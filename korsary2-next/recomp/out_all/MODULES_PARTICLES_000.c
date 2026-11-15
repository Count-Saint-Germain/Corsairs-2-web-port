#include "recomp.h"

void f_00871000(CPU *c) { /* DMAInterface */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    W32((uint32_t)(0x881164u), (uint32_t)(c->eax)); /* mov dword ptr [0x10011164], eax */
    W32((uint32_t)(0x88114cu), (uint32_t)(c->eax)); /* mov dword ptr [0x1001114c], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov eax, dword ptr [eax + 4] */
    W32((uint32_t)(0x881148u), (uint32_t)(c->ecx)); /* mov dword ptr [0x10011148], ecx */
    W32((uint32_t)(0x881150u), (uint32_t)(c->eax)); /* mov dword ptr [0x10011150], eax */
    c->eax = (uint32_t)(R32((uint32_t)(0x881168u))); /* mov eax, dword ptr [0x10011168] */
    c->esp += 4; return; /* ret  */
}

void f_00871030(CPU *c) { /* FUN_10001030 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(0x881164u))); /* mov ecx, dword ptr [0x10011164] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x00871040u); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
    c->esp += 4; return; /* ret  */
}

void f_00871050(CPU *c) { /* FUN_10001050 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x881164u))); /* mov ecx, dword ptr [0x10011164] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4u)); PUSH32(c, 0x0087106au); call_indirect(c, t_); } /* call dword ptr [eax + 4] */
    c->esp += 4; return; /* ret  */
}

void f_00871070(CPU *c) { /* FUN_10001070 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x881164u))); /* mov ecx, dword ptr [0x10011164] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0xcu)); PUSH32(c, 0x0087108fu); call_indirect(c, t_); } /* call dword ptr [eax + 0xc] */
    c->esp += 4; return; /* ret  */
}

void f_00871090(CPU *c) { /* PTR_00871090 */
    PREEMPT_POLL(c);
    PUSH32(c, 0x00871095u); f_008710a0(c); /* call 0x8710a0 */
    { f_00871180(c); return; } /* jmp 0x871180 */
}

void f_008710a0(CPU *c) { /* PTR_008710a0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x881168u; PUSH32(c, v_); } /* push 0x10011168 */
    c->ecx = (uint32_t)((uint32_t)0x881154u); /* mov ecx, 0x10011154 */
    PUSH32(c, 0x008710afu); f_008710b0(c); /* call 0x8710b0 */
    c->esp += 4; return; /* ret  */
}

void f_008710b0(CPU *c) { /* PTR_008710b0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0xc], ecx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x87d0e8u)); /* mov dword ptr [eax], 0x1000d0e8 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 4], edx */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    c->esp += 8; return; /* ret 4 */
}

void f_008710d0(CPU *c) { /* PTR_008710d0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x87e040u); /* mov eax, 0x1000e040 */
    c->esp += 4; return; /* ret  */
}

void f_008710e0(CPU *c) { /* FUN_100010e0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x87c264u; PUSH32(c, v_); } /* push 0x1000c264 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov eax, dword ptr [ecx + 0xc] */
    { uint32_t v_ = 0x5u; PUSH32(c, v_); } /* push 5 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t v_ = 0x87e04cu; PUSH32(c, v_); } /* push 0x1000e04c */
    { uint32_t v_ = 0x13cu; PUSH32(c, v_); } /* push 0x13c */
    W32((uint32_t)(c->ecx + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 0xc], eax */
    PUSH32(c, 0x0087110eu); f_00871050(c); /* call 0x871050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->esp), (uint32_t)(c->eax)); /* mov dword ptr [esp], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0xc], 0 */
    if (c->zf) goto L_00871137; /* je 0x871137 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    PUSH32(c, 0x00871128u); f_008711a0(c); /* call 0x8711a0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
L_00871137:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_00871150(CPU *c) { /* FUN_10001150 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00871158u); f_00871170(c); /* call 0x871170 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00871168; /* je 0x871168 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00871165u); f_00871030(c); /* call 0x871030 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00871168:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00871170(CPU *c) { /* FUN_10001170 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx), (uint32_t)((uint32_t)0x87d108u)); /* mov dword ptr [ecx], 0x1000d108 */
    c->esp += 4; return; /* ret  */
}

void f_00871180(CPU *c) { /* PTR_00871180 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x871190u; PUSH32(c, v_); } /* push 0x10001190 */
    PUSH32(c, 0x0087118au); f_00875624(c); /* call 0x875624 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00871190(CPU *c) { /* PTR_00871190 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)0x881154u); /* mov ecx, 0x10011154 */
    { f_00871170(c); return; } /* jmp 0x871170 */
}

void f_008711a0(CPU *c) { /* FUN_100011a0 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ebp = (uint32_t)(logic32(c, 0)); /* xor ebp, ebp */
    c->edi = (uint32_t)((uint32_t)(c->ebx + 0x4u)); /* lea edi, [ebx + 4] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 4], eax */
    W32((uint32_t)(c->edi + 0x8u), (uint32_t)(c->ebp)); /* mov dword ptr [edi + 8], ebp */
    W32((uint32_t)(c->edi + 0xcu), (uint32_t)(c->ebp)); /* mov dword ptr [edi + 0xc], ebp */
    W32((uint32_t)(c->edi + 0x10u), (uint32_t)(c->ebp)); /* mov dword ptr [edi + 0x10], ebp */
    W32((uint32_t)(c->edi + 0x14u), (uint32_t)(c->ebp)); /* mov dword ptr [edi + 0x14], ebp */
    W32((uint32_t)(c->ebx), (uint32_t)((uint32_t)0x87d14cu)); /* mov dword ptr [ebx], 0x1000d14c */
    W32((uint32_t)(c->ebx + 0x1cu), (uint32_t)(c->ebp)); /* mov dword ptr [ebx + 0x1c], ebp */
    c->ecx = (uint32_t)(R32((uint32_t)(0x881148u))); /* mov ecx, dword ptr [0x10011148] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x008711d8u); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x881148u))); /* mov ecx, dword ptr [0x10011148] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x10u)); /* lea edx, [esp + 0x10] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x10u)); PUSH32(c, 0x008711e8u); call_indirect(c, t_); } /* call dword ptr [eax + 0x10] */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x10u))); /* mov edx, dword ptr [ebx + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x881148u))); /* mov ecx, dword ptr [0x10011148] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x14u))); /* mov edx, dword ptr [ebx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4u)); PUSH32(c, 0x00871204u); call_indirect(c, t_); } /* call dword ptr [eax + 4] */
    W32((uint32_t)(c->ebx), (uint32_t)((uint32_t)0x87d128u)); /* mov dword ptr [ebx], 0x1000d128 */
    c->eax = (uint32_t)(R32((uint32_t)(0x881164u))); /* mov eax, dword ptr [0x10011164] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    W32((uint32_t)(c->ebx + 0x130u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 0x130], eax */
    W32((uint32_t)(c->ebx + 0x134u), (uint32_t)(c->ebp)); /* mov dword ptr [ebx + 0x134], ebp */
    W32((uint32_t)(c->ebx + 0x138u), (uint32_t)(c->ebp)); /* mov dword ptr [ebx + 0x138], ebp */
    W32((uint32_t)(c->ebx + 0x128u), (uint32_t)(c->ebp)); /* mov dword ptr [ebx + 0x128], ebp */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    c->esp += 4; return; /* ret  */
}

void f_00871240(CPU *c) { /* FUN_10001240 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00871248u); f_00871260(c); /* call 0x871260 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00871258; /* je 0x871258 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00871255u); f_00871030(c); /* call 0x871030 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00871258:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00871260(CPU *c) { /* FUN_10001260 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x87c278u; PUSH32(c, v_); } /* push 0x1000c278 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0xc], edi */
    W32((uint32_t)(c->edi), (uint32_t)((uint32_t)0x87d128u)); /* mov dword ptr [edi], 0x1000d128 */
    c->esi = (uint32_t)(R32((uint32_t)(c->edi + 0x134u))); /* mov esi, dword ptr [edi + 0x134] */
    c->ebx = (uint32_t)((uint32_t)(c->edi + 0x134u)); /* lea ebx, [edi + 0x134] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x18], 0 */
    if (c->zf) goto L_008712c0; /* je 0x8712c0 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)((uint32_t)(c->edi + 0x138u)); /* lea ebp, [edi + 0x138] */
L_008712a4:;
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x008712adu); f_00872770(c); /* call 0x872770 */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_008712b9; /* je 0x8712b9 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax)); PUSH32(c, 0x008712b9u); call_indirect(c, t_); } /* call dword ptr [eax] */
L_008712b9:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov esi, dword ptr [ebx] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_008712a4; /* jne 0x8712a4 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
L_008712c0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x20u))); /* mov eax, dword ptr [edi + 0x20] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008712d7; /* je 0x8712d7 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x130u))); /* mov ecx, dword ptr [edi + 0x130] */
    { uint32_t v_ = 0x87e07cu; PUSH32(c, v_); } /* push 0x1000e07c */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x50u)); PUSH32(c, 0x008712d7u); call_indirect(c, t_); } /* call dword ptr [edx + 0x50] */
L_008712d7:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x128u))); /* mov eax, dword ptr [edi + 0x128] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0087131a; /* je 0x87131a */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x12cu))); /* mov eax, dword ptr [edi + 0x12c] */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->cf || c->zf)) goto L_0087130b; /* jbe 0x87130b */
L_008712ed:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x128u))); /* mov eax, dword ptr [edi + 0x128] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 4))); /* mov ecx, dword ptr [eax + esi*4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00871300; /* je 0x871300 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t t_ = R32((uint32_t)(c->edx)); PUSH32(c, 0x00871300u); call_indirect(c, t_); } /* call dword ptr [edx] */
L_00871300:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x12cu))); /* mov eax, dword ptr [edi + 0x12c] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if (c->cf) goto L_008712ed; /* jb 0x8712ed */
L_0087130b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x128u))); /* mov eax, dword ptr [edi + 0x128] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00871317u); f_00871030(c); /* call 0x871030 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_0087131a:;
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + 0x14u))); /* mov edx, dword ptr [edi + 0x14] */
    W32((uint32_t)(c->edi), (uint32_t)((uint32_t)0x87d14cu)); /* mov dword ptr [edi], 0x1000d14c */
    c->ecx = (uint32_t)(R32((uint32_t)(0x881148u))); /* mov ecx, dword ptr [0x10011148] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [esp + 0x1c], 0xffffffff */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x00871337u); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_00871350(CPU *c) { /* PTR_00871350 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x87c29bu; PUSH32(c, v_); } /* push 0x1000c29b */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x3b0u)); /* sub esp, 0x3b0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ebp = (uint32_t)(c->ecx); /* mov ebp, ecx */
    { uint32_t v_ = 0xfffffu; PUSH32(c, v_); } /* push 0xfffff */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x130u))); /* mov eax, dword ptr [ebp + 0x130] */
    c->ebx = (uint32_t)((uint32_t)(c->ebp + 0x4u)); /* lea ebx, [ebp + 4] */
    c->esi = (uint32_t)(c->ebx); /* mov esi, ebx */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0x87e120u; PUSH32(c, v_); } /* push 0x1000e120 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xb0u)); PUSH32(c, 0x0087139cu); call_indirect(c, t_); } /* call dword ptr [edx + 0xb0] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x130u))); /* mov eax, dword ptr [ebp + 0x130] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->esi = (uint32_t)(c->ebx); /* mov esi, ebx */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    { uint32_t v_ = 0x87e118u; PUSH32(c, v_); } /* push 0x1000e118 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xb0u)); PUSH32(c, 0x008713c1u); call_indirect(c, t_); } /* call dword ptr [edx + 0xb0] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x130u))); /* mov ecx, dword ptr [ebp + 0x130] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x87e118u; PUSH32(c, v_); } /* push 0x1000e118 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0xc0u)); PUSH32(c, 0x008713d6u); call_indirect(c, t_); } /* call dword ptr [eax + 0xc0] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x130u))); /* mov ecx, dword ptr [ebp + 0x130] */
    { uint32_t v_ = 0x87e07cu; PUSH32(c, v_); } /* push 0x1000e07c */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x4cu)); PUSH32(c, 0x008713e6u); call_indirect(c, t_); } /* call dword ptr [edx + 0x4c] */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    W32((uint32_t)(c->ebp + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x20], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (!c->zf) goto L_0087147b; /* jne 0x87147b */
    c->ecx = (uint32_t)(R32((uint32_t)(0x881148u))); /* mov ecx, dword ptr [0x10011148] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x18u)); PUSH32(c, 0x008713feu); call_indirect(c, t_); } /* call dword ptr [eax + 0x18] */
    c->eax = (uint32_t)(R32((uint32_t)(0x881148u))); /* mov eax, dword ptr [0x10011148] */
    { uint32_t v_ = 0x87e100u; PUSH32(c, v_); } /* push 0x1000e100 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x0087140eu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(0x881148u))); /* mov eax, dword ptr [0x10011148] */
    { uint32_t v_ = 0x38u; PUSH32(c, v_); } /* push 0x38 */
    { uint32_t v_ = 0x87e04cu; PUSH32(c, v_); } /* push 0x1000e04c */
    { uint32_t v_ = 0x87e0f4u; PUSH32(c, v_); } /* push 0x1000e0f4 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00871425u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(0x881148u))); /* mov eax, dword ptr [0x10011148] */
    { uint32_t v_ = 0x87e0dcu; PUSH32(c, v_); } /* push 0x1000e0dc */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00871435u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    W32((uint32_t)(c->esp + 0x154u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x154], esi */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00871441:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x87e0dcu))); /* mov cl, byte ptr [eax + 0x1000e0dc] */
    W8((uint32_t)(c->esp + c->eax + 0x30u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esp + eax + 0x30], cl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_00871441; /* jne 0x871441 */
    W32((uint32_t)(c->esp + 0x3c8u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x3c8], esi */
    c->ecx = (uint32_t)((uint32_t)0x4au); /* mov ecx, 0x4a */
    c->esi = (uint32_t)((uint32_t)(c->esp + 0x30u)); /* lea esi, [esp + 0x30] */
    c->edi = (uint32_t)((uint32_t)(c->esp + 0x298u)); /* lea edi, [esp + 0x298] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x298u)); /* lea edx, [esp + 0x298] */
    { uint32_t v_ = 0x87d920u; PUSH32(c, v_); } /* push 0x1000d920 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x0087147bu); f_008756fa(c); /* call 0x8756fa */
L_0087147b:;
    c->ebx = (uint32_t)((uint32_t)(c->ebp + 0x24u)); /* lea ebx, [ebp + 0x24] */
    c->eax = (uint32_t)((uint32_t)0x87e0bcu); /* mov eax, 0x1000e0bc */
    c->edx = (uint32_t)(c->ebx); /* mov edx, ebx */
    W32((uint32_t)(c->ebp + 0x12cu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0x12c], esi */
    c->edx = (uint32_t)(sub32(c, c->edx, c->eax)); /* sub edx, eax */
L_0087148d:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    W8((uint32_t)(c->edx + c->eax), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [edx + eax], cl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_0087148d; /* jne 0x87148d */
    c->ecx = (uint32_t)(R32((uint32_t)(0x881150u))); /* mov ecx, dword ptr [0x10011150] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x158u)); /* lea edx, [esp + 0x158] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x1cu)); PUSH32(c, 0x008714abu); call_indirect(c, t_); } /* call dword ptr [eax + 0x1c] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    if (c->zf) goto L_00871589; /* je 0x871589 */
    c->esi = (uint32_t)(c->ebx); /* mov esi, ebx */
    c->esi = (uint32_t)(sub32(c, c->esi, (uint32_t)0x87e0a4u)); /* sub esi, 0x1000e0a4 */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x14], esi */
    goto L_008714ca; /* jmp 0x8714ca */
L_008714c6:;
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov esi, dword ptr [esp + 0x14] */
L_008714ca:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x12cu))); /* mov eax, dword ptr [ebp + 0x12c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x128u))); /* mov edx, dword ptr [ebp + 0x128] */
    { uint32_t v_ = 0x49u; PUSH32(c, v_); } /* push 0x49 */
    { uint32_t v_ = 0x87e04cu; PUSH32(c, v_); } /* push 0x1000e04c */
    c->ecx = (uint32_t)((uint32_t)(c->eax * 4 + 0x4u)); /* lea ecx, [eax*4 + 4] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x008714ebu); f_00871070(c); /* call 0x871070 */
    W32((uint32_t)(c->ebp + 0x128u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x128], eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->eax = (uint32_t)((uint32_t)0x87e0a4u); /* mov eax, 0x1000e0a4 */
L_008714f9:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    W8((uint32_t)(c->esi + c->eax), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esi + eax], cl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_008714f9; /* jne 0x8714f9 */
    c->edi = (uint32_t)((uint32_t)(c->esp + 0x184u)); /* lea edi, [esp + 0x184] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0xffffffffu))); /* or ecx, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    while (c->ecx) { (void)sub8(c, ((uint8_t)c->eax), R8(c->edi)); c->edi += (c->df ? -1 : 1); c->ecx--; if (c->zf) break; } /* repne scasb al, byte ptr es:[edi] */
    c->ecx = (uint32_t)((uint32_t)~c->ecx); /* not ecx */
    c->edi = (uint32_t)(sub32(c, c->edi, c->ecx)); /* sub edi, ecx */
    c->esi = (uint32_t)(c->edi); /* mov esi, edi */
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    c->edi = (uint32_t)(c->ebx); /* mov edi, ebx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0xffffffffu))); /* or ecx, 0xffffffff */
    while (c->ecx) { (void)sub8(c, ((uint8_t)c->eax), R8(c->edi)); c->edi += (c->df ? -1 : 1); c->ecx--; if (c->zf) break; } /* repne scasb al, byte ptr es:[edi] */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u))); /* and ecx, 3 */
    while (c->ecx) { W8(c->edi, R8(c->esi)); c->esi += (c->df ? -1 : 1); c->edi += (c->df ? -1 : 1); c->ecx--; } /* rep movsb byte ptr es:[edi], byte ptr [esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x881150u))); /* mov ecx, dword ptr [0x10011150] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x58u)); PUSH32(c, 0x0087153bu); call_indirect(c, t_); } /* call dword ptr [eax + 0x58] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x12cu))); /* mov ecx, dword ptr [ebp + 0x12c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x128u))); /* mov edx, dword ptr [ebp + 0x128] */
    W32((uint32_t)(c->edx + c->ecx * 4), (uint32_t)(c->eax)); /* mov dword ptr [edx + ecx*4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x12cu))); /* mov eax, dword ptr [ebp + 0x12c] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x158u)); /* lea edx, [esp + 0x158] */
    W32((uint32_t)(c->ebp + 0x12cu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x12c], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(0x881150u))); /* mov ecx, dword ptr [0x10011150] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edx, dword ptr [esp + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x20u)); PUSH32(c, 0x0087156fu); call_indirect(c, t_); } /* call dword ptr [eax + 0x20] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_008714c6; /* jne 0x8714c6 */
    c->ecx = (uint32_t)(R32((uint32_t)(0x881150u))); /* mov ecx, dword ptr [0x10011150] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x24u)); PUSH32(c, 0x00871587u); call_indirect(c, t_); } /* call dword ptr [eax + 0x24] */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_00871589:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x130u))); /* mov ecx, dword ptr [ebp + 0x130] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x18], eax */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x20], esi */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x1c], eax */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x24], esi */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x28], esi */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x2c], esi */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x1cu)); /* lea eax, [esp + 0x1c] */
    { uint32_t v_ = 0x87e09cu; PUSH32(c, v_); } /* push 0x1000e09c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x44u)); PUSH32(c, 0x008715b9u); call_indirect(c, t_); } /* call dword ptr [edx + 0x44] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ebp + 0x130u))); /* mov ebp, dword ptr [ebp + 0x130] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x18u)); /* lea eax, [esp + 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov edx, dword ptr [ebp] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x48u)); PUSH32(c, 0x008715ccu); call_indirect(c, t_); } /* call dword ptr [edx + 0x48] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x3c0u))); /* mov ecx, dword ptr [esp + 0x3c0] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x3bcu)); /* add esp, 0x3bc */
    c->esp += 4; return; /* ret  */
}

void f_008715f0(CPU *c) { /* PTR_008715f0 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x90u)); /* sub esp, 0x90 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x1cu)); /* lea eax, [esp + 0x1c] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x10], esi */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0xc], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
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
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x5cu)); /* lea ecx, [esp + 0x5c] */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0xc], ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
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
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov ecx, dword ptr [esi + 0x20] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x1cu)); /* lea eax, [esp + 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x5cu)); PUSH32(c, 0x00871692u); call_indirect(c, t_); } /* call dword ptr [edx + 0x5c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov ecx, dword ptr [esi + 0x20] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x5cu)); /* lea eax, [esp + 0x5c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x58u)); PUSH32(c, 0x008716a1u); call_indirect(c, t_); } /* call dword ptr [edx + 0x58] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov ecx, dword ptr [esi + 0x20] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x5cu)); /* lea eax, [esp + 0x5c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x100u; PUSH32(c, v_); } /* push 0x100 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x58u)); PUSH32(c, 0x008716b3u); call_indirect(c, t_); } /* call dword ptr [edx + 0x58] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov ecx, dword ptr [esi + 0x20] */
    { uint32_t v_ = 0x142u; PUSH32(c, v_); } /* push 0x142 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x1b8u)); PUSH32(c, 0x008716c3u); call_indirect(c, t_); } /* call dword ptr [edx + 0x1b8] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esi + 0x134u))); /* mov ebp, dword ptr [esi + 0x134] */
    (void)logic32(c, (uint32_t)(c->ebp & c->ebp)); /* test ebp, ebp */
    c->ebx = (uint32_t)(c->ebp); /* mov ebx, ebp */
    if (c->zf) goto L_008717de; /* je 0x8717de */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
L_008716d4:;
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0x31cu)); /* lea edi, [ebp + 0x31c] */
L_008716da:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x31cu))); /* mov eax, dword ptr [ebp + 0x31c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi))); /* mov ecx, dword ptr [edi] */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->zf) goto L_0087171d; /* jne 0x87171d */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x33cu))); /* mov ecx, dword ptr [ebp + 0x33c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x33cu))); /* mov eax, dword ptr [ebx + 0x33c] */
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
    if (!c->zf) goto L_0087171d; /* jne 0x87171d */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x40cu))); /* mov edx, dword ptr [ebx + 0x40c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x40cu))); /* mov eax, dword ptr [ebp + 0x40c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00871709u); f_0087bf70(c); /* call 0x87bf70 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_0087171d; /* jne 0x87171d */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    PUSH32(c, 0x00871717u); f_008726b0(c); /* call 0x8726b0 */
    c->ebp = (uint32_t)(c->eax); /* mov ebp, eax */
    (void)logic32(c, (uint32_t)(c->ebp & c->ebp)); /* test ebp, ebp */
    if (!c->zf) goto L_008716da; /* jne 0x8716da */
L_0087171d:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov eax, dword ptr [esi + 0x20] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x40cu))); /* mov edx, dword ptr [ebx + 0x40c] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0xc0u)); PUSH32(c, 0x00871732u); call_indirect(c, t_); } /* call dword ptr [ecx + 0xc0] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_008717d3; /* je 0x8717d3 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov ecx, dword ptr [esi + 0x20] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x31cu))); /* mov edx, dword ptr [ebx + 0x31c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x7cu)); PUSH32(c, 0x0087174eu); call_indirect(c, t_); } /* call dword ptr [eax + 0x7c] */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    goto L_0087175a; /* jmp 0x87175a */
L_00871756:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
L_0087175a:;
    (void)sub32(c, c->eax, c->ebp); /* cmp eax, ebp */
    if (c->zf) goto L_008717a4; /* je 0x8717a4 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x20u)); /* lea ecx, [esp + 0x20] */
    c->edx = (uint32_t)((uint32_t)(c->eax + 0x430u)); /* lea edx, [eax + 0x430] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x18], ecx */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x1c], edx */
    c->df = 0; /* cld  */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov edi, dword ptr [esp + 0x1c] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov esi, dword ptr [esp + 0x18] */
    c->ecx = (uint32_t)((uint32_t)0x10u); /* mov ecx, 0x10 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xa4u))); /* mov ecx, dword ptr [esp + 0xa4] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    PUSH32(c, 0x0087178fu); f_00873c80(c); /* call 0x873c80 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    PUSH32(c, 0x00871798u); f_008726b0(c); /* call 0x8726b0 */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov esi, dword ptr [esp + 0x14] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00871756; /* jne 0x871756 */
L_008717a4:;
    (void)sub32(c, c->ebx, c->ebp); /* cmp ebx, ebp */
    if (c->zf) goto L_008717c4; /* je 0x8717c4 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xa4u))); /* mov edx, dword ptr [esp + 0xa4] */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x008717b7u); f_00873ed0(c); /* call 0x873ed0 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    PUSH32(c, 0x008717beu); f_008726b0(c); /* call 0x8726b0 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (!c->zf) goto L_008717a4; /* jne 0x8717a4 */
L_008717c4:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov ecx, dword ptr [esi + 0x20] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0xc4u)); PUSH32(c, 0x008717cfu); call_indirect(c, t_); } /* call dword ptr [eax + 0xc4] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_008717c4; /* jne 0x8717c4 */
L_008717d3:;
    (void)logic32(c, (uint32_t)(c->ebp & c->ebp)); /* test ebp, ebp */
    c->ebx = (uint32_t)(c->ebp); /* mov ebx, ebp */
    if (!c->zf) goto L_008716d4; /* jne 0x8716d4 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_008717de:;
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov esi, dword ptr [esi + 0x20] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x1cu)); /* lea eax, [esp + 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x58u)); PUSH32(c, 0x008717efu); call_indirect(c, t_); } /* call dword ptr [edx + 0x58] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x90u)); /* add esp, 0x90 */
    c->esp += 8; return; /* ret 4 */
}

void f_00871800(CPU *c) { /* PTR_00871800 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x134u))); /* mov esi, dword ptr [ecx + 0x134] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)((uint32_t)(c->ecx + 0x134u)); /* lea edi, [ecx + 0x134] */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0xc], ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00871834; /* je 0x871834 */
    c->ebx = (uint32_t)((uint32_t)(c->ecx + 0x138u)); /* lea ebx, [ecx + 0x138] */
L_0087181e:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00871827u); f_008727d0(c); /* call 0x8727d0 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x0087182eu); f_008726b0(c); /* call 0x8726b0 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_0087181e; /* jne 0x87181e */
L_00871834:;
    c->esi = (uint32_t)(R32((uint32_t)(c->edi))); /* mov esi, dword ptr [edi] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00871872; /* je 0x871872 */
L_0087183a:;
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00871841u); f_008726b0(c); /* call 0x8726b0 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    PUSH32(c, 0x0087184au); f_00874d20(c); /* call 0x874d20 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_0087186c; /* je 0x87186c */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x138u)); /* add eax, 0x138 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00871860u); f_00872770(c); /* call 0x872770 */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_0087186c; /* je 0x87186c */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx)); PUSH32(c, 0x0087186cu); call_indirect(c, t_); } /* call dword ptr [edx] */
L_0087186c:;
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    c->esi = (uint32_t)(c->ebx); /* mov esi, ebx */
    if (!c->zf) goto L_0087183a; /* jne 0x87183a */
L_00871872:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 8; return; /* ret 4 */
}

void f_00871880(CPU *c) { /* FUN_10001880 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x134u))); /* mov eax, dword ptr [ecx + 0x134] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0087189e; /* je 0x87189e */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
L_0087188f:;
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->zf) goto L_008718a4; /* je 0x8718a4 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    PUSH32(c, 0x0087189au); f_008726b0(c); /* call 0x8726b0 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_0087188f; /* jne 0x87188f */
L_0087189e:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
L_008718a4:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_008718b0(CPU *c) { /* FUN_100018b0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x134u))); /* mov esi, dword ptr [ecx + 0x134] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)((uint32_t)(c->ecx + 0x134u)); /* lea edi, [ecx + 0x134] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_008718e5; /* je 0x8718e5 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)((uint32_t)(c->ecx + 0x138u)); /* lea ebx, [ecx + 0x138] */
L_008718c9:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x008718d2u); f_00872770(c); /* call 0x872770 */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_008718de; /* je 0x8718de */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax)); PUSH32(c, 0x008718deu); call_indirect(c, t_); } /* call dword ptr [eax] */
L_008718de:;
    c->esi = (uint32_t)(R32((uint32_t)(c->edi))); /* mov esi, dword ptr [edi] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_008718c9; /* jne 0x8718c9 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
L_008718e5:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_008718f0(CPU *c) { /* FUN_100018f0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    c->esi = (uint32_t)(R32((uint32_t)(c->edi + 0x134u))); /* mov esi, dword ptr [edi + 0x134] */
    c->ebx = (uint32_t)((uint32_t)(c->edi + 0x134u)); /* lea ebx, [edi + 0x134] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_0087193b; /* je 0x87193b */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ebp, dword ptr [esp + 0x14] */
L_0087190a:;
    (void)sub32(c, c->esi, c->ebp); /* cmp esi, ebp */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    if (c->zf) goto L_00871922; /* je 0x871922 */
    PUSH32(c, 0x00871915u); f_008726b0(c); /* call 0x8726b0 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_0087190a; /* jne 0x87190a */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
L_00871922:;
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x138u)); /* add edi, 0x138 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x0087192fu); f_00872770(c); /* call 0x872770 */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_0087193b; /* je 0x87193b */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax)); PUSH32(c, 0x0087193bu); call_indirect(c, t_); } /* call dword ptr [eax] */
L_0087193b:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
}

void f_00871950(CPU *c) { /* FUN_10001950 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x134u))); /* mov esi, dword ptr [ecx + 0x134] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00871976; /* je 0x871976 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edi, dword ptr [esp + 0xc] */
L_00871960:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x1cu)); PUSH32(c, 0x00871968u); call_indirect(c, t_); } /* call dword ptr [eax + 0x1c] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x0087196fu); f_008726b0(c); /* call 0x8726b0 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_00871960; /* jne 0x871960 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_00871976:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00871980(CPU *c) { /* PTR_00871980 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x17cu)); /* sub esp, 0x17c */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x18cu))); /* mov esi, dword ptr [esp + 0x18c] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0xcu)); PUSH32(c, 0x00871997u); call_indirect(c, t_); } /* call dword ptr [eax + 0xc] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xffffd8f0u)); /* add eax, 0xffffd8f0 */
    (void)sub32(c, c->eax, (uint32_t)0xau); /* cmp eax, 0xa */
    if ((!c->cf && !c->zf)) goto L_00871e80; /* ja 0x871e80 */
    { uint32_t t_ = R32((uint32_t)(c->eax * 4 + 0x871e8cu)); switch (t_) { case 0x008719acu: goto L_008719ac; case 0x008719d1u: goto L_008719d1; case 0x008719f1u: goto L_008719f1; case 0x00871a09u: goto L_00871a09; case 0x00871acfu: goto L_00871acf; case 0x00871bd6u: goto L_00871bd6; case 0x00871c9cu: goto L_00871c9c; case 0x00871d9eu: goto L_00871d9e; case 0x00871e25u: goto L_00871e25; case 0x00871e80u: goto L_00871e80; default: jump_indirect(c, t_, 0x008719a5u); return; } } /* jmp dword ptr [eax*4 + 0x10001e8c] */
L_008719ac:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x008719b3u); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x18cu))); /* mov ecx, dword ptr [esp + 0x18c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(!c->zf ? 1 : 0); /* setne al */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008719c5u); f_00871950(c); /* call 0x871950 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x17cu)); /* add esp, 0x17c */
    c->esp += 4; return; /* ret  */
L_008719d1:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x008719d8u); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x18cu))); /* mov ecx, dword ptr [esp + 0x18c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008719e5u); f_008718f0(c); /* call 0x8718f0 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x17cu)); /* add esp, 0x17c */
    c->esp += 4; return; /* ret  */
L_008719f1:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x18cu))); /* mov ecx, dword ptr [esp + 0x18c] */
    PUSH32(c, 0x008719fdu); f_008718b0(c); /* call 0x8718b0 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x17cu)); /* add esp, 0x17c */
    c->esp += 4; return; /* ret  */
L_00871a09:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x84u)); /* lea ecx, [esp + 0x84] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x104u; PUSH32(c, v_); } /* push 0x104 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x30u)); PUSH32(c, 0x00871a1du); call_indirect(c, t_); } /* call dword ptr [eax + 0x30] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00871a24u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x00871a2fu); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00871a3au); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x00871a45u); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1c] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00871a50u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp + 0xcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xc] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x00871a5bu); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fld dword ptr [esp + 0x1c] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fld dword ptr [esp + 0x1c] */
    ST(0) = FTRIG(c, ST(0), cos); /* fcos  */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xcu))); /* fld dword ptr [esp + 0xc] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xcu))); /* fld dword ptr [esp + 0xc] */
    ST(0) = FTRIG(c, ST(0), cos); /* fcos  */
    WF32((uint32_t)(c->esp + 0xcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xc] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF32((uint32_t)(c->esp + 0x4cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x4c] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = -ST(0); /* fchs  */
    WF32((uint32_t)(c->esp + 0x50u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x50] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xcu))); /* fld dword ptr [esp + 0xc] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF32((uint32_t)(c->esp + 0x54u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x54] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x00871a9au); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x18cu))); /* mov edi, dword ptr [esp + 0x18c] */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    PUSH32(c, 0x00871aaau); f_00871ec0(c); /* call 0x871ec0 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00871e80; /* je 0x871e80 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4cu))); /* mov edx, dword ptr [esp + 0x4c] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    c->ecx = (uint32_t)(c->esp); /* mov ecx, esp */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x5cu))); /* mov edx, dword ptr [esp + 0x5c] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 4], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x60u))); /* mov edx, dword ptr [esp + 0x60] */
    goto L_00871b5c; /* jmp 0x871b5c */
L_00871acf:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x84u)); /* lea ecx, [esp + 0x84] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x104u; PUSH32(c, v_); } /* push 0x104 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x30u)); PUSH32(c, 0x00871ae3u); call_indirect(c, t_); } /* call dword ptr [eax + 0x30] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00871aeau); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x00871af5u); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00871b00u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x00871b0bu); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp + 0x20u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x20] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00871b16u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x24] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x00871b21u); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp + 0x28u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x28] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x00871b2cu); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x18cu))); /* mov edi, dword ptr [esp + 0x18c] */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    PUSH32(c, 0x00871b3cu); f_00871ec0(c); /* call 0x871ec0 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00871e80; /* je 0x871e80 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov edx, dword ptr [esp + 0x20] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    c->ecx = (uint32_t)(c->esp); /* mov ecx, esp */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov edx, dword ptr [esp + 0x30] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 4], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov edx, dword ptr [esp + 0x34] */
L_00871b5c:;
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 8], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov edx, dword ptr [esp + 0x28] */
    c->ecx = (uint32_t)(c->esp); /* mov ecx, esp */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov edx, dword ptr [esp + 0x2c] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 4], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov edx, dword ptr [esp + 0x30] */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 8], edx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x00871b7fu); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x12cu))); /* mov ecx, dword ptr [edi + 0x12c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + 0x128u))); /* mov edx, dword ptr [edi + 0x128] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x84u)); /* lea eax, [esp + 0x84] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00871b9cu); f_00872820(c); /* call 0x872820 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00871bb4; /* jne 0x871bb4 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    PUSH32(c, 0x00871ba8u); f_008718f0(c); /* call 0x8718f0 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x17cu)); /* add esp, 0x17c */
    c->esp += 4; return; /* ret  */
L_00871bb4:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x10u)); PUSH32(c, 0x00871bbdu); call_indirect(c, t_); } /* call dword ptr [eax + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00871bc5u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00871bccu); f_00874ef0(c); /* call 0x874ef0 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x17cu)); /* add esp, 0x17c */
    c->esp += 4; return; /* ret  */
L_00871bd6:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x84u)); /* lea ecx, [esp + 0x84] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x104u; PUSH32(c, v_); } /* push 0x104 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x30u)); PUSH32(c, 0x00871beau); call_indirect(c, t_); } /* call dword ptr [eax + 0x30] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00871bf1u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x00871bfcu); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00871c07u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x00871c12u); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1c] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00871c1du); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp + 0xcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xc] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x00871c28u); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fld dword ptr [esp + 0x1c] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fld dword ptr [esp + 0x1c] */
    ST(0) = FTRIG(c, ST(0), cos); /* fcos  */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xcu))); /* fld dword ptr [esp + 0xc] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xcu))); /* fld dword ptr [esp + 0xc] */
    ST(0) = FTRIG(c, ST(0), cos); /* fcos  */
    WF32((uint32_t)(c->esp + 0xcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xc] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF32((uint32_t)(c->esp + 0x4cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x4c] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = -ST(0); /* fchs  */
    WF32((uint32_t)(c->esp + 0x50u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x50] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xcu))); /* fld dword ptr [esp + 0xc] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF32((uint32_t)(c->esp + 0x54u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x54] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x00871c67u); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x18cu))); /* mov edi, dword ptr [esp + 0x18c] */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    PUSH32(c, 0x00871c77u); f_00871ec0(c); /* call 0x871ec0 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00871e80; /* je 0x871e80 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4cu))); /* mov edx, dword ptr [esp + 0x4c] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    c->ecx = (uint32_t)(c->esp); /* mov ecx, esp */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x5cu))); /* mov edx, dword ptr [esp + 0x5c] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 4], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x60u))); /* mov edx, dword ptr [esp + 0x60] */
    goto L_00871d29; /* jmp 0x871d29 */
L_00871c9c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x84u)); /* lea ecx, [esp + 0x84] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x104u; PUSH32(c, v_); } /* push 0x104 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x30u)); PUSH32(c, 0x00871cb0u); call_indirect(c, t_); } /* call dword ptr [eax + 0x30] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00871cb7u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x00871cc2u); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00871ccdu); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x00871cd8u); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp + 0x20u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x20] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00871ce3u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x24] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x00871ceeu); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp + 0x28u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x28] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x00871cf9u); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x18cu))); /* mov edi, dword ptr [esp + 0x18c] */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    PUSH32(c, 0x00871d09u); f_00871ec0(c); /* call 0x871ec0 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00871e80; /* je 0x871e80 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov edx, dword ptr [esp + 0x20] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    c->ecx = (uint32_t)(c->esp); /* mov ecx, esp */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov edx, dword ptr [esp + 0x30] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 4], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov edx, dword ptr [esp + 0x34] */
L_00871d29:;
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 8], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov edx, dword ptr [esp + 0x28] */
    c->ecx = (uint32_t)(c->esp); /* mov ecx, esp */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov edx, dword ptr [esp + 0x2c] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 4], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov edx, dword ptr [esp + 0x30] */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 8], edx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x00871d4cu); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x12cu))); /* mov ecx, dword ptr [edi + 0x12c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + 0x128u))); /* mov edx, dword ptr [edi + 0x128] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x84u)); /* lea eax, [esp + 0x84] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00871d69u); f_00872820(c); /* call 0x872820 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00871d81; /* jne 0x871d81 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    PUSH32(c, 0x00871d75u); f_008718f0(c); /* call 0x8718f0 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x17cu)); /* add esp, 0x17c */
    c->esp += 4; return; /* ret  */
L_00871d81:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x10u)); PUSH32(c, 0x00871d8au); call_indirect(c, t_); } /* call dword ptr [eax + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00871d92u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x17cu)); /* add esp, 0x17c */
    c->esp += 4; return; /* ret  */
L_00871d9e:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0xcu)); PUSH32(c, 0x00871da5u); call_indirect(c, t_); } /* call dword ptr [eax + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x18cu))); /* mov ecx, dword ptr [esp + 0x18c] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00871db4u); f_00871880(c); /* call 0x871880 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00871dd8; /* jne 0x871dd8 */
    c->eax = (uint32_t)(R32((uint32_t)(0x881164u))); /* mov eax, dword ptr [0x10011164] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x87e128u; PUSH32(c, v_); } /* push 0x1000e128 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x00871dc9u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x17cu)); /* add esp, 0x17c */
    c->esp += 4; return; /* ret  */
L_00871dd8:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00871ddfu); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x00871deau); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00871df5u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edx, dword ptr [esp + 0x14] */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    c->eax = (uint32_t)(c->esp); /* mov eax, esp */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov ecx, dword ptr [esp + 0x24] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 4], edx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    PUSH32(c, 0x00871e19u); f_00874d40(c); /* call 0x874d40 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x17cu)); /* add esp, 0x17c */
    c->esp += 4; return; /* ret  */
L_00871e25:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x00871e2cu); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x18cu))); /* mov ecx, dword ptr [esp + 0x18c] */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00871e3bu); f_00871880(c); /* call 0x871880 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00871e5f; /* jne 0x871e5f */
    c->eax = (uint32_t)(R32((uint32_t)(0x881164u))); /* mov eax, dword ptr [0x10011164] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x87e128u; PUSH32(c, v_); } /* push 0x1000e128 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x00871e50u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x17cu)); /* add esp, 0x17c */
    c->esp += 4; return; /* ret  */
L_00871e5f:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x6cu)); /* lea eax, [esp + 0x6c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x24u)); PUSH32(c, 0x00871e6bu); call_indirect(c, t_); } /* call dword ptr [edx + 0x24] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    PUSH32(c, 0x00871e80u); f_00874ed0(c); /* call 0x874ed0 */
L_00871e80:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x17cu)); /* add esp, 0x17c */
    c->esp += 4; return; /* ret  */
}

void f_008719ac(CPU *c) { /* PTR_008719ac */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x008719b3u); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x18cu))); /* mov ecx, dword ptr [esp + 0x18c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(!c->zf ? 1 : 0); /* setne al */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008719c5u); f_00871950(c); /* call 0x871950 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x17cu)); /* add esp, 0x17c */
    c->esp += 4; return; /* ret  */
}

void f_008719d1(CPU *c) { /* PTR_008719d1 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x008719d8u); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x18cu))); /* mov ecx, dword ptr [esp + 0x18c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008719e5u); f_008718f0(c); /* call 0x8718f0 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x17cu)); /* add esp, 0x17c */
    c->esp += 4; return; /* ret  */
}

void f_008719f1(CPU *c) { /* PTR_008719f1 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x18cu))); /* mov ecx, dword ptr [esp + 0x18c] */
    PUSH32(c, 0x008719fdu); f_008718b0(c); /* call 0x8718b0 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x17cu)); /* add esp, 0x17c */
    c->esp += 4; return; /* ret  */
}

void f_00871a09(CPU *c) { /* PTR_00871a09 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x84u)); /* lea ecx, [esp + 0x84] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x104u; PUSH32(c, v_); } /* push 0x104 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x30u)); PUSH32(c, 0x00871a1du); call_indirect(c, t_); } /* call dword ptr [eax + 0x30] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00871a24u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x00871a2fu); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00871a3au); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x00871a45u); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1c] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00871a50u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp + 0xcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xc] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x00871a5bu); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fld dword ptr [esp + 0x1c] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fld dword ptr [esp + 0x1c] */
    ST(0) = FTRIG(c, ST(0), cos); /* fcos  */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xcu))); /* fld dword ptr [esp + 0xc] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xcu))); /* fld dword ptr [esp + 0xc] */
    ST(0) = FTRIG(c, ST(0), cos); /* fcos  */
    WF32((uint32_t)(c->esp + 0xcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xc] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF32((uint32_t)(c->esp + 0x4cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x4c] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = -ST(0); /* fchs  */
    WF32((uint32_t)(c->esp + 0x50u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x50] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xcu))); /* fld dword ptr [esp + 0xc] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF32((uint32_t)(c->esp + 0x54u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x54] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x00871a9au); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x18cu))); /* mov edi, dword ptr [esp + 0x18c] */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    PUSH32(c, 0x00871aaau); f_00871ec0(c); /* call 0x871ec0 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00871e80; /* je 0x871e80 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4cu))); /* mov edx, dword ptr [esp + 0x4c] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    c->ecx = (uint32_t)(c->esp); /* mov ecx, esp */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x5cu))); /* mov edx, dword ptr [esp + 0x5c] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 4], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x60u))); /* mov edx, dword ptr [esp + 0x60] */
    goto L_00871b5c; /* jmp 0x871b5c */
L_00871b5c:;
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 8], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov edx, dword ptr [esp + 0x28] */
    c->ecx = (uint32_t)(c->esp); /* mov ecx, esp */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov edx, dword ptr [esp + 0x2c] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 4], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov edx, dword ptr [esp + 0x30] */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 8], edx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x00871b7fu); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x12cu))); /* mov ecx, dword ptr [edi + 0x12c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + 0x128u))); /* mov edx, dword ptr [edi + 0x128] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x84u)); /* lea eax, [esp + 0x84] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00871b9cu); f_00872820(c); /* call 0x872820 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00871bb4; /* jne 0x871bb4 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    PUSH32(c, 0x00871ba8u); f_008718f0(c); /* call 0x8718f0 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x17cu)); /* add esp, 0x17c */
    c->esp += 4; return; /* ret  */
L_00871bb4:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x10u)); PUSH32(c, 0x00871bbdu); call_indirect(c, t_); } /* call dword ptr [eax + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00871bc5u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00871bccu); f_00874ef0(c); /* call 0x874ef0 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x17cu)); /* add esp, 0x17c */
    c->esp += 4; return; /* ret  */
L_00871e80:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x17cu)); /* add esp, 0x17c */
    c->esp += 4; return; /* ret  */
}

void f_00871acf(CPU *c) { /* PTR_00871acf */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x84u)); /* lea ecx, [esp + 0x84] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x104u; PUSH32(c, v_); } /* push 0x104 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x30u)); PUSH32(c, 0x00871ae3u); call_indirect(c, t_); } /* call dword ptr [eax + 0x30] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00871aeau); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x00871af5u); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00871b00u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x00871b0bu); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp + 0x20u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x20] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00871b16u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x24] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x00871b21u); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp + 0x28u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x28] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x00871b2cu); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x18cu))); /* mov edi, dword ptr [esp + 0x18c] */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    PUSH32(c, 0x00871b3cu); f_00871ec0(c); /* call 0x871ec0 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00871e80; /* je 0x871e80 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov edx, dword ptr [esp + 0x20] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    c->ecx = (uint32_t)(c->esp); /* mov ecx, esp */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov edx, dword ptr [esp + 0x30] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 4], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov edx, dword ptr [esp + 0x34] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 8], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov edx, dword ptr [esp + 0x28] */
    c->ecx = (uint32_t)(c->esp); /* mov ecx, esp */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov edx, dword ptr [esp + 0x2c] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 4], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov edx, dword ptr [esp + 0x30] */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 8], edx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x00871b7fu); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x12cu))); /* mov ecx, dword ptr [edi + 0x12c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + 0x128u))); /* mov edx, dword ptr [edi + 0x128] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x84u)); /* lea eax, [esp + 0x84] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00871b9cu); f_00872820(c); /* call 0x872820 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00871bb4; /* jne 0x871bb4 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    PUSH32(c, 0x00871ba8u); f_008718f0(c); /* call 0x8718f0 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x17cu)); /* add esp, 0x17c */
    c->esp += 4; return; /* ret  */
L_00871bb4:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x10u)); PUSH32(c, 0x00871bbdu); call_indirect(c, t_); } /* call dword ptr [eax + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00871bc5u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00871bccu); f_00874ef0(c); /* call 0x874ef0 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x17cu)); /* add esp, 0x17c */
    c->esp += 4; return; /* ret  */
L_00871e80:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x17cu)); /* add esp, 0x17c */
    c->esp += 4; return; /* ret  */
}

void f_00871bd6(CPU *c) { /* PTR_00871bd6 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x84u)); /* lea ecx, [esp + 0x84] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x104u; PUSH32(c, v_); } /* push 0x104 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x30u)); PUSH32(c, 0x00871beau); call_indirect(c, t_); } /* call dword ptr [eax + 0x30] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00871bf1u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x00871bfcu); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00871c07u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x00871c12u); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1c] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00871c1du); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp + 0xcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xc] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x00871c28u); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fld dword ptr [esp + 0x1c] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fld dword ptr [esp + 0x1c] */
    ST(0) = FTRIG(c, ST(0), cos); /* fcos  */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xcu))); /* fld dword ptr [esp + 0xc] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xcu))); /* fld dword ptr [esp + 0xc] */
    ST(0) = FTRIG(c, ST(0), cos); /* fcos  */
    WF32((uint32_t)(c->esp + 0xcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xc] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF32((uint32_t)(c->esp + 0x4cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x4c] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = -ST(0); /* fchs  */
    WF32((uint32_t)(c->esp + 0x50u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x50] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xcu))); /* fld dword ptr [esp + 0xc] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF32((uint32_t)(c->esp + 0x54u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x54] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x00871c67u); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x18cu))); /* mov edi, dword ptr [esp + 0x18c] */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    PUSH32(c, 0x00871c77u); f_00871ec0(c); /* call 0x871ec0 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00871e80; /* je 0x871e80 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4cu))); /* mov edx, dword ptr [esp + 0x4c] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    c->ecx = (uint32_t)(c->esp); /* mov ecx, esp */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x5cu))); /* mov edx, dword ptr [esp + 0x5c] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 4], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x60u))); /* mov edx, dword ptr [esp + 0x60] */
    goto L_00871d29; /* jmp 0x871d29 */
L_00871d29:;
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 8], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov edx, dword ptr [esp + 0x28] */
    c->ecx = (uint32_t)(c->esp); /* mov ecx, esp */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov edx, dword ptr [esp + 0x2c] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 4], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov edx, dword ptr [esp + 0x30] */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 8], edx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x00871d4cu); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x12cu))); /* mov ecx, dword ptr [edi + 0x12c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + 0x128u))); /* mov edx, dword ptr [edi + 0x128] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x84u)); /* lea eax, [esp + 0x84] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00871d69u); f_00872820(c); /* call 0x872820 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00871d81; /* jne 0x871d81 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    PUSH32(c, 0x00871d75u); f_008718f0(c); /* call 0x8718f0 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x17cu)); /* add esp, 0x17c */
    c->esp += 4; return; /* ret  */
L_00871d81:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x10u)); PUSH32(c, 0x00871d8au); call_indirect(c, t_); } /* call dword ptr [eax + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00871d92u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x17cu)); /* add esp, 0x17c */
    c->esp += 4; return; /* ret  */
L_00871e80:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x17cu)); /* add esp, 0x17c */
    c->esp += 4; return; /* ret  */
}

void f_00871c9c(CPU *c) { /* PTR_00871c9c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x84u)); /* lea ecx, [esp + 0x84] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x104u; PUSH32(c, v_); } /* push 0x104 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x30u)); PUSH32(c, 0x00871cb0u); call_indirect(c, t_); } /* call dword ptr [eax + 0x30] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00871cb7u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x00871cc2u); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00871ccdu); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x00871cd8u); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp + 0x20u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x20] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00871ce3u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x24] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x00871ceeu); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp + 0x28u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x28] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x00871cf9u); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x18cu))); /* mov edi, dword ptr [esp + 0x18c] */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    PUSH32(c, 0x00871d09u); f_00871ec0(c); /* call 0x871ec0 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00871e80; /* je 0x871e80 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov edx, dword ptr [esp + 0x20] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    c->ecx = (uint32_t)(c->esp); /* mov ecx, esp */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov edx, dword ptr [esp + 0x30] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 4], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov edx, dword ptr [esp + 0x34] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 8], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov edx, dword ptr [esp + 0x28] */
    c->ecx = (uint32_t)(c->esp); /* mov ecx, esp */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov edx, dword ptr [esp + 0x2c] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 4], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov edx, dword ptr [esp + 0x30] */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 8], edx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x00871d4cu); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x12cu))); /* mov ecx, dword ptr [edi + 0x12c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + 0x128u))); /* mov edx, dword ptr [edi + 0x128] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x84u)); /* lea eax, [esp + 0x84] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00871d69u); f_00872820(c); /* call 0x872820 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00871d81; /* jne 0x871d81 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    PUSH32(c, 0x00871d75u); f_008718f0(c); /* call 0x8718f0 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x17cu)); /* add esp, 0x17c */
    c->esp += 4; return; /* ret  */
L_00871d81:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x10u)); PUSH32(c, 0x00871d8au); call_indirect(c, t_); } /* call dword ptr [eax + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00871d92u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x17cu)); /* add esp, 0x17c */
    c->esp += 4; return; /* ret  */
L_00871e80:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x17cu)); /* add esp, 0x17c */
    c->esp += 4; return; /* ret  */
}

void f_00871d9e(CPU *c) { /* PTR_00871d9e */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0xcu)); PUSH32(c, 0x00871da5u); call_indirect(c, t_); } /* call dword ptr [eax + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x18cu))); /* mov ecx, dword ptr [esp + 0x18c] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00871db4u); f_00871880(c); /* call 0x871880 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00871dd8; /* jne 0x871dd8 */
    c->eax = (uint32_t)(R32((uint32_t)(0x881164u))); /* mov eax, dword ptr [0x10011164] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x87e128u; PUSH32(c, v_); } /* push 0x1000e128 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x00871dc9u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x17cu)); /* add esp, 0x17c */
    c->esp += 4; return; /* ret  */
L_00871dd8:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00871ddfu); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x00871deau); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00871df5u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edx, dword ptr [esp + 0x14] */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    c->eax = (uint32_t)(c->esp); /* mov eax, esp */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov ecx, dword ptr [esp + 0x24] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 4], edx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    PUSH32(c, 0x00871e19u); f_00874d40(c); /* call 0x874d40 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x17cu)); /* add esp, 0x17c */
    c->esp += 4; return; /* ret  */
}

void f_00871e25(CPU *c) { /* PTR_00871e25 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x00871e2cu); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x18cu))); /* mov ecx, dword ptr [esp + 0x18c] */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00871e3bu); f_00871880(c); /* call 0x871880 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00871e5f; /* jne 0x871e5f */
    c->eax = (uint32_t)(R32((uint32_t)(0x881164u))); /* mov eax, dword ptr [0x10011164] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x87e128u; PUSH32(c, v_); } /* push 0x1000e128 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x00871e50u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x17cu)); /* add esp, 0x17c */
    c->esp += 4; return; /* ret  */
L_00871e5f:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x6cu)); /* lea eax, [esp + 0x6c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x24u)); PUSH32(c, 0x00871e6bu); call_indirect(c, t_); } /* call dword ptr [edx + 0x24] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    PUSH32(c, 0x00871e80u); f_00874ed0(c); /* call 0x874ed0 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x17cu)); /* add esp, 0x17c */
    c->esp += 4; return; /* ret  */
}

void f_00871e80(CPU *c) { /* PTR_00871e80 */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x17cu)); /* add esp, 0x17c */
    c->esp += 4; return; /* ret  */
}

void f_00871e8c(CPU *c) { /* PTR_00871e8c */
    PREEMPT_POLL(c);
    guest_trap(c, 0x00871e8cu, "unsupported: salc "); /* salc  */
    c->eax = (uint32_t)(sbb32(c, c->eax, R32((uint32_t)(c->eax)))); /* sbb eax, dword ptr [eax] */
    { uint32_t a_ = (uint32_t)(c->eax + 0x9c10001eu); W8(a_, (uint8_t)(adc8(c, R8(a_), ((uint8_t)c->eax)))); } /* adc byte ptr [eax - 0x63efffe2], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sbb8(c, ((uint8_t)c->eax), (uint8_t)0x0u)); /* sbb al, 0 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x9e10001eu); W8(a_, (uint8_t)(adc8(c, R8(a_), ((uint8_t)c->eax)))); } /* adc byte ptr [eax - 0x61efffe2], al */
    c->eax = (uint32_t)(sbb32(c, c->eax, (uint32_t)0x1e251000u)); /* sbb eax, 0x1e251000 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    guest_trap(c, 0x00871ea4u, "unsupported: int1 "); /* int1  */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(sbb32(c, R32(a_), c->eax))); } /* sbb dword ptr [eax], eax */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(adc8(c, ((uint8_t)c->ecx), ((uint8_t)c->edx))); /* adc cl, dl */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(sbb32(c, R32(a_), c->eax))); } /* sbb dword ptr [eax], eax */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(adc8(c, R8(a_), ((uint8_t)c->ecx)))); } /* adc byte ptr [ecx], cl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sbb8(c, ((uint8_t)c->eax), R8((uint32_t)(c->eax)))); /* sbb al, byte ptr [eax] */
    c->ebx = (c->ebx & 0xffff00ffu) | ((uint32_t)(uint8_t)(adc8(c, ((uint8_t)(c->ebx >> 8)), ((uint8_t)c->ecx))) << 8); /* adc bh, cl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sbb8(c, ((uint8_t)c->eax), R8((uint32_t)(c->eax)))); /* sbb al, byte ptr [eax] */
    { uint32_t a_ = (uint32_t)(c->ecx + c->ebx + 0x90901000u); W8(a_, (uint8_t)(adc8(c, R8(a_), ((uint8_t)(c->ecx >> 8))))); } /* adc byte ptr [ecx + ebx - 0x6f6ff000], ch */
    ; /* nop  */
    ; /* nop  */
    ; /* nop  */
    ; /* nop  */
    ; /* nop  */
    ; /* nop  */
    { f_00871ec0(c); return; }
}

void f_00871ec0(CPU *c) { /* FUN_10001ec0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x87c2d5u; PUSH32(c, v_); } /* push 0x1000c2d5 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x254u)); /* sub esp, 0x254 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x1fau; PUSH32(c, v_); } /* push 0x1fa */
    { uint32_t v_ = 0x87e04cu; PUSH32(c, v_); } /* push 0x1000e04c */
    { uint32_t v_ = 0x4d0u; PUSH32(c, v_); } /* push 0x4d0 */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    PUSH32(c, 0x00871ef3u); f_00871050(c); /* call 0x871050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 8], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esp + 0x264u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x264], 0 */
    if (c->zf) goto L_00871f14; /* je 0x871f14 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    PUSH32(c, 0x00871f10u); f_008723a0(c); /* call 0x8723a0 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    goto L_00871f16; /* jmp 0x871f16 */
L_00871f14:;
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_00871f16:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    W32((uint32_t)(c->esp + 0x264u), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [esp + 0x264], 0xffffffff */
    if (!c->zf) goto L_00871fb8; /* jne 0x871fb8 */
    c->ecx = (uint32_t)(R32((uint32_t)(0x881148u))); /* mov ecx, dword ptr [0x10011148] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x18u)); PUSH32(c, 0x00871f34u); call_indirect(c, t_); } /* call dword ptr [eax + 0x18] */
    c->eax = (uint32_t)(R32((uint32_t)(0x881148u))); /* mov eax, dword ptr [0x10011148] */
    { uint32_t v_ = 0x87e100u; PUSH32(c, v_); } /* push 0x1000e100 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00871f44u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(0x881148u))); /* mov eax, dword ptr [0x10011148] */
    { uint32_t v_ = 0x1fbu; PUSH32(c, v_); } /* push 0x1fb */
    { uint32_t v_ = 0x87e04cu; PUSH32(c, v_); } /* push 0x1000e04c */
    { uint32_t v_ = 0x87e0f4u; PUSH32(c, v_); } /* push 0x1000e0f4 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00871f5eu); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(0x881148u))); /* mov eax, dword ptr [0x10011148] */
    { uint32_t v_ = 0x87e14cu; PUSH32(c, v_); } /* push 0x1000e14c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00871f6eu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    W32((uint32_t)(c->esp + 0x130u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x130], esi */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00871f7a:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x87e14cu))); /* mov cl, byte ptr [eax + 0x1000e14c] */
    W8((uint32_t)(c->esp + c->eax + 0xcu), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esp + eax + 0xc], cl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_00871f7a; /* jne 0x871f7a */
    c->ecx = (uint32_t)((uint32_t)0x4au); /* mov ecx, 0x4a */
    c->esi = (uint32_t)((uint32_t)(c->esp + 0xcu)); /* lea esi, [esp + 0xc] */
    c->edi = (uint32_t)((uint32_t)(c->esp + 0x134u)); /* lea edi, [esp + 0x134] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x134u)); /* lea edx, [esp + 0x134] */
    { uint32_t v_ = 0x87d920u; PUSH32(c, v_); } /* push 0x1000d920 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    W32((uint32_t)(c->esp + 0x26cu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [esp + 0x26c], 1 */
    PUSH32(c, 0x00871fb8u); f_008756fa(c); /* call 0x8756fa */
L_00871fb8:;
    c->eax = (uint32_t)((uint32_t)(c->edi + 0x138u)); /* lea eax, [edi + 0x138] */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x134u)); /* add edi, 0x134 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00871fcdu); f_008726e0(c); /* call 0x8726e0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x25cu))); /* mov ecx, dword ptr [esp + 0x25c] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x260u)); /* add esp, 0x260 */
    c->esp += 4; return; /* ret  */
}

void f_00871ff0(CPU *c) { /* PTR_00871ff0 */
    PREEMPT_POLL(c);
    c->esp += 16; return; /* ret 0xc */
}

void f_00872000(CPU *c) { /* PTR_00872000 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x114u)); /* sub esp, 0x114 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x120u))); /* mov esi, dword ptr [esp + 0x120] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    if (!c->zf) goto L_00872024; /* jne 0x872024 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x114u)); /* add esp, 0x114 */
    c->esp += 8; return; /* ret 4 */
L_00872024:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov edx, dword ptr [esi + 8] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x0087202fu); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_0087203f; /* jne 0x87203f */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x114u)); /* add esp, 0x114 */
    c->esp += 8; return; /* ret 4 */
L_0087203f:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov edx, dword ptr [esi + 8] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x0087204au); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x1cu)); /* lea edx, [esp + 0x1c] */
L_0087204e:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    W8((uint32_t)(c->edx), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [edx], cl */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_0087204e; /* jne 0x87204e */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x1cu)); /* lea eax, [esp + 0x1c] */
    { uint32_t v_ = 0x87e164u; PUSH32(c, v_); } /* push 0x1000e164 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00872067u); f_0087bf70(c); /* call 0x87bf70 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_008720b2; /* jne 0x8720b2 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov ecx, dword ptr [esi + 0xc] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00872077u); f_00875734(c); /* call 0x875734 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x134u))); /* mov eax, dword ptr [ebx + 0x134] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    WF32((uint32_t)(c->esp + 0xcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00872260; /* je 0x872260 */
L_0087208c:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    W32((uint32_t)(c->eax + 0x390u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 0x390], edx */
    PUSH32(c, 0x0087209du); f_008726b0(c); /* call 0x8726b0 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_0087208c; /* jne 0x87208c */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x114u)); /* add esp, 0x114 */
    c->esp += 8; return; /* ret 4 */
L_008720b2:;
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x1cu)); /* lea eax, [esp + 0x1c] */
    { uint32_t v_ = 0x87e160u; PUSH32(c, v_); } /* push 0x1000e160 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008720c1u); f_0087bf70(c); /* call 0x87bf70 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008720f8; /* je 0x8720f8 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x1cu)); /* lea ecx, [esp + 0x1c] */
    { uint32_t v_ = 0x87e15cu; PUSH32(c, v_); } /* push 0x1000e15c */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x008720d7u); f_0087bf70(c); /* call 0x87bf70 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008720f8; /* je 0x8720f8 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x1cu)); /* lea edx, [esp + 0x1c] */
    { uint32_t v_ = 0x87e158u; PUSH32(c, v_); } /* push 0x1000e158 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x008720edu); f_0087bf70(c); /* call 0x87bf70 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00872260; /* jne 0x872260 */
L_008720f8:;
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0x14u))); /* mov esi, dword ptr [esi + 0x14] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_0087210d; /* jne 0x87210d */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x114u)); /* add esp, 0x114 */
    c->esp += 8; return; /* ret 4 */
L_0087210d:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0xc], 0 */
    if ((c->cf || c->zf)) goto L_00872165; /* jbe 0x872165 */
L_0087211e:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->edi * 4))); /* mov eax, dword ptr [eax + edi*4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x0087212fu); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x87e160u; PUSH32(c, v_); } /* push 0x1000e160 */
    PUSH32(c, 0x0087213au); f_0087bf70(c); /* call 0x87bf70 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0087214b; /* je 0x87214b */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_0087211e; /* jb 0x87211e */
    goto L_00872165; /* jmp 0x872165 */
L_0087214b:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + c->edi * 4))); /* mov edx, dword ptr [ecx + edi*4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0xcu))); /* mov eax, dword ptr [edx + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00872165; /* je 0x872165 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0087215eu); f_00875734(c); /* call 0x875734 */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00872165:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0xc], 0 */
    if ((c->cf || c->zf)) goto L_008721c5; /* jbe 0x8721c5 */
L_0087217e:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + c->edi * 4))); /* mov eax, dword ptr [ecx + edi*4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x0087218fu); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x87e15cu; PUSH32(c, v_); } /* push 0x1000e15c */
    PUSH32(c, 0x0087219au); f_0087bf70(c); /* call 0x87bf70 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008721ab; /* je 0x8721ab */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_0087217e; /* jb 0x87217e */
    goto L_008721c5; /* jmp 0x8721c5 */
L_008721ab:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + c->edi * 4))); /* mov edx, dword ptr [ecx + edi*4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0xcu))); /* mov eax, dword ptr [edx + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008721c5; /* je 0x8721c5 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008721beu); f_00875734(c); /* call 0x875734 */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_008721c5:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0xc], 0 */
    if ((c->cf || c->zf)) goto L_00872225; /* jbe 0x872225 */
L_008721de:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + c->edi * 4))); /* mov eax, dword ptr [ecx + edi*4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x008721efu); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x87e158u; PUSH32(c, v_); } /* push 0x1000e158 */
    PUSH32(c, 0x008721fau); f_0087bf70(c); /* call 0x87bf70 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0087220b; /* je 0x87220b */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_008721de; /* jb 0x8721de */
    goto L_00872225; /* jmp 0x872225 */
L_0087220b:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + c->edi * 4))); /* mov edx, dword ptr [ecx + edi*4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0xcu))); /* mov eax, dword ptr [edx + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00872225; /* je 0x872225 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0087221eu); f_00875734(c); /* call 0x875734 */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00872225:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x18], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x134u))); /* mov eax, dword ptr [ebx + 0x134] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00872260; /* je 0x872260 */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov esi, dword ptr [esp + 0x14] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov edi, dword ptr [esp + 0x18] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ebx, dword ptr [esp + 0x10] */
L_00872243:;
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x384u)); /* lea ecx, [eax + 0x384] */
    W32((uint32_t)(c->eax + 0x384u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x384], ebx */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [ecx + 4], esi */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [ecx + 8], edi */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    PUSH32(c, 0x0087225cu); f_008726b0(c); /* call 0x8726b0 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00872243; /* jne 0x872243 */
L_00872260:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x114u)); /* add esp, 0x114 */
    c->esp += 8; return; /* ret 4 */
}

void f_00872280(CPU *c) { /* FUN_10002280 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x87d14cu)); /* mov dword ptr [eax], 0x1000d14c */
    c->ecx = (uint32_t)(R32((uint32_t)(0x881148u))); /* mov ecx, dword ptr [0x10011148] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x14u))); /* mov eax, dword ptr [eax + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x00872297u); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    c->esp += 4; return; /* ret  */
}

void f_008722a0(CPU *c) { /* PTR_008722a0 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    c->esp += 4; return; /* ret  */
}

void f_008722b0(CPU *c) { /* PTR_008722b0 */
    PREEMPT_POLL(c);
    c->esp += 8; return; /* ret 4 */
}

void f_008722c0(CPU *c) { /* PTR_008722c0 */
    PREEMPT_POLL(c);
    c->esp += 16; return; /* ret 0xc */
}

void f_008722d0(CPU *c) { /* PTR_008722d0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_008722e0(CPU *c) { /* PTR_008722e0 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    c->esp += 8; return; /* ret 4 */
}

void f_008722f0(CPU *c) { /* PTR_008722f0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 8; return; /* ret 4 */
}

void f_00872300(CPU *c) { /* FUN_10002300 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x14u))); /* mov edx, dword ptr [esi + 0x14] */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x87d14cu)); /* mov dword ptr [esi], 0x1000d14c */
    c->ecx = (uint32_t)(R32((uint32_t)(0x881148u))); /* mov ecx, dword ptr [0x10011148] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x00872318u); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00872328; /* je 0x872328 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00872325u); f_00871030(c); /* call 0x871030 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00872328:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00872330(CPU *c) { /* PTR_00872330 */
    PREEMPT_POLL(c);
    c->esp += 4; return; /* ret  */
}

void f_00872340(CPU *c) { /* PTR_00872340 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    c->esp += 4; return; /* ret  */
}

void f_00872350(CPU *c) { /* PTR_00872350 */
    PREEMPT_POLL(c);
    { uint32_t a_ = (uint32_t)(c->ecx + 0xcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ecx + 0xc] */
    c->esp += 4; return; /* ret  */
}

void f_00872360(CPU *c) { /* PTR_00872360 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov eax, dword ptr [ecx + 0xc] */
    c->esp += 4; return; /* ret  */
}

void f_00872370(CPU *c) { /* PTR_00872370 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx + 0xcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ecx + 0xc], 0 */
    c->esp += 4; return; /* ret  */
}

void f_00872380(CPU *c) { /* PTR_00872380 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x4u))); /* mov al, byte ptr [esp + 4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x87d108u)); /* mov dword ptr [esi], 0x1000d108 */
    if (c->zf) goto L_0087239a; /* je 0x87239a */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00872397u); f_00871030(c); /* call 0x871030 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_0087239a:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_008723a0(CPU *c) { /* FUN_100023a0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x3f0u)); /* lea eax, [esi + 0x3f0] */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x87d190u)); /* mov dword ptr [esi], 0x1000d190 */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    W32((uint32_t)(c->edx), (uint32_t)(c->ecx)); /* mov dword ptr [edx], ecx */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [edx + 4], ecx */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 8], edx */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->edx)); /* mov dword ptr [eax + 0xc], edx */
    W32((uint32_t)(c->eax + 0x10u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 0x10], edx */
    W32((uint32_t)(c->eax + 0x14u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 0x14], edx */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x430u)); /* lea eax, [esi + 0x430] */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0xc], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
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
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x480u)); /* lea eax, [esi + 0x480] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->edi), (uint32_t)(c->ecx)); /* mov dword ptr [edi], ecx */
    W32((uint32_t)(c->edi + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [edi + 4], ecx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 8], edx */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->edx)); /* mov dword ptr [eax + 0xc], edx */
    W32((uint32_t)(c->eax + 0x10u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 0x10], edx */
    W32((uint32_t)(c->eax + 0x14u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 0x14], edx */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x87d170u)); /* mov dword ptr [esi], 0x1000d170 */
    W32((uint32_t)(c->esi + 0x314u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x314], edx */
    W32((uint32_t)(c->esi + 0x318u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x318], edx */
    c->eax = (uint32_t)(R32((uint32_t)(0x881164u))); /* mov eax, dword ptr [0x10011164] */
    W32((uint32_t)(c->esi + 0x40cu), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x40c], edx */
    W32((uint32_t)(c->esi + 0x308u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x308], eax */
    W32((uint32_t)(c->esi + 0x410u), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [esi + 0x410], 0xffffffff */
    W8((uint32_t)(c->esi + 0x304u), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi + 0x304], dl */
    W32((uint32_t)(c->esi + 0x478u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x478], edx */
    W32((uint32_t)(c->esi + 0x47cu), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x47c], edx */
    W8((uint32_t)(c->esi + 0x474u), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi + 0x474], dl */
    W8((uint32_t)(c->esi + 0x476u), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi + 0x476], dl */
    W32((uint32_t)(c->esi + 0x30cu), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x30c], edx */
    W32((uint32_t)(c->esi + 0x340u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x340], edx */
    W32((uint32_t)(c->esi + 0x33cu), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x33c], edx */
    W32((uint32_t)(c->esi + 0x344u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x344], edx */
    W32((uint32_t)(c->esi + 0x348u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x348], edx */
    W32((uint32_t)(c->esi + 0x36cu), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x36c], edx */
    W32((uint32_t)(c->esi + 0x368u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x368], edx */
    W32((uint32_t)(c->esi + 0x364u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x364], edx */
    W32((uint32_t)(c->esi + 0x354u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x354], edx */
    W32((uint32_t)(c->esi + 0x350u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x350], edx */
    W32((uint32_t)(c->esi + 0x34cu), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x34c], edx */
    W32((uint32_t)(c->esi + 0x378u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x378], edx */
    W32((uint32_t)(c->esi + 0x374u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x374], edx */
    W32((uint32_t)(c->esi + 0x370u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x370], edx */
    W32((uint32_t)(c->esi + 0x37cu), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x37c], edx */
    W8((uint32_t)(c->esi + 0x472u), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi + 0x472], dl */
    W8((uint32_t)(c->esi + 0x473u), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi + 0x473], dl */
    W8((uint32_t)(c->esi + 0x475u), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi + 0x475], dl */
    W8((uint32_t)(c->esi + 0x471u), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi + 0x471], dl */
    W8((uint32_t)(c->esi + 0x470u), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi + 0x470], dl */
    W32((uint32_t)(c->esi + 0x3bcu), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x3bc], edx */
    W32((uint32_t)(c->esi + 0x4bcu), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x4bc], edx */
    W32((uint32_t)(c->esi + 0x4c0u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x4c0], edx */
    W32((uint32_t)(c->esi + 0x3c0u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x3c0], edx */
    W32((uint32_t)(c->esi + 0x3ccu), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x3cc], edx */
    W32((uint32_t)(c->esi + 0x3c4u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x3c4], edx */
    W32((uint32_t)(c->esi + 0x3d0u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x3d0], edx */
    W32((uint32_t)(c->esi + 0x384u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x384], edx */
    W32((uint32_t)(c->esi + 0x388u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x388], edx */
    W32((uint32_t)(c->esi + 0x38cu), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x38c], edx */
    W32((uint32_t)(c->esi + 0x390u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x390], edx */
    W32((uint32_t)(c->esi + 0x394u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x394], edx */
    W32((uint32_t)(c->esi + 0x3d4u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x3d4], edx */
    W32((uint32_t)(c->esi + 0x3d8u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x3d8], edx */
    W8((uint32_t)(c->esi + 0x3dcu), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi + 0x3dc], dl */
    W8((uint32_t)(c->esi + 0x3ecu), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi + 0x3ec], dl */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00872560(CPU *c) { /* FUN_10002560 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00872568u); f_00872580(c); /* call 0x872580 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00872578; /* je 0x872578 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00872575u); f_00871030(c); /* call 0x871030 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00872578:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00872580(CPU *c) { /* FUN_10002580 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x87c2e8u; PUSH32(c, v_); } /* push 0x1000c2e8 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 8], esi */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x87d170u)); /* mov dword ptr [esi], 0x1000d170 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x348u))); /* mov eax, dword ptr [esi + 0x348] */
    c->ebp = (uint32_t)(logic32(c, 0)); /* xor ebp, ebp */
    (void)sub32(c, c->eax, c->ebp); /* cmp eax, ebp */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0x14], ebp */
    if (c->zf) goto L_008725ba; /* je 0x8725ba */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x8u)); PUSH32(c, 0x008725bau); call_indirect(c, t_); } /* call dword ptr [ecx + 8] */
L_008725ba:;
    (void)sub32(c, R32((uint32_t)(c->esi + 0x30cu)), c->ebp); /* cmp dword ptr [esi + 0x30c], ebp */
    if (c->zf) goto L_00872607; /* je 0x872607 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x33cu))); /* mov eax, dword ptr [esi + 0x33c] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, c->eax, c->ebp); /* cmp eax, ebp */
    if ((c->zf || c->sf != c->of)) goto L_008725f6; /* jle 0x8725f6 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)((uint32_t)(c->esi + 0x31cu)); /* lea ebx, [esi + 0x31c] */
L_008725d6:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x30cu))); /* mov ecx, dword ptr [esi + 0x30c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x80u)); PUSH32(c, 0x008725e7u); call_indirect(c, t_); } /* call dword ptr [edx + 0x80] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x33cu))); /* mov eax, dword ptr [esi + 0x33c] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x4u)); /* add ebx, 4 */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if ((c->sf != c->of)) goto L_008725d6; /* jl 0x8725d6 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
L_008725f6:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x308u))); /* mov ecx, dword ptr [esi + 0x308] */
    { uint32_t v_ = 0x87e07cu; PUSH32(c, v_); } /* push 0x1000e07c */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x50u)); PUSH32(c, 0x00872606u); call_indirect(c, t_); } /* call dword ptr [edx + 0x50] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_00872607:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov eax, dword ptr [esi + 0x344] */
    (void)sub32(c, c->eax, c->ebp); /* cmp eax, ebp */
    if (c->zf) goto L_0087261a; /* je 0x87261a */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00872617u); f_00871030(c); /* call 0x871030 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_0087261a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x3d4u))); /* mov eax, dword ptr [esi + 0x3d4] */
    W32((uint32_t)(c->esi + 0x344u), (uint32_t)(c->ebp)); /* mov dword ptr [esi + 0x344], ebp */
    (void)sub32(c, c->eax, c->ebp); /* cmp eax, ebp */
    if (c->zf) goto L_00872633; /* je 0x872633 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00872630u); f_00871030(c); /* call 0x871030 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00872633:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x40cu))); /* mov eax, dword ptr [esi + 0x40c] */
    W32((uint32_t)(c->esi + 0x3d4u), (uint32_t)(c->ebp)); /* mov dword ptr [esi + 0x3d4], ebp */
    (void)sub32(c, c->eax, c->ebp); /* cmp eax, ebp */
    if (c->zf) goto L_0087264c; /* je 0x87264c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00872649u); f_00871030(c); /* call 0x871030 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_0087264c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x314u))); /* mov eax, dword ptr [esi + 0x314] */
    W32((uint32_t)(c->esi + 0x40cu), (uint32_t)(c->ebp)); /* mov dword ptr [esi + 0x40c], ebp */
    (void)sub32(c, c->eax, c->ebp); /* cmp eax, ebp */
    if (c->zf) goto L_00872692; /* je 0x872692 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x318u))); /* mov eax, dword ptr [esi + 0x318] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub32(c, c->eax, c->ebp); /* cmp eax, ebp */
    if ((c->zf || c->sf != c->of)) goto L_00872683; /* jle 0x872683 */
L_00872668:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x314u))); /* mov eax, dword ptr [esi + 0x314] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->ecx * 4))); /* mov eax, dword ptr [eax + ecx*4] */
    (void)sub32(c, c->eax, c->ebp); /* cmp eax, ebp */
    if (c->zf) goto L_00872678; /* je 0x872678 */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ebp)); /* mov dword ptr [eax + 4], ebp */
L_00872678:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x318u))); /* mov eax, dword ptr [esi + 0x318] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
    if ((c->sf != c->of)) goto L_00872668; /* jl 0x872668 */
L_00872683:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x314u))); /* mov ecx, dword ptr [esi + 0x314] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x0087268fu); f_00871030(c); /* call 0x871030 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00872692:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x87d190u)); /* mov dword ptr [esi], 0x1000d190 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_008726b0(CPU *c) { /* FUN_100026b0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x47cu))); /* mov eax, dword ptr [ecx + 0x47c] */
    c->esp += 4; return; /* ret  */
}

void f_008726c0(CPU *c) { /* FUN_100026c0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    W32((uint32_t)(c->ecx + 0x478u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 0x478], eax */
    c->esp += 8; return; /* ret 4 */
}

void f_008726d0(CPU *c) { /* FUN_100026d0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    W32((uint32_t)(c->ecx + 0x47cu), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 0x47c], eax */
    c->esp += 8; return; /* ret 4 */
}

void f_008726e0(CPU *c) { /* FUN_100026e0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0x0u); /* cmp dword ptr [eax], 0 */
    if (!c->zf) goto L_008726f6; /* jne 0x8726f6 */
    W32((uint32_t)(c->eax), (uint32_t)(c->edx)); /* mov dword ptr [eax], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    W32((uint32_t)(c->eax), (uint32_t)(c->edx)); /* mov dword ptr [eax], edx */
    c->esp += 12; return; /* ret 8 */
L_008726f6:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov esi, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    PUSH32(c, 0x00872703u); f_008726d0(c); /* call 0x8726d0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    PUSH32(c, 0x0087270du); f_008726c0(c); /* call 0x8726c0 */
    W32((uint32_t)(c->esi), (uint32_t)(c->edx)); /* mov dword ptr [esi], edx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 12; return; /* ret 8 */
}

void f_00872720(CPU *c) { /* FUN_10002720 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edi, dword ptr [esp + 0xc] */
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    PUSH32(c, 0x0087272fu); f_008726b0(c); /* call 0x8726b0 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    PUSH32(c, 0x00872737u); f_008726d0(c); /* call 0x8726d0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    PUSH32(c, 0x0087273fu); f_008726d0(c); /* call 0x8726d0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00872745u); f_008726c0(c); /* call 0x8726c0 */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00872756; /* je 0x872756 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00872751u); f_008726c0(c); /* call 0x8726c0 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 16; return; /* ret 0xc */
L_00872756:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->eax), (uint32_t)(c->edx)); /* mov dword ptr [eax], edx */
    c->esp += 16; return; /* ret 0xc */
}

void f_00872770(CPU *c) { /* FUN_10002770 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0x478u))); /* mov ecx, dword ptr [edx + 0x478] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00872788; /* je 0x872788 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x47cu))); /* mov eax, dword ptr [edx + 0x47c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00872788u); f_008726d0(c); /* call 0x8726d0 */
L_00872788:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0x47cu))); /* mov ecx, dword ptr [edx + 0x47c] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_0087279e; /* je 0x87279e */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x478u))); /* mov eax, dword ptr [edx + 0x478] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0087279eu); f_008726c0(c); /* call 0x8726c0 */
L_0087279e:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    (void)sub32(c, R32((uint32_t)(c->eax)), c->edx); /* cmp dword ptr [eax], edx */
    if (!c->zf) goto L_008727ae; /* jne 0x8727ae */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0x47cu))); /* mov ecx, dword ptr [edx + 0x47c] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
L_008727ae:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    (void)sub32(c, R32((uint32_t)(c->eax)), c->edx); /* cmp dword ptr [eax], edx */
    if (!c->zf) goto L_008727be; /* jne 0x8727be */
    c->edx = (uint32_t)(R32((uint32_t)(c->edx + 0x478u))); /* mov edx, dword ptr [edx + 0x478] */
    W32((uint32_t)(c->eax), (uint32_t)(c->edx)); /* mov dword ptr [eax], edx */
L_008727be:;
    c->esp += 12; return; /* ret 8 */
}

void f_008727d0(CPU *c) { /* FUN_100027d0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x47cu))); /* mov eax, dword ptr [esi + 0x47c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00872813; /* je 0x872813 */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x360u))); /* fld dword ptr [esi + 0x360] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->eax + 0x360u))); FPOP(c); /* fcomp dword ptr [eax + 0x360] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00872813; /* jp 0x872813 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ebx, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edi, dword ptr [esp + 0x14] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00872801u); f_00872770(c); /* call 0x872770 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x47cu))); /* mov eax, dword ptr [esi + 0x47c] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00872811u); f_00872720(c); /* call 0x872720 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
L_00872813:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 12; return; /* ret 8 */
}

void f_00872820(CPU *c) { /* FUN_10002820 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x87c32cu; PUSH32(c, v_); } /* push 0x1000c32c */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x37cu)); /* sub esp, 0x37c */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x398u))); /* mov ebx, dword ptr [esp + 0x398] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x39cu))); /* mov ecx, dword ptr [esp + 0x39c] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    if ((c->zf || c->sf != c->of)) goto L_0087288e; /* jle 0x87288e */
L_00872859:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x39cu))); /* mov ecx, dword ptr [esp + 0x39c] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ecx + c->eax * 4))); /* mov ebp, dword ptr [ecx + eax*4] */
    (void)logic32(c, (uint32_t)(c->ebp & c->ebp)); /* test ebp, ebp */
    if (c->zf) goto L_00872878; /* je 0x872878 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov edx, dword ptr [ebp] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x6cu)); PUSH32(c, 0x00872870u); call_indirect(c, t_); } /* call dword ptr [edx + 0x6c] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00872888; /* jne 0x872888 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
L_00872878:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x3a0u))); /* mov ecx, dword ptr [esp + 0x3a0] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    if ((c->sf != c->of)) goto L_00872859; /* jl 0x872859 */
L_00872888:;
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, c->ebp, c->edi); /* cmp ebp, edi */
    if (!c->zf) goto L_008728aa; /* jne 0x8728aa */
L_0087288e:;
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0x308u))); /* mov esi, dword ptr [esi + 0x308] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x87e3c4u; PUSH32(c, v_); } /* push 0x1000e3c4 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x30u)); PUSH32(c, 0x008728a0u); call_indirect(c, t_); } /* call dword ptr [eax + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    goto L_00873495; /* jmp 0x873495 */
L_008728aa:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x308u))); /* mov ecx, dword ptr [esi + 0x308] */
    { uint32_t v_ = 0x87e07cu; PUSH32(c, v_); } /* push 0x1000e07c */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x4cu)); PUSH32(c, 0x008728bau); call_indirect(c, t_); } /* call dword ptr [edx + 0x4c] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    W32((uint32_t)(c->esi + 0x30cu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x30c], eax */
    if (!c->zf) goto L_00872953; /* jne 0x872953 */
    c->ecx = (uint32_t)(R32((uint32_t)(0x881148u))); /* mov ecx, dword ptr [0x10011148] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x18u)); PUSH32(c, 0x008728d3u); call_indirect(c, t_); } /* call dword ptr [eax + 0x18] */
    c->eax = (uint32_t)(R32((uint32_t)(0x881148u))); /* mov eax, dword ptr [0x10011148] */
    { uint32_t v_ = 0x87e100u; PUSH32(c, v_); } /* push 0x1000e100 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x008728e3u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(0x881148u))); /* mov eax, dword ptr [0x10011148] */
    { uint32_t v_ = 0xa5u; PUSH32(c, v_); } /* push 0xa5 */
    { uint32_t v_ = 0x87e390u; PUSH32(c, v_); } /* push 0x1000e390 */
    { uint32_t v_ = 0x87e0f4u; PUSH32(c, v_); } /* push 0x1000e0f4 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x008728fdu); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(0x881148u))); /* mov eax, dword ptr [0x10011148] */
    { uint32_t v_ = 0x87e0dcu; PUSH32(c, v_); } /* push 0x1000e0dc */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x0087290du); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    W32((uint32_t)(c->esp + 0x15cu), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x15c], edi */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00872919:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x87e0dcu))); /* mov cl, byte ptr [eax + 0x1000e0dc] */
    W8((uint32_t)(c->esp + c->eax + 0x38u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esp + eax + 0x38], cl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_00872919; /* jne 0x872919 */
    W32((uint32_t)(c->esp + 0x394u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x394], edi */
    c->ecx = (uint32_t)((uint32_t)0x4au); /* mov ecx, 0x4a */
    c->esi = (uint32_t)((uint32_t)(c->esp + 0x38u)); /* lea esi, [esp + 0x38] */
    c->edi = (uint32_t)((uint32_t)(c->esp + 0x160u)); /* lea edi, [esp + 0x160] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x160u)); /* lea edx, [esp + 0x160] */
    { uint32_t v_ = 0x87d920u; PUSH32(c, v_); } /* push 0x1000d920 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00872953u); f_008756fa(c); /* call 0x8756fa */
L_00872953:;
    c->ecx = (uint32_t)(R32((uint32_t)(0x881164u))); /* mov ecx, dword ptr [0x10011164] */
    { uint32_t v_ = 0x87e384u; PUSH32(c, v_); } /* push 0x1000e384 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4cu)); PUSH32(c, 0x00872963u); call_indirect(c, t_); } /* call dword ptr [eax + 0x4c] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    W32((uint32_t)(c->esi + 0x310u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x310], eax */
    W32((uint32_t)(c->esi + 0x33cu), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0x33c], edi */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x14], ecx */
L_00872975:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov edx, dword ptr [ebp] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x288u)); /* lea eax, [esp + 0x288] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    if (!c->zf) goto L_0087299b; /* jne 0x87299b */
    { uint32_t v_ = 0x88116cu; PUSH32(c, v_); } /* push 0x1001116c */
    { uint32_t v_ = 0x104u; PUSH32(c, v_); } /* push 0x104 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x87e37cu; PUSH32(c, v_); } /* push 0x1000e37c */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00872999u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    goto L_008729aa; /* jmp 0x8729aa */
L_0087299b:;
    { uint32_t v_ = 0x104u; PUSH32(c, v_); } /* push 0x104 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x87e37cu; PUSH32(c, v_); } /* push 0x1000e37c */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x1cu)); PUSH32(c, 0x008729aau); call_indirect(c, t_); } /* call dword ptr [edx + 0x1c] */
L_008729aa:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_008729e0; /* je 0x8729e0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x30cu))); /* mov ecx, dword ptr [esi + 0x30c] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x288u)); /* lea eax, [esp + 0x288] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x78u)); PUSH32(c, 0x008729c1u); call_indirect(c, t_); } /* call dword ptr [edx + 0x78] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ecx, dword ptr [esp + 0x14] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esi + c->ecx * 4 + 0x31cu), (uint32_t)(c->eax)); /* mov dword ptr [esi + ecx*4 + 0x31c], eax */
    if ((c->sf != c->of)) goto L_008729d6; /* jl 0x8729d6 */
    { uint32_t a_ = (uint32_t)(c->esi + 0x33cu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [esi + 0x33c] */
L_008729d6:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x14], ecx */
    if ((c->sf != c->of)) goto L_00872975; /* jl 0x872975 */
L_008729e0:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov edx, dword ptr [ebp] */
    { uint32_t v_ = 0x88116cu; PUSH32(c, v_); } /* push 0x1001116c */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x28cu)); /* lea eax, [esp + 0x28c] */
    { uint32_t v_ = 0x104u; PUSH32(c, v_); } /* push 0x104 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x87e370u; PUSH32(c, v_); } /* push 0x1000e370 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00872a00u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00872aab; /* jne 0x872aab */
    c->eax = (uint32_t)(R32((uint32_t)(0x881164u))); /* mov eax, dword ptr [0x10011164] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x87e35cu; PUSH32(c, v_); } /* push 0x1000e35c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x00872a19u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x881148u))); /* mov ecx, dword ptr [0x10011148] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x18u)); PUSH32(c, 0x00872a27u); call_indirect(c, t_); } /* call dword ptr [edx + 0x18] */
    c->eax = (uint32_t)(R32((uint32_t)(0x881148u))); /* mov eax, dword ptr [0x10011148] */
    { uint32_t v_ = 0x87e100u; PUSH32(c, v_); } /* push 0x1000e100 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00872a37u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(0x881148u))); /* mov eax, dword ptr [0x10011148] */
    { uint32_t v_ = 0xbfu; PUSH32(c, v_); } /* push 0xbf */
    { uint32_t v_ = 0x87e390u; PUSH32(c, v_); } /* push 0x1000e390 */
    { uint32_t v_ = 0x87e0f4u; PUSH32(c, v_); } /* push 0x1000e0f4 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00872a51u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(0x881148u))); /* mov eax, dword ptr [0x10011148] */
    { uint32_t v_ = 0x87e338u; PUSH32(c, v_); } /* push 0x1000e338 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00872a61u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W32((uint32_t)(c->esp + 0x15cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x15c], eax */
L_00872a6d:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x87e338u))); /* mov cl, byte ptr [eax + 0x1000e338] */
    W8((uint32_t)(c->esp + c->eax + 0x38u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esp + eax + 0x38], cl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_00872a6d; /* jne 0x872a6d */
    c->ecx = (uint32_t)((uint32_t)0x4au); /* mov ecx, 0x4a */
    c->esi = (uint32_t)((uint32_t)(c->esp + 0x38u)); /* lea esi, [esp + 0x38] */
    c->edi = (uint32_t)((uint32_t)(c->esp + 0x160u)); /* lea edi, [esp + 0x160] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x160u)); /* lea edx, [esp + 0x160] */
    { uint32_t v_ = 0x87d920u; PUSH32(c, v_); } /* push 0x1000d920 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    W32((uint32_t)(c->esp + 0x39cu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [esp + 0x39c], 1 */
    PUSH32(c, 0x00872aabu); f_008756fa(c); /* call 0x8756fa */
L_00872aab:;
    c->edi = (uint32_t)((uint32_t)(c->esp + 0x288u)); /* lea edi, [esp + 0x288] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0xffffffffu))); /* or ecx, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = 0xc1u; PUSH32(c, v_); } /* push 0xc1 */
    while (c->ecx) { (void)sub8(c, ((uint8_t)c->eax), R8(c->edi)); c->edi += (c->df ? -1 : 1); c->ecx--; if (c->zf) break; } /* repne scasb al, byte ptr es:[edi] */
    c->ecx = (uint32_t)((uint32_t)~c->ecx); /* not ecx */
    { uint32_t v_ = 0x87e390u; PUSH32(c, v_); } /* push 0x1000e390 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00872acbu); f_00871050(c); /* call 0x871050 */
    W32((uint32_t)(c->esi + 0x40cu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x40c], eax */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x294u)); /* lea eax, [esp + 0x294] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x288u)); /* lea ecx, [esp + 0x288] */
    c->edx = (uint32_t)(sub32(c, c->edx, c->eax)); /* sub edx, eax */
L_00872ae6:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov al, byte ptr [ecx] */
    W8((uint32_t)(c->edx + c->ecx), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edx + ecx], al */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00872ae6; /* jne 0x872ae6 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov edx, dword ptr [ebp] */
    { uint32_t v_ = 0x20u; PUSH32(c, v_); } /* push 0x20 */
    { uint32_t v_ = 0x87e328u; PUSH32(c, v_); } /* push 0x1000e328 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x20u)); PUSH32(c, 0x00872b00u); call_indirect(c, t_); } /* call dword ptr [edx + 0x20] */
    W32((uint32_t)(c->esi + 0x340u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x340], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov eax, dword ptr [ebp] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x87e318u; PUSH32(c, v_); } /* push 0x1000e318 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x38u)); PUSH32(c, 0x00872b16u); call_indirect(c, t_); } /* call dword ptr [eax + 0x38] */
    WF32((uint32_t)(c->esi + 0x3c8u), (float)ST(0)); /* fst dword ptr [esi + 0x3c8] */
    PUSH32(c, 0x00872b21u); f_008757b8(c); /* call 0x8757b8 */
    W32((uint32_t)(c->esi + 0x3ccu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x3cc], eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov edx, dword ptr [ebp] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x87e304u; PUSH32(c, v_); } /* push 0x1000e304 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x38u)); PUSH32(c, 0x00872b37u); call_indirect(c, t_); } /* call dword ptr [edx + 0x38] */
    WF32((uint32_t)(c->esi + 0x3e4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x3e4] */
    PUSH32(c, 0x00872b42u); f_00875794(c); /* call 0x875794 */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x18], eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x1cu))); /* fild dword ptr [esp + 0x1c] */
    { uint32_t v_ = 0x87e2f4u; PUSH32(c, v_); } /* push 0x1000e2f4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x3e4u))); /* fmul dword ptr [esi + 0x3e4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x87d1ccu))); /* fmul dword ptr [0x1000d1cc] */
    WF32((uint32_t)(c->esi + 0x3e8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x3e8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov eax, dword ptr [ebp] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x38u)); PUSH32(c, 0x00872b6cu); call_indirect(c, t_); } /* call dword ptr [eax + 0x38] */
    WF32((uint32_t)(c->esi + 0x408u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x408] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov edx, dword ptr [ebp] */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x87e2ecu; PUSH32(c, v_); } /* push 0x1000e2ec */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x20u)); PUSH32(c, 0x00872b82u); call_indirect(c, t_); } /* call dword ptr [edx + 0x20] */
    W32((uint32_t)(c->esi + 0x410u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x410], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov eax, dword ptr [ebp] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x87e2e0u; PUSH32(c, v_); } /* push 0x1000e2e0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x38u)); PUSH32(c, 0x00872b98u); call_indirect(c, t_); } /* call dword ptr [eax + 0x38] */
    WF32((uint32_t)(c->esi + 0x394u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x394] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov edx, dword ptr [ebp] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x87e2d4u; PUSH32(c, v_); } /* push 0x1000e2d4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x38u)); PUSH32(c, 0x00872baeu); call_indirect(c, t_); } /* call dword ptr [edx + 0x38] */
    WF32((uint32_t)(c->esi + 0x37cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x37c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov eax, dword ptr [ebp] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x87e2ccu; PUSH32(c, v_); } /* push 0x1000e2cc */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x38u)); PUSH32(c, 0x00872bc4u); call_indirect(c, t_); } /* call dword ptr [eax + 0x38] */
    WF32((uint32_t)(c->esi + 0x398u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x398] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov edx, dword ptr [ebp] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x87e2c4u; PUSH32(c, v_); } /* push 0x1000e2c4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x38u)); PUSH32(c, 0x00872bdau); call_indirect(c, t_); } /* call dword ptr [edx + 0x38] */
    WF32((uint32_t)(c->esi + 0x39cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x39c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov eax, dword ptr [ebp] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x87e2b4u; PUSH32(c, v_); } /* push 0x1000e2b4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x38u)); PUSH32(c, 0x00872bf0u); call_indirect(c, t_); } /* call dword ptr [eax + 0x38] */
    WF32((uint32_t)(c->esi + 0x3a0u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x3a0] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov edx, dword ptr [ebp] */
    { uint32_t v_ = 0x3e8u; PUSH32(c, v_); } /* push 0x3e8 */
    { uint32_t v_ = 0x87e2a8u; PUSH32(c, v_); } /* push 0x1000e2a8 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x20u)); PUSH32(c, 0x00872c09u); call_indirect(c, t_); } /* call dword ptr [edx + 0x20] */
    W32((uint32_t)(c->esi + 0x3a4u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x3a4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov eax, dword ptr [ebp] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x87e2a0u; PUSH32(c, v_); } /* push 0x1000e2a0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x38u)); PUSH32(c, 0x00872c1fu); call_indirect(c, t_); } /* call dword ptr [eax + 0x38] */
    WF32((uint32_t)(c->esi + 0x3acu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x3ac] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov edx, dword ptr [ebp] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x87e290u; PUSH32(c, v_); } /* push 0x1000e290 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x38u)); PUSH32(c, 0x00872c35u); call_indirect(c, t_); } /* call dword ptr [edx + 0x38] */
    WF32((uint32_t)(c->esi + 0x3b0u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x3b0] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov eax, dword ptr [ebp] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x87e280u; PUSH32(c, v_); } /* push 0x1000e280 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x20u)); PUSH32(c, 0x00872c4bu); call_indirect(c, t_); } /* call dword ptr [eax + 0x20] */
    W32((uint32_t)(c->esi + 0x380u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x380], eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov edx, dword ptr [ebp] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x87e278u; PUSH32(c, v_); } /* push 0x1000e278 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x38u)); PUSH32(c, 0x00872c61u); call_indirect(c, t_); } /* call dword ptr [edx + 0x38] */
    WF32((uint32_t)(c->esi + 0x3b4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x3b4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov eax, dword ptr [ebp] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x87e264u; PUSH32(c, v_); } /* push 0x1000e264 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x38u)); PUSH32(c, 0x00872c77u); call_indirect(c, t_); } /* call dword ptr [eax + 0x38] */
    WF32((uint32_t)(c->esi + 0x3b8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x3b8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov edx, dword ptr [ebp] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x87e258u; PUSH32(c, v_); } /* push 0x1000e258 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x20u)); PUSH32(c, 0x00872c8du); call_indirect(c, t_); } /* call dword ptr [edx + 0x20] */
    W32((uint32_t)(c->esi + 0x3a8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x3a8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov eax, dword ptr [ebp] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x87e24cu; PUSH32(c, v_); } /* push 0x1000e24c */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x38u)); PUSH32(c, 0x00872ca3u); call_indirect(c, t_); } /* call dword ptr [eax + 0x38] */
    WF32((uint32_t)(c->esi + 0x3bcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x3bc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov edx, dword ptr [ebp] */
    { uint32_t v_ = 0x3f800000u; PUSH32(c, v_); } /* push 0x3f800000 */
    { uint32_t v_ = 0x87e238u; PUSH32(c, v_); } /* push 0x1000e238 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x38u)); PUSH32(c, 0x00872cbcu); call_indirect(c, t_); } /* call dword ptr [edx + 0x38] */
    WF32((uint32_t)(c->esi + 0x3e0u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x3e0] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov eax, dword ptr [ebp] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x87e22cu; PUSH32(c, v_); } /* push 0x1000e22c */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x20u)); PUSH32(c, 0x00872cd2u); call_indirect(c, t_); } /* call dword ptr [eax + 0x20] */
    W32((uint32_t)(c->esi + 0x4c4u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x4c4], eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov edx, dword ptr [ebp] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x87e220u; PUSH32(c, v_); } /* push 0x1000e220 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x20u)); PUSH32(c, 0x00872ce8u); call_indirect(c, t_); } /* call dword ptr [edx + 0x20] */
    W32((uint32_t)(c->esi + 0x4c8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x4c8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov eax, dword ptr [ebp] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x87e210u; PUSH32(c, v_); } /* push 0x1000e210 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x20u)); PUSH32(c, 0x00872cfeu); call_indirect(c, t_); } /* call dword ptr [eax + 0x20] */
    W32((uint32_t)(c->esi + 0x4ccu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x4cc], eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov edx, dword ptr [ebp] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x87e200u; PUSH32(c, v_); } /* push 0x1000e200 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x54u)); PUSH32(c, 0x00872d14u); call_indirect(c, t_); } /* call dword ptr [edx + 0x54] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00872d21; /* je 0x872d21 */
    W8((uint32_t)(c->esi + 0x472u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esi + 0x472], 1 */
    goto L_00872d28; /* jmp 0x872d28 */
L_00872d21:;
    W8((uint32_t)(c->esi + 0x472u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esi + 0x472], 0 */
L_00872d28:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov eax, dword ptr [ebp] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x87e1f4u; PUSH32(c, v_); } /* push 0x1000e1f4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x54u)); PUSH32(c, 0x00872d38u); call_indirect(c, t_); } /* call dword ptr [eax + 0x54] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00872d45; /* je 0x872d45 */
    W8((uint32_t)(c->esi + 0x473u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esi + 0x473], 1 */
    goto L_00872d4c; /* jmp 0x872d4c */
L_00872d45:;
    W8((uint32_t)(c->esi + 0x473u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esi + 0x473], 0 */
L_00872d4c:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov edx, dword ptr [ebp] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x87e1e4u; PUSH32(c, v_); } /* push 0x1000e1e4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x54u)); PUSH32(c, 0x00872d5cu); call_indirect(c, t_); } /* call dword ptr [edx + 0x54] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00872d69; /* je 0x872d69 */
    W8((uint32_t)(c->esi + 0x475u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esi + 0x475], 1 */
    goto L_00872d70; /* jmp 0x872d70 */
L_00872d69:;
    W8((uint32_t)(c->esi + 0x475u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esi + 0x475], 0 */
L_00872d70:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov eax, dword ptr [ebp] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x87e1d8u; PUSH32(c, v_); } /* push 0x1000e1d8 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x54u)); PUSH32(c, 0x00872d80u); call_indirect(c, t_); } /* call dword ptr [eax + 0x54] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00872d8d; /* je 0x872d8d */
    W8((uint32_t)(c->esi + 0x471u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esi + 0x471], 1 */
    goto L_00872d94; /* jmp 0x872d94 */
L_00872d8d:;
    W8((uint32_t)(c->esi + 0x471u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esi + 0x471], 0 */
L_00872d94:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov edx, dword ptr [ebp] */
    { uint32_t v_ = 0x38d1b717u; PUSH32(c, v_); } /* push 0x38d1b717 */
    { uint32_t v_ = 0x87e1ccu; PUSH32(c, v_); } /* push 0x1000e1cc */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x38u)); PUSH32(c, 0x00872da7u); call_indirect(c, t_); } /* call dword ptr [edx + 0x38] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x340u))); /* mov eax, dword ptr [esi + 0x340] */
    { uint32_t v_ = 0xf5u; PUSH32(c, v_); } /* push 0xf5 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t v_ = 0x87e390u; PUSH32(c, v_); } /* push 0x1000e390 */
    WF32((uint32_t)(c->esp + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x24] */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 5)); /* shl ecx, 5 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 2)); /* shl ecx, 2 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00872dcbu); f_00871050(c); /* call 0x871050 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    W32((uint32_t)(c->esi + 0x344u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0x344], edi */
    if (!c->zf) goto L_00872e6d; /* jne 0x872e6d */
    c->ecx = (uint32_t)(R32((uint32_t)(0x881148u))); /* mov ecx, dword ptr [0x10011148] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x18u)); PUSH32(c, 0x00872de9u); call_indirect(c, t_); } /* call dword ptr [edx + 0x18] */
    c->eax = (uint32_t)(R32((uint32_t)(0x881148u))); /* mov eax, dword ptr [0x10011148] */
    { uint32_t v_ = 0x87e100u; PUSH32(c, v_); } /* push 0x1000e100 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00872df9u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(0x881148u))); /* mov eax, dword ptr [0x10011148] */
    { uint32_t v_ = 0xf6u; PUSH32(c, v_); } /* push 0xf6 */
    { uint32_t v_ = 0x87e390u; PUSH32(c, v_); } /* push 0x1000e390 */
    { uint32_t v_ = 0x87e0f4u; PUSH32(c, v_); } /* push 0x1000e0f4 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00872e13u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(0x881148u))); /* mov eax, dword ptr [0x10011148] */
    { uint32_t v_ = 0x87e14cu; PUSH32(c, v_); } /* push 0x1000e14c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00872e23u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W32((uint32_t)(c->esp + 0x15cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x15c], eax */
L_00872e2f:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x87e14cu))); /* mov cl, byte ptr [eax + 0x1000e14c] */
    W8((uint32_t)(c->esp + c->eax + 0x38u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esp + eax + 0x38], cl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_00872e2f; /* jne 0x872e2f */
    c->ecx = (uint32_t)((uint32_t)0x4au); /* mov ecx, 0x4a */
    c->esi = (uint32_t)((uint32_t)(c->esp + 0x38u)); /* lea esi, [esp + 0x38] */
    c->edi = (uint32_t)((uint32_t)(c->esp + 0x160u)); /* lea edi, [esp + 0x160] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x160u)); /* lea edx, [esp + 0x160] */
    { uint32_t v_ = 0x87d920u; PUSH32(c, v_); } /* push 0x1000d920 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    W32((uint32_t)(c->esp + 0x39cu), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [esp + 0x39c], 2 */
    PUSH32(c, 0x00872e6du); f_008756fa(c); /* call 0x8756fa */
L_00872e6d:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x340u))); /* mov eax, dword ptr [esi + 0x340] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 5)); /* shl ecx, 5 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 2)); /* shl ecx, 2 */
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u))); /* and ecx, 3 */
    while (c->ecx) { W8(c->edi, (uint8_t)((uint8_t)c->eax)); c->edi += (c->df ? -1 : 1); c->ecx--; } /* rep stosb byte ptr es:[edi], al */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x340u))); /* mov ecx, dword ptr [esi + 0x340] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    if ((c->zf || c->sf != c->of)) goto L_00873333; /* jle 0x873333 */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    goto L_00872ea7; /* jmp 0x872ea7 */
L_00872ea5:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00872ea7:;
    (void)sub32(c, R32((uint32_t)(c->esi + 0x4ccu)), c->eax); /* cmp dword ptr [esi + 0x4cc], eax */
    if (c->zf) goto L_00872ec5; /* je 0x872ec5 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov ecx, dword ptr [esi + 0x344] */
    W32((uint32_t)(c->edi + c->ecx + 0x74u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx + 0x74], eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov edx, dword ptr [esi + 0x344] */
    W32((uint32_t)(c->edi + c->edx + 0x78u), (uint32_t)(c->eax)); /* mov dword ptr [edi + edx + 0x78], eax */
    goto L_00872f15; /* jmp 0x872f15 */
L_00872ec5:;
    PUSH32(c, 0x00872ecau); f_00875794(c); /* call 0x875794 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)((uint32_t)0x20005u); /* mov eax, 0x20005 */
    { int64_t r_ = (int64_t)(int32_t)c->ecx * (int32_t)R32((uint32_t)(c->esi + 0x4c4u)); c->ecx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul ecx, dword ptr [esi + 0x4c4] */
    { uint64_t r_ = (uint64_t)c->eax * c->ecx; c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = c->edx != 0; } /* mul ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov eax, dword ptr [esi + 0x344] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->edx)); /* sub ecx, edx */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 1)); /* shr ecx, 1 */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->edx)); /* add ecx, edx */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 14)); /* shr ecx, 0xe */
    W32((uint32_t)(c->edi + c->eax + 0x74u), (uint32_t)(c->ecx)); /* mov dword ptr [edi + eax + 0x74], ecx */
    PUSH32(c, 0x00872ef2u); f_00875794(c); /* call 0x875794 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)((uint32_t)0x20005u); /* mov eax, 0x20005 */
    { int64_t r_ = (int64_t)(int32_t)c->ecx * (int32_t)R32((uint32_t)(c->esi + 0x4c8u)); c->ecx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul ecx, dword ptr [esi + 0x4c8] */
    { uint64_t r_ = (uint64_t)c->eax * c->ecx; c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = c->edx != 0; } /* mul ecx */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->edx)); /* sub ecx, edx */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 1)); /* shr ecx, 1 */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->edx)); /* add ecx, edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov edx, dword ptr [esi + 0x344] */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 14)); /* shr ecx, 0xe */
    W32((uint32_t)(c->edi + c->edx + 0x78u), (uint32_t)(c->ecx)); /* mov dword ptr [edi + edx + 0x78], ecx */
L_00872f15:;
    PUSH32(c, 0x00872f1au); f_00875794(c); /* call 0x875794 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov eax, dword ptr [esi + 0x344] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x10u))); /* fild dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x87d1ccu))); /* fmul dword ptr [0x1000d1cc] */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(0x87d1c8u)) - ST(0)); /* fsubr dword ptr [0x1000d1c8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x3bcu))); /* fmul dword ptr [esi + 0x3bc] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x364u))); /* fadd dword ptr [esi + 0x364] */
    WF32((uint32_t)(c->edi + c->eax), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + eax] */
    PUSH32(c, 0x00872f48u); f_00875794(c); /* call 0x875794 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov ecx, dword ptr [esi + 0x344] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x10u))); /* fild dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x87d1ccu))); /* fmul dword ptr [0x1000d1cc] */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(0x87d1c8u)) - ST(0)); /* fsubr dword ptr [0x1000d1c8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x3bcu))); /* fmul dword ptr [esi + 0x3bc] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x368u))); /* fadd dword ptr [esi + 0x368] */
    WF32((uint32_t)(c->edi + c->ecx + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + ecx + 4] */
    PUSH32(c, 0x00872f77u); f_00875794(c); /* call 0x875794 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov edx, dword ptr [esi + 0x344] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x10u))); /* fild dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x87d1ccu))); /* fmul dword ptr [0x1000d1cc] */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(0x87d1c8u)) - ST(0)); /* fsubr dword ptr [0x1000d1c8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x3bcu))); /* fmul dword ptr [esi + 0x3bc] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x36cu))); /* fadd dword ptr [esi + 0x36c] */
    WF32((uint32_t)(c->edi + c->edx + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + edx + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov eax, dword ptr [esi + 0x344] */
    W32((uint32_t)(c->edi + c->eax + 0x3cu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [edi + eax + 0x3c], 0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov ecx, dword ptr [esi + 0x344] */
    W32((uint32_t)(c->edi + c->ecx + 0x68u), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [edi + ecx + 0x68], 0xffffffff */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov edx, dword ptr [esi + 0x344] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x410u))); /* mov eax, dword ptr [esi + 0x410] */
    W32((uint32_t)(c->edi + c->edx + 0x68u), (uint32_t)(c->eax)); /* mov dword ptr [edi + edx + 0x68], eax */
    PUSH32(c, 0x00872fd2u); f_00875794(c); /* call 0x875794 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov ecx, dword ptr [esi + 0x344] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x10u))); /* fild dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x87d1ccu))); /* fmul dword ptr [0x1000d1cc] */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(0x87d1c8u)) - ST(0)); /* fsubr dword ptr [0x1000d1c8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x3b8u))); /* fmul dword ptr [esi + 0x3b8] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x3b4u))); /* fadd dword ptr [esi + 0x3b4] */
    WF32((uint32_t)(c->edi + c->ecx + 0x40u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + ecx + 0x40] */
    PUSH32(c, 0x00873001u); f_00875794(c); /* call 0x875794 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov edx, dword ptr [esi + 0x344] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x10u))); /* fild dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x87d1ccu))); /* fmul dword ptr [0x1000d1cc] */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(0x87d1c8u)) - ST(0)); /* fsubr dword ptr [0x1000d1c8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x3a0u))); /* fmul dword ptr [esi + 0x3a0] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x39cu))); /* fadd dword ptr [esi + 0x39c] */
    WF32((uint32_t)(c->edi + c->edx + 0x5cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + edx + 0x5c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov eax, dword ptr [esi + 0x344] */
    W32((uint32_t)(c->edi + c->eax + 0x54u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [edi + eax + 0x54], 0 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x475u))); /* mov al, byte ptr [esi + 0x475] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_008730a7; /* je 0x8730a7 */
    PUSH32(c, 0x00873048u); f_00875794(c); /* call 0x875794 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov ecx, dword ptr [esi + 0x344] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x10u))); /* fild dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x87d1ccu))); /* fmul dword ptr [0x1000d1cc] */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(0x87d1c8u)) - ST(0)); /* fsubr dword ptr [0x1000d1c8] */
    WF32((uint32_t)(c->edi + c->ecx + 0xcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + ecx + 0xc] */
    PUSH32(c, 0x0087306bu); f_00875794(c); /* call 0x875794 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov edx, dword ptr [esi + 0x344] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x10u))); /* fild dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x87d1ccu))); /* fmul dword ptr [0x1000d1cc] */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(0x87d1c8u)) - ST(0)); /* fsubr dword ptr [0x1000d1c8] */
    WF32((uint32_t)(c->edi + c->edx + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + edx + 0x10] */
    PUSH32(c, 0x0087308eu); f_00875794(c); /* call 0x875794 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x10u))); /* fild dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x87d1ccu))); /* fmul dword ptr [0x1000d1cc] */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(0x87d1c8u)) - ST(0)); /* fsubr dword ptr [0x1000d1c8] */
    goto L_0087312a; /* jmp 0x87312a */
L_008730a7:;
    PUSH32(c, 0x008730acu); f_00875794(c); /* call 0x875794 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov ecx, dword ptr [esi + 0x344] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x10u))); /* fild dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x87d1ccu))); /* fmul dword ptr [0x1000d1cc] */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(0x87d1c8u)) - ST(0)); /* fsubr dword ptr [0x1000d1c8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x37cu))); /* fmul dword ptr [esi + 0x37c] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x370u))); /* fadd dword ptr [esi + 0x370] */
    WF32((uint32_t)(c->edi + c->ecx + 0xcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + ecx + 0xc] */
    PUSH32(c, 0x008730dbu); f_00875794(c); /* call 0x875794 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov edx, dword ptr [esi + 0x344] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x10u))); /* fild dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x87d1ccu))); /* fmul dword ptr [0x1000d1cc] */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(0x87d1c8u)) - ST(0)); /* fsubr dword ptr [0x1000d1c8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x37cu))); /* fmul dword ptr [esi + 0x37c] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x374u))); /* fadd dword ptr [esi + 0x374] */
    WF32((uint32_t)(c->edi + c->edx + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + edx + 0x10] */
    PUSH32(c, 0x0087310au); f_00875794(c); /* call 0x875794 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x10u))); /* fild dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x87d1ccu))); /* fmul dword ptr [0x1000d1cc] */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(0x87d1c8u)) - ST(0)); /* fsubr dword ptr [0x1000d1c8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x37cu))); /* fmul dword ptr [esi + 0x37c] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x378u))); /* fadd dword ptr [esi + 0x378] */
L_0087312a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov eax, dword ptr [esi + 0x344] */
    WF32((uint32_t)(c->edi + c->eax + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + eax + 0x14] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov ecx, dword ptr [esi + 0x344] */
    FPUSH(c, (double)RF32((uint32_t)(c->edi + c->ecx + 0x14u))); /* fld dword ptr [edi + ecx + 0x14] */
    FPUSH(c, (double)RF32((uint32_t)(c->edi + c->ecx + 0x10u))); /* fld dword ptr [edi + ecx + 0x10] */
    FPUSH(c, (double)RF32((uint32_t)(c->edi + c->ecx + 0xcu))); /* fld dword ptr [edi + ecx + 0xc] */
    c->ecx = (uint32_t)((uint32_t)(c->edi + c->ecx + 0xcu)); /* lea ecx, [edi + ecx + 0xc] */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    { double v_ = ST(2); FPUSH(c, v_); } /* fld st(2) */
    ST(0) = FPRES(c, ST(0) * ST(3)); /* fmul st(3) */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    { double v_ = ST(3); FPUSH(c, v_); } /* fld st(3) */
    ST(0) = FPRES(c, ST(0) * ST(4)); /* fmul st(4) */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(3) = ST(0); FPOP(c); /* fstp st(3) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FCOM(c, ST(0), RF64((uint32_t)(0x87d1c0u))); /* fcom qword ptr [0x1000d1c0] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x44u)); /* test ah, 0x44 */
    if (PF(c)) goto L_00873187; /* jp 0x873187 */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x20], 0 */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x24], 0 */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x28], 0 */
    goto L_008731a9; /* jmp 0x8731a9 */
L_00873187:;
    ST(0) = FPRES(c, sqrt(ST(0))); /* fsqrt  */
    ST(0) = FPRES(c, FDIV(c, RF64((uint32_t)(0x87d1b8u)), ST(0))); /* fdivr qword ptr [0x1000d1b8] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x8u))); /* fld dword ptr [ecx + 8] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x4u))); /* fld dword ptr [ecx + 4] */
    ST(0) = FPRES(c, ST(0) * ST(2)); /* fmul st(2) */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx))); /* fld dword ptr [ecx] */
    ST(0) = FPRES(c, ST(0) * ST(3)); /* fmul st(3) */
    WF32((uint32_t)(c->esp + 0x20u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x20] */
    WF32((uint32_t)(c->esp + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x24] */
    WF32((uint32_t)(c->esp + 0x28u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x28] */
L_008731a9:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov edx, dword ptr [esp + 0x20] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov eax, dword ptr [esp + 0x24] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov edx, dword ptr [esp + 0x28] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 4], eax */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 8], edx */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    PUSH32(c, 0x008731c4u); f_00875794(c); /* call 0x875794 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov eax, dword ptr [esi + 0x344] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x10u))); /* fild dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x87d1ccu))); /* fmul dword ptr [0x1000d1cc] */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(0x87d1c8u)) - ST(0)); /* fsubr dword ptr [0x1000d1c8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fmul dword ptr [esp + 0x1c] */
    WF32((uint32_t)(c->edi + c->eax + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + eax + 0x24] */
    PUSH32(c, 0x008731ebu); f_00875794(c); /* call 0x875794 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov ecx, dword ptr [esi + 0x344] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x10u))); /* fild dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x87d1ccu))); /* fmul dword ptr [0x1000d1cc] */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(0x87d1c8u)) - ST(0)); /* fsubr dword ptr [0x1000d1c8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fmul dword ptr [esp + 0x1c] */
    WF32((uint32_t)(c->edi + c->ecx + 0x28u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + ecx + 0x28] */
    PUSH32(c, 0x00873212u); f_00875794(c); /* call 0x875794 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov edx, dword ptr [esi + 0x344] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x10u))); /* fild dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x87d1ccu))); /* fmul dword ptr [0x1000d1cc] */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(0x87d1c8u)) - ST(0)); /* fsubr dword ptr [0x1000d1c8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fmul dword ptr [esp + 0x1c] */
    WF32((uint32_t)(c->edi + c->edx + 0x2cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + edx + 0x2c] */
    PUSH32(c, 0x00873239u); f_00875794(c); /* call 0x875794 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov eax, dword ptr [esi + 0x344] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x10u))); /* fild dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x87d1ccu))); /* fmul dword ptr [0x1000d1cc] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x87d1b4u))); /* fmul dword ptr [0x1000d1b4] */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(0x87d1b0u)) - ST(0)); /* fsubr dword ptr [0x1000d1b0] */
    WF32((uint32_t)(c->edi + c->eax + 0x58u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + eax + 0x58] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov ecx, dword ptr [esi + 0x344] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + c->ecx + 0x54u))); /* mov edx, dword ptr [edi + ecx + 0x54] */
    c->eax = (uint32_t)((uint32_t)(c->edi + c->ecx)); /* lea eax, [edi + ecx] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x18], edx */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x18u)); /* add eax, 0x18 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0xfffffffcu))); /* fmul dword ptr [eax - 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0xfffffff8u))); /* fmul dword ptr [eax - 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0xfffffff4u))); /* fmul dword ptr [eax - 0xc] */
    WF32((uint32_t)(c->esp + 0x2cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x2c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov ecx, dword ptr [esp + 0x2c] */
    WF32((uint32_t)(c->esp + 0x30u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x30] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov edx, dword ptr [esp + 0x30] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    WF32((uint32_t)(c->esp + 0x34u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x34] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov ecx, dword ptr [esp + 0x34] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 4], edx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov edx, dword ptr [esi + 0x344] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x3a4u))); /* mov eax, dword ptr [esi + 0x3a4] */
    W32((uint32_t)(c->edi + c->edx + 0x60u), (uint32_t)(c->eax)); /* mov dword ptr [edi + edx + 0x60], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov ecx, dword ptr [esi + 0x344] */
    W32((uint32_t)(c->edi + c->ecx + 0x64u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [edi + ecx + 0x64], 0 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov edx, dword ptr [esi + 0x344] */
    W8((uint32_t)(c->edi + c->edx + 0x6cu), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [edi + edx + 0x6c], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov eax, dword ptr [esi + 0x344] */
    W8((uint32_t)(c->edi + c->eax + 0x6du), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [edi + eax + 0x6d], 0 */
    PUSH32(c, 0x008732dfu); f_00875794(c); /* call 0x875794 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov ecx, dword ptr [esi + 0x344] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x10u))); /* fild dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x87d1ccu))); /* fmul dword ptr [0x1000d1cc] */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(0x87d1c8u)) - ST(0)); /* fsubr dword ptr [0x1000d1c8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x3b0u))); /* fmul dword ptr [esi + 0x3b0] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x3acu))); /* fadd dword ptr [esi + 0x3ac] */
    WF32((uint32_t)(c->edi + c->ecx + 0x48u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + ecx + 0x48] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov edx, dword ptr [esi + 0x344] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + c->edx + 0x48u))); /* mov ecx, dword ptr [edi + edx + 0x48] */
    c->eax = (uint32_t)((uint32_t)(c->edi + c->edx)); /* lea eax, [edi + edx] */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x7cu)); /* add edi, 0x7c */
    W32((uint32_t)(c->eax + 0x44u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x44], ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x340u))); /* mov ecx, dword ptr [esi + 0x340] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    if ((c->sf != c->of)) goto L_00872ea5; /* jl 0x872ea5 */
L_00873333:;
    { uint32_t v_ = 0x87e1c0u; PUSH32(c, v_); } /* push 0x1000e1c0 */
    c->edx = (uint32_t)((uint32_t)(c->esi + 0x4u)); /* lea edx, [esi + 4] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00873345u); f_008748f0(c); /* call 0x8748f0 */
    { uint32_t v_ = 0x87e1b4u; PUSH32(c, v_); } /* push 0x1000e1b4 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x84u)); /* lea eax, [esi + 0x84] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x0087335au); f_008748f0(c); /* call 0x8748f0 */
    { uint32_t v_ = 0x87e1a8u; PUSH32(c, v_); } /* push 0x1000e1a8 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x104u)); /* lea ecx, [esi + 0x104] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x0087336fu); f_008748f0(c); /* call 0x8748f0 */
    { uint32_t v_ = 0x87e19cu; PUSH32(c, v_); } /* push 0x1000e19c */
    c->edx = (uint32_t)((uint32_t)(c->esi + 0x184u)); /* lea edx, [esi + 0x184] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00873384u); f_008748f0(c); /* call 0x8748f0 */
    { uint32_t v_ = 0x87e18cu; PUSH32(c, v_); } /* push 0x1000e18c */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x284u)); /* lea eax, [esi + 0x284] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00873399u); f_008748f0(c); /* call 0x8748f0 */
    { uint32_t v_ = 0x87e180u; PUSH32(c, v_); } /* push 0x1000e180 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x204u)); /* lea ecx, [esi + 0x204] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x008733aeu); f_008748f0(c); /* call 0x8748f0 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_008733bb; /* je 0x8733bb */
    W8((uint32_t)(c->esi + 0x304u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esi + 0x304], 1 */
    goto L_008733c2; /* jmp 0x8733c2 */
L_008733bb:;
    W8((uint32_t)(c->esi + 0x304u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esi + 0x304], 0 */
L_008733c2:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x340u))); /* mov eax, dword ptr [esi + 0x340] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x30cu))); /* mov ecx, dword ptr [esi + 0x30c] */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x348u)); /* lea edi, [esi + 0x348] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 8)); /* lea eax, [eax + eax*8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x142u; PUSH32(c, v_); } /* push 0x142 */
    { uint32_t v_ = 0x208u; PUSH32(c, v_); } /* push 0x208 */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xfcu)); PUSH32(c, 0x008733f0u); call_indirect(c, t_); } /* call dword ptr [edx + 0xfc] */
    (void)sub32(c, R32((uint32_t)(c->edi)), (uint32_t)0x0u); /* cmp dword ptr [edi], 0 */
    if (!c->zf) goto L_0087348c; /* jne 0x87348c */
    c->ecx = (uint32_t)(R32((uint32_t)(0x881148u))); /* mov ecx, dword ptr [0x10011148] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x18u)); PUSH32(c, 0x00873404u); call_indirect(c, t_); } /* call dword ptr [edx + 0x18] */
    c->eax = (uint32_t)(R32((uint32_t)(0x881148u))); /* mov eax, dword ptr [0x10011148] */
    { uint32_t v_ = 0x87e100u; PUSH32(c, v_); } /* push 0x1000e100 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00873414u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(0x881148u))); /* mov eax, dword ptr [0x10011148] */
    { uint32_t v_ = 0x145u; PUSH32(c, v_); } /* push 0x145 */
    { uint32_t v_ = 0x87e390u; PUSH32(c, v_); } /* push 0x1000e390 */
    { uint32_t v_ = 0x87e0f4u; PUSH32(c, v_); } /* push 0x1000e0f4 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x0087342eu); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(0x881148u))); /* mov eax, dword ptr [0x10011148] */
    { uint32_t v_ = 0x87e170u; PUSH32(c, v_); } /* push 0x1000e170 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x0087343eu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    W32((uint32_t)(c->esp + 0x15cu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x15c], 0 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_0087344e:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x87e170u))); /* mov cl, byte ptr [eax + 0x1000e170] */
    W8((uint32_t)(c->esp + c->eax + 0x38u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esp + eax + 0x38], cl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_0087344e; /* jne 0x87344e */
    c->ecx = (uint32_t)((uint32_t)0x4au); /* mov ecx, 0x4a */
    c->esi = (uint32_t)((uint32_t)(c->esp + 0x38u)); /* lea esi, [esp + 0x38] */
    c->edi = (uint32_t)((uint32_t)(c->esp + 0x160u)); /* lea edi, [esp + 0x160] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x160u)); /* lea edx, [esp + 0x160] */
    { uint32_t v_ = 0x87d920u; PUSH32(c, v_); } /* push 0x1000d920 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    W32((uint32_t)(c->esp + 0x39cu), (uint32_t)((uint32_t)0x3u)); /* mov dword ptr [esp + 0x39c], 3 */
    PUSH32(c, 0x0087348cu); f_008756fa(c); /* call 0x8756fa */
L_0087348c:;
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00873493u); f_008734b0(c); /* call 0x8734b0 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
L_00873495:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x38cu))); /* mov ecx, dword ptr [esp + 0x38c] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x388u)); /* add esp, 0x388 */
    c->esp += 16; return; /* ret 0xc */
}

void f_008734b0(CPU *c) { /* FUN_100034b0 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x138u)); /* sub esp, 0x138 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x4cu)); /* lea eax, [esp + 0x4c] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    W32((uint32_t)(c->esp + 0x38u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x38], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x38u))); /* mov eax, dword ptr [esp + 0x38] */
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
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4c4u))); /* mov ecx, dword ptr [esi + 0x4c4] */
    c->ebp = (uint32_t)(logic32(c, 0)); /* xor ebp, ebp */
    W32((uint32_t)(c->esp + 0x40u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x40], ecx */
    W32((uint32_t)(c->esp + 0x44u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0x44], ebp */
    FPUSH(c, (double)(int64_t)R64((uint32_t)(c->esp + 0x40u))); /* fild qword ptr [esp + 0x40] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x4c8u))); /* mov edx, dword ptr [esi + 0x4c8] */
    W32((uint32_t)(c->esp + 0x44u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0x44], ebp */
    W32((uint32_t)(c->esp + 0x40u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x40], edx */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0xcu)); /* lea eax, [esp + 0xc] */
    ST(0) = FPRES(c, FDIV(c, (double)RF32((uint32_t)(0x87d1b0u)), ST(0))); /* fdivr dword ptr [0x1000d1b0] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x30cu))); /* mov ecx, dword ptr [esi + 0x30c] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x340u))); /* mov eax, dword ptr [esi + 0x340] */
    W32((uint32_t)(c->esi + 0x360u), (uint32_t)(c->ebp)); /* mov dword ptr [esi + 0x360], ebp */
    W32((uint32_t)(c->esi + 0x35cu), (uint32_t)(c->ebp)); /* mov dword ptr [esi + 0x35c], ebp */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 8)); /* lea eax, [eax + eax*8] */
    W32((uint32_t)(c->esi + 0x358u), (uint32_t)(c->ebp)); /* mov dword ptr [esi + 0x358], ebp */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x348u))); /* mov eax, dword ptr [esi + 0x348] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    WF32((uint32_t)(c->esp + 0x34u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x34] */
    FPUSH(c, (double)(int64_t)R64((uint32_t)(c->esp + 0x54u))); /* fild qword ptr [esp + 0x54] */
    ST(0) = FPRES(c, FDIV(c, (double)RF32((uint32_t)(0x87d1b0u)), ST(0))); /* fdivr dword ptr [0x1000d1b0] */
    WF32((uint32_t)(c->esp + 0x38u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x38] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x158u)); PUSH32(c, 0x00873572u); call_indirect(c, t_); } /* call dword ptr [edx + 0x158] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x340u))); /* mov eax, dword ptr [esi + 0x340] */
    W32((uint32_t)(c->esp + 0x38u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0x38], ebp */
    (void)sub32(c, c->eax, c->ebp); /* cmp eax, ebp */
    if ((c->zf || c->sf != c->of)) goto L_00873bbb; /* jle 0x873bbb */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x54u)); /* lea ecx, [esp + 0x54] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    W32((uint32_t)(c->esp + 0x44u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x44], ecx */
    W32((uint32_t)(c->esp + 0x40u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0x40], ebp */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
L_00873595:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov eax, dword ptr [esi + 0x344] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x440u))); /* fld dword ptr [esi + 0x440] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + c->edi + 0x4u))); /* fmul dword ptr [eax + edi + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x430u))); /* fld dword ptr [esi + 0x430] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + c->edi))); /* fmul dword ptr [eax + edi] */
    c->eax = (uint32_t)(add32(c, c->eax, c->edi)); /* add eax, edi */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x450u))); /* fld dword ptr [esi + 0x450] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x8u))); /* fmul dword ptr [eax + 8] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x460u))); /* fadd dword ptr [esi + 0x460] */
    WF32((uint32_t)(c->esp + 0x2cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x2c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x444u))); /* fld dword ptr [esi + 0x444] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x4u))); /* fmul dword ptr [eax + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x434u))); /* fld dword ptr [esi + 0x434] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax))); /* fmul dword ptr [eax] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x454u))); /* fld dword ptr [esi + 0x454] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x8u))); /* fmul dword ptr [eax + 8] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x464u))); /* fadd dword ptr [esi + 0x464] */
    WF32((uint32_t)(c->esp + 0x30u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x30] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax))); /* fld dword ptr [eax] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x438u))); /* fmul dword ptr [esi + 0x438] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x8u))); /* fld dword ptr [eax + 8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x458u))); /* fmul dword ptr [esi + 0x458] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x4u))); /* fld dword ptr [eax + 4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x448u))); /* fmul dword ptr [esi + 0x448] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x468u))); /* fadd dword ptr [esi + 0x468] */
    WF32((uint32_t)(c->esp + 0x34u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x34] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x2cu))); /* fld dword ptr [esp + 0x2c] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x358u))); /* fadd dword ptr [esi + 0x358] */
    WF32((uint32_t)(c->esi + 0x358u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x358] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x30u))); /* fld dword ptr [esp + 0x30] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x35cu))); /* fadd dword ptr [esi + 0x35c] */
    WF32((uint32_t)(c->esi + 0x35cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x35c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x34u))); /* fld dword ptr [esp + 0x34] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x360u))); /* fadd dword ptr [esi + 0x360] */
    WF32((uint32_t)(c->esi + 0x360u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x360] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov eax, dword ptr [esi + 0x344] */
    c->eax = (uint32_t)(add32(c, c->eax, c->edi)); /* add eax, edi */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x3cu))); /* fld dword ptr [eax + 0x3c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x87d1c8u))); /* fmul dword ptr [0x1000d1c8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4cu))); /* mov ecx, dword ptr [eax + 0x4c] */
    W32((uint32_t)(c->esp + 0x50u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x50], ecx */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); /* fst dword ptr [esp + 0x14] */
    ST(0) = -ST(0); /* fchs  */
    WF32((uint32_t)(c->esp + 0x118u), (float)ST(0)); /* fst dword ptr [esp + 0x118] */
    WF32((uint32_t)(c->esp + 0x124u), (float)ST(0)); /* fst dword ptr [esp + 0x124] */
    WF32((uint32_t)(c->esp + 0x128u), (float)ST(0)); /* fst dword ptr [esp + 0x128] */
    WF32((uint32_t)(c->esp + 0x134u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x134] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x44u))); /* mov eax, dword ptr [esp + 0x44] */
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
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x50u))); /* fld dword ptr [esp + 0x50] */
    ST(0) = FTRIG(c, ST(0), cos); /* fcos  */
    WF32((uint32_t)(c->esp + 0x54u), (float)ST(0)); /* fst dword ptr [esp + 0x54] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x50u))); /* fld dword ptr [esp + 0x50] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = -ST(0); /* fchs  */
    WF32((uint32_t)(c->esp + 0x64u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x64] */
    WF32((uint32_t)(c->esp + 0x58u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x58] */
    WF32((uint32_t)(c->esp + 0x68u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x68] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x74u))); /* fld dword ptr [esp + 0x74] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x87d1d0u))); /* fmul dword ptr [0x1000d1d0] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x64u))); /* fld dword ptr [esp + 0x64] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x14u))); /* fmul dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) + ST(1)); /* fadd st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x54u))); /* fld dword ptr [esp + 0x54] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x118u))); /* fmul dword ptr [esp + 0x118] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x84u))); /* fadd dword ptr [esp + 0x84] */
    ST(0) = FPRES(c, ST(0) + ST(1)); /* fadd st(1) */
    WF32((uint32_t)(c->esp + 0xf4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xf4] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x78u))); /* fld dword ptr [esp + 0x78] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x87d1d0u))); /* fmul dword ptr [0x1000d1d0] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x68u))); /* fld dword ptr [esp + 0x68] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x14u))); /* fmul dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) + ST(1)); /* fadd st(1) */
    WF32((uint32_t)(c->esp + 0x38u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x38] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x58u))); /* fld dword ptr [esp + 0x58] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x118u))); /* fmul dword ptr [esp + 0x118] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov eax, dword ptr [esp + 0x34] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x20], eax */
    W32((uint32_t)(c->esp + 0xa8u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0xa8], ebp */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x88u))); /* fadd dword ptr [esp + 0x88] */
    c->eax = (uint32_t)((uint32_t)(c->edx + c->ecx)); /* lea eax, [edx + ecx] */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x38u))); /* fadd dword ptr [esp + 0x38] */
    WF32((uint32_t)(c->esp + 0xf8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xf8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x64u))); /* fld dword ptr [esp + 0x64] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x128u))); /* fmul dword ptr [esp + 0x128] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x54u))); /* fld dword ptr [esp + 0x54] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x124u))); /* fmul dword ptr [esp + 0x124] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x84u))); /* fadd dword ptr [esp + 0x84] */
    ST(0) = FPRES(c, ST(0) + ST(3)); /* fadd st(3) */
    WF32((uint32_t)(c->esp + 0x100u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x100] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x68u))); /* fld dword ptr [esp + 0x68] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x128u))); /* fmul dword ptr [esp + 0x128] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x58u))); /* fld dword ptr [esp + 0x58] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x124u))); /* fmul dword ptr [esp + 0x124] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x88u))); /* fadd dword ptr [esp + 0x88] */
    ST(0) = FPRES(c, ST(0) + ST(1)); /* fadd st(1) */
    WF32((uint32_t)(c->esp + 0x104u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x104] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x54u))); /* fld dword ptr [esp + 0x54] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x14u))); /* fmul dword ptr [esp + 0x14] */
    WF32((uint32_t)(c->esp + 0x4cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x4c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x64u))); /* fld dword ptr [esp + 0x64] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x134u))); /* fmul dword ptr [esp + 0x134] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x84u))); /* fadd dword ptr [esp + 0x84] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x4cu))); /* fadd dword ptr [esp + 0x4c] */
    ST(0) = FPRES(c, ST(0) + ST(3)); /* fadd st(3) */
    WF32((uint32_t)(c->esp + 0x10cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x58u))); /* fld dword ptr [esp + 0x58] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x14u))); /* fmul dword ptr [esp + 0x14] */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x68u))); /* fld dword ptr [esp + 0x68] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x134u))); /* fmul dword ptr [esp + 0x134] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x88u))); /* fadd dword ptr [esp + 0x88] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x14u))); /* fadd dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) + ST(1)); /* fadd st(1) */
    WF32((uint32_t)(c->esp + 0x110u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x110] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x84u))); /* fld dword ptr [esp + 0x84] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x4cu))); /* fadd dword ptr [esp + 0x4c] */
    ST(0) = FPRES(c, ST(0) + ST(1)); /* fadd st(1) */
    ST(2) = ST(0); FPOP(c); /* fstp st(2) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x88u))); /* fld dword ptr [esp + 0x88] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x14u))); /* fadd dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x38u))); /* fadd dword ptr [esp + 0x38] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xf4u))); /* fld dword ptr [esp + 0xf4] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x2cu))); /* fadd dword ptr [esp + 0x2c] */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xf8u))); /* fld dword ptr [esp + 0xf8] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x30u))); /* fadd dword ptr [esp + 0x30] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
    WF32((uint32_t)(c->esp + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov ecx, dword ptr [esp + 0x1c] */
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [ebx + 4], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov ecx, dword ptr [esp + 0x20] */
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebx + 8], ecx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ebx, dword ptr [esp + 0x10] */
    c->ebx = (uint32_t)((uint32_t)(c->edx + c->ebx + 0x48u)); /* lea ebx, [edx + ebx + 0x48] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov eax, dword ptr [esp + 0x1c] */
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 4], eax */
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebx + 8], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov ecx, dword ptr [esi + 0x344] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + c->edi + 0x74u))); /* mov eax, dword ptr [ecx + edi + 0x74] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    W32((uint32_t)(c->esp + 0xa4u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0xa4], eax */
    FPUSH(c, (double)(int64_t)R64((uint32_t)(c->esp + 0xa4u))); /* fild qword ptr [esp + 0xa4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x24u))); /* fmul dword ptr [esp + 0x24] */
    WF32((uint32_t)(c->edx + c->ecx + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edx + ecx + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov eax, dword ptr [esi + 0x344] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + c->edi + 0x78u))); /* mov ecx, dword ptr [eax + edi + 0x78] */
    W32((uint32_t)(c->esp + 0xacu), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0xac], ecx */
    W32((uint32_t)(c->esp + 0xb0u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0xb0], ebp */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    FPUSH(c, (double)(int64_t)R64((uint32_t)(c->esp + 0xacu))); /* fild qword ptr [esp + 0xac] */
    W32((uint32_t)(c->esp + 0xc0u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0xc0], ebp */
    W32((uint32_t)(c->esp + 0xd8u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0xd8], ebp */
    W32((uint32_t)(c->esp + 0x98u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0x98], ebp */
    W32((uint32_t)(c->esp + 0xe8u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0xe8], ebp */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x28u))); /* fmul dword ptr [esp + 0x28] */
    W32((uint32_t)(c->esp + 0xb8u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0xb8], ebp */
    WF32((uint32_t)(c->edx + c->eax + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edx + eax + 0x14] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov ecx, dword ptr [esi + 0x344] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + c->edi + 0x74u))); /* mov eax, dword ptr [ecx + edi + 0x74] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    W32((uint32_t)(c->esp + 0xbcu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0xbc], eax */
    FPUSH(c, (double)(int64_t)R64((uint32_t)(c->esp + 0xbcu))); /* fild qword ptr [esp + 0xbc] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x24u))); /* fmul dword ptr [esp + 0x24] */
    WF32((uint32_t)(c->edx + c->ecx + 0x58u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edx + ecx + 0x58] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov eax, dword ptr [esi + 0x344] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + c->edi + 0x78u))); /* mov ecx, dword ptr [eax + edi + 0x78] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    W32((uint32_t)(c->esp + 0xd4u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0xd4], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov ecx, dword ptr [esp + 0x34] */
    FPUSH(c, (double)(int64_t)R64((uint32_t)(c->esp + 0xd4u))); /* fild qword ptr [esp + 0xd4] */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x20], ecx */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x28u))); /* fmul dword ptr [esp + 0x28] */
    WF32((uint32_t)(c->edx + c->eax + 0x5cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [edx + eax + 0x5c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x100u))); /* fld dword ptr [esp + 0x100] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x2cu))); /* fadd dword ptr [esp + 0x2c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)((uint32_t)(c->edx + c->eax + 0x18u)); /* lea ecx, [edx + eax + 0x18] */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x104u))); /* fld dword ptr [esp + 0x104] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x30u))); /* fadd dword ptr [esp + 0x30] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    WF32((uint32_t)(c->esp + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov eax, dword ptr [esp + 0x1c] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov eax, dword ptr [esp + 0x20] */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 8], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov ecx, dword ptr [esi + 0x344] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + c->edi + 0x74u))); /* mov eax, dword ptr [ecx + edi + 0x74] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    W32((uint32_t)(c->esp + 0x94u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x94], eax */
    FPUSH(c, (double)(int64_t)R64((uint32_t)(c->esp + 0x94u))); /* fild qword ptr [esp + 0x94] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x24u))); /* fmul dword ptr [esp + 0x24] */
    WF32((uint32_t)(c->edx + c->ecx + 0x28u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edx + ecx + 0x28] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov eax, dword ptr [esi + 0x344] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + c->edi + 0x78u))); /* mov ecx, dword ptr [eax + edi + 0x78] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    W32((uint32_t)(c->esp + 0xe4u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0xe4], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov ecx, dword ptr [esp + 0x34] */
    FPUSH(c, (double)(int64_t)R64((uint32_t)(c->esp + 0xe4u))); /* fild qword ptr [esp + 0xe4] */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x20], ecx */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0x87d1b0u))); /* fadd dword ptr [0x1000d1b0] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x28u))); /* fmul dword ptr [esp + 0x28] */
    WF32((uint32_t)(c->edx + c->eax + 0x2cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [edx + eax + 0x2c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10cu))); /* fld dword ptr [esp + 0x10c] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x2cu))); /* fadd dword ptr [esp + 0x2c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)((uint32_t)(c->edx + c->eax + 0x30u)); /* lea ecx, [edx + eax + 0x30] */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x110u))); /* fld dword ptr [esp + 0x110] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x30u))); /* fadd dword ptr [esp + 0x30] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
    WF32((uint32_t)(c->esp + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov ecx, dword ptr [esp + 0x1c] */
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [ebx + 4], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov ecx, dword ptr [esp + 0x20] */
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebx + 8], ecx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ebx, dword ptr [esp + 0x10] */
    c->ebx = (uint32_t)((uint32_t)(c->edx + c->ebx + 0x60u)); /* lea ebx, [edx + ebx + 0x60] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov eax, dword ptr [esp + 0x1c] */
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 4], eax */
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebx + 8], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov ecx, dword ptr [esi + 0x344] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + c->edi + 0x74u))); /* mov eax, dword ptr [ecx + edi + 0x74] */
    W32((uint32_t)(c->esp + 0xb4u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0xb4], eax */
    FPUSH(c, (double)(int64_t)R64((uint32_t)(c->esp + 0xb4u))); /* fild qword ptr [esp + 0xb4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    W32((uint32_t)(c->esp + 0xd0u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0xd0], ebp */
    W32((uint32_t)(c->esp + 0xc8u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0xc8], ebp */
    W32((uint32_t)(c->esp + 0xe0u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0xe0], ebp */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0x87d1b0u))); /* fadd dword ptr [0x1000d1b0] */
    W32((uint32_t)(c->esp + 0xf0u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0xf0], ebp */
    W32((uint32_t)(c->esp + 0xa0u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0xa0], ebp */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x24u))); /* fmul dword ptr [esp + 0x24] */
    WF32((uint32_t)(c->edx + c->ecx + 0x40u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edx + ecx + 0x40] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov eax, dword ptr [esi + 0x344] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + c->edi + 0x78u))); /* mov ecx, dword ptr [eax + edi + 0x78] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    W32((uint32_t)(c->esp + 0xccu), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0xcc], ecx */
    FPUSH(c, (double)(int64_t)R64((uint32_t)(c->esp + 0xccu))); /* fild qword ptr [esp + 0xcc] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0x87d1b0u))); /* fadd dword ptr [0x1000d1b0] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x28u))); /* fmul dword ptr [esp + 0x28] */
    WF32((uint32_t)(c->edx + c->eax + 0x44u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edx + eax + 0x44] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov ecx, dword ptr [esi + 0x344] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + c->edi + 0x74u))); /* mov eax, dword ptr [ecx + edi + 0x74] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    W32((uint32_t)(c->esp + 0xc4u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0xc4], eax */
    FPUSH(c, (double)(int64_t)R64((uint32_t)(c->esp + 0xc4u))); /* fild qword ptr [esp + 0xc4] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0x87d1b0u))); /* fadd dword ptr [0x1000d1b0] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x24u))); /* fmul dword ptr [esp + 0x24] */
    WF32((uint32_t)(c->edx + c->ecx + 0x70u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edx + ecx + 0x70] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov eax, dword ptr [esi + 0x344] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + c->edi + 0x78u))); /* mov ecx, dword ptr [eax + edi + 0x78] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    W32((uint32_t)(c->esp + 0xdcu), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0xdc], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov ecx, dword ptr [esp + 0x34] */
    FPUSH(c, (double)(int64_t)R64((uint32_t)(c->esp + 0xdcu))); /* fild qword ptr [esp + 0xdc] */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x20], ecx */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0x87d1b0u))); /* fadd dword ptr [0x1000d1b0] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x28u))); /* fmul dword ptr [esp + 0x28] */
    WF32((uint32_t)(c->edx + c->eax + 0x74u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edx + eax + 0x74] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x2cu))); /* fadd dword ptr [esp + 0x2c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)((uint32_t)(c->edx + c->eax + 0x78u)); /* lea ecx, [edx + eax + 0x78] */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x30u))); /* fadd dword ptr [esp + 0x30] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    WF32((uint32_t)(c->esp + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov eax, dword ptr [esp + 0x1c] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov eax, dword ptr [esp + 0x20] */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 8], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov ecx, dword ptr [esi + 0x344] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + c->edi + 0x74u))); /* mov eax, dword ptr [ecx + edi + 0x74] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    W32((uint32_t)(c->esp + 0xecu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0xec], eax */
    FPUSH(c, (double)(int64_t)R64((uint32_t)(c->esp + 0xecu))); /* fild qword ptr [esp + 0xec] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0x87d1b0u))); /* fadd dword ptr [0x1000d1b0] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x24u))); /* fmul dword ptr [esp + 0x24] */
    WF32((uint32_t)(c->edx + c->ecx + 0x88u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edx + ecx + 0x88] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov eax, dword ptr [esi + 0x344] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + c->edi + 0x78u))); /* mov ecx, dword ptr [eax + edi + 0x78] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    W32((uint32_t)(c->esp + 0x9cu), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x9c], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x40u))); /* mov ecx, dword ptr [esp + 0x40] */
    FPUSH(c, (double)(int64_t)R64((uint32_t)(c->esp + 0x9cu))); /* fild qword ptr [esp + 0x9c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x28u))); /* fmul dword ptr [esp + 0x28] */
    WF32((uint32_t)(c->edx + c->eax + 0x8cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [edx + eax + 0x8c] */
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0x6u)); /* lea eax, [ecx + 6] */
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
    if ((c->sf == c->of)) goto L_00873b93; /* jge 0x873b93 */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->ebx = (uint32_t)(c->edx); /* mov ebx, edx */
    W32((uint32_t)(c->esp + 0x38u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x38], eax */
L_00873b6f:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov ecx, dword ptr [esi + 0x344] */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x18u)); /* add ebx, 0x18 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + c->edi + 0x68u))); /* mov eax, dword ptr [ecx + edi + 0x68] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    W32((uint32_t)(c->ebx + c->ecx + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + ecx - 0xc], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x38u))); /* mov eax, dword ptr [esp + 0x38] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    W32((uint32_t)(c->esp + 0x38u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x38], eax */
    if (!c->zf) goto L_00873b6f; /* jne 0x873b6f */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x40u))); /* mov ecx, dword ptr [esp + 0x40] */
L_00873b93:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x3cu))); /* mov eax, dword ptr [esp + 0x3c] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x6u)); /* add ecx, 6 */
    W32((uint32_t)(c->esp + 0x40u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x40], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x340u))); /* mov ecx, dword ptr [esi + 0x340] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x90u)); /* add edx, 0x90 */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x7cu)); /* add edi, 0x7c */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    W32((uint32_t)(c->esp + 0x3cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x3c], eax */
    if ((c->sf != c->of)) goto L_00873595; /* jl 0x873595 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_00873bbb:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x30cu))); /* mov ecx, dword ptr [esi + 0x30c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x348u))); /* mov eax, dword ptr [esi + 0x348] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x15cu)); PUSH32(c, 0x00873bd0u); call_indirect(c, t_); } /* call dword ptr [edx + 0x15c] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x138u)); /* add esp, 0x138 */
    c->esp += 4; return; /* ret  */
}

void f_00873be0(CPU *c) { /* FUN_10003be0 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x308u))); /* mov ecx, dword ptr [edi + 0x308] */
    c->edx = (uint32_t)((uint32_t)(c->edi + 0x3f0u)); /* lea edx, [edi + 0x3f0] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x64u)); PUSH32(c, 0x00873bf8u); call_indirect(c, t_); } /* call dword ptr [eax + 0x64] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00873c79; /* je 0x873c79 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov edx, dword ptr [esp + 0x20] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x344u))); /* mov ecx, dword ptr [edi + 0x344] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->edx); /* mov esi, edx */
    c->esi = (uint32_t)(shl32(c, c->esi, 5)); /* shl esi, 5 */
    c->esi = (uint32_t)(sub32(c, c->esi, c->edx)); /* sub esi, edx */
    c->esi = (uint32_t)(shl32(c, c->esi, 2)); /* shl esi, 2 */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->esi)); /* add ecx, esi */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov ecx, dword ptr [ebx] */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0xc], ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov edx, dword ptr [ebx + 4] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x10], edx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov ebx, dword ptr [ebx + 8] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x18], ecx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x18u)); /* lea ecx, [esp + 0x18] */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x1c], edx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x10u)); /* lea ecx, [esp + 0x10] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x18], ebx */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x24], ebx */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0x42c80000u)); /* mov dword ptr [esp + 0x14], 0x42c80000 */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)((uint32_t)0xc2c80000u)); /* mov dword ptr [esp + 0x20], 0xc2c80000 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x24u)); PUSH32(c, 0x00873c57u); call_indirect(c, t_); } /* call dword ptr [edx + 0x24] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fld dword ptr [esp + 0x1c] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x10u))); /* fsub dword ptr [esp + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + 0x344u))); /* mov edx, dword ptr [edi + 0x344] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->edi + 0x408u))); /* fadd dword ptr [edi + 0x408] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x10u))); /* fadd dword ptr [esp + 0x10] */
    WF32((uint32_t)(c->edx + c->esi + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edx + esi + 4] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
L_00873c79:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    c->esp += 8; return; /* ret 4 */
}

void f_00873c80(CPU *c) { /* FUN_10003c80 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x476u))); /* mov al, byte ptr [esi + 0x476] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00873ebf; /* jne 0x873ebf */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x3c0u))); /* mov eax, dword ptr [esi + 0x3c0] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_00873caf; /* jle 0x873caf */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->esp + 0x14u)))); /* sub eax, dword ptr [esp + 0x14] */
    W32((uint32_t)(c->esi + 0x3c0u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x3c0], eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 8; return; /* ret 4 */
L_00873caf:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x474u))); /* mov al, byte ptr [esi + 0x474] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00873ea3; /* je 0x873ea3 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x308u))); /* mov ecx, dword ptr [esi + 0x308] */
    c->edx = (uint32_t)((uint32_t)(c->esi + 0x480u)); /* lea edx, [esi + 0x480] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x64u)); PUSH32(c, 0x00873cd0u); call_indirect(c, t_); } /* call dword ptr [eax + 0x64] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00873ea3; /* je 0x873ea3 */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x40u))); /* fld dword ptr [eax + 0x40] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x4a0u))); /* fmul dword ptr [esi + 0x4a0] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x30u))); /* fld dword ptr [eax + 0x30] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x49cu))); /* fmul dword ptr [esi + 0x49c] */
    c->edx = (uint32_t)((uint32_t)(c->esi + 0x364u)); /* lea edx, [esi + 0x364] */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x498u))); /* fld dword ptr [esi + 0x498] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x20u))); /* fmul dword ptr [eax + 0x20] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->eax + 0x50u))); /* fadd dword ptr [eax + 0x50] */
    WF32((uint32_t)(c->esp + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x24u))); /* fld dword ptr [eax + 0x24] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x498u))); /* fmul dword ptr [esi + 0x498] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x44u))); /* fld dword ptr [eax + 0x44] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x4a0u))); /* fmul dword ptr [esi + 0x4a0] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edi, dword ptr [esp + 8] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x34u))); /* fld dword ptr [eax + 0x34] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x49cu))); /* fmul dword ptr [esi + 0x49c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->eax + 0x54u))); /* fadd dword ptr [eax + 0x54] */
    WF32((uint32_t)(c->esp + 0xcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xc] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x28u))); /* fld dword ptr [eax + 0x28] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x498u))); /* fmul dword ptr [esi + 0x498] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x48u))); /* fld dword ptr [eax + 0x48] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x4a0u))); /* fmul dword ptr [esi + 0x4a0] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x38u))); /* fld dword ptr [eax + 0x38] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x49cu))); /* fmul dword ptr [esi + 0x49c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->eax + 0x58u))); /* fadd dword ptr [eax + 0x58] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edi)); /* mov dword ptr [ecx], edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edi, dword ptr [esp + 0xc] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->edi)); /* mov dword ptr [ecx + 4], edi */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edi, dword ptr [esp + 0x10] */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [ecx + 8], edi */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x370u)); /* lea ecx, [esi + 0x370] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x30u))); /* fld dword ptr [eax + 0x30] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x4b4u))); /* fmul dword ptr [esi + 0x4b4] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x40u))); /* fld dword ptr [eax + 0x40] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x4b8u))); /* fmul dword ptr [esi + 0x4b8] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x20u))); /* fld dword ptr [eax + 0x20] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x4b0u))); /* fmul dword ptr [esi + 0x4b0] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->eax + 0x50u))); /* fadd dword ptr [eax + 0x50] */
    WF32((uint32_t)(c->esp + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x34u))); /* fld dword ptr [eax + 0x34] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x4b4u))); /* fmul dword ptr [esi + 0x4b4] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x24u))); /* fld dword ptr [eax + 0x24] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x4b0u))); /* fmul dword ptr [esi + 0x4b0] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edi, dword ptr [esp + 8] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x44u))); /* fld dword ptr [eax + 0x44] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x4b8u))); /* fmul dword ptr [esi + 0x4b8] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->eax + 0x54u))); /* fadd dword ptr [eax + 0x54] */
    WF32((uint32_t)(c->esp + 0xcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xc] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x38u))); /* fld dword ptr [eax + 0x38] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x4b4u))); /* fmul dword ptr [esi + 0x4b4] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x28u))); /* fld dword ptr [eax + 0x28] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x4b0u))); /* fmul dword ptr [esi + 0x4b0] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x48u))); /* fld dword ptr [eax + 0x48] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x4b8u))); /* fmul dword ptr [esi + 0x4b8] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->eax + 0x58u))); /* fadd dword ptr [eax + 0x58] */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    W32((uint32_t)(c->eax), (uint32_t)(c->edi)); /* mov dword ptr [eax], edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edi, dword ptr [esp + 0xc] */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->edi)); /* mov dword ptr [eax + 4], edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edi, dword ptr [esp + 0x10] */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [eax + 8], edi */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx))); /* fld dword ptr [ecx] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->edx))); /* fsub dword ptr [edx] */
    WF32((uint32_t)(c->esp + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x4u))); /* fld dword ptr [ecx + 4] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->edx + 0x4u))); /* fsub dword ptr [edx + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    WF32((uint32_t)(c->esp + 0xcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xc] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x8u))); /* fld dword ptr [ecx + 8] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->edx + 0x8u))); /* fsub dword ptr [edx + 8] */
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    W32((uint32_t)(c->edx), (uint32_t)(c->eax)); /* mov dword ptr [edx], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [edx + 4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [edx + 8], eax */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x8u))); /* fld dword ptr [ecx + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x4u))); /* fld dword ptr [ecx + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx))); /* fld dword ptr [ecx] */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    { double v_ = ST(2); FPUSH(c, v_); } /* fld st(2) */
    ST(0) = FPRES(c, ST(0) * ST(3)); /* fmul st(3) */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    { double v_ = ST(3); FPUSH(c, v_); } /* fld st(3) */
    ST(0) = FPRES(c, ST(0) * ST(4)); /* fmul st(4) */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(3) = ST(0); FPOP(c); /* fstp st(3) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FCOM(c, ST(0), RF64((uint32_t)(0x87d1c0u))); /* fcom qword ptr [0x1000d1c0] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x44u)); /* test ah, 0x44 */
    if (PF(c)) goto L_00873e6b; /* jp 0x873e6b */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 8], 0 */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0xc], 0 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x10], 0 */
    goto L_00873e8d; /* jmp 0x873e8d */
L_00873e6b:;
    ST(0) = FPRES(c, sqrt(ST(0))); /* fsqrt  */
    ST(0) = FPRES(c, FDIV(c, RF64((uint32_t)(0x87d1b8u)), ST(0))); /* fdivr qword ptr [0x1000d1b8] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx))); /* fld dword ptr [ecx] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF32((uint32_t)(c->esp + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x4u))); /* fld dword ptr [ecx + 4] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF32((uint32_t)(c->esp + 0xcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xc] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x8u))); /* fld dword ptr [ecx + 8] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
L_00873e8d:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 4], eax */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 8], edx */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
L_00873ea3:;
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov edi, dword ptr [esp + 0x18] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00873eafu); f_008742d0(c); /* call 0x8742d0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00873eb7u); f_00874690(c); /* call 0x874690 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00873ebeu); f_008734b0(c); /* call 0x8734b0 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_00873ebf:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 8; return; /* ret 4 */
}

void f_00873ed0(CPU *c) { /* FUN_10003ed0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x476u))); /* mov al, byte ptr [esi + 0x476] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00873f2d; /* jne 0x873f2d */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x3c0u))); /* mov eax, dword ptr [esi + 0x3c0] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((!c->zf && c->sf == c->of)) goto L_00873f2d; /* jg 0x873f2d */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x30cu))); /* mov ecx, dword ptr [esi + 0x30c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x348u))); /* mov edx, dword ptr [esi + 0x348] */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14cu)); PUSH32(c, 0x00873f00u); call_indirect(c, t_); } /* call dword ptr [eax + 0x14c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x30cu))); /* mov ecx, dword ptr [esi + 0x30c] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x150u)); PUSH32(c, 0x00873f12u); call_indirect(c, t_); } /* call dword ptr [eax + 0x150] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x340u))); /* mov eax, dword ptr [esi + 0x340] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x30cu))); /* mov ecx, dword ptr [esi + 0x30c] */
    c->eax = (uint32_t)(add32(c, c->eax, c->eax)); /* add eax, eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xe0u)); PUSH32(c, 0x00873f2du); call_indirect(c, t_); } /* call dword ptr [edx + 0xe0] */
L_00873f2d:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00873f40(CPU *c) { /* FUN_10003f40 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x10u)); /* sub esp, 0x10 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->ebp = (uint32_t)(logic32(c, 0)); /* xor ebp, ebp */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x340u))); /* mov ecx, dword ptr [esi + 0x340] */
    (void)sub32(c, c->ecx, c->ebx); /* cmp ecx, ebx */
    if ((c->zf || c->sf != c->of)) goto L_00873f78; /* jle 0x873f78 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov edx, dword ptr [esi + 0x344] */
    c->eax = (uint32_t)((uint32_t)(c->edx + 0x6du)); /* lea eax, [edx + 0x6d] */
L_00873f5f:;
    (void)sub8(c, R8((uint32_t)(c->eax + 0xffffffffu)), ((uint8_t)c->ebx)); /* cmp byte ptr [eax - 1], bl */
    if (!c->zf) goto L_00873f70; /* jne 0x873f70 */
    (void)sub8(c, R8((uint32_t)(c->eax)), ((uint8_t)c->ebx)); /* cmp byte ptr [eax], bl */
    if (c->zf) goto L_00873f81; /* je 0x873f81 */
    (void)sub8(c, R8((uint32_t)(c->esi + 0x471u)), ((uint8_t)c->ebx)); /* cmp byte ptr [esi + 0x471], bl */
    if (!c->zf) goto L_00873f81; /* jne 0x873f81 */
L_00873f70:;
    c->ebp = (uint32_t)(inc32(c, c->ebp)); /* inc ebp */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x7cu)); /* add eax, 0x7c */
    (void)sub32(c, c->ebp, c->ecx); /* cmp ebp, ecx */
    if ((c->sf != c->of)) goto L_00873f5f; /* jl 0x873f5f */
L_00873f78:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
L_00873f81:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ebp); /* mov edi, ebp */
    c->edi = (uint32_t)(shl32(c, c->edi, 5)); /* shl edi, 5 */
    c->edi = (uint32_t)(sub32(c, c->edi, c->ebp)); /* sub edi, ebp */
    c->edi = (uint32_t)(shl32(c, c->edi, 2)); /* shl edi, 2 */
    W32((uint32_t)(c->edx + c->edi + 0x64u), (uint32_t)(c->ebx)); /* mov dword ptr [edx + edi + 0x64], ebx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov eax, dword ptr [esi + 0x344] */
    W32((uint32_t)(c->edi + c->eax + 0x70u), (uint32_t)(c->ebx)); /* mov dword ptr [edi + eax + 0x70], ebx */
    PUSH32(c, 0x00873f9fu); f_00875794(c); /* call 0x875794 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov ecx, dword ptr [esi + 0x344] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x10u))); /* fild dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x87d1ccu))); /* fmul dword ptr [0x1000d1cc] */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(0x87d1c8u)) - ST(0)); /* fsubr dword ptr [0x1000d1c8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x3bcu))); /* fmul dword ptr [esi + 0x3bc] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x364u))); /* fadd dword ptr [esi + 0x364] */
    WF32((uint32_t)(c->edi + c->ecx), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + ecx] */
    PUSH32(c, 0x00873fcdu); f_00875794(c); /* call 0x875794 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov edx, dword ptr [esi + 0x344] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x10u))); /* fild dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x87d1ccu))); /* fmul dword ptr [0x1000d1cc] */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(0x87d1c8u)) - ST(0)); /* fsubr dword ptr [0x1000d1c8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x3bcu))); /* fmul dword ptr [esi + 0x3bc] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x368u))); /* fadd dword ptr [esi + 0x368] */
    WF32((uint32_t)(c->edi + c->edx + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + edx + 4] */
    PUSH32(c, 0x00873ffcu); f_00875794(c); /* call 0x875794 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov eax, dword ptr [esi + 0x344] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x10u))); /* fild dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x87d1ccu))); /* fmul dword ptr [0x1000d1cc] */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(0x87d1c8u)) - ST(0)); /* fsubr dword ptr [0x1000d1c8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x3bcu))); /* fmul dword ptr [esi + 0x3bc] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x36cu))); /* fadd dword ptr [esi + 0x36c] */
    WF32((uint32_t)(c->edi + c->eax + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + eax + 8] */
    PUSH32(c, 0x0087402bu); f_00875794(c); /* call 0x875794 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov ecx, dword ptr [esi + 0x344] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x10u))); /* fild dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x87d1ccu))); /* fmul dword ptr [0x1000d1cc] */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(0x87d1c8u)) - ST(0)); /* fsubr dword ptr [0x1000d1c8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x3b0u))); /* fmul dword ptr [esi + 0x3b0] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x3acu))); /* fadd dword ptr [esi + 0x3ac] */
    WF32((uint32_t)(c->edi + c->ecx + 0x48u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + ecx + 0x48] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov edx, dword ptr [esi + 0x344] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + c->edx + 0x48u))); /* mov ecx, dword ptr [edi + edx + 0x48] */
    c->eax = (uint32_t)((uint32_t)(c->edi + c->edx)); /* lea eax, [edi + edx] */
    W32((uint32_t)(c->eax + 0x44u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x44], ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov edx, dword ptr [esi + 0x344] */
    W32((uint32_t)(c->edi + c->edx + 0x54u), (uint32_t)(c->ebx)); /* mov dword ptr [edi + edx + 0x54], ebx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x475u))); /* mov al, byte ptr [esi + 0x475] */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_008740dd; /* je 0x8740dd */
    PUSH32(c, 0x0087407eu); f_00875794(c); /* call 0x875794 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov eax, dword ptr [esi + 0x344] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x10u))); /* fild dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x87d1ccu))); /* fmul dword ptr [0x1000d1cc] */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(0x87d1c8u)) - ST(0)); /* fsubr dword ptr [0x1000d1c8] */
    WF32((uint32_t)(c->edi + c->eax + 0xcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + eax + 0xc] */
    PUSH32(c, 0x008740a1u); f_00875794(c); /* call 0x875794 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov ecx, dword ptr [esi + 0x344] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x10u))); /* fild dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x87d1ccu))); /* fmul dword ptr [0x1000d1cc] */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(0x87d1c8u)) - ST(0)); /* fsubr dword ptr [0x1000d1c8] */
    WF32((uint32_t)(c->edi + c->ecx + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + ecx + 0x10] */
    PUSH32(c, 0x008740c4u); f_00875794(c); /* call 0x875794 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x10u))); /* fild dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x87d1ccu))); /* fmul dword ptr [0x1000d1cc] */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(0x87d1c8u)) - ST(0)); /* fsubr dword ptr [0x1000d1c8] */
    goto L_00874160; /* jmp 0x874160 */
L_008740dd:;
    PUSH32(c, 0x008740e2u); f_00875794(c); /* call 0x875794 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov eax, dword ptr [esi + 0x344] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x10u))); /* fild dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x87d1ccu))); /* fmul dword ptr [0x1000d1cc] */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(0x87d1c8u)) - ST(0)); /* fsubr dword ptr [0x1000d1c8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x37cu))); /* fmul dword ptr [esi + 0x37c] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x370u))); /* fadd dword ptr [esi + 0x370] */
    WF32((uint32_t)(c->edi + c->eax + 0xcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + eax + 0xc] */
    PUSH32(c, 0x00874111u); f_00875794(c); /* call 0x875794 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov ecx, dword ptr [esi + 0x344] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x10u))); /* fild dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x87d1ccu))); /* fmul dword ptr [0x1000d1cc] */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(0x87d1c8u)) - ST(0)); /* fsubr dword ptr [0x1000d1c8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x37cu))); /* fmul dword ptr [esi + 0x37c] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x374u))); /* fadd dword ptr [esi + 0x374] */
    WF32((uint32_t)(c->edi + c->ecx + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + ecx + 0x10] */
    PUSH32(c, 0x00874140u); f_00875794(c); /* call 0x875794 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x10u))); /* fild dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x87d1ccu))); /* fmul dword ptr [0x1000d1cc] */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(0x87d1c8u)) - ST(0)); /* fsubr dword ptr [0x1000d1c8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x37cu))); /* fmul dword ptr [esi + 0x37c] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x378u))); /* fadd dword ptr [esi + 0x378] */
L_00874160:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov edx, dword ptr [esi + 0x344] */
    WF32((uint32_t)(c->edi + c->edx + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + edx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov eax, dword ptr [esi + 0x344] */
    FPUSH(c, (double)RF32((uint32_t)(c->edi + c->eax + 0x14u))); /* fld dword ptr [edi + eax + 0x14] */
    FPUSH(c, (double)RF32((uint32_t)(c->edi + c->eax + 0x10u))); /* fld dword ptr [edi + eax + 0x10] */
    FPUSH(c, (double)RF32((uint32_t)(c->edi + c->eax + 0xcu))); /* fld dword ptr [edi + eax + 0xc] */
    c->ecx = (uint32_t)((uint32_t)(c->edi + c->eax + 0xcu)); /* lea ecx, [edi + eax + 0xc] */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    { double v_ = ST(2); FPUSH(c, v_); } /* fld st(2) */
    ST(0) = FPRES(c, ST(0) * ST(3)); /* fmul st(3) */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    { double v_ = ST(3); FPUSH(c, v_); } /* fld st(3) */
    ST(0) = FPRES(c, ST(0) * ST(4)); /* fmul st(4) */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(3) = ST(0); FPOP(c); /* fstp st(3) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FCOM(c, ST(0), RF64((uint32_t)(0x87d1c0u))); /* fcom qword ptr [0x1000d1c0] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x44u)); /* test ah, 0x44 */
    if (PF(c)) goto L_008741bd; /* jp 0x8741bd */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x14], 0 */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x18], 0 */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x1c], 0 */
    goto L_008741df; /* jmp 0x8741df */
L_008741bd:;
    ST(0) = FPRES(c, sqrt(ST(0))); /* fsqrt  */
    ST(0) = FPRES(c, FDIV(c, RF64((uint32_t)(0x87d1b8u)), ST(0))); /* fdivr qword ptr [0x1000d1b8] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx))); /* fld dword ptr [ecx] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x4u))); /* fld dword ptr [ecx + 4] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x8u))); /* fld dword ptr [ecx + 8] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF32((uint32_t)(c->esp + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1c] */
L_008741df:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edx, dword ptr [esp + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov edx, dword ptr [esp + 0x1c] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 4], eax */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 8], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov eax, dword ptr [esi + 0x344] */
    c->eax = (uint32_t)(add32(c, c->eax, c->edi)); /* add eax, edi */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x54u))); /* fld dword ptr [eax + 0x54] */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0xcu))); /* fmul dword ptr [eax + 0xc] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x18u)); /* add eax, 0x18 */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ecx, dword ptr [esp + 0x14] */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0xfffffff8u))); /* fmul dword ptr [eax - 8] */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov edx, dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0xfffffffcu))); /* fmul dword ptr [eax - 4] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    WF32((uint32_t)(c->esp + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov ecx, dword ptr [esp + 0x1c] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 4], edx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov edx, dword ptr [esi + 0x344] */
    W8((uint32_t)(c->edi + c->edx + 0x6cu), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [edi + edx + 0x6c], 1 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3ecu))); /* mov al, byte ptr [esi + 0x3ec] */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_0087424d; /* je 0x87424d */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x0087424du); f_00873be0(c); /* call 0x873be0 */
L_0087424d:;
    (void)sub32(c, R32((uint32_t)(c->esi + 0x4ccu)), c->ebx); /* cmp dword ptr [esi + 0x4cc], ebx */
    if (c->zf) goto L_00874273; /* je 0x874273 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov eax, dword ptr [esi + 0x344] */
    W32((uint32_t)(c->edi + c->eax + 0x74u), (uint32_t)(c->ebx)); /* mov dword ptr [edi + eax + 0x74], ebx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov ecx, dword ptr [esi + 0x344] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    W32((uint32_t)(c->edi + c->ecx + 0x78u), (uint32_t)(c->ebx)); /* mov dword ptr [edi + ecx + 0x78], ebx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
L_00874273:;
    PUSH32(c, 0x00874278u); f_00875794(c); /* call 0x875794 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)((uint32_t)0x20005u); /* mov eax, 0x20005 */
    { int64_t r_ = (int64_t)(int32_t)c->ecx * (int32_t)R32((uint32_t)(c->esi + 0x4c4u)); c->ecx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul ecx, dword ptr [esi + 0x4c4] */
    { uint64_t r_ = (uint64_t)c->eax * c->ecx; c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = c->edx != 0; } /* mul ecx */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->edx)); /* sub ecx, edx */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 1)); /* shr ecx, 1 */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->edx)); /* add ecx, edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov edx, dword ptr [esi + 0x344] */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 14)); /* shr ecx, 0xe */
    W32((uint32_t)(c->edi + c->edx + 0x74u), (uint32_t)(c->ecx)); /* mov dword ptr [edi + edx + 0x74], ecx */
    PUSH32(c, 0x008742a0u); f_00875794(c); /* call 0x875794 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)((uint32_t)0x20005u); /* mov eax, 0x20005 */
    { int64_t r_ = (int64_t)(int32_t)c->ecx * (int32_t)R32((uint32_t)(c->esi + 0x4c8u)); c->ecx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul ecx, dword ptr [esi + 0x4c8] */
    { uint64_t r_ = (uint64_t)c->eax * c->ecx; c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = c->edx != 0; } /* mul ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov eax, dword ptr [esi + 0x344] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->edx)); /* sub ecx, edx */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 1)); /* shr ecx, 1 */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->edx)); /* add ecx, edx */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 14)); /* shr ecx, 0xe */
    W32((uint32_t)(c->edi + c->eax + 0x78u), (uint32_t)(c->ecx)); /* mov dword ptr [edi + eax + 0x78], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_008742d0(CPU *c) { /* FUN_100042d0 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x28u)); /* sub esp, 0x28 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov ebx, dword ptr [esp + 0x34] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->ebp = (uint32_t)(logic32(c, 0)); /* xor ebp, ebp */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x3d0u))); /* mov eax, dword ptr [esi + 0x3d0] */
    (void)sub32(c, c->eax, c->ebp); /* cmp eax, ebp */
    if ((c->zf || c->sf != c->of)) goto L_008742fb; /* jle 0x8742fb */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ebx)); /* sub eax, ebx */
    (void)sub32(c, c->eax, c->ebp); /* cmp eax, ebp */
    W32((uint32_t)(c->esi + 0x3d0u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x3d0], eax */
    if ((!c->zf && c->sf == c->of)) goto L_008742fb; /* jg 0x8742fb */
    W8((uint32_t)(c->esi + 0x471u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esi + 0x471], 0 */
L_008742fb:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x340u))); /* mov eax, dword ptr [esi + 0x340] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub32(c, c->eax, c->ebp); /* cmp eax, ebp */
    W32((uint32_t)(c->esp + 0x38u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x38], ecx */
    if ((c->zf || c->sf != c->of)) goto L_0087458b; /* jle 0x87458b */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
L_00874312:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov eax, dword ptr [esi + 0x344] */
    c->eax = (uint32_t)(add32(c, c->eax, c->edi)); /* add eax, edi */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x6cu))); /* mov dl, byte ptr [eax + 0x6c] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00874570; /* je 0x874570 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x64u))); /* mov edx, dword ptr [eax + 0x64] */
    c->edx = (uint32_t)(add32(c, c->edx, c->ebx)); /* add edx, ebx */
    W32((uint32_t)(c->eax + 0x64u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 0x64], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov edx, dword ptr [esi + 0x344] */
    c->eax = (uint32_t)((uint32_t)(c->edi + c->edx)); /* lea eax, [edi + edx] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + c->edx + 0x64u))); /* mov edx, dword ptr [edi + edx + 0x64] */
    (void)sub32(c, c->edx, R32((uint32_t)(c->esi + 0x3a4u))); /* cmp edx, dword ptr [esi + 0x3a4] */
    if ((c->zf || c->sf != c->of)) goto L_008743f4; /* jle 0x8743f4 */
    W8((uint32_t)(c->eax + 0x6cu), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [eax + 0x6c], 0 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x471u))); /* mov al, byte ptr [esi + 0x471] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_0087435f; /* jne 0x87435f */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov eax, dword ptr [esi + 0x344] */
    W8((uint32_t)(c->edi + c->eax + 0x6du), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [edi + eax + 0x6d], 1 */
L_0087435f:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov ecx, dword ptr [esi + 0x344] */
    W32((uint32_t)(c->edi + c->ecx + 0x3cu), (uint32_t)(c->ebp)); /* mov dword ptr [edi + ecx + 0x3c], ebp */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov edx, dword ptr [esi + 0x344] */
    W32((uint32_t)(c->edi + c->edx + 0x68u), (uint32_t)(c->ebp)); /* mov dword ptr [edi + edx + 0x68], ebp */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov eax, dword ptr [esi + 0x344] */
    W32((uint32_t)(c->edi + c->eax + 0x68u), (uint32_t)((uint32_t)0xffffffu)); /* mov dword ptr [edi + eax + 0x68], 0xffffff */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov ecx, dword ptr [esi + 0x344] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x410u))); /* mov edx, dword ptr [esi + 0x410] */
    W32((uint32_t)(c->edi + c->ecx + 0x68u), (uint32_t)(c->edx)); /* mov dword ptr [edi + ecx + 0x68], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x410u))); /* mov eax, dword ptr [esi + 0x410] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (c->zf) goto L_008743e5; /* je 0x8743e5 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov eax, dword ptr [esi + 0x344] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->edi + c->eax + 0x68u))); /* mov ebp, dword ptr [edi + eax + 0x68] */
    c->eax = (uint32_t)((uint32_t)(c->edi + c->eax + 0x68u)); /* lea eax, [edi + eax + 0x68] */
    c->ebp = (uint32_t)(logic32(c, (uint32_t)(c->ebp & (uint32_t)0xff000000u))); /* and ebp, 0xff000000 */
    W32((uint32_t)(c->eax), (uint32_t)(c->ebp)); /* mov dword ptr [eax], ebp */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov ecx, dword ptr [esi + 0x344] */
    c->ebp = (uint32_t)((uint32_t)(c->edi + c->ecx + 0x68u)); /* lea ebp, [edi + ecx + 0x68] */
    PUSH32(c, 0x008743c1u); f_00875794(c); /* call 0x875794 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 24)); /* shl ecx, 0x18 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    c->eax = (uint32_t)((uint32_t)0x80010003u); /* mov eax, 0x80010003 */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)c->ecx; c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = r_ != (int32_t)r_; } /* imul ecx */
    c->edx = (uint32_t)(add32(c, c->edx, c->ecx)); /* add edx, ecx */
    c->edx = (uint32_t)(sar32(c, c->edx, 14)); /* sar edx, 0xe */
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    c->eax = (uint32_t)(shr32(c, c->eax, 31)); /* shr eax, 0x1f */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov eax, dword ptr [ebp] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->edx))); /* or eax, edx */
    W32((uint32_t)(c->ebp), (uint32_t)(c->eax)); /* mov dword ptr [ebp], eax */
    c->ebp = (uint32_t)(logic32(c, 0)); /* xor ebp, ebp */
L_008743e5:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov ecx, dword ptr [esi + 0x344] */
    W32((uint32_t)(c->edi + c->ecx + 0x64u), (uint32_t)(c->ebp)); /* mov dword ptr [edi + ecx + 0x64], ebp */
    goto L_00874570; /* jmp 0x874570 */
L_008743f4:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3dcu))); /* mov dl, byte ptr [esi + 0x3dc] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_008744a9; /* je 0x8744a9 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x10], ebx */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0x14], ebp */
    FPUSH(c, (double)(int64_t)R64((uint32_t)(c->esp + 0x10u))); /* fild qword ptr [esp + 0x10] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x24u))); /* fld dword ptr [eax + 0x24] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->eax + 0x18u))); /* fadd dword ptr [eax + 0x18] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->eax))); /* fadd dword ptr [eax] */
    WF32((uint32_t)(c->eax), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov edx, dword ptr [esi + 0x344] */
    FPUSH(c, (double)RF32((uint32_t)(c->edi + c->edx + 0x28u))); /* fld dword ptr [edi + edx + 0x28] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->edi + c->edx + 0x1cu))); /* fadd dword ptr [edi + edx + 0x1c] */
    c->eax = (uint32_t)((uint32_t)(c->edi + c->edx)); /* lea eax, [edi + edx] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->eax + 0x4u))); /* fadd dword ptr [eax + 4] */
    WF32((uint32_t)(c->eax + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov eax, dword ptr [esi + 0x344] */
    c->eax = (uint32_t)(add32(c, c->eax, c->edi)); /* add eax, edi */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x2cu))); /* fld dword ptr [eax + 0x2c] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->eax + 0x20u))); /* fadd dword ptr [eax + 0x20] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->eax + 0x8u))); /* fadd dword ptr [eax + 8] */
    WF32((uint32_t)(c->eax + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 8] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    PUSH32(c, 0x00874453u); f_00874db0(c); /* call 0x874db0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov ecx, dword ptr [esi + 0x344] */
    FPUSH(c, (double)RF32((uint32_t)(c->edi + c->ecx + 0x58u))); /* fld dword ptr [edi + ecx + 0x58] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edi + c->ecx + 0x54u))); /* fmul dword ptr [edi + ecx + 0x54] */
    c->eax = (uint32_t)((uint32_t)(c->edi + c->ecx)); /* lea eax, [edi + ecx] */
    WF32((uint32_t)(c->eax + 0x54u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 0x54] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov edx, dword ptr [esi + 0x344] */
    FPUSH(c, (double)RF32((uint32_t)(c->edi + c->edx + 0x54u))); /* fld dword ptr [edi + edx + 0x54] */
    c->eax = (uint32_t)((uint32_t)(c->edi + c->edx)); /* lea eax, [edi + edx] */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0xcu))); /* fmul dword ptr [eax + 0xc] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x18u)); /* add eax, 0x18 */
    WF32((uint32_t)(c->esp + 0x20u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x20] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov ecx, dword ptr [esp + 0x20] */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0xfffffff8u))); /* fmul dword ptr [eax - 8] */
    WF32((uint32_t)(c->esp + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x24] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov edx, dword ptr [esp + 0x24] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0xfffffffcu))); /* fmul dword ptr [eax - 4] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    WF32((uint32_t)(c->esp + 0x28u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x28] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov ecx, dword ptr [esp + 0x28] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 4], edx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    goto L_00874570; /* jmp 0x874570 */
L_008744a9:;
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x18], ebx */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0x1c], ebp */
    FPUSH(c, (double)(int64_t)R64((uint32_t)(c->esp + 0x18u))); /* fild qword ptr [esp + 0x18] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x24u))); /* fld dword ptr [eax + 0x24] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->eax + 0x18u))); /* fadd dword ptr [eax + 0x18] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->eax))); /* fadd dword ptr [eax] */
    WF32((uint32_t)(c->eax), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov edx, dword ptr [esi + 0x344] */
    FPUSH(c, (double)RF32((uint32_t)(c->edi + c->edx + 0x28u))); /* fld dword ptr [edi + edx + 0x28] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->edi + c->edx + 0x1cu))); /* fadd dword ptr [edi + edx + 0x1c] */
    c->eax = (uint32_t)((uint32_t)(c->edi + c->edx)); /* lea eax, [edi + edx] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->eax + 0x4u))); /* fadd dword ptr [eax + 4] */
    WF32((uint32_t)(c->eax + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov eax, dword ptr [esi + 0x344] */
    c->eax = (uint32_t)(add32(c, c->eax, c->edi)); /* add eax, edi */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x2cu))); /* fld dword ptr [eax + 0x2c] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->eax + 0x20u))); /* fadd dword ptr [eax + 0x20] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->eax + 0x8u))); /* fadd dword ptr [eax + 8] */
    WF32((uint32_t)(c->eax + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov ecx, dword ptr [esi + 0x344] */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edi + c->ecx + 0x44u))); /* fmul dword ptr [edi + ecx + 0x44] */
    c->eax = (uint32_t)((uint32_t)(c->edi + c->ecx)); /* lea eax, [edi + ecx] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->eax + 0x4cu))); /* fadd dword ptr [eax + 0x4c] */
    WF32((uint32_t)(c->eax + 0x4cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 0x4c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov edx, dword ptr [esi + 0x344] */
    FPUSH(c, (double)RF32((uint32_t)(c->edi + c->edx + 0x40u))); /* fld dword ptr [edi + edx + 0x40] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x398u))); /* fmul dword ptr [esi + 0x398] */
    c->eax = (uint32_t)((uint32_t)(c->edi + c->edx)); /* lea eax, [edi + edx] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(c->eax + 0x4u)) - ST(0)); /* fsubr dword ptr [eax + 4] */
    WF32((uint32_t)(c->eax + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov eax, dword ptr [esi + 0x344] */
    c->eax = (uint32_t)(add32(c, c->eax, c->edi)); /* add eax, edi */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x58u))); /* fld dword ptr [eax + 0x58] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x54u))); /* fmul dword ptr [eax + 0x54] */
    WF32((uint32_t)(c->eax + 0x54u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 0x54] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov ecx, dword ptr [esi + 0x344] */
    FPUSH(c, (double)RF32((uint32_t)(c->edi + c->ecx + 0x54u))); /* fld dword ptr [edi + ecx + 0x54] */
    c->eax = (uint32_t)((uint32_t)(c->edi + c->ecx)); /* lea eax, [edi + ecx] */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0xcu))); /* fmul dword ptr [eax + 0xc] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x18u)); /* add eax, 0x18 */
    WF32((uint32_t)(c->esp + 0x2cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x2c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov edx, dword ptr [esp + 0x2c] */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0xfffffff8u))); /* fmul dword ptr [eax - 8] */
    WF32((uint32_t)(c->esp + 0x30u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x30] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov ecx, dword ptr [esp + 0x30] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0xfffffffcu))); /* fmul dword ptr [eax - 4] */
    W32((uint32_t)(c->eax), (uint32_t)(c->edx)); /* mov dword ptr [eax], edx */
    WF32((uint32_t)(c->esp + 0x34u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x34] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov edx, dword ptr [esp + 0x34] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 4], ecx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 8], edx */
L_00874570:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x3cu))); /* mov ecx, dword ptr [esp + 0x3c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x340u))); /* mov eax, dword ptr [esi + 0x340] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x7cu)); /* add edi, 0x7c */
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
    W32((uint32_t)(c->esp + 0x3cu), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x3c], ecx */
    if ((c->sf != c->of)) goto L_00874312; /* jl 0x874312 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_0087458b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x3ccu))); /* mov eax, dword ptr [esi + 0x3cc] */
    c->eax = (uint32_t)(add32(c, c->eax, c->ebx)); /* add eax, ebx */
    W32((uint32_t)(c->esp + 0x38u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x38], eax */
    W32((uint32_t)(c->esi + 0x3ccu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x3cc], eax */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x38u))); /* fild dword ptr [esp + 0x38] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x3c8u))); /* fld dword ptr [esi + 0x3c8] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x3e8u))); /* fadd dword ptr [esi + 0x3e8] */
    FCOM(c, ST(0), ST(1)); FPOP(c); FPOP(c); /* fcompp  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x41u)); /* test ah, 0x41 */
    if (PF(c)) goto L_008745e6; /* jp 0x8745e6 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x008745bdu); f_00873f40(c); /* call 0x873f40 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_008745c7; /* je 0x8745c7 */
    W32((uint32_t)(c->esi + 0x3ccu), (uint32_t)(c->ebp)); /* mov dword ptr [esi + 0x3cc], ebp */
L_008745c7:;
    PUSH32(c, 0x008745ccu); f_00875794(c); /* call 0x875794 */
    W32((uint32_t)(c->esp + 0x38u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x38], eax */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x38u))); /* fild dword ptr [esp + 0x38] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x3e4u))); /* fmul dword ptr [esi + 0x3e4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x87d1ccu))); /* fmul dword ptr [0x1000d1cc] */
    WF32((uint32_t)(c->esi + 0x3e8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x3e8] */
L_008745e6:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x471u))); /* mov al, byte ptr [esi + 0x471] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_0087463c; /* jne 0x87463c */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x3c4u))); /* mov edx, dword ptr [esi + 0x3c4] */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    W32((uint32_t)(c->esi + 0x3c4u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x3c4], edx */
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x340u))); /* mov edx, dword ptr [esi + 0x340] */
    (void)sub32(c, c->eax, c->edx); /* cmp eax, edx */
    if ((c->zf || c->sf != c->of)) goto L_0087463c; /* jle 0x87463c */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, c->edx, c->ebp); /* cmp edx, ebp */
    W8((uint32_t)(c->esi + 0x470u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esi + 0x470], 1 */
    if ((c->zf || c->sf != c->of)) goto L_0087463c; /* jle 0x87463c */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov ecx, dword ptr [esi + 0x344] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x6du)); /* add ecx, 0x6d */
L_0087461f:;
    (void)sub8(c, R8((uint32_t)(c->ecx)), (uint8_t)0x0u); /* cmp byte ptr [ecx], 0 */
    if (c->zf) goto L_00874635; /* je 0x874635 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x7cu)); /* add ecx, 0x7c */
    (void)sub32(c, c->eax, c->edx); /* cmp eax, edx */
    if ((c->sf != c->of)) goto L_0087461f; /* jl 0x87461f */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x28u)); /* add esp, 0x28 */
    c->esp += 8; return; /* ret 4 */
L_00874635:;
    W8((uint32_t)(c->esi + 0x470u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esi + 0x470], 0 */
L_0087463c:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x28u)); /* add esp, 0x28 */
    c->esp += 8; return; /* ret 4 */
}

void f_00874650(CPU *c) { /* PTR_00874650 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->ecx + 0x3c0u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 0x3c0], eax */
    if ((c->zf || c->sf != c->of)) goto L_00874687; /* jle 0x874687 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x340u))); /* mov edx, dword ptr [ecx + 0x340] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if ((c->zf || c->sf != c->of)) goto L_00874687; /* jle 0x874687 */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
L_0087466d:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x344u))); /* mov esi, dword ptr [ecx + 0x344] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    W8((uint32_t)(c->edx + c->esi + 0x6bu), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [edx + esi + 0x6b], 0 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x340u))); /* mov esi, dword ptr [ecx + 0x340] */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x7cu)); /* add edx, 0x7c */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if ((c->sf != c->of)) goto L_0087466d; /* jl 0x87466d */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00874687:;
    c->esp += 8; return; /* ret 4 */
}

void f_00874690(CPU *c) { /* FUN_10004690 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 4], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x340u))); /* mov eax, dword ptr [esi + 0x340] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_00874851; /* jle 0x874851 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
L_008746b0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov eax, dword ptr [esi + 0x344] */
    c->eax = (uint32_t)(add32(c, c->eax, c->edi)); /* add eax, edi */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x6cu))); /* mov cl, byte ptr [eax + 0x6c] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_00874835; /* je 0x874835 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x64u))); /* mov ecx, dword ptr [eax + 0x64] */
    c->edx = (uint32_t)((uint32_t)(c->esi + 0x4u)); /* lea edx, [esi + 4] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x008746d2u); f_00874860(c); /* call 0x874860 */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x87d1d4u))); /* fmul dword ptr [0x1000d1d4] */
    PUSH32(c, 0x008746ddu); f_008757b8(c); /* call 0x8757b8 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov ecx, dword ptr [esi + 0x344] */
    c->eax = (uint32_t)(shl32(c, c->eax, 24)); /* shl eax, 0x18 */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + c->ecx + 0x68u))); /* mov edx, dword ptr [edi + ecx + 0x68] */
    c->ecx = (uint32_t)((uint32_t)(c->edi + c->ecx + 0x68u)); /* lea ecx, [edi + ecx + 0x68] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0xffffffu))); /* and edx, 0xffffff */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx | c->eax))); /* or edx, eax */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov eax, dword ptr [esi + 0x344] */
    c->edx = (uint32_t)((uint32_t)(c->esi + 0x84u)); /* lea edx, [esi + 0x84] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + c->eax + 0x64u))); /* mov ecx, dword ptr [edi + eax + 0x64] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00874711u); f_00874860(c); /* call 0x874860 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov eax, dword ptr [esi + 0x344] */
    WF32((uint32_t)(c->edi + c->eax + 0x3cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + eax + 0x3c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov ecx, dword ptr [esi + 0x344] */
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    c->ebp = (uint32_t)((uint32_t)(c->edi + c->ecx)); /* lea ebp, [edi + ecx] */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x104u)); /* lea ecx, [esi + 0x104] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + c->edx + 0x64u))); /* mov eax, dword ptr [edi + edx + 0x64] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00874739u); f_00874860(c); /* call 0x874860 */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ebp + 0x5cu))); /* fmul dword ptr [ebp + 0x5c] */
    WF32((uint32_t)(c->ebp + 0x54u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp + 0x54] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov edx, dword ptr [esi + 0x344] */
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    c->ebp = (uint32_t)((uint32_t)(c->edi + c->edx)); /* lea ebp, [edi + edx] */
    c->edx = (uint32_t)((uint32_t)(c->esi + 0x184u)); /* lea edx, [esi + 0x184] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + c->eax + 0x64u))); /* mov ecx, dword ptr [edi + eax + 0x64] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x0087475du); f_00874860(c); /* call 0x874860 */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ebp + 0x48u))); /* fmul dword ptr [ebp + 0x48] */
    WF32((uint32_t)(c->ebp + 0x44u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp + 0x44] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x304u))); /* mov al, byte ptr [esi + 0x304] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00874790; /* je 0x874790 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov eax, dword ptr [esi + 0x344] */
    c->edx = (uint32_t)((uint32_t)(c->esi + 0x204u)); /* lea edx, [esi + 0x204] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + c->eax + 0x64u))); /* mov ecx, dword ptr [edi + eax + 0x64] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00874786u); f_00874860(c); /* call 0x874860 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov eax, dword ptr [esi + 0x344] */
    WF32((uint32_t)(c->edi + c->eax + 0x4cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + eax + 0x4c] */
L_00874790:;
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x394u))); /* fld dword ptr [esi + 0x394] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x87d1d0u))); FPOP(c); /* fcomp dword ptr [0x1000d1d0] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x44u)); /* test ah, 0x44 */
    if (!PF(c)) goto L_00874835; /* jnp 0x874835 */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x390u))); /* fld dword ptr [esi + 0x390] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x87d1d0u))); FPOP(c); /* fcomp dword ptr [0x1000d1d0] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x44u)); /* test ah, 0x44 */
    if (!PF(c)) goto L_00874835; /* jnp 0x874835 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov ecx, dword ptr [esi + 0x344] */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x284u)); /* lea eax, [esi + 0x284] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + c->ecx + 0x64u))); /* mov edx, dword ptr [edi + ecx + 0x64] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008747d3u); f_00874860(c); /* call 0x874860 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov ecx, dword ptr [esp + 0x28] */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x14], 0 */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x394u))); /* fmul dword ptr [esi + 0x394] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x10], ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov eax, dword ptr [esi + 0x344] */
    FPUSH(c, (double)(int64_t)R64((uint32_t)(c->esp + 0x10u))); /* fild qword ptr [esp + 0x10] */
    c->eax = (uint32_t)(add32(c, c->eax, c->edi)); /* add eax, edi */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x390u))); /* fmul dword ptr [esi + 0x390] */
    ST(1) = FPRES(c, ST(1) * ST(0)); FPOP(c); /* fmulp st(1) */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x384u))); /* fmul dword ptr [esi + 0x384] */
    { double v_ = ST(1); FPUSH(c, v_); } /* fld st(1) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x388u))); /* fmul dword ptr [esi + 0x388] */
    WF32((uint32_t)(c->esp + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1c] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x38cu))); /* fmul dword ptr [esi + 0x38c] */
    WF32((uint32_t)(c->esp + 0x20u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x20] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->eax))); /* fadd dword ptr [eax] */
    WF32((uint32_t)(c->eax), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fld dword ptr [esp + 0x1c] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->eax + 0x4u))); /* fadd dword ptr [eax + 4] */
    WF32((uint32_t)(c->eax + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x20u))); /* fld dword ptr [esp + 0x20] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->eax + 0x8u))); /* fadd dword ptr [eax + 8] */
    WF32((uint32_t)(c->eax + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 8] */
L_00874835:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x340u))); /* mov ecx, dword ptr [esi + 0x340] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x7cu)); /* add edi, 0x7c */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0xc], eax */
    if ((c->sf != c->of)) goto L_008746b0; /* jl 0x8746b0 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
L_00874851:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    c->esp += 8; return; /* ret 4 */
}

void f_00874860(CPU *c) { /* FUN_10004860 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edi, dword ptr [esp + 0x10] */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if ((c->sf != c->of)) goto L_00874885; /* jl 0x874885 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00874870:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + c->eax * 8))); /* mov ecx, dword ptr [edx + eax*8] */
    (void)sub32(c, c->edi, c->ecx); /* cmp edi, ecx */
    if (c->zf) goto L_008748bc; /* je 0x8748bc */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if ((c->sf != c->of)) goto L_00874890; /* jl 0x874890 */
    (void)sub32(c, c->edi, c->ecx); /* cmp edi, ecx */
    if ((c->zf || c->sf != c->of)) goto L_0087489d; /* jle 0x87489d */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub32(c, c->eax, (uint32_t)0x10u); /* cmp eax, 0x10 */
    if ((c->sf != c->of)) goto L_00874870; /* jl 0x874870 */
L_00874885:;
    FPUSH(c, (double)RF32((uint32_t)(0x87d1d0u))); /* fld dword ptr [0x1000d1d0] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 12; return; /* ret 8 */
L_00874890:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00874885; /* je 0x874885 */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + c->eax * 8 + 0xfffffffcu))); /* fld dword ptr [edx + eax*8 - 4] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 12; return; /* ret 8 */
L_0087489d:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_008748ab; /* jne 0x8748ab */
    FPUSH(c, (double)RF32((uint32_t)(0x87d1d0u))); /* fld dword ptr [0x1000d1d0] */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    goto L_008748b3; /* jmp 0x8748b3 */
L_008748ab:;
    FPUSH(c, (double)RF32((uint32_t)(c->edx + c->eax * 8 + 0xfffffffcu))); /* fld dword ptr [edx + eax*8 - 4] */
    c->esi = (uint32_t)(R32((uint32_t)(c->edx + c->eax * 8 + 0xfffffff8u))); /* mov esi, dword ptr [edx + eax*8 - 8] */
L_008748b3:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + c->eax * 8))); /* mov ecx, dword ptr [edx + eax*8] */
    (void)sub32(c, c->esi, c->ecx); /* cmp esi, ecx */
    if (!c->zf) goto L_008748c5; /* jne 0x8748c5 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
L_008748bc:;
    FPUSH(c, (double)RF32((uint32_t)(c->edx + c->eax * 8 + 0x4u))); /* fld dword ptr [edx + eax*8 + 4] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 12; return; /* ret 8 */
L_008748c5:;
    FPUSH(c, (double)RF32((uint32_t)(c->edx + c->eax * 8 + 0x4u))); /* fld dword ptr [edx + eax*8 + 4] */
    c->edi = (uint32_t)(sub32(c, c->edi, c->esi)); /* sub edi, esi */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->esi)); /* sub ecx, esi */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x10], edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    ST(0) = FPRES(c, ST(0) - ST(1)); /* fsub st(1) */
    ST(0) = FPRES(c, ST(0) * (double)(int32_t)R32((uint32_t)(c->esp + 0xcu))); /* fimul dword ptr [esp + 0xc] */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0xc], ecx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    ST(0) = FPRES(c, FDIV(c, ST(0), (double)(int32_t)R32((uint32_t)(c->esp + 0x8u)))); /* fidiv dword ptr [esp + 8] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    c->esp += 12; return; /* ret 8 */
}

void f_008748f0(CPU *c) { /* FUN_100048f0 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x108u)); /* sub esp, 0x108 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x114u))); /* mov ebx, dword ptr [esp + 0x114] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x114u))); /* mov ebp, dword ptr [esp + 0x114] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W8((uint32_t)(c->esp + 0x13u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esp + 0x13], 0 */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
L_0087490f:;
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    W32((uint32_t)(c->ebx + c->edi * 8 + 0x4u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ebx + edi*8 + 4], 0 */
    W32((uint32_t)(c->ebx + c->edi * 8), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [ebx + edi*8], 0xffffffff */
    if (!c->zf) goto L_00874958; /* jne 0x874958 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x128u))); /* mov edx, dword ptr [esp + 0x128] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov eax, dword ptr [ebp] */
    { uint32_t v_ = 0x87e3ecu; PUSH32(c, v_); } /* push 0x1000e3ec */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x18u)); /* lea ecx, [esp + 0x18] */
    { uint32_t v_ = 0x104u; PUSH32(c, v_); } /* push 0x104 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x130u))); /* mov ecx, dword ptr [esp + 0x130] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x00874949u); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_008749d5; /* je 0x8749d5 */
    W8((uint32_t)(c->esp + 0x13u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esp + 0x13], 1 */
    goto L_0087497a; /* jmp 0x87497a */
L_00874958:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x128u))); /* mov ecx, dword ptr [esp + 0x128] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov edx, dword ptr [ebp] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea eax, [esp + 0x14] */
    { uint32_t v_ = 0x104u; PUSH32(c, v_); } /* push 0x104 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x12cu))); /* mov eax, dword ptr [esp + 0x12c] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x1cu)); PUSH32(c, 0x0087497au); call_indirect(c, t_); } /* call dword ptr [edx + 0x1c] */
L_0087497a:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_008749d5; /* je 0x8749d5 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x14u))); /* mov al, byte ptr [esp + 0x14] */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_008749ba; /* je 0x8749ba */
L_00874988:;
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x2cu); /* cmp al, 0x2c */
    if (c->zf) goto L_00874997; /* je 0x874997 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + c->esi + 0x15u))); /* mov al, byte ptr [esp + esi + 0x15] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00874988; /* jne 0x874988 */
    goto L_008749ba; /* jmp 0x8749ba */
L_00874997:;
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea ecx, [esp + 0x14] */
    W8((uint32_t)(c->esp + c->esi + 0x14u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esp + esi + 0x14], 0 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x008749a6u); f_00875734(c); /* call 0x875734 */
    WF32((uint32_t)(c->ebx + c->edi * 8 + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebx + edi*8 + 4] */
    c->edx = (uint32_t)((uint32_t)(c->esp + c->esi + 0x19u)); /* lea edx, [esp + esi + 0x19] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x008749b4u); f_008757df(c); /* call 0x8757df */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    W32((uint32_t)(c->ebx + c->edi * 8), (uint32_t)(c->eax)); /* mov dword ptr [ebx + edi*8], eax */
L_008749ba:;
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->edi, (uint32_t)0x10u); /* cmp edi, 0x10 */
    if ((c->sf != c->of)) goto L_0087490f; /* jl 0x87490f */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x13u))); /* mov al, byte ptr [esp + 0x13] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x108u)); /* add esp, 0x108 */
    c->esp += 20; return; /* ret 0x10 */
L_008749d5:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x13u))); /* mov al, byte ptr [esp + 0x13] */
    W32((uint32_t)(c->ebx + c->edi * 8), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [ebx + edi*8], 0xffffffff */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x108u)); /* add esp, 0x108 */
    c->esp += 20; return; /* ret 0x10 */
}

void f_008749f0(CPU *c) { /* PTR_008749f0 */
    PREEMPT_POLL(c);
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x18u))); /* fmul dword ptr [esp + 0x18] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x14u))); /* fmul dword ptr [esp + 0x14] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edx, dword ptr [esp + 0x14] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fld dword ptr [esp + 0x1c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fmul dword ptr [esp + 0x1c] */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x364u)); /* lea eax, [esi + 0x364] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov ecx, dword ptr [esp + 0x18] */
    FCOM(c, ST(0), RF64((uint32_t)(0x87d1c0u))); /* fcom qword ptr [0x1000d1c0] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 4], edx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x44u)); /* test ah, 0x44 */
    if (PF(c)) goto L_00874a52; /* jp 0x874a52 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x10], 0 */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x14], 0 */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x18], 0 */
    goto L_00874a78; /* jmp 0x874a78 */
L_00874a52:;
    ST(0) = FPRES(c, sqrt(ST(0))); /* fsqrt  */
    ST(0) = FPRES(c, FDIV(c, RF64((uint32_t)(0x87d1b8u)), ST(0))); /* fdivr qword ptr [0x1000d1b8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fld dword ptr [esp + 0x1c] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x20u))); /* fld dword ptr [esp + 0x20] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x24u))); /* fld dword ptr [esp + 0x24] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
L_00874a78:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ecx, dword ptr [esp + 0x14] */
    c->ebp = (uint32_t)((uint32_t)(c->esi + 0x370u)); /* lea ebp, [esi + 0x370] */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->edx = (uint32_t)(c->ebp); /* mov edx, ebp */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    W32((uint32_t)(c->edx), (uint32_t)(c->eax)); /* mov dword ptr [edx], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [edx + 4], ecx */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [edx + 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x340u))); /* mov eax, dword ptr [esi + 0x340] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_00874b44; /* jle 0x874b44 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
L_00874aa9:;
    PUSH32(c, 0x00874aaeu); f_00875794(c); /* call 0x875794 */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x20], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov ecx, dword ptr [esi + 0x344] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x20u))); /* fild dword ptr [esp + 0x20] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x87d1ccu))); /* fmul dword ptr [0x1000d1cc] */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(0x87d1c8u)) - ST(0)); /* fsubr dword ptr [0x1000d1c8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x37cu))); /* fmul dword ptr [esi + 0x37c] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ebp))); /* fadd dword ptr [ebp] */
    WF32((uint32_t)(c->ecx + c->edi + 0xcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [ecx + edi + 0xc] */
    PUSH32(c, 0x00874adau); f_00875794(c); /* call 0x875794 */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x20], eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov edx, dword ptr [esi + 0x344] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x20u))); /* fild dword ptr [esp + 0x20] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x87d1ccu))); /* fmul dword ptr [0x1000d1cc] */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(0x87d1c8u)) - ST(0)); /* fsubr dword ptr [0x1000d1c8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x37cu))); /* fmul dword ptr [esi + 0x37c] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x374u))); /* fadd dword ptr [esi + 0x374] */
    WF32((uint32_t)(c->edx + c->edi + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edx + edi + 0x10] */
    PUSH32(c, 0x00874b09u); f_00875794(c); /* call 0x875794 */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x20], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x344u))); /* mov eax, dword ptr [esi + 0x344] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x20u))); /* fild dword ptr [esp + 0x20] */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x7cu)); /* add edi, 0x7c */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x87d1ccu))); /* fmul dword ptr [0x1000d1cc] */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(0x87d1c8u)) - ST(0)); /* fsubr dword ptr [0x1000d1c8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x37cu))); /* fmul dword ptr [esi + 0x37c] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x378u))); /* fadd dword ptr [esi + 0x378] */
    WF32((uint32_t)(c->eax + c->edi + 0xffffff98u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + edi - 0x68] */
    (void)sub32(c, c->ebx, R32((uint32_t)(c->esi + 0x340u))); /* cmp ebx, dword ptr [esi + 0x340] */
    if ((c->sf != c->of)) goto L_00874aa9; /* jl 0x874aa9 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_00874b44:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 28; return; /* ret 0x18 */
}

void f_00874b50(CPU *c) { /* PTR_00874b50 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->edx = (uint32_t)((uint32_t)(c->ebx + 0x480u)); /* lea edx, [ebx + 0x480] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->esi = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea esi, [esp + 0x14] */
    c->edi = (uint32_t)(c->edx); /* mov edi, edx */
    W8((uint32_t)(c->ebx + 0x474u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ebx + 0x474], 1 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov ecx, dword ptr [esp + 0x2c] */
    c->esi = (uint32_t)((uint32_t)(c->ebx + 0x498u)); /* lea esi, [ebx + 0x498] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov ecx, dword ptr [esp + 0x34] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 4], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x38u))); /* mov ecx, dword ptr [esp + 0x38] */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    c->eax = (uint32_t)((uint32_t)(c->ebx + 0x4a4u)); /* lea eax, [ebx + 0x4a4] */
    c->ecx = (uint32_t)((uint32_t)(c->ebx + 0x370u)); /* lea ecx, [ebx + 0x370] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov ebp, dword ptr [ecx] */
    W32((uint32_t)(c->edi), (uint32_t)(c->ebp)); /* mov dword ptr [edi], ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ebp, dword ptr [ecx + 4] */
    W32((uint32_t)(c->edi + 0x4u), (uint32_t)(c->ebp)); /* mov dword ptr [edi + 4], ebp */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov ecx, dword ptr [ecx + 8] */
    W32((uint32_t)(c->edi + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [edi + 8], ecx */
    FPUSH(c, (double)RF32((uint32_t)(c->esi))); /* fld dword ptr [esi] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->eax))); /* fadd dword ptr [eax] */
    WF32((uint32_t)(c->esp + 0x30u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x30] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x4u))); /* fld dword ptr [esi + 4] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->eax + 0x4u))); /* fadd dword ptr [eax + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov ecx, dword ptr [esp + 0x30] */
    WF32((uint32_t)(c->esp + 0x34u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x34] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x8u))); /* fld dword ptr [esi + 8] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->eax + 0x8u))); /* fadd dword ptr [eax + 8] */
    c->eax = (uint32_t)((uint32_t)(c->ebx + 0x4b0u)); /* lea eax, [ebx + 0x4b0] */
    W32((uint32_t)(c->ebx + 0x4b0u), (uint32_t)(c->ecx)); /* mov dword ptr [ebx + 0x4b0], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov ecx, dword ptr [esp + 0x34] */
    WF32((uint32_t)(c->esp + 0x38u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x38] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 4], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x38u))); /* mov ecx, dword ptr [esp + 0x38] */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x308u))); /* mov ecx, dword ptr [ebx + 0x308] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x64u)); PUSH32(c, 0x00874bf0u); call_indirect(c, t_); } /* call dword ptr [eax + 0x64] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00874c62; /* je 0x874c62 */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x40u))); /* fld dword ptr [eax + 0x40] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x8u))); /* fmul dword ptr [esi + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x30u))); /* fld dword ptr [eax + 0x30] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x4u))); /* fmul dword ptr [esi + 4] */
    c->ecx = (uint32_t)((uint32_t)(c->ebx + 0x364u)); /* lea ecx, [ebx + 0x364] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esi))); /* fld dword ptr [esi] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x20u))); /* fmul dword ptr [eax + 0x20] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->eax + 0x50u))); /* fadd dword ptr [eax + 0x50] */
    WF32((uint32_t)(c->esp + 0x2cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x2c] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x24u))); /* fld dword ptr [eax + 0x24] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi))); /* fmul dword ptr [esi] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x44u))); /* fld dword ptr [eax + 0x44] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x8u))); /* fmul dword ptr [esi + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov edx, dword ptr [esp + 0x2c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x34u))); /* fld dword ptr [eax + 0x34] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x4u))); /* fmul dword ptr [esi + 4] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->eax + 0x54u))); /* fadd dword ptr [eax + 0x54] */
    WF32((uint32_t)(c->esp + 0x30u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x30] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x28u))); /* fld dword ptr [eax + 0x28] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi))); /* fmul dword ptr [esi] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x48u))); /* fld dword ptr [eax + 0x48] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x8u))); /* fmul dword ptr [esi + 8] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x38u))); /* fld dword ptr [eax + 0x38] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x4u))); /* fmul dword ptr [esi + 4] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->eax + 0x58u))); /* fadd dword ptr [eax + 0x58] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov eax, dword ptr [esp + 0x30] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 4], eax */
    WF32((uint32_t)(c->esp + 0x34u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x34] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov edx, dword ptr [esp + 0x34] */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 8], edx */
L_00874c62:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x340u))); /* mov eax, dword ptr [ebx + 0x340] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_00874d10; /* jle 0x874d10 */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_00874c74:;
    PUSH32(c, 0x00874c79u); f_00875794(c); /* call 0x875794 */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x2c], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x344u))); /* mov eax, dword ptr [ebx + 0x344] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x2cu))); /* fild dword ptr [esp + 0x2c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x87d1ccu))); /* fmul dword ptr [0x1000d1cc] */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(0x87d1c8u)) - ST(0)); /* fsubr dword ptr [0x1000d1c8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ebx + 0x3bcu))); /* fmul dword ptr [ebx + 0x3bc] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ebx + 0x364u))); /* fadd dword ptr [ebx + 0x364] */
    WF32((uint32_t)(c->esi + c->eax), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + eax] */
    PUSH32(c, 0x00874ca7u); f_00875794(c); /* call 0x875794 */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x2c], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x344u))); /* mov ecx, dword ptr [ebx + 0x344] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x2cu))); /* fild dword ptr [esp + 0x2c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x87d1ccu))); /* fmul dword ptr [0x1000d1cc] */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(0x87d1c8u)) - ST(0)); /* fsubr dword ptr [0x1000d1c8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ebx + 0x3bcu))); /* fmul dword ptr [ebx + 0x3bc] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ebx + 0x368u))); /* fadd dword ptr [ebx + 0x368] */
    WF32((uint32_t)(c->esi + c->ecx + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + ecx + 4] */
    PUSH32(c, 0x00874cd6u); f_00875794(c); /* call 0x875794 */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x2c], eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x344u))); /* mov edx, dword ptr [ebx + 0x344] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x2cu))); /* fild dword ptr [esp + 0x2c] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x7cu)); /* add esi, 0x7c */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x87d1ccu))); /* fmul dword ptr [0x1000d1cc] */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(0x87d1c8u)) - ST(0)); /* fsubr dword ptr [0x1000d1c8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ebx + 0x3bcu))); /* fmul dword ptr [ebx + 0x3bc] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ebx + 0x36cu))); /* fadd dword ptr [ebx + 0x36c] */
    WF32((uint32_t)(c->esi + c->edx + 0xffffff8cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + edx - 0x74] */
    (void)sub32(c, c->edi, R32((uint32_t)(c->ebx + 0x340u))); /* cmp edi, dword ptr [ebx + 0x340] */
    if ((c->sf != c->of)) goto L_00874c74; /* jl 0x874c74 */
L_00874d10:;
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    PUSH32(c, 0x00874d17u); f_008734b0(c); /* call 0x8734b0 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 40; return; /* ret 0x24 */
}

void f_00874d20(CPU *c) { /* FUN_10004d20 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0x470u))); /* mov al, byte ptr [ecx + 0x470] */
    c->esp += 4; return; /* ret  */
}

void f_00874d30(CPU *c) { /* PTR_00874d30 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x4u))); /* mov al, byte ptr [esp + 4] */
    W8((uint32_t)(c->ecx + 0x476u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ecx + 0x476], al */
    c->esp += 8; return; /* ret 4 */
}

void f_00874d40(CPU *c) { /* FUN_10004d40 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = 0x35au; PUSH32(c, v_); } /* push 0x35a */
    { uint32_t v_ = 0x87e390u; PUSH32(c, v_); } /* push 0x1000e390 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x3d8u))); /* mov eax, dword ptr [esi + 0x3d8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x3d4u))); /* mov ecx, dword ptr [esi + 0x3d4] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    W8((uint32_t)(c->esi + 0x3dcu), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esi + 0x3dc], 1 */
    W32((uint32_t)(c->esi + 0x3d8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x3d8], eax */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea eax, [eax + eax*2] */
    c->eax = (uint32_t)(shl32(c, c->eax, 2)); /* shl eax, 2 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00874d74u); f_00871070(c); /* call 0x871070 */
    W32((uint32_t)(c->esi + 0x3d4u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x3d4], eax */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0x3d8u))); /* mov esi, dword ptr [esi + 0x3d8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov ecx, dword ptr [esp + 0x18] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->edx = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea edx, [esi + esi*2] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->edx * 4 + 0xfffffff4u)); /* lea eax, [eax + edx*4 - 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 4], edx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    c->esp += 16; return; /* ret 0xc */
}

void f_00874db0(CPU *c) { /* FUN_10004db0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    c->edx = (uint32_t)(shl32(c, c->edx, 5)); /* shl edx, 5 */
    c->edx = (uint32_t)(sub32(c, c->edx, c->eax)); /* sub edx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x344u))); /* mov eax, dword ptr [ecx + 0x344] */
    c->edx = (uint32_t)(shl32(c, c->edx, 2)); /* shl edx, 2 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ecx + 0x3d8u))); /* mov edi, dword ptr [ecx + 0x3d8] */
    c->esi = (uint32_t)((uint32_t)(c->edx + c->eax)); /* lea esi, [edx + eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + c->eax + 0x70u))); /* mov eax, dword ptr [edx + eax + 0x70] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->cf) goto L_00874ebc; /* jae 0x874ebc */
    c->edi = (uint32_t)(R32((uint32_t)(c->ecx + 0x3d4u))); /* mov edi, dword ptr [ecx + 0x3d4] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea eax, [eax + eax*2] */
    c->eax = (uint32_t)((uint32_t)(c->edi + c->eax * 4)); /* lea eax, [edi + eax*4] */
    c->edi = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edi, dword ptr [eax] */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x14], edi */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esi))); /* fsub dword ptr [esi] */
    c->edi = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov edi, dword ptr [eax + 4] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x18], edi */
    WF32((uint32_t)(c->esp + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esi + 0x4u))); /* fsub dword ptr [esi + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x1c], eax */
    WF32((uint32_t)(c->esp + 0xcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xc] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fld dword ptr [esp + 0x1c] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esi + 0x8u))); /* fsub dword ptr [esi + 8] */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); /* fst dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x10u))); /* fmul dword ptr [esp + 0x10] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xcu))); /* fld dword ptr [esp + 0xc] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xcu))); /* fmul dword ptr [esp + 0xc] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x8u))); /* fld dword ptr [esp + 8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x8u))); /* fmul dword ptr [esp + 8] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    FCOM(c, ST(0), RF64((uint32_t)(0x87d1c0u))); /* fcom qword ptr [0x1000d1c0] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x44u)); /* test ah, 0x44 */
    if (PF(c)) goto L_00874e5f; /* jp 0x874e5f */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x14], 0 */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x18], 0 */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x1c], 0 */
    goto L_00874e85; /* jmp 0x874e85 */
L_00874e5f:;
    ST(0) = FPRES(c, sqrt(ST(0))); /* fsqrt  */
    ST(0) = FPRES(c, FDIV(c, RF64((uint32_t)(0x87d1b8u)), ST(0))); /* fdivr qword ptr [0x1000d1b8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x8u))); /* fld dword ptr [esp + 8] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xcu))); /* fld dword ptr [esp + 0xc] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF32((uint32_t)(c->esp + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1c] */
L_00874e85:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xcu)); /* add esi, 0xc */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov eax, dword ptr [esp + 0x1c] */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 8], eax */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->ecx + 0x3e0u))); FPOP(c); /* fcomp dword ptr [ecx + 0x3e0] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00874ebc; /* jp 0x874ebc */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x344u))); /* mov ecx, dword ptr [ecx + 0x344] */
    c->eax = (uint32_t)((uint32_t)(c->edx + c->ecx + 0x70u)); /* lea eax, [edx + ecx + 0x70] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + c->ecx + 0x70u))); /* mov ecx, dword ptr [edx + ecx + 0x70] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
L_00874ebc:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    c->esp += 8; return; /* ret 4 */
}

void f_00874ed0(CPU *c) { /* FUN_10004ed0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W8((uint32_t)(c->ecx + 0x3ecu), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ecx + 0x3ec], 1 */
    c->edi = (uint32_t)((uint32_t)(c->ecx + 0x3f0u)); /* lea edi, [ecx + 0x3f0] */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->esi = (uint32_t)((uint32_t)(c->esp + 0xcu)); /* lea esi, [esp + 0xc] */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 28; return; /* ret 0x18 */
}

void f_00874ef0(CPU *c) { /* FUN_10004ef0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = 0x378u; PUSH32(c, v_); } /* push 0x378 */
    { uint32_t v_ = 0x87e390u; PUSH32(c, v_); } /* push 0x1000e390 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x318u))); /* mov edx, dword ptr [esi + 0x318] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x314u))); /* mov ecx, dword ptr [esi + 0x314] */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    W32((uint32_t)(c->esi + 0x318u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x318], edx */
    c->eax = (uint32_t)(shl32(c, c->eax, 2)); /* shl eax, 2 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00874f1cu); f_00871070(c); /* call 0x871070 */
    { uint32_t v_ = 0x379u; PUSH32(c, v_); } /* push 0x379 */
    { uint32_t v_ = 0x87e390u; PUSH32(c, v_); } /* push 0x1000e390 */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    W32((uint32_t)(c->esi + 0x314u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x314], eax */
    PUSH32(c, 0x00874f33u); f_00871050(c); /* call 0x871050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00874f49; /* je 0x874f49 */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x87d1d8u)); /* mov dword ptr [eax], 0x1000d1d8 */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [eax + 4], 0 */
    goto L_00874f4b; /* jmp 0x874f4b */
L_00874f49:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00874f4b:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x318u))); /* mov edx, dword ptr [esi + 0x318] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x314u))); /* mov ecx, dword ptr [esi + 0x314] */
    W32((uint32_t)(c->ecx + c->edx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ecx + edx*4 - 4], eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x318u))); /* mov edx, dword ptr [esi + 0x318] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x314u))); /* mov eax, dword ptr [esi + 0x314] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + c->edx * 4 + 0xfffffffcu))); /* mov ecx, dword ptr [eax + edx*4 - 4] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [ecx + 4], esi */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x318u))); /* mov edx, dword ptr [esi + 0x318] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x314u))); /* mov eax, dword ptr [esi + 0x314] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->edx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [eax + edx*4 - 4] */
    c->esp += 4; return; /* ret  */
}

void f_00874f80(CPU *c) { /* FUN_10004f80 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x318u))); /* mov eax, dword ptr [esi + 0x318] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->cf || c->zf)) goto L_00874ffe; /* jbe 0x874ffe */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ebx, dword ptr [esp + 0x10] */
L_00874f95:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x314u))); /* mov ecx, dword ptr [esi + 0x314] */
    (void)sub32(c, R32((uint32_t)(c->ecx + c->edi * 4)), c->ebx); /* cmp dword ptr [ecx + edi*4], ebx */
    if (!c->zf) goto L_00874ff2; /* jne 0x874ff2 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (!c->cf) goto L_00874fbe; /* jae 0x874fbe */
L_00874fa5:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x314u))); /* mov eax, dword ptr [esi + 0x314] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + c->edi * 4))); /* mov edx, dword ptr [eax + edi*4] */
    W32((uint32_t)(c->eax + c->edi * 4 + 0xfffffffcu), (uint32_t)(c->edx)); /* mov dword ptr [eax + edi*4 - 4], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x318u))); /* mov eax, dword ptr [esi + 0x318] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_00874fa5; /* jb 0x874fa5 */
L_00874fbe:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x318u))); /* mov eax, dword ptr [esi + 0x318] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x314u))); /* mov edx, dword ptr [esi + 0x314] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    { uint32_t v_ = 0x38bu; PUSH32(c, v_); } /* push 0x38b */
    { uint32_t v_ = 0x87e390u; PUSH32(c, v_); } /* push 0x1000e390 */
    W32((uint32_t)(c->esi + 0x318u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x318], eax */
    c->ecx = (uint32_t)((uint32_t)(c->eax * 4)); /* lea ecx, [eax*4] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00874fe9u); f_00871070(c); /* call 0x871070 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    W32((uint32_t)(c->esi + 0x314u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x314], eax */
L_00874ff2:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x318u))); /* mov eax, dword ptr [esi + 0x318] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_00874f95; /* jb 0x874f95 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
L_00874ffe:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00875010(CPU *c) { /* FUN_10005010 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx), (uint32_t)((uint32_t)0x87d190u)); /* mov dword ptr [ecx], 0x1000d190 */
    c->esp += 4; return; /* ret  */
}

void f_00875020(CPU *c) { /* PTR_00875020 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x4u))); /* mov al, byte ptr [esp + 4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x87d190u)); /* mov dword ptr [esi], 0x1000d190 */
    if (c->zf) goto L_0087503a; /* je 0x87503a */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00875037u); f_00871030(c); /* call 0x871030 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_0087503a:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00875040(CPU *c) { /* PTR_00875040 */
    PREEMPT_POLL(c);
    W8((uint32_t)(c->ecx + 0x470u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ecx + 0x470], 1 */
    c->esp += 4; return; /* ret  */
}

void f_00875050(CPU *c) { /* PTR_00875050 */
    PREEMPT_POLL(c);
    W8((uint32_t)(c->ecx + 0x471u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [ecx + 0x471], 0 */
    c->esp += 4; return; /* ret  */
}

void f_00875060(CPU *c) { /* PTR_00875060 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    W32((uint32_t)(c->ecx + 0x3d0u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 0x3d0], eax */
    c->esp += 8; return; /* ret 4 */
}

void f_00875070(CPU *c) { /* PTR_00875070 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ecx, dword ptr [ecx + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_0087507c; /* je 0x87507c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4u)); switch (t_) {  default: jump_indirect(c, t_, 0x00875079u); return; } } /* jmp dword ptr [eax + 4] */
L_0087507c:;
    c->esp += 4; return; /* ret  */
}

void f_00875080(CPU *c) { /* PTR_00875080 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ecx, dword ptr [ecx + 4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_008750bf; /* je 0x8750bf */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov esi, dword ptr [esp + 0x14] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    c->edx = (uint32_t)(c->esp); /* mov edx, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    W32((uint32_t)(c->edx), (uint32_t)(c->esi)); /* mov dword ptr [edx], esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov esi, dword ptr [esp + 0x30] */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [edx + 4], esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov esi, dword ptr [esp + 0x34] */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [edx + 8], esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov esi, dword ptr [esp + 0x20] */
    c->edx = (uint32_t)(c->esp); /* mov edx, esp */
    W32((uint32_t)(c->edx), (uint32_t)(c->esi)); /* mov dword ptr [edx], esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov esi, dword ptr [esp + 0x24] */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [edx + 4], esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov esi, dword ptr [esp + 0x28] */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [edx + 8], esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x008750bfu); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
L_008750bf:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 28; return; /* ret 0x18 */
}

void f_008750d0(CPU *c) { /* PTR_008750d0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov eax, dword ptr [ecx + 4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (c->zf) goto L_00875109; /* je 0x875109 */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov esi, dword ptr [esp + 0x24] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    c->ecx = (uint32_t)(c->esp); /* mov ecx, esp */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    W32((uint32_t)(c->ecx), (uint32_t)(c->esi)); /* mov dword ptr [ecx], esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x4cu))); /* mov esi, dword ptr [esp + 0x4c] */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [ecx + 4], esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x50u))); /* mov esi, dword ptr [esp + 0x50] */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ecx + 8], esi */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->esi = (uint32_t)((uint32_t)(c->esp + 0x30u)); /* lea esi, [esp + 0x30] */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x00875109u); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
L_00875109:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 40; return; /* ret 0x24 */
}

void f_00875110(CPU *c) { /* PTR_00875110 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ecx, dword ptr [ecx + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_0087511c; /* je 0x87511c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x10u)); switch (t_) {  default: jump_indirect(c, t_, 0x00875119u); return; } } /* jmp dword ptr [eax + 0x10] */
L_0087511c:;
    c->esp += 8; return; /* ret 4 */
}

void f_00875120(CPU *c) { /* PTR_00875120 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ecx, dword ptr [ecx + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_0087512c; /* je 0x87512c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); switch (t_) {  default: jump_indirect(c, t_, 0x00875129u); return; } } /* jmp dword ptr [eax + 0x14] */
L_0087512c:;
    c->esp += 8; return; /* ret 4 */
}

void f_00875130(CPU *c) { /* PTR_00875130 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ecx, dword ptr [ecx + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_0087513c; /* je 0x87513c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x18u)); switch (t_) {  default: jump_indirect(c, t_, 0x00875139u); return; } } /* jmp dword ptr [eax + 0x18] */
L_0087513c:;
    c->esp += 4; return; /* ret  */
}

void f_00875140(CPU *c) { /* PTR_00875140 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ecx, dword ptr [ecx + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00875154; /* je 0x875154 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 4], edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x1cu)); switch (t_) {  default: jump_indirect(c, t_, 0x00875151u); return; } } /* jmp dword ptr [eax + 0x1c] */
L_00875154:;
    c->esp += 8; return; /* ret 4 */
}

void f_00875160(CPU *c) { /* FUN_10005160 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00875168u); f_00875180(c); /* call 0x875180 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00875178; /* je 0x875178 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00875175u); f_00871030(c); /* call 0x871030 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00875178:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00875180(CPU *c) { /* FUN_10005180 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x87c348u; PUSH32(c, v_); } /* push 0x1000c348 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 4], esi */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x87d1d8u)); /* mov dword ptr [esi], 0x1000d1d8 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x10], 0 */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_008751b8; /* je 0x8751b8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008751b8u); f_00874f80(c); /* call 0x874f80 */
L_008751b8:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x87d190u)); /* mov dword ptr [esi], 0x1000d190 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_008751d0(CPU *c) { /* FUN_100051d0 */
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
    { uint32_t t_ = c->eax; switch (t_) {  default: jump_indirect(c, t_, 0x008751fbu); return; } } /* jmp eax */
}

void f_008751fd(CPU *c) { /* PTR_008751fd */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 12; return; /* ret 8 */
}

void f_00875204(CPU *c) { /* FUN_10005204 */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { guest_lock(); { uint32_t t0_ = R32((uint32_t)(c->esp)), t1_ = c->eax; W32((uint32_t)(c->esp), (uint32_t)(t1_)); c->eax = (uint32_t)(t0_); } guest_unlock(); } /* xchg dword ptr [esp], eax */
    { uint32_t t_ = c->eax; switch (t_) {  default: jump_indirect(c, t_, 0x00875209u); return; } } /* jmp eax */
}

void f_0087520b(CPU *c) { /* FUN_1000520b */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { guest_lock(); { uint32_t t0_ = R32((uint32_t)(c->esp)), t1_ = c->eax; W32((uint32_t)(c->esp), (uint32_t)(t1_)); c->eax = (uint32_t)(t0_); } guest_unlock(); } /* xchg dword ptr [esp], eax */
    { uint32_t t_ = c->eax; switch (t_) {  default: jump_indirect(c, t_, 0x00875210u); return; } } /* jmp eax */
}

void f_00875212(CPU *c) { /* FUN_10005212 */
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
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x87523au)); /* mov dword ptr [ebp - 4], 0x1000523a */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x0087523au); f_0087c240(c); /* call 0x87c240 */
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

void f_0087523a(CPU *c) { /* PTR_0087523a */
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

void f_00875261(CPU *c) { /* FUN_10005261 */
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
    PUSH32(c, 0x00875287u); f_00875a13(c); /* call 0x875a13 */
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

void f_00875297(CPU *c) { /* FUN_10005297 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x14u)); /* sub esp, 0x14 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffecu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x14], 0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)((uint32_t)0x8752ebu)); /* mov dword ptr [ebp - 0x10], 0x100052eb */
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
    PUSH32(c, 0x008752dcu); f_00876230(c); /* call 0x876230 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->eax)); /* mov dword ptr fs:[0], eax */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008752eb(CPU *c) { /* FUN_100052eb */
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
    PUSH32(c, 0x0087530bu); f_00875a13(c); /* call 0x875a13 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00875310(CPU *c) { /* FUN_10005310 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x34u)); /* sub esp, 0x34 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffd8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x28], 0 */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)((uint32_t)0x8753c6u)); /* mov dword ptr [ebp - 0x24], 0x100053c6 */
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
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)((uint32_t)0x875398u)); /* mov dword ptr [ebp - 0x10], 0x10005398 */
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
    PUSH32(c, 0x0087538fu); f_00876301(c); /* call 0x876301 */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x68u)); PUSH32(c, 0x00875392u); call_indirect(c, t_); } /* call dword ptr [eax + 0x68] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffccu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x34], 0 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if (c->zf) goto L_008753b5; /* je 0x8753b5 */
    c->ebx = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov ebx, dword ptr fs:[0] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ebx, dword ptr [ebp - 0x28] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ebx)); /* mov dword ptr fs:[0], ebx */
    goto L_008753be; /* jmp 0x8753be */
L_008753b5:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->eax)); /* mov dword ptr fs:[0], eax */
L_008753be:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffccu))); /* mov eax, dword ptr [ebp - 0x34] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00875398(CPU *c) { /* PTR_00875398 */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if (c->zf) goto L_008753b5; /* je 0x8753b5 */
    c->ebx = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov ebx, dword ptr fs:[0] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ebx, dword ptr [ebp - 0x28] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ebx)); /* mov dword ptr fs:[0], ebx */
    goto L_008753be; /* jmp 0x8753be */
L_008753b5:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->eax)); /* mov dword ptr fs:[0], eax */
L_008753be:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffccu))); /* mov eax, dword ptr [ebp - 0x34] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008753c6(CPU *c) { /* FUN_100053c6 */
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
    if (c->zf) goto L_008753e9; /* je 0x8753e9 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->eax + 0x24u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [eax + 0x24], 1 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_00875436; /* jmp 0x875436 */
L_008753e9:;
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
    PUSH32(c, 0x00875410u); f_00875a13(c); /* call 0x875a13 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x24u)), (uint32_t)0x0u); /* cmp dword ptr [eax + 0x24], 0 */
    if (!c->zf) goto L_00875427; /* jne 0x875427 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x00875427u); f_00875212(c); /* call 0x875212 */
L_00875427:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ebx, dword ptr [ebp + 0xc] */
    c->esp = (uint32_t)(R32((uint32_t)(c->ebx + 0x1cu))); /* mov esp, dword ptr [ebx + 0x1c] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ebx + 0x20u))); /* mov ebp, dword ptr [ebx + 0x20] */
    { uint32_t t_ = R32((uint32_t)(c->ebx + 0x18u)); switch (t_) {  default: jump_indirect(c, t_, 0x00875430u); return; } } /* jmp dword ptr [ebx + 0x18] */
L_00875436:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_0087543b(CPU *c) { /* FUN_1000543b */
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
    if ((c->sf != c->of)) goto L_00875492; /* jl 0x875492 */
L_00875459:;
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (!c->zf) goto L_00875463; /* jne 0x875463 */
    PUSH32(c, 0x00875463u); f_00876469(c); /* call 0x876469 */
L_00875463:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi * 4)); /* lea eax, [esi + esi*4] */
    (void)sub32(c, R32((uint32_t)(c->ebx + c->eax * 4 + 0x4u)), c->ecx); /* cmp dword ptr [ebx + eax*4 + 4], ecx */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->eax * 4)); /* lea eax, [ebx + eax*4] */
    if ((c->sf == c->of)) goto L_00875478; /* jge 0x875478 */
    (void)sub32(c, c->ecx, R32((uint32_t)(c->eax + 0x8u))); /* cmp ecx, dword ptr [eax + 8] */
    if ((c->zf || c->sf != c->of)) goto L_0087547d; /* jle 0x87547d */
L_00875478:;
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (!c->zf) goto L_00875489; /* jne 0x875489 */
L_0087547d:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
L_00875489:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    if ((c->sf == c->of)) goto L_00875459; /* jge 0x875459 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
L_00875492:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov ecx, dword ptr [ebp + 0x14] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    W32((uint32_t)(c->ecx), (uint32_t)(c->esi)); /* mov dword ptr [ecx], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov ecx, dword ptr [ebp + 0x18] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    (void)sub32(c, c->eax, R32((uint32_t)(c->edi + 0xcu))); /* cmp eax, dword ptr [edi + 0xc] */
    if ((!c->cf && !c->zf)) goto L_008754a6; /* ja 0x8754a6 */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if ((c->cf || c->zf)) goto L_008754ab; /* jbe 0x8754ab */
L_008754a6:;
    PUSH32(c, 0x008754abu); f_00876469(c); /* call 0x876469 */
L_008754ab:;
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi * 4)); /* lea eax, [esi + esi*4] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->eax * 4)); /* lea eax, [ebx + eax*4] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008754b8(CPU *c) { /* __global_unwind2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x8754d0u; PUSH32(c, v_); } /* push 0x100054d0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x008754d0u); f_0087c240(c); /* call 0x87c240 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_008754d0(CPU *c) { /* PTR_008754d0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_008754d8(CPU *c) { /* PTR_008754d8 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->ecx + 0x4u)) & (uint32_t)0x6u)); /* test dword ptr [ecx + 4], 6 */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    if (c->zf) goto L_008754f9; /* je 0x8754f9 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    W32((uint32_t)(c->edx), (uint32_t)(c->eax)); /* mov dword ptr [edx], eax */
    c->eax = (uint32_t)((uint32_t)0x3u); /* mov eax, 3 */
L_008754f9:;
    c->esp += 4; return; /* ret  */
}

void f_008754fa(CPU *c) { /* __local_unwind2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0xfffffffeu; PUSH32(c, v_); } /* push -2 */
    { uint32_t v_ = 0x8754d8u; PUSH32(c, v_); } /* push 0x100054d8 */
    { uint32_t v_ = R32((uint32_t)(0x0u + c->fs_base)); PUSH32(c, v_); } /* push dword ptr fs:[0] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
L_00875517:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov eax, dword ptr [esp + 0x20] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ebx, dword ptr [eax + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + 0xcu))); /* mov esi, dword ptr [eax + 0xc] */
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (c->zf) goto L_00875554; /* je 0x875554 */
    (void)sub32(c, c->esi, R32((uint32_t)(c->esp + 0x24u))); /* cmp esi, dword ptr [esp + 0x24] */
    if (c->zf) goto L_00875554; /* je 0x875554 */
    c->esi = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea esi, [esi + esi*2] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + c->esi * 4))); /* mov ecx, dword ptr [ebx + esi*4] */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 8], ecx */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0xc], ecx */
    (void)sub32(c, R32((uint32_t)(c->ebx + c->esi * 4 + 0x4u)), (uint32_t)0x0u); /* cmp dword ptr [ebx + esi*4 + 4], 0 */
    if (!c->zf) goto L_00875552; /* jne 0x875552 */
    { uint32_t v_ = 0x101u; PUSH32(c, v_); } /* push 0x101 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + c->esi * 4 + 0x8u))); /* mov eax, dword ptr [ebx + esi*4 + 8] */
    PUSH32(c, 0x0087554eu); f_0087558e(c); /* call 0x87558e */
    { uint32_t t_ = R32((uint32_t)(c->ebx + c->esi * 4 + 0x8u)); PUSH32(c, 0x00875552u); call_indirect(c, t_); } /* call dword ptr [ebx + esi*4 + 8] */
L_00875552:;
    goto L_00875517; /* jmp 0x875517 */
L_00875554:;
    { uint32_t v_ = R32(c->esp); c->esp += 4; W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(v_)); } /* pop dword ptr fs:[0] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00875562(CPU *c) { /* __abnormal_termination */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov ecx, dword ptr fs:[0] */
    (void)sub32(c, R32((uint32_t)(c->ecx + 0x4u)), (uint32_t)0x8754d8u); /* cmp dword ptr [ecx + 4], 0x100054d8 */
    if (!c->zf) goto L_00875584; /* jne 0x875584 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov edx, dword ptr [ecx + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edx + 0xcu))); /* mov edx, dword ptr [edx + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->ecx + 0x8u)), c->edx); /* cmp dword ptr [ecx + 8], edx */
    if (!c->zf) goto L_00875584; /* jne 0x875584 */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
L_00875584:;
    c->esp += 4; return; /* ret  */
}

void f_00875585(CPU *c) { /* __NLG_Notify1 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ebx = (uint32_t)((uint32_t)0x87e3f4u); /* mov ebx, 0x1000e3f4 */
    { f_00875598(c); return; } /* jmp 0x875598 */
}

void f_0087558e(CPU *c) { /* FUN_1000558e */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ebx = (uint32_t)((uint32_t)0x87e3f4u); /* mov ebx, 0x1000e3f4 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebx + 8], ecx */
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 4], eax */
    W32((uint32_t)(c->ebx + 0xcu), (uint32_t)(c->ebp)); /* mov dword ptr [ebx + 0xc], ebp */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
}

void f_00875598(CPU *c) { /* PTR_00875598 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebx + 8], ecx */
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 4], eax */
    W32((uint32_t)(c->ebx + 0xcu), (uint32_t)(c->ebp)); /* mov dword ptr [ebx + 0xc], ebp */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
}

void f_008755a6(CPU *c) { /* PTR_008755a6 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008755acu); f_008765b1(c); /* call 0x8765b1 */
    { uint32_t v_ = R32((uint32_t)(0x881850u)); PUSH32(c, v_); } /* push dword ptr [0x10011850] */
    PUSH32(c, 0x008755b7u); f_0087690c(c); /* call 0x87690c */
    c->edx = (uint32_t)(R32((uint32_t)(0x881850u))); /* mov edx, dword ptr [0x10011850] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(0x88184cu))); /* mov ecx, dword ptr [0x1001184c] */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->esi = (uint32_t)(sub32(c, c->esi, c->edx)); /* sub esi, edx */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (!c->cf) goto L_0087560c; /* jae 0x87560c */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x008755d5u); f_0087690c(c); /* call 0x87690c */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x10u)); /* add eax, 0x10 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(0x881850u)); PUSH32(c, v_); } /* push dword ptr [0x10011850] */
    PUSH32(c, 0x008755e4u); f_008765dd(c); /* call 0x8765dd */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_008755ef; /* jne 0x8755ef */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    goto L_0087561b; /* jmp 0x87561b */
L_008755ef:;
    c->ecx = (uint32_t)(R32((uint32_t)(0x88184cu))); /* mov ecx, dword ptr [0x1001184c] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, R32((uint32_t)(0x881850u)))); /* sub ecx, dword ptr [0x10011850] */
    W32((uint32_t)(0x881850u), (uint32_t)(c->eax)); /* mov dword ptr [0x10011850], eax */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 2)); /* sar ecx, 2 */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->ecx * 4)); /* lea ecx, [eax + ecx*4] */
    W32((uint32_t)(0x88184cu), (uint32_t)(c->ecx)); /* mov dword ptr [0x1001184c], ecx */
L_0087560c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    { uint32_t a_ = (uint32_t)(0x88184cu); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x4u))); } /* add dword ptr [0x1001184c], 4 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_0087561b:;
    PUSH32(c, 0x00875620u); f_008765ba(c); /* call 0x8765ba */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00875624(CPU *c) { /* PTR_00875624 */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    PUSH32(c, 0x0087562du); f_008755a6(c); /* call 0x8755a6 */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->esp += 4; return; /* ret  */
}

void f_00875636(CPU *c) { /* PTR_00875636 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x80u; PUSH32(c, v_); } /* push 0x80 */
    PUSH32(c, 0x00875640u); f_008769fa(c); /* call 0x8769fa */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(0x881850u), (uint32_t)(c->eax)); /* mov dword ptr [0x10011850], eax */
    if (!c->zf) goto L_00875657; /* jne 0x875657 */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    PUSH32(c, 0x00875651u); f_008759e0(c); /* call 0x8759e0 */
    c->eax = (uint32_t)(R32((uint32_t)(0x881850u))); /* mov eax, dword ptr [0x10011850] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00875657:;
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [eax], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(0x881850u))); /* mov eax, dword ptr [0x10011850] */
    W32((uint32_t)(0x88184cu), (uint32_t)(c->eax)); /* mov dword ptr [0x1001184c], eax */
    c->esp += 4; return; /* ret  */
}

void f_00875665(CPU *c) { /* FUN_10005665 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = 0x1bu; PUSH32(c, v_); } /* push 0x1b */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x87d1fcu)); /* mov dword ptr [esi], 0x1000d1fc */
    PUSH32(c, 0x00875675u); f_00876bc9(c); /* call 0x876bc9 */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov esi, dword ptr [esi + 4] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00875684; /* je 0x875684 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00875683u); f_00876c3f(c); /* call 0x876c3f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00875684:;
    { uint32_t v_ = 0x1bu; PUSH32(c, v_); } /* push 0x1b */
    PUSH32(c, 0x0087568bu); f_00876c2a(c); /* call 0x876c2a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_0087568e(CPU *c) { /* type_info::vfunc_0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00875696u); f_00875665(c); /* call 0x875665 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_008756a4; /* je 0x8756a4 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008756a3u); f_00871030(c); /* call 0x871030 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_008756a4:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_008756aa(CPU *c) { /* FUN_100056aa */
    PREEMPT_POLL(c);
    PUSH32(c, 0x008756afu); f_008756c2(c); /* call 0x8756c2 */
    PUSH32(c, 0x008756b4u); f_00876e04(c); /* call 0x876e04 */
    W32((uint32_t)(0x881174u), (uint32_t)(c->eax)); /* mov dword ptr [0x10011174], eax */
    PUSH32(c, 0x008756beu); f_00876db4(c); /* call 0x876db4 */
    c->fpu_sw &= 0x7f00; /* fnclex  */
    c->esp += 4; return; /* ret  */
}

void f_008756c1(CPU *c) { /* PTR_008756c1 */
    PREEMPT_POLL(c);
    c->esp += 4; return; /* ret  */
}

void f_008756c2(CPU *c) { /* FUN_100056c2 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x8771ddu); /* mov eax, 0x100071dd */
    W32((uint32_t)(0x87e514u), (uint32_t)((uint32_t)0x876e87u)); /* mov dword ptr [0x1000e514], 0x10006e87 */
    W32((uint32_t)(0x87e510u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000e510], eax */
    W32((uint32_t)(0x87e518u), (uint32_t)((uint32_t)0x876eedu)); /* mov dword ptr [0x1000e518], 0x10006eed */
    W32((uint32_t)(0x87e51cu), (uint32_t)((uint32_t)0x876e2du)); /* mov dword ptr [0x1000e51c], 0x10006e2d */
    W32((uint32_t)(0x87e520u), (uint32_t)((uint32_t)0x876ed5u)); /* mov dword ptr [0x1000e520], 0x10006ed5 */
    W32((uint32_t)(0x87e524u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000e524], eax */
    c->esp += 4; return; /* ret  */
}

void f_008756fa(CPU *c) { /* __CxxThrowException@8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x20u)); /* sub esp, 0x20 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esi = (uint32_t)((uint32_t)0x87d200u); /* mov esi, 0x1000d200 */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0xffffffe0u)); /* lea edi, [ebp - 0x20] */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffff0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x20] */
    { uint32_t t_ = R32((uint32_t)(0x87d004u)); PUSH32(c, 0x0087572eu); call_indirect(c, t_); } /* call dword ptr [0x1000d004] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 12; return; /* ret 8 */
}

void f_00875734(CPU *c) { /* FUN_10005734 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
L_0087573e:;
    (void)sub32(c, R32((uint32_t)(0x87e73cu)), (uint32_t)0x1u); /* cmp dword ptr [0x1000e73c], 1 */
    if ((c->zf || c->sf != c->of)) goto L_00875756; /* jle 0x875756 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->esi))); /* movzx eax, byte ptr [esi] */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00875752u); f_008773bb(c); /* call 0x8773bb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00875765; /* jmp 0x875765 */
L_00875756:;
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->esi))); /* movzx eax, byte ptr [esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x87e530u))); /* mov ecx, dword ptr [0x1000e530] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x8u))); /* and eax, 8 */
L_00875765:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0087576c; /* je 0x87576c */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    goto L_0087573e; /* jmp 0x87573e */
L_0087576c:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00875776u); f_00877340(c); /* call 0x877340 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe8u)); /* lea eax, [ebp - 0x18] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00875782u); f_008772b7(c); /* call 0x8772b7 */
    FPUSH(c, RF64((uint32_t)(c->eax + 0x10u))); /* fld qword ptr [eax + 0x10] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0087578b(CPU *c) { /* PTR_0087578b */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x19u; PUSH32(c, v_); } /* push 0x19 */
    PUSH32(c, 0x00875792u); f_008759e0(c); /* call 0x8759e0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00875794(CPU *c) { /* _rand */
    PREEMPT_POLL(c);
    PUSH32(c, 0x00875799u); f_00876301(c); /* call 0x876301 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x14u))); /* mov ecx, dword ptr [eax + 0x14] */
    { int64_t r_ = (int64_t)(int32_t)c->ecx * (int32_t)(uint32_t)0x343fdu; c->ecx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul ecx, ecx, 0x343fd */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x269ec3u)); /* add ecx, 0x269ec3 */
    W32((uint32_t)(c->eax + 0x14u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x14], ecx */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->eax = (uint32_t)(shr32(c, c->eax, 16)); /* shr eax, 0x10 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fffu))); /* and eax, 0x7fff */
    c->esp += 4; return; /* ret  */
}

void f_008757b8(CPU *c) { /* __ftol */
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

void f_008757df(CPU *c) { /* FUN_100057df */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edi, dword ptr [esp + 0x14] */
L_008757e7:;
    (void)sub32(c, R32((uint32_t)(0x87e73cu)), (uint32_t)0x1u); /* cmp dword ptr [0x1000e73c], 1 */
    if ((c->zf || c->sf != c->of)) goto L_008757ff; /* jle 0x8757ff */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008757fbu); f_008773bb(c); /* call 0x8773bb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_0087580e; /* jmp 0x87580e */
L_008757ff:;
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x87e530u))); /* mov ecx, dword ptr [0x1000e530] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x8u))); /* and eax, 8 */
L_0087580e:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00875815; /* je 0x875815 */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_008757e7; /* jmp 0x8757e7 */
L_00875815:;
    c->esi = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx esi, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->esi, (uint32_t)0x2du); /* cmp esi, 0x2d */
    c->ebp = (uint32_t)(c->esi); /* mov ebp, esi */
    if (c->zf) goto L_00875825; /* je 0x875825 */
    (void)sub32(c, c->esi, (uint32_t)0x2bu); /* cmp esi, 0x2b */
    if (!c->zf) goto L_00875829; /* jne 0x875829 */
L_00875825:;
    c->esi = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx esi, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
L_00875829:;
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
L_0087582b:;
    (void)sub32(c, R32((uint32_t)(0x87e73cu)), (uint32_t)0x1u); /* cmp dword ptr [0x1000e73c], 1 */
    if ((c->zf || c->sf != c->of)) goto L_00875840; /* jle 0x875840 */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x0087583cu); f_008773bb(c); /* call 0x8773bb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_0087584b; /* jmp 0x87584b */
L_00875840:;
    c->eax = (uint32_t)(R32((uint32_t)(0x87e530u))); /* mov eax, dword ptr [0x1000e530] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + c->esi * 2))); /* mov al, byte ptr [eax + esi*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4u))); /* and eax, 4 */
L_0087584b:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0087585c; /* je 0x87585c */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->ebx * 4)); /* lea eax, [ebx + ebx*4] */
    c->ebx = (uint32_t)((uint32_t)(c->esi + c->eax * 2 + 0xffffffd0u)); /* lea ebx, [esi + eax*2 - 0x30] */
    c->esi = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx esi, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_0087582b; /* jmp 0x87582b */
L_0087585c:;
    (void)sub32(c, c->ebp, (uint32_t)0x2du); /* cmp ebp, 0x2d */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    if (!c->zf) goto L_00875865; /* jne 0x875865 */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
L_00875865:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_0087586a(CPU *c) { /* FUN_1000586a */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_008758ff; /* jne 0x8758ff */
    { uint32_t t_ = R32((uint32_t)(0x87d00cu)); PUSH32(c, 0x0087587du); call_indirect(c, t_); } /* call dword ptr [0x1000d00c] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    W32((uint32_t)(0x881190u), (uint32_t)(c->eax)); /* mov dword ptr [0x10011190], eax */
    PUSH32(c, 0x00875889u); f_00877c21(c); /* call 0x877c21 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_008758ca; /* je 0x8758ca */
    c->eax = (uint32_t)(R32((uint32_t)(0x881190u))); /* mov eax, dword ptr [0x10011190] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x881191u))); /* mov cl, byte ptr [0x10011191] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xffu))); /* and eax, 0xff */
    { uint32_t a_ = (uint32_t)(0x881190u); W32(a_, (uint32_t)(shr32(c, R32(a_), 16))); } /* shr dword ptr [0x10011190], 0x10 */
    W32((uint32_t)(0x881198u), (uint32_t)(c->eax)); /* mov dword ptr [0x10011198], eax */
    W32((uint32_t)(0x88119cu), (uint32_t)(c->ecx)); /* mov dword ptr [0x1001119c], ecx */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    W32((uint32_t)(0x881194u), (uint32_t)(c->eax)); /* mov dword ptr [0x10011194], eax */
    PUSH32(c, 0x008758c1u); f_0087627c(c); /* call 0x87627c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_008758ce; /* jne 0x8758ce */
    PUSH32(c, 0x008758cau); f_00877c7e(c); /* call 0x877c7e */
L_008758ca:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00875940; /* jmp 0x875940 */
L_008758ce:;
    { uint32_t t_ = R32((uint32_t)(0x87d008u)); PUSH32(c, 0x008758d4u); call_indirect(c, t_); } /* call dword ptr [0x1000d008] */
    W32((uint32_t)(0x881854u), (uint32_t)(c->eax)); /* mov dword ptr [0x10011854], eax */
    PUSH32(c, 0x008758deu); f_0087797a(c); /* call 0x87797a */
    W32((uint32_t)(0x88117cu), (uint32_t)(c->eax)); /* mov dword ptr [0x1001117c], eax */
    PUSH32(c, 0x008758e8u); f_00877464(c); /* call 0x877464 */
    PUSH32(c, 0x008758edu); f_0087772d(c); /* call 0x87772d */
    PUSH32(c, 0x008758f2u); f_00877674(c); /* call 0x877674 */
    PUSH32(c, 0x008758f7u); f_008764bf(c); /* call 0x8764bf */
    { uint32_t a_ = (uint32_t)(0x881178u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [0x10011178] */
    goto L_0087593d; /* jmp 0x87593d */
L_008758ff:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->zf) goto L_00875931; /* jne 0x875931 */
    (void)sub32(c, R32((uint32_t)(0x881178u)), c->ecx); /* cmp dword ptr [0x10011178], ecx */
    if ((c->zf || c->sf != c->of)) goto L_008758ca; /* jle 0x8758ca */
    { uint32_t a_ = (uint32_t)(0x881178u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [0x10011178] */
    (void)sub32(c, R32((uint32_t)(0x8811c8u)), c->ecx); /* cmp dword ptr [0x100111c8], ecx */
    if (!c->zf) goto L_00875920; /* jne 0x875920 */
    PUSH32(c, 0x00875920u); f_008764fd(c); /* call 0x8764fd */
L_00875920:;
    PUSH32(c, 0x00875925u); f_00877620(c); /* call 0x877620 */
    PUSH32(c, 0x0087592au); f_008762d0(c); /* call 0x8762d0 */
    PUSH32(c, 0x0087592fu); f_00877c7e(c); /* call 0x877c7e */
    goto L_0087593d; /* jmp 0x87593d */
L_00875931:;
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_0087593d; /* jne 0x87593d */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x0087593cu); f_00876368(c); /* call 0x876368 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_0087593d:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00875940:;
    c->esp += 16; return; /* ret 0xc */
}

void f_00875943(CPU *c) { /* entry */
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
    if (!c->zf) goto L_0087595f; /* jne 0x87595f */
    (void)sub32(c, R32((uint32_t)(0x881178u)), (uint32_t)0x0u); /* cmp dword ptr [0x10011178], 0 */
    goto L_00875985; /* jmp 0x875985 */
L_0087595f:;
    (void)sub32(c, c->esi, (uint32_t)0x1u); /* cmp esi, 1 */
    if (c->zf) goto L_00875969; /* je 0x875969 */
    (void)sub32(c, c->esi, (uint32_t)0x2u); /* cmp esi, 2 */
    if (!c->zf) goto L_0087598b; /* jne 0x87598b */
L_00875969:;
    c->eax = (uint32_t)(R32((uint32_t)(0x881858u))); /* mov eax, dword ptr [0x10011858] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0087597b; /* je 0x87597b */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00875977u); call_indirect(c, t_); } /* call eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00875987; /* je 0x875987 */
L_0087597b:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00875983u); f_0087586a(c); /* call 0x87586a */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
L_00875985:;
    if (!c->zf) goto L_0087598b; /* jne 0x87598b */
L_00875987:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_008759d9; /* jmp 0x8759d9 */
L_0087598b:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00875993u); f_00877d26(c); /* call 0x877d26 */
    (void)sub32(c, c->esi, (uint32_t)0x1u); /* cmp esi, 1 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0xc], eax */
    if (!c->zf) goto L_008759a7; /* jne 0x8759a7 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_008759d6; /* jne 0x8759d6 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x008759a7u); f_0087586a(c); /* call 0x87586a */
L_008759a7:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_008759b0; /* je 0x8759b0 */
    (void)sub32(c, c->esi, (uint32_t)0x3u); /* cmp esi, 3 */
    if (!c->zf) goto L_008759d6; /* jne 0x8759d6 */
L_008759b0:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x008759b8u); f_0087586a(c); /* call 0x87586a */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_008759bf; /* jne 0x8759bf */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->eax)))); } /* and dword ptr [ebp + 0xc], eax */
L_008759bf:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    if (c->zf) goto L_008759d6; /* je 0x8759d6 */
    c->eax = (uint32_t)(R32((uint32_t)(0x881858u))); /* mov eax, dword ptr [0x10011858] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008759d6; /* je 0x8759d6 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = c->eax; PUSH32(c, 0x008759d3u); call_indirect(c, t_); } /* call eax */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0xc], eax */
L_008759d6:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
L_008759d9:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 16; return; /* ret 0xc */
}

void f_008759e0(CPU *c) { /* __amsg_exit */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x881184u))); /* mov eax, dword ptr [0x10011184] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_008759f7; /* je 0x8759f7 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_008759fc; /* jne 0x8759fc */
    (void)sub32(c, R32((uint32_t)(0x881188u)), (uint32_t)0x1u); /* cmp dword ptr [0x10011188], 1 */
    if (!c->zf) goto L_008759fc; /* jne 0x8759fc */
L_008759f7:;
    PUSH32(c, 0x008759fcu); f_00877d2c(c); /* call 0x877d2c */
L_008759fc:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    PUSH32(c, 0x00875a05u); f_00877d65(c); /* call 0x877d65 */
    { uint32_t v_ = 0xffu; PUSH32(c, v_); } /* push 0xff */
    { uint32_t t_ = R32((uint32_t)(0x87e438u)); PUSH32(c, 0x00875a10u); call_indirect(c, t_); } /* call dword ptr [0x1000e438] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00875a10(CPU *c) { /* PTR_00875a10 */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00875a13(CPU *c) { /* FUN_10005a13 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov esi, dword ptr [ebp + 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)((uint32_t)0x19930520u); /* mov edi, 0x19930520 */
    (void)sub32(c, R32((uint32_t)(c->esi)), c->edi); /* cmp dword ptr [esi], edi */
    if (c->zf) goto L_00875a29; /* je 0x875a29 */
    PUSH32(c, 0x00875a29u); f_00876469(c); /* call 0x876469 */
L_00875a29:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + 0x4u)) & (uint8_t)0x66u)); /* test byte ptr [eax + 4], 0x66 */
    if (c->zf) goto L_00875a51; /* je 0x875a51 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x4u)), (uint32_t)0x0u); /* cmp dword ptr [esi + 4], 0 */
    if (c->zf) goto L_00875aa7; /* je 0x875aa7 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x1c], 0 */
    if (!c->zf) goto L_00875aa7; /* jne 0x875aa7 */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x00875a4cu); f_00875d68(c); /* call 0x875d68 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    goto L_00875aa7; /* jmp 0x875aa7 */
L_00875a51:;
    (void)sub32(c, R32((uint32_t)(c->esi + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [esi + 0xc], 0 */
    if (c->zf) goto L_00875aa7; /* je 0x875aa7 */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xe06d7363u); /* cmp dword ptr [eax], 0xe06d7363 */
    if (!c->zf) goto L_00875a8b; /* jne 0x875a8b */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x14u)), c->edi); /* cmp dword ptr [eax + 0x14], edi */
    if ((c->cf || c->zf)) goto L_00875a8b; /* jbe 0x875a8b */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x1cu))); /* mov ecx, dword ptr [eax + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov ecx, dword ptr [ecx + 8] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00875a8b; /* je 0x875a8b */
    c->edx = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0x24u))); /* movzx edx, byte ptr [ebp + 0x24] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = c->ecx; PUSH32(c, 0x00875a86u); call_indirect(c, t_); } /* call ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    goto L_00875aaa; /* jmp 0x875aaa */
L_00875a8b:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x24u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x24] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00875aa4u); f_00875aae(c); /* call 0x875aae */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
L_00875aa7:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00875aaa:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00875aae(CPU *c) { /* FUN_10005aae */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffecu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp - 0x14], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x10], eax */
    if ((c->sf != c->of)) goto L_00875ace; /* jl 0x875ace */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov ecx, dword ptr [ebp + 0x18] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ecx + 0x4u))); /* cmp eax, dword ptr [ecx + 4] */
    if ((c->sf != c->of)) goto L_00875ad3; /* jl 0x875ad3 */
L_00875ace:;
    PUSH32(c, 0x00875ad3u); f_00876469(c); /* call 0x876469 */
L_00875ad3:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    c->ebx = (uint32_t)((uint32_t)0xe06d7363u); /* mov ebx, 0xe06d7363 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)((uint32_t)0x19930520u); /* mov edi, 0x19930520 */
    (void)sub32(c, R32((uint32_t)(c->esi)), c->ebx); /* cmp dword ptr [esi], ebx */
    if (!c->zf) goto L_00875c36; /* jne 0x875c36 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [esi + 0x10], 3 */
    if (!c->zf) goto L_00875b53; /* jne 0x875b53 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x14u)), c->edi); /* cmp dword ptr [esi + 0x14], edi */
    if (!c->zf) goto L_00875b53; /* jne 0x875b53 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [esi + 0x1c], 0 */
    if (!c->zf) goto L_00875b53; /* jne 0x875b53 */
    PUSH32(c, 0x00875b01u); f_00876301(c); /* call 0x876301 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x6cu)), (uint32_t)0x0u); /* cmp dword ptr [eax + 0x6c], 0 */
    if (c->zf) goto L_00875c31; /* je 0x875c31 */
    PUSH32(c, 0x00875b10u); f_00876301(c); /* call 0x876301 */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + 0x6cu))); /* mov esi, dword ptr [eax + 0x6c] */
    PUSH32(c, 0x00875b18u); f_00876301(c); /* call 0x876301 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x70u))); /* mov eax, dword ptr [eax + 0x70] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x10], eax */
    W8((uint32_t)(c->ebp + 0xffffffecu), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ebp - 0x14], 1 */
    PUSH32(c, 0x00875b2au); f_00877eb8(c); /* call 0x877eb8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00875b35; /* jne 0x875b35 */
    PUSH32(c, 0x00875b35u); f_00876469(c); /* call 0x876469 */
L_00875b35:;
    (void)sub32(c, R32((uint32_t)(c->esi)), c->ebx); /* cmp dword ptr [esi], ebx */
    if (!c->zf) goto L_00875c36; /* jne 0x875c36 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [esi + 0x10], 3 */
    if (!c->zf) goto L_00875b53; /* jne 0x875b53 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x14u)), c->edi); /* cmp dword ptr [esi + 0x14], edi */
    if (!c->zf) goto L_00875b53; /* jne 0x875b53 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [esi + 0x1c], 0 */
    if (!c->zf) goto L_00875b53; /* jne 0x875b53 */
    PUSH32(c, 0x00875b53u); f_00876469(c); /* call 0x876469 */
L_00875b53:;
    (void)sub32(c, R32((uint32_t)(c->esi)), c->ebx); /* cmp dword ptr [esi], ebx */
    if (!c->zf) goto L_00875c36; /* jne 0x875c36 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [esi + 0x10], 3 */
    if (!c->zf) goto L_00875c36; /* jne 0x875c36 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x14u)), c->edi); /* cmp dword ptr [esi + 0x14], edi */
    if (!c->zf) goto L_00875c36; /* jne 0x875c36 */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov edi, dword ptr [ebp - 0x10] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe8u)); /* lea eax, [ebp - 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    PUSH32(c, 0x00875b85u); f_0087543b(c); /* call 0x87543b */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
L_00875b8a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xffffffe8u))); /* cmp eax, dword ptr [ebp - 0x18] */
    if (!c->cf) goto L_00875c21; /* jae 0x875c21 */
    (void)sub32(c, R32((uint32_t)(c->ebx)), c->edi); /* cmp dword ptr [ebx], edi */
    if ((!c->zf && c->sf == c->of)) goto L_00875c16; /* jg 0x875c16 */
    (void)sub32(c, c->edi, R32((uint32_t)(c->ebx + 0x4u))); /* cmp edi, dword ptr [ebx + 4] */
    if ((!c->zf && c->sf == c->of)) goto L_00875c16; /* jg 0x875c16 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x10u))); /* mov eax, dword ptr [ebx + 0x10] */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xcu))); /* mov eax, dword ptr [ebx + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    if ((c->zf || c->sf != c->of)) goto L_00875c13; /* jle 0x875c13 */
L_00875baf:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x1cu))); /* mov eax, dword ptr [esi + 0x1c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0xcu))); /* mov eax, dword ptr [eax + 0xc] */
    c->edi = (uint32_t)((uint32_t)(c->eax + 0x4u)); /* lea edi, [eax + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    if ((c->zf || c->sf != c->of)) goto L_00875be0; /* jle 0x875be0 */
L_00875bc1:;
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [esi + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->edi)); PUSH32(c, v_); } /* push dword ptr [edi] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00875bceu); f_00875d0b(c); /* call 0x875d0b */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00875bef; /* jne 0x875bef */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 8] */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff8u)), c->eax); /* cmp dword ptr [ebp - 8], eax */
    if ((!c->zf && c->sf == c->of)) goto L_00875bc1; /* jg 0x875bc1 */
L_00875be0:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff4u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x10u))); } /* add dword ptr [ebp + 8], 0x10 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0xc], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_00875baf; /* jg 0x875baf */
    goto L_00875c13; /* jmp 0x875c13 */
L_00875bef:;
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
    PUSH32(c, 0x00875c10u); f_00875e1c(c); /* call 0x875e1c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
L_00875c13:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov edi, dword ptr [ebp - 0x10] */
L_00875c16:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x14u)); /* add ebx, 0x14 */
    goto L_00875b8a; /* jmp 0x875b8a */
L_00875c21:;
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x1cu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0x1c], 0 */
    if (c->zf) goto L_00875c31; /* je 0x875c31 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00875c2fu); f_008761a0(c); /* call 0x8761a0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00875c31:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00875c36:;
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x1cu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0x1c], 0 */
    if (!c->zf) goto L_00875c5c; /* jne 0x875c5c */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x24u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffff0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00875c57u); f_00875c61(c); /* call 0x875c61 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    goto L_00875c31; /* jmp 0x875c31 */
L_00875c5c:;
    { f_00876408(c); return; } /* jmp 0x876408 */
}

void f_00875c61(CPU *c) { /* FUN_10005c61 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00875c6du); f_00876301(c); /* call 0x876301 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x68u)), (uint32_t)0x0u); /* cmp dword ptr [eax + 0x68], 0 */
    if (c->zf) goto L_00875c94; /* je 0x875c94 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x24u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00875c8du); f_00875310(c); /* call 0x875310 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00875d07; /* jne 0x875d07 */
L_00875c94:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov edi, dword ptr [ebp + 0x1c] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    PUSH32(c, 0x00875cabu); f_0087543b(c); /* call 0x87543b */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_00875cb0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xfffffff8u))); /* cmp eax, dword ptr [ebp - 8] */
    if (!c->cf) goto L_00875d07; /* jae 0x875d07 */
    (void)sub32(c, c->edi, R32((uint32_t)(c->esi))); /* cmp edi, dword ptr [esi] */
    if ((c->sf != c->of)) goto L_00875cff; /* jl 0x875cff */
    (void)sub32(c, c->edi, R32((uint32_t)(c->esi + 0x4u))); /* cmp edi, dword ptr [esi + 4] */
    if ((!c->zf && c->sf == c->of)) goto L_00875cff; /* jg 0x875cff */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0xfffffff4u))); /* mov ecx, dword ptr [eax - 0xc] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00875cd9; /* je 0x875cd9 */
    (void)sub8(c, R8((uint32_t)(c->ecx + 0x8u)), (uint8_t)0x0u); /* cmp byte ptr [ecx + 8], 0 */
    if (!c->zf) goto L_00875cff; /* jne 0x875cff */
L_00875cd9:;
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
    PUSH32(c, 0x00875cfcu); f_00875e1c(c); /* call 0x875e1c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
L_00875cff:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x14u)); /* add esi, 0x14 */
    goto L_00875cb0; /* jmp 0x875cb0 */
L_00875d07:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00875d0b(CPU *c) { /* FUN_10005d0b */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edi, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov eax, dword ptr [edi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00875d62; /* je 0x875d62 */
    (void)sub8(c, R8((uint32_t)(c->eax + 0x8u)), (uint8_t)0x0u); /* cmp byte ptr [eax + 8], 0 */
    c->edx = (uint32_t)((uint32_t)(c->eax + 0x8u)); /* lea edx, [eax + 8] */
    if (c->zf) goto L_00875d62; /* je 0x875d62 */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (c->zf) goto L_00875d3c; /* je 0x875d3c */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x8u)); /* add ecx, 8 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00875d36u); f_00876d30(c); /* call 0x876d30 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00875d5e; /* jne 0x875d5e */
L_00875d3c:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi)) & (uint8_t)0x2u)); /* test byte ptr [esi], 2 */
    if (c->zf) goto L_00875d46; /* je 0x875d46 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edi)) & (uint8_t)0x8u)); /* test byte ptr [edi], 8 */
    if (c->zf) goto L_00875d5e; /* je 0x875d5e */
L_00875d46:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    if (c->zf) goto L_00875d55; /* je 0x875d55 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edi)) & (uint8_t)0x1u)); /* test byte ptr [edi], 1 */
    if (c->zf) goto L_00875d5e; /* je 0x875d5e */
L_00875d55:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x2u)); /* test al, 2 */
    if (c->zf) goto L_00875d62; /* je 0x875d62 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edi)) & (uint8_t)0x2u)); /* test byte ptr [edi], 2 */
    if (!c->zf) goto L_00875d62; /* jne 0x875d62 */
L_00875d5e:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00875d65; /* jmp 0x875d65 */
L_00875d62:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00875d65:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00875d68(CPU *c) { /* FUN_10005d68 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x87d220u; PUSH32(c, v_); } /* push 0x1000d220 */
    { uint32_t v_ = 0x877f10u; PUSH32(c, v_); } /* push 0x10007f10 */
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
L_00875d9a:;
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0x14u))); /* cmp esi, dword ptr [ebp + 0x14] */
    if (c->zf) goto L_00875df4; /* je 0x875df4 */
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if ((c->zf || c->sf != c->of)) goto L_00875da9; /* jle 0x875da9 */
    (void)sub32(c, c->esi, R32((uint32_t)(c->edi + 0x4u))); /* cmp esi, dword ptr [edi + 4] */
    if ((c->sf != c->of)) goto L_00875dae; /* jl 0x875dae */
L_00875da9:;
    PUSH32(c, 0x00875daeu); f_00876469(c); /* call 0x876469 */
L_00875dae:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8 + 0x4u))); /* mov eax, dword ptr [eax + esi*8 + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00875dc9; /* je 0x875dc9 */
    { uint32_t v_ = 0x103u; PUSH32(c, v_); } /* push 0x103 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00875dc9u); f_00876230(c); /* call 0x876230 */
L_00875dc9:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    goto L_00875de9; /* jmp 0x875de9 */
L_00875de9:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8))); /* mov esi, dword ptr [eax + esi*8] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x1c], esi */
    goto L_00875d9a; /* jmp 0x875d9a */
L_00875df4:;
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebx + 8], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00875d9a(CPU *c) { /* PTR_00875d9a */
    PREEMPT_POLL(c);
L_00875d9a:;
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0x14u))); /* cmp esi, dword ptr [ebp + 0x14] */
    if (c->zf) goto L_00875df4; /* je 0x875df4 */
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if ((c->zf || c->sf != c->of)) goto L_00875da9; /* jle 0x875da9 */
    (void)sub32(c, c->esi, R32((uint32_t)(c->edi + 0x4u))); /* cmp esi, dword ptr [edi + 4] */
    if ((c->sf != c->of)) goto L_00875dae; /* jl 0x875dae */
L_00875da9:;
    PUSH32(c, 0x00875daeu); f_00876469(c); /* call 0x876469 */
L_00875dae:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8 + 0x4u))); /* mov eax, dword ptr [eax + esi*8 + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00875dc9; /* je 0x875dc9 */
    { uint32_t v_ = 0x103u; PUSH32(c, v_); } /* push 0x103 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00875dc9u); f_00876230(c); /* call 0x876230 */
L_00875dc9:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    goto L_00875de9; /* jmp 0x875de9 */
L_00875de9:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8))); /* mov esi, dword ptr [eax + esi*8] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x1c], esi */
    goto L_00875d9a; /* jmp 0x875d9a */
L_00875df4:;
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebx + 8], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00875dcf(CPU *c) { /* PTR_00875dcf */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffecu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x14] */
    PUSH32(c, 0x00875dd7u); f_00875e06(c); /* call 0x875e06 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00875dd9(CPU *c) { /* PTR_00875dd9 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edi, dword ptr [ebp + 0x10] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov esi, dword ptr [ebp - 0x1c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8))); /* mov esi, dword ptr [eax + esi*8] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x1c], esi */
    { f_00875d9a(c); return; } /* jmp 0x875d9a */
}

void f_00875e06(CPU *c) { /* FUN_10005e06 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xe06d7363u); /* cmp dword ptr [eax], 0xe06d7363 */
    if (c->zf) goto L_00875e17; /* je 0x875e17 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_00875e17:;
    { f_00876408(c); return; } /* jmp 0x876408 */
}

void f_00875e1c(CPU *c) { /* FUN_10005e1c */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x20u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x20], 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov ebx, dword ptr [ebp + 0x1c] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    if (c->zf) goto L_00875e3e; /* je 0x875e3e */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00875e3bu); f_00875fdc(c); /* call 0x875fdc */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_00875e3e:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x2cu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x2c], 0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    if (!c->zf) goto L_00875e4a; /* jne 0x875e4a */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    goto L_00875e4d; /* jmp 0x875e4d */
L_00875e4a:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x2cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x2c] */
L_00875e4d:;
    PUSH32(c, 0x00875e52u); f_00875212(c); /* call 0x875212 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x24u))); /* mov esi, dword ptr [ebp + 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00875e63u); f_00875d68(c); /* call 0x875d68 */
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
    PUSH32(c, 0x00875e84u); f_00875e97(c); /* call 0x875e97 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00875e92; /* je 0x875e92 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00875e92u); f_008751d0(c); /* call 0x8751d0 */
L_00875e92:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00875e97(CPU *c) { /* FUN_10005e97 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x87d230u; PUSH32(c, v_); } /* push 0x1000d230 */
    { uint32_t v_ = 0x877f10u; PUSH32(c, v_); } /* push 0x10007f10 */
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
    PUSH32(c, 0x00875ed5u); f_00876301(c); /* call 0x876301 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x6cu))); /* mov eax, dword ptr [eax + 0x6c] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    PUSH32(c, 0x00875ee0u); f_00876301(c); /* call 0x876301 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x70u))); /* mov eax, dword ptr [eax + 0x70] */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    PUSH32(c, 0x00875eebu); f_00876301(c); /* call 0x876301 */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    W32((uint32_t)(c->eax + 0x6cu), (uint32_t)(c->edi)); /* mov dword ptr [eax + 0x6c], edi */
    PUSH32(c, 0x00875ef6u); f_00876301(c); /* call 0x876301 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    W32((uint32_t)(c->eax + 0x70u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x70], ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00875f17u); f_00875297(c); /* call 0x875297 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x2c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00875f2au); f_00875f64(c); /* call 0x875f64 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd4u))); /* mov eax, dword ptr [ebp - 0x2c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00875f2d(CPU *c) { /* PTR_00875f2d */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00875f3c(CPU *c) { /* PTR_00875f3c */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffecu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x14] */
    PUSH32(c, 0x00875f44u); f_00875fb2(c); /* call 0x875fb2 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00875f46(CPU *c) { /* PTR_00875f46 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffd4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x2c], 0 */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00875f58u); f_008754fa(c); /* call 0x8754fa */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { f_00875f2d(c); return; } /* jmp 0x875f2d */
}

void f_00875f5e(CPU *c) { /* PTR_00875f5e */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    { f_00875f64(c); return; }
}

void f_00875f64(CPU *c) { /* FUN_10005f64 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    W32((uint32_t)(c->esi + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [esi - 4], eax */
    PUSH32(c, 0x00875f6fu); f_00876301(c); /* call 0x876301 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov ecx, dword ptr [ebp - 0x1c] */
    W32((uint32_t)(c->eax + 0x6cu), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x6c], ecx */
    PUSH32(c, 0x00875f7au); f_00876301(c); /* call 0x876301 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov ecx, dword ptr [ebp - 0x20] */
    W32((uint32_t)(c->eax + 0x70u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x70], ecx */
    (void)sub32(c, R32((uint32_t)(c->edi)), (uint32_t)0xe06d7363u); /* cmp dword ptr [edi], 0xe06d7363 */
    if (!c->zf) goto L_00875fb1; /* jne 0x875fb1 */
    (void)sub32(c, R32((uint32_t)(c->edi + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [edi + 0x10], 3 */
    if (!c->zf) goto L_00875fb1; /* jne 0x875fb1 */
    (void)sub32(c, R32((uint32_t)(c->edi + 0x14u)), (uint32_t)0x19930520u); /* cmp dword ptr [edi + 0x14], 0x19930520 */
    if (!c->zf) goto L_00875fb1; /* jne 0x875fb1 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00875fb1; /* jne 0x875fb1 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x2c], 0 */
    if (c->zf) goto L_00875fb1; /* je 0x875fb1 */
    PUSH32(c, 0x00875fa8u); f_00875562(c); /* call 0x875562 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00875fafu); f_008761a0(c); /* call 0x8761a0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00875fb1:;
    c->esp += 4; return; /* ret  */
}

void f_00875fb2(CPU *c) { /* FUN_10005fb2 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xe06d7363u); /* cmp dword ptr [eax], 0xe06d7363 */
    if (!c->zf) goto L_00875fd9; /* jne 0x875fd9 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [eax + 0x10], 3 */
    if (!c->zf) goto L_00875fd9; /* jne 0x875fd9 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x14u)), (uint32_t)0x19930520u); /* cmp dword ptr [eax + 0x14], 0x19930520 */
    if (!c->zf) goto L_00875fd9; /* jne 0x875fd9 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [eax + 0x1c], 0 */
    if (!c->zf) goto L_00875fd9; /* jne 0x875fd9 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
L_00875fd9:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_00875fdc(CPU *c) { /* FUN_10005fdc */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x87d248u; PUSH32(c, v_); } /* push 0x1000d248 */
    { uint32_t v_ = 0x877f10u; PUSH32(c, v_); } /* push 0x10007f10 */
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
    if (c->zf) goto L_00876185; /* je 0x876185 */
    (void)sub8(c, R8((uint32_t)(c->eax + 0x8u)), (uint8_t)0x0u); /* cmp byte ptr [eax + 8], 0 */
    if (c->zf) goto L_00876185; /* je 0x876185 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov eax, dword ptr [ecx + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00876185; /* je 0x876185 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
    c->edi = (uint32_t)((uint32_t)(c->eax + c->edx + 0xcu)); /* lea edi, [eax + edx + 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ecx)) & (uint8_t)0x8u)); /* test byte ptr [ecx], 8 */
    if (c->zf) goto L_00876079; /* je 0x876079 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x18] */
    PUSH32(c, 0x00876042u); f_00877eb8(c); /* call 0x877eb8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0087617c; /* je 0x87617c */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00876054u); f_00877ed4(c); /* call 0x877ed4 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0087617c; /* je 0x87617c */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x18u))); /* mov eax, dword ptr [esi + 0x18] */
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov ecx, dword ptr [ebp + 0x14] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x8u)); /* add ecx, 8 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
L_0087606a:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00876070u); f_00876207(c); /* call 0x876207 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    goto L_00876181; /* jmp 0x876181 */
L_00876079:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov esi, dword ptr [ebp + 0x14] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi)) & (uint8_t)0x1u)); /* test byte ptr [esi], 1 */
    if (c->zf) goto L_008760d3; /* je 0x8760d3 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    PUSH32(c, 0x0087608eu); f_00877eb8(c); /* call 0x877eb8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0087617c; /* je 0x87617c */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x008760a0u); f_00877ed4(c); /* call 0x877ed4 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0087617c; /* je 0x87617c */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x14u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x008760b6u); f_00877ff0(c); /* call 0x877ff0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x14u)), (uint32_t)0x4u); /* cmp dword ptr [esi + 0x14], 4 */
    if (!c->zf) goto L_00876181; /* jne 0x876181 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00876181; /* je 0x876181 */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x8u)); /* add esi, 8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    goto L_0087606a; /* jmp 0x87606a */
L_008760d3:;
    (void)sub32(c, R32((uint32_t)(c->esi + 0x18u)), (uint32_t)0x0u); /* cmp dword ptr [esi + 0x18], 0 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    if (!c->zf) goto L_0087611b; /* jne 0x87611b */
    PUSH32(c, 0x008760e6u); f_00877eb8(c); /* call 0x877eb8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0087617c; /* je 0x87617c */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x008760f8u); f_00877ed4(c); /* call 0x877ed4 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0087617c; /* je 0x87617c */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x14u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x14] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x8u)); /* add esi, 8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    PUSH32(c, 0x0087610du); f_00876207(c); /* call 0x876207 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00876116u); f_00877ff0(c); /* call 0x877ff0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_00876181; /* jmp 0x876181 */
L_0087611b:;
    PUSH32(c, 0x00876120u); f_00877eb8(c); /* call 0x877eb8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0087617c; /* je 0x87617c */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x0087612eu); f_00877ed4(c); /* call 0x877ed4 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0087617c; /* je 0x87617c */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x18] */
    PUSH32(c, 0x0087613cu); f_00877ef0(c); /* call 0x877ef0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0087617c; /* je 0x87617c */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi)) & (uint8_t)0x4u)); /* test byte ptr [esi], 4 */
    if (c->zf) goto L_00876162; /* je 0x876162 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x8u)); /* lea eax, [esi + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    PUSH32(c, 0x00876154u); f_00876207(c); /* call 0x876207 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00876160u); f_0087520b(c); /* call 0x87520b */
    goto L_00876181; /* jmp 0x876181 */
L_00876162:;
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x8u)); /* lea eax, [esi + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    PUSH32(c, 0x0087616eu); f_00876207(c); /* call 0x876207 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x0087617au); f_00875204(c); /* call 0x875204 */
    goto L_00876181; /* jmp 0x876181 */
L_0087617c:;
    PUSH32(c, 0x00876181u); f_00876469(c); /* call 0x876469 */
L_00876181:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
L_00876185:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00876194(CPU *c) { /* PTR_00876194 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_00876198(CPU *c) { /* PTR_00876198 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { f_00876408(c); return; } /* jmp 0x876408 */
}

void f_008761a0(CPU *c) { /* FUN_100061a0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x87d258u; PUSH32(c, v_); } /* push 0x1000d258 */
    { uint32_t v_ = 0x877f10u; PUSH32(c, v_); } /* push 0x10007f10 */
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
    if (c->zf) goto L_008761e7; /* je 0x8761e7 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x1cu))); /* mov ecx, dword ptr [eax + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ecx, dword ptr [ecx + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_008761e7; /* je 0x8761e7 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = R32((uint32_t)(c->eax + 0x18u)); PUSH32(c, v_); } /* push dword ptr [eax + 0x18] */
    PUSH32(c, 0x008761e3u); f_00875204(c); /* call 0x875204 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
L_008761e7:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008761f6(CPU *c) { /* PTR_008761f6 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xcu)), ((uint8_t)c->eax)); /* cmp byte ptr [ebp + 0xc], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(!c->zf ? 1 : 0); /* setne al */
    c->esp += 4; return; /* ret  */
}

void f_008761ff(CPU *c) { /* PTR_008761ff */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { f_00876408(c); return; } /* jmp 0x876408 */
}

void f_00876207(CPU *c) { /* FUN_10006207 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov edx, dword ptr [ecx + 4] */
    c->eax = (uint32_t)(add32(c, c->eax, c->esi)); /* add eax, esi */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if ((c->sf != c->of)) goto L_00876228; /* jl 0x876228 */
    c->esi = (uint32_t)(R32((uint32_t)(c->edx + c->esi))); /* mov esi, dword ptr [edx + esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov ecx, dword ptr [ecx + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + c->ecx))); /* mov ecx, dword ptr [esi + ecx] */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->edx)); /* add ecx, edx */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
L_00876228:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00876230(CPU *c) { /* __CallSettingFrame@12 */
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
    PUSH32(c, 0x00876253u); f_00875585(c); /* call 0x875585 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00876257u); call_indirect(c, t_); } /* call eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->ebx = (uint32_t)(c->ebp); /* mov ebx, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->ebx); /* mov ebp, ebx */
    (void)sub32(c, c->ecx, (uint32_t)0x100u); /* cmp ecx, 0x100 */
    if (!c->zf) goto L_0087626f; /* jne 0x87626f */
    c->ecx = (uint32_t)((uint32_t)0x2u); /* mov ecx, 2 */
L_0087626f:;
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00876275u); f_00875585(c); /* call 0x875585 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 16; return; /* ret 0xc */
}

void f_0087627c(CPU *c) { /* FUN_1000627c */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00876282u); f_00876b34(c); /* call 0x876b34 */
    { uint32_t t_ = R32((uint32_t)(0x87d018u)); PUSH32(c, 0x00876288u); call_indirect(c, t_); } /* call dword ptr [0x1000d018] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    W32((uint32_t)(0x87e440u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000e440], eax */
    if (c->zf) goto L_008762cc; /* je 0x8762cc */
    { uint32_t v_ = 0x74u; PUSH32(c, v_); } /* push 0x74 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x0087629bu); f_00878325(c); /* call 0x878325 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_008762cc; /* je 0x8762cc */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(0x87e440u)); PUSH32(c, v_); } /* push dword ptr [0x1000e440] */
    { uint32_t t_ = R32((uint32_t)(0x87d014u)); PUSH32(c, 0x008762b0u); call_indirect(c, t_); } /* call dword ptr [0x1000d014] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008762cc; /* je 0x8762cc */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008762bau); f_008762ee(c); /* call 0x8762ee */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t t_ = R32((uint32_t)(0x87d010u)); PUSH32(c, 0x008762c1u); call_indirect(c, t_); } /* call dword ptr [0x1000d010] */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [esi + 4], 0xffffffff */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_008762cc:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_008762d0(CPU *c) { /* FUN_100062d0 */
    PREEMPT_POLL(c);
    PUSH32(c, 0x008762d5u); f_00876b5d(c); /* call 0x876b5d */
    c->eax = (uint32_t)(R32((uint32_t)(0x87e440u))); /* mov eax, dword ptr [0x1000e440] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (c->zf) goto L_008762ed; /* je 0x8762ed */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x87d01cu)); PUSH32(c, 0x008762e6u); call_indirect(c, t_); } /* call dword ptr [0x1000d01c] */
    { uint32_t a_ = (uint32_t)(0x87e440u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [0x1000e440], 0xffffffff */
L_008762ed:;
    c->esp += 4; return; /* ret  */
}

void f_008762ee(CPU *c) { /* FUN_100062ee */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    W32((uint32_t)(c->eax + 0x50u), (uint32_t)((uint32_t)0x87e810u)); /* mov dword ptr [eax + 0x50], 0x1000e810 */
    W32((uint32_t)(c->eax + 0x14u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [eax + 0x14], 1 */
    c->esp += 4; return; /* ret  */
}

void f_00876301(CPU *c) { /* FUN_10006301 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0x87d028u)); PUSH32(c, 0x00876309u); call_indirect(c, t_); } /* call dword ptr [0x1000d028] */
    { uint32_t v_ = R32((uint32_t)(0x87e440u)); PUSH32(c, v_); } /* push dword ptr [0x1000e440] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    { uint32_t t_ = R32((uint32_t)(0x87d024u)); PUSH32(c, 0x00876317u); call_indirect(c, t_); } /* call dword ptr [0x1000d024] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_0087635c; /* jne 0x87635c */
    { uint32_t v_ = 0x74u; PUSH32(c, v_); } /* push 0x74 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x00876326u); f_00878325(c); /* call 0x878325 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00876354; /* je 0x876354 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(0x87e440u)); PUSH32(c, v_); } /* push dword ptr [0x1000e440] */
    { uint32_t t_ = R32((uint32_t)(0x87d014u)); PUSH32(c, 0x0087633bu); call_indirect(c, t_); } /* call dword ptr [0x1000d014] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00876354; /* je 0x876354 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00876345u); f_008762ee(c); /* call 0x8762ee */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t t_ = R32((uint32_t)(0x87d010u)); PUSH32(c, 0x0087634cu); call_indirect(c, t_); } /* call dword ptr [0x1000d010] */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [esi + 4], 0xffffffff */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    goto L_0087635c; /* jmp 0x87635c */
L_00876354:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    PUSH32(c, 0x0087635bu); f_008759e0(c); /* call 0x8759e0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_0087635c:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0x87d020u)); PUSH32(c, 0x00876363u); call_indirect(c, t_); } /* call dword ptr [0x1000d020] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00876368(CPU *c) { /* FUN_10006368 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x87e440u))); /* mov eax, dword ptr [0x1000e440] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (c->zf) goto L_00876407; /* je 0x876407 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_0087638c; /* jne 0x87638c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x87d024u)); PUSH32(c, 0x00876386u); call_indirect(c, t_); } /* call dword ptr [0x1000d024] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_008763f8; /* je 0x8763f8 */
L_0087638c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov eax, dword ptr [esi + 0x24] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0087639a; /* je 0x87639a */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00876399u); f_00876c3f(c); /* call 0x876c3f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_0087639a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x28u))); /* mov eax, dword ptr [esi + 0x28] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008763a8; /* je 0x8763a8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008763a7u); f_00876c3f(c); /* call 0x876c3f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_008763a8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x30u))); /* mov eax, dword ptr [esi + 0x30] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008763b6; /* je 0x8763b6 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008763b5u); f_00876c3f(c); /* call 0x876c3f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_008763b6:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x38u))); /* mov eax, dword ptr [esi + 0x38] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008763c4; /* je 0x8763c4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008763c3u); f_00876c3f(c); /* call 0x876c3f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_008763c4:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x40u))); /* mov eax, dword ptr [esi + 0x40] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008763d2; /* je 0x8763d2 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008763d1u); f_00876c3f(c); /* call 0x876c3f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_008763d2:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x44u))); /* mov eax, dword ptr [esi + 0x44] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008763e0; /* je 0x8763e0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008763dfu); f_00876c3f(c); /* call 0x876c3f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_008763e0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    (void)sub32(c, c->eax, (uint32_t)0x87e810u); /* cmp eax, 0x1000e810 */
    if (c->zf) goto L_008763f1; /* je 0x8763f1 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008763f0u); f_00876c3f(c); /* call 0x876c3f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_008763f1:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008763f7u); f_00876c3f(c); /* call 0x876c3f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_008763f8:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x87e440u)); PUSH32(c, v_); } /* push dword ptr [0x1000e440] */
    { uint32_t t_ = R32((uint32_t)(0x87d014u)); PUSH32(c, 0x00876406u); call_indirect(c, t_); } /* call dword ptr [0x1000d014] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00876407:;
    c->esp += 4; return; /* ret  */
}

void f_00876408(CPU *c) { /* FUN_10006408 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x87d268u; PUSH32(c, v_); } /* push 0x1000d268 */
    { uint32_t v_ = 0x877f10u; PUSH32(c, v_); } /* push 0x10007f10 */
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
    PUSH32(c, 0x00876437u); f_00876301(c); /* call 0x876301 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x60u)), c->esi); /* cmp dword ptr [eax + 0x60], esi */
    if (c->zf) goto L_0087645b; /* je 0x87645b */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    PUSH32(c, 0x00876448u); f_00876301(c); /* call 0x876301 */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x60u)); PUSH32(c, 0x0087644bu); call_indirect(c, t_); } /* call dword ptr [eax + 0x60] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 4], esi */
    goto L_0087645b; /* jmp 0x87645b */
L_0087645b:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00876464u); f_00876464(c); /* call 0x876464 */
    { f_00878462(c); return; } /* jmp 0x878462 */
}

void f_00876450(CPU *c) { /* PTR_00876450 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_00876454(CPU *c) { /* PTR_00876454 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00876464u); f_00876464(c); /* call 0x876464 */
    { f_00878462(c); return; } /* jmp 0x878462 */
}

void f_00876464(CPU *c) { /* PTR_00876464 */
    PREEMPT_POLL(c);
    { f_00878462(c); return; } /* jmp 0x878462 */
}

void f_00876469(CPU *c) { /* FUN_10006469 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x87d280u; PUSH32(c, v_); } /* push 0x1000d280 */
    { uint32_t v_ = 0x877f10u; PUSH32(c, v_); } /* push 0x10007f10 */
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
    c->eax = (uint32_t)(R32((uint32_t)(0x87e444u))); /* mov eax, dword ptr [0x1000e444] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008764b1; /* je 0x8764b1 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x008764a4u); call_indirect(c, t_); } /* call eax */
    goto L_008764ad; /* jmp 0x8764ad */
L_008764ad:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
L_008764b1:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x008764bau); f_008764ba(c); /* call 0x8764ba */
    { f_00876408(c); return; } /* jmp 0x876408 */
}

void f_008764a6(CPU *c) { /* PTR_008764a6 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_008764aa(CPU *c) { /* PTR_008764aa */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x008764bau); f_008764ba(c); /* call 0x8764ba */
    { f_00876408(c); return; } /* jmp 0x876408 */
}

void f_008764ba(CPU *c) { /* PTR_008764ba */
    PREEMPT_POLL(c);
    { f_00876408(c); return; } /* jmp 0x876408 */
}

void f_008764bf(CPU *c) { /* FUN_100064bf */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x87e428u))); /* mov eax, dword ptr [0x1000e428] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008764ca; /* je 0x8764ca */
    { uint32_t t_ = c->eax; PUSH32(c, 0x008764cau); call_indirect(c, t_); } /* call eax */
L_008764ca:;
    { uint32_t v_ = 0x87e01cu; PUSH32(c, v_); } /* push 0x1000e01c */
    { uint32_t v_ = 0x87e00cu; PUSH32(c, v_); } /* push 0x1000e00c */
    PUSH32(c, 0x008764d9u); f_008765c3(c); /* call 0x8765c3 */
    { uint32_t v_ = 0x87e008u; PUSH32(c, v_); } /* push 0x1000e008 */
    { uint32_t v_ = 0x87e000u; PUSH32(c, v_); } /* push 0x1000e000 */
    PUSH32(c, 0x008764e8u); f_008765c3(c); /* call 0x8765c3 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_008764ec(CPU *c) { /* __exit */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    PUSH32(c, 0x008764f9u); f_0087650c(c); /* call 0x87650c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_008764fd(CPU *c) { /* FUN_100064fd */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    PUSH32(c, 0x00876508u); f_0087650c(c); /* call 0x87650c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_0087650c(CPU *c) { /* FUN_1000650c */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00876512u); f_008765b1(c); /* call 0x8765b1 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    (void)sub32(c, R32((uint32_t)(0x8811ccu)), c->edi); /* cmp dword ptr [0x100111cc], edi */
    if (!c->zf) goto L_0087652e; /* jne 0x87652e */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    { uint32_t t_ = R32((uint32_t)(0x87d034u)); PUSH32(c, 0x00876527u); call_indirect(c, t_); } /* call dword ptr [0x1000d034] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x87d030u)); PUSH32(c, 0x0087652eu); call_indirect(c, t_); } /* call dword ptr [0x1000d030] */
L_0087652e:;
    (void)sub32(c, R32((uint32_t)(c->esp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [esp + 0xc], 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ebx, dword ptr [esp + 0x14] */
    W32((uint32_t)(0x8811c8u), (uint32_t)(c->edi)); /* mov dword ptr [0x100111c8], edi */
    W8((uint32_t)(0x8811c4u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [0x100111c4], bl */
    if (!c->zf) goto L_00876582; /* jne 0x876582 */
    c->eax = (uint32_t)(R32((uint32_t)(0x881850u))); /* mov eax, dword ptr [0x10011850] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00876571; /* je 0x876571 */
    c->ecx = (uint32_t)(R32((uint32_t)(0x88184cu))); /* mov ecx, dword ptr [0x1001184c] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)((uint32_t)(c->ecx + 0xfffffffcu)); /* lea esi, [ecx - 4] */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if (c->cf) goto L_00876570; /* jb 0x876570 */
L_0087655d:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00876565; /* je 0x876565 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00876565u); call_indirect(c, t_); } /* call eax */
L_00876565:;
    c->esi = (uint32_t)(sub32(c, c->esi, (uint32_t)0x4u)); /* sub esi, 4 */
    (void)sub32(c, c->esi, R32((uint32_t)(0x881850u))); /* cmp esi, dword ptr [0x10011850] */
    if (!c->cf) goto L_0087655d; /* jae 0x87655d */
L_00876570:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00876571:;
    { uint32_t v_ = 0x87e024u; PUSH32(c, v_); } /* push 0x1000e024 */
    { uint32_t v_ = 0x87e020u; PUSH32(c, v_); } /* push 0x1000e020 */
    PUSH32(c, 0x00876580u); f_008765c3(c); /* call 0x8765c3 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00876582:;
    { uint32_t v_ = 0x87e030u; PUSH32(c, v_); } /* push 0x1000e030 */
    { uint32_t v_ = 0x87e028u; PUSH32(c, v_); } /* push 0x1000e028 */
    PUSH32(c, 0x00876591u); f_008765c3(c); /* call 0x8765c3 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    if (c->zf) goto L_0087659f; /* je 0x87659f */
    PUSH32(c, 0x0087659du); f_008765ba(c); /* call 0x8765ba */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_0087659f:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    W32((uint32_t)(0x8811ccu), (uint32_t)(c->edi)); /* mov dword ptr [0x100111cc], edi */
    { uint32_t t_ = R32((uint32_t)(0x87d02cu)); PUSH32(c, 0x008765afu); call_indirect(c, t_); } /* call dword ptr [0x1000d02c] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_008765af(CPU *c) { /* PTR_008765af */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_008765b1(CPU *c) { /* FUN_100065b1 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xdu; PUSH32(c, v_); } /* push 0xd */
    PUSH32(c, 0x008765b8u); f_00876bc9(c); /* call 0x876bc9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_008765ba(CPU *c) { /* FUN_100065ba */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xdu; PUSH32(c, v_); } /* push 0xd */
    PUSH32(c, 0x008765c1u); f_00876c2a(c); /* call 0x876c2a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_008765c3(CPU *c) { /* FUN_100065c3 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
L_008765c8:;
    (void)sub32(c, c->esi, R32((uint32_t)(c->esp + 0xcu))); /* cmp esi, dword ptr [esp + 0xc] */
    if (!c->cf) goto L_008765db; /* jae 0x8765db */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008765d6; /* je 0x8765d6 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x008765d6u); call_indirect(c, t_); } /* call eax */
L_008765d6:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    goto L_008765c8; /* jmp 0x8765c8 */
L_008765db:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_008765dd(CPU *c) { /* FUN_100065dd */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x87d298u; PUSH32(c, v_); } /* push 0x1000d298 */
    { uint32_t v_ = 0x877f10u; PUSH32(c, v_); } /* push 0x10007f10 */
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
    if (!c->zf) goto L_00876617; /* jne 0x876617 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x00876611u); f_008769fa(c); /* call 0x8769fa */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_008768fd; /* jmp 0x8768fd */
L_00876617:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_0087662a; /* jne 0x87662a */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00876624u); f_00876c3f(c); /* call 0x876c3f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_008768fb; /* jmp 0x8768fb */
L_0087662a:;
    c->eax = (uint32_t)(R32((uint32_t)(0x881728u))); /* mov eax, dword ptr [0x10011728] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_00876771; /* jne 0x876771 */
L_00876638:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00876735; /* ja 0x876735 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x0087664bu); f_00876bc9(c); /* call 0x876bc9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 4], edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00876655u); f_008784c1(c); /* call 0x8784c1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x28], eax */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (c->zf) goto L_00876705; /* je 0x876705 */
    (void)sub32(c, c->esi, R32((uint32_t)(0x881720u))); /* cmp esi, dword ptr [0x10011720] */
    if ((!c->cf && !c->zf)) goto L_008766b5; /* ja 0x8766b5 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00876671u); f_00878cca(c); /* call 0x878cca */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0087667d; /* je 0x87667d */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x24], ebx */
    goto L_008766b5; /* jmp 0x8766b5 */
L_0087667d:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00876683u); f_00878815(c); /* call 0x878815 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (c->zf) goto L_008766b5; /* je 0x8766b5 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xfffffffcu))); /* mov eax, dword ptr [ebx - 4] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00876698; /* jb 0x876698 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00876698:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x008766a2u); f_008796b0(c); /* call 0x8796b0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x008766a8u); f_008784c1(c); /* call 0x8784c1 */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x28], eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008766b2u); f_008784ec(c); /* call 0x8784ec */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_008766b5:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), c->edi); /* cmp dword ptr [ebp - 0x24], edi */
    if (!c->zf) goto L_00876705; /* jne 0x876705 */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_008766c4; /* jne 0x8766c4 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_008766c4:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0x881724u)); PUSH32(c, v_); } /* push dword ptr [0x10011724] */
    { uint32_t t_ = R32((uint32_t)(0x87d03cu)); PUSH32(c, 0x008766dbu); call_indirect(c, t_); } /* call dword ptr [0x1000d03c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (c->zf) goto L_00876705; /* je 0x876705 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xfffffffcu))); /* mov eax, dword ptr [ebx - 4] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_008766ef; /* jb 0x8766ef */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_008766ef:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x008766f9u); f_008796b0(c); /* call 0x8796b0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x28] */
    PUSH32(c, 0x00876702u); f_008784ec(c); /* call 0x8784ec */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
L_00876705:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x0087670eu); f_00876768(c); /* call 0x876768 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), c->edi); /* cmp dword ptr [ebp - 0x28], edi */
    if (!c->zf) goto L_00876735; /* jne 0x876735 */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_0087671a; /* jne 0x87671a */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_0087671a:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0x881724u)); PUSH32(c, v_); } /* push dword ptr [0x10011724] */
    { uint32_t t_ = R32((uint32_t)(0x87d038u)); PUSH32(c, 0x00876732u); call_indirect(c, t_); } /* call dword ptr [0x1000d038] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_00876735:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_008768fd; /* jne 0x8768fd */
    (void)sub32(c, R32((uint32_t)(0x881348u)), c->edi); /* cmp dword ptr [0x10011348], edi */
    if (c->zf) goto L_008768fd; /* je 0x8768fd */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00876752u); f_0087968d(c); /* call 0x87968d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00876638; /* jne 0x876638 */
    goto L_008768fb; /* jmp 0x8768fb */
L_00876771:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_008768c1; /* jne 0x8768c1 */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00876791; /* ja 0x876791 */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if ((c->cf || c->zf)) goto L_0087678b; /* jbe 0x87678b */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    goto L_0087678e; /* jmp 0x87678e */
L_0087678b:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_0087678e:;
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_00876791:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00876890; /* ja 0x876890 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x008767a4u); f_00876bc9(c); /* call 0x876bc9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x008767bau); f_0087921c(c); /* call 0x87921c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00876874; /* je 0x876874 */
    (void)sub32(c, c->esi, R32((uint32_t)(0x8808bcu))); /* cmp esi, dword ptr [0x100108bc] */
    if (!c->cf) goto L_0087682e; /* jae 0x87682e */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 4)); /* shr ebx, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x008767e4u); f_008795e4(c); /* call 0x8795e4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008767f3; /* je 0x8767f3 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_0087682b; /* jmp 0x87682b */
L_008767f3:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x008767f9u); f_008792b8(c); /* call 0x8792b8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0087682b; /* je 0x87682b */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00876810; /* jb 0x876810 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00876810:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x0087681cu); f_008796b0(c); /* call 0x8796b0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00876828u); f_00879273(c); /* call 0x879273 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_0087682b:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_0087682e:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00876887; /* jne 0x876887 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x881724u)); PUSH32(c, v_); } /* push dword ptr [0x10011724] */
    { uint32_t t_ = R32((uint32_t)(0x87d03cu)); PUSH32(c, 0x00876843u); call_indirect(c, t_); } /* call dword ptr [0x1000d03c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00876887; /* je 0x876887 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00876859; /* jb 0x876859 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00876859:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00876863u); f_008796b0(c); /* call 0x8796b0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x0087686fu); f_00879273(c); /* call 0x879273 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00876887; /* jmp 0x876887 */
L_00876874:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x881724u)); PUSH32(c, v_); } /* push dword ptr [0x10011724] */
    { uint32_t t_ = R32((uint32_t)(0x87d038u)); PUSH32(c, 0x00876884u); call_indirect(c, t_); } /* call dword ptr [0x1000d038] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_00876887:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00876890u); f_008768b6(c); /* call 0x8768b6 */
L_00876890:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_008768fd; /* jne 0x8768fd */
    (void)sub32(c, R32((uint32_t)(0x881348u)), c->edi); /* cmp dword ptr [0x10011348], edi */
    if (c->zf) goto L_008768fd; /* je 0x8768fd */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008768a5u); f_0087968d(c); /* call 0x87968d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00876791; /* jne 0x876791 */
    goto L_008768fb; /* jmp 0x8768fb */
L_008768c1:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_008768e4; /* ja 0x8768e4 */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_008768cf; /* jne 0x8768cf */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_008768cf:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0x881724u)); PUSH32(c, v_); } /* push dword ptr [0x10011724] */
    { uint32_t t_ = R32((uint32_t)(0x87d038u)); PUSH32(c, 0x008768e4u); call_indirect(c, t_); } /* call dword ptr [0x1000d038] */
L_008768e4:;
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_008768fd; /* jne 0x8768fd */
    (void)sub32(c, R32((uint32_t)(0x881348u)), c->edi); /* cmp dword ptr [0x10011348], edi */
    if (c->zf) goto L_008768fd; /* je 0x8768fd */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008768f6u); f_0087968d(c); /* call 0x87968d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_008768c1; /* jne 0x8768c1 */
L_008768fb:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_008768fd:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00876760(CPU *c) { /* PTR_00876760 */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    { f_00876768(c); return; }
}

void f_00876768(CPU *c) { /* FUN_10006768 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x0087676fu); f_00876c2a(c); /* call 0x876c2a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00876771(CPU *c) { /* PTR_00876771 */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) { f_008768c1(c); return; } /* jne 0x8768c1 */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00876791; /* ja 0x876791 */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if ((c->cf || c->zf)) goto L_0087678b; /* jbe 0x87678b */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    goto L_0087678e; /* jmp 0x87678e */
L_0087678b:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_0087678e:;
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_00876791:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00876890; /* ja 0x876890 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x008767a4u); f_00876bc9(c); /* call 0x876bc9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x008767bau); f_0087921c(c); /* call 0x87921c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00876874; /* je 0x876874 */
    (void)sub32(c, c->esi, R32((uint32_t)(0x8808bcu))); /* cmp esi, dword ptr [0x100108bc] */
    if (!c->cf) goto L_0087682e; /* jae 0x87682e */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 4)); /* shr ebx, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x008767e4u); f_008795e4(c); /* call 0x8795e4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008767f3; /* je 0x8767f3 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_0087682b; /* jmp 0x87682b */
L_008767f3:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x008767f9u); f_008792b8(c); /* call 0x8792b8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0087682b; /* je 0x87682b */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00876810; /* jb 0x876810 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00876810:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x0087681cu); f_008796b0(c); /* call 0x8796b0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00876828u); f_00879273(c); /* call 0x879273 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_0087682b:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_0087682e:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00876887; /* jne 0x876887 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x881724u)); PUSH32(c, v_); } /* push dword ptr [0x10011724] */
    { uint32_t t_ = R32((uint32_t)(0x87d03cu)); PUSH32(c, 0x00876843u); call_indirect(c, t_); } /* call dword ptr [0x1000d03c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00876887; /* je 0x876887 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00876859; /* jb 0x876859 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00876859:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00876863u); f_008796b0(c); /* call 0x8796b0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x0087686fu); f_00879273(c); /* call 0x879273 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00876887; /* jmp 0x876887 */
L_00876874:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x881724u)); PUSH32(c, v_); } /* push dword ptr [0x10011724] */
    { uint32_t t_ = R32((uint32_t)(0x87d038u)); PUSH32(c, 0x00876884u); call_indirect(c, t_); } /* call dword ptr [0x1000d038] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_00876887:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00876890u); f_008768b6(c); /* call 0x8768b6 */
L_00876890:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_008768fd(c); return; } /* jne 0x8768fd */
    (void)sub32(c, R32((uint32_t)(0x881348u)), c->edi); /* cmp dword ptr [0x10011348], edi */
    if (c->zf) { f_008768fd(c); return; } /* je 0x8768fd */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008768a5u); f_0087968d(c); /* call 0x87968d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00876791; /* jne 0x876791 */
    { f_008768fb(c); return; } /* jmp 0x8768fb */
}

void f_0087678b(CPU *c) { /* PTR_0087678b */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_00876791:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00876890; /* ja 0x876890 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x008767a4u); f_00876bc9(c); /* call 0x876bc9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x008767bau); f_0087921c(c); /* call 0x87921c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00876874; /* je 0x876874 */
    (void)sub32(c, c->esi, R32((uint32_t)(0x8808bcu))); /* cmp esi, dword ptr [0x100108bc] */
    if (!c->cf) goto L_0087682e; /* jae 0x87682e */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 4)); /* shr ebx, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x008767e4u); f_008795e4(c); /* call 0x8795e4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008767f3; /* je 0x8767f3 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_0087682b; /* jmp 0x87682b */
L_008767f3:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x008767f9u); f_008792b8(c); /* call 0x8792b8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0087682b; /* je 0x87682b */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00876810; /* jb 0x876810 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00876810:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x0087681cu); f_008796b0(c); /* call 0x8796b0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00876828u); f_00879273(c); /* call 0x879273 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_0087682b:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_0087682e:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00876887; /* jne 0x876887 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x881724u)); PUSH32(c, v_); } /* push dword ptr [0x10011724] */
    { uint32_t t_ = R32((uint32_t)(0x87d03cu)); PUSH32(c, 0x00876843u); call_indirect(c, t_); } /* call dword ptr [0x1000d03c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00876887; /* je 0x876887 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00876859; /* jb 0x876859 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00876859:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00876863u); f_008796b0(c); /* call 0x8796b0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x0087686fu); f_00879273(c); /* call 0x879273 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00876887; /* jmp 0x876887 */
L_00876874:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x881724u)); PUSH32(c, v_); } /* push dword ptr [0x10011724] */
    { uint32_t t_ = R32((uint32_t)(0x87d038u)); PUSH32(c, 0x00876884u); call_indirect(c, t_); } /* call dword ptr [0x1000d038] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_00876887:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00876890u); f_008768b6(c); /* call 0x8768b6 */
L_00876890:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_008768fd(c); return; } /* jne 0x8768fd */
    (void)sub32(c, R32((uint32_t)(0x881348u)), c->edi); /* cmp dword ptr [0x10011348], edi */
    if (c->zf) { f_008768fd(c); return; } /* je 0x8768fd */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008768a5u); f_0087968d(c); /* call 0x87968d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00876791; /* jne 0x876791 */
    { f_008768fb(c); return; } /* jmp 0x8768fb */
}

void f_0087678e(CPU *c) { /* PTR_0087678e */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_00876791:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00876890; /* ja 0x876890 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x008767a4u); f_00876bc9(c); /* call 0x876bc9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x008767bau); f_0087921c(c); /* call 0x87921c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00876874; /* je 0x876874 */
    (void)sub32(c, c->esi, R32((uint32_t)(0x8808bcu))); /* cmp esi, dword ptr [0x100108bc] */
    if (!c->cf) goto L_0087682e; /* jae 0x87682e */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 4)); /* shr ebx, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x008767e4u); f_008795e4(c); /* call 0x8795e4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008767f3; /* je 0x8767f3 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_0087682b; /* jmp 0x87682b */
L_008767f3:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x008767f9u); f_008792b8(c); /* call 0x8792b8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0087682b; /* je 0x87682b */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00876810; /* jb 0x876810 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00876810:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x0087681cu); f_008796b0(c); /* call 0x8796b0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00876828u); f_00879273(c); /* call 0x879273 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_0087682b:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_0087682e:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00876887; /* jne 0x876887 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x881724u)); PUSH32(c, v_); } /* push dword ptr [0x10011724] */
    { uint32_t t_ = R32((uint32_t)(0x87d03cu)); PUSH32(c, 0x00876843u); call_indirect(c, t_); } /* call dword ptr [0x1000d03c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00876887; /* je 0x876887 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00876859; /* jb 0x876859 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00876859:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00876863u); f_008796b0(c); /* call 0x8796b0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x0087686fu); f_00879273(c); /* call 0x879273 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00876887; /* jmp 0x876887 */
L_00876874:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x881724u)); PUSH32(c, v_); } /* push dword ptr [0x10011724] */
    { uint32_t t_ = R32((uint32_t)(0x87d038u)); PUSH32(c, 0x00876884u); call_indirect(c, t_); } /* call dword ptr [0x1000d038] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_00876887:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00876890u); f_008768b6(c); /* call 0x8768b6 */
L_00876890:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_008768fd(c); return; } /* jne 0x8768fd */
    (void)sub32(c, R32((uint32_t)(0x881348u)), c->edi); /* cmp dword ptr [0x10011348], edi */
    if (c->zf) { f_008768fd(c); return; } /* je 0x8768fd */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008768a5u); f_0087968d(c); /* call 0x87968d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00876791; /* jne 0x876791 */
    { f_008768fb(c); return; } /* jmp 0x8768fb */
}

void f_00876791(CPU *c) { /* PTR_00876791 */
    PREEMPT_POLL(c);
L_00876791:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00876890; /* ja 0x876890 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x008767a4u); f_00876bc9(c); /* call 0x876bc9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x008767bau); f_0087921c(c); /* call 0x87921c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00876874; /* je 0x876874 */
    (void)sub32(c, c->esi, R32((uint32_t)(0x8808bcu))); /* cmp esi, dword ptr [0x100108bc] */
    if (!c->cf) goto L_0087682e; /* jae 0x87682e */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 4)); /* shr ebx, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x008767e4u); f_008795e4(c); /* call 0x8795e4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008767f3; /* je 0x8767f3 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_0087682b; /* jmp 0x87682b */
L_008767f3:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x008767f9u); f_008792b8(c); /* call 0x8792b8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0087682b; /* je 0x87682b */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00876810; /* jb 0x876810 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00876810:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x0087681cu); f_008796b0(c); /* call 0x8796b0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00876828u); f_00879273(c); /* call 0x879273 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_0087682b:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_0087682e:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00876887; /* jne 0x876887 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x881724u)); PUSH32(c, v_); } /* push dword ptr [0x10011724] */
    { uint32_t t_ = R32((uint32_t)(0x87d03cu)); PUSH32(c, 0x00876843u); call_indirect(c, t_); } /* call dword ptr [0x1000d03c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00876887; /* je 0x876887 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00876859; /* jb 0x876859 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00876859:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00876863u); f_008796b0(c); /* call 0x8796b0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x0087686fu); f_00879273(c); /* call 0x879273 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00876887; /* jmp 0x876887 */
L_00876874:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x881724u)); PUSH32(c, v_); } /* push dword ptr [0x10011724] */
    { uint32_t t_ = R32((uint32_t)(0x87d038u)); PUSH32(c, 0x00876884u); call_indirect(c, t_); } /* call dword ptr [0x1000d038] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_00876887:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00876890u); f_008768b6(c); /* call 0x8768b6 */
L_00876890:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_008768fd(c); return; } /* jne 0x8768fd */
    (void)sub32(c, R32((uint32_t)(0x881348u)), c->edi); /* cmp dword ptr [0x10011348], edi */
    if (c->zf) { f_008768fd(c); return; } /* je 0x8768fd */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008768a5u); f_0087968d(c); /* call 0x87968d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00876791; /* jne 0x876791 */
    { f_008768fb(c); return; } /* jmp 0x8768fb */
}

void f_008767f3(CPU *c) { /* PTR_008767f3 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x008767f9u); f_008792b8(c); /* call 0x8792b8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0087682b; /* je 0x87682b */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00876810; /* jb 0x876810 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00876810:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x0087681cu); f_008796b0(c); /* call 0x8796b0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00876828u); f_00879273(c); /* call 0x879273 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_0087682b:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00876887; /* jne 0x876887 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x881724u)); PUSH32(c, v_); } /* push dword ptr [0x10011724] */
    { uint32_t t_ = R32((uint32_t)(0x87d03cu)); PUSH32(c, 0x00876843u); call_indirect(c, t_); } /* call dword ptr [0x1000d03c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00876887; /* je 0x876887 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00876859; /* jb 0x876859 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00876859:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00876863u); f_008796b0(c); /* call 0x8796b0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x0087686fu); f_00879273(c); /* call 0x879273 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00876887; /* jmp 0x876887 */
L_00876887:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00876890u); f_008768b6(c); /* call 0x8768b6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_008768fd(c); return; } /* jne 0x8768fd */
    (void)sub32(c, R32((uint32_t)(0x881348u)), c->edi); /* cmp dword ptr [0x10011348], edi */
    if (c->zf) { f_008768fd(c); return; } /* je 0x8768fd */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008768a5u); f_0087968d(c); /* call 0x87968d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00876791(c); return; } /* jne 0x876791 */
    { f_008768fb(c); return; } /* jmp 0x8768fb */
}

void f_0087680c(CPU *c) { /* PTR_0087680c */
    PREEMPT_POLL(c);
    if (c->cf) goto L_00876810; /* jb 0x876810 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00876810:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x0087681cu); f_008796b0(c); /* call 0x8796b0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00876828u); f_00879273(c); /* call 0x879273 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00876887; /* jne 0x876887 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x881724u)); PUSH32(c, v_); } /* push dword ptr [0x10011724] */
    { uint32_t t_ = R32((uint32_t)(0x87d03cu)); PUSH32(c, 0x00876843u); call_indirect(c, t_); } /* call dword ptr [0x1000d03c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00876887; /* je 0x876887 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00876859; /* jb 0x876859 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00876859:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00876863u); f_008796b0(c); /* call 0x8796b0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x0087686fu); f_00879273(c); /* call 0x879273 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00876887; /* jmp 0x876887 */
L_00876887:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00876890u); f_008768b6(c); /* call 0x8768b6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_008768fd(c); return; } /* jne 0x8768fd */
    (void)sub32(c, R32((uint32_t)(0x881348u)), c->edi); /* cmp dword ptr [0x10011348], edi */
    if (c->zf) { f_008768fd(c); return; } /* je 0x8768fd */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008768a5u); f_0087968d(c); /* call 0x87968d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00876791(c); return; } /* jne 0x876791 */
    { f_008768fb(c); return; } /* jmp 0x8768fb */
}

void f_00876810(CPU *c) { /* PTR_00876810 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x0087681cu); f_008796b0(c); /* call 0x8796b0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00876828u); f_00879273(c); /* call 0x879273 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00876887; /* jne 0x876887 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x881724u)); PUSH32(c, v_); } /* push dword ptr [0x10011724] */
    { uint32_t t_ = R32((uint32_t)(0x87d03cu)); PUSH32(c, 0x00876843u); call_indirect(c, t_); } /* call dword ptr [0x1000d03c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00876887; /* je 0x876887 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00876859; /* jb 0x876859 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00876859:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00876863u); f_008796b0(c); /* call 0x8796b0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x0087686fu); f_00879273(c); /* call 0x879273 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00876887; /* jmp 0x876887 */
L_00876887:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00876890u); f_008768b6(c); /* call 0x8768b6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_008768fd(c); return; } /* jne 0x8768fd */
    (void)sub32(c, R32((uint32_t)(0x881348u)), c->edi); /* cmp dword ptr [0x10011348], edi */
    if (c->zf) { f_008768fd(c); return; } /* je 0x8768fd */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008768a5u); f_0087968d(c); /* call 0x87968d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00876791(c); return; } /* jne 0x876791 */
    { f_008768fb(c); return; } /* jmp 0x8768fb */
}

void f_0087682b(CPU *c) { /* PTR_0087682b */
    PREEMPT_POLL(c);
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00876887; /* jne 0x876887 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x881724u)); PUSH32(c, v_); } /* push dword ptr [0x10011724] */
    { uint32_t t_ = R32((uint32_t)(0x87d03cu)); PUSH32(c, 0x00876843u); call_indirect(c, t_); } /* call dword ptr [0x1000d03c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00876887; /* je 0x876887 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00876859; /* jb 0x876859 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00876859:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00876863u); f_008796b0(c); /* call 0x8796b0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x0087686fu); f_00879273(c); /* call 0x879273 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00876887; /* jmp 0x876887 */
L_00876887:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00876890u); f_008768b6(c); /* call 0x8768b6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_008768fd(c); return; } /* jne 0x8768fd */
    (void)sub32(c, R32((uint32_t)(0x881348u)), c->edi); /* cmp dword ptr [0x10011348], edi */
    if (c->zf) { f_008768fd(c); return; } /* je 0x8768fd */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008768a5u); f_0087968d(c); /* call 0x87968d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00876791(c); return; } /* jne 0x876791 */
    { f_008768fb(c); return; } /* jmp 0x8768fb */
}

void f_0087682e(CPU *c) { /* PTR_0087682e */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00876887; /* jne 0x876887 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x881724u)); PUSH32(c, v_); } /* push dword ptr [0x10011724] */
    { uint32_t t_ = R32((uint32_t)(0x87d03cu)); PUSH32(c, 0x00876843u); call_indirect(c, t_); } /* call dword ptr [0x1000d03c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00876887; /* je 0x876887 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00876859; /* jb 0x876859 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00876859:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00876863u); f_008796b0(c); /* call 0x8796b0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x0087686fu); f_00879273(c); /* call 0x879273 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00876887; /* jmp 0x876887 */
L_00876887:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00876890u); f_008768b6(c); /* call 0x8768b6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_008768fd(c); return; } /* jne 0x8768fd */
    (void)sub32(c, R32((uint32_t)(0x881348u)), c->edi); /* cmp dword ptr [0x10011348], edi */
    if (c->zf) { f_008768fd(c); return; } /* je 0x8768fd */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008768a5u); f_0087968d(c); /* call 0x87968d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00876791(c); return; } /* jne 0x876791 */
    { f_008768fb(c); return; } /* jmp 0x8768fb */
}

void f_00876859(CPU *c) { /* PTR_00876859 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00876863u); f_008796b0(c); /* call 0x8796b0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x0087686fu); f_00879273(c); /* call 0x879273 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00876887; /* jmp 0x876887 */
L_00876887:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00876890u); f_008768b6(c); /* call 0x8768b6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_008768fd(c); return; } /* jne 0x8768fd */
    (void)sub32(c, R32((uint32_t)(0x881348u)), c->edi); /* cmp dword ptr [0x10011348], edi */
    if (c->zf) { f_008768fd(c); return; } /* je 0x8768fd */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008768a5u); f_0087968d(c); /* call 0x87968d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00876791(c); return; } /* jne 0x876791 */
    { f_008768fb(c); return; } /* jmp 0x8768fb */
}

void f_00876874(CPU *c) { /* PTR_00876874 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x881724u)); PUSH32(c, v_); } /* push dword ptr [0x10011724] */
    { uint32_t t_ = R32((uint32_t)(0x87d038u)); PUSH32(c, 0x00876884u); call_indirect(c, t_); } /* call dword ptr [0x1000d038] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00876890u); f_008768b6(c); /* call 0x8768b6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_008768fd(c); return; } /* jne 0x8768fd */
    (void)sub32(c, R32((uint32_t)(0x881348u)), c->edi); /* cmp dword ptr [0x10011348], edi */
    if (c->zf) { f_008768fd(c); return; } /* je 0x8768fd */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008768a5u); f_0087968d(c); /* call 0x87968d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00876791(c); return; } /* jne 0x876791 */
    { f_008768fb(c); return; } /* jmp 0x8768fb */
}

void f_00876887(CPU *c) { /* PTR_00876887 */
    PREEMPT_POLL(c);
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00876890u); f_008768b6(c); /* call 0x8768b6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_008768fd(c); return; } /* jne 0x8768fd */
    (void)sub32(c, R32((uint32_t)(0x881348u)), c->edi); /* cmp dword ptr [0x10011348], edi */
    if (c->zf) { f_008768fd(c); return; } /* je 0x8768fd */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008768a5u); f_0087968d(c); /* call 0x87968d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00876791(c); return; } /* jne 0x876791 */
    { f_008768fb(c); return; } /* jmp 0x8768fb */
}

void f_00876890(CPU *c) { /* PTR_00876890 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_008768fd(c); return; } /* jne 0x8768fd */
    (void)sub32(c, R32((uint32_t)(0x881348u)), c->edi); /* cmp dword ptr [0x10011348], edi */
    if (c->zf) { f_008768fd(c); return; } /* je 0x8768fd */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008768a5u); f_0087968d(c); /* call 0x87968d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00876791(c); return; } /* jne 0x876791 */
    { f_008768fb(c); return; } /* jmp 0x8768fb */
}

void f_008768b0(CPU *c) { /* PTR_008768b0 */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    { f_008768b6(c); return; }
}

void f_008768b6(CPU *c) { /* FUN_100068b6 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x008768bdu); f_00876c2a(c); /* call 0x876c2a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    c->esp += 4; return; /* ret  */
}

void f_008768c1(CPU *c) { /* PTR_008768c1 */
    PREEMPT_POLL(c);
L_008768c1:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_008768e4; /* ja 0x8768e4 */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_008768cf; /* jne 0x8768cf */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_008768cf:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0x881724u)); PUSH32(c, v_); } /* push dword ptr [0x10011724] */
    { uint32_t t_ = R32((uint32_t)(0x87d038u)); PUSH32(c, 0x008768e4u); call_indirect(c, t_); } /* call dword ptr [0x1000d038] */
L_008768e4:;
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_008768fd; /* jne 0x8768fd */
    (void)sub32(c, R32((uint32_t)(0x881348u)), c->edi); /* cmp dword ptr [0x10011348], edi */
    if (c->zf) goto L_008768fd; /* je 0x8768fd */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008768f6u); f_0087968d(c); /* call 0x87968d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_008768c1; /* jne 0x8768c1 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_008768fd:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008768cf(CPU *c) { /* PTR_008768cf */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0x881724u)); PUSH32(c, v_); } /* push dword ptr [0x10011724] */
    { uint32_t t_ = R32((uint32_t)(0x87d038u)); PUSH32(c, 0x008768e4u); call_indirect(c, t_); } /* call dword ptr [0x1000d038] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_008768fd; /* jne 0x8768fd */
    (void)sub32(c, R32((uint32_t)(0x881348u)), c->edi); /* cmp dword ptr [0x10011348], edi */
    if (c->zf) goto L_008768fd; /* je 0x8768fd */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008768f6u); f_0087968d(c); /* call 0x87968d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_008768c1(c); return; } /* jne 0x8768c1 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_008768fd:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008768e4(CPU *c) { /* PTR_008768e4 */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_008768fd; /* jne 0x8768fd */
    (void)sub32(c, R32((uint32_t)(0x881348u)), c->edi); /* cmp dword ptr [0x10011348], edi */
    if (c->zf) goto L_008768fd; /* je 0x8768fd */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008768f6u); f_0087968d(c); /* call 0x87968d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_008768c1(c); return; } /* jne 0x8768c1 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_008768fd:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008768fb(CPU *c) { /* PTR_008768fb */
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

void f_008768fd(CPU *c) { /* PTR_008768fd */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0087690c(CPU *c) { /* FUN_1000690c */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x87d2b0u; PUSH32(c, v_); } /* push 0x1000d2b0 */
    { uint32_t v_ = 0x877f10u; PUSH32(c, v_); } /* push 0x10007f10 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x1cu)); /* sub esp, 0x1c */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(0x881728u))); /* mov eax, dword ptr [0x10011728] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_0087697f; /* jne 0x87697f */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00876940u); f_00876bc9(c); /* call 0x876bc9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x0087694eu); f_008784c1(c); /* call 0x8784c1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00876961; /* je 0x876961 */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0xfffffffcu))); /* mov esi, dword ptr [esi - 4] */
    c->esi = (uint32_t)(sub32(c, c->esi, (uint32_t)0x9u)); /* sub esi, 9 */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x20], esi */
    goto L_00876964; /* jmp 0x876964 */
L_00876961:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
L_00876964:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x0087696du); f_00876976(c); /* call 0x876976 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x1c], 0 */
    goto L_008769c8; /* jmp 0x8769c8 */
L_0087697f:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_008769ca; /* jne 0x8769ca */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x0087698bu); f_00876bc9(c); /* call 0x876bc9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffdcu)); /* lea eax, [ebp - 0x24] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x008769a3u); f_0087921c(c); /* call 0x87921c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x28], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008769b8; /* je 0x8769b8 */
    c->esi = (uint32_t)((uint32_t)R8((uint32_t)(c->eax))); /* movzx esi, byte ptr [eax] */
    c->esi = (uint32_t)(shl32(c, c->esi, 4)); /* shl esi, 4 */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x20], esi */
    goto L_008769bb; /* jmp 0x8769bb */
L_008769b8:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
L_008769bb:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x008769c4u); f_008769f1(c); /* call 0x8769f1 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x28], 0 */
L_008769c8:;
    if (!c->zf) goto L_008769dd; /* jne 0x8769dd */
L_008769ca:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x881724u)); PUSH32(c, v_); } /* push dword ptr [0x10011724] */
    { uint32_t t_ = R32((uint32_t)(0x87d040u)); PUSH32(c, 0x008769dbu); call_indirect(c, t_); } /* call dword ptr [0x1000d040] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_008769dd:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00876973(CPU *c) { /* PTR_00876973 */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
    { f_00876976(c); return; }
}

void f_00876976(CPU *c) { /* FUN_10006976 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x0087697du); f_00876c2a(c); /* call 0x876c2a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_0087697f(CPU *c) { /* PTR_0087697f */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_008769ca; /* jne 0x8769ca */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x0087698bu); f_00876bc9(c); /* call 0x876bc9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffdcu)); /* lea eax, [ebp - 0x24] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x008769a3u); f_0087921c(c); /* call 0x87921c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x28], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008769b8; /* je 0x8769b8 */
    c->esi = (uint32_t)((uint32_t)R8((uint32_t)(c->eax))); /* movzx esi, byte ptr [eax] */
    c->esi = (uint32_t)(shl32(c, c->esi, 4)); /* shl esi, 4 */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x20], esi */
    goto L_008769bb; /* jmp 0x8769bb */
L_008769b8:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
L_008769bb:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x008769c4u); f_008769f1(c); /* call 0x8769f1 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x28], 0 */
    if (!c->zf) goto L_008769dd; /* jne 0x8769dd */
L_008769ca:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x881724u)); PUSH32(c, v_); } /* push dword ptr [0x10011724] */
    { uint32_t t_ = R32((uint32_t)(0x87d040u)); PUSH32(c, 0x008769dbu); call_indirect(c, t_); } /* call dword ptr [0x1000d040] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_008769dd:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008769b8(CPU *c) { /* PTR_008769b8 */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x008769c4u); f_008769f1(c); /* call 0x8769f1 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x28], 0 */
    if (!c->zf) goto L_008769dd; /* jne 0x8769dd */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x881724u)); PUSH32(c, v_); } /* push dword ptr [0x10011724] */
    { uint32_t t_ = R32((uint32_t)(0x87d040u)); PUSH32(c, 0x008769dbu); call_indirect(c, t_); } /* call dword ptr [0x1000d040] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_008769dd:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008769bb(CPU *c) { /* PTR_008769bb */
    PREEMPT_POLL(c);
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x008769c4u); f_008769f1(c); /* call 0x8769f1 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x28], 0 */
    if (!c->zf) goto L_008769dd; /* jne 0x8769dd */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x881724u)); PUSH32(c, v_); } /* push dword ptr [0x10011724] */
    { uint32_t t_ = R32((uint32_t)(0x87d040u)); PUSH32(c, 0x008769dbu); call_indirect(c, t_); } /* call dword ptr [0x1000d040] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_008769dd:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008769c8(CPU *c) { /* PTR_008769c8 */
    PREEMPT_POLL(c);
    if (!c->zf) goto L_008769dd; /* jne 0x8769dd */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x881724u)); PUSH32(c, v_); } /* push dword ptr [0x10011724] */
    { uint32_t t_ = R32((uint32_t)(0x87d040u)); PUSH32(c, 0x008769dbu); call_indirect(c, t_); } /* call dword ptr [0x1000d040] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_008769dd:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008769ca(CPU *c) { /* PTR_008769ca */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x881724u)); PUSH32(c, v_); } /* push dword ptr [0x10011724] */
    { uint32_t t_ = R32((uint32_t)(0x87d040u)); PUSH32(c, 0x008769dbu); call_indirect(c, t_); } /* call dword ptr [0x1000d040] */
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

void f_008769dd(CPU *c) { /* PTR_008769dd */
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

void f_008769ee(CPU *c) { /* PTR_008769ee */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
    { f_008769f1(c); return; }
}

void f_008769f1(CPU *c) { /* FUN_100069f1 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x008769f8u); f_00876c2a(c); /* call 0x876c2a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_008769fa(CPU *c) { /* _malloc */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(0x881348u)); PUSH32(c, v_); } /* push dword ptr [0x10011348] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    PUSH32(c, 0x00876a09u); f_00876a0c(c); /* call 0x876a0c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00876a0c(CPU *c) { /* __nh_malloc */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->esp + 0x4u)), (uint32_t)0xffffffe0u); /* cmp dword ptr [esp + 4], -0x20 */
    if ((!c->cf && !c->zf)) goto L_00876a35; /* ja 0x876a35 */
L_00876a13:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    PUSH32(c, 0x00876a1cu); f_00876a38(c); /* call 0x876a38 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00876a37; /* jne 0x876a37 */
    (void)sub32(c, R32((uint32_t)(c->esp + 0x8u)), c->eax); /* cmp dword ptr [esp + 8], eax */
    if (c->zf) goto L_00876a37; /* je 0x876a37 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    PUSH32(c, 0x00876a30u); f_0087968d(c); /* call 0x87968d */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00876a13; /* jne 0x876a13 */
L_00876a35:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00876a37:;
    c->esp += 4; return; /* ret  */
}

void f_00876a38(CPU *c) { /* FUN_10006a38 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x87d2c8u; PUSH32(c, v_); } /* push 0x1000d2c8 */
    { uint32_t v_ = 0x877f10u; PUSH32(c, v_); } /* push 0x10007f10 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(0x881728u))); /* mov eax, dword ptr [0x10011728] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_00876aa8; /* jne 0x876aa8 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    (void)sub32(c, c->esi, R32((uint32_t)(0x881720u))); /* cmp esi, dword ptr [0x10011720] */
    if ((!c->cf && !c->zf)) goto L_00876b07; /* ja 0x876b07 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00876a7bu); f_00876bc9(c); /* call 0x876bc9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00876a86u); f_00878815(c); /* call 0x878815 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00876a93u); f_00876a9f(c); /* call 0x876a9f */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00876b07; /* je 0x876b07 */
    goto L_00876b25; /* jmp 0x876b25 */
L_00876aa8:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00876b07; /* jne 0x876b07 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00876abc; /* je 0x876abc */
    c->esi = (uint32_t)((uint32_t)(c->eax + 0xfu)); /* lea esi, [eax + 0xf] */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    goto L_00876abf; /* jmp 0x876abf */
L_00876abc:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00876abf:;
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
    (void)sub32(c, c->esi, R32((uint32_t)(0x8808bcu))); /* cmp esi, dword ptr [0x100108bc] */
    if ((!c->cf && !c->zf)) goto L_00876af8; /* ja 0x876af8 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00876ad1u); f_00876bc9(c); /* call 0x876bc9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00876ae4u); f_008792b8(c); /* call 0x8792b8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00876af1u); f_00876afe(c); /* call 0x876afe */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00876b25; /* jne 0x876b25 */
L_00876af8:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    goto L_00876b17; /* jmp 0x876b17 */
L_00876b07:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00876b11; /* jne 0x876b11 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00876b11:;
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xfu)); /* add eax, 0xf */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xf0u))); /* and al, 0xf0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
L_00876b17:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x881724u)); PUSH32(c, v_); } /* push dword ptr [0x10011724] */
    { uint32_t t_ = R32((uint32_t)(0x87d03cu)); PUSH32(c, 0x00876b25u); call_indirect(c, t_); } /* call dword ptr [0x1000d03c] */
L_00876b25:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00876a9f(CPU *c) { /* FUN_10006a9f */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00876aa6u); f_00876c2a(c); /* call 0x876c2a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00876aa8(CPU *c) { /* PTR_00876aa8 */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) { f_00876b07(c); return; } /* jne 0x876b07 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00876abc; /* je 0x876abc */
    c->esi = (uint32_t)((uint32_t)(c->eax + 0xfu)); /* lea esi, [eax + 0xf] */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    goto L_00876abf; /* jmp 0x876abf */
L_00876abc:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00876abf:;
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
    (void)sub32(c, c->esi, R32((uint32_t)(0x8808bcu))); /* cmp esi, dword ptr [0x100108bc] */
    if ((!c->cf && !c->zf)) goto L_00876af8; /* ja 0x876af8 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00876ad1u); f_00876bc9(c); /* call 0x876bc9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00876ae4u); f_008792b8(c); /* call 0x8792b8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00876af1u); f_00876afe(c); /* call 0x876afe */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00876b25(c); return; } /* jne 0x876b25 */
L_00876af8:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { f_00876b17(c); return; } /* jmp 0x876b17 */
}

void f_00876abc(CPU *c) { /* PTR_00876abc */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
    (void)sub32(c, c->esi, R32((uint32_t)(0x8808bcu))); /* cmp esi, dword ptr [0x100108bc] */
    if ((!c->cf && !c->zf)) goto L_00876af8; /* ja 0x876af8 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00876ad1u); f_00876bc9(c); /* call 0x876bc9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00876ae4u); f_008792b8(c); /* call 0x8792b8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00876af1u); f_00876afe(c); /* call 0x876afe */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00876b25(c); return; } /* jne 0x876b25 */
L_00876af8:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { f_00876b17(c); return; } /* jmp 0x876b17 */
}

void f_00876abf(CPU *c) { /* PTR_00876abf */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
    (void)sub32(c, c->esi, R32((uint32_t)(0x8808bcu))); /* cmp esi, dword ptr [0x100108bc] */
    if ((!c->cf && !c->zf)) goto L_00876af8; /* ja 0x876af8 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00876ad1u); f_00876bc9(c); /* call 0x876bc9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00876ae4u); f_008792b8(c); /* call 0x8792b8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00876af1u); f_00876afe(c); /* call 0x876afe */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00876b25(c); return; } /* jne 0x876b25 */
L_00876af8:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { f_00876b17(c); return; } /* jmp 0x876b17 */
}

void f_00876af8(CPU *c) { /* PTR_00876af8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { f_00876b17(c); return; } /* jmp 0x876b17 */
}

void f_00876afb(CPU *c) { /* PTR_00876afb */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    { f_00876afe(c); return; }
}

void f_00876afe(CPU *c) { /* FUN_10006afe */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00876b05u); f_00876c2a(c); /* call 0x876c2a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00876b07(CPU *c) { /* PTR_00876b07 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00876b11; /* jne 0x876b11 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00876b11:;
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xfu)); /* add eax, 0xf */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xf0u))); /* and al, 0xf0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x881724u)); PUSH32(c, v_); } /* push dword ptr [0x10011724] */
    { uint32_t t_ = R32((uint32_t)(0x87d03cu)); PUSH32(c, 0x00876b25u); call_indirect(c, t_); } /* call dword ptr [0x1000d03c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00876b11(CPU *c) { /* PTR_00876b11 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xfu)); /* add eax, 0xf */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xf0u))); /* and al, 0xf0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x881724u)); PUSH32(c, v_); } /* push dword ptr [0x10011724] */
    { uint32_t t_ = R32((uint32_t)(0x87d03cu)); PUSH32(c, 0x00876b25u); call_indirect(c, t_); } /* call dword ptr [0x1000d03c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00876b17(CPU *c) { /* PTR_00876b17 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x881724u)); PUSH32(c, v_); } /* push dword ptr [0x10011724] */
    { uint32_t t_ = R32((uint32_t)(0x87d03cu)); PUSH32(c, 0x00876b25u); call_indirect(c, t_); } /* call dword ptr [0x1000d03c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00876b25(CPU *c) { /* PTR_00876b25 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00876b34(CPU *c) { /* FUN_10006b34 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(0x87d044u))); /* mov esi, dword ptr [0x1000d044] */
    { uint32_t v_ = R32((uint32_t)(0x87e48cu)); PUSH32(c, v_); } /* push dword ptr [0x1000e48c] */
    { uint32_t t_ = c->esi; PUSH32(c, 0x00876b43u); call_indirect(c, t_); } /* call esi */
    { uint32_t v_ = R32((uint32_t)(0x87e47cu)); PUSH32(c, v_); } /* push dword ptr [0x1000e47c] */
    { uint32_t t_ = c->esi; PUSH32(c, 0x00876b4bu); call_indirect(c, t_); } /* call esi */
    { uint32_t v_ = R32((uint32_t)(0x87e46cu)); PUSH32(c, v_); } /* push dword ptr [0x1000e46c] */
    { uint32_t t_ = c->esi; PUSH32(c, 0x00876b53u); call_indirect(c, t_); } /* call esi */
    { uint32_t v_ = R32((uint32_t)(0x87e44cu)); PUSH32(c, v_); } /* push dword ptr [0x1000e44c] */
    { uint32_t t_ = c->esi; PUSH32(c, 0x00876b5bu); call_indirect(c, t_); } /* call esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00876b5d(CPU *c) { /* FUN_10006b5d */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(0x87d048u))); /* mov edi, dword ptr [0x1000d048] */
    c->esi = (uint32_t)((uint32_t)0x87e448u); /* mov esi, 0x1000e448 */
L_00876b6a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00876b9b; /* je 0x876b9b */
    (void)sub32(c, c->esi, (uint32_t)0x87e48cu); /* cmp esi, 0x1000e48c */
    if (c->zf) goto L_00876b9b; /* je 0x876b9b */
    (void)sub32(c, c->esi, (uint32_t)0x87e47cu); /* cmp esi, 0x1000e47c */
    if (c->zf) goto L_00876b9b; /* je 0x876b9b */
    (void)sub32(c, c->esi, (uint32_t)0x87e46cu); /* cmp esi, 0x1000e46c */
    if (c->zf) goto L_00876b9b; /* je 0x876b9b */
    (void)sub32(c, c->esi, (uint32_t)0x87e44cu); /* cmp esi, 0x1000e44c */
    if (c->zf) goto L_00876b9b; /* je 0x876b9b */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00876b93u); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    PUSH32(c, 0x00876b9au); f_00876c3f(c); /* call 0x876c3f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00876b9b:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, c->esi, (uint32_t)0x87e508u); /* cmp esi, 0x1000e508 */
    if ((c->sf != c->of)) goto L_00876b6a; /* jl 0x876b6a */
    { uint32_t v_ = R32((uint32_t)(0x87e46cu)); PUSH32(c, v_); } /* push dword ptr [0x1000e46c] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00876baeu); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = R32((uint32_t)(0x87e47cu)); PUSH32(c, v_); } /* push dword ptr [0x1000e47c] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00876bb6u); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = R32((uint32_t)(0x87e48cu)); PUSH32(c, v_); } /* push dword ptr [0x1000e48c] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00876bbeu); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = R32((uint32_t)(0x87e44cu)); PUSH32(c, v_); } /* push dword ptr [0x1000e44c] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00876bc6u); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00876bc9(CPU *c) { /* FUN_10006bc9 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    (void)sub32(c, R32((uint32_t)(c->eax * 4 + 0x87e448u)), (uint32_t)0x0u); /* cmp dword ptr [eax*4 + 0x1000e448], 0 */
    c->esi = (uint32_t)((uint32_t)(c->eax * 4 + 0x87e448u)); /* lea esi, [eax*4 + 0x1000e448] */
    if (!c->zf) goto L_00876c1f; /* jne 0x876c1f */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    PUSH32(c, 0x00876be9u); f_008769fa(c); /* call 0x8769fa */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (!c->zf) goto L_00876bf8; /* jne 0x876bf8 */
    { uint32_t v_ = 0x11u; PUSH32(c, v_); } /* push 0x11 */
    PUSH32(c, 0x00876bf7u); f_008759e0(c); /* call 0x8759e0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00876bf8:;
    { uint32_t v_ = 0x11u; PUSH32(c, v_); } /* push 0x11 */
    PUSH32(c, 0x00876bffu); f_00876bc9(c); /* call 0x876bc9 */
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x0u); /* cmp dword ptr [esi], 0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00876c10; /* jne 0x876c10 */
    { uint32_t t_ = R32((uint32_t)(0x87d044u)); PUSH32(c, 0x00876c0cu); call_indirect(c, t_); } /* call dword ptr [0x1000d044] */
    W32((uint32_t)(c->esi), (uint32_t)(c->edi)); /* mov dword ptr [esi], edi */
    goto L_00876c16; /* jmp 0x876c16 */
L_00876c10:;
    PUSH32(c, 0x00876c15u); f_00876c3f(c); /* call 0x876c3f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00876c16:;
    { uint32_t v_ = 0x11u; PUSH32(c, v_); } /* push 0x11 */
    PUSH32(c, 0x00876c1du); f_00876c2a(c); /* call 0x876c2a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_00876c1f:;
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(0x87d04cu)); PUSH32(c, 0x00876c27u); call_indirect(c, t_); } /* call dword ptr [0x1000d04c] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00876c2a(CPU *c) { /* FUN_10006c2a */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->eax * 4 + 0x87e448u)); PUSH32(c, v_); } /* push dword ptr [eax*4 + 0x1000e448] */
    { uint32_t t_ = R32((uint32_t)(0x87d050u)); PUSH32(c, 0x00876c3du); call_indirect(c, t_); } /* call dword ptr [0x1000d050] */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00876c3f(CPU *c) { /* FUN_10006c3f */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x87d2e0u; PUSH32(c, v_); } /* push 0x1000d2e0 */
    { uint32_t v_ = 0x877f10u; PUSH32(c, v_); } /* push 0x10007f10 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00876d19; /* je 0x876d19 */
    c->eax = (uint32_t)(R32((uint32_t)(0x881728u))); /* mov eax, dword ptr [0x10011728] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_00876cb2; /* jne 0x876cb2 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00876c7eu); f_00876bc9(c); /* call 0x876bc9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00876c89u); f_008784c1(c); /* call 0x8784c1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00876c9a; /* je 0x876c9a */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00876c98u); f_008784ec(c); /* call 0x8784ec */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00876c9a:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00876ca3u); f_00876ca9(c); /* call 0x876ca9 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x1c], 0 */
    goto L_00876cfa; /* jmp 0x876cfa */
L_00876cb2:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00876d0a; /* jne 0x876d0a */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00876cbeu); f_00876bc9(c); /* call 0x876bc9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe0u)); /* lea eax, [ebp - 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd8u)); /* lea eax, [ebp - 0x28] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00876cd4u); f_0087921c(c); /* call 0x87921c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00876ced; /* je 0x876ced */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x28] */
    PUSH32(c, 0x00876ceau); f_00879273(c); /* call 0x879273 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_00876ced:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00876cf6u); f_00876d01(c); /* call 0x876d01 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
L_00876cfa:;
    if (!c->zf) goto L_00876d19; /* jne 0x876d19 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    goto L_00876d0b; /* jmp 0x876d0b */
L_00876d0a:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
L_00876d0b:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x881724u)); PUSH32(c, v_); } /* push dword ptr [0x10011724] */
    { uint32_t t_ = R32((uint32_t)(0x87d054u)); PUSH32(c, 0x00876d19u); call_indirect(c, t_); } /* call dword ptr [0x1000d054] */
L_00876d19:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00876ca9(CPU *c) { /* FUN_10006ca9 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00876cb0u); f_00876c2a(c); /* call 0x876c2a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00876cb2(CPU *c) { /* PTR_00876cb2 */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) { f_00876d0a(c); return; } /* jne 0x876d0a */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00876cbeu); f_00876bc9(c); /* call 0x876bc9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe0u)); /* lea eax, [ebp - 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd8u)); /* lea eax, [ebp - 0x28] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00876cd4u); f_0087921c(c); /* call 0x87921c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00876ced; /* je 0x876ced */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x28] */
    PUSH32(c, 0x00876ceau); f_00879273(c); /* call 0x879273 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_00876ced:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00876cf6u); f_00876d01(c); /* call 0x876d01 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) { f_00876d19(c); return; } /* jne 0x876d19 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { f_00876d0b(c); return; } /* jmp 0x876d0b */
}

void f_00876ced(CPU *c) { /* PTR_00876ced */
    PREEMPT_POLL(c);
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00876cf6u); f_00876d01(c); /* call 0x876d01 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) { f_00876d19(c); return; } /* jne 0x876d19 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { f_00876d0b(c); return; } /* jmp 0x876d0b */
}

void f_00876cfa(CPU *c) { /* PTR_00876cfa */
    PREEMPT_POLL(c);
    if (!c->zf) { f_00876d19(c); return; } /* jne 0x876d19 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { f_00876d0b(c); return; } /* jmp 0x876d0b */
}

void f_00876d01(CPU *c) { /* FUN_10006d01 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00876d08u); f_00876c2a(c); /* call 0x876c2a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00876d0a(CPU *c) { /* PTR_00876d0a */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x881724u)); PUSH32(c, v_); } /* push dword ptr [0x10011724] */
    { uint32_t t_ = R32((uint32_t)(0x87d054u)); PUSH32(c, 0x00876d19u); call_indirect(c, t_); } /* call dword ptr [0x1000d054] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00876d0b(CPU *c) { /* PTR_00876d0b */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x881724u)); PUSH32(c, v_); } /* push dword ptr [0x10011724] */
    { uint32_t t_ = R32((uint32_t)(0x87d054u)); PUSH32(c, 0x00876d19u); call_indirect(c, t_); } /* call dword ptr [0x1000d054] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00876d19(CPU *c) { /* PTR_00876d19 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00876d30(CPU *c) { /* _strcmp */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u)); /* test edx, 3 */
    if (!c->zf) goto L_00876d7c; /* jne 0x876d7c */
L_00876d40:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edx))); /* mov eax, dword ptr [edx] */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->ecx))); /* cmp al, byte ptr [ecx] */
    if (!c->zf) goto L_00876d74; /* jne 0x876d74 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00876d70; /* je 0x876d70 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), R8((uint32_t)(c->ecx + 0x1u))); /* cmp ah, byte ptr [ecx + 1] */
    if (!c->zf) goto L_00876d74; /* jne 0x876d74 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | ((uint8_t)(c->eax >> 8))))) << 8); /* or ah, ah */
    if (c->zf) goto L_00876d70; /* je 0x876d70 */
    c->eax = (uint32_t)(shr32(c, c->eax, 16)); /* shr eax, 0x10 */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->ecx + 0x2u))); /* cmp al, byte ptr [ecx + 2] */
    if (!c->zf) goto L_00876d74; /* jne 0x876d74 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00876d70; /* je 0x876d70 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), R8((uint32_t)(c->ecx + 0x3u))); /* cmp ah, byte ptr [ecx + 3] */
    if (!c->zf) goto L_00876d74; /* jne 0x876d74 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x4u)); /* add edx, 4 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | ((uint8_t)(c->eax >> 8))))) << 8); /* or ah, ah */
    if (!c->zf) goto L_00876d40; /* jne 0x876d40 */
    c->edi = (uint32_t)(c->edi); /* mov edi, edi */
L_00876d70:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_00876d74:;
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(shl32(c, c->eax, 1)); /* shl eax, 1 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->esp += 4; return; /* ret  */
L_00876d7c:;
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x1u)); /* test edx, 1 */
    if (c->zf) goto L_00876d98; /* je 0x876d98 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov al, byte ptr [edx] */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->ecx))); /* cmp al, byte ptr [ecx] */
    if (!c->zf) goto L_00876d74; /* jne 0x876d74 */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00876d70; /* je 0x876d70 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x2u)); /* test edx, 2 */
    if (c->zf) goto L_00876d40; /* je 0x876d40 */
L_00876d98:;
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->edx))); /* mov ax, word ptr [edx] */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x2u)); /* add edx, 2 */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->ecx))); /* cmp al, byte ptr [ecx] */
    if (!c->zf) goto L_00876d74; /* jne 0x876d74 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00876d70; /* je 0x876d70 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), R8((uint32_t)(c->ecx + 0x1u))); /* cmp ah, byte ptr [ecx + 1] */
    if (!c->zf) goto L_00876d74; /* jne 0x876d74 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | ((uint8_t)(c->eax >> 8))))) << 8); /* or ah, ah */
    if (c->zf) goto L_00876d70; /* je 0x876d70 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x2u)); /* add ecx, 2 */
    goto L_00876d40; /* jmp 0x876d40 */
}

void f_00876db4(CPU *c) { /* FUN_10006db4 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x30000u; PUSH32(c, v_); } /* push 0x30000 */
    { uint32_t v_ = 0x10000u; PUSH32(c, v_); } /* push 0x10000 */
    PUSH32(c, 0x00876dc3u); f_00879a1a(c); /* call 0x879a1a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00876dc6(CPU *c) { /* FUN_10006dc6 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    FPUSH(c, RF64((uint32_t)(0x87d308u))); /* fld qword ptr [0x1000d308] */
    WF64((uint32_t)(c->ebp + 0xfffffff8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 8] */
    FPUSH(c, RF64((uint32_t)(0x87d300u))); /* fld qword ptr [0x1000d300] */
    WF64((uint32_t)(c->ebp + 0xfffffff0u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0x10] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff0u))); /* fld qword ptr [ebp - 0x10] */
    ST(0) = FPRES(c, FDIV(c, ST(0), RF64((uint32_t)(c->ebp + 0xfffffff8u)))); /* fdiv qword ptr [ebp - 8] */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->ebp + 0xfffffff8u))); /* fmul qword ptr [ebp - 8] */
    ST(0) = FPRES(c, RF64((uint32_t)(c->ebp + 0xfffffff0u)) - ST(0)); /* fsubr qword ptr [ebp - 0x10] */
    WF64((uint32_t)(c->ebp + 0xffffffe8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0x18] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xffffffe8u))); /* fld qword ptr [ebp - 0x18] */
    FCOM(c, ST(0), RF64((uint32_t)(0x87d2f8u))); FPOP(c); /* fcomp qword ptr [0x1000d2f8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if ((c->cf || c->zf)) goto L_00876e00; /* jbe 0x876e00 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00876e00:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00876e04(CPU *c) { /* FUN_10006e04 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x87d32cu; PUSH32(c, v_); } /* push 0x1000d32c */
    { uint32_t t_ = R32((uint32_t)(0x87d05cu)); PUSH32(c, 0x00876e0fu); call_indirect(c, t_); } /* call dword ptr [0x1000d05c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00876e28; /* je 0x876e28 */
    { uint32_t v_ = 0x87d310u; PUSH32(c, v_); } /* push 0x1000d310 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x87d058u)); PUSH32(c, 0x00876e1fu); call_indirect(c, t_); } /* call dword ptr [0x1000d058] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00876e28; /* je 0x876e28 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00876e27u); call_indirect(c, t_); } /* call eax */
    c->esp += 4; return; /* ret  */
L_00876e28:;
    { f_00876dc6(c); return; } /* jmp 0x876dc6 */
}

void f_00876e2d(CPU *c) { /* FUN_10006e2d */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->esi))); /* movsx eax, byte ptr [esi] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00876e3bu); f_00879b4b(c); /* call 0x879b4b */
    (void)sub32(c, c->eax, (uint32_t)0x65u); /* cmp eax, 0x65 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00876e6d; /* je 0x876e6d */
L_00876e41:;
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub32(c, R32((uint32_t)(0x87e73cu)), (uint32_t)0x1u); /* cmp dword ptr [0x1000e73c], 1 */
    if ((c->zf || c->sf != c->of)) goto L_00876e5a; /* jle 0x876e5a */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->esi))); /* movsx eax, byte ptr [esi] */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00876e56u); f_008773bb(c); /* call 0x8773bb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00876e69; /* jmp 0x876e69 */
L_00876e5a:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->esi))); /* movsx eax, byte ptr [esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x87e530u))); /* mov ecx, dword ptr [0x1000e530] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4u))); /* and eax, 4 */
L_00876e69:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00876e41; /* jne 0x876e41 */
L_00876e6d:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x87e740u))); /* mov cl, byte ptr [0x1000e740] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esi], cl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_00876e78:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov cl, byte ptr [esi] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [esi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(((uint8_t)c->ecx)); /* mov al, cl */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov cl, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_00876e78; /* jne 0x876e78 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00876e87(CPU *c) { /* PTR_00876e87 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x87e740u))); /* mov dl, byte ptr [0x1000e740] */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_00876ea3; /* je 0x876ea3 */
L_00876e97:;
    (void)sub8(c, ((uint8_t)c->ecx), ((uint8_t)c->edx)); /* cmp cl, dl */
    if (c->zf) goto L_00876ea3; /* je 0x876ea3 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1u))); /* mov cl, byte ptr [eax + 1] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_00876e97; /* jne 0x876e97 */
L_00876ea3:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_00876ed4; /* je 0x876ed4 */
L_00876eaa:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_00876ebd; /* je 0x876ebd */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x65u); /* cmp cl, 0x65 */
    if (c->zf) goto L_00876ebd; /* je 0x876ebd */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x45u); /* cmp cl, 0x45 */
    if (c->zf) goto L_00876ebd; /* je 0x876ebd */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_00876eaa; /* jmp 0x876eaa */
L_00876ebd:;
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
L_00876ebf:;
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x30u); /* cmp byte ptr [eax], 0x30 */
    if (c->zf) goto L_00876ebf; /* je 0x876ebf */
    (void)sub8(c, R8((uint32_t)(c->eax)), ((uint8_t)c->edx)); /* cmp byte ptr [eax], dl */
    if (!c->zf) goto L_00876eca; /* jne 0x876eca */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
L_00876eca:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov dl, byte ptr [ecx] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [eax], dl */
    if (!c->zf) goto L_00876eca; /* jne 0x876eca */
L_00876ed4:;
    c->esp += 4; return; /* ret  */
}

void f_00876ed5(CPU *c) { /* PTR_00876ed5 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    FPUSH(c, RF64((uint32_t)(c->eax))); /* fld qword ptr [eax] */
    FCOM(c, ST(0), RF64((uint32_t)(0x87d338u))); FPOP(c); /* fcomp qword ptr [0x1000d338] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (c->cf) goto L_00876eea; /* jb 0x876eea */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
L_00876eea:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_00876eed(CPU *c) { /* __fassign */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    if (c->zf) goto L_00876f16; /* je 0x876f16 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00876f04u); f_0087a017(c); /* call 0x87a017 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 4], ecx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00876f16:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00876f1fu); f_0087a044(c); /* call 0x87a044 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00876f2b(CPU *c) { /* FUN_10006f2b */
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
    PUSH32(c, 0x00876f49u); f_0087a0e8(c); /* call 0x87a0e8 */
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
    PUSH32(c, 0x00876f71u); f_0087a071(c); /* call 0x87a071 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x00876f83u); f_00876f8c(c); /* call 0x876f8c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x30u)); /* add esp, 0x30 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00876f8c(CPU *c) { /* FUN_10006f8c */
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
    if (c->zf) goto L_00876fba; /* je 0x876fba */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->ebx); /* cmp dword ptr [ebp + 0xc], ebx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((!c->zf && c->sf == c->of) ? 1 : 0); /* setg al */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x2du); /* cmp dword ptr [esi], 0x2d */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete al */
    c->eax = (uint32_t)(add32(c, c->eax, c->edi)); /* add eax, edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00876fb8u); f_0087722e(c); /* call 0x87722e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00876fba:;
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x2du); /* cmp dword ptr [esi], 0x2d */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    if (!c->zf) goto L_00876fc7; /* jne 0x876fc7 */
    W8((uint32_t)(c->edi), (uint8_t)((uint8_t)0x2du)); /* mov byte ptr [edi], 0x2d */
    c->eax = (uint32_t)((uint32_t)(c->edi + 0x1u)); /* lea eax, [edi + 1] */
L_00876fc7:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->ebx); /* cmp dword ptr [ebp + 0xc], ebx */
    if ((c->zf || c->sf != c->of)) goto L_00876fde; /* jle 0x876fde */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1u))); /* mov dl, byte ptr [eax + 1] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x1u)); /* lea ecx, [eax + 1] */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [eax], dl */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x87e740u))); /* mov cl, byte ptr [0x1000e740] */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax], cl */
L_00876fde:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x18u)), ((uint8_t)c->ebx)); /* cmp byte ptr [ebp + 0x18], bl */
    { uint32_t v_ = 0x87d340u; PUSH32(c, v_); } /* push 0x1000d340 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete cl */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    c->ecx = (uint32_t)(add32(c, c->ecx, R32((uint32_t)(c->ebp + 0xcu)))); /* add ecx, dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00876ff6u); f_0087a200(c); /* call 0x87a200 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), c->ebx); /* cmp dword ptr [ebp + 0x10], ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    if (c->zf) goto L_00877002; /* je 0x877002 */
    W8((uint32_t)(c->ecx), (uint8_t)((uint8_t)0x45u)); /* mov byte ptr [ecx], 0x45 */
L_00877002:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x30u); /* cmp byte ptr [eax], 0x30 */
    if (c->zf) goto L_00877047; /* je 0x877047 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ebx, dword ptr [esi + 4] */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->sf) goto L_00877016; /* jns 0x877016 */
    c->ebx = (uint32_t)(neg32(c, c->ebx)); /* neg ebx */
    W8((uint32_t)(c->ecx), (uint8_t)((uint8_t)0x2du)); /* mov byte ptr [ecx], 0x2d */
L_00877016:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->ebx, (uint32_t)0x64u); /* cmp ebx, 0x64 */
    if ((c->sf != c->of)) goto L_0087702d; /* jl 0x87702d */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = 0x64u; PUSH32(c, v_); } /* push 0x64 */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00877022u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [ecx], al */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00877029u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
    c->ebx = (uint32_t)(c->edx); /* mov ebx, edx */
L_0087702d:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->ebx, (uint32_t)0xau); /* cmp ebx, 0xa */
    if ((c->sf != c->of)) goto L_00877044; /* jl 0x877044 */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = 0xau; PUSH32(c, v_); } /* push 0xa */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00877039u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [ecx], al */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00877040u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
    c->ebx = (uint32_t)(c->edx); /* mov ebx, edx */
L_00877044:;
    { uint32_t a_ = (uint32_t)(c->ecx + 0x1u); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ebx)))); } /* add byte ptr [ecx + 1], bl */
L_00877047:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_0087704e(CPU *c) { /* FUN_1000704e */
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
    PUSH32(c, 0x0087706cu); f_0087a0e8(c); /* call 0x87a0e8 */
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
    PUSH32(c, 0x0087708bu); f_0087a071(c); /* call 0x87a071 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x0087709au); f_008770a3(c); /* call 0x8770a3 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008770a3(CPU *c) { /* FUN_100070a3 */
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
    if (c->zf) goto L_008770d3; /* je 0x8770d3 */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xcu))); /* cmp eax, dword ptr [ebp + 0xc] */
    if (!c->zf) goto L_008770d3; /* jne 0x8770d3 */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x2du); /* cmp dword ptr [esi], 0x2d */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete cl */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->ebx)); /* add ecx, ebx */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    W8((uint32_t)(c->eax), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [eax], 0x30 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x1u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax + 1], 0 */
L_008770d3:;
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x2du); /* cmp dword ptr [esi], 0x2d */
    c->edi = (uint32_t)(c->ebx); /* mov edi, ebx */
    if (!c->zf) goto L_008770e0; /* jne 0x8770e0 */
    W8((uint32_t)(c->ebx), (uint8_t)((uint8_t)0x2du)); /* mov byte ptr [ebx], 0x2d */
    c->edi = (uint32_t)((uint32_t)(c->ebx + 0x1u)); /* lea edi, [ebx + 1] */
L_008770e0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((!c->zf && c->sf == c->of)) goto L_008770f7; /* jg 0x8770f7 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x008770efu); f_0087722e(c); /* call 0x87722e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W8((uint32_t)(c->edi), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [edi], 0x30 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_008770f9; /* jmp 0x8770f9 */
L_008770f7:;
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
L_008770f9:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    if ((c->zf || c->sf != c->of)) goto L_00877143; /* jle 0x877143 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00877107u); f_0087722e(c); /* call 0x87722e */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x87e740u))); /* mov al, byte ptr [0x1000e740] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov esi, dword ptr [esi + 4] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if ((c->sf == c->of)) goto L_00877143; /* jge 0x877143 */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x14u)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0x14], 0 */
    if (c->zf) goto L_00877122; /* je 0x877122 */
    c->esi = (uint32_t)(neg32(c, c->esi)); /* neg esi */
    goto L_00877129; /* jmp 0x877129 */
L_00877122:;
    c->esi = (uint32_t)(neg32(c, c->esi)); /* neg esi */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->esi); /* cmp dword ptr [ebp + 0xc], esi */
    if ((c->sf != c->of)) goto L_0087712c; /* jl 0x87712c */
L_00877129:;
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_0087712c:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00877135u); f_0087722e(c); /* call 0x87722e */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = 0x30u; PUSH32(c, v_); } /* push 0x30 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00877140u); f_0087a2f0(c); /* call 0x87a2f0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
L_00877143:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_0087714a(CPU *c) { /* FUN_1000714a */
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
    PUSH32(c, 0x0087716au); f_0087a0e8(c); /* call 0x87a0e8 */
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
    PUSH32(c, 0x0087718cu); f_0087a071(c); /* call 0x87a071 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)((c->sf != c->of) ? 1 : 0); /* setl cl */
    (void)sub32(c, c->eax, (uint32_t)0xfffffffcu); /* cmp eax, -4 */
    if ((c->sf != c->of)) goto L_008771c3; /* jl 0x8771c3 */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if ((c->sf == c->of)) goto L_008771c3; /* jge 0x8771c3 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_008771af; /* je 0x8771af */
L_008771a5:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov al, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_008771a5; /* jne 0x8771a5 */
    { uint32_t a_ = (uint32_t)(c->edi + 0xfffffffeu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & ((uint8_t)c->eax))))); } /* and byte ptr [edi - 2], al */
L_008771af:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x008771beu); f_008770a3(c); /* call 0x8770a3 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    goto L_008771d8; /* jmp 0x8771d8 */
L_008771c3:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x008771d5u); f_00876f8c(c); /* call 0x876f8c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
L_008771d8:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008771dd(CPU *c) { /* __cfltcvt */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), (uint32_t)0x65u); /* cmp dword ptr [ebp + 0x10], 0x65 */
    if (c->zf) goto L_00877218; /* je 0x877218 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), (uint32_t)0x45u); /* cmp dword ptr [ebp + 0x10], 0x45 */
    if (c->zf) goto L_00877218; /* je 0x877218 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), (uint32_t)0x66u); /* cmp dword ptr [ebp + 0x10], 0x66 */
    if (!c->zf) goto L_00877205; /* jne 0x877205 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00877200u); f_0087704e(c); /* call 0x87704e */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
L_00877205:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00877216u); f_0087714a(c); /* call 0x87714a */
    goto L_00877229; /* jmp 0x877229 */
L_00877218:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00877229u); f_00876f2b(c); /* call 0x876f2b */
L_00877229:;
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_0087722e(CPU *c) { /* FUN_1000722e */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edi, dword ptr [esp + 0xc] */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00877251; /* je 0x877251 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov esi, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00877242u); f_00877340(c); /* call 0x877340 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(add32(c, c->esi, c->edi)); /* add esi, edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x0087724du); f_00877ff0(c); /* call 0x877ff0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00877251:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00877253(CPU *c) { /* FUN_10007253 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xe06d7363u); /* cmp dword ptr [eax], 0xe06d7363 */
    if (!c->zf) goto L_00877276; /* jne 0x877276 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [eax + 0x10], 3 */
    if (!c->zf) goto L_00877276; /* jne 0x877276 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x14u)), (uint32_t)0x19930520u); /* cmp dword ptr [eax + 0x14], 0x19930520 */
    if (!c->zf) goto L_00877276; /* jne 0x877276 */
    { f_00876408(c); return; } /* jmp 0x876408 */
L_00877276:;
    c->eax = (uint32_t)(R32((uint32_t)(0x881230u))); /* mov eax, dword ptr [0x10011230] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00877293; /* je 0x877293 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00877285u); f_00877ef0(c); /* call 0x877ef0 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00877293; /* je 0x877293 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(0x881230u)); PUSH32(c, 0x00877291u); call_indirect(c, t_); } /* call dword ptr [0x10011230] */
    goto L_00877295; /* jmp 0x877295 */
L_00877293:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00877295:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00877299(CPU *c) { /* PTR_00877299 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x877253u; PUSH32(c, v_); } /* push 0x10007253 */
    { uint32_t t_ = R32((uint32_t)(0x87d060u)); PUSH32(c, 0x008772a4u); call_indirect(c, t_); } /* call dword ptr [0x1000d060] */
    W32((uint32_t)(0x881230u), (uint32_t)(c->eax)); /* mov dword ptr [0x10011230], eax */
    c->esp += 4; return; /* ret  */
}

void f_008772aa(CPU *c) { /* PTR_008772aa */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(0x881230u)); PUSH32(c, v_); } /* push dword ptr [0x10011230] */
    { uint32_t t_ = R32((uint32_t)(0x87d060u)); PUSH32(c, 0x008772b6u); call_indirect(c, t_); } /* call dword ptr [0x1000d060] */
    c->esp += 4; return; /* ret  */
}

void f_008772b7(CPU *c) { /* FUN_100072b7 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe8u)); /* lea eax, [ebp - 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008772d8u); f_0087a351(c); /* call 0x87a351 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x4u)); /* test bl, 4 */
    if (c->zf) goto L_008772ef; /* je 0x8772ef */
    c->edi = (uint32_t)((uint32_t)0x200u); /* mov edi, 0x200 */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0xc], esi */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 8], esi */
    goto L_0087731d; /* jmp 0x87731d */
L_008772ef:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe8u)); /* lea eax, [ebp - 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008772fcu); f_00879feb(c); /* call 0x879feb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x2u)); /* test bl, 2 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00877308; /* jne 0x877308 */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_0087730d; /* jne 0x87730d */
L_00877308:;
    c->edi = (uint32_t)((uint32_t)0x80u); /* mov edi, 0x80 */
L_0087730d:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x1u)); /* test bl, 1 */
    if (!c->zf) goto L_00877317; /* jne 0x877317 */
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_0087731d; /* jne 0x87731d */
L_00877317:;
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi | (uint32_t)0x100u))); /* or edi, 0x100 */
L_0087731d:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, R32((uint32_t)(c->ebp + 0xcu)))); /* sub ecx, dword ptr [ebp + 0xc] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
    W32((uint32_t)(c->eax), (uint32_t)(c->edi)); /* mov dword ptr [eax], edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    WF64((uint32_t)(c->eax + 0x10u), ST(0)); FPOP(c); /* fstp qword ptr [eax + 0x10] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 4], ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00877340(CPU *c) { /* _strlen */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u)); /* test ecx, 3 */
    if (c->zf) goto L_00877360; /* je 0x877360 */
L_0087734c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov al, byte ptr [ecx] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00877393; /* je 0x877393 */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u)); /* test ecx, 3 */
    if (!c->zf) goto L_0087734c; /* jne 0x87734c */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x0u)); /* add eax, 0 */
L_00877360:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)((uint32_t)0x7efefeffu); /* mov edx, 0x7efefeff */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ (uint32_t)0xffffffffu))); /* xor eax, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ c->edx))); /* xor eax, edx */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u)); /* test eax, 0x81010100 */
    if (c->zf) goto L_00877360; /* je 0x877360 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0xfffffffcu))); /* mov eax, dword ptr [ecx - 4] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_008773b1; /* je 0x8773b1 */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_008773a7; /* je 0x8773a7 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0xff0000u)); /* test eax, 0xff0000 */
    if (c->zf) goto L_0087739d; /* je 0x87739d */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0xff000000u)); /* test eax, 0xff000000 */
    if (c->zf) goto L_00877393; /* je 0x877393 */
    goto L_00877360; /* jmp 0x877360 */
L_00877393:;
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0xffffffffu)); /* lea eax, [ecx - 1] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->esp += 4; return; /* ret  */
L_0087739d:;
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0xfffffffeu)); /* lea eax, [ecx - 2] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->esp += 4; return; /* ret  */
L_008773a7:;
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0xfffffffdu)); /* lea eax, [ecx - 3] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->esp += 4; return; /* ret  */
L_008773b1:;
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0xfffffffcu)); /* lea eax, [ecx - 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->esp += 4; return; /* ret  */
}

void f_008773bb(CPU *c) { /* FUN_100073bb */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x1u)); /* lea ecx, [eax + 1] */
    (void)sub32(c, c->ecx, (uint32_t)0x100u); /* cmp ecx, 0x100 */
    if ((!c->cf && !c->zf)) goto L_008773d9; /* ja 0x8773d9 */
    c->ecx = (uint32_t)(R32((uint32_t)(0x87e530u))); /* mov ecx, dword ptr [0x1000e530] */
    c->eax = (uint32_t)((uint32_t)R16((uint32_t)(c->ecx + c->eax * 2))); /* movzx eax, word ptr [ecx + eax*2] */
    goto L_0087742b; /* jmp 0x87742b */
L_008773d9:;
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(0x87e530u))); /* mov esi, dword ptr [0x1000e530] */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 8)); /* sar ecx, 8 */
    c->edx = (uint32_t)((uint32_t)((uint8_t)c->ecx)); /* movzx edx, cl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi + c->edx * 2 + 0x1u)) & (uint8_t)0x80u)); /* test byte ptr [esi + edx*2 + 1], 0x80 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    if (c->zf) goto L_008773fe; /* je 0x8773fe */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffeu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp - 2], 0 */
    W8((uint32_t)(c->ebp + 0xfffffffcu), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [ebp - 4], cl */
    W8((uint32_t)(c->ebp + 0xfffffffdu), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp - 3], al */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    goto L_00877407; /* jmp 0x877407 */
L_008773fe:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffdu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp - 3], 0 */
    W8((uint32_t)(c->ebp + 0xfffffffcu), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp - 4], al */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
L_00877407:;
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
    PUSH32(c, 0x0087741eu); f_0087a822(c); /* call 0x87a822 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00877427; /* jne 0x877427 */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00877427:;
    c->eax = (uint32_t)((uint32_t)R16((uint32_t)(c->ebp + 0xau))); /* movzx eax, word ptr [ebp + 0xa] */
L_0087742b:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & R32((uint32_t)(c->ebp + 0xcu))))); /* and eax, dword ptr [ebp + 0xc] */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00877430(CPU *c) { /* PTR_00877430 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->eax))); /* or ecx, eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    if (!c->zf) goto L_00877449; /* jne 0x877449 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint64_t r_ = (uint64_t)c->eax * c->ecx; c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = c->edx != 0; } /* mul ecx */
    c->esp += 20; return; /* ret 0x10 */
L_00877449:;
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

void f_00877464(CPU *c) { /* FUN_10007464 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x48u)); /* sub esp, 0x48 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x480u; PUSH32(c, v_); } /* push 0x480 */
    PUSH32(c, 0x00877477u); f_008769fa(c); /* call 0x8769fa */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_00877486; /* jne 0x877486 */
    { uint32_t v_ = 0x1bu; PUSH32(c, v_); } /* push 0x1b */
    PUSH32(c, 0x00877485u); f_008759e0(c); /* call 0x8759e0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00877486:;
    W32((uint32_t)(0x881740u), (uint32_t)(c->esi)); /* mov dword ptr [0x10011740], esi */
    W32((uint32_t)(0x881840u), (uint32_t)((uint32_t)0x20u)); /* mov dword ptr [0x10011840], 0x20 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x480u)); /* lea eax, [esi + 0x480] */
L_0087749c:;
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if (!c->cf) goto L_008774be; /* jae 0x8774be */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [esi + 4], 0 */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [esi], 0xffffffff */
    { uint32_t a_ = (uint32_t)(c->esi + 0x8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi + 8], 0 */
    W8((uint32_t)(c->esi + 0x5u), (uint8_t)((uint8_t)0xau)); /* mov byte ptr [esi + 5], 0xa */
    c->eax = (uint32_t)(R32((uint32_t)(0x881740u))); /* mov eax, dword ptr [0x10011740] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x24u)); /* add esi, 0x24 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x480u)); /* add eax, 0x480 */
    goto L_0087749c; /* jmp 0x87749c */
L_008774be:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffb8u)); /* lea eax, [ebp - 0x48] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x87d070u)); PUSH32(c, 0x008774c8u); call_indirect(c, t_); } /* call dword ptr [0x1000d070] */
    (void)sub16(c, R16((uint32_t)(c->ebp + 0xffffffeau)), (uint16_t)0x0u); /* cmp word ptr [ebp - 0x16], 0 */
    if (c->zf) goto L_008775a4; /* je 0x8775a4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008775a4; /* je 0x8775a4 */
    c->edi = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edi, dword ptr [eax] */
    c->ebx = (uint32_t)((uint32_t)(c->eax + 0x4u)); /* lea ebx, [eax + 4] */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->edi)); /* lea eax, [ebx + edi] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->eax = (uint32_t)((uint32_t)0x800u); /* mov eax, 0x800 */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if ((c->sf != c->of)) goto L_008774f4; /* jl 0x8774f4 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
L_008774f4:;
    (void)sub32(c, R32((uint32_t)(0x881840u)), c->edi); /* cmp dword ptr [0x10011840], edi */
    if ((c->sf == c->of)) goto L_00877552; /* jge 0x877552 */
    c->esi = (uint32_t)((uint32_t)0x881744u); /* mov esi, 0x10011744 */
L_00877501:;
    { uint32_t v_ = 0x480u; PUSH32(c, v_); } /* push 0x480 */
    PUSH32(c, 0x0087750bu); f_008769fa(c); /* call 0x8769fa */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_0087754c; /* je 0x87754c */
    { uint32_t a_ = (uint32_t)(0x881840u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x20u))); } /* add dword ptr [0x10011840], 0x20 */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x480u)); /* lea ecx, [eax + 0x480] */
L_0087751f:;
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->cf) goto L_0087753f; /* jae 0x87753f */
    { uint32_t a_ = (uint32_t)(c->eax + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax + 4], 0 */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [eax], 0xffffffff */
    { uint32_t a_ = (uint32_t)(c->eax + 0x8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [eax + 8], 0 */
    W8((uint32_t)(c->eax + 0x5u), (uint8_t)((uint8_t)0xau)); /* mov byte ptr [eax + 5], 0xa */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x24u)); /* add eax, 0x24 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x480u)); /* add ecx, 0x480 */
    goto L_0087751f; /* jmp 0x87751f */
L_0087753f:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, R32((uint32_t)(0x881840u)), c->edi); /* cmp dword ptr [0x10011840], edi */
    if ((c->sf != c->of)) goto L_00877501; /* jl 0x877501 */
    goto L_00877552; /* jmp 0x877552 */
L_0087754c:;
    c->edi = (uint32_t)(R32((uint32_t)(0x881840u))); /* mov edi, dword ptr [0x10011840] */
L_00877552:;
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if ((c->zf || c->sf != c->of)) goto L_008775a4; /* jle 0x8775a4 */
L_00877558:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    (void)sub32(c, c->ecx, (uint32_t)0xffffffffu); /* cmp ecx, -1 */
    if (c->zf) goto L_0087759a; /* je 0x87759a */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebx))); /* mov al, byte ptr [ebx] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    if (c->zf) goto L_0087759a; /* je 0x87759a */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x8u)); /* test al, 8 */
    if (!c->zf) goto L_00877577; /* jne 0x877577 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t t_ = R32((uint32_t)(0x87d06cu)); PUSH32(c, 0x00877573u); call_indirect(c, t_); } /* call dword ptr [0x1000d06c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0087759a; /* je 0x87759a */
L_00877577:;
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 5)); /* sar ecx, 5 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1fu))); /* and eax, 0x1f */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx * 4 + 0x881740u))); /* mov ecx, dword ptr [ecx*4 + 0x10011740] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 8)); /* lea eax, [eax + eax*8] */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->eax * 4)); /* lea eax, [ecx + eax*4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov ecx, dword ptr [ecx] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebx))); /* mov cl, byte ptr [ebx] */
    W8((uint32_t)(c->eax + 0x4u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax + 4], cl */
L_0087759a:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x4u))); } /* add dword ptr [ebp - 4], 4 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if ((c->sf != c->of)) goto L_00877558; /* jl 0x877558 */
L_008775a4:;
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
L_008775a6:;
    c->ecx = (uint32_t)(R32((uint32_t)(0x881740u))); /* mov ecx, dword ptr [0x10011740] */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->ebx * 8)); /* lea eax, [ebx + ebx*8] */
    (void)sub32(c, R32((uint32_t)(c->ecx + c->eax * 4)), (uint32_t)0xffffffffu); /* cmp dword ptr [ecx + eax*4], -1 */
    c->esi = (uint32_t)((uint32_t)(c->ecx + c->eax * 4)); /* lea esi, [ecx + eax*4] */
    if (!c->zf) goto L_00877605; /* jne 0x877605 */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    W8((uint32_t)(c->esi + 0x4u), (uint8_t)((uint8_t)0x81u)); /* mov byte ptr [esi + 4], 0x81 */
    if (!c->zf) goto L_008775c5; /* jne 0x8775c5 */
    { uint32_t v_ = 0xfffffff6u; PUSH32(c, v_); } /* push -0xa */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_008775cf; /* jmp 0x8775cf */
L_008775c5:;
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xfffffff5u)); /* add eax, -0xb */
L_008775cf:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x87d068u)); PUSH32(c, 0x008775d6u); call_indirect(c, t_); } /* call dword ptr [0x1000d068] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)sub32(c, c->edi, (uint32_t)0xffffffffu); /* cmp edi, -1 */
    if (c->zf) goto L_008775f4; /* je 0x8775f4 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0x87d06cu)); PUSH32(c, 0x008775e4u); call_indirect(c, t_); } /* call dword ptr [0x1000d06c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008775f4; /* je 0x8775f4 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xffu))); /* and eax, 0xff */
    W32((uint32_t)(c->esi), (uint32_t)(c->edi)); /* mov dword ptr [esi], edi */
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_008775fa; /* jne 0x8775fa */
L_008775f4:;
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x40u)))); } /* or byte ptr [esi + 4], 0x40 */
    goto L_00877609; /* jmp 0x877609 */
L_008775fa:;
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_00877609; /* jne 0x877609 */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x8u)))); } /* or byte ptr [esi + 4], 8 */
    goto L_00877609; /* jmp 0x877609 */
L_00877605:;
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x80u)))); } /* or byte ptr [esi + 4], 0x80 */
L_00877609:;
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    (void)sub32(c, c->ebx, (uint32_t)0x3u); /* cmp ebx, 3 */
    if ((c->sf != c->of)) goto L_008775a6; /* jl 0x8775a6 */
    { uint32_t v_ = R32((uint32_t)(0x881840u)); PUSH32(c, v_); } /* push dword ptr [0x10011840] */
    { uint32_t t_ = R32((uint32_t)(0x87d064u)); PUSH32(c, 0x0087761bu); call_indirect(c, t_); } /* call dword ptr [0x1000d064] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00877620(CPU *c) { /* FUN_10007620 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)((uint32_t)0x881740u); /* mov esi, 0x10011740 */
L_00877628:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00877665; /* je 0x877665 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x480u)); /* add eax, 0x480 */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (!c->cf) goto L_0087765a; /* jae 0x87765a */
    c->ebx = (uint32_t)((uint32_t)(c->edi + 0xcu)); /* lea ebx, [edi + 0xc] */
L_0087763c:;
    (void)sub32(c, R32((uint32_t)(c->ebx + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebx - 4], 0 */
    if (c->zf) goto L_00877649; /* je 0x877649 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(0x87d048u)); PUSH32(c, 0x00877649u); call_indirect(c, t_); } /* call dword ptr [0x1000d048] */
L_00877649:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x24u)); /* add edi, 0x24 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x480u)); /* add eax, 0x480 */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x24u)); /* add ebx, 0x24 */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_0087763c; /* jb 0x87763c */
L_0087765a:;
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    PUSH32(c, 0x00877661u); f_00876c3f(c); /* call 0x876c3f */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi], 0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00877665:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, c->esi, (uint32_t)0x881840u); /* cmp esi, 0x10011840 */
    if ((c->sf != c->of)) goto L_00877628; /* jl 0x877628 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00877674(CPU *c) { /* FUN_10007674 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, R32((uint32_t)(0x881848u)), c->ebx); /* cmp dword ptr [0x10011848], ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00877686; /* jne 0x877686 */
    PUSH32(c, 0x00877686u); f_0087ad43(c); /* call 0x87ad43 */
L_00877686:;
    c->esi = (uint32_t)(R32((uint32_t)(0x88117cu))); /* mov esi, dword ptr [0x1001117c] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
L_0087768e:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_008776a6; /* je 0x8776a6 */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x3du); /* cmp al, 0x3d */
    if (c->zf) goto L_00877699; /* je 0x877699 */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
L_00877699:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x0087769fu); f_00877340(c); /* call 0x877340 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esi = (uint32_t)((uint32_t)(c->esi + c->eax + 0x1u)); /* lea esi, [esi + eax + 1] */
    goto L_0087768e; /* jmp 0x87768e */
L_008776a6:;
    c->eax = (uint32_t)((uint32_t)(c->edi * 4 + 0x4u)); /* lea eax, [edi*4 + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008776b3u); f_008769fa(c); /* call 0x8769fa */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    W32((uint32_t)(0x8811acu), (uint32_t)(c->esi)); /* mov dword ptr [0x100111ac], esi */
    if (!c->zf) goto L_008776c8; /* jne 0x8776c8 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x008776c7u); f_008759e0(c); /* call 0x8759e0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_008776c8:;
    c->edi = (uint32_t)(R32((uint32_t)(0x88117cu))); /* mov edi, dword ptr [0x1001117c] */
    (void)sub8(c, R8((uint32_t)(c->edi)), ((uint8_t)c->ebx)); /* cmp byte ptr [edi], bl */
    if (c->zf) goto L_0087770b; /* je 0x87770b */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
L_008776d3:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x008776d9u); f_00877340(c); /* call 0x877340 */
    c->ebp = (uint32_t)(c->eax); /* mov ebp, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ebp = (uint32_t)(inc32(c, c->ebp)); /* inc ebp */
    (void)sub8(c, R8((uint32_t)(c->edi)), (uint8_t)0x3du); /* cmp byte ptr [edi], 0x3d */
    if (c->zf) goto L_00877704; /* je 0x877704 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x008776e8u); f_008769fa(c); /* call 0x8769fa */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    if (!c->zf) goto L_008776f7; /* jne 0x8776f7 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x008776f6u); f_008759e0(c); /* call 0x8759e0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_008776f7:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    PUSH32(c, 0x008776ffu); f_0087a200(c); /* call 0x87a200 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00877704:;
    c->edi = (uint32_t)(add32(c, c->edi, c->ebp)); /* add edi, ebp */
    (void)sub8(c, R8((uint32_t)(c->edi)), ((uint8_t)c->ebx)); /* cmp byte ptr [edi], bl */
    if (!c->zf) goto L_008776d3; /* jne 0x8776d3 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
L_0087770b:;
    { uint32_t v_ = R32((uint32_t)(0x88117cu)); PUSH32(c, v_); } /* push dword ptr [0x1001117c] */
    PUSH32(c, 0x00877716u); f_00876c3f(c); /* call 0x876c3f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(0x88117cu), (uint32_t)(c->ebx)); /* mov dword ptr [0x1001117c], ebx */
    W32((uint32_t)(c->esi), (uint32_t)(c->ebx)); /* mov dword ptr [esi], ebx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0x881844u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x10011844], 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_0087772d(CPU *c) { /* FUN_1000772d */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, R32((uint32_t)(0x881848u)), c->ebx); /* cmp dword ptr [0x10011848], ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00877744; /* jne 0x877744 */
    PUSH32(c, 0x00877744u); f_0087ad43(c); /* call 0x87ad43 */
L_00877744:;
    c->esi = (uint32_t)((uint32_t)0x881234u); /* mov esi, 0x10011234 */
    { uint32_t v_ = 0x104u; PUSH32(c, v_); } /* push 0x104 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(0x87d074u)); PUSH32(c, 0x00877756u); call_indirect(c, t_); } /* call dword ptr [0x1000d074] */
    c->eax = (uint32_t)(R32((uint32_t)(0x881854u))); /* mov eax, dword ptr [0x10011854] */
    W32((uint32_t)(0x8811bcu), (uint32_t)(c->esi)); /* mov dword ptr [0x100111bc], esi */
    c->edi = (uint32_t)(c->esi); /* mov edi, esi */
    (void)sub8(c, R8((uint32_t)(c->eax)), ((uint8_t)c->ebx)); /* cmp byte ptr [eax], bl */
    if (c->zf) goto L_00877769; /* je 0x877769 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
L_00877769:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00877779u); f_008777c6(c); /* call 0x8777c6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->ecx * 4)); /* lea eax, [eax + ecx*4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00877788u); f_008769fa(c); /* call 0x8769fa */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (!c->zf) goto L_00877799; /* jne 0x877799 */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    PUSH32(c, 0x00877798u); f_008759e0(c); /* call 0x8759e0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00877799:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->eax * 4)); /* lea eax, [esi + eax*4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x008777afu); f_008777c6(c); /* call 0x8777c6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    W32((uint32_t)(0x8811a4u), (uint32_t)(c->esi)); /* mov dword ptr [0x100111a4], esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0x8811a0u), (uint32_t)(c->eax)); /* mov dword ptr [0x100111a0], eax */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008777c6(CPU *c) { /* FUN_100077c6 */
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
    if (c->zf) goto L_008777f0; /* je 0x8777f0 */
    W32((uint32_t)(c->edi), (uint32_t)(c->esi)); /* mov dword ptr [edi], esi */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 0xc], edi */
L_008777f0:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x22u); /* cmp byte ptr [eax], 0x22 */
    if (!c->zf) goto L_00877839; /* jne 0x877839 */
L_008777f5:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1u))); /* mov dl, byte ptr [eax + 1] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x22u); /* cmp dl, 0x22 */
    if (c->zf) goto L_00877827; /* je 0x877827 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00877827; /* je 0x877827 */
    c->edx = (uint32_t)((uint32_t)((uint8_t)c->edx)); /* movzx edx, dl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edx + 0x881601u)) & (uint8_t)0x4u)); /* test byte ptr [edx + 0x10011601], 4 */
    if (c->zf) goto L_0087781a; /* je 0x87781a */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_0087781a; /* je 0x87781a */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
L_0087781a:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_008777f5; /* je 0x8777f5 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    goto L_008777f5; /* jmp 0x8777f5 */
L_00877827:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00877831; /* je 0x877831 */
    { uint32_t a_ = (uint32_t)(c->esi); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [esi], 0 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_00877831:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x22u); /* cmp byte ptr [eax], 0x22 */
    if (!c->zf) goto L_0087787c; /* jne 0x87787c */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_0087787c; /* jmp 0x87787c */
L_00877839:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00877844; /* je 0x877844 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_00877844:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ebx = (uint32_t)((uint32_t)((uint8_t)c->edx)); /* movzx ebx, dl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebx + 0x881601u)) & (uint8_t)0x4u)); /* test byte ptr [ebx + 0x10011601], 4 */
    if (c->zf) goto L_0087785f; /* je 0x87785f */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_0087785e; /* je 0x87785e */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov bl, byte ptr [eax] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [esi], bl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_0087785e:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
L_0087785f:;
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x20u); /* cmp dl, 0x20 */
    if (c->zf) goto L_0087786d; /* je 0x87786d */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00877871; /* je 0x877871 */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x9u); /* cmp dl, 9 */
    if (!c->zf) goto L_00877839; /* jne 0x877839 */
L_0087786d:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (!c->zf) goto L_00877874; /* jne 0x877874 */
L_00877871:;
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    goto L_0087787c; /* jmp 0x87787c */
L_00877874:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_0087787c; /* je 0x87787c */
    { uint32_t a_ = (uint32_t)(c->esi + 0xffffffffu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [esi - 1], 0 */
L_0087787c:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0x18u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp + 0x18], 0 */
L_00877880:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (c->zf) goto L_00877969; /* je 0x877969 */
L_00877889:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x20u); /* cmp dl, 0x20 */
    if (c->zf) goto L_00877895; /* je 0x877895 */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x9u); /* cmp dl, 9 */
    if (!c->zf) goto L_00877898; /* jne 0x877898 */
L_00877895:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_00877889; /* jmp 0x877889 */
L_00877898:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (c->zf) goto L_00877969; /* je 0x877969 */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_008778ad; /* je 0x8778ad */
    W32((uint32_t)(c->edi), (uint32_t)(c->esi)); /* mov dword ptr [edi], esi */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 0xc], edi */
L_008778ad:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov edx, dword ptr [ebp + 0x14] */
    { uint32_t a_ = (uint32_t)(c->edx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [edx] */
L_008778b2:;
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp + 8], 1 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
L_008778bb:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x5cu); /* cmp byte ptr [eax], 0x5c */
    if (!c->zf) goto L_008778c4; /* jne 0x8778c4 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    goto L_008778bb; /* jmp 0x8778bb */
L_008778c4:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x22u); /* cmp byte ptr [eax], 0x22 */
    if (!c->zf) goto L_008778f5; /* jne 0x8778f5 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x1u)); /* test bl, 1 */
    if (!c->zf) goto L_008778f3; /* jne 0x8778f3 */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x18u)), c->edi); /* cmp dword ptr [ebp + 0x18], edi */
    if (c->zf) goto L_008778e2; /* je 0x8778e2 */
    (void)sub8(c, R8((uint32_t)(c->eax + 0x1u)), (uint8_t)0x22u); /* cmp byte ptr [eax + 1], 0x22 */
    c->edx = (uint32_t)((uint32_t)(c->eax + 0x1u)); /* lea edx, [eax + 1] */
    if (!c->zf) goto L_008778e2; /* jne 0x8778e2 */
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    goto L_008778e5; /* jmp 0x8778e5 */
L_008778e2:;
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 8], edi */
L_008778e5:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x18u)), c->edx); /* cmp dword ptr [ebp + 0x18], edx */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete dl */
    W32((uint32_t)(c->ebp + 0x18u), (uint32_t)(c->edx)); /* mov dword ptr [ebp + 0x18], edx */
L_008778f3:;
    c->ebx = (uint32_t)(shr32(c, c->ebx, 1)); /* shr ebx, 1 */
L_008778f5:;
    c->edx = (uint32_t)(c->ebx); /* mov edx, ebx */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_0087790a; /* je 0x87790a */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
L_008778fd:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00877905; /* je 0x877905 */
    W8((uint32_t)(c->esi), (uint8_t)((uint8_t)0x5cu)); /* mov byte ptr [esi], 0x5c */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_00877905:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->zf) goto L_008778fd; /* jne 0x8778fd */
L_0087790a:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_0087795a; /* je 0x87795a */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x18u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x18], 0 */
    if (!c->zf) goto L_00877920; /* jne 0x877920 */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x20u); /* cmp dl, 0x20 */
    if (c->zf) goto L_0087795a; /* je 0x87795a */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x9u); /* cmp dl, 9 */
    if (c->zf) goto L_0087795a; /* je 0x87795a */
L_00877920:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    if (c->zf) goto L_00877954; /* je 0x877954 */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00877943; /* je 0x877943 */
    c->ebx = (uint32_t)((uint32_t)((uint8_t)c->edx)); /* movzx ebx, dl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebx + 0x881601u)) & (uint8_t)0x4u)); /* test byte ptr [ebx + 0x10011601], 4 */
    if (c->zf) goto L_0087793c; /* je 0x87793c */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
L_0087793c:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    goto L_00877952; /* jmp 0x877952 */
L_00877943:;
    c->edx = (uint32_t)((uint32_t)((uint8_t)c->edx)); /* movzx edx, dl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edx + 0x881601u)) & (uint8_t)0x4u)); /* test byte ptr [edx + 0x10011601], 4 */
    if (c->zf) goto L_00877952; /* je 0x877952 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
L_00877952:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
L_00877954:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_008778b2; /* jmp 0x8778b2 */
L_0087795a:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00877962; /* je 0x877962 */
    { uint32_t a_ = (uint32_t)(c->esi); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [esi], 0 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_00877962:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    goto L_00877880; /* jmp 0x877880 */
L_00877969:;
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00877970; /* je 0x877970 */
    { uint32_t a_ = (uint32_t)(c->edi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [edi], 0 */
L_00877970:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [eax] */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_0087797a(CPU *c) { /* FUN_1000797a */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(0x881338u))); /* mov eax, dword ptr [0x10011338] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(0x87d088u))); /* mov ebp, dword ptr [0x1000d088] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (!c->zf) goto L_008779c8; /* jne 0x8779c8 */
    { uint32_t t_ = c->ebp; PUSH32(c, 0x00877997u); call_indirect(c, t_); } /* call ebp */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (c->zf) goto L_008779a9; /* je 0x8779a9 */
    W32((uint32_t)(0x881338u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x10011338], 1 */
    goto L_008779d1; /* jmp 0x8779d1 */
L_008779a9:;
    { uint32_t t_ = R32((uint32_t)(0x87d084u)); PUSH32(c, 0x008779afu); call_indirect(c, t_); } /* call dword ptr [0x1000d084] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    if (c->zf) goto L_00877aa3; /* je 0x877aa3 */
    W32((uint32_t)(0x881338u), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [0x10011338], 2 */
    goto L_00877a57; /* jmp 0x877a57 */
L_008779c8:;
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_00877a52; /* jne 0x877a52 */
L_008779d1:;
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (!c->zf) goto L_008779e1; /* jne 0x8779e1 */
    { uint32_t t_ = c->ebp; PUSH32(c, 0x008779d7u); call_indirect(c, t_); } /* call ebp */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (c->zf) goto L_00877aa3; /* je 0x877aa3 */
L_008779e1:;
    (void)sub16(c, R16((uint32_t)(c->esi)), ((uint16_t)c->ebx)); /* cmp word ptr [esi], bx */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    if (c->zf) goto L_008779f6; /* je 0x8779f6 */
L_008779e8:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub16(c, R16((uint32_t)(c->eax)), ((uint16_t)c->ebx)); /* cmp word ptr [eax], bx */
    if (!c->zf) goto L_008779e8; /* jne 0x8779e8 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub16(c, R16((uint32_t)(c->eax)), ((uint16_t)c->ebx)); /* cmp word ptr [eax], bx */
    if (!c->zf) goto L_008779e8; /* jne 0x8779e8 */
L_008779f6:;
    c->eax = (uint32_t)(sub32(c, c->eax, c->esi)); /* sub eax, esi */
    c->edi = (uint32_t)(R32((uint32_t)(0x87d080u))); /* mov edi, dword ptr [0x1000d080] */
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
    { uint32_t t_ = c->edi; PUSH32(c, 0x00877a0fu); call_indirect(c, t_); } /* call edi */
    c->ebp = (uint32_t)(c->eax); /* mov ebp, eax */
    (void)sub32(c, c->ebp, c->ebx); /* cmp ebp, ebx */
    if (c->zf) goto L_00877a47; /* je 0x877a47 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x00877a1bu); f_008769fa(c); /* call 0x8769fa */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    if (c->zf) goto L_00877a47; /* je 0x877a47 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x24u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x24] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00877a31u); call_indirect(c, t_); } /* call edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00877a43; /* jne 0x877a43 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    PUSH32(c, 0x00877a3eu); f_00876c3f(c); /* call 0x876c3f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x10], ebx */
L_00877a43:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ebx, dword ptr [esp + 0x10] */
L_00877a47:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(0x87d07cu)); PUSH32(c, 0x00877a4eu); call_indirect(c, t_); } /* call dword ptr [0x1000d07c] */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    goto L_00877aa5; /* jmp 0x877aa5 */
L_00877a52:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00877aa3; /* jne 0x877aa3 */
L_00877a57:;
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    if (!c->zf) goto L_00877a67; /* jne 0x877a67 */
    { uint32_t t_ = R32((uint32_t)(0x87d084u)); PUSH32(c, 0x00877a61u); call_indirect(c, t_); } /* call dword ptr [0x1000d084] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    if (c->zf) goto L_00877aa3; /* je 0x877aa3 */
L_00877a67:;
    (void)sub8(c, R8((uint32_t)(c->edi)), ((uint8_t)c->ebx)); /* cmp byte ptr [edi], bl */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    if (c->zf) goto L_00877a77; /* je 0x877a77 */
L_00877a6d:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), ((uint8_t)c->ebx)); /* cmp byte ptr [eax], bl */
    if (!c->zf) goto L_00877a6d; /* jne 0x877a6d */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), ((uint8_t)c->ebx)); /* cmp byte ptr [eax], bl */
    if (!c->zf) goto L_00877a6d; /* jne 0x877a6d */
L_00877a77:;
    c->eax = (uint32_t)(sub32(c, c->eax, c->edi)); /* sub eax, edi */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ebp = (uint32_t)(c->eax); /* mov ebp, eax */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x00877a82u); f_008769fa(c); /* call 0x8769fa */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (!c->zf) goto L_00877a8d; /* jne 0x877a8d */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    goto L_00877a98; /* jmp 0x877a98 */
L_00877a8d:;
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00877a95u); f_008796b0(c); /* call 0x8796b0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_00877a98:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0x87d078u)); PUSH32(c, 0x00877a9fu); call_indirect(c, t_); } /* call dword ptr [0x1000d078] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    goto L_00877aa5; /* jmp 0x877aa5 */
L_00877aa3:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00877aa5:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00877aac(CPU *c) { /* FUN_10007aac */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi], 0 */
    { uint32_t t_ = R32((uint32_t)(0x87d05cu)); PUSH32(c, 0x00877abcu); call_indirect(c, t_); } /* call dword ptr [0x1000d05c] */
    (void)sub16(c, R16((uint32_t)(c->eax)), (uint16_t)0x5a4du); /* cmp word ptr [eax], 0x5a4d */
    if (!c->zf) goto L_00877ad7; /* jne 0x877ad7 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x3cu))); /* mov ecx, dword ptr [eax + 0x3c] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00877ad7; /* je 0x877ad7 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1au))); /* mov cl, byte ptr [eax + 0x1a] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esi], cl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1bu))); /* mov al, byte ptr [eax + 0x1b] */
    W8((uint32_t)(c->esi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [esi + 1], al */
L_00877ad7:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00877ad9(CPU *c) { /* FUN_10007ad9 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->eax = (uint32_t)((uint32_t)0x122cu); /* mov eax, 0x122c */
    PUSH32(c, 0x00877ae6u); f_0087b110(c); /* call 0x87b110 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff68u)); /* lea eax, [ebp - 0x98] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(c->ebp + 0xffffff68u), (uint32_t)((uint32_t)0x94u)); /* mov dword ptr [ebp - 0x98], 0x94 */
    { uint32_t t_ = R32((uint32_t)(0x87d090u)); PUSH32(c, 0x00877afeu); call_indirect(c, t_); } /* call dword ptr [0x1000d090] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00877b1c; /* je 0x877b1c */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffff78u)), (uint32_t)0x2u); /* cmp dword ptr [ebp - 0x88], 2 */
    if (!c->zf) goto L_00877b1c; /* jne 0x877b1c */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffff6cu)), (uint32_t)0x5u); /* cmp dword ptr [ebp - 0x94], 5 */
    if (c->cf) goto L_00877b1c; /* jb 0x877b1c */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_00877c1e; /* jmp 0x877c1e */
L_00877b1c:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffedd4u)); /* lea eax, [ebp - 0x122c] */
    { uint32_t v_ = 0x1090u; PUSH32(c, v_); } /* push 0x1090 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x87d360u; PUSH32(c, v_); } /* push 0x1000d360 */
    { uint32_t t_ = R32((uint32_t)(0x87d08cu)); PUSH32(c, 0x00877b33u); call_indirect(c, t_); } /* call dword ptr [0x1000d08c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00877c0b; /* je 0x877c0b */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffedd4u)); /* lea ecx, [ebp - 0x122c] */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xffffedd4u)), ((uint8_t)c->ebx)); /* cmp byte ptr [ebp - 0x122c], bl */
    if (c->zf) goto L_00877b5e; /* je 0x877b5e */
L_00877b4b:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov al, byte ptr [ecx] */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x61u); /* cmp al, 0x61 */
    if ((c->sf != c->of)) goto L_00877b59; /* jl 0x877b59 */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x7au); /* cmp al, 0x7a */
    if ((!c->zf && c->sf == c->of)) goto L_00877b59; /* jg 0x877b59 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sub8(c, ((uint8_t)c->eax), (uint8_t)0x20u)); /* sub al, 0x20 */
    W8((uint32_t)(c->ecx), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ecx], al */
L_00877b59:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub8(c, R8((uint32_t)(c->ecx)), ((uint8_t)c->ebx)); /* cmp byte ptr [ecx], bl */
    if (!c->zf) goto L_00877b4b; /* jne 0x877b4b */
L_00877b5e:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffedd4u)); /* lea eax, [ebp - 0x122c] */
    { uint32_t v_ = 0x16u; PUSH32(c, v_); } /* push 0x16 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x87d348u; PUSH32(c, v_); } /* push 0x1000d348 */
    PUSH32(c, 0x00877b71u); f_0087b0d0(c); /* call 0x87b0d0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00877b80; /* jne 0x877b80 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffedd4u)); /* lea eax, [ebp - 0x122c] */
    goto L_00877bc9; /* jmp 0x877bc9 */
L_00877b80:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe64u)); /* lea eax, [ebp - 0x19c] */
    { uint32_t v_ = 0x104u; PUSH32(c, v_); } /* push 0x104 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(0x87d074u)); PUSH32(c, 0x00877b93u); call_indirect(c, t_); } /* call dword ptr [0x1000d074] */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xfffffe64u)), ((uint8_t)c->ebx)); /* cmp byte ptr [ebp - 0x19c], bl */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffe64u)); /* lea ecx, [ebp - 0x19c] */
    if (c->zf) goto L_00877bb4; /* je 0x877bb4 */
L_00877ba1:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov al, byte ptr [ecx] */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x61u); /* cmp al, 0x61 */
    if ((c->sf != c->of)) goto L_00877baf; /* jl 0x877baf */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x7au); /* cmp al, 0x7a */
    if ((!c->zf && c->sf == c->of)) goto L_00877baf; /* jg 0x877baf */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sub8(c, ((uint8_t)c->eax), (uint8_t)0x20u)); /* sub al, 0x20 */
    W8((uint32_t)(c->ecx), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ecx], al */
L_00877baf:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub8(c, R8((uint32_t)(c->ecx)), ((uint8_t)c->ebx)); /* cmp byte ptr [ecx], bl */
    if (!c->zf) goto L_00877ba1; /* jne 0x877ba1 */
L_00877bb4:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe64u)); /* lea eax, [ebp - 0x19c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffedd4u)); /* lea eax, [ebp - 0x122c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00877bc7u); f_0087b050(c); /* call 0x87b050 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00877bc9:;
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_00877c0b; /* je 0x877c0b */
    { uint32_t v_ = 0x2cu; PUSH32(c, v_); } /* push 0x2c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00877bd5u); f_0087af90(c); /* call 0x87af90 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00877c0b; /* je 0x877c0b */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), ((uint8_t)c->ebx)); /* cmp byte ptr [eax], bl */
    if (c->zf) goto L_00877bf0; /* je 0x877bf0 */
L_00877be2:;
    (void)sub8(c, R8((uint32_t)(c->ecx)), (uint8_t)0x3bu); /* cmp byte ptr [ecx], 0x3b */
    if (!c->zf) goto L_00877beb; /* jne 0x877beb */
    W8((uint32_t)(c->ecx), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ecx], bl */
    goto L_00877bec; /* jmp 0x877bec */
L_00877beb:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
L_00877bec:;
    (void)sub8(c, R8((uint32_t)(c->ecx)), ((uint8_t)c->ebx)); /* cmp byte ptr [ecx], bl */
    if (!c->zf) goto L_00877be2; /* jne 0x877be2 */
L_00877bf0:;
    { uint32_t v_ = 0xau; PUSH32(c, v_); } /* push 0xa */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00877bf9u); f_0087ad5f(c); /* call 0x87ad5f */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (c->zf) goto L_00877c1e; /* je 0x877c1e */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (c->zf) goto L_00877c1e; /* je 0x877c1e */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_00877c1e; /* je 0x877c1e */
L_00877c0b:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00877c14u); f_00877aac(c); /* call 0x877aac */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xfffffffcu)), (uint8_t)0x6u); /* cmp byte ptr [ebp - 4], 6 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x3u)); /* add eax, 3 */
L_00877c1e:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00877c21(CPU *c) { /* FUN_10007c21 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    (void)sub32(c, R32((uint32_t)(c->esp + 0x8u)), c->eax); /* cmp dword ptr [esp + 8], eax */
    { uint32_t v_ = 0x1000u; PUSH32(c, v_); } /* push 0x1000 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete al */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x87d098u)); PUSH32(c, 0x00877c38u); call_indirect(c, t_); } /* call dword ptr [0x1000d098] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(0x881724u), (uint32_t)(c->eax)); /* mov dword ptr [0x10011724], eax */
    if (c->zf) goto L_00877c77; /* je 0x877c77 */
    PUSH32(c, 0x00877c46u); f_00877ad9(c); /* call 0x877ad9 */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    W32((uint32_t)(0x881728u), (uint32_t)(c->eax)); /* mov dword ptr [0x10011728], eax */
    if (!c->zf) goto L_00877c5d; /* jne 0x877c5d */
    { uint32_t v_ = 0x3f8u; PUSH32(c, v_); } /* push 0x3f8 */
    PUSH32(c, 0x00877c5au); f_00878479(c); /* call 0x878479 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00877c67; /* jmp 0x877c67 */
L_00877c5d:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00877c7a; /* jne 0x877c7a */
    PUSH32(c, 0x00877c67u); f_00878fc0(c); /* call 0x878fc0 */
L_00877c67:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00877c7a; /* jne 0x877c7a */
    { uint32_t v_ = R32((uint32_t)(0x881724u)); PUSH32(c, v_); } /* push dword ptr [0x10011724] */
    { uint32_t t_ = R32((uint32_t)(0x87d094u)); PUSH32(c, 0x00877c77u); call_indirect(c, t_); } /* call dword ptr [0x1000d094] */
L_00877c77:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_00877c7a:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_00877c7e(CPU *c) { /* FUN_10007c7e */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x881728u))); /* mov eax, dword ptr [0x10011728] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00877cf0; /* jne 0x877cf0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, R32((uint32_t)(0x881718u)), c->ebx); /* cmp dword ptr [0x10011718], ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(0x87d054u))); /* mov ebp, dword ptr [0x1000d054] */
    if ((c->zf || c->sf != c->of)) goto L_00877cdc; /* jle 0x877cdc */
    c->eax = (uint32_t)(R32((uint32_t)(0x88171cu))); /* mov eax, dword ptr [0x1001171c] */
    c->edi = (uint32_t)(R32((uint32_t)(0x87d09cu))); /* mov edi, dword ptr [0x1000d09c] */
    c->esi = (uint32_t)((uint32_t)(c->eax + 0xcu)); /* lea esi, [eax + 0xc] */
L_00877caa:;
    { uint32_t v_ = 0x4000u; PUSH32(c, v_); } /* push 0x4000 */
    { uint32_t v_ = 0x100000u; PUSH32(c, v_); } /* push 0x100000 */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00877cb8u); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = 0x8000u; PUSH32(c, v_); } /* push 0x8000 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00877cc3u); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esi + 4] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x881724u)); PUSH32(c, v_); } /* push dword ptr [0x10011724] */
    { uint32_t t_ = c->ebp; PUSH32(c, 0x00877cd0u); call_indirect(c, t_); } /* call ebp */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x14u)); /* add esi, 0x14 */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    (void)sub32(c, c->ebx, R32((uint32_t)(0x881718u))); /* cmp ebx, dword ptr [0x10011718] */
    if ((c->sf != c->of)) goto L_00877caa; /* jl 0x877caa */
L_00877cdc:;
    { uint32_t v_ = R32((uint32_t)(0x88171cu)); PUSH32(c, v_); } /* push dword ptr [0x1001171c] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x881724u)); PUSH32(c, v_); } /* push dword ptr [0x10011724] */
    { uint32_t t_ = c->ebp; PUSH32(c, 0x00877cecu); call_indirect(c, t_); } /* call ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    goto L_00877d17; /* jmp 0x877d17 */
L_00877cf0:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00877d17; /* jne 0x877d17 */
    c->edi = (uint32_t)((uint32_t)0x87e898u); /* mov edi, 0x1000e898 */
    c->esi = (uint32_t)(c->edi); /* mov esi, edi */
L_00877cfc:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00877d11; /* je 0x877d11 */
    { uint32_t v_ = 0x8000u; PUSH32(c, v_); } /* push 0x8000 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x87d09cu)); PUSH32(c, 0x00877d11u); call_indirect(c, t_); } /* call dword ptr [0x1000d09c] */
L_00877d11:;
    c->esi = (uint32_t)(R32((uint32_t)(c->esi))); /* mov esi, dword ptr [esi] */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_00877cfc; /* jne 0x877cfc */
L_00877d17:;
    { uint32_t v_ = R32((uint32_t)(0x881724u)); PUSH32(c, v_); } /* push dword ptr [0x10011724] */
    { uint32_t t_ = R32((uint32_t)(0x87d094u)); PUSH32(c, 0x00877d23u); call_indirect(c, t_); } /* call dword ptr [0x1000d094] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00877d26(CPU *c) { /* FUN_10007d26 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 16; return; /* ret 0xc */
}

void f_00877d2c(CPU *c) { /* FUN_10007d2c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x881184u))); /* mov eax, dword ptr [0x10011184] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_00877d43; /* je 0x877d43 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00877d64; /* jne 0x877d64 */
    (void)sub32(c, R32((uint32_t)(0x881188u)), (uint32_t)0x1u); /* cmp dword ptr [0x10011188], 1 */
    if (!c->zf) goto L_00877d64; /* jne 0x877d64 */
L_00877d43:;
    { uint32_t v_ = 0xfcu; PUSH32(c, v_); } /* push 0xfc */
    PUSH32(c, 0x00877d4du); f_00877d65(c); /* call 0x877d65 */
    c->eax = (uint32_t)(R32((uint32_t)(0x88133cu))); /* mov eax, dword ptr [0x1001133c] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00877d59; /* je 0x877d59 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00877d59u); call_indirect(c, t_); } /* call eax */
L_00877d59:;
    { uint32_t v_ = 0xffu; PUSH32(c, v_); } /* push 0xff */
    PUSH32(c, 0x00877d63u); f_00877d65(c); /* call 0x877d65 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00877d64:;
    c->esp += 4; return; /* ret  */
}

void f_00877d65(CPU *c) { /* FUN_10007d65 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x1a4u)); /* sub esp, 0x1a4 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->eax = (uint32_t)((uint32_t)0x87e778u); /* mov eax, 0x1000e778 */
L_00877d78:;
    (void)sub32(c, c->edx, R32((uint32_t)(c->eax))); /* cmp edx, dword ptr [eax] */
    if (c->zf) goto L_00877d87; /* je 0x877d87 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->eax, (uint32_t)0x87e808u); /* cmp eax, 0x1000e808 */
    if ((c->sf != c->of)) goto L_00877d78; /* jl 0x877d78 */
L_00877d87:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->esi = (uint32_t)(shl32(c, c->esi, 3)); /* shl esi, 3 */
    (void)sub32(c, c->edx, R32((uint32_t)(c->esi + 0x87e778u))); /* cmp edx, dword ptr [esi + 0x1000e778] */
    if (!c->zf) goto L_00877eb5; /* jne 0x877eb5 */
    c->eax = (uint32_t)(R32((uint32_t)(0x881184u))); /* mov eax, dword ptr [0x10011184] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_00877e8f; /* je 0x877e8f */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00877db8; /* jne 0x877db8 */
    (void)sub32(c, R32((uint32_t)(0x881188u)), (uint32_t)0x1u); /* cmp dword ptr [0x10011188], 1 */
    if (c->zf) goto L_00877e8f; /* je 0x877e8f */
L_00877db8:;
    (void)sub32(c, c->edx, (uint32_t)0xfcu); /* cmp edx, 0xfc */
    if (c->zf) goto L_00877eb5; /* je 0x877eb5 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea eax, [ebp - 0x1a4] */
    { uint32_t v_ = 0x104u; PUSH32(c, v_); } /* push 0x104 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t t_ = R32((uint32_t)(0x87d074u)); PUSH32(c, 0x00877dd8u); call_indirect(c, t_); } /* call dword ptr [0x1000d074] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00877def; /* jne 0x877def */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea eax, [ebp - 0x1a4] */
    { uint32_t v_ = 0x87d650u; PUSH32(c, v_); } /* push 0x1000d650 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00877dedu); f_0087a200(c); /* call 0x87a200 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00877def:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea eax, [ebp - 0x1a4] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea edi, [ebp - 0x1a4] */
    PUSH32(c, 0x00877e02u); f_00877340(c); /* call 0x877340 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->eax, (uint32_t)0x3cu); /* cmp eax, 0x3c */
    if ((c->cf || c->zf)) goto L_00877e32; /* jbe 0x877e32 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea eax, [ebp - 0x1a4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00877e15u); f_00877340(c); /* call 0x877340 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea eax, [ebp - 0x1a4] */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3bu)); /* sub eax, 0x3b */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t v_ = 0x87d64cu; PUSH32(c, v_); } /* push 0x1000d64c */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00877e2fu); f_0087b1d0(c); /* call 0x87b1d0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_00877e32:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff60u)); /* lea eax, [ebp - 0xa0] */
    { uint32_t v_ = 0x87d630u; PUSH32(c, v_); } /* push 0x1000d630 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00877e43u); f_0087a200(c); /* call 0x87a200 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff60u)); /* lea eax, [ebp - 0xa0] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00877e50u); f_0087a210(c); /* call 0x87a210 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff60u)); /* lea eax, [ebp - 0xa0] */
    { uint32_t v_ = 0x87d62cu; PUSH32(c, v_); } /* push 0x1000d62c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00877e61u); f_0087a210(c); /* call 0x87a210 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x87e77cu)); PUSH32(c, v_); } /* push dword ptr [esi + 0x1000e77c] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff60u)); /* lea eax, [ebp - 0xa0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00877e73u); f_0087a210(c); /* call 0x87a210 */
    { uint32_t v_ = 0x12010u; PUSH32(c, v_); } /* push 0x12010 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff60u)); /* lea eax, [ebp - 0xa0] */
    { uint32_t v_ = 0x87d604u; PUSH32(c, v_); } /* push 0x1000d604 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00877e89u); f_0087b13f(c); /* call 0x87b13f */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    goto L_00877eb5; /* jmp 0x877eb5 */
L_00877e8f:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x8u)); /* lea eax, [ebp + 8] */
    c->esi = (uint32_t)((uint32_t)(c->esi + 0x87e77cu)); /* lea esi, [esi + 0x1000e77c] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    PUSH32(c, 0x00877ea2u); f_00877340(c); /* call 0x877340 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    { uint32_t v_ = 0xfffffff4u; PUSH32(c, v_); } /* push -0xc */
    { uint32_t t_ = R32((uint32_t)(0x87d068u)); PUSH32(c, 0x00877eaeu); call_indirect(c, t_); } /* call dword ptr [0x1000d068] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x87d0a0u)); PUSH32(c, 0x00877eb5u); call_indirect(c, t_); } /* call dword ptr [0x1000d0a0] */
L_00877eb5:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00877eb8(CPU *c) { /* FUN_10007eb8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    { uint32_t t_ = R32((uint32_t)(0x87d0a4u)); PUSH32(c, 0x00877ecau); call_indirect(c, t_); } /* call dword ptr [0x1000d0a4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00877ed0; /* je 0x877ed0 */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_00877ed0:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00877ed4(CPU *c) { /* FUN_10007ed4 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    { uint32_t t_ = R32((uint32_t)(0x87d0a8u)); PUSH32(c, 0x00877ee6u); call_indirect(c, t_); } /* call dword ptr [0x1000d0a8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00877eec; /* je 0x877eec */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_00877eec:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00877ef0(CPU *c) { /* FUN_10007ef0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    { uint32_t t_ = R32((uint32_t)(0x87d0acu)); PUSH32(c, 0x00877efeu); call_indirect(c, t_); } /* call dword ptr [0x1000d0ac] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00877f04; /* je 0x877f04 */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_00877f04:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00877f08(CPU *c) { /* PTR_00877f08 */
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
    if (!c->zf) goto L_00877fb0; /* jne 0x877fb0 */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    W32((uint32_t)(c->ebx + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebx - 4], eax */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebx + 0xcu))); /* mov esi, dword ptr [ebx + 0xc] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov edi, dword ptr [ebx + 8] */
L_00877f43:;
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (c->zf) goto L_00877fa9; /* je 0x877fa9 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea ecx, [esi + esi*2] */
    (void)sub32(c, R32((uint32_t)(c->edi + c->ecx * 4 + 0x4u)), (uint32_t)0x0u); /* cmp dword ptr [edi + ecx*4 + 4], 0 */
    if (c->zf) goto L_00877f97; /* je 0x877f97 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)((uint32_t)(c->ebx + 0x10u)); /* lea ebp, [ebx + 0x10] */
    { uint32_t t_ = R32((uint32_t)(c->edi + c->ecx * 4 + 0x4u)); PUSH32(c, 0x00877f5bu); call_indirect(c, t_); } /* call dword ptr [edi + ecx*4 + 4] */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ebx, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->eax))); /* or eax, eax */
    if (c->zf) goto L_00877f97; /* je 0x877f97 */
    if (c->sf) goto L_00877fa2; /* js 0x877fa2 */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov edi, dword ptr [ebx + 8] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00877f6fu); f_008754b8(c); /* call 0x8754b8 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->ebp = (uint32_t)((uint32_t)(c->ebx + 0x10u)); /* lea ebp, [ebx + 0x10] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00877f7cu); f_008754fa(c); /* call 0x8754fa */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea ecx, [esi + esi*2] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + c->ecx * 4 + 0x8u))); /* mov eax, dword ptr [edi + ecx*4 + 8] */
    PUSH32(c, 0x00877f8du); f_0087558e(c); /* call 0x87558e */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + c->ecx * 4))); /* mov eax, dword ptr [edi + ecx*4] */
    W32((uint32_t)(c->ebx + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 0xc], eax */
    { uint32_t t_ = R32((uint32_t)(c->edi + c->ecx * 4 + 0x8u)); PUSH32(c, 0x00877f97u); call_indirect(c, t_); } /* call dword ptr [edi + ecx*4 + 8] */
L_00877f97:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov edi, dword ptr [ebx + 8] */
    c->ecx = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea ecx, [esi + esi*2] */
    c->esi = (uint32_t)(R32((uint32_t)(c->edi + c->ecx * 4))); /* mov esi, dword ptr [edi + ecx*4] */
    goto L_00877f43; /* jmp 0x877f43 */
L_00877fa2:;
    c->eax = (uint32_t)((uint32_t)0x0u); /* mov eax, 0 */
    goto L_00877fc5; /* jmp 0x877fc5 */
L_00877fa9:;
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    goto L_00877fc5; /* jmp 0x877fc5 */
L_00877fb0:;
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)((uint32_t)(c->ebx + 0x10u)); /* lea ebp, [ebx + 0x10] */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00877fbcu); f_008754fa(c); /* call 0x8754fa */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
L_00877fc5:;
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00877fcd(CPU *c) { /* FUN_10007fcd */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov ebp, dword ptr [ecx] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x1cu))); /* mov eax, dword ptr [ecx + 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x18u))); /* mov eax, dword ptr [ecx + 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00877fe1u); f_008754fa(c); /* call 0x8754fa */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 8; return; /* ret 4 */
}

void f_00877ff0(CPU *c) { /* FUN_10007ff0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    c->eax = (uint32_t)(add32(c, c->eax, c->esi)); /* add eax, esi */
    (void)sub32(c, c->edi, c->esi); /* cmp edi, esi */
    if ((c->cf || c->zf)) goto L_00878010; /* jbe 0x878010 */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_00878188; /* jb 0x878188 */
L_00878010:;
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x3u)); /* test edi, 3 */
    if (!c->zf) goto L_0087802c; /* jne 0x87802c */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u))); /* and edx, 3 */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) goto L_0087804c; /* jb 0x87804c */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x878138u)); switch (t_) { case 0x00878148u: goto L_00878148; case 0x00878150u: goto L_00878150; case 0x0087815cu: goto L_0087815c; case 0x00878170u: goto L_00878170; default: jump_indirect(c, t_, 0x00878025u); return; } } /* jmp dword ptr [edx*4 + 0x10008138] */
L_0087802c:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edx = (uint32_t)((uint32_t)0x3u); /* mov edx, 3 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x4u)); /* sub ecx, 4 */
    if (c->cf) goto L_00878044; /* jb 0x878044 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x3u))); /* and eax, 3 */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->eax * 4 + 0x878050u)); switch (t_) {  default: jump_indirect(c, t_, 0x0087803du); return; } } /* jmp dword ptr [eax*4 + 0x10008050] */
L_00878044:;
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0x878148u)); switch (t_) {  default: jump_indirect(c, t_, 0x00878044u); return; } } /* jmp dword ptr [ecx*4 + 0x10008148] */
L_0087804c:;
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0x8780ccu)); switch (t_) { case 0x008780ecu: goto L_008780ec; case 0x008780f4u: goto L_008780f4; case 0x008780fcu: goto L_008780fc; case 0x00878104u: goto L_00878104; case 0x0087810cu: goto L_0087810c; case 0x00878114u: goto L_00878114; case 0x0087811cu: goto L_0087811c; case 0x0087812fu: goto L_0087812f; default: jump_indirect(c, t_, 0x0087804cu); return; } } /* jmp dword ptr [ecx*4 + 0x100080cc] */
L_008780ec:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe4u))); /* mov eax, dword ptr [esi + ecx*4 - 0x1c] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x1c], eax */
L_008780f4:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe8u))); /* mov eax, dword ptr [esi + ecx*4 - 0x18] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x18], eax */
L_008780fc:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffecu))); /* mov eax, dword ptr [esi + ecx*4 - 0x14] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffecu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x14], eax */
L_00878104:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff0u))); /* mov eax, dword ptr [esi + ecx*4 - 0x10] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x10], eax */
L_0087810c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff4u))); /* mov eax, dword ptr [esi + ecx*4 - 0xc] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0xc], eax */
L_00878114:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff8u))); /* mov eax, dword ptr [esi + ecx*4 - 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 8], eax */
L_0087811c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
L_0087812f:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x878138u)); switch (t_) { case 0x00878148u: goto L_00878148; case 0x00878150u: goto L_00878150; case 0x0087815cu: goto L_0087815c; case 0x00878170u: goto L_00878170; default: jump_indirect(c, t_, 0x0087812fu); return; } } /* jmp dword ptr [edx*4 + 0x10008138] */
L_00878148:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00878150:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0087815c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00878170:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00878188:;
    c->esi = (uint32_t)((uint32_t)(c->ecx + c->esi + 0xfffffffcu)); /* lea esi, [ecx + esi - 4] */
    c->edi = (uint32_t)((uint32_t)(c->ecx + c->edi + 0xfffffffcu)); /* lea edi, [ecx + edi - 4] */
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x3u)); /* test edi, 3 */
    if (!c->zf) goto L_008781bc; /* jne 0x8781bc */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u))); /* and edx, 3 */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) goto L_008781b0; /* jb 0x8781b0 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x8782d0u)); switch (t_) { case 0x008782e0u: goto L_008782e0; case 0x008782e8u: goto L_008782e8; case 0x008782f8u: goto L_008782f8; case 0x0087830cu: goto L_0087830c; default: jump_indirect(c, t_, 0x008781a7u); return; } } /* jmp dword ptr [edx*4 + 0x100082d0] */
L_008781b0:;
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0x878280u)); switch (t_) { case 0x008782c7u: goto L_008782c7; default: jump_indirect(c, t_, 0x008781b2u); return; } } /* jmp dword ptr [ecx*4 + 0x10008280] */
L_008781bc:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edx = (uint32_t)((uint32_t)0x3u); /* mov edx, 3 */
    (void)sub32(c, c->ecx, (uint32_t)0x4u); /* cmp ecx, 4 */
    if (c->cf) goto L_008781d4; /* jb 0x8781d4 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x3u))); /* and eax, 3 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->eax * 4 + 0x8781d8u)); switch (t_) {  default: jump_indirect(c, t_, 0x008781cdu); return; } } /* jmp dword ptr [eax*4 + 0x100081d8] */
L_008781d4:;
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0x8782d0u)); switch (t_) { case 0x008782e0u: goto L_008782e0; case 0x008782e8u: goto L_008782e8; case 0x008782f8u: goto L_008782f8; case 0x0087830cu: goto L_0087830c; default: jump_indirect(c, t_, 0x008781d4u); return; } } /* jmp dword ptr [ecx*4 + 0x100082d0] */
L_008782c7:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x8782d0u)); switch (t_) { case 0x008782e0u: goto L_008782e0; case 0x008782e8u: goto L_008782e8; case 0x008782f8u: goto L_008782f8; case 0x0087830cu: goto L_0087830c; default: jump_indirect(c, t_, 0x008782c7u); return; } } /* jmp dword ptr [edx*4 + 0x100082d0] */
L_008782e0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008782e8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008782f8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0087830c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0087804c(CPU *c) { /* PTR_0087804c */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0x8780ccu)); switch (t_) { case 0x008780ecu: goto L_008780ec; case 0x008780f4u: goto L_008780f4; case 0x008780fcu: goto L_008780fc; case 0x00878104u: goto L_00878104; case 0x0087810cu: goto L_0087810c; case 0x00878114u: goto L_00878114; case 0x0087811cu: goto L_0087811c; case 0x0087812fu: goto L_0087812f; default: jump_indirect(c, t_, 0x0087804cu); return; } } /* jmp dword ptr [ecx*4 + 0x100080cc] */
L_008780ec:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe4u))); /* mov eax, dword ptr [esi + ecx*4 - 0x1c] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x1c], eax */
L_008780f4:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe8u))); /* mov eax, dword ptr [esi + ecx*4 - 0x18] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x18], eax */
L_008780fc:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffecu))); /* mov eax, dword ptr [esi + ecx*4 - 0x14] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffecu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x14], eax */
L_00878104:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff0u))); /* mov eax, dword ptr [esi + ecx*4 - 0x10] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x10], eax */
L_0087810c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff4u))); /* mov eax, dword ptr [esi + ecx*4 - 0xc] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0xc], eax */
L_00878114:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff8u))); /* mov eax, dword ptr [esi + ecx*4 - 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 8], eax */
L_0087811c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
L_0087812f:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x878138u)); switch (t_) { case 0x00878148u: goto L_00878148; case 0x00878150u: goto L_00878150; case 0x0087815cu: goto L_0087815c; case 0x00878170u: goto L_00878170; default: jump_indirect(c, t_, 0x0087812fu); return; } } /* jmp dword ptr [edx*4 + 0x10008138] */
L_00878148:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00878150:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0087815c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00878170:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00878050(CPU *c) { /* PTR_00878050 */
    PREEMPT_POLL(c);
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), (uint8_t)0x10u))); } /* add byte ptr [eax], 0x10 */
    ; /* nop  */
    { uint32_t s_ = c->esp; PUSH32(c, c->eax); PUSH32(c, c->ecx); PUSH32(c, c->edx); PUSH32(c, c->ebx); PUSH32(c, s_); PUSH32(c, c->ebp); PUSH32(c, c->esi); PUSH32(c, c->edi); } /* pushal  */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), (uint8_t)0x10u))); } /* add byte ptr [eax], 0x10 */
    guest_trap(c, 0x00878058u, "unsupported: mov word ptr [eax - 0x7f4ff000], es"); /* mov word ptr [eax - 0x7f4ff000], es */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & c->ecx))); /* and edx, ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x3u)); /* add esi, 3 */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x3u)); /* add edi, 3 */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) { f_0087804c(c); return; } /* jb 0x87804c */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x878138u)); switch (t_) { case 0x00878148u: goto L_00878148; case 0x00878150u: goto L_00878150; case 0x0087815cu: goto L_0087815c; case 0x00878170u: goto L_00878170; default: jump_indirect(c, t_, 0x00878082u); return; } } /* jmp dword ptr [edx*4 + 0x10008138] */
L_00878148:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00878150:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0087815c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00878170:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00878060(CPU *c) { /* PTR_00878060 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & c->ecx))); /* and edx, ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x3u)); /* add esi, 3 */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x3u)); /* add edi, 3 */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) { f_0087804c(c); return; } /* jb 0x87804c */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x878138u)); switch (t_) { case 0x00878148u: goto L_00878148; case 0x00878150u: goto L_00878150; case 0x0087815cu: goto L_0087815c; case 0x00878170u: goto L_00878170; default: jump_indirect(c, t_, 0x00878082u); return; } } /* jmp dword ptr [edx*4 + 0x10008138] */
L_00878148:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00878150:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0087815c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00878170:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00878080(CPU *c) { /* PTR_00878080 */
    PREEMPT_POLL(c);
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x878138u)); switch (t_) { case 0x00878148u: goto L_00878148; case 0x00878150u: goto L_00878150; case 0x0087815cu: goto L_0087815c; case 0x00878170u: goto L_00878170; default: jump_indirect(c, t_, 0x00878082u); return; } } /* jmp dword ptr [edx*4 + 0x10008138] */
L_00878148:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00878150:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0087815c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00878170:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0087808c(CPU *c) { /* PTR_0087808c */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & c->ecx))); /* and edx, ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x2u)); /* add esi, 2 */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x2u)); /* add edi, 2 */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) { f_0087804c(c); return; } /* jb 0x87804c */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x878138u)); switch (t_) { case 0x00878148u: goto L_00878148; case 0x00878150u: goto L_00878150; case 0x0087815cu: goto L_0087815c; case 0x00878170u: goto L_00878170; default: jump_indirect(c, t_, 0x008780a8u); return; } } /* jmp dword ptr [edx*4 + 0x10008138] */
L_00878148:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00878150:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0087815c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00878170:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008780b0(CPU *c) { /* PTR_008780b0 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & c->ecx))); /* and edx, ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) { f_0087804c(c); return; } /* jb 0x87804c */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x878138u)); switch (t_) { case 0x00878148u: goto L_00878148; case 0x00878150u: goto L_00878150; case 0x0087815cu: goto L_0087815c; case 0x00878170u: goto L_00878170; default: jump_indirect(c, t_, 0x008780c2u); return; } } /* jmp dword ptr [edx*4 + 0x10008138] */
L_00878148:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00878150:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0087815c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00878170:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008780ec(CPU *c) { /* PTR_008780ec */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe4u))); /* mov eax, dword ptr [esi + ecx*4 - 0x1c] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x1c], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe8u))); /* mov eax, dword ptr [esi + ecx*4 - 0x18] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x18], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffecu))); /* mov eax, dword ptr [esi + ecx*4 - 0x14] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffecu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x14], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff0u))); /* mov eax, dword ptr [esi + ecx*4 - 0x10] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x10], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff4u))); /* mov eax, dword ptr [esi + ecx*4 - 0xc] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0xc], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff8u))); /* mov eax, dword ptr [esi + ecx*4 - 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x878138u)); switch (t_) { case 0x00878148u: goto L_00878148; case 0x00878150u: goto L_00878150; case 0x0087815cu: goto L_0087815c; case 0x00878170u: goto L_00878170; default: jump_indirect(c, t_, 0x0087812fu); return; } } /* jmp dword ptr [edx*4 + 0x10008138] */
L_00878148:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00878150:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0087815c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00878170:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008780f4(CPU *c) { /* PTR_008780f4 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe8u))); /* mov eax, dword ptr [esi + ecx*4 - 0x18] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x18], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffecu))); /* mov eax, dword ptr [esi + ecx*4 - 0x14] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffecu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x14], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff0u))); /* mov eax, dword ptr [esi + ecx*4 - 0x10] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x10], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff4u))); /* mov eax, dword ptr [esi + ecx*4 - 0xc] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0xc], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff8u))); /* mov eax, dword ptr [esi + ecx*4 - 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x878138u)); switch (t_) { case 0x00878148u: goto L_00878148; case 0x00878150u: goto L_00878150; case 0x0087815cu: goto L_0087815c; case 0x00878170u: goto L_00878170; default: jump_indirect(c, t_, 0x0087812fu); return; } } /* jmp dword ptr [edx*4 + 0x10008138] */
L_00878148:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00878150:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0087815c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00878170:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008780fc(CPU *c) { /* PTR_008780fc */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffecu))); /* mov eax, dword ptr [esi + ecx*4 - 0x14] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffecu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x14], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff0u))); /* mov eax, dword ptr [esi + ecx*4 - 0x10] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x10], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff4u))); /* mov eax, dword ptr [esi + ecx*4 - 0xc] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0xc], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff8u))); /* mov eax, dword ptr [esi + ecx*4 - 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x878138u)); switch (t_) { case 0x00878148u: goto L_00878148; case 0x00878150u: goto L_00878150; case 0x0087815cu: goto L_0087815c; case 0x00878170u: goto L_00878170; default: jump_indirect(c, t_, 0x0087812fu); return; } } /* jmp dword ptr [edx*4 + 0x10008138] */
L_00878148:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00878150:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0087815c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00878170:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00878104(CPU *c) { /* PTR_00878104 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff0u))); /* mov eax, dword ptr [esi + ecx*4 - 0x10] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x10], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff4u))); /* mov eax, dword ptr [esi + ecx*4 - 0xc] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0xc], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff8u))); /* mov eax, dword ptr [esi + ecx*4 - 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x878138u)); switch (t_) { case 0x00878148u: goto L_00878148; case 0x00878150u: goto L_00878150; case 0x0087815cu: goto L_0087815c; case 0x00878170u: goto L_00878170; default: jump_indirect(c, t_, 0x0087812fu); return; } } /* jmp dword ptr [edx*4 + 0x10008138] */
L_00878148:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00878150:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0087815c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00878170:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0087810c(CPU *c) { /* PTR_0087810c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff4u))); /* mov eax, dword ptr [esi + ecx*4 - 0xc] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0xc], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff8u))); /* mov eax, dword ptr [esi + ecx*4 - 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x878138u)); switch (t_) { case 0x00878148u: goto L_00878148; case 0x00878150u: goto L_00878150; case 0x0087815cu: goto L_0087815c; case 0x00878170u: goto L_00878170; default: jump_indirect(c, t_, 0x0087812fu); return; } } /* jmp dword ptr [edx*4 + 0x10008138] */
L_00878148:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00878150:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0087815c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00878170:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00878114(CPU *c) { /* PTR_00878114 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff8u))); /* mov eax, dword ptr [esi + ecx*4 - 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x878138u)); switch (t_) { case 0x00878148u: goto L_00878148; case 0x00878150u: goto L_00878150; case 0x0087815cu: goto L_0087815c; case 0x00878170u: goto L_00878170; default: jump_indirect(c, t_, 0x0087812fu); return; } } /* jmp dword ptr [edx*4 + 0x10008138] */
L_00878148:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00878150:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0087815c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00878170:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0087811c(CPU *c) { /* PTR_0087811c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x878138u)); switch (t_) { case 0x00878148u: goto L_00878148; case 0x00878150u: goto L_00878150; case 0x0087815cu: goto L_0087815c; case 0x00878170u: goto L_00878170; default: jump_indirect(c, t_, 0x0087812fu); return; } } /* jmp dword ptr [edx*4 + 0x10008138] */
L_00878148:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00878150:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0087815c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00878170:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0087812f(CPU *c) { /* PTR_0087812f */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x878138u)); switch (t_) { case 0x00878148u: goto L_00878148; case 0x00878150u: goto L_00878150; case 0x0087815cu: goto L_0087815c; case 0x00878170u: goto L_00878170; default: jump_indirect(c, t_, 0x0087812fu); return; } } /* jmp dword ptr [edx*4 + 0x10008138] */
L_00878148:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00878150:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0087815c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00878170:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00878148(CPU *c) { /* PTR_00878148 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00878150(CPU *c) { /* PTR_00878150 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0087815c(CPU *c) { /* PTR_0087815c */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}
