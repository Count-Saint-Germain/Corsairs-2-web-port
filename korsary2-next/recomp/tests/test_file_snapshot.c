/* Read-only open-time snapshots: real guest wrappers, only owned temporary files.
   Covers read/seek/size semantics of buffered handles, the write-handle conflict
   refusal, the save read-activity counter and the PORT_FILE_SNAPSHOT=0 off switch
   (the runner runs this binary twice: default on, then with the variable set). */
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
#define FILE_SHARE_READ 1

static void create_call(CPU *c, const char *name, uint32_t access, uint32_t share, uint32_t disposition) {
    strcpy((char *)HP(0x2000), name);
    c->esp = 0x1000;
    W32(0x1000, 0); W32(0x1004, 0x2000); W32(0x1008, access); W32(0x100c, share);
    W32(0x1010, 0); W32(0x1014, disposition); W32(0x1018, 0); W32(0x101c, 0);
    w_CreateFileA(c);
}
static void read_call(CPU *c, uint32_t h, uint32_t buf, uint32_t want) {
    c->esp = 0x1000;
    W32(0x1000, 0); W32(0x1004, h); W32(0x1008, buf); W32(0x100c, want); W32(0x1010, 0x9000);
    w_ReadFile(c);
}
static void seek_call(CPU *c, uint32_t h, uint32_t low, uint32_t high, uint32_t method) {
    c->esp = 0x1000; W32(0x1000, 0); W32(0x1004, h); W32(0x1008, low); W32(0x100c, high); W32(0x1010, method);
    w_SetFilePointer(c);
}
static void close_call(CPU *c, uint32_t handle) {
    c->esp = 0x1000;
    W32(0x1000, 0); W32(0x1004, handle);
    w_CloseHandle(c);
}
static void size_call(CPU *c, uint32_t h) {
    c->esp = 0x1000; W32(0x1000, 0); W32(0x1004, h); W32(0x1008, 0x9004);
    w_GetFileSize(c);
}
static void write_call(CPU *c, uint32_t h, const char *bytes, uint32_t want) {
    strcpy((char *)HP(0x4000), bytes);
    c->esp = 0x1000; W32(0x1000, 0); W32(0x1004, h); W32(0x1008, 0x4000);
    W32(0x100c, want); W32(0x1010, 0x9008);
    w_WriteFile(c);
}
static WinHandle *hptr(uint32_t h) { WinHandle *x = handle_get(h, H_FILE); assert(x); return x; }
static void expect_prefix(const char *path, const char *expected) {
    char b[64] = {0}; FILE *fp = fopen(path, "rb"); assert(fp);
    size_t n = fread(b, 1, sizeof b, fp); assert(!fclose(fp));
    assert(n >= strlen(expected) && !memcmp(b, expected, strlen(expected)));
}

int main(void) {
    int enabled = !getenv("PORT_FILE_SNAPSHOT_OFF");
    if (!enabled) assert(setenv("PORT_FILE_SNAPSHOT", "0", 1) == 0);
    g_mem = calloc(1, 65536); assert(g_mem);
    GuestThread thread = {0}; t_self = &thread; CPU c = {0};
#ifdef TEST_OPFS
    assert(!wasmfs_create_directory("/opfs", 0777, wasmfs_create_opfs_backend()));
    char root[] = "/opfs/korsary-snapshot-XXXXXX";
#else
    char root[] = "/tmp/korsary-snapshot-XXXXXX";
#endif
    assert(mkdtemp(root)); snprintf(g_game_root, sizeof g_game_root, "%s", root);
    const char *content = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    size_t len = strlen(content);
    char path[256]; snprintf(path, sizeof path, "%s/data", root);
    FILE *f = fopen(path, "wb"); assert(f && fwrite(content, 1, len, f) == len && !fclose(f));

    /* read-only OPEN_EXISTING: snapshot engaged, sequential + seeked reads, EOF */
    create_call(&c, "data", GENERIC_READ, FILE_SHARE_READ, 3);
    uint32_t hr = c.eax; assert(hr != 0xffffffffu);
    WinHandle *x = hptr(hr);
    assert((x->buf != NULL) == enabled);
    assert(!x->write_open);
    read_call(&c, hr, 0x3000, 10);
    assert(c.eax == 1 && R32(0x9000) == 10 && !memcmp(HP(0x3000), content, 10) && thread.last_error == 0);
    read_call(&c, hr, 0x3000, 1000);   /* EOF: short read, still success */
    uint32_t rest = (uint32_t)len - 10;
    assert(c.eax == 1 && R32(0x9000) == rest && !memcmp(HP(0x3000), content + 10, rest));
    read_call(&c, hr, 0x3000, 16);
    assert(c.eax == 1 && R32(0x9000) == 0);   /* past EOF: zero bytes, success */
    seek_call(&c, hr, 20, 0, 0);
    assert(c.eax == 20);
    read_call(&c, hr, 0x3000, 4);
    assert(R32(0x9000) == 4 && !memcmp(HP(0x3000), content + 20, 4));
    seek_call(&c, hr, (uint32_t)-5, 0, 2 /* FILE_END */);
    assert(c.eax == len - 5);
    read_call(&c, hr, 0x3000, 100);
    assert(R32(0x9000) == 5 && !memcmp(HP(0x3000), content + len - 5, 5));
    seek_call(&c, hr, (uint32_t)-2, 0, 1 /* FILE_CURRENT */);
    assert(c.eax == len - 2);
    seek_call(&c, hr, (uint32_t)-1000, 0, 0);
    assert(c.eax == 0xffffffffu && thread.last_error == 131 /* ERROR_NEGATIVE_SEEK */);
    seek_call(&c, hr, 100000, 0, 0);   /* beyond EOF positions are legal */
    assert(c.eax == 100000);
    read_call(&c, hr, 0x3000, 8);
    assert(c.eax == 1 && R32(0x9000) == 0);
    size_call(&c, hr);
    assert(c.eax == len && R32(0x9004) == 0);
    close_call(&c, hr);

    /* save reads bump the activity counter from the snapshot path too */
    snprintf(path, sizeof path, "%s/SAVE", root);
    mkdir(path, 0775);
    snprintf(path, sizeof path, "%s/SAVE/slot", root);
    f = fopen(path, "wb"); assert(f && fwrite("SAVEBYTES", 1, 9, f) == 9 && !fclose(f));
    uint32_t before = port_save_read_count();
    create_call(&c, "SAVE\\slot", GENERIC_READ, FILE_SHARE_READ, 3);
    hr = c.eax; assert(hr != 0xffffffffu && hptr(hr)->save_read_activity == 1);
    read_call(&c, hr, 0x3000, 4);
    assert(c.eax == 1 && R32(0x9000) == 4 && port_save_read_count() == before + 1);
    close_call(&c, hr);

    if (enabled) {
        /* an open write handle must refuse the snapshot for the same path (fd fallback) */
        create_call(&c, "data", GENERIC_WRITE, FILE_SHARE_READ, 3);
        uint32_t hw = c.eax; assert(hw != 0xffffffffu);
        create_call(&c, "data", GENERIC_READ, FILE_SHARE_READ, 3);
        hr = c.eax; assert(hr != 0xffffffffu);
        assert(hptr(hr)->buf == NULL);   /* conflict: plain fd path serves current bytes */
        read_call(&c, hr, 0x3000, 4);
        assert(c.eax == 1 && !memcmp(HP(0x3000), content, 4));
        close_call(&c, hr);
        /* the writer overwrites its first four bytes while open; the next read-only
           open must still not snapshot, and must see the new bytes through the fd */
        write_call(&c, hw, "NEW!", 4);
        assert(c.eax == 1);
        create_call(&c, "data", GENERIC_READ, FILE_SHARE_READ, 3);
        hr = c.eax; assert(hr != 0xffffffffu && hptr(hr)->buf == NULL);
        read_call(&c, hr, 0x3000, 10);
        assert(R32(0x9000) == 10 && !memcmp(HP(0x3000), "NEW!456789", 10));
        close_call(&c, hr);
        close_call(&c, hw);
        snprintf(path, sizeof path, "%s/data", root);   /* path was reused for SAVE/slot above */
        expect_prefix(path, "NEW!");
    }

    free(g_mem);
    puts(enabled ? "FileSnapshot: semantics, conflict refusal, activity PASS"
                 : "FileSnapshot: disabled switch keeps the fd path PASS");
}
