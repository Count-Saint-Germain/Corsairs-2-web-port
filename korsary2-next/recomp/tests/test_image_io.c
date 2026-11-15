#include "runtime.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Test-only libc fault shims; the runtime uses these only with PORT_TEST_IMAGE_IO. */
static int fault, seeks, closes;
int image_test_fseek(FILE *f, long n, int origin) {
    seeks++;
    if ((fault == 1 && seeks == 1) || (fault == 3 && seeks == 2)) return -1;
    return fseek(f, n, origin);
}
long image_test_ftell(FILE *f) { return fault == 2 ? -1 : ftell(f); }
void *image_test_malloc(size_t n) { return fault == 4 ? NULL : malloc(n); }
size_t image_test_fread(void *p, size_t size, size_t count, FILE *f) {
    return fread(p, size, fault == 5 ? count - 1 : count, f);
}
int image_test_fclose(FILE *f) {
    closes++;
    int result = fclose(f);
    return fault == 6 ? EOF : result;
}
int dyncode_contains(uint32_t x) { (void)x; return 0; }
void interp_call(CPU *c, uint32_t x) { (void)c; (void)x; abort(); }

static void put32(unsigned char *p, unsigned value) {
    for (int i = 0; i < 4; i++) p[i] = (unsigned char)(value >> (i * 8));
}
static void write_image(const char *path, int empty) {
    unsigned char image[512] = {0};
    put32(image + 0x3c, 0x80); /* PE header location */
    put32(image + 0x80 + 24 + 28, 0x1000); /* preferred image base */
    put32(image + 0x80 + 24 + 56, 0x200); /* image size */
    put32(image + 0x80 + 24 + 60, sizeof image); /* header size */
    FILE *f = fopen(path, "wb"); assert(f);
    if (!empty) assert(fwrite(image, 1, sizeof image, f) == sizeof image);
    assert(!fclose(f));
}
static void reject(const char *path, int injected) {
    LoadedImage out; memset(&out, 0xa5, sizeof out); LoadedImage before = out;
    memset(g_mem, 0x5a, 0x10000);
    fault = injected; seeks = closes = 0;
    assert(load_image(path, 0x1000, &out) == -1);
    assert(closes == 1 && !memcmp(&out, &before, sizeof out));
    for (size_t i = 0; i < 0x10000; i++) assert(g_mem[i] == 0x5a);
}
int main(int argc, char **argv) {
    assert(argc == 2);
    g_mem = malloc(0x10000); assert(g_mem);
    write_image(argv[1], 1); reject(argv[1], 0);
    write_image(argv[1], 0);
    for (int i = 1; i <= 6; i++) reject(argv[1], i);
    memset(g_mem, 0, 0x10000); fault = seeks = closes = 0;
    LoadedImage out = {0};
    assert(!load_image(argv[1], 0x1000, &out));
    assert(closes == 1 && out.image_base == 0x1000 && out.entry == 0x1000);
    free(g_mem);
    puts("load_image I/O faults: PASS");
}
