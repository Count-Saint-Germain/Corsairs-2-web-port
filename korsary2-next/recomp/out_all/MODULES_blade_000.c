#include "recomp.h"

void f_00b91000(CPU *c) { /* DMAInterface */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    W32((uint32_t)(0xb9efa4u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000efa4], eax */
    W32((uint32_t)(0xb9ef8cu), (uint32_t)(c->eax)); /* mov dword ptr [0x1000ef8c], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov eax, dword ptr [eax + 4] */
    W32((uint32_t)(0xb9ef88u), (uint32_t)(c->ecx)); /* mov dword ptr [0x1000ef88], ecx */
    W32((uint32_t)(0xb9ef90u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000ef90], eax */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9efa8u))); /* mov eax, dword ptr [0x1000efa8] */
    c->esp += 4; return; /* ret  */
}

void f_00b91030(CPU *c) { /* FUN_10001030 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb9efa4u))); /* mov ecx, dword ptr [0x1000efa4] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4u)); PUSH32(c, 0x00b9104au); call_indirect(c, t_); } /* call dword ptr [eax + 4] */
    c->esp += 4; return; /* ret  */
}

void f_00b91050(CPU *c) { /* FUN_10001050 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(0xb9efa4u))); /* mov ecx, dword ptr [0x1000efa4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x00b91060u); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
    c->esp += 4; return; /* ret  */
}

void f_00b91070(CPU *c) { /* PTR_00b91070 */
    PREEMPT_POLL(c);
    PUSH32(c, 0x00b91075u); f_00b91080(c); /* call 0xb91080 */
    { f_00b91160(c); return; } /* jmp 0xb91160 */
}

void f_00b91080(CPU *c) { /* PTR_00b91080 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xb9efa8u; PUSH32(c, v_); } /* push 0x1000efa8 */
    c->ecx = (uint32_t)((uint32_t)0xb9ef94u); /* mov ecx, 0x1000ef94 */
    PUSH32(c, 0x00b9108fu); f_00b91090(c); /* call 0xb91090 */
    c->esp += 4; return; /* ret  */
}

void f_00b91090(CPU *c) { /* PTR_00b91090 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0xc], ecx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0xb9b0e8u)); /* mov dword ptr [eax], 0x1000b0e8 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 4], edx */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    c->esp += 8; return; /* ret 4 */
}

void f_00b910b0(CPU *c) { /* PTR_00b910b0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb9c0c4u); /* mov eax, 0x1000c0c4 */
    c->esp += 4; return; /* ret  */
}

void f_00b910c0(CPU *c) { /* FUN_100010c0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xb9a7f4u; PUSH32(c, v_); } /* push 0x1000a7f4 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov eax, dword ptr [ecx + 0xc] */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t v_ = 0xb9c0ccu; PUSH32(c, v_); } /* push 0x1000c0cc */
    { uint32_t v_ = 0x990u; PUSH32(c, v_); } /* push 0x990 */
    W32((uint32_t)(c->ecx + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 0xc], eax */
    PUSH32(c, 0x00b910eeu); f_00b91030(c); /* call 0xb91030 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->esp), (uint32_t)(c->eax)); /* mov dword ptr [esp], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0xc], 0 */
    if (c->zf) goto L_00b91117; /* je 0xb91117 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    PUSH32(c, 0x00b91108u); f_00b91180(c); /* call 0xb91180 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
L_00b91117:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_00b91130(CPU *c) { /* FUN_10001130 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00b91138u); f_00b91150(c); /* call 0xb91150 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00b91148; /* je 0xb91148 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b91145u); f_00b91050(c); /* call 0xb91050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00b91148:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00b91150(CPU *c) { /* FUN_10001150 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx), (uint32_t)((uint32_t)0xb9b108u)); /* mov dword ptr [ecx], 0x1000b108 */
    c->esp += 4; return; /* ret  */
}

void f_00b91160(CPU *c) { /* PTR_00b91160 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xb91170u; PUSH32(c, v_); } /* push 0x10001170 */
    PUSH32(c, 0x00b9116au); f_00b93d44(c); /* call 0xb93d44 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00b91170(CPU *c) { /* PTR_00b91170 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)0xb9ef94u); /* mov ecx, 0x1000ef94 */
    { f_00b91150(c); return; } /* jmp 0xb91150 */
}

void f_00b91180(CPU *c) { /* FUN_10001180 */
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
    W32((uint32_t)(c->ebx), (uint32_t)((uint32_t)0xb9b14cu)); /* mov dword ptr [ebx], 0x1000b14c */
    W32((uint32_t)(c->ebx + 0x1cu), (uint32_t)(c->ebp)); /* mov dword ptr [ebx + 0x1c], ebp */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb9ef88u))); /* mov ecx, dword ptr [0x1000ef88] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x00b911b8u); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb9ef88u))); /* mov ecx, dword ptr [0x1000ef88] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x10u)); /* lea edx, [esp + 0x10] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x10u)); PUSH32(c, 0x00b911c8u); call_indirect(c, t_); } /* call dword ptr [eax + 0x10] */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x10u))); /* mov edx, dword ptr [ebx + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb9ef88u))); /* mov ecx, dword ptr [0x1000ef88] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x14u))); /* mov edx, dword ptr [ebx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4u)); PUSH32(c, 0x00b911e4u); call_indirect(c, t_); } /* call dword ptr [eax + 4] */
    c->eax = (uint32_t)((uint32_t)(c->ebx + 0x28u)); /* lea eax, [ebx + 0x28] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    c->edi = (uint32_t)((uint32_t)(c->ebx + 0x884u)); /* lea edi, [ebx + 0x884] */
    W32((uint32_t)(c->edx), (uint32_t)(c->ecx)); /* mov dword ptr [edx], ecx */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [edx + 4], ecx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ebp)); /* mov dword ptr [eax + 8], ebp */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->ebp)); /* mov dword ptr [eax + 0xc], ebp */
    W32((uint32_t)(c->eax + 0x10u), (uint32_t)(c->ebp)); /* mov dword ptr [eax + 0x10], ebp */
    W32((uint32_t)(c->eax + 0x14u), (uint32_t)(c->ebp)); /* mov dword ptr [eax + 0x14], ebp */
    c->eax = (uint32_t)((uint32_t)(c->ebx + 0x40u)); /* lea eax, [ebx + 0x40] */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    W32((uint32_t)(c->edx), (uint32_t)(c->ecx)); /* mov dword ptr [edx], ecx */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [edx + 4], ecx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ebp)); /* mov dword ptr [eax + 8], ebp */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->ebp)); /* mov dword ptr [eax + 0xc], ebp */
    W32((uint32_t)(c->eax + 0x10u), (uint32_t)(c->ebp)); /* mov dword ptr [eax + 0x10], ebp */
    W32((uint32_t)(c->eax + 0x14u), (uint32_t)(c->ebp)); /* mov dword ptr [eax + 0x14], ebp */
    c->eax = (uint32_t)((uint32_t)(c->ebx + 0x58u)); /* lea eax, [ebx + 0x58] */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    W32((uint32_t)(c->edx), (uint32_t)(c->ecx)); /* mov dword ptr [edx], ecx */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [edx + 4], ecx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ebp)); /* mov dword ptr [eax + 8], ebp */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->ebp)); /* mov dword ptr [eax + 0xc], ebp */
    W32((uint32_t)(c->eax + 0x10u), (uint32_t)(c->ebp)); /* mov dword ptr [eax + 0x10], ebp */
    W32((uint32_t)(c->eax + 0x14u), (uint32_t)(c->ebp)); /* mov dword ptr [eax + 0x14], ebp */
    W32((uint32_t)(c->ebx), (uint32_t)((uint32_t)0xb9b128u)); /* mov dword ptr [ebx], 0x1000b128 */
    W32((uint32_t)(c->ebx + 0x78u), (uint32_t)((uint32_t)0x3e19999au)); /* mov dword ptr [ebx + 0x78], 0x3e19999a */
    W32((uint32_t)(c->ebx + 0x7cu), (uint32_t)(c->ebp)); /* mov dword ptr [ebx + 0x7c], ebp */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9c044u))); /* mov eax, dword ptr [0x1000c044] */
    W32((uint32_t)(c->ebx + 0x984u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 0x984], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb9c05cu))); /* mov ecx, dword ptr [0x1000c05c] */
    W32((uint32_t)(c->ebx + 0x988u), (uint32_t)(c->ecx)); /* mov dword ptr [ebx + 0x988], ecx */
    c->ecx = (uint32_t)((uint32_t)0x40u); /* mov ecx, 0x40 */
    c->eax = (uint32_t)((uint32_t)0xe0ad78ecu); /* mov eax, 0xe0ad78ec */
    W32((uint32_t)(c->ebx + 0x70u), (uint32_t)((uint32_t)0x80162ebeu)); /* mov dword ptr [ebx + 0x70], 0x80162ebe */
    W32((uint32_t)(c->ebx + 0x74u), (uint32_t)((uint32_t)0xff0000u)); /* mov dword ptr [ebx + 0x74], 0xff0000 */
    W32((uint32_t)(c->ebx + 0x80u), (uint32_t)(c->ebp)); /* mov dword ptr [ebx + 0x80], ebp */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->ebx + 0x98cu), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [ebx + 0x98c], 0xffffffff */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    c->esp += 4; return; /* ret  */
}

void f_00b91290(CPU *c) { /* FUN_10001290 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00b91298u); f_00b912b0(c); /* call 0xb912b0 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00b912a8; /* je 0xb912a8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b912a5u); f_00b91050(c); /* call 0xb91050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00b912a8:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00b912b0(CPU *c) { /* FUN_100012b0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xb9a808u; PUSH32(c, v_); } /* push 0x1000a808 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0xc], ebx */
    W32((uint32_t)(c->ebx), (uint32_t)((uint32_t)0xb9b128u)); /* mov dword ptr [ebx], 0x1000b128 */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9efa4u))); /* mov eax, dword ptr [0x1000efa4] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->esi = (uint32_t)((uint32_t)(c->ebx + 0x40u)); /* lea esi, [ebx + 0x40] */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    W32((uint32_t)(c->esp + 0x30u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x30], 0 */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x60u)); PUSH32(c, 0x00b912f8u); call_indirect(c, t_); } /* call dword ptr [edx + 0x60] */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9efa4u))); /* mov eax, dword ptr [0x1000efa4] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->esi = (uint32_t)((uint32_t)(c->ebx + 0x58u)); /* lea esi, [ebx + 0x58] */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x60u)); PUSH32(c, 0x00b91313u); call_indirect(c, t_); } /* call dword ptr [edx + 0x60] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x14u))); /* mov edx, dword ptr [ebx + 0x14] */
    W32((uint32_t)(c->ebx), (uint32_t)((uint32_t)0xb9b14cu)); /* mov dword ptr [ebx], 0x1000b14c */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb9ef88u))); /* mov ecx, dword ptr [0x1000ef88] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [esp + 0x1c], 0xffffffff */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x00b91330u); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_00b91350(CPU *c) { /* PTR_00b91350 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xb9a836u; PUSH32(c, v_); } /* push 0x1000a836 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x250u)); /* sub esp, 0x250 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->ecx); /* mov ebp, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb9efa4u))); /* mov ecx, dword ptr [0x1000efa4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0xb9c170u; PUSH32(c, v_); } /* push 0x1000c170 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4cu)); PUSH32(c, 0x00b91380u); call_indirect(c, t_); } /* call dword ptr [eax + 0x4c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->ebp + 0x24u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x24], eax */
    if (!c->zf) goto L_00b9141b; /* jne 0xb9141b */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb9ef88u))); /* mov ecx, dword ptr [0x1000ef88] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x18u)); PUSH32(c, 0x00b91396u); call_indirect(c, t_); } /* call dword ptr [edx + 0x18] */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9ef88u))); /* mov eax, dword ptr [0x1000ef88] */
    { uint32_t v_ = 0xb9c158u; PUSH32(c, v_); } /* push 0x1000c158 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00b913a6u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9ef88u))); /* mov eax, dword ptr [0x1000ef88] */
    { uint32_t v_ = 0x33u; PUSH32(c, v_); } /* push 0x33 */
    { uint32_t v_ = 0xb9c0ccu; PUSH32(c, v_); } /* push 0x1000c0cc */
    { uint32_t v_ = 0xb9c14cu; PUSH32(c, v_); } /* push 0x1000c14c */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00b913bdu); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9ef88u))); /* mov eax, dword ptr [0x1000ef88] */
    { uint32_t v_ = 0xb9c134u; PUSH32(c, v_); } /* push 0x1000c134 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00b913cdu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    W32((uint32_t)(c->esp + 0x130u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x130], 0 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00b913dd:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0xb9c134u))); /* mov cl, byte ptr [eax + 0x1000c134] */
    W8((uint32_t)(c->esp + c->eax + 0xcu), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esp + eax + 0xc], cl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_00b913dd; /* jne 0xb913dd */
    c->ecx = (uint32_t)((uint32_t)0x4au); /* mov ecx, 0x4a */
    c->esi = (uint32_t)((uint32_t)(c->esp + 0xcu)); /* lea esi, [esp + 0xc] */
    c->edi = (uint32_t)((uint32_t)(c->esp + 0x134u)); /* lea edi, [esp + 0x134] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x134u)); /* lea edx, [esp + 0x134] */
    { uint32_t v_ = 0xb9b8a8u; PUSH32(c, v_); } /* push 0x1000b8a8 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    W32((uint32_t)(c->esp + 0x26cu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x26c], 0 */
    PUSH32(c, 0x00b9141bu); f_00b93e1a(c); /* call 0xb93e1a */
L_00b9141b:;
    c->eax = (uint32_t)(R32((uint32_t)(0xb9efa4u))); /* mov eax, dword ptr [0x1000efa4] */
    { uint32_t v_ = 0xfffbu; PUSH32(c, v_); } /* push 0xfffb */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->esi = (uint32_t)((uint32_t)(c->ebp + 0x4u)); /* lea esi, [ebp + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    { uint32_t v_ = 0xb9c12cu; PUSH32(c, v_); } /* push 0x1000c12c */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xb0u)); PUSH32(c, 0x00b91443u); call_indirect(c, t_); } /* call dword ptr [edx + 0xb0] */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb9efa4u))); /* mov ecx, dword ptr [0x1000efa4] */
    { uint32_t v_ = 0xb9c120u; PUSH32(c, v_); } /* push 0x1000c120 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4cu)); PUSH32(c, 0x00b91453u); call_indirect(c, t_); } /* call dword ptr [eax + 0x4c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->ebp + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x20], eax */
    if (!c->zf) goto L_00b914ee; /* jne 0xb914ee */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb9ef88u))); /* mov ecx, dword ptr [0x1000ef88] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x18u)); PUSH32(c, 0x00b91469u); call_indirect(c, t_); } /* call dword ptr [edx + 0x18] */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9ef88u))); /* mov eax, dword ptr [0x1000ef88] */
    { uint32_t v_ = 0xb9c158u; PUSH32(c, v_); } /* push 0x1000c158 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00b91479u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9ef88u))); /* mov eax, dword ptr [0x1000ef88] */
    { uint32_t v_ = 0x38u; PUSH32(c, v_); } /* push 0x38 */
    { uint32_t v_ = 0xb9c0ccu; PUSH32(c, v_); } /* push 0x1000c0cc */
    { uint32_t v_ = 0xb9c14cu; PUSH32(c, v_); } /* push 0x1000c14c */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00b91490u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9ef88u))); /* mov eax, dword ptr [0x1000ef88] */
    { uint32_t v_ = 0xb9c108u; PUSH32(c, v_); } /* push 0x1000c108 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00b914a0u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    W32((uint32_t)(c->esp + 0x130u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x130], 0 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00b914b0:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0xb9c108u))); /* mov cl, byte ptr [eax + 0x1000c108] */
    W8((uint32_t)(c->esp + c->eax + 0xcu), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esp + eax + 0xc], cl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_00b914b0; /* jne 0xb914b0 */
    c->ecx = (uint32_t)((uint32_t)0x4au); /* mov ecx, 0x4a */
    c->esi = (uint32_t)((uint32_t)(c->esp + 0xcu)); /* lea esi, [esp + 0xc] */
    c->edi = (uint32_t)((uint32_t)(c->esp + 0x134u)); /* lea edi, [esp + 0x134] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x134u)); /* lea edx, [esp + 0x134] */
    { uint32_t v_ = 0xb9b8a8u; PUSH32(c, v_); } /* push 0x1000b8a8 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    W32((uint32_t)(c->esp + 0x26cu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [esp + 0x26c], 1 */
    PUSH32(c, 0x00b914eeu); f_00b93e1a(c); /* call 0xb93e1a */
L_00b914ee:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x25cu))); /* mov ecx, dword ptr [esp + 0x25c] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x25cu)); /* add esp, 0x25c */
    c->esp += 4; return; /* ret  */
}

void f_00b91510(CPU *c) { /* PTR_00b91510 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x2d0u)); /* sub esp, 0x2d0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x2d4u))); /* mov eax, dword ptr [esp + 0x2d4] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x10], 0 */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0xc], eax */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    FPUSH(c, (double)(int64_t)R64((uint32_t)(c->esp + 0x10u))); /* fild qword ptr [esp + 0x10] */
    c->ebp = (uint32_t)(c->ecx); /* mov ebp, ecx */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb9b174u))); /* fmul dword ptr [0x1000b174] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x28u)); /* lea eax, [ebp + 0x28] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ebp + 0x80u))); /* fadd dword ptr [ebp + 0x80] */
    WF32((uint32_t)(c->ebp + 0x80u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp + 0x80] */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb9efa4u))); /* mov ecx, dword ptr [0x1000efa4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x64u)); PUSH32(c, 0x00b91551u); call_indirect(c, t_); } /* call dword ptr [edx + 0x64] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esp + 0xa8u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0xa8], eax */
    if (c->zf) goto L_00b92ba2; /* je 0xb92ba2 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x34u)); PUSH32(c, 0x00b9156cu); call_indirect(c, t_); } /* call dword ptr [edx + 0x34] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x20u))); /* mov ecx, dword ptr [ebp + 0x20] */
    W32((uint32_t)(c->esp + 0xb8u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0xb8], eax */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x7cu)); PUSH32(c, 0x00b9157fu); call_indirect(c, t_); } /* call dword ptr [eax + 0x7c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x20u))); /* mov ecx, dword ptr [ebp + 0x20] */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x7cu)); PUSH32(c, 0x00b9158bu); call_indirect(c, t_); } /* call dword ptr [edx + 0x7c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x20u))); /* mov ecx, dword ptr [ebp + 0x20] */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x7cu)); PUSH32(c, 0x00b91597u); call_indirect(c, t_); } /* call dword ptr [eax + 0x7c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x20u))); /* mov ecx, dword ptr [ebp + 0x20] */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x7cu)); PUSH32(c, 0x00b915a3u); call_indirect(c, t_); } /* call dword ptr [edx + 0x7c] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x13cu)); /* lea eax, [esp + 0x13c] */
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
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x20u))); /* mov ecx, dword ptr [ebp + 0x20] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x13cu)); /* lea eax, [esp + 0x13c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x5cu)); PUSH32(c, 0x00b915fau); call_indirect(c, t_); } /* call dword ptr [edx + 0x5c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x16cu))); /* fld dword ptr [esp + 0x16c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x13cu))); /* fmul dword ptr [esp + 0x13c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x140u))); /* fld dword ptr [esp + 0x140] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x170u))); /* fmul dword ptr [esp + 0x170] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x14cu)); /* lea ecx, [esp + 0x14c] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x16cu)); /* lea edx, [esp + 0x16c] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14cu))); /* fld dword ptr [esp + 0x14c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x17cu))); /* fmul dword ptr [esp + 0x17c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->esp + 0x20u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x20] */
    PUSH32(c, 0x00b91641u); f_00b93590(c); /* call 0xb93590 */
    WF32((uint32_t)(c->esp + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1c] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x164u)); /* lea eax, [esp + 0x164] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x174u)); /* lea ecx, [esp + 0x174] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00b9165au); f_00b93590(c); /* call 0xb93590 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x28u))); /* fld dword ptr [esp + 0x28] */
    ST(0) = -ST(0); /* fchs  */
    WF32((uint32_t)(c->esp + 0x17cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x17c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x24u))); /* fld dword ptr [esp + 0x24] */
    ST(0) = -ST(0); /* fchs  */
    WF32((uint32_t)(c->esp + 0x180u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x180] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x14cu)); /* lea edx, [esp + 0x14c] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    ST(0) = -ST(0); /* fchs  */
    WF32((uint32_t)(c->esp + 0x174u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x174] */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x14], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->eax + 0x10u))); /* mov ebx, dword ptr [eax + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x20u))); /* mov ecx, dword ptr [eax + 0x20] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov esi, dword ptr [eax + 4] */
    c->edi = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov edi, dword ptr [eax + 8] */
    W32((uint32_t)(c->eax + 0x10u), (uint32_t)(c->esi)); /* mov dword ptr [eax + 0x10], esi */
    W32((uint32_t)(c->eax + 0x20u), (uint32_t)(c->edi)); /* mov dword ptr [eax + 0x20], edi */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 4], ebx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->eax + 0x18u))); /* mov ebx, dword ptr [eax + 0x18] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + 0x24u))); /* mov esi, dword ptr [eax + 0x24] */
    W32((uint32_t)(c->eax + 0x18u), (uint32_t)(c->esi)); /* mov dword ptr [eax + 0x18], esi */
    W32((uint32_t)(c->eax + 0x24u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x24], ebx */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x20], 0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov ecx, dword ptr [esp + 0x20] */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x1c], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov eax, dword ptr [esp + 0x1c] */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x24], 0 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov edx, dword ptr [esp + 0x24] */
    W32((uint32_t)(c->esp + 0x170u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x170], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x20u))); /* mov ecx, dword ptr [ebp + 0x20] */
    W32((uint32_t)(c->esp + 0x16cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x16c], eax */
    W32((uint32_t)(c->esp + 0x174u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x174], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x13cu)); /* lea edx, [esp + 0x13c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x11u; PUSH32(c, v_); } /* push 0x11 */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x58u)); PUSH32(c, 0x00b916feu); call_indirect(c, t_); } /* call dword ptr [eax + 0x58] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x20u))); /* mov ecx, dword ptr [ebp + 0x20] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x98cu))); /* mov edx, dword ptr [ebp + 0x98c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x3cu; PUSH32(c, v_); } /* push 0x3c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x12cu)); PUSH32(c, 0x00b91712u); call_indirect(c, t_); } /* call dword ptr [eax + 0x12c] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0xfcu)); /* lea eax, [esp + 0xfc] */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
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
    c->ecx = (uint32_t)(R32((uint32_t)(0xb9efa4u))); /* mov ecx, dword ptr [0x1000efa4] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x58u)); /* lea eax, [ebp + 0x58] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x64u)); PUSH32(c, 0x00b91766u); call_indirect(c, t_); } /* call dword ptr [edx + 0x64] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x18], esi */
    if (c->zf) goto L_00b91ef5; /* je 0xb91ef5 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x34u)); PUSH32(c, 0x00b9177du); call_indirect(c, t_); } /* call dword ptr [edx + 0x34] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x98cu))); /* mov ecx, dword ptr [ebp + 0x98c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0xff000000u))); /* and ecx, 0xff000000 */
    (void)sub32(c, c->ecx, (uint32_t)0xff000000u); /* cmp ecx, 0xff000000 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    if (!c->zf) goto L_00b9179c; /* jne 0xb9179c */
    { uint32_t v_ = 0xb9c1c4u; PUSH32(c, v_); } /* push 0x1000c1c4 */
    goto L_00b917a1; /* jmp 0xb917a1 */
L_00b9179c:;
    { uint32_t v_ = 0xb9c1b4u; PUSH32(c, v_); } /* push 0x1000c1b4 */
L_00b917a1:;
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x18u)); PUSH32(c, 0x00b917a4u); call_indirect(c, t_); } /* call dword ptr [edx + 0x18] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0xb8u))); /* mov ebx, dword ptr [esp + 0xb8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x988u))); /* mov edx, dword ptr [ebp + 0x988] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x88u))); /* mov ecx, dword ptr [ebx + 0x88] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax)); PUSH32(c, 0x00b917bcu); call_indirect(c, t_); } /* call dword ptr [eax] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x88u))); /* mov ecx, dword ptr [ebx + 0x88] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x00b917cau); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)sub32(c, c->edi, (uint32_t)0xffffffffu); /* cmp edi, -1 */
    if ((c->zf || c->sf != c->of)) goto L_00b91ec6; /* jle 0xb91ec6 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xb4u))); /* mov ecx, dword ptr [esp + 0xb4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x40u)); PUSH32(c, 0x00b917e1u); call_indirect(c, t_); } /* call dword ptr [eax + 0x40] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x1cu)); PUSH32(c, 0x00b917eau); call_indirect(c, t_); } /* call dword ptr [edx + 0x1c] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebx + 0x88u))); /* mov ebx, dword ptr [ebx + 0x88] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x1bcu)); /* lea ecx, [esp + 0x1bc] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x10u)); PUSH32(c, 0x00b91802u); call_indirect(c, t_); } /* call dword ptr [eax + 0x10] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x17cu)); /* lea edx, [esp + 0x17c] */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x14], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
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
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1c0u))); /* fld dword ptr [esp + 0x1c0] */
    WF32((uint32_t)(c->esp + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1c4u))); /* fld dword ptr [esp + 0x1c4] */
    WF32((uint32_t)(c->esp + 0x20u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x20] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1c8u))); /* fld dword ptr [esp + 0x1c8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov eax, dword ptr [esp + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov ecx, dword ptr [esp + 0x20] */
    WF32((uint32_t)(c->esp + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x24] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1d0u))); /* fld dword ptr [esp + 0x1d0] */
    WF32((uint32_t)(c->esp + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1d4u))); /* fld dword ptr [esp + 0x1d4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov edx, dword ptr [esp + 0x24] */
    W32((uint32_t)(c->esp + 0x17cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x17c], eax */
    WF32((uint32_t)(c->esp + 0x20u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x20] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1d8u))); /* fld dword ptr [esp + 0x1d8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov eax, dword ptr [esp + 0x1c] */
    W32((uint32_t)(c->esp + 0x180u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x180], ecx */
    WF32((uint32_t)(c->esp + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x24] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1e0u))); /* fld dword ptr [esp + 0x1e0] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov ecx, dword ptr [esp + 0x20] */
    W32((uint32_t)(c->esp + 0x184u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x184], edx */
    WF32((uint32_t)(c->esp + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1e4u))); /* fld dword ptr [esp + 0x1e4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov edx, dword ptr [esp + 0x24] */
    W32((uint32_t)(c->esp + 0x18cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x18c], eax */
    WF32((uint32_t)(c->esp + 0x20u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x20] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1e8u))); /* fld dword ptr [esp + 0x1e8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov eax, dword ptr [esp + 0x1c] */
    W32((uint32_t)(c->esp + 0x190u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x190], ecx */
    WF32((uint32_t)(c->esp + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x24] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1f0u))); /* fld dword ptr [esp + 0x1f0] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov ecx, dword ptr [esp + 0x20] */
    W32((uint32_t)(c->esp + 0x194u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x194], edx */
    WF32((uint32_t)(c->esp + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1f4u))); /* fld dword ptr [esp + 0x1f4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov edx, dword ptr [esp + 0x24] */
    W32((uint32_t)(c->esp + 0x19cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x19c], eax */
    WF32((uint32_t)(c->esp + 0x20u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x20] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1f8u))); /* fld dword ptr [esp + 0x1f8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov eax, dword ptr [esp + 0x1c] */
    W32((uint32_t)(c->esp + 0x1a4u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x1a4], edx */
    WF32((uint32_t)(c->esp + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x24] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov edx, dword ptr [esp + 0x24] */
    W32((uint32_t)(c->esp + 0x1a0u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x1a0], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov ecx, dword ptr [esp + 0x20] */
    W32((uint32_t)(c->esp + 0x1b4u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x1b4], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x208u))); /* mov edx, dword ptr [esp + 0x208] */
    W32((uint32_t)(c->esp + 0x1acu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x1ac], eax */
    c->edx = (uint32_t)(shl32(c, c->edx, 6)); /* shl edx, 6 */
    W32((uint32_t)(c->esp + 0x1b0u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x1b0], ecx */
    c->edx = (uint32_t)(add32(c, c->edx, c->esi)); /* add edx, esi */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x228u)); /* lea eax, [esp + 0x228] */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
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
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x17cu)); /* lea ecx, [esp + 0x17c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x230u)); /* lea ecx, [esp + 0x230] */
    PUSH32(c, 0x00b919b5u); f_00b936d0(c); /* call 0xb936d0 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x228u)); /* lea edx, [esp + 0x228] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0xbcu)); /* lea eax, [esp + 0xbc] */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x14], edx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    c->df = 0; /* cld  */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edi, dword ptr [esp + 0x10] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov esi, dword ptr [esp + 0x14] */
    c->ecx = (uint32_t)((uint32_t)0x10u); /* mov ecx, 0x10 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xecu))); /* fld dword ptr [esp + 0xec] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb9b170u))); /* fmul dword ptr [0x1000b170] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x34u)); /* lea ecx, [esp + 0x34] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x10], ecx */
    WF32((uint32_t)(c->esp + 0xecu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xec] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xbcu))); /* fld dword ptr [esp + 0xbc] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb9b170u))); /* fmul dword ptr [0x1000b170] */
    WF32((uint32_t)(c->esp + 0xbcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xbc] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xccu))); /* fld dword ptr [esp + 0xcc] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb9b170u))); /* fmul dword ptr [0x1000b170] */
    WF32((uint32_t)(c->esp + 0xccu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xcc] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xdcu))); /* fld dword ptr [esp + 0xdc] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb9b170u))); /* fmul dword ptr [0x1000b170] */
    WF32((uint32_t)(c->esp + 0xdcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xdc] */
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
    c->edx = (uint32_t)((uint32_t)(c->esp + 0xbcu)); /* lea edx, [esp + 0xbc] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x74u)); /* lea eax, [esp + 0x74] */
    W32((uint32_t)(c->esp + 0x34u), (uint32_t)((uint32_t)0xbf800000u)); /* mov dword ptr [esp + 0x34], 0xbf800000 */
    W32((uint32_t)(c->esp + 0x48u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [esp + 0x48], 0x3f800000 */
    W32((uint32_t)(c->esp + 0x5cu), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [esp + 0x5c], 0x3f800000 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x10], edx */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    c->df = 0; /* cld  */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edi, dword ptr [esp + 0x14] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)((uint32_t)0x10u); /* mov ecx, 0x10 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x38u))); /* fld dword ptr [esp + 0x38] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x84u))); /* fmul dword ptr [esp + 0x84] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x3cu))); /* fld dword ptr [esp + 0x3c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x94u))); /* fmul dword ptr [esp + 0x94] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xa4u))); /* fld dword ptr [esp + 0xa4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x40u))); /* fmul dword ptr [esp + 0x40] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x74u))); /* fld dword ptr [esp + 0x74] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x34u))); /* fmul dword ptr [esp + 0x34] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->esp + 0xbcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xbc] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x38u))); /* fld dword ptr [esp + 0x38] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x88u))); /* fmul dword ptr [esp + 0x88] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x3cu))); /* fld dword ptr [esp + 0x3c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x98u))); /* fmul dword ptr [esp + 0x98] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x40u))); /* fld dword ptr [esp + 0x40] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xa8u))); /* fmul dword ptr [esp + 0xa8] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x78u))); /* fld dword ptr [esp + 0x78] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x34u))); /* fmul dword ptr [esp + 0x34] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->esp + 0xc0u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xc0] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x38u))); /* fld dword ptr [esp + 0x38] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x8cu))); /* fmul dword ptr [esp + 0x8c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x3cu))); /* fld dword ptr [esp + 0x3c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x9cu))); /* fmul dword ptr [esp + 0x9c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x40u))); /* fld dword ptr [esp + 0x40] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xacu))); /* fmul dword ptr [esp + 0xac] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x7cu))); /* fld dword ptr [esp + 0x7c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x34u))); /* fmul dword ptr [esp + 0x34] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->esp + 0xc4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xc4] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x38u))); /* fld dword ptr [esp + 0x38] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x90u))); /* fmul dword ptr [esp + 0x90] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x3cu))); /* fld dword ptr [esp + 0x3c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xa0u))); /* fmul dword ptr [esp + 0xa0] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x40u))); /* fld dword ptr [esp + 0x40] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xb0u))); /* fmul dword ptr [esp + 0xb0] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x80u))); /* fld dword ptr [esp + 0x80] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x34u))); /* fmul dword ptr [esp + 0x34] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->esp + 0xc8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xc8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x44u))); /* fld dword ptr [esp + 0x44] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x74u))); /* fmul dword ptr [esp + 0x74] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x48u))); /* fld dword ptr [esp + 0x48] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x84u))); /* fmul dword ptr [esp + 0x84] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x4cu))); /* fld dword ptr [esp + 0x4c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x94u))); /* fmul dword ptr [esp + 0x94] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xa4u))); /* fld dword ptr [esp + 0xa4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x50u))); /* fmul dword ptr [esp + 0x50] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->esp + 0xccu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xcc] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x48u))); /* fld dword ptr [esp + 0x48] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x88u))); /* fmul dword ptr [esp + 0x88] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x4cu))); /* fld dword ptr [esp + 0x4c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x98u))); /* fmul dword ptr [esp + 0x98] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x50u))); /* fld dword ptr [esp + 0x50] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xa8u))); /* fmul dword ptr [esp + 0xa8] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x44u))); /* fld dword ptr [esp + 0x44] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x78u))); /* fmul dword ptr [esp + 0x78] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->esp + 0xd0u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xd0] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x48u))); /* fld dword ptr [esp + 0x48] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x8cu))); /* fmul dword ptr [esp + 0x8c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x4cu))); /* fld dword ptr [esp + 0x4c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x9cu))); /* fmul dword ptr [esp + 0x9c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x50u))); /* fld dword ptr [esp + 0x50] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xacu))); /* fmul dword ptr [esp + 0xac] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x44u))); /* fld dword ptr [esp + 0x44] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x7cu))); /* fmul dword ptr [esp + 0x7c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->esp + 0xd4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xd4] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x48u))); /* fld dword ptr [esp + 0x48] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x90u))); /* fmul dword ptr [esp + 0x90] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x4cu))); /* fld dword ptr [esp + 0x4c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xa0u))); /* fmul dword ptr [esp + 0xa0] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x50u))); /* fld dword ptr [esp + 0x50] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xb0u))); /* fmul dword ptr [esp + 0xb0] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x44u))); /* fld dword ptr [esp + 0x44] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x80u))); /* fmul dword ptr [esp + 0x80] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->esp + 0xd8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xd8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x54u))); /* fld dword ptr [esp + 0x54] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x74u))); /* fmul dword ptr [esp + 0x74] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x58u))); /* fld dword ptr [esp + 0x58] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x84u))); /* fmul dword ptr [esp + 0x84] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x5cu))); /* fld dword ptr [esp + 0x5c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x94u))); /* fmul dword ptr [esp + 0x94] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xa4u))); /* fld dword ptr [esp + 0xa4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x60u))); /* fmul dword ptr [esp + 0x60] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->esp + 0xdcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xdc] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x58u))); /* fld dword ptr [esp + 0x58] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x88u))); /* fmul dword ptr [esp + 0x88] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x5cu))); /* fld dword ptr [esp + 0x5c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x98u))); /* fmul dword ptr [esp + 0x98] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x60u))); /* fld dword ptr [esp + 0x60] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xa8u))); /* fmul dword ptr [esp + 0xa8] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x54u))); /* fld dword ptr [esp + 0x54] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x78u))); /* fmul dword ptr [esp + 0x78] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->esp + 0xe0u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xe0] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x58u))); /* fld dword ptr [esp + 0x58] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x8cu))); /* fmul dword ptr [esp + 0x8c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x5cu))); /* fld dword ptr [esp + 0x5c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x9cu))); /* fmul dword ptr [esp + 0x9c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x60u))); /* fld dword ptr [esp + 0x60] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xacu))); /* fmul dword ptr [esp + 0xac] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x74u)); /* lea ecx, [esp + 0x74] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x10], ecx */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x54u))); /* fld dword ptr [esp + 0x54] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x7cu))); /* fmul dword ptr [esp + 0x7c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->esp + 0xe4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xe4] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x58u))); /* fld dword ptr [esp + 0x58] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x90u))); /* fmul dword ptr [esp + 0x90] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x5cu))); /* fld dword ptr [esp + 0x5c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xa0u))); /* fmul dword ptr [esp + 0xa0] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x60u))); /* fld dword ptr [esp + 0x60] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xb0u))); /* fmul dword ptr [esp + 0xb0] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x54u))); /* fld dword ptr [esp + 0x54] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x80u))); /* fmul dword ptr [esp + 0x80] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->esp + 0xe8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xe8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x64u))); /* fld dword ptr [esp + 0x64] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x74u))); /* fmul dword ptr [esp + 0x74] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x68u))); /* fld dword ptr [esp + 0x68] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x84u))); /* fmul dword ptr [esp + 0x84] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x6cu))); /* fld dword ptr [esp + 0x6c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x94u))); /* fmul dword ptr [esp + 0x94] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xa4u))); /* fld dword ptr [esp + 0xa4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x70u))); /* fmul dword ptr [esp + 0x70] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->esp + 0xecu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xec] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x68u))); /* fld dword ptr [esp + 0x68] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x88u))); /* fmul dword ptr [esp + 0x88] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x6cu))); /* fld dword ptr [esp + 0x6c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x98u))); /* fmul dword ptr [esp + 0x98] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x70u))); /* fld dword ptr [esp + 0x70] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xa8u))); /* fmul dword ptr [esp + 0xa8] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x64u))); /* fld dword ptr [esp + 0x64] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x78u))); /* fmul dword ptr [esp + 0x78] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->esp + 0xf0u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xf0] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x68u))); /* fld dword ptr [esp + 0x68] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x8cu))); /* fmul dword ptr [esp + 0x8c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x6cu))); /* fld dword ptr [esp + 0x6c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x9cu))); /* fmul dword ptr [esp + 0x9c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x70u))); /* fld dword ptr [esp + 0x70] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xacu))); /* fmul dword ptr [esp + 0xac] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x64u))); /* fld dword ptr [esp + 0x64] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x7cu))); /* fmul dword ptr [esp + 0x7c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->esp + 0xf4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xf4] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x68u))); /* fld dword ptr [esp + 0x68] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x90u))); /* fmul dword ptr [esp + 0x90] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x6cu))); /* fld dword ptr [esp + 0x6c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xa0u))); /* fmul dword ptr [esp + 0xa0] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x70u))); /* fld dword ptr [esp + 0x70] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xb0u))); /* fmul dword ptr [esp + 0xb0] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x64u))); /* fld dword ptr [esp + 0x64] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x80u))); /* fmul dword ptr [esp + 0x80] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->esp + 0xf8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xf8] */
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
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xb4u))); /* mov edx, dword ptr [esp + 0xb4] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0xbcu)); /* lea eax, [esp + 0xbc] */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x20u)); /* add edx, 0x20 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x74u)); /* lea ecx, [esp + 0x74] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b91e72u); f_00b936d0(c); /* call 0xb936d0 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x74u)); /* lea ecx, [esp + 0x74] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x228u)); /* lea edx, [esp + 0x228] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x10], ecx */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x14], edx */
    c->df = 0; /* cld  */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edi, dword ptr [esp + 0x14] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)((uint32_t)0x10u); /* mov ecx, 0x10 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x228u)); /* lea eax, [esp + 0x228] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0xfcu)); /* lea ecx, [esp + 0xfc] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x14], ecx */
    c->df = 0; /* cld  */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edi, dword ptr [esp + 0x14] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)((uint32_t)0x10u); /* mov ecx, 0x10 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0xb8u))); /* mov ebx, dword ptr [esp + 0xb8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov esi, dword ptr [esp + 0x18] */
L_00b91ec6:;
    c->edx = (uint32_t)((uint32_t)(c->esp + 0xfcu)); /* lea edx, [esp + 0xfc] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x20u)); /* add esi, 0x20 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x10], edx */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x14], esi */
    c->df = 0; /* cld  */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edi, dword ptr [esp + 0x14] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)((uint32_t)0x10u); /* mov ecx, 0x10 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov ecx, dword ptr [esp + 0x18] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0xcu)); PUSH32(c, 0x00b91ef3u); call_indirect(c, t_); } /* call dword ptr [eax + 0xc] */
    goto L_00b91efc; /* jmp 0xb91efc */
L_00b91ef5:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0xb8u))); /* mov ebx, dword ptr [esp + 0xb8] */
L_00b91efc:;
    c->ecx = (uint32_t)(R32((uint32_t)(0xb9efa4u))); /* mov ecx, dword ptr [0x1000efa4] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x40u)); /* lea eax, [ebp + 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x64u)); PUSH32(c, 0x00b91f0bu); call_indirect(c, t_); } /* call dword ptr [edx + 0x64] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x18], esi */
    if (c->zf) goto L_00b92b45; /* je 0xb92b45 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x34u)); PUSH32(c, 0x00b91f22u); call_indirect(c, t_); } /* call dword ptr [edx + 0x34] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x98cu))); /* mov ecx, dword ptr [ebp + 0x98c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0xff000000u))); /* and ecx, 0xff000000 */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x1c], eax */
    (void)sub32(c, c->ecx, (uint32_t)0xff000000u); /* cmp ecx, 0xff000000 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    if (!c->zf) goto L_00b91f45; /* jne 0xb91f45 */
    { uint32_t v_ = 0xb9c1c4u; PUSH32(c, v_); } /* push 0x1000c1c4 */
    goto L_00b91f4a; /* jmp 0xb91f4a */
L_00b91f45:;
    { uint32_t v_ = 0xb9c1b4u; PUSH32(c, v_); } /* push 0x1000c1b4 */
L_00b91f4a:;
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x18u)); PUSH32(c, 0x00b91f4du); call_indirect(c, t_); } /* call dword ptr [edx + 0x18] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x88u))); /* mov ecx, dword ptr [ebx + 0x88] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x984u))); /* mov edx, dword ptr [ebp + 0x984] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax)); PUSH32(c, 0x00b91f5eu); call_indirect(c, t_); } /* call dword ptr [eax] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x88u))); /* mov ecx, dword ptr [ebx + 0x88] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x00b91f6cu); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)sub32(c, c->edi, (uint32_t)0xffffffffu); /* cmp edi, -1 */
    if ((c->zf || c->sf != c->of)) goto L_00b92661; /* jle 0xb92661 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xb4u))); /* mov ecx, dword ptr [esp + 0xb4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x40u)); PUSH32(c, 0x00b91f83u); call_indirect(c, t_); } /* call dword ptr [eax + 0x40] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x1cu)); PUSH32(c, 0x00b91f8cu); call_indirect(c, t_); } /* call dword ptr [edx + 0x1c] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebx + 0x88u))); /* mov ebx, dword ptr [ebx + 0x88] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x1bcu)); /* lea ecx, [esp + 0x1bc] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x10u)); PUSH32(c, 0x00b91fa4u); call_indirect(c, t_); } /* call dword ptr [eax + 0x10] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x17cu)); /* lea edx, [esp + 0x17c] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x10], edx */
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
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1c0u))); /* fld dword ptr [esp + 0x1c0] */
    WF32((uint32_t)(c->esp + 0x28u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x28] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1c4u))); /* fld dword ptr [esp + 0x1c4] */
    WF32((uint32_t)(c->esp + 0x2cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x2c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1c8u))); /* fld dword ptr [esp + 0x1c8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov eax, dword ptr [esp + 0x28] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov ecx, dword ptr [esp + 0x2c] */
    WF32((uint32_t)(c->esp + 0x30u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x30] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1d0u))); /* fld dword ptr [esp + 0x1d0] */
    WF32((uint32_t)(c->esp + 0x28u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x28] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1d4u))); /* fld dword ptr [esp + 0x1d4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov edx, dword ptr [esp + 0x30] */
    W32((uint32_t)(c->esp + 0x17cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x17c], eax */
    WF32((uint32_t)(c->esp + 0x2cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x2c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1d8u))); /* fld dword ptr [esp + 0x1d8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov eax, dword ptr [esp + 0x28] */
    W32((uint32_t)(c->esp + 0x180u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x180], ecx */
    WF32((uint32_t)(c->esp + 0x30u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x30] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1e0u))); /* fld dword ptr [esp + 0x1e0] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov ecx, dword ptr [esp + 0x2c] */
    W32((uint32_t)(c->esp + 0x184u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x184], edx */
    WF32((uint32_t)(c->esp + 0x28u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x28] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1e4u))); /* fld dword ptr [esp + 0x1e4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov edx, dword ptr [esp + 0x30] */
    W32((uint32_t)(c->esp + 0x18cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x18c], eax */
    WF32((uint32_t)(c->esp + 0x2cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x2c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1e8u))); /* fld dword ptr [esp + 0x1e8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov eax, dword ptr [esp + 0x28] */
    W32((uint32_t)(c->esp + 0x190u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x190], ecx */
    WF32((uint32_t)(c->esp + 0x30u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x30] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1f0u))); /* fld dword ptr [esp + 0x1f0] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov ecx, dword ptr [esp + 0x2c] */
    W32((uint32_t)(c->esp + 0x194u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x194], edx */
    WF32((uint32_t)(c->esp + 0x28u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x28] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1f4u))); /* fld dword ptr [esp + 0x1f4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov edx, dword ptr [esp + 0x30] */
    W32((uint32_t)(c->esp + 0x19cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x19c], eax */
    WF32((uint32_t)(c->esp + 0x2cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x2c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1f8u))); /* fld dword ptr [esp + 0x1f8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov eax, dword ptr [esp + 0x28] */
    W32((uint32_t)(c->esp + 0x1a4u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x1a4], edx */
    WF32((uint32_t)(c->esp + 0x30u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x30] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov edx, dword ptr [esp + 0x30] */
    W32((uint32_t)(c->esp + 0x1a0u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x1a0], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov ecx, dword ptr [esp + 0x2c] */
    W32((uint32_t)(c->esp + 0x1b4u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x1b4], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x208u))); /* mov edx, dword ptr [esp + 0x208] */
    W32((uint32_t)(c->esp + 0x1acu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x1ac], eax */
    c->edx = (uint32_t)(shl32(c, c->edx, 6)); /* shl edx, 6 */
    W32((uint32_t)(c->esp + 0x1b0u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x1b0], ecx */
    c->edx = (uint32_t)(add32(c, c->edx, c->esi)); /* add edx, esi */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x228u)); /* lea eax, [esp + 0x228] */
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
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x17cu)); /* lea ecx, [esp + 0x17c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x230u)); /* lea ecx, [esp + 0x230] */
    PUSH32(c, 0x00b92157u); f_00b936d0(c); /* call 0xb936d0 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x228u)); /* lea edx, [esp + 0x228] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0xbcu)); /* lea eax, [esp + 0xbc] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x10], edx */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    c->df = 0; /* cld  */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edi, dword ptr [esp + 0x14] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)((uint32_t)0x10u); /* mov ecx, 0x10 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xecu))); /* fld dword ptr [esp + 0xec] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb9b170u))); /* fmul dword ptr [0x1000b170] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x34u)); /* lea ecx, [esp + 0x34] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x10], ecx */
    WF32((uint32_t)(c->esp + 0xecu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xec] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xbcu))); /* fld dword ptr [esp + 0xbc] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb9b170u))); /* fmul dword ptr [0x1000b170] */
    WF32((uint32_t)(c->esp + 0xbcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xbc] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xccu))); /* fld dword ptr [esp + 0xcc] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb9b170u))); /* fmul dword ptr [0x1000b170] */
    WF32((uint32_t)(c->esp + 0xccu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xcc] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xdcu))); /* fld dword ptr [esp + 0xdc] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb9b170u))); /* fmul dword ptr [0x1000b170] */
    WF32((uint32_t)(c->esp + 0xdcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xdc] */
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
    c->edx = (uint32_t)((uint32_t)(c->esp + 0xbcu)); /* lea edx, [esp + 0xbc] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x74u)); /* lea eax, [esp + 0x74] */
    W32((uint32_t)(c->esp + 0x34u), (uint32_t)((uint32_t)0xbf800000u)); /* mov dword ptr [esp + 0x34], 0xbf800000 */
    W32((uint32_t)(c->esp + 0x48u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [esp + 0x48], 0x3f800000 */
    W32((uint32_t)(c->esp + 0x5cu), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [esp + 0x5c], 0x3f800000 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x10], edx */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    c->df = 0; /* cld  */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edi, dword ptr [esp + 0x14] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)((uint32_t)0x10u); /* mov ecx, 0x10 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x38u))); /* fld dword ptr [esp + 0x38] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x84u))); /* fmul dword ptr [esp + 0x84] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x3cu))); /* fld dword ptr [esp + 0x3c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x94u))); /* fmul dword ptr [esp + 0x94] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x40u))); /* fld dword ptr [esp + 0x40] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xa4u))); /* fmul dword ptr [esp + 0xa4] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x34u))); /* fld dword ptr [esp + 0x34] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x74u))); /* fmul dword ptr [esp + 0x74] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->esp + 0xbcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xbc] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x38u))); /* fld dword ptr [esp + 0x38] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x88u))); /* fmul dword ptr [esp + 0x88] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x3cu))); /* fld dword ptr [esp + 0x3c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x98u))); /* fmul dword ptr [esp + 0x98] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x40u))); /* fld dword ptr [esp + 0x40] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xa8u))); /* fmul dword ptr [esp + 0xa8] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x34u))); /* fld dword ptr [esp + 0x34] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x78u))); /* fmul dword ptr [esp + 0x78] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->esp + 0xc0u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xc0] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x7cu))); /* fld dword ptr [esp + 0x7c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x34u))); /* fmul dword ptr [esp + 0x34] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x38u))); /* fld dword ptr [esp + 0x38] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x8cu))); /* fmul dword ptr [esp + 0x8c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x3cu))); /* fld dword ptr [esp + 0x3c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x9cu))); /* fmul dword ptr [esp + 0x9c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x40u))); /* fld dword ptr [esp + 0x40] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xacu))); /* fmul dword ptr [esp + 0xac] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->esp + 0xc4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xc4] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x80u))); /* fld dword ptr [esp + 0x80] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x34u))); /* fmul dword ptr [esp + 0x34] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x38u))); /* fld dword ptr [esp + 0x38] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x90u))); /* fmul dword ptr [esp + 0x90] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x3cu))); /* fld dword ptr [esp + 0x3c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xa0u))); /* fmul dword ptr [esp + 0xa0] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x40u))); /* fld dword ptr [esp + 0x40] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xb0u))); /* fmul dword ptr [esp + 0xb0] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->esp + 0xc8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xc8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x44u))); /* fld dword ptr [esp + 0x44] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x74u))); /* fmul dword ptr [esp + 0x74] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x48u))); /* fld dword ptr [esp + 0x48] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x84u))); /* fmul dword ptr [esp + 0x84] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x4cu))); /* fld dword ptr [esp + 0x4c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x94u))); /* fmul dword ptr [esp + 0x94] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x50u))); /* fld dword ptr [esp + 0x50] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xa4u))); /* fmul dword ptr [esp + 0xa4] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->esp + 0xccu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xcc] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x48u))); /* fld dword ptr [esp + 0x48] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x88u))); /* fmul dword ptr [esp + 0x88] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x4cu))); /* fld dword ptr [esp + 0x4c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x98u))); /* fmul dword ptr [esp + 0x98] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x50u))); /* fld dword ptr [esp + 0x50] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xa8u))); /* fmul dword ptr [esp + 0xa8] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x44u))); /* fld dword ptr [esp + 0x44] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x78u))); /* fmul dword ptr [esp + 0x78] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->esp + 0xd0u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xd0] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x48u))); /* fld dword ptr [esp + 0x48] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x8cu))); /* fmul dword ptr [esp + 0x8c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x4cu))); /* fld dword ptr [esp + 0x4c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x9cu))); /* fmul dword ptr [esp + 0x9c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x50u))); /* fld dword ptr [esp + 0x50] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xacu))); /* fmul dword ptr [esp + 0xac] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x44u))); /* fld dword ptr [esp + 0x44] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x7cu))); /* fmul dword ptr [esp + 0x7c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->esp + 0xd4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xd4] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x48u))); /* fld dword ptr [esp + 0x48] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x90u))); /* fmul dword ptr [esp + 0x90] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x4cu))); /* fld dword ptr [esp + 0x4c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xa0u))); /* fmul dword ptr [esp + 0xa0] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x50u))); /* fld dword ptr [esp + 0x50] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xb0u))); /* fmul dword ptr [esp + 0xb0] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x44u))); /* fld dword ptr [esp + 0x44] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x80u))); /* fmul dword ptr [esp + 0x80] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->esp + 0xd8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xd8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x54u))); /* fld dword ptr [esp + 0x54] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x74u))); /* fmul dword ptr [esp + 0x74] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x58u))); /* fld dword ptr [esp + 0x58] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x84u))); /* fmul dword ptr [esp + 0x84] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x5cu))); /* fld dword ptr [esp + 0x5c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x94u))); /* fmul dword ptr [esp + 0x94] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x60u))); /* fld dword ptr [esp + 0x60] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xa4u))); /* fmul dword ptr [esp + 0xa4] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->esp + 0xdcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xdc] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x58u))); /* fld dword ptr [esp + 0x58] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x88u))); /* fmul dword ptr [esp + 0x88] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x5cu))); /* fld dword ptr [esp + 0x5c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x98u))); /* fmul dword ptr [esp + 0x98] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x60u))); /* fld dword ptr [esp + 0x60] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xa8u))); /* fmul dword ptr [esp + 0xa8] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x54u))); /* fld dword ptr [esp + 0x54] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x78u))); /* fmul dword ptr [esp + 0x78] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->esp + 0xe0u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xe0] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x58u))); /* fld dword ptr [esp + 0x58] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x8cu))); /* fmul dword ptr [esp + 0x8c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x5cu))); /* fld dword ptr [esp + 0x5c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x9cu))); /* fmul dword ptr [esp + 0x9c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x60u))); /* fld dword ptr [esp + 0x60] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xacu))); /* fmul dword ptr [esp + 0xac] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x74u)); /* lea ecx, [esp + 0x74] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x10], ecx */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x54u))); /* fld dword ptr [esp + 0x54] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x7cu))); /* fmul dword ptr [esp + 0x7c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->esp + 0xe4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xe4] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x58u))); /* fld dword ptr [esp + 0x58] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x90u))); /* fmul dword ptr [esp + 0x90] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x5cu))); /* fld dword ptr [esp + 0x5c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xa0u))); /* fmul dword ptr [esp + 0xa0] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x60u))); /* fld dword ptr [esp + 0x60] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xb0u))); /* fmul dword ptr [esp + 0xb0] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x54u))); /* fld dword ptr [esp + 0x54] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x80u))); /* fmul dword ptr [esp + 0x80] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->esp + 0xe8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xe8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x64u))); /* fld dword ptr [esp + 0x64] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x74u))); /* fmul dword ptr [esp + 0x74] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x68u))); /* fld dword ptr [esp + 0x68] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x84u))); /* fmul dword ptr [esp + 0x84] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x6cu))); /* fld dword ptr [esp + 0x6c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x94u))); /* fmul dword ptr [esp + 0x94] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x70u))); /* fld dword ptr [esp + 0x70] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xa4u))); /* fmul dword ptr [esp + 0xa4] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->esp + 0xecu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xec] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x68u))); /* fld dword ptr [esp + 0x68] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x88u))); /* fmul dword ptr [esp + 0x88] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x6cu))); /* fld dword ptr [esp + 0x6c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x98u))); /* fmul dword ptr [esp + 0x98] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x70u))); /* fld dword ptr [esp + 0x70] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xa8u))); /* fmul dword ptr [esp + 0xa8] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x64u))); /* fld dword ptr [esp + 0x64] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x78u))); /* fmul dword ptr [esp + 0x78] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->esp + 0xf0u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xf0] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x68u))); /* fld dword ptr [esp + 0x68] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x8cu))); /* fmul dword ptr [esp + 0x8c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x6cu))); /* fld dword ptr [esp + 0x6c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x9cu))); /* fmul dword ptr [esp + 0x9c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x70u))); /* fld dword ptr [esp + 0x70] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xacu))); /* fmul dword ptr [esp + 0xac] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x64u))); /* fld dword ptr [esp + 0x64] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x7cu))); /* fmul dword ptr [esp + 0x7c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->esp + 0xf4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xf4] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x68u))); /* fld dword ptr [esp + 0x68] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x90u))); /* fmul dword ptr [esp + 0x90] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x6cu))); /* fld dword ptr [esp + 0x6c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xa0u))); /* fmul dword ptr [esp + 0xa0] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x70u))); /* fld dword ptr [esp + 0x70] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xb0u))); /* fmul dword ptr [esp + 0xb0] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x64u))); /* fld dword ptr [esp + 0x64] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x80u))); /* fmul dword ptr [esp + 0x80] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->esp + 0xf8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xf8] */
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
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xb4u))); /* mov edx, dword ptr [esp + 0xb4] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0xbcu)); /* lea eax, [esp + 0xbc] */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x20u)); /* add edx, 0x20 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x74u)); /* lea ecx, [esp + 0x74] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b92614u); f_00b936d0(c); /* call 0xb936d0 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x74u)); /* lea ecx, [esp + 0x74] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x228u)); /* lea edx, [esp + 0x228] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x10], ecx */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x14], edx */
    c->df = 0; /* cld  */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edi, dword ptr [esp + 0x14] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)((uint32_t)0x10u); /* mov ecx, 0x10 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x228u)); /* lea eax, [esp + 0x228] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0xfcu)); /* lea ecx, [esp + 0xfc] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x14], ecx */
    c->df = 0; /* cld  */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edi, dword ptr [esp + 0x14] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)((uint32_t)0x10u); /* mov ecx, 0x10 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov esi, dword ptr [esp + 0x18] */
L_00b92661:;
    c->edx = (uint32_t)((uint32_t)(c->esp + 0xfcu)); /* lea edx, [esp + 0xfc] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x20u)); /* add esi, 0x20 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x10], edx */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x14], esi */
    c->df = 0; /* cld  */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edi, dword ptr [esp + 0x14] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)((uint32_t)0x10u); /* mov ecx, 0x10 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov ecx, dword ptr [esp + 0x18] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0xcu)); PUSH32(c, 0x00b9268eu); call_indirect(c, t_); } /* call dword ptr [eax + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x20u))); /* mov ecx, dword ptr [ebp + 0x20] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x178u)); PUSH32(c, 0x00b9269du); call_indirect(c, t_); } /* call dword ptr [edx + 0x178] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x228u)); /* lea eax, [esp + 0x228] */
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
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x20u))); /* mov ecx, dword ptr [ebp + 0x20] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x228u)); /* lea eax, [esp + 0x228] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x100u; PUSH32(c, v_); } /* push 0x100 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x58u)); PUSH32(c, 0x00b926f7u); call_indirect(c, t_); } /* call dword ptr [edx + 0x58] */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0x980u)); /* lea ecx, [ebp + 0x980] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x864u)); /* lea eax, [ebp + 0x864] */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->esp + 0xb8u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0xb8], ecx */
    W32((uint32_t)(c->esp + 0xb4u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0xb4], eax */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)((uint32_t)0x3fu)); /* mov dword ptr [esp + 0x18], 0x3f */
    goto L_00b9272b; /* jmp 0xb9272b */
L_00b9271d:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xb4u))); /* mov eax, dword ptr [esp + 0xb4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xb8u))); /* mov ecx, dword ptr [esp + 0xb8] */
L_00b9272b:;
    c->edx = (uint32_t)((uint32_t)(c->eax + 0xffffffe0u)); /* lea edx, [eax - 0x20] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    W32((uint32_t)(c->esp + 0x26cu), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x26c], edx */
    c->edi = (uint32_t)(R32((uint32_t)(c->edx))); /* mov edi, dword ptr [edx] */
    W32((uint32_t)(c->esi), (uint32_t)(c->edi)); /* mov dword ptr [esi], edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov edi, dword ptr [edx + 4] */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 4], edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov edi, dword ptr [edx + 8] */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 8], edi */
    c->edx = (uint32_t)(R32((uint32_t)(c->edx + 0xcu))); /* mov edx, dword ptr [edx + 0xc] */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0xc], edx */
    c->edx = (uint32_t)((uint32_t)(c->eax + 0xfffffff0u)); /* lea edx, [eax - 0x10] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x10u)); /* add eax, 0x10 */
    c->esi = (uint32_t)(R32((uint32_t)(c->edx))); /* mov esi, dword ptr [edx] */
    W32((uint32_t)(c->eax), (uint32_t)(c->esi)); /* mov dword ptr [eax], esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov esi, dword ptr [edx + 4] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [eax + 4], esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov esi, dword ptr [edx + 8] */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [eax + 8], esi */
    c->edx = (uint32_t)(R32((uint32_t)(c->edx + 0xcu))); /* mov edx, dword ptr [edx + 0xc] */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->edx)); /* mov dword ptr [eax + 0xc], edx */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0xfffffffcu))); /* fld dword ptr [ecx - 4] */
    WF32((uint32_t)(c->ecx), (float)ST(0)); /* fst dword ptr [ecx] */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ebp + 0x7cu))); /* fadd dword ptr [ebp + 0x7c] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->ebp + 0x80u))); FPOP(c); /* fcomp dword ptr [ebp + 0x80] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x41u)); /* test ah, 0x41 */
    if (!PF(c)) goto L_00b9288e; /* jnp 0xb9288e */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(c->ebp + 0x80u)) - ST(0)); /* fsubr dword ptr [ebp + 0x80] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0x73u))); /* mov al, byte ptr [ebp + 0x73] */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0x77u))); /* mov cl, byte ptr [ebp + 0x77] */
    ST(0) = FPRES(c, FDIV(c, ST(0), (double)RF32((uint32_t)(c->ebp + 0x7cu)))); /* fdiv dword ptr [ebp + 0x7c] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    W32((uint32_t)(c->esp + 0x268u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x268], ebx */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x10u))); /* fild dword ptr [esp + 0x10] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x10], ecx */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x10u))); /* fild dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) - ST(1)); /* fsub st(1) */
    ST(0) = FPRES(c, ST(0) * ST(2)); /* fmul st(2) */
    ST(0) = FPRES(c, ST(0) + ST(1)); /* fadd st(1) */
    PUSH32(c, 0x00b927bau); f_00b93e54(c); /* call 0xb93e54 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0x72u))); /* mov dl, byte ptr [ebp + 0x72] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0x76u))); /* mov al, byte ptr [ebp + 0x76] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0xffu))); /* and edx, 0xff */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x10], edx */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xffu))); /* and eax, 0xff */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x10u))); /* fild dword ptr [esp + 0x10] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x10u))); /* fild dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) - ST(1)); /* fsub st(1) */
    ST(0) = FPRES(c, ST(0) * ST(2)); /* fmul st(2) */
    ST(0) = FPRES(c, ST(0) + ST(1)); /* fadd st(1) */
    PUSH32(c, 0x00b927eau); f_00b93e54(c); /* call 0xb93e54 */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x70u))); /* mov edi, dword ptr [ebp + 0x70] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x74u))); /* mov ebx, dword ptr [ebp + 0x74] */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    c->edx = (uint32_t)(c->ebx); /* mov edx, ebx */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 8)); /* sar ecx, 8 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0xffu))); /* and ecx, 0xff */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    c->edx = (uint32_t)(sar32(c, c->edx, 8)); /* sar edx, 8 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x10], ecx */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0xffu))); /* and edx, 0xff */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x10u))); /* fild dword ptr [esp + 0x10] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x10], edx */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x10u))); /* fild dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) - ST(1)); /* fsub st(1) */
    ST(0) = FPRES(c, ST(0) * ST(2)); /* fmul st(2) */
    ST(0) = FPRES(c, ST(0) + ST(1)); /* fadd st(1) */
    PUSH32(c, 0x00b92827u); f_00b93e54(c); /* call 0xb93e54 */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & (uint32_t)0xffu))); /* and edi, 0xff */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0xffu))); /* and ebx, 0xff */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x10], edi */
    W32((uint32_t)(c->esp + 0x270u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x270], eax */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x10u))); /* fild dword ptr [esp + 0x10] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x10], ebx */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x10u))); /* fild dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) - ST(1)); /* fsub st(1) */
    ST(0) = FPRES(c, ST(0) * ST(2)); /* fmul st(2) */
    ST(0) = FPRES(c, ST(0) + ST(1)); /* fadd st(1) */
    PUSH32(c, 0x00b92857u); f_00b93e54(c); /* call 0xb93e54 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ecx, dword ptr [esp + 0x14] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x270u))); /* mov edi, dword ptr [esp + 0x270] */
    c->esi = (uint32_t)(shl32(c, c->esi, 8)); /* shl esi, 8 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi | c->ecx))); /* or esi, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xb4u))); /* mov ecx, dword ptr [esp + 0xb4] */
    c->esi = (uint32_t)(shl32(c, c->esi, 8)); /* shl esi, 8 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi | c->edi))); /* or esi, edi */
    c->esi = (uint32_t)(shl32(c, c->esi, 8)); /* shl esi, 8 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->esi))); /* or eax, esi */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    W32((uint32_t)(c->ecx + 0x1cu), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 0x1c], eax */
    W32((uint32_t)(c->ecx + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 0xc], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xb8u))); /* mov ecx, dword ptr [esp + 0xb8] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x268u))); /* mov ebx, dword ptr [esp + 0x268] */
L_00b9288e:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x26cu))); /* mov eax, dword ptr [esp + 0x26c] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0xfffffffcu)); /* add ecx, -4 */
    W32((uint32_t)(c->esp + 0xb4u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0xb4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    W32((uint32_t)(c->esp + 0xb8u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0xb8], ecx */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x18], eax */
    if (!c->zf) goto L_00b9271d; /* jne 0xb9271d */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov esi, dword ptr [esp + 0x1c] */
    c->edx = (uint32_t)(R32((uint32_t)(0xb9c050u))); /* mov edx, dword ptr [0x1000c050] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x88u))); /* mov ecx, dword ptr [esi + 0x88] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edi, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edi)); PUSH32(c, 0x00b928ccu); call_indirect(c, t_); } /* call dword ptr [edi] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x88u))); /* mov ecx, dword ptr [esi + 0x88] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t t_ = R32((uint32_t)(c->edi + 0x8u)); PUSH32(c, 0x00b928d8u); call_indirect(c, t_); } /* call dword ptr [edi + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf != c->of)) goto L_00b92b1c; /* jl 0xb92b1c */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x88u))); /* mov ecx, dword ptr [esi + 0x88] */
    c->edi = (uint32_t)((uint32_t)(c->esp + 0x274u)); /* lea edi, [esp + 0x274] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x10u)); PUSH32(c, 0x00b928f4u); call_indirect(c, t_); } /* call dword ptr [edx + 0x10] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x2a8u))); /* fld dword ptr [esp + 0x2a8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x2acu))); /* fld dword ptr [esp + 0x2ac] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x2b0u))); /* fld dword ptr [esp + 0x2b0] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xfcu))); /* fld dword ptr [esp + 0xfc] */
    ST(0) = FPRES(c, ST(0) * ST(3)); /* fmul st(3) */
    { double v_ = ST(1); FPUSH(c, v_); } /* fld st(1) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x11cu))); /* fmul dword ptr [esp + 0x11c] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x84u)); /* lea eax, [ebp + 0x84] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    { double v_ = ST(2); FPUSH(c, v_); } /* fld st(2) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x10cu))); /* fmul dword ptr [esp + 0x10c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x12cu))); /* fadd dword ptr [esp + 0x12c] */
    WF32((uint32_t)(c->esp + 0x28u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x28] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x120u))); /* fld dword ptr [esp + 0x120] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    { double v_ = ST(2); FPUSH(c, v_); } /* fld st(2) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x110u))); /* fmul dword ptr [esp + 0x110] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov ecx, dword ptr [esp + 0x28] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    { double v_ = ST(3); FPUSH(c, v_); } /* fld st(3) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x100u))); /* fmul dword ptr [esp + 0x100] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x130u))); /* fadd dword ptr [esp + 0x130] */
    WF32((uint32_t)(c->esp + 0x2cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x2c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov edx, dword ptr [esp + 0x2c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x124u))); /* fmul dword ptr [esp + 0x124] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x114u))); /* fmul dword ptr [esp + 0x114] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 4], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x70u))); /* mov edx, dword ptr [ebp + 0x70] */
    W32((uint32_t)(c->ebp + 0x90u), (uint32_t)(c->edx)); /* mov dword ptr [ebp + 0x90], edx */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x104u))); /* fld dword ptr [esp + 0x104] */
    ST(0) = FPRES(c, ST(0) * ST(2)); /* fmul st(2) */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x134u))); /* fadd dword ptr [esp + 0x134] */
    WF32((uint32_t)(c->esp + 0x30u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x30] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov ecx, dword ptr [esp + 0x30] */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x88u))); /* mov ecx, dword ptr [esi + 0x88] */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9c054u))); /* mov eax, dword ptr [0x1000c054] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edi, dword ptr [ecx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    { uint32_t t_ = R32((uint32_t)(c->edi)); PUSH32(c, 0x00b929bau); call_indirect(c, t_); } /* call dword ptr [edi] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x88u))); /* mov ecx, dword ptr [esi + 0x88] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t t_ = R32((uint32_t)(c->edi + 0x8u)); PUSH32(c, 0x00b929c6u); call_indirect(c, t_); } /* call dword ptr [edi + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf != c->of)) goto L_00b92af9; /* jl 0xb92af9 */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0x88u))); /* mov esi, dword ptr [esi + 0x88] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x274u)); /* lea ecx, [esp + 0x274] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x10u)); PUSH32(c, 0x00b929e4u); call_indirect(c, t_); } /* call dword ptr [edx + 0x10] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x2a8u))); /* fld dword ptr [esp + 0x2a8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x2acu))); /* fld dword ptr [esp + 0x2ac] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x2b0u))); /* fld dword ptr [esp + 0x2b0] */
    { double v_ = ST(2); FPUSH(c, v_); } /* fld st(2) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xfcu))); /* fmul dword ptr [esp + 0xfc] */
    { double v_ = ST(1); FPUSH(c, v_); } /* fld st(1) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x11cu))); /* fmul dword ptr [esp + 0x11c] */
    c->edx = (uint32_t)((uint32_t)(c->ebp + 0x94u)); /* lea edx, [ebp + 0x94] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0xb9c1acu; PUSH32(c, v_); } /* push 0x1000c1ac */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    { double v_ = ST(2); FPUSH(c, v_); } /* fld st(2) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x114u))); /* fmul dword ptr [esp + 0x114] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x134u))); /* fadd dword ptr [esp + 0x134] */
    WF32((uint32_t)(c->esp + 0x30u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x30] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x128u))); /* fld dword ptr [esp + 0x128] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    { double v_ = ST(2); FPUSH(c, v_); } /* fld st(2) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x118u))); /* fmul dword ptr [esp + 0x118] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov eax, dword ptr [esp + 0x30] */
    W32((uint32_t)(c->edx), (uint32_t)(c->eax)); /* mov dword ptr [edx], eax */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    { double v_ = ST(3); FPUSH(c, v_); } /* fld st(3) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x108u))); /* fmul dword ptr [esp + 0x108] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x138u))); /* fadd dword ptr [esp + 0x138] */
    WF32((uint32_t)(c->esp + 0x34u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x34] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov ecx, dword ptr [esp + 0x34] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x12cu))); /* fmul dword ptr [esp + 0x12c] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x11cu))); /* fmul dword ptr [esp + 0x11c] */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [edx + 4], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x70u))); /* mov ecx, dword ptr [ebp + 0x70] */
    W32((uint32_t)(c->ebp + 0xa0u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp + 0xa0], ecx */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10cu))); /* fld dword ptr [esp + 0x10c] */
    ST(0) = FPRES(c, ST(0) * ST(2)); /* fmul st(2) */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x13cu))); /* fadd dword ptr [esp + 0x13c] */
    WF32((uint32_t)(c->esp + 0x38u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x38] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x38u))); /* mov eax, dword ptr [esp + 0x38] */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [edx + 8], eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x80u))); /* mov edx, dword ptr [ebp + 0x80] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x20u))); /* mov eax, dword ptr [ebp + 0x20] */
    W32((uint32_t)(c->ebp + 0x884u), (uint32_t)(c->edx)); /* mov dword ptr [ebp + 0x884], edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0xc0u)); PUSH32(c, 0x00b92ab9u); call_indirect(c, t_); } /* call dword ptr [ecx + 0xc0] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00b92ae8; /* je 0xb92ae8 */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if ((c->zf || c->sf != c->of)) goto L_00b92ae8; /* jle 0xb92ae8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x20u))); /* mov eax, dword ptr [ebp + 0x20] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0x84u)); /* lea ecx, [ebp + 0x84] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)((uint32_t)(c->ebx + c->ebx)); /* lea ecx, [ebx + ebx] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x42u; PUSH32(c, v_); } /* push 0x42 */
    { uint32_t v_ = 0x5u; PUSH32(c, v_); } /* push 5 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xe8u)); PUSH32(c, 0x00b92ae5u); call_indirect(c, t_); } /* call dword ptr [edx + 0xe8] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
L_00b92ae8:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x20u))); /* mov ecx, dword ptr [ebp + 0x20] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xc4u)); PUSH32(c, 0x00b92af3u); call_indirect(c, t_); } /* call dword ptr [edx + 0xc4] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00b92ae8; /* jne 0xb92ae8 */
    goto L_00b92b45; /* jmp 0xb92b45 */
L_00b92af9:;
    c->eax = (uint32_t)(R32((uint32_t)(0xb9ef8cu))); /* mov eax, dword ptr [0x1000ef8c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->edi = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edi, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x4u)); PUSH32(c, 0x00b92b07u); call_indirect(c, t_); } /* call dword ptr [edx + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb9ef8cu))); /* mov ecx, dword ptr [0x1000ef8c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9c054u))); /* mov eax, dword ptr [0x1000c054] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0xb9c178u; PUSH32(c, v_); } /* push 0x1000c178 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    goto L_00b92b3f; /* jmp 0xb92b3f */
L_00b92b1c:;
    c->edx = (uint32_t)(R32((uint32_t)(0xb9ef8cu))); /* mov edx, dword ptr [0x1000ef8c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->edi = (uint32_t)(R32((uint32_t)(c->edx))); /* mov edi, dword ptr [edx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4u)); PUSH32(c, 0x00b92b2bu); call_indirect(c, t_); } /* call dword ptr [eax + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb9c050u))); /* mov ecx, dword ptr [0x1000c050] */
    c->edx = (uint32_t)(R32((uint32_t)(0xb9ef8cu))); /* mov edx, dword ptr [0x1000ef8c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0xb9c178u; PUSH32(c, v_); } /* push 0x1000c178 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
L_00b92b3f:;
    { uint32_t t_ = R32((uint32_t)(c->edi + 0x30u)); PUSH32(c, 0x00b92b42u); call_indirect(c, t_); } /* call dword ptr [edi + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_00b92b45:;
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x13cu)); /* lea eax, [esp + 0x13c] */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x1c], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov eax, dword ptr [esp + 0x1c] */
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
    c->ebp = (uint32_t)(R32((uint32_t)(c->ebp + 0x20u))); /* mov ebp, dword ptr [ebp + 0x20] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x13cu)); /* lea eax, [esp + 0x13c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x11u; PUSH32(c, v_); } /* push 0x11 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov edx, dword ptr [ebp] */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x58u)); PUSH32(c, 0x00b92b9fu); call_indirect(c, t_); } /* call dword ptr [edx + 0x58] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
L_00b92ba2:;
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2d0u)); /* add esp, 0x2d0 */
    c->esp += 8; return; /* ret 4 */
}

void f_00b92bb0(CPU *c) { /* FUN_10002bb0 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x1e8u)); /* sub esp, 0x1e8 */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9efa4u))); /* mov eax, dword ptr [0x1000efa4] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ebp = (uint32_t)((uint32_t)(c->ecx + 0x40u)); /* lea ebp, [ecx + 0x40] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x2c], ecx */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->esi = (uint32_t)(c->ebp); /* mov esi, ebp */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x60u)); PUSH32(c, 0x00b92bdbu); call_indirect(c, t_); } /* call dword ptr [edx + 0x60] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x1fcu))); /* mov ebx, dword ptr [esp + 0x1fc] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x18u)); /* lea ecx, [esp + 0x18] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x24u)); PUSH32(c, 0x00b92beeu); call_indirect(c, t_); } /* call dword ptr [eax + 0x24] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edx, dword ptr [esp + 0x14] */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->edi = (uint32_t)((uint32_t)(c->edx + 0x28u)); /* lea edi, [edx + 0x28] */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x30u)); /* lea ecx, [esp + 0x30] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0xc8u; PUSH32(c, v_); } /* push 0xc8 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x30u)); PUSH32(c, 0x00b92c0fu); call_indirect(c, t_); } /* call dword ptr [eax + 0x30] */
    c->edi = (uint32_t)((uint32_t)(c->esp + 0x30u)); /* lea edi, [esp + 0x30] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0xffffffffu))); /* or ecx, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W8((uint32_t)(c->esp + 0xf7u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esp + 0xf7], 0 */
    while (c->ecx) { (void)sub8(c, ((uint8_t)c->eax), R8(c->edi)); c->edi += (c->df ? -1 : 1); c->ecx--; if (c->zf) break; } /* repne scasb al, byte ptr es:[edi] */
    c->ecx = (uint32_t)((uint32_t)~c->ecx); /* not ecx */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_00b92d07; /* je 0xb92d07 */
L_00b92c2b:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0xb9c1ecu))); /* mov cl, byte ptr [eax + 0x1000c1ec] */
    W8((uint32_t)(c->esp + c->eax + 0xf8u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esp + eax + 0xf8], cl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_00b92c2b; /* jne 0xb92c2b */
    c->edi = (uint32_t)((uint32_t)(c->esp + 0x30u)); /* lea edi, [esp + 0x30] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0xffffffffu))); /* or ecx, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0xf8u)); /* lea edx, [esp + 0xf8] */
    while (c->ecx) { (void)sub8(c, ((uint8_t)c->eax), R8(c->edi)); c->edi += (c->df ? -1 : 1); c->ecx--; if (c->zf) break; } /* repne scasb al, byte ptr es:[edi] */
    c->ecx = (uint32_t)((uint32_t)~c->ecx); /* not ecx */
    c->edi = (uint32_t)(sub32(c, c->edi, c->ecx)); /* sub edi, ecx */
    { uint32_t v_ = 0xb9c1e0u; PUSH32(c, v_); } /* push 0x1000c1e0 */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->esi = (uint32_t)(c->edi); /* mov esi, edi */
    c->edi = (uint32_t)(c->edx); /* mov edi, edx */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0xffffffffu))); /* or ecx, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    while (c->ecx) { (void)sub8(c, ((uint8_t)c->eax), R8(c->edi)); c->edi += (c->df ? -1 : 1); c->ecx--; if (c->zf) break; } /* repne scasb al, byte ptr es:[edi] */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u))); /* and ecx, 3 */
    while (c->ecx) { W8(c->edi, R8(c->esi)); c->esi += (c->df ? -1 : 1); c->edi += (c->df ? -1 : 1); c->ecx--; } /* rep movsb byte ptr es:[edi], byte ptr [esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb9efa4u))); /* mov ecx, dword ptr [0x1000efa4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4cu)); PUSH32(c, 0x00b92c81u); call_indirect(c, t_); } /* call dword ptr [eax + 0x4c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    if (c->zf) goto L_00b92c95; /* je 0xb92c95 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0xb9c1ecu; PUSH32(c, v_); } /* push 0x1000c1ec */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x38u)); PUSH32(c, 0x00b92c95u); call_indirect(c, t_); } /* call dword ptr [edx + 0x38] */
L_00b92c95:;
    c->ecx = (uint32_t)(R32((uint32_t)(0xb9efa4u))); /* mov ecx, dword ptr [0x1000efa4] */
    { uint32_t v_ = 0xb9c1d8u; PUSH32(c, v_); } /* push 0x1000c1d8 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x5cu)); PUSH32(c, 0x00b92ca6u); call_indirect(c, t_); } /* call dword ptr [eax + 0x5c] */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9efa4u))); /* mov eax, dword ptr [0x1000efa4] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0xf8u)); /* lea ecx, [esp + 0xf8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x5014u; PUSH32(c, v_); } /* push 0x5014 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0xb9c1d4u; PUSH32(c, v_); } /* push 0x1000c1d4 */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->esi = (uint32_t)(c->ebp); /* mov esi, ebp */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x98u)); PUSH32(c, 0x00b92cd4u); call_indirect(c, t_); } /* call dword ptr [edx + 0x98] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x28u)); /* add esp, 0x28 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b92d16; /* jne 0xb92d16 */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9efa4u))); /* mov eax, dword ptr [0x1000efa4] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->esi = (uint32_t)(c->ebp); /* mov esi, ebp */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x60u)); PUSH32(c, 0x00b92cf5u); call_indirect(c, t_); } /* call dword ptr [edx + 0x60] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00b92d07; /* je 0xb92d07 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = 0xb9efacu; PUSH32(c, v_); } /* push 0x1000efac */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x38u)); PUSH32(c, 0x00b92d07u); call_indirect(c, t_); } /* call dword ptr [eax + 0x38] */
L_00b92d07:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1e8u)); /* add esp, 0x1e8 */
    c->esp += 8; return; /* ret 4 */
L_00b92d16:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00b92d28; /* je 0xb92d28 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = 0xb9efacu; PUSH32(c, v_); } /* push 0x1000efac */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x38u)); PUSH32(c, 0x00b92d28u); call_indirect(c, t_); } /* call dword ptr [edx + 0x38] */
L_00b92d28:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x00b92d2fu); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov esi, dword ptr [esp + 0x14] */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    WF32((uint32_t)(c->esi + 0x78u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x78] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov edx, dword ptr [ebx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x00b92d3du); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    W32((uint32_t)(c->esi + 0x70u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x70], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0xcu)); PUSH32(c, 0x00b92d47u); call_indirect(c, t_); } /* call dword ptr [eax + 0xc] */
    W32((uint32_t)(c->esi + 0x74u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x74], eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1e8u)); /* add esp, 0x1e8 */
    c->esp += 8; return; /* ret 4 */
}

void f_00b92d60(CPU *c) { /* FUN_10002d60 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x1e4u)); /* sub esp, 0x1e4 */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9efa4u))); /* mov eax, dword ptr [0x1000efa4] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ebp = (uint32_t)(c->ecx); /* mov ebp, ecx */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    c->esi = (uint32_t)((uint32_t)(c->ebp + 0x58u)); /* lea esi, [ebp + 0x58] */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x28], esi */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x60u)); PUSH32(c, 0x00b92d8bu); call_indirect(c, t_); } /* call dword ptr [edx + 0x60] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x1f8u))); /* mov ebx, dword ptr [esp + 0x1f8] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea ecx, [esp + 0x14] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x24u)); PUSH32(c, 0x00b92d9eu); call_indirect(c, t_); } /* call dword ptr [eax + 0x24] */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0x28u)); /* lea edi, [ebp + 0x28] */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x2cu)); /* lea eax, [esp + 0x2c] */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov edx, dword ptr [ebx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0xc8u; PUSH32(c, v_); } /* push 0xc8 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x30u)); PUSH32(c, 0x00b92dbbu); call_indirect(c, t_); } /* call dword ptr [edx + 0x30] */
    c->edi = (uint32_t)((uint32_t)(c->esp + 0x2cu)); /* lea edi, [esp + 0x2c] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0xffffffffu))); /* or ecx, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W8((uint32_t)(c->esp + 0xf3u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esp + 0xf3], 0 */
    while (c->ecx) { (void)sub8(c, ((uint8_t)c->eax), R8(c->edi)); c->edi += (c->df ? -1 : 1); c->ecx--; if (c->zf) break; } /* repne scasb al, byte ptr es:[edi] */
    c->ecx = (uint32_t)((uint32_t)~c->ecx); /* not ecx */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_00b92eaf; /* je 0xb92eaf */
L_00b92dd7:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0xb9c1ecu))); /* mov cl, byte ptr [eax + 0x1000c1ec] */
    W8((uint32_t)(c->esp + c->eax + 0xf4u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esp + eax + 0xf4], cl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_00b92dd7; /* jne 0xb92dd7 */
    c->edi = (uint32_t)((uint32_t)(c->esp + 0x2cu)); /* lea edi, [esp + 0x2c] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0xffffffffu))); /* or ecx, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0xf4u)); /* lea edx, [esp + 0xf4] */
    while (c->ecx) { (void)sub8(c, ((uint8_t)c->eax), R8(c->edi)); c->edi += (c->df ? -1 : 1); c->ecx--; if (c->zf) break; } /* repne scasb al, byte ptr es:[edi] */
    c->ecx = (uint32_t)((uint32_t)~c->ecx); /* not ecx */
    c->edi = (uint32_t)(sub32(c, c->edi, c->ecx)); /* sub edi, ecx */
    { uint32_t v_ = 0xb9c1e0u; PUSH32(c, v_); } /* push 0x1000c1e0 */
    c->esi = (uint32_t)(c->edi); /* mov esi, edi */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    c->edi = (uint32_t)(c->edx); /* mov edi, edx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0xffffffffu))); /* or ecx, 0xffffffff */
    while (c->ecx) { (void)sub8(c, ((uint8_t)c->eax), R8(c->edi)); c->edi += (c->df ? -1 : 1); c->ecx--; if (c->zf) break; } /* repne scasb al, byte ptr es:[edi] */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u))); /* and ecx, 3 */
    while (c->ecx) { W8(c->edi, R8(c->esi)); c->esi += (c->df ? -1 : 1); c->edi += (c->df ? -1 : 1); c->ecx--; } /* rep movsb byte ptr es:[edi], byte ptr [esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb9efa4u))); /* mov ecx, dword ptr [0x1000efa4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4cu)); PUSH32(c, 0x00b92e29u); call_indirect(c, t_); } /* call dword ptr [eax + 0x4c] */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (c->zf) goto L_00b92e3b; /* je 0xb92e3b */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov edx, dword ptr [ebx] */
    { uint32_t v_ = 0xb9c1ecu; PUSH32(c, v_); } /* push 0x1000c1ec */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x38u)); PUSH32(c, 0x00b92e3bu); call_indirect(c, t_); } /* call dword ptr [edx + 0x38] */
L_00b92e3b:;
    c->ecx = (uint32_t)(R32((uint32_t)(0xb9efa4u))); /* mov ecx, dword ptr [0x1000efa4] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ebp, dword ptr [esp + 0x10] */
    { uint32_t v_ = 0xb9c1d8u; PUSH32(c, v_); } /* push 0x1000c1d8 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x5cu)); PUSH32(c, 0x00b92e50u); call_indirect(c, t_); } /* call dword ptr [eax + 0x5c] */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9efa4u))); /* mov eax, dword ptr [0x1000efa4] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0xf4u)); /* lea ecx, [esp + 0xf4] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x5014u; PUSH32(c, v_); } /* push 0x5014 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0xb9c1d4u; PUSH32(c, v_); } /* push 0x1000c1d4 */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->esi = (uint32_t)(c->ebp); /* mov esi, ebp */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x98u)); PUSH32(c, 0x00b92e7eu); call_indirect(c, t_); } /* call dword ptr [edx + 0x98] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x28u)); /* add esp, 0x28 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b92ebe; /* jne 0xb92ebe */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9efa4u))); /* mov eax, dword ptr [0x1000efa4] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->esi = (uint32_t)(c->ebp); /* mov esi, ebp */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x60u)); PUSH32(c, 0x00b92e9fu); call_indirect(c, t_); } /* call dword ptr [edx + 0x60] */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (c->zf) goto L_00b92eaf; /* je 0xb92eaf */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    { uint32_t v_ = 0xb9efacu; PUSH32(c, v_); } /* push 0x1000efac */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x38u)); PUSH32(c, 0x00b92eafu); call_indirect(c, t_); } /* call dword ptr [eax + 0x38] */
L_00b92eaf:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1e4u)); /* add esp, 0x1e4 */
    c->esp += 8; return; /* ret 4 */
L_00b92ebe:;
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (c->zf) goto L_00b92ece; /* je 0xb92ece */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov edx, dword ptr [ebx] */
    { uint32_t v_ = 0xb9efacu; PUSH32(c, v_); } /* push 0x1000efac */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x38u)); PUSH32(c, 0x00b92eceu); call_indirect(c, t_); } /* call dword ptr [edx + 0x38] */
L_00b92ece:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1e4u)); /* add esp, 0x1e4 */
    c->esp += 8; return; /* ret 4 */
}

void f_00b92ee0(CPU *c) { /* FUN_10002ee0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(logic32(c, (uint32_t)(c->esp & (uint32_t)0xfffffff8u))); /* and esp, 0xfffffff8 */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x1e0u)); /* sub esp, 0x1e0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb9efa4u))); /* mov ecx, dword ptr [0x1000efa4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)((uint32_t)(c->edi + 0x28u)); /* lea edx, [edi + 0x28] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x64u)); PUSH32(c, 0x00b92f01u); call_indirect(c, t_); } /* call dword ptr [eax + 0x64] */
    c->ebp = (uint32_t)(c->eax); /* mov ebp, eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov eax, dword ptr [ebp] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x34u)); PUSH32(c, 0x00b92f0du); call_indirect(c, t_); } /* call dword ptr [eax + 0x34] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x28u)); /* lea ecx, [esp + 0x28] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x20], ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov eax, dword ptr [esp + 0x20] */
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
    c->ecx = (uint32_t)(R32((uint32_t)(0xb9efa4u))); /* mov ecx, dword ptr [0x1000efa4] */
    c->eax = (uint32_t)((uint32_t)(c->edi + 0x58u)); /* lea eax, [edi + 0x58] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x64u)); PUSH32(c, 0x00b92f60u); call_indirect(c, t_); } /* call dword ptr [edx + 0x64] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b9346b; /* je 0xb9346b */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x34u)); PUSH32(c, 0x00b92f71u); call_indirect(c, t_); } /* call dword ptr [edx + 0x34] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x88u))); /* mov ecx, dword ptr [esi + 0x88] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + 0x988u))); /* mov edx, dword ptr [edi + 0x988] */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x28], ebx */
    { uint32_t t_ = R32((uint32_t)(c->eax)); PUSH32(c, 0x00b92f88u); call_indirect(c, t_); } /* call dword ptr [eax] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x88u))); /* mov ecx, dword ptr [esi + 0x88] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x00b92f96u); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)sub32(c, c->edi, (uint32_t)0xffffffffu); /* cmp edi, -1 */
    if ((c->zf || c->sf != c->of)) goto L_00b932a3; /* jle 0xb932a3 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov eax, dword ptr [ebp] */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x40u)); PUSH32(c, 0x00b92fa9u); call_indirect(c, t_); } /* call dword ptr [eax + 0x40] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x1cu)); PUSH32(c, 0x00b92fb2u); call_indirect(c, t_); } /* call dword ptr [edx + 0x1c] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0x88u))); /* mov esi, dword ptr [esi + 0x88] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x140u)); /* lea ecx, [esp + 0x140] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x10u)); PUSH32(c, 0x00b92fccu); call_indirect(c, t_); } /* call dword ptr [eax + 0x10] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x80u)); /* lea edx, [esp + 0x80] */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x20], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov eax, dword ptr [esp + 0x20] */
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
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x144u))); /* fld dword ptr [esp + 0x144] */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x148u))); /* fld dword ptr [esp + 0x148] */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14cu))); /* fld dword ptr [esp + 0x14c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov ecx, dword ptr [esp + 0x18] */
    WF32((uint32_t)(c->esp + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x154u))); /* fld dword ptr [esp + 0x154] */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x158u))); /* fld dword ptr [esp + 0x158] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov edx, dword ptr [esp + 0x1c] */
    W32((uint32_t)(c->esp + 0x80u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x80], eax */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x15cu))); /* fld dword ptr [esp + 0x15c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    W32((uint32_t)(c->esp + 0x84u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x84], ecx */
    WF32((uint32_t)(c->esp + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x164u))); /* fld dword ptr [esp + 0x164] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov ecx, dword ptr [esp + 0x18] */
    W32((uint32_t)(c->esp + 0x88u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x88], edx */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x168u))); /* fld dword ptr [esp + 0x168] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov edx, dword ptr [esp + 0x1c] */
    W32((uint32_t)(c->esp + 0x90u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x90], eax */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x16cu))); /* fld dword ptr [esp + 0x16c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    W32((uint32_t)(c->esp + 0x94u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x94], ecx */
    WF32((uint32_t)(c->esp + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x174u))); /* fld dword ptr [esp + 0x174] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov ecx, dword ptr [esp + 0x18] */
    W32((uint32_t)(c->esp + 0x98u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x98], edx */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x178u))); /* fld dword ptr [esp + 0x178] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov edx, dword ptr [esp + 0x1c] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edi, dword ptr [esp + 0x10] */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x17cu))); /* fld dword ptr [esp + 0x17c] */
    WF32((uint32_t)(c->esp + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1c] */
    W32((uint32_t)(c->esp + 0xa8u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0xa8], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov edx, dword ptr [esp + 0x1c] */
    W32((uint32_t)(c->esp + 0xa0u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0xa0], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    W32((uint32_t)(c->esp + 0xa4u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0xa4], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov ecx, dword ptr [esp + 0x18] */
    W32((uint32_t)(c->esp + 0xb8u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0xb8], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x18cu))); /* mov edx, dword ptr [esp + 0x18c] */
    W32((uint32_t)(c->esp + 0xb0u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0xb0], eax */
    W32((uint32_t)(c->esp + 0xb4u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0xb4], ecx */
    c->edx = (uint32_t)(shl32(c, c->edx, 6)); /* shl edx, 6 */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x100u)); /* lea eax, [esp + 0x100] */
    c->edx = (uint32_t)(add32(c, c->edx, c->edi)); /* add edx, edi */
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
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x80u)); /* lea ecx, [esp + 0x80] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x108u)); /* lea ecx, [esp + 0x108] */
    PUSH32(c, 0x00b93183u); f_00b936d0(c); /* call 0xb936d0 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x100u)); /* lea edx, [esp + 0x100] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0xc0u)); /* lea eax, [esp + 0xc0] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x10], edx */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x20], eax */
    c->df = 0; /* cld  */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov edi, dword ptr [esp + 0x20] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)((uint32_t)0x10u); /* mov ecx, 0x10 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xf0u))); /* fld dword ptr [esp + 0xf0] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb9b170u))); /* fmul dword ptr [0x1000b170] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x1b0u)); /* lea ecx, [esp + 0x1b0] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x10], ecx */
    WF32((uint32_t)(c->esp + 0xf0u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xf0] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xc0u))); /* fld dword ptr [esp + 0xc0] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb9b170u))); /* fmul dword ptr [0x1000b170] */
    WF32((uint32_t)(c->esp + 0xc0u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xc0] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xd0u))); /* fld dword ptr [esp + 0xd0] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb9b170u))); /* fmul dword ptr [0x1000b170] */
    WF32((uint32_t)(c->esp + 0xd0u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xd0] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xe0u))); /* fld dword ptr [esp + 0xe0] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb9b170u))); /* fmul dword ptr [0x1000b170] */
    WF32((uint32_t)(c->esp + 0xe0u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xe0] */
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
    c->ebp = (uint32_t)(add32(c, c->ebp, (uint32_t)0x20u)); /* add ebp, 0x20 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0xc0u)); /* lea edx, [esp + 0xc0] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x1b8u)); /* lea ecx, [esp + 0x1b8] */
    PUSH32(c, 0x00b93256u); f_00b936d0(c); /* call 0xb936d0 */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x1b0u)); /* lea eax, [esp + 0x1b0] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x100u)); /* lea ecx, [esp + 0x100] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x20], ecx */
    c->df = 0; /* cld  */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov edi, dword ptr [esp + 0x20] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)((uint32_t)0x10u); /* mov ecx, 0x10 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x100u)); /* lea edx, [esp + 0x100] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x28u)); /* lea eax, [esp + 0x28] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x10], edx */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x20], eax */
    c->df = 0; /* cld  */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov edi, dword ptr [esp + 0x20] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)((uint32_t)0x10u); /* mov ecx, 0x10 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov ebx, dword ptr [esp + 0x24] */
L_00b932a3:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x88u))); /* mov ecx, dword ptr [ebx + 0x88] */
    c->edx = (uint32_t)(R32((uint32_t)(0xb9c060u))); /* mov edx, dword ptr [0x1000c060] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov esi, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->esi)); PUSH32(c, 0x00b932b4u); call_indirect(c, t_); } /* call dword ptr [esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x88u))); /* mov ecx, dword ptr [ebx + 0x88] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t t_ = R32((uint32_t)(c->esi + 0x8u)); PUSH32(c, 0x00b932c0u); call_indirect(c, t_); } /* call dword ptr [esi + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf != c->of)) goto L_00b93458; /* jl 0xb93458 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x88u))); /* mov ecx, dword ptr [ebx + 0x88] */
    c->esi = (uint32_t)((uint32_t)(c->esp + 0x140u)); /* lea esi, [esp + 0x140] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x10u)); PUSH32(c, 0x00b932dcu); call_indirect(c, t_); } /* call dword ptr [edx + 0x10] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x100u)); /* lea eax, [esp + 0x100] */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x24], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov eax, dword ptr [esp + 0x24] */
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
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x144u)); /* lea ecx, [esp + 0x144] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x28u)); /* lea edx, [esp + 0x28] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x108u)); /* lea ecx, [esp + 0x108] */
    PUSH32(c, 0x00b9333au); f_00b936d0(c); /* call 0xb936d0 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x174u))); /* fld dword ptr [esp + 0x174] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x178u))); /* fld dword ptr [esp + 0x178] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x17cu))); /* fld dword ptr [esp + 0x17c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x48u))); /* fld dword ptr [esp + 0x48] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x38u))); /* fld dword ptr [esp + 0x38] */
    ST(0) = FPRES(c, ST(0) * ST(3)); /* fmul st(3) */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb9ef8cu))); /* mov ecx, dword ptr [0x1000ef8c] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W32((uint32_t)(c->esp + 0x68u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x68], eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x28u))); /* fld dword ptr [esp + 0x28] */
    ST(0) = FPRES(c, ST(0) * ST(4)); /* fmul st(4) */
    W32((uint32_t)(c->esp + 0x6cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x6c], eax */
    W32((uint32_t)(c->esp + 0x70u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x70], esi */
    W32((uint32_t)(c->esp + 0x74u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x74], esi */
    W32((uint32_t)(c->esp + 0x78u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x78], esi */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    W32((uint32_t)(c->esp + 0x7cu), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x7c], esi */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x6cu)); /* lea eax, [esp + 0x6c] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x5cu))); /* fadd dword ptr [esp + 0x5c] */
    { uint32_t v_ = 0xb9c238u; PUSH32(c, v_); } /* push 0x1000c238 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    WF32((uint32_t)(c->esp + 0x20u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x20] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x58u))); /* fld dword ptr [esp + 0x58] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x48u))); /* fld dword ptr [esp + 0x48] */
    ST(0) = FPRES(c, ST(0) * ST(3)); /* fmul st(3) */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x38u))); /* fld dword ptr [esp + 0x38] */
    ST(0) = FPRES(c, ST(0) * ST(4)); /* fmul st(4) */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x68u))); /* fadd dword ptr [esp + 0x68] */
    WF32((uint32_t)(c->esp + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x24] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x5cu))); /* fld dword ptr [esp + 0x5c] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x4cu))); /* fld dword ptr [esp + 0x4c] */
    ST(0) = FPRES(c, ST(0) * ST(3)); /* fmul st(3) */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x3cu))); /* fld dword ptr [esp + 0x3c] */
    ST(0) = FPRES(c, ST(0) * ST(4)); /* fmul st(4) */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x6cu))); /* fadd dword ptr [esp + 0x6c] */
    WF32((uint32_t)(c->esp + 0x28u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x28] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x44u)); PUSH32(c, 0x00b933e1u); call_indirect(c, t_); } /* call dword ptr [edx + 0x44] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x128u))); /* fld dword ptr [esp + 0x128] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9ef8cu))); /* mov eax, dword ptr [0x1000ef8c] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x30u)); /* sub esp, 0x30 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    WF64((uint32_t)(c->esp + 0x28u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x28] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x158u))); /* fld dword ptr [esp + 0x158] */
    WF64((uint32_t)(c->esp + 0x20u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x20] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x154u))); /* fld dword ptr [esp + 0x154] */
    WF64((uint32_t)(c->esp + 0x18u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x18] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x50u))); /* fld dword ptr [esp + 0x50] */
    WF64((uint32_t)(c->esp + 0x10u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x10] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x4cu))); /* fld dword ptr [esp + 0x4c] */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->esi = (uint32_t)((uint32_t)(c->esp + 0x9cu)); /* lea esi, [esp + 0x9c] */
    WF64((uint32_t)(c->esp + 0x8u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x48u))); /* fld dword ptr [esp + 0x48] */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    { uint32_t v_ = 0xb9c230u; PUSH32(c, v_); } /* push 0x1000c230 */
    { uint32_t v_ = 0x2712u; PUSH32(c, v_); } /* push 0x2712 */
    { uint32_t v_ = 0xb9c224u; PUSH32(c, v_); } /* push 0x1000c224 */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x98u)); PUSH32(c, 0x00b9344du); call_indirect(c, t_); } /* call dword ptr [edx + 0x98] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x5cu)); /* add esp, 0x5c */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
L_00b93458:;
    c->eax = (uint32_t)(R32((uint32_t)(0xb9efa4u))); /* mov eax, dword ptr [0x1000efa4] */
    { uint32_t v_ = 0xb9c1f4u; PUSH32(c, v_); } /* push 0x1000c1f4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x00b93468u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
L_00b9346b:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00b93480(CPU *c) { /* FUN_10003480 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov esi, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0xcu)); PUSH32(c, 0x00b9348cu); call_indirect(c, t_); } /* call dword ptr [eax + 0xc] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xffffadf8u)); /* add eax, 0xffffadf8 */
    (void)sub32(c, c->eax, (uint32_t)0xcu); /* cmp eax, 0xc */
    if ((!c->cf && !c->zf)) goto L_00b93554; /* ja 0xb93554 */
    { uint32_t t_ = R32((uint32_t)(c->eax * 4 + 0xb93558u)); switch (t_) { case 0x00b934a1u: goto L_00b934a1; case 0x00b934b2u: goto L_00b934b2; case 0x00b934cdu: goto L_00b934cd; case 0x00b934e0u: goto L_00b934e0; case 0x00b934f1u: goto L_00b934f1; case 0x00b93505u: goto L_00b93505; case 0x00b93519u: goto L_00b93519; case 0x00b93526u: goto L_00b93526; case 0x00b93534u: goto L_00b93534; case 0x00b93543u: goto L_00b93543; case 0x00b93554u: goto L_00b93554; default: jump_indirect(c, t_, 0x00b9349au); return; } } /* jmp dword ptr [eax*4 + 0x10003558] */
L_00b934a1:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b934abu); f_00b92bb0(c); /* call 0xb92bb0 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xffu))); /* and eax, 0xff */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_00b934b2:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb9c044u))); /* mov ecx, dword ptr [0x1000c044] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->eax + 0x984u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x984], ecx */
    W32((uint32_t)(c->eax + 0x7cu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [eax + 0x7c], 0 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_00b934cd:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9c040u))); /* mov eax, dword ptr [0x1000c040] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->edx + 0x984u), (uint32_t)(c->eax)); /* mov dword ptr [edx + 0x984], eax */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_00b934e0:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b934eau); f_00b92d60(c); /* call 0xb92d60 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xffu))); /* and eax, 0xff */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_00b934f1:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(0xb9c05cu))); /* mov edx, dword ptr [0x1000c05c] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->ecx + 0x988u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 0x988], edx */
    c->esp += 4; return; /* ret  */
L_00b93505:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb9c058u))); /* mov ecx, dword ptr [0x1000c058] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->eax + 0x988u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x988], ecx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_00b93519:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    PUSH32(c, 0x00b93522u); f_00b92ee0(c); /* call 0xb92ee0 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_00b93526:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x78u))); /* mov edx, dword ptr [eax + 0x78] */
    W32((uint32_t)(c->eax + 0x7cu), (uint32_t)(c->edx)); /* mov dword ptr [eax + 0x7c], edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_00b93534:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->eax + 0x7cu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [eax + 0x7c], 0 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_00b93543:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x00b9354au); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    W32((uint32_t)(c->ecx + 0x98cu), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 0x98c], eax */
L_00b93554:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b934a1(CPU *c) { /* PTR_00b934a1 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b934abu); f_00b92bb0(c); /* call 0xb92bb0 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xffu))); /* and eax, 0xff */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b934b2(CPU *c) { /* PTR_00b934b2 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb9c044u))); /* mov ecx, dword ptr [0x1000c044] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->eax + 0x984u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x984], ecx */
    W32((uint32_t)(c->eax + 0x7cu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [eax + 0x7c], 0 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_00b934cd(CPU *c) { /* PTR_00b934cd */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9c040u))); /* mov eax, dword ptr [0x1000c040] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->edx + 0x984u), (uint32_t)(c->eax)); /* mov dword ptr [edx + 0x984], eax */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_00b934e0(CPU *c) { /* PTR_00b934e0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b934eau); f_00b92d60(c); /* call 0xb92d60 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xffu))); /* and eax, 0xff */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b934f1(CPU *c) { /* PTR_00b934f1 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(0xb9c05cu))); /* mov edx, dword ptr [0x1000c05c] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->ecx + 0x988u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 0x988], edx */
    c->esp += 4; return; /* ret  */
}

void f_00b93505(CPU *c) { /* PTR_00b93505 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb9c058u))); /* mov ecx, dword ptr [0x1000c058] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->eax + 0x988u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x988], ecx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_00b93519(CPU *c) { /* PTR_00b93519 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    PUSH32(c, 0x00b93522u); f_00b92ee0(c); /* call 0xb92ee0 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b93526(CPU *c) { /* PTR_00b93526 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x78u))); /* mov edx, dword ptr [eax + 0x78] */
    W32((uint32_t)(c->eax + 0x7cu), (uint32_t)(c->edx)); /* mov dword ptr [eax + 0x7c], edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_00b93534(CPU *c) { /* PTR_00b93534 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->eax + 0x7cu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [eax + 0x7c], 0 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_00b93543(CPU *c) { /* PTR_00b93543 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x00b9354au); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    W32((uint32_t)(c->ecx + 0x98cu), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 0x98c], eax */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b93554(CPU *c) { /* PTR_00b93554 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b93590(CPU *c) { /* FUN_10003590 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x8u))); /* fld dword ptr [eax + 8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ecx + 0x8u))); /* fmul dword ptr [ecx + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x4u))); /* fld dword ptr [eax + 4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ecx + 0x4u))); /* fmul dword ptr [ecx + 4] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->eax))); /* fld dword ptr [eax] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ecx))); /* fmul dword ptr [ecx] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    c->esp += 4; return; /* ret  */
}

void f_00b935b0(CPU *c) { /* FUN_100035b0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0xb9b14cu)); /* mov dword ptr [eax], 0x1000b14c */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb9ef88u))); /* mov ecx, dword ptr [0x1000ef88] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x14u))); /* mov eax, dword ptr [eax + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x00b935c7u); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    c->esp += 4; return; /* ret  */
}

void f_00b935d0(CPU *c) { /* PTR_00b935d0 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    c->esp += 4; return; /* ret  */
}

void f_00b935e0(CPU *c) { /* PTR_00b935e0 */
    PREEMPT_POLL(c);
    c->esp += 8; return; /* ret 4 */
}

void f_00b935f0(CPU *c) { /* PTR_00b935f0 */
    PREEMPT_POLL(c);
    c->esp += 16; return; /* ret 0xc */
}

void f_00b93600(CPU *c) { /* PTR_00b93600 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_00b93610(CPU *c) { /* PTR_00b93610 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    c->esp += 8; return; /* ret 4 */
}

void f_00b93620(CPU *c) { /* PTR_00b93620 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 8; return; /* ret 4 */
}

void f_00b93630(CPU *c) { /* FUN_10003630 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x14u))); /* mov edx, dword ptr [esi + 0x14] */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0xb9b14cu)); /* mov dword ptr [esi], 0x1000b14c */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb9ef88u))); /* mov ecx, dword ptr [0x1000ef88] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x00b93648u); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00b93658; /* je 0xb93658 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b93655u); f_00b91050(c); /* call 0xb91050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00b93658:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00b93660(CPU *c) { /* PTR_00b93660 */
    PREEMPT_POLL(c);
    c->esp += 4; return; /* ret  */
}

void f_00b93670(CPU *c) { /* PTR_00b93670 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    c->esp += 4; return; /* ret  */
}

void f_00b93680(CPU *c) { /* PTR_00b93680 */
    PREEMPT_POLL(c);
    { uint32_t a_ = (uint32_t)(c->ecx + 0xcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ecx + 0xc] */
    c->esp += 4; return; /* ret  */
}

void f_00b93690(CPU *c) { /* PTR_00b93690 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov eax, dword ptr [ecx + 0xc] */
    c->esp += 4; return; /* ret  */
}

void f_00b936a0(CPU *c) { /* PTR_00b936a0 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx + 0xcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ecx + 0xc], 0 */
    c->esp += 4; return; /* ret  */
}

void f_00b936b0(CPU *c) { /* PTR_00b936b0 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x4u))); /* mov al, byte ptr [esp + 4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0xb9b108u)); /* mov dword ptr [esi], 0x1000b108 */
    if (c->zf) goto L_00b936ca; /* je 0xb936ca */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b936c7u); f_00b91050(c); /* call 0xb91050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00b936ca:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00b936d0(CPU *c) { /* FUN_100036d0 */
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

void f_00b938f0(CPU *c) { /* FUN_100038f0 */
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
    { uint32_t t_ = c->eax; switch (t_) {  default: jump_indirect(c, t_, 0x00b9391bu); return; } } /* jmp eax */
}

void f_00b9391d(CPU *c) { /* PTR_00b9391d */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 12; return; /* ret 8 */
}

void f_00b93924(CPU *c) { /* FUN_10003924 */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { guest_lock(); { uint32_t t0_ = R32((uint32_t)(c->esp)), t1_ = c->eax; W32((uint32_t)(c->esp), (uint32_t)(t1_)); c->eax = (uint32_t)(t0_); } guest_unlock(); } /* xchg dword ptr [esp], eax */
    { uint32_t t_ = c->eax; switch (t_) {  default: jump_indirect(c, t_, 0x00b93929u); return; } } /* jmp eax */
}

void f_00b9392b(CPU *c) { /* FUN_1000392b */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { guest_lock(); { uint32_t t0_ = R32((uint32_t)(c->esp)), t1_ = c->eax; W32((uint32_t)(c->esp), (uint32_t)(t1_)); c->eax = (uint32_t)(t0_); } guest_unlock(); } /* xchg dword ptr [esp], eax */
    { uint32_t t_ = c->eax; switch (t_) {  default: jump_indirect(c, t_, 0x00b93930u); return; } } /* jmp eax */
}

void f_00b93932(CPU *c) { /* FUN_10003932 */
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
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0xb9395au)); /* mov dword ptr [ebp - 4], 0x1000395a */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00b9395au); f_00b9a7d4(c); /* call 0xb9a7d4 */
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

void f_00b9395a(CPU *c) { /* PTR_00b9395a */
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

void f_00b93981(CPU *c) { /* FUN_10003981 */
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
    PUSH32(c, 0x00b939a7u); f_00b94024(c); /* call 0xb94024 */
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

void f_00b939b7(CPU *c) { /* FUN_100039b7 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x14u)); /* sub esp, 0x14 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffecu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x14], 0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)((uint32_t)0xb93a0bu)); /* mov dword ptr [ebp - 0x10], 0x10003a0b */
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
    PUSH32(c, 0x00b939fcu); f_00b94840(c); /* call 0xb94840 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->eax)); /* mov dword ptr fs:[0], eax */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b93a0b(CPU *c) { /* FUN_10003a0b */
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
    PUSH32(c, 0x00b93a2bu); f_00b94024(c); /* call 0xb94024 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00b93a30(CPU *c) { /* FUN_10003a30 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x34u)); /* sub esp, 0x34 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffd8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x28], 0 */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)((uint32_t)0xb93ae6u)); /* mov dword ptr [ebp - 0x24], 0x10003ae6 */
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
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)((uint32_t)0xb93ab8u)); /* mov dword ptr [ebp - 0x10], 0x10003ab8 */
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
    PUSH32(c, 0x00b93aafu); f_00b94911(c); /* call 0xb94911 */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x68u)); PUSH32(c, 0x00b93ab2u); call_indirect(c, t_); } /* call dword ptr [eax + 0x68] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffccu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x34], 0 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if (c->zf) goto L_00b93ad5; /* je 0xb93ad5 */
    c->ebx = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov ebx, dword ptr fs:[0] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ebx, dword ptr [ebp - 0x28] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ebx)); /* mov dword ptr fs:[0], ebx */
    goto L_00b93ade; /* jmp 0xb93ade */
L_00b93ad5:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->eax)); /* mov dword ptr fs:[0], eax */
L_00b93ade:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffccu))); /* mov eax, dword ptr [ebp - 0x34] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b93ab8(CPU *c) { /* PTR_00b93ab8 */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if (c->zf) goto L_00b93ad5; /* je 0xb93ad5 */
    c->ebx = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov ebx, dword ptr fs:[0] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ebx, dword ptr [ebp - 0x28] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ebx)); /* mov dword ptr fs:[0], ebx */
    goto L_00b93ade; /* jmp 0xb93ade */
L_00b93ad5:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->eax)); /* mov dword ptr fs:[0], eax */
L_00b93ade:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffccu))); /* mov eax, dword ptr [ebp - 0x34] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b93ae6(CPU *c) { /* FUN_10003ae6 */
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
    if (c->zf) goto L_00b93b09; /* je 0xb93b09 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->eax + 0x24u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [eax + 0x24], 1 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_00b93b56; /* jmp 0xb93b56 */
L_00b93b09:;
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
    PUSH32(c, 0x00b93b30u); f_00b94024(c); /* call 0xb94024 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x24u)), (uint32_t)0x0u); /* cmp dword ptr [eax + 0x24], 0 */
    if (!c->zf) goto L_00b93b47; /* jne 0xb93b47 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x00b93b47u); f_00b93932(c); /* call 0xb93932 */
L_00b93b47:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ebx, dword ptr [ebp + 0xc] */
    c->esp = (uint32_t)(R32((uint32_t)(c->ebx + 0x1cu))); /* mov esp, dword ptr [ebx + 0x1c] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ebx + 0x20u))); /* mov ebp, dword ptr [ebx + 0x20] */
    { uint32_t t_ = R32((uint32_t)(c->ebx + 0x18u)); switch (t_) {  default: jump_indirect(c, t_, 0x00b93b50u); return; } } /* jmp dword ptr [ebx + 0x18] */
L_00b93b56:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00b93b5b(CPU *c) { /* FUN_10003b5b */
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
    if ((c->sf != c->of)) goto L_00b93bb2; /* jl 0xb93bb2 */
L_00b93b79:;
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (!c->zf) goto L_00b93b83; /* jne 0xb93b83 */
    PUSH32(c, 0x00b93b83u); f_00b94a79(c); /* call 0xb94a79 */
L_00b93b83:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi * 4)); /* lea eax, [esi + esi*4] */
    (void)sub32(c, R32((uint32_t)(c->ebx + c->eax * 4 + 0x4u)), c->ecx); /* cmp dword ptr [ebx + eax*4 + 4], ecx */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->eax * 4)); /* lea eax, [ebx + eax*4] */
    if ((c->sf == c->of)) goto L_00b93b98; /* jge 0xb93b98 */
    (void)sub32(c, c->ecx, R32((uint32_t)(c->eax + 0x8u))); /* cmp ecx, dword ptr [eax + 8] */
    if ((c->zf || c->sf != c->of)) goto L_00b93b9d; /* jle 0xb93b9d */
L_00b93b98:;
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (!c->zf) goto L_00b93ba9; /* jne 0xb93ba9 */
L_00b93b9d:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
L_00b93ba9:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    if ((c->sf == c->of)) goto L_00b93b79; /* jge 0xb93b79 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
L_00b93bb2:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov ecx, dword ptr [ebp + 0x14] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    W32((uint32_t)(c->ecx), (uint32_t)(c->esi)); /* mov dword ptr [ecx], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov ecx, dword ptr [ebp + 0x18] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    (void)sub32(c, c->eax, R32((uint32_t)(c->edi + 0xcu))); /* cmp eax, dword ptr [edi + 0xc] */
    if ((!c->cf && !c->zf)) goto L_00b93bc6; /* ja 0xb93bc6 */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if ((c->cf || c->zf)) goto L_00b93bcb; /* jbe 0xb93bcb */
L_00b93bc6:;
    PUSH32(c, 0x00b93bcbu); f_00b94a79(c); /* call 0xb94a79 */
L_00b93bcb:;
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi * 4)); /* lea eax, [esi + esi*4] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->eax * 4)); /* lea eax, [ebx + eax*4] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b93bd8(CPU *c) { /* __global_unwind2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0xb93bf0u; PUSH32(c, v_); } /* push 0x10003bf0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00b93bf0u); f_00b9a7d4(c); /* call 0xb9a7d4 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00b93bf0(CPU *c) { /* PTR_00b93bf0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00b93bf8(CPU *c) { /* PTR_00b93bf8 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->ecx + 0x4u)) & (uint32_t)0x6u)); /* test dword ptr [ecx + 4], 6 */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    if (c->zf) goto L_00b93c19; /* je 0xb93c19 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    W32((uint32_t)(c->edx), (uint32_t)(c->eax)); /* mov dword ptr [edx], eax */
    c->eax = (uint32_t)((uint32_t)0x3u); /* mov eax, 3 */
L_00b93c19:;
    c->esp += 4; return; /* ret  */
}

void f_00b93c1a(CPU *c) { /* __local_unwind2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0xfffffffeu; PUSH32(c, v_); } /* push -2 */
    { uint32_t v_ = 0xb93bf8u; PUSH32(c, v_); } /* push 0x10003bf8 */
    { uint32_t v_ = R32((uint32_t)(0x0u + c->fs_base)); PUSH32(c, v_); } /* push dword ptr fs:[0] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
L_00b93c37:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov eax, dword ptr [esp + 0x20] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ebx, dword ptr [eax + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + 0xcu))); /* mov esi, dword ptr [eax + 0xc] */
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (c->zf) goto L_00b93c74; /* je 0xb93c74 */
    (void)sub32(c, c->esi, R32((uint32_t)(c->esp + 0x24u))); /* cmp esi, dword ptr [esp + 0x24] */
    if (c->zf) goto L_00b93c74; /* je 0xb93c74 */
    c->esi = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea esi, [esi + esi*2] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + c->esi * 4))); /* mov ecx, dword ptr [ebx + esi*4] */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 8], ecx */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0xc], ecx */
    (void)sub32(c, R32((uint32_t)(c->ebx + c->esi * 4 + 0x4u)), (uint32_t)0x0u); /* cmp dword ptr [ebx + esi*4 + 4], 0 */
    if (!c->zf) goto L_00b93c72; /* jne 0xb93c72 */
    { uint32_t v_ = 0x101u; PUSH32(c, v_); } /* push 0x101 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + c->esi * 4 + 0x8u))); /* mov eax, dword ptr [ebx + esi*4 + 8] */
    PUSH32(c, 0x00b93c6eu); f_00b93cae(c); /* call 0xb93cae */
    { uint32_t t_ = R32((uint32_t)(c->ebx + c->esi * 4 + 0x8u)); PUSH32(c, 0x00b93c72u); call_indirect(c, t_); } /* call dword ptr [ebx + esi*4 + 8] */
L_00b93c72:;
    goto L_00b93c37; /* jmp 0xb93c37 */
L_00b93c74:;
    { uint32_t v_ = R32(c->esp); c->esp += 4; W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(v_)); } /* pop dword ptr fs:[0] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00b93c82(CPU *c) { /* __abnormal_termination */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov ecx, dword ptr fs:[0] */
    (void)sub32(c, R32((uint32_t)(c->ecx + 0x4u)), (uint32_t)0xb93bf8u); /* cmp dword ptr [ecx + 4], 0x10003bf8 */
    if (!c->zf) goto L_00b93ca4; /* jne 0xb93ca4 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov edx, dword ptr [ecx + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edx + 0xcu))); /* mov edx, dword ptr [edx + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->ecx + 0x8u)), c->edx); /* cmp dword ptr [ecx + 8], edx */
    if (!c->zf) goto L_00b93ca4; /* jne 0xb93ca4 */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
L_00b93ca4:;
    c->esp += 4; return; /* ret  */
}

void f_00b93ca5(CPU *c) { /* __NLG_Notify1 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ebx = (uint32_t)((uint32_t)0xb9c244u); /* mov ebx, 0x1000c244 */
    { f_00b93cb8(c); return; } /* jmp 0xb93cb8 */
}

void f_00b93cae(CPU *c) { /* FUN_10003cae */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ebx = (uint32_t)((uint32_t)0xb9c244u); /* mov ebx, 0x1000c244 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebx + 8], ecx */
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 4], eax */
    W32((uint32_t)(c->ebx + 0xcu), (uint32_t)(c->ebp)); /* mov dword ptr [ebx + 0xc], ebp */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
}

void f_00b93cb8(CPU *c) { /* PTR_00b93cb8 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebx + 8], ecx */
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 4], eax */
    W32((uint32_t)(c->ebx + 0xcu), (uint32_t)(c->ebp)); /* mov dword ptr [ebx + 0xc], ebp */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
}

void f_00b93cc6(CPU *c) { /* PTR_00b93cc6 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b93cccu); f_00b94bc1(c); /* call 0xb94bc1 */
    { uint32_t v_ = R32((uint32_t)(0xb9f690u)); PUSH32(c, v_); } /* push dword ptr [0x1000f690] */
    PUSH32(c, 0x00b93cd7u); f_00b94f1c(c); /* call 0xb94f1c */
    c->edx = (uint32_t)(R32((uint32_t)(0xb9f690u))); /* mov edx, dword ptr [0x1000f690] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb9f68cu))); /* mov ecx, dword ptr [0x1000f68c] */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->esi = (uint32_t)(sub32(c, c->esi, c->edx)); /* sub esi, edx */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (!c->cf) goto L_00b93d2c; /* jae 0xb93d2c */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00b93cf5u); f_00b94f1c(c); /* call 0xb94f1c */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x10u)); /* add eax, 0x10 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(0xb9f690u)); PUSH32(c, v_); } /* push dword ptr [0x1000f690] */
    PUSH32(c, 0x00b93d04u); f_00b94bed(c); /* call 0xb94bed */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b93d0f; /* jne 0xb93d0f */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    goto L_00b93d3b; /* jmp 0xb93d3b */
L_00b93d0f:;
    c->ecx = (uint32_t)(R32((uint32_t)(0xb9f68cu))); /* mov ecx, dword ptr [0x1000f68c] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, R32((uint32_t)(0xb9f690u)))); /* sub ecx, dword ptr [0x1000f690] */
    W32((uint32_t)(0xb9f690u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000f690], eax */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 2)); /* sar ecx, 2 */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->ecx * 4)); /* lea ecx, [eax + ecx*4] */
    W32((uint32_t)(0xb9f68cu), (uint32_t)(c->ecx)); /* mov dword ptr [0x1000f68c], ecx */
L_00b93d2c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    { uint32_t a_ = (uint32_t)(0xb9f68cu); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x4u))); } /* add dword ptr [0x1000f68c], 4 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_00b93d3b:;
    PUSH32(c, 0x00b93d40u); f_00b94bca(c); /* call 0xb94bca */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b93d44(CPU *c) { /* PTR_00b93d44 */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    PUSH32(c, 0x00b93d4du); f_00b93cc6(c); /* call 0xb93cc6 */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->esp += 4; return; /* ret  */
}

void f_00b93d56(CPU *c) { /* PTR_00b93d56 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x80u; PUSH32(c, v_); } /* push 0x80 */
    PUSH32(c, 0x00b93d60u); f_00b9500a(c); /* call 0xb9500a */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(0xb9f690u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000f690], eax */
    if (!c->zf) goto L_00b93d77; /* jne 0xb93d77 */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    PUSH32(c, 0x00b93d71u); f_00b93ff1(c); /* call 0xb93ff1 */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9f690u))); /* mov eax, dword ptr [0x1000f690] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b93d77:;
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [eax], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9f690u))); /* mov eax, dword ptr [0x1000f690] */
    W32((uint32_t)(0xb9f68cu), (uint32_t)(c->eax)); /* mov dword ptr [0x1000f68c], eax */
    c->esp += 4; return; /* ret  */
}

void f_00b93d85(CPU *c) { /* FUN_10003d85 */
    PREEMPT_POLL(c);
    PUSH32(c, 0x00b93d8au); f_00b93d9d(c); /* call 0xb93d9d */
    PUSH32(c, 0x00b93d8fu); f_00b95194(c); /* call 0xb95194 */
    W32((uint32_t)(0xb9efb4u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000efb4], eax */
    PUSH32(c, 0x00b93d99u); f_00b95144(c); /* call 0xb95144 */
    c->fpu_sw &= 0x7f00; /* fnclex  */
    c->esp += 4; return; /* ret  */
}

void f_00b93d9c(CPU *c) { /* PTR_00b93d9c */
    PREEMPT_POLL(c);
    c->esp += 4; return; /* ret  */
}

void f_00b93d9d(CPU *c) { /* FUN_10003d9d */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb9556du); /* mov eax, 0x1000556d */
    W32((uint32_t)(0xb9c29cu), (uint32_t)((uint32_t)0xb95217u)); /* mov dword ptr [0x1000c29c], 0x10005217 */
    W32((uint32_t)(0xb9c298u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000c298], eax */
    W32((uint32_t)(0xb9c2a0u), (uint32_t)((uint32_t)0xb9527du)); /* mov dword ptr [0x1000c2a0], 0x1000527d */
    W32((uint32_t)(0xb9c2a4u), (uint32_t)((uint32_t)0xb951bdu)); /* mov dword ptr [0x1000c2a4], 0x100051bd */
    W32((uint32_t)(0xb9c2a8u), (uint32_t)((uint32_t)0xb95265u)); /* mov dword ptr [0x1000c2a8], 0x10005265 */
    W32((uint32_t)(0xb9c2acu), (uint32_t)(c->eax)); /* mov dword ptr [0x1000c2ac], eax */
    c->esp += 4; return; /* ret  */
}

void f_00b93dd5(CPU *c) { /* FUN_10003dd5 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = 0x1bu; PUSH32(c, v_); } /* push 0x1b */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0xb9b17cu)); /* mov dword ptr [esi], 0x1000b17c */
    PUSH32(c, 0x00b93de5u); f_00b95678(c); /* call 0xb95678 */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov esi, dword ptr [esi + 4] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00b93df4; /* je 0xb93df4 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b93df3u); f_00b956ee(c); /* call 0xb956ee */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b93df4:;
    { uint32_t v_ = 0x1bu; PUSH32(c, v_); } /* push 0x1b */
    PUSH32(c, 0x00b93dfbu); f_00b956d9(c); /* call 0xb956d9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b93dfe(CPU *c) { /* type_info::vfunc_0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00b93e06u); f_00b93dd5(c); /* call 0xb93dd5 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00b93e14; /* je 0xb93e14 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b93e13u); f_00b91050(c); /* call 0xb91050 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b93e14:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00b93e1a(CPU *c) { /* __CxxThrowException@8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x20u)); /* sub esp, 0x20 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esi = (uint32_t)((uint32_t)0xb9b180u); /* mov esi, 0x1000b180 */
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
    { uint32_t t_ = R32((uint32_t)(0xb9b004u)); PUSH32(c, 0x00b93e4eu); call_indirect(c, t_); } /* call dword ptr [0x1000b004] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 12; return; /* ret 8 */
}

void f_00b93e54(CPU *c) { /* __ftol */
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

void f_00b93e7b(CPU *c) { /* FUN_10003e7b */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_00b93f10; /* jne 0xb93f10 */
    { uint32_t t_ = R32((uint32_t)(0xb9b00cu)); PUSH32(c, 0x00b93e8eu); call_indirect(c, t_); } /* call dword ptr [0x1000b00c] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    W32((uint32_t)(0xb9efd0u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000efd0], eax */
    PUSH32(c, 0x00b93e9au); f_00b96085(c); /* call 0xb96085 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00b93edb; /* je 0xb93edb */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9efd0u))); /* mov eax, dword ptr [0x1000efd0] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0xb9efd1u))); /* mov cl, byte ptr [0x1000efd1] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xffu))); /* and eax, 0xff */
    { uint32_t a_ = (uint32_t)(0xb9efd0u); W32(a_, (uint32_t)(shr32(c, R32(a_), 16))); } /* shr dword ptr [0x1000efd0], 0x10 */
    W32((uint32_t)(0xb9efd8u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000efd8], eax */
    W32((uint32_t)(0xb9efdcu), (uint32_t)(c->ecx)); /* mov dword ptr [0x1000efdc], ecx */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    W32((uint32_t)(0xb9efd4u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000efd4], eax */
    PUSH32(c, 0x00b93ed2u); f_00b9488c(c); /* call 0xb9488c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b93edf; /* jne 0xb93edf */
    PUSH32(c, 0x00b93edbu); f_00b960e2(c); /* call 0xb960e2 */
L_00b93edb:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00b93f51; /* jmp 0xb93f51 */
L_00b93edf:;
    { uint32_t t_ = R32((uint32_t)(0xb9b008u)); PUSH32(c, 0x00b93ee5u); call_indirect(c, t_); } /* call dword ptr [0x1000b008] */
    W32((uint32_t)(0xb9f694u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000f694], eax */
    PUSH32(c, 0x00b93eefu); f_00b95dde(c); /* call 0xb95dde */
    W32((uint32_t)(0xb9efbcu), (uint32_t)(c->eax)); /* mov dword ptr [0x1000efbc], eax */
    PUSH32(c, 0x00b93ef9u); f_00b958c8(c); /* call 0xb958c8 */
    PUSH32(c, 0x00b93efeu); f_00b95b91(c); /* call 0xb95b91 */
    PUSH32(c, 0x00b93f03u); f_00b95ad8(c); /* call 0xb95ad8 */
    PUSH32(c, 0x00b93f08u); f_00b94acf(c); /* call 0xb94acf */
    { uint32_t a_ = (uint32_t)(0xb9efb8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [0x1000efb8] */
    goto L_00b93f4e; /* jmp 0xb93f4e */
L_00b93f10:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->zf) goto L_00b93f42; /* jne 0xb93f42 */
    (void)sub32(c, R32((uint32_t)(0xb9efb8u)), c->ecx); /* cmp dword ptr [0x1000efb8], ecx */
    if ((c->zf || c->sf != c->of)) goto L_00b93edb; /* jle 0xb93edb */
    { uint32_t a_ = (uint32_t)(0xb9efb8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [0x1000efb8] */
    (void)sub32(c, R32((uint32_t)(0xb9f008u)), c->ecx); /* cmp dword ptr [0x1000f008], ecx */
    if (!c->zf) goto L_00b93f31; /* jne 0xb93f31 */
    PUSH32(c, 0x00b93f31u); f_00b94b0d(c); /* call 0xb94b0d */
L_00b93f31:;
    PUSH32(c, 0x00b93f36u); f_00b95a84(c); /* call 0xb95a84 */
    PUSH32(c, 0x00b93f3bu); f_00b948e0(c); /* call 0xb948e0 */
    PUSH32(c, 0x00b93f40u); f_00b960e2(c); /* call 0xb960e2 */
    goto L_00b93f4e; /* jmp 0xb93f4e */
L_00b93f42:;
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_00b93f4e; /* jne 0xb93f4e */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00b93f4du); f_00b94978(c); /* call 0xb94978 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b93f4e:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00b93f51:;
    c->esp += 16; return; /* ret 0xc */
}

void f_00b93f54(CPU *c) { /* entry */
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
    if (!c->zf) goto L_00b93f70; /* jne 0xb93f70 */
    (void)sub32(c, R32((uint32_t)(0xb9efb8u)), (uint32_t)0x0u); /* cmp dword ptr [0x1000efb8], 0 */
    goto L_00b93f96; /* jmp 0xb93f96 */
L_00b93f70:;
    (void)sub32(c, c->esi, (uint32_t)0x1u); /* cmp esi, 1 */
    if (c->zf) goto L_00b93f7a; /* je 0xb93f7a */
    (void)sub32(c, c->esi, (uint32_t)0x2u); /* cmp esi, 2 */
    if (!c->zf) goto L_00b93f9c; /* jne 0xb93f9c */
L_00b93f7a:;
    c->eax = (uint32_t)(R32((uint32_t)(0xb9f698u))); /* mov eax, dword ptr [0x1000f698] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b93f8c; /* je 0xb93f8c */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00b93f88u); call_indirect(c, t_); } /* call eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b93f98; /* je 0xb93f98 */
L_00b93f8c:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b93f94u); f_00b93e7b(c); /* call 0xb93e7b */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
L_00b93f96:;
    if (!c->zf) goto L_00b93f9c; /* jne 0xb93f9c */
L_00b93f98:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00b93fea; /* jmp 0xb93fea */
L_00b93f9c:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b93fa4u); f_00b9618a(c); /* call 0xb9618a */
    (void)sub32(c, c->esi, (uint32_t)0x1u); /* cmp esi, 1 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0xc], eax */
    if (!c->zf) goto L_00b93fb8; /* jne 0xb93fb8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b93fe7; /* jne 0xb93fe7 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b93fb8u); f_00b93e7b(c); /* call 0xb93e7b */
L_00b93fb8:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00b93fc1; /* je 0xb93fc1 */
    (void)sub32(c, c->esi, (uint32_t)0x3u); /* cmp esi, 3 */
    if (!c->zf) goto L_00b93fe7; /* jne 0xb93fe7 */
L_00b93fc1:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b93fc9u); f_00b93e7b(c); /* call 0xb93e7b */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b93fd0; /* jne 0xb93fd0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->eax)))); } /* and dword ptr [ebp + 0xc], eax */
L_00b93fd0:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    if (c->zf) goto L_00b93fe7; /* je 0xb93fe7 */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9f698u))); /* mov eax, dword ptr [0x1000f698] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b93fe7; /* je 0xb93fe7 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00b93fe4u); call_indirect(c, t_); } /* call eax */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0xc], eax */
L_00b93fe7:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
L_00b93fea:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 16; return; /* ret 0xc */
}

void f_00b93ff1(CPU *c) { /* __amsg_exit */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0xb9efc4u))); /* mov eax, dword ptr [0x1000efc4] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_00b94008; /* je 0xb94008 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b9400d; /* jne 0xb9400d */
    (void)sub32(c, R32((uint32_t)(0xb9efc8u)), (uint32_t)0x1u); /* cmp dword ptr [0x1000efc8], 1 */
    if (!c->zf) goto L_00b9400d; /* jne 0xb9400d */
L_00b94008:;
    PUSH32(c, 0x00b9400du); f_00b96190(c); /* call 0xb96190 */
L_00b9400d:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    PUSH32(c, 0x00b94016u); f_00b961c9(c); /* call 0xb961c9 */
    { uint32_t v_ = 0xffu; PUSH32(c, v_); } /* push 0xff */
    { uint32_t t_ = R32((uint32_t)(0xb9c284u)); PUSH32(c, 0x00b94021u); call_indirect(c, t_); } /* call dword ptr [0x1000c284] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00b94021(CPU *c) { /* PTR_00b94021 */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00b94024(CPU *c) { /* FUN_10004024 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov esi, dword ptr [ebp + 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)((uint32_t)0x19930520u); /* mov edi, 0x19930520 */
    (void)sub32(c, R32((uint32_t)(c->esi)), c->edi); /* cmp dword ptr [esi], edi */
    if (c->zf) goto L_00b9403a; /* je 0xb9403a */
    PUSH32(c, 0x00b9403au); f_00b94a79(c); /* call 0xb94a79 */
L_00b9403a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + 0x4u)) & (uint8_t)0x66u)); /* test byte ptr [eax + 4], 0x66 */
    if (c->zf) goto L_00b94062; /* je 0xb94062 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x4u)), (uint32_t)0x0u); /* cmp dword ptr [esi + 4], 0 */
    if (c->zf) goto L_00b940b8; /* je 0xb940b8 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x1c], 0 */
    if (!c->zf) goto L_00b940b8; /* jne 0xb940b8 */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x00b9405du); f_00b94379(c); /* call 0xb94379 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    goto L_00b940b8; /* jmp 0xb940b8 */
L_00b94062:;
    (void)sub32(c, R32((uint32_t)(c->esi + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [esi + 0xc], 0 */
    if (c->zf) goto L_00b940b8; /* je 0xb940b8 */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xe06d7363u); /* cmp dword ptr [eax], 0xe06d7363 */
    if (!c->zf) goto L_00b9409c; /* jne 0xb9409c */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x14u)), c->edi); /* cmp dword ptr [eax + 0x14], edi */
    if ((c->cf || c->zf)) goto L_00b9409c; /* jbe 0xb9409c */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x1cu))); /* mov ecx, dword ptr [eax + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov ecx, dword ptr [ecx + 8] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00b9409c; /* je 0xb9409c */
    c->edx = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0x24u))); /* movzx edx, byte ptr [ebp + 0x24] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = c->ecx; PUSH32(c, 0x00b94097u); call_indirect(c, t_); } /* call ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    goto L_00b940bb; /* jmp 0xb940bb */
L_00b9409c:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x24u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x24] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b940b5u); f_00b940bf(c); /* call 0xb940bf */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
L_00b940b8:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00b940bb:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00b940bf(CPU *c) { /* FUN_100040bf */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffecu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp - 0x14], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x10], eax */
    if ((c->sf != c->of)) goto L_00b940df; /* jl 0xb940df */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov ecx, dword ptr [ebp + 0x18] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ecx + 0x4u))); /* cmp eax, dword ptr [ecx + 4] */
    if ((c->sf != c->of)) goto L_00b940e4; /* jl 0xb940e4 */
L_00b940df:;
    PUSH32(c, 0x00b940e4u); f_00b94a79(c); /* call 0xb94a79 */
L_00b940e4:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    c->ebx = (uint32_t)((uint32_t)0xe06d7363u); /* mov ebx, 0xe06d7363 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)((uint32_t)0x19930520u); /* mov edi, 0x19930520 */
    (void)sub32(c, R32((uint32_t)(c->esi)), c->ebx); /* cmp dword ptr [esi], ebx */
    if (!c->zf) goto L_00b94247; /* jne 0xb94247 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [esi + 0x10], 3 */
    if (!c->zf) goto L_00b94164; /* jne 0xb94164 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x14u)), c->edi); /* cmp dword ptr [esi + 0x14], edi */
    if (!c->zf) goto L_00b94164; /* jne 0xb94164 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [esi + 0x1c], 0 */
    if (!c->zf) goto L_00b94164; /* jne 0xb94164 */
    PUSH32(c, 0x00b94112u); f_00b94911(c); /* call 0xb94911 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x6cu)), (uint32_t)0x0u); /* cmp dword ptr [eax + 0x6c], 0 */
    if (c->zf) goto L_00b94242; /* je 0xb94242 */
    PUSH32(c, 0x00b94121u); f_00b94911(c); /* call 0xb94911 */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + 0x6cu))); /* mov esi, dword ptr [eax + 0x6c] */
    PUSH32(c, 0x00b94129u); f_00b94911(c); /* call 0xb94911 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x70u))); /* mov eax, dword ptr [eax + 0x70] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x10], eax */
    W8((uint32_t)(c->ebp + 0xffffffecu), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ebp - 0x14], 1 */
    PUSH32(c, 0x00b9413bu); f_00b9631c(c); /* call 0xb9631c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00b94146; /* jne 0xb94146 */
    PUSH32(c, 0x00b94146u); f_00b94a79(c); /* call 0xb94a79 */
L_00b94146:;
    (void)sub32(c, R32((uint32_t)(c->esi)), c->ebx); /* cmp dword ptr [esi], ebx */
    if (!c->zf) goto L_00b94247; /* jne 0xb94247 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [esi + 0x10], 3 */
    if (!c->zf) goto L_00b94164; /* jne 0xb94164 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x14u)), c->edi); /* cmp dword ptr [esi + 0x14], edi */
    if (!c->zf) goto L_00b94164; /* jne 0xb94164 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [esi + 0x1c], 0 */
    if (!c->zf) goto L_00b94164; /* jne 0xb94164 */
    PUSH32(c, 0x00b94164u); f_00b94a79(c); /* call 0xb94a79 */
L_00b94164:;
    (void)sub32(c, R32((uint32_t)(c->esi)), c->ebx); /* cmp dword ptr [esi], ebx */
    if (!c->zf) goto L_00b94247; /* jne 0xb94247 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [esi + 0x10], 3 */
    if (!c->zf) goto L_00b94247; /* jne 0xb94247 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x14u)), c->edi); /* cmp dword ptr [esi + 0x14], edi */
    if (!c->zf) goto L_00b94247; /* jne 0xb94247 */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov edi, dword ptr [ebp - 0x10] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe8u)); /* lea eax, [ebp - 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    PUSH32(c, 0x00b94196u); f_00b93b5b(c); /* call 0xb93b5b */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
L_00b9419b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xffffffe8u))); /* cmp eax, dword ptr [ebp - 0x18] */
    if (!c->cf) goto L_00b94232; /* jae 0xb94232 */
    (void)sub32(c, R32((uint32_t)(c->ebx)), c->edi); /* cmp dword ptr [ebx], edi */
    if ((!c->zf && c->sf == c->of)) goto L_00b94227; /* jg 0xb94227 */
    (void)sub32(c, c->edi, R32((uint32_t)(c->ebx + 0x4u))); /* cmp edi, dword ptr [ebx + 4] */
    if ((!c->zf && c->sf == c->of)) goto L_00b94227; /* jg 0xb94227 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x10u))); /* mov eax, dword ptr [ebx + 0x10] */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xcu))); /* mov eax, dword ptr [ebx + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    if ((c->zf || c->sf != c->of)) goto L_00b94224; /* jle 0xb94224 */
L_00b941c0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x1cu))); /* mov eax, dword ptr [esi + 0x1c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0xcu))); /* mov eax, dword ptr [eax + 0xc] */
    c->edi = (uint32_t)((uint32_t)(c->eax + 0x4u)); /* lea edi, [eax + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    if ((c->zf || c->sf != c->of)) goto L_00b941f1; /* jle 0xb941f1 */
L_00b941d2:;
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [esi + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->edi)); PUSH32(c, v_); } /* push dword ptr [edi] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00b941dfu); f_00b9431c(c); /* call 0xb9431c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b94200; /* jne 0xb94200 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 8] */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff8u)), c->eax); /* cmp dword ptr [ebp - 8], eax */
    if ((!c->zf && c->sf == c->of)) goto L_00b941d2; /* jg 0xb941d2 */
L_00b941f1:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff4u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x10u))); } /* add dword ptr [ebp + 8], 0x10 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0xc], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_00b941c0; /* jg 0xb941c0 */
    goto L_00b94224; /* jmp 0xb94224 */
L_00b94200:;
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
    PUSH32(c, 0x00b94221u); f_00b9442d(c); /* call 0xb9442d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
L_00b94224:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov edi, dword ptr [ebp - 0x10] */
L_00b94227:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x14u)); /* add ebx, 0x14 */
    goto L_00b9419b; /* jmp 0xb9419b */
L_00b94232:;
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x1cu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0x1c], 0 */
    if (c->zf) goto L_00b94242; /* je 0xb94242 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b94240u); f_00b947b1(c); /* call 0xb947b1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b94242:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b94247:;
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x1cu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0x1c], 0 */
    if (!c->zf) goto L_00b9426d; /* jne 0xb9426d */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x24u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffff0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b94268u); f_00b94272(c); /* call 0xb94272 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    goto L_00b94242; /* jmp 0xb94242 */
L_00b9426d:;
    { f_00b94a18(c); return; } /* jmp 0xb94a18 */
}

void f_00b94272(CPU *c) { /* FUN_10004272 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b9427eu); f_00b94911(c); /* call 0xb94911 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x68u)), (uint32_t)0x0u); /* cmp dword ptr [eax + 0x68], 0 */
    if (c->zf) goto L_00b942a5; /* je 0xb942a5 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x24u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00b9429eu); f_00b93a30(c); /* call 0xb93a30 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b94318; /* jne 0xb94318 */
L_00b942a5:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov edi, dword ptr [ebp + 0x1c] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    PUSH32(c, 0x00b942bcu); f_00b93b5b(c); /* call 0xb93b5b */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_00b942c1:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xfffffff8u))); /* cmp eax, dword ptr [ebp - 8] */
    if (!c->cf) goto L_00b94318; /* jae 0xb94318 */
    (void)sub32(c, c->edi, R32((uint32_t)(c->esi))); /* cmp edi, dword ptr [esi] */
    if ((c->sf != c->of)) goto L_00b94310; /* jl 0xb94310 */
    (void)sub32(c, c->edi, R32((uint32_t)(c->esi + 0x4u))); /* cmp edi, dword ptr [esi + 4] */
    if ((!c->zf && c->sf == c->of)) goto L_00b94310; /* jg 0xb94310 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0xfffffff4u))); /* mov ecx, dword ptr [eax - 0xc] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00b942ea; /* je 0xb942ea */
    (void)sub8(c, R8((uint32_t)(c->ecx + 0x8u)), (uint8_t)0x0u); /* cmp byte ptr [ecx + 8], 0 */
    if (!c->zf) goto L_00b94310; /* jne 0xb94310 */
L_00b942ea:;
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
    PUSH32(c, 0x00b9430du); f_00b9442d(c); /* call 0xb9442d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
L_00b94310:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x14u)); /* add esi, 0x14 */
    goto L_00b942c1; /* jmp 0xb942c1 */
L_00b94318:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b9431c(CPU *c) { /* FUN_1000431c */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edi, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov eax, dword ptr [edi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b94373; /* je 0xb94373 */
    (void)sub8(c, R8((uint32_t)(c->eax + 0x8u)), (uint8_t)0x0u); /* cmp byte ptr [eax + 8], 0 */
    c->edx = (uint32_t)((uint32_t)(c->eax + 0x8u)); /* lea edx, [eax + 8] */
    if (c->zf) goto L_00b94373; /* je 0xb94373 */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (c->zf) goto L_00b9434d; /* je 0xb9434d */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x8u)); /* add ecx, 8 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00b94347u); f_00b957e0(c); /* call 0xb957e0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00b9436f; /* jne 0xb9436f */
L_00b9434d:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi)) & (uint8_t)0x2u)); /* test byte ptr [esi], 2 */
    if (c->zf) goto L_00b94357; /* je 0xb94357 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edi)) & (uint8_t)0x8u)); /* test byte ptr [edi], 8 */
    if (c->zf) goto L_00b9436f; /* je 0xb9436f */
L_00b94357:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    if (c->zf) goto L_00b94366; /* je 0xb94366 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edi)) & (uint8_t)0x1u)); /* test byte ptr [edi], 1 */
    if (c->zf) goto L_00b9436f; /* je 0xb9436f */
L_00b94366:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x2u)); /* test al, 2 */
    if (c->zf) goto L_00b94373; /* je 0xb94373 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edi)) & (uint8_t)0x2u)); /* test byte ptr [edi], 2 */
    if (!c->zf) goto L_00b94373; /* jne 0xb94373 */
L_00b9436f:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00b94376; /* jmp 0xb94376 */
L_00b94373:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00b94376:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b94379(CPU *c) { /* FUN_10004379 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xb9b1a0u; PUSH32(c, v_); } /* push 0x1000b1a0 */
    { uint32_t v_ = 0xb96374u; PUSH32(c, v_); } /* push 0x10006374 */
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
L_00b943ab:;
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0x14u))); /* cmp esi, dword ptr [ebp + 0x14] */
    if (c->zf) goto L_00b94405; /* je 0xb94405 */
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if ((c->zf || c->sf != c->of)) goto L_00b943ba; /* jle 0xb943ba */
    (void)sub32(c, c->esi, R32((uint32_t)(c->edi + 0x4u))); /* cmp esi, dword ptr [edi + 4] */
    if ((c->sf != c->of)) goto L_00b943bf; /* jl 0xb943bf */
L_00b943ba:;
    PUSH32(c, 0x00b943bfu); f_00b94a79(c); /* call 0xb94a79 */
L_00b943bf:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8 + 0x4u))); /* mov eax, dword ptr [eax + esi*8 + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b943da; /* je 0xb943da */
    { uint32_t v_ = 0x103u; PUSH32(c, v_); } /* push 0x103 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b943dau); f_00b94840(c); /* call 0xb94840 */
L_00b943da:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    goto L_00b943fa; /* jmp 0xb943fa */
L_00b943fa:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8))); /* mov esi, dword ptr [eax + esi*8] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x1c], esi */
    goto L_00b943ab; /* jmp 0xb943ab */
L_00b94405:;
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebx + 8], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b943ab(CPU *c) { /* PTR_00b943ab */
    PREEMPT_POLL(c);
L_00b943ab:;
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0x14u))); /* cmp esi, dword ptr [ebp + 0x14] */
    if (c->zf) goto L_00b94405; /* je 0xb94405 */
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if ((c->zf || c->sf != c->of)) goto L_00b943ba; /* jle 0xb943ba */
    (void)sub32(c, c->esi, R32((uint32_t)(c->edi + 0x4u))); /* cmp esi, dword ptr [edi + 4] */
    if ((c->sf != c->of)) goto L_00b943bf; /* jl 0xb943bf */
L_00b943ba:;
    PUSH32(c, 0x00b943bfu); f_00b94a79(c); /* call 0xb94a79 */
L_00b943bf:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8 + 0x4u))); /* mov eax, dword ptr [eax + esi*8 + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b943da; /* je 0xb943da */
    { uint32_t v_ = 0x103u; PUSH32(c, v_); } /* push 0x103 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b943dau); f_00b94840(c); /* call 0xb94840 */
L_00b943da:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    goto L_00b943fa; /* jmp 0xb943fa */
L_00b943fa:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8))); /* mov esi, dword ptr [eax + esi*8] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x1c], esi */
    goto L_00b943ab; /* jmp 0xb943ab */
L_00b94405:;
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebx + 8], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b943e0(CPU *c) { /* PTR_00b943e0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffecu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x14] */
    PUSH32(c, 0x00b943e8u); f_00b94417(c); /* call 0xb94417 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00b943ea(CPU *c) { /* PTR_00b943ea */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edi, dword ptr [ebp + 0x10] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov esi, dword ptr [ebp - 0x1c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8))); /* mov esi, dword ptr [eax + esi*8] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x1c], esi */
    { f_00b943ab(c); return; } /* jmp 0xb943ab */
}

void f_00b94417(CPU *c) { /* FUN_10004417 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xe06d7363u); /* cmp dword ptr [eax], 0xe06d7363 */
    if (c->zf) goto L_00b94428; /* je 0xb94428 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_00b94428:;
    { f_00b94a18(c); return; } /* jmp 0xb94a18 */
}

void f_00b9442d(CPU *c) { /* FUN_1000442d */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x20u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x20], 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov ebx, dword ptr [ebp + 0x1c] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    if (c->zf) goto L_00b9444f; /* je 0xb9444f */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00b9444cu); f_00b945ed(c); /* call 0xb945ed */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_00b9444f:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x2cu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x2c], 0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    if (!c->zf) goto L_00b9445b; /* jne 0xb9445b */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    goto L_00b9445e; /* jmp 0xb9445e */
L_00b9445b:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x2cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x2c] */
L_00b9445e:;
    PUSH32(c, 0x00b94463u); f_00b93932(c); /* call 0xb93932 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x24u))); /* mov esi, dword ptr [ebp + 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b94474u); f_00b94379(c); /* call 0xb94379 */
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
    PUSH32(c, 0x00b94495u); f_00b944a8(c); /* call 0xb944a8 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b944a3; /* je 0xb944a3 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b944a3u); f_00b938f0(c); /* call 0xb938f0 */
L_00b944a3:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00b944a8(CPU *c) { /* FUN_100044a8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xb9b1b0u; PUSH32(c, v_); } /* push 0x1000b1b0 */
    { uint32_t v_ = 0xb96374u; PUSH32(c, v_); } /* push 0x10006374 */
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
    PUSH32(c, 0x00b944e6u); f_00b94911(c); /* call 0xb94911 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x6cu))); /* mov eax, dword ptr [eax + 0x6c] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    PUSH32(c, 0x00b944f1u); f_00b94911(c); /* call 0xb94911 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x70u))); /* mov eax, dword ptr [eax + 0x70] */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    PUSH32(c, 0x00b944fcu); f_00b94911(c); /* call 0xb94911 */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    W32((uint32_t)(c->eax + 0x6cu), (uint32_t)(c->edi)); /* mov dword ptr [eax + 0x6c], edi */
    PUSH32(c, 0x00b94507u); f_00b94911(c); /* call 0xb94911 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    W32((uint32_t)(c->eax + 0x70u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x70], ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b94528u); f_00b939b7(c); /* call 0xb939b7 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x2c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b9453bu); f_00b94575(c); /* call 0xb94575 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd4u))); /* mov eax, dword ptr [ebp - 0x2c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b9453e(CPU *c) { /* PTR_00b9453e */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b9454d(CPU *c) { /* PTR_00b9454d */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffecu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x14] */
    PUSH32(c, 0x00b94555u); f_00b945c3(c); /* call 0xb945c3 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00b94557(CPU *c) { /* PTR_00b94557 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffd4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x2c], 0 */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b94569u); f_00b93c1a(c); /* call 0xb93c1a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { f_00b9453e(c); return; } /* jmp 0xb9453e */
}

void f_00b9456f(CPU *c) { /* PTR_00b9456f */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    { f_00b94575(c); return; }
}

void f_00b94575(CPU *c) { /* FUN_10004575 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    W32((uint32_t)(c->esi + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [esi - 4], eax */
    PUSH32(c, 0x00b94580u); f_00b94911(c); /* call 0xb94911 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov ecx, dword ptr [ebp - 0x1c] */
    W32((uint32_t)(c->eax + 0x6cu), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x6c], ecx */
    PUSH32(c, 0x00b9458bu); f_00b94911(c); /* call 0xb94911 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov ecx, dword ptr [ebp - 0x20] */
    W32((uint32_t)(c->eax + 0x70u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x70], ecx */
    (void)sub32(c, R32((uint32_t)(c->edi)), (uint32_t)0xe06d7363u); /* cmp dword ptr [edi], 0xe06d7363 */
    if (!c->zf) goto L_00b945c2; /* jne 0xb945c2 */
    (void)sub32(c, R32((uint32_t)(c->edi + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [edi + 0x10], 3 */
    if (!c->zf) goto L_00b945c2; /* jne 0xb945c2 */
    (void)sub32(c, R32((uint32_t)(c->edi + 0x14u)), (uint32_t)0x19930520u); /* cmp dword ptr [edi + 0x14], 0x19930520 */
    if (!c->zf) goto L_00b945c2; /* jne 0xb945c2 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00b945c2; /* jne 0xb945c2 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x2c], 0 */
    if (c->zf) goto L_00b945c2; /* je 0xb945c2 */
    PUSH32(c, 0x00b945b9u); f_00b93c82(c); /* call 0xb93c82 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b945c0u); f_00b947b1(c); /* call 0xb947b1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b945c2:;
    c->esp += 4; return; /* ret  */
}

void f_00b945c3(CPU *c) { /* FUN_100045c3 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xe06d7363u); /* cmp dword ptr [eax], 0xe06d7363 */
    if (!c->zf) goto L_00b945ea; /* jne 0xb945ea */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [eax + 0x10], 3 */
    if (!c->zf) goto L_00b945ea; /* jne 0xb945ea */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x14u)), (uint32_t)0x19930520u); /* cmp dword ptr [eax + 0x14], 0x19930520 */
    if (!c->zf) goto L_00b945ea; /* jne 0xb945ea */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [eax + 0x1c], 0 */
    if (!c->zf) goto L_00b945ea; /* jne 0xb945ea */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
L_00b945ea:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_00b945ed(CPU *c) { /* FUN_100045ed */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xb9b1c8u; PUSH32(c, v_); } /* push 0x1000b1c8 */
    { uint32_t v_ = 0xb96374u; PUSH32(c, v_); } /* push 0x10006374 */
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
    if (c->zf) goto L_00b94796; /* je 0xb94796 */
    (void)sub8(c, R8((uint32_t)(c->eax + 0x8u)), (uint8_t)0x0u); /* cmp byte ptr [eax + 8], 0 */
    if (c->zf) goto L_00b94796; /* je 0xb94796 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov eax, dword ptr [ecx + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b94796; /* je 0xb94796 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
    c->edi = (uint32_t)((uint32_t)(c->eax + c->edx + 0xcu)); /* lea edi, [eax + edx + 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ecx)) & (uint8_t)0x8u)); /* test byte ptr [ecx], 8 */
    if (c->zf) goto L_00b9468a; /* je 0xb9468a */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x18] */
    PUSH32(c, 0x00b94653u); f_00b9631c(c); /* call 0xb9631c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b9478d; /* je 0xb9478d */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b94665u); f_00b96338(c); /* call 0xb96338 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b9478d; /* je 0xb9478d */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x18u))); /* mov eax, dword ptr [esi + 0x18] */
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov ecx, dword ptr [ebp + 0x14] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x8u)); /* add ecx, 8 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
L_00b9467b:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b94681u); f_00b94818(c); /* call 0xb94818 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    goto L_00b94792; /* jmp 0xb94792 */
L_00b9468a:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov esi, dword ptr [ebp + 0x14] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi)) & (uint8_t)0x1u)); /* test byte ptr [esi], 1 */
    if (c->zf) goto L_00b946e4; /* je 0xb946e4 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    PUSH32(c, 0x00b9469fu); f_00b9631c(c); /* call 0xb9631c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b9478d; /* je 0xb9478d */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b946b1u); f_00b96338(c); /* call 0xb96338 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b9478d; /* je 0xb9478d */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x14u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b946c7u); f_00b96450(c); /* call 0xb96450 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x14u)), (uint32_t)0x4u); /* cmp dword ptr [esi + 0x14], 4 */
    if (!c->zf) goto L_00b94792; /* jne 0xb94792 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b94792; /* je 0xb94792 */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x8u)); /* add esi, 8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    goto L_00b9467b; /* jmp 0xb9467b */
L_00b946e4:;
    (void)sub32(c, R32((uint32_t)(c->esi + 0x18u)), (uint32_t)0x0u); /* cmp dword ptr [esi + 0x18], 0 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    if (!c->zf) goto L_00b9472c; /* jne 0xb9472c */
    PUSH32(c, 0x00b946f7u); f_00b9631c(c); /* call 0xb9631c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b9478d; /* je 0xb9478d */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b94709u); f_00b96338(c); /* call 0xb96338 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b9478d; /* je 0xb9478d */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x14u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x14] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x8u)); /* add esi, 8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    PUSH32(c, 0x00b9471eu); f_00b94818(c); /* call 0xb94818 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b94727u); f_00b96450(c); /* call 0xb96450 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_00b94792; /* jmp 0xb94792 */
L_00b9472c:;
    PUSH32(c, 0x00b94731u); f_00b9631c(c); /* call 0xb9631c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b9478d; /* je 0xb9478d */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b9473fu); f_00b96338(c); /* call 0xb96338 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b9478d; /* je 0xb9478d */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x18] */
    PUSH32(c, 0x00b9474du); f_00b96354(c); /* call 0xb96354 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b9478d; /* je 0xb9478d */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi)) & (uint8_t)0x4u)); /* test byte ptr [esi], 4 */
    if (c->zf) goto L_00b94773; /* je 0xb94773 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x8u)); /* lea eax, [esi + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    PUSH32(c, 0x00b94765u); f_00b94818(c); /* call 0xb94818 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b94771u); f_00b9392b(c); /* call 0xb9392b */
    goto L_00b94792; /* jmp 0xb94792 */
L_00b94773:;
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x8u)); /* lea eax, [esi + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    PUSH32(c, 0x00b9477fu); f_00b94818(c); /* call 0xb94818 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b9478bu); f_00b93924(c); /* call 0xb93924 */
    goto L_00b94792; /* jmp 0xb94792 */
L_00b9478d:;
    PUSH32(c, 0x00b94792u); f_00b94a79(c); /* call 0xb94a79 */
L_00b94792:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
L_00b94796:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b947a5(CPU *c) { /* PTR_00b947a5 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_00b947a9(CPU *c) { /* PTR_00b947a9 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { f_00b94a18(c); return; } /* jmp 0xb94a18 */
}

void f_00b947b1(CPU *c) { /* FUN_100047b1 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xb9b1d8u; PUSH32(c, v_); } /* push 0x1000b1d8 */
    { uint32_t v_ = 0xb96374u; PUSH32(c, v_); } /* push 0x10006374 */
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
    if (c->zf) goto L_00b947f8; /* je 0xb947f8 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x1cu))); /* mov ecx, dword ptr [eax + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ecx, dword ptr [ecx + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00b947f8; /* je 0xb947f8 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = R32((uint32_t)(c->eax + 0x18u)); PUSH32(c, v_); } /* push dword ptr [eax + 0x18] */
    PUSH32(c, 0x00b947f4u); f_00b93924(c); /* call 0xb93924 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
L_00b947f8:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b94807(CPU *c) { /* PTR_00b94807 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xcu)), ((uint8_t)c->eax)); /* cmp byte ptr [ebp + 0xc], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(!c->zf ? 1 : 0); /* setne al */
    c->esp += 4; return; /* ret  */
}

void f_00b94810(CPU *c) { /* PTR_00b94810 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { f_00b94a18(c); return; } /* jmp 0xb94a18 */
}

void f_00b94818(CPU *c) { /* FUN_10004818 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov edx, dword ptr [ecx + 4] */
    c->eax = (uint32_t)(add32(c, c->eax, c->esi)); /* add eax, esi */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if ((c->sf != c->of)) goto L_00b94839; /* jl 0xb94839 */
    c->esi = (uint32_t)(R32((uint32_t)(c->edx + c->esi))); /* mov esi, dword ptr [edx + esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov ecx, dword ptr [ecx + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + c->ecx))); /* mov ecx, dword ptr [esi + ecx] */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->edx)); /* add ecx, edx */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
L_00b94839:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b94840(CPU *c) { /* __CallSettingFrame@12 */
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
    PUSH32(c, 0x00b94863u); f_00b93ca5(c); /* call 0xb93ca5 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00b94867u); call_indirect(c, t_); } /* call eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->ebx = (uint32_t)(c->ebp); /* mov ebx, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->ebx); /* mov ebp, ebx */
    (void)sub32(c, c->ecx, (uint32_t)0x100u); /* cmp ecx, 0x100 */
    if (!c->zf) goto L_00b9487f; /* jne 0xb9487f */
    c->ecx = (uint32_t)((uint32_t)0x2u); /* mov ecx, 2 */
L_00b9487f:;
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00b94885u); f_00b93ca5(c); /* call 0xb93ca5 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 16; return; /* ret 0xc */
}

void f_00b9488c(CPU *c) { /* FUN_1000488c */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b94892u); f_00b955e3(c); /* call 0xb955e3 */
    { uint32_t t_ = R32((uint32_t)(0xb9b018u)); PUSH32(c, 0x00b94898u); call_indirect(c, t_); } /* call dword ptr [0x1000b018] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    W32((uint32_t)(0xb9c290u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000c290], eax */
    if (c->zf) goto L_00b948dc; /* je 0xb948dc */
    { uint32_t v_ = 0x74u; PUSH32(c, v_); } /* push 0x74 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x00b948abu); f_00b96785(c); /* call 0xb96785 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00b948dc; /* je 0xb948dc */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(0xb9c290u)); PUSH32(c, v_); } /* push dword ptr [0x1000c290] */
    { uint32_t t_ = R32((uint32_t)(0xb9b014u)); PUSH32(c, 0x00b948c0u); call_indirect(c, t_); } /* call dword ptr [0x1000b014] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b948dc; /* je 0xb948dc */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b948cau); f_00b948fe(c); /* call 0xb948fe */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t t_ = R32((uint32_t)(0xb9b010u)); PUSH32(c, 0x00b948d1u); call_indirect(c, t_); } /* call dword ptr [0x1000b010] */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [esi + 4], 0xffffffff */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_00b948dc:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b948e0(CPU *c) { /* FUN_100048e0 */
    PREEMPT_POLL(c);
    PUSH32(c, 0x00b948e5u); f_00b9560c(c); /* call 0xb9560c */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9c290u))); /* mov eax, dword ptr [0x1000c290] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (c->zf) goto L_00b948fd; /* je 0xb948fd */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0xb9b01cu)); PUSH32(c, 0x00b948f6u); call_indirect(c, t_); } /* call dword ptr [0x1000b01c] */
    { uint32_t a_ = (uint32_t)(0xb9c290u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [0x1000c290], 0xffffffff */
L_00b948fd:;
    c->esp += 4; return; /* ret  */
}

void f_00b948fe(CPU *c) { /* FUN_100048fe */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    W32((uint32_t)(c->eax + 0x50u), (uint32_t)((uint32_t)0xb9c430u)); /* mov dword ptr [eax + 0x50], 0x1000c430 */
    W32((uint32_t)(c->eax + 0x14u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [eax + 0x14], 1 */
    c->esp += 4; return; /* ret  */
}

void f_00b94911(CPU *c) { /* FUN_10004911 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0xb9b028u)); PUSH32(c, 0x00b94919u); call_indirect(c, t_); } /* call dword ptr [0x1000b028] */
    { uint32_t v_ = R32((uint32_t)(0xb9c290u)); PUSH32(c, v_); } /* push dword ptr [0x1000c290] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    { uint32_t t_ = R32((uint32_t)(0xb9b024u)); PUSH32(c, 0x00b94927u); call_indirect(c, t_); } /* call dword ptr [0x1000b024] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_00b9496c; /* jne 0xb9496c */
    { uint32_t v_ = 0x74u; PUSH32(c, v_); } /* push 0x74 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x00b94936u); f_00b96785(c); /* call 0xb96785 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00b94964; /* je 0xb94964 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(0xb9c290u)); PUSH32(c, v_); } /* push dword ptr [0x1000c290] */
    { uint32_t t_ = R32((uint32_t)(0xb9b014u)); PUSH32(c, 0x00b9494bu); call_indirect(c, t_); } /* call dword ptr [0x1000b014] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b94964; /* je 0xb94964 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b94955u); f_00b948fe(c); /* call 0xb948fe */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t t_ = R32((uint32_t)(0xb9b010u)); PUSH32(c, 0x00b9495cu); call_indirect(c, t_); } /* call dword ptr [0x1000b010] */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [esi + 4], 0xffffffff */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    goto L_00b9496c; /* jmp 0xb9496c */
L_00b94964:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    PUSH32(c, 0x00b9496bu); f_00b93ff1(c); /* call 0xb93ff1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b9496c:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0xb9b020u)); PUSH32(c, 0x00b94973u); call_indirect(c, t_); } /* call dword ptr [0x1000b020] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b94978(CPU *c) { /* FUN_10004978 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0xb9c290u))); /* mov eax, dword ptr [0x1000c290] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (c->zf) goto L_00b94a17; /* je 0xb94a17 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_00b9499c; /* jne 0xb9499c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0xb9b024u)); PUSH32(c, 0x00b94996u); call_indirect(c, t_); } /* call dword ptr [0x1000b024] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00b94a08; /* je 0xb94a08 */
L_00b9499c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov eax, dword ptr [esi + 0x24] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b949aa; /* je 0xb949aa */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b949a9u); f_00b956ee(c); /* call 0xb956ee */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b949aa:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x28u))); /* mov eax, dword ptr [esi + 0x28] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b949b8; /* je 0xb949b8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b949b7u); f_00b956ee(c); /* call 0xb956ee */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b949b8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x30u))); /* mov eax, dword ptr [esi + 0x30] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b949c6; /* je 0xb949c6 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b949c5u); f_00b956ee(c); /* call 0xb956ee */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b949c6:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x38u))); /* mov eax, dword ptr [esi + 0x38] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b949d4; /* je 0xb949d4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b949d3u); f_00b956ee(c); /* call 0xb956ee */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b949d4:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x40u))); /* mov eax, dword ptr [esi + 0x40] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b949e2; /* je 0xb949e2 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b949e1u); f_00b956ee(c); /* call 0xb956ee */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b949e2:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x44u))); /* mov eax, dword ptr [esi + 0x44] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b949f0; /* je 0xb949f0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b949efu); f_00b956ee(c); /* call 0xb956ee */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b949f0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    (void)sub32(c, c->eax, (uint32_t)0xb9c430u); /* cmp eax, 0x1000c430 */
    if (c->zf) goto L_00b94a01; /* je 0xb94a01 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b94a00u); f_00b956ee(c); /* call 0xb956ee */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b94a01:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b94a07u); f_00b956ee(c); /* call 0xb956ee */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b94a08:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb9c290u)); PUSH32(c, v_); } /* push dword ptr [0x1000c290] */
    { uint32_t t_ = R32((uint32_t)(0xb9b014u)); PUSH32(c, 0x00b94a16u); call_indirect(c, t_); } /* call dword ptr [0x1000b014] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00b94a17:;
    c->esp += 4; return; /* ret  */
}

void f_00b94a18(CPU *c) { /* FUN_10004a18 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xb9b1e8u; PUSH32(c, v_); } /* push 0x1000b1e8 */
    { uint32_t v_ = 0xb96374u; PUSH32(c, v_); } /* push 0x10006374 */
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
    PUSH32(c, 0x00b94a47u); f_00b94911(c); /* call 0xb94911 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x60u)), c->esi); /* cmp dword ptr [eax + 0x60], esi */
    if (c->zf) goto L_00b94a6b; /* je 0xb94a6b */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    PUSH32(c, 0x00b94a58u); f_00b94911(c); /* call 0xb94911 */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x60u)); PUSH32(c, 0x00b94a5bu); call_indirect(c, t_); } /* call dword ptr [eax + 0x60] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 4], esi */
    goto L_00b94a6b; /* jmp 0xb94a6b */
L_00b94a6b:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b94a74u); f_00b94a74(c); /* call 0xb94a74 */
    { f_00b968c2(c); return; } /* jmp 0xb968c2 */
}

void f_00b94a60(CPU *c) { /* PTR_00b94a60 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_00b94a64(CPU *c) { /* PTR_00b94a64 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b94a74u); f_00b94a74(c); /* call 0xb94a74 */
    { f_00b968c2(c); return; } /* jmp 0xb968c2 */
}

void f_00b94a74(CPU *c) { /* PTR_00b94a74 */
    PREEMPT_POLL(c);
    { f_00b968c2(c); return; } /* jmp 0xb968c2 */
}

void f_00b94a79(CPU *c) { /* FUN_10004a79 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xb9b200u; PUSH32(c, v_); } /* push 0x1000b200 */
    { uint32_t v_ = 0xb96374u; PUSH32(c, v_); } /* push 0x10006374 */
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
    c->eax = (uint32_t)(R32((uint32_t)(0xb9c294u))); /* mov eax, dword ptr [0x1000c294] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b94ac1; /* je 0xb94ac1 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00b94ab4u); call_indirect(c, t_); } /* call eax */
    goto L_00b94abd; /* jmp 0xb94abd */
L_00b94abd:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
L_00b94ac1:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b94acau); f_00b94aca(c); /* call 0xb94aca */
    { f_00b94a18(c); return; } /* jmp 0xb94a18 */
}

void f_00b94ab6(CPU *c) { /* PTR_00b94ab6 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_00b94aba(CPU *c) { /* PTR_00b94aba */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b94acau); f_00b94aca(c); /* call 0xb94aca */
    { f_00b94a18(c); return; } /* jmp 0xb94a18 */
}

void f_00b94aca(CPU *c) { /* PTR_00b94aca */
    PREEMPT_POLL(c);
    { f_00b94a18(c); return; } /* jmp 0xb94a18 */
}

void f_00b94acf(CPU *c) { /* FUN_10004acf */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0xb9c25cu))); /* mov eax, dword ptr [0x1000c25c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b94ada; /* je 0xb94ada */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00b94adau); call_indirect(c, t_); } /* call eax */
L_00b94ada:;
    { uint32_t v_ = 0xb9c01cu; PUSH32(c, v_); } /* push 0x1000c01c */
    { uint32_t v_ = 0xb9c00cu; PUSH32(c, v_); } /* push 0x1000c00c */
    PUSH32(c, 0x00b94ae9u); f_00b94bd3(c); /* call 0xb94bd3 */
    { uint32_t v_ = 0xb9c008u; PUSH32(c, v_); } /* push 0x1000c008 */
    { uint32_t v_ = 0xb9c000u; PUSH32(c, v_); } /* push 0x1000c000 */
    PUSH32(c, 0x00b94af8u); f_00b94bd3(c); /* call 0xb94bd3 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_00b94afc(CPU *c) { /* __exit */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    PUSH32(c, 0x00b94b09u); f_00b94b1c(c); /* call 0xb94b1c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b94b0d(CPU *c) { /* FUN_10004b0d */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    PUSH32(c, 0x00b94b18u); f_00b94b1c(c); /* call 0xb94b1c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b94b1c(CPU *c) { /* FUN_10004b1c */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b94b22u); f_00b94bc1(c); /* call 0xb94bc1 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    (void)sub32(c, R32((uint32_t)(0xb9f00cu)), c->edi); /* cmp dword ptr [0x1000f00c], edi */
    if (!c->zf) goto L_00b94b3e; /* jne 0xb94b3e */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    { uint32_t t_ = R32((uint32_t)(0xb9b034u)); PUSH32(c, 0x00b94b37u); call_indirect(c, t_); } /* call dword ptr [0x1000b034] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0xb9b030u)); PUSH32(c, 0x00b94b3eu); call_indirect(c, t_); } /* call dword ptr [0x1000b030] */
L_00b94b3e:;
    (void)sub32(c, R32((uint32_t)(c->esp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [esp + 0xc], 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ebx, dword ptr [esp + 0x14] */
    W32((uint32_t)(0xb9f008u), (uint32_t)(c->edi)); /* mov dword ptr [0x1000f008], edi */
    W8((uint32_t)(0xb9f004u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [0x1000f004], bl */
    if (!c->zf) goto L_00b94b92; /* jne 0xb94b92 */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9f690u))); /* mov eax, dword ptr [0x1000f690] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b94b81; /* je 0xb94b81 */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb9f68cu))); /* mov ecx, dword ptr [0x1000f68c] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)((uint32_t)(c->ecx + 0xfffffffcu)); /* lea esi, [ecx - 4] */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if (c->cf) goto L_00b94b80; /* jb 0xb94b80 */
L_00b94b6d:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b94b75; /* je 0xb94b75 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00b94b75u); call_indirect(c, t_); } /* call eax */
L_00b94b75:;
    c->esi = (uint32_t)(sub32(c, c->esi, (uint32_t)0x4u)); /* sub esi, 4 */
    (void)sub32(c, c->esi, R32((uint32_t)(0xb9f690u))); /* cmp esi, dword ptr [0x1000f690] */
    if (!c->cf) goto L_00b94b6d; /* jae 0xb94b6d */
L_00b94b80:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00b94b81:;
    { uint32_t v_ = 0xb9c024u; PUSH32(c, v_); } /* push 0x1000c024 */
    { uint32_t v_ = 0xb9c020u; PUSH32(c, v_); } /* push 0x1000c020 */
    PUSH32(c, 0x00b94b90u); f_00b94bd3(c); /* call 0xb94bd3 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b94b92:;
    { uint32_t v_ = 0xb9c030u; PUSH32(c, v_); } /* push 0x1000c030 */
    { uint32_t v_ = 0xb9c028u; PUSH32(c, v_); } /* push 0x1000c028 */
    PUSH32(c, 0x00b94ba1u); f_00b94bd3(c); /* call 0xb94bd3 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    if (c->zf) goto L_00b94baf; /* je 0xb94baf */
    PUSH32(c, 0x00b94badu); f_00b94bca(c); /* call 0xb94bca */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_00b94baf:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    W32((uint32_t)(0xb9f00cu), (uint32_t)(c->edi)); /* mov dword ptr [0x1000f00c], edi */
    { uint32_t t_ = R32((uint32_t)(0xb9b02cu)); PUSH32(c, 0x00b94bbfu); call_indirect(c, t_); } /* call dword ptr [0x1000b02c] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00b94bbf(CPU *c) { /* PTR_00b94bbf */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00b94bc1(CPU *c) { /* FUN_10004bc1 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xdu; PUSH32(c, v_); } /* push 0xd */
    PUSH32(c, 0x00b94bc8u); f_00b95678(c); /* call 0xb95678 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00b94bca(CPU *c) { /* FUN_10004bca */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xdu; PUSH32(c, v_); } /* push 0xd */
    PUSH32(c, 0x00b94bd1u); f_00b956d9(c); /* call 0xb956d9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00b94bd3(CPU *c) { /* FUN_10004bd3 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
L_00b94bd8:;
    (void)sub32(c, c->esi, R32((uint32_t)(c->esp + 0xcu))); /* cmp esi, dword ptr [esp + 0xc] */
    if (!c->cf) goto L_00b94beb; /* jae 0xb94beb */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b94be6; /* je 0xb94be6 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00b94be6u); call_indirect(c, t_); } /* call eax */
L_00b94be6:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    goto L_00b94bd8; /* jmp 0xb94bd8 */
L_00b94beb:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b94bed(CPU *c) { /* FUN_10004bed */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xb9b218u; PUSH32(c, v_); } /* push 0x1000b218 */
    { uint32_t v_ = 0xb96374u; PUSH32(c, v_); } /* push 0x10006374 */
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
    if (!c->zf) goto L_00b94c27; /* jne 0xb94c27 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x00b94c21u); f_00b9500a(c); /* call 0xb9500a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00b94f0d; /* jmp 0xb94f0d */
L_00b94c27:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_00b94c3a; /* jne 0xb94c3a */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b94c34u); f_00b956ee(c); /* call 0xb956ee */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00b94f0b; /* jmp 0xb94f0b */
L_00b94c3a:;
    c->eax = (uint32_t)(R32((uint32_t)(0xb9f568u))); /* mov eax, dword ptr [0x1000f568] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_00b94d81; /* jne 0xb94d81 */
L_00b94c48:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00b94d45; /* ja 0xb94d45 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b94c5bu); f_00b95678(c); /* call 0xb95678 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 4], edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b94c65u); f_00b96921(c); /* call 0xb96921 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x28], eax */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (c->zf) goto L_00b94d15; /* je 0xb94d15 */
    (void)sub32(c, c->esi, R32((uint32_t)(0xb9f560u))); /* cmp esi, dword ptr [0x1000f560] */
    if ((!c->cf && !c->zf)) goto L_00b94cc5; /* ja 0xb94cc5 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b94c81u); f_00b9712a(c); /* call 0xb9712a */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b94c8d; /* je 0xb94c8d */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x24], ebx */
    goto L_00b94cc5; /* jmp 0xb94cc5 */
L_00b94c8d:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b94c93u); f_00b96c75(c); /* call 0xb96c75 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (c->zf) goto L_00b94cc5; /* je 0xb94cc5 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xfffffffcu))); /* mov eax, dword ptr [ebx - 4] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00b94ca8; /* jb 0xb94ca8 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00b94ca8:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00b94cb2u); f_00b97b10(c); /* call 0xb97b10 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b94cb8u); f_00b96921(c); /* call 0xb96921 */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x28], eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b94cc2u); f_00b9694c(c); /* call 0xb9694c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00b94cc5:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), c->edi); /* cmp dword ptr [ebp - 0x24], edi */
    if (!c->zf) goto L_00b94d15; /* jne 0xb94d15 */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_00b94cd4; /* jne 0xb94cd4 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_00b94cd4:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0xb9f564u)); PUSH32(c, v_); } /* push dword ptr [0x1000f564] */
    { uint32_t t_ = R32((uint32_t)(0xb9b03cu)); PUSH32(c, 0x00b94cebu); call_indirect(c, t_); } /* call dword ptr [0x1000b03c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (c->zf) goto L_00b94d15; /* je 0xb94d15 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xfffffffcu))); /* mov eax, dword ptr [ebx - 4] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00b94cff; /* jb 0xb94cff */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00b94cff:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00b94d09u); f_00b97b10(c); /* call 0xb97b10 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x28] */
    PUSH32(c, 0x00b94d12u); f_00b9694c(c); /* call 0xb9694c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
L_00b94d15:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b94d1eu); f_00b94d78(c); /* call 0xb94d78 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), c->edi); /* cmp dword ptr [ebp - 0x28], edi */
    if (!c->zf) goto L_00b94d45; /* jne 0xb94d45 */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_00b94d2a; /* jne 0xb94d2a */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00b94d2a:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0xb9f564u)); PUSH32(c, v_); } /* push dword ptr [0x1000f564] */
    { uint32_t t_ = R32((uint32_t)(0xb9b038u)); PUSH32(c, 0x00b94d42u); call_indirect(c, t_); } /* call dword ptr [0x1000b038] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_00b94d45:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_00b94f0d; /* jne 0xb94f0d */
    (void)sub32(c, R32((uint32_t)(0xb9f188u)), c->edi); /* cmp dword ptr [0x1000f188], edi */
    if (c->zf) goto L_00b94f0d; /* je 0xb94f0d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b94d62u); f_00b97aed(c); /* call 0xb97aed */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b94c48; /* jne 0xb94c48 */
    goto L_00b94f0b; /* jmp 0xb94f0b */
L_00b94d81:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00b94ed1; /* jne 0xb94ed1 */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00b94da1; /* ja 0xb94da1 */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if ((c->cf || c->zf)) goto L_00b94d9b; /* jbe 0xb94d9b */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    goto L_00b94d9e; /* jmp 0xb94d9e */
L_00b94d9b:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00b94d9e:;
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_00b94da1:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00b94ea0; /* ja 0xb94ea0 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b94db4u); f_00b95678(c); /* call 0xb95678 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b94dcau); f_00b9767c(c); /* call 0xb9767c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00b94e84; /* je 0xb94e84 */
    (void)sub32(c, c->esi, R32((uint32_t)(0xb9e4dcu))); /* cmp esi, dword ptr [0x1000e4dc] */
    if (!c->cf) goto L_00b94e3e; /* jae 0xb94e3e */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 4)); /* shr ebx, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00b94df4u); f_00b97a44(c); /* call 0xb97a44 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b94e03; /* je 0xb94e03 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_00b94e3b; /* jmp 0xb94e3b */
L_00b94e03:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b94e09u); f_00b97718(c); /* call 0xb97718 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b94e3b; /* je 0xb94e3b */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00b94e20; /* jb 0xb94e20 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00b94e20:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00b94e2cu); f_00b97b10(c); /* call 0xb97b10 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00b94e38u); f_00b976d3(c); /* call 0xb976d3 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00b94e3b:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00b94e3e:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00b94e97; /* jne 0xb94e97 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb9f564u)); PUSH32(c, v_); } /* push dword ptr [0x1000f564] */
    { uint32_t t_ = R32((uint32_t)(0xb9b03cu)); PUSH32(c, 0x00b94e53u); call_indirect(c, t_); } /* call dword ptr [0x1000b03c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b94e97; /* je 0xb94e97 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00b94e69; /* jb 0xb94e69 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00b94e69:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00b94e73u); f_00b97b10(c); /* call 0xb97b10 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00b94e7fu); f_00b976d3(c); /* call 0xb976d3 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00b94e97; /* jmp 0xb94e97 */
L_00b94e84:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb9f564u)); PUSH32(c, v_); } /* push dword ptr [0x1000f564] */
    { uint32_t t_ = R32((uint32_t)(0xb9b038u)); PUSH32(c, 0x00b94e94u); call_indirect(c, t_); } /* call dword ptr [0x1000b038] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_00b94e97:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b94ea0u); f_00b94ec6(c); /* call 0xb94ec6 */
L_00b94ea0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_00b94f0d; /* jne 0xb94f0d */
    (void)sub32(c, R32((uint32_t)(0xb9f188u)), c->edi); /* cmp dword ptr [0x1000f188], edi */
    if (c->zf) goto L_00b94f0d; /* je 0xb94f0d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b94eb5u); f_00b97aed(c); /* call 0xb97aed */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b94da1; /* jne 0xb94da1 */
    goto L_00b94f0b; /* jmp 0xb94f0b */
L_00b94ed1:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00b94ef4; /* ja 0xb94ef4 */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_00b94edf; /* jne 0xb94edf */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00b94edf:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0xb9f564u)); PUSH32(c, v_); } /* push dword ptr [0x1000f564] */
    { uint32_t t_ = R32((uint32_t)(0xb9b038u)); PUSH32(c, 0x00b94ef4u); call_indirect(c, t_); } /* call dword ptr [0x1000b038] */
L_00b94ef4:;
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_00b94f0d; /* jne 0xb94f0d */
    (void)sub32(c, R32((uint32_t)(0xb9f188u)), c->edi); /* cmp dword ptr [0x1000f188], edi */
    if (c->zf) goto L_00b94f0d; /* je 0xb94f0d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b94f06u); f_00b97aed(c); /* call 0xb97aed */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b94ed1; /* jne 0xb94ed1 */
L_00b94f0b:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00b94f0d:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b94d70(CPU *c) { /* PTR_00b94d70 */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    { f_00b94d78(c); return; }
}

void f_00b94d78(CPU *c) { /* FUN_10004d78 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b94d7fu); f_00b956d9(c); /* call 0xb956d9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00b94d81(CPU *c) { /* PTR_00b94d81 */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) { f_00b94ed1(c); return; } /* jne 0xb94ed1 */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00b94da1; /* ja 0xb94da1 */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if ((c->cf || c->zf)) goto L_00b94d9b; /* jbe 0xb94d9b */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    goto L_00b94d9e; /* jmp 0xb94d9e */
L_00b94d9b:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00b94d9e:;
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_00b94da1:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00b94ea0; /* ja 0xb94ea0 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b94db4u); f_00b95678(c); /* call 0xb95678 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b94dcau); f_00b9767c(c); /* call 0xb9767c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00b94e84; /* je 0xb94e84 */
    (void)sub32(c, c->esi, R32((uint32_t)(0xb9e4dcu))); /* cmp esi, dword ptr [0x1000e4dc] */
    if (!c->cf) goto L_00b94e3e; /* jae 0xb94e3e */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 4)); /* shr ebx, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00b94df4u); f_00b97a44(c); /* call 0xb97a44 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b94e03; /* je 0xb94e03 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_00b94e3b; /* jmp 0xb94e3b */
L_00b94e03:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b94e09u); f_00b97718(c); /* call 0xb97718 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b94e3b; /* je 0xb94e3b */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00b94e20; /* jb 0xb94e20 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00b94e20:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00b94e2cu); f_00b97b10(c); /* call 0xb97b10 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00b94e38u); f_00b976d3(c); /* call 0xb976d3 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00b94e3b:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00b94e3e:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00b94e97; /* jne 0xb94e97 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb9f564u)); PUSH32(c, v_); } /* push dword ptr [0x1000f564] */
    { uint32_t t_ = R32((uint32_t)(0xb9b03cu)); PUSH32(c, 0x00b94e53u); call_indirect(c, t_); } /* call dword ptr [0x1000b03c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b94e97; /* je 0xb94e97 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00b94e69; /* jb 0xb94e69 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00b94e69:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00b94e73u); f_00b97b10(c); /* call 0xb97b10 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00b94e7fu); f_00b976d3(c); /* call 0xb976d3 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00b94e97; /* jmp 0xb94e97 */
L_00b94e84:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb9f564u)); PUSH32(c, v_); } /* push dword ptr [0x1000f564] */
    { uint32_t t_ = R32((uint32_t)(0xb9b038u)); PUSH32(c, 0x00b94e94u); call_indirect(c, t_); } /* call dword ptr [0x1000b038] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_00b94e97:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b94ea0u); f_00b94ec6(c); /* call 0xb94ec6 */
L_00b94ea0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00b94f0d(c); return; } /* jne 0xb94f0d */
    (void)sub32(c, R32((uint32_t)(0xb9f188u)), c->edi); /* cmp dword ptr [0x1000f188], edi */
    if (c->zf) { f_00b94f0d(c); return; } /* je 0xb94f0d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b94eb5u); f_00b97aed(c); /* call 0xb97aed */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b94da1; /* jne 0xb94da1 */
    { f_00b94f0b(c); return; } /* jmp 0xb94f0b */
}

void f_00b94d9b(CPU *c) { /* PTR_00b94d9b */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_00b94da1:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00b94ea0; /* ja 0xb94ea0 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b94db4u); f_00b95678(c); /* call 0xb95678 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b94dcau); f_00b9767c(c); /* call 0xb9767c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00b94e84; /* je 0xb94e84 */
    (void)sub32(c, c->esi, R32((uint32_t)(0xb9e4dcu))); /* cmp esi, dword ptr [0x1000e4dc] */
    if (!c->cf) goto L_00b94e3e; /* jae 0xb94e3e */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 4)); /* shr ebx, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00b94df4u); f_00b97a44(c); /* call 0xb97a44 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b94e03; /* je 0xb94e03 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_00b94e3b; /* jmp 0xb94e3b */
L_00b94e03:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b94e09u); f_00b97718(c); /* call 0xb97718 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b94e3b; /* je 0xb94e3b */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00b94e20; /* jb 0xb94e20 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00b94e20:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00b94e2cu); f_00b97b10(c); /* call 0xb97b10 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00b94e38u); f_00b976d3(c); /* call 0xb976d3 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00b94e3b:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00b94e3e:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00b94e97; /* jne 0xb94e97 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb9f564u)); PUSH32(c, v_); } /* push dword ptr [0x1000f564] */
    { uint32_t t_ = R32((uint32_t)(0xb9b03cu)); PUSH32(c, 0x00b94e53u); call_indirect(c, t_); } /* call dword ptr [0x1000b03c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b94e97; /* je 0xb94e97 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00b94e69; /* jb 0xb94e69 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00b94e69:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00b94e73u); f_00b97b10(c); /* call 0xb97b10 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00b94e7fu); f_00b976d3(c); /* call 0xb976d3 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00b94e97; /* jmp 0xb94e97 */
L_00b94e84:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb9f564u)); PUSH32(c, v_); } /* push dword ptr [0x1000f564] */
    { uint32_t t_ = R32((uint32_t)(0xb9b038u)); PUSH32(c, 0x00b94e94u); call_indirect(c, t_); } /* call dword ptr [0x1000b038] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_00b94e97:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b94ea0u); f_00b94ec6(c); /* call 0xb94ec6 */
L_00b94ea0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00b94f0d(c); return; } /* jne 0xb94f0d */
    (void)sub32(c, R32((uint32_t)(0xb9f188u)), c->edi); /* cmp dword ptr [0x1000f188], edi */
    if (c->zf) { f_00b94f0d(c); return; } /* je 0xb94f0d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b94eb5u); f_00b97aed(c); /* call 0xb97aed */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b94da1; /* jne 0xb94da1 */
    { f_00b94f0b(c); return; } /* jmp 0xb94f0b */
}

void f_00b94d9e(CPU *c) { /* PTR_00b94d9e */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_00b94da1:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00b94ea0; /* ja 0xb94ea0 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b94db4u); f_00b95678(c); /* call 0xb95678 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b94dcau); f_00b9767c(c); /* call 0xb9767c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00b94e84; /* je 0xb94e84 */
    (void)sub32(c, c->esi, R32((uint32_t)(0xb9e4dcu))); /* cmp esi, dword ptr [0x1000e4dc] */
    if (!c->cf) goto L_00b94e3e; /* jae 0xb94e3e */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 4)); /* shr ebx, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00b94df4u); f_00b97a44(c); /* call 0xb97a44 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b94e03; /* je 0xb94e03 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_00b94e3b; /* jmp 0xb94e3b */
L_00b94e03:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b94e09u); f_00b97718(c); /* call 0xb97718 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b94e3b; /* je 0xb94e3b */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00b94e20; /* jb 0xb94e20 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00b94e20:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00b94e2cu); f_00b97b10(c); /* call 0xb97b10 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00b94e38u); f_00b976d3(c); /* call 0xb976d3 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00b94e3b:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00b94e3e:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00b94e97; /* jne 0xb94e97 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb9f564u)); PUSH32(c, v_); } /* push dword ptr [0x1000f564] */
    { uint32_t t_ = R32((uint32_t)(0xb9b03cu)); PUSH32(c, 0x00b94e53u); call_indirect(c, t_); } /* call dword ptr [0x1000b03c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b94e97; /* je 0xb94e97 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00b94e69; /* jb 0xb94e69 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00b94e69:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00b94e73u); f_00b97b10(c); /* call 0xb97b10 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00b94e7fu); f_00b976d3(c); /* call 0xb976d3 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00b94e97; /* jmp 0xb94e97 */
L_00b94e84:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb9f564u)); PUSH32(c, v_); } /* push dword ptr [0x1000f564] */
    { uint32_t t_ = R32((uint32_t)(0xb9b038u)); PUSH32(c, 0x00b94e94u); call_indirect(c, t_); } /* call dword ptr [0x1000b038] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_00b94e97:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b94ea0u); f_00b94ec6(c); /* call 0xb94ec6 */
L_00b94ea0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00b94f0d(c); return; } /* jne 0xb94f0d */
    (void)sub32(c, R32((uint32_t)(0xb9f188u)), c->edi); /* cmp dword ptr [0x1000f188], edi */
    if (c->zf) { f_00b94f0d(c); return; } /* je 0xb94f0d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b94eb5u); f_00b97aed(c); /* call 0xb97aed */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b94da1; /* jne 0xb94da1 */
    { f_00b94f0b(c); return; } /* jmp 0xb94f0b */
}

void f_00b94da1(CPU *c) { /* PTR_00b94da1 */
    PREEMPT_POLL(c);
L_00b94da1:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00b94ea0; /* ja 0xb94ea0 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b94db4u); f_00b95678(c); /* call 0xb95678 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b94dcau); f_00b9767c(c); /* call 0xb9767c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00b94e84; /* je 0xb94e84 */
    (void)sub32(c, c->esi, R32((uint32_t)(0xb9e4dcu))); /* cmp esi, dword ptr [0x1000e4dc] */
    if (!c->cf) goto L_00b94e3e; /* jae 0xb94e3e */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 4)); /* shr ebx, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00b94df4u); f_00b97a44(c); /* call 0xb97a44 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b94e03; /* je 0xb94e03 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_00b94e3b; /* jmp 0xb94e3b */
L_00b94e03:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b94e09u); f_00b97718(c); /* call 0xb97718 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b94e3b; /* je 0xb94e3b */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00b94e20; /* jb 0xb94e20 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00b94e20:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00b94e2cu); f_00b97b10(c); /* call 0xb97b10 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00b94e38u); f_00b976d3(c); /* call 0xb976d3 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00b94e3b:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00b94e3e:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00b94e97; /* jne 0xb94e97 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb9f564u)); PUSH32(c, v_); } /* push dword ptr [0x1000f564] */
    { uint32_t t_ = R32((uint32_t)(0xb9b03cu)); PUSH32(c, 0x00b94e53u); call_indirect(c, t_); } /* call dword ptr [0x1000b03c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b94e97; /* je 0xb94e97 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00b94e69; /* jb 0xb94e69 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00b94e69:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00b94e73u); f_00b97b10(c); /* call 0xb97b10 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00b94e7fu); f_00b976d3(c); /* call 0xb976d3 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00b94e97; /* jmp 0xb94e97 */
L_00b94e84:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb9f564u)); PUSH32(c, v_); } /* push dword ptr [0x1000f564] */
    { uint32_t t_ = R32((uint32_t)(0xb9b038u)); PUSH32(c, 0x00b94e94u); call_indirect(c, t_); } /* call dword ptr [0x1000b038] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_00b94e97:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b94ea0u); f_00b94ec6(c); /* call 0xb94ec6 */
L_00b94ea0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00b94f0d(c); return; } /* jne 0xb94f0d */
    (void)sub32(c, R32((uint32_t)(0xb9f188u)), c->edi); /* cmp dword ptr [0x1000f188], edi */
    if (c->zf) { f_00b94f0d(c); return; } /* je 0xb94f0d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b94eb5u); f_00b97aed(c); /* call 0xb97aed */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b94da1; /* jne 0xb94da1 */
    { f_00b94f0b(c); return; } /* jmp 0xb94f0b */
}

void f_00b94e03(CPU *c) { /* PTR_00b94e03 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b94e09u); f_00b97718(c); /* call 0xb97718 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b94e3b; /* je 0xb94e3b */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00b94e20; /* jb 0xb94e20 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00b94e20:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00b94e2cu); f_00b97b10(c); /* call 0xb97b10 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00b94e38u); f_00b976d3(c); /* call 0xb976d3 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00b94e3b:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00b94e97; /* jne 0xb94e97 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb9f564u)); PUSH32(c, v_); } /* push dword ptr [0x1000f564] */
    { uint32_t t_ = R32((uint32_t)(0xb9b03cu)); PUSH32(c, 0x00b94e53u); call_indirect(c, t_); } /* call dword ptr [0x1000b03c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b94e97; /* je 0xb94e97 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00b94e69; /* jb 0xb94e69 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00b94e69:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00b94e73u); f_00b97b10(c); /* call 0xb97b10 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00b94e7fu); f_00b976d3(c); /* call 0xb976d3 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00b94e97; /* jmp 0xb94e97 */
L_00b94e97:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b94ea0u); f_00b94ec6(c); /* call 0xb94ec6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00b94f0d(c); return; } /* jne 0xb94f0d */
    (void)sub32(c, R32((uint32_t)(0xb9f188u)), c->edi); /* cmp dword ptr [0x1000f188], edi */
    if (c->zf) { f_00b94f0d(c); return; } /* je 0xb94f0d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b94eb5u); f_00b97aed(c); /* call 0xb97aed */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00b94da1(c); return; } /* jne 0xb94da1 */
    { f_00b94f0b(c); return; } /* jmp 0xb94f0b */
}

void f_00b94e20(CPU *c) { /* PTR_00b94e20 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00b94e2cu); f_00b97b10(c); /* call 0xb97b10 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00b94e38u); f_00b976d3(c); /* call 0xb976d3 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00b94e97; /* jne 0xb94e97 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb9f564u)); PUSH32(c, v_); } /* push dword ptr [0x1000f564] */
    { uint32_t t_ = R32((uint32_t)(0xb9b03cu)); PUSH32(c, 0x00b94e53u); call_indirect(c, t_); } /* call dword ptr [0x1000b03c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b94e97; /* je 0xb94e97 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00b94e69; /* jb 0xb94e69 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00b94e69:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00b94e73u); f_00b97b10(c); /* call 0xb97b10 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00b94e7fu); f_00b976d3(c); /* call 0xb976d3 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00b94e97; /* jmp 0xb94e97 */
L_00b94e97:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b94ea0u); f_00b94ec6(c); /* call 0xb94ec6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00b94f0d(c); return; } /* jne 0xb94f0d */
    (void)sub32(c, R32((uint32_t)(0xb9f188u)), c->edi); /* cmp dword ptr [0x1000f188], edi */
    if (c->zf) { f_00b94f0d(c); return; } /* je 0xb94f0d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b94eb5u); f_00b97aed(c); /* call 0xb97aed */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00b94da1(c); return; } /* jne 0xb94da1 */
    { f_00b94f0b(c); return; } /* jmp 0xb94f0b */
}

void f_00b94e3b(CPU *c) { /* PTR_00b94e3b */
    PREEMPT_POLL(c);
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00b94e97; /* jne 0xb94e97 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb9f564u)); PUSH32(c, v_); } /* push dword ptr [0x1000f564] */
    { uint32_t t_ = R32((uint32_t)(0xb9b03cu)); PUSH32(c, 0x00b94e53u); call_indirect(c, t_); } /* call dword ptr [0x1000b03c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b94e97; /* je 0xb94e97 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00b94e69; /* jb 0xb94e69 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00b94e69:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00b94e73u); f_00b97b10(c); /* call 0xb97b10 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00b94e7fu); f_00b976d3(c); /* call 0xb976d3 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00b94e97; /* jmp 0xb94e97 */
L_00b94e97:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b94ea0u); f_00b94ec6(c); /* call 0xb94ec6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00b94f0d(c); return; } /* jne 0xb94f0d */
    (void)sub32(c, R32((uint32_t)(0xb9f188u)), c->edi); /* cmp dword ptr [0x1000f188], edi */
    if (c->zf) { f_00b94f0d(c); return; } /* je 0xb94f0d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b94eb5u); f_00b97aed(c); /* call 0xb97aed */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00b94da1(c); return; } /* jne 0xb94da1 */
    { f_00b94f0b(c); return; } /* jmp 0xb94f0b */
}

void f_00b94e3e(CPU *c) { /* PTR_00b94e3e */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00b94e97; /* jne 0xb94e97 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb9f564u)); PUSH32(c, v_); } /* push dword ptr [0x1000f564] */
    { uint32_t t_ = R32((uint32_t)(0xb9b03cu)); PUSH32(c, 0x00b94e53u); call_indirect(c, t_); } /* call dword ptr [0x1000b03c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b94e97; /* je 0xb94e97 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00b94e69; /* jb 0xb94e69 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00b94e69:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00b94e73u); f_00b97b10(c); /* call 0xb97b10 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00b94e7fu); f_00b976d3(c); /* call 0xb976d3 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00b94e97; /* jmp 0xb94e97 */
L_00b94e97:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b94ea0u); f_00b94ec6(c); /* call 0xb94ec6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00b94f0d(c); return; } /* jne 0xb94f0d */
    (void)sub32(c, R32((uint32_t)(0xb9f188u)), c->edi); /* cmp dword ptr [0x1000f188], edi */
    if (c->zf) { f_00b94f0d(c); return; } /* je 0xb94f0d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b94eb5u); f_00b97aed(c); /* call 0xb97aed */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00b94da1(c); return; } /* jne 0xb94da1 */
    { f_00b94f0b(c); return; } /* jmp 0xb94f0b */
}

void f_00b94e69(CPU *c) { /* PTR_00b94e69 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00b94e73u); f_00b97b10(c); /* call 0xb97b10 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00b94e7fu); f_00b976d3(c); /* call 0xb976d3 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00b94e97; /* jmp 0xb94e97 */
L_00b94e97:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b94ea0u); f_00b94ec6(c); /* call 0xb94ec6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00b94f0d(c); return; } /* jne 0xb94f0d */
    (void)sub32(c, R32((uint32_t)(0xb9f188u)), c->edi); /* cmp dword ptr [0x1000f188], edi */
    if (c->zf) { f_00b94f0d(c); return; } /* je 0xb94f0d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b94eb5u); f_00b97aed(c); /* call 0xb97aed */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00b94da1(c); return; } /* jne 0xb94da1 */
    { f_00b94f0b(c); return; } /* jmp 0xb94f0b */
}

void f_00b94e84(CPU *c) { /* PTR_00b94e84 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb9f564u)); PUSH32(c, v_); } /* push dword ptr [0x1000f564] */
    { uint32_t t_ = R32((uint32_t)(0xb9b038u)); PUSH32(c, 0x00b94e94u); call_indirect(c, t_); } /* call dword ptr [0x1000b038] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b94ea0u); f_00b94ec6(c); /* call 0xb94ec6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00b94f0d(c); return; } /* jne 0xb94f0d */
    (void)sub32(c, R32((uint32_t)(0xb9f188u)), c->edi); /* cmp dword ptr [0x1000f188], edi */
    if (c->zf) { f_00b94f0d(c); return; } /* je 0xb94f0d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b94eb5u); f_00b97aed(c); /* call 0xb97aed */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00b94da1(c); return; } /* jne 0xb94da1 */
    { f_00b94f0b(c); return; } /* jmp 0xb94f0b */
}

void f_00b94e97(CPU *c) { /* PTR_00b94e97 */
    PREEMPT_POLL(c);
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b94ea0u); f_00b94ec6(c); /* call 0xb94ec6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00b94f0d(c); return; } /* jne 0xb94f0d */
    (void)sub32(c, R32((uint32_t)(0xb9f188u)), c->edi); /* cmp dword ptr [0x1000f188], edi */
    if (c->zf) { f_00b94f0d(c); return; } /* je 0xb94f0d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b94eb5u); f_00b97aed(c); /* call 0xb97aed */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00b94da1(c); return; } /* jne 0xb94da1 */
    { f_00b94f0b(c); return; } /* jmp 0xb94f0b */
}

void f_00b94ea0(CPU *c) { /* PTR_00b94ea0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00b94f0d(c); return; } /* jne 0xb94f0d */
    (void)sub32(c, R32((uint32_t)(0xb9f188u)), c->edi); /* cmp dword ptr [0x1000f188], edi */
    if (c->zf) { f_00b94f0d(c); return; } /* je 0xb94f0d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b94eb5u); f_00b97aed(c); /* call 0xb97aed */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00b94da1(c); return; } /* jne 0xb94da1 */
    { f_00b94f0b(c); return; } /* jmp 0xb94f0b */
}

void f_00b94ec0(CPU *c) { /* PTR_00b94ec0 */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    { f_00b94ec6(c); return; }
}

void f_00b94ec6(CPU *c) { /* FUN_10004ec6 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b94ecdu); f_00b956d9(c); /* call 0xb956d9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    c->esp += 4; return; /* ret  */
}

void f_00b94ed1(CPU *c) { /* PTR_00b94ed1 */
    PREEMPT_POLL(c);
L_00b94ed1:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00b94ef4; /* ja 0xb94ef4 */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_00b94edf; /* jne 0xb94edf */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00b94edf:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0xb9f564u)); PUSH32(c, v_); } /* push dword ptr [0x1000f564] */
    { uint32_t t_ = R32((uint32_t)(0xb9b038u)); PUSH32(c, 0x00b94ef4u); call_indirect(c, t_); } /* call dword ptr [0x1000b038] */
L_00b94ef4:;
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_00b94f0d; /* jne 0xb94f0d */
    (void)sub32(c, R32((uint32_t)(0xb9f188u)), c->edi); /* cmp dword ptr [0x1000f188], edi */
    if (c->zf) goto L_00b94f0d; /* je 0xb94f0d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b94f06u); f_00b97aed(c); /* call 0xb97aed */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b94ed1; /* jne 0xb94ed1 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00b94f0d:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b94edf(CPU *c) { /* PTR_00b94edf */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0xb9f564u)); PUSH32(c, v_); } /* push dword ptr [0x1000f564] */
    { uint32_t t_ = R32((uint32_t)(0xb9b038u)); PUSH32(c, 0x00b94ef4u); call_indirect(c, t_); } /* call dword ptr [0x1000b038] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_00b94f0d; /* jne 0xb94f0d */
    (void)sub32(c, R32((uint32_t)(0xb9f188u)), c->edi); /* cmp dword ptr [0x1000f188], edi */
    if (c->zf) goto L_00b94f0d; /* je 0xb94f0d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b94f06u); f_00b97aed(c); /* call 0xb97aed */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00b94ed1(c); return; } /* jne 0xb94ed1 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00b94f0d:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b94ef4(CPU *c) { /* PTR_00b94ef4 */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_00b94f0d; /* jne 0xb94f0d */
    (void)sub32(c, R32((uint32_t)(0xb9f188u)), c->edi); /* cmp dword ptr [0x1000f188], edi */
    if (c->zf) goto L_00b94f0d; /* je 0xb94f0d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b94f06u); f_00b97aed(c); /* call 0xb97aed */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00b94ed1(c); return; } /* jne 0xb94ed1 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00b94f0d:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b94f0b(CPU *c) { /* PTR_00b94f0b */
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

void f_00b94f0d(CPU *c) { /* PTR_00b94f0d */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b94f1c(CPU *c) { /* FUN_10004f1c */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xb9b230u; PUSH32(c, v_); } /* push 0x1000b230 */
    { uint32_t v_ = 0xb96374u; PUSH32(c, v_); } /* push 0x10006374 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x1cu)); /* sub esp, 0x1c */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9f568u))); /* mov eax, dword ptr [0x1000f568] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_00b94f8f; /* jne 0xb94f8f */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b94f50u); f_00b95678(c); /* call 0xb95678 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b94f5eu); f_00b96921(c); /* call 0xb96921 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b94f71; /* je 0xb94f71 */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0xfffffffcu))); /* mov esi, dword ptr [esi - 4] */
    c->esi = (uint32_t)(sub32(c, c->esi, (uint32_t)0x9u)); /* sub esi, 9 */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x20], esi */
    goto L_00b94f74; /* jmp 0xb94f74 */
L_00b94f71:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
L_00b94f74:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b94f7du); f_00b94f86(c); /* call 0xb94f86 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x1c], 0 */
    goto L_00b94fd8; /* jmp 0xb94fd8 */
L_00b94f8f:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00b94fda; /* jne 0xb94fda */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b94f9bu); f_00b95678(c); /* call 0xb95678 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffdcu)); /* lea eax, [ebp - 0x24] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00b94fb3u); f_00b9767c(c); /* call 0xb9767c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x28], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b94fc8; /* je 0xb94fc8 */
    c->esi = (uint32_t)((uint32_t)R8((uint32_t)(c->eax))); /* movzx esi, byte ptr [eax] */
    c->esi = (uint32_t)(shl32(c, c->esi, 4)); /* shl esi, 4 */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x20], esi */
    goto L_00b94fcb; /* jmp 0xb94fcb */
L_00b94fc8:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
L_00b94fcb:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b94fd4u); f_00b95001(c); /* call 0xb95001 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x28], 0 */
L_00b94fd8:;
    if (!c->zf) goto L_00b94fed; /* jne 0xb94fed */
L_00b94fda:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb9f564u)); PUSH32(c, v_); } /* push dword ptr [0x1000f564] */
    { uint32_t t_ = R32((uint32_t)(0xb9b040u)); PUSH32(c, 0x00b94febu); call_indirect(c, t_); } /* call dword ptr [0x1000b040] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_00b94fed:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b94f83(CPU *c) { /* PTR_00b94f83 */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
    { f_00b94f86(c); return; }
}

void f_00b94f86(CPU *c) { /* FUN_10004f86 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b94f8du); f_00b956d9(c); /* call 0xb956d9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00b94f8f(CPU *c) { /* PTR_00b94f8f */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00b94fda; /* jne 0xb94fda */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b94f9bu); f_00b95678(c); /* call 0xb95678 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffdcu)); /* lea eax, [ebp - 0x24] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00b94fb3u); f_00b9767c(c); /* call 0xb9767c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x28], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b94fc8; /* je 0xb94fc8 */
    c->esi = (uint32_t)((uint32_t)R8((uint32_t)(c->eax))); /* movzx esi, byte ptr [eax] */
    c->esi = (uint32_t)(shl32(c, c->esi, 4)); /* shl esi, 4 */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x20], esi */
    goto L_00b94fcb; /* jmp 0xb94fcb */
L_00b94fc8:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
L_00b94fcb:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b94fd4u); f_00b95001(c); /* call 0xb95001 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x28], 0 */
    if (!c->zf) goto L_00b94fed; /* jne 0xb94fed */
L_00b94fda:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb9f564u)); PUSH32(c, v_); } /* push dword ptr [0x1000f564] */
    { uint32_t t_ = R32((uint32_t)(0xb9b040u)); PUSH32(c, 0x00b94febu); call_indirect(c, t_); } /* call dword ptr [0x1000b040] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_00b94fed:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b94fc8(CPU *c) { /* PTR_00b94fc8 */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b94fd4u); f_00b95001(c); /* call 0xb95001 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x28], 0 */
    if (!c->zf) goto L_00b94fed; /* jne 0xb94fed */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb9f564u)); PUSH32(c, v_); } /* push dword ptr [0x1000f564] */
    { uint32_t t_ = R32((uint32_t)(0xb9b040u)); PUSH32(c, 0x00b94febu); call_indirect(c, t_); } /* call dword ptr [0x1000b040] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_00b94fed:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b94fcb(CPU *c) { /* PTR_00b94fcb */
    PREEMPT_POLL(c);
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b94fd4u); f_00b95001(c); /* call 0xb95001 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x28], 0 */
    if (!c->zf) goto L_00b94fed; /* jne 0xb94fed */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb9f564u)); PUSH32(c, v_); } /* push dword ptr [0x1000f564] */
    { uint32_t t_ = R32((uint32_t)(0xb9b040u)); PUSH32(c, 0x00b94febu); call_indirect(c, t_); } /* call dword ptr [0x1000b040] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_00b94fed:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b94fd8(CPU *c) { /* PTR_00b94fd8 */
    PREEMPT_POLL(c);
    if (!c->zf) goto L_00b94fed; /* jne 0xb94fed */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb9f564u)); PUSH32(c, v_); } /* push dword ptr [0x1000f564] */
    { uint32_t t_ = R32((uint32_t)(0xb9b040u)); PUSH32(c, 0x00b94febu); call_indirect(c, t_); } /* call dword ptr [0x1000b040] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_00b94fed:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b94fda(CPU *c) { /* PTR_00b94fda */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb9f564u)); PUSH32(c, v_); } /* push dword ptr [0x1000f564] */
    { uint32_t t_ = R32((uint32_t)(0xb9b040u)); PUSH32(c, 0x00b94febu); call_indirect(c, t_); } /* call dword ptr [0x1000b040] */
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

void f_00b94fed(CPU *c) { /* PTR_00b94fed */
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

void f_00b94ffe(CPU *c) { /* PTR_00b94ffe */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
    { f_00b95001(c); return; }
}

void f_00b95001(CPU *c) { /* FUN_10005001 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b95008u); f_00b956d9(c); /* call 0xb956d9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00b9500a(CPU *c) { /* _malloc */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(0xb9f188u)); PUSH32(c, v_); } /* push dword ptr [0x1000f188] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    PUSH32(c, 0x00b95019u); f_00b9501c(c); /* call 0xb9501c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00b9501c(CPU *c) { /* __nh_malloc */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->esp + 0x4u)), (uint32_t)0xffffffe0u); /* cmp dword ptr [esp + 4], -0x20 */
    if ((!c->cf && !c->zf)) goto L_00b95045; /* ja 0xb95045 */
L_00b95023:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    PUSH32(c, 0x00b9502cu); f_00b95048(c); /* call 0xb95048 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00b95047; /* jne 0xb95047 */
    (void)sub32(c, R32((uint32_t)(c->esp + 0x8u)), c->eax); /* cmp dword ptr [esp + 8], eax */
    if (c->zf) goto L_00b95047; /* je 0xb95047 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    PUSH32(c, 0x00b95040u); f_00b97aed(c); /* call 0xb97aed */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00b95023; /* jne 0xb95023 */
L_00b95045:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00b95047:;
    c->esp += 4; return; /* ret  */
}

void f_00b95048(CPU *c) { /* FUN_10005048 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xb9b248u; PUSH32(c, v_); } /* push 0x1000b248 */
    { uint32_t v_ = 0xb96374u; PUSH32(c, v_); } /* push 0x10006374 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9f568u))); /* mov eax, dword ptr [0x1000f568] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_00b950b8; /* jne 0xb950b8 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    (void)sub32(c, c->esi, R32((uint32_t)(0xb9f560u))); /* cmp esi, dword ptr [0x1000f560] */
    if ((!c->cf && !c->zf)) goto L_00b95117; /* ja 0xb95117 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b9508bu); f_00b95678(c); /* call 0xb95678 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b95096u); f_00b96c75(c); /* call 0xb96c75 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b950a3u); f_00b950af(c); /* call 0xb950af */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b95117; /* je 0xb95117 */
    goto L_00b95135; /* jmp 0xb95135 */
L_00b950b8:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00b95117; /* jne 0xb95117 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b950cc; /* je 0xb950cc */
    c->esi = (uint32_t)((uint32_t)(c->eax + 0xfu)); /* lea esi, [eax + 0xf] */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    goto L_00b950cf; /* jmp 0xb950cf */
L_00b950cc:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00b950cf:;
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
    (void)sub32(c, c->esi, R32((uint32_t)(0xb9e4dcu))); /* cmp esi, dword ptr [0x1000e4dc] */
    if ((!c->cf && !c->zf)) goto L_00b95108; /* ja 0xb95108 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b950e1u); f_00b95678(c); /* call 0xb95678 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b950f4u); f_00b97718(c); /* call 0xb97718 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b95101u); f_00b9510e(c); /* call 0xb9510e */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b95135; /* jne 0xb95135 */
L_00b95108:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    goto L_00b95127; /* jmp 0xb95127 */
L_00b95117:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b95121; /* jne 0xb95121 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00b95121:;
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xfu)); /* add eax, 0xf */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xf0u))); /* and al, 0xf0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
L_00b95127:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb9f564u)); PUSH32(c, v_); } /* push dword ptr [0x1000f564] */
    { uint32_t t_ = R32((uint32_t)(0xb9b03cu)); PUSH32(c, 0x00b95135u); call_indirect(c, t_); } /* call dword ptr [0x1000b03c] */
L_00b95135:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b950af(CPU *c) { /* FUN_100050af */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b950b6u); f_00b956d9(c); /* call 0xb956d9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00b950b8(CPU *c) { /* PTR_00b950b8 */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) { f_00b95117(c); return; } /* jne 0xb95117 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b950cc; /* je 0xb950cc */
    c->esi = (uint32_t)((uint32_t)(c->eax + 0xfu)); /* lea esi, [eax + 0xf] */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    goto L_00b950cf; /* jmp 0xb950cf */
L_00b950cc:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00b950cf:;
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
    (void)sub32(c, c->esi, R32((uint32_t)(0xb9e4dcu))); /* cmp esi, dword ptr [0x1000e4dc] */
    if ((!c->cf && !c->zf)) goto L_00b95108; /* ja 0xb95108 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b950e1u); f_00b95678(c); /* call 0xb95678 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b950f4u); f_00b97718(c); /* call 0xb97718 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b95101u); f_00b9510e(c); /* call 0xb9510e */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00b95135(c); return; } /* jne 0xb95135 */
L_00b95108:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { f_00b95127(c); return; } /* jmp 0xb95127 */
}

void f_00b950cc(CPU *c) { /* PTR_00b950cc */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
    (void)sub32(c, c->esi, R32((uint32_t)(0xb9e4dcu))); /* cmp esi, dword ptr [0x1000e4dc] */
    if ((!c->cf && !c->zf)) goto L_00b95108; /* ja 0xb95108 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b950e1u); f_00b95678(c); /* call 0xb95678 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b950f4u); f_00b97718(c); /* call 0xb97718 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b95101u); f_00b9510e(c); /* call 0xb9510e */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00b95135(c); return; } /* jne 0xb95135 */
L_00b95108:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { f_00b95127(c); return; } /* jmp 0xb95127 */
}

void f_00b950cf(CPU *c) { /* PTR_00b950cf */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
    (void)sub32(c, c->esi, R32((uint32_t)(0xb9e4dcu))); /* cmp esi, dword ptr [0x1000e4dc] */
    if ((!c->cf && !c->zf)) goto L_00b95108; /* ja 0xb95108 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b950e1u); f_00b95678(c); /* call 0xb95678 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b950f4u); f_00b97718(c); /* call 0xb97718 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b95101u); f_00b9510e(c); /* call 0xb9510e */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00b95135(c); return; } /* jne 0xb95135 */
L_00b95108:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { f_00b95127(c); return; } /* jmp 0xb95127 */
}

void f_00b95108(CPU *c) { /* PTR_00b95108 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { f_00b95127(c); return; } /* jmp 0xb95127 */
}

void f_00b9510b(CPU *c) { /* PTR_00b9510b */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    { f_00b9510e(c); return; }
}

void f_00b9510e(CPU *c) { /* FUN_1000510e */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b95115u); f_00b956d9(c); /* call 0xb956d9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00b95117(CPU *c) { /* PTR_00b95117 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b95121; /* jne 0xb95121 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00b95121:;
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xfu)); /* add eax, 0xf */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xf0u))); /* and al, 0xf0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb9f564u)); PUSH32(c, v_); } /* push dword ptr [0x1000f564] */
    { uint32_t t_ = R32((uint32_t)(0xb9b03cu)); PUSH32(c, 0x00b95135u); call_indirect(c, t_); } /* call dword ptr [0x1000b03c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b95121(CPU *c) { /* PTR_00b95121 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xfu)); /* add eax, 0xf */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xf0u))); /* and al, 0xf0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb9f564u)); PUSH32(c, v_); } /* push dword ptr [0x1000f564] */
    { uint32_t t_ = R32((uint32_t)(0xb9b03cu)); PUSH32(c, 0x00b95135u); call_indirect(c, t_); } /* call dword ptr [0x1000b03c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b95127(CPU *c) { /* PTR_00b95127 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb9f564u)); PUSH32(c, v_); } /* push dword ptr [0x1000f564] */
    { uint32_t t_ = R32((uint32_t)(0xb9b03cu)); PUSH32(c, 0x00b95135u); call_indirect(c, t_); } /* call dword ptr [0x1000b03c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b95135(CPU *c) { /* PTR_00b95135 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b95144(CPU *c) { /* FUN_10005144 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x30000u; PUSH32(c, v_); } /* push 0x30000 */
    { uint32_t v_ = 0x10000u; PUSH32(c, v_); } /* push 0x10000 */
    PUSH32(c, 0x00b95153u); f_00b97e7a(c); /* call 0xb97e7a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00b95156(CPU *c) { /* FUN_10005156 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    FPUSH(c, RF64((uint32_t)(0xb9b270u))); /* fld qword ptr [0x1000b270] */
    WF64((uint32_t)(c->ebp + 0xfffffff8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 8] */
    FPUSH(c, RF64((uint32_t)(0xb9b268u))); /* fld qword ptr [0x1000b268] */
    WF64((uint32_t)(c->ebp + 0xfffffff0u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0x10] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff0u))); /* fld qword ptr [ebp - 0x10] */
    ST(0) = FPRES(c, FDIV(c, ST(0), RF64((uint32_t)(c->ebp + 0xfffffff8u)))); /* fdiv qword ptr [ebp - 8] */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->ebp + 0xfffffff8u))); /* fmul qword ptr [ebp - 8] */
    ST(0) = FPRES(c, RF64((uint32_t)(c->ebp + 0xfffffff0u)) - ST(0)); /* fsubr qword ptr [ebp - 0x10] */
    WF64((uint32_t)(c->ebp + 0xffffffe8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0x18] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xffffffe8u))); /* fld qword ptr [ebp - 0x18] */
    FCOM(c, ST(0), RF64((uint32_t)(0xb9b260u))); FPOP(c); /* fcomp qword ptr [0x1000b260] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if ((c->cf || c->zf)) goto L_00b95190; /* jbe 0xb95190 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b95190:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b95194(CPU *c) { /* FUN_10005194 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xb9b294u; PUSH32(c, v_); } /* push 0x1000b294 */
    { uint32_t t_ = R32((uint32_t)(0xb9b048u)); PUSH32(c, 0x00b9519fu); call_indirect(c, t_); } /* call dword ptr [0x1000b048] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b951b8; /* je 0xb951b8 */
    { uint32_t v_ = 0xb9b278u; PUSH32(c, v_); } /* push 0x1000b278 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0xb9b044u)); PUSH32(c, 0x00b951afu); call_indirect(c, t_); } /* call dword ptr [0x1000b044] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b951b8; /* je 0xb951b8 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00b951b7u); call_indirect(c, t_); } /* call eax */
    c->esp += 4; return; /* ret  */
L_00b951b8:;
    { f_00b95156(c); return; } /* jmp 0xb95156 */
}

void f_00b951bd(CPU *c) { /* FUN_100051bd */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->esi))); /* movsx eax, byte ptr [esi] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b951cbu); f_00b98020(c); /* call 0xb98020 */
    (void)sub32(c, c->eax, (uint32_t)0x65u); /* cmp eax, 0x65 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00b951fd; /* je 0xb951fd */
L_00b951d1:;
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub32(c, R32((uint32_t)(0xb9e4e0u)), (uint32_t)0x1u); /* cmp dword ptr [0x1000e4e0], 1 */
    if ((c->zf || c->sf != c->of)) goto L_00b951ea; /* jle 0xb951ea */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->esi))); /* movsx eax, byte ptr [esi] */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b951e6u); f_00b97fab(c); /* call 0xb97fab */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00b951f9; /* jmp 0xb951f9 */
L_00b951ea:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->esi))); /* movsx eax, byte ptr [esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb9e4ecu))); /* mov ecx, dword ptr [0x1000e4ec] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4u))); /* and eax, 4 */
L_00b951f9:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b951d1; /* jne 0xb951d1 */
L_00b951fd:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0xb9e4e4u))); /* mov cl, byte ptr [0x1000e4e4] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esi], cl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_00b95208:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov cl, byte ptr [esi] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [esi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(((uint8_t)c->ecx)); /* mov al, cl */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov cl, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_00b95208; /* jne 0xb95208 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b95217(CPU *c) { /* PTR_00b95217 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0xb9e4e4u))); /* mov dl, byte ptr [0x1000e4e4] */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_00b95233; /* je 0xb95233 */
L_00b95227:;
    (void)sub8(c, ((uint8_t)c->ecx), ((uint8_t)c->edx)); /* cmp cl, dl */
    if (c->zf) goto L_00b95233; /* je 0xb95233 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1u))); /* mov cl, byte ptr [eax + 1] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_00b95227; /* jne 0xb95227 */
L_00b95233:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_00b95264; /* je 0xb95264 */
L_00b9523a:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_00b9524d; /* je 0xb9524d */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x65u); /* cmp cl, 0x65 */
    if (c->zf) goto L_00b9524d; /* je 0xb9524d */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x45u); /* cmp cl, 0x45 */
    if (c->zf) goto L_00b9524d; /* je 0xb9524d */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_00b9523a; /* jmp 0xb9523a */
L_00b9524d:;
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
L_00b9524f:;
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x30u); /* cmp byte ptr [eax], 0x30 */
    if (c->zf) goto L_00b9524f; /* je 0xb9524f */
    (void)sub8(c, R8((uint32_t)(c->eax)), ((uint8_t)c->edx)); /* cmp byte ptr [eax], dl */
    if (!c->zf) goto L_00b9525a; /* jne 0xb9525a */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
L_00b9525a:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov dl, byte ptr [ecx] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [eax], dl */
    if (!c->zf) goto L_00b9525a; /* jne 0xb9525a */
L_00b95264:;
    c->esp += 4; return; /* ret  */
}

void f_00b95265(CPU *c) { /* PTR_00b95265 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    FPUSH(c, RF64((uint32_t)(c->eax))); /* fld qword ptr [eax] */
    FCOM(c, ST(0), RF64((uint32_t)(0xb9b2a0u))); FPOP(c); /* fcomp qword ptr [0x1000b2a0] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (c->cf) goto L_00b9527a; /* jb 0xb9527a */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
L_00b9527a:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_00b9527d(CPU *c) { /* __fassign */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    if (c->zf) goto L_00b952a6; /* je 0xb952a6 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b95294u); f_00b984ec(c); /* call 0xb984ec */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 4], ecx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b952a6:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b952afu); f_00b98519(c); /* call 0xb98519 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b952bb(CPU *c) { /* FUN_100052bb */
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
    PUSH32(c, 0x00b952d9u); f_00b985bd(c); /* call 0xb985bd */
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
    PUSH32(c, 0x00b95301u); f_00b98546(c); /* call 0xb98546 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x00b95313u); f_00b9531c(c); /* call 0xb9531c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x30u)); /* add esp, 0x30 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b9531c(CPU *c) { /* FUN_1000531c */
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
    if (c->zf) goto L_00b9534a; /* je 0xb9534a */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->ebx); /* cmp dword ptr [ebp + 0xc], ebx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((!c->zf && c->sf == c->of) ? 1 : 0); /* setg al */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x2du); /* cmp dword ptr [esi], 0x2d */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete al */
    c->eax = (uint32_t)(add32(c, c->eax, c->edi)); /* add eax, edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b95348u); f_00b955be(c); /* call 0xb955be */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b9534a:;
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x2du); /* cmp dword ptr [esi], 0x2d */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    if (!c->zf) goto L_00b95357; /* jne 0xb95357 */
    W8((uint32_t)(c->edi), (uint8_t)((uint8_t)0x2du)); /* mov byte ptr [edi], 0x2d */
    c->eax = (uint32_t)((uint32_t)(c->edi + 0x1u)); /* lea eax, [edi + 1] */
L_00b95357:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->ebx); /* cmp dword ptr [ebp + 0xc], ebx */
    if ((c->zf || c->sf != c->of)) goto L_00b9536e; /* jle 0xb9536e */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1u))); /* mov dl, byte ptr [eax + 1] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x1u)); /* lea ecx, [eax + 1] */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [eax], dl */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0xb9e4e4u))); /* mov cl, byte ptr [0x1000e4e4] */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax], cl */
L_00b9536e:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x18u)), ((uint8_t)c->ebx)); /* cmp byte ptr [ebp + 0x18], bl */
    { uint32_t v_ = 0xb9b2a8u; PUSH32(c, v_); } /* push 0x1000b2a8 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete cl */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    c->ecx = (uint32_t)(add32(c, c->ecx, R32((uint32_t)(c->ebp + 0xcu)))); /* add ecx, dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00b95386u); f_00b986d0(c); /* call 0xb986d0 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), c->ebx); /* cmp dword ptr [ebp + 0x10], ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    if (c->zf) goto L_00b95392; /* je 0xb95392 */
    W8((uint32_t)(c->ecx), (uint8_t)((uint8_t)0x45u)); /* mov byte ptr [ecx], 0x45 */
L_00b95392:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x30u); /* cmp byte ptr [eax], 0x30 */
    if (c->zf) goto L_00b953d7; /* je 0xb953d7 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ebx, dword ptr [esi + 4] */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->sf) goto L_00b953a6; /* jns 0xb953a6 */
    c->ebx = (uint32_t)(neg32(c, c->ebx)); /* neg ebx */
    W8((uint32_t)(c->ecx), (uint8_t)((uint8_t)0x2du)); /* mov byte ptr [ecx], 0x2d */
L_00b953a6:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->ebx, (uint32_t)0x64u); /* cmp ebx, 0x64 */
    if ((c->sf != c->of)) goto L_00b953bd; /* jl 0xb953bd */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = 0x64u; PUSH32(c, v_); } /* push 0x64 */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00b953b2u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [ecx], al */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00b953b9u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
    c->ebx = (uint32_t)(c->edx); /* mov ebx, edx */
L_00b953bd:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->ebx, (uint32_t)0xau); /* cmp ebx, 0xa */
    if ((c->sf != c->of)) goto L_00b953d4; /* jl 0xb953d4 */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = 0xau; PUSH32(c, v_); } /* push 0xa */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00b953c9u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [ecx], al */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00b953d0u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
    c->ebx = (uint32_t)(c->edx); /* mov ebx, edx */
L_00b953d4:;
    { uint32_t a_ = (uint32_t)(c->ecx + 0x1u); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ebx)))); } /* add byte ptr [ecx + 1], bl */
L_00b953d7:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00b953de(CPU *c) { /* FUN_100053de */
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
    PUSH32(c, 0x00b953fcu); f_00b985bd(c); /* call 0xb985bd */
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
    PUSH32(c, 0x00b9541bu); f_00b98546(c); /* call 0xb98546 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x00b9542au); f_00b95433(c); /* call 0xb95433 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b95433(CPU *c) { /* FUN_10005433 */
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
    if (c->zf) goto L_00b95463; /* je 0xb95463 */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xcu))); /* cmp eax, dword ptr [ebp + 0xc] */
    if (!c->zf) goto L_00b95463; /* jne 0xb95463 */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x2du); /* cmp dword ptr [esi], 0x2d */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete cl */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->ebx)); /* add ecx, ebx */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    W8((uint32_t)(c->eax), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [eax], 0x30 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x1u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax + 1], 0 */
L_00b95463:;
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x2du); /* cmp dword ptr [esi], 0x2d */
    c->edi = (uint32_t)(c->ebx); /* mov edi, ebx */
    if (!c->zf) goto L_00b95470; /* jne 0xb95470 */
    W8((uint32_t)(c->ebx), (uint8_t)((uint8_t)0x2du)); /* mov byte ptr [ebx], 0x2d */
    c->edi = (uint32_t)((uint32_t)(c->ebx + 0x1u)); /* lea edi, [ebx + 1] */
L_00b95470:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((!c->zf && c->sf == c->of)) goto L_00b95487; /* jg 0xb95487 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b9547fu); f_00b955be(c); /* call 0xb955be */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W8((uint32_t)(c->edi), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [edi], 0x30 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_00b95489; /* jmp 0xb95489 */
L_00b95487:;
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
L_00b95489:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    if ((c->zf || c->sf != c->of)) goto L_00b954d3; /* jle 0xb954d3 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b95497u); f_00b955be(c); /* call 0xb955be */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0xb9e4e4u))); /* mov al, byte ptr [0x1000e4e4] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov esi, dword ptr [esi + 4] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if ((c->sf == c->of)) goto L_00b954d3; /* jge 0xb954d3 */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x14u)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0x14], 0 */
    if (c->zf) goto L_00b954b2; /* je 0xb954b2 */
    c->esi = (uint32_t)(neg32(c, c->esi)); /* neg esi */
    goto L_00b954b9; /* jmp 0xb954b9 */
L_00b954b2:;
    c->esi = (uint32_t)(neg32(c, c->esi)); /* neg esi */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->esi); /* cmp dword ptr [ebp + 0xc], esi */
    if ((c->sf != c->of)) goto L_00b954bc; /* jl 0xb954bc */
L_00b954b9:;
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_00b954bc:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b954c5u); f_00b955be(c); /* call 0xb955be */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = 0x30u; PUSH32(c, v_); } /* push 0x30 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b954d0u); f_00b987c0(c); /* call 0xb987c0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
L_00b954d3:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00b954da(CPU *c) { /* FUN_100054da */
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
    PUSH32(c, 0x00b954fau); f_00b985bd(c); /* call 0xb985bd */
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
    PUSH32(c, 0x00b9551cu); f_00b98546(c); /* call 0xb98546 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)((c->sf != c->of) ? 1 : 0); /* setl cl */
    (void)sub32(c, c->eax, (uint32_t)0xfffffffcu); /* cmp eax, -4 */
    if ((c->sf != c->of)) goto L_00b95553; /* jl 0xb95553 */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if ((c->sf == c->of)) goto L_00b95553; /* jge 0xb95553 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_00b9553f; /* je 0xb9553f */
L_00b95535:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov al, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00b95535; /* jne 0xb95535 */
    { uint32_t a_ = (uint32_t)(c->edi + 0xfffffffeu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & ((uint8_t)c->eax))))); } /* and byte ptr [edi - 2], al */
L_00b9553f:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x00b9554eu); f_00b95433(c); /* call 0xb95433 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    goto L_00b95568; /* jmp 0xb95568 */
L_00b95553:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x00b95565u); f_00b9531c(c); /* call 0xb9531c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
L_00b95568:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b9556d(CPU *c) { /* __cfltcvt */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), (uint32_t)0x65u); /* cmp dword ptr [ebp + 0x10], 0x65 */
    if (c->zf) goto L_00b955a8; /* je 0xb955a8 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), (uint32_t)0x45u); /* cmp dword ptr [ebp + 0x10], 0x45 */
    if (c->zf) goto L_00b955a8; /* je 0xb955a8 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), (uint32_t)0x66u); /* cmp dword ptr [ebp + 0x10], 0x66 */
    if (!c->zf) goto L_00b95595; /* jne 0xb95595 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00b95590u); f_00b953de(c); /* call 0xb953de */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
L_00b95595:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00b955a6u); f_00b954da(c); /* call 0xb954da */
    goto L_00b955b9; /* jmp 0xb955b9 */
L_00b955a8:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00b955b9u); f_00b952bb(c); /* call 0xb952bb */
L_00b955b9:;
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00b955be(CPU *c) { /* FUN_100055be */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edi, dword ptr [esp + 0xc] */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00b955e1; /* je 0xb955e1 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov esi, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b955d2u); f_00b98820(c); /* call 0xb98820 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(add32(c, c->esi, c->edi)); /* add esi, edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b955ddu); f_00b96450(c); /* call 0xb96450 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00b955e1:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00b955e3(CPU *c) { /* FUN_100055e3 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(0xb9b04cu))); /* mov esi, dword ptr [0x1000b04c] */
    { uint32_t v_ = R32((uint32_t)(0xb9c2f4u)); PUSH32(c, v_); } /* push dword ptr [0x1000c2f4] */
    { uint32_t t_ = c->esi; PUSH32(c, 0x00b955f2u); call_indirect(c, t_); } /* call esi */
    { uint32_t v_ = R32((uint32_t)(0xb9c2e4u)); PUSH32(c, v_); } /* push dword ptr [0x1000c2e4] */
    { uint32_t t_ = c->esi; PUSH32(c, 0x00b955fau); call_indirect(c, t_); } /* call esi */
    { uint32_t v_ = R32((uint32_t)(0xb9c2d4u)); PUSH32(c, v_); } /* push dword ptr [0x1000c2d4] */
    { uint32_t t_ = c->esi; PUSH32(c, 0x00b95602u); call_indirect(c, t_); } /* call esi */
    { uint32_t v_ = R32((uint32_t)(0xb9c2b4u)); PUSH32(c, v_); } /* push dword ptr [0x1000c2b4] */
    { uint32_t t_ = c->esi; PUSH32(c, 0x00b9560au); call_indirect(c, t_); } /* call esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b9560c(CPU *c) { /* FUN_1000560c */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(0xb9b050u))); /* mov edi, dword ptr [0x1000b050] */
    c->esi = (uint32_t)((uint32_t)0xb9c2b0u); /* mov esi, 0x1000c2b0 */
L_00b95619:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b9564a; /* je 0xb9564a */
    (void)sub32(c, c->esi, (uint32_t)0xb9c2f4u); /* cmp esi, 0x1000c2f4 */
    if (c->zf) goto L_00b9564a; /* je 0xb9564a */
    (void)sub32(c, c->esi, (uint32_t)0xb9c2e4u); /* cmp esi, 0x1000c2e4 */
    if (c->zf) goto L_00b9564a; /* je 0xb9564a */
    (void)sub32(c, c->esi, (uint32_t)0xb9c2d4u); /* cmp esi, 0x1000c2d4 */
    if (c->zf) goto L_00b9564a; /* je 0xb9564a */
    (void)sub32(c, c->esi, (uint32_t)0xb9c2b4u); /* cmp esi, 0x1000c2b4 */
    if (c->zf) goto L_00b9564a; /* je 0xb9564a */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00b95642u); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    PUSH32(c, 0x00b95649u); f_00b956ee(c); /* call 0xb956ee */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b9564a:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, c->esi, (uint32_t)0xb9c370u); /* cmp esi, 0x1000c370 */
    if ((c->sf != c->of)) goto L_00b95619; /* jl 0xb95619 */
    { uint32_t v_ = R32((uint32_t)(0xb9c2d4u)); PUSH32(c, v_); } /* push dword ptr [0x1000c2d4] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00b9565du); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = R32((uint32_t)(0xb9c2e4u)); PUSH32(c, v_); } /* push dword ptr [0x1000c2e4] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00b95665u); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = R32((uint32_t)(0xb9c2f4u)); PUSH32(c, v_); } /* push dword ptr [0x1000c2f4] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00b9566du); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = R32((uint32_t)(0xb9c2b4u)); PUSH32(c, v_); } /* push dword ptr [0x1000c2b4] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00b95675u); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b95678(CPU *c) { /* FUN_10005678 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    (void)sub32(c, R32((uint32_t)(c->eax * 4 + 0xb9c2b0u)), (uint32_t)0x0u); /* cmp dword ptr [eax*4 + 0x1000c2b0], 0 */
    c->esi = (uint32_t)((uint32_t)(c->eax * 4 + 0xb9c2b0u)); /* lea esi, [eax*4 + 0x1000c2b0] */
    if (!c->zf) goto L_00b956ce; /* jne 0xb956ce */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    PUSH32(c, 0x00b95698u); f_00b9500a(c); /* call 0xb9500a */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (!c->zf) goto L_00b956a7; /* jne 0xb956a7 */
    { uint32_t v_ = 0x11u; PUSH32(c, v_); } /* push 0x11 */
    PUSH32(c, 0x00b956a6u); f_00b93ff1(c); /* call 0xb93ff1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b956a7:;
    { uint32_t v_ = 0x11u; PUSH32(c, v_); } /* push 0x11 */
    PUSH32(c, 0x00b956aeu); f_00b95678(c); /* call 0xb95678 */
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x0u); /* cmp dword ptr [esi], 0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00b956bf; /* jne 0xb956bf */
    { uint32_t t_ = R32((uint32_t)(0xb9b04cu)); PUSH32(c, 0x00b956bbu); call_indirect(c, t_); } /* call dword ptr [0x1000b04c] */
    W32((uint32_t)(c->esi), (uint32_t)(c->edi)); /* mov dword ptr [esi], edi */
    goto L_00b956c5; /* jmp 0xb956c5 */
L_00b956bf:;
    PUSH32(c, 0x00b956c4u); f_00b956ee(c); /* call 0xb956ee */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b956c5:;
    { uint32_t v_ = 0x11u; PUSH32(c, v_); } /* push 0x11 */
    PUSH32(c, 0x00b956ccu); f_00b956d9(c); /* call 0xb956d9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_00b956ce:;
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(0xb9b054u)); PUSH32(c, 0x00b956d6u); call_indirect(c, t_); } /* call dword ptr [0x1000b054] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00b956d9(CPU *c) { /* FUN_100056d9 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->eax * 4 + 0xb9c2b0u)); PUSH32(c, v_); } /* push dword ptr [eax*4 + 0x1000c2b0] */
    { uint32_t t_ = R32((uint32_t)(0xb9b058u)); PUSH32(c, 0x00b956ecu); call_indirect(c, t_); } /* call dword ptr [0x1000b058] */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00b956ee(CPU *c) { /* FUN_100056ee */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xb9b2b0u; PUSH32(c, v_); } /* push 0x1000b2b0 */
    { uint32_t v_ = 0xb96374u; PUSH32(c, v_); } /* push 0x10006374 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00b957c8; /* je 0xb957c8 */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9f568u))); /* mov eax, dword ptr [0x1000f568] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_00b95761; /* jne 0xb95761 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b9572du); f_00b95678(c); /* call 0xb95678 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b95738u); f_00b96921(c); /* call 0xb96921 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b95749; /* je 0xb95749 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b95747u); f_00b9694c(c); /* call 0xb9694c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b95749:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b95752u); f_00b95758(c); /* call 0xb95758 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x1c], 0 */
    goto L_00b957a9; /* jmp 0xb957a9 */
L_00b95761:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00b957b9; /* jne 0xb957b9 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b9576du); f_00b95678(c); /* call 0xb95678 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe0u)); /* lea eax, [ebp - 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd8u)); /* lea eax, [ebp - 0x28] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b95783u); f_00b9767c(c); /* call 0xb9767c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b9579c; /* je 0xb9579c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x28] */
    PUSH32(c, 0x00b95799u); f_00b976d3(c); /* call 0xb976d3 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_00b9579c:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b957a5u); f_00b957b0(c); /* call 0xb957b0 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
L_00b957a9:;
    if (!c->zf) goto L_00b957c8; /* jne 0xb957c8 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    goto L_00b957ba; /* jmp 0xb957ba */
L_00b957b9:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
L_00b957ba:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb9f564u)); PUSH32(c, v_); } /* push dword ptr [0x1000f564] */
    { uint32_t t_ = R32((uint32_t)(0xb9b05cu)); PUSH32(c, 0x00b957c8u); call_indirect(c, t_); } /* call dword ptr [0x1000b05c] */
L_00b957c8:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b95758(CPU *c) { /* FUN_10005758 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b9575fu); f_00b956d9(c); /* call 0xb956d9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00b95761(CPU *c) { /* PTR_00b95761 */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) { f_00b957b9(c); return; } /* jne 0xb957b9 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b9576du); f_00b95678(c); /* call 0xb95678 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe0u)); /* lea eax, [ebp - 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd8u)); /* lea eax, [ebp - 0x28] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b95783u); f_00b9767c(c); /* call 0xb9767c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b9579c; /* je 0xb9579c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x28] */
    PUSH32(c, 0x00b95799u); f_00b976d3(c); /* call 0xb976d3 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_00b9579c:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b957a5u); f_00b957b0(c); /* call 0xb957b0 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) { f_00b957c8(c); return; } /* jne 0xb957c8 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { f_00b957ba(c); return; } /* jmp 0xb957ba */
}

void f_00b9579c(CPU *c) { /* PTR_00b9579c */
    PREEMPT_POLL(c);
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b957a5u); f_00b957b0(c); /* call 0xb957b0 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) { f_00b957c8(c); return; } /* jne 0xb957c8 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { f_00b957ba(c); return; } /* jmp 0xb957ba */
}

void f_00b957a9(CPU *c) { /* PTR_00b957a9 */
    PREEMPT_POLL(c);
    if (!c->zf) { f_00b957c8(c); return; } /* jne 0xb957c8 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { f_00b957ba(c); return; } /* jmp 0xb957ba */
}

void f_00b957b0(CPU *c) { /* FUN_100057b0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b957b7u); f_00b956d9(c); /* call 0xb956d9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00b957b9(CPU *c) { /* PTR_00b957b9 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb9f564u)); PUSH32(c, v_); } /* push dword ptr [0x1000f564] */
    { uint32_t t_ = R32((uint32_t)(0xb9b05cu)); PUSH32(c, 0x00b957c8u); call_indirect(c, t_); } /* call dword ptr [0x1000b05c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b957ba(CPU *c) { /* PTR_00b957ba */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb9f564u)); PUSH32(c, v_); } /* push dword ptr [0x1000f564] */
    { uint32_t t_ = R32((uint32_t)(0xb9b05cu)); PUSH32(c, 0x00b957c8u); call_indirect(c, t_); } /* call dword ptr [0x1000b05c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b957c8(CPU *c) { /* PTR_00b957c8 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b957e0(CPU *c) { /* _strcmp */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u)); /* test edx, 3 */
    if (!c->zf) goto L_00b9582c; /* jne 0xb9582c */
L_00b957f0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edx))); /* mov eax, dword ptr [edx] */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->ecx))); /* cmp al, byte ptr [ecx] */
    if (!c->zf) goto L_00b95824; /* jne 0xb95824 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00b95820; /* je 0xb95820 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), R8((uint32_t)(c->ecx + 0x1u))); /* cmp ah, byte ptr [ecx + 1] */
    if (!c->zf) goto L_00b95824; /* jne 0xb95824 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | ((uint8_t)(c->eax >> 8))))) << 8); /* or ah, ah */
    if (c->zf) goto L_00b95820; /* je 0xb95820 */
    c->eax = (uint32_t)(shr32(c, c->eax, 16)); /* shr eax, 0x10 */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->ecx + 0x2u))); /* cmp al, byte ptr [ecx + 2] */
    if (!c->zf) goto L_00b95824; /* jne 0xb95824 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00b95820; /* je 0xb95820 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), R8((uint32_t)(c->ecx + 0x3u))); /* cmp ah, byte ptr [ecx + 3] */
    if (!c->zf) goto L_00b95824; /* jne 0xb95824 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x4u)); /* add edx, 4 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | ((uint8_t)(c->eax >> 8))))) << 8); /* or ah, ah */
    if (!c->zf) goto L_00b957f0; /* jne 0xb957f0 */
    c->edi = (uint32_t)(c->edi); /* mov edi, edi */
L_00b95820:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_00b95824:;
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(shl32(c, c->eax, 1)); /* shl eax, 1 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->esp += 4; return; /* ret  */
L_00b9582c:;
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x1u)); /* test edx, 1 */
    if (c->zf) goto L_00b95848; /* je 0xb95848 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov al, byte ptr [edx] */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->ecx))); /* cmp al, byte ptr [ecx] */
    if (!c->zf) goto L_00b95824; /* jne 0xb95824 */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00b95820; /* je 0xb95820 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x2u)); /* test edx, 2 */
    if (c->zf) goto L_00b957f0; /* je 0xb957f0 */
L_00b95848:;
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->edx))); /* mov ax, word ptr [edx] */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x2u)); /* add edx, 2 */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->ecx))); /* cmp al, byte ptr [ecx] */
    if (!c->zf) goto L_00b95824; /* jne 0xb95824 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00b95820; /* je 0xb95820 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), R8((uint32_t)(c->ecx + 0x1u))); /* cmp ah, byte ptr [ecx + 1] */
    if (!c->zf) goto L_00b95824; /* jne 0xb95824 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | ((uint8_t)(c->eax >> 8))))) << 8); /* or ah, ah */
    if (c->zf) goto L_00b95820; /* je 0xb95820 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x2u)); /* add ecx, 2 */
    goto L_00b957f0; /* jmp 0xb957f0 */
}

void f_00b95864(CPU *c) { /* FUN_10005864 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xe06d7363u); /* cmp dword ptr [eax], 0xe06d7363 */
    if (!c->zf) goto L_00b95887; /* jne 0xb95887 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [eax + 0x10], 3 */
    if (!c->zf) goto L_00b95887; /* jne 0xb95887 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x14u)), (uint32_t)0x19930520u); /* cmp dword ptr [eax + 0x14], 0x19930520 */
    if (!c->zf) goto L_00b95887; /* jne 0xb95887 */
    { f_00b94a18(c); return; } /* jmp 0xb94a18 */
L_00b95887:;
    c->eax = (uint32_t)(R32((uint32_t)(0xb9f070u))); /* mov eax, dword ptr [0x1000f070] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b958a4; /* je 0xb958a4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b95896u); f_00b96354(c); /* call 0xb96354 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00b958a4; /* je 0xb958a4 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(0xb9f070u)); PUSH32(c, 0x00b958a2u); call_indirect(c, t_); } /* call dword ptr [0x1000f070] */
    goto L_00b958a6; /* jmp 0xb958a6 */
L_00b958a4:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00b958a6:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00b958aa(CPU *c) { /* PTR_00b958aa */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xb95864u; PUSH32(c, v_); } /* push 0x10005864 */
    { uint32_t t_ = R32((uint32_t)(0xb9b060u)); PUSH32(c, 0x00b958b5u); call_indirect(c, t_); } /* call dword ptr [0x1000b060] */
    W32((uint32_t)(0xb9f070u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000f070], eax */
    c->esp += 4; return; /* ret  */
}

void f_00b958bb(CPU *c) { /* PTR_00b958bb */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(0xb9f070u)); PUSH32(c, v_); } /* push dword ptr [0x1000f070] */
    { uint32_t t_ = R32((uint32_t)(0xb9b060u)); PUSH32(c, 0x00b958c7u); call_indirect(c, t_); } /* call dword ptr [0x1000b060] */
    c->esp += 4; return; /* ret  */
}

void f_00b958c8(CPU *c) { /* FUN_100058c8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x48u)); /* sub esp, 0x48 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x480u; PUSH32(c, v_); } /* push 0x480 */
    PUSH32(c, 0x00b958dbu); f_00b9500a(c); /* call 0xb9500a */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_00b958ea; /* jne 0xb958ea */
    { uint32_t v_ = 0x1bu; PUSH32(c, v_); } /* push 0x1b */
    PUSH32(c, 0x00b958e9u); f_00b93ff1(c); /* call 0xb93ff1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b958ea:;
    W32((uint32_t)(0xb9f580u), (uint32_t)(c->esi)); /* mov dword ptr [0x1000f580], esi */
    W32((uint32_t)(0xb9f680u), (uint32_t)((uint32_t)0x20u)); /* mov dword ptr [0x1000f680], 0x20 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x480u)); /* lea eax, [esi + 0x480] */
L_00b95900:;
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if (!c->cf) goto L_00b95922; /* jae 0xb95922 */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [esi + 4], 0 */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [esi], 0xffffffff */
    { uint32_t a_ = (uint32_t)(c->esi + 0x8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi + 8], 0 */
    W8((uint32_t)(c->esi + 0x5u), (uint8_t)((uint8_t)0xau)); /* mov byte ptr [esi + 5], 0xa */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9f580u))); /* mov eax, dword ptr [0x1000f580] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x24u)); /* add esi, 0x24 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x480u)); /* add eax, 0x480 */
    goto L_00b95900; /* jmp 0xb95900 */
L_00b95922:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffb8u)); /* lea eax, [ebp - 0x48] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0xb9b070u)); PUSH32(c, 0x00b9592cu); call_indirect(c, t_); } /* call dword ptr [0x1000b070] */
    (void)sub16(c, R16((uint32_t)(c->ebp + 0xffffffeau)), (uint16_t)0x0u); /* cmp word ptr [ebp - 0x16], 0 */
    if (c->zf) goto L_00b95a08; /* je 0xb95a08 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b95a08; /* je 0xb95a08 */
    c->edi = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edi, dword ptr [eax] */
    c->ebx = (uint32_t)((uint32_t)(c->eax + 0x4u)); /* lea ebx, [eax + 4] */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->edi)); /* lea eax, [ebx + edi] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->eax = (uint32_t)((uint32_t)0x800u); /* mov eax, 0x800 */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if ((c->sf != c->of)) goto L_00b95958; /* jl 0xb95958 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
L_00b95958:;
    (void)sub32(c, R32((uint32_t)(0xb9f680u)), c->edi); /* cmp dword ptr [0x1000f680], edi */
    if ((c->sf == c->of)) goto L_00b959b6; /* jge 0xb959b6 */
    c->esi = (uint32_t)((uint32_t)0xb9f584u); /* mov esi, 0x1000f584 */
L_00b95965:;
    { uint32_t v_ = 0x480u; PUSH32(c, v_); } /* push 0x480 */
    PUSH32(c, 0x00b9596fu); f_00b9500a(c); /* call 0xb9500a */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00b959b0; /* je 0xb959b0 */
    { uint32_t a_ = (uint32_t)(0xb9f680u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x20u))); } /* add dword ptr [0x1000f680], 0x20 */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x480u)); /* lea ecx, [eax + 0x480] */
L_00b95983:;
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->cf) goto L_00b959a3; /* jae 0xb959a3 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax + 4], 0 */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [eax], 0xffffffff */
    { uint32_t a_ = (uint32_t)(c->eax + 0x8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [eax + 8], 0 */
    W8((uint32_t)(c->eax + 0x5u), (uint8_t)((uint8_t)0xau)); /* mov byte ptr [eax + 5], 0xa */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x24u)); /* add eax, 0x24 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x480u)); /* add ecx, 0x480 */
    goto L_00b95983; /* jmp 0xb95983 */
L_00b959a3:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, R32((uint32_t)(0xb9f680u)), c->edi); /* cmp dword ptr [0x1000f680], edi */
    if ((c->sf != c->of)) goto L_00b95965; /* jl 0xb95965 */
    goto L_00b959b6; /* jmp 0xb959b6 */
L_00b959b0:;
    c->edi = (uint32_t)(R32((uint32_t)(0xb9f680u))); /* mov edi, dword ptr [0x1000f680] */
L_00b959b6:;
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if ((c->zf || c->sf != c->of)) goto L_00b95a08; /* jle 0xb95a08 */
L_00b959bc:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    (void)sub32(c, c->ecx, (uint32_t)0xffffffffu); /* cmp ecx, -1 */
    if (c->zf) goto L_00b959fe; /* je 0xb959fe */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebx))); /* mov al, byte ptr [ebx] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    if (c->zf) goto L_00b959fe; /* je 0xb959fe */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x8u)); /* test al, 8 */
    if (!c->zf) goto L_00b959db; /* jne 0xb959db */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t t_ = R32((uint32_t)(0xb9b06cu)); PUSH32(c, 0x00b959d7u); call_indirect(c, t_); } /* call dword ptr [0x1000b06c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b959fe; /* je 0xb959fe */
L_00b959db:;
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 5)); /* sar ecx, 5 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1fu))); /* and eax, 0x1f */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx * 4 + 0xb9f580u))); /* mov ecx, dword ptr [ecx*4 + 0x1000f580] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 8)); /* lea eax, [eax + eax*8] */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->eax * 4)); /* lea eax, [ecx + eax*4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov ecx, dword ptr [ecx] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebx))); /* mov cl, byte ptr [ebx] */
    W8((uint32_t)(c->eax + 0x4u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax + 4], cl */
L_00b959fe:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x4u))); } /* add dword ptr [ebp - 4], 4 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if ((c->sf != c->of)) goto L_00b959bc; /* jl 0xb959bc */
L_00b95a08:;
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
L_00b95a0a:;
    c->ecx = (uint32_t)(R32((uint32_t)(0xb9f580u))); /* mov ecx, dword ptr [0x1000f580] */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->ebx * 8)); /* lea eax, [ebx + ebx*8] */
    (void)sub32(c, R32((uint32_t)(c->ecx + c->eax * 4)), (uint32_t)0xffffffffu); /* cmp dword ptr [ecx + eax*4], -1 */
    c->esi = (uint32_t)((uint32_t)(c->ecx + c->eax * 4)); /* lea esi, [ecx + eax*4] */
    if (!c->zf) goto L_00b95a69; /* jne 0xb95a69 */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    W8((uint32_t)(c->esi + 0x4u), (uint8_t)((uint8_t)0x81u)); /* mov byte ptr [esi + 4], 0x81 */
    if (!c->zf) goto L_00b95a29; /* jne 0xb95a29 */
    { uint32_t v_ = 0xfffffff6u; PUSH32(c, v_); } /* push -0xa */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_00b95a33; /* jmp 0xb95a33 */
L_00b95a29:;
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xfffffff5u)); /* add eax, -0xb */
L_00b95a33:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0xb9b068u)); PUSH32(c, 0x00b95a3au); call_indirect(c, t_); } /* call dword ptr [0x1000b068] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)sub32(c, c->edi, (uint32_t)0xffffffffu); /* cmp edi, -1 */
    if (c->zf) goto L_00b95a58; /* je 0xb95a58 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0xb9b06cu)); PUSH32(c, 0x00b95a48u); call_indirect(c, t_); } /* call dword ptr [0x1000b06c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b95a58; /* je 0xb95a58 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xffu))); /* and eax, 0xff */
    W32((uint32_t)(c->esi), (uint32_t)(c->edi)); /* mov dword ptr [esi], edi */
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00b95a5e; /* jne 0xb95a5e */
L_00b95a58:;
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x40u)))); } /* or byte ptr [esi + 4], 0x40 */
    goto L_00b95a6d; /* jmp 0xb95a6d */
L_00b95a5e:;
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_00b95a6d; /* jne 0xb95a6d */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x8u)))); } /* or byte ptr [esi + 4], 8 */
    goto L_00b95a6d; /* jmp 0xb95a6d */
L_00b95a69:;
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x80u)))); } /* or byte ptr [esi + 4], 0x80 */
L_00b95a6d:;
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    (void)sub32(c, c->ebx, (uint32_t)0x3u); /* cmp ebx, 3 */
    if ((c->sf != c->of)) goto L_00b95a0a; /* jl 0xb95a0a */
    { uint32_t v_ = R32((uint32_t)(0xb9f680u)); PUSH32(c, v_); } /* push dword ptr [0x1000f680] */
    { uint32_t t_ = R32((uint32_t)(0xb9b064u)); PUSH32(c, 0x00b95a7fu); call_indirect(c, t_); } /* call dword ptr [0x1000b064] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b95a84(CPU *c) { /* FUN_10005a84 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)((uint32_t)0xb9f580u); /* mov esi, 0x1000f580 */
L_00b95a8c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b95ac9; /* je 0xb95ac9 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x480u)); /* add eax, 0x480 */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (!c->cf) goto L_00b95abe; /* jae 0xb95abe */
    c->ebx = (uint32_t)((uint32_t)(c->edi + 0xcu)); /* lea ebx, [edi + 0xc] */
L_00b95aa0:;
    (void)sub32(c, R32((uint32_t)(c->ebx + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebx - 4], 0 */
    if (c->zf) goto L_00b95aad; /* je 0xb95aad */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(0xb9b050u)); PUSH32(c, 0x00b95aadu); call_indirect(c, t_); } /* call dword ptr [0x1000b050] */
L_00b95aad:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x24u)); /* add edi, 0x24 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x480u)); /* add eax, 0x480 */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x24u)); /* add ebx, 0x24 */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_00b95aa0; /* jb 0xb95aa0 */
L_00b95abe:;
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    PUSH32(c, 0x00b95ac5u); f_00b956ee(c); /* call 0xb956ee */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi], 0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b95ac9:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, c->esi, (uint32_t)0xb9f680u); /* cmp esi, 0x1000f680 */
    if ((c->sf != c->of)) goto L_00b95a8c; /* jl 0xb95a8c */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00b95ad8(CPU *c) { /* FUN_10005ad8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, R32((uint32_t)(0xb9f688u)), c->ebx); /* cmp dword ptr [0x1000f688], ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00b95aea; /* jne 0xb95aea */
    PUSH32(c, 0x00b95aeau); f_00b98c7c(c); /* call 0xb98c7c */
L_00b95aea:;
    c->esi = (uint32_t)(R32((uint32_t)(0xb9efbcu))); /* mov esi, dword ptr [0x1000efbc] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
L_00b95af2:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_00b95b0a; /* je 0xb95b0a */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x3du); /* cmp al, 0x3d */
    if (c->zf) goto L_00b95afd; /* je 0xb95afd */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
L_00b95afd:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b95b03u); f_00b98820(c); /* call 0xb98820 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esi = (uint32_t)((uint32_t)(c->esi + c->eax + 0x1u)); /* lea esi, [esi + eax + 1] */
    goto L_00b95af2; /* jmp 0xb95af2 */
L_00b95b0a:;
    c->eax = (uint32_t)((uint32_t)(c->edi * 4 + 0x4u)); /* lea eax, [edi*4 + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b95b17u); f_00b9500a(c); /* call 0xb9500a */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    W32((uint32_t)(0xb9efecu), (uint32_t)(c->esi)); /* mov dword ptr [0x1000efec], esi */
    if (!c->zf) goto L_00b95b2c; /* jne 0xb95b2c */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b95b2bu); f_00b93ff1(c); /* call 0xb93ff1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b95b2c:;
    c->edi = (uint32_t)(R32((uint32_t)(0xb9efbcu))); /* mov edi, dword ptr [0x1000efbc] */
    (void)sub8(c, R8((uint32_t)(c->edi)), ((uint8_t)c->ebx)); /* cmp byte ptr [edi], bl */
    if (c->zf) goto L_00b95b6f; /* je 0xb95b6f */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
L_00b95b37:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b95b3du); f_00b98820(c); /* call 0xb98820 */
    c->ebp = (uint32_t)(c->eax); /* mov ebp, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ebp = (uint32_t)(inc32(c, c->ebp)); /* inc ebp */
    (void)sub8(c, R8((uint32_t)(c->edi)), (uint8_t)0x3du); /* cmp byte ptr [edi], 0x3d */
    if (c->zf) goto L_00b95b68; /* je 0xb95b68 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x00b95b4cu); f_00b9500a(c); /* call 0xb9500a */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    if (!c->zf) goto L_00b95b5b; /* jne 0xb95b5b */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b95b5au); f_00b93ff1(c); /* call 0xb93ff1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b95b5b:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    PUSH32(c, 0x00b95b63u); f_00b986d0(c); /* call 0xb986d0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b95b68:;
    c->edi = (uint32_t)(add32(c, c->edi, c->ebp)); /* add edi, ebp */
    (void)sub8(c, R8((uint32_t)(c->edi)), ((uint8_t)c->ebx)); /* cmp byte ptr [edi], bl */
    if (!c->zf) goto L_00b95b37; /* jne 0xb95b37 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
L_00b95b6f:;
    { uint32_t v_ = R32((uint32_t)(0xb9efbcu)); PUSH32(c, v_); } /* push dword ptr [0x1000efbc] */
    PUSH32(c, 0x00b95b7au); f_00b956ee(c); /* call 0xb956ee */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(0xb9efbcu), (uint32_t)(c->ebx)); /* mov dword ptr [0x1000efbc], ebx */
    W32((uint32_t)(c->esi), (uint32_t)(c->ebx)); /* mov dword ptr [esi], ebx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0xb9f684u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x1000f684], 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00b95b91(CPU *c) { /* FUN_10005b91 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, R32((uint32_t)(0xb9f688u)), c->ebx); /* cmp dword ptr [0x1000f688], ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00b95ba8; /* jne 0xb95ba8 */
    PUSH32(c, 0x00b95ba8u); f_00b98c7c(c); /* call 0xb98c7c */
L_00b95ba8:;
    c->esi = (uint32_t)((uint32_t)0xb9f074u); /* mov esi, 0x1000f074 */
    { uint32_t v_ = 0x104u; PUSH32(c, v_); } /* push 0x104 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(0xb9b074u)); PUSH32(c, 0x00b95bbau); call_indirect(c, t_); } /* call dword ptr [0x1000b074] */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9f694u))); /* mov eax, dword ptr [0x1000f694] */
    W32((uint32_t)(0xb9effcu), (uint32_t)(c->esi)); /* mov dword ptr [0x1000effc], esi */
    c->edi = (uint32_t)(c->esi); /* mov edi, esi */
    (void)sub8(c, R8((uint32_t)(c->eax)), ((uint8_t)c->ebx)); /* cmp byte ptr [eax], bl */
    if (c->zf) goto L_00b95bcd; /* je 0xb95bcd */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
L_00b95bcd:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b95bddu); f_00b95c2a(c); /* call 0xb95c2a */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->ecx * 4)); /* lea eax, [eax + ecx*4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b95becu); f_00b9500a(c); /* call 0xb9500a */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (!c->zf) goto L_00b95bfd; /* jne 0xb95bfd */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    PUSH32(c, 0x00b95bfcu); f_00b93ff1(c); /* call 0xb93ff1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b95bfd:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->eax * 4)); /* lea eax, [esi + eax*4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b95c13u); f_00b95c2a(c); /* call 0xb95c2a */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    W32((uint32_t)(0xb9efe4u), (uint32_t)(c->esi)); /* mov dword ptr [0x1000efe4], esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0xb9efe0u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000efe0], eax */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b95c2a(CPU *c) { /* FUN_10005c2a */
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
    if (c->zf) goto L_00b95c54; /* je 0xb95c54 */
    W32((uint32_t)(c->edi), (uint32_t)(c->esi)); /* mov dword ptr [edi], esi */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 0xc], edi */
L_00b95c54:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x22u); /* cmp byte ptr [eax], 0x22 */
    if (!c->zf) goto L_00b95c9d; /* jne 0xb95c9d */
L_00b95c59:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1u))); /* mov dl, byte ptr [eax + 1] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x22u); /* cmp dl, 0x22 */
    if (c->zf) goto L_00b95c8b; /* je 0xb95c8b */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00b95c8b; /* je 0xb95c8b */
    c->edx = (uint32_t)((uint32_t)((uint8_t)c->edx)); /* movzx edx, dl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edx + 0xb9f441u)) & (uint8_t)0x4u)); /* test byte ptr [edx + 0x1000f441], 4 */
    if (c->zf) goto L_00b95c7e; /* je 0xb95c7e */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00b95c7e; /* je 0xb95c7e */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
L_00b95c7e:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00b95c59; /* je 0xb95c59 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    goto L_00b95c59; /* jmp 0xb95c59 */
L_00b95c8b:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00b95c95; /* je 0xb95c95 */
    { uint32_t a_ = (uint32_t)(c->esi); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [esi], 0 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_00b95c95:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x22u); /* cmp byte ptr [eax], 0x22 */
    if (!c->zf) goto L_00b95ce0; /* jne 0xb95ce0 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_00b95ce0; /* jmp 0xb95ce0 */
L_00b95c9d:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00b95ca8; /* je 0xb95ca8 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_00b95ca8:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ebx = (uint32_t)((uint32_t)((uint8_t)c->edx)); /* movzx ebx, dl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebx + 0xb9f441u)) & (uint8_t)0x4u)); /* test byte ptr [ebx + 0x1000f441], 4 */
    if (c->zf) goto L_00b95cc3; /* je 0xb95cc3 */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00b95cc2; /* je 0xb95cc2 */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov bl, byte ptr [eax] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [esi], bl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_00b95cc2:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
L_00b95cc3:;
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x20u); /* cmp dl, 0x20 */
    if (c->zf) goto L_00b95cd1; /* je 0xb95cd1 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00b95cd5; /* je 0xb95cd5 */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x9u); /* cmp dl, 9 */
    if (!c->zf) goto L_00b95c9d; /* jne 0xb95c9d */
L_00b95cd1:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (!c->zf) goto L_00b95cd8; /* jne 0xb95cd8 */
L_00b95cd5:;
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    goto L_00b95ce0; /* jmp 0xb95ce0 */
L_00b95cd8:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00b95ce0; /* je 0xb95ce0 */
    { uint32_t a_ = (uint32_t)(c->esi + 0xffffffffu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [esi - 1], 0 */
L_00b95ce0:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0x18u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp + 0x18], 0 */
L_00b95ce4:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (c->zf) goto L_00b95dcd; /* je 0xb95dcd */
L_00b95ced:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x20u); /* cmp dl, 0x20 */
    if (c->zf) goto L_00b95cf9; /* je 0xb95cf9 */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x9u); /* cmp dl, 9 */
    if (!c->zf) goto L_00b95cfc; /* jne 0xb95cfc */
L_00b95cf9:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_00b95ced; /* jmp 0xb95ced */
L_00b95cfc:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (c->zf) goto L_00b95dcd; /* je 0xb95dcd */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00b95d11; /* je 0xb95d11 */
    W32((uint32_t)(c->edi), (uint32_t)(c->esi)); /* mov dword ptr [edi], esi */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 0xc], edi */
L_00b95d11:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov edx, dword ptr [ebp + 0x14] */
    { uint32_t a_ = (uint32_t)(c->edx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [edx] */
L_00b95d16:;
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp + 8], 1 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
L_00b95d1f:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x5cu); /* cmp byte ptr [eax], 0x5c */
    if (!c->zf) goto L_00b95d28; /* jne 0xb95d28 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    goto L_00b95d1f; /* jmp 0xb95d1f */
L_00b95d28:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x22u); /* cmp byte ptr [eax], 0x22 */
    if (!c->zf) goto L_00b95d59; /* jne 0xb95d59 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x1u)); /* test bl, 1 */
    if (!c->zf) goto L_00b95d57; /* jne 0xb95d57 */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x18u)), c->edi); /* cmp dword ptr [ebp + 0x18], edi */
    if (c->zf) goto L_00b95d46; /* je 0xb95d46 */
    (void)sub8(c, R8((uint32_t)(c->eax + 0x1u)), (uint8_t)0x22u); /* cmp byte ptr [eax + 1], 0x22 */
    c->edx = (uint32_t)((uint32_t)(c->eax + 0x1u)); /* lea edx, [eax + 1] */
    if (!c->zf) goto L_00b95d46; /* jne 0xb95d46 */
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    goto L_00b95d49; /* jmp 0xb95d49 */
L_00b95d46:;
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 8], edi */
L_00b95d49:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x18u)), c->edx); /* cmp dword ptr [ebp + 0x18], edx */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete dl */
    W32((uint32_t)(c->ebp + 0x18u), (uint32_t)(c->edx)); /* mov dword ptr [ebp + 0x18], edx */
L_00b95d57:;
    c->ebx = (uint32_t)(shr32(c, c->ebx, 1)); /* shr ebx, 1 */
L_00b95d59:;
    c->edx = (uint32_t)(c->ebx); /* mov edx, ebx */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_00b95d6e; /* je 0xb95d6e */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
L_00b95d61:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00b95d69; /* je 0xb95d69 */
    W8((uint32_t)(c->esi), (uint8_t)((uint8_t)0x5cu)); /* mov byte ptr [esi], 0x5c */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_00b95d69:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->zf) goto L_00b95d61; /* jne 0xb95d61 */
L_00b95d6e:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00b95dbe; /* je 0xb95dbe */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x18u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x18], 0 */
    if (!c->zf) goto L_00b95d84; /* jne 0xb95d84 */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x20u); /* cmp dl, 0x20 */
    if (c->zf) goto L_00b95dbe; /* je 0xb95dbe */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x9u); /* cmp dl, 9 */
    if (c->zf) goto L_00b95dbe; /* je 0xb95dbe */
L_00b95d84:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    if (c->zf) goto L_00b95db8; /* je 0xb95db8 */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00b95da7; /* je 0xb95da7 */
    c->ebx = (uint32_t)((uint32_t)((uint8_t)c->edx)); /* movzx ebx, dl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebx + 0xb9f441u)) & (uint8_t)0x4u)); /* test byte ptr [ebx + 0x1000f441], 4 */
    if (c->zf) goto L_00b95da0; /* je 0xb95da0 */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
L_00b95da0:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    goto L_00b95db6; /* jmp 0xb95db6 */
L_00b95da7:;
    c->edx = (uint32_t)((uint32_t)((uint8_t)c->edx)); /* movzx edx, dl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edx + 0xb9f441u)) & (uint8_t)0x4u)); /* test byte ptr [edx + 0x1000f441], 4 */
    if (c->zf) goto L_00b95db6; /* je 0xb95db6 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
L_00b95db6:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
L_00b95db8:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_00b95d16; /* jmp 0xb95d16 */
L_00b95dbe:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00b95dc6; /* je 0xb95dc6 */
    { uint32_t a_ = (uint32_t)(c->esi); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [esi], 0 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_00b95dc6:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    goto L_00b95ce4; /* jmp 0xb95ce4 */
L_00b95dcd:;
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00b95dd4; /* je 0xb95dd4 */
    { uint32_t a_ = (uint32_t)(c->edi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [edi], 0 */
L_00b95dd4:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [eax] */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00b95dde(CPU *c) { /* FUN_10005dde */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9f178u))); /* mov eax, dword ptr [0x1000f178] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(0xb9b088u))); /* mov ebp, dword ptr [0x1000b088] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (!c->zf) goto L_00b95e2c; /* jne 0xb95e2c */
    { uint32_t t_ = c->ebp; PUSH32(c, 0x00b95dfbu); call_indirect(c, t_); } /* call ebp */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (c->zf) goto L_00b95e0d; /* je 0xb95e0d */
    W32((uint32_t)(0xb9f178u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x1000f178], 1 */
    goto L_00b95e35; /* jmp 0xb95e35 */
L_00b95e0d:;
    { uint32_t t_ = R32((uint32_t)(0xb9b084u)); PUSH32(c, 0x00b95e13u); call_indirect(c, t_); } /* call dword ptr [0x1000b084] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    if (c->zf) goto L_00b95f07; /* je 0xb95f07 */
    W32((uint32_t)(0xb9f178u), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [0x1000f178], 2 */
    goto L_00b95ebb; /* jmp 0xb95ebb */
L_00b95e2c:;
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_00b95eb6; /* jne 0xb95eb6 */
L_00b95e35:;
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (!c->zf) goto L_00b95e45; /* jne 0xb95e45 */
    { uint32_t t_ = c->ebp; PUSH32(c, 0x00b95e3bu); call_indirect(c, t_); } /* call ebp */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (c->zf) goto L_00b95f07; /* je 0xb95f07 */
L_00b95e45:;
    (void)sub16(c, R16((uint32_t)(c->esi)), ((uint16_t)c->ebx)); /* cmp word ptr [esi], bx */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    if (c->zf) goto L_00b95e5a; /* je 0xb95e5a */
L_00b95e4c:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub16(c, R16((uint32_t)(c->eax)), ((uint16_t)c->ebx)); /* cmp word ptr [eax], bx */
    if (!c->zf) goto L_00b95e4c; /* jne 0xb95e4c */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub16(c, R16((uint32_t)(c->eax)), ((uint16_t)c->ebx)); /* cmp word ptr [eax], bx */
    if (!c->zf) goto L_00b95e4c; /* jne 0xb95e4c */
L_00b95e5a:;
    c->eax = (uint32_t)(sub32(c, c->eax, c->esi)); /* sub eax, esi */
    c->edi = (uint32_t)(R32((uint32_t)(0xb9b080u))); /* mov edi, dword ptr [0x1000b080] */
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
    { uint32_t t_ = c->edi; PUSH32(c, 0x00b95e73u); call_indirect(c, t_); } /* call edi */
    c->ebp = (uint32_t)(c->eax); /* mov ebp, eax */
    (void)sub32(c, c->ebp, c->ebx); /* cmp ebp, ebx */
    if (c->zf) goto L_00b95eab; /* je 0xb95eab */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x00b95e7fu); f_00b9500a(c); /* call 0xb9500a */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    if (c->zf) goto L_00b95eab; /* je 0xb95eab */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x24u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x24] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00b95e95u); call_indirect(c, t_); } /* call edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b95ea7; /* jne 0xb95ea7 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    PUSH32(c, 0x00b95ea2u); f_00b956ee(c); /* call 0xb956ee */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x10], ebx */
L_00b95ea7:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ebx, dword ptr [esp + 0x10] */
L_00b95eab:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(0xb9b07cu)); PUSH32(c, 0x00b95eb2u); call_indirect(c, t_); } /* call dword ptr [0x1000b07c] */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    goto L_00b95f09; /* jmp 0xb95f09 */
L_00b95eb6:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00b95f07; /* jne 0xb95f07 */
L_00b95ebb:;
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    if (!c->zf) goto L_00b95ecb; /* jne 0xb95ecb */
    { uint32_t t_ = R32((uint32_t)(0xb9b084u)); PUSH32(c, 0x00b95ec5u); call_indirect(c, t_); } /* call dword ptr [0x1000b084] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    if (c->zf) goto L_00b95f07; /* je 0xb95f07 */
L_00b95ecb:;
    (void)sub8(c, R8((uint32_t)(c->edi)), ((uint8_t)c->ebx)); /* cmp byte ptr [edi], bl */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    if (c->zf) goto L_00b95edb; /* je 0xb95edb */
L_00b95ed1:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), ((uint8_t)c->ebx)); /* cmp byte ptr [eax], bl */
    if (!c->zf) goto L_00b95ed1; /* jne 0xb95ed1 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), ((uint8_t)c->ebx)); /* cmp byte ptr [eax], bl */
    if (!c->zf) goto L_00b95ed1; /* jne 0xb95ed1 */
L_00b95edb:;
    c->eax = (uint32_t)(sub32(c, c->eax, c->edi)); /* sub eax, edi */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ebp = (uint32_t)(c->eax); /* mov ebp, eax */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x00b95ee6u); f_00b9500a(c); /* call 0xb9500a */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (!c->zf) goto L_00b95ef1; /* jne 0xb95ef1 */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    goto L_00b95efc; /* jmp 0xb95efc */
L_00b95ef1:;
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b95ef9u); f_00b97b10(c); /* call 0xb97b10 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_00b95efc:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0xb9b078u)); PUSH32(c, 0x00b95f03u); call_indirect(c, t_); } /* call dword ptr [0x1000b078] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    goto L_00b95f09; /* jmp 0xb95f09 */
L_00b95f07:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00b95f09:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00b95f10(CPU *c) { /* FUN_10005f10 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi], 0 */
    { uint32_t t_ = R32((uint32_t)(0xb9b048u)); PUSH32(c, 0x00b95f20u); call_indirect(c, t_); } /* call dword ptr [0x1000b048] */
    (void)sub16(c, R16((uint32_t)(c->eax)), (uint16_t)0x5a4du); /* cmp word ptr [eax], 0x5a4d */
    if (!c->zf) goto L_00b95f3b; /* jne 0xb95f3b */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x3cu))); /* mov ecx, dword ptr [eax + 0x3c] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00b95f3b; /* je 0xb95f3b */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1au))); /* mov cl, byte ptr [eax + 0x1a] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esi], cl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1bu))); /* mov al, byte ptr [eax + 0x1b] */
    W8((uint32_t)(c->esi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [esi + 1], al */
L_00b95f3b:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b95f3d(CPU *c) { /* FUN_10005f3d */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->eax = (uint32_t)((uint32_t)0x122cu); /* mov eax, 0x122c */
    PUSH32(c, 0x00b95f4au); f_00b99050(c); /* call 0xb99050 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff68u)); /* lea eax, [ebp - 0x98] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(c->ebp + 0xffffff68u), (uint32_t)((uint32_t)0x94u)); /* mov dword ptr [ebp - 0x98], 0x94 */
    { uint32_t t_ = R32((uint32_t)(0xb9b090u)); PUSH32(c, 0x00b95f62u); call_indirect(c, t_); } /* call dword ptr [0x1000b090] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b95f80; /* je 0xb95f80 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffff78u)), (uint32_t)0x2u); /* cmp dword ptr [ebp - 0x88], 2 */
    if (!c->zf) goto L_00b95f80; /* jne 0xb95f80 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffff6cu)), (uint32_t)0x5u); /* cmp dword ptr [ebp - 0x94], 5 */
    if (c->cf) goto L_00b95f80; /* jb 0xb95f80 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_00b96082; /* jmp 0xb96082 */
L_00b95f80:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffedd4u)); /* lea eax, [ebp - 0x122c] */
    { uint32_t v_ = 0x1090u; PUSH32(c, v_); } /* push 0x1090 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0xb9b2e0u; PUSH32(c, v_); } /* push 0x1000b2e0 */
    { uint32_t t_ = R32((uint32_t)(0xb9b08cu)); PUSH32(c, 0x00b95f97u); call_indirect(c, t_); } /* call dword ptr [0x1000b08c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b9606f; /* je 0xb9606f */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffedd4u)); /* lea ecx, [ebp - 0x122c] */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xffffedd4u)), ((uint8_t)c->ebx)); /* cmp byte ptr [ebp - 0x122c], bl */
    if (c->zf) goto L_00b95fc2; /* je 0xb95fc2 */
L_00b95faf:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov al, byte ptr [ecx] */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x61u); /* cmp al, 0x61 */
    if ((c->sf != c->of)) goto L_00b95fbd; /* jl 0xb95fbd */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x7au); /* cmp al, 0x7a */
    if ((!c->zf && c->sf == c->of)) goto L_00b95fbd; /* jg 0xb95fbd */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sub8(c, ((uint8_t)c->eax), (uint8_t)0x20u)); /* sub al, 0x20 */
    W8((uint32_t)(c->ecx), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ecx], al */
L_00b95fbd:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub8(c, R8((uint32_t)(c->ecx)), ((uint8_t)c->ebx)); /* cmp byte ptr [ecx], bl */
    if (!c->zf) goto L_00b95faf; /* jne 0xb95faf */
L_00b95fc2:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffedd4u)); /* lea eax, [ebp - 0x122c] */
    { uint32_t v_ = 0x16u; PUSH32(c, v_); } /* push 0x16 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0xb9b2c8u; PUSH32(c, v_); } /* push 0x1000b2c8 */
    PUSH32(c, 0x00b95fd5u); f_00b99010(c); /* call 0xb99010 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b95fe4; /* jne 0xb95fe4 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffedd4u)); /* lea eax, [ebp - 0x122c] */
    goto L_00b9602d; /* jmp 0xb9602d */
L_00b95fe4:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe64u)); /* lea eax, [ebp - 0x19c] */
    { uint32_t v_ = 0x104u; PUSH32(c, v_); } /* push 0x104 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(0xb9b074u)); PUSH32(c, 0x00b95ff7u); call_indirect(c, t_); } /* call dword ptr [0x1000b074] */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xfffffe64u)), ((uint8_t)c->ebx)); /* cmp byte ptr [ebp - 0x19c], bl */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffe64u)); /* lea ecx, [ebp - 0x19c] */
    if (c->zf) goto L_00b96018; /* je 0xb96018 */
L_00b96005:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov al, byte ptr [ecx] */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x61u); /* cmp al, 0x61 */
    if ((c->sf != c->of)) goto L_00b96013; /* jl 0xb96013 */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x7au); /* cmp al, 0x7a */
    if ((!c->zf && c->sf == c->of)) goto L_00b96013; /* jg 0xb96013 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sub8(c, ((uint8_t)c->eax), (uint8_t)0x20u)); /* sub al, 0x20 */
    W8((uint32_t)(c->ecx), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ecx], al */
L_00b96013:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub8(c, R8((uint32_t)(c->ecx)), ((uint8_t)c->ebx)); /* cmp byte ptr [ecx], bl */
    if (!c->zf) goto L_00b96005; /* jne 0xb96005 */
L_00b96018:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe64u)); /* lea eax, [ebp - 0x19c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffedd4u)); /* lea eax, [ebp - 0x122c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b9602bu); f_00b98f90(c); /* call 0xb98f90 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b9602d:;
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_00b9606f; /* je 0xb9606f */
    { uint32_t v_ = 0x2cu; PUSH32(c, v_); } /* push 0x2c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b96039u); f_00b98ed0(c); /* call 0xb98ed0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00b9606f; /* je 0xb9606f */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), ((uint8_t)c->ebx)); /* cmp byte ptr [eax], bl */
    if (c->zf) goto L_00b96054; /* je 0xb96054 */
L_00b96046:;
    (void)sub8(c, R8((uint32_t)(c->ecx)), (uint8_t)0x3bu); /* cmp byte ptr [ecx], 0x3b */
    if (!c->zf) goto L_00b9604f; /* jne 0xb9604f */
    W8((uint32_t)(c->ecx), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ecx], bl */
    goto L_00b96050; /* jmp 0xb96050 */
L_00b9604f:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
L_00b96050:;
    (void)sub8(c, R8((uint32_t)(c->ecx)), ((uint8_t)c->ebx)); /* cmp byte ptr [ecx], bl */
    if (!c->zf) goto L_00b96046; /* jne 0xb96046 */
L_00b96054:;
    { uint32_t v_ = 0xau; PUSH32(c, v_); } /* push 0xa */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b9605du); f_00b98c98(c); /* call 0xb98c98 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (c->zf) goto L_00b96082; /* je 0xb96082 */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (c->zf) goto L_00b96082; /* je 0xb96082 */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_00b96082; /* je 0xb96082 */
L_00b9606f:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b96078u); f_00b95f10(c); /* call 0xb95f10 */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xfffffffcu)), (uint8_t)0x6u); /* cmp byte ptr [ebp - 4], 6 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x3u)); /* add eax, 3 */
L_00b96082:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b96085(CPU *c) { /* FUN_10006085 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    (void)sub32(c, R32((uint32_t)(c->esp + 0x8u)), c->eax); /* cmp dword ptr [esp + 8], eax */
    { uint32_t v_ = 0x1000u; PUSH32(c, v_); } /* push 0x1000 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete al */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0xb9b098u)); PUSH32(c, 0x00b9609cu); call_indirect(c, t_); } /* call dword ptr [0x1000b098] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(0xb9f564u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000f564], eax */
    if (c->zf) goto L_00b960db; /* je 0xb960db */
    PUSH32(c, 0x00b960aau); f_00b95f3d(c); /* call 0xb95f3d */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    W32((uint32_t)(0xb9f568u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000f568], eax */
    if (!c->zf) goto L_00b960c1; /* jne 0xb960c1 */
    { uint32_t v_ = 0x3f8u; PUSH32(c, v_); } /* push 0x3f8 */
    PUSH32(c, 0x00b960beu); f_00b968d9(c); /* call 0xb968d9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00b960cb; /* jmp 0xb960cb */
L_00b960c1:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00b960de; /* jne 0xb960de */
    PUSH32(c, 0x00b960cbu); f_00b97420(c); /* call 0xb97420 */
L_00b960cb:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b960de; /* jne 0xb960de */
    { uint32_t v_ = R32((uint32_t)(0xb9f564u)); PUSH32(c, v_); } /* push dword ptr [0x1000f564] */
    { uint32_t t_ = R32((uint32_t)(0xb9b094u)); PUSH32(c, 0x00b960dbu); call_indirect(c, t_); } /* call dword ptr [0x1000b094] */
L_00b960db:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_00b960de:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_00b960e2(CPU *c) { /* FUN_100060e2 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0xb9f568u))); /* mov eax, dword ptr [0x1000f568] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00b96154; /* jne 0xb96154 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, R32((uint32_t)(0xb9f558u)), c->ebx); /* cmp dword ptr [0x1000f558], ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(0xb9b05cu))); /* mov ebp, dword ptr [0x1000b05c] */
    if ((c->zf || c->sf != c->of)) goto L_00b96140; /* jle 0xb96140 */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9f55cu))); /* mov eax, dword ptr [0x1000f55c] */
    c->edi = (uint32_t)(R32((uint32_t)(0xb9b09cu))); /* mov edi, dword ptr [0x1000b09c] */
    c->esi = (uint32_t)((uint32_t)(c->eax + 0xcu)); /* lea esi, [eax + 0xc] */
L_00b9610e:;
    { uint32_t v_ = 0x4000u; PUSH32(c, v_); } /* push 0x4000 */
    { uint32_t v_ = 0x100000u; PUSH32(c, v_); } /* push 0x100000 */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00b9611cu); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = 0x8000u; PUSH32(c, v_); } /* push 0x8000 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00b96127u); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esi + 4] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb9f564u)); PUSH32(c, v_); } /* push dword ptr [0x1000f564] */
    { uint32_t t_ = c->ebp; PUSH32(c, 0x00b96134u); call_indirect(c, t_); } /* call ebp */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x14u)); /* add esi, 0x14 */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    (void)sub32(c, c->ebx, R32((uint32_t)(0xb9f558u))); /* cmp ebx, dword ptr [0x1000f558] */
    if ((c->sf != c->of)) goto L_00b9610e; /* jl 0xb9610e */
L_00b96140:;
    { uint32_t v_ = R32((uint32_t)(0xb9f55cu)); PUSH32(c, v_); } /* push dword ptr [0x1000f55c] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb9f564u)); PUSH32(c, v_); } /* push dword ptr [0x1000f564] */
    { uint32_t t_ = c->ebp; PUSH32(c, 0x00b96150u); call_indirect(c, t_); } /* call ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    goto L_00b9617b; /* jmp 0xb9617b */
L_00b96154:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00b9617b; /* jne 0xb9617b */
    c->edi = (uint32_t)((uint32_t)0xb9c4b8u); /* mov edi, 0x1000c4b8 */
    c->esi = (uint32_t)(c->edi); /* mov esi, edi */
L_00b96160:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b96175; /* je 0xb96175 */
    { uint32_t v_ = 0x8000u; PUSH32(c, v_); } /* push 0x8000 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0xb9b09cu)); PUSH32(c, 0x00b96175u); call_indirect(c, t_); } /* call dword ptr [0x1000b09c] */
L_00b96175:;
    c->esi = (uint32_t)(R32((uint32_t)(c->esi))); /* mov esi, dword ptr [esi] */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_00b96160; /* jne 0xb96160 */
L_00b9617b:;
    { uint32_t v_ = R32((uint32_t)(0xb9f564u)); PUSH32(c, v_); } /* push dword ptr [0x1000f564] */
    { uint32_t t_ = R32((uint32_t)(0xb9b094u)); PUSH32(c, 0x00b96187u); call_indirect(c, t_); } /* call dword ptr [0x1000b094] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b9618a(CPU *c) { /* FUN_1000618a */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 16; return; /* ret 0xc */
}

void f_00b96190(CPU *c) { /* FUN_10006190 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0xb9efc4u))); /* mov eax, dword ptr [0x1000efc4] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_00b961a7; /* je 0xb961a7 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b961c8; /* jne 0xb961c8 */
    (void)sub32(c, R32((uint32_t)(0xb9efc8u)), (uint32_t)0x1u); /* cmp dword ptr [0x1000efc8], 1 */
    if (!c->zf) goto L_00b961c8; /* jne 0xb961c8 */
L_00b961a7:;
    { uint32_t v_ = 0xfcu; PUSH32(c, v_); } /* push 0xfc */
    PUSH32(c, 0x00b961b1u); f_00b961c9(c); /* call 0xb961c9 */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9f17cu))); /* mov eax, dword ptr [0x1000f17c] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b961bd; /* je 0xb961bd */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00b961bdu); call_indirect(c, t_); } /* call eax */
L_00b961bd:;
    { uint32_t v_ = 0xffu; PUSH32(c, v_); } /* push 0xff */
    PUSH32(c, 0x00b961c7u); f_00b961c9(c); /* call 0xb961c9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b961c8:;
    c->esp += 4; return; /* ret  */
}

void f_00b961c9(CPU *c) { /* FUN_100061c9 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x1a4u)); /* sub esp, 0x1a4 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->eax = (uint32_t)((uint32_t)0xb9c398u); /* mov eax, 0x1000c398 */
L_00b961dc:;
    (void)sub32(c, c->edx, R32((uint32_t)(c->eax))); /* cmp edx, dword ptr [eax] */
    if (c->zf) goto L_00b961eb; /* je 0xb961eb */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->eax, (uint32_t)0xb9c428u); /* cmp eax, 0x1000c428 */
    if ((c->sf != c->of)) goto L_00b961dc; /* jl 0xb961dc */
L_00b961eb:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->esi = (uint32_t)(shl32(c, c->esi, 3)); /* shl esi, 3 */
    (void)sub32(c, c->edx, R32((uint32_t)(c->esi + 0xb9c398u))); /* cmp edx, dword ptr [esi + 0x1000c398] */
    if (!c->zf) goto L_00b96319; /* jne 0xb96319 */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9efc4u))); /* mov eax, dword ptr [0x1000efc4] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_00b962f3; /* je 0xb962f3 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b9621c; /* jne 0xb9621c */
    (void)sub32(c, R32((uint32_t)(0xb9efc8u)), (uint32_t)0x1u); /* cmp dword ptr [0x1000efc8], 1 */
    if (c->zf) goto L_00b962f3; /* je 0xb962f3 */
L_00b9621c:;
    (void)sub32(c, c->edx, (uint32_t)0xfcu); /* cmp edx, 0xfc */
    if (c->zf) goto L_00b96319; /* je 0xb96319 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea eax, [ebp - 0x1a4] */
    { uint32_t v_ = 0x104u; PUSH32(c, v_); } /* push 0x104 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t t_ = R32((uint32_t)(0xb9b074u)); PUSH32(c, 0x00b9623cu); call_indirect(c, t_); } /* call dword ptr [0x1000b074] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b96253; /* jne 0xb96253 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea eax, [ebp - 0x1a4] */
    { uint32_t v_ = 0xb9b5d0u; PUSH32(c, v_); } /* push 0x1000b5d0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b96251u); f_00b986d0(c); /* call 0xb986d0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b96253:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea eax, [ebp - 0x1a4] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea edi, [ebp - 0x1a4] */
    PUSH32(c, 0x00b96266u); f_00b98820(c); /* call 0xb98820 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->eax, (uint32_t)0x3cu); /* cmp eax, 0x3c */
    if ((c->cf || c->zf)) goto L_00b96296; /* jbe 0xb96296 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea eax, [ebp - 0x1a4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b96279u); f_00b98820(c); /* call 0xb98820 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea eax, [ebp - 0x1a4] */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3bu)); /* sub eax, 0x3b */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t v_ = 0xb9b5ccu; PUSH32(c, v_); } /* push 0x1000b5cc */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b96293u); f_00b99110(c); /* call 0xb99110 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_00b96296:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff60u)); /* lea eax, [ebp - 0xa0] */
    { uint32_t v_ = 0xb9b5b0u; PUSH32(c, v_); } /* push 0x1000b5b0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b962a7u); f_00b986d0(c); /* call 0xb986d0 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff60u)); /* lea eax, [ebp - 0xa0] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b962b4u); f_00b986e0(c); /* call 0xb986e0 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff60u)); /* lea eax, [ebp - 0xa0] */
    { uint32_t v_ = 0xb9b5acu; PUSH32(c, v_); } /* push 0x1000b5ac */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b962c5u); f_00b986e0(c); /* call 0xb986e0 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0xb9c39cu)); PUSH32(c, v_); } /* push dword ptr [esi + 0x1000c39c] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff60u)); /* lea eax, [ebp - 0xa0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b962d7u); f_00b986e0(c); /* call 0xb986e0 */
    { uint32_t v_ = 0x12010u; PUSH32(c, v_); } /* push 0x12010 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff60u)); /* lea eax, [ebp - 0xa0] */
    { uint32_t v_ = 0xb9b584u; PUSH32(c, v_); } /* push 0x1000b584 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b962edu); f_00b9907f(c); /* call 0xb9907f */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    goto L_00b96319; /* jmp 0xb96319 */
L_00b962f3:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x8u)); /* lea eax, [ebp + 8] */
    c->esi = (uint32_t)((uint32_t)(c->esi + 0xb9c39cu)); /* lea esi, [esi + 0x1000c39c] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    PUSH32(c, 0x00b96306u); f_00b98820(c); /* call 0xb98820 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    { uint32_t v_ = 0xfffffff4u; PUSH32(c, v_); } /* push -0xc */
    { uint32_t t_ = R32((uint32_t)(0xb9b068u)); PUSH32(c, 0x00b96312u); call_indirect(c, t_); } /* call dword ptr [0x1000b068] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0xb9b0a0u)); PUSH32(c, 0x00b96319u); call_indirect(c, t_); } /* call dword ptr [0x1000b0a0] */
L_00b96319:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b9631c(CPU *c) { /* FUN_1000631c */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    { uint32_t t_ = R32((uint32_t)(0xb9b0a4u)); PUSH32(c, 0x00b9632eu); call_indirect(c, t_); } /* call dword ptr [0x1000b0a4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b96334; /* je 0xb96334 */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_00b96334:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b96338(CPU *c) { /* FUN_10006338 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    { uint32_t t_ = R32((uint32_t)(0xb9b0a8u)); PUSH32(c, 0x00b9634au); call_indirect(c, t_); } /* call dword ptr [0x1000b0a8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b96350; /* je 0xb96350 */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_00b96350:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b96354(CPU *c) { /* FUN_10006354 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    { uint32_t t_ = R32((uint32_t)(0xb9b0acu)); PUSH32(c, 0x00b96362u); call_indirect(c, t_); } /* call dword ptr [0x1000b0ac] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b96368; /* je 0xb96368 */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_00b96368:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b9636c(CPU *c) { /* PTR_00b9636c */
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
    if (!c->zf) goto L_00b96414; /* jne 0xb96414 */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    W32((uint32_t)(c->ebx + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebx - 4], eax */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebx + 0xcu))); /* mov esi, dword ptr [ebx + 0xc] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov edi, dword ptr [ebx + 8] */
L_00b963a7:;
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (c->zf) goto L_00b9640d; /* je 0xb9640d */
    c->ecx = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea ecx, [esi + esi*2] */
    (void)sub32(c, R32((uint32_t)(c->edi + c->ecx * 4 + 0x4u)), (uint32_t)0x0u); /* cmp dword ptr [edi + ecx*4 + 4], 0 */
    if (c->zf) goto L_00b963fb; /* je 0xb963fb */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)((uint32_t)(c->ebx + 0x10u)); /* lea ebp, [ebx + 0x10] */
    { uint32_t t_ = R32((uint32_t)(c->edi + c->ecx * 4 + 0x4u)); PUSH32(c, 0x00b963bfu); call_indirect(c, t_); } /* call dword ptr [edi + ecx*4 + 4] */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ebx, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->eax))); /* or eax, eax */
    if (c->zf) goto L_00b963fb; /* je 0xb963fb */
    if (c->sf) goto L_00b96406; /* js 0xb96406 */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov edi, dword ptr [ebx + 8] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b963d3u); f_00b93bd8(c); /* call 0xb93bd8 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->ebp = (uint32_t)((uint32_t)(c->ebx + 0x10u)); /* lea ebp, [ebx + 0x10] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b963e0u); f_00b93c1a(c); /* call 0xb93c1a */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea ecx, [esi + esi*2] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + c->ecx * 4 + 0x8u))); /* mov eax, dword ptr [edi + ecx*4 + 8] */
    PUSH32(c, 0x00b963f1u); f_00b93cae(c); /* call 0xb93cae */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + c->ecx * 4))); /* mov eax, dword ptr [edi + ecx*4] */
    W32((uint32_t)(c->ebx + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 0xc], eax */
    { uint32_t t_ = R32((uint32_t)(c->edi + c->ecx * 4 + 0x8u)); PUSH32(c, 0x00b963fbu); call_indirect(c, t_); } /* call dword ptr [edi + ecx*4 + 8] */
L_00b963fb:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov edi, dword ptr [ebx + 8] */
    c->ecx = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea ecx, [esi + esi*2] */
    c->esi = (uint32_t)(R32((uint32_t)(c->edi + c->ecx * 4))); /* mov esi, dword ptr [edi + ecx*4] */
    goto L_00b963a7; /* jmp 0xb963a7 */
L_00b96406:;
    c->eax = (uint32_t)((uint32_t)0x0u); /* mov eax, 0 */
    goto L_00b96429; /* jmp 0xb96429 */
L_00b9640d:;
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    goto L_00b96429; /* jmp 0xb96429 */
L_00b96414:;
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)((uint32_t)(c->ebx + 0x10u)); /* lea ebp, [ebx + 0x10] */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b96420u); f_00b93c1a(c); /* call 0xb93c1a */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
L_00b96429:;
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00b96431(CPU *c) { /* FUN_10006431 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov ebp, dword ptr [ecx] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x1cu))); /* mov eax, dword ptr [ecx + 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x18u))); /* mov eax, dword ptr [ecx + 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b96445u); f_00b93c1a(c); /* call 0xb93c1a */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 8; return; /* ret 4 */
}

void f_00b96450(CPU *c) { /* FUN_10006450 */
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
    if ((c->cf || c->zf)) goto L_00b96470; /* jbe 0xb96470 */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_00b965e8; /* jb 0xb965e8 */
L_00b96470:;
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x3u)); /* test edi, 3 */
    if (!c->zf) goto L_00b9648c; /* jne 0xb9648c */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u))); /* and edx, 3 */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) goto L_00b964ac; /* jb 0xb964ac */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb96598u)); switch (t_) { case 0x00b965a8u: goto L_00b965a8; case 0x00b965b0u: goto L_00b965b0; case 0x00b965bcu: goto L_00b965bc; case 0x00b965d0u: goto L_00b965d0; default: jump_indirect(c, t_, 0x00b96485u); return; } } /* jmp dword ptr [edx*4 + 0x10006598] */
L_00b9648c:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edx = (uint32_t)((uint32_t)0x3u); /* mov edx, 3 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x4u)); /* sub ecx, 4 */
    if (c->cf) goto L_00b964a4; /* jb 0xb964a4 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x3u))); /* and eax, 3 */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->eax * 4 + 0xb964b0u)); switch (t_) {  default: jump_indirect(c, t_, 0x00b9649du); return; } } /* jmp dword ptr [eax*4 + 0x100064b0] */
L_00b964a4:;
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0xb965a8u)); switch (t_) {  default: jump_indirect(c, t_, 0x00b964a4u); return; } } /* jmp dword ptr [ecx*4 + 0x100065a8] */
L_00b964ac:;
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0xb9652cu)); switch (t_) { case 0x00b9654cu: goto L_00b9654c; case 0x00b96554u: goto L_00b96554; case 0x00b9655cu: goto L_00b9655c; case 0x00b96564u: goto L_00b96564; case 0x00b9656cu: goto L_00b9656c; case 0x00b96574u: goto L_00b96574; case 0x00b9657cu: goto L_00b9657c; case 0x00b9658fu: goto L_00b9658f; default: jump_indirect(c, t_, 0x00b964acu); return; } } /* jmp dword ptr [ecx*4 + 0x1000652c] */
L_00b9654c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe4u))); /* mov eax, dword ptr [esi + ecx*4 - 0x1c] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x1c], eax */
L_00b96554:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe8u))); /* mov eax, dword ptr [esi + ecx*4 - 0x18] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x18], eax */
L_00b9655c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffecu))); /* mov eax, dword ptr [esi + ecx*4 - 0x14] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffecu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x14], eax */
L_00b96564:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff0u))); /* mov eax, dword ptr [esi + ecx*4 - 0x10] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x10], eax */
L_00b9656c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff4u))); /* mov eax, dword ptr [esi + ecx*4 - 0xc] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0xc], eax */
L_00b96574:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff8u))); /* mov eax, dword ptr [esi + ecx*4 - 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 8], eax */
L_00b9657c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
L_00b9658f:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb96598u)); switch (t_) { case 0x00b965a8u: goto L_00b965a8; case 0x00b965b0u: goto L_00b965b0; case 0x00b965bcu: goto L_00b965bc; case 0x00b965d0u: goto L_00b965d0; default: jump_indirect(c, t_, 0x00b9658fu); return; } } /* jmp dword ptr [edx*4 + 0x10006598] */
L_00b965a8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b965b0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b965bc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b965d0:;
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
L_00b965e8:;
    c->esi = (uint32_t)((uint32_t)(c->ecx + c->esi + 0xfffffffcu)); /* lea esi, [ecx + esi - 4] */
    c->edi = (uint32_t)((uint32_t)(c->ecx + c->edi + 0xfffffffcu)); /* lea edi, [ecx + edi - 4] */
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x3u)); /* test edi, 3 */
    if (!c->zf) goto L_00b9661c; /* jne 0xb9661c */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u))); /* and edx, 3 */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) goto L_00b96610; /* jb 0xb96610 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb96730u)); switch (t_) { case 0x00b96740u: goto L_00b96740; case 0x00b96748u: goto L_00b96748; case 0x00b96758u: goto L_00b96758; case 0x00b9676cu: goto L_00b9676c; default: jump_indirect(c, t_, 0x00b96607u); return; } } /* jmp dword ptr [edx*4 + 0x10006730] */
L_00b96610:;
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0xb966e0u)); switch (t_) { case 0x00b96727u: goto L_00b96727; default: jump_indirect(c, t_, 0x00b96612u); return; } } /* jmp dword ptr [ecx*4 + 0x100066e0] */
L_00b9661c:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edx = (uint32_t)((uint32_t)0x3u); /* mov edx, 3 */
    (void)sub32(c, c->ecx, (uint32_t)0x4u); /* cmp ecx, 4 */
    if (c->cf) goto L_00b96634; /* jb 0xb96634 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x3u))); /* and eax, 3 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->eax * 4 + 0xb96638u)); switch (t_) {  default: jump_indirect(c, t_, 0x00b9662du); return; } } /* jmp dword ptr [eax*4 + 0x10006638] */
L_00b96634:;
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0xb96730u)); switch (t_) { case 0x00b96740u: goto L_00b96740; case 0x00b96748u: goto L_00b96748; case 0x00b96758u: goto L_00b96758; case 0x00b9676cu: goto L_00b9676c; default: jump_indirect(c, t_, 0x00b96634u); return; } } /* jmp dword ptr [ecx*4 + 0x10006730] */
L_00b96727:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb96730u)); switch (t_) { case 0x00b96740u: goto L_00b96740; case 0x00b96748u: goto L_00b96748; case 0x00b96758u: goto L_00b96758; case 0x00b9676cu: goto L_00b9676c; default: jump_indirect(c, t_, 0x00b96727u); return; } } /* jmp dword ptr [edx*4 + 0x10006730] */
L_00b96740:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b96748:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b96758:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b9676c:;
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

void f_00b964ac(CPU *c) { /* PTR_00b964ac */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0xb9652cu)); switch (t_) { case 0x00b9654cu: goto L_00b9654c; case 0x00b96554u: goto L_00b96554; case 0x00b9655cu: goto L_00b9655c; case 0x00b96564u: goto L_00b96564; case 0x00b9656cu: goto L_00b9656c; case 0x00b96574u: goto L_00b96574; case 0x00b9657cu: goto L_00b9657c; case 0x00b9658fu: goto L_00b9658f; default: jump_indirect(c, t_, 0x00b964acu); return; } } /* jmp dword ptr [ecx*4 + 0x1000652c] */
L_00b9654c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe4u))); /* mov eax, dword ptr [esi + ecx*4 - 0x1c] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x1c], eax */
L_00b96554:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe8u))); /* mov eax, dword ptr [esi + ecx*4 - 0x18] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x18], eax */
L_00b9655c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffecu))); /* mov eax, dword ptr [esi + ecx*4 - 0x14] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffecu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x14], eax */
L_00b96564:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff0u))); /* mov eax, dword ptr [esi + ecx*4 - 0x10] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x10], eax */
L_00b9656c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff4u))); /* mov eax, dword ptr [esi + ecx*4 - 0xc] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0xc], eax */
L_00b96574:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff8u))); /* mov eax, dword ptr [esi + ecx*4 - 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 8], eax */
L_00b9657c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
L_00b9658f:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb96598u)); switch (t_) { case 0x00b965a8u: goto L_00b965a8; case 0x00b965b0u: goto L_00b965b0; case 0x00b965bcu: goto L_00b965bc; case 0x00b965d0u: goto L_00b965d0; default: jump_indirect(c, t_, 0x00b9658fu); return; } } /* jmp dword ptr [edx*4 + 0x10006598] */
L_00b965a8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b965b0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b965bc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b965d0:;
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

void f_00b964c0(CPU *c) { /* PTR_00b964c0 */
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
    if (c->cf) { f_00b964ac(c); return; } /* jb 0xb964ac */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb96598u)); switch (t_) { case 0x00b965a8u: goto L_00b965a8; case 0x00b965b0u: goto L_00b965b0; case 0x00b965bcu: goto L_00b965bc; case 0x00b965d0u: goto L_00b965d0; default: jump_indirect(c, t_, 0x00b964e2u); return; } } /* jmp dword ptr [edx*4 + 0x10006598] */
L_00b965a8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b965b0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b965bc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b965d0:;
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

void f_00b964e0(CPU *c) { /* PTR_00b964e0 */
    PREEMPT_POLL(c);
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb96598u)); switch (t_) { case 0x00b965a8u: goto L_00b965a8; case 0x00b965b0u: goto L_00b965b0; case 0x00b965bcu: goto L_00b965bc; case 0x00b965d0u: goto L_00b965d0; default: jump_indirect(c, t_, 0x00b964e2u); return; } } /* jmp dword ptr [edx*4 + 0x10006598] */
L_00b965a8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b965b0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b965bc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b965d0:;
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

void f_00b964ec(CPU *c) { /* PTR_00b964ec */
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
    if (c->cf) { f_00b964ac(c); return; } /* jb 0xb964ac */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb96598u)); switch (t_) { case 0x00b965a8u: goto L_00b965a8; case 0x00b965b0u: goto L_00b965b0; case 0x00b965bcu: goto L_00b965bc; case 0x00b965d0u: goto L_00b965d0; default: jump_indirect(c, t_, 0x00b96508u); return; } } /* jmp dword ptr [edx*4 + 0x10006598] */
L_00b965a8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b965b0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b965bc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b965d0:;
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

void f_00b96510(CPU *c) { /* PTR_00b96510 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & c->ecx))); /* and edx, ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) { f_00b964ac(c); return; } /* jb 0xb964ac */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb96598u)); switch (t_) { case 0x00b965a8u: goto L_00b965a8; case 0x00b965b0u: goto L_00b965b0; case 0x00b965bcu: goto L_00b965bc; case 0x00b965d0u: goto L_00b965d0; default: jump_indirect(c, t_, 0x00b96522u); return; } } /* jmp dword ptr [edx*4 + 0x10006598] */
L_00b965a8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b965b0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b965bc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b965d0:;
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

void f_00b9654c(CPU *c) { /* PTR_00b9654c */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb96598u)); switch (t_) { case 0x00b965a8u: goto L_00b965a8; case 0x00b965b0u: goto L_00b965b0; case 0x00b965bcu: goto L_00b965bc; case 0x00b965d0u: goto L_00b965d0; default: jump_indirect(c, t_, 0x00b9658fu); return; } } /* jmp dword ptr [edx*4 + 0x10006598] */
L_00b965a8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b965b0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b965bc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b965d0:;
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

void f_00b96554(CPU *c) { /* PTR_00b96554 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb96598u)); switch (t_) { case 0x00b965a8u: goto L_00b965a8; case 0x00b965b0u: goto L_00b965b0; case 0x00b965bcu: goto L_00b965bc; case 0x00b965d0u: goto L_00b965d0; default: jump_indirect(c, t_, 0x00b9658fu); return; } } /* jmp dword ptr [edx*4 + 0x10006598] */
L_00b965a8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b965b0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b965bc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b965d0:;
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

void f_00b9655c(CPU *c) { /* PTR_00b9655c */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb96598u)); switch (t_) { case 0x00b965a8u: goto L_00b965a8; case 0x00b965b0u: goto L_00b965b0; case 0x00b965bcu: goto L_00b965bc; case 0x00b965d0u: goto L_00b965d0; default: jump_indirect(c, t_, 0x00b9658fu); return; } } /* jmp dword ptr [edx*4 + 0x10006598] */
L_00b965a8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b965b0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b965bc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b965d0:;
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

void f_00b96564(CPU *c) { /* PTR_00b96564 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb96598u)); switch (t_) { case 0x00b965a8u: goto L_00b965a8; case 0x00b965b0u: goto L_00b965b0; case 0x00b965bcu: goto L_00b965bc; case 0x00b965d0u: goto L_00b965d0; default: jump_indirect(c, t_, 0x00b9658fu); return; } } /* jmp dword ptr [edx*4 + 0x10006598] */
L_00b965a8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b965b0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b965bc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b965d0:;
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

void f_00b9656c(CPU *c) { /* PTR_00b9656c */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb96598u)); switch (t_) { case 0x00b965a8u: goto L_00b965a8; case 0x00b965b0u: goto L_00b965b0; case 0x00b965bcu: goto L_00b965bc; case 0x00b965d0u: goto L_00b965d0; default: jump_indirect(c, t_, 0x00b9658fu); return; } } /* jmp dword ptr [edx*4 + 0x10006598] */
L_00b965a8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b965b0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b965bc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b965d0:;
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

void f_00b96574(CPU *c) { /* PTR_00b96574 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff8u))); /* mov eax, dword ptr [esi + ecx*4 - 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb96598u)); switch (t_) { case 0x00b965a8u: goto L_00b965a8; case 0x00b965b0u: goto L_00b965b0; case 0x00b965bcu: goto L_00b965bc; case 0x00b965d0u: goto L_00b965d0; default: jump_indirect(c, t_, 0x00b9658fu); return; } } /* jmp dword ptr [edx*4 + 0x10006598] */
L_00b965a8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b965b0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b965bc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b965d0:;
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

void f_00b9657c(CPU *c) { /* PTR_00b9657c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb96598u)); switch (t_) { case 0x00b965a8u: goto L_00b965a8; case 0x00b965b0u: goto L_00b965b0; case 0x00b965bcu: goto L_00b965bc; case 0x00b965d0u: goto L_00b965d0; default: jump_indirect(c, t_, 0x00b9658fu); return; } } /* jmp dword ptr [edx*4 + 0x10006598] */
L_00b965a8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b965b0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b965bc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b965d0:;
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

void f_00b9658f(CPU *c) { /* PTR_00b9658f */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb96598u)); switch (t_) { case 0x00b965a8u: goto L_00b965a8; case 0x00b965b0u: goto L_00b965b0; case 0x00b965bcu: goto L_00b965bc; case 0x00b965d0u: goto L_00b965d0; default: jump_indirect(c, t_, 0x00b9658fu); return; } } /* jmp dword ptr [edx*4 + 0x10006598] */
L_00b965a8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b965b0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b965bc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b965d0:;
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

void f_00b965a8(CPU *c) { /* PTR_00b965a8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b965b0(CPU *c) { /* PTR_00b965b0 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b965bc(CPU *c) { /* PTR_00b965bc */
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

void f_00b965d0(CPU *c) { /* PTR_00b965d0 */
    PREEMPT_POLL(c);
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

void f_00b96610(CPU *c) { /* PTR_00b96610 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0xb966e0u)); switch (t_) { case 0x00b96727u: goto L_00b96727; default: jump_indirect(c, t_, 0x00b96612u); return; } } /* jmp dword ptr [ecx*4 + 0x100066e0] */
L_00b96727:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb96730u)); switch (t_) { case 0x00b96740u: goto L_00b96740; case 0x00b96748u: goto L_00b96748; case 0x00b96758u: goto L_00b96758; case 0x00b9676cu: goto L_00b9676c; default: jump_indirect(c, t_, 0x00b96727u); return; } } /* jmp dword ptr [edx*4 + 0x10006730] */
L_00b96740:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b96748:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b96758:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b9676c:;
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

void f_00b96648(CPU *c) { /* PTR_00b96648 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & c->ecx))); /* and edx, ecx */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) { f_00b96610(c); return; } /* jb 0xb96610 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb96730u)); switch (t_) { case 0x00b96740u: goto L_00b96740; case 0x00b96748u: goto L_00b96748; case 0x00b96758u: goto L_00b96758; case 0x00b9676cu: goto L_00b9676c; default: jump_indirect(c, t_, 0x00b9665eu); return; } } /* jmp dword ptr [edx*4 + 0x10006730] */
L_00b96740:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b96748:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b96758:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b9676c:;
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

void f_00b96668(CPU *c) { /* PTR_00b96668 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & c->ecx))); /* and edx, ecx */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->esi = (uint32_t)(sub32(c, c->esi, (uint32_t)0x2u)); /* sub esi, 2 */
    c->edi = (uint32_t)(sub32(c, c->edi, (uint32_t)0x2u)); /* sub edi, 2 */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) { f_00b96610(c); return; } /* jb 0xb96610 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb96730u)); switch (t_) { case 0x00b96740u: goto L_00b96740; case 0x00b96748u: goto L_00b96748; case 0x00b96758u: goto L_00b96758; case 0x00b9676cu: goto L_00b9676c; default: jump_indirect(c, t_, 0x00b96688u); return; } } /* jmp dword ptr [edx*4 + 0x10006730] */
L_00b96740:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b96748:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b96758:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b9676c:;
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

void f_00b96690(CPU *c) { /* PTR_00b96690 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & c->ecx))); /* and edx, ecx */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->esi = (uint32_t)(sub32(c, c->esi, (uint32_t)0x3u)); /* sub esi, 3 */
    c->edi = (uint32_t)(sub32(c, c->edi, (uint32_t)0x3u)); /* sub edi, 3 */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) { f_00b96610(c); return; } /* jb 0xb96610 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb96730u)); switch (t_) { case 0x00b96740u: goto L_00b96740; case 0x00b96748u: goto L_00b96748; case 0x00b96758u: goto L_00b96758; case 0x00b9676cu: goto L_00b9676c; default: jump_indirect(c, t_, 0x00b966bau); return; } } /* jmp dword ptr [edx*4 + 0x10006730] */
L_00b96740:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b96748:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b96758:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b9676c:;
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

void f_00b966e4(CPU *c) { /* PTR_00b966e4 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x1cu))); /* mov eax, dword ptr [esi + ecx*4 + 0x1c] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x1cu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 0x1c], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x18u))); /* mov eax, dword ptr [esi + ecx*4 + 0x18] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 0x18], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x14u))); /* mov eax, dword ptr [esi + ecx*4 + 0x14] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 0x14], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x10u))); /* mov eax, dword ptr [esi + ecx*4 + 0x10] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 0x10], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xcu))); /* mov eax, dword ptr [esi + ecx*4 + 0xc] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 0xc], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x8u))); /* mov eax, dword ptr [esi + ecx*4 + 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x4u))); /* mov eax, dword ptr [esi + ecx*4 + 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb96730u)); switch (t_) { case 0x00b96740u: goto L_00b96740; case 0x00b96748u: goto L_00b96748; case 0x00b96758u: goto L_00b96758; case 0x00b9676cu: goto L_00b9676c; default: jump_indirect(c, t_, 0x00b96727u); return; } } /* jmp dword ptr [edx*4 + 0x10006730] */
L_00b96740:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b96748:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b96758:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b9676c:;
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

void f_00b966ec(CPU *c) { /* PTR_00b966ec */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x18u))); /* mov eax, dword ptr [esi + ecx*4 + 0x18] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 0x18], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x14u))); /* mov eax, dword ptr [esi + ecx*4 + 0x14] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 0x14], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x10u))); /* mov eax, dword ptr [esi + ecx*4 + 0x10] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 0x10], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xcu))); /* mov eax, dword ptr [esi + ecx*4 + 0xc] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 0xc], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x8u))); /* mov eax, dword ptr [esi + ecx*4 + 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x4u))); /* mov eax, dword ptr [esi + ecx*4 + 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb96730u)); switch (t_) { case 0x00b96740u: goto L_00b96740; case 0x00b96748u: goto L_00b96748; case 0x00b96758u: goto L_00b96758; case 0x00b9676cu: goto L_00b9676c; default: jump_indirect(c, t_, 0x00b96727u); return; } } /* jmp dword ptr [edx*4 + 0x10006730] */
L_00b96740:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b96748:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b96758:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b9676c:;
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

void f_00b966f4(CPU *c) { /* PTR_00b966f4 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x14u))); /* mov eax, dword ptr [esi + ecx*4 + 0x14] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 0x14], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x10u))); /* mov eax, dword ptr [esi + ecx*4 + 0x10] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 0x10], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xcu))); /* mov eax, dword ptr [esi + ecx*4 + 0xc] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 0xc], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x8u))); /* mov eax, dword ptr [esi + ecx*4 + 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x4u))); /* mov eax, dword ptr [esi + ecx*4 + 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb96730u)); switch (t_) { case 0x00b96740u: goto L_00b96740; case 0x00b96748u: goto L_00b96748; case 0x00b96758u: goto L_00b96758; case 0x00b9676cu: goto L_00b9676c; default: jump_indirect(c, t_, 0x00b96727u); return; } } /* jmp dword ptr [edx*4 + 0x10006730] */
L_00b96740:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b96748:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b96758:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b9676c:;
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

void f_00b966fc(CPU *c) { /* PTR_00b966fc */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x10u))); /* mov eax, dword ptr [esi + ecx*4 + 0x10] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 0x10], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xcu))); /* mov eax, dword ptr [esi + ecx*4 + 0xc] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 0xc], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x8u))); /* mov eax, dword ptr [esi + ecx*4 + 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x4u))); /* mov eax, dword ptr [esi + ecx*4 + 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb96730u)); switch (t_) { case 0x00b96740u: goto L_00b96740; case 0x00b96748u: goto L_00b96748; case 0x00b96758u: goto L_00b96758; case 0x00b9676cu: goto L_00b9676c; default: jump_indirect(c, t_, 0x00b96727u); return; } } /* jmp dword ptr [edx*4 + 0x10006730] */
L_00b96740:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b96748:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b96758:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b9676c:;
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

void f_00b96704(CPU *c) { /* PTR_00b96704 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xcu))); /* mov eax, dword ptr [esi + ecx*4 + 0xc] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 0xc], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x8u))); /* mov eax, dword ptr [esi + ecx*4 + 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x4u))); /* mov eax, dword ptr [esi + ecx*4 + 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb96730u)); switch (t_) { case 0x00b96740u: goto L_00b96740; case 0x00b96748u: goto L_00b96748; case 0x00b96758u: goto L_00b96758; case 0x00b9676cu: goto L_00b9676c; default: jump_indirect(c, t_, 0x00b96727u); return; } } /* jmp dword ptr [edx*4 + 0x10006730] */
L_00b96740:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b96748:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b96758:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b9676c:;
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

void f_00b9670c(CPU *c) { /* PTR_00b9670c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x8u))); /* mov eax, dword ptr [esi + ecx*4 + 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x4u))); /* mov eax, dword ptr [esi + ecx*4 + 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb96730u)); switch (t_) { case 0x00b96740u: goto L_00b96740; case 0x00b96748u: goto L_00b96748; case 0x00b96758u: goto L_00b96758; case 0x00b9676cu: goto L_00b9676c; default: jump_indirect(c, t_, 0x00b96727u); return; } } /* jmp dword ptr [edx*4 + 0x10006730] */
L_00b96740:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b96748:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b96758:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b9676c:;
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

void f_00b96714(CPU *c) { /* PTR_00b96714 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x4u))); /* mov eax, dword ptr [esi + ecx*4 + 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb96730u)); switch (t_) { case 0x00b96740u: goto L_00b96740; case 0x00b96748u: goto L_00b96748; case 0x00b96758u: goto L_00b96758; case 0x00b9676cu: goto L_00b9676c; default: jump_indirect(c, t_, 0x00b96727u); return; } } /* jmp dword ptr [edx*4 + 0x10006730] */
L_00b96740:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b96748:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b96758:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b9676c:;
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

void f_00b96727(CPU *c) { /* PTR_00b96727 */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb96730u)); switch (t_) { case 0x00b96740u: goto L_00b96740; case 0x00b96748u: goto L_00b96748; case 0x00b96758u: goto L_00b96758; case 0x00b9676cu: goto L_00b9676c; default: jump_indirect(c, t_, 0x00b96727u); return; } } /* jmp dword ptr [edx*4 + 0x10006730] */
L_00b96740:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b96748:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b96758:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b9676c:;
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

void f_00b96740(CPU *c) { /* PTR_00b96740 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b96748(CPU *c) { /* PTR_00b96748 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b96758(CPU *c) { /* PTR_00b96758 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b9676c(CPU *c) { /* PTR_00b9676c */
    PREEMPT_POLL(c);
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

void f_00b96785(CPU *c) { /* FUN_10006785 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xb9b5e8u; PUSH32(c, v_); } /* push 0x1000b5e8 */
    { uint32_t v_ = 0xb96374u; PUSH32(c, v_); } /* push 0x10006374 */
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
    if ((!c->cf && !c->zf)) goto L_00b967ce; /* ja 0xb967ce */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (!c->zf) goto L_00b967c3; /* jne 0xb967c3 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00b967c3:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
    goto L_00b967d0; /* jmp 0xb967d0 */
L_00b967ce:;
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
L_00b967d0:;
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x20], ebx */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00b96884; /* ja 0xb96884 */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9f568u))); /* mov eax, dword ptr [0x1000f568] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_00b96827; /* jne 0xb96827 */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov edi, dword ptr [ebp - 0x1c] */
    (void)sub32(c, c->edi, R32((uint32_t)(0xb9f560u))); /* cmp edi, dword ptr [0x1000f560] */
    if ((!c->cf && !c->zf)) goto L_00b9686d; /* ja 0xb9686d */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b967f8u); f_00b95678(c); /* call 0xb95678 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 4], ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b96802u); f_00b96c75(c); /* call 0xb96c75 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b9680fu); f_00b9681e(c); /* call 0xb9681e */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (c->zf) goto L_00b96872; /* je 0xb96872 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x1c] */
    goto L_00b96861; /* jmp 0xb96861 */
L_00b96827:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00b9686d; /* jne 0xb9686d */
    (void)sub32(c, c->esi, R32((uint32_t)(0xb9e4dcu))); /* cmp esi, dword ptr [0x1000e4dc] */
    if ((!c->cf && !c->zf)) goto L_00b9686d; /* ja 0xb9686d */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b9683bu); f_00b95678(c); /* call 0xb95678 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b9684eu); f_00b97718(c); /* call 0xb97718 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b9685bu); f_00b968a7(c); /* call 0xb968a7 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (c->zf) goto L_00b96872; /* je 0xb96872 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
L_00b96861:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x20] */
    PUSH32(c, 0x00b9686au); f_00b987c0(c); /* call 0xb987c0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_00b9686d:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (!c->zf) goto L_00b968b0; /* jne 0xb968b0 */
L_00b96872:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = R32((uint32_t)(0xb9f564u)); PUSH32(c, v_); } /* push dword ptr [0x1000f564] */
    { uint32_t t_ = R32((uint32_t)(0xb9b03cu)); PUSH32(c, 0x00b96881u); call_indirect(c, t_); } /* call dword ptr [0x1000b03c] */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
L_00b96884:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (!c->zf) goto L_00b968b0; /* jne 0xb968b0 */
    (void)sub32(c, R32((uint32_t)(0xb9f188u)), c->ebx); /* cmp dword ptr [0x1000f188], ebx */
    if (c->zf) goto L_00b968b0; /* je 0xb968b0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b96897u); f_00b97aed(c); /* call 0xb97aed */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b967d0; /* jne 0xb967d0 */
    goto L_00b968b3; /* jmp 0xb968b3 */
L_00b968b0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov eax, dword ptr [ebp - 0x20] */
L_00b968b3:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b967d0(CPU *c) { /* PTR_00b967d0 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x20], ebx */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) { f_00b96884(c); return; } /* ja 0xb96884 */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9f568u))); /* mov eax, dword ptr [0x1000f568] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) { f_00b96827(c); return; } /* jne 0xb96827 */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov edi, dword ptr [ebp - 0x1c] */
    (void)sub32(c, c->edi, R32((uint32_t)(0xb9f560u))); /* cmp edi, dword ptr [0x1000f560] */
    if ((!c->cf && !c->zf)) { f_00b9686d(c); return; } /* ja 0xb9686d */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b967f8u); f_00b95678(c); /* call 0xb95678 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 4], ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b96802u); f_00b96c75(c); /* call 0xb96c75 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b9680fu); f_00b9681e(c); /* call 0xb9681e */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (c->zf) { f_00b96872(c); return; } /* je 0xb96872 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x1c] */
    { f_00b96861(c); return; } /* jmp 0xb96861 */
}

void f_00b96819(CPU *c) { /* PTR_00b96819 */
    PREEMPT_POLL(c);
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    { f_00b9681e(c); return; }
}

void f_00b9681e(CPU *c) { /* FUN_1000681e */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b96825u); f_00b956d9(c); /* call 0xb956d9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00b96827(CPU *c) { /* PTR_00b96827 */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00b9686d; /* jne 0xb9686d */
    (void)sub32(c, c->esi, R32((uint32_t)(0xb9e4dcu))); /* cmp esi, dword ptr [0x1000e4dc] */
    if ((!c->cf && !c->zf)) goto L_00b9686d; /* ja 0xb9686d */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b9683bu); f_00b95678(c); /* call 0xb95678 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b9684eu); f_00b97718(c); /* call 0xb97718 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b9685bu); f_00b968a7(c); /* call 0xb968a7 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (c->zf) goto L_00b96872; /* je 0xb96872 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x20] */
    PUSH32(c, 0x00b9686au); f_00b987c0(c); /* call 0xb987c0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_00b9686d:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (!c->zf) { f_00b968b0(c); return; } /* jne 0xb968b0 */
L_00b96872:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = R32((uint32_t)(0xb9f564u)); PUSH32(c, v_); } /* push dword ptr [0x1000f564] */
    { uint32_t t_ = R32((uint32_t)(0xb9b03cu)); PUSH32(c, 0x00b96881u); call_indirect(c, t_); } /* call dword ptr [0x1000b03c] */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (!c->zf) { f_00b968b0(c); return; } /* jne 0xb968b0 */
    (void)sub32(c, R32((uint32_t)(0xb9f188u)), c->ebx); /* cmp dword ptr [0x1000f188], ebx */
    if (c->zf) { f_00b968b0(c); return; } /* je 0xb968b0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b96897u); f_00b97aed(c); /* call 0xb97aed */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00b967d0(c); return; } /* jne 0xb967d0 */
    { f_00b968b3(c); return; } /* jmp 0xb968b3 */
}

void f_00b96861(CPU *c) { /* PTR_00b96861 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x20] */
    PUSH32(c, 0x00b9686au); f_00b987c0(c); /* call 0xb987c0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (!c->zf) { f_00b968b0(c); return; } /* jne 0xb968b0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = R32((uint32_t)(0xb9f564u)); PUSH32(c, v_); } /* push dword ptr [0x1000f564] */
    { uint32_t t_ = R32((uint32_t)(0xb9b03cu)); PUSH32(c, 0x00b96881u); call_indirect(c, t_); } /* call dword ptr [0x1000b03c] */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (!c->zf) { f_00b968b0(c); return; } /* jne 0xb968b0 */
    (void)sub32(c, R32((uint32_t)(0xb9f188u)), c->ebx); /* cmp dword ptr [0x1000f188], ebx */
    if (c->zf) { f_00b968b0(c); return; } /* je 0xb968b0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b96897u); f_00b97aed(c); /* call 0xb97aed */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00b967d0(c); return; } /* jne 0xb967d0 */
    { f_00b968b3(c); return; } /* jmp 0xb968b3 */
}

void f_00b9686d(CPU *c) { /* PTR_00b9686d */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (!c->zf) { f_00b968b0(c); return; } /* jne 0xb968b0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = R32((uint32_t)(0xb9f564u)); PUSH32(c, v_); } /* push dword ptr [0x1000f564] */
    { uint32_t t_ = R32((uint32_t)(0xb9b03cu)); PUSH32(c, 0x00b96881u); call_indirect(c, t_); } /* call dword ptr [0x1000b03c] */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (!c->zf) { f_00b968b0(c); return; } /* jne 0xb968b0 */
    (void)sub32(c, R32((uint32_t)(0xb9f188u)), c->ebx); /* cmp dword ptr [0x1000f188], ebx */
    if (c->zf) { f_00b968b0(c); return; } /* je 0xb968b0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b96897u); f_00b97aed(c); /* call 0xb97aed */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00b967d0(c); return; } /* jne 0xb967d0 */
    { f_00b968b3(c); return; } /* jmp 0xb968b3 */
}

void f_00b96872(CPU *c) { /* PTR_00b96872 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = R32((uint32_t)(0xb9f564u)); PUSH32(c, v_); } /* push dword ptr [0x1000f564] */
    { uint32_t t_ = R32((uint32_t)(0xb9b03cu)); PUSH32(c, 0x00b96881u); call_indirect(c, t_); } /* call dword ptr [0x1000b03c] */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (!c->zf) { f_00b968b0(c); return; } /* jne 0xb968b0 */
    (void)sub32(c, R32((uint32_t)(0xb9f188u)), c->ebx); /* cmp dword ptr [0x1000f188], ebx */
    if (c->zf) { f_00b968b0(c); return; } /* je 0xb968b0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b96897u); f_00b97aed(c); /* call 0xb97aed */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00b967d0(c); return; } /* jne 0xb967d0 */
    { f_00b968b3(c); return; } /* jmp 0xb968b3 */
}

void f_00b96884(CPU *c) { /* PTR_00b96884 */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (!c->zf) { f_00b968b0(c); return; } /* jne 0xb968b0 */
    (void)sub32(c, R32((uint32_t)(0xb9f188u)), c->ebx); /* cmp dword ptr [0x1000f188], ebx */
    if (c->zf) { f_00b968b0(c); return; } /* je 0xb968b0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b96897u); f_00b97aed(c); /* call 0xb97aed */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00b967d0(c); return; } /* jne 0xb967d0 */
    { f_00b968b3(c); return; } /* jmp 0xb968b3 */
}

void f_00b968a2(CPU *c) { /* PTR_00b968a2 */
    PREEMPT_POLL(c);
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    { f_00b968a7(c); return; }
}

void f_00b968a7(CPU *c) { /* FUN_100068a7 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b968aeu); f_00b956d9(c); /* call 0xb956d9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00b968b0(CPU *c) { /* PTR_00b968b0 */
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

void f_00b968b3(CPU *c) { /* PTR_00b968b3 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b968c2(CPU *c) { /* FUN_100068c2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xau; PUSH32(c, v_); } /* push 0xa */
    PUSH32(c, 0x00b968c9u); f_00b961c9(c); /* call 0xb961c9 */
    { uint32_t v_ = 0x16u; PUSH32(c, v_); } /* push 0x16 */
    PUSH32(c, 0x00b968d0u); f_00b9920e(c); /* call 0xb9920e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    PUSH32(c, 0x00b968d9u); f_00b94afc(c); /* call 0xb94afc */
    { f_00b968d9(c); return; }
}

void f_00b968d9(CPU *c) { /* FUN_100068d9 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x140u; PUSH32(c, v_); } /* push 0x140 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb9f564u)); PUSH32(c, v_); } /* push dword ptr [0x1000f564] */
    { uint32_t t_ = R32((uint32_t)(0xb9b03cu)); PUSH32(c, 0x00b968ecu); call_indirect(c, t_); } /* call dword ptr [0x1000b03c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(0xb9f55cu), (uint32_t)(c->eax)); /* mov dword ptr [0x1000f55c], eax */
    if (!c->zf) goto L_00b968f6; /* jne 0xb968f6 */
    c->esp += 4; return; /* ret  */
L_00b968f6:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    { uint32_t a_ = (uint32_t)(0xb9f554u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [0x1000f554], 0 */
    { uint32_t a_ = (uint32_t)(0xb9f558u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [0x1000f558], 0 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    W32((uint32_t)(0xb9f550u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000f550], eax */
    W32((uint32_t)(0xb9f560u), (uint32_t)(c->ecx)); /* mov dword ptr [0x1000f560], ecx */
    W32((uint32_t)(0xb9f548u), (uint32_t)((uint32_t)0x10u)); /* mov dword ptr [0x1000f548], 0x10 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_00b96921(CPU *c) { /* FUN_10006921 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0xb9f558u))); /* mov eax, dword ptr [0x1000f558] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea ecx, [eax + eax*4] */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9f55cu))); /* mov eax, dword ptr [0x1000f55c] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->ecx * 4)); /* lea ecx, [eax + ecx*4] */
L_00b96931:;
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->cf) goto L_00b96949; /* jae 0xb96949 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    c->edx = (uint32_t)(sub32(c, c->edx, R32((uint32_t)(c->eax + 0xcu)))); /* sub edx, dword ptr [eax + 0xc] */
    (void)sub32(c, c->edx, (uint32_t)0x100000u); /* cmp edx, 0x100000 */
    if (c->cf) goto L_00b9694b; /* jb 0xb9694b */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x14u)); /* add eax, 0x14 */
    goto L_00b96931; /* jmp 0xb96931 */
L_00b96949:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00b9694b:;
    c->esp += 4; return; /* ret  */
}

void f_00b9694c(CPU *c) { /* FUN_1000694c */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x10u)); /* sub esp, 0x10 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x10u))); /* mov eax, dword ptr [ecx + 0x10] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->esi); /* mov edi, esi */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfffffffcu)); /* add esi, -4 */
    c->edi = (uint32_t)(sub32(c, c->edi, R32((uint32_t)(c->ecx + 0xcu)))); /* sub edi, dword ptr [ecx + 0xc] */
    c->edi = (uint32_t)(shr32(c, c->edi, 15)); /* shr edi, 0xf */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    { int64_t r_ = (int64_t)(int32_t)c->ecx * (int32_t)(uint32_t)0x204u; c->ecx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul ecx, ecx, 0x204 */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->eax + 0x144u)); /* lea ecx, [ecx + eax + 0x144] */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 0x10], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x1u)); /* test cl, 1 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 4], ecx */
    if (!c->zf) goto L_00b96c70; /* jne 0xb96c70 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + c->esi))); /* mov edx, dword ptr [ecx + esi] */
    c->ebx = (uint32_t)((uint32_t)(c->ecx + c->esi)); /* lea ebx, [ecx + esi] */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0xc], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0xfffffffcu))); /* mov edx, dword ptr [esi - 4] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 8], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov edx, dword ptr [ebp - 0xc] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & (uint8_t)0x1u)); /* test dl, 1 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 0xc], ebx */
    if (!c->zf) goto L_00b96a22; /* jne 0xb96a22 */
    c->edx = (uint32_t)(sar32(c, c->edx, 4)); /* sar edx, 4 */
    c->edx = (uint32_t)(dec32(c, c->edx)); /* dec edx */
    (void)sub32(c, c->edx, (uint32_t)0x3fu); /* cmp edx, 0x3f */
    if ((c->cf || c->zf)) goto L_00b969b0; /* jbe 0xb969b0 */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
L_00b969b0:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov ecx, dword ptr [ebx + 4] */
    (void)sub32(c, c->ecx, R32((uint32_t)(c->ebx + 0x8u))); /* cmp ecx, dword ptr [ebx + 8] */
    if (!c->zf) goto L_00b96a04; /* jne 0xb96a04 */
    (void)sub32(c, c->edx, (uint32_t)0x20u); /* cmp edx, 0x20 */
    if (!c->cf) goto L_00b969db; /* jae 0xb969db */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->ecx = (uint32_t)((uint32_t)(c->edx + c->eax + 0x4u)); /* lea ecx, [edx + eax + 4] */
    c->ebx = (uint32_t)((uint32_t)~c->ebx); /* not ebx */
    { uint32_t a_ = (uint32_t)(c->eax + c->edi * 4 + 0x44u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [eax + edi*4 + 0x44], ebx */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(dec8(c, R8(a_)))); } /* dec byte ptr [ecx] */
    if (!c->zf) goto L_00b969fc; /* jne 0xb969fc */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [ecx], ebx */
    goto L_00b969fc; /* jmp 0xb969fc */
L_00b969db:;
    c->ecx = (uint32_t)((uint32_t)(c->edx + 0xffffffe0u)); /* lea ecx, [edx - 0x20] */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->ecx = (uint32_t)((uint32_t)(c->edx + c->eax + 0x4u)); /* lea ecx, [edx + eax + 4] */
    c->ebx = (uint32_t)((uint32_t)~c->ebx); /* not ebx */
    { uint32_t a_ = (uint32_t)(c->eax + c->edi * 4 + 0xc4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [eax + edi*4 + 0xc4], ebx */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(dec8(c, R8(a_)))); } /* dec byte ptr [ecx] */
    if (!c->zf) goto L_00b969fc; /* jne 0xb969fc */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [ecx + 4], ebx */
L_00b969fc:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ebx, dword ptr [ebp + 0xc] */
    goto L_00b96a07; /* jmp 0xb96a07 */
L_00b96a04:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
L_00b96a07:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov edx, dword ptr [ebx + 8] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov ebx, dword ptr [ebx + 4] */
    c->ecx = (uint32_t)(add32(c, c->ecx, R32((uint32_t)(c->ebp + 0xfffffff4u)))); /* add ecx, dword ptr [ebp - 0xc] */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [edx + 4], ebx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 4], ecx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov ebx, dword ptr [edx + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov edx, dword ptr [edx + 8] */
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [ebx + 8], edx */
L_00b96a22:;
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    c->edx = (uint32_t)(sar32(c, c->edx, 4)); /* sar edx, 4 */
    c->edx = (uint32_t)(dec32(c, c->edx)); /* dec edx */
    (void)sub32(c, c->edx, (uint32_t)0x3fu); /* cmp edx, 0x3f */
    if ((c->cf || c->zf)) goto L_00b96a30; /* jbe 0xb96a30 */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
L_00b96a30:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ebx, dword ptr [ebp - 8] */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x1u))); /* and ebx, 1 */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0xc], ebx */
    if (!c->zf) goto L_00b96ad3; /* jne 0xb96ad3 */
    c->esi = (uint32_t)(sub32(c, c->esi, R32((uint32_t)(c->ebp + 0xfffffff8u)))); /* sub esi, dword ptr [ebp - 8] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ebx, dword ptr [ebp - 8] */
    c->ebx = (uint32_t)(sar32(c, c->ebx, 4)); /* sar ebx, 4 */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    (void)sub32(c, c->ebx, c->esi); /* cmp ebx, esi */
    if ((c->cf || c->zf)) goto L_00b96a55; /* jbe 0xb96a55 */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
L_00b96a55:;
    c->ecx = (uint32_t)(add32(c, c->ecx, R32((uint32_t)(c->ebp + 0xfffffff8u)))); /* add ecx, dword ptr [ebp - 8] */
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 4], ecx */
    c->edx = (uint32_t)(sar32(c, c->edx, 4)); /* sar edx, 4 */
    c->edx = (uint32_t)(dec32(c, c->edx)); /* dec edx */
    (void)sub32(c, c->edx, c->esi); /* cmp edx, esi */
    if ((c->cf || c->zf)) goto L_00b96a67; /* jbe 0xb96a67 */
    c->edx = (uint32_t)(c->esi); /* mov edx, esi */
L_00b96a67:;
    (void)sub32(c, c->ebx, c->edx); /* cmp ebx, edx */
    if (c->zf) goto L_00b96ace; /* je 0xb96ace */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov esi, dword ptr [ecx + 4] */
    (void)sub32(c, c->esi, R32((uint32_t)(c->ecx + 0x8u))); /* cmp esi, dword ptr [ecx + 8] */
    if (!c->zf) goto L_00b96ab6; /* jne 0xb96ab6 */
    (void)sub32(c, c->ebx, (uint32_t)0x20u); /* cmp ebx, 0x20 */
    if (!c->cf) goto L_00b96a97; /* jae 0xb96a97 */
    c->esi = (uint32_t)((uint32_t)0x80000000u); /* mov esi, 0x80000000 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    c->esi = (uint32_t)(shr32(c, c->esi, (c->ecx & 0xff))); /* shr esi, cl */
    c->esi = (uint32_t)((uint32_t)~c->esi); /* not esi */
    { uint32_t a_ = (uint32_t)(c->eax + c->edi * 4 + 0x44u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->esi)))); } /* and dword ptr [eax + edi*4 + 0x44], esi */
    { uint32_t a_ = (uint32_t)(c->ebx + c->eax + 0x4u); W8(a_, (uint8_t)(dec8(c, R8(a_)))); } /* dec byte ptr [ebx + eax + 4] */
    if (!c->zf) goto L_00b96ab6; /* jne 0xb96ab6 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->esi)))); } /* and dword ptr [ecx], esi */
    goto L_00b96ab6; /* jmp 0xb96ab6 */
L_00b96a97:;
    c->ecx = (uint32_t)((uint32_t)(c->ebx + 0xffffffe0u)); /* lea ecx, [ebx - 0x20] */
    c->esi = (uint32_t)((uint32_t)0x80000000u); /* mov esi, 0x80000000 */
    c->esi = (uint32_t)(shr32(c, c->esi, (c->ecx & 0xff))); /* shr esi, cl */
    c->esi = (uint32_t)((uint32_t)~c->esi); /* not esi */
    { uint32_t a_ = (uint32_t)(c->eax + c->edi * 4 + 0xc4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->esi)))); } /* and dword ptr [eax + edi*4 + 0xc4], esi */
    { uint32_t a_ = (uint32_t)(c->ebx + c->eax + 0x4u); W8(a_, (uint8_t)(dec8(c, R8(a_)))); } /* dec byte ptr [ebx + eax + 4] */
    if (!c->zf) goto L_00b96ab6; /* jne 0xb96ab6 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->esi)))); } /* and dword ptr [ecx + 4], esi */
L_00b96ab6:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov esi, dword ptr [ecx + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ecx, dword ptr [ecx + 4] */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 4], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov esi, dword ptr [ecx + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov ecx, dword ptr [ecx + 8] */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 8], ecx */
L_00b96ace:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    goto L_00b96ad6; /* jmp 0xb96ad6 */
L_00b96ad3:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00b96ad6:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0xc], 0 */
    if (!c->zf) goto L_00b96ae4; /* jne 0xb96ae4 */
    (void)sub32(c, c->ebx, c->edx); /* cmp ebx, edx */
    if (c->zf) goto L_00b96b65; /* je 0xb96b65 */
L_00b96ae4:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ecx + c->edx * 8 + 0x4u))); /* mov ebx, dword ptr [ecx + edx*8 + 4] */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->edx * 8)); /* lea ecx, [ecx + edx*8] */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 4], ebx */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 8], ecx */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [ecx + 4], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ecx + 8], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    (void)sub32(c, c->ecx, R32((uint32_t)(c->esi + 0x8u))); /* cmp ecx, dword ptr [esi + 8] */
    if (!c->zf) goto L_00b96b65; /* jne 0xb96b65 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx + c->eax + 0x4u))); /* mov cl, byte ptr [edx + eax + 4] */
    (void)sub32(c, c->edx, (uint32_t)0x20u); /* cmp edx, 0x20 */
    W8((uint32_t)(c->ebp + 0xfu), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [ebp + 0xf], cl */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(inc8(c, ((uint8_t)c->ecx))); /* inc cl */
    W8((uint32_t)(c->edx + c->eax + 0x4u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [edx + eax + 4], cl */
    if (!c->cf) goto L_00b96b3c; /* jae 0xb96b3c */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xfu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0xf], 0 */
    if (!c->zf) goto L_00b96b2b; /* jne 0xb96b2b */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->ebx)))); } /* or dword ptr [ecx], ebx */
L_00b96b2b:;
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->edi * 4 + 0x44u)); /* lea eax, [eax + edi*4 + 0x44] */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->ebx)))); } /* or dword ptr [eax], ebx */
    goto L_00b96b65; /* jmp 0xb96b65 */
L_00b96b3c:;
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xfu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0xf], 0 */
    if (!c->zf) goto L_00b96b52; /* jne 0xb96b52 */
    c->ecx = (uint32_t)((uint32_t)(c->edx + 0xffffffe0u)); /* lea ecx, [edx - 0x20] */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->ebx)))); } /* or dword ptr [ecx + 4], ebx */
L_00b96b52:;
    c->ecx = (uint32_t)((uint32_t)(c->edx + 0xffffffe0u)); /* lea ecx, [edx - 0x20] */
    c->edx = (uint32_t)((uint32_t)0x80000000u); /* mov edx, 0x80000000 */
    c->edx = (uint32_t)(shr32(c, c->edx, (c->ecx & 0xff))); /* shr edx, cl */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->edi * 4 + 0xc4u)); /* lea eax, [eax + edi*4 + 0xc4] */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edx)))); } /* or dword ptr [eax], edx */
L_00b96b65:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    W32((uint32_t)(c->eax + c->esi + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [eax + esi - 4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [eax] */
    if (!c->zf) goto L_00b96c70; /* jne 0xb96c70 */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9f554u))); /* mov eax, dword ptr [0x1000f554] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b96c62; /* je 0xb96c62 */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb9f54cu))); /* mov ecx, dword ptr [0x1000f54c] */
    c->esi = (uint32_t)(R32((uint32_t)(0xb9b09cu))); /* mov esi, dword ptr [0x1000b09c] */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 15)); /* shl ecx, 0xf */
    c->ecx = (uint32_t)(add32(c, c->ecx, R32((uint32_t)(c->eax + 0xcu)))); /* add ecx, dword ptr [eax + 0xc] */
    c->ebx = (uint32_t)((uint32_t)0x8000u); /* mov ebx, 0x8000 */
    { uint32_t v_ = 0x4000u; PUSH32(c, v_); } /* push 0x4000 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t t_ = c->esi; PUSH32(c, 0x00b96ba6u); call_indirect(c, t_); } /* call esi */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb9f54cu))); /* mov ecx, dword ptr [0x1000f54c] */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9f554u))); /* mov eax, dword ptr [0x1000f554] */
    c->edx = (uint32_t)((uint32_t)0x80000000u); /* mov edx, 0x80000000 */
    c->edx = (uint32_t)(shr32(c, c->edx, (c->ecx & 0xff))); /* shr edx, cl */
    { uint32_t a_ = (uint32_t)(c->eax + 0x8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edx)))); } /* or dword ptr [eax + 8], edx */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9f554u))); /* mov eax, dword ptr [0x1000f554] */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb9f54cu))); /* mov ecx, dword ptr [0x1000f54c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x10u))); /* mov eax, dword ptr [eax + 0x10] */
    { uint32_t a_ = (uint32_t)(c->eax + c->ecx * 4 + 0xc4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [eax + ecx*4 + 0xc4], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9f554u))); /* mov eax, dword ptr [0x1000f554] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x10u))); /* mov eax, dword ptr [eax + 0x10] */
    { uint32_t a_ = (uint32_t)(c->eax + 0x43u); W8(a_, (uint8_t)(dec8(c, R8(a_)))); } /* dec byte ptr [eax + 0x43] */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9f554u))); /* mov eax, dword ptr [0x1000f554] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x10u))); /* mov ecx, dword ptr [eax + 0x10] */
    (void)sub8(c, R8((uint32_t)(c->ecx + 0x43u)), (uint8_t)0x0u); /* cmp byte ptr [ecx + 0x43], 0 */
    if (!c->zf) goto L_00b96bf3; /* jne 0xb96bf3 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0xfffffffeu)))); } /* and dword ptr [eax + 4], 0xfffffffe */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9f554u))); /* mov eax, dword ptr [0x1000f554] */
L_00b96bf3:;
    (void)sub32(c, R32((uint32_t)(c->eax + 0x8u)), (uint32_t)0xffffffffu); /* cmp dword ptr [eax + 8], -1 */
    if (!c->zf) goto L_00b96c62; /* jne 0xb96c62 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->eax + 0xcu)); PUSH32(c, v_); } /* push dword ptr [eax + 0xc] */
    { uint32_t t_ = c->esi; PUSH32(c, 0x00b96c01u); call_indirect(c, t_); } /* call esi */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9f554u))); /* mov eax, dword ptr [0x1000f554] */
    { uint32_t v_ = R32((uint32_t)(c->eax + 0x10u)); PUSH32(c, v_); } /* push dword ptr [eax + 0x10] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb9f564u)); PUSH32(c, v_); } /* push dword ptr [0x1000f564] */
    { uint32_t t_ = R32((uint32_t)(0xb9b05cu)); PUSH32(c, 0x00b96c17u); call_indirect(c, t_); } /* call dword ptr [0x1000b05c] */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9f558u))); /* mov eax, dword ptr [0x1000f558] */
    c->edx = (uint32_t)(R32((uint32_t)(0xb9f55cu))); /* mov edx, dword ptr [0x1000f55c] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea eax, [eax + eax*4] */
    c->eax = (uint32_t)(shl32(c, c->eax, 2)); /* shl eax, 2 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9f554u))); /* mov eax, dword ptr [0x1000f554] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->edx + 0xffffffecu)); /* lea ecx, [ecx + edx - 0x14] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x14u)); /* lea ecx, [eax + 0x14] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b96c40u); f_00b96450(c); /* call 0xb96450 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t a_ = (uint32_t)(0xb9f558u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [0x1000f558] */
    (void)sub32(c, c->eax, R32((uint32_t)(0xb9f554u))); /* cmp eax, dword ptr [0x1000f554] */
    if ((c->cf || c->zf)) goto L_00b96c58; /* jbe 0xb96c58 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(sub32(c, R32(a_), (uint32_t)0x14u))); } /* sub dword ptr [ebp + 8], 0x14 */
L_00b96c58:;
    c->eax = (uint32_t)(R32((uint32_t)(0xb9f55cu))); /* mov eax, dword ptr [0x1000f55c] */
    W32((uint32_t)(0xb9f550u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000f550], eax */
L_00b96c62:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(0xb9f54cu), (uint32_t)(c->edi)); /* mov dword ptr [0x1000f54c], edi */
    W32((uint32_t)(0xb9f554u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000f554], eax */
L_00b96c70:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b96c75(CPU *c) { /* FUN_10006c75 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x14u)); /* sub esp, 0x14 */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9f558u))); /* mov eax, dword ptr [0x1000f558] */
    c->edx = (uint32_t)(R32((uint32_t)(0xb9f55cu))); /* mov edx, dword ptr [0x1000f55c] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea eax, [eax + eax*4] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)((uint32_t)(c->edx + c->eax * 4)); /* lea edi, [edx + eax*4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 4], edi */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x17u)); /* lea ecx, [eax + 0x17] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0xfffffff0u))); /* and ecx, 0xfffffff0 */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 0x10], ecx */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 4)); /* sar ecx, 4 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    (void)sub32(c, c->ecx, (uint32_t)0x20u); /* cmp ecx, 0x20 */
    if ((c->sf == c->of)) goto L_00b96cb5; /* jge 0xb96cb5 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi | (uint32_t)0xffffffffu))); /* or esi, 0xffffffff */
    c->esi = (uint32_t)(shr32(c, c->esi, (c->ecx & 0xff))); /* shr esi, cl */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 8], 0xffffffff */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0xc], esi */
    goto L_00b96cc5; /* jmp 0xb96cc5 */
L_00b96cb5:;
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0xffffffe0u)); /* add ecx, -0x20 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, (c->ecx & 0xff))); /* shr eax, cl */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0xc], esi */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
L_00b96cc5:;
    c->eax = (uint32_t)(R32((uint32_t)(0xb9f550u))); /* mov eax, dword ptr [0x1000f550] */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 8], ebx */
    if (!c->cf) goto L_00b96cec; /* jae 0xb96cec */
L_00b96cd3:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov ecx, dword ptr [ebx + 4] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov edi, dword ptr [ebx] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & R32((uint32_t)(c->ebp + 0xfffffff8u))))); /* and ecx, dword ptr [ebp - 8] */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & c->esi))); /* and edi, esi */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->edi))); /* or ecx, edi */
    if (!c->zf) goto L_00b96cec; /* jne 0xb96cec */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x14u)); /* add ebx, 0x14 */
    (void)sub32(c, c->ebx, R32((uint32_t)(c->ebp + 0xfffffffcu))); /* cmp ebx, dword ptr [ebp - 4] */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 8], ebx */
    if (c->cf) goto L_00b96cd3; /* jb 0xb96cd3 */
L_00b96cec:;
    (void)sub32(c, c->ebx, R32((uint32_t)(c->ebp + 0xfffffffcu))); /* cmp ebx, dword ptr [ebp - 4] */
    if (!c->zf) goto L_00b96d6a; /* jne 0xb96d6a */
    c->ebx = (uint32_t)(c->edx); /* mov ebx, edx */
L_00b96cf3:;
    (void)sub32(c, c->ebx, c->eax); /* cmp ebx, eax */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 8], ebx */
    if (!c->cf) goto L_00b96d0f; /* jae 0xb96d0f */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov ecx, dword ptr [ebx + 4] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov edi, dword ptr [ebx] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & R32((uint32_t)(c->ebp + 0xfffffff8u))))); /* and ecx, dword ptr [ebp - 8] */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & c->esi))); /* and edi, esi */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->edi))); /* or ecx, edi */
    if (!c->zf) goto L_00b96d0d; /* jne 0xb96d0d */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x14u)); /* add ebx, 0x14 */
    goto L_00b96cf3; /* jmp 0xb96cf3 */
L_00b96d0d:;
    (void)sub32(c, c->ebx, c->eax); /* cmp ebx, eax */
L_00b96d0f:;
    if (!c->zf) goto L_00b96d6a; /* jne 0xb96d6a */
L_00b96d11:;
    (void)sub32(c, c->ebx, R32((uint32_t)(c->ebp + 0xfffffffcu))); /* cmp ebx, dword ptr [ebp - 4] */
    if (!c->cf) goto L_00b96d27; /* jae 0xb96d27 */
    (void)sub32(c, R32((uint32_t)(c->ebx + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebx + 8], 0 */
    if (!c->zf) goto L_00b96d24; /* jne 0xb96d24 */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x14u)); /* add ebx, 0x14 */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 8], ebx */
    goto L_00b96d11; /* jmp 0xb96d11 */
L_00b96d24:;
    (void)sub32(c, c->ebx, R32((uint32_t)(c->ebp + 0xfffffffcu))); /* cmp ebx, dword ptr [ebp - 4] */
L_00b96d27:;
    if (!c->zf) goto L_00b96d4f; /* jne 0xb96d4f */
    c->ebx = (uint32_t)(c->edx); /* mov ebx, edx */
L_00b96d2b:;
    (void)sub32(c, c->ebx, c->eax); /* cmp ebx, eax */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 8], ebx */
    if (!c->cf) goto L_00b96d3f; /* jae 0xb96d3f */
    (void)sub32(c, R32((uint32_t)(c->ebx + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebx + 8], 0 */
    if (!c->zf) goto L_00b96d3d; /* jne 0xb96d3d */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x14u)); /* add ebx, 0x14 */
    goto L_00b96d2b; /* jmp 0xb96d2b */
L_00b96d3d:;
    (void)sub32(c, c->ebx, c->eax); /* cmp ebx, eax */
L_00b96d3f:;
    if (!c->zf) goto L_00b96d4f; /* jne 0xb96d4f */
    PUSH32(c, 0x00b96d46u); f_00b96f7e(c); /* call 0xb96f7e */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 8], ebx */
    if (c->zf) goto L_00b96d63; /* je 0xb96d63 */
L_00b96d4f:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b96d55u); f_00b9702f(c); /* call 0xb9702f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x10u))); /* mov ecx, dword ptr [ebx + 0x10] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x10u))); /* mov eax, dword ptr [ebx + 0x10] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xffffffffu); /* cmp dword ptr [eax], -1 */
    if (!c->zf) goto L_00b96d6a; /* jne 0xb96d6a */
L_00b96d63:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00b96f79; /* jmp 0xb96f79 */
L_00b96d6a:;
    W32((uint32_t)(0xb9f550u), (uint32_t)(c->ebx)); /* mov dword ptr [0x1000f550], ebx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x10u))); /* mov eax, dword ptr [ebx + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    (void)sub32(c, c->edx, (uint32_t)0xffffffffu); /* cmp edx, -1 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 4], edx */
    if (c->zf) goto L_00b96d91; /* je 0xb96d91 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + c->edx * 4 + 0xc4u))); /* mov ecx, dword ptr [eax + edx*4 + 0xc4] */
    c->edi = (uint32_t)(R32((uint32_t)(c->eax + c->edx * 4 + 0x44u))); /* mov edi, dword ptr [eax + edx*4 + 0x44] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & R32((uint32_t)(c->ebp + 0xfffffff8u))))); /* and ecx, dword ptr [ebp - 8] */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & c->esi))); /* and edi, esi */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->edi))); /* or ecx, edi */
    if (!c->zf) goto L_00b96dc8; /* jne 0xb96dc8 */
L_00b96d91:;
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0xc4u))); /* mov edx, dword ptr [eax + 0xc4] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + 0x44u))); /* mov esi, dword ptr [eax + 0x44] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & R32((uint32_t)(c->ebp + 0xfffffff8u))))); /* and edx, dword ptr [ebp - 8] */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & R32((uint32_t)(c->ebp + 0xfffffff4u))))); /* and esi, dword ptr [ebp - 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x44u)); /* lea ecx, [eax + 0x44] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx | c->esi))); /* or edx, esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov esi, dword ptr [ebp - 0xc] */
    if (!c->zf) goto L_00b96dc5; /* jne 0xb96dc5 */
L_00b96dae:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x84u))); /* mov edx, dword ptr [ecx + 0x84] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & R32((uint32_t)(c->ebp + 0xfffffff8u))))); /* and edx, dword ptr [ebp - 8] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    c->edi = (uint32_t)(c->esi); /* mov edi, esi */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & R32((uint32_t)(c->ecx))))); /* and edi, dword ptr [ecx] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx | c->edi))); /* or edx, edi */
    if (c->zf) goto L_00b96dae; /* je 0xb96dae */
L_00b96dc5:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov edx, dword ptr [ebp - 4] */
L_00b96dc8:;
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    { int64_t r_ = (int64_t)(int32_t)c->ecx * (int32_t)(uint32_t)0x204u; c->ecx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul ecx, ecx, 0x204 */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->eax + 0x144u)); /* lea ecx, [ecx + eax + 0x144] */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 0xc], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + c->edx * 4 + 0x44u))); /* mov ecx, dword ptr [eax + edx*4 + 0x44] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & c->esi))); /* and ecx, esi */
    if (!c->zf) goto L_00b96df1; /* jne 0xb96df1 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + c->edx * 4 + 0xc4u))); /* mov ecx, dword ptr [eax + edx*4 + 0xc4] */
    { uint32_t v_ = 0x20u; PUSH32(c, v_); } /* push 0x20 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & R32((uint32_t)(c->ebp + 0xfffffff8u))))); /* and ecx, dword ptr [ebp - 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_00b96df1:;
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if ((c->sf != c->of)) goto L_00b96dfa; /* jl 0xb96dfa */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 1)); /* shl ecx, 1 */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_00b96df1; /* jmp 0xb96df1 */
L_00b96dfa:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + c->edi * 8 + 0x4u))); /* mov edx, dword ptr [ecx + edi*8 + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx))); /* mov ecx, dword ptr [edx] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, R32((uint32_t)(c->ebp + 0xfffffff0u)))); /* sub ecx, dword ptr [ebp - 0x10] */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
    c->esi = (uint32_t)(sar32(c, c->esi, 4)); /* sar esi, 4 */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    (void)sub32(c, c->esi, (uint32_t)0x3fu); /* cmp esi, 0x3f */
    if ((c->zf || c->sf != c->of)) goto L_00b96e17; /* jle 0xb96e17 */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00b96e17:;
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (c->zf) goto L_00b96f2c; /* je 0xb96f2c */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov ecx, dword ptr [edx + 4] */
    (void)sub32(c, c->ecx, R32((uint32_t)(c->edx + 0x8u))); /* cmp ecx, dword ptr [edx + 8] */
    if (!c->zf) goto L_00b96e88; /* jne 0xb96e88 */
    (void)sub32(c, c->edi, (uint32_t)0x20u); /* cmp edi, 0x20 */
    if ((c->sf == c->of)) goto L_00b96e57; /* jge 0xb96e57 */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->edi = (uint32_t)((uint32_t)(c->eax + c->edi + 0x4u)); /* lea edi, [eax + edi + 4] */
    c->ebx = (uint32_t)((uint32_t)~c->ebx); /* not ebx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x14], ebx */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & R32((uint32_t)(c->eax + c->ecx * 4 + 0x44u))))); /* and ebx, dword ptr [eax + ecx*4 + 0x44] */
    W32((uint32_t)(c->eax + c->ecx * 4 + 0x44u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + ecx*4 + 0x44], ebx */
    { uint32_t a_ = (uint32_t)(c->edi); W8(a_, (uint8_t)(dec8(c, R8(a_)))); } /* dec byte ptr [edi] */
    if (!c->zf) goto L_00b96e85; /* jne 0xb96e85 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov ecx, dword ptr [ebp - 0x14] */
    { uint32_t a_ = (uint32_t)(c->ebx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ecx)))); } /* and dword ptr [ebx], ecx */
    goto L_00b96e88; /* jmp 0xb96e88 */
L_00b96e57:;
    c->ecx = (uint32_t)((uint32_t)(c->edi + 0xffffffe0u)); /* lea ecx, [edi - 0x20] */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->edi = (uint32_t)((uint32_t)(c->eax + c->edi + 0x4u)); /* lea edi, [eax + edi + 4] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->ecx * 4 + 0xc4u)); /* lea ecx, [eax + ecx*4 + 0xc4] */
    c->ebx = (uint32_t)((uint32_t)~c->ebx); /* not ebx */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [ecx], ebx */
    { uint32_t a_ = (uint32_t)(c->edi); W8(a_, (uint8_t)(dec8(c, R8(a_)))); } /* dec byte ptr [edi] */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x14], ebx */
    if (!c->zf) goto L_00b96e85; /* jne 0xb96e85 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov ecx, dword ptr [ebp - 0x14] */
    { uint32_t a_ = (uint32_t)(c->ebx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ecx)))); } /* and dword ptr [ebx + 4], ecx */
    goto L_00b96e88; /* jmp 0xb96e88 */
L_00b96e85:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00b96e88:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov ecx, dword ptr [edx + 8] */
    c->edi = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov edi, dword ptr [edx + 4] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 8], 0 */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->edi)); /* mov dword ptr [ecx + 4], edi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov ecx, dword ptr [edx + 4] */
    c->edi = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov edi, dword ptr [edx + 8] */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [ecx + 8], edi */
    if (c->zf) goto L_00b96f38; /* je 0xb96f38 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ecx + c->esi * 8 + 0x4u))); /* mov edi, dword ptr [ecx + esi*8 + 4] */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->esi * 8)); /* lea ecx, [ecx + esi*8] */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->edi)); /* mov dword ptr [edx + 4], edi */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [edx + 8], ecx */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 4], edx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov ecx, dword ptr [edx + 4] */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 8], edx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov ecx, dword ptr [edx + 4] */
    (void)sub32(c, c->ecx, R32((uint32_t)(c->edx + 0x8u))); /* cmp ecx, dword ptr [edx + 8] */
    if (!c->zf) goto L_00b96f29; /* jne 0xb96f29 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + c->eax + 0x4u))); /* mov cl, byte ptr [esi + eax + 4] */
    (void)sub32(c, c->esi, (uint32_t)0x20u); /* cmp esi, 0x20 */
    W8((uint32_t)(c->ebp + 0xbu), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [ebp + 0xb], cl */
    if ((c->sf == c->of)) goto L_00b96efa; /* jge 0xb96efa */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(inc8(c, ((uint8_t)c->ecx))); /* inc cl */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xbu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0xb], 0 */
    W8((uint32_t)(c->esi + c->eax + 0x4u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esi + eax + 4], cl */
    if (!c->zf) goto L_00b96ee8; /* jne 0xb96ee8 */
    c->edi = (uint32_t)((uint32_t)0x80000000u); /* mov edi, 0x80000000 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->edi = (uint32_t)(shr32(c, c->edi, (c->ecx & 0xff))); /* shr edi, cl */
    { uint32_t a_ = (uint32_t)(c->ebx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edi)))); } /* or dword ptr [ebx], edi */
L_00b96ee8:;
    c->edi = (uint32_t)((uint32_t)0x80000000u); /* mov edi, 0x80000000 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->edi = (uint32_t)(shr32(c, c->edi, (c->ecx & 0xff))); /* shr edi, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    { uint32_t a_ = (uint32_t)(c->eax + c->ecx * 4 + 0x44u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edi)))); } /* or dword ptr [eax + ecx*4 + 0x44], edi */
    goto L_00b96f29; /* jmp 0xb96f29 */
L_00b96efa:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(inc8(c, ((uint8_t)c->ecx))); /* inc cl */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xbu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0xb], 0 */
    W8((uint32_t)(c->esi + c->eax + 0x4u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esi + eax + 4], cl */
    if (!c->zf) goto L_00b96f13; /* jne 0xb96f13 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0xffffffe0u)); /* lea ecx, [esi - 0x20] */
    c->edi = (uint32_t)((uint32_t)0x80000000u); /* mov edi, 0x80000000 */
    c->edi = (uint32_t)(shr32(c, c->edi, (c->ecx & 0xff))); /* shr edi, cl */
    { uint32_t a_ = (uint32_t)(c->ebx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edi)))); } /* or dword ptr [ebx + 4], edi */
L_00b96f13:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->edi = (uint32_t)((uint32_t)(c->eax + c->ecx * 4 + 0xc4u)); /* lea edi, [eax + ecx*4 + 0xc4] */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0xffffffe0u)); /* lea ecx, [esi - 0x20] */
    c->esi = (uint32_t)((uint32_t)0x80000000u); /* mov esi, 0x80000000 */
    c->esi = (uint32_t)(shr32(c, c->esi, (c->ecx & 0xff))); /* shr esi, cl */
    { uint32_t a_ = (uint32_t)(c->edi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->esi)))); } /* or dword ptr [edi], esi */
L_00b96f29:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
L_00b96f2c:;
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00b96f3b; /* je 0xb96f3b */
    W32((uint32_t)(c->edx), (uint32_t)(c->ecx)); /* mov dword ptr [edx], ecx */
    W32((uint32_t)(c->ecx + c->edx + 0xfffffffcu), (uint32_t)(c->ecx)); /* mov dword ptr [ecx + edx - 4], ecx */
    goto L_00b96f3b; /* jmp 0xb96f3b */
L_00b96f38:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
L_00b96f3b:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov esi, dword ptr [ebp - 0x10] */
    c->edx = (uint32_t)(add32(c, c->edx, c->ecx)); /* add edx, ecx */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x1u)); /* lea ecx, [esi + 1] */
    W32((uint32_t)(c->edx), (uint32_t)(c->ecx)); /* mov dword ptr [edx], ecx */
    W32((uint32_t)(c->edx + c->esi + 0xfffffffcu), (uint32_t)(c->ecx)); /* mov dword ptr [edx + esi - 4], ecx */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov esi, dword ptr [ebp - 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    c->edi = (uint32_t)((uint32_t)(c->ecx + 0x1u)); /* lea edi, [ecx + 1] */
    W32((uint32_t)(c->esi), (uint32_t)(c->edi)); /* mov dword ptr [esi], edi */
    if (!c->zf) goto L_00b96f71; /* jne 0xb96f71 */
    (void)sub32(c, c->ebx, R32((uint32_t)(0xb9f554u))); /* cmp ebx, dword ptr [0x1000f554] */
    if (!c->zf) goto L_00b96f71; /* jne 0xb96f71 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    (void)sub32(c, c->ecx, R32((uint32_t)(0xb9f54cu))); /* cmp ecx, dword ptr [0x1000f54c] */
    if (!c->zf) goto L_00b96f71; /* jne 0xb96f71 */
    { uint32_t a_ = (uint32_t)(0xb9f554u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [0x1000f554], 0 */
L_00b96f71:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->eax = (uint32_t)((uint32_t)(c->edx + 0x4u)); /* lea eax, [edx + 4] */
L_00b96f79:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b96f7e(CPU *c) { /* FUN_10006f7e */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0xb9f558u))); /* mov eax, dword ptr [0x1000f558] */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb9f548u))); /* mov ecx, dword ptr [0x1000f548] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->zf) goto L_00b96fc1; /* jne 0xb96fc1 */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->ecx * 4 + 0x50u)); /* lea eax, [ecx + ecx*4 + 0x50] */
    c->eax = (uint32_t)(shl32(c, c->eax, 2)); /* shl eax, 2 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(0xb9f55cu)); PUSH32(c, v_); } /* push dword ptr [0x1000f55c] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0xb9f564u)); PUSH32(c, v_); } /* push dword ptr [0x1000f564] */
    { uint32_t t_ = R32((uint32_t)(0xb9b038u)); PUSH32(c, 0x00b96facu); call_indirect(c, t_); } /* call dword ptr [0x1000b038] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (c->zf) goto L_00b97011; /* je 0xb97011 */
    { uint32_t a_ = (uint32_t)(0xb9f548u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x10u))); } /* add dword ptr [0x1000f548], 0x10 */
    W32((uint32_t)(0xb9f55cu), (uint32_t)(c->eax)); /* mov dword ptr [0x1000f55c], eax */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9f558u))); /* mov eax, dword ptr [0x1000f558] */
L_00b96fc1:;
    c->ecx = (uint32_t)(R32((uint32_t)(0xb9f55cu))); /* mov ecx, dword ptr [0x1000f55c] */
    { uint32_t v_ = 0x41c4u; PUSH32(c, v_); } /* push 0x41c4 */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea eax, [eax + eax*4] */
    { uint32_t v_ = R32((uint32_t)(0xb9f564u)); PUSH32(c, v_); } /* push dword ptr [0x1000f564] */
    c->esi = (uint32_t)((uint32_t)(c->ecx + c->eax * 4)); /* lea esi, [ecx + eax*4] */
    { uint32_t t_ = R32((uint32_t)(0xb9b03cu)); PUSH32(c, 0x00b96fe0u); call_indirect(c, t_); } /* call dword ptr [0x1000b03c] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x10], eax */
    if (c->zf) goto L_00b97011; /* je 0xb97011 */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = 0x2000u; PUSH32(c, v_); } /* push 0x2000 */
    { uint32_t v_ = 0x100000u; PUSH32(c, v_); } /* push 0x100000 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0xb9b0b0u)); PUSH32(c, 0x00b96ffau); call_indirect(c, t_); } /* call dword ptr [0x1000b0b0] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xc], eax */
    if (!c->zf) goto L_00b97015; /* jne 0xb97015 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x10] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0xb9f564u)); PUSH32(c, v_); } /* push dword ptr [0x1000f564] */
    { uint32_t t_ = R32((uint32_t)(0xb9b05cu)); PUSH32(c, 0x00b97011u); call_indirect(c, t_); } /* call dword ptr [0x1000b05c] */
L_00b97011:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00b9702c; /* jmp 0xb9702c */
L_00b97015:;
    { uint32_t a_ = (uint32_t)(c->esi + 0x8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [esi + 8], 0xffffffff */
    W32((uint32_t)(c->esi), (uint32_t)(c->edi)); /* mov dword ptr [esi], edi */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 4], edi */
    { uint32_t a_ = (uint32_t)(0xb9f558u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [0x1000f558] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [eax], 0xffffffff */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00b9702c:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b9702f(CPU *c) { /* FUN_1000702f */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x10u))); /* mov esi, dword ptr [ecx + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov eax, dword ptr [ecx + 8] */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
L_00b97041:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf != c->of)) goto L_00b9704a; /* jl 0xb9704a */
    c->eax = (uint32_t)(shl32(c, c->eax, 1)); /* shl eax, 1 */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    goto L_00b97041; /* jmp 0xb97041 */
L_00b9704a:;
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)(uint32_t)0x204u; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, eax, 0x204 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->esi + 0x144u)); /* lea eax, [eax + esi + 0x144] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
L_00b9705f:;
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [eax + 8], eax */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [eax + 4], eax */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
    c->edx = (uint32_t)(dec32(c, c->edx)); /* dec edx */
    if (!c->zf) goto L_00b9705f; /* jne 0xb9705f */
    c->edi = (uint32_t)(c->ebx); /* mov edi, ebx */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    c->edi = (uint32_t)(shl32(c, c->edi, 15)); /* shl edi, 0xf */
    c->edi = (uint32_t)(add32(c, c->edi, R32((uint32_t)(c->ecx + 0xcu)))); /* add edi, dword ptr [ecx + 0xc] */
    { uint32_t v_ = 0x1000u; PUSH32(c, v_); } /* push 0x1000 */
    { uint32_t v_ = 0x8000u; PUSH32(c, v_); } /* push 0x8000 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0xb9b0b0u)); PUSH32(c, 0x00b97086u); call_indirect(c, t_); } /* call dword ptr [0x1000b0b0] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b97092; /* jne 0xb97092 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    goto L_00b97125; /* jmp 0xb97125 */
L_00b97092:;
    c->edx = (uint32_t)((uint32_t)(c->edi + 0x7000u)); /* lea edx, [edi + 0x7000] */
    (void)sub32(c, c->edi, c->edx); /* cmp edi, edx */
    if ((!c->cf && !c->zf)) goto L_00b970d8; /* ja 0xb970d8 */
    c->eax = (uint32_t)((uint32_t)(c->edi + 0x10u)); /* lea eax, [edi + 0x10] */
L_00b9709f:;
    { uint32_t a_ = (uint32_t)(c->eax + 0xfffffff8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [eax - 8], 0xffffffff */
    { uint32_t a_ = (uint32_t)(c->eax + 0xfecu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [eax + 0xfec], 0xffffffff */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0xffcu)); /* lea ecx, [eax + 0xffc] */
    W32((uint32_t)(c->eax + 0xfffffffcu), (uint32_t)((uint32_t)0xff0u)); /* mov dword ptr [eax - 4], 0xff0 */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0xffffeffcu)); /* lea ecx, [eax - 0x1004] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 4], ecx */
    W32((uint32_t)(c->eax + 0xfe8u), (uint32_t)((uint32_t)0xff0u)); /* mov dword ptr [eax + 0xfe8], 0xff0 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x1000u)); /* add eax, 0x1000 */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0xfffffff0u)); /* lea ecx, [eax - 0x10] */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if ((c->cf || c->zf)) goto L_00b9709f; /* jbe 0xb9709f */
L_00b970d8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->ecx = (uint32_t)((uint32_t)(c->edi + 0xcu)); /* lea ecx, [edi + 0xc] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x1f8u)); /* add eax, 0x1f8 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 4], ecx */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 8], eax */
    c->ecx = (uint32_t)((uint32_t)(c->edx + 0xcu)); /* lea ecx, [edx + 0xc] */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 4], eax */
    { uint32_t a_ = (uint32_t)(c->esi + c->ebx * 4 + 0x44u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi + ebx*4 + 0x44], 0 */
    W32((uint32_t)(c->esi + c->ebx * 4 + 0xc4u), (uint32_t)(c->edi)); /* mov dword ptr [esi + ebx*4 + 0xc4], edi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x43u))); /* mov al, byte ptr [esi + 0x43] */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(((uint8_t)c->eax)); /* mov cl, al */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(inc8(c, ((uint8_t)c->ecx))); /* inc cl */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W8((uint32_t)(c->esi + 0x43u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esi + 0x43], cl */
    if (!c->zf) goto L_00b97115; /* jne 0xb97115 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edi)))); } /* or dword ptr [eax + 4], edi */
L_00b97115:;
    c->edx = (uint32_t)((uint32_t)0x80000000u); /* mov edx, 0x80000000 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    c->edx = (uint32_t)(shr32(c, c->edx, (c->ecx & 0xff))); /* shr edx, cl */
    c->edx = (uint32_t)((uint32_t)~c->edx); /* not edx */
    { uint32_t a_ = (uint32_t)(c->eax + 0x8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->edx)))); } /* and dword ptr [eax + 8], edx */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
L_00b97125:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b9712a(CPU *c) { /* FUN_1000712a */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    c->edx = (uint32_t)(c->edi); /* mov edx, edi */
    c->esi = (uint32_t)((uint32_t)(c->eax + 0x17u)); /* lea esi, [eax + 0x17] */
    c->edx = (uint32_t)(sub32(c, c->edx, R32((uint32_t)(c->ecx + 0xcu)))); /* sub edx, dword ptr [ecx + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x10u))); /* mov eax, dword ptr [ecx + 0x10] */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    c->edx = (uint32_t)(shr32(c, c->edx, 15)); /* shr edx, 0xf */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    { int64_t r_ = (int64_t)(int32_t)c->ecx * (int32_t)(uint32_t)0x204u; c->ecx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul ecx, ecx, 0x204 */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->eax + 0x144u)); /* lea ecx, [ecx + eax + 0x144] */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 0xc], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0xfffffffcu))); /* mov ecx, dword ptr [edi - 4] */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    (void)sub32(c, c->esi, c->ecx); /* cmp esi, ecx */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp + 0x10], ecx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ecx + c->edi + 0xfffffffcu))); /* mov ebx, dword ptr [ecx + edi - 4] */
    c->edi = (uint32_t)((uint32_t)(c->ecx + c->edi + 0xfffffffcu)); /* lea edi, [ecx + edi - 4] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 4], ebx */
    if ((c->zf || c->sf != c->of)) goto L_00b972d8; /* jle 0xb972d8 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x1u)); /* test bl, 1 */
    if (!c->zf) goto L_00b972d1; /* jne 0xb972d1 */
    c->ebx = (uint32_t)(add32(c, c->ebx, c->ecx)); /* add ebx, ecx */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if ((!c->zf && c->sf == c->of)) goto L_00b972d1; /* jg 0xb972d1 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 4)); /* sar ecx, 4 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    (void)sub32(c, c->ecx, (uint32_t)0x3fu); /* cmp ecx, 0x3f */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
    if ((c->cf || c->zf)) goto L_00b971a1; /* jbe 0xb971a1 */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
L_00b971a1:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov ebx, dword ptr [edi + 4] */
    (void)sub32(c, c->ebx, R32((uint32_t)(c->edi + 0x8u))); /* cmp ebx, dword ptr [edi + 8] */
    if (!c->zf) goto L_00b971f1; /* jne 0xb971f1 */
    (void)sub32(c, c->ecx, (uint32_t)0x20u); /* cmp ecx, 0x20 */
    if (!c->cf) goto L_00b971cd; /* jae 0xb971cd */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->eax + 0x4u)); /* lea ecx, [ecx + eax + 4] */
    c->ebx = (uint32_t)((uint32_t)~c->ebx); /* not ebx */
    { uint32_t a_ = (uint32_t)(c->eax + c->edx * 4 + 0x44u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [eax + edx*4 + 0x44], ebx */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(dec8(c, R8(a_)))); } /* dec byte ptr [ecx] */
    if (!c->zf) goto L_00b971f1; /* jne 0xb971f1 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [ecx], ebx */
    goto L_00b971f1; /* jmp 0xb971f1 */
L_00b971cd:;
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0xffffffe0u)); /* add ecx, -0x20 */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->eax + 0x4u)); /* lea ecx, [ecx + eax + 4] */
    c->ebx = (uint32_t)((uint32_t)~c->ebx); /* not ebx */
    { uint32_t a_ = (uint32_t)(c->eax + c->edx * 4 + 0xc4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [eax + edx*4 + 0xc4], ebx */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(dec8(c, R8(a_)))); } /* dec byte ptr [ecx] */
    if (!c->zf) goto L_00b971f1; /* jne 0xb971f1 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [ecx + 4], ebx */
L_00b971f1:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov ecx, dword ptr [edi + 8] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov ebx, dword ptr [edi + 4] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [ecx + 4], ebx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov ecx, dword ptr [edi + 4] */
    c->edi = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov edi, dword ptr [edi + 8] */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [ecx + 8], edi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->esi)); /* sub ecx, esi */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(add32(c, R32(a_), c->ecx))); } /* add dword ptr [ebp - 4], ecx */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if ((c->zf || c->sf != c->of)) goto L_00b972bf; /* jle 0xb972bf */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov edi, dword ptr [ebp - 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    c->edi = (uint32_t)(sar32(c, c->edi, 4)); /* sar edi, 4 */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->esi + 0xfffffffcu)); /* lea ecx, [ecx + esi - 4] */
    (void)sub32(c, c->edi, (uint32_t)0x3fu); /* cmp edi, 0x3f */
    if ((c->cf || c->zf)) goto L_00b9722b; /* jbe 0xb9722b */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_00b9722b:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ebx, dword ptr [ebp - 0xc] */
    c->ebx = (uint32_t)((uint32_t)(c->ebx + c->edi * 8)); /* lea ebx, [ebx + edi*8] */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 0x10], ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov ebx, dword ptr [ebx + 4] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [ecx + 4], ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ebx, dword ptr [ebp + 0x10] */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [ecx + 8], ebx */
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [ebx + 4], ecx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ebx, dword ptr [ecx + 4] */
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebx + 8], ecx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ebx, dword ptr [ecx + 4] */
    (void)sub32(c, c->ebx, R32((uint32_t)(c->ecx + 0x8u))); /* cmp ebx, dword ptr [ecx + 8] */
    if (!c->zf) goto L_00b972ad; /* jne 0xb972ad */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi + c->eax + 0x4u))); /* mov cl, byte ptr [edi + eax + 4] */
    (void)sub32(c, c->edi, (uint32_t)0x20u); /* cmp edi, 0x20 */
    W8((uint32_t)(c->ebp + 0x13u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [ebp + 0x13], cl */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(inc8(c, ((uint8_t)c->ecx))); /* inc cl */
    W8((uint32_t)(c->edi + c->eax + 0x4u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [edi + eax + 4], cl */
    if (!c->cf) goto L_00b97284; /* jae 0xb97284 */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x13u)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0x13], 0 */
    if (!c->zf) goto L_00b97277; /* jne 0xb97277 */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->ebx)))); } /* or dword ptr [ecx], ebx */
L_00b97277:;
    c->eax = (uint32_t)((uint32_t)(c->eax + c->edx * 4 + 0x44u)); /* lea eax, [eax + edx*4 + 0x44] */
    c->edx = (uint32_t)((uint32_t)0x80000000u); /* mov edx, 0x80000000 */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    goto L_00b972a9; /* jmp 0xb972a9 */
L_00b97284:;
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x13u)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0x13], 0 */
    if (!c->zf) goto L_00b9729a; /* jne 0xb9729a */
    c->ecx = (uint32_t)((uint32_t)(c->edi + 0xffffffe0u)); /* lea ecx, [edi - 0x20] */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->ebx)))); } /* or dword ptr [ecx + 4], ebx */
L_00b9729a:;
    c->eax = (uint32_t)((uint32_t)(c->eax + c->edx * 4 + 0xc4u)); /* lea eax, [eax + edx*4 + 0xc4] */
    c->ecx = (uint32_t)((uint32_t)(c->edi + 0xffffffe0u)); /* lea ecx, [edi - 0x20] */
    c->edx = (uint32_t)((uint32_t)0x80000000u); /* mov edx, 0x80000000 */
L_00b972a9:;
    c->edx = (uint32_t)(shr32(c, c->edx, (c->ecx & 0xff))); /* shr edx, cl */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edx)))); } /* or dword ptr [eax], edx */
L_00b972ad:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->eax = (uint32_t)((uint32_t)(c->edx + c->esi + 0xfffffffcu)); /* lea eax, [edx + esi - 4] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    W32((uint32_t)(c->ecx + c->eax + 0xfffffffcu), (uint32_t)(c->ecx)); /* mov dword ptr [ecx + eax - 4], ecx */
    goto L_00b972c2; /* jmp 0xb972c2 */
L_00b972bf:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
L_00b972c2:;
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x1u)); /* lea eax, [esi + 1] */
    W32((uint32_t)(c->edx + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edx - 4], eax */
    W32((uint32_t)(c->edx + c->esi + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edx + esi - 8], eax */
    goto L_00b97418; /* jmp 0xb97418 */
L_00b972d1:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00b9741b; /* jmp 0xb9741b */
L_00b972d8:;
    if ((c->sf == c->of)) goto L_00b97418; /* jge 0xb97418 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ebx, dword ptr [ebp + 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x10u); W32(a_, (uint32_t)(sub32(c, R32(a_), c->esi))); } /* sub dword ptr [ebp + 0x10], esi */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x1u)); /* lea ecx, [esi + 1] */
    W32((uint32_t)(c->ebx + 0xfffffffcu), (uint32_t)(c->ecx)); /* mov dword ptr [ebx - 4], ecx */
    c->ebx = (uint32_t)((uint32_t)(c->ebx + c->esi + 0xfffffffcu)); /* lea ebx, [ebx + esi - 4] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov esi, dword ptr [ebp + 0x10] */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 0xc], ebx */
    c->esi = (uint32_t)(sar32(c, c->esi, 4)); /* sar esi, 4 */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    W32((uint32_t)(c->ebx + 0xfffffffcu), (uint32_t)(c->ecx)); /* mov dword ptr [ebx - 4], ecx */
    (void)sub32(c, c->esi, (uint32_t)0x3fu); /* cmp esi, 0x3f */
    if ((c->cf || c->zf)) goto L_00b97303; /* jbe 0xb97303 */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00b97303:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffcu)) & (uint8_t)0x1u)); /* test byte ptr [ebp - 4], 1 */
    if (!c->zf) goto L_00b97392; /* jne 0xb97392 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov esi, dword ptr [ebp - 4] */
    c->esi = (uint32_t)(sar32(c, c->esi, 4)); /* sar esi, 4 */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    (void)sub32(c, c->esi, (uint32_t)0x3fu); /* cmp esi, 0x3f */
    if ((c->cf || c->zf)) goto L_00b9731c; /* jbe 0xb9731c */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00b9731c:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov ecx, dword ptr [edi + 4] */
    (void)sub32(c, c->ecx, R32((uint32_t)(c->edi + 0x8u))); /* cmp ecx, dword ptr [edi + 8] */
    if (!c->zf) goto L_00b9736b; /* jne 0xb9736b */
    (void)sub32(c, c->esi, (uint32_t)0x20u); /* cmp esi, 0x20 */
    if (!c->cf) goto L_00b97347; /* jae 0xb97347 */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->esi = (uint32_t)((uint32_t)(c->esi + c->eax + 0x4u)); /* lea esi, [esi + eax + 4] */
    c->ebx = (uint32_t)((uint32_t)~c->ebx); /* not ebx */
    { uint32_t a_ = (uint32_t)(c->eax + c->edx * 4 + 0x44u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [eax + edx*4 + 0x44], ebx */
    { uint32_t a_ = (uint32_t)(c->esi); W8(a_, (uint8_t)(dec8(c, R8(a_)))); } /* dec byte ptr [esi] */
    if (!c->zf) goto L_00b97368; /* jne 0xb97368 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [ecx], ebx */
    goto L_00b97368; /* jmp 0xb97368 */
L_00b97347:;
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0xffffffe0u)); /* lea ecx, [esi - 0x20] */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->ecx = (uint32_t)((uint32_t)(c->esi + c->eax + 0x4u)); /* lea ecx, [esi + eax + 4] */
    c->ebx = (uint32_t)((uint32_t)~c->ebx); /* not ebx */
    { uint32_t a_ = (uint32_t)(c->eax + c->edx * 4 + 0xc4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [eax + edx*4 + 0xc4], ebx */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(dec8(c, R8(a_)))); } /* dec byte ptr [ecx] */
    if (!c->zf) goto L_00b97368; /* jne 0xb97368 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [ecx + 4], ebx */
L_00b97368:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ebx, dword ptr [ebp + 0xc] */
L_00b9736b:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov ecx, dword ptr [edi + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov esi, dword ptr [edi + 4] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [ecx + 4], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov ecx, dword ptr [edi + 4] */
    c->esi = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov esi, dword ptr [edi + 8] */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ecx + 8], esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov esi, dword ptr [ebp + 0x10] */
    c->esi = (uint32_t)(add32(c, c->esi, R32((uint32_t)(c->ebp + 0xfffffffcu)))); /* add esi, dword ptr [ebp - 4] */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0x10], esi */
    c->esi = (uint32_t)(sar32(c, c->esi, 4)); /* sar esi, 4 */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    (void)sub32(c, c->esi, (uint32_t)0x3fu); /* cmp esi, 0x3f */
    if ((c->cf || c->zf)) goto L_00b97392; /* jbe 0xb97392 */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00b97392:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ecx + c->esi * 8 + 0x4u))); /* mov edi, dword ptr [ecx + esi*8 + 4] */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->esi * 8)); /* lea ecx, [ecx + esi*8] */
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->edi)); /* mov dword ptr [ebx + 4], edi */
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebx + 8], ecx */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [ecx + 4], ebx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov ecx, dword ptr [ebx + 4] */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [ecx + 8], ebx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov ecx, dword ptr [ebx + 4] */
    (void)sub32(c, c->ecx, R32((uint32_t)(c->ebx + 0x8u))); /* cmp ecx, dword ptr [ebx + 8] */
    if (!c->zf) goto L_00b9740f; /* jne 0xb9740f */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + c->eax + 0x4u))); /* mov cl, byte ptr [esi + eax + 4] */
    (void)sub32(c, c->esi, (uint32_t)0x20u); /* cmp esi, 0x20 */
    W8((uint32_t)(c->ebp + 0xfu), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [ebp + 0xf], cl */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(inc8(c, ((uint8_t)c->ecx))); /* inc cl */
    W8((uint32_t)(c->esi + c->eax + 0x4u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esi + eax + 4], cl */
    if (!c->cf) goto L_00b973e6; /* jae 0xb973e6 */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xfu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0xf], 0 */
    if (!c->zf) goto L_00b973d9; /* jne 0xb973d9 */
    c->edi = (uint32_t)((uint32_t)0x80000000u); /* mov edi, 0x80000000 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->edi = (uint32_t)(shr32(c, c->edi, (c->ecx & 0xff))); /* shr edi, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edi)))); } /* or dword ptr [ecx], edi */
L_00b973d9:;
    c->eax = (uint32_t)((uint32_t)(c->eax + c->edx * 4 + 0x44u)); /* lea eax, [eax + edx*4 + 0x44] */
    c->edx = (uint32_t)((uint32_t)0x80000000u); /* mov edx, 0x80000000 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    goto L_00b9740b; /* jmp 0xb9740b */
L_00b973e6:;
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xfu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0xf], 0 */
    if (!c->zf) goto L_00b973fc; /* jne 0xb973fc */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0xffffffe0u)); /* lea ecx, [esi - 0x20] */
    c->edi = (uint32_t)((uint32_t)0x80000000u); /* mov edi, 0x80000000 */
    c->edi = (uint32_t)(shr32(c, c->edi, (c->ecx & 0xff))); /* shr edi, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edi)))); } /* or dword ptr [ecx + 4], edi */
L_00b973fc:;
    c->eax = (uint32_t)((uint32_t)(c->eax + c->edx * 4 + 0xc4u)); /* lea eax, [eax + edx*4 + 0xc4] */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0xffffffe0u)); /* lea ecx, [esi - 0x20] */
    c->edx = (uint32_t)((uint32_t)0x80000000u); /* mov edx, 0x80000000 */
L_00b9740b:;
    c->edx = (uint32_t)(shr32(c, c->edx, (c->ecx & 0xff))); /* shr edx, cl */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edx)))); } /* or dword ptr [eax], edx */
L_00b9740f:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
    W32((uint32_t)(c->eax + c->ebx + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [eax + ebx - 4], eax */
L_00b97418:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00b9741b:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b97420(CPU *c) { /* FUN_10007420 */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(0xb9c4c8u)), (uint32_t)0xffffffffu); /* cmp dword ptr [0x1000c4c8], -1 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00b97434; /* jne 0xb97434 */
    c->esi = (uint32_t)((uint32_t)0xb9c4b8u); /* mov esi, 0x1000c4b8 */
    goto L_00b97451; /* jmp 0xb97451 */
L_00b97434:;
    { uint32_t v_ = 0x2020u; PUSH32(c, v_); } /* push 0x2020 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb9f564u)); PUSH32(c, v_); } /* push dword ptr [0x1000f564] */
    { uint32_t t_ = R32((uint32_t)(0xb9b03cu)); PUSH32(c, 0x00b97447u); call_indirect(c, t_); } /* call dword ptr [0x1000b03c] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00b9755d; /* je 0xb9755d */
L_00b97451:;
    c->ebp = (uint32_t)(R32((uint32_t)(0xb9b0b0u))); /* mov ebp, dword ptr [0x1000b0b0] */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = 0x2000u; PUSH32(c, v_); } /* push 0x2000 */
    { uint32_t v_ = 0x400000u; PUSH32(c, v_); } /* push 0x400000 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t t_ = c->ebp; PUSH32(c, 0x00b97467u); call_indirect(c, t_); } /* call ebp */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00b97546; /* je 0xb97546 */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    c->ebx = (uint32_t)((uint32_t)0x10000u); /* mov ebx, 0x10000 */
    { uint32_t v_ = 0x1000u; PUSH32(c, v_); } /* push 0x1000 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = c->ebp; PUSH32(c, 0x00b97481u); call_indirect(c, t_); } /* call ebp */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b97538; /* je 0xb97538 */
    c->eax = (uint32_t)((uint32_t)0xb9c4b8u); /* mov eax, 0x1000c4b8 */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if (!c->zf) goto L_00b974b0; /* jne 0xb974b0 */
    (void)sub32(c, R32((uint32_t)(0xb9c4b8u)), (uint32_t)0x0u); /* cmp dword ptr [0x1000c4b8], 0 */
    if (!c->zf) goto L_00b974a0; /* jne 0xb974a0 */
    W32((uint32_t)(0xb9c4b8u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000c4b8], eax */
L_00b974a0:;
    (void)sub32(c, R32((uint32_t)(0xb9c4bcu)), (uint32_t)0x0u); /* cmp dword ptr [0x1000c4bc], 0 */
    if (!c->zf) goto L_00b974c5; /* jne 0xb974c5 */
    W32((uint32_t)(0xb9c4bcu), (uint32_t)(c->eax)); /* mov dword ptr [0x1000c4bc], eax */
    goto L_00b974c5; /* jmp 0xb974c5 */
L_00b974b0:;
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    c->eax = (uint32_t)(R32((uint32_t)(0xb9c4bcu))); /* mov eax, dword ptr [0x1000c4bc] */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 4], eax */
    W32((uint32_t)(0xb9c4bcu), (uint32_t)(c->esi)); /* mov dword ptr [0x1000c4bc], esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    W32((uint32_t)(c->eax), (uint32_t)(c->esi)); /* mov dword ptr [eax], esi */
L_00b974c5:;
    c->eax = (uint32_t)((uint32_t)(c->edi + 0x400000u)); /* lea eax, [edi + 0x400000] */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x98u)); /* lea ecx, [esi + 0x98] */
    W32((uint32_t)(c->esi + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x14], eax */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x18u)); /* lea eax, [esi + 0x18] */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 0xc], ecx */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0x10], edi */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 8], eax */
    c->ebp = (uint32_t)(logic32(c, 0)); /* xor ebp, ebp */
    c->ecx = (uint32_t)((uint32_t)0xf1u); /* mov ecx, 0xf1 */
L_00b974e7:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    (void)sub32(c, c->ebp, (uint32_t)0x10u); /* cmp ebp, 0x10 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)((c->sf == c->of) ? 1 : 0); /* setge dl */
    c->edx = (uint32_t)(dec32(c, c->edx)); /* dec edx */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & c->ecx))); /* and edx, ecx */
    c->edx = (uint32_t)(dec32(c, c->edx)); /* dec edx */
    c->ebp = (uint32_t)(inc32(c, c->ebp)); /* inc ebp */
    W32((uint32_t)(c->eax), (uint32_t)(c->edx)); /* mov dword ptr [eax], edx */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 4], ecx */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
    (void)sub32(c, c->ebp, (uint32_t)0x400u); /* cmp ebp, 0x400 */
    if ((c->sf != c->of)) goto L_00b974e7; /* jl 0xb974e7 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b9750du); f_00b987c0(c); /* call 0xb987c0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_00b97510:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(add32(c, c->eax, c->ebx)); /* add eax, ebx */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (!c->cf) goto L_00b97534; /* jae 0xb97534 */
    { uint32_t a_ = (uint32_t)(c->edi + 0xf8u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0xffu)))); } /* or byte ptr [edi + 0xf8], 0xff */
    c->eax = (uint32_t)((uint32_t)(c->edi + 0x8u)); /* lea eax, [edi + 8] */
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    W32((uint32_t)(c->edi + 0x4u), (uint32_t)((uint32_t)0xf0u)); /* mov dword ptr [edi + 4], 0xf0 */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x1000u)); /* add edi, 0x1000 */
    goto L_00b97510; /* jmp 0xb97510 */
L_00b97534:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    goto L_00b9755f; /* jmp 0xb9755f */
L_00b97538:;
    { uint32_t v_ = 0x8000u; PUSH32(c, v_); } /* push 0x8000 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0xb9b09cu)); PUSH32(c, 0x00b97546u); call_indirect(c, t_); } /* call dword ptr [0x1000b09c] */
L_00b97546:;
    (void)sub32(c, c->esi, (uint32_t)0xb9c4b8u); /* cmp esi, 0x1000c4b8 */
    if (c->zf) goto L_00b9755d; /* je 0xb9755d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb9f564u)); PUSH32(c, v_); } /* push dword ptr [0x1000f564] */
    { uint32_t t_ = R32((uint32_t)(0xb9b05cu)); PUSH32(c, 0x00b9755du); call_indirect(c, t_); } /* call dword ptr [0x1000b05c] */
L_00b9755d:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00b9755f:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00b97564(CPU *c) { /* FUN_10007564 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    { uint32_t v_ = 0x8000u; PUSH32(c, v_); } /* push 0x8000 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x10] */
    { uint32_t t_ = R32((uint32_t)(0xb9b09cu)); PUSH32(c, 0x00b97579u); call_indirect(c, t_); } /* call dword ptr [0x1000b09c] */
    (void)sub32(c, R32((uint32_t)(0xb9e4d8u)), c->esi); /* cmp dword ptr [0x1000e4d8], esi */
    if (!c->zf) goto L_00b97589; /* jne 0xb97589 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    W32((uint32_t)(0xb9e4d8u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000e4d8], eax */
L_00b97589:;
    (void)sub32(c, c->esi, (uint32_t)0xb9c4b8u); /* cmp esi, 0x1000c4b8 */
    if (c->zf) goto L_00b975b1; /* je 0xb975b1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 4], ecx */
    { uint32_t v_ = R32((uint32_t)(0xb9f564u)); PUSH32(c, v_); } /* push dword ptr [0x1000f564] */
    { uint32_t t_ = R32((uint32_t)(0xb9b05cu)); PUSH32(c, 0x00b975afu); call_indirect(c, t_); } /* call dword ptr [0x1000b05c] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_00b975b1:;
    { uint32_t a_ = (uint32_t)(0xb9c4c8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [0x1000c4c8], 0xffffffff */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b975ba(CPU *c) { /* FUN_100075ba */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(0xb9c4bcu))); /* mov esi, dword ptr [0x1000c4bc] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
L_00b975c7:;
    (void)sub32(c, R32((uint32_t)(c->esi + 0x10u)), (uint32_t)0xffffffffu); /* cmp dword ptr [esi + 0x10], -1 */
    if (c->zf) goto L_00b97665; /* je 0xb97665 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x2010u)); /* lea edi, [esi + 0x2010] */
    c->ebx = (uint32_t)((uint32_t)0x3ff000u); /* mov ebx, 0x3ff000 */
L_00b975e0:;
    (void)sub32(c, R32((uint32_t)(c->edi)), (uint32_t)0xf0u); /* cmp dword ptr [edi], 0xf0 */
    if (!c->zf) goto L_00b97621; /* jne 0xb97621 */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = 0x4000u; PUSH32(c, v_); } /* push 0x4000 */
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->esi + 0x10u)))); /* add eax, dword ptr [esi + 0x10] */
    { uint32_t v_ = 0x1000u; PUSH32(c, v_); } /* push 0x1000 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0xb9b09cu)); PUSH32(c, 0x00b975feu); call_indirect(c, t_); } /* call dword ptr [0x1000b09c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b97621; /* je 0xb97621 */
    { uint32_t a_ = (uint32_t)(c->edi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [edi], 0xffffffff */
    { uint32_t a_ = (uint32_t)(0xb9f180u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [0x1000f180] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b97616; /* je 0xb97616 */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if ((c->cf || c->zf)) goto L_00b97619; /* jbe 0xb97619 */
L_00b97616:;
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0xc], edi */
L_00b97619:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 8] */
    if (c->zf) goto L_00b9762e; /* je 0xb9762e */
L_00b97621:;
    c->ebx = (uint32_t)(sub32(c, c->ebx, (uint32_t)0x1000u)); /* sub ebx, 0x1000 */
    c->edi = (uint32_t)(sub32(c, c->edi, (uint32_t)0x8u)); /* sub edi, 8 */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if ((c->sf == c->of)) goto L_00b975e0; /* jge 0xb975e0 */
L_00b9762e:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov esi, dword ptr [esi + 4] */
    if (c->zf) goto L_00b97665; /* je 0xb97665 */
    (void)sub32(c, R32((uint32_t)(c->ecx + 0x18u)), (uint32_t)0xffffffffu); /* cmp dword ptr [ecx + 0x18], -1 */
    if (!c->zf) goto L_00b97665; /* jne 0xb97665 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0x20u)); /* lea eax, [ecx + 0x20] */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
L_00b97645:;
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xffffffffu); /* cmp dword ptr [eax], -1 */
    if (!c->zf) goto L_00b97656; /* jne 0xb97656 */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
    (void)sub32(c, c->edx, (uint32_t)0x400u); /* cmp edx, 0x400 */
    if ((c->sf != c->of)) goto L_00b97645; /* jl 0xb97645 */
L_00b97656:;
    (void)sub32(c, c->edx, (uint32_t)0x400u); /* cmp edx, 0x400 */
    if (!c->zf) goto L_00b97665; /* jne 0xb97665 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00b97664u); f_00b97564(c); /* call 0xb97564 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b97665:;
    (void)sub32(c, c->esi, R32((uint32_t)(0xb9c4bcu))); /* cmp esi, dword ptr [0x1000c4bc] */
    if (c->zf) goto L_00b97677; /* je 0xb97677 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_00b975c7; /* jg 0xb975c7 */
L_00b97677:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b9767c(CPU *c) { /* FUN_1000767c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->edx = (uint32_t)((uint32_t)0xb9c4b8u); /* mov edx, 0x1000c4b8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
L_00b97688:;
    (void)sub32(c, c->eax, R32((uint32_t)(c->ecx + 0x10u))); /* cmp eax, dword ptr [ecx + 0x10] */
    if ((c->cf || c->zf)) goto L_00b97692; /* jbe 0xb97692 */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ecx + 0x14u))); /* cmp eax, dword ptr [ecx + 0x14] */
    if (c->cf) goto L_00b9769a; /* jb 0xb9769a */
L_00b97692:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov ecx, dword ptr [ecx] */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if (c->zf) goto L_00b976cf; /* je 0xb976cf */
    goto L_00b97688; /* jmp 0xb97688 */
L_00b9769a:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfu)); /* test al, 0xf */
    if (!c->zf) goto L_00b976cf; /* jne 0xb976cf */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->edx = (uint32_t)((uint32_t)0x100u); /* mov edx, 0x100 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffu))); /* and esi, 0xfff */
    (void)sub32(c, c->esi, c->edx); /* cmp esi, edx */
    if (c->cf) goto L_00b976cf; /* jb 0xb976cf */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov esi, dword ptr [esp + 0xc] */
    W32((uint32_t)(c->esi), (uint32_t)(c->ecx)); /* mov dword ptr [esi], ecx */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->ecx = (c->ecx & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->ecx) & (uint16_t)0xf000u))); /* and cx, 0xf000 */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    W32((uint32_t)(c->esi), (uint32_t)(c->ecx)); /* mov dword ptr [esi], ecx */
    c->eax = (uint32_t)(sub32(c, c->eax, c->edx)); /* sub eax, edx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)(sar32(c, c->eax, 4)); /* sar eax, 4 */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->ecx + 0x8u)); /* lea eax, [eax + ecx + 8] */
    c->esp += 4; return; /* ret  */
L_00b976cf:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b976d3(CPU *c) { /* FUN_100076d3 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, R32((uint32_t)(c->eax + 0x10u)))); /* sub ecx, dword ptr [eax + 0x10] */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 12)); /* sar ecx, 0xc */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->ecx * 8 + 0x18u)); /* lea eax, [eax + ecx*8 + 0x18] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    c->edx = (uint32_t)((uint32_t)R8((uint32_t)(c->ecx))); /* movzx edx, byte ptr [ecx] */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(add32(c, R32(a_), c->edx))); } /* add dword ptr [eax], edx */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ecx], 0 */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xf0u); /* cmp dword ptr [eax], 0xf0 */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)((uint32_t)0xf1u)); /* mov dword ptr [eax + 4], 0xf1 */
    if (!c->zf) goto L_00b97717; /* jne 0xb97717 */
    { uint32_t a_ = (uint32_t)(0xb9f180u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [0x1000f180] */
    (void)sub32(c, R32((uint32_t)(0xb9f180u)), (uint32_t)0x20u); /* cmp dword ptr [0x1000f180], 0x20 */
    if (!c->zf) goto L_00b97717; /* jne 0xb97717 */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    PUSH32(c, 0x00b97716u); f_00b975ba(c); /* call 0xb975ba */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b97717:;
    c->esp += 4; return; /* ret  */
}

void f_00b97718(CPU *c) { /* FUN_10007718 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(0xb9e4d8u))); /* mov esi, dword ptr [0x1000e4d8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
L_00b97726:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov edx, dword ptr [esi + 0x10] */
    (void)sub32(c, c->edx, (uint32_t)0xffffffffu); /* cmp edx, -1 */
    if (c->zf) goto L_00b977d1; /* je 0xb977d1 */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov edi, dword ptr [esi + 8] */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x2018u)); /* lea ecx, [esi + 0x2018] */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->eax = (uint32_t)(sub32(c, c->eax, c->esi)); /* sub eax, esi */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x18u)); /* sub eax, 0x18 */
    c->eax = (uint32_t)(sar32(c, c->eax, 3)); /* sar eax, 3 */
    c->eax = (uint32_t)(shl32(c, c->eax, 12)); /* shl eax, 0xc */
    c->eax = (uint32_t)(add32(c, c->eax, c->edx)); /* add eax, edx */
    (void)sub32(c, c->edi, c->ecx); /* cmp edi, ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    if (!c->cf) goto L_00b9778b; /* jae 0xb9778b */
L_00b97751:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi))); /* mov ecx, dword ptr [edi] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    (void)sub32(c, c->ecx, c->ebx); /* cmp ecx, ebx */
    if ((c->sf != c->of)) goto L_00b97774; /* jl 0xb97774 */
    (void)sub32(c, R32((uint32_t)(c->edi + 0x4u)), c->ebx); /* cmp dword ptr [edi + 4], ebx */
    if ((c->cf || c->zf)) goto L_00b97774; /* jbe 0xb97774 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b97767u); f_00b97920(c); /* call 0xb97920 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b977e3; /* jne 0xb977e3 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    W32((uint32_t)(c->edi + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [edi + 4], ebx */
L_00b97774:;
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x8u)); /* add edi, 8 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x2018u)); /* lea ecx, [esi + 0x2018] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x1000u)); /* add eax, 0x1000 */
    (void)sub32(c, c->edi, c->ecx); /* cmp edi, ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    if (c->cf) goto L_00b97751; /* jb 0xb97751 */
    goto L_00b9778e; /* jmp 0xb9778e */
L_00b9778b:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00b9778e:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x18u)); /* lea edi, [esi + 0x18] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 4], ecx */
    if (!c->cf) goto L_00b977d4; /* jae 0xb977d4 */
L_00b977a1:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if ((c->sf != c->of)) goto L_00b977c0; /* jl 0xb977c0 */
    (void)sub32(c, R32((uint32_t)(c->edi + 0x4u)), c->ebx); /* cmp dword ptr [edi + 4], ebx */
    if ((c->cf || c->zf)) goto L_00b977c0; /* jbe 0xb977c0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    PUSH32(c, 0x00b977b6u); f_00b97920(c); /* call 0xb97920 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b977e3; /* jne 0xb977e3 */
    W32((uint32_t)(c->edi + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [edi + 4], ebx */
L_00b977c0:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x1000u))); } /* add dword ptr [ebp - 4], 0x1000 */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x8u)); /* add edi, 8 */
    (void)sub32(c, c->edi, R32((uint32_t)(c->ebp + 0xfffffff8u))); /* cmp edi, dword ptr [ebp - 8] */
    if (c->cf) goto L_00b977a1; /* jb 0xb977a1 */
    goto L_00b977d4; /* jmp 0xb977d4 */
L_00b977d1:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00b977d4:;
    c->esi = (uint32_t)(R32((uint32_t)(c->esi))); /* mov esi, dword ptr [esi] */
    (void)sub32(c, c->esi, R32((uint32_t)(0xb9e4d8u))); /* cmp esi, dword ptr [0x1000e4d8] */
    if (c->zf) goto L_00b977f3; /* je 0xb977f3 */
    goto L_00b97726; /* jmp 0xb97726 */
L_00b977e3:;
    W32((uint32_t)(0xb9e4d8u), (uint32_t)(c->esi)); /* mov dword ptr [0x1000e4d8], esi */
    { uint32_t a_ = (uint32_t)(c->edi); W32(a_, (uint32_t)(sub32(c, R32(a_), c->ebx))); } /* sub dword ptr [edi], ebx */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 8], edi */
    goto L_00b9791b; /* jmp 0xb9791b */
L_00b977f3:;
    c->eax = (uint32_t)((uint32_t)0xb9c4b8u); /* mov eax, 0x1000c4b8 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
L_00b977fa:;
    (void)sub32(c, R32((uint32_t)(c->edi + 0x10u)), (uint32_t)0xffffffffu); /* cmp dword ptr [edi + 0x10], -1 */
    if (c->zf) goto L_00b97806; /* je 0xb97806 */
    (void)sub32(c, R32((uint32_t)(c->edi + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [edi + 0xc], 0 */
    if (!c->zf) goto L_00b97812; /* jne 0xb97812 */
L_00b97806:;
    c->edi = (uint32_t)(R32((uint32_t)(c->edi))); /* mov edi, dword ptr [edi] */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->zf) goto L_00b978e7; /* je 0xb978e7 */
    goto L_00b977fa; /* jmp 0xb977fa */
L_00b97812:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->edi + 0xcu))); /* mov ebx, dword ptr [edi + 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    c->esi = (uint32_t)(c->ebx); /* mov esi, ebx */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->esi = (uint32_t)(sub32(c, c->esi, c->edi)); /* sub esi, edi */
    c->esi = (uint32_t)(sub32(c, c->esi, (uint32_t)0x18u)); /* sub esi, 0x18 */
    c->esi = (uint32_t)(sar32(c, c->esi, 3)); /* sar esi, 3 */
    c->esi = (uint32_t)(shl32(c, c->esi, 12)); /* shl esi, 0xc */
    c->esi = (uint32_t)(add32(c, c->esi, R32((uint32_t)(c->edi + 0x10u)))); /* add esi, dword ptr [edi + 0x10] */
    (void)sub32(c, R32((uint32_t)(c->ebx)), (uint32_t)0xffffffffu); /* cmp dword ptr [ebx], -1 */
    if (!c->zf) goto L_00b97841; /* jne 0xb97841 */
L_00b97830:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x10u); /* cmp dword ptr [ebp - 4], 0x10 */
    if ((c->sf == c->of)) goto L_00b97841; /* jge 0xb97841 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xffffffffu); /* cmp dword ptr [eax], -1 */
    if (c->zf) goto L_00b97830; /* je 0xb97830 */
L_00b97841:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    c->eax = (uint32_t)(shl32(c, c->eax, 12)); /* shl eax, 0xc */
    { uint32_t v_ = 0x1000u; PUSH32(c, v_); } /* push 0x1000 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    { uint32_t t_ = R32((uint32_t)(0xb9b0b0u)); PUSH32(c, 0x00b97859u); call_indirect(c, t_); } /* call dword ptr [0x1000b0b0] */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (!c->zf) goto L_00b97919; /* jne 0xb97919 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffff8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b9786cu); f_00b987c0(c); /* call 0xb987c0 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov edx, dword ptr [ebp - 4] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    if ((c->zf || c->sf != c->of)) goto L_00b978a8; /* jle 0xb978a8 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x4u)); /* lea eax, [esi + 4] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 4], edx */
L_00b9787e:;
    { uint32_t a_ = (uint32_t)(c->eax + 0xf4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0xffu)))); } /* or byte ptr [eax + 0xf4], 0xff */
    c->edx = (uint32_t)((uint32_t)(c->eax + 0x4u)); /* lea edx, [eax + 4] */
    W32((uint32_t)(c->eax + 0xfffffffcu), (uint32_t)(c->edx)); /* mov dword ptr [eax - 4], edx */
    c->edx = (uint32_t)((uint32_t)0xf0u); /* mov edx, 0xf0 */
    W32((uint32_t)(c->eax), (uint32_t)(c->edx)); /* mov dword ptr [eax], edx */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)((uint32_t)0xf1u)); /* mov dword ptr [ecx + 4], 0xf1 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x1000u)); /* add eax, 0x1000 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x8u)); /* add ecx, 8 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 4] */
    if (!c->zf) goto L_00b9787e; /* jne 0xb9787e */
L_00b978a8:;
    W32((uint32_t)(0xb9e4d8u), (uint32_t)(c->edi)); /* mov dword ptr [0x1000e4d8], edi */
    c->eax = (uint32_t)((uint32_t)(c->edi + 0x2018u)); /* lea eax, [edi + 0x2018] */
L_00b978b4:;
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
    if (!c->cf) goto L_00b978c4; /* jae 0xb978c4 */
    (void)sub32(c, R32((uint32_t)(c->ecx)), (uint32_t)0xffffffffu); /* cmp dword ptr [ecx], -1 */
    if (c->zf) goto L_00b978c2; /* je 0xb978c2 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x8u)); /* add ecx, 8 */
    goto L_00b978b4; /* jmp 0xb978b4 */
L_00b978c2:;
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
L_00b978c4:;
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & c->ecx))); /* and eax, ecx */
    W32((uint32_t)(c->edi + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + 0xc], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W8((uint32_t)(c->esi + 0x8u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [esi + 8], al */
    W32((uint32_t)(c->edi + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [edi + 8], ebx */
    { uint32_t a_ = (uint32_t)(c->ebx); W32(a_, (uint32_t)(sub32(c, R32(a_), c->eax))); } /* sub dword ptr [ebx], eax */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W32(a_, (uint32_t)(sub32(c, R32(a_), c->eax))); } /* sub dword ptr [esi + 4], eax */
    c->ecx = (uint32_t)((uint32_t)(c->esi + c->eax + 0x8u)); /* lea ecx, [esi + eax + 8] */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x100u)); /* lea eax, [esi + 0x100] */
    W32((uint32_t)(c->esi), (uint32_t)(c->ecx)); /* mov dword ptr [esi], ecx */
    goto L_00b9791b; /* jmp 0xb9791b */
L_00b978e7:;
    PUSH32(c, 0x00b978ecu); f_00b97420(c); /* call 0xb97420 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b97919; /* je 0xb97919 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x10u))); /* mov ecx, dword ptr [eax + 0x10] */
    W8((uint32_t)(c->ecx + 0x8u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ecx + 8], bl */
    c->edx = (uint32_t)((uint32_t)(c->ecx + c->ebx + 0x8u)); /* lea edx, [ecx + ebx + 8] */
    W32((uint32_t)(0xb9e4d8u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000e4d8], eax */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    c->edx = (uint32_t)((uint32_t)0xf0u); /* mov edx, 0xf0 */
    c->edx = (uint32_t)(sub32(c, c->edx, c->ebx)); /* sub edx, ebx */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 4], edx */
    c->edx = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx edx, bl */
    { uint32_t a_ = (uint32_t)(c->eax + 0x18u); W32(a_, (uint32_t)(sub32(c, R32(a_), c->edx))); } /* sub dword ptr [eax + 0x18], edx */
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0x100u)); /* lea eax, [ecx + 0x100] */
    goto L_00b9791b; /* jmp 0xb9791b */
L_00b97919:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00b9791b:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b97920(CPU *c) { /* FUN_10007920 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edx, dword ptr [ebp + 0x10] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov esi, dword ptr [ecx + 4] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edi, dword ptr [ecx] */
    c->ebx = (uint32_t)((uint32_t)(c->ecx + 0xf8u)); /* lea ebx, [ecx + 0xf8] */
    (void)sub32(c, c->esi, c->edx); /* cmp esi, edx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 4], edi */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 8], ebx */
    if (c->cf) goto L_00b97965; /* jb 0xb97965 */
    c->eax = (uint32_t)((uint32_t)(c->edi + c->edx)); /* lea eax, [edi + edx] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [edi], dl */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (!c->cf) goto L_00b97954; /* jae 0xb97954 */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(add32(c, R32(a_), c->edx))); } /* add dword ptr [ecx], edx */
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(sub32(c, R32(a_), c->edx))); } /* sub dword ptr [ecx + 4], edx */
    goto L_00b9795d; /* jmp 0xb9795d */
L_00b97954:;
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ecx + 4], 0 */
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0x8u)); /* lea eax, [ecx + 8] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
L_00b9795d:;
    c->eax = (uint32_t)((uint32_t)(c->edi + 0x8u)); /* lea eax, [edi + 8] */
    goto L_00b97a33; /* jmp 0xb97a33 */
L_00b97965:;
    c->esi = (uint32_t)(add32(c, c->esi, c->edi)); /* add esi, edi */
    (void)sub8(c, R8((uint32_t)(c->esi)), (uint8_t)0x0u); /* cmp byte ptr [esi], 0 */
    if (c->zf) goto L_00b9796e; /* je 0xb9796e */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00b9796e:;
    c->esi = (uint32_t)((uint32_t)(c->eax + c->edx)); /* lea esi, [eax + edx] */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (!c->cf) goto L_00b979b8; /* jae 0xb979b8 */
L_00b97975:;
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov bl, byte ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & ((uint8_t)c->ebx))); /* test bl, bl */
    if (!c->zf) goto L_00b979ab; /* jne 0xb979ab */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ebx = (uint32_t)((uint32_t)(c->eax + 0x1u)); /* lea ebx, [eax + 1] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00b97981:;
    (void)sub8(c, R8((uint32_t)(c->ebx)), (uint8_t)0x0u); /* cmp byte ptr [ebx], 0 */
    if (!c->zf) goto L_00b9798a; /* jne 0xb9798a */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    goto L_00b97981; /* jmp 0xb97981 */
L_00b9798a:;
    (void)sub32(c, c->esi, c->edx); /* cmp esi, edx */
    if (!c->cf) goto L_00b979dc; /* jae 0xb979dc */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xfffffffcu))); /* cmp eax, dword ptr [ebp - 4] */
    if (!c->zf) goto L_00b97998; /* jne 0xb97998 */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [ecx + 4], esi */
    goto L_00b979a4; /* jmp 0xb979a4 */
L_00b97998:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(sub32(c, R32(a_), c->esi))); } /* sub dword ptr [ebp + 0xc], esi */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->edx); /* cmp dword ptr [ebp + 0xc], edx */
    if (c->cf) goto L_00b97a3d; /* jb 0xb97a3d */
L_00b979a4:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov edi, dword ptr [ebp - 4] */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    goto L_00b979b0; /* jmp 0xb979b0 */
L_00b979ab:;
    c->esi = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx esi, bl */
    c->eax = (uint32_t)(add32(c, c->eax, c->esi)); /* add eax, esi */
L_00b979b0:;
    c->esi = (uint32_t)((uint32_t)(c->eax + c->edx)); /* lea esi, [eax + edx] */
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0x8u))); /* cmp esi, dword ptr [ebp + 8] */
    if (c->cf) goto L_00b97975; /* jb 0xb97975 */
L_00b979b8:;
    c->esi = (uint32_t)((uint32_t)(c->ecx + 0x8u)); /* lea esi, [ecx + 8] */
L_00b979bb:;
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->cf) goto L_00b97a3d; /* jae 0xb97a3d */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->edx)); /* lea eax, [esi + edx] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0x8u))); /* cmp eax, dword ptr [ebp + 8] */
    if (!c->cf) goto L_00b97a3d; /* jae 0xb97a3d */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00b97a0d; /* jne 0xb97a0d */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ebx = (uint32_t)((uint32_t)(c->esi + 0x1u)); /* lea ebx, [esi + 1] */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00b979d3:;
    (void)sub8(c, R8((uint32_t)(c->ebx)), (uint8_t)0x0u); /* cmp byte ptr [ebx], 0 */
    if (!c->zf) goto L_00b979fd; /* jne 0xb979fd */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_00b979d3; /* jmp 0xb979d3 */
L_00b979dc:;
    c->ebx = (uint32_t)((uint32_t)(c->eax + c->edx)); /* lea ebx, [eax + edx] */
    (void)sub32(c, c->ebx, R32((uint32_t)(c->ebp + 0x8u))); /* cmp ebx, dword ptr [ebp + 8] */
    if (!c->cf) goto L_00b979ed; /* jae 0xb979ed */
    c->esi = (uint32_t)(sub32(c, c->esi, c->edx)); /* sub esi, edx */
    W32((uint32_t)(c->ecx), (uint32_t)(c->ebx)); /* mov dword ptr [ecx], ebx */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [ecx + 4], esi */
    goto L_00b979f6; /* jmp 0xb979f6 */
L_00b979ed:;
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ecx + 4], 0 */
    c->esi = (uint32_t)((uint32_t)(c->ecx + 0x8u)); /* lea esi, [ecx + 8] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->esi)); /* mov dword ptr [ecx], esi */
L_00b979f6:;
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [eax], dl */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
    goto L_00b97a33; /* jmp 0xb97a33 */
L_00b979fd:;
    (void)sub32(c, c->eax, c->edx); /* cmp eax, edx */
    if (!c->cf) goto L_00b97a14; /* jae 0xb97a14 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(sub32(c, R32(a_), c->eax))); } /* sub dword ptr [ebp + 0xc], eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->edx); /* cmp dword ptr [ebp + 0xc], edx */
    if (c->cf) goto L_00b97a3d; /* jb 0xb97a3d */
    c->esi = (uint32_t)(c->ebx); /* mov esi, ebx */
    goto L_00b979bb; /* jmp 0xb979bb */
L_00b97a0d:;
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->eax)); /* movzx eax, al */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    goto L_00b979bb; /* jmp 0xb979bb */
L_00b97a14:;
    c->ebx = (uint32_t)((uint32_t)(c->esi + c->edx)); /* lea ebx, [esi + edx] */
    (void)sub32(c, c->ebx, R32((uint32_t)(c->ebp + 0x8u))); /* cmp ebx, dword ptr [ebp + 8] */
    if (!c->cf) goto L_00b97a25; /* jae 0xb97a25 */
    c->eax = (uint32_t)(sub32(c, c->eax, c->edx)); /* sub eax, edx */
    W32((uint32_t)(c->ecx), (uint32_t)(c->ebx)); /* mov dword ptr [ecx], ebx */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 4], eax */
    goto L_00b97a2e; /* jmp 0xb97a2e */
L_00b97a25:;
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ecx + 4], 0 */
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0x8u)); /* lea eax, [ecx + 8] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
L_00b97a2e:;
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x8u)); /* lea eax, [esi + 8] */
L_00b97a33:;
    { int64_t r_ = (int64_t)(int32_t)c->ecx * (int32_t)(uint32_t)0xfu; c->ecx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul ecx, ecx, 0xf */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    goto L_00b97a3f; /* jmp 0xb97a3f */
L_00b97a3d:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00b97a3f:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b97a44(CPU *c) { /* FUN_10007a44 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edx, dword ptr [ebp + 0x10] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ebx, dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ecx = (uint32_t)((uint32_t)R8((uint32_t)(c->edx))); /* movzx ecx, byte ptr [edx] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->edi + 0x10u)))); /* sub eax, dword ptr [edi + 0x10] */
    c->eax = (uint32_t)(sar32(c, c->eax, 12)); /* sar eax, 0xc */
    (void)sub32(c, c->ecx, R32((uint32_t)(c->ebp + 0x14u))); /* cmp ecx, dword ptr [ebp + 0x14] */
    c->edi = (uint32_t)((uint32_t)(c->edi + c->eax * 8 + 0x18u)); /* lea edi, [edi + eax*8 + 0x18] */
    if ((c->cf || c->zf)) goto L_00b97a7e; /* jbe 0xb97a7e */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    W8((uint32_t)(c->edx), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edx], al */
    { uint32_t a_ = (uint32_t)(c->edi); W32(a_, (uint32_t)(add32(c, R32(a_), c->ecx))); } /* add dword ptr [edi], ecx */
    W32((uint32_t)(c->edi + 0x4u), (uint32_t)((uint32_t)0xf1u)); /* mov dword ptr [edi + 4], 0xf1 */
    goto L_00b97ade; /* jmp 0xb97ade */
L_00b97a7e:;
    if (!c->cf) goto L_00b97ae5; /* jae 0xb97ae5 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    c->esi = (uint32_t)((uint32_t)(c->edx + c->eax)); /* lea esi, [edx + eax] */
    c->eax = (uint32_t)((uint32_t)(c->ebx + 0xf8u)); /* lea eax, [ebx + 0xf8] */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00b97ae5; /* jb 0xb97ae5 */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->edx)); /* lea eax, [ecx + edx] */
L_00b97a93:;
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (!c->cf) goto L_00b97aa1; /* jae 0xb97aa1 */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (!c->zf) goto L_00b97a9f; /* jne 0xb97a9f */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_00b97a93; /* jmp 0xb97a93 */
L_00b97a9f:;
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
L_00b97aa1:;
    if (!c->zf) goto L_00b97ae5; /* jne 0xb97ae5 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0x14u))); /* mov al, byte ptr [ebp + 0x14] */
    W8((uint32_t)(c->edx), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edx], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    (void)sub32(c, c->edx, c->eax); /* cmp edx, eax */
    if ((!c->cf && !c->zf)) goto L_00b97ad9; /* ja 0xb97ad9 */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if ((c->cf || c->zf)) goto L_00b97ad9; /* jbe 0xb97ad9 */
    c->eax = (uint32_t)((uint32_t)(c->ebx + 0xf8u)); /* lea eax, [ebx + 0xf8] */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if (!c->cf) goto L_00b97ad0; /* jae 0xb97ad0 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W32((uint32_t)(c->ebx), (uint32_t)(c->esi)); /* mov dword ptr [ebx], esi */
    (void)sub8(c, R8((uint32_t)(c->esi)), ((uint8_t)c->eax)); /* cmp byte ptr [esi], al */
    if (!c->zf) goto L_00b97acb; /* jne 0xb97acb */
L_00b97ac4:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub8(c, R8((uint32_t)(c->esi + c->eax)), (uint8_t)0x0u); /* cmp byte ptr [esi + eax], 0 */
    if (c->zf) goto L_00b97ac4; /* je 0xb97ac4 */
L_00b97acb:;
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 4], eax */
    goto L_00b97ad9; /* jmp 0xb97ad9 */
L_00b97ad0:;
    { uint32_t a_ = (uint32_t)(c->ebx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebx + 4], 0 */
    c->eax = (uint32_t)((uint32_t)(c->ebx + 0x8u)); /* lea eax, [ebx + 8] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
L_00b97ad9:;
    c->ecx = (uint32_t)(sub32(c, c->ecx, R32((uint32_t)(c->ebp + 0x14u)))); /* sub ecx, dword ptr [ebp + 0x14] */
    { uint32_t a_ = (uint32_t)(c->edi); W32(a_, (uint32_t)(add32(c, R32(a_), c->ecx))); } /* add dword ptr [edi], ecx */
L_00b97ade:;
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
L_00b97ae5:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b97aed(CPU *c) { /* FUN_10007aed */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0xb9f184u))); /* mov eax, dword ptr [0x1000f184] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b97b05; /* je 0xb97b05 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00b97afcu); call_indirect(c, t_); } /* call eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00b97b05; /* je 0xb97b05 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
L_00b97b05:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_00b97b10(CPU *c) { /* FUN_10007b10 */
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
    if ((c->cf || c->zf)) goto L_00b97b30; /* jbe 0xb97b30 */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_00b97ca8; /* jb 0xb97ca8 */
L_00b97b30:;
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x3u)); /* test edi, 3 */
    if (!c->zf) goto L_00b97b4c; /* jne 0xb97b4c */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u))); /* and edx, 3 */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) goto L_00b97b6c; /* jb 0xb97b6c */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb97c58u)); switch (t_) { case 0x00b97c68u: goto L_00b97c68; case 0x00b97c70u: goto L_00b97c70; case 0x00b97c7cu: goto L_00b97c7c; case 0x00b97c90u: goto L_00b97c90; default: jump_indirect(c, t_, 0x00b97b45u); return; } } /* jmp dword ptr [edx*4 + 0x10007c58] */
L_00b97b4c:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edx = (uint32_t)((uint32_t)0x3u); /* mov edx, 3 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x4u)); /* sub ecx, 4 */
    if (c->cf) goto L_00b97b64; /* jb 0xb97b64 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x3u))); /* and eax, 3 */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->eax * 4 + 0xb97b70u)); switch (t_) {  default: jump_indirect(c, t_, 0x00b97b5du); return; } } /* jmp dword ptr [eax*4 + 0x10007b70] */
L_00b97b64:;
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0xb97c68u)); switch (t_) {  default: jump_indirect(c, t_, 0x00b97b64u); return; } } /* jmp dword ptr [ecx*4 + 0x10007c68] */
L_00b97b6c:;
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0xb97becu)); switch (t_) { case 0x00b97c0cu: goto L_00b97c0c; case 0x00b97c14u: goto L_00b97c14; case 0x00b97c1cu: goto L_00b97c1c; case 0x00b97c24u: goto L_00b97c24; case 0x00b97c2cu: goto L_00b97c2c; case 0x00b97c34u: goto L_00b97c34; case 0x00b97c3cu: goto L_00b97c3c; case 0x00b97c4fu: goto L_00b97c4f; default: jump_indirect(c, t_, 0x00b97b6cu); return; } } /* jmp dword ptr [ecx*4 + 0x10007bec] */
L_00b97c0c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe4u))); /* mov eax, dword ptr [esi + ecx*4 - 0x1c] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x1c], eax */
L_00b97c14:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe8u))); /* mov eax, dword ptr [esi + ecx*4 - 0x18] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x18], eax */
L_00b97c1c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffecu))); /* mov eax, dword ptr [esi + ecx*4 - 0x14] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffecu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x14], eax */
L_00b97c24:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff0u))); /* mov eax, dword ptr [esi + ecx*4 - 0x10] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x10], eax */
L_00b97c2c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff4u))); /* mov eax, dword ptr [esi + ecx*4 - 0xc] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0xc], eax */
L_00b97c34:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff8u))); /* mov eax, dword ptr [esi + ecx*4 - 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 8], eax */
L_00b97c3c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
L_00b97c4f:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb97c58u)); switch (t_) { case 0x00b97c68u: goto L_00b97c68; case 0x00b97c70u: goto L_00b97c70; case 0x00b97c7cu: goto L_00b97c7c; case 0x00b97c90u: goto L_00b97c90; default: jump_indirect(c, t_, 0x00b97c4fu); return; } } /* jmp dword ptr [edx*4 + 0x10007c58] */
L_00b97c68:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b97c70:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b97c7c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b97c90:;
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
L_00b97ca8:;
    c->esi = (uint32_t)((uint32_t)(c->ecx + c->esi + 0xfffffffcu)); /* lea esi, [ecx + esi - 4] */
    c->edi = (uint32_t)((uint32_t)(c->ecx + c->edi + 0xfffffffcu)); /* lea edi, [ecx + edi - 4] */
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x3u)); /* test edi, 3 */
    if (!c->zf) goto L_00b97cdc; /* jne 0xb97cdc */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u))); /* and edx, 3 */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) goto L_00b97cd0; /* jb 0xb97cd0 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb97df0u)); switch (t_) { case 0x00b97e00u: goto L_00b97e00; case 0x00b97e08u: goto L_00b97e08; case 0x00b97e18u: goto L_00b97e18; case 0x00b97e2cu: goto L_00b97e2c; default: jump_indirect(c, t_, 0x00b97cc7u); return; } } /* jmp dword ptr [edx*4 + 0x10007df0] */
L_00b97cd0:;
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0xb97da0u)); switch (t_) { case 0x00b97de7u: goto L_00b97de7; default: jump_indirect(c, t_, 0x00b97cd2u); return; } } /* jmp dword ptr [ecx*4 + 0x10007da0] */
L_00b97cdc:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edx = (uint32_t)((uint32_t)0x3u); /* mov edx, 3 */
    (void)sub32(c, c->ecx, (uint32_t)0x4u); /* cmp ecx, 4 */
    if (c->cf) goto L_00b97cf4; /* jb 0xb97cf4 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x3u))); /* and eax, 3 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->eax * 4 + 0xb97cf8u)); switch (t_) {  default: jump_indirect(c, t_, 0x00b97cedu); return; } } /* jmp dword ptr [eax*4 + 0x10007cf8] */
L_00b97cf4:;
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0xb97df0u)); switch (t_) { case 0x00b97e00u: goto L_00b97e00; case 0x00b97e08u: goto L_00b97e08; case 0x00b97e18u: goto L_00b97e18; case 0x00b97e2cu: goto L_00b97e2c; default: jump_indirect(c, t_, 0x00b97cf4u); return; } } /* jmp dword ptr [ecx*4 + 0x10007df0] */
L_00b97de7:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb97df0u)); switch (t_) { case 0x00b97e00u: goto L_00b97e00; case 0x00b97e08u: goto L_00b97e08; case 0x00b97e18u: goto L_00b97e18; case 0x00b97e2cu: goto L_00b97e2c; default: jump_indirect(c, t_, 0x00b97de7u); return; } } /* jmp dword ptr [edx*4 + 0x10007df0] */
L_00b97e00:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b97e08:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b97e18:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b97e2c:;
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

void f_00b97b6c(CPU *c) { /* PTR_00b97b6c */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0xb97becu)); switch (t_) { case 0x00b97c0cu: goto L_00b97c0c; case 0x00b97c14u: goto L_00b97c14; case 0x00b97c1cu: goto L_00b97c1c; case 0x00b97c24u: goto L_00b97c24; case 0x00b97c2cu: goto L_00b97c2c; case 0x00b97c34u: goto L_00b97c34; case 0x00b97c3cu: goto L_00b97c3c; case 0x00b97c4fu: goto L_00b97c4f; default: jump_indirect(c, t_, 0x00b97b6cu); return; } } /* jmp dword ptr [ecx*4 + 0x10007bec] */
L_00b97c0c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe4u))); /* mov eax, dword ptr [esi + ecx*4 - 0x1c] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x1c], eax */
L_00b97c14:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe8u))); /* mov eax, dword ptr [esi + ecx*4 - 0x18] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x18], eax */
L_00b97c1c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffecu))); /* mov eax, dword ptr [esi + ecx*4 - 0x14] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffecu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x14], eax */
L_00b97c24:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff0u))); /* mov eax, dword ptr [esi + ecx*4 - 0x10] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x10], eax */
L_00b97c2c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff4u))); /* mov eax, dword ptr [esi + ecx*4 - 0xc] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0xc], eax */
L_00b97c34:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff8u))); /* mov eax, dword ptr [esi + ecx*4 - 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 8], eax */
L_00b97c3c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
L_00b97c4f:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb97c58u)); switch (t_) { case 0x00b97c68u: goto L_00b97c68; case 0x00b97c70u: goto L_00b97c70; case 0x00b97c7cu: goto L_00b97c7c; case 0x00b97c90u: goto L_00b97c90; default: jump_indirect(c, t_, 0x00b97c4fu); return; } } /* jmp dword ptr [edx*4 + 0x10007c58] */
L_00b97c68:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b97c70:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b97c7c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b97c90:;
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

void f_00b97b80(CPU *c) { /* PTR_00b97b80 */
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
    if (c->cf) { f_00b97b6c(c); return; } /* jb 0xb97b6c */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb97c58u)); switch (t_) { case 0x00b97c68u: goto L_00b97c68; case 0x00b97c70u: goto L_00b97c70; case 0x00b97c7cu: goto L_00b97c7c; case 0x00b97c90u: goto L_00b97c90; default: jump_indirect(c, t_, 0x00b97ba2u); return; } } /* jmp dword ptr [edx*4 + 0x10007c58] */
L_00b97c68:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b97c70:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b97c7c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b97c90:;
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

void f_00b97ba0(CPU *c) { /* PTR_00b97ba0 */
    PREEMPT_POLL(c);
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb97c58u)); switch (t_) { case 0x00b97c68u: goto L_00b97c68; case 0x00b97c70u: goto L_00b97c70; case 0x00b97c7cu: goto L_00b97c7c; case 0x00b97c90u: goto L_00b97c90; default: jump_indirect(c, t_, 0x00b97ba2u); return; } } /* jmp dword ptr [edx*4 + 0x10007c58] */
L_00b97c68:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b97c70:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b97c7c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b97c90:;
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

void f_00b97bac(CPU *c) { /* PTR_00b97bac */
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
    if (c->cf) { f_00b97b6c(c); return; } /* jb 0xb97b6c */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb97c58u)); switch (t_) { case 0x00b97c68u: goto L_00b97c68; case 0x00b97c70u: goto L_00b97c70; case 0x00b97c7cu: goto L_00b97c7c; case 0x00b97c90u: goto L_00b97c90; default: jump_indirect(c, t_, 0x00b97bc8u); return; } } /* jmp dword ptr [edx*4 + 0x10007c58] */
L_00b97c68:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b97c70:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b97c7c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b97c90:;
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

void f_00b97bd0(CPU *c) { /* PTR_00b97bd0 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & c->ecx))); /* and edx, ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) { f_00b97b6c(c); return; } /* jb 0xb97b6c */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb97c58u)); switch (t_) { case 0x00b97c68u: goto L_00b97c68; case 0x00b97c70u: goto L_00b97c70; case 0x00b97c7cu: goto L_00b97c7c; case 0x00b97c90u: goto L_00b97c90; default: jump_indirect(c, t_, 0x00b97be2u); return; } } /* jmp dword ptr [edx*4 + 0x10007c58] */
L_00b97c68:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b97c70:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b97c7c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b97c90:;
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

void f_00b97c0c(CPU *c) { /* PTR_00b97c0c */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb97c58u)); switch (t_) { case 0x00b97c68u: goto L_00b97c68; case 0x00b97c70u: goto L_00b97c70; case 0x00b97c7cu: goto L_00b97c7c; case 0x00b97c90u: goto L_00b97c90; default: jump_indirect(c, t_, 0x00b97c4fu); return; } } /* jmp dword ptr [edx*4 + 0x10007c58] */
L_00b97c68:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b97c70:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b97c7c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b97c90:;
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

void f_00b97c14(CPU *c) { /* PTR_00b97c14 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb97c58u)); switch (t_) { case 0x00b97c68u: goto L_00b97c68; case 0x00b97c70u: goto L_00b97c70; case 0x00b97c7cu: goto L_00b97c7c; case 0x00b97c90u: goto L_00b97c90; default: jump_indirect(c, t_, 0x00b97c4fu); return; } } /* jmp dword ptr [edx*4 + 0x10007c58] */
L_00b97c68:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b97c70:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b97c7c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b97c90:;
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

void f_00b97c1c(CPU *c) { /* PTR_00b97c1c */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb97c58u)); switch (t_) { case 0x00b97c68u: goto L_00b97c68; case 0x00b97c70u: goto L_00b97c70; case 0x00b97c7cu: goto L_00b97c7c; case 0x00b97c90u: goto L_00b97c90; default: jump_indirect(c, t_, 0x00b97c4fu); return; } } /* jmp dword ptr [edx*4 + 0x10007c58] */
L_00b97c68:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b97c70:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b97c7c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b97c90:;
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

void f_00b97c24(CPU *c) { /* PTR_00b97c24 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb97c58u)); switch (t_) { case 0x00b97c68u: goto L_00b97c68; case 0x00b97c70u: goto L_00b97c70; case 0x00b97c7cu: goto L_00b97c7c; case 0x00b97c90u: goto L_00b97c90; default: jump_indirect(c, t_, 0x00b97c4fu); return; } } /* jmp dword ptr [edx*4 + 0x10007c58] */
L_00b97c68:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b97c70:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b97c7c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b97c90:;
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

void f_00b97c2c(CPU *c) { /* PTR_00b97c2c */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb97c58u)); switch (t_) { case 0x00b97c68u: goto L_00b97c68; case 0x00b97c70u: goto L_00b97c70; case 0x00b97c7cu: goto L_00b97c7c; case 0x00b97c90u: goto L_00b97c90; default: jump_indirect(c, t_, 0x00b97c4fu); return; } } /* jmp dword ptr [edx*4 + 0x10007c58] */
L_00b97c68:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b97c70:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b97c7c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b97c90:;
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
