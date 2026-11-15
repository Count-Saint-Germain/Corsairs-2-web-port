/* Standalone experimental namespace test: no game or saved data is touched.
 * Optionally pass a newline-delimited list of manifest paths. */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../host/core.c"
#include "../experimental/lazy-loading/lazy_index.c"
uint8_t *g_mem;
uint32_t g_code_lo = 0x401000, g_code_hi = 0x401000;
int sched_active(void) { return 0; }
uint64_t sched_now_us(void) { return 0; }
int sched_wait(int (*pred)(void *), void *arg, uint64_t t, uint64_t (*f)(void)) {
    (void)pred; (void)arg; (void)t; (void)f; return 0;
}

int main(int argc, char **argv) {
    LazyIndex *idx = lazy_index_new(); assert(idx);
    assert(lazy_index_add(idx, "RESOURCE/INI/Fonts.ini", 123) == 1);
    assert(lazy_index_add(idx, "RESOURCE/INI/\xD0\x81\xD0\xB6.TXT", 42) == 1); /* Ёж */
    assert(lazy_index_add(idx, "PROGRAM/dialog.c", 1) == 1);
    assert(lazy_index_add(idx, "SAVE/slot", 10) == 0);
    assert(lazy_index_add(idx, "save_meta/s", 10) == 0);
    assert(lazy_index_add(idx, "SAVE_TX/s", 10) == 0);
    assert(lazy_index_add(idx, "OpTiOnS", 10) == 0);
    const LazyNode *root = lazy_index_root(idx);
    assert(lazy_index_count(root) == 2 && !lazy_index_child(root, "save", 0));
    const LazyNode *res = lazy_index_child(root, "resource", 0); assert(res && lazy_index_is_dir(res));
    const LazyNode *ini = lazy_index_child(res, "ini", 0); assert(ini && lazy_index_count(ini) == 2);
    const LazyNode *font = lazy_index_child(ini, "fONTS.INI", 0);
    assert(font && !strcmp(lazy_index_name(font), "Fonts.ini") && lazy_index_size(font) == 123);
    const LazyNode *cyr = lazy_index_child(ini, "\xB8\xE6.txt", 1); /* ёж, CP1251 */
    assert(cyr && lazy_index_size(cyr) == 42 && !lazy_index_is_dir(cyr));
    assert(lazy_index_entry(ini, 0) == font && lazy_index_entry(ini, 2) == NULL);
    assert(!lazy_index_child(root, "RESOURCE/INI", 0));
    assert(lazy_index_add(idx, "RESOURCE/INI/fonts.INI", 1) == -1);
    assert(lazy_index_add(idx, "RESOURCE/INI/Fonts.ini", 1) == -1);
    assert(lazy_index_add(idx, "RESOURCE/INI/Fonts.ini/child", 1) == -1);
    assert(lazy_index_add(idx, "../SAVE/test", 1) == -1);
    assert(lazy_index_add(idx, "/RESOURCE/x", 1) == -1);
    assert(lazy_index_add(idx, "RESOURCE//x", 1) == -1);
    assert(lazy_index_add(idx, "RESOURCE/x\\y", 1) == -1);
    lazy_index_free(idx);
    if (argc > 1) {
        FILE *in = fopen(argv[1], "rb"); assert(in);
        idx = lazy_index_new(); assert(idx);
        char line[2048]; size_t added = 0, skipped = 0;
        while (fgets(line, sizeof line, in)) {
            size_t len = strlen(line); assert(len && line[len - 1] == '\n'); line[len - 1] = 0;
            int r = lazy_index_add(idx, line, 1);
            if (r < 0) { fprintf(stderr, "rejected manifest path: %s\n", line); return 1; }
            if (r) added++; else skipped++;
        }
        fclose(in); lazy_index_free(idx);
        printf("manifest namespace: %zu files, %zu mutable paths skipped\n", added, skipped);
    }
    puts("lazy index: PASS");
}
