/* Access/share compatibility: PORT_STRICT_FILE_SHARE=1 enforces the two-sided Windows rule
   (ERROR_SHARING_VIOLATION = 32); the default permissive policy keeps every open succeeding. */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#ifdef TEST_OPFS
#include <emscripten/wasmfs.h>
#endif
#include "../host/core.c"
#include "../host/kernel32.c"
uint8_t *g_mem;

#define GENERIC_READ 0x80000000u
#define GENERIC_WRITE 0x40000000u
#define DELETE 0x00010000u
#define FILE_SHARE_READ 1
#define FILE_SHARE_WRITE 2
#define FILE_SHARE_DELETE 4

static void create_call(CPU *c, const char *name, uint32_t access, uint32_t share, uint32_t disposition) {
    strcpy((char *)HP(0x2000), name);
    c->esp = 0x1000;
    W32(0x1000, 0); W32(0x1004, 0x2000); W32(0x1008, access); W32(0x100c, share);
    W32(0x1010, 0); W32(0x1014, disposition); W32(0x1018, 0); W32(0x101c, 0);
    w_CreateFileA(c);
}
static void close_call(CPU *c, uint32_t handle) {
    c->esp = 0x1000;
    W32(0x1000, 0); W32(0x1004, handle);
    w_CloseHandle(c);
}
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
static void open_expect(CPU *c, GuestThread *t, const char *name, uint32_t access, uint32_t share,
                        uint32_t ok, uint32_t error) {
    create_call(c, name, access, share, 3 /* OPEN_EXISTING */);
    if (ok) assert(c->eax != 0xffffffffu);
    else assert(c->eax == 0xffffffffu);
    assert(t->last_error == error);
}
int main(void) {
    int strict = getenv("PORT_STRICT_FILE_SHARE") != NULL;
    g_mem = calloc(1, 65536); assert(g_mem);
    GuestThread thread = {0}; t_self = &thread; CPU c = {0};
#ifdef TEST_OPFS
    assert(!wasmfs_create_directory("/opfs", 0777, wasmfs_create_opfs_backend()));
    char root[] = "/opfs/korsary-file-share-XXXXXX";
#else
    char root[] = "/tmp/korsary-file-share-XXXXXX";
#endif
    assert(mkdtemp(root)); snprintf(g_game_root, sizeof g_game_root, "%s", root);
    char path[256]; snprintf(path, sizeof path, "%s/data", root);
    FILE *f = fopen(path, "wb"); assert(f && fputs("KEEP", f) >= 0 && !fclose(f));

    if (strict) {
        /* An exclusive handle must refuse every later open of the same file. */
        create_call(&c, "data", GENERIC_READ, 0, 3);
        uint32_t h1 = c.eax; assert(h1 != 0xffffffffu);
        open_expect(&c, &thread, "data", GENERIC_READ, FILE_SHARE_READ, 0, ERROR_SHARING_VIOLATION);
        open_expect(&c, &thread, "data", GENERIC_WRITE, 0, 0, ERROR_SHARING_VIOLATION);
        expect_contents(path, "KEEP");   /* refusals must precede any truncation */
        create_call(&c, "data", GENERIC_WRITE, FILE_SHARE_READ, 2 /* CREATE_ALWAYS */);
        assert(c.eax == 0xffffffffu && thread.last_error == ERROR_SHARING_VIOLATION);
        expect_contents(path, "KEEP");
        close_call(&c, h1);
        expect_contents(path, "KEEP");

        /* A writer sharing only READ admits a reader only if the reader itself shares WRITE
           (the existing handle's desired WRITE must fit the new share). */
        create_call(&c, "data", GENERIC_WRITE, FILE_SHARE_READ, 3);
        uint32_t h2 = c.eax; assert(h2 != 0xffffffffu);
        open_expect(&c, &thread, "data", GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, 1, 0);
        uint32_t hr = c.eax;
        open_expect(&c, &thread, "data", GENERIC_READ, FILE_SHARE_READ, 0, ERROR_SHARING_VIOLATION);
        open_expect(&c, &thread, "data", GENERIC_WRITE, FILE_SHARE_READ, 0, ERROR_SHARING_VIOLATION);
        close_call(&c, hr);
        close_call(&c, h2);
        /* After both handles close the conflict disappears. */
        open_expect(&c, &thread, "data", GENERIC_WRITE, 0, 1, 0);
        close_call(&c, c.eax);
        expect_contents(path, "KEEP");
#if !defined(__EMSCRIPTEN__) || defined(PORT_NODE_BUILD)
        /* MoveFileA needs every open handle on the source to share DELETE. */
        create_call(&c, "data", GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, 3);
        uint32_t h3 = c.eax; assert(h3 != 0xffffffffu);
        move_call(&c, "data", "moved");
        assert(c.eax == 0 && thread.last_error == ERROR_SHARING_VIOLATION);
        expect_contents(path, "KEEP");
        close_call(&c, h3);
        move_call(&c, "data", "moved");
        assert(c.eax == 1);
        char moved[256]; snprintf(moved, sizeof moved, "%s/moved", root);
        expect_contents(moved, "KEEP");
        move_call(&c, "moved", "data");   /* move it back */
        assert(c.eax == 1);
        expect_contents(path, "KEEP");
#endif
        puts("CreateFileA share matrix (strict): PASS");
    } else {
        /* Default policy: share flags are ignored, every open still succeeds. */
        create_call(&c, "data", GENERIC_READ, 0, 3);
        uint32_t h1 = c.eax; assert(h1 != 0xffffffffu);
        open_expect(&c, &thread, "data", GENERIC_WRITE, 0, 1, 0);
        close_call(&c, c.eax);
        close_call(&c, h1);
        expect_contents(path, "KEEP");
        puts("CreateFileA share matrix (permissive default): PASS");
    }

    assert(!unlink(path));
#ifndef TEST_OPFS
    assert(!rmdir(root));
#endif
    free(g_mem);
}
