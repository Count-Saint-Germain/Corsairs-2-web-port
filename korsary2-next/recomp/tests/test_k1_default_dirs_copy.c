/* K1: CreateDirectoryA / RemoveDirectoryA / CopyFileA in the DEFAULT mode (PORT_STRICT_FILE_SHARE unset)
   on the REAL kernel32.c handlers, over synthetic temp directories only. Not a check of the running game.

   Background (K1_COPYFILE_AUDIT.md): static analysis of ENGINE.exe and every MODULES/*.dll found ONE
   live caller of the three imports: XINTERFACE.dll 0x10033716 calls fio->_CreateDirectory(SavePath,
   NULL) with the interface attribute GameInterface.SavePath = "SAVE" each time the save list is
   built, ignoring the result, and then enumerates "SAVE\*". Nothing reaches CopyFileA or
   RemoveDirectoryA. Therefore the default path is NOT changed; this test pins it so that any later
   change is a deliberate one:
     * the one real use: CreateDirectoryA("SAVE") on an existing / absent directory, repeated, in all
       spellings, with and without SAVE_TX / SAVE_META (-DPORT_SAVE_META=1 -DPORT_SAVE_TX=1);
     * RemoveDirectoryA semantics (empty / non-empty / absent / file / case);
     * CopyFileA characterization: existing destination (overwritten, failIfExists), large file, absent
       source; the KNOWN GAPS of the default path (absent destination -> FALSE, unchecked write errors,
       copy onto itself) are only reported ("KNOWN-GAP ..." lines), never asserted, because nobody
       calls it and they must not be cemented as a contract.
   Usage: test [scratch-dir]   (default /tmp). Run by run_k1_dir_copy.sh (native, savetx, wasm, node). */
#include <assert.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <unistd.h>
#include "../host/core.c"
#include "../host/kernel32.c"
uint8_t *g_mem;

#define CHECK(c) do { if (!(c)) { fprintf(stderr, "FAIL %s:%d: %s\n", __FILE__, __LINE__, #c); abort(); } } while (0)
#define GENERIC_READ 0x80000000u
#define GENERIC_WRITE 0x40000000u
#define FS_R 1
#define FS_W 2
#define INVALID 0xffffffffu
#define CREATE_ALWAYS 2
#define OPEN_EXISTING 3
#define NOERR 0xdeadu   /* sentinel the call() helper stores into LastError before every call */

static char root[1024];

typedef struct { CPU c; GuestThread th; uint32_t base; } Eng;
static Eng g_e;
static uint32_t g_err;   /* LastError after the latest call; NOERR = the handler did not touch it */
static uint32_t call(void (*fn)(CPU *), int n, const uint32_t *a) {
    t_self = &g_e.th;
    g_e.th.last_error = NOERR;
    g_e.c.esp = g_e.base + 0x100;
    W32(g_e.c.esp, 0);
    for (int i = 0; i < n; i++) W32(g_e.c.esp + 4 + 4u * (uint32_t)i, a[i]);
    fn(&g_e.c);
    g_err = g_e.th.last_error;
    return g_e.c.eax;
}
static uint32_t gstr(int k, const char *s) {
    uint32_t at = g_e.base + 0x400u + (uint32_t)k * 0x1000u;
    CHECK(strlen(s) < 0xff0);
    strcpy((char *)HP(at), s);
    return at;
}
static uint32_t cf(const char *name, uint32_t access, uint32_t share, uint32_t disp) {
    uint32_t a[7] = { gstr(0, name), access, share, 0, disp, 0, 0 };
    return call(w_CreateFileA, 7, a);
}
static uint32_t ch(uint32_t h) { uint32_t a[1] = { h }; return call(w_CloseHandle, 1, a); }
static uint32_t mkd(const char *n) { uint32_t a[2] = { gstr(0, n), 0 }; return call(w_CreateDirectoryA, 2, a); }
static uint32_t rmd(const char *n) { uint32_t a[1] = { gstr(0, n) }; return call(w_RemoveDirectoryA, 1, a); }
static uint32_t cpy(const char *s, const char *d, uint32_t fail_if_exists) {
    uint32_t a[3] = { gstr(0, s), gstr(1, d), fail_if_exists };
    return call(w_CopyFileA, 3, a);
}
static uint32_t rd(uint32_t h, void *buf, uint32_t n) {
    uint32_t out = g_e.base + 0x200u, data = g_e.base + 0x3000u;
    uint32_t a[5] = { h, data, n, out, 0 };
    if (!call(w_ReadFile, 5, a)) return INVALID;
    uint32_t got = R32(out);
    memcpy(buf, HP(data), got);
    return got;
}

static char *hp(const char *name) {
    static char b[4][1200];
    static int i;
    char *r = b[i++ & 3];
    snprintf(r, 1200, "%s/%s", root, name);
    return r;
}
static void put(const char *name, const char *content) {
    FILE *f = fopen(hp(name), "wb");
    CHECK(f && fputs(content, f) >= 0 && !fclose(f));
}
static int present(const char *name) { struct stat st; return stat(hp(name), &st) == 0; }
static int isdir(const char *name) { struct stat st; return stat(hp(name), &st) == 0 && S_ISDIR(st.st_mode); }
static int slurp(const char *name, char *out, size_t n) {   /* -1 absent */
    FILE *f = fopen(hp(name), "rb");
    if (!f) return -1;
    size_t got = fread(out, 1, n - 1, f);
    fclose(f);
    out[got] = 0;
    return (int)got;
}
static void expect(const char *name, const char *content) {
    char b[8192];
    int n = slurp(name, b, sizeof b);
    if (n < 0 || strcmp(b, content)) fprintf(stderr, "expect(%s): got %d bytes '%.40s' wanted '%.40s'\n", name, n, n < 0 ? "<absent>" : b, content);
    CHECK(n >= 0 && !strcmp(b, content));
}
static long fsize(const char *name) { struct stat st; return stat(hp(name), &st) == 0 ? (long)st.st_size : -1; }
static int count_ci(const char *name) {   /* root entries equal to name ignoring case */
    DIR *d = opendir(root);
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
static void quiescent(int live_before) {   /* nothing the calls did may hold a handle or a share reservation */
    CHECK(res_used() == 0);
    CHECK(pend_used() == 0);
    CHECK(live_handles() == live_before);
}
static void rm_rf(const char *abs) {
    struct stat st;
    if (lstat(abs, &st) != 0) return;
    if (S_ISDIR(st.st_mode)) {
        chmod(abs, 0755);
        DIR *d = opendir(abs);
        struct dirent *e;
        while (d && (e = readdir(d))) {
            if (!strcmp(e->d_name, ".") || !strcmp(e->d_name, "..")) continue;
            char q[1500];
            snprintf(q, sizeof q, "%s/%s", abs, e->d_name);
            rm_rf(q);
        }
        if (d) closedir(d);
        rmdir(abs);
    } else {
        chmod(abs, 0644);
        unlink(abs);
    }
}
static void clean_root(void) {
    DIR *d = opendir(root);
    struct dirent *e;
    while (d && (e = readdir(d))) {
        if (!strcmp(e->d_name, ".") || !strcmp(e->d_name, "..")) continue;
        char q[1500];
        snprintf(q, sizeof q, "%s/%s", root, e->d_name);
        rm_rf(q);
    }
    if (d) closedir(d);
}
static int running_as_root(void) { return geteuid() == 0; }

/* ------------------------------------------------------------------------------------------ */
/* the one live caller: CreateDirectoryA("SAVE") while the engine builds the save list         */
/* ------------------------------------------------------------------------------------------ */
static void t_savepath(void) {
    int live = live_handles();
    /* fresh install: no SAVE yet -> the call creates it and the later FindFirstFile("SAVE\*") finds nothing */
    CHECK(!present("SAVE"));
    CHECK(mkd("SAVE") == 1 && isdir("SAVE"));
    /* the next menu opens: it exists now -> FALSE + ERROR_ALREADY_EXISTS, which the engine ignores */
    for (int i = 0; i < 300; i++) {
        CHECK(mkd("SAVE") == 0 && g_err == ERROR_ALREADY_EXISTS);
        if (i % 7 == 0) CHECK(mkd("SAVE\\") == 0 && g_err == ERROR_ALREADY_EXISTS);
    }
    /* every spelling resolves to the one real directory (case-insensitive existing component) */
    CHECK(mkd("save") == 0 && g_err == ERROR_ALREADY_EXISTS);
    CHECK(mkd("Save\\") == 0 && g_err == ERROR_ALREADY_EXISTS);
    CHECK(mkd(".\\SAVE") == 0 && g_err == ERROR_ALREADY_EXISTS);
    CHECK(count_ci("save") == 1);
    /* with slots in it nothing is touched */
    put("SAVE/slot1", "SLOT-ONE");
    put("SAVE/slot2", "SLOT-TWO");
    for (int i = 0; i < 50; i++) CHECK(mkd("SAVE") == 0 && g_err == ERROR_ALREADY_EXISTS);
    expect("SAVE/slot1", "SLOT-ONE");
    expect("SAVE/slot2", "SLOT-TWO");
    /* and the slots still read through the guest file API */
    uint32_t h = cf("SAVE\\slot1", GENERIC_READ, FS_R, OPEN_EXISTING);
    CHECK(h != INVALID);
    char b[16] = { 0 };
    CHECK(rd(h, b, 15) == 8 && !memcmp(b, "SLOT-ONE", 8));
    CHECK(ch(h) == 1);
    /* a profile sub-directory below an existing SAVE is created, a second call reports it exists */
    CHECK(mkd("SAVE\\Captain") == 1 && isdir("SAVE/Captain"));
    CHECK(mkd("SAVE\\Captain") == 0 && g_err == ERROR_ALREADY_EXISTS);
    CHECK(mkd("SAVE\\captain") == 0 && g_err == ERROR_ALREADY_EXISTS && count_ci("SAVE") == 1);
    /* a FILE named SAVE (damaged tree): FALSE + ERROR_ALREADY_EXISTS, the file survives */
    rm_rf(hp("SAVE"));
    put("SAVE", "I-AM-A-FILE");
    CHECK(mkd("SAVE") == 0 && g_err == ERROR_ALREADY_EXISTS);
    expect("SAVE", "I-AM-A-FILE");
    rm_rf(hp("SAVE"));
    /* an absent parent: FALSE, nothing created (the engine then simply lists nothing) */
    CHECK(mkd("NOSUCH\\Captain") == 0 && !present("NOSUCH"));
    /* a read-only parent cannot take a new directory (skipped as root: root ignores the mode bits) */
    if (!running_as_root()) {
        CHECK(!mkdir(hp("ro"), 0755));
        CHECK(!chmod(hp("ro"), 0555));
        CHECK(mkd("ro\\SAVE") == 0 && !present("ro/SAVE"));
        CHECK(!chmod(hp("ro"), 0755));
        rm_rf(hp("ro"));
    }
    /* the full cycle runs again from scratch: create, list x N, remove */
    for (int round = 0; round < 3; round++) {
        CHECK(mkd("SAVE") == 1);
        CHECK(mkd("SAVE") == 0 && g_err == ERROR_ALREADY_EXISTS);
        CHECK(rmd("SAVE") == 1 && !present("SAVE"));
    }
    quiescent(live);
    puts("K1 CreateDirectoryA(\"SAVE\") default contract: PASS");
}

/* ------------------------------------------------------------------------------------------ */
/* RemoveDirectoryA (no caller found; semantics pinned)                                          */
/* ------------------------------------------------------------------------------------------ */
static void t_rmdir(void) {
    int live = live_handles();
    CHECK(mkd("Dir") == 1);
    CHECK(rmd("dir") == 1 && !present("Dir"));                       /* empty, another spelling */
    CHECK(rmd("Dir") == 0 && !present("Dir"));                       /* absent */
    CHECK(mkd("Dir") == 1);
    put("Dir/f", "F");
    CHECK(rmd("Dir") == 0 && present("Dir/f") && isdir("Dir"));      /* non-empty stays */
    CHECK(rmd("Dir\\f") == 0 && present("Dir/f"));                   /* a file is not a directory */
    CHECK(rmd("NOSUCH\\x") == 0);
    CHECK(unlink(hp("Dir/f")) == 0 && rmd("DIR\\") == 1 && !present("Dir"));
    /* SAVE with slots is never removed by it */
    CHECK(mkd("SAVE") == 1);
    put("SAVE/slot1", "KEEP");
    CHECK(rmd("SAVE") == 0);
    expect("SAVE/slot1", "KEEP");
    rm_rf(hp("SAVE"));
    quiescent(live);
    puts("K1 RemoveDirectoryA default contract: PASS");
}

/* ------------------------------------------------------------------------------------------ */
/* CopyFileA (no caller found; existing-destination behavior pinned, gaps only reported)         */
/* ------------------------------------------------------------------------------------------ */
static void fill(unsigned char *p, size_t n, unsigned seed) {   /* deterministic, incompressible-ish */
    uint32_t x = seed * 2654435761u + 1;
    for (size_t i = 0; i < n; i++) { x = x * 1664525u + 1013904223u; p[i] = (unsigned char)(x >> 24); }
}
static void write_bin(const char *name, const unsigned char *p, size_t n) {
    FILE *f = fopen(hp(name), "wb");
    CHECK(f && fwrite(p, 1, n, f) == n && !fclose(f));
}
static int same_bin(const char *name, const unsigned char *p, size_t n) {
    FILE *f = fopen(hp(name), "rb");
    if (!f) return 0;
    unsigned char *q = malloc(n + 1);
    CHECK(q);
    size_t got = fread(q, 1, n + 1, f);
    fclose(f);
    int ok = got == n && !memcmp(p, q, n);
    free(q);
    return ok;
}

static void t_copy(void) {
    int live = live_handles();
    put("src", "SOURCE-BYTES");
    /* existing destination, no failIfExists: overwritten, TRUE */
    put("dst", "OLD-DESTINATION-LONGER-THAN-SRC");
    CHECK(cpy("src", "dst", 0) == 1);
    expect("dst", "SOURCE-BYTES");
    CHECK(fsize("dst") == 12);                                          /* truncated, not merged */
    /* failIfExists=1 on an existing destination: FALSE + ERROR_FILE_EXISTS, destination untouched */
    put("dst", "KEEP-ME");
    CHECK(cpy("src", "dst", 1) == 0 && g_err == ERROR_FILE_EXISTS);
    expect("dst", "KEEP-ME");
    /* the destination spelled in another case is the same file */
    CHECK(cpy("src", "DST", 1) == 0 && g_err == ERROR_FILE_EXISTS);
    CHECK(cpy("SRC", "Dst", 0) == 1);
    expect("dst", "SOURCE-BYTES");
    CHECK(count_ci("dst") == 1);
    /* absent source: FALSE, existing destination untouched (default does not read-then-truncate) */
    put("dst", "STILL-HERE");
    CHECK(cpy("nosuch", "dst", 0) == 0);
    expect("dst", "STILL-HERE");
    CHECK(cpy("nosuch", "dst", 1) == 0);
    expect("dst", "STILL-HERE");
    CHECK(cpy("nosuch", "nosuch2", 0) == 0 && !present("nosuch2"));
    /* empty source over a non-empty destination -> empty destination */
    put("empty", "");
    CHECK(cpy("empty", "dst", 0) == 1 && fsize("dst") == 0);
    /* big files: not a multiple of the 64 KiB copy buffer, and an exact multiple of it */
    {
        size_t sizes[3] = { 3u * 1024 * 1024 + 17, 65536u * 5, 65536u + 1 };
        for (int k = 0; k < 3; k++) {
            unsigned char *buf = malloc(sizes[k]);
            CHECK(buf);
            fill(buf, sizes[k], (unsigned)k + 1);
            write_bin("big", buf, sizes[k]);
            put("bigdst", "SHORT");
            CHECK(cpy("big", "bigdst", 0) == 1);
            CHECK(fsize("bigdst") == (long)sizes[k] && same_bin("bigdst", buf, sizes[k]));
            CHECK(same_bin("big", buf, sizes[k]));                      /* source unchanged */
            /* a shorter source over the big destination shrinks it */
            CHECK(cpy("src", "bigdst", 0) == 1 && fsize("bigdst") == 12);
            free(buf);
        }
    }
    /* a destination that cannot be opened for writing (read-only file): FALSE, content unchanged */
    if (!running_as_root()) {
        put("rodst", "READONLY");
        CHECK(!chmod(hp("rodst"), 0444));
        CHECK(cpy("src", "rodst", 0) == 0);
        expect("rodst", "READONLY");
        CHECK(!chmod(hp("rodst"), 0644));
    }
    /* SAVE\ slots: overwrite an existing slot, the sibling slot and the directory stay */
    CHECK(mkd("SAVE") == 1);
    put("SAVE/slot1", "SLOT-ONE-OLD-LONG");
    put("SAVE/slot2", "SLOT-TWO");
    CHECK(cpy("SAVE\\slot2", "SAVE\\slot1", 0) == 1);
    expect("SAVE/slot1", "SLOT-TWO");
    expect("SAVE/slot2", "SLOT-TWO");
    CHECK(cpy("SAVE\\slot2", "SAVE\\slot1", 1) == 0 && g_err == ERROR_FILE_EXISTS);
    {   /* and through the guest file API afterwards */
        uint32_t h = cf("SAVE\\slot1", GENERIC_READ, FS_R, OPEN_EXISTING);
        CHECK(h != INVALID);
        char b[32] = { 0 };
        CHECK(rd(h, b, 31) == 8 && !memcmp(b, "SLOT-TWO", 8));
        CHECK(ch(h) == 1);
    }
    rm_rf(hp("SAVE"));
    clean_root();
    quiescent(live);
    puts("K1 CopyFileA default contract (existing destination): PASS");

    /* ---- KNOWN GAPS of the default path, reported only (nobody calls it, see the audit) ---- */
    put("src", "SOURCE-BYTES");
    uint32_t r = cpy("src", "newdst", 0);
    printf("KNOWN-GAP absent destination: CopyFileA(src,newdst,0) = %u, created = %d, LastError %s\n",
           r, present("newdst"), g_err == NOERR ? "untouched (no error code)" : "set");
    CHECK(r == 0 || present("newdst"));                                 /* never "TRUE without a file" */
    if (present("newdst")) unlink(hp("newdst"));
    put("selfcopy", "ABCDEFGH");
    r = cpy("selfcopy", "selfcopy", 0);
    printf("KNOWN-GAP copy onto itself: = %u, size afterwards %ld (Windows: FALSE, ERROR_SHARING_VIOLATION, untouched)\n", r, fsize("selfcopy"));
#if !defined(__EMSCRIPTEN__)
    {   /* a write error (quota / full disk stand-in: RLIMIT_FSIZE) */
        unsigned char *buf = malloc(300000);
        CHECK(buf);
        fill(buf, 300000, 9);
        write_bin("quotasrc", buf, 300000);
        put("quotadst", "OLD");
        struct rlimit old, lim;
        CHECK(!getrlimit(RLIMIT_FSIZE, &old));
        lim = old;
        lim.rlim_cur = 100000;   /* only the soft limit: the hard one stays, so it can be restored */
        void (*prev)(int) = signal(SIGXFSZ, SIG_IGN);
        int lim_ok = setrlimit(RLIMIT_FSIZE, &lim) == 0;
        r = lim_ok ? cpy("quotasrc", "quotadst", 0) : 0;
        if (lim_ok) setrlimit(RLIMIT_FSIZE, &old);
        signal(SIGXFSZ, prev);
        if (lim_ok)
            printf("KNOWN-GAP write error: CopyFileA(300000 B) under a 100000 B file-size limit = %u, destination %ld B (Windows: FALSE with the error)\n", r, fsize("quotadst"));
        else puts("KNOWN-GAP write error: setrlimit unavailable, not exercised");
        free(buf);
    }
#endif
    clean_root();
    quiescent(live);
    puts("K1 CopyFileA known gaps reported");
}

#if SAVE_META_ON && defined(PORT_SAVE_TX)
/* the default path next to SAVE_META / SAVE_TX: a repeated mkd("SAVE") and an overwrite copy must
   neither disturb the slot, its time record nor the transaction state */
static void t_save_hooks(void) {
    int live = live_handles();
    CHECK(mkd("SAVE") == 1);
    put("SAVE/slot1", "OLDSLOT");
    save_meta_write("slot1", guest_time_100ns());
    CHECK(save_meta_exists("slot1"));
    for (int i = 0; i < 100; i++) CHECK(mkd("SAVE") == 0 && g_err == ERROR_ALREADY_EXISTS);
    CHECK(save_meta_exists("slot1") && present("SAVE/slot1") && !present("SAVE_TX/journal.log"));
    expect("SAVE/slot1", "OLDSLOT");
    uint32_t h = cf("SAVE\\slot1", GENERIC_READ, FS_R, OPEN_EXISTING);
    CHECK(h != INVALID);
    char b[16] = { 0 };
    CHECK(rd(h, b, 15) == 7 && !memcmp(b, "OLDSLOT", 7));
    CHECK(ch(h) == 1);
    /* CopyFileA onto an existing slot is invisible to SAVE_TX and SAVE_META (inherited gap, F32_AUDIT.md) */
    put("SAVE/slot2", "SLOT2");
    CHECK(cpy("SAVE\\slot2", "SAVE\\slot1", 0) == 1);
    expect("SAVE/slot1", "SLOT2");
    CHECK(save_meta_exists("slot1") && !present("SAVE_TX/journal.log"));
    /* RemoveDirectoryA("SAVE") with slots in it: refused, record and slots stay */
    CHECK(rmd("SAVE") == 0 && present("SAVE/slot1") && save_meta_exists("slot1"));
    /* the engine's overwrite flow still works afterwards */
    CHECK(mkd("SAVE") == 0 && g_err == ERROR_ALREADY_EXISTS);
    uint32_t w = cf("SAVE\\slot1", GENERIC_WRITE, FS_R | FS_W, CREATE_ALWAYS);
    CHECK(w != INVALID);
    {
        uint32_t out = g_e.base + 0x200u, data = g_e.base + 0x3000u;
        memcpy(HP(data), "NEW1", 4);
        uint32_t a[5] = { w, data, 4, out, 0 };
        CHECK(call(w_WriteFile, 5, a) == 1 && R32(out) == 4);
    }
    CHECK(ch(w) == 1);
    expect("SAVE/slot1", "NEW1");
    CHECK(save_meta_exists("slot1"));
    rm_rf(hp("SAVE"));
    rm_rf(hp("SAVE_TX"));
    rm_rf(hp("SAVE_META"));
    clean_root();
    quiescent(live);
    puts("K1 default path with SAVE_TX/SAVE_META: PASS");
}
#endif

int main(int argc, char **argv) {
    unsetenv("PORT_STRICT_FILE_SHARE");
    CHECK(strict_share() == 0);   /* the default mode is the whole point */
    CHECK(!setenv("PORT_FILE_SNAPSHOT", "0", 1));
    g_mem = calloc(1, 0x100000);
    CHECK(g_mem);
    memset(&g_e, 0, sizeof g_e);
    g_e.base = 0x1000u;
    (void)snapshot_enabled(); (void)snapshot_max(); (void)host_seconds();
    snprintf(root, sizeof root, "%s/korsary-k1-XXXXXX", argc > 1 ? argv[1] : "/tmp");
    CHECK(mkdtemp(root));
    snprintf(g_game_root, sizeof g_game_root, "%s", root);
    CHECK(res_used() == 0 && pend_used() == 0);
    for (int run = 0; run < 2; run++) {   /* a second run over the same root: nothing may be left behind */
        t_savepath();
        t_rmdir();
        t_copy();
#if SAVE_META_ON && defined(PORT_SAVE_TX)
        t_save_hooks();
#endif
        CHECK(!present("SAVE") && !present("Dir") && !present("dst"));
    }
    clean_root();
    CHECK(res_used() == 0 && pend_used() == 0);
    rmdir(root);
    free(g_mem);
    puts("K1 default dirs/copy: ALL PASS");
    return 0;
}
