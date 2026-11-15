#include "recomp.h"

void f_00cd1000(CPU *c) { /* FUN_10001000 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00cd1006u); f_00cd2b70(c); /* call 0xcd2b70 */
    W32((uint32_t)(c->esp), (uint32_t)(c->eax)); /* mov dword ptr [esp], eax */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp))); /* fild dword ptr [esp] */
    ST(0) = FPRES(c, FDIV(c, ST(0), (double)RF32((uint32_t)(0xcdc0f0u)))); /* fdiv dword ptr [0x1000c0f0] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x8u))); /* fmul dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00cd1020(CPU *c) { /* FUN_10001020 */
    PREEMPT_POLL(c);
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x4u))); /* fld dword ptr [esp + 4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xcdc0f4u))); /* fmul dword ptr [0x1000c0f4] */
    WF32((uint32_t)(c->esp + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd1038u); f_00cd1000(c); /* call 0xcd1000 */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x8u))); /* fadd dword ptr [esp + 8] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->esp += 4; return; /* ret  */
}

void f_00cd1040(CPU *c) { /* FUN_10001040 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd104au); f_00cd1000(c); /* call 0xcd1000 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x8u))); /* fld dword ptr [esp + 8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xcdc0f4u))); /* fmul dword ptr [0x1000c0f4] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    ST(1) = FPRES(c, ST(1) - ST(0)); FPOP(c); /* fsubp st(1) */
    c->esp += 4; return; /* ret  */
}

void f_00cd1060(CPU *c) { /* DMAInterface */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    W32((uint32_t)(0xce01d4u), (uint32_t)(c->eax)); /* mov dword ptr [0x100101d4], eax */
    W32((uint32_t)(0xce01ccu), (uint32_t)(c->eax)); /* mov dword ptr [0x100101cc], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov eax, dword ptr [eax + 4] */
    W32((uint32_t)(0xce01b8u), (uint32_t)(c->ecx)); /* mov dword ptr [0x100101b8], ecx */
    W32((uint32_t)(0xce01d0u), (uint32_t)(c->eax)); /* mov dword ptr [0x100101d0], eax */
    c->eax = (uint32_t)(R32((uint32_t)(0xce01d8u))); /* mov eax, dword ptr [0x100101d8] */
    c->esp += 4; return; /* ret  */
}

void f_00cd1090(CPU *c) { /* FUN_10001090 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(0xce01d4u))); /* mov ecx, dword ptr [0x100101d4] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4u)); PUSH32(c, 0x00cd10aau); call_indirect(c, t_); } /* call dword ptr [eax + 4] */
    c->esp += 4; return; /* ret  */
}

void f_00cd10b0(CPU *c) { /* FUN_100010b0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(0xce01d4u))); /* mov ecx, dword ptr [0x100101d4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x00cd10c0u); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
    c->esp += 4; return; /* ret  */
}

void f_00cd10d0(CPU *c) { /* PTR_00cd10d0 */
    PREEMPT_POLL(c);
    PUSH32(c, 0x00cd10d5u); f_00cd10e0(c); /* call 0xcd10e0 */
    { f_00cd11c0(c); return; } /* jmp 0xcd11c0 */
}

void f_00cd10e0(CPU *c) { /* FUN_100010e0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xce01d8u; PUSH32(c, v_); } /* push 0x100101d8 */
    c->ecx = (uint32_t)((uint32_t)0xce01bcu); /* mov ecx, 0x100101bc */
    PUSH32(c, 0x00cd10efu); f_00cd10f0(c); /* call 0xcd10f0 */
    c->esp += 4; return; /* ret  */
}

void f_00cd10f0(CPU *c) { /* FUN_100010f0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0xc], ecx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0xcdc114u)); /* mov dword ptr [eax], 0x1000c114 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 4], edx */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    c->esp += 8; return; /* ret 4 */
}

void f_00cd1110(CPU *c) { /* PTR_00cd1110 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xcdd04cu); /* mov eax, 0x1000d04c */
    c->esp += 4; return; /* ret  */
}

void f_00cd1120(CPU *c) { /* FUN_10001120 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xcdb4d4u; PUSH32(c, v_); } /* push 0x1000b4d4 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov eax, dword ptr [ecx + 0xc] */
    { uint32_t v_ = 0xau; PUSH32(c, v_); } /* push 0xa */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t v_ = 0xcdd058u; PUSH32(c, v_); } /* push 0x1000d058 */
    { uint32_t v_ = 0x16468u; PUSH32(c, v_); } /* push 0x16468 */
    W32((uint32_t)(c->ecx + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 0xc], eax */
    PUSH32(c, 0x00cd114eu); f_00cd1090(c); /* call 0xcd1090 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->esp), (uint32_t)(c->eax)); /* mov dword ptr [esp], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0xc], 0 */
    if (c->zf) goto L_00cd1177; /* je 0xcd1177 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    PUSH32(c, 0x00cd1168u); f_00cd11e0(c); /* call 0xcd11e0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
L_00cd1177:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_00cd1190(CPU *c) { /* FUN_10001190 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00cd1198u); f_00cd11b0(c); /* call 0xcd11b0 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00cd11a8; /* je 0xcd11a8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd11a5u); f_00cd10b0(c); /* call 0xcd10b0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00cd11a8:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00cd11b0(CPU *c) { /* FUN_100011b0 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx), (uint32_t)((uint32_t)0xcdc134u)); /* mov dword ptr [ecx], 0x1000c134 */
    c->esp += 4; return; /* ret  */
}

void f_00cd11c0(CPU *c) { /* FUN_100011c0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xcd11d0u; PUSH32(c, v_); } /* push 0x100011d0 */
    PUSH32(c, 0x00cd11cau); f_00cd305d(c); /* call 0xcd305d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00cd11d0(CPU *c) { /* PTR_00cd11d0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)0xce01bcu); /* mov ecx, 0x100101bc */
    { f_00cd11b0(c); return; } /* jmp 0xcd11b0 */
}

void f_00cd11e0(CPU *c) { /* FUN_100011e0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xcdb4e8u; PUSH32(c, v_); } /* push 0x1000b4e8 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x1cu)); /* sub esp, 0x1c */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edi = (uint32_t)((uint32_t)(c->ebx + 0x4u)); /* lea edi, [ebx + 4] */
    c->ebp = (uint32_t)(logic32(c, 0)); /* xor ebp, ebp */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x14], ebx */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 4], eax */
    W32((uint32_t)(c->edi + 0x8u), (uint32_t)(c->ebp)); /* mov dword ptr [edi + 8], ebp */
    W32((uint32_t)(c->edi + 0xcu), (uint32_t)(c->ebp)); /* mov dword ptr [edi + 0xc], ebp */
    W32((uint32_t)(c->edi + 0x10u), (uint32_t)(c->ebp)); /* mov dword ptr [edi + 0x10], ebp */
    W32((uint32_t)(c->edi + 0x14u), (uint32_t)(c->ebp)); /* mov dword ptr [edi + 0x14], ebp */
    W32((uint32_t)(c->ebx), (uint32_t)((uint32_t)0xcdc178u)); /* mov dword ptr [ebx], 0x1000c178 */
    W32((uint32_t)(c->ebx + 0x1cu), (uint32_t)(c->ebp)); /* mov dword ptr [ebx + 0x1c], ebp */
    c->ecx = (uint32_t)(R32((uint32_t)(0xce01b8u))); /* mov ecx, dword ptr [0x100101b8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x00cd1231u); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(0xce01b8u))); /* mov ecx, dword ptr [0x100101b8] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea edx, [esp + 0x14] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x10u)); PUSH32(c, 0x00cd1241u); call_indirect(c, t_); } /* call dword ptr [eax + 0x10] */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x10u))); /* mov edx, dword ptr [ebx + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(0xce01b8u))); /* mov ecx, dword ptr [0x100101b8] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x14u))); /* mov edx, dword ptr [ebx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4u)); PUSH32(c, 0x00cd125du); call_indirect(c, t_); } /* call dword ptr [eax + 4] */
    { uint32_t v_ = 0xcd2010u; PUSH32(c, v_); } /* push 0x10002010 */
    { uint32_t v_ = 0xcd1f70u; PUSH32(c, v_); } /* push 0x10001f70 */
    { uint32_t v_ = 0x19u; PUSH32(c, v_); } /* push 0x19 */
    c->eax = (uint32_t)((uint32_t)(c->ebx + 0x20u)); /* lea eax, [ebx + 0x20] */
    { uint32_t v_ = 0xe40u; PUSH32(c, v_); } /* push 0xe40 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(c->esp + 0x48u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0x48], ebp */
    PUSH32(c, 0x00cd127bu); f_00cd309e(c); /* call 0xcd309e */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov ecx, dword ptr [esp + 0x2c] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    W32((uint32_t)(c->ebx + 0x16460u), (uint32_t)(c->ebp)); /* mov dword ptr [ebx + 0x16460], ebp */
    W32((uint32_t)(c->ebx + 0x16464u), (uint32_t)(c->ebp)); /* mov dword ptr [ebx + 0x16464], ebp */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->ebx), (uint32_t)((uint32_t)0xcdc154u)); /* mov dword ptr [ebx], 0x1000c154 */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x28u)); /* add esp, 0x28 */
    c->esp += 4; return; /* ret  */
}

void f_00cd12b0(CPU *c) { /* FUN_100012b0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00cd12b8u); f_00cd12d0(c); /* call 0xcd12d0 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00cd12c8; /* je 0xcd12c8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd12c5u); f_00cd10b0(c); /* call 0xcd10b0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00cd12c8:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00cd12d0(CPU *c) { /* FUN_100012d0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xcdb508u; PUSH32(c, v_); } /* push 0x1000b508 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 4], esi */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0xcdc154u)); /* mov dword ptr [esi], 0x1000c154 */
    { uint32_t v_ = 0xcd2010u; PUSH32(c, v_); } /* push 0x10002010 */
    { uint32_t v_ = 0x19u; PUSH32(c, v_); } /* push 0x19 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x20u)); /* lea eax, [esi + 0x20] */
    { uint32_t v_ = 0xe40u; PUSH32(c, v_); } /* push 0xe40 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x20], 0 */
    PUSH32(c, 0x00cd1310u); f_00cd3120(c); /* call 0xcd3120 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x14u))); /* mov eax, dword ptr [esi + 0x14] */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0xcdc178u)); /* mov dword ptr [esi], 0x1000c178 */
    c->ecx = (uint32_t)(R32((uint32_t)(0xce01b8u))); /* mov ecx, dword ptr [0x100101b8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [esp + 0x14], 0xffffffff */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x00cd132du); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_00cd1340(CPU *c) { /* PTR_00cd1340 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(0xce01d4u))); /* mov ecx, dword ptr [0x100101d4] */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 4], eax */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 8], eax */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0xc], eax */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x18], eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x8u)); /* lea eax, [esp + 8] */
    { uint32_t v_ = 0xcdd088u; PUSH32(c, v_); } /* push 0x1000d088 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x44u)); PUSH32(c, 0x00cd1376u); call_indirect(c, t_); } /* call dword ptr [edx + 0x44] */
    c->ecx = (uint32_t)(R32((uint32_t)(0xce01d4u))); /* mov ecx, dword ptr [0x100101d4] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x4u)); /* lea eax, [esp + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x64u)); PUSH32(c, 0x00cd1386u); call_indirect(c, t_); } /* call dword ptr [edx + 0x64] */
    W32((uint32_t)(c->esi + 0x16464u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x16464], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(0xce01d4u))); /* mov ecx, dword ptr [0x100101d4] */
    { uint32_t v_ = 0xcdd040u; PUSH32(c, v_); } /* push 0x1000d040 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x4cu)); PUSH32(c, 0x00cd139cu); call_indirect(c, t_); } /* call dword ptr [edx + 0x4c] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    W32((uint32_t)(c->esi + 0x16460u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x16460], eax */
    PUSH32(c, 0x00cd13a9u); f_00cd14f0(c); /* call 0xcd14f0 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    c->esp += 4; return; /* ret  */
}

void f_00cd13b0(CPU *c) { /* PTR_00cd13b0 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x30u)); /* sub esp, 0x30 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x40u))); /* mov esi, dword ptr [esp + 0x40] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x20], eax */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x28], eax */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x2c], ebx */
    W32((uint32_t)(c->esp + 0x30u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x30], ebx */
    W32((uint32_t)(c->esp + 0x34u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x34], ebx */
    W32((uint32_t)(c->esp + 0x38u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x38], ebx */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x00cd13ddu); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    (void)sub32(c, c->eax, (uint32_t)0xc47du); /* cmp eax, 0xc47d */
    if (!c->zf) goto L_00cd147c; /* jne 0xcd147c */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x20u)); PUSH32(c, 0x00cd13efu); call_indirect(c, t_); } /* call dword ptr [eax + 0x20] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    if (c->zf) goto L_00cd147c; /* je 0xcd147c */
    c->ecx = (uint32_t)(R32((uint32_t)(0xce01d4u))); /* mov ecx, dword ptr [0x100101d4] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x28u)); /* lea eax, [esp + 0x28] */
    { uint32_t v_ = 0xcdd08cu; PUSH32(c, v_); } /* push 0x1000d08c */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x44u)); PUSH32(c, 0x00cd140fu); call_indirect(c, t_); } /* call dword ptr [edx + 0x44] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00cd147c; /* je 0xcd147c */
L_00cd1413:;
    c->ecx = (uint32_t)(R32((uint32_t)(0xce01d4u))); /* mov ecx, dword ptr [0x100101d4] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x24u)); /* lea eax, [esp + 0x24] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x64u)); PUSH32(c, 0x00cd1423u); call_indirect(c, t_); } /* call dword ptr [edx + 0x64] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x3cu)); PUSH32(c, 0x00cd142cu); call_indirect(c, t_); } /* call dword ptr [edx + 0x3c] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (c->zf) goto L_00cd144d; /* je 0xcd144d */
    c->ecx = (uint32_t)(R32((uint32_t)(0xce01d4u))); /* mov ecx, dword ptr [0x100101d4] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x24u)); /* lea edx, [esp + 0x24] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x48u)); PUSH32(c, 0x00cd1440u); call_indirect(c, t_); } /* call dword ptr [eax + 0x48] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00cd1413; /* jne 0xcd1413 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x30u)); /* add esp, 0x30 */
    c->esp += 4; return; /* ret  */
L_00cd144d:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0xcu)); /* lea ecx, [esp + 0xc] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x54u)); PUSH32(c, 0x00cd1459u); call_indirect(c, t_); } /* call dword ptr [eax + 0x54] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x8u))); /* fld dword ptr [eax + 8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xcdc0f4u))); /* fmul dword ptr [0x1000c0f4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x1cu)); /* lea eax, [esp + 0x1c] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x48u)); PUSH32(c, 0x00cd1472u); call_indirect(c, t_); } /* call dword ptr [edx + 0x48] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x44u))); /* mov ecx, dword ptr [esp + 0x44] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd147cu); f_00cd1550(c); /* call 0xcd1550 */
L_00cd147c:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x30u)); /* add esp, 0x30 */
    c->esp += 4; return; /* ret  */
}

void f_00cd1490(CPU *c) { /* FUN_10001490 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ebx, dword ptr [esp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)((uint32_t)(c->ecx + 0x20u)); /* lea esi, [ecx + 0x20] */
    c->edi = (uint32_t)((uint32_t)0x19u); /* mov edi, 0x19 */
L_00cd149f:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00cd14a7u); f_00cd24b0(c); /* call 0xcd24b0 */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xe40u)); /* add esi, 0xe40 */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    if (!c->zf) goto L_00cd149f; /* jne 0xcd149f */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
}

void f_00cd14c0(CPU *c) { /* FUN_100014c0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ebx, dword ptr [esp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)((uint32_t)(c->ecx + 0x20u)); /* lea esi, [ecx + 0x20] */
    c->edi = (uint32_t)((uint32_t)0x19u); /* mov edi, 0x19 */
L_00cd14cf:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00cd14d7u); f_00cd2250(c); /* call 0xcd2250 */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xe40u)); /* add esi, 0xe40 */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    if (!c->zf) goto L_00cd14cf; /* jne 0xcd14cf */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
}

void f_00cd14f0(CPU *c) { /* FUN_100014f0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0xce01d4u))); /* mov eax, dword ptr [0x100101d4] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    { uint32_t v_ = 0xcdd094u; PUSH32(c, v_); } /* push 0x1000d094 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x58u)); PUSH32(c, 0x00cd1508u); call_indirect(c, t_); } /* call dword ptr [edx + 0x58] */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->esi = (uint32_t)((uint32_t)(c->edi + 0x20u)); /* lea esi, [edi + 0x20] */
    c->ebp = (uint32_t)((uint32_t)0x19u); /* mov ebp, 0x19 */
L_00cd1512:;
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00cd1519u); f_00cd2180(c); /* call 0xcd2180 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x16460u))); /* mov eax, dword ptr [edi + 0x16460] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x16464u))); /* mov ecx, dword ptr [edi + 0x16464] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00cd1531u); f_00cd2090(c); /* call 0xcd2090 */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xe40u)); /* add esi, 0xe40 */
    c->ebp = (uint32_t)(dec32(c, c->ebp)); /* dec ebp */
    if (!c->zf) goto L_00cd1512; /* jne 0xcd1512 */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (c->zf) goto L_00cd1546; /* je 0xcd1546 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov edx, dword ptr [ebx] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    { uint32_t t_ = R32((uint32_t)(c->edx)); PUSH32(c, 0x00cd1546u); call_indirect(c, t_); } /* call dword ptr [edx] */
L_00cd1546:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00cd1550(CPU *c) { /* FUN_10001550 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->edi = (uint32_t)((uint32_t)(c->ebx + 0x20u)); /* lea edi, [ebx + 0x20] */
L_00cd155a:;
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    PUSH32(c, 0x00cd1561u); f_00cd25d0(c); /* call 0xcd25d0 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00cd1579; /* je 0xcd1579 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0xe40u)); /* add edi, 0xe40 */
    (void)sub32(c, c->esi, (uint32_t)0x19u); /* cmp esi, 0x19 */
    if ((c->sf != c->of)) goto L_00cd155a; /* jl 0xcd155a */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 12; return; /* ret 8 */
L_00cd1579:;
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi * 8)); /* lea eax, [esi + esi*8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edx, dword ptr [esp + 0x14] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->eax * 2)); /* lea eax, [esi + eax*2] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea ecx, [eax + eax*2] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 6)); /* shl ecx, 6 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->esi = (uint32_t)((uint32_t)(c->ecx + c->ebx + 0x20u)); /* lea esi, [ecx + ebx + 0x20] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00cd159au); f_00cd21c0(c); /* call 0xcd21c0 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 12; return; /* ret 8 */
}

void f_00cd15b0(CPU *c) { /* FUN_100015b0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0xcdc178u)); /* mov dword ptr [eax], 0x1000c178 */
    c->ecx = (uint32_t)(R32((uint32_t)(0xce01b8u))); /* mov ecx, dword ptr [0x100101b8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x14u))); /* mov eax, dword ptr [eax + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x00cd15c7u); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    c->esp += 4; return; /* ret  */
}

void f_00cd15d0(CPU *c) { /* PTR_00cd15d0 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    c->esp += 4; return; /* ret  */
}

void f_00cd15e0(CPU *c) { /* PTR_00cd15e0 */
    PREEMPT_POLL(c);
    c->esp += 8; return; /* ret 4 */
}

void f_00cd15f0(CPU *c) { /* PTR_00cd15f0 */
    PREEMPT_POLL(c);
    c->esp += 16; return; /* ret 0xc */
}

void f_00cd1600(CPU *c) { /* PTR_00cd1600 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    c->esp += 8; return; /* ret 4 */
}

void f_00cd1610(CPU *c) { /* PTR_00cd1610 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 8; return; /* ret 4 */
}

void f_00cd1620(CPU *c) { /* FUN_10001620 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x14u))); /* mov edx, dword ptr [esi + 0x14] */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0xcdc178u)); /* mov dword ptr [esi], 0x1000c178 */
    c->ecx = (uint32_t)(R32((uint32_t)(0xce01b8u))); /* mov ecx, dword ptr [0x100101b8] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x00cd1638u); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00cd1648; /* je 0xcd1648 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd1645u); f_00cd10b0(c); /* call 0xcd10b0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00cd1648:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00cd1650(CPU *c) { /* PTR_00cd1650 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_00cd1660(CPU *c) { /* PTR_00cd1660 */
    PREEMPT_POLL(c);
    { uint32_t a_ = (uint32_t)(c->ecx + 0xcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ecx + 0xc] */
    c->esp += 4; return; /* ret  */
}

void f_00cd1670(CPU *c) { /* PTR_00cd1670 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov eax, dword ptr [ecx + 0xc] */
    c->esp += 4; return; /* ret  */
}

void f_00cd1680(CPU *c) { /* PTR_00cd1680 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx + 0xcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ecx + 0xc], 0 */
    c->esp += 4; return; /* ret  */
}

void f_00cd1690(CPU *c) { /* PTR_00cd1690 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    c->esp += 4; return; /* ret  */
}

void f_00cd16a0(CPU *c) { /* PTR_00cd16a0 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x4u))); /* mov al, byte ptr [esp + 4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0xcdc134u)); /* mov dword ptr [esi], 0x1000c134 */
    if (c->zf) goto L_00cd16ba; /* je 0xcd16ba */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd16b7u); f_00cd10b0(c); /* call 0xcd10b0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00cd16ba:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00cd16c0(CPU *c) { /* PTR_00cd16c0 */
    PREEMPT_POLL(c);
    goto L_00cd16d0; /* jmp 0xcd16d0 */
L_00cd16d0:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)((uint32_t)0xce01ecu); /* mov eax, 0x100101ec */
    c->edx = (uint32_t)((uint32_t)0x4u); /* mov edx, 4 */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
L_00cd16de:;
    c->edi = (uint32_t)((uint32_t)(c->eax + 0xfffffff4u)); /* lea edi, [eax - 0xc] */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x18u)); /* add eax, 0x18 */
    c->edx = (uint32_t)(dec32(c, c->edx)); /* dec edx */
    W32((uint32_t)(c->edi), (uint32_t)(c->esi)); /* mov dword ptr [edi], esi */
    W32((uint32_t)(c->edi + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [edi + 4], esi */
    W32((uint32_t)(c->eax + 0xffffffe4u), (uint32_t)(c->ecx)); /* mov dword ptr [eax - 0x1c], ecx */
    W32((uint32_t)(c->eax + 0xffffffe8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax - 0x18], ecx */
    W32((uint32_t)(c->eax + 0xffffffecu), (uint32_t)(c->ecx)); /* mov dword ptr [eax - 0x14], ecx */
    W32((uint32_t)(c->eax + 0xfffffff0u), (uint32_t)(c->ecx)); /* mov dword ptr [eax - 0x10], ecx */
    if (!c->zf) goto L_00cd16de; /* jne 0xcd16de */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00cd1700(CPU *c) { /* PTR_00cd1700 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x38u)); /* lea ecx, [eax + 0x38] */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 4], edx */
    W8((uint32_t)(c->eax + 0x34u), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [eax + 0x34], dl */
    W32((uint32_t)(c->edi), (uint32_t)(c->esi)); /* mov dword ptr [edi], esi */
    W32((uint32_t)(c->edi + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [edi + 4], esi */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 8], edx */
    W32((uint32_t)(c->ecx + 0xcu), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 0xc], edx */
    W32((uint32_t)(c->ecx + 0x10u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 0x10], edx */
    W32((uint32_t)(c->ecx + 0x14u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 0x14], edx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0xcdc19cu)); /* mov dword ptr [eax], 0x1000c19c */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00cd1730(CPU *c) { /* FUN_10001730 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00cd1738u); f_00cd1750(c); /* call 0xcd1750 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00cd1748; /* je 0xcd1748 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd1745u); f_00cd10b0(c); /* call 0xcd10b0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00cd1748:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00cd1750(CPU *c) { /* FUN_10001750 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx), (uint32_t)((uint32_t)0xcdc19cu)); /* mov dword ptr [ecx], 0x1000c19c */
    c->eax = (uint32_t)(R32((uint32_t)(0xce0450u))); /* mov eax, dword ptr [0x10010450] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(0xce0450u), (uint32_t)(c->eax)); /* mov dword ptr [0x10010450], eax */
    if (!c->zf) goto L_00cd1790; /* jne 0xcd1790 */
    c->ebx = (uint32_t)((uint32_t)0xce01e0u); /* mov ebx, 0x100101e0 */
L_00cd176b:;
    c->eax = (uint32_t)(R32((uint32_t)(0xce01d4u))); /* mov eax, dword ptr [0x100101d4] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->esi = (uint32_t)(c->ebx); /* mov esi, ebx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x60u)); PUSH32(c, 0x00cd1785u); call_indirect(c, t_); } /* call dword ptr [edx + 0x60] */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x18u)); /* add ebx, 0x18 */
    (void)sub32(c, c->ebx, (uint32_t)0xce0240u); /* cmp ebx, 0x10010240 */
    if ((c->sf != c->of)) goto L_00cd176b; /* jl 0xcd176b */
L_00cd1790:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00cd17a0(CPU *c) { /* FUN_100017a0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W8((uint32_t)(c->edi + 0x34u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [edi + 0x34], 1 */
    W32((uint32_t)(c->edi + 0x2cu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [edi + 0x2c], 0 */
    PUSH32(c, 0x00cd17b9u); f_00cd1040(c); /* call 0xcd1040 */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x10u))); /* fadd dword ptr [esp + 0x10] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    WF32((uint32_t)(c->edi + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + 8] */
    PUSH32(c, 0x00cd17c6u); f_00cd1040(c); /* call 0xcd1040 */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x18u))); /* fadd dword ptr [esp + 0x18] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov ecx, dword ptr [edi + 4] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); /* fst dword ptr [esp + 0x18] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov edx, dword ptr [esp + 0x18] */
    WF32((uint32_t)(c->edi + 0xcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov edx, dword ptr [edi + 8] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x3cu)); PUSH32(c, 0x00cd17e7u); call_indirect(c, t_); } /* call dword ptr [eax + 0x3c] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0xcdc1acu))); /* fsub dword ptr [0x1000c1ac] */
    { uint32_t v_ = 0x3f800000u; PUSH32(c, v_); } /* push 0x3f800000 */
    WF32((uint32_t)(c->edi + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + 0x10] */
    PUSH32(c, 0x00cd17fau); f_00cd1040(c); /* call 0xcd1040 */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xcdc1a8u))); /* fmul dword ptr [0x1000c1a8] */
    { uint32_t v_ = 0x3f800000u; PUSH32(c, v_); } /* push 0x3f800000 */
    WF32((uint32_t)(c->edi + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + 0x14] */
    PUSH32(c, 0x00cd180du); f_00cd1020(c); /* call 0xcd1020 */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xcdc1a4u))); /* fmul dword ptr [0x1000c1a4] */
    { uint32_t v_ = 0x3f800000u; PUSH32(c, v_); } /* push 0x3f800000 */
    WF32((uint32_t)(c->edi + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + 0x1c] */
    PUSH32(c, 0x00cd1820u); f_00cd1040(c); /* call 0xcd1040 */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xcdc1a8u))); /* fmul dword ptr [0x1000c1a8] */
    { uint32_t v_ = 0x40c90fdbu; PUSH32(c, v_); } /* push 0x40c90fdb */
    WF32((uint32_t)(c->edi + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + 0x18] */
    PUSH32(c, 0x00cd1833u); f_00cd1000(c); /* call 0xcd1000 */
    WF32((uint32_t)(c->edi + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + 0x24] */
    { uint32_t v_ = 0x3f800000u; PUSH32(c, v_); } /* push 0x3f800000 */
    PUSH32(c, 0x00cd1840u); f_00cd1040(c); /* call 0xcd1040 */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xcdc1a0u))); /* fmul dword ptr [0x1000c1a0] */
    { uint32_t v_ = 0x46ea6000u; PUSH32(c, v_); } /* push 0x46ea6000 */
    WF32((uint32_t)(c->edi + 0x20u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + 0x20] */
    PUSH32(c, 0x00cd1853u); f_00cd1020(c); /* call 0xcd1020 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    PUSH32(c, 0x00cd185bu); f_00cd2fb8(c); /* call 0xcd2fb8 */
    W32((uint32_t)(c->edi + 0x30u), (uint32_t)(c->eax)); /* mov dword ptr [edi + 0x30], eax */
    W32((uint32_t)(c->edi + 0x28u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [edi + 0x28], 0 */
    PUSH32(c, 0x00cd186au); f_00cd2b70(c); /* call 0xcd2b70 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x80000003u))); /* and eax, 0x80000003 */
    if (!c->sf) goto L_00cd1876; /* jns 0xcd1876 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xfffffffcu))); /* or eax, 0xfffffffc */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
L_00cd1876:;
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea eax, [eax + eax*2] */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x38u)); /* add edi, 0x38 */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->esi = (uint32_t)((uint32_t)(c->eax * 8 + 0xce01e0u)); /* lea esi, [eax*8 + 0x100101e0] */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 16; return; /* ret 0xc */
}

void f_00cd1890(CPU *c) { /* FUN_10001890 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    c->eax = (uint32_t)(R32((uint32_t)(0xce0450u))); /* mov eax, dword ptr [0x10010450] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x14], ecx */
    if (!c->zf) goto L_00cd198b; /* jne 0xcd198b */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00cd18aa:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0xcdd0f8u))); /* mov cl, byte ptr [eax + 0x1000d0f8] */
    W8((uint32_t)(c->eax + 0xce0240u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax + 0x10010240], cl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_00cd18aa; /* jne 0xcd18aa */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00cd18bd:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0xcdd0e4u))); /* mov cl, byte ptr [eax + 0x1000d0e4] */
    W8((uint32_t)(c->eax + 0xce02c0u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax + 0x100102c0], cl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_00cd18bd; /* jne 0xcd18bd */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00cd18d0:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0xcdd0d0u))); /* mov cl, byte ptr [eax + 0x1000d0d0] */
    W8((uint32_t)(c->eax + 0xce0340u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax + 0x10010340], cl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_00cd18d0; /* jne 0xcd18d0 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00cd18e3:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0xcdd0bcu))); /* mov cl, byte ptr [eax + 0x1000d0bc] */
    W8((uint32_t)(c->eax + 0xce03c0u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax + 0x100103c0], cl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_00cd18e3; /* jne 0xcd18e3 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0xce0440u)); /* mov dword ptr [esp + 0x10], 0x10010440 */
    c->ebx = (uint32_t)((uint32_t)0xce01e0u); /* mov ebx, 0x100101e0 */
    c->ebp = (uint32_t)((uint32_t)0xce0240u); /* mov ebp, 0x10010240 */
L_00cd1906:;
    c->ecx = (uint32_t)(R32((uint32_t)(0xce01d4u))); /* mov ecx, dword ptr [0x100101d4] */
    { uint32_t v_ = 0xcdd0b4u; PUSH32(c, v_); } /* push 0x1000d0b4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x5cu)); PUSH32(c, 0x00cd1917u); call_indirect(c, t_); } /* call dword ptr [eax + 0x5c] */
    c->eax = (uint32_t)(R32((uint32_t)(0xce01d4u))); /* mov eax, dword ptr [0x100101d4] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = 0x5014u; PUSH32(c, v_); } /* push 0x5014 */
    { uint32_t v_ = 0xcdd0b0u; PUSH32(c, v_); } /* push 0x1000d0b0 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->esi = (uint32_t)(c->ebx); /* mov esi, ebx */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x98u)); PUSH32(c, 0x00cd193eu); call_indirect(c, t_); } /* call dword ptr [edx + 0x98] */
    c->ecx = (uint32_t)(R32((uint32_t)(0xce01d4u))); /* mov ecx, dword ptr [0x100101d4] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x28u)); /* add esp, 0x28 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x64u)); PUSH32(c, 0x00cd194du); call_indirect(c, t_); } /* call dword ptr [eax + 0x64] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    c->ebp = (uint32_t)(add32(c, c->ebp, (uint32_t)0x80u)); /* add ebp, 0x80 */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x18u)); /* add ebx, 0x18 */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    (void)sub32(c, c->ebp, (uint32_t)0xce0440u); /* cmp ebp, 0x10010440 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x10], ecx */
    if ((c->sf != c->of)) goto L_00cd1906; /* jl 0xcd1906 */
    c->eax = (uint32_t)(R32((uint32_t)(0xce0450u))); /* mov eax, dword ptr [0x10010450] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edx, dword ptr [esp + 0x14] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov ecx, dword ptr [esp + 0x1c] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    W32((uint32_t)(0xce0450u), (uint32_t)(c->eax)); /* mov dword ptr [0x10010450], eax */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [edx + 4], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->esp += 8; return; /* ret 4 */
L_00cd198b:;
    c->eax = (uint32_t)(R32((uint32_t)(0xce0450u))); /* mov eax, dword ptr [0x10010450] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0xce0450u), (uint32_t)(c->eax)); /* mov dword ptr [0x10010450], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 4], eax */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->esp += 8; return; /* ret 4 */
}

void f_00cd19b0(CPU *c) { /* FUN_100019b0 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x34u))); /* mov al, byte ptr [esi + 0x34] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00cd1b06; /* je 0xcd1b06 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ecx, dword ptr [esp + 0x14] */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0xc], 0 */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 8], ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x28u))); /* mov eax, dword ptr [esi + 0x28] */
    FPUSH(c, (double)(int64_t)R64((uint32_t)(c->esp + 0x8u))); /* fild qword ptr [esp + 8] */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x0u)); /* sub eax, 0 */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xcdc1c0u))); /* fmul dword ptr [0x1000c1c0] */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    if (c->zf) goto L_00cd1aac; /* je 0xcd1aac */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00cd1a59; /* je 0xcd1a59 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (!c->zf) goto L_00cd1b06; /* jne 0xcd1b06 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x14u))); /* fmul dword ptr [esi + 0x14] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x8u))); /* fadd dword ptr [esi + 8] */
    WF32((uint32_t)(c->esp + 0xcu), (float)ST(0)); /* fst dword ptr [esp + 0xc] */
    WF32((uint32_t)(c->esi + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x18u))); /* fmul dword ptr [esi + 0x18] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0xcu))); /* fadd dword ptr [esi + 0xc] */
    WF32((uint32_t)(c->esp + 0x8u), (float)ST(0)); /* fst dword ptr [esp + 8] */
    WF32((uint32_t)(c->esi + 0xcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0xc] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x1cu))); /* fmul dword ptr [esi + 0x1c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(c->esi + 0x10u)) - ST(0)); /* fsubr dword ptr [esi + 0x10] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    WF32((uint32_t)(c->esi + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x3cu)); PUSH32(c, 0x00cd1a38u); call_indirect(c, t_); } /* call dword ptr [eax + 0x3c] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0xcdc1acu))); /* fsub dword ptr [0x1000c1ac] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->esi + 0x10u))); FPOP(c); /* fcomp dword ptr [esi + 0x10] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x100u))); /* and eax, 0x100 */
    if (!c->zf) goto L_00cd1b06; /* jne 0xcd1b06 */
    W8((uint32_t)(c->esi + 0x34u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esi + 0x34], 0 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 8; return; /* ret 4 */
L_00cd1a59:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x14u))); /* fmul dword ptr [esi + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x2cu))); /* mov edx, dword ptr [esi + 0x2c] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edx = (uint32_t)(add32(c, c->edx, c->ecx)); /* add edx, ecx */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x8u))); /* fadd dword ptr [esi + 8] */
    W32((uint32_t)(c->esi + 0x2cu), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x2c], edx */
    c->edi = (uint32_t)(c->edx); /* mov edi, edx */
    WF32((uint32_t)(c->esi + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x18u))); /* fmul dword ptr [esi + 0x18] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0xcu))); /* fadd dword ptr [esi + 0xc] */
    WF32((uint32_t)(c->esi + 0xcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0xc] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x20u))); /* fmul dword ptr [esi + 0x20] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x24u))); /* fadd dword ptr [esi + 0x24] */
    FPUSH(c, RF64((uint32_t)(0xcdc1b8u))); /* fld qword ptr [0x1000c1b8] */
    PUSH32(c, 0x00cd1a93u); f_00cd322a(c); /* call 0xcd322a */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x30u))); /* mov eax, dword ptr [esi + 0x30] */
    WF32((uint32_t)(c->esi + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x24] */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    if ((c->cf || c->zf)) goto L_00cd1b06; /* jbe 0xcd1b06 */
    W32((uint32_t)(c->esi + 0x28u), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [esi + 0x28], 2 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 8; return; /* ret 4 */
L_00cd1aac:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x14u))); /* fmul dword ptr [esi + 0x14] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x8u))); /* fadd dword ptr [esi + 8] */
    WF32((uint32_t)(c->esp + 0xcu), (float)ST(0)); /* fst dword ptr [esp + 0xc] */
    WF32((uint32_t)(c->esi + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x18u))); /* fmul dword ptr [esi + 0x18] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0xcu))); /* fadd dword ptr [esi + 0xc] */
    WF32((uint32_t)(c->esp + 0x8u), (float)ST(0)); /* fst dword ptr [esp + 8] */
    WF32((uint32_t)(c->esi + 0xcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0xc] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x1cu))); /* fmul dword ptr [esi + 0x1c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x10u))); /* fadd dword ptr [esi + 0x10] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    WF32((uint32_t)(c->esi + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x3cu)); PUSH32(c, 0x00cd1aefu); call_indirect(c, t_); } /* call dword ptr [eax + 0x3c] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0xcdc1b0u))); /* fadd dword ptr [0x1000c1b0] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->esi + 0x10u))); FPOP(c); /* fcomp dword ptr [esi + 0x10] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00cd1b06; /* jp 0xcd1b06 */
    W32((uint32_t)(c->esi + 0x28u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [esi + 0x28], 1 */
L_00cd1b06:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 8; return; /* ret 4 */
}

void f_00cd1b10(CPU *c) { /* FUN_10001b10 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x38u)); /* sub esp, 0x38 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x34u))); /* mov al, byte ptr [esi + 0x34] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00cd1c79; /* je 0xcd1c79 */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x8u))); /* fld dword ptr [esi + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x28u))); /* mov eax, dword ptr [esi + 0x28] */
    WF32((uint32_t)(c->esp + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x24] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0xcu))); /* fld dword ptr [esi + 0xc] */
    WF32((uint32_t)(c->esp + 0x2cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x2c] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_00cd1b55; /* jne 0xcd1b55 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov edx, dword ptr [esi + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov edx, dword ptr [esi + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x3cu)); PUSH32(c, 0x00cd1b49u); call_indirect(c, t_); } /* call dword ptr [eax + 0x3c] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0xcdc1b0u))); /* fadd dword ptr [0x1000c1b0] */
    WF32((uint32_t)(c->esp + 0x28u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x28] */
    goto L_00cd1b5c; /* jmp 0xcd1b5c */
L_00cd1b55:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x28], eax */
L_00cd1b5c:;
    c->ecx = (uint32_t)(R32((uint32_t)(0xce01ccu))); /* mov ecx, dword ptr [0x100101cc] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x24u))); /* fld dword ptr [esi + 0x24] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x38u)); /* add esi, 0x38 */
    WF32((uint32_t)(c->esp + 0x34u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x34] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x64u)); PUSH32(c, 0x00cd1b72u); call_indirect(c, t_); } /* call dword ptr [edx + 0x64] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd1c79; /* je 0xcd1c79 */
    FPUSH(c, RF64((uint32_t)(0xcdc108u))); /* fld qword ptr [0x1000c108] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->eax + 0x2cu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [eax + 0x2c], 0 */
    W32((uint32_t)(c->eax + 0x3cu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [eax + 0x3c], 0 */
    W32((uint32_t)(c->eax + 0x4cu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [eax + 0x4c], 0 */
    W32((uint32_t)(c->eax + 0x5cu), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [eax + 0x5c], 0x3f800000 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x38u)); /* add esp, 0x38 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    FPUSH(c, RF64((uint32_t)(0xcdc108u))); /* fld qword ptr [0x1000c108] */
    ST(0) = FTRIG(c, ST(0), cos); /* fcos  */
    WF32((uint32_t)(c->esp + 0xffffffc8u), (float)ST(0)); /* fst dword ptr [esp - 0x38] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xfffffff8u))); /* fld dword ptr [esp - 8] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xfffffff8u))); /* fld dword ptr [esp - 8] */
    ST(0) = FTRIG(c, ST(0), cos); /* fcos  */
    WF32((uint32_t)(c->esp + 0xffffffd4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp - 0x2c] */
    { double t_ = ST(0); ST(0) = ST(3); ST(3) = t_; } /* fxch st(3) */
    WF32((uint32_t)(c->esp + 0xffffffccu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp - 0x34] */
    WF32((uint32_t)(c->esp + 0xffffffd0u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp - 0x30] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xffffffccu))); /* fld dword ptr [esp - 0x34] */
    ST(0) = FPRES(c, ST(0) * ST(2)); /* fmul st(2) */
    WF32((uint32_t)(c->esp + 0xffffffe4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp - 0x1c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xffffffd0u))); /* fld dword ptr [esp - 0x30] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xffffffd4u))); /* fmul dword ptr [esp - 0x2c] */
    WF32((uint32_t)(c->esp + 0xffffffe0u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp - 0x20] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xffffffe4u))); /* fld dword ptr [esp - 0x1c] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0xffffffe0u))); /* fadd dword ptr [esp - 0x20] */
    WF32((uint32_t)(c->eax + 0x20u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 0x20] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xffffffd0u))); /* fld dword ptr [esp - 0x30] */
    ST(0) = FPRES(c, ST(0) * ST(2)); /* fmul st(2) */
    WF32((uint32_t)(c->esp + 0xffffffdcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp - 0x24] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xffffffccu))); /* fld dword ptr [esp - 0x34] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xffffffd4u))); /* fmul dword ptr [esp - 0x2c] */
    WF32((uint32_t)(c->esp + 0xffffffd8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp - 0x28] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xffffffdcu))); /* fld dword ptr [esp - 0x24] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0xffffffd8u))); /* fsub dword ptr [esp - 0x28] */
    WF32((uint32_t)(c->eax + 0x30u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 0x30] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xffffffc8u))); /* fmul dword ptr [esp - 0x38] */
    WF32((uint32_t)(c->eax + 0x40u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 0x40] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xffffffe8u))); /* fld dword ptr [esp - 0x18] */
    WF32((uint32_t)(c->eax + 0x50u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 0x50] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xffffffccu))); /* fld dword ptr [esp - 0x34] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xffffffc8u))); /* fmul dword ptr [esp - 0x38] */
    WF32((uint32_t)(c->eax + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 0x24] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xffffffd0u))); /* fld dword ptr [esp - 0x30] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xffffffc8u))); /* fmul dword ptr [esp - 0x38] */
    WF32((uint32_t)(c->eax + 0x34u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 0x34] */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = -ST(0); /* fchs  */
    WF32((uint32_t)(c->eax + 0x44u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 0x44] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xffffffecu))); /* fld dword ptr [esp - 0x14] */
    WF32((uint32_t)(c->eax + 0x54u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 0x54] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xffffffd8u))); /* fld dword ptr [esp - 0x28] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0xffffffdcu))); /* fsub dword ptr [esp - 0x24] */
    WF32((uint32_t)(c->eax + 0x28u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 0x28] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xffffffe0u))); /* fld dword ptr [esp - 0x20] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0xffffffe4u))); /* fadd dword ptr [esp - 0x1c] */
    WF32((uint32_t)(c->eax + 0x38u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 0x38] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xffffffd4u))); /* fld dword ptr [esp - 0x2c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xffffffc8u))); /* fmul dword ptr [esp - 0x38] */
    WF32((uint32_t)(c->eax + 0x48u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 0x48] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xfffffff0u))); /* fld dword ptr [esp - 0x10] */
    WF32((uint32_t)(c->eax + 0x58u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 0x58] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); switch (t_) {  default: jump_indirect(c, t_, 0x00cd1c76u); return; } } /* jmp dword ptr [edx + 0xc] */
L_00cd1c79:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x38u)); /* add esp, 0x38 */
    c->esp += 8; return; /* ret 4 */
}

void f_00cd1c80(CPU *c) { /* FUN_10001c80 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0x34u))); /* mov al, byte ptr [ecx + 0x34] */
    c->esp += 4; return; /* ret  */
}

void f_00cd1c90(CPU *c) { /* FUN_10001c90 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->esi + 0x14u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x14], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov edx, dword ptr [esp + 0x20] */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x10], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov eax, dword ptr [esp + 0x1c] */
    W32((uint32_t)(c->esi + 0x1cu), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x1c], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov edx, dword ptr [esp + 0x24] */
    W32((uint32_t)(c->esi + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x18], eax */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)c->edx; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, edx */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 4], ecx */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 8], ebx */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0xc], ebx */
    W32((uint32_t)(c->esi + 0x20u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x20], edx */
    W32((uint32_t)(c->esi + 0x24u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x24], ebx */
    W8((uint32_t)(c->esi + 0x28u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [esi + 0x28], bl */
    W32((uint32_t)(c->esi + 0x2cu), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x2c], ebx */
    W32((uint32_t)(c->esi + 0x30u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x30], ebx */
    W32((uint32_t)(c->esi + 0x34u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x34], ebx */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0xcdc1c4u)); /* mov dword ptr [esi], 0x1000c1c4 */
    c->edi = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edi, dword ptr [ecx] */
    c->eax = (uint32_t)(add32(c, c->eax, c->eax)); /* add eax, eax */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edi + 0x104u)); PUSH32(c, 0x00cd1cecu); call_indirect(c, t_); } /* call dword ptr [edi + 0x104] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov edx, dword ptr [esi + 0x20] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    { int64_t r_ = (int64_t)(int32_t)c->edx * (int32_t)R32((uint32_t)(c->esi + 0x1cu)); c->edx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul edx, dword ptr [esi + 0x1c] */
    { int64_t r_ = (int64_t)(int32_t)c->edx * (int32_t)R32((uint32_t)(c->esi + 0x14u)); c->edx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul edx, dword ptr [esi + 0x14] */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov edx, dword ptr [esi + 0x10] */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xc], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x100u)); PUSH32(c, 0x00cd1d0cu); call_indirect(c, t_); } /* call dword ptr [eax + 0x100] */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov eax, dword ptr [esi + 0x20] */
    { uint32_t v_ = 0x15u; PUSH32(c, v_); } /* push 0x15 */
    { uint32_t v_ = 0xcdd10cu; PUSH32(c, v_); } /* push 0x1000d10c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd1d1fu); f_00cd1090(c); /* call 0xcd1090 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov ecx, dword ptr [esi + 0x20] */
    W32((uint32_t)(c->esi + 0x24u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x24], eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, c->ecx, c->ebx); /* cmp ecx, ebx */
    if ((c->zf || c->sf != c->of)) goto L_00cd1d3d; /* jle 0xcd1d3d */
L_00cd1d2e:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov ecx, dword ptr [esi + 0x24] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    W8((uint32_t)(c->eax + c->ecx + 0xffffffffu), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [eax + ecx - 1], bl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov ecx, dword ptr [esi + 0x20] */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if ((c->sf != c->of)) goto L_00cd1d2e; /* jl 0xcd1d2e */
L_00cd1d3d:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 28; return; /* ret 0x18 */
}

void f_00cd1d50(CPU *c) { /* FUN_10001d50 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00cd1d58u); f_00cd1d70(c); /* call 0xcd1d70 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00cd1d68; /* je 0xcd1d68 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd1d65u); f_00cd10b0(c); /* call 0xcd10b0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00cd1d68:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00cd1d70(CPU *c) { /* FUN_10001d70 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov eax, dword ptr [esi + 0x24] */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0xcdc1c4u)); /* mov dword ptr [esi], 0x1000c1c4 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd1d89; /* je 0xcd1d89 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd1d86u); f_00cd10b0(c); /* call 0xcd10b0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00cd1d89:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd1d9c; /* je 0xcd1d9c */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x124u)); PUSH32(c, 0x00cd1d9cu); call_indirect(c, t_); } /* call dword ptr [edx + 0x124] */
L_00cd1d9c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd1daf; /* je 0xcd1daf */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x128u)); PUSH32(c, 0x00cd1dafu); call_indirect(c, t_); } /* call dword ptr [edx + 0x128] */
L_00cd1daf:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00cd1dc0(CPU *c) { /* FUN_10001dc0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x20u))); /* mov esi, dword ptr [ecx + 0x20] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if ((c->zf || c->sf != c->of)) goto L_00cd1dd8; /* jle 0xcd1dd8 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x24u))); /* mov edx, dword ptr [ecx + 0x24] */
L_00cd1dcd:;
    (void)sub8(c, R8((uint32_t)(c->edx + c->eax)), (uint8_t)0x0u); /* cmp byte ptr [edx + eax], 0 */
    if (c->zf) goto L_00cd1ddd; /* je 0xcd1ddd */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if ((c->sf != c->of)) goto L_00cd1dcd; /* jl 0xcd1dcd */
L_00cd1dd8:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
L_00cd1ddb:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_00cd1ddd:;
    W8((uint32_t)(c->edx + c->eax), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [edx + eax], 1 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x34u))); /* mov edx, dword ptr [ecx + 0x34] */
    (void)sub32(c, c->eax, c->edx); /* cmp eax, edx */
    if (!c->zf) goto L_00cd1ddb; /* jne 0xcd1ddb */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->ecx + 0x34u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 0x34], edx */
    c->esp += 4; return; /* ret  */
}

void f_00cd1df0(CPU *c) { /* FUN_10001df0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf != c->of)) goto L_00cd1dff; /* jl 0xcd1dff */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x24u))); /* mov ecx, dword ptr [ecx + 0x24] */
    W8((uint32_t)(c->eax + c->ecx), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [eax + ecx], 0 */
L_00cd1dff:;
    c->esp += 8; return; /* ret 4 */
}

void f_00cd1e10(CPU *c) { /* FUN_10001e10 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x20u))); /* mov edx, dword ptr [ecx + 0x20] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if ((c->zf || c->sf != c->of)) goto L_00cd1e29; /* jle 0xcd1e29 */
L_00cd1e19:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x24u))); /* mov edx, dword ptr [ecx + 0x24] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    W8((uint32_t)(c->eax + c->edx + 0xffffffffu), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [eax + edx - 1], 0 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x20u))); /* mov edx, dword ptr [ecx + 0x20] */
    (void)sub32(c, c->eax, c->edx); /* cmp eax, edx */
    if ((c->sf != c->of)) goto L_00cd1e19; /* jl 0xcd1e19 */
L_00cd1e29:;
    c->esp += 4; return; /* ret  */
}

void f_00cd1e30(CPU *c) { /* FUN_10001e30 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov edx, dword ptr [esi + 0xc] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x11cu)); PUSH32(c, 0x00cd1e44u); call_indirect(c, t_); } /* call dword ptr [eax + 0x11c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov edx, dword ptr [esi + 8] */
    W32((uint32_t)(c->esi + 0x2cu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x2c], eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x110u)); PUSH32(c, 0x00cd1e58u); call_indirect(c, t_); } /* call dword ptr [eax + 0x110] */
    W32((uint32_t)(c->esi + 0x30u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x30], eax */
    W8((uint32_t)(c->esi + 0x28u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esi + 0x28], 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00cd1e70(CPU *c) { /* FUN_10001e70 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov edx, dword ptr [esi + 0xc] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x120u)); PUSH32(c, 0x00cd1e82u); call_indirect(c, t_); } /* call dword ptr [eax + 0x120] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov edx, dword ptr [esi + 8] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x114u)); PUSH32(c, 0x00cd1e91u); call_indirect(c, t_); } /* call dword ptr [eax + 0x114] */
    W8((uint32_t)(c->esi + 0x28u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esi + 0x28], 0 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00cd1ea0(CPU *c) { /* FUN_10001ea0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf != c->of)) goto L_00cd1eeb; /* jl 0xcd1eeb */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0x28u))); /* mov dl, byte ptr [ecx + 0x28] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00cd1eeb; /* je 0xcd1eeb */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x18u))); /* mov edx, dword ptr [ecx + 0x18] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { int64_t r_ = (int64_t)(int32_t)c->edx * (int32_t)c->eax; c->edx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul edx, eax */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x2cu))); /* mov esi, dword ptr [ecx + 0x2c] */
    c->edx = (uint32_t)((uint32_t)(c->esi + c->edx * 2)); /* lea edx, [esi + edx*2] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov esi, dword ptr [esp + 0xc] */
    W32((uint32_t)(c->esi), (uint32_t)(c->edx)); /* mov dword ptr [esi], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x14u))); /* mov edx, dword ptr [ecx + 0x14] */
    { int64_t r_ = (int64_t)(int32_t)c->edx * (int32_t)R32((uint32_t)(c->ecx + 0x1cu)); c->edx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul edx, dword ptr [ecx + 0x1c] */
    { int64_t r_ = (int64_t)(int32_t)c->edx * (int32_t)c->eax; c->edx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul edx, eax */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x30u))); /* mov esi, dword ptr [ecx + 0x30] */
    c->edx = (uint32_t)(add32(c, c->edx, c->esi)); /* add edx, esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
    W32((uint32_t)(c->esi), (uint32_t)(c->edx)); /* mov dword ptr [esi], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edx, dword ptr [esp + 0x14] */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    if (c->zf) goto L_00cd1eff; /* je 0xcd1eff */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x1cu))); /* mov ecx, dword ptr [ecx + 0x1c] */
    { int64_t r_ = (int64_t)(int32_t)c->ecx * (int32_t)c->eax; c->ecx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul ecx, eax */
    W32((uint32_t)(c->edx), (uint32_t)(c->ecx)); /* mov dword ptr [edx], ecx */
    c->esp += 20; return; /* ret 0x10 */
L_00cd1eeb:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    W32((uint32_t)(c->edx), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [edx], 0 */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [eax], 0 */
L_00cd1eff:;
    c->esp += 20; return; /* ret 0x10 */
}

void f_00cd1f10(CPU *c) { /* FUN_10001f10 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0x28u))); /* mov al, byte ptr [ecx + 0x28] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00cd1f65; /* jne 0xcd1f65 */
    c->edi = (uint32_t)(R32((uint32_t)(c->ecx + 0x34u))); /* mov edi, dword ptr [ecx + 0x34] */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00cd1f65; /* je 0xcd1f65 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x18u))); /* mov edx, dword ptr [ecx + 0x18] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { int64_t r_ = (int64_t)(int32_t)c->edx * (int32_t)c->edi; c->edx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul edx, edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)0x55555556u); /* mov eax, 0x55555556 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov esi, dword ptr [ecx + 4] */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)c->edx; c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = r_ != (int32_t)r_; } /* imul edx */
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ebx, dword ptr [esi] */
    c->eax = (uint32_t)(shr32(c, c->eax, 31)); /* shr eax, 0x1f */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov eax, dword ptr [ecx + 0xc] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x1cu))); /* mov edx, dword ptr [ecx + 0x1c] */
    { int64_t r_ = (int64_t)(int32_t)c->edx * (int32_t)c->edi; c->edx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul edx, edi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x14u))); /* mov edx, dword ptr [ecx + 0x14] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov eax, dword ptr [ecx + 8] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->ebx + 0xd8u)); PUSH32(c, 0x00cd1f60u); call_indirect(c, t_); } /* call dword ptr [ebx + 0xd8] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x28u)); /* add esp, 0x28 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
L_00cd1f65:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 8; return; /* ret 4 */
}

void f_00cd1f70(CPU *c) { /* FUN_10001f70 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xcdb536u; PUSH32(c, v_); } /* push 0x1000b536 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = 0xcd2620u; PUSH32(c, v_); } /* push 0x10002620 */
    { uint32_t v_ = 0xcd25e0u; PUSH32(c, v_); } /* push 0x100025e0 */
    { uint32_t v_ = 0x19u; PUSH32(c, v_); } /* push 0x19 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x1cu)); /* lea eax, [esi + 0x1c] */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    { uint32_t v_ = 0x34u; PUSH32(c, v_); } /* push 0x34 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x1c], esi */
    W8((uint32_t)(c->esi + 0x4u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [esi + 4], bl */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x10], ebx */
    W32((uint32_t)(c->esi + 0x14u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x14], ebx */
    W32((uint32_t)(c->esi + 0x18u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x18], ebx */
    PUSH32(c, 0x00cd1fb3u); f_00cd309e(c); /* call 0xcd309e */
    { uint32_t v_ = 0xcd1750u; PUSH32(c, v_); } /* push 0x10001750 */
    { uint32_t v_ = 0xcd1700u; PUSH32(c, v_); } /* push 0x10001700 */
    { uint32_t v_ = 0x19u; PUSH32(c, v_); } /* push 0x19 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x65cu)); /* lea ecx, [esi + 0x65c] */
    { uint32_t v_ = 0x50u; PUSH32(c, v_); } /* push 0x50 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x28], ebx */
    PUSH32(c, 0x00cd1fd1u); f_00cd309e(c); /* call 0xcd309e */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0xcdc1c8u)); /* mov dword ptr [esi], 0x1000c1c8 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_00cd1ff0(CPU *c) { /* FUN_10001ff0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00cd1ff8u); f_00cd2010(c); /* call 0xcd2010 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00cd2008; /* je 0xcd2008 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd2005u); f_00cd10b0(c); /* call 0xcd10b0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00cd2008:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00cd2010(CPU *c) { /* FUN_10002010 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xcdb56eu; PUSH32(c, v_); } /* push 0x1000b56e */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 4], esi */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0xcdc1c8u)); /* mov dword ptr [esi], 0x1000c1c8 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [esp + 0x10], 1 */
    PUSH32(c, 0x00cd2040u); f_00cd2180(c); /* call 0xcd2180 */
    { uint32_t v_ = 0xcd1750u; PUSH32(c, v_); } /* push 0x10001750 */
    { uint32_t v_ = 0x19u; PUSH32(c, v_); } /* push 0x19 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x65cu)); /* lea eax, [esi + 0x65c] */
    { uint32_t v_ = 0x50u; PUSH32(c, v_); } /* push 0x50 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W8((uint32_t)(c->esp + 0x20u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esp + 0x20], 0 */
    PUSH32(c, 0x00cd205au); f_00cd3120(c); /* call 0xcd3120 */
    { uint32_t v_ = 0xcd2620u; PUSH32(c, v_); } /* push 0x10002620 */
    { uint32_t v_ = 0x19u; PUSH32(c, v_); } /* push 0x19 */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x1cu)); /* add esi, 0x1c */
    { uint32_t v_ = 0x34u; PUSH32(c, v_); } /* push 0x34 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [esp + 0x20], 0xffffffff */
    PUSH32(c, 0x00cd2074u); f_00cd3120(c); /* call 0xcd3120 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_00cd2090(CPU *c) { /* FUN_10002090 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xcdb594u; PUSH32(c, v_); } /* push 0x1000b594 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov ecx, dword ptr [esp + 0x2c] */
    { uint32_t v_ = 0x1au; PUSH32(c, v_); } /* push 0x1a */
    { uint32_t v_ = 0xcdd150u; PUSH32(c, v_); } /* push 0x1000d150 */
    { uint32_t v_ = 0x38u; PUSH32(c, v_); } /* push 0x38 */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xc], eax */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 8], ecx */
    PUSH32(c, 0x00cd20c7u); f_00cd1090(c); /* call 0xcd1090 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x28], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x18], 0 */
    if (c->zf) goto L_00cd20f7; /* je 0xcd20f7 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov edx, dword ptr [esi + 8] */
    { uint32_t v_ = 0x19u; PUSH32(c, v_); } /* push 0x19 */
    { uint32_t v_ = 0x79u; PUSH32(c, v_); } /* push 0x79 */
    { uint32_t v_ = 0x258u; PUSH32(c, v_); } /* push 0x258 */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    { uint32_t v_ = 0x142u; PUSH32(c, v_); } /* push 0x142 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    PUSH32(c, 0x00cd20f5u); f_00cd1c90(c); /* call 0xcd1c90 */
    goto L_00cd20f9; /* jmp 0xcd20f9 */
L_00cd20f7:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00cd20f9:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ecx, dword ptr [esi + 8] */
    W32((uint32_t)(c->esi + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x14], eax */
    { uint32_t v_ = 0xcdd144u; PUSH32(c, v_); } /* push 0x1000d144 */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [esp + 0x1c], 0xffffffff */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x78u)); PUSH32(c, 0x00cd2111u); call_indirect(c, t_); } /* call dword ptr [eax + 0x78] */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x10], eax */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x594u)); /* lea edi, [esi + 0x594] */
    c->ebx = (uint32_t)((uint32_t)(c->esi + 0x1cu)); /* lea ebx, [esi + 0x1c] */
    c->ebp = (uint32_t)((uint32_t)0x19u); /* mov ebp, 0x19 */
L_00cd2122:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov ecx, dword ptr [esi + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov edx, dword ptr [esp + 0x20] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    PUSH32(c, 0x00cd2132u); f_00cd2630(c); /* call 0xcd2630 */
    W32((uint32_t)(c->edi), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [edi], 0xffffffff */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x34u)); /* add ebx, 0x34 */
    c->ebp = (uint32_t)(dec32(c, c->ebp)); /* dec ebp */
    if (!c->zf) goto L_00cd2122; /* jne 0xcd2122 */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x65cu)); /* lea edi, [esi + 0x65c] */
    c->ebx = (uint32_t)((uint32_t)0x19u); /* mov ebx, 0x19 */
L_00cd214c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd2157u); f_00cd1890(c); /* call 0xcd1890 */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x50u)); /* add edi, 0x50 */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->zf) goto L_00cd214c; /* jne 0xcd214c */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 20; return; /* ret 0x10 */
}

void f_00cd2180(CPU *c) { /* FUN_10002180 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x14u))); /* mov ecx, dword ptr [esi + 0x14] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00cd2197; /* je 0xcd2197 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t t_ = R32((uint32_t)(c->eax)); PUSH32(c, 0x00cd2190u); call_indirect(c, t_); } /* call dword ptr [eax] */
    W32((uint32_t)(c->esi + 0x14u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 0x14], 0 */
L_00cd2197:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd21b1; /* je 0xcd21b1 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ecx, dword ptr [esi + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x80u)); PUSH32(c, 0x00cd21aau); call_indirect(c, t_); } /* call dword ptr [edx + 0x80] */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 0x10], 0 */
L_00cd21b1:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00cd21c0(CPU *c) { /* FUN_100021c0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x4u))); /* mov al, byte ptr [esi + 4] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00cd2247; /* jne 0xcd2247 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    W32((uint32_t)(c->esi + 0x18u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 0x18], 0 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0xe34u)); /* lea eax, [esi + 0xe34] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->eax), (uint32_t)(c->edx)); /* mov dword ptr [eax], edx */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x530u)); /* lea edi, [esi + 0x530] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov edx, dword ptr [ecx + 4] */
    c->ebx = (uint32_t)((uint32_t)0x19u); /* mov ebx, 0x19 */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 4], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edx, dword ptr [esp + 0x14] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov ecx, dword ptr [ecx + 8] */
    W32((uint32_t)(c->esi + 0xe30u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0xe30], edx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    W8((uint32_t)(c->esi + 0x4u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esi + 4], 1 */
L_00cd2206:;
    { uint32_t v_ = 0x44fa0000u; PUSH32(c, v_); } /* push 0x44fa0000 */
    PUSH32(c, 0x00cd2210u); f_00cd1000(c); /* call 0xcd1000 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    PUSH32(c, 0x00cd2218u); f_00cd2fb8(c); /* call 0xcd2fb8 */
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->zf) goto L_00cd2206; /* jne 0xcd2206 */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x5f8u)); /* add esi, 0x5f8 */
    c->edi = (uint32_t)((uint32_t)0x19u); /* mov edi, 0x19 */
L_00cd222b:;
    { uint32_t v_ = 0x44fa0000u; PUSH32(c, v_); } /* push 0x44fa0000 */
    PUSH32(c, 0x00cd2235u); f_00cd1000(c); /* call 0xcd1000 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    PUSH32(c, 0x00cd223du); f_00cd2fb8(c); /* call 0xcd2fb8 */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    if (!c->zf) goto L_00cd222b; /* jne 0xcd222b */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
L_00cd2247:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 12; return; /* ret 8 */
}

void f_00cd2250(CPU *c) { /* FUN_10002250 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x1cu)); /* sub esp, 0x1c */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x4u))); /* mov al, byte ptr [esi + 4] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00cd24a4; /* je 0xcd24a4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov eax, dword ptr [esp + 0x2c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x18u))); /* mov ecx, dword ptr [esi + 0x18] */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    W32((uint32_t)(c->esi + 0x18u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 0x18], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x14u))); /* mov ecx, dword ptr [esi + 0x14] */
    (void)sub32(c, c->eax, (uint32_t)0x1dc90u); /* cmp eax, 0x1dc90 */
    if ((c->cf || c->zf)) goto L_00cd22f8; /* jbe 0xcd22f8 */
    W8((uint32_t)(c->esi + 0x4u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esi + 4], 0 */
    PUSH32(c, 0x00cd2284u); f_00cd1e30(c); /* call 0xcd1e30 */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x594u)); /* lea edi, [esi + 0x594] */
    c->ebx = (uint32_t)((uint32_t)(c->esi + 0x1cu)); /* lea ebx, [esi + 0x1c] */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)((uint32_t)0x19u)); /* mov dword ptr [esp + 0x2c], 0x19 */
L_00cd2295:;
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    PUSH32(c, 0x00cd229cu); f_00cd2b40(c); /* call 0xcd2b40 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00cd22c8; /* je 0xcd22c8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0xcu)); /* lea ecx, [esp + 0xc] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea edx, [esp + 0x14] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x14u))); /* mov ecx, dword ptr [esi + 0x14] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd22b7u); f_00cd1ea0(c); /* call 0xcd1ea0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    PUSH32(c, 0x00cd22c8u); f_00cd2b50(c); /* call 0xcd2b50 */
L_00cd22c8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov eax, dword ptr [esp + 0x2c] */
    W32((uint32_t)(c->edi), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [edi], 0xffffffff */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x34u)); /* add ebx, 0x34 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x2c], eax */
    if (!c->zf) goto L_00cd2295; /* jne 0xcd2295 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x14u))); /* mov ecx, dword ptr [esi + 0x14] */
    PUSH32(c, 0x00cd22e7u); f_00cd1e70(c); /* call 0xcd1e70 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x14u))); /* mov ecx, dword ptr [esi + 0x14] */
    PUSH32(c, 0x00cd22efu); f_00cd1e10(c); /* call 0xcd1e10 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    c->esp += 8; return; /* ret 4 */
L_00cd22f8:;
    PUSH32(c, 0x00cd22fdu); f_00cd1e30(c); /* call 0xcd1e30 */
    c->ebx = (uint32_t)((uint32_t)(c->esi + 0x1cu)); /* lea ebx, [esi + 0x1c] */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x594u)); /* lea edi, [esi + 0x594] */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0x19u)); /* mov dword ptr [esp + 0x14], 0x19 */
L_00cd230e:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0xffffff9cu))); /* mov eax, dword ptr [edi - 0x64] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_00cd2321; /* jle 0xcd2321 */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->esp + 0x2cu)))); /* sub eax, dword ptr [esp + 0x2c] */
    W32((uint32_t)(c->edi + 0xffffff9cu), (uint32_t)(c->eax)); /* mov dword ptr [edi - 0x64], eax */
    goto L_00cd241f; /* jmp 0xcd241f */
L_00cd2321:;
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    PUSH32(c, 0x00cd2328u); f_00cd2b40(c); /* call 0xcd2b40 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00cd23f2; /* jne 0xcd23f2 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (c->zf) goto L_00cd2360; /* je 0xcd2360 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x14u))); /* mov ecx, dword ptr [esi + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd2340u); f_00cd1df0(c); /* call 0xcd1df0 */
    { uint32_t v_ = 0x44fa0000u; PUSH32(c, v_); } /* push 0x44fa0000 */
    PUSH32(c, 0x00cd234au); f_00cd1000(c); /* call 0xcd1000 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    PUSH32(c, 0x00cd2352u); f_00cd2fb8(c); /* call 0xcd2fb8 */
    W32((uint32_t)(c->edi + 0xffffff9cu), (uint32_t)(c->eax)); /* mov dword ptr [edi - 0x64], eax */
    W32((uint32_t)(c->edi), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [edi], 0xffffffff */
    goto L_00cd241f; /* jmp 0xcd241f */
L_00cd2360:;
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0xe30u))); /* fld dword ptr [esi + 0xe30] */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0xe34u)); /* lea eax, [esi + 0xe34] */
    ST(0) = FPRES(c, ST(0) + ST(0)); /* fadd st(0), st(0) */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x20], ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov edx, dword ptr [eax + 4] */
    WF32((uint32_t)(c->esp), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x24], edx */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x28], eax */
    PUSH32(c, 0x00cd238bu); f_00cd1040(c); /* call 0xcd1040 */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x20u))); /* fadd dword ptr [esp + 0x20] */
    WF32((uint32_t)(c->esp + 0x20u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x20] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0xe30u))); /* fld dword ptr [esi + 0xe30] */
    ST(0) = FPRES(c, ST(0) + ST(0)); /* fadd st(0), st(0) */
    WF32((uint32_t)(c->esp), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp] */
    PUSH32(c, 0x00cd23a3u); f_00cd1040(c); /* call 0xcd1040 */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x28u))); /* fadd dword ptr [esp + 0x28] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x14u))); /* mov ecx, dword ptr [esi + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    WF32((uint32_t)(c->esp + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x24] */
    PUSH32(c, 0x00cd23b6u); f_00cd1dc0(c); /* call 0xcd1dc0 */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    if (c->zf) goto L_00cd241f; /* je 0xcd241f */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x18u)); /* lea ecx, [esp + 0x18] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0xcu)); /* lea edx, [esp + 0xc] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea ecx, [esp + 0x14] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x14u))); /* mov ecx, dword ptr [esi + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd23d5u); f_00cd1ea0(c); /* call 0xcd1ea0 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov edx, dword ptr [esp + 0x18] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x24u)); /* lea edx, [esp + 0x24] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    PUSH32(c, 0x00cd23f0u); f_00cd2650(c); /* call 0xcd2650 */
    goto L_00cd241f; /* jmp 0xcd241f */
L_00cd23f2:;
    c->edx = (uint32_t)(R32((uint32_t)(c->edi))); /* mov edx, dword ptr [edi] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0xcu)); /* lea eax, [esp + 0xc] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea ecx, [esp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x14u))); /* mov ecx, dword ptr [esi + 0x14] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00cd2409u); f_00cd1ea0(c); /* call 0xcd1ea0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov edx, dword ptr [esp + 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    PUSH32(c, 0x00cd241fu); f_00cd2830(c); /* call 0xcd2830 */
L_00cd241f:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x34u)); /* add ebx, 0x34 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    if (!c->zf) goto L_00cd230e; /* jne 0xcd230e */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x14u))); /* mov ecx, dword ptr [esi + 0x14] */
    PUSH32(c, 0x00cd243cu); f_00cd1e70(c); /* call 0xcd1e70 */
    c->ebx = (uint32_t)((uint32_t)(c->esi + 0x65cu)); /* lea ebx, [esi + 0x65c] */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x5f8u)); /* lea edi, [esi + 0x5f8] */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0x19u)); /* mov dword ptr [esp + 0x14], 0x19 */
L_00cd2450:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_00cd245e; /* jle 0xcd245e */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->esp + 0x2cu)))); /* sub eax, dword ptr [esp + 0x2c] */
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    goto L_00cd2493; /* jmp 0xcd2493 */
L_00cd245e:;
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    PUSH32(c, 0x00cd2465u); f_00cd1c80(c); /* call 0xcd1c80 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00cd2487; /* jne 0xcd2487 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xe30u))); /* mov eax, dword ptr [esi + 0xe30] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0xe3cu))); /* mov ecx, dword ptr [esi + 0xe3c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0xe34u))); /* mov edx, dword ptr [esi + 0xe34] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    PUSH32(c, 0x00cd2485u); f_00cd17a0(c); /* call 0xcd17a0 */
    goto L_00cd2493; /* jmp 0xcd2493 */
L_00cd2487:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov eax, dword ptr [esp + 0x2c] */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd2493u); f_00cd19b0(c); /* call 0xcd19b0 */
L_00cd2493:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x50u)); /* add ebx, 0x50 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    if (!c->zf) goto L_00cd2450; /* jne 0xcd2450 */
L_00cd24a4:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    c->esp += 8; return; /* ret 4 */
}

void f_00cd24b0(CPU *c) { /* FUN_100024b0 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x48u)); /* sub esp, 0x48 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x4u))); /* mov al, byte ptr [esi + 4] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00cd25c6; /* je 0xcd25c6 */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0xcu)); /* lea eax, [esp + 0xc] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)((uint32_t)0x3f800000u); /* mov ecx, 0x3f800000 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 4], ebx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 8], ebx */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0xc], ebx */
    W32((uint32_t)(c->eax + 0x10u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x10], ebx */
    W32((uint32_t)(c->eax + 0x14u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x14], ecx */
    W32((uint32_t)(c->eax + 0x18u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x18], ebx */
    W32((uint32_t)(c->eax + 0x1cu), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x1c], ebx */
    W32((uint32_t)(c->eax + 0x20u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x20], ebx */
    W32((uint32_t)(c->eax + 0x24u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x24], ebx */
    W32((uint32_t)(c->eax + 0x28u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x28], ecx */
    W32((uint32_t)(c->eax + 0x2cu), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x2c], ebx */
    W32((uint32_t)(c->eax + 0x30u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x30], ebx */
    W32((uint32_t)(c->eax + 0x34u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x34], ebx */
    W32((uint32_t)(c->eax + 0x38u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x38], ebx */
    W32((uint32_t)(c->eax + 0x3cu), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x3c], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ecx, dword ptr [esi + 8] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea eax, [esp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x100u; PUSH32(c, v_); } /* push 0x100 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x58u)); PUSH32(c, 0x00cd2517u); call_indirect(c, t_); } /* call dword ptr [edx + 0x58] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ecx, dword ptr [esi + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x7cu)); PUSH32(c, 0x00cd2525u); call_indirect(c, t_); } /* call dword ptr [edx + 0x7c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ecx, dword ptr [esi + 8] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0xcu)); /* lea eax, [esp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x8bu; PUSH32(c, v_); } /* push 0x8b */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x130u)); PUSH32(c, 0x00cd253au); call_indirect(c, t_); } /* call dword ptr [edx + 0x130] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ecx, dword ptr [esi + 8] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0x55000000u))); /* or eax, 0x55000000 */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0xc], eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x3cu; PUSH32(c, v_); } /* push 0x3c */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x12cu)); PUSH32(c, 0x00cd2555u); call_indirect(c, t_); } /* call dword ptr [edx + 0x12c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x14u))); /* mov ecx, dword ptr [esi + 0x14] */
    { uint32_t v_ = 0xcdd17cu; PUSH32(c, v_); } /* push 0x1000d17c */
    PUSH32(c, 0x00cd2562u); f_00cd1f10(c); /* call 0xcd1f10 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ecx, dword ptr [esi + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x8bu; PUSH32(c, v_); } /* push 0x8b */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x12cu)); PUSH32(c, 0x00cd2577u); call_indirect(c, t_); } /* call dword ptr [eax + 0x12c] */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x1cu)); /* lea edi, [esi + 0x1c] */
    c->ebx = (uint32_t)((uint32_t)0x19u); /* mov ebx, 0x19 */
L_00cd257f:;
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    PUSH32(c, 0x00cd2586u); f_00cd2b40(c); /* call 0xcd2b40 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00cd2596; /* je 0xcd2596 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x58u))); /* mov eax, dword ptr [esp + 0x58] */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd2596u); f_00cd2b60(c); /* call 0xcd2b60 */
L_00cd2596:;
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x34u)); /* add edi, 0x34 */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->zf) goto L_00cd257f; /* jne 0xcd257f */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x58u))); /* mov ebx, dword ptr [esp + 0x58] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x65cu)); /* add esi, 0x65c */
    c->edi = (uint32_t)((uint32_t)0x19u); /* mov edi, 0x19 */
L_00cd25ab:;
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00cd25b2u); f_00cd1c80(c); /* call 0xcd1c80 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00cd25be; /* je 0xcd25be */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00cd25beu); f_00cd1b10(c); /* call 0xcd1b10 */
L_00cd25be:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x50u)); /* add esi, 0x50 */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    if (!c->zf) goto L_00cd25ab; /* jne 0xcd25ab */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
L_00cd25c6:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x48u)); /* add esp, 0x48 */
    c->esp += 8; return; /* ret 4 */
}

void f_00cd25d0(CPU *c) { /* FUN_100025d0 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0x4u))); /* mov al, byte ptr [ecx + 4] */
    c->esp += 4; return; /* ret  */
}

void f_00cd25e0(CPU *c) { /* PTR_00cd25e0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 4], ecx */
    W8((uint32_t)(c->eax + 0x8u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax + 8], cl */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0xc], ecx */
    W32((uint32_t)(c->eax + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x10], ecx */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0xcdc1ccu)); /* mov dword ptr [eax], 0x1000c1cc */
    c->esp += 4; return; /* ret  */
}

void f_00cd2600(CPU *c) { /* FUN_10002600 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00cd2608u); f_00cd2620(c); /* call 0xcd2620 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00cd2618; /* je 0xcd2618 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd2615u); f_00cd10b0(c); /* call 0xcd10b0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00cd2618:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00cd2620(CPU *c) { /* FUN_10002620 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx), (uint32_t)((uint32_t)0xcdc1ccu)); /* mov dword ptr [ecx], 0x1000c1cc */
    goto L_00cd2640; /* jmp 0xcd2640 */
L_00cd2640:;
    c->esp += 4; return; /* ret  */
}

void f_00cd2630(CPU *c) { /* FUN_10002630 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    W32((uint32_t)(c->ecx + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 0xc], eax */
    c->esp += 12; return; /* ret 8 */
}

void f_00cd2640(CPU *c) { /* PTR_00cd2640 */
    PREEMPT_POLL(c);
    c->esp += 4; return; /* ret  */
}

void f_00cd2650(CPU *c) { /* FUN_10002650 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    { uint32_t v_ = 0x3dcccccdu; PUSH32(c, v_); } /* push 0x3dcccccd */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x18u)); /* lea edi, [esi + 0x18] */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x10], ebx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov edx, dword ptr [eax + 4] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 4], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    W8((uint32_t)(c->esi + 0x8u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esi + 8], 1 */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 8], eax */
    PUSH32(c, 0x00cd2685u); f_00cd1020(c); /* call 0xcd1020 */
    WF32((uint32_t)(c->esp + 0x20u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x20] */
    { uint32_t v_ = 0x3fc00000u; PUSH32(c, v_); } /* push 0x3fc00000 */
    PUSH32(c, 0x00cd2693u); f_00cd1000(c); /* call 0xcd1000 */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x24u))); /* fadd dword ptr [esp + 0x24] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov eax, dword ptr [esi + 0x20] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov ecx, dword ptr [esi + 0xc] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    WF32((uint32_t)(c->esi + 0x30u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x30] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x3cu)); PUSH32(c, 0x00cd26adu); call_indirect(c, t_); } /* call dword ptr [edx + 0x3c] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0xcdc1b0u))); /* fsub dword ptr [0x1000c1b0] */
    { uint32_t v_ = 0x46ea6000u; PUSH32(c, v_); } /* push 0x46ea6000 */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
    PUSH32(c, 0x00cd26c1u); f_00cd1000(c); /* call 0xcd1000 */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0xcdc1d8u))); /* fadd dword ptr [0x1000c1d8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov eax, dword ptr [esp + 0x28] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x10], edx */
    WF32((uint32_t)(c->esi + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x14] */
L_00cd26d7:;
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x10u))); /* fild dword ptr [esp + 0x10] */
    FPUSH(c, (double)RF32((uint32_t)(0xcdc1d4u))); /* fld dword ptr [0x1000c1d4] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x1c], ecx */
    WF32((uint32_t)(c->esp + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x24] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xcdc1d0u))); /* fmul dword ptr [0x1000c1d0] */
L_00cd26f3:;
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x1cu))); /* fild dword ptr [esp + 0x1c] */
    FPUSH(c, (double)RF32((uint32_t)(0xcdc1d4u))); /* fld dword ptr [0x1000c1d4] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ebp, dword ptr [esp + 0x14] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x18u)); /* add eax, 0x18 */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->ecx, (uint32_t)0xbu); /* cmp ecx, 0xb */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x1c], ecx */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->edi))); /* fadd dword ptr [edi] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0xcdc1a0u))); /* fsub dword ptr [0x1000c1a0] */
    WF32((uint32_t)(c->eax + 0xffffffe8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax - 0x18] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x24u))); /* fld dword ptr [esp + 0x24] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x20u))); /* fadd dword ptr [esi + 0x20] */
    W32((uint32_t)(c->eax + 0xffffffecu), (uint32_t)(c->ebp)); /* mov dword ptr [eax - 0x14], ebp */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0xcdc1a0u))); /* fsub dword ptr [0x1000c1a0] */
    WF32((uint32_t)(c->eax + 0xfffffff0u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax - 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xcdc1d0u))); /* fmul dword ptr [0x1000c1d0] */
    WF32((uint32_t)(c->eax + 0xfffffff8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax - 8] */
    WF32((uint32_t)(c->eax + 0xfffffffcu), (float)ST(0)); /* fst dword ptr [eax - 4] */
    if ((c->sf != c->of)) goto L_00cd26f3; /* jl 0xcd26f3 */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    (void)sub32(c, c->edx, (uint32_t)0xbu); /* cmp edx, 0xb */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x10], edx */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    if ((c->sf != c->of)) goto L_00cd26d7; /* jl 0xcd26d7 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov eax, dword ptr [esp + 0x20] */
L_00cd274a:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov edx, dword ptr [esp + 0x28] */
    c->esi = (uint32_t)((uint32_t)(c->ebx + c->ebx * 4 + 0x5u)); /* lea esi, [ebx + ebx*4 + 5] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->edi = (uint32_t)((uint32_t)(c->edx + c->ebx + 0x1u)); /* lea edi, [edx + ebx + 1] */
    c->edx = (uint32_t)(add32(c, c->edx, c->ebx)); /* add edx, ebx */
    c->ebp = (uint32_t)((uint32_t)(c->edi + c->esi * 2)); /* lea ebp, [edi + esi*2] */
    c->esi = (uint32_t)((uint32_t)(c->ebx + c->ebx * 4)); /* lea esi, [ebx + ebx*4] */
    c->edx = (uint32_t)((uint32_t)(c->edx + c->esi * 2)); /* lea edx, [edx + esi*2] */
L_00cd2763:;
    c->esi = (uint32_t)((uint32_t)(c->ecx + c->edx)); /* lea esi, [ecx + edx] */
    c->edi = (uint32_t)((uint32_t)(c->ecx + c->ebp)); /* lea edi, [ecx + ebp] */
    W16((uint32_t)(c->eax), (uint16_t)(((uint16_t)c->esi))); /* mov word ptr [eax], si */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x2u)); /* add eax, 2 */
    W16((uint32_t)(c->eax), (uint16_t)(((uint16_t)c->edi))); /* mov word ptr [eax], di */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x2u)); /* add eax, 2 */
    c->edi = (uint32_t)((uint32_t)(c->ecx + c->edx + 0xcu)); /* lea edi, [ecx + edx + 0xc] */
    W16((uint32_t)(c->eax), (uint16_t)(((uint16_t)c->edi))); /* mov word ptr [eax], di */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x2u)); /* add eax, 2 */
    W16((uint32_t)(c->eax), (uint16_t)(((uint16_t)c->esi))); /* mov word ptr [eax], si */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x2u)); /* add eax, 2 */
    c->esi = (uint32_t)((uint32_t)(c->ecx + c->edx + 0x1u)); /* lea esi, [ecx + edx + 1] */
    W16((uint32_t)(c->eax), (uint16_t)(((uint16_t)c->edi))); /* mov word ptr [eax], di */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x2u)); /* add eax, 2 */
    W16((uint32_t)(c->eax), (uint16_t)(((uint16_t)c->esi))); /* mov word ptr [eax], si */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x2u)); /* add eax, 2 */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->ecx, (uint32_t)0xau); /* cmp ecx, 0xa */
    if ((c->sf != c->of)) goto L_00cd2763; /* jl 0xcd2763 */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    (void)sub32(c, c->ebx, (uint32_t)0xau); /* cmp ebx, 0xa */
    if ((c->sf != c->of)) goto L_00cd274a; /* jl 0xcd274a */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->esp += 20; return; /* ret 0x10 */
}

void f_00cd27b0(CPU *c) { /* FUN_100027b0 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 4], 0 */
    W32((uint32_t)(c->esp), (uint32_t)(c->eax)); /* mov dword ptr [esp], eax */
    FPUSH(c, (double)(int64_t)R64((uint32_t)(c->esp))); /* fild qword ptr [esp] */
    FPUSH(c, (double)RF32((uint32_t)(0xcdc1e8u))); /* fld dword ptr [0x1000c1e8] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xcdc1e4u))); /* fmul dword ptr [0x1000c1e4] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    ST(0) = fabs(ST(0)); /* fabs  */
    ST(0) = FPRES(c, ST(0) + RF64((uint32_t)(0xcdc100u))); /* fadd qword ptr [0x1000c100] */
    FPUSH(c, (double)RF32((uint32_t)(0xcdc1e0u))); /* fld dword ptr [0x1000c1e0] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x10u))); /* fsub dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xcdc1dcu))); /* fmul dword ptr [0x1000c1dc] */
    ST(1) = FPRES(c, ST(1) * ST(0)); FPOP(c); /* fmulp st(1) */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xcdc1c0u))); /* fmul dword ptr [0x1000c1c0] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xcdc0f8u))); /* fcom dword ptr [0x1000c0f8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00cd2818; /* jne 0xcd2818 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, (double)RF32((uint32_t)(0xcdc0f8u))); /* fld dword ptr [0x1000c0f8] */
L_00cd2818:;
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x10u))); /* fmul dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xcdc0f4u))); /* fmul dword ptr [0x1000c0f4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x14u))); /* fmul dword ptr [esp + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->esp += 16; return; /* ret 0xc */
}

void f_00cd2830(CPU *c) { /* FUN_10002830 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x38u)); /* sub esp, 0x38 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x8u))); /* mov al, byte ptr [esi + 8] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00cd2b17; /* je 0xcd2b17 */
    { uint32_t v_ = 0x40c90fdbu; PUSH32(c, v_); } /* push 0x40c90fdb */
    PUSH32(c, 0x00cd284cu); f_00cd1000(c); /* call 0xcd1000 */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
    { uint32_t v_ = 0x3fc00000u; PUSH32(c, v_); } /* push 0x3fc00000 */
    PUSH32(c, 0x00cd285au); f_00cd1020(c); /* call 0xcd1020 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0xce0454u))); /* mov cl, byte ptr [0x10010454] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->ecx))); /* test al, cl */
    if (!c->zf) goto L_00cd2884; /* jne 0xcd2884 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(((uint8_t)c->ecx)); /* mov dl, cl */
    { uint32_t v_ = 0xcd2b30u; PUSH32(c, v_); } /* push 0x10002b30 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->edx) | ((uint8_t)c->eax)))); /* or dl, al */
    W8((uint32_t)(0xce0454u), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [0x10010454], dl */
    PUSH32(c, 0x00cd2881u); f_00cd305d(c); /* call 0xcd305d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00cd2884:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0xce0454u))); /* mov cl, byte ptr [0x10010454] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x2u); /* mov al, 2 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->ecx))); /* test al, cl */
    if (!c->zf) goto L_00cd28a7; /* jne 0xcd28a7 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(((uint8_t)c->ecx)); /* mov dl, cl */
    { uint32_t v_ = 0xcd2b20u; PUSH32(c, v_); } /* push 0x10002b20 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->edx) | ((uint8_t)c->eax)))); /* or dl, al */
    W8((uint32_t)(0xce0454u), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [0x10010454], dl */
    PUSH32(c, 0x00cd28a4u); f_00cd305d(c); /* call 0xcd305d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00cd28a7:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xcu))); /* fld dword ptr [esp + 0xc] */
    ST(0) = FTRIG(c, ST(0), cos); /* fcos  */
    c->ebx = (uint32_t)((uint32_t)(c->esi + 0x18u)); /* lea ebx, [esi + 0x18] */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    W32((uint32_t)(0xce0464u), (uint32_t)(c->ecx)); /* mov dword ptr [0x10010464], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x44u))); /* mov ecx, dword ptr [esp + 0x44] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov edx, dword ptr [eax + 4] */
    W32((uint32_t)(0xce0468u), (uint32_t)(c->edx)); /* mov dword ptr [0x10010468], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    W32((uint32_t)(0xce045cu), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [0x1001045c], 0x3f800000 */
    W32((uint32_t)(0xce046cu), (uint32_t)(c->eax)); /* mov dword ptr [0x1001046c], eax */
    FPUSH(c, RF64((uint32_t)(0xcdc1f0u))); /* fld qword ptr [0x1000c1f0] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0xce0464u))); /* fadd dword ptr [0x10010464] */
    WF32((uint32_t)(0xce0464u), (float)ST(0)); FPOP(c); /* fstp dword ptr [0x10010464] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xcu))); /* fld dword ptr [esp + 0xc] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    FPUSH(c, RF64((uint32_t)(0xcdc1f0u))); /* fld qword ptr [0x1000c1f0] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0xce046cu))); /* fadd dword ptr [0x1001046c] */
    WF32((uint32_t)(0xce046cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [0x1001046c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x8u))); /* fld dword ptr [esp + 8] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * ST(3)); /* fmul st(3) */
    WF32((uint32_t)(0xce0458u), (float)ST(0)); FPOP(c); /* fstp dword ptr [0x10010458] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF32((uint32_t)(0xce0460u), (float)ST(0)); FPOP(c); /* fstp dword ptr [0x10010460] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov edx, dword ptr [esi + 0x10] */
    c->edx = (uint32_t)(add32(c, c->edx, c->ecx)); /* add edx, ecx */
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x10], edx */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    (void)sub32(c, c->eax, (uint32_t)0xbb8u); /* cmp eax, 0xbb8 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    if ((c->cf || c->zf)) goto L_00cd2940; /* jbe 0xcd2940 */
    W8((uint32_t)(c->esi + 0x8u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esi + 8], 0 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x38u)); /* add esp, 0x38 */
    c->esp += 16; return; /* ret 0xc */
L_00cd2940:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov eax, dword ptr [esi + 0x20] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov ecx, dword ptr [esi + 0xc] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x3cu)); PUSH32(c, 0x00cd2953u); call_indirect(c, t_); } /* call dword ptr [edx + 0x3c] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0xcdc1b0u))); /* fsub dword ptr [0x1000c1b0] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x54u))); /* mov edi, dword ptr [esp + 0x54] */
    W32((uint32_t)(c->esp + 0x4cu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x4c], 0 */
    WF32((uint32_t)(c->esp + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1c] */
L_00cd2969:;
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x4cu))); /* fild dword ptr [esp + 0x4c] */
    c->ebp = (uint32_t)(logic32(c, 0)); /* xor ebp, ebp */
    W32((uint32_t)(c->esp + 0x54u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0x54], ebp */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); /* fst dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xcdc1d4u))); /* fmul dword ptr [0x1000c1d4] */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); /* fst dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0xcdc1a0u))); /* fsub dword ptr [0x1000c1a0] */
    WF32((uint32_t)(c->esp + 0x38u), (float)ST(0)); /* fst dword ptr [esp + 0x38] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x38u))); /* fmul dword ptr [esp + 0x38] */
    WF32((uint32_t)(c->esp + 0x20u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x20] */
L_00cd2993:;
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x54u))); /* fild dword ptr [esp + 0x54] */
    FPUSH(c, (double)RF32((uint32_t)(0xcdc1d4u))); /* fld dword ptr [0x1000c1d4] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF32((uint32_t)(c->esp + 0x54u), (float)ST(0)); /* fst dword ptr [esp + 0x54] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0xcdc1a0u))); /* fsub dword ptr [0x1000c1a0] */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x20u))); /* fadd dword ptr [esp + 0x20] */
    FCOM(c, ST(0), RF64((uint32_t)(0xcdc108u))); /* fcom qword ptr [0x1000c108] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x44u)); /* test ah, 0x44 */
    if (PF(c)) goto L_00cd29d2; /* jp 0xcd29d2 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, (double)RF32((uint32_t)(0xcdc110u))); /* fld dword ptr [0x1000c110] */
    W32((uint32_t)(c->esp + 0x3cu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x3c], 0 */
    goto L_00cd29ec; /* jmp 0xcd29ec */
L_00cd29d2:;
    ST(0) = FPRES(c, sqrt(ST(0))); /* fsqrt  */
    ST(0) = FPRES(c, FDIV(c, RF64((uint32_t)(0xcdc100u)), ST(0))); /* fdivr qword ptr [0x1000c100] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF32((uint32_t)(c->esp + 0x3cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x3c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x38u))); /* fld dword ptr [esp + 0x38] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
L_00cd29ec:;
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x2cu))); /* fmul dword ptr [esi + 0x2c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x3cu))); /* fld dword ptr [esp + 0x3c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x24u))); /* fmul dword ptr [esi + 0x24] */
    c->ecx = (uint32_t)((uint32_t)0xbb8u); /* mov ecx, 0xbb8 */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x54u))); /* fld dword ptr [esp + 0x54] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ebx))); /* fadd dword ptr [ebx] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0xcdc1a0u))); /* fsub dword ptr [0x1000c1a0] */
    WF32((uint32_t)(c->esp + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x24] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x20u))); /* fadd dword ptr [esi + 0x20] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0xcdc1a0u))); /* fsub dword ptr [0x1000c1a0] */
    WF32((uint32_t)(c->esp + 0x2cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x2c] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xcdc1d4u))); /* fmul dword ptr [0x1000c1d4] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0xcdc1a0u))); /* fsub dword ptr [0x1000c1a0] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x30u))); /* fmul dword ptr [esi + 0x30] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ebx))); /* fadd dword ptr [ebx] */
    WF32((uint32_t)(c->edi), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xcdc1d4u))); /* fmul dword ptr [0x1000c1d4] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0xcdc1a0u))); /* fsub dword ptr [0x1000c1a0] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x30u))); /* fmul dword ptr [esi + 0x30] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x20u))); /* fadd dword ptr [esi + 0x20] */
    WF32((uint32_t)(c->edi + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    c->eax = (uint32_t)((uint32_t)0x57619f1u); /* mov eax, 0x57619f1 */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 8)); /* shl ecx, 8 */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)c->ecx; c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = r_ != (int32_t)r_; } /* imul ecx */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    c->edx = (uint32_t)(sar32(c, c->edx, 6)); /* sar edx, 6 */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 31)); /* shr ecx, 0x1f */
    c->edx = (uint32_t)(add32(c, c->edx, c->ecx)); /* add edx, ecx */
    c->edx = (uint32_t)(shl32(c, c->edx, 24)); /* shl edx, 0x18 */
    (void)logic32(c, (uint32_t)(c->ebp & c->ebp)); /* test ebp, ebp */
    W32((uint32_t)(c->edi + 0xcu), (uint32_t)(c->edx)); /* mov dword ptr [edi + 0xc], edx */
    if ((c->zf || c->sf != c->of)) goto L_00cd2ade; /* jle 0xcd2ade */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4cu))); /* mov eax, dword ptr [esp + 0x4c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_00cd2ade; /* jle 0xcd2ade */
    (void)sub32(c, c->ebp, (uint32_t)0xau); /* cmp ebp, 0xa */
    if ((c->sf == c->of)) goto L_00cd2ade; /* jge 0xcd2ade */
    (void)sub32(c, c->eax, (uint32_t)0xau); /* cmp eax, 0xa */
    if ((c->sf == c->of)) goto L_00cd2ade; /* jge 0xcd2ade */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x2cu))); /* fld dword ptr [esp + 0x2c] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esi + 0x20u))); /* fsub dword ptr [esi + 0x20] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x24u))); /* fld dword ptr [esp + 0x24] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->ebx))); /* fsub dword ptr [ebx] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    { double v_ = ST(2); FPUSH(c, v_); } /* fld st(2) */
    ST(0) = FPRES(c, ST(0) * ST(3)); /* fmul st(3) */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, sqrt(ST(0))); /* fsqrt  */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edx, dword ptr [esp + 0x14] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, (double)RF32((uint32_t)(0xcdc1e0u))); /* fld dword ptr [0x1000c1e0] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x14u))); /* fsub dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xcdc1dcu))); /* fmul dword ptr [0x1000c1dc] */
    WF32((uint32_t)(c->esp), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd2accu); f_00cd27b0(c); /* call 0xcd27b0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov ecx, dword ptr [esp + 0x24] */
    W32((uint32_t)(c->edi), (uint32_t)(c->ecx)); /* mov dword ptr [edi], ecx */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x30u))); /* fmul dword ptr [esi + 0x30] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fadd dword ptr [esp + 0x1c] */
    WF32((uint32_t)(c->edi + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + 4] */
    goto L_00cd2aeb; /* jmp 0xcd2aeb */
L_00cd2ade:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov eax, dword ptr [esp + 0x24] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov ecx, dword ptr [esp + 0x1c] */
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    W32((uint32_t)(c->edi + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [edi + 4], ecx */
L_00cd2aeb:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov edx, dword ptr [esp + 0x2c] */
    W32((uint32_t)(c->edi + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [edi + 8], edx */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x18u)); /* add edi, 0x18 */
    c->ebp = (uint32_t)(inc32(c, c->ebp)); /* inc ebp */
    (void)sub32(c, c->ebp, (uint32_t)0xbu); /* cmp ebp, 0xb */
    W32((uint32_t)(c->esp + 0x54u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0x54], ebp */
    if ((c->sf != c->of)) goto L_00cd2993; /* jl 0xcd2993 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4cu))); /* mov eax, dword ptr [esp + 0x4c] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub32(c, c->eax, (uint32_t)0xbu); /* cmp eax, 0xb */
    W32((uint32_t)(c->esp + 0x4cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x4c], eax */
    if ((c->sf != c->of)) goto L_00cd2969; /* jl 0xcd2969 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
L_00cd2b17:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x38u)); /* add esp, 0x38 */
    c->esp += 16; return; /* ret 0xc */
}

void f_00cd2b20(CPU *c) { /* PTR_00cd2b20 */
    PREEMPT_POLL(c);
    c->esp += 4; return; /* ret  */
}

void f_00cd2b30(CPU *c) { /* PTR_00cd2b30 */
    PREEMPT_POLL(c);
    c->esp += 4; return; /* ret  */
}

void f_00cd2b40(CPU *c) { /* FUN_10002b40 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0x8u))); /* mov al, byte ptr [ecx + 8] */
    c->esp += 4; return; /* ret  */
}

void f_00cd2b50(CPU *c) { /* FUN_10002b50 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W32((uint32_t)(c->ecx + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 0x10], eax */
    W8((uint32_t)(c->ecx + 0x8u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ecx + 8], al */
    c->esp += 12; return; /* ret 8 */
}

void f_00cd2b60(CPU *c) { /* FUN_10002b60 */
    PREEMPT_POLL(c);
    c->esp += 8; return; /* ret 4 */
}

void f_00cd2b70(CPU *c) { /* _rand */
    PREEMPT_POLL(c);
    PUSH32(c, 0x00cd2b75u); f_00cd3480(c); /* call 0xcd3480 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x14u))); /* mov ecx, dword ptr [eax + 0x14] */
    { int64_t r_ = (int64_t)(int32_t)c->ecx * (int32_t)(uint32_t)0x343fdu; c->ecx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul ecx, ecx, 0x343fd */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x269ec3u)); /* add ecx, 0x269ec3 */
    W32((uint32_t)(c->eax + 0x14u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x14], ecx */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->eax = (uint32_t)(shr32(c, c->eax, 16)); /* shr eax, 0x10 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fffu))); /* and eax, 0x7fff */
    c->esp += 4; return; /* ret  */
}

void f_00cd2b92(CPU *c) { /* FUN_10002b92 */
    PREEMPT_POLL(c);
    PUSH32(c, 0x00cd2b97u); f_00cd2baa(c); /* call 0xcd2baa */
    PUSH32(c, 0x00cd2b9cu); f_00cd35d7(c); /* call 0xcd35d7 */
    W32((uint32_t)(0xce0474u), (uint32_t)(c->eax)); /* mov dword ptr [0x10010474], eax */
    PUSH32(c, 0x00cd2ba6u); f_00cd3587(c); /* call 0xcd3587 */
    c->fpu_sw &= 0x7f00; /* fnclex  */
    c->esp += 4; return; /* ret  */
}

void f_00cd2ba9(CPU *c) { /* PTR_00cd2ba9 */
    PREEMPT_POLL(c);
    c->esp += 4; return; /* ret  */
}

void f_00cd2baa(CPU *c) { /* FUN_10002baa */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xcd39b0u); /* mov eax, 0x100039b0 */
    W32((uint32_t)(0xcdd20cu), (uint32_t)((uint32_t)0xcd365au)); /* mov dword ptr [0x1000d20c], 0x1000365a */
    W32((uint32_t)(0xcdd208u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000d208], eax */
    W32((uint32_t)(0xcdd210u), (uint32_t)((uint32_t)0xcd36c0u)); /* mov dword ptr [0x1000d210], 0x100036c0 */
    W32((uint32_t)(0xcdd214u), (uint32_t)((uint32_t)0xcd3600u)); /* mov dword ptr [0x1000d214], 0x10003600 */
    W32((uint32_t)(0xcdd218u), (uint32_t)((uint32_t)0xcd36a8u)); /* mov dword ptr [0x1000d218], 0x100036a8 */
    W32((uint32_t)(0xcdd21cu), (uint32_t)(c->eax)); /* mov dword ptr [0x1000d21c], eax */
    c->esp += 4; return; /* ret  */
}

void f_00cd2be2(CPU *c) { /* FUN_10002be2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xcu)); /* add eax, 0xc */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->ebx = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov ebx, dword ptr fs:[0] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->eax)); /* mov dword ptr fs:[0], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ebx, dword ptr [ebp + 0xc] */
    c->esp = (uint32_t)(R32((uint32_t)(c->ebx + 0xfffffffcu))); /* mov esp, dword ptr [ebx - 4] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ebp, dword ptr [ebp - 4] */
    { uint32_t t_ = c->eax; switch (t_) {  default: jump_indirect(c, t_, 0x00cd2c0du); return; } } /* jmp eax */
}

void f_00cd2c0f(CPU *c) { /* PTR_00cd2c0f */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 12; return; /* ret 8 */
}

void f_00cd2c16(CPU *c) { /* FUN_10002c16 */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { guest_lock(); { uint32_t t0_ = R32((uint32_t)(c->esp)), t1_ = c->eax; W32((uint32_t)(c->esp), (uint32_t)(t1_)); c->eax = (uint32_t)(t0_); } guest_unlock(); } /* xchg dword ptr [esp], eax */
    { uint32_t t_ = c->eax; switch (t_) {  default: jump_indirect(c, t_, 0x00cd2c1bu); return; } } /* jmp eax */
}

void f_00cd2c1d(CPU *c) { /* FUN_10002c1d */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { guest_lock(); { uint32_t t0_ = R32((uint32_t)(c->esp)), t1_ = c->eax; W32((uint32_t)(c->esp), (uint32_t)(t1_)); c->eax = (uint32_t)(t0_); } guest_unlock(); } /* xchg dword ptr [esp], eax */
    { uint32_t t_ = c->eax; switch (t_) {  default: jump_indirect(c, t_, 0x00cd2c22u); return; } } /* jmp eax */
}

void f_00cd2c24(CPU *c) { /* FUN_10002c24 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0xcd2c4cu)); /* mov dword ptr [ebp - 4], 0x10002c4c */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00cd2c4cu); f_00cdb4b6(c); /* call 0xcdb4b6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov eax, dword ptr [eax + 4] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfdu))); /* and al, 0xfd */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ebx, dword ptr [ebp - 8] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ebx)); /* mov dword ptr fs:[0], ebx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 12; return; /* ret 8 */
}

void f_00cd2c4c(CPU *c) { /* PTR_00cd2c4c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov eax, dword ptr [eax + 4] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfdu))); /* and al, 0xfd */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ebx, dword ptr [ebp - 8] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ebx)); /* mov dword ptr fs:[0], ebx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 12; return; /* ret 8 */
}

void f_00cd2c73(CPU *c) { /* FUN_10002c73 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x4u)); /* sub esp, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->df = 0; /* cld  */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00cd2c99u); f_00cd3ca4(c); /* call 0xcd3ca4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    W32((uint32_t)(c->ebp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x14], eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00cd2ca9(CPU *c) { /* FUN_10002ca9 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x14u)); /* sub esp, 0x14 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffecu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x14], 0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)((uint32_t)0xcd2cfdu)); /* mov dword ptr [ebp - 0x10], 0x10002cfd */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x14], eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea eax, [ebp - 0x14] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->eax)); /* mov dword ptr fs:[0], eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    PUSH32(c, 0x00cd2ceeu); f_00cd44b0(c); /* call 0xcd44b0 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->eax)); /* mov dword ptr fs:[0], eax */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd2cfd(CPU *c) { /* FUN_10002cfd */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->df = 0; /* cld  */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->eax + 0x10u)); PUSH32(c, v_); } /* push dword ptr [eax + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, v_); } /* push dword ptr [eax + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->eax + 0xcu)); PUSH32(c, v_); } /* push dword ptr [eax + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00cd2d1du); f_00cd3ca4(c); /* call 0xcd3ca4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00cd2d22(CPU *c) { /* FUN_10002d22 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x34u)); /* sub esp, 0x34 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffd8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x28], 0 */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)((uint32_t)0xcd2dd8u)); /* mov dword ptr [ebp - 0x24], 0x10002dd8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov eax, dword ptr [ebp + 0x18] */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov eax, dword ptr [ebp + 0x1c] */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x18], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x20u))); /* mov eax, dword ptr [ebp + 0x20] */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x14], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff0u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x10], 0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0xc], 0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 8], 0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)((uint32_t)0xcd2daau)); /* mov dword ptr [ebp - 0x10], 0x10002daa */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0xc], esp */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ebp)); /* mov dword ptr [ebp - 8], ebp */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x28], eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd8u)); /* lea eax, [ebp - 0x28] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->eax)); /* mov dword ptr fs:[0], eax */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x34], 1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x30], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x2c], eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd0u)); /* lea eax, [ebp - 0x30] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->eax)); PUSH32(c, v_); } /* push dword ptr [eax] */
    PUSH32(c, 0x00cd2da1u); f_00cd3480(c); /* call 0xcd3480 */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x68u)); PUSH32(c, 0x00cd2da4u); call_indirect(c, t_); } /* call dword ptr [eax + 0x68] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffccu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x34], 0 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if (c->zf) goto L_00cd2dc7; /* je 0xcd2dc7 */
    c->ebx = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov ebx, dword ptr fs:[0] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ebx, dword ptr [ebp - 0x28] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ebx)); /* mov dword ptr fs:[0], ebx */
    goto L_00cd2dd0; /* jmp 0xcd2dd0 */
L_00cd2dc7:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->eax)); /* mov dword ptr fs:[0], eax */
L_00cd2dd0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffccu))); /* mov eax, dword ptr [ebp - 0x34] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd2daa(CPU *c) { /* PTR_00cd2daa */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if (c->zf) goto L_00cd2dc7; /* je 0xcd2dc7 */
    c->ebx = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov ebx, dword ptr fs:[0] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ebx, dword ptr [ebp - 0x28] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ebx)); /* mov dword ptr fs:[0], ebx */
    goto L_00cd2dd0; /* jmp 0xcd2dd0 */
L_00cd2dc7:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->eax)); /* mov dword ptr fs:[0], eax */
L_00cd2dd0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffccu))); /* mov eax, dword ptr [ebp - 0x34] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd2dd8(CPU *c) { /* FUN_10002dd8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->df = 0; /* cld  */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov eax, dword ptr [eax + 4] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x66u))); /* and eax, 0x66 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd2dfb; /* je 0xcd2dfb */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->eax + 0x24u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [eax + 0x24], 1 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_00cd2e48; /* jmp 0xcd2e48 */
L_00cd2dfb:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, v_); } /* push dword ptr [eax + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->eax + 0x10u)); PUSH32(c, v_); } /* push dword ptr [eax + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, v_); } /* push dword ptr [eax + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->eax + 0xcu)); PUSH32(c, v_); } /* push dword ptr [eax + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00cd2e22u); f_00cd3ca4(c); /* call 0xcd3ca4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x24u)), (uint32_t)0x0u); /* cmp dword ptr [eax + 0x24], 0 */
    if (!c->zf) goto L_00cd2e39; /* jne 0xcd2e39 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x00cd2e39u); f_00cd2c24(c); /* call 0xcd2c24 */
L_00cd2e39:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ebx, dword ptr [ebp + 0xc] */
    c->esp = (uint32_t)(R32((uint32_t)(c->ebx + 0x1cu))); /* mov esp, dword ptr [ebx + 0x1c] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ebx + 0x20u))); /* mov ebp, dword ptr [ebx + 0x20] */
    { uint32_t t_ = R32((uint32_t)(c->ebx + 0x18u)); switch (t_) {  default: jump_indirect(c, t_, 0x00cd2e42u); return; } } /* jmp dword ptr [ebx + 0x18] */
L_00cd2e48:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00cd2e4d(CPU *c) { /* FUN_10002e4d */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->edi + 0xcu))); /* mov esi, dword ptr [edi + 0xc] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->edi + 0x10u))); /* mov ebx, dword ptr [edi + 0x10] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    if ((c->sf != c->of)) goto L_00cd2ea4; /* jl 0xcd2ea4 */
L_00cd2e6b:;
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (!c->zf) goto L_00cd2e75; /* jne 0xcd2e75 */
    PUSH32(c, 0x00cd2e75u); f_00cd455d(c); /* call 0xcd455d */
L_00cd2e75:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi * 4)); /* lea eax, [esi + esi*4] */
    (void)sub32(c, R32((uint32_t)(c->ebx + c->eax * 4 + 0x4u)), c->ecx); /* cmp dword ptr [ebx + eax*4 + 4], ecx */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->eax * 4)); /* lea eax, [ebx + eax*4] */
    if ((c->sf == c->of)) goto L_00cd2e8a; /* jge 0xcd2e8a */
    (void)sub32(c, c->ecx, R32((uint32_t)(c->eax + 0x8u))); /* cmp ecx, dword ptr [eax + 8] */
    if ((c->zf || c->sf != c->of)) goto L_00cd2e8f; /* jle 0xcd2e8f */
L_00cd2e8a:;
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (!c->zf) goto L_00cd2e9b; /* jne 0xcd2e9b */
L_00cd2e8f:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
L_00cd2e9b:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    if ((c->sf == c->of)) goto L_00cd2e6b; /* jge 0xcd2e6b */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
L_00cd2ea4:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov ecx, dword ptr [ebp + 0x14] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    W32((uint32_t)(c->ecx), (uint32_t)(c->esi)); /* mov dword ptr [ecx], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov ecx, dword ptr [ebp + 0x18] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    (void)sub32(c, c->eax, R32((uint32_t)(c->edi + 0xcu))); /* cmp eax, dword ptr [edi + 0xc] */
    if ((!c->cf && !c->zf)) goto L_00cd2eb8; /* ja 0xcd2eb8 */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if ((c->cf || c->zf)) goto L_00cd2ebd; /* jbe 0xcd2ebd */
L_00cd2eb8:;
    PUSH32(c, 0x00cd2ebdu); f_00cd455d(c); /* call 0xcd455d */
L_00cd2ebd:;
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi * 4)); /* lea eax, [esi + esi*4] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->eax * 4)); /* lea eax, [ebx + eax*4] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd2ec8(CPU *c) { /* __global_unwind2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0xcd2ee0u; PUSH32(c, v_); } /* push 0x10002ee0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00cd2ee0u); f_00cdb4b6(c); /* call 0xcdb4b6 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00cd2ee0(CPU *c) { /* PTR_00cd2ee0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00cd2ee8(CPU *c) { /* PTR_00cd2ee8 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->ecx + 0x4u)) & (uint32_t)0x6u)); /* test dword ptr [ecx + 4], 6 */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    if (c->zf) goto L_00cd2f09; /* je 0xcd2f09 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    W32((uint32_t)(c->edx), (uint32_t)(c->eax)); /* mov dword ptr [edx], eax */
    c->eax = (uint32_t)((uint32_t)0x3u); /* mov eax, 3 */
L_00cd2f09:;
    c->esp += 4; return; /* ret  */
}

void f_00cd2f0a(CPU *c) { /* __local_unwind2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0xfffffffeu; PUSH32(c, v_); } /* push -2 */
    { uint32_t v_ = 0xcd2ee8u; PUSH32(c, v_); } /* push 0x10002ee8 */
    { uint32_t v_ = R32((uint32_t)(0x0u + c->fs_base)); PUSH32(c, v_); } /* push dword ptr fs:[0] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
L_00cd2f27:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov eax, dword ptr [esp + 0x20] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ebx, dword ptr [eax + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + 0xcu))); /* mov esi, dword ptr [eax + 0xc] */
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (c->zf) goto L_00cd2f64; /* je 0xcd2f64 */
    (void)sub32(c, c->esi, R32((uint32_t)(c->esp + 0x24u))); /* cmp esi, dword ptr [esp + 0x24] */
    if (c->zf) goto L_00cd2f64; /* je 0xcd2f64 */
    c->esi = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea esi, [esi + esi*2] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + c->esi * 4))); /* mov ecx, dword ptr [ebx + esi*4] */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 8], ecx */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0xc], ecx */
    (void)sub32(c, R32((uint32_t)(c->ebx + c->esi * 4 + 0x4u)), (uint32_t)0x0u); /* cmp dword ptr [ebx + esi*4 + 4], 0 */
    if (!c->zf) goto L_00cd2f62; /* jne 0xcd2f62 */
    { uint32_t v_ = 0x101u; PUSH32(c, v_); } /* push 0x101 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + c->esi * 4 + 0x8u))); /* mov eax, dword ptr [ebx + esi*4 + 8] */
    PUSH32(c, 0x00cd2f5eu); f_00cd2f9e(c); /* call 0xcd2f9e */
    { uint32_t t_ = R32((uint32_t)(c->ebx + c->esi * 4 + 0x8u)); PUSH32(c, 0x00cd2f62u); call_indirect(c, t_); } /* call dword ptr [ebx + esi*4 + 8] */
L_00cd2f62:;
    goto L_00cd2f27; /* jmp 0xcd2f27 */
L_00cd2f64:;
    { uint32_t v_ = R32(c->esp); c->esp += 4; W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(v_)); } /* pop dword ptr fs:[0] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00cd2f72(CPU *c) { /* __abnormal_termination */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov ecx, dword ptr fs:[0] */
    (void)sub32(c, R32((uint32_t)(c->ecx + 0x4u)), (uint32_t)0xcd2ee8u); /* cmp dword ptr [ecx + 4], 0x10002ee8 */
    if (!c->zf) goto L_00cd2f94; /* jne 0xcd2f94 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov edx, dword ptr [ecx + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edx + 0xcu))); /* mov edx, dword ptr [edx + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->ecx + 0x8u)), c->edx); /* cmp dword ptr [ecx + 8], edx */
    if (!c->zf) goto L_00cd2f94; /* jne 0xcd2f94 */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
L_00cd2f94:;
    c->esp += 4; return; /* ret  */
}

void f_00cd2f95(CPU *c) { /* __NLG_Notify1 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ebx = (uint32_t)((uint32_t)0xcdd198u); /* mov ebx, 0x1000d198 */
    { f_00cd2fa8(c); return; } /* jmp 0xcd2fa8 */
}

void f_00cd2f9e(CPU *c) { /* FUN_10002f9e */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ebx = (uint32_t)((uint32_t)0xcdd198u); /* mov ebx, 0x1000d198 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebx + 8], ecx */
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 4], eax */
    W32((uint32_t)(c->ebx + 0xcu), (uint32_t)(c->ebp)); /* mov dword ptr [ebx + 0xc], ebp */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
}

void f_00cd2fa8(CPU *c) { /* PTR_00cd2fa8 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebx + 8], ecx */
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 4], eax */
    W32((uint32_t)(c->ebx + 0xcu), (uint32_t)(c->ebp)); /* mov dword ptr [ebx + 0xc], ebp */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
}

void f_00cd2fb8(CPU *c) { /* __ftol */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xfffffff4u)); /* add esp, -0xc */
    ; /* wait  */
    W16((uint32_t)(c->ebp + 0xfffffffeu), c->fpu_cw); /* fnstcw word ptr [ebp - 2] */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ebp + 0xfffffffeu))); /* mov ax, word ptr [ebp - 2] */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | (uint8_t)0xcu))) << 8); /* or ah, 0xc */
    W16((uint32_t)(c->ebp + 0xfffffffcu), (uint16_t)(((uint16_t)c->eax))); /* mov word ptr [ebp - 4], ax */
    c->fpu_cw = R16((uint32_t)(c->ebp + 0xfffffffcu)); fpu_sync_rounding(c); /* fldcw word ptr [ebp - 4] */
    W64((uint32_t)(c->ebp + 0xfffffff4u), (uint64_t)fpu_to_int64(c, ST(0))); FPOP(c); /* fistp qword ptr [ebp - 0xc] */
    c->fpu_cw = R16((uint32_t)(c->ebp + 0xfffffffeu)); fpu_sync_rounding(c); /* fldcw word ptr [ebp - 2] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov edx, dword ptr [ebp - 8] */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd2fdf(CPU *c) { /* FUN_10002fdf */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd2fe5u); f_00cd483d(c); /* call 0xcd483d */
    { uint32_t v_ = R32((uint32_t)(0xce0b70u)); PUSH32(c, v_); } /* push dword ptr [0x10010b70] */
    PUSH32(c, 0x00cd2ff0u); f_00cd4b98(c); /* call 0xcd4b98 */
    c->edx = (uint32_t)(R32((uint32_t)(0xce0b70u))); /* mov edx, dword ptr [0x10010b70] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(0xce0b6cu))); /* mov ecx, dword ptr [0x10010b6c] */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->esi = (uint32_t)(sub32(c, c->esi, c->edx)); /* sub esi, edx */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (!c->cf) goto L_00cd3045; /* jae 0xcd3045 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00cd300eu); f_00cd4b98(c); /* call 0xcd4b98 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x10u)); /* add eax, 0x10 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(0xce0b70u)); PUSH32(c, v_); } /* push dword ptr [0x10010b70] */
    PUSH32(c, 0x00cd301du); f_00cd4869(c); /* call 0xcd4869 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00cd3028; /* jne 0xcd3028 */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    goto L_00cd3054; /* jmp 0xcd3054 */
L_00cd3028:;
    c->ecx = (uint32_t)(R32((uint32_t)(0xce0b6cu))); /* mov ecx, dword ptr [0x10010b6c] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, R32((uint32_t)(0xce0b70u)))); /* sub ecx, dword ptr [0x10010b70] */
    W32((uint32_t)(0xce0b70u), (uint32_t)(c->eax)); /* mov dword ptr [0x10010b70], eax */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 2)); /* sar ecx, 2 */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->ecx * 4)); /* lea ecx, [eax + ecx*4] */
    W32((uint32_t)(0xce0b6cu), (uint32_t)(c->ecx)); /* mov dword ptr [0x10010b6c], ecx */
L_00cd3045:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    { uint32_t a_ = (uint32_t)(0xce0b6cu); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x4u))); } /* add dword ptr [0x10010b6c], 4 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_00cd3054:;
    PUSH32(c, 0x00cd3059u); f_00cd4846(c); /* call 0xcd4846 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00cd305d(CPU *c) { /* FUN_1000305d */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    PUSH32(c, 0x00cd3066u); f_00cd2fdf(c); /* call 0xcd2fdf */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->esp += 4; return; /* ret  */
}

void f_00cd306f(CPU *c) { /* PTR_00cd306f */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x80u; PUSH32(c, v_); } /* push 0x80 */
    PUSH32(c, 0x00cd3079u); f_00cd4c86(c); /* call 0xcd4c86 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(0xce0b70u), (uint32_t)(c->eax)); /* mov dword ptr [0x10010b70], eax */
    if (!c->zf) goto L_00cd3090; /* jne 0xcd3090 */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    PUSH32(c, 0x00cd308au); f_00cd33c8(c); /* call 0xcd33c8 */
    c->eax = (uint32_t)(R32((uint32_t)(0xce0b70u))); /* mov eax, dword ptr [0x10010b70] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00cd3090:;
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [eax], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(0xce0b70u))); /* mov eax, dword ptr [0x10010b70] */
    W32((uint32_t)(0xce0b6cu), (uint32_t)(c->eax)); /* mov dword ptr [0x10010b6c], eax */
    c->esp += 4; return; /* ret  */
}

void f_00cd309e(CPU *c) { /* FUN_1000309e */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xcdc218u; PUSH32(c, v_); } /* push 0x1000c218 */
    { uint32_t v_ = 0xcd4dc8u; PUSH32(c, v_); } /* push 0x10004dc8 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x10u)); /* sub esp, 0x10 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
L_00cd30cc:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0x10u))); /* cmp eax, dword ptr [ebp + 0x10] */
    if ((c->sf == c->of)) goto L_00cd30e7; /* jge 0xcd30e7 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, 0x00cd30dcu); call_indirect(c, t_); } /* call dword ptr [ebp + 0x14] */
    c->esi = (uint32_t)(add32(c, c->esi, R32((uint32_t)(c->ebp + 0xcu)))); /* add esi, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe4u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0x1c] */
    goto L_00cd30cc; /* jmp 0xcd30cc */
L_00cd30e7:;
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x20], 1 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00cd30f7u); f_00cd3108(c); /* call 0xcd3108 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 24; return; /* ret 0x14 */
}

void f_00cd3108(CPU *c) { /* FUN_10003108 */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x20], 0 */
    if (!c->zf) goto L_00cd311f; /* jne 0xcd311f */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00cd311fu); f_00cd31a0(c); /* call 0xcd31a0 */
L_00cd311f:;
    c->esp += 4; return; /* ret  */
}

void f_00cd3120(CPU *c) { /* FUN_10003120 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xcdc228u; PUSH32(c, v_); } /* push 0x1000c228 */
    { uint32_t v_ = 0xcd4dc8u; PUSH32(c, v_); } /* push 0x10004dc8 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x1c], 0 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)R32((uint32_t)(c->ebp + 0x10u)); c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, dword ptr [ebp + 0x10] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(add32(c, R32(a_), c->eax))); } /* add dword ptr [ebp + 8], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
L_00cd3157:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0x10u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 0x10] */
    if (c->sf) goto L_00cd3167; /* js 0xcd3167 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(sub32(c, R32(a_), c->esi))); } /* sub dword ptr [ebp + 8], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, 0x00cd3165u); call_indirect(c, t_); } /* call dword ptr [ebp + 0x14] */
    goto L_00cd3157; /* jmp 0xcd3157 */
L_00cd3167:;
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x1c], 1 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00cd3177u); f_00cd3188(c); /* call 0xcd3188 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 20; return; /* ret 0x10 */
}

void f_00cd3188(CPU *c) { /* FUN_10003188 */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x1c], 0 */
    if (!c->zf) goto L_00cd319f; /* jne 0xcd319f */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00cd319fu); f_00cd31a0(c); /* call 0xcd31a0 */
L_00cd319f:;
    c->esp += 4; return; /* ret  */
}

void f_00cd31a0(CPU *c) { /* FUN_100031a0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xcdc238u; PUSH32(c, v_); } /* push 0x1000c238 */
    { uint32_t v_ = 0xcd4dc8u; PUSH32(c, v_); } /* push 0x10004dc8 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
L_00cd31c9:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0x10u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 0x10] */
    if (c->sf) goto L_00cd31e9; /* js 0xcd31e9 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, R32((uint32_t)(c->ebp + 0xcu)))); /* sub ecx, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp + 8], ecx */
    { uint32_t t_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, 0x00cd31dau); call_indirect(c, t_); } /* call dword ptr [ebp + 0x14] */
    goto L_00cd31c9; /* jmp 0xcd31c9 */
L_00cd31e9:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 20; return; /* ret 0x10 */
}

void f_00cd31dc(CPU *c) { /* PTR_00cd31dc */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffecu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x14] */
    PUSH32(c, 0x00cd31e4u); f_00cd31fe(c); /* call 0xcd31fe */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00cd31e6(CPU *c) { /* PTR_00cd31e6 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 20; return; /* ret 0x10 */
}

void f_00cd31fe(CPU *c) { /* FUN_100031fe */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xe06d7363u); /* cmp dword ptr [eax], 0xe06d7363 */
    if (c->zf) goto L_00cd320f; /* je 0xcd320f */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_00cd320f:;
    { f_00cd44fc(c); return; } /* jmp 0xcd44fc */
}

void f_00cd3220(CPU *c) { /* PTR_00cd3220 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)((uint32_t)0xcdd1b0u); /* mov edx, 0x1000d1b0 */
    { f_00cd4f1b(c); return; } /* jmp 0xcd4f1b */
}

void f_00cd322a(CPU *c) { /* FUN_1000322a */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)((uint32_t)0xcdd1b0u); /* mov edx, 0x1000d1b0 */
    { f_00cd4ea0(c); return; } /* jmp 0xcd4ea0 */
}

void f_00cd3234(CPU *c) { /* PTR_00cd3234 */
    PREEMPT_POLL(c);
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
L_00cd3236:;
    (void)sub32(c, R32((uint32_t)(0xce0474u)), (uint32_t)0x1u); /* cmp dword ptr [0x10010474], 1 */
    if (c->zf) goto L_00cd3243; /* je 0xcd3243 */
    ST(0) = fmod(ST(0), ST(1)); c->fpu_sw &= ~0x0400; /* fprem  */
    goto L_00cd3248; /* jmp 0xcd3248 */
L_00cd3243:;
    PUSH32(c, 0x00cd3248u); f_00cd5cec(c); /* call 0xcd5cec */
L_00cd3248:;
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    ; /* wait  */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (PF(c)) goto L_00cd3236; /* jp 0xcd3236 */
    ST(1) = ST(0); FPOP(c); /* fstp st(1) */
    c->esp += 4; return; /* ret  */
}

void f_00cd3252(CPU *c) { /* FUN_10003252 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_00cd32e7; /* jne 0xcd32e7 */
    { uint32_t t_ = R32((uint32_t)(0xcdc00cu)); PUSH32(c, 0x00cd3265u); call_indirect(c, t_); } /* call dword ptr [0x1000c00c] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    W32((uint32_t)(0xce04f8u), (uint32_t)(c->eax)); /* mov dword ptr [0x100104f8], eax */
    PUSH32(c, 0x00cd3271u); f_00cd6828(c); /* call 0xcd6828 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00cd32b2; /* je 0xcd32b2 */
    c->eax = (uint32_t)(R32((uint32_t)(0xce04f8u))); /* mov eax, dword ptr [0x100104f8] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0xce04f9u))); /* mov cl, byte ptr [0x100104f9] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xffu))); /* and eax, 0xff */
    { uint32_t a_ = (uint32_t)(0xce04f8u); W32(a_, (uint32_t)(shr32(c, R32(a_), 16))); } /* shr dword ptr [0x100104f8], 0x10 */
    W32((uint32_t)(0xce0500u), (uint32_t)(c->eax)); /* mov dword ptr [0x10010500], eax */
    W32((uint32_t)(0xce0504u), (uint32_t)(c->ecx)); /* mov dword ptr [0x10010504], ecx */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    W32((uint32_t)(0xce04fcu), (uint32_t)(c->eax)); /* mov dword ptr [0x100104fc], eax */
    PUSH32(c, 0x00cd32a9u); f_00cd33fb(c); /* call 0xcd33fb */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00cd32b6; /* jne 0xcd32b6 */
    PUSH32(c, 0x00cd32b2u); f_00cd6885(c); /* call 0xcd6885 */
L_00cd32b2:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00cd3328; /* jmp 0xcd3328 */
L_00cd32b6:;
    { uint32_t t_ = R32((uint32_t)(0xcdc008u)); PUSH32(c, 0x00cd32bcu); call_indirect(c, t_); } /* call dword ptr [0x1000c008] */
    W32((uint32_t)(0xce0b74u), (uint32_t)(c->eax)); /* mov dword ptr [0x10010b74], eax */
    PUSH32(c, 0x00cd32c6u); f_00cd6581(c); /* call 0xcd6581 */
    W32((uint32_t)(0xce047cu), (uint32_t)(c->eax)); /* mov dword ptr [0x1001047c], eax */
    PUSH32(c, 0x00cd32d0u); f_00cd606b(c); /* call 0xcd606b */
    PUSH32(c, 0x00cd32d5u); f_00cd6334(c); /* call 0xcd6334 */
    PUSH32(c, 0x00cd32dau); f_00cd627b(c); /* call 0xcd627b */
    PUSH32(c, 0x00cd32dfu); f_00cd474b(c); /* call 0xcd474b */
    { uint32_t a_ = (uint32_t)(0xce0478u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [0x10010478] */
    goto L_00cd3325; /* jmp 0xcd3325 */
L_00cd32e7:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->zf) goto L_00cd3319; /* jne 0xcd3319 */
    (void)sub32(c, R32((uint32_t)(0xce0478u)), c->ecx); /* cmp dword ptr [0x10010478], ecx */
    if ((c->zf || c->sf != c->of)) goto L_00cd32b2; /* jle 0xcd32b2 */
    { uint32_t a_ = (uint32_t)(0xce0478u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [0x10010478] */
    (void)sub32(c, R32((uint32_t)(0xce0530u)), c->ecx); /* cmp dword ptr [0x10010530], ecx */
    if (!c->zf) goto L_00cd3308; /* jne 0xcd3308 */
    PUSH32(c, 0x00cd3308u); f_00cd4789(c); /* call 0xcd4789 */
L_00cd3308:;
    PUSH32(c, 0x00cd330du); f_00cd6227(c); /* call 0xcd6227 */
    PUSH32(c, 0x00cd3312u); f_00cd344f(c); /* call 0xcd344f */
    PUSH32(c, 0x00cd3317u); f_00cd6885(c); /* call 0xcd6885 */
    goto L_00cd3325; /* jmp 0xcd3325 */
L_00cd3319:;
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_00cd3325; /* jne 0xcd3325 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00cd3324u); f_00cd34e7(c); /* call 0xcd34e7 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00cd3325:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00cd3328:;
    c->esp += 16; return; /* ret 0xc */
}

void f_00cd332b(CPU *c) { /* entry */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edi, dword ptr [ebp + 0x10] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_00cd3347; /* jne 0xcd3347 */
    (void)sub32(c, R32((uint32_t)(0xce0478u)), (uint32_t)0x0u); /* cmp dword ptr [0x10010478], 0 */
    goto L_00cd336d; /* jmp 0xcd336d */
L_00cd3347:;
    (void)sub32(c, c->esi, (uint32_t)0x1u); /* cmp esi, 1 */
    if (c->zf) goto L_00cd3351; /* je 0xcd3351 */
    (void)sub32(c, c->esi, (uint32_t)0x2u); /* cmp esi, 2 */
    if (!c->zf) goto L_00cd3373; /* jne 0xcd3373 */
L_00cd3351:;
    c->eax = (uint32_t)(R32((uint32_t)(0xce0b78u))); /* mov eax, dword ptr [0x10010b78] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd3363; /* je 0xcd3363 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00cd335fu); call_indirect(c, t_); } /* call eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd336f; /* je 0xcd336f */
L_00cd3363:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00cd336bu); f_00cd3252(c); /* call 0xcd3252 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
L_00cd336d:;
    if (!c->zf) goto L_00cd3373; /* jne 0xcd3373 */
L_00cd336f:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00cd33c1; /* jmp 0xcd33c1 */
L_00cd3373:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00cd337bu); f_00cd692d(c); /* call 0xcd692d */
    (void)sub32(c, c->esi, (uint32_t)0x1u); /* cmp esi, 1 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0xc], eax */
    if (!c->zf) goto L_00cd338f; /* jne 0xcd338f */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00cd33be; /* jne 0xcd33be */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00cd338fu); f_00cd3252(c); /* call 0xcd3252 */
L_00cd338f:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00cd3398; /* je 0xcd3398 */
    (void)sub32(c, c->esi, (uint32_t)0x3u); /* cmp esi, 3 */
    if (!c->zf) goto L_00cd33be; /* jne 0xcd33be */
L_00cd3398:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00cd33a0u); f_00cd3252(c); /* call 0xcd3252 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00cd33a7; /* jne 0xcd33a7 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->eax)))); } /* and dword ptr [ebp + 0xc], eax */
L_00cd33a7:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    if (c->zf) goto L_00cd33be; /* je 0xcd33be */
    c->eax = (uint32_t)(R32((uint32_t)(0xce0b78u))); /* mov eax, dword ptr [0x10010b78] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd33be; /* je 0xcd33be */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00cd33bbu); call_indirect(c, t_); } /* call eax */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0xc], eax */
L_00cd33be:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
L_00cd33c1:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 16; return; /* ret 0xc */
}

void f_00cd33c8(CPU *c) { /* __amsg_exit */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0xce0484u))); /* mov eax, dword ptr [0x10010484] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_00cd33df; /* je 0xcd33df */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00cd33e4; /* jne 0xcd33e4 */
    (void)sub32(c, R32((uint32_t)(0xce0488u)), (uint32_t)0x1u); /* cmp dword ptr [0x10010488], 1 */
    if (!c->zf) goto L_00cd33e4; /* jne 0xcd33e4 */
L_00cd33df:;
    PUSH32(c, 0x00cd33e4u); f_00cd6933(c); /* call 0xcd6933 */
L_00cd33e4:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    PUSH32(c, 0x00cd33edu); f_00cd696c(c); /* call 0xcd696c */
    { uint32_t v_ = 0xffu; PUSH32(c, v_); } /* push 0xff */
    { uint32_t t_ = R32((uint32_t)(0xcdd200u)); PUSH32(c, 0x00cd33f8u); call_indirect(c, t_); } /* call dword ptr [0x1000d200] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00cd33f8(CPU *c) { /* PTR_00cd33f8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00cd33fb(CPU *c) { /* FUN_100033fb */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd3401u); f_00cd3a26(c); /* call 0xcd3a26 */
    { uint32_t t_ = R32((uint32_t)(0xcdc018u)); PUSH32(c, 0x00cd3407u); call_indirect(c, t_); } /* call dword ptr [0x1000c018] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    W32((uint32_t)(0xcdd204u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000d204], eax */
    if (c->zf) goto L_00cd344b; /* je 0xcd344b */
    { uint32_t v_ = 0x74u; PUSH32(c, v_); } /* push 0x74 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x00cd341au); f_00cd6abf(c); /* call 0xcd6abf */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00cd344b; /* je 0xcd344b */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(0xcdd204u)); PUSH32(c, v_); } /* push dword ptr [0x1000d204] */
    { uint32_t t_ = R32((uint32_t)(0xcdc014u)); PUSH32(c, 0x00cd342fu); call_indirect(c, t_); } /* call dword ptr [0x1000c014] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd344b; /* je 0xcd344b */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd3439u); f_00cd346d(c); /* call 0xcd346d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t t_ = R32((uint32_t)(0xcdc010u)); PUSH32(c, 0x00cd3440u); call_indirect(c, t_); } /* call dword ptr [0x1000c010] */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [esi + 4], 0xffffffff */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_00cd344b:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00cd344f(CPU *c) { /* FUN_1000344f */
    PREEMPT_POLL(c);
    PUSH32(c, 0x00cd3454u); f_00cd3a4f(c); /* call 0xcd3a4f */
    c->eax = (uint32_t)(R32((uint32_t)(0xcdd204u))); /* mov eax, dword ptr [0x1000d204] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (c->zf) goto L_00cd346c; /* je 0xcd346c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0xcdc01cu)); PUSH32(c, 0x00cd3465u); call_indirect(c, t_); } /* call dword ptr [0x1000c01c] */
    { uint32_t a_ = (uint32_t)(0xcdd204u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [0x1000d204], 0xffffffff */
L_00cd346c:;
    c->esp += 4; return; /* ret  */
}

void f_00cd346d(CPU *c) { /* FUN_1000346d */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    W32((uint32_t)(c->eax + 0x50u), (uint32_t)((uint32_t)0xcdd758u)); /* mov dword ptr [eax + 0x50], 0x1000d758 */
    W32((uint32_t)(c->eax + 0x14u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [eax + 0x14], 1 */
    c->esp += 4; return; /* ret  */
}

void f_00cd3480(CPU *c) { /* FUN_10003480 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0xcdc028u)); PUSH32(c, 0x00cd3488u); call_indirect(c, t_); } /* call dword ptr [0x1000c028] */
    { uint32_t v_ = R32((uint32_t)(0xcdd204u)); PUSH32(c, v_); } /* push dword ptr [0x1000d204] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    { uint32_t t_ = R32((uint32_t)(0xcdc024u)); PUSH32(c, 0x00cd3496u); call_indirect(c, t_); } /* call dword ptr [0x1000c024] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_00cd34db; /* jne 0xcd34db */
    { uint32_t v_ = 0x74u; PUSH32(c, v_); } /* push 0x74 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x00cd34a5u); f_00cd6abf(c); /* call 0xcd6abf */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00cd34d3; /* je 0xcd34d3 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(0xcdd204u)); PUSH32(c, v_); } /* push dword ptr [0x1000d204] */
    { uint32_t t_ = R32((uint32_t)(0xcdc014u)); PUSH32(c, 0x00cd34bau); call_indirect(c, t_); } /* call dword ptr [0x1000c014] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd34d3; /* je 0xcd34d3 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd34c4u); f_00cd346d(c); /* call 0xcd346d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t t_ = R32((uint32_t)(0xcdc010u)); PUSH32(c, 0x00cd34cbu); call_indirect(c, t_); } /* call dword ptr [0x1000c010] */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [esi + 4], 0xffffffff */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    goto L_00cd34db; /* jmp 0xcd34db */
L_00cd34d3:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    PUSH32(c, 0x00cd34dau); f_00cd33c8(c); /* call 0xcd33c8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00cd34db:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0xcdc020u)); PUSH32(c, 0x00cd34e2u); call_indirect(c, t_); } /* call dword ptr [0x1000c020] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00cd34e7(CPU *c) { /* FUN_100034e7 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0xcdd204u))); /* mov eax, dword ptr [0x1000d204] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (c->zf) goto L_00cd3586; /* je 0xcd3586 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_00cd350b; /* jne 0xcd350b */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0xcdc024u)); PUSH32(c, 0x00cd3505u); call_indirect(c, t_); } /* call dword ptr [0x1000c024] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00cd3577; /* je 0xcd3577 */
L_00cd350b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov eax, dword ptr [esi + 0x24] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd3519; /* je 0xcd3519 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd3518u); f_00cd3b31(c); /* call 0xcd3b31 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00cd3519:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x28u))); /* mov eax, dword ptr [esi + 0x28] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd3527; /* je 0xcd3527 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd3526u); f_00cd3b31(c); /* call 0xcd3b31 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00cd3527:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x30u))); /* mov eax, dword ptr [esi + 0x30] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd3535; /* je 0xcd3535 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd3534u); f_00cd3b31(c); /* call 0xcd3b31 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00cd3535:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x38u))); /* mov eax, dword ptr [esi + 0x38] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd3543; /* je 0xcd3543 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd3542u); f_00cd3b31(c); /* call 0xcd3b31 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00cd3543:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x40u))); /* mov eax, dword ptr [esi + 0x40] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd3551; /* je 0xcd3551 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd3550u); f_00cd3b31(c); /* call 0xcd3b31 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00cd3551:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x44u))); /* mov eax, dword ptr [esi + 0x44] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd355f; /* je 0xcd355f */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd355eu); f_00cd3b31(c); /* call 0xcd3b31 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00cd355f:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    (void)sub32(c, c->eax, (uint32_t)0xcdd758u); /* cmp eax, 0x1000d758 */
    if (c->zf) goto L_00cd3570; /* je 0xcd3570 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd356fu); f_00cd3b31(c); /* call 0xcd3b31 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00cd3570:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd3576u); f_00cd3b31(c); /* call 0xcd3b31 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00cd3577:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xcdd204u)); PUSH32(c, v_); } /* push dword ptr [0x1000d204] */
    { uint32_t t_ = R32((uint32_t)(0xcdc014u)); PUSH32(c, 0x00cd3585u); call_indirect(c, t_); } /* call dword ptr [0x1000c014] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00cd3586:;
    c->esp += 4; return; /* ret  */
}

void f_00cd3587(CPU *c) { /* FUN_10003587 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x30000u; PUSH32(c, v_); } /* push 0x30000 */
    { uint32_t v_ = 0x10000u; PUSH32(c, v_); } /* push 0x10000 */
    PUSH32(c, 0x00cd3596u); f_00cd6c31(c); /* call 0xcd6c31 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00cd3599(CPU *c) { /* FUN_10003599 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    FPUSH(c, RF64((uint32_t)(0xcdc258u))); /* fld qword ptr [0x1000c258] */
    WF64((uint32_t)(c->ebp + 0xfffffff8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 8] */
    FPUSH(c, RF64((uint32_t)(0xcdc250u))); /* fld qword ptr [0x1000c250] */
    WF64((uint32_t)(c->ebp + 0xfffffff0u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0x10] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff0u))); /* fld qword ptr [ebp - 0x10] */
    ST(0) = FPRES(c, FDIV(c, ST(0), RF64((uint32_t)(c->ebp + 0xfffffff8u)))); /* fdiv qword ptr [ebp - 8] */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->ebp + 0xfffffff8u))); /* fmul qword ptr [ebp - 8] */
    ST(0) = FPRES(c, RF64((uint32_t)(c->ebp + 0xfffffff0u)) - ST(0)); /* fsubr qword ptr [ebp - 0x10] */
    WF64((uint32_t)(c->ebp + 0xffffffe8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0x18] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xffffffe8u))); /* fld qword ptr [ebp - 0x18] */
    FCOM(c, ST(0), RF64((uint32_t)(0xcdc248u))); FPOP(c); /* fcomp qword ptr [0x1000c248] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if ((c->cf || c->zf)) goto L_00cd35d3; /* jbe 0xcd35d3 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd35d3:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd35d7(CPU *c) { /* FUN_100035d7 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xcdc27cu; PUSH32(c, v_); } /* push 0x1000c27c */
    { uint32_t t_ = R32((uint32_t)(0xcdc030u)); PUSH32(c, 0x00cd35e2u); call_indirect(c, t_); } /* call dword ptr [0x1000c030] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd35fb; /* je 0xcd35fb */
    { uint32_t v_ = 0xcdc260u; PUSH32(c, v_); } /* push 0x1000c260 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0xcdc02cu)); PUSH32(c, 0x00cd35f2u); call_indirect(c, t_); } /* call dword ptr [0x1000c02c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd35fb; /* je 0xcd35fb */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00cd35fau); call_indirect(c, t_); } /* call eax */
    c->esp += 4; return; /* ret  */
L_00cd35fb:;
    { f_00cd3599(c); return; } /* jmp 0xcd3599 */
}

void f_00cd3600(CPU *c) { /* FUN_10003600 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->esi))); /* movsx eax, byte ptr [esi] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd360eu); f_00cd6d62(c); /* call 0xcd6d62 */
    (void)sub32(c, c->eax, (uint32_t)0x65u); /* cmp eax, 0x65 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00cd3640; /* je 0xcd3640 */
L_00cd3614:;
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub32(c, R32((uint32_t)(0xcdd500u)), (uint32_t)0x1u); /* cmp dword ptr [0x1000d500], 1 */
    if ((c->zf || c->sf != c->of)) goto L_00cd362d; /* jle 0xcd362d */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->esi))); /* movsx eax, byte ptr [esi] */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd3629u); f_00cd4617(c); /* call 0xcd4617 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00cd363c; /* jmp 0xcd363c */
L_00cd362d:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->esi))); /* movsx eax, byte ptr [esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(0xcdd2f4u))); /* mov ecx, dword ptr [0x1000d2f4] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4u))); /* and eax, 4 */
L_00cd363c:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00cd3614; /* jne 0xcd3614 */
L_00cd3640:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0xcdd504u))); /* mov cl, byte ptr [0x1000d504] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esi], cl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_00cd364b:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov cl, byte ptr [esi] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [esi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(((uint8_t)c->ecx)); /* mov al, cl */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov cl, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_00cd364b; /* jne 0xcd364b */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00cd365a(CPU *c) { /* PTR_00cd365a */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0xcdd504u))); /* mov dl, byte ptr [0x1000d504] */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_00cd3676; /* je 0xcd3676 */
L_00cd366a:;
    (void)sub8(c, ((uint8_t)c->ecx), ((uint8_t)c->edx)); /* cmp cl, dl */
    if (c->zf) goto L_00cd3676; /* je 0xcd3676 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1u))); /* mov cl, byte ptr [eax + 1] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_00cd366a; /* jne 0xcd366a */
L_00cd3676:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_00cd36a7; /* je 0xcd36a7 */
L_00cd367d:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_00cd3690; /* je 0xcd3690 */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x65u); /* cmp cl, 0x65 */
    if (c->zf) goto L_00cd3690; /* je 0xcd3690 */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x45u); /* cmp cl, 0x45 */
    if (c->zf) goto L_00cd3690; /* je 0xcd3690 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_00cd367d; /* jmp 0xcd367d */
L_00cd3690:;
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
L_00cd3692:;
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x30u); /* cmp byte ptr [eax], 0x30 */
    if (c->zf) goto L_00cd3692; /* je 0xcd3692 */
    (void)sub8(c, R8((uint32_t)(c->eax)), ((uint8_t)c->edx)); /* cmp byte ptr [eax], dl */
    if (!c->zf) goto L_00cd369d; /* jne 0xcd369d */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
L_00cd369d:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov dl, byte ptr [ecx] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [eax], dl */
    if (!c->zf) goto L_00cd369d; /* jne 0xcd369d */
L_00cd36a7:;
    c->esp += 4; return; /* ret  */
}

void f_00cd36a8(CPU *c) { /* PTR_00cd36a8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    FPUSH(c, RF64((uint32_t)(c->eax))); /* fld qword ptr [eax] */
    FCOM(c, ST(0), RF64((uint32_t)(0xcdc288u))); FPOP(c); /* fcomp qword ptr [0x1000c288] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (c->cf) goto L_00cd36bd; /* jb 0xcd36bd */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
L_00cd36bd:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_00cd36c0(CPU *c) { /* __fassign */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    if (c->zf) goto L_00cd36e9; /* je 0xcd36e9 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd36d7u); f_00cd722e(c); /* call 0xcd722e */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 4], ecx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd36e9:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd36f2u); f_00cd725b(c); /* call 0xcd725b */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd36fe(CPU *c) { /* FUN_100036fe */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x28u)); /* sub esp, 0x28 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd8u)); /* lea eax, [ebp - 0x28] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    FPUSH(c, RF64((uint32_t)(c->eax))); /* fld qword ptr [eax] */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x00cd371cu); f_00cd72ff(c); /* call 0xcd72ff */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov esi, dword ptr [ebp + 0x10] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x1u)); /* lea eax, [esi + 1] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff0u)), (uint32_t)0x2du); /* cmp dword ptr [ebp - 0x10], 0x2d */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete al */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)((!c->zf && c->sf == c->of) ? 1 : 0); /* setg cl */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->edx)); /* add ecx, edx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00cd3744u); f_00cd7288(c); /* call 0xcd7288 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x00cd3756u); f_00cd375f(c); /* call 0xcd375f */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x30u)); /* add esp, 0x30 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd375f(CPU *c) { /* FUN_1000375f */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x18u)), ((uint8_t)c->ebx)); /* cmp byte ptr [ebp + 0x18], bl */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov esi, dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    if (c->zf) goto L_00cd378d; /* je 0xcd378d */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->ebx); /* cmp dword ptr [ebp + 0xc], ebx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((!c->zf && c->sf == c->of) ? 1 : 0); /* setg al */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x2du); /* cmp dword ptr [esi], 0x2d */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete al */
    c->eax = (uint32_t)(add32(c, c->eax, c->edi)); /* add eax, edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd378bu); f_00cd3a01(c); /* call 0xcd3a01 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00cd378d:;
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x2du); /* cmp dword ptr [esi], 0x2d */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    if (!c->zf) goto L_00cd379a; /* jne 0xcd379a */
    W8((uint32_t)(c->edi), (uint8_t)((uint8_t)0x2du)); /* mov byte ptr [edi], 0x2d */
    c->eax = (uint32_t)((uint32_t)(c->edi + 0x1u)); /* lea eax, [edi + 1] */
L_00cd379a:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->ebx); /* cmp dword ptr [ebp + 0xc], ebx */
    if ((c->zf || c->sf != c->of)) goto L_00cd37b1; /* jle 0xcd37b1 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1u))); /* mov dl, byte ptr [eax + 1] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x1u)); /* lea ecx, [eax + 1] */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [eax], dl */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0xcdd504u))); /* mov cl, byte ptr [0x1000d504] */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax], cl */
L_00cd37b1:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x18u)), ((uint8_t)c->ebx)); /* cmp byte ptr [ebp + 0x18], bl */
    { uint32_t v_ = 0xcdc290u; PUSH32(c, v_); } /* push 0x1000c290 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete cl */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    c->ecx = (uint32_t)(add32(c, c->ecx, R32((uint32_t)(c->ebp + 0xcu)))); /* add ecx, dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00cd37c9u); f_00cd7420(c); /* call 0xcd7420 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), c->ebx); /* cmp dword ptr [ebp + 0x10], ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    if (c->zf) goto L_00cd37d5; /* je 0xcd37d5 */
    W8((uint32_t)(c->ecx), (uint8_t)((uint8_t)0x45u)); /* mov byte ptr [ecx], 0x45 */
L_00cd37d5:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x30u); /* cmp byte ptr [eax], 0x30 */
    if (c->zf) goto L_00cd381a; /* je 0xcd381a */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ebx, dword ptr [esi + 4] */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->sf) goto L_00cd37e9; /* jns 0xcd37e9 */
    c->ebx = (uint32_t)(neg32(c, c->ebx)); /* neg ebx */
    W8((uint32_t)(c->ecx), (uint8_t)((uint8_t)0x2du)); /* mov byte ptr [ecx], 0x2d */
L_00cd37e9:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->ebx, (uint32_t)0x64u); /* cmp ebx, 0x64 */
    if ((c->sf != c->of)) goto L_00cd3800; /* jl 0xcd3800 */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = 0x64u; PUSH32(c, v_); } /* push 0x64 */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00cd37f5u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [ecx], al */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00cd37fcu, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
    c->ebx = (uint32_t)(c->edx); /* mov ebx, edx */
L_00cd3800:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->ebx, (uint32_t)0xau); /* cmp ebx, 0xa */
    if ((c->sf != c->of)) goto L_00cd3817; /* jl 0xcd3817 */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = 0xau; PUSH32(c, v_); } /* push 0xa */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00cd380cu, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [ecx], al */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00cd3813u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
    c->ebx = (uint32_t)(c->edx); /* mov ebx, edx */
L_00cd3817:;
    { uint32_t a_ = (uint32_t)(c->ecx + 0x1u); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ebx)))); } /* add byte ptr [ecx + 1], bl */
L_00cd381a:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00cd3821(CPU *c) { /* FUN_10003821 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x28u)); /* sub esp, 0x28 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd8u)); /* lea eax, [ebp - 0x28] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    FPUSH(c, RF64((uint32_t)(c->eax))); /* fld qword ptr [eax] */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x00cd383fu); f_00cd72ff(c); /* call 0xcd72ff */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov esi, dword ptr [ebp + 0x10] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->eax = (uint32_t)(add32(c, c->eax, c->esi)); /* add eax, esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff0u)), (uint32_t)0x2du); /* cmp dword ptr [ebp - 0x10], 0x2d */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete al */
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->ebp + 0xcu)))); /* add eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd385eu); f_00cd7288(c); /* call 0xcd7288 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x00cd386du); f_00cd3876(c); /* call 0xcd3876 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd3876(CPU *c) { /* FUN_10003876 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov esi, dword ptr [ebp + 0x10] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x14u)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0x14], 0 */
    if (c->zf) goto L_00cd38a6; /* je 0xcd38a6 */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xcu))); /* cmp eax, dword ptr [ebp + 0xc] */
    if (!c->zf) goto L_00cd38a6; /* jne 0xcd38a6 */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x2du); /* cmp dword ptr [esi], 0x2d */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete cl */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->ebx)); /* add ecx, ebx */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    W8((uint32_t)(c->eax), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [eax], 0x30 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x1u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax + 1], 0 */
L_00cd38a6:;
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x2du); /* cmp dword ptr [esi], 0x2d */
    c->edi = (uint32_t)(c->ebx); /* mov edi, ebx */
    if (!c->zf) goto L_00cd38b3; /* jne 0xcd38b3 */
    W8((uint32_t)(c->ebx), (uint8_t)((uint8_t)0x2du)); /* mov byte ptr [ebx], 0x2d */
    c->edi = (uint32_t)((uint32_t)(c->ebx + 0x1u)); /* lea edi, [ebx + 1] */
L_00cd38b3:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((!c->zf && c->sf == c->of)) goto L_00cd38ca; /* jg 0xcd38ca */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00cd38c2u); f_00cd3a01(c); /* call 0xcd3a01 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W8((uint32_t)(c->edi), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [edi], 0x30 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_00cd38cc; /* jmp 0xcd38cc */
L_00cd38ca:;
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
L_00cd38cc:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    if ((c->zf || c->sf != c->of)) goto L_00cd3916; /* jle 0xcd3916 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00cd38dau); f_00cd3a01(c); /* call 0xcd3a01 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0xcdd504u))); /* mov al, byte ptr [0x1000d504] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov esi, dword ptr [esi + 4] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if ((c->sf == c->of)) goto L_00cd3916; /* jge 0xcd3916 */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x14u)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0x14], 0 */
    if (c->zf) goto L_00cd38f5; /* je 0xcd38f5 */
    c->esi = (uint32_t)(neg32(c, c->esi)); /* neg esi */
    goto L_00cd38fc; /* jmp 0xcd38fc */
L_00cd38f5:;
    c->esi = (uint32_t)(neg32(c, c->esi)); /* neg esi */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->esi); /* cmp dword ptr [ebp + 0xc], esi */
    if ((c->sf != c->of)) goto L_00cd38ff; /* jl 0xcd38ff */
L_00cd38fc:;
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_00cd38ff:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00cd3908u); f_00cd3a01(c); /* call 0xcd3a01 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = 0x30u; PUSH32(c, v_); } /* push 0x30 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00cd3913u); f_00cd7510(c); /* call 0xcd7510 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
L_00cd3916:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00cd391d(CPU *c) { /* FUN_1000391d */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x28u)); /* sub esp, 0x28 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd8u)); /* lea eax, [ebp - 0x28] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    FPUSH(c, RF64((uint32_t)(c->eax))); /* fld qword ptr [eax] */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x00cd393du); f_00cd72ff(c); /* call 0xcd72ff */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ebx, dword ptr [ebp + 0x10] */
    c->esi = (uint32_t)((uint32_t)(c->eax + 0xffffffffu)); /* lea esi, [eax - 1] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff0u)), (uint32_t)0x2du); /* cmp dword ptr [ebp - 0x10], 0x2d */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete al */
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->ebp + 0xcu)))); /* add eax, dword ptr [ebp + 0xc] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00cd395fu); f_00cd7288(c); /* call 0xcd7288 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)((c->sf != c->of) ? 1 : 0); /* setl cl */
    (void)sub32(c, c->eax, (uint32_t)0xfffffffcu); /* cmp eax, -4 */
    if ((c->sf != c->of)) goto L_00cd3996; /* jl 0xcd3996 */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if ((c->sf == c->of)) goto L_00cd3996; /* jge 0xcd3996 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_00cd3982; /* je 0xcd3982 */
L_00cd3978:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov al, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00cd3978; /* jne 0xcd3978 */
    { uint32_t a_ = (uint32_t)(c->edi + 0xfffffffeu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & ((uint8_t)c->eax))))); } /* and byte ptr [edi - 2], al */
L_00cd3982:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x00cd3991u); f_00cd3876(c); /* call 0xcd3876 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    goto L_00cd39ab; /* jmp 0xcd39ab */
L_00cd3996:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x00cd39a8u); f_00cd375f(c); /* call 0xcd375f */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
L_00cd39ab:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd39b0(CPU *c) { /* __cfltcvt */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), (uint32_t)0x65u); /* cmp dword ptr [ebp + 0x10], 0x65 */
    if (c->zf) goto L_00cd39eb; /* je 0xcd39eb */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), (uint32_t)0x45u); /* cmp dword ptr [ebp + 0x10], 0x45 */
    if (c->zf) goto L_00cd39eb; /* je 0xcd39eb */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), (uint32_t)0x66u); /* cmp dword ptr [ebp + 0x10], 0x66 */
    if (!c->zf) goto L_00cd39d8; /* jne 0xcd39d8 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00cd39d3u); f_00cd3821(c); /* call 0xcd3821 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
L_00cd39d8:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00cd39e9u); f_00cd391d(c); /* call 0xcd391d */
    goto L_00cd39fc; /* jmp 0xcd39fc */
L_00cd39eb:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00cd39fcu); f_00cd36fe(c); /* call 0xcd36fe */
L_00cd39fc:;
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00cd3a01(CPU *c) { /* FUN_10003a01 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edi, dword ptr [esp + 0xc] */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00cd3a24; /* je 0xcd3a24 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov esi, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd3a15u); f_00cd46d0(c); /* call 0xcd46d0 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(add32(c, c->esi, c->edi)); /* add esi, edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd3a20u); f_00cd7570(c); /* call 0xcd7570 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00cd3a24:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00cd3a26(CPU *c) { /* FUN_10003a26 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(0xcdc034u))); /* mov esi, dword ptr [0x1000c034] */
    { uint32_t v_ = R32((uint32_t)(0xcdd264u)); PUSH32(c, v_); } /* push dword ptr [0x1000d264] */
    { uint32_t t_ = c->esi; PUSH32(c, 0x00cd3a35u); call_indirect(c, t_); } /* call esi */
    { uint32_t v_ = R32((uint32_t)(0xcdd254u)); PUSH32(c, v_); } /* push dword ptr [0x1000d254] */
    { uint32_t t_ = c->esi; PUSH32(c, 0x00cd3a3du); call_indirect(c, t_); } /* call esi */
    { uint32_t v_ = R32((uint32_t)(0xcdd244u)); PUSH32(c, v_); } /* push dword ptr [0x1000d244] */
    { uint32_t t_ = c->esi; PUSH32(c, 0x00cd3a45u); call_indirect(c, t_); } /* call esi */
    { uint32_t v_ = R32((uint32_t)(0xcdd224u)); PUSH32(c, v_); } /* push dword ptr [0x1000d224] */
    { uint32_t t_ = c->esi; PUSH32(c, 0x00cd3a4du); call_indirect(c, t_); } /* call esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00cd3a4f(CPU *c) { /* FUN_10003a4f */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(0xcdc038u))); /* mov edi, dword ptr [0x1000c038] */
    c->esi = (uint32_t)((uint32_t)0xcdd220u); /* mov esi, 0x1000d220 */
L_00cd3a5c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd3a8d; /* je 0xcd3a8d */
    (void)sub32(c, c->esi, (uint32_t)0xcdd264u); /* cmp esi, 0x1000d264 */
    if (c->zf) goto L_00cd3a8d; /* je 0xcd3a8d */
    (void)sub32(c, c->esi, (uint32_t)0xcdd254u); /* cmp esi, 0x1000d254 */
    if (c->zf) goto L_00cd3a8d; /* je 0xcd3a8d */
    (void)sub32(c, c->esi, (uint32_t)0xcdd244u); /* cmp esi, 0x1000d244 */
    if (c->zf) goto L_00cd3a8d; /* je 0xcd3a8d */
    (void)sub32(c, c->esi, (uint32_t)0xcdd224u); /* cmp esi, 0x1000d224 */
    if (c->zf) goto L_00cd3a8d; /* je 0xcd3a8d */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00cd3a85u); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    PUSH32(c, 0x00cd3a8cu); f_00cd3b31(c); /* call 0xcd3b31 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00cd3a8d:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, c->esi, (uint32_t)0xcdd2e0u); /* cmp esi, 0x1000d2e0 */
    if ((c->sf != c->of)) goto L_00cd3a5c; /* jl 0xcd3a5c */
    { uint32_t v_ = R32((uint32_t)(0xcdd244u)); PUSH32(c, v_); } /* push dword ptr [0x1000d244] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00cd3aa0u); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = R32((uint32_t)(0xcdd254u)); PUSH32(c, v_); } /* push dword ptr [0x1000d254] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00cd3aa8u); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = R32((uint32_t)(0xcdd264u)); PUSH32(c, v_); } /* push dword ptr [0x1000d264] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00cd3ab0u); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = R32((uint32_t)(0xcdd224u)); PUSH32(c, v_); } /* push dword ptr [0x1000d224] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00cd3ab8u); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00cd3abb(CPU *c) { /* FUN_10003abb */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    (void)sub32(c, R32((uint32_t)(c->eax * 4 + 0xcdd220u)), (uint32_t)0x0u); /* cmp dword ptr [eax*4 + 0x1000d220], 0 */
    c->esi = (uint32_t)((uint32_t)(c->eax * 4 + 0xcdd220u)); /* lea esi, [eax*4 + 0x1000d220] */
    if (!c->zf) goto L_00cd3b11; /* jne 0xcd3b11 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    PUSH32(c, 0x00cd3adbu); f_00cd4c86(c); /* call 0xcd4c86 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (!c->zf) goto L_00cd3aea; /* jne 0xcd3aea */
    { uint32_t v_ = 0x11u; PUSH32(c, v_); } /* push 0x11 */
    PUSH32(c, 0x00cd3ae9u); f_00cd33c8(c); /* call 0xcd33c8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00cd3aea:;
    { uint32_t v_ = 0x11u; PUSH32(c, v_); } /* push 0x11 */
    PUSH32(c, 0x00cd3af1u); f_00cd3abb(c); /* call 0xcd3abb */
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x0u); /* cmp dword ptr [esi], 0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00cd3b02; /* jne 0xcd3b02 */
    { uint32_t t_ = R32((uint32_t)(0xcdc034u)); PUSH32(c, 0x00cd3afeu); call_indirect(c, t_); } /* call dword ptr [0x1000c034] */
    W32((uint32_t)(c->esi), (uint32_t)(c->edi)); /* mov dword ptr [esi], edi */
    goto L_00cd3b08; /* jmp 0xcd3b08 */
L_00cd3b02:;
    PUSH32(c, 0x00cd3b07u); f_00cd3b31(c); /* call 0xcd3b31 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00cd3b08:;
    { uint32_t v_ = 0x11u; PUSH32(c, v_); } /* push 0x11 */
    PUSH32(c, 0x00cd3b0fu); f_00cd3b1c(c); /* call 0xcd3b1c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_00cd3b11:;
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(0xcdc03cu)); PUSH32(c, 0x00cd3b19u); call_indirect(c, t_); } /* call dword ptr [0x1000c03c] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00cd3b1c(CPU *c) { /* FUN_10003b1c */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->eax * 4 + 0xcdd220u)); PUSH32(c, v_); } /* push dword ptr [eax*4 + 0x1000d220] */
    { uint32_t t_ = R32((uint32_t)(0xcdc040u)); PUSH32(c, 0x00cd3b2fu); call_indirect(c, t_); } /* call dword ptr [0x1000c040] */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00cd3b31(CPU *c) { /* FUN_10003b31 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xcdc298u; PUSH32(c, v_); } /* push 0x1000c298 */
    { uint32_t v_ = 0xcd4dc8u; PUSH32(c, v_); } /* push 0x10004dc8 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00cd3c0b; /* je 0xcd3c0b */
    c->eax = (uint32_t)(R32((uint32_t)(0xce0a48u))); /* mov eax, dword ptr [0x10010a48] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_00cd3ba4; /* jne 0xcd3ba4 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00cd3b70u); f_00cd3abb(c); /* call 0xcd3abb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd3b7bu); f_00cd78f6(c); /* call 0xcd78f6 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd3b8c; /* je 0xcd3b8c */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd3b8au); f_00cd7921(c); /* call 0xcd7921 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00cd3b8c:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00cd3b95u); f_00cd3b9b(c); /* call 0xcd3b9b */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x1c], 0 */
    goto L_00cd3bec; /* jmp 0xcd3bec */
L_00cd3ba4:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00cd3bfc; /* jne 0xcd3bfc */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00cd3bb0u); f_00cd3abb(c); /* call 0xcd3abb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe0u)); /* lea eax, [ebp - 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd8u)); /* lea eax, [ebp - 0x28] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd3bc6u); f_00cd8651(c); /* call 0xcd8651 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd3bdf; /* je 0xcd3bdf */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x28] */
    PUSH32(c, 0x00cd3bdcu); f_00cd86a8(c); /* call 0xcd86a8 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_00cd3bdf:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00cd3be8u); f_00cd3bf3(c); /* call 0xcd3bf3 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
L_00cd3bec:;
    if (!c->zf) goto L_00cd3c0b; /* jne 0xcd3c0b */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    goto L_00cd3bfd; /* jmp 0xcd3bfd */
L_00cd3bfc:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
L_00cd3bfd:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xce0a44u)); PUSH32(c, v_); } /* push dword ptr [0x10010a44] */
    { uint32_t t_ = R32((uint32_t)(0xcdc048u)); PUSH32(c, 0x00cd3c0bu); call_indirect(c, t_); } /* call dword ptr [0x1000c048] */
L_00cd3c0b:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd3b9b(CPU *c) { /* FUN_10003b9b */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00cd3ba2u); f_00cd3b1c(c); /* call 0xcd3b1c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00cd3ba4(CPU *c) { /* PTR_00cd3ba4 */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) { f_00cd3bfc(c); return; } /* jne 0xcd3bfc */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00cd3bb0u); f_00cd3abb(c); /* call 0xcd3abb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe0u)); /* lea eax, [ebp - 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd8u)); /* lea eax, [ebp - 0x28] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd3bc6u); f_00cd8651(c); /* call 0xcd8651 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd3bdf; /* je 0xcd3bdf */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x28] */
    PUSH32(c, 0x00cd3bdcu); f_00cd86a8(c); /* call 0xcd86a8 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_00cd3bdf:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00cd3be8u); f_00cd3bf3(c); /* call 0xcd3bf3 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) { f_00cd3c0b(c); return; } /* jne 0xcd3c0b */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { f_00cd3bfd(c); return; } /* jmp 0xcd3bfd */
}

void f_00cd3bdf(CPU *c) { /* PTR_00cd3bdf */
    PREEMPT_POLL(c);
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00cd3be8u); f_00cd3bf3(c); /* call 0xcd3bf3 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) { f_00cd3c0b(c); return; } /* jne 0xcd3c0b */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { f_00cd3bfd(c); return; } /* jmp 0xcd3bfd */
}

void f_00cd3bec(CPU *c) { /* PTR_00cd3bec */
    PREEMPT_POLL(c);
    if (!c->zf) { f_00cd3c0b(c); return; } /* jne 0xcd3c0b */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { f_00cd3bfd(c); return; } /* jmp 0xcd3bfd */
}

void f_00cd3bf3(CPU *c) { /* FUN_10003bf3 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00cd3bfau); f_00cd3b1c(c); /* call 0xcd3b1c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00cd3bfc(CPU *c) { /* PTR_00cd3bfc */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xce0a44u)); PUSH32(c, v_); } /* push dword ptr [0x10010a44] */
    { uint32_t t_ = R32((uint32_t)(0xcdc048u)); PUSH32(c, 0x00cd3c0bu); call_indirect(c, t_); } /* call dword ptr [0x1000c048] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd3bfd(CPU *c) { /* PTR_00cd3bfd */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xce0a44u)); PUSH32(c, v_); } /* push dword ptr [0x10010a44] */
    { uint32_t t_ = R32((uint32_t)(0xcdc048u)); PUSH32(c, 0x00cd3c0bu); call_indirect(c, t_); } /* call dword ptr [0x1000c048] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd3c0b(CPU *c) { /* PTR_00cd3c0b */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd3c20(CPU *c) { /* _strcmp */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u)); /* test edx, 3 */
    if (!c->zf) goto L_00cd3c6c; /* jne 0xcd3c6c */
L_00cd3c30:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edx))); /* mov eax, dword ptr [edx] */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->ecx))); /* cmp al, byte ptr [ecx] */
    if (!c->zf) goto L_00cd3c64; /* jne 0xcd3c64 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00cd3c60; /* je 0xcd3c60 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), R8((uint32_t)(c->ecx + 0x1u))); /* cmp ah, byte ptr [ecx + 1] */
    if (!c->zf) goto L_00cd3c64; /* jne 0xcd3c64 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | ((uint8_t)(c->eax >> 8))))) << 8); /* or ah, ah */
    if (c->zf) goto L_00cd3c60; /* je 0xcd3c60 */
    c->eax = (uint32_t)(shr32(c, c->eax, 16)); /* shr eax, 0x10 */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->ecx + 0x2u))); /* cmp al, byte ptr [ecx + 2] */
    if (!c->zf) goto L_00cd3c64; /* jne 0xcd3c64 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00cd3c60; /* je 0xcd3c60 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), R8((uint32_t)(c->ecx + 0x3u))); /* cmp ah, byte ptr [ecx + 3] */
    if (!c->zf) goto L_00cd3c64; /* jne 0xcd3c64 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x4u)); /* add edx, 4 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | ((uint8_t)(c->eax >> 8))))) << 8); /* or ah, ah */
    if (!c->zf) goto L_00cd3c30; /* jne 0xcd3c30 */
    c->edi = (uint32_t)(c->edi); /* mov edi, edi */
L_00cd3c60:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_00cd3c64:;
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(shl32(c, c->eax, 1)); /* shl eax, 1 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->esp += 4; return; /* ret  */
L_00cd3c6c:;
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x1u)); /* test edx, 1 */
    if (c->zf) goto L_00cd3c88; /* je 0xcd3c88 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov al, byte ptr [edx] */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->ecx))); /* cmp al, byte ptr [ecx] */
    if (!c->zf) goto L_00cd3c64; /* jne 0xcd3c64 */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00cd3c60; /* je 0xcd3c60 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x2u)); /* test edx, 2 */
    if (c->zf) goto L_00cd3c30; /* je 0xcd3c30 */
L_00cd3c88:;
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->edx))); /* mov ax, word ptr [edx] */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x2u)); /* add edx, 2 */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->ecx))); /* cmp al, byte ptr [ecx] */
    if (!c->zf) goto L_00cd3c64; /* jne 0xcd3c64 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00cd3c60; /* je 0xcd3c60 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), R8((uint32_t)(c->ecx + 0x1u))); /* cmp ah, byte ptr [ecx + 1] */
    if (!c->zf) goto L_00cd3c64; /* jne 0xcd3c64 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | ((uint8_t)(c->eax >> 8))))) << 8); /* or ah, ah */
    if (c->zf) goto L_00cd3c60; /* je 0xcd3c60 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x2u)); /* add ecx, 2 */
    goto L_00cd3c30; /* jmp 0xcd3c30 */
}

void f_00cd3ca4(CPU *c) { /* FUN_10003ca4 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov esi, dword ptr [ebp + 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)((uint32_t)0x19930520u); /* mov edi, 0x19930520 */
    (void)sub32(c, R32((uint32_t)(c->esi)), c->edi); /* cmp dword ptr [esi], edi */
    if (c->zf) goto L_00cd3cba; /* je 0xcd3cba */
    PUSH32(c, 0x00cd3cbau); f_00cd455d(c); /* call 0xcd455d */
L_00cd3cba:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + 0x4u)) & (uint8_t)0x66u)); /* test byte ptr [eax + 4], 0x66 */
    if (c->zf) goto L_00cd3ce2; /* je 0xcd3ce2 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x4u)), (uint32_t)0x0u); /* cmp dword ptr [esi + 4], 0 */
    if (c->zf) goto L_00cd3d38; /* je 0xcd3d38 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x1c], 0 */
    if (!c->zf) goto L_00cd3d38; /* jne 0xcd3d38 */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x00cd3cddu); f_00cd3ff9(c); /* call 0xcd3ff9 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    goto L_00cd3d38; /* jmp 0xcd3d38 */
L_00cd3ce2:;
    (void)sub32(c, R32((uint32_t)(c->esi + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [esi + 0xc], 0 */
    if (c->zf) goto L_00cd3d38; /* je 0xcd3d38 */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xe06d7363u); /* cmp dword ptr [eax], 0xe06d7363 */
    if (!c->zf) goto L_00cd3d1c; /* jne 0xcd3d1c */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x14u)), c->edi); /* cmp dword ptr [eax + 0x14], edi */
    if ((c->cf || c->zf)) goto L_00cd3d1c; /* jbe 0xcd3d1c */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x1cu))); /* mov ecx, dword ptr [eax + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov ecx, dword ptr [ecx + 8] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00cd3d1c; /* je 0xcd3d1c */
    c->edx = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0x24u))); /* movzx edx, byte ptr [ebp + 0x24] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = c->ecx; PUSH32(c, 0x00cd3d17u); call_indirect(c, t_); } /* call ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    goto L_00cd3d3b; /* jmp 0xcd3d3b */
L_00cd3d1c:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x24u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x24] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd3d35u); f_00cd3d3f(c); /* call 0xcd3d3f */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
L_00cd3d38:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00cd3d3b:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00cd3d3f(CPU *c) { /* FUN_10003d3f */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffecu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp - 0x14], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x10], eax */
    if ((c->sf != c->of)) goto L_00cd3d5f; /* jl 0xcd3d5f */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov ecx, dword ptr [ebp + 0x18] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ecx + 0x4u))); /* cmp eax, dword ptr [ecx + 4] */
    if ((c->sf != c->of)) goto L_00cd3d64; /* jl 0xcd3d64 */
L_00cd3d5f:;
    PUSH32(c, 0x00cd3d64u); f_00cd455d(c); /* call 0xcd455d */
L_00cd3d64:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    c->ebx = (uint32_t)((uint32_t)0xe06d7363u); /* mov ebx, 0xe06d7363 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)((uint32_t)0x19930520u); /* mov edi, 0x19930520 */
    (void)sub32(c, R32((uint32_t)(c->esi)), c->ebx); /* cmp dword ptr [esi], ebx */
    if (!c->zf) goto L_00cd3ec7; /* jne 0xcd3ec7 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [esi + 0x10], 3 */
    if (!c->zf) goto L_00cd3de4; /* jne 0xcd3de4 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x14u)), c->edi); /* cmp dword ptr [esi + 0x14], edi */
    if (!c->zf) goto L_00cd3de4; /* jne 0xcd3de4 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [esi + 0x1c], 0 */
    if (!c->zf) goto L_00cd3de4; /* jne 0xcd3de4 */
    PUSH32(c, 0x00cd3d92u); f_00cd3480(c); /* call 0xcd3480 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x6cu)), (uint32_t)0x0u); /* cmp dword ptr [eax + 0x6c], 0 */
    if (c->zf) goto L_00cd3ec2; /* je 0xcd3ec2 */
    PUSH32(c, 0x00cd3da1u); f_00cd3480(c); /* call 0xcd3480 */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + 0x6cu))); /* mov esi, dword ptr [eax + 0x6c] */
    PUSH32(c, 0x00cd3da9u); f_00cd3480(c); /* call 0xcd3480 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x70u))); /* mov eax, dword ptr [eax + 0x70] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x10], eax */
    W8((uint32_t)(c->ebp + 0xffffffecu), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ebp - 0x14], 1 */
    PUSH32(c, 0x00cd3dbbu); f_00cd8ac2(c); /* call 0xcd8ac2 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00cd3dc6; /* jne 0xcd3dc6 */
    PUSH32(c, 0x00cd3dc6u); f_00cd455d(c); /* call 0xcd455d */
L_00cd3dc6:;
    (void)sub32(c, R32((uint32_t)(c->esi)), c->ebx); /* cmp dword ptr [esi], ebx */
    if (!c->zf) goto L_00cd3ec7; /* jne 0xcd3ec7 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [esi + 0x10], 3 */
    if (!c->zf) goto L_00cd3de4; /* jne 0xcd3de4 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x14u)), c->edi); /* cmp dword ptr [esi + 0x14], edi */
    if (!c->zf) goto L_00cd3de4; /* jne 0xcd3de4 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [esi + 0x1c], 0 */
    if (!c->zf) goto L_00cd3de4; /* jne 0xcd3de4 */
    PUSH32(c, 0x00cd3de4u); f_00cd455d(c); /* call 0xcd455d */
L_00cd3de4:;
    (void)sub32(c, R32((uint32_t)(c->esi)), c->ebx); /* cmp dword ptr [esi], ebx */
    if (!c->zf) goto L_00cd3ec7; /* jne 0xcd3ec7 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [esi + 0x10], 3 */
    if (!c->zf) goto L_00cd3ec7; /* jne 0xcd3ec7 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x14u)), c->edi); /* cmp dword ptr [esi + 0x14], edi */
    if (!c->zf) goto L_00cd3ec7; /* jne 0xcd3ec7 */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov edi, dword ptr [ebp - 0x10] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe8u)); /* lea eax, [ebp - 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    PUSH32(c, 0x00cd3e16u); f_00cd2e4d(c); /* call 0xcd2e4d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
L_00cd3e1b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xffffffe8u))); /* cmp eax, dword ptr [ebp - 0x18] */
    if (!c->cf) goto L_00cd3eb2; /* jae 0xcd3eb2 */
    (void)sub32(c, R32((uint32_t)(c->ebx)), c->edi); /* cmp dword ptr [ebx], edi */
    if ((!c->zf && c->sf == c->of)) goto L_00cd3ea7; /* jg 0xcd3ea7 */
    (void)sub32(c, c->edi, R32((uint32_t)(c->ebx + 0x4u))); /* cmp edi, dword ptr [ebx + 4] */
    if ((!c->zf && c->sf == c->of)) goto L_00cd3ea7; /* jg 0xcd3ea7 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x10u))); /* mov eax, dword ptr [ebx + 0x10] */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xcu))); /* mov eax, dword ptr [ebx + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    if ((c->zf || c->sf != c->of)) goto L_00cd3ea4; /* jle 0xcd3ea4 */
L_00cd3e40:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x1cu))); /* mov eax, dword ptr [esi + 0x1c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0xcu))); /* mov eax, dword ptr [eax + 0xc] */
    c->edi = (uint32_t)((uint32_t)(c->eax + 0x4u)); /* lea edi, [eax + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    if ((c->zf || c->sf != c->of)) goto L_00cd3e71; /* jle 0xcd3e71 */
L_00cd3e52:;
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [esi + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->edi)); PUSH32(c, v_); } /* push dword ptr [edi] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00cd3e5fu); f_00cd3f9c(c); /* call 0xcd3f9c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00cd3e80; /* jne 0xcd3e80 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 8] */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff8u)), c->eax); /* cmp dword ptr [ebp - 8], eax */
    if ((!c->zf && c->sf == c->of)) goto L_00cd3e52; /* jg 0xcd3e52 */
L_00cd3e71:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff4u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x10u))); } /* add dword ptr [ebp + 8], 0x10 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0xc], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_00cd3e40; /* jg 0xcd3e40 */
    goto L_00cd3ea4; /* jmp 0xcd3ea4 */
L_00cd3e80:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffecu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x24u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->edi)); PUSH32(c, v_); } /* push dword ptr [edi] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd3ea1u); f_00cd4097(c); /* call 0xcd4097 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
L_00cd3ea4:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov edi, dword ptr [ebp - 0x10] */
L_00cd3ea7:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x14u)); /* add ebx, 0x14 */
    goto L_00cd3e1b; /* jmp 0xcd3e1b */
L_00cd3eb2:;
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x1cu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0x1c], 0 */
    if (c->zf) goto L_00cd3ec2; /* je 0xcd3ec2 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd3ec0u); f_00cd441b(c); /* call 0xcd441b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00cd3ec2:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd3ec7:;
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x1cu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0x1c], 0 */
    if (!c->zf) goto L_00cd3eed; /* jne 0xcd3eed */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x24u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffff0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd3ee8u); f_00cd3ef2(c); /* call 0xcd3ef2 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    goto L_00cd3ec2; /* jmp 0xcd3ec2 */
L_00cd3eed:;
    { f_00cd44fc(c); return; } /* jmp 0xcd44fc */
}

void f_00cd3ef2(CPU *c) { /* FUN_10003ef2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00cd3efeu); f_00cd3480(c); /* call 0xcd3480 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x68u)), (uint32_t)0x0u); /* cmp dword ptr [eax + 0x68], 0 */
    if (c->zf) goto L_00cd3f25; /* je 0xcd3f25 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x24u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00cd3f1eu); f_00cd2d22(c); /* call 0xcd2d22 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00cd3f98; /* jne 0xcd3f98 */
L_00cd3f25:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov edi, dword ptr [ebp + 0x1c] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    PUSH32(c, 0x00cd3f3cu); f_00cd2e4d(c); /* call 0xcd2e4d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_00cd3f41:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xfffffff8u))); /* cmp eax, dword ptr [ebp - 8] */
    if (!c->cf) goto L_00cd3f98; /* jae 0xcd3f98 */
    (void)sub32(c, c->edi, R32((uint32_t)(c->esi))); /* cmp edi, dword ptr [esi] */
    if ((c->sf != c->of)) goto L_00cd3f90; /* jl 0xcd3f90 */
    (void)sub32(c, c->edi, R32((uint32_t)(c->esi + 0x4u))); /* cmp edi, dword ptr [esi + 4] */
    if ((!c->zf && c->sf == c->of)) goto L_00cd3f90; /* jg 0xcd3f90 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0xfffffff4u))); /* mov ecx, dword ptr [eax - 0xc] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00cd3f6a; /* je 0xcd3f6a */
    (void)sub8(c, R8((uint32_t)(c->ecx + 0x8u)), (uint8_t)0x0u); /* cmp byte ptr [ecx + 8], 0 */
    if (!c->zf) goto L_00cd3f90; /* jne 0xcd3f90 */
L_00cd3f6a:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xfffffff0u)); /* add eax, -0x10 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x24u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00cd3f8du); f_00cd4097(c); /* call 0xcd4097 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
L_00cd3f90:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x14u)); /* add esi, 0x14 */
    goto L_00cd3f41; /* jmp 0xcd3f41 */
L_00cd3f98:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd3f9c(CPU *c) { /* FUN_10003f9c */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edi, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov eax, dword ptr [edi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd3ff3; /* je 0xcd3ff3 */
    (void)sub8(c, R8((uint32_t)(c->eax + 0x8u)), (uint8_t)0x0u); /* cmp byte ptr [eax + 8], 0 */
    c->edx = (uint32_t)((uint32_t)(c->eax + 0x8u)); /* lea edx, [eax + 8] */
    if (c->zf) goto L_00cd3ff3; /* je 0xcd3ff3 */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (c->zf) goto L_00cd3fcd; /* je 0xcd3fcd */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x8u)); /* add ecx, 8 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00cd3fc7u); f_00cd3c20(c); /* call 0xcd3c20 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00cd3fef; /* jne 0xcd3fef */
L_00cd3fcd:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi)) & (uint8_t)0x2u)); /* test byte ptr [esi], 2 */
    if (c->zf) goto L_00cd3fd7; /* je 0xcd3fd7 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edi)) & (uint8_t)0x8u)); /* test byte ptr [edi], 8 */
    if (c->zf) goto L_00cd3fef; /* je 0xcd3fef */
L_00cd3fd7:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    if (c->zf) goto L_00cd3fe6; /* je 0xcd3fe6 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edi)) & (uint8_t)0x1u)); /* test byte ptr [edi], 1 */
    if (c->zf) goto L_00cd3fef; /* je 0xcd3fef */
L_00cd3fe6:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x2u)); /* test al, 2 */
    if (c->zf) goto L_00cd3ff3; /* je 0xcd3ff3 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edi)) & (uint8_t)0x2u)); /* test byte ptr [edi], 2 */
    if (!c->zf) goto L_00cd3ff3; /* jne 0xcd3ff3 */
L_00cd3fef:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00cd3ff6; /* jmp 0xcd3ff6 */
L_00cd3ff3:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00cd3ff6:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00cd3ff9(CPU *c) { /* FUN_10003ff9 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xcdc2b0u; PUSH32(c, v_); } /* push 0x1000c2b0 */
    { uint32_t v_ = 0xcd4dc8u; PUSH32(c, v_); } /* push 0x10004dc8 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov esi, dword ptr [ebx + 8] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x1c], esi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edi, dword ptr [ebp + 0x10] */
L_00cd402b:;
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0x14u))); /* cmp esi, dword ptr [ebp + 0x14] */
    if (c->zf) goto L_00cd4085; /* je 0xcd4085 */
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if ((c->zf || c->sf != c->of)) goto L_00cd403a; /* jle 0xcd403a */
    (void)sub32(c, c->esi, R32((uint32_t)(c->edi + 0x4u))); /* cmp esi, dword ptr [edi + 4] */
    if ((c->sf != c->of)) goto L_00cd403f; /* jl 0xcd403f */
L_00cd403a:;
    PUSH32(c, 0x00cd403fu); f_00cd455d(c); /* call 0xcd455d */
L_00cd403f:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8 + 0x4u))); /* mov eax, dword ptr [eax + esi*8 + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd405a; /* je 0xcd405a */
    { uint32_t v_ = 0x103u; PUSH32(c, v_); } /* push 0x103 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd405au); f_00cd44b0(c); /* call 0xcd44b0 */
L_00cd405a:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    goto L_00cd407a; /* jmp 0xcd407a */
L_00cd407a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8))); /* mov esi, dword ptr [eax + esi*8] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x1c], esi */
    goto L_00cd402b; /* jmp 0xcd402b */
L_00cd4085:;
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebx + 8], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd402b(CPU *c) { /* PTR_00cd402b */
    PREEMPT_POLL(c);
L_00cd402b:;
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0x14u))); /* cmp esi, dword ptr [ebp + 0x14] */
    if (c->zf) goto L_00cd4085; /* je 0xcd4085 */
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if ((c->zf || c->sf != c->of)) goto L_00cd403a; /* jle 0xcd403a */
    (void)sub32(c, c->esi, R32((uint32_t)(c->edi + 0x4u))); /* cmp esi, dword ptr [edi + 4] */
    if ((c->sf != c->of)) goto L_00cd403f; /* jl 0xcd403f */
L_00cd403a:;
    PUSH32(c, 0x00cd403fu); f_00cd455d(c); /* call 0xcd455d */
L_00cd403f:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8 + 0x4u))); /* mov eax, dword ptr [eax + esi*8 + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd405a; /* je 0xcd405a */
    { uint32_t v_ = 0x103u; PUSH32(c, v_); } /* push 0x103 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd405au); f_00cd44b0(c); /* call 0xcd44b0 */
L_00cd405a:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    goto L_00cd407a; /* jmp 0xcd407a */
L_00cd407a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8))); /* mov esi, dword ptr [eax + esi*8] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x1c], esi */
    goto L_00cd402b; /* jmp 0xcd402b */
L_00cd4085:;
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebx + 8], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd4060(CPU *c) { /* PTR_00cd4060 */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffecu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x14] */
    PUSH32(c, 0x00cd4068u); f_00cd31fe(c); /* call 0xcd31fe */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00cd406a(CPU *c) { /* PTR_00cd406a */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edi, dword ptr [ebp + 0x10] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov esi, dword ptr [ebp - 0x1c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8))); /* mov esi, dword ptr [eax + esi*8] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x1c], esi */
    { f_00cd402b(c); return; } /* jmp 0xcd402b */
}

void f_00cd4097(CPU *c) { /* FUN_10004097 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x20u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x20], 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov ebx, dword ptr [ebp + 0x1c] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    if (c->zf) goto L_00cd40b9; /* je 0xcd40b9 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00cd40b6u); f_00cd4257(c); /* call 0xcd4257 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_00cd40b9:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x2cu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x2c], 0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    if (!c->zf) goto L_00cd40c5; /* jne 0xcd40c5 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    goto L_00cd40c8; /* jmp 0xcd40c8 */
L_00cd40c5:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x2cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x2c] */
L_00cd40c8:;
    PUSH32(c, 0x00cd40cdu); f_00cd2c24(c); /* call 0xcd2c24 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x24u))); /* mov esi, dword ptr [ebp + 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00cd40deu); f_00cd3ff9(c); /* call 0xcd3ff9 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    { uint32_t v_ = 0x100u; PUSH32(c, v_); } /* push 0x100 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x28u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x28] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    W32((uint32_t)(c->edi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + 8], eax */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebx + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00cd40ffu); f_00cd4112(c); /* call 0xcd4112 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd410d; /* je 0xcd410d */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd410du); f_00cd2be2(c); /* call 0xcd2be2 */
L_00cd410d:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00cd4112(CPU *c) { /* FUN_10004112 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xcdc2c0u; PUSH32(c, v_); } /* push 0x1000c2c0 */
    { uint32_t v_ = 0xcd4dc8u; PUSH32(c, v_); } /* push 0x10004dc8 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x1cu)); /* sub esp, 0x1c */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov ebx, dword ptr [ebp + 0x18] */
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x2c], ebx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffdcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x24], 0 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xfffffffcu))); /* mov eax, dword ptr [esi - 4] */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x28], eax */
    PUSH32(c, 0x00cd4150u); f_00cd3480(c); /* call 0xcd3480 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x6cu))); /* mov eax, dword ptr [eax + 0x6c] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    PUSH32(c, 0x00cd415bu); f_00cd3480(c); /* call 0xcd3480 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x70u))); /* mov eax, dword ptr [eax + 0x70] */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    PUSH32(c, 0x00cd4166u); f_00cd3480(c); /* call 0xcd3480 */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    W32((uint32_t)(c->eax + 0x6cu), (uint32_t)(c->edi)); /* mov dword ptr [eax + 0x6c], edi */
    PUSH32(c, 0x00cd4171u); f_00cd3480(c); /* call 0xcd3480 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    W32((uint32_t)(c->eax + 0x70u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x70], ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd4192u); f_00cd2ca9(c); /* call 0xcd2ca9 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x2c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00cd41a5u); f_00cd41df(c); /* call 0xcd41df */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd4u))); /* mov eax, dword ptr [ebp - 0x2c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd41a8(CPU *c) { /* PTR_00cd41a8 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd41b7(CPU *c) { /* PTR_00cd41b7 */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffecu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x14] */
    PUSH32(c, 0x00cd41bfu); f_00cd422d(c); /* call 0xcd422d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00cd41c1(CPU *c) { /* PTR_00cd41c1 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffd4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x2c], 0 */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd41d3u); f_00cd2f0a(c); /* call 0xcd2f0a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { f_00cd41a8(c); return; } /* jmp 0xcd41a8 */
}

void f_00cd41d9(CPU *c) { /* PTR_00cd41d9 */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    { f_00cd41df(c); return; }
}

void f_00cd41df(CPU *c) { /* FUN_100041df */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    W32((uint32_t)(c->esi + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [esi - 4], eax */
    PUSH32(c, 0x00cd41eau); f_00cd3480(c); /* call 0xcd3480 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov ecx, dword ptr [ebp - 0x1c] */
    W32((uint32_t)(c->eax + 0x6cu), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x6c], ecx */
    PUSH32(c, 0x00cd41f5u); f_00cd3480(c); /* call 0xcd3480 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov ecx, dword ptr [ebp - 0x20] */
    W32((uint32_t)(c->eax + 0x70u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x70], ecx */
    (void)sub32(c, R32((uint32_t)(c->edi)), (uint32_t)0xe06d7363u); /* cmp dword ptr [edi], 0xe06d7363 */
    if (!c->zf) goto L_00cd422c; /* jne 0xcd422c */
    (void)sub32(c, R32((uint32_t)(c->edi + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [edi + 0x10], 3 */
    if (!c->zf) goto L_00cd422c; /* jne 0xcd422c */
    (void)sub32(c, R32((uint32_t)(c->edi + 0x14u)), (uint32_t)0x19930520u); /* cmp dword ptr [edi + 0x14], 0x19930520 */
    if (!c->zf) goto L_00cd422c; /* jne 0xcd422c */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00cd422c; /* jne 0xcd422c */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x2c], 0 */
    if (c->zf) goto L_00cd422c; /* je 0xcd422c */
    PUSH32(c, 0x00cd4223u); f_00cd2f72(c); /* call 0xcd2f72 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00cd422au); f_00cd441b(c); /* call 0xcd441b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00cd422c:;
    c->esp += 4; return; /* ret  */
}

void f_00cd422d(CPU *c) { /* FUN_1000422d */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xe06d7363u); /* cmp dword ptr [eax], 0xe06d7363 */
    if (!c->zf) goto L_00cd4254; /* jne 0xcd4254 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [eax + 0x10], 3 */
    if (!c->zf) goto L_00cd4254; /* jne 0xcd4254 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x14u)), (uint32_t)0x19930520u); /* cmp dword ptr [eax + 0x14], 0x19930520 */
    if (!c->zf) goto L_00cd4254; /* jne 0xcd4254 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [eax + 0x1c], 0 */
    if (!c->zf) goto L_00cd4254; /* jne 0xcd4254 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
L_00cd4254:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_00cd4257(CPU *c) { /* FUN_10004257 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xcdc2d8u; PUSH32(c, v_); } /* push 0x1000c2d8 */
    { uint32_t v_ = 0xcd4dc8u; PUSH32(c, v_); } /* push 0x10004dc8 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov eax, dword ptr [ecx + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd4400; /* je 0xcd4400 */
    (void)sub8(c, R8((uint32_t)(c->eax + 0x8u)), (uint8_t)0x0u); /* cmp byte ptr [eax + 8], 0 */
    if (c->zf) goto L_00cd4400; /* je 0xcd4400 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov eax, dword ptr [ecx + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd4400; /* je 0xcd4400 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
    c->edi = (uint32_t)((uint32_t)(c->eax + c->edx + 0xcu)); /* lea edi, [eax + edx + 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ecx)) & (uint8_t)0x8u)); /* test byte ptr [ecx], 8 */
    if (c->zf) goto L_00cd42f4; /* je 0xcd42f4 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x18] */
    PUSH32(c, 0x00cd42bdu); f_00cd8ac2(c); /* call 0xcd8ac2 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd43f7; /* je 0xcd43f7 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00cd42cfu); f_00cd8ade(c); /* call 0xcd8ade */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd43f7; /* je 0xcd43f7 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x18u))); /* mov eax, dword ptr [esi + 0x18] */
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov ecx, dword ptr [ebp + 0x14] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x8u)); /* add ecx, 8 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
L_00cd42e5:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd42ebu); f_00cd4482(c); /* call 0xcd4482 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    goto L_00cd43fc; /* jmp 0xcd43fc */
L_00cd42f4:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov esi, dword ptr [ebp + 0x14] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi)) & (uint8_t)0x1u)); /* test byte ptr [esi], 1 */
    if (c->zf) goto L_00cd434e; /* je 0xcd434e */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    PUSH32(c, 0x00cd4309u); f_00cd8ac2(c); /* call 0xcd8ac2 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd43f7; /* je 0xcd43f7 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00cd431bu); f_00cd8ade(c); /* call 0xcd8ade */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd43f7; /* je 0xcd43f7 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x14u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00cd4331u); f_00cd7570(c); /* call 0xcd7570 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x14u)), (uint32_t)0x4u); /* cmp dword ptr [esi + 0x14], 4 */
    if (!c->zf) goto L_00cd43fc; /* jne 0xcd43fc */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd43fc; /* je 0xcd43fc */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x8u)); /* add esi, 8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    goto L_00cd42e5; /* jmp 0xcd42e5 */
L_00cd434e:;
    (void)sub32(c, R32((uint32_t)(c->esi + 0x18u)), (uint32_t)0x0u); /* cmp dword ptr [esi + 0x18], 0 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    if (!c->zf) goto L_00cd4396; /* jne 0xcd4396 */
    PUSH32(c, 0x00cd4361u); f_00cd8ac2(c); /* call 0xcd8ac2 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd43f7; /* je 0xcd43f7 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00cd4373u); f_00cd8ade(c); /* call 0xcd8ade */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd43f7; /* je 0xcd43f7 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x14u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x14] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x8u)); /* add esi, 8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    PUSH32(c, 0x00cd4388u); f_00cd4482(c); /* call 0xcd4482 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00cd4391u); f_00cd7570(c); /* call 0xcd7570 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_00cd43fc; /* jmp 0xcd43fc */
L_00cd4396:;
    PUSH32(c, 0x00cd439bu); f_00cd8ac2(c); /* call 0xcd8ac2 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd43f7; /* je 0xcd43f7 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00cd43a9u); f_00cd8ade(c); /* call 0xcd8ade */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd43f7; /* je 0xcd43f7 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x18] */
    PUSH32(c, 0x00cd43b7u); f_00cd8afa(c); /* call 0xcd8afa */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd43f7; /* je 0xcd43f7 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi)) & (uint8_t)0x4u)); /* test byte ptr [esi], 4 */
    if (c->zf) goto L_00cd43dd; /* je 0xcd43dd */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x8u)); /* lea eax, [esi + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    PUSH32(c, 0x00cd43cfu); f_00cd4482(c); /* call 0xcd4482 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00cd43dbu); f_00cd2c1d(c); /* call 0xcd2c1d */
    goto L_00cd43fc; /* jmp 0xcd43fc */
L_00cd43dd:;
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x8u)); /* lea eax, [esi + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    PUSH32(c, 0x00cd43e9u); f_00cd4482(c); /* call 0xcd4482 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00cd43f5u); f_00cd2c16(c); /* call 0xcd2c16 */
    goto L_00cd43fc; /* jmp 0xcd43fc */
L_00cd43f7:;
    PUSH32(c, 0x00cd43fcu); f_00cd455d(c); /* call 0xcd455d */
L_00cd43fc:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
L_00cd4400:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd440f(CPU *c) { /* PTR_00cd440f */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_00cd4413(CPU *c) { /* PTR_00cd4413 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { f_00cd44fc(c); return; } /* jmp 0xcd44fc */
}

void f_00cd441b(CPU *c) { /* FUN_1000441b */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xcdc2e8u; PUSH32(c, v_); } /* push 0x1000c2e8 */
    { uint32_t v_ = 0xcd4dc8u; PUSH32(c, v_); } /* push 0x10004dc8 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd4462; /* je 0xcd4462 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x1cu))); /* mov ecx, dword ptr [eax + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ecx, dword ptr [ecx + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00cd4462; /* je 0xcd4462 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = R32((uint32_t)(c->eax + 0x18u)); PUSH32(c, v_); } /* push dword ptr [eax + 0x18] */
    PUSH32(c, 0x00cd445eu); f_00cd2c16(c); /* call 0xcd2c16 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
L_00cd4462:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd4471(CPU *c) { /* PTR_00cd4471 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xcu)), ((uint8_t)c->eax)); /* cmp byte ptr [ebp + 0xc], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(!c->zf ? 1 : 0); /* setne al */
    c->esp += 4; return; /* ret  */
}

void f_00cd447a(CPU *c) { /* PTR_00cd447a */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { f_00cd44fc(c); return; } /* jmp 0xcd44fc */
}

void f_00cd4482(CPU *c) { /* FUN_10004482 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov edx, dword ptr [ecx + 4] */
    c->eax = (uint32_t)(add32(c, c->eax, c->esi)); /* add eax, esi */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if ((c->sf != c->of)) goto L_00cd44a3; /* jl 0xcd44a3 */
    c->esi = (uint32_t)(R32((uint32_t)(c->edx + c->esi))); /* mov esi, dword ptr [edx + esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov ecx, dword ptr [ecx + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + c->ecx))); /* mov ecx, dword ptr [esi + ecx] */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->edx)); /* add ecx, edx */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
L_00cd44a3:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00cd44b0(CPU *c) { /* __CallSettingFrame@12 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x4u)); /* sub esp, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xcu)); /* add eax, 0xc */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ebp, dword ptr [ebp - 4] */
    PUSH32(c, 0x00cd44d3u); f_00cd2f95(c); /* call 0xcd2f95 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00cd44d7u); call_indirect(c, t_); } /* call eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->ebx = (uint32_t)(c->ebp); /* mov ebx, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->ebx); /* mov ebp, ebx */
    (void)sub32(c, c->ecx, (uint32_t)0x100u); /* cmp ecx, 0x100 */
    if (!c->zf) goto L_00cd44ef; /* jne 0xcd44ef */
    c->ecx = (uint32_t)((uint32_t)0x2u); /* mov ecx, 2 */
L_00cd44ef:;
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00cd44f5u); f_00cd2f95(c); /* call 0xcd2f95 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 16; return; /* ret 0xc */
}

void f_00cd44fc(CPU *c) { /* FUN_100044fc */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xcdc2f8u; PUSH32(c, v_); } /* push 0x1000c2f8 */
    { uint32_t v_ = 0xcd4dc8u; PUSH32(c, v_); } /* push 0x10004dc8 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 4], esi */
    PUSH32(c, 0x00cd452bu); f_00cd3480(c); /* call 0xcd3480 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x60u)), c->esi); /* cmp dword ptr [eax + 0x60], esi */
    if (c->zf) goto L_00cd454f; /* je 0xcd454f */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    PUSH32(c, 0x00cd453cu); f_00cd3480(c); /* call 0xcd3480 */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x60u)); PUSH32(c, 0x00cd453fu); call_indirect(c, t_); } /* call dword ptr [eax + 0x60] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 4], esi */
    goto L_00cd454f; /* jmp 0xcd454f */
L_00cd454f:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00cd4558u); f_00cd4558(c); /* call 0xcd4558 */
    { f_00cd8b12(c); return; } /* jmp 0xcd8b12 */
}

void f_00cd4544(CPU *c) { /* PTR_00cd4544 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_00cd4548(CPU *c) { /* PTR_00cd4548 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00cd4558u); f_00cd4558(c); /* call 0xcd4558 */
    { f_00cd8b12(c); return; } /* jmp 0xcd8b12 */
}

void f_00cd4558(CPU *c) { /* PTR_00cd4558 */
    PREEMPT_POLL(c);
    { f_00cd8b12(c); return; } /* jmp 0xcd8b12 */
}

void f_00cd455d(CPU *c) { /* FUN_1000455d */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xcdc310u; PUSH32(c, v_); } /* push 0x1000c310 */
    { uint32_t v_ = 0xcd4dc8u; PUSH32(c, v_); } /* push 0x10004dc8 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(0xcdd2f0u))); /* mov eax, dword ptr [0x1000d2f0] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd45a5; /* je 0xcd45a5 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00cd4598u); call_indirect(c, t_); } /* call eax */
    goto L_00cd45a1; /* jmp 0xcd45a1 */
L_00cd45a1:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
L_00cd45a5:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00cd45aeu); f_00cd45ae(c); /* call 0xcd45ae */
    { f_00cd44fc(c); return; } /* jmp 0xcd44fc */
}

void f_00cd459a(CPU *c) { /* PTR_00cd459a */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_00cd459e(CPU *c) { /* PTR_00cd459e */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00cd45aeu); f_00cd45ae(c); /* call 0xcd45ae */
    { f_00cd44fc(c); return; } /* jmp 0xcd44fc */
}

void f_00cd45ae(CPU *c) { /* PTR_00cd45ae */
    PREEMPT_POLL(c);
    { f_00cd44fc(c); return; } /* jmp 0xcd44fc */
}

void f_00cd45b3(CPU *c) { /* FUN_100045b3 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xe06d7363u); /* cmp dword ptr [eax], 0xe06d7363 */
    if (!c->zf) goto L_00cd45d6; /* jne 0xcd45d6 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [eax + 0x10], 3 */
    if (!c->zf) goto L_00cd45d6; /* jne 0xcd45d6 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x14u)), (uint32_t)0x19930520u); /* cmp dword ptr [eax + 0x14], 0x19930520 */
    if (!c->zf) goto L_00cd45d6; /* jne 0xcd45d6 */
    { f_00cd44fc(c); return; } /* jmp 0xcd44fc */
L_00cd45d6:;
    c->eax = (uint32_t)(R32((uint32_t)(0xce04f0u))); /* mov eax, dword ptr [0x100104f0] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd45f3; /* je 0xcd45f3 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd45e5u); f_00cd8afa(c); /* call 0xcd8afa */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00cd45f3; /* je 0xcd45f3 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(0xce04f0u)); PUSH32(c, 0x00cd45f1u); call_indirect(c, t_); } /* call dword ptr [0x100104f0] */
    goto L_00cd45f5; /* jmp 0xcd45f5 */
L_00cd45f3:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00cd45f5:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00cd45f9(CPU *c) { /* PTR_00cd45f9 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xcd45b3u; PUSH32(c, v_); } /* push 0x100045b3 */
    { uint32_t t_ = R32((uint32_t)(0xcdc04cu)); PUSH32(c, 0x00cd4604u); call_indirect(c, t_); } /* call dword ptr [0x1000c04c] */
    W32((uint32_t)(0xce04f0u), (uint32_t)(c->eax)); /* mov dword ptr [0x100104f0], eax */
    c->esp += 4; return; /* ret  */
}

void f_00cd460a(CPU *c) { /* PTR_00cd460a */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(0xce04f0u)); PUSH32(c, v_); } /* push dword ptr [0x100104f0] */
    { uint32_t t_ = R32((uint32_t)(0xcdc04cu)); PUSH32(c, 0x00cd4616u); call_indirect(c, t_); } /* call dword ptr [0x1000c04c] */
    c->esp += 4; return; /* ret  */
}

void f_00cd4617(CPU *c) { /* FUN_10004617 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x1u)); /* lea ecx, [eax + 1] */
    (void)sub32(c, c->ecx, (uint32_t)0x100u); /* cmp ecx, 0x100 */
    if ((!c->cf && !c->zf)) goto L_00cd4635; /* ja 0xcd4635 */
    c->ecx = (uint32_t)(R32((uint32_t)(0xcdd2f4u))); /* mov ecx, dword ptr [0x1000d2f4] */
    c->eax = (uint32_t)((uint32_t)R16((uint32_t)(c->ecx + c->eax * 2))); /* movzx eax, word ptr [ecx + eax*2] */
    goto L_00cd4687; /* jmp 0xcd4687 */
L_00cd4635:;
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(0xcdd2f4u))); /* mov esi, dword ptr [0x1000d2f4] */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 8)); /* sar ecx, 8 */
    c->edx = (uint32_t)((uint32_t)((uint8_t)c->ecx)); /* movzx edx, cl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi + c->edx * 2 + 0x1u)) & (uint8_t)0x80u)); /* test byte ptr [esi + edx*2 + 1], 0x80 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    if (c->zf) goto L_00cd465a; /* je 0xcd465a */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffeu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp - 2], 0 */
    W8((uint32_t)(c->ebp + 0xfffffffcu), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [ebp - 4], cl */
    W8((uint32_t)(c->ebp + 0xfffffffdu), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp - 3], al */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    goto L_00cd4663; /* jmp 0xcd4663 */
L_00cd465a:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffdu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp - 3], 0 */
    W8((uint32_t)(c->ebp + 0xfffffffcu), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp - 4], al */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
L_00cd4663:;
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xau)); /* lea ecx, [ebp + 0xa] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x00cd467au); f_00cd8b29(c); /* call 0xcd8b29 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00cd4683; /* jne 0xcd4683 */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd4683:;
    c->eax = (uint32_t)((uint32_t)R16((uint32_t)(c->ebp + 0xau))); /* movzx eax, word ptr [ebp + 0xa] */
L_00cd4687:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & R32((uint32_t)(c->ebp + 0xcu))))); /* and eax, dword ptr [ebp + 0xc] */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd4690(CPU *c) { /* PTR_00cd4690 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->eax))); /* or ecx, eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    if (!c->zf) goto L_00cd46a9; /* jne 0xcd46a9 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint64_t r_ = (uint64_t)c->eax * c->ecx; c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = c->edx != 0; } /* mul ecx */
    c->esp += 20; return; /* ret 0x10 */
L_00cd46a9:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint64_t r_ = (uint64_t)c->eax * c->ecx; c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = c->edx != 0; } /* mul ecx */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint64_t r_ = (uint64_t)c->eax * R32((uint32_t)(c->esp + 0x14u)); c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = c->edx != 0; } /* mul dword ptr [esp + 0x14] */
    c->ebx = (uint32_t)(add32(c, c->ebx, c->eax)); /* add ebx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint64_t r_ = (uint64_t)c->eax * c->ecx; c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = c->edx != 0; } /* mul ecx */
    c->edx = (uint32_t)(add32(c, c->edx, c->ebx)); /* add edx, ebx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 20; return; /* ret 0x10 */
}

void f_00cd46d0(CPU *c) { /* _strlen */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u)); /* test ecx, 3 */
    if (c->zf) goto L_00cd46f0; /* je 0xcd46f0 */
L_00cd46dc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov al, byte ptr [ecx] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00cd4723; /* je 0xcd4723 */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u)); /* test ecx, 3 */
    if (!c->zf) goto L_00cd46dc; /* jne 0xcd46dc */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x0u)); /* add eax, 0 */
L_00cd46f0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)((uint32_t)0x7efefeffu); /* mov edx, 0x7efefeff */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ (uint32_t)0xffffffffu))); /* xor eax, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ c->edx))); /* xor eax, edx */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u)); /* test eax, 0x81010100 */
    if (c->zf) goto L_00cd46f0; /* je 0xcd46f0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0xfffffffcu))); /* mov eax, dword ptr [ecx - 4] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00cd4741; /* je 0xcd4741 */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_00cd4737; /* je 0xcd4737 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0xff0000u)); /* test eax, 0xff0000 */
    if (c->zf) goto L_00cd472d; /* je 0xcd472d */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0xff000000u)); /* test eax, 0xff000000 */
    if (c->zf) goto L_00cd4723; /* je 0xcd4723 */
    goto L_00cd46f0; /* jmp 0xcd46f0 */
L_00cd4723:;
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0xffffffffu)); /* lea eax, [ecx - 1] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->esp += 4; return; /* ret  */
L_00cd472d:;
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0xfffffffeu)); /* lea eax, [ecx - 2] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->esp += 4; return; /* ret  */
L_00cd4737:;
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0xfffffffdu)); /* lea eax, [ecx - 3] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->esp += 4; return; /* ret  */
L_00cd4741:;
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0xfffffffcu)); /* lea eax, [ecx - 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->esp += 4; return; /* ret  */
}

void f_00cd474b(CPU *c) { /* FUN_1000474b */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0xcdd18cu))); /* mov eax, dword ptr [0x1000d18c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd4756; /* je 0xcd4756 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00cd4756u); call_indirect(c, t_); } /* call eax */
L_00cd4756:;
    { uint32_t v_ = 0xcdd020u; PUSH32(c, v_); } /* push 0x1000d020 */
    { uint32_t v_ = 0xcdd010u; PUSH32(c, v_); } /* push 0x1000d010 */
    PUSH32(c, 0x00cd4765u); f_00cd484f(c); /* call 0xcd484f */
    { uint32_t v_ = 0xcdd00cu; PUSH32(c, v_); } /* push 0x1000d00c */
    { uint32_t v_ = 0xcdd000u; PUSH32(c, v_); } /* push 0x1000d000 */
    PUSH32(c, 0x00cd4774u); f_00cd484f(c); /* call 0xcd484f */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_00cd4778(CPU *c) { /* __exit */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    PUSH32(c, 0x00cd4785u); f_00cd4798(c); /* call 0xcd4798 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00cd4789(CPU *c) { /* FUN_10004789 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    PUSH32(c, 0x00cd4794u); f_00cd4798(c); /* call 0xcd4798 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00cd4798(CPU *c) { /* FUN_10004798 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00cd479eu); f_00cd483d(c); /* call 0xcd483d */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    (void)sub32(c, R32((uint32_t)(0xce0534u)), c->edi); /* cmp dword ptr [0x10010534], edi */
    if (!c->zf) goto L_00cd47ba; /* jne 0xcd47ba */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    { uint32_t t_ = R32((uint32_t)(0xcdc054u)); PUSH32(c, 0x00cd47b3u); call_indirect(c, t_); } /* call dword ptr [0x1000c054] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0xcdc050u)); PUSH32(c, 0x00cd47bau); call_indirect(c, t_); } /* call dword ptr [0x1000c050] */
L_00cd47ba:;
    (void)sub32(c, R32((uint32_t)(c->esp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [esp + 0xc], 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ebx, dword ptr [esp + 0x14] */
    W32((uint32_t)(0xce0530u), (uint32_t)(c->edi)); /* mov dword ptr [0x10010530], edi */
    W8((uint32_t)(0xce052cu), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [0x1001052c], bl */
    if (!c->zf) goto L_00cd480e; /* jne 0xcd480e */
    c->eax = (uint32_t)(R32((uint32_t)(0xce0b70u))); /* mov eax, dword ptr [0x10010b70] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd47fd; /* je 0xcd47fd */
    c->ecx = (uint32_t)(R32((uint32_t)(0xce0b6cu))); /* mov ecx, dword ptr [0x10010b6c] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)((uint32_t)(c->ecx + 0xfffffffcu)); /* lea esi, [ecx - 4] */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if (c->cf) goto L_00cd47fc; /* jb 0xcd47fc */
L_00cd47e9:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd47f1; /* je 0xcd47f1 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00cd47f1u); call_indirect(c, t_); } /* call eax */
L_00cd47f1:;
    c->esi = (uint32_t)(sub32(c, c->esi, (uint32_t)0x4u)); /* sub esi, 4 */
    (void)sub32(c, c->esi, R32((uint32_t)(0xce0b70u))); /* cmp esi, dword ptr [0x10010b70] */
    if (!c->cf) goto L_00cd47e9; /* jae 0xcd47e9 */
L_00cd47fc:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00cd47fd:;
    { uint32_t v_ = 0xcdd028u; PUSH32(c, v_); } /* push 0x1000d028 */
    { uint32_t v_ = 0xcdd024u; PUSH32(c, v_); } /* push 0x1000d024 */
    PUSH32(c, 0x00cd480cu); f_00cd484f(c); /* call 0xcd484f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00cd480e:;
    { uint32_t v_ = 0xcdd034u; PUSH32(c, v_); } /* push 0x1000d034 */
    { uint32_t v_ = 0xcdd02cu; PUSH32(c, v_); } /* push 0x1000d02c */
    PUSH32(c, 0x00cd481du); f_00cd484f(c); /* call 0xcd484f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    if (c->zf) goto L_00cd482b; /* je 0xcd482b */
    PUSH32(c, 0x00cd4829u); f_00cd4846(c); /* call 0xcd4846 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_00cd482b:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    W32((uint32_t)(0xce0534u), (uint32_t)(c->edi)); /* mov dword ptr [0x10010534], edi */
    { uint32_t t_ = R32((uint32_t)(0xcdc044u)); PUSH32(c, 0x00cd483bu); call_indirect(c, t_); } /* call dword ptr [0x1000c044] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00cd483b(CPU *c) { /* PTR_00cd483b */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00cd483d(CPU *c) { /* FUN_1000483d */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xdu; PUSH32(c, v_); } /* push 0xd */
    PUSH32(c, 0x00cd4844u); f_00cd3abb(c); /* call 0xcd3abb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00cd4846(CPU *c) { /* FUN_10004846 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xdu; PUSH32(c, v_); } /* push 0xd */
    PUSH32(c, 0x00cd484du); f_00cd3b1c(c); /* call 0xcd3b1c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00cd484f(CPU *c) { /* FUN_1000484f */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
L_00cd4854:;
    (void)sub32(c, c->esi, R32((uint32_t)(c->esp + 0xcu))); /* cmp esi, dword ptr [esp + 0xc] */
    if (!c->cf) goto L_00cd4867; /* jae 0xcd4867 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd4862; /* je 0xcd4862 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00cd4862u); call_indirect(c, t_); } /* call eax */
L_00cd4862:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    goto L_00cd4854; /* jmp 0xcd4854 */
L_00cd4867:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00cd4869(CPU *c) { /* FUN_10004869 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xcdc328u; PUSH32(c, v_); } /* push 0x1000c328 */
    { uint32_t v_ = 0xcd4dc8u; PUSH32(c, v_); } /* push 0x10004dc8 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x28u)); /* sub esp, 0x28 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    if (!c->zf) goto L_00cd48a3; /* jne 0xcd48a3 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x00cd489du); f_00cd4c86(c); /* call 0xcd4c86 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00cd4b89; /* jmp 0xcd4b89 */
L_00cd48a3:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_00cd48b6; /* jne 0xcd48b6 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00cd48b0u); f_00cd3b31(c); /* call 0xcd3b31 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00cd4b87; /* jmp 0xcd4b87 */
L_00cd48b6:;
    c->eax = (uint32_t)(R32((uint32_t)(0xce0a48u))); /* mov eax, dword ptr [0x10010a48] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_00cd49fd; /* jne 0xcd49fd */
L_00cd48c4:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00cd49c1; /* ja 0xcd49c1 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00cd48d7u); f_00cd3abb(c); /* call 0xcd3abb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 4], edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00cd48e1u); f_00cd78f6(c); /* call 0xcd78f6 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x28], eax */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (c->zf) goto L_00cd4991; /* je 0xcd4991 */
    (void)sub32(c, c->esi, R32((uint32_t)(0xce0a40u))); /* cmp esi, dword ptr [0x10010a40] */
    if ((!c->cf && !c->zf)) goto L_00cd4941; /* ja 0xcd4941 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd48fdu); f_00cd80ff(c); /* call 0xcd80ff */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd4909; /* je 0xcd4909 */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x24], ebx */
    goto L_00cd4941; /* jmp 0xcd4941 */
L_00cd4909:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd490fu); f_00cd7c4a(c); /* call 0xcd7c4a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (c->zf) goto L_00cd4941; /* je 0xcd4941 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xfffffffcu))); /* mov eax, dword ptr [ebx - 4] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00cd4924; /* jb 0xcd4924 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00cd4924:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00cd492eu); f_00cd9160(c); /* call 0xcd9160 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00cd4934u); f_00cd78f6(c); /* call 0xcd78f6 */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x28], eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd493eu); f_00cd7921(c); /* call 0xcd7921 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00cd4941:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), c->edi); /* cmp dword ptr [ebp - 0x24], edi */
    if (!c->zf) goto L_00cd4991; /* jne 0xcd4991 */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_00cd4950; /* jne 0xcd4950 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_00cd4950:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0xce0a44u)); PUSH32(c, v_); } /* push dword ptr [0x10010a44] */
    { uint32_t t_ = R32((uint32_t)(0xcdc05cu)); PUSH32(c, 0x00cd4967u); call_indirect(c, t_); } /* call dword ptr [0x1000c05c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (c->zf) goto L_00cd4991; /* je 0xcd4991 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xfffffffcu))); /* mov eax, dword ptr [ebx - 4] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00cd497b; /* jb 0xcd497b */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00cd497b:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00cd4985u); f_00cd9160(c); /* call 0xcd9160 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x28] */
    PUSH32(c, 0x00cd498eu); f_00cd7921(c); /* call 0xcd7921 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
L_00cd4991:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00cd499au); f_00cd49f4(c); /* call 0xcd49f4 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), c->edi); /* cmp dword ptr [ebp - 0x28], edi */
    if (!c->zf) goto L_00cd49c1; /* jne 0xcd49c1 */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_00cd49a6; /* jne 0xcd49a6 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00cd49a6:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0xce0a44u)); PUSH32(c, v_); } /* push dword ptr [0x10010a44] */
    { uint32_t t_ = R32((uint32_t)(0xcdc058u)); PUSH32(c, 0x00cd49beu); call_indirect(c, t_); } /* call dword ptr [0x1000c058] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_00cd49c1:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_00cd4b89; /* jne 0xcd4b89 */
    (void)sub32(c, R32((uint32_t)(0xce0650u)), c->edi); /* cmp dword ptr [0x10010650], edi */
    if (c->zf) goto L_00cd4b89; /* je 0xcd4b89 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd49deu); f_00cd9143(c); /* call 0xcd9143 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00cd48c4; /* jne 0xcd48c4 */
    goto L_00cd4b87; /* jmp 0xcd4b87 */
L_00cd49fd:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00cd4b4d; /* jne 0xcd4b4d */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00cd4a1d; /* ja 0xcd4a1d */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if ((c->cf || c->zf)) goto L_00cd4a17; /* jbe 0xcd4a17 */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    goto L_00cd4a1a; /* jmp 0xcd4a1a */
L_00cd4a17:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00cd4a1a:;
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_00cd4a1d:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00cd4b1c; /* ja 0xcd4b1c */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00cd4a30u); f_00cd3abb(c); /* call 0xcd3abb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00cd4a46u); f_00cd8651(c); /* call 0xcd8651 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00cd4b00; /* je 0xcd4b00 */
    (void)sub32(c, c->esi, R32((uint32_t)(0xcdf834u))); /* cmp esi, dword ptr [0x1000f834] */
    if (!c->cf) goto L_00cd4aba; /* jae 0xcd4aba */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 4)); /* shr ebx, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00cd4a70u); f_00cd8a19(c); /* call 0xcd8a19 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd4a7f; /* je 0xcd4a7f */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_00cd4ab7; /* jmp 0xcd4ab7 */
L_00cd4a7f:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00cd4a85u); f_00cd86ed(c); /* call 0xcd86ed */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd4ab7; /* je 0xcd4ab7 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00cd4a9c; /* jb 0xcd4a9c */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00cd4a9c:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00cd4aa8u); f_00cd9160(c); /* call 0xcd9160 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00cd4ab4u); f_00cd86a8(c); /* call 0xcd86a8 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00cd4ab7:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00cd4aba:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00cd4b13; /* jne 0xcd4b13 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xce0a44u)); PUSH32(c, v_); } /* push dword ptr [0x10010a44] */
    { uint32_t t_ = R32((uint32_t)(0xcdc05cu)); PUSH32(c, 0x00cd4acfu); call_indirect(c, t_); } /* call dword ptr [0x1000c05c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd4b13; /* je 0xcd4b13 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00cd4ae5; /* jb 0xcd4ae5 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00cd4ae5:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00cd4aefu); f_00cd9160(c); /* call 0xcd9160 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00cd4afbu); f_00cd86a8(c); /* call 0xcd86a8 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00cd4b13; /* jmp 0xcd4b13 */
L_00cd4b00:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xce0a44u)); PUSH32(c, v_); } /* push dword ptr [0x10010a44] */
    { uint32_t t_ = R32((uint32_t)(0xcdc058u)); PUSH32(c, 0x00cd4b10u); call_indirect(c, t_); } /* call dword ptr [0x1000c058] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_00cd4b13:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00cd4b1cu); f_00cd4b42(c); /* call 0xcd4b42 */
L_00cd4b1c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_00cd4b89; /* jne 0xcd4b89 */
    (void)sub32(c, R32((uint32_t)(0xce0650u)), c->edi); /* cmp dword ptr [0x10010650], edi */
    if (c->zf) goto L_00cd4b89; /* je 0xcd4b89 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd4b31u); f_00cd9143(c); /* call 0xcd9143 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00cd4a1d; /* jne 0xcd4a1d */
    goto L_00cd4b87; /* jmp 0xcd4b87 */
L_00cd4b4d:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00cd4b70; /* ja 0xcd4b70 */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_00cd4b5b; /* jne 0xcd4b5b */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00cd4b5b:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0xce0a44u)); PUSH32(c, v_); } /* push dword ptr [0x10010a44] */
    { uint32_t t_ = R32((uint32_t)(0xcdc058u)); PUSH32(c, 0x00cd4b70u); call_indirect(c, t_); } /* call dword ptr [0x1000c058] */
L_00cd4b70:;
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_00cd4b89; /* jne 0xcd4b89 */
    (void)sub32(c, R32((uint32_t)(0xce0650u)), c->edi); /* cmp dword ptr [0x10010650], edi */
    if (c->zf) goto L_00cd4b89; /* je 0xcd4b89 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd4b82u); f_00cd9143(c); /* call 0xcd9143 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00cd4b4d; /* jne 0xcd4b4d */
L_00cd4b87:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00cd4b89:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd49ec(CPU *c) { /* PTR_00cd49ec */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    { f_00cd49f4(c); return; }
}

void f_00cd49f4(CPU *c) { /* FUN_100049f4 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00cd49fbu); f_00cd3b1c(c); /* call 0xcd3b1c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00cd49fd(CPU *c) { /* PTR_00cd49fd */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) { f_00cd4b4d(c); return; } /* jne 0xcd4b4d */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00cd4a1d; /* ja 0xcd4a1d */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if ((c->cf || c->zf)) goto L_00cd4a17; /* jbe 0xcd4a17 */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    goto L_00cd4a1a; /* jmp 0xcd4a1a */
L_00cd4a17:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00cd4a1a:;
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_00cd4a1d:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00cd4b1c; /* ja 0xcd4b1c */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00cd4a30u); f_00cd3abb(c); /* call 0xcd3abb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00cd4a46u); f_00cd8651(c); /* call 0xcd8651 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00cd4b00; /* je 0xcd4b00 */
    (void)sub32(c, c->esi, R32((uint32_t)(0xcdf834u))); /* cmp esi, dword ptr [0x1000f834] */
    if (!c->cf) goto L_00cd4aba; /* jae 0xcd4aba */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 4)); /* shr ebx, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00cd4a70u); f_00cd8a19(c); /* call 0xcd8a19 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd4a7f; /* je 0xcd4a7f */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_00cd4ab7; /* jmp 0xcd4ab7 */
L_00cd4a7f:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00cd4a85u); f_00cd86ed(c); /* call 0xcd86ed */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd4ab7; /* je 0xcd4ab7 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00cd4a9c; /* jb 0xcd4a9c */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00cd4a9c:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00cd4aa8u); f_00cd9160(c); /* call 0xcd9160 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00cd4ab4u); f_00cd86a8(c); /* call 0xcd86a8 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00cd4ab7:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00cd4aba:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00cd4b13; /* jne 0xcd4b13 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xce0a44u)); PUSH32(c, v_); } /* push dword ptr [0x10010a44] */
    { uint32_t t_ = R32((uint32_t)(0xcdc05cu)); PUSH32(c, 0x00cd4acfu); call_indirect(c, t_); } /* call dword ptr [0x1000c05c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd4b13; /* je 0xcd4b13 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00cd4ae5; /* jb 0xcd4ae5 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00cd4ae5:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00cd4aefu); f_00cd9160(c); /* call 0xcd9160 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00cd4afbu); f_00cd86a8(c); /* call 0xcd86a8 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00cd4b13; /* jmp 0xcd4b13 */
L_00cd4b00:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xce0a44u)); PUSH32(c, v_); } /* push dword ptr [0x10010a44] */
    { uint32_t t_ = R32((uint32_t)(0xcdc058u)); PUSH32(c, 0x00cd4b10u); call_indirect(c, t_); } /* call dword ptr [0x1000c058] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_00cd4b13:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00cd4b1cu); f_00cd4b42(c); /* call 0xcd4b42 */
L_00cd4b1c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00cd4b89(c); return; } /* jne 0xcd4b89 */
    (void)sub32(c, R32((uint32_t)(0xce0650u)), c->edi); /* cmp dword ptr [0x10010650], edi */
    if (c->zf) { f_00cd4b89(c); return; } /* je 0xcd4b89 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd4b31u); f_00cd9143(c); /* call 0xcd9143 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00cd4a1d; /* jne 0xcd4a1d */
    { f_00cd4b87(c); return; } /* jmp 0xcd4b87 */
}

void f_00cd4a17(CPU *c) { /* PTR_00cd4a17 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_00cd4a1d:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00cd4b1c; /* ja 0xcd4b1c */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00cd4a30u); f_00cd3abb(c); /* call 0xcd3abb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00cd4a46u); f_00cd8651(c); /* call 0xcd8651 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00cd4b00; /* je 0xcd4b00 */
    (void)sub32(c, c->esi, R32((uint32_t)(0xcdf834u))); /* cmp esi, dword ptr [0x1000f834] */
    if (!c->cf) goto L_00cd4aba; /* jae 0xcd4aba */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 4)); /* shr ebx, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00cd4a70u); f_00cd8a19(c); /* call 0xcd8a19 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd4a7f; /* je 0xcd4a7f */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_00cd4ab7; /* jmp 0xcd4ab7 */
L_00cd4a7f:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00cd4a85u); f_00cd86ed(c); /* call 0xcd86ed */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd4ab7; /* je 0xcd4ab7 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00cd4a9c; /* jb 0xcd4a9c */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00cd4a9c:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00cd4aa8u); f_00cd9160(c); /* call 0xcd9160 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00cd4ab4u); f_00cd86a8(c); /* call 0xcd86a8 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00cd4ab7:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00cd4aba:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00cd4b13; /* jne 0xcd4b13 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xce0a44u)); PUSH32(c, v_); } /* push dword ptr [0x10010a44] */
    { uint32_t t_ = R32((uint32_t)(0xcdc05cu)); PUSH32(c, 0x00cd4acfu); call_indirect(c, t_); } /* call dword ptr [0x1000c05c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd4b13; /* je 0xcd4b13 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00cd4ae5; /* jb 0xcd4ae5 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00cd4ae5:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00cd4aefu); f_00cd9160(c); /* call 0xcd9160 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00cd4afbu); f_00cd86a8(c); /* call 0xcd86a8 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00cd4b13; /* jmp 0xcd4b13 */
L_00cd4b00:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xce0a44u)); PUSH32(c, v_); } /* push dword ptr [0x10010a44] */
    { uint32_t t_ = R32((uint32_t)(0xcdc058u)); PUSH32(c, 0x00cd4b10u); call_indirect(c, t_); } /* call dword ptr [0x1000c058] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_00cd4b13:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00cd4b1cu); f_00cd4b42(c); /* call 0xcd4b42 */
L_00cd4b1c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00cd4b89(c); return; } /* jne 0xcd4b89 */
    (void)sub32(c, R32((uint32_t)(0xce0650u)), c->edi); /* cmp dword ptr [0x10010650], edi */
    if (c->zf) { f_00cd4b89(c); return; } /* je 0xcd4b89 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd4b31u); f_00cd9143(c); /* call 0xcd9143 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00cd4a1d; /* jne 0xcd4a1d */
    { f_00cd4b87(c); return; } /* jmp 0xcd4b87 */
}

void f_00cd4a1a(CPU *c) { /* PTR_00cd4a1a */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_00cd4a1d:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00cd4b1c; /* ja 0xcd4b1c */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00cd4a30u); f_00cd3abb(c); /* call 0xcd3abb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00cd4a46u); f_00cd8651(c); /* call 0xcd8651 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00cd4b00; /* je 0xcd4b00 */
    (void)sub32(c, c->esi, R32((uint32_t)(0xcdf834u))); /* cmp esi, dword ptr [0x1000f834] */
    if (!c->cf) goto L_00cd4aba; /* jae 0xcd4aba */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 4)); /* shr ebx, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00cd4a70u); f_00cd8a19(c); /* call 0xcd8a19 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd4a7f; /* je 0xcd4a7f */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_00cd4ab7; /* jmp 0xcd4ab7 */
L_00cd4a7f:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00cd4a85u); f_00cd86ed(c); /* call 0xcd86ed */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd4ab7; /* je 0xcd4ab7 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00cd4a9c; /* jb 0xcd4a9c */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00cd4a9c:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00cd4aa8u); f_00cd9160(c); /* call 0xcd9160 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00cd4ab4u); f_00cd86a8(c); /* call 0xcd86a8 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00cd4ab7:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00cd4aba:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00cd4b13; /* jne 0xcd4b13 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xce0a44u)); PUSH32(c, v_); } /* push dword ptr [0x10010a44] */
    { uint32_t t_ = R32((uint32_t)(0xcdc05cu)); PUSH32(c, 0x00cd4acfu); call_indirect(c, t_); } /* call dword ptr [0x1000c05c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd4b13; /* je 0xcd4b13 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00cd4ae5; /* jb 0xcd4ae5 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00cd4ae5:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00cd4aefu); f_00cd9160(c); /* call 0xcd9160 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00cd4afbu); f_00cd86a8(c); /* call 0xcd86a8 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00cd4b13; /* jmp 0xcd4b13 */
L_00cd4b00:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xce0a44u)); PUSH32(c, v_); } /* push dword ptr [0x10010a44] */
    { uint32_t t_ = R32((uint32_t)(0xcdc058u)); PUSH32(c, 0x00cd4b10u); call_indirect(c, t_); } /* call dword ptr [0x1000c058] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_00cd4b13:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00cd4b1cu); f_00cd4b42(c); /* call 0xcd4b42 */
L_00cd4b1c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00cd4b89(c); return; } /* jne 0xcd4b89 */
    (void)sub32(c, R32((uint32_t)(0xce0650u)), c->edi); /* cmp dword ptr [0x10010650], edi */
    if (c->zf) { f_00cd4b89(c); return; } /* je 0xcd4b89 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd4b31u); f_00cd9143(c); /* call 0xcd9143 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00cd4a1d; /* jne 0xcd4a1d */
    { f_00cd4b87(c); return; } /* jmp 0xcd4b87 */
}

void f_00cd4a1d(CPU *c) { /* PTR_00cd4a1d */
    PREEMPT_POLL(c);
L_00cd4a1d:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00cd4b1c; /* ja 0xcd4b1c */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00cd4a30u); f_00cd3abb(c); /* call 0xcd3abb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00cd4a46u); f_00cd8651(c); /* call 0xcd8651 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00cd4b00; /* je 0xcd4b00 */
    (void)sub32(c, c->esi, R32((uint32_t)(0xcdf834u))); /* cmp esi, dword ptr [0x1000f834] */
    if (!c->cf) goto L_00cd4aba; /* jae 0xcd4aba */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 4)); /* shr ebx, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00cd4a70u); f_00cd8a19(c); /* call 0xcd8a19 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd4a7f; /* je 0xcd4a7f */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_00cd4ab7; /* jmp 0xcd4ab7 */
L_00cd4a7f:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00cd4a85u); f_00cd86ed(c); /* call 0xcd86ed */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd4ab7; /* je 0xcd4ab7 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00cd4a9c; /* jb 0xcd4a9c */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00cd4a9c:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00cd4aa8u); f_00cd9160(c); /* call 0xcd9160 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00cd4ab4u); f_00cd86a8(c); /* call 0xcd86a8 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00cd4ab7:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00cd4aba:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00cd4b13; /* jne 0xcd4b13 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xce0a44u)); PUSH32(c, v_); } /* push dword ptr [0x10010a44] */
    { uint32_t t_ = R32((uint32_t)(0xcdc05cu)); PUSH32(c, 0x00cd4acfu); call_indirect(c, t_); } /* call dword ptr [0x1000c05c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd4b13; /* je 0xcd4b13 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00cd4ae5; /* jb 0xcd4ae5 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00cd4ae5:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00cd4aefu); f_00cd9160(c); /* call 0xcd9160 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00cd4afbu); f_00cd86a8(c); /* call 0xcd86a8 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00cd4b13; /* jmp 0xcd4b13 */
L_00cd4b00:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xce0a44u)); PUSH32(c, v_); } /* push dword ptr [0x10010a44] */
    { uint32_t t_ = R32((uint32_t)(0xcdc058u)); PUSH32(c, 0x00cd4b10u); call_indirect(c, t_); } /* call dword ptr [0x1000c058] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_00cd4b13:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00cd4b1cu); f_00cd4b42(c); /* call 0xcd4b42 */
L_00cd4b1c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00cd4b89(c); return; } /* jne 0xcd4b89 */
    (void)sub32(c, R32((uint32_t)(0xce0650u)), c->edi); /* cmp dword ptr [0x10010650], edi */
    if (c->zf) { f_00cd4b89(c); return; } /* je 0xcd4b89 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd4b31u); f_00cd9143(c); /* call 0xcd9143 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00cd4a1d; /* jne 0xcd4a1d */
    { f_00cd4b87(c); return; } /* jmp 0xcd4b87 */
}

void f_00cd4a7f(CPU *c) { /* PTR_00cd4a7f */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00cd4a85u); f_00cd86ed(c); /* call 0xcd86ed */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd4ab7; /* je 0xcd4ab7 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00cd4a9c; /* jb 0xcd4a9c */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00cd4a9c:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00cd4aa8u); f_00cd9160(c); /* call 0xcd9160 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00cd4ab4u); f_00cd86a8(c); /* call 0xcd86a8 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00cd4ab7:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00cd4b13; /* jne 0xcd4b13 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xce0a44u)); PUSH32(c, v_); } /* push dword ptr [0x10010a44] */
    { uint32_t t_ = R32((uint32_t)(0xcdc05cu)); PUSH32(c, 0x00cd4acfu); call_indirect(c, t_); } /* call dword ptr [0x1000c05c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd4b13; /* je 0xcd4b13 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00cd4ae5; /* jb 0xcd4ae5 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00cd4ae5:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00cd4aefu); f_00cd9160(c); /* call 0xcd9160 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00cd4afbu); f_00cd86a8(c); /* call 0xcd86a8 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00cd4b13; /* jmp 0xcd4b13 */
L_00cd4b13:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00cd4b1cu); f_00cd4b42(c); /* call 0xcd4b42 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00cd4b89(c); return; } /* jne 0xcd4b89 */
    (void)sub32(c, R32((uint32_t)(0xce0650u)), c->edi); /* cmp dword ptr [0x10010650], edi */
    if (c->zf) { f_00cd4b89(c); return; } /* je 0xcd4b89 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd4b31u); f_00cd9143(c); /* call 0xcd9143 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00cd4a1d(c); return; } /* jne 0xcd4a1d */
    { f_00cd4b87(c); return; } /* jmp 0xcd4b87 */
}

void f_00cd4a9c(CPU *c) { /* PTR_00cd4a9c */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00cd4aa8u); f_00cd9160(c); /* call 0xcd9160 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00cd4ab4u); f_00cd86a8(c); /* call 0xcd86a8 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00cd4b13; /* jne 0xcd4b13 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xce0a44u)); PUSH32(c, v_); } /* push dword ptr [0x10010a44] */
    { uint32_t t_ = R32((uint32_t)(0xcdc05cu)); PUSH32(c, 0x00cd4acfu); call_indirect(c, t_); } /* call dword ptr [0x1000c05c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd4b13; /* je 0xcd4b13 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00cd4ae5; /* jb 0xcd4ae5 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00cd4ae5:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00cd4aefu); f_00cd9160(c); /* call 0xcd9160 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00cd4afbu); f_00cd86a8(c); /* call 0xcd86a8 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00cd4b13; /* jmp 0xcd4b13 */
L_00cd4b13:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00cd4b1cu); f_00cd4b42(c); /* call 0xcd4b42 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00cd4b89(c); return; } /* jne 0xcd4b89 */
    (void)sub32(c, R32((uint32_t)(0xce0650u)), c->edi); /* cmp dword ptr [0x10010650], edi */
    if (c->zf) { f_00cd4b89(c); return; } /* je 0xcd4b89 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd4b31u); f_00cd9143(c); /* call 0xcd9143 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00cd4a1d(c); return; } /* jne 0xcd4a1d */
    { f_00cd4b87(c); return; } /* jmp 0xcd4b87 */
}

void f_00cd4ab7(CPU *c) { /* PTR_00cd4ab7 */
    PREEMPT_POLL(c);
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00cd4b13; /* jne 0xcd4b13 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xce0a44u)); PUSH32(c, v_); } /* push dword ptr [0x10010a44] */
    { uint32_t t_ = R32((uint32_t)(0xcdc05cu)); PUSH32(c, 0x00cd4acfu); call_indirect(c, t_); } /* call dword ptr [0x1000c05c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd4b13; /* je 0xcd4b13 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00cd4ae5; /* jb 0xcd4ae5 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00cd4ae5:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00cd4aefu); f_00cd9160(c); /* call 0xcd9160 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00cd4afbu); f_00cd86a8(c); /* call 0xcd86a8 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00cd4b13; /* jmp 0xcd4b13 */
L_00cd4b13:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00cd4b1cu); f_00cd4b42(c); /* call 0xcd4b42 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00cd4b89(c); return; } /* jne 0xcd4b89 */
    (void)sub32(c, R32((uint32_t)(0xce0650u)), c->edi); /* cmp dword ptr [0x10010650], edi */
    if (c->zf) { f_00cd4b89(c); return; } /* je 0xcd4b89 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd4b31u); f_00cd9143(c); /* call 0xcd9143 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00cd4a1d(c); return; } /* jne 0xcd4a1d */
    { f_00cd4b87(c); return; } /* jmp 0xcd4b87 */
}

void f_00cd4aba(CPU *c) { /* PTR_00cd4aba */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00cd4b13; /* jne 0xcd4b13 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xce0a44u)); PUSH32(c, v_); } /* push dword ptr [0x10010a44] */
    { uint32_t t_ = R32((uint32_t)(0xcdc05cu)); PUSH32(c, 0x00cd4acfu); call_indirect(c, t_); } /* call dword ptr [0x1000c05c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd4b13; /* je 0xcd4b13 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00cd4ae5; /* jb 0xcd4ae5 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00cd4ae5:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00cd4aefu); f_00cd9160(c); /* call 0xcd9160 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00cd4afbu); f_00cd86a8(c); /* call 0xcd86a8 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00cd4b13; /* jmp 0xcd4b13 */
L_00cd4b13:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00cd4b1cu); f_00cd4b42(c); /* call 0xcd4b42 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00cd4b89(c); return; } /* jne 0xcd4b89 */
    (void)sub32(c, R32((uint32_t)(0xce0650u)), c->edi); /* cmp dword ptr [0x10010650], edi */
    if (c->zf) { f_00cd4b89(c); return; } /* je 0xcd4b89 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd4b31u); f_00cd9143(c); /* call 0xcd9143 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00cd4a1d(c); return; } /* jne 0xcd4a1d */
    { f_00cd4b87(c); return; } /* jmp 0xcd4b87 */
}

void f_00cd4ae5(CPU *c) { /* PTR_00cd4ae5 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00cd4aefu); f_00cd9160(c); /* call 0xcd9160 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00cd4afbu); f_00cd86a8(c); /* call 0xcd86a8 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00cd4b13; /* jmp 0xcd4b13 */
L_00cd4b13:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00cd4b1cu); f_00cd4b42(c); /* call 0xcd4b42 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00cd4b89(c); return; } /* jne 0xcd4b89 */
    (void)sub32(c, R32((uint32_t)(0xce0650u)), c->edi); /* cmp dword ptr [0x10010650], edi */
    if (c->zf) { f_00cd4b89(c); return; } /* je 0xcd4b89 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd4b31u); f_00cd9143(c); /* call 0xcd9143 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00cd4a1d(c); return; } /* jne 0xcd4a1d */
    { f_00cd4b87(c); return; } /* jmp 0xcd4b87 */
}

void f_00cd4b00(CPU *c) { /* PTR_00cd4b00 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xce0a44u)); PUSH32(c, v_); } /* push dword ptr [0x10010a44] */
    { uint32_t t_ = R32((uint32_t)(0xcdc058u)); PUSH32(c, 0x00cd4b10u); call_indirect(c, t_); } /* call dword ptr [0x1000c058] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00cd4b1cu); f_00cd4b42(c); /* call 0xcd4b42 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00cd4b89(c); return; } /* jne 0xcd4b89 */
    (void)sub32(c, R32((uint32_t)(0xce0650u)), c->edi); /* cmp dword ptr [0x10010650], edi */
    if (c->zf) { f_00cd4b89(c); return; } /* je 0xcd4b89 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd4b31u); f_00cd9143(c); /* call 0xcd9143 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00cd4a1d(c); return; } /* jne 0xcd4a1d */
    { f_00cd4b87(c); return; } /* jmp 0xcd4b87 */
}

void f_00cd4b13(CPU *c) { /* PTR_00cd4b13 */
    PREEMPT_POLL(c);
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00cd4b1cu); f_00cd4b42(c); /* call 0xcd4b42 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00cd4b89(c); return; } /* jne 0xcd4b89 */
    (void)sub32(c, R32((uint32_t)(0xce0650u)), c->edi); /* cmp dword ptr [0x10010650], edi */
    if (c->zf) { f_00cd4b89(c); return; } /* je 0xcd4b89 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd4b31u); f_00cd9143(c); /* call 0xcd9143 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00cd4a1d(c); return; } /* jne 0xcd4a1d */
    { f_00cd4b87(c); return; } /* jmp 0xcd4b87 */
}

void f_00cd4b1c(CPU *c) { /* PTR_00cd4b1c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00cd4b89(c); return; } /* jne 0xcd4b89 */
    (void)sub32(c, R32((uint32_t)(0xce0650u)), c->edi); /* cmp dword ptr [0x10010650], edi */
    if (c->zf) { f_00cd4b89(c); return; } /* je 0xcd4b89 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd4b31u); f_00cd9143(c); /* call 0xcd9143 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00cd4a1d(c); return; } /* jne 0xcd4a1d */
    { f_00cd4b87(c); return; } /* jmp 0xcd4b87 */
}

void f_00cd4b3c(CPU *c) { /* PTR_00cd4b3c */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    { f_00cd4b42(c); return; }
}

void f_00cd4b42(CPU *c) { /* FUN_10004b42 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00cd4b49u); f_00cd3b1c(c); /* call 0xcd3b1c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    c->esp += 4; return; /* ret  */
}

void f_00cd4b4d(CPU *c) { /* PTR_00cd4b4d */
    PREEMPT_POLL(c);
L_00cd4b4d:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00cd4b70; /* ja 0xcd4b70 */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_00cd4b5b; /* jne 0xcd4b5b */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00cd4b5b:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0xce0a44u)); PUSH32(c, v_); } /* push dword ptr [0x10010a44] */
    { uint32_t t_ = R32((uint32_t)(0xcdc058u)); PUSH32(c, 0x00cd4b70u); call_indirect(c, t_); } /* call dword ptr [0x1000c058] */
L_00cd4b70:;
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_00cd4b89; /* jne 0xcd4b89 */
    (void)sub32(c, R32((uint32_t)(0xce0650u)), c->edi); /* cmp dword ptr [0x10010650], edi */
    if (c->zf) goto L_00cd4b89; /* je 0xcd4b89 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd4b82u); f_00cd9143(c); /* call 0xcd9143 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00cd4b4d; /* jne 0xcd4b4d */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00cd4b89:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd4b5b(CPU *c) { /* PTR_00cd4b5b */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0xce0a44u)); PUSH32(c, v_); } /* push dword ptr [0x10010a44] */
    { uint32_t t_ = R32((uint32_t)(0xcdc058u)); PUSH32(c, 0x00cd4b70u); call_indirect(c, t_); } /* call dword ptr [0x1000c058] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_00cd4b89; /* jne 0xcd4b89 */
    (void)sub32(c, R32((uint32_t)(0xce0650u)), c->edi); /* cmp dword ptr [0x10010650], edi */
    if (c->zf) goto L_00cd4b89; /* je 0xcd4b89 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd4b82u); f_00cd9143(c); /* call 0xcd9143 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00cd4b4d(c); return; } /* jne 0xcd4b4d */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00cd4b89:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd4b70(CPU *c) { /* PTR_00cd4b70 */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_00cd4b89; /* jne 0xcd4b89 */
    (void)sub32(c, R32((uint32_t)(0xce0650u)), c->edi); /* cmp dword ptr [0x10010650], edi */
    if (c->zf) goto L_00cd4b89; /* je 0xcd4b89 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd4b82u); f_00cd9143(c); /* call 0xcd9143 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00cd4b4d(c); return; } /* jne 0xcd4b4d */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00cd4b89:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd4b87(CPU *c) { /* PTR_00cd4b87 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd4b89(CPU *c) { /* PTR_00cd4b89 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd4b98(CPU *c) { /* FUN_10004b98 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xcdc340u; PUSH32(c, v_); } /* push 0x1000c340 */
    { uint32_t v_ = 0xcd4dc8u; PUSH32(c, v_); } /* push 0x10004dc8 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x1cu)); /* sub esp, 0x1c */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(0xce0a48u))); /* mov eax, dword ptr [0x10010a48] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_00cd4c0b; /* jne 0xcd4c0b */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00cd4bccu); f_00cd3abb(c); /* call 0xcd3abb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd4bdau); f_00cd78f6(c); /* call 0xcd78f6 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd4bed; /* je 0xcd4bed */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0xfffffffcu))); /* mov esi, dword ptr [esi - 4] */
    c->esi = (uint32_t)(sub32(c, c->esi, (uint32_t)0x9u)); /* sub esi, 9 */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x20], esi */
    goto L_00cd4bf0; /* jmp 0xcd4bf0 */
L_00cd4bed:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
L_00cd4bf0:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00cd4bf9u); f_00cd4c02(c); /* call 0xcd4c02 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x1c], 0 */
    goto L_00cd4c54; /* jmp 0xcd4c54 */
L_00cd4c0b:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00cd4c56; /* jne 0xcd4c56 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00cd4c17u); f_00cd3abb(c); /* call 0xcd3abb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffdcu)); /* lea eax, [ebp - 0x24] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00cd4c2fu); f_00cd8651(c); /* call 0xcd8651 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x28], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd4c44; /* je 0xcd4c44 */
    c->esi = (uint32_t)((uint32_t)R8((uint32_t)(c->eax))); /* movzx esi, byte ptr [eax] */
    c->esi = (uint32_t)(shl32(c, c->esi, 4)); /* shl esi, 4 */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x20], esi */
    goto L_00cd4c47; /* jmp 0xcd4c47 */
L_00cd4c44:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
L_00cd4c47:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00cd4c50u); f_00cd4c7d(c); /* call 0xcd4c7d */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x28], 0 */
L_00cd4c54:;
    if (!c->zf) goto L_00cd4c69; /* jne 0xcd4c69 */
L_00cd4c56:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xce0a44u)); PUSH32(c, v_); } /* push dword ptr [0x10010a44] */
    { uint32_t t_ = R32((uint32_t)(0xcdc060u)); PUSH32(c, 0x00cd4c67u); call_indirect(c, t_); } /* call dword ptr [0x1000c060] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_00cd4c69:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd4bff(CPU *c) { /* PTR_00cd4bff */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
    { f_00cd4c02(c); return; }
}

void f_00cd4c02(CPU *c) { /* FUN_10004c02 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00cd4c09u); f_00cd3b1c(c); /* call 0xcd3b1c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00cd4c0b(CPU *c) { /* PTR_00cd4c0b */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00cd4c56; /* jne 0xcd4c56 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00cd4c17u); f_00cd3abb(c); /* call 0xcd3abb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffdcu)); /* lea eax, [ebp - 0x24] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00cd4c2fu); f_00cd8651(c); /* call 0xcd8651 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x28], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd4c44; /* je 0xcd4c44 */
    c->esi = (uint32_t)((uint32_t)R8((uint32_t)(c->eax))); /* movzx esi, byte ptr [eax] */
    c->esi = (uint32_t)(shl32(c, c->esi, 4)); /* shl esi, 4 */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x20], esi */
    goto L_00cd4c47; /* jmp 0xcd4c47 */
L_00cd4c44:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
L_00cd4c47:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00cd4c50u); f_00cd4c7d(c); /* call 0xcd4c7d */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x28], 0 */
    if (!c->zf) goto L_00cd4c69; /* jne 0xcd4c69 */
L_00cd4c56:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xce0a44u)); PUSH32(c, v_); } /* push dword ptr [0x10010a44] */
    { uint32_t t_ = R32((uint32_t)(0xcdc060u)); PUSH32(c, 0x00cd4c67u); call_indirect(c, t_); } /* call dword ptr [0x1000c060] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_00cd4c69:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd4c44(CPU *c) { /* PTR_00cd4c44 */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00cd4c50u); f_00cd4c7d(c); /* call 0xcd4c7d */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x28], 0 */
    if (!c->zf) goto L_00cd4c69; /* jne 0xcd4c69 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xce0a44u)); PUSH32(c, v_); } /* push dword ptr [0x10010a44] */
    { uint32_t t_ = R32((uint32_t)(0xcdc060u)); PUSH32(c, 0x00cd4c67u); call_indirect(c, t_); } /* call dword ptr [0x1000c060] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_00cd4c69:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd4c47(CPU *c) { /* PTR_00cd4c47 */
    PREEMPT_POLL(c);
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00cd4c50u); f_00cd4c7d(c); /* call 0xcd4c7d */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x28], 0 */
    if (!c->zf) goto L_00cd4c69; /* jne 0xcd4c69 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xce0a44u)); PUSH32(c, v_); } /* push dword ptr [0x10010a44] */
    { uint32_t t_ = R32((uint32_t)(0xcdc060u)); PUSH32(c, 0x00cd4c67u); call_indirect(c, t_); } /* call dword ptr [0x1000c060] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_00cd4c69:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd4c54(CPU *c) { /* PTR_00cd4c54 */
    PREEMPT_POLL(c);
    if (!c->zf) goto L_00cd4c69; /* jne 0xcd4c69 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xce0a44u)); PUSH32(c, v_); } /* push dword ptr [0x10010a44] */
    { uint32_t t_ = R32((uint32_t)(0xcdc060u)); PUSH32(c, 0x00cd4c67u); call_indirect(c, t_); } /* call dword ptr [0x1000c060] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_00cd4c69:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd4c56(CPU *c) { /* PTR_00cd4c56 */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xce0a44u)); PUSH32(c, v_); } /* push dword ptr [0x10010a44] */
    { uint32_t t_ = R32((uint32_t)(0xcdc060u)); PUSH32(c, 0x00cd4c67u); call_indirect(c, t_); } /* call dword ptr [0x1000c060] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd4c69(CPU *c) { /* PTR_00cd4c69 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd4c7a(CPU *c) { /* PTR_00cd4c7a */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
    { f_00cd4c7d(c); return; }
}

void f_00cd4c7d(CPU *c) { /* FUN_10004c7d */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00cd4c84u); f_00cd3b1c(c); /* call 0xcd3b1c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00cd4c86(CPU *c) { /* _malloc */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(0xce0650u)); PUSH32(c, v_); } /* push dword ptr [0x10010650] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    PUSH32(c, 0x00cd4c95u); f_00cd4c98(c); /* call 0xcd4c98 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00cd4c98(CPU *c) { /* __nh_malloc */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->esp + 0x4u)), (uint32_t)0xffffffe0u); /* cmp dword ptr [esp + 4], -0x20 */
    if ((!c->cf && !c->zf)) goto L_00cd4cc1; /* ja 0xcd4cc1 */
L_00cd4c9f:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    PUSH32(c, 0x00cd4ca8u); f_00cd4cc4(c); /* call 0xcd4cc4 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00cd4cc3; /* jne 0xcd4cc3 */
    (void)sub32(c, R32((uint32_t)(c->esp + 0x8u)), c->eax); /* cmp dword ptr [esp + 8], eax */
    if (c->zf) goto L_00cd4cc3; /* je 0xcd4cc3 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    PUSH32(c, 0x00cd4cbcu); f_00cd9143(c); /* call 0xcd9143 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00cd4c9f; /* jne 0xcd4c9f */
L_00cd4cc1:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00cd4cc3:;
    c->esp += 4; return; /* ret  */
}

void f_00cd4cc4(CPU *c) { /* FUN_10004cc4 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xcdc358u; PUSH32(c, v_); } /* push 0x1000c358 */
    { uint32_t v_ = 0xcd4dc8u; PUSH32(c, v_); } /* push 0x10004dc8 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(0xce0a48u))); /* mov eax, dword ptr [0x10010a48] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_00cd4d34; /* jne 0xcd4d34 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    (void)sub32(c, c->esi, R32((uint32_t)(0xce0a40u))); /* cmp esi, dword ptr [0x10010a40] */
    if ((!c->cf && !c->zf)) goto L_00cd4d93; /* ja 0xcd4d93 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00cd4d07u); f_00cd3abb(c); /* call 0xcd3abb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd4d12u); f_00cd7c4a(c); /* call 0xcd7c4a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00cd4d1fu); f_00cd4d2b(c); /* call 0xcd4d2b */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd4d93; /* je 0xcd4d93 */
    goto L_00cd4db1; /* jmp 0xcd4db1 */
L_00cd4d34:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00cd4d93; /* jne 0xcd4d93 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd4d48; /* je 0xcd4d48 */
    c->esi = (uint32_t)((uint32_t)(c->eax + 0xfu)); /* lea esi, [eax + 0xf] */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    goto L_00cd4d4b; /* jmp 0xcd4d4b */
L_00cd4d48:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00cd4d4b:;
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
    (void)sub32(c, c->esi, R32((uint32_t)(0xcdf834u))); /* cmp esi, dword ptr [0x1000f834] */
    if ((!c->cf && !c->zf)) goto L_00cd4d84; /* ja 0xcd4d84 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00cd4d5du); f_00cd3abb(c); /* call 0xcd3abb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd4d70u); f_00cd86ed(c); /* call 0xcd86ed */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00cd4d7du); f_00cd4d8a(c); /* call 0xcd4d8a */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00cd4db1; /* jne 0xcd4db1 */
L_00cd4d84:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    goto L_00cd4da3; /* jmp 0xcd4da3 */
L_00cd4d93:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00cd4d9d; /* jne 0xcd4d9d */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00cd4d9d:;
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xfu)); /* add eax, 0xf */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xf0u))); /* and al, 0xf0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
L_00cd4da3:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xce0a44u)); PUSH32(c, v_); } /* push dword ptr [0x10010a44] */
    { uint32_t t_ = R32((uint32_t)(0xcdc05cu)); PUSH32(c, 0x00cd4db1u); call_indirect(c, t_); } /* call dword ptr [0x1000c05c] */
L_00cd4db1:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd4d2b(CPU *c) { /* FUN_10004d2b */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00cd4d32u); f_00cd3b1c(c); /* call 0xcd3b1c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00cd4d34(CPU *c) { /* PTR_00cd4d34 */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) { f_00cd4d93(c); return; } /* jne 0xcd4d93 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd4d48; /* je 0xcd4d48 */
    c->esi = (uint32_t)((uint32_t)(c->eax + 0xfu)); /* lea esi, [eax + 0xf] */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    goto L_00cd4d4b; /* jmp 0xcd4d4b */
L_00cd4d48:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00cd4d4b:;
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
    (void)sub32(c, c->esi, R32((uint32_t)(0xcdf834u))); /* cmp esi, dword ptr [0x1000f834] */
    if ((!c->cf && !c->zf)) goto L_00cd4d84; /* ja 0xcd4d84 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00cd4d5du); f_00cd3abb(c); /* call 0xcd3abb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd4d70u); f_00cd86ed(c); /* call 0xcd86ed */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00cd4d7du); f_00cd4d8a(c); /* call 0xcd4d8a */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00cd4db1(c); return; } /* jne 0xcd4db1 */
L_00cd4d84:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { f_00cd4da3(c); return; } /* jmp 0xcd4da3 */
}

void f_00cd4d48(CPU *c) { /* PTR_00cd4d48 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
    (void)sub32(c, c->esi, R32((uint32_t)(0xcdf834u))); /* cmp esi, dword ptr [0x1000f834] */
    if ((!c->cf && !c->zf)) goto L_00cd4d84; /* ja 0xcd4d84 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00cd4d5du); f_00cd3abb(c); /* call 0xcd3abb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd4d70u); f_00cd86ed(c); /* call 0xcd86ed */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00cd4d7du); f_00cd4d8a(c); /* call 0xcd4d8a */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00cd4db1(c); return; } /* jne 0xcd4db1 */
L_00cd4d84:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { f_00cd4da3(c); return; } /* jmp 0xcd4da3 */
}

void f_00cd4d4b(CPU *c) { /* PTR_00cd4d4b */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
    (void)sub32(c, c->esi, R32((uint32_t)(0xcdf834u))); /* cmp esi, dword ptr [0x1000f834] */
    if ((!c->cf && !c->zf)) goto L_00cd4d84; /* ja 0xcd4d84 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00cd4d5du); f_00cd3abb(c); /* call 0xcd3abb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd4d70u); f_00cd86ed(c); /* call 0xcd86ed */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00cd4d7du); f_00cd4d8a(c); /* call 0xcd4d8a */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00cd4db1(c); return; } /* jne 0xcd4db1 */
L_00cd4d84:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { f_00cd4da3(c); return; } /* jmp 0xcd4da3 */
}

void f_00cd4d84(CPU *c) { /* PTR_00cd4d84 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { f_00cd4da3(c); return; } /* jmp 0xcd4da3 */
}

void f_00cd4d87(CPU *c) { /* PTR_00cd4d87 */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    { f_00cd4d8a(c); return; }
}

void f_00cd4d8a(CPU *c) { /* FUN_10004d8a */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00cd4d91u); f_00cd3b1c(c); /* call 0xcd3b1c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00cd4d93(CPU *c) { /* PTR_00cd4d93 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00cd4d9d; /* jne 0xcd4d9d */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00cd4d9d:;
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xfu)); /* add eax, 0xf */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xf0u))); /* and al, 0xf0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xce0a44u)); PUSH32(c, v_); } /* push dword ptr [0x10010a44] */
    { uint32_t t_ = R32((uint32_t)(0xcdc05cu)); PUSH32(c, 0x00cd4db1u); call_indirect(c, t_); } /* call dword ptr [0x1000c05c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd4d9d(CPU *c) { /* PTR_00cd4d9d */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xfu)); /* add eax, 0xf */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xf0u))); /* and al, 0xf0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xce0a44u)); PUSH32(c, v_); } /* push dword ptr [0x10010a44] */
    { uint32_t t_ = R32((uint32_t)(0xcdc05cu)); PUSH32(c, 0x00cd4db1u); call_indirect(c, t_); } /* call dword ptr [0x1000c05c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd4da3(CPU *c) { /* PTR_00cd4da3 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xce0a44u)); PUSH32(c, v_); } /* push dword ptr [0x10010a44] */
    { uint32_t t_ = R32((uint32_t)(0xcdc05cu)); PUSH32(c, 0x00cd4db1u); call_indirect(c, t_); } /* call dword ptr [0x1000c05c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd4db1(CPU *c) { /* PTR_00cd4db1 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd4dc0(CPU *c) { /* PTR_00cd4dc0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    c->edx = (c->edx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->edx >> 8)) ^ R8((uint32_t)(c->eax))))) << 8); /* xor dh, byte ptr [eax] */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) ^ ((uint8_t)(c->edx >> 8)))))); } /* xor byte ptr [eax], dh */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->df = 0; /* cld  */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ebx, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->eax + 0x4u)) & (uint32_t)0x6u)); /* test dword ptr [eax + 4], 6 */
    if (!c->zf) goto L_00cd4e68; /* jne 0xcd4e68 */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    W32((uint32_t)(c->ebx + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebx - 4], eax */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebx + 0xcu))); /* mov esi, dword ptr [ebx + 0xc] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov edi, dword ptr [ebx + 8] */
L_00cd4dfb:;
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (c->zf) goto L_00cd4e61; /* je 0xcd4e61 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea ecx, [esi + esi*2] */
    (void)sub32(c, R32((uint32_t)(c->edi + c->ecx * 4 + 0x4u)), (uint32_t)0x0u); /* cmp dword ptr [edi + ecx*4 + 4], 0 */
    if (c->zf) goto L_00cd4e4f; /* je 0xcd4e4f */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)((uint32_t)(c->ebx + 0x10u)); /* lea ebp, [ebx + 0x10] */
    { uint32_t t_ = R32((uint32_t)(c->edi + c->ecx * 4 + 0x4u)); PUSH32(c, 0x00cd4e13u); call_indirect(c, t_); } /* call dword ptr [edi + ecx*4 + 4] */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ebx, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->eax))); /* or eax, eax */
    if (c->zf) goto L_00cd4e4f; /* je 0xcd4e4f */
    if (c->sf) goto L_00cd4e5a; /* js 0xcd4e5a */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov edi, dword ptr [ebx + 8] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00cd4e27u); f_00cd2ec8(c); /* call 0xcd2ec8 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->ebp = (uint32_t)((uint32_t)(c->ebx + 0x10u)); /* lea ebp, [ebx + 0x10] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00cd4e34u); f_00cd2f0a(c); /* call 0xcd2f0a */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea ecx, [esi + esi*2] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + c->ecx * 4 + 0x8u))); /* mov eax, dword ptr [edi + ecx*4 + 8] */
    PUSH32(c, 0x00cd4e45u); f_00cd2f9e(c); /* call 0xcd2f9e */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + c->ecx * 4))); /* mov eax, dword ptr [edi + ecx*4] */
    W32((uint32_t)(c->ebx + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 0xc], eax */
    { uint32_t t_ = R32((uint32_t)(c->edi + c->ecx * 4 + 0x8u)); PUSH32(c, 0x00cd4e4fu); call_indirect(c, t_); } /* call dword ptr [edi + ecx*4 + 8] */
L_00cd4e4f:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov edi, dword ptr [ebx + 8] */
    c->ecx = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea ecx, [esi + esi*2] */
    c->esi = (uint32_t)(R32((uint32_t)(c->edi + c->ecx * 4))); /* mov esi, dword ptr [edi + ecx*4] */
    goto L_00cd4dfb; /* jmp 0xcd4dfb */
L_00cd4e5a:;
    c->eax = (uint32_t)((uint32_t)0x0u); /* mov eax, 0 */
    goto L_00cd4e7d; /* jmp 0xcd4e7d */
L_00cd4e61:;
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    goto L_00cd4e7d; /* jmp 0xcd4e7d */
L_00cd4e68:;
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)((uint32_t)(c->ebx + 0x10u)); /* lea ebp, [ebx + 0x10] */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00cd4e74u); f_00cd2f0a(c); /* call 0xcd2f0a */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
L_00cd4e7d:;
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00cd4e85(CPU *c) { /* FUN_10004e85 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov ebp, dword ptr [ecx] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x1cu))); /* mov eax, dword ptr [ecx + 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x18u))); /* mov eax, dword ptr [ecx + 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd4e99u); f_00cd2f0a(c); /* call 0xcd2f0a */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 8; return; /* ret 4 */
}

void f_00cd4ea0(CPU *c) { /* __cintrindisp2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xfffffd30u)); /* add esp, 0xfffffd30 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    ; /* wait  */
    W16((uint32_t)(c->ebp + 0xffffff5cu), c->fpu_cw); /* fnstcw word ptr [ebp - 0xa4] */
    ; /* wait  */
    (void)sub32(c, R32((uint32_t)(0xcdfb28u)), (uint32_t)0x0u); /* cmp dword ptr [0x1000fb28], 0 */
    if (c->zf) goto L_00cd4ecf; /* je 0xcd4ecf */
L_00cd4ebb:;
    PUSH32(c, 0x00cd4ec0u); f_00cd5177(c); /* call 0xcd5177 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffd38u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x3u)))); } /* or byte ptr [ebp - 0x2c8], 3 */
    PUSH32(c, 0x00cd4eccu); f_00cd4f6a(c); /* call 0xcd4f6a */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd4ecf:;
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    WF64((uint32_t)(c->ebp + 0xffffff7au), ST(0)); /* fst qword ptr [ebp - 0x86] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    WF64((uint32_t)(c->ebp + 0xffffff82u), ST(0)); /* fst qword ptr [ebp - 0x7e] */
    goto L_00cd4ebb; /* jmp 0xcd4ebb */
}

void f_00cd4ede(CPU *c) { /* __cintrindisp1 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xfffffd30u)); /* add esp, 0xfffffd30 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    ; /* wait  */
    W16((uint32_t)(c->ebp + 0xffffff5cu), c->fpu_cw); /* fnstcw word ptr [ebp - 0xa4] */
    (void)sub32(c, R32((uint32_t)(0xcdfb28u)), (uint32_t)0x0u); /* cmp dword ptr [0x1000fb28], 0 */
    if (c->zf) goto L_00cd4f13; /* je 0xcd4f13 */
L_00cd4ef8:;
    PUSH32(c, 0x00cd4efdu); f_00cd5110(c); /* call 0xcd5110 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffd38u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x1u)))); } /* or byte ptr [ebp - 0x2c8], 1 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffd38u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0xfdu)))); } /* and byte ptr [ebp - 0x2c8], 0xfd */
    PUSH32(c, 0x00cd4f10u); f_00cd4f6a(c); /* call 0xcd4f6a */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd4f13:;
    WF64((uint32_t)(c->ebp + 0xffffff7au), ST(0)); /* fst qword ptr [ebp - 0x86] */
    goto L_00cd4ef8; /* jmp 0xcd4ef8 */
}

void f_00cd4f1b(CPU *c) { /* __ctrandisp2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xfffffd30u)); /* add esp, 0xfffffd30 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00cd4f30u); f_00cd50ce(c); /* call 0xcd50ce */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    PUSH32(c, 0x00cd4f3eu); f_00cd50ce(c); /* call 0xcd50ce */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    ; /* wait  */
    W16((uint32_t)(c->ebp + 0xffffff5cu), c->fpu_cw); /* fnstcw word ptr [ebp - 0xa4] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffd38u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x2u)))); } /* or byte ptr [ebp - 0x2c8], 2 */
    W8((uint32_t)(c->ebp + 0xffffff71u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ebp - 0x8f], 1 */
    PUSH32(c, 0x00cd4f5bu); f_00cd5177(c); /* call 0xcd5177 */
    PUSH32(c, 0x00cd4f60u); f_00cd4f63(c); /* call 0xcd4f63 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd4f63(CPU *c) { /* FUN_10004f63 */
    PREEMPT_POLL(c);
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffd38u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0xfeu)))); } /* and byte ptr [ebp - 0x2c8], 0xfe */
    { f_00cd4f6a(c); return; }
}

void f_00cd4f6a(CPU *c) { /* FUN_10004f6a */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(0xce0470u)), (uint32_t)0x0u); /* cmp dword ptr [0x10010470], 0 */
    if (!c->zf) goto L_00cd4fbf; /* jne 0xcd4fbf */
    WF64((uint32_t)(c->ebp + 0xfffffd30u), ST(0)); /* fst qword ptr [ebp - 0x2d0] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0xffffff70u))); /* mov al, byte ptr [ebp - 0x90] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00cd4f9d; /* je 0xcd4f9d */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0xffu); /* cmp al, 0xff */
    if (c->zf) goto L_00cd4fc7; /* je 0xcd4fc7 */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0xfeu); /* cmp al, 0xfe */
    if (c->zf) goto L_00cd4fc7; /* je 0xcd4fc7 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00cd4fbf; /* je 0xcd4fbf */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->eax)); /* movsx eax, al */
    W32((uint32_t)(c->ebp + 0xffffff72u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x8e], eax */
    goto L_00cd5039; /* jmp 0xcd5039 */
L_00cd4f9d:;
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ebp + 0xffffff5cu))); /* mov ax, word ptr [ebp - 0xa4] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->eax) & (uint16_t)0x20u))); /* and ax, 0x20 */
    if (!c->zf) goto L_00cd4fbf; /* jne 0xcd4fbf */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->eax) & (uint16_t)0x20u))); /* and ax, 0x20 */
    if (c->zf) goto L_00cd4fbf; /* je 0xcd4fbf */
    W32((uint32_t)(c->ebp + 0xffffff72u), (uint32_t)((uint32_t)0x8u)); /* mov dword ptr [ebp - 0x8e], 8 */
    goto L_00cd5039; /* jmp 0xcd5039 */
L_00cd4fbf:;
    c->fpu_cw = R16((uint32_t)(c->ebp + 0xffffff5cu)); fpu_sync_rounding(c); /* fldcw word ptr [ebp - 0xa4] */
    ; /* wait  */
    c->esp += 4; return; /* ret  */
L_00cd4fc7:;
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ebp + 0xfffffd36u))); /* mov ax, word ptr [ebp - 0x2ca] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->eax) & (uint16_t)0x7ff0u))); /* and ax, 0x7ff0 */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->eax) | ((uint16_t)c->eax)))); /* or ax, ax */
    if (c->zf) goto L_00cd4fdf; /* je 0xcd4fdf */
    (void)sub16(c, ((uint16_t)c->eax), (uint16_t)0x7ff0u); /* cmp ax, 0x7ff0 */
    if (c->zf) goto L_00cd500d; /* je 0xcd500d */
    goto L_00cd4f9d; /* jmp 0xcd4f9d */
L_00cd4fdf:;
    W32((uint32_t)(c->ebp + 0xffffff72u), (uint32_t)((uint32_t)0x4u)); /* mov dword ptr [ebp - 0x8e], 4 */
    FPUSH(c, RF64((uint32_t)(0xcdc388u))); /* fld qword ptr [0x1000c388] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = ldexp(ST(0), (int)trunc(ST(1))); /* fscale  */
    ST(1) = ST(0); FPOP(c); /* fstp st(1) */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = fabs(ST(0)); /* fabs  */
    FCOM(c, ST(0), RF64((uint32_t)(0xcdc378u))); FPOP(c); /* fcomp qword ptr [0x1000c378] */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (!c->cf) goto L_00cd5039; /* jae 0xcd5039 */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(0xcdc398u))); /* fmul qword ptr [0x1000c398] */
    goto L_00cd5039; /* jmp 0xcd5039 */
L_00cd500d:;
    W32((uint32_t)(c->ebp + 0xffffff72u), (uint32_t)((uint32_t)0x3u)); /* mov dword ptr [ebp - 0x8e], 3 */
    FPUSH(c, RF64((uint32_t)(0xcdc380u))); /* fld qword ptr [0x1000c380] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = ldexp(ST(0), (int)trunc(ST(1))); /* fscale  */
    ST(1) = ST(0); FPOP(c); /* fstp st(1) */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = fabs(ST(0)); /* fabs  */
    FCOM(c, ST(0), RF64((uint32_t)(0xcdc370u))); FPOP(c); /* fcomp qword ptr [0x1000c370] */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if ((c->cf || c->zf)) goto L_00cd5039; /* jbe 0xcd5039 */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(0xcdc390u))); /* fmul qword ptr [0x1000c390] */
L_00cd5039:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffff6cu))); /* mov ebx, dword ptr [ebp - 0x94] */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    W32((uint32_t)(c->ebp + 0xffffff76u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x8a], ebx */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffd38u)) & (uint8_t)0x1u)); /* test byte ptr [ebp - 0x2c8], 1 */
    if (!c->zf) goto L_00cd506b; /* jne 0xcd506b */
    c->df = 0; /* cld  */
    c->esi = (uint32_t)((uint32_t)(c->ebp + 0x8u)); /* lea esi, [ebp + 8] */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0xffffff7au)); /* lea edi, [ebp - 0x86] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    (void)sub8(c, R8((uint32_t)(c->ebx + 0xcu)), (uint8_t)0x1u); /* cmp byte ptr [ebx + 0xc], 1 */
    if (c->zf) goto L_00cd506b; /* je 0xcd506b */
    c->esi = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea esi, [ebp + 0x10] */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0xffffff82u)); /* lea edi, [ebp - 0x7e] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
L_00cd506b:;
    WF64((uint32_t)(c->ebp + 0xffffff8au), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0x76] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff72u)); /* lea eax, [ebp - 0x8e] */
    c->ebx = (uint32_t)((uint32_t)(c->ebp + 0xffffff5cu)); /* lea ebx, [ebp - 0xa4] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffff6cu))); /* mov ebx, dword ptr [ebp - 0x94] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebx + 0xeu))); /* mov al, byte ptr [ebx + 0xe] */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->eax)); /* movsx eax, al */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd508eu); f_00cd9495(c); /* call 0xcd9495 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xffffff8au))); /* fld qword ptr [ebp - 0x76] */
    goto L_00cd4fbf; /* jmp 0xcd4fbf */
}

void f_00cd509b(CPU *c) { /* __ctrandisp1 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xfffffd30u)); /* add esp, 0xfffffd30 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00cd50b0u); f_00cd50ce(c); /* call 0xcd50ce */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    ; /* wait  */
    W16((uint32_t)(c->ebp + 0xffffff5cu), c->fpu_cw); /* fnstcw word ptr [ebp - 0xa4] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffd38u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0xfdu)))); } /* and byte ptr [ebp - 0x2c8], 0xfd */
    PUSH32(c, 0x00cd50c6u); f_00cd5110(c); /* call 0xcd5110 */
    PUSH32(c, 0x00cd50cbu); f_00cd4f63(c); /* call 0xcd4f63 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd50ce(CPU *c) { /* __fload */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xfffffff4u)); /* add esp, -0xc */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ebp + 0xeu))); /* mov ax, word ptr [ebp + 0xe] */
    c->ebx = (c->ebx & 0xffff0000u) | (uint16_t)(((uint16_t)c->eax)); /* mov bx, ax */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->eax) & (uint16_t)0x7ff0u))); /* and ax, 0x7ff0 */
    (void)sub16(c, ((uint16_t)c->eax), (uint16_t)0x7ff0u); /* cmp ax, 0x7ff0 */
    if (!c->zf) goto L_00cd5104; /* jne 0xcd5104 */
    c->ebx = (c->ebx & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->ebx) | (uint16_t)0x7fffu))); /* or bx, 0x7fff */
    W16((uint32_t)(c->ebp + 0xfffffffeu), (uint16_t)(((uint16_t)c->ebx))); /* mov word ptr [ebp - 2], bx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(({ unsigned n_ = 11 & 31; uint32_t r_ = n_ ? ((c->eax << n_) | (c->ebx >> (32 - n_))) : c->eax; if (n_) { c->cf = (c->eax >> (32 - n_)) & 1; c->zf = r_ == 0; c->sf = (int32_t)r_ < 0; c->pf_byte = (uint8_t)r_; } r_; })); /* shld eax, ebx, 0xb */
    W32((uint32_t)(c->ebp + 0xfffffffau), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 6], eax */
    W32((uint32_t)(c->ebp + 0xfffffff6u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0xa], ebx */
    FPUSH(c, RF80((uint32_t)(c->ebp + 0xfffffff6u))); /* fld xword ptr [ebp - 0xa] */
    goto L_00cd5107; /* jmp 0xcd5107 */
L_00cd5104:;
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
L_00cd5107:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd5110(CPU *c) { /* __trandisp1 */
    PREEMPT_POLL(c);
    (void)sub8(c, R8((uint32_t)(c->edx + 0xeu)), (uint8_t)0x5u); /* cmp byte ptr [edx + 0xe], 5 */
    if (!c->zf) goto L_00cd5127; /* jne 0xcd5127 */
    c->ebx = (c->ebx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ebp + 0xffffff5cu))); /* mov bx, word ptr [ebp - 0xa4] */
    c->ebx = (c->ebx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ebx >> 8)) | (uint8_t)0x2u))) << 8); /* or bh, 2 */
    c->ebx = (c->ebx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ebx >> 8)) & (uint8_t)0xfeu))) << 8); /* and bh, 0xfe */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)((uint8_t)0x3fu); /* mov bl, 0x3f */
    goto L_00cd512b; /* jmp 0xcd512b */
L_00cd5127:;
    c->ebx = (c->ebx & 0xffff0000u) | (uint16_t)((uint16_t)0x133fu); /* mov bx, 0x133f */
L_00cd512b:;
    W16((uint32_t)(c->ebp + 0xffffff5eu), (uint16_t)(((uint16_t)c->ebx))); /* mov word ptr [ebp - 0xa2], bx */
    c->fpu_cw = R16((uint32_t)(c->ebp + 0xffffff5eu)); fpu_sync_rounding(c); /* fldcw word ptr [ebp - 0xa2] */
    c->ebx = (uint32_t)((uint32_t)0xcdd52cu); /* mov ebx, 0x1000d52c */
    { double v_ = ST(0); uint16_t sw_ = c->fpu_sw & ~0x4700; if (signbit(v_)) sw_ |= 0x0200; if (isnan(v_)) sw_ |= 0x0100; else if (isinf(v_)) sw_ |= 0x0500; else if (v_ == 0) sw_ |= 0x4000; else sw_ |= 0x0400; c->fpu_sw = sw_; } /* fxam  */
    W32((uint32_t)(c->ebp + 0xffffff6cu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x94], edx */
    ; /* wait  */
    W16((uint32_t)(c->ebp + 0xffffff60u), FNSTSW(c)); /* fnstsw word ptr [ebp - 0xa0] */
    W8((uint32_t)(c->ebp + 0xffffff70u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [ebp - 0x90], 0 */
    ; /* wait  */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0xffffff61u))); /* mov cl, byte ptr [ebp - 0x9f] */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(shl8(c, ((uint8_t)c->ecx), 1)); /* shl cl, 1 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(sar8(c, ((uint8_t)c->ecx), 1)); /* sar cl, 1 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(rol8(c, ((uint8_t)c->ecx), 1)); /* rol cl, 1 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(((uint8_t)c->ecx)); /* mov al, cl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfu))); /* and al, 0xf */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8(c->ebx + (uint8_t)c->eax)); /* xlatb  */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->eax)); /* movsx eax, al */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x404u))); /* and ecx, 0x404 */
    c->ebx = (uint32_t)(c->edx); /* mov ebx, edx */
    c->ebx = (uint32_t)(add32(c, c->ebx, c->eax)); /* add ebx, eax */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x10u)); /* add ebx, 0x10 */
    { uint32_t t_ = R32((uint32_t)(c->ebx)); switch (t_) {  default: jump_indirect(c, t_, 0x00cd5175u); return; } } /* jmp dword ptr [ebx] */
}

void f_00cd5177(CPU *c) { /* __trandisp2 */
    PREEMPT_POLL(c);
    (void)sub8(c, R8((uint32_t)(c->edx + 0xeu)), (uint8_t)0x5u); /* cmp byte ptr [edx + 0xe], 5 */
    if (!c->zf) goto L_00cd518e; /* jne 0xcd518e */
    c->ebx = (c->ebx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ebp + 0xffffff5cu))); /* mov bx, word ptr [ebp - 0xa4] */
    c->ebx = (c->ebx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ebx >> 8)) | (uint8_t)0x2u))) << 8); /* or bh, 2 */
    c->ebx = (c->ebx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ebx >> 8)) & (uint8_t)0xfeu))) << 8); /* and bh, 0xfe */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)((uint8_t)0x3fu); /* mov bl, 0x3f */
    goto L_00cd5192; /* jmp 0xcd5192 */
L_00cd518e:;
    c->ebx = (c->ebx & 0xffff0000u) | (uint16_t)((uint16_t)0x133fu); /* mov bx, 0x133f */
L_00cd5192:;
    W16((uint32_t)(c->ebp + 0xffffff5eu), (uint16_t)(((uint16_t)c->ebx))); /* mov word ptr [ebp - 0xa2], bx */
    c->fpu_cw = R16((uint32_t)(c->ebp + 0xffffff5eu)); fpu_sync_rounding(c); /* fldcw word ptr [ebp - 0xa2] */
    c->ebx = (uint32_t)((uint32_t)0xcdd52cu); /* mov ebx, 0x1000d52c */
    { double v_ = ST(0); uint16_t sw_ = c->fpu_sw & ~0x4700; if (signbit(v_)) sw_ |= 0x0200; if (isnan(v_)) sw_ |= 0x0100; else if (isinf(v_)) sw_ |= 0x0500; else if (v_ == 0) sw_ |= 0x4000; else sw_ |= 0x0400; c->fpu_sw = sw_; } /* fxam  */
    W32((uint32_t)(c->ebp + 0xffffff6cu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x94], edx */
    ; /* wait  */
    W16((uint32_t)(c->ebp + 0xffffff60u), FNSTSW(c)); /* fnstsw word ptr [ebp - 0xa0] */
    W8((uint32_t)(c->ebp + 0xffffff70u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [ebp - 0x90], 0 */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0xffffff61u))); /* mov cl, byte ptr [ebp - 0x9f] */
    { double v_ = ST(0); uint16_t sw_ = c->fpu_sw & ~0x4700; if (signbit(v_)) sw_ |= 0x0200; if (isnan(v_)) sw_ |= 0x0100; else if (isinf(v_)) sw_ |= 0x0500; else if (v_ == 0) sw_ |= 0x4000; else sw_ |= 0x0400; c->fpu_sw = sw_; } /* fxam  */
    ; /* wait  */
    W16((uint32_t)(c->ebp + 0xffffff60u), FNSTSW(c)); /* fnstsw word ptr [ebp - 0xa0] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->ebp + 0xffffff61u))) << 8); /* mov ch, byte ptr [ebp - 0x9f] */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(shl8(c, ((uint8_t)(c->ecx >> 8)), 1)) << 8); /* shl ch, 1 */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(sar8(c, ((uint8_t)(c->ecx >> 8)), 1)) << 8); /* sar ch, 1 */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(rol8(c, ((uint8_t)(c->ecx >> 8)), 1)) << 8); /* rol ch, 1 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(((uint8_t)(c->ecx >> 8))); /* mov al, ch */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfu))); /* and al, 0xf */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8(c->ebx + (uint8_t)c->eax)); /* xlatb  */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(((uint8_t)c->eax)) << 8); /* mov ah, al */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(shl8(c, ((uint8_t)c->ecx), 1)); /* shl cl, 1 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(sar8(c, ((uint8_t)c->ecx), 1)); /* sar cl, 1 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(rol8(c, ((uint8_t)c->ecx), 1)); /* rol cl, 1 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(((uint8_t)c->ecx)); /* mov al, cl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfu))); /* and al, 0xf */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8(c->ebx + (uint8_t)c->eax)); /* xlatb  */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(shl8(c, ((uint8_t)(c->eax >> 8)), 1)) << 8); /* shl ah, 1 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(shl8(c, ((uint8_t)(c->eax >> 8)), 1)) << 8); /* shl ah, 1 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)(c->eax >> 8))))); /* or al, ah */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->eax)); /* movsx eax, al */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x404u))); /* and ecx, 0x404 */
    c->ebx = (uint32_t)(c->edx); /* mov ebx, edx */
    c->ebx = (uint32_t)(add32(c, c->ebx, c->eax)); /* add ebx, eax */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x10u)); /* add ebx, 0x10 */
    { uint32_t t_ = R32((uint32_t)(c->ebx)); switch (t_) {  default: jump_indirect(c, t_, 0x00cd5201u); return; } } /* jmp dword ptr [ebx] */
}

void f_00cd5203(CPU *c) { /* PTR_00cd5203 */
    PREEMPT_POLL(c);
    PUSH32(c, 0x00cd5208u); f_00cd52c9(c); /* call 0xcd52c9 */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    c->esp += 4; return; /* ret  */
}

void f_00cd5214(CPU *c) { /* PTR_00cd5214 */
    PREEMPT_POLL(c);
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, 0.0); /* fldz  */
    c->esp += 4; return; /* ret  */
}

void f_00cd524d(CPU *c) { /* PTR_00cd524d */
    PREEMPT_POLL(c);
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    WF80((uint32_t)(c->ebp + 0xffffff62u), ST(0)); FPOP(c); /* fstp xword ptr [ebp - 0x9e] */
    FPUSH(c, RF80((uint32_t)(c->ebp + 0xffffff62u))); /* fld xword ptr [ebp - 0x9e] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xffffff69u)) & (uint8_t)0x40u)); /* test byte ptr [ebp - 0x97], 0x40 */
    if (c->zf) goto L_00cd526d; /* je 0xcd526d */
    W8((uint32_t)(c->ebp + 0xffffff70u), (uint8_t)((uint8_t)0x7u)); /* mov byte ptr [ebp - 0x90], 7 */
    goto L_00cd5274; /* jmp 0xcd5274 */
L_00cd526d:;
    W8((uint32_t)(c->ebp + 0xffffff70u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ebp - 0x90], 1 */
L_00cd5274:;
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    c->esp += 4; return; /* ret  */
}

void f_00cd524f(CPU *c) { /* PTR_00cd524f */
    PREEMPT_POLL(c);
    WF80((uint32_t)(c->ebp + 0xffffff62u), ST(0)); FPOP(c); /* fstp xword ptr [ebp - 0x9e] */
    FPUSH(c, RF80((uint32_t)(c->ebp + 0xffffff62u))); /* fld xword ptr [ebp - 0x9e] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xffffff69u)) & (uint8_t)0x40u)); /* test byte ptr [ebp - 0x97], 0x40 */
    if (c->zf) goto L_00cd526d; /* je 0xcd526d */
    W8((uint32_t)(c->ebp + 0xffffff70u), (uint8_t)((uint8_t)0x7u)); /* mov byte ptr [ebp - 0x90], 7 */
    goto L_00cd5274; /* jmp 0xcd5274 */
L_00cd526d:;
    W8((uint32_t)(c->ebp + 0xffffff70u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ebp - 0x90], 1 */
L_00cd5274:;
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    c->esp += 4; return; /* ret  */
}

void f_00cd5277(CPU *c) { /* PTR_00cd5277 */
    PREEMPT_POLL(c);
    WF80((uint32_t)(c->ebp + 0xffffff62u), ST(0)); FPOP(c); /* fstp xword ptr [ebp - 0x9e] */
    FPUSH(c, RF80((uint32_t)(c->ebp + 0xffffff62u))); /* fld xword ptr [ebp - 0x9e] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xffffff69u)) & (uint8_t)0x40u)); /* test byte ptr [ebp - 0x97], 0x40 */
    if (c->zf) goto L_00cd52ac; /* je 0xcd52ac */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    WF80((uint32_t)(c->ebp + 0xffffff62u), ST(0)); FPOP(c); /* fstp xword ptr [ebp - 0x9e] */
    FPUSH(c, RF80((uint32_t)(c->ebp + 0xffffff62u))); /* fld xword ptr [ebp - 0x9e] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xffffff69u)) & (uint8_t)0x40u)); /* test byte ptr [ebp - 0x97], 0x40 */
    if (c->zf) goto L_00cd52ac; /* je 0xcd52ac */
    W8((uint32_t)(c->ebp + 0xffffff70u), (uint8_t)((uint8_t)0x7u)); /* mov byte ptr [ebp - 0x90], 7 */
    goto L_00cd52b3; /* jmp 0xcd52b3 */
L_00cd52ac:;
    W8((uint32_t)(c->ebp + 0xffffff70u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ebp - 0x90], 1 */
L_00cd52b3:;
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    c->esp += 4; return; /* ret  */
}

void f_00cd52b6(CPU *c) { /* PTR_00cd52b6 */
    PREEMPT_POLL(c);
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, RF80((uint32_t)(0xcdd510u))); /* fld xword ptr [0x1000d510] */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xffffff70u)), (uint8_t)0x0u); /* cmp byte ptr [ebp - 0x90], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_00cd52d0; /* jg 0xcd52d0 */
    W8((uint32_t)(c->ebp + 0xffffff70u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ebp - 0x90], 1 */
L_00cd52d0:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->ecx) | ((uint8_t)c->ecx)))); /* or cl, cl */
    c->esp += 4; return; /* ret  */
}

void f_00cd52c9(CPU *c) { /* PTR_00cd52c9 */
    PREEMPT_POLL(c);
    W8((uint32_t)(c->ebp + 0xffffff70u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ebp - 0x90], 1 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->ecx) | ((uint8_t)c->ecx)))); /* or cl, cl */
    c->esp += 4; return; /* ret  */
}

void f_00cd52e0(CPU *c) { /* PTR_00cd52e0 */
    PREEMPT_POLL(c);
    FPUSH(c, RF80((uint32_t)(c->esp + 0x10u))); /* fld xword ptr [esp + 0x10] */
    FPUSH(c, RF80((uint32_t)(c->esp + 0x4u))); /* fld xword ptr [esp + 4] */
L_00cd52e8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->eax = (uint32_t)(add32(c, c->eax, c->eax)); /* add eax, eax */
    if (!c->cf) goto L_00cd537a; /* jae 0xcd537a */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ (uint32_t)0xe000000u))); /* xor eax, 0xe000000 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0xe000000u)); /* test eax, 0xe000000 */
    if (c->zf) goto L_00cd5303; /* je 0xcd5303 */
    ST(1) = FPRES(c, FDIV(c, ST(1), ST(0))); FPOP(c); /* fdivp st(1) */
    c->esp += 4; return; /* ret  */
L_00cd5303:;
    c->eax = (uint32_t)(shr32(c, c->eax, 28)); /* shr eax, 0x1c */
    (void)sub8(c, R8((uint32_t)(c->eax + 0xcdd540u)), (uint8_t)0x0u); /* cmp byte ptr [eax + 0x1000d540], 0 */
    if (!c->zf) goto L_00cd5312; /* jne 0xcd5312 */
    ST(1) = FPRES(c, FDIV(c, ST(1), ST(0))); FPOP(c); /* fdivp st(1) */
    c->esp += 4; return; /* ret  */
L_00cd5312:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fffu))); /* and eax, 0x7fff */
    if (c->zf) goto L_00cd5384; /* je 0xcd5384 */
    (void)sub32(c, c->eax, (uint32_t)0x7fffu); /* cmp eax, 0x7fff */
    if (c->zf) goto L_00cd5384; /* je 0xcd5384 */
    W16((uint32_t)(c->esp + 0x1cu), c->fpu_cw); /* fnstcw word ptr [esp + 0x1c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov eax, dword ptr [esp + 0x1c] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0x33fu))); /* or eax, 0x33f */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xf3ffu))); /* and eax, 0xf3ff */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x20], eax */
    c->fpu_cw = R16((uint32_t)(c->esp + 0x20u)); fpu_sync_rounding(c); /* fldcw word ptr [esp + 0x20] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fffu))); /* and eax, 0x7fff */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_00cd5363; /* je 0xcd5363 */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xcdd550u))); /* fmul dword ptr [0x1000d550] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xcdd550u))); /* fmul dword ptr [0x1000d550] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    c->fpu_cw = R16((uint32_t)(c->esp + 0x1cu)); fpu_sync_rounding(c); /* fldcw word ptr [esp + 0x1c] */
    ST(1) = FPRES(c, FDIV(c, ST(1), ST(0))); FPOP(c); /* fdivp st(1) */
    c->esp += 4; return; /* ret  */
L_00cd5363:;
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xcdd554u))); /* fmul dword ptr [0x1000d554] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xcdd554u))); /* fmul dword ptr [0x1000d554] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    c->fpu_cw = R16((uint32_t)(c->esp + 0x1cu)); fpu_sync_rounding(c); /* fldcw word ptr [esp + 0x1c] */
    ST(1) = FPRES(c, FDIV(c, ST(1), ST(0))); FPOP(c); /* fdivp st(1) */
    c->esp += 4; return; /* ret  */
L_00cd537a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | R32((uint32_t)(c->esp + 0x8u))))); /* or eax, dword ptr [esp + 8] */
    if (!c->zf) goto L_00cd5387; /* jne 0xcd5387 */
L_00cd5384:;
    ST(1) = FPRES(c, FDIV(c, ST(1), ST(0))); FPOP(c); /* fdivp st(1) */
    c->esp += 4; return; /* ret  */
L_00cd5387:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fffu))); /* and eax, 0x7fff */
    if (!c->zf) goto L_00cd5384; /* jne 0xcd5384 */
    W16((uint32_t)(c->esp + 0x1cu), c->fpu_cw); /* fnstcw word ptr [esp + 0x1c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov eax, dword ptr [esp + 0x1c] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0x33fu))); /* or eax, 0x33f */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xf3ffu))); /* and eax, 0xf3ff */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x20], eax */
    c->fpu_cw = R16((uint32_t)(c->esp + 0x20u)); fpu_sync_rounding(c); /* fldcw word ptr [esp + 0x20] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fffu))); /* and eax, 0x7fff */
    if (c->zf) goto L_00cd53c8; /* je 0xcd53c8 */
    (void)sub32(c, c->eax, (uint32_t)0x7fffu); /* cmp eax, 0x7fff */
    if (c->zf) goto L_00cd53f0; /* je 0xcd53f0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->eax = (uint32_t)(add32(c, c->eax, c->eax)); /* add eax, eax */
    if (!c->cf) goto L_00cd53f0; /* jae 0xcd53f0 */
    goto L_00cd53d0; /* jmp 0xcd53d0 */
L_00cd53c8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->eax = (uint32_t)(add32(c, c->eax, c->eax)); /* add eax, eax */
    if (c->cf) goto L_00cd53f0; /* jb 0xcd53f0 */
L_00cd53d0:;
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xcdd558u))); /* fmul dword ptr [0x1000d558] */
    WF80((uint32_t)(c->esp + 0x4u), ST(0)); FPOP(c); /* fstp xword ptr [esp + 4] */
    FPUSH(c, RF80((uint32_t)(c->esp + 0x10u))); /* fld xword ptr [esp + 0x10] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ; /* wait  */
    c->fpu_cw = R16((uint32_t)(c->esp + 0x1cu)); fpu_sync_rounding(c); /* fldcw word ptr [esp + 0x1c] */
    goto L_00cd52e8; /* jmp 0xcd52e8 */
L_00cd53f0:;
    c->fpu_cw = R16((uint32_t)(c->esp + 0x1cu)); fpu_sync_rounding(c); /* fldcw word ptr [esp + 0x1c] */
    ST(1) = FPRES(c, FDIV(c, ST(1), ST(0))); FPOP(c); /* fdivp st(1) */
    c->esp += 4; return; /* ret  */
}

void f_00cd56b0(CPU *c) { /* PTR_00cd56b0 */
    PREEMPT_POLL(c);
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    WF80((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp xword ptr [esp] */
    WF80((uint32_t)(c->esp + 0x20u), ST(0)); FPOP(c); /* fstp xword ptr [esp + 0x20] */
    PUSH32(c, 0x00cd56beu); f_00cd52e0(c); /* call 0xcd52e0 */
    { double t_ = ST(0); ST(0) = ST(4); ST(4) = t_; } /* fxch st(4) */
    FPUSH(c, RF80((uint32_t)(c->esp + 0x20u))); /* fld xword ptr [esp + 0x20] */
    { double t_ = ST(0); ST(0) = ST(5); ST(5) = t_; } /* fxch st(5) */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
    c->esp += 4; return; /* ret  */
}

void f_00cd56c0(CPU *c) { /* PTR_00cd56c0 */
    PREEMPT_POLL(c);
    FPUSH(c, RF80((uint32_t)(c->esp + 0x20u))); /* fld xword ptr [esp + 0x20] */
    { double t_ = ST(0); ST(0) = ST(5); ST(5) = t_; } /* fxch st(5) */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
    c->esp += 4; return; /* ret  */
}

void f_00cd5740(CPU *c) { /* PTR_00cd5740 */
    PREEMPT_POLL(c);
    WF80((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp xword ptr [esp] */
    PUSH32(c, 0x00cd5748u); f_00cd52e0(c); /* call 0xcd52e0 */
    { double t_ = ST(0); ST(0) = ST(4); ST(4) = t_; } /* fxch st(4) */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
    c->esp += 4; return; /* ret  */
}

void f_00cd5ae6(CPU *c) { /* FUN_10005ae6 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x16u))); /* mov eax, dword ptr [esp + 0x16] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ (uint32_t)0x700u))); /* xor eax, 0x700 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x700u)); /* test eax, 0x700 */
    if (!c->zf) goto L_00cd5c80; /* jne 0xcd5c80 */
    c->eax = (uint32_t)(shr32(c, c->eax, 11)); /* shr eax, 0xb */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xfu))); /* and eax, 0xf */
    (void)sub8(c, R8((uint32_t)(c->eax + 0xcdd55cu)), (uint8_t)0x0u); /* cmp byte ptr [eax + 0x1000d55c], 0 */
    if (c->zf) goto L_00cd5c80; /* je 0xcd5c80 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x16u))); /* mov eax, dword ptr [esp + 0x16] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fff0000u))); /* and eax, 0x7fff0000 */
    (void)sub32(c, c->eax, (uint32_t)0x7fff0000u); /* cmp eax, 0x7fff0000 */
    if (c->zf) goto L_00cd5c80; /* je 0xcd5c80 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x2eu))); /* mov eax, dword ptr [esp + 0x2e] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fff0000u))); /* and eax, 0x7fff0000 */
    if (c->zf) goto L_00cd5c80; /* je 0xcd5c80 */
    (void)sub32(c, c->eax, (uint32_t)0x7fff0000u); /* cmp eax, 0x7fff0000 */
    if (c->zf) goto L_00cd5c80; /* je 0xcd5c80 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov eax, dword ptr [esp + 0x2c] */
    c->eax = (uint32_t)(add32(c, c->eax, c->eax)); /* add eax, eax */
    if (!c->zf) goto L_00cd5c80; /* jne 0xcd5c80 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->eax = (uint32_t)(add32(c, c->eax, c->eax)); /* add eax, eax */
    if (!c->zf) goto L_00cd5c80; /* jne 0xcd5c80 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fffu))); /* and eax, 0x7fff */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x3fu)); /* add eax, 0x3f */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov ebx, dword ptr [esp + 0x30] */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x7fffu))); /* and ebx, 0x7fff */
    c->ebx = (uint32_t)(sub32(c, c->ebx, c->eax)); /* sub ebx, eax */
    if ((!c->cf && !c->zf)) goto L_00cd5bce; /* ja 0xcd5bce */
L_00cd5b70:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fffu))); /* and eax, 0x7fff */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xau)); /* add eax, 0xa */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov ebx, dword ptr [esp + 0x30] */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x7fffu))); /* and ebx, 0x7fff */
    c->ebx = (uint32_t)(sub32(c, c->ebx, c->eax)); /* sub ebx, eax */
    if (c->sf) goto L_00cd5c80; /* js 0xcd5c80 */
    FPUSH(c, RF80((uint32_t)(c->esp + 0x28u))); /* fld xword ptr [esp + 0x28] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov ebx, dword ptr [esp + 0x30] */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x7fffu))); /* and ebx, 0x7fff */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    c->ebx = (uint32_t)(sub32(c, c->ebx, c->eax)); /* sub ebx, eax */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x7u))); /* and ebx, 7 */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | (uint32_t)0x4u))); /* or ebx, 4 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->ebx)); /* sub ecx, ebx */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x8000u))); /* and ebx, 0x8000 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->ebx))); /* or ecx, ebx */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x18], ecx */
    FPUSH(c, RF80((uint32_t)(c->esp + 0x10u))); /* fld xword ptr [esp + 0x10] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x18], eax */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = fmod(ST(0), ST(1)); c->fpu_sw &= ~0x0400; /* fprem  */
    WF80((uint32_t)(c->esp + 0x28u), ST(0)); FPOP(c); /* fstp xword ptr [esp + 0x28] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    goto L_00cd5b70; /* jmp 0xcd5b70 */
L_00cd5bce:;
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x2u)); /* test edx, 2 */
    if (!c->zf) goto L_00cd5bde; /* jne 0xcd5bde */
    FPUSH(c, RF80((uint32_t)(c->esp + 0x10u))); /* fld xword ptr [esp + 0x10] */
    WF80((uint32_t)(c->esp + 0x1cu), ST(0)); FPOP(c); /* fstp xword ptr [esp + 0x1c] */
L_00cd5bde:;
    W16((uint32_t)(c->esp + 0x34u), c->fpu_cw); /* fnstcw word ptr [esp + 0x34] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov eax, dword ptr [esp + 0x34] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0x33fu))); /* or eax, 0x33f */
    W32((uint32_t)(c->esp + 0x38u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x38], eax */
    c->fpu_cw = R16((uint32_t)(c->esp + 0x38u)); fpu_sync_rounding(c); /* fldcw word ptr [esp + 0x38] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fffu))); /* and eax, 0x7fff */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov ebx, dword ptr [esp + 0x30] */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x7fffu))); /* and ebx, 0x7fff */
    c->ebx = (uint32_t)(sub32(c, c->ebx, c->eax)); /* sub ebx, eax */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x3fu))); /* and ebx, 0x3f */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | (uint32_t)0x20u))); /* or ebx, 0x20 */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x1u)); /* add ebx, 1 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov ebx, dword ptr [esp + 0x30] */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x7fffu))); /* and ebx, 0x7fff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x8000u))); /* and eax, 0x8000 */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | c->eax))); /* or ebx, eax */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x18], ebx */
    FPUSH(c, RF80((uint32_t)(c->esp + 0x10u))); /* fld xword ptr [esp + 0x10] */
    ST(0) = fabs(ST(0)); /* fabs  */
    FPUSH(c, RF80((uint32_t)(c->esp + 0x28u))); /* fld xword ptr [esp + 0x28] */
    ST(0) = fabs(ST(0)); /* fabs  */
L_00cd5c38:;
    FCOM(c, ST(0), ST(1)); /* fcom st(1) */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x100u))); /* and eax, 0x100 */
    if (!c->zf) goto L_00cd5c45; /* jne 0xcd5c45 */
    ST(0) = FPRES(c, ST(0) - ST(1)); /* fsub st(1) */
L_00cd5c45:;
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(0xcdd58cu))); /* fmul qword ptr [0x1000d58c] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x1u)); /* sub ecx, 1 */
    if (!c->zf) goto L_00cd5c38; /* jne 0xcd5c38 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov ebx, dword ptr [esp + 0x30] */
    WF80((uint32_t)(c->esp + 0x28u), ST(0)); FPOP(c); /* fstp xword ptr [esp + 0x28] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, RF80((uint32_t)(c->esp + 0x1cu))); /* fld xword ptr [esp + 0x1c] */
    FPUSH(c, RF80((uint32_t)(0xcdd594u))); /* fld xword ptr [0x1000d594] */
    ST(0) = fmod(ST(0), ST(1)); c->fpu_sw &= ~0x0400; /* fprem  */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, RF80((uint32_t)(c->esp + 0x28u))); /* fld xword ptr [esp + 0x28] */
    c->fpu_cw = R16((uint32_t)(c->esp + 0x34u)); fpu_sync_rounding(c); /* fldcw word ptr [esp + 0x34] */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x8000u))); /* and ebx, 0x8000 */
    if (c->zf) goto L_00cd5c8a; /* je 0xcd5c8a */
    ST(0) = -ST(0); /* fchs  */
    goto L_00cd5c8a; /* jmp 0xcd5c8a */
L_00cd5c80:;
    FPUSH(c, RF80((uint32_t)(c->esp + 0x10u))); /* fld xword ptr [esp + 0x10] */
    FPUSH(c, RF80((uint32_t)(c->esp + 0x28u))); /* fld xword ptr [esp + 0x28] */
    ST(0) = fmod(ST(0), ST(1)); c->fpu_sw &= ~0x0400; /* fprem  */
L_00cd5c8a:;
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u)); /* test edx, 3 */
    if (c->zf) goto L_00cd5ce8; /* je 0xcd5ce8 */
    W16((uint32_t)(c->esp + 0x3cu), FNSTSW(c)); /* fnstsw word ptr [esp + 0x3c] */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x1u)); /* test edx, 1 */
    if (c->zf) goto L_00cd5cbd; /* je 0xcd5cbd */
    W16((uint32_t)(c->esp + 0x34u), c->fpu_cw); /* fnstcw word ptr [esp + 0x34] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov eax, dword ptr [esp + 0x34] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0x300u))); /* or eax, 0x300 */
    W32((uint32_t)(c->esp + 0x38u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x38], eax */
    c->fpu_cw = R16((uint32_t)(c->esp + 0x38u)); fpu_sync_rounding(c); /* fldcw word ptr [esp + 0x38] */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(0xcdd57cu))); /* fmul qword ptr [0x1000d57c] */
    c->fpu_cw = R16((uint32_t)(c->esp + 0x34u)); fpu_sync_rounding(c); /* fldcw word ptr [esp + 0x34] */
L_00cd5cbd:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x3cu))); /* mov eax, dword ptr [esp + 0x3c] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, RF80((uint32_t)(c->esp + 0x1cu))); /* fld xword ptr [esp + 0x1c] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4300u))); /* and eax, 0x4300 */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x1cu)); /* sub esp, 0x1c */
    guest_trap(c, 0x00cd5cd3u, "unsupported: fnstenv [esp]"); /* fnstenv [esp] */
    { uint32_t a_ = (uint32_t)(c->esp + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0xbcffu)))); } /* and dword ptr [esp + 4], 0xbcff */
    { uint32_t a_ = (uint32_t)(c->esp + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->eax)))); } /* or dword ptr [esp + 4], eax */
    guest_trap(c, 0x00cd5ce2u, "unsupported: fldenv [esp]"); /* fldenv [esp] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
L_00cd5ce8:;
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_00cd5cec(CPU *c) { /* FUN_10005cec */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x30u)); /* sub esp, 0x30 */
    WF80((uint32_t)(c->esp + 0x18u), ST(0)); FPOP(c); /* fstp xword ptr [esp + 0x18] */
    WF80((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp xword ptr [esp] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x6u))); /* mov eax, dword ptr [esp + 6] */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fff0000u)); /* test eax, 0x7fff0000 */
    if (c->zf) goto L_00cd5d0e; /* je 0xcd5d0e */
    PUSH32(c, 0x00cd5d09u); f_00cd5ae6(c); /* call 0xcd5ae6 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x30u)); /* add esp, 0x30 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->esp += 4; return; /* ret  */
L_00cd5d0e:;
    FPUSH(c, RF80((uint32_t)(c->esp))); /* fld xword ptr [esp] */
    FPUSH(c, RF80((uint32_t)(c->esp + 0x18u))); /* fld xword ptr [esp + 0x18] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp))); /* mov eax, dword ptr [esp] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | R32((uint32_t)(c->esp + 0x4u))))); /* or eax, dword ptr [esp + 4] */
    if (c->zf) goto L_00cd5d97; /* je 0xcd5d97 */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    WF80((uint32_t)(c->esp + 0xcu), ST(0)); FPOP(c); /* fstp xword ptr [esp + 0xc] */
    FPUSH(c, RF80((uint32_t)(c->esp))); /* fld xword ptr [esp] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx | (uint32_t)0x2u))); /* or edx, 2 */
    W16((uint32_t)(c->esp + 0x24u), c->fpu_cw); /* fnstcw word ptr [esp + 0x24] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov eax, dword ptr [esp + 0x24] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0x33fu))); /* or eax, 0x33f */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x28], eax */
    c->fpu_cw = R16((uint32_t)(c->esp + 0x28u)); fpu_sync_rounding(c); /* fldcw word ptr [esp + 0x28] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov eax, dword ptr [esp + 0x20] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fffu))); /* and eax, 0x7fff */
    (void)sub32(c, c->eax, (uint32_t)0x7fbeu); /* cmp eax, 0x7fbe */
    if ((!c->cf && !c->zf)) goto L_00cd5d69; /* ja 0xcd5d69 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx | (uint32_t)0x1u))); /* or edx, 1 */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(0xcdd574u))); /* fmul qword ptr [0x1000d574] */
    WF80((uint32_t)(c->esp + 0x18u), ST(0)); FPOP(c); /* fstp xword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(0xcdd574u))); /* fmul qword ptr [0x1000d574] */
    WF80((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp xword ptr [esp] */
    goto L_00cd5d89; /* jmp 0xcd5d89 */
L_00cd5d69:;
    W16((uint32_t)(c->esp + 0x24u), c->fpu_cw); /* fnstcw word ptr [esp + 0x24] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov eax, dword ptr [esp + 0x24] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0x300u))); /* or eax, 0x300 */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x28], eax */
    c->fpu_cw = R16((uint32_t)(c->esp + 0x28u)); fpu_sync_rounding(c); /* fldcw word ptr [esp + 0x28] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(0xcdd574u))); /* fmul qword ptr [0x1000d574] */
    WF80((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp xword ptr [esp] */
L_00cd5d89:;
    c->fpu_cw = R16((uint32_t)(c->esp + 0x24u)); fpu_sync_rounding(c); /* fldcw word ptr [esp + 0x24] */
    PUSH32(c, 0x00cd5d92u); f_00cd5ae6(c); /* call 0xcd5ae6 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x30u)); /* add esp, 0x30 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->esp += 4; return; /* ret  */
L_00cd5d97:;
    ST(0) = fmod(ST(0), ST(1)); c->fpu_sw &= ~0x0400; /* fprem  */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x30u)); /* add esp, 0x30 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->esp += 4; return; /* ret  */
}

void f_00cd5d9e(CPU *c) { /* PTR_00cd5d9e */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x16u))); /* mov eax, dword ptr [esp + 0x16] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ (uint32_t)0x700u))); /* xor eax, 0x700 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x700u)); /* test eax, 0x700 */
    if (!c->zf) goto L_00cd5f38; /* jne 0xcd5f38 */
    c->eax = (uint32_t)(shr32(c, c->eax, 11)); /* shr eax, 0xb */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xfu))); /* and eax, 0xf */
    (void)sub8(c, R8((uint32_t)(c->eax + 0xcdd55cu)), (uint8_t)0x0u); /* cmp byte ptr [eax + 0x1000d55c], 0 */
    if (c->zf) goto L_00cd5f38; /* je 0xcd5f38 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x16u))); /* mov eax, dword ptr [esp + 0x16] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fff0000u))); /* and eax, 0x7fff0000 */
    (void)sub32(c, c->eax, (uint32_t)0x7fff0000u); /* cmp eax, 0x7fff0000 */
    if (c->zf) goto L_00cd5f38; /* je 0xcd5f38 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x2eu))); /* mov eax, dword ptr [esp + 0x2e] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fff0000u))); /* and eax, 0x7fff0000 */
    if (c->zf) goto L_00cd5f38; /* je 0xcd5f38 */
    (void)sub32(c, c->eax, (uint32_t)0x7fff0000u); /* cmp eax, 0x7fff0000 */
    if (c->zf) goto L_00cd5f38; /* je 0xcd5f38 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov eax, dword ptr [esp + 0x2c] */
    c->eax = (uint32_t)(add32(c, c->eax, c->eax)); /* add eax, eax */
    if (!c->zf) goto L_00cd5f38; /* jne 0xcd5f38 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->eax = (uint32_t)(add32(c, c->eax, c->eax)); /* add eax, eax */
    if (!c->zf) goto L_00cd5f38; /* jne 0xcd5f38 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fffu))); /* and eax, 0x7fff */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x3fu)); /* add eax, 0x3f */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov ebx, dword ptr [esp + 0x30] */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x7fffu))); /* and ebx, 0x7fff */
    c->ebx = (uint32_t)(sub32(c, c->ebx, c->eax)); /* sub ebx, eax */
    if ((!c->cf && !c->zf)) goto L_00cd5e86; /* ja 0xcd5e86 */
L_00cd5e28:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fffu))); /* and eax, 0x7fff */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xau)); /* add eax, 0xa */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov ebx, dword ptr [esp + 0x30] */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x7fffu))); /* and ebx, 0x7fff */
    c->ebx = (uint32_t)(sub32(c, c->ebx, c->eax)); /* sub ebx, eax */
    if (c->sf) goto L_00cd5f38; /* js 0xcd5f38 */
    FPUSH(c, RF80((uint32_t)(c->esp + 0x28u))); /* fld xword ptr [esp + 0x28] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov ebx, dword ptr [esp + 0x30] */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x7fffu))); /* and ebx, 0x7fff */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    c->ebx = (uint32_t)(sub32(c, c->ebx, c->eax)); /* sub ebx, eax */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x7u))); /* and ebx, 7 */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | (uint32_t)0x4u))); /* or ebx, 4 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->ebx)); /* sub ecx, ebx */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x8000u))); /* and ebx, 0x8000 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->ebx))); /* or ecx, ebx */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x18], ecx */
    FPUSH(c, RF80((uint32_t)(c->esp + 0x10u))); /* fld xword ptr [esp + 0x10] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x18], eax */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = fmod(ST(0), ST(1)); c->fpu_sw &= ~0x0400; /* fprem  */
    WF80((uint32_t)(c->esp + 0x28u), ST(0)); FPOP(c); /* fstp xword ptr [esp + 0x28] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    goto L_00cd5e28; /* jmp 0xcd5e28 */
L_00cd5e86:;
    (void)logic32(c, (uint32_t)(c->ebx & (uint32_t)0x2u)); /* test ebx, 2 */
    if (!c->zf) goto L_00cd5e96; /* jne 0xcd5e96 */
    FPUSH(c, RF80((uint32_t)(c->esp + 0x10u))); /* fld xword ptr [esp + 0x10] */
    WF80((uint32_t)(c->esp + 0x1cu), ST(0)); FPOP(c); /* fstp xword ptr [esp + 0x1c] */
L_00cd5e96:;
    W16((uint32_t)(c->esp + 0x34u), c->fpu_cw); /* fnstcw word ptr [esp + 0x34] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov eax, dword ptr [esp + 0x34] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0x33fu))); /* or eax, 0x33f */
    W32((uint32_t)(c->esp + 0x38u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x38], eax */
    c->fpu_cw = R16((uint32_t)(c->esp + 0x38u)); fpu_sync_rounding(c); /* fldcw word ptr [esp + 0x38] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fffu))); /* and eax, 0x7fff */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov ebx, dword ptr [esp + 0x30] */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x7fffu))); /* and ebx, 0x7fff */
    c->ebx = (uint32_t)(sub32(c, c->ebx, c->eax)); /* sub ebx, eax */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x3fu))); /* and ebx, 0x3f */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | (uint32_t)0x20u))); /* or ebx, 0x20 */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x1u)); /* add ebx, 1 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov ebx, dword ptr [esp + 0x30] */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x7fffu))); /* and ebx, 0x7fff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x8000u))); /* and eax, 0x8000 */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | c->eax))); /* or ebx, eax */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x18], ebx */
    FPUSH(c, RF80((uint32_t)(c->esp + 0x10u))); /* fld xword ptr [esp + 0x10] */
    ST(0) = fabs(ST(0)); /* fabs  */
    FPUSH(c, RF80((uint32_t)(c->esp + 0x28u))); /* fld xword ptr [esp + 0x28] */
    ST(0) = fabs(ST(0)); /* fabs  */
L_00cd5ef0:;
    FCOM(c, ST(0), ST(1)); /* fcom st(1) */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x100u))); /* and eax, 0x100 */
    if (!c->zf) goto L_00cd5efd; /* jne 0xcd5efd */
    ST(0) = FPRES(c, ST(0) - ST(1)); /* fsub st(1) */
L_00cd5efd:;
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(0xcdd58cu))); /* fmul qword ptr [0x1000d58c] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x1u)); /* sub ecx, 1 */
    if (!c->zf) goto L_00cd5ef0; /* jne 0xcd5ef0 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov ebx, dword ptr [esp + 0x30] */
    WF80((uint32_t)(c->esp + 0x28u), ST(0)); FPOP(c); /* fstp xword ptr [esp + 0x28] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, RF80((uint32_t)(c->esp + 0x1cu))); /* fld xword ptr [esp + 0x1c] */
    FPUSH(c, RF80((uint32_t)(0xcdd594u))); /* fld xword ptr [0x1000d594] */
    ST(0) = remainder(ST(0), ST(1)); c->fpu_sw &= ~0x0400; /* fprem1  */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, RF80((uint32_t)(c->esp + 0x28u))); /* fld xword ptr [esp + 0x28] */
    c->fpu_cw = R16((uint32_t)(c->esp + 0x34u)); fpu_sync_rounding(c); /* fldcw word ptr [esp + 0x34] */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x8000u))); /* and ebx, 0x8000 */
    if (c->zf) goto L_00cd5f42; /* je 0xcd5f42 */
    ST(0) = -ST(0); /* fchs  */
    goto L_00cd5f42; /* jmp 0xcd5f42 */
L_00cd5f38:;
    FPUSH(c, RF80((uint32_t)(c->esp + 0x10u))); /* fld xword ptr [esp + 0x10] */
    FPUSH(c, RF80((uint32_t)(c->esp + 0x28u))); /* fld xword ptr [esp + 0x28] */
    ST(0) = remainder(ST(0), ST(1)); c->fpu_sw &= ~0x0400; /* fprem1  */
L_00cd5f42:;
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u)); /* test edx, 3 */
    if (c->zf) goto L_00cd5fa0; /* je 0xcd5fa0 */
    W16((uint32_t)(c->esp + 0x3cu), FNSTSW(c)); /* fnstsw word ptr [esp + 0x3c] */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x1u)); /* test edx, 1 */
    if (c->zf) goto L_00cd5f75; /* je 0xcd5f75 */
    W16((uint32_t)(c->esp + 0x34u), c->fpu_cw); /* fnstcw word ptr [esp + 0x34] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov eax, dword ptr [esp + 0x34] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0x300u))); /* or eax, 0x300 */
    W32((uint32_t)(c->esp + 0x38u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x38], eax */
    c->fpu_cw = R16((uint32_t)(c->esp + 0x38u)); fpu_sync_rounding(c); /* fldcw word ptr [esp + 0x38] */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(0xcdd57cu))); /* fmul qword ptr [0x1000d57c] */
    c->fpu_cw = R16((uint32_t)(c->esp + 0x34u)); fpu_sync_rounding(c); /* fldcw word ptr [esp + 0x34] */
L_00cd5f75:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x3cu))); /* mov eax, dword ptr [esp + 0x3c] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, RF80((uint32_t)(c->esp + 0x1cu))); /* fld xword ptr [esp + 0x1c] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4300u))); /* and eax, 0x4300 */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x1cu)); /* sub esp, 0x1c */
    guest_trap(c, 0x00cd5f8bu, "unsupported: fnstenv [esp]"); /* fnstenv [esp] */
    { uint32_t a_ = (uint32_t)(c->esp + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0xbcffu)))); } /* and dword ptr [esp + 4], 0xbcff */
    { uint32_t a_ = (uint32_t)(c->esp + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->eax)))); } /* or dword ptr [esp + 4], eax */
    guest_trap(c, 0x00cd5f9au, "unsupported: fldenv [esp]"); /* fldenv [esp] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
L_00cd5fa0:;
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_00cd606b(CPU *c) { /* FUN_1000606b */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x48u)); /* sub esp, 0x48 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x480u; PUSH32(c, v_); } /* push 0x480 */
    PUSH32(c, 0x00cd607eu); f_00cd4c86(c); /* call 0xcd4c86 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_00cd608d; /* jne 0xcd608d */
    { uint32_t v_ = 0x1bu; PUSH32(c, v_); } /* push 0x1b */
    PUSH32(c, 0x00cd608cu); f_00cd33c8(c); /* call 0xcd33c8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00cd608d:;
    W32((uint32_t)(0xce0a60u), (uint32_t)(c->esi)); /* mov dword ptr [0x10010a60], esi */
    W32((uint32_t)(0xce0b60u), (uint32_t)((uint32_t)0x20u)); /* mov dword ptr [0x10010b60], 0x20 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x480u)); /* lea eax, [esi + 0x480] */
L_00cd60a3:;
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if (!c->cf) goto L_00cd60c5; /* jae 0xcd60c5 */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [esi + 4], 0 */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [esi], 0xffffffff */
    { uint32_t a_ = (uint32_t)(c->esi + 0x8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi + 8], 0 */
    W8((uint32_t)(c->esi + 0x5u), (uint8_t)((uint8_t)0xau)); /* mov byte ptr [esi + 5], 0xa */
    c->eax = (uint32_t)(R32((uint32_t)(0xce0a60u))); /* mov eax, dword ptr [0x10010a60] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x24u)); /* add esi, 0x24 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x480u)); /* add eax, 0x480 */
    goto L_00cd60a3; /* jmp 0xcd60a3 */
L_00cd60c5:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffb8u)); /* lea eax, [ebp - 0x48] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0xcdc070u)); PUSH32(c, 0x00cd60cfu); call_indirect(c, t_); } /* call dword ptr [0x1000c070] */
    (void)sub16(c, R16((uint32_t)(c->ebp + 0xffffffeau)), (uint16_t)0x0u); /* cmp word ptr [ebp - 0x16], 0 */
    if (c->zf) goto L_00cd61ab; /* je 0xcd61ab */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd61ab; /* je 0xcd61ab */
    c->edi = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edi, dword ptr [eax] */
    c->ebx = (uint32_t)((uint32_t)(c->eax + 0x4u)); /* lea ebx, [eax + 4] */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->edi)); /* lea eax, [ebx + edi] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->eax = (uint32_t)((uint32_t)0x800u); /* mov eax, 0x800 */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if ((c->sf != c->of)) goto L_00cd60fb; /* jl 0xcd60fb */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
L_00cd60fb:;
    (void)sub32(c, R32((uint32_t)(0xce0b60u)), c->edi); /* cmp dword ptr [0x10010b60], edi */
    if ((c->sf == c->of)) goto L_00cd6159; /* jge 0xcd6159 */
    c->esi = (uint32_t)((uint32_t)0xce0a64u); /* mov esi, 0x10010a64 */
L_00cd6108:;
    { uint32_t v_ = 0x480u; PUSH32(c, v_); } /* push 0x480 */
    PUSH32(c, 0x00cd6112u); f_00cd4c86(c); /* call 0xcd4c86 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00cd6153; /* je 0xcd6153 */
    { uint32_t a_ = (uint32_t)(0xce0b60u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x20u))); } /* add dword ptr [0x10010b60], 0x20 */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x480u)); /* lea ecx, [eax + 0x480] */
L_00cd6126:;
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->cf) goto L_00cd6146; /* jae 0xcd6146 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax + 4], 0 */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [eax], 0xffffffff */
    { uint32_t a_ = (uint32_t)(c->eax + 0x8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [eax + 8], 0 */
    W8((uint32_t)(c->eax + 0x5u), (uint8_t)((uint8_t)0xau)); /* mov byte ptr [eax + 5], 0xa */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x24u)); /* add eax, 0x24 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x480u)); /* add ecx, 0x480 */
    goto L_00cd6126; /* jmp 0xcd6126 */
L_00cd6146:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, R32((uint32_t)(0xce0b60u)), c->edi); /* cmp dword ptr [0x10010b60], edi */
    if ((c->sf != c->of)) goto L_00cd6108; /* jl 0xcd6108 */
    goto L_00cd6159; /* jmp 0xcd6159 */
L_00cd6153:;
    c->edi = (uint32_t)(R32((uint32_t)(0xce0b60u))); /* mov edi, dword ptr [0x10010b60] */
L_00cd6159:;
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if ((c->zf || c->sf != c->of)) goto L_00cd61ab; /* jle 0xcd61ab */
L_00cd615f:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    (void)sub32(c, c->ecx, (uint32_t)0xffffffffu); /* cmp ecx, -1 */
    if (c->zf) goto L_00cd61a1; /* je 0xcd61a1 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebx))); /* mov al, byte ptr [ebx] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    if (c->zf) goto L_00cd61a1; /* je 0xcd61a1 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x8u)); /* test al, 8 */
    if (!c->zf) goto L_00cd617e; /* jne 0xcd617e */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t t_ = R32((uint32_t)(0xcdc06cu)); PUSH32(c, 0x00cd617au); call_indirect(c, t_); } /* call dword ptr [0x1000c06c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd61a1; /* je 0xcd61a1 */
L_00cd617e:;
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 5)); /* sar ecx, 5 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1fu))); /* and eax, 0x1f */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx * 4 + 0xce0a60u))); /* mov ecx, dword ptr [ecx*4 + 0x10010a60] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 8)); /* lea eax, [eax + eax*8] */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->eax * 4)); /* lea eax, [ecx + eax*4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov ecx, dword ptr [ecx] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebx))); /* mov cl, byte ptr [ebx] */
    W8((uint32_t)(c->eax + 0x4u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax + 4], cl */
L_00cd61a1:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x4u))); } /* add dword ptr [ebp - 4], 4 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if ((c->sf != c->of)) goto L_00cd615f; /* jl 0xcd615f */
L_00cd61ab:;
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
L_00cd61ad:;
    c->ecx = (uint32_t)(R32((uint32_t)(0xce0a60u))); /* mov ecx, dword ptr [0x10010a60] */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->ebx * 8)); /* lea eax, [ebx + ebx*8] */
    (void)sub32(c, R32((uint32_t)(c->ecx + c->eax * 4)), (uint32_t)0xffffffffu); /* cmp dword ptr [ecx + eax*4], -1 */
    c->esi = (uint32_t)((uint32_t)(c->ecx + c->eax * 4)); /* lea esi, [ecx + eax*4] */
    if (!c->zf) goto L_00cd620c; /* jne 0xcd620c */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    W8((uint32_t)(c->esi + 0x4u), (uint8_t)((uint8_t)0x81u)); /* mov byte ptr [esi + 4], 0x81 */
    if (!c->zf) goto L_00cd61cc; /* jne 0xcd61cc */
    { uint32_t v_ = 0xfffffff6u; PUSH32(c, v_); } /* push -0xa */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_00cd61d6; /* jmp 0xcd61d6 */
L_00cd61cc:;
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xfffffff5u)); /* add eax, -0xb */
L_00cd61d6:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0xcdc068u)); PUSH32(c, 0x00cd61ddu); call_indirect(c, t_); } /* call dword ptr [0x1000c068] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)sub32(c, c->edi, (uint32_t)0xffffffffu); /* cmp edi, -1 */
    if (c->zf) goto L_00cd61fb; /* je 0xcd61fb */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0xcdc06cu)); PUSH32(c, 0x00cd61ebu); call_indirect(c, t_); } /* call dword ptr [0x1000c06c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd61fb; /* je 0xcd61fb */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xffu))); /* and eax, 0xff */
    W32((uint32_t)(c->esi), (uint32_t)(c->edi)); /* mov dword ptr [esi], edi */
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00cd6201; /* jne 0xcd6201 */
L_00cd61fb:;
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x40u)))); } /* or byte ptr [esi + 4], 0x40 */
    goto L_00cd6210; /* jmp 0xcd6210 */
L_00cd6201:;
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_00cd6210; /* jne 0xcd6210 */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x8u)))); } /* or byte ptr [esi + 4], 8 */
    goto L_00cd6210; /* jmp 0xcd6210 */
L_00cd620c:;
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x80u)))); } /* or byte ptr [esi + 4], 0x80 */
L_00cd6210:;
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    (void)sub32(c, c->ebx, (uint32_t)0x3u); /* cmp ebx, 3 */
    if ((c->sf != c->of)) goto L_00cd61ad; /* jl 0xcd61ad */
    { uint32_t v_ = R32((uint32_t)(0xce0b60u)); PUSH32(c, v_); } /* push dword ptr [0x10010b60] */
    { uint32_t t_ = R32((uint32_t)(0xcdc064u)); PUSH32(c, 0x00cd6222u); call_indirect(c, t_); } /* call dword ptr [0x1000c064] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd6227(CPU *c) { /* FUN_10006227 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)((uint32_t)0xce0a60u); /* mov esi, 0x10010a60 */
L_00cd622f:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd626c; /* je 0xcd626c */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x480u)); /* add eax, 0x480 */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (!c->cf) goto L_00cd6261; /* jae 0xcd6261 */
    c->ebx = (uint32_t)((uint32_t)(c->edi + 0xcu)); /* lea ebx, [edi + 0xc] */
L_00cd6243:;
    (void)sub32(c, R32((uint32_t)(c->ebx + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebx - 4], 0 */
    if (c->zf) goto L_00cd6250; /* je 0xcd6250 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(0xcdc038u)); PUSH32(c, 0x00cd6250u); call_indirect(c, t_); } /* call dword ptr [0x1000c038] */
L_00cd6250:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x24u)); /* add edi, 0x24 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x480u)); /* add eax, 0x480 */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x24u)); /* add ebx, 0x24 */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_00cd6243; /* jb 0xcd6243 */
L_00cd6261:;
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    PUSH32(c, 0x00cd6268u); f_00cd3b31(c); /* call 0xcd3b31 */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi], 0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00cd626c:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, c->esi, (uint32_t)0xce0b60u); /* cmp esi, 0x10010b60 */
    if ((c->sf != c->of)) goto L_00cd622f; /* jl 0xcd622f */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00cd627b(CPU *c) { /* FUN_1000627b */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, R32((uint32_t)(0xce0b68u)), c->ebx); /* cmp dword ptr [0x10010b68], ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00cd628d; /* jne 0xcd628d */
    PUSH32(c, 0x00cd628du); f_00cd993d(c); /* call 0xcd993d */
L_00cd628d:;
    c->esi = (uint32_t)(R32((uint32_t)(0xce047cu))); /* mov esi, dword ptr [0x1001047c] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
L_00cd6295:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_00cd62ad; /* je 0xcd62ad */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x3du); /* cmp al, 0x3d */
    if (c->zf) goto L_00cd62a0; /* je 0xcd62a0 */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
L_00cd62a0:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd62a6u); f_00cd46d0(c); /* call 0xcd46d0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esi = (uint32_t)((uint32_t)(c->esi + c->eax + 0x1u)); /* lea esi, [esi + eax + 1] */
    goto L_00cd6295; /* jmp 0xcd6295 */
L_00cd62ad:;
    c->eax = (uint32_t)((uint32_t)(c->edi * 4 + 0x4u)); /* lea eax, [edi*4 + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd62bau); f_00cd4c86(c); /* call 0xcd4c86 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    W32((uint32_t)(0xce0514u), (uint32_t)(c->esi)); /* mov dword ptr [0x10010514], esi */
    if (!c->zf) goto L_00cd62cf; /* jne 0xcd62cf */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00cd62ceu); f_00cd33c8(c); /* call 0xcd33c8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00cd62cf:;
    c->edi = (uint32_t)(R32((uint32_t)(0xce047cu))); /* mov edi, dword ptr [0x1001047c] */
    (void)sub8(c, R8((uint32_t)(c->edi)), ((uint8_t)c->ebx)); /* cmp byte ptr [edi], bl */
    if (c->zf) goto L_00cd6312; /* je 0xcd6312 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
L_00cd62da:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00cd62e0u); f_00cd46d0(c); /* call 0xcd46d0 */
    c->ebp = (uint32_t)(c->eax); /* mov ebp, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ebp = (uint32_t)(inc32(c, c->ebp)); /* inc ebp */
    (void)sub8(c, R8((uint32_t)(c->edi)), (uint8_t)0x3du); /* cmp byte ptr [edi], 0x3d */
    if (c->zf) goto L_00cd630b; /* je 0xcd630b */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x00cd62efu); f_00cd4c86(c); /* call 0xcd4c86 */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    if (!c->zf) goto L_00cd62fe; /* jne 0xcd62fe */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00cd62fdu); f_00cd33c8(c); /* call 0xcd33c8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00cd62fe:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    PUSH32(c, 0x00cd6306u); f_00cd7420(c); /* call 0xcd7420 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00cd630b:;
    c->edi = (uint32_t)(add32(c, c->edi, c->ebp)); /* add edi, ebp */
    (void)sub8(c, R8((uint32_t)(c->edi)), ((uint8_t)c->ebx)); /* cmp byte ptr [edi], bl */
    if (!c->zf) goto L_00cd62da; /* jne 0xcd62da */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
L_00cd6312:;
    { uint32_t v_ = R32((uint32_t)(0xce047cu)); PUSH32(c, v_); } /* push dword ptr [0x1001047c] */
    PUSH32(c, 0x00cd631du); f_00cd3b31(c); /* call 0xcd3b31 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(0xce047cu), (uint32_t)(c->ebx)); /* mov dword ptr [0x1001047c], ebx */
    W32((uint32_t)(c->esi), (uint32_t)(c->ebx)); /* mov dword ptr [esi], ebx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0xce0b64u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x10010b64], 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00cd6334(CPU *c) { /* FUN_10006334 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, R32((uint32_t)(0xce0b68u)), c->ebx); /* cmp dword ptr [0x10010b68], ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00cd634b; /* jne 0xcd634b */
    PUSH32(c, 0x00cd634bu); f_00cd993d(c); /* call 0xcd993d */
L_00cd634b:;
    c->esi = (uint32_t)((uint32_t)0xce0538u); /* mov esi, 0x10010538 */
    { uint32_t v_ = 0x104u; PUSH32(c, v_); } /* push 0x104 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(0xcdc074u)); PUSH32(c, 0x00cd635du); call_indirect(c, t_); } /* call dword ptr [0x1000c074] */
    c->eax = (uint32_t)(R32((uint32_t)(0xce0b74u))); /* mov eax, dword ptr [0x10010b74] */
    W32((uint32_t)(0xce0524u), (uint32_t)(c->esi)); /* mov dword ptr [0x10010524], esi */
    c->edi = (uint32_t)(c->esi); /* mov edi, esi */
    (void)sub8(c, R8((uint32_t)(c->eax)), ((uint8_t)c->ebx)); /* cmp byte ptr [eax], bl */
    if (c->zf) goto L_00cd6370; /* je 0xcd6370 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
L_00cd6370:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00cd6380u); f_00cd63cd(c); /* call 0xcd63cd */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->ecx * 4)); /* lea eax, [eax + ecx*4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd638fu); f_00cd4c86(c); /* call 0xcd4c86 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (!c->zf) goto L_00cd63a0; /* jne 0xcd63a0 */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    PUSH32(c, 0x00cd639fu); f_00cd33c8(c); /* call 0xcd33c8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00cd63a0:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->eax * 4)); /* lea eax, [esi + eax*4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00cd63b6u); f_00cd63cd(c); /* call 0xcd63cd */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    W32((uint32_t)(0xce050cu), (uint32_t)(c->esi)); /* mov dword ptr [0x1001050c], esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0xce0508u), (uint32_t)(c->eax)); /* mov dword ptr [0x10010508], eax */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd63cd(CPU *c) { /* FUN_100063cd */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov ecx, dword ptr [ebp + 0x18] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ecx], 0 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov esi, dword ptr [ebp + 0x10] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [eax], 1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00cd63f7; /* je 0xcd63f7 */
    W32((uint32_t)(c->edi), (uint32_t)(c->esi)); /* mov dword ptr [edi], esi */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 0xc], edi */
L_00cd63f7:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x22u); /* cmp byte ptr [eax], 0x22 */
    if (!c->zf) goto L_00cd6440; /* jne 0xcd6440 */
L_00cd63fc:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1u))); /* mov dl, byte ptr [eax + 1] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x22u); /* cmp dl, 0x22 */
    if (c->zf) goto L_00cd642e; /* je 0xcd642e */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00cd642e; /* je 0xcd642e */
    c->edx = (uint32_t)((uint32_t)((uint8_t)c->edx)); /* movzx edx, dl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edx + 0xce0921u)) & (uint8_t)0x4u)); /* test byte ptr [edx + 0x10010921], 4 */
    if (c->zf) goto L_00cd6421; /* je 0xcd6421 */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00cd6421; /* je 0xcd6421 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
L_00cd6421:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00cd63fc; /* je 0xcd63fc */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    goto L_00cd63fc; /* jmp 0xcd63fc */
L_00cd642e:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00cd6438; /* je 0xcd6438 */
    { uint32_t a_ = (uint32_t)(c->esi); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [esi], 0 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_00cd6438:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x22u); /* cmp byte ptr [eax], 0x22 */
    if (!c->zf) goto L_00cd6483; /* jne 0xcd6483 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_00cd6483; /* jmp 0xcd6483 */
L_00cd6440:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00cd644b; /* je 0xcd644b */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_00cd644b:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ebx = (uint32_t)((uint32_t)((uint8_t)c->edx)); /* movzx ebx, dl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebx + 0xce0921u)) & (uint8_t)0x4u)); /* test byte ptr [ebx + 0x10010921], 4 */
    if (c->zf) goto L_00cd6466; /* je 0xcd6466 */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00cd6465; /* je 0xcd6465 */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov bl, byte ptr [eax] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [esi], bl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_00cd6465:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
L_00cd6466:;
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x20u); /* cmp dl, 0x20 */
    if (c->zf) goto L_00cd6474; /* je 0xcd6474 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00cd6478; /* je 0xcd6478 */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x9u); /* cmp dl, 9 */
    if (!c->zf) goto L_00cd6440; /* jne 0xcd6440 */
L_00cd6474:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (!c->zf) goto L_00cd647b; /* jne 0xcd647b */
L_00cd6478:;
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    goto L_00cd6483; /* jmp 0xcd6483 */
L_00cd647b:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00cd6483; /* je 0xcd6483 */
    { uint32_t a_ = (uint32_t)(c->esi + 0xffffffffu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [esi - 1], 0 */
L_00cd6483:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0x18u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp + 0x18], 0 */
L_00cd6487:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (c->zf) goto L_00cd6570; /* je 0xcd6570 */
L_00cd6490:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x20u); /* cmp dl, 0x20 */
    if (c->zf) goto L_00cd649c; /* je 0xcd649c */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x9u); /* cmp dl, 9 */
    if (!c->zf) goto L_00cd649f; /* jne 0xcd649f */
L_00cd649c:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_00cd6490; /* jmp 0xcd6490 */
L_00cd649f:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (c->zf) goto L_00cd6570; /* je 0xcd6570 */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00cd64b4; /* je 0xcd64b4 */
    W32((uint32_t)(c->edi), (uint32_t)(c->esi)); /* mov dword ptr [edi], esi */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 0xc], edi */
L_00cd64b4:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov edx, dword ptr [ebp + 0x14] */
    { uint32_t a_ = (uint32_t)(c->edx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [edx] */
L_00cd64b9:;
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp + 8], 1 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
L_00cd64c2:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x5cu); /* cmp byte ptr [eax], 0x5c */
    if (!c->zf) goto L_00cd64cb; /* jne 0xcd64cb */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    goto L_00cd64c2; /* jmp 0xcd64c2 */
L_00cd64cb:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x22u); /* cmp byte ptr [eax], 0x22 */
    if (!c->zf) goto L_00cd64fc; /* jne 0xcd64fc */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x1u)); /* test bl, 1 */
    if (!c->zf) goto L_00cd64fa; /* jne 0xcd64fa */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x18u)), c->edi); /* cmp dword ptr [ebp + 0x18], edi */
    if (c->zf) goto L_00cd64e9; /* je 0xcd64e9 */
    (void)sub8(c, R8((uint32_t)(c->eax + 0x1u)), (uint8_t)0x22u); /* cmp byte ptr [eax + 1], 0x22 */
    c->edx = (uint32_t)((uint32_t)(c->eax + 0x1u)); /* lea edx, [eax + 1] */
    if (!c->zf) goto L_00cd64e9; /* jne 0xcd64e9 */
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    goto L_00cd64ec; /* jmp 0xcd64ec */
L_00cd64e9:;
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 8], edi */
L_00cd64ec:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x18u)), c->edx); /* cmp dword ptr [ebp + 0x18], edx */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete dl */
    W32((uint32_t)(c->ebp + 0x18u), (uint32_t)(c->edx)); /* mov dword ptr [ebp + 0x18], edx */
L_00cd64fa:;
    c->ebx = (uint32_t)(shr32(c, c->ebx, 1)); /* shr ebx, 1 */
L_00cd64fc:;
    c->edx = (uint32_t)(c->ebx); /* mov edx, ebx */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_00cd6511; /* je 0xcd6511 */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
L_00cd6504:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00cd650c; /* je 0xcd650c */
    W8((uint32_t)(c->esi), (uint8_t)((uint8_t)0x5cu)); /* mov byte ptr [esi], 0x5c */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_00cd650c:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->zf) goto L_00cd6504; /* jne 0xcd6504 */
L_00cd6511:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00cd6561; /* je 0xcd6561 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x18u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x18], 0 */
    if (!c->zf) goto L_00cd6527; /* jne 0xcd6527 */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x20u); /* cmp dl, 0x20 */
    if (c->zf) goto L_00cd6561; /* je 0xcd6561 */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x9u); /* cmp dl, 9 */
    if (c->zf) goto L_00cd6561; /* je 0xcd6561 */
L_00cd6527:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    if (c->zf) goto L_00cd655b; /* je 0xcd655b */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00cd654a; /* je 0xcd654a */
    c->ebx = (uint32_t)((uint32_t)((uint8_t)c->edx)); /* movzx ebx, dl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebx + 0xce0921u)) & (uint8_t)0x4u)); /* test byte ptr [ebx + 0x10010921], 4 */
    if (c->zf) goto L_00cd6543; /* je 0xcd6543 */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
L_00cd6543:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    goto L_00cd6559; /* jmp 0xcd6559 */
L_00cd654a:;
    c->edx = (uint32_t)((uint32_t)((uint8_t)c->edx)); /* movzx edx, dl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edx + 0xce0921u)) & (uint8_t)0x4u)); /* test byte ptr [edx + 0x10010921], 4 */
    if (c->zf) goto L_00cd6559; /* je 0xcd6559 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
L_00cd6559:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
L_00cd655b:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_00cd64b9; /* jmp 0xcd64b9 */
L_00cd6561:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00cd6569; /* je 0xcd6569 */
    { uint32_t a_ = (uint32_t)(c->esi); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [esi], 0 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_00cd6569:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    goto L_00cd6487; /* jmp 0xcd6487 */
L_00cd6570:;
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00cd6577; /* je 0xcd6577 */
    { uint32_t a_ = (uint32_t)(c->edi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [edi], 0 */
L_00cd6577:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [eax] */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00cd6581(CPU *c) { /* FUN_10006581 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(0xce063cu))); /* mov eax, dword ptr [0x1001063c] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(0xcdc088u))); /* mov ebp, dword ptr [0x1000c088] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (!c->zf) goto L_00cd65cf; /* jne 0xcd65cf */
    { uint32_t t_ = c->ebp; PUSH32(c, 0x00cd659eu); call_indirect(c, t_); } /* call ebp */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (c->zf) goto L_00cd65b0; /* je 0xcd65b0 */
    W32((uint32_t)(0xce063cu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x1001063c], 1 */
    goto L_00cd65d8; /* jmp 0xcd65d8 */
L_00cd65b0:;
    { uint32_t t_ = R32((uint32_t)(0xcdc084u)); PUSH32(c, 0x00cd65b6u); call_indirect(c, t_); } /* call dword ptr [0x1000c084] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    if (c->zf) goto L_00cd66aa; /* je 0xcd66aa */
    W32((uint32_t)(0xce063cu), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [0x1001063c], 2 */
    goto L_00cd665e; /* jmp 0xcd665e */
L_00cd65cf:;
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_00cd6659; /* jne 0xcd6659 */
L_00cd65d8:;
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (!c->zf) goto L_00cd65e8; /* jne 0xcd65e8 */
    { uint32_t t_ = c->ebp; PUSH32(c, 0x00cd65deu); call_indirect(c, t_); } /* call ebp */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (c->zf) goto L_00cd66aa; /* je 0xcd66aa */
L_00cd65e8:;
    (void)sub16(c, R16((uint32_t)(c->esi)), ((uint16_t)c->ebx)); /* cmp word ptr [esi], bx */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    if (c->zf) goto L_00cd65fd; /* je 0xcd65fd */
L_00cd65ef:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub16(c, R16((uint32_t)(c->eax)), ((uint16_t)c->ebx)); /* cmp word ptr [eax], bx */
    if (!c->zf) goto L_00cd65ef; /* jne 0xcd65ef */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub16(c, R16((uint32_t)(c->eax)), ((uint16_t)c->ebx)); /* cmp word ptr [eax], bx */
    if (!c->zf) goto L_00cd65ef; /* jne 0xcd65ef */
L_00cd65fd:;
    c->eax = (uint32_t)(sub32(c, c->eax, c->esi)); /* sub eax, esi */
    c->edi = (uint32_t)(R32((uint32_t)(0xcdc080u))); /* mov edi, dword ptr [0x1000c080] */
    c->eax = (uint32_t)(sar32(c, c->eax, 1)); /* sar eax, 1 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    W32((uint32_t)(c->esp + 0x34u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x34], eax */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00cd6616u); call_indirect(c, t_); } /* call edi */
    c->ebp = (uint32_t)(c->eax); /* mov ebp, eax */
    (void)sub32(c, c->ebp, c->ebx); /* cmp ebp, ebx */
    if (c->zf) goto L_00cd664e; /* je 0xcd664e */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x00cd6622u); f_00cd4c86(c); /* call 0xcd4c86 */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    if (c->zf) goto L_00cd664e; /* je 0xcd664e */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x24u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x24] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00cd6638u); call_indirect(c, t_); } /* call edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00cd664a; /* jne 0xcd664a */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    PUSH32(c, 0x00cd6645u); f_00cd3b31(c); /* call 0xcd3b31 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x10], ebx */
L_00cd664a:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ebx, dword ptr [esp + 0x10] */
L_00cd664e:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(0xcdc07cu)); PUSH32(c, 0x00cd6655u); call_indirect(c, t_); } /* call dword ptr [0x1000c07c] */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    goto L_00cd66ac; /* jmp 0xcd66ac */
L_00cd6659:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00cd66aa; /* jne 0xcd66aa */
L_00cd665e:;
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    if (!c->zf) goto L_00cd666e; /* jne 0xcd666e */
    { uint32_t t_ = R32((uint32_t)(0xcdc084u)); PUSH32(c, 0x00cd6668u); call_indirect(c, t_); } /* call dword ptr [0x1000c084] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    if (c->zf) goto L_00cd66aa; /* je 0xcd66aa */
L_00cd666e:;
    (void)sub8(c, R8((uint32_t)(c->edi)), ((uint8_t)c->ebx)); /* cmp byte ptr [edi], bl */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    if (c->zf) goto L_00cd667e; /* je 0xcd667e */
L_00cd6674:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), ((uint8_t)c->ebx)); /* cmp byte ptr [eax], bl */
    if (!c->zf) goto L_00cd6674; /* jne 0xcd6674 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), ((uint8_t)c->ebx)); /* cmp byte ptr [eax], bl */
    if (!c->zf) goto L_00cd6674; /* jne 0xcd6674 */
L_00cd667e:;
    c->eax = (uint32_t)(sub32(c, c->eax, c->edi)); /* sub eax, edi */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ebp = (uint32_t)(c->eax); /* mov ebp, eax */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x00cd6689u); f_00cd4c86(c); /* call 0xcd4c86 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (!c->zf) goto L_00cd6694; /* jne 0xcd6694 */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    goto L_00cd669f; /* jmp 0xcd669f */
L_00cd6694:;
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd669cu); f_00cd9160(c); /* call 0xcd9160 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_00cd669f:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0xcdc078u)); PUSH32(c, 0x00cd66a6u); call_indirect(c, t_); } /* call dword ptr [0x1000c078] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    goto L_00cd66ac; /* jmp 0xcd66ac */
L_00cd66aa:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00cd66ac:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00cd66b3(CPU *c) { /* FUN_100066b3 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi], 0 */
    { uint32_t t_ = R32((uint32_t)(0xcdc030u)); PUSH32(c, 0x00cd66c3u); call_indirect(c, t_); } /* call dword ptr [0x1000c030] */
    (void)sub16(c, R16((uint32_t)(c->eax)), (uint16_t)0x5a4du); /* cmp word ptr [eax], 0x5a4d */
    if (!c->zf) goto L_00cd66de; /* jne 0xcd66de */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x3cu))); /* mov ecx, dword ptr [eax + 0x3c] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00cd66de; /* je 0xcd66de */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1au))); /* mov cl, byte ptr [eax + 0x1a] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esi], cl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1bu))); /* mov al, byte ptr [eax + 0x1b] */
    W8((uint32_t)(c->esi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [esi + 1], al */
L_00cd66de:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00cd66e0(CPU *c) { /* FUN_100066e0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->eax = (uint32_t)((uint32_t)0x122cu); /* mov eax, 0x122c */
    PUSH32(c, 0x00cd66edu); f_00cd9d10(c); /* call 0xcd9d10 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff68u)); /* lea eax, [ebp - 0x98] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(c->ebp + 0xffffff68u), (uint32_t)((uint32_t)0x94u)); /* mov dword ptr [ebp - 0x98], 0x94 */
    { uint32_t t_ = R32((uint32_t)(0xcdc090u)); PUSH32(c, 0x00cd6705u); call_indirect(c, t_); } /* call dword ptr [0x1000c090] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd6723; /* je 0xcd6723 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffff78u)), (uint32_t)0x2u); /* cmp dword ptr [ebp - 0x88], 2 */
    if (!c->zf) goto L_00cd6723; /* jne 0xcd6723 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffff6cu)), (uint32_t)0x5u); /* cmp dword ptr [ebp - 0x94], 5 */
    if (c->cf) goto L_00cd6723; /* jb 0xcd6723 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_00cd6825; /* jmp 0xcd6825 */
L_00cd6723:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffedd4u)); /* lea eax, [ebp - 0x122c] */
    { uint32_t v_ = 0x1090u; PUSH32(c, v_); } /* push 0x1090 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0xcdc3b8u; PUSH32(c, v_); } /* push 0x1000c3b8 */
    { uint32_t t_ = R32((uint32_t)(0xcdc08cu)); PUSH32(c, 0x00cd673au); call_indirect(c, t_); } /* call dword ptr [0x1000c08c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd6812; /* je 0xcd6812 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffedd4u)); /* lea ecx, [ebp - 0x122c] */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xffffedd4u)), ((uint8_t)c->ebx)); /* cmp byte ptr [ebp - 0x122c], bl */
    if (c->zf) goto L_00cd6765; /* je 0xcd6765 */
L_00cd6752:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov al, byte ptr [ecx] */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x61u); /* cmp al, 0x61 */
    if ((c->sf != c->of)) goto L_00cd6760; /* jl 0xcd6760 */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x7au); /* cmp al, 0x7a */
    if ((!c->zf && c->sf == c->of)) goto L_00cd6760; /* jg 0xcd6760 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sub8(c, ((uint8_t)c->eax), (uint8_t)0x20u)); /* sub al, 0x20 */
    W8((uint32_t)(c->ecx), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ecx], al */
L_00cd6760:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub8(c, R8((uint32_t)(c->ecx)), ((uint8_t)c->ebx)); /* cmp byte ptr [ecx], bl */
    if (!c->zf) goto L_00cd6752; /* jne 0xcd6752 */
L_00cd6765:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffedd4u)); /* lea eax, [ebp - 0x122c] */
    { uint32_t v_ = 0x16u; PUSH32(c, v_); } /* push 0x16 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0xcdc3a0u; PUSH32(c, v_); } /* push 0x1000c3a0 */
    PUSH32(c, 0x00cd6778u); f_00cd9cd0(c); /* call 0xcd9cd0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00cd6787; /* jne 0xcd6787 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffedd4u)); /* lea eax, [ebp - 0x122c] */
    goto L_00cd67d0; /* jmp 0xcd67d0 */
L_00cd6787:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe64u)); /* lea eax, [ebp - 0x19c] */
    { uint32_t v_ = 0x104u; PUSH32(c, v_); } /* push 0x104 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(0xcdc074u)); PUSH32(c, 0x00cd679au); call_indirect(c, t_); } /* call dword ptr [0x1000c074] */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xfffffe64u)), ((uint8_t)c->ebx)); /* cmp byte ptr [ebp - 0x19c], bl */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffe64u)); /* lea ecx, [ebp - 0x19c] */
    if (c->zf) goto L_00cd67bb; /* je 0xcd67bb */
L_00cd67a8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov al, byte ptr [ecx] */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x61u); /* cmp al, 0x61 */
    if ((c->sf != c->of)) goto L_00cd67b6; /* jl 0xcd67b6 */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x7au); /* cmp al, 0x7a */
    if ((!c->zf && c->sf == c->of)) goto L_00cd67b6; /* jg 0xcd67b6 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sub8(c, ((uint8_t)c->eax), (uint8_t)0x20u)); /* sub al, 0x20 */
    W8((uint32_t)(c->ecx), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ecx], al */
L_00cd67b6:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub8(c, R8((uint32_t)(c->ecx)), ((uint8_t)c->ebx)); /* cmp byte ptr [ecx], bl */
    if (!c->zf) goto L_00cd67a8; /* jne 0xcd67a8 */
L_00cd67bb:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe64u)); /* lea eax, [ebp - 0x19c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffedd4u)); /* lea eax, [ebp - 0x122c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd67ceu); f_00cd9c50(c); /* call 0xcd9c50 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00cd67d0:;
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_00cd6812; /* je 0xcd6812 */
    { uint32_t v_ = 0x2cu; PUSH32(c, v_); } /* push 0x2c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd67dcu); f_00cd9b90(c); /* call 0xcd9b90 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00cd6812; /* je 0xcd6812 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), ((uint8_t)c->ebx)); /* cmp byte ptr [eax], bl */
    if (c->zf) goto L_00cd67f7; /* je 0xcd67f7 */
L_00cd67e9:;
    (void)sub8(c, R8((uint32_t)(c->ecx)), (uint8_t)0x3bu); /* cmp byte ptr [ecx], 0x3b */
    if (!c->zf) goto L_00cd67f2; /* jne 0xcd67f2 */
    W8((uint32_t)(c->ecx), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ecx], bl */
    goto L_00cd67f3; /* jmp 0xcd67f3 */
L_00cd67f2:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
L_00cd67f3:;
    (void)sub8(c, R8((uint32_t)(c->ecx)), ((uint8_t)c->ebx)); /* cmp byte ptr [ecx], bl */
    if (!c->zf) goto L_00cd67e9; /* jne 0xcd67e9 */
L_00cd67f7:;
    { uint32_t v_ = 0xau; PUSH32(c, v_); } /* push 0xa */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd6800u); f_00cd9959(c); /* call 0xcd9959 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (c->zf) goto L_00cd6825; /* je 0xcd6825 */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (c->zf) goto L_00cd6825; /* je 0xcd6825 */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_00cd6825; /* je 0xcd6825 */
L_00cd6812:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd681bu); f_00cd66b3(c); /* call 0xcd66b3 */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xfffffffcu)), (uint8_t)0x6u); /* cmp byte ptr [ebp - 4], 6 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x3u)); /* add eax, 3 */
L_00cd6825:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd6800(CPU *c) { /* PTR_00cd6800 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (c->zf) goto L_00cd6825; /* je 0xcd6825 */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (c->zf) goto L_00cd6825; /* je 0xcd6825 */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_00cd6825; /* je 0xcd6825 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd681bu); f_00cd66b3(c); /* call 0xcd66b3 */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xfffffffcu)), (uint8_t)0x6u); /* cmp byte ptr [ebp - 4], 6 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x3u)); /* add eax, 3 */
L_00cd6825:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd6828(CPU *c) { /* FUN_10006828 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    (void)sub32(c, R32((uint32_t)(c->esp + 0x8u)), c->eax); /* cmp dword ptr [esp + 8], eax */
    { uint32_t v_ = 0x1000u; PUSH32(c, v_); } /* push 0x1000 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete al */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0xcdc098u)); PUSH32(c, 0x00cd683fu); call_indirect(c, t_); } /* call dword ptr [0x1000c098] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(0xce0a44u), (uint32_t)(c->eax)); /* mov dword ptr [0x10010a44], eax */
    if (c->zf) goto L_00cd687e; /* je 0xcd687e */
    PUSH32(c, 0x00cd684du); f_00cd66e0(c); /* call 0xcd66e0 */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    W32((uint32_t)(0xce0a48u), (uint32_t)(c->eax)); /* mov dword ptr [0x10010a48], eax */
    if (!c->zf) goto L_00cd6864; /* jne 0xcd6864 */
    { uint32_t v_ = 0x3f8u; PUSH32(c, v_); } /* push 0x3f8 */
    PUSH32(c, 0x00cd6861u); f_00cd78ae(c); /* call 0xcd78ae */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00cd686e; /* jmp 0xcd686e */
L_00cd6864:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00cd6881; /* jne 0xcd6881 */
    PUSH32(c, 0x00cd686eu); f_00cd83f5(c); /* call 0xcd83f5 */
L_00cd686e:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00cd6881; /* jne 0xcd6881 */
    { uint32_t v_ = R32((uint32_t)(0xce0a44u)); PUSH32(c, v_); } /* push dword ptr [0x10010a44] */
    { uint32_t t_ = R32((uint32_t)(0xcdc094u)); PUSH32(c, 0x00cd687eu); call_indirect(c, t_); } /* call dword ptr [0x1000c094] */
L_00cd687e:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_00cd6881:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_00cd6885(CPU *c) { /* FUN_10006885 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0xce0a48u))); /* mov eax, dword ptr [0x10010a48] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00cd68f7; /* jne 0xcd68f7 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, R32((uint32_t)(0xce0a38u)), c->ebx); /* cmp dword ptr [0x10010a38], ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(0xcdc048u))); /* mov ebp, dword ptr [0x1000c048] */
    if ((c->zf || c->sf != c->of)) goto L_00cd68e3; /* jle 0xcd68e3 */
    c->eax = (uint32_t)(R32((uint32_t)(0xce0a3cu))); /* mov eax, dword ptr [0x10010a3c] */
    c->edi = (uint32_t)(R32((uint32_t)(0xcdc09cu))); /* mov edi, dword ptr [0x1000c09c] */
    c->esi = (uint32_t)((uint32_t)(c->eax + 0xcu)); /* lea esi, [eax + 0xc] */
L_00cd68b1:;
    { uint32_t v_ = 0x4000u; PUSH32(c, v_); } /* push 0x4000 */
    { uint32_t v_ = 0x100000u; PUSH32(c, v_); } /* push 0x100000 */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00cd68bfu); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = 0x8000u; PUSH32(c, v_); } /* push 0x8000 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00cd68cau); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esi + 4] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xce0a44u)); PUSH32(c, v_); } /* push dword ptr [0x10010a44] */
    { uint32_t t_ = c->ebp; PUSH32(c, 0x00cd68d7u); call_indirect(c, t_); } /* call ebp */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x14u)); /* add esi, 0x14 */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    (void)sub32(c, c->ebx, R32((uint32_t)(0xce0a38u))); /* cmp ebx, dword ptr [0x10010a38] */
    if ((c->sf != c->of)) goto L_00cd68b1; /* jl 0xcd68b1 */
L_00cd68e3:;
    { uint32_t v_ = R32((uint32_t)(0xce0a3cu)); PUSH32(c, v_); } /* push dword ptr [0x10010a3c] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xce0a44u)); PUSH32(c, v_); } /* push dword ptr [0x10010a44] */
    { uint32_t t_ = c->ebp; PUSH32(c, 0x00cd68f3u); call_indirect(c, t_); } /* call ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    goto L_00cd691e; /* jmp 0xcd691e */
L_00cd68f7:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00cd691e; /* jne 0xcd691e */
    c->edi = (uint32_t)((uint32_t)0xcdd810u); /* mov edi, 0x1000d810 */
    c->esi = (uint32_t)(c->edi); /* mov esi, edi */
L_00cd6903:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd6918; /* je 0xcd6918 */
    { uint32_t v_ = 0x8000u; PUSH32(c, v_); } /* push 0x8000 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0xcdc09cu)); PUSH32(c, 0x00cd6918u); call_indirect(c, t_); } /* call dword ptr [0x1000c09c] */
L_00cd6918:;
    c->esi = (uint32_t)(R32((uint32_t)(c->esi))); /* mov esi, dword ptr [esi] */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_00cd6903; /* jne 0xcd6903 */
L_00cd691e:;
    { uint32_t v_ = R32((uint32_t)(0xce0a44u)); PUSH32(c, v_); } /* push dword ptr [0x10010a44] */
    { uint32_t t_ = R32((uint32_t)(0xcdc094u)); PUSH32(c, 0x00cd692au); call_indirect(c, t_); } /* call dword ptr [0x1000c094] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00cd692d(CPU *c) { /* FUN_1000692d */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 16; return; /* ret 0xc */
}

void f_00cd6933(CPU *c) { /* FUN_10006933 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0xce0484u))); /* mov eax, dword ptr [0x10010484] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_00cd694a; /* je 0xcd694a */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00cd696b; /* jne 0xcd696b */
    (void)sub32(c, R32((uint32_t)(0xce0488u)), (uint32_t)0x1u); /* cmp dword ptr [0x10010488], 1 */
    if (!c->zf) goto L_00cd696b; /* jne 0xcd696b */
L_00cd694a:;
    { uint32_t v_ = 0xfcu; PUSH32(c, v_); } /* push 0xfc */
    PUSH32(c, 0x00cd6954u); f_00cd696c(c); /* call 0xcd696c */
    c->eax = (uint32_t)(R32((uint32_t)(0xce0640u))); /* mov eax, dword ptr [0x10010640] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd6960; /* je 0xcd6960 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00cd6960u); call_indirect(c, t_); } /* call eax */
L_00cd6960:;
    { uint32_t v_ = 0xffu; PUSH32(c, v_); } /* push 0xff */
    PUSH32(c, 0x00cd696au); f_00cd696c(c); /* call 0xcd696c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00cd696b:;
    c->esp += 4; return; /* ret  */
}

void f_00cd696c(CPU *c) { /* FUN_1000696c */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x1a4u)); /* sub esp, 0x1a4 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->eax = (uint32_t)((uint32_t)0xcdd6c8u); /* mov eax, 0x1000d6c8 */
L_00cd697f:;
    (void)sub32(c, c->edx, R32((uint32_t)(c->eax))); /* cmp edx, dword ptr [eax] */
    if (c->zf) goto L_00cd698e; /* je 0xcd698e */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->eax, (uint32_t)0xcdd758u); /* cmp eax, 0x1000d758 */
    if ((c->sf != c->of)) goto L_00cd697f; /* jl 0xcd697f */
L_00cd698e:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->esi = (uint32_t)(shl32(c, c->esi, 3)); /* shl esi, 3 */
    (void)sub32(c, c->edx, R32((uint32_t)(c->esi + 0xcdd6c8u))); /* cmp edx, dword ptr [esi + 0x1000d6c8] */
    if (!c->zf) goto L_00cd6abc; /* jne 0xcd6abc */
    c->eax = (uint32_t)(R32((uint32_t)(0xce0484u))); /* mov eax, dword ptr [0x10010484] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_00cd6a96; /* je 0xcd6a96 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00cd69bf; /* jne 0xcd69bf */
    (void)sub32(c, R32((uint32_t)(0xce0488u)), (uint32_t)0x1u); /* cmp dword ptr [0x10010488], 1 */
    if (c->zf) goto L_00cd6a96; /* je 0xcd6a96 */
L_00cd69bf:;
    (void)sub32(c, c->edx, (uint32_t)0xfcu); /* cmp edx, 0xfc */
    if (c->zf) goto L_00cd6abc; /* je 0xcd6abc */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea eax, [ebp - 0x1a4] */
    { uint32_t v_ = 0x104u; PUSH32(c, v_); } /* push 0x104 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t t_ = R32((uint32_t)(0xcdc074u)); PUSH32(c, 0x00cd69dfu); call_indirect(c, t_); } /* call dword ptr [0x1000c074] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00cd69f6; /* jne 0xcd69f6 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea eax, [ebp - 0x1a4] */
    { uint32_t v_ = 0xcdc6a8u; PUSH32(c, v_); } /* push 0x1000c6a8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd69f4u); f_00cd7420(c); /* call 0xcd7420 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00cd69f6:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea eax, [ebp - 0x1a4] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea edi, [ebp - 0x1a4] */
    PUSH32(c, 0x00cd6a09u); f_00cd46d0(c); /* call 0xcd46d0 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->eax, (uint32_t)0x3cu); /* cmp eax, 0x3c */
    if ((c->cf || c->zf)) goto L_00cd6a39; /* jbe 0xcd6a39 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea eax, [ebp - 0x1a4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd6a1cu); f_00cd46d0(c); /* call 0xcd46d0 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea eax, [ebp - 0x1a4] */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3bu)); /* sub eax, 0x3b */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t v_ = 0xcdc6a4u; PUSH32(c, v_); } /* push 0x1000c6a4 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00cd6a36u); f_00cd9dd0(c); /* call 0xcd9dd0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_00cd6a39:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff60u)); /* lea eax, [ebp - 0xa0] */
    { uint32_t v_ = 0xcdc688u; PUSH32(c, v_); } /* push 0x1000c688 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd6a4au); f_00cd7420(c); /* call 0xcd7420 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff60u)); /* lea eax, [ebp - 0xa0] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd6a57u); f_00cd7430(c); /* call 0xcd7430 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff60u)); /* lea eax, [ebp - 0xa0] */
    { uint32_t v_ = 0xcdc684u; PUSH32(c, v_); } /* push 0x1000c684 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd6a68u); f_00cd7430(c); /* call 0xcd7430 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0xcdd6ccu)); PUSH32(c, v_); } /* push dword ptr [esi + 0x1000d6cc] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff60u)); /* lea eax, [ebp - 0xa0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd6a7au); f_00cd7430(c); /* call 0xcd7430 */
    { uint32_t v_ = 0x12010u; PUSH32(c, v_); } /* push 0x12010 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff60u)); /* lea eax, [ebp - 0xa0] */
    { uint32_t v_ = 0xcdc65cu; PUSH32(c, v_); } /* push 0x1000c65c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd6a90u); f_00cd9d3f(c); /* call 0xcd9d3f */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    goto L_00cd6abc; /* jmp 0xcd6abc */
L_00cd6a96:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x8u)); /* lea eax, [ebp + 8] */
    c->esi = (uint32_t)((uint32_t)(c->esi + 0xcdd6ccu)); /* lea esi, [esi + 0x1000d6cc] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    PUSH32(c, 0x00cd6aa9u); f_00cd46d0(c); /* call 0xcd46d0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    { uint32_t v_ = 0xfffffff4u; PUSH32(c, v_); } /* push -0xc */
    { uint32_t t_ = R32((uint32_t)(0xcdc068u)); PUSH32(c, 0x00cd6ab5u); call_indirect(c, t_); } /* call dword ptr [0x1000c068] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0xcdc0a0u)); PUSH32(c, 0x00cd6abcu); call_indirect(c, t_); } /* call dword ptr [0x1000c0a0] */
L_00cd6abc:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd6abf(CPU *c) { /* FUN_10006abf */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xcdc6c0u; PUSH32(c, v_); } /* push 0x1000c6c0 */
    { uint32_t v_ = 0xcd4dc8u; PUSH32(c, v_); } /* push 0x10004dc8 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    { int64_t r_ = (int64_t)(int32_t)c->esi * (int32_t)R32((uint32_t)(c->ebp + 0xcu)); c->esi = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul esi, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x1c], esi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00cd6b08; /* ja 0xcd6b08 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (!c->zf) goto L_00cd6afd; /* jne 0xcd6afd */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00cd6afd:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
    goto L_00cd6b0a; /* jmp 0xcd6b0a */
L_00cd6b08:;
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
L_00cd6b0a:;
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x20], ebx */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00cd6bbe; /* ja 0xcd6bbe */
    c->eax = (uint32_t)(R32((uint32_t)(0xce0a48u))); /* mov eax, dword ptr [0x10010a48] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_00cd6b61; /* jne 0xcd6b61 */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov edi, dword ptr [ebp - 0x1c] */
    (void)sub32(c, c->edi, R32((uint32_t)(0xce0a40u))); /* cmp edi, dword ptr [0x10010a40] */
    if ((!c->cf && !c->zf)) goto L_00cd6ba7; /* ja 0xcd6ba7 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00cd6b32u); f_00cd3abb(c); /* call 0xcd3abb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 4], ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00cd6b3cu); f_00cd7c4a(c); /* call 0xcd7c4a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00cd6b49u); f_00cd6b58(c); /* call 0xcd6b58 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (c->zf) goto L_00cd6bac; /* je 0xcd6bac */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x1c] */
    goto L_00cd6b9b; /* jmp 0xcd6b9b */
L_00cd6b61:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00cd6ba7; /* jne 0xcd6ba7 */
    (void)sub32(c, c->esi, R32((uint32_t)(0xcdf834u))); /* cmp esi, dword ptr [0x1000f834] */
    if ((!c->cf && !c->zf)) goto L_00cd6ba7; /* ja 0xcd6ba7 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00cd6b75u); f_00cd3abb(c); /* call 0xcd3abb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd6b88u); f_00cd86ed(c); /* call 0xcd86ed */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00cd6b95u); f_00cd6be1(c); /* call 0xcd6be1 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (c->zf) goto L_00cd6bac; /* je 0xcd6bac */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
L_00cd6b9b:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x20] */
    PUSH32(c, 0x00cd6ba4u); f_00cd7510(c); /* call 0xcd7510 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_00cd6ba7:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (!c->zf) goto L_00cd6bea; /* jne 0xcd6bea */
L_00cd6bac:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = R32((uint32_t)(0xce0a44u)); PUSH32(c, v_); } /* push dword ptr [0x10010a44] */
    { uint32_t t_ = R32((uint32_t)(0xcdc05cu)); PUSH32(c, 0x00cd6bbbu); call_indirect(c, t_); } /* call dword ptr [0x1000c05c] */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
L_00cd6bbe:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (!c->zf) goto L_00cd6bea; /* jne 0xcd6bea */
    (void)sub32(c, R32((uint32_t)(0xce0650u)), c->ebx); /* cmp dword ptr [0x10010650], ebx */
    if (c->zf) goto L_00cd6bea; /* je 0xcd6bea */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd6bd1u); f_00cd9143(c); /* call 0xcd9143 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00cd6b0a; /* jne 0xcd6b0a */
    goto L_00cd6bed; /* jmp 0xcd6bed */
L_00cd6bea:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov eax, dword ptr [ebp - 0x20] */
L_00cd6bed:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd6b0a(CPU *c) { /* PTR_00cd6b0a */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x20], ebx */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) { f_00cd6bbe(c); return; } /* ja 0xcd6bbe */
    c->eax = (uint32_t)(R32((uint32_t)(0xce0a48u))); /* mov eax, dword ptr [0x10010a48] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) { f_00cd6b61(c); return; } /* jne 0xcd6b61 */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov edi, dword ptr [ebp - 0x1c] */
    (void)sub32(c, c->edi, R32((uint32_t)(0xce0a40u))); /* cmp edi, dword ptr [0x10010a40] */
    if ((!c->cf && !c->zf)) { f_00cd6ba7(c); return; } /* ja 0xcd6ba7 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00cd6b32u); f_00cd3abb(c); /* call 0xcd3abb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 4], ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00cd6b3cu); f_00cd7c4a(c); /* call 0xcd7c4a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00cd6b49u); f_00cd6b58(c); /* call 0xcd6b58 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (c->zf) { f_00cd6bac(c); return; } /* je 0xcd6bac */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x1c] */
    { f_00cd6b9b(c); return; } /* jmp 0xcd6b9b */
}

void f_00cd6b53(CPU *c) { /* PTR_00cd6b53 */
    PREEMPT_POLL(c);
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    { f_00cd6b58(c); return; }
}

void f_00cd6b58(CPU *c) { /* FUN_10006b58 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00cd6b5fu); f_00cd3b1c(c); /* call 0xcd3b1c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00cd6b61(CPU *c) { /* PTR_00cd6b61 */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00cd6ba7; /* jne 0xcd6ba7 */
    (void)sub32(c, c->esi, R32((uint32_t)(0xcdf834u))); /* cmp esi, dword ptr [0x1000f834] */
    if ((!c->cf && !c->zf)) goto L_00cd6ba7; /* ja 0xcd6ba7 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00cd6b75u); f_00cd3abb(c); /* call 0xcd3abb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd6b88u); f_00cd86ed(c); /* call 0xcd86ed */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00cd6b95u); f_00cd6be1(c); /* call 0xcd6be1 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (c->zf) goto L_00cd6bac; /* je 0xcd6bac */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x20] */
    PUSH32(c, 0x00cd6ba4u); f_00cd7510(c); /* call 0xcd7510 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_00cd6ba7:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (!c->zf) { f_00cd6bea(c); return; } /* jne 0xcd6bea */
L_00cd6bac:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = R32((uint32_t)(0xce0a44u)); PUSH32(c, v_); } /* push dword ptr [0x10010a44] */
    { uint32_t t_ = R32((uint32_t)(0xcdc05cu)); PUSH32(c, 0x00cd6bbbu); call_indirect(c, t_); } /* call dword ptr [0x1000c05c] */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (!c->zf) { f_00cd6bea(c); return; } /* jne 0xcd6bea */
    (void)sub32(c, R32((uint32_t)(0xce0650u)), c->ebx); /* cmp dword ptr [0x10010650], ebx */
    if (c->zf) { f_00cd6bea(c); return; } /* je 0xcd6bea */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd6bd1u); f_00cd9143(c); /* call 0xcd9143 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00cd6b0a(c); return; } /* jne 0xcd6b0a */
    { f_00cd6bed(c); return; } /* jmp 0xcd6bed */
}

void f_00cd6b9b(CPU *c) { /* PTR_00cd6b9b */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x20] */
    PUSH32(c, 0x00cd6ba4u); f_00cd7510(c); /* call 0xcd7510 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (!c->zf) { f_00cd6bea(c); return; } /* jne 0xcd6bea */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = R32((uint32_t)(0xce0a44u)); PUSH32(c, v_); } /* push dword ptr [0x10010a44] */
    { uint32_t t_ = R32((uint32_t)(0xcdc05cu)); PUSH32(c, 0x00cd6bbbu); call_indirect(c, t_); } /* call dword ptr [0x1000c05c] */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (!c->zf) { f_00cd6bea(c); return; } /* jne 0xcd6bea */
    (void)sub32(c, R32((uint32_t)(0xce0650u)), c->ebx); /* cmp dword ptr [0x10010650], ebx */
    if (c->zf) { f_00cd6bea(c); return; } /* je 0xcd6bea */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd6bd1u); f_00cd9143(c); /* call 0xcd9143 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00cd6b0a(c); return; } /* jne 0xcd6b0a */
    { f_00cd6bed(c); return; } /* jmp 0xcd6bed */
}

void f_00cd6ba7(CPU *c) { /* PTR_00cd6ba7 */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (!c->zf) { f_00cd6bea(c); return; } /* jne 0xcd6bea */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = R32((uint32_t)(0xce0a44u)); PUSH32(c, v_); } /* push dword ptr [0x10010a44] */
    { uint32_t t_ = R32((uint32_t)(0xcdc05cu)); PUSH32(c, 0x00cd6bbbu); call_indirect(c, t_); } /* call dword ptr [0x1000c05c] */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (!c->zf) { f_00cd6bea(c); return; } /* jne 0xcd6bea */
    (void)sub32(c, R32((uint32_t)(0xce0650u)), c->ebx); /* cmp dword ptr [0x10010650], ebx */
    if (c->zf) { f_00cd6bea(c); return; } /* je 0xcd6bea */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd6bd1u); f_00cd9143(c); /* call 0xcd9143 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00cd6b0a(c); return; } /* jne 0xcd6b0a */
    { f_00cd6bed(c); return; } /* jmp 0xcd6bed */
}

void f_00cd6bac(CPU *c) { /* PTR_00cd6bac */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = R32((uint32_t)(0xce0a44u)); PUSH32(c, v_); } /* push dword ptr [0x10010a44] */
    { uint32_t t_ = R32((uint32_t)(0xcdc05cu)); PUSH32(c, 0x00cd6bbbu); call_indirect(c, t_); } /* call dword ptr [0x1000c05c] */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (!c->zf) { f_00cd6bea(c); return; } /* jne 0xcd6bea */
    (void)sub32(c, R32((uint32_t)(0xce0650u)), c->ebx); /* cmp dword ptr [0x10010650], ebx */
    if (c->zf) { f_00cd6bea(c); return; } /* je 0xcd6bea */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd6bd1u); f_00cd9143(c); /* call 0xcd9143 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00cd6b0a(c); return; } /* jne 0xcd6b0a */
    { f_00cd6bed(c); return; } /* jmp 0xcd6bed */
}

void f_00cd6bbe(CPU *c) { /* PTR_00cd6bbe */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (!c->zf) { f_00cd6bea(c); return; } /* jne 0xcd6bea */
    (void)sub32(c, R32((uint32_t)(0xce0650u)), c->ebx); /* cmp dword ptr [0x10010650], ebx */
    if (c->zf) { f_00cd6bea(c); return; } /* je 0xcd6bea */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd6bd1u); f_00cd9143(c); /* call 0xcd9143 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00cd6b0a(c); return; } /* jne 0xcd6b0a */
    { f_00cd6bed(c); return; } /* jmp 0xcd6bed */
}

void f_00cd6bdc(CPU *c) { /* PTR_00cd6bdc */
    PREEMPT_POLL(c);
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    { f_00cd6be1(c); return; }
}

void f_00cd6be1(CPU *c) { /* FUN_10006be1 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00cd6be8u); f_00cd3b1c(c); /* call 0xcd3b1c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00cd6bea(CPU *c) { /* PTR_00cd6bea */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov eax, dword ptr [ebp - 0x20] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd6bed(CPU *c) { /* PTR_00cd6bed */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}
