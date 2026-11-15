#include "recomp.h"

void f_00b21000(CPU *c) { /* DMAInterface */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    W32((uint32_t)(0xb333b4u), (uint32_t)(c->eax)); /* mov dword ptr [0x100133b4], eax */
    W32((uint32_t)(0xb333acu), (uint32_t)(c->eax)); /* mov dword ptr [0x100133ac], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov eax, dword ptr [eax + 4] */
    W32((uint32_t)(0xb33398u), (uint32_t)(c->ecx)); /* mov dword ptr [0x10013398], ecx */
    W32((uint32_t)(0xb333b0u), (uint32_t)(c->eax)); /* mov dword ptr [0x100133b0], eax */
    c->eax = (uint32_t)(R32((uint32_t)(0xb333b8u))); /* mov eax, dword ptr [0x100133b8] */
    c->esp += 4; return; /* ret  */
}

void f_00b21030(CPU *c) { /* FUN_10001030 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(0xb333b4u))); /* mov ecx, dword ptr [0x100133b4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x00b21040u); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
    c->esp += 4; return; /* ret  */
}

void f_00b21050(CPU *c) { /* FUN_10001050 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb333b4u))); /* mov ecx, dword ptr [0x100133b4] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4u)); PUSH32(c, 0x00b2106au); call_indirect(c, t_); } /* call dword ptr [eax + 4] */
    c->esp += 4; return; /* ret  */
}

void f_00b21070(CPU *c) { /* PTR_00b21070 */
    PREEMPT_POLL(c);
    PUSH32(c, 0x00b21075u); f_00b21080(c); /* call 0xb21080 */
    { f_00b21160(c); return; } /* jmp 0xb21160 */
}

void f_00b21080(CPU *c) { /* FUN_10001080 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xb333b8u; PUSH32(c, v_); } /* push 0x100133b8 */
    c->ecx = (uint32_t)((uint32_t)0xb3339cu); /* mov ecx, 0x1001339c */
    PUSH32(c, 0x00b2108fu); f_00b21090(c); /* call 0xb21090 */
    c->esp += 4; return; /* ret  */
}

void f_00b21090(CPU *c) { /* FUN_10001090 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0xc], ecx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0xb2e0f0u)); /* mov dword ptr [eax], 0x1000e0f0 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 4], edx */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    c->esp += 8; return; /* ret 4 */
}

void f_00b210b0(CPU *c) { /* PTR_00b210b0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb30040u); /* mov eax, 0x10010040 */
    c->esp += 4; return; /* ret  */
}

void f_00b210c0(CPU *c) { /* FUN_100010c0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xb2de44u; PUSH32(c, v_); } /* push 0x1000de44 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov eax, dword ptr [ecx + 0xc] */
    { uint32_t v_ = 0xbu; PUSH32(c, v_); } /* push 0xb */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t v_ = 0xb30048u; PUSH32(c, v_); } /* push 0x10010048 */
    { uint32_t v_ = 0x2cu; PUSH32(c, v_); } /* push 0x2c */
    W32((uint32_t)(c->ecx + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 0xc], eax */
    PUSH32(c, 0x00b210ebu); f_00b21050(c); /* call 0xb21050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->esp), (uint32_t)(c->eax)); /* mov dword ptr [esp], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0xc], 0 */
    if (c->zf) goto L_00b21114; /* je 0xb21114 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    PUSH32(c, 0x00b21105u); f_00b21180(c); /* call 0xb21180 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
L_00b21114:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_00b21130(CPU *c) { /* FUN_10001130 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00b21138u); f_00b21150(c); /* call 0xb21150 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00b21148; /* je 0xb21148 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b21145u); f_00b21030(c); /* call 0xb21030 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00b21148:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00b21150(CPU *c) { /* FUN_10001150 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx), (uint32_t)((uint32_t)0xb2e110u)); /* mov dword ptr [ecx], 0x1000e110 */
    c->esp += 4; return; /* ret  */
}

void f_00b21160(CPU *c) { /* FUN_10001160 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xb21170u; PUSH32(c, v_); } /* push 0x10001170 */
    PUSH32(c, 0x00b2116au); f_00b257c4(c); /* call 0xb257c4 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00b21170(CPU *c) { /* PTR_00b21170 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)0xb3339cu); /* mov ecx, 0x1001339c */
    { f_00b21150(c); return; } /* jmp 0xb21150 */
}

void f_00b21180(CPU *c) { /* FUN_10001180 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xb2de94u; PUSH32(c, v_); } /* push 0x1000de94 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x20u)); /* sub esp, 0x20 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->ecx); /* mov ebp, ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0x4u)); /* lea edi, [ebp + 4] */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0x14], ebp */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 4], eax */
    W32((uint32_t)(c->edi + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [edi + 8], ebx */
    W32((uint32_t)(c->edi + 0xcu), (uint32_t)(c->ebx)); /* mov dword ptr [edi + 0xc], ebx */
    W32((uint32_t)(c->edi + 0x10u), (uint32_t)(c->ebx)); /* mov dword ptr [edi + 0x10], ebx */
    W32((uint32_t)(c->edi + 0x14u), (uint32_t)(c->ebx)); /* mov dword ptr [edi + 0x14], ebx */
    W32((uint32_t)(c->ebp), (uint32_t)((uint32_t)0xb2e154u)); /* mov dword ptr [ebp], 0x1000e154 */
    W32((uint32_t)(c->ebp + 0x1cu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 0x1c], ebx */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb33398u))); /* mov ecx, dword ptr [0x10013398] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x00b211d2u); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb33398u))); /* mov ecx, dword ptr [0x10013398] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x18u)); /* lea edx, [esp + 0x18] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x10u)); PUSH32(c, 0x00b211e2u); call_indirect(c, t_); } /* call dword ptr [eax + 0x10] */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edx, dword ptr [ebp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb33398u))); /* mov ecx, dword ptr [0x10013398] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov edx, dword ptr [ebp + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4u)); PUSH32(c, 0x00b211feu); call_indirect(c, t_); } /* call dword ptr [eax + 4] */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    { uint32_t v_ = 0xb30048u; PUSH32(c, v_); } /* push 0x10010048 */
    { uint32_t v_ = 0x3504u; PUSH32(c, v_); } /* push 0x3504 */
    W32((uint32_t)(c->esp + 0x44u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x44], ebx */
    W32((uint32_t)(c->ebp + 0x20u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 0x20], ebx */
    W32((uint32_t)(c->ebp + 0x24u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 0x24], ebx */
    W32((uint32_t)(c->ebp + 0x28u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 0x28], ebx */
    W32((uint32_t)(c->ebp), (uint32_t)((uint32_t)0xb2e130u)); /* mov dword ptr [ebp], 0x1000e130 */
    PUSH32(c, 0x00b21223u); f_00b21050(c); /* call 0xb21050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    W8((uint32_t)(c->esp + 0x38u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esp + 0x38], 1 */
    if (c->zf) goto L_00b2123c; /* je 0xb2123c */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    PUSH32(c, 0x00b2123au); f_00b247d0(c); /* call 0xb247d0 */
    goto L_00b2123e; /* jmp 0xb2123e */
L_00b2123c:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00b2123e:;
    { uint32_t v_ = 0x15u; PUSH32(c, v_); } /* push 0x15 */
    { uint32_t v_ = 0xb30048u; PUSH32(c, v_); } /* push 0x10010048 */
    { uint32_t v_ = 0x838u; PUSH32(c, v_); } /* push 0x838 */
    W8((uint32_t)(c->esp + 0x44u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [esp + 0x44], bl */
    W32((uint32_t)(c->ebp + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x20], eax */
    PUSH32(c, 0x00b21256u); f_00b21050(c); /* call 0xb21050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    W8((uint32_t)(c->esp + 0x38u), (uint8_t)((uint8_t)0x2u)); /* mov byte ptr [esp + 0x38], 2 */
    if (c->zf) goto L_00b2126f; /* je 0xb2126f */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    PUSH32(c, 0x00b2126du); f_00b23d60(c); /* call 0xb23d60 */
    goto L_00b21271; /* jmp 0xb21271 */
L_00b2126f:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00b21271:;
    { uint32_t v_ = 0x16u; PUSH32(c, v_); } /* push 0x16 */
    { uint32_t v_ = 0xb30048u; PUSH32(c, v_); } /* push 0x10010048 */
    { uint32_t v_ = 0x4e60u; PUSH32(c, v_); } /* push 0x4e60 */
    W8((uint32_t)(c->esp + 0x44u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [esp + 0x44], bl */
    W32((uint32_t)(c->ebp + 0x24u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x24], eax */
    PUSH32(c, 0x00b21289u); f_00b21050(c); /* call 0xb21050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    W8((uint32_t)(c->esp + 0x38u), (uint8_t)((uint8_t)0x3u)); /* mov byte ptr [esp + 0x38], 3 */
    if (c->zf) goto L_00b212a5; /* je 0xb212a5 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    PUSH32(c, 0x00b212a0u); f_00b216a0(c); /* call 0xb216a0 */
    W32((uint32_t)(c->ebp + 0x28u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x28], eax */
    goto L_00b212a8; /* jmp 0xb212a8 */
L_00b212a5:;
    W32((uint32_t)(c->ebp + 0x28u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 0x28], ebx */
L_00b212a8:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov ecx, dword ptr [esp + 0x30] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)(c->ebp); /* mov eax, ebp */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
    c->esp += 4; return; /* ret  */
}

void f_00b212c0(CPU *c) { /* FUN_100012c0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00b212c8u); f_00b212e0(c); /* call 0xb212e0 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00b212d8; /* je 0xb212d8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b212d5u); f_00b21030(c); /* call 0xb21030 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00b212d8:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00b212e0(CPU *c) { /* FUN_100012e0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xb2dea8u; PUSH32(c, v_); } /* push 0x1000dea8 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 4], esi */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0xb2e130u)); /* mov dword ptr [esi], 0x1000e130 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov ecx, dword ptr [esi + 0x20] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x10], 0 */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00b21318; /* je 0xb21318 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t t_ = R32((uint32_t)(c->eax)); PUSH32(c, 0x00b21318u); call_indirect(c, t_); } /* call dword ptr [eax] */
L_00b21318:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov ecx, dword ptr [esi + 0x24] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00b21325; /* je 0xb21325 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t t_ = R32((uint32_t)(c->edx)); PUSH32(c, 0x00b21325u); call_indirect(c, t_); } /* call dword ptr [edx] */
L_00b21325:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x28u))); /* mov ecx, dword ptr [esi + 0x28] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00b21332; /* je 0xb21332 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t t_ = R32((uint32_t)(c->eax)); PUSH32(c, 0x00b21332u); call_indirect(c, t_); } /* call dword ptr [eax] */
L_00b21332:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x14u))); /* mov eax, dword ptr [esi + 0x14] */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0xb2e154u)); /* mov dword ptr [esi], 0x1000e154 */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb33398u))); /* mov ecx, dword ptr [0x10013398] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [esp + 0x14], 0xffffffff */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x00b2134fu); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_00b21360(CPU *c) { /* PTR_00b21360 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->eax = (uint32_t)(R32((uint32_t)(0xb333b4u))); /* mov eax, dword ptr [0x100133b4] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0x4du; PUSH32(c, v_); } /* push 0x4d */
    c->ebp = (uint32_t)((uint32_t)(c->ebx + 0x4u)); /* lea ebp, [ebx + 4] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->esi = (uint32_t)(c->ebp); /* mov esi, ebp */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    { uint32_t v_ = 0xb3007cu; PUSH32(c, v_); } /* push 0x1001007c */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xb0u)); PUSH32(c, 0x00b2138du); call_indirect(c, t_); } /* call dword ptr [edx + 0xb0] */
    c->eax = (uint32_t)(R32((uint32_t)(0xb333b4u))); /* mov eax, dword ptr [0x100133b4] */
    { uint32_t v_ = 0x4du; PUSH32(c, v_); } /* push 0x4d */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->esi = (uint32_t)(c->ebp); /* mov esi, ebp */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    { uint32_t v_ = 0xb30074u; PUSH32(c, v_); } /* push 0x10010074 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xb0u)); PUSH32(c, 0x00b213b1u); call_indirect(c, t_); } /* call dword ptr [edx + 0xb0] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x20u))); /* mov ecx, dword ptr [ebx + 0x20] */
    PUSH32(c, 0x00b213b9u); f_00b24a20(c); /* call 0xb24a20 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    PUSH32(c, 0x00b213c1u); f_00b23f30(c); /* call 0xb23f30 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x28u))); /* mov ecx, dword ptr [ebx + 0x28] */
    PUSH32(c, 0x00b213c9u); f_00b21810(c); /* call 0xb21810 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00b213d0(CPU *c) { /* PTR_00b213d0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0xcu)); PUSH32(c, 0x00b213deu); call_indirect(c, t_); } /* call dword ptr [eax + 0xc] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, c->edi, (uint32_t)0x12cddu); /* cmp edi, 0x12cdd */
    if (c->zf) goto L_00b21414; /* je 0xb21414 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ebx, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x20u))); /* mov ecx, dword ptr [ebx + 0x20] */
    PUSH32(c, 0x00b213f8u); f_00b24b70(c); /* call 0xb24b70 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b21414; /* jne 0xb21414 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b21406u); f_00b241b0(c); /* call 0xb241b0 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b21414; /* jne 0xb21414 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x28u))); /* mov ecx, dword ptr [ebx + 0x28] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b21414u); f_00b21a90(c); /* call 0xb21a90 */
L_00b21414:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00b21420(CPU *c) { /* PTR_00b21420 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edi, dword ptr [esp + 0xc] */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov ecx, dword ptr [esi + 0x20] */
    PUSH32(c, 0x00b21431u); f_00b24f50(c); /* call 0xb24f50 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov ecx, dword ptr [esi + 0x24] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b2143au); f_00b24300(c); /* call 0xb24300 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x28u))); /* mov ecx, dword ptr [esi + 0x28] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b21443u); f_00b21d10(c); /* call 0xb21d10 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00b21450(CPU *c) { /* PTR_00b21450 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edi, dword ptr [esp + 0xc] */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov ecx, dword ptr [esi + 0x20] */
    PUSH32(c, 0x00b21461u); f_00b24c00(c); /* call 0xb24c00 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov ecx, dword ptr [esi + 0x24] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b2146au); f_00b241e0(c); /* call 0xb241e0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x28u))); /* mov ecx, dword ptr [esi + 0x28] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b21473u); f_00b21b70(c); /* call 0xb21b70 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00b21480(CPU *c) { /* PTR_00b21480 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0xb30084u))); /* mov al, byte ptr [0x10010084] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    if (c->zf) goto L_00b21522; /* je 0xb21522 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = 0xb30084u; PUSH32(c, v_); } /* push 0x10010084 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x00b214a4u); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b214aau); f_00b2db10(c); /* call 0xb2db10 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete al */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00b21522; /* je 0xb21522 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x1cu))); /* mov edi, dword ptr [ebx + 0x1c] */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x10], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov eax, dword ptr [edi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->cf || c->zf)) goto L_00b21513; /* jbe 0xb21513 */
L_00b214cc:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x10u))); /* mov ecx, dword ptr [edi + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + c->esi * 4))); /* mov eax, dword ptr [ecx + esi*4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x00b214ddu); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0xb30084u; PUSH32(c, v_); } /* push 0x10010084 */
    PUSH32(c, 0x00b214e8u); f_00b2db10(c); /* call 0xb2db10 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b214f9; /* je 0xb214f9 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov eax, dword ptr [edi + 4] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if (c->cf) goto L_00b214cc; /* jb 0xb214cc */
    goto L_00b21513; /* jmp 0xb21513 */
L_00b214f9:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x10u))); /* mov ecx, dword ptr [edi + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + c->esi * 4))); /* mov edx, dword ptr [ecx + esi*4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0xcu))); /* mov eax, dword ptr [edx + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b21513; /* je 0xb21513 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2150cu); f_00b25805(c); /* call 0xb25805 */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00b21513:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x20u))); /* mov eax, dword ptr [ebx + 0x20] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->eax + 0x3500u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x3500], ecx */
L_00b21522:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
}

void f_00b21530(CPU *c) { /* FUN_10001530 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0xb2e154u)); /* mov dword ptr [eax], 0x1000e154 */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb33398u))); /* mov ecx, dword ptr [0x10013398] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x14u))); /* mov eax, dword ptr [eax + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x00b21547u); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    c->esp += 4; return; /* ret  */
}

void f_00b21550(CPU *c) { /* PTR_00b21550 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    c->esp += 4; return; /* ret  */
}

void f_00b21560(CPU *c) { /* PTR_00b21560 */
    PREEMPT_POLL(c);
    c->esp += 8; return; /* ret 4 */
}

void f_00b21570(CPU *c) { /* PTR_00b21570 */
    PREEMPT_POLL(c);
    c->esp += 16; return; /* ret 0xc */
}

void f_00b21580(CPU *c) { /* PTR_00b21580 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    c->esp += 8; return; /* ret 4 */
}

void f_00b21590(CPU *c) { /* PTR_00b21590 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 8; return; /* ret 4 */
}

void f_00b215a0(CPU *c) { /* FUN_100015a0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x14u))); /* mov edx, dword ptr [esi + 0x14] */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0xb2e154u)); /* mov dword ptr [esi], 0x1000e154 */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb33398u))); /* mov ecx, dword ptr [0x10013398] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x00b215b8u); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00b215c8; /* je 0xb215c8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b215c5u); f_00b21030(c); /* call 0xb21030 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00b215c8:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00b215d0(CPU *c) { /* PTR_00b215d0 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    c->esp += 4; return; /* ret  */
}

void f_00b215e0(CPU *c) { /* PTR_00b215e0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_00b215f0(CPU *c) { /* PTR_00b215f0 */
    PREEMPT_POLL(c);
    { uint32_t a_ = (uint32_t)(c->ecx + 0xcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ecx + 0xc] */
    c->esp += 4; return; /* ret  */
}

void f_00b21600(CPU *c) { /* PTR_00b21600 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov eax, dword ptr [ecx + 0xc] */
    c->esp += 4; return; /* ret  */
}

void f_00b21610(CPU *c) { /* PTR_00b21610 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx + 0xcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ecx + 0xc], 0 */
    c->esp += 4; return; /* ret  */
}

void f_00b21620(CPU *c) { /* PTR_00b21620 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x4u))); /* mov al, byte ptr [esp + 4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0xb2e110u)); /* mov dword ptr [esi], 0x1000e110 */
    if (c->zf) goto L_00b2163a; /* je 0xb2163a */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b21637u); f_00b21030(c); /* call 0xb21030 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00b2163a:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00b21640(CPU *c) { /* FUN_10001640 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00b21646u); f_00b258ac(c); /* call 0xb258ac */
    W32((uint32_t)(c->esp), (uint32_t)(c->eax)); /* mov dword ptr [esp], eax */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp))); /* fild dword ptr [esp] */
    ST(0) = FPRES(c, FDIV(c, ST(0), (double)RF32((uint32_t)(0xb2e198u)))); /* fdiv dword ptr [0x1000e198] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x8u))); /* fmul dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00b21660(CPU *c) { /* FUN_10001660 */
    PREEMPT_POLL(c);
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x4u))); /* fld dword ptr [esp + 4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb2e19cu))); /* fmul dword ptr [0x1000e19c] */
    WF32((uint32_t)(c->esp + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b21678u); f_00b21640(c); /* call 0xb21640 */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x8u))); /* fadd dword ptr [esp + 8] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->esp += 4; return; /* ret  */
}

void f_00b21680(CPU *c) { /* FUN_10001680 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2168au); f_00b21640(c); /* call 0xb21640 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x8u))); /* fld dword ptr [esp + 8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb2e19cu))); /* fmul dword ptr [0x1000e19c] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    ST(1) = FPRES(c, ST(1) - ST(0)); FPOP(c); /* fsubp st(1) */
    c->esp += 4; return; /* ret  */
}

void f_00b216a0(CPU *c) { /* FUN_100016a0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    { uint32_t v_ = 0xb21e10u; PUSH32(c, v_); } /* push 0x10001e10 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x14u)); /* lea eax, [esi + 0x14] */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0xc], ebx */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    { uint32_t v_ = 0xb21dd0u; PUSH32(c, v_); } /* push 0x10001dd0 */
    { uint32_t v_ = 0xc8u; PUSH32(c, v_); } /* push 0xc8 */
    { uint32_t v_ = 0x64u; PUSH32(c, v_); } /* push 0x64 */
    W32((uint32_t)(c->edx), (uint32_t)(c->ecx)); /* mov dword ptr [edx], ecx */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [edx + 4], ecx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 8], ebx */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0xc], ebx */
    W32((uint32_t)(c->eax + 0x10u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x10], ebx */
    W32((uint32_t)(c->eax + 0x14u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x14], ebx */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x2cu)); /* lea eax, [esi + 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b216dbu); f_00b258ce(c); /* call 0xb258ce */
    W8((uint32_t)(c->esi + 0x4e54u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [esi + 0x4e54], bl */
    W32((uint32_t)(c->esi + 0x4e58u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x4e58], ebx */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0xb2e1a4u)); /* mov dword ptr [esi], 0x1000e1a4 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00b21700(CPU *c) { /* FUN_10001700 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00b21708u); f_00b21720(c); /* call 0xb21720 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00b21718; /* je 0xb21718 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b21715u); f_00b21030(c); /* call 0xb21030 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00b21718:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00b21720(CPU *c) { /* FUN_10001720 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xb2ded9u; PUSH32(c, v_); } /* push 0x1000ded9 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 4], esi */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0xb2e1a4u)); /* mov dword ptr [esi], 0x1000e1a4 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x4e5cu))); /* mov edx, dword ptr [esi + 0x4e5c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x14], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x80u)); PUSH32(c, 0x00b2175du); call_indirect(c, t_); } /* call dword ptr [eax + 0x80] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov ecx, dword ptr [esi + 0xc] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00b2176a; /* je 0xb2176a */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t t_ = R32((uint32_t)(c->eax)); PUSH32(c, 0x00b2176au); call_indirect(c, t_); } /* call dword ptr [eax] */
L_00b2176a:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00b21777; /* je 0xb21777 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t t_ = R32((uint32_t)(c->edx)); PUSH32(c, 0x00b21777u); call_indirect(c, t_); } /* call dword ptr [edx] */
L_00b21777:;
    { uint32_t v_ = 0xb21e10u; PUSH32(c, v_); } /* push 0x10001e10 */
    { uint32_t v_ = 0xc8u; PUSH32(c, v_); } /* push 0xc8 */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x2cu)); /* add esi, 0x2c */
    { uint32_t v_ = 0x64u; PUSH32(c, v_); } /* push 0x64 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [esp + 0x20], 0xffffffff */
    PUSH32(c, 0x00b21794u); f_00b25950(c); /* call 0xb25950 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_00b217b0(CPU *c) { /* FUN_100017b0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0xb333b4u))); /* mov eax, dword ptr [0x100133b4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    { uint32_t v_ = 0xb3008cu; PUSH32(c, v_); } /* push 0x1001008c */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x58u)); PUSH32(c, 0x00b217c6u); call_indirect(c, t_); } /* call dword ptr [edx + 0x58] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00b2180c; /* je 0xb2180c */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t v_ = 0xc8u; PUSH32(c, v_); } /* push 0xc8 */
    { uint32_t v_ = 0xb300f0u; PUSH32(c, v_); } /* push 0x100100f0 */
    { uint32_t v_ = 0xb300d8u; PUSH32(c, v_); } /* push 0x100100d8 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x20u)); PUSH32(c, 0x00b217e2u); call_indirect(c, t_); } /* call dword ptr [eax + 0x20] */
    W32((uint32_t)(c->edi + 0x4e4cu), (uint32_t)(c->eax)); /* mov dword ptr [edi + 0x4e4c], eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    { uint32_t v_ = 0x42c80000u; PUSH32(c, v_); } /* push 0x42c80000 */
    { uint32_t v_ = 0xb300e4u; PUSH32(c, v_); } /* push 0x100100e4 */
    { uint32_t v_ = 0xb300d8u; PUSH32(c, v_); } /* push 0x100100d8 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x38u)); PUSH32(c, 0x00b217feu); call_indirect(c, t_); } /* call dword ptr [edx + 0x38] */
    WF32((uint32_t)(c->edi + 0x4e50u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + 0x4e50] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax)); PUSH32(c, 0x00b2180cu); call_indirect(c, t_); } /* call dword ptr [eax] */
L_00b2180c:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b21810(CPU *c) { /* FUN_10001810 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xb2df1du; PUSH32(c, v_); } /* push 0x1000df1d */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x260u)); /* sub esp, 0x260 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00b21835u); f_00b217b0(c); /* call 0xb217b0 */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb333b4u))); /* mov ecx, dword ptr [0x100133b4] */
    { uint32_t v_ = 0xb301c8u; PUSH32(c, v_); } /* push 0x100101c8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4cu)); PUSH32(c, 0x00b21845u); call_indirect(c, t_); } /* call dword ptr [eax + 0x4c] */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 4], eax */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (!c->zf) goto L_00b218da; /* jne 0xb218da */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb33398u))); /* mov ecx, dword ptr [0x10013398] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x18u)); PUSH32(c, 0x00b2185du); call_indirect(c, t_); } /* call dword ptr [edx + 0x18] */
    c->eax = (uint32_t)(R32((uint32_t)(0xb33398u))); /* mov eax, dword ptr [0x10013398] */
    { uint32_t v_ = 0xb301b0u; PUSH32(c, v_); } /* push 0x100101b0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00b2186du); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(0xb33398u))); /* mov eax, dword ptr [0x10013398] */
    { uint32_t v_ = 0x33u; PUSH32(c, v_); } /* push 0x33 */
    { uint32_t v_ = 0xb30180u; PUSH32(c, v_); } /* push 0x10010180 */
    { uint32_t v_ = 0xb30174u; PUSH32(c, v_); } /* push 0x10010174 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00b21884u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(0xb33398u))); /* mov eax, dword ptr [0x10013398] */
    { uint32_t v_ = 0xb3014cu; PUSH32(c, v_); } /* push 0x1001014c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00b21894u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    W32((uint32_t)(c->esp + 0x140u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x140], ebx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00b218a0:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0xb3014cu))); /* mov cl, byte ptr [eax + 0x1001014c] */
    W8((uint32_t)(c->esp + c->eax + 0x1cu), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esp + eax + 0x1c], cl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub8(c, ((uint8_t)c->ecx), ((uint8_t)c->ebx)); /* cmp cl, bl */
    if (!c->zf) goto L_00b218a0; /* jne 0xb218a0 */
    c->ecx = (uint32_t)((uint32_t)0x4au); /* mov ecx, 0x4a */
    c->esi = (uint32_t)((uint32_t)(c->esp + 0x1cu)); /* lea esi, [esp + 0x1c] */
    c->edi = (uint32_t)((uint32_t)(c->esp + 0x144u)); /* lea edi, [esp + 0x144] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x144u)); /* lea edx, [esp + 0x144] */
    { uint32_t v_ = 0xb2eae8u; PUSH32(c, v_); } /* push 0x1000eae8 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    W32((uint32_t)(c->esp + 0x27cu), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x27c], ebx */
    PUSH32(c, 0x00b218dau); f_00b25a89(c); /* call 0xb25a89 */
L_00b218da:;
    c->ecx = (uint32_t)(R32((uint32_t)(0xb333b4u))); /* mov ecx, dword ptr [0x100133b4] */
    { uint32_t v_ = 0xb30144u; PUSH32(c, v_); } /* push 0x10010144 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4cu)); PUSH32(c, 0x00b218eau); call_indirect(c, t_); } /* call dword ptr [eax + 0x4c] */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 8], eax */
    if (!c->zf) goto L_00b21981; /* jne 0xb21981 */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb33398u))); /* mov ecx, dword ptr [0x10013398] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x18u)); PUSH32(c, 0x00b21900u); call_indirect(c, t_); } /* call dword ptr [edx + 0x18] */
    c->eax = (uint32_t)(R32((uint32_t)(0xb33398u))); /* mov eax, dword ptr [0x10013398] */
    { uint32_t v_ = 0xb301b0u; PUSH32(c, v_); } /* push 0x100101b0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00b21910u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(0xb33398u))); /* mov eax, dword ptr [0x10013398] */
    { uint32_t v_ = 0x37u; PUSH32(c, v_); } /* push 0x37 */
    { uint32_t v_ = 0xb30180u; PUSH32(c, v_); } /* push 0x10010180 */
    { uint32_t v_ = 0xb30174u; PUSH32(c, v_); } /* push 0x10010174 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00b21927u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(0xb33398u))); /* mov eax, dword ptr [0x10013398] */
    { uint32_t v_ = 0xb30120u; PUSH32(c, v_); } /* push 0x10010120 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00b21937u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    W32((uint32_t)(c->esp + 0x140u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x140], ebx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00b21943:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0xb30120u))); /* mov cl, byte ptr [eax + 0x10010120] */
    W8((uint32_t)(c->esp + c->eax + 0x1cu), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esp + eax + 0x1c], cl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub8(c, ((uint8_t)c->ecx), ((uint8_t)c->ebx)); /* cmp cl, bl */
    if (!c->zf) goto L_00b21943; /* jne 0xb21943 */
    c->ecx = (uint32_t)((uint32_t)0x4au); /* mov ecx, 0x4a */
    c->esi = (uint32_t)((uint32_t)(c->esp + 0x1cu)); /* lea esi, [esp + 0x1c] */
    c->edi = (uint32_t)((uint32_t)(c->esp + 0x144u)); /* lea edi, [esp + 0x144] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x144u)); /* lea edx, [esp + 0x144] */
    { uint32_t v_ = 0xb2eae8u; PUSH32(c, v_); } /* push 0x1000eae8 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    W32((uint32_t)(c->esp + 0x27cu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [esp + 0x27c], 1 */
    PUSH32(c, 0x00b21981u); f_00b25a89(c); /* call 0xb25a89 */
L_00b21981:;
    c->ecx = (uint32_t)(R32((uint32_t)(0xb333b4u))); /* mov ecx, dword ptr [0x100133b4] */
    { uint32_t v_ = 0xb30118u; PUSH32(c, v_); } /* push 0x10010118 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0xc8u)); PUSH32(c, 0x00b21994u); call_indirect(c, t_); } /* call dword ptr [eax + 0xc8] */
    { uint32_t v_ = 0x3bu; PUSH32(c, v_); } /* push 0x3b */
    { uint32_t v_ = 0xb30180u; PUSH32(c, v_); } /* push 0x10010180 */
    { uint32_t v_ = 0x38u; PUSH32(c, v_); } /* push 0x38 */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xc], eax */
    PUSH32(c, 0x00b219a5u); f_00b21050(c); /* call 0xb21050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x18], eax */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    W32((uint32_t)(c->esp + 0x274u), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [esp + 0x274], 2 */
    if (c->zf) goto L_00b219da; /* je 0xb219da */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4e4cu))); /* mov ecx, dword ptr [esi + 0x4e4c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov edx, dword ptr [esi + 4] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x6u; PUSH32(c, v_); } /* push 6 */
    { uint32_t v_ = 0xcu; PUSH32(c, v_); } /* push 0xc */
    { uint32_t v_ = 0x14u; PUSH32(c, v_); } /* push 0x14 */
    { uint32_t v_ = 0x102u; PUSH32(c, v_); } /* push 0x102 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    PUSH32(c, 0x00b219d8u); f_00b24530(c); /* call 0xb24530 */
    goto L_00b219dc; /* jmp 0xb219dc */
L_00b219da:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00b219dc:;
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x10], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4e4cu))); /* mov eax, dword ptr [esi + 0x4e4c] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    W32((uint32_t)(c->esp + 0x274u), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [esp + 0x274], 0xffffffff */
    if ((c->zf || c->sf != c->of)) goto L_00b21a5f; /* jle 0xb21a5f */
    c->ebx = (uint32_t)((uint32_t)(c->esi + 0x2cu)); /* lea ebx, [esi + 0x2c] */
L_00b219f9:;
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0xc], 0 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x10], 0 */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x14], 0 */
    PUSH32(c, 0x00b21a16u); f_00b258ac(c); /* call 0xb258ac */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x80000003u))); /* and eax, 0x80000003 */
    if (!c->sf) goto L_00b21a22; /* jns 0xb21a22 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xfffffffcu))); /* or eax, 0xfffffffc */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
L_00b21a22:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b21a28u); f_00b258ac(c); /* call 0xb258ac */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x80000003u))); /* and eax, 0x80000003 */
    if (!c->sf) goto L_00b21a34; /* jns 0xb21a34 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xfffffffcu))); /* or eax, 0xfffffffc */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
L_00b21a34:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b21a3du); f_00b24660(c); /* call 0xb24660 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4e50u))); /* mov eax, dword ptr [esi + 0x4e50] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x18u)); /* lea ecx, [esp + 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    PUSH32(c, 0x00b21a51u); f_00b21e20(c); /* call 0xb21e20 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4e4cu))); /* mov eax, dword ptr [esi + 0x4e4c] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x64u)); /* add ebx, 0x64 */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if ((c->sf != c->of)) goto L_00b219f9; /* jl 0xb219f9 */
L_00b21a5f:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    { uint32_t v_ = 0xb3010cu; PUSH32(c, v_); } /* push 0x1001010c */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x78u)); PUSH32(c, 0x00b21a6cu); call_indirect(c, t_); } /* call dword ptr [edx + 0x78] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x26cu))); /* mov ecx, dword ptr [esp + 0x26c] */
    W32((uint32_t)(c->esi + 0x4e5cu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x4e5c], eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x26cu)); /* add esp, 0x26c */
    c->esp += 4; return; /* ret  */
}

void f_00b21a90(CPU *c) { /* FUN_10001a90 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x12d34u)); /* sub eax, 0x12d34 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    if (c->zf) goto L_00b21b50; /* je 0xb21b50 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00b21b42; /* je 0xb21b42 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (!c->zf) goto L_00b21b57; /* jne 0xb21b57 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0xb333c8u))); /* mov cl, byte ptr [0x100133c8] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->ecx))); /* test al, cl */
    if (!c->zf) goto L_00b21af2; /* jne 0xb21af2 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(((uint8_t)c->ecx)); /* mov dl, cl */
    { uint32_t v_ = 0xb21b60u; PUSH32(c, v_); } /* push 0x10001b60 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->edx) | ((uint8_t)c->eax)))); /* or dl, al */
    W32((uint32_t)(0xb333bcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [0x100133bc], 0 */
    W8((uint32_t)(0xb333c8u), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [0x100133c8], dl */
    W32((uint32_t)(0xb333c0u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [0x100133c0], 0 */
    W32((uint32_t)(0xb333c4u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [0x100133c4], 0 */
    PUSH32(c, 0x00b21aefu); f_00b257c4(c); /* call 0xb257c4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00b21af2:;
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x00b21afdu); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    WF32((uint32_t)(0xb333bcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [0x100133bc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00b21b0au); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    WF32((uint32_t)(0xb333c4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [0x100133c4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x4e4cu))); /* mov eax, dword ptr [ebx + 0x4e4c] */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_00b21b57; /* jle 0xb21b57 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)((uint32_t)(c->ebx + 0x2cu)); /* lea edi, [ebx + 0x2c] */
L_00b21b20:;
    { uint32_t v_ = 0xb333bcu; PUSH32(c, v_); } /* push 0x100133bc */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    PUSH32(c, 0x00b21b2cu); f_00b22490(c); /* call 0xb22490 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x4e4cu))); /* mov eax, dword ptr [ebx + 0x4e4c] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x64u)); /* add edi, 0x64 */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if ((c->sf != c->of)) goto L_00b21b20; /* jl 0xb21b20 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 12; return; /* ret 8 */
L_00b21b42:;
    W8((uint32_t)(c->ebx + 0x4e54u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [ebx + 0x4e54], 0 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 12; return; /* ret 8 */
L_00b21b50:;
    W8((uint32_t)(c->ebx + 0x4e54u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ebx + 0x4e54], 1 */
L_00b21b57:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 12; return; /* ret 8 */
}

void f_00b21b60(CPU *c) { /* PTR_00b21b60 */
    PREEMPT_POLL(c);
    c->esp += 4; return; /* ret  */
}

void f_00b21b70(CPU *c) { /* FUN_10001b70 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x34u)); /* sub esp, 0x34 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x4e54u))); /* mov al, byte ptr [esi + 0x4e54] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00b21cfa; /* je 0xb21cfa */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0xcu)); /* lea edx, [esp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x3cu)); /* lea edx, [esp + 0x3c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x34u)); /* lea edx, [esp + 0x34] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x70u)); PUSH32(c, 0x00b21b9eu); call_indirect(c, t_); } /* call dword ptr [eax + 0x70] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov eax, dword ptr [esp + 0x2c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov ecx, dword ptr [esp + 0x30] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov edx, dword ptr [esp + 0x34] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x48u))); /* mov ebp, dword ptr [esp + 0x48] */
    W32((uint32_t)(0xb33458u), (uint32_t)(c->eax)); /* mov dword ptr [0x10013458], eax */
    W32((uint32_t)(0xb3345cu), (uint32_t)(c->ecx)); /* mov dword ptr [0x1001345c], ecx */
    W32((uint32_t)(0xb33460u), (uint32_t)(c->edx)); /* mov dword ptr [0x10013460], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x4e58u))); /* mov edx, dword ptr [esi + 0x4e58] */
    c->edx = (uint32_t)(add32(c, c->edx, c->ebp)); /* add edx, ebp */
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    W32((uint32_t)(c->esi + 0x4e58u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x4e58], edx */
    (void)sub32(c, c->eax, (uint32_t)0xfau); /* cmp eax, 0xfa */
    if ((c->zf || c->sf != c->of)) goto L_00b21caf; /* jle 0xb21caf */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b21bf7; /* jne 0xb21bf7 */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb333b4u))); /* mov ecx, dword ptr [0x100133b4] */
    { uint32_t v_ = 0xb30118u; PUSH32(c, v_); } /* push 0x10010118 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0xc8u)); PUSH32(c, 0x00b21bf4u); call_indirect(c, t_); } /* call dword ptr [eax + 0xc8] */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xc], eax */
L_00b21bf7:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4e4cu))); /* mov eax, dword ptr [esi + 0x4e4c] */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_00b21caf; /* jle 0xb21caf */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x7cu)); /* lea edi, [esi + 0x7c] */
L_00b21c0a:;
    c->eax = (uint32_t)((uint32_t)(c->edi + 0xffffffb4u)); /* lea eax, [edi - 0x4c] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    FPUSH(c, (double)RF32((uint32_t)(0xb2e1a0u))); /* fld dword ptr [0x1000e1a0] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x28], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov edx, dword ptr [ecx + 4] */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x2c], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov ecx, dword ptr [ecx + 8] */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x1c], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov edx, dword ptr [eax + 8] */
    W32((uint32_t)(c->esp + 0x30u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x30], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(0xb2e1a0u))); /* mov eax, dword ptr [0x1000e1a0] */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x2c], eax */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x1cu)); /* lea eax, [esp + 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x24], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ecx, dword ptr [esi + 8] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x2cu)); /* lea eax, [esp + 0x2c] */
    ST(0) = -ST(0); /* fchs  */
    WF32((uint32_t)(c->esp + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x24] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x2c], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x20u)); PUSH32(c, 0x00b21c66u); call_indirect(c, t_); } /* call dword ptr [edx + 0x20] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xb2e1acu))); /* fcom dword ptr [0x1000e1ac] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x41u)); /* test ah, 0x41 */
    if (PF(c)) goto L_00b21c89; /* jp 0xb21c89 */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(0xb2e1acu)) - ST(0)); /* fsubr dword ptr [0x1000e1ac] */
    ST(0) = FPRES(c, ST(0) + ST(0)); /* fadd st(0), st(0) */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0xb2e1acu))); /* fsub dword ptr [0x1000e1ac] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb2e1a0u))); /* fmul dword ptr [0x1000e1a0] */
    goto L_00b21c93; /* jmp 0xb21c93 */
L_00b21c89:;
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, (double)RF32((uint32_t)(0xb2e1a0u))); /* fld dword ptr [0x1000e1a0] */
    ST(0) = -ST(0); /* fchs  */
L_00b21c93:;
    WF32((uint32_t)(c->edi + 0xfffffffcu), (float)ST(0)); /* fst dword ptr [edi - 4] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0xb2e1a8u))); /* fadd dword ptr [0x1000e1a8] */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x64u)); /* add edi, 0x64 */
    WF32((uint32_t)(c->edi + 0xffffff9cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi - 0x64] */
    (void)sub32(c, c->ebx, R32((uint32_t)(c->esi + 0x4e4cu))); /* cmp ebx, dword ptr [esi + 0x4e4c] */
    if ((c->sf != c->of)) goto L_00b21c0a; /* jl 0xb21c0a */
L_00b21caf:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    PUSH32(c, 0x00b21cb7u); f_00b24690(c); /* call 0xb24690 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4e4cu))); /* mov eax, dword ptr [esi + 0x4e4c] */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_00b21cef; /* jle 0xb21cef */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x2cu)); /* lea edi, [esi + 0x2c] */
L_00b21cc6:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov ecx, dword ptr [esi + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov edx, dword ptr [esi + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    PUSH32(c, 0x00b21cd6u); f_00b22050(c); /* call 0xb22050 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b21ce1u); f_00b224f0(c); /* call 0xb224f0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4e4cu))); /* mov eax, dword ptr [esi + 0x4e4c] */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x64u)); /* add edi, 0x64 */
    (void)sub32(c, c->ebx, c->eax); /* cmp ebx, eax */
    if ((c->sf != c->of)) goto L_00b21cc6; /* jl 0xb21cc6 */
L_00b21cef:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    PUSH32(c, 0x00b21cf7u); f_00b246d0(c); /* call 0xb246d0 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
L_00b21cfa:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x34u)); /* add esp, 0x34 */
    c->esp += 8; return; /* ret 4 */
}

void f_00b21d10(CPU *c) { /* FUN_10001d10 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x44u)); /* sub esp, 0x44 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x4e54u))); /* mov al, byte ptr [esi + 0x4e54] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00b21d94; /* je 0xb21d94 */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x8u)); /* lea eax, [esp + 8] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
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
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0xcu)); /* lea eax, [esp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x100u; PUSH32(c, v_); } /* push 0x100 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x58u)); PUSH32(c, 0x00b21d75u); call_indirect(c, t_); } /* call dword ptr [edx + 0x58] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4e5cu))); /* mov eax, dword ptr [esi + 0x4e5c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x7cu)); PUSH32(c, 0x00b21d86u); call_indirect(c, t_); } /* call dword ptr [edx + 0x7c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    { uint32_t v_ = 0xb301d4u; PUSH32(c, v_); } /* push 0x100101d4 */
    PUSH32(c, 0x00b21d93u); f_00b24770(c); /* call 0xb24770 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
L_00b21d94:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x44u)); /* add esp, 0x44 */
    c->esp += 8; return; /* ret 4 */
}

void f_00b21da0(CPU *c) { /* PTR_00b21da0 */
    PREEMPT_POLL(c);
    c->esp += 4; return; /* ret  */
}

void f_00b21db0(CPU *c) { /* PTR_00b21db0 */
    PREEMPT_POLL(c);
    goto L_00b21dc0; /* jmp 0xb21dc0 */
L_00b21dc0:;
    c->esp += 4; return; /* ret  */
}

void f_00b21dd0(CPU *c) { /* PTR_00b21dd0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    W32((uint32_t)(c->eax + 0x4cu), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x4c], ecx */
    W32((uint32_t)(c->eax + 0x50u), (uint32_t)((uint32_t)0x40800000u)); /* mov dword ptr [eax + 0x50], 0x40800000 */
    W8((uint32_t)(c->eax + 0x54u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [eax + 0x54], 1 */
    W32((uint32_t)(c->eax + 0x58u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x58], ecx */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0xb2e1b0u)); /* mov dword ptr [eax], 0x1000e1b0 */
    c->esp += 4; return; /* ret  */
}

void f_00b21df0(CPU *c) { /* FUN_10001df0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00b21df8u); f_00b21e10(c); /* call 0xb21e10 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00b21e08; /* je 0xb21e08 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b21e05u); f_00b21030(c); /* call 0xb21030 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00b21e08:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00b21e10(CPU *c) { /* FUN_10001e10 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx), (uint32_t)((uint32_t)0xb2e1b0u)); /* mov dword ptr [ecx], 0x1000e1b0 */
    c->esp += 4; return; /* ret  */
}

void f_00b21e20(CPU *c) { /* FUN_10001e20 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov edi, dword ptr [esp + 0x20] */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->esi + 0x44u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x44], eax */
    PUSH32(c, 0x00b21e39u); f_00b21680(c); /* call 0xb21680 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov ebx, dword ptr [esp + 0x20] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ebx))); /* fadd dword ptr [ebx] */
    WF32((uint32_t)(c->esi + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 4] */
    PUSH32(c, 0x00b21e48u); f_00b21680(c); /* call 0xb21680 */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ebx + 0x4u))); /* fadd dword ptr [ebx + 4] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    WF32((uint32_t)(c->esi + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 8] */
    PUSH32(c, 0x00b21e54u); f_00b21680(c); /* call 0xb21680 */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ebx + 0x8u))); /* fadd dword ptr [ebx + 8] */
    { uint32_t v_ = 0x3f800000u; PUSH32(c, v_); } /* push 0x3f800000 */
    WF32((uint32_t)(c->esi + 0xcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0xc] */
    PUSH32(c, 0x00b21e64u); f_00b21680(c); /* call 0xb21680 */
    WF32((uint32_t)(c->esp + 0x34u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x34] */
    { uint32_t v_ = 0x3f800000u; PUSH32(c, v_); } /* push 0x3f800000 */
    PUSH32(c, 0x00b21e72u); f_00b21680(c); /* call 0xb21680 */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x38u))); /* fld dword ptr [esp + 0x38] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x38u))); /* fmul dword ptr [esp + 0x38] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FCOM(c, ST(0), RF64((uint32_t)(0xb2e1c0u))); /* fcom qword ptr [0x1000e1c0] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x44u)); /* test ah, 0x44 */
    if (PF(c)) goto L_00b21eae; /* jp 0xb21eae */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0xc], 0 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x10], 0 */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x14], 0 */
    goto L_00b21ed6; /* jmp 0xb21ed6 */
L_00b21eae:;
    ST(0) = FPRES(c, sqrt(ST(0))); /* fsqrt  */
    ST(0) = FPRES(c, FDIV(c, RF64((uint32_t)(0xb2e1b8u)), ST(0))); /* fdivr qword ptr [0x1000e1b8] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF32((uint32_t)(c->esp + 0xcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xc] */
    FPUSH(c, RF64((uint32_t)(0xb2e1c0u))); /* fld qword ptr [0x1000e1c0] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x24u))); /* fld dword ptr [esp + 0x24] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
L_00b21ed6:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x10u)); /* lea ecx, [esi + 0x10] */
    { uint32_t v_ = 0x3f800000u; PUSH32(c, v_); } /* push 0x3f800000 */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov edx, dword ptr [esp + 0x18] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 4], eax */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 8], edx */
    PUSH32(c, 0x00b21ef7u); f_00b21680(c); /* call 0xb21680 */
    WF32((uint32_t)(c->esp + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x24] */
    { uint32_t v_ = 0x3f800000u; PUSH32(c, v_); } /* push 0x3f800000 */
    PUSH32(c, 0x00b21f05u); f_00b21680(c); /* call 0xb21680 */
    WF32((uint32_t)(c->esp + 0x2cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x2c] */
    { uint32_t v_ = 0x3f800000u; PUSH32(c, v_); } /* push 0x3f800000 */
    PUSH32(c, 0x00b21f13u); f_00b21680(c); /* call 0xb21680 */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x30u))); /* fld dword ptr [esp + 0x30] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x30u))); /* fmul dword ptr [esp + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x20u))); /* fld dword ptr [esp + 0x20] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x20u))); /* fmul dword ptr [esp + 0x20] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FCOM(c, ST(0), RF64((uint32_t)(0xb2e1c0u))); /* fcom qword ptr [0x1000e1c0] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x44u)); /* test ah, 0x44 */
    if (PF(c)) goto L_00b21f59; /* jp 0xb21f59 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0xc], 0 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x10], 0 */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x14], 0 */
    goto L_00b21f7f; /* jmp 0xb21f7f */
L_00b21f59:;
    ST(0) = FPRES(c, sqrt(ST(0))); /* fsqrt  */
    ST(0) = FPRES(c, FDIV(c, RF64((uint32_t)(0xb2e1b8u)), ST(0))); /* fdivr qword ptr [0x1000e1b8] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF32((uint32_t)(c->esp + 0xcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xc] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x24u))); /* fld dword ptr [esp + 0x24] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x20u))); /* fld dword ptr [esp + 0x20] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
L_00b21f7f:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x28u)); /* lea eax, [esi + 0x28] */
    { uint32_t v_ = 0x43960000u; PUSH32(c, v_); } /* push 0x43960000 */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov ecx, dword ptr [esp + 0x18] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 4], edx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    PUSH32(c, 0x00b21fa0u); f_00b21640(c); /* call 0xb21640 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    PUSH32(c, 0x00b21fa8u); f_00b25ac4(c); /* call 0xb25ac4 */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x28u))); /* fild dword ptr [esp + 0x28] */
    W32((uint32_t)(c->esi + 0x34u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x34], eax */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb2e1b4u))); /* fmul dword ptr [0x1000e1b4] */
    WF32((uint32_t)(c->esi + 0x5cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x5c] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x2cu))); /* fild dword ptr [esp + 0x2c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb2e1b4u))); /* fmul dword ptr [0x1000e1b4] */
    WF32((uint32_t)(c->esi + 0x60u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x60] */
    PUSH32(c, 0x00b21fcau); f_00b258ac(c); /* call 0xb258ac */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    { uint32_t v_ = 0x469c4000u; PUSH32(c, v_); } /* push 0x469c4000 */
    if (c->zf) goto L_00b2200f; /* je 0xb2200f */
    PUSH32(c, 0x00b21fd8u); f_00b21660(c); /* call 0xb21660 */
    PUSH32(c, 0x00b21fddu); f_00b25ac4(c); /* call 0xb25ac4 */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x28], eax */
    W32((uint32_t)(c->esi + 0x38u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x38], eax */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x28u))); /* fild dword ptr [esp + 0x28] */
    WF32((uint32_t)(c->esp), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp] */
    PUSH32(c, 0x00b21ff0u); f_00b21640(c); /* call 0xb21640 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    PUSH32(c, 0x00b21ff8u); f_00b25ac4(c); /* call 0xb25ac4 */
    W32((uint32_t)(c->esi + 0x40u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 0x40], 0 */
    W8((uint32_t)(c->esi + 0x48u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esi + 0x48], 1 */
    W32((uint32_t)(c->esi + 0x3cu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x3c], eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 24; return; /* ret 0x14 */
L_00b2200f:;
    PUSH32(c, 0x00b22014u); f_00b21640(c); /* call 0xb21640 */
    PUSH32(c, 0x00b22019u); f_00b25ac4(c); /* call 0xb25ac4 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x4cu))); /* mov edx, dword ptr [esi + 0x4c] */
    { uint32_t v_ = 0x469c4000u; PUSH32(c, v_); } /* push 0x469c4000 */
    W32((uint32_t)(c->esi + 0x40u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x40], eax */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 8], edx */
    PUSH32(c, 0x00b2202cu); f_00b21660(c); /* call 0xb21660 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    PUSH32(c, 0x00b22034u); f_00b25ac4(c); /* call 0xb25ac4 */
    W32((uint32_t)(c->esi + 0x38u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x38], eax */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W8((uint32_t)(c->esi + 0x48u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [esi + 0x48], al */
    W32((uint32_t)(c->esi + 0x3cu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x3c], eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 24; return; /* ret 0x14 */
}

void f_00b22050(CPU *c) { /* FUN_10002050 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x20u)); /* sub esp, 0x20 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov ecx, dword ptr [esp + 0x28] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x48u))); /* mov al, byte ptr [esi + 0x48] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00b22095; /* jne 0xb22095 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x40u))); /* mov eax, dword ptr [esi + 0x40] */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    W32((uint32_t)(c->esi + 0x40u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x40], eax */
    if (!c->sf) goto L_00b22095; /* jns 0xb22095 */
    { uint32_t v_ = 0x469c4000u; PUSH32(c, v_); } /* push 0x469c4000 */
    PUSH32(c, 0x00b22076u); f_00b21660(c); /* call 0xb21660 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    PUSH32(c, 0x00b2207eu); f_00b25ac4(c); /* call 0xb25ac4 */
    W32((uint32_t)(c->esi + 0x38u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x38], eax */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W32((uint32_t)(c->esi + 0x3cu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x3c], eax */
    W32((uint32_t)(c->esi + 0x40u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x40], eax */
    W8((uint32_t)(c->esi + 0x48u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esi + 0x48], 1 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    c->esp += 16; return; /* ret 0xc */
L_00b22095:;
    c->edi = (uint32_t)(R32((uint32_t)(c->esi + 0x3cu))); /* mov edi, dword ptr [esi + 0x3c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x38u))); /* mov edx, dword ptr [esi + 0x38] */
    c->edi = (uint32_t)(add32(c, c->edi, c->ecx)); /* add edi, ecx */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    W32((uint32_t)(c->esi + 0x3cu), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0x3c], edi */
    (void)sub32(c, c->eax, c->edx); /* cmp eax, edx */
    if ((c->zf || c->sf != c->of)) goto L_00b220fc; /* jle 0xb220fc */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x8u))); /* fld dword ptr [esi + 8] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esi + 0x4cu))); /* fsub dword ptr [esi + 0x4c] */
    ST(0) = fabs(ST(0)); /* fabs  */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xb2e1e0u))); FPOP(c); /* fcomp dword ptr [0x1000e1e0] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00b220e2; /* jp 0xb220e2 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4cu))); /* mov eax, dword ptr [esi + 0x4c] */
    { uint32_t v_ = 0x469c4000u; PUSH32(c, v_); } /* push 0x469c4000 */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 8], eax */
    PUSH32(c, 0x00b220cbu); f_00b21640(c); /* call 0xb21640 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    PUSH32(c, 0x00b220d3u); f_00b25ac4(c); /* call 0xb25ac4 */
    W32((uint32_t)(c->esi + 0x40u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x40], eax */
    W8((uint32_t)(c->esi + 0x48u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esi + 0x48], 0 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    c->esp += 16; return; /* ret 0xc */
L_00b220e2:;
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x8u))); /* fld dword ptr [esi + 8] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->esi + 0x4cu))); FPOP(c); /* fcomp dword ptr [esi + 0x4c] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00b220fc; /* jp 0xb220fc */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x4cu))); /* mov edx, dword ptr [esi + 0x4c] */
    W32((uint32_t)(c->esi + 0x3cu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 0x3c], 0 */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 8], edx */
L_00b220fc:;
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x2cu))); /* fild dword ptr [esp + 0x2c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x34u))); /* mov eax, dword ptr [esi + 0x34] */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb2e1dcu))); /* fmul dword ptr [0x1000e1dc] */
    W32((uint32_t)(c->esi + 0x34u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x34], eax */
    WF32((uint32_t)(c->esp + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 8] */
    if (!c->sf) goto L_00b221c0; /* jns 0xb221c0 */
    { uint32_t v_ = 0x3f800000u; PUSH32(c, v_); } /* push 0x3f800000 */
    PUSH32(c, 0x00b22122u); f_00b21680(c); /* call 0xb21680 */
    WF32((uint32_t)(c->esp + 0x30u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x30] */
    { uint32_t v_ = 0x3f800000u; PUSH32(c, v_); } /* push 0x3f800000 */
    PUSH32(c, 0x00b22130u); f_00b21680(c); /* call 0xb21680 */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x34u))); /* fld dword ptr [esp + 0x34] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x34u))); /* fmul dword ptr [esp + 0x34] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FCOM(c, ST(0), RF64((uint32_t)(0xb2e1c0u))); /* fcom qword ptr [0x1000e1c0] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x44u)); /* test ah, 0x44 */
    if (PF(c)) goto L_00b2216c; /* jp 0xb2216c */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x10], 0 */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x14], 0 */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x18], 0 */
    goto L_00b22194; /* jmp 0xb22194 */
L_00b2216c:;
    ST(0) = FPRES(c, sqrt(ST(0))); /* fsqrt  */
    ST(0) = FPRES(c, FDIV(c, RF64((uint32_t)(0xb2e1b8u)), ST(0))); /* fdivr qword ptr [0x1000e1b8] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
    FPUSH(c, RF64((uint32_t)(0xb2e1c0u))); /* fld qword ptr [0x1000e1c0] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x2cu))); /* fld dword ptr [esp + 0x2c] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
L_00b22194:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edx, dword ptr [esp + 0x14] */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x28u)); /* lea eax, [esi + 0x28] */
    { uint32_t v_ = 0x43960000u; PUSH32(c, v_); } /* push 0x43960000 */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov ecx, dword ptr [esp + 0x1c] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 4], edx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    PUSH32(c, 0x00b221b5u); f_00b21640(c); /* call 0xb21640 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    PUSH32(c, 0x00b221bdu); f_00b25ac4(c); /* call 0xb25ac4 */
    W32((uint32_t)(c->esi + 0x34u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x34], eax */
L_00b221c0:;
    { uint32_t v_ = 0x41200000u; PUSH32(c, v_); } /* push 0x41200000 */
    PUSH32(c, 0x00b221cau); f_00b21640(c); /* call 0xb21640 */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xcu))); /* fmul dword ptr [esp + 0xc] */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x10u)); /* lea edi, [esi + 0x10] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x28u))); /* fmul dword ptr [esi + 0x28] */
    { double v_ = ST(1); FPUSH(c, v_); } /* fld st(1) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x2cu))); /* fmul dword ptr [esi + 0x2c] */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x30u))); /* fmul dword ptr [esi + 0x30] */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->edi))); /* fadd dword ptr [edi] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->edi + 0x4u))); /* fadd dword ptr [edi + 4] */
    WF32((uint32_t)(c->esp + 0x20u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x20] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->edi + 0x8u))); /* fadd dword ptr [edi + 8] */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x20u))); /* fld dword ptr [esp + 0x20] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x20u))); /* fmul dword ptr [esp + 0x20] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    { double v_ = ST(2); FPUSH(c, v_); } /* fld st(2) */
    ST(0) = FPRES(c, ST(0) * ST(3)); /* fmul st(3) */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FCOM(c, ST(0), RF64((uint32_t)(0xb2e1c0u))); /* fcom qword ptr [0x1000e1c0] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x44u)); /* test ah, 0x44 */
    if (PF(c)) goto L_00b22240; /* jp 0xb22240 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x10], 0 */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x14], 0 */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x18], 0 */
    goto L_00b22262; /* jmp 0xb22262 */
L_00b22240:;
    ST(0) = FPRES(c, sqrt(ST(0))); /* fsqrt  */
    ST(0) = FPRES(c, FDIV(c, RF64((uint32_t)(0xb2e1b8u)), ST(0))); /* fdivr qword ptr [0x1000e1b8] */
    { double t_ = ST(0); ST(0) = ST(2); ST(2) = t_; } /* fxch st(2) */
    ST(0) = FPRES(c, ST(0) * ST(2)); /* fmul st(2) */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x20u))); /* fld dword ptr [esp + 0x20] */
    ST(0) = FPRES(c, ST(0) * ST(2)); /* fmul st(2) */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
L_00b22262:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ecx, dword ptr [esp + 0x14] */
    c->edx = (uint32_t)(c->edi); /* mov edx, edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esi + 0x38u))); /* mov ebx, dword ptr [esi + 0x38] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esi + 0x3cu))); /* mov ebp, dword ptr [esi + 0x3c] */
    W32((uint32_t)(c->edx), (uint32_t)(c->eax)); /* mov dword ptr [edx], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov eax, dword ptr [esp + 0x20] */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [edx + 4], ecx */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [edx + 8], eax */
    c->eax = (uint32_t)(c->ebp); /* mov eax, ebp */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)c->ebx; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00b22283u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv ebx */
    W32((uint32_t)(c->esp + 0x34u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x34], eax */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x34u))); /* fild dword ptr [esp + 0x34] */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(0xb2e1acu)) - ST(0)); /* fsubr dword ptr [0x1000e1ac] */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); /* fst dword ptr [esp + 0x14] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xb2e1d8u))); FPOP(c); /* fcomp dword ptr [0x1000e1d8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00b222ac; /* jp 0xb222ac */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0x3ecccccdu)); /* mov dword ptr [esp + 0x14], 0x3ecccccd */
L_00b222ac:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb2e1d4u))); /* fmul dword ptr [0x1000e1d4] */
    WF32((uint32_t)(c->esp + 0x34u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x34] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x10u))); /* fmul dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb2e1d0u))); /* fmul dword ptr [0x1000e1d0] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x58u))); /* fadd dword ptr [esi + 0x58] */
    FPUSH(c, RF64((uint32_t)(0xb2e1c8u))); /* fld qword ptr [0x1000e1c8] */
    PUSH32(c, 0x00b222d6u); f_00b25afa(c); /* call 0xb25afa */
    WF32((uint32_t)(c->esi + 0x58u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x58] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x34u))); /* fld dword ptr [esp + 0x34] */
    ST(0) = fabs(ST(0)); /* fabs  */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
    (void)sub32(c, c->ebp, c->ebx); /* cmp ebp, ebx */
    if ((c->sf != c->of)) goto L_00b22302; /* jl 0xb22302 */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x8u))); /* fld dword ptr [esi + 8] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esi + 0x4cu))); /* fsub dword ptr [esi + 0x4c] */
    ST(0) = fabs(ST(0)); /* fabs  */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0xb2e1e0u))); /* fadd dword ptr [0x1000e1e0] */
    FCOM(c, ST(0), ST(1)); FPOP(c); FPOP(c); /* fcompp  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00b2237e; /* jp 0xb2237e */
L_00b22302:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x34u))); /* fld dword ptr [esp + 0x34] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edi))); /* fmul dword ptr [edi] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x34u))); /* fld dword ptr [esp + 0x34] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x18u))); /* fmul dword ptr [esi + 0x18] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x4u))); /* fadd dword ptr [esi + 4] */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x4u)); /* lea eax, [esi + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x38u))); /* mov ecx, dword ptr [esp + 0x38] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ebx = (uint32_t)((uint32_t)(c->esp + 0x28u)); /* lea ebx, [esp + 0x28] */
    WF32((uint32_t)(c->esp + 0x28u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x28] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x4u))); /* fld dword ptr [eax + 4] */
    WF32((uint32_t)(c->esp + 0x2cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x2c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->eax + 0x8u))); /* fadd dword ptr [eax + 8] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4cu))); /* mov eax, dword ptr [esp + 0x4c] */
    WF32((uint32_t)(c->esp + 0x3cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x3c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x20u)); PUSH32(c, 0x00b22341u); call_indirect(c, t_); } /* call dword ptr [edx + 0x20] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xb2e1acu))); FPOP(c); /* fcomp dword ptr [0x1000e1ac] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x41u)); /* test ah, 0x41 */
    if (PF(c)) goto L_00b2237e; /* jp 0xb2237e */
    FPUSH(c, (double)RF32((uint32_t)(c->edi))); /* fld dword ptr [edi] */
    ST(0) = -ST(0); /* fchs  */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
    FPUSH(c, (double)RF32((uint32_t)(c->edi + 0x4u))); /* fld dword ptr [edi + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov edx, dword ptr [esp + 0x18] */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    ST(0) = -ST(0); /* fchs  */
    WF32((uint32_t)(c->esp + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1c] */
    FPUSH(c, (double)RF32((uint32_t)(c->edi + 0x8u))); /* fld dword ptr [edi + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov eax, dword ptr [esp + 0x1c] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    ST(0) = -ST(0); /* fchs  */
    WF32((uint32_t)(c->esp + 0x20u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x20] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov edx, dword ptr [esp + 0x20] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 4], eax */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 8], edx */
L_00b2237e:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x34u))); /* fld dword ptr [esp + 0x34] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edi))); /* fmul dword ptr [edi] */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x4u))); /* fadd dword ptr [esi + 4] */
    WF32((uint32_t)(c->esi + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x2cu))); /* fld dword ptr [esp + 0x2c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x18u))); /* fmul dword ptr [esi + 0x18] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0xcu))); /* fadd dword ptr [esi + 0xc] */
    WF32((uint32_t)(c->esi + 0xcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0xc] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xcu))); /* fld dword ptr [esp + 0xc] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xb2e19cu))); FPOP(c); /* fcomp dword ptr [0x1000e19c] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00b223c7; /* jne 0xb223c7 */
    PUSH32(c, 0x00b223b1u); f_00b258ac(c); /* call 0xb258ac */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    { int32_t d_ = (int32_t)c->ecx; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00b223b7u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv ecx */
    (void)sub32(c, c->edx, (uint32_t)0x1u); /* cmp edx, 1 */
    if (!c->zf) goto L_00b223e2; /* jne 0xb223e2 */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x8u))); /* fld dword ptr [esi + 8] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x8u))); /* fsub dword ptr [esp + 8] */
    goto L_00b223e9; /* jmp 0xb223e9 */
L_00b223c7:;
    PUSH32(c, 0x00b223ccu); f_00b258ac(c); /* call 0xb258ac */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    c->ecx = (uint32_t)((uint32_t)0xau); /* mov ecx, 0xa */
    { int32_t d_ = (int32_t)c->ecx; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00b223d2u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv ecx */
    (void)sub32(c, c->edx, (uint32_t)0x1u); /* cmp edx, 1 */
    if (c->zf) goto L_00b223e2; /* je 0xb223e2 */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x8u))); /* fld dword ptr [esi + 8] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x8u))); /* fsub dword ptr [esp + 8] */
    goto L_00b223e9; /* jmp 0xb223e9 */
L_00b223e2:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x8u))); /* fld dword ptr [esp + 8] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x8u))); /* fadd dword ptr [esi + 8] */
L_00b223e9:;
    WF32((uint32_t)(c->esi + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x8u))); /* fld dword ptr [esi + 8] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->esi + 0x50u))); FPOP(c); /* fcomp dword ptr [esi + 0x50] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00b22401; /* jne 0xb22401 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x38u))); /* mov edx, dword ptr [esi + 0x38] */
    W32((uint32_t)(c->esi + 0x3cu), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x3c], edx */
L_00b22401:;
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x8u))); /* fld dword ptr [esi + 8] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->esi + 0x4cu))); FPOP(c); /* fcomp dword ptr [esi + 0x4c] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00b22415; /* jp 0xb22415 */
    W32((uint32_t)(c->esi + 0x3cu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 0x3c], 0 */
L_00b22415:;
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0xcu))); /* fld dword ptr [esi + 0xc] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0xb33460u))); /* fsub dword ptr [0x10013460] */
    ST(0) = fabs(ST(0)); /* fabs  */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x4u))); /* fld dword ptr [esi + 4] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0xb33458u))); /* fsub dword ptr [0x10013458] */
    ST(0) = fabs(ST(0)); /* fabs  */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xb301e0u))); FPOP(c); /* fcomp dword ptr [0x100101e0] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00b2247c; /* jne 0xb2247c */
    { uint32_t v_ = 0x41200000u; PUSH32(c, v_); } /* push 0x41200000 */
    PUSH32(c, 0x00b2244au); f_00b21680(c); /* call 0xb21680 */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0xb33458u))); /* fadd dword ptr [0x10013458] */
    { uint32_t v_ = 0x3f800000u; PUSH32(c, v_); } /* push 0x3f800000 */
    WF32((uint32_t)(c->esi + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 4] */
    PUSH32(c, 0x00b2245du); f_00b21660(c); /* call 0xb21660 */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0xb3345cu))); /* fadd dword ptr [0x1001345c] */
    { uint32_t v_ = 0x41200000u; PUSH32(c, v_); } /* push 0x41200000 */
    WF32((uint32_t)(c->esi + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 8] */
    PUSH32(c, 0x00b22470u); f_00b21680(c); /* call 0xb21680 */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0xb33460u))); /* fadd dword ptr [0x10013460] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    WF32((uint32_t)(c->esi + 0xcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0xc] */
L_00b2247c:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    c->esp += 16; return; /* ret 0xc */
}

void f_00b22490(CPU *c) { /* FUN_10002490 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x48u))); /* mov al, byte ptr [esi + 0x48] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00b224e9; /* jne 0xb224e9 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x8u))); /* fld dword ptr [eax + 8] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esi + 0xcu))); /* fsub dword ptr [esi + 0xc] */
    ST(0) = fabs(ST(0)); /* fabs  */
    FPUSH(c, (double)RF32((uint32_t)(c->eax))); /* fld dword ptr [eax] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esi + 0x4u))); /* fsub dword ptr [esi + 4] */
    ST(0) = fabs(ST(0)); /* fabs  */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xb2e1e4u))); FPOP(c); /* fcomp dword ptr [0x1000e1e4] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (c->zf) goto L_00b224e9; /* je 0xb224e9 */
    { uint32_t v_ = 0x469c4000u; PUSH32(c, v_); } /* push 0x469c4000 */
    PUSH32(c, 0x00b224ccu); f_00b21660(c); /* call 0xb21660 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    PUSH32(c, 0x00b224d4u); f_00b25ac4(c); /* call 0xb25ac4 */
    W32((uint32_t)(c->esi + 0x38u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x38], eax */
    W32((uint32_t)(c->esi + 0x3cu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 0x3c], 0 */
    W32((uint32_t)(c->esi + 0x40u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 0x40], 0 */
    W8((uint32_t)(c->esi + 0x48u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esi + 0x48], 1 */
L_00b224e9:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00b224f0(CPU *c) { /* FUN_100024f0 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x228u)); /* sub esp, 0x228 */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x8u)); /* lea eax, [esp + 8] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x4u)); /* lea edx, [esp + 4] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0xcu)); /* lea ecx, [esp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x44u))); /* mov eax, dword ptr [esi + 0x44] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x240u))); /* mov ecx, dword ptr [esp + 0x240] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2251au); f_00b24700(c); /* call 0xb24700 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x54u))); /* mov al, byte ptr [esi + 0x54] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00b22631; /* je 0xb22631 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    W8((uint32_t)(c->esi + 0x54u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esi + 0x54], 0 */
    W16((uint32_t)(c->ecx), (uint16_t)(((uint16_t)c->eax))); /* mov word ptr [ecx], ax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    c->edx = (uint32_t)((uint32_t)(c->eax + 0x1u)); /* lea edx, [eax + 1] */
    W16((uint32_t)(c->ecx + 0x2u), (uint16_t)(((uint16_t)c->edx))); /* mov word ptr [ecx + 2], dx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x3u)); /* lea ecx, [eax + 3] */
    W16((uint32_t)(c->edx + 0x4u), (uint16_t)(((uint16_t)c->ecx))); /* mov word ptr [edx + 4], cx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    W16((uint32_t)(c->edx + 0x6u), (uint16_t)(((uint16_t)c->eax))); /* mov word ptr [edx + 6], ax */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    W16((uint32_t)(c->edx + 0x8u), (uint16_t)(((uint16_t)c->ecx))); /* mov word ptr [edx + 8], cx */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edi, dword ptr [esp + 0x10] */
    c->edx = (uint32_t)((uint32_t)(c->eax + 0x2u)); /* lea edx, [eax + 2] */
    W16((uint32_t)(c->edi + 0xau), (uint16_t)(((uint16_t)c->edx))); /* mov word ptr [edi + 0xa], dx */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edi, dword ptr [esp + 0x10] */
    W16((uint32_t)(c->edi + 0xcu), (uint16_t)(((uint16_t)c->edx))); /* mov word ptr [edi + 0xc], dx */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edi, dword ptr [esp + 0x10] */
    W16((uint32_t)(c->edi + 0xeu), (uint16_t)(((uint16_t)c->ecx))); /* mov word ptr [edi + 0xe], cx */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edi, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x5u)); /* lea ecx, [eax + 5] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x4u)); /* add eax, 4 */
    W16((uint32_t)(c->edi + 0x10u), (uint16_t)(((uint16_t)c->ecx))); /* mov word ptr [edi + 0x10], cx */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edi, dword ptr [esp + 0x10] */
    W16((uint32_t)(c->edi + 0x12u), (uint16_t)(((uint16_t)c->edx))); /* mov word ptr [edi + 0x12], dx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    W16((uint32_t)(c->edx + 0x14u), (uint16_t)(((uint16_t)c->ecx))); /* mov word ptr [edx + 0x14], cx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    W16((uint32_t)(c->ecx + 0x16u), (uint16_t)(((uint16_t)c->eax))); /* mov word ptr [ecx + 0x16], ax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x5cu))); /* mov edx, dword ptr [esi + 0x5c] */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->edx)); /* mov dword ptr [eax + 0xc], edx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x60u))); /* fld dword ptr [esi + 0x60] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0xb2e1b4u))); /* fadd dword ptr [0x1000e1b4] */
    WF32((uint32_t)(c->ecx + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ecx + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x5cu))); /* mov edx, dword ptr [esi + 0x5c] */
    W32((uint32_t)(c->eax + 0x20u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 0x20], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x60u))); /* mov ecx, dword ptr [esi + 0x60] */
    W32((uint32_t)(c->edx + 0x24u), (uint32_t)(c->ecx)); /* mov dword ptr [edx + 0x24], ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x5cu))); /* fld dword ptr [esi + 0x5c] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0xb2e1b4u))); /* fadd dword ptr [0x1000e1b4] */
    WF32((uint32_t)(c->eax + 0x34u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 0x34] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x60u))); /* fld dword ptr [esi + 0x60] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0xb2e1b4u))); /* fadd dword ptr [0x1000e1b4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    WF32((uint32_t)(c->ecx + 0x38u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ecx + 0x38] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x5cu))); /* fld dword ptr [esi + 0x5c] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0xb2e1b4u))); /* fadd dword ptr [0x1000e1b4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    WF32((uint32_t)(c->edx + 0x48u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edx + 0x48] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x60u))); /* mov eax, dword ptr [esi + 0x60] */
    W32((uint32_t)(c->ecx + 0x4cu), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 0x4c], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x5cu))); /* mov edx, dword ptr [esi + 0x5c] */
    W32((uint32_t)(c->eax + 0x5cu), (uint32_t)(c->edx)); /* mov dword ptr [eax + 0x5c], edx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x60u))); /* fld dword ptr [esi + 0x60] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0xb2e1b4u))); /* fadd dword ptr [0x1000e1b4] */
    WF32((uint32_t)(c->ecx + 0x60u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ecx + 0x60] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x5cu))); /* mov edx, dword ptr [esi + 0x5c] */
    W32((uint32_t)(c->eax + 0x70u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 0x70], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x60u))); /* mov ecx, dword ptr [esi + 0x60] */
    W32((uint32_t)(c->edx + 0x74u), (uint32_t)(c->ecx)); /* mov dword ptr [edx + 0x74], ecx */
L_00b22631:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0xb333e8u))); /* mov cl, byte ptr [0x100133e8] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->ecx))); /* test al, cl */
    if (!c->zf) goto L_00b22672; /* jne 0xb22672 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(((uint8_t)c->ecx)); /* mov dl, cl */
    { uint32_t v_ = 0xb233b0u; PUSH32(c, v_); } /* push 0x100033b0 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->edx) | ((uint8_t)c->eax)))); /* or dl, al */
    W32((uint32_t)(0xb333dcu), (uint32_t)((uint32_t)0xbd4ccccdu)); /* mov dword ptr [0x100133dc], 0xbd4ccccd */
    W8((uint32_t)(0xb333e8u), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [0x100133e8], dl */
    W32((uint32_t)(0xb333e0u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [0x100133e0], 0 */
    W32((uint32_t)(0xb333e4u), (uint32_t)((uint32_t)0xbd4ccccdu)); /* mov dword ptr [0x100133e4], 0xbd4ccccd */
    PUSH32(c, 0x00b2266fu); f_00b257c4(c); /* call 0xb257c4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00b22672:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0xb333e8u))); /* mov cl, byte ptr [0x100133e8] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x2u); /* mov al, 2 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->ecx))); /* test al, cl */
    if (!c->zf) goto L_00b226b3; /* jne 0xb226b3 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(((uint8_t)c->ecx)); /* mov dl, cl */
    { uint32_t v_ = 0xb233a0u; PUSH32(c, v_); } /* push 0x100033a0 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->edx) | ((uint8_t)c->eax)))); /* or dl, al */
    W32((uint32_t)(0xb333f8u), (uint32_t)((uint32_t)0xbd4ccccdu)); /* mov dword ptr [0x100133f8], 0xbd4ccccd */
    W8((uint32_t)(0xb333e8u), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [0x100133e8], dl */
    W32((uint32_t)(0xb333fcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [0x100133fc], 0 */
    W32((uint32_t)(0xb33400u), (uint32_t)((uint32_t)0x3d4ccccdu)); /* mov dword ptr [0x10013400], 0x3d4ccccd */
    PUSH32(c, 0x00b226b0u); f_00b257c4(c); /* call 0xb257c4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00b226b3:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0xb333e8u))); /* mov cl, byte ptr [0x100133e8] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x4u); /* mov al, 4 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->ecx))); /* test al, cl */
    if (!c->zf) goto L_00b226f4; /* jne 0xb226f4 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(((uint8_t)c->ecx)); /* mov dl, cl */
    { uint32_t v_ = 0xb23390u; PUSH32(c, v_); } /* push 0x10003390 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->edx) | ((uint8_t)c->eax)))); /* or dl, al */
    W32((uint32_t)(0xb33464u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [0x10013464], 0 */
    W8((uint32_t)(0xb333e8u), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [0x100133e8], dl */
    W32((uint32_t)(0xb33468u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [0x10013468], 0 */
    W32((uint32_t)(0xb3346cu), (uint32_t)((uint32_t)0xbd4ccccdu)); /* mov dword ptr [0x1001346c], 0xbd4ccccd */
    PUSH32(c, 0x00b226f1u); f_00b257c4(c); /* call 0xb257c4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00b226f4:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0xb333e8u))); /* mov cl, byte ptr [0x100133e8] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x8u); /* mov al, 8 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->ecx))); /* test al, cl */
    if (!c->zf) goto L_00b22735; /* jne 0xb22735 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(((uint8_t)c->ecx)); /* mov dl, cl */
    { uint32_t v_ = 0xb23380u; PUSH32(c, v_); } /* push 0x10003380 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->edx) | ((uint8_t)c->eax)))); /* or dl, al */
    W32((uint32_t)(0xb333ecu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [0x100133ec], 0 */
    W8((uint32_t)(0xb333e8u), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [0x100133e8], dl */
    W32((uint32_t)(0xb333f0u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [0x100133f0], 0 */
    W32((uint32_t)(0xb333f4u), (uint32_t)((uint32_t)0x3d4ccccdu)); /* mov dword ptr [0x100133f4], 0x3d4ccccd */
    PUSH32(c, 0x00b22732u); f_00b257c4(c); /* call 0xb257c4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00b22735:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0xb333e8u))); /* mov cl, byte ptr [0x100133e8] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x10u); /* mov al, 0x10 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->ecx))); /* test al, cl */
    if (!c->zf) goto L_00b22776; /* jne 0xb22776 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(((uint8_t)c->ecx)); /* mov dl, cl */
    { uint32_t v_ = 0xb23370u; PUSH32(c, v_); } /* push 0x10003370 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->edx) | ((uint8_t)c->eax)))); /* or dl, al */
    W32((uint32_t)(0xb333d0u), (uint32_t)((uint32_t)0x3d4ccccdu)); /* mov dword ptr [0x100133d0], 0x3d4ccccd */
    W8((uint32_t)(0xb333e8u), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [0x100133e8], dl */
    W32((uint32_t)(0xb333d4u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [0x100133d4], 0 */
    W32((uint32_t)(0xb333d8u), (uint32_t)((uint32_t)0xbd4ccccdu)); /* mov dword ptr [0x100133d8], 0xbd4ccccd */
    PUSH32(c, 0x00b22773u); f_00b257c4(c); /* call 0xb257c4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00b22776:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0xb333e8u))); /* mov cl, byte ptr [0x100133e8] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x20u); /* mov al, 0x20 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->ecx))); /* test al, cl */
    if (!c->zf) goto L_00b227b7; /* jne 0xb227b7 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(((uint8_t)c->ecx)); /* mov dl, cl */
    { uint32_t v_ = 0xb23360u; PUSH32(c, v_); } /* push 0x10003360 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->edx) | ((uint8_t)c->eax)))); /* or dl, al */
    W32((uint32_t)(0xb33404u), (uint32_t)((uint32_t)0x3d4ccccdu)); /* mov dword ptr [0x10013404], 0x3d4ccccd */
    W8((uint32_t)(0xb333e8u), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [0x100133e8], dl */
    W32((uint32_t)(0xb33408u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [0x10013408], 0 */
    W32((uint32_t)(0xb3340cu), (uint32_t)((uint32_t)0x3d4ccccdu)); /* mov dword ptr [0x1001340c], 0x3d4ccccd */
    PUSH32(c, 0x00b227b4u); f_00b257c4(c); /* call 0xb257c4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00b227b7:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0xb333e8u))); /* mov cl, byte ptr [0x100133e8] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x40u); /* mov al, 0x40 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->ecx))); /* test al, cl */
    if (!c->zf) goto L_00b228aa; /* jne 0xb228aa */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(((uint8_t)c->ecx)); /* mov dl, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb333e0u))); /* mov ecx, dword ptr [0x100133e0] */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->edx) | ((uint8_t)c->eax)))); /* or dl, al */
    c->eax = (uint32_t)(R32((uint32_t)(0xb333dcu))); /* mov eax, dword ptr [0x100133dc] */
    W8((uint32_t)(0xb333e8u), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [0x100133e8], dl */
    c->edx = (uint32_t)(R32((uint32_t)(0xb333e4u))); /* mov edx, dword ptr [0x100133e4] */
    W32((uint32_t)(0xb33410u), (uint32_t)(c->eax)); /* mov dword ptr [0x10013410], eax */
    c->eax = (uint32_t)(R32((uint32_t)(0xb333f8u))); /* mov eax, dword ptr [0x100133f8] */
    W32((uint32_t)(0xb33414u), (uint32_t)(c->ecx)); /* mov dword ptr [0x10013414], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb333fcu))); /* mov ecx, dword ptr [0x100133fc] */
    W32((uint32_t)(0xb33418u), (uint32_t)(c->edx)); /* mov dword ptr [0x10013418], edx */
    c->edx = (uint32_t)(R32((uint32_t)(0xb33400u))); /* mov edx, dword ptr [0x10013400] */
    W32((uint32_t)(0xb3341cu), (uint32_t)(c->eax)); /* mov dword ptr [0x1001341c], eax */
    c->eax = (uint32_t)(R32((uint32_t)(0xb33464u))); /* mov eax, dword ptr [0x10013464] */
    W32((uint32_t)(0xb33420u), (uint32_t)(c->ecx)); /* mov dword ptr [0x10013420], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb33468u))); /* mov ecx, dword ptr [0x10013468] */
    W32((uint32_t)(0xb33424u), (uint32_t)(c->edx)); /* mov dword ptr [0x10013424], edx */
    c->edx = (uint32_t)(R32((uint32_t)(0xb3346cu))); /* mov edx, dword ptr [0x1001346c] */
    W32((uint32_t)(0xb33428u), (uint32_t)(c->eax)); /* mov dword ptr [0x10013428], eax */
    c->eax = (uint32_t)(R32((uint32_t)(0xb333ecu))); /* mov eax, dword ptr [0x100133ec] */
    W32((uint32_t)(0xb3342cu), (uint32_t)(c->ecx)); /* mov dword ptr [0x1001342c], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb333f0u))); /* mov ecx, dword ptr [0x100133f0] */
    W32((uint32_t)(0xb33430u), (uint32_t)(c->edx)); /* mov dword ptr [0x10013430], edx */
    c->edx = (uint32_t)(R32((uint32_t)(0xb333f4u))); /* mov edx, dword ptr [0x100133f4] */
    W32((uint32_t)(0xb33434u), (uint32_t)(c->eax)); /* mov dword ptr [0x10013434], eax */
    c->eax = (uint32_t)(R32((uint32_t)(0xb333d0u))); /* mov eax, dword ptr [0x100133d0] */
    W32((uint32_t)(0xb33438u), (uint32_t)(c->ecx)); /* mov dword ptr [0x10013438], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb333d4u))); /* mov ecx, dword ptr [0x100133d4] */
    W32((uint32_t)(0xb3343cu), (uint32_t)(c->edx)); /* mov dword ptr [0x1001343c], edx */
    c->edx = (uint32_t)(R32((uint32_t)(0xb333d8u))); /* mov edx, dword ptr [0x100133d8] */
    W32((uint32_t)(0xb33440u), (uint32_t)(c->eax)); /* mov dword ptr [0x10013440], eax */
    c->eax = (uint32_t)(R32((uint32_t)(0xb33404u))); /* mov eax, dword ptr [0x10013404] */
    W32((uint32_t)(0xb33444u), (uint32_t)(c->ecx)); /* mov dword ptr [0x10013444], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb33408u))); /* mov ecx, dword ptr [0x10013408] */
    W32((uint32_t)(0xb33448u), (uint32_t)(c->edx)); /* mov dword ptr [0x10013448], edx */
    c->edx = (uint32_t)(R32((uint32_t)(0xb3340cu))); /* mov edx, dword ptr [0x1001340c] */
    { uint32_t v_ = 0xb23350u; PUSH32(c, v_); } /* push 0x10003350 */
    W32((uint32_t)(0xb3344cu), (uint32_t)(c->eax)); /* mov dword ptr [0x1001344c], eax */
    W32((uint32_t)(0xb33450u), (uint32_t)(c->ecx)); /* mov dword ptr [0x10013450], ecx */
    W32((uint32_t)(0xb33454u), (uint32_t)(c->edx)); /* mov dword ptr [0x10013454], edx */
    PUSH32(c, 0x00b228a7u); f_00b257c4(c); /* call 0xb257c4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00b228aa:;
    c->eax = (uint32_t)((uint32_t)(c->esp + 0xb0u)); /* lea eax, [esp + 0xb0] */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x2c], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov eax, dword ptr [esp + 0x2c] */
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
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x130u)); /* lea ecx, [esp + 0x130] */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x2c], ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov eax, dword ptr [esp + 0x2c] */
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
    c->edx = (uint32_t)((uint32_t)(c->esp + 0xf0u)); /* lea edx, [esp + 0xf0] */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x2c], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov eax, dword ptr [esp + 0x2c] */
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
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x70u)); /* lea eax, [esp + 0x70] */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x2c], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov eax, dword ptr [esp + 0x2c] */
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
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov ecx, dword ptr [esi + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov edx, dword ptr [esi + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x18], ecx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0xb0u)); /* lea ecx, [esp + 0xb0] */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x1c], edx */
    W32((uint32_t)(c->esp + 0x230u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x230], eax */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x2c], ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov eax, dword ptr [esp + 0x2c] */
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
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x230u))); /* mov edx, dword ptr [esp + 0x230] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov eax, dword ptr [esp + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov ecx, dword ptr [esp + 0x18] */
    W32((uint32_t)(c->esp + 0xe0u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0xe0], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x58u))); /* mov edx, dword ptr [esi + 0x58] */
    W32((uint32_t)(c->esp + 0xe4u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0xe4], eax */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x130u)); /* lea eax, [esp + 0x130] */
    W32((uint32_t)(c->esp + 0xe8u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0xe8], ecx */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x2c], edx */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x18], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
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
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x2cu))); /* fld dword ptr [esp + 0x2c] */
    ST(0) = FTRIG(c, ST(0), cos); /* fcos  */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0xf0u)); /* lea ecx, [esp + 0xf0] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x18], ecx */
    WF32((uint32_t)(c->esp + 0x130u), (float)ST(0)); /* fst dword ptr [esp + 0x130] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x2cu))); /* fld dword ptr [esp + 0x2c] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = -ST(0); /* fchs  */
    WF32((uint32_t)(c->esp + 0x140u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x140] */
    WF32((uint32_t)(c->esp + 0x134u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x134] */
    WF32((uint32_t)(c->esp + 0x144u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x144] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x58u))); /* fld dword ptr [esi + 0x58] */
    ST(0) = -ST(0); /* fchs  */
    WF32((uint32_t)(c->esp + 0x2cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x2c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
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
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x2cu))); /* fld dword ptr [esp + 0x2c] */
    ST(0) = FTRIG(c, ST(0), cos); /* fcos  */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x10u)); /* lea eax, [esi + 0x10] */
    WF32((uint32_t)(c->esp + 0xf0u), (float)ST(0)); /* fst dword ptr [esp + 0xf0] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x2cu))); /* fld dword ptr [esp + 0x2c] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = -ST(0); /* fchs  */
    WF32((uint32_t)(c->esp + 0x100u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x100] */
    WF32((uint32_t)(c->esp + 0xf4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xf4] */
    WF32((uint32_t)(c->esp + 0x104u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x104] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x4u))); /* fld dword ptr [eax + 4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb2e1e8u))); /* fmul dword ptr [0x1000e1e8] */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->eax + 0x8u))); /* fsub dword ptr [eax + 8] */
    WF32((uint32_t)(c->esp + 0x20u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x20] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x8u))); /* fld dword ptr [eax + 8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb2e1e8u))); /* fmul dword ptr [0x1000e1e8] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax))); /* fld dword ptr [eax] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb2e1e8u))); /* fmul dword ptr [0x1000e1e8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov edx, dword ptr [esp + 0x20] */
    W32((uint32_t)(c->esp + 0x70u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x70], edx */
    ST(1) = FPRES(c, ST(1) - ST(0)); FPOP(c); /* fsubp st(1) */
    WF32((uint32_t)(c->esp + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x24] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax))); /* fld dword ptr [eax] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov ecx, dword ptr [esp + 0x24] */
    ST(0) = FPRES(c, ST(0) - ST(1)); /* fsub st(1) */
    W32((uint32_t)(c->esp + 0x74u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x74], ecx */
    WF32((uint32_t)(c->esp + 0x28u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x28] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov edx, dword ptr [esp + 0x28] */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x20], 0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov ecx, dword ptr [esp + 0x20] */
    W32((uint32_t)(c->esp + 0x78u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x78], edx */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [esp + 0x24], 0x3f800000 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov edx, dword ptr [esp + 0x24] */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x28], 0 */
    W32((uint32_t)(c->esp + 0x80u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x80], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov ecx, dword ptr [esp + 0x28] */
    W32((uint32_t)(c->esp + 0x84u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x84], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    W32((uint32_t)(c->esp + 0x88u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x88], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    W32((uint32_t)(c->esp + 0x90u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x90], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov edx, dword ptr [eax + 8] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x1b0u)); /* lea eax, [esp + 0x1b0] */
    W32((uint32_t)(c->esp + 0x94u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x94], ecx */
    W32((uint32_t)(c->esp + 0x98u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x98], edx */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x18], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
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
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x70u)); /* lea ecx, [esp + 0x70] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0xf0u)); /* lea edx, [esp + 0xf0] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x1b8u)); /* lea ecx, [esp + 0x1b8] */
    PUSH32(c, 0x00b22c30u); f_00b234c0(c); /* call 0xb234c0 */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x1b0u)); /* lea eax, [esp + 0x1b0] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x1f0u)); /* lea ecx, [esp + 0x1f0] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x18], eax */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x1c], ecx */
    c->df = 0; /* cld  */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov edi, dword ptr [esp + 0x1c] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov esi, dword ptr [esp + 0x18] */
    c->ecx = (uint32_t)((uint32_t)0x10u); /* mov ecx, 0x10 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x170u)); /* lea edx, [esp + 0x170] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x18], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
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
    c->eax = (uint32_t)((uint32_t)(c->esp + 0xb0u)); /* lea eax, [esp + 0xb0] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x1f0u)); /* lea ecx, [esp + 0x1f0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x178u)); /* lea ecx, [esp + 0x178] */
    PUSH32(c, 0x00b22cb7u); f_00b234c0(c); /* call 0xb234c0 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x170u)); /* lea edx, [esp + 0x170] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x30u)); /* lea eax, [esp + 0x30] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x18], edx */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x1c], eax */
    c->df = 0; /* cld  */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov edi, dword ptr [esp + 0x1c] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov esi, dword ptr [esp + 0x18] */
    c->ecx = (uint32_t)((uint32_t)0x10u); /* mov ecx, 0x10 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x30u))); /* fld dword ptr [esp + 0x30] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb333dcu))); /* fmul dword ptr [0x100133dc] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x50u))); /* fld dword ptr [esp + 0x50] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb333e4u))); /* fmul dword ptr [0x100133e4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x40u))); /* fld dword ptr [esp + 0x40] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb333e0u))); /* fmul dword ptr [0x100133e0] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x60u))); /* fadd dword ptr [esp + 0x60] */
    WF32((uint32_t)(c->esp + 0x20u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x20] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x34u))); /* fld dword ptr [esp + 0x34] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb333dcu))); /* fmul dword ptr [0x100133dc] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x54u))); /* fld dword ptr [esp + 0x54] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb333e4u))); /* fmul dword ptr [0x100133e4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov edx, dword ptr [esp + 0x20] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x44u))); /* fld dword ptr [esp + 0x44] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb333e0u))); /* fmul dword ptr [0x100133e0] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x64u))); /* fadd dword ptr [esp + 0x64] */
    WF32((uint32_t)(c->esp + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x24] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x38u))); /* fld dword ptr [esp + 0x38] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb333dcu))); /* fmul dword ptr [0x100133dc] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x58u))); /* fld dword ptr [esp + 0x58] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb333e4u))); /* fmul dword ptr [0x100133e4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov eax, dword ptr [esp + 0x24] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x48u))); /* fld dword ptr [esp + 0x48] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb333e0u))); /* fmul dword ptr [0x100133e0] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x68u))); /* fadd dword ptr [esp + 0x68] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 4], eax */
    WF32((uint32_t)(c->esp + 0x28u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x28] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov edx, dword ptr [esp + 0x28] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x1b0u)); /* lea eax, [esp + 0x1b0] */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 8], edx */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x18], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
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
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x70u)); /* lea ecx, [esp + 0x70] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0xf0u)); /* lea edx, [esp + 0xf0] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x1b8u)); /* lea ecx, [esp + 0x1b8] */
    PUSH32(c, 0x00b22dceu); f_00b234c0(c); /* call 0xb234c0 */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x1b0u)); /* lea eax, [esp + 0x1b0] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x1f0u)); /* lea ecx, [esp + 0x1f0] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x18], eax */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x1c], ecx */
    c->df = 0; /* cld  */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov edi, dword ptr [esp + 0x1c] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov esi, dword ptr [esp + 0x18] */
    c->ecx = (uint32_t)((uint32_t)0x10u); /* mov ecx, 0x10 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x170u)); /* lea edx, [esp + 0x170] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x18], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
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
    c->eax = (uint32_t)((uint32_t)(c->esp + 0xb0u)); /* lea eax, [esp + 0xb0] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x1f0u)); /* lea ecx, [esp + 0x1f0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x178u)); /* lea ecx, [esp + 0x178] */
    PUSH32(c, 0x00b22e55u); f_00b234c0(c); /* call 0xb234c0 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x170u)); /* lea edx, [esp + 0x170] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x30u)); /* lea eax, [esp + 0x30] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x18], edx */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x1c], eax */
    c->df = 0; /* cld  */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov edi, dword ptr [esp + 0x1c] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov esi, dword ptr [esp + 0x18] */
    c->ecx = (uint32_t)((uint32_t)0x10u); /* mov ecx, 0x10 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x30u))); /* fld dword ptr [esp + 0x30] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb333f8u))); /* fmul dword ptr [0x100133f8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x50u))); /* fld dword ptr [esp + 0x50] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb33400u))); /* fmul dword ptr [0x10013400] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x14u)); /* add ecx, 0x14 */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x40u))); /* fld dword ptr [esp + 0x40] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb333fcu))); /* fmul dword ptr [0x100133fc] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x60u))); /* fadd dword ptr [esp + 0x60] */
    WF32((uint32_t)(c->esp + 0x20u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x20] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x34u))); /* fld dword ptr [esp + 0x34] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb333f8u))); /* fmul dword ptr [0x100133f8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x54u))); /* fld dword ptr [esp + 0x54] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb33400u))); /* fmul dword ptr [0x10013400] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov edx, dword ptr [esp + 0x20] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x44u))); /* fld dword ptr [esp + 0x44] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb333fcu))); /* fmul dword ptr [0x100133fc] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x64u))); /* fadd dword ptr [esp + 0x64] */
    WF32((uint32_t)(c->esp + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x24] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x38u))); /* fld dword ptr [esp + 0x38] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb333f8u))); /* fmul dword ptr [0x100133f8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x58u))); /* fld dword ptr [esp + 0x58] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb33400u))); /* fmul dword ptr [0x10013400] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov eax, dword ptr [esp + 0x24] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x48u))); /* fld dword ptr [esp + 0x48] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb333fcu))); /* fmul dword ptr [0x100133fc] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x68u))); /* fadd dword ptr [esp + 0x68] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x170u)); /* lea eax, [esp + 0x170] */
    WF32((uint32_t)(c->esp + 0x28u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x28] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov edx, dword ptr [esp + 0x28] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x18], eax */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 8], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
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
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0xb0u)); /* lea ecx, [esp + 0xb0] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x70u)); /* lea edx, [esp + 0x70] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x178u)); /* lea ecx, [esp + 0x178] */
    PUSH32(c, 0x00b22f6fu); f_00b234c0(c); /* call 0xb234c0 */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x170u)); /* lea eax, [esp + 0x170] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x30u)); /* lea ecx, [esp + 0x30] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x18], eax */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x1c], ecx */
    c->df = 0; /* cld  */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov edi, dword ptr [esp + 0x1c] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov esi, dword ptr [esp + 0x18] */
    c->ecx = (uint32_t)((uint32_t)0x10u); /* mov ecx, 0x10 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x30u))); /* fld dword ptr [esp + 0x30] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb33464u))); /* fmul dword ptr [0x10013464] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x40u))); /* fld dword ptr [esp + 0x40] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb33468u))); /* fmul dword ptr [0x10013468] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x28u)); /* add edx, 0x28 */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x50u))); /* fld dword ptr [esp + 0x50] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb3346cu))); /* fmul dword ptr [0x1001346c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x60u))); /* fadd dword ptr [esp + 0x60] */
    WF32((uint32_t)(c->esp + 0x20u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x20] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x34u))); /* fld dword ptr [esp + 0x34] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb33464u))); /* fmul dword ptr [0x10013464] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x54u))); /* fld dword ptr [esp + 0x54] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb3346cu))); /* fmul dword ptr [0x1001346c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov eax, dword ptr [esp + 0x20] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x44u))); /* fld dword ptr [esp + 0x44] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb33468u))); /* fmul dword ptr [0x10013468] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x64u))); /* fadd dword ptr [esp + 0x64] */
    WF32((uint32_t)(c->esp + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x24] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x38u))); /* fld dword ptr [esp + 0x38] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb33464u))); /* fmul dword ptr [0x10013464] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x58u))); /* fld dword ptr [esp + 0x58] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb3346cu))); /* fmul dword ptr [0x1001346c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov ecx, dword ptr [esp + 0x24] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x48u))); /* fld dword ptr [esp + 0x48] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb33468u))); /* fmul dword ptr [0x10013468] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x68u))); /* fadd dword ptr [esp + 0x68] */
    W32((uint32_t)(c->edx), (uint32_t)(c->eax)); /* mov dword ptr [edx], eax */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [edx + 4], ecx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x170u)); /* lea ecx, [esp + 0x170] */
    WF32((uint32_t)(c->esp + 0x28u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x28] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov eax, dword ptr [esp + 0x28] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x18], ecx */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [edx + 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
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
    c->edx = (uint32_t)((uint32_t)(c->esp + 0xb0u)); /* lea edx, [esp + 0xb0] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x70u)); /* lea eax, [esp + 0x70] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x178u)); /* lea ecx, [esp + 0x178] */
    PUSH32(c, 0x00b23089u); f_00b234c0(c); /* call 0xb234c0 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x170u)); /* lea ecx, [esp + 0x170] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x30u)); /* lea edx, [esp + 0x30] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x18], ecx */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x1c], edx */
    c->df = 0; /* cld  */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov edi, dword ptr [esp + 0x1c] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov esi, dword ptr [esp + 0x18] */
    c->ecx = (uint32_t)((uint32_t)0x10u); /* mov ecx, 0x10 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x30u))); /* fld dword ptr [esp + 0x30] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb333ecu))); /* fmul dword ptr [0x100133ec] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x50u))); /* fld dword ptr [esp + 0x50] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb333f4u))); /* fmul dword ptr [0x100133f4] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x40u))); /* fld dword ptr [esp + 0x40] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb333f0u))); /* fmul dword ptr [0x100133f0] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x60u))); /* fadd dword ptr [esp + 0x60] */
    WF32((uint32_t)(c->esp + 0x20u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x20] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x34u))); /* fld dword ptr [esp + 0x34] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb333ecu))); /* fmul dword ptr [0x100133ec] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x44u))); /* fld dword ptr [esp + 0x44] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb333f0u))); /* fmul dword ptr [0x100133f0] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x54u))); /* fld dword ptr [esp + 0x54] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb333f4u))); /* fmul dword ptr [0x100133f4] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x64u))); /* fadd dword ptr [esp + 0x64] */
    WF32((uint32_t)(c->esp + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x24] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x38u))); /* fld dword ptr [esp + 0x38] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb333ecu))); /* fmul dword ptr [0x100133ec] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x58u))); /* fld dword ptr [esp + 0x58] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb333f4u))); /* fmul dword ptr [0x100133f4] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x48u))); /* fld dword ptr [esp + 0x48] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb333f0u))); /* fmul dword ptr [0x100133f0] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x68u))); /* fadd dword ptr [esp + 0x68] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov ecx, dword ptr [esp + 0x20] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov edx, dword ptr [esp + 0x24] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x3cu)); /* add eax, 0x3c */
    WF32((uint32_t)(c->esp + 0x28u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x28] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov ecx, dword ptr [esp + 0x28] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 4], edx */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x1b0u)); /* lea edx, [esp + 0x1b0] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x18], edx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
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
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x70u)); /* lea eax, [esp + 0x70] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x130u)); /* lea ecx, [esp + 0x130] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x1b8u)); /* lea ecx, [esp + 0x1b8] */
    PUSH32(c, 0x00b231a3u); f_00b234c0(c); /* call 0xb234c0 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x1b0u)); /* lea edx, [esp + 0x1b0] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x1f0u)); /* lea eax, [esp + 0x1f0] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x18], edx */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x1c], eax */
    c->df = 0; /* cld  */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov edi, dword ptr [esp + 0x1c] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov esi, dword ptr [esp + 0x18] */
    c->ecx = (uint32_t)((uint32_t)0x10u); /* mov ecx, 0x10 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x170u)); /* lea ecx, [esp + 0x170] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x18], ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
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
    c->edx = (uint32_t)((uint32_t)(c->esp + 0xb0u)); /* lea edx, [esp + 0xb0] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x1f0u)); /* lea eax, [esp + 0x1f0] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x178u)); /* lea ecx, [esp + 0x178] */
    PUSH32(c, 0x00b2322au); f_00b234c0(c); /* call 0xb234c0 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x170u)); /* lea ecx, [esp + 0x170] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x30u)); /* lea edx, [esp + 0x30] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x18], ecx */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x1c], edx */
    c->df = 0; /* cld  */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov edi, dword ptr [esp + 0x1c] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov esi, dword ptr [esp + 0x18] */
    c->ecx = (uint32_t)((uint32_t)0x10u); /* mov ecx, 0x10 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x20u)); /* lea eax, [esp + 0x20] */
    { uint32_t v_ = 0xb333d0u; PUSH32(c, v_); } /* push 0x100133d0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x38u)); /* lea ecx, [esp + 0x38] */
    PUSH32(c, 0x00b23260u); f_00b23440(c); /* call 0xb23440 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x50u)); /* add ecx, 0x50 */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov edx, dword ptr [eax + 4] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 4], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 8], eax */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x170u)); /* lea ecx, [esp + 0x170] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x18], ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
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
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x70u)); /* lea edx, [esp + 0x70] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x130u)); /* lea eax, [esp + 0x130] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x178u)); /* lea ecx, [esp + 0x178] */
    PUSH32(c, 0x00b232d5u); f_00b234c0(c); /* call 0xb234c0 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x170u)); /* lea ecx, [esp + 0x170] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x1f0u)); /* lea edx, [esp + 0x1f0] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x18], ecx */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x1c], edx */
    c->df = 0; /* cld  */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov edi, dword ptr [esp + 0x1c] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov esi, dword ptr [esp + 0x18] */
    c->ecx = (uint32_t)((uint32_t)0x10u); /* mov ecx, 0x10 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x20u)); /* lea eax, [esp + 0x20] */
    { uint32_t v_ = 0xb33404u; PUSH32(c, v_); } /* push 0x10013404 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0xb4u)); /* lea ecx, [esp + 0xb4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x1b8u)); /* lea edx, [esp + 0x1b8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x200u)); /* lea ecx, [esp + 0x200] */
    PUSH32(c, 0x00b23321u); f_00b233c0(c); /* call 0xb233c0 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    PUSH32(c, 0x00b23328u); f_00b23440(c); /* call 0xb23440 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x64u)); /* add ecx, 0x64 */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov edx, dword ptr [eax + 4] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 4], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 8], eax */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x228u)); /* add esp, 0x228 */
    c->esp += 8; return; /* ret 4 */
}

void f_00b23350(CPU *c) { /* PTR_00b23350 */
    PREEMPT_POLL(c);
    c->esp += 4; return; /* ret  */
}

void f_00b23360(CPU *c) { /* PTR_00b23360 */
    PREEMPT_POLL(c);
    c->esp += 4; return; /* ret  */
}

void f_00b23370(CPU *c) { /* PTR_00b23370 */
    PREEMPT_POLL(c);
    c->esp += 4; return; /* ret  */
}

void f_00b23380(CPU *c) { /* PTR_00b23380 */
    PREEMPT_POLL(c);
    c->esp += 4; return; /* ret  */
}

void f_00b23390(CPU *c) { /* PTR_00b23390 */
    PREEMPT_POLL(c);
    c->esp += 4; return; /* ret  */
}

void f_00b233a0(CPU *c) { /* PTR_00b233a0 */
    PREEMPT_POLL(c);
    c->esp += 4; return; /* ret  */
}

void f_00b233b0(CPU *c) { /* PTR_00b233b0 */
    PREEMPT_POLL(c);
    c->esp += 4; return; /* ret  */
}

void f_00b233c0(CPU *c) { /* FUN_100033c0 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x44u)); /* sub esp, 0x44 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x8u)); /* lea eax, [esp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
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
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x58u))); /* mov ecx, dword ptr [esp + 0x58] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x18u)); /* lea ecx, [esp + 0x18] */
    PUSH32(c, 0x00b23419u); f_00b234c0(c); /* call 0xb234c0 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x10u)); /* lea edx, [esp + 0x10] */
    W32((uint32_t)(c->esp + 0x58u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x58], edx */
    c->df = 0; /* cld  */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x54u))); /* mov edi, dword ptr [esp + 0x54] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x58u))); /* mov esi, dword ptr [esp + 0x58] */
    c->ecx = (uint32_t)((uint32_t)0x10u); /* mov ecx, 0x10 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x54u))); /* mov eax, dword ptr [esp + 0x54] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x44u)); /* add esp, 0x44 */
    c->esp += 12; return; /* ret 8 */
}

void f_00b23440(CPU *c) { /* FUN_10003440 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x20u))); /* fld dword ptr [ecx + 0x20] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x8u))); /* fmul dword ptr [eax + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x10u))); /* fld dword ptr [ecx + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x4u))); /* fmul dword ptr [eax + 4] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->eax))); /* fld dword ptr [eax] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ecx))); /* fmul dword ptr [ecx] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ecx + 0x30u))); /* fadd dword ptr [ecx + 0x30] */
    WF32((uint32_t)(c->esp), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x24u))); /* fld dword ptr [ecx + 0x24] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x8u))); /* fmul dword ptr [eax + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x14u))); /* fld dword ptr [ecx + 0x14] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x4u))); /* fmul dword ptr [eax + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp))); /* mov edx, dword ptr [esp] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x4u))); /* fld dword ptr [ecx + 4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax))); /* fmul dword ptr [eax] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ecx + 0x34u))); /* fadd dword ptr [ecx + 0x34] */
    WF32((uint32_t)(c->esp + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x28u))); /* fld dword ptr [ecx + 0x28] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x8u))); /* fmul dword ptr [eax + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x18u))); /* fld dword ptr [ecx + 0x18] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x4u))); /* fmul dword ptr [eax + 4] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x8u))); /* fld dword ptr [ecx + 8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax))); /* fmul dword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ecx + 0x38u))); /* fadd dword ptr [ecx + 0x38] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    WF32((uint32_t)(c->esp + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 8] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 4], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 8], edx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 12; return; /* ret 8 */
}

void f_00b234c0(CPU *c) { /* FUN_100034c0 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->edx))); /* fld dword ptr [edx] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax))); /* fmul dword ptr [eax] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x20u))); /* fld dword ptr [eax + 0x20] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edx + 0x8u))); /* fmul dword ptr [edx + 8] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + 0x4u))); /* fld dword ptr [edx + 4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x10u))); /* fmul dword ptr [eax + 0x10] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + 0xcu))); /* fld dword ptr [edx + 0xc] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x30u))); /* fmul dword ptr [eax + 0x30] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->ecx), (float)ST(0)); FPOP(c); /* fstp dword ptr [ecx] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x24u))); /* fld dword ptr [eax + 0x24] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edx + 0x8u))); /* fmul dword ptr [edx + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->edx))); /* fld dword ptr [edx] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x4u))); /* fmul dword ptr [eax + 4] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x14u))); /* fld dword ptr [eax + 0x14] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edx + 0x4u))); /* fmul dword ptr [edx + 4] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x34u))); /* fld dword ptr [eax + 0x34] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edx + 0xcu))); /* fmul dword ptr [edx + 0xc] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->ecx + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ecx + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->edx))); /* fld dword ptr [edx] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x8u))); /* fmul dword ptr [eax + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x28u))); /* fld dword ptr [eax + 0x28] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edx + 0x8u))); /* fmul dword ptr [edx + 8] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + 0x4u))); /* fld dword ptr [edx + 4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x18u))); /* fmul dword ptr [eax + 0x18] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x38u))); /* fld dword ptr [eax + 0x38] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edx + 0xcu))); /* fmul dword ptr [edx + 0xc] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->ecx + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ecx + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + 0xcu))); /* fld dword ptr [edx + 0xc] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x3cu))); /* fmul dword ptr [eax + 0x3c] */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + 0x4u))); /* fld dword ptr [edx + 4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x1cu))); /* fmul dword ptr [eax + 0x1c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0xcu))); /* fld dword ptr [eax + 0xc] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edx))); /* fmul dword ptr [edx] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x2cu))); /* fld dword ptr [eax + 0x2c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edx + 0x8u))); /* fmul dword ptr [edx + 8] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->ecx + 0xcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [ecx + 0xc] */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + 0x14u))); /* fld dword ptr [edx + 0x14] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x10u))); /* fmul dword ptr [eax + 0x10] */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + 0x1cu))); /* fld dword ptr [edx + 0x1c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x30u))); /* fmul dword ptr [eax + 0x30] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x20u))); /* fld dword ptr [eax + 0x20] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edx + 0x18u))); /* fmul dword ptr [edx + 0x18] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + 0x10u))); /* fld dword ptr [edx + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax))); /* fmul dword ptr [eax] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->ecx + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ecx + 0x10] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x14u))); /* fld dword ptr [eax + 0x14] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edx + 0x14u))); /* fmul dword ptr [edx + 0x14] */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + 0x10u))); /* fld dword ptr [edx + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x4u))); /* fmul dword ptr [eax + 4] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x34u))); /* fld dword ptr [eax + 0x34] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edx + 0x1cu))); /* fmul dword ptr [edx + 0x1c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x24u))); /* fld dword ptr [eax + 0x24] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edx + 0x18u))); /* fmul dword ptr [edx + 0x18] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->ecx + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ecx + 0x14] */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + 0x14u))); /* fld dword ptr [edx + 0x14] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x18u))); /* fmul dword ptr [eax + 0x18] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x38u))); /* fld dword ptr [eax + 0x38] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edx + 0x1cu))); /* fmul dword ptr [edx + 0x1c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x28u))); /* fld dword ptr [eax + 0x28] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edx + 0x18u))); /* fmul dword ptr [edx + 0x18] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + 0x10u))); /* fld dword ptr [edx + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x8u))); /* fmul dword ptr [eax + 8] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->ecx + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ecx + 0x18] */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + 0x10u))); /* fld dword ptr [edx + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0xcu))); /* fmul dword ptr [eax + 0xc] */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + 0x1cu))); /* fld dword ptr [edx + 0x1c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x3cu))); /* fmul dword ptr [eax + 0x3c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + 0x18u))); /* fld dword ptr [edx + 0x18] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x2cu))); /* fmul dword ptr [eax + 0x2c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + 0x14u))); /* fld dword ptr [edx + 0x14] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x1cu))); /* fmul dword ptr [eax + 0x1c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->ecx + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [ecx + 0x1c] */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + 0x24u))); /* fld dword ptr [edx + 0x24] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x10u))); /* fmul dword ptr [eax + 0x10] */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + 0x2cu))); /* fld dword ptr [edx + 0x2c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x30u))); /* fmul dword ptr [eax + 0x30] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x20u))); /* fld dword ptr [eax + 0x20] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edx + 0x28u))); /* fmul dword ptr [edx + 0x28] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + 0x20u))); /* fld dword ptr [edx + 0x20] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax))); /* fmul dword ptr [eax] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->ecx + 0x20u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ecx + 0x20] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x14u))); /* fld dword ptr [eax + 0x14] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edx + 0x24u))); /* fmul dword ptr [edx + 0x24] */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + 0x20u))); /* fld dword ptr [edx + 0x20] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x4u))); /* fmul dword ptr [eax + 4] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x34u))); /* fld dword ptr [eax + 0x34] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edx + 0x2cu))); /* fmul dword ptr [edx + 0x2c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x24u))); /* fld dword ptr [eax + 0x24] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edx + 0x28u))); /* fmul dword ptr [edx + 0x28] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->ecx + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ecx + 0x24] */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + 0x24u))); /* fld dword ptr [edx + 0x24] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x18u))); /* fmul dword ptr [eax + 0x18] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x38u))); /* fld dword ptr [eax + 0x38] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edx + 0x2cu))); /* fmul dword ptr [edx + 0x2c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x28u))); /* fld dword ptr [eax + 0x28] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edx + 0x28u))); /* fmul dword ptr [edx + 0x28] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + 0x20u))); /* fld dword ptr [edx + 0x20] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x8u))); /* fmul dword ptr [eax + 8] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->ecx + 0x28u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ecx + 0x28] */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + 0x20u))); /* fld dword ptr [edx + 0x20] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0xcu))); /* fmul dword ptr [eax + 0xc] */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + 0x2cu))); /* fld dword ptr [edx + 0x2c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x3cu))); /* fmul dword ptr [eax + 0x3c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + 0x28u))); /* fld dword ptr [edx + 0x28] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x2cu))); /* fmul dword ptr [eax + 0x2c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + 0x24u))); /* fld dword ptr [edx + 0x24] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x1cu))); /* fmul dword ptr [eax + 0x1c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->ecx + 0x2cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [ecx + 0x2c] */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + 0x34u))); /* fld dword ptr [edx + 0x34] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x10u))); /* fmul dword ptr [eax + 0x10] */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + 0x3cu))); /* fld dword ptr [edx + 0x3c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x30u))); /* fmul dword ptr [eax + 0x30] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x20u))); /* fld dword ptr [eax + 0x20] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edx + 0x38u))); /* fmul dword ptr [edx + 0x38] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + 0x30u))); /* fld dword ptr [edx + 0x30] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax))); /* fmul dword ptr [eax] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->ecx + 0x30u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ecx + 0x30] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x14u))); /* fld dword ptr [eax + 0x14] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edx + 0x34u))); /* fmul dword ptr [edx + 0x34] */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + 0x30u))); /* fld dword ptr [edx + 0x30] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x4u))); /* fmul dword ptr [eax + 4] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x34u))); /* fld dword ptr [eax + 0x34] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edx + 0x3cu))); /* fmul dword ptr [edx + 0x3c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x24u))); /* fld dword ptr [eax + 0x24] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edx + 0x38u))); /* fmul dword ptr [edx + 0x38] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->ecx + 0x34u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ecx + 0x34] */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + 0x34u))); /* fld dword ptr [edx + 0x34] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x18u))); /* fmul dword ptr [eax + 0x18] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x38u))); /* fld dword ptr [eax + 0x38] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edx + 0x3cu))); /* fmul dword ptr [edx + 0x3c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x28u))); /* fld dword ptr [eax + 0x28] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edx + 0x38u))); /* fmul dword ptr [edx + 0x38] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + 0x30u))); /* fld dword ptr [edx + 0x30] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x8u))); /* fmul dword ptr [eax + 8] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->ecx + 0x38u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ecx + 0x38] */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + 0x30u))); /* fld dword ptr [edx + 0x30] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0xcu))); /* fmul dword ptr [eax + 0xc] */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + 0x3cu))); /* fld dword ptr [edx + 0x3c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x3cu))); /* fmul dword ptr [eax + 0x3c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + 0x38u))); /* fld dword ptr [edx + 0x38] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x2cu))); /* fmul dword ptr [eax + 0x2c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + 0x34u))); /* fld dword ptr [edx + 0x34] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x1cu))); /* fmul dword ptr [eax + 0x1c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->ecx + 0x3cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [ecx + 0x3c] */
    c->esp += 12; return; /* ret 8 */
}

void f_00b236e0(CPU *c) { /* FUN_100036e0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0xb2e1ecu)); /* mov dword ptr [eax], 0x1000e1ec */
    c->esp += 4; return; /* ret  */
}

void f_00b236f0(CPU *c) { /* FUN_100036f0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00b236f8u); f_00b23710(c); /* call 0xb23710 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00b23708; /* je 0xb23708 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b23705u); f_00b21030(c); /* call 0xb21030 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00b23708:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00b23710(CPU *c) { /* FUN_10003710 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx), (uint32_t)((uint32_t)0xb2e1ecu)); /* mov dword ptr [ecx], 0x1000e1ec */
    c->esp += 4; return; /* ret  */
}

void f_00b23720(CPU *c) { /* FUN_10003720 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov edi, dword ptr [esp + 0x20] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00b23732u); f_00b21680(c); /* call 0xb21680 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov ebx, dword ptr [esp + 0x20] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ebx))); /* fadd dword ptr [ebx] */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 8], 0 */
    WF32((uint32_t)(c->esi + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 4] */
    PUSH32(c, 0x00b23748u); f_00b21680(c); /* call 0xb21680 */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ebx + 0x8u))); /* fadd dword ptr [ebx + 8] */
    { uint32_t v_ = 0x3f800000u; PUSH32(c, v_); } /* push 0x3f800000 */
    WF32((uint32_t)(c->esi + 0xcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0xc] */
    PUSH32(c, 0x00b23758u); f_00b21680(c); /* call 0xb21680 */
    WF32((uint32_t)(c->esp + 0x2cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x2c] */
    { uint32_t v_ = 0x3f800000u; PUSH32(c, v_); } /* push 0x3f800000 */
    PUSH32(c, 0x00b23766u); f_00b21680(c); /* call 0xb21680 */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x30u))); /* fld dword ptr [esp + 0x30] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x30u))); /* fmul dword ptr [esp + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FCOM(c, ST(0), RF64((uint32_t)(0xb2e1c0u))); /* fcom qword ptr [0x1000e1c0] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x44u)); /* test ah, 0x44 */
    if (PF(c)) goto L_00b237a2; /* jp 0xb237a2 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0xc], 0 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x10], 0 */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x14], 0 */
    goto L_00b237ca; /* jmp 0xb237ca */
L_00b237a2:;
    ST(0) = FPRES(c, sqrt(ST(0))); /* fsqrt  */
    ST(0) = FPRES(c, FDIV(c, RF64((uint32_t)(0xb2e1b8u)), ST(0))); /* fdivr qword ptr [0x1000e1b8] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF32((uint32_t)(c->esp + 0xcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xc] */
    FPUSH(c, RF64((uint32_t)(0xb2e1c0u))); /* fld qword ptr [0x1000e1c0] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x20u))); /* fld dword ptr [esp + 0x20] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
L_00b237ca:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edx, dword ptr [esp + 0x14] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x10u)); /* add esi, 0x10 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 4], ecx */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 8], edx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 12; return; /* ret 8 */
}

void f_00b237f0(CPU *c) { /* FUN_100037f0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(logic32(c, (uint32_t)(c->esp & (uint32_t)0xfffffff8u))); /* and esp, 0xfffffff8 */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x4cu)); /* sub esp, 0x4c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x10], 0 */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x14], 0 */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x18], 0 */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x1c], 0 */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x20], 0 */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x24], 0 */
    if ((c->zf || c->sf != c->of)) goto L_00b238dc; /* jle 0xb238dc */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
L_00b2383e:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b238d2; /* je 0xb238d2 */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if (c->zf) goto L_00b238d2; /* je 0xb238d2 */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0xcu))); /* fld dword ptr [eax + 0xc] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esi + 0xcu))); /* fsub dword ptr [esi + 0xc] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x40u)); /* lea ecx, [esp + 0x40] */
    WF32((uint32_t)(c->esp + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x8u))); /* fld dword ptr [eax + 8] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esi + 0x8u))); /* fsub dword ptr [esi + 8] */
    WF32((uint32_t)(c->esp + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x4u))); /* fld dword ptr [eax + 4] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esi + 0x4u))); /* fsub dword ptr [esi + 4] */
    WF32((uint32_t)(c->esp), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp] */
    PUSH32(c, 0x00b23879u); f_00b23b60(c); /* call 0xb23b60 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x3cu))); /* fld dword ptr [esp + 0x3c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb2e1fcu))); /* fmul dword ptr [0x1000e1fc] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x34u)); /* lea ecx, [esp + 0x34] */
    WF32((uint32_t)(c->esp + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x44u))); /* fld dword ptr [esp + 0x44] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb2e1fcu))); /* fmul dword ptr [0x1000e1fc] */
    WF32((uint32_t)(c->esp + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x40u))); /* fld dword ptr [esp + 0x40] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb2e1fcu))); /* fmul dword ptr [0x1000e1fc] */
    WF32((uint32_t)(c->esp), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp] */
    PUSH32(c, 0x00b238aeu); f_00b23b60(c); /* call 0xb23b60 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x28u))); /* fld dword ptr [esp + 0x28] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x10u))); /* fadd dword ptr [esp + 0x10] */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x2cu))); /* fadd dword ptr [esp + 0x2c] */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x30u))); /* fadd dword ptr [esp + 0x30] */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
L_00b238d2:;
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->zf) goto L_00b2383e; /* jne 0xb2383e */
L_00b238dc:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edi, dword ptr [ebp + 0x10] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_00b23a43; /* jle 0xb23a43 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
L_00b238ec:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b23a39; /* je 0xb23a39 */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if (c->zf) goto L_00b23a39; /* je 0xb23a39 */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0xcu))); /* fld dword ptr [eax + 0xc] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esi + 0xcu))); /* fsub dword ptr [esi + 0xc] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x34u)); /* lea ecx, [esp + 0x34] */
    WF32((uint32_t)(c->esp + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x8u))); /* fld dword ptr [eax + 8] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esi + 0x8u))); /* fsub dword ptr [esi + 8] */
    WF32((uint32_t)(c->esp + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x4u))); /* fld dword ptr [eax + 4] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esi + 0x4u))); /* fsub dword ptr [esi + 4] */
    WF32((uint32_t)(c->esp), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp] */
    PUSH32(c, 0x00b23927u); f_00b23b60(c); /* call 0xb23b60 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x28u))); /* fld dword ptr [esp + 0x28] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x28u))); /* fmul dword ptr [esp + 0x28] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x2cu))); /* fld dword ptr [esp + 0x2c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x2cu))); /* fmul dword ptr [esp + 0x2c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x30u))); /* fld dword ptr [esp + 0x30] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x30u))); /* fmul dword ptr [esp + 0x30] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, sqrt(ST(0))); /* fsqrt  */
    WF32((uint32_t)(c->esp + 0xcu), (float)ST(0)); /* fst dword ptr [esp + 0xc] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xb2e1f8u))); FPOP(c); /* fcomp dword ptr [0x1000e1f8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00b23960; /* jp 0xb23960 */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)((uint32_t)0x2edbe6ffu)); /* mov dword ptr [esp + 0xc], 0x2edbe6ff */
L_00b23960:;
    FCOM(c, ST(0), RF64((uint32_t)(0xb2e1c0u))); /* fcom qword ptr [0x1000e1c0] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x34u)); /* lea ecx, [esp + 0x34] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x44u)); /* test ah, 0x44 */
    if (PF(c)) goto L_00b2397c; /* jp 0xb2397c */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    PUSH32(c, 0x00b2397au); f_00b23b40(c); /* call 0xb23b40 */
    goto L_00b239ab; /* jmp 0xb239ab */
L_00b2397c:;
    ST(0) = FPRES(c, sqrt(ST(0))); /* fsqrt  */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    ST(0) = FPRES(c, FDIV(c, RF64((uint32_t)(0xb2e1b8u)), ST(0))); /* fdivr qword ptr [0x1000e1b8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x48u))); /* fld dword ptr [esp + 0x48] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF64((uint32_t)(c->esp + 0x10u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x10] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x44u))); /* fld dword ptr [esp + 0x44] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF64((uint32_t)(c->esp + 0x8u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x40u))); /* fld dword ptr [esp + 0x40] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    PUSH32(c, 0x00b239abu); f_00b23b80(c); /* call 0xb23b80 */
L_00b239ab:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x3cu))); /* fld dword ptr [esp + 0x3c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb2e1f4u))); /* fmul dword ptr [0x1000e1f4] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x4cu)); /* lea ecx, [esp + 0x4c] */
    WF32((uint32_t)(c->esp + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x44u))); /* fld dword ptr [esp + 0x44] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb2e1f4u))); /* fmul dword ptr [0x1000e1f4] */
    WF32((uint32_t)(c->esp + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x40u))); /* fld dword ptr [esp + 0x40] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb2e1f4u))); /* fmul dword ptr [0x1000e1f4] */
    WF32((uint32_t)(c->esp), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp] */
    PUSH32(c, 0x00b239e0u); f_00b23b60(c); /* call 0xb23b60 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xcu))); /* fld dword ptr [esp + 0xc] */
    ST(0) = FPRES(c, FDIV(c, RF64((uint32_t)(0xb2e1b8u)), ST(0))); /* fdivr qword ptr [0x1000e1b8] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x64u)); /* lea ecx, [esp + 0x64] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x60u))); /* fld dword ptr [esp + 0x60] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF64((uint32_t)(c->esp + 0x10u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x10] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x5cu))); /* fld dword ptr [esp + 0x5c] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF64((uint32_t)(c->esp + 0x8u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x58u))); /* fld dword ptr [esp + 0x58] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    PUSH32(c, 0x00b23a15u); f_00b23b80(c); /* call 0xb23b80 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x4cu))); /* fld dword ptr [esp + 0x4c] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fadd dword ptr [esp + 0x1c] */
    WF32((uint32_t)(c->esp + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x20u))); /* fld dword ptr [esp + 0x20] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x50u))); /* fadd dword ptr [esp + 0x50] */
    WF32((uint32_t)(c->esp + 0x20u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x20] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x24u))); /* fld dword ptr [esp + 0x24] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x54u))); /* fadd dword ptr [esp + 0x54] */
    WF32((uint32_t)(c->esp + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x24] */
L_00b23a39:;
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->zf) goto L_00b238ec; /* jne 0xb238ec */
L_00b23a43:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x24u))); /* fsub dword ptr [esp + 0x24] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x58u)); /* lea ecx, [esp + 0x58] */
    WF32((uint32_t)(c->esp + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x20u))); /* fld dword ptr [esp + 0x20] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x2cu))); /* fsub dword ptr [esp + 0x2c] */
    WF32((uint32_t)(c->esp + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fld dword ptr [esp + 0x1c] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x28u))); /* fsub dword ptr [esp + 0x28] */
    WF32((uint32_t)(c->esp), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp] */
    PUSH32(c, 0x00b23a72u); f_00b23b60(c); /* call 0xb23b60 */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x4cu)); /* lea eax, [esp + 0x4c] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x34u)); /* lea ecx, [esp + 0x34] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00b23a81u); f_00b23bd0(c); /* call 0xb23bd0 */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x8u))); /* fld dword ptr [eax + 8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb2e1f0u))); /* fmul dword ptr [0x1000e1f0] */
    WF32((uint32_t)(c->esp + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x4u))); /* fld dword ptr [eax + 4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb2e1f0u))); /* fmul dword ptr [0x1000e1f0] */
    WF32((uint32_t)(c->esp), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax))); /* fld dword ptr [eax] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb2e1f0u))); /* fmul dword ptr [0x1000e1f0] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x4cu)); /* lea ecx, [esp + 0x4c] */
    WF32((uint32_t)(c->esp), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp] */
    PUSH32(c, 0x00b23aafu); f_00b23b60(c); /* call 0xb23b60 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x40u)); /* lea edx, [esp + 0x40] */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x10u)); /* lea edi, [esi + 0x10] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x2cu)); /* lea eax, [esp + 0x2c] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b23ac2u); f_00b23c40(c); /* call 0xb23c40 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x28u)); /* lea ecx, [esp + 0x28] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00b23acdu); f_00b23bd0(c); /* call 0xb23bd0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->edx = (uint32_t)(c->edi); /* mov edx, edi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    W32((uint32_t)(c->edx), (uint32_t)(c->ecx)); /* mov dword ptr [edx], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [edx + 4], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov ecx, dword ptr [ebp + 0x18] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x50u)); /* lea ecx, [esp + 0x50] */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [edx + 8], eax */
    PUSH32(c, 0x00b23aefu); f_00b23b40(c); /* call 0xb23b40 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x4cu)); /* lea edx, [esp + 0x4c] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x44u)); /* lea eax, [esp + 0x44] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b23affu); f_00b23c70(c); /* call 0xb23c70 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x4u)); /* lea ecx, [esi + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b23b0bu); f_00b23ba0(c); /* call 0xb23ba0 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 24; return; /* ret 0x14 */
}

void f_00b23b20(CPU *c) { /* FUN_10003b20 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov edx, dword ptr [eax + 4] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 4], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 8], eax */
    c->esp += 8; return; /* ret 4 */
}

void f_00b23b40(CPU *c) { /* FUN_10003b40 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 4], edx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    c->esp += 8; return; /* ret 4 */
}

void f_00b23b60(CPU *c) { /* FUN_10003b60 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 4], edx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    c->esp += 16; return; /* ret 0xc */
}

void f_00b23b80(CPU *c) { /* FUN_10003b80 */
    PREEMPT_POLL(c);
    FPUSH(c, RF64((uint32_t)(c->esp + 0x4u))); /* fld qword ptr [esp + 4] */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    WF32((uint32_t)(c->eax), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax] */
    FPUSH(c, RF64((uint32_t)(c->esp + 0xcu))); /* fld qword ptr [esp + 0xc] */
    WF32((uint32_t)(c->eax + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 4] */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x14u))); /* fld qword ptr [esp + 0x14] */
    WF32((uint32_t)(c->eax + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 8] */
    c->esp += 28; return; /* ret 0x18 */
}

void f_00b23ba0(CPU *c) { /* FUN_10003ba0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx))); /* fld dword ptr [ecx] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->eax))); /* fadd dword ptr [eax] */
    WF32((uint32_t)(c->eax), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x4u))); /* fld dword ptr [ecx + 4] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->eax + 0x4u))); /* fadd dword ptr [eax + 4] */
    WF32((uint32_t)(c->eax + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x8u))); /* fld dword ptr [ecx + 8] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->eax + 0x8u))); /* fadd dword ptr [eax + 8] */
    WF32((uint32_t)(c->eax + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 8] */
    c->esp += 8; return; /* ret 4 */
}

void f_00b23bd0(CPU *c) { /* FUN_10003bd0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
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
    FCOM(c, ST(0), RF64((uint32_t)(0xb2e1c0u))); /* fcom qword ptr [0x1000e1c0] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x44u)); /* test ah, 0x44 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    if (PF(c)) goto L_00b23c10; /* jp 0xb23c10 */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 4], ecx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    c->esp += 4; return; /* ret  */
L_00b23c10:;
    ST(0) = FPRES(c, sqrt(ST(0))); /* fsqrt  */
    ST(0) = FPRES(c, FDIV(c, RF64((uint32_t)(0xb2e1b8u)), ST(0))); /* fdivr qword ptr [0x1000e1b8] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x8u))); /* fld dword ptr [ecx + 8] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x4u))); /* fld dword ptr [ecx + 4] */
    ST(0) = FPRES(c, ST(0) * ST(2)); /* fmul st(2) */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx))); /* fld dword ptr [ecx] */
    ST(0) = FPRES(c, ST(0) * ST(3)); /* fmul st(3) */
    WF32((uint32_t)(c->eax), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax] */
    WF32((uint32_t)(c->eax + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 4] */
    WF32((uint32_t)(c->eax + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 8] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    c->esp += 4; return; /* ret  */
}

void f_00b23c40(CPU *c) { /* FUN_10003c40 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x8u))); /* fld dword ptr [eax + 8] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ecx + 0x8u))); /* fadd dword ptr [ecx + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x4u))); /* fld dword ptr [eax + 4] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ecx + 0x4u))); /* fadd dword ptr [ecx + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax))); /* fld dword ptr [eax] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ecx))); /* fadd dword ptr [ecx] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    WF32((uint32_t)(c->eax), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax] */
    WF32((uint32_t)(c->eax + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 4] */
    WF32((uint32_t)(c->eax + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 8] */
    c->esp += 4; return; /* ret  */
}

void f_00b23c70(CPU *c) { /* FUN_10003c70 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x8u))); /* fld dword ptr [eax + 8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ecx + 0x8u))); /* fmul dword ptr [ecx + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x4u))); /* fld dword ptr [eax + 4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ecx + 0x4u))); /* fmul dword ptr [ecx + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax))); /* fld dword ptr [eax] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ecx))); /* fmul dword ptr [ecx] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    WF32((uint32_t)(c->eax), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax] */
    WF32((uint32_t)(c->eax + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 4] */
    WF32((uint32_t)(c->eax + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 8] */
    c->esp += 4; return; /* ret  */
}

void f_00b23ca0(CPU *c) { /* FUN_10003ca0 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)((uint32_t)0x96u); /* mov ecx, 0x96 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edi = (uint32_t)((uint32_t)(c->edx + 0x4u)); /* lea edi, [edx + 4] */
    W32((uint32_t)(c->edx), (uint32_t)((uint32_t)0xb2e200u)); /* mov dword ptr [edx], 0x1000e200 */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
    c->ecx = (uint32_t)((uint32_t)0x96u); /* mov ecx, 0x96 */
    c->edi = (uint32_t)((uint32_t)(c->edx + 0x25cu)); /* lea edi, [edx + 0x25c] */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00b23cd0(CPU *c) { /* FUN_10003cd0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00b23cd8u); f_00b23cf0(c); /* call 0xb23cf0 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00b23ce8; /* je 0xb23ce8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b23ce5u); f_00b21030(c); /* call 0xb21030 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00b23ce8:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00b23cf0(CPU *c) { /* FUN_10003cf0 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx), (uint32_t)((uint32_t)0xb2e200u)); /* mov dword ptr [ecx], 0x1000e200 */
    c->esp += 4; return; /* ret  */
}

void f_00b23d00(CPU *c) { /* FUN_10003d00 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edx = (uint32_t)((uint32_t)(c->ecx + 0x4u)); /* lea edx, [ecx + 4] */
L_00b23d05:;
    (void)sub32(c, R32((uint32_t)(c->edx)), (uint32_t)0x0u); /* cmp dword ptr [edx], 0 */
    if (c->zf) goto L_00b23d1a; /* je 0xb23d1a */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x4u)); /* add edx, 4 */
    (void)sub32(c, c->eax, (uint32_t)0x96u); /* cmp eax, 0x96 */
    if ((c->sf != c->of)) goto L_00b23d05; /* jl 0xb23d05 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    c->esp += 8; return; /* ret 4 */
L_00b23d1a:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    W32((uint32_t)(c->ecx + c->eax * 4 + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + eax*4 + 4], edx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    c->esp += 8; return; /* ret 4 */
}

void f_00b23d30(CPU *c) { /* FUN_10003d30 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edx = (uint32_t)((uint32_t)(c->ecx + 0x25cu)); /* lea edx, [ecx + 0x25c] */
L_00b23d38:;
    (void)sub32(c, R32((uint32_t)(c->edx)), (uint32_t)0x0u); /* cmp dword ptr [edx], 0 */
    if (c->zf) goto L_00b23d4d; /* je 0xb23d4d */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x4u)); /* add edx, 4 */
    (void)sub32(c, c->eax, (uint32_t)0x96u); /* cmp eax, 0x96 */
    if ((c->sf != c->of)) goto L_00b23d38; /* jl 0xb23d38 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    c->esp += 8; return; /* ret 4 */
L_00b23d4d:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    W32((uint32_t)(c->ecx + c->eax * 4 + 0x25cu), (uint32_t)(c->edx)); /* mov dword ptr [ecx + eax*4 + 0x25c], edx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    c->esp += 8; return; /* ret 4 */
}

void f_00b23d51(CPU *c) { /* PTR_00b23d51 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx + c->eax * 4 + 0x25cu), (uint32_t)(c->edx)); /* mov dword ptr [ecx + eax*4 + 0x25c], edx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    c->esp += 8; return; /* ret 4 */
}

void f_00b23d60(CPU *c) { /* FUN_10003d60 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xb2df38u; PUSH32(c, v_); } /* push 0x1000df38 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0xc], esi */
    PUSH32(c, 0x00b23d84u); f_00b23ca0(c); /* call 0xb23ca0 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x4b8u)); /* lea eax, [esi + 0x4b8] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x18], ebx */
    W32((uint32_t)(c->edx), (uint32_t)(c->ecx)); /* mov dword ptr [edx], ecx */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [edx + 4], ecx */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x7f8u)); /* lea ecx, [esi + 0x7f8] */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 8], ebx */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0xc], ebx */
    W32((uint32_t)(c->eax + 0x10u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x10], ebx */
    W32((uint32_t)(c->eax + 0x14u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x14], ebx */
    PUSH32(c, 0x00b23db0u); f_00b236e0(c); /* call 0xb236e0 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x81cu)); /* lea eax, [esi + 0x81c] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    W8((uint32_t)(c->esi + 0x818u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [esi + 0x818], bl */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x4d0u)); /* lea edi, [esi + 0x4d0] */
    W32((uint32_t)(c->edx), (uint32_t)(c->ecx)); /* mov dword ptr [edx], ecx */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [edx + 4], ecx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 8], ebx */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0xc], ebx */
    W32((uint32_t)(c->eax + 0x10u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x10], ebx */
    W32((uint32_t)(c->eax + 0x14u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x14], ebx */
    c->ecx = (uint32_t)((uint32_t)0xc8u); /* mov ecx, 0xc8 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0xb2e204u)); /* mov dword ptr [esi], 0x1000e204 */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_00b23e00(CPU *c) { /* FUN_10003e00 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00b23e08u); f_00b23e20(c); /* call 0xb23e20 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00b23e18; /* je 0xb23e18 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b23e15u); f_00b21030(c); /* call 0xb21030 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00b23e18:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00b23e20(CPU *c) { /* FUN_10003e20 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xb2df66u; PUSH32(c, v_); } /* push 0x1000df66 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0xc], ebx */
    W32((uint32_t)(c->ebx), (uint32_t)((uint32_t)0xb2e204u)); /* mov dword ptr [ebx], 0x1000e204 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x7f4u))); /* mov eax, dword ptr [ebx + 0x7f4] */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [esp + 0x18], 1 */
    if ((c->zf || c->sf != c->of)) goto L_00b23e79; /* jle 0xb23e79 */
    c->edi = (uint32_t)((uint32_t)(c->ebx + 0x4d0u)); /* lea edi, [ebx + 0x4d0] */
L_00b23e5f:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi))); /* mov ecx, dword ptr [edi] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00b23e6b; /* je 0xb23e6b */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t t_ = R32((uint32_t)(c->eax)); PUSH32(c, 0x00b23e6bu); call_indirect(c, t_); } /* call dword ptr [eax] */
L_00b23e6b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x7f4u))); /* mov eax, dword ptr [ebx + 0x7f4] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if ((c->sf != c->of)) goto L_00b23e5f; /* jl 0xb23e5f */
L_00b23e79:;
    c->eax = (uint32_t)(R32((uint32_t)(0xb333b4u))); /* mov eax, dword ptr [0x100133b4] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->esi = (uint32_t)((uint32_t)(c->ebx + 0x4b8u)); /* lea esi, [ebx + 0x4b8] */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x60u)); PUSH32(c, 0x00b23e97u); call_indirect(c, t_); } /* call dword ptr [edx + 0x60] */
    c->ecx = (uint32_t)((uint32_t)(c->ebx + 0x7f8u)); /* lea ecx, [ebx + 0x7f8] */
    W8((uint32_t)(c->esp + 0x18u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esp + 0x18], 0 */
    PUSH32(c, 0x00b23ea7u); f_00b23710(c); /* call 0xb23710 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [esp + 0x18], 0xffffffff */
    PUSH32(c, 0x00b23eb6u); f_00b23cf0(c); /* call 0xb23cf0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_00b23ed0(CPU *c) { /* FUN_10003ed0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0xb333b4u))); /* mov eax, dword ptr [0x100133b4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    { uint32_t v_ = 0xb3008cu; PUSH32(c, v_); } /* push 0x1001008c */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x58u)); PUSH32(c, 0x00b23ee6u); call_indirect(c, t_); } /* call dword ptr [edx + 0x58] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00b23f2c; /* je 0xb23f2c */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t v_ = 0xc8u; PUSH32(c, v_); } /* push 0xc8 */
    { uint32_t v_ = 0xb300f0u; PUSH32(c, v_); } /* push 0x100100f0 */
    { uint32_t v_ = 0xb300c8u; PUSH32(c, v_); } /* push 0x100100c8 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x20u)); PUSH32(c, 0x00b23f02u); call_indirect(c, t_); } /* call dword ptr [eax + 0x20] */
    W32((uint32_t)(c->edi + 0x7f4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + 0x7f4], eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    { uint32_t v_ = 0x42c80000u; PUSH32(c, v_); } /* push 0x42c80000 */
    { uint32_t v_ = 0xb300e4u; PUSH32(c, v_); } /* push 0x100100e4 */
    { uint32_t v_ = 0xb300c8u; PUSH32(c, v_); } /* push 0x100100c8 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x38u)); PUSH32(c, 0x00b23f1eu); call_indirect(c, t_); } /* call dword ptr [edx + 0x38] */
    WF32((uint32_t)(c->edi + 0x814u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + 0x814] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax)); PUSH32(c, 0x00b23f2cu); call_indirect(c, t_); } /* call dword ptr [eax] */
L_00b23f2c:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b23f30(CPU *c) { /* FUN_10003f30 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xb2df92u; PUSH32(c, v_); } /* push 0x1000df92 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x260u)); /* sub esp, 0x260 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    PUSH32(c, 0x00b23f56u); f_00b23ed0(c); /* call 0xb23ed0 */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb333b4u))); /* mov ecx, dword ptr [0x100133b4] */
    { uint32_t v_ = 0xb301c8u; PUSH32(c, v_); } /* push 0x100101c8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4cu)); PUSH32(c, 0x00b23f66u); call_indirect(c, t_); } /* call dword ptr [eax + 0x4c] */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->edi + 0x4b4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + 0x4b4], eax */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (!c->zf) goto L_00b23ffe; /* jne 0xb23ffe */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb33398u))); /* mov ecx, dword ptr [0x10013398] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x18u)); PUSH32(c, 0x00b23f81u); call_indirect(c, t_); } /* call dword ptr [edx + 0x18] */
    c->eax = (uint32_t)(R32((uint32_t)(0xb33398u))); /* mov eax, dword ptr [0x10013398] */
    { uint32_t v_ = 0xb301b0u; PUSH32(c, v_); } /* push 0x100101b0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00b23f91u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(0xb33398u))); /* mov eax, dword ptr [0x10013398] */
    { uint32_t v_ = 0x2eu; PUSH32(c, v_); } /* push 0x2e */
    { uint32_t v_ = 0xb3021cu; PUSH32(c, v_); } /* push 0x1001021c */
    { uint32_t v_ = 0xb30174u; PUSH32(c, v_); } /* push 0x10010174 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00b23fa8u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(0xb33398u))); /* mov eax, dword ptr [0x10013398] */
    { uint32_t v_ = 0xb301f4u; PUSH32(c, v_); } /* push 0x100101f4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00b23fb8u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    W32((uint32_t)(c->esp + 0x144u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x144], ebx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00b23fc4:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0xb301f4u))); /* mov cl, byte ptr [eax + 0x100101f4] */
    W8((uint32_t)(c->esp + c->eax + 0x20u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esp + eax + 0x20], cl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_00b23fc4; /* jne 0xb23fc4 */
    c->ecx = (uint32_t)((uint32_t)0x4au); /* mov ecx, 0x4a */
    c->esi = (uint32_t)((uint32_t)(c->esp + 0x20u)); /* lea esi, [esp + 0x20] */
    c->edi = (uint32_t)((uint32_t)(c->esp + 0x148u)); /* lea edi, [esp + 0x148] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x148u)); /* lea edx, [esp + 0x148] */
    { uint32_t v_ = 0xb2eae8u; PUSH32(c, v_); } /* push 0x1000eae8 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    W32((uint32_t)(c->esp + 0x280u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x280], ebx */
    PUSH32(c, 0x00b23ffeu); f_00b25a89(c); /* call 0xb25a89 */
L_00b23ffe:;
    c->ecx = (uint32_t)(R32((uint32_t)(0xb333b4u))); /* mov ecx, dword ptr [0x100133b4] */
    c->esi = (uint32_t)((uint32_t)(c->edi + 0x81cu)); /* lea esi, [edi + 0x81c] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0xb301f0u; PUSH32(c, v_); } /* push 0x100101f0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x44u)); PUSH32(c, 0x00b24016u); call_indirect(c, t_); } /* call dword ptr [eax + 0x44] */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb333b4u))); /* mov ecx, dword ptr [0x100133b4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x64u)); PUSH32(c, 0x00b24022u); call_indirect(c, t_); } /* call dword ptr [edx + 0x64] */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    W32((uint32_t)(c->edi + 0x834u), (uint32_t)(c->eax)); /* mov dword ptr [edi + 0x834], eax */
    if (!c->zf) goto L_00b24038; /* jne 0xb24038 */
    W8((uint32_t)(c->edi + 0x818u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [edi + 0x818], 0 */
    goto L_00b2415a; /* jmp 0xb2415a */
L_00b24038:;
    (void)sub32(c, R32((uint32_t)(c->edi + 0x7f4u)), c->ebx); /* cmp dword ptr [edi + 0x7f4], ebx */
    if ((c->zf || c->sf != c->of)) goto L_00b24109; /* jle 0xb24109 */
    c->esi = (uint32_t)((uint32_t)(c->edi + 0x4d0u)); /* lea esi, [edi + 0x4d0] */
L_00b2404a:;
    { uint32_t v_ = 0x3au; PUSH32(c, v_); } /* push 0x3a */
    { uint32_t v_ = 0xb3021cu; PUSH32(c, v_); } /* push 0x1001021c */
    { uint32_t v_ = 0x2cu; PUSH32(c, v_); } /* push 0x2c */
    PUSH32(c, 0x00b24058u); f_00b21050(c); /* call 0xb21050 */
    c->ebp = (uint32_t)(c->eax); /* mov ebp, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0x1c], ebp */
    (void)logic32(c, (uint32_t)(c->ebp & c->ebp)); /* test ebp, ebp */
    W32((uint32_t)(c->esp + 0x278u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [esp + 0x278], 1 */
    if (c->zf) goto L_00b24082; /* je 0xb24082 */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    PUSH32(c, 0x00b24077u); f_00b236e0(c); /* call 0xb236e0 */
    W32((uint32_t)(c->ebp), (uint32_t)((uint32_t)0xb2e208u)); /* mov dword ptr [ebp], 0x1000e208 */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    goto L_00b24084; /* jmp 0xb24084 */
L_00b24082:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
L_00b24084:;
    W32((uint32_t)(c->esi), (uint32_t)(c->ecx)); /* mov dword ptr [esi], ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x814u))); /* mov eax, dword ptr [edi + 0x814] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x10u)); /* lea edx, [esp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    W32((uint32_t)(c->esp + 0x280u), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [esp + 0x280], 0xffffffff */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x18], 0 */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x1c], 0 */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x20], 0 */
    PUSH32(c, 0x00b240bau); f_00b23720(c); /* call 0xb23720 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t v_ = 0x42c80000u; PUSH32(c, v_); } /* push 0x42c80000 */
    W32((uint32_t)(c->eax + 0x1cu), (uint32_t)((uint32_t)0x3d4ccccdu)); /* mov dword ptr [eax + 0x1c], 0x3d4ccccd */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    W32((uint32_t)(c->ecx + 0x20u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ecx + 0x20], 0 */
    PUSH32(c, 0x00b240d6u); f_00b21660(c); /* call 0xb21660 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    { uint32_t v_ = 0x3c23d70au; PUSH32(c, v_); } /* push 0x3c23d70a */
    WF32((uint32_t)(c->edx + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edx + 0x24] */
    PUSH32(c, 0x00b240e5u); f_00b21640(c); /* call 0xb21640 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    WF32((uint32_t)(c->eax + 0x28u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 0x28] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    PUSH32(c, 0x00b240f7u); f_00b23d30(c); /* call 0xb23d30 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x7f4u))); /* mov eax, dword ptr [edi + 0x7f4] */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, c->ebx, c->eax); /* cmp ebx, eax */
    if ((c->sf != c->of)) goto L_00b2404a; /* jl 0xb2404a */
L_00b24109:;
    c->edx = (uint32_t)((uint32_t)(c->edi + 0x7f8u)); /* lea edx, [edi + 0x7f8] */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00b24117u); f_00b23d00(c); /* call 0xb23d00 */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb333b4u))); /* mov ecx, dword ptr [0x100133b4] */
    c->esi = (uint32_t)((uint32_t)(c->edi + 0x4b8u)); /* lea esi, [edi + 0x4b8] */
    { uint32_t v_ = 0xb301e8u; PUSH32(c, v_); } /* push 0x100101e8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x5cu)); PUSH32(c, 0x00b2412eu); call_indirect(c, t_); } /* call dword ptr [eax + 0x5c] */
    c->eax = (uint32_t)(R32((uint32_t)(0xb333b4u))); /* mov eax, dword ptr [0x100133b4] */
    { uint32_t v_ = 0xb2e188u; PUSH32(c, v_); } /* push 0x1000e188 */
    { uint32_t v_ = 0x5014u; PUSH32(c, v_); } /* push 0x5014 */
    { uint32_t v_ = 0xb301e4u; PUSH32(c, v_); } /* push 0x100101e4 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x98u)); PUSH32(c, 0x00b24157u); call_indirect(c, t_); } /* call dword ptr [edx + 0x98] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x28u)); /* add esp, 0x28 */
L_00b2415a:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x270u))); /* mov ecx, dword ptr [esp + 0x270] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x26cu)); /* add esp, 0x26c */
    c->esp += 4; return; /* ret  */
}

void f_00b24180(CPU *c) { /* FUN_10004180 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00b24188u); f_00b241a0(c); /* call 0xb241a0 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00b24198; /* je 0xb24198 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b24195u); f_00b21030(c); /* call 0xb21030 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00b24198:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00b241a0(CPU *c) { /* thunk_FUN_10003710 */
    PREEMPT_POLL(c);
    { f_00b23710(c); return; } /* jmp 0xb23710 */
}

void f_00b241b0(CPU *c) { /* FUN_100041b0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x12d32u)); /* sub eax, 0x12d32 */
    if (c->zf) goto L_00b241ca; /* je 0xb241ca */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (!c->zf) goto L_00b241d1; /* jne 0xb241d1 */
    W8((uint32_t)(c->ecx + 0x818u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [ecx + 0x818], 0 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 12; return; /* ret 8 */
L_00b241ca:;
    W8((uint32_t)(c->ecx + 0x818u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ecx + 0x818], 1 */
L_00b241d1:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 12; return; /* ret 8 */
}

void f_00b241e0(CPU *c) { /* FUN_100041e0 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x34u)); /* sub esp, 0x34 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub8(c, R8((uint32_t)(c->edi + 0x818u)), ((uint8_t)c->ebx)); /* cmp byte ptr [edi + 0x818], bl */
    if (c->zf) goto L_00b242ef; /* je 0xb242ef */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x4b4u))); /* mov ecx, dword ptr [edi + 0x4b4] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea edx, [esp + 0x14] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x34u)); /* lea edx, [esp + 0x34] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x2cu)); /* lea edx, [esp + 0x2c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x70u)); PUSH32(c, 0x00b2420fu); call_indirect(c, t_); } /* call dword ptr [eax + 0x70] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x24u)); /* lea eax, [esp + 0x24] */
    c->ecx = (uint32_t)((uint32_t)(c->edi + 0x7f8u)); /* lea ecx, [edi + 0x7f8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2421fu); f_00b23b20(c); /* call 0xb23b20 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x40u))); /* mov ecx, dword ptr [esp + 0x40] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x10], ebx */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0xc], ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x7f4u))); /* mov eax, dword ptr [edi + 0x7f4] */
    FPUSH(c, (double)(int64_t)R64((uint32_t)(c->esp + 0xcu))); /* fild qword ptr [esp + 0xc] */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb2e1dcu))); /* fmul dword ptr [0x1000e1dc] */
    WF32((uint32_t)(c->esp + 0xcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xc] */
    if ((c->zf || c->sf != c->of)) goto L_00b242ef; /* jle 0xb242ef */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ebp = (uint32_t)((uint32_t)(c->edi + 0x25cu)); /* lea ebp, [edi + 0x25c] */
    c->esi = (uint32_t)((uint32_t)(c->edi + 0x4d0u)); /* lea esi, [edi + 0x4d0] */
L_00b24255:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x4u)); /* add eax, 4 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x20], edx */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x20u))); /* fld dword ptr [esp + 0x20] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x2cu))); /* fsub dword ptr [esp + 0x2c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov edx, dword ptr [eax + 8] */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x24], ecx */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x28], edx */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    PUSH32(c, 0x00b2427du); f_00b25ac4(c); /* call 0xb25ac4 */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ c->edx))); /* xor eax, edx */
    c->eax = (uint32_t)(sub32(c, c->eax, c->edx)); /* sub eax, edx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x10u))); /* fild dword ptr [esp + 0x10] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = fabs(ST(0)); /* fabs  */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FCOM(c, ST(0), RF64((uint32_t)(0xb2e210u))); FPOP(c); /* fcomp qword ptr [0x1000e210] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00b242b2; /* jne 0xb242b2 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x814u))); /* mov eax, dword ptr [edi + 0x814] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x2cu)); /* lea ecx, [esp + 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    PUSH32(c, 0x00b242b2u); f_00b23720(c); /* call 0xb23720 */
L_00b242b2:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edx, dword ptr [esp + 0x14] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x96u; PUSH32(c, v_); } /* push 0x96 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->eax = (uint32_t)((uint32_t)(c->edi + 0x4u)); /* lea eax, [edi + 4] */
    { uint32_t v_ = 0x96u; PUSH32(c, v_); } /* push 0x96 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b242cdu); f_00b237f0(c); /* call 0xb237f0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x48u))); /* mov ecx, dword ptr [esp + 0x48] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x20u))); /* mov edx, dword ptr [eax + 0x20] */
    c->edx = (uint32_t)(add32(c, c->edx, c->ecx)); /* add edx, ecx */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    W32((uint32_t)(c->eax + 0x20u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 0x20], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x7f4u))); /* mov eax, dword ptr [edi + 0x7f4] */
    (void)sub32(c, c->ebx, c->eax); /* cmp ebx, eax */
    if ((c->sf != c->of)) goto L_00b24255; /* jl 0xb24255 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
L_00b242ef:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x34u)); /* add esp, 0x34 */
    c->esp += 8; return; /* ret 4 */
}

void f_00b24300(CPU *c) { /* FUN_10004300 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x4cu)); /* sub esp, 0x4c */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi + 0x818u))); /* mov al, byte ptr [edi + 0x818] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00b24522; /* je 0xb24522 */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb333b4u))); /* mov ecx, dword ptr [0x100133b4] */
    c->edx = (uint32_t)((uint32_t)(c->edi + 0x81cu)); /* lea edx, [edi + 0x81c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x64u)); PUSH32(c, 0x00b24328u); call_indirect(c, t_); } /* call dword ptr [eax + 0x64] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->edi + 0x834u), (uint32_t)(c->eax)); /* mov dword ptr [edi + 0x834], eax */
    if (!c->zf) goto L_00b24341; /* jne 0xb24341 */
    W8((uint32_t)(c->edi + 0x818u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 0x818], al */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4cu)); /* add esp, 0x4c */
    c->esp += 8; return; /* ret 4 */
L_00b24341:;
    c->ecx = (uint32_t)(R32((uint32_t)(0xb333b4u))); /* mov ecx, dword ptr [0x100133b4] */
    c->edx = (uint32_t)((uint32_t)(c->edi + 0x4b8u)); /* lea edx, [edi + 0x4b8] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x64u)); PUSH32(c, 0x00b24353u); call_indirect(c, t_); } /* call dword ptr [eax + 0x64] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00b24522; /* je 0xb24522 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x7f4u))); /* mov eax, dword ptr [edi + 0x7f4] */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_00b24522; /* jle 0xb24522 */
    FPUSH(c, RF64((uint32_t)(0xb2e1c0u))); /* fld qword ptr [0x1000e1c0] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)((uint32_t)(c->edi + 0x4d0u)); /* lea ebp, [edi + 0x4d0] */
    WF32((uint32_t)(c->esp + 0x28u), (float)ST(0)); /* fst dword ptr [esp + 0x28] */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    FPUSH(c, RF64((uint32_t)(0xb2e1c0u))); /* fld qword ptr [0x1000e1c0] */
    ST(0) = FTRIG(c, ST(0), cos); /* fcos  */
    WF32((uint32_t)(c->esp + 0x2cu), (float)ST(0)); /* fst dword ptr [esp + 0x2c] */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
L_00b24394:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov eax, dword ptr [ebp] */
    W32((uint32_t)(c->esp + 0x34u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x34], 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x18u))); /* fld dword ptr [eax + 0x18] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x10u))); /* fld dword ptr [eax + 0x10] */
    ST(1) = atan2(ST(1), ST(0)); FPOP(c); /* fpatan  */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x4u)); /* lea ecx, [eax + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov edx, dword ptr [eax + 4] */
    W32((uint32_t)(c->esp + 0x48u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x48], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov edx, dword ptr [ecx + 4] */
    W32((uint32_t)(c->esp + 0x4cu), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x4c], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x20u))); /* mov edx, dword ptr [eax + 0x20] */
    W32((uint32_t)(c->esp + 0x34u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x34], edx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov ecx, dword ptr [ecx + 8] */
    W32((uint32_t)(c->esp + 0x50u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x50], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x834u))); /* mov ecx, dword ptr [edi + 0x834] */
    FPUSH(c, (double)(int64_t)R64((uint32_t)(c->esp + 0x34u))); /* fild qword ptr [esp + 0x34] */
    ST(0) = FPRES(c, FDIV(c, ST(0), (double)RF32((uint32_t)(c->eax + 0x24u)))); /* fdiv dword ptr [eax + 0x24] */
    FPUSH(c, (double)RF32((uint32_t)(0xb2e218u))); /* fld dword ptr [0x1000e218] */
    ST(0) = FPRES(c, ST(0) - ST(2)); /* fsub st(2) */
    { double v_ = ST(1); FPUSH(c, v_); } /* fld st(1) */
    ST(0) = FTRIG(c, ST(0), cos); /* fcos  */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x28u))); /* fld dword ptr [eax + 0x28] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb2e218u))); /* fmul dword ptr [0x1000e218] */
    ST(2) = FPRES(c, ST(2) * ST(0)); FPOP(c); /* fmulp st(2) */
    ST(1) = FPRES(c, ST(0) - ST(1)); FPOP(c); /* fsubrp st(1) */
    WF32((uint32_t)(c->esp + 0x58u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x58] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0xb2e218u))); /* fadd dword ptr [0x1000e218] */
    WF32((uint32_t)(c->esp + 0x20u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x20] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x20u))); /* fld dword ptr [esp + 0x20] */
    ST(0) = FTRIG(c, ST(0), cos); /* fcos  */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x28u))); /* fmul dword ptr [eax + 0x28] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x48u))); /* fadd dword ptr [esp + 0x48] */
    WF32((uint32_t)(c->esp + 0x3cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x3c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x20u))); /* fld dword ptr [esp + 0x20] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x28u))); /* fmul dword ptr [eax + 0x28] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x50u))); /* fadd dword ptr [esp + 0x50] */
    WF32((uint32_t)(c->esp + 0x44u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x44] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x44u))); /* mov edx, dword ptr [esp + 0x44] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x40u))); /* mov edx, dword ptr [esp + 0x40] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x3cu)); PUSH32(c, 0x00b24439u); call_indirect(c, t_); } /* call dword ptr [eax + 0x3c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov eax, dword ptr [ebp] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov ecx, dword ptr [esp + 0x2c] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x10], ecx */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->eax + 0x1cu))); /* fsub dword ptr [eax + 0x1c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x28u))); /* fld dword ptr [esp + 0x28] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x54u))); /* fld dword ptr [esp + 0x54] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x54u))); /* fld dword ptr [esp + 0x54] */
    ST(0) = FTRIG(c, ST(0), cos); /* fcos  */
    WF32((uint32_t)(c->esp + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF32((uint32_t)(c->esp + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x24] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fmul dword ptr [esp + 0x1c] */
    WF32((uint32_t)(c->esp + 0x20u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x20] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x24u))); /* fld dword ptr [esp + 0x24] */
    ST(0) = FPRES(c, ST(0) * ST(2)); /* fmul st(2) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x20u))); /* fadd dword ptr [esp + 0x20] */
    WF32((uint32_t)(c->esi + 0x20u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x20] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fmul dword ptr [esp + 0x1c] */
    { double v_ = ST(1); FPUSH(c, v_); } /* fld st(1) */
    ST(0) = FPRES(c, ST(0) * ST(4)); /* fmul st(4) */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W32((uint32_t)(c->esi + 0x5cu), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [esi + 0x5c], 0x3f800000 */
    W32((uint32_t)(c->esi + 0x2cu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x2c], eax */
    W32((uint32_t)(c->esi + 0x3cu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x3c], eax */
    ST(0) = FPRES(c, ST(0) - ST(1)); /* fsub st(1) */
    W32((uint32_t)(c->esi + 0x4cu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x4c], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x60u))); /* mov eax, dword ptr [esp + 0x60] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esi + 0x30u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x30] */
    { double t_ = ST(0); ST(0) = ST(2); ST(2) = t_; } /* fxch st(2) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x14u))); /* fmul dword ptr [esp + 0x14] */
    WF32((uint32_t)(c->esi + 0x40u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x40] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x3cu))); /* fld dword ptr [esp + 0x3c] */
    WF32((uint32_t)(c->esi + 0x50u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x50] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x14u))); /* fmul dword ptr [esp + 0x14] */
    WF32((uint32_t)(c->esi + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x24] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fld dword ptr [esp + 0x1c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x14u))); /* fmul dword ptr [esp + 0x14] */
    WF32((uint32_t)(c->esi + 0x34u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x34] */
    { double v_ = ST(2); FPUSH(c, v_); } /* fld st(2) */
    ST(0) = -ST(0); /* fchs  */
    WF32((uint32_t)(c->esi + 0x44u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x44] */
    { double t_ = ST(0); ST(0) = ST(3); ST(3) = t_; } /* fxch st(3) */
    WF32((uint32_t)(c->esi + 0x54u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x54] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    ST(0) = FPRES(c, ST(0) - ST(2)); /* fsub st(2) */
    WF32((uint32_t)(c->esi + 0x28u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x28] */
    ST(1) = ST(0); FPOP(c); /* fstp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x24u))); /* fld dword ptr [esp + 0x24] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x28u))); /* fadd dword ptr [esp + 0x28] */
    WF32((uint32_t)(c->esi + 0x38u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x38] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x20u))); /* fld dword ptr [esp + 0x20] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x14u))); /* fmul dword ptr [esp + 0x14] */
    WF32((uint32_t)(c->esi + 0x48u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x48] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x44u))); /* fld dword ptr [esp + 0x44] */
    WF32((uint32_t)(c->esi + 0x58u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x58] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x00b2450fu); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x7f4u))); /* mov eax, dword ptr [edi + 0x7f4] */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    c->ebp = (uint32_t)(add32(c, c->ebp, (uint32_t)0x4u)); /* add ebp, 4 */
    (void)sub32(c, c->ebx, c->eax); /* cmp ebx, eax */
    if ((c->sf != c->of)) goto L_00b24394; /* jl 0xb24394 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
L_00b24522:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4cu)); /* add esp, 0x4c */
    c->esp += 8; return; /* ret 4 */
}

void f_00b24530(CPU *c) { /* FUN_10004530 */
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
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0xb2e21cu)); /* mov dword ptr [esi], 0x1000e21c */
    c->edi = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edi, dword ptr [ecx] */
    c->eax = (uint32_t)(add32(c, c->eax, c->eax)); /* add eax, eax */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edi + 0x104u)); PUSH32(c, 0x00b2458cu); call_indirect(c, t_); } /* call dword ptr [edi + 0x104] */
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
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x100u)); PUSH32(c, 0x00b245acu); call_indirect(c, t_); } /* call dword ptr [eax + 0x100] */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov eax, dword ptr [esi + 0x20] */
    { uint32_t v_ = 0x15u; PUSH32(c, v_); } /* push 0x15 */
    { uint32_t v_ = 0xb3024cu; PUSH32(c, v_); } /* push 0x1001024c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b245bfu); f_00b21050(c); /* call 0xb21050 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov ecx, dword ptr [esi + 0x20] */
    W32((uint32_t)(c->esi + 0x24u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x24], eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, c->ecx, c->ebx); /* cmp ecx, ebx */
    if ((c->zf || c->sf != c->of)) goto L_00b245dd; /* jle 0xb245dd */
L_00b245ce:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov ecx, dword ptr [esi + 0x24] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    W8((uint32_t)(c->eax + c->ecx + 0xffffffffu), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [eax + ecx - 1], bl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov ecx, dword ptr [esi + 0x20] */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if ((c->sf != c->of)) goto L_00b245ce; /* jl 0xb245ce */
L_00b245dd:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 28; return; /* ret 0x18 */
}

void f_00b245f0(CPU *c) { /* FUN_100045f0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00b245f8u); f_00b24610(c); /* call 0xb24610 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00b24608; /* je 0xb24608 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b24605u); f_00b21030(c); /* call 0xb21030 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00b24608:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00b24610(CPU *c) { /* FUN_10004610 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov eax, dword ptr [esi + 0x24] */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0xb2e21cu)); /* mov dword ptr [esi], 0x1000e21c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b24629; /* je 0xb24629 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b24626u); f_00b21030(c); /* call 0xb21030 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00b24629:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b2463c; /* je 0xb2463c */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x124u)); PUSH32(c, 0x00b2463cu); call_indirect(c, t_); } /* call dword ptr [edx + 0x124] */
L_00b2463c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b2464f; /* je 0xb2464f */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x128u)); PUSH32(c, 0x00b2464fu); call_indirect(c, t_); } /* call dword ptr [edx + 0x128] */
L_00b2464f:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b24660(CPU *c) { /* FUN_10004660 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x20u))); /* mov esi, dword ptr [ecx + 0x20] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if ((c->zf || c->sf != c->of)) goto L_00b24678; /* jle 0xb24678 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x24u))); /* mov edx, dword ptr [ecx + 0x24] */
L_00b2466d:;
    (void)sub8(c, R8((uint32_t)(c->edx + c->eax)), (uint8_t)0x0u); /* cmp byte ptr [edx + eax], 0 */
    if (c->zf) goto L_00b2467d; /* je 0xb2467d */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if ((c->sf != c->of)) goto L_00b2466d; /* jl 0xb2466d */
L_00b24678:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
L_00b2467b:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_00b2467d:;
    W8((uint32_t)(c->edx + c->eax), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [edx + eax], 1 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x34u))); /* mov edx, dword ptr [ecx + 0x34] */
    (void)sub32(c, c->eax, c->edx); /* cmp eax, edx */
    if (!c->zf) goto L_00b2467b; /* jne 0xb2467b */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->ecx + 0x34u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 0x34], edx */
    c->esp += 4; return; /* ret  */
}

void f_00b24690(CPU *c) { /* FUN_10004690 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov edx, dword ptr [esi + 0xc] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x11cu)); PUSH32(c, 0x00b246a4u); call_indirect(c, t_); } /* call dword ptr [eax + 0x11c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov edx, dword ptr [esi + 8] */
    W32((uint32_t)(c->esi + 0x2cu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x2c], eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x110u)); PUSH32(c, 0x00b246b8u); call_indirect(c, t_); } /* call dword ptr [eax + 0x110] */
    W32((uint32_t)(c->esi + 0x30u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x30], eax */
    W8((uint32_t)(c->esi + 0x28u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esi + 0x28], 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b246d0(CPU *c) { /* FUN_100046d0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov edx, dword ptr [esi + 0xc] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x120u)); PUSH32(c, 0x00b246e2u); call_indirect(c, t_); } /* call dword ptr [eax + 0x120] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov edx, dword ptr [esi + 8] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x114u)); PUSH32(c, 0x00b246f1u); call_indirect(c, t_); } /* call dword ptr [eax + 0x114] */
    W8((uint32_t)(c->esi + 0x28u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esi + 0x28], 0 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b24700(CPU *c) { /* FUN_10004700 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf != c->of)) goto L_00b2474b; /* jl 0xb2474b */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0x28u))); /* mov dl, byte ptr [ecx + 0x28] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00b2474b; /* je 0xb2474b */
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
    if (c->zf) goto L_00b2475f; /* je 0xb2475f */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x1cu))); /* mov ecx, dword ptr [ecx + 0x1c] */
    { int64_t r_ = (int64_t)(int32_t)c->ecx * (int32_t)c->eax; c->ecx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul ecx, eax */
    W32((uint32_t)(c->edx), (uint32_t)(c->ecx)); /* mov dword ptr [edx], ecx */
    c->esp += 20; return; /* ret 0x10 */
L_00b2474b:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    W32((uint32_t)(c->edx), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [edx], 0 */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [eax], 0 */
L_00b2475f:;
    c->esp += 20; return; /* ret 0x10 */
}

void f_00b24770(CPU *c) { /* FUN_10004770 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0x28u))); /* mov al, byte ptr [ecx + 0x28] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00b247c5; /* jne 0xb247c5 */
    c->edi = (uint32_t)(R32((uint32_t)(c->ecx + 0x34u))); /* mov edi, dword ptr [ecx + 0x34] */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00b247c5; /* je 0xb247c5 */
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
    { uint32_t t_ = R32((uint32_t)(c->ebx + 0xd8u)); PUSH32(c, 0x00b247c0u); call_indirect(c, t_); } /* call dword ptr [ebx + 0xd8] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x28u)); /* add esp, 0x28 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
L_00b247c5:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 8; return; /* ret 4 */
}

void f_00b247d0(CPU *c) { /* FUN_100047d0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x4u)); /* lea ecx, [eax + 4] */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    W32((uint32_t)(c->esi), (uint32_t)(c->edx)); /* mov dword ptr [esi], edx */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 4], edx */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 8], edx */
    W32((uint32_t)(c->ecx + 0xcu), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 0xc], edx */
    W32((uint32_t)(c->ecx + 0x10u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 0x10], edx */
    W32((uint32_t)(c->ecx + 0x14u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 0x14], edx */
    W8((uint32_t)(c->eax + 0x33b4u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [eax + 0x33b4], 1 */
    W32((uint32_t)(c->eax + 0x33b8u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 0x33b8], edx */
    W8((uint32_t)(c->eax + 0x33dcu), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [eax + 0x33dc], dl */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0xb2e220u)); /* mov dword ptr [eax], 0x1000e220 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b24810(CPU *c) { /* FUN_10004810 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00b24818u); f_00b24830(c); /* call 0xb24830 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00b24828; /* je 0xb24828 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b24825u); f_00b21030(c); /* call 0xb21030 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00b24828:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00b24830(CPU *c) { /* FUN_10004830 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    W32((uint32_t)(c->ecx), (uint32_t)((uint32_t)0xb2e220u)); /* mov dword ptr [ecx], 0x1000e220 */
    c->eax = (uint32_t)(R32((uint32_t)(0xb333b4u))); /* mov eax, dword ptr [0x100133b4] */
    c->esi = (uint32_t)((uint32_t)(c->ecx + 0x4u)); /* lea esi, [ecx + 4] */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x60u)); PUSH32(c, 0x00b24853u); call_indirect(c, t_); } /* call dword ptr [edx + 0x60] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b24860(CPU *c) { /* FUN_10004860 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0xb333b4u))); /* mov eax, dword ptr [0x100133b4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    { uint32_t v_ = 0xb3008cu; PUSH32(c, v_); } /* push 0x1001008c */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x58u)); PUSH32(c, 0x00b24876u); call_indirect(c, t_); } /* call dword ptr [edx + 0x58] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (!c->zf) goto L_00b248f0; /* jne 0xb248f0 */
    c->eax = (uint32_t)((uint32_t)0xb300a8u); /* mov eax, 0x100100a8 */
    c->edx = (uint32_t)((uint32_t)(c->esi + 0x33e8u)); /* lea edx, [esi + 0x33e8] */
    W32((uint32_t)(c->esi + 0x33ccu), (uint32_t)((uint32_t)0x14u)); /* mov dword ptr [esi + 0x33cc], 0x14 */
    W32((uint32_t)(c->esi + 0x33c0u), (uint32_t)((uint32_t)0x42700000u)); /* mov dword ptr [esi + 0x33c0], 0x42700000 */
    W32((uint32_t)(c->esi + 0x33c4u), (uint32_t)((uint32_t)0x41f00000u)); /* mov dword ptr [esi + 0x33c4], 0x41f00000 */
    W32((uint32_t)(c->esi + 0x33c8u), (uint32_t)((uint32_t)0x42480000u)); /* mov dword ptr [esi + 0x33c8], 0x42480000 */
    W32((uint32_t)(c->esi + 0x33d0u), (uint32_t)((uint32_t)0x3e8u)); /* mov dword ptr [esi + 0x33d0], 0x3e8 */
    W32((uint32_t)(c->esi + 0x33d4u), (uint32_t)((uint32_t)0x4u)); /* mov dword ptr [esi + 0x33d4], 4 */
    W32((uint32_t)(c->esi + 0x33bcu), (uint32_t)((uint32_t)0x42c80000u)); /* mov dword ptr [esi + 0x33bc], 0x42c80000 */
    W32((uint32_t)(c->esi + 0x33d8u), (uint32_t)((uint32_t)0x4e20u)); /* mov dword ptr [esi + 0x33d8], 0x4e20 */
    W32((uint32_t)(c->esi + 0x33e4u), (uint32_t)((uint32_t)0x3a98u)); /* mov dword ptr [esi + 0x33e4], 0x3a98 */
    c->edx = (uint32_t)(sub32(c, c->edx, c->eax)); /* sub edx, eax */
L_00b248e3:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    W8((uint32_t)(c->edx + c->eax), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [edx + eax], cl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_00b248e3; /* jne 0xb248e3 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_00b248f0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    { uint32_t v_ = 0x42700000u; PUSH32(c, v_); } /* push 0x42700000 */
    { uint32_t v_ = 0xb302dcu; PUSH32(c, v_); } /* push 0x100102dc */
    { uint32_t v_ = 0xb300b4u; PUSH32(c, v_); } /* push 0x100100b4 */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x38u)); PUSH32(c, 0x00b24906u); call_indirect(c, t_); } /* call dword ptr [eax + 0x38] */
    WF32((uint32_t)(c->esi + 0x33c0u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x33c0] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi))); /* mov edx, dword ptr [edi] */
    { uint32_t v_ = 0x41f00000u; PUSH32(c, v_); } /* push 0x41f00000 */
    { uint32_t v_ = 0xb302d0u; PUSH32(c, v_); } /* push 0x100102d0 */
    { uint32_t v_ = 0xb300b4u; PUSH32(c, v_); } /* push 0x100100b4 */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x38u)); PUSH32(c, 0x00b24922u); call_indirect(c, t_); } /* call dword ptr [edx + 0x38] */
    WF32((uint32_t)(c->esi + 0x33c4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x33c4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    { uint32_t v_ = 0x42c80000u; PUSH32(c, v_); } /* push 0x42c80000 */
    { uint32_t v_ = 0xb300e4u; PUSH32(c, v_); } /* push 0x100100e4 */
    { uint32_t v_ = 0xb300b4u; PUSH32(c, v_); } /* push 0x100100b4 */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x38u)); PUSH32(c, 0x00b2493eu); call_indirect(c, t_); } /* call dword ptr [eax + 0x38] */
    WF32((uint32_t)(c->esi + 0x33bcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x33bc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi))); /* mov edx, dword ptr [edi] */
    { uint32_t v_ = 0x42480000u; PUSH32(c, v_); } /* push 0x42480000 */
    { uint32_t v_ = 0xb302c8u; PUSH32(c, v_); } /* push 0x100102c8 */
    { uint32_t v_ = 0xb300b4u; PUSH32(c, v_); } /* push 0x100100b4 */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x38u)); PUSH32(c, 0x00b2495au); call_indirect(c, t_); } /* call dword ptr [edx + 0x38] */
    WF32((uint32_t)(c->esi + 0x33c8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x33c8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    { uint32_t v_ = 0x3e8u; PUSH32(c, v_); } /* push 0x3e8 */
    { uint32_t v_ = 0xb302bcu; PUSH32(c, v_); } /* push 0x100102bc */
    { uint32_t v_ = 0xb300b4u; PUSH32(c, v_); } /* push 0x100100b4 */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x20u)); PUSH32(c, 0x00b24976u); call_indirect(c, t_); } /* call dword ptr [eax + 0x20] */
    W32((uint32_t)(c->esi + 0x33d0u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x33d0], eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi))); /* mov edx, dword ptr [edi] */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = 0xb302b0u; PUSH32(c, v_); } /* push 0x100102b0 */
    { uint32_t v_ = 0xb300b4u; PUSH32(c, v_); } /* push 0x100100b4 */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x20u)); PUSH32(c, 0x00b2498fu); call_indirect(c, t_); } /* call dword ptr [edx + 0x20] */
    W32((uint32_t)(c->esi + 0x33d4u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x33d4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    { uint32_t v_ = 0x4e20u; PUSH32(c, v_); } /* push 0x4e20 */
    { uint32_t v_ = 0xb302a4u; PUSH32(c, v_); } /* push 0x100102a4 */
    { uint32_t v_ = 0xb300b4u; PUSH32(c, v_); } /* push 0x100100b4 */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x20u)); PUSH32(c, 0x00b249abu); call_indirect(c, t_); } /* call dword ptr [eax + 0x20] */
    W32((uint32_t)(c->esi + 0x33d8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x33d8], eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi))); /* mov edx, dword ptr [edi] */
    { uint32_t v_ = 0x3a98u; PUSH32(c, v_); } /* push 0x3a98 */
    { uint32_t v_ = 0xb30298u; PUSH32(c, v_); } /* push 0x10010298 */
    { uint32_t v_ = 0xb300b4u; PUSH32(c, v_); } /* push 0x100100b4 */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x20u)); PUSH32(c, 0x00b249c7u); call_indirect(c, t_); } /* call dword ptr [edx + 0x20] */
    W32((uint32_t)(c->esi + 0x33e4u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x33e4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    { uint32_t v_ = 0x14u; PUSH32(c, v_); } /* push 0x14 */
    { uint32_t v_ = 0xb3028cu; PUSH32(c, v_); } /* push 0x1001028c */
    { uint32_t v_ = 0xb300b4u; PUSH32(c, v_); } /* push 0x100100b4 */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x20u)); PUSH32(c, 0x00b249e0u); call_indirect(c, t_); } /* call dword ptr [eax + 0x20] */
    W32((uint32_t)(c->esi + 0x33ccu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x33cc], eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi))); /* mov edx, dword ptr [edi] */
    { uint32_t v_ = 0xb300a8u; PUSH32(c, v_); } /* push 0x100100a8 */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x33e8u)); /* add esi, 0x33e8 */
    { uint32_t v_ = 0x100u; PUSH32(c, v_); } /* push 0x100 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0xb30280u; PUSH32(c, v_); } /* push 0x10010280 */
    { uint32_t v_ = 0xb300b4u; PUSH32(c, v_); } /* push 0x100100b4 */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00b24a08u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    { uint32_t t_ = R32((uint32_t)(c->eax)); PUSH32(c, 0x00b24a10u); call_indirect(c, t_); } /* call dword ptr [eax] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b24a20(CPU *c) { /* FUN_10004a20 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xb2dfabu; PUSH32(c, v_); } /* push 0x1000dfab */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x250u)); /* sub esp, 0x250 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->esi + 0x3500u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 0x3500], 0 */
    PUSH32(c, 0x00b24a4eu); f_00b24860(c); /* call 0xb24860 */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb333b4u))); /* mov ecx, dword ptr [0x100133b4] */
    { uint32_t v_ = 0xb301c8u; PUSH32(c, v_); } /* push 0x100101c8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4cu)); PUSH32(c, 0x00b24a5eu); call_indirect(c, t_); } /* call dword ptr [eax + 0x4c] */
    W32((uint32_t)(c->esi + 0x33acu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x33ac], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb333b4u))); /* mov ecx, dword ptr [0x100133b4] */
    { uint32_t v_ = 0xb30334u; PUSH32(c, v_); } /* push 0x10010334 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x4cu)); PUSH32(c, 0x00b24a74u); call_indirect(c, t_); } /* call dword ptr [edx + 0x4c] */
    W32((uint32_t)(c->esi + 0x33b0u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x33b0], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x33acu))); /* mov eax, dword ptr [esi + 0x33ac] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b24b18; /* jne 0xb24b18 */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb33398u))); /* mov ecx, dword ptr [0x10013398] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x18u)); PUSH32(c, 0x00b24a93u); call_indirect(c, t_); } /* call dword ptr [eax + 0x18] */
    c->eax = (uint32_t)(R32((uint32_t)(0xb33398u))); /* mov eax, dword ptr [0x10013398] */
    { uint32_t v_ = 0xb301b0u; PUSH32(c, v_); } /* push 0x100101b0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00b24aa3u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(0xb33398u))); /* mov eax, dword ptr [0x10013398] */
    { uint32_t v_ = 0x41u; PUSH32(c, v_); } /* push 0x41 */
    { uint32_t v_ = 0xb30308u; PUSH32(c, v_); } /* push 0x10010308 */
    { uint32_t v_ = 0xb30174u; PUSH32(c, v_); } /* push 0x10010174 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00b24abau); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(0xb33398u))); /* mov eax, dword ptr [0x10013398] */
    { uint32_t v_ = 0xb302e4u; PUSH32(c, v_); } /* push 0x100102e4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00b24acau); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    W32((uint32_t)(c->esp + 0x12cu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x12c], 0 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00b24ada:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0xb302e4u))); /* mov cl, byte ptr [eax + 0x100102e4] */
    W8((uint32_t)(c->esp + c->eax + 0x8u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esp + eax + 8], cl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_00b24ada; /* jne 0xb24ada */
    c->ecx = (uint32_t)((uint32_t)0x4au); /* mov ecx, 0x4a */
    c->esi = (uint32_t)((uint32_t)(c->esp + 0x8u)); /* lea esi, [esp + 8] */
    c->edi = (uint32_t)((uint32_t)(c->esp + 0x130u)); /* lea edi, [esp + 0x130] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x130u)); /* lea edx, [esp + 0x130] */
    { uint32_t v_ = 0xb2eae8u; PUSH32(c, v_); } /* push 0x1000eae8 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    W32((uint32_t)(c->esp + 0x268u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x268], 0 */
    PUSH32(c, 0x00b24b18u); f_00b25a89(c); /* call 0xb25a89 */
L_00b24b18:;
    c->ecx = (uint32_t)(R32((uint32_t)(0xb333b4u))); /* mov ecx, dword ptr [0x100133b4] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    { uint32_t v_ = 0xb301e8u; PUSH32(c, v_); } /* push 0x100101e8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x5cu)); PUSH32(c, 0x00b24b2cu); call_indirect(c, t_); } /* call dword ptr [eax + 0x5c] */
    c->eax = (uint32_t)(R32((uint32_t)(0xb333b4u))); /* mov eax, dword ptr [0x100133b4] */
    { uint32_t v_ = 0xb2e178u; PUSH32(c, v_); } /* push 0x1000e178 */
    { uint32_t v_ = 0x5014u; PUSH32(c, v_); } /* push 0x5014 */
    { uint32_t v_ = 0xb301e4u; PUSH32(c, v_); } /* push 0x100101e4 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x98u)); PUSH32(c, 0x00b24b55u); call_indirect(c, t_); } /* call dword ptr [edx + 0x98] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x280u))); /* mov ecx, dword ptr [esp + 0x280] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x28u)); /* add esp, 0x28 */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x25cu)); /* add esp, 0x25c */
    c->esp += 4; return; /* ret  */
}

void f_00b24b70(CPU *c) { /* FUN_10004b70 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xfffed2d4u)); /* add eax, 0xfffed2d4 */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if ((!c->cf && !c->zf)) { f_00b24be2(c); return; } /* ja 0xb24be2 */
    { uint32_t t_ = R32((uint32_t)(c->eax * 4 + 0xb24be8u)); switch (t_) { case 0x00b24b88u: goto L_00b24b88; case 0x00b24b95u: goto L_00b24b95; case 0x00b24ba7u: goto L_00b24ba7; default: jump_indirect(c, t_, 0x00b24b81u); return; } } /* jmp dword ptr [eax*4 + 0x10004be8] */
L_00b24b88:;
    W8((uint32_t)(c->edi + 0x33b4u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [edi + 0x33b4], 1 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 12; return; /* ret 8 */
L_00b24b95:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W8((uint32_t)(c->edi + 0x33b4u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 0x33b4], al */
    W32((uint32_t)(c->edi + 0x33b8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + 0x33b8], eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 12; return; /* ret 8 */
L_00b24ba7:;
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    PUSH32(c, 0x00b24baeu); f_00b251b0(c); /* call 0xb251b0 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 12; return; /* ret 8 */
}

void f_00b24b88(CPU *c) { /* PTR_00b24b88 */
    PREEMPT_POLL(c);
    W8((uint32_t)(c->edi + 0x33b4u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [edi + 0x33b4], 1 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 12; return; /* ret 8 */
}

void f_00b24b95(CPU *c) { /* PTR_00b24b95 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W8((uint32_t)(c->edi + 0x33b4u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 0x33b4], al */
    W32((uint32_t)(c->edi + 0x33b8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + 0x33b8], eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 12; return; /* ret 8 */
}

void f_00b24ba7(CPU *c) { /* PTR_00b24ba7 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    PUSH32(c, 0x00b24baeu); f_00b251b0(c); /* call 0xb251b0 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 12; return; /* ret 8 */
}

void f_00b24bb4(CPU *c) { /* FUN_10004bb4 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00b24bc0u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x00b24bcbu); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    WF32((uint32_t)(c->esp), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00b24bd6u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    WF32((uint32_t)(c->esp), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp] */
    PUSH32(c, 0x00b24be1u); f_00b25210(c); /* call 0xb25210 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 12; return; /* ret 8 */
}

void f_00b24be2(CPU *c) { /* PTR_00b24be2 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 12; return; /* ret 8 */
}

void f_00b24be8(CPU *c) { /* PTR_00b24be8 */
    PREEMPT_POLL(c);
    W8((uint32_t)(c->ebx), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [ebx], cl */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xa710004bu); W8(a_, (uint8_t)(adc8(c, R8(a_), ((uint8_t)c->edx)))); } /* adc byte ptr [ebp - 0x58efffb5], dl */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)((uint8_t)0x4bu) << 8); /* mov ah, 0x4b */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    ; /* nop  */
    ; /* nop  */
    ; /* nop  */
    ; /* nop  */
    ; /* nop  */
    ; /* nop  */
    ; /* nop  */
    ; /* nop  */
    { f_00b24c00(c); return; }
}

void f_00b24c00(CPU *c) { /* FUN_10004c00 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x38u)); /* sub esp, 0x38 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub8(c, R8((uint32_t)(c->edi + 0x33b4u)), ((uint8_t)c->ebx)); /* cmp byte ptr [edi + 0x33b4], bl */
    if (c->zf) goto L_00b24f43; /* je 0xb24f43 */
    (void)sub8(c, R8((uint32_t)(c->edi + 0x33dcu)), ((uint8_t)c->ebx)); /* cmp byte ptr [edi + 0x33dc], bl */
    if (c->zf) goto L_00b24c6f; /* je 0xb24c6f */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x44u))); /* mov eax, dword ptr [esp + 0x44] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x33e0u))); /* mov ecx, dword ptr [edi + 0x33e0] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    W32((uint32_t)(c->edi + 0x33e0u), (uint32_t)(c->ecx)); /* mov dword ptr [edi + 0x33e0], ecx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if ((!c->zf && c->sf == c->of)) goto L_00b24c6f; /* jg 0xb24c6f */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x33e4u))); /* mov ecx, dword ptr [edi + 0x33e4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x33b8u))); /* mov eax, dword ptr [edi + 0x33b8] */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->ecx)); /* add ecx, ecx */
    W8((uint32_t)(c->edi + 0x33dcu), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [edi + 0x33dc], bl */
    W32((uint32_t)(c->edi + 0x33e4u), (uint32_t)(c->ecx)); /* mov dword ptr [edi + 0x33e4], ecx */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if ((c->zf || c->sf != c->of)) goto L_00b24c6f; /* jle 0xb24c6f */
    c->eax = (uint32_t)((uint32_t)(c->edi + 0x2cu)); /* lea eax, [edi + 0x2c] */
L_00b24c58:;
    FPUSH(c, (double)RF32((uint32_t)(c->eax))); /* fld dword ptr [eax] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb2e19cu))); /* fmul dword ptr [0x1000e19c] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x2cu)); /* add eax, 0x2c */
    WF32((uint32_t)(c->eax + 0xffffffd4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax - 0x2c] */
    (void)sub32(c, c->ecx, R32((uint32_t)(c->edi + 0x33b8u))); /* cmp ecx, dword ptr [edi + 0x33b8] */
    if ((c->sf != c->of)) goto L_00b24c58; /* jl 0xb24c58 */
L_00b24c6f:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x33b8u))); /* mov eax, dword ptr [edi + 0x33b8] */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x20], ebx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if ((c->zf || c->sf != c->of)) goto L_00b24f43; /* jle 0xb24f43 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x44u))); /* mov ecx, dword ptr [esp + 0x44] */
    W32((uint32_t)(c->esp + 0x30u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x30], ebx */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x2c], ecx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    FPUSH(c, (double)(int64_t)R64((uint32_t)(c->esp + 0x30u))); /* fild qword ptr [esp + 0x30] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)((uint32_t)(c->edi + 0x44u)); /* lea esi, [edi + 0x44] */
    WF32((uint32_t)(c->esp + 0x2cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x2c] */
L_00b24c9a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if ((c->zf || c->sf != c->of)) goto L_00b24ca8; /* jle 0xb24ca8 */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->esp + 0x4cu)))); /* sub eax, dword ptr [esp + 0x4c] */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    goto L_00b24d15; /* jmp 0xb24d15 */
L_00b24ca8:;
    c->ebp = (uint32_t)(R32((uint32_t)(c->edi + 0x33e4u))); /* mov ebp, dword ptr [edi + 0x33e4] */
    c->ebp = (uint32_t)(sar32(c, c->ebp, 1)); /* sar ebp, 1 */
    PUSH32(c, 0x00b24cb5u); f_00b258ac(c); /* call 0xb258ac */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0xfffffff4u))); /* fld dword ptr [esi - 0xc] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)c->ebp; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00b24cbbu, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv ebp */
    c->edx = (uint32_t)(add32(c, c->edx, c->ebp)); /* add edx, ebp */
    W32((uint32_t)(c->esi), (uint32_t)(c->edx)); /* mov dword ptr [esi], edx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x33b0u))); /* mov ecx, dword ptr [edi + 0x33b0] */
    (void)sub32(c, c->ecx, c->ebx); /* cmp ecx, ebx */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0xffffffe4u))); /* fmul dword ptr [esi - 0x1c] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0xffffffd8u))); /* fadd dword ptr [esi - 0x28] */
    WF32((uint32_t)(c->esp + 0x3cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x3c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0xfffffff4u))); /* fld dword ptr [esi - 0xc] */
    ST(0) = FTRIG(c, ST(0), cos); /* fcos  */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0xffffffe4u))); /* fmul dword ptr [esi - 0x1c] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0xffffffe0u))); /* fadd dword ptr [esi - 0x20] */
    WF32((uint32_t)(c->esp + 0x40u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x40] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0xffffffecu))); /* fld dword ptr [esi - 0x14] */
    WF32((uint32_t)(c->esp + 0x44u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x44] */
    if (c->zf) goto L_00b24d15; /* je 0xb24d15 */
    { uint32_t v_ = 0x3f800000u; PUSH32(c, v_); } /* push 0x3f800000 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = 0xbf800000u; PUSH32(c, v_); } /* push 0xbf800000 */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x48u)); /* lea eax, [esp + 0x48] */
    { uint32_t v_ = 0xbf800000u; PUSH32(c, v_); } /* push 0xbf800000 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->eax = (uint32_t)((uint32_t)(c->edi + 0x33e8u)); /* lea eax, [edi + 0x33e8] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x1cu)); PUSH32(c, 0x00b24d15u); call_indirect(c, t_); } /* call dword ptr [edx + 0x1c] */
L_00b24d15:;
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0xffffffe8u))); /* fld dword ptr [esi - 0x18] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb2e240u))); /* fmul dword ptr [0x1000e240] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x2cu))); /* fmul dword ptr [esp + 0x2c] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0xfffffff4u))); /* fadd dword ptr [esi - 0xc] */
    FPUSH(c, RF64((uint32_t)(0xb2e238u))); /* fld qword ptr [0x1000e238] */
    PUSH32(c, 0x00b24d30u); f_00b25afa(c); /* call 0xb25afa */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xfffffffcu))); /* mov eax, dword ptr [esi - 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0xfffffff8u))); /* mov ecx, dword ptr [esi - 8] */
    WF32((uint32_t)(c->esi + 0xfffffff4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi - 0xc] */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if ((c->sf == c->of)) goto L_00b24d4b; /* jge 0xb24d4b */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4cu))); /* mov ecx, dword ptr [esp + 0x4c] */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    W32((uint32_t)(c->esi + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [esi - 4], eax */
    goto L_00b24f27; /* jmp 0xb24f27 */
L_00b24d4b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x33c0u))); /* mov eax, dword ptr [edi + 0x33c0] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0xffffffe4u))); /* mov edx, dword ptr [esi - 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x14], edx */
    PUSH32(c, 0x00b24d5eu); f_00b21640(c); /* call 0xb21640 */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0xb2e230u))); /* fadd dword ptr [0x1000e230] */
    W32((uint32_t)(c->esi + 0xfffffffcu), (uint32_t)(c->ebx)); /* mov dword ptr [esi - 4], ebx */
    WF32((uint32_t)(c->esi + 0xffffffe4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi - 0x1c] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->edi + 0x33d0u))); /* fild dword ptr [edi + 0x33d0] */
    WF32((uint32_t)(c->esp), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp] */
    PUSH32(c, 0x00b24d78u); f_00b21640(c); /* call 0xb21640 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    PUSH32(c, 0x00b24d80u); f_00b25ac4(c); /* call 0xb25ac4 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)((uint32_t)0x66666667u); /* mov eax, 0x66666667 */
    W32((uint32_t)(c->esi + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [esi - 8], ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + 0x33d0u))); /* mov edx, dword ptr [edi + 0x33d0] */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)c->edx; c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = r_ != (int32_t)r_; } /* imul edx */
    c->edx = (uint32_t)(sar32(c, c->edx, 3)); /* sar edx, 3 */
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    c->eax = (uint32_t)(shr32(c, c->eax, 31)); /* shr eax, 0x1f */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if ((c->sf == c->of)) goto L_00b24da3; /* jge 0xb24da3 */
    W32((uint32_t)(c->esi + 0xfffffff8u), (uint32_t)(c->edx)); /* mov dword ptr [esi - 8], edx */
L_00b24da3:;
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0xfffffff4u))); /* fld dword ptr [esi - 0xc] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0xfffffff4u))); /* fld dword ptr [esi - 0xc] */
    ST(0) = FTRIG(c, ST(0), cos); /* fcos  */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0xffffffe4u))); /* fadd dword ptr [esi - 0x1c] */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * ST(3)); /* fmul st(3) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0xffffffd8u))); /* fadd dword ptr [esi - 0x28] */
    WF32((uint32_t)(c->esp + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1c] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0xffffffe0u))); /* fadd dword ptr [esi - 0x20] */
    WF32((uint32_t)(c->esp + 0x20u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x20] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esi + 0xffffffe4u))); /* fsub dword ptr [esi - 0x1c] */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * ST(3)); /* fmul st(3) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0xffffffd8u))); /* fadd dword ptr [esi - 0x28] */
    WF32((uint32_t)(c->esp + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x24] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0xffffffe0u))); /* fadd dword ptr [esi - 0x20] */
    WF32((uint32_t)(c->esp + 0x28u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x28] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, (double)RF32((uint32_t)(c->edi + 0x34f0u))); /* fld dword ptr [edi + 0x34f0] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x20u))); /* fsub dword ptr [esp + 0x20] */
    ST(0) = fabs(ST(0)); /* fabs  */
    FPUSH(c, (double)RF32((uint32_t)(c->edi + 0x34e8u))); /* fld dword ptr [edi + 0x34e8] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fsub dword ptr [esp + 0x1c] */
    ST(0) = fabs(ST(0)); /* fabs  */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->esp + 0x34u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x34] */
    FPUSH(c, (double)RF32((uint32_t)(c->edi + 0x34f0u))); /* fld dword ptr [edi + 0x34f0] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x28u))); /* fsub dword ptr [esp + 0x28] */
    ST(0) = fabs(ST(0)); /* fabs  */
    FPUSH(c, (double)RF32((uint32_t)(c->edi + 0x34e8u))); /* fld dword ptr [edi + 0x34e8] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x24u))); /* fsub dword ptr [esp + 0x24] */
    ST(0) = fabs(ST(0)); /* fabs  */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->esp + 0x38u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x38] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, FDIV(c, ST(0), (double)RF32((uint32_t)(c->esi + 0xffffffe4u)))); /* fdiv dword ptr [esi - 0x1c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0xffffffe8u))); /* fmul dword ptr [esi - 0x18] */
    WF32((uint32_t)(c->esi + 0xffffffe8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi - 0x18] */
    FPUSH(c, (double)RF32((uint32_t)(c->edi + 0x33c4u))); /* fld dword ptr [edi + 0x33c4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb2e22cu))); /* fmul dword ptr [0x1000e22c] */
    WF32((uint32_t)(c->esp), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp] */
    PUSH32(c, 0x00b24e4du); f_00b21680(c); /* call 0xb21680 */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); /* fst dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0xffffffe8u))); /* fadd dword ptr [esi - 0x18] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0xffffffe8u))); /* fmul dword ptr [esi - 0x18] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xb2e1e8u))); FPOP(c); /* fcomp dword ptr [0x1000e1e8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00b24e72; /* jp 0xb24e72 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0xffffffe8u))); /* fld dword ptr [esi - 0x18] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x14u))); /* fsub dword ptr [esp + 0x14] */
L_00b24e72:;
    WF32((uint32_t)(c->esi + 0xffffffe8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi - 0x18] */
    FPUSH(c, (double)RF32((uint32_t)(c->edi + 0x33c0u))); /* fld dword ptr [edi + 0x33c0] */
    ST(0) = FPRES(c, FDIV(c, ST(0), (double)RF32((uint32_t)(c->esi + 0xffffffe4u)))); /* fdiv dword ptr [esi - 0x1c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edi + 0x33c4u))); /* fmul dword ptr [edi + 0x33c4] */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); /* fst dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb2e19cu))); /* fmul dword ptr [0x1000e19c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0xffffffe8u))); /* fld dword ptr [esi - 0x18] */
    ST(0) = fabs(ST(0)); /* fabs  */
    { double v_ = ST(1); FPUSH(c, v_); } /* fld st(1) */
    FCOM(c, ST(0), ST(1)); FPOP(c); FPOP(c); /* fcompp  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00b24ec8; /* jne 0xb24ec8 */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0xffffffe8u))); /* fld dword ptr [esi - 0x18] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xb2e1e8u))); FPOP(c); /* fcomp dword ptr [0x1000e1e8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00b24eb7; /* jne 0xb24eb7 */
    WF32((uint32_t)(c->esi + 0xffffffe8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi - 0x18] */
    goto L_00b24eca; /* jmp 0xb24eca */
L_00b24eb7:;
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb2e228u))); /* fmul dword ptr [0x1000e228] */
    WF32((uint32_t)(c->esi + 0xffffffe8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi - 0x18] */
    goto L_00b24eca; /* jmp 0xb24eca */
L_00b24ec8:;
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
L_00b24eca:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x30u))); /* fld dword ptr [esp + 0x30] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->esp + 0x34u))); FPOP(c); /* fcomp dword ptr [esp + 0x34] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00b24f19; /* jp 0xb24f19 */
    PUSH32(c, 0x00b24edeu); f_00b258ac(c); /* call 0xb258ac */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)R32((uint32_t)(c->edi + 0x33d4u)); int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00b24edfu, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv dword ptr [edi + 0x33d4] */
    (void)sub32(c, c->edx, (uint32_t)0x1u); /* cmp edx, 1 */
    if (!c->zf) goto L_00b24f19; /* jne 0xb24f19 */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0xffffffe8u))); /* fld dword ptr [esi - 0x18] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov ecx, dword ptr [esp + 0x18] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov edx, dword ptr [esp + 0x1c] */
    ST(0) = -ST(0); /* fchs  */
    WF32((uint32_t)(c->esi + 0xffffffe8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi - 0x18] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0xfffffff4u))); /* fld dword ptr [esi - 0xc] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0xb2e224u))); /* fadd dword ptr [0x1000e224] */
    FPUSH(c, RF64((uint32_t)(0xb2e238u))); /* fld qword ptr [0x1000e238] */
    W32((uint32_t)(c->esi + 0xffffffd8u), (uint32_t)(c->ecx)); /* mov dword ptr [esi - 0x28], ecx */
    W32((uint32_t)(c->esi + 0xffffffe0u), (uint32_t)(c->edx)); /* mov dword ptr [esi - 0x20], edx */
    PUSH32(c, 0x00b24f14u); f_00b25afa(c); /* call 0xb25afa */
    WF32((uint32_t)(c->esi + 0xfffffff4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi - 0xc] */
    goto L_00b24f27; /* jmp 0xb24f27 */
L_00b24f19:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov eax, dword ptr [esp + 0x20] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov ecx, dword ptr [esp + 0x24] */
    W32((uint32_t)(c->esi + 0xffffffd8u), (uint32_t)(c->eax)); /* mov dword ptr [esi - 0x28], eax */
    W32((uint32_t)(c->esi + 0xffffffe0u), (uint32_t)(c->ecx)); /* mov dword ptr [esi - 0x20], ecx */
L_00b24f27:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov eax, dword ptr [esp + 0x28] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x33b8u))); /* mov ecx, dword ptr [edi + 0x33b8] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x2cu)); /* add esi, 0x2c */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x28], eax */
    if ((c->sf != c->of)) goto L_00b24c9a; /* jl 0xb24c9a */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
L_00b24f43:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x38u)); /* add esp, 0x38 */
    c->esp += 8; return; /* ret 4 */
}

void f_00b24f50(CPU *c) { /* FUN_10004f50 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8cu)); /* sub esp, 0x8c */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->ecx); /* mov ebp, ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0x33b4u))); /* mov al, byte ptr [ebp + 0x33b4] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00b251a2; /* je 0xb251a2 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x33acu))); /* mov ecx, dword ptr [ebp + 0x33ac] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x20u)); /* lea edx, [esp + 0x20] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)((uint32_t)(c->ebp + 0x34f4u)); /* lea edx, [ebp + 0x34f4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->esi = (uint32_t)((uint32_t)(c->ebp + 0x34e8u)); /* lea esi, [ebp + 0x34e8] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x70u)); PUSH32(c, 0x00b24f86u); call_indirect(c, t_); } /* call dword ptr [eax + 0x70] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x33b8u))); /* mov eax, dword ptr [ebp + 0x33b8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b24fa8; /* jne 0xb24fa8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x34f0u))); /* mov eax, dword ptr [ebp + 0x34f0] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x34ecu))); /* mov ecx, dword ptr [ebp + 0x34ec] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    PUSH32(c, 0x00b24fa8u); f_00b25210(c); /* call 0xb25210 */
L_00b24fa8:;
    c->ecx = (uint32_t)(R32((uint32_t)(0xb333b4u))); /* mov ecx, dword ptr [0x100133b4] */
    c->edx = (uint32_t)((uint32_t)(c->ebp + 0x4u)); /* lea edx, [ebp + 4] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x64u)); PUSH32(c, 0x00b24fb7u); call_indirect(c, t_); } /* call dword ptr [eax + 0x64] */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    W32((uint32_t)(c->esp + 0x3cu), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x3c], edx */
    if (c->zf) goto L_00b251a2; /* je 0xb251a2 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x33b8u))); /* mov eax, dword ptr [ebp + 0x33b8] */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x24], 0 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_00b251a2; /* jle 0xb251a2 */
    FPUSH(c, RF64((uint32_t)(0xb2e1c0u))); /* fld qword ptr [0x1000e1c0] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ebx = (uint32_t)((uint32_t)(c->ebp + 0x38u)); /* lea ebx, [ebp + 0x38] */
    WF32((uint32_t)(c->esp + 0x40u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x40] */
    FPUSH(c, RF64((uint32_t)(0xb2e1c0u))); /* fld qword ptr [0x1000e1c0] */
    ST(0) = FTRIG(c, ST(0), cos); /* fcos  */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x40u))); /* mov eax, dword ptr [esp + 0x40] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x18], eax */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x5cu)); /* lea eax, [esp + 0x5c] */
    W32((uint32_t)(c->esp + 0x4cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x4c], eax */
    WF32((uint32_t)(c->esp + 0x38u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x38] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x38u))); /* mov ecx, dword ptr [esp + 0x38] */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x1c], ecx */
    c->ecx = (uint32_t)((uint32_t)(c->edx + 0x20u)); /* lea ecx, [edx + 0x20] */
    W32((uint32_t)(c->esp + 0x48u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x48], ecx */
    goto L_00b2501d; /* jmp 0xb2501d */
L_00b25019:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x44u))); /* mov edx, dword ptr [esp + 0x44] */
L_00b2501d:;
    FPUSH(c, (double)RF32((uint32_t)(c->ebx + 0xfffffff4u))); /* fld dword ptr [ebx - 0xc] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xb2e1e8u))); FPOP(c); /* fcomp dword ptr [0x1000e1e8] */
    FPUSH(c, (double)RF32((uint32_t)(c->ebx))); /* fld dword ptr [ebx] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00b25039; /* jne 0xb25039 */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0xb2e218u))); /* fadd dword ptr [0x1000e218] */
    goto L_00b2503f; /* jmp 0xb2503f */
L_00b25039:;
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0xb2e218u))); /* fsub dword ptr [0x1000e218] */
L_00b2503f:;
    FPUSH(c, (double)RF32((uint32_t)(c->ebx))); /* fld dword ptr [ebx] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x40u))); /* mov ecx, dword ptr [esp + 0x40] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xfffffff8u))); /* mov eax, dword ptr [ebx - 8] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x10], ecx */
    W32((uint32_t)(c->esp + 0x54u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x54], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x38u))); /* mov eax, dword ptr [esp + 0x38] */
    W32((uint32_t)(c->esp + 0x68u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x68], 0 */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    W32((uint32_t)(c->esp + 0x78u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x78], 0 */
    W32((uint32_t)(c->esp + 0x88u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x88], 0 */
    W32((uint32_t)(c->esp + 0x98u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [esp + 0x98], 0x3f800000 */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ebx + 0xfffffff0u))); /* fmul dword ptr [ebx - 0x10] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ebx + 0xffffffe4u))); /* fadd dword ptr [ebx - 0x1c] */
    FPUSH(c, (double)RF32((uint32_t)(c->ebx))); /* fld dword ptr [ebx] */
    ST(0) = FTRIG(c, ST(0), cos); /* fcos  */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ebx + 0xfffffff0u))); /* fmul dword ptr [ebx - 0x10] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ebx + 0xffffffecu))); /* fadd dword ptr [ebx - 0x14] */
    WF32((uint32_t)(c->esp + 0x58u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x58] */
    { double v_ = ST(1); FPUSH(c, v_); } /* fld st(1) */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    { double t_ = ST(0); ST(0) = ST(2); ST(2) = t_; } /* fxch st(2) */
    ST(0) = FTRIG(c, ST(0), cos); /* fcos  */
    WF32((uint32_t)(c->esp + 0x20u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x20] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) * ST(2)); /* fmul st(2) */
    WF32((uint32_t)(c->esp + 0x34u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x34] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fld dword ptr [esp + 0x1c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x20u))); /* fmul dword ptr [esp + 0x20] */
    WF32((uint32_t)(c->esp + 0x3cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x3c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x34u))); /* fld dword ptr [esp + 0x34] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x10u))); /* fmul dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x3cu))); /* fadd dword ptr [esp + 0x3c] */
    WF32((uint32_t)(c->esp + 0x5cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x5c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fld dword ptr [esp + 0x1c] */
    ST(0) = FPRES(c, ST(0) * ST(2)); /* fmul st(2) */
    WF32((uint32_t)(c->esp + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x24] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x20u))); /* fmul dword ptr [esp + 0x20] */
    WF32((uint32_t)(c->esp + 0x30u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x30] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x24u))); /* fld dword ptr [esp + 0x24] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x10u))); /* fmul dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x30u))); /* fsub dword ptr [esp + 0x30] */
    WF32((uint32_t)(c->esp + 0x6cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x6c] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x14u))); /* fmul dword ptr [esp + 0x14] */
    WF32((uint32_t)(c->esp + 0x7cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x7c] */
    WF32((uint32_t)(c->esp + 0x8cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x8c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x14u))); /* fmul dword ptr [esp + 0x14] */
    WF32((uint32_t)(c->esp + 0x60u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x60] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fld dword ptr [esp + 0x1c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x14u))); /* fmul dword ptr [esp + 0x14] */
    WF32((uint32_t)(c->esp + 0x70u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x70] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    ST(0) = -ST(0); /* fchs  */
    WF32((uint32_t)(c->esp + 0x80u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x80] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x54u))); /* fld dword ptr [esp + 0x54] */
    WF32((uint32_t)(c->esp + 0x90u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x90] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x30u))); /* fld dword ptr [esp + 0x30] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x10u))); /* fmul dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x24u))); /* fsub dword ptr [esp + 0x24] */
    WF32((uint32_t)(c->esp + 0x64u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x64] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x3cu))); /* fld dword ptr [esp + 0x3c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x10u))); /* fmul dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x34u))); /* fadd dword ptr [esp + 0x34] */
    WF32((uint32_t)(c->esp + 0x74u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x74] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x20u))); /* fld dword ptr [esp + 0x20] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x14u))); /* fmul dword ptr [esp + 0x14] */
    WF32((uint32_t)(c->esp + 0x84u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x84] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x58u))); /* fld dword ptr [esp + 0x58] */
    WF32((uint32_t)(c->esp + 0x94u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x94] */
    c->df = 0; /* cld  */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x48u))); /* mov edi, dword ptr [esp + 0x48] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x4cu))); /* mov esi, dword ptr [esp + 0x4c] */
    c->ecx = (uint32_t)((uint32_t)0x10u); /* mov ecx, 0x10 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xa0u))); /* mov ecx, dword ptr [esp + 0xa0] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx))); /* mov eax, dword ptr [edx] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0xcu)); PUSH32(c, 0x00b25186u); call_indirect(c, t_); } /* call dword ptr [eax + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov eax, dword ptr [esp + 0x2c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x33b8u))); /* mov ecx, dword ptr [ebp + 0x33b8] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x2cu)); /* add ebx, 0x2c */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x2c], eax */
    if ((c->sf != c->of)) goto L_00b25019; /* jl 0xb25019 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
L_00b251a2:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8cu)); /* add esp, 0x8c */
    c->esp += 8; return; /* ret 4 */
}

void f_00b251b0(CPU *c) { /* FUN_100051b0 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0x33dcu))); /* mov al, byte ptr [ecx + 0x33dc] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00b25200; /* jne 0xb25200 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x33d8u))); /* mov eax, dword ptr [ecx + 0x33d8] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    W32((uint32_t)(c->ecx + 0x33e0u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 0x33e0], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x33b8u))); /* mov eax, dword ptr [ecx + 0x33b8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W8((uint32_t)(c->ecx + 0x33dcu), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ecx + 0x33dc], 1 */
    if ((c->zf || c->sf != c->of)) goto L_00b251fa; /* jle 0xb251fa */
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0x44u)); /* lea eax, [ecx + 0x44] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
L_00b251dd:;
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0xffffffe8u))); /* fld dword ptr [eax - 0x18] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax))); /* mov esi, dword ptr [eax] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x2cu)); /* add eax, 0x2c */
    ST(0) = FPRES(c, ST(0) + ST(0)); /* fadd st(0), st(0) */
    c->esi = (uint32_t)(sar32(c, c->esi, 2)); /* sar esi, 2 */
    W32((uint32_t)(c->eax + 0xffffffd4u), (uint32_t)(c->esi)); /* mov dword ptr [eax - 0x2c], esi */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    WF32((uint32_t)(c->eax + 0xffffffbcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax - 0x44] */
    (void)sub32(c, c->edx, R32((uint32_t)(c->ecx + 0x33b8u))); /* cmp edx, dword ptr [ecx + 0x33b8] */
    if ((c->sf != c->of)) goto L_00b251dd; /* jl 0xb251dd */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00b251fa:;
    { uint32_t a_ = (uint32_t)(c->ecx + 0x33e4u); W32(a_, (uint32_t)(sar32(c, R32(a_), 1))); } /* sar dword ptr [ecx + 0x33e4], 1 */
L_00b25200:;
    c->esp += 4; return; /* ret  */
}

void f_00b25210(CPU *c) { /* FUN_10005210 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x14u)); /* sub esp, 0x14 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esi + 0x33b8u))); /* mov ebx, dword ptr [esi + 0x33b8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x33ccu))); /* mov eax, dword ptr [esi + 0x33cc] */
    c->eax = (uint32_t)(add32(c, c->eax, c->ebx)); /* add eax, ebx */
    (void)sub32(c, c->ebx, c->eax); /* cmp ebx, eax */
    if ((c->sf == c->of)) goto L_00b2534c; /* jge 0xb2534c */
    c->ecx = (uint32_t)((uint32_t)(c->ebx + c->ebx * 4 + 0x5u)); /* lea ecx, [ebx + ebx*4 + 5] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edx = (uint32_t)((uint32_t)(c->ebx + c->ecx * 2 + 0x1u)); /* lea edx, [ebx + ecx*2 + 1] */
    c->edi = (uint32_t)((uint32_t)(c->esi + c->edx * 4)); /* lea edi, [esi + edx*4] */
L_00b25239:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x33bcu))); /* mov eax, dword ptr [esi + 0x33bc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b25245u); f_00b21680(c); /* call 0xb21680 */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x30u))); /* fadd dword ptr [esp + 0x30] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x33c8u))); /* mov ecx, dword ptr [esi + 0x33c8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
    PUSH32(c, 0x00b25259u); f_00b21640(c); /* call 0xb21640 */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0xb2e244u))); /* fadd dword ptr [0x1000e244] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x33bcu))); /* mov edx, dword ptr [esi + 0x33bc] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
    PUSH32(c, 0x00b2526fu); f_00b21680(c); /* call 0xb21680 */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x30u))); /* fadd dword ptr [esp + 0x30] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov ecx, dword ptr [esp + 0x1c] */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x24], eax */
    c->edx = (uint32_t)((uint32_t)(c->edi + 0xfffffff0u)); /* lea edx, [edi - 0x10] */
    WF32((uint32_t)(c->esp + 0x20u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x20] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov eax, dword ptr [esp + 0x20] */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x28], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov ecx, dword ptr [esp + 0x24] */
    W32((uint32_t)(c->edx), (uint32_t)(c->eax)); /* mov dword ptr [edx], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov eax, dword ptr [esp + 0x28] */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [edx + 4], ecx */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [edx + 8], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x33c0u))); /* mov ecx, dword ptr [esi + 0x33c0] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00b252aau); f_00b21660(c); /* call 0xb21660 */
    WF32((uint32_t)(c->edi + 0xfffffffcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi - 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x33c4u))); /* mov edx, dword ptr [esi + 0x33c4] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00b252b9u); f_00b21660(c); /* call 0xb21660 */
    WF32((uint32_t)(c->esp + 0x20u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x20] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    PUSH32(c, 0x00b252c5u); f_00b258ac(c); /* call 0xb258ac */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    if (c->zf) goto L_00b252d1; /* je 0xb252d1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    goto L_00b252d9; /* jmp 0xb252d9 */
L_00b252d1:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xcu))); /* fld dword ptr [esp + 0xc] */
    ST(0) = -ST(0); /* fchs  */
    WF32((uint32_t)(c->edi), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi] */
L_00b252d9:;
    FPUSH(c, (double)RF32((uint32_t)(c->edi + 0xfffffff4u))); /* fld dword ptr [edi - 0xc] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x3500u))); /* fadd dword ptr [esi + 0x3500] */
    { uint32_t v_ = 0x40c90fdbu; PUSH32(c, v_); } /* push 0x40c90fdb */
    WF32((uint32_t)(c->edi + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + 4] */
    PUSH32(c, 0x00b252efu); f_00b21640(c); /* call 0xb21640 */
    WF32((uint32_t)(c->edi + 0xcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + 0xc] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    PUSH32(c, 0x00b252fau); f_00b258ac(c); /* call 0xb258ac */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)R32((uint32_t)(c->esi + 0x33d0u)); int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00b252fbu, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv dword ptr [esi + 0x33d0] */
    W32((uint32_t)(c->edi + 0x10u), (uint32_t)(c->edx)); /* mov dword ptr [edi + 0x10], edx */
    PUSH32(c, 0x00b25309u); f_00b258ac(c); /* call 0xb258ac */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x33e4u))); /* mov ecx, dword ptr [esi + 0x33e4] */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x2cu)); /* add edi, 0x2c */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 3)); /* sar ecx, 3 */
    { int32_t d_ = (int32_t)c->ecx; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00b25316u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv ecx */
    c->edx = (uint32_t)(shl32(c, c->edx, 3)); /* shl edx, 3 */
    W32((uint32_t)(c->edi + 0xffffffecu), (uint32_t)(c->edx)); /* mov dword ptr [edi - 0x14], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x33ccu))); /* mov edx, dword ptr [esi + 0x33cc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x33b8u))); /* mov ecx, dword ptr [esi + 0x33b8] */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    c->edx = (uint32_t)(add32(c, c->edx, c->ecx)); /* add edx, ecx */
    (void)sub32(c, c->ebx, c->edx); /* cmp ebx, edx */
    if ((c->sf != c->of)) goto L_00b25239; /* jl 0xb25239 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x33ccu))); /* mov eax, dword ptr [esi + 0x33cc] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    W32((uint32_t)(c->esi + 0x33b8u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 0x33b8], ecx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esp += 16; return; /* ret 0xc */
L_00b2534c:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x33ccu))); /* mov ecx, dword ptr [esi + 0x33cc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x33b8u))); /* mov eax, dword ptr [esi + 0x33b8] */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    W32((uint32_t)(c->esi + 0x33b8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x33b8], eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esp += 16; return; /* ret 0xc */
}

void f_00b25370(CPU *c) { /* FUN_10005370 */
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
    { uint32_t t_ = c->eax; switch (t_) {  default: jump_indirect(c, t_, 0x00b2539bu); return; } } /* jmp eax */
}

void f_00b2539d(CPU *c) { /* PTR_00b2539d */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 12; return; /* ret 8 */
}

void f_00b253a4(CPU *c) { /* FUN_100053a4 */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { guest_lock(); { uint32_t t0_ = R32((uint32_t)(c->esp)), t1_ = c->eax; W32((uint32_t)(c->esp), (uint32_t)(t1_)); c->eax = (uint32_t)(t0_); } guest_unlock(); } /* xchg dword ptr [esp], eax */
    { uint32_t t_ = c->eax; switch (t_) {  default: jump_indirect(c, t_, 0x00b253a9u); return; } } /* jmp eax */
}

void f_00b253ab(CPU *c) { /* FUN_100053ab */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { guest_lock(); { uint32_t t0_ = R32((uint32_t)(c->esp)), t1_ = c->eax; W32((uint32_t)(c->esp), (uint32_t)(t1_)); c->eax = (uint32_t)(t0_); } guest_unlock(); } /* xchg dword ptr [esp], eax */
    { uint32_t t_ = c->eax; switch (t_) {  default: jump_indirect(c, t_, 0x00b253b0u); return; } } /* jmp eax */
}

void f_00b253b2(CPU *c) { /* FUN_100053b2 */
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
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0xb253dau)); /* mov dword ptr [ebp - 4], 0x100053da */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00b253dau); f_00b2de20(c); /* call 0xb2de20 */
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

void f_00b253da(CPU *c) { /* PTR_00b253da */
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

void f_00b25401(CPU *c) { /* FUN_10005401 */
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
    PUSH32(c, 0x00b25427u); f_00b25ccb(c); /* call 0xb25ccb */
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

void f_00b25437(CPU *c) { /* FUN_10005437 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x14u)); /* sub esp, 0x14 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffecu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x14], 0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)((uint32_t)0xb2548bu)); /* mov dword ptr [ebp - 0x10], 0x1000548b */
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
    PUSH32(c, 0x00b2547cu); f_00b264d0(c); /* call 0xb264d0 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->eax)); /* mov dword ptr fs:[0], eax */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b2548b(CPU *c) { /* FUN_1000548b */
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
    PUSH32(c, 0x00b254abu); f_00b25ccb(c); /* call 0xb25ccb */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00b254b0(CPU *c) { /* FUN_100054b0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x34u)); /* sub esp, 0x34 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffd8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x28], 0 */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)((uint32_t)0xb25566u)); /* mov dword ptr [ebp - 0x24], 0x10005566 */
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
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)((uint32_t)0xb25538u)); /* mov dword ptr [ebp - 0x10], 0x10005538 */
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
    PUSH32(c, 0x00b2552fu); f_00b265a1(c); /* call 0xb265a1 */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x68u)); PUSH32(c, 0x00b25532u); call_indirect(c, t_); } /* call dword ptr [eax + 0x68] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffccu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x34], 0 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if (c->zf) goto L_00b25555; /* je 0xb25555 */
    c->ebx = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov ebx, dword ptr fs:[0] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ebx, dword ptr [ebp - 0x28] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ebx)); /* mov dword ptr fs:[0], ebx */
    goto L_00b2555e; /* jmp 0xb2555e */
L_00b25555:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->eax)); /* mov dword ptr fs:[0], eax */
L_00b2555e:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffccu))); /* mov eax, dword ptr [ebp - 0x34] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b25538(CPU *c) { /* PTR_00b25538 */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if (c->zf) goto L_00b25555; /* je 0xb25555 */
    c->ebx = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov ebx, dword ptr fs:[0] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ebx, dword ptr [ebp - 0x28] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ebx)); /* mov dword ptr fs:[0], ebx */
    goto L_00b2555e; /* jmp 0xb2555e */
L_00b25555:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->eax)); /* mov dword ptr fs:[0], eax */
L_00b2555e:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffccu))); /* mov eax, dword ptr [ebp - 0x34] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b25566(CPU *c) { /* FUN_10005566 */
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
    if (c->zf) goto L_00b25589; /* je 0xb25589 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->eax + 0x24u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [eax + 0x24], 1 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_00b255d6; /* jmp 0xb255d6 */
L_00b25589:;
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
    PUSH32(c, 0x00b255b0u); f_00b25ccb(c); /* call 0xb25ccb */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x24u)), (uint32_t)0x0u); /* cmp dword ptr [eax + 0x24], 0 */
    if (!c->zf) goto L_00b255c7; /* jne 0xb255c7 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x00b255c7u); f_00b253b2(c); /* call 0xb253b2 */
L_00b255c7:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ebx, dword ptr [ebp + 0xc] */
    c->esp = (uint32_t)(R32((uint32_t)(c->ebx + 0x1cu))); /* mov esp, dword ptr [ebx + 0x1c] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ebx + 0x20u))); /* mov ebp, dword ptr [ebx + 0x20] */
    { uint32_t t_ = R32((uint32_t)(c->ebx + 0x18u)); switch (t_) {  default: jump_indirect(c, t_, 0x00b255d0u); return; } } /* jmp dword ptr [ebx + 0x18] */
L_00b255d6:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00b255db(CPU *c) { /* FUN_100055db */
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
    if ((c->sf != c->of)) goto L_00b25632; /* jl 0xb25632 */
L_00b255f9:;
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (!c->zf) goto L_00b25603; /* jne 0xb25603 */
    PUSH32(c, 0x00b25603u); f_00b26709(c); /* call 0xb26709 */
L_00b25603:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi * 4)); /* lea eax, [esi + esi*4] */
    (void)sub32(c, R32((uint32_t)(c->ebx + c->eax * 4 + 0x4u)), c->ecx); /* cmp dword ptr [ebx + eax*4 + 4], ecx */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->eax * 4)); /* lea eax, [ebx + eax*4] */
    if ((c->sf == c->of)) goto L_00b25618; /* jge 0xb25618 */
    (void)sub32(c, c->ecx, R32((uint32_t)(c->eax + 0x8u))); /* cmp ecx, dword ptr [eax + 8] */
    if ((c->zf || c->sf != c->of)) goto L_00b2561d; /* jle 0xb2561d */
L_00b25618:;
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (!c->zf) goto L_00b25629; /* jne 0xb25629 */
L_00b2561d:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
L_00b25629:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    if ((c->sf == c->of)) goto L_00b255f9; /* jge 0xb255f9 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
L_00b25632:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov ecx, dword ptr [ebp + 0x14] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    W32((uint32_t)(c->ecx), (uint32_t)(c->esi)); /* mov dword ptr [ecx], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov ecx, dword ptr [ebp + 0x18] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    (void)sub32(c, c->eax, R32((uint32_t)(c->edi + 0xcu))); /* cmp eax, dword ptr [edi + 0xc] */
    if ((!c->cf && !c->zf)) goto L_00b25646; /* ja 0xb25646 */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if ((c->cf || c->zf)) goto L_00b2564b; /* jbe 0xb2564b */
L_00b25646:;
    PUSH32(c, 0x00b2564bu); f_00b26709(c); /* call 0xb26709 */
L_00b2564b:;
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi * 4)); /* lea eax, [esi + esi*4] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->eax * 4)); /* lea eax, [ebx + eax*4] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b25658(CPU *c) { /* __global_unwind2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0xb25670u; PUSH32(c, v_); } /* push 0x10005670 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00b25670u); f_00b2de20(c); /* call 0xb2de20 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00b25670(CPU *c) { /* PTR_00b25670 */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00b25678(CPU *c) { /* PTR_00b25678 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->ecx + 0x4u)) & (uint32_t)0x6u)); /* test dword ptr [ecx + 4], 6 */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    if (c->zf) goto L_00b25699; /* je 0xb25699 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    W32((uint32_t)(c->edx), (uint32_t)(c->eax)); /* mov dword ptr [edx], eax */
    c->eax = (uint32_t)((uint32_t)0x3u); /* mov eax, 3 */
L_00b25699:;
    c->esp += 4; return; /* ret  */
}

void f_00b2569a(CPU *c) { /* __local_unwind2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0xfffffffeu; PUSH32(c, v_); } /* push -2 */
    { uint32_t v_ = 0xb25678u; PUSH32(c, v_); } /* push 0x10005678 */
    { uint32_t v_ = R32((uint32_t)(0x0u + c->fs_base)); PUSH32(c, v_); } /* push dword ptr fs:[0] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
L_00b256b7:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov eax, dword ptr [esp + 0x20] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ebx, dword ptr [eax + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + 0xcu))); /* mov esi, dword ptr [eax + 0xc] */
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (c->zf) goto L_00b256f4; /* je 0xb256f4 */
    (void)sub32(c, c->esi, R32((uint32_t)(c->esp + 0x24u))); /* cmp esi, dword ptr [esp + 0x24] */
    if (c->zf) goto L_00b256f4; /* je 0xb256f4 */
    c->esi = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea esi, [esi + esi*2] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + c->esi * 4))); /* mov ecx, dword ptr [ebx + esi*4] */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 8], ecx */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0xc], ecx */
    (void)sub32(c, R32((uint32_t)(c->ebx + c->esi * 4 + 0x4u)), (uint32_t)0x0u); /* cmp dword ptr [ebx + esi*4 + 4], 0 */
    if (!c->zf) goto L_00b256f2; /* jne 0xb256f2 */
    { uint32_t v_ = 0x101u; PUSH32(c, v_); } /* push 0x101 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + c->esi * 4 + 0x8u))); /* mov eax, dword ptr [ebx + esi*4 + 8] */
    PUSH32(c, 0x00b256eeu); f_00b2572e(c); /* call 0xb2572e */
    { uint32_t t_ = R32((uint32_t)(c->ebx + c->esi * 4 + 0x8u)); PUSH32(c, 0x00b256f2u); call_indirect(c, t_); } /* call dword ptr [ebx + esi*4 + 8] */
L_00b256f2:;
    goto L_00b256b7; /* jmp 0xb256b7 */
L_00b256f4:;
    { uint32_t v_ = R32(c->esp); c->esp += 4; W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(v_)); } /* pop dword ptr fs:[0] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00b25702(CPU *c) { /* __abnormal_termination */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov ecx, dword ptr fs:[0] */
    (void)sub32(c, R32((uint32_t)(c->ecx + 0x4u)), (uint32_t)0xb25678u); /* cmp dword ptr [ecx + 4], 0x10005678 */
    if (!c->zf) goto L_00b25724; /* jne 0xb25724 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov edx, dword ptr [ecx + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edx + 0xcu))); /* mov edx, dword ptr [edx + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->ecx + 0x8u)), c->edx); /* cmp dword ptr [ecx + 8], edx */
    if (!c->zf) goto L_00b25724; /* jne 0xb25724 */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
L_00b25724:;
    c->esp += 4; return; /* ret  */
}

void f_00b25725(CPU *c) { /* __NLG_Notify1 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ebx = (uint32_t)((uint32_t)0xb30344u); /* mov ebx, 0x10010344 */
    { f_00b25738(c); return; } /* jmp 0xb25738 */
}

void f_00b2572e(CPU *c) { /* FUN_1000572e */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ebx = (uint32_t)((uint32_t)0xb30344u); /* mov ebx, 0x10010344 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebx + 8], ecx */
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 4], eax */
    W32((uint32_t)(c->ebx + 0xcu), (uint32_t)(c->ebp)); /* mov dword ptr [ebx + 0xc], ebp */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
}

void f_00b25738(CPU *c) { /* PTR_00b25738 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebx + 8], ecx */
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 4], eax */
    W32((uint32_t)(c->ebx + 0xcu), (uint32_t)(c->ebp)); /* mov dword ptr [ebx + 0xc], ebp */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
}

void f_00b25746(CPU *c) { /* FUN_10005746 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b2574cu); f_00b26851(c); /* call 0xb26851 */
    { uint32_t v_ = R32((uint32_t)(0xb33b50u)); PUSH32(c, v_); } /* push dword ptr [0x10013b50] */
    PUSH32(c, 0x00b25757u); f_00b26bac(c); /* call 0xb26bac */
    c->edx = (uint32_t)(R32((uint32_t)(0xb33b50u))); /* mov edx, dword ptr [0x10013b50] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb33b4cu))); /* mov ecx, dword ptr [0x10013b4c] */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->esi = (uint32_t)(sub32(c, c->esi, c->edx)); /* sub esi, edx */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (!c->cf) goto L_00b257ac; /* jae 0xb257ac */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00b25775u); f_00b26bac(c); /* call 0xb26bac */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x10u)); /* add eax, 0x10 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(0xb33b50u)); PUSH32(c, v_); } /* push dword ptr [0x10013b50] */
    PUSH32(c, 0x00b25784u); f_00b2687d(c); /* call 0xb2687d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b2578f; /* jne 0xb2578f */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    goto L_00b257bb; /* jmp 0xb257bb */
L_00b2578f:;
    c->ecx = (uint32_t)(R32((uint32_t)(0xb33b4cu))); /* mov ecx, dword ptr [0x10013b4c] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, R32((uint32_t)(0xb33b50u)))); /* sub ecx, dword ptr [0x10013b50] */
    W32((uint32_t)(0xb33b50u), (uint32_t)(c->eax)); /* mov dword ptr [0x10013b50], eax */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 2)); /* sar ecx, 2 */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->ecx * 4)); /* lea ecx, [eax + ecx*4] */
    W32((uint32_t)(0xb33b4cu), (uint32_t)(c->ecx)); /* mov dword ptr [0x10013b4c], ecx */
L_00b257ac:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    { uint32_t a_ = (uint32_t)(0xb33b4cu); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x4u))); } /* add dword ptr [0x10013b4c], 4 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_00b257bb:;
    PUSH32(c, 0x00b257c0u); f_00b2685a(c); /* call 0xb2685a */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b257c4(CPU *c) { /* FUN_100057c4 */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    PUSH32(c, 0x00b257cdu); f_00b25746(c); /* call 0xb25746 */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->esp += 4; return; /* ret  */
}

void f_00b257d6(CPU *c) { /* PTR_00b257d6 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x80u; PUSH32(c, v_); } /* push 0x80 */
    PUSH32(c, 0x00b257e0u); f_00b26c9a(c); /* call 0xb26c9a */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(0xb33b50u), (uint32_t)(c->eax)); /* mov dword ptr [0x10013b50], eax */
    if (!c->zf) goto L_00b257f7; /* jne 0xb257f7 */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    PUSH32(c, 0x00b257f1u); f_00b25c98(c); /* call 0xb25c98 */
    c->eax = (uint32_t)(R32((uint32_t)(0xb33b50u))); /* mov eax, dword ptr [0x10013b50] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b257f7:;
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [eax], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(0xb33b50u))); /* mov eax, dword ptr [0x10013b50] */
    W32((uint32_t)(0xb33b4cu), (uint32_t)(c->eax)); /* mov dword ptr [0x10013b4c], eax */
    c->esp += 4; return; /* ret  */
}

void f_00b25805(CPU *c) { /* FUN_10005805 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
L_00b2580f:;
    (void)sub32(c, R32((uint32_t)(0xb3060cu)), (uint32_t)0x1u); /* cmp dword ptr [0x1001060c], 1 */
    if ((c->zf || c->sf != c->of)) goto L_00b25827; /* jle 0xb25827 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->esi))); /* movzx eax, byte ptr [esi] */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b25823u); f_00b26edb(c); /* call 0xb26edb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00b25836; /* jmp 0xb25836 */
L_00b25827:;
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->esi))); /* movzx eax, byte ptr [esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb30400u))); /* mov ecx, dword ptr [0x10010400] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x8u))); /* and eax, 8 */
L_00b25836:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b2583d; /* je 0xb2583d */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    goto L_00b2580f; /* jmp 0xb2580f */
L_00b2583d:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b25847u); f_00b26e60(c); /* call 0xb26e60 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe8u)); /* lea eax, [ebp - 0x18] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b25853u); f_00b26dd4(c); /* call 0xb26dd4 */
    FPUSH(c, RF64((uint32_t)(c->eax + 0x10u))); /* fld qword ptr [eax + 0x10] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b2585c(CPU *c) { /* FUN_1000585c */
    PREEMPT_POLL(c);
    PUSH32(c, 0x00b25861u); f_00b25874(c); /* call 0xb25874 */
    PUSH32(c, 0x00b25866u); f_00b26fa0(c); /* call 0xb26fa0 */
    W32((uint32_t)(0xb33474u), (uint32_t)(c->eax)); /* mov dword ptr [0x10013474], eax */
    PUSH32(c, 0x00b25870u); f_00b26f50(c); /* call 0xb26f50 */
    c->fpu_sw &= 0x7f00; /* fnclex  */
    c->esp += 4; return; /* ret  */
}

void f_00b25873(CPU *c) { /* PTR_00b25873 */
    PREEMPT_POLL(c);
    c->esp += 4; return; /* ret  */
}

void f_00b25874(CPU *c) { /* FUN_10005874 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb27379u); /* mov eax, 0x10007379 */
    W32((uint32_t)(0xb3061cu), (uint32_t)((uint32_t)0xb27023u)); /* mov dword ptr [0x1001061c], 0x10007023 */
    W32((uint32_t)(0xb30618u), (uint32_t)(c->eax)); /* mov dword ptr [0x10010618], eax */
    W32((uint32_t)(0xb30620u), (uint32_t)((uint32_t)0xb27089u)); /* mov dword ptr [0x10010620], 0x10007089 */
    W32((uint32_t)(0xb30624u), (uint32_t)((uint32_t)0xb26fc9u)); /* mov dword ptr [0x10010624], 0x10006fc9 */
    W32((uint32_t)(0xb30628u), (uint32_t)((uint32_t)0xb27071u)); /* mov dword ptr [0x10010628], 0x10007071 */
    W32((uint32_t)(0xb3062cu), (uint32_t)(c->eax)); /* mov dword ptr [0x1001062c], eax */
    c->esp += 4; return; /* ret  */
}

void f_00b258ac(CPU *c) { /* _rand */
    PREEMPT_POLL(c);
    PUSH32(c, 0x00b258b1u); f_00b265a1(c); /* call 0xb265a1 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x14u))); /* mov ecx, dword ptr [eax + 0x14] */
    { int64_t r_ = (int64_t)(int32_t)c->ecx * (int32_t)(uint32_t)0x343fdu; c->ecx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul ecx, ecx, 0x343fd */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x269ec3u)); /* add ecx, 0x269ec3 */
    W32((uint32_t)(c->eax + 0x14u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x14], ecx */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->eax = (uint32_t)(shr32(c, c->eax, 16)); /* shr eax, 0x10 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fffu))); /* and eax, 0x7fff */
    c->esp += 4; return; /* ret  */
}

void f_00b258ce(CPU *c) { /* FUN_100058ce */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xb2e250u; PUSH32(c, v_); } /* push 0x1000e250 */
    { uint32_t v_ = 0xb273f8u; PUSH32(c, v_); } /* push 0x100073f8 */
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
L_00b258fc:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0x10u))); /* cmp eax, dword ptr [ebp + 0x10] */
    if ((c->sf == c->of)) goto L_00b25917; /* jge 0xb25917 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, 0x00b2590cu); call_indirect(c, t_); } /* call dword ptr [ebp + 0x14] */
    c->esi = (uint32_t)(add32(c, c->esi, R32((uint32_t)(c->ebp + 0xcu)))); /* add esi, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe4u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0x1c] */
    goto L_00b258fc; /* jmp 0xb258fc */
L_00b25917:;
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x20], 1 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b25927u); f_00b25938(c); /* call 0xb25938 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 24; return; /* ret 0x14 */
}

void f_00b25938(CPU *c) { /* FUN_10005938 */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x20], 0 */
    if (!c->zf) goto L_00b2594f; /* jne 0xb2594f */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00b2594fu); f_00b259d0(c); /* call 0xb259d0 */
L_00b2594f:;
    c->esp += 4; return; /* ret  */
}

void f_00b25950(CPU *c) { /* FUN_10005950 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xb2e260u; PUSH32(c, v_); } /* push 0x1000e260 */
    { uint32_t v_ = 0xb273f8u; PUSH32(c, v_); } /* push 0x100073f8 */
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
L_00b25987:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0x10u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 0x10] */
    if (c->sf) goto L_00b25997; /* js 0xb25997 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(sub32(c, R32(a_), c->esi))); } /* sub dword ptr [ebp + 8], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, 0x00b25995u); call_indirect(c, t_); } /* call dword ptr [ebp + 0x14] */
    goto L_00b25987; /* jmp 0xb25987 */
L_00b25997:;
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x1c], 1 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b259a7u); f_00b259b8(c); /* call 0xb259b8 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 20; return; /* ret 0x10 */
}

void f_00b259b8(CPU *c) { /* FUN_100059b8 */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x1c], 0 */
    if (!c->zf) goto L_00b259cf; /* jne 0xb259cf */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00b259cfu); f_00b259d0(c); /* call 0xb259d0 */
L_00b259cf:;
    c->esp += 4; return; /* ret  */
}

void f_00b259d0(CPU *c) { /* FUN_100059d0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xb2e270u; PUSH32(c, v_); } /* push 0x1000e270 */
    { uint32_t v_ = 0xb273f8u; PUSH32(c, v_); } /* push 0x100073f8 */
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
L_00b259f9:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0x10u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 0x10] */
    if (c->sf) goto L_00b25a19; /* js 0xb25a19 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, R32((uint32_t)(c->ebp + 0xcu)))); /* sub ecx, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp + 8], ecx */
    { uint32_t t_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, 0x00b25a0au); call_indirect(c, t_); } /* call dword ptr [ebp + 0x14] */
    goto L_00b259f9; /* jmp 0xb259f9 */
L_00b25a19:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 20; return; /* ret 0x10 */
}

void f_00b25a0c(CPU *c) { /* PTR_00b25a0c */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffecu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x14] */
    PUSH32(c, 0x00b25a14u); f_00b25a2e(c); /* call 0xb25a2e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00b25a16(CPU *c) { /* PTR_00b25a16 */
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

void f_00b25a2e(CPU *c) { /* FUN_10005a2e */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xe06d7363u); /* cmp dword ptr [eax], 0xe06d7363 */
    if (c->zf) goto L_00b25a3f; /* je 0xb25a3f */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_00b25a3f:;
    { f_00b266a8(c); return; } /* jmp 0xb266a8 */
}

void f_00b25a44(CPU *c) { /* FUN_10005a44 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = 0x1bu; PUSH32(c, v_); } /* push 0x1b */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0xb2e280u)); /* mov dword ptr [esi], 0x1000e280 */
    PUSH32(c, 0x00b25a54u); f_00b27565(c); /* call 0xb27565 */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov esi, dword ptr [esi + 4] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00b25a63; /* je 0xb25a63 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b25a62u); f_00b275db(c); /* call 0xb275db */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b25a63:;
    { uint32_t v_ = 0x1bu; PUSH32(c, v_); } /* push 0x1b */
    PUSH32(c, 0x00b25a6au); f_00b275c6(c); /* call 0xb275c6 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b25a6d(CPU *c) { /* type_info::vfunc_0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00b25a75u); f_00b25a44(c); /* call 0xb25a44 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00b25a83; /* je 0xb25a83 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b25a82u); f_00b21030(c); /* call 0xb21030 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b25a83:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00b25a89(CPU *c) { /* __CxxThrowException@8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x20u)); /* sub esp, 0x20 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esi = (uint32_t)((uint32_t)0xb2e288u); /* mov esi, 0x1000e288 */
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
    { uint32_t t_ = R32((uint32_t)(0xb2e004u)); PUSH32(c, 0x00b25abdu); call_indirect(c, t_); } /* call dword ptr [0x1000e004] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 12; return; /* ret 8 */
}

void f_00b25ac4(CPU *c) { /* __ftol */
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

void f_00b25af0(CPU *c) { /* PTR_00b25af0 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)((uint32_t)0xb30390u); /* mov edx, 0x10010390 */
    { f_00b2783b(c); return; } /* jmp 0xb2783b */
}

void f_00b25afa(CPU *c) { /* FUN_10005afa */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)((uint32_t)0xb30390u); /* mov edx, 0x10010390 */
    { f_00b277c0(c); return; } /* jmp 0xb277c0 */
}

void f_00b25b04(CPU *c) { /* PTR_00b25b04 */
    PREEMPT_POLL(c);
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
L_00b25b06:;
    (void)sub32(c, R32((uint32_t)(0xb33474u)), (uint32_t)0x1u); /* cmp dword ptr [0x10013474], 1 */
    if (c->zf) goto L_00b25b13; /* je 0xb25b13 */
    ST(0) = fmod(ST(0), ST(1)); c->fpu_sw &= ~0x0400; /* fprem  */
    goto L_00b25b18; /* jmp 0xb25b18 */
L_00b25b13:;
    PUSH32(c, 0x00b25b18u); f_00b2860c(c); /* call 0xb2860c */
L_00b25b18:;
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    ; /* wait  */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (PF(c)) goto L_00b25b06; /* jp 0xb25b06 */
    ST(1) = ST(0); FPOP(c); /* fstp st(1) */
    c->esp += 4; return; /* ret  */
}

void f_00b25b22(CPU *c) { /* FUN_10005b22 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_00b25bb7; /* jne 0xb25bb7 */
    { uint32_t t_ = R32((uint32_t)(0xb2e00cu)); PUSH32(c, 0x00b25b35u); call_indirect(c, t_); } /* call dword ptr [0x1000e00c] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    W32((uint32_t)(0xb33490u), (uint32_t)(c->eax)); /* mov dword ptr [0x10013490], eax */
    PUSH32(c, 0x00b25b41u); f_00b29148(c); /* call 0xb29148 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00b25b82; /* je 0xb25b82 */
    c->eax = (uint32_t)(R32((uint32_t)(0xb33490u))); /* mov eax, dword ptr [0x10013490] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0xb33491u))); /* mov cl, byte ptr [0x10013491] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xffu))); /* and eax, 0xff */
    { uint32_t a_ = (uint32_t)(0xb33490u); W32(a_, (uint32_t)(shr32(c, R32(a_), 16))); } /* shr dword ptr [0x10013490], 0x10 */
    W32((uint32_t)(0xb33498u), (uint32_t)(c->eax)); /* mov dword ptr [0x10013498], eax */
    W32((uint32_t)(0xb3349cu), (uint32_t)(c->ecx)); /* mov dword ptr [0x1001349c], ecx */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    W32((uint32_t)(0xb33494u), (uint32_t)(c->eax)); /* mov dword ptr [0x10013494], eax */
    PUSH32(c, 0x00b25b79u); f_00b2651c(c); /* call 0xb2651c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b25b86; /* jne 0xb25b86 */
    PUSH32(c, 0x00b25b82u); f_00b291a5(c); /* call 0xb291a5 */
L_00b25b82:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00b25bf8; /* jmp 0xb25bf8 */
L_00b25b86:;
    { uint32_t t_ = R32((uint32_t)(0xb2e008u)); PUSH32(c, 0x00b25b8cu); call_indirect(c, t_); } /* call dword ptr [0x1000e008] */
    W32((uint32_t)(0xb33b54u), (uint32_t)(c->eax)); /* mov dword ptr [0x10013b54], eax */
    PUSH32(c, 0x00b25b96u); f_00b28ea1(c); /* call 0xb28ea1 */
    W32((uint32_t)(0xb3347cu), (uint32_t)(c->eax)); /* mov dword ptr [0x1001347c], eax */
    PUSH32(c, 0x00b25ba0u); f_00b2898b(c); /* call 0xb2898b */
    PUSH32(c, 0x00b25ba5u); f_00b28c54(c); /* call 0xb28c54 */
    PUSH32(c, 0x00b25baau); f_00b28b9b(c); /* call 0xb28b9b */
    PUSH32(c, 0x00b25bafu); f_00b2675f(c); /* call 0xb2675f */
    { uint32_t a_ = (uint32_t)(0xb33478u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [0x10013478] */
    goto L_00b25bf5; /* jmp 0xb25bf5 */
L_00b25bb7:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->zf) goto L_00b25be9; /* jne 0xb25be9 */
    (void)sub32(c, R32((uint32_t)(0xb33478u)), c->ecx); /* cmp dword ptr [0x10013478], ecx */
    if ((c->zf || c->sf != c->of)) goto L_00b25b82; /* jle 0xb25b82 */
    { uint32_t a_ = (uint32_t)(0xb33478u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [0x10013478] */
    (void)sub32(c, R32((uint32_t)(0xb334c8u)), c->ecx); /* cmp dword ptr [0x100134c8], ecx */
    if (!c->zf) goto L_00b25bd8; /* jne 0xb25bd8 */
    PUSH32(c, 0x00b25bd8u); f_00b2679d(c); /* call 0xb2679d */
L_00b25bd8:;
    PUSH32(c, 0x00b25bddu); f_00b28b47(c); /* call 0xb28b47 */
    PUSH32(c, 0x00b25be2u); f_00b26570(c); /* call 0xb26570 */
    PUSH32(c, 0x00b25be7u); f_00b291a5(c); /* call 0xb291a5 */
    goto L_00b25bf5; /* jmp 0xb25bf5 */
L_00b25be9:;
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_00b25bf5; /* jne 0xb25bf5 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00b25bf4u); f_00b26608(c); /* call 0xb26608 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b25bf5:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00b25bf8:;
    c->esp += 16; return; /* ret 0xc */
}

void f_00b25bfb(CPU *c) { /* entry */
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
    if (!c->zf) goto L_00b25c17; /* jne 0xb25c17 */
    (void)sub32(c, R32((uint32_t)(0xb33478u)), (uint32_t)0x0u); /* cmp dword ptr [0x10013478], 0 */
    goto L_00b25c3d; /* jmp 0xb25c3d */
L_00b25c17:;
    (void)sub32(c, c->esi, (uint32_t)0x1u); /* cmp esi, 1 */
    if (c->zf) goto L_00b25c21; /* je 0xb25c21 */
    (void)sub32(c, c->esi, (uint32_t)0x2u); /* cmp esi, 2 */
    if (!c->zf) goto L_00b25c43; /* jne 0xb25c43 */
L_00b25c21:;
    c->eax = (uint32_t)(R32((uint32_t)(0xb33b58u))); /* mov eax, dword ptr [0x10013b58] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b25c33; /* je 0xb25c33 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00b25c2fu); call_indirect(c, t_); } /* call eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b25c3f; /* je 0xb25c3f */
L_00b25c33:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b25c3bu); f_00b25b22(c); /* call 0xb25b22 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
L_00b25c3d:;
    if (!c->zf) goto L_00b25c43; /* jne 0xb25c43 */
L_00b25c3f:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00b25c91; /* jmp 0xb25c91 */
L_00b25c43:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b25c4bu); f_00b2924d(c); /* call 0xb2924d */
    (void)sub32(c, c->esi, (uint32_t)0x1u); /* cmp esi, 1 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0xc], eax */
    if (!c->zf) goto L_00b25c5f; /* jne 0xb25c5f */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b25c8e; /* jne 0xb25c8e */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b25c5fu); f_00b25b22(c); /* call 0xb25b22 */
L_00b25c5f:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00b25c68; /* je 0xb25c68 */
    (void)sub32(c, c->esi, (uint32_t)0x3u); /* cmp esi, 3 */
    if (!c->zf) goto L_00b25c8e; /* jne 0xb25c8e */
L_00b25c68:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b25c70u); f_00b25b22(c); /* call 0xb25b22 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b25c77; /* jne 0xb25c77 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->eax)))); } /* and dword ptr [ebp + 0xc], eax */
L_00b25c77:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    if (c->zf) goto L_00b25c8e; /* je 0xb25c8e */
    c->eax = (uint32_t)(R32((uint32_t)(0xb33b58u))); /* mov eax, dword ptr [0x10013b58] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b25c8e; /* je 0xb25c8e */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00b25c8bu); call_indirect(c, t_); } /* call eax */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0xc], eax */
L_00b25c8e:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
L_00b25c91:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 16; return; /* ret 0xc */
}

void f_00b25c98(CPU *c) { /* __amsg_exit */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0xb33484u))); /* mov eax, dword ptr [0x10013484] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_00b25caf; /* je 0xb25caf */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b25cb4; /* jne 0xb25cb4 */
    (void)sub32(c, R32((uint32_t)(0xb33488u)), (uint32_t)0x1u); /* cmp dword ptr [0x10013488], 1 */
    if (!c->zf) goto L_00b25cb4; /* jne 0xb25cb4 */
L_00b25caf:;
    PUSH32(c, 0x00b25cb4u); f_00b29253(c); /* call 0xb29253 */
L_00b25cb4:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    PUSH32(c, 0x00b25cbdu); f_00b2928c(c); /* call 0xb2928c */
    { uint32_t v_ = 0xffu; PUSH32(c, v_); } /* push 0xff */
    { uint32_t t_ = R32((uint32_t)(0xb303e0u)); PUSH32(c, 0x00b25cc8u); call_indirect(c, t_); } /* call dword ptr [0x100103e0] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00b25cc8(CPU *c) { /* PTR_00b25cc8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00b25ccb(CPU *c) { /* FUN_10005ccb */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov esi, dword ptr [ebp + 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)((uint32_t)0x19930520u); /* mov edi, 0x19930520 */
    (void)sub32(c, R32((uint32_t)(c->esi)), c->edi); /* cmp dword ptr [esi], edi */
    if (c->zf) goto L_00b25ce1; /* je 0xb25ce1 */
    PUSH32(c, 0x00b25ce1u); f_00b26709(c); /* call 0xb26709 */
L_00b25ce1:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + 0x4u)) & (uint8_t)0x66u)); /* test byte ptr [eax + 4], 0x66 */
    if (c->zf) goto L_00b25d09; /* je 0xb25d09 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x4u)), (uint32_t)0x0u); /* cmp dword ptr [esi + 4], 0 */
    if (c->zf) goto L_00b25d5f; /* je 0xb25d5f */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x1c], 0 */
    if (!c->zf) goto L_00b25d5f; /* jne 0xb25d5f */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x00b25d04u); f_00b26020(c); /* call 0xb26020 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    goto L_00b25d5f; /* jmp 0xb25d5f */
L_00b25d09:;
    (void)sub32(c, R32((uint32_t)(c->esi + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [esi + 0xc], 0 */
    if (c->zf) goto L_00b25d5f; /* je 0xb25d5f */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xe06d7363u); /* cmp dword ptr [eax], 0xe06d7363 */
    if (!c->zf) goto L_00b25d43; /* jne 0xb25d43 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x14u)), c->edi); /* cmp dword ptr [eax + 0x14], edi */
    if ((c->cf || c->zf)) goto L_00b25d43; /* jbe 0xb25d43 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x1cu))); /* mov ecx, dword ptr [eax + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov ecx, dword ptr [ecx + 8] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00b25d43; /* je 0xb25d43 */
    c->edx = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0x24u))); /* movzx edx, byte ptr [ebp + 0x24] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = c->ecx; PUSH32(c, 0x00b25d3eu); call_indirect(c, t_); } /* call ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    goto L_00b25d62; /* jmp 0xb25d62 */
L_00b25d43:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x24u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x24] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b25d5cu); f_00b25d66(c); /* call 0xb25d66 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
L_00b25d5f:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00b25d62:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00b25d66(CPU *c) { /* FUN_10005d66 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffecu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp - 0x14], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x10], eax */
    if ((c->sf != c->of)) goto L_00b25d86; /* jl 0xb25d86 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov ecx, dword ptr [ebp + 0x18] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ecx + 0x4u))); /* cmp eax, dword ptr [ecx + 4] */
    if ((c->sf != c->of)) goto L_00b25d8b; /* jl 0xb25d8b */
L_00b25d86:;
    PUSH32(c, 0x00b25d8bu); f_00b26709(c); /* call 0xb26709 */
L_00b25d8b:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    c->ebx = (uint32_t)((uint32_t)0xe06d7363u); /* mov ebx, 0xe06d7363 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)((uint32_t)0x19930520u); /* mov edi, 0x19930520 */
    (void)sub32(c, R32((uint32_t)(c->esi)), c->ebx); /* cmp dword ptr [esi], ebx */
    if (!c->zf) goto L_00b25eee; /* jne 0xb25eee */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [esi + 0x10], 3 */
    if (!c->zf) goto L_00b25e0b; /* jne 0xb25e0b */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x14u)), c->edi); /* cmp dword ptr [esi + 0x14], edi */
    if (!c->zf) goto L_00b25e0b; /* jne 0xb25e0b */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [esi + 0x1c], 0 */
    if (!c->zf) goto L_00b25e0b; /* jne 0xb25e0b */
    PUSH32(c, 0x00b25db9u); f_00b265a1(c); /* call 0xb265a1 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x6cu)), (uint32_t)0x0u); /* cmp dword ptr [eax + 0x6c], 0 */
    if (c->zf) goto L_00b25ee9; /* je 0xb25ee9 */
    PUSH32(c, 0x00b25dc8u); f_00b265a1(c); /* call 0xb265a1 */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + 0x6cu))); /* mov esi, dword ptr [eax + 0x6c] */
    PUSH32(c, 0x00b25dd0u); f_00b265a1(c); /* call 0xb265a1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x70u))); /* mov eax, dword ptr [eax + 0x70] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x10], eax */
    W8((uint32_t)(c->ebp + 0xffffffecu), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ebp - 0x14], 1 */
    PUSH32(c, 0x00b25de2u); f_00b293df(c); /* call 0xb293df */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00b25ded; /* jne 0xb25ded */
    PUSH32(c, 0x00b25dedu); f_00b26709(c); /* call 0xb26709 */
L_00b25ded:;
    (void)sub32(c, R32((uint32_t)(c->esi)), c->ebx); /* cmp dword ptr [esi], ebx */
    if (!c->zf) goto L_00b25eee; /* jne 0xb25eee */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [esi + 0x10], 3 */
    if (!c->zf) goto L_00b25e0b; /* jne 0xb25e0b */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x14u)), c->edi); /* cmp dword ptr [esi + 0x14], edi */
    if (!c->zf) goto L_00b25e0b; /* jne 0xb25e0b */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [esi + 0x1c], 0 */
    if (!c->zf) goto L_00b25e0b; /* jne 0xb25e0b */
    PUSH32(c, 0x00b25e0bu); f_00b26709(c); /* call 0xb26709 */
L_00b25e0b:;
    (void)sub32(c, R32((uint32_t)(c->esi)), c->ebx); /* cmp dword ptr [esi], ebx */
    if (!c->zf) goto L_00b25eee; /* jne 0xb25eee */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [esi + 0x10], 3 */
    if (!c->zf) goto L_00b25eee; /* jne 0xb25eee */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x14u)), c->edi); /* cmp dword ptr [esi + 0x14], edi */
    if (!c->zf) goto L_00b25eee; /* jne 0xb25eee */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov edi, dword ptr [ebp - 0x10] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe8u)); /* lea eax, [ebp - 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    PUSH32(c, 0x00b25e3du); f_00b255db(c); /* call 0xb255db */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
L_00b25e42:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xffffffe8u))); /* cmp eax, dword ptr [ebp - 0x18] */
    if (!c->cf) goto L_00b25ed9; /* jae 0xb25ed9 */
    (void)sub32(c, R32((uint32_t)(c->ebx)), c->edi); /* cmp dword ptr [ebx], edi */
    if ((!c->zf && c->sf == c->of)) goto L_00b25ece; /* jg 0xb25ece */
    (void)sub32(c, c->edi, R32((uint32_t)(c->ebx + 0x4u))); /* cmp edi, dword ptr [ebx + 4] */
    if ((!c->zf && c->sf == c->of)) goto L_00b25ece; /* jg 0xb25ece */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x10u))); /* mov eax, dword ptr [ebx + 0x10] */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xcu))); /* mov eax, dword ptr [ebx + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    if ((c->zf || c->sf != c->of)) goto L_00b25ecb; /* jle 0xb25ecb */
L_00b25e67:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x1cu))); /* mov eax, dword ptr [esi + 0x1c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0xcu))); /* mov eax, dword ptr [eax + 0xc] */
    c->edi = (uint32_t)((uint32_t)(c->eax + 0x4u)); /* lea edi, [eax + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    if ((c->zf || c->sf != c->of)) goto L_00b25e98; /* jle 0xb25e98 */
L_00b25e79:;
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [esi + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->edi)); PUSH32(c, v_); } /* push dword ptr [edi] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00b25e86u); f_00b25fc3(c); /* call 0xb25fc3 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b25ea7; /* jne 0xb25ea7 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 8] */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff8u)), c->eax); /* cmp dword ptr [ebp - 8], eax */
    if ((!c->zf && c->sf == c->of)) goto L_00b25e79; /* jg 0xb25e79 */
L_00b25e98:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff4u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x10u))); } /* add dword ptr [ebp + 8], 0x10 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0xc], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_00b25e67; /* jg 0xb25e67 */
    goto L_00b25ecb; /* jmp 0xb25ecb */
L_00b25ea7:;
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
    PUSH32(c, 0x00b25ec8u); f_00b260be(c); /* call 0xb260be */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
L_00b25ecb:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov edi, dword ptr [ebp - 0x10] */
L_00b25ece:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x14u)); /* add ebx, 0x14 */
    goto L_00b25e42; /* jmp 0xb25e42 */
L_00b25ed9:;
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x1cu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0x1c], 0 */
    if (c->zf) goto L_00b25ee9; /* je 0xb25ee9 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b25ee7u); f_00b26442(c); /* call 0xb26442 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b25ee9:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b25eee:;
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x1cu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0x1c], 0 */
    if (!c->zf) goto L_00b25f14; /* jne 0xb25f14 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x24u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffff0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b25f0fu); f_00b25f19(c); /* call 0xb25f19 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    goto L_00b25ee9; /* jmp 0xb25ee9 */
L_00b25f14:;
    { f_00b266a8(c); return; } /* jmp 0xb266a8 */
}

void f_00b25f19(CPU *c) { /* FUN_10005f19 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b25f25u); f_00b265a1(c); /* call 0xb265a1 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x68u)), (uint32_t)0x0u); /* cmp dword ptr [eax + 0x68], 0 */
    if (c->zf) goto L_00b25f4c; /* je 0xb25f4c */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x24u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00b25f45u); f_00b254b0(c); /* call 0xb254b0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b25fbf; /* jne 0xb25fbf */
L_00b25f4c:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov edi, dword ptr [ebp + 0x1c] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    PUSH32(c, 0x00b25f63u); f_00b255db(c); /* call 0xb255db */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_00b25f68:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xfffffff8u))); /* cmp eax, dword ptr [ebp - 8] */
    if (!c->cf) goto L_00b25fbf; /* jae 0xb25fbf */
    (void)sub32(c, c->edi, R32((uint32_t)(c->esi))); /* cmp edi, dword ptr [esi] */
    if ((c->sf != c->of)) goto L_00b25fb7; /* jl 0xb25fb7 */
    (void)sub32(c, c->edi, R32((uint32_t)(c->esi + 0x4u))); /* cmp edi, dword ptr [esi + 4] */
    if ((!c->zf && c->sf == c->of)) goto L_00b25fb7; /* jg 0xb25fb7 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0xfffffff4u))); /* mov ecx, dword ptr [eax - 0xc] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00b25f91; /* je 0xb25f91 */
    (void)sub8(c, R8((uint32_t)(c->ecx + 0x8u)), (uint8_t)0x0u); /* cmp byte ptr [ecx + 8], 0 */
    if (!c->zf) goto L_00b25fb7; /* jne 0xb25fb7 */
L_00b25f91:;
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
    PUSH32(c, 0x00b25fb4u); f_00b260be(c); /* call 0xb260be */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
L_00b25fb7:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x14u)); /* add esi, 0x14 */
    goto L_00b25f68; /* jmp 0xb25f68 */
L_00b25fbf:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b25fc3(CPU *c) { /* FUN_10005fc3 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edi, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov eax, dword ptr [edi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b2601a; /* je 0xb2601a */
    (void)sub8(c, R8((uint32_t)(c->eax + 0x8u)), (uint8_t)0x0u); /* cmp byte ptr [eax + 8], 0 */
    c->edx = (uint32_t)((uint32_t)(c->eax + 0x8u)); /* lea edx, [eax + 8] */
    if (c->zf) goto L_00b2601a; /* je 0xb2601a */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (c->zf) goto L_00b25ff4; /* je 0xb25ff4 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x8u)); /* add ecx, 8 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00b25feeu); f_00b276d0(c); /* call 0xb276d0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00b26016; /* jne 0xb26016 */
L_00b25ff4:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi)) & (uint8_t)0x2u)); /* test byte ptr [esi], 2 */
    if (c->zf) goto L_00b25ffe; /* je 0xb25ffe */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edi)) & (uint8_t)0x8u)); /* test byte ptr [edi], 8 */
    if (c->zf) goto L_00b26016; /* je 0xb26016 */
L_00b25ffe:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    if (c->zf) goto L_00b2600d; /* je 0xb2600d */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edi)) & (uint8_t)0x1u)); /* test byte ptr [edi], 1 */
    if (c->zf) goto L_00b26016; /* je 0xb26016 */
L_00b2600d:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x2u)); /* test al, 2 */
    if (c->zf) goto L_00b2601a; /* je 0xb2601a */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edi)) & (uint8_t)0x2u)); /* test byte ptr [edi], 2 */
    if (!c->zf) goto L_00b2601a; /* jne 0xb2601a */
L_00b26016:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00b2601d; /* jmp 0xb2601d */
L_00b2601a:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00b2601d:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b26020(CPU *c) { /* FUN_10006020 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xb2e2a8u; PUSH32(c, v_); } /* push 0x1000e2a8 */
    { uint32_t v_ = 0xb273f8u; PUSH32(c, v_); } /* push 0x100073f8 */
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
L_00b26052:;
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0x14u))); /* cmp esi, dword ptr [ebp + 0x14] */
    if (c->zf) goto L_00b260ac; /* je 0xb260ac */
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if ((c->zf || c->sf != c->of)) goto L_00b26061; /* jle 0xb26061 */
    (void)sub32(c, c->esi, R32((uint32_t)(c->edi + 0x4u))); /* cmp esi, dword ptr [edi + 4] */
    if ((c->sf != c->of)) goto L_00b26066; /* jl 0xb26066 */
L_00b26061:;
    PUSH32(c, 0x00b26066u); f_00b26709(c); /* call 0xb26709 */
L_00b26066:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8 + 0x4u))); /* mov eax, dword ptr [eax + esi*8 + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b26081; /* je 0xb26081 */
    { uint32_t v_ = 0x103u; PUSH32(c, v_); } /* push 0x103 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b26081u); f_00b264d0(c); /* call 0xb264d0 */
L_00b26081:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    goto L_00b260a1; /* jmp 0xb260a1 */
L_00b260a1:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8))); /* mov esi, dword ptr [eax + esi*8] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x1c], esi */
    goto L_00b26052; /* jmp 0xb26052 */
L_00b260ac:;
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebx + 8], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b26052(CPU *c) { /* PTR_00b26052 */
    PREEMPT_POLL(c);
L_00b26052:;
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0x14u))); /* cmp esi, dword ptr [ebp + 0x14] */
    if (c->zf) goto L_00b260ac; /* je 0xb260ac */
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if ((c->zf || c->sf != c->of)) goto L_00b26061; /* jle 0xb26061 */
    (void)sub32(c, c->esi, R32((uint32_t)(c->edi + 0x4u))); /* cmp esi, dword ptr [edi + 4] */
    if ((c->sf != c->of)) goto L_00b26066; /* jl 0xb26066 */
L_00b26061:;
    PUSH32(c, 0x00b26066u); f_00b26709(c); /* call 0xb26709 */
L_00b26066:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8 + 0x4u))); /* mov eax, dword ptr [eax + esi*8 + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b26081; /* je 0xb26081 */
    { uint32_t v_ = 0x103u; PUSH32(c, v_); } /* push 0x103 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b26081u); f_00b264d0(c); /* call 0xb264d0 */
L_00b26081:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    goto L_00b260a1; /* jmp 0xb260a1 */
L_00b260a1:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8))); /* mov esi, dword ptr [eax + esi*8] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x1c], esi */
    goto L_00b26052; /* jmp 0xb26052 */
L_00b260ac:;
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebx + 8], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b26087(CPU *c) { /* PTR_00b26087 */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffecu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x14] */
    PUSH32(c, 0x00b2608fu); f_00b25a2e(c); /* call 0xb25a2e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00b26091(CPU *c) { /* PTR_00b26091 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edi, dword ptr [ebp + 0x10] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov esi, dword ptr [ebp - 0x1c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8))); /* mov esi, dword ptr [eax + esi*8] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x1c], esi */
    { f_00b26052(c); return; } /* jmp 0xb26052 */
}

void f_00b260be(CPU *c) { /* FUN_100060be */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x20u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x20], 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov ebx, dword ptr [ebp + 0x1c] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    if (c->zf) goto L_00b260e0; /* je 0xb260e0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00b260ddu); f_00b2627e(c); /* call 0xb2627e */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_00b260e0:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x2cu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x2c], 0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    if (!c->zf) goto L_00b260ec; /* jne 0xb260ec */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    goto L_00b260ef; /* jmp 0xb260ef */
L_00b260ec:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x2cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x2c] */
L_00b260ef:;
    PUSH32(c, 0x00b260f4u); f_00b253b2(c); /* call 0xb253b2 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x24u))); /* mov esi, dword ptr [ebp + 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b26105u); f_00b26020(c); /* call 0xb26020 */
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
    PUSH32(c, 0x00b26126u); f_00b26139(c); /* call 0xb26139 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b26134; /* je 0xb26134 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b26134u); f_00b25370(c); /* call 0xb25370 */
L_00b26134:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00b26139(CPU *c) { /* FUN_10006139 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xb2e2b8u; PUSH32(c, v_); } /* push 0x1000e2b8 */
    { uint32_t v_ = 0xb273f8u; PUSH32(c, v_); } /* push 0x100073f8 */
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
    PUSH32(c, 0x00b26177u); f_00b265a1(c); /* call 0xb265a1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x6cu))); /* mov eax, dword ptr [eax + 0x6c] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    PUSH32(c, 0x00b26182u); f_00b265a1(c); /* call 0xb265a1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x70u))); /* mov eax, dword ptr [eax + 0x70] */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    PUSH32(c, 0x00b2618du); f_00b265a1(c); /* call 0xb265a1 */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    W32((uint32_t)(c->eax + 0x6cu), (uint32_t)(c->edi)); /* mov dword ptr [eax + 0x6c], edi */
    PUSH32(c, 0x00b26198u); f_00b265a1(c); /* call 0xb265a1 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    W32((uint32_t)(c->eax + 0x70u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x70], ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b261b9u); f_00b25437(c); /* call 0xb25437 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x2c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b261ccu); f_00b26206(c); /* call 0xb26206 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd4u))); /* mov eax, dword ptr [ebp - 0x2c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b261cf(CPU *c) { /* PTR_00b261cf */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b261de(CPU *c) { /* PTR_00b261de */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffecu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x14] */
    PUSH32(c, 0x00b261e6u); f_00b26254(c); /* call 0xb26254 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00b261e8(CPU *c) { /* PTR_00b261e8 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffd4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x2c], 0 */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b261fau); f_00b2569a(c); /* call 0xb2569a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { f_00b261cf(c); return; } /* jmp 0xb261cf */
}

void f_00b26200(CPU *c) { /* PTR_00b26200 */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    { f_00b26206(c); return; }
}

void f_00b26206(CPU *c) { /* FUN_10006206 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    W32((uint32_t)(c->esi + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [esi - 4], eax */
    PUSH32(c, 0x00b26211u); f_00b265a1(c); /* call 0xb265a1 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov ecx, dword ptr [ebp - 0x1c] */
    W32((uint32_t)(c->eax + 0x6cu), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x6c], ecx */
    PUSH32(c, 0x00b2621cu); f_00b265a1(c); /* call 0xb265a1 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov ecx, dword ptr [ebp - 0x20] */
    W32((uint32_t)(c->eax + 0x70u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x70], ecx */
    (void)sub32(c, R32((uint32_t)(c->edi)), (uint32_t)0xe06d7363u); /* cmp dword ptr [edi], 0xe06d7363 */
    if (!c->zf) goto L_00b26253; /* jne 0xb26253 */
    (void)sub32(c, R32((uint32_t)(c->edi + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [edi + 0x10], 3 */
    if (!c->zf) goto L_00b26253; /* jne 0xb26253 */
    (void)sub32(c, R32((uint32_t)(c->edi + 0x14u)), (uint32_t)0x19930520u); /* cmp dword ptr [edi + 0x14], 0x19930520 */
    if (!c->zf) goto L_00b26253; /* jne 0xb26253 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00b26253; /* jne 0xb26253 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x2c], 0 */
    if (c->zf) goto L_00b26253; /* je 0xb26253 */
    PUSH32(c, 0x00b2624au); f_00b25702(c); /* call 0xb25702 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b26251u); f_00b26442(c); /* call 0xb26442 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b26253:;
    c->esp += 4; return; /* ret  */
}

void f_00b26254(CPU *c) { /* FUN_10006254 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xe06d7363u); /* cmp dword ptr [eax], 0xe06d7363 */
    if (!c->zf) goto L_00b2627b; /* jne 0xb2627b */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [eax + 0x10], 3 */
    if (!c->zf) goto L_00b2627b; /* jne 0xb2627b */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x14u)), (uint32_t)0x19930520u); /* cmp dword ptr [eax + 0x14], 0x19930520 */
    if (!c->zf) goto L_00b2627b; /* jne 0xb2627b */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [eax + 0x1c], 0 */
    if (!c->zf) goto L_00b2627b; /* jne 0xb2627b */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
L_00b2627b:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_00b2627e(CPU *c) { /* FUN_1000627e */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xb2e2d0u; PUSH32(c, v_); } /* push 0x1000e2d0 */
    { uint32_t v_ = 0xb273f8u; PUSH32(c, v_); } /* push 0x100073f8 */
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
    if (c->zf) goto L_00b26427; /* je 0xb26427 */
    (void)sub8(c, R8((uint32_t)(c->eax + 0x8u)), (uint8_t)0x0u); /* cmp byte ptr [eax + 8], 0 */
    if (c->zf) goto L_00b26427; /* je 0xb26427 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov eax, dword ptr [ecx + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b26427; /* je 0xb26427 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
    c->edi = (uint32_t)((uint32_t)(c->eax + c->edx + 0xcu)); /* lea edi, [eax + edx + 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ecx)) & (uint8_t)0x8u)); /* test byte ptr [ecx], 8 */
    if (c->zf) goto L_00b2631b; /* je 0xb2631b */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x18] */
    PUSH32(c, 0x00b262e4u); f_00b293df(c); /* call 0xb293df */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b2641e; /* je 0xb2641e */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b262f6u); f_00b293fb(c); /* call 0xb293fb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b2641e; /* je 0xb2641e */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x18u))); /* mov eax, dword ptr [esi + 0x18] */
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov ecx, dword ptr [ebp + 0x14] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x8u)); /* add ecx, 8 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
L_00b2630c:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b26312u); f_00b264a9(c); /* call 0xb264a9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    goto L_00b26423; /* jmp 0xb26423 */
L_00b2631b:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov esi, dword ptr [ebp + 0x14] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi)) & (uint8_t)0x1u)); /* test byte ptr [esi], 1 */
    if (c->zf) goto L_00b26375; /* je 0xb26375 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    PUSH32(c, 0x00b26330u); f_00b293df(c); /* call 0xb293df */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b2641e; /* je 0xb2641e */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b26342u); f_00b293fb(c); /* call 0xb293fb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b2641e; /* je 0xb2641e */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x14u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b26358u); f_00b29430(c); /* call 0xb29430 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x14u)), (uint32_t)0x4u); /* cmp dword ptr [esi + 0x14], 4 */
    if (!c->zf) goto L_00b26423; /* jne 0xb26423 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b26423; /* je 0xb26423 */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x8u)); /* add esi, 8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    goto L_00b2630c; /* jmp 0xb2630c */
L_00b26375:;
    (void)sub32(c, R32((uint32_t)(c->esi + 0x18u)), (uint32_t)0x0u); /* cmp dword ptr [esi + 0x18], 0 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    if (!c->zf) goto L_00b263bd; /* jne 0xb263bd */
    PUSH32(c, 0x00b26388u); f_00b293df(c); /* call 0xb293df */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b2641e; /* je 0xb2641e */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b2639au); f_00b293fb(c); /* call 0xb293fb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b2641e; /* je 0xb2641e */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x14u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x14] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x8u)); /* add esi, 8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    PUSH32(c, 0x00b263afu); f_00b264a9(c); /* call 0xb264a9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b263b8u); f_00b29430(c); /* call 0xb29430 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_00b26423; /* jmp 0xb26423 */
L_00b263bd:;
    PUSH32(c, 0x00b263c2u); f_00b293df(c); /* call 0xb293df */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b2641e; /* je 0xb2641e */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b263d0u); f_00b293fb(c); /* call 0xb293fb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b2641e; /* je 0xb2641e */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x18] */
    PUSH32(c, 0x00b263deu); f_00b29417(c); /* call 0xb29417 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b2641e; /* je 0xb2641e */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi)) & (uint8_t)0x4u)); /* test byte ptr [esi], 4 */
    if (c->zf) goto L_00b26404; /* je 0xb26404 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x8u)); /* lea eax, [esi + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    PUSH32(c, 0x00b263f6u); f_00b264a9(c); /* call 0xb264a9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b26402u); f_00b253ab(c); /* call 0xb253ab */
    goto L_00b26423; /* jmp 0xb26423 */
L_00b26404:;
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x8u)); /* lea eax, [esi + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    PUSH32(c, 0x00b26410u); f_00b264a9(c); /* call 0xb264a9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b2641cu); f_00b253a4(c); /* call 0xb253a4 */
    goto L_00b26423; /* jmp 0xb26423 */
L_00b2641e:;
    PUSH32(c, 0x00b26423u); f_00b26709(c); /* call 0xb26709 */
L_00b26423:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
L_00b26427:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b26436(CPU *c) { /* PTR_00b26436 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_00b2643a(CPU *c) { /* PTR_00b2643a */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { f_00b266a8(c); return; } /* jmp 0xb266a8 */
}

void f_00b26442(CPU *c) { /* FUN_10006442 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xb2e2e0u; PUSH32(c, v_); } /* push 0x1000e2e0 */
    { uint32_t v_ = 0xb273f8u; PUSH32(c, v_); } /* push 0x100073f8 */
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
    if (c->zf) goto L_00b26489; /* je 0xb26489 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x1cu))); /* mov ecx, dword ptr [eax + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ecx, dword ptr [ecx + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00b26489; /* je 0xb26489 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = R32((uint32_t)(c->eax + 0x18u)); PUSH32(c, v_); } /* push dword ptr [eax + 0x18] */
    PUSH32(c, 0x00b26485u); f_00b253a4(c); /* call 0xb253a4 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
L_00b26489:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b26498(CPU *c) { /* PTR_00b26498 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xcu)), ((uint8_t)c->eax)); /* cmp byte ptr [ebp + 0xc], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(!c->zf ? 1 : 0); /* setne al */
    c->esp += 4; return; /* ret  */
}

void f_00b264a1(CPU *c) { /* PTR_00b264a1 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { f_00b266a8(c); return; } /* jmp 0xb266a8 */
}

void f_00b264a9(CPU *c) { /* FUN_100064a9 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov edx, dword ptr [ecx + 4] */
    c->eax = (uint32_t)(add32(c, c->eax, c->esi)); /* add eax, esi */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if ((c->sf != c->of)) goto L_00b264ca; /* jl 0xb264ca */
    c->esi = (uint32_t)(R32((uint32_t)(c->edx + c->esi))); /* mov esi, dword ptr [edx + esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov ecx, dword ptr [ecx + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + c->ecx))); /* mov ecx, dword ptr [esi + ecx] */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->edx)); /* add ecx, edx */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
L_00b264ca:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b264d0(CPU *c) { /* __CallSettingFrame@12 */
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
    PUSH32(c, 0x00b264f3u); f_00b25725(c); /* call 0xb25725 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00b264f7u); call_indirect(c, t_); } /* call eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->ebx = (uint32_t)(c->ebp); /* mov ebx, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->ebx); /* mov ebp, ebx */
    (void)sub32(c, c->ecx, (uint32_t)0x100u); /* cmp ecx, 0x100 */
    if (!c->zf) goto L_00b2650f; /* jne 0xb2650f */
    c->ecx = (uint32_t)((uint32_t)0x2u); /* mov ecx, 2 */
L_00b2650f:;
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00b26515u); f_00b25725(c); /* call 0xb25725 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 16; return; /* ret 0xc */
}

void f_00b2651c(CPU *c) { /* FUN_1000651c */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b26522u); f_00b274d0(c); /* call 0xb274d0 */
    { uint32_t t_ = R32((uint32_t)(0xb2e018u)); PUSH32(c, 0x00b26528u); call_indirect(c, t_); } /* call dword ptr [0x1000e018] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    W32((uint32_t)(0xb303f0u), (uint32_t)(c->eax)); /* mov dword ptr [0x100103f0], eax */
    if (c->zf) goto L_00b2656c; /* je 0xb2656c */
    { uint32_t v_ = 0x74u; PUSH32(c, v_); } /* push 0x74 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x00b2653bu); f_00b29765(c); /* call 0xb29765 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00b2656c; /* je 0xb2656c */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(0xb303f0u)); PUSH32(c, v_); } /* push dword ptr [0x100103f0] */
    { uint32_t t_ = R32((uint32_t)(0xb2e014u)); PUSH32(c, 0x00b26550u); call_indirect(c, t_); } /* call dword ptr [0x1000e014] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b2656c; /* je 0xb2656c */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b2655au); f_00b2658e(c); /* call 0xb2658e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t t_ = R32((uint32_t)(0xb2e010u)); PUSH32(c, 0x00b26561u); call_indirect(c, t_); } /* call dword ptr [0x1000e010] */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [esi + 4], 0xffffffff */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_00b2656c:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b26570(CPU *c) { /* FUN_10006570 */
    PREEMPT_POLL(c);
    PUSH32(c, 0x00b26575u); f_00b274f9(c); /* call 0xb274f9 */
    c->eax = (uint32_t)(R32((uint32_t)(0xb303f0u))); /* mov eax, dword ptr [0x100103f0] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (c->zf) goto L_00b2658d; /* je 0xb2658d */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0xb2e01cu)); PUSH32(c, 0x00b26586u); call_indirect(c, t_); } /* call dword ptr [0x1000e01c] */
    { uint32_t a_ = (uint32_t)(0xb303f0u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [0x100103f0], 0xffffffff */
L_00b2658d:;
    c->esp += 4; return; /* ret  */
}

void f_00b2658e(CPU *c) { /* FUN_1000658e */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    W32((uint32_t)(c->eax + 0x50u), (uint32_t)((uint32_t)0xb30940u)); /* mov dword ptr [eax + 0x50], 0x10010940 */
    W32((uint32_t)(c->eax + 0x14u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [eax + 0x14], 1 */
    c->esp += 4; return; /* ret  */
}

void f_00b265a1(CPU *c) { /* FUN_100065a1 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0xb2e028u)); PUSH32(c, 0x00b265a9u); call_indirect(c, t_); } /* call dword ptr [0x1000e028] */
    { uint32_t v_ = R32((uint32_t)(0xb303f0u)); PUSH32(c, v_); } /* push dword ptr [0x100103f0] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    { uint32_t t_ = R32((uint32_t)(0xb2e024u)); PUSH32(c, 0x00b265b7u); call_indirect(c, t_); } /* call dword ptr [0x1000e024] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_00b265fc; /* jne 0xb265fc */
    { uint32_t v_ = 0x74u; PUSH32(c, v_); } /* push 0x74 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x00b265c6u); f_00b29765(c); /* call 0xb29765 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00b265f4; /* je 0xb265f4 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(0xb303f0u)); PUSH32(c, v_); } /* push dword ptr [0x100103f0] */
    { uint32_t t_ = R32((uint32_t)(0xb2e014u)); PUSH32(c, 0x00b265dbu); call_indirect(c, t_); } /* call dword ptr [0x1000e014] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b265f4; /* je 0xb265f4 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b265e5u); f_00b2658e(c); /* call 0xb2658e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t t_ = R32((uint32_t)(0xb2e010u)); PUSH32(c, 0x00b265ecu); call_indirect(c, t_); } /* call dword ptr [0x1000e010] */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [esi + 4], 0xffffffff */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    goto L_00b265fc; /* jmp 0xb265fc */
L_00b265f4:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    PUSH32(c, 0x00b265fbu); f_00b25c98(c); /* call 0xb25c98 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b265fc:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0xb2e020u)); PUSH32(c, 0x00b26603u); call_indirect(c, t_); } /* call dword ptr [0x1000e020] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b26608(CPU *c) { /* FUN_10006608 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0xb303f0u))); /* mov eax, dword ptr [0x100103f0] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (c->zf) goto L_00b266a7; /* je 0xb266a7 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_00b2662c; /* jne 0xb2662c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0xb2e024u)); PUSH32(c, 0x00b26626u); call_indirect(c, t_); } /* call dword ptr [0x1000e024] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00b26698; /* je 0xb26698 */
L_00b2662c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov eax, dword ptr [esi + 0x24] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b2663a; /* je 0xb2663a */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b26639u); f_00b275db(c); /* call 0xb275db */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b2663a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x28u))); /* mov eax, dword ptr [esi + 0x28] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b26648; /* je 0xb26648 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b26647u); f_00b275db(c); /* call 0xb275db */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b26648:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x30u))); /* mov eax, dword ptr [esi + 0x30] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b26656; /* je 0xb26656 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b26655u); f_00b275db(c); /* call 0xb275db */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b26656:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x38u))); /* mov eax, dword ptr [esi + 0x38] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b26664; /* je 0xb26664 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b26663u); f_00b275db(c); /* call 0xb275db */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b26664:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x40u))); /* mov eax, dword ptr [esi + 0x40] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b26672; /* je 0xb26672 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b26671u); f_00b275db(c); /* call 0xb275db */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b26672:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x44u))); /* mov eax, dword ptr [esi + 0x44] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b26680; /* je 0xb26680 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2667fu); f_00b275db(c); /* call 0xb275db */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b26680:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    (void)sub32(c, c->eax, (uint32_t)0xb30940u); /* cmp eax, 0x10010940 */
    if (c->zf) goto L_00b26691; /* je 0xb26691 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b26690u); f_00b275db(c); /* call 0xb275db */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b26691:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b26697u); f_00b275db(c); /* call 0xb275db */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b26698:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb303f0u)); PUSH32(c, v_); } /* push dword ptr [0x100103f0] */
    { uint32_t t_ = R32((uint32_t)(0xb2e014u)); PUSH32(c, 0x00b266a6u); call_indirect(c, t_); } /* call dword ptr [0x1000e014] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00b266a7:;
    c->esp += 4; return; /* ret  */
}

void f_00b266a8(CPU *c) { /* FUN_100066a8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xb2e2f0u; PUSH32(c, v_); } /* push 0x1000e2f0 */
    { uint32_t v_ = 0xb273f8u; PUSH32(c, v_); } /* push 0x100073f8 */
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
    PUSH32(c, 0x00b266d7u); f_00b265a1(c); /* call 0xb265a1 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x60u)), c->esi); /* cmp dword ptr [eax + 0x60], esi */
    if (c->zf) goto L_00b266fb; /* je 0xb266fb */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    PUSH32(c, 0x00b266e8u); f_00b265a1(c); /* call 0xb265a1 */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x60u)); PUSH32(c, 0x00b266ebu); call_indirect(c, t_); } /* call dword ptr [eax + 0x60] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 4], esi */
    goto L_00b266fb; /* jmp 0xb266fb */
L_00b266fb:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b26704u); f_00b26704(c); /* call 0xb26704 */
    { f_00b298a2(c); return; } /* jmp 0xb298a2 */
}

void f_00b266f0(CPU *c) { /* PTR_00b266f0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_00b266f4(CPU *c) { /* PTR_00b266f4 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b26704u); f_00b26704(c); /* call 0xb26704 */
    { f_00b298a2(c); return; } /* jmp 0xb298a2 */
}

void f_00b26704(CPU *c) { /* PTR_00b26704 */
    PREEMPT_POLL(c);
    { f_00b298a2(c); return; } /* jmp 0xb298a2 */
}

void f_00b26709(CPU *c) { /* FUN_10006709 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xb2e308u; PUSH32(c, v_); } /* push 0x1000e308 */
    { uint32_t v_ = 0xb273f8u; PUSH32(c, v_); } /* push 0x100073f8 */
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
    c->eax = (uint32_t)(R32((uint32_t)(0xb303f4u))); /* mov eax, dword ptr [0x100103f4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b26751; /* je 0xb26751 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00b26744u); call_indirect(c, t_); } /* call eax */
    goto L_00b2674d; /* jmp 0xb2674d */
L_00b2674d:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
L_00b26751:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b2675au); f_00b2675a(c); /* call 0xb2675a */
    { f_00b266a8(c); return; } /* jmp 0xb266a8 */
}

void f_00b26746(CPU *c) { /* PTR_00b26746 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_00b2674a(CPU *c) { /* PTR_00b2674a */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b2675au); f_00b2675a(c); /* call 0xb2675a */
    { f_00b266a8(c); return; } /* jmp 0xb266a8 */
}

void f_00b2675a(CPU *c) { /* PTR_00b2675a */
    PREEMPT_POLL(c);
    { f_00b266a8(c); return; } /* jmp 0xb266a8 */
}

void f_00b2675f(CPU *c) { /* FUN_1000675f */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0xb3035cu))); /* mov eax, dword ptr [0x1001035c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b2676a; /* je 0xb2676a */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00b2676au); call_indirect(c, t_); } /* call eax */
L_00b2676a:;
    { uint32_t v_ = 0xb30020u; PUSH32(c, v_); } /* push 0x10010020 */
    { uint32_t v_ = 0xb30010u; PUSH32(c, v_); } /* push 0x10010010 */
    PUSH32(c, 0x00b26779u); f_00b26863(c); /* call 0xb26863 */
    { uint32_t v_ = 0xb3000cu; PUSH32(c, v_); } /* push 0x1001000c */
    { uint32_t v_ = 0xb30000u; PUSH32(c, v_); } /* push 0x10010000 */
    PUSH32(c, 0x00b26788u); f_00b26863(c); /* call 0xb26863 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_00b2678c(CPU *c) { /* __exit */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    PUSH32(c, 0x00b26799u); f_00b267ac(c); /* call 0xb267ac */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b2679d(CPU *c) { /* FUN_1000679d */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    PUSH32(c, 0x00b267a8u); f_00b267ac(c); /* call 0xb267ac */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b267ac(CPU *c) { /* FUN_100067ac */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b267b2u); f_00b26851(c); /* call 0xb26851 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    (void)sub32(c, R32((uint32_t)(0xb334ccu)), c->edi); /* cmp dword ptr [0x100134cc], edi */
    if (!c->zf) goto L_00b267ce; /* jne 0xb267ce */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    { uint32_t t_ = R32((uint32_t)(0xb2e034u)); PUSH32(c, 0x00b267c7u); call_indirect(c, t_); } /* call dword ptr [0x1000e034] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0xb2e030u)); PUSH32(c, 0x00b267ceu); call_indirect(c, t_); } /* call dword ptr [0x1000e030] */
L_00b267ce:;
    (void)sub32(c, R32((uint32_t)(c->esp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [esp + 0xc], 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ebx, dword ptr [esp + 0x14] */
    W32((uint32_t)(0xb334c8u), (uint32_t)(c->edi)); /* mov dword ptr [0x100134c8], edi */
    W8((uint32_t)(0xb334c4u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [0x100134c4], bl */
    if (!c->zf) goto L_00b26822; /* jne 0xb26822 */
    c->eax = (uint32_t)(R32((uint32_t)(0xb33b50u))); /* mov eax, dword ptr [0x10013b50] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b26811; /* je 0xb26811 */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb33b4cu))); /* mov ecx, dword ptr [0x10013b4c] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)((uint32_t)(c->ecx + 0xfffffffcu)); /* lea esi, [ecx - 4] */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if (c->cf) goto L_00b26810; /* jb 0xb26810 */
L_00b267fd:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b26805; /* je 0xb26805 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00b26805u); call_indirect(c, t_); } /* call eax */
L_00b26805:;
    c->esi = (uint32_t)(sub32(c, c->esi, (uint32_t)0x4u)); /* sub esi, 4 */
    (void)sub32(c, c->esi, R32((uint32_t)(0xb33b50u))); /* cmp esi, dword ptr [0x10013b50] */
    if (!c->cf) goto L_00b267fd; /* jae 0xb267fd */
L_00b26810:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00b26811:;
    { uint32_t v_ = 0xb30028u; PUSH32(c, v_); } /* push 0x10010028 */
    { uint32_t v_ = 0xb30024u; PUSH32(c, v_); } /* push 0x10010024 */
    PUSH32(c, 0x00b26820u); f_00b26863(c); /* call 0xb26863 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b26822:;
    { uint32_t v_ = 0xb30034u; PUSH32(c, v_); } /* push 0x10010034 */
    { uint32_t v_ = 0xb3002cu; PUSH32(c, v_); } /* push 0x1001002c */
    PUSH32(c, 0x00b26831u); f_00b26863(c); /* call 0xb26863 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    if (c->zf) goto L_00b2683f; /* je 0xb2683f */
    PUSH32(c, 0x00b2683du); f_00b2685a(c); /* call 0xb2685a */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_00b2683f:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    W32((uint32_t)(0xb334ccu), (uint32_t)(c->edi)); /* mov dword ptr [0x100134cc], edi */
    { uint32_t t_ = R32((uint32_t)(0xb2e02cu)); PUSH32(c, 0x00b2684fu); call_indirect(c, t_); } /* call dword ptr [0x1000e02c] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00b2684f(CPU *c) { /* PTR_00b2684f */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00b26851(CPU *c) { /* FUN_10006851 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xdu; PUSH32(c, v_); } /* push 0xd */
    PUSH32(c, 0x00b26858u); f_00b27565(c); /* call 0xb27565 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00b2685a(CPU *c) { /* FUN_1000685a */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xdu; PUSH32(c, v_); } /* push 0xd */
    PUSH32(c, 0x00b26861u); f_00b275c6(c); /* call 0xb275c6 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00b26863(CPU *c) { /* FUN_10006863 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
L_00b26868:;
    (void)sub32(c, c->esi, R32((uint32_t)(c->esp + 0xcu))); /* cmp esi, dword ptr [esp + 0xc] */
    if (!c->cf) goto L_00b2687b; /* jae 0xb2687b */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b26876; /* je 0xb26876 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00b26876u); call_indirect(c, t_); } /* call eax */
L_00b26876:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    goto L_00b26868; /* jmp 0xb26868 */
L_00b2687b:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b2687d(CPU *c) { /* FUN_1000687d */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xb2e320u; PUSH32(c, v_); } /* push 0x1000e320 */
    { uint32_t v_ = 0xb273f8u; PUSH32(c, v_); } /* push 0x100073f8 */
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
    if (!c->zf) goto L_00b268b7; /* jne 0xb268b7 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x00b268b1u); f_00b26c9a(c); /* call 0xb26c9a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00b26b9d; /* jmp 0xb26b9d */
L_00b268b7:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_00b268ca; /* jne 0xb268ca */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b268c4u); f_00b275db(c); /* call 0xb275db */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00b26b9b; /* jmp 0xb26b9b */
L_00b268ca:;
    c->eax = (uint32_t)(R32((uint32_t)(0xb33a28u))); /* mov eax, dword ptr [0x10013a28] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_00b26a11; /* jne 0xb26a11 */
L_00b268d8:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00b269d5; /* ja 0xb269d5 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b268ebu); f_00b27565(c); /* call 0xb27565 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 4], edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b268f5u); f_00b29901(c); /* call 0xb29901 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x28], eax */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (c->zf) goto L_00b269a5; /* je 0xb269a5 */
    (void)sub32(c, c->esi, R32((uint32_t)(0xb33a20u))); /* cmp esi, dword ptr [0x10013a20] */
    if ((!c->cf && !c->zf)) goto L_00b26955; /* ja 0xb26955 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b26911u); f_00b2a10a(c); /* call 0xb2a10a */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b2691d; /* je 0xb2691d */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x24], ebx */
    goto L_00b26955; /* jmp 0xb26955 */
L_00b2691d:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b26923u); f_00b29c55(c); /* call 0xb29c55 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (c->zf) goto L_00b26955; /* je 0xb26955 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xfffffffcu))); /* mov eax, dword ptr [ebx - 4] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00b26938; /* jb 0xb26938 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00b26938:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00b26942u); f_00b2aaf0(c); /* call 0xb2aaf0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b26948u); f_00b29901(c); /* call 0xb29901 */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x28], eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b26952u); f_00b2992c(c); /* call 0xb2992c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00b26955:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), c->edi); /* cmp dword ptr [ebp - 0x24], edi */
    if (!c->zf) goto L_00b269a5; /* jne 0xb269a5 */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_00b26964; /* jne 0xb26964 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_00b26964:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0xb33a24u)); PUSH32(c, v_); } /* push dword ptr [0x10013a24] */
    { uint32_t t_ = R32((uint32_t)(0xb2e03cu)); PUSH32(c, 0x00b2697bu); call_indirect(c, t_); } /* call dword ptr [0x1000e03c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (c->zf) goto L_00b269a5; /* je 0xb269a5 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xfffffffcu))); /* mov eax, dword ptr [ebx - 4] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00b2698f; /* jb 0xb2698f */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00b2698f:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00b26999u); f_00b2aaf0(c); /* call 0xb2aaf0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x28] */
    PUSH32(c, 0x00b269a2u); f_00b2992c(c); /* call 0xb2992c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
L_00b269a5:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b269aeu); f_00b26a08(c); /* call 0xb26a08 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), c->edi); /* cmp dword ptr [ebp - 0x28], edi */
    if (!c->zf) goto L_00b269d5; /* jne 0xb269d5 */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_00b269ba; /* jne 0xb269ba */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00b269ba:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0xb33a24u)); PUSH32(c, v_); } /* push dword ptr [0x10013a24] */
    { uint32_t t_ = R32((uint32_t)(0xb2e038u)); PUSH32(c, 0x00b269d2u); call_indirect(c, t_); } /* call dword ptr [0x1000e038] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_00b269d5:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_00b26b9d; /* jne 0xb26b9d */
    (void)sub32(c, R32((uint32_t)(0xb33648u)), c->edi); /* cmp dword ptr [0x10013648], edi */
    if (c->zf) goto L_00b26b9d; /* je 0xb26b9d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b269f2u); f_00b2aacd(c); /* call 0xb2aacd */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b268d8; /* jne 0xb268d8 */
    goto L_00b26b9b; /* jmp 0xb26b9b */
L_00b26a11:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00b26b61; /* jne 0xb26b61 */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00b26a31; /* ja 0xb26a31 */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if ((c->cf || c->zf)) goto L_00b26a2b; /* jbe 0xb26a2b */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    goto L_00b26a2e; /* jmp 0xb26a2e */
L_00b26a2b:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00b26a2e:;
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_00b26a31:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00b26b30; /* ja 0xb26b30 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b26a44u); f_00b27565(c); /* call 0xb27565 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b26a5au); f_00b2a65c(c); /* call 0xb2a65c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00b26b14; /* je 0xb26b14 */
    (void)sub32(c, c->esi, R32((uint32_t)(0xb329ecu))); /* cmp esi, dword ptr [0x100129ec] */
    if (!c->cf) goto L_00b26ace; /* jae 0xb26ace */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 4)); /* shr ebx, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00b26a84u); f_00b2aa24(c); /* call 0xb2aa24 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b26a93; /* je 0xb26a93 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_00b26acb; /* jmp 0xb26acb */
L_00b26a93:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b26a99u); f_00b2a6f8(c); /* call 0xb2a6f8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b26acb; /* je 0xb26acb */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00b26ab0; /* jb 0xb26ab0 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00b26ab0:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00b26abcu); f_00b2aaf0(c); /* call 0xb2aaf0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00b26ac8u); f_00b2a6b3(c); /* call 0xb2a6b3 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00b26acb:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00b26ace:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00b26b27; /* jne 0xb26b27 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb33a24u)); PUSH32(c, v_); } /* push dword ptr [0x10013a24] */
    { uint32_t t_ = R32((uint32_t)(0xb2e03cu)); PUSH32(c, 0x00b26ae3u); call_indirect(c, t_); } /* call dword ptr [0x1000e03c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b26b27; /* je 0xb26b27 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00b26af9; /* jb 0xb26af9 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00b26af9:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00b26b03u); f_00b2aaf0(c); /* call 0xb2aaf0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00b26b0fu); f_00b2a6b3(c); /* call 0xb2a6b3 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00b26b27; /* jmp 0xb26b27 */
L_00b26b14:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb33a24u)); PUSH32(c, v_); } /* push dword ptr [0x10013a24] */
    { uint32_t t_ = R32((uint32_t)(0xb2e038u)); PUSH32(c, 0x00b26b24u); call_indirect(c, t_); } /* call dword ptr [0x1000e038] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_00b26b27:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b26b30u); f_00b26b56(c); /* call 0xb26b56 */
L_00b26b30:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_00b26b9d; /* jne 0xb26b9d */
    (void)sub32(c, R32((uint32_t)(0xb33648u)), c->edi); /* cmp dword ptr [0x10013648], edi */
    if (c->zf) goto L_00b26b9d; /* je 0xb26b9d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b26b45u); f_00b2aacd(c); /* call 0xb2aacd */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b26a31; /* jne 0xb26a31 */
    goto L_00b26b9b; /* jmp 0xb26b9b */
L_00b26b61:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00b26b84; /* ja 0xb26b84 */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_00b26b6f; /* jne 0xb26b6f */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00b26b6f:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0xb33a24u)); PUSH32(c, v_); } /* push dword ptr [0x10013a24] */
    { uint32_t t_ = R32((uint32_t)(0xb2e038u)); PUSH32(c, 0x00b26b84u); call_indirect(c, t_); } /* call dword ptr [0x1000e038] */
L_00b26b84:;
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_00b26b9d; /* jne 0xb26b9d */
    (void)sub32(c, R32((uint32_t)(0xb33648u)), c->edi); /* cmp dword ptr [0x10013648], edi */
    if (c->zf) goto L_00b26b9d; /* je 0xb26b9d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b26b96u); f_00b2aacd(c); /* call 0xb2aacd */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b26b61; /* jne 0xb26b61 */
L_00b26b9b:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00b26b9d:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b26a00(CPU *c) { /* PTR_00b26a00 */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    { f_00b26a08(c); return; }
}

void f_00b26a08(CPU *c) { /* FUN_10006a08 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b26a0fu); f_00b275c6(c); /* call 0xb275c6 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00b26a11(CPU *c) { /* PTR_00b26a11 */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) { f_00b26b61(c); return; } /* jne 0xb26b61 */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00b26a31; /* ja 0xb26a31 */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if ((c->cf || c->zf)) goto L_00b26a2b; /* jbe 0xb26a2b */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    goto L_00b26a2e; /* jmp 0xb26a2e */
L_00b26a2b:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00b26a2e:;
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_00b26a31:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00b26b30; /* ja 0xb26b30 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b26a44u); f_00b27565(c); /* call 0xb27565 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b26a5au); f_00b2a65c(c); /* call 0xb2a65c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00b26b14; /* je 0xb26b14 */
    (void)sub32(c, c->esi, R32((uint32_t)(0xb329ecu))); /* cmp esi, dword ptr [0x100129ec] */
    if (!c->cf) goto L_00b26ace; /* jae 0xb26ace */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 4)); /* shr ebx, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00b26a84u); f_00b2aa24(c); /* call 0xb2aa24 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b26a93; /* je 0xb26a93 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_00b26acb; /* jmp 0xb26acb */
L_00b26a93:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b26a99u); f_00b2a6f8(c); /* call 0xb2a6f8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b26acb; /* je 0xb26acb */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00b26ab0; /* jb 0xb26ab0 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00b26ab0:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00b26abcu); f_00b2aaf0(c); /* call 0xb2aaf0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00b26ac8u); f_00b2a6b3(c); /* call 0xb2a6b3 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00b26acb:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00b26ace:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00b26b27; /* jne 0xb26b27 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb33a24u)); PUSH32(c, v_); } /* push dword ptr [0x10013a24] */
    { uint32_t t_ = R32((uint32_t)(0xb2e03cu)); PUSH32(c, 0x00b26ae3u); call_indirect(c, t_); } /* call dword ptr [0x1000e03c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b26b27; /* je 0xb26b27 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00b26af9; /* jb 0xb26af9 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00b26af9:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00b26b03u); f_00b2aaf0(c); /* call 0xb2aaf0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00b26b0fu); f_00b2a6b3(c); /* call 0xb2a6b3 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00b26b27; /* jmp 0xb26b27 */
L_00b26b14:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb33a24u)); PUSH32(c, v_); } /* push dword ptr [0x10013a24] */
    { uint32_t t_ = R32((uint32_t)(0xb2e038u)); PUSH32(c, 0x00b26b24u); call_indirect(c, t_); } /* call dword ptr [0x1000e038] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_00b26b27:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b26b30u); f_00b26b56(c); /* call 0xb26b56 */
L_00b26b30:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00b26b9d(c); return; } /* jne 0xb26b9d */
    (void)sub32(c, R32((uint32_t)(0xb33648u)), c->edi); /* cmp dword ptr [0x10013648], edi */
    if (c->zf) { f_00b26b9d(c); return; } /* je 0xb26b9d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b26b45u); f_00b2aacd(c); /* call 0xb2aacd */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b26a31; /* jne 0xb26a31 */
    { f_00b26b9b(c); return; } /* jmp 0xb26b9b */
}

void f_00b26a2b(CPU *c) { /* PTR_00b26a2b */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_00b26a31:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00b26b30; /* ja 0xb26b30 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b26a44u); f_00b27565(c); /* call 0xb27565 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b26a5au); f_00b2a65c(c); /* call 0xb2a65c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00b26b14; /* je 0xb26b14 */
    (void)sub32(c, c->esi, R32((uint32_t)(0xb329ecu))); /* cmp esi, dword ptr [0x100129ec] */
    if (!c->cf) goto L_00b26ace; /* jae 0xb26ace */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 4)); /* shr ebx, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00b26a84u); f_00b2aa24(c); /* call 0xb2aa24 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b26a93; /* je 0xb26a93 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_00b26acb; /* jmp 0xb26acb */
L_00b26a93:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b26a99u); f_00b2a6f8(c); /* call 0xb2a6f8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b26acb; /* je 0xb26acb */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00b26ab0; /* jb 0xb26ab0 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00b26ab0:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00b26abcu); f_00b2aaf0(c); /* call 0xb2aaf0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00b26ac8u); f_00b2a6b3(c); /* call 0xb2a6b3 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00b26acb:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00b26ace:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00b26b27; /* jne 0xb26b27 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb33a24u)); PUSH32(c, v_); } /* push dword ptr [0x10013a24] */
    { uint32_t t_ = R32((uint32_t)(0xb2e03cu)); PUSH32(c, 0x00b26ae3u); call_indirect(c, t_); } /* call dword ptr [0x1000e03c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b26b27; /* je 0xb26b27 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00b26af9; /* jb 0xb26af9 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00b26af9:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00b26b03u); f_00b2aaf0(c); /* call 0xb2aaf0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00b26b0fu); f_00b2a6b3(c); /* call 0xb2a6b3 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00b26b27; /* jmp 0xb26b27 */
L_00b26b14:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb33a24u)); PUSH32(c, v_); } /* push dword ptr [0x10013a24] */
    { uint32_t t_ = R32((uint32_t)(0xb2e038u)); PUSH32(c, 0x00b26b24u); call_indirect(c, t_); } /* call dword ptr [0x1000e038] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_00b26b27:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b26b30u); f_00b26b56(c); /* call 0xb26b56 */
L_00b26b30:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00b26b9d(c); return; } /* jne 0xb26b9d */
    (void)sub32(c, R32((uint32_t)(0xb33648u)), c->edi); /* cmp dword ptr [0x10013648], edi */
    if (c->zf) { f_00b26b9d(c); return; } /* je 0xb26b9d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b26b45u); f_00b2aacd(c); /* call 0xb2aacd */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b26a31; /* jne 0xb26a31 */
    { f_00b26b9b(c); return; } /* jmp 0xb26b9b */
}

void f_00b26a2e(CPU *c) { /* PTR_00b26a2e */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_00b26a31:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00b26b30; /* ja 0xb26b30 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b26a44u); f_00b27565(c); /* call 0xb27565 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b26a5au); f_00b2a65c(c); /* call 0xb2a65c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00b26b14; /* je 0xb26b14 */
    (void)sub32(c, c->esi, R32((uint32_t)(0xb329ecu))); /* cmp esi, dword ptr [0x100129ec] */
    if (!c->cf) goto L_00b26ace; /* jae 0xb26ace */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 4)); /* shr ebx, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00b26a84u); f_00b2aa24(c); /* call 0xb2aa24 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b26a93; /* je 0xb26a93 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_00b26acb; /* jmp 0xb26acb */
L_00b26a93:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b26a99u); f_00b2a6f8(c); /* call 0xb2a6f8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b26acb; /* je 0xb26acb */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00b26ab0; /* jb 0xb26ab0 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00b26ab0:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00b26abcu); f_00b2aaf0(c); /* call 0xb2aaf0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00b26ac8u); f_00b2a6b3(c); /* call 0xb2a6b3 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00b26acb:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00b26ace:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00b26b27; /* jne 0xb26b27 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb33a24u)); PUSH32(c, v_); } /* push dword ptr [0x10013a24] */
    { uint32_t t_ = R32((uint32_t)(0xb2e03cu)); PUSH32(c, 0x00b26ae3u); call_indirect(c, t_); } /* call dword ptr [0x1000e03c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b26b27; /* je 0xb26b27 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00b26af9; /* jb 0xb26af9 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00b26af9:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00b26b03u); f_00b2aaf0(c); /* call 0xb2aaf0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00b26b0fu); f_00b2a6b3(c); /* call 0xb2a6b3 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00b26b27; /* jmp 0xb26b27 */
L_00b26b14:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb33a24u)); PUSH32(c, v_); } /* push dword ptr [0x10013a24] */
    { uint32_t t_ = R32((uint32_t)(0xb2e038u)); PUSH32(c, 0x00b26b24u); call_indirect(c, t_); } /* call dword ptr [0x1000e038] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_00b26b27:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b26b30u); f_00b26b56(c); /* call 0xb26b56 */
L_00b26b30:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00b26b9d(c); return; } /* jne 0xb26b9d */
    (void)sub32(c, R32((uint32_t)(0xb33648u)), c->edi); /* cmp dword ptr [0x10013648], edi */
    if (c->zf) { f_00b26b9d(c); return; } /* je 0xb26b9d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b26b45u); f_00b2aacd(c); /* call 0xb2aacd */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b26a31; /* jne 0xb26a31 */
    { f_00b26b9b(c); return; } /* jmp 0xb26b9b */
}

void f_00b26a31(CPU *c) { /* PTR_00b26a31 */
    PREEMPT_POLL(c);
L_00b26a31:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00b26b30; /* ja 0xb26b30 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b26a44u); f_00b27565(c); /* call 0xb27565 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b26a5au); f_00b2a65c(c); /* call 0xb2a65c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00b26b14; /* je 0xb26b14 */
    (void)sub32(c, c->esi, R32((uint32_t)(0xb329ecu))); /* cmp esi, dword ptr [0x100129ec] */
    if (!c->cf) goto L_00b26ace; /* jae 0xb26ace */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 4)); /* shr ebx, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00b26a84u); f_00b2aa24(c); /* call 0xb2aa24 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b26a93; /* je 0xb26a93 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_00b26acb; /* jmp 0xb26acb */
L_00b26a93:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b26a99u); f_00b2a6f8(c); /* call 0xb2a6f8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b26acb; /* je 0xb26acb */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00b26ab0; /* jb 0xb26ab0 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00b26ab0:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00b26abcu); f_00b2aaf0(c); /* call 0xb2aaf0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00b26ac8u); f_00b2a6b3(c); /* call 0xb2a6b3 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00b26acb:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00b26ace:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00b26b27; /* jne 0xb26b27 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb33a24u)); PUSH32(c, v_); } /* push dword ptr [0x10013a24] */
    { uint32_t t_ = R32((uint32_t)(0xb2e03cu)); PUSH32(c, 0x00b26ae3u); call_indirect(c, t_); } /* call dword ptr [0x1000e03c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b26b27; /* je 0xb26b27 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00b26af9; /* jb 0xb26af9 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00b26af9:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00b26b03u); f_00b2aaf0(c); /* call 0xb2aaf0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00b26b0fu); f_00b2a6b3(c); /* call 0xb2a6b3 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00b26b27; /* jmp 0xb26b27 */
L_00b26b14:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb33a24u)); PUSH32(c, v_); } /* push dword ptr [0x10013a24] */
    { uint32_t t_ = R32((uint32_t)(0xb2e038u)); PUSH32(c, 0x00b26b24u); call_indirect(c, t_); } /* call dword ptr [0x1000e038] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_00b26b27:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b26b30u); f_00b26b56(c); /* call 0xb26b56 */
L_00b26b30:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00b26b9d(c); return; } /* jne 0xb26b9d */
    (void)sub32(c, R32((uint32_t)(0xb33648u)), c->edi); /* cmp dword ptr [0x10013648], edi */
    if (c->zf) { f_00b26b9d(c); return; } /* je 0xb26b9d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b26b45u); f_00b2aacd(c); /* call 0xb2aacd */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b26a31; /* jne 0xb26a31 */
    { f_00b26b9b(c); return; } /* jmp 0xb26b9b */
}

void f_00b26a93(CPU *c) { /* PTR_00b26a93 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b26a99u); f_00b2a6f8(c); /* call 0xb2a6f8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b26acb; /* je 0xb26acb */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00b26ab0; /* jb 0xb26ab0 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00b26ab0:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00b26abcu); f_00b2aaf0(c); /* call 0xb2aaf0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00b26ac8u); f_00b2a6b3(c); /* call 0xb2a6b3 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00b26acb:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00b26b27; /* jne 0xb26b27 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb33a24u)); PUSH32(c, v_); } /* push dword ptr [0x10013a24] */
    { uint32_t t_ = R32((uint32_t)(0xb2e03cu)); PUSH32(c, 0x00b26ae3u); call_indirect(c, t_); } /* call dword ptr [0x1000e03c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b26b27; /* je 0xb26b27 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00b26af9; /* jb 0xb26af9 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00b26af9:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00b26b03u); f_00b2aaf0(c); /* call 0xb2aaf0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00b26b0fu); f_00b2a6b3(c); /* call 0xb2a6b3 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00b26b27; /* jmp 0xb26b27 */
L_00b26b27:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b26b30u); f_00b26b56(c); /* call 0xb26b56 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00b26b9d(c); return; } /* jne 0xb26b9d */
    (void)sub32(c, R32((uint32_t)(0xb33648u)), c->edi); /* cmp dword ptr [0x10013648], edi */
    if (c->zf) { f_00b26b9d(c); return; } /* je 0xb26b9d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b26b45u); f_00b2aacd(c); /* call 0xb2aacd */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00b26a31(c); return; } /* jne 0xb26a31 */
    { f_00b26b9b(c); return; } /* jmp 0xb26b9b */
}

void f_00b26ab0(CPU *c) { /* PTR_00b26ab0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00b26abcu); f_00b2aaf0(c); /* call 0xb2aaf0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00b26ac8u); f_00b2a6b3(c); /* call 0xb2a6b3 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00b26b27; /* jne 0xb26b27 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb33a24u)); PUSH32(c, v_); } /* push dword ptr [0x10013a24] */
    { uint32_t t_ = R32((uint32_t)(0xb2e03cu)); PUSH32(c, 0x00b26ae3u); call_indirect(c, t_); } /* call dword ptr [0x1000e03c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b26b27; /* je 0xb26b27 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00b26af9; /* jb 0xb26af9 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00b26af9:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00b26b03u); f_00b2aaf0(c); /* call 0xb2aaf0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00b26b0fu); f_00b2a6b3(c); /* call 0xb2a6b3 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00b26b27; /* jmp 0xb26b27 */
L_00b26b27:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b26b30u); f_00b26b56(c); /* call 0xb26b56 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00b26b9d(c); return; } /* jne 0xb26b9d */
    (void)sub32(c, R32((uint32_t)(0xb33648u)), c->edi); /* cmp dword ptr [0x10013648], edi */
    if (c->zf) { f_00b26b9d(c); return; } /* je 0xb26b9d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b26b45u); f_00b2aacd(c); /* call 0xb2aacd */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00b26a31(c); return; } /* jne 0xb26a31 */
    { f_00b26b9b(c); return; } /* jmp 0xb26b9b */
}

void f_00b26acb(CPU *c) { /* PTR_00b26acb */
    PREEMPT_POLL(c);
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00b26b27; /* jne 0xb26b27 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb33a24u)); PUSH32(c, v_); } /* push dword ptr [0x10013a24] */
    { uint32_t t_ = R32((uint32_t)(0xb2e03cu)); PUSH32(c, 0x00b26ae3u); call_indirect(c, t_); } /* call dword ptr [0x1000e03c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b26b27; /* je 0xb26b27 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00b26af9; /* jb 0xb26af9 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00b26af9:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00b26b03u); f_00b2aaf0(c); /* call 0xb2aaf0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00b26b0fu); f_00b2a6b3(c); /* call 0xb2a6b3 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00b26b27; /* jmp 0xb26b27 */
L_00b26b27:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b26b30u); f_00b26b56(c); /* call 0xb26b56 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00b26b9d(c); return; } /* jne 0xb26b9d */
    (void)sub32(c, R32((uint32_t)(0xb33648u)), c->edi); /* cmp dword ptr [0x10013648], edi */
    if (c->zf) { f_00b26b9d(c); return; } /* je 0xb26b9d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b26b45u); f_00b2aacd(c); /* call 0xb2aacd */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00b26a31(c); return; } /* jne 0xb26a31 */
    { f_00b26b9b(c); return; } /* jmp 0xb26b9b */
}

void f_00b26ace(CPU *c) { /* PTR_00b26ace */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00b26b27; /* jne 0xb26b27 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb33a24u)); PUSH32(c, v_); } /* push dword ptr [0x10013a24] */
    { uint32_t t_ = R32((uint32_t)(0xb2e03cu)); PUSH32(c, 0x00b26ae3u); call_indirect(c, t_); } /* call dword ptr [0x1000e03c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b26b27; /* je 0xb26b27 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00b26af9; /* jb 0xb26af9 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00b26af9:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00b26b03u); f_00b2aaf0(c); /* call 0xb2aaf0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00b26b0fu); f_00b2a6b3(c); /* call 0xb2a6b3 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00b26b27; /* jmp 0xb26b27 */
L_00b26b27:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b26b30u); f_00b26b56(c); /* call 0xb26b56 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00b26b9d(c); return; } /* jne 0xb26b9d */
    (void)sub32(c, R32((uint32_t)(0xb33648u)), c->edi); /* cmp dword ptr [0x10013648], edi */
    if (c->zf) { f_00b26b9d(c); return; } /* je 0xb26b9d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b26b45u); f_00b2aacd(c); /* call 0xb2aacd */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00b26a31(c); return; } /* jne 0xb26a31 */
    { f_00b26b9b(c); return; } /* jmp 0xb26b9b */
}

void f_00b26af9(CPU *c) { /* PTR_00b26af9 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00b26b03u); f_00b2aaf0(c); /* call 0xb2aaf0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00b26b0fu); f_00b2a6b3(c); /* call 0xb2a6b3 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00b26b27; /* jmp 0xb26b27 */
L_00b26b27:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b26b30u); f_00b26b56(c); /* call 0xb26b56 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00b26b9d(c); return; } /* jne 0xb26b9d */
    (void)sub32(c, R32((uint32_t)(0xb33648u)), c->edi); /* cmp dword ptr [0x10013648], edi */
    if (c->zf) { f_00b26b9d(c); return; } /* je 0xb26b9d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b26b45u); f_00b2aacd(c); /* call 0xb2aacd */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00b26a31(c); return; } /* jne 0xb26a31 */
    { f_00b26b9b(c); return; } /* jmp 0xb26b9b */
}

void f_00b26b14(CPU *c) { /* PTR_00b26b14 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb33a24u)); PUSH32(c, v_); } /* push dword ptr [0x10013a24] */
    { uint32_t t_ = R32((uint32_t)(0xb2e038u)); PUSH32(c, 0x00b26b24u); call_indirect(c, t_); } /* call dword ptr [0x1000e038] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b26b30u); f_00b26b56(c); /* call 0xb26b56 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00b26b9d(c); return; } /* jne 0xb26b9d */
    (void)sub32(c, R32((uint32_t)(0xb33648u)), c->edi); /* cmp dword ptr [0x10013648], edi */
    if (c->zf) { f_00b26b9d(c); return; } /* je 0xb26b9d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b26b45u); f_00b2aacd(c); /* call 0xb2aacd */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00b26a31(c); return; } /* jne 0xb26a31 */
    { f_00b26b9b(c); return; } /* jmp 0xb26b9b */
}

void f_00b26b27(CPU *c) { /* PTR_00b26b27 */
    PREEMPT_POLL(c);
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b26b30u); f_00b26b56(c); /* call 0xb26b56 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00b26b9d(c); return; } /* jne 0xb26b9d */
    (void)sub32(c, R32((uint32_t)(0xb33648u)), c->edi); /* cmp dword ptr [0x10013648], edi */
    if (c->zf) { f_00b26b9d(c); return; } /* je 0xb26b9d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b26b45u); f_00b2aacd(c); /* call 0xb2aacd */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00b26a31(c); return; } /* jne 0xb26a31 */
    { f_00b26b9b(c); return; } /* jmp 0xb26b9b */
}

void f_00b26b30(CPU *c) { /* PTR_00b26b30 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00b26b9d(c); return; } /* jne 0xb26b9d */
    (void)sub32(c, R32((uint32_t)(0xb33648u)), c->edi); /* cmp dword ptr [0x10013648], edi */
    if (c->zf) { f_00b26b9d(c); return; } /* je 0xb26b9d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b26b45u); f_00b2aacd(c); /* call 0xb2aacd */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00b26a31(c); return; } /* jne 0xb26a31 */
    { f_00b26b9b(c); return; } /* jmp 0xb26b9b */
}

void f_00b26b50(CPU *c) { /* PTR_00b26b50 */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    { f_00b26b56(c); return; }
}

void f_00b26b56(CPU *c) { /* FUN_10006b56 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b26b5du); f_00b275c6(c); /* call 0xb275c6 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    c->esp += 4; return; /* ret  */
}

void f_00b26b61(CPU *c) { /* PTR_00b26b61 */
    PREEMPT_POLL(c);
L_00b26b61:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00b26b84; /* ja 0xb26b84 */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_00b26b6f; /* jne 0xb26b6f */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00b26b6f:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0xb33a24u)); PUSH32(c, v_); } /* push dword ptr [0x10013a24] */
    { uint32_t t_ = R32((uint32_t)(0xb2e038u)); PUSH32(c, 0x00b26b84u); call_indirect(c, t_); } /* call dword ptr [0x1000e038] */
L_00b26b84:;
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_00b26b9d; /* jne 0xb26b9d */
    (void)sub32(c, R32((uint32_t)(0xb33648u)), c->edi); /* cmp dword ptr [0x10013648], edi */
    if (c->zf) goto L_00b26b9d; /* je 0xb26b9d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b26b96u); f_00b2aacd(c); /* call 0xb2aacd */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b26b61; /* jne 0xb26b61 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00b26b9d:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b26b6f(CPU *c) { /* PTR_00b26b6f */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0xb33a24u)); PUSH32(c, v_); } /* push dword ptr [0x10013a24] */
    { uint32_t t_ = R32((uint32_t)(0xb2e038u)); PUSH32(c, 0x00b26b84u); call_indirect(c, t_); } /* call dword ptr [0x1000e038] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_00b26b9d; /* jne 0xb26b9d */
    (void)sub32(c, R32((uint32_t)(0xb33648u)), c->edi); /* cmp dword ptr [0x10013648], edi */
    if (c->zf) goto L_00b26b9d; /* je 0xb26b9d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b26b96u); f_00b2aacd(c); /* call 0xb2aacd */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00b26b61(c); return; } /* jne 0xb26b61 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00b26b9d:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b26b84(CPU *c) { /* PTR_00b26b84 */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_00b26b9d; /* jne 0xb26b9d */
    (void)sub32(c, R32((uint32_t)(0xb33648u)), c->edi); /* cmp dword ptr [0x10013648], edi */
    if (c->zf) goto L_00b26b9d; /* je 0xb26b9d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b26b96u); f_00b2aacd(c); /* call 0xb2aacd */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00b26b61(c); return; } /* jne 0xb26b61 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00b26b9d:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b26b9b(CPU *c) { /* PTR_00b26b9b */
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

void f_00b26b9d(CPU *c) { /* PTR_00b26b9d */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b26bac(CPU *c) { /* FUN_10006bac */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xb2e338u; PUSH32(c, v_); } /* push 0x1000e338 */
    { uint32_t v_ = 0xb273f8u; PUSH32(c, v_); } /* push 0x100073f8 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x1cu)); /* sub esp, 0x1c */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(0xb33a28u))); /* mov eax, dword ptr [0x10013a28] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_00b26c1f; /* jne 0xb26c1f */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b26be0u); f_00b27565(c); /* call 0xb27565 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b26beeu); f_00b29901(c); /* call 0xb29901 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b26c01; /* je 0xb26c01 */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0xfffffffcu))); /* mov esi, dword ptr [esi - 4] */
    c->esi = (uint32_t)(sub32(c, c->esi, (uint32_t)0x9u)); /* sub esi, 9 */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x20], esi */
    goto L_00b26c04; /* jmp 0xb26c04 */
L_00b26c01:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
L_00b26c04:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b26c0du); f_00b26c16(c); /* call 0xb26c16 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x1c], 0 */
    goto L_00b26c68; /* jmp 0xb26c68 */
L_00b26c1f:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00b26c6a; /* jne 0xb26c6a */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b26c2bu); f_00b27565(c); /* call 0xb27565 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffdcu)); /* lea eax, [ebp - 0x24] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00b26c43u); f_00b2a65c(c); /* call 0xb2a65c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x28], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b26c58; /* je 0xb26c58 */
    c->esi = (uint32_t)((uint32_t)R8((uint32_t)(c->eax))); /* movzx esi, byte ptr [eax] */
    c->esi = (uint32_t)(shl32(c, c->esi, 4)); /* shl esi, 4 */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x20], esi */
    goto L_00b26c5b; /* jmp 0xb26c5b */
L_00b26c58:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
L_00b26c5b:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b26c64u); f_00b26c91(c); /* call 0xb26c91 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x28], 0 */
L_00b26c68:;
    if (!c->zf) goto L_00b26c7d; /* jne 0xb26c7d */
L_00b26c6a:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb33a24u)); PUSH32(c, v_); } /* push dword ptr [0x10013a24] */
    { uint32_t t_ = R32((uint32_t)(0xb2e040u)); PUSH32(c, 0x00b26c7bu); call_indirect(c, t_); } /* call dword ptr [0x1000e040] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_00b26c7d:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b26c13(CPU *c) { /* PTR_00b26c13 */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
    { f_00b26c16(c); return; }
}

void f_00b26c16(CPU *c) { /* FUN_10006c16 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b26c1du); f_00b275c6(c); /* call 0xb275c6 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00b26c1f(CPU *c) { /* PTR_00b26c1f */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00b26c6a; /* jne 0xb26c6a */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b26c2bu); f_00b27565(c); /* call 0xb27565 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffdcu)); /* lea eax, [ebp - 0x24] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00b26c43u); f_00b2a65c(c); /* call 0xb2a65c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x28], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b26c58; /* je 0xb26c58 */
    c->esi = (uint32_t)((uint32_t)R8((uint32_t)(c->eax))); /* movzx esi, byte ptr [eax] */
    c->esi = (uint32_t)(shl32(c, c->esi, 4)); /* shl esi, 4 */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x20], esi */
    goto L_00b26c5b; /* jmp 0xb26c5b */
L_00b26c58:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
L_00b26c5b:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b26c64u); f_00b26c91(c); /* call 0xb26c91 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x28], 0 */
    if (!c->zf) goto L_00b26c7d; /* jne 0xb26c7d */
L_00b26c6a:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb33a24u)); PUSH32(c, v_); } /* push dword ptr [0x10013a24] */
    { uint32_t t_ = R32((uint32_t)(0xb2e040u)); PUSH32(c, 0x00b26c7bu); call_indirect(c, t_); } /* call dword ptr [0x1000e040] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_00b26c7d:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b26c58(CPU *c) { /* PTR_00b26c58 */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b26c64u); f_00b26c91(c); /* call 0xb26c91 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x28], 0 */
    if (!c->zf) goto L_00b26c7d; /* jne 0xb26c7d */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb33a24u)); PUSH32(c, v_); } /* push dword ptr [0x10013a24] */
    { uint32_t t_ = R32((uint32_t)(0xb2e040u)); PUSH32(c, 0x00b26c7bu); call_indirect(c, t_); } /* call dword ptr [0x1000e040] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_00b26c7d:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b26c5b(CPU *c) { /* PTR_00b26c5b */
    PREEMPT_POLL(c);
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b26c64u); f_00b26c91(c); /* call 0xb26c91 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x28], 0 */
    if (!c->zf) goto L_00b26c7d; /* jne 0xb26c7d */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb33a24u)); PUSH32(c, v_); } /* push dword ptr [0x10013a24] */
    { uint32_t t_ = R32((uint32_t)(0xb2e040u)); PUSH32(c, 0x00b26c7bu); call_indirect(c, t_); } /* call dword ptr [0x1000e040] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_00b26c7d:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b26c68(CPU *c) { /* PTR_00b26c68 */
    PREEMPT_POLL(c);
    if (!c->zf) goto L_00b26c7d; /* jne 0xb26c7d */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb33a24u)); PUSH32(c, v_); } /* push dword ptr [0x10013a24] */
    { uint32_t t_ = R32((uint32_t)(0xb2e040u)); PUSH32(c, 0x00b26c7bu); call_indirect(c, t_); } /* call dword ptr [0x1000e040] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_00b26c7d:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b26c6a(CPU *c) { /* PTR_00b26c6a */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb33a24u)); PUSH32(c, v_); } /* push dword ptr [0x10013a24] */
    { uint32_t t_ = R32((uint32_t)(0xb2e040u)); PUSH32(c, 0x00b26c7bu); call_indirect(c, t_); } /* call dword ptr [0x1000e040] */
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

void f_00b26c7d(CPU *c) { /* PTR_00b26c7d */
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

void f_00b26c8e(CPU *c) { /* PTR_00b26c8e */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
    { f_00b26c91(c); return; }
}

void f_00b26c91(CPU *c) { /* FUN_10006c91 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b26c98u); f_00b275c6(c); /* call 0xb275c6 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00b26c9a(CPU *c) { /* _malloc */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(0xb33648u)); PUSH32(c, v_); } /* push dword ptr [0x10013648] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    PUSH32(c, 0x00b26ca9u); f_00b26cac(c); /* call 0xb26cac */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00b26cac(CPU *c) { /* __nh_malloc */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->esp + 0x4u)), (uint32_t)0xffffffe0u); /* cmp dword ptr [esp + 4], -0x20 */
    if ((!c->cf && !c->zf)) goto L_00b26cd5; /* ja 0xb26cd5 */
L_00b26cb3:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    PUSH32(c, 0x00b26cbcu); f_00b26cd8(c); /* call 0xb26cd8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00b26cd7; /* jne 0xb26cd7 */
    (void)sub32(c, R32((uint32_t)(c->esp + 0x8u)), c->eax); /* cmp dword ptr [esp + 8], eax */
    if (c->zf) goto L_00b26cd7; /* je 0xb26cd7 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    PUSH32(c, 0x00b26cd0u); f_00b2aacd(c); /* call 0xb2aacd */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00b26cb3; /* jne 0xb26cb3 */
L_00b26cd5:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00b26cd7:;
    c->esp += 4; return; /* ret  */
}

void f_00b26cd8(CPU *c) { /* FUN_10006cd8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xb2e350u; PUSH32(c, v_); } /* push 0x1000e350 */
    { uint32_t v_ = 0xb273f8u; PUSH32(c, v_); } /* push 0x100073f8 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(0xb33a28u))); /* mov eax, dword ptr [0x10013a28] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_00b26d48; /* jne 0xb26d48 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    (void)sub32(c, c->esi, R32((uint32_t)(0xb33a20u))); /* cmp esi, dword ptr [0x10013a20] */
    if ((!c->cf && !c->zf)) goto L_00b26da7; /* ja 0xb26da7 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b26d1bu); f_00b27565(c); /* call 0xb27565 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b26d26u); f_00b29c55(c); /* call 0xb29c55 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b26d33u); f_00b26d3f(c); /* call 0xb26d3f */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b26da7; /* je 0xb26da7 */
    goto L_00b26dc5; /* jmp 0xb26dc5 */
L_00b26d48:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00b26da7; /* jne 0xb26da7 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b26d5c; /* je 0xb26d5c */
    c->esi = (uint32_t)((uint32_t)(c->eax + 0xfu)); /* lea esi, [eax + 0xf] */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    goto L_00b26d5f; /* jmp 0xb26d5f */
L_00b26d5c:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00b26d5f:;
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
    (void)sub32(c, c->esi, R32((uint32_t)(0xb329ecu))); /* cmp esi, dword ptr [0x100129ec] */
    if ((!c->cf && !c->zf)) goto L_00b26d98; /* ja 0xb26d98 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b26d71u); f_00b27565(c); /* call 0xb27565 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b26d84u); f_00b2a6f8(c); /* call 0xb2a6f8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b26d91u); f_00b26d9e(c); /* call 0xb26d9e */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b26dc5; /* jne 0xb26dc5 */
L_00b26d98:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    goto L_00b26db7; /* jmp 0xb26db7 */
L_00b26da7:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b26db1; /* jne 0xb26db1 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00b26db1:;
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xfu)); /* add eax, 0xf */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xf0u))); /* and al, 0xf0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
L_00b26db7:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb33a24u)); PUSH32(c, v_); } /* push dword ptr [0x10013a24] */
    { uint32_t t_ = R32((uint32_t)(0xb2e03cu)); PUSH32(c, 0x00b26dc5u); call_indirect(c, t_); } /* call dword ptr [0x1000e03c] */
L_00b26dc5:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b26d3f(CPU *c) { /* FUN_10006d3f */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b26d46u); f_00b275c6(c); /* call 0xb275c6 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00b26d48(CPU *c) { /* PTR_00b26d48 */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) { f_00b26da7(c); return; } /* jne 0xb26da7 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b26d5c; /* je 0xb26d5c */
    c->esi = (uint32_t)((uint32_t)(c->eax + 0xfu)); /* lea esi, [eax + 0xf] */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    goto L_00b26d5f; /* jmp 0xb26d5f */
L_00b26d5c:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00b26d5f:;
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
    (void)sub32(c, c->esi, R32((uint32_t)(0xb329ecu))); /* cmp esi, dword ptr [0x100129ec] */
    if ((!c->cf && !c->zf)) goto L_00b26d98; /* ja 0xb26d98 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b26d71u); f_00b27565(c); /* call 0xb27565 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b26d84u); f_00b2a6f8(c); /* call 0xb2a6f8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b26d91u); f_00b26d9e(c); /* call 0xb26d9e */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00b26dc5(c); return; } /* jne 0xb26dc5 */
L_00b26d98:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { f_00b26db7(c); return; } /* jmp 0xb26db7 */
}

void f_00b26d5c(CPU *c) { /* PTR_00b26d5c */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
    (void)sub32(c, c->esi, R32((uint32_t)(0xb329ecu))); /* cmp esi, dword ptr [0x100129ec] */
    if ((!c->cf && !c->zf)) goto L_00b26d98; /* ja 0xb26d98 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b26d71u); f_00b27565(c); /* call 0xb27565 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b26d84u); f_00b2a6f8(c); /* call 0xb2a6f8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b26d91u); f_00b26d9e(c); /* call 0xb26d9e */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00b26dc5(c); return; } /* jne 0xb26dc5 */
L_00b26d98:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { f_00b26db7(c); return; } /* jmp 0xb26db7 */
}

void f_00b26d5f(CPU *c) { /* PTR_00b26d5f */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
    (void)sub32(c, c->esi, R32((uint32_t)(0xb329ecu))); /* cmp esi, dword ptr [0x100129ec] */
    if ((!c->cf && !c->zf)) goto L_00b26d98; /* ja 0xb26d98 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b26d71u); f_00b27565(c); /* call 0xb27565 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b26d84u); f_00b2a6f8(c); /* call 0xb2a6f8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b26d91u); f_00b26d9e(c); /* call 0xb26d9e */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00b26dc5(c); return; } /* jne 0xb26dc5 */
L_00b26d98:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { f_00b26db7(c); return; } /* jmp 0xb26db7 */
}

void f_00b26d98(CPU *c) { /* PTR_00b26d98 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { f_00b26db7(c); return; } /* jmp 0xb26db7 */
}

void f_00b26d9b(CPU *c) { /* PTR_00b26d9b */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    { f_00b26d9e(c); return; }
}

void f_00b26d9e(CPU *c) { /* FUN_10006d9e */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b26da5u); f_00b275c6(c); /* call 0xb275c6 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00b26da7(CPU *c) { /* PTR_00b26da7 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b26db1; /* jne 0xb26db1 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00b26db1:;
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xfu)); /* add eax, 0xf */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xf0u))); /* and al, 0xf0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb33a24u)); PUSH32(c, v_); } /* push dword ptr [0x10013a24] */
    { uint32_t t_ = R32((uint32_t)(0xb2e03cu)); PUSH32(c, 0x00b26dc5u); call_indirect(c, t_); } /* call dword ptr [0x1000e03c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b26db1(CPU *c) { /* PTR_00b26db1 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xfu)); /* add eax, 0xf */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xf0u))); /* and al, 0xf0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb33a24u)); PUSH32(c, v_); } /* push dword ptr [0x10013a24] */
    { uint32_t t_ = R32((uint32_t)(0xb2e03cu)); PUSH32(c, 0x00b26dc5u); call_indirect(c, t_); } /* call dword ptr [0x1000e03c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b26db7(CPU *c) { /* PTR_00b26db7 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb33a24u)); PUSH32(c, v_); } /* push dword ptr [0x10013a24] */
    { uint32_t t_ = R32((uint32_t)(0xb2e03cu)); PUSH32(c, 0x00b26dc5u); call_indirect(c, t_); } /* call dword ptr [0x1000e03c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b26dc5(CPU *c) { /* PTR_00b26dc5 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b26dd4(CPU *c) { /* FUN_10006dd4 */
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
    PUSH32(c, 0x00b26df5u); f_00b2b211(c); /* call 0xb2b211 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x4u)); /* test bl, 4 */
    if (c->zf) goto L_00b26e0c; /* je 0xb26e0c */
    c->edi = (uint32_t)((uint32_t)0x200u); /* mov edi, 0x200 */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0xc], esi */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 8], esi */
    goto L_00b26e3a; /* jmp 0xb26e3a */
L_00b26e0c:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe8u)); /* lea eax, [ebp - 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b26e19u); f_00b2b18b(c); /* call 0xb2b18b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x2u)); /* test bl, 2 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00b26e25; /* jne 0xb26e25 */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_00b26e2a; /* jne 0xb26e2a */
L_00b26e25:;
    c->edi = (uint32_t)((uint32_t)0x80u); /* mov edi, 0x80 */
L_00b26e2a:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x1u)); /* test bl, 1 */
    if (!c->zf) goto L_00b26e34; /* jne 0xb26e34 */
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00b26e3a; /* jne 0xb26e3a */
L_00b26e34:;
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi | (uint32_t)0x100u))); /* or edi, 0x100 */
L_00b26e3a:;
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

void f_00b26e60(CPU *c) { /* _strlen */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u)); /* test ecx, 3 */
    if (c->zf) goto L_00b26e80; /* je 0xb26e80 */
L_00b26e6c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov al, byte ptr [ecx] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00b26eb3; /* je 0xb26eb3 */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u)); /* test ecx, 3 */
    if (!c->zf) goto L_00b26e6c; /* jne 0xb26e6c */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x0u)); /* add eax, 0 */
L_00b26e80:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)((uint32_t)0x7efefeffu); /* mov edx, 0x7efefeff */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ (uint32_t)0xffffffffu))); /* xor eax, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ c->edx))); /* xor eax, edx */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u)); /* test eax, 0x81010100 */
    if (c->zf) goto L_00b26e80; /* je 0xb26e80 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0xfffffffcu))); /* mov eax, dword ptr [ecx - 4] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00b26ed1; /* je 0xb26ed1 */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_00b26ec7; /* je 0xb26ec7 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0xff0000u)); /* test eax, 0xff0000 */
    if (c->zf) goto L_00b26ebd; /* je 0xb26ebd */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0xff000000u)); /* test eax, 0xff000000 */
    if (c->zf) goto L_00b26eb3; /* je 0xb26eb3 */
    goto L_00b26e80; /* jmp 0xb26e80 */
L_00b26eb3:;
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0xffffffffu)); /* lea eax, [ecx - 1] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->esp += 4; return; /* ret  */
L_00b26ebd:;
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0xfffffffeu)); /* lea eax, [ecx - 2] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->esp += 4; return; /* ret  */
L_00b26ec7:;
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0xfffffffdu)); /* lea eax, [ecx - 3] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->esp += 4; return; /* ret  */
L_00b26ed1:;
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0xfffffffcu)); /* lea eax, [ecx - 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->esp += 4; return; /* ret  */
}

void f_00b26edb(CPU *c) { /* FUN_10006edb */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x1u)); /* lea ecx, [eax + 1] */
    (void)sub32(c, c->ecx, (uint32_t)0x100u); /* cmp ecx, 0x100 */
    if ((!c->cf && !c->zf)) goto L_00b26ef9; /* ja 0xb26ef9 */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb30400u))); /* mov ecx, dword ptr [0x10010400] */
    c->eax = (uint32_t)((uint32_t)R16((uint32_t)(c->ecx + c->eax * 2))); /* movzx eax, word ptr [ecx + eax*2] */
    goto L_00b26f4b; /* jmp 0xb26f4b */
L_00b26ef9:;
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(0xb30400u))); /* mov esi, dword ptr [0x10010400] */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 8)); /* sar ecx, 8 */
    c->edx = (uint32_t)((uint32_t)((uint8_t)c->ecx)); /* movzx edx, cl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi + c->edx * 2 + 0x1u)) & (uint8_t)0x80u)); /* test byte ptr [esi + edx*2 + 1], 0x80 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    if (c->zf) goto L_00b26f1e; /* je 0xb26f1e */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffeu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp - 2], 0 */
    W8((uint32_t)(c->ebp + 0xfffffffcu), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [ebp - 4], cl */
    W8((uint32_t)(c->ebp + 0xfffffffdu), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp - 3], al */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    goto L_00b26f27; /* jmp 0xb26f27 */
L_00b26f1e:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffdu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp - 3], 0 */
    W8((uint32_t)(c->ebp + 0xfffffffcu), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp - 4], al */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
L_00b26f27:;
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
    PUSH32(c, 0x00b26f3eu); f_00b2b6e2(c); /* call 0xb2b6e2 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b26f47; /* jne 0xb26f47 */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b26f47:;
    c->eax = (uint32_t)((uint32_t)R16((uint32_t)(c->ebp + 0xau))); /* movzx eax, word ptr [ebp + 0xa] */
L_00b26f4b:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & R32((uint32_t)(c->ebp + 0xcu))))); /* and eax, dword ptr [ebp + 0xc] */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b26f50(CPU *c) { /* FUN_10006f50 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x30000u; PUSH32(c, v_); } /* push 0x30000 */
    { uint32_t v_ = 0x10000u; PUSH32(c, v_); } /* push 0x10000 */
    PUSH32(c, 0x00b26f5fu); f_00b2b860(c); /* call 0xb2b860 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00b26f62(CPU *c) { /* FUN_10006f62 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    FPUSH(c, RF64((uint32_t)(0xb2e378u))); /* fld qword ptr [0x1000e378] */
    WF64((uint32_t)(c->ebp + 0xfffffff8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 8] */
    FPUSH(c, RF64((uint32_t)(0xb2e370u))); /* fld qword ptr [0x1000e370] */
    WF64((uint32_t)(c->ebp + 0xfffffff0u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0x10] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff0u))); /* fld qword ptr [ebp - 0x10] */
    ST(0) = FPRES(c, FDIV(c, ST(0), RF64((uint32_t)(c->ebp + 0xfffffff8u)))); /* fdiv qword ptr [ebp - 8] */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->ebp + 0xfffffff8u))); /* fmul qword ptr [ebp - 8] */
    ST(0) = FPRES(c, RF64((uint32_t)(c->ebp + 0xfffffff0u)) - ST(0)); /* fsubr qword ptr [ebp - 0x10] */
    WF64((uint32_t)(c->ebp + 0xffffffe8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0x18] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xffffffe8u))); /* fld qword ptr [ebp - 0x18] */
    FCOM(c, ST(0), RF64((uint32_t)(0xb2e368u))); FPOP(c); /* fcomp qword ptr [0x1000e368] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if ((c->cf || c->zf)) goto L_00b26f9c; /* jbe 0xb26f9c */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b26f9c:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b26fa0(CPU *c) { /* FUN_10006fa0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xb2e39cu; PUSH32(c, v_); } /* push 0x1000e39c */
    { uint32_t t_ = R32((uint32_t)(0xb2e048u)); PUSH32(c, 0x00b26fabu); call_indirect(c, t_); } /* call dword ptr [0x1000e048] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b26fc4; /* je 0xb26fc4 */
    { uint32_t v_ = 0xb2e380u; PUSH32(c, v_); } /* push 0x1000e380 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0xb2e044u)); PUSH32(c, 0x00b26fbbu); call_indirect(c, t_); } /* call dword ptr [0x1000e044] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b26fc4; /* je 0xb26fc4 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00b26fc3u); call_indirect(c, t_); } /* call eax */
    c->esp += 4; return; /* ret  */
L_00b26fc4:;
    { f_00b26f62(c); return; } /* jmp 0xb26f62 */
}

void f_00b26fc9(CPU *c) { /* FUN_10006fc9 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->esi))); /* movsx eax, byte ptr [esi] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b26fd7u); f_00b2b991(c); /* call 0xb2b991 */
    (void)sub32(c, c->eax, (uint32_t)0x65u); /* cmp eax, 0x65 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00b27009; /* je 0xb27009 */
L_00b26fdd:;
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub32(c, R32((uint32_t)(0xb3060cu)), (uint32_t)0x1u); /* cmp dword ptr [0x1001060c], 1 */
    if ((c->zf || c->sf != c->of)) goto L_00b26ff6; /* jle 0xb26ff6 */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->esi))); /* movsx eax, byte ptr [esi] */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b26ff2u); f_00b26edb(c); /* call 0xb26edb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00b27005; /* jmp 0xb27005 */
L_00b26ff6:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->esi))); /* movsx eax, byte ptr [esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb30400u))); /* mov ecx, dword ptr [0x10010400] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4u))); /* and eax, 4 */
L_00b27005:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b26fdd; /* jne 0xb26fdd */
L_00b27009:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0xb30610u))); /* mov cl, byte ptr [0x10010610] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esi], cl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_00b27014:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov cl, byte ptr [esi] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [esi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(((uint8_t)c->ecx)); /* mov al, cl */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov cl, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_00b27014; /* jne 0xb27014 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b27023(CPU *c) { /* PTR_00b27023 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0xb30610u))); /* mov dl, byte ptr [0x10010610] */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_00b2703f; /* je 0xb2703f */
L_00b27033:;
    (void)sub8(c, ((uint8_t)c->ecx), ((uint8_t)c->edx)); /* cmp cl, dl */
    if (c->zf) goto L_00b2703f; /* je 0xb2703f */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1u))); /* mov cl, byte ptr [eax + 1] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_00b27033; /* jne 0xb27033 */
L_00b2703f:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_00b27070; /* je 0xb27070 */
L_00b27046:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_00b27059; /* je 0xb27059 */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x65u); /* cmp cl, 0x65 */
    if (c->zf) goto L_00b27059; /* je 0xb27059 */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x45u); /* cmp cl, 0x45 */
    if (c->zf) goto L_00b27059; /* je 0xb27059 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_00b27046; /* jmp 0xb27046 */
L_00b27059:;
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
L_00b2705b:;
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x30u); /* cmp byte ptr [eax], 0x30 */
    if (c->zf) goto L_00b2705b; /* je 0xb2705b */
    (void)sub8(c, R8((uint32_t)(c->eax)), ((uint8_t)c->edx)); /* cmp byte ptr [eax], dl */
    if (!c->zf) goto L_00b27066; /* jne 0xb27066 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
L_00b27066:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov dl, byte ptr [ecx] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [eax], dl */
    if (!c->zf) goto L_00b27066; /* jne 0xb27066 */
L_00b27070:;
    c->esp += 4; return; /* ret  */
}

void f_00b27071(CPU *c) { /* PTR_00b27071 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    FPUSH(c, RF64((uint32_t)(c->eax))); /* fld qword ptr [eax] */
    FCOM(c, ST(0), RF64((uint32_t)(0xb2e3a8u))); FPOP(c); /* fcomp qword ptr [0x1000e3a8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (c->cf) goto L_00b27086; /* jb 0xb27086 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
L_00b27086:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_00b27089(CPU *c) { /* __fassign */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    if (c->zf) goto L_00b270b2; /* je 0xb270b2 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b270a0u); f_00b2b1b7(c); /* call 0xb2b1b7 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 4], ecx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b270b2:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b270bbu); f_00b2b1e4(c); /* call 0xb2b1e4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b270c7(CPU *c) { /* FUN_100070c7 */
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
    PUSH32(c, 0x00b270e5u); f_00b2bb42(c); /* call 0xb2bb42 */
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
    PUSH32(c, 0x00b2710du); f_00b2bacb(c); /* call 0xb2bacb */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x00b2711fu); f_00b27128(c); /* call 0xb27128 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x30u)); /* add esp, 0x30 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b27128(CPU *c) { /* FUN_10007128 */
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
    if (c->zf) goto L_00b27156; /* je 0xb27156 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->ebx); /* cmp dword ptr [ebp + 0xc], ebx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((!c->zf && c->sf == c->of) ? 1 : 0); /* setg al */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x2du); /* cmp dword ptr [esi], 0x2d */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete al */
    c->eax = (uint32_t)(add32(c, c->eax, c->edi)); /* add eax, edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b27154u); f_00b273ca(c); /* call 0xb273ca */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b27156:;
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x2du); /* cmp dword ptr [esi], 0x2d */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    if (!c->zf) goto L_00b27163; /* jne 0xb27163 */
    W8((uint32_t)(c->edi), (uint8_t)((uint8_t)0x2du)); /* mov byte ptr [edi], 0x2d */
    c->eax = (uint32_t)((uint32_t)(c->edi + 0x1u)); /* lea eax, [edi + 1] */
L_00b27163:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->ebx); /* cmp dword ptr [ebp + 0xc], ebx */
    if ((c->zf || c->sf != c->of)) goto L_00b2717a; /* jle 0xb2717a */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1u))); /* mov dl, byte ptr [eax + 1] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x1u)); /* lea ecx, [eax + 1] */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [eax], dl */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0xb30610u))); /* mov cl, byte ptr [0x10010610] */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax], cl */
L_00b2717a:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x18u)), ((uint8_t)c->ebx)); /* cmp byte ptr [ebp + 0x18], bl */
    { uint32_t v_ = 0xb2e3b0u; PUSH32(c, v_); } /* push 0x1000e3b0 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete cl */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    c->ecx = (uint32_t)(add32(c, c->ecx, R32((uint32_t)(c->ebp + 0xcu)))); /* add ecx, dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00b27192u); f_00b2bc60(c); /* call 0xb2bc60 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), c->ebx); /* cmp dword ptr [ebp + 0x10], ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    if (c->zf) goto L_00b2719e; /* je 0xb2719e */
    W8((uint32_t)(c->ecx), (uint8_t)((uint8_t)0x45u)); /* mov byte ptr [ecx], 0x45 */
L_00b2719e:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x30u); /* cmp byte ptr [eax], 0x30 */
    if (c->zf) goto L_00b271e3; /* je 0xb271e3 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ebx, dword ptr [esi + 4] */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->sf) goto L_00b271b2; /* jns 0xb271b2 */
    c->ebx = (uint32_t)(neg32(c, c->ebx)); /* neg ebx */
    W8((uint32_t)(c->ecx), (uint8_t)((uint8_t)0x2du)); /* mov byte ptr [ecx], 0x2d */
L_00b271b2:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->ebx, (uint32_t)0x64u); /* cmp ebx, 0x64 */
    if ((c->sf != c->of)) goto L_00b271c9; /* jl 0xb271c9 */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = 0x64u; PUSH32(c, v_); } /* push 0x64 */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00b271beu, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [ecx], al */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00b271c5u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
    c->ebx = (uint32_t)(c->edx); /* mov ebx, edx */
L_00b271c9:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->ebx, (uint32_t)0xau); /* cmp ebx, 0xa */
    if ((c->sf != c->of)) goto L_00b271e0; /* jl 0xb271e0 */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = 0xau; PUSH32(c, v_); } /* push 0xa */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00b271d5u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [ecx], al */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00b271dcu, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
    c->ebx = (uint32_t)(c->edx); /* mov ebx, edx */
L_00b271e0:;
    { uint32_t a_ = (uint32_t)(c->ecx + 0x1u); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ebx)))); } /* add byte ptr [ecx + 1], bl */
L_00b271e3:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00b271ea(CPU *c) { /* FUN_100071ea */
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
    PUSH32(c, 0x00b27208u); f_00b2bb42(c); /* call 0xb2bb42 */
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
    PUSH32(c, 0x00b27227u); f_00b2bacb(c); /* call 0xb2bacb */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x00b27236u); f_00b2723f(c); /* call 0xb2723f */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b2723f(CPU *c) { /* FUN_1000723f */
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
    if (c->zf) goto L_00b2726f; /* je 0xb2726f */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xcu))); /* cmp eax, dword ptr [ebp + 0xc] */
    if (!c->zf) goto L_00b2726f; /* jne 0xb2726f */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x2du); /* cmp dword ptr [esi], 0x2d */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete cl */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->ebx)); /* add ecx, ebx */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    W8((uint32_t)(c->eax), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [eax], 0x30 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x1u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax + 1], 0 */
L_00b2726f:;
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x2du); /* cmp dword ptr [esi], 0x2d */
    c->edi = (uint32_t)(c->ebx); /* mov edi, ebx */
    if (!c->zf) goto L_00b2727c; /* jne 0xb2727c */
    W8((uint32_t)(c->ebx), (uint8_t)((uint8_t)0x2du)); /* mov byte ptr [ebx], 0x2d */
    c->edi = (uint32_t)((uint32_t)(c->ebx + 0x1u)); /* lea edi, [ebx + 1] */
L_00b2727c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((!c->zf && c->sf == c->of)) goto L_00b27293; /* jg 0xb27293 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b2728bu); f_00b273ca(c); /* call 0xb273ca */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W8((uint32_t)(c->edi), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [edi], 0x30 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_00b27295; /* jmp 0xb27295 */
L_00b27293:;
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
L_00b27295:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    if ((c->zf || c->sf != c->of)) goto L_00b272df; /* jle 0xb272df */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b272a3u); f_00b273ca(c); /* call 0xb273ca */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0xb30610u))); /* mov al, byte ptr [0x10010610] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov esi, dword ptr [esi + 4] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if ((c->sf == c->of)) goto L_00b272df; /* jge 0xb272df */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x14u)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0x14], 0 */
    if (c->zf) goto L_00b272be; /* je 0xb272be */
    c->esi = (uint32_t)(neg32(c, c->esi)); /* neg esi */
    goto L_00b272c5; /* jmp 0xb272c5 */
L_00b272be:;
    c->esi = (uint32_t)(neg32(c, c->esi)); /* neg esi */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->esi); /* cmp dword ptr [ebp + 0xc], esi */
    if ((c->sf != c->of)) goto L_00b272c8; /* jl 0xb272c8 */
L_00b272c5:;
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_00b272c8:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b272d1u); f_00b273ca(c); /* call 0xb273ca */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = 0x30u; PUSH32(c, v_); } /* push 0x30 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b272dcu); f_00b2bd50(c); /* call 0xb2bd50 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
L_00b272df:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00b272e6(CPU *c) { /* FUN_100072e6 */
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
    PUSH32(c, 0x00b27306u); f_00b2bb42(c); /* call 0xb2bb42 */
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
    PUSH32(c, 0x00b27328u); f_00b2bacb(c); /* call 0xb2bacb */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)((c->sf != c->of) ? 1 : 0); /* setl cl */
    (void)sub32(c, c->eax, (uint32_t)0xfffffffcu); /* cmp eax, -4 */
    if ((c->sf != c->of)) goto L_00b2735f; /* jl 0xb2735f */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if ((c->sf == c->of)) goto L_00b2735f; /* jge 0xb2735f */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_00b2734b; /* je 0xb2734b */
L_00b27341:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov al, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00b27341; /* jne 0xb27341 */
    { uint32_t a_ = (uint32_t)(c->edi + 0xfffffffeu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & ((uint8_t)c->eax))))); } /* and byte ptr [edi - 2], al */
L_00b2734b:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x00b2735au); f_00b2723f(c); /* call 0xb2723f */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    goto L_00b27374; /* jmp 0xb27374 */
L_00b2735f:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x00b27371u); f_00b27128(c); /* call 0xb27128 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
L_00b27374:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b27379(CPU *c) { /* __cfltcvt */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), (uint32_t)0x65u); /* cmp dword ptr [ebp + 0x10], 0x65 */
    if (c->zf) goto L_00b273b4; /* je 0xb273b4 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), (uint32_t)0x45u); /* cmp dword ptr [ebp + 0x10], 0x45 */
    if (c->zf) goto L_00b273b4; /* je 0xb273b4 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), (uint32_t)0x66u); /* cmp dword ptr [ebp + 0x10], 0x66 */
    if (!c->zf) goto L_00b273a1; /* jne 0xb273a1 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00b2739cu); f_00b271ea(c); /* call 0xb271ea */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
L_00b273a1:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00b273b2u); f_00b272e6(c); /* call 0xb272e6 */
    goto L_00b273c5; /* jmp 0xb273c5 */
L_00b273b4:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00b273c5u); f_00b270c7(c); /* call 0xb270c7 */
L_00b273c5:;
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00b273ca(CPU *c) { /* FUN_100073ca */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edi, dword ptr [esp + 0xc] */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00b273ed; /* je 0xb273ed */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov esi, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b273deu); f_00b26e60(c); /* call 0xb26e60 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(add32(c, c->esi, c->edi)); /* add esi, edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b273e9u); f_00b29430(c); /* call 0xb29430 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00b273ed:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00b273f0(CPU *c) { /* PTR_00b273f0 */
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
    if (!c->zf) goto L_00b27498; /* jne 0xb27498 */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    W32((uint32_t)(c->ebx + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebx - 4], eax */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebx + 0xcu))); /* mov esi, dword ptr [ebx + 0xc] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov edi, dword ptr [ebx + 8] */
L_00b2742b:;
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (c->zf) goto L_00b27491; /* je 0xb27491 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea ecx, [esi + esi*2] */
    (void)sub32(c, R32((uint32_t)(c->edi + c->ecx * 4 + 0x4u)), (uint32_t)0x0u); /* cmp dword ptr [edi + ecx*4 + 4], 0 */
    if (c->zf) goto L_00b2747f; /* je 0xb2747f */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)((uint32_t)(c->ebx + 0x10u)); /* lea ebp, [ebx + 0x10] */
    { uint32_t t_ = R32((uint32_t)(c->edi + c->ecx * 4 + 0x4u)); PUSH32(c, 0x00b27443u); call_indirect(c, t_); } /* call dword ptr [edi + ecx*4 + 4] */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ebx, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->eax))); /* or eax, eax */
    if (c->zf) goto L_00b2747f; /* je 0xb2747f */
    if (c->sf) goto L_00b2748a; /* js 0xb2748a */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov edi, dword ptr [ebx + 8] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b27457u); f_00b25658(c); /* call 0xb25658 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->ebp = (uint32_t)((uint32_t)(c->ebx + 0x10u)); /* lea ebp, [ebx + 0x10] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b27464u); f_00b2569a(c); /* call 0xb2569a */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea ecx, [esi + esi*2] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + c->ecx * 4 + 0x8u))); /* mov eax, dword ptr [edi + ecx*4 + 8] */
    PUSH32(c, 0x00b27475u); f_00b2572e(c); /* call 0xb2572e */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + c->ecx * 4))); /* mov eax, dword ptr [edi + ecx*4] */
    W32((uint32_t)(c->ebx + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 0xc], eax */
    { uint32_t t_ = R32((uint32_t)(c->edi + c->ecx * 4 + 0x8u)); PUSH32(c, 0x00b2747fu); call_indirect(c, t_); } /* call dword ptr [edi + ecx*4 + 8] */
L_00b2747f:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov edi, dword ptr [ebx + 8] */
    c->ecx = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea ecx, [esi + esi*2] */
    c->esi = (uint32_t)(R32((uint32_t)(c->edi + c->ecx * 4))); /* mov esi, dword ptr [edi + ecx*4] */
    goto L_00b2742b; /* jmp 0xb2742b */
L_00b2748a:;
    c->eax = (uint32_t)((uint32_t)0x0u); /* mov eax, 0 */
    goto L_00b274ad; /* jmp 0xb274ad */
L_00b27491:;
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    goto L_00b274ad; /* jmp 0xb274ad */
L_00b27498:;
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)((uint32_t)(c->ebx + 0x10u)); /* lea ebp, [ebx + 0x10] */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b274a4u); f_00b2569a(c); /* call 0xb2569a */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
L_00b274ad:;
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00b274b5(CPU *c) { /* FUN_100074b5 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov ebp, dword ptr [ecx] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x1cu))); /* mov eax, dword ptr [ecx + 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x18u))); /* mov eax, dword ptr [ecx + 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b274c9u); f_00b2569a(c); /* call 0xb2569a */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 8; return; /* ret 4 */
}

void f_00b274d0(CPU *c) { /* FUN_100074d0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(0xb2e04cu))); /* mov esi, dword ptr [0x1000e04c] */
    { uint32_t v_ = R32((uint32_t)(0xb30674u)); PUSH32(c, v_); } /* push dword ptr [0x10010674] */
    { uint32_t t_ = c->esi; PUSH32(c, 0x00b274dfu); call_indirect(c, t_); } /* call esi */
    { uint32_t v_ = R32((uint32_t)(0xb30664u)); PUSH32(c, v_); } /* push dword ptr [0x10010664] */
    { uint32_t t_ = c->esi; PUSH32(c, 0x00b274e7u); call_indirect(c, t_); } /* call esi */
    { uint32_t v_ = R32((uint32_t)(0xb30654u)); PUSH32(c, v_); } /* push dword ptr [0x10010654] */
    { uint32_t t_ = c->esi; PUSH32(c, 0x00b274efu); call_indirect(c, t_); } /* call esi */
    { uint32_t v_ = R32((uint32_t)(0xb30634u)); PUSH32(c, v_); } /* push dword ptr [0x10010634] */
    { uint32_t t_ = c->esi; PUSH32(c, 0x00b274f7u); call_indirect(c, t_); } /* call esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b274f9(CPU *c) { /* FUN_100074f9 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(0xb2e050u))); /* mov edi, dword ptr [0x1000e050] */
    c->esi = (uint32_t)((uint32_t)0xb30630u); /* mov esi, 0x10010630 */
L_00b27506:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b27537; /* je 0xb27537 */
    (void)sub32(c, c->esi, (uint32_t)0xb30674u); /* cmp esi, 0x10010674 */
    if (c->zf) goto L_00b27537; /* je 0xb27537 */
    (void)sub32(c, c->esi, (uint32_t)0xb30664u); /* cmp esi, 0x10010664 */
    if (c->zf) goto L_00b27537; /* je 0xb27537 */
    (void)sub32(c, c->esi, (uint32_t)0xb30654u); /* cmp esi, 0x10010654 */
    if (c->zf) goto L_00b27537; /* je 0xb27537 */
    (void)sub32(c, c->esi, (uint32_t)0xb30634u); /* cmp esi, 0x10010634 */
    if (c->zf) goto L_00b27537; /* je 0xb27537 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00b2752fu); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    PUSH32(c, 0x00b27536u); f_00b275db(c); /* call 0xb275db */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b27537:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, c->esi, (uint32_t)0xb306f0u); /* cmp esi, 0x100106f0 */
    if ((c->sf != c->of)) goto L_00b27506; /* jl 0xb27506 */
    { uint32_t v_ = R32((uint32_t)(0xb30654u)); PUSH32(c, v_); } /* push dword ptr [0x10010654] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00b2754au); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = R32((uint32_t)(0xb30664u)); PUSH32(c, v_); } /* push dword ptr [0x10010664] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00b27552u); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = R32((uint32_t)(0xb30674u)); PUSH32(c, v_); } /* push dword ptr [0x10010674] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00b2755au); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = R32((uint32_t)(0xb30634u)); PUSH32(c, v_); } /* push dword ptr [0x10010634] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00b27562u); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b27565(CPU *c) { /* FUN_10007565 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    (void)sub32(c, R32((uint32_t)(c->eax * 4 + 0xb30630u)), (uint32_t)0x0u); /* cmp dword ptr [eax*4 + 0x10010630], 0 */
    c->esi = (uint32_t)((uint32_t)(c->eax * 4 + 0xb30630u)); /* lea esi, [eax*4 + 0x10010630] */
    if (!c->zf) goto L_00b275bb; /* jne 0xb275bb */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    PUSH32(c, 0x00b27585u); f_00b26c9a(c); /* call 0xb26c9a */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (!c->zf) goto L_00b27594; /* jne 0xb27594 */
    { uint32_t v_ = 0x11u; PUSH32(c, v_); } /* push 0x11 */
    PUSH32(c, 0x00b27593u); f_00b25c98(c); /* call 0xb25c98 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b27594:;
    { uint32_t v_ = 0x11u; PUSH32(c, v_); } /* push 0x11 */
    PUSH32(c, 0x00b2759bu); f_00b27565(c); /* call 0xb27565 */
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x0u); /* cmp dword ptr [esi], 0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00b275ac; /* jne 0xb275ac */
    { uint32_t t_ = R32((uint32_t)(0xb2e04cu)); PUSH32(c, 0x00b275a8u); call_indirect(c, t_); } /* call dword ptr [0x1000e04c] */
    W32((uint32_t)(c->esi), (uint32_t)(c->edi)); /* mov dword ptr [esi], edi */
    goto L_00b275b2; /* jmp 0xb275b2 */
L_00b275ac:;
    PUSH32(c, 0x00b275b1u); f_00b275db(c); /* call 0xb275db */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b275b2:;
    { uint32_t v_ = 0x11u; PUSH32(c, v_); } /* push 0x11 */
    PUSH32(c, 0x00b275b9u); f_00b275c6(c); /* call 0xb275c6 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_00b275bb:;
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(0xb2e054u)); PUSH32(c, 0x00b275c3u); call_indirect(c, t_); } /* call dword ptr [0x1000e054] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00b275c6(CPU *c) { /* FUN_100075c6 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->eax * 4 + 0xb30630u)); PUSH32(c, v_); } /* push dword ptr [eax*4 + 0x10010630] */
    { uint32_t t_ = R32((uint32_t)(0xb2e058u)); PUSH32(c, 0x00b275d9u); call_indirect(c, t_); } /* call dword ptr [0x1000e058] */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00b275db(CPU *c) { /* FUN_100075db */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xb2e3b8u; PUSH32(c, v_); } /* push 0x1000e3b8 */
    { uint32_t v_ = 0xb273f8u; PUSH32(c, v_); } /* push 0x100073f8 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00b276b5; /* je 0xb276b5 */
    c->eax = (uint32_t)(R32((uint32_t)(0xb33a28u))); /* mov eax, dword ptr [0x10013a28] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_00b2764e; /* jne 0xb2764e */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b2761au); f_00b27565(c); /* call 0xb27565 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b27625u); f_00b29901(c); /* call 0xb29901 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b27636; /* je 0xb27636 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b27634u); f_00b2992c(c); /* call 0xb2992c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b27636:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b2763fu); f_00b27645(c); /* call 0xb27645 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x1c], 0 */
    goto L_00b27696; /* jmp 0xb27696 */
L_00b2764e:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00b276a6; /* jne 0xb276a6 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b2765au); f_00b27565(c); /* call 0xb27565 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe0u)); /* lea eax, [ebp - 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd8u)); /* lea eax, [ebp - 0x28] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b27670u); f_00b2a65c(c); /* call 0xb2a65c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b27689; /* je 0xb27689 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x28] */
    PUSH32(c, 0x00b27686u); f_00b2a6b3(c); /* call 0xb2a6b3 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_00b27689:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b27692u); f_00b2769d(c); /* call 0xb2769d */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
L_00b27696:;
    if (!c->zf) goto L_00b276b5; /* jne 0xb276b5 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    goto L_00b276a7; /* jmp 0xb276a7 */
L_00b276a6:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
L_00b276a7:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb33a24u)); PUSH32(c, v_); } /* push dword ptr [0x10013a24] */
    { uint32_t t_ = R32((uint32_t)(0xb2e05cu)); PUSH32(c, 0x00b276b5u); call_indirect(c, t_); } /* call dword ptr [0x1000e05c] */
L_00b276b5:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b27645(CPU *c) { /* FUN_10007645 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b2764cu); f_00b275c6(c); /* call 0xb275c6 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00b2764e(CPU *c) { /* PTR_00b2764e */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) { f_00b276a6(c); return; } /* jne 0xb276a6 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b2765au); f_00b27565(c); /* call 0xb27565 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe0u)); /* lea eax, [ebp - 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd8u)); /* lea eax, [ebp - 0x28] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b27670u); f_00b2a65c(c); /* call 0xb2a65c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b27689; /* je 0xb27689 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x28] */
    PUSH32(c, 0x00b27686u); f_00b2a6b3(c); /* call 0xb2a6b3 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_00b27689:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b27692u); f_00b2769d(c); /* call 0xb2769d */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) { f_00b276b5(c); return; } /* jne 0xb276b5 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { f_00b276a7(c); return; } /* jmp 0xb276a7 */
}

void f_00b27689(CPU *c) { /* PTR_00b27689 */
    PREEMPT_POLL(c);
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b27692u); f_00b2769d(c); /* call 0xb2769d */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) { f_00b276b5(c); return; } /* jne 0xb276b5 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { f_00b276a7(c); return; } /* jmp 0xb276a7 */
}

void f_00b27696(CPU *c) { /* PTR_00b27696 */
    PREEMPT_POLL(c);
    if (!c->zf) { f_00b276b5(c); return; } /* jne 0xb276b5 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { f_00b276a7(c); return; } /* jmp 0xb276a7 */
}

void f_00b2769d(CPU *c) { /* FUN_1000769d */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b276a4u); f_00b275c6(c); /* call 0xb275c6 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00b276a6(CPU *c) { /* PTR_00b276a6 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb33a24u)); PUSH32(c, v_); } /* push dword ptr [0x10013a24] */
    { uint32_t t_ = R32((uint32_t)(0xb2e05cu)); PUSH32(c, 0x00b276b5u); call_indirect(c, t_); } /* call dword ptr [0x1000e05c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b276a7(CPU *c) { /* PTR_00b276a7 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb33a24u)); PUSH32(c, v_); } /* push dword ptr [0x10013a24] */
    { uint32_t t_ = R32((uint32_t)(0xb2e05cu)); PUSH32(c, 0x00b276b5u); call_indirect(c, t_); } /* call dword ptr [0x1000e05c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b276b5(CPU *c) { /* PTR_00b276b5 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b276d0(CPU *c) { /* _strcmp */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u)); /* test edx, 3 */
    if (!c->zf) goto L_00b2771c; /* jne 0xb2771c */
L_00b276e0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edx))); /* mov eax, dword ptr [edx] */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->ecx))); /* cmp al, byte ptr [ecx] */
    if (!c->zf) goto L_00b27714; /* jne 0xb27714 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00b27710; /* je 0xb27710 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), R8((uint32_t)(c->ecx + 0x1u))); /* cmp ah, byte ptr [ecx + 1] */
    if (!c->zf) goto L_00b27714; /* jne 0xb27714 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | ((uint8_t)(c->eax >> 8))))) << 8); /* or ah, ah */
    if (c->zf) goto L_00b27710; /* je 0xb27710 */
    c->eax = (uint32_t)(shr32(c, c->eax, 16)); /* shr eax, 0x10 */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->ecx + 0x2u))); /* cmp al, byte ptr [ecx + 2] */
    if (!c->zf) goto L_00b27714; /* jne 0xb27714 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00b27710; /* je 0xb27710 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), R8((uint32_t)(c->ecx + 0x3u))); /* cmp ah, byte ptr [ecx + 3] */
    if (!c->zf) goto L_00b27714; /* jne 0xb27714 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x4u)); /* add edx, 4 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | ((uint8_t)(c->eax >> 8))))) << 8); /* or ah, ah */
    if (!c->zf) goto L_00b276e0; /* jne 0xb276e0 */
    c->edi = (uint32_t)(c->edi); /* mov edi, edi */
L_00b27710:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_00b27714:;
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(shl32(c, c->eax, 1)); /* shl eax, 1 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->esp += 4; return; /* ret  */
L_00b2771c:;
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x1u)); /* test edx, 1 */
    if (c->zf) goto L_00b27738; /* je 0xb27738 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov al, byte ptr [edx] */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->ecx))); /* cmp al, byte ptr [ecx] */
    if (!c->zf) goto L_00b27714; /* jne 0xb27714 */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00b27710; /* je 0xb27710 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x2u)); /* test edx, 2 */
    if (c->zf) goto L_00b276e0; /* je 0xb276e0 */
L_00b27738:;
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->edx))); /* mov ax, word ptr [edx] */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x2u)); /* add edx, 2 */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->ecx))); /* cmp al, byte ptr [ecx] */
    if (!c->zf) goto L_00b27714; /* jne 0xb27714 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00b27710; /* je 0xb27710 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), R8((uint32_t)(c->ecx + 0x1u))); /* cmp ah, byte ptr [ecx + 1] */
    if (!c->zf) goto L_00b27714; /* jne 0xb27714 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | ((uint8_t)(c->eax >> 8))))) << 8); /* or ah, ah */
    if (c->zf) goto L_00b27710; /* je 0xb27710 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x2u)); /* add ecx, 2 */
    goto L_00b276e0; /* jmp 0xb276e0 */
}

void f_00b27754(CPU *c) { /* FUN_10007754 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xe06d7363u); /* cmp dword ptr [eax], 0xe06d7363 */
    if (!c->zf) goto L_00b27777; /* jne 0xb27777 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [eax + 0x10], 3 */
    if (!c->zf) goto L_00b27777; /* jne 0xb27777 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x14u)), (uint32_t)0x19930520u); /* cmp dword ptr [eax + 0x14], 0x19930520 */
    if (!c->zf) goto L_00b27777; /* jne 0xb27777 */
    { f_00b266a8(c); return; } /* jmp 0xb266a8 */
L_00b27777:;
    c->eax = (uint32_t)(R32((uint32_t)(0xb33530u))); /* mov eax, dword ptr [0x10013530] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b27794; /* je 0xb27794 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b27786u); f_00b29417(c); /* call 0xb29417 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00b27794; /* je 0xb27794 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(0xb33530u)); PUSH32(c, 0x00b27792u); call_indirect(c, t_); } /* call dword ptr [0x10013530] */
    goto L_00b27796; /* jmp 0xb27796 */
L_00b27794:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00b27796:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00b2779a(CPU *c) { /* PTR_00b2779a */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xb27754u; PUSH32(c, v_); } /* push 0x10007754 */
    { uint32_t t_ = R32((uint32_t)(0xb2e060u)); PUSH32(c, 0x00b277a5u); call_indirect(c, t_); } /* call dword ptr [0x1000e060] */
    W32((uint32_t)(0xb33530u), (uint32_t)(c->eax)); /* mov dword ptr [0x10013530], eax */
    c->esp += 4; return; /* ret  */
}

void f_00b277ab(CPU *c) { /* PTR_00b277ab */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(0xb33530u)); PUSH32(c, v_); } /* push dword ptr [0x10013530] */
    { uint32_t t_ = R32((uint32_t)(0xb2e060u)); PUSH32(c, 0x00b277b7u); call_indirect(c, t_); } /* call dword ptr [0x1000e060] */
    c->esp += 4; return; /* ret  */
}

void f_00b277c0(CPU *c) { /* __cintrindisp2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xfffffd30u)); /* add esp, 0xfffffd30 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    ; /* wait  */
    W16((uint32_t)(c->ebp + 0xffffff5cu), c->fpu_cw); /* fnstcw word ptr [ebp - 0xa4] */
    ; /* wait  */
    (void)sub32(c, R32((uint32_t)(0xb32d08u)), (uint32_t)0x0u); /* cmp dword ptr [0x10012d08], 0 */
    if (c->zf) goto L_00b277ef; /* je 0xb277ef */
L_00b277db:;
    PUSH32(c, 0x00b277e0u); f_00b27a97(c); /* call 0xb27a97 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffd38u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x3u)))); } /* or byte ptr [ebp - 0x2c8], 3 */
    PUSH32(c, 0x00b277ecu); f_00b2788a(c); /* call 0xb2788a */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b277ef:;
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    WF64((uint32_t)(c->ebp + 0xffffff7au), ST(0)); /* fst qword ptr [ebp - 0x86] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    WF64((uint32_t)(c->ebp + 0xffffff82u), ST(0)); /* fst qword ptr [ebp - 0x7e] */
    goto L_00b277db; /* jmp 0xb277db */
}

void f_00b277fe(CPU *c) { /* __cintrindisp1 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xfffffd30u)); /* add esp, 0xfffffd30 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    ; /* wait  */
    W16((uint32_t)(c->ebp + 0xffffff5cu), c->fpu_cw); /* fnstcw word ptr [ebp - 0xa4] */
    (void)sub32(c, R32((uint32_t)(0xb32d08u)), (uint32_t)0x0u); /* cmp dword ptr [0x10012d08], 0 */
    if (c->zf) goto L_00b27833; /* je 0xb27833 */
L_00b27818:;
    PUSH32(c, 0x00b2781du); f_00b27a30(c); /* call 0xb27a30 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffd38u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x1u)))); } /* or byte ptr [ebp - 0x2c8], 1 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffd38u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0xfdu)))); } /* and byte ptr [ebp - 0x2c8], 0xfd */
    PUSH32(c, 0x00b27830u); f_00b2788a(c); /* call 0xb2788a */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b27833:;
    WF64((uint32_t)(c->ebp + 0xffffff7au), ST(0)); /* fst qword ptr [ebp - 0x86] */
    goto L_00b27818; /* jmp 0xb27818 */
}

void f_00b2783b(CPU *c) { /* __ctrandisp2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xfffffd30u)); /* add esp, 0xfffffd30 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00b27850u); f_00b279ee(c); /* call 0xb279ee */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    PUSH32(c, 0x00b2785eu); f_00b279ee(c); /* call 0xb279ee */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    ; /* wait  */
    W16((uint32_t)(c->ebp + 0xffffff5cu), c->fpu_cw); /* fnstcw word ptr [ebp - 0xa4] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffd38u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x2u)))); } /* or byte ptr [ebp - 0x2c8], 2 */
    W8((uint32_t)(c->ebp + 0xffffff71u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ebp - 0x8f], 1 */
    PUSH32(c, 0x00b2787bu); f_00b27a97(c); /* call 0xb27a97 */
    PUSH32(c, 0x00b27880u); f_00b27883(c); /* call 0xb27883 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b27883(CPU *c) { /* FUN_10007883 */
    PREEMPT_POLL(c);
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffd38u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0xfeu)))); } /* and byte ptr [ebp - 0x2c8], 0xfe */
    { f_00b2788a(c); return; }
}

void f_00b2788a(CPU *c) { /* FUN_1000788a */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(0xb33470u)), (uint32_t)0x0u); /* cmp dword ptr [0x10013470], 0 */
    if (!c->zf) goto L_00b278df; /* jne 0xb278df */
    WF64((uint32_t)(c->ebp + 0xfffffd30u), ST(0)); /* fst qword ptr [ebp - 0x2d0] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0xffffff70u))); /* mov al, byte ptr [ebp - 0x90] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00b278bd; /* je 0xb278bd */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0xffu); /* cmp al, 0xff */
    if (c->zf) goto L_00b278e7; /* je 0xb278e7 */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0xfeu); /* cmp al, 0xfe */
    if (c->zf) goto L_00b278e7; /* je 0xb278e7 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00b278df; /* je 0xb278df */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->eax)); /* movsx eax, al */
    W32((uint32_t)(c->ebp + 0xffffff72u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x8e], eax */
    goto L_00b27959; /* jmp 0xb27959 */
L_00b278bd:;
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ebp + 0xffffff5cu))); /* mov ax, word ptr [ebp - 0xa4] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->eax) & (uint16_t)0x20u))); /* and ax, 0x20 */
    if (!c->zf) goto L_00b278df; /* jne 0xb278df */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->eax) & (uint16_t)0x20u))); /* and ax, 0x20 */
    if (c->zf) goto L_00b278df; /* je 0xb278df */
    W32((uint32_t)(c->ebp + 0xffffff72u), (uint32_t)((uint32_t)0x8u)); /* mov dword ptr [ebp - 0x8e], 8 */
    goto L_00b27959; /* jmp 0xb27959 */
L_00b278df:;
    c->fpu_cw = R16((uint32_t)(c->ebp + 0xffffff5cu)); fpu_sync_rounding(c); /* fldcw word ptr [ebp - 0xa4] */
    ; /* wait  */
    c->esp += 4; return; /* ret  */
L_00b278e7:;
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ebp + 0xfffffd36u))); /* mov ax, word ptr [ebp - 0x2ca] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->eax) & (uint16_t)0x7ff0u))); /* and ax, 0x7ff0 */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->eax) | ((uint16_t)c->eax)))); /* or ax, ax */
    if (c->zf) goto L_00b278ff; /* je 0xb278ff */
    (void)sub16(c, ((uint16_t)c->eax), (uint16_t)0x7ff0u); /* cmp ax, 0x7ff0 */
    if (c->zf) goto L_00b2792d; /* je 0xb2792d */
    goto L_00b278bd; /* jmp 0xb278bd */
L_00b278ff:;
    W32((uint32_t)(c->ebp + 0xffffff72u), (uint32_t)((uint32_t)0x4u)); /* mov dword ptr [ebp - 0x8e], 4 */
    FPUSH(c, RF64((uint32_t)(0xb2e3e8u))); /* fld qword ptr [0x1000e3e8] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = ldexp(ST(0), (int)trunc(ST(1))); /* fscale  */
    ST(1) = ST(0); FPOP(c); /* fstp st(1) */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = fabs(ST(0)); /* fabs  */
    FCOM(c, ST(0), RF64((uint32_t)(0xb2e3d8u))); FPOP(c); /* fcomp qword ptr [0x1000e3d8] */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (!c->cf) goto L_00b27959; /* jae 0xb27959 */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(0xb2e3f8u))); /* fmul qword ptr [0x1000e3f8] */
    goto L_00b27959; /* jmp 0xb27959 */
L_00b2792d:;
    W32((uint32_t)(c->ebp + 0xffffff72u), (uint32_t)((uint32_t)0x3u)); /* mov dword ptr [ebp - 0x8e], 3 */
    FPUSH(c, RF64((uint32_t)(0xb2e3e0u))); /* fld qword ptr [0x1000e3e0] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = ldexp(ST(0), (int)trunc(ST(1))); /* fscale  */
    ST(1) = ST(0); FPOP(c); /* fstp st(1) */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = fabs(ST(0)); /* fabs  */
    FCOM(c, ST(0), RF64((uint32_t)(0xb2e3d0u))); FPOP(c); /* fcomp qword ptr [0x1000e3d0] */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if ((c->cf || c->zf)) goto L_00b27959; /* jbe 0xb27959 */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(0xb2e3f0u))); /* fmul qword ptr [0x1000e3f0] */
L_00b27959:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffff6cu))); /* mov ebx, dword ptr [ebp - 0x94] */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    W32((uint32_t)(c->ebp + 0xffffff76u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x8a], ebx */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffd38u)) & (uint8_t)0x1u)); /* test byte ptr [ebp - 0x2c8], 1 */
    if (!c->zf) goto L_00b2798b; /* jne 0xb2798b */
    c->df = 0; /* cld  */
    c->esi = (uint32_t)((uint32_t)(c->ebp + 0x8u)); /* lea esi, [ebp + 8] */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0xffffff7au)); /* lea edi, [ebp - 0x86] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    (void)sub8(c, R8((uint32_t)(c->ebx + 0xcu)), (uint8_t)0x1u); /* cmp byte ptr [ebx + 0xc], 1 */
    if (c->zf) goto L_00b2798b; /* je 0xb2798b */
    c->esi = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea esi, [ebp + 0x10] */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0xffffff82u)); /* lea edi, [ebp - 0x7e] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
L_00b2798b:;
    WF64((uint32_t)(c->ebp + 0xffffff8au), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0x76] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff72u)); /* lea eax, [ebp - 0x8e] */
    c->ebx = (uint32_t)((uint32_t)(c->ebp + 0xffffff5cu)); /* lea ebx, [ebp - 0xa4] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffff6cu))); /* mov ebx, dword ptr [ebp - 0x94] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebx + 0xeu))); /* mov al, byte ptr [ebx + 0xe] */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->eax)); /* movsx eax, al */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b279aeu); f_00b2bdb1(c); /* call 0xb2bdb1 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xffffff8au))); /* fld qword ptr [ebp - 0x76] */
    goto L_00b278df; /* jmp 0xb278df */
}

void f_00b279bb(CPU *c) { /* __ctrandisp1 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xfffffd30u)); /* add esp, 0xfffffd30 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00b279d0u); f_00b279ee(c); /* call 0xb279ee */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    ; /* wait  */
    W16((uint32_t)(c->ebp + 0xffffff5cu), c->fpu_cw); /* fnstcw word ptr [ebp - 0xa4] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffd38u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0xfdu)))); } /* and byte ptr [ebp - 0x2c8], 0xfd */
    PUSH32(c, 0x00b279e6u); f_00b27a30(c); /* call 0xb27a30 */
    PUSH32(c, 0x00b279ebu); f_00b27883(c); /* call 0xb27883 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b279ee(CPU *c) { /* __fload */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xfffffff4u)); /* add esp, -0xc */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ebp + 0xeu))); /* mov ax, word ptr [ebp + 0xe] */
    c->ebx = (c->ebx & 0xffff0000u) | (uint16_t)(((uint16_t)c->eax)); /* mov bx, ax */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->eax) & (uint16_t)0x7ff0u))); /* and ax, 0x7ff0 */
    (void)sub16(c, ((uint16_t)c->eax), (uint16_t)0x7ff0u); /* cmp ax, 0x7ff0 */
    if (!c->zf) goto L_00b27a24; /* jne 0xb27a24 */
    c->ebx = (c->ebx & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->ebx) | (uint16_t)0x7fffu))); /* or bx, 0x7fff */
    W16((uint32_t)(c->ebp + 0xfffffffeu), (uint16_t)(((uint16_t)c->ebx))); /* mov word ptr [ebp - 2], bx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(({ unsigned n_ = 11 & 31; uint32_t r_ = n_ ? ((c->eax << n_) | (c->ebx >> (32 - n_))) : c->eax; if (n_) { c->cf = (c->eax >> (32 - n_)) & 1; c->zf = r_ == 0; c->sf = (int32_t)r_ < 0; c->pf_byte = (uint8_t)r_; } r_; })); /* shld eax, ebx, 0xb */
    W32((uint32_t)(c->ebp + 0xfffffffau), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 6], eax */
    W32((uint32_t)(c->ebp + 0xfffffff6u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0xa], ebx */
    FPUSH(c, RF80((uint32_t)(c->ebp + 0xfffffff6u))); /* fld xword ptr [ebp - 0xa] */
    goto L_00b27a27; /* jmp 0xb27a27 */
L_00b27a24:;
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
L_00b27a27:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}
