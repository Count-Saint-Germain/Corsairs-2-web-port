/* CREATE_ALWAYS: truncate an existing file to zero and succeed; no "already exists" failure. */
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#ifdef TEST_OPFS
#include <emscripten/wasmfs.h>
#endif
#include "../host/core.c"
#include "../host/kernel32.c"
uint8_t *g_mem;

static void create_call(CPU *c, const char *name, uint32_t access, uint32_t disposition) {
    strcpy((char *)HP(0x2000), name);
    c->esp = 0x1000;
    W32(0x1000, 0); W32(0x1004, 0x2000); W32(0x1008, access);
    W32(0x100c, 0); W32(0x1010, 0); W32(0x1014, disposition);
    W32(0x1018, 0); W32(0x101c, 0);
    w_CreateFileA(c);
}
static void write_call(CPU *c, uint32_t handle, const char *text) {
    strcpy((char *)HP(0x2000), text);
    c->esp = 0x1000;
    W32(0x1000, 0); W32(0x1004, handle); W32(0x1008, 0x2000); W32(0x100c, strlen(text));
    W32(0x1010, 0); W32(0x1014, 0);
    w_WriteFile(c);
}
static long file_size(const char *path) {
    FILE *f = fopen(path, "rb"); assert(f);
    assert(!fseek(f, 0, SEEK_END));
    long n = ftell(f); assert(!fclose(f));
    return n;
}
static void expect_contents(const char *path, const char *expected) {
    char b[32] = {0}; FILE *f = fopen(path, "rb"); assert(f);
    size_t n = fread(b, 1, sizeof b, f); assert(!fclose(f));
    assert(n == strlen(expected) && !memcmp(b, expected, n));
}
int main(void) {
    g_mem = calloc(1, 65536); assert(g_mem);
    GuestThread thread = {0}; t_self = &thread; CPU c = {0};
#ifdef TEST_OPFS
    assert(!wasmfs_create_directory("/opfs", 0777, wasmfs_create_opfs_backend()));
    char root[] = "/opfs/korsary-create-always-XXXXXX";
#else
    char root[] = "/tmp/korsary-create-always-XXXXXX";
#endif
    assert(mkdtemp(root)); snprintf(g_game_root, sizeof g_game_root, "%s", root);
    char path[256]; snprintf(path, sizeof path, "%s/data", root);
    FILE *f = fopen(path, "wb"); assert(f && fputs("KEEP", f) >= 0 && !fclose(f));

    /* CREATE_ALWAYS over an existing file: must succeed (not fail with FILE_EXISTS),
       truncate it to zero, and report ERROR_ALREADY_EXISTS as the informational last error. */
    create_call(&c, "data", 0x40000000u, 2); /* GENERIC_WRITE */
    assert(c.eax != 0xffffffffu);
    assert(thread.last_error == ERROR_ALREADY_EXISTS);
    assert(file_size(path) == 0);
    write_call(&c, c.eax, "NEW"); /* the returned handle stays writable */
    assert(c.eax != 0);
    handle_close(c.eax);
    expect_contents(path, "NEW");

    /* CREATE_ALWAYS over a missing file: succeeds with a clear last error. */
    char made[256]; snprintf(made, sizeof made, "%s/fresh", root);
    create_call(&c, "fresh", 0x40000000u, 2);
    assert(c.eax != 0xffffffffu && thread.last_error == 0);
    handle_close(c.eax);
    assert(file_size(made) == 0);
    expect_contents(made, "");

    /* CREATE_ALWAYS + GENERIC_READ keeps working in this port (untested against real Windows);
       the file must still be truncated, never left as-is. */
    create_call(&c, "data", 0x80000000u, 2);
    assert(c.eax != 0xffffffffu);
    handle_close(c.eax);
    assert(file_size(path) == 0);

    /* CREATE_ALWAYS must not fail when the file exists with zero length already. */
    create_call(&c, "data", 0x40000000u, 2);
    assert(c.eax != 0xffffffffu && thread.last_error == ERROR_ALREADY_EXISTS);
    handle_close(c.eax);
    assert(file_size(path) == 0);

    assert(!unlink(path)); assert(!unlink(made));
#ifndef TEST_OPFS
    assert(!rmdir(root));
#endif
    free(g_mem); puts("CreateFileA: CREATE_ALWAYS truncation PASS");
}
