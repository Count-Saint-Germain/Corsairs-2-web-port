#include "recomp.h"

void f_006bd330(CPU *c) { /* Unwind@1002d330 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_00699e80(c); return; } /* jmp 0x699e80 */
}

void f_006bd338(CPU *c) { /* PTR_006bd338 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x6c2468u); /* mov eax, 0x10032468 */
    { f_006aef44(c); return; } /* jmp 0x6aef44 */
}

void f_006bd350(CPU *c) { /* Unwind@1002d350 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_006961c0(c); return; } /* jmp 0x6961c0 */
}

void f_006bd35b(CPU *c) { /* PTR_006bd35b */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x6c248cu); /* mov eax, 0x1003248c */
    { f_006aef44(c); return; } /* jmp 0x6aef44 */
}

void f_006bd370(CPU *c) { /* Unwind@1002d370 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffca4u)); /* lea ecx, [ebp - 0x35c] */
    { f_006961c0(c); return; } /* jmp 0x6961c0 */
}

void f_006bd37b(CPU *c) { /* PTR_006bd37b */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x6c24b0u); /* mov eax, 0x100324b0 */
    { f_006aef44(c); return; } /* jmp 0x6aef44 */
}

void f_006bd390(CPU *c) { /* Unwind@1002d390 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x61au; PUSH32(c, v_); } /* push 0x61a */
    { uint32_t v_ = 0x6c3a54u; PUSH32(c, v_); } /* push 0x10033a54 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006bd3a3u); f_00692260(c); /* call 0x692260 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_006bd3a7(CPU *c) { /* PTR_006bd3a7 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x6c24d4u); /* mov eax, 0x100324d4 */
    { f_006aef44(c); return; } /* jmp 0x6aef44 */
}

void f_006bd3c0(CPU *c) { /* Unwind@1002d3c0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x6cfu; PUSH32(c, v_); } /* push 0x6cf */
    { uint32_t v_ = 0x6c3a54u; PUSH32(c, v_); } /* push 0x10033a54 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffb78u))); /* mov eax, dword ptr [ebp - 0x488] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006bd3d6u); f_00692260(c); /* call 0x692260 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_006bd3da(CPU *c) { /* PTR_006bd3da */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x6c24f8u); /* mov eax, 0x100324f8 */
    { f_006aef44(c); return; } /* jmp 0x6aef44 */
}

void f_006bd3f0(CPU *c) { /* Unwind@1002d3f0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x747u; PUSH32(c, v_); } /* push 0x747 */
    { uint32_t v_ = 0x6c3a54u; PUSH32(c, v_); } /* push 0x10033a54 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffc78u))); /* mov eax, dword ptr [ebp - 0x388] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006bd406u); f_00692260(c); /* call 0x692260 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_006bd40a(CPU *c) { /* PTR_006bd40a */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x6c251cu); /* mov eax, 0x1003251c */
    { f_006aef44(c); return; } /* jmp 0x6aef44 */
}

void f_006bd420(CPU *c) { /* Unwind@1002d420 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x22u; PUSH32(c, v_); } /* push 0x22 */
    { uint32_t v_ = 0x6c634cu; PUSH32(c, v_); } /* push 0x1003634c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006bd430u); f_00692260(c); /* call 0x692260 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_006bd434(CPU *c) { /* PTR_006bd434 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x6c2540u); /* mov eax, 0x10032540 */
    { f_006aef44(c); return; } /* jmp 0x6aef44 */
}

void f_006bd440(CPU *c) { /* Unwind@1002d440 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x18u)); /* add ecx, 0x18 */
    { f_0069d3e0(c); return; } /* jmp 0x69d3e0 */
}

void f_006bd44b(CPU *c) { /* PTR_006bd44b */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x6c2564u); /* mov eax, 0x10032564 */
    { f_006aef44(c); return; } /* jmp 0x6aef44 */
}

void f_006bd460(CPU *c) { /* Unwind@1002d460 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_006961c0(c); return; } /* jmp 0x6961c0 */
}

void f_006bd46b(CPU *c) { /* PTR_006bd46b */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x6c2588u); /* mov eax, 0x10032588 */
    { f_006aef44(c); return; } /* jmp 0x6aef44 */
}

void f_006bd480(CPU *c) { /* Unwind@1002d480 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_006961c0(c); return; } /* jmp 0x6961c0 */
}

void f_006bd48b(CPU *c) { /* PTR_006bd48b */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x6c25acu); /* mov eax, 0x100325ac */
    { f_006aef44(c); return; } /* jmp 0x6aef44 */
}

void f_006bd495(CPU *c) { /* Unwind@1002d495 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_006a3b25(c); return; } /* jmp 0x6a3b25 */
}

void f_006bd49d(CPU *c) { /* Unwind@1002d49d */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x14u)); /* add ecx, 0x14 */
    { f_006a3a62(c); return; } /* jmp 0x6a3a62 */
}

void f_006bd4a8(CPU *c) { /* Unwind@1002d4a8 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x24u)); /* add ecx, 0x24 */
    { f_006a3a62(c); return; } /* jmp 0x6a3a62 */
}

void f_006bd4b3(CPU *c) { /* Unwind@1002d4b3 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x34u)); /* add ecx, 0x34 */
    { f_006a3a62(c); return; } /* jmp 0x6a3a62 */
}

void f_006bd4be(CPU *c) { /* Unwind@1002d4be */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x44u)); /* add ecx, 0x44 */
    { f_006a3a62(c); return; } /* jmp 0x6a3a62 */
}

void f_006bd4c9(CPU *c) { /* Unwind@1002d4c9 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x54u)); /* add ecx, 0x54 */
    { f_006a3a62(c); return; } /* jmp 0x6a3a62 */
}

void f_006bd4d4(CPU *c) { /* Unwind@1002d4d4 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x64u)); /* add ecx, 0x64 */
    { f_006a3a62(c); return; } /* jmp 0x6a3a62 */
}

void f_006bd4df(CPU *c) { /* Unwind@1002d4df */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x74u)); /* add ecx, 0x74 */
    { f_006a3a62(c); return; } /* jmp 0x6a3a62 */
}

void f_006bd4ea(CPU *c) { /* PTR_006bd4ea */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x6c2608u); /* mov eax, 0x10032608 */
    { f_006aef44(c); return; } /* jmp 0x6aef44 */
}

void f_006bd4f4(CPU *c) { /* Unwind@1002d4f4 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_006a3b25(c); return; } /* jmp 0x6a3b25 */
}

void f_006bd4fc(CPU *c) { /* Unwind@1002d4fc */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x14u)); /* add ecx, 0x14 */
    { f_006a3a62(c); return; } /* jmp 0x6a3a62 */
}

void f_006bd507(CPU *c) { /* Unwind@1002d507 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x24u)); /* add ecx, 0x24 */
    { f_006a3a62(c); return; } /* jmp 0x6a3a62 */
}

void f_006bd512(CPU *c) { /* Unwind@1002d512 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x34u)); /* add ecx, 0x34 */
    { f_006a3a62(c); return; } /* jmp 0x6a3a62 */
}

void f_006bd51d(CPU *c) { /* Unwind@1002d51d */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x44u)); /* add ecx, 0x44 */
    { f_006a3a62(c); return; } /* jmp 0x6a3a62 */
}

void f_006bd528(CPU *c) { /* Unwind@1002d528 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x54u)); /* add ecx, 0x54 */
    { f_006a3a62(c); return; } /* jmp 0x6a3a62 */
}

void f_006bd533(CPU *c) { /* Unwind@1002d533 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x64u)); /* add ecx, 0x64 */
    { f_006a3a62(c); return; } /* jmp 0x6a3a62 */
}

void f_006bd53e(CPU *c) { /* Unwind@1002d53e */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x74u)); /* add ecx, 0x74 */
    { f_006a3a62(c); return; } /* jmp 0x6a3a62 */
}

void f_006bd549(CPU *c) { /* PTR_006bd549 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x6c2664u); /* mov eax, 0x10032664 */
    { f_006aef44(c); return; } /* jmp 0x6aef44 */
}

void f_006bd553(CPU *c) { /* Unwind@1002d553 */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x006bd55bu); f_00692260(c); /* call 0x692260 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_006bd55d(CPU *c) { /* Unwind@1002d55d */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x006bd565u); f_00692260(c); /* call 0x692260 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_006bd567(CPU *c) { /* PTR_006bd567 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x6c2690u); /* mov eax, 0x10032690 */
    { f_006aef44(c); return; } /* jmp 0x6aef44 */
}

void f_006bd57b(CPU *c) { /* Unwind@1002d57b */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x18] */
    PUSH32(c, 0x006bd583u); f_00692260(c); /* call 0x692260 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_006bd585(CPU *c) { /* PTR_006bd585 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x6c2704u); /* mov eax, 0x10032704 */
    { f_006aef44(c); return; } /* jmp 0x6aef44 */
}
