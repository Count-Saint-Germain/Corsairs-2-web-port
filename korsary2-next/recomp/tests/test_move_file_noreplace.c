/* MoveFileA: atomic no-replace. An existing destination must refuse with ERROR_ALREADY_EXISTS;
   on WasmFS/OPFS (browser build) every move stays fail-closed ERROR_NOT_SUPPORTED. */
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#ifdef TEST_OPFS
#include <emscripten/wasmfs.h>
#endif
#include "../host/core.c"
#include "../host/kernel32.c"
uint8_t *g_mem;

static void move_call(CPU *c, const char *src, const char *dst) {
    strcpy((char *)HP(0x2000), src);
    strcpy((char *)HP(0x3000), dst);
    c->esp = 0x1000;
    W32(0x1000, 0); W32(0x1004, 0x2000); W32(0x1008, 0x3000);
    w_MoveFileA(c);
}
static void expect_contents(const char *path, const char *expected) {
    char b[32] = {0}; FILE *f = fopen(path, "rb"); assert(f);
    size_t n = fread(b, 1, sizeof b, f); assert(!fclose(f));
    assert(n == strlen(expected) && !memcmp(b, expected, n));
}
static void make(const char *path, const char *text) {
    FILE *f = fopen(path, "wb"); assert(f && fputs(text, f) >= 0 && !fclose(f));
}
int main(void) {
    g_mem = calloc(1, 65536); assert(g_mem);
    GuestThread thread = {0}; t_self = &thread; CPU c = {0};
#ifdef TEST_OPFS
    assert(!wasmfs_create_directory("/opfs", 0777, wasmfs_create_opfs_backend()));
    char root[] = "/opfs/korsary-move-noreplace-XXXXXX";
#else
    char root[] = "/tmp/korsary-move-noreplace-XXXXXX";
#endif
    assert(mkdtemp(root)); snprintf(g_game_root, sizeof g_game_root, "%s", root);
    char src[256], dst[256]; snprintf(src, sizeof src, "%s/SRC", root); snprintf(dst, sizeof dst, "%s/DST", root);
    make(src, "SOURCE"); make(dst, "DEST");

#if defined(__EMSCRIPTEN__) && !defined(PORT_NODE_BUILD)
    /* Browser build: fail closed before touching either file (OPFS cannot promise no-replace). */
    move_call(&c, "SRC", "DST");
    assert(c.eax == 0 && thread.last_error == ERROR_NOT_SUPPORTED);
    expect_contents(src, "SOURCE"); expect_contents(dst, "DEST");
    move_call(&c, "SRC", "absent");
    assert(c.eax == 0 && thread.last_error == ERROR_NOT_SUPPORTED);
    expect_contents(src, "SOURCE");
    char absent[256]; snprintf(absent, sizeof absent, "%s/absent", root);
    assert(access(absent, F_OK) != 0);
    puts("MoveFileA: fail-closed, files unchanged PASS");
#else
    /* Existing destination: MoveFileA must refuse (only MoveFileEx + MOVEFILE_REPLACE_EXISTING
       replaces) and leave both files untouched. */
    move_call(&c, "SRC", "DST");
    assert(c.eax == 0 && thread.last_error == ERROR_ALREADY_EXISTS);
    expect_contents(src, "SOURCE"); expect_contents(dst, "DEST");
    /* Absent destination: the move happens, the source disappears. */
    move_call(&c, "SRC", "absent");
    assert(c.eax == 1 && thread.last_error == 0);
    char absent[256]; snprintf(absent, sizeof absent, "%s/absent", root);
    expect_contents(absent, "SOURCE");
    assert(access(src, F_OK) != 0);
    /* Move it back under a fresh name, then rename onto itself is a no-op success. */
    move_call(&c, "absent", "SRC");
    assert(c.eax == 1);
    expect_contents(src, "SOURCE");
    move_call(&c, "SRC", "SRC");
    assert(c.eax == 1);
    expect_contents(src, "SOURCE");
    /* Case-insensitive path mapping resolves SRC to the same host file: still a no-op success. */
    move_call(&c, "SRC", "src");
    assert(c.eax == 1);
    expect_contents(src, "SOURCE");
    /* Missing source refuses with FILE_NOT_FOUND. */
    move_call(&c, "missing", "DST");
    assert(c.eax == 0 && thread.last_error == ERROR_FILE_NOT_FOUND);
    /* Directories: move works, moving onto an existing directory refuses. */
    char sub[256], inside[300]; snprintf(sub, sizeof sub, "%s/sub", root);
    snprintf(inside, sizeof inside, "%s/f", sub);
    assert(!mkdir(sub, 0755)); make(inside, "D");
    move_call(&c, "sub", "DST");   /* directory onto an existing file */
    assert(c.eax == 0 && thread.last_error == ERROR_ALREADY_EXISTS);
    expect_contents(dst, "DEST");
    move_call(&c, "sub", "sub2");
    assert(c.eax == 1);
    char sub2[256], inside2[300]; snprintf(sub2, sizeof sub2, "%s/sub2", root);
    snprintf(inside2, sizeof inside2, "%s/f", sub2);
    assert(access(sub, F_OK) != 0 && access(sub2, F_OK) == 0);
    expect_contents(inside2, "D");
    /* Both fixtures removed only when nothing was lost. */
    assert(!unlink(dst)); assert(!unlink(src));
    assert(!unlink(inside2)); assert(!rmdir(sub2));
    assert(!rmdir(root));
    puts("MoveFileA: no-replace semantics PASS");
#endif
    free(g_mem);
}
