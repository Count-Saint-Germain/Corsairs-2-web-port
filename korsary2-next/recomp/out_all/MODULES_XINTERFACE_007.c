#include "recomp.h"

void f_00afcf1a(CPU *c) { /* FUN_1004cf1a */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00afcf41; /* je 0xafcf41 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00afcf29u); f_00af16c0(c); /* call 0xaf16c0 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00afcf30u); f_00af2637(c); /* call 0xaf2637 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00afcf41; /* je 0xafcf41 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00afcf3du); f_00af3f30(c); /* call 0xaf3f30 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_00afcf41:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00afcf50(CPU *c) { /* DDRAW.DLL::DirectDrawCreate */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(0xb172c8u)); switch (t_) {  default: jump_indirect(c, t_, 0x00afcf50u); return; } } /* jmp dword ptr [0x100672c8] */
}

void f_00afcf56(CPU *c) { /* KERNEL32.DLL::RtlUnwind */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(0xb1733cu)); switch (t_) {  default: jump_indirect(c, t_, 0x00afcf56u); return; } } /* jmp dword ptr [0x1006733c] */
}

void f_00afcf5c(CPU *c) { /* PTR_00afcf5c */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(0xb17340u)); switch (t_) {  default: jump_indirect(c, t_, 0x00afcf5cu); return; } } /* jmp dword ptr [0x10067340] */
}

void f_00aff268(CPU *c) { /* PTR_00aff268 */
    PREEMPT_POLL(c);
    guest_trap(c, 0x00aff268u, "int3"); /* int3  */
}

void f_00b004c7(CPU *c) { /* PTR_00b004c7 */
    PREEMPT_POLL(c);
    guest_trap(c, 0x00b004c7u, "int3"); /* int3  */
}

void f_00b015c0(CPU *c) { /* Unwind@100515c0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_00ab16f9(c); return; } /* jmp 0xab16f9 */
}

void f_00b015c8(CPU *c) { /* PTR_00b015c8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0a114u); /* mov eax, 0x1005a114 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b015e0(CPU *c) { /* Unwind@100515e0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1d6u; PUSH32(c, v_); } /* push 0x1d6 */
    { uint32_t v_ = 0xb0ce30u; PUSH32(c, v_); } /* push 0x1005ce30 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b015f3u); f_00ab153c(c); /* call 0xab153c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b015f7(CPU *c) { /* PTR_00b015f7 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0a13cu); /* mov eax, 0x1005a13c */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b01610(CPU *c) { /* Unwind@10051610 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_00ab16f9(c); return; } /* jmp 0xab16f9 */
}

void f_00b01618(CPU *c) { /* PTR_00b01618 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0a164u); /* mov eax, 0x1005a164 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b01630(CPU *c) { /* Unwind@10051630 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffca4u)); /* lea ecx, [ebp - 0x35c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b0163b(CPU *c) { /* PTR_00b0163b */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0a1c8u); /* mov eax, 0x1005a1c8 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b01650(CPU *c) { /* Unwind@10051650 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_00ab16f9(c); return; } /* jmp 0xab16f9 */
}

void f_00b01658(CPU *c) { /* PTR_00b01658 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0a1f0u); /* mov eax, 0x1005a1f0 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b01670(CPU *c) { /* Unwind@10051670 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b0167b(CPU *c) { /* PTR_00b0167b */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0a218u); /* mov eax, 0x1005a218 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b01690(CPU *c) { /* Unwind@10051690 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b0169b(CPU *c) { /* PTR_00b0169b */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0a240u); /* mov eax, 0x1005a240 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b016b0(CPU *c) { /* Unwind@100516b0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_00ab16f9(c); return; } /* jmp 0xab16f9 */
}

void f_00b016b8(CPU *c) { /* PTR_00b016b8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0a268u); /* mov eax, 0x1005a268 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b016d0(CPU *c) { /* Unwind@100516d0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b016db(CPU *c) { /* PTR_00b016db */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0a290u); /* mov eax, 0x1005a290 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b016f0(CPU *c) { /* Unwind@100516f0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_00ab16f9(c); return; } /* jmp 0xab16f9 */
}

void f_00b016f8(CPU *c) { /* PTR_00b016f8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0a2b8u); /* mov eax, 0x1005a2b8 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b01710(CPU *c) { /* Unwind@10051710 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffba4u)); /* lea ecx, [ebp - 0x45c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b0171b(CPU *c) { /* Unwind@1005171b */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffba4u)); /* lea ecx, [ebp - 0x45c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b01726(CPU *c) { /* PTR_00b01726 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0a2e8u); /* mov eax, 0x1005a2e8 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b01740(CPU *c) { /* Unwind@10051740 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b0174b(CPU *c) { /* PTR_00b0174b */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0a310u); /* mov eax, 0x1005a310 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b01760(CPU *c) { /* Unwind@10051760 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_00ab16f9(c); return; } /* jmp 0xab16f9 */
}

void f_00b01768(CPU *c) { /* PTR_00b01768 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0a338u); /* mov eax, 0x1005a338 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b01780(CPU *c) { /* Unwind@10051780 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b0178b(CPU *c) { /* PTR_00b0178b */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0a360u); /* mov eax, 0x1005a360 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b017a0(CPU *c) { /* Unwind@100517a0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b017ab(CPU *c) { /* PTR_00b017ab */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0a388u); /* mov eax, 0x1005a388 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b017c0(CPU *c) { /* Unwind@100517c0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x2bu; PUSH32(c, v_); } /* push 0x2b */
    { uint32_t v_ = 0xb0d4b8u; PUSH32(c, v_); } /* push 0x1005d4b8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffda0u))); /* mov eax, dword ptr [ebp - 0x260] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b017d3u); f_00ab153c(c); /* call 0xab153c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b017d7(CPU *c) { /* Unwind@100517d7 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b017e2(CPU *c) { /* PTR_00b017e2 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0a3b8u); /* mov eax, 0x1005a3b8 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b01800(CPU *c) { /* Unwind@10051800 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_00ab16f9(c); return; } /* jmp 0xab16f9 */
}

void f_00b01808(CPU *c) { /* PTR_00b01808 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0a3e0u); /* mov eax, 0x1005a3e0 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b01820(CPU *c) { /* Unwind@10051820 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1d0u; PUSH32(c, v_); } /* push 0x1d0 */
    { uint32_t v_ = 0xb0d4b8u; PUSH32(c, v_); } /* push 0x1005d4b8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffba0u))); /* mov eax, dword ptr [ebp - 0x460] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b01836u); f_00ab153c(c); /* call 0xab153c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b0183a(CPU *c) { /* Unwind@1005183a */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffba4u)); /* lea ecx, [ebp - 0x45c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b01845(CPU *c) { /* PTR_00b01845 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0a410u); /* mov eax, 0x1005a410 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b01860(CPU *c) { /* Unwind@10051860 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1d6u; PUSH32(c, v_); } /* push 0x1d6 */
    { uint32_t v_ = 0xb0d6a0u; PUSH32(c, v_); } /* push 0x1005d6a0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffba0u))); /* mov eax, dword ptr [ebp - 0x460] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b01876u); f_00ab153c(c); /* call 0xab153c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b0187a(CPU *c) { /* Unwind@1005187a */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b01885(CPU *c) { /* PTR_00b01885 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0a440u); /* mov eax, 0x1005a440 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b018a0(CPU *c) { /* Unwind@100518a0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_00ab16f9(c); return; } /* jmp 0xab16f9 */
}

void f_00b018a8(CPU *c) { /* PTR_00b018a8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0a468u); /* mov eax, 0x1005a468 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b018c0(CPU *c) { /* Unwind@100518c0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b018cb(CPU *c) { /* Unwind@100518cb */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b018d6(CPU *c) { /* Unwind@100518d6 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b018e1(CPU *c) { /* Unwind@100518e1 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b018ec(CPU *c) { /* Unwind@100518ec */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b018f7(CPU *c) { /* PTR_00b018f7 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0a4b0u); /* mov eax, 0x1005a4b0 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b01920(CPU *c) { /* Unwind@10051920 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffca4u)); /* lea ecx, [ebp - 0x35c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b0192b(CPU *c) { /* Unwind@1005192b */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffca4u)); /* lea ecx, [ebp - 0x35c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b01936(CPU *c) { /* PTR_00b01936 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0a4e4u); /* mov eax, 0x1005a4e4 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b01950(CPU *c) { /* Unwind@10051950 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_00ab16f9(c); return; } /* jmp 0xab16f9 */
}

void f_00b01958(CPU *c) { /* PTR_00b01958 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0a50cu); /* mov eax, 0x1005a50c */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b01970(CPU *c) { /* Unwind@10051970 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_00ab16f9(c); return; } /* jmp 0xab16f9 */
}

void f_00b01978(CPU *c) { /* PTR_00b01978 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0a534u); /* mov eax, 0x1005a534 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b01990(CPU *c) { /* Unwind@10051990 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_00ab16f9(c); return; } /* jmp 0xab16f9 */
}

void f_00b01998(CPU *c) { /* PTR_00b01998 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0a55cu); /* mov eax, 0x1005a55c */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b019b0(CPU *c) { /* Unwind@100519b0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_00ab16f9(c); return; } /* jmp 0xab16f9 */
}

void f_00b019b8(CPU *c) { /* PTR_00b019b8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0a584u); /* mov eax, 0x1005a584 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b019d0(CPU *c) { /* Unwind@100519d0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b019db(CPU *c) { /* PTR_00b019db */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0a5acu); /* mov eax, 0x1005a5ac */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b019f0(CPU *c) { /* Unwind@100519f0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_00ab16f9(c); return; } /* jmp 0xab16f9 */
}

void f_00b019f8(CPU *c) { /* PTR_00b019f8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0a5d4u); /* mov eax, 0x1005a5d4 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b01a10(CPU *c) { /* Unwind@10051a10 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b01a1b(CPU *c) { /* PTR_00b01a1b */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0a5fcu); /* mov eax, 0x1005a5fc */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b01a30(CPU *c) { /* Unwind@10051a30 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_00ab16f9(c); return; } /* jmp 0xab16f9 */
}

void f_00b01a38(CPU *c) { /* PTR_00b01a38 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0a624u); /* mov eax, 0x1005a624 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b01a50(CPU *c) { /* Unwind@10051a50 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b01a5b(CPU *c) { /* PTR_00b01a5b */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0a64cu); /* mov eax, 0x1005a64c */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b01a70(CPU *c) { /* Unwind@10051a70 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_00ab16f9(c); return; } /* jmp 0xab16f9 */
}

void f_00b01a78(CPU *c) { /* PTR_00b01a78 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0a674u); /* mov eax, 0x1005a674 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b01a90(CPU *c) { /* Unwind@10051a90 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b01a9b(CPU *c) { /* PTR_00b01a9b */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0a69cu); /* mov eax, 0x1005a69c */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b01ab0(CPU *c) { /* Unwind@10051ab0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x19u; PUSH32(c, v_); } /* push 0x19 */
    { uint32_t v_ = 0xb0dbd0u; PUSH32(c, v_); } /* push 0x1005dbd0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffda0u))); /* mov eax, dword ptr [ebp - 0x260] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b01ac3u); f_00ab153c(c); /* call 0xab153c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b01ac7(CPU *c) { /* Unwind@10051ac7 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b01ad2(CPU *c) { /* PTR_00b01ad2 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0a6ccu); /* mov eax, 0x1005a6cc */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b01af0(CPU *c) { /* Unwind@10051af0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_00ab16f9(c); return; } /* jmp 0xab16f9 */
}

void f_00b01af8(CPU *c) { /* PTR_00b01af8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0a6f4u); /* mov eax, 0x1005a6f4 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b01b10(CPU *c) { /* Unwind@10051b10 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x111u; PUSH32(c, v_); } /* push 0x111 */
    { uint32_t v_ = 0xb0dbd0u; PUSH32(c, v_); } /* push 0x1005dbd0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffdba0u))); /* mov eax, dword ptr [ebp - 0x2460] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b01b26u); f_00ab153c(c); /* call 0xab153c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b01b2a(CPU *c) { /* Unwind@10051b2a */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffdba4u)); /* lea ecx, [ebp - 0x245c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b01b35(CPU *c) { /* PTR_00b01b35 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0a724u); /* mov eax, 0x1005a724 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b01b50(CPU *c) { /* Unwind@10051b50 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_00ab16f9(c); return; } /* jmp 0xab16f9 */
}

void f_00b01b58(CPU *c) { /* PTR_00b01b58 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0a74cu); /* mov eax, 0x1005a74c */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b01b70(CPU *c) { /* Unwind@10051b70 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b01b7b(CPU *c) { /* PTR_00b01b7b */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0a774u); /* mov eax, 0x1005a774 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b01b90(CPU *c) { /* Unwind@10051b90 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffca4u)); /* lea ecx, [ebp - 0x35c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b01b9b(CPU *c) { /* PTR_00b01b9b */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0a79cu); /* mov eax, 0x1005a79c */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b01bb0(CPU *c) { /* Unwind@10051bb0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_00ab16f9(c); return; } /* jmp 0xab16f9 */
}

void f_00b01bb8(CPU *c) { /* PTR_00b01bb8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0a7c4u); /* mov eax, 0x1005a7c4 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b01bd0(CPU *c) { /* Unwind@10051bd0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_00ab16f9(c); return; } /* jmp 0xab16f9 */
}

void f_00b01bd8(CPU *c) { /* PTR_00b01bd8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0a7ecu); /* mov eax, 0x1005a7ec */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b01be9(CPU *c) { /* PTR_00b01be9 */
    PREEMPT_POLL(c);
    guest_trap(c, 0x00b01be9u, "int3"); /* int3  */
}

void f_00b01bf0(CPU *c) { /* Unwind@10051bf0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b01bfb(CPU *c) { /* Unwind@10051bfb */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b01c06(CPU *c) { /* PTR_00b01c06 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0a81cu); /* mov eax, 0x1005a81c */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b01c20(CPU *c) { /* Unwind@10051c20 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_00ab16f9(c); return; } /* jmp 0xab16f9 */
}

void f_00b01c28(CPU *c) { /* PTR_00b01c28 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0a844u); /* mov eax, 0x1005a844 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b01c40(CPU *c) { /* Unwind@10051c40 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_00ab16f9(c); return; } /* jmp 0xab16f9 */
}

void f_00b01c48(CPU *c) { /* PTR_00b01c48 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0a86cu); /* mov eax, 0x1005a86c */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b01c60(CPU *c) { /* Unwind@10051c60 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffca4u)); /* lea ecx, [ebp - 0x35c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b01c6b(CPU *c) { /* Unwind@10051c6b */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffca4u)); /* lea ecx, [ebp - 0x35c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b01c76(CPU *c) { /* Unwind@10051c76 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffca4u)); /* lea ecx, [ebp - 0x35c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b01c81(CPU *c) { /* Unwind@10051c81 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffca4u)); /* lea ecx, [ebp - 0x35c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b01c8c(CPU *c) { /* Unwind@10051c8c */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffca4u)); /* lea ecx, [ebp - 0x35c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b01c97(CPU *c) { /* Unwind@10051c97 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffb7cu)); /* lea ecx, [ebp - 0x484] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b01ca2(CPU *c) { /* Unwind@10051ca2 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffb7cu)); /* lea ecx, [ebp - 0x484] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b01cad(CPU *c) { /* Unwind@10051cad */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffb7cu)); /* lea ecx, [ebp - 0x484] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b01cb8(CPU *c) { /* Unwind@10051cb8 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffb7cu)); /* lea ecx, [ebp - 0x484] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b01cc3(CPU *c) { /* Unwind@10051cc3 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffb7cu)); /* lea ecx, [ebp - 0x484] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b01cce(CPU *c) { /* PTR_00b01cce */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0a8dcu); /* mov eax, 0x1005a8dc */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b01d00(CPU *c) { /* Unwind@10051d00 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b01d0b(CPU *c) { /* PTR_00b01d0b */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0a90cu); /* mov eax, 0x1005a90c */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b01d20(CPU *c) { /* Unwind@10051d20 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffca4u)); /* lea ecx, [ebp - 0x35c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b01d2b(CPU *c) { /* Unwind@10051d2b */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffca4u)); /* lea ecx, [ebp - 0x35c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b01d36(CPU *c) { /* Unwind@10051d36 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffca4u)); /* lea ecx, [ebp - 0x35c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b01d41(CPU *c) { /* PTR_00b01d41 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0a944u); /* mov eax, 0x1005a944 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b01d60(CPU *c) { /* Unwind@10051d60 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b01d6b(CPU *c) { /* Unwind@10051d6b */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1d6u; PUSH32(c, v_); } /* push 0x1d6 */
    { uint32_t v_ = 0xb0ce30u; PUSH32(c, v_); } /* push 0x1005ce30 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffd1cu))); /* mov eax, dword ptr [ebp - 0x2e4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b01d81u); f_00ab153c(c); /* call 0xab153c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b01d85(CPU *c) { /* PTR_00b01d85 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0a978u); /* mov eax, 0x1005a978 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b01da0(CPU *c) { /* Unwind@10051da0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b01dab(CPU *c) { /* Unwind@10051dab */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b01db6(CPU *c) { /* Unwind@10051db6 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b01dc1(CPU *c) { /* Unwind@10051dc1 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffafcu)); /* lea ecx, [ebp - 0x504] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b01dcc(CPU *c) { /* Unwind@10051dcc */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffafcu)); /* lea ecx, [ebp - 0x504] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b01dd7(CPU *c) { /* Unwind@10051dd7 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffafcu)); /* lea ecx, [ebp - 0x504] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b01de2(CPU *c) { /* Unwind@10051de2 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffafcu)); /* lea ecx, [ebp - 0x504] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b01ded(CPU *c) { /* Unwind@10051ded */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1d6u; PUSH32(c, v_); } /* push 0x1d6 */
    { uint32_t v_ = 0xb0ce30u; PUSH32(c, v_); } /* push 0x1005ce30 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffaf0u))); /* mov eax, dword ptr [ebp - 0x510] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b01e03u); f_00ab153c(c); /* call 0xab153c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b01e07(CPU *c) { /* PTR_00b01e07 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0a9d8u); /* mov eax, 0x1005a9d8 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b01e30(CPU *c) { /* Unwind@10051e30 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_00ab16f9(c); return; } /* jmp 0xab16f9 */
}

void f_00b01e38(CPU *c) { /* PTR_00b01e38 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0aa08u); /* mov eax, 0x1005aa08 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b01e50(CPU *c) { /* Unwind@10051e50 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffff0a4u)); /* lea ecx, [ebp - 0xf5c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b01e5b(CPU *c) { /* PTR_00b01e5b */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0aa30u); /* mov eax, 0x1005aa30 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b01e70(CPU *c) { /* Unwind@10051e70 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_00ab16f9(c); return; } /* jmp 0xab16f9 */
}

void f_00b01e78(CPU *c) { /* PTR_00b01e78 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0aa58u); /* mov eax, 0x1005aa58 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b01e90(CPU *c) { /* Unwind@10051e90 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b01e9b(CPU *c) { /* PTR_00b01e9b */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0aa80u); /* mov eax, 0x1005aa80 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b01eb0(CPU *c) { /* Unwind@10051eb0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_00ab16f9(c); return; } /* jmp 0xab16f9 */
}

void f_00b01eb8(CPU *c) { /* PTR_00b01eb8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0aaa8u); /* mov eax, 0x1005aaa8 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b01ed0(CPU *c) { /* Unwind@10051ed0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b01edb(CPU *c) { /* Unwind@10051edb */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b01ee6(CPU *c) { /* PTR_00b01ee6 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0aad8u); /* mov eax, 0x1005aad8 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b01f00(CPU *c) { /* Unwind@10051f00 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_00ab16f9(c); return; } /* jmp 0xab16f9 */
}

void f_00b01f08(CPU *c) { /* PTR_00b01f08 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0ab00u); /* mov eax, 0x1005ab00 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b01f20(CPU *c) { /* Unwind@10051f20 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b01f2b(CPU *c) { /* PTR_00b01f2b */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0ab28u); /* mov eax, 0x1005ab28 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b01f40(CPU *c) { /* Unwind@10051f40 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_00ab16f9(c); return; } /* jmp 0xab16f9 */
}

void f_00b01f48(CPU *c) { /* PTR_00b01f48 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0ab50u); /* mov eax, 0x1005ab50 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b01f60(CPU *c) { /* Unwind@10051f60 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b01f6b(CPU *c) { /* Unwind@10051f6b */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b01f76(CPU *c) { /* Unwind@10051f76 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b01f81(CPU *c) { /* PTR_00b01f81 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0ab88u); /* mov eax, 0x1005ab88 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b01fa0(CPU *c) { /* Unwind@10051fa0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_00ab16f9(c); return; } /* jmp 0xab16f9 */
}

void f_00b01fa8(CPU *c) { /* PTR_00b01fa8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0abb4u); /* mov eax, 0x1005abb4 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b01fc0(CPU *c) { /* Unwind@10051fc0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b01fcb(CPU *c) { /* Unwind@10051fcb */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b01fd6(CPU *c) { /* PTR_00b01fd6 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0abe4u); /* mov eax, 0x1005abe4 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b01ff0(CPU *c) { /* Unwind@10051ff0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b01ffb(CPU *c) { /* PTR_00b01ffb */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0ac0cu); /* mov eax, 0x1005ac0c */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b02010(CPU *c) { /* Unwind@10052010 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_00ab16f9(c); return; } /* jmp 0xab16f9 */
}

void f_00b02018(CPU *c) { /* PTR_00b02018 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0ac34u); /* mov eax, 0x1005ac34 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b02030(CPU *c) { /* Unwind@10052030 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b0203b(CPU *c) { /* Unwind@1005203b */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b02046(CPU *c) { /* Unwind@10052046 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b02051(CPU *c) { /* PTR_00b02051 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0ac6cu); /* mov eax, 0x1005ac6c */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b02070(CPU *c) { /* Unwind@10052070 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_00ab16f9(c); return; } /* jmp 0xab16f9 */
}

void f_00b02078(CPU *c) { /* PTR_00b02078 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0ac98u); /* mov eax, 0x1005ac98 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b02090(CPU *c) { /* Unwind@10052090 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_00ab16f9(c); return; } /* jmp 0xab16f9 */
}

void f_00b02098(CPU *c) { /* PTR_00b02098 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0acc0u); /* mov eax, 0x1005acc0 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b020b0(CPU *c) { /* Unwind@100520b0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b020bb(CPU *c) { /* PTR_00b020bb */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0ace8u); /* mov eax, 0x1005ace8 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b020d0(CPU *c) { /* Unwind@100520d0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b020db(CPU *c) { /* Unwind@100520db */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b020e6(CPU *c) { /* PTR_00b020e6 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0ad18u); /* mov eax, 0x1005ad18 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b02100(CPU *c) { /* Unwind@10052100 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x16u; PUSH32(c, v_); } /* push 0x16 */
    { uint32_t v_ = 0xb0eb04u; PUSH32(c, v_); } /* push 0x1005eb04 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b02110u); f_00ab153c(c); /* call 0xab153c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b02114(CPU *c) { /* PTR_00b02114 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0ad40u); /* mov eax, 0x1005ad40 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b02130(CPU *c) { /* Unwind@10052130 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    { uint32_t v_ = 0xb0eb04u; PUSH32(c, v_); } /* push 0x1005eb04 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b02140u); f_00ab153c(c); /* call 0xab153c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b02144(CPU *c) { /* PTR_00b02144 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0ad68u); /* mov eax, 0x1005ad68 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b02160(CPU *c) { /* Unwind@10052160 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x19u; PUSH32(c, v_); } /* push 0x19 */
    { uint32_t v_ = 0xb0eb04u; PUSH32(c, v_); } /* push 0x1005eb04 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b02170u); f_00ab153c(c); /* call 0xab153c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b02174(CPU *c) { /* PTR_00b02174 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0ad90u); /* mov eax, 0x1005ad90 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b02190(CPU *c) { /* Unwind@10052190 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1au; PUSH32(c, v_); } /* push 0x1a */
    { uint32_t v_ = 0xb0eb04u; PUSH32(c, v_); } /* push 0x1005eb04 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b021a0u); f_00ab153c(c); /* call 0xab153c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b021a4(CPU *c) { /* PTR_00b021a4 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0adb8u); /* mov eax, 0x1005adb8 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b021c0(CPU *c) { /* Unwind@100521c0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1bu; PUSH32(c, v_); } /* push 0x1b */
    { uint32_t v_ = 0xb0eb04u; PUSH32(c, v_); } /* push 0x1005eb04 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b021d0u); f_00ab153c(c); /* call 0xab153c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b021d4(CPU *c) { /* PTR_00b021d4 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0ade0u); /* mov eax, 0x1005ade0 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b021f0(CPU *c) { /* Unwind@100521f0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1cu; PUSH32(c, v_); } /* push 0x1c */
    { uint32_t v_ = 0xb0eb04u; PUSH32(c, v_); } /* push 0x1005eb04 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b02200u); f_00ab153c(c); /* call 0xab153c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b02204(CPU *c) { /* PTR_00b02204 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0ae08u); /* mov eax, 0x1005ae08 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b02220(CPU *c) { /* Unwind@10052220 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1du; PUSH32(c, v_); } /* push 0x1d */
    { uint32_t v_ = 0xb0eb04u; PUSH32(c, v_); } /* push 0x1005eb04 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b02230u); f_00ab153c(c); /* call 0xab153c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b02234(CPU *c) { /* PTR_00b02234 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0ae30u); /* mov eax, 0x1005ae30 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b02250(CPU *c) { /* Unwind@10052250 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1eu; PUSH32(c, v_); } /* push 0x1e */
    { uint32_t v_ = 0xb0eb04u; PUSH32(c, v_); } /* push 0x1005eb04 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b02260u); f_00ab153c(c); /* call 0xab153c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b02264(CPU *c) { /* PTR_00b02264 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0ae58u); /* mov eax, 0x1005ae58 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b02280(CPU *c) { /* Unwind@10052280 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x21u; PUSH32(c, v_); } /* push 0x21 */
    { uint32_t v_ = 0xb0eb04u; PUSH32(c, v_); } /* push 0x1005eb04 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b02290u); f_00ab153c(c); /* call 0xab153c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b02294(CPU *c) { /* PTR_00b02294 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0ae80u); /* mov eax, 0x1005ae80 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b022b0(CPU *c) { /* Unwind@100522b0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_00ab150a(c); return; } /* jmp 0xab150a */
}

void f_00b022b8(CPU *c) { /* PTR_00b022b8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0aea8u); /* mov eax, 0x1005aea8 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b022d0(CPU *c) { /* Unwind@100522d0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b022db(CPU *c) { /* Unwind@100522db */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b022e6(CPU *c) { /* Unwind@100522e6 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xa9u; PUSH32(c, v_); } /* push 0xa9 */
    { uint32_t v_ = 0xb0eb04u; PUSH32(c, v_); } /* push 0x1005eb04 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffda0u))); /* mov eax, dword ptr [ebp - 0x260] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b022fcu); f_00ab153c(c); /* call 0xab153c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b02300(CPU *c) { /* Unwind@10052300 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b0230b(CPU *c) { /* Unwind@1005230b */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xb0u; PUSH32(c, v_); } /* push 0xb0 */
    { uint32_t v_ = 0xb0eb04u; PUSH32(c, v_); } /* push 0x1005eb04 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffda0u))); /* mov eax, dword ptr [ebp - 0x260] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b02321u); f_00ab153c(c); /* call 0xab153c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b02325(CPU *c) { /* Unwind@10052325 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b02330(CPU *c) { /* PTR_00b02330 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0aef8u); /* mov eax, 0x1005aef8 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b02360(CPU *c) { /* Unwind@10052360 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffdcecu)); /* lea ecx, [ebp - 0x2314] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b0236b(CPU *c) { /* Unwind@1005236b */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffdcecu)); /* lea ecx, [ebp - 0x2314] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b02376(CPU *c) { /* Unwind@10052376 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffdcecu)); /* lea ecx, [ebp - 0x2314] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b02381(CPU *c) { /* Unwind@10052381 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffdcecu)); /* lea ecx, [ebp - 0x2314] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b0238c(CPU *c) { /* PTR_00b0238c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0af3cu); /* mov eax, 0x1005af3c */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b023b0(CPU *c) { /* Unwind@100523b0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b023bb(CPU *c) { /* PTR_00b023bb */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0af68u); /* mov eax, 0x1005af68 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b023d0(CPU *c) { /* Unwind@100523d0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x493u; PUSH32(c, v_); } /* push 0x493 */
    { uint32_t v_ = 0xb0eb04u; PUSH32(c, v_); } /* push 0x1005eb04 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffff530u))); /* mov eax, dword ptr [ebp - 0xad0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b023e6u); f_00ab153c(c); /* call 0xab153c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b023ea(CPU *c) { /* Unwind@100523ea */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x494u; PUSH32(c, v_); } /* push 0x494 */
    { uint32_t v_ = 0xb0eb04u; PUSH32(c, v_); } /* push 0x1005eb04 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffff530u))); /* mov eax, dword ptr [ebp - 0xad0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b02400u); f_00ab153c(c); /* call 0xab153c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b02404(CPU *c) { /* Unwind@10052404 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x495u; PUSH32(c, v_); } /* push 0x495 */
    { uint32_t v_ = 0xb0eb04u; PUSH32(c, v_); } /* push 0x1005eb04 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffff530u))); /* mov eax, dword ptr [ebp - 0xad0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b0241au); f_00ab153c(c); /* call 0xab153c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b0241e(CPU *c) { /* Unwind@1005241e */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x496u; PUSH32(c, v_); } /* push 0x496 */
    { uint32_t v_ = 0xb0eb04u; PUSH32(c, v_); } /* push 0x1005eb04 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffff530u))); /* mov eax, dword ptr [ebp - 0xad0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b02434u); f_00ab153c(c); /* call 0xab153c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b02438(CPU *c) { /* Unwind@10052438 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x497u; PUSH32(c, v_); } /* push 0x497 */
    { uint32_t v_ = 0xb0eb04u; PUSH32(c, v_); } /* push 0x1005eb04 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffff530u))); /* mov eax, dword ptr [ebp - 0xad0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b0244eu); f_00ab153c(c); /* call 0xab153c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b02452(CPU *c) { /* Unwind@10052452 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x498u; PUSH32(c, v_); } /* push 0x498 */
    { uint32_t v_ = 0xb0eb04u; PUSH32(c, v_); } /* push 0x1005eb04 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffff530u))); /* mov eax, dword ptr [ebp - 0xad0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b02468u); f_00ab153c(c); /* call 0xab153c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b0246c(CPU *c) { /* Unwind@1005246c */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x499u; PUSH32(c, v_); } /* push 0x499 */
    { uint32_t v_ = 0xb0eb04u; PUSH32(c, v_); } /* push 0x1005eb04 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffff530u))); /* mov eax, dword ptr [ebp - 0xad0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b02482u); f_00ab153c(c); /* call 0xab153c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b02486(CPU *c) { /* Unwind@10052486 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x49au; PUSH32(c, v_); } /* push 0x49a */
    { uint32_t v_ = 0xb0eb04u; PUSH32(c, v_); } /* push 0x1005eb04 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffff530u))); /* mov eax, dword ptr [ebp - 0xad0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b0249cu); f_00ab153c(c); /* call 0xab153c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b024a0(CPU *c) { /* Unwind@100524a0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x49bu; PUSH32(c, v_); } /* push 0x49b */
    { uint32_t v_ = 0xb0eb04u; PUSH32(c, v_); } /* push 0x1005eb04 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffff530u))); /* mov eax, dword ptr [ebp - 0xad0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b024b6u); f_00ab153c(c); /* call 0xab153c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b024ba(CPU *c) { /* Unwind@100524ba */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x49cu; PUSH32(c, v_); } /* push 0x49c */
    { uint32_t v_ = 0xb0eb04u; PUSH32(c, v_); } /* push 0x1005eb04 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffff530u))); /* mov eax, dword ptr [ebp - 0xad0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b024d0u); f_00ab153c(c); /* call 0xab153c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b024d4(CPU *c) { /* Unwind@100524d4 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x49du; PUSH32(c, v_); } /* push 0x49d */
    { uint32_t v_ = 0xb0eb04u; PUSH32(c, v_); } /* push 0x1005eb04 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffff530u))); /* mov eax, dword ptr [ebp - 0xad0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b024eau); f_00ab153c(c); /* call 0xab153c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b024ee(CPU *c) { /* Unwind@100524ee */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x49eu; PUSH32(c, v_); } /* push 0x49e */
    { uint32_t v_ = 0xb0eb04u; PUSH32(c, v_); } /* push 0x1005eb04 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffff530u))); /* mov eax, dword ptr [ebp - 0xad0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b02504u); f_00ab153c(c); /* call 0xab153c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b02508(CPU *c) { /* Unwind@10052508 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x49fu; PUSH32(c, v_); } /* push 0x49f */
    { uint32_t v_ = 0xb0eb04u; PUSH32(c, v_); } /* push 0x1005eb04 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffff530u))); /* mov eax, dword ptr [ebp - 0xad0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b0251eu); f_00ab153c(c); /* call 0xab153c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b02522(CPU *c) { /* Unwind@10052522 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x4a0u; PUSH32(c, v_); } /* push 0x4a0 */
    { uint32_t v_ = 0xb0eb04u; PUSH32(c, v_); } /* push 0x1005eb04 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffff530u))); /* mov eax, dword ptr [ebp - 0xad0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b02538u); f_00ab153c(c); /* call 0xab153c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b0253c(CPU *c) { /* Unwind@1005253c */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x4a1u; PUSH32(c, v_); } /* push 0x4a1 */
    { uint32_t v_ = 0xb0eb04u; PUSH32(c, v_); } /* push 0x1005eb04 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffff530u))); /* mov eax, dword ptr [ebp - 0xad0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b02552u); f_00ab153c(c); /* call 0xab153c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b02556(CPU *c) { /* Unwind@10052556 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x4a2u; PUSH32(c, v_); } /* push 0x4a2 */
    { uint32_t v_ = 0xb0eb04u; PUSH32(c, v_); } /* push 0x1005eb04 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffff530u))); /* mov eax, dword ptr [ebp - 0xad0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b0256cu); f_00ab153c(c); /* call 0xab153c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b02570(CPU *c) { /* Unwind@10052570 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x4a3u; PUSH32(c, v_); } /* push 0x4a3 */
    { uint32_t v_ = 0xb0eb04u; PUSH32(c, v_); } /* push 0x1005eb04 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffff530u))); /* mov eax, dword ptr [ebp - 0xad0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b02586u); f_00ab153c(c); /* call 0xab153c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b0258a(CPU *c) { /* Unwind@1005258a */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x4a4u; PUSH32(c, v_); } /* push 0x4a4 */
    { uint32_t v_ = 0xb0eb04u; PUSH32(c, v_); } /* push 0x1005eb04 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffff530u))); /* mov eax, dword ptr [ebp - 0xad0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b025a0u); f_00ab153c(c); /* call 0xab153c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b025a4(CPU *c) { /* Unwind@100525a4 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x4a5u; PUSH32(c, v_); } /* push 0x4a5 */
    { uint32_t v_ = 0xb0eb04u; PUSH32(c, v_); } /* push 0x1005eb04 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffff530u))); /* mov eax, dword ptr [ebp - 0xad0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b025bau); f_00ab153c(c); /* call 0xab153c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b025be(CPU *c) { /* Unwind@100525be */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x4a6u; PUSH32(c, v_); } /* push 0x4a6 */
    { uint32_t v_ = 0xb0eb04u; PUSH32(c, v_); } /* push 0x1005eb04 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffff530u))); /* mov eax, dword ptr [ebp - 0xad0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b025d4u); f_00ab153c(c); /* call 0xab153c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b025d8(CPU *c) { /* Unwind@100525d8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x4a7u; PUSH32(c, v_); } /* push 0x4a7 */
    { uint32_t v_ = 0xb0eb04u; PUSH32(c, v_); } /* push 0x1005eb04 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffff530u))); /* mov eax, dword ptr [ebp - 0xad0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b025eeu); f_00ab153c(c); /* call 0xab153c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b025f2(CPU *c) { /* Unwind@100525f2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x4a8u; PUSH32(c, v_); } /* push 0x4a8 */
    { uint32_t v_ = 0xb0eb04u; PUSH32(c, v_); } /* push 0x1005eb04 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffff530u))); /* mov eax, dword ptr [ebp - 0xad0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b02608u); f_00ab153c(c); /* call 0xab153c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b0260c(CPU *c) { /* Unwind@1005260c */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x4a9u; PUSH32(c, v_); } /* push 0x4a9 */
    { uint32_t v_ = 0xb0eb04u; PUSH32(c, v_); } /* push 0x1005eb04 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffff530u))); /* mov eax, dword ptr [ebp - 0xad0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b02622u); f_00ab153c(c); /* call 0xab153c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b02626(CPU *c) { /* Unwind@10052626 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x4aau; PUSH32(c, v_); } /* push 0x4aa */
    { uint32_t v_ = 0xb0eb04u; PUSH32(c, v_); } /* push 0x1005eb04 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffff530u))); /* mov eax, dword ptr [ebp - 0xad0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b0263cu); f_00ab153c(c); /* call 0xab153c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b02640(CPU *c) { /* Unwind@10052640 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x4abu; PUSH32(c, v_); } /* push 0x4ab */
    { uint32_t v_ = 0xb0eb04u; PUSH32(c, v_); } /* push 0x1005eb04 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffff530u))); /* mov eax, dword ptr [ebp - 0xad0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b02656u); f_00ab153c(c); /* call 0xab153c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b0265a(CPU *c) { /* Unwind@1005265a */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x4acu; PUSH32(c, v_); } /* push 0x4ac */
    { uint32_t v_ = 0xb0eb04u; PUSH32(c, v_); } /* push 0x1005eb04 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffff530u))); /* mov eax, dword ptr [ebp - 0xad0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b02670u); f_00ab153c(c); /* call 0xab153c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b02674(CPU *c) { /* Unwind@10052674 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x4adu; PUSH32(c, v_); } /* push 0x4ad */
    { uint32_t v_ = 0xb0eb04u; PUSH32(c, v_); } /* push 0x1005eb04 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffff530u))); /* mov eax, dword ptr [ebp - 0xad0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b0268au); f_00ab153c(c); /* call 0xab153c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b0268e(CPU *c) { /* Unwind@1005268e */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x4aeu; PUSH32(c, v_); } /* push 0x4ae */
    { uint32_t v_ = 0xb0eb04u; PUSH32(c, v_); } /* push 0x1005eb04 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffff530u))); /* mov eax, dword ptr [ebp - 0xad0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b026a4u); f_00ab153c(c); /* call 0xab153c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b026a8(CPU *c) { /* Unwind@100526a8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x4afu; PUSH32(c, v_); } /* push 0x4af */
    { uint32_t v_ = 0xb0eb04u; PUSH32(c, v_); } /* push 0x1005eb04 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffff530u))); /* mov eax, dword ptr [ebp - 0xad0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b026beu); f_00ab153c(c); /* call 0xab153c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b026c2(CPU *c) { /* Unwind@100526c2 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffff954u)); /* lea ecx, [ebp - 0x6ac] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b026cd(CPU *c) { /* Unwind@100526cd */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffa7cu)); /* lea ecx, [ebp - 0x584] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b026d8(CPU *c) { /* Unwind@100526d8 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffff954u)); /* lea ecx, [ebp - 0x6ac] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b026e3(CPU *c) { /* PTR_00b026e3 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0b088u); /* mov eax, 0x1005b088 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b027c0(CPU *c) { /* Unwind@100527c0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_00ab1442(c); return; } /* jmp 0xab1442 */
}

void f_00b027c8(CPU *c) { /* PTR_00b027c8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0b0c8u); /* mov eax, 0x1005b0c8 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b027e0(CPU *c) { /* Unwind@100527e0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffb3cu)); /* lea ecx, [ebp - 0x4c4] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b027eb(CPU *c) { /* Unwind@100527eb */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffb3cu)); /* lea ecx, [ebp - 0x4c4] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b027f6(CPU *c) { /* Unwind@100527f6 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffc64u)); /* lea ecx, [ebp - 0x39c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b02801(CPU *c) { /* PTR_00b02801 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0b100u); /* mov eax, 0x1005b100 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b02820(CPU *c) { /* Unwind@10052820 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_00ab137f(c); return; } /* jmp 0xab137f */
}

void f_00b02828(CPU *c) { /* PTR_00b02828 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0b12cu); /* mov eax, 0x1005b12c */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b02840(CPU *c) { /* Unwind@10052840 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b0284b(CPU *c) { /* PTR_00b0284b */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0b154u); /* mov eax, 0x1005b154 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b02860(CPU *c) { /* Unwind@10052860 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b0286b(CPU *c) { /* PTR_00b0286b */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0b17cu); /* mov eax, 0x1005b17c */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b02880(CPU *c) { /* Unwind@10052880 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_00ab19f1(c); return; } /* jmp 0xab19f1 */
}

void f_00b02888(CPU *c) { /* PTR_00b02888 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0b1a4u); /* mov eax, 0x1005b1a4 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b028a0(CPU *c) { /* Unwind@100528a0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffaa4u)); /* lea ecx, [ebp - 0x55c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b028ab(CPU *c) { /* Unwind@100528ab */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffaa4u)); /* lea ecx, [ebp - 0x55c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b028b6(CPU *c) { /* Unwind@100528b6 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffaa4u)); /* lea ecx, [ebp - 0x55c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b028c1(CPU *c) { /* Unwind@100528c1 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffaa4u)); /* lea ecx, [ebp - 0x55c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b028cc(CPU *c) { /* Unwind@100528cc */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffaa4u)); /* lea ecx, [ebp - 0x55c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b028d7(CPU *c) { /* Unwind@100528d7 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffaa4u)); /* lea ecx, [ebp - 0x55c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b028e2(CPU *c) { /* Unwind@100528e2 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffaa4u)); /* lea ecx, [ebp - 0x55c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b028ed(CPU *c) { /* PTR_00b028ed */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0b1fcu); /* mov eax, 0x1005b1fc */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b02910(CPU *c) { /* Unwind@10052910 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffba4u)); /* lea ecx, [ebp - 0x45c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b0291b(CPU *c) { /* PTR_00b0291b */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0b228u); /* mov eax, 0x1005b228 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b02930(CPU *c) { /* Unwind@10052930 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffba4u)); /* lea ecx, [ebp - 0x45c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b0293b(CPU *c) { /* Unwind@1005293b */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffba4u)); /* lea ecx, [ebp - 0x45c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b02946(CPU *c) { /* Unwind@10052946 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffba4u)); /* lea ecx, [ebp - 0x45c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b02951(CPU *c) { /* Unwind@10052951 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffba4u)); /* lea ecx, [ebp - 0x45c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b0295c(CPU *c) { /* PTR_00b0295c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0b268u); /* mov eax, 0x1005b268 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b02980(CPU *c) { /* Unwind@10052980 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b0298b(CPU *c) { /* Unwind@1005298b */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b02996(CPU *c) { /* PTR_00b02996 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0b29cu); /* mov eax, 0x1005b29c */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b029b0(CPU *c) { /* Unwind@100529b0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_00ab15ff(c); return; } /* jmp 0xab15ff */
}

void f_00b029b8(CPU *c) { /* PTR_00b029b8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0b2c4u); /* mov eax, 0x1005b2c4 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b029d0(CPU *c) { /* Unwind@100529d0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_00ab1442(c); return; } /* jmp 0xab1442 */
}

void f_00b029d8(CPU *c) { /* PTR_00b029d8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0b2ecu); /* mov eax, 0x1005b2ec */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b029f0(CPU *c) { /* Unwind@100529f0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b029fb(CPU *c) { /* PTR_00b029fb */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0b314u); /* mov eax, 0x1005b314 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b02a10(CPU *c) { /* Unwind@10052a10 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b02a1b(CPU *c) { /* PTR_00b02a1b */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0b33cu); /* mov eax, 0x1005b33c */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b02a30(CPU *c) { /* Unwind@10052a30 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffff9a4u)); /* lea ecx, [ebp - 0x65c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b02a3b(CPU *c) { /* Unwind@10052a3b */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffff9a4u)); /* lea ecx, [ebp - 0x65c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b02a46(CPU *c) { /* PTR_00b02a46 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0b36cu); /* mov eax, 0x1005b36c */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b02a60(CPU *c) { /* Unwind@10052a60 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b02a6b(CPU *c) { /* PTR_00b02a6b */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0b394u); /* mov eax, 0x1005b394 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b02a80(CPU *c) { /* Unwind@10052a80 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_00ab1442(c); return; } /* jmp 0xab1442 */
}

void f_00b02a88(CPU *c) { /* PTR_00b02a88 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0b3bcu); /* mov eax, 0x1005b3bc */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b02aa0(CPU *c) { /* Unwind@10052aa0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b02aab(CPU *c) { /* PTR_00b02aab */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0b3e4u); /* mov eax, 0x1005b3e4 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}

void f_00b02ac0(CPU *c) { /* Unwind@10052ac0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b02acb(CPU *c) { /* Unwind@10052acb */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00ab1a55(c); return; } /* jmp 0xab1a55 */
}

void f_00b02ad6(CPU *c) { /* PTR_00b02ad6 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb0b414u); /* mov eax, 0x1005b414 */
    { f_00aeec72(c); return; } /* jmp 0xaeec72 */
}
