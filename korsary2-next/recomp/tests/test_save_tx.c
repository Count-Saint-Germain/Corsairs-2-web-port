/* Ф4.2 SAVE_TX host half. Drives the REAL production handlers w_CreateFileA /
   w_WriteFile / w_ReadFile / w_CloseHandle / w_DeleteFileA of kernel32.c over
   synthetic temp directories (never player data), with a small shim in front
   of the host syscalls (write/fsync/unlink/open/ftruncate) that can fail,
   shorten or cut any call and can kill the process before the n-th mutating
   syscall. Compiled with -DPORT_SAVE_META=1 -DPORT_SAVE_TX=1 (the browser
   configuration; the page opts in at runtime through PORT_SAVE_TX).

   Modes:
     (none)                     in-process assertions on the real handlers
     --seed <root> <scenario>   prepare the SAVE folder of a scenario
     --run <root> <scenario> [kill=<n>] [torn=1] [inject=<class>:<nth>:<kind>]
                                run the engine flow of a scenario; kill=<n>
                                _exit()s before the n-th mutating syscall
                                (torn=1: after writing half of an n-th write)
     --final <scenario>         print the final bytes' size and SHA-256 hex
   test_save_tx.mjs drives --seed/--run for every kill point and recovers the
   result with the page code; it never replaces a live check of the game. */
#include <assert.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <pthread.h>
#include <sched.h>
#include <stdarg.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "../host/core.c"

/* ---- syscall shim: wraps only what kernel32.c (included below) calls ---- */
enum { CL_OTHER, CL_SLOT, CL_META, CL_JOURNAL, CL_PRIOR, CL_MAX };
static unsigned char sh_class[4096];
static long sh_ops, sh_kill_at = -1, sh_writes[CL_MAX];
static int sh_torn;
static int sh_inj_class = -1, sh_inj_kind;            /* 1 ENOSPC, 2 short, 3 zero */
static long sh_inj_nth = -1;
static int sh_fsync_fail_class = -1; static long sh_fsync_fail_nth = -1, sh_fsyncs[CL_MAX];
static int sh_unlink_fail_class = -1; static long sh_unlink_fail_nth = -1, sh_unlinks[CL_MAX];
static uint64_t t_skew;                                /* test clock offset, 100 ns */

static int sh_classify(const char *path) {
    if (strstr(path, "/SAVE_TX/journal.log")) return CL_JOURNAL;
    if (strstr(path, "/SAVE_TX/prior-")) return CL_PRIOR;
    if (strstr(path, "/SAVE_META/")) return CL_META;
    if (strstr(path, "/SAVE/")) return CL_SLOT;
    return CL_OTHER;
}
static void sh_tick(void) { if (sh_kill_at != -1 && sh_ops++ == sh_kill_at) _exit(77); }   /* -1 off, -2 count only */
static int sh_open(const char *path, int fl, ...) {
    mode_t mode = 0;
    if (fl & O_CREAT) { va_list ap; va_start(ap, fl); mode = (mode_t)va_arg(ap, int); va_end(ap); }
    if (fl & (O_CREAT | O_TRUNC)) sh_tick();
    int fd = (open)(path, fl, mode);
    if (fd >= 0 && fd < (int)sizeof sh_class) __atomic_store_n(&sh_class[fd], (unsigned char)sh_classify(path), __ATOMIC_RELAXED);
    return fd;
}
static ssize_t sh_write(int fd, const void *b, size_t n) {
    int cl = fd >= 0 && fd < (int)sizeof sh_class ? __atomic_load_n(&sh_class[fd], __ATOMIC_RELAXED) : CL_OTHER;
    if (sh_kill_at >= 0 && sh_ops == sh_kill_at && sh_torn && n > 1) { (write)(fd, b, n / 2); _exit(77); }
    sh_tick();
    long nth = __atomic_add_fetch(&sh_writes[cl], 1, __ATOMIC_RELAXED);
    if (cl == sh_inj_class && nth == sh_inj_nth) {
        if (sh_inj_kind == 1) { errno = ENOSPC; return -1; }
        if (sh_inj_kind == 2) return (write)(fd, b, n > 1 ? n / 2 : n);
        if (sh_inj_kind == 3) return 0;
    }
    return (write)(fd, b, n);
}
static int sh_fsync(int fd) {
    int cl = fd >= 0 && fd < (int)sizeof sh_class ? __atomic_load_n(&sh_class[fd], __ATOMIC_RELAXED) : CL_OTHER;
    sh_tick();
    if (cl == sh_fsync_fail_class && ++sh_fsyncs[cl] == sh_fsync_fail_nth) { errno = EIO; return -1; }
    return (fsync)(fd);
}
static int sh_unlink(const char *p) {
    int cl = sh_classify(p);
    sh_tick();
    if (cl == sh_unlink_fail_class && ++sh_unlinks[cl] == sh_unlink_fail_nth) { errno = EACCES; return -1; }
    return (unlink)(p);
}
static int sh_ftruncate(int fd, off_t n) { sh_tick(); return (ftruncate)(fd, n); }
static int sh_mkdir(const char *p, mode_t m) { sh_tick(); return (mkdir)(p, m); }
static uint64_t sh_now(void) { return (host_time_100ns)() + t_skew; }
#define open(...) sh_open(__VA_ARGS__)
#define write(fd, b, n) sh_write(fd, b, n)
#define fsync(fd) sh_fsync(fd)
#define unlink(p) sh_unlink(p)
#define ftruncate(fd, n) sh_ftruncate(fd, n)
#define mkdir(p, m) sh_mkdir(p, m)
#define host_time_100ns() sh_now()
#include "../host/kernel32.c"
#undef open
#undef write
#undef fsync
#undef unlink
#undef ftruncate
#undef mkdir
#undef host_time_100ns
uint8_t *g_mem;

#if !SAVE_META_ON
#error "test_save_tx.c needs the browser configuration (-DPORT_SAVE_META=1)"
#endif

/* ---- the engine: one guest thread's view ---- */
typedef struct { CPU c; GuestThread th; uint32_t base; } Eng;
static Eng g_eng[4];
static void eng_bind(Eng *e) { t_self = &e->th; }
static uint32_t eng_create(Eng *e, const char *guest, uint32_t access, uint32_t disp) {
    eng_bind(e);
    uint32_t sp = e->base + 0x100, str = e->base + 0x400;
    strcpy((char *)HP(str), guest);
    e->c.esp = sp;
    W32(sp, 0); W32(sp + 4, str); W32(sp + 8, access); W32(sp + 12, 7 /* share all */); W32(sp + 16, 0); W32(sp + 20, disp);
    W32(sp + 24, 0); W32(sp + 28, 0);
    w_CreateFileA(&e->c);
    return e->c.eax;
}
static int eng_write(Eng *e, uint32_t h, const void *data, uint32_t n, uint32_t *written) {
    eng_bind(e);
    uint32_t sp = e->base + 0x100, buf = e->base + 0x1000, out = e->base + 0x200;
    memcpy(HP(buf), data, n);
    e->c.esp = sp;
    W32(sp, 0); W32(sp + 4, h); W32(sp + 8, buf); W32(sp + 12, n); W32(sp + 16, out); W32(sp + 20, 0);
    w_WriteFile(&e->c);
    if (written) *written = R32(out);
    return (int)e->c.eax;
}
static uint32_t eng_read(Eng *e, uint32_t h, void *data, uint32_t n) {
    eng_bind(e);
    uint32_t sp = e->base + 0x100, buf = e->base + 0x1000, out = e->base + 0x200;
    e->c.esp = sp;
    W32(sp, 0); W32(sp + 4, h); W32(sp + 8, buf); W32(sp + 12, n); W32(sp + 16, out); W32(sp + 20, 0);
    w_ReadFile(&e->c);
    memcpy(data, HP(buf), R32(out));
    return R32(out);
}
static int eng_close(Eng *e, uint32_t h) {
    eng_bind(e);
    e->c.esp = e->base + 0x100;
    W32(e->c.esp, 0); W32(e->c.esp + 4, h);
    w_CloseHandle(&e->c);
    return (int)e->c.eax;
}
static int eng_delete(Eng *e, const char *guest) {
    eng_bind(e);
    uint32_t sp = e->base + 0x100, str = e->base + 0x400;
    strcpy((char *)HP(str), guest);
    e->c.esp = sp;
    W32(sp, 0); W32(sp + 4, str);
    w_DeleteFileA(&e->c);
    return (int)e->c.eax;
}
#define GENERIC_WRITE_ 0x40000000u
#define GENERIC_READ_ 0x80000000u
#define BAD 0xffffffffu

/* ---- synthetic slot bytes ---- */
static size_t fill_bytes(uint8_t *b, size_t n, const char *tag, int salt) {
    for (size_t i = 0; i < n; i++) b[i] = (uint8_t)(tag[i % strlen(tag)] + salt * 7 + (int)(i / 251));
    return n;
}
#define STAGE1_LEN 6000
#define STAGE2_LEN 6500
#define OLD_LEN 5000
/* Stage 1 (SaveEngineState): header of eight zero bytes, then body chunks. */
static int stage1(Eng *e, const char *guest, const char *tag) {
    uint32_t h = eng_create(e, guest, GENERIC_WRITE_, 2);
    if (h == BAD) return 0;
    uint8_t body[STAGE1_LEN], z[8] = {0};
    fill_bytes(body, sizeof body, tag, 1);
    uint32_t w;
    int ok = eng_write(e, h, z, 8, &w) && w == 8;
    for (size_t off = 0; off < sizeof body && ok; off += 2000) ok = eng_write(e, h, body + off, 2000, &w) && w == 2000;
    eng_close(e, h);
    return ok;
}
/* Stage 2 (ISetSaveData): read the whole file, re-open it for writing with
   CREATE_ALWAYS and write the header, body and the metadata block. */
static int stage2(Eng *e, const char *guest, const char *tag) {
    uint32_t r = eng_create(e, guest, GENERIC_READ_, 3);
    if (r == BAD) return 0;
    uint8_t tmp[16384];
    uint32_t got = eng_read(e, r, tmp, sizeof tmp);
    eng_close(e, r);
    (void)got;
    uint32_t h = eng_create(e, guest, GENERIC_WRITE_, 2);
    if (h == BAD) return 0;
    uint8_t fin[STAGE2_LEN];
    fill_bytes(fin, sizeof fin, tag, 2);
    uint32_t w;
    int ok = eng_write(e, h, fin, 4, &w) && w == 4;
    ok = ok && eng_write(e, h, fin + 4, 4, &w) && w == 4;
    for (size_t off = 8; off < sizeof fin && ok; off += 1500) {
        uint32_t n = (uint32_t)(sizeof fin - off < 1500 ? sizeof fin - off : 1500);
        ok = eng_write(e, h, fin + off, n, &w) && w == n;
    }
    eng_close(e, h);
    return ok;
}
static void final_bytes(uint8_t *out, const char *tag) { fill_bytes(out, STAGE2_LEN, tag, 2); }

/* ---- files ---- */
static char g_root[1100];
static void path_in(char *out, size_t n, const char *dir, const char *name) { snprintf(out, n, "%s/%s/%s", g_root, dir, name); }
static int read_file(const char *path, uint8_t *buf, size_t cap, size_t *len) {
    FILE *f = fopen(path, "rb");
    if (!f) return 0;
    *len = fread(buf, 1, cap, f);
    fclose(f);
    return 1;
}
static void put_file(const char *dir, const char *name, const void *data, size_t n) {
    char d[1200], p[1300];
    snprintf(d, sizeof d, "%s/%s", g_root, dir);
    (mkdir)(d, 0755);
    snprintf(p, sizeof p, "%s/%s", d, name);
    FILE *f = fopen(p, "wb");
    assert(f);
    if (n) assert(fwrite(data, 1, n, f) == n);
    assert(!fclose(f));
}
static int exists_in(const char *dir, const char *name) {
    char p[1300]; struct stat st;
    path_in(p, sizeof p, dir, name);
    return stat(p, &st) == 0;
}
static void put_meta(const char *slot, uint64_t ft) {
    uint8_t b[8];
    for (int i = 0; i < 8; i++) b[i] = (uint8_t)(ft >> (8 * i));
    char name[600];
    snprintf(name, sizeof name, "%s.time", slot);
    put_file("SAVE_META", name, b, 8);
}
static void rm_tree(const char *dir) {
    DIR *d = opendir(dir);
    if (!d) return;
    struct dirent *e;
    while ((e = readdir(d))) {
        if (!strcmp(e->d_name, ".") || !strcmp(e->d_name, "..")) continue;
        char p[1300];
        snprintf(p, sizeof p, "%s/%s", dir, e->d_name);
        struct stat st;
        if (lstat(p, &st) == 0 && S_ISDIR(st.st_mode)) rm_tree(p); else (unlink)(p);
    }
    closedir(d);
    (rmdir)(dir);
}
static int count_dir(const char *dir) {
    char p[1300];
    snprintf(p, sizeof p, "%s/%s", g_root, dir);
    DIR *d = opendir(p);
    if (!d) return -1;
    int n = 0;
    struct dirent *e;
    while ((e = readdir(d))) if (strcmp(e->d_name, ".") && strcmp(e->d_name, "..")) n++;
    closedir(d);
    return n;
}

/* ---- journal inspection ---- */
static char g_journal[1 << 18];
static int load_journal(void) {
    char p[1300];
    path_in(p, sizeof p, "SAVE_TX", "journal.log");
    size_t len = 0;
    g_journal[0] = 0;
    if (!read_file(p, (uint8_t *)g_journal, sizeof g_journal - 1, &len)) return 0;
    g_journal[len] = 0;
    return 1;
}
/* Every line must end with a CRC-32 of its own text; returns the line count or -1. */
static int journal_valid_lines(void) {
    load_journal();
    int n = 0;
    for (char *line = g_journal; *line;) {
        char *nl = strchr(line, '\n');
        if (!nl) return -1;   /* torn tail */
        *nl = 0;
        if (*line) {
            char *crc = strstr(line, " crc=");
            if (!crc) { *nl = '\n'; return -1; }
            char body[2400];
            snprintf(body, sizeof body, "%.*s", (int)(crc - line), line);
            unsigned got = 0;
            sscanf(crc + 5, "%x", &got);
            if (got != save_tx_crc32(body, strlen(body))) { *nl = '\n'; return -1; }
            n++;
        }
        *nl = '\n';
        line = nl + 1;
    }
    return n;
}
static int count_events(const char *ev) {
    load_journal();
    char pat[64];
    snprintf(pat, sizeof pat, "v1 %s ", ev);
    int n = 0;
    for (const char *p = g_journal; (p = strstr(p, pat)); p++) n++;
    return n;
}
static const char *find_event(const char *ev, int nth) {
    char pat[64];
    snprintf(pat, sizeof pat, "v1 %s ", ev);
    const char *p = g_journal;
    while ((p = strstr(p, pat)) && nth--) p++;
    return p;
}
static void hex_of(const char *s, char *out) { save_tx_hex(s, out, 2048); }

/* ---- scenarios shared by the unit run and the kill matrix ---- */
static void reset_world(void) {
    memset(&g_save_tx, 0, sizeof g_save_tx);
    memset(sh_writes, 0, sizeof sh_writes); memset(sh_fsyncs, 0, sizeof sh_fsyncs); memset(sh_unlinks, 0, sizeof sh_unlinks);
    sh_ops = 0; sh_kill_at = -1; sh_torn = 0; sh_inj_class = -1; sh_inj_nth = -1; sh_fsync_fail_class = -1; sh_fsync_fail_nth = -1;
    sh_unlink_fail_class = -1; sh_unlink_fail_nth = -1; t_skew = 0;
    g_save_tx_dir[0] = 0;
}
#define OLD_TIME 133000000000000000ull
static void seed_slot(const char *name, int with_meta, const char *tag) {
    uint8_t old[OLD_LEN];
    fill_bytes(old, sizeof old, tag, 0);
    put_file("SAVE", name, old, sizeof old);
    if (with_meta) put_meta(name, OLD_TIME);
}
static void seed_scenario(const char *sc) {
    (mkdir)(g_root, 0755);
    char d[1200]; snprintf(d, sizeof d, "%s/SAVE", g_root); (mkdir)(d, 0755);
    if (!strcmp(sc, "fresh")) { seed_slot("Keep", 1, "KEEP"); return; }
    if (!strcmp(sc, "legacy")) { seed_slot("Oxbay", 0, "OLD-Oxbay"); seed_slot("Keep", 1, "KEEP"); return; }
    seed_slot("Oxbay", 1, "OLD-Oxbay");
    seed_slot("Keep", 1, "KEEP");
}
/* The engine sequence of one scenario; returns 1 when every engine call succeeded. */
static int run_scenario(const char *sc) {
    Eng *e = &g_eng[0];
    if (!strcmp(sc, "same") || !strcmp(sc, "legacy")) {
        eng_delete(e, "SAVE\\Oxbay");
        return stage1(e, "SAVE\\Oxbay", "NEW") && stage2(e, "SAVE\\Oxbay", "NEW");
    }
    if (!strcmp(sc, "rename")) {
        eng_delete(e, "SAVE\\Oxbay");
        return stage1(e, "SAVE\\Oxbay 2", "NEW") && stage2(e, "SAVE\\Oxbay 2", "NEW");
    }
    if (!strcmp(sc, "fresh")) return stage1(e, "SAVE\\Fresh", "NEW") && stage2(e, "SAVE\\Fresh", "NEW");
    if (!strcmp(sc, "trunc")) return stage1(e, "SAVE\\Oxbay", "NEW") && stage2(e, "SAVE\\Oxbay", "NEW");
    if (!strcmp(sc, "delete")) { eng_delete(e, "SAVE\\Oxbay"); return 1; }
    fprintf(stderr, "unknown scenario %s\n", sc);
    exit(2);
}

static void check_sha_vectors(void) {
    struct { const char *in; const char *hex; } v[] = {
        {"", "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855"},
        {"abc", "ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad"},
        {"abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq", "248d6a61d20638b8e5c026930c3e6039a33ce45964ff2167f6ecedd419db06c1"},
    };
    for (size_t i = 0; i < sizeof v / sizeof v[0]; i++) {
        SaveTxSha s; char h[65];
        save_tx_sha_init(&s);
        save_tx_sha_update(&s, v[i].in, strlen(v[i].in));
        save_tx_sha_hex(&s, h);
        assert(!strcmp(h, v[i].hex));
    }
    SaveTxSha s; char h[65];
    save_tx_sha_init(&s);
    char blk[1000]; memset(blk, 'a', sizeof blk);
    for (int i = 0; i < 1000; i++) save_tx_sha_update(&s, blk, sizeof blk);   /* streamed in odd-aligned pieces below */
    save_tx_sha_hex(&s, h);
    assert(!strcmp(h, "cdc76e5c9914fb9281a1c7e284d73e67f1809a48a497200e046d39ccc7112cd0"));
    /* block-boundary lengths 55/56/63/64/65 against fixed digests */
    struct { size_t n; const char *hex; } b[] = {
        {55, "9f4390f8d30c2dd92ec9f095b65e2b9ae9b0a925a5258e241c9f1e910f734318"},
        {56, "b35439a4ac6f0948b6d6f9e3c6af0f5f590ce20f1bde7090ef7970686ec6738a"},
        {63, "7d3e74a05d7db15bce4ad9ec0658ea98e3f06eeecf16b4c6fff2da457ddc2f34"},
        {64, "ffe054fe7ae0cb6dc65c3af9b61d5209f439851db43d0ba5997337df154668eb"},
        {65, "635361c48bb9eab14198e76ea8ab7f1a41685d6ad62aa9146d301d4f17eb0ae0"},
    };
    for (size_t i = 0; i < sizeof b / sizeof b[0]; i++) {
        char in[70]; memset(in, 'a', sizeof in);
        save_tx_sha_init(&s);
        for (size_t k = 0; k < b[i].n; k++) save_tx_sha_update(&s, in, 1);   /* byte by byte */
        save_tx_sha_hex(&s, h);
        assert(!strcmp(h, b[i].hex));
    }
}

/* =========================================================== unit assertions */
static void with_world(const char *sc) {
    reset_world();
    rm_tree(g_root);
    seed_scenario(sc);
    __atomic_store_n(&g_save_tx_on, 1, __ATOMIC_RELAXED);
}
static void expect_slot(const char *name, const char *tag, int salt, size_t len) {
    uint8_t want[16384], got[16384];
    size_t n = 0;
    char p[1300];
    path_in(p, sizeof p, "SAVE", name);
    assert(read_file(p, got, sizeof got, &n));
    assert(n == len);
    fill_bytes(want, len, tag, salt);
    assert(!memcmp(want, got, len));
}
static void test_normal_overwrite(const char *sc, const char *created, int has_meta) {
    with_world(sc);
    assert(run_scenario(sc));
    assert(journal_valid_lines() > 0);
    assert(count_events("arm") == 1 && count_events("create") == 1 && count_events("cycle") == 2 &&
           count_events("commit") == 1 && count_events("fail") == 0 && count_events("anomaly") == 0);
    char hexo[2048], hexc[2048];
    hex_of("Oxbay", hexo); hex_of(created, hexc);
    assert(strstr(find_event("arm", 0), "kind=delete"));
    char want[2100];
    snprintf(want, sizeof want, "slot=%s", hexo);
    assert(strstr(find_event("arm", 0), want));
    snprintf(want, sizeof want, "target=%s", hexc);
    assert(strstr(find_event("create", 0), want) && strstr(find_event("commit", 0), want));
    assert(strstr(find_event("cycle", 0), " n=1 ") && strstr(find_event("cycle", 1), " n=2 "));
    assert(strstr(find_event("cycle", 0), "errors=0") && strstr(find_event("cycle", 1), "errors=0"));
    /* the fixture is the SHA-256 of what is on disk now */
    uint8_t b[16384]; size_t n = 0; char p[1300];
    path_in(p, sizeof p, "SAVE", created);
    assert(read_file(p, b, sizeof b, &n) && n == STAGE2_LEN);
    SaveTxSha s; char h[65], line[256];
    save_tx_sha_init(&s); save_tx_sha_update(&s, b, n); save_tx_sha_hex(&s, h);
    snprintf(line, sizeof line, "size=%d sha=%s", STAGE2_LEN, h);
    assert(strstr(find_event("commit", 0), line));
    /* the prior copy holds the old bytes; its record keeps the old sidecar */
    const char *a = find_event("arm", 0);
    assert(strstr(a, "meta=") && (has_meta ? !strstr(a, "meta=-") : !!strstr(a, "meta=-")));
    const char *pr = strstr(a, "prior=");
    char priorname[80];
    sscanf(pr + 6, "%79s", priorname);
    uint8_t ob[OLD_LEN], got[OLD_LEN]; size_t gn = 0;
    fill_bytes(ob, sizeof ob, "OLD-Oxbay", 0);
    path_in(p, sizeof p, "SAVE_TX", priorname);
    assert(read_file(p, got, sizeof got, &gn) && gn == OLD_LEN && !memcmp(ob, got, OLD_LEN));
    expect_slot(created, "NEW", 2, STAGE2_LEN);
    if (strcmp(created, "Oxbay")) assert(!exists_in("SAVE", "Oxbay"));
    expect_slot("Keep", "KEEP", 0, OLD_LEN);
}
static void test_fresh_and_trunc(void) {
    with_world("fresh");
    assert(run_scenario("fresh"));
    assert(journal_valid_lines() > 0 && count_events("arm") == 0 && count_events("commit") == 1);
    assert(strstr(find_event("create", 0), "fresh=1"));
    with_world("trunc");   /* overwrite of an existing slot WITHOUT a delete: the open itself is armed */
    assert(run_scenario("trunc"));
    assert(journal_valid_lines() > 0 && count_events("arm") == 1 && count_events("commit") == 1);
    assert(strstr(find_event("arm", 0), "kind=trunc") && strstr(find_event("create", 0), "fresh=0"));
    expect_slot("Oxbay", "NEW", 2, STAGE2_LEN);
}
static void test_explicit_delete(void) {
    with_world("delete");
    assert(run_scenario("delete"));
    assert(count_events("arm") == 1 && count_events("create") == 0 && count_events("commit") == 0);
    assert(!exists_in("SAVE", "Oxbay") && !exists_in("SAVE_META", "Oxbay.time"));
    assert(count_events("settle") == 0);
    /* a later unrelated write within the bind window belongs to the delete's intent;
       beyond the window the delete is settled as stand-alone first */
    t_skew = 60ull * 10000000ull;
    Eng *e = &g_eng[0];
    assert(stage1(e, "SAVE\\Later", "NEW") && stage2(e, "SAVE\\Later", "NEW"));
    assert(journal_valid_lines() > 0 && count_events("settle") == 1 && count_events("commit") == 1);
    assert(count_events("arm") == 1);
    /* the settle line comes before the new intent's create line, with a different tx */
    const char *s = find_event("settle", 0), *c = find_event("create", 0);
    assert(s < c);
    char txs[40], txc[40];
    sscanf(strstr(s, "tx=") + 3, "%39s", txs);
    sscanf(strstr(c, "tx=") + 3, "%39s", txc);
    assert(strcmp(txs, txc));
}
static void test_many_deletes(void) {
    /* clearing many slots in a row: every delete stays protected (the intent is settled and a new one begins) */
    with_world("fresh");
    Eng *e = &g_eng[0];
    char name[32], guest[64];
    for (int i = 0; i < 20; i++) { snprintf(name, sizeof name, "Many%d", i); seed_slot(name, 1, "MANY"); }
    for (int i = 0; i < 20; i++) { snprintf(guest, sizeof guest, "SAVE\\Many%d", i); assert(eng_delete(e, guest) == 1); }
    assert(count_events("arm") == 20 && count_events("settle") >= 2 && journal_valid_lines() > 0);
    for (int i = 0; i < 20; i++) { snprintf(name, sizeof name, "Many%d", i); assert(!exists_in("SAVE", name)); }
}
static void test_history_bound(void) {
    /* many committed overwrites in a row: the kept-prior history never exceeds its bound and the fields behind it
       stay intact (regression: history[] was sized SAVE_TX_HISTORY_MAX but one commit appends up to
       SAVE_TX_ARM_MAX entries before the trim, so the 5th commit overflowed into the neighbouring fields) */
    with_world("fresh");
    Eng *e = &g_eng[0];
    seed_slot("Hist", 1, "HIST");
    for (int i = 0; i < 14; i++) {
        assert(eng_delete(e, "SAVE\\Hist") == 1);
        assert(stage1(e, "SAVE\\Hist", "HNEW"));
        assert(stage2(e, "SAVE\\Hist", "HNEW"));
        assert(g_save_tx.history_count >= 0 && g_save_tx.history_count <= SAVE_TX_HISTORY_MAX);
        assert(g_save_tx.arm_count >= 0 && g_save_tx.arm_count <= SAVE_TX_ARM_MAX);
        assert(g_save_tx.state >= 0 && g_save_tx.state <= 4);
    }
    assert(count_events("commit") == 14);
    load_journal();
}
static void test_flag_off(void) {
    reset_world();
    rm_tree(g_root);
    seed_scenario("same");
    __atomic_store_n(&g_save_tx_on, 0, __ATOMIC_RELAXED);
    assert(run_scenario("same"));
    assert(!exists_in(".", "SAVE_TX") && count_dir("SAVE_TX") == -1);
    expect_slot("Oxbay", "NEW", 2, STAGE2_LEN);
    assert(exists_in("SAVE_META", "Oxbay.time"));
    uint64_t ft = 0; char p[1300]; uint8_t b[8]; size_t n;
    path_in(p, sizeof p, "SAVE_META", "Oxbay.time");
    assert(read_file(p, b, 8, &n) && n == 8);
    for (int i = 7; i >= 0; i--) ft = (ft << 8) | b[i];
    assert(ft != OLD_TIME);   /* the delete+create flow restamped it, exactly like before this feature */
    /* unset env (value "0" or empty) also means off */
    __atomic_store_n(&g_save_tx_on, -1, __ATOMIC_RELAXED);
}
static void test_io_errors(void) {
    /* a failed engine write in stage 1 */
    with_world("same");
    sh_inj_class = CL_SLOT; sh_inj_nth = 3; sh_inj_kind = 1;
    assert(!run_scenario("same"));
    assert(count_events("commit") == 0 && count_events("fail") == 1 && strstr(find_event("fail", 0), "io-errors"));
    assert(count_events("cycle") == 1 && strstr(find_event("cycle", 0), "errors=1"));
    /* short write in stage 2: the engine sees 'success' with fewer bytes */
    with_world("same");
    sh_inj_class = CL_SLOT; sh_inj_nth = 8; sh_inj_kind = 2;
    run_scenario("same");
    assert(count_events("commit") == 0 && count_events("fail") >= 1);
    /* zero-byte write result */
    with_world("same");
    sh_inj_class = CL_SLOT; sh_inj_nth = 2; sh_inj_kind = 3;
    run_scenario("same");
    assert(count_events("commit") == 0 && count_events("fail") >= 1);
    /* fsync failure of the close hook */
    with_world("same");
    sh_fsync_fail_class = CL_SLOT; sh_fsync_fail_nth = 1;
    run_scenario("same");
    assert(count_events("commit") == 0 && count_events("fail") >= 1);
    /* failing prior copy (quota): the delete proceeds exactly as with the flag off; the later
       fresh create is a prior-less intent that can still commit */
    with_world("same");
    sh_inj_class = CL_PRIOR; sh_inj_nth = 1; sh_inj_kind = 1;
    assert(run_scenario("same"));
    assert(count_events("arm") == 0 && count_events("commit") == 1);
    expect_slot("Oxbay", "NEW", 2, STAGE2_LEN);
    {   /* the failed copy left nothing behind */
        char p[1300]; snprintf(p, sizeof p, "%s/SAVE_TX", g_root);
        DIR *d = opendir(p); struct dirent *e; int priors = 0;
        while (d && (e = readdir(d))) priors += !strncmp(e->d_name, "prior-", 6);
        if (d) closedir(d);
        assert(priors == 0);
    }
    /* unwritable journal: the delete degrades, nothing is half-protected */
    with_world("same");
    sh_inj_class = CL_JOURNAL; sh_inj_nth = 1; sh_inj_kind = 1;
    assert(run_scenario("same"));
    expect_slot("Oxbay", "NEW", 2, STAGE2_LEN);
    assert(count_events("arm") == 0);
    /* an unlink that fails after the arm cancels the arm and frees its copy */
    with_world("same");
    sh_unlink_fail_class = CL_SLOT; sh_unlink_fail_nth = 1;
    assert(eng_delete(&g_eng[0], "SAVE\\Oxbay") == 0);
    assert(exists_in("SAVE", "Oxbay"));
    assert(count_events("arm") == 1 && count_events("abort") == 1);
    {
        const char *pr = strstr(find_event("arm", 0), "prior=");
        char name[80], p[1300];
        sscanf(pr + 6, "%79s", name);
        path_in(p, sizeof p, "SAVE_TX", name);
        struct stat st;
        assert(stat(p, &st) != 0);
    }
    assert(journal_valid_lines() == 2);
}
static void test_tracking_and_reentry(void) {
    /* table exhaustion: more simultaneous write opens of the target than slots */
    with_world("fresh");
    Eng *e = &g_eng[0];
    uint32_t hs[SAVE_TX_TRACK_MAX + 2];
    int n = 0;
    for (; n < SAVE_TX_TRACK_MAX + 2; n++) { hs[n] = eng_create(e, "SAVE\\Fresh", GENERIC_WRITE_, 2 + (n > 0 ? 1 : 0)); }
    uint32_t w;
    for (int i = 0; i < n; i++) if (hs[i] != BAD) eng_write(e, hs[i], "xxxxxxxx", 8, &w);
    for (int i = 0; i < n; i++) if (hs[i] != BAD) eng_close(e, hs[i]);
    assert(count_events("commit") == 0 && count_events("fail") == 1 && strstr(find_event("fail", 0), "io-errors"));
    /* stage 2 never came, some other slot starts: the first intent is failed, the second is independent */
    with_world("fresh");
    assert(stage1(e, "SAVE\\Fresh", "NEW"));
    assert(stage1(e, "SAVE\\Other", "NEW") && stage2(e, "SAVE\\Other", "NEW"));
    assert(journal_valid_lines() > 0 && count_events("fail") == 1 && strstr(find_event("fail", 0), "superseded"));
    assert(count_events("commit") == 1 && strstr(find_event("commit", 0), "target="));
    /* overlap: a second write begins while the first is still open */
    with_world("same");
    uint32_t h = eng_create(e, "SAVE\\Fresh", GENERIC_WRITE_, 2);
    assert(h != BAD);
    uint32_t h2 = eng_create(e, "SAVE\\Keep", GENERIC_WRITE_, 3);   /* existing, foreign, still open */
    assert(h2 != BAD);
    assert(eng_delete(e, "SAVE\\Oxbay") == 1);                       /* unprotected, intent failed */
    eng_write(e, h, "yyyyyyyy", 8, &w);
    eng_close(e, h);
    eng_close(e, h2);
    assert(count_events("anomaly") >= 1 && count_events("commit") == 0);
    assert(journal_valid_lines() > 0);
    /* a third write open after the commit is the NEXT intent: its arm protects the committed bytes */
    with_world("fresh");
    for (int i = 0; i < 3; i++) {
        h = eng_create(e, "SAVE\\Fresh", GENERIC_WRITE_, 2);
        eng_write(e, h, "zzzzzzzz", 8, &w);
        eng_close(e, h);
    }
    assert(count_events("commit") == 1 && count_events("cycle") == 3);
    assert(count_events("arm") == 1 && strstr(find_event("arm", 0), "kind=trunc"));
    assert(journal_valid_lines() > 0);
    /* a failed create of an armed intent keeps the intent for a retry */
    with_world("same");
    assert(eng_delete(e, "SAVE\\Oxbay") == 1);
    char dirp[1300]; snprintf(dirp, sizeof dirp, "%s/SAVE", g_root);
    chmod(dirp, 0555);
    uint32_t bad = eng_create(e, "SAVE\\Oxbay", GENERIC_WRITE_, 2);
    chmod(dirp, 0755);
    if (geteuid() != 0) {   /* root ignores directory permissions */
        assert(bad == BAD);
        assert(count_events("create-fail") == 1);
        assert(stage1(e, "SAVE\\Oxbay", "NEW") && stage2(e, "SAVE\\Oxbay", "NEW"));
        assert(count_events("commit") == 1 && count_events("arm") == 1 && count_events("create") == 2);
    } else if (bad != BAD) eng_close(e, bad);
}
static void test_torn_journal(void) {
    with_world("same");
    Eng *e = &g_eng[0];
    assert(eng_delete(e, "SAVE\\Oxbay") == 1);
    char p[1300];
    path_in(p, sizeof p, "SAVE_TX", "journal.log");
    FILE *f = fopen(p, "ab"); assert(f);
    fputs("v1 cycle tx=00 ts=1 target=ab n=1 wri", f);   /* a crash cut the record: no newline */
    fclose(f);
    assert(stage1(e, "SAVE\\Oxbay", "NEW") && stage2(e, "SAVE\\Oxbay", "NEW"));
    load_journal();
    assert(strstr(g_journal, "wri\nv1 create "));   /* the next record starts on a fresh line */
    /* every line except the planted torn one has a valid checksum */
    int good = 0, bad = 0;
    for (char *line = g_journal; *line;) {
        char *nl = strchr(line, '\n'); assert(nl); *nl = 0;
        char *crc = strstr(line, " crc=");
        if (crc) {
            char body[2400]; snprintf(body, sizeof body, "%.*s", (int)(crc - line), line);
            unsigned got = 0; sscanf(crc + 5, "%x", &got);
            if (got == save_tx_crc32(body, strlen(body))) good++; else bad++;
        } else bad++;
        line = nl + 1;
    }
    assert(bad == 1 && good >= 5);
}
static volatile int g_bar_n;
static void *thread_flow(void *arg) {
    int i = (int)(intptr_t)arg;
    Eng *e = &g_eng[i];
    t_self = &e->th;
    __atomic_add_fetch(&g_bar_n, 1, __ATOMIC_SEQ_CST);
    while (__atomic_load_n(&g_bar_n, __ATOMIC_SEQ_CST) < 3) sched_yield();
    char guest[64], tag[16];
    for (int k = 0; k < 20; k++) {
        snprintf(guest, sizeof guest, "SAVE\\T%d_%d", i, k % 3);
        snprintf(tag, sizeof tag, "NEW%d", i);
        eng_delete(e, guest);
        stage1(e, guest, tag);
        stage2(e, guest, tag);
    }
    return NULL;
}
static void test_threads(void) {
    with_world("fresh");
    pthread_t t[3];
    g_bar_n = 0;
    for (int i = 1; i <= 3; i++) assert(!pthread_create(&t[i - 1], NULL, thread_flow, (void *)(intptr_t)i));
    for (int i = 0; i < 3; i++) pthread_join(t[i], NULL);
    /* whatever interleaving happened, the journal stays parseable and every commit has a fixture */
    assert(journal_valid_lines() > 0);
    load_journal();
    int commits = count_events("commit");
    for (int i = 0; i < commits; i++) assert(strstr(find_event("commit", i), "sha="));
}

/* ---- E5: the language label SAVE_META/<slot>.lang in the journal and in the engine flow */
static void overlay_set(const char *dir) {
    if (dir) setenv("PORT_OVERLAY", dir, 1); else unsetenv("PORT_OVERLAY");
    overlay_test_reset();
}
static int lang_label(const char *slot, char out[3]) {   /* 1 and the two bytes, or 0 */
    uint8_t b[8]; size_t n = 0; char p[1300], name[1100];
    snprintf(name, sizeof name, "%s.lang", slot);
    path_in(p, sizeof p, "SAVE_META", name);
    if (!read_file(p, b, sizeof b, &n) || n != 2) return 0;
    out[0] = (char)b[0]; out[1] = (char)b[1]; out[2] = 0;
    return 1;
}
static int run_load(const char *sc) { int ok = run_scenario(sc); load_journal(); return ok; }
static void test_lang_label(void) {
    char ov[] = "/tmp/korsary-save-tx-lang-ov-XXXXXX";
    assert(mkdtemp(ov));
    char got[3];
    /* Russian mode (overlay off): no label seeded -> the arm line is exactly what it was (no lang= field), nothing is labelled */
    overlay_set(NULL);
    with_world("same");
    assert(run_load("same"));
    assert(!strstr(find_event("arm", 0), "lang=") && !lang_label("Oxbay", got) && count_events("commit") == 1);
    /* a label that an English session left on the slot: the arm preserves it (lang=<hex>), the delete removes it, a Russian re-creation writes none */
    with_world("same"); put_file("SAVE_META", "Oxbay.lang", (const uint8_t *)"en", 2);
    assert(run_load("same"));
    assert(strstr(find_event("arm", 0), " lang=656e") && !lang_label("Oxbay", got) && count_events("commit") == 1);
    /* English mode (overlay on): the re-created slot is labelled "en"; the arm of an unlabelled prior has no lang=, of a labelled one its value */
    overlay_set(ov);
    assert(overlay_active());
    with_world("same");
    assert(run_load("same"));
    assert(!strstr(find_event("arm", 0), "lang=") && lang_label("Oxbay", got) && !strcmp(got, "en"));
    with_world("same"); put_file("SAVE_META", "Oxbay.lang", (const uint8_t *)"ru", 2);
    assert(run_load("same"));
    assert(strstr(find_event("arm", 0), " lang=7275") && lang_label("Oxbay", got) && !strcmp(got, "en"));
    /* renamed slot: the new name is labelled, the old label went with the delete */
    with_world("rename"); put_file("SAVE_META", "Oxbay.lang", (const uint8_t *)"en", 2);
    assert(run_load("rename"));
    assert(!lang_label("Oxbay", got) && lang_label("Oxbay 2", got) && !strcmp(got, "en") && strstr(find_event("arm", 0), " lang=656e"));
    /* an in-place rewrite (kind=trunc): the prior label is journaled and the label stays */
    with_world("trunc"); put_file("SAVE_META", "Oxbay.lang", (const uint8_t *)"ru", 2);
    assert(run_load("trunc"));
    assert(strstr(find_event("arm", 0), "kind=trunc") && strstr(find_event("arm", 0), " lang=7275") && lang_label("Oxbay", got) && !strcmp(got, "ru"));
    /* a stand-alone delete takes the label with the slot (either mode) */
    with_world("delete"); put_file("SAVE_META", "Oxbay.lang", (const uint8_t *)"en", 2);
    assert(run_load("delete"));
    assert(!lang_label("Oxbay", got) && !exists_in("SAVE_META", "Oxbay.time") && strstr(find_event("arm", 0), " lang=656e"));
    /* an invalid label (wrong value, wrong size) is no label: the arm line has no lang= field */
    const char *bad[] = {"xx", "e", "eng", "EN"};
    for (int i = 0; i < 4; i++) {
        with_world("same"); put_file("SAVE_META", "Oxbay.lang", (const uint8_t *)bad[i], strlen(bad[i]));
        assert(run_load("same"));
        assert(!strstr(find_event("arm", 0), "lang="));
    }
    overlay_set(NULL);
    assert(rmdir(ov) == 0);
}

static void unit(void) {
    check_sha_vectors();
    test_normal_overwrite("same", "Oxbay", 1);
    test_normal_overwrite("rename", "Oxbay 2", 1);
    test_normal_overwrite("legacy", "Oxbay", 0);   /* seeded WITHOUT a sidecar: meta=- in its arm record */
    test_fresh_and_trunc();
    test_explicit_delete();
    test_lang_label();
    test_many_deletes();
    test_history_bound();
    test_flag_off();
    test_io_errors();
    test_tracking_and_reentry();
    test_torn_journal();
    if (!getenv("SAVE_TX_NO_THREADS")) test_threads();   /* NODERAWFS: worker threads need the event loop */
    else puts("(threads skipped)");
}

int main(int argc, char **argv) {
    g_mem = calloc(1, 1 << 20); assert(g_mem);
    for (int i = 0; i < 4; i++) g_eng[i].base = 0x20000u + (uint32_t)i * 0x20000u;
    t_self = &g_eng[0].th;
    if (argc >= 3 && !strcmp(argv[1], "--final")) {
        uint8_t b[STAGE2_LEN]; char h[65];
        final_bytes(b, "NEW");
        SaveTxSha s; save_tx_sha_init(&s); save_tx_sha_update(&s, b, sizeof b); save_tx_sha_hex(&s, h);
        printf("%d %s\n", STAGE2_LEN, h);
        return 0;
    }
    if (argc >= 4 && (!strcmp(argv[1], "--seed") || !strcmp(argv[1], "--run"))) {
        snprintf(g_root, sizeof g_root, "%s", argv[2]);
        snprintf(g_game_root, sizeof g_game_root, "%s", argv[2]);
        if (!strcmp(argv[1], "--seed")) { seed_scenario(argv[3]); return 0; }
        __atomic_store_n(&g_save_tx_on, 1, __ATOMIC_RELAXED);
        for (int i = 4; i < argc; i++) {
            if (!strncmp(argv[i], "kill=", 5)) sh_kill_at = atol(argv[i] + 5);
            else if (!strcmp(argv[i], "torn=1")) sh_torn = 1;
            else if (!strncmp(argv[i], "inject=", 7)) {
                int cl, kind; long nth;
                if (sscanf(argv[i] + 7, "%d:%ld:%d", &cl, &nth, &kind) == 3) { sh_inj_class = cl; sh_inj_nth = nth; sh_inj_kind = kind; }
            }
        }
        if (sh_kill_at < 0) sh_kill_at = -2;   /* count only */
        int ok = run_scenario(argv[3]);
        printf("OPS %ld OK %d\n", sh_ops, ok);
        return 0;
    }
    if (argc >= 3 && !strcmp(argv[1], "--envcheck")) {   /* build WITHOUT -DPORT_SAVE_TX: the runtime switch alone decides */
        int expect = atoi(argv[2]);
        char root[] = "/tmp/korsary-save-tx-env-XXXXXX";
        assert(mkdtemp(root));
        snprintf(g_root, sizeof g_root, "%s", root);
        snprintf(g_game_root, sizeof g_game_root, "%s", root);
        seed_scenario("same");
        assert(save_tx_on() == expect);
        assert(run_scenario("same"));
        assert(exists_in(".", "SAVE_TX") == expect);
        expect_slot("Oxbay", "NEW", 2, STAGE2_LEN);
        expect_slot("Keep", "KEEP", 0, OLD_LEN);
        assert(exists_in("SAVE_META", "Oxbay.time"));
        rm_tree(root);
        printf("env PORT_SAVE_TX=%s -> %s: PASS\n", getenv("PORT_SAVE_TX") ? getenv("PORT_SAVE_TX") : "(unset)", expect ? "on" : "off");
        return 0;
    }
    char root[] = "/tmp/korsary-save-tx-XXXXXX";
    assert(mkdtemp(root));
    snprintf(g_root, sizeof g_root, "%s", root);
    snprintf(g_game_root, sizeof g_game_root, "%s", root);
    unit();
    rm_tree(root);
    free(g_mem);
    printf("save tx (real handlers, syscall shim, strict_share=%d): PASS\n", strict_share());
    return 0;
}
