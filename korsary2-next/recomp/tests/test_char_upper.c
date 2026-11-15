/* Exercise the actual USER32 import for character and guest-string arguments. */
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../host/user32.c"

uint8_t *g_mem;

static uint32_t invoke(uint32_t arg) {
    CPU c = {0};
    c.esp = 0x200;
    W32(c.esp, 0x12345678);
    W32(c.esp + 4, arg);
    w_CharUpperA(&c);
    assert(c.esp == 0x208);
    return c.eax;
}

int main(void) {
    g_mem = calloc(1, 0x20000);
    assert(g_mem);
    for (unsigned ch = 0; ch <= 0xff; ch++) {
        unsigned expected = ch;
        if (ch >= 'a' && ch <= 'z') expected = ch - 32;
        if (ch >= 0xe0) expected = ch - 32;
        if (ch == 0xb8) expected = 0xa8;
        assert(invoke(ch) == expected);
    }
    assert(invoke(0x1234) == 0x1234); /* no invalid C ctype input */
    /* Малькольм Хатчер → МАЛЬКОЛЬМ ХАТЧЕР, in Windows-1251. */
    static const uint8_t input[] = {
        0xcc,0xe0,0xeb,0xfc,0xea,0xee,0xeb,0xfc,0xec,' ',
        0xd5,0xe0,0xf2,0xf7,0xe5,0xf0,0
    };
    static const uint8_t expected[] = {
        0xcc,0xc0,0xcb,0xdc,0xca,0xce,0xcb,0xdc,0xcc,' ',
        0xd5,0xc0,0xd2,0xd7,0xc5,0xd0,0
    };
    const uint32_t at = 0x11000;
    memcpy(HP(at), input, sizeof input);
    W8(at + sizeof input, 0x7f);
    assert(invoke(at) == at);
    assert(memcmp(HP(at), expected, sizeof expected) == 0);
    assert(R8(at + sizeof input) == 0x7f);
    free(g_mem);
    puts("CharUpperA: ASCII, Russian CP1251, byte and string arguments PASS");
    return 0;
}
