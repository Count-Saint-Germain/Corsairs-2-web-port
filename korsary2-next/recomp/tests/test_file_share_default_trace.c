/* Ф3.2: scripted file/handle scenario in the PERMISSIVE default mode (PORT_STRICT_FILE_SHARE unset, "0" or
   empty). It prints a trace (operation, result, last error, handle values, file contents, directory
   listing). run_file_share_semantics.sh diff BASE_DIR builds this same file against an older copy of
   recomp/host and against the current one; the two traces must be byte-identical, which is the evidence
   that the strict-mode work left the default mode unchanged. Uses only the public handlers, so it also
   compiles against the old tree. Synthetic temp dirs only. Usage: test scratch-dir [unset|0|empty [unset|0|empty [snap]]]  (second: PORT_NAME_CP1251; snap: PORT_FILE_SNAPSHOT on) */
#include <assert.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include "../host/core.c"
#include "../host/kernel32.c"
uint8_t *g_mem;
/* the deterministic scheduler (sched.c) and the code range are not linked into this test */
uint32_t g_code_lo = 0x401000, g_code_hi = 0x401000;
int sched_active(void) { return 0; }
uint64_t sched_now_us(void) { return 0; }
int sched_wait(int (*pred)(void *), void *arg, uint64_t deadline_us, uint64_t (*deadline_fn)(void)) { (void)pred; (void)arg; (void)deadline_us; (void)deadline_fn; return 0; }

static CPU cpu;
static GuestThread th;
static char root[1024];
static uint32_t call(void (*fn)(CPU *), int n, const uint32_t *a) {
    t_self = &th;
    th.last_error = 0xdeadu;
    cpu.esp = 0x1000;
    W32(0x1000, 0);
    for (int i = 0; i < n; i++) W32(0x1004 + 4u * (uint32_t)i, a[i]);
    fn(&cpu);
    return cpu.eax;
}
static uint32_t gs(int k, const char *s) { uint32_t at = 0x4000u + (uint32_t)k * 0x1000u; strcpy((char *)HP(at), s); return at; }
#define TR(...) do { printf(__VA_ARGS__); printf(" | err=%u\n", th.last_error); } while (0)
static uint32_t cf(const char *n, uint32_t acc, uint32_t sh, uint32_t disp) {
    uint32_t a[7] = { gs(0, n), acc, sh, 0, disp, 0, 0 };
    uint32_t r = call(w_CreateFileA, 7, a);
    TR("CreateFileA(%s,%x,%x,%u) = %x", n, acc, sh, disp, r);
    return r;
}
static uint32_t ch(uint32_t h) { uint32_t a[1] = { h }; uint32_t r = call(w_CloseHandle, 1, a); TR("CloseHandle(%x) = %u", h, r); return r; }
static void dl(const char *n) { uint32_t a[1] = { gs(0, n) }; uint32_t r = call(w_DeleteFileA, 1, a); TR("DeleteFileA(%s) = %u", n, r); }
static void mv(const char *s, const char *d) { uint32_t a[2] = { gs(0, s), gs(1, d) }; uint32_t r = call(w_MoveFileA, 2, a); TR("MoveFileA(%s,%s) = %u", s, d, r); }
static void mkd(const char *n) { uint32_t a[2] = { gs(0, n), 0 }; uint32_t r = call(w_CreateDirectoryA, 2, a); TR("CreateDirectoryA(%s) = %u", n, r); }
static void rmd(const char *n) { uint32_t a[1] = { gs(0, n) }; uint32_t r = call(w_RemoveDirectoryA, 1, a); TR("RemoveDirectoryA(%s) = %u", n, r); }
static void cpy(const char *s, const char *d, uint32_t f) { uint32_t a[3] = { gs(0, s), gs(1, d), f }; uint32_t r = call(w_CopyFileA, 3, a); TR("CopyFileA(%s,%s,%u) = %u", s, d, f, r); }
static void dup_h(uint32_t h) { uint32_t a[7] = { 0xFFFFFFFFu, h, 0xFFFFFFFFu, 0x3000, 0, 0, 2 }; uint32_t r = call(w_DuplicateHandle, 7, a); TR("DuplicateHandle(%x) = %u -> %x", h, r, R32(0x3000)); }
static void rd(uint32_t h, uint32_t n) {
    uint32_t a[5] = { h, 0x6000, n, 0x2000, 0 };
    uint32_t r = call(w_ReadFile, 5, a);
    uint32_t got = R32(0x2000);
    char b[64] = ""; memcpy(b, HP(0x6000), got < 63 ? got : 63);
    TR("ReadFile(%x,%u) = %u got=%u '%s'", h, n, r, got, b);
}
static void wr(uint32_t h, const char *data) {
    memcpy(HP(0x7000), data, strlen(data));
    uint32_t a[5] = { h, 0x7000, (uint32_t)strlen(data), 0x2000, 0 };
    uint32_t r = call(w_WriteFile, 5, a);
    TR("WriteFile(%x,%s) = %u wrote=%u", h, data, r, R32(0x2000));
}
static void mapping(uint32_t h) {
    uint32_t a[6] = { h, 0, 2, 0, 0, 0 };
    uint32_t m = call(w_CreateFileMappingA, 6, a);
    TR("CreateFileMappingA(%x) = %x", h, m);
    ch(m);
}
static void put(const char *name, const char *c) { char p[1300]; snprintf(p, sizeof p, "%s/%s", root, name); FILE *f = fopen(p, "wb"); assert(f); fputs(c, f); fclose(f); }
static int cmpstr(const void *a, const void *b) { return strcmp(*(char *const *)a, *(char *const *)b); }
static void listing(const char *tag) {
    char *names[128]; int n = 0;
    DIR *d = opendir(root);
    struct dirent *e;
    while (d && (e = readdir(d)) && n < 128) if (e->d_name[0] != '.') names[n++] = strdup(e->d_name);
    if (d) closedir(d);
    qsort(names, (size_t)n, sizeof *names, cmpstr);
    printf("LIST %s:", tag);
    for (int i = 0; i < n; i++) {
        char p[1300], b[64] = "";
        snprintf(p, sizeof p, "%s/%s", root, names[i]);
        struct stat st;
        if (stat(p, &st) == 0 && S_ISREG(st.st_mode)) { FILE *f = fopen(p, "rb"); size_t g = f ? fread(b, 1, 63, f) : 0; b[g] = 0; if (f) fclose(f); printf(" %s='%s'", names[i], b); }
        else printf(" %s/", names[i]);
        free(names[i]);
    }
    printf("\n");
}
static void hexs(const char *s, char *o) { for (; *s; s++, o += 2) sprintf(o, "%02x", (unsigned char)*s); *o = 0; }
/* FindFirstFileA / FindNextFileA over the whole listing, names in hex (bytes >= 0x80 are not printable) */
static void fnd(const char *spec) {
    uint32_t a[2] = { gs(0, spec), 0x8000 };
    uint32_t h = call(w_FindFirstFileA, 2, a);
    char names[16][300]; int n = 0;
    if (h != 0xFFFFFFFFu) {
        do {
            if (n < 16) hexs((const char *)HP(0x8000 + 44), names[n++]);
            uint32_t b[2] = { h, 0x8000 };
            if (!call(w_FindNextFileA, 2, b)) break;
        } while (1);
        uint32_t b[1] = { h }; call(w_FindClose, 1, b);
    }
    /* the order of readdir is the host's: sort for a stable trace */
    for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) if (strcmp(names[i], names[j]) > 0) { char t[300]; strcpy(t, names[i]); strcpy(names[i], names[j]); strcpy(names[j], t); }
    printf("FIND(%s) = %s n=%d:", spec, h == 0xFFFFFFFFu ? "none" : "ok", n);
    for (int i = 0; i < n; i++) printf(" %s", names[i]);
    printf(" | err=%u\n", th.last_error);
}

/* Handle table (PORT_SPECIFICATION.md): the values and results the table hands out must not change. */
static uint32_t h1a(void (*fn)(CPU *), const char *n, uint32_t a0) { uint32_t a[1] = { a0 }; uint32_t r = call(fn, 1, a); TR("%s(%x) = %x", n, a0, r); return r; }
static uint32_t h2a(void (*fn)(CPU *), const char *n, uint32_t a0, uint32_t a1) { uint32_t a[2] = { a0, a1 }; uint32_t r = call(fn, 2, a); TR("%s(%x,%x) = %x", n, a0, a1, r); return r; }
static void table_trace(void) {
    put("t1", "one-0123456789"); put("t2", "two-0123456789"); put("t3", "three-0123456789");
    uint32_t f1 = cf("t1", 0x80000000u, 1, 3), f2 = cf("t2", 0x80000000u, 1, 3), f3 = cf("t3", 0x80000000u, 1, 3);
    uint32_t ea[4] = { 0, 1, 0, 0 }; uint32_t ev = call(w_CreateEventA, 4, ea); TR("CreateEventA = %x", ev);
    uint32_t ma[3] = { 0, 1, 0 }; uint32_t mu = call(w_CreateMutexA, 3, ma); TR("CreateMutexA = %x", mu);
    uint32_t sa[4] = { 0, 1, 4, 0 }; uint32_t se = call(w_CreateSemaphoreA, 4, sa); TR("CreateSemaphoreA = %x", se);
    h1a(w_SetEvent, "SetEvent", ev); h2a(w_WaitForSingleObject, "WaitForSingleObject", ev, 0);
    h1a(w_ResetEvent, "ResetEvent", ev); h2a(w_WaitForSingleObject, "WaitForSingleObject", ev, 0);
    h1a(w_ReleaseMutex, "ReleaseMutex", mu);
    { uint32_t r[3] = { se, 1, 0 }; uint32_t x = call(w_ReleaseSemaphore, 3, r); TR("ReleaseSemaphore(%x) = %x", se, x); }
    h1a(w_GetFileType, "GetFileType", f1); h1a(w_GetFileType, "GetFileType", ev);
    rd(f1, 6); rd(f2, 6);
    { uint32_t a[4] = { f3, 4, 0, 0 }; uint32_t r = call(w_SetFilePointer, 4, a); TR("SetFilePointer(%x,4) = %x", f3, r); }
    rd(f3, 5); h2a(w_GetFileSize, "GetFileSize", f3, 0);
    /* close the middle one: the lowest free slot is reused (mix of types) */
    ch(f2); uint32_t n1 = cf("t2", 0x80000000u, 1, 3); ch(ev); uint32_t n2 = call(w_CreateEventA, 4, ea); TR("CreateEventA = %x", n2);
    ch(n1); ch(f1); ch(f3); ch(mu); ch(se); ch(n2);
    /* everything is closed: every use fails the same way, a second close of a file/event handle stays TRUE */
    rd(f1, 4); rd(n1, 4); h2a(w_GetFileSize, "GetFileSize", f3, 0); h1a(w_GetFileType, "GetFileType", f3);
    h1a(w_SetEvent, "SetEvent", ev); h1a(w_ResetEvent, "ResetEvent", n2); h1a(w_ReleaseMutex, "ReleaseMutex", mu);
    { uint32_t r[3] = { se, 1, 0 }; uint32_t x = call(w_ReleaseSemaphore, 3, r); TR("ReleaseSemaphore(%x) = %x", se, x); }
    h1a(w_CloseHandle, "CloseHandle", f1); h1a(w_CloseHandle, "CloseHandle", ev);
    /* directory search handles */
    { uint32_t a[2] = { gs(0, "t*"), 0x8000 }; uint32_t h = call(w_FindFirstFileA, 2, a); TR("FindFirstFileA(t*) = %x", h);
      uint32_t b[2] = { h, 0x8000 }; uint32_t g = call(w_FindNextFileA, 2, b); TR("FindNextFileA = %u", g);
      h1a(w_FindClose, "FindClose", h); g = call(w_FindNextFileA, 2, b); TR("FindNextFileA after FindClose = %u", g);
      h1a(w_FindClose, "FindClose", h); uint32_t h2 = call(w_FindFirstFileA, 2, a); TR("FindFirstFileA(t*) = %x", h2); h1a(w_FindClose, "FindClose", h2); }
    /* a read-only open while another handle holds the path for writing, then after it is closed */
    { uint32_t w = cf("t1", 0x40000000u, 0, 3); uint32_t r1 = cf("t1", 0x80000000u, 1, 3); rd(r1, 6); ch(w); uint32_t r2 = cf("t1", 0x80000000u, 1, 3); rd(r2, 6); ch(r1); ch(r2); }
    /* waits (PORT_SPECIFICATION.md): live objects, values that are closed, invalid or not sync objects, and a
       mapping handle closed before MapViewOfFile: none of these results may change with the wait/close rework */
    {
        uint32_t ea1[4] = { 0, 0, 1, 0 }; uint32_t e1 = call(w_CreateEventA, 4, ea1); TR("CreateEventA(auto,signaled) = %x", e1);
        h2a(w_WaitForSingleObject, "WaitForSingleObject", e1, 0); h2a(w_WaitForSingleObject, "WaitForSingleObject", e1, 0);
        h2a(w_WaitForSingleObject, "WaitForSingleObject", e1, 15);
        uint32_t sa2[4] = { 0, 2, 4, 0 }; uint32_t s2 = call(w_CreateSemaphoreA, 4, sa2); TR("CreateSemaphoreA(2) = %x", s2);
        for (int i = 0; i < 3; i++) h2a(w_WaitForSingleObject, "WaitForSingleObject", s2, 0);
        uint32_t ma2[3] = { 0, 0, 0 }; uint32_t m2 = call(w_CreateMutexA, 3, ma2); TR("CreateMutexA = %x", m2);
        h2a(w_WaitForSingleObject, "WaitForSingleObject", m2, 0); h2a(w_WaitForSingleObject, "WaitForSingleObject", m2, 0);   /* recursion */
        h1a(w_ReleaseMutex, "ReleaseMutex", m2); h1a(w_ReleaseMutex, "ReleaseMutex", m2); h1a(w_ReleaseMutex, "ReleaseMutex", m2);
        { uint32_t fa[2] = { gs(0, "t*"), 0x8000 }; uint32_t fh = call(w_FindFirstFileA, 2, fa); TR("FindFirstFileA(t*) = %x", fh);
          h2a(w_WaitForSingleObject, "WaitForSingleObject", fh, 0); h1a(w_FindClose, "FindClose", fh); h2a(w_WaitForSingleObject, "WaitForSingleObject", fh, 0); }
        { uint32_t fh = cf("t1", 0x80000000u, 1, 3); h2a(w_WaitForSingleObject, "WaitForSingleObject", fh, 0); uint32_t ma[6] = { fh, 0, 2, 0, 0, 0 };
          uint32_t mp = call(w_CreateFileMappingA, 6, ma); TR("CreateFileMappingA(%x) = %x", fh, mp); h2a(w_WaitForSingleObject, "WaitForSingleObject", mp, 0);
          ch(mp); h1a(w_MapViewOfFile, "MapViewOfFile(closed mapping)", mp); ch(fh); }
        ch(e1); ch(s2); ch(m2);
        h2a(w_WaitForSingleObject, "WaitForSingleObject", e1, 0); h2a(w_WaitForSingleObject, "WaitForSingleObject", e1, 10);
        h2a(w_WaitForSingleObject, "WaitForSingleObject", s2, 0); h2a(w_WaitForSingleObject, "WaitForSingleObject", m2, 0);
        h2a(w_WaitForSingleObject, "WaitForSingleObject", 0, 0); h2a(w_WaitForSingleObject, "WaitForSingleObject", 0xFFFFFFFFu, 10);
        h2a(w_WaitForSingleObject, "WaitForSingleObject", 0x1004, 10); h2a(w_WaitForSingleObject, "WaitForSingleObject", 0xDEADBEEFu, 0);
    }
    /* fill the table: the 4081st open fails the same way (permissive: abort is not scriptable, stay below) */
    { uint32_t hh[64]; for (int i = 0; i < 64; i++) hh[i] = cf("t3", 0x80000000u, 1, 3); printf("OPEN64 first=%x last=%x\n", hh[0], hh[63]); for (int i = 0; i < 64; i += 2) ch(hh[i]); uint32_t again = cf("t3", 0x80000000u, 1, 3); printf("REOPEN %x\n", again); for (int i = 1; i < 64; i += 2) ch(hh[i]); ch(again); }
}
int main(int argc, char **argv) {

    if (argc < 2) return 2;
    if (argc > 3) { if (!strcmp(argv[3], "unset")) unsetenv("PORT_NAME_CP1251"); else setenv("PORT_NAME_CP1251", !strcmp(argv[3], "empty") ? "" : argv[3], 1); }
    if (argc > 2) { if (!strcmp(argv[2], "unset")) unsetenv("PORT_STRICT_FILE_SHARE"); else setenv("PORT_STRICT_FILE_SHARE", !strcmp(argv[2], "empty") ? "" : argv[2], 1); }
    /* argv[4] "snap": snapshots on (the default of the browser build), else off as in the other modes */
    setenv("PORT_FILE_SNAPSHOT", argc > 4 && !strcmp(argv[4], "snap") ? "1" : "0", 1);
    /* argv[5] PORT_OVERLAY (E1; the old host ignores it): unset | 0 | empty = off; emptydir = on with an empty folder;
       decoys = on with a folder that holds files and folders named like the ones this scenario uses, but only at the top level
       and under SAVE/options/engine.ini, where the overlay is never looked at (the trace must not change in any of them) */
    {
        const char *ov = argc > 5 ? argv[5] : "unset";
        if (!strcmp(ov, "unset")) unsetenv("PORT_OVERLAY");
        else if (!strcmp(ov, "empty")) setenv("PORT_OVERLAY", "", 1);
        else if (!strcmp(ov, "emptydir") || !strcmp(ov, "decoys")) {
            static char od[1100];
            snprintf(od, sizeof od, "%s/korsary-f32trace-overlay-XXXXXX", argv[1]);
            assert(mkdtemp(od));
            if (!strcmp(ov, "decoys")) {
                static const char *names[] = { "data", "DATA", "fresh", "t1", "t2", "t3", "moved", "options", "engine.ini", "a/b/c", "dd/x", "SAVE/slot1", "SAVE_META/slot1.time", "SAVE_TX/j", NULL };
                for (int i = 0; names[i]; i++) {
                    char p[1300];
                    snprintf(p, sizeof p, "%s/%s", od, names[i]);
                    for (char *q = p + strlen(od) + 1; *q; q++) if (*q == '/') { *q = 0; mkdir(p, 0755); *q = '/'; }
                    FILE *f = fopen(p, "wb");
                    if (f) { fputs("OVERLAY-DECOY", f); fclose(f); }
                }
            }
            setenv("PORT_OVERLAY", od, 1);
        } else setenv("PORT_OVERLAY", ov, 1);
    }
    g_mem = calloc(1, 0x100000);
    snprintf(root, sizeof root, "%s/korsary-f32trace-XXXXXX", argv[1]);
    assert(mkdtemp(root));
    snprintf(g_game_root, sizeof g_game_root, "%s", root);
    put("data", "KEEP");
    uint32_t h1 = cf("data", 0x80000000u, 0, 3);
    uint32_t h2 = cf("DATA", 0x40000000u, 0, 3);          /* conflicting open succeeds */
    rd(h1, 8); wr(h2, "Z"); rd(h1, 8);
    ch(h1); uint32_t h3 = cf(".\\data", 0x80000000u, 7, 3); ch(h3); ch(h3); ch(h3);
    ch(0); ch(0x1003); ch(0xdeadbeefu); ch(0xFFFFFFFFu); ch(0xFFFFFFFEu); ch(0xF4);
    dup_h(h2); mapping(h2);
    dl("data"); listing("after delete with open handle"); ch(h2); dl("data");
    cf("data", 0x40000000u, 0, 2); listing("after CREATE_ALWAYS");
    uint32_t h4 = cf("a/b/c", 0x40000000u, 3, 2); wr(h4, "deep"); ch(h4); ch(h4);
    cf("nosuch", 0x80000000u, 0, 3); cf("data", 0x80000000u, 0, 9); cf("data", 0x80000000u, 0, 5);
    uint32_t h5 = cf("data", 0xC0000000u, 0, 4); wr(h5, "xy"); ch(h5);
    uint32_t h6 = cf("fresh", 0x40000000u, 0, 1); ch(h6); cf("fresh", 0x40000000u, 0, 1);
    mkd("dd"); mkd("DD"); mkd("zz/yy"); rmd("dd"); rmd("dd"); rmd("a"); rmd("a/b/c"); rmd("data");
    cpy("data", "dcopy", 0); cpy("data", "fresh", 0); cpy("data", "fresh", 1); cpy("nosuch", "x", 0);
    mv("data", "moved"); mv("moved", "fresh"); mv("moved", "MOVED"); mv("nosuch", "x");
    /* names with bytes >= 0x80 with the CP1251 layer off: the bytes go to the host untouched. UTF-8 spellings
       (valid on every host) and CP1251 spellings (ill-formed UTF-8: refused by APFS, kept by ext4/WasmFS) */
    {
        const char *u1 = "\xD0\x96\xD1\x83\xD0\xBA", *u2 = "\xD0\x81\xD0\xB6", *c1 = "\xD2\xE5\xF1\xF2", *c2 = "\xA8\xE6";
        uint32_t h7 = cf(u1, 0xC0000000u, 0, 2); wr(h7, "utf8"); ch(h7);
        h7 = cf(u1, 0x80000000u, 0, 3); rd(h7, 8); ch(h7);
        cf("\xD0\x96\xD0\xA3\xD0\x9A", 0x80000000u, 0, 3);            /* another case of the same letters: byte-wise lookup */
        h7 = cf(c1, 0xC0000000u, 0, 2); if (h7 != 0xFFFFFFFFu) { wr(h7, "cp1251"); ch(h7); }
        h7 = cf(c2, 0xC0000000u, 0, 2); if (h7 != 0xFFFFFFFFu) { wr(h7, "yo"); ch(h7); }
        h7 = cf(u2, 0xC0000000u, 0, 2); wr(h7, "u2"); ch(h7);
        fnd("*"); fnd("*.*"); fnd("\xD0*"); fnd("*\xBA"); fnd("\xD2\xE5*"); fnd("?\xE6"); fnd(c1);
        mv(u1, "mv-utf8"); mv("mv-utf8", u1); cpy(u1, "copy-utf8", 0); cpy(c1, "copy-cp", 0);
        mkd("\xD0\x96" "dir"); mkd(c1); fnd("*"); rmd("\xD0\x96" "dir"); rmd(c1);
        dl(u1); dl(c1); dl(c2); dl(u2); dl("copy-utf8"); dl("copy-cp");
        fnd("*");
    }
    table_trace();
    listing("end");
    printf("TRACE END\n");
    return 0;
}
