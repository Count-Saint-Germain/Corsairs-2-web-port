#include "recomp.h"

void f_00581000(CPU *c) { /* DMAInterface */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    W32((uint32_t)(0x591308u), (uint32_t)(c->eax)); /* mov dword ptr [0x10011308], eax */
    W32((uint32_t)(0x591284u), (uint32_t)(c->eax)); /* mov dword ptr [0x10011284], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov eax, dword ptr [eax + 4] */
    W32((uint32_t)(0x591280u), (uint32_t)(c->ecx)); /* mov dword ptr [0x10011280], ecx */
    W32((uint32_t)(0x5912f4u), (uint32_t)(c->eax)); /* mov dword ptr [0x100112f4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(0x6217a8u))); /* mov eax, dword ptr [0x100a17a8] */
    c->esp += 4; return; /* ret  */
}

void f_00581030(CPU *c) { /* FUN_10001030 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x591308u))); /* mov ecx, dword ptr [0x10011308] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4u)); PUSH32(c, 0x0058104au); call_indirect(c, t_); } /* call dword ptr [eax + 4] */
    c->esp += 4; return; /* ret  */
}

void f_00581050(CPU *c) { /* FUN_10001050 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(0x591308u))); /* mov ecx, dword ptr [0x10011308] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x00581060u); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
    c->esp += 4; return; /* ret  */
}

void f_00581070(CPU *c) { /* FUN_10001070 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x591308u))); /* mov ecx, dword ptr [0x10011308] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0xcu)); PUSH32(c, 0x0058108fu); call_indirect(c, t_); } /* call dword ptr [eax + 0xc] */
    c->esp += 4; return; /* ret  */
}

void f_00581090(CPU *c) { /* PTR_00581090 */
    PREEMPT_POLL(c);
    PUSH32(c, 0x00581095u); f_005810a0(c); /* call 0x5810a0 */
    { f_00581180(c); return; } /* jmp 0x581180 */
}

void f_005810a0(CPU *c) { /* FUN_100010a0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x6217a8u; PUSH32(c, v_); } /* push 0x100a17a8 */
    c->ecx = (uint32_t)((uint32_t)0x591794u); /* mov ecx, 0x10011794 */
    PUSH32(c, 0x005810afu); f_005810b0(c); /* call 0x5810b0 */
    c->esp += 4; return; /* ret  */
}

void f_005810b0(CPU *c) { /* FUN_100010b0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0xc], ecx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x58d0f8u)); /* mov dword ptr [eax], 0x1000d0f8 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 4], edx */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    c->esp += 8; return; /* ret 4 */
}

void f_005810d0(CPU *c) { /* PTR_005810d0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x58e050u); /* mov eax, 0x1000e050 */
    c->esp += 4; return; /* ret  */
}

void f_005810e0(CPU *c) { /* FUN_100010e0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x58cb94u; PUSH32(c, v_); } /* push 0x1000cb94 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov eax, dword ptr [ecx + 0xc] */
    { uint32_t v_ = 0x11u; PUSH32(c, v_); } /* push 0x11 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t v_ = 0x58e058u; PUSH32(c, v_); } /* push 0x1000e058 */
    { uint32_t v_ = 0x9284cu; PUSH32(c, v_); } /* push 0x9284c */
    W32((uint32_t)(c->ecx + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 0xc], eax */
    PUSH32(c, 0x0058110eu); f_00581030(c); /* call 0x581030 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->esp), (uint32_t)(c->eax)); /* mov dword ptr [esp], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0xc], 0 */
    if (c->zf) goto L_00581137; /* je 0x581137 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    PUSH32(c, 0x00581128u); f_005811e0(c); /* call 0x5811e0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
L_00581137:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_00581150(CPU *c) { /* FUN_10001150 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00581158u); f_00581170(c); /* call 0x581170 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00581168; /* je 0x581168 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00581165u); f_00581050(c); /* call 0x581050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00581168:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00581170(CPU *c) { /* FUN_10001170 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx), (uint32_t)((uint32_t)0x58d118u)); /* mov dword ptr [ecx], 0x1000d118 */
    c->esp += 4; return; /* ret  */
}

void f_00581180(CPU *c) { /* FUN_10001180 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x581190u; PUSH32(c, v_); } /* push 0x10001190 */
    PUSH32(c, 0x0058118au); f_00584a94(c); /* call 0x584a94 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00581190(CPU *c) { /* PTR_00581190 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)0x591794u); /* mov ecx, 0x10011794 */
    { f_00581170(c); return; } /* jmp 0x581170 */
}

void f_005811a0(CPU *c) { /* PTR_005811a0 */
    PREEMPT_POLL(c);
    goto L_005811b0; /* jmp 0x5811b0 */
L_005811b0:;
    c->esp += 4; return; /* ret  */
}

void f_005811c0(CPU *c) { /* PTR_005811c0 */
    PREEMPT_POLL(c);
    goto L_005811d0; /* jmp 0x5811d0 */
L_005811d0:;
    c->esp += 4; return; /* ret  */
}

void f_005811e0(CPU *c) { /* FUN_100011e0 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->ecx); /* mov ebp, ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0x4u)); /* lea edi, [ebp + 4] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 4], eax */
    W32((uint32_t)(c->edi + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [edi + 8], ebx */
    W32((uint32_t)(c->edi + 0xcu), (uint32_t)(c->ebx)); /* mov dword ptr [edi + 0xc], ebx */
    W32((uint32_t)(c->edi + 0x10u), (uint32_t)(c->ebx)); /* mov dword ptr [edi + 0x10], ebx */
    W32((uint32_t)(c->edi + 0x14u), (uint32_t)(c->ebx)); /* mov dword ptr [edi + 0x14], ebx */
    W32((uint32_t)(c->ebp), (uint32_t)((uint32_t)0x58d15cu)); /* mov dword ptr [ebp], 0x1000d15c */
    W32((uint32_t)(c->ebp + 0x1cu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 0x1c], ebx */
    c->ecx = (uint32_t)(R32((uint32_t)(0x591280u))); /* mov ecx, dword ptr [0x10011280] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x00581219u); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x591280u))); /* mov ecx, dword ptr [0x10011280] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x10u)); /* lea edx, [esp + 0x10] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x10u)); PUSH32(c, 0x00581229u); call_indirect(c, t_); } /* call dword ptr [eax + 0x10] */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edx, dword ptr [ebp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x591280u))); /* mov ecx, dword ptr [0x10011280] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov edx, dword ptr [ebp + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4u)); PUSH32(c, 0x00581245u); call_indirect(c, t_); } /* call dword ptr [eax + 4] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x24u)); /* lea eax, [ebp + 0x24] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    W32((uint32_t)(c->edx), (uint32_t)(c->ecx)); /* mov dword ptr [edx], ecx */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [edx + 4], ecx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 8], ebx */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0xc], ebx */
    W32((uint32_t)(c->eax + 0x10u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x10], ebx */
    W32((uint32_t)(c->eax + 0x14u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x14], ebx */
    W32((uint32_t)(c->ebp), (uint32_t)((uint32_t)0x58d138u)); /* mov dword ptr [ebp], 0x1000d138 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x44u)); /* lea eax, [ebp + 0x44] */
    c->ecx = (uint32_t)((uint32_t)0x100u); /* mov ecx, 0x100 */
L_0058126c:;
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [eax], bl */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x28u)); /* add eax, 0x28 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (!c->zf) goto L_0058126c; /* jne 0x58126c */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    W32((uint32_t)(c->ebp + 0x20u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 0x20], ebx */
    W32((uint32_t)(c->ebp + 0x3cu), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [ebp + 0x3c], 0xffffffff */
    W32((uint32_t)(c->ebp + 0x92844u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 0x92844], ebx */
    W32((uint32_t)(c->ebp + 0x40u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 0x40], ebx */
    W32((uint32_t)(c->ebp + 0x92848u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 0x92848], ebx */
    c->eax = (uint32_t)(c->ebp); /* mov eax, ebp */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    c->esp += 4; return; /* ret  */
}

void f_005812a0(CPU *c) { /* FUN_100012a0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x005812a8u); f_005812c0(c); /* call 0x5812c0 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_005812b8; /* je 0x5812b8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x005812b5u); f_00581050(c); /* call 0x581050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_005812b8:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_005812c0(CPU *c) { /* FUN_100012c0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x58cba8u; PUSH32(c, v_); } /* push 0x1000cba8 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 4], esi */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x58d138u)); /* mov dword ptr [esi], 0x1000d138 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov ecx, dword ptr [esi + 0x20] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x10], 0 */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00581302; /* je 0x581302 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x3cu))); /* mov eax, dword ptr [esi + 0x3c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf != c->of)) goto L_00581302; /* jl 0x581302 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x80u)); PUSH32(c, 0x00581302u); call_indirect(c, t_); } /* call dword ptr [edx + 0x80] */
L_00581302:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x14u))); /* mov edx, dword ptr [esi + 0x14] */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x58d15cu)); /* mov dword ptr [esi], 0x1000d15c */
    c->ecx = (uint32_t)(R32((uint32_t)(0x591280u))); /* mov ecx, dword ptr [0x10011280] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [esp + 0x14], 0xffffffff */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x0058131fu); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_00581330(CPU *c) { /* PTR_00581330 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x58cbcbu; PUSH32(c, v_); } /* push 0x1000cbcb */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x250u)); /* sub esp, 0x250 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(0x591308u))); /* mov ecx, dword ptr [0x10011308] */
    { uint32_t v_ = 0x58e0d8u; PUSH32(c, v_); } /* push 0x1000e0d8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4cu)); PUSH32(c, 0x0058135eu); call_indirect(c, t_); } /* call dword ptr [eax + 0x4c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esi + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x20], eax */
    if (!c->zf) goto L_005813fb; /* jne 0x5813fb */
    c->ecx = (uint32_t)(R32((uint32_t)(0x591280u))); /* mov ecx, dword ptr [0x10011280] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x18u)); PUSH32(c, 0x00581374u); call_indirect(c, t_); } /* call dword ptr [edx + 0x18] */
    c->eax = (uint32_t)(R32((uint32_t)(0x591280u))); /* mov eax, dword ptr [0x10011280] */
    { uint32_t v_ = 0x58e0c0u; PUSH32(c, v_); } /* push 0x1000e0c0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00581384u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(0x591280u))); /* mov eax, dword ptr [0x10011280] */
    { uint32_t v_ = 0x36u; PUSH32(c, v_); } /* push 0x36 */
    { uint32_t v_ = 0x58e058u; PUSH32(c, v_); } /* push 0x1000e058 */
    { uint32_t v_ = 0x58e0b4u; PUSH32(c, v_); } /* push 0x1000e0b4 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x0058139bu); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(0x591280u))); /* mov eax, dword ptr [0x10011280] */
    { uint32_t v_ = 0x58e09cu; PUSH32(c, v_); } /* push 0x1000e09c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x005813abu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    W32((uint32_t)(c->esp + 0x128u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x128], 0 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_005813bb:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x58e09cu))); /* mov cl, byte ptr [eax + 0x1000e09c] */
    W8((uint32_t)(c->esp + c->eax + 0x4u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esp + eax + 4], cl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_005813bb; /* jne 0x5813bb */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)((uint32_t)0x4au); /* mov ecx, 0x4a */
    c->esi = (uint32_t)((uint32_t)(c->esp + 0x8u)); /* lea esi, [esp + 8] */
    c->edi = (uint32_t)((uint32_t)(c->esp + 0x130u)); /* lea edi, [esp + 0x130] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x130u)); /* lea edx, [esp + 0x130] */
    { uint32_t v_ = 0x58d958u; PUSH32(c, v_); } /* push 0x1000d958 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    W32((uint32_t)(c->esp + 0x268u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x268], 0 */
    PUSH32(c, 0x005813fau); f_00584b1a(c); /* call 0x584b1a */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_005813fb:;
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0x58e090u; PUSH32(c, v_); } /* push 0x1000e090 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x78u)); PUSH32(c, 0x00581407u); call_indirect(c, t_); } /* call dword ptr [edx + 0x78] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x254u))); /* mov ecx, dword ptr [esp + 0x254] */
    W32((uint32_t)(c->esi + 0x3cu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x3c], eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x25cu)); /* add esp, 0x25c */
    c->esp += 4; return; /* ret  */
}

void f_00581430(CPU *c) { /* PTR_00581430 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x13cu)); /* sub esp, 0x13c */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x148u))); /* mov ebx, dword ptr [esp + 0x148] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0xcu)); PUSH32(c, 0x00581448u); call_indirect(c, t_); } /* call dword ptr [eax + 0xc] */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x7788u)); /* sub eax, 0x7788 */
    if (c->zf) goto L_00581470; /* je 0x581470 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (!c->zf) goto L_005816a3; /* jne 0x5816a3 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x150u))); /* mov ecx, dword ptr [esp + 0x150] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00581463u); f_005816b0(c); /* call 0x5816b0 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x13cu)); /* add esp, 0x13c */
    c->esp += 4; return; /* ret  */
L_00581470:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov edx, dword ptr [ebx] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x30u)); /* lea eax, [esp + 0x30] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x24u)); PUSH32(c, 0x0058147cu); call_indirect(c, t_); } /* call dword ptr [edx + 0x24] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x150u))); /* mov ebp, dword ptr [esp + 0x150] */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0x24u)); /* lea edi, [ebp + 0x24] */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov edx, dword ptr [ebx] */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x20u)); PUSH32(c, 0x00581496u); call_indirect(c, t_); } /* call dword ptr [edx + 0x20] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    W32((uint32_t)(c->ebp + 0x40u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0x40], esi */
    if (c->zf) goto L_005816a3; /* je 0x5816a3 */
    c->ebp = (uint32_t)(logic32(c, 0)); /* xor ebp, ebp */
L_005814a5:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0x58e11cu))); /* mov al, byte ptr [ebp + 0x1000e11c] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_0058160e; /* je 0x58160e */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x2eu); /* cmp al, 0x2e */
    if (c->zf) goto L_005814ba; /* je 0x5814ba */
    c->ebp = (uint32_t)(inc32(c, c->ebp)); /* inc ebp */
    goto L_005814a5; /* jmp 0x5814a5 */
L_005814ba:;
    (void)sub32(c, c->ebp, (uint32_t)0x104u); /* cmp ebp, 0x104 */
    if (!c->cf) goto L_0058159f; /* jae 0x58159f */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x4cu)); /* lea eax, [esp + 0x4c] */
    { uint32_t v_ = 0x58e11cu; PUSH32(c, v_); } /* push 0x1000e11c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x005814d6u); f_00584bb0(c); /* call 0x584bb0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    W8((uint32_t)(c->esp + c->ebp + 0x48u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esp + ebp + 0x48], 0 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->cf || c->zf)) goto L_00581522; /* jbe 0x581522 */
L_005814e7:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + c->edi * 4))); /* mov eax, dword ptr [ecx + edi*4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x005814f8u); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x48u)); /* lea ecx, [esp + 0x48] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00581503u); f_0058c990(c); /* call 0x58c990 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00581514; /* je 0x581514 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_005814e7; /* jb 0x5814e7 */
    goto L_00581522; /* jmp 0x581522 */
L_00581514:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov edx, dword ptr [esi + 0x10] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->edx + c->edi * 4))); /* mov ebx, dword ptr [edx + edi*4] */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (!c->zf) goto L_005815fd; /* jne 0x5815fd */
L_00581522:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x48u)); /* lea edx, [esp + 0x48] */
    { uint32_t v_ = 0x6217acu; PUSH32(c, v_); } /* push 0x100a17ac */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0xcu)); PUSH32(c, 0x00581533u); call_indirect(c, t_); } /* call dword ptr [eax + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x0058153bu); f_00583b00(c); /* call 0x583b00 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->cf || c->zf)) goto L_0058156f; /* jbe 0x58156f */
L_00581544:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->edi * 4))); /* mov eax, dword ptr [eax + edi*4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x00581555u); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x48u)); /* lea ecx, [esp + 0x48] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00581560u); f_0058c990(c); /* call 0x58c990 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00581585; /* je 0x581585 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_00581544; /* jb 0x581544 */
L_0058156f:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x58e11du)); /* lea eax, [ebp + 0x1000e11d] */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00581580u); f_005830a0(c); /* call 0x5830a0 */
    goto L_0058163b; /* jmp 0x58163b */
L_00581585:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov edx, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x58e11du)); /* lea eax, [ebp + 0x1000e11d] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->ebx = (uint32_t)(R32((uint32_t)(c->edx + c->edi * 4))); /* mov ebx, dword ptr [edx + edi*4] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x0058159au); f_005830a0(c); /* call 0x5830a0 */
    goto L_0058163b; /* jmp 0x58163b */
L_0058159f:;
    { uint32_t v_ = 0x148u; PUSH32(c, v_); } /* push 0x148 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x1u)); /* lea eax, [ebp + 1] */
    { uint32_t v_ = 0x58e0e8u; PUSH32(c, v_); } /* push 0x1000e0e8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x005815b2u); f_00581030(c); /* call 0x581030 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = 0x58e11cu; PUSH32(c, v_); } /* push 0x1000e11c */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x005815c0u); f_00584bb0(c); /* call 0x584bb0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    W8((uint32_t)(c->edi + c->ebp), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [edi + ebp], 0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x005815cfu); f_00582490(c); /* call 0x582490 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (!c->zf) goto L_005815f4; /* jne 0x5815f4 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    { uint32_t v_ = 0x6217acu; PUSH32(c, v_); } /* push 0x100a17ac */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x005815e2u); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x005815eau); f_00583b00(c); /* call 0x583b00 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x005815f2u); f_00582490(c); /* call 0x582490 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
L_005815f4:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x005815fau); f_00581050(c); /* call 0x581050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_005815fd:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x58e11du)); /* lea eax, [ebp + 0x1000e11d] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x0058160cu); f_005830a0(c); /* call 0x5830a0 */
    goto L_0058163b; /* jmp 0x58163b */
L_0058160e:;
    { uint32_t v_ = 0x58e11cu; PUSH32(c, v_); } /* push 0x1000e11c */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x0058161au); f_00582490(c); /* call 0x582490 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_0058163b; /* jne 0x58163b */
    { uint32_t v_ = 0x6217acu; PUSH32(c, v_); } /* push 0x100a17ac */
    { uint32_t v_ = 0x58e11cu; PUSH32(c, v_); } /* push 0x1000e11c */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x0058162fu); f_00582980(c); /* call 0x582980 */
    { uint32_t v_ = 0x58e11cu; PUSH32(c, v_); } /* push 0x1000e11c */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x0058163bu); f_00582490(c); /* call 0x582490 */
L_0058163b:;
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x150u))); /* mov ebp, dword ptr [esp + 0x150] */
    { uint32_t v_ = 0x100u; PUSH32(c, v_); } /* push 0x100 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea ecx, [esp + 0x14] */
    { uint32_t v_ = 0x58e0e4u; PUSH32(c, v_); } /* push 0x1000e0e4 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    W32((uint32_t)(c->ebp + 0x40u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x40], eax */
    PUSH32(c, 0x00581659u); f_00584b54(c); /* call 0x584b54 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x40u))); /* mov esi, dword ptr [ebp + 0x40] */
    c->edi = (uint32_t)((uint32_t)(c->esp + 0x1cu)); /* lea edi, [esp + 0x1c] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0xffffffffu))); /* or ecx, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    while (c->ecx) { (void)sub8(c, ((uint8_t)c->eax), R8(c->edi)); c->edi += (c->df ? -1 : 1); c->ecx--; if (c->zf) break; } /* repne scasb al, byte ptr es:[edi] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov edx, dword ptr [esi + 0xc] */
    { uint32_t v_ = 0x4eu; PUSH32(c, v_); } /* push 0x4e */
    c->ecx = (uint32_t)((uint32_t)~c->ecx); /* not ecx */
    { uint32_t v_ = 0x58e0e8u; PUSH32(c, v_); } /* push 0x1000e0e8 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x0058167au); f_00581070(c); /* call 0x581070 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xc], eax */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x10u)); /* lea ecx, [esp + 0x10] */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
L_00581686:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov al, byte ptr [ecx] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    W8((uint32_t)(c->edx), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edx], al */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00581686; /* jne 0x581686 */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_00581692:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    PUSH32(c, 0x0058169au); f_00582b30(c); /* call 0x582b30 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub32(c, c->esi, (uint32_t)0x100u); /* cmp esi, 0x100 */
    if ((c->sf != c->of)) goto L_00581692; /* jl 0x581692 */
L_005816a3:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x13cu)); /* add esp, 0x13c */
    c->esp += 4; return; /* ret  */
}

void f_005816b0(CPU *c) { /* FUN_100016b0 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x24u)); /* sub esp, 0x24 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->ecx); /* mov ebp, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(0x591308u))); /* mov ecx, dword ptr [0x10011308] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)((uint32_t)(c->ebp + 0x24u)); /* lea edx, [ebp + 0x24] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x64u)); PUSH32(c, 0x005816c8u); call_indirect(c, t_); } /* call dword ptr [eax + 0x64] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00581867; /* je 0x581867 */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x38u))); /* mov edi, dword ptr [esp + 0x38] */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x005816ddu); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi))); /* mov edx, dword ptr [edi] */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x005816e8u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x005816f3u); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esi + 0x58u))); /* fsub dword ptr [esi + 0x58] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | (uint32_t)0xffffffffu))); /* or ebx, 0xffffffff */
    c->edx = (uint32_t)((uint32_t)(c->ebp + 0x5cu)); /* lea edx, [ebp + 0x5c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x28u))); /* fmul dword ptr [esi + 0x28] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esi + 0x54u))); /* fsub dword ptr [esi + 0x54] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x24u))); /* fmul dword ptr [esi + 0x24] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esi + 0x50u))); /* fsub dword ptr [esi + 0x50] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x20u))); /* fmul dword ptr [esi + 0x20] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->esp + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1c] */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esi + 0x58u))); /* fsub dword ptr [esi + 0x58] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x38u))); /* fmul dword ptr [esi + 0x38] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esi + 0x54u))); /* fsub dword ptr [esi + 0x54] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x34u))); /* fmul dword ptr [esi + 0x34] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esi + 0x50u))); /* fsub dword ptr [esi + 0x50] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x30u))); /* fmul dword ptr [esi + 0x30] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->esp + 0x20u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x20] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esi + 0x58u))); /* fsub dword ptr [esi + 0x58] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x48u))); /* fmul dword ptr [esi + 0x48] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esi + 0x54u))); /* fsub dword ptr [esi + 0x54] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x44u))); /* fmul dword ptr [esi + 0x44] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esi + 0x50u))); /* fsub dword ptr [esi + 0x50] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x40u))); /* fmul dword ptr [esi + 0x40] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->esp + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x24] */
L_00581765:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx + 0xffffffe8u))); /* mov al, byte ptr [edx - 0x18] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_005817a9; /* je 0x5817a9 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fld dword ptr [esp + 0x1c] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->edx + 0xfffffff8u))); /* fsub dword ptr [edx - 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x20u))); /* fld dword ptr [esp + 0x20] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->edx + 0xfffffffcu))); /* fsub dword ptr [edx - 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x24u))); /* fld dword ptr [esp + 0x24] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->edx))); /* fsub dword ptr [edx] */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    { double v_ = ST(2); FPUSH(c, v_); } /* fld st(2) */
    ST(0) = FPRES(c, ST(0) * ST(3)); /* fmul st(3) */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    { double v_ = ST(3); FPUSH(c, v_); } /* fld st(3) */
    ST(0) = FPRES(c, ST(0) * ST(4)); /* fmul st(4) */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x58d180u))); FPOP(c); /* fcomp dword ptr [0x1000d180] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    if (!PF(c)) goto L_00581867; /* jnp 0x581867 */
    goto L_005817af; /* jmp 0x5817af */
L_005817a9:;
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if ((c->sf == c->of)) goto L_005817af; /* jge 0x5817af */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
L_005817af:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x28u)); /* add edx, 0x28 */
    (void)sub32(c, c->ecx, (uint32_t)0x100u); /* cmp ecx, 0x100 */
    if ((c->sf != c->of)) goto L_00581765; /* jl 0x581765 */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if ((c->sf != c->of)) goto L_00581867; /* jl 0x581867 */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi))); /* mov edx, dword ptr [edi] */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x005817cau); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    WF32((uint32_t)(0x5912f8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [0x100112f8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x005817d7u); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    WF32((uint32_t)(0x5912fcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [0x100112fc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi))); /* mov edx, dword ptr [edi] */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x005817e4u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    WF32((uint32_t)(0x591300u), (float)ST(0)); /* fst dword ptr [0x10011300] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x28u))); /* fmul dword ptr [esi + 0x28] */
    FPUSH(c, (double)RF32((uint32_t)(0x5912fcu))); /* fld dword ptr [0x100112fc] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x24u))); /* fmul dword ptr [esi + 0x24] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x28u)); /* lea eax, [esp + 0x28] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x20u)); /* lea ecx, [esp + 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(0x5912f8u))); /* fld dword ptr [0x100112f8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x20u))); /* fmul dword ptr [esi + 0x20] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->esp + 0x34u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x34] */
    FPUSH(c, (double)RF32((uint32_t)(0x591300u))); /* fld dword ptr [0x10011300] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x38u))); /* fmul dword ptr [esi + 0x38] */
    FPUSH(c, (double)RF32((uint32_t)(0x5912fcu))); /* fld dword ptr [0x100112fc] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x34u))); /* fmul dword ptr [esi + 0x34] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(0x5912f8u))); /* fld dword ptr [0x100112f8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x30u))); /* fmul dword ptr [esi + 0x30] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->esp + 0x38u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x38] */
    FPUSH(c, (double)RF32((uint32_t)(0x591300u))); /* fld dword ptr [0x10011300] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x48u))); /* fmul dword ptr [esi + 0x48] */
    FPUSH(c, (double)RF32((uint32_t)(0x5912fcu))); /* fld dword ptr [0x100112fc] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x44u))); /* fmul dword ptr [esi + 0x44] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(0x5912f8u))); /* fld dword ptr [0x100112f8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x40u))); /* fmul dword ptr [esi + 0x40] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->esp + 0x3cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x3c] */
    PUSH32(c, 0x0058185eu); f_00584cae(c); /* call 0x584cae */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    PUSH32(c, 0x00581867u); f_00581880(c); /* call 0x581880 */
L_00581867:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x24u)); /* add esp, 0x24 */
    c->esp += 8; return; /* ret 4 */
}

void f_00581880(CPU *c) { /* FUN_10001880 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x108u)); /* sub esp, 0x108 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(0x591308u))); /* mov ecx, dword ptr [0x10011308] */
    W32((uint32_t)(c->esp + 0x94u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x94], edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)((uint32_t)(c->edi + 0x24u)); /* lea edx, [edi + 0x24] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x64u)); PUSH32(c, 0x005818a2u); call_indirect(c, t_); } /* call dword ptr [eax + 0x64] */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (c->zf) goto L_0058247f; /* je 0x58247f */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x11cu))); /* mov eax, dword ptr [esp + 0x11c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x124u))); /* mov ecx, dword ptr [esp + 0x124] */
    c->esi = (uint32_t)((uint32_t)(c->ebx + 0x20u)); /* lea esi, [ebx + 0x20] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea eax, [eax + eax*4] */
    c->ebp = (uint32_t)((uint32_t)(c->edi + c->eax * 8)); /* lea ebp, [edi + eax*8] */
    W8((uint32_t)(c->ebp + 0x44u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [ebp + 0x44], 0 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x1c], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov eax, dword ptr [ecx + 4] */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x20], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov ecx, dword ptr [ecx + 8] */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x24], ecx */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x24u))); /* fld dword ptr [esp + 0x24] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x20u))); /* fmul dword ptr [esi + 0x20] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x20u))); /* fld dword ptr [esp + 0x20] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x10u))); /* fmul dword ptr [esi + 0x10] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fld dword ptr [esp + 0x1c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi))); /* fmul dword ptr [esi] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x30u))); /* fadd dword ptr [esi + 0x30] */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x24u))); /* fld dword ptr [esp + 0x24] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x24u))); /* fmul dword ptr [esi + 0x24] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x20u))); /* fld dword ptr [esp + 0x20] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x14u))); /* fmul dword ptr [esi + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fld dword ptr [esp + 0x1c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x4u))); /* fmul dword ptr [esi + 4] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x34u))); /* fadd dword ptr [esi + 0x34] */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x24u))); /* fld dword ptr [esp + 0x24] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x28u))); /* fmul dword ptr [esi + 0x28] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x20u))); /* fld dword ptr [esp + 0x20] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x18u))); /* fmul dword ptr [esi + 0x18] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fld dword ptr [esp + 0x1c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x8u))); /* fmul dword ptr [esi + 8] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x38u))); /* fadd dword ptr [esi + 0x38] */
    W32((uint32_t)(c->esp + 0x48u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x48], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x128u))); /* mov eax, dword ptr [esp + 0x128] */
    W32((uint32_t)(c->esp + 0x44u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x44], edx */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov ecx, dword ptr [esp + 0x18] */
    W32((uint32_t)(c->esp + 0x4cu), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x4c], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx))); /* mov ecx, dword ptr [edx] */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x1c], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov ecx, dword ptr [edx + 4] */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x20], ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov edx, dword ptr [edx + 8] */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x24], edx */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x24u))); /* fld dword ptr [esp + 0x24] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x20u))); /* fmul dword ptr [esi + 0x20] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x20u))); /* fld dword ptr [esp + 0x20] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x10u))); /* fmul dword ptr [esi + 0x10] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fld dword ptr [esp + 0x1c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi))); /* fmul dword ptr [esi] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x30u))); /* fadd dword ptr [esi + 0x30] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x24u))); /* fld dword ptr [esp + 0x24] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x24u))); /* fmul dword ptr [esi + 0x24] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x20u))); /* fld dword ptr [esp + 0x20] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x14u))); /* fmul dword ptr [esi + 0x14] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fld dword ptr [esp + 0x1c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x4u))); /* fmul dword ptr [esi + 4] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x34u))); /* fadd dword ptr [esi + 0x34] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x24u))); /* fld dword ptr [esp + 0x24] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x28u))); /* fmul dword ptr [esi + 0x28] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x20u))); /* fld dword ptr [esp + 0x20] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x18u))); /* fmul dword ptr [esi + 0x18] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fld dword ptr [esp + 0x1c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x8u))); /* fmul dword ptr [esi + 8] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x38u))); /* fadd dword ptr [esi + 0x38] */
    WF32((uint32_t)(c->esp + 0x3cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x3c] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->ebx + 0x50u))); /* fsub dword ptr [ebx + 0x50] */
    WF32((uint32_t)(c->esp + 0x28u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x28] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov ecx, dword ptr [esp + 0x28] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->ebx + 0x54u))); /* fsub dword ptr [ebx + 0x54] */
    WF32((uint32_t)(c->esp + 0x2cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x2c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x3cu))); /* fld dword ptr [esp + 0x3c] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->ebx + 0x58u))); /* fsub dword ptr [ebx + 0x58] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov edx, dword ptr [esp + 0x2c] */
    W32((uint32_t)(0x5912f8u), (uint32_t)(c->ecx)); /* mov dword ptr [0x100112f8], ecx */
    W32((uint32_t)(0x5912fcu), (uint32_t)(c->edx)); /* mov dword ptr [0x100112fc], edx */
    W32((uint32_t)(0x591288u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [0x10011288], 0 */
    WF32((uint32_t)(c->esp + 0x30u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x30] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0x58d198u))); /* fadd dword ptr [0x1000d198] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov ecx, dword ptr [esp + 0x30] */
    W32((uint32_t)(0x59128cu), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [0x1001128c], 0x3f800000 */
    W32((uint32_t)(0x591300u), (uint32_t)(c->ecx)); /* mov dword ptr [0x10011300], ecx */
    W32((uint32_t)(0x591290u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [0x10011290], 0 */
    WF32((uint32_t)(0x591294u), (float)ST(0)); FPOP(c); /* fstp dword ptr [0x10011294] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0x58d198u))); /* fsub dword ptr [0x1000d198] */
    W32((uint32_t)(0x591298u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [0x10011298], 0 */
    W32((uint32_t)(0x59129cu), (uint32_t)((uint32_t)0xbf800000u)); /* mov dword ptr [0x1001129c], 0xbf800000 */
    W32((uint32_t)(0x5912a0u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [0x100112a0], 0 */
    W32((uint32_t)(0x5912a8u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [0x100112a8], 0 */
    ST(0) = -ST(0); /* fchs  */
    WF32((uint32_t)(0x5912a4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [0x100112a4] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0x58d198u))); /* fadd dword ptr [0x1000d198] */
    W32((uint32_t)(0x5912acu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [0x100112ac], 0 */
    W32((uint32_t)(0x5912b0u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [0x100112b0], 0x3f800000 */
    W32((uint32_t)(0x5912b8u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [0x100112b8], 0 */
    W32((uint32_t)(0x5912bcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [0x100112bc], 0 */
    WF32((uint32_t)(0x5912b4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [0x100112b4] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0x58d198u))); /* fsub dword ptr [0x1000d198] */
    W32((uint32_t)(0x5912c0u), (uint32_t)((uint32_t)0xbf800000u)); /* mov dword ptr [0x100112c0], 0xbf800000 */
    W32((uint32_t)(0x5912c8u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [0x100112c8], 0x3f800000 */
    W32((uint32_t)(0x5912ccu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [0x100112cc], 0 */
    W32((uint32_t)(0x5912d0u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [0x100112d0], 0 */
    ST(0) = -ST(0); /* fchs  */
    WF32((uint32_t)(0x5912c4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [0x100112c4] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0x58d198u))); /* fadd dword ptr [0x1000d198] */
    W32((uint32_t)(0x5912d8u), (uint32_t)((uint32_t)0xbf800000u)); /* mov dword ptr [0x100112d8], 0xbf800000 */
    W32((uint32_t)(0x5912dcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [0x100112dc], 0 */
    W32((uint32_t)(0x5912e0u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [0x100112e0], 0 */
    W32((uint32_t)(0x591790u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [0x10011790], 0 */
    WF32((uint32_t)(0x5912d4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [0x100112d4] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0x58d198u))); /* fsub dword ptr [0x1000d198] */
    ST(0) = -ST(0); /* fchs  */
    WF32((uint32_t)(0x5912e4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [0x100112e4] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax))); /* fld dword ptr [eax] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x58d194u))); /* fmul dword ptr [0x1000d194] */
    WF32((uint32_t)(c->esp + 0x28u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x28] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x4u))); /* fld dword ptr [eax + 4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x58d194u))); /* fmul dword ptr [0x1000d194] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov edx, dword ptr [esp + 0x28] */
    WF32((uint32_t)(c->esp + 0x2cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x2c] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x8u))); /* fld dword ptr [eax + 8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x58d194u))); /* fmul dword ptr [0x1000d194] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov eax, dword ptr [esp + 0x2c] */
    W32((uint32_t)(0x5912e8u), (uint32_t)(c->edx)); /* mov dword ptr [0x100112e8], edx */
    WF32((uint32_t)(c->esp + 0x30u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x30] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov ecx, dword ptr [esp + 0x30] */
    W32((uint32_t)(0x5912ecu), (uint32_t)(c->eax)); /* mov dword ptr [0x100112ec], eax */
    W32((uint32_t)(0x5912f0u), (uint32_t)(c->ecx)); /* mov dword ptr [0x100112f0], ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov edx, dword ptr [ebx] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x34u)); PUSH32(c, 0x00581b6fu); call_indirect(c, t_); } /* call dword ptr [edx + 0x34] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    W32((uint32_t)(c->esp + 0x48u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x48], eax */
    PUSH32(c, 0x00581b7du); f_005824e0(c); /* call 0x5824e0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    { uint32_t v_ = 0x583ce0u; PUSH32(c, v_); } /* push 0x10003ce0 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x48u)); /* lea ecx, [esp + 0x48] */
    { uint32_t v_ = 0x3f19999au; PUSH32(c, v_); } /* push 0x3f19999a */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x6u; PUSH32(c, v_); } /* push 6 */
    { uint32_t v_ = 0x591288u; PUSH32(c, v_); } /* push 0x10011288 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x28u)); PUSH32(c, 0x00581b9au); call_indirect(c, t_); } /* call dword ptr [eax + 0x28] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x40u))); /* mov edx, dword ptr [esp + 0x40] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    PUSH32(c, 0x00581ba8u); f_005824e0(c); /* call 0x5824e0 */
    c->eax = (uint32_t)(R32((uint32_t)(0x591790u))); /* mov eax, dword ptr [0x10011790] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_0058247f; /* jle 0x58247f */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x54u)); /* lea eax, [esp + 0x54] */
    W32((uint32_t)(c->esp + 0x40u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x40], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x40u))); /* mov eax, dword ptr [esp + 0x40] */
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
    FPUSH(c, (double)RF32((uint32_t)(0x5912e8u))); /* fld dword ptr [0x100112e8] */
    FPUSH(c, (double)RF32((uint32_t)(0x5912ecu))); /* fld dword ptr [0x100112ec] */
    FPUSH(c, (double)RF32((uint32_t)(0x5912f0u))); /* fld dword ptr [0x100112f0] */
    WF32((uint32_t)(c->esp + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x24] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x44u))); /* fadd dword ptr [esp + 0x44] */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x28], 0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov ecx, dword ptr [esp + 0x28] */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [esp + 0x2c], 0x3f800000 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov edx, dword ptr [esp + 0x2c] */
    WF32((uint32_t)(c->esp + 0x34u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x34] */
    W32((uint32_t)(c->esp + 0x30u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x30], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov eax, dword ptr [esp + 0x30] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x48u))); /* fadd dword ptr [esp + 0x48] */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x1c], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov ecx, dword ptr [esp + 0x34] */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x20], edx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x10], ecx */
    WF32((uint32_t)(c->esp + 0x38u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x38] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x24u))); /* fld dword ptr [esp + 0x24] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x4cu))); /* fadd dword ptr [esp + 0x4c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x38u))); /* mov edx, dword ptr [esp + 0x38] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x44u))); /* mov ecx, dword ptr [esp + 0x44] */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x24], eax */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x14], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x48u))); /* mov edx, dword ptr [esp + 0x48] */
    W32((uint32_t)(c->esp + 0x34u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x34], ecx */
    WF32((uint32_t)(c->esp + 0x3cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x3c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x3cu))); /* mov eax, dword ptr [esp + 0x3c] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x54u)); /* lea ecx, [esp + 0x54] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x18], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4cu))); /* mov eax, dword ptr [esp + 0x4c] */
    W32((uint32_t)(c->esp + 0x38u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x38], edx */
    W32((uint32_t)(c->esp + 0x3cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x3c], eax */
    W32((uint32_t)(c->esp + 0x40u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x40], ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x40u))); /* mov eax, dword ptr [esp + 0x40] */
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
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x34u))); /* fsub dword ptr [esp + 0x34] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x10u)); /* lea edx, [esp + 0x10] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x3cu))); /* fsub dword ptr [esp + 0x3c] */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fld dword ptr [esp + 0x1c] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x40u))); /* fsub dword ptr [esp + 0x40] */
    WF32((uint32_t)(c->esp + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1c] */
    PUSH32(c, 0x00581cfbu); f_00583fa0(c); /* call 0x583fa0 */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x58d190u))); /* fcom dword ptr [0x1000d190] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x44u)); /* test ah, 0x44 */
    if (PF(c)) goto L_00581e84; /* jp 0x581e84 */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x34u)); /* lea eax, [esp + 0x34] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x10cu)); /* lea ecx, [esp + 0x10c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    PUSH32(c, 0x00581d23u); f_00583fd0(c); /* call 0x583fd0 */
    FPUSH(c, (double)RF32((uint32_t)(0x5912e8u))); /* fld dword ptr [0x100112e8] */
    FPUSH(c, (double)RF32((uint32_t)(0x5912ecu))); /* fld dword ptr [0x100112ec] */
    FPUSH(c, (double)RF32((uint32_t)(0x5912f0u))); /* fld dword ptr [0x100112f0] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    WF32((uint32_t)(c->esp + 0xa4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xa4] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x44u))); /* fadd dword ptr [esp + 0x44] */
    W32((uint32_t)(c->esp + 0x84u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x84], edx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    W32((uint32_t)(c->esp + 0x88u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x88], ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov edx, dword ptr [eax + 8] */
    WF32((uint32_t)(c->esp + 0x34u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x34] */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x28], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov eax, dword ptr [esp + 0x28] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x48u))); /* fadd dword ptr [esp + 0x48] */
    W32((uint32_t)(c->esp + 0x8cu), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x8c], edx */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x2c], 0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov ecx, dword ptr [esp + 0x2c] */
    W32((uint32_t)(c->esp + 0x30u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [esp + 0x30], 0x3f800000 */
    WF32((uint32_t)(c->esp + 0x38u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x38] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xa4u))); /* fld dword ptr [esp + 0xa4] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x4cu))); /* fadd dword ptr [esp + 0x4c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov edx, dword ptr [esp + 0x30] */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x1c], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov eax, dword ptr [esp + 0x34] */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x20], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x38u))); /* mov ecx, dword ptr [esp + 0x38] */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x24], edx */
    WF32((uint32_t)(c->esp + 0x3cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x3c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x3cu))); /* mov edx, dword ptr [esp + 0x3c] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x44u))); /* mov eax, dword ptr [esp + 0x44] */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x14], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x48u))); /* mov ecx, dword ptr [esp + 0x48] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x18], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4cu))); /* mov edx, dword ptr [esp + 0x4c] */
    W32((uint32_t)(c->esp + 0x34u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x34], eax */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x54u)); /* lea eax, [esp + 0x54] */
    W32((uint32_t)(c->esp + 0x38u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x38], ecx */
    W32((uint32_t)(c->esp + 0x3cu), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x3c], edx */
    W32((uint32_t)(c->esp + 0x40u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x40], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x40u))); /* mov eax, dword ptr [esp + 0x40] */
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
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x34u)); /* lea ecx, [esp + 0x34] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea ecx, [esp + 0x14] */
    PUSH32(c, 0x00581e2du); f_00583f40(c); /* call 0x583f40 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x10u)); /* lea edx, [esp + 0x10] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00581e37u); f_00583fa0(c); /* call 0x583fa0 */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x58d190u))); /* fcom dword ptr [0x1000d190] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x44u)); /* test ah, 0x44 */
    if (PF(c)) goto L_00582014; /* jp 0x582014 */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x34u)); /* lea eax, [esp + 0x34] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0xc0u)); /* lea ecx, [esp + 0xc0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    PUSH32(c, 0x00581e5fu); f_00583fd0(c); /* call 0x583fd0 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    W32((uint32_t)(c->esp + 0x84u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x84], edx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    W32((uint32_t)(c->esp + 0x88u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x88], ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov edx, dword ptr [eax + 8] */
    W32((uint32_t)(c->esp + 0x8cu), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x8c], edx */
    goto L_00582131; /* jmp 0x582131 */
L_00581e84:;
    ST(0) = FPRES(c, sqrt(ST(0))); /* fsqrt  */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0xacu)); /* lea ecx, [esp + 0xac] */
    ST(0) = FPRES(c, FDIV(c, (double)RF32((uint32_t)(0x58d18cu)), ST(0))); /* fdivr dword ptr [0x1000d18c] */
    WF32((uint32_t)(c->esp), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp] */
    PUSH32(c, 0x00581e9cu); f_00583f00(c); /* call 0x583f00 */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0xa8u)); /* lea eax, [esp + 0xa8] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x10u)); /* lea ecx, [esp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00581eadu); f_00583f70(c); /* call 0x583f70 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x1cu)); /* lea ecx, [esp + 0x1c] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x10u)); /* lea edx, [esp + 0x10] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00581ebcu); f_00584060(c); /* call 0x584060 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea eax, [esp + 0x14] */
    WF32((uint32_t)(c->esp), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0xc4u)); /* lea ecx, [esp + 0xc4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00581ed4u); f_00583ff0(c); /* call 0x583ff0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x1cu)); /* lea ecx, [esp + 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00581ee1u); f_00583f40(c); /* call 0x583f40 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x1cu)); /* lea edx, [esp + 0x1c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00581eebu); f_00583fa0(c); /* call 0x583fa0 */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x58d190u))); /* fcom dword ptr [0x1000d190] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x44u)); /* test ah, 0x44 */
    if (PF(c)) goto L_00581f07; /* jp 0x581f07 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [esp + 0x20], 0x3f800000 */
    goto L_00581f30; /* jmp 0x581f30 */
L_00581f07:;
    ST(0) = FPRES(c, sqrt(ST(0))); /* fsqrt  */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0xb8u)); /* lea ecx, [esp + 0xb8] */
    ST(0) = FPRES(c, FDIV(c, (double)RF32((uint32_t)(0x58d18cu)), ST(0))); /* fdivr dword ptr [0x1000d18c] */
    WF32((uint32_t)(c->esp), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp] */
    PUSH32(c, 0x00581f1fu); f_00583f00(c); /* call 0x583f00 */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0xb4u)); /* lea eax, [esp + 0xb4] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x1cu)); /* lea ecx, [esp + 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00581f30u); f_00583f70(c); /* call 0x583f70 */
L_00581f30:;
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x10u)); /* lea ecx, [esp + 0x10] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x1cu)); /* lea edx, [esp + 0x1c] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x2cu)); /* lea eax, [esp + 0x2c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00581f44u); f_00584020(c); /* call 0x584020 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x34u)); /* lea ecx, [esp + 0x34] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00581f4eu); f_00583fa0(c); /* call 0x583fa0 */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x58d190u))); /* fcom dword ptr [0x1000d190] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x44u)); /* test ah, 0x44 */
    if (!PF(c)) goto L_00582112; /* jnp 0x582112 */
    ST(0) = FPRES(c, sqrt(ST(0))); /* fsqrt  */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0xa0u)); /* lea ecx, [esp + 0xa0] */
    ST(0) = FPRES(c, FDIV(c, (double)RF32((uint32_t)(0x58d18cu)), ST(0))); /* fdivr dword ptr [0x1000d18c] */
    WF32((uint32_t)(c->esp), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp] */
    PUSH32(c, 0x00581f7au); f_00583f00(c); /* call 0x583f00 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x9cu)); /* lea edx, [esp + 0x9c] */
L_00581f81:;
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x2cu)); /* lea ecx, [esp + 0x2c] */
    PUSH32(c, 0x00581f8bu); f_00583f70(c); /* call 0x583f70 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov eax, dword ptr [esp + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov ecx, dword ptr [esp + 0x20] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov edx, dword ptr [esp + 0x24] */
    W32((uint32_t)(c->esp + 0x54u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x54], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    W32((uint32_t)(c->esp + 0x58u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x58], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ecx, dword ptr [esp + 0x14] */
    W32((uint32_t)(c->esp + 0x5cu), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x5c], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov edx, dword ptr [esp + 0x18] */
    W32((uint32_t)(c->esp + 0x64u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x64], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov eax, dword ptr [esp + 0x28] */
    W32((uint32_t)(c->esp + 0x68u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x68], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov ecx, dword ptr [esp + 0x2c] */
    W32((uint32_t)(c->esp + 0x6cu), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x6c], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov edx, dword ptr [esp + 0x30] */
    W32((uint32_t)(c->esp + 0x74u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x74], eax */
    W32((uint32_t)(c->esp + 0x78u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x78], ecx */
    W32((uint32_t)(c->esp + 0x7cu), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x7c], edx */
    W32((uint32_t)(c->esp + 0x54u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x54], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov eax, dword ptr [esp + 0x1c] */
    W32((uint32_t)(c->esp + 0x64u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x64], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov ecx, dword ptr [esp + 0x20] */
    W32((uint32_t)(c->esp + 0x74u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x74], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov edx, dword ptr [esp + 0x24] */
    W32((uint32_t)(c->esp + 0x58u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x58], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    W32((uint32_t)(c->esp + 0x68u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x68], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ecx, dword ptr [esp + 0x14] */
    W32((uint32_t)(c->esp + 0x78u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x78], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov edx, dword ptr [esp + 0x18] */
    W32((uint32_t)(c->esp + 0x5cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x5c], eax */
    W32((uint32_t)(c->esp + 0x6cu), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x6c], ecx */
    W32((uint32_t)(c->esp + 0x7cu), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x7c], edx */
    goto L_00582114; /* jmp 0x582114 */
L_00582014:;
    ST(0) = FPRES(c, sqrt(ST(0))); /* fsqrt  */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0xa0u)); /* lea ecx, [esp + 0xa0] */
    ST(0) = FPRES(c, FDIV(c, (double)RF32((uint32_t)(0x58d18cu)), ST(0))); /* fdivr dword ptr [0x1000d18c] */
    WF32((uint32_t)(c->esp), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp] */
    PUSH32(c, 0x0058202cu); f_00583f00(c); /* call 0x583f00 */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x9cu)); /* lea eax, [esp + 0x9c] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x10u)); /* lea ecx, [esp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0058203du); f_00583f70(c); /* call 0x583f70 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x1cu)); /* lea ecx, [esp + 0x1c] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x10u)); /* lea edx, [esp + 0x10] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x0058204cu); f_00584060(c); /* call 0x584060 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea eax, [esp + 0x14] */
    WF32((uint32_t)(c->esp), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x110u)); /* lea ecx, [esp + 0x110] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00582064u); f_00583ff0(c); /* call 0x583ff0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x1cu)); /* lea ecx, [esp + 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00582071u); f_00583f40(c); /* call 0x583f40 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x1cu)); /* lea edx, [esp + 0x1c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x0058207bu); f_00583fa0(c); /* call 0x583fa0 */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x58d190u))); /* fcom dword ptr [0x1000d190] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x44u)); /* test ah, 0x44 */
    if (PF(c)) goto L_00582097; /* jp 0x582097 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [esp + 0x20], 0x3f800000 */
    goto L_005820c0; /* jmp 0x5820c0 */
L_00582097:;
    ST(0) = FPRES(c, sqrt(ST(0))); /* fsqrt  */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0xb8u)); /* lea ecx, [esp + 0xb8] */
    ST(0) = FPRES(c, FDIV(c, (double)RF32((uint32_t)(0x58d18cu)), ST(0))); /* fdivr dword ptr [0x1000d18c] */
    WF32((uint32_t)(c->esp), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp] */
    PUSH32(c, 0x005820afu); f_00583f00(c); /* call 0x583f00 */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0xb4u)); /* lea eax, [esp + 0xb4] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x1cu)); /* lea ecx, [esp + 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x005820c0u); f_00583f70(c); /* call 0x583f70 */
L_005820c0:;
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x10u)); /* lea ecx, [esp + 0x10] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x1cu)); /* lea edx, [esp + 0x1c] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x2cu)); /* lea eax, [esp + 0x2c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x005820d4u); f_00584020(c); /* call 0x584020 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x34u)); /* lea ecx, [esp + 0x34] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x005820deu); f_00583fa0(c); /* call 0x583fa0 */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x58d190u))); /* fcom dword ptr [0x1000d190] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x44u)); /* test ah, 0x44 */
    if (!PF(c)) goto L_00582112; /* jnp 0x582112 */
    ST(0) = FPRES(c, sqrt(ST(0))); /* fsqrt  */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0xacu)); /* lea ecx, [esp + 0xac] */
    ST(0) = FPRES(c, FDIV(c, (double)RF32((uint32_t)(0x58d18cu)), ST(0))); /* fdivr dword ptr [0x1000d18c] */
    WF32((uint32_t)(c->esp), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp] */
    PUSH32(c, 0x00582106u); f_00583f00(c); /* call 0x583f00 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0xa8u)); /* lea edx, [esp + 0xa8] */
    goto L_00581f81; /* jmp 0x581f81 */
L_00582112:;
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
L_00582114:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x3cu))); /* mov eax, dword ptr [esp + 0x3c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x38u))); /* mov ecx, dword ptr [esp + 0x38] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov edx, dword ptr [esp + 0x34] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x60u)); /* lea ecx, [esp + 0x60] */
    PUSH32(c, 0x0058212cu); f_005842b0(c); /* call 0x5842b0 */
    goto L_005821f1; /* jmp 0x5821f1 */
L_00582131:;
    c->eax = (uint32_t)(R32((uint32_t)(0x5912f0u))); /* mov eax, dword ptr [0x100112f0] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x5912ecu))); /* mov ecx, dword ptr [0x100112ec] */
    c->edx = (uint32_t)(R32((uint32_t)(0x5912e8u))); /* mov edx, dword ptr [0x100112e8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x40u)); /* lea ecx, [esp + 0x40] */
    W32((uint32_t)(c->esp + 0x34u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [esp + 0x34], 0x3f800000 */
    W32((uint32_t)(c->esp + 0x38u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x38], 0 */
    W32((uint32_t)(c->esp + 0x3cu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x3c], 0 */
    PUSH32(c, 0x00582166u); f_00583f20(c); /* call 0x583f20 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x3cu))); /* fld dword ptr [esp + 0x3c] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x4cu))); /* fadd dword ptr [esp + 0x4c] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x28u)); /* lea ecx, [esp + 0x28] */
    WF32((uint32_t)(c->esp + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x44u))); /* fld dword ptr [esp + 0x44] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x54u))); /* fadd dword ptr [esp + 0x54] */
    WF32((uint32_t)(c->esp + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x40u))); /* fld dword ptr [esp + 0x40] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x50u))); /* fadd dword ptr [esp + 0x50] */
    WF32((uint32_t)(c->esp), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp] */
    PUSH32(c, 0x00582195u); f_00583f20(c); /* call 0x583f20 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov ecx, dword ptr [esp + 0x28] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov edx, dword ptr [esp + 0x2c] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    c->eax = (uint32_t)(c->esp); /* mov eax, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x48u))); /* mov ecx, dword ptr [esp + 0x48] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 4], edx */
    c->edx = (uint32_t)(c->esp); /* mov edx, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x40u))); /* mov eax, dword ptr [esp + 0x40] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x44u))); /* mov ecx, dword ptr [esp + 0x44] */
    W32((uint32_t)(c->edx), (uint32_t)(c->eax)); /* mov dword ptr [edx], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x48u))); /* mov eax, dword ptr [esp + 0x48] */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [edx + 4], ecx */
    c->ecx = (uint32_t)(c->esp); /* mov ecx, esp */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [edx + 8], eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x68u))); /* mov edx, dword ptr [esp + 0x68] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x6cu))); /* mov eax, dword ptr [esp + 0x6c] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x70u))); /* mov edx, dword ptr [esp + 0x70] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 4], eax */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 8], edx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x78u)); /* lea ecx, [esp + 0x78] */
    PUSH32(c, 0x005821e9u); f_00584310(c); /* call 0x584310 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_0058247f; /* je 0x58247f */
L_005821f1:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x12cu))); /* mov ecx, dword ptr [esp + 0x12c] */
    W8((uint32_t)(c->ebp + 0x44u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ebp + 0x44], 1 */
    W8((uint32_t)(c->ebp + 0x45u), (uint8_t)((uint8_t)0xffu)); /* mov byte ptr [ebp + 0x45], 0xff */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(0x591790u))); /* mov ax, word ptr [0x10011790] */
    W16((uint32_t)(c->ebp + 0x46u), (uint16_t)(((uint16_t)c->eax))); /* mov word ptr [ebp + 0x46], ax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x124u))); /* mov eax, dword ptr [esp + 0x124] */
    W32((uint32_t)(c->ebp + 0x48u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp + 0x48], ecx */
    c->edx = (uint32_t)((uint32_t)(c->ebp + 0x54u)); /* lea edx, [ebp + 0x54] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x120u))); /* mov ebx, dword ptr [esp + 0x120] */
    W32((uint32_t)(c->edx), (uint32_t)(c->ecx)); /* mov dword ptr [edx], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [edx + 4], ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0x60u)); /* lea ecx, [ebp + 0x60] */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [edx + 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x128u))); /* mov eax, dword ptr [esp + 0x128] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov edx, dword ptr [eax + 4] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 4], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x11cu))); /* mov eax, dword ptr [esp + 0x11c] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->eax * 4 + 0xau)); /* lea ecx, [eax + eax*4 + 0xa] */
    W32((uint32_t)(c->edi + c->ecx * 8), (uint32_t)(c->ebx)); /* mov dword ptr [edi + ecx*8], ebx */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + 0x92844u))); /* mov edx, dword ptr [edi + 0x92844] */
    W32((uint32_t)(c->ebp + 0x4cu), (uint32_t)(c->edx)); /* mov dword ptr [ebp + 0x4c], edx */
    c->eax = (uint32_t)(R32((uint32_t)(0x591790u))); /* mov eax, dword ptr [0x10011790] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x92844u))); /* mov ecx, dword ptr [edi + 0x92844] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea eax, [eax + eax*2] */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    W32((uint32_t)(c->edi + 0x92844u), (uint32_t)(c->ecx)); /* mov dword ptr [edi + 0x92844], ecx */
    (void)sub32(c, c->eax, (uint32_t)0x6000u); /* cmp eax, 0x6000 */
    if (c->cf) goto L_005822a1; /* jb 0x5822a1 */
    c->eax = (uint32_t)(R32((uint32_t)(0x591280u))); /* mov eax, dword ptr [0x10011280] */
    { uint32_t v_ = 0x58e15cu; PUSH32(c, v_); } /* push 0x1000e15c */
    { uint32_t v_ = 0xa6u; PUSH32(c, v_); } /* push 0xa6 */
    { uint32_t v_ = 0x58e058u; PUSH32(c, v_); } /* push 0x1000e058 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x58e128u; PUSH32(c, v_); } /* push 0x1000e128 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x0058229du); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x005822a0u, "int3"); /* int3  */
L_005822a1:;
    c->edx = (uint32_t)((uint32_t)(c->esp + 0xccu)); /* lea edx, [esp + 0xcc] */
    W32((uint32_t)(c->esp + 0x40u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x40], esi */
    W32((uint32_t)(c->esp + 0x50u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x50], edx */
    c->df = 0; /* cld  */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x50u))); /* mov edi, dword ptr [esp + 0x50] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x40u))); /* mov esi, dword ptr [esp + 0x40] */
    c->ecx = (uint32_t)((uint32_t)0x10u); /* mov ecx, 0x10 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0xccu)); /* lea ecx, [esp + 0xcc] */
    PUSH32(c, 0x005822ccu); f_00584220(c); /* call 0x584220 */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ebp + 0x4cu))); /* mov ebp, dword ptr [ebp + 0x4c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x94u))); /* mov ecx, dword ptr [esp + 0x94] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x1u)); /* test bl, 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + c->ebp * 2)); /* lea eax, [ebp + ebp*2] */
    W32((uint32_t)(c->esp + 0x50u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x50], 0 */
    W32((uint32_t)(c->esp + 0x40u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x40], 0 */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->eax * 8 + 0x2844u)); /* lea ecx, [ecx + eax*8 + 0x2844] */
    c->eax = (uint32_t)(R32((uint32_t)(0x591790u))); /* mov eax, dword ptr [0x10011790] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea eax, [eax + eax*2] */
    W32((uint32_t)(0x591790u), (uint32_t)(c->eax)); /* mov dword ptr [0x10011790], eax */
    if (c->zf) goto L_0058230b; /* je 0x58230b */
    W32((uint32_t)(c->esp + 0x50u), (uint32_t)((uint32_t)0x3f000000u)); /* mov dword ptr [esp + 0x50], 0x3f000000 */
L_0058230b:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x2u)); /* test bl, 2 */
    if (c->zf) goto L_00582318; /* je 0x582318 */
    W32((uint32_t)(c->esp + 0x40u), (uint32_t)((uint32_t)0x3f000000u)); /* mov dword ptr [esp + 0x40], 0x3f000000 */
L_00582318:;
    c->ebp = (uint32_t)(logic32(c, 0)); /* xor ebp, ebp */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_0058246b; /* jle 0x58246b */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->edi = (uint32_t)((uint32_t)0x591310u); /* mov edi, 0x10011310 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4u))); /* and eax, 4 */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x8u))); /* and ebx, 8 */
    W32((uint32_t)(c->esp + 0x98u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x98], eax */
    c->esi = (uint32_t)((uint32_t)(c->ecx + 0x10u)); /* lea esi, [ecx + 0x10] */
L_00582339:;
    c->edx = (uint32_t)((uint32_t)(c->esp + 0xc0u)); /* lea edx, [esp + 0xc0] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0xd4u)); /* lea ecx, [esp + 0xd4] */
    PUSH32(c, 0x0058234eu); f_005841a0(c); /* call 0x5841a0 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0xfffffff0u)); /* lea ecx, [esi - 0x10] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov edx, dword ptr [eax + 4] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 4], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    W32((uint32_t)(c->esi + 0xfffffffcu), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [esi - 4], 0xffffffff */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 8], eax */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea ecx, [esp + 0x14] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x5cu)); /* lea ecx, [esp + 0x5c] */
    PUSH32(c, 0x00582377u); f_005841a0(c); /* call 0x5841a0 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x58d188u))); /* fmul dword ptr [0x1000d188] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0x58d184u))); /* fadd dword ptr [0x1000d184] */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x58d188u))); /* fmul dword ptr [0x1000d188] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0x58d184u))); /* fadd dword ptr [0x1000d184] */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x58d190u))); FPOP(c); /* fcomp dword ptr [0x1000d190] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_005823ba; /* jp 0x5823ba */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x10], 0 */
    goto L_005823d5; /* jmp 0x5823d5 */
L_005823ba:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x58d18cu))); FPOP(c); /* fcomp dword ptr [0x1000d18c] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_005823d5; /* jne 0x5823d5 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [esp + 0x10], 0x3f800000 */
L_005823d5:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x58d190u))); FPOP(c); /* fcomp dword ptr [0x1000d190] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_005823f0; /* jp 0x5823f0 */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x14], 0 */
    goto L_0058240b; /* jmp 0x58240b */
L_005823f0:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x58d18cu))); FPOP(c); /* fcomp dword ptr [0x1000d18c] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_0058240b; /* jne 0x58240b */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [esp + 0x14], 0x3f800000 */
L_0058240b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x98u))); /* mov eax, dword ptr [esp + 0x98] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00582424; /* je 0x582424 */
    FPUSH(c, (double)RF32((uint32_t)(0x58d18cu))); /* fld dword ptr [0x1000d18c] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x10u))); /* fsub dword ptr [esp + 0x10] */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
L_00582424:;
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (c->zf) goto L_00582436; /* je 0x582436 */
    FPUSH(c, (double)RF32((uint32_t)(0x58d18cu))); /* fld dword ptr [0x1000d18c] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x14u))); /* fsub dword ptr [esp + 0x14] */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
L_00582436:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x58d184u))); /* fmul dword ptr [0x1000d184] */
    c->ebp = (uint32_t)(inc32(c, c->ebp)); /* inc ebp */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0xcu)); /* add edi, 0xc */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x18u)); /* add esi, 0x18 */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x50u))); /* fadd dword ptr [esp + 0x50] */
    WF32((uint32_t)(c->esi + 0xffffffe8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi - 0x18] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x58d184u))); /* fmul dword ptr [0x1000d184] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x40u))); /* fadd dword ptr [esp + 0x40] */
    WF32((uint32_t)(c->esi + 0xffffffecu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi - 0x14] */
    (void)sub32(c, c->ebp, R32((uint32_t)(0x591790u))); /* cmp ebp, dword ptr [0x10011790] */
    if ((c->sf != c->of)) goto L_00582339; /* jl 0x582339 */
L_0058246b:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x11cu))); /* mov edx, dword ptr [esp + 0x11c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x94u))); /* mov ecx, dword ptr [esp + 0x94] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x0058247fu); f_00582660(c); /* call 0x582660 */
L_0058247f:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x108u)); /* add esp, 0x108 */
    c->esp += 24; return; /* ret 0x14 */
}

void f_00582490(CPU *c) { /* FUN_10002490 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov eax, dword ptr [edi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->cf || c->zf)) goto L_005824c9; /* jbe 0x5824c9 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ebx, dword ptr [esp + 0x10] */
L_005824a2:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x10u))); /* mov eax, dword ptr [edi + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 4))); /* mov eax, dword ptr [eax + esi*4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x005824b3u); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x005824bau); f_0058c990(c); /* call 0x58c990 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_005824d1; /* je 0x5824d1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov eax, dword ptr [edi + 4] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if (c->cf) goto L_005824a2; /* jb 0x5824a2 */
L_005824c9:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
L_005824d1:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x10u))); /* mov ecx, dword ptr [edi + 0x10] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + c->esi * 4))); /* mov eax, dword ptr [ecx + esi*4] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
}

void f_005824e0(CPU *c) { /* FUN_100024e0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ebp = (uint32_t)(c->ecx); /* mov ebp, ecx */
    if (c->zf) goto L_0058264f; /* je 0x58264f */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov ebx, dword ptr [esp + 0x18] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & ((uint8_t)c->ebx))); /* test bl, bl */
    if (c->zf) goto L_005825fc; /* je 0x5825fc */
    W8((uint32_t)(c->esi + 0x87u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esi + 0x87], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x84u))); /* mov eax, dword ptr [esi + 0x84] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 24)); /* shl ecx, 0x18 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->eax))); /* or ecx, eax */
    W32((uint32_t)(c->esi + 0x84u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 0x84], ecx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x4u)); PUSH32(c, 0x0058251fu); call_indirect(c, t_); } /* call dword ptr [edx + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00582626; /* je 0x582626 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_00582626; /* je 0x582626 */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x72u); /* cmp cl, 0x72 */
    if (c->zf) goto L_005825d4; /* je 0x5825d4 */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x52u); /* cmp cl, 0x52 */
    if (c->zf) goto L_005825d4; /* je 0x5825d4 */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x6du); /* cmp cl, 0x6d */
    if (c->zf) goto L_0058259f; /* je 0x58259f */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x4du); /* cmp cl, 0x4d */
    if (c->zf) goto L_0058259f; /* je 0x58259f */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x70u); /* cmp cl, 0x70 */
    if (c->zf) goto L_0058255b; /* je 0x58255b */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x50u); /* cmp cl, 0x50 */
    if (!c->zf) goto L_00582626; /* jne 0x582626 */
L_0058255b:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1u))); /* mov cl, byte ptr [eax + 1] */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x61u); /* cmp cl, 0x61 */
    if (c->zf) goto L_0058256c; /* je 0x58256c */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x41u); /* cmp cl, 0x41 */
    if (!c->zf) goto L_00582626; /* jne 0x582626 */
L_0058256c:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x2u))); /* mov cl, byte ptr [eax + 2] */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x74u); /* cmp cl, 0x74 */
    if (c->zf) goto L_0058257d; /* je 0x58257d */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x54u); /* cmp cl, 0x54 */
    if (!c->zf) goto L_00582626; /* jne 0x582626 */
L_0058257d:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x3u))); /* mov al, byte ptr [eax + 3] */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x68u); /* cmp al, 0x68 */
    if (c->zf) goto L_0058258c; /* je 0x58258c */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x48u); /* cmp al, 0x48 */
    if (!c->zf) goto L_00582626; /* jne 0x582626 */
L_0058258c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x84u))); /* mov eax, dword ptr [esi + 0x84] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfbu))); /* and al, 0xfb */
    W32((uint32_t)(c->esi + 0x84u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x84], eax */
    goto L_00582626; /* jmp 0x582626 */
L_0058259f:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1u))); /* mov cl, byte ptr [eax + 1] */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x61u); /* cmp cl, 0x61 */
    if (c->zf) goto L_005825ac; /* je 0x5825ac */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x41u); /* cmp cl, 0x41 */
    if (!c->zf) goto L_00582626; /* jne 0x582626 */
L_005825ac:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x2u))); /* mov cl, byte ptr [eax + 2] */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x73u); /* cmp cl, 0x73 */
    if (c->zf) goto L_005825b9; /* je 0x5825b9 */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x53u); /* cmp cl, 0x53 */
    if (!c->zf) goto L_00582626; /* jne 0x582626 */
L_005825b9:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x3u))); /* mov al, byte ptr [eax + 3] */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x74u); /* cmp al, 0x74 */
    if (c->zf) goto L_005825c4; /* je 0x5825c4 */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x54u); /* cmp al, 0x54 */
    if (!c->zf) goto L_00582626; /* jne 0x582626 */
L_005825c4:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x84u))); /* mov eax, dword ptr [esi + 0x84] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfbu))); /* and al, 0xfb */
    W32((uint32_t)(c->esi + 0x84u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x84], eax */
    goto L_00582626; /* jmp 0x582626 */
L_005825d4:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1u))); /* mov cl, byte ptr [eax + 1] */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x65u); /* cmp cl, 0x65 */
    if (c->zf) goto L_005825e1; /* je 0x5825e1 */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x45u); /* cmp cl, 0x45 */
    if (!c->zf) goto L_00582626; /* jne 0x582626 */
L_005825e1:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x2u))); /* mov al, byte ptr [eax + 2] */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x79u); /* cmp al, 0x79 */
    if (c->zf) goto L_005825ec; /* je 0x5825ec */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x59u); /* cmp al, 0x59 */
    if (!c->zf) goto L_00582626; /* jne 0x582626 */
L_005825ec:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x84u))); /* mov eax, dword ptr [esi + 0x84] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfbu))); /* and al, 0xfb */
    W32((uint32_t)(c->esi + 0x84u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x84], eax */
    goto L_00582626; /* jmp 0x582626 */
L_005825fc:;
    c->edi = (uint32_t)(R32((uint32_t)(c->esi + 0x84u))); /* mov edi, dword ptr [esi + 0x84] */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & (uint32_t)0xffffff00u))); /* and edi, 0xffffff00 */
    W32((uint32_t)(c->esi + 0x84u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0x84], edi */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->ecx = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->esi + 0x87u))); /* movsx ecx, byte ptr [esi + 0x87] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->eax))); /* or ecx, eax */
    W32((uint32_t)(c->esi + 0x84u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 0x84], ecx */
    W8((uint32_t)(c->esi + 0x87u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esi + 0x87], 0 */
L_00582626:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x90u))); /* mov eax, dword ptr [esi + 0x90] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_0058264f; /* jle 0x58264f */
L_00582632:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x94u))); /* mov edx, dword ptr [esi + 0x94] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + c->edi * 4))); /* mov eax, dword ptr [edx + edi*4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00582644u); f_005824e0(c); /* call 0x5824e0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x90u))); /* mov eax, dword ptr [esi + 0x90] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if ((c->sf != c->of)) goto L_00582632; /* jl 0x582632 */
L_0058264f:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 12; return; /* ret 8 */
}

void f_00582660(CPU *c) { /* FUN_10002660 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(logic32(c, (uint32_t)(c->esp & (uint32_t)0xfffffff8u))); /* and esp, 0xfffffff8 */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x1a4u)); /* sub esp, 0x1a4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x24], esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x40u))); /* mov eax, dword ptr [esi + 0x40] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00582977; /* je 0x582977 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea eax, [esp + 0x14] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x58e1a8u; PUSH32(c, v_); } /* push 0x1000e1a8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00582693u); f_00584b54(c); /* call 0x584b54 */
    c->ecx = (uint32_t)((uint32_t)(c->ebx + c->ebx * 4)); /* lea ecx, [ebx + ebx*4] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + c->ecx * 8 + 0x44u))); /* mov al, byte ptr [esi + ecx*8 + 0x44] */
    c->edi = (uint32_t)((uint32_t)(c->esi + c->ecx * 8)); /* lea edi, [esi + ecx*8] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00582960; /* je 0x582960 */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0x40u))); /* mov esi, dword ptr [esi + 0x40] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_005827e7; /* je 0x5827e7 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
L_005826b5:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + c->ebx + 0x14u))); /* mov al, byte ptr [esp + ebx + 0x14] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_005827b5; /* je 0x5827b5 */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x2eu); /* cmp al, 0x2e */
    if (c->zf) goto L_005826c8; /* je 0x5826c8 */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    goto L_005826b5; /* jmp 0x5826b5 */
L_005826c8:;
    (void)sub32(c, c->ebx, (uint32_t)0x104u); /* cmp ebx, 0x104 */
    if (!c->cf) goto L_00582736; /* jae 0x582736 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea edx, [esp + 0x14] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0xacu)); /* lea eax, [esp + 0xac] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x005826e3u); f_00584bb0(c); /* call 0x584bb0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0xa8u)); /* lea ecx, [esp + 0xa8] */
    W8((uint32_t)(c->esp + c->ebx + 0xa8u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esp + ebx + 0xa8], 0 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x005826fdu); f_00582490(c); /* call 0x582490 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_005827a6; /* jne 0x5827a6 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0xa8u)); /* lea eax, [esp + 0xa8] */
    { uint32_t v_ = 0x6217acu; PUSH32(c, v_); } /* push 0x100a17ac */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x00582719u); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00582721u); f_00583b00(c); /* call 0x583b00 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0xa8u)); /* lea ecx, [esp + 0xa8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00582730u); f_00582490(c); /* call 0x582490 */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0xc], eax */
    goto L_005827a2; /* jmp 0x5827a2 */
L_00582736:;
    { uint32_t v_ = 0x148u; PUSH32(c, v_); } /* push 0x148 */
    c->edx = (uint32_t)((uint32_t)(c->ebx + 0x1u)); /* lea edx, [ebx + 1] */
    { uint32_t v_ = 0x58e0e8u; PUSH32(c, v_); } /* push 0x1000e0e8 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00582749u); f_00581030(c); /* call 0x581030 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x20u)); /* lea ecx, [esp + 0x20] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x28], eax */
    PUSH32(c, 0x00582759u); f_00584bb0(c); /* call 0x584bb0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov eax, dword ptr [esp + 0x28] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W8((uint32_t)(c->eax + c->ebx), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [eax + ebx], 0 */
    PUSH32(c, 0x0058276cu); f_00582490(c); /* call 0x582490 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0xc], eax */
    if (!c->zf) goto L_00582795; /* jne 0x582795 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    { uint32_t v_ = 0x6217acu; PUSH32(c, v_); } /* push 0x100a17ac */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00582785u); f_00582980(c); /* call 0x582980 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00582791u); f_00582490(c); /* call 0x582490 */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0xc], eax */
L_00582795:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x0058279fu); f_00581050(c); /* call 0x581050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_005827a2:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
L_005827a6:;
    c->edx = (uint32_t)((uint32_t)(c->esp + c->ebx + 0x15u)); /* lea edx, [esp + ebx + 0x15] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x005827b3u); f_005830a0(c); /* call 0x5830a0 */
    goto L_005827e2; /* jmp 0x5827e2 */
L_005827b5:;
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea eax, [esp + 0x14] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x005827c1u); f_00582490(c); /* call 0x582490 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_005827e2; /* jne 0x5827e2 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea ecx, [esp + 0x14] */
    { uint32_t v_ = 0x6217acu; PUSH32(c, v_); } /* push 0x100a17ac */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x005827d6u); f_00582980(c); /* call 0x582980 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea edx, [esp + 0x14] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x005827e2u); f_00582490(c); /* call 0x582490 */
L_005827e2:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_005827e7:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov edx, dword ptr [esp + 0x24] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x28u)); /* lea eax, [esp + 0x28] */
    c->ecx = (uint32_t)((uint32_t)(c->ebx + c->ebx * 4 + 0xau)); /* lea ecx, [ebx + ebx*4 + 0xa] */
    { uint32_t v_ = 0xau; PUSH32(c, v_); } /* push 0xa */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + c->ecx * 8))); /* mov eax, dword ptr [edx + ecx*8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x005827ffu); f_0058c971(c); /* call 0x58c971 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x28u)); /* lea edx, [esp + 0x28] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x58e1a4u; PUSH32(c, v_); } /* push 0x1000e1a4 */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0xcu)); PUSH32(c, 0x00582813u); call_indirect(c, t_); } /* call dword ptr [eax + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x0058281bu); f_00583b00(c); /* call 0x583b00 */
    FPUSH(c, (double)RF32((uint32_t)(c->edi + 0x54u))); /* fld dword ptr [edi + 0x54] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x30u)); /* lea ecx, [esp + 0x30] */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    { uint32_t v_ = 0x58e1a0u; PUSH32(c, v_); } /* push 0x1000e1a0 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00582833u); f_00584b54(c); /* call 0x584b54 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x28u)); /* lea edx, [esp + 0x28] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x58e19cu; PUSH32(c, v_); } /* push 0x1000e19c */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0xcu)); PUSH32(c, 0x00582847u); call_indirect(c, t_); } /* call dword ptr [eax + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x0058284fu); f_00583b00(c); /* call 0x583b00 */
    FPUSH(c, (double)RF32((uint32_t)(c->edi + 0x58u))); /* fld dword ptr [edi + 0x58] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x30u)); /* lea ecx, [esp + 0x30] */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    { uint32_t v_ = 0x58e1a0u; PUSH32(c, v_); } /* push 0x1000e1a0 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00582867u); f_00584b54(c); /* call 0x584b54 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x28u)); /* lea edx, [esp + 0x28] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x58e198u; PUSH32(c, v_); } /* push 0x1000e198 */
    PUSH32(c, 0x0058287bu); f_00582980(c); /* call 0x582980 */
    FPUSH(c, (double)RF32((uint32_t)(c->edi + 0x5cu))); /* fld dword ptr [edi + 0x5c] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x30u)); /* lea eax, [esp + 0x30] */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    { uint32_t v_ = 0x58e1a0u; PUSH32(c, v_); } /* push 0x1000e1a0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00582893u); f_00584b54(c); /* call 0x584b54 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x28u)); /* lea ecx, [esp + 0x28] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x58e194u; PUSH32(c, v_); } /* push 0x1000e194 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x005828a7u); f_00582980(c); /* call 0x582980 */
    FPUSH(c, (double)RF32((uint32_t)(c->edi + 0x60u))); /* fld dword ptr [edi + 0x60] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x30u)); /* lea edx, [esp + 0x30] */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    { uint32_t v_ = 0x58e1a0u; PUSH32(c, v_); } /* push 0x1000e1a0 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x005828bfu); f_00584b54(c); /* call 0x584b54 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x28u)); /* lea eax, [esp + 0x28] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x58e190u; PUSH32(c, v_); } /* push 0x1000e190 */
    PUSH32(c, 0x005828d3u); f_00582980(c); /* call 0x582980 */
    FPUSH(c, (double)RF32((uint32_t)(c->edi + 0x64u))); /* fld dword ptr [edi + 0x64] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x30u)); /* lea ecx, [esp + 0x30] */
    { uint32_t v_ = 0x58e1a0u; PUSH32(c, v_); } /* push 0x1000e1a0 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x005828ebu); f_00584b54(c); /* call 0x584b54 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x28u)); /* lea edx, [esp + 0x28] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x58e18cu; PUSH32(c, v_); } /* push 0x1000e18c */
    PUSH32(c, 0x005828ffu); f_00582980(c); /* call 0x582980 */
    FPUSH(c, (double)RF32((uint32_t)(c->edi + 0x68u))); /* fld dword ptr [edi + 0x68] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x30u)); /* lea eax, [esp + 0x30] */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    { uint32_t v_ = 0x58e1a0u; PUSH32(c, v_); } /* push 0x1000e1a0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00582917u); f_00584b54(c); /* call 0x584b54 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x28u)); /* lea ecx, [esp + 0x28] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x58e188u; PUSH32(c, v_); } /* push 0x1000e188 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x0058292bu); f_00582980(c); /* call 0x582980 */
    FPUSH(c, (double)RF32((uint32_t)(c->edi + 0x48u))); /* fld dword ptr [edi + 0x48] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x30u)); /* lea edx, [esp + 0x30] */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    { uint32_t v_ = 0x58e1a0u; PUSH32(c, v_); } /* push 0x1000e1a0 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00582943u); f_00584b54(c); /* call 0x584b54 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x28u)); /* lea eax, [esp + 0x28] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x58e180u; PUSH32(c, v_); } /* push 0x1000e180 */
    PUSH32(c, 0x00582957u); f_00582980(c); /* call 0x582980 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 8; return; /* ret 4 */
L_00582960:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x40u))); /* mov ecx, dword ptr [esi + 0x40] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea edx, [esp + 0x14] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x0058296eu); f_00583950(c); /* call 0x583950 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x40u))); /* mov ecx, dword ptr [esi + 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00582977u); f_005829a0(c); /* call 0x5829a0 */
L_00582977:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 8; return; /* ret 4 */
}

void f_00582980(CPU *c) { /* FUN_10002980 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x00582994u); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x0058299cu); f_00583b00(c); /* call 0x583b00 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 12; return; /* ret 8 */
}

void f_005829a0(CPU *c) { /* FUN_100029a0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    if (c->zf) goto L_00582a49; /* je 0x582a49 */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (!c->zf) goto L_00582a52; /* jne 0x582a52 */
    (void)sub32(c, R32((uint32_t)(c->ebx + 0x10u)), c->edi); /* cmp dword ptr [ebx + 0x10], edi */
    if (c->zf) goto L_00582a49; /* je 0x582a49 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov eax, dword ptr [ebx + 4] */
    c->ebp = (uint32_t)(logic32(c, 0)); /* xor ebp, ebp */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if ((c->cf || c->zf)) goto L_00582a37; /* jbe 0x582a37 */
L_005829ce:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x10u))); /* mov eax, dword ptr [ebx + 0x10] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + c->ebp * 4))); /* mov esi, dword ptr [eax + ebp*4] */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (c->zf) goto L_00582a2f; /* je 0x582a2f */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (c->zf) goto L_005829e8; /* je 0x5829e8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x005829e5u); f_00581050(c); /* call 0x581050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_005829e8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0xc], edi */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (c->zf) goto L_00582a20; /* je 0x582a20 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->cf || c->zf)) goto L_00582a12; /* jbe 0x582a12 */
L_005829f9:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + c->edi * 4))); /* mov ecx, dword ptr [ecx + edi*4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00582a0a; /* je 0x582a0a */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x00582a0au); f_00583e80(c); /* call 0x583e80 */
L_00582a0a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_005829f9; /* jb 0x5829f9 */
L_00582a12:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov edx, dword ptr [esi + 0x10] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00582a1bu); f_00581050(c); /* call 0x581050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
L_00582a20:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0x10], edi */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 4], edi */
    PUSH32(c, 0x00582a2cu); f_00581050(c); /* call 0x581050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00582a2f:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov eax, dword ptr [ebx + 4] */
    c->ebp = (uint32_t)(inc32(c, c->ebp)); /* inc ebp */
    (void)sub32(c, c->ebp, c->eax); /* cmp ebp, eax */
    if (c->cf) goto L_005829ce; /* jb 0x5829ce */
L_00582a37:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x10u))); /* mov eax, dword ptr [ebx + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00582a40u); f_00581050(c); /* call 0x581050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    W32((uint32_t)(c->ebx + 0x10u), (uint32_t)(c->edi)); /* mov dword ptr [ebx + 0x10], edi */
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->edi)); /* mov dword ptr [ebx + 4], edi */
L_00582a49:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
L_00582a52:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov eax, dword ptr [ebx + 4] */
    c->ebp = (uint32_t)(logic32(c, 0)); /* xor ebp, ebp */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if ((c->cf || c->zf)) goto L_00582a49; /* jbe 0x582a49 */
L_00582a5b:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x10u))); /* mov ecx, dword ptr [ebx + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + c->ebp * 4))); /* mov ecx, dword ptr [ecx + ebp*4] */
    (void)sub32(c, c->ecx, c->esi); /* cmp ecx, esi */
    if (c->zf) goto L_00582a84; /* je 0x582a84 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00582a6bu); f_005829a0(c); /* call 0x5829a0 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00582b20; /* jne 0x582b20 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov eax, dword ptr [ebx + 4] */
    c->ebp = (uint32_t)(inc32(c, c->ebp)); /* inc ebp */
    (void)sub32(c, c->ebp, c->eax); /* cmp ebp, eax */
    if (c->cf) goto L_00582a5b; /* jb 0x582a5b */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
L_00582a84:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (c->zf) goto L_00582a94; /* je 0x582a94 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00582a91u); f_00581050(c); /* call 0x581050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00582a94:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0xc], edi */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (c->zf) goto L_00582acc; /* je 0x582acc */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->cf || c->zf)) goto L_00582abe; /* jbe 0x582abe */
L_00582aa5:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov edx, dword ptr [esi + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + c->edi * 4))); /* mov ecx, dword ptr [edx + edi*4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00582ab6; /* je 0x582ab6 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x00582ab6u); f_00583e80(c); /* call 0x583e80 */
L_00582ab6:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_00582aa5; /* jb 0x582aa5 */
L_00582abe:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00582ac7u); f_00581050(c); /* call 0x581050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
L_00582acc:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0x10], edi */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 4], edi */
    PUSH32(c, 0x00582ad8u); f_00581050(c); /* call 0x581050 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov ecx, dword ptr [ebx + 4] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    c->eax = (uint32_t)(c->ebp); /* mov eax, ebp */
    (void)sub32(c, c->ebp, c->ecx); /* cmp ebp, ecx */
    if (!c->cf) goto L_00582af8; /* jae 0x582af8 */
L_00582ae5:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x10u))); /* mov ecx, dword ptr [ebx + 0x10] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + c->eax * 4))); /* mov edx, dword ptr [ecx + eax*4] */
    W32((uint32_t)(c->ecx + c->eax * 4 + 0xfffffffcu), (uint32_t)(c->edx)); /* mov dword ptr [ecx + eax*4 - 4], edx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov ecx, dword ptr [ebx + 4] */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (c->cf) goto L_00582ae5; /* jb 0x582ae5 */
L_00582af8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov eax, dword ptr [ebx + 4] */
    { uint32_t v_ = 0x123u; PUSH32(c, v_); } /* push 0x123 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    { uint32_t v_ = 0x58e0e8u; PUSH32(c, v_); } /* push 0x1000e0e8 */
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 4], eax */
    c->edx = (uint32_t)((uint32_t)(c->eax * 4)); /* lea edx, [eax*4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x10u))); /* mov eax, dword ptr [ebx + 0x10] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00582b1au); f_00581070(c); /* call 0x581070 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    W32((uint32_t)(c->ebx + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 0x10], eax */
L_00582b20:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
}

void f_00582b30(CPU *c) { /* FUN_10002b30 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x148u)); /* sub esp, 0x148 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x40u))); /* mov eax, dword ptr [ebx + 0x40] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x10], ebx */
    if (c->zf) goto L_00582f32; /* je 0x582f32 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x15cu))); /* mov eax, dword ptr [esp + 0x15c] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x2cu)); /* lea ecx, [esp + 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x58e1a8u; PUSH32(c, v_); } /* push 0x1000e1a8 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00582b62u); f_00584b54(c); /* call 0x584b54 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebx + 0x40u))); /* mov esi, dword ptr [ebx + 0x40] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00582f32; /* je 0x582f32 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x2cu))); /* mov al, byte ptr [esp + 0x2c] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00582c25; /* je 0x582c25 */
L_00582b7e:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + c->edi + 0x2cu))); /* mov al, byte ptr [esp + edi + 0x2c] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00582c17; /* je 0x582c17 */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x2eu); /* cmp al, 0x2e */
    if (c->zf) goto L_00582b91; /* je 0x582b91 */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_00582b7e; /* jmp 0x582b7e */
L_00582b91:;
    (void)sub32(c, c->edi, (uint32_t)0x104u); /* cmp edi, 0x104 */
    if (!c->cf) goto L_00582bc1; /* jae 0x582bc1 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x2cu)); /* lea edx, [esp + 0x2c] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x58u)); /* lea eax, [esp + 0x58] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00582ba9u); f_00584bb0(c); /* call 0x584bb0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x54u)); /* lea ecx, [esp + 0x54] */
    W8((uint32_t)(c->esp + c->edi + 0x54u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esp + edi + 0x54], 0 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00582bbdu); f_00582490(c); /* call 0x582490 */
    c->ebp = (uint32_t)(c->eax); /* mov ebp, eax */
    goto L_00582c00; /* jmp 0x582c00 */
L_00582bc1:;
    { uint32_t v_ = 0x182u; PUSH32(c, v_); } /* push 0x182 */
    c->edx = (uint32_t)((uint32_t)(c->edi + 0x1u)); /* lea edx, [edi + 1] */
    { uint32_t v_ = 0x58e0e8u; PUSH32(c, v_); } /* push 0x1000e0e8 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00582bd4u); f_00581030(c); /* call 0x581030 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x38u)); /* lea eax, [esp + 0x38] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00582be2u); f_00584bb0(c); /* call 0x584bb0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    W8((uint32_t)(c->ebx + c->edi), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [ebx + edi], 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00582bf1u); f_00582490(c); /* call 0x582490 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebp = (uint32_t)(c->eax); /* mov ebp, eax */
    PUSH32(c, 0x00582bf9u); f_00581050(c); /* call 0x581050 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ebx, dword ptr [esp + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00582c00:;
    (void)logic32(c, (uint32_t)(c->ebp & c->ebp)); /* test ebp, ebp */
    if (c->zf) goto L_00582f32; /* je 0x582f32 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + c->edi + 0x2du)); /* lea ecx, [esp + edi + 0x2d] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00582c15u); f_00583950(c); /* call 0x583950 */
    goto L_00582c23; /* jmp 0x582c23 */
L_00582c17:;
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x2cu)); /* lea edx, [esp + 0x2c] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00582c23u); f_00582490(c); /* call 0x582490 */
L_00582c23:;
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_00582c25:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00582f32; /* je 0x582f32 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->cf || c->zf)) goto L_00582f32; /* jbe 0x582f32 */
L_00582c3a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->edi * 4))); /* mov eax, dword ptr [eax + edi*4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x00582c4bu); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x58e1a4u; PUSH32(c, v_); } /* push 0x1000e1a4 */
    PUSH32(c, 0x00582c56u); f_0058c990(c); /* call 0x58c990 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00582c72; /* je 0x582c72 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_00582c3a; /* jb 0x582c3a */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x148u)); /* add esp, 0x148 */
    c->esp += 8; return; /* ret 4 */
L_00582c72:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + c->edi * 4))); /* mov edx, dword ptr [ecx + edi*4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0xcu))); /* mov eax, dword ptr [edx + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00582f32; /* je 0x582f32 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->cf || c->zf)) goto L_00582f32; /* jbe 0x582f32 */
L_00582c90:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->edi * 4))); /* mov eax, dword ptr [eax + edi*4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x00582ca1u); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x58e19cu; PUSH32(c, v_); } /* push 0x1000e19c */
    PUSH32(c, 0x00582cacu); f_0058c990(c); /* call 0x58c990 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00582cc8; /* je 0x582cc8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_00582c90; /* jb 0x582c90 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x148u)); /* add esp, 0x148 */
    c->esp += 8; return; /* ret 4 */
L_00582cc8:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + c->edi * 4))); /* mov edx, dword ptr [ecx + edi*4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0xcu))); /* mov eax, dword ptr [edx + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00582f32; /* je 0x582f32 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->cf || c->zf)) goto L_00582f32; /* jbe 0x582f32 */
L_00582ce6:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->edi * 4))); /* mov eax, dword ptr [eax + edi*4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x00582cf7u); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x58e198u; PUSH32(c, v_); } /* push 0x1000e198 */
    PUSH32(c, 0x00582d02u); f_0058c990(c); /* call 0x58c990 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00582d1e; /* je 0x582d1e */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_00582ce6; /* jb 0x582ce6 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x148u)); /* add esp, 0x148 */
    c->esp += 8; return; /* ret 4 */
L_00582d1e:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + c->edi * 4))); /* mov edx, dword ptr [ecx + edi*4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0xcu))); /* mov eax, dword ptr [edx + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00582f32; /* je 0x582f32 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->cf || c->zf)) goto L_00582f32; /* jbe 0x582f32 */
L_00582d3c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->edi * 4))); /* mov eax, dword ptr [eax + edi*4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x00582d4du); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x58e194u; PUSH32(c, v_); } /* push 0x1000e194 */
    PUSH32(c, 0x00582d58u); f_0058c990(c); /* call 0x58c990 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00582d74; /* je 0x582d74 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_00582d3c; /* jb 0x582d3c */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x148u)); /* add esp, 0x148 */
    c->esp += 8; return; /* ret 4 */
L_00582d74:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + c->edi * 4))); /* mov edx, dword ptr [ecx + edi*4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0xcu))); /* mov eax, dword ptr [edx + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00582f32; /* je 0x582f32 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->cf || c->zf)) goto L_00582f32; /* jbe 0x582f32 */
L_00582d92:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->edi * 4))); /* mov eax, dword ptr [eax + edi*4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x00582da3u); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x58e190u; PUSH32(c, v_); } /* push 0x1000e190 */
    PUSH32(c, 0x00582daeu); f_0058c990(c); /* call 0x58c990 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00582dca; /* je 0x582dca */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_00582d92; /* jb 0x582d92 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x148u)); /* add esp, 0x148 */
    c->esp += 8; return; /* ret 4 */
L_00582dca:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + c->edi * 4))); /* mov edx, dword ptr [ecx + edi*4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0xcu))); /* mov eax, dword ptr [edx + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00582f32; /* je 0x582f32 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->cf || c->zf)) goto L_00582f32; /* jbe 0x582f32 */
L_00582de8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->edi * 4))); /* mov eax, dword ptr [eax + edi*4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x00582df9u); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x58e18cu; PUSH32(c, v_); } /* push 0x1000e18c */
    PUSH32(c, 0x00582e04u); f_0058c990(c); /* call 0x58c990 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00582e20; /* je 0x582e20 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_00582de8; /* jb 0x582de8 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x148u)); /* add esp, 0x148 */
    c->esp += 8; return; /* ret 4 */
L_00582e20:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + c->edi * 4))); /* mov edx, dword ptr [ecx + edi*4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0xcu))); /* mov eax, dword ptr [edx + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00582f32; /* je 0x582f32 */
    { uint32_t v_ = 0x58e188u; PUSH32(c, v_); } /* push 0x1000e188 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00582e3du); f_00582f40(c); /* call 0x582f40 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00582f32; /* je 0x582f32 */
    { uint32_t v_ = 0x58e180u; PUSH32(c, v_); } /* push 0x1000e180 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00582e51u); f_00582f40(c); /* call 0x582f40 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00582f32; /* je 0x582f32 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x58e1a4u; PUSH32(c, v_); } /* push 0x1000e1a4 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00582e67u); f_00582fa0(c); /* call 0x582fa0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x58e19cu; PUSH32(c, v_); } /* push 0x1000e19c */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    PUSH32(c, 0x00582e77u); f_00583020(c); /* call 0x583020 */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x58e198u; PUSH32(c, v_); } /* push 0x1000e198 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00582e89u); f_00583020(c); /* call 0x583020 */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x58e194u; PUSH32(c, v_); } /* push 0x1000e194 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00582e9bu); f_00583020(c); /* call 0x583020 */
    WF32((uint32_t)(c->esp + 0x28u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x28] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x58e190u; PUSH32(c, v_); } /* push 0x1000e190 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00582eadu); f_00583020(c); /* call 0x583020 */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x58e18cu; PUSH32(c, v_); } /* push 0x1000e18c */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00582ebfu); f_00583020(c); /* call 0x583020 */
    WF32((uint32_t)(c->esp + 0x20u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x20] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x58e188u; PUSH32(c, v_); } /* push 0x1000e188 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00582ed1u); f_00583020(c); /* call 0x583020 */
    WF32((uint32_t)(c->esp + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1c] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x58e180u; PUSH32(c, v_); } /* push 0x1000e180 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00582ee3u); f_00583020(c); /* call 0x583020 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov ecx, dword ptr [esp + 0x20] */
    WF32((uint32_t)(c->esp + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x24] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov edx, dword ptr [esp + 0x1c] */
    W32((uint32_t)(c->esp + 0x3cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x3c], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov eax, dword ptr [esp + 0x24] */
    W32((uint32_t)(c->esp + 0x40u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x40], ecx */
    W32((uint32_t)(c->esp + 0x44u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x44], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov edx, dword ptr [esp + 0x28] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x3cu)); /* lea ecx, [esp + 0x3c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov ecx, dword ptr [esp + 0x20] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x5cu)); /* lea ecx, [esp + 0x5c] */
    PUSH32(c, 0x00582f21u); f_00583f20(c); /* call 0x583f20 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x164u))); /* mov edx, dword ptr [esp + 0x164] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    PUSH32(c, 0x00582f32u); f_00581880(c); /* call 0x581880 */
L_00582f32:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x148u)); /* add esp, 0x148 */
    c->esp += 8; return; /* ret 4 */
}

void f_00582f40(CPU *c) { /* FUN_10002f40 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ebx, dword ptr [esp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    if (c->zf) goto L_00582f7d; /* je 0x582f7d */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov eax, dword ptr [edi + 4] */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->cf || c->zf)) goto L_00582f7d; /* jbe 0x582f7d */
L_00582f56:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x10u))); /* mov eax, dword ptr [edi + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 4))); /* mov eax, dword ptr [eax + esi*4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x00582f67u); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00582f6eu); f_0058c990(c); /* call 0x58c990 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00582f85; /* je 0x582f85 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov eax, dword ptr [edi + 4] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if (c->cf) goto L_00582f56; /* jb 0x582f56 */
L_00582f7d:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
L_00582f85:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x10u))); /* mov ecx, dword ptr [edi + 0x10] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + c->esi * 4))); /* mov edx, dword ptr [ecx + esi*4] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0xcu))); /* mov eax, dword ptr [edx + 0xc] */
    c->esp += 8; return; /* ret 4 */
}

void f_00582fa0(CPU *c) { /* FUN_10002fa0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ebx, dword ptr [esp + 8] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ebp, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    if (c->zf) goto L_00583008; /* je 0x583008 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->cf || c->zf)) goto L_00582fe2; /* jbe 0x582fe2 */
L_00582fbb:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->edi * 4))); /* mov eax, dword ptr [eax + edi*4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x00582fccu); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00582fd3u); f_0058c990(c); /* call 0x58c990 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00582feb; /* je 0x582feb */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_00582fbb; /* jb 0x582fbb */
L_00582fe2:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)(c->ebp); /* mov eax, ebp */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 12; return; /* ret 8 */
L_00582feb:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + c->edi * 4))); /* mov edx, dword ptr [ecx + edi*4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0xcu))); /* mov eax, dword ptr [edx + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00582fe2; /* je 0x582fe2 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00582ffeu); f_00584d20(c); /* call 0x584d20 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 12; return; /* ret 8 */
L_00583008:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00583011u); f_00584d20(c); /* call 0x584d20 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 12; return; /* ret 8 */
}

void f_00583020(CPU *c) { /* FUN_10003020 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ebx, dword ptr [esp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    if (c->zf) goto L_0058308b; /* je 0x58308b */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov eax, dword ptr [edi + 4] */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->cf || c->zf)) goto L_00583065; /* jbe 0x583065 */
L_0058303e:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x10u))); /* mov ecx, dword ptr [edi + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + c->esi * 4))); /* mov eax, dword ptr [ecx + esi*4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x0058304fu); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00583056u); f_0058c990(c); /* call 0x58c990 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0058306f; /* je 0x58306f */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov eax, dword ptr [edi + 4] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if (c->cf) goto L_0058303e; /* jb 0x58303e */
L_00583065:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 12; return; /* ret 8 */
L_0058306f:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x10u))); /* mov ecx, dword ptr [edi + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + c->esi * 4))); /* mov edx, dword ptr [ecx + esi*4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0xcu))); /* mov eax, dword ptr [edx + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00583065; /* je 0x583065 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00583082u); f_00584dab(c); /* call 0x584dab */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 12; return; /* ret 8 */
L_0058308b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0xcu))); /* mov eax, dword ptr [edi + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00583094u); f_00584dab(c); /* call 0x584dab */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 12; return; /* ret 8 */
}

void f_005830a0(CPU *c) { /* FUN_100030a0 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x108u)); /* sub esp, 0x108 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x118u))); /* mov esi, dword ptr [esp + 0x118] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x10], ecx */
    if (!c->zf) goto L_005830c8; /* jne 0x5830c8 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x108u)); /* add esp, 0x108 */
    c->esp += 12; return; /* ret 8 */
L_005830c8:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x120u))); /* mov ebx, dword ptr [esp + 0x120] */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (!c->zf) goto L_005830e2; /* jne 0x5830e2 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x108u)); /* add esp, 0x108 */
    c->esp += 12; return; /* ret 8 */
L_005830e2:;
    c->ebp = (uint32_t)(logic32(c, 0)); /* xor ebp, ebp */
L_005830e4:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebx + c->ebp))); /* mov al, byte ptr [ebx + ebp] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00583294; /* je 0x583294 */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x2eu); /* cmp al, 0x2e */
    if (c->zf) goto L_005830f6; /* je 0x5830f6 */
    c->ebp = (uint32_t)(inc32(c, c->ebp)); /* inc ebp */
    goto L_005830e4; /* jmp 0x5830e4 */
L_005830f6:;
    (void)sub32(c, c->ebp, (uint32_t)0x104u); /* cmp ebp, 0x104 */
    if (!c->cf) goto L_005831b9; /* jae 0x5831b9 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x18u)); /* lea eax, [esp + 0x18] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0058310eu); f_00584bb0(c); /* call 0x584bb0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    W8((uint32_t)(c->esp + c->ebp + 0x14u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esp + ebp + 0x14], 0 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->cf || c->zf)) goto L_0058315a; /* jbe 0x58315a */
L_0058311f:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + c->edi * 4))); /* mov eax, dword ptr [ecx + edi*4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x00583130u); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea ecx, [esp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x0058313bu); f_0058c990(c); /* call 0x58c990 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0058314c; /* je 0x58314c */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_0058311f; /* jb 0x58311f */
    goto L_0058315a; /* jmp 0x58315a */
L_0058314c:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov edx, dword ptr [esi + 0x10] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->edx + c->edi * 4))); /* mov ebx, dword ptr [edx + edi*4] */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (!c->zf) goto L_00583269; /* jne 0x583269 */
L_0058315a:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea edx, [esp + 0x14] */
    { uint32_t v_ = 0x6217acu; PUSH32(c, v_); } /* push 0x100a17ac */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0xcu)); PUSH32(c, 0x0058316bu); call_indirect(c, t_); } /* call dword ptr [eax + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00583173u); f_00583b00(c); /* call 0x583b00 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->cf || c->zf)) goto L_005831a7; /* jbe 0x5831a7 */
L_0058317c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->edi * 4))); /* mov eax, dword ptr [eax + edi*4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x0058318du); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea ecx, [esp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00583198u); f_0058c990(c); /* call 0x58c990 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_005831ae; /* je 0x5831ae */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_0058317c; /* jb 0x58317c */
L_005831a7:;
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    goto L_00583269; /* jmp 0x583269 */
L_005831ae:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov edx, dword ptr [esi + 0x10] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->edx + c->edi * 4))); /* mov ebx, dword ptr [edx + edi*4] */
    goto L_00583269; /* jmp 0x583269 */
L_005831b9:;
    { uint32_t v_ = 0x148u; PUSH32(c, v_); } /* push 0x148 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x1u)); /* lea eax, [ebp + 1] */
    { uint32_t v_ = 0x58e0e8u; PUSH32(c, v_); } /* push 0x1000e0e8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x005831ccu); f_00581030(c); /* call 0x581030 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x005831d6u); f_00584bb0(c); /* call 0x584bb0 */
    W8((uint32_t)(c->edi + c->ebp), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [edi + ebp], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->cf || c->zf)) goto L_00583219; /* jbe 0x583219 */
L_005831e6:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + c->ebx * 4))); /* mov eax, dword ptr [ecx + ebx*4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x005831f7u); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x005831feu); f_0058c990(c); /* call 0x58c990 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0058320f; /* je 0x58320f */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    (void)sub32(c, c->ebx, c->eax); /* cmp ebx, eax */
    if (c->cf) goto L_005831e6; /* jb 0x5831e6 */
    goto L_00583219; /* jmp 0x583219 */
L_0058320f:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ecx + c->ebx * 4))); /* mov ebx, dword ptr [ecx + ebx*4] */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (!c->zf) goto L_00583260; /* jne 0x583260 */
L_00583219:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    { uint32_t v_ = 0x6217acu; PUSH32(c, v_); } /* push 0x100a17ac */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x00583226u); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x0058322eu); f_00583b00(c); /* call 0x583b00 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->cf || c->zf)) goto L_0058325e; /* jbe 0x58325e */
L_00583237:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->ebx * 4))); /* mov eax, dword ptr [eax + ebx*4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x00583248u); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x0058324fu); f_0058c990(c); /* call 0x58c990 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0058328c; /* je 0x58328c */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    (void)sub32(c, c->ebx, c->eax); /* cmp ebx, eax */
    if (c->cf) goto L_00583237; /* jb 0x583237 */
L_0058325e:;
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
L_00583260:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00583266u); f_00581050(c); /* call 0x581050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00583269:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x120u))); /* mov edx, dword ptr [esp + 0x120] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    c->eax = (uint32_t)((uint32_t)(c->edx + c->ebp + 0x1u)); /* lea eax, [edx + ebp + 1] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x0058327fu); f_005830a0(c); /* call 0x5830a0 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x108u)); /* add esp, 0x108 */
    c->esp += 12; return; /* ret 8 */
L_0058328c:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ecx + c->ebx * 4))); /* mov ebx, dword ptr [ecx + ebx*4] */
    goto L_00583260; /* jmp 0x583260 */
L_00583294:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->cf || c->zf)) goto L_005832d0; /* jbe 0x5832d0 */
L_0058329d:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + c->edi * 4))); /* mov eax, dword ptr [ecx + edi*4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x005832aeu); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x005832b5u); f_0058c990(c); /* call 0x58c990 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_005832c6; /* je 0x5832c6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_0058329d; /* jb 0x58329d */
    goto L_005832d0; /* jmp 0x5832d0 */
L_005832c6:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ecx + c->edi * 4))); /* mov edi, dword ptr [ecx + edi*4] */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (!c->zf) goto L_00583317; /* jne 0x583317 */
L_005832d0:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    { uint32_t v_ = 0x6217acu; PUSH32(c, v_); } /* push 0x100a17ac */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x005832ddu); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x005832e5u); f_00583b00(c); /* call 0x583b00 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->cf || c->zf)) goto L_00583315; /* jbe 0x583315 */
L_005832ee:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->edi * 4))); /* mov eax, dword ptr [eax + edi*4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x005832ffu); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00583306u); f_0058c990(c); /* call 0x58c990 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00583326; /* je 0x583326 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_005832ee; /* jb 0x5832ee */
L_00583315:;
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
L_00583317:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x108u)); /* add esp, 0x108 */
    c->esp += 12; return; /* ret 8 */
L_00583326:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ecx + c->edi * 4))); /* mov edi, dword ptr [ecx + edi*4] */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x108u)); /* add esp, 0x108 */
    c->esp += 12; return; /* ret 8 */
}

void f_00583340(CPU *c) { /* PTR_00583340 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x34u)); /* sub esp, 0x34 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 8], esi */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x92848u))); /* mov edx, dword ptr [esi + 0x92848] */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    W32((uint32_t)(c->esi + 0x92848u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x92848], edx */
    (void)sub32(c, c->eax, (uint32_t)0x100u); /* cmp eax, 0x100 */
    if ((c->sf != c->of)) goto L_0058336b; /* jl 0x58336b */
    W32((uint32_t)(c->esi + 0x92848u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 0x92848], 0 */
L_0058336b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x92848u))); /* mov eax, dword ptr [esi + 0x92848] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00583379u); f_00582660(c); /* call 0x582660 */
    c->ecx = (uint32_t)(R32((uint32_t)(0x591308u))); /* mov ecx, dword ptr [0x10011308] */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x24u)); /* lea eax, [esi + 0x24] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x64u)); PUSH32(c, 0x00583388u); call_indirect(c, t_); } /* call dword ptr [edx + 0x64] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_0058393d; /* je 0x58393d */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov ecx, dword ptr [esi + 0x20] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x30u)); /* lea eax, [esp + 0x30] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x34u)); /* lea eax, [esp + 0x34] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x2cu)); /* lea eax, [esp + 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x70u)); PUSH32(c, 0x005833a9u); call_indirect(c, t_); } /* call dword ptr [edx + 0x70] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x24u))); /* fld dword ptr [esp + 0x24] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->edi + 0x50u))); /* fsub dword ptr [edi + 0x50] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x28u))); /* fld dword ptr [esp + 0x28] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->edi + 0x54u))); /* fsub dword ptr [edi + 0x54] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x2cu))); /* fld dword ptr [esp + 0x2c] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->edi + 0x58u))); /* fsub dword ptr [edi + 0x58] */
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
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x58d1acu))); /* fcom dword ptr [0x1000d1ac] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x100u))); /* and eax, 0x100 */
    if (c->zf) goto L_0058393b; /* je 0x58393b */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x58d1a8u))); /* fmul dword ptr [0x1000d1a8] */
    ST(0) = FPRES(c, sqrt(ST(0))); /* fsqrt  */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0x58d184u))); /* fsub dword ptr [0x1000d184] */
    ST(0) = FPRES(c, ST(0) + ST(0)); /* fadd st(0), st(0) */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x58d190u))); /* fcom dword ptr [0x1000d190] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x41u)); /* test ah, 0x41 */
    if (PF(c)) goto L_0058340c; /* jp 0x58340c */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, (double)RF32((uint32_t)(0x58d190u))); /* fld dword ptr [0x1000d190] */
L_0058340c:;
    FPUSH(c, (double)RF32((uint32_t)(0x58d18cu))); /* fld dword ptr [0x1000d18c] */
    ST(0) = FPRES(c, ST(0) - ST(1)); /* fsub st(1) */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x58d1a4u))); /* fmul dword ptr [0x1000d1a4] */
    PUSH32(c, 0x00583421u); f_00584e04(c); /* call 0x584e04 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov ecx, dword ptr [esi + 0x20] */
    c->ebx = (uint32_t)(shl32(c, c->ebx, 8)); /* shl ebx, 8 */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | c->eax))); /* or ebx, eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    c->ebx = (uint32_t)(shl32(c, c->ebx, 8)); /* shl ebx, 8 */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | c->eax))); /* or ebx, eax */
    c->ebx = (uint32_t)(shl32(c, c->ebx, 8)); /* shl ebx, 8 */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | c->eax))); /* or ebx, eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x3cu; PUSH32(c, v_); } /* push 0x3c */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x12cu)); PUSH32(c, 0x00583442u); call_indirect(c, t_); } /* call dword ptr [edx + 0x12c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov ecx, dword ptr [esi + 0x20] */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x20u)); /* add edi, 0x20 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x100u; PUSH32(c, v_); } /* push 0x100 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x58u)); PUSH32(c, 0x00583453u); call_indirect(c, t_); } /* call dword ptr [eax + 0x58] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov ecx, dword ptr [esi + 0x20] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x3cu))); /* mov eax, dword ptr [esi + 0x3c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x7cu)); PUSH32(c, 0x00583461u); call_indirect(c, t_); } /* call dword ptr [edx + 0x7c] */
    c->ebx = (uint32_t)((uint32_t)(c->esi + 0x48u)); /* lea ebx, [esi + 0x48] */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)((uint32_t)0x100u)); /* mov dword ptr [esp + 0x20], 0x100 */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x1c], ebx */
L_00583470:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebx + 0xfffffffcu))); /* mov al, byte ptr [ebx - 4] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_005838db; /* je 0x5838db */
    FPUSH(c, (double)RF32((uint32_t)(c->ebx))); /* fld dword ptr [ebx] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x58d1a0u))); FPOP(c); /* fcomp dword ptr [0x1000d1a0] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x100u))); /* and eax, 0x100 */
    if (!c->zf) goto L_00583848; /* jne 0x583848 */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov edi, dword ptr [ebx + 4] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ebx + 0xfffffffeu))); /* mov ax, word ptr [ebx - 2] */
    W8((uint32_t)(c->ebx + 0xfffffffcu), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [ebx - 4], 0 */
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)((uint32_t)0xffffd8f0u)); /* mov dword ptr [ebx + 4], 0xffffd8f0 */
    W16((uint32_t)(c->ebx + 0xfffffffeu), (uint16_t)((uint16_t)0x0u)); /* mov word ptr [ebx - 2], 0 */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea ecx, [eax + eax*2] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x591304u))); /* mov al, byte ptr [0x10011304] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x28], edi */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x14], ecx */
    if (!c->zf) goto L_005834d6; /* jne 0x5834d6 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(((uint8_t)c->eax)); /* mov dl, al */
    { uint32_t v_ = 0x583cd0u; PUSH32(c, v_); } /* push 0x10003cd0 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->edx) | (uint8_t)0x1u))); /* or dl, 1 */
    W8((uint32_t)(0x591304u), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [0x10011304], dl */
    PUSH32(c, 0x005834d3u); f_00584a94(c); /* call 0x584a94 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_005834d6:;
    c->edx = (uint32_t)((uint32_t)0x5917a8u); /* mov edx, 0x100117a8 */
    c->ebp = (uint32_t)((uint32_t)(c->esi + 0x46u)); /* lea ebp, [esi + 0x46] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x18], edx */
L_005834e2:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffeu))); /* mov al, byte ptr [ebp - 2] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_0058353c; /* je 0x58353c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x6u))); /* mov eax, dword ptr [ebp + 6] */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea eax, [eax + eax*2] */
    c->ecx = (uint32_t)((uint32_t)(c->esi + c->eax * 8 + 0x2844u)); /* lea ecx, [esi + eax*8 + 0x2844] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ebp))); /* mov ax, word ptr [ebp] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea eax, [eax + eax*2] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_0058353c; /* jle 0x58353c */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->eax = (uint32_t)(sub32(c, c->eax, c->edx)); /* sub eax, edx */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x24], eax */
    goto L_00583513; /* jmp 0x583513 */
L_0058350f:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov eax, dword ptr [esp + 0x24] */
L_00583513:;
    c->esi = (uint32_t)((uint32_t)(c->eax + c->edx)); /* lea esi, [eax + edx] */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->edi = (uint32_t)(c->edx); /* mov edi, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ebp))); /* mov ax, word ptr [ebp] */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x18u)); /* add edx, 0x18 */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea ecx, [eax + eax*2] */
    (void)sub32(c, c->ebx, c->ecx); /* cmp ebx, ecx */
    if ((c->sf != c->of)) goto L_0058350f; /* jl 0x58350f */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov edx, dword ptr [esp + 0x18] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov edi, dword ptr [esp + 0x28] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
L_0058353c:;
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x900u)); /* add edx, 0x900 */
    c->ebp = (uint32_t)(add32(c, c->ebp, (uint32_t)0x28u)); /* add ebp, 0x28 */
    (void)sub32(c, c->edx, (uint32_t)0x6217a8u); /* cmp edx, 0x100a17a8 */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x18], edx */
    if ((c->sf != c->of)) goto L_005834e2; /* jl 0x5834e2 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x4cu)); /* lea ecx, [esi + 0x4c] */
    c->edx = (uint32_t)((uint32_t)0x100u); /* mov edx, 0x100 */
L_00583559:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0xfffffff8u))); /* mov al, byte ptr [ecx - 8] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_0058356c; /* je 0x58356c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if ((c->zf || c->sf != c->of)) goto L_0058356c; /* jle 0x58356c */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->esp + 0x14u)))); /* sub eax, dword ptr [esp + 0x14] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
L_0058356c:;
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x28u)); /* add ecx, 0x28 */
    c->edx = (uint32_t)(dec32(c, c->edx)); /* dec edx */
    if (!c->zf) goto L_00583559; /* jne 0x583559 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esi + 0x92844u))); /* mov ebx, dword ptr [esi + 0x92844] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->ebx = (uint32_t)(sub32(c, c->ebx, c->eax)); /* sub ebx, eax */
    c->ebx = (uint32_t)(sub32(c, c->ebx, c->edi)); /* sub ebx, edi */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if ((c->zf || c->sf != c->of)) goto L_005835b8; /* jle 0x5835b8 */
    c->eax = (uint32_t)(add32(c, c->eax, c->edi)); /* add eax, edi */
    c->ecx = (uint32_t)((uint32_t)(c->ebx + c->ebx * 2)); /* lea ecx, [ebx + ebx*2] */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 3)); /* shl ecx, 3 */
    c->edx = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea edx, [eax + eax*2] */
    c->eax = (uint32_t)((uint32_t)(c->edi + c->edi * 2)); /* lea eax, [edi + edi*2] */
    c->esi = (uint32_t)((uint32_t)(c->esi + c->edx * 8 + 0x2844u)); /* lea esi, [esi + edx*8 + 0x2844] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    c->edi = (uint32_t)((uint32_t)(c->edx + c->eax * 8 + 0x2844u)); /* lea edi, [edx + eax*8 + 0x2844] */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u))); /* and ecx, 3 */
    while (c->ecx) { W8(c->edi, R8(c->esi)); c->esi += (c->df ? -1 : 1); c->edi += (c->df ? -1 : 1); c->ecx--; } /* rep movsb byte ptr es:[edi], byte ptr [esi] */
    c->esi = (uint32_t)(c->edx); /* mov esi, edx */
L_005835b8:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x92844u))); /* mov ecx, dword ptr [esi + 0x92844] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    W32((uint32_t)(c->esi + 0x92844u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 0x92844], ecx */
    if (!c->sf) goto L_005835eb; /* jns 0x5835eb */
    c->eax = (uint32_t)(R32((uint32_t)(0x591280u))); /* mov eax, dword ptr [0x10011280] */
    { uint32_t v_ = 0x58e298u; PUSH32(c, v_); } /* push 0x1000e298 */
    { uint32_t v_ = 0x15cu; PUSH32(c, v_); } /* push 0x15c */
    { uint32_t v_ = 0x58e058u; PUSH32(c, v_); } /* push 0x1000e058 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x58e128u; PUSH32(c, v_); } /* push 0x1000e128 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x005835e7u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x005835eau, "int3"); /* int3  */
L_005835eb:;
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->ecx = (uint32_t)((uint32_t)0x3u); /* mov ecx, 3 */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)c->ecx; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x005835f3u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv ecx */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_0058361c; /* je 0x58361c */
    c->eax = (uint32_t)(R32((uint32_t)(0x591280u))); /* mov eax, dword ptr [0x10011280] */
    { uint32_t v_ = 0x58e28cu; PUSH32(c, v_); } /* push 0x1000e28c */
    { uint32_t v_ = 0x160u; PUSH32(c, v_); } /* push 0x160 */
    { uint32_t v_ = 0x58e058u; PUSH32(c, v_); } /* push 0x1000e058 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0x58e128u; PUSH32(c, v_); } /* push 0x1000e128 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00583618u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x0058361bu, "int3"); /* int3  */
L_0058361c:;
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x46u)); /* add esi, 0x46 */
    c->ebx = (uint32_t)((uint32_t)0x100u); /* mov ebx, 0x100 */
L_00583626:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0xfffffffeu))); /* mov al, byte ptr [esi - 2] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_0058366b; /* je 0x58366b */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x6u))); /* mov ecx, dword ptr [esi + 6] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->esi))); /* mov ax, word ptr [esi] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea eax, [eax + eax*2] */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    (void)sub32(c, c->ecx, R32((uint32_t)(c->edx + 0x92844u))); /* cmp ecx, dword ptr [edx + 0x92844] */
    if ((c->zf || c->sf != c->of)) goto L_0058366b; /* jle 0x58366b */
    c->eax = (uint32_t)(R32((uint32_t)(0x591280u))); /* mov eax, dword ptr [0x10011280] */
    { uint32_t v_ = 0x58e258u; PUSH32(c, v_); } /* push 0x1000e258 */
    { uint32_t v_ = 0x166u; PUSH32(c, v_); } /* push 0x166 */
    { uint32_t v_ = 0x58e058u; PUSH32(c, v_); } /* push 0x1000e058 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x58e128u; PUSH32(c, v_); } /* push 0x1000e128 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00583667u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x0058366au, "int3"); /* int3  */
L_0058366b:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x28u)); /* add esi, 0x28 */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->zf) goto L_00583626; /* jne 0x583626 */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
    (void)sub32(c, c->edi, R32((uint32_t)(c->esi + 0x92844u))); /* cmp edi, dword ptr [esi + 0x92844] */
    if (c->zf) goto L_005836a0; /* je 0x5836a0 */
    c->eax = (uint32_t)(R32((uint32_t)(0x591280u))); /* mov eax, dword ptr [0x10011280] */
    { uint32_t v_ = 0x58e248u; PUSH32(c, v_); } /* push 0x1000e248 */
    { uint32_t v_ = 0x168u; PUSH32(c, v_); } /* push 0x168 */
    { uint32_t v_ = 0x58e058u; PUSH32(c, v_); } /* push 0x1000e058 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0x58e128u; PUSH32(c, v_); } /* push 0x1000e128 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x0058369cu); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x0058369fu, "int3"); /* int3  */
L_005836a0:;
    c->edx = (uint32_t)((uint32_t)0x5917a8u); /* mov edx, 0x100117a8 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x46u)); /* lea eax, [esi + 0x46] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x18], edx */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
L_005836ae:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebx + 0xfffffffeu))); /* mov al, byte ptr [ebx - 2] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00583822; /* je 0x583822 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x6u))); /* mov eax, dword ptr [ebx + 6] */
    c->ebp = (uint32_t)(logic32(c, 0)); /* xor ebp, ebp */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea eax, [eax + eax*2] */
    c->ecx = (uint32_t)((uint32_t)(c->esi + c->eax * 8 + 0x2844u)); /* lea ecx, [esi + eax*8 + 0x2844] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ebx))); /* mov ax, word ptr [ebx] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea eax, [eax + eax*2] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_00583822; /* jle 0x583822 */
    c->edi = (uint32_t)((uint32_t)(c->edx + 0xcu)); /* lea edi, [edx + 0xc] */
    c->edx = (uint32_t)(sub32(c, c->edx, c->ecx)); /* sub edx, ecx */
    c->esi = (uint32_t)((uint32_t)(c->ecx + 0x4u)); /* lea esi, [ecx + 4] */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x28], edx */
L_005836e4:;
    FPUSH(c, (double)RF32((uint32_t)(c->edi + 0xfffffff4u))); /* fld dword ptr [edi - 0xc] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->esi + 0xfffffffcu))); FPOP(c); /* fcomp dword ptr [esi - 4] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x44u)); /* test ah, 0x44 */
    if (!PF(c)) goto L_00583714; /* jnp 0x583714 */
    c->eax = (uint32_t)(R32((uint32_t)(0x591280u))); /* mov eax, dword ptr [0x10011280] */
    { uint32_t v_ = 0x58e22cu; PUSH32(c, v_); } /* push 0x1000e22c */
    { uint32_t v_ = 0x170u; PUSH32(c, v_); } /* push 0x170 */
    { uint32_t v_ = 0x58e058u; PUSH32(c, v_); } /* push 0x1000e058 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x58e128u; PUSH32(c, v_); } /* push 0x1000e128 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00583710u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00583713u, "int3"); /* int3  */
L_00583714:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov edx, dword ptr [esp + 0x28] */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + c->esi))); /* fld dword ptr [edx + esi] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->esi))); FPOP(c); /* fcomp dword ptr [esi] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x44u)); /* test ah, 0x44 */
    if (!PF(c)) goto L_00583747; /* jnp 0x583747 */
    c->eax = (uint32_t)(R32((uint32_t)(0x591280u))); /* mov eax, dword ptr [0x10011280] */
    { uint32_t v_ = 0x58e210u; PUSH32(c, v_); } /* push 0x1000e210 */
    { uint32_t v_ = 0x171u; PUSH32(c, v_); } /* push 0x171 */
    { uint32_t v_ = 0x58e058u; PUSH32(c, v_); } /* push 0x1000e058 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x58e128u; PUSH32(c, v_); } /* push 0x1000e128 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00583743u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00583746u, "int3"); /* int3  */
L_00583747:;
    FPUSH(c, (double)RF32((uint32_t)(c->edi + 0xfffffffcu))); /* fld dword ptr [edi - 4] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->esi + 0x4u))); FPOP(c); /* fcomp dword ptr [esi + 4] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x44u)); /* test ah, 0x44 */
    if (!PF(c)) goto L_00583777; /* jnp 0x583777 */
    c->eax = (uint32_t)(R32((uint32_t)(0x591280u))); /* mov eax, dword ptr [0x10011280] */
    { uint32_t v_ = 0x58e1f4u; PUSH32(c, v_); } /* push 0x1000e1f4 */
    { uint32_t v_ = 0x172u; PUSH32(c, v_); } /* push 0x172 */
    { uint32_t v_ = 0x58e058u; PUSH32(c, v_); } /* push 0x1000e058 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0x58e128u; PUSH32(c, v_); } /* push 0x1000e128 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00583773u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00583776u, "int3"); /* int3  */
L_00583777:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ecx, dword ptr [esi + 8] */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (c->zf) goto L_005837a3; /* je 0x5837a3 */
    c->eax = (uint32_t)(R32((uint32_t)(0x591280u))); /* mov eax, dword ptr [0x10011280] */
    { uint32_t v_ = 0x58e1e0u; PUSH32(c, v_); } /* push 0x1000e1e0 */
    { uint32_t v_ = 0x173u; PUSH32(c, v_); } /* push 0x173 */
    { uint32_t v_ = 0x58e058u; PUSH32(c, v_); } /* push 0x1000e058 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x58e128u; PUSH32(c, v_); } /* push 0x1000e128 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x0058379fu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x005837a2u, "int3"); /* int3  */
L_005837a3:;
    FPUSH(c, (double)RF32((uint32_t)(c->edi + 0x4u))); /* fld dword ptr [edi + 4] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->esi + 0xcu))); FPOP(c); /* fcomp dword ptr [esi + 0xc] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x44u)); /* test ah, 0x44 */
    if (!PF(c)) goto L_005837d3; /* jnp 0x5837d3 */
    c->eax = (uint32_t)(R32((uint32_t)(0x591280u))); /* mov eax, dword ptr [0x10011280] */
    { uint32_t v_ = 0x58e1ccu; PUSH32(c, v_); } /* push 0x1000e1cc */
    { uint32_t v_ = 0x174u; PUSH32(c, v_); } /* push 0x174 */
    { uint32_t v_ = 0x58e058u; PUSH32(c, v_); } /* push 0x1000e058 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0x58e128u; PUSH32(c, v_); } /* push 0x1000e128 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x005837cfu); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x005837d2u, "int3"); /* int3  */
L_005837d3:;
    FPUSH(c, (double)RF32((uint32_t)(c->edi + 0x8u))); /* fld dword ptr [edi + 8] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->esi + 0x10u))); FPOP(c); /* fcomp dword ptr [esi + 0x10] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x44u)); /* test ah, 0x44 */
    if (!PF(c)) goto L_00583803; /* jnp 0x583803 */
    c->eax = (uint32_t)(R32((uint32_t)(0x591280u))); /* mov eax, dword ptr [0x10011280] */
    { uint32_t v_ = 0x58e1b8u; PUSH32(c, v_); } /* push 0x1000e1b8 */
    { uint32_t v_ = 0x175u; PUSH32(c, v_); } /* push 0x175 */
    { uint32_t v_ = 0x58e058u; PUSH32(c, v_); } /* push 0x1000e058 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x58e128u; PUSH32(c, v_); } /* push 0x1000e128 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x005837ffu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00583802u, "int3"); /* int3  */
L_00583803:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ebp = (uint32_t)(inc32(c, c->ebp)); /* inc ebp */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ebx))); /* mov ax, word ptr [ebx] */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x18u)); /* add edi, 0x18 */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x18u)); /* add esi, 0x18 */
    c->edx = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea edx, [eax + eax*2] */
    (void)sub32(c, c->ebp, c->edx); /* cmp ebp, edx */
    if ((c->sf != c->of)) goto L_005836e4; /* jl 0x5836e4 */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov edx, dword ptr [esp + 0x18] */
L_00583822:;
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x900u)); /* add edx, 0x900 */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x28u)); /* add ebx, 0x28 */
    (void)sub32(c, c->edx, (uint32_t)0x6217a8u); /* cmp edx, 0x100a17a8 */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x18], edx */
    if ((c->sf != c->of)) goto L_005836ae; /* jl 0x5836ae */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov ebx, dword ptr [esp + 0x1c] */
    goto L_005838db; /* jmp 0x5838db */
L_00583848:;
    FPUSH(c, (double)RF32((uint32_t)(c->ebx))); /* fld dword ptr [ebx] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x58d19cu))); /* fmul dword ptr [0x1000d19c] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0x58d184u))); /* fsub dword ptr [0x1000d184] */
    ST(0) = FPRES(c, ST(0) + ST(0)); /* fadd st(0), st(0) */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x58d190u))); /* fcom dword ptr [0x1000d190] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_0058386f; /* jp 0x58386f */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, (double)RF32((uint32_t)(0x58d190u))); /* fld dword ptr [0x1000d190] */
    goto L_00583886; /* jmp 0x583886 */
L_0058386f:;
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x58d18cu))); /* fcom dword ptr [0x1000d18c] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00583886; /* jne 0x583886 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, (double)RF32((uint32_t)(0x58d18cu))); /* fld dword ptr [0x1000d18c] */
L_00583886:;
    FPUSH(c, (double)RF32((uint32_t)(0x58d18cu))); /* fld dword ptr [0x1000d18c] */
    ST(0) = FPRES(c, ST(0) - ST(1)); /* fsub st(1) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x58d1a4u))); /* fmul dword ptr [0x1000d1a4] */
    PUSH32(c, 0x00583899u); f_00584e04(c); /* call 0x584e04 */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebx + 0xfffffffdu))); /* mov cl, byte ptr [ebx - 3] */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    if (c->zf) goto L_005838db; /* je 0x5838db */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx | (uint32_t)0xffffff00u))); /* or edx, 0xffffff00 */
    c->ecx = (c->ecx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ebx + 0xfffffffeu))); /* mov cx, word ptr [ebx - 2] */
    c->edx = (uint32_t)(shl32(c, c->edx, 8)); /* shl edx, 8 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx | c->eax))); /* or edx, eax */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea ecx, [ecx + ecx*2] */
    c->edx = (uint32_t)(shl32(c, c->edx, 8)); /* shl edx, 8 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->edx))); /* or eax, edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov edx, dword ptr [ebx + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    c->edx = (uint32_t)((uint32_t)(c->edx + c->edx * 2)); /* lea edx, [edx + edx*2] */
    c->edx = (uint32_t)((uint32_t)(c->esi + c->edx * 8 + 0x2844u)); /* lea edx, [esi + edx*8 + 0x2844] */
    if ((c->zf || c->sf != c->of)) goto L_005838db; /* jle 0x5838db */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0xcu)); /* add edx, 0xc */
L_005838d3:;
    W32((uint32_t)(c->edx), (uint32_t)(c->eax)); /* mov dword ptr [edx], eax */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x18u)); /* add edx, 0x18 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (!c->zf) goto L_005838d3; /* jne 0x5838d3 */
L_005838db:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov eax, dword ptr [esp + 0x20] */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x28u)); /* add ebx, 0x28 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x1c], ebx */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x20], eax */
    if (!c->zf) goto L_00583470; /* jne 0x583470 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x92844u))); /* mov edx, dword ptr [esi + 0x92844] */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    (void)sub32(c, c->edx, (uint32_t)0x3u); /* cmp edx, 3 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    if ((c->zf || c->sf != c->of)) goto L_0058393d; /* jle 0x58393d */
    c->eax = (uint32_t)((uint32_t)0x55555556u); /* mov eax, 0x55555556 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov ecx, dword ptr [esi + 0x20] */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)c->edx; c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = r_ != (int32_t)r_; } /* imul edx */
    c->edi = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edi, dword ptr [ecx] */
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x58e1b0u; PUSH32(c, v_); } /* push 0x1000e1b0 */
    c->eax = (uint32_t)(shr32(c, c->eax, 31)); /* shr eax, 0x1f */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x2844u)); /* add esi, 0x2844 */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x142u; PUSH32(c, v_); } /* push 0x142 */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t t_ = R32((uint32_t)(c->edi + 0xe8u)); PUSH32(c, 0x00583930u); call_indirect(c, t_); } /* call dword ptr [edi + 0xe8] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x34u)); /* add esp, 0x34 */
    c->esp += 8; return; /* ret 4 */
L_0058393b:;
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
L_0058393d:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x34u)); /* add esp, 0x34 */
    c->esp += 8; return; /* ret 4 */
}

void f_005836a0(CPU *c) { /* PTR_005836a0 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)((uint32_t)0x5917a8u); /* mov edx, 0x100117a8 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x46u)); /* lea eax, [esi + 0x46] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x18], edx */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
L_005836ae:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebx + 0xfffffffeu))); /* mov al, byte ptr [ebx - 2] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00583822; /* je 0x583822 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x6u))); /* mov eax, dword ptr [ebx + 6] */
    c->ebp = (uint32_t)(logic32(c, 0)); /* xor ebp, ebp */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea eax, [eax + eax*2] */
    c->ecx = (uint32_t)((uint32_t)(c->esi + c->eax * 8 + 0x2844u)); /* lea ecx, [esi + eax*8 + 0x2844] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ebx))); /* mov ax, word ptr [ebx] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea eax, [eax + eax*2] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_00583822; /* jle 0x583822 */
    c->edi = (uint32_t)((uint32_t)(c->edx + 0xcu)); /* lea edi, [edx + 0xc] */
    c->edx = (uint32_t)(sub32(c, c->edx, c->ecx)); /* sub edx, ecx */
    c->esi = (uint32_t)((uint32_t)(c->ecx + 0x4u)); /* lea esi, [ecx + 4] */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x28], edx */
L_005836e4:;
    FPUSH(c, (double)RF32((uint32_t)(c->edi + 0xfffffff4u))); /* fld dword ptr [edi - 0xc] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->esi + 0xfffffffcu))); FPOP(c); /* fcomp dword ptr [esi - 4] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x44u)); /* test ah, 0x44 */
    if (!PF(c)) goto L_00583714; /* jnp 0x583714 */
    c->eax = (uint32_t)(R32((uint32_t)(0x591280u))); /* mov eax, dword ptr [0x10011280] */
    { uint32_t v_ = 0x58e22cu; PUSH32(c, v_); } /* push 0x1000e22c */
    { uint32_t v_ = 0x170u; PUSH32(c, v_); } /* push 0x170 */
    { uint32_t v_ = 0x58e058u; PUSH32(c, v_); } /* push 0x1000e058 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x58e128u; PUSH32(c, v_); } /* push 0x1000e128 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00583710u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00583713u, "int3"); /* int3  */
L_00583714:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov edx, dword ptr [esp + 0x28] */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + c->esi))); /* fld dword ptr [edx + esi] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->esi))); FPOP(c); /* fcomp dword ptr [esi] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x44u)); /* test ah, 0x44 */
    if (!PF(c)) goto L_00583747; /* jnp 0x583747 */
    c->eax = (uint32_t)(R32((uint32_t)(0x591280u))); /* mov eax, dword ptr [0x10011280] */
    { uint32_t v_ = 0x58e210u; PUSH32(c, v_); } /* push 0x1000e210 */
    { uint32_t v_ = 0x171u; PUSH32(c, v_); } /* push 0x171 */
    { uint32_t v_ = 0x58e058u; PUSH32(c, v_); } /* push 0x1000e058 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x58e128u; PUSH32(c, v_); } /* push 0x1000e128 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00583743u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00583746u, "int3"); /* int3  */
L_00583747:;
    FPUSH(c, (double)RF32((uint32_t)(c->edi + 0xfffffffcu))); /* fld dword ptr [edi - 4] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->esi + 0x4u))); FPOP(c); /* fcomp dword ptr [esi + 4] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x44u)); /* test ah, 0x44 */
    if (!PF(c)) goto L_00583777; /* jnp 0x583777 */
    c->eax = (uint32_t)(R32((uint32_t)(0x591280u))); /* mov eax, dword ptr [0x10011280] */
    { uint32_t v_ = 0x58e1f4u; PUSH32(c, v_); } /* push 0x1000e1f4 */
    { uint32_t v_ = 0x172u; PUSH32(c, v_); } /* push 0x172 */
    { uint32_t v_ = 0x58e058u; PUSH32(c, v_); } /* push 0x1000e058 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0x58e128u; PUSH32(c, v_); } /* push 0x1000e128 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00583773u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00583776u, "int3"); /* int3  */
L_00583777:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ecx, dword ptr [esi + 8] */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (c->zf) goto L_005837a3; /* je 0x5837a3 */
    c->eax = (uint32_t)(R32((uint32_t)(0x591280u))); /* mov eax, dword ptr [0x10011280] */
    { uint32_t v_ = 0x58e1e0u; PUSH32(c, v_); } /* push 0x1000e1e0 */
    { uint32_t v_ = 0x173u; PUSH32(c, v_); } /* push 0x173 */
    { uint32_t v_ = 0x58e058u; PUSH32(c, v_); } /* push 0x1000e058 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x58e128u; PUSH32(c, v_); } /* push 0x1000e128 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x0058379fu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x005837a2u, "int3"); /* int3  */
L_005837a3:;
    FPUSH(c, (double)RF32((uint32_t)(c->edi + 0x4u))); /* fld dword ptr [edi + 4] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->esi + 0xcu))); FPOP(c); /* fcomp dword ptr [esi + 0xc] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x44u)); /* test ah, 0x44 */
    if (!PF(c)) goto L_005837d3; /* jnp 0x5837d3 */
    c->eax = (uint32_t)(R32((uint32_t)(0x591280u))); /* mov eax, dword ptr [0x10011280] */
    { uint32_t v_ = 0x58e1ccu; PUSH32(c, v_); } /* push 0x1000e1cc */
    { uint32_t v_ = 0x174u; PUSH32(c, v_); } /* push 0x174 */
    { uint32_t v_ = 0x58e058u; PUSH32(c, v_); } /* push 0x1000e058 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0x58e128u; PUSH32(c, v_); } /* push 0x1000e128 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x005837cfu); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x005837d2u, "int3"); /* int3  */
L_005837d3:;
    FPUSH(c, (double)RF32((uint32_t)(c->edi + 0x8u))); /* fld dword ptr [edi + 8] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->esi + 0x10u))); FPOP(c); /* fcomp dword ptr [esi + 0x10] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x44u)); /* test ah, 0x44 */
    if (!PF(c)) goto L_00583803; /* jnp 0x583803 */
    c->eax = (uint32_t)(R32((uint32_t)(0x591280u))); /* mov eax, dword ptr [0x10011280] */
    { uint32_t v_ = 0x58e1b8u; PUSH32(c, v_); } /* push 0x1000e1b8 */
    { uint32_t v_ = 0x175u; PUSH32(c, v_); } /* push 0x175 */
    { uint32_t v_ = 0x58e058u; PUSH32(c, v_); } /* push 0x1000e058 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x58e128u; PUSH32(c, v_); } /* push 0x1000e128 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x005837ffu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00583802u, "int3"); /* int3  */
L_00583803:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ebp = (uint32_t)(inc32(c, c->ebp)); /* inc ebp */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ebx))); /* mov ax, word ptr [ebx] */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x18u)); /* add edi, 0x18 */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x18u)); /* add esi, 0x18 */
    c->edx = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea edx, [eax + eax*2] */
    (void)sub32(c, c->ebp, c->edx); /* cmp ebp, edx */
    if ((c->sf != c->of)) goto L_005836e4; /* jl 0x5836e4 */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov edx, dword ptr [esp + 0x18] */
L_00583822:;
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x900u)); /* add edx, 0x900 */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x28u)); /* add ebx, 0x28 */
    (void)sub32(c, c->edx, (uint32_t)0x6217a8u); /* cmp edx, 0x100a17a8 */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x18], edx */
    if ((c->sf != c->of)) goto L_005836ae; /* jl 0x5836ae */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov ebx, dword ptr [esp + 0x1c] */
    goto L_005838db; /* jmp 0x5838db */
L_005838db:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov eax, dword ptr [esp + 0x20] */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x28u)); /* add ebx, 0x28 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x1c], ebx */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x20], eax */
    if (!c->zf) { jump_indirect(c, 0x00583470u, 0x005838ebu); return; } /* jne 0x583470 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x92844u))); /* mov edx, dword ptr [esi + 0x92844] */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    (void)sub32(c, c->edx, (uint32_t)0x3u); /* cmp edx, 3 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    if ((c->zf || c->sf != c->of)) goto L_0058393d; /* jle 0x58393d */
    c->eax = (uint32_t)((uint32_t)0x55555556u); /* mov eax, 0x55555556 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov ecx, dword ptr [esi + 0x20] */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)c->edx; c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = r_ != (int32_t)r_; } /* imul edx */
    c->edi = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edi, dword ptr [ecx] */
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x58e1b0u; PUSH32(c, v_); } /* push 0x1000e1b0 */
    c->eax = (uint32_t)(shr32(c, c->eax, 31)); /* shr eax, 0x1f */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x2844u)); /* add esi, 0x2844 */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x142u; PUSH32(c, v_); } /* push 0x142 */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t t_ = R32((uint32_t)(c->edi + 0xe8u)); PUSH32(c, 0x00583930u); call_indirect(c, t_); } /* call dword ptr [edi + 0xe8] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x34u)); /* add esp, 0x34 */
    c->esp += 8; return; /* ret 4 */
L_0058393d:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x34u)); /* add esp, 0x34 */
    c->esp += 8; return; /* ret 4 */
}

void f_00583950(CPU *c) { /* FUN_10003950 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x108u)); /* sub esp, 0x108 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x118u))); /* mov esi, dword ptr [esp + 0x118] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x10], ecx */
    if (c->zf) goto L_005839f0; /* je 0x5839f0 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x120u))); /* mov ebx, dword ptr [esp + 0x120] */
    c->ebp = (uint32_t)(logic32(c, 0)); /* xor ebp, ebp */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (c->zf) goto L_005839f0; /* je 0x5839f0 */
    (void)sub8(c, R8((uint32_t)(c->ebx)), (uint8_t)0x0u); /* cmp byte ptr [ebx], 0 */
    if (!c->zf) goto L_0058398e; /* jne 0x58398e */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x108u)); /* add esp, 0x108 */
    c->esp += 12; return; /* ret 8 */
L_0058398e:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebx + c->ebp))); /* mov al, byte ptr [ebx + ebp] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00583aa0; /* je 0x583aa0 */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x2eu); /* cmp al, 0x2e */
    if (c->zf) goto L_005839a0; /* je 0x5839a0 */
    c->ebp = (uint32_t)(inc32(c, c->ebp)); /* inc ebp */
    goto L_0058398e; /* jmp 0x58398e */
L_005839a0:;
    (void)sub32(c, c->ebp, (uint32_t)0x104u); /* cmp ebp, 0x104 */
    if (!c->cf) goto L_00583a07; /* jae 0x583a07 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x18u)); /* lea eax, [esp + 0x18] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x005839b4u); f_00584bb0(c); /* call 0x584bb0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    W8((uint32_t)(c->esp + c->ebp + 0x14u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esp + ebp + 0x14], 0 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->cf || c->zf)) goto L_005839f0; /* jbe 0x5839f0 */
L_005839c5:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + c->edi * 4))); /* mov eax, dword ptr [ecx + edi*4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x005839d6u); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea ecx, [esp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x005839e1u); f_0058c990(c); /* call 0x58c990 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_005839ff; /* je 0x5839ff */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_005839c5; /* jb 0x5839c5 */
L_005839f0:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x108u)); /* add esp, 0x108 */
    c->esp += 12; return; /* ret 8 */
L_005839ff:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov edx, dword ptr [esi + 0x10] */
    c->edi = (uint32_t)(R32((uint32_t)(c->edx + c->edi * 4))); /* mov edi, dword ptr [edx + edi*4] */
    goto L_00583a74; /* jmp 0x583a74 */
L_00583a07:;
    { uint32_t v_ = 0x182u; PUSH32(c, v_); } /* push 0x182 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x1u)); /* lea eax, [ebp + 1] */
    { uint32_t v_ = 0x58e0e8u; PUSH32(c, v_); } /* push 0x1000e0e8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00583a1au); f_00581030(c); /* call 0x581030 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x12cu))); /* mov ecx, dword ptr [esp + 0x12c] */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00583a2bu); f_00584bb0(c); /* call 0x584bb0 */
    W8((uint32_t)(c->ebx + c->ebp), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [ebx + ebp], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->cf || c->zf)) goto L_00583a62; /* jbe 0x583a62 */
L_00583a3b:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov edx, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + c->edi * 4))); /* mov eax, dword ptr [edx + edi*4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x00583a4cu); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00583a53u); f_0058c990(c); /* call 0x58c990 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00583a98; /* je 0x583a98 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_00583a3b; /* jb 0x583a3b */
L_00583a62:;
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
L_00583a64:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00583a6au); f_00581050(c); /* call 0x581050 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x124u))); /* mov ebx, dword ptr [esp + 0x124] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00583a74:;
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_005839f0; /* je 0x5839f0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    c->edx = (uint32_t)((uint32_t)(c->ebx + c->ebp + 0x1u)); /* lea edx, [ebx + ebp + 1] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00583a8bu); f_00583950(c); /* call 0x583950 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x108u)); /* add esp, 0x108 */
    c->esp += 12; return; /* ret 8 */
L_00583a98:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ecx + c->edi * 4))); /* mov edi, dword ptr [ecx + edi*4] */
    goto L_00583a64; /* jmp 0x583a64 */
L_00583aa0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->cf || c->zf)) goto L_005839f0; /* jbe 0x5839f0 */
L_00583aad:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->edi * 4))); /* mov eax, dword ptr [eax + edi*4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x00583abeu); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00583ac5u); f_0058c990(c); /* call 0x58c990 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00583ae3; /* je 0x583ae3 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_00583aad; /* jb 0x583aad */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x108u)); /* add esp, 0x108 */
    c->esp += 12; return; /* ret 8 */
L_00583ae3:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + c->edi * 4))); /* mov eax, dword ptr [ecx + edi*4] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x108u)); /* add esp, 0x108 */
    c->esp += 12; return; /* ret 8 */
}

void f_00583b00(CPU *c) { /* FUN_10003b00 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x58cbf7u; PUSH32(c, v_); } /* push 0x1000cbf7 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->ebp = (uint32_t)(logic32(c, 0)); /* xor ebp, ebp */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if ((c->cf || c->zf)) goto L_00583b41; /* jbe 0x583b41 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov edx, dword ptr [esi + 0x10] */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
L_00583b2c:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edi, dword ptr [ecx] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov ebx, dword ptr [esp + 0x24] */
    (void)sub32(c, R32((uint32_t)(c->edi + 0x8u)), c->ebx); /* cmp dword ptr [edi + 8], ebx */
    if (c->zf) goto L_00583ba4; /* je 0x583ba4 */
    c->ebp = (uint32_t)(inc32(c, c->ebp)); /* inc ebp */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    (void)sub32(c, c->ebp, c->eax); /* cmp ebp, eax */
    if (c->cf) goto L_00583b2c; /* jb 0x583b2c */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
L_00583b41:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov edx, dword ptr [esi + 0x10] */
    { uint32_t v_ = 0x1d4u; PUSH32(c, v_); } /* push 0x1d4 */
    c->ecx = (uint32_t)((uint32_t)(c->eax * 4 + 0x4u)); /* lea ecx, [eax*4 + 4] */
    { uint32_t v_ = 0x58e0e8u; PUSH32(c, v_); } /* push 0x1000e0e8 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00583b5cu); f_00581070(c); /* call 0x581070 */
    { uint32_t v_ = 0x1d6u; PUSH32(c, v_); } /* push 0x1d6 */
    { uint32_t v_ = 0x58e0e8u; PUSH32(c, v_); } /* push 0x1000e0e8 */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x10], eax */
    PUSH32(c, 0x00583b70u); f_00581030(c); /* call 0x581030 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x10], edi */
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x1c], ebx */
    if (c->zf) goto L_00583c1f; /* je 0x583c1f */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    W32((uint32_t)(c->edi + 0x10u), (uint32_t)(c->ebx)); /* mov dword ptr [edi + 0x10], ebx */
    W32((uint32_t)(c->edi), (uint32_t)(c->ecx)); /* mov dword ptr [edi], ecx */
    W32((uint32_t)(c->edi + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [edi + 4], ebx */
    W32((uint32_t)(c->edi + 0xcu), (uint32_t)(c->ebx)); /* mov dword ptr [edi + 0xc], ebx */
    W32((uint32_t)(c->edi + 0x14u), (uint32_t)(c->ebx)); /* mov dword ptr [edi + 0x14], ebx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = 0x58e2a4u; PUSH32(c, v_); } /* push 0x1000e2a4 */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0xcu)); PUSH32(c, 0x00583b9fu); call_indirect(c, t_); } /* call dword ptr [eax + 0xc] */
    W32((uint32_t)(c->edi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + 8], eax */
    goto L_00583c21; /* jmp 0x583c21 */
L_00583ba4:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov ebx, dword ptr [esp + 0x28] */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (c->zf) goto L_00583bf8; /* je 0x583bf8 */
    c->edi = (uint32_t)(c->ebx); /* mov edi, ebx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0xffffffffu))); /* or ecx, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = 0x1c5u; PUSH32(c, v_); } /* push 0x1c5 */
    while (c->ecx) { (void)sub8(c, ((uint8_t)c->eax), R8(c->edi)); c->edi += (c->df ? -1 : 1); c->ecx--; if (c->zf) break; } /* repne scasb al, byte ptr es:[edi] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + c->ebp * 4))); /* mov eax, dword ptr [edx + ebp*4] */
    { uint32_t v_ = 0x58e0e8u; PUSH32(c, v_); } /* push 0x1000e0e8 */
    c->ecx = (uint32_t)((uint32_t)~c->ecx); /* not ecx */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0xcu))); /* mov ecx, dword ptr [eax + 0xc] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00583bd0u); f_00581070(c); /* call 0x581070 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov edx, dword ptr [esi + 0x10] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + c->ebp * 4))); /* mov ecx, dword ptr [edx + ebp*4] */
    W32((uint32_t)(c->ecx + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 0xc], eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov edx, dword ptr [esi + 0x10] */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + c->ebp * 4))); /* mov eax, dword ptr [edx + ebp*4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0xcu))); /* mov edx, dword ptr [eax + 0xc] */
L_00583be7:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov al, byte ptr [ecx] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    W8((uint32_t)(c->edx), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edx], al */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00583be7; /* jne 0x583be7 */
    c->eax = (uint32_t)(c->ebp); /* mov eax, ebp */
    goto L_00583cae; /* jmp 0x583cae */
L_00583bf8:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + c->ebp * 4))); /* mov ecx, dword ptr [edx + ebp*4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov eax, dword ptr [ecx + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00583c0b; /* je 0x583c0b */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00583c08u); f_00581050(c); /* call 0x581050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00583c0b:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov edx, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + c->ebp * 4))); /* mov eax, dword ptr [edx + ebp*4] */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [eax + 0xc], 0 */
    c->eax = (uint32_t)(c->ebp); /* mov eax, ebp */
    goto L_00583cae; /* jmp 0x583cae */
L_00583c1f:;
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
L_00583c21:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov edx, dword ptr [esi + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov ebx, dword ptr [esp + 0x28] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0xffffffffu))); /* or ecx, 0xffffffff */
    W32((uint32_t)(c->eax + c->edx * 4), (uint32_t)(c->edi)); /* mov dword ptr [eax + edx*4], edi */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov edx, dword ptr [esi + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x1c], ecx */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + c->edx * 4))); /* mov edx, dword ptr [eax + edx*4] */
    W32((uint32_t)(c->edx + 0x14u), (uint32_t)(c->esi)); /* mov dword ptr [edx + 0x14], esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov edx, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + c->eax * 4))); /* mov eax, dword ptr [edx + eax*4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov edx, dword ptr [esp + 0x24] */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 8], edx */
    if (c->zf) goto L_00583c92; /* je 0x583c92 */
    c->edi = (uint32_t)(c->ebx); /* mov edi, ebx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    while (c->ecx) { (void)sub8(c, ((uint8_t)c->eax), R8(c->edi)); c->edi += (c->df ? -1 : 1); c->ecx--; if (c->zf) break; } /* repne scasb al, byte ptr es:[edi] */
    c->ecx = (uint32_t)((uint32_t)~c->ecx); /* not ecx */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    { uint32_t v_ = 0x1dcu; PUSH32(c, v_); } /* push 0x1dc */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    { uint32_t v_ = 0x58e0e8u; PUSH32(c, v_); } /* push 0x1000e0e8 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00583c6fu); f_00581030(c); /* call 0x581030 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + c->ebp * 4))); /* mov edx, dword ptr [ecx + ebp*4] */
    W32((uint32_t)(c->edx + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [edx + 0xc], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + c->ebp * 4))); /* mov edx, dword ptr [ecx + ebp*4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0xcu))); /* mov ecx, dword ptr [edx + 0xc] */
L_00583c86:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    W8((uint32_t)(c->ecx), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [ecx], dl */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (!c->zf) goto L_00583c86; /* jne 0x583c86 */
    goto L_00583ca2; /* jmp 0x583ca2 */
L_00583c92:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + c->eax * 4))); /* mov edx, dword ptr [ecx + eax*4] */
    W32((uint32_t)(c->edx + 0xcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [edx + 0xc], 0 */
L_00583ca2:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 4], eax */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0xffffffffu)); /* lea eax, [esi - 1] */
L_00583cae:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ecx, dword ptr [esp + 0x14] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 12; return; /* ret 8 */
}

void f_00583cd0(CPU *c) { /* PTR_00583cd0 */
    PREEMPT_POLL(c);
    c->esp += 4; return; /* ret  */
}

void f_00583ce0(CPU *c) { /* PTR_00583ce0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(0x591790u))); /* mov ecx, dword ptr [0x10011790] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    (void)sub32(c, c->ecx, (uint32_t)0x20u); /* cmp ecx, 0x20 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if ((c->sf != c->of)) goto L_00583cfc; /* jl 0x583cfc */
L_00583cf2:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    c->esp += 4; return; /* ret  */
L_00583cfc:;
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov edi, dword ptr [esp + 0x30] */
    (void)sub32(c, c->edi, (uint32_t)0x3u); /* cmp edi, 3 */
    if ((c->sf != c->of)) goto L_00583e73; /* jl 0x583e73 */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov esi, dword ptr [esp + 0x2c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi))); /* fld dword ptr [esi] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esi + 0x18u))); /* fsub dword ptr [esi + 0x18] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x4u))); /* fld dword ptr [esi + 4] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esi + 0x1cu))); /* fsub dword ptr [esi + 0x1c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x8u))); /* fld dword ptr [esi + 8] */
    c->edx = (uint32_t)((uint32_t)(c->esi + 0x18u)); /* lea edx, [esi + 0x18] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->edx + 0x8u))); /* fsub dword ptr [edx + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi))); /* fld dword ptr [esi] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esi + 0xcu))); /* fsub dword ptr [esi + 0xc] */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x4u))); /* fld dword ptr [esi + 4] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esi + 0x10u))); /* fsub dword ptr [esi + 0x10] */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x8u))); /* fld dword ptr [esi + 8] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esi + 0x14u))); /* fsub dword ptr [esi + 0x14] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) * ST(2)); /* fmul st(2) */
    { double v_ = ST(1); FPUSH(c, v_); } /* fld st(1) */
    ST(0) = FPRES(c, ST(0) * ST(4)); /* fmul st(4) */
    ST(1) = FPRES(c, ST(1) - ST(0)); FPOP(c); /* fsubp st(1) */
    WF32((uint32_t)(c->esp + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1c] */
    ST(0) = FPRES(c, ST(0) * ST(3)); /* fmul st(3) */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x10u))); /* fmul dword ptr [esp + 0x10] */
    ST(1) = FPRES(c, ST(1) - ST(0)); FPOP(c); /* fsubp st(1) */
    WF32((uint32_t)(c->esp + 0x20u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x20] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) * ST(3)); /* fmul st(3) */
    ST(1) = FPRES(c, ST(1) - ST(0)); FPOP(c); /* fsubp st(1) */
    ST(2) = ST(0); FPOP(c); /* fstp st(2) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, (double)RF32((uint32_t)(0x591300u))); /* fld dword ptr [0x10011300] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x20u))); /* fld dword ptr [esp + 0x20] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x5912fcu))); /* fmul dword ptr [0x100112fc] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(0x5912f8u))); /* fld dword ptr [0x100112f8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fmul dword ptr [esp + 0x1c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x58d190u))); FPOP(c); /* fcomp dword ptr [0x1000d190] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x100u))); /* and eax, 0x100 */
    if (!c->zf) goto L_00583da5; /* jne 0x583da5 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    c->esp += 4; return; /* ret  */
L_00583da5:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fld dword ptr [esp + 0x1c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x58d1b0u))); /* fmul dword ptr [0x1000d1b0] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x20u))); /* fld dword ptr [esp + 0x20] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x58d1b0u))); /* fmul dword ptr [0x1000d1b0] */
    { double t_ = ST(0); ST(0) = ST(2); ST(2) = t_; } /* fxch st(2) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x58d1b0u))); /* fmul dword ptr [0x1000d1b0] */
    (void)sub32(c, c->edi, (uint32_t)0x2u); /* cmp edi, 2 */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [esp + 0x2c], 2 */
    WF32((uint32_t)(c->esp + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x24] */
    FPUSH(c, (double)RF32((uint32_t)(0x5912e8u))); /* fld dword ptr [0x100112e8] */
    ST(0) = FPRES(c, ST(0) + ST(1)); /* fadd st(1) */
    WF32((uint32_t)(0x5912e8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [0x100112e8] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0x5912ecu))); /* fadd dword ptr [0x100112ec] */
    WF32((uint32_t)(0x5912ecu), (float)ST(0)); FPOP(c); /* fstp dword ptr [0x100112ec] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x24u))); /* fld dword ptr [esp + 0x24] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0x5912f0u))); /* fadd dword ptr [0x100112f0] */
    WF32((uint32_t)(0x5912f0u), (float)ST(0)); FPOP(c); /* fstp dword ptr [0x100112f0] */
    if ((c->zf || c->sf != c->of)) goto L_00583e73; /* jle 0x583e73 */
L_00583e00:;
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->ecx * 8)); /* lea eax, [ecx + ecx*8] */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->eax = (uint32_t)(shl32(c, c->eax, 2)); /* shl eax, 2 */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov ebp, dword ptr [ebx] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->edi = (uint32_t)((uint32_t)(c->eax + 0x591310u)); /* lea edi, [eax + 0x10011310] */
    (void)sub32(c, c->ecx, (uint32_t)0x20u); /* cmp ecx, 0x20 */
    W32((uint32_t)(c->edi), (uint32_t)(c->ebp)); /* mov dword ptr [edi], ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov ebp, dword ptr [ebx + 4] */
    W32((uint32_t)(c->edi + 0x4u), (uint32_t)(c->ebp)); /* mov dword ptr [edi + 4], ebp */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov ebx, dword ptr [ebx + 8] */
    W32((uint32_t)(c->edi + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [edi + 8], ebx */
    c->edi = (uint32_t)((uint32_t)(c->edx + 0xfffffff4u)); /* lea edi, [edx - 0xc] */
    c->ebx = (uint32_t)((uint32_t)(c->eax + 0x59131cu)); /* lea ebx, [eax + 0x1001131c] */
    c->eax = (uint32_t)((uint32_t)(c->eax + 0x591328u)); /* lea eax, [eax + 0x10011328] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->edi))); /* mov ebp, dword ptr [edi] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->ebp)); /* mov dword ptr [ebx], ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov ebp, dword ptr [edi + 4] */
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->ebp)); /* mov dword ptr [ebx + 4], ebp */
    c->edi = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov edi, dword ptr [edi + 8] */
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [ebx + 8], edi */
    c->edi = (uint32_t)(c->edx); /* mov edi, edx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->edi))); /* mov ebx, dword ptr [edi] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ebx)); /* mov dword ptr [eax], ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov ebx, dword ptr [edi + 4] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 4], ebx */
    c->edi = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov edi, dword ptr [edi + 8] */
    W32((uint32_t)(0x591790u), (uint32_t)(c->ecx)); /* mov dword ptr [0x10011790], ecx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [eax + 8], edi */
    if ((c->sf == c->of)) goto L_00583cf2; /* jge 0x583cf2 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov eax, dword ptr [esp + 0x2c] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov edi, dword ptr [esp + 0x30] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0xcu)); /* add edx, 0xc */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x2c], eax */
    if ((c->sf != c->of)) goto L_00583e00; /* jl 0x583e00 */
L_00583e73:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    c->esp += 4; return; /* ret  */
}

void f_00583e80(CPU *c) { /* FUN_10003e80 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00583e93; /* je 0x583e93 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00583e90u); f_00581050(c); /* call 0x581050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00583e93:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 0xc], 0 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00583ed1; /* je 0x583ed1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->cf || c->zf)) goto L_00583ec4; /* jbe 0x583ec4 */
L_00583eab:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + c->edi * 4))); /* mov ecx, dword ptr [eax + edi*4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00583ebc; /* je 0x583ebc */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x00583ebcu); f_00583e80(c); /* call 0x583e80 */
L_00583ebc:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_00583eab; /* jb 0x583eab */
L_00583ec4:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00583ecdu); f_00581050(c); /* call 0x581050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_00583ed1:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x8u))); /* mov al, byte ptr [esp + 8] */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 0x10], 0 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 4], 0 */
    if (c->zf) goto L_00583ef0; /* je 0x583ef0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00583eedu); f_00581050(c); /* call 0x581050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00583ef0:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00583f00(CPU *c) { /* FUN_10003f00 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 4], edx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    c->esp += 8; return; /* ret 4 */
}

void f_00583f20(CPU *c) { /* FUN_10003f20 */
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

void f_00583f40(CPU *c) { /* FUN_10003f40 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax))); /* fld dword ptr [eax] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->ecx))); /* fsub dword ptr [ecx] */
    WF32((uint32_t)(c->eax), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x4u))); /* fld dword ptr [eax + 4] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->ecx + 0x4u))); /* fsub dword ptr [ecx + 4] */
    WF32((uint32_t)(c->eax + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x8u))); /* fld dword ptr [eax + 8] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->ecx + 0x8u))); /* fsub dword ptr [ecx + 8] */
    WF32((uint32_t)(c->eax + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 8] */
    c->esp += 8; return; /* ret 4 */
}

void f_00583f70(CPU *c) { /* FUN_10003f70 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx))); /* fld dword ptr [ecx] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax))); /* fmul dword ptr [eax] */
    WF32((uint32_t)(c->eax), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x4u))); /* fld dword ptr [ecx + 4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x4u))); /* fmul dword ptr [eax + 4] */
    WF32((uint32_t)(c->eax + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x8u))); /* fld dword ptr [ecx + 8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x8u))); /* fmul dword ptr [eax + 8] */
    WF32((uint32_t)(c->eax + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 8] */
    c->esp += 8; return; /* ret 4 */
}

void f_00583fa0(CPU *c) { /* FUN_10003fa0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x8u))); /* fld dword ptr [eax + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x4u))); /* fld dword ptr [eax + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax))); /* fld dword ptr [eax] */
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
    c->esp += 4; return; /* ret  */
}

void f_00583fd0(CPU *c) { /* FUN_10003fd0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x8u))); /* fld dword ptr [eax + 8] */
    ST(0) = -ST(0); /* fchs  */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x4u))); /* fld dword ptr [eax + 4] */
    ST(0) = -ST(0); /* fchs  */
    FPUSH(c, (double)RF32((uint32_t)(c->eax))); /* fld dword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    ST(0) = -ST(0); /* fchs  */
    WF32((uint32_t)(c->eax), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax] */
    WF32((uint32_t)(c->eax + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 4] */
    WF32((uint32_t)(c->eax + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 8] */
    c->esp += 4; return; /* ret  */
}

void f_00583ff0(CPU *c) { /* FUN_10003ff0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xcu))); /* fld dword ptr [esp + 0xc] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x8u))); /* fmul dword ptr [eax + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xcu))); /* fld dword ptr [esp + 0xc] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x4u))); /* fmul dword ptr [eax + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xcu))); /* fld dword ptr [esp + 0xc] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax))); /* fmul dword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    WF32((uint32_t)(c->eax), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax] */
    WF32((uint32_t)(c->eax + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 4] */
    WF32((uint32_t)(c->eax + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 8] */
    c->esp += 4; return; /* ret  */
}

void f_00584020(CPU *c) { /* FUN_10004020 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx))); /* fld dword ptr [ecx] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x4u))); /* fmul dword ptr [eax + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x4u))); /* fld dword ptr [ecx + 4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax))); /* fmul dword ptr [eax] */
    ST(1) = FPRES(c, ST(1) - ST(0)); FPOP(c); /* fsubp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x8u))); /* fld dword ptr [ecx + 8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax))); /* fmul dword ptr [eax] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x8u))); /* fld dword ptr [eax + 8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ecx))); /* fmul dword ptr [ecx] */
    ST(1) = FPRES(c, ST(1) - ST(0)); FPOP(c); /* fsubp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x4u))); /* fld dword ptr [ecx + 4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x8u))); /* fmul dword ptr [eax + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x8u))); /* fld dword ptr [ecx + 8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x4u))); /* fmul dword ptr [eax + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    ST(1) = FPRES(c, ST(1) - ST(0)); FPOP(c); /* fsubp st(1) */
    WF32((uint32_t)(c->eax), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax] */
    WF32((uint32_t)(c->eax + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 4] */
    WF32((uint32_t)(c->eax + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 8] */
    c->esp += 4; return; /* ret  */
}

void f_00584060(CPU *c) { /* FUN_10004060 */
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

void f_00584080(CPU *c) { /* FUN_10004080 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x58d15cu)); /* mov dword ptr [eax], 0x1000d15c */
    c->ecx = (uint32_t)(R32((uint32_t)(0x591280u))); /* mov ecx, dword ptr [0x10011280] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x14u))); /* mov eax, dword ptr [eax + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x00584097u); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    c->esp += 4; return; /* ret  */
}

void f_005840a0(CPU *c) { /* PTR_005840a0 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    c->esp += 4; return; /* ret  */
}

void f_005840b0(CPU *c) { /* PTR_005840b0 */
    PREEMPT_POLL(c);
    c->esp += 8; return; /* ret 4 */
}

void f_005840c0(CPU *c) { /* PTR_005840c0 */
    PREEMPT_POLL(c);
    c->esp += 16; return; /* ret 0xc */
}

void f_005840d0(CPU *c) { /* PTR_005840d0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_005840e0(CPU *c) { /* PTR_005840e0 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    c->esp += 8; return; /* ret 4 */
}

void f_005840f0(CPU *c) { /* PTR_005840f0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 8; return; /* ret 4 */
}

void f_00584100(CPU *c) { /* FUN_10004100 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x14u))); /* mov edx, dword ptr [esi + 0x14] */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x58d15cu)); /* mov dword ptr [esi], 0x1000d15c */
    c->ecx = (uint32_t)(R32((uint32_t)(0x591280u))); /* mov ecx, dword ptr [0x10011280] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x00584118u); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00584128; /* je 0x584128 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00584125u); f_00581050(c); /* call 0x581050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00584128:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00584130(CPU *c) { /* PTR_00584130 */
    PREEMPT_POLL(c);
    c->esp += 4; return; /* ret  */
}

void f_00584140(CPU *c) { /* PTR_00584140 */
    PREEMPT_POLL(c);
    { uint32_t a_ = (uint32_t)(c->ecx + 0xcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ecx + 0xc] */
    c->esp += 4; return; /* ret  */
}

void f_00584150(CPU *c) { /* PTR_00584150 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov eax, dword ptr [ecx + 0xc] */
    c->esp += 4; return; /* ret  */
}

void f_00584160(CPU *c) { /* PTR_00584160 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx + 0xcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ecx + 0xc], 0 */
    c->esp += 4; return; /* ret  */
}

void f_00584170(CPU *c) { /* PTR_00584170 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    c->esp += 4; return; /* ret  */
}

void f_00584180(CPU *c) { /* PTR_00584180 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x4u))); /* mov al, byte ptr [esp + 4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x58d118u)); /* mov dword ptr [esi], 0x1000d118 */
    if (c->zf) goto L_0058419a; /* je 0x58419a */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00584197u); f_00581050(c); /* call 0x581050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_0058419a:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_005841a0(CPU *c) { /* FUN_100041a0 */
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

void f_00584220(CPU *c) { /* FUN_10004220 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x38u))); /* fld dword ptr [ecx + 0x38] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ecx + 0x18u))); /* fmul dword ptr [ecx + 0x18] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x34u))); /* fld dword ptr [ecx + 0x34] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ecx + 0x14u))); /* fmul dword ptr [ecx + 0x14] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0xc], ecx */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x30u))); /* fld dword ptr [ecx + 0x30] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ecx + 0x10u))); /* fmul dword ptr [ecx + 0x10] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x38u))); /* fld dword ptr [ecx + 0x38] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ecx + 0x28u))); /* fmul dword ptr [ecx + 0x28] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x34u))); /* fld dword ptr [ecx + 0x34] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ecx + 0x24u))); /* fmul dword ptr [ecx + 0x24] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x30u))); /* fld dword ptr [ecx + 0x30] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ecx + 0x20u))); /* fmul dword ptr [ecx + 0x20] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x38u))); /* fld dword ptr [ecx + 0x38] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ecx + 0x8u))); /* fmul dword ptr [ecx + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x34u))); /* fld dword ptr [ecx + 0x34] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ecx + 0x4u))); /* fmul dword ptr [ecx + 4] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x30u))); /* fld dword ptr [ecx + 0x30] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ecx))); /* fmul dword ptr [ecx] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = -ST(0); /* fchs  */
    WF32((uint32_t)(c->ecx + 0x30u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ecx + 0x30] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = -ST(0); /* fchs  */
    WF32((uint32_t)(c->ecx + 0x34u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ecx + 0x34] */
    ST(0) = -ST(0); /* fchs  */
    WF32((uint32_t)(c->ecx + 0x38u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ecx + 0x38] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
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
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_005842b0(CPU *c) { /* FUN_100042b0 */
    PREEMPT_POLL(c);
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x8u))); /* fld dword ptr [esp + 8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ecx + 0x10u))); /* fmul dword ptr [ecx + 0x10] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xcu))); /* fld dword ptr [esp + 0xc] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ecx + 0x20u))); /* fmul dword ptr [ecx + 0x20] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x4u))); /* fld dword ptr [esp + 4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ecx))); /* fmul dword ptr [ecx] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = -ST(0); /* fchs  */
    WF32((uint32_t)(c->ecx + 0x30u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ecx + 0x30] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x4u))); /* fld dword ptr [esp + 4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ecx + 0x4u))); /* fmul dword ptr [ecx + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x8u))); /* fld dword ptr [esp + 8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ecx + 0x14u))); /* fmul dword ptr [ecx + 0x14] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xcu))); /* fld dword ptr [esp + 0xc] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ecx + 0x24u))); /* fmul dword ptr [ecx + 0x24] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = -ST(0); /* fchs  */
    WF32((uint32_t)(c->ecx + 0x34u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ecx + 0x34] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x4u))); /* fld dword ptr [esp + 4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ecx + 0x8u))); /* fmul dword ptr [ecx + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x8u))); /* fld dword ptr [esp + 8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ecx + 0x18u))); /* fmul dword ptr [ecx + 0x18] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xcu))); /* fld dword ptr [esp + 0xc] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ecx + 0x28u))); /* fmul dword ptr [ecx + 0x28] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = -ST(0); /* fchs  */
    WF32((uint32_t)(c->ecx + 0x38u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ecx + 0x38] */
    c->esp += 16; return; /* ret 0xc */
}

void f_00584310(CPU *c) { /* FUN_10004310 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x1cu)); /* sub esp, 0x1c */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 8], esi */
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
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x34u))); /* fld dword ptr [esp + 0x34] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x28u))); /* fsub dword ptr [esp + 0x28] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x38u))); /* fld dword ptr [esp + 0x38] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x2cu))); /* fsub dword ptr [esp + 0x2c] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    WF32((uint32_t)(c->esp + 0x44u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x44] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x48u))); /* fld dword ptr [esp + 0x48] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x3cu))); /* fsub dword ptr [esp + 0x3c] */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x44u))); /* fld dword ptr [esp + 0x44] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x44u))); /* fmul dword ptr [esp + 0x44] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    { double v_ = ST(2); FPUSH(c, v_); } /* fld st(2) */
    ST(0) = FPRES(c, ST(0) * ST(3)); /* fmul st(3) */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x58d190u))); /* fcom dword ptr [0x1000d190] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x44u)); /* test ah, 0x44 */
    if (PF(c)) goto L_005843e2; /* jp 0x5843e2 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x3cu))); /* fld dword ptr [esp + 0x3c] */
    ST(0) = -ST(0); /* fchs  */
    WF32((uint32_t)(c->esp + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x38u))); /* fld dword ptr [esp + 0x38] */
    ST(0) = -ST(0); /* fchs  */
    WF32((uint32_t)(c->esp + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x34u))); /* fld dword ptr [esp + 0x34] */
    ST(0) = -ST(0); /* fchs  */
    WF32((uint32_t)(c->esp), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x4cu)); /* lea ecx, [esp + 0x4c] */
    PUSH32(c, 0x005843c1u); f_00583f20(c); /* call 0x583f20 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x40u))); /* mov eax, dword ptr [esp + 0x40] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x44u))); /* mov ecx, dword ptr [esp + 0x44] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x48u))); /* mov edx, dword ptr [esp + 0x48] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x30u)); /* add esi, 0x30 */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 4], ecx */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 8], edx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    c->esp += 40; return; /* ret 0x24 */
L_005843e2:;
    ST(0) = FPRES(c, sqrt(ST(0))); /* fsqrt  */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x24u)); /* lea ecx, [esp + 0x24] */
    ST(0) = FPRES(c, FDIV(c, (double)RF32((uint32_t)(0x58d18cu)), ST(0))); /* fdivr dword ptr [0x1000d18c] */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * ST(3)); /* fmul st(3) */
    WF32((uint32_t)(c->esp + 0x40u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x40] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x44u))); /* fld dword ptr [esp + 0x44] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF32((uint32_t)(c->esp + 0x44u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x44] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF32((uint32_t)(c->esp + 0x48u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x48] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x48u))); /* fld dword ptr [esp + 0x48] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x54u))); /* fmul dword ptr [esp + 0x54] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x40u))); /* fld dword ptr [esp + 0x40] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x4cu))); /* fmul dword ptr [esp + 0x4c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x44u))); /* fld dword ptr [esp + 0x44] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x50u))); /* fmul dword ptr [esp + 0x50] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x48u))); /* fld dword ptr [esp + 0x48] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF32((uint32_t)(c->esp + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x44u))); /* fld dword ptr [esp + 0x44] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF32((uint32_t)(c->esp + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x40u))); /* fmul dword ptr [esp + 0x40] */
    WF32((uint32_t)(c->esp), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp] */
    PUSH32(c, 0x00584446u); f_00583f20(c); /* call 0x583f20 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x40u))); /* fld dword ptr [esp + 0x40] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x18u))); /* fsub dword ptr [esp + 0x18] */
    WF32((uint32_t)(c->esp + 0x40u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x40] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x44u))); /* fld dword ptr [esp + 0x44] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fsub dword ptr [esp + 0x1c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x48u))); /* fld dword ptr [esp + 0x48] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x20u))); /* fsub dword ptr [esp + 0x20] */
    WF32((uint32_t)(c->esp + 0x48u), (float)ST(0)); /* fst dword ptr [esp + 0x48] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x48u))); /* fmul dword ptr [esp + 0x48] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x40u))); /* fld dword ptr [esp + 0x40] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x40u))); /* fmul dword ptr [esp + 0x40] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    { double v_ = ST(1); FPUSH(c, v_); } /* fld st(1) */
    ST(0) = FPRES(c, ST(0) * ST(2)); /* fmul st(2) */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x58d190u))); /* fcom dword ptr [0x1000d190] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x44u)); /* test ah, 0x44 */
    if (PF(c)) goto L_00584493; /* jp 0x584493 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    W32((uint32_t)(c->esp + 0x44u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [esp + 0x44], 0x3f800000 */
    goto L_005844b5; /* jmp 0x5844b5 */
L_00584493:;
    ST(0) = FPRES(c, sqrt(ST(0))); /* fsqrt  */
    ST(0) = FPRES(c, FDIV(c, (double)RF32((uint32_t)(0x58d18cu)), ST(0))); /* fdivr dword ptr [0x1000d18c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x40u))); /* fld dword ptr [esp + 0x40] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF32((uint32_t)(c->esp + 0x40u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x40] */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * ST(2)); /* fmul st(2) */
    WF32((uint32_t)(c->esp + 0x44u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x44] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x48u))); /* fmul dword ptr [esp + 0x48] */
    WF32((uint32_t)(c->esp + 0x48u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x48] */
L_005844b5:;
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x38u))); /* fld dword ptr [esp + 0x38] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x40u))); /* fmul dword ptr [esp + 0x40] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x34u))); /* fld dword ptr [esp + 0x34] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x44u))); /* fmul dword ptr [esp + 0x44] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x18u)); /* lea ecx, [esp + 0x18] */
    ST(1) = FPRES(c, ST(1) - ST(0)); FPOP(c); /* fsubp st(1) */
    WF32((uint32_t)(c->esp + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x40u))); /* fld dword ptr [esp + 0x40] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x54u))); /* fmul dword ptr [esp + 0x54] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x48u))); /* fld dword ptr [esp + 0x48] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x4cu))); /* fmul dword ptr [esp + 0x4c] */
    ST(1) = FPRES(c, ST(1) - ST(0)); FPOP(c); /* fsubp st(1) */
    WF32((uint32_t)(c->esp + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x48u))); /* fld dword ptr [esp + 0x48] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x50u))); /* fmul dword ptr [esp + 0x50] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x44u))); /* fld dword ptr [esp + 0x44] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x54u))); /* fmul dword ptr [esp + 0x54] */
    ST(1) = FPRES(c, ST(1) - ST(0)); FPOP(c); /* fsubp st(1) */
    WF32((uint32_t)(c->esp), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp] */
    PUSH32(c, 0x00584504u); f_00583f20(c); /* call 0x583f20 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x14u))); /* fmul dword ptr [esp + 0x14] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x10u))); /* fmul dword ptr [esp + 0x10] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xcu))); /* fld dword ptr [esp + 0xc] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xcu))); /* fmul dword ptr [esp + 0xc] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x58d190u))); /* fcom dword ptr [0x1000d190] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x44u)); /* test ah, 0x44 */
    if (!PF(c)) goto L_005845d9; /* jnp 0x5845d9 */
    ST(0) = FPRES(c, sqrt(ST(0))); /* fsqrt  */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x40u))); /* mov ecx, dword ptr [esp + 0x40] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x44u))); /* mov edx, dword ptr [esp + 0x44] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4cu))); /* mov ecx, dword ptr [esp + 0x4c] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 4], edx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x38u))); /* mov ecx, dword ptr [esp + 0x38] */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x10u)); /* lea eax, [esi + 0x10] */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    W32((uint32_t)(c->edx), (uint32_t)(c->ecx)); /* mov dword ptr [edx], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x3cu))); /* mov ecx, dword ptr [esp + 0x3c] */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [edx + 4], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x40u))); /* mov ecx, dword ptr [esp + 0x40] */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [edx + 8], ecx */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x20u)); /* lea ecx, [esi + 0x20] */
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    ST(0) = FPRES(c, FDIV(c, (double)RF32((uint32_t)(0x58d18cu)), ST(0))); /* fdivr dword ptr [0x1000d18c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); /* fst dword ptr [esp + 0x10] */
    { double v_ = ST(1); FPUSH(c, v_); } /* fld st(1) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x14u))); /* fmul dword ptr [esp + 0x14] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edi, dword ptr [esp + 0x10] */
    W32((uint32_t)(c->edx), (uint32_t)(c->edi)); /* mov dword ptr [edx], edi */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edi, dword ptr [esp + 0x14] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x18u))); /* fmul dword ptr [esp + 0x18] */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->edi)); /* mov dword ptr [edx + 4], edi */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov edi, dword ptr [esp + 0x18] */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [edx + 8], edi */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edx, dword ptr [esp + 0x14] */
    W32((uint32_t)(c->eax), (uint32_t)(c->edx)); /* mov dword ptr [eax], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x48u))); /* mov edx, dword ptr [esp + 0x48] */
    WF32((uint32_t)(c->esi), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi] */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    W32((uint32_t)(c->esi + 0x14u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x14], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x3cu))); /* mov edx, dword ptr [esp + 0x3c] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x44u))); /* mov ecx, dword ptr [esp + 0x44] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4cu))); /* mov eax, dword ptr [esp + 0x4c] */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 4], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x38u))); /* mov ecx, dword ptr [esp + 0x38] */
    W32((uint32_t)(c->esi + 0x24u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x24], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x40u))); /* mov eax, dword ptr [esp + 0x40] */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 8], ecx */
    W32((uint32_t)(c->esi + 0x18u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x18], edx */
    W32((uint32_t)(c->esi + 0x28u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x28], eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    goto L_005845db; /* jmp 0x5845db */
L_005845d9:;
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
L_005845db:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x2cu))); /* fld dword ptr [esp + 0x2c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x10u))); /* fmul dword ptr [esi + 0x10] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x30u))); /* fld dword ptr [esp + 0x30] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x20u))); /* fmul dword ptr [esi + 0x20] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x28u))); /* fld dword ptr [esp + 0x28] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi))); /* fmul dword ptr [esi] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = -ST(0); /* fchs  */
    WF32((uint32_t)(c->esi + 0x30u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x30] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x28u))); /* fld dword ptr [esp + 0x28] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x4u))); /* fmul dword ptr [esi + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x2cu))); /* fld dword ptr [esp + 0x2c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x14u))); /* fmul dword ptr [esi + 0x14] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x30u))); /* fld dword ptr [esp + 0x30] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x24u))); /* fmul dword ptr [esi + 0x24] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = -ST(0); /* fchs  */
    WF32((uint32_t)(c->esi + 0x34u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x34] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x28u))); /* fld dword ptr [esp + 0x28] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x8u))); /* fmul dword ptr [esi + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x2cu))); /* fld dword ptr [esp + 0x2c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x18u))); /* fmul dword ptr [esi + 0x18] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x30u))); /* fld dword ptr [esp + 0x30] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x28u))); /* fmul dword ptr [esi + 0x28] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = -ST(0); /* fchs  */
    WF32((uint32_t)(c->esi + 0x38u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x38] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    c->esp += 40; return; /* ret 0x24 */
}

void f_00584640(CPU *c) { /* FUN_10004640 */
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
    { uint32_t t_ = c->eax; switch (t_) {  default: jump_indirect(c, t_, 0x0058466bu); return; } } /* jmp eax */
}

void f_0058466d(CPU *c) { /* PTR_0058466d */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 12; return; /* ret 8 */
}

void f_00584674(CPU *c) { /* FUN_10004674 */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { guest_lock(); { uint32_t t0_ = R32((uint32_t)(c->esp)), t1_ = c->eax; W32((uint32_t)(c->esp), (uint32_t)(t1_)); c->eax = (uint32_t)(t0_); } guest_unlock(); } /* xchg dword ptr [esp], eax */
    { uint32_t t_ = c->eax; switch (t_) {  default: jump_indirect(c, t_, 0x00584679u); return; } } /* jmp eax */
}

void f_0058467b(CPU *c) { /* FUN_1000467b */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { guest_lock(); { uint32_t t0_ = R32((uint32_t)(c->esp)), t1_ = c->eax; W32((uint32_t)(c->esp), (uint32_t)(t1_)); c->eax = (uint32_t)(t0_); } guest_unlock(); } /* xchg dword ptr [esp], eax */
    { uint32_t t_ = c->eax; switch (t_) {  default: jump_indirect(c, t_, 0x00584680u); return; } } /* jmp eax */
}

void f_00584682(CPU *c) { /* FUN_10004682 */
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
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x5846aau)); /* mov dword ptr [ebp - 4], 0x100046aa */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x005846aau); f_0058cb70(c); /* call 0x58cb70 */
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

void f_005846aa(CPU *c) { /* PTR_005846aa */
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

void f_005846d1(CPU *c) { /* FUN_100046d1 */
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
    PUSH32(c, 0x005846f7u); f_00584fd4(c); /* call 0x584fd4 */
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

void f_00584707(CPU *c) { /* FUN_10004707 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x14u)); /* sub esp, 0x14 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffecu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x14], 0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)((uint32_t)0x58475bu)); /* mov dword ptr [ebp - 0x10], 0x1000475b */
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
    PUSH32(c, 0x0058474cu); f_005857f0(c); /* call 0x5857f0 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->eax)); /* mov dword ptr fs:[0], eax */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0058475b(CPU *c) { /* FUN_1000475b */
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
    PUSH32(c, 0x0058477bu); f_00584fd4(c); /* call 0x584fd4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00584780(CPU *c) { /* FUN_10004780 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x34u)); /* sub esp, 0x34 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffd8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x28], 0 */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)((uint32_t)0x584836u)); /* mov dword ptr [ebp - 0x24], 0x10004836 */
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
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)((uint32_t)0x584808u)); /* mov dword ptr [ebp - 0x10], 0x10004808 */
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
    PUSH32(c, 0x005847ffu); f_005858c1(c); /* call 0x5858c1 */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x68u)); PUSH32(c, 0x00584802u); call_indirect(c, t_); } /* call dword ptr [eax + 0x68] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffccu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x34], 0 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if (c->zf) goto L_00584825; /* je 0x584825 */
    c->ebx = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov ebx, dword ptr fs:[0] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ebx, dword ptr [ebp - 0x28] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ebx)); /* mov dword ptr fs:[0], ebx */
    goto L_0058482e; /* jmp 0x58482e */
L_00584825:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->eax)); /* mov dword ptr fs:[0], eax */
L_0058482e:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffccu))); /* mov eax, dword ptr [ebp - 0x34] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00584808(CPU *c) { /* PTR_00584808 */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if (c->zf) goto L_00584825; /* je 0x584825 */
    c->ebx = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov ebx, dword ptr fs:[0] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ebx, dword ptr [ebp - 0x28] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ebx)); /* mov dword ptr fs:[0], ebx */
    goto L_0058482e; /* jmp 0x58482e */
L_00584825:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->eax)); /* mov dword ptr fs:[0], eax */
L_0058482e:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffccu))); /* mov eax, dword ptr [ebp - 0x34] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00584836(CPU *c) { /* FUN_10004836 */
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
    if (c->zf) goto L_00584859; /* je 0x584859 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->eax + 0x24u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [eax + 0x24], 1 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_005848a6; /* jmp 0x5848a6 */
L_00584859:;
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
    PUSH32(c, 0x00584880u); f_00584fd4(c); /* call 0x584fd4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x24u)), (uint32_t)0x0u); /* cmp dword ptr [eax + 0x24], 0 */
    if (!c->zf) goto L_00584897; /* jne 0x584897 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x00584897u); f_00584682(c); /* call 0x584682 */
L_00584897:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ebx, dword ptr [ebp + 0xc] */
    c->esp = (uint32_t)(R32((uint32_t)(c->ebx + 0x1cu))); /* mov esp, dword ptr [ebx + 0x1c] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ebx + 0x20u))); /* mov ebp, dword ptr [ebx + 0x20] */
    { uint32_t t_ = R32((uint32_t)(c->ebx + 0x18u)); switch (t_) {  default: jump_indirect(c, t_, 0x005848a0u); return; } } /* jmp dword ptr [ebx + 0x18] */
L_005848a6:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_005848ab(CPU *c) { /* FUN_100048ab */
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
    if ((c->sf != c->of)) goto L_00584902; /* jl 0x584902 */
L_005848c9:;
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (!c->zf) goto L_005848d3; /* jne 0x5848d3 */
    PUSH32(c, 0x005848d3u); f_00585a29(c); /* call 0x585a29 */
L_005848d3:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi * 4)); /* lea eax, [esi + esi*4] */
    (void)sub32(c, R32((uint32_t)(c->ebx + c->eax * 4 + 0x4u)), c->ecx); /* cmp dword ptr [ebx + eax*4 + 4], ecx */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->eax * 4)); /* lea eax, [ebx + eax*4] */
    if ((c->sf == c->of)) goto L_005848e8; /* jge 0x5848e8 */
    (void)sub32(c, c->ecx, R32((uint32_t)(c->eax + 0x8u))); /* cmp ecx, dword ptr [eax + 8] */
    if ((c->zf || c->sf != c->of)) goto L_005848ed; /* jle 0x5848ed */
L_005848e8:;
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (!c->zf) goto L_005848f9; /* jne 0x5848f9 */
L_005848ed:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
L_005848f9:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    if ((c->sf == c->of)) goto L_005848c9; /* jge 0x5848c9 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
L_00584902:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov ecx, dword ptr [ebp + 0x14] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    W32((uint32_t)(c->ecx), (uint32_t)(c->esi)); /* mov dword ptr [ecx], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov ecx, dword ptr [ebp + 0x18] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    (void)sub32(c, c->eax, R32((uint32_t)(c->edi + 0xcu))); /* cmp eax, dword ptr [edi + 0xc] */
    if ((!c->cf && !c->zf)) goto L_00584916; /* ja 0x584916 */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if ((c->cf || c->zf)) goto L_0058491b; /* jbe 0x58491b */
L_00584916:;
    PUSH32(c, 0x0058491bu); f_00585a29(c); /* call 0x585a29 */
L_0058491b:;
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi * 4)); /* lea eax, [esi + esi*4] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->eax * 4)); /* lea eax, [ebx + eax*4] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00584928(CPU *c) { /* __global_unwind2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x584940u; PUSH32(c, v_); } /* push 0x10004940 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00584940u); f_0058cb70(c); /* call 0x58cb70 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00584940(CPU *c) { /* PTR_00584940 */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00584948(CPU *c) { /* PTR_00584948 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->ecx + 0x4u)) & (uint32_t)0x6u)); /* test dword ptr [ecx + 4], 6 */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    if (c->zf) goto L_00584969; /* je 0x584969 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    W32((uint32_t)(c->edx), (uint32_t)(c->eax)); /* mov dword ptr [edx], eax */
    c->eax = (uint32_t)((uint32_t)0x3u); /* mov eax, 3 */
L_00584969:;
    c->esp += 4; return; /* ret  */
}

void f_0058496a(CPU *c) { /* __local_unwind2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0xfffffffeu; PUSH32(c, v_); } /* push -2 */
    { uint32_t v_ = 0x584948u; PUSH32(c, v_); } /* push 0x10004948 */
    { uint32_t v_ = R32((uint32_t)(0x0u + c->fs_base)); PUSH32(c, v_); } /* push dword ptr fs:[0] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
L_00584987:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov eax, dword ptr [esp + 0x20] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ebx, dword ptr [eax + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + 0xcu))); /* mov esi, dword ptr [eax + 0xc] */
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (c->zf) goto L_005849c4; /* je 0x5849c4 */
    (void)sub32(c, c->esi, R32((uint32_t)(c->esp + 0x24u))); /* cmp esi, dword ptr [esp + 0x24] */
    if (c->zf) goto L_005849c4; /* je 0x5849c4 */
    c->esi = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea esi, [esi + esi*2] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + c->esi * 4))); /* mov ecx, dword ptr [ebx + esi*4] */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 8], ecx */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0xc], ecx */
    (void)sub32(c, R32((uint32_t)(c->ebx + c->esi * 4 + 0x4u)), (uint32_t)0x0u); /* cmp dword ptr [ebx + esi*4 + 4], 0 */
    if (!c->zf) goto L_005849c2; /* jne 0x5849c2 */
    { uint32_t v_ = 0x101u; PUSH32(c, v_); } /* push 0x101 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + c->esi * 4 + 0x8u))); /* mov eax, dword ptr [ebx + esi*4 + 8] */
    PUSH32(c, 0x005849beu); f_005849fe(c); /* call 0x5849fe */
    { uint32_t t_ = R32((uint32_t)(c->ebx + c->esi * 4 + 0x8u)); PUSH32(c, 0x005849c2u); call_indirect(c, t_); } /* call dword ptr [ebx + esi*4 + 8] */
L_005849c2:;
    goto L_00584987; /* jmp 0x584987 */
L_005849c4:;
    { uint32_t v_ = R32(c->esp); c->esp += 4; W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(v_)); } /* pop dword ptr fs:[0] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_005849d2(CPU *c) { /* __abnormal_termination */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov ecx, dword ptr fs:[0] */
    (void)sub32(c, R32((uint32_t)(c->ecx + 0x4u)), (uint32_t)0x584948u); /* cmp dword ptr [ecx + 4], 0x10004948 */
    if (!c->zf) goto L_005849f4; /* jne 0x5849f4 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov edx, dword ptr [ecx + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edx + 0xcu))); /* mov edx, dword ptr [edx + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->ecx + 0x8u)), c->edx); /* cmp dword ptr [ecx + 8], edx */
    if (!c->zf) goto L_005849f4; /* jne 0x5849f4 */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
L_005849f4:;
    c->esp += 4; return; /* ret  */
}

void f_005849f5(CPU *c) { /* __NLG_Notify1 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ebx = (uint32_t)((uint32_t)0x58e2acu); /* mov ebx, 0x1000e2ac */
    { f_00584a08(c); return; } /* jmp 0x584a08 */
}

void f_005849fe(CPU *c) { /* FUN_100049fe */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ebx = (uint32_t)((uint32_t)0x58e2acu); /* mov ebx, 0x1000e2ac */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebx + 8], ecx */
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 4], eax */
    W32((uint32_t)(c->ebx + 0xcu), (uint32_t)(c->ebp)); /* mov dword ptr [ebx + 0xc], ebp */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
}

void f_00584a08(CPU *c) { /* PTR_00584a08 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebx + 8], ecx */
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 4], eax */
    W32((uint32_t)(c->ebx + 0xcu), (uint32_t)(c->ebp)); /* mov dword ptr [ebx + 0xc], ebp */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
}

void f_00584a16(CPU *c) { /* FUN_10004a16 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00584a1cu); f_00585b71(c); /* call 0x585b71 */
    { uint32_t v_ = R32((uint32_t)(0x622ed0u)); PUSH32(c, v_); } /* push dword ptr [0x100a2ed0] */
    PUSH32(c, 0x00584a27u); f_00585ecc(c); /* call 0x585ecc */
    c->edx = (uint32_t)(R32((uint32_t)(0x622ed0u))); /* mov edx, dword ptr [0x100a2ed0] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(0x622eccu))); /* mov ecx, dword ptr [0x100a2ecc] */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->esi = (uint32_t)(sub32(c, c->esi, c->edx)); /* sub esi, edx */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (!c->cf) goto L_00584a7c; /* jae 0x584a7c */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00584a45u); f_00585ecc(c); /* call 0x585ecc */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x10u)); /* add eax, 0x10 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(0x622ed0u)); PUSH32(c, v_); } /* push dword ptr [0x100a2ed0] */
    PUSH32(c, 0x00584a54u); f_00585b9d(c); /* call 0x585b9d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00584a5f; /* jne 0x584a5f */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    goto L_00584a8b; /* jmp 0x584a8b */
L_00584a5f:;
    c->ecx = (uint32_t)(R32((uint32_t)(0x622eccu))); /* mov ecx, dword ptr [0x100a2ecc] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, R32((uint32_t)(0x622ed0u)))); /* sub ecx, dword ptr [0x100a2ed0] */
    W32((uint32_t)(0x622ed0u), (uint32_t)(c->eax)); /* mov dword ptr [0x100a2ed0], eax */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 2)); /* sar ecx, 2 */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->ecx * 4)); /* lea ecx, [eax + ecx*4] */
    W32((uint32_t)(0x622eccu), (uint32_t)(c->ecx)); /* mov dword ptr [0x100a2ecc], ecx */
L_00584a7c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    { uint32_t a_ = (uint32_t)(0x622eccu); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x4u))); } /* add dword ptr [0x100a2ecc], 4 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_00584a8b:;
    PUSH32(c, 0x00584a90u); f_00585b7a(c); /* call 0x585b7a */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00584a94(CPU *c) { /* FUN_10004a94 */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    PUSH32(c, 0x00584a9du); f_00584a16(c); /* call 0x584a16 */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->esp += 4; return; /* ret  */
}

void f_00584aa6(CPU *c) { /* PTR_00584aa6 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x80u; PUSH32(c, v_); } /* push 0x80 */
    PUSH32(c, 0x00584ab0u); f_00585fba(c); /* call 0x585fba */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(0x622ed0u), (uint32_t)(c->eax)); /* mov dword ptr [0x100a2ed0], eax */
    if (!c->zf) goto L_00584ac7; /* jne 0x584ac7 */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    PUSH32(c, 0x00584ac1u); f_00584fa1(c); /* call 0x584fa1 */
    c->eax = (uint32_t)(R32((uint32_t)(0x622ed0u))); /* mov eax, dword ptr [0x100a2ed0] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00584ac7:;
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [eax], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(0x622ed0u))); /* mov eax, dword ptr [0x100a2ed0] */
    W32((uint32_t)(0x622eccu), (uint32_t)(c->eax)); /* mov dword ptr [0x100a2ecc], eax */
    c->esp += 4; return; /* ret  */
}

void f_00584ad5(CPU *c) { /* FUN_10004ad5 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = 0x1bu; PUSH32(c, v_); } /* push 0x1b */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x58d1b8u)); /* mov dword ptr [esi], 0x1000d1b8 */
    PUSH32(c, 0x00584ae5u); f_00586189(c); /* call 0x586189 */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov esi, dword ptr [esi + 4] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00584af4; /* je 0x584af4 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00584af3u); f_005861ff(c); /* call 0x5861ff */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00584af4:;
    { uint32_t v_ = 0x1bu; PUSH32(c, v_); } /* push 0x1b */
    PUSH32(c, 0x00584afbu); f_005861ea(c); /* call 0x5861ea */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00584afe(CPU *c) { /* type_info::vfunc_0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00584b06u); f_00584ad5(c); /* call 0x584ad5 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00584b14; /* je 0x584b14 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00584b13u); f_00581050(c); /* call 0x581050 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00584b14:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00584b1a(CPU *c) { /* __CxxThrowException@8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x20u)); /* sub esp, 0x20 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esi = (uint32_t)((uint32_t)0x58d1c0u); /* mov esi, 0x1000d1c0 */
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
    { uint32_t t_ = R32((uint32_t)(0x58d004u)); PUSH32(c, 0x00584b4eu); call_indirect(c, t_); } /* call dword ptr [0x1000d004] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 12; return; /* ret 8 */
}

void f_00584b54(CPU *c) { /* FUN_10004b54 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x20u)); /* sub esp, 0x20 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x18], eax */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x42u)); /* mov dword ptr [ebp - 0x14], 0x42 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe0u)); /* lea eax, [ebp - 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)((uint32_t)0x7fffffffu)); /* mov dword ptr [ebp - 0x1c], 0x7fffffff */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00584b82u); f_005864f0(c); /* call 0x5864f0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe4u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 0x1c] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    if (c->sf) goto L_00584b94; /* js 0x584b94 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov eax, dword ptr [ebp - 0x20] */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax], 0 */
    goto L_00584ba1; /* jmp 0x584ba1 */
L_00584b94:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe0u)); /* lea eax, [ebp - 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    PUSH32(c, 0x00584b9fu); f_005863d8(c); /* call 0x5863d8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00584ba1:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00584bb0(CPU *c) { /* _strncpy */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00584c33; /* je 0x584c33 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov esi, dword ptr [esp + 0x14] */
    (void)logic32(c, (uint32_t)(c->esi & (uint32_t)0x3u)); /* test esi, 3 */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edi, dword ptr [esp + 0x10] */
    if (!c->zf) goto L_00584bd4; /* jne 0x584bd4 */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->zf) goto L_00584c41; /* jne 0x584c41 */
    goto L_00584bf5; /* jmp 0x584bf5 */
L_00584bd4:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_00584c02; /* je 0x584c02 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00584c0a; /* je 0x584c0a */
    (void)logic32(c, (uint32_t)(c->esi & (uint32_t)0x3u)); /* test esi, 3 */
    if (!c->zf) goto L_00584bd4; /* jne 0x584bd4 */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->zf) goto L_00584c41; /* jne 0x584c41 */
L_00584bf0:;
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x3u))); /* and ebx, 3 */
    if (c->zf) goto L_00584c02; /* je 0x584c02 */
L_00584bf5:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00584c2e; /* je 0x584c2e */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->zf) goto L_00584bf5; /* jne 0x584bf5 */
L_00584c02:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_00584c0a:;
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x3u)); /* test edi, 3 */
    if (c->zf) goto L_00584c24; /* je 0x584c24 */
L_00584c12:;
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_00584ca6; /* je 0x584ca6 */
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x3u)); /* test edi, 3 */
    if (!c->zf) goto L_00584c12; /* jne 0x584c12 */
L_00584c24:;
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->zf) goto L_00584c97; /* jne 0x584c97 */
L_00584c2b:;
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
L_00584c2e:;
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->zf) goto L_00584c2b; /* jne 0x584c2b */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00584c33:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_00584c39:;
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_00584bf0; /* je 0x584bf0 */
L_00584c41:;
    c->edx = (uint32_t)((uint32_t)0x7efefeffu); /* mov edx, 0x7efefeff */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ (uint32_t)0xffffffffu))); /* xor eax, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ c->edx))); /* xor eax, edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u)); /* test eax, 0x81010100 */
    if (c->zf) goto L_00584c39; /* je 0x584c39 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00584c8b; /* je 0x584c8b */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->edx >> 8)) & ((uint8_t)(c->edx >> 8)))); /* test dh, dh */
    if (c->zf) goto L_00584c81; /* je 0x584c81 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0xff0000u)); /* test edx, 0xff0000 */
    if (c->zf) goto L_00584c77; /* je 0x584c77 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0xff000000u)); /* test edx, 0xff000000 */
    if (!c->zf) goto L_00584c39; /* jne 0x584c39 */
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    goto L_00584c8f; /* jmp 0x584c8f */
L_00584c77:;
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0xffffu))); /* and edx, 0xffff */
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    goto L_00584c8f; /* jmp 0x584c8f */
L_00584c81:;
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0xffu))); /* and edx, 0xff */
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    goto L_00584c8f; /* jmp 0x584c8f */
L_00584c8b:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
L_00584c8f:;
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_00584ca1; /* je 0x584ca1 */
L_00584c97:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00584c99:;
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (!c->zf) goto L_00584c99; /* jne 0x584c99 */
L_00584ca1:;
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x3u))); /* and ebx, 3 */
    if (!c->zf) goto L_00584c2b; /* jne 0x584c2b */
L_00584ca6:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00584cae(CPU *c) { /* _rand */
    PREEMPT_POLL(c);
    PUSH32(c, 0x00584cb3u); f_005858c1(c); /* call 0x5858c1 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x14u))); /* mov ecx, dword ptr [eax + 0x14] */
    { int64_t r_ = (int64_t)(int32_t)c->ecx * (int32_t)(uint32_t)0x343fdu; c->ecx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul ecx, ecx, 0x343fd */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x269ec3u)); /* add ecx, 0x269ec3 */
    W32((uint32_t)(c->eax + 0x14u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x14], ecx */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->eax = (uint32_t)(shr32(c, c->eax, 16)); /* shr eax, 0x10 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fffu))); /* and eax, 0x7fff */
    c->esp += 4; return; /* ret  */
}

void f_00584cd0(CPU *c) { /* FUN_10004cd0 */
    PREEMPT_POLL(c);
    PUSH32(c, 0x00584cd5u); f_00584ce8(c); /* call 0x584ce8 */
    PUSH32(c, 0x00584cdau); f_00586d4a(c); /* call 0x586d4a */
    W32((uint32_t)(0x6217b4u), (uint32_t)(c->eax)); /* mov dword ptr [0x100a17b4], eax */
    PUSH32(c, 0x00584ce4u); f_00586cfa(c); /* call 0x586cfa */
    c->fpu_sw &= 0x7f00; /* fnclex  */
    c->esp += 4; return; /* ret  */
}

void f_00584ce7(CPU *c) { /* PTR_00584ce7 */
    PREEMPT_POLL(c);
    c->esp += 4; return; /* ret  */
}

void f_00584ce8(CPU *c) { /* FUN_10004ce8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x587123u); /* mov eax, 0x10007123 */
    W32((uint32_t)(0x58e3dcu), (uint32_t)((uint32_t)0x586dcdu)); /* mov dword ptr [0x1000e3dc], 0x10006dcd */
    W32((uint32_t)(0x58e3d8u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000e3d8], eax */
    W32((uint32_t)(0x58e3e0u), (uint32_t)((uint32_t)0x586e33u)); /* mov dword ptr [0x1000e3e0], 0x10006e33 */
    W32((uint32_t)(0x58e3e4u), (uint32_t)((uint32_t)0x586d73u)); /* mov dword ptr [0x1000e3e4], 0x10006d73 */
    W32((uint32_t)(0x58e3e8u), (uint32_t)((uint32_t)0x586e1bu)); /* mov dword ptr [0x1000e3e8], 0x10006e1b */
    W32((uint32_t)(0x58e3ecu), (uint32_t)(c->eax)); /* mov dword ptr [0x1000e3ec], eax */
    c->esp += 4; return; /* ret  */
}

void f_00584d20(CPU *c) { /* FUN_10004d20 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edi, dword ptr [esp + 0x14] */
L_00584d28:;
    (void)sub32(c, R32((uint32_t)(0x58e5fcu)), (uint32_t)0x1u); /* cmp dword ptr [0x1000e5fc], 1 */
    if ((c->zf || c->sf != c->of)) goto L_00584d40; /* jle 0x584d40 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00584d3cu); f_00587199(c); /* call 0x587199 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00584d4f; /* jmp 0x584d4f */
L_00584d40:;
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x58e3f0u))); /* mov ecx, dword ptr [0x1000e3f0] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x8u))); /* and eax, 8 */
L_00584d4f:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00584d56; /* je 0x584d56 */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_00584d28; /* jmp 0x584d28 */
L_00584d56:;
    c->esi = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx esi, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->esi, (uint32_t)0x2du); /* cmp esi, 0x2d */
    c->ebp = (uint32_t)(c->esi); /* mov ebp, esi */
    if (c->zf) goto L_00584d66; /* je 0x584d66 */
    (void)sub32(c, c->esi, (uint32_t)0x2bu); /* cmp esi, 0x2b */
    if (!c->zf) goto L_00584d6a; /* jne 0x584d6a */
L_00584d66:;
    c->esi = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx esi, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
L_00584d6a:;
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
L_00584d6c:;
    (void)sub32(c, R32((uint32_t)(0x58e5fcu)), (uint32_t)0x1u); /* cmp dword ptr [0x1000e5fc], 1 */
    if ((c->zf || c->sf != c->of)) goto L_00584d81; /* jle 0x584d81 */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00584d7du); f_00587199(c); /* call 0x587199 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00584d8c; /* jmp 0x584d8c */
L_00584d81:;
    c->eax = (uint32_t)(R32((uint32_t)(0x58e3f0u))); /* mov eax, dword ptr [0x1000e3f0] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + c->esi * 2))); /* mov al, byte ptr [eax + esi*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4u))); /* and eax, 4 */
L_00584d8c:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00584d9d; /* je 0x584d9d */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->ebx * 4)); /* lea eax, [ebx + ebx*4] */
    c->ebx = (uint32_t)((uint32_t)(c->esi + c->eax * 2 + 0xffffffd0u)); /* lea ebx, [esi + eax*2 - 0x30] */
    c->esi = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx esi, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_00584d6c; /* jmp 0x584d6c */
L_00584d9d:;
    (void)sub32(c, c->ebp, (uint32_t)0x2du); /* cmp ebp, 0x2d */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    if (!c->zf) goto L_00584da6; /* jne 0x584da6 */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
L_00584da6:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00584dab(CPU *c) { /* FUN_10004dab */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
L_00584db5:;
    (void)sub32(c, R32((uint32_t)(0x58e5fcu)), (uint32_t)0x1u); /* cmp dword ptr [0x1000e5fc], 1 */
    if ((c->zf || c->sf != c->of)) goto L_00584dcd; /* jle 0x584dcd */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->esi))); /* movzx eax, byte ptr [esi] */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00584dc9u); f_00587199(c); /* call 0x587199 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00584ddc; /* jmp 0x584ddc */
L_00584dcd:;
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->esi))); /* movzx eax, byte ptr [esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x58e3f0u))); /* mov ecx, dword ptr [0x1000e3f0] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x8u))); /* and eax, 8 */
L_00584ddc:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00584de3; /* je 0x584de3 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    goto L_00584db5; /* jmp 0x584db5 */
L_00584de3:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00584dedu); f_005872d0(c); /* call 0x5872d0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe8u)); /* lea eax, [ebp - 0x18] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00584df9u); f_00587244(c); /* call 0x587244 */
    FPUSH(c, RF64((uint32_t)(c->eax + 0x10u))); /* fld qword ptr [eax + 0x10] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00584e04(CPU *c) { /* __ftol */
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

void f_00584e2b(CPU *c) { /* FUN_10004e2b */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_00584ec0; /* jne 0x584ec0 */
    { uint32_t t_ = R32((uint32_t)(0x58d00cu)); PUSH32(c, 0x00584e3eu); call_indirect(c, t_); } /* call dword ptr [0x1000d00c] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    W32((uint32_t)(0x6217d0u), (uint32_t)(c->eax)); /* mov dword ptr [0x100a17d0], eax */
    PUSH32(c, 0x00584e4au); f_00587b08(c); /* call 0x587b08 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00584e8b; /* je 0x584e8b */
    c->eax = (uint32_t)(R32((uint32_t)(0x6217d0u))); /* mov eax, dword ptr [0x100a17d0] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x6217d1u))); /* mov cl, byte ptr [0x100a17d1] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xffu))); /* and eax, 0xff */
    { uint32_t a_ = (uint32_t)(0x6217d0u); W32(a_, (uint32_t)(shr32(c, R32(a_), 16))); } /* shr dword ptr [0x100a17d0], 0x10 */
    W32((uint32_t)(0x6217d8u), (uint32_t)(c->eax)); /* mov dword ptr [0x100a17d8], eax */
    W32((uint32_t)(0x6217dcu), (uint32_t)(c->ecx)); /* mov dword ptr [0x100a17dc], ecx */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    W32((uint32_t)(0x6217d4u), (uint32_t)(c->eax)); /* mov dword ptr [0x100a17d4], eax */
    PUSH32(c, 0x00584e82u); f_0058583c(c); /* call 0x58583c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00584e8f; /* jne 0x584e8f */
    PUSH32(c, 0x00584e8bu); f_00587b65(c); /* call 0x587b65 */
L_00584e8b:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00584f01; /* jmp 0x584f01 */
L_00584e8f:;
    { uint32_t t_ = R32((uint32_t)(0x58d008u)); PUSH32(c, 0x00584e95u); call_indirect(c, t_); } /* call dword ptr [0x1000d008] */
    W32((uint32_t)(0x622ed4u), (uint32_t)(c->eax)); /* mov dword ptr [0x100a2ed4], eax */
    PUSH32(c, 0x00584e9fu); f_00587861(c); /* call 0x587861 */
    W32((uint32_t)(0x6217bcu), (uint32_t)(c->eax)); /* mov dword ptr [0x100a17bc], eax */
    PUSH32(c, 0x00584ea9u); f_0058734b(c); /* call 0x58734b */
    PUSH32(c, 0x00584eaeu); f_00587614(c); /* call 0x587614 */
    PUSH32(c, 0x00584eb3u); f_0058755b(c); /* call 0x58755b */
    PUSH32(c, 0x00584eb8u); f_00585a7f(c); /* call 0x585a7f */
    { uint32_t a_ = (uint32_t)(0x6217b8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [0x100a17b8] */
    goto L_00584efe; /* jmp 0x584efe */
L_00584ec0:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->zf) goto L_00584ef2; /* jne 0x584ef2 */
    (void)sub32(c, R32((uint32_t)(0x6217b8u)), c->ecx); /* cmp dword ptr [0x100a17b8], ecx */
    if ((c->zf || c->sf != c->of)) goto L_00584e8b; /* jle 0x584e8b */
    { uint32_t a_ = (uint32_t)(0x6217b8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [0x100a17b8] */
    (void)sub32(c, R32((uint32_t)(0x621808u)), c->ecx); /* cmp dword ptr [0x100a1808], ecx */
    if (!c->zf) goto L_00584ee1; /* jne 0x584ee1 */
    PUSH32(c, 0x00584ee1u); f_00585abd(c); /* call 0x585abd */
L_00584ee1:;
    PUSH32(c, 0x00584ee6u); f_00587507(c); /* call 0x587507 */
    PUSH32(c, 0x00584eebu); f_00585890(c); /* call 0x585890 */
    PUSH32(c, 0x00584ef0u); f_00587b65(c); /* call 0x587b65 */
    goto L_00584efe; /* jmp 0x584efe */
L_00584ef2:;
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_00584efe; /* jne 0x584efe */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00584efdu); f_00585928(c); /* call 0x585928 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00584efe:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00584f01:;
    c->esp += 16; return; /* ret 0xc */
}

void f_00584f04(CPU *c) { /* entry */
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
    if (!c->zf) goto L_00584f20; /* jne 0x584f20 */
    (void)sub32(c, R32((uint32_t)(0x6217b8u)), (uint32_t)0x0u); /* cmp dword ptr [0x100a17b8], 0 */
    goto L_00584f46; /* jmp 0x584f46 */
L_00584f20:;
    (void)sub32(c, c->esi, (uint32_t)0x1u); /* cmp esi, 1 */
    if (c->zf) goto L_00584f2a; /* je 0x584f2a */
    (void)sub32(c, c->esi, (uint32_t)0x2u); /* cmp esi, 2 */
    if (!c->zf) goto L_00584f4c; /* jne 0x584f4c */
L_00584f2a:;
    c->eax = (uint32_t)(R32((uint32_t)(0x622ed8u))); /* mov eax, dword ptr [0x100a2ed8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00584f3c; /* je 0x584f3c */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00584f38u); call_indirect(c, t_); } /* call eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00584f48; /* je 0x584f48 */
L_00584f3c:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00584f44u); f_00584e2b(c); /* call 0x584e2b */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
L_00584f46:;
    if (!c->zf) goto L_00584f4c; /* jne 0x584f4c */
L_00584f48:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00584f9a; /* jmp 0x584f9a */
L_00584f4c:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00584f54u); f_00587c0d(c); /* call 0x587c0d */
    (void)sub32(c, c->esi, (uint32_t)0x1u); /* cmp esi, 1 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0xc], eax */
    if (!c->zf) goto L_00584f68; /* jne 0x584f68 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00584f97; /* jne 0x584f97 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00584f68u); f_00584e2b(c); /* call 0x584e2b */
L_00584f68:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00584f71; /* je 0x584f71 */
    (void)sub32(c, c->esi, (uint32_t)0x3u); /* cmp esi, 3 */
    if (!c->zf) goto L_00584f97; /* jne 0x584f97 */
L_00584f71:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00584f79u); f_00584e2b(c); /* call 0x584e2b */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00584f80; /* jne 0x584f80 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->eax)))); } /* and dword ptr [ebp + 0xc], eax */
L_00584f80:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    if (c->zf) goto L_00584f97; /* je 0x584f97 */
    c->eax = (uint32_t)(R32((uint32_t)(0x622ed8u))); /* mov eax, dword ptr [0x100a2ed8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00584f97; /* je 0x584f97 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00584f94u); call_indirect(c, t_); } /* call eax */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0xc], eax */
L_00584f97:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
L_00584f9a:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 16; return; /* ret 0xc */
}

void f_00584fa1(CPU *c) { /* __amsg_exit */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x6217c4u))); /* mov eax, dword ptr [0x100a17c4] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_00584fb8; /* je 0x584fb8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00584fbd; /* jne 0x584fbd */
    (void)sub32(c, R32((uint32_t)(0x6217c8u)), (uint32_t)0x1u); /* cmp dword ptr [0x100a17c8], 1 */
    if (!c->zf) goto L_00584fbd; /* jne 0x584fbd */
L_00584fb8:;
    PUSH32(c, 0x00584fbdu); f_00587c13(c); /* call 0x587c13 */
L_00584fbd:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    PUSH32(c, 0x00584fc6u); f_00587c4c(c); /* call 0x587c4c */
    { uint32_t v_ = 0xffu; PUSH32(c, v_); } /* push 0xff */
    { uint32_t t_ = R32((uint32_t)(0x58e2f4u)); PUSH32(c, 0x00584fd1u); call_indirect(c, t_); } /* call dword ptr [0x1000e2f4] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00584fd1(CPU *c) { /* PTR_00584fd1 */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00584fd4(CPU *c) { /* FUN_10004fd4 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov esi, dword ptr [ebp + 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)((uint32_t)0x19930520u); /* mov edi, 0x19930520 */
    (void)sub32(c, R32((uint32_t)(c->esi)), c->edi); /* cmp dword ptr [esi], edi */
    if (c->zf) goto L_00584fea; /* je 0x584fea */
    PUSH32(c, 0x00584feau); f_00585a29(c); /* call 0x585a29 */
L_00584fea:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + 0x4u)) & (uint8_t)0x66u)); /* test byte ptr [eax + 4], 0x66 */
    if (c->zf) goto L_00585012; /* je 0x585012 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x4u)), (uint32_t)0x0u); /* cmp dword ptr [esi + 4], 0 */
    if (c->zf) goto L_00585068; /* je 0x585068 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x1c], 0 */
    if (!c->zf) goto L_00585068; /* jne 0x585068 */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x0058500du); f_00585329(c); /* call 0x585329 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    goto L_00585068; /* jmp 0x585068 */
L_00585012:;
    (void)sub32(c, R32((uint32_t)(c->esi + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [esi + 0xc], 0 */
    if (c->zf) goto L_00585068; /* je 0x585068 */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xe06d7363u); /* cmp dword ptr [eax], 0xe06d7363 */
    if (!c->zf) goto L_0058504c; /* jne 0x58504c */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x14u)), c->edi); /* cmp dword ptr [eax + 0x14], edi */
    if ((c->cf || c->zf)) goto L_0058504c; /* jbe 0x58504c */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x1cu))); /* mov ecx, dword ptr [eax + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov ecx, dword ptr [ecx + 8] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_0058504c; /* je 0x58504c */
    c->edx = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0x24u))); /* movzx edx, byte ptr [ebp + 0x24] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = c->ecx; PUSH32(c, 0x00585047u); call_indirect(c, t_); } /* call ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    goto L_0058506b; /* jmp 0x58506b */
L_0058504c:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x24u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x24] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00585065u); f_0058506f(c); /* call 0x58506f */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
L_00585068:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_0058506b:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_0058506f(CPU *c) { /* FUN_1000506f */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffecu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp - 0x14], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x10], eax */
    if ((c->sf != c->of)) goto L_0058508f; /* jl 0x58508f */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov ecx, dword ptr [ebp + 0x18] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ecx + 0x4u))); /* cmp eax, dword ptr [ecx + 4] */
    if ((c->sf != c->of)) goto L_00585094; /* jl 0x585094 */
L_0058508f:;
    PUSH32(c, 0x00585094u); f_00585a29(c); /* call 0x585a29 */
L_00585094:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    c->ebx = (uint32_t)((uint32_t)0xe06d7363u); /* mov ebx, 0xe06d7363 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)((uint32_t)0x19930520u); /* mov edi, 0x19930520 */
    (void)sub32(c, R32((uint32_t)(c->esi)), c->ebx); /* cmp dword ptr [esi], ebx */
    if (!c->zf) goto L_005851f7; /* jne 0x5851f7 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [esi + 0x10], 3 */
    if (!c->zf) goto L_00585114; /* jne 0x585114 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x14u)), c->edi); /* cmp dword ptr [esi + 0x14], edi */
    if (!c->zf) goto L_00585114; /* jne 0x585114 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [esi + 0x1c], 0 */
    if (!c->zf) goto L_00585114; /* jne 0x585114 */
    PUSH32(c, 0x005850c2u); f_005858c1(c); /* call 0x5858c1 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x6cu)), (uint32_t)0x0u); /* cmp dword ptr [eax + 0x6c], 0 */
    if (c->zf) goto L_005851f2; /* je 0x5851f2 */
    PUSH32(c, 0x005850d1u); f_005858c1(c); /* call 0x5858c1 */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + 0x6cu))); /* mov esi, dword ptr [eax + 0x6c] */
    PUSH32(c, 0x005850d9u); f_005858c1(c); /* call 0x5858c1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x70u))); /* mov eax, dword ptr [eax + 0x70] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x10], eax */
    W8((uint32_t)(c->ebp + 0xffffffecu), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ebp - 0x14], 1 */
    PUSH32(c, 0x005850ebu); f_00587d9f(c); /* call 0x587d9f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_005850f6; /* jne 0x5850f6 */
    PUSH32(c, 0x005850f6u); f_00585a29(c); /* call 0x585a29 */
L_005850f6:;
    (void)sub32(c, R32((uint32_t)(c->esi)), c->ebx); /* cmp dword ptr [esi], ebx */
    if (!c->zf) goto L_005851f7; /* jne 0x5851f7 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [esi + 0x10], 3 */
    if (!c->zf) goto L_00585114; /* jne 0x585114 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x14u)), c->edi); /* cmp dword ptr [esi + 0x14], edi */
    if (!c->zf) goto L_00585114; /* jne 0x585114 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [esi + 0x1c], 0 */
    if (!c->zf) goto L_00585114; /* jne 0x585114 */
    PUSH32(c, 0x00585114u); f_00585a29(c); /* call 0x585a29 */
L_00585114:;
    (void)sub32(c, R32((uint32_t)(c->esi)), c->ebx); /* cmp dword ptr [esi], ebx */
    if (!c->zf) goto L_005851f7; /* jne 0x5851f7 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [esi + 0x10], 3 */
    if (!c->zf) goto L_005851f7; /* jne 0x5851f7 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x14u)), c->edi); /* cmp dword ptr [esi + 0x14], edi */
    if (!c->zf) goto L_005851f7; /* jne 0x5851f7 */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov edi, dword ptr [ebp - 0x10] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe8u)); /* lea eax, [ebp - 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    PUSH32(c, 0x00585146u); f_005848ab(c); /* call 0x5848ab */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
L_0058514b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xffffffe8u))); /* cmp eax, dword ptr [ebp - 0x18] */
    if (!c->cf) goto L_005851e2; /* jae 0x5851e2 */
    (void)sub32(c, R32((uint32_t)(c->ebx)), c->edi); /* cmp dword ptr [ebx], edi */
    if ((!c->zf && c->sf == c->of)) goto L_005851d7; /* jg 0x5851d7 */
    (void)sub32(c, c->edi, R32((uint32_t)(c->ebx + 0x4u))); /* cmp edi, dword ptr [ebx + 4] */
    if ((!c->zf && c->sf == c->of)) goto L_005851d7; /* jg 0x5851d7 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x10u))); /* mov eax, dword ptr [ebx + 0x10] */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xcu))); /* mov eax, dword ptr [ebx + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    if ((c->zf || c->sf != c->of)) goto L_005851d4; /* jle 0x5851d4 */
L_00585170:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x1cu))); /* mov eax, dword ptr [esi + 0x1c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0xcu))); /* mov eax, dword ptr [eax + 0xc] */
    c->edi = (uint32_t)((uint32_t)(c->eax + 0x4u)); /* lea edi, [eax + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    if ((c->zf || c->sf != c->of)) goto L_005851a1; /* jle 0x5851a1 */
L_00585182:;
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [esi + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->edi)); PUSH32(c, v_); } /* push dword ptr [edi] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x0058518fu); f_005852cc(c); /* call 0x5852cc */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_005851b0; /* jne 0x5851b0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 8] */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff8u)), c->eax); /* cmp dword ptr [ebp - 8], eax */
    if ((!c->zf && c->sf == c->of)) goto L_00585182; /* jg 0x585182 */
L_005851a1:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff4u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x10u))); } /* add dword ptr [ebp + 8], 0x10 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0xc], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_00585170; /* jg 0x585170 */
    goto L_005851d4; /* jmp 0x5851d4 */
L_005851b0:;
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
    PUSH32(c, 0x005851d1u); f_005853dd(c); /* call 0x5853dd */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
L_005851d4:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov edi, dword ptr [ebp - 0x10] */
L_005851d7:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x14u)); /* add ebx, 0x14 */
    goto L_0058514b; /* jmp 0x58514b */
L_005851e2:;
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x1cu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0x1c], 0 */
    if (c->zf) goto L_005851f2; /* je 0x5851f2 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x005851f0u); f_00585761(c); /* call 0x585761 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_005851f2:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_005851f7:;
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x1cu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0x1c], 0 */
    if (!c->zf) goto L_0058521d; /* jne 0x58521d */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x24u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffff0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00585218u); f_00585222(c); /* call 0x585222 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    goto L_005851f2; /* jmp 0x5851f2 */
L_0058521d:;
    { f_005859c8(c); return; } /* jmp 0x5859c8 */
}

void f_00585222(CPU *c) { /* FUN_10005222 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x0058522eu); f_005858c1(c); /* call 0x5858c1 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x68u)), (uint32_t)0x0u); /* cmp dword ptr [eax + 0x68], 0 */
    if (c->zf) goto L_00585255; /* je 0x585255 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x24u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x0058524eu); f_00584780(c); /* call 0x584780 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_005852c8; /* jne 0x5852c8 */
L_00585255:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov edi, dword ptr [ebp + 0x1c] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    PUSH32(c, 0x0058526cu); f_005848ab(c); /* call 0x5848ab */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_00585271:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xfffffff8u))); /* cmp eax, dword ptr [ebp - 8] */
    if (!c->cf) goto L_005852c8; /* jae 0x5852c8 */
    (void)sub32(c, c->edi, R32((uint32_t)(c->esi))); /* cmp edi, dword ptr [esi] */
    if ((c->sf != c->of)) goto L_005852c0; /* jl 0x5852c0 */
    (void)sub32(c, c->edi, R32((uint32_t)(c->esi + 0x4u))); /* cmp edi, dword ptr [esi + 4] */
    if ((!c->zf && c->sf == c->of)) goto L_005852c0; /* jg 0x5852c0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0xfffffff4u))); /* mov ecx, dword ptr [eax - 0xc] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_0058529a; /* je 0x58529a */
    (void)sub8(c, R8((uint32_t)(c->ecx + 0x8u)), (uint8_t)0x0u); /* cmp byte ptr [ecx + 8], 0 */
    if (!c->zf) goto L_005852c0; /* jne 0x5852c0 */
L_0058529a:;
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
    PUSH32(c, 0x005852bdu); f_005853dd(c); /* call 0x5853dd */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
L_005852c0:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x14u)); /* add esi, 0x14 */
    goto L_00585271; /* jmp 0x585271 */
L_005852c8:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_005852cc(CPU *c) { /* FUN_100052cc */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edi, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov eax, dword ptr [edi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00585323; /* je 0x585323 */
    (void)sub8(c, R8((uint32_t)(c->eax + 0x8u)), (uint8_t)0x0u); /* cmp byte ptr [eax + 8], 0 */
    c->edx = (uint32_t)((uint32_t)(c->eax + 0x8u)); /* lea edx, [eax + 8] */
    if (c->zf) goto L_00585323; /* je 0x585323 */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (c->zf) goto L_005852fd; /* je 0x5852fd */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x8u)); /* add ecx, 8 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x005852f7u); f_005862f0(c); /* call 0x5862f0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_0058531f; /* jne 0x58531f */
L_005852fd:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi)) & (uint8_t)0x2u)); /* test byte ptr [esi], 2 */
    if (c->zf) goto L_00585307; /* je 0x585307 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edi)) & (uint8_t)0x8u)); /* test byte ptr [edi], 8 */
    if (c->zf) goto L_0058531f; /* je 0x58531f */
L_00585307:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    if (c->zf) goto L_00585316; /* je 0x585316 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edi)) & (uint8_t)0x1u)); /* test byte ptr [edi], 1 */
    if (c->zf) goto L_0058531f; /* je 0x58531f */
L_00585316:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x2u)); /* test al, 2 */
    if (c->zf) goto L_00585323; /* je 0x585323 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edi)) & (uint8_t)0x2u)); /* test byte ptr [edi], 2 */
    if (!c->zf) goto L_00585323; /* jne 0x585323 */
L_0058531f:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00585326; /* jmp 0x585326 */
L_00585323:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00585326:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00585329(CPU *c) { /* FUN_10005329 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x58d1e0u; PUSH32(c, v_); } /* push 0x1000d1e0 */
    { uint32_t v_ = 0x587df8u; PUSH32(c, v_); } /* push 0x10007df8 */
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
L_0058535b:;
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0x14u))); /* cmp esi, dword ptr [ebp + 0x14] */
    if (c->zf) goto L_005853b5; /* je 0x5853b5 */
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if ((c->zf || c->sf != c->of)) goto L_0058536a; /* jle 0x58536a */
    (void)sub32(c, c->esi, R32((uint32_t)(c->edi + 0x4u))); /* cmp esi, dword ptr [edi + 4] */
    if ((c->sf != c->of)) goto L_0058536f; /* jl 0x58536f */
L_0058536a:;
    PUSH32(c, 0x0058536fu); f_00585a29(c); /* call 0x585a29 */
L_0058536f:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8 + 0x4u))); /* mov eax, dword ptr [eax + esi*8 + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0058538a; /* je 0x58538a */
    { uint32_t v_ = 0x103u; PUSH32(c, v_); } /* push 0x103 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0058538au); f_005857f0(c); /* call 0x5857f0 */
L_0058538a:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    goto L_005853aa; /* jmp 0x5853aa */
L_005853aa:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8))); /* mov esi, dword ptr [eax + esi*8] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x1c], esi */
    goto L_0058535b; /* jmp 0x58535b */
L_005853b5:;
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebx + 8], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0058535b(CPU *c) { /* PTR_0058535b */
    PREEMPT_POLL(c);
L_0058535b:;
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0x14u))); /* cmp esi, dword ptr [ebp + 0x14] */
    if (c->zf) goto L_005853b5; /* je 0x5853b5 */
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if ((c->zf || c->sf != c->of)) goto L_0058536a; /* jle 0x58536a */
    (void)sub32(c, c->esi, R32((uint32_t)(c->edi + 0x4u))); /* cmp esi, dword ptr [edi + 4] */
    if ((c->sf != c->of)) goto L_0058536f; /* jl 0x58536f */
L_0058536a:;
    PUSH32(c, 0x0058536fu); f_00585a29(c); /* call 0x585a29 */
L_0058536f:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8 + 0x4u))); /* mov eax, dword ptr [eax + esi*8 + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0058538a; /* je 0x58538a */
    { uint32_t v_ = 0x103u; PUSH32(c, v_); } /* push 0x103 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0058538au); f_005857f0(c); /* call 0x5857f0 */
L_0058538a:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    goto L_005853aa; /* jmp 0x5853aa */
L_005853aa:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8))); /* mov esi, dword ptr [eax + esi*8] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x1c], esi */
    goto L_0058535b; /* jmp 0x58535b */
L_005853b5:;
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebx + 8], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00585390(CPU *c) { /* PTR_00585390 */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffecu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x14] */
    PUSH32(c, 0x00585398u); f_005853c7(c); /* call 0x5853c7 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_0058539a(CPU *c) { /* PTR_0058539a */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edi, dword ptr [ebp + 0x10] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov esi, dword ptr [ebp - 0x1c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8))); /* mov esi, dword ptr [eax + esi*8] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x1c], esi */
    { f_0058535b(c); return; } /* jmp 0x58535b */
}

void f_005853c7(CPU *c) { /* PTR_005853c7 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xe06d7363u); /* cmp dword ptr [eax], 0xe06d7363 */
    if (c->zf) goto L_005853d8; /* je 0x5853d8 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_005853d8:;
    { f_005859c8(c); return; } /* jmp 0x5859c8 */
}

void f_005853dd(CPU *c) { /* FUN_100053dd */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x20u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x20], 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov ebx, dword ptr [ebp + 0x1c] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    if (c->zf) goto L_005853ff; /* je 0x5853ff */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x005853fcu); f_0058559d(c); /* call 0x58559d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_005853ff:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x2cu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x2c], 0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    if (!c->zf) goto L_0058540b; /* jne 0x58540b */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    goto L_0058540e; /* jmp 0x58540e */
L_0058540b:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x2cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x2c] */
L_0058540e:;
    PUSH32(c, 0x00585413u); f_00584682(c); /* call 0x584682 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x24u))); /* mov esi, dword ptr [ebp + 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00585424u); f_00585329(c); /* call 0x585329 */
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
    PUSH32(c, 0x00585445u); f_00585458(c); /* call 0x585458 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00585453; /* je 0x585453 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00585453u); f_00584640(c); /* call 0x584640 */
L_00585453:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00585458(CPU *c) { /* FUN_10005458 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x58d1f0u; PUSH32(c, v_); } /* push 0x1000d1f0 */
    { uint32_t v_ = 0x587df8u; PUSH32(c, v_); } /* push 0x10007df8 */
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
    PUSH32(c, 0x00585496u); f_005858c1(c); /* call 0x5858c1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x6cu))); /* mov eax, dword ptr [eax + 0x6c] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    PUSH32(c, 0x005854a1u); f_005858c1(c); /* call 0x5858c1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x70u))); /* mov eax, dword ptr [eax + 0x70] */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    PUSH32(c, 0x005854acu); f_005858c1(c); /* call 0x5858c1 */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    W32((uint32_t)(c->eax + 0x6cu), (uint32_t)(c->edi)); /* mov dword ptr [eax + 0x6c], edi */
    PUSH32(c, 0x005854b7u); f_005858c1(c); /* call 0x5858c1 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    W32((uint32_t)(c->eax + 0x70u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x70], ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x005854d8u); f_00584707(c); /* call 0x584707 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x2c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x005854ebu); f_00585525(c); /* call 0x585525 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd4u))); /* mov eax, dword ptr [ebp - 0x2c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_005854ee(CPU *c) { /* PTR_005854ee */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_005854fd(CPU *c) { /* PTR_005854fd */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffecu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x14] */
    PUSH32(c, 0x00585505u); f_00585573(c); /* call 0x585573 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00585507(CPU *c) { /* PTR_00585507 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffd4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x2c], 0 */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00585519u); f_0058496a(c); /* call 0x58496a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { f_005854ee(c); return; } /* jmp 0x5854ee */
}

void f_0058551f(CPU *c) { /* PTR_0058551f */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    { f_00585525(c); return; }
}

void f_00585525(CPU *c) { /* FUN_10005525 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    W32((uint32_t)(c->esi + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [esi - 4], eax */
    PUSH32(c, 0x00585530u); f_005858c1(c); /* call 0x5858c1 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov ecx, dword ptr [ebp - 0x1c] */
    W32((uint32_t)(c->eax + 0x6cu), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x6c], ecx */
    PUSH32(c, 0x0058553bu); f_005858c1(c); /* call 0x5858c1 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov ecx, dword ptr [ebp - 0x20] */
    W32((uint32_t)(c->eax + 0x70u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x70], ecx */
    (void)sub32(c, R32((uint32_t)(c->edi)), (uint32_t)0xe06d7363u); /* cmp dword ptr [edi], 0xe06d7363 */
    if (!c->zf) goto L_00585572; /* jne 0x585572 */
    (void)sub32(c, R32((uint32_t)(c->edi + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [edi + 0x10], 3 */
    if (!c->zf) goto L_00585572; /* jne 0x585572 */
    (void)sub32(c, R32((uint32_t)(c->edi + 0x14u)), (uint32_t)0x19930520u); /* cmp dword ptr [edi + 0x14], 0x19930520 */
    if (!c->zf) goto L_00585572; /* jne 0x585572 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00585572; /* jne 0x585572 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x2c], 0 */
    if (c->zf) goto L_00585572; /* je 0x585572 */
    PUSH32(c, 0x00585569u); f_005849d2(c); /* call 0x5849d2 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00585570u); f_00585761(c); /* call 0x585761 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00585572:;
    c->esp += 4; return; /* ret  */
}

void f_00585573(CPU *c) { /* PTR_00585573 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xe06d7363u); /* cmp dword ptr [eax], 0xe06d7363 */
    if (!c->zf) goto L_0058559a; /* jne 0x58559a */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [eax + 0x10], 3 */
    if (!c->zf) goto L_0058559a; /* jne 0x58559a */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x14u)), (uint32_t)0x19930520u); /* cmp dword ptr [eax + 0x14], 0x19930520 */
    if (!c->zf) goto L_0058559a; /* jne 0x58559a */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [eax + 0x1c], 0 */
    if (!c->zf) goto L_0058559a; /* jne 0x58559a */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
L_0058559a:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_0058559d(CPU *c) { /* FUN_1000559d */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x58d208u; PUSH32(c, v_); } /* push 0x1000d208 */
    { uint32_t v_ = 0x587df8u; PUSH32(c, v_); } /* push 0x10007df8 */
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
    if (c->zf) goto L_00585746; /* je 0x585746 */
    (void)sub8(c, R8((uint32_t)(c->eax + 0x8u)), (uint8_t)0x0u); /* cmp byte ptr [eax + 8], 0 */
    if (c->zf) goto L_00585746; /* je 0x585746 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov eax, dword ptr [ecx + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00585746; /* je 0x585746 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
    c->edi = (uint32_t)((uint32_t)(c->eax + c->edx + 0xcu)); /* lea edi, [eax + edx + 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ecx)) & (uint8_t)0x8u)); /* test byte ptr [ecx], 8 */
    if (c->zf) goto L_0058563a; /* je 0x58563a */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x18] */
    PUSH32(c, 0x00585603u); f_00587d9f(c); /* call 0x587d9f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0058573d; /* je 0x58573d */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00585615u); f_00587dbb(c); /* call 0x587dbb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0058573d; /* je 0x58573d */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x18u))); /* mov eax, dword ptr [esi + 0x18] */
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov ecx, dword ptr [ebp + 0x14] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x8u)); /* add ecx, 8 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
L_0058562b:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00585631u); f_005857c8(c); /* call 0x5857c8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    goto L_00585742; /* jmp 0x585742 */
L_0058563a:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov esi, dword ptr [ebp + 0x14] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi)) & (uint8_t)0x1u)); /* test byte ptr [esi], 1 */
    if (c->zf) goto L_00585694; /* je 0x585694 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    PUSH32(c, 0x0058564fu); f_00587d9f(c); /* call 0x587d9f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0058573d; /* je 0x58573d */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00585661u); f_00587dbb(c); /* call 0x587dbb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0058573d; /* je 0x58573d */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x14u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00585677u); f_00587ed0(c); /* call 0x587ed0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x14u)), (uint32_t)0x4u); /* cmp dword ptr [esi + 0x14], 4 */
    if (!c->zf) goto L_00585742; /* jne 0x585742 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00585742; /* je 0x585742 */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x8u)); /* add esi, 8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    goto L_0058562b; /* jmp 0x58562b */
L_00585694:;
    (void)sub32(c, R32((uint32_t)(c->esi + 0x18u)), (uint32_t)0x0u); /* cmp dword ptr [esi + 0x18], 0 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    if (!c->zf) goto L_005856dc; /* jne 0x5856dc */
    PUSH32(c, 0x005856a7u); f_00587d9f(c); /* call 0x587d9f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0058573d; /* je 0x58573d */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x005856b9u); f_00587dbb(c); /* call 0x587dbb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0058573d; /* je 0x58573d */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x14u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x14] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x8u)); /* add esi, 8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    PUSH32(c, 0x005856ceu); f_005857c8(c); /* call 0x5857c8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x005856d7u); f_00587ed0(c); /* call 0x587ed0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_00585742; /* jmp 0x585742 */
L_005856dc:;
    PUSH32(c, 0x005856e1u); f_00587d9f(c); /* call 0x587d9f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0058573d; /* je 0x58573d */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x005856efu); f_00587dbb(c); /* call 0x587dbb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0058573d; /* je 0x58573d */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x18] */
    PUSH32(c, 0x005856fdu); f_00587dd7(c); /* call 0x587dd7 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0058573d; /* je 0x58573d */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi)) & (uint8_t)0x4u)); /* test byte ptr [esi], 4 */
    if (c->zf) goto L_00585723; /* je 0x585723 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x8u)); /* lea eax, [esi + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    PUSH32(c, 0x00585715u); f_005857c8(c); /* call 0x5857c8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00585721u); f_0058467b(c); /* call 0x58467b */
    goto L_00585742; /* jmp 0x585742 */
L_00585723:;
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x8u)); /* lea eax, [esi + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    PUSH32(c, 0x0058572fu); f_005857c8(c); /* call 0x5857c8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x0058573bu); f_00584674(c); /* call 0x584674 */
    goto L_00585742; /* jmp 0x585742 */
L_0058573d:;
    PUSH32(c, 0x00585742u); f_00585a29(c); /* call 0x585a29 */
L_00585742:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
L_00585746:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00585755(CPU *c) { /* PTR_00585755 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_00585759(CPU *c) { /* PTR_00585759 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { f_005859c8(c); return; } /* jmp 0x5859c8 */
}

void f_00585761(CPU *c) { /* FUN_10005761 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x58d218u; PUSH32(c, v_); } /* push 0x1000d218 */
    { uint32_t v_ = 0x587df8u; PUSH32(c, v_); } /* push 0x10007df8 */
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
    if (c->zf) goto L_005857a8; /* je 0x5857a8 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x1cu))); /* mov ecx, dword ptr [eax + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ecx, dword ptr [ecx + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_005857a8; /* je 0x5857a8 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = R32((uint32_t)(c->eax + 0x18u)); PUSH32(c, v_); } /* push dword ptr [eax + 0x18] */
    PUSH32(c, 0x005857a4u); f_00584674(c); /* call 0x584674 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
L_005857a8:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_005857b7(CPU *c) { /* PTR_005857b7 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xcu)), ((uint8_t)c->eax)); /* cmp byte ptr [ebp + 0xc], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(!c->zf ? 1 : 0); /* setne al */
    c->esp += 4; return; /* ret  */
}

void f_005857c0(CPU *c) { /* PTR_005857c0 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { f_005859c8(c); return; } /* jmp 0x5859c8 */
}

void f_005857c8(CPU *c) { /* FUN_100057c8 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov edx, dword ptr [ecx + 4] */
    c->eax = (uint32_t)(add32(c, c->eax, c->esi)); /* add eax, esi */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if ((c->sf != c->of)) goto L_005857e9; /* jl 0x5857e9 */
    c->esi = (uint32_t)(R32((uint32_t)(c->edx + c->esi))); /* mov esi, dword ptr [edx + esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov ecx, dword ptr [ecx + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + c->ecx))); /* mov ecx, dword ptr [esi + ecx] */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->edx)); /* add ecx, edx */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
L_005857e9:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_005857f0(CPU *c) { /* __CallSettingFrame@12 */
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
    PUSH32(c, 0x00585813u); f_005849f5(c); /* call 0x5849f5 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00585817u); call_indirect(c, t_); } /* call eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->ebx = (uint32_t)(c->ebp); /* mov ebx, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->ebx); /* mov ebp, ebx */
    (void)sub32(c, c->ecx, (uint32_t)0x100u); /* cmp ecx, 0x100 */
    if (!c->zf) goto L_0058582f; /* jne 0x58582f */
    c->ecx = (uint32_t)((uint32_t)0x2u); /* mov ecx, 2 */
L_0058582f:;
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00585835u); f_005849f5(c); /* call 0x5849f5 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 16; return; /* ret 0xc */
}

void f_0058583c(CPU *c) { /* FUN_1000583c */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00585842u); f_005860f4(c); /* call 0x5860f4 */
    { uint32_t t_ = R32((uint32_t)(0x58d018u)); PUSH32(c, 0x00585848u); call_indirect(c, t_); } /* call dword ptr [0x1000d018] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    W32((uint32_t)(0x58e300u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000e300], eax */
    if (c->zf) goto L_0058588c; /* je 0x58588c */
    { uint32_t v_ = 0x74u; PUSH32(c, v_); } /* push 0x74 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x0058585bu); f_00588205(c); /* call 0x588205 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_0058588c; /* je 0x58588c */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(0x58e300u)); PUSH32(c, v_); } /* push dword ptr [0x1000e300] */
    { uint32_t t_ = R32((uint32_t)(0x58d014u)); PUSH32(c, 0x00585870u); call_indirect(c, t_); } /* call dword ptr [0x1000d014] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0058588c; /* je 0x58588c */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x0058587au); f_005858ae(c); /* call 0x5858ae */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t t_ = R32((uint32_t)(0x58d010u)); PUSH32(c, 0x00585881u); call_indirect(c, t_); } /* call dword ptr [0x1000d010] */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [esi + 4], 0xffffffff */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_0058588c:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00585890(CPU *c) { /* FUN_10005890 */
    PREEMPT_POLL(c);
    PUSH32(c, 0x00585895u); f_0058611d(c); /* call 0x58611d */
    c->eax = (uint32_t)(R32((uint32_t)(0x58e300u))); /* mov eax, dword ptr [0x1000e300] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (c->zf) goto L_005858ad; /* je 0x5858ad */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x58d01cu)); PUSH32(c, 0x005858a6u); call_indirect(c, t_); } /* call dword ptr [0x1000d01c] */
    { uint32_t a_ = (uint32_t)(0x58e300u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [0x1000e300], 0xffffffff */
L_005858ad:;
    c->esp += 4; return; /* ret  */
}

void f_005858ae(CPU *c) { /* FUN_100058ae */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    W32((uint32_t)(c->eax + 0x50u), (uint32_t)((uint32_t)0x58e6d0u)); /* mov dword ptr [eax + 0x50], 0x1000e6d0 */
    W32((uint32_t)(c->eax + 0x14u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [eax + 0x14], 1 */
    c->esp += 4; return; /* ret  */
}

void f_005858c1(CPU *c) { /* FUN_100058c1 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0x58d028u)); PUSH32(c, 0x005858c9u); call_indirect(c, t_); } /* call dword ptr [0x1000d028] */
    { uint32_t v_ = R32((uint32_t)(0x58e300u)); PUSH32(c, v_); } /* push dword ptr [0x1000e300] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    { uint32_t t_ = R32((uint32_t)(0x58d024u)); PUSH32(c, 0x005858d7u); call_indirect(c, t_); } /* call dword ptr [0x1000d024] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_0058591c; /* jne 0x58591c */
    { uint32_t v_ = 0x74u; PUSH32(c, v_); } /* push 0x74 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x005858e6u); f_00588205(c); /* call 0x588205 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00585914; /* je 0x585914 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(0x58e300u)); PUSH32(c, v_); } /* push dword ptr [0x1000e300] */
    { uint32_t t_ = R32((uint32_t)(0x58d014u)); PUSH32(c, 0x005858fbu); call_indirect(c, t_); } /* call dword ptr [0x1000d014] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00585914; /* je 0x585914 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00585905u); f_005858ae(c); /* call 0x5858ae */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t t_ = R32((uint32_t)(0x58d010u)); PUSH32(c, 0x0058590cu); call_indirect(c, t_); } /* call dword ptr [0x1000d010] */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [esi + 4], 0xffffffff */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    goto L_0058591c; /* jmp 0x58591c */
L_00585914:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    PUSH32(c, 0x0058591bu); f_00584fa1(c); /* call 0x584fa1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_0058591c:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0x58d020u)); PUSH32(c, 0x00585923u); call_indirect(c, t_); } /* call dword ptr [0x1000d020] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00585928(CPU *c) { /* FUN_10005928 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x58e300u))); /* mov eax, dword ptr [0x1000e300] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (c->zf) goto L_005859c7; /* je 0x5859c7 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_0058594c; /* jne 0x58594c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x58d024u)); PUSH32(c, 0x00585946u); call_indirect(c, t_); } /* call dword ptr [0x1000d024] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_005859b8; /* je 0x5859b8 */
L_0058594c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov eax, dword ptr [esi + 0x24] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0058595a; /* je 0x58595a */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00585959u); f_005861ff(c); /* call 0x5861ff */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_0058595a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x28u))); /* mov eax, dword ptr [esi + 0x28] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00585968; /* je 0x585968 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00585967u); f_005861ff(c); /* call 0x5861ff */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00585968:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x30u))); /* mov eax, dword ptr [esi + 0x30] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00585976; /* je 0x585976 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00585975u); f_005861ff(c); /* call 0x5861ff */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00585976:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x38u))); /* mov eax, dword ptr [esi + 0x38] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00585984; /* je 0x585984 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00585983u); f_005861ff(c); /* call 0x5861ff */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00585984:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x40u))); /* mov eax, dword ptr [esi + 0x40] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00585992; /* je 0x585992 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00585991u); f_005861ff(c); /* call 0x5861ff */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00585992:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x44u))); /* mov eax, dword ptr [esi + 0x44] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_005859a0; /* je 0x5859a0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0058599fu); f_005861ff(c); /* call 0x5861ff */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_005859a0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    (void)sub32(c, c->eax, (uint32_t)0x58e6d0u); /* cmp eax, 0x1000e6d0 */
    if (c->zf) goto L_005859b1; /* je 0x5859b1 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x005859b0u); f_005861ff(c); /* call 0x5861ff */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_005859b1:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x005859b7u); f_005861ff(c); /* call 0x5861ff */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_005859b8:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x58e300u)); PUSH32(c, v_); } /* push dword ptr [0x1000e300] */
    { uint32_t t_ = R32((uint32_t)(0x58d014u)); PUSH32(c, 0x005859c6u); call_indirect(c, t_); } /* call dword ptr [0x1000d014] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_005859c7:;
    c->esp += 4; return; /* ret  */
}

void f_005859c8(CPU *c) { /* FUN_100059c8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x58d228u; PUSH32(c, v_); } /* push 0x1000d228 */
    { uint32_t v_ = 0x587df8u; PUSH32(c, v_); } /* push 0x10007df8 */
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
    PUSH32(c, 0x005859f7u); f_005858c1(c); /* call 0x5858c1 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x60u)), c->esi); /* cmp dword ptr [eax + 0x60], esi */
    if (c->zf) goto L_00585a1b; /* je 0x585a1b */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    PUSH32(c, 0x00585a08u); f_005858c1(c); /* call 0x5858c1 */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x60u)); PUSH32(c, 0x00585a0bu); call_indirect(c, t_); } /* call dword ptr [eax + 0x60] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 4], esi */
    goto L_00585a1b; /* jmp 0x585a1b */
L_00585a1b:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00585a24u); f_00585a24(c); /* call 0x585a24 */
    { f_00588342(c); return; } /* jmp 0x588342 */
}

void f_00585a10(CPU *c) { /* PTR_00585a10 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_00585a14(CPU *c) { /* PTR_00585a14 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00585a24u); f_00585a24(c); /* call 0x585a24 */
    { f_00588342(c); return; } /* jmp 0x588342 */
}

void f_00585a24(CPU *c) { /* PTR_00585a24 */
    PREEMPT_POLL(c);
    { f_00588342(c); return; } /* jmp 0x588342 */
}

void f_00585a29(CPU *c) { /* FUN_10005a29 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x58d240u; PUSH32(c, v_); } /* push 0x1000d240 */
    { uint32_t v_ = 0x587df8u; PUSH32(c, v_); } /* push 0x10007df8 */
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
    c->eax = (uint32_t)(R32((uint32_t)(0x58e304u))); /* mov eax, dword ptr [0x1000e304] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00585a71; /* je 0x585a71 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00585a64u); call_indirect(c, t_); } /* call eax */
    goto L_00585a6d; /* jmp 0x585a6d */
L_00585a6d:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
L_00585a71:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00585a7au); f_00585a7a(c); /* call 0x585a7a */
    { f_005859c8(c); return; } /* jmp 0x5859c8 */
}

void f_00585a66(CPU *c) { /* PTR_00585a66 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_00585a6a(CPU *c) { /* PTR_00585a6a */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00585a7au); f_00585a7a(c); /* call 0x585a7a */
    { f_005859c8(c); return; } /* jmp 0x5859c8 */
}

void f_00585a7a(CPU *c) { /* PTR_00585a7a */
    PREEMPT_POLL(c);
    { f_005859c8(c); return; } /* jmp 0x5859c8 */
}

void f_00585a7f(CPU *c) { /* FUN_10005a7f */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x58e2e8u))); /* mov eax, dword ptr [0x1000e2e8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00585a8a; /* je 0x585a8a */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00585a8au); call_indirect(c, t_); } /* call eax */
L_00585a8a:;
    { uint32_t v_ = 0x58e028u; PUSH32(c, v_); } /* push 0x1000e028 */
    { uint32_t v_ = 0x58e014u; PUSH32(c, v_); } /* push 0x1000e014 */
    PUSH32(c, 0x00585a99u); f_00585b83(c); /* call 0x585b83 */
    { uint32_t v_ = 0x58e010u; PUSH32(c, v_); } /* push 0x1000e010 */
    { uint32_t v_ = 0x58e000u; PUSH32(c, v_); } /* push 0x1000e000 */
    PUSH32(c, 0x00585aa8u); f_00585b83(c); /* call 0x585b83 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_00585aac(CPU *c) { /* __exit */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    PUSH32(c, 0x00585ab9u); f_00585acc(c); /* call 0x585acc */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00585abd(CPU *c) { /* FUN_10005abd */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    PUSH32(c, 0x00585ac8u); f_00585acc(c); /* call 0x585acc */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00585acc(CPU *c) { /* FUN_10005acc */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00585ad2u); f_00585b71(c); /* call 0x585b71 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    (void)sub32(c, R32((uint32_t)(0x62180cu)), c->edi); /* cmp dword ptr [0x100a180c], edi */
    if (!c->zf) goto L_00585aee; /* jne 0x585aee */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    { uint32_t t_ = R32((uint32_t)(0x58d034u)); PUSH32(c, 0x00585ae7u); call_indirect(c, t_); } /* call dword ptr [0x1000d034] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x58d030u)); PUSH32(c, 0x00585aeeu); call_indirect(c, t_); } /* call dword ptr [0x1000d030] */
L_00585aee:;
    (void)sub32(c, R32((uint32_t)(c->esp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [esp + 0xc], 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ebx, dword ptr [esp + 0x14] */
    W32((uint32_t)(0x621808u), (uint32_t)(c->edi)); /* mov dword ptr [0x100a1808], edi */
    W8((uint32_t)(0x621804u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [0x100a1804], bl */
    if (!c->zf) goto L_00585b42; /* jne 0x585b42 */
    c->eax = (uint32_t)(R32((uint32_t)(0x622ed0u))); /* mov eax, dword ptr [0x100a2ed0] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00585b31; /* je 0x585b31 */
    c->ecx = (uint32_t)(R32((uint32_t)(0x622eccu))); /* mov ecx, dword ptr [0x100a2ecc] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)((uint32_t)(c->ecx + 0xfffffffcu)); /* lea esi, [ecx - 4] */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if (c->cf) goto L_00585b30; /* jb 0x585b30 */
L_00585b1d:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00585b25; /* je 0x585b25 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00585b25u); call_indirect(c, t_); } /* call eax */
L_00585b25:;
    c->esi = (uint32_t)(sub32(c, c->esi, (uint32_t)0x4u)); /* sub esi, 4 */
    (void)sub32(c, c->esi, R32((uint32_t)(0x622ed0u))); /* cmp esi, dword ptr [0x100a2ed0] */
    if (!c->cf) goto L_00585b1d; /* jae 0x585b1d */
L_00585b30:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00585b31:;
    { uint32_t v_ = 0x58e034u; PUSH32(c, v_); } /* push 0x1000e034 */
    { uint32_t v_ = 0x58e02cu; PUSH32(c, v_); } /* push 0x1000e02c */
    PUSH32(c, 0x00585b40u); f_00585b83(c); /* call 0x585b83 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00585b42:;
    { uint32_t v_ = 0x58e040u; PUSH32(c, v_); } /* push 0x1000e040 */
    { uint32_t v_ = 0x58e038u; PUSH32(c, v_); } /* push 0x1000e038 */
    PUSH32(c, 0x00585b51u); f_00585b83(c); /* call 0x585b83 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    if (c->zf) goto L_00585b5f; /* je 0x585b5f */
    PUSH32(c, 0x00585b5du); f_00585b7a(c); /* call 0x585b7a */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_00585b5f:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    W32((uint32_t)(0x62180cu), (uint32_t)(c->edi)); /* mov dword ptr [0x100a180c], edi */
    { uint32_t t_ = R32((uint32_t)(0x58d02cu)); PUSH32(c, 0x00585b6fu); call_indirect(c, t_); } /* call dword ptr [0x1000d02c] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00585b6f(CPU *c) { /* PTR_00585b6f */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00585b71(CPU *c) { /* FUN_10005b71 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xdu; PUSH32(c, v_); } /* push 0xd */
    PUSH32(c, 0x00585b78u); f_00586189(c); /* call 0x586189 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00585b7a(CPU *c) { /* FUN_10005b7a */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xdu; PUSH32(c, v_); } /* push 0xd */
    PUSH32(c, 0x00585b81u); f_005861ea(c); /* call 0x5861ea */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00585b83(CPU *c) { /* FUN_10005b83 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
L_00585b88:;
    (void)sub32(c, c->esi, R32((uint32_t)(c->esp + 0xcu))); /* cmp esi, dword ptr [esp + 0xc] */
    if (!c->cf) goto L_00585b9b; /* jae 0x585b9b */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00585b96; /* je 0x585b96 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00585b96u); call_indirect(c, t_); } /* call eax */
L_00585b96:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    goto L_00585b88; /* jmp 0x585b88 */
L_00585b9b:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00585b9d(CPU *c) { /* FUN_10005b9d */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x58d258u; PUSH32(c, v_); } /* push 0x1000d258 */
    { uint32_t v_ = 0x587df8u; PUSH32(c, v_); } /* push 0x10007df8 */
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
    if (!c->zf) goto L_00585bd7; /* jne 0x585bd7 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x00585bd1u); f_00585fba(c); /* call 0x585fba */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00585ebd; /* jmp 0x585ebd */
L_00585bd7:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_00585bea; /* jne 0x585bea */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00585be4u); f_005861ff(c); /* call 0x5861ff */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00585ebb; /* jmp 0x585ebb */
L_00585bea:;
    c->eax = (uint32_t)(R32((uint32_t)(0x622da4u))); /* mov eax, dword ptr [0x100a2da4] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_00585d31; /* jne 0x585d31 */
L_00585bf8:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00585cf5; /* ja 0x585cf5 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00585c0bu); f_00586189(c); /* call 0x586189 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 4], edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00585c15u); f_005883a1(c); /* call 0x5883a1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x28], eax */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (c->zf) goto L_00585cc5; /* je 0x585cc5 */
    (void)sub32(c, c->esi, R32((uint32_t)(0x622d9cu))); /* cmp esi, dword ptr [0x100a2d9c] */
    if ((!c->cf && !c->zf)) goto L_00585c75; /* ja 0x585c75 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00585c31u); f_00588baa(c); /* call 0x588baa */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00585c3d; /* je 0x585c3d */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x24], ebx */
    goto L_00585c75; /* jmp 0x585c75 */
L_00585c3d:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00585c43u); f_005886f5(c); /* call 0x5886f5 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (c->zf) goto L_00585c75; /* je 0x585c75 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xfffffffcu))); /* mov eax, dword ptr [ebx - 4] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00585c58; /* jb 0x585c58 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00585c58:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00585c62u); f_00589590(c); /* call 0x589590 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00585c68u); f_005883a1(c); /* call 0x5883a1 */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x28], eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00585c72u); f_005883cc(c); /* call 0x5883cc */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00585c75:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), c->edi); /* cmp dword ptr [ebp - 0x24], edi */
    if (!c->zf) goto L_00585cc5; /* jne 0x585cc5 */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_00585c84; /* jne 0x585c84 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_00585c84:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0x622da0u)); PUSH32(c, v_); } /* push dword ptr [0x100a2da0] */
    { uint32_t t_ = R32((uint32_t)(0x58d03cu)); PUSH32(c, 0x00585c9bu); call_indirect(c, t_); } /* call dword ptr [0x1000d03c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (c->zf) goto L_00585cc5; /* je 0x585cc5 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xfffffffcu))); /* mov eax, dword ptr [ebx - 4] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00585caf; /* jb 0x585caf */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00585caf:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00585cb9u); f_00589590(c); /* call 0x589590 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x28] */
    PUSH32(c, 0x00585cc2u); f_005883cc(c); /* call 0x5883cc */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
L_00585cc5:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00585cceu); f_00585d28(c); /* call 0x585d28 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), c->edi); /* cmp dword ptr [ebp - 0x28], edi */
    if (!c->zf) goto L_00585cf5; /* jne 0x585cf5 */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_00585cda; /* jne 0x585cda */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00585cda:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0x622da0u)); PUSH32(c, v_); } /* push dword ptr [0x100a2da0] */
    { uint32_t t_ = R32((uint32_t)(0x58d038u)); PUSH32(c, 0x00585cf2u); call_indirect(c, t_); } /* call dword ptr [0x1000d038] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_00585cf5:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_00585ebd; /* jne 0x585ebd */
    (void)sub32(c, R32((uint32_t)(0x621988u)), c->edi); /* cmp dword ptr [0x100a1988], edi */
    if (c->zf) goto L_00585ebd; /* je 0x585ebd */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00585d12u); f_0058956d(c); /* call 0x58956d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00585bf8; /* jne 0x585bf8 */
    goto L_00585ebb; /* jmp 0x585ebb */
L_00585d31:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00585e81; /* jne 0x585e81 */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00585d51; /* ja 0x585d51 */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if ((c->cf || c->zf)) goto L_00585d4b; /* jbe 0x585d4b */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    goto L_00585d4e; /* jmp 0x585d4e */
L_00585d4b:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00585d4e:;
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_00585d51:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00585e50; /* ja 0x585e50 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00585d64u); f_00586189(c); /* call 0x586189 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00585d7au); f_005890fc(c); /* call 0x5890fc */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00585e34; /* je 0x585e34 */
    (void)sub32(c, c->esi, R32((uint32_t)(0x59077cu))); /* cmp esi, dword ptr [0x1001077c] */
    if (!c->cf) goto L_00585dee; /* jae 0x585dee */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 4)); /* shr ebx, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00585da4u); f_005894c4(c); /* call 0x5894c4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00585db3; /* je 0x585db3 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_00585deb; /* jmp 0x585deb */
L_00585db3:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00585db9u); f_00589198(c); /* call 0x589198 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00585deb; /* je 0x585deb */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00585dd0; /* jb 0x585dd0 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00585dd0:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00585ddcu); f_00589590(c); /* call 0x589590 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00585de8u); f_00589153(c); /* call 0x589153 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00585deb:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00585dee:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00585e47; /* jne 0x585e47 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x622da0u)); PUSH32(c, v_); } /* push dword ptr [0x100a2da0] */
    { uint32_t t_ = R32((uint32_t)(0x58d03cu)); PUSH32(c, 0x00585e03u); call_indirect(c, t_); } /* call dword ptr [0x1000d03c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00585e47; /* je 0x585e47 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00585e19; /* jb 0x585e19 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00585e19:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00585e23u); f_00589590(c); /* call 0x589590 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00585e2fu); f_00589153(c); /* call 0x589153 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00585e47; /* jmp 0x585e47 */
L_00585e34:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x622da0u)); PUSH32(c, v_); } /* push dword ptr [0x100a2da0] */
    { uint32_t t_ = R32((uint32_t)(0x58d038u)); PUSH32(c, 0x00585e44u); call_indirect(c, t_); } /* call dword ptr [0x1000d038] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_00585e47:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00585e50u); f_00585e76(c); /* call 0x585e76 */
L_00585e50:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_00585ebd; /* jne 0x585ebd */
    (void)sub32(c, R32((uint32_t)(0x621988u)), c->edi); /* cmp dword ptr [0x100a1988], edi */
    if (c->zf) goto L_00585ebd; /* je 0x585ebd */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00585e65u); f_0058956d(c); /* call 0x58956d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00585d51; /* jne 0x585d51 */
    goto L_00585ebb; /* jmp 0x585ebb */
L_00585e81:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00585ea4; /* ja 0x585ea4 */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_00585e8f; /* jne 0x585e8f */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00585e8f:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0x622da0u)); PUSH32(c, v_); } /* push dword ptr [0x100a2da0] */
    { uint32_t t_ = R32((uint32_t)(0x58d038u)); PUSH32(c, 0x00585ea4u); call_indirect(c, t_); } /* call dword ptr [0x1000d038] */
L_00585ea4:;
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_00585ebd; /* jne 0x585ebd */
    (void)sub32(c, R32((uint32_t)(0x621988u)), c->edi); /* cmp dword ptr [0x100a1988], edi */
    if (c->zf) goto L_00585ebd; /* je 0x585ebd */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00585eb6u); f_0058956d(c); /* call 0x58956d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00585e81; /* jne 0x585e81 */
L_00585ebb:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00585ebd:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00585d20(CPU *c) { /* PTR_00585d20 */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    { f_00585d28(c); return; }
}

void f_00585d28(CPU *c) { /* FUN_10005d28 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00585d2fu); f_005861ea(c); /* call 0x5861ea */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00585d31(CPU *c) { /* PTR_00585d31 */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) { f_00585e81(c); return; } /* jne 0x585e81 */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00585d51; /* ja 0x585d51 */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if ((c->cf || c->zf)) goto L_00585d4b; /* jbe 0x585d4b */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    goto L_00585d4e; /* jmp 0x585d4e */
L_00585d4b:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00585d4e:;
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_00585d51:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00585e50; /* ja 0x585e50 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00585d64u); f_00586189(c); /* call 0x586189 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00585d7au); f_005890fc(c); /* call 0x5890fc */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00585e34; /* je 0x585e34 */
    (void)sub32(c, c->esi, R32((uint32_t)(0x59077cu))); /* cmp esi, dword ptr [0x1001077c] */
    if (!c->cf) goto L_00585dee; /* jae 0x585dee */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 4)); /* shr ebx, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00585da4u); f_005894c4(c); /* call 0x5894c4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00585db3; /* je 0x585db3 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_00585deb; /* jmp 0x585deb */
L_00585db3:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00585db9u); f_00589198(c); /* call 0x589198 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00585deb; /* je 0x585deb */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00585dd0; /* jb 0x585dd0 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00585dd0:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00585ddcu); f_00589590(c); /* call 0x589590 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00585de8u); f_00589153(c); /* call 0x589153 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00585deb:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00585dee:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00585e47; /* jne 0x585e47 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x622da0u)); PUSH32(c, v_); } /* push dword ptr [0x100a2da0] */
    { uint32_t t_ = R32((uint32_t)(0x58d03cu)); PUSH32(c, 0x00585e03u); call_indirect(c, t_); } /* call dword ptr [0x1000d03c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00585e47; /* je 0x585e47 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00585e19; /* jb 0x585e19 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00585e19:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00585e23u); f_00589590(c); /* call 0x589590 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00585e2fu); f_00589153(c); /* call 0x589153 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00585e47; /* jmp 0x585e47 */
L_00585e34:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x622da0u)); PUSH32(c, v_); } /* push dword ptr [0x100a2da0] */
    { uint32_t t_ = R32((uint32_t)(0x58d038u)); PUSH32(c, 0x00585e44u); call_indirect(c, t_); } /* call dword ptr [0x1000d038] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_00585e47:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00585e50u); f_00585e76(c); /* call 0x585e76 */
L_00585e50:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00585ebd(c); return; } /* jne 0x585ebd */
    (void)sub32(c, R32((uint32_t)(0x621988u)), c->edi); /* cmp dword ptr [0x100a1988], edi */
    if (c->zf) { f_00585ebd(c); return; } /* je 0x585ebd */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00585e65u); f_0058956d(c); /* call 0x58956d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00585d51; /* jne 0x585d51 */
    { f_00585ebb(c); return; } /* jmp 0x585ebb */
}

void f_00585d4b(CPU *c) { /* PTR_00585d4b */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_00585d51:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00585e50; /* ja 0x585e50 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00585d64u); f_00586189(c); /* call 0x586189 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00585d7au); f_005890fc(c); /* call 0x5890fc */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00585e34; /* je 0x585e34 */
    (void)sub32(c, c->esi, R32((uint32_t)(0x59077cu))); /* cmp esi, dword ptr [0x1001077c] */
    if (!c->cf) goto L_00585dee; /* jae 0x585dee */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 4)); /* shr ebx, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00585da4u); f_005894c4(c); /* call 0x5894c4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00585db3; /* je 0x585db3 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_00585deb; /* jmp 0x585deb */
L_00585db3:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00585db9u); f_00589198(c); /* call 0x589198 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00585deb; /* je 0x585deb */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00585dd0; /* jb 0x585dd0 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00585dd0:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00585ddcu); f_00589590(c); /* call 0x589590 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00585de8u); f_00589153(c); /* call 0x589153 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00585deb:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00585dee:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00585e47; /* jne 0x585e47 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x622da0u)); PUSH32(c, v_); } /* push dword ptr [0x100a2da0] */
    { uint32_t t_ = R32((uint32_t)(0x58d03cu)); PUSH32(c, 0x00585e03u); call_indirect(c, t_); } /* call dword ptr [0x1000d03c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00585e47; /* je 0x585e47 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00585e19; /* jb 0x585e19 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00585e19:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00585e23u); f_00589590(c); /* call 0x589590 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00585e2fu); f_00589153(c); /* call 0x589153 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00585e47; /* jmp 0x585e47 */
L_00585e34:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x622da0u)); PUSH32(c, v_); } /* push dword ptr [0x100a2da0] */
    { uint32_t t_ = R32((uint32_t)(0x58d038u)); PUSH32(c, 0x00585e44u); call_indirect(c, t_); } /* call dword ptr [0x1000d038] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_00585e47:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00585e50u); f_00585e76(c); /* call 0x585e76 */
L_00585e50:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00585ebd(c); return; } /* jne 0x585ebd */
    (void)sub32(c, R32((uint32_t)(0x621988u)), c->edi); /* cmp dword ptr [0x100a1988], edi */
    if (c->zf) { f_00585ebd(c); return; } /* je 0x585ebd */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00585e65u); f_0058956d(c); /* call 0x58956d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00585d51; /* jne 0x585d51 */
    { f_00585ebb(c); return; } /* jmp 0x585ebb */
}

void f_00585d4e(CPU *c) { /* PTR_00585d4e */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_00585d51:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00585e50; /* ja 0x585e50 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00585d64u); f_00586189(c); /* call 0x586189 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00585d7au); f_005890fc(c); /* call 0x5890fc */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00585e34; /* je 0x585e34 */
    (void)sub32(c, c->esi, R32((uint32_t)(0x59077cu))); /* cmp esi, dword ptr [0x1001077c] */
    if (!c->cf) goto L_00585dee; /* jae 0x585dee */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 4)); /* shr ebx, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00585da4u); f_005894c4(c); /* call 0x5894c4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00585db3; /* je 0x585db3 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_00585deb; /* jmp 0x585deb */
L_00585db3:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00585db9u); f_00589198(c); /* call 0x589198 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00585deb; /* je 0x585deb */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00585dd0; /* jb 0x585dd0 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00585dd0:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00585ddcu); f_00589590(c); /* call 0x589590 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00585de8u); f_00589153(c); /* call 0x589153 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00585deb:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00585dee:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00585e47; /* jne 0x585e47 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x622da0u)); PUSH32(c, v_); } /* push dword ptr [0x100a2da0] */
    { uint32_t t_ = R32((uint32_t)(0x58d03cu)); PUSH32(c, 0x00585e03u); call_indirect(c, t_); } /* call dword ptr [0x1000d03c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00585e47; /* je 0x585e47 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00585e19; /* jb 0x585e19 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00585e19:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00585e23u); f_00589590(c); /* call 0x589590 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00585e2fu); f_00589153(c); /* call 0x589153 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00585e47; /* jmp 0x585e47 */
L_00585e34:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x622da0u)); PUSH32(c, v_); } /* push dword ptr [0x100a2da0] */
    { uint32_t t_ = R32((uint32_t)(0x58d038u)); PUSH32(c, 0x00585e44u); call_indirect(c, t_); } /* call dword ptr [0x1000d038] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_00585e47:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00585e50u); f_00585e76(c); /* call 0x585e76 */
L_00585e50:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00585ebd(c); return; } /* jne 0x585ebd */
    (void)sub32(c, R32((uint32_t)(0x621988u)), c->edi); /* cmp dword ptr [0x100a1988], edi */
    if (c->zf) { f_00585ebd(c); return; } /* je 0x585ebd */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00585e65u); f_0058956d(c); /* call 0x58956d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00585d51; /* jne 0x585d51 */
    { f_00585ebb(c); return; } /* jmp 0x585ebb */
}

void f_00585d51(CPU *c) { /* PTR_00585d51 */
    PREEMPT_POLL(c);
L_00585d51:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00585e50; /* ja 0x585e50 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00585d64u); f_00586189(c); /* call 0x586189 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00585d7au); f_005890fc(c); /* call 0x5890fc */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00585e34; /* je 0x585e34 */
    (void)sub32(c, c->esi, R32((uint32_t)(0x59077cu))); /* cmp esi, dword ptr [0x1001077c] */
    if (!c->cf) goto L_00585dee; /* jae 0x585dee */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 4)); /* shr ebx, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00585da4u); f_005894c4(c); /* call 0x5894c4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00585db3; /* je 0x585db3 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_00585deb; /* jmp 0x585deb */
L_00585db3:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00585db9u); f_00589198(c); /* call 0x589198 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00585deb; /* je 0x585deb */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00585dd0; /* jb 0x585dd0 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00585dd0:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00585ddcu); f_00589590(c); /* call 0x589590 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00585de8u); f_00589153(c); /* call 0x589153 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00585deb:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00585dee:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00585e47; /* jne 0x585e47 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x622da0u)); PUSH32(c, v_); } /* push dword ptr [0x100a2da0] */
    { uint32_t t_ = R32((uint32_t)(0x58d03cu)); PUSH32(c, 0x00585e03u); call_indirect(c, t_); } /* call dword ptr [0x1000d03c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00585e47; /* je 0x585e47 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00585e19; /* jb 0x585e19 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00585e19:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00585e23u); f_00589590(c); /* call 0x589590 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00585e2fu); f_00589153(c); /* call 0x589153 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00585e47; /* jmp 0x585e47 */
L_00585e34:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x622da0u)); PUSH32(c, v_); } /* push dword ptr [0x100a2da0] */
    { uint32_t t_ = R32((uint32_t)(0x58d038u)); PUSH32(c, 0x00585e44u); call_indirect(c, t_); } /* call dword ptr [0x1000d038] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_00585e47:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00585e50u); f_00585e76(c); /* call 0x585e76 */
L_00585e50:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00585ebd(c); return; } /* jne 0x585ebd */
    (void)sub32(c, R32((uint32_t)(0x621988u)), c->edi); /* cmp dword ptr [0x100a1988], edi */
    if (c->zf) { f_00585ebd(c); return; } /* je 0x585ebd */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00585e65u); f_0058956d(c); /* call 0x58956d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00585d51; /* jne 0x585d51 */
    { f_00585ebb(c); return; } /* jmp 0x585ebb */
}

void f_00585db3(CPU *c) { /* PTR_00585db3 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00585db9u); f_00589198(c); /* call 0x589198 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00585deb; /* je 0x585deb */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00585dd0; /* jb 0x585dd0 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00585dd0:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00585ddcu); f_00589590(c); /* call 0x589590 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00585de8u); f_00589153(c); /* call 0x589153 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00585deb:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00585e47; /* jne 0x585e47 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x622da0u)); PUSH32(c, v_); } /* push dword ptr [0x100a2da0] */
    { uint32_t t_ = R32((uint32_t)(0x58d03cu)); PUSH32(c, 0x00585e03u); call_indirect(c, t_); } /* call dword ptr [0x1000d03c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00585e47; /* je 0x585e47 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00585e19; /* jb 0x585e19 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00585e19:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00585e23u); f_00589590(c); /* call 0x589590 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00585e2fu); f_00589153(c); /* call 0x589153 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00585e47; /* jmp 0x585e47 */
L_00585e47:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00585e50u); f_00585e76(c); /* call 0x585e76 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00585ebd(c); return; } /* jne 0x585ebd */
    (void)sub32(c, R32((uint32_t)(0x621988u)), c->edi); /* cmp dword ptr [0x100a1988], edi */
    if (c->zf) { f_00585ebd(c); return; } /* je 0x585ebd */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00585e65u); f_0058956d(c); /* call 0x58956d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00585d51(c); return; } /* jne 0x585d51 */
    { f_00585ebb(c); return; } /* jmp 0x585ebb */
}

void f_00585dd0(CPU *c) { /* PTR_00585dd0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00585ddcu); f_00589590(c); /* call 0x589590 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00585de8u); f_00589153(c); /* call 0x589153 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00585e47; /* jne 0x585e47 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x622da0u)); PUSH32(c, v_); } /* push dword ptr [0x100a2da0] */
    { uint32_t t_ = R32((uint32_t)(0x58d03cu)); PUSH32(c, 0x00585e03u); call_indirect(c, t_); } /* call dword ptr [0x1000d03c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00585e47; /* je 0x585e47 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00585e19; /* jb 0x585e19 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00585e19:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00585e23u); f_00589590(c); /* call 0x589590 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00585e2fu); f_00589153(c); /* call 0x589153 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00585e47; /* jmp 0x585e47 */
L_00585e47:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00585e50u); f_00585e76(c); /* call 0x585e76 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00585ebd(c); return; } /* jne 0x585ebd */
    (void)sub32(c, R32((uint32_t)(0x621988u)), c->edi); /* cmp dword ptr [0x100a1988], edi */
    if (c->zf) { f_00585ebd(c); return; } /* je 0x585ebd */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00585e65u); f_0058956d(c); /* call 0x58956d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00585d51(c); return; } /* jne 0x585d51 */
    { f_00585ebb(c); return; } /* jmp 0x585ebb */
}

void f_00585deb(CPU *c) { /* PTR_00585deb */
    PREEMPT_POLL(c);
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00585e47; /* jne 0x585e47 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x622da0u)); PUSH32(c, v_); } /* push dword ptr [0x100a2da0] */
    { uint32_t t_ = R32((uint32_t)(0x58d03cu)); PUSH32(c, 0x00585e03u); call_indirect(c, t_); } /* call dword ptr [0x1000d03c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00585e47; /* je 0x585e47 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00585e19; /* jb 0x585e19 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00585e19:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00585e23u); f_00589590(c); /* call 0x589590 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00585e2fu); f_00589153(c); /* call 0x589153 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00585e47; /* jmp 0x585e47 */
L_00585e47:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00585e50u); f_00585e76(c); /* call 0x585e76 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00585ebd(c); return; } /* jne 0x585ebd */
    (void)sub32(c, R32((uint32_t)(0x621988u)), c->edi); /* cmp dword ptr [0x100a1988], edi */
    if (c->zf) { f_00585ebd(c); return; } /* je 0x585ebd */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00585e65u); f_0058956d(c); /* call 0x58956d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00585d51(c); return; } /* jne 0x585d51 */
    { f_00585ebb(c); return; } /* jmp 0x585ebb */
}

void f_00585dee(CPU *c) { /* PTR_00585dee */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00585e47; /* jne 0x585e47 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x622da0u)); PUSH32(c, v_); } /* push dword ptr [0x100a2da0] */
    { uint32_t t_ = R32((uint32_t)(0x58d03cu)); PUSH32(c, 0x00585e03u); call_indirect(c, t_); } /* call dword ptr [0x1000d03c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00585e47; /* je 0x585e47 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00585e19; /* jb 0x585e19 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00585e19:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00585e23u); f_00589590(c); /* call 0x589590 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00585e2fu); f_00589153(c); /* call 0x589153 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00585e47; /* jmp 0x585e47 */
L_00585e47:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00585e50u); f_00585e76(c); /* call 0x585e76 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00585ebd(c); return; } /* jne 0x585ebd */
    (void)sub32(c, R32((uint32_t)(0x621988u)), c->edi); /* cmp dword ptr [0x100a1988], edi */
    if (c->zf) { f_00585ebd(c); return; } /* je 0x585ebd */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00585e65u); f_0058956d(c); /* call 0x58956d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00585d51(c); return; } /* jne 0x585d51 */
    { f_00585ebb(c); return; } /* jmp 0x585ebb */
}

void f_00585e19(CPU *c) { /* PTR_00585e19 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00585e23u); f_00589590(c); /* call 0x589590 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00585e2fu); f_00589153(c); /* call 0x589153 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00585e47; /* jmp 0x585e47 */
L_00585e47:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00585e50u); f_00585e76(c); /* call 0x585e76 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00585ebd(c); return; } /* jne 0x585ebd */
    (void)sub32(c, R32((uint32_t)(0x621988u)), c->edi); /* cmp dword ptr [0x100a1988], edi */
    if (c->zf) { f_00585ebd(c); return; } /* je 0x585ebd */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00585e65u); f_0058956d(c); /* call 0x58956d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00585d51(c); return; } /* jne 0x585d51 */
    { f_00585ebb(c); return; } /* jmp 0x585ebb */
}

void f_00585e34(CPU *c) { /* PTR_00585e34 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x622da0u)); PUSH32(c, v_); } /* push dword ptr [0x100a2da0] */
    { uint32_t t_ = R32((uint32_t)(0x58d038u)); PUSH32(c, 0x00585e44u); call_indirect(c, t_); } /* call dword ptr [0x1000d038] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00585e50u); f_00585e76(c); /* call 0x585e76 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00585ebd(c); return; } /* jne 0x585ebd */
    (void)sub32(c, R32((uint32_t)(0x621988u)), c->edi); /* cmp dword ptr [0x100a1988], edi */
    if (c->zf) { f_00585ebd(c); return; } /* je 0x585ebd */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00585e65u); f_0058956d(c); /* call 0x58956d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00585d51(c); return; } /* jne 0x585d51 */
    { f_00585ebb(c); return; } /* jmp 0x585ebb */
}

void f_00585e47(CPU *c) { /* PTR_00585e47 */
    PREEMPT_POLL(c);
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00585e50u); f_00585e76(c); /* call 0x585e76 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00585ebd(c); return; } /* jne 0x585ebd */
    (void)sub32(c, R32((uint32_t)(0x621988u)), c->edi); /* cmp dword ptr [0x100a1988], edi */
    if (c->zf) { f_00585ebd(c); return; } /* je 0x585ebd */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00585e65u); f_0058956d(c); /* call 0x58956d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00585d51(c); return; } /* jne 0x585d51 */
    { f_00585ebb(c); return; } /* jmp 0x585ebb */
}

void f_00585e50(CPU *c) { /* PTR_00585e50 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00585ebd(c); return; } /* jne 0x585ebd */
    (void)sub32(c, R32((uint32_t)(0x621988u)), c->edi); /* cmp dword ptr [0x100a1988], edi */
    if (c->zf) { f_00585ebd(c); return; } /* je 0x585ebd */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00585e65u); f_0058956d(c); /* call 0x58956d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00585d51(c); return; } /* jne 0x585d51 */
    { f_00585ebb(c); return; } /* jmp 0x585ebb */
}

void f_00585e70(CPU *c) { /* PTR_00585e70 */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    { f_00585e76(c); return; }
}

void f_00585e76(CPU *c) { /* FUN_10005e76 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00585e7du); f_005861ea(c); /* call 0x5861ea */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    c->esp += 4; return; /* ret  */
}

void f_00585e81(CPU *c) { /* PTR_00585e81 */
    PREEMPT_POLL(c);
L_00585e81:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00585ea4; /* ja 0x585ea4 */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_00585e8f; /* jne 0x585e8f */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00585e8f:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0x622da0u)); PUSH32(c, v_); } /* push dword ptr [0x100a2da0] */
    { uint32_t t_ = R32((uint32_t)(0x58d038u)); PUSH32(c, 0x00585ea4u); call_indirect(c, t_); } /* call dword ptr [0x1000d038] */
L_00585ea4:;
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_00585ebd; /* jne 0x585ebd */
    (void)sub32(c, R32((uint32_t)(0x621988u)), c->edi); /* cmp dword ptr [0x100a1988], edi */
    if (c->zf) goto L_00585ebd; /* je 0x585ebd */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00585eb6u); f_0058956d(c); /* call 0x58956d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00585e81; /* jne 0x585e81 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00585ebd:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00585e8f(CPU *c) { /* PTR_00585e8f */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0x622da0u)); PUSH32(c, v_); } /* push dword ptr [0x100a2da0] */
    { uint32_t t_ = R32((uint32_t)(0x58d038u)); PUSH32(c, 0x00585ea4u); call_indirect(c, t_); } /* call dword ptr [0x1000d038] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_00585ebd; /* jne 0x585ebd */
    (void)sub32(c, R32((uint32_t)(0x621988u)), c->edi); /* cmp dword ptr [0x100a1988], edi */
    if (c->zf) goto L_00585ebd; /* je 0x585ebd */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00585eb6u); f_0058956d(c); /* call 0x58956d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00585e81(c); return; } /* jne 0x585e81 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00585ebd:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00585ea4(CPU *c) { /* PTR_00585ea4 */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_00585ebd; /* jne 0x585ebd */
    (void)sub32(c, R32((uint32_t)(0x621988u)), c->edi); /* cmp dword ptr [0x100a1988], edi */
    if (c->zf) goto L_00585ebd; /* je 0x585ebd */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00585eb6u); f_0058956d(c); /* call 0x58956d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00585e81(c); return; } /* jne 0x585e81 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00585ebd:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00585ebb(CPU *c) { /* PTR_00585ebb */
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

void f_00585ebd(CPU *c) { /* PTR_00585ebd */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00585ecc(CPU *c) { /* FUN_10005ecc */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x58d270u; PUSH32(c, v_); } /* push 0x1000d270 */
    { uint32_t v_ = 0x587df8u; PUSH32(c, v_); } /* push 0x10007df8 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x1cu)); /* sub esp, 0x1c */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(0x622da4u))); /* mov eax, dword ptr [0x100a2da4] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_00585f3f; /* jne 0x585f3f */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00585f00u); f_00586189(c); /* call 0x586189 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00585f0eu); f_005883a1(c); /* call 0x5883a1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00585f21; /* je 0x585f21 */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0xfffffffcu))); /* mov esi, dword ptr [esi - 4] */
    c->esi = (uint32_t)(sub32(c, c->esi, (uint32_t)0x9u)); /* sub esi, 9 */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x20], esi */
    goto L_00585f24; /* jmp 0x585f24 */
L_00585f21:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
L_00585f24:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00585f2du); f_00585f36(c); /* call 0x585f36 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x1c], 0 */
    goto L_00585f88; /* jmp 0x585f88 */
L_00585f3f:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00585f8a; /* jne 0x585f8a */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00585f4bu); f_00586189(c); /* call 0x586189 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffdcu)); /* lea eax, [ebp - 0x24] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00585f63u); f_005890fc(c); /* call 0x5890fc */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x28], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00585f78; /* je 0x585f78 */
    c->esi = (uint32_t)((uint32_t)R8((uint32_t)(c->eax))); /* movzx esi, byte ptr [eax] */
    c->esi = (uint32_t)(shl32(c, c->esi, 4)); /* shl esi, 4 */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x20], esi */
    goto L_00585f7b; /* jmp 0x585f7b */
L_00585f78:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
L_00585f7b:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00585f84u); f_00585fb1(c); /* call 0x585fb1 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x28], 0 */
L_00585f88:;
    if (!c->zf) goto L_00585f9d; /* jne 0x585f9d */
L_00585f8a:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x622da0u)); PUSH32(c, v_); } /* push dword ptr [0x100a2da0] */
    { uint32_t t_ = R32((uint32_t)(0x58d040u)); PUSH32(c, 0x00585f9bu); call_indirect(c, t_); } /* call dword ptr [0x1000d040] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_00585f9d:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00585f33(CPU *c) { /* PTR_00585f33 */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
    { f_00585f36(c); return; }
}

void f_00585f36(CPU *c) { /* FUN_10005f36 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00585f3du); f_005861ea(c); /* call 0x5861ea */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00585f3f(CPU *c) { /* PTR_00585f3f */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00585f8a; /* jne 0x585f8a */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00585f4bu); f_00586189(c); /* call 0x586189 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffdcu)); /* lea eax, [ebp - 0x24] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00585f63u); f_005890fc(c); /* call 0x5890fc */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x28], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00585f78; /* je 0x585f78 */
    c->esi = (uint32_t)((uint32_t)R8((uint32_t)(c->eax))); /* movzx esi, byte ptr [eax] */
    c->esi = (uint32_t)(shl32(c, c->esi, 4)); /* shl esi, 4 */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x20], esi */
    goto L_00585f7b; /* jmp 0x585f7b */
L_00585f78:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
L_00585f7b:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00585f84u); f_00585fb1(c); /* call 0x585fb1 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x28], 0 */
    if (!c->zf) goto L_00585f9d; /* jne 0x585f9d */
L_00585f8a:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x622da0u)); PUSH32(c, v_); } /* push dword ptr [0x100a2da0] */
    { uint32_t t_ = R32((uint32_t)(0x58d040u)); PUSH32(c, 0x00585f9bu); call_indirect(c, t_); } /* call dword ptr [0x1000d040] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_00585f9d:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00585f78(CPU *c) { /* PTR_00585f78 */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00585f84u); f_00585fb1(c); /* call 0x585fb1 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x28], 0 */
    if (!c->zf) goto L_00585f9d; /* jne 0x585f9d */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x622da0u)); PUSH32(c, v_); } /* push dword ptr [0x100a2da0] */
    { uint32_t t_ = R32((uint32_t)(0x58d040u)); PUSH32(c, 0x00585f9bu); call_indirect(c, t_); } /* call dword ptr [0x1000d040] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_00585f9d:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00585f7b(CPU *c) { /* PTR_00585f7b */
    PREEMPT_POLL(c);
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00585f84u); f_00585fb1(c); /* call 0x585fb1 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x28], 0 */
    if (!c->zf) goto L_00585f9d; /* jne 0x585f9d */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x622da0u)); PUSH32(c, v_); } /* push dword ptr [0x100a2da0] */
    { uint32_t t_ = R32((uint32_t)(0x58d040u)); PUSH32(c, 0x00585f9bu); call_indirect(c, t_); } /* call dword ptr [0x1000d040] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_00585f9d:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00585f88(CPU *c) { /* PTR_00585f88 */
    PREEMPT_POLL(c);
    if (!c->zf) goto L_00585f9d; /* jne 0x585f9d */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x622da0u)); PUSH32(c, v_); } /* push dword ptr [0x100a2da0] */
    { uint32_t t_ = R32((uint32_t)(0x58d040u)); PUSH32(c, 0x00585f9bu); call_indirect(c, t_); } /* call dword ptr [0x1000d040] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_00585f9d:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00585f8a(CPU *c) { /* PTR_00585f8a */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x622da0u)); PUSH32(c, v_); } /* push dword ptr [0x100a2da0] */
    { uint32_t t_ = R32((uint32_t)(0x58d040u)); PUSH32(c, 0x00585f9bu); call_indirect(c, t_); } /* call dword ptr [0x1000d040] */
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

void f_00585f9d(CPU *c) { /* PTR_00585f9d */
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

void f_00585fae(CPU *c) { /* PTR_00585fae */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
    { f_00585fb1(c); return; }
}

void f_00585fb1(CPU *c) { /* FUN_10005fb1 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00585fb8u); f_005861ea(c); /* call 0x5861ea */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00585fba(CPU *c) { /* _malloc */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(0x621988u)); PUSH32(c, v_); } /* push dword ptr [0x100a1988] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    PUSH32(c, 0x00585fc9u); f_00585fcc(c); /* call 0x585fcc */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00585fcc(CPU *c) { /* __nh_malloc */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->esp + 0x4u)), (uint32_t)0xffffffe0u); /* cmp dword ptr [esp + 4], -0x20 */
    if ((!c->cf && !c->zf)) goto L_00585ff5; /* ja 0x585ff5 */
L_00585fd3:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    PUSH32(c, 0x00585fdcu); f_00585ff8(c); /* call 0x585ff8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00585ff7; /* jne 0x585ff7 */
    (void)sub32(c, R32((uint32_t)(c->esp + 0x8u)), c->eax); /* cmp dword ptr [esp + 8], eax */
    if (c->zf) goto L_00585ff7; /* je 0x585ff7 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    PUSH32(c, 0x00585ff0u); f_0058956d(c); /* call 0x58956d */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00585fd3; /* jne 0x585fd3 */
L_00585ff5:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00585ff7:;
    c->esp += 4; return; /* ret  */
}

void f_00585ff8(CPU *c) { /* FUN_10005ff8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x58d288u; PUSH32(c, v_); } /* push 0x1000d288 */
    { uint32_t v_ = 0x587df8u; PUSH32(c, v_); } /* push 0x10007df8 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(0x622da4u))); /* mov eax, dword ptr [0x100a2da4] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_00586068; /* jne 0x586068 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    (void)sub32(c, c->esi, R32((uint32_t)(0x622d9cu))); /* cmp esi, dword ptr [0x100a2d9c] */
    if ((!c->cf && !c->zf)) goto L_005860c7; /* ja 0x5860c7 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x0058603bu); f_00586189(c); /* call 0x586189 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00586046u); f_005886f5(c); /* call 0x5886f5 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00586053u); f_0058605f(c); /* call 0x58605f */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_005860c7; /* je 0x5860c7 */
    goto L_005860e5; /* jmp 0x5860e5 */
L_00586068:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_005860c7; /* jne 0x5860c7 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0058607c; /* je 0x58607c */
    c->esi = (uint32_t)((uint32_t)(c->eax + 0xfu)); /* lea esi, [eax + 0xf] */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    goto L_0058607f; /* jmp 0x58607f */
L_0058607c:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_0058607f:;
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
    (void)sub32(c, c->esi, R32((uint32_t)(0x59077cu))); /* cmp esi, dword ptr [0x1001077c] */
    if ((!c->cf && !c->zf)) goto L_005860b8; /* ja 0x5860b8 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00586091u); f_00586189(c); /* call 0x586189 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x005860a4u); f_00589198(c); /* call 0x589198 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x005860b1u); f_005860be(c); /* call 0x5860be */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_005860e5; /* jne 0x5860e5 */
L_005860b8:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    goto L_005860d7; /* jmp 0x5860d7 */
L_005860c7:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_005860d1; /* jne 0x5860d1 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_005860d1:;
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xfu)); /* add eax, 0xf */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xf0u))); /* and al, 0xf0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
L_005860d7:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x622da0u)); PUSH32(c, v_); } /* push dword ptr [0x100a2da0] */
    { uint32_t t_ = R32((uint32_t)(0x58d03cu)); PUSH32(c, 0x005860e5u); call_indirect(c, t_); } /* call dword ptr [0x1000d03c] */
L_005860e5:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0058605f(CPU *c) { /* FUN_1000605f */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00586066u); f_005861ea(c); /* call 0x5861ea */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00586068(CPU *c) { /* PTR_00586068 */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) { f_005860c7(c); return; } /* jne 0x5860c7 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0058607c; /* je 0x58607c */
    c->esi = (uint32_t)((uint32_t)(c->eax + 0xfu)); /* lea esi, [eax + 0xf] */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    goto L_0058607f; /* jmp 0x58607f */
L_0058607c:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_0058607f:;
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
    (void)sub32(c, c->esi, R32((uint32_t)(0x59077cu))); /* cmp esi, dword ptr [0x1001077c] */
    if ((!c->cf && !c->zf)) goto L_005860b8; /* ja 0x5860b8 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00586091u); f_00586189(c); /* call 0x586189 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x005860a4u); f_00589198(c); /* call 0x589198 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x005860b1u); f_005860be(c); /* call 0x5860be */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_005860e5(c); return; } /* jne 0x5860e5 */
L_005860b8:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { f_005860d7(c); return; } /* jmp 0x5860d7 */
}

void f_0058607c(CPU *c) { /* PTR_0058607c */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
    (void)sub32(c, c->esi, R32((uint32_t)(0x59077cu))); /* cmp esi, dword ptr [0x1001077c] */
    if ((!c->cf && !c->zf)) goto L_005860b8; /* ja 0x5860b8 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00586091u); f_00586189(c); /* call 0x586189 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x005860a4u); f_00589198(c); /* call 0x589198 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x005860b1u); f_005860be(c); /* call 0x5860be */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_005860e5(c); return; } /* jne 0x5860e5 */
L_005860b8:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { f_005860d7(c); return; } /* jmp 0x5860d7 */
}

void f_0058607f(CPU *c) { /* PTR_0058607f */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
    (void)sub32(c, c->esi, R32((uint32_t)(0x59077cu))); /* cmp esi, dword ptr [0x1001077c] */
    if ((!c->cf && !c->zf)) goto L_005860b8; /* ja 0x5860b8 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00586091u); f_00586189(c); /* call 0x586189 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x005860a4u); f_00589198(c); /* call 0x589198 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x005860b1u); f_005860be(c); /* call 0x5860be */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_005860e5(c); return; } /* jne 0x5860e5 */
L_005860b8:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { f_005860d7(c); return; } /* jmp 0x5860d7 */
}

void f_005860b8(CPU *c) { /* PTR_005860b8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { f_005860d7(c); return; } /* jmp 0x5860d7 */
}

void f_005860bb(CPU *c) { /* PTR_005860bb */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    { f_005860be(c); return; }
}

void f_005860be(CPU *c) { /* FUN_100060be */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x005860c5u); f_005861ea(c); /* call 0x5861ea */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_005860c7(CPU *c) { /* PTR_005860c7 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_005860d1; /* jne 0x5860d1 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_005860d1:;
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xfu)); /* add eax, 0xf */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xf0u))); /* and al, 0xf0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x622da0u)); PUSH32(c, v_); } /* push dword ptr [0x100a2da0] */
    { uint32_t t_ = R32((uint32_t)(0x58d03cu)); PUSH32(c, 0x005860e5u); call_indirect(c, t_); } /* call dword ptr [0x1000d03c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_005860d1(CPU *c) { /* PTR_005860d1 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xfu)); /* add eax, 0xf */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xf0u))); /* and al, 0xf0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x622da0u)); PUSH32(c, v_); } /* push dword ptr [0x100a2da0] */
    { uint32_t t_ = R32((uint32_t)(0x58d03cu)); PUSH32(c, 0x005860e5u); call_indirect(c, t_); } /* call dword ptr [0x1000d03c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_005860d7(CPU *c) { /* PTR_005860d7 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x622da0u)); PUSH32(c, v_); } /* push dword ptr [0x100a2da0] */
    { uint32_t t_ = R32((uint32_t)(0x58d03cu)); PUSH32(c, 0x005860e5u); call_indirect(c, t_); } /* call dword ptr [0x1000d03c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_005860e5(CPU *c) { /* PTR_005860e5 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_005860f4(CPU *c) { /* FUN_100060f4 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(0x58d044u))); /* mov esi, dword ptr [0x1000d044] */
    { uint32_t v_ = R32((uint32_t)(0x58e34cu)); PUSH32(c, v_); } /* push dword ptr [0x1000e34c] */
    { uint32_t t_ = c->esi; PUSH32(c, 0x00586103u); call_indirect(c, t_); } /* call esi */
    { uint32_t v_ = R32((uint32_t)(0x58e33cu)); PUSH32(c, v_); } /* push dword ptr [0x1000e33c] */
    { uint32_t t_ = c->esi; PUSH32(c, 0x0058610bu); call_indirect(c, t_); } /* call esi */
    { uint32_t v_ = R32((uint32_t)(0x58e32cu)); PUSH32(c, v_); } /* push dword ptr [0x1000e32c] */
    { uint32_t t_ = c->esi; PUSH32(c, 0x00586113u); call_indirect(c, t_); } /* call esi */
    { uint32_t v_ = R32((uint32_t)(0x58e30cu)); PUSH32(c, v_); } /* push dword ptr [0x1000e30c] */
    { uint32_t t_ = c->esi; PUSH32(c, 0x0058611bu); call_indirect(c, t_); } /* call esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_0058611d(CPU *c) { /* FUN_1000611d */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(0x58d048u))); /* mov edi, dword ptr [0x1000d048] */
    c->esi = (uint32_t)((uint32_t)0x58e308u); /* mov esi, 0x1000e308 */
L_0058612a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0058615b; /* je 0x58615b */
    (void)sub32(c, c->esi, (uint32_t)0x58e34cu); /* cmp esi, 0x1000e34c */
    if (c->zf) goto L_0058615b; /* je 0x58615b */
    (void)sub32(c, c->esi, (uint32_t)0x58e33cu); /* cmp esi, 0x1000e33c */
    if (c->zf) goto L_0058615b; /* je 0x58615b */
    (void)sub32(c, c->esi, (uint32_t)0x58e32cu); /* cmp esi, 0x1000e32c */
    if (c->zf) goto L_0058615b; /* je 0x58615b */
    (void)sub32(c, c->esi, (uint32_t)0x58e30cu); /* cmp esi, 0x1000e30c */
    if (c->zf) goto L_0058615b; /* je 0x58615b */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00586153u); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    PUSH32(c, 0x0058615au); f_005861ff(c); /* call 0x5861ff */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_0058615b:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, c->esi, (uint32_t)0x58e3c8u); /* cmp esi, 0x1000e3c8 */
    if ((c->sf != c->of)) goto L_0058612a; /* jl 0x58612a */
    { uint32_t v_ = R32((uint32_t)(0x58e32cu)); PUSH32(c, v_); } /* push dword ptr [0x1000e32c] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x0058616eu); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = R32((uint32_t)(0x58e33cu)); PUSH32(c, v_); } /* push dword ptr [0x1000e33c] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00586176u); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = R32((uint32_t)(0x58e34cu)); PUSH32(c, v_); } /* push dword ptr [0x1000e34c] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x0058617eu); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = R32((uint32_t)(0x58e30cu)); PUSH32(c, v_); } /* push dword ptr [0x1000e30c] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00586186u); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00586189(CPU *c) { /* FUN_10006189 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    (void)sub32(c, R32((uint32_t)(c->eax * 4 + 0x58e308u)), (uint32_t)0x0u); /* cmp dword ptr [eax*4 + 0x1000e308], 0 */
    c->esi = (uint32_t)((uint32_t)(c->eax * 4 + 0x58e308u)); /* lea esi, [eax*4 + 0x1000e308] */
    if (!c->zf) goto L_005861df; /* jne 0x5861df */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    PUSH32(c, 0x005861a9u); f_00585fba(c); /* call 0x585fba */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (!c->zf) goto L_005861b8; /* jne 0x5861b8 */
    { uint32_t v_ = 0x11u; PUSH32(c, v_); } /* push 0x11 */
    PUSH32(c, 0x005861b7u); f_00584fa1(c); /* call 0x584fa1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_005861b8:;
    { uint32_t v_ = 0x11u; PUSH32(c, v_); } /* push 0x11 */
    PUSH32(c, 0x005861bfu); f_00586189(c); /* call 0x586189 */
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x0u); /* cmp dword ptr [esi], 0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_005861d0; /* jne 0x5861d0 */
    { uint32_t t_ = R32((uint32_t)(0x58d044u)); PUSH32(c, 0x005861ccu); call_indirect(c, t_); } /* call dword ptr [0x1000d044] */
    W32((uint32_t)(c->esi), (uint32_t)(c->edi)); /* mov dword ptr [esi], edi */
    goto L_005861d6; /* jmp 0x5861d6 */
L_005861d0:;
    PUSH32(c, 0x005861d5u); f_005861ff(c); /* call 0x5861ff */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_005861d6:;
    { uint32_t v_ = 0x11u; PUSH32(c, v_); } /* push 0x11 */
    PUSH32(c, 0x005861ddu); f_005861ea(c); /* call 0x5861ea */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_005861df:;
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(0x58d04cu)); PUSH32(c, 0x005861e7u); call_indirect(c, t_); } /* call dword ptr [0x1000d04c] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_005861ea(CPU *c) { /* FUN_100061ea */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->eax * 4 + 0x58e308u)); PUSH32(c, v_); } /* push dword ptr [eax*4 + 0x1000e308] */
    { uint32_t t_ = R32((uint32_t)(0x58d050u)); PUSH32(c, 0x005861fdu); call_indirect(c, t_); } /* call dword ptr [0x1000d050] */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_005861ff(CPU *c) { /* FUN_100061ff */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x58d2a0u; PUSH32(c, v_); } /* push 0x1000d2a0 */
    { uint32_t v_ = 0x587df8u; PUSH32(c, v_); } /* push 0x10007df8 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_005862d9; /* je 0x5862d9 */
    c->eax = (uint32_t)(R32((uint32_t)(0x622da4u))); /* mov eax, dword ptr [0x100a2da4] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_00586272; /* jne 0x586272 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x0058623eu); f_00586189(c); /* call 0x586189 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00586249u); f_005883a1(c); /* call 0x5883a1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0058625a; /* je 0x58625a */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00586258u); f_005883cc(c); /* call 0x5883cc */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_0058625a:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00586263u); f_00586269(c); /* call 0x586269 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x1c], 0 */
    goto L_005862ba; /* jmp 0x5862ba */
L_00586272:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_005862ca; /* jne 0x5862ca */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x0058627eu); f_00586189(c); /* call 0x586189 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe0u)); /* lea eax, [ebp - 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd8u)); /* lea eax, [ebp - 0x28] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00586294u); f_005890fc(c); /* call 0x5890fc */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_005862ad; /* je 0x5862ad */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x28] */
    PUSH32(c, 0x005862aau); f_00589153(c); /* call 0x589153 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_005862ad:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x005862b6u); f_005862c1(c); /* call 0x5862c1 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
L_005862ba:;
    if (!c->zf) goto L_005862d9; /* jne 0x5862d9 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    goto L_005862cb; /* jmp 0x5862cb */
L_005862ca:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
L_005862cb:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x622da0u)); PUSH32(c, v_); } /* push dword ptr [0x100a2da0] */
    { uint32_t t_ = R32((uint32_t)(0x58d054u)); PUSH32(c, 0x005862d9u); call_indirect(c, t_); } /* call dword ptr [0x1000d054] */
L_005862d9:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00586269(CPU *c) { /* FUN_10006269 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00586270u); f_005861ea(c); /* call 0x5861ea */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00586272(CPU *c) { /* PTR_00586272 */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) { f_005862ca(c); return; } /* jne 0x5862ca */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x0058627eu); f_00586189(c); /* call 0x586189 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe0u)); /* lea eax, [ebp - 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd8u)); /* lea eax, [ebp - 0x28] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00586294u); f_005890fc(c); /* call 0x5890fc */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_005862ad; /* je 0x5862ad */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x28] */
    PUSH32(c, 0x005862aau); f_00589153(c); /* call 0x589153 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_005862ad:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x005862b6u); f_005862c1(c); /* call 0x5862c1 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) { f_005862d9(c); return; } /* jne 0x5862d9 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { f_005862cb(c); return; } /* jmp 0x5862cb */
}

void f_005862ad(CPU *c) { /* PTR_005862ad */
    PREEMPT_POLL(c);
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x005862b6u); f_005862c1(c); /* call 0x5862c1 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) { f_005862d9(c); return; } /* jne 0x5862d9 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { f_005862cb(c); return; } /* jmp 0x5862cb */
}

void f_005862ba(CPU *c) { /* PTR_005862ba */
    PREEMPT_POLL(c);
    if (!c->zf) { f_005862d9(c); return; } /* jne 0x5862d9 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { f_005862cb(c); return; } /* jmp 0x5862cb */
}

void f_005862c1(CPU *c) { /* FUN_100062c1 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x005862c8u); f_005861ea(c); /* call 0x5861ea */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_005862ca(CPU *c) { /* PTR_005862ca */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x622da0u)); PUSH32(c, v_); } /* push dword ptr [0x100a2da0] */
    { uint32_t t_ = R32((uint32_t)(0x58d054u)); PUSH32(c, 0x005862d9u); call_indirect(c, t_); } /* call dword ptr [0x1000d054] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_005862cb(CPU *c) { /* PTR_005862cb */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x622da0u)); PUSH32(c, v_); } /* push dword ptr [0x100a2da0] */
    { uint32_t t_ = R32((uint32_t)(0x58d054u)); PUSH32(c, 0x005862d9u); call_indirect(c, t_); } /* call dword ptr [0x1000d054] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_005862d9(CPU *c) { /* PTR_005862d9 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_005862f0(CPU *c) { /* _strcmp */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u)); /* test edx, 3 */
    if (!c->zf) goto L_0058633c; /* jne 0x58633c */
L_00586300:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edx))); /* mov eax, dword ptr [edx] */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->ecx))); /* cmp al, byte ptr [ecx] */
    if (!c->zf) goto L_00586334; /* jne 0x586334 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00586330; /* je 0x586330 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), R8((uint32_t)(c->ecx + 0x1u))); /* cmp ah, byte ptr [ecx + 1] */
    if (!c->zf) goto L_00586334; /* jne 0x586334 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | ((uint8_t)(c->eax >> 8))))) << 8); /* or ah, ah */
    if (c->zf) goto L_00586330; /* je 0x586330 */
    c->eax = (uint32_t)(shr32(c, c->eax, 16)); /* shr eax, 0x10 */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->ecx + 0x2u))); /* cmp al, byte ptr [ecx + 2] */
    if (!c->zf) goto L_00586334; /* jne 0x586334 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00586330; /* je 0x586330 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), R8((uint32_t)(c->ecx + 0x3u))); /* cmp ah, byte ptr [ecx + 3] */
    if (!c->zf) goto L_00586334; /* jne 0x586334 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x4u)); /* add edx, 4 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | ((uint8_t)(c->eax >> 8))))) << 8); /* or ah, ah */
    if (!c->zf) goto L_00586300; /* jne 0x586300 */
    c->edi = (uint32_t)(c->edi); /* mov edi, edi */
L_00586330:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_00586334:;
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(shl32(c, c->eax, 1)); /* shl eax, 1 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->esp += 4; return; /* ret  */
L_0058633c:;
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x1u)); /* test edx, 1 */
    if (c->zf) goto L_00586358; /* je 0x586358 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov al, byte ptr [edx] */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->ecx))); /* cmp al, byte ptr [ecx] */
    if (!c->zf) goto L_00586334; /* jne 0x586334 */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00586330; /* je 0x586330 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x2u)); /* test edx, 2 */
    if (c->zf) goto L_00586300; /* je 0x586300 */
L_00586358:;
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->edx))); /* mov ax, word ptr [edx] */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x2u)); /* add edx, 2 */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->ecx))); /* cmp al, byte ptr [ecx] */
    if (!c->zf) goto L_00586334; /* jne 0x586334 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00586330; /* je 0x586330 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), R8((uint32_t)(c->ecx + 0x1u))); /* cmp ah, byte ptr [ecx + 1] */
    if (!c->zf) goto L_00586334; /* jne 0x586334 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | ((uint8_t)(c->eax >> 8))))) << 8); /* or ah, ah */
    if (c->zf) goto L_00586330; /* je 0x586330 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x2u)); /* add ecx, 2 */
    goto L_00586300; /* jmp 0x586300 */
}

void f_00586374(CPU *c) { /* FUN_10006374 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xe06d7363u); /* cmp dword ptr [eax], 0xe06d7363 */
    if (!c->zf) goto L_00586397; /* jne 0x586397 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [eax + 0x10], 3 */
    if (!c->zf) goto L_00586397; /* jne 0x586397 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x14u)), (uint32_t)0x19930520u); /* cmp dword ptr [eax + 0x14], 0x19930520 */
    if (!c->zf) goto L_00586397; /* jne 0x586397 */
    { f_005859c8(c); return; } /* jmp 0x5859c8 */
L_00586397:;
    c->eax = (uint32_t)(R32((uint32_t)(0x621870u))); /* mov eax, dword ptr [0x100a1870] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_005863b4; /* je 0x5863b4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x005863a6u); f_00587dd7(c); /* call 0x587dd7 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_005863b4; /* je 0x5863b4 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(0x621870u)); PUSH32(c, 0x005863b2u); call_indirect(c, t_); } /* call dword ptr [0x100a1870] */
    goto L_005863b6; /* jmp 0x5863b6 */
L_005863b4:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_005863b6:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_005863ba(CPU *c) { /* PTR_005863ba */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x586374u; PUSH32(c, v_); } /* push 0x10006374 */
    { uint32_t t_ = R32((uint32_t)(0x58d058u)); PUSH32(c, 0x005863c5u); call_indirect(c, t_); } /* call dword ptr [0x1000d058] */
    W32((uint32_t)(0x621870u), (uint32_t)(c->eax)); /* mov dword ptr [0x100a1870], eax */
    c->esp += 4; return; /* ret  */
}

void f_005863cb(CPU *c) { /* PTR_005863cb */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(0x621870u)); PUSH32(c, v_); } /* push dword ptr [0x100a1870] */
    { uint32_t t_ = R32((uint32_t)(0x58d058u)); PUSH32(c, 0x005863d7u); call_indirect(c, t_); } /* call dword ptr [0x1000d058] */
    c->esp += 4; return; /* ret  */
}

void f_005863d8(CPU *c) { /* FUN_100063d8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ebx, dword ptr [esi + 0x10] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x82u)); /* test al, 0x82 */
    if (c->zf) goto L_005864e4; /* je 0x5864e4 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x40u)); /* test al, 0x40 */
    if (!c->zf) goto L_005864e4; /* jne 0x5864e4 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    if (c->zf) goto L_00586410; /* je 0x586410 */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi + 4], 0 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x10u)); /* test al, 0x10 */
    if (c->zf) goto L_005864e4; /* je 0x5864e4 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ecx, dword ptr [esi + 8] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfeu))); /* and al, 0xfe */
    W32((uint32_t)(c->esi), (uint32_t)(c->ecx)); /* mov dword ptr [esi], ecx */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xc], eax */
L_00586410:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi + 4], 0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp + 0xc], 0 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xefu))); /* and al, 0xef */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x2u))); /* or al, 2 */
    (void)logic16(c, (uint16_t)(((uint16_t)c->eax) & (uint16_t)0x10cu)); /* test ax, 0x10c */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xc], eax */
    if (!c->zf) goto L_0058644a; /* jne 0x58644a */
    (void)sub32(c, c->esi, (uint32_t)0x5907a0u); /* cmp esi, 0x100107a0 */
    if (c->zf) goto L_00586438; /* je 0x586438 */
    (void)sub32(c, c->esi, (uint32_t)0x5907c0u); /* cmp esi, 0x100107c0 */
    if (!c->zf) goto L_00586443; /* jne 0x586443 */
L_00586438:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x0058643eu); f_00589bd1(c); /* call 0x589bd1 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_0058644a; /* jne 0x58644a */
L_00586443:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00586449u); f_00589b8d(c); /* call 0x589b8d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_0058644a:;
    (void)logic16(c, (uint16_t)(R16((uint32_t)(c->esi + 0xcu)) & (uint16_t)0x108u)); /* test word ptr [esi + 0xc], 0x108 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (c->zf) goto L_005864ba; /* je 0x5864ba */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edi, dword ptr [esi] */
    c->edi = (uint32_t)(sub32(c, c->edi, c->eax)); /* sub edi, eax */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x1u)); /* lea ecx, [eax + 1] */
    W32((uint32_t)(c->esi), (uint32_t)(c->ecx)); /* mov dword ptr [esi], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x18u))); /* mov ecx, dword ptr [esi + 0x18] */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 4], ecx */
    if ((c->zf || c->sf != c->of)) goto L_0058647a; /* jle 0x58647a */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00586472u); f_0058999d(c); /* call 0x58999d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0xc], eax */
    goto L_005864b0; /* jmp 0x5864b0 */
L_0058647a:;
    (void)sub32(c, c->ebx, (uint32_t)0xffffffffu); /* cmp ebx, -1 */
    if (c->zf) goto L_00586498; /* je 0x586498 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 5)); /* sar ecx, 5 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1fu))); /* and eax, 0x1f */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx * 4 + 0x622dc0u))); /* mov ecx, dword ptr [ecx*4 + 0x100a2dc0] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 8)); /* lea eax, [eax + eax*8] */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->eax * 4)); /* lea eax, [ecx + eax*4] */
    goto L_0058649d; /* jmp 0x58649d */
L_00586498:;
    c->eax = (uint32_t)((uint32_t)0x58e610u); /* mov eax, 0x1000e610 */
L_0058649d:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + 0x4u)) & (uint8_t)0x20u)); /* test byte ptr [eax + 4], 0x20 */
    if (c->zf) goto L_005864b0; /* je 0x5864b0 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x005864adu); f_005898c5(c); /* call 0x5898c5 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_005864b0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0x8u))); /* mov cl, byte ptr [ebp + 8] */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax], cl */
    goto L_005864ce; /* jmp 0x5864ce */
L_005864ba:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x8u)); /* lea eax, [ebp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x005864c8u); f_0058999d(c); /* call 0x58999d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0xc], eax */
L_005864ce:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->edi); /* cmp dword ptr [ebp + 0xc], edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    if (c->zf) goto L_005864da; /* je 0x5864da */
    { uint32_t a_ = (uint32_t)(c->esi + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x20u)))); } /* or dword ptr [esi + 0xc], 0x20 */
    goto L_005864e9; /* jmp 0x5864e9 */
L_005864da:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xffu))); /* and eax, 0xff */
    goto L_005864ec; /* jmp 0x5864ec */
L_005864e4:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x20u))); /* or al, 0x20 */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xc], eax */
L_005864e9:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
L_005864ec:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_005864f0(CPU *c) { /* FUN_100064f0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x248u)); /* sub esp, 0x248 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & ((uint8_t)c->ebx))); /* test bl, bl */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0xc], esi */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x14], esi */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 0xc], edi */
    if (c->zf) goto L_00586c09; /* je 0x586c09 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    goto L_00586524; /* jmp 0x586524 */
L_0058651c:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd0u))); /* mov esi, dword ptr [ebp - 0x30] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
L_00586524:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffecu)), c->edx); /* cmp dword ptr [ebp - 0x14], edx */
    if ((c->sf != c->of)) goto L_00586c09; /* jl 0x586c09 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x20u); /* cmp bl, 0x20 */
    if ((c->sf != c->of)) goto L_00586545; /* jl 0x586545 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x78u); /* cmp bl, 0x78 */
    if ((!c->zf && c->sf == c->of)) goto L_00586545; /* jg 0x586545 */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx eax, bl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x58d298u))); /* mov al, byte ptr [eax + 0x1000d298] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xfu))); /* and eax, 0xf */
    goto L_00586547; /* jmp 0x586547 */
L_00586545:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00586547:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->esi + c->eax * 8 + 0x58d2b8u))); /* movsx eax, byte ptr [esi + eax*8 + 0x1000d2b8] */
    c->eax = (uint32_t)(sar32(c, c->eax, 4)); /* sar eax, 4 */
    (void)sub32(c, c->eax, (uint32_t)0x7u); /* cmp eax, 7 */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x30], eax */
    if ((!c->cf && !c->zf)) goto L_00586bf8; /* ja 0x586bf8 */
    { uint32_t t_ = R32((uint32_t)(c->eax * 4 + 0x586c11u)); switch (t_) { case 0x00586565u: goto L_00586565; case 0x00586580u: goto L_00586580; case 0x005865ccu: goto L_005865cc; case 0x00586603u: goto L_00586603; case 0x0058660bu: goto L_0058660b; case 0x00586640u: goto L_00586640; case 0x0058668fu: goto L_0058668f; case 0x005866d3u: goto L_005866d3; default: jump_indirect(c, t_, 0x0058655eu); return; } } /* jmp dword ptr [eax*4 + 0x10006c11] */
L_00586565:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff0u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 0x10], 0xffffffff */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x34], edx */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x28], edx */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x20], edx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x1c], edx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 4], edx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x24], edx */
    goto L_00586bf8; /* jmp 0x586bf8 */
L_00586580:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx eax, bl */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x20u)); /* sub eax, 0x20 */
    if (c->zf) goto L_005865c3; /* je 0x5865c3 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3u)); /* sub eax, 3 */
    if (c->zf) goto L_005865ba; /* je 0x5865ba */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x8u)); /* sub eax, 8 */
    if (c->zf) goto L_005865b1; /* je 0x5865b1 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_005865a8; /* je 0x5865a8 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3u)); /* sub eax, 3 */
    if (!c->zf) goto L_00586bf8; /* jne 0x586bf8 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x8u)))); } /* or dword ptr [ebp - 4], 8 */
    goto L_00586bf8; /* jmp 0x586bf8 */
L_005865a8:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x4u)))); } /* or dword ptr [ebp - 4], 4 */
    goto L_00586bf8; /* jmp 0x586bf8 */
L_005865b1:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x1u)))); } /* or dword ptr [ebp - 4], 1 */
    goto L_00586bf8; /* jmp 0x586bf8 */
L_005865ba:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x80u)))); } /* or byte ptr [ebp - 4], 0x80 */
    goto L_00586bf8; /* jmp 0x586bf8 */
L_005865c3:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x2u)))); } /* or dword ptr [ebp - 4], 2 */
    goto L_00586bf8; /* jmp 0x586bf8 */
L_005865cc:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x2au); /* cmp bl, 0x2a */
    if (!c->zf) goto L_005865f4; /* jne 0x5865f4 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x005865dau); f_00586ccf(c); /* call 0x586ccf */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    if ((c->sf == c->of)) goto L_00586bf8; /* jge 0x586bf8 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x4u)))); } /* or dword ptr [ebp - 4], 4 */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
L_005865ec:;
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    goto L_00586bf8; /* jmp 0x586bf8 */
L_005865f4:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov eax, dword ptr [ebp - 0x20] */
    c->ecx = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx ecx, bl */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea eax, [eax + eax*4] */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->eax * 2 + 0xffffffd0u)); /* lea eax, [ecx + eax*2 - 0x30] */
    goto L_005865ec; /* jmp 0x5865ec */
L_00586603:;
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x10], edx */
    goto L_00586bf8; /* jmp 0x586bf8 */
L_0058660b:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x2au); /* cmp bl, 0x2a */
    if (!c->zf) goto L_0058662e; /* jne 0x58662e */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00586619u); f_00586ccf(c); /* call 0x586ccf */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x10], eax */
    if ((c->sf == c->of)) goto L_00586bf8; /* jge 0x586bf8 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff0u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 0x10], 0xffffffff */
    goto L_00586bf8; /* jmp 0x586bf8 */
L_0058662e:;
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->ecx * 4)); /* lea eax, [ecx + ecx*4] */
    c->ecx = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx ecx, bl */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->eax * 2 + 0xffffffd0u)); /* lea eax, [ecx + eax*2 - 0x30] */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x10], eax */
    goto L_00586bf8; /* jmp 0x586bf8 */
L_00586640:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x49u); /* cmp bl, 0x49 */
    if (c->zf) goto L_00586673; /* je 0x586673 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x68u); /* cmp bl, 0x68 */
    if (c->zf) goto L_0058666a; /* je 0x58666a */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x6cu); /* cmp bl, 0x6c */
    if (c->zf) goto L_00586661; /* je 0x586661 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x77u); /* cmp bl, 0x77 */
    if (!c->zf) goto L_00586bf8; /* jne 0x586bf8 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffdu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x8u)))); } /* or byte ptr [ebp - 3], 8 */
    goto L_00586bf8; /* jmp 0x586bf8 */
L_00586661:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x10u)))); } /* or dword ptr [ebp - 4], 0x10 */
    goto L_00586bf8; /* jmp 0x586bf8 */
L_0058666a:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x20u)))); } /* or dword ptr [ebp - 4], 0x20 */
    goto L_00586bf8; /* jmp 0x586bf8 */
L_00586673:;
    (void)sub8(c, R8((uint32_t)(c->edi)), (uint8_t)0x36u); /* cmp byte ptr [edi], 0x36 */
    if (!c->zf) goto L_0058668c; /* jne 0x58668c */
    (void)sub8(c, R8((uint32_t)(c->edi + 0x1u)), (uint8_t)0x34u); /* cmp byte ptr [edi + 1], 0x34 */
    if (!c->zf) goto L_0058668c; /* jne 0x58668c */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffdu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x80u)))); } /* or byte ptr [ebp - 3], 0x80 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 0xc], edi */
    goto L_00586bf8; /* jmp 0x586bf8 */
L_0058668c:;
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x30], edx */
L_0058668f:;
    c->ecx = (uint32_t)(R32((uint32_t)(0x58e3f0u))); /* mov ecx, dword ptr [0x1000e3f0] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x24], edx */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2 + 0x1u)) & (uint8_t)0x80u)); /* test byte ptr [ecx + eax*2 + 1], 0x80 */
    if (c->zf) goto L_005866bb; /* je 0x5866bb */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea eax, [ebp - 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx eax, bl */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x005866b2u); f_00586c31(c); /* call 0x586c31 */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 0xc], edi */
L_005866bb:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea eax, [ebp - 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx eax, bl */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x005866cbu); f_00586c31(c); /* call 0x586c31 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_00586bf8; /* jmp 0x586bf8 */
L_005866d3:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx eax, bl */
    (void)sub32(c, c->eax, (uint32_t)0x67u); /* cmp eax, 0x67 */
    if ((!c->zf && c->sf == c->of)) goto L_005868fb; /* jg 0x5868fb */
    (void)sub32(c, c->eax, (uint32_t)0x65u); /* cmp eax, 0x65 */
    if ((c->sf == c->of)) goto L_0058677e; /* jge 0x58677e */
    (void)sub32(c, c->eax, (uint32_t)0x58u); /* cmp eax, 0x58 */
    if ((!c->zf && c->sf == c->of)) goto L_005867dc; /* jg 0x5867dc */
    if (c->zf) goto L_0058696f; /* je 0x58696f */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x43u)); /* sub eax, 0x43 */
    if (c->zf) goto L_0058679f; /* je 0x58679f */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00586774; /* je 0x586774 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00586774; /* je 0x586774 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0xcu)); /* sub eax, 0xc */
    if (!c->zf) goto L_00586afa; /* jne 0x586afa */
    (void)logic16(c, (uint16_t)(R16((uint32_t)(c->ebp + 0xfffffffcu)) & (uint16_t)0x830u)); /* test word ptr [ebp - 4], 0x830 */
    if (!c->zf) goto L_0058671d; /* jne 0x58671d */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffdu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x8u)))); } /* or byte ptr [ebp - 3], 8 */
L_0058671d:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov esi, dword ptr [ebp - 0x10] */
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (!c->zf) goto L_0058672a; /* jne 0x58672a */
    c->esi = (uint32_t)((uint32_t)0x7fffffffu); /* mov esi, 0x7fffffff */
L_0058672a:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00586733u); f_00586ccf(c); /* call 0x586ccf */
    (void)logic16(c, (uint16_t)(R16((uint32_t)(c->ebp + 0xfffffffcu)) & (uint16_t)0x810u)); /* test word ptr [ebp - 4], 0x810 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
    if (c->zf) goto L_00586943; /* je 0x586943 */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (!c->zf) goto L_00586752; /* jne 0x586752 */
    c->ecx = (uint32_t)(R32((uint32_t)(0x58e3d4u))); /* mov ecx, dword ptr [0x1000e3d4] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
L_00586752:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x24], 1 */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
L_0058675b:;
    c->edx = (uint32_t)(c->esi); /* mov edx, esi */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_0058693a; /* je 0x58693a */
    (void)sub16(c, R16((uint32_t)(c->eax)), (uint16_t)0x0u); /* cmp word ptr [eax], 0 */
    if (c->zf) goto L_0058693a; /* je 0x58693a */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_0058675b; /* jmp 0x58675b */
L_00586774:;
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x34], 1 */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(add8(c, ((uint8_t)c->ebx), (uint8_t)0x20u)); /* add bl, 0x20 */
L_0058677e:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x40u)))); } /* or dword ptr [ebp - 4], 0x40 */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0xfffffdb8u)); /* lea edi, [ebp - 0x248] */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 8], edi */
    if ((c->sf == c->of)) goto L_00586862; /* jge 0x586862 */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)((uint32_t)0x6u)); /* mov dword ptr [ebp - 0x10], 6 */
    goto L_00586870; /* jmp 0x586870 */
L_0058679f:;
    (void)logic16(c, (uint16_t)(R16((uint32_t)(c->ebp + 0xfffffffcu)) & (uint16_t)0x830u)); /* test word ptr [ebp - 4], 0x830 */
    if (!c->zf) goto L_005867ab; /* jne 0x5867ab */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffdu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x8u)))); } /* or byte ptr [ebp - 3], 8 */
L_005867ab:;
    (void)logic16(c, (uint16_t)(R16((uint32_t)(c->ebp + 0xfffffffcu)) & (uint16_t)0x810u)); /* test word ptr [ebp - 4], 0x810 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    if (c->zf) goto L_005867f2; /* je 0x5867f2 */
    PUSH32(c, 0x005867bcu); f_00586cec(c); /* call 0x586cec */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffdb8u)); /* lea eax, [ebp - 0x248] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x005867c9u); f_00589d5a(c); /* call 0x589d5a */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf == c->of)) goto L_00586805; /* jge 0x586805 */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x28], 1 */
    goto L_00586805; /* jmp 0x586805 */
L_005867dc:;
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x5au)); /* sub eax, 0x5a */
    if (c->zf) goto L_00586813; /* je 0x586813 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x9u)); /* sub eax, 9 */
    if (c->zf) goto L_005867ab; /* je 0x5867ab */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_005869d5; /* je 0x5869d5 */
    goto L_00586afa; /* jmp 0x586afa */
L_005867f2:;
    PUSH32(c, 0x005867f7u); f_00586ccf(c); /* call 0x586ccf */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W8((uint32_t)(c->ebp + 0xfffffdb8u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp - 0x248], al */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0xc], 1 */
L_00586805:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffdb8u)); /* lea eax, [ebp - 0x248] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    goto L_00586afa; /* jmp 0x586afa */
L_00586813:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0058681cu); f_00586ccf(c); /* call 0x586ccf */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00586854; /* je 0x586854 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00586854; /* je 0x586854 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffdu)) & (uint8_t)0x8u)); /* test byte ptr [ebp - 3], 8 */
    if (c->zf) goto L_00586845; /* je 0x586845 */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int16_t)R16((uint32_t)(c->eax))); /* movsx eax, word ptr [eax] */
    c->eax = (uint32_t)(shr32(c, c->eax, 1)); /* shr eax, 1 */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x24], 1 */
    goto L_00586afa; /* jmp 0x586afa */
L_00586845:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffdcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x24], 0 */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int16_t)R16((uint32_t)(c->eax))); /* movsx eax, word ptr [eax] */
    goto L_00586af7; /* jmp 0x586af7 */
L_00586854:;
    c->eax = (uint32_t)(R32((uint32_t)(0x58e3d0u))); /* mov eax, dword ptr [0x1000e3d0] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    goto L_005868f0; /* jmp 0x5868f0 */
L_00586862:;
    if (!c->zf) goto L_00586870; /* jne 0x586870 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x67u); /* cmp bl, 0x67 */
    if (!c->zf) goto L_00586870; /* jne 0x586870 */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x10], 1 */
L_00586870:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffccu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x34] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x10], eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffff0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0xfffffff8u))); /* mov ecx, dword ptr [eax - 8] */
    W32((uint32_t)(c->ebp + 0xffffffb8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 0x48], ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0xfffffffcu))); /* mov eax, dword ptr [eax - 4] */
    W32((uint32_t)(c->ebp + 0xffffffbcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x44], eax */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx eax, bl */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffdb8u)); /* lea eax, [ebp - 0x248] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffb8u)); /* lea eax, [ebp - 0x48] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x58e3d8u)); PUSH32(c, 0x005868a0u); call_indirect(c, t_); } /* call dword ptr [0x1000e3d8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov esi, dword ptr [ebp - 4] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0x80u))); /* and esi, 0x80 */
    if (c->zf) goto L_005868c2; /* je 0x5868c2 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x10], 0 */
    if (!c->zf) goto L_005868c2; /* jne 0x5868c2 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffdb8u)); /* lea eax, [ebp - 0x248] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x58e3e4u)); PUSH32(c, 0x005868c1u); call_indirect(c, t_); } /* call dword ptr [0x1000e3e4] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_005868c2:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x67u); /* cmp bl, 0x67 */
    if (!c->zf) goto L_005868d9; /* jne 0x5868d9 */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_005868d9; /* jne 0x5868d9 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffdb8u)); /* lea eax, [ebp - 0x248] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x58e3dcu)); PUSH32(c, 0x005868d8u); call_indirect(c, t_); } /* call dword ptr [0x1000e3dc] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_005868d9:;
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xfffffdb8u)), (uint8_t)0x2du); /* cmp byte ptr [ebp - 0x248], 0x2d */
    if (!c->zf) goto L_005868ef; /* jne 0x5868ef */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffdu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x1u)))); } /* or byte ptr [ebp - 3], 1 */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0xfffffdb9u)); /* lea edi, [ebp - 0x247] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 8], edi */
L_005868ef:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
L_005868f0:;
    PUSH32(c, 0x005868f5u); f_005872d0(c); /* call 0x5872d0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00586af7; /* jmp 0x586af7 */
L_005868fb:;
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x69u)); /* sub eax, 0x69 */
    if (c->zf) goto L_005869d5; /* je 0x5869d5 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x5u)); /* sub eax, 5 */
    if (c->zf) goto L_005869ab; /* je 0x5869ab */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00586998; /* je 0x586998 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00586968; /* je 0x586968 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3u)); /* sub eax, 3 */
    if (c->zf) goto L_0058671d; /* je 0x58671d */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_005869d9; /* je 0x5869d9 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3u)); /* sub eax, 3 */
    if (!c->zf) goto L_00586afa; /* jne 0x586afa */
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)((uint32_t)0x27u)); /* mov dword ptr [ebp - 0x2c], 0x27 */
    goto L_00586976; /* jmp 0x586976 */
L_0058693a:;
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->eax = (uint32_t)(sar32(c, c->eax, 1)); /* sar eax, 1 */
    goto L_00586af7; /* jmp 0x586af7 */
L_00586943:;
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (!c->zf) goto L_00586950; /* jne 0x586950 */
    c->ecx = (uint32_t)(R32((uint32_t)(0x58e3d0u))); /* mov ecx, dword ptr [0x1000e3d0] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
L_00586950:;
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
L_00586952:;
    c->edx = (uint32_t)(c->esi); /* mov edx, esi */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_00586961; /* je 0x586961 */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (c->zf) goto L_00586961; /* je 0x586961 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_00586952; /* jmp 0x586952 */
L_00586961:;
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    goto L_00586af7; /* jmp 0x586af7 */
L_00586968:;
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)((uint32_t)0x8u)); /* mov dword ptr [ebp - 0x10], 8 */
L_0058696f:;
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)((uint32_t)0x7u)); /* mov dword ptr [ebp - 0x2c], 7 */
L_00586976:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffcu)) & (uint8_t)0x80u)); /* test byte ptr [ebp - 4], 0x80 */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)((uint32_t)0x10u)); /* mov dword ptr [ebp - 0xc], 0x10 */
    if (c->zf) goto L_005869e0; /* je 0x5869e0 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0xffffffd4u))); /* mov al, byte ptr [ebp - 0x2c] */
    W8((uint32_t)(c->ebp + 0xffffffeau), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [ebp - 0x16], 0x30 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(add8(c, ((uint8_t)c->eax), (uint8_t)0x51u)); /* add al, 0x51 */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [ebp - 0x1c], 2 */
    W8((uint32_t)(c->ebp + 0xffffffebu), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp - 0x15], al */
    goto L_005869e0; /* jmp 0x5869e0 */
L_00586998:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffcu)) & (uint8_t)0x80u)); /* test byte ptr [ebp - 4], 0x80 */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)((uint32_t)0x8u)); /* mov dword ptr [ebp - 0xc], 8 */
    if (c->zf) goto L_005869e0; /* je 0x5869e0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffdu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x2u)))); } /* or byte ptr [ebp - 3], 2 */
    goto L_005869e0; /* jmp 0x5869e0 */
L_005869ab:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x005869b4u); f_00586ccf(c); /* call 0x586ccf */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffcu)) & (uint8_t)0x20u)); /* test byte ptr [ebp - 4], 0x20 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_005869c4; /* je 0x5869c4 */
    c->ecx = (c->ecx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ebp + 0xffffffecu))); /* mov cx, word ptr [ebp - 0x14] */
    W16((uint32_t)(c->eax), (uint16_t)(((uint16_t)c->ecx))); /* mov word ptr [eax], cx */
    goto L_005869c9; /* jmp 0x5869c9 */
L_005869c4:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov ecx, dword ptr [ebp - 0x14] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
L_005869c9:;
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x28], 1 */
    goto L_00586bf8; /* jmp 0x586bf8 */
L_005869d5:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x40u)))); } /* or dword ptr [ebp - 4], 0x40 */
L_005869d9:;
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)((uint32_t)0xau)); /* mov dword ptr [ebp - 0xc], 0xa */
L_005869e0:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffdu)) & (uint8_t)0x80u)); /* test byte ptr [ebp - 3], 0x80 */
    if (c->zf) goto L_005869f2; /* je 0x5869f2 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x005869efu); f_00586cdc(c); /* call 0x586cdc */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00586a33; /* jmp 0x586a33 */
L_005869f2:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffcu)) & (uint8_t)0x20u)); /* test byte ptr [ebp - 4], 0x20 */
    if (c->zf) goto L_00586a19; /* je 0x586a19 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffcu)) & (uint8_t)0x40u)); /* test byte ptr [ebp - 4], 0x40 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    if (c->zf) goto L_00586a0e; /* je 0x586a0e */
    PUSH32(c, 0x00586a07u); f_00586ccf(c); /* call 0x586ccf */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int16_t)((uint16_t)c->eax)); /* movsx eax, ax */
L_00586a0b:;
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    goto L_00586a33; /* jmp 0x586a33 */
L_00586a0e:;
    PUSH32(c, 0x00586a13u); f_00586ccf(c); /* call 0x586ccf */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)((uint32_t)((uint16_t)c->eax)); /* movzx eax, ax */
    goto L_00586a0b; /* jmp 0x586a0b */
L_00586a19:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffcu)) & (uint8_t)0x40u)); /* test byte ptr [ebp - 4], 0x40 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    if (c->zf) goto L_00586a2b; /* je 0x586a2b */
    PUSH32(c, 0x00586a28u); f_00586ccf(c); /* call 0x586ccf */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00586a0b; /* jmp 0x586a0b */
L_00586a2b:;
    PUSH32(c, 0x00586a30u); f_00586ccf(c); /* call 0x586ccf */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
L_00586a33:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffcu)) & (uint8_t)0x40u)); /* test byte ptr [ebp - 4], 0x40 */
    if (c->zf) goto L_00586a54; /* je 0x586a54 */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if ((!c->zf && c->sf == c->of)) goto L_00586a54; /* jg 0x586a54 */
    if ((c->sf != c->of)) goto L_00586a43; /* jl 0x586a43 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->cf) goto L_00586a54; /* jae 0x586a54 */
L_00586a43:;
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->edx = (uint32_t)(adc32(c, c->edx, (uint32_t)0x0u)); /* adc edx, 0 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->edx = (uint32_t)(neg32(c, c->edx)); /* neg edx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffdu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x1u)))); } /* or byte ptr [ebp - 3], 1 */
    c->edi = (uint32_t)(c->edx); /* mov edi, edx */
    goto L_00586a58; /* jmp 0x586a58 */
L_00586a54:;
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->edi = (uint32_t)(c->edx); /* mov edi, edx */
L_00586a58:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffdu)) & (uint8_t)0x80u)); /* test byte ptr [ebp - 3], 0x80 */
    if (!c->zf) goto L_00586a61; /* jne 0x586a61 */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & (uint32_t)0x0u))); /* and edi, 0 */
L_00586a61:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x10], 0 */
    if ((c->sf == c->of)) goto L_00586a70; /* jge 0x586a70 */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x10], 1 */
    goto L_00586a74; /* jmp 0x586a74 */
L_00586a70:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0xfffffff7u)))); } /* and dword ptr [ebp - 4], 0xfffffff7 */
L_00586a74:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->edi))); /* or eax, edi */
    if (!c->zf) goto L_00586a7e; /* jne 0x586a7e */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x1c], 0 */
L_00586a7e:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffb7u)); /* lea eax, [ebp - 0x49] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
L_00586a84:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff0u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 0x10] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((!c->zf && c->sf == c->of)) goto L_00586a94; /* jg 0x586a94 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->edi))); /* or eax, edi */
    if (c->zf) goto L_00586acf; /* je 0x586acf */
L_00586a94:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W32((uint32_t)(c->ebp + 0xffffffc0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x40], eax */
    W32((uint32_t)(c->ebp + 0xffffffc4u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x3c], edx */
    PUSH32(c, 0x00586aa7u); f_00589e90(c); /* call 0x589e90 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x3c] */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x30u)); /* add ebx, 0x30 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x40] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00586ab9u); f_00589e20(c); /* call 0x589e20 */
    (void)sub32(c, c->ebx, (uint32_t)0x39u); /* cmp ebx, 0x39 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->edi = (uint32_t)(c->edx); /* mov edi, edx */
    if ((c->zf || c->sf != c->of)) goto L_00586ac5; /* jle 0x586ac5 */
    c->ebx = (uint32_t)(add32(c, c->ebx, R32((uint32_t)(c->ebp + 0xffffffd4u)))); /* add ebx, dword ptr [ebp - 0x2c] */
L_00586ac5:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 8] */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [eax], bl */
    goto L_00586a84; /* jmp 0x586a84 */
L_00586acf:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffb7u)); /* lea eax, [ebp - 0x49] */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xfffffff8u)))); /* sub eax, dword ptr [ebp - 8] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffdu)) & (uint8_t)0x2u)); /* test byte ptr [ebp - 3], 2 */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    if (c->zf) goto L_00586afa; /* je 0x586afa */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    (void)sub8(c, R8((uint32_t)(c->ecx)), (uint8_t)0x30u); /* cmp byte ptr [ecx], 0x30 */
    if (!c->zf) goto L_00586aed; /* jne 0x586aed */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00586afa; /* jne 0x586afa */
L_00586aed:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 8] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    W8((uint32_t)(c->ecx), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [ecx], 0x30 */
L_00586af7:;
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
L_00586afa:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x28], 0 */
    if (!c->zf) goto L_00586bf8; /* jne 0x586bf8 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ebx, dword ptr [ebp - 4] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x40u)); /* test bl, 0x40 */
    if (c->zf) goto L_00586b32; /* je 0x586b32 */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->ebx >> 8)) & (uint8_t)0x1u)); /* test bh, 1 */
    if (c->zf) goto L_00586b17; /* je 0x586b17 */
    W8((uint32_t)(c->ebp + 0xffffffeau), (uint8_t)((uint8_t)0x2du)); /* mov byte ptr [ebp - 0x16], 0x2d */
    goto L_00586b2b; /* jmp 0x586b2b */
L_00586b17:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x1u)); /* test bl, 1 */
    if (c->zf) goto L_00586b22; /* je 0x586b22 */
    W8((uint32_t)(c->ebp + 0xffffffeau), (uint8_t)((uint8_t)0x2bu)); /* mov byte ptr [ebp - 0x16], 0x2b */
    goto L_00586b2b; /* jmp 0x586b2b */
L_00586b22:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x2u)); /* test bl, 2 */
    if (c->zf) goto L_00586b32; /* je 0x586b32 */
    W8((uint32_t)(c->ebp + 0xffffffeau), (uint8_t)((uint8_t)0x20u)); /* mov byte ptr [ebp - 0x16], 0x20 */
L_00586b2b:;
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x1c], 1 */
L_00586b32:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
    c->esi = (uint32_t)(sub32(c, c->esi, R32((uint32_t)(c->ebp + 0xffffffe4u)))); /* sub esi, dword ptr [ebp - 0x1c] */
    c->esi = (uint32_t)(sub32(c, c->esi, R32((uint32_t)(c->ebp + 0xfffffff4u)))); /* sub esi, dword ptr [ebp - 0xc] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0xcu)); /* test bl, 0xc */
    if (!c->zf) goto L_00586b52; /* jne 0x586b52 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea eax, [ebp - 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x20u; PUSH32(c, v_); } /* push 0x20 */
    PUSH32(c, 0x00586b4fu); f_00586c66(c); /* call 0x586c66 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_00586b52:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea eax, [ebp - 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffeau)); /* lea eax, [ebp - 0x16] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00586b65u); f_00586c97(c); /* call 0x586c97 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x8u)); /* test bl, 8 */
    if (c->zf) goto L_00586b84; /* je 0x586b84 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x4u)); /* test bl, 4 */
    if (!c->zf) goto L_00586b84; /* jne 0x586b84 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea eax, [ebp - 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x30u; PUSH32(c, v_); } /* push 0x30 */
    PUSH32(c, 0x00586b81u); f_00586c66(c); /* call 0x586c66 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_00586b84:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (c->zf) goto L_00586bcb; /* je 0x586bcb */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0xc], 0 */
    if ((c->zf || c->sf != c->of)) goto L_00586bcb; /* jle 0x586bcb */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ebx, dword ptr [ebp - 8] */
    c->edi = (uint32_t)((uint32_t)(c->eax + 0xffffffffu)); /* lea edi, [eax - 1] */
L_00586b99:;
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ebx))); /* mov ax, word ptr [ebx] */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    PUSH32(c, 0x00586ba8u); f_00589d5a(c); /* call 0x589d5a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if ((c->zf || c->sf != c->of)) goto L_00586be0; /* jle 0x586be0 */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea ecx, [ebp - 0x14] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00586bbfu); f_00586c97(c); /* call 0x586c97 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00586b99; /* jne 0x586b99 */
    goto L_00586be0; /* jmp 0x586be0 */
L_00586bcb:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea eax, [ebp - 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffff4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffff8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 8] */
    PUSH32(c, 0x00586bddu); f_00586c97(c); /* call 0x586c97 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_00586be0:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffcu)) & (uint8_t)0x4u)); /* test byte ptr [ebp - 4], 4 */
    if (c->zf) goto L_00586bf8; /* je 0x586bf8 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea eax, [ebp - 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x20u; PUSH32(c, v_); } /* push 0x20 */
    PUSH32(c, 0x00586bf5u); f_00586c66(c); /* call 0x586c66 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_00586bf8:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & ((uint8_t)c->ebx))); /* test bl, bl */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 0xc], edi */
    if (!c->zf) goto L_0058651c; /* jne 0x58651c */
L_00586c09:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00586565(CPU *c) { /* PTR_00586565 */
    PREEMPT_POLL(c);
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff0u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 0x10], 0xffffffff */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x34], edx */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x28], edx */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x20], edx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x1c], edx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 4], edx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x24], edx */
    goto L_00586bf8; /* jmp 0x586bf8 */
L_00586bf8:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & ((uint8_t)c->ebx))); /* test bl, bl */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 0xc], edi */
    if (!c->zf) { jump_indirect(c, 0x0058651cu, 0x00586c03u); return; } /* jne 0x58651c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00586c31(CPU *c) { /* PTR_00586c31 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ecx + 4] */
    if (c->sf) goto L_00586c4a; /* js 0x586c4a */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0x8u))); /* mov al, byte ptr [ebp + 8] */
    W8((uint32_t)(c->edx), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edx], al */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->eax)); /* movzx eax, al */
    goto L_00586c55; /* jmp 0x586c55 */
L_00586c4a:;
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00586c53u); f_005863d8(c); /* call 0x5863d8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00586c55:;
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    if (!c->zf) goto L_00586c62; /* jne 0x586c62 */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [eax], 0xffffffff */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
L_00586c62:;
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [eax] */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00586c66(CPU *c) { /* PTR_00586c66 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edi, dword ptr [esp + 0x10] */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_00586c94; /* jle 0x586c94 */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov esi, dword ptr [esp + 0x18] */
L_00586c77:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x14] */
    PUSH32(c, 0x00586c85u); f_00586c31(c); /* call 0x586c31 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0xffffffffu); /* cmp dword ptr [esi], -1 */
    if (c->zf) goto L_00586c94; /* je 0x586c94 */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((!c->zf && c->sf == c->of)) goto L_00586c77; /* jg 0x586c77 */
L_00586c94:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00586c97(CPU *c) { /* PTR_00586c97 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ebx, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_00586ccb; /* jle 0x586ccb */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov edi, dword ptr [esp + 0x1c] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
L_00586cad:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->esi))); /* movsx eax, byte ptr [esi] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [esp + 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00586cbcu); f_00586c31(c); /* call 0x586c31 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, R32((uint32_t)(c->edi)), (uint32_t)0xffffffffu); /* cmp dword ptr [edi], -1 */
    if (c->zf) goto L_00586ccb; /* je 0x586ccb */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((!c->zf && c->sf == c->of)) goto L_00586cad; /* jg 0x586cad */
L_00586ccb:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00586ccf(CPU *c) { /* PTR_00586ccf */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x4u))); } /* add dword ptr [eax], 4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0xfffffffcu))); /* mov eax, dword ptr [eax - 4] */
    c->esp += 4; return; /* ret  */
}

void f_00586cdc(CPU *c) { /* PTR_00586cdc */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x8u))); } /* add dword ptr [eax], 8 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0xfffffff8u))); /* mov eax, dword ptr [ecx - 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0xfffffffcu))); /* mov edx, dword ptr [ecx - 4] */
    c->esp += 4; return; /* ret  */
}

void f_00586cec(CPU *c) { /* PTR_00586cec */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x4u))); } /* add dword ptr [eax], 4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->eax + 0xfffffffcu))); /* mov ax, word ptr [eax - 4] */
    c->esp += 4; return; /* ret  */
}

void f_00586cfa(CPU *c) { /* FUN_10006cfa */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x30000u; PUSH32(c, v_); } /* push 0x30000 */
    { uint32_t v_ = 0x10000u; PUSH32(c, v_); } /* push 0x10000 */
    PUSH32(c, 0x00586d09u); f_00589f3a(c); /* call 0x589f3a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00586d0c(CPU *c) { /* FUN_10006d0c */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    FPUSH(c, RF64((uint32_t)(0x58d340u))); /* fld qword ptr [0x1000d340] */
    WF64((uint32_t)(c->ebp + 0xfffffff8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 8] */
    FPUSH(c, RF64((uint32_t)(0x58d338u))); /* fld qword ptr [0x1000d338] */
    WF64((uint32_t)(c->ebp + 0xfffffff0u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0x10] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff0u))); /* fld qword ptr [ebp - 0x10] */
    ST(0) = FPRES(c, FDIV(c, ST(0), RF64((uint32_t)(c->ebp + 0xfffffff8u)))); /* fdiv qword ptr [ebp - 8] */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->ebp + 0xfffffff8u))); /* fmul qword ptr [ebp - 8] */
    ST(0) = FPRES(c, RF64((uint32_t)(c->ebp + 0xfffffff0u)) - ST(0)); /* fsubr qword ptr [ebp - 0x10] */
    WF64((uint32_t)(c->ebp + 0xffffffe8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0x18] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xffffffe8u))); /* fld qword ptr [ebp - 0x18] */
    FCOM(c, ST(0), RF64((uint32_t)(0x58d330u))); FPOP(c); /* fcomp qword ptr [0x1000d330] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if ((c->cf || c->zf)) goto L_00586d46; /* jbe 0x586d46 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00586d46:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00586d4a(CPU *c) { /* FUN_10006d4a */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x58d364u; PUSH32(c, v_); } /* push 0x1000d364 */
    { uint32_t t_ = R32((uint32_t)(0x58d060u)); PUSH32(c, 0x00586d55u); call_indirect(c, t_); } /* call dword ptr [0x1000d060] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00586d6e; /* je 0x586d6e */
    { uint32_t v_ = 0x58d348u; PUSH32(c, v_); } /* push 0x1000d348 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x58d05cu)); PUSH32(c, 0x00586d65u); call_indirect(c, t_); } /* call dword ptr [0x1000d05c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00586d6e; /* je 0x586d6e */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00586d6du); call_indirect(c, t_); } /* call eax */
    c->esp += 4; return; /* ret  */
L_00586d6e:;
    { f_00586d0c(c); return; } /* jmp 0x586d0c */
}

void f_00586d73(CPU *c) { /* FUN_10006d73 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->esi))); /* movsx eax, byte ptr [esi] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00586d81u); f_0058a06b(c); /* call 0x58a06b */
    (void)sub32(c, c->eax, (uint32_t)0x65u); /* cmp eax, 0x65 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00586db3; /* je 0x586db3 */
L_00586d87:;
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub32(c, R32((uint32_t)(0x58e5fcu)), (uint32_t)0x1u); /* cmp dword ptr [0x1000e5fc], 1 */
    if ((c->zf || c->sf != c->of)) goto L_00586da0; /* jle 0x586da0 */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->esi))); /* movsx eax, byte ptr [esi] */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00586d9cu); f_00587199(c); /* call 0x587199 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00586daf; /* jmp 0x586daf */
L_00586da0:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->esi))); /* movsx eax, byte ptr [esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x58e3f0u))); /* mov ecx, dword ptr [0x1000e3f0] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4u))); /* and eax, 4 */
L_00586daf:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00586d87; /* jne 0x586d87 */
L_00586db3:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x58e600u))); /* mov cl, byte ptr [0x1000e600] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esi], cl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_00586dbe:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov cl, byte ptr [esi] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [esi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(((uint8_t)c->ecx)); /* mov al, cl */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov cl, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_00586dbe; /* jne 0x586dbe */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00586dcd(CPU *c) { /* PTR_00586dcd */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x58e600u))); /* mov dl, byte ptr [0x1000e600] */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_00586de9; /* je 0x586de9 */
L_00586ddd:;
    (void)sub8(c, ((uint8_t)c->ecx), ((uint8_t)c->edx)); /* cmp cl, dl */
    if (c->zf) goto L_00586de9; /* je 0x586de9 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1u))); /* mov cl, byte ptr [eax + 1] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_00586ddd; /* jne 0x586ddd */
L_00586de9:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_00586e1a; /* je 0x586e1a */
L_00586df0:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_00586e03; /* je 0x586e03 */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x65u); /* cmp cl, 0x65 */
    if (c->zf) goto L_00586e03; /* je 0x586e03 */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x45u); /* cmp cl, 0x45 */
    if (c->zf) goto L_00586e03; /* je 0x586e03 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_00586df0; /* jmp 0x586df0 */
L_00586e03:;
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
L_00586e05:;
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x30u); /* cmp byte ptr [eax], 0x30 */
    if (c->zf) goto L_00586e05; /* je 0x586e05 */
    (void)sub8(c, R8((uint32_t)(c->eax)), ((uint8_t)c->edx)); /* cmp byte ptr [eax], dl */
    if (!c->zf) goto L_00586e10; /* jne 0x586e10 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
L_00586e10:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov dl, byte ptr [ecx] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [eax], dl */
    if (!c->zf) goto L_00586e10; /* jne 0x586e10 */
L_00586e1a:;
    c->esp += 4; return; /* ret  */
}

void f_00586e1b(CPU *c) { /* PTR_00586e1b */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    FPUSH(c, RF64((uint32_t)(c->eax))); /* fld qword ptr [eax] */
    FCOM(c, ST(0), RF64((uint32_t)(0x58d370u))); FPOP(c); /* fcomp qword ptr [0x1000d370] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (c->cf) goto L_00586e30; /* jb 0x586e30 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
L_00586e30:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_00586e33(CPU *c) { /* __fassign */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    if (c->zf) goto L_00586e5c; /* je 0x586e5c */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00586e4au); f_0058a537(c); /* call 0x58a537 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 4], ecx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00586e5c:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00586e65u); f_0058a564(c); /* call 0x58a564 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00586e71(CPU *c) { /* FUN_10006e71 */
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
    PUSH32(c, 0x00586e8fu); f_0058a608(c); /* call 0x58a608 */
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
    PUSH32(c, 0x00586eb7u); f_0058a591(c); /* call 0x58a591 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x00586ec9u); f_00586ed2(c); /* call 0x586ed2 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x30u)); /* add esp, 0x30 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00586ed2(CPU *c) { /* FUN_10006ed2 */
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
    if (c->zf) goto L_00586f00; /* je 0x586f00 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->ebx); /* cmp dword ptr [ebp + 0xc], ebx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((!c->zf && c->sf == c->of) ? 1 : 0); /* setg al */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x2du); /* cmp dword ptr [esi], 0x2d */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete al */
    c->eax = (uint32_t)(add32(c, c->eax, c->edi)); /* add eax, edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00586efeu); f_00587174(c); /* call 0x587174 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00586f00:;
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x2du); /* cmp dword ptr [esi], 0x2d */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    if (!c->zf) goto L_00586f0d; /* jne 0x586f0d */
    W8((uint32_t)(c->edi), (uint8_t)((uint8_t)0x2du)); /* mov byte ptr [edi], 0x2d */
    c->eax = (uint32_t)((uint32_t)(c->edi + 0x1u)); /* lea eax, [edi + 1] */
L_00586f0d:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->ebx); /* cmp dword ptr [ebp + 0xc], ebx */
    if ((c->zf || c->sf != c->of)) goto L_00586f24; /* jle 0x586f24 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1u))); /* mov dl, byte ptr [eax + 1] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x1u)); /* lea ecx, [eax + 1] */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [eax], dl */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x58e600u))); /* mov cl, byte ptr [0x1000e600] */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax], cl */
L_00586f24:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x18u)), ((uint8_t)c->ebx)); /* cmp byte ptr [ebp + 0x18], bl */
    { uint32_t v_ = 0x58d378u; PUSH32(c, v_); } /* push 0x1000d378 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete cl */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    c->ecx = (uint32_t)(add32(c, c->ecx, R32((uint32_t)(c->ebp + 0xcu)))); /* add ecx, dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00586f3cu); f_0058a720(c); /* call 0x58a720 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), c->ebx); /* cmp dword ptr [ebp + 0x10], ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    if (c->zf) goto L_00586f48; /* je 0x586f48 */
    W8((uint32_t)(c->ecx), (uint8_t)((uint8_t)0x45u)); /* mov byte ptr [ecx], 0x45 */
L_00586f48:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x30u); /* cmp byte ptr [eax], 0x30 */
    if (c->zf) goto L_00586f8d; /* je 0x586f8d */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ebx, dword ptr [esi + 4] */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->sf) goto L_00586f5c; /* jns 0x586f5c */
    c->ebx = (uint32_t)(neg32(c, c->ebx)); /* neg ebx */
    W8((uint32_t)(c->ecx), (uint8_t)((uint8_t)0x2du)); /* mov byte ptr [ecx], 0x2d */
L_00586f5c:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->ebx, (uint32_t)0x64u); /* cmp ebx, 0x64 */
    if ((c->sf != c->of)) goto L_00586f73; /* jl 0x586f73 */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = 0x64u; PUSH32(c, v_); } /* push 0x64 */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00586f68u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [ecx], al */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00586f6fu, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
    c->ebx = (uint32_t)(c->edx); /* mov ebx, edx */
L_00586f73:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->ebx, (uint32_t)0xau); /* cmp ebx, 0xa */
    if ((c->sf != c->of)) goto L_00586f8a; /* jl 0x586f8a */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = 0xau; PUSH32(c, v_); } /* push 0xa */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00586f7fu, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [ecx], al */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00586f86u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
    c->ebx = (uint32_t)(c->edx); /* mov ebx, edx */
L_00586f8a:;
    { uint32_t a_ = (uint32_t)(c->ecx + 0x1u); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ebx)))); } /* add byte ptr [ecx + 1], bl */
L_00586f8d:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00586f94(CPU *c) { /* FUN_10006f94 */
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
    PUSH32(c, 0x00586fb2u); f_0058a608(c); /* call 0x58a608 */
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
    PUSH32(c, 0x00586fd1u); f_0058a591(c); /* call 0x58a591 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x00586fe0u); f_00586fe9(c); /* call 0x586fe9 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00586fe9(CPU *c) { /* FUN_10006fe9 */
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
    if (c->zf) goto L_00587019; /* je 0x587019 */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xcu))); /* cmp eax, dword ptr [ebp + 0xc] */
    if (!c->zf) goto L_00587019; /* jne 0x587019 */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x2du); /* cmp dword ptr [esi], 0x2d */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete cl */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->ebx)); /* add ecx, ebx */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    W8((uint32_t)(c->eax), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [eax], 0x30 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x1u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax + 1], 0 */
L_00587019:;
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x2du); /* cmp dword ptr [esi], 0x2d */
    c->edi = (uint32_t)(c->ebx); /* mov edi, ebx */
    if (!c->zf) goto L_00587026; /* jne 0x587026 */
    W8((uint32_t)(c->ebx), (uint8_t)((uint8_t)0x2du)); /* mov byte ptr [ebx], 0x2d */
    c->edi = (uint32_t)((uint32_t)(c->ebx + 0x1u)); /* lea edi, [ebx + 1] */
L_00587026:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((!c->zf && c->sf == c->of)) goto L_0058703d; /* jg 0x58703d */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00587035u); f_00587174(c); /* call 0x587174 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W8((uint32_t)(c->edi), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [edi], 0x30 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_0058703f; /* jmp 0x58703f */
L_0058703d:;
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
L_0058703f:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    if ((c->zf || c->sf != c->of)) goto L_00587089; /* jle 0x587089 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x0058704du); f_00587174(c); /* call 0x587174 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x58e600u))); /* mov al, byte ptr [0x1000e600] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov esi, dword ptr [esi + 4] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if ((c->sf == c->of)) goto L_00587089; /* jge 0x587089 */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x14u)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0x14], 0 */
    if (c->zf) goto L_00587068; /* je 0x587068 */
    c->esi = (uint32_t)(neg32(c, c->esi)); /* neg esi */
    goto L_0058706f; /* jmp 0x58706f */
L_00587068:;
    c->esi = (uint32_t)(neg32(c, c->esi)); /* neg esi */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->esi); /* cmp dword ptr [ebp + 0xc], esi */
    if ((c->sf != c->of)) goto L_00587072; /* jl 0x587072 */
L_0058706f:;
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_00587072:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x0058707bu); f_00587174(c); /* call 0x587174 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = 0x30u; PUSH32(c, v_); } /* push 0x30 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00587086u); f_0058a810(c); /* call 0x58a810 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
L_00587089:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00587090(CPU *c) { /* FUN_10007090 */
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
    PUSH32(c, 0x005870b0u); f_0058a608(c); /* call 0x58a608 */
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
    PUSH32(c, 0x005870d2u); f_0058a591(c); /* call 0x58a591 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)((c->sf != c->of) ? 1 : 0); /* setl cl */
    (void)sub32(c, c->eax, (uint32_t)0xfffffffcu); /* cmp eax, -4 */
    if ((c->sf != c->of)) goto L_00587109; /* jl 0x587109 */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if ((c->sf == c->of)) goto L_00587109; /* jge 0x587109 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_005870f5; /* je 0x5870f5 */
L_005870eb:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov al, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_005870eb; /* jne 0x5870eb */
    { uint32_t a_ = (uint32_t)(c->edi + 0xfffffffeu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & ((uint8_t)c->eax))))); } /* and byte ptr [edi - 2], al */
L_005870f5:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x00587104u); f_00586fe9(c); /* call 0x586fe9 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    goto L_0058711e; /* jmp 0x58711e */
L_00587109:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x0058711bu); f_00586ed2(c); /* call 0x586ed2 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
L_0058711e:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00587123(CPU *c) { /* __cfltcvt */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), (uint32_t)0x65u); /* cmp dword ptr [ebp + 0x10], 0x65 */
    if (c->zf) goto L_0058715e; /* je 0x58715e */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), (uint32_t)0x45u); /* cmp dword ptr [ebp + 0x10], 0x45 */
    if (c->zf) goto L_0058715e; /* je 0x58715e */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), (uint32_t)0x66u); /* cmp dword ptr [ebp + 0x10], 0x66 */
    if (!c->zf) goto L_0058714b; /* jne 0x58714b */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00587146u); f_00586f94(c); /* call 0x586f94 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
L_0058714b:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x0058715cu); f_00587090(c); /* call 0x587090 */
    goto L_0058716f; /* jmp 0x58716f */
L_0058715e:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x0058716fu); f_00586e71(c); /* call 0x586e71 */
L_0058716f:;
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00587174(CPU *c) { /* FUN_10007174 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edi, dword ptr [esp + 0xc] */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00587197; /* je 0x587197 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov esi, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00587188u); f_005872d0(c); /* call 0x5872d0 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(add32(c, c->esi, c->edi)); /* add esi, edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00587193u); f_00587ed0(c); /* call 0x587ed0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00587197:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00587199(CPU *c) { /* FUN_10007199 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x1u)); /* lea ecx, [eax + 1] */
    (void)sub32(c, c->ecx, (uint32_t)0x100u); /* cmp ecx, 0x100 */
    if ((!c->cf && !c->zf)) goto L_005871b7; /* ja 0x5871b7 */
    c->ecx = (uint32_t)(R32((uint32_t)(0x58e3f0u))); /* mov ecx, dword ptr [0x1000e3f0] */
    c->eax = (uint32_t)((uint32_t)R16((uint32_t)(c->ecx + c->eax * 2))); /* movzx eax, word ptr [ecx + eax*2] */
    goto L_00587209; /* jmp 0x587209 */
L_005871b7:;
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(0x58e3f0u))); /* mov esi, dword ptr [0x1000e3f0] */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 8)); /* sar ecx, 8 */
    c->edx = (uint32_t)((uint32_t)((uint8_t)c->ecx)); /* movzx edx, cl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi + c->edx * 2 + 0x1u)) & (uint8_t)0x80u)); /* test byte ptr [esi + edx*2 + 1], 0x80 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    if (c->zf) goto L_005871dc; /* je 0x5871dc */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffeu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp - 2], 0 */
    W8((uint32_t)(c->ebp + 0xfffffffcu), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [ebp - 4], cl */
    W8((uint32_t)(c->ebp + 0xfffffffdu), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp - 3], al */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    goto L_005871e5; /* jmp 0x5871e5 */
L_005871dc:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffdu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp - 3], 0 */
    W8((uint32_t)(c->ebp + 0xfffffffcu), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp - 4], al */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
L_005871e5:;
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
    PUSH32(c, 0x005871fcu); f_0058a871(c); /* call 0x58a871 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00587205; /* jne 0x587205 */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00587205:;
    c->eax = (uint32_t)((uint32_t)R16((uint32_t)(c->ebp + 0xau))); /* movzx eax, word ptr [ebp + 0xa] */
L_00587209:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & R32((uint32_t)(c->ebp + 0xcu))))); /* and eax, dword ptr [ebp + 0xc] */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00587210(CPU *c) { /* PTR_00587210 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->eax))); /* or ecx, eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    if (!c->zf) goto L_00587229; /* jne 0x587229 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint64_t r_ = (uint64_t)c->eax * c->ecx; c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = c->edx != 0; } /* mul ecx */
    c->esp += 20; return; /* ret 0x10 */
L_00587229:;
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

void f_00587244(CPU *c) { /* FUN_10007244 */
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
    PUSH32(c, 0x00587265u); f_0058a9ba(c); /* call 0x58a9ba */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x4u)); /* test bl, 4 */
    if (c->zf) goto L_0058727c; /* je 0x58727c */
    c->edi = (uint32_t)((uint32_t)0x200u); /* mov edi, 0x200 */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0xc], esi */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 8], esi */
    goto L_005872aa; /* jmp 0x5872aa */
L_0058727c:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe8u)); /* lea eax, [ebp - 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00587289u); f_0058a50b(c); /* call 0x58a50b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x2u)); /* test bl, 2 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00587295; /* jne 0x587295 */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_0058729a; /* jne 0x58729a */
L_00587295:;
    c->edi = (uint32_t)((uint32_t)0x80u); /* mov edi, 0x80 */
L_0058729a:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x1u)); /* test bl, 1 */
    if (!c->zf) goto L_005872a4; /* jne 0x5872a4 */
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_005872aa; /* jne 0x5872aa */
L_005872a4:;
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi | (uint32_t)0x100u))); /* or edi, 0x100 */
L_005872aa:;
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

void f_005872d0(CPU *c) { /* _strlen */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u)); /* test ecx, 3 */
    if (c->zf) goto L_005872f0; /* je 0x5872f0 */
L_005872dc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov al, byte ptr [ecx] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00587323; /* je 0x587323 */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u)); /* test ecx, 3 */
    if (!c->zf) goto L_005872dc; /* jne 0x5872dc */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x0u)); /* add eax, 0 */
L_005872f0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)((uint32_t)0x7efefeffu); /* mov edx, 0x7efefeff */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ (uint32_t)0xffffffffu))); /* xor eax, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ c->edx))); /* xor eax, edx */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u)); /* test eax, 0x81010100 */
    if (c->zf) goto L_005872f0; /* je 0x5872f0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0xfffffffcu))); /* mov eax, dword ptr [ecx - 4] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00587341; /* je 0x587341 */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_00587337; /* je 0x587337 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0xff0000u)); /* test eax, 0xff0000 */
    if (c->zf) goto L_0058732d; /* je 0x58732d */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0xff000000u)); /* test eax, 0xff000000 */
    if (c->zf) goto L_00587323; /* je 0x587323 */
    goto L_005872f0; /* jmp 0x5872f0 */
L_00587323:;
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0xffffffffu)); /* lea eax, [ecx - 1] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->esp += 4; return; /* ret  */
L_0058732d:;
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0xfffffffeu)); /* lea eax, [ecx - 2] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->esp += 4; return; /* ret  */
L_00587337:;
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0xfffffffdu)); /* lea eax, [ecx - 3] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->esp += 4; return; /* ret  */
L_00587341:;
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0xfffffffcu)); /* lea eax, [ecx - 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->esp += 4; return; /* ret  */
}

void f_0058734b(CPU *c) { /* FUN_1000734b */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x48u)); /* sub esp, 0x48 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x480u; PUSH32(c, v_); } /* push 0x480 */
    PUSH32(c, 0x0058735eu); f_00585fba(c); /* call 0x585fba */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_0058736d; /* jne 0x58736d */
    { uint32_t v_ = 0x1bu; PUSH32(c, v_); } /* push 0x1b */
    PUSH32(c, 0x0058736cu); f_00584fa1(c); /* call 0x584fa1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_0058736d:;
    W32((uint32_t)(0x622dc0u), (uint32_t)(c->esi)); /* mov dword ptr [0x100a2dc0], esi */
    W32((uint32_t)(0x622ec0u), (uint32_t)((uint32_t)0x20u)); /* mov dword ptr [0x100a2ec0], 0x20 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x480u)); /* lea eax, [esi + 0x480] */
L_00587383:;
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if (!c->cf) goto L_005873a5; /* jae 0x5873a5 */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [esi + 4], 0 */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [esi], 0xffffffff */
    { uint32_t a_ = (uint32_t)(c->esi + 0x8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi + 8], 0 */
    W8((uint32_t)(c->esi + 0x5u), (uint8_t)((uint8_t)0xau)); /* mov byte ptr [esi + 5], 0xa */
    c->eax = (uint32_t)(R32((uint32_t)(0x622dc0u))); /* mov eax, dword ptr [0x100a2dc0] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x24u)); /* add esi, 0x24 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x480u)); /* add eax, 0x480 */
    goto L_00587383; /* jmp 0x587383 */
L_005873a5:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffb8u)); /* lea eax, [ebp - 0x48] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x58d070u)); PUSH32(c, 0x005873afu); call_indirect(c, t_); } /* call dword ptr [0x1000d070] */
    (void)sub16(c, R16((uint32_t)(c->ebp + 0xffffffeau)), (uint16_t)0x0u); /* cmp word ptr [ebp - 0x16], 0 */
    if (c->zf) goto L_0058748b; /* je 0x58748b */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0058748b; /* je 0x58748b */
    c->edi = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edi, dword ptr [eax] */
    c->ebx = (uint32_t)((uint32_t)(c->eax + 0x4u)); /* lea ebx, [eax + 4] */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->edi)); /* lea eax, [ebx + edi] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->eax = (uint32_t)((uint32_t)0x800u); /* mov eax, 0x800 */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if ((c->sf != c->of)) goto L_005873db; /* jl 0x5873db */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
L_005873db:;
    (void)sub32(c, R32((uint32_t)(0x622ec0u)), c->edi); /* cmp dword ptr [0x100a2ec0], edi */
    if ((c->sf == c->of)) goto L_00587439; /* jge 0x587439 */
    c->esi = (uint32_t)((uint32_t)0x622dc4u); /* mov esi, 0x100a2dc4 */
L_005873e8:;
    { uint32_t v_ = 0x480u; PUSH32(c, v_); } /* push 0x480 */
    PUSH32(c, 0x005873f2u); f_00585fba(c); /* call 0x585fba */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00587433; /* je 0x587433 */
    { uint32_t a_ = (uint32_t)(0x622ec0u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x20u))); } /* add dword ptr [0x100a2ec0], 0x20 */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x480u)); /* lea ecx, [eax + 0x480] */
L_00587406:;
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->cf) goto L_00587426; /* jae 0x587426 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax + 4], 0 */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [eax], 0xffffffff */
    { uint32_t a_ = (uint32_t)(c->eax + 0x8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [eax + 8], 0 */
    W8((uint32_t)(c->eax + 0x5u), (uint8_t)((uint8_t)0xau)); /* mov byte ptr [eax + 5], 0xa */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x24u)); /* add eax, 0x24 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x480u)); /* add ecx, 0x480 */
    goto L_00587406; /* jmp 0x587406 */
L_00587426:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, R32((uint32_t)(0x622ec0u)), c->edi); /* cmp dword ptr [0x100a2ec0], edi */
    if ((c->sf != c->of)) goto L_005873e8; /* jl 0x5873e8 */
    goto L_00587439; /* jmp 0x587439 */
L_00587433:;
    c->edi = (uint32_t)(R32((uint32_t)(0x622ec0u))); /* mov edi, dword ptr [0x100a2ec0] */
L_00587439:;
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if ((c->zf || c->sf != c->of)) goto L_0058748b; /* jle 0x58748b */
L_0058743f:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    (void)sub32(c, c->ecx, (uint32_t)0xffffffffu); /* cmp ecx, -1 */
    if (c->zf) goto L_00587481; /* je 0x587481 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebx))); /* mov al, byte ptr [ebx] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    if (c->zf) goto L_00587481; /* je 0x587481 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x8u)); /* test al, 8 */
    if (!c->zf) goto L_0058745e; /* jne 0x58745e */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t t_ = R32((uint32_t)(0x58d06cu)); PUSH32(c, 0x0058745au); call_indirect(c, t_); } /* call dword ptr [0x1000d06c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00587481; /* je 0x587481 */
L_0058745e:;
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 5)); /* sar ecx, 5 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1fu))); /* and eax, 0x1f */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx * 4 + 0x622dc0u))); /* mov ecx, dword ptr [ecx*4 + 0x100a2dc0] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 8)); /* lea eax, [eax + eax*8] */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->eax * 4)); /* lea eax, [ecx + eax*4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov ecx, dword ptr [ecx] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebx))); /* mov cl, byte ptr [ebx] */
    W8((uint32_t)(c->eax + 0x4u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax + 4], cl */
L_00587481:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x4u))); } /* add dword ptr [ebp - 4], 4 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if ((c->sf != c->of)) goto L_0058743f; /* jl 0x58743f */
L_0058748b:;
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
L_0058748d:;
    c->ecx = (uint32_t)(R32((uint32_t)(0x622dc0u))); /* mov ecx, dword ptr [0x100a2dc0] */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->ebx * 8)); /* lea eax, [ebx + ebx*8] */
    (void)sub32(c, R32((uint32_t)(c->ecx + c->eax * 4)), (uint32_t)0xffffffffu); /* cmp dword ptr [ecx + eax*4], -1 */
    c->esi = (uint32_t)((uint32_t)(c->ecx + c->eax * 4)); /* lea esi, [ecx + eax*4] */
    if (!c->zf) goto L_005874ec; /* jne 0x5874ec */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    W8((uint32_t)(c->esi + 0x4u), (uint8_t)((uint8_t)0x81u)); /* mov byte ptr [esi + 4], 0x81 */
    if (!c->zf) goto L_005874ac; /* jne 0x5874ac */
    { uint32_t v_ = 0xfffffff6u; PUSH32(c, v_); } /* push -0xa */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_005874b6; /* jmp 0x5874b6 */
L_005874ac:;
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xfffffff5u)); /* add eax, -0xb */
L_005874b6:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x58d068u)); PUSH32(c, 0x005874bdu); call_indirect(c, t_); } /* call dword ptr [0x1000d068] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)sub32(c, c->edi, (uint32_t)0xffffffffu); /* cmp edi, -1 */
    if (c->zf) goto L_005874db; /* je 0x5874db */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0x58d06cu)); PUSH32(c, 0x005874cbu); call_indirect(c, t_); } /* call dword ptr [0x1000d06c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_005874db; /* je 0x5874db */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xffu))); /* and eax, 0xff */
    W32((uint32_t)(c->esi), (uint32_t)(c->edi)); /* mov dword ptr [esi], edi */
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_005874e1; /* jne 0x5874e1 */
L_005874db:;
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x40u)))); } /* or byte ptr [esi + 4], 0x40 */
    goto L_005874f0; /* jmp 0x5874f0 */
L_005874e1:;
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_005874f0; /* jne 0x5874f0 */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x8u)))); } /* or byte ptr [esi + 4], 8 */
    goto L_005874f0; /* jmp 0x5874f0 */
L_005874ec:;
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x80u)))); } /* or byte ptr [esi + 4], 0x80 */
L_005874f0:;
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    (void)sub32(c, c->ebx, (uint32_t)0x3u); /* cmp ebx, 3 */
    if ((c->sf != c->of)) goto L_0058748d; /* jl 0x58748d */
    { uint32_t v_ = R32((uint32_t)(0x622ec0u)); PUSH32(c, v_); } /* push dword ptr [0x100a2ec0] */
    { uint32_t t_ = R32((uint32_t)(0x58d064u)); PUSH32(c, 0x00587502u); call_indirect(c, t_); } /* call dword ptr [0x1000d064] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00587507(CPU *c) { /* FUN_10007507 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)((uint32_t)0x622dc0u); /* mov esi, 0x100a2dc0 */
L_0058750f:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0058754c; /* je 0x58754c */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x480u)); /* add eax, 0x480 */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (!c->cf) goto L_00587541; /* jae 0x587541 */
    c->ebx = (uint32_t)((uint32_t)(c->edi + 0xcu)); /* lea ebx, [edi + 0xc] */
L_00587523:;
    (void)sub32(c, R32((uint32_t)(c->ebx + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebx - 4], 0 */
    if (c->zf) goto L_00587530; /* je 0x587530 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(0x58d048u)); PUSH32(c, 0x00587530u); call_indirect(c, t_); } /* call dword ptr [0x1000d048] */
L_00587530:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x24u)); /* add edi, 0x24 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x480u)); /* add eax, 0x480 */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x24u)); /* add ebx, 0x24 */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_00587523; /* jb 0x587523 */
L_00587541:;
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    PUSH32(c, 0x00587548u); f_005861ff(c); /* call 0x5861ff */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi], 0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_0058754c:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, c->esi, (uint32_t)0x622ec0u); /* cmp esi, 0x100a2ec0 */
    if ((c->sf != c->of)) goto L_0058750f; /* jl 0x58750f */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_0058755b(CPU *c) { /* FUN_1000755b */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, R32((uint32_t)(0x622ec8u)), c->ebx); /* cmp dword ptr [0x100a2ec8], ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_0058756d; /* jne 0x58756d */
    PUSH32(c, 0x0058756du); f_0058b263(c); /* call 0x58b263 */
L_0058756d:;
    c->esi = (uint32_t)(R32((uint32_t)(0x6217bcu))); /* mov esi, dword ptr [0x100a17bc] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
L_00587575:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_0058758d; /* je 0x58758d */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x3du); /* cmp al, 0x3d */
    if (c->zf) goto L_00587580; /* je 0x587580 */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
L_00587580:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00587586u); f_005872d0(c); /* call 0x5872d0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esi = (uint32_t)((uint32_t)(c->esi + c->eax + 0x1u)); /* lea esi, [esi + eax + 1] */
    goto L_00587575; /* jmp 0x587575 */
L_0058758d:;
    c->eax = (uint32_t)((uint32_t)(c->edi * 4 + 0x4u)); /* lea eax, [edi*4 + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0058759au); f_00585fba(c); /* call 0x585fba */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    W32((uint32_t)(0x6217ecu), (uint32_t)(c->esi)); /* mov dword ptr [0x100a17ec], esi */
    if (!c->zf) goto L_005875af; /* jne 0x5875af */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x005875aeu); f_00584fa1(c); /* call 0x584fa1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_005875af:;
    c->edi = (uint32_t)(R32((uint32_t)(0x6217bcu))); /* mov edi, dword ptr [0x100a17bc] */
    (void)sub8(c, R8((uint32_t)(c->edi)), ((uint8_t)c->ebx)); /* cmp byte ptr [edi], bl */
    if (c->zf) goto L_005875f2; /* je 0x5875f2 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
L_005875ba:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x005875c0u); f_005872d0(c); /* call 0x5872d0 */
    c->ebp = (uint32_t)(c->eax); /* mov ebp, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ebp = (uint32_t)(inc32(c, c->ebp)); /* inc ebp */
    (void)sub8(c, R8((uint32_t)(c->edi)), (uint8_t)0x3du); /* cmp byte ptr [edi], 0x3d */
    if (c->zf) goto L_005875eb; /* je 0x5875eb */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x005875cfu); f_00585fba(c); /* call 0x585fba */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    if (!c->zf) goto L_005875de; /* jne 0x5875de */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x005875ddu); f_00584fa1(c); /* call 0x584fa1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_005875de:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    PUSH32(c, 0x005875e6u); f_0058a720(c); /* call 0x58a720 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_005875eb:;
    c->edi = (uint32_t)(add32(c, c->edi, c->ebp)); /* add edi, ebp */
    (void)sub8(c, R8((uint32_t)(c->edi)), ((uint8_t)c->ebx)); /* cmp byte ptr [edi], bl */
    if (!c->zf) goto L_005875ba; /* jne 0x5875ba */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
L_005875f2:;
    { uint32_t v_ = R32((uint32_t)(0x6217bcu)); PUSH32(c, v_); } /* push dword ptr [0x100a17bc] */
    PUSH32(c, 0x005875fdu); f_005861ff(c); /* call 0x5861ff */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(0x6217bcu), (uint32_t)(c->ebx)); /* mov dword ptr [0x100a17bc], ebx */
    W32((uint32_t)(c->esi), (uint32_t)(c->ebx)); /* mov dword ptr [esi], ebx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0x622ec4u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x100a2ec4], 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00587614(CPU *c) { /* FUN_10007614 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, R32((uint32_t)(0x622ec8u)), c->ebx); /* cmp dword ptr [0x100a2ec8], ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_0058762b; /* jne 0x58762b */
    PUSH32(c, 0x0058762bu); f_0058b263(c); /* call 0x58b263 */
L_0058762b:;
    c->esi = (uint32_t)((uint32_t)0x621874u); /* mov esi, 0x100a1874 */
    { uint32_t v_ = 0x104u; PUSH32(c, v_); } /* push 0x104 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(0x58d074u)); PUSH32(c, 0x0058763du); call_indirect(c, t_); } /* call dword ptr [0x1000d074] */
    c->eax = (uint32_t)(R32((uint32_t)(0x622ed4u))); /* mov eax, dword ptr [0x100a2ed4] */
    W32((uint32_t)(0x6217fcu), (uint32_t)(c->esi)); /* mov dword ptr [0x100a17fc], esi */
    c->edi = (uint32_t)(c->esi); /* mov edi, esi */
    (void)sub8(c, R8((uint32_t)(c->eax)), ((uint8_t)c->ebx)); /* cmp byte ptr [eax], bl */
    if (c->zf) goto L_00587650; /* je 0x587650 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
L_00587650:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00587660u); f_005876ad(c); /* call 0x5876ad */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->ecx * 4)); /* lea eax, [eax + ecx*4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0058766fu); f_00585fba(c); /* call 0x585fba */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (!c->zf) goto L_00587680; /* jne 0x587680 */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    PUSH32(c, 0x0058767fu); f_00584fa1(c); /* call 0x584fa1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00587680:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->eax * 4)); /* lea eax, [esi + eax*4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00587696u); f_005876ad(c); /* call 0x5876ad */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    W32((uint32_t)(0x6217e4u), (uint32_t)(c->esi)); /* mov dword ptr [0x100a17e4], esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0x6217e0u), (uint32_t)(c->eax)); /* mov dword ptr [0x100a17e0], eax */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_005876ad(CPU *c) { /* FUN_100076ad */
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
    if (c->zf) goto L_005876d7; /* je 0x5876d7 */
    W32((uint32_t)(c->edi), (uint32_t)(c->esi)); /* mov dword ptr [edi], esi */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 0xc], edi */
L_005876d7:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x22u); /* cmp byte ptr [eax], 0x22 */
    if (!c->zf) goto L_00587720; /* jne 0x587720 */
L_005876dc:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1u))); /* mov dl, byte ptr [eax + 1] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x22u); /* cmp dl, 0x22 */
    if (c->zf) goto L_0058770e; /* je 0x58770e */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_0058770e; /* je 0x58770e */
    c->edx = (uint32_t)((uint32_t)((uint8_t)c->edx)); /* movzx edx, dl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edx + 0x621c61u)) & (uint8_t)0x4u)); /* test byte ptr [edx + 0x100a1c61], 4 */
    if (c->zf) goto L_00587701; /* je 0x587701 */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00587701; /* je 0x587701 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
L_00587701:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_005876dc; /* je 0x5876dc */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    goto L_005876dc; /* jmp 0x5876dc */
L_0058770e:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00587718; /* je 0x587718 */
    { uint32_t a_ = (uint32_t)(c->esi); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [esi], 0 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_00587718:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x22u); /* cmp byte ptr [eax], 0x22 */
    if (!c->zf) goto L_00587763; /* jne 0x587763 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_00587763; /* jmp 0x587763 */
L_00587720:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_0058772b; /* je 0x58772b */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_0058772b:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ebx = (uint32_t)((uint32_t)((uint8_t)c->edx)); /* movzx ebx, dl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebx + 0x621c61u)) & (uint8_t)0x4u)); /* test byte ptr [ebx + 0x100a1c61], 4 */
    if (c->zf) goto L_00587746; /* je 0x587746 */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00587745; /* je 0x587745 */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov bl, byte ptr [eax] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [esi], bl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_00587745:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
L_00587746:;
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x20u); /* cmp dl, 0x20 */
    if (c->zf) goto L_00587754; /* je 0x587754 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00587758; /* je 0x587758 */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x9u); /* cmp dl, 9 */
    if (!c->zf) goto L_00587720; /* jne 0x587720 */
L_00587754:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (!c->zf) goto L_0058775b; /* jne 0x58775b */
L_00587758:;
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    goto L_00587763; /* jmp 0x587763 */
L_0058775b:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00587763; /* je 0x587763 */
    { uint32_t a_ = (uint32_t)(c->esi + 0xffffffffu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [esi - 1], 0 */
L_00587763:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0x18u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp + 0x18], 0 */
L_00587767:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (c->zf) goto L_00587850; /* je 0x587850 */
L_00587770:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x20u); /* cmp dl, 0x20 */
    if (c->zf) goto L_0058777c; /* je 0x58777c */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x9u); /* cmp dl, 9 */
    if (!c->zf) goto L_0058777f; /* jne 0x58777f */
L_0058777c:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_00587770; /* jmp 0x587770 */
L_0058777f:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (c->zf) goto L_00587850; /* je 0x587850 */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00587794; /* je 0x587794 */
    W32((uint32_t)(c->edi), (uint32_t)(c->esi)); /* mov dword ptr [edi], esi */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 0xc], edi */
L_00587794:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov edx, dword ptr [ebp + 0x14] */
    { uint32_t a_ = (uint32_t)(c->edx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [edx] */
L_00587799:;
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp + 8], 1 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
L_005877a2:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x5cu); /* cmp byte ptr [eax], 0x5c */
    if (!c->zf) goto L_005877ab; /* jne 0x5877ab */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    goto L_005877a2; /* jmp 0x5877a2 */
L_005877ab:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x22u); /* cmp byte ptr [eax], 0x22 */
    if (!c->zf) goto L_005877dc; /* jne 0x5877dc */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x1u)); /* test bl, 1 */
    if (!c->zf) goto L_005877da; /* jne 0x5877da */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x18u)), c->edi); /* cmp dword ptr [ebp + 0x18], edi */
    if (c->zf) goto L_005877c9; /* je 0x5877c9 */
    (void)sub8(c, R8((uint32_t)(c->eax + 0x1u)), (uint8_t)0x22u); /* cmp byte ptr [eax + 1], 0x22 */
    c->edx = (uint32_t)((uint32_t)(c->eax + 0x1u)); /* lea edx, [eax + 1] */
    if (!c->zf) goto L_005877c9; /* jne 0x5877c9 */
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    goto L_005877cc; /* jmp 0x5877cc */
L_005877c9:;
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 8], edi */
L_005877cc:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x18u)), c->edx); /* cmp dword ptr [ebp + 0x18], edx */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete dl */
    W32((uint32_t)(c->ebp + 0x18u), (uint32_t)(c->edx)); /* mov dword ptr [ebp + 0x18], edx */
L_005877da:;
    c->ebx = (uint32_t)(shr32(c, c->ebx, 1)); /* shr ebx, 1 */
L_005877dc:;
    c->edx = (uint32_t)(c->ebx); /* mov edx, ebx */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_005877f1; /* je 0x5877f1 */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
L_005877e4:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_005877ec; /* je 0x5877ec */
    W8((uint32_t)(c->esi), (uint8_t)((uint8_t)0x5cu)); /* mov byte ptr [esi], 0x5c */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_005877ec:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->zf) goto L_005877e4; /* jne 0x5877e4 */
L_005877f1:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00587841; /* je 0x587841 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x18u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x18], 0 */
    if (!c->zf) goto L_00587807; /* jne 0x587807 */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x20u); /* cmp dl, 0x20 */
    if (c->zf) goto L_00587841; /* je 0x587841 */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x9u); /* cmp dl, 9 */
    if (c->zf) goto L_00587841; /* je 0x587841 */
L_00587807:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    if (c->zf) goto L_0058783b; /* je 0x58783b */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_0058782a; /* je 0x58782a */
    c->ebx = (uint32_t)((uint32_t)((uint8_t)c->edx)); /* movzx ebx, dl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebx + 0x621c61u)) & (uint8_t)0x4u)); /* test byte ptr [ebx + 0x100a1c61], 4 */
    if (c->zf) goto L_00587823; /* je 0x587823 */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
L_00587823:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    goto L_00587839; /* jmp 0x587839 */
L_0058782a:;
    c->edx = (uint32_t)((uint32_t)((uint8_t)c->edx)); /* movzx edx, dl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edx + 0x621c61u)) & (uint8_t)0x4u)); /* test byte ptr [edx + 0x100a1c61], 4 */
    if (c->zf) goto L_00587839; /* je 0x587839 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
L_00587839:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
L_0058783b:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_00587799; /* jmp 0x587799 */
L_00587841:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00587849; /* je 0x587849 */
    { uint32_t a_ = (uint32_t)(c->esi); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [esi], 0 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_00587849:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    goto L_00587767; /* jmp 0x587767 */
L_00587850:;
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00587857; /* je 0x587857 */
    { uint32_t a_ = (uint32_t)(c->edi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [edi], 0 */
L_00587857:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [eax] */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00587861(CPU *c) { /* FUN_10007861 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(0x621978u))); /* mov eax, dword ptr [0x100a1978] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(0x58d088u))); /* mov ebp, dword ptr [0x1000d088] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (!c->zf) goto L_005878af; /* jne 0x5878af */
    { uint32_t t_ = c->ebp; PUSH32(c, 0x0058787eu); call_indirect(c, t_); } /* call ebp */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (c->zf) goto L_00587890; /* je 0x587890 */
    W32((uint32_t)(0x621978u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x100a1978], 1 */
    goto L_005878b8; /* jmp 0x5878b8 */
L_00587890:;
    { uint32_t t_ = R32((uint32_t)(0x58d084u)); PUSH32(c, 0x00587896u); call_indirect(c, t_); } /* call dword ptr [0x1000d084] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    if (c->zf) goto L_0058798a; /* je 0x58798a */
    W32((uint32_t)(0x621978u), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [0x100a1978], 2 */
    goto L_0058793e; /* jmp 0x58793e */
L_005878af:;
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_00587939; /* jne 0x587939 */
L_005878b8:;
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (!c->zf) goto L_005878c8; /* jne 0x5878c8 */
    { uint32_t t_ = c->ebp; PUSH32(c, 0x005878beu); call_indirect(c, t_); } /* call ebp */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (c->zf) goto L_0058798a; /* je 0x58798a */
L_005878c8:;
    (void)sub16(c, R16((uint32_t)(c->esi)), ((uint16_t)c->ebx)); /* cmp word ptr [esi], bx */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    if (c->zf) goto L_005878dd; /* je 0x5878dd */
L_005878cf:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub16(c, R16((uint32_t)(c->eax)), ((uint16_t)c->ebx)); /* cmp word ptr [eax], bx */
    if (!c->zf) goto L_005878cf; /* jne 0x5878cf */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub16(c, R16((uint32_t)(c->eax)), ((uint16_t)c->ebx)); /* cmp word ptr [eax], bx */
    if (!c->zf) goto L_005878cf; /* jne 0x5878cf */
L_005878dd:;
    c->eax = (uint32_t)(sub32(c, c->eax, c->esi)); /* sub eax, esi */
    c->edi = (uint32_t)(R32((uint32_t)(0x58d080u))); /* mov edi, dword ptr [0x1000d080] */
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
    { uint32_t t_ = c->edi; PUSH32(c, 0x005878f6u); call_indirect(c, t_); } /* call edi */
    c->ebp = (uint32_t)(c->eax); /* mov ebp, eax */
    (void)sub32(c, c->ebp, c->ebx); /* cmp ebp, ebx */
    if (c->zf) goto L_0058792e; /* je 0x58792e */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x00587902u); f_00585fba(c); /* call 0x585fba */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    if (c->zf) goto L_0058792e; /* je 0x58792e */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x24u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x24] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00587918u); call_indirect(c, t_); } /* call edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_0058792a; /* jne 0x58792a */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    PUSH32(c, 0x00587925u); f_005861ff(c); /* call 0x5861ff */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x10], ebx */
L_0058792a:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ebx, dword ptr [esp + 0x10] */
L_0058792e:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(0x58d07cu)); PUSH32(c, 0x00587935u); call_indirect(c, t_); } /* call dword ptr [0x1000d07c] */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    goto L_0058798c; /* jmp 0x58798c */
L_00587939:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_0058798a; /* jne 0x58798a */
L_0058793e:;
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    if (!c->zf) goto L_0058794e; /* jne 0x58794e */
    { uint32_t t_ = R32((uint32_t)(0x58d084u)); PUSH32(c, 0x00587948u); call_indirect(c, t_); } /* call dword ptr [0x1000d084] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    if (c->zf) goto L_0058798a; /* je 0x58798a */
L_0058794e:;
    (void)sub8(c, R8((uint32_t)(c->edi)), ((uint8_t)c->ebx)); /* cmp byte ptr [edi], bl */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    if (c->zf) goto L_0058795e; /* je 0x58795e */
L_00587954:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), ((uint8_t)c->ebx)); /* cmp byte ptr [eax], bl */
    if (!c->zf) goto L_00587954; /* jne 0x587954 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), ((uint8_t)c->ebx)); /* cmp byte ptr [eax], bl */
    if (!c->zf) goto L_00587954; /* jne 0x587954 */
L_0058795e:;
    c->eax = (uint32_t)(sub32(c, c->eax, c->edi)); /* sub eax, edi */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ebp = (uint32_t)(c->eax); /* mov ebp, eax */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x00587969u); f_00585fba(c); /* call 0x585fba */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (!c->zf) goto L_00587974; /* jne 0x587974 */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    goto L_0058797f; /* jmp 0x58797f */
L_00587974:;
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x0058797cu); f_00589590(c); /* call 0x589590 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_0058797f:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0x58d078u)); PUSH32(c, 0x00587986u); call_indirect(c, t_); } /* call dword ptr [0x1000d078] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    goto L_0058798c; /* jmp 0x58798c */
L_0058798a:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_0058798c:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00587993(CPU *c) { /* FUN_10007993 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi], 0 */
    { uint32_t t_ = R32((uint32_t)(0x58d060u)); PUSH32(c, 0x005879a3u); call_indirect(c, t_); } /* call dword ptr [0x1000d060] */
    (void)sub16(c, R16((uint32_t)(c->eax)), (uint16_t)0x5a4du); /* cmp word ptr [eax], 0x5a4d */
    if (!c->zf) goto L_005879be; /* jne 0x5879be */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x3cu))); /* mov ecx, dword ptr [eax + 0x3c] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_005879be; /* je 0x5879be */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1au))); /* mov cl, byte ptr [eax + 0x1a] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esi], cl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1bu))); /* mov al, byte ptr [eax + 0x1b] */
    W8((uint32_t)(c->esi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [esi + 1], al */
L_005879be:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_005879c0(CPU *c) { /* FUN_100079c0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->eax = (uint32_t)((uint32_t)0x122cu); /* mov eax, 0x122c */
    PUSH32(c, 0x005879cdu); f_0058b630(c); /* call 0x58b630 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff68u)); /* lea eax, [ebp - 0x98] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(c->ebp + 0xffffff68u), (uint32_t)((uint32_t)0x94u)); /* mov dword ptr [ebp - 0x98], 0x94 */
    { uint32_t t_ = R32((uint32_t)(0x58d090u)); PUSH32(c, 0x005879e5u); call_indirect(c, t_); } /* call dword ptr [0x1000d090] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00587a03; /* je 0x587a03 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffff78u)), (uint32_t)0x2u); /* cmp dword ptr [ebp - 0x88], 2 */
    if (!c->zf) goto L_00587a03; /* jne 0x587a03 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffff6cu)), (uint32_t)0x5u); /* cmp dword ptr [ebp - 0x94], 5 */
    if (c->cf) goto L_00587a03; /* jb 0x587a03 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_00587b05; /* jmp 0x587b05 */
L_00587a03:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffedd4u)); /* lea eax, [ebp - 0x122c] */
    { uint32_t v_ = 0x1090u; PUSH32(c, v_); } /* push 0x1090 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x58d398u; PUSH32(c, v_); } /* push 0x1000d398 */
    { uint32_t t_ = R32((uint32_t)(0x58d08cu)); PUSH32(c, 0x00587a1au); call_indirect(c, t_); } /* call dword ptr [0x1000d08c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00587af2; /* je 0x587af2 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffedd4u)); /* lea ecx, [ebp - 0x122c] */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xffffedd4u)), ((uint8_t)c->ebx)); /* cmp byte ptr [ebp - 0x122c], bl */
    if (c->zf) goto L_00587a45; /* je 0x587a45 */
L_00587a32:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov al, byte ptr [ecx] */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x61u); /* cmp al, 0x61 */
    if ((c->sf != c->of)) goto L_00587a40; /* jl 0x587a40 */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x7au); /* cmp al, 0x7a */
    if ((!c->zf && c->sf == c->of)) goto L_00587a40; /* jg 0x587a40 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sub8(c, ((uint8_t)c->eax), (uint8_t)0x20u)); /* sub al, 0x20 */
    W8((uint32_t)(c->ecx), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ecx], al */
L_00587a40:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub8(c, R8((uint32_t)(c->ecx)), ((uint8_t)c->ebx)); /* cmp byte ptr [ecx], bl */
    if (!c->zf) goto L_00587a32; /* jne 0x587a32 */
L_00587a45:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffedd4u)); /* lea eax, [ebp - 0x122c] */
    { uint32_t v_ = 0x16u; PUSH32(c, v_); } /* push 0x16 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x58d380u; PUSH32(c, v_); } /* push 0x1000d380 */
    PUSH32(c, 0x00587a58u); f_0058b5f0(c); /* call 0x58b5f0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00587a67; /* jne 0x587a67 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffedd4u)); /* lea eax, [ebp - 0x122c] */
    goto L_00587ab0; /* jmp 0x587ab0 */
L_00587a67:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe64u)); /* lea eax, [ebp - 0x19c] */
    { uint32_t v_ = 0x104u; PUSH32(c, v_); } /* push 0x104 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(0x58d074u)); PUSH32(c, 0x00587a7au); call_indirect(c, t_); } /* call dword ptr [0x1000d074] */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xfffffe64u)), ((uint8_t)c->ebx)); /* cmp byte ptr [ebp - 0x19c], bl */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffe64u)); /* lea ecx, [ebp - 0x19c] */
    if (c->zf) goto L_00587a9b; /* je 0x587a9b */
L_00587a88:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov al, byte ptr [ecx] */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x61u); /* cmp al, 0x61 */
    if ((c->sf != c->of)) goto L_00587a96; /* jl 0x587a96 */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x7au); /* cmp al, 0x7a */
    if ((!c->zf && c->sf == c->of)) goto L_00587a96; /* jg 0x587a96 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sub8(c, ((uint8_t)c->eax), (uint8_t)0x20u)); /* sub al, 0x20 */
    W8((uint32_t)(c->ecx), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ecx], al */
L_00587a96:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub8(c, R8((uint32_t)(c->ecx)), ((uint8_t)c->ebx)); /* cmp byte ptr [ecx], bl */
    if (!c->zf) goto L_00587a88; /* jne 0x587a88 */
L_00587a9b:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe64u)); /* lea eax, [ebp - 0x19c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffedd4u)); /* lea eax, [ebp - 0x122c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00587aaeu); f_0058b570(c); /* call 0x58b570 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00587ab0:;
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_00587af2; /* je 0x587af2 */
    { uint32_t v_ = 0x2cu; PUSH32(c, v_); } /* push 0x2c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00587abcu); f_0058b4b0(c); /* call 0x58b4b0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00587af2; /* je 0x587af2 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), ((uint8_t)c->ebx)); /* cmp byte ptr [eax], bl */
    if (c->zf) goto L_00587ad7; /* je 0x587ad7 */
L_00587ac9:;
    (void)sub8(c, R8((uint32_t)(c->ecx)), (uint8_t)0x3bu); /* cmp byte ptr [ecx], 0x3b */
    if (!c->zf) goto L_00587ad2; /* jne 0x587ad2 */
    W8((uint32_t)(c->ecx), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ecx], bl */
    goto L_00587ad3; /* jmp 0x587ad3 */
L_00587ad2:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
L_00587ad3:;
    (void)sub8(c, R8((uint32_t)(c->ecx)), ((uint8_t)c->ebx)); /* cmp byte ptr [ecx], bl */
    if (!c->zf) goto L_00587ac9; /* jne 0x587ac9 */
L_00587ad7:;
    { uint32_t v_ = 0xau; PUSH32(c, v_); } /* push 0xa */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00587ae0u); f_0058b27f(c); /* call 0x58b27f */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (c->zf) goto L_00587b05; /* je 0x587b05 */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (c->zf) goto L_00587b05; /* je 0x587b05 */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_00587b05; /* je 0x587b05 */
L_00587af2:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00587afbu); f_00587993(c); /* call 0x587993 */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xfffffffcu)), (uint8_t)0x6u); /* cmp byte ptr [ebp - 4], 6 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x3u)); /* add eax, 3 */
L_00587b05:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00587b08(CPU *c) { /* FUN_10007b08 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    (void)sub32(c, R32((uint32_t)(c->esp + 0x8u)), c->eax); /* cmp dword ptr [esp + 8], eax */
    { uint32_t v_ = 0x1000u; PUSH32(c, v_); } /* push 0x1000 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete al */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x58d098u)); PUSH32(c, 0x00587b1fu); call_indirect(c, t_); } /* call dword ptr [0x1000d098] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(0x622da0u), (uint32_t)(c->eax)); /* mov dword ptr [0x100a2da0], eax */
    if (c->zf) goto L_00587b5e; /* je 0x587b5e */
    PUSH32(c, 0x00587b2du); f_005879c0(c); /* call 0x5879c0 */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    W32((uint32_t)(0x622da4u), (uint32_t)(c->eax)); /* mov dword ptr [0x100a2da4], eax */
    if (!c->zf) goto L_00587b44; /* jne 0x587b44 */
    { uint32_t v_ = 0x3f8u; PUSH32(c, v_); } /* push 0x3f8 */
    PUSH32(c, 0x00587b41u); f_00588359(c); /* call 0x588359 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00587b4e; /* jmp 0x587b4e */
L_00587b44:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00587b61; /* jne 0x587b61 */
    PUSH32(c, 0x00587b4eu); f_00588ea0(c); /* call 0x588ea0 */
L_00587b4e:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00587b61; /* jne 0x587b61 */
    { uint32_t v_ = R32((uint32_t)(0x622da0u)); PUSH32(c, v_); } /* push dword ptr [0x100a2da0] */
    { uint32_t t_ = R32((uint32_t)(0x58d094u)); PUSH32(c, 0x00587b5eu); call_indirect(c, t_); } /* call dword ptr [0x1000d094] */
L_00587b5e:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_00587b61:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_00587b65(CPU *c) { /* FUN_10007b65 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x622da4u))); /* mov eax, dword ptr [0x100a2da4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00587bd7; /* jne 0x587bd7 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, R32((uint32_t)(0x622d94u)), c->ebx); /* cmp dword ptr [0x100a2d94], ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(0x58d054u))); /* mov ebp, dword ptr [0x1000d054] */
    if ((c->zf || c->sf != c->of)) goto L_00587bc3; /* jle 0x587bc3 */
    c->eax = (uint32_t)(R32((uint32_t)(0x622d98u))); /* mov eax, dword ptr [0x100a2d98] */
    c->edi = (uint32_t)(R32((uint32_t)(0x58d09cu))); /* mov edi, dword ptr [0x1000d09c] */
    c->esi = (uint32_t)((uint32_t)(c->eax + 0xcu)); /* lea esi, [eax + 0xc] */
L_00587b91:;
    { uint32_t v_ = 0x4000u; PUSH32(c, v_); } /* push 0x4000 */
    { uint32_t v_ = 0x100000u; PUSH32(c, v_); } /* push 0x100000 */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00587b9fu); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = 0x8000u; PUSH32(c, v_); } /* push 0x8000 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00587baau); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esi + 4] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x622da0u)); PUSH32(c, v_); } /* push dword ptr [0x100a2da0] */
    { uint32_t t_ = c->ebp; PUSH32(c, 0x00587bb7u); call_indirect(c, t_); } /* call ebp */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x14u)); /* add esi, 0x14 */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    (void)sub32(c, c->ebx, R32((uint32_t)(0x622d94u))); /* cmp ebx, dword ptr [0x100a2d94] */
    if ((c->sf != c->of)) goto L_00587b91; /* jl 0x587b91 */
L_00587bc3:;
    { uint32_t v_ = R32((uint32_t)(0x622d98u)); PUSH32(c, v_); } /* push dword ptr [0x100a2d98] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x622da0u)); PUSH32(c, v_); } /* push dword ptr [0x100a2da0] */
    { uint32_t t_ = c->ebp; PUSH32(c, 0x00587bd3u); call_indirect(c, t_); } /* call ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    goto L_00587bfe; /* jmp 0x587bfe */
L_00587bd7:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00587bfe; /* jne 0x587bfe */
    c->edi = (uint32_t)((uint32_t)0x58e758u); /* mov edi, 0x1000e758 */
    c->esi = (uint32_t)(c->edi); /* mov esi, edi */
L_00587be3:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00587bf8; /* je 0x587bf8 */
    { uint32_t v_ = 0x8000u; PUSH32(c, v_); } /* push 0x8000 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x58d09cu)); PUSH32(c, 0x00587bf8u); call_indirect(c, t_); } /* call dword ptr [0x1000d09c] */
L_00587bf8:;
    c->esi = (uint32_t)(R32((uint32_t)(c->esi))); /* mov esi, dword ptr [esi] */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_00587be3; /* jne 0x587be3 */
L_00587bfe:;
    { uint32_t v_ = R32((uint32_t)(0x622da0u)); PUSH32(c, v_); } /* push dword ptr [0x100a2da0] */
    { uint32_t t_ = R32((uint32_t)(0x58d094u)); PUSH32(c, 0x00587c0au); call_indirect(c, t_); } /* call dword ptr [0x1000d094] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00587c0d(CPU *c) { /* FUN_10007c0d */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 16; return; /* ret 0xc */
}

void f_00587c13(CPU *c) { /* FUN_10007c13 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x6217c4u))); /* mov eax, dword ptr [0x100a17c4] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_00587c2a; /* je 0x587c2a */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00587c4b; /* jne 0x587c4b */
    (void)sub32(c, R32((uint32_t)(0x6217c8u)), (uint32_t)0x1u); /* cmp dword ptr [0x100a17c8], 1 */
    if (!c->zf) goto L_00587c4b; /* jne 0x587c4b */
L_00587c2a:;
    { uint32_t v_ = 0xfcu; PUSH32(c, v_); } /* push 0xfc */
    PUSH32(c, 0x00587c34u); f_00587c4c(c); /* call 0x587c4c */
    c->eax = (uint32_t)(R32((uint32_t)(0x62197cu))); /* mov eax, dword ptr [0x100a197c] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00587c40; /* je 0x587c40 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00587c40u); call_indirect(c, t_); } /* call eax */
L_00587c40:;
    { uint32_t v_ = 0xffu; PUSH32(c, v_); } /* push 0xff */
    PUSH32(c, 0x00587c4au); f_00587c4c(c); /* call 0x587c4c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00587c4b:;
    c->esp += 4; return; /* ret  */
}

void f_00587c4c(CPU *c) { /* FUN_10007c4c */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x1a4u)); /* sub esp, 0x1a4 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->eax = (uint32_t)((uint32_t)0x58e638u); /* mov eax, 0x1000e638 */
L_00587c5f:;
    (void)sub32(c, c->edx, R32((uint32_t)(c->eax))); /* cmp edx, dword ptr [eax] */
    if (c->zf) goto L_00587c6e; /* je 0x587c6e */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->eax, (uint32_t)0x58e6c8u); /* cmp eax, 0x1000e6c8 */
    if ((c->sf != c->of)) goto L_00587c5f; /* jl 0x587c5f */
L_00587c6e:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->esi = (uint32_t)(shl32(c, c->esi, 3)); /* shl esi, 3 */
    (void)sub32(c, c->edx, R32((uint32_t)(c->esi + 0x58e638u))); /* cmp edx, dword ptr [esi + 0x1000e638] */
    if (!c->zf) goto L_00587d9c; /* jne 0x587d9c */
    c->eax = (uint32_t)(R32((uint32_t)(0x6217c4u))); /* mov eax, dword ptr [0x100a17c4] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_00587d76; /* je 0x587d76 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00587c9f; /* jne 0x587c9f */
    (void)sub32(c, R32((uint32_t)(0x6217c8u)), (uint32_t)0x1u); /* cmp dword ptr [0x100a17c8], 1 */
    if (c->zf) goto L_00587d76; /* je 0x587d76 */
L_00587c9f:;
    (void)sub32(c, c->edx, (uint32_t)0xfcu); /* cmp edx, 0xfc */
    if (c->zf) goto L_00587d9c; /* je 0x587d9c */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea eax, [ebp - 0x1a4] */
    { uint32_t v_ = 0x104u; PUSH32(c, v_); } /* push 0x104 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t t_ = R32((uint32_t)(0x58d074u)); PUSH32(c, 0x00587cbfu); call_indirect(c, t_); } /* call dword ptr [0x1000d074] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00587cd6; /* jne 0x587cd6 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea eax, [ebp - 0x1a4] */
    { uint32_t v_ = 0x58d688u; PUSH32(c, v_); } /* push 0x1000d688 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00587cd4u); f_0058a720(c); /* call 0x58a720 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00587cd6:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea eax, [ebp - 0x1a4] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea edi, [ebp - 0x1a4] */
    PUSH32(c, 0x00587ce9u); f_005872d0(c); /* call 0x5872d0 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->eax, (uint32_t)0x3cu); /* cmp eax, 0x3c */
    if ((c->cf || c->zf)) goto L_00587d19; /* jbe 0x587d19 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea eax, [ebp - 0x1a4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00587cfcu); f_005872d0(c); /* call 0x5872d0 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea eax, [ebp - 0x1a4] */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3bu)); /* sub eax, 0x3b */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t v_ = 0x58d684u; PUSH32(c, v_); } /* push 0x1000d684 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00587d16u); f_00584bb0(c); /* call 0x584bb0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_00587d19:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff60u)); /* lea eax, [ebp - 0xa0] */
    { uint32_t v_ = 0x58d668u; PUSH32(c, v_); } /* push 0x1000d668 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00587d2au); f_0058a720(c); /* call 0x58a720 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff60u)); /* lea eax, [ebp - 0xa0] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00587d37u); f_0058a730(c); /* call 0x58a730 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff60u)); /* lea eax, [ebp - 0xa0] */
    { uint32_t v_ = 0x58d664u; PUSH32(c, v_); } /* push 0x1000d664 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00587d48u); f_0058a730(c); /* call 0x58a730 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x58e63cu)); PUSH32(c, v_); } /* push dword ptr [esi + 0x1000e63c] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff60u)); /* lea eax, [ebp - 0xa0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00587d5au); f_0058a730(c); /* call 0x58a730 */
    { uint32_t v_ = 0x12010u; PUSH32(c, v_); } /* push 0x12010 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff60u)); /* lea eax, [ebp - 0xa0] */
    { uint32_t v_ = 0x58d63cu; PUSH32(c, v_); } /* push 0x1000d63c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00587d70u); f_0058b65f(c); /* call 0x58b65f */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    goto L_00587d9c; /* jmp 0x587d9c */
L_00587d76:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x8u)); /* lea eax, [ebp + 8] */
    c->esi = (uint32_t)((uint32_t)(c->esi + 0x58e63cu)); /* lea esi, [esi + 0x1000e63c] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    PUSH32(c, 0x00587d89u); f_005872d0(c); /* call 0x5872d0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    { uint32_t v_ = 0xfffffff4u; PUSH32(c, v_); } /* push -0xc */
    { uint32_t t_ = R32((uint32_t)(0x58d068u)); PUSH32(c, 0x00587d95u); call_indirect(c, t_); } /* call dword ptr [0x1000d068] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x58d0a0u)); PUSH32(c, 0x00587d9cu); call_indirect(c, t_); } /* call dword ptr [0x1000d0a0] */
L_00587d9c:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00587d9f(CPU *c) { /* FUN_10007d9f */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    { uint32_t t_ = R32((uint32_t)(0x58d0a4u)); PUSH32(c, 0x00587db1u); call_indirect(c, t_); } /* call dword ptr [0x1000d0a4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00587db7; /* je 0x587db7 */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_00587db7:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00587dbb(CPU *c) { /* FUN_10007dbb */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    { uint32_t t_ = R32((uint32_t)(0x58d0a8u)); PUSH32(c, 0x00587dcdu); call_indirect(c, t_); } /* call dword ptr [0x1000d0a8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00587dd3; /* je 0x587dd3 */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_00587dd3:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00587dd7(CPU *c) { /* FUN_10007dd7 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    { uint32_t t_ = R32((uint32_t)(0x58d0acu)); PUSH32(c, 0x00587de5u); call_indirect(c, t_); } /* call dword ptr [0x1000d0ac] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00587deb; /* je 0x587deb */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_00587deb:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00587df0(CPU *c) { /* PTR_00587df0 */
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
    if (!c->zf) goto L_00587e98; /* jne 0x587e98 */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    W32((uint32_t)(c->ebx + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebx - 4], eax */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebx + 0xcu))); /* mov esi, dword ptr [ebx + 0xc] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov edi, dword ptr [ebx + 8] */
L_00587e2b:;
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (c->zf) goto L_00587e91; /* je 0x587e91 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea ecx, [esi + esi*2] */
    (void)sub32(c, R32((uint32_t)(c->edi + c->ecx * 4 + 0x4u)), (uint32_t)0x0u); /* cmp dword ptr [edi + ecx*4 + 4], 0 */
    if (c->zf) goto L_00587e7f; /* je 0x587e7f */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)((uint32_t)(c->ebx + 0x10u)); /* lea ebp, [ebx + 0x10] */
    { uint32_t t_ = R32((uint32_t)(c->edi + c->ecx * 4 + 0x4u)); PUSH32(c, 0x00587e43u); call_indirect(c, t_); } /* call dword ptr [edi + ecx*4 + 4] */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ebx, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->eax))); /* or eax, eax */
    if (c->zf) goto L_00587e7f; /* je 0x587e7f */
    if (c->sf) goto L_00587e8a; /* js 0x587e8a */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov edi, dword ptr [ebx + 8] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00587e57u); f_00584928(c); /* call 0x584928 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->ebp = (uint32_t)((uint32_t)(c->ebx + 0x10u)); /* lea ebp, [ebx + 0x10] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00587e64u); f_0058496a(c); /* call 0x58496a */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea ecx, [esi + esi*2] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + c->ecx * 4 + 0x8u))); /* mov eax, dword ptr [edi + ecx*4 + 8] */
    PUSH32(c, 0x00587e75u); f_005849fe(c); /* call 0x5849fe */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + c->ecx * 4))); /* mov eax, dword ptr [edi + ecx*4] */
    W32((uint32_t)(c->ebx + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 0xc], eax */
    { uint32_t t_ = R32((uint32_t)(c->edi + c->ecx * 4 + 0x8u)); PUSH32(c, 0x00587e7fu); call_indirect(c, t_); } /* call dword ptr [edi + ecx*4 + 8] */
L_00587e7f:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov edi, dword ptr [ebx + 8] */
    c->ecx = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea ecx, [esi + esi*2] */
    c->esi = (uint32_t)(R32((uint32_t)(c->edi + c->ecx * 4))); /* mov esi, dword ptr [edi + ecx*4] */
    goto L_00587e2b; /* jmp 0x587e2b */
L_00587e8a:;
    c->eax = (uint32_t)((uint32_t)0x0u); /* mov eax, 0 */
    goto L_00587ead; /* jmp 0x587ead */
L_00587e91:;
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    goto L_00587ead; /* jmp 0x587ead */
L_00587e98:;
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)((uint32_t)(c->ebx + 0x10u)); /* lea ebp, [ebx + 0x10] */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00587ea4u); f_0058496a(c); /* call 0x58496a */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
L_00587ead:;
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00587eb5(CPU *c) { /* FUN_10007eb5 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov ebp, dword ptr [ecx] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x1cu))); /* mov eax, dword ptr [ecx + 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x18u))); /* mov eax, dword ptr [ecx + 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00587ec9u); f_0058496a(c); /* call 0x58496a */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 8; return; /* ret 4 */
}

void f_00587ed0(CPU *c) { /* FUN_10007ed0 */
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
    if ((c->cf || c->zf)) goto L_00587ef0; /* jbe 0x587ef0 */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_00588068; /* jb 0x588068 */
L_00587ef0:;
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x3u)); /* test edi, 3 */
    if (!c->zf) goto L_00587f0c; /* jne 0x587f0c */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u))); /* and edx, 3 */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) goto L_00587f2c; /* jb 0x587f2c */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x588018u)); switch (t_) { case 0x00588028u: goto L_00588028; case 0x00588030u: goto L_00588030; case 0x0058803cu: goto L_0058803c; case 0x00588050u: goto L_00588050; default: jump_indirect(c, t_, 0x00587f05u); return; } } /* jmp dword ptr [edx*4 + 0x10008018] */
L_00587f0c:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edx = (uint32_t)((uint32_t)0x3u); /* mov edx, 3 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x4u)); /* sub ecx, 4 */
    if (c->cf) goto L_00587f24; /* jb 0x587f24 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x3u))); /* and eax, 3 */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->eax * 4 + 0x587f30u)); switch (t_) {  default: jump_indirect(c, t_, 0x00587f1du); return; } } /* jmp dword ptr [eax*4 + 0x10007f30] */
L_00587f24:;
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0x588028u)); switch (t_) {  default: jump_indirect(c, t_, 0x00587f24u); return; } } /* jmp dword ptr [ecx*4 + 0x10008028] */
L_00587f2c:;
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0x587facu)); switch (t_) { case 0x00587fccu: goto L_00587fcc; case 0x00587fd4u: goto L_00587fd4; case 0x00587fdcu: goto L_00587fdc; case 0x00587fe4u: goto L_00587fe4; case 0x00587fecu: goto L_00587fec; case 0x00587ff4u: goto L_00587ff4; case 0x00587ffcu: goto L_00587ffc; case 0x0058800fu: goto L_0058800f; default: jump_indirect(c, t_, 0x00587f2cu); return; } } /* jmp dword ptr [ecx*4 + 0x10007fac] */
L_00587fcc:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe4u))); /* mov eax, dword ptr [esi + ecx*4 - 0x1c] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x1c], eax */
L_00587fd4:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe8u))); /* mov eax, dword ptr [esi + ecx*4 - 0x18] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x18], eax */
L_00587fdc:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffecu))); /* mov eax, dword ptr [esi + ecx*4 - 0x14] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffecu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x14], eax */
L_00587fe4:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff0u))); /* mov eax, dword ptr [esi + ecx*4 - 0x10] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x10], eax */
L_00587fec:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff4u))); /* mov eax, dword ptr [esi + ecx*4 - 0xc] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0xc], eax */
L_00587ff4:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff8u))); /* mov eax, dword ptr [esi + ecx*4 - 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 8], eax */
L_00587ffc:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
L_0058800f:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x588018u)); switch (t_) { case 0x00588028u: goto L_00588028; case 0x00588030u: goto L_00588030; case 0x0058803cu: goto L_0058803c; case 0x00588050u: goto L_00588050; default: jump_indirect(c, t_, 0x0058800fu); return; } } /* jmp dword ptr [edx*4 + 0x10008018] */
L_00588028:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00588030:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0058803c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00588050:;
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
L_00588068:;
    c->esi = (uint32_t)((uint32_t)(c->ecx + c->esi + 0xfffffffcu)); /* lea esi, [ecx + esi - 4] */
    c->edi = (uint32_t)((uint32_t)(c->ecx + c->edi + 0xfffffffcu)); /* lea edi, [ecx + edi - 4] */
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x3u)); /* test edi, 3 */
    if (!c->zf) goto L_0058809c; /* jne 0x58809c */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u))); /* and edx, 3 */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) goto L_00588090; /* jb 0x588090 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x5881b0u)); switch (t_) { case 0x005881c0u: goto L_005881c0; case 0x005881c8u: goto L_005881c8; case 0x005881d8u: goto L_005881d8; case 0x005881ecu: goto L_005881ec; default: jump_indirect(c, t_, 0x00588087u); return; } } /* jmp dword ptr [edx*4 + 0x100081b0] */
L_00588090:;
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0x588160u)); switch (t_) { case 0x005881a7u: goto L_005881a7; default: jump_indirect(c, t_, 0x00588092u); return; } } /* jmp dword ptr [ecx*4 + 0x10008160] */
L_0058809c:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edx = (uint32_t)((uint32_t)0x3u); /* mov edx, 3 */
    (void)sub32(c, c->ecx, (uint32_t)0x4u); /* cmp ecx, 4 */
    if (c->cf) goto L_005880b4; /* jb 0x5880b4 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x3u))); /* and eax, 3 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->eax * 4 + 0x5880b8u)); switch (t_) {  default: jump_indirect(c, t_, 0x005880adu); return; } } /* jmp dword ptr [eax*4 + 0x100080b8] */
L_005880b4:;
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0x5881b0u)); switch (t_) { case 0x005881c0u: goto L_005881c0; case 0x005881c8u: goto L_005881c8; case 0x005881d8u: goto L_005881d8; case 0x005881ecu: goto L_005881ec; default: jump_indirect(c, t_, 0x005880b4u); return; } } /* jmp dword ptr [ecx*4 + 0x100081b0] */
L_005881a7:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x5881b0u)); switch (t_) { case 0x005881c0u: goto L_005881c0; case 0x005881c8u: goto L_005881c8; case 0x005881d8u: goto L_005881d8; case 0x005881ecu: goto L_005881ec; default: jump_indirect(c, t_, 0x005881a7u); return; } } /* jmp dword ptr [edx*4 + 0x100081b0] */
L_005881c0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_005881c8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_005881d8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_005881ec:;
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

void f_00587f2c(CPU *c) { /* PTR_00587f2c */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0x587facu)); switch (t_) { case 0x00587fccu: goto L_00587fcc; case 0x00587fd4u: goto L_00587fd4; case 0x00587fdcu: goto L_00587fdc; case 0x00587fe4u: goto L_00587fe4; case 0x00587fecu: goto L_00587fec; case 0x00587ff4u: goto L_00587ff4; case 0x00587ffcu: goto L_00587ffc; case 0x0058800fu: goto L_0058800f; default: jump_indirect(c, t_, 0x00587f2cu); return; } } /* jmp dword ptr [ecx*4 + 0x10007fac] */
L_00587fcc:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe4u))); /* mov eax, dword ptr [esi + ecx*4 - 0x1c] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x1c], eax */
L_00587fd4:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe8u))); /* mov eax, dword ptr [esi + ecx*4 - 0x18] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x18], eax */
L_00587fdc:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffecu))); /* mov eax, dword ptr [esi + ecx*4 - 0x14] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffecu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x14], eax */
L_00587fe4:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff0u))); /* mov eax, dword ptr [esi + ecx*4 - 0x10] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x10], eax */
L_00587fec:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff4u))); /* mov eax, dword ptr [esi + ecx*4 - 0xc] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0xc], eax */
L_00587ff4:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff8u))); /* mov eax, dword ptr [esi + ecx*4 - 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 8], eax */
L_00587ffc:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
L_0058800f:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x588018u)); switch (t_) { case 0x00588028u: goto L_00588028; case 0x00588030u: goto L_00588030; case 0x0058803cu: goto L_0058803c; case 0x00588050u: goto L_00588050; default: jump_indirect(c, t_, 0x0058800fu); return; } } /* jmp dword ptr [edx*4 + 0x10008018] */
L_00588028:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00588030:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0058803c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00588050:;
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

void f_00587f40(CPU *c) { /* PTR_00587f40 */
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
    if (c->cf) { f_00587f2c(c); return; } /* jb 0x587f2c */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x588018u)); switch (t_) { case 0x00588028u: goto L_00588028; case 0x00588030u: goto L_00588030; case 0x0058803cu: goto L_0058803c; case 0x00588050u: goto L_00588050; default: jump_indirect(c, t_, 0x00587f62u); return; } } /* jmp dword ptr [edx*4 + 0x10008018] */
L_00588028:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00588030:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0058803c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00588050:;
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

void f_00587f60(CPU *c) { /* PTR_00587f60 */
    PREEMPT_POLL(c);
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x588018u)); switch (t_) { case 0x00588028u: goto L_00588028; case 0x00588030u: goto L_00588030; case 0x0058803cu: goto L_0058803c; case 0x00588050u: goto L_00588050; default: jump_indirect(c, t_, 0x00587f62u); return; } } /* jmp dword ptr [edx*4 + 0x10008018] */
L_00588028:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00588030:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0058803c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00588050:;
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

void f_00587f6c(CPU *c) { /* PTR_00587f6c */
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
    if (c->cf) { f_00587f2c(c); return; } /* jb 0x587f2c */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x588018u)); switch (t_) { case 0x00588028u: goto L_00588028; case 0x00588030u: goto L_00588030; case 0x0058803cu: goto L_0058803c; case 0x00588050u: goto L_00588050; default: jump_indirect(c, t_, 0x00587f88u); return; } } /* jmp dword ptr [edx*4 + 0x10008018] */
L_00588028:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00588030:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0058803c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00588050:;
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

void f_00587f90(CPU *c) { /* PTR_00587f90 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & c->ecx))); /* and edx, ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) { f_00587f2c(c); return; } /* jb 0x587f2c */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x588018u)); switch (t_) { case 0x00588028u: goto L_00588028; case 0x00588030u: goto L_00588030; case 0x0058803cu: goto L_0058803c; case 0x00588050u: goto L_00588050; default: jump_indirect(c, t_, 0x00587fa2u); return; } } /* jmp dword ptr [edx*4 + 0x10008018] */
L_00588028:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00588030:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0058803c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00588050:;
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

void f_00587fcc(CPU *c) { /* PTR_00587fcc */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x588018u)); switch (t_) { case 0x00588028u: goto L_00588028; case 0x00588030u: goto L_00588030; case 0x0058803cu: goto L_0058803c; case 0x00588050u: goto L_00588050; default: jump_indirect(c, t_, 0x0058800fu); return; } } /* jmp dword ptr [edx*4 + 0x10008018] */
L_00588028:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00588030:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0058803c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00588050:;
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

void f_00587fd4(CPU *c) { /* PTR_00587fd4 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x588018u)); switch (t_) { case 0x00588028u: goto L_00588028; case 0x00588030u: goto L_00588030; case 0x0058803cu: goto L_0058803c; case 0x00588050u: goto L_00588050; default: jump_indirect(c, t_, 0x0058800fu); return; } } /* jmp dword ptr [edx*4 + 0x10008018] */
L_00588028:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00588030:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0058803c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00588050:;
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

void f_00587fdc(CPU *c) { /* PTR_00587fdc */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x588018u)); switch (t_) { case 0x00588028u: goto L_00588028; case 0x00588030u: goto L_00588030; case 0x0058803cu: goto L_0058803c; case 0x00588050u: goto L_00588050; default: jump_indirect(c, t_, 0x0058800fu); return; } } /* jmp dword ptr [edx*4 + 0x10008018] */
L_00588028:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00588030:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0058803c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00588050:;
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

void f_00587fe4(CPU *c) { /* PTR_00587fe4 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x588018u)); switch (t_) { case 0x00588028u: goto L_00588028; case 0x00588030u: goto L_00588030; case 0x0058803cu: goto L_0058803c; case 0x00588050u: goto L_00588050; default: jump_indirect(c, t_, 0x0058800fu); return; } } /* jmp dword ptr [edx*4 + 0x10008018] */
L_00588028:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00588030:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0058803c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00588050:;
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

void f_00587fec(CPU *c) { /* PTR_00587fec */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x588018u)); switch (t_) { case 0x00588028u: goto L_00588028; case 0x00588030u: goto L_00588030; case 0x0058803cu: goto L_0058803c; case 0x00588050u: goto L_00588050; default: jump_indirect(c, t_, 0x0058800fu); return; } } /* jmp dword ptr [edx*4 + 0x10008018] */
L_00588028:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00588030:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0058803c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00588050:;
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

void f_00587ff4(CPU *c) { /* PTR_00587ff4 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff8u))); /* mov eax, dword ptr [esi + ecx*4 - 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x588018u)); switch (t_) { case 0x00588028u: goto L_00588028; case 0x00588030u: goto L_00588030; case 0x0058803cu: goto L_0058803c; case 0x00588050u: goto L_00588050; default: jump_indirect(c, t_, 0x0058800fu); return; } } /* jmp dword ptr [edx*4 + 0x10008018] */
L_00588028:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00588030:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0058803c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00588050:;
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

void f_00587ffc(CPU *c) { /* PTR_00587ffc */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x588018u)); switch (t_) { case 0x00588028u: goto L_00588028; case 0x00588030u: goto L_00588030; case 0x0058803cu: goto L_0058803c; case 0x00588050u: goto L_00588050; default: jump_indirect(c, t_, 0x0058800fu); return; } } /* jmp dword ptr [edx*4 + 0x10008018] */
L_00588028:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00588030:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0058803c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00588050:;
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

void f_0058800f(CPU *c) { /* PTR_0058800f */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x588018u)); switch (t_) { case 0x00588028u: goto L_00588028; case 0x00588030u: goto L_00588030; case 0x0058803cu: goto L_0058803c; case 0x00588050u: goto L_00588050; default: jump_indirect(c, t_, 0x0058800fu); return; } } /* jmp dword ptr [edx*4 + 0x10008018] */
L_00588028:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00588030:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0058803c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00588050:;
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

void f_00588028(CPU *c) { /* PTR_00588028 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00588030(CPU *c) { /* PTR_00588030 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0058803c(CPU *c) { /* PTR_0058803c */
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

void f_00588050(CPU *c) { /* PTR_00588050 */
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

void f_00588090(CPU *c) { /* PTR_00588090 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0x588160u)); switch (t_) { case 0x005881a7u: goto L_005881a7; default: jump_indirect(c, t_, 0x00588092u); return; } } /* jmp dword ptr [ecx*4 + 0x10008160] */
L_005881a7:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x5881b0u)); switch (t_) { case 0x005881c0u: goto L_005881c0; case 0x005881c8u: goto L_005881c8; case 0x005881d8u: goto L_005881d8; case 0x005881ecu: goto L_005881ec; default: jump_indirect(c, t_, 0x005881a7u); return; } } /* jmp dword ptr [edx*4 + 0x100081b0] */
L_005881c0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_005881c8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_005881d8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_005881ec:;
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

void f_005880c8(CPU *c) { /* PTR_005880c8 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & c->ecx))); /* and edx, ecx */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) { f_00588090(c); return; } /* jb 0x588090 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x5881b0u)); switch (t_) { case 0x005881c0u: goto L_005881c0; case 0x005881c8u: goto L_005881c8; case 0x005881d8u: goto L_005881d8; case 0x005881ecu: goto L_005881ec; default: jump_indirect(c, t_, 0x005880deu); return; } } /* jmp dword ptr [edx*4 + 0x100081b0] */
L_005881c0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_005881c8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_005881d8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_005881ec:;
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

void f_005880e8(CPU *c) { /* PTR_005880e8 */
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
    if (c->cf) { f_00588090(c); return; } /* jb 0x588090 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x5881b0u)); switch (t_) { case 0x005881c0u: goto L_005881c0; case 0x005881c8u: goto L_005881c8; case 0x005881d8u: goto L_005881d8; case 0x005881ecu: goto L_005881ec; default: jump_indirect(c, t_, 0x00588108u); return; } } /* jmp dword ptr [edx*4 + 0x100081b0] */
L_005881c0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_005881c8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_005881d8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_005881ec:;
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

void f_00588110(CPU *c) { /* PTR_00588110 */
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
    if (c->cf) { f_00588090(c); return; } /* jb 0x588090 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x5881b0u)); switch (t_) { case 0x005881c0u: goto L_005881c0; case 0x005881c8u: goto L_005881c8; case 0x005881d8u: goto L_005881d8; case 0x005881ecu: goto L_005881ec; default: jump_indirect(c, t_, 0x0058813au); return; } } /* jmp dword ptr [edx*4 + 0x100081b0] */
L_005881c0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_005881c8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_005881d8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_005881ec:;
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

void f_00588164(CPU *c) { /* PTR_00588164 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x5881b0u)); switch (t_) { case 0x005881c0u: goto L_005881c0; case 0x005881c8u: goto L_005881c8; case 0x005881d8u: goto L_005881d8; case 0x005881ecu: goto L_005881ec; default: jump_indirect(c, t_, 0x005881a7u); return; } } /* jmp dword ptr [edx*4 + 0x100081b0] */
L_005881c0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_005881c8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_005881d8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_005881ec:;
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

void f_0058816c(CPU *c) { /* PTR_0058816c */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x5881b0u)); switch (t_) { case 0x005881c0u: goto L_005881c0; case 0x005881c8u: goto L_005881c8; case 0x005881d8u: goto L_005881d8; case 0x005881ecu: goto L_005881ec; default: jump_indirect(c, t_, 0x005881a7u); return; } } /* jmp dword ptr [edx*4 + 0x100081b0] */
L_005881c0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_005881c8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_005881d8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_005881ec:;
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

void f_00588174(CPU *c) { /* PTR_00588174 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x5881b0u)); switch (t_) { case 0x005881c0u: goto L_005881c0; case 0x005881c8u: goto L_005881c8; case 0x005881d8u: goto L_005881d8; case 0x005881ecu: goto L_005881ec; default: jump_indirect(c, t_, 0x005881a7u); return; } } /* jmp dword ptr [edx*4 + 0x100081b0] */
L_005881c0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_005881c8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_005881d8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_005881ec:;
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

void f_0058817c(CPU *c) { /* PTR_0058817c */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x5881b0u)); switch (t_) { case 0x005881c0u: goto L_005881c0; case 0x005881c8u: goto L_005881c8; case 0x005881d8u: goto L_005881d8; case 0x005881ecu: goto L_005881ec; default: jump_indirect(c, t_, 0x005881a7u); return; } } /* jmp dword ptr [edx*4 + 0x100081b0] */
L_005881c0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_005881c8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_005881d8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_005881ec:;
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

void f_00588184(CPU *c) { /* PTR_00588184 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x5881b0u)); switch (t_) { case 0x005881c0u: goto L_005881c0; case 0x005881c8u: goto L_005881c8; case 0x005881d8u: goto L_005881d8; case 0x005881ecu: goto L_005881ec; default: jump_indirect(c, t_, 0x005881a7u); return; } } /* jmp dword ptr [edx*4 + 0x100081b0] */
L_005881c0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_005881c8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_005881d8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_005881ec:;
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

void f_0058818c(CPU *c) { /* PTR_0058818c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x8u))); /* mov eax, dword ptr [esi + ecx*4 + 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x4u))); /* mov eax, dword ptr [esi + ecx*4 + 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x5881b0u)); switch (t_) { case 0x005881c0u: goto L_005881c0; case 0x005881c8u: goto L_005881c8; case 0x005881d8u: goto L_005881d8; case 0x005881ecu: goto L_005881ec; default: jump_indirect(c, t_, 0x005881a7u); return; } } /* jmp dword ptr [edx*4 + 0x100081b0] */
L_005881c0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_005881c8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_005881d8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_005881ec:;
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

void f_00588194(CPU *c) { /* PTR_00588194 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x4u))); /* mov eax, dword ptr [esi + ecx*4 + 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x5881b0u)); switch (t_) { case 0x005881c0u: goto L_005881c0; case 0x005881c8u: goto L_005881c8; case 0x005881d8u: goto L_005881d8; case 0x005881ecu: goto L_005881ec; default: jump_indirect(c, t_, 0x005881a7u); return; } } /* jmp dword ptr [edx*4 + 0x100081b0] */
L_005881c0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_005881c8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_005881d8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_005881ec:;
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

void f_005881a7(CPU *c) { /* PTR_005881a7 */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x5881b0u)); switch (t_) { case 0x005881c0u: goto L_005881c0; case 0x005881c8u: goto L_005881c8; case 0x005881d8u: goto L_005881d8; case 0x005881ecu: goto L_005881ec; default: jump_indirect(c, t_, 0x005881a7u); return; } } /* jmp dword ptr [edx*4 + 0x100081b0] */
L_005881c0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_005881c8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_005881d8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_005881ec:;
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

void f_005881c0(CPU *c) { /* PTR_005881c0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_005881c8(CPU *c) { /* PTR_005881c8 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_005881d8(CPU *c) { /* PTR_005881d8 */
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

void f_005881ec(CPU *c) { /* PTR_005881ec */
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

void f_00588205(CPU *c) { /* FUN_10008205 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x58d6a0u; PUSH32(c, v_); } /* push 0x1000d6a0 */
    { uint32_t v_ = 0x587df8u; PUSH32(c, v_); } /* push 0x10007df8 */
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
    if ((!c->cf && !c->zf)) goto L_0058824e; /* ja 0x58824e */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (!c->zf) goto L_00588243; /* jne 0x588243 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00588243:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
    goto L_00588250; /* jmp 0x588250 */
L_0058824e:;
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
L_00588250:;
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x20], ebx */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00588304; /* ja 0x588304 */
    c->eax = (uint32_t)(R32((uint32_t)(0x622da4u))); /* mov eax, dword ptr [0x100a2da4] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_005882a7; /* jne 0x5882a7 */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov edi, dword ptr [ebp - 0x1c] */
    (void)sub32(c, c->edi, R32((uint32_t)(0x622d9cu))); /* cmp edi, dword ptr [0x100a2d9c] */
    if ((!c->cf && !c->zf)) goto L_005882ed; /* ja 0x5882ed */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00588278u); f_00586189(c); /* call 0x586189 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 4], ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00588282u); f_005886f5(c); /* call 0x5886f5 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x0058828fu); f_0058829e(c); /* call 0x58829e */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (c->zf) goto L_005882f2; /* je 0x5882f2 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x1c] */
    goto L_005882e1; /* jmp 0x5882e1 */
L_005882a7:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_005882ed; /* jne 0x5882ed */
    (void)sub32(c, c->esi, R32((uint32_t)(0x59077cu))); /* cmp esi, dword ptr [0x1001077c] */
    if ((!c->cf && !c->zf)) goto L_005882ed; /* ja 0x5882ed */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x005882bbu); f_00586189(c); /* call 0x586189 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x005882ceu); f_00589198(c); /* call 0x589198 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x005882dbu); f_00588327(c); /* call 0x588327 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (c->zf) goto L_005882f2; /* je 0x5882f2 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
L_005882e1:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x20] */
    PUSH32(c, 0x005882eau); f_0058a810(c); /* call 0x58a810 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_005882ed:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (!c->zf) goto L_00588330; /* jne 0x588330 */
L_005882f2:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = R32((uint32_t)(0x622da0u)); PUSH32(c, v_); } /* push dword ptr [0x100a2da0] */
    { uint32_t t_ = R32((uint32_t)(0x58d03cu)); PUSH32(c, 0x00588301u); call_indirect(c, t_); } /* call dword ptr [0x1000d03c] */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
L_00588304:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (!c->zf) goto L_00588330; /* jne 0x588330 */
    (void)sub32(c, R32((uint32_t)(0x621988u)), c->ebx); /* cmp dword ptr [0x100a1988], ebx */
    if (c->zf) goto L_00588330; /* je 0x588330 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00588317u); f_0058956d(c); /* call 0x58956d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00588250; /* jne 0x588250 */
    goto L_00588333; /* jmp 0x588333 */
L_00588330:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov eax, dword ptr [ebp - 0x20] */
L_00588333:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00588250(CPU *c) { /* PTR_00588250 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x20], ebx */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) { f_00588304(c); return; } /* ja 0x588304 */
    c->eax = (uint32_t)(R32((uint32_t)(0x622da4u))); /* mov eax, dword ptr [0x100a2da4] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) { f_005882a7(c); return; } /* jne 0x5882a7 */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov edi, dword ptr [ebp - 0x1c] */
    (void)sub32(c, c->edi, R32((uint32_t)(0x622d9cu))); /* cmp edi, dword ptr [0x100a2d9c] */
    if ((!c->cf && !c->zf)) { f_005882ed(c); return; } /* ja 0x5882ed */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00588278u); f_00586189(c); /* call 0x586189 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 4], ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00588282u); f_005886f5(c); /* call 0x5886f5 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x0058828fu); f_0058829e(c); /* call 0x58829e */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (c->zf) { f_005882f2(c); return; } /* je 0x5882f2 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x1c] */
    { f_005882e1(c); return; } /* jmp 0x5882e1 */
}

void f_00588299(CPU *c) { /* PTR_00588299 */
    PREEMPT_POLL(c);
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    { f_0058829e(c); return; }
}

void f_0058829e(CPU *c) { /* FUN_1000829e */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x005882a5u); f_005861ea(c); /* call 0x5861ea */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_005882a7(CPU *c) { /* PTR_005882a7 */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_005882ed; /* jne 0x5882ed */
    (void)sub32(c, c->esi, R32((uint32_t)(0x59077cu))); /* cmp esi, dword ptr [0x1001077c] */
    if ((!c->cf && !c->zf)) goto L_005882ed; /* ja 0x5882ed */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x005882bbu); f_00586189(c); /* call 0x586189 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x005882ceu); f_00589198(c); /* call 0x589198 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x005882dbu); f_00588327(c); /* call 0x588327 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (c->zf) goto L_005882f2; /* je 0x5882f2 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x20] */
    PUSH32(c, 0x005882eau); f_0058a810(c); /* call 0x58a810 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_005882ed:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (!c->zf) { f_00588330(c); return; } /* jne 0x588330 */
L_005882f2:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = R32((uint32_t)(0x622da0u)); PUSH32(c, v_); } /* push dword ptr [0x100a2da0] */
    { uint32_t t_ = R32((uint32_t)(0x58d03cu)); PUSH32(c, 0x00588301u); call_indirect(c, t_); } /* call dword ptr [0x1000d03c] */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (!c->zf) { f_00588330(c); return; } /* jne 0x588330 */
    (void)sub32(c, R32((uint32_t)(0x621988u)), c->ebx); /* cmp dword ptr [0x100a1988], ebx */
    if (c->zf) { f_00588330(c); return; } /* je 0x588330 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00588317u); f_0058956d(c); /* call 0x58956d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00588250(c); return; } /* jne 0x588250 */
    { f_00588333(c); return; } /* jmp 0x588333 */
}
