#include "recomp.h"

void f_00a40058(CPU *c) { /* PTR_00a40058 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xa42118u); /* mov eax, 0x10022118 */
    { f_00a35da9(c); return; } /* jmp 0xa35da9 */
}

void f_00a40070(CPU *c) { /* Unwind@10020070 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_00a232d0(c); return; } /* jmp 0xa232d0 */
}

void f_00a40078(CPU *c) { /* Unwind@10020078 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x20u)); /* add ecx, 0x20 */
    { f_00a23570(c); return; } /* jmp 0xa23570 */
}

void f_00a40083(CPU *c) { /* PTR_00a40083 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xa42144u); /* mov eax, 0x10022144 */
    { f_00a35da9(c); return; } /* jmp 0xa35da9 */
}

void f_00a40090(CPU *c) { /* Unwind@10020090 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_00a232d0(c); return; } /* jmp 0xa232d0 */
}

void f_00a40098(CPU *c) { /* PTR_00a40098 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xa42168u); /* mov eax, 0x10022168 */
    { f_00a35da9(c); return; } /* jmp 0xa35da9 */
}

void f_00a400b0(CPU *c) { /* Unwind@100200b0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00a232f0(c); return; } /* jmp 0xa232f0 */
}

void f_00a400bb(CPU *c) { /* Unwind@100200bb */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00a232f0(c); return; } /* jmp 0xa232f0 */
}

void f_00a400c6(CPU *c) { /* PTR_00a400c6 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xa42194u); /* mov eax, 0x10022194 */
    { f_00a35da9(c); return; } /* jmp 0xa35da9 */
}
