/* Tail-jumped COM slots must dispatch to the new target without a stack push. */
#include "runtime.h"
#include <assert.h>
#include <stdlib.h>

/* No dynamically generated code is involved in this isolated runtime test. */
int dyncode_contains(uint32_t addr) { (void)addr; return 0; }
void interp_call(CPU *c, uint32_t addr) { (void)c; (void)addr; abort(); }

static uint32_t seen_slot, seen_return;
static void host_slot(CPU *c) {
    seen_slot = g_import_target;
    seen_return = R32(c->esp);
    c->esp += 4; /* host method consumes the original return address */
}

int main(void) {
    CPU c = {0};
    g_mem = calloc(1, 4096);
    assert(g_mem);
    uint32_t old_slot = add_dynamic_import("old method", host_slot);
    uint32_t new_slot = add_dynamic_import("new method", host_slot);

    c.esp = 0x100;
    W32(c.esp, 0x12345678);
    call_indirect(&c, old_slot);
    assert(seen_slot == old_slot && seen_return == 0x12345678 && c.esp == 0x104);

    c.esp = 0x200;
    W32(c.esp, 0x87654321);
    jump_indirect(&c, new_slot, 0x400000);
    assert(seen_slot == new_slot && seen_return == 0x87654321 && c.esp == 0x204);
    free(g_mem);
    return 0;
}
