/* Exercise the guest Win32 heap wrappers as well as the allocator. */
#include "../host/core.c"
#include "../host/kernel32.c"
#include <assert.h>
#include <setjmp.h>

uint8_t *g_mem;
static jmp_buf trapped;
void guest_trap(CPU *c, uint32_t a, const char *why) {
    (void)c; (void)a; (void)why;
    longjmp(trapped, 1);
}

static void args(CPU *c, uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3) {
    c->esp = 0x1000;
    W32(c->esp, 0x1234);
    W32(c->esp + 4, a0); W32(c->esp + 8, a1);
    W32(c->esp + 12, a2); W32(c->esp + 16, a3);
}

int main(void) {
    CPU c = {0};
    GuestThread thread = {0};
    t_self = &thread;
    g_mem = calloc(1, (size_t)HEAP_LO + (2u << 20));
    assert(g_mem);
    thread.last_error = 0x12345678;
    args(&c, HEAP_HANDLE, 0, UINT32_MAX, 0);
    w_HeapAlloc(&c);
    assert(c.eax == 0 && thread.last_error == 0x12345678);

    uint32_t p = heap_alloc(31, 0), guard = heap_alloc(32, 0);
    assert(p && guard);
    W8(p, 0x87);
    args(&c, HEAP_HANDLE, 0x10, p, 4096);
    w_HeapReAlloc(&c);
    assert(c.eax == 0 && heap_size(p) == 31 && R8(p) == 0x87);
    assert(thread.last_error == 0x12345678);
    args(&c, HEAP_HANDLE, 0, p, 0);
    w_HeapSize(&c);
    assert(c.eax == 31);
    args(&c, HEAP_HANDLE, 0, 0, 0);
    w_HeapSize(&c);
    assert(c.eax == UINT32_MAX);

    args(&c, HEAP_HANDLE, 4, UINT32_MAX, 0);
    if (!setjmp(trapped)) { w_HeapAlloc(&c); assert(!"expected explicit exception trap"); }
    heap_free(guard); heap_free(p);
    free(g_mem);
    return 0;
}
