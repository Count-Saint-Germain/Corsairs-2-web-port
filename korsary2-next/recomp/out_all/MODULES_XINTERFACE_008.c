#include "recomp.h"

void f_00b02af0(CPU *c) { /* Unwind@10052af0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_00ab1442(c); return; } /* jmp 0xab1442 */
}

void f_00b02af8(CPU *c) { /* PTR_00b02af8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0b43cu); /* mov eax, 0x1005b43c */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b02be9(CPU *c) { /* PTR_00b02be9 */
    PREEMPT_POLL(c);
    guest_trap(c, 0x00b02be9u, "int3"); /* int3  */
}
