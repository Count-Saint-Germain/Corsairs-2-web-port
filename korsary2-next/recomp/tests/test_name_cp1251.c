/* Слой имён CP1251 <-> UTF-8 (PORT_NAME_CP1251, host/core.c map_path + kernel32.c FindFirstFileA/FindNextFileA) на
   НАСТОЯЩИХ обработчиках kernel32.c, на синтетических временных каталогах (игровые данные и сохранения игрока не
   затрагиваются; это не проверка запущенной игры).

   Что проверяется (после каждого пункта в скобках, какие режимы его исполняют):
     units      таблица 0x80..0xFF, круг байт-кодпоинт-байт, 66 букв, Ё/ё, неопределённый байт 0x98, свёртка регистра
                (совпадает с share_fold_cp strict по ВСЕМ кодпоинтам), wildcard по символам;
     cycle      полный круг «создать -> перечислить (FindFirstFileA) -> открыть по перечисленным байтам -> прочитать
                -> переместить -> удалить» для всех 66 букв и для смешанных/спецсимвольных имён;
     case       Ёж/ёж, регистр, на регистрозависимом хосте (WasmFS, Linux) и без него (APFS);
     copy       CopyFileA поверх имени другого регистра, "..", слеши, абсолютный путь;
     legacy     имена, которые хост уже хранит и которых CP1251-слой не создаёт (валидный UTF-8 вне CP1251, не-UTF-8
                байты там, где хост их принимает): листинг отдаёт свои байты, open по ним находит файл;
     off        слой выключен: байт-в-байт прежнее поведение (имена уходят хосту как есть);
     boundary   компонент 254/255/256 байт UTF-8, путь гостя 259 символов из кириллицы, слишком длинные имена;
     env        unset, "", "0" выключают, остальное включает;
     strict     (если PORT_STRICT_FILE_SHARE) имена из кириллицы проходят политику, Ёж и ёж одно имя;
     savemeta   (-DPORT_SAVE_META=1) sidecar SAVE_META/<utf-8>.time и ftCreationTime в листинге для слота «Ёж»;
     threads    8 потоков создают/перечисляют/удаляют кириллические имена (TSan);
     --tx-seed/--tx-run  сценарии SAVE_TX с кириллическим слотом для test_name_cp1251_savetx.mjs (страничный recoverSaveTx).
   Использование: test scratch-dir [strict|permissive]. NAME_NO_THREADS=1 пропускает потоки. */
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
#define FS_R 1
#define FS_W 2
#define FS_D 4
#define INVALID 0xffffffffu
#define CREATE_NEW 1
#define CREATE_ALWAYS 2
#define OPEN_EXISTING 3
#define OPEN_ALWAYS 4
#if !defined(__EMSCRIPTEN__) || defined(PORT_NODE_BUILD)
#define MOVE_OK 1
#else
#define MOVE_OK 0   /* the browser configuration refuses every MoveFileA before any path work */
#endif

static int strict;
static char root[1024];
static int use_threads = 1;
static int g_case_sensitive;   /* host distinguishes Ёж from ёж */
static int n_skipped;

/* ---- one guest thread: CPU + GuestThread + a private slice of guest memory ---- */
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

/* a whole small file through the guest API */
static int g_put(Eng *e, const char *name, const char *content, uint32_t disp) {
    uint32_t h = cf(e, name, GENERIC_WRITE, 0, disp);
    if (h == INVALID) return 0;
    uint32_t n = (uint32_t)strlen(content);
    int ok = wr(e, h, content, n) == n;
    ch(e, h);
    return ok;
}
static int g_get(Eng *e, const char *name, char *out, size_t cap) {   /* -1 when the open fails */
    uint32_t h = cf(e, name, GENERIC_READ, FS_R | FS_W | FS_D, OPEN_EXISTING);
    if (h == INVALID) return -1;
    uint32_t got = rd(e, h, out, (uint32_t)cap - 1);
    ch(e, h);
    out[got == INVALID ? 0 : got] = 0;
    return got == INVALID ? -1 : (int)got;
}

/* FindFirstFileA / FindNextFileA / FindClose: every name (as the guest receives it, raw bytes) into names[] */
#define MAXN 400
typedef struct { int n; char s[MAXN][300]; uint32_t attrs[MAXN]; uint64_t ctime[MAXN]; } NameList;
static int fnd(Eng *e, const char *spec, NameList *l) {   /* returns 1 when FindFirstFileA succeeded */
    l->n = 0;
    uint32_t out = e->base + 0x5000u;
    uint32_t a[2] = { gstr(e, 1, spec), out };
    uint32_t h = call(e, w_FindFirstFileA, 2, a);
    if (h == INVALID) return 0;
    do {
        const char *nm = (const char *)HP(out + 44);
        if (strcmp(nm, ".") && strcmp(nm, "..") && l->n < MAXN) {
            CHECK(strlen(nm) < 260);
            snprintf(l->s[l->n], 300, "%s", nm);
            l->attrs[l->n] = R32(out);
            l->ctime[l->n] = R64(out + 4);
            l->n++;
        }
        uint32_t b[2] = { h, out };
        if (!call(e, w_FindNextFileA, 2, b)) break;
    } while (1);
    uint32_t b[1] = { h };
    call(e, w_FindClose, 1, b);
    return 1;
}
static int in_list(const NameList *l, const char *name) {
    for (int i = 0; i < l->n; i++) if (!strcmp(l->s[i], name)) return 1;
    return 0;
}
static int count_of(const NameList *l, const char *name) {
    int c = 0;
    for (int i = 0; i < l->n; i++) if (!strcmp(l->s[i], name)) c++;
    return c;
}

/* ---- host-side helpers ---- */
static char *hp(const char *name) {
    static __thread char b[4][1400];
    static __thread int i;
    char *r = b[i++ & 3];
    snprintf(r, 1400, "%s/%s", root, name);
    return r;
}
static int dir_has_exact(const char *dir_rel, const char *name) {   /* readdir spelling, byte for byte */
    DIR *d = opendir(hp(dir_rel));
    if (!d) return 0;
    struct dirent *e;
    int hit = 0;
    while ((e = readdir(d))) if (!strcmp(e->d_name, name)) { hit = 1; break; }
    closedir(d);
    return hit;
}
static int dir_count(const char *dir_rel) {
    DIR *d = opendir(hp(dir_rel));
    int n = 0;
    struct dirent *e;
    while (d && (e = readdir(d))) if (strcmp(e->d_name, ".") && strcmp(e->d_name, "..")) n++;
    if (d) closedir(d);
    return n;
}
static int host_put(const char *rel, const char *content) {   /* 0 when the host refuses the name */
    FILE *f = fopen(hp(rel), "wb");
    if (!f) return 0;
    fputs(content, f);
    return fclose(f) == 0;
}
static int host_get(const char *rel, char *out, size_t cap) {
    FILE *f = fopen(hp(rel), "rb");
    if (!f) return -1;
    size_t n = fread(out, 1, cap - 1, f);
    fclose(f);
    out[n] = 0;
    return (int)n;
}
static void clear_dir(const char *rel) {   /* remove every entry of a directory (readdir spelling) */
    DIR *d = opendir(hp(rel));
    if (!d) return;
    struct dirent *e;
    while ((e = readdir(d))) {
        if (!strcmp(e->d_name, ".") || !strcmp(e->d_name, "..")) continue;
        char p[2000];
        snprintf(p, sizeof p, "%s/%s", hp(rel), e->d_name);
        unlink(p);
    }
    closedir(d);
}
static void rm_rf(const char *path) {
    DIR *d = opendir(path);
    if (d) {
        struct dirent *e;
        while ((e = readdir(d))) {
            if (!strcmp(e->d_name, ".") || !strcmp(e->d_name, "..")) continue;
            char p[2000];
            snprintf(p, sizeof p, "%s/%s", path, e->d_name);
            rm_rf(p);
        }
        closedir(d);
        rmdir(path);
    } else unlink(path);
}
/* guest CP1251 name -> expected host UTF-8 name, built independently of the production table: from the
   Unicode scalar of each byte (letters by arithmetic, the rest by the explicit table of the test) */
static void utf8_of_cp(uint32_t cp, char *o) {
    if (cp < 0x80) { *o++ = (char)cp; }
    else if (cp < 0x800) { *o++ = (char)(0xC0 | (cp >> 6)); *o++ = (char)(0x80 | (cp & 0x3F)); }
    else { *o++ = (char)(0xE0 | (cp >> 12)); *o++ = (char)(0x80 | ((cp >> 6) & 0x3F)); *o++ = (char)(0x80 | (cp & 0x3F)); }
    *o = 0;
}
static const struct { uint8_t b; uint16_t cp; } k_other[] = {   /* the non-letter and non-Cyrillic-basic bytes, written out again */
    {0x80,0x0402},{0x81,0x0403},{0x82,0x201A},{0x83,0x0453},{0x84,0x201E},{0x85,0x2026},{0x86,0x2020},{0x87,0x2021},
    {0x88,0x20AC},{0x89,0x2030},{0x8A,0x0409},{0x8B,0x2039},{0x8C,0x040A},{0x8D,0x040C},{0x8E,0x040B},{0x8F,0x040F},
    {0x90,0x0452},{0x91,0x2018},{0x92,0x2019},{0x93,0x201C},{0x94,0x201D},{0x95,0x2022},{0x96,0x2013},{0x97,0x2014},
    {0x98,0x0098},{0x99,0x2122},{0x9A,0x0459},{0x9B,0x203A},{0x9C,0x045A},{0x9D,0x045C},{0x9E,0x045B},{0x9F,0x045F},
    {0xA0,0x00A0},{0xA1,0x040E},{0xA2,0x045E},{0xA3,0x0408},{0xA4,0x00A4},{0xA5,0x0490},{0xA6,0x00A6},{0xA7,0x00A7},
    {0xA8,0x0401},{0xA9,0x00A9},{0xAA,0x0404},{0xAB,0x00AB},{0xAC,0x00AC},{0xAD,0x00AD},{0xAE,0x00AE},{0xAF,0x0407},
    {0xB0,0x00B0},{0xB1,0x00B1},{0xB2,0x0406},{0xB3,0x0456},{0xB4,0x0491},{0xB5,0x00B5},{0xB6,0x00B6},{0xB7,0x00B7},
    {0xB8,0x0451},{0xB9,0x2116},{0xBA,0x0454},{0xBB,0x00BB},{0xBC,0x0458},{0xBD,0x0405},{0xBE,0x0455},{0xBF,0x0457},
};
static uint32_t expect_cp(uint8_t b) {
    if (b < 0x80) return b;
    if (b >= 0xC0) return 0x0410u + (uint32_t)(b - 0xC0);   /* А..Я, а..я are one contiguous block */
    for (size_t i = 0; i < sizeof k_other / sizeof k_other[0]; i++) if (k_other[i].b == b) return k_other[i].cp;
    CHECK(0);
    return 0;
}
static void expect_host_name(const char *guest, char *host) {
    char *o = host;
    for (const unsigned char *p = (const unsigned char *)guest; *p; p++) { utf8_of_cp(expect_cp(*p), o); o += strlen(o); }
    *o = 0;
}

/* ========================================================================== units */
/* Строчные пары CP1251 (байт заглавной -> байт строчной), сверено с Python str.lower() по всем 128 байтам. */
static const uint8_t k_pairs[][2] = {
    {0x80,0x90},{0x81,0x83},{0x8A,0x9A},{0x8C,0x9C},{0x8D,0x9D},{0x8E,0x9E},{0x8F,0x9F},{0xA1,0xA2},{0xA3,0xBC},
    {0xA5,0xB4},{0xA8,0xB8},{0xAA,0xBA},{0xAF,0xBF},{0xB2,0xB3},{0xBD,0xBE},
};
static int upper_pair(uint8_t b, uint8_t *lower) {
    for (size_t i = 0; i < sizeof k_pairs / sizeof k_pairs[0]; i++) if (k_pairs[i][0] == b) { *lower = k_pairs[i][1]; return 1; }
    if (b >= 0xC0 && b <= 0xDF) { *lower = (uint8_t)(b + 0x20); return 1; }
    return 0;
}
static void t_units(void) {
    /* table: every byte against the independently written expectation and a bijection */
    uint8_t seen_hi[0x10000 / 8];
    memset(seen_hi, 0, sizeof seen_hi);
    for (int b = 1; b < 256; b++) {
        char g[2] = { (char)b, 0 }, h[8], back[8], want[8];
        CHECK(name_guest_to_host(g, h, sizeof h));
        utf8_of_cp(expect_cp((uint8_t)b), want);
        CHECK(!strcmp(h, want));
        uint32_t cp; const unsigned char *u = (const unsigned char *)h;
        int len = name_utf8_decode(u, &cp);
        CHECK(len == (int)strlen(h) && cp == expect_cp((uint8_t)b));
        CHECK(!(seen_hi[cp / 8] & (1u << (cp % 8))));   /* injective */
        seen_hi[cp / 8] |= (uint8_t)(1u << (cp % 8));
        CHECK(name_host_to_guest(h, back, sizeof back) && (uint8_t)back[0] == b && !back[1]);
        CHECK((b < 0x80) == !name_has_high(g));
    }
    /* 66 letters: А..Я (C0..DF), а..я (E0..FF), Ё (A8), ё (B8) */
    int letters = 0;
    for (int b = 0xC0; b <= 0xFF; b++) { CHECK(expect_cp((uint8_t)b) == 0x410u + (uint32_t)(b - 0xC0)); letters++; }
    CHECK(expect_cp(0xA8) == 0x401 && expect_cp(0xB8) == 0x451);
    letters += 2;
    CHECK(letters == 66);
    CHECK(expect_cp(0x98) == 0x98 && name_fold_cp(0x98) == 0x98);   /* undefined byte: the control U+0098, a bijection */
    /* fold: pairs, and every other CP1251 character folds to itself */
    for (int b = 0x80; b < 256; b++) {
        uint8_t lo;
        uint32_t cp = expect_cp((uint8_t)b);
        if (upper_pair((uint8_t)b, &lo)) CHECK(name_fold_cp(cp) == expect_cp(lo));
        else CHECK(name_fold_cp(cp) == cp || (b >= 0xE0));
        if (b >= 0xE0 || b == 0xB8) CHECK(name_fold_cp(cp) == cp);
    }
    CHECK(name_fold_cp('A') == 'a' && name_fold_cp('z') == 'z');
    /* the layer's fold and the strict-share fold are one table: identical over all of Unicode */
    for (uint32_t c = 0; c <= 0x10FFFF; c++) CHECK(name_fold_cp(c) == share_fold_cp(c));
    /* host -> guest: not representable / ill-formed names are reported, not mangled */
    char o[64];
    CHECK(!name_host_to_guest("\xC3\xA9", o, sizeof o));                 /* é: not in CP1251 */
    CHECK(!name_host_to_guest("\xE6\x97\xA5", o, sizeof o));             /* 日 */
    CHECK(!name_host_to_guest("\xEF\xBF\xBD", o, sizeof o));             /* U+FFFD, what OPFS makes of a bad byte */
    CHECK(!name_host_to_guest("\xA8\xE6", o, sizeof o));                 /* not UTF-8 */
    CHECK(!name_host_to_guest("\xC0\x80", o, sizeof o));                 /* overlong */
    CHECK(!name_host_to_guest("\xED\xA0\x80", o, sizeof o));             /* surrogate */
    CHECK(!name_host_to_guest("\xD0", o, sizeof o));                     /* truncated */
    CHECK(!name_host_to_guest("\xC2\x81", o, sizeof o));                 /* U+0081: a control CP1251 does not have */
    CHECK(name_host_to_guest("\xC2\x98", o, sizeof o) && !strcmp(o, "\x98"));
    CHECK(name_host_to_guest("", o, sizeof o) && !o[0]);
    CHECK(!name_host_to_guest("abc", o, 3) && !o[0]);                    /* does not fit */
    CHECK(name_host_to_guest("abc", o, 4) && !strcmp(o, "abc"));
    CHECK(!name_guest_to_host("\xE0\xE0\xE0", o, 6) && !o[0]);           /* 3 x 2 bytes + NUL do not fit in 6 */
    CHECK(name_guest_to_host("\xE0\xE0\xE0", o, 7));
    CHECK(name_guest_to_host("\x88", o, 4) && !strcmp(o, "\xE2\x82\xAC")); /* € takes 3 bytes */
    /* wildcard in characters, folded */
    CHECK(name_wild_match("*", "\xD0\x81\xD0\xB6"));
    CHECK(name_wild_match("??", "\xD0\x81\xD0\xB6"));                    /* two characters, four bytes */
    CHECK(!name_wild_match("???", "\xD0\x81\xD0\xB6"));
    CHECK(!name_wild_match("?", "\xD0\x81\xD0\xB6"));
    CHECK(name_wild_match("\xB8\xE6", "\xD0\x81\xD0\xB6"));              /* ёж matches Ёж */
    CHECK(name_wild_match("\xA8\xC6", "\xD1\x91\xD0\xB6"));              /* ЁЖ matches ёж */
    CHECK(name_wild_match("\xA8*", "\xD0\x81\xD0\xB6.TXT"));
    CHECK(name_wild_match("*.txt", "\xD0\x81\xD0\xB6.TXT"));
    CHECK(name_wild_match("*\xE6.t?t", "\xD0\x81\xD0\xB6.txt"));
    CHECK(!name_wild_match("*\xE5.t?t", "\xD0\x81\xD0\xB6.txt"));
    CHECK(name_wild_match("a*b*c", "aXXbYYc") && !name_wild_match("a*b*c", "aXXbYY"));
    CHECK(name_wild_match("**", "") && !name_wild_match("?", ""));
    CHECK(name_wild_match("[x]", "[X]") && !name_wild_match("[x]", "x"));  /* Windows has no [] sets */
    CHECK(!name_wild_match("*", "\xA8\xE6"));                            /* ill-formed host name: never matched here */
    /* env contract of the layer */
    const char *saved = getenv("PORT_NAME_CP1251");
    char keep[16] = "";
    if (saved) snprintf(keep, sizeof keep, "%s", saved);
    unsetenv("PORT_NAME_CP1251"); g_name_cp1251 = -1; CHECK(!name_cp1251_on());
    setenv("PORT_NAME_CP1251", "", 1); g_name_cp1251 = -1; CHECK(!name_cp1251_on());
    setenv("PORT_NAME_CP1251", "0", 1); g_name_cp1251 = -1; CHECK(!name_cp1251_on());
    setenv("PORT_NAME_CP1251", "1", 1); g_name_cp1251 = -1; CHECK(name_cp1251_on());
    setenv("PORT_NAME_CP1251", "yes", 1); g_name_cp1251 = -1; CHECK(name_cp1251_on());
    if (saved) setenv("PORT_NAME_CP1251", keep, 1); else unsetenv("PORT_NAME_CP1251");
    g_name_cp1251 = -1;
    printf("units (table, 66 letters, fold == strict fold, wildcard, env): PASS\n");
}

/* ========================================================================== cycle */
/* create -> find -> open by the found bytes -> read -> move -> delete, for one guest name inside SAVE\ */
static int g_moves;
static void cycle_name(Eng *e, const char *guest_leaf, const char *tag) {
    char gpath[600], gpath2[600], want_host[600], buf[64], content[64], mvleaf[600];
    snprintf(gpath, sizeof gpath, "SAVE\\%s", guest_leaf);
    snprintf(content, sizeof content, "content-%s", tag);
    expect_host_name(guest_leaf, want_host);
    CHECK(g_put(e, gpath, content, CREATE_ALWAYS));
    /* on the host: the UTF-8 name exactly, and NOT the raw guest bytes (when they differ) */
    CHECK(dir_has_exact("SAVE", want_host));
    if (strcmp(want_host, guest_leaf)) CHECK(!dir_has_exact("SAVE", guest_leaf));
    /* the game finds it by listing, as the CP1251 bytes it created */
    NameList l;
    CHECK(fnd(e, "SAVE\\*", &l));
    CHECK(count_of(&l, guest_leaf) == 1);
    /* by exact pattern too (existence probe) and by *.* */
    CHECK(fnd(e, gpath, &l) && l.n == 1 && !strcmp(l.s[0], guest_leaf));
    CHECK(fnd(e, "SAVE\\*.*", &l) && in_list(&l, guest_leaf));
    CHECK(attr(e, gpath) == 0x20);
    CHECK(g_get(e, gpath, buf, sizeof buf) == (int)strlen(content) && !strcmp(buf, content));
    if (MOVE_OK) {
        /* leaf + "-moved" */
        snprintf(mvleaf, sizeof mvleaf, "%s-m", guest_leaf);
        snprintf(gpath2, sizeof gpath2, "SAVE\\%s", mvleaf);
        CHECK(mv(e, gpath, gpath2));
        char want2[600];
        expect_host_name(mvleaf, want2);
        CHECK(dir_has_exact("SAVE", want2) && !dir_has_exact("SAVE", want_host));
        CHECK(g_get(e, gpath2, buf, sizeof buf) == (int)strlen(content) && !strcmp(buf, content));
        CHECK(mv(e, gpath2, gpath));
        CHECK(dir_has_exact("SAVE", want_host));
        g_moves++;
    }
    CHECK(dl(e, gpath));
    CHECK(!dir_has_exact("SAVE", want_host));
    CHECK(attr(e, gpath) == 0xFFFFFFFFu);
    CHECK(g_get(e, gpath, buf, sizeof buf) < 0);
}

static void t_cycle(void) {
    Eng *e = &g_eng[0];
    name_cp1251_set(1);
    /* all 66 letters, one file name each, created in the spelling of the table */
    int n = 0;
    for (int b = 0xC0; b <= 0xFF; b++) { char leaf[2] = { (char)b, 0 }, tag[16]; snprintf(tag, sizeof tag, "L%02X", b); cycle_name(e, leaf, tag); n++; }
    { char leaf[2] = { (char)0xA8, 0 }; cycle_name(e, leaf, "YO"); n++; }
    { char leaf[2] = { (char)0xB8, 0 }; cycle_name(e, leaf, "yo"); n++; }
    CHECK(n == 66);
    /* the high bytes 0x80..0xBF as a part of a name (0x98 has its own test, Ё/ё were done above) */
    int n_high = 0;
    for (int b = 0x80; b <= 0xBF; b++) {
        if (b == 0x98 || b == 0xA8 || b == 0xB8) continue;
        n_high++;
        char leaf[8] = { 'a', ' ', (char)b, (char)0xE6, '.', 'x', 0 }, tag[16];
        snprintf(tag, sizeof tag, "H%02X", b);
        cycle_name(e, leaf, tag);
    }
    /* mixed and special names: Latin + Cyrillic, spaces, dots, brackets, №, quotes, dashes, NBSP, digits */
    static const char *k_names[] = {
        "Oxbay \xEF\xEE\xF0\xF2 12-11-2026",                       /* "Oxbay порт 12-11-2026": the shape of a slot name */
        "\xD2\xE5\xF1\xF2 1",                                      /* Тест 1 */
        "\xCF\xEE\xF0\xF2 \xCE\xEA\xF1\xE1\xE5\xE9 12-11-2026 2",  /* Порт Оксбей 12-11-2026 2 */
        "\xCE\xEA\xF1\xE1\xE5\xE9.\xF2\xE5\xF1\xF2",               /* Оксбей.тест */
        "(\xE0)[\xE1]{\xE2}+\xE3=\xE4,\xE5;\xE6!\xE7@\xE8#\xE9$\xEA%\xEB&\xEC'\xED^\xEE~\xEF-\xF0_\xF1",
        "\xB9 1 \xAB\xEA\xE0\xE2\xFB\xF7\xEA\xE8\xBB",             /* № 1 «кавычки» */
        "\x96 \x97 \x85 \x99 \x88",                                /* – — … ™ € */
        "\xA0nbsp\xA0\xE0",                                        /* NBSP inside and at the start */
        "\xC0\xE0\xC1\xE1\xC2\xE2 mixed CASE \xC3\xE3",
        "caf\xE9",                                                 /* CP1251 0xE9 is 'й': "cafй", not an accented e */
        "a\xA8" "b",                                               /* Ё between ASCII */
        "\xFF\xFE\xFD\xFC\xFB\xFA\xF9\xF8\xF7\xF6\xF5\xF4\xF3\xF2\xF1\xF0",
        "0123456789\xD0\xA0\xD0\xA1",                              /* bytes that happen to be valid UTF-8: here they are CP1251 (Р, NBSP, Р, Ў) */
    };
    for (size_t i = 0; i < sizeof k_names / sizeof k_names[0]; i++) { char tag[16]; snprintf(tag, sizeof tag, "M%zu", i); cycle_name(e, k_names[i], tag); }
    /* nested: a directory with a Cyrillic name, a file below it, the listing of the directory */
    CHECK(mkd(e, "SAVE\\\xCF\xE0\xEF\xEA\xE0"));   /* Папка */
    CHECK(dir_has_exact("SAVE", "\xD0\x9F\xD0\xB0\xD0\xBF\xD0\xBA\xD0\xB0"));
    CHECK(g_put(e, "SAVE\\\xCF\xE0\xEF\xEA\xE0\\\xF4\xE0\xE9\xEB.txt", "inner", CREATE_ALWAYS));   /* Папка\файл.txt */
    CHECK(g_put(e, "save\\\xEF\xE0\xEF\xEA\xE0\\\xD4\xC0\xC9\xCB.TXT", "inner2", OPEN_ALWAYS));    /* other case everywhere: the same file */
    NameList l;
    CHECK(fnd(e, "SAVE\\\xCF\xE0\xEF\xEA\xE0\\*", &l) && l.n == 1 && !strcmp(l.s[0], "\xF4\xE0\xE9\xEB.txt"));
    CHECK(fnd(e, "SAVE\\*", &l) && l.n == 1 && !strcmp(l.s[0], "\xCF\xE0\xEF\xEA\xE0") && l.attrs[0] == 0x10);
    char buf[32];
    CHECK(g_get(e, "SAVE\\\xCF\xC0\xCF\xCA\xC0\\\xF4\xE0\xE9\xEB.TXT", buf, sizeof buf) == 6 && !strcmp(buf, "inner2"));
    CHECK(dl(e, "SAVE\\\xCF\xE0\xEF\xEA\xE0\\\xF4\xE0\xE9\xEB.txt"));
    CHECK(rmd(e, "SAVE\\\xCF\xE0\xEF\xEA\xE0"));
    CHECK(dir_count("SAVE") == 0);
    printf("cycle: 66 letters + %d high-byte names + %zu mixed names + nested dir: PASS (moves %s)\n",
           n_high, sizeof k_names / sizeof k_names[0], MOVE_OK ? "executed" : "refused by the browser configuration, not exercised");
}

/* ========================================================================== 0x98 */
static void t_undefined_byte(void) {
    Eng *e = &g_eng[0];
    name_cp1251_set(1);
    const char *leaf = "a\x98" "b";
    char gpath[64], want[64];
    snprintf(gpath, sizeof gpath, "SAVE\\%s", leaf);
    expect_host_name(leaf, want);
    CHECK(!strcmp(want, "a\xC2\x98" "b"));
    if (!g_put(e, gpath, "x98", CREATE_ALWAYS)) {   /* a host may refuse a C1 control in a name: then it refuses cleanly, no partial state */
        CHECK(dir_count("SAVE") == 0);
        n_skipped++;
        printf("undefined byte 0x98: the host refuses the name U+0098 (error %u); the layer stays consistent: PASS\n", g_err);
        return;
    }
    CHECK(dir_has_exact("SAVE", want));
    NameList l;
    CHECK(fnd(e, "SAVE\\*", &l) && l.n == 1 && !strcmp(l.s[0], leaf));
    char buf[16];
    CHECK(g_get(e, gpath, buf, sizeof buf) == 3 && !strcmp(buf, "x98"));
    CHECK(dl(e, gpath));
    CHECK(dir_count("SAVE") == 0);
    printf("undefined byte 0x98 <-> U+0098 (C2 98): full circle: PASS\n");
}

/* ========================================================================== case */
static void t_case(void) {
    Eng *e = &g_eng[0];
    name_cp1251_set(1);
    char buf[32];
    CHECK(g_put(e, "SAVE\\\xA8\xE6", "YO-ZH", CREATE_ALWAYS));                   /* Ёж */
    CHECK(dir_has_exact("SAVE", "\xD0\x81\xD0\xB6") && dir_count("SAVE") == 1);
    /* ёж is the same file under Windows rules: opens it, finds it, and writing it overwrites, never a second file */
    CHECK(g_get(e, "SAVE\\\xB8\xE6", buf, sizeof buf) == 5 && !strcmp(buf, "YO-ZH"));
    CHECK(g_get(e, "save\\\xB8\xC6", buf, sizeof buf) == 5);                     /* ёЖ, other case of SAVE */
    NameList l;
    CHECK(fnd(e, "SAVE\\\xB8\xE6", &l) && l.n == 1 && !strcmp(l.s[0], "\xA8\xE6"));   /* the entry keeps the spelling it was created with */
    CHECK(fnd(e, "SAVE\\\xA8\xC6*", &l) && l.n == 1);
    CHECK(g_put(e, "SAVE\\\xB8\xE6", "yo-zh2", CREATE_ALWAYS));
    CHECK(dir_count("SAVE") == 1 && dir_has_exact("SAVE", "\xD0\x81\xD0\xB6"));
    CHECK(g_get(e, "SAVE\\\xA8\xE6", buf, sizeof buf) == 6 && !strcmp(buf, "yo-zh2"));
    CHECK(attr(e, "SAVE\\\xB8\xE6") == 0x20);
    /* CREATE_NEW of the other case: the name exists */
    uint32_t h = cf(e, "SAVE\\\xB8\xE6", GENERIC_WRITE, 0, CREATE_NEW);
    CHECK(h == INVALID);   /* exists (ERROR_FILE_EXISTS); the browser configuration refuses CREATE_NEW altogether (no atomic no-replace) */
    if (MOVE_OK) CHECK(g_err == 80);
    CHECK(dir_count("SAVE") == 1);
    if (MOVE_OK) {   /* a move to the other case of the same name never makes a second file (the result code is the host's) */
        (void)mv(e, "SAVE\\\xA8\xE6", "SAVE\\\xB8\xE6");
        CHECK(dir_count("SAVE") == 1);
    }
    CHECK(dl(e, "SAVE\\\xB8\xC6"));                                              /* deleted through the third spelling */
    CHECK(dir_count("SAVE") == 0);
    /* the reverse: created lower case, found by upper case */
    CHECK(g_put(e, "SAVE\\\xE0\xE1\xE2", "abc", CREATE_ALWAYS));
    CHECK(dir_has_exact("SAVE", "\xD0\xB0\xD0\xB1\xD0\xB2"));
    CHECK(g_get(e, "SAVE\\\xC0\xC1\xC2", buf, sizeof buf) == 3);
    CHECK(fnd(e, "SAVE\\\xC0*", &l) && l.n == 1 && !strcmp(l.s[0], "\xE0\xE1\xE2"));
    CHECK(dl(e, "SAVE\\\xC0\xC1\xC2"));
    CHECK(dir_count("SAVE") == 0);
    /* a host that tells the cases apart: two entries must not appear (the point of the whole layer) */
    if (g_case_sensitive) {
        /* an entry the host stores as ёж and the game asks for as Ёж: found through the fold, not duplicated */
        CHECK(host_put("SAVE/\xD1\x91\xD0\xB6", "host-yo"));
        CHECK(g_get(e, "SAVE\\\xA8\xE6", buf, sizeof buf) == 7 && !strcmp(buf, "host-yo"));
        CHECK(g_put(e, "SAVE\\\xA8\xE6", "game-yo", CREATE_ALWAYS));
        CHECK(dir_count("SAVE") == 1 && dir_has_exact("SAVE", "\xD1\x91\xD0\xB6"));
        CHECK(fnd(e, "SAVE\\*", &l) && l.n == 1 && !strcmp(l.s[0], "\xB8\xE6"));
        CHECK(dl(e, "SAVE\\\xA8\xC6"));
        CHECK(dir_count("SAVE") == 0);
        /* Latin keeps working as before */
        CHECK(g_put(e, "SAVE\\Oxbay", "lat", CREATE_ALWAYS));
        CHECK(g_get(e, "save\\OXBAY", buf, sizeof buf) == 3);
        CHECK(dl(e, "SAVE\\oxbay") && dir_count("SAVE") == 0);
        printf("case: Ёж/ёж/ЁЖ are one file (host case-sensitive: executed against a host entry spelled ёж): PASS\n");
    } else {
        printf("case: Ёж/ёж/ЁЖ are one file; the host-side probe (entry spelled ёж, request Ёж) is SKIPPED: this host's file system is case-insensitive\n");
    }
}

/* ========================================================================== CopyFileA, "..", slashes */
static void t_copy_paths(void) {
    Eng *e = &g_eng[0];
    name_cp1251_set(1);
    char buf[16];
    CHECK(g_put(e, "SAVE\\\xA8\xE6", "SRC", CREATE_ALWAYS));                      /* Ёж */
    CHECK(g_put(e, "SAVE\\\xCA\xEE\xEF\xE8\xFF", "DST", CREATE_ALWAYS));            /* Копия */
    /* the destination in another case is the same file; failIfExists refuses, otherwise it is overwritten */
    CHECK(cpy(e, "SAVE\\\xB8\xC6", "SAVE\\\xEA\xCE\xCF\xC8\xDF", 1) == 0 && g_err == 80);
    CHECK(g_get(e, "SAVE\\\xCA\xEE\xEF\xE8\xFF", buf, sizeof buf) == 3 && !strcmp(buf, "DST"));
    CHECK(cpy(e, "SAVE\\\xB8\xC6", "SAVE\\\xEA\xCE\xCF\xC8\xDF", 0) == 1);
    CHECK(g_get(e, "SAVE\\\xCA\xEE\xEF\xE8\xFF", buf, sizeof buf) == 3 && !strcmp(buf, "SRC"));
    CHECK(dir_count("SAVE") == 2 && dir_has_exact("SAVE", "\xD0\x9A\xD0\xBE\xD0\xBF\xD0\xB8\xD1\x8F"));
    if (strict) {   /* strict CopyFileA creates a new destination (the permissive one needs it to exist, as before) */
        CHECK(cpy(e, "SAVE\\\xA8\xE6", "SAVE\\\xCD\xEE\xE2\xE0\xFF", 1) == 1);         /* Новая */
        CHECK(dir_has_exact("SAVE", "\xD0\x9D\xD0\xBE\xD0\xB2\xD0\xB0\xD1\x8F"));
        CHECK(dl(e, "SAVE\\\xCD\xEE\xE2\xE0\xFF"));
    }
    /* ".." and mixed separators around Cyrillic components */
    CHECK(mkd(e, "SAVE\\\xCF\xE0\xEF\xEA\xE0"));
    CHECK(g_get(e, "SAVE\\\xCF\xE0\xEF\xEA\xE0\\..\\\xA8\xE6", buf, sizeof buf) == 3);       /* SAVE\Папка\..\Ёж */
    CHECK(g_get(e, "save/\xEF\xC0\xCF\xCA\xC0/../\xB8\xE6", buf, sizeof buf) == 3);               /* forward slashes, other case */
    CHECK(g_get(e, "C:\\Games\\Korsary2\\SAVE\\\xB8\xE6", buf, sizeof buf) == 3);                    /* absolute */
    CHECK(rmd(e, "SAVE\\\xCF\xE0\xEF\xEA\xE0"));
    CHECK(dl(e, "SAVE\\\xA8\xE6") && dl(e, "SAVE\\\xCA\xEE\xEF\xE8\xFF"));
    CHECK(dir_count("SAVE") == 0);
    printf("copy and paths: CopyFileA over another-case name, \"..\", slashes, absolute path: PASS\n");
}

/* ========================================================================== find: patterns */
static void t_find(void) {
    Eng *e = &g_eng[0];
    name_cp1251_set(1);
    static const char *k_files[] = {
        "\xA8\xE6.TXT",              /* Ёж.TXT */
        "\xE5\xE6.txt",              /* еж.txt */
        "\xA8\xE6",                  /* Ёж */
        "Abc.txt",
        "abc",
        "\xE0\xE1\xE2\xE3.sav",      /* абвг.sav */
        "\xC0\xC1.SAV",              /* АБ.SAV */
        "x\xFF",                     /* xя */
        "\xFF",                      /* я */
    };
    for (size_t i = 0; i < sizeof k_files / sizeof k_files[0]; i++) {
        char p[64]; snprintf(p, sizeof p, "SAVE\\%s", k_files[i]);
        CHECK(g_put(e, p, "x", CREATE_ALWAYS));
    }
    NameList l;
    CHECK(fnd(e, "SAVE\\*", &l) && l.n == (int)(sizeof k_files / sizeof k_files[0]));
    for (size_t i = 0; i < sizeof k_files / sizeof k_files[0]; i++) CHECK(count_of(&l, k_files[i]) == 1);
    CHECK(fnd(e, "SAVE\\*.*", &l) && l.n == 9);
    CHECK(fnd(e, "SAVE\\*.txt", &l) && l.n == 3 && in_list(&l, "\xA8\xE6.TXT") && in_list(&l, "\xE5\xE6.txt") && in_list(&l, "Abc.txt"));
    CHECK(fnd(e, "SAVE\\*.sav", &l) && l.n == 2);
    CHECK(fnd(e, "SAVE\\\xE5*", &l) && l.n == 1);                       /* е*: еж.txt only, Ё is another letter */
    CHECK(fnd(e, "SAVE\\\xB8*", &l) && l.n == 2);                       /* ё*: Ёж.TXT, Ёж */
    CHECK(fnd(e, "SAVE\\??", &l) && l.n == 2 && in_list(&l, "\xA8\xE6") && in_list(&l, "x\xFF"));   /* ?? is two CHARACTERS */
    CHECK(fnd(e, "SAVE\\?", &l) && l.n == 1 && in_list(&l, "\xFF"));
    CHECK(fnd(e, "SAVE\\?\xE6.???", &l) && l.n == 2);
    CHECK(fnd(e, "SAVE\\\xFF", &l) && l.n == 1 && !strcmp(l.s[0], "\xFF"));
    CHECK(fnd(e, "SAVE\\\xDF", &l) && l.n == 1);                        /* Я matches я */
    CHECK(fnd(e, "SAVE\\x\xDF", &l) && l.n == 1);
    CHECK(!fnd(e, "SAVE\\nosuch*", &l) && g_err == ERROR_FILE_NOT_FOUND);
    CHECK(!fnd(e, "SAVE\\\xD0*", &l));                                  /* Р*: nothing starts with Р */
    CHECK(fnd(e, "SAVE\\ABC*", &l) && l.n == 2);                        /* ASCII patterns keep fnmatch semantics */
    for (size_t i = 0; i < sizeof k_files / sizeof k_files[0]; i++) { char p[64]; snprintf(p, sizeof p, "SAVE\\%s", k_files[i]); CHECK(dl(e, p)); }
    CHECK(dir_count("SAVE") == 0);
    printf("find: wildcards by character, folded, ASCII patterns unchanged: PASS\n");
}

/* ========================================================================== legacy names */
static void t_legacy(void) {
    Eng *e = &g_eng[0];
    name_cp1251_set(1);
    char buf[32];
    NameList l;
    /* valid UTF-8 the game's code page cannot spell (café, 日本): the guest gets the host bytes and can open them */
    CHECK(host_put("SAVE/caf\xC3\xA9", "cafe"));
    CHECK(host_put("SAVE/\xE6\x97\xA5\xE6\x9C\xAC", "nihon"));
    CHECK(host_put("SAVE/\xD0\xA2\xD0\xB5", "te"));                       /* Те in UTF-8: spellable, returned as CP1251 D2 E5 */
    CHECK(fnd(e, "SAVE\\*", &l) && l.n == 3);
    CHECK(in_list(&l, "caf\xC3\xA9") && in_list(&l, "\xE6\x97\xA5\xE6\x9C\xAC") && in_list(&l, "\xD2\xE5"));
    CHECK(g_get(e, "SAVE\\caf\xC3\xA9", buf, sizeof buf) == 4 && !strcmp(buf, "cafe"));
    CHECK(g_get(e, "SAVE\\\xE6\x97\xA5\xE6\x9C\xAC", buf, sizeof buf) == 5);
    CHECK(g_get(e, "SAVE\\\xD2\xE5", buf, sizeof buf) == 2 && !strcmp(buf, "te"));
    CHECK(g_get(e, "SAVE\\\xD0\xA2\xD0\xB5", buf, sizeof buf) == 2);      /* the spelling the old run used (raw bytes), still found */
    CHECK(fnd(e, "SAVE\\caf*", &l) && l.n == 1);
    CHECK(attr(e, "SAVE\\caf\xC3\xA9") == 0x20);
    CHECK(g_put(e, "SAVE\\caf\xC3\xA9", "cafe2", CREATE_ALWAYS));         /* overwritten, not duplicated */
    CHECK(dir_count("SAVE") == 3);
    CHECK(dl(e, "SAVE\\caf\xC3\xA9") && dl(e, "SAVE\\\xE6\x97\xA5\xE6\x9C\xAC") && dl(e, "SAVE\\\xD2\xE5"));
    CHECK(dir_count("SAVE") == 0);
    /* ill-formed names (what a CP1251 game wrote before the layer, on hosts that keep such bytes: WasmFS, ext4) */
    /* the host must really keep the raw bytes (WasmFS in memory, ext4 do; APFS refuses; Node's fs and OPFS store a lossy U+FFFD name) */
    int raw_kept = host_put("SAVE/\xD2\xE5\xF1\xF2", "cp-test") && dir_has_exact("SAVE", "\xD2\xE5\xF1\xF2");
    if (!raw_kept) clear_dir("SAVE");
    if (raw_kept) {
        CHECK(fnd(e, "SAVE\\*", &l) && l.n == 1 && !strcmp(l.s[0], "\xD2\xE5\xF1\xF2"));   /* those bytes cannot be told from the CP1251 name Тест */
        if (strict) {   /* K2: strict refuses a name that is not well-formed UTF-8, with the layer too (no identity for it) */
            CHECK(g_get(e, "SAVE\\\xD2\xE5\xF1\xF2", buf, sizeof buf) < 0 && g_err == ERROR_INVALID_NAME);
            unlink(hp("SAVE/\xD2\xE5\xF1\xF2"));
            printf("legacy: ill-formed host name is listed but refused by strict (ERROR_INVALID_NAME), as in K2: PASS\n");
        } else {
            CHECK(g_get(e, "SAVE\\\xD2\xE5\xF1\xF2", buf, sizeof buf) == 7 && !strcmp(buf, "cp-test"));
            CHECK(g_put(e, "SAVE\\\xD2\xE5\xF1\xF2", "cp-test2", CREATE_ALWAYS));
            CHECK(dir_count("SAVE") == 1 && dir_has_exact("SAVE", "\xD2\xE5\xF1\xF2"));   /* still the legacy entry: no duplicate in UTF-8 */
            CHECK(dl(e, "SAVE\\\xD2\xE5\xF1\xF2"));
            printf("legacy: ill-formed host name (CP1251 bytes stored raw) is listed, opened, overwritten and deleted by its own bytes: PASS\n");
        }
        CHECK(dir_count("SAVE") == 0);
    } else {
        n_skipped++;
        printf("legacy: the host refuses or mangles ill-formed UTF-8 names (APFS refuses, Node/OPFS store U+FFFD); the ill-formed part is SKIPPED here (WasmFS in memory and ext4 run it)\n");
    }
    printf("legacy: valid UTF-8 names outside CP1251 and spellable ones: PASS\n");
}

/* ========================================================================== off */
static void t_off(void) {
    Eng *e = &g_eng[0];
    name_cp1251_set(0);
    NameList l;
    char buf[16];
    /* the guest's bytes go to the host untouched: a name that is valid UTF-8 as it stands stays itself */
    const char *u = "\xD0\x96\xD1\x83\xD0\xBA";
    CHECK(g_put(e, "SAVE\\\xD0\x96\xD1\x83\xD0\xBA", "off", CREATE_ALWAYS));
    CHECK(dir_has_exact("SAVE", u) && dir_count("SAVE") == 1);
    CHECK(fnd(e, "SAVE\\*", &l) && l.n == 1 && !strcmp(l.s[0], u));       /* returned as it is, no conversion */
    CHECK(g_get(e, "SAVE\\\xD0\x96\xD1\x83\xD0\xBA", buf, sizeof buf) == 3);
    CHECK(dl(e, "SAVE\\\xD0\x96\xD1\x83\xD0\xBA"));
    CHECK(dir_count("SAVE") == 0);
    /* ill-formed bytes: with the layer off the guest sees what the host does with them (kept raw, or refused) */
    uint32_t h = cf(e, "SAVE\\\xA8\xE6", GENERIC_WRITE, 0, CREATE_ALWAYS);
    if (h != INVALID) {
        wr(e, h, "raw", 3);
        ch(e, h);
        if (dir_has_exact("SAVE", "\xA8\xE6")) {                          /* the raw bytes, not UTF-8 */
            CHECK(!dir_has_exact("SAVE", "\xD0\x81\xD0\xB6"));
            CHECK(fnd(e, "SAVE\\*", &l) && in_list(&l, "\xA8\xE6"));
            CHECK(dl(e, "SAVE\\\xA8\xE6"));
        } else { n_skipped++; clear_dir("SAVE"); }                          /* a host that mangles the bytes (Node fs) */
    } else n_skipped++;
    /* case is ASCII-only, as before */
    if (g_case_sensitive && !strict) {
        CHECK(g_put(e, "SAVE\\\xD0\xB0", "a", CREATE_ALWAYS));              /* а as UTF-8 bytes, which every host accepts */
        CHECK(g_get(e, "SAVE\\\xD0\x90", buf, sizeof buf) < 0);             /* А is not found for а with the layer off */
        CHECK(dl(e, "SAVE\\\xD0\xB0"));
    }
    CHECK(dir_count("SAVE") == 0);
    printf("off: names go to the host byte for byte, listing unchanged: PASS\n");
}

/* ========================================================================== boundary */
static void cyr(char *o, int n, int shift) { for (int i = 0; i < n; i++) o[i] = (char)(0xE0 + (i + shift) % 32); o[n] = 0; }   /* n letters а..я */
static void t_boundary(void) {
    Eng *e = &g_eng[0];
    name_cp1251_set(1);
    NameList l;
    char leaf[600], path[900], buf[8];
    /* a component of 127 letters = 254 UTF-8 bytes: fits NAME_MAX on every host */
    cyr(leaf, 127, 0);
    snprintf(path, sizeof path, "SAVE\\%s", leaf);
    if (!strict || strlen(root) + 6 + 254 < 500) {   /* strict keeps names in 512-byte buffers: a long scratch root is refused cleanly */
        CHECK(g_put(e, path, "127", CREATE_ALWAYS));
        CHECK(fnd(e, "SAVE\\*", &l) && l.n == 1 && !strcmp(l.s[0], leaf) && strlen(l.s[0]) == 127);
        CHECK(g_get(e, path, buf, sizeof buf) == 3);
        CHECK(dl(e, path));
    }
    /* 128 letters = 256 bytes (> NAME_MAX = 255) and 255 letters = 510 bytes: the host decides; whatever happens
       is consistent: a refusal leaves nothing behind, a success is a full circle */
#ifdef PORT_NODE_BUILD
    /* NODERAWFS: emscripten's struct dirent keeps 255 bytes of name, so an entry longer than NAME_MAX that Node's fs created on APFS can neither be
       listed nor unlinked from inside the module: the over-long names are exercised by the native and WasmFS runs only */
    int lens[] = { 0 };
    const int over_long_ok = 0;
#else
    int lens[] = { 128, 200, 255 };
    const int over_long_ok = 1;
#endif
    for (size_t k = 0; k < sizeof lens / sizeof lens[0]; k++) {
        if (!lens[k]) continue;
        cyr(leaf, lens[k], 1);
        snprintf(path, sizeof path, "SAVE\\%s", leaf);
        if (g_put(e, path, "long", CREATE_ALWAYS)) {
            /* struct dirent holds 255 bytes of name on every libc this runs on: a longer entry may come back cut by the host
               (Node's fs under NODERAWFS does), so only the exact round trip of a representable listing is asserted */
            if (fnd(e, "SAVE\\*", &l) && l.n == 1 && strlen(l.s[0]) == strlen(leaf)) CHECK(!strcmp(l.s[0], leaf));
            CHECK(g_get(e, path, buf, sizeof buf) == 4);
            CHECK(dl(e, path));
            printf("boundary: a %d-letter component (%d UTF-8 bytes): created and round-tripped\n", lens[k], 2 * lens[k]);
        } else {
            CHECK(dir_count("SAVE") == 0);
            printf("boundary: a %d-letter component (%d UTF-8 bytes): refused by the host/strict (error %u), nothing left behind\n", lens[k], 2 * lens[k], g_err);
        }
    }
    /* guest component longer than the 512 bytes of the host component buffers */
    cyr(leaf, 300, 2);
    snprintf(path, sizeof path, "SAVE\\%s", leaf);
    /* 600 bytes in one component is invalid on Windows (255) and on most hosts; a host that stores it anyway (APFS, Node) may
       fail to remove it again by name, so only "no crash, no overrun" is asserted and the host side is cleaned directly */
    if (over_long_ok) {
        (void)g_put(e, path, "x", CREATE_ALWAYS);
        (void)dl(e, path);
        clear_dir("SAVE");
    }
    CHECK(dir_count("SAVE") == 0);
    /* the longest Windows path: 259 characters from C:\Games\Korsary2\ on, in 50-letter components */
    {
        char full[400] = "C:\\Games\\Korsary2\\", part[64];
        int k = 0;
        while (strlen(full) < 259) {
            size_t room = 259 - strlen(full);
            int last = room <= 51, n = last ? (int)room : 50;
            cyr(part, n, k++);
            strcat(full, part);
            if (!last) strcat(full, "\\");
        }
        CHECK(strlen(full) == 259);
        int ok = g_put(e, full, "deep", CREATE_ALWAYS);
        if (strict) {
            /* strict keeps its own name buffers (512): the registry refuses what does not fit, cleanly */
            printf("boundary: %zu-char path in strict: %s (error %u)\n", strlen(full), ok ? "created" : "refused", ok ? 0u : g_err);
        } else CHECK(ok);
        if (ok) {
            char dirpath[400];
            snprintf(dirpath, sizeof dirpath, "%s", full);
            char *sl = strrchr(dirpath, '\\');
            *sl = 0;
            char spec[420];
            snprintf(spec, sizeof spec, "%s\\*", dirpath);
            CHECK(fnd(e, spec, &l) && l.n == 1 && !strcmp(l.s[0], strrchr(full, '\\') + 1));
            CHECK(g_get(e, full, buf, sizeof buf) == 4);
            CHECK(dl(e, full));
        }
        /* a path of 300 characters (not valid on Windows either) must not corrupt anything */
        char longp[700] = "C:\\Games\\Korsary2\\";
        for (int i = 0; i < 6; i++) { cyr(part, 50, i); strcat(longp, part); strcat(longp, "\\"); }
        strcat(longp, "f");
        (void)g_put(e, longp, "x", CREATE_ALWAYS);
        (void)dl(e, longp);
    }
    {   /* clean what the nested creation made below the game root: the first component is 50 letters from shift 0 */
        char first[64], u[200];
        cyr(first, 50, 0);
        expect_host_name(first, u);
        rm_rf(hp(u));
    }
    printf("boundary: 127/128/200/255-letter names, 300-byte component, 259-char and 300-char paths: PASS\n");
}

/* ========================================================================== strict */
static void t_strict(void) {
    Eng *e = &g_eng[0];
    name_cp1251_set(1);
    /* K2 refused every CP1251 name in strict ("component is not well-formed UTF-8"); with the layer they are UTF-8 */
    CHECK(g_put(e, "SAVE\\\xD2\xE5\xF1\xF2 1", "strict", CREATE_ALWAYS));
    CHECK(dir_has_exact("SAVE", "\xD0\xA2\xD0\xB5\xD1\x81\xD1\x82 1"));
    char buf[16];
    CHECK(g_get(e, "SAVE\\\xF2\xE5\xF1\xF2 1", buf, sizeof buf) == 6);   /* тест 1: other case, same object */
    NameList l;
    CHECK(fnd(e, "SAVE\\*", &l) && l.n == 1 && !strcmp(l.s[0], "\xD2\xE5\xF1\xF2 1"));
    /* identity: an open of the name blocks the open of its other case, like on Windows */
    uint32_t a = cf(e, "SAVE\\\xD2\xE5\xF1\xF2 1", GENERIC_READ, FS_R, OPEN_EXISTING);
    CHECK(a != INVALID);
    uint32_t b = cf(e, "SAVE\\\xF2\xC5\xD1\xF2 1", GENERIC_WRITE, FS_R | FS_W, OPEN_EXISTING);
    CHECK(b == INVALID && g_err == ERROR_SHARING_VIOLATION);              /* write access vs a reader that shares only read */
    uint32_t c = cf(e, "SAVE\\\xF2\xE5\xF1\xF2 1", GENERIC_READ, FS_R, OPEN_EXISTING);
    CHECK(c != INVALID);                                                  /* read + read: compatible */
    CHECK(ch(e, a) && ch(e, c));
    CHECK(dl(e, "SAVE\\\xF2\xC5\xD1\xF2 1"));
    CHECK(dir_count("SAVE") == 0);
    /* a name with the layer OFF is still refused when it is not UTF-8 (unchanged K2 behaviour) */
    name_cp1251_set(0);
    uint32_t r = cf(e, "SAVE\\\xD2\xE5\xF1\xF2", GENERIC_WRITE, 0, CREATE_ALWAYS);
    CHECK(r == INVALID && g_err == ERROR_INVALID_NAME);
    name_cp1251_set(1);
    /* a legacy ill-formed host entry is refused by the same rule (listed to the game, but strict cannot give it an identity) */
    if (host_put("SAVE/\xD2\xE5\xF1\xF3", "legacy") && dir_has_exact("SAVE", "\xD2\xE5\xF1\xF3")) {
        uint32_t lh = cf(e, "SAVE\\\xD2\xE5\xF1\xF3", GENERIC_READ, FS_R, OPEN_EXISTING);
        CHECK(lh == INVALID && g_err == ERROR_INVALID_NAME);
    }
    clear_dir("SAVE");
    printf("strict: Cyrillic names pass the K2 policy, identity folds case, layer off still refuses CP1251: PASS\n");
}

/* ========================================================================== SAVE_META */
#if SAVE_META_ON
static void t_savemeta(void) {
    Eng *e = &g_eng[0];
    name_cp1251_set(1);
    const char *slot = "\xCE\xEA\xF1\xE1\xE5\xE9 \xEF\xEE\xF0\xF2 12-11-2026";   /* Оксбей порт 12-11-2026 */
    char host_slot[200];
    expect_host_name(slot, host_slot);
    char gpath[300];
    snprintf(gpath, sizeof gpath, "SAVE\\%s", slot);
    CHECK(g_put(e, gpath, "save", CREATE_ALWAYS));
    char meta[400];
    snprintf(meta, sizeof meta, "SAVE_META/%s.time", host_slot);
    struct stat st;
    CHECK(stat(hp(meta), &st) == 0 && st.st_size == 8);                  /* the sidecar is named by the UTF-8 slot name */
    NameList l;
    CHECK(fnd(e, "SAVE\\*", &l) && l.n == 1 && !strcmp(l.s[0], slot));
    CHECK(l.ctime[0] != 0);                                              /* ftCreationTime comes from the sidecar */
    /* a rewrite keeps the original record; the other case is the same slot */
    uint64_t t0 = l.ctime[0];
    CHECK(g_put(e, "SAVE\\\xCE\xCA\xD1\xC1\xC5\xC9 \xCF\xCE\xD0\xD2 12-11-2026", "save2", CREATE_ALWAYS));
    CHECK(fnd(e, "SAVE\\*", &l) && l.n == 1 && l.ctime[0] == t0);
    CHECK(dl(e, gpath));
    CHECK(fnd(e, "SAVE\\*", &l) && l.n == 0);   /* only . and .. remain */
    unlink(hp(meta));
    rm_rf(hp("SAVE_TX"));
    printf("savemeta: sidecar named by the UTF-8 slot, ftCreationTime in the CP1251 listing, case-folded slot: PASS\n");
}
#endif

/* ========================================================================== threads */
typedef struct { int idx; int rounds; int fails; char first[160]; } TArg;
#define TFAIL(a, ...) do { if (!(a)->fails++) snprintf((a)->first, sizeof (a)->first, __VA_ARGS__); } while (0)
/* Every thread works in its OWN Cyrillic directory SAVE\Поток-<n>: listing a directory that other threads create and delete in at the same
   time is not reliable on every host (APFS through Node's fs skips entries of a directory modified during the scan), which is a property of
   the host and not of the layer. What is shared and concurrent here is the layer itself: the env switch, the tables, map_path's lookups of
   SAVE and of the 8 directory names, the case folding, the strict registry. */
static void *t_worker(void *p) {
    TArg *a = p;
    Eng *e = &g_eng[a->idx];
    char dir[64], dirU[64];
    snprintf(dir, sizeof dir, "SAVE\\\xCF\xEE\xF2\xEE\xEA-%d", a->idx);          /* Поток-n */
    snprintf(dirU, sizeof dirU, "save\\\xEF\xCE\xD2\xCE\xCA-%d", a->idx);        /* other case of everything */
    for (int i = 0; i < a->rounds; i++) {
        char leaf[96], path[160], buf[16], upper[160], spec[160];
        snprintf(leaf, sizeof leaf, "\xD2\xE5\xF1\xF2-%d", i);
        snprintf(path, sizeof path, "%s\\%s", dir, leaf);
        if (!g_put(e, path, "thr", CREATE_ALWAYS)) { TFAIL(a, "round %d: create failed, error %u", i, g_err); continue; }
        NameList *l = malloc(sizeof *l);
        snprintf(spec, sizeof spec, "%s\\\xF2\xE5*", dirU);
        if (!fnd(e, spec, l)) TFAIL(a, "round %d: find failed, error %u", i, g_err);
        else if (!in_list(l, leaf) || l->n != 1) TFAIL(a, "round %d: find returned %d entries, the thread's own file %s", i, l->n, in_list(l, leaf) ? "listed" : "missing");
        free(l);
        int got = g_get(e, path, buf, sizeof buf);
        if (got != 3) TFAIL(a, "round %d: open by name read %d, error %u", i, got, g_err);
        snprintf(upper, sizeof upper, "%s\\\xD2\xC5\xD1\xD2-%d", dirU, i);
        got = g_get(e, upper, buf, sizeof buf);
        if (got != 3) TFAIL(a, "round %d: open by the other case read %d, error %u", i, got, g_err);
        if (!dl(e, upper)) TFAIL(a, "round %d: delete (other case) failed, error %u", i, g_err);
        name_cp1251_on();
    }
    return NULL;
}
static void t_threads(void) {
    Eng *e0 = &g_eng[0];
    name_cp1251_set(1);
    for (int i = 1; i <= 8; i++) { char d[64]; snprintf(d, sizeof d, "SAVE\\\xCF\xEE\xF2\xEE\xEA-%d", i); CHECK(mkd(e0, d)); }
    pthread_t th[8];
    TArg arg[8];
    for (int i = 0; i < 8; i++) { arg[i] = (TArg){ i + 1, 40, 0, "" }; CHECK(!pthread_create(&th[i], NULL, t_worker, &arg[i])); }
    int fails = 0;
    for (int i = 0; i < 8; i++) { pthread_join(th[i], NULL); fails += arg[i].fails; }
    for (int i = 0; i < 8; i++) if (arg[i].fails) fprintf(stderr, "thread %d: %d failures, first: %s\n", arg[i].idx, arg[i].fails, arg[i].first);
    CHECK(fails == 0);
    for (int i = 1; i <= 8; i++) { char d[64]; snprintf(d, sizeof d, "SAVE\\\xCF\xEE\xF2\xEE\xEA-%d", i); CHECK(rmd(e0, d)); }
    CHECK(dir_count("SAVE") == 0);
    printf("threads: 8 x 40 rounds of create/find/open (other case)/delete of Cyrillic names in 8 Cyrillic directories: PASS\n");
}

/* ========================================================================== SAVE_TX scenarios for the page recovery */
#if SAVE_META_ON
static const char *k_tx_slot = "\xCE\xEA\xF1\xE1\xE5\xE9 \xEF\xEE\xF0\xF2 12-11-2026";   /* Оксбей порт 12-11-2026 */
static int tx_stage(Eng *e, const char *gp, const char *data) { return g_put(e, gp, data, CREATE_ALWAYS); }
static int tx_main(int argc, char **argv) {
    if (argc < 4) return 2;
    g_mem = calloc(1, 0x100000);
    for (int i = 0; i < 16; i++) eng_init(&g_eng[i], i);
    snprintf(root, sizeof root, "%s", argv[2]);
    snprintf(g_game_root, sizeof g_game_root, "%s", argv[2]);
    setenv("PORT_FILE_SNAPSHOT", "0", 1);
    name_cp1251_set(1);
    __atomic_store_n(&g_save_tx_on, strcmp(argv[3], "seed") ? 1 : 0, __ATOMIC_RELAXED);   /* the seed is a slot from before SAVE_TX was on */
    Eng *e = &g_eng[0];
    char gp[300], gp2[300];
    snprintf(gp, sizeof gp, "SAVE\\%s", k_tx_slot);
    snprintf(gp2, sizeof gp2, "SAVE\\%s 2", k_tx_slot);
    if (!strcmp(argv[3], "seed")) {
        mkdir(hp("SAVE"), 0755);
        return tx_stage(e, gp, "OLD-VERSION") && tx_stage(e, "SAVE\\Keep", "KEEP") ? 0 : 1;
    }
    /* the engine's overwrite: DeleteFileA(old) -> CreateFileA(CREATE_ALWAYS, new) -> two write cycles */
    if (!strcmp(argv[3], "overwrite")) return dl(e, gp) && tx_stage(e, gp, "NEW-1") && tx_stage(e, gp, "NEW-2") ? 0 : 1;
    if (!strcmp(argv[3], "kill-after-delete")) { dl(e, gp); _exit(77); }
    if (!strcmp(argv[3], "kill-after-stage1")) { dl(e, gp); tx_stage(e, gp, "NEW-1"); _exit(77); }
    if (!strcmp(argv[3], "rename")) return dl(e, gp) && tx_stage(e, gp2, "NEW-1") && tx_stage(e, gp2, "NEW-2") ? 0 : 1;
    if (!strcmp(argv[3], "delete")) return dl(e, gp) ? 0 : 1;
    return 2;
}
#endif

int main(int argc, char **argv) {
#if SAVE_META_ON
    if (argc >= 2 && !strcmp(argv[1], "--tx")) return tx_main(argc, argv);
#endif
    const char *mode = argc > 2 ? argv[2] : "permissive";
    if (!strcmp(mode, "strict")) setenv("PORT_STRICT_FILE_SHARE", "1", 1); else unsetenv("PORT_STRICT_FILE_SHARE");
    strict = strict_share();
    CHECK(strict == !strcmp(mode, "strict"));
    use_threads = !getenv("NAME_NO_THREADS");
    CHECK(!setenv("PORT_FILE_SNAPSHOT", "0", 1));
    g_mem = calloc(1, 0x100000);
    CHECK(g_mem);
    for (int i = 0; i < 16; i++) eng_init(&g_eng[i], i);
    (void)snapshot_enabled(); (void)snapshot_max(); (void)host_seconds();
    snprintf(root, sizeof root, "%s/korsary-name-XXXXXX", argc > 1 ? argv[1] : "/tmp");
    CHECK(mkdtemp(root));
    snprintf(g_game_root, sizeof g_game_root, "%s", root);
    CHECK(mkdir(hp("SAVE"), 0755) == 0);
    printf("-- name layer test, %s share mode, %s\n", strict ? "strict" : "permissive", SAVE_META_ON ? "SAVE_META on" : "SAVE_META off");
    {   /* is the host case-sensitive? */
        host_put("CASE-PROBE", "x");
        FILE *f = fopen(hp("case-probe"), "rb");
        g_case_sensitive = f == NULL;
        if (f) fclose(f);
        unlink(hp("CASE-PROBE"));
        printf("host file system is %s\n", g_case_sensitive ? "case-sensitive" : "case-insensitive");
    }
    t_units();
    t_cycle();
    t_undefined_byte();
    t_case();
    t_copy_paths();
    t_find();
    t_legacy();
    t_off();
    t_boundary();
    if (strict) t_strict();
#if SAVE_META_ON
    t_savemeta();
#endif
    if (use_threads) t_threads();
    printf("name layer (%s): all PASS, %d part(s) skipped by the host (%d move cycles executed)\n", strict ? "strict" : "permissive", n_skipped, g_moves);
    rm_rf(root);
    return 0;
}
