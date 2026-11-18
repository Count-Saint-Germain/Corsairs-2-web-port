/* Exercise the real USER32 handlers and the XINTERFACE control-state hook
   with the guest stack layouts recorded in the translated sources. */
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include "../host/user32.c"

static uint8_t memory[8192];
uint8_t *g_mem = memory;
static CPU cpu;
static int netplay;
static double now = 100.0;

int netplay_on(void) { return netplay; }
double host_seconds(void) { return now; }

enum { STACK = 0x1000, POINT = 0x1200, INTERFACE = 0x1400 };

static void get_cursor(uint32_t site, int x, int y) {
    cpu.esp = STACK;
    W32(STACK, site);
    W32(STACK + 4, POINT);
    w_GetCursorPos(&cpu);
    assert(cpu.eax == 1 && cpu.esp == STACK + 8);
    assert((int32_t)R32(POINT) == x && (int32_t)R32(POINT + 4) == y);
}

static void set_cursor(uint32_t site, int x, int y) {
    cpu.esp = STACK;
    W32(STACK, site);
    W32(STACK + 4, (uint32_t)x);
    W32(STACK + 8, (uint32_t)y);
    w_SetCursorPos(&cpu);
    assert(cpu.eax == 1 && cpu.esp == STACK + 12);
}

int main(void) {
    set_cursor(0, 512, 384);
    user32_mouse_move(25, -12);
    get_cursor(0, 537, 372);
    get_cursor(PCS_CURSOR_READ, 537, 372);
    user32_mouse_move(-7, 8); /* Arrives between the two PCS calls. */
    set_cursor(PCS_CURSOR_RECENTER, 512, 384);
    get_cursor(PCS_CURSOR_READ, 505, 392);
    set_cursor(PCS_CURSOR_RECENTER, 512, 384);
    get_cursor(0, 512, 384);

    user32_mouse_move(50, 50);
    set_cursor(0, 10, 20); /* Other guest callers still move the cursor. */
    get_cursor(0, 10, 20);
    get_cursor(0, 10, 20);
    set_cursor(PCS_CURSOR_RECENTER, 20, 30); /* Guard exact recenter target. */
    get_cursor(0, 20, 30);

    cpu.esi = INTERFACE;
    cpu.esp = STACK;
    W32(INTERFACE + 0x74, 720);
    W32(INTERFACE + 0x78, 540);
    WF32(INTERFACE + 0xb4, 360);
    WF32(INTERFACE + 0xb8, 270);
    W32(INTERFACE + 0xbc, (uint32_t)-16);
    W32(INTERFACE + 0xc0, (uint32_t)-16);

    assert(!port_menu_mouse_active());
    input_mouse_position(0.25f, 0.75f);
    port_menu_mouse_control(&cpu, STACK + 0x20);
    assert(port_menu_mouse_active());
    now += 0.7;
    assert(!port_menu_mouse_active());
    port_menu_mouse_control(&cpu, STACK + 0x20);
    assert(port_menu_mouse_active());
    assert(RF32(STACK + 0x24) == -164.25f && RF32(STACK + 0x18) == -150.25f);
    assert(R32(STACK + 0x28) == 1 && R32(STACK + 0x1c) == 1);

    /* At the absolute position, suppress the corresponding relative input. */
    WF32(INTERFACE + 0xb4, 195.75f);
    WF32(INTERFACE + 0xb8, 420.25f);
    port_menu_mouse_control(&cpu, STACK + 0x20);
    assert(R32(STACK + 0x28) == 0 && R32(STACK + 0x1c) == 0);

    input_mouse_position(1, 1);
    port_menu_mouse_control(&cpu, STACK + 0x20);
    assert(RF32(STACK + 0x24) == 719.0f - 195.75f);
    assert(RF32(STACK + 0x18) == 420.25f - 539.0f);

    /* Stale layout, netplay and invalid browser coordinates leave relative input alone. */
    WF32(STACK + 0x24, 77);
    port_menu_mouse_control(&cpu, STACK + 0x1c);
    assert(RF32(STACK + 0x24) == 77);
    input_mouse_position(-1, NAN);
    netplay = 1;
    input_mouse_position(0.5f, 0.5f);
    port_menu_mouse_control(&cpu, STACK + 0x20);
    assert(RF32(STACK + 0x24) == 77);

    puts("Cursor input: wrapped PCS re-centering and XINTERFACE position PASS");
    return 0;
}
