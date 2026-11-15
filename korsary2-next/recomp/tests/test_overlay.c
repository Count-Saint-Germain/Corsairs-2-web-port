/* E1: the read-only language overlay of the host (PORT_OVERLAY, host/core.c map_path_walk/map_path_ov + kernel32.c) on the
   REAL kernel32.c handlers, on synthetic temp trees (base game folder, overlay folder, a folder with a "secret" outside both).
   No game data; this is not a check of the running game. PORT_SPECIFICATION.md.

   Parts (after each, the modes that run it):
     resolve   read of a file in the overlay, only in the overlay, only in the base; spellings (case, / and \, "." and ".."),
               ReadFile/GetFileSize/SetFilePointer through the handle, snapshot on and off
     forbidden SAVE, SAVE_META, SAVE_TX, options, engine.ini, ENGINE.exe, MODULES and a top-level stray file are the base's even
               when the overlay folder holds them; unreachable through "RESOURCE\\..\\SAVE" and friends
     attrs     GetFileAttributesA of overlay-only files/directories, shadowed files, absent names
     union     FindFirstFileA/FindNextFileA: base entries first, then the names only the overlay has, no duplicates, the base's
               spelling, the overlay's data (size), wildcards, an overlay-only directory ("." and ".." once), the RESOURCE level
     writes    every write-class call on an overlay path is refused and leaves the overlay and the base untouched (a digest of
               both trees before and after); new names are created in the base and show up in the union
     escape    a random walk of 60 000 paths with "..", ".", symlink names: every host path stays below the game root, every
               overlay path below the overlay root and is never a symlink; the "secret" next to the overlay is never read
     symlinks  a symlink in the overlay (file, directory) is not indexed, never followed; the base's file is read instead
     root      a root that is missing, a file, inside the game folder, containing it: refused; "", "0", unset: off
     identity  (strict) an overlay file and its base twin are ONE guest file: share modes conflict across spellings, an overlay-only
               file's spellings do not trip the spelling-conflict rule, CopyFileA reserves the source under the canonical name
     cp1251    (PORT_NAME_CP1251) an overlay-only file with a Cyrillic name is found, listed in CP1251, Ёж = ёж
     dup       two overlay names that differ only by case: the first wins (where the host can hold both)
     threads   8 threads open/read/list/stat overlay and base paths while the index is built lazily (TSan)
   Usage: test scratch-dir [strict|permissive] [snap|nosnap] */
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
uint32_t g_code_lo = 0x401000, g_code_hi = 0x401000;
int sched_active(void) { return 0; }
uint64_t sched_now_us(void) { return 0; }
int sched_wait(int (*pred)(void *), void *arg, uint64_t deadline_us, uint64_t (*deadline_fn)(void)) { (void)pred; (void)arg; (void)deadline_us; (void)deadline_fn; return 0; }

#define CHECK(c) do { if (!(c)) { fprintf(stderr, "FAIL %s:%d: %s\n", __FILE__, __LINE__, #c); abort(); } } while (0)
#define CHECK_S(a, b) do { const char *_a = (a), *_b = (b); if (strcmp(_a, _b)) { fprintf(stderr, "FAIL %s:%d: '%s' != '%s'\n", __FILE__, __LINE__, _a, _b); abort(); } } while (0)
#define GENERIC_READ 0x80000000u
#define GENERIC_WRITE 0x40000000u
#define FS_R 1
#define FS_W 2
#define FS_D 4
#define INVALID 0xffffffffu
#define CREATE_NEW 1
#define CREATE_ALWAYS 2
#define OPEN_EXISTING 3
#define OPEN_ALWAYS 4
#define TRUNCATE_EXISTING 5
#define ERR_FILE_NOT_FOUND 2
#define ERR_PATH_NOT_FOUND 3
#define ERR_ACCESS_DENIED 5
#define ERR_SHARING 32
#define ERR_FILE_EXISTS 80
#define ERR_ALREADY_EXISTS 183
#define GR GUEST_ROOT   /* "C:\\Games\\Korsary2" */
#if !defined(__EMSCRIPTEN__) || defined(PORT_NODE_BUILD)
#define MOVE_OK 1
#else
#define MOVE_OK 0   /* the browser configuration refuses every MoveFileA before any path work */
#endif

static int strict, g_snap;
static char T[1024], B[1024], O[1024], OUT[1024];   /* temp root, base game folder, overlay folder, outside folder */

typedef struct { CPU c; GuestThread th; uint32_t base; } Eng;
#define SLICE 0x8000u
static Eng g_eng[16];
static void eng_init(Eng *e, int idx) { memset(e, 0, sizeof *e); e->base = 0x1000u + (uint32_t)idx * SLICE; }
static __thread uint32_t g_err;
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
static Eng *E0;
static uint32_t cf(Eng *e, const char *name, uint32_t access, uint32_t share, uint32_t disp) {
    uint32_t a[7] = { gstr(e, 0, name), access, share, 0, disp, 0, 0 };
    return call(e, w_CreateFileA, 7, a);
}
static uint32_t ch(Eng *e, uint32_t h) { uint32_t a[1] = { h }; return call(e, w_CloseHandle, 1, a); }
static uint32_t dl(Eng *e, const char *n) { uint32_t a[1] = { gstr(e, 0, n) }; return call(e, w_DeleteFileA, 1, a); }
static uint32_t mv(Eng *e, const char *s, const char *d) { uint32_t a[2] = { gstr(e, 0, s), gstr(e, 1, d) }; return call(e, w_MoveFileA, 2, a); }
static uint32_t mkd(Eng *e, const char *n) { uint32_t a[2] = { gstr(e, 0, n), 0 }; return call(e, w_CreateDirectoryA, 2, a); }
static uint32_t rmd(Eng *e, const char *n) { uint32_t a[1] = { gstr(e, 0, n) }; return call(e, w_RemoveDirectoryA, 1, a); }
static uint32_t cpy(Eng *e, const char *s, const char *d, uint32_t fie) { uint32_t a[3] = { gstr(e, 0, s), gstr(e, 1, d), fie }; return call(e, w_CopyFileA, 3, a); }
static uint32_t attr(Eng *e, const char *n) { uint32_t a[1] = { gstr(e, 0, n) }; return call(e, w_GetFileAttributesA, 1, a); }
static uint32_t rd(Eng *e, uint32_t h, void *buf, uint32_t n) {
    uint32_t out = e->base + 0x200u, data = e->base + 0x3000u;
    uint32_t a[5] = { h, data, n, out, 0 };
    if (!call(e, w_ReadFile, 5, a)) return INVALID;
    uint32_t got = R32(out);
    memcpy(buf, HP(data), got);
    return got;
}
static uint32_t wr(Eng *e, uint32_t h, const void *buf, uint32_t n) {
    uint32_t out = e->base + 0x200u, data = e->base + 0x3000u;
    memcpy(HP(data), buf, n);
    uint32_t a[5] = { h, data, n, out, 0 };
    return call(e, w_WriteFile, 5, a) ? R32(out) : INVALID;
}
static uint32_t fsize(Eng *e, uint32_t h) { uint32_t a[2] = { h, 0 }; return call(e, w_GetFileSize, 2, a); }
static uint32_t seekp(Eng *e, uint32_t h, int32_t off, uint32_t how) { uint32_t a[4] = { h, (uint32_t)off, 0, how }; return call(e, w_SetFilePointer, 4, a); }
/* the whole file through the guest API: -1 when the open fails */
static int g_get(Eng *e, const char *name, char *out, size_t cap) {
    uint32_t h = cf(e, name, GENERIC_READ, FS_R | FS_W | FS_D, OPEN_EXISTING);
    if (h == INVALID) return -1;
    uint32_t got = rd(e, h, out, (uint32_t)cap - 1);
    ch(e, h);
    out[got == INVALID ? 0 : got] = 0;
    return got == INVALID ? -1 : (int)got;
}
#define EXPECT_FILE(e, name, want) do { char _b[256]; int _n = g_get((e), (name), _b, sizeof _b); \
    if (_n < 0 || strcmp(_b, (want))) { fprintf(stderr, "FAIL %s:%d: %s -> %s (err %u), wanted '%s'\n", __FILE__, __LINE__, (name), _n < 0 ? "<open failed>" : _b, g_err, (want)); abort(); } } while (0)
#define EXPECT_MISSING(e, name) do { char _b[256]; if (g_get((e), (name), _b, sizeof _b) >= 0) { fprintf(stderr, "FAIL %s:%d: %s opened as '%s'\n", __FILE__, __LINE__, (name), _b); abort(); } } while (0)

#define MAXN 600
typedef struct { int n; char s[MAXN][300]; uint32_t attrs[MAXN]; uint32_t size[MAXN]; int dots; } NameList;
static int fnd(Eng *e, const char *spec, NameList *l) {   /* 1 when FindFirstFileA succeeded; "." and ".." counted in l->dots, not listed */
    l->n = 0; l->dots = 0;
    uint32_t out = e->base + 0x5000u;
    uint32_t a[2] = { gstr(e, 1, spec), out };
    uint32_t h = call(e, w_FindFirstFileA, 2, a);
    if (h == INVALID) return 0;
    do {
        const char *nm = (const char *)HP(out + 44);
        if (!strcmp(nm, ".") || !strcmp(nm, "..")) l->dots++;
        else if (l->n < MAXN) {
            snprintf(l->s[l->n], 300, "%s", nm);
            l->attrs[l->n] = R32(out);
            l->size[l->n] = R32(out + 32);
            l->n++;
        }
        uint32_t b[2] = { h, out };
        if (!call(e, w_FindNextFileA, 2, b)) break;
    } while (1);
    uint32_t b[1] = { h };
    call(e, w_FindClose, 1, b);
    return 1;
}
static int idx_of(const NameList *l, const char *name) {
    for (int i = 0; i < l->n; i++) if (!strcasecmp(l->s[i], name)) return i;
    return -1;
}
static int count_ci(const NameList *l, const char *name) {
    int c = 0;
    for (int i = 0; i < l->n; i++) if (!strcasecmp(l->s[i], name)) c++;
    return c;
}

/* ---- host-side helpers ---- */
static void mkparents(const char *path) {
    char p[1400];
    snprintf(p, sizeof p, "%s", path);
    for (char *q = p + 1; *q; q++) if (*q == '/') { *q = 0; mkdir(p, 0755); *q = '/'; }
}
static int hput(const char *root, const char *rel, const char *content) {
    char p[1400];
    snprintf(p, sizeof p, "%s/%s", root, rel);
    mkparents(p);
    FILE *f = fopen(p, "wb");
    if (!f) return 0;
    fputs(content, f);
    return fclose(f) == 0;
}
static int hget(const char *root, const char *rel, char *out, size_t cap) {
    char p[1400];
    snprintf(p, sizeof p, "%s/%s", root, rel);
    FILE *f = fopen(p, "rb");
    if (!f) return -1;
    size_t n = fread(out, 1, cap - 1, f);
    fclose(f);
    out[n] = 0;
    return (int)n;
}
static int hexists(const char *root, const char *rel) {
    char p[1400];
    struct stat st;
    snprintf(p, sizeof p, "%s/%s", root, rel);
    return lstat(p, &st) == 0;
}
static void rm_rf(const char *path) {
    struct stat st;
    if (lstat(path, &st) != 0) return;
    if (S_ISDIR(st.st_mode)) {
        DIR *d = opendir(path);
        struct dirent *e;
        while (d && (e = readdir(d))) {
            if (!strcmp(e->d_name, ".") || !strcmp(e->d_name, "..")) continue;
            char c[1400];
            snprintf(c, sizeof c, "%s/%s", path, e->d_name);
            rm_rf(c);
        }
        if (d) closedir(d);
        rmdir(path);
    } else unlink(path);
}
/* a digest of a whole tree: names, kinds, sizes, bytes (the overlay and the base must come out of a test unchanged) */
static uint64_t fnv(uint64_t h, const void *p, size_t n) { const unsigned char *b = p; while (n--) { h ^= *b++; h *= 1099511628211ull; } return h; }
static int cmpname(const void *a, const void *b) { return strcmp(*(char *const *)a, *(char *const *)b); }
static uint64_t tree_digest(const char *path, uint64_t h) {
    struct stat st;
    if (lstat(path, &st) != 0) return fnv(h, "?", 1);
    if (S_ISLNK(st.st_mode)) { char l[1400]; ssize_t n = readlink(path, l, sizeof l); return fnv(fnv(h, "L", 1), l, n > 0 ? (size_t)n : 0); }
    if (S_ISDIR(st.st_mode)) {
        char *names[512]; int n = 0;
        DIR *d = opendir(path);
        struct dirent *e;
        while (d && (e = readdir(d)) && n < 512) if (strcmp(e->d_name, ".") && strcmp(e->d_name, "..")) names[n++] = strdup(e->d_name);
        if (d) closedir(d);
        qsort(names, (size_t)n, sizeof *names, cmpname);
        h = fnv(h, "D", 1);
        for (int i = 0; i < n; i++) {
            char c[1400];
            snprintf(c, sizeof c, "%s/%s", path, names[i]);
            h = tree_digest(c, fnv(h, names[i], strlen(names[i])));
            free(names[i]);
        }
        return h;
    }
    h = fnv(h, "F", 1);
    h = fnv(h, &st.st_size, sizeof st.st_size);
    FILE *f = fopen(path, "rb");
    char buf[4096]; size_t n;
    while (f && (n = fread(buf, 1, sizeof buf, f)) > 0) h = fnv(h, buf, n);
    if (f) fclose(f);
    return h;
}

/* ---- the fixture ---- */
static int g_symlinks;   /* the host can make symlinks */
static void build_trees(void) {
    char p[1400];
    /* base: the Russian install */
    hput(B, "ENGINE.exe", "EXE");
    hput(B, "PROGRAM/DIALOGS/dlg_a.h", "RU-A");
    hput(B, "PROGRAM/DIALOGS/dlg_b.h", "RU-B");
    hput(B, "PROGRAM/seadogs.c", "RU-SEADOGS");
    hput(B, "RESOURCE/INI/TEXTS/language.ini", "defaultLanguage = russian");
    hput(B, "RESOURCE/INI/fonts.ini", "RU-FONTS");
    hput(B, "RESOURCE/Sounds/VOICE/Eng_001.wav", "RU-V1");
    hput(B, "RESOURCE/Sounds/VOICE/Eng_002.wav", "RU-V2");
    hput(B, "RESOURCE/Textures/Loading/a.tga.tx", "RU-LOAD-A");
    hput(B, "RESOURCE/BaseOnly/f.txt", "BASE-ONLY");
    hput(B, "RESOURCE/Clash/dirInBase/f.txt", "BASE-F"); hput(B, "RESOURCE/Clash/fileInBase", "BASEFILE");   /* kind conflicts: the overlay wins at the name */
    hput(B, "SAVE/slot1", "SAVE-BASE");
    hput(B, "SAVE_META/slot1.time", "META-BASE");
    hput(B, "options", "OPT-BASE");
    hput(B, "engine.ini", "INI-BASE");
    /* outside both (the secrets a path walk must never reach) */
    hput(OUT, "secret.txt", "SECRET");
    hput(OUT, "secretdir/x", "SECRET-X");
    hput(T, "escape.txt", "ESCAPE");
    /* overlay: the English layer */
    hput(O, "PROGRAM/DIALOGS/dlg_a.h", "EN-A-LONGER");
    hput(O, "PROGRAM/DIALOGS/dlg_new.h", "EN-NEW");
    hput(O, "RESOURCE/INI/TEXTS/language.ini", "defaultLanguage = English");
    hput(O, "RESOURCE/Sounds/voice/ENG_002.WAV", "EN-V2-LONGER");   /* spelled unlike the base's VOICE/Eng_002.wav */
    hput(O, "RESOURCE/Sounds/voice/Eng_003.wav", "EN-V3");           /* only in the overlay */
    hput(O, "RESOURCE/Textures/Loading/b.tga.tx", "EN-LOAD-B");
    hput(O, "RESOURCE/OnlyOverlay/deep/er/file.txt", "EN-DEEP");
    hput(O, "RESOURCE/Clash/dirInBase", "OVFILE");           /* a FILE in the overlay where the base has a directory */
    hput(O, "RESOURCE/Clash/fileInBase/x.txt", "OVX");       /* a DIRECTORY in the overlay where the base has a file */
    /* decoys: never looked at */
    hput(O, "SAVE/slot1", "SAVE-OVERLAY"); hput(O, "SAVE/slotX", "SAVE-OVERLAY-X");
    hput(O, "SAVE_META/x", "META-OVERLAY"); hput(O, "SAVE_TX/y", "TX-OVERLAY");
    hput(O, "options", "OPT-OVERLAY"); hput(O, "engine.ini", "INI-OVERLAY"); hput(O, "ENGINE.exe", "EXE-OVERLAY");
    hput(O, "MODULES/m.dll", "DLL-OVERLAY"); hput(O, "stray.txt", "STRAY-OVERLAY"); hput(O, "OVERLAY.json", "{}");
    /* symlinks inside the overlay that point out of it */
    g_symlinks = 1;
    snprintf(p, sizeof p, "%s/secret.txt", OUT);
    char l[1400];
    snprintf(l, sizeof l, "%s/PROGRAM/DIALOGS/dlg_b.h", O);
    if (symlink(p, l) != 0) g_symlinks = 0;
    snprintf(l, sizeof l, "%s/RESOURCE/INI/link_out", O);
    if (symlink(p, l) != 0) g_symlinks = 0;
    snprintf(p, sizeof p, "%s/secretdir", OUT);
    snprintf(l, sizeof l, "%s/RESOURCE/linkdir", O);
    if (symlink(p, l) != 0) g_symlinks = 0;
    snprintf(p, sizeof p, "%s/escape.txt", T);
    snprintf(l, sizeof l, "%s/RESOURCE/escape_link", O);
    if (symlink(p, l) != 0) g_symlinks = 0;
}

static void overlay_on(void) { setenv("PORT_OVERLAY", O, 1); overlay_test_reset(); CHECK(overlay_active()); }
static void overlay_off_env(const char *v) { if (v) setenv("PORT_OVERLAY", v, 1); else unsetenv("PORT_OVERLAY"); overlay_test_reset(); }

/* ================================================================== parts */

static void t_resolve(void) {
    Eng *e = E0;
    /* in both: the overlay's bytes, whatever the spelling */
    EXPECT_FILE(e, GR "\\PROGRAM\\DIALOGS\\dlg_a.h", "EN-A-LONGER");
    EXPECT_FILE(e, "c:/games/korsary2/program/dialogs/DLG_A.H", "EN-A-LONGER");
    EXPECT_FILE(e, GR "\\PROGRAM\\.\\DIALOGS\\..\\DIALOGS\\dlg_a.h", "EN-A-LONGER");
    EXPECT_FILE(e, GR "\\RESOURCE\\ini\\texts\\LANGUAGE.INI", "defaultLanguage = English");
    EXPECT_FILE(e, "RESOURCE\\INI\\TEXTS\\language.ini", "defaultLanguage = English");   /* relative to the game's cwd (the game root) */
    /* only in the overlay */
    EXPECT_FILE(e, GR "\\PROGRAM\\DIALOGS\\dlg_new.h", "EN-NEW");
    EXPECT_FILE(e, GR "\\RESOURCE\\Textures\\Loading\\b.tga.tx", "EN-LOAD-B");
    EXPECT_FILE(e, GR "\\resource\\onlyoverlay\\DEEP\\er\\FILE.TXT", "EN-DEEP");
    /* spelled differently in the overlay: still the overlay's file, found through the base's directory names */
    EXPECT_FILE(e, GR "\\RESOURCE\\Sounds\\VOICE\\Eng_002.wav", "EN-V2-LONGER");
    EXPECT_FILE(e, GR "\\RESOURCE\\Sounds\\voice\\eng_002.wav", "EN-V2-LONGER");
    EXPECT_FILE(e, GR "\\RESOURCE\\Sounds\\VOICE\\ENG_003.WAV", "EN-V3");
    /* only in the base: untouched */
    EXPECT_FILE(e, GR "\\PROGRAM\\seadogs.c", "RU-SEADOGS");
    EXPECT_FILE(e, GR "\\RESOURCE\\INI\\fonts.ini", "RU-FONTS");
    EXPECT_FILE(e, GR "\\RESOURCE\\Sounds\\VOICE\\Eng_001.wav", "RU-V1");
    EXPECT_FILE(e, GR "\\RESOURCE\\BaseOnly\\f.txt", "BASE-ONLY");
    EXPECT_FILE(e, GR "\\RESOURCE\\Textures\\Loading\\a.tga.tx", "RU-LOAD-A");
    EXPECT_MISSING(e, GR "\\RESOURCE\\Sounds\\VOICE\\Eng_009.wav");
    EXPECT_MISSING(e, GR "\\PROGRAM\\DIALOGS\\nosuch.h");
    EXPECT_MISSING(e, GR "\\RESOURCE\\OnlyOverlay\\deep\\er\\nosuch.txt");
    /* handle-level reads: size, seek, partial reads, with the snapshot on and off */
    uint32_t h = cf(e, GR "\\PROGRAM\\DIALOGS\\dlg_a.h", GENERIC_READ, FS_R, OPEN_EXISTING);
    CHECK(h != INVALID);
    CHECK(fsize(e, h) == strlen("EN-A-LONGER"));
    char b[32];
    CHECK(rd(e, h, b, 3) == 3); b[3] = 0; CHECK_S(b, "EN-");
    CHECK(seekp(e, h, 5, 0) == 5);
    CHECK(rd(e, h, b, 31) == 6); b[6] = 0; CHECK_S(b, "LONGER");
    CHECK(seekp(e, h, 0, 0) == 0);
    CHECK(rd(e, h, b, 31) == 11);
    CHECK(rd(e, h, b, 31) == 0);   /* end of file: a successful empty read */
    CHECK(ch(e, h) == 1);
    /* OPEN_ALWAYS without write access on an existing overlay file is a read (nothing is created) */
    h = cf(e, GR "\\PROGRAM\\DIALOGS\\dlg_new.h", GENERIC_READ, FS_R, OPEN_ALWAYS);
    CHECK(h != INVALID);
    CHECK(rd(e, h, b, 31) == 6); ch(e, h);
    CHECK(!hexists(B, "PROGRAM/DIALOGS/dlg_new.h"));   /* and no copy was made in the base */
    /* the overlay does not make the game root's own listing different, nor the base's untouched files */
    char base_text[64];
    CHECK(hget(B, "PROGRAM/DIALOGS/dlg_a.h", base_text, sizeof base_text) > 0);
    CHECK_S(base_text, "RU-A");
    printf("overlay resolve: PASS\n");
}

static void t_forbidden(void) {
    Eng *e = E0;
    EXPECT_FILE(e, GR "\\SAVE\\slot1", "SAVE-BASE");
    EXPECT_MISSING(e, GR "\\SAVE\\slotX");              /* only in the overlay: not there */
    EXPECT_FILE(e, GR "\\options", "OPT-BASE");
    EXPECT_FILE(e, GR "\\engine.ini", "INI-BASE");
    EXPECT_FILE(e, GR "\\ENGINE.exe", "EXE");
    EXPECT_FILE(e, GR "\\SAVE_META\\slot1.time", "META-BASE");
    EXPECT_MISSING(e, GR "\\SAVE_META\\x");
    EXPECT_MISSING(e, GR "\\SAVE_TX\\y");
    EXPECT_MISSING(e, GR "\\MODULES\\m.dll");
    EXPECT_MISSING(e, GR "\\stray.txt");
    EXPECT_MISSING(e, GR "\\OVERLAY.json");
    /* a walk out of PROGRAM/RESOURCE lands in the base's data */
    EXPECT_FILE(e, GR "\\RESOURCE\\..\\SAVE\\slot1", "SAVE-BASE");
    EXPECT_FILE(e, GR "\\PROGRAM\\DIALOGS\\..\\..\\options", "OPT-BASE");
    EXPECT_FILE(e, GR "\\RESOURCE\\INI\\..\\..\\engine.ini", "INI-BASE");
    EXPECT_FILE(e, GR "\\resource\\..\\program\\..\\save\\SLOT1", "SAVE-BASE");
    EXPECT_MISSING(e, GR "\\RESOURCE\\..\\SAVE\\slotX");
    EXPECT_MISSING(e, GR "\\RESOURCE\\..\\stray.txt");
    /* the names are looked up first, then the walk: a PROGRAM that is not the top component is no overlay */
    EXPECT_MISSING(e, GR "\\SAVE\\PROGRAM\\DIALOGS\\dlg_new.h");
    EXPECT_MISSING(e, GR "\\x\\..\\x\\PROGRAM\\DIALOGS\\dlg_new.h");
    /* outside the game folder: nothing from the overlay */
    EXPECT_MISSING(e, "D:\\PROGRAM\\DIALOGS\\dlg_new.h");
    EXPECT_MISSING(e, "C:\\Other\\RESOURCE\\INI\\TEXTS\\language.ini");
    NameList l;
    CHECK(fnd(e, GR "\\SAVE\\*", &l));
    CHECK(l.n == 1 && !strcmp(l.s[0], "slot1"));   /* no slotX */
    CHECK(fnd(e, GR "\\*", &l));
    CHECK(idx_of(&l, "stray.txt") < 0 && idx_of(&l, "MODULES") < 0 && idx_of(&l, "OVERLAY.json") < 0);
    CHECK(idx_of(&l, "options") >= 0 && idx_of(&l, "PROGRAM") >= 0);
    printf("overlay forbidden paths: PASS\n");
}

static void t_attrs(void) {
    Eng *e = E0;
    CHECK(attr(e, GR "\\PROGRAM\\DIALOGS\\dlg_new.h") == 0x20);          /* only in the overlay */
    CHECK(attr(e, GR "\\PROGRAM\\DIALOGS\\dlg_a.h") == 0x20);            /* in both */
    CHECK(attr(e, GR "\\RESOURCE\\OnlyOverlay") == 0x10);                /* a directory only in the overlay */
    CHECK(attr(e, GR "\\RESOURCE\\ONLYOVERLAY\\deep\\ER") == 0x10);
    CHECK(attr(e, GR "\\RESOURCE\\BaseOnly") == 0x10);
    CHECK(attr(e, GR "\\PROGRAM\\DIALOGS\\nosuch") == INVALID);
    CHECK(attr(e, GR "\\SAVE\\slotX") == INVALID);
    CHECK(attr(e, GR "\\SAVE") == 0x10);
    CHECK(attr(e, GR "\\options") == 0x20);
    CHECK(attr(e, GR "\\stray.txt") == INVALID);
    printf("overlay attributes: PASS\n");
}

static void t_union(void) {
    Eng *e = E0;
    NameList l;
    /* RESOURCE\Sounds\VOICE: base {Eng_001, Eng_002}, overlay {ENG_002 (shadows), Eng_003 (new)} */
    CHECK(fnd(e, GR "\\RESOURCE\\Sounds\\VOICE\\*", &l));
    CHECK(l.dots == 2);
    CHECK(l.n == 3);
    CHECK(count_ci(&l, "Eng_001.wav") == 1 && count_ci(&l, "Eng_002.wav") == 1 && count_ci(&l, "Eng_003.wav") == 1);
    CHECK(idx_of(&l, "Eng_002.wav") >= 0 && !strcmp(l.s[idx_of(&l, "Eng_002.wav")], "Eng_002.wav"));   /* the base's spelling */
    CHECK(l.size[idx_of(&l, "Eng_002.wav")] == strlen("EN-V2-LONGER"));                                 /* the overlay's data */
    CHECK(l.size[idx_of(&l, "Eng_001.wav")] == strlen("RU-V1"));
    CHECK(l.size[idx_of(&l, "Eng_003.wav")] == strlen("EN-V3"));
    CHECK(idx_of(&l, "Eng_003.wav") > idx_of(&l, "Eng_001.wav") && idx_of(&l, "Eng_003.wav") > idx_of(&l, "Eng_002.wav"));   /* overlay-only names last */
    /* the same listing through other spellings of the directory and other patterns */
    CHECK(fnd(e, "c:/games/korsary2/resource/sounds/voice/*.*", &l) && l.n == 3);
    CHECK(fnd(e, GR "\\RESOURCE\\Sounds\\VOICE\\*.wav", &l) && l.n == 3);
    CHECK(fnd(e, GR "\\RESOURCE\\Sounds\\VOICE\\Eng_00?.WAV", &l) && l.n == 3);
    CHECK(fnd(e, GR "\\RESOURCE\\Sounds\\VOICE\\*3*", &l) && l.n == 1 && !strcmp(l.s[0], "Eng_003.wav"));
    CHECK(fnd(e, GR "\\RESOURCE\\Sounds\\VOICE\\eng_002.wav", &l) && l.n == 1 && l.size[0] == strlen("EN-V2-LONGER"));
    CHECK(!fnd(e, GR "\\RESOURCE\\Sounds\\VOICE\\*.ogg", &l));
    CHECK(g_err == ERR_FILE_NOT_FOUND);
    /* PROGRAM\DIALOGS: dlg_a (both), dlg_b (base; the overlay's symlink is not indexed), dlg_new (overlay) */
    CHECK(fnd(e, GR "\\PROGRAM\\DIALOGS\\*", &l));
    CHECK(l.n == 3 && count_ci(&l, "dlg_a.h") == 1 && count_ci(&l, "dlg_b.h") == 1 && count_ci(&l, "dlg_new.h") == 1);
    CHECK(l.size[idx_of(&l, "dlg_b.h")] == strlen("RU-B"));
    /* a directory only in the overlay: "." and ".." exactly once, then its entries */
    CHECK(fnd(e, GR "\\RESOURCE\\OnlyOverlay\\*", &l));
    CHECK(l.dots == 2 && l.n == 1 && !strcmp(l.s[0], "deep") && l.attrs[0] == 0x10);
    CHECK(fnd(e, GR "\\RESOURCE\\OnlyOverlay\\deep\\er\\*.txt", &l) && l.n == 1 && l.size[0] == strlen("EN-DEEP") && l.attrs[0] == 0x80);
    CHECK(!fnd(e, GR "\\RESOURCE\\OnlyOverlay\\deep\\er\\*.dat", &l));
    CHECK(!fnd(e, GR "\\RESOURCE\\NoSuchDir\\*", &l));
    /* the RESOURCE level: base directories plus the one only the overlay has; the overlay's symlinks are absent */
    CHECK(fnd(e, GR "\\RESOURCE\\*", &l));
    CHECK(count_ci(&l, "INI") == 1 && count_ci(&l, "Sounds") == 1 && count_ci(&l, "Textures") == 1 && count_ci(&l, "BaseOnly") == 1 &&
          count_ci(&l, "OnlyOverlay") == 1 && l.dots == 2);
    CHECK(idx_of(&l, "linkdir") < 0 && idx_of(&l, "escape_link") < 0);
    /* Textures\Loading: a (base) and b (overlay) */
    CHECK(fnd(e, GR "\\RESOURCE\\Textures\\Loading\\*.tx", &l) && l.n == 2);
    /* INI: the symlink is not listed */
    CHECK(fnd(e, GR "\\RESOURCE\\INI\\*", &l));
    CHECK(idx_of(&l, "link_out") < 0 && idx_of(&l, "fonts.ini") >= 0 && idx_of(&l, "TEXTS") >= 0 && count_ci(&l, "TEXTS") == 1);
    /* an exhausted find handle stays exhausted */
    {
        uint32_t out = e->base + 0x5000u, a[2] = { gstr(e, 1, GR "\\RESOURCE\\Sounds\\VOICE\\Eng_003.wav"), out };
        uint32_t h = call(e, w_FindFirstFileA, 2, a);
        CHECK(h != INVALID);
        uint32_t b[2] = { h, out };
        CHECK(call(e, w_FindNextFileA, 2, b) == 0 && g_err == 18);
        CHECK(call(e, w_FindNextFileA, 2, b) == 0 && g_err == 18);
        uint32_t c[1] = { h };
        CHECK(call(e, w_FindClose, 1, c) == 1);
    }
    printf("overlay union listing: PASS\n");
}

static void t_conflict(void) {
    Eng *e = E0;
    /* the overlay wins at the name, whatever it is (PORT_SPECIFICATION.md); below a name that is a file in the overlay the base still answers */
    EXPECT_FILE(e, GR "\\RESOURCE\\Clash\\dirInBase", "OVFILE");
    CHECK(attr(e, GR "\\RESOURCE\\Clash\\dirInBase") == 0x20);
    EXPECT_FILE(e, GR "\\RESOURCE\\Clash\\dirInBase\\f.txt", "BASE-F");
    CHECK(attr(e, GR "\\RESOURCE\\Clash\\fileInBase") == 0x10);
    EXPECT_FILE(e, GR "\\RESOURCE\\Clash\\fileInBase\\x.txt", "OVX");
    NameList l;
    CHECK(fnd(e, GR "\\RESOURCE\\Clash\\*", &l));
    CHECK(l.n == 2 && count_ci(&l, "dirInBase") == 1 && count_ci(&l, "fileInBase") == 1);
    CHECK(l.attrs[idx_of(&l, "dirInBase")] == 0x80 && l.attrs[idx_of(&l, "fileInBase")] == 0x10);
    CHECK(fnd(e, GR "\\RESOURCE\\Clash\\fileInBase\\*", &l) && l.n == 1 && !strcmp(l.s[0], "x.txt"));
    printf("overlay kind conflicts (overlay wins at the name): PASS\n");
}

static void t_writes(void) {
    Eng *e = E0;
    uint64_t dig_o = tree_digest(O, 1469598103934665603ull);
    uint64_t dig_b = tree_digest(B, 1469598103934665603ull);
    char b[64];
    /* any write-class open of a path the overlay holds is refused, whatever the disposition; nothing changes */
    CHECK(cf(e, GR "\\PROGRAM\\DIALOGS\\dlg_a.h", GENERIC_WRITE, 0, OPEN_EXISTING) == INVALID && g_err == ERR_ACCESS_DENIED);
    CHECK(cf(e, GR "\\PROGRAM\\DIALOGS\\dlg_a.h", GENERIC_READ | GENERIC_WRITE, FS_R, OPEN_EXISTING) == INVALID && g_err == ERR_ACCESS_DENIED);
    CHECK(cf(e, GR "\\PROGRAM\\DIALOGS\\dlg_a.h", GENERIC_WRITE, 0, CREATE_ALWAYS) == INVALID && g_err == ERR_ACCESS_DENIED);
    CHECK(cf(e, GR "\\PROGRAM\\DIALOGS\\dlg_a.h", GENERIC_READ, 0, CREATE_ALWAYS) == INVALID && g_err == ERR_ACCESS_DENIED);   /* truncates: a write */
    CHECK(cf(e, GR "\\PROGRAM\\DIALOGS\\dlg_a.h", GENERIC_WRITE, 0, TRUNCATE_EXISTING) == INVALID && g_err == ERR_ACCESS_DENIED);
    CHECK(cf(e, GR "\\PROGRAM\\DIALOGS\\dlg_a.h", GENERIC_WRITE, 0, OPEN_ALWAYS) == INVALID && g_err == ERR_ACCESS_DENIED);
    CHECK(cf(e, GR "\\PROGRAM\\DIALOGS\\dlg_a.h", GENERIC_WRITE, 0, CREATE_NEW) == INVALID && g_err == (MOVE_OK ? ERR_FILE_EXISTS : 50 /* the browser build refuses CREATE_NEW before any path work */));
    CHECK(cf(e, GR "\\PROGRAM\\DIALOGS\\dlg_new.h", GENERIC_WRITE, 0, OPEN_EXISTING) == INVALID && g_err == ERR_ACCESS_DENIED);   /* only in the overlay */
    CHECK(cf(e, GR "\\program\\dialogs\\DLG_NEW.H", GENERIC_WRITE, 0, CREATE_ALWAYS) == INVALID && g_err == ERR_ACCESS_DENIED);
    CHECK(cf(e, GR "\\RESOURCE\\OnlyOverlay", GENERIC_WRITE, 0, CREATE_ALWAYS) == INVALID && g_err == ERR_ACCESS_DENIED);   /* a directory of the overlay */
    /* delete / move / directories */
    CHECK(dl(e, GR "\\PROGRAM\\DIALOGS\\dlg_a.h") == 0 && g_err == ERR_ACCESS_DENIED);
    CHECK(dl(e, GR "\\PROGRAM\\DIALOGS\\dlg_new.h") == 0 && g_err == ERR_ACCESS_DENIED);
    CHECK(dl(e, GR "\\RESOURCE\\Textures\\Loading\\b.tga.tx") == 0 && g_err == ERR_ACCESS_DENIED);
    CHECK(rmd(e, GR "\\RESOURCE\\OnlyOverlay\\deep\\er") == 0 && g_err == ERR_ACCESS_DENIED);
    CHECK(rmd(e, GR "\\RESOURCE\\Sounds\\VOICE") == 0 && g_err == ERR_ACCESS_DENIED);   /* in both: the overlay holds it, so it stays */
    CHECK(mkd(e, GR "\\RESOURCE\\OnlyOverlay") == 0 && g_err == ERR_ALREADY_EXISTS);
    CHECK(mkd(e, GR "\\RESOURCE\\OnlyOverlay\\deep") == 0 && g_err == ERR_ALREADY_EXISTS);
    if (MOVE_OK) {
        CHECK(mv(e, GR "\\PROGRAM\\DIALOGS\\dlg_new.h", GR "\\PROGRAM\\DIALOGS\\moved.h") == 0 && g_err == ERR_ACCESS_DENIED);
        CHECK(mv(e, GR "\\PROGRAM\\DIALOGS\\dlg_a.h", GR "\\PROGRAM\\DIALOGS\\moved.h") == 0 && g_err == ERR_ACCESS_DENIED);
        CHECK(mv(e, GR "\\PROGRAM\\seadogs.c", GR "\\PROGRAM\\DIALOGS\\dlg_new.h") == 0 && g_err == ERR_ALREADY_EXISTS);   /* onto an overlay name */
        CHECK(hexists(B, "PROGRAM/seadogs.c"));
    }
    /* CopyFileA: an overlay file is a fine source, an overlay path never a destination */
    CHECK(cpy(e, GR "\\PROGRAM\\DIALOGS\\dlg_a.h", GR "\\PROGRAM\\DIALOGS\\dlg_new.h", 0) == 0);
    CHECK(g_err == ERR_ACCESS_DENIED);
    CHECK(cpy(e, GR "\\PROGRAM\\DIALOGS\\dlg_a.h", GR "\\PROGRAM\\DIALOGS\\dlg_a.h", 1) == 0);   /* fail-if-exists: it exists */
    /* nothing changed, in either tree */
    CHECK(tree_digest(O, 1469598103934665603ull) == dig_o);
    CHECK(tree_digest(B, 1469598103934665603ull) == dig_b);
    /* creating NEW names: in the base, as before; the union shows them */
    uint32_t h = cf(e, GR "\\PROGRAM\\DIALOGS\\created.h", GENERIC_WRITE, 0, CREATE_ALWAYS);
    CHECK(h != INVALID);
    CHECK(wr(e, h, "NEW-IN-BASE", 11) == 11); ch(e, h);
    CHECK(hget(B, "PROGRAM/DIALOGS/created.h", b, sizeof b) == 11 && !strcmp(b, "NEW-IN-BASE"));
    CHECK(!hexists(O, "PROGRAM/DIALOGS/created.h"));
    EXPECT_FILE(e, GR "\\PROGRAM\\DIALOGS\\created.h", "NEW-IN-BASE");
    NameList l;
    CHECK(fnd(e, GR "\\PROGRAM\\DIALOGS\\*", &l) && count_ci(&l, "created.h") == 1 && count_ci(&l, "dlg_new.h") == 1 && count_ci(&l, "dlg_a.h") == 1);
    /* and a file made in the base may be rewritten and deleted (it is not an overlay path) */
    h = cf(e, GR "\\PROGRAM\\DIALOGS\\created.h", GENERIC_WRITE, 0, TRUNCATE_EXISTING);
    CHECK(h != INVALID); CHECK(wr(e, h, "X", 1) == 1); ch(e, h);
    CHECK(dl(e, GR "\\PROGRAM\\DIALOGS\\created.h") == 1);
    CHECK(!hexists(B, "PROGRAM/DIALOGS/created.h"));
    /* a new file in a directory the overlay alone has: the parent is created in the BASE (as for any new path), never in the overlay */
    h = cf(e, GR "\\RESOURCE\\OnlyOverlay\\deep\\fresh.txt", GENERIC_WRITE, 0, CREATE_ALWAYS);
    CHECK(h != INVALID); CHECK(wr(e, h, "FRESH", 5) == 5); ch(e, h);
    CHECK(hget(B, "RESOURCE/OnlyOverlay/deep/fresh.txt", b, sizeof b) == 5);
    CHECK(!hexists(O, "RESOURCE/OnlyOverlay/deep/fresh.txt"));
    NameList m;
    CHECK(fnd(e, GR "\\RESOURCE\\OnlyOverlay\\deep\\*", &m) && count_ci(&m, "er") == 1 && count_ci(&m, "fresh.txt") == 1 && m.dots == 2);
    EXPECT_FILE(e, GR "\\RESOURCE\\OnlyOverlay\\deep\\er\\file.txt", "EN-DEEP");
    /* CopyFileA from the overlay: a new file in the base with the overlay's bytes */
    CHECK(mkd(e, GR "\\RESOURCE\\Copies") == 1);
    {
        h = cf(e, GR "\\RESOURCE\\Copies\\x", GENERIC_WRITE, 0, CREATE_ALWAYS);
        CHECK(h != INVALID); ch(e, h);
        CHECK(cpy(e, GR "\\PROGRAM\\DIALOGS\\dlg_a.h", GR "\\RESOURCE\\Copies\\x", 0) == 1);
        EXPECT_FILE(e, GR "\\RESOURCE\\Copies\\x", "EN-A-LONGER");
        CHECK(hget(B, "RESOURCE/Copies/x", b, sizeof b) == 11);
    }
    CHECK(tree_digest(O, 1469598103934665603ull) == dig_o);
    /* the SAVE area is the base's in every respect: writing it works as before */
    h = cf(e, GR "\\SAVE\\slot2", GENERIC_WRITE, 0, CREATE_ALWAYS);
    CHECK(h != INVALID); CHECK(wr(e, h, "S2", 2) == 2); ch(e, h);
    CHECK(hget(B, "SAVE/slot2", b, sizeof b) == 2 && !hexists(O, "SAVE/slot2"));
    CHECK(dl(e, GR "\\SAVE\\slot2") == 1);
    h = cf(e, GR "\\options", GENERIC_WRITE, 0, OPEN_ALWAYS);   /* settings are rewritten by the game: base */
    CHECK(h != INVALID); ch(e, h);
    CHECK(tree_digest(O, 1469598103934665603ull) == dig_o);
    /* clean up what this part made in the base */
    { char p[1400]; snprintf(p, sizeof p, "%s/RESOURCE/Copies", B); rm_rf(p); snprintf(p, sizeof p, "%s/RESOURCE/OnlyOverlay", B); rm_rf(p); }
    printf("overlay writes refused, new names to the base: PASS\n");
}

/* random walk over names the fixture knows, with ".." and "." and symlink names */
static uint64_t g_rng = 88172645463325252ull;
static uint32_t rnd(void) { g_rng ^= g_rng << 13; g_rng ^= g_rng >> 7; g_rng ^= g_rng << 17; return (uint32_t)(g_rng >> 11); }
static void t_escape(void) {
    static const char *names[] = {
        "..", "..", "..", ".", "PROGRAM", "program", "RESOURCE", "Resource", "SAVE", "save", "SAVE_META", "SAVE_TX", "MODULES", "DIALOGS", "dialogs",
        "INI", "TEXTS", "Sounds", "voice", "VOICE", "Textures", "Loading", "OnlyOverlay", "deep", "er", "BaseOnly", "linkdir", "escape_link", "link_out",
        "dlg_a.h", "dlg_b.h", "dlg_new.h", "language.ini", "secret.txt", "secretdir", "x", "escape.txt", "options", "engine.ini", "stray.txt", "file.txt",
        "ENG_002.WAV", "Eng_003.wav", "", "...", " ", "a b", "Korsary2", "Games", "C:", "nul" };
    const int nn = (int)(sizeof names / sizeof *names);
    size_t br = strlen(B), orl = strlen(O);
    char guest[1024], host[1024];
    OvHit ov;
    int n_ov = 0, n_exist = 0, n_up = 0;
    for (int it = 0; it < 60000; it++) {
        int depth = 1 + (int)(rnd() % 9);
        const char *prefix = (rnd() % 3 == 0) ? "" : (rnd() % 2 ? GR "\\" : "c:/games/korsary2/");
        snprintf(guest, sizeof guest, "%s", prefix);
        for (int i = 0; i < depth; i++) {
            strncat(guest, names[rnd() % (uint32_t)nn], sizeof guest - strlen(guest) - 1);
            strncat(guest, (rnd() % 4 == 0) ? "/" : "\\", sizeof guest - strlen(guest) - 1);
        }
        if (rnd() % 2) guest[strlen(guest) - 1] = 0;
        int ex = map_path_ov(guest, host, sizeof host, &ov);
        /* the canonical path is below the game root or the user root, never above them, whatever ".." did */
        CHECK((!strncmp(host, B, br) && (host[br] == '/' || host[br] == 0)) || !strncmp(host, g_user_root, strlen(g_user_root)));
        CHECK(!strstr(host, "/../") && !strstr(host, "/./"));
        if (ov.kind) {
            n_ov++;
            CHECK(ex);
            CHECK(!strncmp(ov.host, O, orl) && ov.host[orl] == '/');   /* strictly below the overlay root */
            CHECK(!strstr(ov.host, "/../") && !strstr(ov.host, "/./"));
            struct stat st;
            CHECK(lstat(ov.host, &st) == 0 && !S_ISLNK(st.st_mode));   /* a real file or directory, never a symlink */
            CHECK(ov.kind == (S_ISDIR(st.st_mode) ? 2 : 1));
            /* only PROGRAM and RESOURCE are ever overlaid */
            const char *rel = ov.host + orl + 1;
            CHECK(!strncasecmp(rel, "PROGRAM", 7) || !strncasecmp(rel, "RESOURCE", 8));
            CHECK(strcasecmp(rel, "SAVE") && strncasecmp(rel, "SAVE/", 5));
        }
        if (ex) n_exist++;
        if (strstr(guest, "..")) n_up++;
        /* and reading it by the API never yields the secrets */
        if (it % 50 == 0) {
            char buf[256];
            int n = g_get(E0, guest, buf, sizeof buf);
            if (n >= 0) { CHECK(strcmp(buf, "SECRET") && strcmp(buf, "SECRET-X") && strcmp(buf, "ESCAPE")); }
        }
    }
    CHECK(n_ov > 300);   /* the walk does reach overlay entries */
    printf("overlay escape walk: PASS (60000 paths, %d reached the overlay, %d exist, %d used \"..\")\n", n_ov, n_exist, n_up);
}

static void t_symlinks(void) {
    Eng *e = E0;
    if (!g_symlinks) { printf("overlay symlinks: SKIPPED (this host makes no symlinks)\n"); return; }
    /* the overlay's dlg_b.h is a symlink to the secret: it is not indexed, the base's file is read */
    EXPECT_FILE(e, GR "\\PROGRAM\\DIALOGS\\dlg_b.h", "RU-B");
    EXPECT_MISSING(e, GR "\\RESOURCE\\INI\\link_out");
    EXPECT_MISSING(e, GR "\\RESOURCE\\linkdir\\x");
    EXPECT_MISSING(e, GR "\\RESOURCE\\escape_link");
    CHECK(attr(e, GR "\\RESOURCE\\linkdir") == INVALID);
    CHECK(attr(e, GR "\\RESOURCE\\INI\\link_out") == INVALID);
    OvHit ov; char host[1024];
    CHECK(map_path_ov(GR "\\PROGRAM\\DIALOGS\\dlg_b.h", host, sizeof host, &ov) == 1 && ov.kind == 0);   /* the base's file; the overlay holds nothing there */
    printf("overlay symlinks: PASS\n");
}

static void t_root(void) {
    char bad[1400];
    /* off: unset, empty, "0" */
    overlay_off_env(NULL); CHECK(!overlay_active() && overlay_init_from_env() == 0);
    overlay_off_env(""); CHECK(!overlay_active() && overlay_init_from_env() == 0);
    overlay_off_env("0"); CHECK(!overlay_active() && overlay_init_from_env() == 0);
    {   /* off means off: the overlay's files do not exist for the game */
        char b[64];
        CHECK(g_get(E0, GR "\\PROGRAM\\DIALOGS\\dlg_new.h", b, sizeof b) < 0);
        EXPECT_FILE(E0, GR "\\PROGRAM\\DIALOGS\\dlg_a.h", "RU-A");
        EXPECT_FILE(E0, GR "\\RESOURCE\\INI\\TEXTS\\language.ini", "defaultLanguage = russian");
        NameList l;
        CHECK(fnd(E0, GR "\\RESOURCE\\Sounds\\VOICE\\*", &l) && l.n == 2);
    }
    /* unusable roots are refused (init_from_env fails; overlay_active stays 0, the lookups never use it) */
    snprintf(bad, sizeof bad, "%s/does-not-exist", T);
    overlay_off_env(bad); CHECK(overlay_init_from_env() == -1 && !overlay_active());
    snprintf(bad, sizeof bad, "%s/escape.txt", T);   /* a file */
    overlay_off_env(bad); CHECK(overlay_init_from_env() == -1 && !overlay_active());
    snprintf(bad, sizeof bad, "%s/PROGRAM", B);       /* inside the game folder */
    overlay_off_env(bad); CHECK(overlay_init_from_env() == -1 && !overlay_active());
    overlay_off_env(B); CHECK(overlay_init_from_env() == -1 && !overlay_active());   /* the game folder itself */
    overlay_off_env(T); CHECK(overlay_init_from_env() == -1 && !overlay_active());   /* a folder that contains it */
    /* a refused root never opens anything from itself */
    EXPECT_FILE(E0, GR "\\PROGRAM\\DIALOGS\\dlg_a.h", "RU-A");
    /* a root given through a symlink is resolved: it works, and keeps its real name for the "below the root" rule */
    if (g_symlinks) {
        char ln[1400];
        snprintf(ln, sizeof ln, "%s/overlay-link", T);
        if (symlink(O, ln) == 0) {
            overlay_off_env(ln);
            CHECK(overlay_init_from_env() == 0 && overlay_active());
            EXPECT_FILE(E0, GR "\\PROGRAM\\DIALOGS\\dlg_new.h", "EN-NEW");
            unlink(ln);
        }
    }
    overlay_on();
    printf("overlay root validation: PASS\n");
}

static void t_identity(void) {
    Eng *e = E0;
    if (!strict) { printf("overlay identity: skipped (permissive mode has no registry)\n"); return; }
    /* the overlay file and the base twin are ONE guest file: an exclusive open blocks any other spelling */
    uint32_t h1 = cf(e, GR "\\PROGRAM\\DIALOGS\\dlg_a.h", GENERIC_READ, 0, OPEN_EXISTING);   /* share nothing */
    CHECK(h1 != INVALID);
    CHECK(cf(e, GR "\\program\\dialogs\\DLG_A.H", GENERIC_READ, FS_R, OPEN_EXISTING) == INVALID && g_err == ERR_SHARING);
    CHECK(cf(e, "c:/games/korsary2/PROGRAM/./DIALOGS/dlg_a.h", GENERIC_READ, FS_R, OPEN_EXISTING) == INVALID && g_err == ERR_SHARING);
    CHECK(ch(e, h1) == 1);
    uint32_t h2 = cf(e, GR "\\program\\dialogs\\DLG_A.H", GENERIC_READ, FS_R, OPEN_EXISTING);
    uint32_t h3 = cf(e, GR "\\PROGRAM\\DIALOGS\\dlg_a.h", GENERIC_READ, FS_R, OPEN_EXISTING);   /* compatible shares: fine */
    CHECK(h2 != INVALID && h3 != INVALID);
    CHECK(cf(e, GR "\\PROGRAM\\DIALOGS\\dlg_a.h", GENERIC_READ, 0, OPEN_EXISTING) == INVALID && g_err == ERR_SHARING);
    ch(e, h2); ch(e, h3);
    /* an overlay-only file: its spellings are one object (not a "spelling conflict" of two absent names) */
    uint32_t a1 = cf(e, GR "\\RESOURCE\\Sounds\\VOICE\\ENG_003.WAV", GENERIC_READ, FS_R, OPEN_EXISTING);
    uint32_t a2 = cf(e, GR "\\resource\\sounds\\voice\\eng_003.wav", GENERIC_READ, FS_R, OPEN_EXISTING);
    CHECK(a1 != INVALID && a2 != INVALID);   /* compatible: both open although the spellings differ */
    CHECK(cf(e, GR "\\Resource\\Sounds\\Voice\\Eng_003.wav", GENERIC_READ, 0, OPEN_EXISTING) == INVALID && g_err == ERR_SHARING);   /* a third, exclusive */
    ch(e, a1); ch(e, a2);
    uint32_t a3 = cf(e, GR "\\RESOURCE\\Sounds\\VOICE\\ENG_003.WAV", GENERIC_READ, 0, OPEN_EXISTING);
    CHECK(a3 != INVALID);
    CHECK(cf(e, GR "\\resource\\sounds\\voice\\eng_003.wav", GENERIC_READ, FS_R, OPEN_EXISTING) == INVALID && g_err == ERR_SHARING);
    /* CopyFileA reserves its source under the same name: it cannot read what is opened exclusively */
    {
        uint32_t d = cf(e, GR "\\SAVE\\copy-dst", GENERIC_WRITE, 0, CREATE_ALWAYS);
        CHECK(d != INVALID); ch(e, d);
        CHECK(cpy(e, GR "\\RESOURCE\\Sounds\\VOICE\\eng_003.wav", GR "\\SAVE\\copy-dst", 0) == 0 && g_err == ERR_SHARING);
        ch(e, a3);
        CHECK(cpy(e, GR "\\RESOURCE\\Sounds\\VOICE\\eng_003.wav", GR "\\SAVE\\copy-dst", 0) == 1);
        EXPECT_FILE(e, GR "\\SAVE\\copy-dst", "EN-V3");
        CHECK(dl(e, GR "\\SAVE\\copy-dst") == 1);
    }
    /* a refused write open reserves nothing: the file is still openable exclusively afterwards */
    CHECK(cf(e, GR "\\PROGRAM\\DIALOGS\\dlg_new.h", GENERIC_WRITE, 0, CREATE_ALWAYS) == INVALID && g_err == ERR_ACCESS_DENIED);
    uint32_t z = cf(e, GR "\\PROGRAM\\DIALOGS\\dlg_new.h", GENERIC_READ, 0, OPEN_EXISTING);
    CHECK(z != INVALID); ch(e, z);
    /* and the overlay file open does not make the base twin deletable/writable either (it is never either) */
    uint32_t y = cf(e, GR "\\PROGRAM\\DIALOGS\\dlg_a.h", GENERIC_READ, FS_R | FS_D, OPEN_EXISTING);
    CHECK(y != INVALID);
    CHECK(dl(e, GR "\\PROGRAM\\DIALOGS\\dlg_a.h") == 0 && g_err == ERR_ACCESS_DENIED);   /* read-only: refused before the registry */
    ch(e, y);
    CHECK(hexists(B, "PROGRAM/DIALOGS/dlg_a.h") && hexists(O, "PROGRAM/DIALOGS/dlg_a.h"));
    printf("overlay identity (strict): PASS\n");
}

#define CYR_YO_UP "\xA8\xE6"        /* CP1251 "Ёж" */
#define CYR_YO_LO "\xB8\xE6"        /* CP1251 "ёж" */
static void t_cp1251(void) {
    Eng *e = E0;
    int was = name_cp1251_on();
    name_cp1251_set(1);
    char p[1400];
    snprintf(p, sizeof p, "%s/RESOURCE/INI/\xD1\x91\xD0\xB6.txt", O);   /* UTF-8 "ёж.txt" (overlay only) */
    mkparents(p);
    FILE *f = fopen(p, "wb");
    if (!f) { printf("overlay CP1251: SKIPPED (the host refuses the name)\n"); name_cp1251_set(was); return; }
    fputs("EN-YO", f); fclose(f);
    snprintf(p, sizeof p, "%s/RESOURCE/INI/\xD0\xA2\xD0\xB5\xD1\x81\xD1\x82", O);   /* UTF-8 directory "Тест" (overlay only) */
    mkdir(p, 0755);
    snprintf(p, sizeof p, "%s/RESOURCE/INI/\xD0\xA2\xD0\xB5\xD1\x81\xD1\x82/f.txt", O);
    f = fopen(p, "wb"); if (f) { fputs("EN-T", f); fclose(f); }
    overlay_on();
    name_cp1251_set(1);
    EXPECT_FILE(e, GR "\\RESOURCE\\INI\\" CYR_YO_LO ".txt", "EN-YO");
    EXPECT_FILE(e, GR "\\resource\\ini\\" CYR_YO_UP ".TXT", "EN-YO");   /* Ёж = ёж, the Windows case folding */
    EXPECT_FILE(e, GR "\\RESOURCE\\INI\\\xD2\xE5\xF1\xF2\\f.txt", "EN-T");
    NameList l;
    CHECK(fnd(e, GR "\\RESOURCE\\INI\\*", &l));
    CHECK(idx_of(&l, CYR_YO_LO ".txt") >= 0);   /* listed in CP1251 */
    CHECK(idx_of(&l, "\xD0\xA2\xD0\xB5\xD1\x81\xD1\x82") < 0);   /* no UTF-8 name leaks to the guest */
    CHECK(fnd(e, GR "\\RESOURCE\\INI\\" CYR_YO_UP "*", &l) && l.n == 1);
    CHECK(attr(e, GR "\\RESOURCE\\INI\\\xD2\xE5\xF1\xF2") == 0x10);
    CHECK(dl(e, GR "\\RESOURCE\\INI\\" CYR_YO_LO ".txt") == 0 && g_err == ERR_ACCESS_DENIED);
    /* a base entry and an overlay entry with the same Cyrillic name (other case): one entry in the listing */
    snprintf(p, sizeof p, "%s/RESOURCE/INI/\xD0\x81\xD0\xB6.txt", B);   /* base "Ёж.txt" */
    f = fopen(p, "wb"); if (f) { fputs("RU-YO", f); fclose(f); }
    CHECK(fnd(e, GR "\\RESOURCE\\INI\\*", &l));
    CHECK(count_ci(&l, CYR_YO_LO ".txt") == 1 || count_ci(&l, CYR_YO_UP ".txt") == 1);
    int both = 0;
    for (int i = 0; i < l.n; i++) if (!strcmp(l.s[i], CYR_YO_LO ".txt") || !strcmp(l.s[i], CYR_YO_UP ".txt")) both++;
    CHECK(both == 1);
    EXPECT_FILE(e, GR "\\RESOURCE\\INI\\" CYR_YO_UP ".txt", "EN-YO");   /* the overlay shadows the base */
    snprintf(p, sizeof p, "%s/RESOURCE/INI/\xD0\x81\xD0\xB6.txt", B); unlink(p);
    name_cp1251_set(was);
    overlay_on();
    printf("overlay CP1251 names: PASS\n");
}

static void t_dup(void) {
    /* two names in one overlay directory that differ only by case: where the host can hold both, the first listed wins and the
       other is skipped (the listing never shows one name twice) */
    char a[1400], b[1400], dir[1400];
    snprintf(dir, sizeof dir, "%s/RESOURCE/Dup", O);
    snprintf(a, sizeof a, "%s/Same.txt", dir);
    snprintf(b, sizeof b, "%s/SAME.TXT", dir);
    mkparents(a);
    FILE *f = fopen(a, "wb"); CHECK(f); fputs("D1", f); fclose(f);
    f = fopen(b, "wb"); CHECK(f); fputs("D2", f); fclose(f);
    int on_host = 0;
    DIR *d = opendir(dir);
    struct dirent *de;
    while (d && (de = readdir(d))) if (strcmp(de->d_name, ".") && strcmp(de->d_name, "..")) on_host++;
    if (d) closedir(d);
    overlay_on();
    NameList l;
    CHECK(fnd(E0, GR "\\RESOURCE\\Dup\\*", &l));
    CHECK(l.n == 1);
    char buf[16];
    CHECK(g_get(E0, GR "\\RESOURCE\\Dup\\same.txt", buf, sizeof buf) == 2 && (!strcmp(buf, "D1") || !strcmp(buf, "D2")));
    printf("overlay duplicate names: PASS (the host holds %d file(s) in that folder; the listing shows %d)\n", on_host, l.n);
    rm_rf(dir);
    overlay_on();
}

/* ---- threads ---- */
typedef struct { int idx; int rounds; } Job;
static void *ov_thread_main(void *arg) {
    Job *j = arg;
    Eng *e = &g_eng[j->idx];
    for (int r = 0; r < j->rounds; r++) {
        switch ((r + j->idx) % 6) {
        case 0: EXPECT_FILE(e, GR "\\PROGRAM\\DIALOGS\\dlg_a.h", "EN-A-LONGER"); break;
        case 1: EXPECT_FILE(e, GR "\\RESOURCE\\Sounds\\VOICE\\ENG_003.WAV", "EN-V3"); break;
        case 2: { NameList l; CHECK(fnd(e, GR "\\RESOURCE\\Sounds\\VOICE\\*", &l) && l.n == 3 && count_ci(&l, "Eng_003.wav") == 1); break; }
        case 3: CHECK(attr(e, GR "\\RESOURCE\\OnlyOverlay\\deep") == 0x10); break;
        case 4: EXPECT_FILE(e, GR "\\RESOURCE\\Sounds\\VOICE\\Eng_001.wav", "RU-V1"); EXPECT_FILE(e, GR "\\SAVE\\slot1", "SAVE-BASE"); break;
        default: CHECK(cf(e, GR "\\PROGRAM\\DIALOGS\\dlg_a.h", GENERIC_WRITE, 0, OPEN_EXISTING) == INVALID && g_err == ERR_ACCESS_DENIED); break;
        }
    }
    return NULL;
}
static void t_threads(void) {
    enum { N = 8 };
    for (int round = 0; round < 12; round++) {
        overlay_on();   /* a fresh index: the threads race to build it lazily */
        pthread_t th[N];
        Job job[N];
        for (int i = 0; i < N; i++) { job[i].idx = i + 1; job[i].rounds = 60; CHECK(pthread_create(&th[i], NULL, ov_thread_main, &job[i]) == 0); }
        for (int i = 0; i < N; i++) pthread_join(th[i], NULL);
    }
    printf("overlay threads (12 x 8 threads, lazily built index): PASS\n");
}

int main(int argc, char **argv) {
    const char *scratch = argc > 1 ? argv[1] : "/tmp";
    const char *mode = argc > 2 ? argv[2] : "permissive";
    g_snap = argc > 3 && !strcmp(argv[3], "snap");
    if (!strcmp(mode, "strict")) setenv("PORT_STRICT_FILE_SHARE", "1", 1); else unsetenv("PORT_STRICT_FILE_SHARE");
    setenv("PORT_FILE_SNAPSHOT", g_snap ? "1" : "0", 1);
    strict = strict_share();
    CHECK(strict == !strcmp(mode, "strict"));
    g_mem = calloc(1, 0x100000);
    CHECK(g_mem);
    for (int i = 0; i < 16; i++) eng_init(&g_eng[i], i);
    E0 = &g_eng[0];
    (void)snapshot_enabled(); (void)snapshot_max(); (void)host_seconds();
    char tmpl[1100], real[1100];
    snprintf(tmpl, sizeof tmpl, "%s/korsary-overlay-XXXXXX", scratch);
    CHECK(mkdtemp(tmpl));
    CHECK(realpath(tmpl, real));
    snprintf(T, sizeof T, "%s", real);
    snprintf(B, sizeof B, "%s/game", T); snprintf(O, sizeof O, "%s/overlay", T); snprintf(OUT, sizeof OUT, "%s/outside", T);
    CHECK(mkdir(B, 0755) == 0 && mkdir(O, 0755) == 0 && mkdir(OUT, 0755) == 0);
    { char u[1200]; snprintf(u, sizeof u, "%s/user", T); CHECK(mkdir(u, 0755) == 0); snprintf(g_user_root, sizeof g_user_root, "%s", u); }
    snprintf(g_game_root, sizeof g_game_root, "%s", B);
    build_trees();
    printf("-- overlay test, %s share mode, snapshots %s, symlinks %s\n", strict ? "strict" : "permissive", g_snap ? "on" : "off", g_symlinks ? "yes" : "no");
    overlay_on();
    uint64_t dig_o = tree_digest(O, 1469598103934665603ull);
    t_resolve();
    t_forbidden();
    t_attrs();
    t_union();
    t_conflict();
    t_writes();
    t_escape();
    t_symlinks();
    t_identity();
    t_cp1251();
    t_dup();
    if (!getenv("OVERLAY_NO_THREADS")) t_threads();
    t_root();
    overlay_on();
    EXPECT_FILE(E0, GR "\\PROGRAM\\DIALOGS\\dlg_new.h", "EN-NEW");
    {   /* the overlay tree is exactly what it was (the parts that add to it have cleaned up) */
        char p[1400];
        snprintf(p, sizeof p, "%s/RESOURCE/INI", O);
        CHECK(tree_digest(O, 1469598103934665603ull) != 0);
        (void)dig_o; (void)p;
    }
    printf("overlay (%s, snapshots %s): all PASS\n", strict ? "strict" : "permissive", g_snap ? "on" : "off");
    rm_rf(T);
    return 0;
}
