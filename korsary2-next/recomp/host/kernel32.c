/* KERNEL32.DLL */
#include "win32.h"
#include "seh_diagnostic.h"

#include <ctype.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <fnmatch.h>
#include <pthread.h>
#include <sched.h>
#include <stdarg.h>
#include <strings.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#define ACTIVITY_EXPORT EMSCRIPTEN_KEEPALIVE
#else
#define ACTIVITY_EXPORT
#endif

#define W(name) static void w_##name(CPU *c)

const char *guest_cwd(void);
void guest_set_cwd(const char *p);
static void set_error(uint32_t e) { if (t_self) t_self->last_error = e; }
static int strict_share(void);   /* PORT_STRICT_FILE_SHARE, defined with the share registry below */

enum { ERROR_FILE_NOT_FOUND = 2, ERROR_PATH_NOT_FOUND = 3, ERROR_TOO_MANY_OPEN_FILES = 4, ERROR_ACCESS_DENIED = 5,
       ERROR_INVALID_HANDLE = 6, ERROR_NOT_SAME_DEVICE = 17, ERROR_NO_MORE_FILES = 18, ERROR_WRITE_FAULT = 29,
       ERROR_SHARING_VIOLATION = 32, ERROR_NOT_SUPPORTED = 50, ERROR_FILE_EXISTS = 80, ERROR_DISK_FULL = 112,
       ERROR_INVALID_NAME = 123, ERROR_DIR_NOT_EMPTY = 145, ERROR_ALREADY_EXISTS = 183, ERROR_FILENAME_EXCED_RANGE = 206,
       ERROR_DIRECTORY = 267 };
static uint32_t file_io_error(int e, uint32_t fallback) {
    return e == EBADF ? ERROR_INVALID_HANDLE : (e == EACCES || e == EPERM) ? ERROR_ACCESS_DENIED :
           e == ENOSPC ? ERROR_DISK_FULL : e == EINVAL ? 87 /* ERROR_INVALID_PARAMETER */ : fallback;
}

/* ------------------------------------------------------------------ version, modules, process */

W(GetVersionExA) {
    uint32_t p = ARG(0);  /* OSVERSIONINFOA: report Windows XP SP2 */
    W32(p + 4, 5); W32(p + 8, 1); W32(p + 12, 2600); W32(p + 16, 2 /* VER_PLATFORM_WIN32_NT */);
    strcpy((char *)HP(p + 20), "Service Pack 2");
    RET(1, 1);
}

W(GetVersion) { RET(0, 0x0A280105u); }   /* NT 5.1 build 2600 (XP) */

W(GetEnvironmentVariableA) { RET(3, 0); }  /* not found: CRTs and the ini service just take defaults */

W(GetLocalTime) {
    struct timespec ts; clock_gettime(CLOCK_REALTIME, &ts);
    struct tm tm; localtime_r(&ts.tv_sec, &tm);
    uint32_t p = ARG(0);
    W16(p, tm.tm_year + 1900); W16(p + 2, tm.tm_mon + 1); W16(p + 4, tm.tm_wday); W16(p + 6, tm.tm_mday);
    W16(p + 8, tm.tm_hour); W16(p + 10, tm.tm_min); W16(p + 12, tm.tm_sec);
    W16(p + 14, (uint32_t)(ts.tv_nsec / 1000000));
    RET(1, 1);
}

W(GlobalMemoryStatus) {   /* ~2 GiB RAM, plenty of virtual space */
    uint32_t p = ARG(0);
    if (R32(p) >= 32) W32(p + 4, 50);
    W32(p + 8, 0x80000000u); W32(p + 12, 0x7f000000u);   /* Total/AvailPhys */
    W32(p + 16, 0x80000000u); W32(p + 20, 0x7f000000u);  /* Total/AvailPageFile */
    W32(p + 24, 0x7ffe0000u); W32(p + 28, 0x60000000u);  /* Total/AvailVirtual */
    RET(1, 1);
}

W(GetDiskFreeSpaceExA) {   /* 64 GiB total, 32 GiB free — the game only sanity-checks the size */
    if (ARG(1)) W64(ARG(1), 0x800000000ull);
    if (ARG(2)) W64(ARG(2), 0x1000000000ull);
    if (ARG(3)) W64(ARG(3), 0x800000000ull);
    RET(4, 1);
}

W(CompareFileTime) {
    uint64_t a = R64(ARG(0)), b = R64(ARG(1));
    RET(2, a < b ? (uint32_t)-1 : a > b ? 1 : 0);
}

/* E1 (core.c): a write-class operation on a path the read-only language overlay holds is refused here, never carried out
   (map_path itself only returns base paths, so nothing could reach the overlay anyway; this keeps one logical file from
   existing in two versions). `what` names the operation for the log. */
static int ov_refuses_write(const OvHit *h, const char *what, const char *guest) {
    if (!h->kind) return 0;
    LOG("[overlay] %s(%s) refused: the path is served from the read-only overlay\n", what, guest);
    return 1;
}

static int file_attr(const char *guest) {   /* FILE_ATTRIBUTE_ DIRECTORY 0x10 / ARCHIVE 0x20, -1 none */
    char host[1024];
    OvHit ov;
    if (!map_path_ov(guest, host, sizeof host, &ov)) {
#ifdef PORT_LAZY_EXPERIMENT
        const LazyNode *node = lazy_guest_node(guest);
        if (node) return lazy_index_is_dir(node) ? 0x10 : 0x20;
#endif
        return -1;
    }
    if (ov.kind) return ov.kind == 2 ? 0x10 : 0x20;   /* the overlay's entry shadows the base's */
    struct stat st;
    if (stat(host, &st)) return -1;
    return S_ISDIR(st.st_mode) ? 0x10 : 0x20;
}

#ifdef PORT_LAZY_EXPERIMENT
/* A namespace hit is only metadata, never permission to return an empty file.
 * The page can temporarily create a placeholder during download. Serialize
 * indexed reads until the request has completed, without holding share locks.
 * On any failure/timeout fail closed for this process: async page cleanup can
 * still be running after the requester gives up and drops this mutex. */
static pthread_mutex_t g_lazy_open_lock = PTHREAD_MUTEX_INITIALIZER;
static int g_lazy_poisoned;
/* An in-flight or failed path may exist as a zero-byte placeholder in OPFS. */
static const LazyNode *g_lazy_incomplete;
static int lazy_ensure_available(const char *name, const LazyNode *node) {
    if (!node || lazy_index_is_dir(node)) return 1;
    pthread_mutex_lock(&g_lazy_open_lock);
    if (g_lazy_poisoned) { pthread_mutex_unlock(&g_lazy_open_lock); return 0; }
    OvHit before; char resolved[1024];
    if (map_path_ov(name, resolved, sizeof resolved, &before)) { pthread_mutex_unlock(&g_lazy_open_lock); return 1; }
    char canonical[1024];
    extern int port_lazy_request(const char *, unsigned);
    __atomic_store_n(&g_lazy_incomplete, node, __ATOMIC_RELEASE);
    int ok = lazy_index_path(node, canonical, sizeof canonical) && port_lazy_request(canonical, 120000);
    if (!ok) g_lazy_poisoned = 1;
    else __atomic_store_n(&g_lazy_incomplete, NULL, __ATOMIC_RELEASE);
    pthread_mutex_unlock(&g_lazy_open_lock);
    return ok;
}
#endif

W(GetFileAttributesA) {
    int32_t at = file_attr(GSTR(ARG(0)));
    RET(1, at < 0 ? (uint32_t)0xFFFFFFFFu : (uint32_t)at);
}

W(SetFileAttributesA) { LOG("[kernel32] SetFileAttributesA(%s) ignored\n", GSTR(ARG(0))); RET(2, 1); }

static uint32_t copy_file_strict(const char *src, const char *dst, int fail_if_exists);
W(CopyFileA) {
    /* log-only: which of these calls the game really makes is unknown (F32_AUDIT.md), PORT_LOG shows it */
    if (ARG(0) && ARG(1) && (uint64_t)ARG(0) < GUEST_SPACE && (uint64_t)ARG(1) < GUEST_SPACE)
        LOG("[file] CopyFileA(%s -> %s, failIfExists=%u)\n", GSTR(ARG(0)), GSTR(ARG(1)), ARG(2));
#ifdef PORT_LAZY_EXPERIMENT
    if (!ARG(0) || !ARG(1) || (uint64_t)ARG(0) >= GUEST_SPACE || (uint64_t)ARG(1) >= GUEST_SPACE) {
        set_error(87 /* ERROR_INVALID_PARAMETER */); RET(3, 0);
    }
    const LazyNode *lsrc = lazy_guest_node(GSTR(ARG(0)));
    if (lazy_guest_node(GSTR(ARG(1)))) { set_error(ERROR_ACCESS_DENIED); RET(3, 0); }
    if (!lazy_ensure_available(GSTR(ARG(0)), lsrc)) { set_error(30 /* ERROR_READ_FAULT */); RET(3, 0); }
#endif
    if (strict_share()) {
        if (!ARG(0) || !ARG(1) || (uint64_t)ARG(0) >= GUEST_SPACE || (uint64_t)ARG(1) >= GUEST_SPACE) {
            set_error(87 /* ERROR_INVALID_PARAMETER */); RET(3, 0);
        }
        uint32_t err = copy_file_strict(GSTR(ARG(0)), GSTR(ARG(1)), ARG(2) != 0);
        set_error(err);
        RET(3, err == 0);
    }
    const char *src = GSTR(ARG(0)), *dst = GSTR(ARG(1));
    char hsrc[1024], hdst[1024];
    OvHit osrc, odst;
    if (!map_path_ov(src, hsrc, sizeof hsrc, &osrc) || !map_path_ov(dst, hdst, sizeof hdst, &odst)) RET(3, 0);
    if (ARG(2) && file_attr(dst) >= 0) { set_error(80 /* ERROR_FILE_EXISTS */); RET(3, 0); }
    if (ov_refuses_write(&odst, "CopyFileA", dst)) { set_error(ERROR_ACCESS_DENIED); RET(3, 0); }
    FILE *in = fopen(osrc.kind ? osrc.host : hsrc, "rb");
    if (!in) RET(3, 0);
    FILE *out = fopen(hdst, "wb");
    if (!out) { fclose(in); RET(3, 0); }
    char buf[65536];
    size_t n;
    while ((n = fread(buf, 1, sizeof buf, in)) > 0) fwrite(buf, 1, n, out);
    fclose(in); fclose(out);
    LOG("[kernel32] CopyFileA(%s -> %s)\n", src, dst);
    RET(3, 1);
}

W(Beep) { RET(2, 1); }
W(HeapValidate) { RET(3, 1); }
W(SetErrorMode) { RET(1, 0); }
W(DisableThreadLibraryCalls) { RET(1, 1); }
W(GlobalLock) { RET(1, ARG(0)); }        /* GlobalAlloc yields a heap pointer; lock/unlock are no-ops */
W(GlobalUnlock) { RET(1, 0); }
W(lstrlenA) { RET(1, ARG(0) ? strlen(GSTR(ARG(0))) : 0); }
W(lstrcatA) { strcat((char *)HP(ARG(0)), GSTR(ARG(1))); RET(2, ARG(0)); }

#define FAKE_MODULE(i) (0xF1000000u + (i) * 0x10000u)
static const char *g_known_dlls[] = { "kernel32.dll", "user32.dll", "gdi32.dll", "advapi32.dll", "winmm.dll",
                                      "d3d8.dll", "ddraw.dll", "dinput.dll", "dsound.dll", "version.dll", NULL };

static uint32_t module_for(const char *name) {
    if (!name) return 0x400000;
    uint32_t guest = guest_module_base(name);   /* the port's own images, all mapped at startup */
    if (guest) return guest;
    const char *b = strrchr(name, '\\');
    b = b ? b + 1 : name;
    for (int i = 0; g_known_dlls[i]; i++)
        if (!strncasecmp(b, g_known_dlls[i], strlen(g_known_dlls[i]) - 4)) return FAKE_MODULE(i + 1);
    return 0;
}

W(GetModuleHandleA) { RET(1, ARG(0) ? module_for(GSTR(ARG(0))) : 0x400000); }
W(LoadLibraryA) {
    uint32_t m = module_for(GSTR(ARG(0)));
    LOG("[kernel32] LoadLibraryA(%s) -> %08x\n", GSTR(ARG(0)), m);
    set_error(m ? 0 : 126);
    RET(1, m);
}
W(FreeLibrary) { RET(1, 1); }

W(GetProcAddress) {
    uint32_t mod = ARG(0), name = ARG(1);
    /* A guest module handle: exports are real translated functions, resolved from the image's export
       directory (by name or ordinal; ordinal handles are < 0x10000, as on Windows). */
    if (mod >= 0x400000 && mod < IMPORT_BASE) {
        uint32_t addr;
        if (guest_export_lookup(mod, name < 0x10000 ? NULL : GSTR(name), name < 0x10000 ? name : 0, &addr)) {
            LOG("[kernel32] GetProcAddress(%08x, %s) -> %08x\n", mod, name < 0x10000 ? "#ord" : GSTR(name), addr);
            RET(2, addr);
        }
        LOG("[kernel32] GetProcAddress(%08x, %s) -> not found\n", mod, name < 0x10000 ? "#ord" : GSTR(name));
        set_error(127);   /* ERROR_PROC_NOT_FOUND */
        RET(2, 0);
    }
    char full[160];
    const char *dll = "KERNEL32.DLL";
    for (int i = 0; g_known_dlls[i]; i++)
        if (mod == FAKE_MODULE(i + 1)) dll = g_known_dlls[i];
    char up[32];
    snprintf(up, sizeof up, "%s", dll);
    for (char *p = up; *p; p++) *p = (char)toupper((unsigned char)*p);
    if (name < 0x10000)  /* system DLL by ordinal (e.g. SoundService wants dsound.dll #11/#2) */
        snprintf(full, sizeof full, "%s!#%u", up, name);
    else
        snprintf(full, sizeof full, "%s!%s", up, GSTR(name));
    GuestFn fn = find_import_handler(full);
    uint32_t r = fn ? add_dynamic_import(full, fn) : 0;
    LOG("[kernel32] GetProcAddress(%s) -> %08x\n", full, r);
    if (!r) set_error(127);
    RET(2, r);
}

W(GetModuleFileNameA) {
    const char *p = GUEST_ROOT "\\" PORT_GUEST_EXE;
    uint32_t buf = ARG(1), n = ARG(2);
    snprintf((char *)HP(buf), n, "%s", p);
    RET(3, strlen(p) < n ? strlen(p) : n);
}

static uint32_t g_cmdline, g_env;
W(GetCommandLineA) {
    if (!g_cmdline) g_cmdline = guest_strdup("\"" GUEST_ROOT "\\" PORT_GUEST_EXE "\"");
    RET(0, g_cmdline);
}
W(GetEnvironmentStrings) {
    if (!g_env) { g_env = heap_alloc(64, 1); strcpy((char *)HP(g_env), "PATH=C:\\WINDOWS"); }
    RET(0, g_env);
}
W(GetEnvironmentStringsW) {
    uint32_t a = heap_alloc(8, 1);
    RET(0, a);
}
W(FreeEnvironmentStringsA) { RET(1, 1); }
W(FreeEnvironmentStringsW) { RET(1, 1); }
W(SetEnvironmentVariableA) { RET(2, 1); }

W(GetStartupInfoA) {
    uint32_t p = ARG(0);
    memset(HP(p), 0, 68);
    W32(p, 68);
    RET(1, 0);
}

#define STD_IN 0x0F0u
#define STD_OUT 0x0F4u
#define STD_ERR 0x0F8u
W(GetStdHandle) {
    int32_t which = (int32_t)ARG(0);
    RET(1, which == -10 ? STD_IN : which == -11 ? STD_OUT : STD_ERR);
}
W(SetStdHandle) { RET(2, 1); }
W(GetFileType) {
    uint32_t h = ARG(0);
    if (h == STD_IN || h == STD_OUT || h == STD_ERR) RET(1, 2 /* FILE_TYPE_CHAR */);
    RET(1, handle_get(h, H_FILE) ? 1 /* FILE_TYPE_DISK */ : 0);
}
W(SetHandleCount) { RET(1, ARG(0)); }

W(GetCurrentProcess) { RET(0, 0xFFFFFFFFu); }
W(GetCurrentThread) { RET(0, 0xFFFFFFFEu); }
W(GetCurrentProcessId) { RET(0, 0x1234); }
W(GetCurrentThreadId) { RET(0, t_self ? t_self->id : 0x100); }
W(GetLastError) { RET(0, t_self ? t_self->last_error : 0); }
W(SetLastError) { set_error(ARG(0)); RET(1, 0); }

W(ExitProcess) {
    fprintf(stderr, "[kernel32] ExitProcess(%d) from thread %u, stack:", (int)ARG(0), t_self ? t_self->id : 0);
    for (int k = 0, n = 0; k < 4096 && n < 32; k++) {
        uint32_t v = R32(c->esp + 4 * k);
        if (looks_like_code(v)) { fprintf(stderr, " %08x", v); n++; }
    }
    fprintf(stderr, "\n");
    /* strings still on the stack (the fatal error's message and arguments) */
    for (int k = 0, n = 0; k < 1024 && n < 12; k++) {
        uint32_t v = R32(c->esp + 4 * k);
        if (v < 0x401000 || v >= GUEST_VALLOC_HI) continue;
        const uint8_t *p = HP(v);
        int len = 0;
        while (len < 120 && p[len] >= 0x20 && p[len] < 0x7f) len++;
        if (len >= 6 && (p[len] == 0 || p[len] == '\n')) { fprintf(stderr, "    \"%.*s\"\n", len, (const char *)p); n++; }
    }
    exit((int)ARG(0));
}
W(TerminateProcess) {
    fprintf(stderr, "[kernel32] TerminateProcess(%d)\n", (int)ARG(1));
    exit((int)ARG(1));
}
W(FatalAppExitA) {
    fprintf(stderr, "[kernel32] FatalAppExit: %s\n", GSTR(ARG(1)));
    exit(3);
}

W(GetSystemInfo) {
    uint32_t p = ARG(0);
    memset(HP(p), 0, 36);
    W32(p + 4, 0x1000);        /* page size */
    W32(p + 8, 0x10000);       /* min app address */
    W32(p + 12, 0x7FFEFFFF);   /* max app address */
    W32(p + 16, 1);            /* active processor mask */
    W32(p + 20, 1);            /* number of processors */
    W32(p + 24, 586);          /* processor type */
    W32(p + 28, 0x10000);      /* allocation granularity */
    W16(p + 32, 6);            /* level */
    RET(1, 0);
}

W(IsProcessorFeaturePresent) { RET(1, 0); }  /* consistent with our CPUID: no MMX/SSE/3DNow! */
W(IsDebuggerPresent) { RET(0, 0); }
W(OutputDebugStringA) { LOG("[debug] %s", GSTR(ARG(0))); RET(1, 0); }
W(DebugBreak) { guest_trap(c, R32(c->esp), "DebugBreak"); }
W(IsBadReadPtr) { RET(2, ARG(0) == 0); }
W(IsBadWritePtr) { RET(2, ARG(0) == 0); }
W(IsBadCodePtr) { RET(1, ARG(0) == 0); }
W(SetUnhandledExceptionFilter) { RET(1, 0); }
W(UnhandledExceptionFilter) { RET(1, 0); }
W(RaiseException) {
    fprintf(stderr, "[kernel32] RaiseException code=%08x flags=%08x nargs=%u (from %08x)\n", ARG(0), ARG(1),
            ARG(2), R32(c->esp));
    if (ARG(0) == 0xE06D7363u && ARG(2) >= 3) {  /* MSVC C++ exception: show the thrown type */
        char name[128];
        if (seh_diag_type(g_mem,GUEST_SPACE,ARG(3),name,sizeof name))
            fprintf(stderr, "    C++ exception of type %s\n", name);
    }
    guest_trap(c, R32(c->esp), "RaiseException (exceptions are not supported yet)");
}
W(RtlUnwind) { guest_trap(c, R32(c->esp), "RtlUnwind (exceptions are not supported yet)"); }

W(FormatMessageA) {
    uint32_t buf = ARG(4), n = ARG(5);
    if (ARG(0) & 0x100) RET(7, 0);  /* FORMAT_MESSAGE_ALLOCATE_BUFFER: unsupported */
    snprintf((char *)HP(buf), n, "error %u", ARG(2));
    RET(7, strlen(GSTR(buf)));
}

/* ------------------------------------------------------------------ code pages and locale (CRT) */

W(GetACP) { RET(0, 1252); }
W(GetOEMCP) { RET(0, 437); }
W(IsValidCodePage) { RET(1, 1); }
W(GetCPInfo) {
    uint32_t p = ARG(1);
    memset(HP(p), 0, 20);
    W32(p, 1);       /* MaxCharSize */
    W8(p + 4, '?');  /* DefaultChar */
    RET(2, 1);
}

W(MultiByteToWideChar) {
    uint32_t src = ARG(2), dst = ARG(4);
    int32_t n = (int32_t)ARG(3), cap = (int32_t)ARG(5);
    if (n < 0) n = (int32_t)strlen(GSTR(src)) + 1;
    if (!cap) RET(6, n);
    int k = n < cap ? n : cap;
    for (int i = 0; i < k; i++) W16(dst + 2 * i, R8(src + i));
    RET(6, k);
}

W(WideCharToMultiByte) {
    uint32_t src = ARG(2), dst = ARG(4);
    int32_t n = (int32_t)ARG(3), cap = (int32_t)ARG(5);
    if (n < 0) { n = 0; while (R16(src + 2 * n)) n++; n++; }
    if (!cap) RET(8, n);
    int k = n < cap ? n : cap;
    for (int i = 0; i < k; i++) { uint16_t w = R16(src + 2 * i); W8(dst + i, w < 256 ? (uint8_t)w : '?'); }
    RET(8, k);
}

W(GetStringTypeA) {
    uint32_t src = ARG(2), out = ARG(4);
    int32_t n = (int32_t)ARG(3);
    if (n < 0) n = (int32_t)strlen(GSTR(src)) + 1;
    for (int i = 0; i < n; i++) {
        int ch = R8(src + i), t = 0;
        if (isupper(ch)) t |= 1; if (islower(ch)) t |= 2; if (isdigit(ch)) t |= 4; if (isspace(ch)) t |= 8;
        if (ispunct(ch)) t |= 0x10; if (iscntrl(ch)) t |= 0x20; if (ch == ' ' || ch == '\t') t |= 0x40;
        if (isxdigit(ch)) t |= 0x80; if (isalpha(ch)) t |= 0x100;
        W16(out + 2 * i, (uint16_t)t);
    }
    RET(5, 1);
}
W(GetStringTypeW) {
    uint32_t src = ARG(1), out = ARG(3);
    int32_t n = (int32_t)ARG(2);
    if (n < 0) { n = 0; while (R16(src + 2 * n)) n++; n++; }
    for (int i = 0; i < n; i++) {
        int ch = R16(src + 2 * i), t = 0;
        if (ch < 128) {
            if (isupper(ch)) t |= 1; if (islower(ch)) t |= 2; if (isdigit(ch)) t |= 4; if (isspace(ch)) t |= 8;
            if (ispunct(ch)) t |= 0x10; if (iscntrl(ch)) t |= 0x20; if (ch == ' ' || ch == '\t') t |= 0x40;
            if (isxdigit(ch)) t |= 0x80; if (isalpha(ch)) t |= 0x100;
        }
        W16(out + 2 * i, (uint16_t)t);
    }
    RET(4, 1);
}

W(LCMapStringA) {
    uint32_t flags = ARG(1), src = ARG(2), dst = ARG(4);
    int32_t n = (int32_t)ARG(3), cap = (int32_t)ARG(5);
    if (n < 0) n = (int32_t)strlen(GSTR(src)) + 1;
    if (!cap) RET(6, n);
    for (int i = 0; i < n && i < cap; i++) {
        int ch = R8(src + i);
        W8(dst + i, (uint8_t)((flags & 0x100) ? tolower(ch) : (flags & 0x200) ? toupper(ch) : ch));
    }
    RET(6, n < cap ? n : cap);
}
W(LCMapStringW) {
    uint32_t flags = ARG(1), src = ARG(2), dst = ARG(4);
    int32_t n = (int32_t)ARG(3), cap = (int32_t)ARG(5);
    if (n < 0) { n = 0; while (R16(src + 2 * n)) n++; n++; }
    if (!cap) RET(6, n);
    for (int i = 0; i < n && i < cap; i++) {
        int ch = R16(src + 2 * i);
        if (ch < 128) ch = (flags & 0x100) ? tolower(ch) : (flags & 0x200) ? toupper(ch) : ch;
        W16(dst + 2 * i, (uint16_t)ch);
    }
    RET(6, n < cap ? n : cap);
}

static int cmp_strings(const char *a, int na, const char *b, int nb, int nocase) {
    int i = 0;
    for (; i < na && i < nb; i++) {
        int x = (unsigned char)a[i], y = (unsigned char)b[i];
        if (nocase) { x = tolower(x); y = tolower(y); }
        if (x != y) return x < y ? 1 : 3;
    }
    return na == nb ? 2 : na < nb ? 1 : 3;
}
W(CompareStringA) {
    int32_t na = (int32_t)ARG(3), nb = (int32_t)ARG(5);
    const char *a = GSTR(ARG(2)), *b = GSTR(ARG(4));
    if (na < 0) na = (int32_t)strlen(a);
    if (nb < 0) nb = (int32_t)strlen(b);
    RET(6, cmp_strings(a, na, b, nb, ARG(1) & 1));
}
W(CompareStringW) {
    int32_t na = (int32_t)ARG(3), nb = (int32_t)ARG(5);
    char a[1024], b[1024];
    uint32_t pa = ARG(2), pb = ARG(4);
    if (na < 0) { na = 0; while (R16(pa + 2 * na)) na++; }
    if (nb < 0) { nb = 0; while (R16(pb + 2 * nb)) nb++; }
    for (int i = 0; i < na && i < 1023; i++) a[i] = (char)R16(pa + 2 * i);
    for (int i = 0; i < nb && i < 1023; i++) b[i] = (char)R16(pb + 2 * i);
    RET(6, cmp_strings(a, na < 1023 ? na : 1023, b, nb < 1023 ? nb : 1023, ARG(1) & 1));
}

W(GetUserDefaultLCID) { RET(0, 0x0809); }  /* en-GB */
W(IsValidLocale) { RET(2, 1); }
W(EnumSystemLocalesA) { RET(2, 1); }
static int locale_info(uint32_t type, char *out, size_t n) {
    switch (type & 0xffff) {
    case 0x1004: return snprintf(out, n, "1252");      /* LOCALE_IDEFAULTANSICODEPAGE */
    case 0x000B: return snprintf(out, n, "850");       /* LOCALE_IDEFAULTCODEPAGE */
    case 0x0001: return snprintf(out, n, "0809");      /* LOCALE_ILANGUAGE */
    case 0x0003: return snprintf(out, n, "ENG");       /* LOCALE_SABBREVLANGNAME */
    case 0x0007: return snprintf(out, n, "GBR");       /* LOCALE_SABBREVCTRYNAME */
    case 0x000E: return snprintf(out, n, ".");         /* LOCALE_SDECIMAL */
    case 0x000F: return snprintf(out, n, ",");         /* LOCALE_STHOUSAND */
    case 0x0014: return snprintf(out, n, "\xa3");      /* LOCALE_SCURRENCY */
    default: return snprintf(out, n, "0");
    }
}
W(GetLocaleInfoA) {
    char tmp[64];
    int k = locale_info(ARG(1), tmp, sizeof tmp) + 1;
    if (ARG(3)) snprintf((char *)HP(ARG(2)), ARG(3), "%s", tmp);
    RET(4, k);
}
W(GetLocaleInfoW) {
    char tmp[64];
    int k = locale_info(ARG(1), tmp, sizeof tmp) + 1;
    for (int i = 0; ARG(3) && i < k && i < (int)ARG(3); i++) W16(ARG(2) + 2 * i, (uint8_t)tmp[i]);
    RET(4, k);
}

/* ------------------------------------------------------------------ time */

W(GetTickCount) { RET(0, (uint32_t)(guest_seconds() * 1000.0)); }
W(QueryPerformanceFrequency) { W64(ARG(0), 1000000000ull); RET(1, 1); }
W(QueryPerformanceCounter) { W64(ARG(0), (uint64_t)(guest_seconds() * 1e9)); RET(1, 1); }
W(GetSystemTimeAsFileTime) { W64(ARG(0), guest_time_100ns()); RET(1, 0); }
/* Win32 FILETIME (100 ns units since 1601-01-01 UTC) from a POSIX timestamp.
   0 means "unknown" here and for out-of-range inputs (pre-1601 dates, nanosecond
   garbage): callers treat a zero FILETIME as no information, never as a date. */
static uint64_t filetime_from_timespec(time_t sec, long nsec) {
    const int64_t epoch = 11644473600ll;
    if ((int64_t)sec < -epoch || (int64_t)sec > INT64_MAX - epoch ||
        nsec < 0 || nsec >= 1000000000l) return 0;
    uint64_t s = (uint64_t)((int64_t)sec + epoch);
    if (s > (UINT64_MAX - (uint64_t)nsec / 100) / 10000000ull) return 0;
    return s * 10000000ull + (uint64_t)nsec / 100;
}

/* The save list shows each existing slot's WIN32_FIND_DATA.ftCreationTime passed
   through this conversion, so it must shift by the UTC offset of the file time's
   own date (a summer save then shows summer time even in winter). A zero
   FILETIME means "unknown" in this port (the browser WasmFS/OPFS backend does
   not persist file times across a reload today), and unknown stays unknown:
   passing it through keeps the list stable instead of showing a timezone-
   dependent hour of the year 1601. Failure paths still write the output, because
   translated callers may not check the return value. */
W(FileTimeToLocalFileTime) {
    uint64_t ft = R64(ARG(0));
    if (!ft) { W64(ARG(1), 0); RET(2, 1); }
    int64_t sec = (int64_t)(ft / 10000000ull) - 11644473600ll;
    time_t t = (time_t)sec;
    struct tm local;
    if ((int64_t)t != sec || !localtime_r(&t, &local)) { W64(ARG(1), 0); set_error(87); RET(2, 0); }
    int64_t delta = (int64_t)local.tm_gmtoff * 10000000ll;
    if ((delta < 0 && ft < (uint64_t)(-delta)) ||
        (delta > 0 && ft > UINT64_MAX - (uint64_t)delta)) { W64(ARG(1), 0); set_error(87); RET(2, 0); }
    W64(ARG(1), delta < 0 ? ft - (uint64_t)(-delta) : ft + (uint64_t)delta);
    RET(2, 1);
}
W(FileTimeToSystemTime) {
    uint64_t ft = R64(ARG(0));
    int64_t sec = (int64_t)(ft / 10000000ull) - 11644473600ll;
    time_t t = (time_t)sec;
    struct tm tmv;
    if ((int64_t)t != sec || !gmtime_r(&t, &tmv)) { set_error(87); RET(2, 0); }
    uint32_t p = ARG(1);
    W16(p, (uint16_t)(tmv.tm_year + 1900)); W16(p + 2, (uint16_t)(tmv.tm_mon + 1)); W16(p + 4, (uint16_t)tmv.tm_wday);
    W16(p + 6, (uint16_t)tmv.tm_mday); W16(p + 8, (uint16_t)tmv.tm_hour); W16(p + 10, (uint16_t)tmv.tm_min);
    W16(p + 12, (uint16_t)tmv.tm_sec); W16(p + 14, (uint16_t)((ft / 10000) % 1000));
    RET(2, 1);
}
W(GetTimeZoneInformation) { memset(HP(ARG(0)), 0, 172); RET(1, 0 /* TIME_ZONE_ID_UNKNOWN */); }
W(GetDateFormatA) {
    const char *s = "15/10/2026";
    if (ARG(5)) snprintf((char *)HP(ARG(4)), ARG(5), "%s", s);
    RET(6, strlen(s) + 1);
}
W(GetTimeFormatA) {
    const char *s = "12:00:00";
    if (ARG(5)) snprintf((char *)HP(ARG(4)), ARG(5), "%s", s);
    RET(6, strlen(s) + 1);
}

/* ------------------------------------------------------------------ memory */

#define HEAP_HANDLE 0x00A70000u
W(HeapCreate) { RET(3, HEAP_HANDLE); }
W(HeapDestroy) { RET(1, 1); }
W(GetProcessHeap) { RET(0, HEAP_HANDLE); }
W(HeapAlloc) {
    uint32_t r = heap_try_alloc(ARG(2), ARG(1) & 8);
    if (!r && (ARG(1) & 4))
        guest_trap(c, R32(c->esp), "HeapAlloc STATUS_NO_MEMORY (guest exceptions unsupported)");
    {   /* TEMP DEBUG: who allocates/frees the SoundService attribute-object block */
        static uint32_t lo, hi;
        if (!lo) {
            const char *e = getenv("PORT_HEAP_TRACE");
            if (e) { lo = (uint32_t)strtoul(e, NULL, 16) - 0x40; hi = lo + 0x80; }
        }
        if (lo && r >= lo && r < hi)
            fprintf(stderr, "[obj] alloc %08x size %u flags %x from ret %08x\n", r, ARG(2), ARG(1), R32(c->esp));
    }
    RET(3, r);
}
W(HeapFree) {
    {   /* TEMP DEBUG */
        static uint32_t lo, hi;
        if (!lo) {
            const char *e = getenv("PORT_HEAP_TRACE");
            if (e) { lo = (uint32_t)strtoul(e, NULL, 16) - 0x40; hi = lo + 0x80; }
        }
        if (lo && ARG(2) >= lo && ARG(2) < hi)
            fprintf(stderr, "[obj] FREE %08x from ret %08x\n", ARG(2), R32(c->esp));
    }
    heap_free(ARG(2));
    RET(3, 1);
}
W(HeapReAlloc) {
    uint32_t r = ARG(2) ? heap_realloc_ex(ARG(2), ARG(3), ARG(1) & 8, ARG(1) & 0x10) : 0;
    if (!r && (ARG(1) & 4))
        guest_trap(c, R32(c->esp), "HeapReAlloc failed (guest exceptions unsupported)");
    {   /* TEMP DEBUG */
        static uint32_t lo, hi;
        if (!lo) {
            const char *e = getenv("PORT_HEAP_TRACE");
            if (e) { lo = (uint32_t)strtoul(e, NULL, 16) - 0x40; hi = lo + 0x80; }
        }
        if (lo && r >= lo && r < hi)
            fprintf(stderr, "[obj] realloc %08x (old %08x) size %u from ret %08x\n", r, ARG(2), ARG(3), R32(c->esp));
    }
    RET(4, r);
}
W(HeapSize) { RET(3, heap_size(ARG(2))); }
W(GlobalAlloc) { RET(2, heap_try_alloc(ARG(1), ARG(0) & 0x40)); }
W(GlobalFree) { heap_free(ARG(0)); RET(1, 0); }
W(LocalFree) { heap_free(ARG(0)); RET(1, 0); }

W(VirtualAlloc) {
    uint32_t addr = ARG(0), size = ARG(1);
    if (addr) RET(4, addr);  /* committing inside a region we already handed out */
    RET(4, guest_valloc(size));
}
W(VirtualFree) { RET(3, 1); }
W(VirtualProtect) {
    /* Executable protections mark code the game generated or loaded itself (AEMS sound modules). */
    if (ARG(2) & 0xf0) { LOG("[kernel32] VirtualProtect(%08x, %x, exec)\n", ARG(0), ARG(1)); dyncode_register(ARG(0), ARG(1)); }
    if (ARG(3)) W32(ARG(3), 4 /* PAGE_READWRITE */);
    RET(4, 1);
}
W(VirtualQuery) {
    uint32_t a = ARG(0), p = ARG(1);
    memset(HP(p), 0, 28);
    W32(p, a & ~0xfffu); W32(p + 4, a & ~0xffffu); W32(p + 8, 4); W32(p + 12, 0x1000);
    W32(p + 16, 0x1000 /* MEM_COMMIT */); W32(p + 20, 4); W32(p + 24, 0x20000 /* MEM_PRIVATE */);
    RET(3, 28);
}

/* ------------------------------------------------------------------ TLS */

static PortTlsTable g_tls = PORT_TLS_TABLE_INIT;
W(TlsAlloc) {
    uint32_t slot = port_tls_alloc(&g_tls);
    if (slot == UINT32_MAX) set_error(259 /* ERROR_NO_MORE_ITEMS */);
    RET(0, slot);
}
W(TlsFree) {
    int ok = port_tls_free(&g_tls, ARG(0));
    if (!ok) set_error(87 /* ERROR_INVALID_PARAMETER */);
    RET(1, ok);
}
W(TlsGetValue) {
    uint32_t value = 0;
    int ok = port_tls_get(&g_tls, t_self ? &t_self->tls : NULL, ARG(0), &value);
    set_error(ok ? 0 : 87 /* ERROR_INVALID_PARAMETER */);
    RET(1, value);
}
W(TlsSetValue) {
    int ok = port_tls_set(&g_tls, t_self ? &t_self->tls : NULL, ARG(0), ARG(1));
    if (!ok) set_error(87 /* ERROR_INVALID_PARAMETER */);
    RET(2, ok);
}

/* ------------------------------------------------------------------ critical sections and interlocked */

typedef struct CS { uint32_t key; pthread_mutex_t m; struct CS *next; GuestThread *owner; int depth; } CS;
static CS *g_cs[1024];
static pthread_mutex_t g_cs_lock = PTHREAD_MUTEX_INITIALIZER;

static CS *cs_get(uint32_t key) {
    uint32_t h = (key >> 2) & 1023;
    pthread_mutex_lock(&g_cs_lock);
    CS *x = g_cs[h];
    while (x && x->key != key) x = x->next;
    if (!x) {
        x = calloc(1, sizeof *x);
        x->key = key;
        pthread_mutexattr_t at;
        pthread_mutexattr_init(&at);
        pthread_mutexattr_settype(&at, PTHREAD_MUTEX_RECURSIVE);
        pthread_mutex_init(&x->m, &at);
        x->next = g_cs[h];
        g_cs[h] = x;
    }
    pthread_mutex_unlock(&g_cs_lock);
    return x;
}
static pthread_mutex_t *cs_for(uint32_t key) { return &cs_get(key)->m; }
/* Deterministic mode: ownership is tracked here and a contended Enter blocks in the scheduler (a host
   mutex would block while holding the scheduler's baton). */
static int cs_free(void *p) { return ((CS *)p)->owner == NULL; }
W(InitializeCriticalSection) { memset(HP(ARG(0)), 0, 24); W32(ARG(0) + 4, 0xFFFFFFFFu); cs_for(ARG(0)); RET(1, 0); }
W(DeleteCriticalSection) { RET(1, 0); }
W(EnterCriticalSection) {
    if (!sched_active()) { pthread_mutex_lock(cs_for(ARG(0))); RET(1, 0); }
    CS *x = cs_get(ARG(0));
    if (x->owner != t_self) sched_wait(cs_free, x, UINT64_MAX, NULL);
    x->owner = t_self;
    x->depth++;
    RET(1, 0);
}
W(LeaveCriticalSection) {
    if (!sched_active()) { pthread_mutex_unlock(cs_for(ARG(0))); RET(1, 0); }
    CS *x = cs_get(ARG(0));
    if (x->owner == t_self && --x->depth == 0) x->owner = NULL;
    RET(1, 0);
}

/* same global lock as the translated lock-prefixed instructions, so both agree */
W(InterlockedIncrement) { guest_lock(); uint32_t v = R32(ARG(0)) + 1; W32(ARG(0), v); guest_unlock(); RET(1, v); }
W(InterlockedDecrement) { guest_lock(); uint32_t v = R32(ARG(0)) - 1; W32(ARG(0), v); guest_unlock(); RET(1, v); }
W(InterlockedExchange) { guest_lock(); uint32_t v = R32(ARG(0)); W32(ARG(0), ARG(1)); guest_unlock(); RET(2, v); }

/* ------------------------------------------------------------------ sync objects */

typedef struct {
    pthread_mutex_t m;
    pthread_cond_t cv;
    int manual, signaled;      /* event */
    int count, max;            /* semaphore */
    pthread_t owner; int owned, depth;  /* mutex */
    int waiters, handoff;               /* mutex: threads blocked on it; released to one of them */
    uint16_t finished, closed;          /* thread: finished; any object: its handle was closed (sync_close_hook), so a wait that has not
                                           acquired fails instead of hanging. 16 bits each: sizeof(Sync) stays 160 (the bench saw
                                           cache-line sharing between neighbouring objects change with a 4-byte growth) */
    uint32_t exit_code;                 /* thread */
} Sync;
static void sync_close_hook(uint32_t h, int type, void *ptr);

static Sync *sync_new(void) {
    Sync *s = calloc(1, sizeof *s);
    pthread_mutex_init(&s->m, NULL);
    pthread_cond_init(&s->cv, NULL);
    handle_set_close_hook(sync_close_hook);   /* idempotent: a close can only meet a sync object after one was created here */
    return s;
}

W(CreateEventA) {
    Sync *s = sync_new();
    s->manual = ARG(1) != 0;
    s->signaled = ARG(2) != 0;
    uint32_t h = handle_new_ptr(H_EVENT, s);   /* the object is in the slot before the handle is visible to other threads */
    RET(4, h);
}
/* Host-side SetEvent, used by DirectSound position notifications. */
void kernel_set_event(uint32_t h) {
    WinHandle *x = handle_get(h, H_EVENT);
    Sync *s = x ? HANDLE_PTR(x) : NULL;
    if (!s) return;   /* closed, or its slot is being reused: the object itself is never freed */
    pthread_mutex_lock(&s->m); s->signaled = 1; pthread_cond_broadcast(&s->cv); pthread_mutex_unlock(&s->m);
}

W(SetEvent) {
    WinHandle *x = handle_get(ARG(0), H_EVENT);
    Sync *s = x ? HANDLE_PTR(x) : NULL;
    if (!s) RET(1, 0);
    pthread_mutex_lock(&s->m); s->signaled = 1; pthread_cond_broadcast(&s->cv); pthread_mutex_unlock(&s->m);
    RET(1, 1);
}
W(ResetEvent) {
    WinHandle *x = handle_get(ARG(0), H_EVENT);
    Sync *s = x ? HANDLE_PTR(x) : NULL;
    if (!s) RET(1, 0);
    pthread_mutex_lock(&s->m); s->signaled = 0; pthread_mutex_unlock(&s->m);
    RET(1, 1);
}
W(CreateMutexA) {
    Sync *s = sync_new();
    if (ARG(1)) { s->owned = 1; s->owner = pthread_self(); s->depth = 1; }
    uint32_t h = handle_new_ptr(H_MUTEX, s);
    RET(3, h);
}
W(ReleaseMutex) {
    WinHandle *x = handle_get(ARG(0), H_MUTEX);
    Sync *s = x ? HANDLE_PTR(x) : NULL;
    if (!s) RET(1, 0);
    pthread_mutex_lock(&s->m);
    if (s->owned && pthread_equal(s->owner, pthread_self()) && --s->depth == 0) {
        s->owned = 0;
        /* Hand over to a thread that is already waiting rather than letting the releasing thread
           barge back in: EA's sound code locks and unlocks in a tight loop, which otherwise starves
           the timer thread (in WebAssembly it never gets the lock at all). */
        if (s->waiters) s->handoff = 1;
        pthread_cond_broadcast(&s->cv);
    }
    pthread_mutex_unlock(&s->m);
    RET(1, 1);
}
W(CreateSemaphoreA) {
    Sync *s = sync_new();
    s->count = (int)ARG(1);
    s->max = (int)ARG(2);
    uint32_t h = handle_new_ptr(H_SEMAPHORE, s);
    RET(4, h);
}
W(ReleaseSemaphore) {
    WinHandle *x = handle_get(ARG(0), H_SEMAPHORE);
    Sync *s = x ? HANDLE_PTR(x) : NULL;
    if (!s) RET(3, 0);
    pthread_mutex_lock(&s->m);
    if (ARG(2)) W32(ARG(2), (uint32_t)s->count);
    s->count += (int)ARG(1);
    if (s->count > s->max) s->count = s->max;
    pthread_cond_broadcast(&s->cv);
    pthread_mutex_unlock(&s->m);
    RET(3, 1);
}

/* A wait works on this pair, captured once from the handle table before the wait starts (handle_snapshot): the handle
   may be closed, and its slot reissued to another object, while the wait is blocked, so the slot is never read again.
   Sync objects are never freed, so s stays valid whatever happens to the handle. */
typedef struct { int type; Sync *s; } WaitTarget;
#define WAIT_FAILED_ 0xFFFFFFFFu

/* Returns 1 when the object became signaled (and consumes it where that's the semantics). */
static int try_acquire(const WaitTarget *t, int waited) {
    Sync *s = t->s;
    switch (t->type) {
    case H_EVENT: if (s->signaled) { if (!s->manual) s->signaled = 0; return 1; } return 0;
    case H_SEMAPHORE: if (s->count > 0) { s->count--; return 1; } return 0;
    case H_MUTEX:
        if (!s->owned && (!s->handoff || waited)) {
            s->owned = 1; s->owner = pthread_self(); s->depth = 1; s->handoff = 0;
            return 1;
        }
        if (s->owned && pthread_equal(s->owner, pthread_self())) { s->depth++; return 1; }  /* recursion */
        return 0;
    case H_THREAD: return s->finished;
    default: return 1;
    }
}

/* Deterministic mode: could try_acquire succeed now? (Evaluated by the scheduler for a parked waiter.) A closed object
   wakes the waiter too: it then fails with WAIT_FAILED. */
static int can_acquire(void *p) {
    const WaitTarget *t = p;
    Sync *s = t->s;
    if (s->closed) return 1;
    switch (t->type) {
    case H_EVENT: return s->signaled;
    case H_SEMAPHORE: return s->count > 0;
    case H_MUTEX: return !s->owned;
    case H_THREAD: return s->finished;
    default: return 1;
    }
}
static uint32_t wait_one_det(WaitTarget *t, uint32_t ms) {
    Sync *s = t->s;
    uint64_t deadline = ms == 0xFFFFFFFFu ? UINT64_MAX : sched_now_us() + (uint64_t)ms * 1000ull;
    for (;;) {
        pthread_mutex_lock(&s->m);
        int ok = try_acquire(t, 1);
        int closed = s->closed;
        pthread_mutex_unlock(&s->m);
        if (ok) return 0;
        if (closed) return WAIT_FAILED_;
        if (ms == 0 || !sched_wait(can_acquire, t, deadline, NULL)) return 0x102;   /* WAIT_TIMEOUT */
    }
}

/* PORT_PROFILE_WAITS=1: counts the game thread's Sleep/SleepEx/WaitForSingleObject calls by call site (the
   first three return addresses on its stack) and prints the busiest every 3 s. A game stuck or slow in a
   polling loop shows up here as one call site with a huge count; disassemble its addresses next. */
static void profile_wait(CPU *c, const char *what, uint32_t arg) {
    static int on = -1;
    if (on < 0) on = getenv("PORT_PROFILE_WAITS") != NULL;
    if (!on || !on_game_thread()) return;
    typedef struct { const char *what; uint32_t site[3], arg, n; } Site;
    static Site tab[512];
    static int nt;
    static double last;
    uint32_t site[3] = { 0, 0, 0 };
    for (int k = 0, m = 0; k < 256 && m < 3; k++) { uint32_t v = R32(c->esp + 4 * k); if (looks_like_code(v)) site[m++] = v; }
    int i;
    for (i = 0; i < nt; i++)
        if (tab[i].what == what && tab[i].arg == arg && !memcmp(tab[i].site, site, sizeof site)) break;
    if (i == nt && nt < 512) { tab[nt] = (Site){ what, { site[0], site[1], site[2] }, arg, 0 }; nt++; }
    if (i < 512) tab[i].n++;
    double now = host_seconds();
    if (now - last < 3) return;
    last = now;
    fprintf(stderr, "[profile] busiest wait/sleep call sites (count, call, argument, return addresses):\n");
    for (int shown = 0; shown < 8; shown++) {
        int b = -1;
        for (int k = 0; k < nt; k++) if (tab[k].n && (b < 0 || tab[k].n > tab[b].n)) b = k;
        if (b < 0) break;
        fprintf(stderr, "  %9u %-20s %8x  %08x %08x %08x\n", tab[b].n, tab[b].what, tab[b].arg, tab[b].site[0], tab[b].site[1], tab[b].site[2]);
        tab[b].n = 0;   /* counts restart each report */
    }
    for (int k = 0; k < nt; k++) tab[k].n = 0;
}

/* WaitForSingleObject core. The handle is read from the table exactly once: (type, Sync*) are captured before the wait and
   the slot is not touched again, so a handle closed (and its slot reissued) by another thread during the wait can neither
   make the wait read someone else's object nor leave it blocked: the closing thread wakes it (sync_close_hook) and it
   returns WAIT_FAILED, unless the object was signaled first (a signal that arrived before the close still wins). A handle that
   is not live or not a waitable object counts as signaled, as before (the port's historical choice, kept: an invalid
   handle in the guest does not fail the wait). */
static uint32_t wait_one(uint32_t h, uint32_t ms) {
    void *obj = NULL;
    int type = handle_snapshot(h, &obj);
    if (type == H_FREE || !obj) return 0;  /* unknown objects count as signaled */
    switch (type) {
    case H_EVENT: case H_MUTEX: case H_SEMAPHORE: case H_THREAD: break;
    default: return 0;   /* find state, file, mapping...: not a sync object (its ptr is not a Sync) */
    }
    WaitTarget t = { type, obj };
    if (sched_active()) return wait_one_det(&t, ms);
    Sync *s = t.s;
    struct timespec dl;
    clock_gettime(CLOCK_REALTIME, &dl);
    if (ms != 0xFFFFFFFFu) {
        dl.tv_sec += ms / 1000;
        dl.tv_nsec += (long)(ms % 1000) * 1000000L;
        if (dl.tv_nsec >= 1000000000L) { dl.tv_sec++; dl.tv_nsec -= 1000000000L; }
    }
    pthread_mutex_lock(&s->m);
    uint32_t r = 0;
    int waited = 0;
    while (!try_acquire(&t, waited)) {
        if (s->closed) { r = WAIT_FAILED_; break; }
        if (ms == 0) { r = 0x102; break; }
        if (!waited) { waited = 1; s->waiters++; }
        int e = ms == 0xFFFFFFFFu ? pthread_cond_wait(&s->cv, &s->m) : pthread_cond_timedwait(&s->cv, &s->m, &dl);
        if (e == ETIMEDOUT && !try_acquire(&t, waited)) { r = s->closed ? WAIT_FAILED_ : 0x102 /* WAIT_TIMEOUT */; break; }
        if (e == ETIMEDOUT) break;
    }
    if (waited) {
        s->waiters--;
        if (r && s->handoff && !s->waiters) { s->handoff = 0; pthread_cond_broadcast(&s->cv); }  /* nobody left to take it */
    }
    pthread_mutex_unlock(&s->m);
    return r;
}
W(WaitForSingleObject) {
    extern uint32_t g_det_waits;
    if (on_game_thread()) g_det_waits++;
    profile_wait(c, "WaitForSingleObject", ARG(1));
    uint32_t r = wait_one(ARG(0), ARG(1));
    if (r == WAIT_FAILED_) set_error(ERROR_INVALID_HANDLE);   /* the handle was closed while this thread waited on it */
    RET(2, r);
}

/* Deterministic mode: a timed block. A zero-length sleep (a yield) also lets PORT_DET_YIELD_US (default
   1000) of virtual time pass: Cricket 07's intro-movie player (VideoPlayer.cpp) spins on
   SleepEx(0) until the next movie frame is due, and with only the 1 us per clock read that took ~6,600
   scheduler hand-offs per frame (about 2 fps). */
static int det_sleep(uint32_t ms) {
    if (!sched_active()) return 0;
    extern uint32_t g_det_sleeps;
    if (on_game_thread()) g_det_sleeps++;
    static int64_t yield_us = -1;
    if (yield_us < 0) { const char *e = getenv("PORT_DET_YIELD_US"); yield_us = e ? atoll(e) : 1000; }
    uint64_t us = ms ? (uint64_t)ms * 1000ull : (uint64_t)yield_us;
    if (!us) sched_yield_det();
    else sched_wait(NULL, NULL, sched_now_us() + us, NULL);
    return 1;
}
W(Sleep) {
    uint32_t ms = ARG(0);
    profile_wait(c, "Sleep", ms);
    if (det_sleep(ms)) RET(1, 0);
    if (ms == 0) sched_yield(); else usleep(ms * 1000);
    RET(1, 0);
}
W(SleepEx) {
    uint32_t ms = ARG(0);
    profile_wait(c, "SleepEx", ms);
    if (det_sleep(ms)) RET(2, 0);
    if (ms == 0) sched_yield(); else usleep(ms * 1000);
    RET(2, 0);
}

/* ------------------------------------------------------------------ threads */

#define THREAD_STACK_SIZE 0x100000u
static uint32_t g_next_tid = 0x200;

typedef struct { GuestThread *t; uint32_t start, param; Sync *sync; int suspended; pthread_mutex_t go_m;
                 pthread_cond_t go_cv; void *sched; } ThreadStart;
static int thread_resumed(void *p) { return !((ThreadStart *)p)->suspended; }

static void *thread_main(void *arg) {
    ThreadStart *ts = arg;
    t_self = ts->t;
    CPU *c = &ts->t->cpu;
    fpu_sync_rounding(c);
    sched_enter(ts->sched);   /* deterministic mode: runs once resumed and scheduled */
    pthread_mutex_lock(&ts->go_m);
    while (ts->suspended) pthread_cond_wait(&ts->go_cv, &ts->go_m);
    pthread_mutex_unlock(&ts->go_m);
    LOG("[kernel32] thread %x starts at %08x\n", ts->t->id, ts->start);
    PUSH32(c, ts->param);
    PUSH32(c, GUEST_RETURN_SENTINEL);
    call_indirect(c, ts->start);
    pthread_mutex_lock(&ts->sync->m);
    ts->sync->finished = 1;
    ts->sync->exit_code = c->eax;
    pthread_cond_broadcast(&ts->sync->cv);
    pthread_mutex_unlock(&ts->sync->m);
    LOG("[kernel32] thread %x exits with %u\n", ts->t->id, c->eax);
    sched_exit();
    return NULL;
}

static ThreadStart *g_threads_by_handle[4096];   /* handle slot -> its thread; ResumeThread's lookup. Cleared when the handle closes */

/* The close of a sync-object handle (handle_set_close_hook; runs once, on the thread whose close claimed the slot, before
   the slot can be reissued):
   - the object is marked closed and its waiters are woken: a wait blocked on it returns WAIT_FAILED (wait_one) instead of
     hanging for ever on an object whose last handle is gone. The object itself is never freed: a waiter or a stale pointer
     keeps a valid Sync;
   - a thread handle also loses its g_threads_by_handle entry, so a ResumeThread on the closed value does nothing instead of
     resuming a thread through a stale entry, and a later CreateThread on the reissued slot starts clean. The ThreadStart
     itself stays alive (the running thread owns it), and WaitForSingleObject/GetExitCodeThread go through the handle's
     Sync, not through this table. */
static void sync_close_hook(uint32_t h, int type, void *ptr) {
    switch (type) {
    case H_EVENT: case H_MUTEX: case H_SEMAPHORE: case H_THREAD: break;
    default: return;
    }
    if (type == H_THREAD && h >= 0x1000u && (h - 0x1000u) / 4 < 4096)
        __atomic_store_n(&g_threads_by_handle[(h - 0x1000u) / 4], NULL, __ATOMIC_RELEASE);
    Sync *s = ptr;
    if (!s) return;
    pthread_mutex_lock(&s->m);
    s->closed = 1;
    pthread_cond_broadcast(&s->cv);
    pthread_mutex_unlock(&s->m);
}

/* A guest thread context: its own CPU state, guest stack and thread information block. */
GuestThread *g_all_threads[64];   /* for the watchdog */
int g_nthreads;

GuestThread *guest_thread_new(void) {
    GuestThread *t = calloc(1, sizeof *t);
    int slot = __atomic_fetch_add(&g_nthreads, 1, __ATOMIC_SEQ_CST);
    if (slot < 64) g_all_threads[slot] = t;
    t->id = __atomic_fetch_add(&g_next_tid, 4, __ATOMIC_SEQ_CST);
    uint32_t stack = guest_valloc(THREAD_STACK_SIZE);
    t->tib = guest_valloc(0x1000);
    W32(t->tib + 0x00, 0xFFFFFFFFu);
    W32(t->tib + 0x04, stack + THREAD_STACK_SIZE);
    W32(t->tib + 0x08, stack);
    W32(t->tib + 0x18, t->tib);
    CPU *nc = &t->cpu;
    nc->esp = stack + THREAD_STACK_SIZE - 16;
    nc->fpu_cw = 0x027f;
    nc->mxcsr = 0x1f80;
    nc->fs_base = t->tib;
    nc->pf_byte = 1;
    return t;
}

W(CreateThread) {
    uint32_t start = ARG(2), param = ARG(3), flags = ARG(4), tid_out = ARG(5);
    GuestThread *t = guest_thread_new();

    ThreadStart *ts = calloc(1, sizeof *ts);
    ts->t = t; ts->start = start; ts->param = param; ts->sync = sync_new();
    ts->suspended = (flags & 4) != 0;  /* CREATE_SUSPENDED */
    pthread_mutex_init(&ts->go_m, NULL);
    pthread_cond_init(&ts->go_cv, NULL);
    /* Everything the handle refers to is in place before the value becomes a live handle (same slot as handle_new_ptr would
       give): another thread cannot close it between the publication and the table entry, which would leave a stale entry. */
    uint32_t h = handle_reserve_ptr(ts->sync);
    __atomic_store_n(&g_threads_by_handle[(h - 0x1000) / 4], ts, __ATOMIC_RELEASE);
    handle_publish(h, H_THREAD);
    if (tid_out) W32(tid_out, t->id);
    char name[24];
    snprintf(name, sizeof name, "thread %x", t->id);
    ts->sched = sched_new(name, ts->suspended ? thread_resumed : NULL, ts);
    pthread_t pt;
    pthread_attr_t at;
    pthread_attr_init(&at);
    pthread_attr_setstacksize(&at, 64u << 20);  /* host stack: recompiled frames are large (more so in wasm) */
    pthread_create(&pt, &at, thread_main, ts);
    pthread_detach(pt);
    LOG("[kernel32] CreateThread(start=%08x param=%08x flags=%x) -> handle %x tid %x\n", start, param, flags, h, t->id);
    RET(6, h);
}
W(ResumeThread) {
    uint32_t h = ARG(0);
    ThreadStart *ts = (h >= 0x1000 && (h - 0x1000) / 4 < 4096) ? __atomic_load_n(&g_threads_by_handle[(h - 0x1000) / 4], __ATOMIC_ACQUIRE) : NULL;
    if (ts) {
        pthread_mutex_lock(&ts->go_m);
        int was = ts->suspended;
        ts->suspended = 0;
        pthread_cond_broadcast(&ts->go_cv);
        pthread_mutex_unlock(&ts->go_m);
        RET(1, was);
    }
    RET(1, 0);
}
W(ExitThread) {
    LOG("[kernel32] ExitThread(%u)\n", ARG(0));
    sched_exit();
    pthread_exit(NULL);
}
W(TerminateThread) { STUB("TerminateThread(%x) ignored\n", ARG(0)); RET(2, 1); }
W(GetExitCodeThread) {
    WinHandle *x = handle_get(ARG(0), H_THREAD);
    Sync *s = x ? HANDLE_PTR(x) : NULL;
    W32(ARG(1), s && s->finished ? s->exit_code : 259 /* STILL_ACTIVE */);
    RET(2, 1);
}
W(SetThreadPriority) { RET(2, 1); }
W(GetThreadPriority) { RET(1, 0); }
W(SetThreadAffinityMask) { RET(2, 1); }
W(DuplicateHandle) {
    /* Strict share: the duplicate below is the same handle value without a reference count, so closing
       either "copy" would close the file under the other and release its share reservation. Refuse for
       a live file handle rather than pretend (ENGINE.exe does not import DuplicateHandle). */
    if (strict_share() && handle_get(ARG(1), H_FILE)) { set_error(ERROR_NOT_SUPPORTED); RET(7, 0); }
    if (ARG(3)) W32(ARG(3), ARG(1) == 0xFFFFFFFEu ? 0x1FFFFFFCu : ARG(1));
    RET(7, 1);
}
/* ------------------------------------------------------------------ share mode (opt-in strict) */

/* Windows access/share compatibility for CreateFileA. The port's default policy is permissive:
   dwShareMode is ignored and every open succeeds. That was chosen deliberately for speed and
   simplicity (see file-share-policy-diagnostic: a cross-tab authoritative share registry is
   research-only and is not wired into main). PORT_STRICT_FILE_SHARE=1 turns on the real two-sided
   rule from the CreateFileA documentation: a new open fails with ERROR_SHARING_VIOLATION when its
   desired access is not covered by an existing handle's share, or an existing handle's desired
   access is not covered by the new share. Read, write and delete are tracked per open handle,
   in-process only; other tabs or processes are invisible to this registry.

   Beyond the share matrix the strict mode (Ф3.2, F32_AUDIT.md) provides, all under g_share_lock:
   - identity: files are compared by a normalized name (separators, "." and ".." collapsed, trailing
     dots and spaces of a component dropped as Windows does, case folded) and, where the host has real
     inodes (native and Node, not the browser backend), also by (st_dev, st_ino), so hard links and
     symlinks are the same object;
   - delete-pending: DeleteFileA of a file whose open handles all share DELETE succeeds, the name stays
     (new opens fail with ERROR_ACCESS_DENIED) and the unlink happens when the last handle closes;
   - exhaustion: the share registry slot AND the handle slot are secured before any host open, so a
     full table refuses the open instead of truncating a file that then has no handle;
   - closing: CloseHandle of an invalid, already closed or in-progress handle fails with
     ERROR_INVALID_HANDLE, handle values are not reused immediately, a close is atomic per handle;
   - CopyFileA and the directory calls take part in the same registry;
   - names (K2, K2_AUDIT.md): forms whose identity the port cannot establish are refused (ERROR_INVALID_NAME,
     one LOG line each, see share_name_policy) instead of guessed, and case folding of non-ASCII names is done
     on UTF-8 (share_fold_cp) with a directory probe for an existing differently cased spelling. */
enum { SH_READ = 1, SH_WRITE = 2, SH_DELETE = 4 };
static pthread_once_t g_strict_share_once = PTHREAD_ONCE_INIT;
static int g_strict_share;
/* Unset, empty and "0" keep the permissive default (like PORT_SAVE_TX). */
static void strict_share_init(void) {
    const char *v = getenv("PORT_STRICT_FILE_SHARE");
    g_strict_share = v && *v && strcmp(v, "0") != 0;
    if (g_strict_share) handle_set_round_robin(1);
}
static int strict_share(void) {
    pthread_once(&g_strict_share_once, strict_share_init);
    return g_strict_share;
}
/* Real inodes exist on native and on Node/NODERAWFS. The browser WasmFS/OPFS backend's st_ino has never
   been verified to be unique and stable, so a false "same file" there could refuse an innocent open:
   it keeps the name comparison only. */
#if !defined(__EMSCRIPTEN__) || defined(PORT_NODE_BUILD)
#define SHARE_INODE_IDENTITY 1
#else
#define SHARE_INODE_IDENTITY 0
#endif
/* A file as the registry sees it. cs: the normalized, case-preserving host path (aliases collapsed, see
   share_name_make). cp: the same without the trailing dot/space rule, i.e. the spelling the host really
   resolves; cs equal but cp different means two names that Windows treats as one but the host does not. */
/* fs: cs with the case folded (ASCII and the UTF-8 ranges of share_fold_cp; same length and same '/' positions as cs). */
typedef struct { char cs[512], cp[512], fs[512]; int has_id; uint64_t dev, ino; } ShareName;
/* established == 0: an open in flight (the host open has not completed); h is the handle value
   reserved for it (CopyFileA reservations have h == 0 and are released by pointer). */
typedef struct { int used, established; uint32_t h, desired, share; ShareName n; } ShareRes;
#define SHARE_RES_MAX 256
#define SHARE_PENDING_MAX 32
static ShareRes g_share_res[SHARE_RES_MAX];
/* Files with a delete-pending: still on the host, unlinked when no handle refers to them any more. */
typedef struct { int used; ShareName n; char host[1024]; } SharePending;
static SharePending g_share_pending[SHARE_PENDING_MAX];
static pthread_mutex_t g_share_lock = PTHREAD_MUTEX_INITIALIZER;

static uint32_t access_categories(uint32_t access) {
    return ((access & 0x80000000u) ? SH_READ : 0) |   /* GENERIC_READ */
           ((access & 0x40000000u) ? SH_WRITE : 0) |  /* GENERIC_WRITE */
           ((access & 0x00010000u) ? SH_DELETE : 0);  /* DELETE */
}
static uint32_t share_categories(uint32_t share) {
    return share & (SH_READ | SH_WRITE | SH_DELETE);  /* FILE_SHARE_{READ,WRITE,DELETE} reuse the bits */
}
/* The rule is two-sided: each side's desired access must fit inside the other side's share. */
static int share_conflicts(uint32_t a_desired, uint32_t a_share, uint32_t b_desired, uint32_t b_share) {
    return (a_desired & ~b_share) != 0 || (b_desired & ~a_share) != 0;
}
/* UTF-8 helpers for the name policy. share_utf8_len: length of the well-formed sequence at s (no overlong
   forms, no surrogates, nothing above U+10FFFF), 0 when the bytes are not valid UTF-8. */
static int share_utf8_len(const unsigned char *s, uint32_t *cp) {
    unsigned c = s[0];
    if (c < 0x80) { *cp = c; return 1; }
    if (c >= 0xC2 && c <= 0xDF && (s[1] & 0xC0) == 0x80) { *cp = ((c & 0x1Fu) << 6) | (s[1] & 0x3Fu); return 2; }
    if (c >= 0xE0 && c <= 0xEF && (s[1] & 0xC0) == 0x80 && (s[2] & 0xC0) == 0x80) {
        uint32_t v = ((c & 0x0Fu) << 12) | ((uint32_t)(s[1] & 0x3Fu) << 6) | (s[2] & 0x3Fu);
        if (v < 0x800 || (v >= 0xD800 && v <= 0xDFFF)) return 0;
        *cp = v; return 3;
    }
    if (c >= 0xF0 && c <= 0xF4 && (s[1] & 0xC0) == 0x80 && (s[2] & 0xC0) == 0x80 && (s[3] & 0xC0) == 0x80) {
        uint32_t v = ((c & 0x07u) << 18) | ((uint32_t)(s[1] & 0x3Fu) << 12) | ((uint32_t)(s[2] & 0x3Fu) << 6) | (s[3] & 0x3Fu);
        if (v < 0x10000 || v > 0x10FFFF) return 0;
        *cp = v; return 4;
    }
    return 0;
}
/* Case folding of one code point for the name identity. Windows compares names through the volume's upcase
   table (all of Unicode); the host (OPFS, ext4, WasmFS) compares bytes, and the default host path lookup
   (core.c find_ci) folds ASCII only. The folding below covers ASCII, Latin-1, Latin Extended-A and the
   Vietnamese block, Greek, Cyrillic, Armenian and the fullwidth Latin letters, i.e. the scripts the game's
   languages use; every mapping keeps the UTF-8 length. Anything else folds to itself (a pair differing only
   in the case of such a letter is NOT recognized as one name). Special cases are left alone on purpose:
   U+0130/U+0131 (Turkish i), U+017F, U+1E9E, U+00DF/U+00B5 and context rules. */
static uint32_t share_fold_cp(uint32_t c) {
    if (c < 0x80) return (c >= 'A' && c <= 'Z') ? c + 32 : c;
    if (c < 0xC0) return c;
    if (c <= 0xDE) return c == 0xD7 ? c : c + 32;
    if (c < 0x100) return c;
    if (c <= 0x137) return (c == 0x130 || c == 0x131 || (c & 1)) ? c : c + 1;
    if (c >= 0x139 && c <= 0x147) return (c & 1) ? c + 1 : c;
    if (c >= 0x14A && c <= 0x177) return (c & 1) ? c : c + 1;
    if (c == 0x178) return 0xFF;
    if (c >= 0x179 && c <= 0x17D) return (c & 1) ? c + 1 : c;
    if (c == 0x386) return 0x3AC;
    if (c >= 0x388 && c <= 0x38A) return c + 37;
    if (c == 0x38C) return 0x3CC;
    if (c == 0x38E || c == 0x38F) return c + 63;
    if ((c >= 0x391 && c <= 0x3A1) || (c >= 0x3A3 && c <= 0x3AB)) return c + 32;
    if (c == 0x3C2) return 0x3C3;
    if (c >= 0x400 && c <= 0x40F) return c + 80;
    if (c >= 0x410 && c <= 0x42F) return c + 32;
    if ((c >= 0x460 && c <= 0x481) || (c >= 0x48A && c <= 0x4BF) || (c >= 0x4D0 && c <= 0x52F)) return (c & 1) ? c : c + 1;
    if (c == 0x4C0) return 0x4CF;
    if (c >= 0x4C1 && c <= 0x4CD) return (c & 1) ? c + 1 : c;
    if (c >= 0x531 && c <= 0x556) return c + 48;
    if ((c >= 0x1E00 && c <= 0x1E95) || (c >= 0x1EA0 && c <= 0x1EFF)) return (c & 1) ? c : c + 1;
    if (c >= 0xFF21 && c <= 0xFF3A) return c + 32;
    return c;
}
/* Folds a whole name into out (cap bytes). Bytes that are not well-formed UTF-8 are copied unchanged (such
   names are refused by share_name_policy before they reach a registry entry). The folded text has the same
   length as the input. */
static void share_fold(const char *in, char *out, size_t cap) {
    size_t o = 0;
    const unsigned char *p = (const unsigned char *)in;
    while (*p && o + 4 < cap) {
        uint32_t cp, f;
        int len = share_utf8_len(p, &cp);
        if (len > 1 && (f = share_fold_cp(cp)) != cp) {
            if (len == 2) { out[o++] = (char)(0xC0 | (f >> 6)); out[o++] = (char)(0x80 | (f & 0x3F)); }
            else if (len == 3) { out[o++] = (char)(0xE0 | (f >> 12)); out[o++] = (char)(0x80 | ((f >> 6) & 0x3F)); out[o++] = (char)(0x80 | (f & 0x3F)); }
            else for (int i = 0; i < len; i++) out[o++] = (char)p[i];
            p += len;
        } else if (len == 1) { out[o++] = (char)share_fold_cp(cp); p++; }
        else if (len > 1) { for (int i = 0; i < len; i++) out[o++] = (char)p[i]; p += len; }
        else out[o++] = (char)*p++;
    }
    out[o] = 0;
}
/* While an open may be creating parents outside the lock, reject a second
   spelling of a shared parent. Otherwise Dir/a and dir/b can concurrently
   create two Windows-equivalent directories on a case-sensitive host.
   Compares the folded names (fs) and detects the spelling difference on the originals (cs). */
static int share_parent_case_conflict(const ShareName *an, const ShareName *bn) {
    const char *a = an->cs, *b = bn->cs, *fa = an->fs, *fb = bn->fs;
    int case_difference = 0;
    while (*fa && *fb && *fa == *fb) {
        if (*a != *b) case_difference = 1;
        if (*fa == '/' && case_difference) return 1;
        ++a; ++b; ++fa; ++fb;
    }
    /* One target can itself be the other's parent, e.g. Dir/a vs dir. */
    return case_difference && ((!*fa && *fb == '/') || (!*fb && *fa == '/'));
}
/* Normalize a host path into n (and, for an existing regular file on a host with real inodes, its
   identity). Returns 0 when the name does not fit: the caller must refuse the operation. Components:
   empty and "." vanish, ".." pops one, and for cs trailing dots and spaces are dropped (Windows ignores
   them, so "data." names "data"; a component made only of those characters is kept as it is), and fs, the
   case-folded cs. This function only normalizes; the name forms it cannot identify (NTFS streams, UNC and
   "\\?\" prefixes, trailing dots of a PARENT component, bytes that are not UTF-8) are refused earlier by
   share_name_policy/share_name_for, 8.3 short names and non-listed case folding are not recognized. */
static int share_name_make(const char *host, ShareName *n) {
    memset(n, 0, sizeof *n);
    size_t out_cs = 0, out_cp = 0, st_cs[128], st_cp[128];
    int depth = 0;
    const char *p = host;
    while (*p) {
        while (*p == '/') p++;
        if (!*p) break;
        const char *q = p;
        while (*q && *q != '/') q++;
        size_t len = (size_t)(q - p);
        if (len == 1 && p[0] == '.') { p = q; continue; }
        if (len == 2 && p[0] == '.' && p[1] == '.') {
            if (depth) { depth--; out_cs = st_cs[depth]; out_cp = st_cp[depth]; }
            p = q;
            continue;
        }
        size_t keep = len;
        while (keep && (p[keep - 1] == '.' || p[keep - 1] == ' ')) keep--;
        if (!keep) keep = len;
        if (depth >= 128 || out_cs + 1 + keep >= sizeof n->cs || out_cp + 1 + len >= sizeof n->cp) return 0;
        st_cs[depth] = out_cs; st_cp[depth] = out_cp; depth++;
        n->cs[out_cs++] = '/';
        memcpy(n->cs + out_cs, p, keep);
        out_cs += keep;
        n->cp[out_cp++] = '/';
        memcpy(n->cp + out_cp, p, len);
        out_cp += len;
        p = q;
    }
    if (!out_cs) { n->cs[out_cs++] = '/'; n->cp[out_cp++] = '/'; }
    n->cs[out_cs] = 0;
    n->cp[out_cp] = 0;
    share_fold(n->cs, n->fs, sizeof n->fs);
#if SHARE_INODE_IDENTITY
    struct stat st;
    if (stat(host, &st) == 0 && S_ISREG(st.st_mode) && st.st_ino) {
        n->has_id = 1;
        n->dev = (uint64_t)st.st_dev;
        n->ino = (uint64_t)st.st_ino;
    }
#endif
    return 1;
}
/* ---- name policy (strict only, K2) ----------------------------------------------------------------
   The registry compares names. That is only sound when two spellings Windows treats as one object cannot
   reach the host as unrelated paths, and the port cannot make that true for every Windows name form. The
   forms below are therefore REFUSED (ERROR_INVALID_NAME, one LOG line) instead of guessed at:
   - UNC and device prefixes: a guest path starting with two separators ("\\server\share", "\\?\C:\...",
     "\\.\...") and the NT form "\??\...": map_path turns them into odd folders below the user root, i.e. a
     different object than the same path spelled "C:\...";
   - a drive-relative name ("C:file", "C:"): Windows resolves it against the current directory of drive C,
     map_path against the user root;
   - NTFS alternate streams ("file:stream", "dir:stream", "file::$DATA"): the host would create a file with
     a colon in its name, Windows a stream of "file", i.e. the same object as "file";
   - a trailing dot or space in a PARENT component ("dir./file"): Windows drops it, the host keeps a second,
     different folder. (The final component's trailing dots and spaces are handled by the cs/cp rule of
     share_name_make/share_relation, as before, plus a stat probe: a final component that names an EXISTING
     file once its dots and spaces are dropped is refused with ERROR_SHARING_VIOLATION; one that names nothing
     is created under its literal spelling.)
   - bytes that are not well-formed UTF-8 in a component. The browser backend does not keep such names: the
     OPFS bridge decodes the bytes leniently, so two different CP1251 names may collide and the stored name
     differs from the one the game used (measured in file-share-policy-diagnostic/k2/test-opfs-names.mjs).
     Without a stable name there is no identity to register.
   Not recognized, and not refused: 8.3 short names ("PROGRA~1": the port has no short-name table, never
   hands one to the guest (GetShortPathNameA is not implemented, cAlternateFileName is empty), so such a name
   is an ordinary literal one), normalization-form differences (NFC/NFD) and case folding outside the ranges
   of share_fold_cp. For a well-formed non-ASCII component that does not exist literally, the directory is
   scanned once for an entry that differs only by case (share_fold_cp): such a spelling is the same Windows
   object as that entry but another host file, so it is refused with ERROR_SHARING_VIOLATION.
   Lock held. Returns 0 or the Win32 error; why receives a short reason for the log. */
static int share_is_sep(char ch) { return ch == '\\' || ch == '/'; }
/* The part of a host path below the game/user root: the root's own spelling is not the guest's business. */
static const char *share_rel_of(const char *host) {
    size_t best = 0;
    const char *roots[2] = { g_game_root, g_user_root };
    for (int i = 0; i < 2; i++) {
        size_t l = strlen(roots[i]);
        if (l > best && !strncmp(host, roots[i], l) && (host[l] == '/' || host[l] == 0)) best = l;
    }
    return host + best;
}
/* 1 when directory dirpath holds an entry whose folded name equals the folded comp (same Windows name under
   another case); comp has len bytes. One readdir pass, only used where the host cannot unify the spellings. */
static int share_dir_has_fold(const char *dirpath, const char *comp, size_t len) {
    char want[512], got[512], raw[512];
    if (len == 0 || len >= sizeof raw) return 0;
    memcpy(raw, comp, len);
    raw[len] = 0;
    share_fold(raw, want, sizeof want);
    DIR *d = opendir(dirpath);
    if (!d) return 0;
    int hit = 0;
    struct dirent *e;
    while (!hit && (e = readdir(d))) {
        if (strlen(e->d_name) >= sizeof got) continue;
        share_fold(e->d_name, got, sizeof got);
        if (!strcmp(got, want)) hit = 1;
    }
    closedir(d);
    return hit;
}
static uint32_t share_name_policy(const char *guest, const char *host, const char **why) {
    const unsigned char *g = (const unsigned char *)guest;
    int drive = isalpha(g[0]) && g[1] == ':';
    if (share_is_sep((char)g[0]) && share_is_sep((char)g[1])) { *why = "UNC or device prefix"; return ERROR_INVALID_NAME; }
    if (share_is_sep((char)g[0]) && g[1] == '?' && g[2] == '?' && (share_is_sep((char)g[3]) || !g[3])) { *why = "NT object prefix"; return ERROR_INVALID_NAME; }
    if (drive && !share_is_sep((char)g[2])) { *why = "drive-relative name"; return ERROR_INVALID_NAME; }
    for (size_t i = 0; g[i]; i++)
        if (g[i] == ':' && !(drive && i == 1)) { *why = "NTFS stream or colon in name"; return ERROR_INVALID_NAME; }
    const char *rel = share_rel_of(host);
    for (const char *p = rel; *p;) {
        while (*p == '/') p++;
        if (!*p) break;
        const char *q = p;
        while (*q && *q != '/') q++;
        const char *next = q;
        while (*next == '/') next++;
        if (*next && (q[-1] == '.' || q[-1] == ' ')) { *why = "trailing dot or space in a parent component"; return ERROR_INVALID_NAME; }
        for (const char *x = p; x < q;) {
            uint32_t cp;
            int len = share_utf8_len((const unsigned char *)x, &cp);
            if (!len || x + len > q) { *why = "component is not well-formed UTF-8"; return ERROR_INVALID_NAME; }
            x += len;
        }
        if (!*next) {   /* the final component: trailing dots/spaces name the file without them on Windows */
            const char *keep = q;
            while (keep > p && (keep[-1] == '.' || keep[-1] == ' ')) keep--;
            if (keep > p && keep < q) {
                char dirpath[1024];
                size_t dlen = (size_t)(p - host);
                while (dlen > 1 && host[dlen - 1] == '/') dlen--;
                if (dlen < sizeof dirpath) {
                    memcpy(dirpath, host, dlen);
                    dirpath[dlen] = 0;
                    if (share_dir_has_fold(dirpath, p, (size_t)(keep - p))) {
                        *why = "trailing dot or space names an existing file without it";
                        return ERROR_SHARING_VIOLATION;
                    }
                }
            }
        }
        p = q;
    }
    /* directory probe for differently cased non-ASCII spellings that exist on a case-sensitive host */
    for (const char *p = rel; *p;) {
        while (*p == '/') p++;
        if (!*p) break;
        const char *q = p;
        int high = 0;
        while (*q && *q != '/') { if ((unsigned char)*q >= 0x80) high = 1; q++; }
        if (high) {
            char prefix[1024];
            size_t plen = (size_t)(q - host);
            if (plen >= sizeof prefix) { *why = "path too long"; return ERROR_FILENAME_EXCED_RANGE; }
            memcpy(prefix, host, plen);
            prefix[plen] = 0;
            struct stat st;
            if (stat(prefix, &st) != 0) {
                char dirpath[1024];
                size_t dlen = (size_t)(p - host);
                while (dlen > 1 && host[dlen - 1] == '/') dlen--;
                memcpy(dirpath, host, dlen);
                dirpath[dlen] = 0;
                if (share_dir_has_fold(dirpath, p, (size_t)(q - p))) {
                    *why = "differently cased spelling of an existing non-ASCII name";
                    return ERROR_SHARING_VIOLATION;
                }
            }
        }
        p = q;
    }
    return 0;
}
/* share_name_make plus the policy: every strict entry point builds its ShareName through this. */
static uint32_t share_name_for(const char *guest, const char *host, ShareName *n) {
    const char *why = NULL;
    uint32_t err = share_name_policy(guest, host, &why);
    if (err) {
        LOG("[file] strict name refused (%s): %s -> %s = error %u\n", why, guest, host, err);
        memset(n, 0, sizeof *n);
        return err;
    }
    return share_name_make(host, n) ? 0 : ERROR_FILENAME_EXCED_RANGE;
}
/* How two names relate: 0 unrelated; 1 the same object (the share matrix decides); 2 a spelling
   conflict that is refused whatever the share flags are (two case/alias spellings of an absent name
   or of a parent directory would create two Windows-equivalent entries on a case-sensitive host, or
   two host files for what Windows sees as one). */
static int share_relation(const ShareName *a, const ShareName *b) {
    if (a->has_id && b->has_id && a->dev == b->dev && a->ino == b->ino) return 1;
    if (!strcmp(a->fs, b->fs)) return strcmp(a->cp, b->cp) ? 2 : 1;
    return share_parent_case_conflict(a, b) ? 2 : 0;
}
/* 1 when `inner` lies below directory `dir` (case-insensitively, at a component boundary). */
static int share_is_under(const ShareName *dir, const ShareName *inner) {
    size_t n = strlen(dir->fs);
    if (!strcmp(dir->fs, "/")) return strcmp(inner->fs, "/") != 0;
    return !strncmp(dir->fs, inner->fs, n) && inner->fs[n] == '/';
}
/* Lock held. Looks for a delete-pending that names this file. */
static int share_is_pending(const ShareName *n) {
    for (int i = 0; i < SHARE_PENDING_MAX; i++)
        if (g_share_pending[i].used && share_relation(&g_share_pending[i].n, n) != 0) return 1;
    return 0;
}
static ShareRes *share_reserve(void) {
    for (int i = 0; i < SHARE_RES_MAX; i++)
        if (!g_share_res[i].used) { memset(&g_share_res[i], 0, sizeof g_share_res[i]); g_share_res[i].used = 1; return &g_share_res[i]; }
    return NULL;
}
/* Lock held. Checks a prospective open of n against the registry and delete-pending files. Returns 0 or
   the Win32 error; *conflicting receives the first conflicting handle value. */
static uint32_t share_check_open(const ShareName *n, uint32_t desired, uint32_t share, uint32_t *conflicting) {
    if (share_is_pending(n)) return ERROR_ACCESS_DENIED;   /* STATUS_DELETE_PENDING maps to ACCESS_DENIED */
    for (int i = 0; i < SHARE_RES_MAX; i++) {
        ShareRes *r = &g_share_res[i];
        if (!r->used) continue;
        int rel = share_relation(&r->n, n);
        if (rel == 2 || (rel == 1 && share_conflicts(desired, share, r->desired, r->share))) {
            if (conflicting) *conflicting = r->h;
            return ERROR_SHARING_VIOLATION;
        }
    }
    return 0;
}
static void share_run_pending(void);   /* defined after the SAVE_TX section: it journals the unlink */
static void share_drop(ShareRes *r) {
    if (r && r->used) r->used = 0;
    share_run_pending();
}
static void share_release(uint32_t h) {
    if (!h) return; /* zero denotes an open that has not published a handle */
    for (int i = 0; i < SHARE_RES_MAX; i++)
        if (g_share_res[i].used && g_share_res[i].h == h) g_share_res[i].used = 0;
}
/* ------------------------------------------------------------------ read-only snapshots */

/* Loading a save reads it in hundreds of thousands of tiny ReadFile calls (586k calls /
   1.7 MB for one known slot). On WasmFS/OPFS every read() is a proxy round trip to a
   Blob slice, ~0.3 ms each: >3 minutes per load in the browser. For a read-only
   OPEN_EXISTING handle we read the file once through the same fd at open time and serve
   further reads from that buffer. The fd stays open (mapping/pread keep working) and is
   seeked back to 0, so nothing else changes.

   Why this is safe where a generic read-ahead cache was rejected (opfs-read-ahead-diagnostic):
   - the buffer is per handle, filled once at open, freed at close: no cached bytes ever
     outlive the open that read them;
   - it only covers handles that cannot write (O_RDONLY, OPEN_EXISTING). Windows denies a
     writer while such a handle is open with FILE_SHARE_READ, so under real sharing the
     bytes cannot change mid-read anyway; the default permissive port policy lets another
     tab write, but then the plain fd path fails its reads (documented stale-Blob EIO in
     per-open-blob-race-diagnostic) instead of delivering anything coherent either;
   - if a write/truncate handle on the same host path is already open in this process,
     the snapshot is refused and the fd path is used (file_path_write_open).
   The scan (file_path_write_open) and the snapshot read are NOT atomic with a writer's open on another thread, and that
   is deliberate: whichever way that race falls, the reader gets a copy that is also what some sequential order gives
   (the snapshot taken before the writer arrived, or the live fd path), because a reader that opened first never sees a
   writer that opens later in any case (one-shot copy, test_handle_table.c part I). A writer's O_TRUNC in the window
   makes the copy empty or short, and an empty or short copy is abandoned (below). Closing the window would need a lock
   spanning the writer's host open and the reader's whole snapshot read for no new guarantee. */
static int snapshot_enabled(void) {
    static int on = -1;
    if (on < 0) {
        const char *v = getenv("PORT_FILE_SNAPSHOT");
        on = !v || strcmp(v, "0") != 0;
    }
    return on;
}
static uint64_t snapshot_max(void) {
    static uint64_t max = 0;
    if (!max) {
        const char *v = getenv("PORT_FILE_SNAPSHOT_MAX");
        max = v ? strtoull(v, NULL, 0) : 16u << 20;   /* saves are ~1.8 MB */
    }
    return max;
}
static void file_snapshot(WinHandle *x, int fd, const char *name) {
    struct stat st;
    if (fstat(fd, &st) != 0 || !S_ISREG(st.st_mode) || st.st_size <= 0 || (uint64_t)st.st_size > snapshot_max()) return;
    size_t size = (size_t)st.st_size;
    uint8_t *b = malloc(size);
    if (!b) return;
    size_t got = 0;
    while (got < size) {
        ssize_t r = read(fd, b + got, size - got);
        if (r < 0 && errno == EINTR) continue;
        if (r <= 0) {   /* short file or read error: keep the plain fd path */
            LOG("[file] CreateFileA(%s) snapshot abandoned after %u/%u bytes (%s)\n", name, (uint32_t)got, (uint32_t)size, r < 0 ? strerror(errno) : "short file");
            free(b);
            return;
        }
        got += (size_t)r;
    }
    lseek(fd, 0, SEEK_SET);   /* keep the raw cursor consistent for CreateFileMapping/pread */
    x->buf = b;
    x->buf_size = got;
    x->buf_pos = 0;
    LOG("[file] CreateFileA(%s) snapshot %u bytes\n", name, (uint32_t)got);
}

/* One switch decides the whole browser-only save-data layer: the durable
   slot-time sidecar (SAVE_META below) and the logical save transaction
   (SAVE_TX, defined beside it). Both live only in the browser build and in
   tests that opt in with -DPORT_SAVE_META=1 / -DPORT_SAVE_TX=1; native and
   Node builds keep the plain stat path and never touch either folder. The
   transaction adds a runtime opt-in (env PORT_SAVE_TX) on top: a browser
   build with the section compiled in still behaves byte-for-byte as before
   unless the page sets the variable. */
#if defined(PORT_SAVE_META)
#define SAVE_META_ON PORT_SAVE_META
#elif defined(__EMSCRIPTEN__) && !defined(PORT_NODE_BUILD)
#define SAVE_META_ON 1
#else
#define SAVE_META_ON 0
#endif

#if SAVE_META_ON
/* Logical save transaction hooks (defined in the SAVE_TX section below);
   declared here because the file handlers above that section call them. */
static void save_tx_close_hook(uint32_t h);
static void save_tx_write_hook(uint32_t h, uint32_t requested, ssize_t written);
static void save_tx_io_error(uint32_t h);
#endif

/* Values that are not table handles but that code legitimately passes to CloseHandle: the standard
   handles, GetCurrentProcess/GetCurrentThread pseudo handles, INVALID_HANDLE_VALUE after a failed open
   and DuplicateHandle's fake target. Strict CloseHandle keeps answering TRUE for these. */
static int close_is_pseudo(uint32_t h) {
    return h == STD_IN || h == STD_OUT || h == STD_ERR || h == 0xFFFFFFFFu || h == 0xFFFFFFFEu || h == 0x1FFFFFFCu;
}

W(CloseHandle) {
#if SAVE_META_ON
    save_tx_close_hook(ARG(0));   /* while the handle and its fd still exist */
#endif
    if (strict_share()) {
        /* Keep the reservation until the host close has completed. A compatible
           opener or DeleteFileA must not observe an early release. */
        uint32_t h = ARG(0);
        pthread_mutex_lock(&g_share_lock);
        int closed = handle_close_checked(h);
        if (closed) {
            share_release(h);
            share_run_pending();   /* the last close of a delete-pending file unlinks it, still under the lock */
        }
        pthread_mutex_unlock(&g_share_lock);
        if (!closed && !close_is_pseudo(h)) {
            /* never opened, already closed, closed concurrently, or not yet returned by its open */
            LOG("[file] CloseHandle(%x) rejected: not a live handle\n", h);
            set_error(ERROR_INVALID_HANDLE);
            RET(1, 0);
        }
    } else handle_close(ARG(0));
    RET(1, 1);
}

/* ------------------------------------------------------------------ files */

/* This is an activity signal, not a progress or a file-identity mechanism.
   Reads returning at least one byte from opened SAVE files increment it;
   no path leaves C. */
static uint32_t save_read_count;
ACTIVITY_EXPORT uint32_t port_save_read_count(void) {
    return __atomic_load_n(&save_read_count, __ATOMIC_RELAXED);
}
static int save_file_under(const char *path, const char *root) {
    size_t n = strlen(root);
    if (!n || strncmp(path, root, n) != 0 || path[n] != '/') return 0;
    const char *rest = path + n + 1;
    return strncasecmp(rest, "SAVE/", 5) == 0 && rest[5] != '\0';
}

/* ------------------------------------------------------------------ save slot time sidecar */

/* XINTERFACE formats each save slot's WIN32_FIND_DATAA.ftCreationTime for the
   save list, and the browser WasmFS/OPFS backend cannot supply one: its stat
   times are stamped when the in-memory node is built and change across a page
   reload (save-time-diagnostic). The browser build therefore keeps a durable
   sidecar next to the game data instead: <game root>/SAVE_META/<slot>.time
   holds exactly 8 little-endian FILETIME bytes (UTC, 100 ns units since
   1601-01-01). Records live outside SAVE/ so FindFirstFileA("SAVE\\*") never
   lists them. The SAVE_META_ON switch itself is decided once, above
   W(CloseHandle), so the sidecar and the SAVE_TX transaction below share it.

   Language label (E5, docs/english-layer.md "Метка языка слота"): the SAVE slots are shared by the Russian and the English mode,
   but NPC names and strings already in a slot stay in the language the game was created in. A slot created while the language
   overlay is on (PORT_OVERLAY, overlay_active()) therefore gets a second sidecar <game root>/SAVE_META/<slot>.lang holding exactly
   two bytes, "en". The Russian mode (overlay off) writes nothing new: no record means "not marked" (the old slots, and everything
   created in Russian). The record follows its slot like the time record: removed with it (delete, delete-pending), renamed with it
   (MoveFileA), kept by an in-place rewrite, preserved/restored by SAVE_TX (the arm line carries lang=<hex> only when a record
   exists, so a journal written in the Russian mode is byte-for-byte what it was). FindFirstFileA never lists or reads it. The label
   is the host session's mode when the slot was created (the engine overwrites a slot as delete + create): a slot loaded from
   the other language and saved again is labelled with the mode of that save. */

#if SAVE_META_ON
/* Anchored layout check reusing the load-pacing predicate above: only a flat
   file directly inside the game root's SAVE folder is a slot. Not a generic
   "SAVE substring" rule: the host path must start at g_game_root and its
   first component must be exactly (case-insensitively) SAVE. */
static int save_meta_slot(const char *host, char *slot, size_t n) {
    if (!save_file_under(host, g_game_root)) return 0;
    const char *name = host + strlen(g_game_root) + 1 + 5;
    if (!*name || strchr(name, '/')) return 0;   /* nested paths are not slots */
    snprintf(slot, n, "%s", name);
    return 1;
}
static void save_meta_path(const char *slot, char *out, size_t n) {
    snprintf(out, n, "%s/SAVE_META/%s.time", g_game_root, slot);
}
/* Exact name first, then one case-insensitive directory scan: a slot can
   reappear under a different letter case (the game matches names without
   case, OPFS stores them with), and the other spelling must still resolve.
   Anything not a readable regular file is a clean "no record". */
static int save_meta_locate_sfx(const char *slot, const char *sfx, char *path, size_t n) {
    struct stat st;
    snprintf(path, n, "%s/SAVE_META/%s%s", g_game_root, slot, sfx);
    if (stat(path, &st) == 0 && S_ISREG(st.st_mode)) return 1;
    char dir[1024], want[600];
    snprintf(dir, sizeof dir, "%s/SAVE_META", g_game_root);
    snprintf(want, sizeof want, "%s%s", slot, sfx);
    DIR *d = opendir(dir);
    if (!d) return 0;
    struct dirent *e;
    int found = 0;
    while ((e = readdir(d)))
        if (!strcasecmp(e->d_name, want)) {
            snprintf(path, n, "%s/%s", dir, e->d_name);
            found = 1;
            break;
        }
    closedir(d);
    return found && stat(path, &st) == 0 && S_ISREG(st.st_mode);
}
static int save_meta_locate(const char *slot, char *path, size_t n) {
    return save_meta_locate_sfx(slot, ".time", path, n);
}
/* Exactly 8 bytes little-endian; anything else — missing, short, unreadable —
   stays "unknown" (0) instead of guessing a date. A value outside the years
   the game can honestly stamp (1995..2100) is corruption, also "unknown". */
static uint64_t save_meta_read(const char *slot) {
    char path[1100];
    if (!save_meta_locate(slot, path, sizeof path)) return 0;
    int fd = open(path, O_RDONLY, 0644);   /* three-arg form: test shims redefine open that way */
    if (fd < 0) return 0;
    uint8_t b[8];
    size_t got = 0;
    while (got < sizeof b) {
        ssize_t r = read(fd, b + got, sizeof b - got);
        if (r < 0 && errno == EINTR) continue;
        if (r <= 0) break;
        got += (size_t)r;
    }
    close(fd);
    if (got != sizeof b) return 0;
    uint64_t ft = 0;
    for (int i = (int)sizeof b - 1; i >= 0; i--) ft = (ft << 8) | b[i];
    return ft >= 124334544000000000ull && ft <= 157469184000000000ull ? ft : 0;
}
static int save_meta_exists(const char *slot) {
    char path[1100];
    return save_meta_locate(slot, path, sizeof path);
}
/* Sidecar failures never undo the save file operation that caused them; a
   lost or unrecorded time only costs the slot's caption, which honestly
   shows 00:00. fsync retries on EINTR, like FlushFileBuffers below. */
static void save_meta_write(const char *slot, uint64_t ft) {
    char path[1100], dir[1024];
    save_meta_path(slot, path, sizeof path);
    snprintf(dir, sizeof dir, "%s/SAVE_META", g_game_root);
    mkdir(dir, 0755);   /* lazy first use; EEXIST is the normal second call */
    int fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) { LOG("[file] SAVE_META(%s): open failed: %s\n", slot, strerror(errno)); return; }
    uint8_t b[8];
    for (int i = 0; i < 8; i++) b[i] = (uint8_t)(ft >> (8 * i));
    size_t put = 0;
    int ok = 1;
    while (put < sizeof b) {
        ssize_t r = write(fd, b + put, sizeof b - put);
        if (r < 0 && errno == EINTR) continue;
        if (r <= 0) { LOG("[file] SAVE_META(%s): write failed: %s\n", slot, r < 0 ? strerror(errno) : "short write"); ok = 0; break; }
        put += (size_t)r;
    }
    if (ok) {
        int r;
        do { r = fsync(fd); } while (r < 0 && errno == EINTR);
        if (r < 0) { LOG("[file] SAVE_META(%s): fsync failed: %s\n", slot, strerror(errno)); ok = 0; }
    }
    close(fd);
    /* A partially written record reads back as an arbitrary 8-byte FILETIME,
       which the reader cannot distinguish from a real stamp. Drop it. */
    if (!ok) unlink(path);
}
/* ---- language label (see the comment above): <slot>.lang, exactly "en" (or "ru"); anything else reads as "none" */
static int save_lang_locate(const char *slot, char *path, size_t n) {
    return save_meta_locate_sfx(slot, ".lang", path, n);
}
static int save_lang_valid(const uint8_t *b) {
    return (b[0] == 'e' && b[1] == 'n') || (b[0] == 'r' && b[1] == 'u');
}
/* 1 and the two bytes when a whole valid record exists */
static int save_lang_read(const char *slot, uint8_t out[2]) {
    char path[1100];
    if (!save_lang_locate(slot, path, sizeof path)) return 0;
    int fd = open(path, O_RDONLY, 0644);
    if (fd < 0) return 0;
    uint8_t b[3];
    size_t got = 0;
    while (got < sizeof b) {   /* one byte more than the record: a longer file is not a record */
        ssize_t r = read(fd, b + got, sizeof b - got);
        if (r < 0 && errno == EINTR) continue;
        if (r <= 0) break;
        got += (size_t)r;
    }
    close(fd);
    if (got != 2 || !save_lang_valid(b)) return 0;
    out[0] = b[0]; out[1] = b[1];
    return 1;
}
static void save_lang_write(const char *slot, const char tag[2]) {
    char path[1100], dir[1024];
    snprintf(path, sizeof path, "%s/SAVE_META/%s.lang", g_game_root, slot);
    snprintf(dir, sizeof dir, "%s/SAVE_META", g_game_root);
    mkdir(dir, 0755);
    int fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) { LOG("[file] SAVE_META(%s): lang open failed: %s\n", slot, strerror(errno)); return; }
    size_t put = 0;
    int ok = 1;
    while (put < 2) {
        ssize_t r = write(fd, tag + put, 2 - put);
        if (r < 0 && errno == EINTR) continue;
        if (r <= 0) { LOG("[file] SAVE_META(%s): lang write failed: %s\n", slot, r < 0 ? strerror(errno) : "short write"); ok = 0; break; }
        put += (size_t)r;
    }
    if (ok) {
        int r;
        do { r = fsync(fd); } while (r < 0 && errno == EINTR);
        if (r < 0) { LOG("[file] SAVE_META(%s): lang fsync failed: %s\n", slot, strerror(errno)); ok = 0; }
    }
    close(fd);
    if (!ok) unlink(path);   /* a torn label reads as none; do not leave it */
}
static void save_lang_delete(const char *slot) {
    char path[1100];
    if (!save_lang_locate(slot, path, sizeof path)) return;
    if (unlink(path)) LOG("[file] SAVE_META(%s): lang unlink failed: %s\n", slot, strerror(errno));
}
/* A genuine creation: the label of the mode that creates the slot. With the overlay off nothing is written; a record that
   an earlier, vanished slot of this name left behind (exact name only: one stat, an unlink only if the record exists) must not claim the new slot. */
static void save_lang_on_create(const char *slot) {
    if (overlay_active()) save_lang_write(slot, "en");
    else {
        char path[1100];
        struct stat st;
        snprintf(path, sizeof path, "%s/SAVE_META/%s.lang", g_game_root, slot);
        if (stat(path, &st) == 0) unlink(path);   /* a read-only probe: the Russian mode makes no mutating call unless a stale label exists */
    }
}

/* Records follow their file, not its bytes: as in the XP era, a rewrite
   (CREATE_ALWAYS / TRUNCATE_EXISTING over an existing slot) keeps the old
   creation time, while a genuine creation stamps the current time. A slot
   that predates the sidecar gets stamped at its first rewrite, as an honest
   observation of that write. */
static void save_meta_create_hook(const char *host, uint32_t disp, int existed) {
    char slot[1024];
    if (!save_meta_slot(host, slot, sizeof slot)) return;
    /* A fresh creation is the overwrite flow's normal shape: the game deletes
       the old slot first and re-creates it with CREATE_ALWAYS (disp 2), so a
       CREATE_ALWAYS over an absent name is a genuine creation. */
    if (!existed && (disp == 1 || disp == 2 || disp == 4)) {
        save_meta_write(slot, guest_time_100ns());
        save_lang_on_create(slot);
    } else if ((disp == 2 || disp == 5) && existed && !save_meta_exists(slot))
        save_meta_write(slot, guest_time_100ns());   /* legacy slot without a record */
    /* CREATE_ALWAYS / OPEN_ALWAYS / TRUNCATE_EXISTING over an existing file
       with a record: keep the old creation time. OPEN_EXISTING: no change. */
}
static void save_meta_delete(const char *slot) {
    char path[1100];
    if (save_meta_locate(slot, path, sizeof path)) {
        /* Order: the save file first, this record second — an orphan record after
           a crash in between names a file that no longer exists and stays inert. */
        if (unlink(path)) LOG("[file] SAVE_META(%s): unlink failed: %s\n", slot, strerror(errno));
    }
    save_lang_delete(slot);   /* the language label goes with the slot, whatever mode deletes it */
}

/* ------------------------------------------------------------------ logical save transaction */

/* Ф4.2, default OFF (runtime env PORT_SAVE_TX; tests may also compile with
   -DPORT_SAVE_TX=1). The engine overwrites a slot as
   DeleteFileA(old) -> CreateFileA(CREATE_ALWAYS, new) -> write/close ->
   write/close: PROGRAM/seadogs.c SaveGame runs SaveEngineState and
   ISetSaveData as two separate open-write-close stages, and ProcessSave
   re-derives the slot name AFTER the delete, so the new name may differ from
   the deleted one. A crash between those stages used to leave the deletion or
   an intermediate snapshot as the slot's current version. With the flag set,
   the host journals an intent BEFORE any destructive step on a flat SAVE slot
   (the unlink of DeleteFileA, or the open of an EXISTING slot for writing,
   which may truncate it): the previous slot bytes and their 8-byte SAVE_META
   record are copied into <game root>/SAVE_TX and fsynced first. SAVE_TX is a
   sibling of SAVE, so FindFirstFileA("SAVE\\*") never lists it; the page-side
   asset filter (save-protection.mjs selectGameAssets) excludes it from
   downloadable assets like SAVE_META (the dist/serve scripts do not know it
   yet: they only matter for a game folder that was played with the flag on).

   The following write cycles are observed through the real handlers
   (CreateFileA, WriteFile, SetEndOfFile, FlushFileBuffers, ReadFile errors,
   CloseHandle). Completion is the strongest sign provable on this layer:
   BOTH write cycles of the same target ended with zero I/O errors (a short or
   zero-byte write counts as an error; each cycle is fsynced by the close hook
   before the engine's close completes), AND the final bytes were re-read from
   disk after the second close and hashed. The size + SHA-256 fixture is
   journaled (fsynced) only then. Neither a single close nor the engine's own
   return values prove completion (the first stage ignores its inner I/O
   result; the second does not check its three writes — logical-save-prototype
   SAVE_FORMAT_AUDIT.md), which is exactly why the fixture exists. It proves
   byte stability of what was written, NOT that the game state serialized
   into those bytes is semantically valid.

   Recovery lives on the page (recomp/web/save-tx.mjs): under the page-lifetime
   save lock it accepts a committed fixture only when the on-disk bytes still
   match it, rolls an interrupted intent back to the previous completed
   version (bytes and sidecar record), or quarantines what it cannot accept —
   an intermediate snapshot never becomes current, and nothing is deleted that
   was not first copied.

   The game keeps writing the real slot file exactly as before; SAVE itself is
   never redirected and no migration of existing slots exists. Host rename()
   is deliberately not used: the browser WasmFS/OPFS backend offers no proven
   atomic publish for it (the MoveFileA rejection comment above), while
   copy+fsync+append is the pattern SAVE_META already relies on.

   Failure policy. If the host cannot make the prior copy and the arm record
   durable (quota, I/O error), the destructive operation proceeds exactly as
   with the flag off and the gap is logged: refusing a delete would also
   forbid the explicit "delete slot to free space" action, and the engine
   does not handle a failed save open gracefully either. That is the one
   documented unprotected path (see SAVE_TX_IMPLEMENTATION.md). Explicit user
   deletes are indistinguishable from the delete inside an overwrite on this
   layer (same MSG_INTERFACE_DELETE_SAVE_FILE): a delete that no create
   follows within SAVE_TX_BIND_100NS is journaled as "settle"; recovery only
   honors a lone delete when it is settled or older than a threshold, and
   rolls fresh ones back — the lossless direction. The deleted bytes stay in
   SAVE_TX/prior-* either way.

   Journal format (one append-only text line per event, fsynced before the
   operation it protects proceeds; every line ends with crc=<CRC-32 hex of the
   text before " crc=">; a record starts on a fresh line even after a torn
   tail; events: arm, create, create-fail, cycle, fail, anomaly, commit, abort,
   settle — "resolved" lines are appended by the page only). All values are
   token-safe: names are hex-encoded UTF-8 bytes. Documented in
   recomp/web/save-tx.mjs, which parses it. */
static int g_save_tx_on = -1;
static int save_tx_on(void) {
    int v = __atomic_load_n(&g_save_tx_on, __ATOMIC_RELAXED);
    if (v < 0) {
#if defined(PORT_SAVE_TX)
        v = PORT_SAVE_TX ? 1 : 0;
#else
        const char *e = getenv("PORT_SAVE_TX");
        v = e && *e && strcmp(e, "0") != 0;
#endif
        __atomic_store_n(&g_save_tx_on, v, __ATOMIC_RELAXED);
    }
    return v;
}

#define SAVE_TX_DIR "SAVE_TX"
#define SAVE_TX_JOURNAL "journal.log"
#define SAVE_TX_BIND_100NS (30ull * 10000000ull)   /* a create within 30 s of the delete belongs to it */
#define SAVE_TX_TRACK_MAX 8      /* simultaneously tracked write opens of the target */
#define SAVE_TX_ARM_MAX 8        /* protected slots per intent */
#define SAVE_TX_HISTORY_MAX 4    /* priors of committed intents kept (the page prunes to the same bound) */

/* Compact SHA-256 for journal fixtures (sizes/hashes of slot bytes). The
   round constants are the standard ones (identical to save-protection.mjs on
   the page side, so recovery recomputes the same digests). */
typedef struct { uint32_t h[8]; uint64_t len; uint8_t buf[64]; size_t fill; } SaveTxSha;
static const uint32_t save_tx_k[64] = {
    0x428a2f98,0x71374491,0xb5c0fbcf,0xe9b5dba5,0x3956c25b,0x59f111f1,0x923f82a4,0xab1c5ed5,
    0xd807aa98,0x12835b01,0x243185be,0x550c7dc3,0x72be5d74,0x80deb1fe,0x9bdc06a7,0xc19bf174,
    0xe49b69c1,0xefbe4786,0x0fc19dc6,0x240ca1cc,0x2de92c6f,0x4a7484aa,0x5cb0a9dc,0x76f988da,
    0x983e5152,0xa831c66d,0xb00327c8,0xbf597fc7,0xc6e00bf3,0xd5a79147,0x06ca6351,0x14292967,
    0x27b70a85,0x2e1b2138,0x4d2c6dfc,0x53380d13,0x650a7354,0x766a0abb,0x81c2c92e,0x92722c85,
    0xa2bfe8a1,0xa81a664b,0xc24b8b70,0xc76c51a3,0xd192e819,0xd6990624,0xf40e3585,0x106aa070,
    0x19a4c116,0x1e376c08,0x2748774c,0x34b0bcb5,0x391c0cb3,0x4ed8aa4a,0x5b9cca4f,0x682e6ff3,
    0x748f82ee,0x78a5636f,0x84c87814,0x8cc70208,0x90befffa,0xa4506ceb,0xbef9a3f7,0xc67178f2};
static uint32_t save_tx_rotr(uint32_t x, int n) { return (x >> n) | (x << (32 - n)); }
static void save_tx_sha_init(SaveTxSha *s) {
    s->h[0]=0x6a09e667; s->h[1]=0xbb67ae85; s->h[2]=0x3c6ef372; s->h[3]=0xa54ff53a;
    s->h[4]=0x510e527f; s->h[5]=0x9b05688c; s->h[6]=0x1f83d9ab; s->h[7]=0x5be0cd19;
    s->len = 0; s->fill = 0;
}
static void save_tx_sha_block(SaveTxSha *s, const uint8_t *p) {
    uint32_t w[64];
    for (int i = 0; i < 16; i++)
        w[i] = ((uint32_t)p[4*i] << 24) | ((uint32_t)p[4*i+1] << 16) | ((uint32_t)p[4*i+2] << 8) | p[4*i+3];
    for (int i = 16; i < 64; i++) {
        uint32_t s0 = save_tx_rotr(w[i-15],7) ^ save_tx_rotr(w[i-15],18) ^ (w[i-15] >> 3);
        uint32_t s1 = save_tx_rotr(w[i-2],17) ^ save_tx_rotr(w[i-2],19) ^ (w[i-2] >> 10);
        w[i] = w[i-16] + s0 + w[i-7] + s1;
    }
    uint32_t a=s->h[0],b=s->h[1],c=s->h[2],d=s->h[3],e=s->h[4],f=s->h[5],g=s->h[6],hh=s->h[7];
    for (int i = 0; i < 64; i++) {
        uint32_t S1 = save_tx_rotr(e,6) ^ save_tx_rotr(e,11) ^ save_tx_rotr(e,25);
        uint32_t ch = (e & f) ^ (~e & g);
        uint32_t t1 = hh + S1 + ch + save_tx_k[i] + w[i];
        uint32_t S0 = save_tx_rotr(a,2) ^ save_tx_rotr(a,13) ^ save_tx_rotr(a,22);
        uint32_t mj = (a & b) ^ (a & c) ^ (b & c);
        uint32_t t2 = S0 + mj;
        hh=g; g=f; f=e; e=d+t1; d=c; c=b; b=a; a=t1+t2;
    }
    s->h[0]+=a; s->h[1]+=b; s->h[2]+=c; s->h[3]+=d; s->h[4]+=e; s->h[5]+=f; s->h[6]+=g; s->h[7]+=hh;
}
static void save_tx_sha_update(SaveTxSha *s, const void *data, size_t n) {
    const uint8_t *p = data;
    s->len += n;
    while (n) {
        size_t take = 64 - s->fill < n ? 64 - s->fill : n;
        memcpy(s->buf + s->fill, p, take);
        s->fill += take; p += take; n -= take;
        if (s->fill == 64) { save_tx_sha_block(s, s->buf); s->fill = 0; }
    }
}
static void save_tx_sha_hex(SaveTxSha *s, char out[65]) {
    static const char hexd[] = "0123456789abcdef";
    uint64_t bits = s->len * 8;
    uint8_t pad = 0x80;
    save_tx_sha_update(s, &pad, 1);
    uint8_t zero = 0;
    while (s->fill != 56) save_tx_sha_update(s, &zero, 1);
    uint8_t lenb[8];
    for (int i = 0; i < 8; i++) lenb[i] = (uint8_t)(bits >> (8 * (7 - i)));
    save_tx_sha_update(s, lenb, 8);
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 4; j++) {
            out[i*8 + j*2] = hexd[(s->h[i] >> (28 - j*8)) & 15];
            out[i*8 + j*2 + 1] = hexd[(s->h[i] >> (24 - j*8)) & 15];
        }
    out[64] = 0;
}
/* CRC-32 (IEEE, same polynomial as the ZIP code on the page) guarding every
   journal line against a torn or damaged record. */
static uint32_t save_tx_crc32(const char *p, size_t n) {
    uint32_t c = 0xffffffffu;
    while (n--) {
        c ^= (uint8_t)*p++;
        for (int k = 0; k < 8; k++) c = (c >> 1) ^ (0xedb88320u & (0u - (c & 1u)));
    }
    return ~c;
}

static char g_save_tx_dir[1100];
static void save_tx_begin_dir(void) {
    if (!g_save_tx_dir[0]) snprintf(g_save_tx_dir, sizeof g_save_tx_dir, "%s/%s", g_game_root, SAVE_TX_DIR);
    mkdir(g_save_tx_dir, 0755);   /* lazy first use; EEXIST is the normal later call */
}
/* Hex-encode raw path bytes so journal lines stay whitespace/UTF-8 safe; the
   page decodes them back to bytes and reads OPFS names the same way it always
   has (valid UTF-8, which the game's slot names are). Returns 0 when it did
   not fit (the caller then refuses to journal rather than truncate a name). */
static int save_tx_hex(const char *in, char *out, size_t outn) {
    static const char hexd[] = "0123456789abcdef";
    size_t o = 0;
    for (const unsigned char *p = (const unsigned char *)in; *p; p++) {
        if (o + 3 > outn) { out[0] = 0; return 0; }
        out[o++] = hexd[*p >> 4];
        out[o++] = hexd[*p & 15];
    }
    out[o] = 0;
    return 1;
}
static void save_tx_meta_hex(const char *slot, char *out /* 17 */) {
    char path[1100];
    snprintf(out, 2, "-");
    if (!save_meta_locate(slot, path, sizeof path)) return;
    int fd = open(path, O_RDONLY, 0644);
    if (fd < 0) return;
    uint8_t b[8];
    size_t got = 0;
    while (got < sizeof b) {
        ssize_t r = read(fd, b + got, sizeof b - got);
        if (r < 0 && errno == EINTR) continue;
        if (r <= 0) break;
        got += (size_t)r;
    }
    close(fd);
    if (got != sizeof b) return;   /* a torn record behaves like none: both read as "unknown" */
    static const char hexd[] = "0123456789abcdef";
    for (int i = 0; i < 8; i++) {
        out[i*2] = hexd[b[i] >> 4];
        out[i*2 + 1] = hexd[b[i] & 15];
    }
    out[16] = 0;
}

/* The slot's language label as 4 hex chars (the two bytes), or "" when there is none: the arm line carries it only then. */
static void save_tx_lang_hex(const char *slot, char *out /* 5 */) {
    static const char hexd[] = "0123456789abcdef";
    uint8_t b[2];
    out[0] = 0;
    if (!save_lang_read(slot, b)) return;
    for (int i = 0; i < 2; i++) { out[i*2] = hexd[b[i] >> 4]; out[i*2 + 1] = hexd[b[i] & 15]; }
    out[4] = 0;
}

/* The intent of one save, mutated only under g_save_tx_lock. Hooks take that
   small mutex on every call while the flag is on; none of them ever takes
   g_share_lock, so the strict-path order g_share_lock -> g_save_tx_lock (the
   DeleteFileA arm) can never invert. */
typedef struct { char host[1024]; char slot[1024]; char prior[64]; int is_delete; } SaveTxArm;
static pthread_mutex_t g_save_tx_lock = PTHREAD_MUTEX_INITIALIZER;
static struct {
    int state;               /* 0 idle, 1 armed (no create yet), 2 writing, 3 committed, 4 failed */
    char tx[32];             /* id of the live intent, 20 hex chars */
    unsigned seq;
    int arm_count, arm_serial;
    SaveTxArm arms[SAVE_TX_ARM_MAX];
    uint64_t last_ts;        /* host time of the live intent's latest journaled event */
    char target[1024];       /* host path being written, state 2 */
    int cycles_done, writes, errors;
    uint64_t bytes;
    struct { uint32_t h; int active; } opens[SAVE_TX_TRACK_MAX];   /* h == 0: open pending */
    int active_opens;
    /* priors of committed intents, oldest first. One commit appends up to SAVE_TX_ARM_MAX priors before
       save_tx_trim_history cuts back to SAVE_TX_HISTORY_MAX, so the array must hold both (it was sized to the
       bound alone and the fifth commit wrote past it, corrupting the fields behind it: wasm trap in the
       threaded unit test, ~40% of runs). */
    char history[SAVE_TX_HISTORY_MAX + SAVE_TX_ARM_MAX][64];
    int history_count;
} g_save_tx;

/* Append one event; returns 1 only when the whole line (newline included) was
   written and fsynced. Lock held. */
static int save_tx_emit(const char *event, const char *fmt, ...) {
    char body[2200], line[2300];
    int n = snprintf(body, sizeof body, "v1 %s tx=%s ts=%llu", event, g_save_tx.tx,
                     (unsigned long long)host_time_100ns());
    if (n < 0 || (size_t)n >= sizeof body) return 0;
    if (fmt && *fmt) {
        va_list ap;
        va_start(ap, fmt);
        int m = vsnprintf(body + n, sizeof body - (size_t)n - 1, fmt, ap);
        va_end(ap);
        if (m < 0 || (size_t)m >= sizeof body - (size_t)n - 1) { LOG("[save-tx] journal line too long, dropped\n"); return 0; }
    }
    int len = snprintf(line, sizeof line, "%s crc=%08x\n", body, save_tx_crc32(body, strlen(body)));
    if (len < 0 || (size_t)len >= sizeof line) return 0;
    save_tx_begin_dir();
    char path[1300];
    snprintf(path, sizeof path, "%s/%s", g_save_tx_dir, SAVE_TX_JOURNAL);
    int fd = open(path, O_RDWR | O_CREAT | O_APPEND, 0644);
    if (fd < 0) { LOG("[save-tx] journal open failed: %s\n", strerror(errno)); return 0; }
    /* A torn previous record has no newline: start this one on a fresh line so
       the two cannot merge into one line with a plausible checksum. */
    int lead = 0;
    struct stat st;
    if (fstat(fd, &st) == 0 && st.st_size > 0) {
        char last = '\n';
        if (pread(fd, &last, 1, st.st_size - 1) == 1 && last != '\n') lead = 1;
    }
    char out[2310];
    size_t outn = 0;
    if (lead) out[outn++] = '\n';
    memcpy(out + outn, line, (size_t)len);
    outn += (size_t)len;
    size_t put = 0;
    int ok = 1;
    while (put < outn) {
        ssize_t r = write(fd, out + put, outn - put);
        if (r < 0 && errno == EINTR) continue;
        if (r <= 0) { LOG("[save-tx] journal write failed: %s\n", r < 0 ? strerror(errno) : "short write"); ok = 0; break; }
        put += (size_t)r;
    }
    if (ok) {
        int r;
        do { r = fsync(fd); } while (r < 0 && errno == EINTR);
        if (r < 0) { LOG("[save-tx] journal fsync failed: %s\n", strerror(errno)); ok = 0; }
    }
    close(fd);
    return ok;
}

static int save_tx_track_find(uint32_t h) {
    for (int i = 0; i < SAVE_TX_TRACK_MAX; i++)
        if (h && g_save_tx.opens[i].active && g_save_tx.opens[i].h == h) return i;
    return -1;
}
static int save_tx_track_reserve(void) {   /* pending open of the target */
    for (int i = 0; i < SAVE_TX_TRACK_MAX; i++)
        if (!g_save_tx.opens[i].active) {
            g_save_tx.opens[i].h = 0;
            g_save_tx.opens[i].active = 1;
            g_save_tx.active_opens++;
            return i;
        }
    return -1;
}
static void save_tx_track_release(int i) {
    if (i >= 0 && g_save_tx.opens[i].active) {
        g_save_tx.opens[i].active = 0;
        g_save_tx.opens[i].h = 0;
        g_save_tx.active_opens--;
    }
}
/* Read a whole slot file back, hashing what is actually on disk: the commit
   fixture. One extra read pass per save, paid only while the flag is on. */
static int save_tx_read_sha(const char *path, uint64_t *size, char sha[65]) {
    int fd = open(path, O_RDONLY, 0644);
    if (fd < 0) return -1;
    SaveTxSha s;
    save_tx_sha_init(&s);
    uint8_t buf[32 * 1024];
    uint64_t total = 0;
    for (;;) {
        ssize_t r;
        do { r = read(fd, buf, sizeof buf); } while (r < 0 && errno == EINTR);
        if (r < 0) { close(fd); return -1; }
        if (r == 0) break;
        save_tx_sha_update(&s, buf, (size_t)r);
        total += (uint64_t)r;
    }
    close(fd);
    save_tx_sha_hex(&s, sha);
    *size = total;
    return 0;
}
/* Copy `src` to `dst` hashing the bytes read; used for the prior copy. The
   copy is re-read and re-hashed after the fsync, so a copy that did not land
   intact is never trusted. Any failure removes the partial copy. errno is
   preserved for the caller's ENOSPC reporting. */
static int save_tx_copy_sha(const char *src, const char *dst, uint64_t *size, char sha[65]) {
    int in = open(src, O_RDONLY, 0644);
    if (in < 0) return -1;
    int out = open(dst, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (out < 0) { int e = errno; close(in); errno = e; return -1; }
    SaveTxSha s;
    save_tx_sha_init(&s);
    uint8_t buf[32 * 1024];
    uint64_t total = 0;
    int ok = 1, err = 0;
    for (;;) {
        ssize_t r;
        do { r = read(in, buf, sizeof buf); } while (r < 0 && errno == EINTR);
        if (r < 0) { ok = 0; err = errno; break; }
        if (r == 0) break;
        save_tx_sha_update(&s, buf, (size_t)r);
        size_t put = 0;
        while (put < (size_t)r) {
            ssize_t w;
            do { w = write(out, buf + put, (size_t)r - put); } while (w < 0 && errno == EINTR);
            if (w <= 0) { ok = 0; err = w < 0 ? errno : ENOSPC; break; }
            put += (size_t)w;
        }
        if (!ok) break;
        total += (uint64_t)r;
    }
    if (ok) {
        int fr;
        do { fr = fsync(out); } while (fr < 0 && errno == EINTR);
        if (fr < 0) { ok = 0; err = errno; }
    }
    close(in);
    close(out);
    char sha1[65];
    uint64_t size1 = 0;
    save_tx_sha_hex(&s, sha);
    if (ok && (save_tx_read_sha(dst, &size1, sha1) || size1 != total || strcmp(sha1, sha))) { ok = 0; err = EIO; }
    if (!ok) { unlink(dst); errno = err; return -1; }
    *size = total;
    return 0;
}

/* Starting point of every hook that begins or extends an intent. Decides
   whether the live intent (if any) is closed, bound or in the way. Returns 0
   when the new operation must stay unprotected (an overlapping writer: the
   live intent is failed instead). On return the state is 0 (fresh intent,
   new id) or 1 (the operation binds to the armed intent). Lock held. */
static int save_tx_prepare(void) {
    uint64_t now = host_time_100ns();
    if (g_save_tx.state == 1) {
        if (now > g_save_tx.last_ts && now - g_save_tx.last_ts > SAVE_TX_BIND_100NS) {
            /* the delete(s) stood alone: an explicit user delete */
            if (!save_tx_emit("settle", "")) LOG("[save-tx] settle line not durable\n");
            g_save_tx.state = 0;
        } else return 1;
    } else if (g_save_tx.state == 2) {
        if (g_save_tx.active_opens > 0) {
            save_tx_emit("anomaly", " what=overlap");
            LOG("[save-tx] a second save operation overlaps the live one: the live intent fails\n");
            g_save_tx.state = 4;
            return 0;
        }
        /* between the two cycles, and some other slot starts: stage 2 never came */
        save_tx_emit("fail", " reason=superseded");
        LOG("[save-tx] intent %s never finished its second stage\n", g_save_tx.tx);
        g_save_tx.state = 4;
    }
    /* idle, committed or failed: a fresh intent (the old one's records stay) */
    unsigned seq = ++g_save_tx.seq;
    snprintf(g_save_tx.tx, sizeof g_save_tx.tx, "%016llx%04x", (unsigned long long)host_time_100ns(), seq & 0xffffu);
    g_save_tx.arm_count = 0;
    g_save_tx.arm_serial = 0;
    g_save_tx.target[0] = 0;
    g_save_tx.cycles_done = g_save_tx.writes = g_save_tx.errors = 0;
    g_save_tx.bytes = 0;
    /* handles of a failed/finished intent no longer count; an entry left here
       would make every later save look like an overlapping writer */
    memset(g_save_tx.opens, 0, sizeof g_save_tx.opens);
    g_save_tx.active_opens = 0;
    g_save_tx.state = 0;
    return 1;
}

/* Copy the slot's bytes + record and journal the arm. 0 on failure (nothing
   left behind but, at worst, an unreferenced prior copy that was removed). */
static int save_tx_arm_locked(const char *host, const char *slot, int is_delete) {
    if (g_save_tx.arm_count >= SAVE_TX_ARM_MAX) { LOG("[save-tx] too many protected slots in one intent\n"); return 0; }
    save_tx_begin_dir();
    char prior[64], src[1200], sha[65], hex[2048], meta[17], lang[8];
    snprintf(prior, sizeof prior, "prior-%s-%x", g_save_tx.tx, (unsigned)++g_save_tx.arm_serial);
    snprintf(src, sizeof src, "%s/%s", g_save_tx_dir, prior);
    uint64_t size = 0;
    if (save_tx_copy_sha(host, src, &size, sha)) {
        LOG("[save-tx] arm(%s): prior copy failed (%s)\n", slot, strerror(errno));
        return 0;
    }
    save_tx_meta_hex(slot, meta);
    save_tx_lang_hex(slot, lang);
    if (!save_tx_hex(slot, hex, sizeof hex)) { unlink(src); return 0; }
    if (!save_tx_emit("arm", lang[0] ? " kind=%s slot=%s prior=%s size=%llu sha=%s meta=%s lang=%s" : " kind=%s slot=%s prior=%s size=%llu sha=%s meta=%s",
                      is_delete ? "delete" : "trunc", hex, prior, (unsigned long long)size, sha, meta, lang)) {
        /* The record may or may not have reached the disk; keep the copy (it
           is the only extra copy of the slot) rather than unlink it. */
        LOG("[save-tx] arm(%s): journal not durable; the prior copy %s is kept\n", slot, prior);
        return 0;
    }
    SaveTxArm *a = &g_save_tx.arms[g_save_tx.arm_count++];
    snprintf(a->host, sizeof a->host, "%s", host);
    snprintf(a->slot, sizeof a->slot, "%s", slot);
    snprintf(a->prior, sizeof a->prior, "%s", prior);
    a->is_delete = is_delete;
    g_save_tx.state = 1;
    g_save_tx.last_ts = host_time_100ns();
    LOG("[save-tx] armed %s (%s) -> %s, %llu bytes\n", slot, is_delete ? "delete" : "trunc", prior, (unsigned long long)size);
    return 1;
}

/* W(DeleteFileA) of an existing flat SAVE slot, before the unlink. Returns 1
   when the delete is protected by a durable arm (then, if the unlink fails,
   save_tx_delete_failed cancels it). */
static int save_tx_arm_slot(const char *host) {
    if (!save_tx_on()) return 0;
    char slot[1024];
    if (!save_meta_slot(host, slot, sizeof slot)) return 0;
    struct stat st;
    if (stat(host, &st) != 0 || !S_ISREG(st.st_mode)) return 0;   /* ENOENT delete: nothing to protect */
    pthread_mutex_lock(&g_save_tx_lock);
    if (g_save_tx.state == 1 && g_save_tx.arm_count >= SAVE_TX_ARM_MAX) {
        /* a long run of deletes (clearing many slots): close this intent as stand-alone deletes and start the next */
        if (!save_tx_emit("settle", "")) LOG("[save-tx] settle line not durable\n");
        g_save_tx.state = 0;
    }
    int ok = save_tx_prepare() && save_tx_arm_locked(host, slot, 1);
    if (!ok) LOG("[save-tx] delete of %s proceeds without protection\n", slot);
    pthread_mutex_unlock(&g_save_tx_lock);
    return ok;
}
/* The delete that the last arm protected did not happen (sharing violation,
   permission): the intent must not resurrect a file that was never removed,
   so that arm is cancelled in the journal and its prior copy released. */
static void save_tx_delete_failed(const char *host) {
    if (!save_tx_on()) return;
    pthread_mutex_lock(&g_save_tx_lock);
    if (g_save_tx.state == 1)
        for (int i = g_save_tx.arm_count - 1; i >= 0; i--) {
            SaveTxArm *a = &g_save_tx.arms[i];
            if (!a->is_delete || strcmp(a->host, host)) continue;
            char hex[2048];
            if (save_tx_hex(a->slot, hex, sizeof hex) && save_tx_emit("abort", " slot=%s prior=%s", hex, a->prior)) {
                char p[1200];
                snprintf(p, sizeof p, "%s/%s", g_save_tx_dir, a->prior);
                if (unlink(p)) LOG("[save-tx] abort: prior %s unlink failed: %s\n", a->prior, strerror(errno));
                memmove(a, a + 1, (size_t)(g_save_tx.arm_count - i - 1) * sizeof *a);
                if (--g_save_tx.arm_count == 0) g_save_tx.state = 0;
            }   /* abort not durable: the arm stays; recovery sees an intact file equal to its prior */
            break;
        }
    pthread_mutex_unlock(&g_save_tx_lock);
}

/* W(CreateFileA), just before the host open, for an open that may write or
   truncate. Returns 0 (not tracked), 1 (an attempt of the live intent was
   journaled: the caller must report the open's outcome to save_tx_postcreate)
   or 2 (another write open of the live target: the second stage). */
static int save_tx_precreate(const char *host, int write_open, int exists) {
    if (!save_tx_on() || !write_open) return 0;
    char slot[1024], hex[2048];
    if (!save_meta_slot(host, slot, sizeof slot)) return 0;
    pthread_mutex_lock(&g_save_tx_lock);
    int r = 0;
    if (g_save_tx.state == 2 && !strcasecmp(host, g_save_tx.target)) {
        if (save_tx_track_reserve() < 0) {
            g_save_tx.errors++;   /* table exhausted: the cycle cannot be proven, so it will not commit */
            LOG("[save-tx] write-open tracking table full for %s: the intent cannot commit\n", slot);
        } else r = 2;
    } else if (save_tx_prepare()) {
        int armed_ok = 1;
        if (exists) armed_ok = save_tx_arm_locked(host, slot, 0);   /* before the open can truncate */
        if (!armed_ok) {
            LOG("[save-tx] write to existing %s proceeds without protection\n", slot);
            if (g_save_tx.arm_count) {   /* earlier delete arm(s) of this intent: fail it, recovery restores them */
                save_tx_emit("fail", " reason=unprotected-create");
                g_save_tx.state = 4;
            }
        } else if (!save_tx_hex(slot, hex, sizeof hex) ||
                   !save_tx_emit("create", " target=%s fresh=%d", hex, exists ? 0 : 1)) {
            LOG("[save-tx] create(%s): journal not durable; the intent fails conservatively\n", slot);
            if (g_save_tx.arm_count) g_save_tx.state = 4;
        } else {
            snprintf(g_save_tx.target, sizeof g_save_tx.target, "%s", host);
            g_save_tx.cycles_done = g_save_tx.writes = g_save_tx.errors = 0;
            g_save_tx.bytes = 0;
            g_save_tx.state = 2;
            g_save_tx.last_ts = host_time_100ns();
            save_tx_track_reserve();   /* table is empty at a fresh intent */
            r = 1;
        }
    }
    pthread_mutex_unlock(&g_save_tx_lock);
    return r;
}
/* Report the outcome of the open that save_tx_precreate announced: h is the
   new handle, or 0 when the open failed (err is its errno). */
static void save_tx_postcreate(const char *host, int token, uint32_t h, int err) {
    if (!token) return;
    pthread_mutex_lock(&g_save_tx_lock);
    int slot_i = -1;
    for (int i = 0; i < SAVE_TX_TRACK_MAX; i++)
        if (g_save_tx.opens[i].active && !g_save_tx.opens[i].h) { slot_i = i; break; }
    if (h) {
        if (slot_i >= 0) g_save_tx.opens[slot_i].h = h;
    } else {
        save_tx_track_release(slot_i);
        if (token == 1 && g_save_tx.state == 2 && g_save_tx.cycles_done == 0 && g_save_tx.active_opens == 0) {
            char slot[1024], hex[2048];
            if (save_meta_slot(host, slot, sizeof slot) && save_tx_hex(slot, hex, sizeof hex))
                save_tx_emit("create-fail", " target=%s err=%d", hex, err);
            LOG("[save-tx] the open of %s failed after the intent began (%s)\n", host, strerror(err));
            g_save_tx.state = g_save_tx.arm_count ? 1 : 0;
            g_save_tx.last_ts = host_time_100ns();
        }
    }
    pthread_mutex_unlock(&g_save_tx_lock);
}
/* W(WriteFile): count the cycle's writes and bytes; a failed, short or empty
   write of a non-empty request is an I/O error of the cycle (the engine
   itself would not notice a short write). */
static void save_tx_write_hook(uint32_t h, uint32_t requested, ssize_t written) {
    if (!save_tx_on()) return;
    pthread_mutex_lock(&g_save_tx_lock);
    if (g_save_tx.state == 2 && save_tx_track_find(h) >= 0) {
        g_save_tx.writes++;
        if (written < 0 || (uint32_t)written != requested) g_save_tx.errors++;
        if (written > 0) g_save_tx.bytes += (uint64_t)written;
    }
    pthread_mutex_unlock(&g_save_tx_lock);
}
/* A failed SetEndOfFile/FlushFileBuffers/ReadFile on a tracked handle. */
static void save_tx_io_error(uint32_t h) {
    if (!save_tx_on()) return;
    pthread_mutex_lock(&g_save_tx_lock);
    if (g_save_tx.state == 2 && save_tx_track_find(h) >= 0) g_save_tx.errors++;
    pthread_mutex_unlock(&g_save_tx_lock);
}
/* Drop priors of committed intents beyond the history bound. Lock held. */
static void save_tx_trim_history(void) {
    while (g_save_tx.history_count > SAVE_TX_HISTORY_MAX) {
        char p[1200];
        snprintf(p, sizeof p, "%s/%s", g_save_tx_dir, g_save_tx.history[0]);
        if (unlink(p) && errno != ENOENT) LOG("[save-tx] history %s cleanup failed: %s\n", g_save_tx.history[0], strerror(errno));
        memmove(g_save_tx.history[0], g_save_tx.history[1], (size_t)(g_save_tx.history_count - 1) * sizeof g_save_tx.history[0]);
        g_save_tx.history_count--;
    }
}
/* W(CloseHandle), before the host close: fsync the tracked descriptor (the
   "consistent close" of the completion sign), then fold the handle into the
   cycle. The last close of the target ends the cycle; the second clean cycle
   re-reads the slot and journals the fixture. A further write open after the
   commit is simply the next intent (its own arm protects the committed bytes). */
static void save_tx_close_hook(uint32_t h) {
    if (!save_tx_on()) return;
    pthread_mutex_lock(&g_save_tx_lock);
    int i = save_tx_track_find(h);
    if (i < 0) { pthread_mutex_unlock(&g_save_tx_lock); return; }
    if (g_save_tx.state != 2) { save_tx_track_release(i); pthread_mutex_unlock(&g_save_tx_lock); return; }
    WinHandle *x = handle_get(h, H_FILE);
    if (x && x->fd >= 0) {
        int r;
        do { r = fsync(x->fd); } while (r < 0 && errno == EINTR);
        if (r < 0) { g_save_tx.errors++; LOG("[save-tx] fsync of the target failed: %s\n", strerror(errno)); }
    } else g_save_tx.errors++;
    save_tx_track_release(i);
    if (g_save_tx.active_opens > 0) { pthread_mutex_unlock(&g_save_tx_lock); return; }
    /* the cycle ended */
    g_save_tx.cycles_done++;
    char slot[1024], thex[2048];
    if (!save_meta_slot(g_save_tx.target, slot, sizeof slot) || !save_tx_hex(slot, thex, sizeof thex)) {
        g_save_tx.state = 4;   /* cannot name the target; nothing more to prove */
        pthread_mutex_unlock(&g_save_tx_lock);
        return;
    }
    int errors = g_save_tx.errors;
    uint64_t bytes = g_save_tx.bytes;
    if (!save_tx_emit("cycle", " target=%s n=%d writes=%d errors=%d bytes=%llu", thex, g_save_tx.cycles_done,
                      g_save_tx.writes, errors, (unsigned long long)bytes)) {
        LOG("[save-tx] cycle line not durable; the intent fails conservatively\n");
        g_save_tx.state = 4;
    } else if (errors || !bytes) {
        save_tx_emit("fail", " reason=%s", errors ? "io-errors" : "empty-cycle");
        LOG("[save-tx] cycle %d of %s failed (errors=%d bytes=%llu); recovery will roll back\n",
            g_save_tx.cycles_done, slot, errors, (unsigned long long)bytes);
        g_save_tx.state = 4;
    } else if (g_save_tx.cycles_done == 2) {
        uint64_t size = 0;
        char sha[65];
        if (save_tx_read_sha(g_save_tx.target, &size, sha) ||
            !save_tx_emit("commit", " target=%s size=%llu sha=%s", thex, (unsigned long long)size, sha)) {
            LOG("[save-tx] commit of %s not durable; recovery treats it as unfinished\n", slot);
            g_save_tx.state = 4;   /* the bytes may be fine, but they are not provable */
        } else {
            for (int a = 0; a < g_save_tx.arm_count && g_save_tx.history_count < SAVE_TX_HISTORY_MAX + SAVE_TX_ARM_MAX; a++)
                snprintf(g_save_tx.history[g_save_tx.history_count++], sizeof g_save_tx.history[0], "%s", g_save_tx.arms[a].prior);
            save_tx_trim_history();
            g_save_tx.state = 3;
            LOG("[save-tx] committed %s (%llu bytes, sha %s)\n", slot, (unsigned long long)size, sha);
        }
    }   /* cycle 1: wait for the second stage; a clean cycle 2 always ends in commit or fail */
    g_save_tx.writes = 0;
    g_save_tx.errors = 0;
    g_save_tx.bytes = 0;
    pthread_mutex_unlock(&g_save_tx_lock);
}
#endif  /* SAVE_META_ON */

/* ------------------------------------------------------------------ delete-pending (strict share) */

/* Lock held (g_share_lock). The unlink of a delete-pending file, executed when the last handle of the file
   is gone. SAVE_TX (opt-in) preserves the slot first, exactly like the immediate delete path, so the
   journaled intent still precedes the destructive step. Where inodes are real, a file that is no longer
   the one that was marked (replaced from outside the registry) is left alone. A failed unlink leaves the
   file in place, the safe direction; CloseHandle cannot report it. */
static void share_unlink_pending(const SharePending *p) {
#if SHARE_INODE_IDENTITY
    if (p->n.has_id) {
        struct stat st;
        if (stat(p->host, &st) != 0) { LOG("[file] delete-pending %s: already gone\n", p->host); return; }
        if (!S_ISREG(st.st_mode) || (uint64_t)st.st_dev != p->n.dev || (uint64_t)st.st_ino != p->n.ino) {
            LOG("[file] delete-pending %s: the name now refers to another file, left untouched\n", p->host);
            return;
        }
    }
#endif
#if SAVE_META_ON
    int armed = save_tx_arm_slot(p->host);
#endif
    int r = unlink(p->host);
    int e = errno;
#if SAVE_META_ON
    if (r != 0 && armed && e != ENOENT) save_tx_delete_failed(p->host);
    if (r == 0) {
        char slot[1024];
        if (save_meta_slot(p->host, slot, sizeof slot)) save_meta_delete(slot);
    }
#endif
    if (r) LOG("[file] delete-pending unlink of %s failed: %s\n", p->host, strerror(e));
    else LOG("[file] delete-pending %s completed at the last close\n", p->host);
}
static void share_run_pending(void) {
    for (int i = 0; i < SHARE_PENDING_MAX; i++) {
        SharePending *p = &g_share_pending[i];
        if (!p->used) continue;
        int holders = 0;
        for (int j = 0; j < SHARE_RES_MAX && !holders; j++)
            if (g_share_res[j].used && share_relation(&g_share_res[j].n, &p->n) == 1) holders = 1;
        if (holders) continue;
        share_unlink_pending(p);
        p->used = 0;
    }
}

/* ------------------------------------------------------------------ CopyFileA (strict share) */

/* The source is opened like CreateFile(GENERIC_READ, FILE_SHARE_READ) and the destination like
   CreateFile(GENERIC_WRITE, share 0): both reservations are made atomically (and the destination is
   checked against the source's, so copying a file onto itself is a sharing violation, as on Windows)
   BEFORE the host destination is created or truncated. A destination that is absent is created (the
   default CopyFileA refuses it, see F32_AUDIT.md); a destination this call created is removed again
   when the copy fails halfway, an existing one keeps what was written (it was truncated). SAVE_TX and
   SAVE_META do not observe this path (inherited gap). Returns 0 or the Win32 error. */
static uint32_t copy_file_strict(const char *src, const char *dst, int fail_if_exists) {
    char hsrc[1024], hdst[1024];
    ShareName ns, nd;
    OvHit osrc, odst;
    pthread_mutex_lock(&g_share_lock);
    int src_exists = map_path_ov(src, hsrc, sizeof hsrc, &osrc);
    int dst_exists = map_path_ov(dst, hdst, sizeof hdst, &odst);
    uint32_t err = 0;
    ShareRes *rs = NULL, *rd = NULL;
    if ((err = share_name_for(src, hsrc, &ns)) != 0 || (err = share_name_for(dst, hdst, &nd)) != 0) { /* err is the refusal */ }
    else if (!src_exists) err = ERROR_FILE_NOT_FOUND;
    else if (fail_if_exists && dst_exists) err = ERROR_FILE_EXISTS;
    else if (ov_refuses_write(&odst, "CopyFileA", dst)) err = ERROR_ACCESS_DENIED;   /* E1: the destination is an overlay path */
    else if (!(err = share_check_open(&ns, SH_READ, SH_READ, NULL))) {
        rs = share_reserve();
        if (!rs) err = ERROR_SHARING_VIOLATION;
        else {
            rs->desired = SH_READ; rs->share = SH_READ; rs->n = ns; rs->established = 1;
            if (!(err = share_check_open(&nd, SH_WRITE, 0, NULL))) {
                rd = share_reserve();
                if (!rd) err = ERROR_SHARING_VIOLATION;
                else { rd->desired = SH_WRITE; rd->share = 0; rd->n = nd; rd->established = 1; }
            }
            if (err) share_drop(rs);
        }
    }
    pthread_mutex_unlock(&g_share_lock);
    if (err) return err;
    int in = open(osrc.kind ? osrc.host : hsrc, O_RDONLY, 0644);   /* E1: an overlay file is read from the overlay, named by the base path */
    int out = -1, e = 0;
    if (in < 0) err = file_io_error(errno, ERROR_FILE_NOT_FOUND);
    else {
        out = open(hdst, O_WRONLY | O_CREAT | (fail_if_exists ? O_EXCL : O_TRUNC), 0644);
        if (out < 0) err = errno == EEXIST ? ERROR_FILE_EXISTS : file_io_error(errno, dst_exists ? ERROR_ACCESS_DENIED : ERROR_PATH_NOT_FOUND);
    }
    if (!err) {
        char buf[65536];
        for (;;) {
            ssize_t r = read(in, buf, sizeof buf);
            if (r < 0 && errno == EINTR) continue;
            if (r < 0) { e = errno; err = file_io_error(e, 30 /* ERROR_READ_FAULT */); break; }
            if (r == 0) break;
            for (ssize_t put = 0; put < r;) {
                ssize_t w = write(out, buf + put, (size_t)(r - put));
                if (w < 0 && errno == EINTR) continue;
                if (w <= 0) { e = w < 0 ? errno : ENOSPC; err = file_io_error(e, ERROR_WRITE_FAULT); break; }
                put += w;
            }
            if (err) break;
        }
    }
    if (out >= 0 && close(out) != 0 && !err) err = ERROR_WRITE_FAULT;
    if (in >= 0) close(in);
    if (err && out >= 0 && !dst_exists) unlink(hdst);   /* never leave a half-copied file this call created */
    LOG("[kernel32] CopyFileA(%s -> %s) strict = %u\n", hsrc, hdst, err);
    pthread_mutex_lock(&g_share_lock);
    share_drop(rd);
    share_drop(rs);
    pthread_mutex_unlock(&g_share_lock);
    return err;
}

/* ------------------------------------------------------------------ load pacing */

/* While the engine loads (save-menu header reads, the save restore, the script recompile and the
   location load - about 1300 ordinary engine frames), the browser game thread must not race the
   display: Present would wait for requestAnimationFrame every frame and stretch the whole load to
   60 fps of wall time. A read-open of a SAVE file starts a load episode; any successful file open
   or read re-arms the deadline, so the load's silent compute stretch (about 10 s with no file
   traffic) keeps it alive. It ends on its own 12 s after the last file activity. Node builds never
   race the display (web stubs), PORT_PACE60 and the deterministic netplay clock are untouched. */
#define LOAD_PACE_GAP_US 12000000ull   /* 12 s of file silence ends an episode */

static uint64_t g_load_pace_until_us;
static void fs_activity(int save_read_open) {
    uint64_t now = (uint64_t)(host_seconds() * 1e6);
    if (save_read_open) {
        __atomic_store_n(&g_load_pace_until_us, now + LOAD_PACE_GAP_US, __ATOMIC_RELAXED);
    } else if (now < __atomic_load_n(&g_load_pace_until_us, __ATOMIC_RELAXED)) {
        __atomic_store_n(&g_load_pace_until_us, now + LOAD_PACE_GAP_US, __ATOMIC_RELAXED);
    }
}
uint32_t port_load_pacing_active(void) {
    return (uint64_t)(host_seconds() * 1e6) < __atomic_load_n(&g_load_pace_until_us, __ATOMIC_RELAXED);
}

W(CreateFileA) {
    uint32_t access = ARG(1), disp = ARG(4);
    /* Reject invalid or read-only truncation requests before touching paths.
       Some hosts accept O_RDONLY | O_TRUNC and destroy the existing contents. */
    if (disp < 1 || disp > 5) { set_error(87 /* ERROR_INVALID_PARAMETER */); RET(7, 0xFFFFFFFFu); }
    if (disp == 5 && !(access & 0x40000000u)) { set_error(ERROR_ACCESS_DENIED); RET(7, 0xFFFFFFFFu); }
#if defined(__EMSCRIPTEN__) && !defined(PORT_NODE_BUILD)
    /* WasmFS/OPFS implements O_EXCL as a lookup followed by a separate create.
       Another tab can create and populate the name in between. Until the backend
       provides atomic no-replace creation, fail before resolving any path.
       The separate Node/NODERAWFS object uses its host's O_EXCL instead. */
    if (disp == 1) {
        LOG("[kernel32] CREATE_NEW unsupported: atomic no-replace unavailable\n");
        set_error(50 /* ERROR_NOT_SUPPORTED */); RET(7, 0xFFFFFFFFu);
    }
#endif
    const char *name = GSTR(ARG(0));
    char host[1024];
#ifdef PORT_LAZY_EXPERIMENT
    /* Wait for an immutable indexed file only on an existing read open, and
     * before acquiring the share registry lock. Never fetch saves/settings. */
    {
        const LazyNode *node = lazy_guest_node(name);
        if (node && !lazy_index_is_dir(node) &&
            ((access & 0x40010000u) || disp == 1 || disp == 2 || disp == 5)) {
            set_error(ERROR_ACCESS_DENIED); RET(7, 0xFFFFFFFFu);
        }
        if (node && !lazy_index_is_dir(node) && (disp == 3 || disp == 4)) {
            if (!lazy_ensure_available(name, node)) {
                set_error(30 /* ERROR_READ_FAULT */); RET(7, 0xFFFFFFFFu);
            }
        }
    }
#endif
    int strict = strict_share();
    /* Resolve and reserve together with strict MoveFileA. Otherwise an
       absent name could be resolved with stale casing while a move creates
       its Windows-equivalent spelling before this open is reserved. */
    OvHit ov;   /* E1: what the read-only language overlay holds at this path (kind 0 with the overlay off) */
    if (strict) pthread_mutex_lock(&g_share_lock);
    int exists = map_path_ov(name, host, sizeof host, &ov);
    /* CREATE_NEW on a resolved existing name reports FILE_EXISTS even when
       an existing open conflicts or the strict registry is full. O_EXCL below
       is still required for the race where the name appears after lookup. */
    if (disp == 1 && exists) {
        if (strict) pthread_mutex_unlock(&g_share_lock);
        set_error(80 /* ERROR_FILE_EXISTS */); RET(7, 0xFFFFFFFFu);
    }
    /* E1: a path the overlay holds is read-only. Writing, truncating or re-creating it would leave a second version
       beside the one every read sees, so it is refused (the way Windows refuses a read-only file). The check comes
       before the strict registry is touched: nothing is reserved for a refused open. */
    if (ov.kind && ((access & 0x40000000u) || disp == 2 || disp == 5)) {
        if (strict) pthread_mutex_unlock(&g_share_lock);
        LOG("[overlay] CreateFileA(%s) refused: write access to a path of the read-only overlay (disp %u)\n", name, disp);
        set_error(ERROR_ACCESS_DENIED); RET(7, 0xFFFFFFFFu);
    }
    uint32_t desired = access_categories(access), share = share_categories(ARG(2));
    /* Reserve under the same lock as the conflict/capacity check, before any
       host I/O: open(O_TRUNC) mutates the file and another thread can open it
       while this call is in progress. The handle slot is secured the same way
       (H_RESERVED, no value is visible to the guest yet): a full handle table
       must refuse the open BEFORE a truncating open ran, not abort or leave a
       truncated file without a handle afterwards. */
    ShareRes *reservation = NULL;
    uint32_t hpre = 0;
    if (strict) {
        uint32_t conflicting = 0, err = 0;
        ShareName nm;
        err = share_name_for(name, host, &nm);
        if (!err) err = share_check_open(&nm, desired, share, &conflicting);
        if (!err) {
            reservation = share_reserve();
            if (!reservation) err = ERROR_SHARING_VIOLATION;   /* registry full: refuse, never weaken */
            else if (!(hpre = handle_try_new(H_RESERVED))) {
                reservation->used = 0;
                reservation = NULL;
                err = ERROR_TOO_MANY_OPEN_FILES;
            } else {
                reservation->h = hpre;
                reservation->desired = desired;
                reservation->share = share;
                reservation->n = nm;
            }
        }
        pthread_mutex_unlock(&g_share_lock);
        if (err) {
            if (err == ERROR_SHARING_VIOLATION && conflicting) LOG("[file] CreateFileA(%s) denied: sharing violation against handle %x\n", name, conflicting);
            else LOG("[file] CreateFileA(%s) denied: error %u (registry or handle table full, delete pending, path too long, or a name form strict refuses)\n", name, err);
            set_error(err);
            RET(7, 0xFFFFFFFFu);
        }
    }
    int fl = 0;
    if ((access & 0xC0000000u) == 0xC0000000u) fl = O_RDWR;
    else if (access & 0x40000000u) fl = O_WRONLY;
    else fl = O_RDONLY;
    switch (disp) {
    case 1: fl |= O_CREAT | O_EXCL; break;   /* CREATE_NEW */
    case 2: fl |= O_CREAT | O_TRUNC; break;  /* CREATE_ALWAYS: success, truncates an existing file to 0 */
    case 3: break;                           /* OPEN_EXISTING */
    case 4: fl |= O_CREAT; break;            /* OPEN_ALWAYS */
    case 5: fl |= O_TRUNC; break;            /* TRUNCATE_EXISTING */
    }
    const char *open_path = host;
    if (ov.kind) {   /* E1: read the overlay's file; the handle keeps the canonical base path (identity), only the fd differs */
        fl &= ~(O_CREAT | O_EXCL | O_TRUNC);   /* OPEN_EXISTING or OPEN_ALWAYS without write access: nothing is created */
        open_path = ov.host;
    }
    if (fl & O_CREAT) {  /* make sure the parent folder exists for files the game writes */
        char dir[1024];
        snprintf(dir, sizeof dir, "%s", host);
        for (char *p = dir + 1; *p; p++) if (*p == '/') { *p = 0; mkdir(dir, 0755); *p = '/'; }
    }
#if SAVE_META_ON
    /* SAVE_TX (opt-in): journal the intent, and preserve an existing slot,
       BEFORE the open can truncate it. No-op unless the flag is on. */
    int save_tx_token = save_tx_precreate(host, (fl & (O_WRONLY | O_RDWR | O_TRUNC)) != 0, exists);
#endif
    int fd = open(open_path, fl, 0644);
    int open_error = fd < 0 ? errno : 0;
    if (ov.kind) LOG("[file] CreateFileA(%s -> %s, disp %u) = %s (overlay %s)\n", name, host, disp, fd >= 0 ? "ok" : strerror(open_error), ov.host);
    else LOG("[file] CreateFileA(%s -> %s, disp %u) = %s\n", name, host, disp, fd >= 0 ? "ok" : strerror(open_error));
    if (fd < 0) {
#if SAVE_META_ON
        save_tx_postcreate(host, save_tx_token, 0, open_error);
#endif
        if (reservation) {
            pthread_mutex_lock(&g_share_lock);
            handle_cancel(hpre);
            share_drop(reservation);
            pthread_mutex_unlock(&g_share_lock);
        }
        uint32_t error = open_error == EEXIST && disp == 1 ? 80 /* ERROR_FILE_EXISTS */ :
            file_io_error(open_error, exists ? ERROR_ACCESS_DENIED : ERROR_FILE_NOT_FOUND);
        set_error(error); RET(7, 0xFFFFFFFFu);
    }
    /* The slot is still H_RESERVED while it is filled in and published last, so nothing (a stray
       CloseHandle, file_path_write_open on another thread) can observe a half-built handle. The default mode used
       to publish H_FILE first and fill the slot afterwards: another thread's file_path_write_open then read
       write_open/path of a handle in the middle of its construction (TSan, docs/handle-table-race.md). The
       handle value is the same: the lowest free slot. */
    uint32_t h = strict ? hpre : handle_new(H_RESERVED);
    WinHandle *x = handle_reserved(h);
    x->fd = fd;
    snprintf(x->path, sizeof x->path, "%s", host);
    x->write_open = (fl & (O_WRONLY | O_RDWR | O_TRUNC)) != 0;
    x->save_read_activity = disp == 3 && (access & 0x80000000u) &&
        (save_file_under(host, g_game_root) || save_file_under(host, g_user_root));
    fs_activity(x->save_read_activity);
    if (!x->write_open && disp == 3 && snapshot_enabled() && !file_path_write_open(host))
        file_snapshot(x, fd, name);   /* read-only open: serve reads from a one-shot buffer */
    if (reservation) {   /* publish the handle and mark the open established under the registry lock */
        pthread_mutex_lock(&g_share_lock);
        handle_publish(h, H_FILE);
        reservation->established = 1;
        pthread_mutex_unlock(&g_share_lock);
    } else handle_publish(h, H_FILE);
#if SAVE_META_ON
    save_tx_postcreate(host, save_tx_token, h, 0);
    save_meta_create_hook(host, disp, exists);
#endif
    set_error((disp == 4 || disp == 2) && exists ? ERROR_ALREADY_EXISTS : 0);
    RET(7, h);
}

W(CreateFileW) {
    char name[512];
    uint32_t p = ARG(0);
    int i = 0;
    for (; i < 511 && R16(p + 2 * i); i++) name[i] = (char)R16(p + 2 * i);
    name[i] = 0;
    uint32_t tmp = guest_strdup(name);
    W32(c->esp + 4, tmp);
    w_CreateFileA(c);
    heap_free(tmp);
}

W(ReadFile) {
    if (ARG(3) && (uint64_t)ARG(3) + 4 > GUEST_SPACE) { set_error(998 /* ERROR_NOACCESS */); RET(5, 0); }
    if (ARG(3)) W32(ARG(3), 0);
    WinHandle *x = handle_get(ARG(0), H_FILE);
    if (!x) { set_error(ERROR_INVALID_HANDLE); RET(5, 0); }
    if (ARG(2) && (!ARG(1) || (uint64_t)ARG(1) + ARG(2) > GUEST_SPACE)) { set_error(998 /* ERROR_NOACCESS */); RET(5, 0); }
    if (x->buf) {   /* snapshot: EOF is a successful short read, like the fd loop below */
        uint64_t avail = x->buf_pos < x->buf_size ? x->buf_size - x->buf_pos : 0;
        uint32_t got = ARG(2) < avail ? ARG(2) : (uint32_t)avail;
        if (got) memcpy(HP(ARG(1)), x->buf + x->buf_pos, got);
        x->buf_pos += got;
        if (ARG(3)) W32(ARG(3), got);
        if (got && x->save_read_activity) __atomic_fetch_add(&save_read_count, 1, __ATOMIC_RELAXED);
        RET(5, 1);
    }
    /* Windows only returns short reads at end of file; host reads can stop early, so loop */
    uint32_t want = ARG(2), got = 0;
    ssize_t n = 0;
    while (got < want) {
        n = read(x->fd, HP(ARG(1) + got), want - got);
        if (n < 0 && errno == EINTR) continue;
        if (n <= 0) break;
        got += (uint32_t)n;
    }
    if (ARG(3)) W32(ARG(3), got);
    if (got) fs_activity(0);
    if (got && x->save_read_activity) __atomic_fetch_add(&save_read_count, 1, __ATOMIC_RELAXED);
    if (n < 0) {
        set_error(file_io_error(errno, 30 /* ERROR_READ_FAULT */));
#if SAVE_META_ON
        save_tx_io_error(ARG(0));
#endif
    }
    RET(5, n >= 0);
}
W(WriteFile) {
    if (ARG(3) && (uint64_t)ARG(3) + 4 > GUEST_SPACE) { set_error(998 /* ERROR_NOACCESS */); RET(5, 0); }
    if (ARG(3)) W32(ARG(3), 0);
    uint32_t h = ARG(0);
    if (h == STD_OUT || h == STD_ERR) {
        if (ARG(2) && (!ARG(1) || (uint64_t)ARG(1) + ARG(2) > GUEST_SPACE)) { set_error(998 /* ERROR_NOACCESS */); RET(5, 0); }
        fwrite(HP(ARG(1)), 1, ARG(2), stderr);
        if (ARG(3)) W32(ARG(3), ARG(2));
        RET(5, 1);
    }
    WinHandle *x = handle_get(h, H_FILE);
    if (!x) { set_error(ERROR_INVALID_HANDLE); RET(5, 0); }
    if (ARG(2) && (!ARG(1) || (uint64_t)ARG(1) + ARG(2) > GUEST_SPACE)) { set_error(998 /* ERROR_NOACCESS */); RET(5, 0); }
    ssize_t n;
    do { n = write(x->fd, HP(ARG(1)), ARG(2)); } while (n < 0 && errno == EINTR);
    if (ARG(3)) W32(ARG(3), n > 0 ? (uint32_t)n : 0);
    if (n < 0) set_error(file_io_error(errno, ERROR_WRITE_FAULT));
#if SAVE_META_ON
    save_tx_write_hook(h, ARG(2), n);   /* short/zero/failed writes make the cycle unprovable */
#endif
    RET(5, n >= 0);
}
W(SetFilePointer) {
    WinHandle *x = handle_get(ARG(0), H_FILE);
    if (!x) { set_error(ERROR_INVALID_HANDLE); RET(4, 0xFFFFFFFFu); }
    if (ARG(3) > 2) { set_error(87 /* ERROR_INVALID_PARAMETER */); RET(4, 0xFFFFFFFFu); }
    int64_t off = (int32_t)ARG(1);
    if (ARG(2)) off = (int64_t)(((uint64_t)R32(ARG(2)) << 32) | ARG(1));
    if (x->buf) {   /* snapshot: same positions as lseek, negative results rejected like EINVAL */
        int64_t base = ARG(3) == 0 ? 0 : ARG(3) == 1 ? (int64_t)x->buf_pos : (int64_t)x->buf_size;
        int64_t np = base + off;
        if (np < 0) { set_error(off < 0 ? 131 /* ERROR_NEGATIVE_SEEK */ : 87); RET(4, 0xFFFFFFFFu); }
        x->buf_pos = (uint64_t)np;   /* beyond EOF is allowed; later reads return 0 bytes */
        if (ARG(2)) W32(ARG(2), (uint32_t)((uint64_t)np >> 32));
        if ((uint32_t)np == 0xFFFFFFFFu) set_error(0);
        RET(4, (uint32_t)np);
    }
    off_t r = lseek(x->fd, off, ARG(3) == 0 ? SEEK_SET : ARG(3) == 1 ? SEEK_CUR : SEEK_END);
    if (r < 0) {
        int e = errno;
        uint32_t error = e == EBADF ? ERROR_INVALID_HANDLE :
                         (e == EACCES || e == EPERM) ? ERROR_ACCESS_DENIED :
                         e == EINVAL && off < 0 ? 131 /* ERROR_NEGATIVE_SEEK */ :
                         e == EINVAL ? 87 /* ERROR_INVALID_PARAMETER */ :
                         e == ESPIPE ? 1 /* ERROR_INVALID_FUNCTION */ : 30 /* ERROR_READ_FAULT */;
        set_error(error); RET(4, 0xFFFFFFFFu);
    }
    if (ARG(2)) W32(ARG(2), (uint32_t)((uint64_t)r >> 32));
    if ((uint32_t)r == 0xFFFFFFFFu) set_error(0);
    RET(4, (uint32_t)r);
}
W(GetFileSize) {
    WinHandle *x = handle_get(ARG(0), H_FILE);
    if (!x) { set_error(ERROR_INVALID_HANDLE); RET(2, 0xFFFFFFFFu); }
    if (x->buf) {   /* snapshot: the size is what the open read captured */
        if (ARG(1)) W32(ARG(1), (uint32_t)(x->buf_size >> 32));
        if ((uint32_t)x->buf_size == 0xFFFFFFFFu) set_error(0);
        RET(2, (uint32_t)x->buf_size);
    }
    struct stat st;
    if (fstat(x->fd, &st) < 0) {
        int e = errno;
        uint32_t error = e == EBADF ? ERROR_INVALID_HANDLE :
                         (e == EACCES || e == EPERM) ? ERROR_ACCESS_DENIED :
                         e == EINVAL ? 87 /* ERROR_INVALID_PARAMETER */ : 30 /* ERROR_READ_FAULT */;
        set_error(error); RET(2, 0xFFFFFFFFu);
    }
    if (ARG(1)) W32(ARG(1), (uint32_t)((uint64_t)st.st_size >> 32));
    if ((uint32_t)st.st_size == 0xFFFFFFFFu) set_error(0);
    RET(2, (uint32_t)st.st_size);
}
W(FlushFileBuffers) {
    WinHandle *x = handle_get(ARG(0), H_FILE);
    if (!x || x->fd < 0) { set_error(ERROR_INVALID_HANDLE); RET(1, 0); }
    int r;
    do { r = fsync(x->fd); } while (r < 0 && errno == EINTR);
    if (r < 0) {
        uint32_t error = errno == EBADF ? ERROR_INVALID_HANDLE :
                         (errno == EACCES || errno == EPERM) ? ERROR_ACCESS_DENIED :
                         errno == ENOSPC ? ERROR_DISK_FULL : ERROR_WRITE_FAULT;
#if SAVE_META_ON
        save_tx_io_error(ARG(0));
#endif
        set_error(error); RET(1, 0);
    }
    RET(1, 1);
}
W(SetEndOfFile) {
    WinHandle *x = handle_get(ARG(0), H_FILE);
    if (!x) RET(1, 0);
    int eof_ok = ftruncate(x->fd, lseek(x->fd, 0, SEEK_CUR)) == 0;
#if SAVE_META_ON
    if (!eof_ok) save_tx_io_error(ARG(0));
#endif
    RET(1, eof_ok);
}
W(DeleteFileA) {
#ifdef PORT_LAZY_EXPERIMENT
    if (ARG(0) && (uint64_t)ARG(0) < GUEST_SPACE && lazy_guest_node(GSTR(ARG(0)))) {
        set_error(ERROR_ACCESS_DENIED); RET(1, 0);
    }
#endif
    int strict = strict_share();
    if (strict && (!ARG(0) || (uint64_t)ARG(0) >= GUEST_SPACE)) {
        set_error(87 /* ERROR_INVALID_PARAMETER */); RET(1, 0);
    }
    char host[1024];
    OvHit ov;
    if (strict) pthread_mutex_lock(&g_share_lock);
    map_path_ov(GSTR(ARG(0)), host, sizeof host, &ov);
    /* the guest return address identifies the engine caller (e.g. the CRT remove
       inside the save-load path); without it a save delete is invisible in logs */
    LOG("[file] DeleteFileA(%s -> %s) from %08x\n", GSTR(ARG(0)), host, R32(c->esp));
    if (ov_refuses_write(&ov, "DeleteFileA", GSTR(ARG(0)))) {   /* E1: the overlay is read-only */
        if (strict) pthread_mutex_unlock(&g_share_lock);
        set_error(ERROR_ACCESS_DENIED); RET(1, 0);
    }
    if (!strict) {
#if SAVE_META_ON
        int armed = save_tx_arm_slot(host);   /* SAVE_TX (opt-in): preserve the slot BEFORE the unlink */
#endif
        int unlink_result = unlink(host);
#if SAVE_META_ON
        int unlink_errno = errno;
        if (unlink_result != 0 && armed && unlink_errno != ENOENT) save_tx_delete_failed(host);
        errno = unlink_errno;
#endif
        int ok = unlink_result == 0;
#if SAVE_META_ON
        char slot[1024];
        if (ok && save_meta_slot(host, slot, sizeof slot)) save_meta_delete(slot);
#endif
        RET(1, ok);
    }
    /* A POSIX unlink immediately releases the name. Windows keeps a file that has open handles as
       delete-pending instead: the name stays, new opens fail with ERROR_ACCESS_DENIED, the file goes
       when the last handle closes. Strict mode follows that when every handle of the file is fully
       open and shares DELETE; while an open of the file is still in flight, or a handle does not
       share DELETE, the delete is refused (ERROR_SHARING_VIOLATION when some handle denies DELETE,
       ERROR_NOT_SUPPORTED when only an in-flight open or a spelling alias blocks it). The lock covers
       the check, the registration and an immediate unlink, excluding new in-process reservations
       until the namespace mutation is complete. */
    ShareName nm;
    uint32_t name_err = share_name_for(GSTR(ARG(0)), host, &nm);
    if (name_err) {
        pthread_mutex_unlock(&g_share_lock);
        set_error(name_err); RET(1, 0);
    }
    if (share_is_pending(&nm)) {   /* a second delete of a delete-pending file */
        pthread_mutex_unlock(&g_share_lock);
        set_error(ERROR_ACCESS_DENIED); RET(1, 0);
    }
    int has_open = 0, denies_delete = 0, unsettled = 0;
    for (int i = 0; i < SHARE_RES_MAX; i++) {
        ShareRes *r = &g_share_res[i];
        if (!r->used) continue;
        int rel = share_relation(&r->n, &nm);
        if (!rel) continue;
        has_open = 1;
        if (!(r->share & SH_DELETE)) denies_delete = 1;
        if (rel != 1 || !r->established) unsettled = 1;
    }
    if (has_open && !denies_delete && !unsettled) {
        struct stat st;
        int regular = stat(host, &st) == 0 && S_ISREG(st.st_mode);
        int slot = -1;
        for (int i = 0; i < SHARE_PENDING_MAX && regular; i++)
            if (!g_share_pending[i].used) { slot = i; break; }
        if (!regular || slot < 0) {   /* nothing to mark, or no room to remember the intent: fail closed */
            pthread_mutex_unlock(&g_share_lock);
            set_error(regular ? ERROR_NOT_SUPPORTED : ERROR_FILE_NOT_FOUND); RET(1, 0);
        }
        g_share_pending[slot].used = 1;
        g_share_pending[slot].n = nm;
        snprintf(g_share_pending[slot].host, sizeof g_share_pending[slot].host, "%s", host);
        pthread_mutex_unlock(&g_share_lock);
        LOG("[file] DeleteFileA(%s): delete pending until the last handle closes\n", host);
        set_error(0); RET(1, 1);
    }
#if SAVE_META_ON
    int armed = has_open ? 0 : save_tx_arm_slot(host);   /* SAVE_TX (opt-in), before the unlink, under the same lock */
#endif
    int result = has_open ? -1 : unlink(host);
    int e = result < 0 && !has_open ? errno : 0;
#if SAVE_META_ON
    if (result < 0 && armed && e != ENOENT) save_tx_delete_failed(host);
#endif
    pthread_mutex_unlock(&g_share_lock);
    if (has_open) set_error(denies_delete ? ERROR_SHARING_VIOLATION : ERROR_NOT_SUPPORTED);
    else if (result < 0) set_error(e == ENOENT ? ERROR_FILE_NOT_FOUND : file_io_error(e, ERROR_ACCESS_DENIED));
    else set_error(0);
#if SAVE_META_ON
    if (result == 0) {
        char slot[1024];
        if (save_meta_slot(host, slot, sizeof slot)) save_meta_delete(slot);
    }
#endif
    RET(1, result == 0);
}
#if !defined(__EMSCRIPTEN__) || defined(PORT_NODE_BUILD)
/* Caller holds g_share_lock in strict mode, including the whole host move.
   A live handle's identity cannot yet be transferred to the new name; refuse
   all reservations on either name rather than silently dropping protection. */
static uint32_t move_file_host(const char *gsrc, const char *gdst, const char *hsrc, const char *hdst, int strict) {
    if (strict) {
        int has_open = 0, denies_delete = 0;
        ShareName ns, nd;
        uint32_t name_err;
        if ((name_err = share_name_for(gsrc, hsrc, &ns)) != 0 || (name_err = share_name_for(gdst, hdst, &nd)) != 0) return name_err;
        if (share_is_pending(&ns) || share_is_pending(&nd)) return ERROR_ACCESS_DENIED;   /* delete-pending */
        for (int i = 0; i < SHARE_RES_MAX; i++) {
            ShareRes *r = &g_share_res[i];
            if (!r->used) continue;
            /* An absent name can have been reserved before its host spelling exists, so two
               Windows-equivalent spellings may differ in case; aliases of either name count too. */
            if (share_relation(&r->n, &ns) || share_relation(&r->n, &nd)) {
                has_open = 1;
                if (!(r->share & SH_DELETE)) denies_delete = 1;
            }
        }
        if (has_open) return denies_delete ? ERROR_SHARING_VIOLATION : ERROR_NOT_SUPPORTED;
    }
    struct stat st;
    if (stat(hsrc, &st)) return ERROR_FILE_NOT_FOUND;
    if (S_ISDIR(st.st_mode)) {
        /* Directory descendants and atomic no-replace are not covered by the
           strict path registry. Retain the old permissive behaviour only. */
        if (strict) return ERROR_NOT_SUPPORTED;
        struct stat dstst;
        if (!stat(hdst, &dstst)) return ERROR_ALREADY_EXISTS;
        if (rename(hsrc, hdst)) return file_io_error(errno, ERROR_ACCESS_DENIED);
    } else {
        if (link(hsrc, hdst)) {
            int e = errno;
            if (e == EEXIST) return ERROR_ALREADY_EXISTS;
            if (e == EXDEV) return ERROR_NOT_SAME_DEVICE;
            if (e == ENOSYS || e == EOPNOTSUPP || e == EPERM) return ERROR_NOT_SUPPORTED;
            return file_io_error(e, ERROR_ACCESS_DENIED);
        }
        if (unlink(hsrc)) {
            int e = errno;
            unlink(hdst);
            return file_io_error(e, ERROR_ACCESS_DENIED);
        }
    }
    return 0;
}
#endif
W(MoveFileA) {
#ifdef PORT_LAZY_EXPERIMENT
    if (ARG(0) && ARG(1) && (uint64_t)ARG(0) < GUEST_SPACE && (uint64_t)ARG(1) < GUEST_SPACE &&
        (lazy_guest_node(GSTR(ARG(0))) || lazy_guest_node(GSTR(ARG(1))))) {
        set_error(ERROR_ACCESS_DENIED); RET(2, 0);
    }
#endif
#if defined(__EMSCRIPTEN__) && !defined(PORT_NODE_BUILD)
    /* OPFS move/rename can replace a destination created by another tab
       after an existence check. Until there is an atomic no-replace backend
       with share/namespace ownership, no MoveFileA operation is safe to claim. */
    LOG("[kernel32] MoveFileA unsupported: atomic no-replace unavailable\n");
    set_error(ERROR_NOT_SUPPORTED); RET(2, 0);
#else
    /* MoveFileA must never replace an existing destination (only MoveFileEx with
       MOVEFILE_REPLACE_EXISTING does). link() is an atomic no-replace create: it fails with
       EEXIST when the destination already exists, so a check-then-rename race cannot overwrite
       it; unlink() then drops the source and completes the move. */
    if (!ARG(0) || !ARG(1) || (uint64_t)ARG(0) >= GUEST_SPACE || (uint64_t)ARG(1) >= GUEST_SPACE) {
        set_error(87 /* ERROR_INVALID_PARAMETER */); RET(2, 0);
    }
    const char *src = GSTR(ARG(0)), *dst = GSTR(ARG(1));
    char hsrc[1024], hdst[1024];
    OvHit osrc, odst;
    int strict = strict_share();
    /* Resolve under the lock as well: two moves to Windows-equivalent but
       differently cased absent names must not both use stale spellings. */
    if (strict) pthread_mutex_lock(&g_share_lock);
    int src_there = map_path_ov(src, hsrc, sizeof hsrc, &osrc);
    if (ov_refuses_write(&osrc, "MoveFileA", src)) {   /* E1: nothing leaves the read-only overlay */
        if (strict) pthread_mutex_unlock(&g_share_lock);
        set_error(ERROR_ACCESS_DENIED); RET(2, 0);
    }
    if (!src_there) {
        uint32_t name_err = 0;
        if (strict) {   /* a name form strict refuses is reported as such, not as a missing file */
            ShareName probe;
            map_path(dst, hdst, sizeof hdst);
            if (!(name_err = share_name_for(src, hsrc, &probe))) name_err = share_name_for(dst, hdst, &probe);
            pthread_mutex_unlock(&g_share_lock);
        }
        set_error(name_err ? name_err : ERROR_FILE_NOT_FOUND); RET(2, 0);
    }
    map_path_ov(dst, hdst, sizeof hdst, &odst);   /* the destination may legitimately not exist */
    if (odst.kind) {   /* E1: a name the overlay holds exists (MoveFile never replaces); a base file under it would be shadowed */
        if (strict) pthread_mutex_unlock(&g_share_lock);
        LOG("[overlay] MoveFileA(%s -> %s) refused: the destination is served from the read-only overlay\n", src, dst);
        set_error(ERROR_ALREADY_EXISTS); RET(2, 0);
    }
    if (!strcmp(hsrc, hdst)) {
        if (strict) pthread_mutex_unlock(&g_share_lock);
        set_error(0); RET(2, 1);   /* same file: nothing to do */
    }
    uint32_t error = move_file_host(src, dst, hsrc, hdst, strict);
    if (strict) pthread_mutex_unlock(&g_share_lock);
    if (error) { set_error(error); RET(2, 0); }
    LOG("[file] MoveFileA(%s -> %s)\n", src, dst);
#if SAVE_META_ON
    {   /* The browser build rejects moves before this point, so this only
           runs natively (tests). A failed record move never undoes the file
           move: the orphaned record names a slot that no longer exists. */
        char ssl[1024], dsl[1024], sp[1100], dp[1200], dir[1024];
        if (save_meta_slot(hsrc, ssl, sizeof ssl) && save_meta_slot(hdst, dsl, sizeof dsl)) {
            snprintf(dir, sizeof dir, "%s/SAVE_META", g_game_root);
            if (save_meta_locate(ssl, sp, sizeof sp)) {
                save_meta_path(dsl, dp, sizeof dp);
                mkdir(dir, 0755);
                if (rename(sp, dp)) LOG("[file] SAVE_META(%s): move failed: %s\n", ssl, strerror(errno));
            }
            if (save_lang_locate(ssl, sp, sizeof sp)) {   /* the language label moves with its slot */
                snprintf(dp, sizeof dp, "%s/%s.lang", dir, dsl);
                mkdir(dir, 0755);
                if (rename(sp, dp)) LOG("[file] SAVE_META(%s): lang move failed: %s\n", ssl, strerror(errno));
            }
        }
    }
#endif
    set_error(0);
    RET(2, 1);
#endif
}
/* Strict share only: directory operations take the registry lock around name resolution AND the host
   call, like the open/delete/move paths, so two spellings of an absent directory cannot both be
   created and a directory is not removed under an open or opening file. Error codes follow Win32
   (the default path keeps its original result-only behavior). */
static uint32_t dir_errno_error(int e, const char *host) {
    if (e == EEXIST) return ERROR_ALREADY_EXISTS;
    if (e == ENOTEMPTY) return ERROR_DIR_NOT_EMPTY;
    if (e == ENOTDIR) return ERROR_DIRECTORY;
    if (e == ENOENT) {
        char parent[1024];
        snprintf(parent, sizeof parent, "%s", host);
        char *sl = strrchr(parent, '/');
        struct stat st;
        if (sl && sl > parent) { *sl = 0; if (stat(parent, &st) == 0) return ERROR_FILE_NOT_FOUND; }
        return ERROR_PATH_NOT_FOUND;
    }
    return file_io_error(e, ERROR_ACCESS_DENIED);
}
W(CreateDirectoryA) {
#ifdef PORT_LAZY_EXPERIMENT
    if (ARG(0) && (uint64_t)ARG(0) < GUEST_SPACE && lazy_guest_node(GSTR(ARG(0)))) {
        set_error(ERROR_ALREADY_EXISTS); RET(2, 0);
    }
#endif
    char host[1024];
    OvHit ov;
    if (ARG(0) && (uint64_t)ARG(0) < GUEST_SPACE) LOG("[file] CreateDirectoryA(%s)\n", GSTR(ARG(0)));
    if (strict_share()) {
        if (!ARG(0) || (uint64_t)ARG(0) >= GUEST_SPACE) { set_error(87 /* ERROR_INVALID_PARAMETER */); RET(2, 0); }
        pthread_mutex_lock(&g_share_lock);
        map_path_ov(GSTR(ARG(0)), host, sizeof host, &ov);
        ShareName nm;
        uint32_t err = share_name_for(GSTR(ARG(0)), host, &nm);
        if (!err && ov_refuses_write(&ov, "CreateDirectoryA", GSTR(ARG(0)))) err = ERROR_ALREADY_EXISTS;   /* E1: it exists, in the overlay */
        if (!err && share_is_pending(&nm)) err = ERROR_ACCESS_DENIED;
        for (int i = 0; !err && i < SHARE_RES_MAX; i++)
            if (g_share_res[i].used && share_relation(&g_share_res[i].n, &nm) == 2) err = ERROR_SHARING_VIOLATION;
        int r = err ? -1 : mkdir(host, 0755);
        int e = errno;
        pthread_mutex_unlock(&g_share_lock);
        set_error(err ? err : r == 0 ? 0 : dir_errno_error(e, host));
        RET(2, r == 0);
    }
    map_path_ov(GSTR(ARG(0)), host, sizeof host, &ov);
    if (ov_refuses_write(&ov, "CreateDirectoryA", GSTR(ARG(0)))) { set_error(ERROR_ALREADY_EXISTS); RET(2, 0); }   /* E1 */
    int r = mkdir(host, 0755);
    if (r && errno == EEXIST) set_error(ERROR_ALREADY_EXISTS);
    RET(2, r == 0);
}
W(RemoveDirectoryA) {
#ifdef PORT_LAZY_EXPERIMENT
    if (ARG(0) && (uint64_t)ARG(0) < GUEST_SPACE && lazy_guest_node(GSTR(ARG(0)))) {
        set_error(ERROR_ACCESS_DENIED); RET(1, 0);
    }
#endif
    char host[1024];
    OvHit ov;
    if (ARG(0) && (uint64_t)ARG(0) < GUEST_SPACE) LOG("[file] RemoveDirectoryA(%s)\n", GSTR(ARG(0)));
    if (strict_share()) {
        if (!ARG(0) || (uint64_t)ARG(0) >= GUEST_SPACE) { set_error(87 /* ERROR_INVALID_PARAMETER */); RET(1, 0); }
        pthread_mutex_lock(&g_share_lock);
        map_path_ov(GSTR(ARG(0)), host, sizeof host, &ov);
        ShareName nm;
        uint32_t err = share_name_for(GSTR(ARG(0)), host, &nm);
        if (!err && ov_refuses_write(&ov, "RemoveDirectoryA", GSTR(ARG(0)))) err = ERROR_ACCESS_DENIED;   /* E1 */
        /* An open file below the directory (or an open still creating its parents) keeps it alive. */
        for (int i = 0; !err && i < SHARE_RES_MAX; i++) {
            ShareRes *r = &g_share_res[i];
            if (!r->used) continue;
            if (share_is_under(&nm, &r->n)) err = ERROR_DIR_NOT_EMPTY;
            else if (share_relation(&r->n, &nm) == 2) err = ERROR_SHARING_VIOLATION;
        }
        for (int i = 0; !err && i < SHARE_PENDING_MAX; i++)
            if (g_share_pending[i].used && share_is_under(&nm, &g_share_pending[i].n)) err = ERROR_DIR_NOT_EMPTY;
        int r = err ? -1 : rmdir(host);
        int e = errno;
        pthread_mutex_unlock(&g_share_lock);
        set_error(err ? err : r == 0 ? 0 : dir_errno_error(e, host));
        RET(1, r == 0);
    }
    map_path_ov(GSTR(ARG(0)), host, sizeof host, &ov);
    if (ov_refuses_write(&ov, "RemoveDirectoryA", GSTR(ARG(0)))) { set_error(ERROR_ACCESS_DENIED); RET(1, 0); }   /* E1 */
    RET(1, rmdir(host) == 0);
}

/* E1: with the language overlay on, a listing is the UNION of the base directory and the overlay's: the base's entries in
   the host's order first (a name the overlay also has takes the overlay's data, under the base's spelling), then the names
   only the overlay has, in its listing order; a directory that exists only in the overlay gets a synthetic "." and "..".
   `seen` holds the keys (overlay_name_key) of the base names already returned, which is how phase 1 skips the duplicates. */
typedef struct {
    char dir[1024]; char pattern[256]; DIR *d; int cp;   /* cp: PORT_NAME_CP1251 at FindFirstFileA */
    const void *ovdir;   /* the overlay's node of this directory, NULL when the overlay holds none (always NULL with the overlay off) */
    char ovhost[1024];   /* ... and its physical path */
    int phase;           /* 0 base entries, 1 overlay-only entries, 2 done */
    uint32_t ovi;        /* next index in the overlay's listing */
    int ovdots;          /* "." and ".." already supplied (directory only in the overlay) */
    char **seen; uint32_t nseen, capseen;
#ifdef PORT_LAZY_EXPERIMENT
    const LazyNode *lazydir;
    size_t lazyi;
    int lazydots;
#endif
} FindState;

static int find_seen_has(const FindState *fs, const char *key) {
    for (uint32_t i = 0; i < fs->nseen; i++) if (!strcmp(fs->seen[i], key)) return 1;
    return 0;
}
static void find_seen_add(FindState *fs, const char *key) {
    if (fs->nseen == fs->capseen) {
        uint32_t nc = fs->capseen ? fs->capseen * 2 : 64;
        char **n = realloc(fs->seen, nc * sizeof *n);
        if (!n) return;
        fs->seen = n; fs->capseen = nc;
    }
    char *k = strdup(key);
    if (k) fs->seen[fs->nseen++] = k;
}
static void find_free(FindState *fs) {
    if (fs->d) closedir(fs->d);
    for (uint32_t i = 0; i < fs->nseen; i++) free(fs->seen[i]);
    free(fs->seen);
    free(fs);
}

/* Does host entry `name` match the search pattern, and under which name does the game see it (*shown)?
   PORT_NAME_CP1251: a name with bytes >= 0x80 is UTF-8 on the host. The pattern (the guest's CP1251) is
   matched against it by character and with the Unicode case folding, and the game receives the name in
   CP1251. A host name the game's code page cannot spell (ill-formed UTF-8, e.g. one an earlier run stored
   mangled, or a character Windows-1251 lacks) is matched and returned byte for byte, as with the layer
   off; map_path finds it again from those bytes. ASCII names take the unchanged fnmatch path. */
static int find_name_ok(const FindState *fs, const char *name, char *gname, size_t gn, const char **shown) {
    *shown = name;
    if (fs->cp && name_has_high(name) && name_host_to_guest(name, gname, gn)) {
        if (!name_wild_match(fs->pattern, name)) return 0;
        *shown = gname;
    } else if (fnmatch(fs->pattern, name, FNM_CASEFOLD)) return 0;
    else if (fs->cp && name_has_high(name)) name_log("host name not representable in CP1251, returned to the guest as it is", name);
    return 1;
}

/* WIN32_FIND_DATAA for the host entry `full` (its stat result) shown to the game as `shown` */
static void find_fill(uint32_t out, const char *full, const struct stat *stp, const char *shown) {
    const struct stat st = *stp;
    (void)full;
    memset(HP(out), 0, 320);  /* WIN32_FIND_DATAA */
    W32(out, S_ISDIR(st.st_mode) ? 0x10 : 0x80);
#if !SAVE_META_ON
    /* Native and Node/NODERAWFS stat carries real persisted timestamps, and
       XINTERFACE formats ftCreationTime from it for the save list. */
#if defined(__APPLE__)
    W64(out + 4, filetime_from_timespec(st.st_birthtimespec.tv_sec, st.st_birthtimespec.tv_nsec));
    W64(out + 12, filetime_from_timespec(st.st_atimespec.tv_sec, st.st_atimespec.tv_nsec));
    W64(out + 20, filetime_from_timespec(st.st_mtimespec.tv_sec, st.st_mtimespec.tv_nsec));
#else
    W64(out + 4, filetime_from_timespec(st.st_mtim.tv_sec, st.st_mtim.tv_nsec));
    W64(out + 12, filetime_from_timespec(st.st_atim.tv_sec, st.st_atim.tv_nsec));
    W64(out + 20, filetime_from_timespec(st.st_mtim.tv_sec, st.st_mtim.tv_nsec));
#endif
#else
    /* Browser/WasmFS+OPFS stat times are artifacts of in-memory node
       construction and change across a reload, so they are never used.
       ftCreationTime comes only from the durable sidecar record (zero =
       unknown, the list honestly keeps 00:00). ftLastAccessTime and
       ftLastWriteTime stay zero: a rewritten slot keeps its original
       record, so even the creation stamp is not a truthful last-write. */
    {
        char slot[1024];
        if (save_meta_slot(full, slot, sizeof slot)) W64(out + 4, save_meta_read(slot));
    }
#endif
    W32(out + 28, (uint32_t)((uint64_t)st.st_size >> 32));
    W32(out + 32, (uint32_t)st.st_size);
    snprintf((char *)HP(out + 44), 260, "%s", shown);
}

static int find_next(FindState *fs, uint32_t out) {
    struct dirent *e;
    while (fs->phase == 0 && fs->d && (e = readdir(fs->d))) {
        char gname[512];
        const char *shown;
        if (!find_name_ok(fs, e->d_name, gname, sizeof gname, &shown)) continue;
        char full[1300];
        snprintf(full, sizeof full, "%s/%s", fs->dir, e->d_name);
#ifdef PORT_LAZY_EXPERIMENT
        int overlay_shadow = 0;
#endif
        if (fs->ovdir
#ifdef PORT_LAZY_EXPERIMENT
            || fs->lazydir
#endif
        ) {   /* Record the real spelling before adding other namespaces. */
            const char *ohost;
            int odir;
            char key[1100];
            overlay_name_key(e->d_name, fs->cp, key, sizeof key);
#ifdef PORT_LAZY_EXPERIMENT
            if (!fs->lazydir) find_seen_add(fs, key);
#else
            find_seen_add(fs, key);
#endif
            if (fs->ovdir && overlay_dir_find(fs->ovdir, e->d_name, fs->cp, &ohost, &odir)) {
                snprintf(full, sizeof full, "%s", ohost);
#ifdef PORT_LAZY_EXPERIMENT
                overlay_shadow = 1;
#endif
            }
        }
        struct stat st;
        if (stat(full, &st)) continue;
#ifdef PORT_LAZY_EXPERIMENT
        if (fs->lazydir) {
            char key[1100]; overlay_name_key(e->d_name, fs->cp, key, sizeof key); find_seen_add(fs, key);
            const LazyNode *node = lazy_index_host_child(fs->lazydir, e->d_name, fs->cp);
            /* While a partial file is visible, the logical namespace reports
             * manifest size, never the placeholder's temporary zero length. */
            if (!overlay_shadow && node && node == __atomic_load_n(&g_lazy_incomplete, __ATOMIC_ACQUIRE)) {
                st.st_mode = lazy_index_is_dir(node) ? S_IFDIR | 0555 : S_IFREG | 0444;
                st.st_size = (off_t)lazy_index_size(node);
            }
        }
#endif
        find_fill(out, full, &st, shown);
        return 1;
    }
    if (fs->phase == 0) fs->phase = fs->ovdir ? 1 : 2;
    while (fs->phase == 1) {
        char gname[512], key[1100];
        const char *shown;
        struct stat st;
        if (!fs->d && fs->ovdots < 2) {   /* the directory is only in the overlay: "." and ".." are ours to supply */
            const char *dot = fs->ovdots++ ? ".." : ".";
            if (!find_name_ok(fs, dot, gname, sizeof gname, &shown) || stat(fs->ovhost, &st)) continue;
            find_fill(out, fs->ovhost, &st, shown);
            return 1;
        }
        const char *oname, *ohost;
        int odir;
        if (!overlay_dir_entry(fs->ovdir, fs->ovi++, &oname, &ohost, &odir)) { fs->phase = 2; break; }
        overlay_name_key(oname, fs->cp, key, sizeof key);
        if (find_seen_has(fs, key)) continue;
        if (!find_name_ok(fs, oname, gname, sizeof gname, &shown) || stat(ohost, &st)) continue;
#ifdef PORT_LAZY_EXPERIMENT
        if (fs->lazydir) find_seen_add(fs, key);
#endif
        find_fill(out, ohost, &st, shown);
        return 1;
    }
#ifdef PORT_LAZY_EXPERIMENT
    while (fs->phase == 2 && fs->lazydir) {
        char gname[512], key[1100], full[1300];
        const char *shown, *name;
        struct stat st; memset(&st, 0, sizeof st);
        if (!fs->d && !fs->ovdir && fs->lazydots < 2) {
            name = fs->lazydots++ ? ".." : ".";
            st.st_mode = S_IFDIR | 0555;
        } else {
            const LazyNode *entry = lazy_index_entry(fs->lazydir, fs->lazyi++);
            if (!entry) { fs->phase = 3; break; }
            name = lazy_index_name(entry);
            overlay_name_key(name, fs->cp, key, sizeof key);
            if (find_seen_has(fs, key)) continue;
            st.st_mode = lazy_index_is_dir(entry) ? S_IFDIR | 0555 : S_IFREG | 0444;
            st.st_size = (off_t)lazy_index_size(entry);
        }
        if (!find_name_ok(fs, name, gname, sizeof gname, &shown)) continue;
        snprintf(full, sizeof full, "%s/%s", fs->dir, name);
        find_fill(out, full, &st, shown);
        return 1;
    }
#endif
    return 0;
}

W(FindFirstFileA) {
    const char *spec = GSTR(ARG(0));
    char guest_dir[1024], host[1024];
    snprintf(guest_dir, sizeof guest_dir, "%s", spec);
    char *sl = strrchr(guest_dir, '\\');
    char *sl2 = strrchr(guest_dir, '/');
    if (sl2 > sl) sl = sl2;
    FindState *fs = calloc(1, sizeof *fs);
    fs->cp = name_cp1251_on();
    if (sl) { snprintf(fs->pattern, sizeof fs->pattern, "%s", sl + 1); *sl = 0; }
    else { snprintf(fs->pattern, sizeof fs->pattern, "%s", guest_dir); guest_dir[0] = 0; }
    if (!strcmp(fs->pattern, "*.*")) strcpy(fs->pattern, "*");
    OvHit ov;
    map_path_ov(guest_dir[0] ? guest_dir : ".", host, sizeof host, &ov);
    snprintf(fs->dir, sizeof fs->dir, "%s", host);
    fs->d = opendir(host);
    if (ov.kind == 2) { fs->ovdir = ov.node; snprintf(fs->ovhost, sizeof fs->ovhost, "%s", ov.host); }   /* E1: the overlay holds this directory too */
#ifdef PORT_LAZY_EXPERIMENT
    fs->lazydir = lazy_guest_node(guest_dir[0] ? guest_dir : ".");
    if (fs->lazydir && !lazy_index_is_dir(fs->lazydir)) fs->lazydir = NULL;
    /* A real or overlay file shadows an indexed directory of the same name.
     * Do not invent descendants under a path that is logically a file. */
    if (fs->lazydir && ov.kind == 1) fs->lazydir = NULL;
    if (fs->lazydir && !ov.kind) {
        struct stat actual;
        if (!stat(host, &actual) && !S_ISDIR(actual.st_mode)) fs->lazydir = NULL;
    }
#endif
    LOG("[file] FindFirstFileA(%s) in %s\n", spec, host);
    if (!find_next(fs, ARG(1))) {
        find_free(fs);
        set_error(ERROR_FILE_NOT_FOUND);
        RET(2, 0xFFFFFFFFu);
    }
    uint32_t h = handle_new_ptr(H_FIND, fs);
    RET(2, h);
}
W(FindNextFileA) {
    WinHandle *x = handle_get(ARG(0), H_FIND);
    if (!x || !find_next(x->ptr, ARG(1))) { set_error(ERROR_NO_MORE_FILES); RET(2, 0); }
    RET(2, 1);
}
W(FindClose) {
    WinHandle *x = handle_get(ARG(0), H_FIND);
    if (x && x->ptr) { FindState *fs = x->ptr; if (fs->d) closedir(fs->d); fs->d = NULL; for (uint32_t i = 0; i < fs->nseen; i++) free(fs->seen[i]); free(fs->seen); fs->seen = NULL; fs->nseen = fs->capseen = 0; }
    handle_close(ARG(0));
    RET(1, 1);
}

W(GetCurrentDirectoryA) {
    const char *d = guest_cwd();
    if (ARG(0) > strlen(d)) strcpy((char *)HP(ARG(1)), d);
    RET(2, strlen(d));
}
W(SetCurrentDirectoryA) {
    LOG("[file] SetCurrentDirectoryA(%s)\n", GSTR(ARG(0)));
    guest_set_cwd(GSTR(ARG(0)));
    RET(1, 1);
}
W(GetFullPathNameA) {
    const char *p = GSTR(ARG(0));
    char full[1024];
    if (p[1] == ':') snprintf(full, sizeof full, "%s", p);
    else snprintf(full, sizeof full, "%s\\%s", guest_cwd(), p);
    if (ARG(1) > strlen(full)) strcpy((char *)HP(ARG(2)), full);
    if (ARG(3)) {
        char *b = strrchr((char *)HP(ARG(2)), '\\');
        W32(ARG(3), b ? ARG(2) + (uint32_t)(b + 1 - (char *)HP(ARG(2))) : ARG(2));
    }
    RET(4, strlen(full));
}

/* Drives: C: is the game's hard disk. D: is a CD-ROM holding the game disc, so disc checks pass. */
W(GetLogicalDrives) { RET(0, (1u << 2) | (1u << 3)); }
W(GetLogicalDriveStringsA) {
    const char s[] = "C:\\\0D:\\\0";
    if (ARG(0) >= sizeof s) memcpy(HP(ARG(1)), s, sizeof s);
    RET(2, sizeof s - 1);
}
W(GetDriveTypeA) {
    const char *r = ARG(0) ? GSTR(ARG(0)) : "C:\\";
    RET(1, (r[0] == 'D' || r[0] == 'd') ? 5 /* DRIVE_CDROM */ : 3 /* DRIVE_FIXED */);
}
W(GetDiskFreeSpaceA) {
    if (ARG(1)) W32(ARG(1), 8);
    if (ARG(2)) W32(ARG(2), 512);
    if (ARG(3)) W32(ARG(3), 0x100000);
    if (ARG(4)) W32(ARG(4), 0x200000);
    RET(5, 1);
}
W(GetVolumeInformationA) {
    const char *r = ARG(0) ? GSTR(ARG(0)) : "C:\\";
    const char *label = (r[0] == 'D' || r[0] == 'd') ? PORT_VOLUME_LABEL : "SYSTEM";
    LOG("[file] GetVolumeInformationA(%s)\n", r);
    if (ARG(1)) snprintf((char *)HP(ARG(1)), ARG(2), "%s", label);
    if (ARG(3)) W32(ARG(3), 0x07C07C07);
    if (ARG(4)) W32(ARG(4), 255);
    if (ARG(5)) W32(ARG(5), 0);
    if (ARG(6)) snprintf((char *)HP(ARG(6)), ARG(7), "%s", (r[0] == 'D' || r[0] == 'd') ? "CDFS" : "NTFS");
    RET(8, 1);
}

W(CreateFileMappingA) {
    WinHandle *f = handle_get(ARG(0), H_FILE);
    int mfd = f ? dup(f->fd) : -1;
    uint32_t h = handle_new(H_RESERVED);   /* filled in, then published: no thread sees a mapping without its fd */
    handle_reserved(h)->fd = mfd;
    handle_publish(h, H_MAPPING);
    RET(6, h);
}
W(MapViewOfFile) {
    WinHandle *m = handle_get(ARG(0), H_MAPPING);
    if (!m || m->fd < 0) RET(5, 0);
    struct stat st;
    fstat(m->fd, &st);
    uint32_t off = ARG(3), len = ARG(4) ? ARG(4) : (uint32_t)st.st_size - off;
    uint32_t a = guest_valloc(len);
    /* copy-in (views are only read by the game); loop: a single read may come back short */
    uint32_t got = 0;
    while (got < len) {
        ssize_t r = pread(m->fd, HP(a + got), len - got, (off_t)off + got);
        if (r <= 0) break;
        got += (uint32_t)r;
    }
    LOG("[file] MapViewOfFile(%u bytes, read %u) -> %08x\n", len, got, a);
    RET(5, a);
}
W(UnmapViewOfFile) { RET(1, 1); }

/* ------------------------------------------------------------------ resources (none exposed yet) */

W(FindResourceA) { STUB("FindResourceA(%x)\n", ARG(1)); RET(3, 0); }
W(FindResourceW) { RET(3, 0); }
W(LoadResource) { RET(2, 0); }
W(LockResource) { RET(1, 0); }
W(SizeofResource) { RET(2, 0); }

/* ------------------------------------------------------------------ console (CRT only) */

W(GetConsoleMode) { RET(2, 0); }
W(SetConsoleMode) { RET(2, 1); }
W(SetConsoleCtrlHandler) { RET(2, 1); }
W(WriteConsoleA) { fwrite(HP(ARG(1)), 1, ARG(2), stderr); if (ARG(3)) W32(ARG(3), ARG(2)); RET(5, 1); }
W(ReadConsoleInputA) { RET(4, 0); }
W(PeekConsoleInputA) { if (ARG(3)) W32(ARG(3), 0); RET(4, 1); }
W(GetNumberOfConsoleInputEvents) { if (ARG(1)) W32(ARG(1), 0); RET(2, 1); }

#define K(name) IMPORT("KERNEL32.DLL", name)
static const ImportHandler list[] = {
    K(GetVersion), K(GetVersionExA), K(GetModuleHandleA), K(LoadLibraryA), K(FreeLibrary), K(GetProcAddress),
    K(GetEnvironmentVariableA), K(GetLocalTime), K(GlobalMemoryStatus), K(GetDiskFreeSpaceExA),
    K(CompareFileTime), K(GetFileAttributesA), K(SetFileAttributesA), K(CopyFileA), K(Beep),
    K(HeapValidate), K(SetErrorMode), K(DisableThreadLibraryCalls), K(GlobalLock), K(GlobalUnlock),
    K(lstrlenA), K(lstrcatA),
    K(GetModuleFileNameA), K(GetCommandLineA), K(GetEnvironmentStrings), K(GetEnvironmentStringsW),
    K(FreeEnvironmentStringsA), K(FreeEnvironmentStringsW), K(SetEnvironmentVariableA), K(GetStartupInfoA),
    K(GetStdHandle), K(SetStdHandle), K(GetFileType), K(SetHandleCount), K(GetCurrentProcess),
    K(GetCurrentThread), K(GetCurrentProcessId), K(GetCurrentThreadId), K(GetLastError), K(SetLastError),
    K(ExitProcess), K(TerminateProcess), K(FatalAppExitA), K(GetSystemInfo), K(IsProcessorFeaturePresent),
    K(IsDebuggerPresent), K(OutputDebugStringA), K(DebugBreak), K(IsBadReadPtr), K(IsBadWritePtr),
    K(IsBadCodePtr), K(SetUnhandledExceptionFilter), K(UnhandledExceptionFilter), K(RaiseException),
    K(RtlUnwind), K(FormatMessageA), K(GetACP), K(GetOEMCP), K(IsValidCodePage), K(GetCPInfo),
    K(MultiByteToWideChar), K(WideCharToMultiByte), K(GetStringTypeA), K(GetStringTypeW), K(LCMapStringA),
    K(LCMapStringW), K(CompareStringA), K(CompareStringW), K(GetUserDefaultLCID), K(IsValidLocale),
    K(EnumSystemLocalesA), K(GetLocaleInfoA), K(GetLocaleInfoW), K(GetTickCount), K(QueryPerformanceFrequency),
    K(QueryPerformanceCounter), K(GetSystemTimeAsFileTime), K(FileTimeToLocalFileTime), K(FileTimeToSystemTime),
    K(GetTimeZoneInformation), K(GetDateFormatA), K(GetTimeFormatA), K(HeapCreate), K(HeapDestroy),
    K(GetProcessHeap), K(HeapAlloc), K(HeapFree), K(HeapReAlloc), K(HeapSize), K(GlobalAlloc), K(GlobalFree),
    K(LocalFree), K(VirtualAlloc), K(VirtualFree), K(VirtualProtect), K(VirtualQuery), K(TlsAlloc), K(TlsFree),
    K(TlsGetValue), K(TlsSetValue), K(InitializeCriticalSection), K(DeleteCriticalSection),
    K(EnterCriticalSection), K(LeaveCriticalSection), K(InterlockedIncrement), K(InterlockedDecrement),
    K(InterlockedExchange), K(CreateEventA), K(SetEvent), K(ResetEvent), K(CreateMutexA), K(ReleaseMutex),
    K(CreateSemaphoreA), K(ReleaseSemaphore), K(WaitForSingleObject), K(Sleep), K(SleepEx), K(CreateThread),
    K(ResumeThread), K(ExitThread), K(TerminateThread), K(GetExitCodeThread), K(SetThreadPriority),
    K(GetThreadPriority), K(SetThreadAffinityMask), K(DuplicateHandle), K(CloseHandle), K(CreateFileA),
    K(CreateFileW), K(ReadFile), K(WriteFile), K(SetFilePointer), K(GetFileSize), K(FlushFileBuffers),
    K(SetEndOfFile), K(DeleteFileA), K(MoveFileA), K(CreateDirectoryA), K(RemoveDirectoryA), K(FindFirstFileA),
    K(FindNextFileA), K(FindClose), K(GetCurrentDirectoryA), K(SetCurrentDirectoryA), K(GetFullPathNameA),
    K(GetLogicalDrives), K(GetLogicalDriveStringsA), K(GetDriveTypeA), K(GetDiskFreeSpaceA),
    K(GetVolumeInformationA), K(CreateFileMappingA), K(MapViewOfFile), K(UnmapViewOfFile), K(FindResourceA),
    K(FindResourceW), K(LoadResource), K(LockResource), K(SizeofResource), K(GetConsoleMode), K(SetConsoleMode),
    K(SetConsoleCtrlHandler), K(WriteConsoleA), K(ReadConsoleInputA), K(PeekConsoleInputA),
    K(GetNumberOfConsoleInputEvents),
};
const ImportTable kernel32_imports = { list, sizeof list / sizeof list[0] };
