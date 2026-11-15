/* Exercise the actual recorder conversion with exact-sized source vertices. */
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "../host/render_rec.c"

static unsigned size_code(unsigned dim) {
    static const unsigned code[] = {0, 3, 0, 1, 2};
    return code[dim];
}

static void check(const unsigned *dims, unsigned n, int rich) {
    uint32_t fvf = 0x002u | (n << 8) | (rich ? 0x10u | 0x40u | 0x80u : 0u);
    for (unsigned i = 0; i < n; ++i) fvf |= size_code(dims[i]) << (16 + 2*i);
    FvfLayout layout;
    fvf_layout(fvf, &layout);
    uint8_t *input = calloc(layout.stride, 1);
    assert(input);
    unsigned offset = rich ? 32 : 12;
    if (rich) {
        uint32_t diffuse = 0x12345678, specular = 0x87654321;
        memcpy(input + 24, &diffuse, 4);
        memcpy(input + 28, &specular, 4);
    }
    for (unsigned i = 0; i < n; ++i) {
        for (unsigned j = 0; j < dims[i]; ++j) {
            float value = 10.0f * (float)(i + 1) + (float)j;
            memcpy(input + offset, &value, sizeof value);
            offset += sizeof value;
        }
    }
    assert(offset == layout.stride);
    CVert out;
    convert_vertex(input, &layout, &out);
    if (rich) { assert(out.diffuse == 0x12345678); assert(out.specular == 0x87654321); }
    for (unsigned i = 0; i < 4; ++i) {
        for (unsigned j = 0; j < 4; ++j) {
            float want = (i < n && j < dims[i]) ? 10.0f * (float)(i + 1) + (float)j : (j == 3 ? 1.0f : 0.0f);
            assert(out.tc[i][j] == want);
        }
    }
    free(input);
}

int main(void) {
    const unsigned one[] = {1};
    const unsigned two[] = {2};
    const unsigned three[] = {3};
    const unsigned four[] = {4};
    const unsigned mixed[] = {1, 4, 3, 2};
    const unsigned eight[] = {4, 1, 2, 3, 1, 2, 3, 4};
    check(one, 1, 0); check(two, 1, 0); check(three, 1, 0); check(four, 1, 0);
    check(mixed, 4, 0); check(eight, 8, 0); check(NULL, 0, 0);
    check(mixed, 4, 1); check(one, 1, 1);
    puts("FVF coordinate dimensions and offsets OK");
}
