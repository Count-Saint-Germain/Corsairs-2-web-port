/* Ф3.2: file semantics of the opt-in strict share mode (PORT_STRICT_FILE_SHARE) on the REAL
   kernel32.c handlers, over synthetic temp directories only. Not a check of the running game.

   Run by run_file_share_semantics.sh in native (ASan/UBSan, TSan), WasmFS-under-Node and NODERAWFS
   builds, once per mode:
     env unset / "0" / ""        permissive default: pins the unchanged behavior
     env "1" (or any other)      strict: aliases, delete-pending, exhaustion, closing, directories,
                                 CopyFileA, concurrency
   Usage: test [scratch-dir [unset|0|empty|1]]  (default /tmp; the optional mode sets
   PORT_STRICT_FILE_SHARE itself, so the runner does not depend on environment passing into WasmFS);
   SHARE_NO_THREADS=1 skips the pthread parts. */
#include <assert.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <pthread.h>
#include <sched.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include "../host/core.c"
#include "../host/kernel32.c"
uint8_t *g_mem;

#define CHECK(c) do { if (!(c)) { fprintf(stderr, "FAIL %s:%d: %s\n", __FILE__, __LINE__, #c); abort(); } } while (0)
#define GENERIC_READ 0x80000000u
#define GENERIC_WRITE 0x40000000u
#define DELETE_ACC 0x00010000u
#define FS_R 1
#define FS_W 2
#define FS_D 4
#define INVALID 0xffffffffu
#define CREATE_NEW 1
#define CREATE_ALWAYS 2
#define OPEN_EXISTING 3
#define OPEN_ALWAYS 4
#define TRUNCATE_EXISTING 5
#if !defined(__EMSCRIPTEN__) || defined(PORT_NODE_BUILD)
#define MOVE_OK 1
#else
#define MOVE_OK 0   /* the browser configuration refuses every MoveFileA before any path work */
#endif

static int strict;
static char root[1024];
static int use_threads = 1;

/* ---- one guest thread: CPU + GuestThread + a private slice of guest memory ---- */
typedef struct { CPU c; GuestThread th; uint32_t base; } Eng;
#define SLICE 0x8000u
static Eng g_eng[16];
static __thread uint32_t g_err;   /* last error of the latest call by the calling thread's Eng */
static void eng_init(Eng *e, int idx) { memset(e, 0, sizeof *e); e->base = 0x1000u + (uint32_t)idx * SLICE; }
static uint32_t call(Eng *e, void (*fn)(CPU *), int n, const uint32_t *a) {
    t_self = &e->th;
    e->th.last_error = 0xdeadu;
    e->c.esp = e->base + 0x100;
    W32(e->c.esp, 0);
    for (int i = 0; i < n; i++) W32(e->c.esp + 4 + 4u * (uint32_t)i, a[i]);
    fn(&e->c);
    g_err = e->th.last_error;
    return e->c.eax;
}
static uint32_t gstr(Eng *e, int k, const char *s) {
    uint32_t at = e->base + 0x400u + (uint32_t)k * 0x1000u;
    CHECK(strlen(s) < 0xff0);
    strcpy((char *)HP(at), s);
    return at;
}
static uint32_t cf(Eng *e, const char *name, uint32_t access, uint32_t share, uint32_t disp) {
    uint32_t a[7] = { gstr(e, 0, name), access, share, 0, disp, 0, 0 };
    return call(e, w_CreateFileA, 7, a);
}
static uint32_t ch(Eng *e, uint32_t h) { uint32_t a[1] = { h }; return call(e, w_CloseHandle, 1, a); }
static uint32_t dl(Eng *e, const char *n) { uint32_t a[1] = { gstr(e, 0, n) }; return call(e, w_DeleteFileA, 1, a); }
static uint32_t mv(Eng *e, const char *s, const char *d) { uint32_t a[2] = { gstr(e, 0, s), gstr(e, 1, d) }; return call(e, w_MoveFileA, 2, a); }
static uint32_t mkd(Eng *e, const char *n) { uint32_t a[2] = { gstr(e, 0, n), 0 }; return call(e, w_CreateDirectoryA, 2, a); }
static uint32_t rmd(Eng *e, const char *n) { uint32_t a[1] = { gstr(e, 0, n) }; return call(e, w_RemoveDirectoryA, 1, a); }
static uint32_t cpy(Eng *e, const char *s, const char *d, uint32_t fail_if_exists) {
    uint32_t a[3] = { gstr(e, 0, s), gstr(e, 1, d), fail_if_exists };
    return call(e, w_CopyFileA, 3, a);
}
static uint32_t dup_h(Eng *e, uint32_t h) {
    uint32_t a[7] = { 0xFFFFFFFFu, h, 0xFFFFFFFFu, e->base + 0x300u, 0, 0, 2 };
    return call(e, w_DuplicateHandle, 7, a);
}
static uint32_t rd(Eng *e, uint32_t h, void *buf, uint32_t n) {
    uint32_t out = e->base + 0x200u, data = e->base + 0x3000u;
    uint32_t a[5] = { h, data, n, out, 0 };
    uint32_t ok = call(e, w_ReadFile, 5, a);
    if (!ok) return INVALID;
    uint32_t got = R32(out);
    memcpy(buf, HP(data), got);
    return got;
}
static uint32_t wr(Eng *e, uint32_t h, const void *buf, uint32_t n) {
    uint32_t out = e->base + 0x200u, data = e->base + 0x3000u;
    memcpy(HP(data), buf, n);
    uint32_t a[5] = { h, data, n, out, 0 };
    uint32_t ok = call(e, w_WriteFile, 5, a);
    return ok ? R32(out) : INVALID;
}

/* ---- host-side fixture helpers ---- */
static char *hp(const char *name) {
    static __thread char b[4][1200];
    static __thread int i;
    char *r = b[i++ & 3];
    snprintf(r, 1200, "%s/%s", root, name);
    return r;
}
static void put(const char *name, const char *content) {
    FILE *f = fopen(hp(name), "wb");
    CHECK(f && fputs(content, f) >= 0 && !fclose(f));
}
static int slurp(const char *name, char *out, size_t n) {   /* -1 absent */
    FILE *f = fopen(hp(name), "rb");
    if (!f) return -1;
    size_t got = fread(out, 1, n - 1, f);
    fclose(f);
    out[got] = 0;
    return (int)got;
}
static int present(const char *name) { struct stat st; return stat(hp(name), &st) == 0; }
static void expect(const char *name, const char *content) {
    char b[8192];
    int n = slurp(name, b, sizeof b);
    if (n < 0 || strcmp(b, content)) fprintf(stderr, "expect(%s): got %d bytes '%.40s' wanted '%.40s'\n", name, n, n < 0 ? "<absent>" : b, content);
    CHECK(n >= 0 && !strcmp(b, content));
}
static int count_ci(const char *dir, const char *name) {   /* entries equal to name ignoring case */
    DIR *d = opendir(dir[0] ? hp(dir) : root);
    CHECK(d);
    int n = 0;
    struct dirent *e;
    while ((e = readdir(d))) if (!strcasecmp(e->d_name, name)) n++;
    closedir(d);
    return n;
}
static int res_used(void) { int n = 0; for (int i = 0; i < SHARE_RES_MAX; i++) n += g_share_res[i].used; return n; }
static int pend_used(void) { int n = 0; for (int i = 0; i < SHARE_PENDING_MAX; i++) n += g_share_pending[i].used; return n; }
static int live_handles(void) { int n = 0; for (int i = 16; i < MAX_HANDLES; i++) n += g_handles[i].type != H_FREE; return n; }
static void quiescent(int live_before) {
    CHECK(res_used() == 0);
    CHECK(pend_used() == 0);
    CHECK(live_handles() == live_before);
}

/* ------------------------------------------------------------------------------------------ */
/* permissive default: the contracts the strict work must not change                          */
/* ------------------------------------------------------------------------------------------ */
static void t_default(void) {
    Eng *e = &g_eng[0];
    put("data", "KEEP");
    uint32_t h1 = cf(e, "data", GENERIC_READ, 0, OPEN_EXISTING);
    CHECK(h1 != INVALID);
    uint32_t h2 = cf(e, "data", GENERIC_WRITE, 0, OPEN_EXISTING);   /* share flags are ignored */
    CHECK(h2 != INVALID && h2 != h1);
    CHECK(ch(e, h1) == 1);
    uint32_t h3 = cf(e, "data", GENERIC_READ, 7, OPEN_EXISTING);
    CHECK(h3 == h1);                       /* lowest free slot is reused at once: no round robin */
    CHECK(ch(e, h3) == 1 && ch(e, h3) == 1);   /* a double close still reports success */
    CHECK(ch(e, 0) == 1 && ch(e, 0xdeadbeefu) == 1 && ch(e, 0x1003u) == 1);
    CHECK(dup_h(e, h2) == 1);              /* the alias "duplicate" of a file handle stays */
    CHECK(ch(e, h2) == 1);
    /* delete of an open file unlinks at once (no delete-pending) */
    uint32_t h4 = cf(e, "data", GENERIC_READ, FS_R | FS_W | FS_D, OPEN_EXISTING);
    CHECK(h4 != INVALID);
    CHECK(dl(e, "data") == 1 && !present("data"));
    CHECK(ch(e, h4) == 1);
    /* directories */
    CHECK(mkd(e, "dd") == 1);
    CHECK(mkd(e, "dd") == 0 && g_err == ERROR_ALREADY_EXISTS);
    CHECK(rmd(e, "dd") == 1);
    /* CopyFileA to an ABSENT destination fails (existing quirk of the default path, see F32_AUDIT.md) */
    put("src", "SRC");
    CHECK(cpy(e, "src", "newdst", 0) == 0 && !present("newdst"));
    put("dst", "OLD");
    CHECK(cpy(e, "src", "dst", 0) == 1);
    expect("dst", "SRC");
    CHECK(cpy(e, "src", "dst", 1) == 0 && g_err == ERROR_FILE_EXISTS);
    unlink(hp("src")); unlink(hp("dst"));
    CHECK(res_used() == 0 && pend_used() == 0);
    puts("F3.2 default (permissive) contracts: PASS");
}

/* ------------------------------------------------------------------------------------------ */
/* identity and aliases                                                                        */
/* ------------------------------------------------------------------------------------------ */
static void t_aliases(void) {
    Eng *e = &g_eng[0];
    int live = live_handles();
    put("data", "KEEP");
    mkdir(hp("sub"), 0755);
    uint32_t h = cf(e, "data", GENERIC_READ, 0, OPEN_EXISTING);
    CHECK(h != INVALID);
    static const char *aliases[] = {
        "DATA", "Data", ".\\data", "sub\\..\\data", "nosuch\\..\\data", "data\\", ".\\.\\data", "sub\\.\\..\\DATA",
        "C:\\Games\\Korsary2\\data", "c:/games/korsary2/DATA", "C:\\Games\\Korsary2\\sub\\..\\data",
        "C:\\Games\\Korsary2\\\\data", ".\\\\data", "data.", "data..", "data ", "data. .", "DATA. ", NULL };
    for (int i = 0; aliases[i]; i++) {
        uint32_t x = cf(e, aliases[i], GENERIC_READ, FS_R | FS_W | FS_D, OPEN_EXISTING);
        if (x != INVALID || g_err != ERROR_SHARING_VIOLATION) fprintf(stderr, "alias %s: h=%x err=%u\n", aliases[i], x, g_err);
        CHECK(x == INVALID && g_err == ERROR_SHARING_VIOLATION);
        /* a refused alias must neither create nor truncate anything */
        uint32_t y = cf(e, aliases[i], GENERIC_WRITE, FS_R | FS_W | FS_D, CREATE_ALWAYS);
        CHECK(y == INVALID && g_err == ERROR_SHARING_VIOLATION);
        expect("data", "KEEP");
    }
    CHECK(!present("data.") && !present("data..") && !present("data "));   /* nothing was created under an alias spelling */
    CHECK(dl(e, "DATA") == 0 && g_err == ERROR_SHARING_VIOLATION);   /* delete through an alias */
    CHECK(mv(e, "Data", "moved") == 0 && !present("moved"));
    expect("data", "KEEP");
    CHECK(ch(e, h) == 1);
    /* compatible sharing through an alias is the normal matrix, not a blanket refusal */
    uint32_t a = cf(e, "data", GENERIC_READ, FS_R | FS_W, OPEN_EXISTING);
    CHECK(a != INVALID);
    uint32_t b = cf(e, ".\\DATA", GENERIC_WRITE, FS_R | FS_W, OPEN_EXISTING);
    CHECK(b != INVALID);
    CHECK(cf(e, "sub\\..\\data", GENERIC_WRITE, FS_R, OPEN_EXISTING) == INVALID && g_err == ERROR_SHARING_VIOLATION);
    CHECK(ch(e, a) == 1 && ch(e, b) == 1);
    /* two spellings of an ABSENT name never create two entries (trailing-dot alias of a new file) */
    uint32_t n1 = cf(e, "fresh", GENERIC_WRITE, FS_R | FS_W | FS_D, CREATE_ALWAYS);
    CHECK(n1 != INVALID);
    CHECK(cf(e, "fresh.", GENERIC_WRITE, FS_R | FS_W | FS_D, CREATE_ALWAYS) == INVALID && g_err == ERROR_SHARING_VIOLATION);
    CHECK(count_ci("", "fresh") == 1 && !present("fresh."));
    CHECK(ch(e, n1) == 1);
#if SHARE_INODE_IDENTITY
    /* hard links and symlinks are the same object where the host has real inodes */
    CHECK(!link(hp("data"), hp("hl")) && !symlink("data", hp("sl")));
    h = cf(e, "data", GENERIC_READ, 0, OPEN_EXISTING);
    CHECK(h != INVALID);
    CHECK(cf(e, "hl", GENERIC_READ, FS_R, OPEN_EXISTING) == INVALID && g_err == ERROR_SHARING_VIOLATION);
    CHECK(cf(e, "sl", GENERIC_WRITE, FS_R | FS_W, OPEN_EXISTING) == INVALID && g_err == ERROR_SHARING_VIOLATION);
    CHECK(ch(e, h) == 1);
    h = cf(e, "data", GENERIC_READ, FS_R | FS_W, OPEN_EXISTING);
    uint32_t hl = cf(e, "hl", GENERIC_WRITE, FS_R | FS_W, OPEN_EXISTING);   /* compatible: the matrix decides */
    CHECK(h != INVALID && hl != INVALID);
    CHECK(cf(e, "sl", GENERIC_WRITE, FS_R, OPEN_EXISTING) == INVALID && g_err == ERROR_SHARING_VIOLATION);
    CHECK(ch(e, h) == 1 && ch(e, hl) == 1);
    unlink(hp("hl")); unlink(hp("sl"));
#endif
    unlink(hp("data")); unlink(hp("fresh")); rmdir(hp("sub"));
    quiescent(live);
    puts("F3.2 aliases and identity (strict): PASS");
}

/* ------------------------------------------------------------------------------------------ */
/* delete-pending                                                                               */
/* ------------------------------------------------------------------------------------------ */
static void t_delete_pending(void) {
    Eng *e = &g_eng[0];
    int live = live_handles();
    char buf[64];
    /* every handle shares DELETE: DeleteFileA succeeds, the file stays until the last close */
    put("data", "KEEP");
    uint32_t h1 = cf(e, "data", GENERIC_READ, FS_R | FS_W | FS_D, OPEN_EXISTING);
    uint32_t h2 = cf(e, "data", GENERIC_READ | GENERIC_WRITE, FS_R | FS_W | FS_D, OPEN_EXISTING);
    CHECK(h1 != INVALID && h2 != INVALID);
    CHECK(dl(e, "data") == 1 && g_err == 0);
    CHECK(pend_used() == 1 && present("data"));
    CHECK(dl(e, "data") == 0 && g_err == ERROR_ACCESS_DENIED);                       /* delete again */
    CHECK(dl(e, "DATA") == 0 && g_err == ERROR_ACCESS_DENIED);                       /* ...through an alias */
    CHECK(cf(e, "data", GENERIC_READ, FS_R | FS_W | FS_D, OPEN_EXISTING) == INVALID && g_err == ERROR_ACCESS_DENIED);
    CHECK(cf(e, ".\\Data", GENERIC_WRITE, FS_R | FS_W | FS_D, CREATE_ALWAYS) == INVALID && g_err == ERROR_ACCESS_DENIED);
    CHECK(cf(e, "data", GENERIC_WRITE, FS_R | FS_W | FS_D, OPEN_ALWAYS) == INVALID && g_err == ERROR_ACCESS_DENIED);
    CHECK(mkd(e, "data") == 0 && g_err == ERROR_ACCESS_DENIED);
    CHECK(cpy(e, "data", "copy", 0) == 0 && g_err == ERROR_ACCESS_DENIED && !present("copy"));
    put("other", "O");
    CHECK(cpy(e, "other", "data", 0) == 0 && g_err == ERROR_ACCESS_DENIED);
#if MOVE_OK
    CHECK(mv(e, "data", "moved") == 0 && g_err == ERROR_ACCESS_DENIED);
    CHECK(mv(e, "other", "data") == 0 && g_err == ERROR_ACCESS_DENIED);
#endif
    expect("data", "KEEP");                                                           /* nothing was touched */
    CHECK(rd(e, h1, buf, sizeof buf) == 4 && !memcmp(buf, "KEEP", 4));                /* handles keep working */
    CHECK(wr(e, h2, "Z", 1) == 1);
    CHECK(ch(e, h1) == 1);
    CHECK(present("data") && pend_used() == 1);                                        /* one handle left */
    CHECK(ch(e, h2) == 1);
    CHECK(!present("data") && pend_used() == 0);                                       /* last close unlinks */
    CHECK(cf(e, "data", GENERIC_READ, 0, OPEN_EXISTING) == INVALID && g_err == ERROR_FILE_NOT_FOUND);
    uint32_t n = cf(e, "data", GENERIC_WRITE, 0, CREATE_ALWAYS);                       /* the name is free again */
    CHECK(n != INVALID && g_err == 0);
    CHECK(ch(e, n) == 1);
    expect("data", "");                                                               /* a fresh file, not the old one */
    unlink(hp("data")); unlink(hp("other"));

    /* a handle that does not share DELETE refuses the delete and nothing becomes pending */
    put("data", "KEEP");
    h1 = cf(e, "data", GENERIC_READ, FS_R | FS_W, OPEN_EXISTING);
    CHECK(dl(e, "data") == 0 && g_err == ERROR_SHARING_VIOLATION && pend_used() == 0);
    h2 = cf(e, "data", GENERIC_READ, FS_R | FS_W | FS_D, OPEN_EXISTING);
    CHECK(dl(e, "data") == 0 && g_err == ERROR_SHARING_VIOLATION && pend_used() == 0);
    CHECK(ch(e, h1) == 1);
    CHECK(dl(e, "data") == 1 && pend_used() == 1);                                     /* now only h2 remains */
    CHECK(ch(e, h2) == 1 && !present("data"));

    /* DELETE access: a delete-sharing handle opened with DELETE is itself compatible */
    put("data", "KEEP");
    h1 = cf(e, "data", GENERIC_READ | DELETE_ACC, FS_R | FS_D, OPEN_EXISTING);
    CHECK(h1 != INVALID);
    CHECK(dl(e, "data") == 1 && ch(e, h1) == 1 && !present("data"));

    /* the pending delete table is bounded: a full table refuses, nothing is lost */
    uint32_t hs[SHARE_PENDING_MAX + 1];
    char nm[32];
    for (int i = 0; i <= SHARE_PENDING_MAX; i++) {
        snprintf(nm, sizeof nm, "p%d", i);
        put(nm, "P");
        hs[i] = cf(e, nm, GENERIC_READ, FS_R | FS_W | FS_D, OPEN_EXISTING);
        CHECK(hs[i] != INVALID);
    }
    for (int i = 0; i < SHARE_PENDING_MAX; i++) { snprintf(nm, sizeof nm, "p%d", i); CHECK(dl(e, nm) == 1); }
    snprintf(nm, sizeof nm, "p%d", SHARE_PENDING_MAX);
    CHECK(dl(e, nm) == 0 && g_err == ERROR_NOT_SUPPORTED && present(nm));
    char last[32];
    snprintf(last, sizeof last, "p%d", SHARE_PENDING_MAX);
    for (int i = 0; i <= SHARE_PENDING_MAX; i++) CHECK(ch(e, hs[i]) == 1);
    for (int i = 0; i < SHARE_PENDING_MAX; i++) { snprintf(nm, sizeof nm, "p%d", i); CHECK(!present(nm)); }
    CHECK(present(last));   /* the refused one is still there */
    unlink(hp(last));
    quiescent(live);

#if SHARE_INODE_IDENTITY
    /* the file behind a pending name was replaced from OUTSIDE the registry: the new file is left alone */
    put("data", "OLD");
    h1 = cf(e, "data", GENERIC_READ, FS_R | FS_W | FS_D, OPEN_EXISTING);
    CHECK(dl(e, "data") == 1);
    CHECK(!rename(hp("data"), hp("gone")));
    put("data", "NEW");
    CHECK(ch(e, h1) == 1);
    expect("data", "NEW");
    unlink(hp("data")); unlink(hp("gone"));
    quiescent(live);
#endif
    puts("F3.2 delete-pending (strict): PASS");
}

/* ------------------------------------------------------------------------------------------ */
/* exhaustion: refusals precede any truncation, nothing leaks                                   */
/* ------------------------------------------------------------------------------------------ */
static void t_exhaustion(void) {
    Eng *e = &g_eng[0];
    int live = live_handles();
    put("victim", "KEEP");
    put("race", "R");
    /* (a) share registry full */
    uint32_t hs[SHARE_RES_MAX];
    for (int i = 0; i < SHARE_RES_MAX; i++) { hs[i] = cf(e, "race", GENERIC_READ, FS_R | FS_W | FS_D, OPEN_EXISTING); CHECK(hs[i] != INVALID); }
    CHECK(cf(e, "victim", GENERIC_WRITE, FS_R | FS_W | FS_D, CREATE_ALWAYS) == INVALID && g_err == ERROR_SHARING_VIOLATION);
    expect("victim", "KEEP");
    CHECK(cf(e, "brandnew", GENERIC_WRITE, FS_R | FS_W | FS_D, OPEN_ALWAYS) == INVALID && !present("brandnew"));
    CHECK(cf(e, "victim", GENERIC_WRITE, FS_R | FS_W | FS_D, TRUNCATE_EXISTING) == INVALID);
    expect("victim", "KEEP");
    CHECK(cpy(e, "victim", "victim2", 0) == 0 && !present("victim2"));
    for (int i = 0; i < SHARE_RES_MAX; i++) CHECK(ch(e, hs[i]) == 1);
    quiescent(live);
    /* a failed open must not leak a reservation or a handle slot, however often it fails */
    for (int i = 0; i < 3 * SHARE_RES_MAX; i++) CHECK(cf(e, "absent", GENERIC_READ, FS_R, OPEN_EXISTING) == INVALID && g_err == ERROR_FILE_NOT_FOUND);
    quiescent(live);
    /* (b) handle table full: the open is refused BEFORE a truncating host open ran */
    uint32_t ev[MAX_HANDLES];
    int nev = 0;
    for (uint32_t t; (t = handle_try_new(H_EVENT)) != 0; ) ev[nev++] = t;
    CHECK(nev > 100 && live_handles() == MAX_HANDLES - 16);
    uint32_t r = cf(e, "victim", GENERIC_WRITE, FS_R | FS_W | FS_D, CREATE_ALWAYS);
    CHECK(r == INVALID && g_err == ERROR_TOO_MANY_OPEN_FILES);
    expect("victim", "KEEP");
    CHECK(cf(e, "victim", GENERIC_WRITE, FS_R | FS_W | FS_D, TRUNCATE_EXISTING) == INVALID && g_err == ERROR_TOO_MANY_OPEN_FILES);
    CHECK(cf(e, "victim", GENERIC_WRITE, FS_R | FS_W | FS_D, OPEN_ALWAYS) == INVALID);
    CHECK(cf(e, "newfile", GENERIC_WRITE, FS_R | FS_W | FS_D, CREATE_ALWAYS) == INVALID && !present("newfile"));
    CHECK(cf(e, "dir9/newfile", GENERIC_WRITE, FS_R | FS_W | FS_D, CREATE_ALWAYS) == INVALID && !present("dir9"));
    expect("victim", "KEEP");
    CHECK(res_used() == 0);                         /* the refused opens left no reservation behind */
    CHECK(ch(e, ev[--nev]) == 1);                   /* one slot frees: the same open now works */
    uint32_t ok = cf(e, "victim", GENERIC_WRITE, FS_R | FS_W | FS_D, CREATE_ALWAYS);
    CHECK(ok != INVALID);
    CHECK(ch(e, ok) == 1);
    expect("victim", "");
    while (nev) CHECK(ch(e, ev[--nev]) == 1);
    quiescent(live);
    /* (c) a path that does not fit the registry */
    char longname[700] = "";
    for (int i = 0; i < 22; i++) strcat(longname, i ? "\\aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" : "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    CHECK(cf(e, longname, GENERIC_WRITE, FS_R | FS_W | FS_D, CREATE_ALWAYS) == INVALID && g_err == ERROR_FILENAME_EXCED_RANGE);
    CHECK(!present("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"));
    CHECK(dl(e, longname) == 0 && g_err == ERROR_FILENAME_EXCED_RANGE);
    CHECK(mkd(e, longname) == 0 && g_err == ERROR_FILENAME_EXCED_RANGE);
    unlink(hp("victim")); unlink(hp("race"));
    quiescent(live);
    puts("F3.2 exhaustion: refusal before truncation, no leaks (strict): PASS");
}

/* ------------------------------------------------------------------------------------------ */
/* closing                                                                                       */
/* ------------------------------------------------------------------------------------------ */
static void t_close(void) {
    Eng *e = &g_eng[0];
    int live = live_handles();
    put("data", "KEEP");
    uint32_t h1 = cf(e, "data", GENERIC_READ, 0, OPEN_EXISTING);
    CHECK(h1 != INVALID);
    CHECK(ch(e, h1) == 1);
    CHECK(ch(e, h1) == 0 && g_err == ERROR_INVALID_HANDLE);                           /* double close */
    CHECK(ch(e, h1) == 0 && g_err == ERROR_INVALID_HANDLE);
    uint32_t h2 = cf(e, "data", GENERIC_READ, 0, OPEN_EXISTING);                       /* exclusive again */
    CHECK(h2 != INVALID && h2 != h1);                                                  /* a closed value is not handed out at once */
    CHECK(ch(e, h1) == 0 && g_err == ERROR_INVALID_HANDLE);                            /* the stale close hits nothing */
    char b[8];
    CHECK(rd(e, h2, b, 4) == 4 && !memcmp(b, "KEEP", 4));                              /* h2 is alive... */
    CHECK(cf(e, "data", GENERIC_READ, FS_R, OPEN_EXISTING) == INVALID && g_err == ERROR_SHARING_VIOLATION);   /* ...and still reserved */
    CHECK(ch(e, h2) == 1);
    /* values that were never handles */
    static const uint32_t junk[] = { 0, 0x1, 0xF3, 0x1003, 0x1000 + 4 * MAX_HANDLES, 0x7fffffff, 0xdeadbeef, 0x1000 + 4 * 7 };
    for (size_t i = 0; i < sizeof junk / sizeof *junk; i++) CHECK(ch(e, junk[i]) == 0 && g_err == ERROR_INVALID_HANDLE);
    /* pseudo handles that code legitimately closes keep answering TRUE */
    CHECK(ch(e, 0xFFFFFFFFu) == 1 && ch(e, 0xFFFFFFFEu) == 1 && ch(e, 0xF4) == 1 && ch(e, 0xF8) == 1 && ch(e, 0xF0) == 1);
    /* non-file handles close once */
    uint32_t ev = handle_new(H_EVENT);
    CHECK(ch(e, ev) == 1 && ch(e, ev) == 0);
    /* a mapping handle closes its dup'd descriptor (the default path leaks it) */
    h1 = cf(e, "data", GENERIC_READ, FS_R | FS_W | FS_D, OPEN_EXISTING);
    uint32_t a[6] = { h1, 0, 2, 0, 0, 0 };
    uint32_t m = call(e, w_CreateFileMappingA, 6, a);
    CHECK(m != 0 && handle_get(m, H_MAPPING)->fd >= 0);
    int mfd = handle_get(m, H_MAPPING)->fd;
    CHECK(ch(e, m) == 1);
    CHECK(fcntl(mfd, F_GETFD) == -1 && errno == EBADF);
    CHECK(ch(e, h1) == 1);
    /* DuplicateHandle of a file would alias the value without a reference count: refused */
    h1 = cf(e, "data", GENERIC_READ, FS_R | FS_W | FS_D, OPEN_EXISTING);
    CHECK(dup_h(e, h1) == 0 && g_err == ERROR_NOT_SUPPORTED);
    CHECK(rd(e, h1, b, 4) == 4);   /* the source stays usable */
    CHECK(ch(e, h1) == 1);
    uint32_t ev2 = handle_new(H_EVENT);
    CHECK(dup_h(e, ev2) == 1);
    CHECK(ch(e, ev2) == 1);
    /* handle values walk round robin: 3000 open/close cycles never repeat a value inside a window */
    uint32_t seen_first = 0;
    for (int i = 0; i < 3000; i++) {
        uint32_t h = cf(e, "data", GENERIC_READ, FS_R | FS_W | FS_D, OPEN_EXISTING);
        CHECK(h != INVALID);
        if (i == 0) seen_first = h;
        CHECK(i == 0 || h != seen_first || i > 2000);
        CHECK(ch(e, h) == 1);
    }
    unlink(hp("data"));
    quiescent(live);
    puts("F3.2 close semantics (strict): PASS");
}

/* ------------------------------------------------------------------------------------------ */
/* directories                                                                                   */
/* ------------------------------------------------------------------------------------------ */
static void t_dirs(void) {
    Eng *e = &g_eng[0];
    int live = live_handles();
    CHECK(mkd(e, "Dir") == 1 && g_err == 0);
    CHECK(mkd(e, "dir") == 0 && g_err == ERROR_ALREADY_EXISTS);        /* the other spelling resolves to the same */
    CHECK(mkd(e, "DIR\\") == 0 && g_err == ERROR_ALREADY_EXISTS);
    CHECK(count_ci("", "dir") == 1);
    CHECK(mkd(e, "nosuch\\child") == 0 && g_err == ERROR_PATH_NOT_FOUND);
    CHECK(mkd(e, "Dir\\sub") == 1);
    CHECK(rmd(e, "dir") == 0 && g_err == ERROR_DIR_NOT_EMPTY);          /* non-empty */
    CHECK(rmd(e, "Dir\\sub") == 1);
    CHECK(rmd(e, "Dir\\sub") == 0 && g_err == ERROR_FILE_NOT_FOUND);    /* leaf missing, parent present */
    CHECK(rmd(e, "nosuch\\sub") == 0 && g_err == ERROR_PATH_NOT_FOUND);
    put("Dir/f", "F");
    CHECK(rmd(e, "Dir\\f") == 0 && g_err == ERROR_DIRECTORY);           /* a file is not a directory */
    CHECK(rmd(e, "Dir") == 0 && g_err == ERROR_DIR_NOT_EMPTY);
    /* an open file below keeps its directory alive, and a delete-pending file does too */
    uint32_t h = cf(e, "dir\\f", GENERIC_READ, FS_R | FS_W | FS_D, OPEN_EXISTING);
    CHECK(h != INVALID);
    CHECK(rmd(e, "DIR") == 0 && g_err == ERROR_DIR_NOT_EMPTY);
    CHECK(dl(e, "Dir\\f") == 1 && rmd(e, "Dir") == 0 && g_err == ERROR_DIR_NOT_EMPTY && present("Dir/f"));
    CHECK(ch(e, h) == 1 && !present("Dir/f"));
    CHECK(rmd(e, "Dir") == 1 && !present("Dir"));
    /* an open that is creating its parents makes a differently spelled mkdir/rmdir of them a conflict */
    uint32_t c = cf(e, "Up\\x", GENERIC_WRITE, FS_R | FS_W | FS_D, CREATE_ALWAYS);   /* creates "Up" */
    CHECK(c != INVALID);
    CHECK(mkd(e, "up") == 0 && g_err == ERROR_ALREADY_EXISTS);          /* resolves to the real spelling */
    CHECK(rmd(e, "UP") == 0 && g_err == ERROR_DIR_NOT_EMPTY);
    CHECK(ch(e, c) == 1);
    unlink(hp("Up/x"));
    CHECK(rmd(e, "up") == 1);
    quiescent(live);
    puts("F3.2 directory operations (strict): PASS");
}

/* ------------------------------------------------------------------------------------------ */
/* an open that is still in flight (registry entry without a published handle)                  */
/* ------------------------------------------------------------------------------------------ */
static ShareRes *fake_inflight(const char *rel, uint32_t desired, uint32_t share) {
    ShareRes *r = share_reserve();
    char p[1200];
    snprintf(p, sizeof p, "%s/%s", root, rel);
    CHECK(r && share_name_make(p, &r->n));
    r->desired = desired; r->share = share; r->established = 0;
    return r;
}
static void t_inflight(void) {
    Eng *e = &g_eng[0];
    int live = live_handles();
    mkdir(hp("rd"), 0755);
    /* an open that is still creating "rd/f" keeps the (still empty) directory alive */
    ShareRes *r = fake_inflight("rd/f", SH_WRITE, FS_R | FS_W | FS_D);
    CHECK(rmd(e, "rd") == 0 && g_err == ERROR_DIR_NOT_EMPTY && present("rd"));
    CHECK(rmd(e, "RD") == 0 && g_err == ERROR_DIR_NOT_EMPTY);
    r->used = 0;
    CHECK(rmd(e, "rd") == 1 && !present("rd"));
    /* a delete racing an in-flight open of the same name is refused, never turned into a pending delete */
    put("f", "F");
    r = fake_inflight("f", SH_READ, FS_R | FS_W | FS_D);
    CHECK(dl(e, "f") == 0 && g_err == ERROR_NOT_SUPPORTED && present("f") && pend_used() == 0);
    r->used = 0;
    CHECK(dl(e, "f") == 1);
    /* another spelling of a directory that an open is creating: refused; the same spelling is fine */
    r = fake_inflight("Pd/x", SH_WRITE, FS_R | FS_W | FS_D);
    CHECK(mkd(e, "pd") == 0 && g_err == ERROR_SHARING_VIOLATION && !present("pd"));
    CHECK(rmd(e, "pd") == 0 && g_err == ERROR_DIR_NOT_EMPTY);   /* something is being created below it */
    CHECK(mkd(e, "Pd") == 1);
    r->used = 0;
    CHECK(rmd(e, "Pd") == 1);
    quiescent(live);
    puts("F3.2 in-flight open vs directory/delete operations (strict): PASS");
}

/* ------------------------------------------------------------------------------------------ */
/* CopyFileA                                                                                     */
/* ------------------------------------------------------------------------------------------ */
static void t_copy(void) {
    Eng *e = &g_eng[0];
    int live = live_handles();
    put("src", "SOURCE");
    CHECK(cpy(e, "src", "dst", 0) == 1 && g_err == 0);                    /* an absent destination is created */
    expect("dst", "SOURCE");
    put("dst", "OLD");
    CHECK(cpy(e, "src", "dst", 1) == 0 && g_err == ERROR_FILE_EXISTS);
    expect("dst", "OLD");
    CHECK(cpy(e, "src", "DST", 0) == 1);
    expect("dst", "SOURCE");
    CHECK(cpy(e, "nosuch", "x", 0) == 0 && g_err == ERROR_FILE_NOT_FOUND && !present("x"));
    CHECK(res_used() == 0);
    /* a copy onto itself, also through an alias, is a sharing violation and changes nothing */
    CHECK(cpy(e, "src", "src", 0) == 0 && g_err == ERROR_SHARING_VIOLATION);
    CHECK(cpy(e, "src", "SRC", 0) == 0 && g_err == ERROR_SHARING_VIOLATION);
    CHECK(cpy(e, "src", ".\\src", 0) == 0 && g_err == ERROR_SHARING_VIOLATION);
    expect("src", "SOURCE");
    /* an open writer of the source blocks the copy (the copy reads with FILE_SHARE_READ only) */
    uint32_t w = cf(e, "src", GENERIC_WRITE, FS_R | FS_W, OPEN_EXISTING);
    CHECK(w != INVALID);
    CHECK(cpy(e, "src", "dst", 0) == 0 && g_err == ERROR_SHARING_VIOLATION);
    expect("dst", "SOURCE");                                               /* the destination was not touched */
    CHECK(ch(e, w) == 1);
    /* a reader that shares READ does not */
    uint32_t r = cf(e, "src", GENERIC_READ, FS_R, OPEN_EXISTING);
    CHECK(cpy(e, "src", "dst", 0) == 1);
    CHECK(ch(e, r) == 1);
    /* any open handle of the destination blocks the copy BEFORE it truncates it */
    put("dst", "KEEPDST");
    uint32_t d = cf(e, "dst", GENERIC_READ, FS_R | FS_W | FS_D, OPEN_EXISTING);
    CHECK(cpy(e, "src", "dst", 0) == 0 && g_err == ERROR_SHARING_VIOLATION);
    expect("dst", "KEEPDST");
    CHECK(ch(e, d) == 1);
    CHECK(res_used() == 0);
    /* registry full: refused before any truncation */
    uint32_t hs[SHARE_RES_MAX];
    put("other", "O");
    for (int i = 0; i < SHARE_RES_MAX; i++) hs[i] = cf(e, "other", GENERIC_READ, FS_R | FS_W | FS_D, OPEN_EXISTING);
    CHECK(cpy(e, "src", "dst", 0) == 0);
    expect("dst", "KEEPDST");
    for (int i = 0; i < SHARE_RES_MAX; i++) CHECK(ch(e, hs[i]) == 1);
    /* a failed copy removes only a destination this call created */
    CHECK(cpy(e, "src", "nodir\\x", 0) == 0 && g_err == ERROR_PATH_NOT_FOUND && !present("nodir"));
    unlink(hp("src")); unlink(hp("dst")); unlink(hp("other"));
    quiescent(live);
    puts("F3.2 CopyFileA (strict): PASS");
}

/* ------------------------------------------------------------------------------------------ */
/* SAVE_TX / SAVE_META compatibility (only in the browser configuration build)                  */
/* ------------------------------------------------------------------------------------------ */
#if SAVE_META_ON && defined(PORT_SAVE_TX)
static void t_save_compat(void) {
    Eng *e = &g_eng[0];
    int live = live_handles();
    mkdir(hp("SAVE"), 0755);
    put("SAVE/slot1", "OLDSLOT");
    save_meta_write("slot1", guest_time_100ns());
    CHECK(save_meta_exists("slot1"));
    uint32_t h = cf(e, "SAVE\\slot1", GENERIC_READ, FS_R | FS_W | FS_D, OPEN_EXISTING);
    CHECK(h != INVALID);
    CHECK(dl(e, "SAVE\\slot1") == 1);
    /* nothing destructive happened yet: no journal, slot and record intact */
    CHECK(!present("SAVE_TX/journal.log") && present("SAVE/slot1") && save_meta_exists("slot1"));
    CHECK(ch(e, h) == 1);
    /* the last close ran the delete through the SAVE_TX arm: prior copy and journal exist, slot and record gone */
    CHECK(!present("SAVE/slot1") && !save_meta_exists("slot1"));
    char j[8192];
    CHECK(slurp("SAVE_TX/journal.log", j, sizeof j) > 0 && strstr(j, " arm ") && strstr(j, "kind=delete"));
    int priors = 0;
    DIR *d = opendir(hp("SAVE_TX"));
    struct dirent *de;
    while (d && (de = readdir(d))) if (!strncmp(de->d_name, "prior-", 6)) {
        char path[300], b[32];
        snprintf(path, sizeof path, "SAVE_TX/%s", de->d_name);
        CHECK(slurp(path, b, sizeof b) == 7 && !strcmp(b, "OLDSLOT"));
        priors++;
    }
    if (d) closedir(d);
    CHECK(priors == 1);
    /* the engine overwrite flow still works: delete, create, write, close (twice) with SAVE_TX on */
    put("SAVE/slot2", "OLD2");
    CHECK(dl(e, "SAVE\\slot2") == 1);
    for (int cycle = 0; cycle < 2; cycle++) {
        uint32_t w = cf(e, "SAVE\\slot2", GENERIC_WRITE, FS_R | FS_W, CREATE_ALWAYS);
        CHECK(w != INVALID && wr(e, w, "NEW2", 4) == 4 && ch(e, w) == 1);
    }
    expect("SAVE/slot2", "NEW2");
    quiescent(live);
    puts("F3.2 pending delete with SAVE_TX/SAVE_META (strict): PASS");
}
#endif

/* ------------------------------------------------------------------------------------------ */
/* concurrency (also the ThreadSanitizer target)                                                 */
/* ------------------------------------------------------------------------------------------ */
typedef struct { pthread_mutex_t m; pthread_cond_t cv; int n, arrived, gen; } Barrier;
static void barrier_init(Barrier *b, int n) { pthread_mutex_init(&b->m, NULL); pthread_cond_init(&b->cv, NULL); b->n = n; b->arrived = b->gen = 0; }
static void barrier_wait(Barrier *b) {
    pthread_mutex_lock(&b->m);
    int g = b->gen;
    if (++b->arrived == b->n) { b->arrived = 0; b->gen++; pthread_cond_broadcast(&b->cv); }
    else while (g == b->gen) pthread_cond_wait(&b->cv, &b->m);
    pthread_mutex_unlock(&b->m);
}
#define NT 8
typedef struct { int idx; Barrier *bar; int rounds; volatile int *stop; uint32_t shared_h; int result; int wins; } Task;

static void run_threads(void *(*fn)(void *), Task *tasks, int n) {
    pthread_t th[16];
    for (int i = 0; i < n; i++) CHECK(!pthread_create(&th[i], NULL, fn, &tasks[i]));
    for (int i = 0; i < n; i++) CHECK(!pthread_join(th[i], NULL));
}
static __attribute__((unused)) int g_win_count;

/* C1: N threads race for the same exclusive open: exactly one wins per round */
static void *c1(void *p) {
    Task *t = p;
    Eng *e = &g_eng[t->idx];
    for (int r = 0; r < t->rounds; r++) {
        barrier_wait(t->bar);
        uint32_t h = cf(e, "race", GENERIC_READ, 0, OPEN_EXISTING);
        if (h != INVALID) { __atomic_add_fetch(&g_win_count, 1, __ATOMIC_RELAXED); t->shared_h = h; }
        else if (g_err != ERROR_SHARING_VIOLATION) t->result = 1;
        barrier_wait(t->bar);
        if (h != INVALID) CHECK(ch(e, h) == 1);
        barrier_wait(t->bar);
    }
    return NULL;
}
/* C2: CREATE_ALWAYS racers against a held reader never truncate */
typedef struct { int stop; } Gate;   /* accessed with __atomic only */
#define GATE_STOPPED(g) __atomic_load_n(&(g).stop, __ATOMIC_ACQUIRE)
#define GATE_STOP(g) __atomic_store_n(&(g).stop, 1, __ATOMIC_RELEASE)
static Gate g_gate;
static void *c2_writer(void *p) {
    Task *t = p;
    Eng *e = &g_eng[t->idx];
    while (!GATE_STOPPED(g_gate)) {
        uint32_t h = cf(e, "keep", GENERIC_WRITE, FS_R | FS_W | FS_D, t->idx & 1 ? CREATE_ALWAYS : TRUNCATE_EXISTING);
        if (h != INVALID) { t->result = 1; ch(e, h); }
        else if (g_err != ERROR_SHARING_VIOLATION) t->result = 2;
        t->wins++;
        sched_yield();
    }
    return NULL;
}
/* C3: concurrent deletes of a file held open with FILE_SHARE_DELETE: exactly one succeeds */
static void *c3(void *p) {
    Task *t = p;
    Eng *e = &g_eng[t->idx];
    for (int r = 0; r < t->rounds; r++) {
        barrier_wait(t->bar);
        uint32_t ok = dl(e, "victim");
        if (ok) __atomic_add_fetch(&g_win_count, 1, __ATOMIC_RELAXED);
        else if (g_err != ERROR_ACCESS_DENIED) t->result = 1;
        barrier_wait(t->bar);
        barrier_wait(t->bar);
    }
    return NULL;
}
/* C4: many threads close the same value: exactly one succeeds */
static void *c4(void *p) {
    Task *t = p;
    Eng *e = &g_eng[t->idx];
    for (int r = 0; r < t->rounds; r++) {
        barrier_wait(t->bar);
        uint32_t ok = ch(e, t->shared_h);
        if (ok) __atomic_add_fetch(&g_win_count, 1, __ATOMIC_RELAXED);
        else if (g_err != ERROR_INVALID_HANDLE) t->result = 1;
        barrier_wait(t->bar);
        barrier_wait(t->bar);
    }
    return NULL;
}
/* C5: spellings of an absent directory and of an absent file's parent never both get created */
static void *c5(void *p) {
    Task *t = p;
    Eng *e = &g_eng[t->idx];
    static const char *dirs[] = { "NewDir", "newdir", "NEWDIR", "nEwDiR" };
    static const char *files[] = { "Par\\a", "par\\b", "PAR\\c", "pAR\\d" };
    barrier_wait(t->bar);
    if (t->idx < 4) mkd(e, dirs[t->idx]);
    else {
        uint32_t h = cf(e, files[t->idx - 4], GENERIC_WRITE, FS_R | FS_W | FS_D, CREATE_ALWAYS);
        if (h != INVALID) { t->result = 1; ch(e, h); }
    }
    return NULL;
}
/* C6: stress with stale closes and aliases of a few files; invariants checked at the end */
static void *c6(void *p) {
    Task *t = p;
    Eng *e = &g_eng[t->idx];
    unsigned seed = 1234u + (unsigned)t->idx;
    uint32_t old[8] = { 0 };
    static const char *names[] = { "s0", "S1", ".\\s2", "s3" };
    for (int i = 0; i < t->rounds; i++) {
        const char *nm = names[rand_r(&seed) & 3];
        uint32_t h = cf(e, nm, GENERIC_READ | ((i & 3) == 0 ? GENERIC_WRITE : 0), FS_R | FS_W | FS_D, OPEN_ALWAYS);
        if (h != INVALID) {
            char b[8];
            rd(e, h, b, 1);
            ch(e, h);
            old[i & 7] = h;
        }
        if ((i & 7) == 7) for (int k = 0; k < 8; k++) if (old[k]) { uint32_t x = ch(e, old[k]); (void)x; old[k] = 0; }   /* stale */
        if ((i % 11) == 0) dl(e, nm);
        if ((i % 13) == 0) { cpy(e, "s0", "s9", 0); }
    }
    return NULL;
}
/* C7: copy never reads a file that has an open writer: the copy is whole or refused */
static Gate g_c7;
#define C7_LEN 8192
static void *c7_writer(void *p) {
    Task *t = p;
    Eng *e = &g_eng[t->idx];
    static char a[C7_LEN], b[C7_LEN];
    memset(a, 'A', sizeof a); memset(b, 'B', sizeof b);
    int i = 0;
    while (!GATE_STOPPED(g_c7)) {
        uint32_t h = cf(e, "live", GENERIC_WRITE, FS_R | FS_W, CREATE_ALWAYS);
        if (h == INVALID) {   /* a copy in flight holds the source: a legitimate refusal */
            if (g_err != ERROR_SHARING_VIOLATION) { t->result = 1; break; }
            sched_yield();
            continue;
        }
        const char *c = (i++ & 1) ? a : b;
        for (uint32_t off = 0; off < C7_LEN; off += 2048) wr(e, h, c + off, 2048);
        ch(e, h);
        sched_yield();
    }
    return NULL;
}
static void *c7_copier(void *p) {
    Task *t = p;
    Eng *e = &g_eng[t->idx];
    while (!GATE_STOPPED(g_c7)) {
        char dst[32];
        snprintf(dst, sizeof dst, "copy%d", t->idx);
        uint32_t ok = cpy(e, "live", dst, 0);
        if (ok) {
            char buf[C7_LEN + 8];
            int n = slurp(dst, buf, sizeof buf);
            int uniform = n == C7_LEN;
            for (int i = 1; uniform && i < n; i++) uniform = buf[i] == buf[0];
            if (!uniform) t->result = 1;   /* a torn copy */
            t->wins++;
        } else if (g_err != ERROR_SHARING_VIOLATION && g_err != ERROR_FILE_NOT_FOUND) t->result = 2;
        sched_yield();
    }
    return NULL;
}

static void t_threads(void) {
    int live = live_handles();
    Barrier bar;
    Task tk[16];
    Eng *e0 = &g_eng[0];

    /* C1 */
    put("race", "R");
    barrier_init(&bar, NT);
    memset(tk, 0, sizeof tk);
    for (int i = 0; i < NT; i++) { tk[i].idx = i; tk[i].bar = &bar; tk[i].rounds = 300; }
    g_win_count = 0;
    run_threads(c1, tk, NT);
    for (int i = 0; i < NT; i++) CHECK(!tk[i].result);
    CHECK(g_win_count == 300);   /* exactly one winner per round */
    unlink(hp("race"));
    quiescent(live);

    /* C2 */
    put("keep", "KEEP");
    uint32_t reader = cf(e0, "keep", GENERIC_READ, FS_R, OPEN_EXISTING);
    CHECK(reader != INVALID);
    __atomic_store_n(&g_gate.stop, 0, __ATOMIC_RELEASE);
    memset(tk, 0, sizeof tk);
    pthread_t th[6];
    for (int i = 0; i < 6; i++) { tk[i].idx = i + 1; CHECK(!pthread_create(&th[i], NULL, c2_writer, &tk[i])); }
    for (int i = 0; i < 400; i++) {
        char b[8];
        (void)rd(e0, reader, b, 4);
        expect("keep", "KEEP");
        sched_yield();
    }
    GATE_STOP(g_gate);
    for (int i = 0; i < 6; i++) CHECK(!pthread_join(th[i], NULL));
    for (int i = 0; i < 6; i++) CHECK(tk[i].result == 0);
    expect("keep", "KEEP");
    CHECK(ch(e0, reader) == 1);
    unlink(hp("keep"));
    quiescent(live);

    /* C3 */
    barrier_init(&bar, NT + 1);
    memset(tk, 0, sizeof tk);
    for (int i = 0; i < NT; i++) { tk[i].idx = i + 1; tk[i].bar = &bar; tk[i].rounds = 100; }
    pthread_t t3[NT];
    for (int i = 0; i < NT; i++) CHECK(!pthread_create(&t3[i], NULL, c3, &tk[i]));
    for (int r = 0; r < 100; r++) {
        put("victim", "V");
        uint32_t h = cf(e0, "victim", GENERIC_READ, FS_R | FS_W | FS_D, OPEN_EXISTING);
        CHECK(h != INVALID);
        g_win_count = 0;
        barrier_wait(&bar);   /* deleters run */
        barrier_wait(&bar);
        CHECK(g_win_count == 1 && present("victim"));   /* pending, still there */
        CHECK(ch(e0, h) == 1);
        CHECK(!present("victim"));
        barrier_wait(&bar);
    }
    for (int i = 0; i < NT; i++) CHECK(!pthread_join(t3[i], NULL));
    for (int i = 0; i < NT; i++) CHECK(!tk[i].result);
    quiescent(live);

    /* C4 */
    barrier_init(&bar, NT + 1);
    memset(tk, 0, sizeof tk);
    for (int i = 0; i < NT; i++) { tk[i].idx = i + 1; tk[i].bar = &bar; tk[i].rounds = 200; }
    put("data", "D");
    pthread_t t4[NT];
    uint32_t cur = 0;
    for (int r = 0; r < 200; r++) {
        cur = cf(e0, "data", GENERIC_READ, 0, OPEN_EXISTING);
        CHECK(cur != INVALID);
        for (int i = 0; i < NT; i++) tk[i].shared_h = cur;
        if (r == 0) for (int i = 0; i < NT; i++) CHECK(!pthread_create(&t4[i], NULL, c4, &tk[i]));
        g_win_count = 0;
        barrier_wait(&bar);
        barrier_wait(&bar);
        CHECK(g_win_count == 1);
        /* the exclusive reservation is gone with the handle: the same open works at once */
        uint32_t again = cf(e0, "data", GENERIC_READ, 0, OPEN_EXISTING);
        CHECK(again != INVALID && ch(e0, again) == 1);
        barrier_wait(&bar);
    }
    for (int i = 0; i < NT; i++) CHECK(!pthread_join(t4[i], NULL));
    for (int i = 0; i < NT; i++) CHECK(!tk[i].result);
    unlink(hp("data"));
    quiescent(live);

    /* C5 */
    barrier_init(&bar, 8);
    memset(tk, 0, sizeof tk);
    for (int i = 0; i < 8; i++) { tk[i].idx = i; tk[i].bar = &bar; }
    run_threads(c5, tk, 8);
    CHECK(count_ci("", "newdir") == 1 && count_ci("", "par") <= 1);
    DIR *d = opendir(root);
    struct dirent *de;
    while ((de = readdir(d))) if (!strcasecmp(de->d_name, "par")) {
        char sub[300], inner[300];
        snprintf(sub, sizeof sub, "%s", de->d_name);
        DIR *dd = opendir(hp(sub));
        struct dirent *x;
        while (dd && (x = readdir(dd))) if (x->d_name[0] != '.') { snprintf(inner, sizeof inner, "%s/%s", sub, x->d_name); unlink(hp(inner)); }
        if (dd) closedir(dd);
        rmdir(hp(sub));
    }
    closedir(d);
    rmdir(hp("NewDir")); rmdir(hp("newdir")); rmdir(hp("NEWDIR")); rmdir(hp("nEwDiR"));
    quiescent(live);

    /* C6 */
    put("s0", "0"); put("S1", "1"); put("s2", "2"); put("s3", "3");
    memset(tk, 0, sizeof tk);
    for (int i = 0; i < NT; i++) { tk[i].idx = i; tk[i].rounds = 400; }
    run_threads(c6, tk, NT);
    for (int i = 0; i < NT; i++) CHECK(!tk[i].result);
    CHECK(res_used() == 0);
    {   /* delete may have removed a file, but no pending entry or handle may be left behind */
        const char *rm[] = { "s0", "S1", "s2", "s3", "s9" };
        for (size_t i = 0; i < 5; i++) unlink(hp(rm[i]));
    }
    quiescent(live);

    /* C7 */
    {   char init[C7_LEN + 1];
        memset(init, 'A', C7_LEN); init[C7_LEN] = 0;
        put("live", init);
    }
    __atomic_store_n(&g_c7.stop, 0, __ATOMIC_RELEASE);
    memset(tk, 0, sizeof tk);
    pthread_t t7[4];
    for (int i = 0; i < 4; i++) { tk[i].idx = i + 1; CHECK(!pthread_create(&t7[i], NULL, i == 0 ? c7_writer : c7_copier, &tk[i])); }
    for (int i = 0; i < 300; i++) sched_yield();
    usleep(200000);
    GATE_STOP(g_c7);
    for (int i = 0; i < 4; i++) CHECK(!pthread_join(t7[i], NULL));
    CHECK(!tk[0].result);
    for (int i = 1; i < 4; i++) CHECK(!tk[i].result);
    unlink(hp("live"));
    for (int i = 2; i <= 4; i++) { char n[16]; snprintf(n, sizeof n, "copy%d", i); unlink(hp(n)); }
    quiescent(live);
    puts("F3.2 concurrency (strict): PASS");
}

/* ------------------------------------------------------------------------------------------ */
/* K2: name forms strict refuses, UTF-8 case folding, differently cased non-ASCII spellings    */
/* ------------------------------------------------------------------------------------------ */
#define YO_U "\xD0\x81"          /* U+0401 Ё */
#define YO_L "\xD1\x91"          /* U+0451 ё */
#define OKS_A "\xD0\x9E\xD0\xBA\xD1\x81\xD0\xB1\xD0\xB0\xD0\xB9"   /* "Оксбай" */
#define OKS_B "\xD0\x9E\xD0\x9A\xD0\xA1\xD0\x91\xD0\x90\xD0\x99"   /* "ОКСБАЙ" */
#define OKS_C "\xD0\xBE\xD0\xBA\xD1\x81\xD0\xB1\xD0\xB0\xD0\xB9"   /* "оксбай" */
static int g_case_sensitive;
static void expect_refused(Eng *e, const char *name, uint32_t err) {
    int live = live_handles();
    int before = res_used();
    uint32_t h = cf(e, name, GENERIC_WRITE, FS_R | FS_W | FS_D, CREATE_ALWAYS);
    if (h != INVALID || g_err != err) fprintf(stderr, "refusal of '%s': h=%x err=%u (want %u)\n", name, h, g_err, err);
    CHECK(h == INVALID && g_err == err);
    h = cf(e, name, GENERIC_READ, FS_R, OPEN_EXISTING);
    CHECK(h == INVALID && g_err == err);
    CHECK(dl(e, name) == 0 && g_err == err);
    CHECK(mkd(e, name) == 0 && g_err == err);
    CHECK(rmd(e, name) == 0 && g_err == err);
    CHECK(cpy(e, name, "k2-copy-dst", 0) == 0 && g_err == err);
    CHECK(cpy(e, "k2-ok", name, 0) == 0 && g_err == err);
    if (MOVE_OK) {
        CHECK(mv(e, name, "k2-moved") == 0 && g_err == err);
        CHECK(mv(e, "k2-ok", name) == 0 && g_err == err);
    }
    CHECK(!present("k2-copy-dst") && !present("k2-moved"));
    CHECK(res_used() == before && live_handles() == live);
}
static void *c8(void *p) {   /* racing spellings of one Cyrillic name: one host file, one open at a time */
    Task *t = p;
    Eng *e = &g_eng[t->idx];
    static const char *names[] = { OKS_A, OKS_B, OKS_C, OKS_A };
    barrier_wait(t->bar);
    for (int r = 0; r < t->rounds; r++) {
        uint32_t h = cf(e, names[(t->idx + r) & 3], GENERIC_WRITE, 0, CREATE_ALWAYS);
        if (h == INVALID) { if (g_err != ERROR_SHARING_VIOLATION) t->result = 1; }
        else {
            char tag[2] = { (char)('A' + t->idx), 0 }, back[4];
            wr(e, h, tag, 1);
            sched_yield();
            if (ch(e, h) != 1) t->result = 2;
            else t->wins++;
            (void)back;
        }
    }
    return NULL;
}
static void t_names(void) {
    Eng *e = &g_eng[0];
    int live = live_handles();
    put("k2-ok", "OK");
    /* the ASCII fixture must be unaffected by the policy */
    uint32_t okh = cf(e, "k2-ok", GENERIC_READ, FS_R, OPEN_EXISTING);
    CHECK(okh != INVALID && ch(e, okh) == 1);

    /* --- refused forms: UNC / device / NT prefixes ------------------------------------------------ */
    static const char *prefixes[] = { "\\\\server\\share\\x", "//server/share/x", "\\\\?\\C:\\Games\\Korsary2\\k2-ok",
        "\\\\.\\C:\\k2-ok", "\\\\?\\UNC\\server\\share\\x", "\\??\\C:\\Games\\Korsary2\\k2-ok", "\\??\\", "\\\\", "//?/C:/k2-ok", NULL };
    for (int i = 0; prefixes[i]; i++) expect_refused(e, prefixes[i], ERROR_INVALID_NAME);
    /* --- drive-relative names --------------------------------------------------------------------- */
    static const char *drives[] = { "C:k2-ok", "c:k2-ok", "D:", "C:..\\k2-ok", NULL };
    for (int i = 0; drives[i]; i++) expect_refused(e, drives[i], ERROR_INVALID_NAME);
    /* --- NTFS streams ----------------------------------------------------------------------------- */
    static const char *streams[] = { "k2-ok:stream", "k2-ok::$DATA", "k2-ok:s:$DATA", "sub:x\\file", "C:\\Games\\Korsary2\\k2-ok:s",
        "k2-ok:", ":s", ".\\k2-ok:Zone.Identifier", NULL };
    for (int i = 0; streams[i]; i++) expect_refused(e, streams[i], ERROR_INVALID_NAME);
    /* --- trailing dot/space in a parent component ------------------------------------------------- */
    static const char *parents[] = { "dir.\\file", "dir \\file", "dir. .\\file", "a\\dir.\\b\\file", "C:\\Games\\Korsary2\\dir.\\file",
        "dir..\\file", NULL };
    for (int i = 0; parents[i]; i++) expect_refused(e, parents[i], ERROR_INVALID_NAME);
    CHECK(!present("dir.") && !present("dir ") && !present("dir. ."));
    /* the final component: a trailing dot/space that names an EXISTING file without it is refused (nothing may be
       created or truncated), one that names nothing is an ordinary literal name */
    put("k2-final", "FINAL");
    {
        static const char *fin[] = { "k2-final.", "k2-final ", "k2-final..", "K2-FINAL. ", NULL };
        for (int i = 0; fin[i]; i++) {
            uint32_t h = cf(e, fin[i], GENERIC_WRITE, FS_R | FS_W | FS_D, CREATE_ALWAYS);
            if (h != INVALID || g_err != ERROR_SHARING_VIOLATION) fprintf(stderr, "final '%s': h=%x err=%u\n", fin[i], h, g_err);
            CHECK(h == INVALID && g_err == ERROR_SHARING_VIOLATION);
            CHECK(dl(e, fin[i]) == 0 && g_err == ERROR_SHARING_VIOLATION);
        }
        expect("k2-final", "FINAL");
        CHECK(!present("k2-final.") && !present("k2-final ") && !present("k2-final.."));
        uint32_t h = cf(e, "k2-fresh.", GENERIC_WRITE, FS_R | FS_W | FS_D, CREATE_ALWAYS);
        CHECK(h != INVALID && ch(e, h) == 1);
        unlink(hp("k2-fresh.")); unlink(hp("k2-final"));
    }
    /* a parent that is made absolute by ".." is no parent any more, and an inner dot is ordinary */
    {
        uint32_t h = cf(e, "dir.\\..\\k2-ok", GENERIC_READ, FS_R, OPEN_EXISTING);
        CHECK(h != INVALID && ch(e, h) == 1);
        h = cf(e, "a.b\\..\\k2-ok", GENERIC_READ, FS_R, OPEN_EXISTING);
        CHECK(h != INVALID && ch(e, h) == 1);
    }
    /* --- bytes that are not UTF-8 (CP1251 names, overlong, surrogate, out of range, truncated) ------ */
    static const char *bad[] = { "\xD2\xE5\xF1\xF2", "pre\\\xD2\xE5\xF1\xF2\\x", "k2\xE9", "\xC0\x80", "\xED\xA0\x80", "\xF4\x90\x80\x80",
        "\xD0", "\xE0\x80\x80", "\xF8\x88\x80\x80\x80", "name\xA8", "\xA8\xE6", "\xB8\xE6", NULL };
    for (int i = 0; bad[i]; i++) expect_refused(e, bad[i], ERROR_INVALID_NAME);

    /* --- not refused, not recognized: 8.3 look-alikes are ordinary literal names ------------------- */
    {
        uint32_t a = cf(e, "PROGRA~1", GENERIC_WRITE, 0, CREATE_ALWAYS);
        uint32_t b = cf(e, "Program Files", GENERIC_WRITE, 0, CREATE_ALWAYS);   /* a different file for the host (and for the guest, as the port hands out no short names) */
        CHECK(a != INVALID && b != INVALID);
        CHECK(cf(e, "progra~1", GENERIC_WRITE, 0, OPEN_EXISTING) == INVALID && g_err == ERROR_SHARING_VIOLATION);   /* the plain case alias still works */
        CHECK(ch(e, a) == 1 && ch(e, b) == 1);
        CHECK(present("PROGRA~1") && present("Program Files"));
        unlink(hp("PROGRA~1")); unlink(hp("Program Files"));
        uint32_t t = cf(e, "~tmp1.dat", GENERIC_WRITE, FS_R | FS_W | FS_D, CREATE_ALWAYS);
        CHECK(t != INVALID && ch(e, t) == 1);
        unlink(hp("~tmp1.dat"));
    }
    /* well-formed UTF-8 (2-, 3- and 4-byte) and spaces inside names are fine */
    {
        static const char *ok[] = { "k2 spaced name", "k2\xC3\xA9", "k2\xE2\x82\xAC", "k2\xF0\x9F\x8E\xB2", "a.b.c", "k2" OKS_A, NULL };
        for (int i = 0; ok[i]; i++) {
            uint32_t h = cf(e, ok[i], GENERIC_WRITE, FS_R | FS_W | FS_D, CREATE_ALWAYS);
            if (h == INVALID) fprintf(stderr, "ok name '%s' refused: %u\n", ok[i], g_err);
            CHECK(h != INVALID && ch(e, h) == 1);
            unlink(hp(ok[i]));
        }
    }

    /* --- UTF-8 case folding in the registry ---------------------------------------------------------- */
    {
        static const char *fam[][2] = { { OKS_A, OKS_B }, { OKS_C, OKS_A }, { "k2\xC3\x84", "k2\xC3\xA4" }, { YO_U, YO_L },
            { "k2\xCE\x91", "k2\xCE\xB1" } /* Greek Alpha/alpha */, { "k2\xC5\x9E", "k2\xC5\x9F" } /* Ş/ş */, { NULL, NULL } };
        for (int i = 0; fam[i][0]; i++) {
            uint32_t h = cf(e, fam[i][0], GENERIC_WRITE, 0, CREATE_ALWAYS);
            CHECK(h != INVALID);
            /* the other spelling is the same Windows object: a sharing violation whatever it asks for,
               and it must not create a second host file */
            uint32_t x = cf(e, fam[i][1], GENERIC_WRITE, FS_R | FS_W | FS_D, CREATE_ALWAYS);
            if (x != INVALID || g_err != ERROR_SHARING_VIOLATION) fprintf(stderr, "fold family %d: h=%x err=%u\n", i, x, g_err);
            CHECK(x == INVALID && g_err == ERROR_SHARING_VIOLATION);
            CHECK(dl(e, fam[i][1]) == 0 && g_err == ERROR_SHARING_VIOLATION);
            CHECK(mkd(e, fam[i][1]) == 0);
            CHECK(ch(e, h) == 1);
            if (g_case_sensitive) CHECK(!present(fam[i][1]));
            unlink(hp(fam[i][0])); unlink(hp(fam[i][1]));
            quiescent(live);
        }
        /* different letters are not aliases: Ш and и share the CP1251 byte pair 0xA8/0xB8 in their UTF-8 */
        uint32_t s1 = cf(e, "k2\xD0\xA8", GENERIC_WRITE, 0, CREATE_ALWAYS);   /* Ш */
        uint32_t s2 = cf(e, "k2\xD0\xB8", GENERIC_WRITE, 0, CREATE_ALWAYS);   /* и */
        CHECK(s1 != INVALID && s2 != INVALID);
        CHECK(ch(e, s1) == 1 && ch(e, s2) == 1);
        unlink(hp("k2\xD0\xA8")); unlink(hp("k2\xD0\xB8"));
        quiescent(live);
    }
    /* --- an existing file under one case, opened under another (nothing registered) -------------------- */
    if (g_case_sensitive) {
        put(OKS_A, "ORIG");
        uint32_t h = cf(e, OKS_B, GENERIC_WRITE, FS_R | FS_W | FS_D, CREATE_ALWAYS);   /* would create a second file and truncate nothing */
        CHECK(h == INVALID && g_err == ERROR_SHARING_VIOLATION);
        CHECK(!present(OKS_B) && !present(OKS_C));
        expect(OKS_A, "ORIG");
        CHECK(dl(e, OKS_C) == 0 && g_err == ERROR_SHARING_VIOLATION);
        CHECK(cpy(e, OKS_A, OKS_B, 0) == 0 && g_err == ERROR_SHARING_VIOLATION && !present(OKS_B));
        CHECK(cpy(e, OKS_B, "k2-dst", 0) == 0 && !present("k2-dst"));
        /* the exact spelling keeps working, and so does a directory component */
        h = cf(e, OKS_A, GENERIC_READ, FS_R, OPEN_EXISTING);
        CHECK(h != INVALID && ch(e, h) == 1);
        CHECK(mkd(e, YO_U) == 1);
        CHECK(cf(e, YO_L "\\f", GENERIC_WRITE, 0, CREATE_ALWAYS) == INVALID && g_err == ERROR_SHARING_VIOLATION);
        CHECK(rmd(e, YO_U) == 1);
        unlink(hp(OKS_A));
        /* an absent name may be created under its first spelling only */
        h = cf(e, OKS_B, GENERIC_WRITE, FS_R | FS_W | FS_D, CREATE_ALWAYS);
        CHECK(h != INVALID && ch(e, h) == 1);
        CHECK(cf(e, OKS_A, GENERIC_WRITE, FS_R | FS_W | FS_D, CREATE_ALWAYS) == INVALID && g_err == ERROR_SHARING_VIOLATION);
        CHECK(present(OKS_B) && !present(OKS_A));
        unlink(hp(OKS_B));
        quiescent(live);
    } else puts("K2 differently cased non-ASCII spelling of an unregistered file: SKIPPED (case-insensitive host: the host itself unifies the spellings)");
    unlink(hp("k2-ok"));
    quiescent(live);
    puts("K2 name policy and UTF-8 folding (strict): PASS");
}
static void t_names_unit(void) {
    /* share_fold_cp: the documented ranges, spot checks that do not depend on the host */
    CHECK(share_fold_cp('A') == 'a' && share_fold_cp('z') == 'z' && share_fold_cp('0') == '0' && share_fold_cp('_') == '_');
    for (uint32_t c = 0x410; c <= 0x42F; c++) CHECK(share_fold_cp(c) == c + 32 && share_fold_cp(c + 32) == c + 32);   /* А-Я -> а-я */
    for (uint32_t c = 0x400; c <= 0x40F; c++) CHECK(share_fold_cp(c) == c + 80);                                     /* Ѐ-Џ */
    CHECK(share_fold_cp(0x401) == 0x451);                                    /* Ё -> ё */
    CHECK(share_fold_cp(0xC4) == 0xE4 && share_fold_cp(0xD7) == 0xD7 && share_fold_cp(0xDF) == 0xDF && share_fold_cp(0xB5) == 0xB5);
    CHECK(share_fold_cp(0x130) == 0x130 && share_fold_cp(0x131) == 0x131);   /* Turkish i is left alone */
    CHECK(share_fold_cp(0x178) == 0xFF && share_fold_cp(0x17D) == 0x17E);
    CHECK(share_fold_cp(0x3A3) == 0x3C3 && share_fold_cp(0x3C2) == 0x3C3 && share_fold_cp(0x386) == 0x3AC);
    CHECK(share_fold_cp(0x10D0) == 0x10D0 && share_fold_cp(0x1F600) == 0x1F600);   /* not covered: identity */
    /* every mapping is idempotent, never changes the UTF-8 length, and every result is a valid scalar */
    for (uint32_t c = 0; c <= 0x10FFFF; c++) {
        if (c >= 0xD800 && c <= 0xDFFF) continue;
        uint32_t f = share_fold_cp(c);
        CHECK(share_fold_cp(f) == f);
        int lc = c < 0x80 ? 1 : c < 0x800 ? 2 : c < 0x10000 ? 3 : 4, lf = f < 0x80 ? 1 : f < 0x800 ? 2 : f < 0x10000 ? 3 : 4;
        CHECK(lc == lf && !(f >= 0xD800 && f <= 0xDFFF) && f <= 0x10FFFF);
    }
    /* UTF-8 validation, including what a lenient decoder would accept */
    uint32_t cp;
    CHECK(share_utf8_len((const unsigned char *)"\xC2\x80", &cp) == 2 && cp == 0x80);
    CHECK(share_utf8_len((const unsigned char *)"\xDF\xBF", &cp) == 2 && cp == 0x7FF);
    CHECK(share_utf8_len((const unsigned char *)"\xE0\xA0\x80", &cp) == 3 && cp == 0x800);
    CHECK(share_utf8_len((const unsigned char *)"\xEF\xBF\xBF", &cp) == 3 && cp == 0xFFFF);
    CHECK(share_utf8_len((const unsigned char *)"\xF0\x90\x80\x80", &cp) == 4 && cp == 0x10000);
    CHECK(share_utf8_len((const unsigned char *)"\xF4\x8F\xBF\xBF", &cp) == 4 && cp == 0x10FFFF);
    static const char *invalid[] = { "\x80", "\xBF", "\xC0\x80", "\xC1\xBF", "\xC2", "\xC2\x41", "\xE0\x9F\xBF", "\xED\xA0\x80", "\xED\xBF\xBF",
        "\xF0\x8F\xBF\xBF", "\xF4\x90\x80\x80", "\xF5\x80\x80\x80", "\xF8\x80\x80\x80\x80", "\xFF", "\xFE", NULL };
    for (int i = 0; invalid[i]; i++) CHECK(share_utf8_len((const unsigned char *)invalid[i], &cp) == 0);
    /* share_fold on strings, ASCII and bytes that are not UTF-8 pass through byte-wise */
    char o[64];
    share_fold("/Data/" OKS_B, o, sizeof o);
    CHECK(!strcmp(o, "/data/" OKS_C));
    share_fold("/\xD2\xE5\xF1\xF2/ABC", o, sizeof o);
    CHECK(!strcmp(o, "/\xD2\xE5\xF1\xF2/abc"));
    /* relation of two registry names: same fold, different bytes = the refused spelling conflict (2) */
    ShareName a, b;
    char pa[1200], pb[1200];
    snprintf(pa, sizeof pa, "%s/%s", root, OKS_A); snprintf(pb, sizeof pb, "%s/%s", root, OKS_B);
    CHECK(share_name_make(pa, &a) && share_name_make(pb, &b));
    CHECK(share_relation(&a, &b) == 2 || share_relation(&a, &b) == 1);   /* 1 only through a shared inode of a case-insensitive host */
    CHECK(share_relation(&a, &a) == 1);
    snprintf(pb, sizeof pb, "%s/%s/x", root, OKS_B);
    CHECK(share_name_make(pb, &b) && share_relation(&a, &b) == 2 && share_is_under(&a, &b));   /* a file below the other spelling of a directory: refused, and "under" it */
    snprintf(pa, sizeof pa, "%s/%s/y", root, OKS_C);
    CHECK(share_name_make(pa, &a) && share_relation(&a, &b) == 2);      /* shared parent spelled two ways */
    puts("K2 fold and UTF-8 validation units: PASS");
}
static void t_names_threads(void) {
    int live = live_handles();
    Barrier bar;
    Task tk[16];
    barrier_init(&bar, NT);
    memset(tk, 0, sizeof tk);
    for (int i = 0; i < NT; i++) { tk[i].idx = i; tk[i].bar = &bar; tk[i].rounds = 200; }
    run_threads(c8, tk, NT);
    int wins = 0;
    for (int i = 0; i < NT; i++) { CHECK(!tk[i].result); wins += tk[i].wins; }
    CHECK(wins > 0);
    /* however the spellings raced, the host holds ONE entry for the name */
    DIR *d = opendir(root);
    CHECK(d);
    int entries = 0;
    struct dirent *de;
    while ((de = readdir(d))) if (!strcmp(de->d_name, OKS_A) || !strcmp(de->d_name, OKS_B) || !strcmp(de->d_name, OKS_C)) entries++;
    closedir(d);
    CHECK(entries == 1);
    unlink(hp(OKS_A)); unlink(hp(OKS_B)); unlink(hp(OKS_C));
    quiescent(live);
    puts("K2 racing spellings of a non-ASCII name (strict): PASS");
}

static void ensure_empty(void) {
    DIR *d = opendir(root);
    CHECK(d);
    struct dirent *de;
    while ((de = readdir(d))) CHECK(!strcmp(de->d_name, ".") || !strcmp(de->d_name, ".."));
    closedir(d);
}

int main(int argc, char **argv) {
    if (argc > 2) {
        if (!strcmp(argv[2], "unset")) unsetenv("PORT_STRICT_FILE_SHARE");
        else CHECK(!setenv("PORT_STRICT_FILE_SHARE", !strcmp(argv[2], "empty") ? "" : argv[2], 1));
    }
    const char *v = getenv("PORT_STRICT_FILE_SHARE");
    strict = v && *v && strcmp(v, "0") != 0;
    use_threads = !getenv("SHARE_NO_THREADS");
    CHECK(strict_share() == strict);   /* the env contract: unset, "" and "0" are permissive */
    CHECK(!setenv("PORT_FILE_SNAPSHOT", "0", 1));
    g_mem = calloc(1, 0x100000);
    CHECK(g_mem);
    for (int i = 0; i < 16; i++) eng_init(&g_eng[i], i);
    /* first-use initializers that are not thread-safe by themselves in kernel32.c/core.c */
    (void)snapshot_enabled(); (void)snapshot_max(); (void)host_seconds();
    snprintf(root, sizeof root, "%s/korsary-f32-XXXXXX", argc > 1 ? argv[1] : "/tmp");
    CHECK(mkdtemp(root));
    snprintf(g_game_root, sizeof g_game_root, "%s", root);
    /* the registry must start empty; a handle value of the default mode is the lowest free slot */
    CHECK(res_used() == 0 && pend_used() == 0);

    if (!strict) {
        t_default();
    } else {
        t_aliases();
        t_delete_pending();
        t_exhaustion();
        t_close();
        t_dirs();
        t_inflight();
        t_copy();
        {   /* is the host case-sensitive? (WasmFS yes, APFS/HFS+ default no) */
            put("K2-CASE-PROBE", "x");
            g_case_sensitive = !present("k2-case-probe");
            unlink(hp("K2-CASE-PROBE"));
        }
        t_names_unit();
        t_names();
#if SAVE_META_ON && defined(PORT_SAVE_TX)
        t_save_compat();
#endif
        if (use_threads) { t_threads(); t_names_threads(); } else puts("F3.2 concurrency (strict): SKIPPED (SHARE_NO_THREADS)");
    }
    /* clean up what the tests left (their own fixtures only) */
    DIR *d = opendir(root);
    struct dirent *de;
    while (d && (de = readdir(d))) {
        if (!strcmp(de->d_name, ".") || !strcmp(de->d_name, "..")) continue;
        char p[1200];
        snprintf(p, sizeof p, "%s/%s", root, de->d_name);
        struct stat st;
        if (lstat(p, &st) == 0 && S_ISDIR(st.st_mode)) {
            DIR *dd = opendir(p);
            struct dirent *x;
            while (dd && (x = readdir(dd))) {
                if (!strcmp(x->d_name, ".") || !strcmp(x->d_name, "..")) continue;
                char q[1500];
                snprintf(q, sizeof q, "%s/%s", p, x->d_name);
                unlink(q);
            }
            if (dd) closedir(dd);
            rmdir(p);
        } else unlink(p);
    }
    if (d) closedir(d);
    ensure_empty();
    rmdir(root);
    free(g_mem);
    return 0;
}
