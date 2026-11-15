#include "recomp.h"

void f_0045a034(CPU *c) { /* PTR_0045a034 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45cc20u); /* mov eax, 0x45cc20 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a03e(CPU *c) { /* Unwind@0045a03e */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    PUSH32(c, 0x0045a049u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a04a(CPU *c) { /* PTR_0045a04a */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45cc44u); /* mov eax, 0x45cc44 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a054(CPU *c) { /* Unwind@0045a054 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    PUSH32(c, 0x0045a05fu); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a060(CPU *c) { /* PTR_0045a060 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45cc68u); /* mov eax, 0x45cc68 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a06a(CPU *c) { /* Unwind@0045a06a */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    PUSH32(c, 0x0045a075u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a076(CPU *c) { /* PTR_0045a076 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45cc8cu); /* mov eax, 0x45cc8c */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a080(CPU *c) { /* Unwind@0045a080 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffd68u)); /* lea ecx, [ebp - 0x298] */
    PUSH32(c, 0x0045a08bu); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a08c(CPU *c) { /* PTR_0045a08c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45ccb0u); /* mov eax, 0x45ccb0 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a096(CPU *c) { /* Unwind@0045a096 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x76du; PUSH32(c, v_); } /* push 0x76d */
    { uint32_t v_ = 0x4631b8u; PUSH32(c, v_); } /* push 0x4631b8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffff88u))); /* mov eax, dword ptr [ebp - 0x78] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0045a0a9u); f_0043b0d9(c); /* call 0x43b0d9 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_0045a0ad(CPU *c) { /* Unwind@0045a0ad */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x79eu; PUSH32(c, v_); } /* push 0x79e */
    { uint32_t v_ = 0x4631e8u; PUSH32(c, v_); } /* push 0x4631e8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffff68u))); /* mov eax, dword ptr [ebp - 0x98] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0045a0c3u); f_0043b0d9(c); /* call 0x43b0d9 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_0045a0c7(CPU *c) { /* PTR_0045a0c7 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45ccdcu); /* mov eax, 0x45ccdc */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a0d1(CPU *c) { /* Unwind@0045a0d1 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffc9cu)); /* lea ecx, [ebp - 0x364] */
    PUSH32(c, 0x0045a0dcu); f_004237a7(c); /* call 0x4237a7 */
    c->esp += 4; return; /* ret  */
}

void f_0045a0dd(CPU *c) { /* Unwind@0045a0dd */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffff7c4u)); /* lea ecx, [ebp - 0x83c] */
    PUSH32(c, 0x0045a0e8u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a0e9(CPU *c) { /* Unwind@0045a0e9 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffff574u)); /* lea ecx, [ebp - 0xa8c] */
    PUSH32(c, 0x0045a0f4u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a0f5(CPU *c) { /* Unwind@0045a0f5 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffff324u)); /* lea ecx, [ebp - 0xcdc] */
    PUSH32(c, 0x0045a100u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a101(CPU *c) { /* Unwind@0045a101 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffff0d4u)); /* lea ecx, [ebp - 0xf2c] */
    PUSH32(c, 0x0045a10cu); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a10d(CPU *c) { /* Unwind@0045a10d */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffee84u)); /* lea ecx, [ebp - 0x117c] */
    PUSH32(c, 0x0045a118u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a119(CPU *c) { /* Unwind@0045a119 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffec34u)); /* lea ecx, [ebp - 0x13cc] */
    PUSH32(c, 0x0045a124u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a125(CPU *c) { /* PTR_0045a125 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45cd38u); /* mov eax, 0x45cd38 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a12f(CPU *c) { /* Unwind@0045a12f */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda0u)); /* lea ecx, [ebp - 0x260] */
    PUSH32(c, 0x0045a13au); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a13b(CPU *c) { /* Unwind@0045a13b */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffb48u)); /* lea ecx, [ebp - 0x4b8] */
    PUSH32(c, 0x0045a146u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a147(CPU *c) { /* PTR_0045a147 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45cd64u); /* mov eax, 0x45cd64 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a151(CPU *c) { /* Unwind@0045a151 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffcb4u)); /* lea ecx, [ebp - 0x34c] */
    PUSH32(c, 0x0045a15cu); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a15d(CPU *c) { /* Unwind@0045a15d */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffff14u)); /* lea ecx, [ebp - 0xec] */
    PUSH32(c, 0x0045a168u); f_00424829(c); /* call 0x424829 */
    c->esp += 4; return; /* ret  */
}

void f_0045a169(CPU *c) { /* Unwind@0045a169 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea ecx, [ebp - 0x2c] */
    PUSH32(c, 0x0045a171u); f_0041ddb0(c); /* call 0x41ddb0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a172(CPU *c) { /* Unwind@0045a172 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffec78u)); /* lea ecx, [ebp - 0x1388] */
    PUSH32(c, 0x0045a17du); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a17e(CPU *c) { /* Unwind@0045a17e */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffea28u)); /* lea ecx, [ebp - 0x15d8] */
    PUSH32(c, 0x0045a189u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a18a(CPU *c) { /* PTR_0045a18a */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45cdd8u); /* mov eax, 0x45cdd8 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a1a0(CPU *c) { /* Unwind@0045a1a0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda0u)); /* lea ecx, [ebp - 0x260] */
    PUSH32(c, 0x0045a1abu); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a1ac(CPU *c) { /* PTR_0045a1ac */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45cdfcu); /* mov eax, 0x45cdfc */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a1c0(CPU *c) { /* Unwind@0045a1c0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    PUSH32(c, 0x0045a1c8u); f_00423570(c); /* call 0x423570 */
    c->esp += 4; return; /* ret  */
}

void f_0045a1c9(CPU *c) { /* PTR_0045a1c9 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45ce20u); /* mov eax, 0x45ce20 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a1d3(CPU *c) { /* Unwind@0045a1d3 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    PUSH32(c, 0x0045a1dbu); f_00423570(c); /* call 0x423570 */
    c->esp += 4; return; /* ret  */
}

void f_0045a1dc(CPU *c) { /* PTR_0045a1dc */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45ce44u); /* mov eax, 0x45ce44 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a1e6(CPU *c) { /* Unwind@0045a1e6 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov ecx, dword ptr [ebp - 0x20] */
    PUSH32(c, 0x0045a1eeu); f_00423570(c); /* call 0x423570 */
    c->esp += 4; return; /* ret  */
}

void f_0045a1ef(CPU *c) { /* Unwind@0045a1ef */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)(uint32_t)0x50u; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, eax, 0x50 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov ecx, dword ptr [ebp - 0x20] */
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->ecx + 0x44u)))); /* add eax, dword ptr [ecx + 0x44] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov edx, dword ptr [ebp - 0x1c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x0045a205u); f_004235f0(c); /* call 0x4235f0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->esp += 4; return; /* ret  */
}

void f_0045a209(CPU *c) { /* PTR_0045a209 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45ce70u); /* mov eax, 0x45ce70 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a213(CPU *c) { /* Unwind@0045a213 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    PUSH32(c, 0x0045a21bu); f_00423570(c); /* call 0x423570 */
    c->esp += 4; return; /* ret  */
}

void f_0045a21c(CPU *c) { /* PTR_0045a21c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45ce94u); /* mov eax, 0x45ce94 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a226(CPU *c) { /* Unwind@0045a226 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x11bu; PUSH32(c, v_); } /* push 0x11b */
    { uint32_t v_ = 0x463da0u; PUSH32(c, v_); } /* push 0x463da0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0045a239u); f_0043b0d9(c); /* call 0x43b0d9 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_0045a23d(CPU *c) { /* PTR_0045a23d */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45ceb8u); /* mov eax, 0x45ceb8 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a247(CPU *c) { /* Unwind@0045a247 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)(uint32_t)0x50u; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, eax, 0x50 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov ecx, dword ptr [ebp - 0x24] */
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->ecx + 0x44u)))); /* add eax, dword ptr [ecx + 0x44] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov edx, dword ptr [ebp - 0x18] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x0045a25du); f_004235f0(c); /* call 0x4235f0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->esp += 4; return; /* ret  */
}

void f_0045a261(CPU *c) { /* PTR_0045a261 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45cedcu); /* mov eax, 0x45cedc */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a26b(CPU *c) { /* Unwind@0045a26b */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)(uint32_t)0x50u; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, eax, 0x50 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov ecx, dword ptr [ebp - 0x1c] */
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->ecx + 0x44u)))); /* add eax, dword ptr [ecx + 0x44] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov edx, dword ptr [ebp - 0x18] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x0045a281u); f_004235f0(c); /* call 0x4235f0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->esp += 4; return; /* ret  */
}

void f_0045a285(CPU *c) { /* PTR_0045a285 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45cf00u); /* mov eax, 0x45cf00 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a28f(CPU *c) { /* Unwind@0045a28f */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x6c4u; PUSH32(c, v_); } /* push 0x6c4 */
    { uint32_t v_ = 0x4643e8u; PUSH32(c, v_); } /* push 0x4643e8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov eax, dword ptr [ebp - 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0045a2a2u); f_0043b0d9(c); /* call 0x43b0d9 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_0045a2a6(CPU *c) { /* Unwind@0045a2a6 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x6cfu; PUSH32(c, v_); } /* push 0x6cf */
    { uint32_t v_ = 0x464418u; PUSH32(c, v_); } /* push 0x464418 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0045a2b9u); f_0043b0d9(c); /* call 0x43b0d9 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_0045a2bd(CPU *c) { /* PTR_0045a2bd */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45cf2cu); /* mov eax, 0x45cf2c */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a2c7(CPU *c) { /* Unwind@0045a2c7 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x7a5u; PUSH32(c, v_); } /* push 0x7a5 */
    { uint32_t v_ = 0x464630u; PUSH32(c, v_); } /* push 0x464630 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0045a2dau); f_0043b0d9(c); /* call 0x43b0d9 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_0045a2de(CPU *c) { /* PTR_0045a2de */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45cf50u); /* mov eax, 0x45cf50 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a2f0(CPU *c) { /* Unwind@0045a2f0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov ecx, dword ptr [ebp - 0x18] */
    PUSH32(c, 0x0045a2f8u); f_00426980(c); /* call 0x426980 */
    c->esp += 4; return; /* ret  */
}

void f_0045a2f9(CPU *c) { /* PTR_0045a2f9 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45cf74u); /* mov eax, 0x45cf74 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a303(CPU *c) { /* Unwind@0045a303 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    PUSH32(c, 0x0045a30eu); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a30f(CPU *c) { /* Unwind@0045a30f */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffb54u)); /* lea ecx, [ebp - 0x4ac] */
    PUSH32(c, 0x0045a31au); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a31b(CPU *c) { /* PTR_0045a31b */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45cfa0u); /* mov eax, 0x45cfa0 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a325(CPU *c) { /* Unwind@0045a325 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffd9cu)); /* lea ecx, [ebp - 0x264] */
    PUSH32(c, 0x0045a330u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a331(CPU *c) { /* Unwind@0045a331 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffb4cu)); /* lea ecx, [ebp - 0x4b4] */
    PUSH32(c, 0x0045a33cu); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a33d(CPU *c) { /* Unwind@0045a33d */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffff8fcu)); /* lea ecx, [ebp - 0x704] */
    PUSH32(c, 0x0045a348u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a349(CPU *c) { /* Unwind@0045a349 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffff6acu)); /* lea ecx, [ebp - 0x954] */
    PUSH32(c, 0x0045a354u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a355(CPU *c) { /* Unwind@0045a355 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffff45cu)); /* lea ecx, [ebp - 0xba4] */
    PUSH32(c, 0x0045a360u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a361(CPU *c) { /* PTR_0045a361 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45cfe4u); /* mov eax, 0x45cfe4 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a36b(CPU *c) { /* Unwind@0045a36b */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    PUSH32(c, 0x0045a376u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a377(CPU *c) { /* PTR_0045a377 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d008u); /* mov eax, 0x45d008 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a381(CPU *c) { /* Unwind@0045a381 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffd98u)); /* lea ecx, [ebp - 0x268] */
    PUSH32(c, 0x0045a38cu); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a38d(CPU *c) { /* Unwind@0045a38d */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffb44u)); /* lea ecx, [ebp - 0x4bc] */
    PUSH32(c, 0x0045a398u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a399(CPU *c) { /* Unwind@0045a399 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffff8f4u)); /* lea ecx, [ebp - 0x70c] */
    PUSH32(c, 0x0045a3a4u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a3a5(CPU *c) { /* Unwind@0045a3a5 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffff6a0u)); /* lea ecx, [ebp - 0x960] */
    PUSH32(c, 0x0045a3b0u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a3b1(CPU *c) { /* Unwind@0045a3b1 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffff450u)); /* lea ecx, [ebp - 0xbb0] */
    PUSH32(c, 0x0045a3bcu); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a3bd(CPU *c) { /* PTR_0045a3bd */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d04cu); /* mov eax, 0x45d04c */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a3c7(CPU *c) { /* Unwind@0045a3c7 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov ecx, dword ptr [ebp - 0x18] */
    PUSH32(c, 0x0045a3cfu); f_00426af0(c); /* call 0x426af0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a3d0(CPU *c) { /* PTR_0045a3d0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d070u); /* mov eax, 0x45d070 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a3da(CPU *c) { /* Unwind@0045a3da */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    PUSH32(c, 0x0045a3e5u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a3e6(CPU *c) { /* Unwind@0045a3e6 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffb54u)); /* lea ecx, [ebp - 0x4ac] */
    PUSH32(c, 0x0045a3f1u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a3f2(CPU *c) { /* PTR_0045a3f2 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d09cu); /* mov eax, 0x45d09c */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a3fc(CPU *c) { /* Unwind@0045a3fc */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffd94u)); /* lea ecx, [ebp - 0x26c] */
    PUSH32(c, 0x0045a407u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a408(CPU *c) { /* Unwind@0045a408 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffb44u)); /* lea ecx, [ebp - 0x4bc] */
    PUSH32(c, 0x0045a413u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a414(CPU *c) { /* Unwind@0045a414 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffff8f4u)); /* lea ecx, [ebp - 0x70c] */
    PUSH32(c, 0x0045a41fu); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a420(CPU *c) { /* Unwind@0045a420 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffff6a4u)); /* lea ecx, [ebp - 0x95c] */
    PUSH32(c, 0x0045a42bu); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a42c(CPU *c) { /* Unwind@0045a42c */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffff450u)); /* lea ecx, [ebp - 0xbb0] */
    PUSH32(c, 0x0045a437u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a438(CPU *c) { /* Unwind@0045a438 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffff200u)); /* lea ecx, [ebp - 0xe00] */
    PUSH32(c, 0x0045a443u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a444(CPU *c) { /* Unwind@0045a444 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffefb0u)); /* lea ecx, [ebp - 0x1050] */
    PUSH32(c, 0x0045a44fu); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a450(CPU *c) { /* Unwind@0045a450 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffed5cu)); /* lea ecx, [ebp - 0x12a4] */
    PUSH32(c, 0x0045a45bu); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a45c(CPU *c) { /* Unwind@0045a45c */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffeb0cu)); /* lea ecx, [ebp - 0x14f4] */
    PUSH32(c, 0x0045a467u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a468(CPU *c) { /* Unwind@0045a468 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffe8bcu)); /* lea ecx, [ebp - 0x1744] */
    PUSH32(c, 0x0045a473u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a474(CPU *c) { /* PTR_0045a474 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d108u); /* mov eax, 0x45d108 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a47e(CPU *c) { /* Unwind@0045a47e */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda0u)); /* lea ecx, [ebp - 0x260] */
    PUSH32(c, 0x0045a489u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a48a(CPU *c) { /* Unwind@0045a48a */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffb50u)); /* lea ecx, [ebp - 0x4b0] */
    PUSH32(c, 0x0045a495u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a496(CPU *c) { /* PTR_0045a496 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d134u); /* mov eax, 0x45d134 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a4a0(CPU *c) { /* Unwind@0045a4a0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    PUSH32(c, 0x0045a4abu); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a4ac(CPU *c) { /* PTR_0045a4ac */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d158u); /* mov eax, 0x45d158 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a4b6(CPU *c) { /* Unwind@0045a4b6 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    PUSH32(c, 0x0045a4c1u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a4c2(CPU *c) { /* PTR_0045a4c2 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d17cu); /* mov eax, 0x45d17c */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a4cc(CPU *c) { /* Unwind@0045a4cc */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    PUSH32(c, 0x0045a4d7u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a4d8(CPU *c) { /* PTR_0045a4d8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d1a0u); /* mov eax, 0x45d1a0 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a4e2(CPU *c) { /* Unwind@0045a4e2 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    PUSH32(c, 0x0045a4edu); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a4ee(CPU *c) { /* PTR_0045a4ee */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d1c4u); /* mov eax, 0x45d1c4 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a4f8(CPU *c) { /* Unwind@0045a4f8 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    PUSH32(c, 0x0045a503u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a504(CPU *c) { /* PTR_0045a504 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d1e8u); /* mov eax, 0x45d1e8 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a50e(CPU *c) { /* Unwind@0045a50e */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    PUSH32(c, 0x0045a519u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a51a(CPU *c) { /* PTR_0045a51a */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d20cu); /* mov eax, 0x45d20c */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a524(CPU *c) { /* Unwind@0045a524 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    PUSH32(c, 0x0045a52fu); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a530(CPU *c) { /* PTR_0045a530 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d230u); /* mov eax, 0x45d230 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a53a(CPU *c) { /* Unwind@0045a53a */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda0u)); /* lea ecx, [ebp - 0x260] */
    PUSH32(c, 0x0045a545u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a546(CPU *c) { /* Unwind@0045a546 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffb50u)); /* lea ecx, [ebp - 0x4b0] */
    PUSH32(c, 0x0045a551u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a552(CPU *c) { /* Unwind@0045a552 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffff900u)); /* lea ecx, [ebp - 0x700] */
    PUSH32(c, 0x0045a55du); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a55e(CPU *c) { /* PTR_0045a55e */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d264u); /* mov eax, 0x45d264 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a568(CPU *c) { /* Unwind@0045a568 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda0u)); /* lea ecx, [ebp - 0x260] */
    PUSH32(c, 0x0045a573u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a574(CPU *c) { /* Unwind@0045a574 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffb50u)); /* lea ecx, [ebp - 0x4b0] */
    PUSH32(c, 0x0045a57fu); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a580(CPU *c) { /* Unwind@0045a580 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffff900u)); /* lea ecx, [ebp - 0x700] */
    PUSH32(c, 0x0045a58bu); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a58c(CPU *c) { /* Unwind@0045a58c */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffff6b0u)); /* lea ecx, [ebp - 0x950] */
    PUSH32(c, 0x0045a597u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a598(CPU *c) { /* PTR_0045a598 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d2a0u); /* mov eax, 0x45d2a0 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a5a2(CPU *c) { /* Unwind@0045a5a2 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda0u)); /* lea ecx, [ebp - 0x260] */
    PUSH32(c, 0x0045a5adu); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a5ae(CPU *c) { /* Unwind@0045a5ae */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffb50u)); /* lea ecx, [ebp - 0x4b0] */
    PUSH32(c, 0x0045a5b9u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a5ba(CPU *c) { /* Unwind@0045a5ba */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffff900u)); /* lea ecx, [ebp - 0x700] */
    PUSH32(c, 0x0045a5c5u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a5c6(CPU *c) { /* Unwind@0045a5c6 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffff6b0u)); /* lea ecx, [ebp - 0x950] */
    PUSH32(c, 0x0045a5d1u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a5d2(CPU *c) { /* PTR_0045a5d2 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d2dcu); /* mov eax, 0x45d2dc */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a5e0(CPU *c) { /* Unwind@0045a5e0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffff9cu)); /* lea ecx, [ebp - 0x64] */
    PUSH32(c, 0x0045a5e8u); f_0041e556(c); /* call 0x41e556 */
    c->esp += 4; return; /* ret  */
}

void f_0045a5e9(CPU *c) { /* Unwind@0045a5e9 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffff24u)); /* lea ecx, [ebp - 0xdc] */
    PUSH32(c, 0x0045a5f4u); f_0041e556(c); /* call 0x41e556 */
    c->esp += 4; return; /* ret  */
}

void f_0045a5f5(CPU *c) { /* PTR_0045a5f5 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d308u); /* mov eax, 0x45d308 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a5ff(CPU *c) { /* Unwind@0045a5ff */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffff9cu)); /* lea ecx, [ebp - 0x64] */
    PUSH32(c, 0x0045a607u); f_0041e556(c); /* call 0x41e556 */
    c->esp += 4; return; /* ret  */
}

void f_0045a608(CPU *c) { /* PTR_0045a608 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d32cu); /* mov eax, 0x45d32c */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a612(CPU *c) { /* Unwind@0045a612 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffff9cu)); /* lea ecx, [ebp - 0x64] */
    PUSH32(c, 0x0045a61au); f_0041e556(c); /* call 0x41e556 */
    c->esp += 4; return; /* ret  */
}

void f_0045a61b(CPU *c) { /* PTR_0045a61b */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d350u); /* mov eax, 0x45d350 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a625(CPU *c) { /* Unwind@0045a625 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffff9cu)); /* lea ecx, [ebp - 0x64] */
    PUSH32(c, 0x0045a62du); f_0041e556(c); /* call 0x41e556 */
    c->esp += 4; return; /* ret  */
}

void f_0045a62e(CPU *c) { /* PTR_0045a62e */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d374u); /* mov eax, 0x45d374 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a638(CPU *c) { /* Unwind@0045a638 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffff9cu)); /* lea ecx, [ebp - 0x64] */
    PUSH32(c, 0x0045a640u); f_0041e556(c); /* call 0x41e556 */
    c->esp += 4; return; /* ret  */
}

void f_0045a641(CPU *c) { /* PTR_0045a641 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d398u); /* mov eax, 0x45d398 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a64b(CPU *c) { /* Unwind@0045a64b */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffff9cu)); /* lea ecx, [ebp - 0x64] */
    PUSH32(c, 0x0045a653u); f_0041e556(c); /* call 0x41e556 */
    c->esp += 4; return; /* ret  */
}

void f_0045a654(CPU *c) { /* PTR_0045a654 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d3bcu); /* mov eax, 0x45d3bc */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a65e(CPU *c) { /* Unwind@0045a65e */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffffa4u)); /* lea ecx, [ebp - 0x5c] */
    PUSH32(c, 0x0045a666u); f_0041e556(c); /* call 0x41e556 */
    c->esp += 4; return; /* ret  */
}

void f_0045a667(CPU *c) { /* Unwind@0045a667 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffec4u)); /* lea ecx, [ebp - 0x13c] */
    PUSH32(c, 0x0045a672u); f_0041e556(c); /* call 0x41e556 */
    c->esp += 4; return; /* ret  */
}

void f_0045a673(CPU *c) { /* Unwind@0045a673 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffff1cu)); /* lea ecx, [ebp - 0xe4] */
    PUSH32(c, 0x0045a67eu); f_0041e556(c); /* call 0x41e556 */
    c->esp += 4; return; /* ret  */
}

void f_0045a67f(CPU *c) { /* PTR_0045a67f */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d3f0u); /* mov eax, 0x45d3f0 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a690(CPU *c) { /* Unwind@0045a690 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov ecx, dword ptr [ebp - 0x14] */
    PUSH32(c, 0x0045a698u); f_0042ba10(c); /* call 0x42ba10 */
    c->esp += 4; return; /* ret  */
}

void f_0045a699(CPU *c) { /* PTR_0045a699 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d414u); /* mov eax, 0x45d414 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a6a3(CPU *c) { /* Unwind@0045a6a3 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    PUSH32(c, 0x0045a6abu); f_0042ba10(c); /* call 0x42ba10 */
    c->esp += 4; return; /* ret  */
}

void f_0045a6ac(CPU *c) { /* PTR_0045a6ac */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d438u); /* mov eax, 0x45d438 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a6b6(CPU *c) { /* Unwind@0045a6b6 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x137u; PUSH32(c, v_); } /* push 0x137 */
    { uint32_t v_ = 0x466334u; PUSH32(c, v_); } /* push 0x466334 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0045a6c9u); f_0043b0d9(c); /* call 0x43b0d9 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_0045a6cd(CPU *c) { /* Unwind@0045a6cd */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffd94u)); /* lea ecx, [ebp - 0x26c] */
    PUSH32(c, 0x0045a6d8u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a6d9(CPU *c) { /* Unwind@0045a6d9 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x142u; PUSH32(c, v_); } /* push 0x142 */
    { uint32_t v_ = 0x46636cu; PUSH32(c, v_); } /* push 0x46636c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffd8cu))); /* mov eax, dword ptr [ebp - 0x274] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0045a6efu); f_0043b0d9(c); /* call 0x43b0d9 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_0045a6f3(CPU *c) { /* Unwind@0045a6f3 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffb3cu)); /* lea ecx, [ebp - 0x4c4] */
    PUSH32(c, 0x0045a6feu); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a6ff(CPU *c) { /* Unwind@0045a6ff */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x153u; PUSH32(c, v_); } /* push 0x153 */
    { uint32_t v_ = 0x4663a4u; PUSH32(c, v_); } /* push 0x4663a4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffb2cu))); /* mov eax, dword ptr [ebp - 0x4d4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0045a715u); f_0043b0d9(c); /* call 0x43b0d9 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_0045a719(CPU *c) { /* Unwind@0045a719 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffff8dcu)); /* lea ecx, [ebp - 0x724] */
    PUSH32(c, 0x0045a724u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a725(CPU *c) { /* PTR_0045a725 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d484u); /* mov eax, 0x45d484 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a72f(CPU *c) { /* Unwind@0045a72f */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda0u)); /* lea ecx, [ebp - 0x260] */
    PUSH32(c, 0x0045a73au); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a73b(CPU *c) { /* Unwind@0045a73b */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffb48u)); /* lea ecx, [ebp - 0x4b8] */
    PUSH32(c, 0x0045a746u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a747(CPU *c) { /* PTR_0045a747 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d4b0u); /* mov eax, 0x45d4b0 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a751(CPU *c) { /* Unwind@0045a751 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    PUSH32(c, 0x0045a759u); f_0042bd00(c); /* call 0x42bd00 */
    c->esp += 4; return; /* ret  */
}

void f_0045a75a(CPU *c) { /* PTR_0045a75a */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d4d4u); /* mov eax, 0x45d4d4 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a770(CPU *c) { /* Unwind@0045a770 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda0u)); /* lea ecx, [ebp - 0x260] */
    PUSH32(c, 0x0045a77bu); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a77c(CPU *c) { /* Unwind@0045a77c */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffb4cu)); /* lea ecx, [ebp - 0x4b4] */
    PUSH32(c, 0x0045a787u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a788(CPU *c) { /* PTR_0045a788 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d500u); /* mov eax, 0x45d500 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a7a0(CPU *c) { /* Unwind@0045a7a0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffd9cu)); /* lea ecx, [ebp - 0x264] */
    PUSH32(c, 0x0045a7abu); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a7ac(CPU *c) { /* PTR_0045a7ac */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d524u); /* mov eax, 0x45d524 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a7b6(CPU *c) { /* Unwind@0045a7b6 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffd9cu)); /* lea ecx, [ebp - 0x264] */
    PUSH32(c, 0x0045a7c1u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a7c2(CPU *c) { /* PTR_0045a7c2 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d548u); /* mov eax, 0x45d548 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a7cc(CPU *c) { /* Unwind@0045a7cc */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffd9cu)); /* lea ecx, [ebp - 0x264] */
    PUSH32(c, 0x0045a7d7u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a7d8(CPU *c) { /* PTR_0045a7d8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d56cu); /* mov eax, 0x45d56c */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a7e2(CPU *c) { /* Unwind@0045a7e2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xb8u; PUSH32(c, v_); } /* push 0xb8 */
    { uint32_t v_ = 0x466904u; PUSH32(c, v_); } /* push 0x466904 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov eax, dword ptr [ebp - 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0045a7f5u); f_0043b0d9(c); /* call 0x43b0d9 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_0045a7f9(CPU *c) { /* PTR_0045a7f9 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d590u); /* mov eax, 0x45d590 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a803(CPU *c) { /* Unwind@0045a803 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov ecx, dword ptr [ebp - 0x20] */
    PUSH32(c, 0x0045a80bu); f_0042bd00(c); /* call 0x42bd00 */
    c->esp += 4; return; /* ret  */
}

void f_0045a80c(CPU *c) { /* PTR_0045a80c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d5b4u); /* mov eax, 0x45d5b4 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a816(CPU *c) { /* Unwind@0045a816 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x192u; PUSH32(c, v_); } /* push 0x192 */
    { uint32_t v_ = 0x4669e0u; PUSH32(c, v_); } /* push 0x4669e0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffbcu))); /* mov eax, dword ptr [ebp - 0x44] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0045a829u); f_0043b0d9(c); /* call 0x43b0d9 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_0045a82d(CPU *c) { /* Unwind@0045a82d */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1cau; PUSH32(c, v_); } /* push 0x1ca */
    { uint32_t v_ = 0x466a0cu; PUSH32(c, v_); } /* push 0x466a0c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffb4u))); /* mov eax, dword ptr [ebp - 0x4c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0045a840u); f_0043b0d9(c); /* call 0x43b0d9 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_0045a844(CPU *c) { /* PTR_0045a844 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d5e0u); /* mov eax, 0x45d5e0 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a84e(CPU *c) { /* Unwind@0045a84e */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffd88u)); /* lea ecx, [ebp - 0x278] */
    PUSH32(c, 0x0045a859u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a85a(CPU *c) { /* Unwind@0045a85a */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffb38u)); /* lea ecx, [ebp - 0x4c8] */
    PUSH32(c, 0x0045a865u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a866(CPU *c) { /* Unwind@0045a866 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffff8e8u)); /* lea ecx, [ebp - 0x718] */
    PUSH32(c, 0x0045a871u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a872(CPU *c) { /* Unwind@0045a872 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffff698u)); /* lea ecx, [ebp - 0x968] */
    PUSH32(c, 0x0045a87du); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a87e(CPU *c) { /* Unwind@0045a87e */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffff448u)); /* lea ecx, [ebp - 0xbb8] */
    PUSH32(c, 0x0045a889u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a88a(CPU *c) { /* Unwind@0045a88a */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffff1f8u)); /* lea ecx, [ebp - 0xe08] */
    PUSH32(c, 0x0045a895u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a896(CPU *c) { /* Unwind@0045a896 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffefa8u)); /* lea ecx, [ebp - 0x1058] */
    PUSH32(c, 0x0045a8a1u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a8a2(CPU *c) { /* Unwind@0045a8a2 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffed58u)); /* lea ecx, [ebp - 0x12a8] */
    PUSH32(c, 0x0045a8adu); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a8ae(CPU *c) { /* Unwind@0045a8ae */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffeb08u)); /* lea ecx, [ebp - 0x14f8] */
    PUSH32(c, 0x0045a8b9u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a8ba(CPU *c) { /* Unwind@0045a8ba */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffe8b8u)); /* lea ecx, [ebp - 0x1748] */
    PUSH32(c, 0x0045a8c5u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a8c6(CPU *c) { /* Unwind@0045a8c6 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffe668u)); /* lea ecx, [ebp - 0x1998] */
    PUSH32(c, 0x0045a8d1u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a8d2(CPU *c) { /* Unwind@0045a8d2 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffe418u)); /* lea ecx, [ebp - 0x1be8] */
    PUSH32(c, 0x0045a8ddu); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a8de(CPU *c) { /* Unwind@0045a8de */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffe1c8u)); /* lea ecx, [ebp - 0x1e38] */
    PUSH32(c, 0x0045a8e9u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a8ea(CPU *c) { /* Unwind@0045a8ea */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffdf74u)); /* lea ecx, [ebp - 0x208c] */
    PUSH32(c, 0x0045a8f5u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a8f6(CPU *c) { /* PTR_0045a8f6 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d66cu); /* mov eax, 0x45d66c */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a900(CPU *c) { /* Unwind@0045a900 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x2d0u; PUSH32(c, v_); } /* push 0x2d0 */
    { uint32_t v_ = 0x466f4cu; PUSH32(c, v_); } /* push 0x466f4c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov eax, dword ptr [ebp - 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0045a913u); f_0043b0d9(c); /* call 0x43b0d9 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_0045a917(CPU *c) { /* PTR_0045a917 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d690u); /* mov eax, 0x45d690 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a921(CPU *c) { /* Unwind@0045a921 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffd98u)); /* lea ecx, [ebp - 0x268] */
    PUSH32(c, 0x0045a92cu); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a92d(CPU *c) { /* Unwind@0045a92d */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffb48u)); /* lea ecx, [ebp - 0x4b8] */
    PUSH32(c, 0x0045a938u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a939(CPU *c) { /* Unwind@0045a939 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffff8f8u)); /* lea ecx, [ebp - 0x708] */
    PUSH32(c, 0x0045a944u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a945(CPU *c) { /* Unwind@0045a945 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffff6a8u)); /* lea ecx, [ebp - 0x958] */
    PUSH32(c, 0x0045a950u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a951(CPU *c) { /* PTR_0045a951 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d6ccu); /* mov eax, 0x45d6cc */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a95b(CPU *c) { /* Unwind@0045a95b */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffd90u)); /* lea ecx, [ebp - 0x270] */
    PUSH32(c, 0x0045a966u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a967(CPU *c) { /* Unwind@0045a967 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffb40u)); /* lea ecx, [ebp - 0x4c0] */
    PUSH32(c, 0x0045a972u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a973(CPU *c) { /* PTR_0045a973 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d6f8u); /* mov eax, 0x45d6f8 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a97d(CPU *c) { /* Unwind@0045a97d */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffd9cu)); /* lea ecx, [ebp - 0x264] */
    PUSH32(c, 0x0045a988u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a989(CPU *c) { /* Unwind@0045a989 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffb4cu)); /* lea ecx, [ebp - 0x4b4] */
    PUSH32(c, 0x0045a994u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a995(CPU *c) { /* PTR_0045a995 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d724u); /* mov eax, 0x45d724 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a99f(CPU *c) { /* Unwind@0045a99f */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffd9cu)); /* lea ecx, [ebp - 0x264] */
    PUSH32(c, 0x0045a9aau); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a9ab(CPU *c) { /* Unwind@0045a9ab */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffb4cu)); /* lea ecx, [ebp - 0x4b4] */
    PUSH32(c, 0x0045a9b6u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045a9b7(CPU *c) { /* PTR_0045a9b7 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d750u); /* mov eax, 0x45d750 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045a9d0(CPU *c) { /* Unwind@0045a9d0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffd1cu)); /* lea ecx, [ebp - 0x2e4] */
    PUSH32(c, 0x0045a9dbu); f_0041e556(c); /* call 0x41e556 */
    c->esp += 4; return; /* ret  */
}

void f_0045a9dc(CPU *c) { /* Unwind@0045a9dc */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffcb4u)); /* lea ecx, [ebp - 0x34c] */
    PUSH32(c, 0x0045a9e7u); f_00412130(c); /* call 0x412130 */
    c->esp += 4; return; /* ret  */
}

void f_0045a9e8(CPU *c) { /* Unwind@0045a9e8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x574u; PUSH32(c, v_); } /* push 0x574 */
    { uint32_t v_ = 0x468fa4u; PUSH32(c, v_); } /* push 0x468fa4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffb5cu))); /* mov eax, dword ptr [ebp - 0x4a4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0045a9feu); f_0043b0d9(c); /* call 0x43b0d9 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_0045aa02(CPU *c) { /* Unwind@0045aa02 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x579u; PUSH32(c, v_); } /* push 0x579 */
    { uint32_t v_ = 0x468fe0u; PUSH32(c, v_); } /* push 0x468fe0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffb54u))); /* mov eax, dword ptr [ebp - 0x4ac] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0045aa18u); f_0043b0d9(c); /* call 0x43b0d9 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_0045aa1c(CPU *c) { /* PTR_0045aa1c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d78cu); /* mov eax, 0x45d78c */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045aa30(CPU *c) { /* Unwind@0045aa30 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x28u; PUSH32(c, v_); } /* push 0x28 */
    { uint32_t v_ = 0x469148u; PUSH32(c, v_); } /* push 0x469148 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov eax, dword ptr [ebp - 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0045aa40u); f_0043b0d9(c); /* call 0x43b0d9 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_0045aa44(CPU *c) { /* PTR_0045aa44 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d7b0u); /* mov eax, 0x45d7b0 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045aa4e(CPU *c) { /* Unwind@0045aa4e */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x3du; PUSH32(c, v_); } /* push 0x3d */
    { uint32_t v_ = 0x469224u; PUSH32(c, v_); } /* push 0x469224 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0045aa5eu); f_0043b0d9(c); /* call 0x43b0d9 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_0045aa62(CPU *c) { /* Unwind@0045aa62 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffd94u)); /* lea ecx, [ebp - 0x26c] */
    PUSH32(c, 0x0045aa6du); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045aa6e(CPU *c) { /* PTR_0045aa6e */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d7dcu); /* mov eax, 0x45d7dc */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045aa78(CPU *c) { /* Unwind@0045aa78 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x101u; PUSH32(c, v_); } /* push 0x101 */
    { uint32_t v_ = 0x469314u; PUSH32(c, v_); } /* push 0x469314 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0045aa8bu); f_0043b0d9(c); /* call 0x43b0d9 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_0045aa8f(CPU *c) { /* Unwind@0045aa8f */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x103u; PUSH32(c, v_); } /* push 0x103 */
    { uint32_t v_ = 0x469344u; PUSH32(c, v_); } /* push 0x469344 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0045aaa2u); f_0043b0d9(c); /* call 0x43b0d9 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_0045aaa6(CPU *c) { /* PTR_0045aaa6 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d808u); /* mov eax, 0x45d808 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045aab0(CPU *c) { /* Unwind@0045aab0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    PUSH32(c, 0x0045aab8u); f_004391e0(c); /* call 0x4391e0 */
    c->esp += 4; return; /* ret  */
}

void f_0045aab9(CPU *c) { /* PTR_0045aab9 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d82cu); /* mov eax, 0x45d82c */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045aad0(CPU *c) { /* Unwind@0045aad0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    PUSH32(c, 0x0045aad8u); f_004391e0(c); /* call 0x4391e0 */
    c->esp += 4; return; /* ret  */
}

void f_0045aad9(CPU *c) { /* PTR_0045aad9 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d850u); /* mov eax, 0x45d850 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045aaf0(CPU *c) { /* Unwind@0045aaf0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    PUSH32(c, 0x0045aafbu); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045aafc(CPU *c) { /* Unwind@0045aafc */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffb54u)); /* lea ecx, [ebp - 0x4ac] */
    PUSH32(c, 0x0045ab07u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045ab08(CPU *c) { /* Unwind@0045ab08 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffff904u)); /* lea ecx, [ebp - 0x6fc] */
    PUSH32(c, 0x0045ab13u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045ab14(CPU *c) { /* Unwind@0045ab14 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x30u; PUSH32(c, v_); } /* push 0x30 */
    { uint32_t v_ = 0x46958cu; PUSH32(c, v_); } /* push 0x46958c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffff8fcu))); /* mov eax, dword ptr [ebp - 0x704] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0045ab27u); f_0043b0d9(c); /* call 0x43b0d9 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_0045ab2b(CPU *c) { /* Unwind@0045ab2b */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffff6acu)); /* lea ecx, [ebp - 0x954] */
    PUSH32(c, 0x0045ab36u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045ab37(CPU *c) { /* PTR_0045ab37 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d894u); /* mov eax, 0x45d894 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045ab41(CPU *c) { /* Unwind@0045ab41 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x4du; PUSH32(c, v_); } /* push 0x4d */
    { uint32_t v_ = 0x46965cu; PUSH32(c, v_); } /* push 0x46965c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov eax, dword ptr [ebp - 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0045ab51u); f_0043b0d9(c); /* call 0x43b0d9 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_0045ab55(CPU *c) { /* Unwind@0045ab55 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffd98u)); /* lea ecx, [ebp - 0x268] */
    PUSH32(c, 0x0045ab60u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045ab61(CPU *c) { /* PTR_0045ab61 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d8c0u); /* mov eax, 0x45d8c0 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045ab6b(CPU *c) { /* Unwind@0045ab6b */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda0u)); /* lea ecx, [ebp - 0x260] */
    PUSH32(c, 0x0045ab76u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045ab77(CPU *c) { /* Unwind@0045ab77 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffb50u)); /* lea ecx, [ebp - 0x4b0] */
    PUSH32(c, 0x0045ab82u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045ab83(CPU *c) { /* Unwind@0045ab83 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffff8f8u)); /* lea ecx, [ebp - 0x708] */
    PUSH32(c, 0x0045ab8eu); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045ab8f(CPU *c) { /* PTR_0045ab8f */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d8f4u); /* mov eax, 0x45d8f4 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045ab99(CPU *c) { /* Unwind@0045ab99 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda0u)); /* lea ecx, [ebp - 0x260] */
    PUSH32(c, 0x0045aba4u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045aba5(CPU *c) { /* PTR_0045aba5 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d918u); /* mov eax, 0x45d918 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045abaf(CPU *c) { /* Unwind@0045abaf */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda0u)); /* lea ecx, [ebp - 0x260] */
    PUSH32(c, 0x0045abbau); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045abbb(CPU *c) { /* PTR_0045abbb */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d93cu); /* mov eax, 0x45d93c */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045abc5(CPU *c) { /* Unwind@0045abc5 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    PUSH32(c, 0x0045abd0u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045abd1(CPU *c) { /* PTR_0045abd1 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d960u); /* mov eax, 0x45d960 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045abdb(CPU *c) { /* Unwind@0045abdb */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    PUSH32(c, 0x0045abe6u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045abe7(CPU *c) { /* Unwind@0045abe7 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffb54u)); /* lea ecx, [ebp - 0x4ac] */
    PUSH32(c, 0x0045abf2u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045abf3(CPU *c) { /* PTR_0045abf3 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d98cu); /* mov eax, 0x45d98c */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045ac00(CPU *c) { /* PTR_0045ac00 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45d9dcu); /* mov eax, 0x45d9dc */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045ac10(CPU *c) { /* Unwind@0045ac10 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov eax, dword ptr [ebp - 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0045ac19u); f_0043b0c6(c); /* call 0x43b0c6 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_0045ac1b(CPU *c) { /* PTR_0045ac1b */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45da10u); /* mov eax, 0x45da10 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045ac30(CPU *c) { /* Unwind@0045ac30 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov ecx, dword ptr [ebp - 0x14] */
    PUSH32(c, 0x0045ac38u); f_0043e7a0(c); /* call 0x43e7a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045ac39(CPU *c) { /* Unwind@0045ac39 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov ecx, dword ptr [ebp - 0x14] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x128u)); /* add ecx, 0x128 */
    PUSH32(c, 0x0045ac47u); f_0043c981(c); /* call 0x43c981 */
    c->esp += 4; return; /* ret  */
}

void f_0045ac48(CPU *c) { /* PTR_0045ac48 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45da3cu); /* mov eax, 0x45da3c */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045ac52(CPU *c) { /* Unwind@0045ac52 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    PUSH32(c, 0x0045ac5au); f_0043e7a0(c); /* call 0x43e7a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045ac5b(CPU *c) { /* Unwind@0045ac5b */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x128u)); /* add ecx, 0x128 */
    PUSH32(c, 0x0045ac69u); f_0043c981(c); /* call 0x43c981 */
    c->esp += 4; return; /* ret  */
}

void f_0045ac6a(CPU *c) { /* Unwind@0045ac6a */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x134u)); /* add ecx, 0x134 */
    PUSH32(c, 0x0045ac78u); f_0043b98f(c); /* call 0x43b98f */
    c->esp += 4; return; /* ret  */
}

void f_0045ac79(CPU *c) { /* PTR_0045ac79 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45da70u); /* mov eax, 0x45da70 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045ac83(CPU *c) { /* Unwind@0045ac83 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffd98u)); /* lea ecx, [ebp - 0x268] */
    PUSH32(c, 0x0045ac8eu); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045ac8f(CPU *c) { /* PTR_0045ac8f */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45da94u); /* mov eax, 0x45da94 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045ac99(CPU *c) { /* Unwind@0045ac99 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffd70u)); /* lea ecx, [ebp - 0x290] */
    PUSH32(c, 0x0045aca4u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045aca5(CPU *c) { /* Unwind@0045aca5 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffb20u)); /* lea ecx, [ebp - 0x4e0] */
    PUSH32(c, 0x0045acb0u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045acb1(CPU *c) { /* PTR_0045acb1 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45dac0u); /* mov eax, 0x45dac0 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045acc5(CPU *c) { /* Unwind@0045acc5 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd0u))); /* mov eax, dword ptr [ebp - 0x30] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0045acceu); f_0043b0c6(c); /* call 0x43b0c6 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_0045acd0(CPU *c) { /* PTR_0045acd0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45db68u); /* mov eax, 0x45db68 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045ace0(CPU *c) { /* Unwind@0045ace0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffd94u)); /* lea ecx, [ebp - 0x26c] */
    PUSH32(c, 0x0045acebu); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045acec(CPU *c) { /* Unwind@0045acec */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffb40u)); /* lea ecx, [ebp - 0x4c0] */
    PUSH32(c, 0x0045acf7u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045acf8(CPU *c) { /* PTR_0045acf8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45db94u); /* mov eax, 0x45db94 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045ad02(CPU *c) { /* Unwind@0045ad02 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    PUSH32(c, 0x0045ad0du); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045ad0e(CPU *c) { /* Unwind@0045ad0e */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffb50u)); /* lea ecx, [ebp - 0x4b0] */
    PUSH32(c, 0x0045ad19u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045ad1a(CPU *c) { /* PTR_0045ad1a */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45dbc0u); /* mov eax, 0x45dbc0 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045ad30(CPU *c) { /* Unwind@0045ad30 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x5bu; PUSH32(c, v_); } /* push 0x5b */
    { uint32_t v_ = 0x46a93cu; PUSH32(c, v_); } /* push 0x46a93c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0045ad40u); f_0043b0d9(c); /* call 0x43b0d9 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_0045ad44(CPU *c) { /* Unwind@0045ad44 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x7du; PUSH32(c, v_); } /* push 0x7d */
    { uint32_t v_ = 0x46a970u; PUSH32(c, v_); } /* push 0x46a970 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd0u))); /* mov eax, dword ptr [ebp - 0x30] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0045ad54u); f_0043b0d9(c); /* call 0x43b0d9 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_0045ad58(CPU *c) { /* PTR_0045ad58 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45dbecu); /* mov eax, 0x45dbec */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045ad70(CPU *c) { /* Unwind@0045ad70 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x10u)); /* add ecx, 0x10 */
    PUSH32(c, 0x0045ad7bu); f_00440740(c); /* call 0x440740 */
    c->esp += 4; return; /* ret  */
}

void f_0045ad7c(CPU *c) { /* PTR_0045ad7c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45dc10u); /* mov eax, 0x45dc10 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045ad90(CPU *c) { /* Unwind@0045ad90 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffebcu))); /* mov ecx, dword ptr [ebp - 0x144] */
    PUSH32(c, 0x0045ad9bu); f_0044ac84(c); /* call 0x44ac84 */
    c->esp += 4; return; /* ret  */
}

void f_0045ad9c(CPU *c) { /* PTR_0045ad9c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45dc34u); /* mov eax, 0x45dc34 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045ada6(CPU *c) { /* Unwind@0045ada6 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov ecx, dword ptr [ebp - 0x18] */
    PUSH32(c, 0x0045adaeu); f_0044ac84(c); /* call 0x44ac84 */
    c->esp += 4; return; /* ret  */
}

void f_0045adaf(CPU *c) { /* PTR_0045adaf */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45dc58u); /* mov eax, 0x45dc58 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045adc0(CPU *c) { /* Unwind@0045adc0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x370u)); /* add ecx, 0x370 */
    PUSH32(c, 0x0045adceu); f_00440b85(c); /* call 0x440b85 */
    c->esp += 4; return; /* ret  */
}

void f_0045adcf(CPU *c) { /* PTR_0045adcf */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45dc7cu); /* mov eax, 0x45dc7c */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045add9(CPU *c) { /* Unwind@0045add9 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x370u)); /* add ecx, 0x370 */
    PUSH32(c, 0x0045ade7u); f_00440b85(c); /* call 0x440b85 */
    c->esp += 4; return; /* ret  */
}

void f_0045ade8(CPU *c) { /* PTR_0045ade8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45dca0u); /* mov eax, 0x45dca0 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045adf2(CPU *c) { /* Unwind@0045adf2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1d8u; PUSH32(c, v_); } /* push 0x1d8 */
    { uint32_t v_ = 0x46aea0u; PUSH32(c, v_); } /* push 0x46aea0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffacu))); /* mov eax, dword ptr [ebp - 0x54] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0045ae05u); f_0043b0d9(c); /* call 0x43b0d9 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_0045ae09(CPU *c) { /* Unwind@0045ae09 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1e0u; PUSH32(c, v_); } /* push 0x1e0 */
    { uint32_t v_ = 0x46aed0u; PUSH32(c, v_); } /* push 0x46aed0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffff9cu))); /* mov eax, dword ptr [ebp - 0x64] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0045ae1cu); f_0043b0d9(c); /* call 0x43b0d9 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_0045ae20(CPU *c) { /* PTR_0045ae20 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45dcccu); /* mov eax, 0x45dccc */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045ae2a(CPU *c) { /* Unwind@0045ae2a */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffffa4u)); /* lea ecx, [ebp - 0x5c] */
    PUSH32(c, 0x0045ae32u); f_0041e556(c); /* call 0x41e556 */
    c->esp += 4; return; /* ret  */
}

void f_0045ae33(CPU *c) { /* PTR_0045ae33 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45dcf0u); /* mov eax, 0x45dcf0 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045ae3d(CPU *c) { /* Unwind@0045ae3d */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffffa4u)); /* lea ecx, [ebp - 0x5c] */
    PUSH32(c, 0x0045ae45u); f_0041e556(c); /* call 0x41e556 */
    c->esp += 4; return; /* ret  */
}

void f_0045ae46(CPU *c) { /* PTR_0045ae46 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45dd14u); /* mov eax, 0x45dd14 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045ae50(CPU *c) { /* Unwind@0045ae50 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    PUSH32(c, 0x0045ae58u); f_00448be0(c); /* call 0x448be0 */
    c->esp += 4; return; /* ret  */
}

void f_0045ae59(CPU *c) { /* PTR_0045ae59 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45dd38u); /* mov eax, 0x45dd38 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045ae63(CPU *c) { /* Unwind@0045ae63 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffd9cu)); /* lea ecx, [ebp - 0x264] */
    PUSH32(c, 0x0045ae6eu); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045ae6f(CPU *c) { /* Unwind@0045ae6f */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x39u; PUSH32(c, v_); } /* push 0x39 */
    { uint32_t v_ = 0x46b4a4u; PUSH32(c, v_); } /* push 0x46b4a4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffd94u))); /* mov eax, dword ptr [ebp - 0x26c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0045ae82u); f_00448ba0(c); /* call 0x448ba0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_0045ae86(CPU *c) { /* PTR_0045ae86 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45dd64u); /* mov eax, 0x45dd64 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045ae90(CPU *c) { /* Unwind@0045ae90 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    PUSH32(c, 0x0045ae9bu); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045ae9c(CPU *c) { /* PTR_0045ae9c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45dd88u); /* mov eax, 0x45dd88 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045aea6(CPU *c) { /* Unwind@0045aea6 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    PUSH32(c, 0x0045aeb1u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045aeb2(CPU *c) { /* PTR_0045aeb2 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45ddacu); /* mov eax, 0x45ddac */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045aebc(CPU *c) { /* Unwind@0045aebc */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    PUSH32(c, 0x0045aec7u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045aec8(CPU *c) { /* PTR_0045aec8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45ddd0u); /* mov eax, 0x45ddd0 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045aee0(CPU *c) { /* Unwind@0045aee0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x60u; PUSH32(c, v_); } /* push 0x60 */
    { uint32_t v_ = 0x46b808u; PUSH32(c, v_); } /* push 0x46b808 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0045aef0u); f_00448ba0(c); /* call 0x448ba0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_0045aef4(CPU *c) { /* Unwind@0045aef4 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x7eu; PUSH32(c, v_); } /* push 0x7e */
    { uint32_t v_ = 0x46b83cu; PUSH32(c, v_); } /* push 0x46b83c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd4u))); /* mov eax, dword ptr [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0045af04u); f_00448ba0(c); /* call 0x448ba0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_0045af08(CPU *c) { /* PTR_0045af08 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45ddfcu); /* mov eax, 0x45ddfc */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045af20(CPU *c) { /* Unwind@0045af20 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda0u)); /* lea ecx, [ebp - 0x260] */
    PUSH32(c, 0x0045af2bu); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045af2c(CPU *c) { /* PTR_0045af2c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45de20u); /* mov eax, 0x45de20 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045af36(CPU *c) { /* Unwind@0045af36 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda0u)); /* lea ecx, [ebp - 0x260] */
    PUSH32(c, 0x0045af41u); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045af42(CPU *c) { /* PTR_0045af42 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45de44u); /* mov eax, 0x45de44 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}

void f_0045af50(CPU *c) { /* Unwind@0045af50 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda0u)); /* lea ecx, [ebp - 0x260] */
    PUSH32(c, 0x0045af5bu); f_004016a0(c); /* call 0x4016a0 */
    c->esp += 4; return; /* ret  */
}

void f_0045af5c(CPU *c) { /* PTR_0045af5c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x45de68u); /* mov eax, 0x45de68 */
    { f_0044d8bb(c); return; } /* jmp 0x44d8bb */
}
