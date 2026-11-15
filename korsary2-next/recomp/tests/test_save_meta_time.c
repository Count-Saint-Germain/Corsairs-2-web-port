/* П1.1 durable save-time sidecar: drives the real production handlers
   w_CreateFileA / w_DeleteFileA / w_MoveFileA and find_next from kernel32.c
   over synthetic temp directories (never player data). The native run
   compiles with -DPORT_SAVE_META=1 to emulate the browser build (whose only
   extra restriction is that CREATE_NEW and MoveFileA are rejected before any
   path mapping); the wasm run gets that mode automatically; the Node run
   keeps the plain stat path and asserts it instead. */
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "../host/core.c"
#include "../host/kernel32.c"
uint8_t *g_mem;

static GuestThread thread;
static CPU c;

/* FILETIME of a Unix second (same conversion as filetime_from_timespec), so
   the browser build can still build known stamps for the tests. */
static uint64_t ft_of_unix(time_t sec) { return (uint64_t)((int64_t)sec + 11644473600ll) * 10000000ull; }

static uint32_t create_guest(const char *guest, uint32_t disp) {
    strcpy((char *)HP(0x2000), guest);
    c.esp = 0x1000;
    W32(0x1000, 0); W32(0x1004, 0x2000); W32(0x1008, 0x40000000u);   /* GENERIC_WRITE */
    W32(0x100c, 0); W32(0x1010, 0); W32(0x1014, disp);
    W32(0x1018, 0); W32(0x101c, 0);
    w_CreateFileA(&c);
    return c.eax;
}
static int delete_guest(const char *guest) {
    strcpy((char *)HP(0x2000), guest);
    c.esp = 0x1000; W32(0x1000, 0); W32(0x1004, 0x2000);
    w_DeleteFileA(&c);
    return c.eax;
}
static int move_guest(const char *src, const char *dst) {
    strcpy((char *)HP(0x2000), src); strcpy((char *)HP(0x2400), dst);
    c.esp = 0x1000; W32(0x1000, 0); W32(0x1004, 0x2000); W32(0x1008, 0x2400);
    w_MoveFileA(&c);
    return c.eax;
}
static uint64_t find_record(const char *dir, const char *pattern, const char *name,
                            uint64_t *access, uint64_t *write) {
    FindState fs;
    memset(&fs, 0, sizeof fs);
    snprintf(fs.dir, sizeof fs.dir, "%s", dir);
    snprintf(fs.pattern, sizeof fs.pattern, "%s", pattern);
    fs.d = opendir(dir); assert(fs.d);
    uint32_t out = 0x3000;
    int ok = find_next(&fs, out);
    closedir(fs.d);
    assert(ok);
    assert(!strcmp((char *)HP(out + 44), name));
    if (access) *access = R64(out + 12);
    if (write) *write = R64(out + 20);
    return R64(out + 4);
}
/* Raw sidecar record bytes on disk; *exists reports the exact-name file. */
static uint64_t sidecar_raw(const char *slot, int *exists) {
    char path[1100];
    snprintf(path, sizeof path, "%s/SAVE_META/%s.time", g_game_root, slot);
    FILE *f = fopen(path, "rb");
    if (exists) *exists = f != NULL;
    if (!f) return 0;
    uint8_t b[8] = {0};
    size_t n = fread(b, 1, 8, f);
    fclose(f);
    if (exists && n != 8) *exists = -1;   /* present but short */
    uint64_t ft = 0;
    for (int i = 7; i >= 0; i--) ft = (ft << 8) | b[i];
    return ft;
}
static void put_sidecar(const char *slot, const uint8_t *b, size_t n) {
    char path[1100];
    snprintf(path, sizeof path, "%s/SAVE_META", g_game_root);
    mkdir(path, 0755);
    snprintf(path, sizeof path, "%s/SAVE_META/%s", g_game_root, slot);
    FILE *f = fopen(path, "wb"); assert(f);
    if (n) fwrite(b, 1, n, f);
    fclose(f);
}
static void put_save_file(const char *dir, const char *name, const char *text) {
    char path[1200];
    snprintf(path, sizeof path, "%s/%s", dir, name);
    FILE *f = fopen(path, "wb"); assert(f && fputs(text, f) >= 0 && !fclose(f));
}
/* remove synthetic test files recursively (files, then the directory itself) */
static void cleanup_tree(const char *dir) {
    DIR *d = opendir(dir);
    if (!d) return;
    struct dirent *e;
    while ((e = readdir(d))) {
        if (!strcmp(e->d_name, ".") || !strcmp(e->d_name, "..")) continue;
        char p[1200];
        snprintf(p, sizeof p, "%s/%s", dir, e->d_name);
        cleanup_tree(p);              /* recursion is a no-op on regular files */
        struct stat st;
        if (stat(p, &st) == 0 && (rmdir(p) != 0)) assert(unlink(p) == 0);
    }
    closedir(d);
    assert(rmdir(dir) == 0);
}

#if SAVE_META_ON
static void browser_mode(const char *root, const char *save_dir) {
    /* create-new stamps the current time and find_next reads it back */
    uint64_t before = guest_time_100ns();
    uint32_t h = create_guest("SAVE\\slot1", 4);   /* OPEN_ALWAYS creates */
    assert(h != 0xffffffffu);
    handle_close(h);
    int exists = 0;
    uint64_t ft1 = sidecar_raw("slot1", &exists);
    assert(exists == 1 && ft1 >= before && ft1 <= guest_time_100ns() + 10000000ull);
    uint64_t access = 1, write = 1;
    assert(find_record(save_dir, "slot1", "slot1", &access, &write) == ft1);
    assert(access == 0 && write == 0);   /* only creation is known in the browser */

    /* CREATE_NEW stamps too (native emulation only: the browser rejects it) */
#if !defined(__EMSCRIPTEN__)
    h = create_guest("SAVE\\slot1n", 1);
    assert(h != 0xffffffffu && exists);
    handle_close(h);
    assert(sidecar_raw("slot1n", &exists) != 0 && exists == 1);
#endif

    /* CREATE_ALWAYS over an absent name is a genuine creation: this is the
       game's normal overwrite flow (it deletes the old slot first), so it
       must stamp a fresh time, not leave the record missing */
    uint64_t before2 = guest_time_100ns();
    h = create_guest("SAVE\\slot1c", 2);
    assert(h != 0xffffffffu);
    handle_close(h);
    uint64_t ft1c = sidecar_raw("slot1c", &exists);
    assert(exists == 1 && ft1c >= before2 && ft1c <= guest_time_100ns() + 10000000ull);
    assert(find_record(save_dir, "slot1c", "slot1c", NULL, NULL) == ft1c);

    /* a rewrite keeps the recorded creation time (XP-era semantics) */
    const uint64_t fixed = ft_of_unix(1700000000);   /* 2023-11-14, inside the honest range */
    uint8_t b8[8];
    for (int i = 0; i < 8; i++) b8[i] = (uint8_t)(fixed >> (8 * i));
    put_save_file(save_dir, "slot2", "old");
    put_sidecar("slot2.time", b8, 8);
    h = create_guest("SAVE\\slot2", 2);   /* CREATE_ALWAYS truncates */
    assert(h != 0xffffffffu);
    handle_close(h);
    assert(sidecar_raw("slot2", &exists) == fixed && exists == 1);
    assert(find_record(save_dir, "slot2", "slot2", NULL, NULL) == fixed);
    h = create_guest("SAVE\\slot2", 5);   /* TRUNCATE_EXISTING also keeps it */
    assert(h != 0xffffffffu);
    handle_close(h);
    assert(sidecar_raw("slot2", &exists) == fixed && exists == 1);

    /* a legacy slot without a record is stamped at its first rewrite */
    put_save_file(save_dir, "slot3", "legacy");
    h = create_guest("SAVE\\slot3", 2);
    assert(h != 0xffffffffu);
    handle_close(h);
    assert(sidecar_raw("slot3", &exists) != 0 && exists == 1);

    /* plain opens invent nothing: no record stays no record */
    put_save_file(save_dir, "slot4", "quiet");
    h = create_guest("SAVE\\slot4", 3);   /* OPEN_EXISTING */
    assert(h != 0xffffffffu);
    handle_close(h);
    h = create_guest("SAVE\\slot4", 4);   /* OPEN_ALWAYS on an existing file */
    assert(h != 0xffffffffu);
    handle_close(h);
    assert(sidecar_raw("slot4", &exists) == 0 && exists == 0);

    /* delete removes the file and its record */
    assert(delete_guest("SAVE\\slot2") == 1);
    struct stat st;
    char path[1200];
    snprintf(path, sizeof path, "%s/SAVE/slot2", root);
    assert(stat(path, &st) != 0);
    assert(sidecar_raw("slot2", &exists) == 0 && exists == 0);
    assert(delete_guest("SAVE\\slot2") == 0);   /* already gone: clean failure */

    /* a move carries the record to the new name (browser build refuses moves) */
#if !defined(__EMSCRIPTEN__) || defined(PORT_NODE_BUILD)
    put_save_file(save_dir, "slot5", "moved");
    put_sidecar("slot5.time", b8, 8);
    assert(move_guest("SAVE\\slot5", "SAVE\\slot6") == 1);
    assert(sidecar_raw("slot5", &exists) == 0 && exists == 0);
    assert(sidecar_raw("slot6", &exists) == fixed && exists == 1);
    assert(find_record(save_dir, "slot6", "slot6", NULL, NULL) == fixed);
#else
    assert(move_guest("SAVE\\slot1", "SAVE\\slotX") == 0);
#endif

    /* short, zero and out-of-range records stay "unknown" */
    const uint8_t short3[3] = {0x11, 0x22, 0x33};
    put_sidecar("slot3.time", short3, 3);
    assert(find_record(save_dir, "slot3", "slot3", NULL, NULL) == 0);
    const uint8_t zeros[8] = {0};
    put_sidecar("slot3.time", zeros, 8);
    assert(find_record(save_dir, "slot3", "slot3", NULL, NULL) == 0);
    const uint8_t garbage[8] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
    put_sidecar("slot3.time", garbage, 8);
    assert(find_record(save_dir, "slot3", "slot3", NULL, NULL) == 0);
    for (int i = 0; i < 8; i++) b8[i] = (uint8_t)(ft_of_unix(1700000000) >> (8 * i));
    put_sidecar("slot3.time", b8, 8);
    assert(find_record(save_dir, "slot3", "slot3", NULL, NULL) == ft_of_unix(1700000000));

    /* the record is found under a different letter case of its file name */
    put_save_file(save_dir, "slot7", "case");
    put_sidecar("Slot7.time", b8, 8);   /* sidecar spelled differently from the slot */
    assert(find_record(save_dir, "slot7", "slot7", NULL, NULL) == ft_of_unix(1700000000));

    /* a sidecar write failure never breaks the save file operation */
    snprintf(path, sizeof path, "%s/SAVE_META", root);
    cleanup_tree(path);   /* drop the directory: the blocker below is a regular file */
    FILE *blocker = fopen(path, "wb"); assert(blocker && !fclose(blocker));
    h = create_guest("SAVE\\slot8", 4);
    assert(h != 0xffffffffu);   /* the open itself still succeeds */
    handle_close(h);
    snprintf(path, sizeof path, "%s/SAVE/slot8", root);
    assert(stat(path, &st) == 0);
    assert(find_record(save_dir, "slot8", "slot8", NULL, NULL) == 0);
    assert(unlink(path) == 0);
    snprintf(path, sizeof path, "%s/SAVE_META", root);
    assert(unlink(path) == 0);   /* the blocking regular file again */

    /* records are not consulted outside the game root's flat SAVE layout */
    char prog_dir[1200], sub_dir[1200];
    snprintf(prog_dir, sizeof prog_dir, "%s/PROGRAM", root);
    snprintf(sub_dir, sizeof sub_dir, "%s/SAVE/sub", root);
    assert(mkdir(prog_dir, 0755) == 0 && mkdir(sub_dir, 0755) == 0);
    put_save_file(prog_dir, "slot1", "not a slot");
    put_save_file(sub_dir, "slot1", "not a slot");
    assert(find_record(prog_dir, "slot1", "slot1", NULL, NULL) == 0);
    assert(find_record(sub_dir, "slot1", "slot1", NULL, NULL) == 0);
}

/* ---- E5: the language label SAVE_META/<slot>.lang (host/kernel32.c, "language label"): exactly two bytes "en", written only when a slot
   is genuinely created while the language overlay is on (PORT_OVERLAY); the Russian mode (overlay off) writes nothing new */
static int lang_raw(const char *slot, uint8_t out[8], size_t *n, int *exists) {
    char path[1100];
    snprintf(path, sizeof path, "%s/SAVE_META/%s.lang", g_game_root, slot);
    FILE *f = fopen(path, "rb");
    *exists = f != NULL;
    *n = 0;
    if (!f) return 0;
    *n = fread(out, 1, 8, f);
    fclose(f);
    return 1;
}
static int lang_is(const char *slot, const char *tag) {
    uint8_t b[8]; size_t n; int ex;
    return lang_raw(slot, b, &n, &ex) && n == 2 && b[0] == (uint8_t)tag[0] && b[1] == (uint8_t)tag[1];
}
static int lang_exists(const char *slot) { uint8_t b[8]; size_t n; int ex; lang_raw(slot, b, &n, &ex); return ex; }
static void put_lang(const char *slot, const char *bytes, size_t n) {
    char name[1100];
    snprintf(name, sizeof name, "%s.lang", slot);
    put_sidecar(name, (const uint8_t *)bytes, n);
}
static void overlay_set(const char *dir) {
    if (dir) setenv("PORT_OVERLAY", dir, 1); else unsetenv("PORT_OVERLAY");
    overlay_test_reset();
}
static void lang_label_mode(const char *root, const char *save_dir) {
    char ov[] = "/tmp/korsary-save-lang-ov-XXXXXX";
    assert(mkdtemp(ov));
    int exists = 0;
    uint32_t h;
    struct stat st;
    char path[1200];
    const uint64_t fixed = ft_of_unix(1700000000);
    uint8_t b8[8];
    for (int i = 0; i < 8; i++) b8[i] = (uint8_t)(fixed >> (8 * i));

    /* Russian mode (overlay off): a genuine creation stamps the time and writes NO label */
    overlay_set(NULL);
    assert(!overlay_active());
    h = create_guest("SAVE\\lr1", 2);
    assert(h != 0xffffffffu); handle_close(h);
    assert(sidecar_raw("lr1", &exists) != 0 && exists == 1);
    assert(!lang_exists("lr1"));
    snprintf(path, sizeof path, "%s/SAVE_META", root);
    int count = 0;
    { DIR *d = opendir(path); struct dirent *e; while (d && (e = readdir(d))) if (strstr(e->d_name, ".lang")) count++; if (d) closedir(d); }
    assert(count == 0);   /* not a single .lang file was written by the Russian mode */

    /* English mode (overlay on): a genuine creation writes exactly "en" next to the time record; every creation disposition does */
    overlay_set(ov);
    assert(overlay_active());
    uint32_t disps[] = {2, 4};   /* CREATE_ALWAYS over an absent name (the overwrite flow), OPEN_ALWAYS that creates */
    const char *names[] = {"le1", "le2"};
    for (int i = 0; i < 2; i++) {
        uint64_t before = guest_time_100ns();
        char guest[64];
        snprintf(guest, sizeof guest, "SAVE\\%s", names[i]);
        h = create_guest(guest, disps[i]);
        assert(h != 0xffffffffu); handle_close(h);
        uint8_t raw[8]; size_t n; int ex;
        assert(lang_raw(names[i], raw, &n, &ex) && n == 2 && raw[0] == 'e' && raw[1] == 'n');
        uint64_t ft = sidecar_raw(names[i], &exists);
        assert(exists == 1 && ft >= before);
        assert(find_record(save_dir, names[i], names[i], NULL, NULL) == ft);   /* find_next reads only the time record */
    }
#if !defined(__EMSCRIPTEN__)
    h = create_guest("SAVE\\le3", 1);   /* CREATE_NEW (native emulation only: the browser refuses it) */
    assert(h != 0xffffffffu); handle_close(h);
    assert(lang_is("le3", "en"));
#endif
    /* the label is not part of SAVE: the slot folder lists no .lang */
    snprintf(path, sizeof path, "%s/SAVE/le1.lang", root);
    assert(stat(path, &st) != 0);

    /* an in-place rewrite keeps the label (and the time) as it was; a legacy slot without a label is not labelled by a rewrite */
    put_save_file(save_dir, "lk1", "old"); put_sidecar("lk1.time", b8, 8); put_lang("lk1", "ru", 2);
    h = create_guest("SAVE\\lk1", 2); assert(h != 0xffffffffu); handle_close(h);
    assert(lang_is("lk1", "ru") && sidecar_raw("lk1", &exists) == fixed);
    h = create_guest("SAVE\\lk1", 5); assert(h != 0xffffffffu); handle_close(h);
    assert(lang_is("lk1", "ru"));
    put_save_file(save_dir, "lk2", "legacy"); put_sidecar("lk2.time", b8, 8);
    h = create_guest("SAVE\\lk2", 2); assert(h != 0xffffffffu); handle_close(h);
    assert(!lang_exists("lk2"));
    h = create_guest("SAVE\\lk2", 3); assert(h != 0xffffffffu); handle_close(h);   /* plain opens invent nothing */
    h = create_guest("SAVE\\lk2", 4); assert(h != 0xffffffffu); handle_close(h);
    assert(!lang_exists("lk2"));

    /* delete removes the label with the slot and the time, in either mode */
    assert(delete_guest("SAVE\\le1") == 1);
    assert(!lang_exists("le1") && sidecar_raw("le1", &exists) == 0 && exists == 0);
    put_save_file(save_dir, "ld1", "x"); put_sidecar("ld1.time", b8, 8); put_lang("ld1", "en", 2);
    overlay_set(NULL);   /* deleted by a Russian session: the English label must not survive for a later Russian slot of this name */
    assert(delete_guest("SAVE\\ld1") == 1);
    assert(!lang_exists("ld1") && sidecar_raw("ld1", &exists) == 0 && exists == 0);
    assert(delete_guest("SAVE\\ld1") == 0);

    /* the stale-label guard: a label left by a slot that vanished must not claim a slot created later in the Russian mode */
    put_lang("ls1", "en", 2);
    h = create_guest("SAVE\\ls1", 2); assert(h != 0xffffffffu); handle_close(h);
    assert(!lang_exists("ls1"));
    overlay_set(ov);   /* ... and in the English mode the new slot gets its own label */
    put_lang("ls2", "ru", 2);
    h = create_guest("SAVE\\ls2", 2); assert(h != 0xffffffffu); handle_close(h);
    assert(lang_is("ls2", "en"));

    /* the label is found (and deleted) under a different letter case of its name */
    put_save_file(save_dir, "LC1", "case"); put_lang("lc1", "en", 2);
    assert(delete_guest("SAVE\\LC1") == 1);
    assert(!lang_exists("lc1"));

    /* only exactly two valid bytes are a label: save_lang_read is what SAVE_TX stores in an arm line */
    uint8_t got[2];
    put_lang("lv1", "en", 2); assert(save_lang_read("lv1", got) && got[0] == 'e' && got[1] == 'n');
    put_lang("lv1", "ru", 2); assert(save_lang_read("lv1", got) && got[0] == 'r' && got[1] == 'u');
    put_lang("lv1", "xx", 2); assert(!save_lang_read("lv1", got));
    put_lang("lv1", "e", 1); assert(!save_lang_read("lv1", got));
    put_lang("lv1", "eng", 3); assert(!save_lang_read("lv1", got));
    put_lang("lv1", "", 0); assert(!save_lang_read("lv1", got));
    put_lang("lv1", "EN", 2); assert(!save_lang_read("lv1", got));
    char hex[8];
    put_lang("lv1", "en", 2); save_tx_lang_hex("lv1", hex); assert(!strcmp(hex, "656e"));
    put_lang("lv1", "zz", 2); save_tx_lang_hex("lv1", hex); assert(hex[0] == 0);
    assert(!lang_is("nothing-here", "en"));

    /* a move carries the label to the new name (the browser build refuses moves) */
#if !defined(__EMSCRIPTEN__) || defined(PORT_NODE_BUILD)
    put_save_file(save_dir, "lm1", "moved"); put_sidecar("lm1.time", b8, 8); put_lang("lm1", "en", 2);
    assert(move_guest("SAVE\\lm1", "SAVE\\lm2") == 1);
    assert(!lang_exists("lm1") && lang_is("lm2", "en") && sidecar_raw("lm2", &exists) == fixed);
    put_save_file(save_dir, "lm3", "moved");   /* a slot with a label but without a time record */
    put_lang("lm3", "ru", 2);
    assert(move_guest("SAVE\\lm3", "SAVE\\lm4") == 1);
    assert(!lang_exists("lm3") && lang_is("lm4", "ru"));
#endif

    /* a label write failure never breaks the save file operation */
    snprintf(path, sizeof path, "%s/SAVE_META", root);
    cleanup_tree(path);
    FILE *blocker = fopen(path, "wb"); assert(blocker && !fclose(blocker));
    h = create_guest("SAVE\\lf1", 4);
    assert(h != 0xffffffffu);   /* the open itself still succeeds while SAVE_META is a regular file */
    handle_close(h);
    snprintf(path, sizeof path, "%s/SAVE/lf1", root);
    assert(stat(path, &st) == 0 && unlink(path) == 0);
    snprintf(path, sizeof path, "%s/SAVE_META", root);
    assert(unlink(path) == 0);

    overlay_set(NULL);
    assert(rmdir(ov) == 0);
}
#else
static void stat_mode(const char *root, const char *save_dir) {
    (void)root;
    /* native and Node builds keep plain stat and never write a sidecar */
    put_save_file(save_dir, "slot1", "s");
    struct stat st;
    char path[1200];
    snprintf(path, sizeof path, "%s/SAVE/slot1", root);
    assert(stat(path, &st) == 0);
#if defined(__APPLE__)
    uint64_t expect = filetime_from_timespec(st.st_birthtimespec.tv_sec, st.st_birthtimespec.tv_nsec);
#else
    uint64_t expect = filetime_from_timespec(st.st_mtim.tv_sec, st.st_mtim.tv_nsec);
#endif
    assert(expect != 0);
    assert(find_record(save_dir, "slot1", "slot1", NULL, NULL) == expect);
    uint32_t h = create_guest("SAVE\\slot2", 4);   /* a created file leaves no SAVE_META */
    assert(h != 0xffffffffu);
    handle_close(h);
    snprintf(path, sizeof path, "%s/SAVE_META", root);
    assert(stat(path, &st) != 0);
}
#endif

int main(void) {
    g_mem = calloc(1, 65536); assert(g_mem);
    t_self = &thread;
    char root[] = "/tmp/korsary-save-meta-XXXXXX";
    assert(mkdtemp(root));
    snprintf(g_game_root, sizeof g_game_root, "%s", root);
    char save_dir[1200];
    snprintf(save_dir, sizeof save_dir, "%s/SAVE", root);
    assert(mkdir(save_dir, 0755) == 0);
#if SAVE_META_ON
    browser_mode(root, save_dir);
    puts("save time sidecar (browser mode, real handlers): PASS");
    lang_label_mode(root, save_dir);
    puts("save language label SAVE_META/<slot>.lang (overlay on writes en; Russian mode writes nothing; follows delete/move; invalid = none): PASS");
#else
    stat_mode(root, save_dir);
    puts("find_next stat FILETIMEs, no sidecar (native/Node mode): PASS");
#endif
    cleanup_tree(save_dir);
    cleanup_tree(root);   /* SAVE_META when it exists */
    free(g_mem);
    return 0;
}
