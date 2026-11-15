/* Exercise actual CreateFileA wrapper on files created by this fixture only. */
#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#ifdef TEST_OPFS
#include <emscripten/wasmfs.h>
#endif
#include "../host/core.c"
static int injected_open_error;
static int test_open(const char *path, int flags, mode_t mode) {
    if (injected_open_error) { errno = injected_open_error; injected_open_error = 0; return -1; }
    return open(path, flags, mode);
}
#define open test_open
#include "../host/kernel32.c"
#undef open
uint8_t *g_mem;

static void create_call(CPU *c, const char *name, uint32_t access, uint32_t disposition) {
    strcpy((char *)HP(0x2000), name);
    c->esp = 0x1000;
    W32(0x1000, 0); W32(0x1004, 0x2000); W32(0x1008, access);
    W32(0x100c, 0); W32(0x1010, 0); W32(0x1014, disposition);
    W32(0x1018, 0); W32(0x101c, 0);
    w_CreateFileA(c);
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
    char root[] = "/opfs/korsary-create-safety-XXXXXX";
#else
    char root[] = "/tmp/korsary-create-safety-XXXXXX";
#endif
    assert(mkdtemp(root)); snprintf(g_game_root, sizeof g_game_root, "%s", root);
    char path[256]; snprintf(path, sizeof path, "%s/data", root);
    FILE *f = fopen(path, "wb"); assert(f && fputs("KEEP", f) >= 0 && !fclose(f));
    create_call(&c, "data", 0x80000000u, 5); /* read-only TRUNCATE_EXISTING */
    expect_contents(path, "KEEP");
    assert(c.eax == 0xffffffffu && thread.last_error == ERROR_ACCESS_DENIED);
    create_call(&c, "data", 0, 5); /* metadata-only TRUNCATE_EXISTING */
    assert(c.eax == 0xffffffffu && thread.last_error == ERROR_ACCESS_DENIED);
    expect_contents(path, "KEEP");
    create_call(&c, "data", 0x80000000u, 0);
    assert(c.eax == 0xffffffffu && thread.last_error == 87);
    expect_contents(path, "KEEP");
    create_call(&c, "data", 0x80000000u, 0xffffffffu);
    assert(c.eax == 0xffffffffu && thread.last_error == 87);
    expect_contents(path, "KEEP");
    /* Validation must not dereference the name for these rejected requests. */
    W32(0x1004, 0xffffffffu); W32(0x1008, 0x80000000u); W32(0x1014, 5);
    c.esp = 0x1000; w_CreateFileA(&c);
    assert(c.eax == 0xffffffffu && thread.last_error == ERROR_ACCESS_DENIED);
    W32(0x1004, 0xffffffffu); W32(0x1014, 0);
    c.esp = 0x1000; w_CreateFileA(&c);
    assert(c.eax == 0xffffffffu && thread.last_error == 87);
    expect_contents(path, "KEEP");
    create_call(&c, "data", 0x80000000u, 3); /* ordinary read remains available */
    assert(c.eax != 0xffffffffu); handle_close(c.eax); expect_contents(path, "KEEP");
    create_call(&c, "DaTa", 0x40000000u, 1); /* CREATE_NEW must report a conflict */
#if defined(__EMSCRIPTEN__) && !defined(PORT_NODE_BUILD)
    /* WasmFS cannot safely implement no-replace against another OPFS tab. */
    assert(c.eax == 0xffffffffu && thread.last_error == 50 /* ERROR_NOT_SUPPORTED */);
    expect_contents(path, "KEEP");
    create_call(&c, "created", 0x40000000u, 1);
    assert(c.eax == 0xffffffffu && thread.last_error == 50);
    char made[256]; snprintf(made, sizeof made, "%s/created", root);
    assert(access(made, F_OK) != 0);
    W32(0x1004,0xffffffffu); W32(0x1008,0x40000000u); W32(0x1014,1);
    c.esp=0x1000; w_CreateFileA(&c);
    assert(c.eax == 0xffffffffu && thread.last_error == 50);
#else
    assert(c.eax == 0xffffffffu && thread.last_error == 80 /* ERROR_FILE_EXISTS */);
    expect_contents(path, "KEEP");
    injected_open_error = EEXIST; /* creation lost a race after pathname resolution */
    create_call(&c, "raced", 0x40000000u, 1);
    assert(c.eax == 0xffffffffu && thread.last_error == 80);
    injected_open_error = ENOSPC;
    create_call(&c, "raced", 0x40000000u, 1);
    assert(c.eax == 0xffffffffu && thread.last_error == ERROR_DISK_FULL);
    injected_open_error = EACCES;
    create_call(&c, "raced", 0x40000000u, 1);
    assert(c.eax == 0xffffffffu && thread.last_error == ERROR_ACCESS_DENIED);
    injected_open_error = EINVAL;
    create_call(&c, "raced", 0x40000000u, 1);
    assert(c.eax == 0xffffffffu && thread.last_error == 87);
    char made[256]; snprintf(made, sizeof made, "%s/created", root);
    create_call(&c, "created", 0x40000000u, 1);
    assert(c.eax != 0xffffffffu); handle_close(c.eax); expect_contents(made, "");
    assert(!unlink(made));
#endif
    create_call(&c, "missing", 0x40000000u, 5);
    assert(c.eax == 0xffffffffu && thread.last_error == ERROR_FILE_NOT_FOUND);
    create_call(&c, "data", 0x40000000u, 5); /* explicitly authorized truncation */
    assert(c.eax != 0xffffffffu); handle_close(c.eax); expect_contents(path, "");
    assert(!unlink(path));
#ifndef TEST_OPFS
    assert(!rmdir(root));
#endif
    free(g_mem); puts("CreateFileA: truncation access and disposition PASS");
}
