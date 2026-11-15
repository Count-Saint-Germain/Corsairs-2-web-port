#include "recomp.h"

void f_00781000(CPU *c) { /* DMAInterface */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    W32((uint32_t)(0x795694u), (uint32_t)(c->eax)); /* mov dword ptr [0x10015694], eax */
    W32((uint32_t)(0x79567cu), (uint32_t)(c->eax)); /* mov dword ptr [0x1001567c], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov eax, dword ptr [eax + 4] */
    W32((uint32_t)(0x795678u), (uint32_t)(c->ecx)); /* mov dword ptr [0x10015678], ecx */
    W32((uint32_t)(0x795680u), (uint32_t)(c->eax)); /* mov dword ptr [0x10015680], eax */
    c->eax = (uint32_t)(R32((uint32_t)(0x795698u))); /* mov eax, dword ptr [0x10015698] */
    c->esp += 4; return; /* ret  */
}

void f_00781030(CPU *c) { /* FUN_10001030 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(0x795694u))); /* mov ecx, dword ptr [0x10015694] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4u)); PUSH32(c, 0x00781044u); call_indirect(c, t_); } /* call dword ptr [eax + 4] */
    c->esp += 4; return; /* ret  */
}

void f_00781050(CPU *c) { /* FUN_10001050 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(0x795694u))); /* mov ecx, dword ptr [0x10015694] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x00781060u); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
    c->esp += 4; return; /* ret  */
}

void f_00781070(CPU *c) { /* FUN_10001070 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x795694u))); /* mov ecx, dword ptr [0x10015694] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4u)); PUSH32(c, 0x0078108au); call_indirect(c, t_); } /* call dword ptr [eax + 4] */
    c->esp += 4; return; /* ret  */
}

void f_00781090(CPU *c) { /* FUN_10001090 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x795694u))); /* mov ecx, dword ptr [0x10015694] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0xcu)); PUSH32(c, 0x007810afu); call_indirect(c, t_); } /* call dword ptr [eax + 0xc] */
    c->esp += 4; return; /* ret  */
}

void f_007810b0(CPU *c) { /* PTR_007810b0 */
    PREEMPT_POLL(c);
    PUSH32(c, 0x007810b5u); f_007810c0(c); /* call 0x7810c0 */
    { f_007811a0(c); return; } /* jmp 0x7811a0 */
}

void f_007810c0(CPU *c) { /* PTR_007810c0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x795698u; PUSH32(c, v_); } /* push 0x10015698 */
    c->ecx = (uint32_t)((uint32_t)0x795684u); /* mov ecx, 0x10015684 */
    PUSH32(c, 0x007810cfu); f_007810d0(c); /* call 0x7810d0 */
    c->esp += 4; return; /* ret  */
}

void f_007810d0(CPU *c) { /* PTR_007810d0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0xc], ecx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x790100u)); /* mov dword ptr [eax], 0x10010100 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 4], edx */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    c->esp += 8; return; /* ret 4 */
}

void f_007810f0(CPU *c) { /* PTR_007810f0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x792040u); /* mov eax, 0x10012040 */
    c->esp += 4; return; /* ret  */
}

void f_00781100(CPU *c) { /* FUN_10001100 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x78f8f4u; PUSH32(c, v_); } /* push 0x1000f8f4 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov eax, dword ptr [ecx + 0xc] */
    { uint32_t v_ = 0x7u; PUSH32(c, v_); } /* push 7 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t v_ = 0x792048u; PUSH32(c, v_); } /* push 0x10012048 */
    { uint32_t v_ = 0x8c8u; PUSH32(c, v_); } /* push 0x8c8 */
    W32((uint32_t)(c->ecx + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 0xc], eax */
    PUSH32(c, 0x0078112eu); f_00781070(c); /* call 0x781070 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->esp), (uint32_t)(c->eax)); /* mov dword ptr [esp], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0xc], 0 */
    if (c->zf) goto L_00781157; /* je 0x781157 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    PUSH32(c, 0x00781148u); f_007811c0(c); /* call 0x7811c0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
L_00781157:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_00781170(CPU *c) { /* FUN_10001170 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00781178u); f_00781190(c); /* call 0x781190 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00781188; /* je 0x781188 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00781185u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00781188:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00781190(CPU *c) { /* FUN_10001190 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx), (uint32_t)((uint32_t)0x790120u)); /* mov dword ptr [ecx], 0x10010120 */
    c->esp += 4; return; /* ret  */
}

void f_007811a0(CPU *c) { /* PTR_007811a0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x7811b0u; PUSH32(c, v_); } /* push 0x100011b0 */
    PUSH32(c, 0x007811aau); f_007868b4(c); /* call 0x7868b4 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_007811b0(CPU *c) { /* PTR_007811b0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)0x795684u); /* mov ecx, 0x10015684 */
    { f_00781190(c); return; } /* jmp 0x781190 */
}

void f_007811c0(CPU *c) { /* FUN_100011c0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x78f963u; PUSH32(c, v_); } /* push 0x1000f963 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x10], esi */
    PUSH32(c, 0x007811e7u); f_00785080(c); /* call 0x785080 */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x7901c0u)); /* mov dword ptr [esi], 0x100101c0 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->esi + 0x6cu), (uint32_t)((uint32_t)0x10u)); /* mov dword ptr [esi + 0x6c], 0x10 */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x20], ebx */
    W32((uint32_t)(c->esi + 0x60u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x60], ebx */
    W32((uint32_t)(c->esi + 0x64u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x64], ebx */
    W32((uint32_t)(c->esi + 0x68u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x68], ebx */
    W32((uint32_t)(c->esi + 0x74u), (uint32_t)((uint32_t)0x7901b0u)); /* mov dword ptr [esi + 0x74], 0x100101b0 */
    W32((uint32_t)(c->esi + 0x78u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x78], ebx */
    W32((uint32_t)(c->esi + 0x80u), (uint32_t)((uint32_t)0x8u)); /* mov dword ptr [esi + 0x80], 8 */
    W32((uint32_t)(c->esi + 0x84u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x84], ebx */
    W32((uint32_t)(c->esi + 0x7cu), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x7c], ebx */
    W32((uint32_t)(c->esi + 0x70u), (uint32_t)((uint32_t)0x7901a4u)); /* mov dword ptr [esi + 0x70], 0x100101a4 */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x88u)); /* lea edi, [esi + 0x88] */
    { uint32_t v_ = 0x40u; PUSH32(c, v_); } /* push 0x40 */
    W8((uint32_t)(c->esp + 0x24u), (uint8_t)((uint8_t)0x2u)); /* mov byte ptr [esp + 0x24], 2 */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x18], edi */
    c->ecx = (uint32_t)((uint32_t)(c->edi + 0x4u)); /* lea ecx, [edi + 4] */
    PUSH32(c, 0x00781240u); f_00785060(c); /* call 0x785060 */
    W32((uint32_t)(c->edi), (uint32_t)((uint32_t)0x790198u)); /* mov dword ptr [edi], 0x10010198 */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    c->ecx = (uint32_t)((uint32_t)(c->edi + 0x1cu)); /* lea ecx, [edi + 0x1c] */
    W8((uint32_t)(c->esp + 0x24u), (uint8_t)((uint8_t)0x3u)); /* mov byte ptr [esp + 0x24], 3 */
    PUSH32(c, 0x00781255u); f_00784820(c); /* call 0x784820 */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    c->ecx = (uint32_t)((uint32_t)(c->edi + 0x34u)); /* lea ecx, [edi + 0x34] */
    W8((uint32_t)(c->esp + 0x24u), (uint8_t)((uint8_t)0x4u)); /* mov byte ptr [esp + 0x24], 4 */
    PUSH32(c, 0x00781264u); f_00784960(c); /* call 0x784960 */
    c->ebp = (uint32_t)((uint32_t)(c->edi + 0x4cu)); /* lea ebp, [edi + 0x4c] */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    W8((uint32_t)(c->esp + 0x24u), (uint8_t)((uint8_t)0x5u)); /* mov byte ptr [esp + 0x24], 5 */
    PUSH32(c, 0x00781275u); f_007851c0(c); /* call 0x7851c0 */
    { uint32_t v_ = 0x792070u; PUSH32(c, v_); } /* push 0x10012070 */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    W8((uint32_t)(c->esp + 0x24u), (uint8_t)((uint8_t)0x6u)); /* mov byte ptr [esp + 0x24], 6 */
    W32((uint32_t)(c->edi + 0x5cu), (uint32_t)(c->ebx)); /* mov dword ptr [edi + 0x5c], ebx */
    PUSH32(c, 0x00781289u); f_007851f0(c); /* call 0x7851f0 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x140u)); /* lea eax, [esi + 0x140] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    W8((uint32_t)(c->esp + 0x20u), (uint8_t)((uint8_t)0x7u)); /* mov byte ptr [esp + 0x20], 7 */
    W32((uint32_t)(c->edx), (uint32_t)(c->ecx)); /* mov dword ptr [edx], ecx */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [edx + 4], ecx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 8], ebx */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0xc], ebx */
    W32((uint32_t)(c->eax + 0x10u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x10], ebx */
    W32((uint32_t)(c->eax + 0x14u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x14], ebx */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x158u)); /* lea eax, [esi + 0x158] */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    W32((uint32_t)(c->edx), (uint32_t)(c->ecx)); /* mov dword ptr [edx], ecx */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [edx + 4], ecx */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x874u)); /* lea ecx, [esi + 0x874] */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 8], ebx */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0xc], ebx */
    W32((uint32_t)(c->eax + 0x10u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x10], ebx */
    W32((uint32_t)(c->eax + 0x14u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x14], ebx */
    PUSH32(c, 0x007812cdu); f_00785eb0(c); /* call 0x785eb0 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x894u)); /* lea ecx, [esi + 0x894] */
    W8((uint32_t)(c->esp + 0x20u), (uint8_t)((uint8_t)0x8u)); /* mov byte ptr [esp + 0x20], 8 */
    PUSH32(c, 0x007812ddu); f_00785eb0(c); /* call 0x785eb0 */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x790140u)); /* mov dword ptr [esi], 0x10010140 */
    W8((uint32_t)(c->esi + 0xf8u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [esi + 0xf8], bl */
    W32((uint32_t)(c->esi + 0x8bcu), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x8bc], ebx */
    W32((uint32_t)(c->esi + 0x8b4u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x8b4], ebx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov ecx, dword ptr [esp + 0x18] */
    W32((uint32_t)(c->esi + 0x8b8u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x8b8], ebx */
    W32((uint32_t)(c->esi + 0x8c4u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x8c4], ebx */
    W8((uint32_t)(c->esi + 0xf9u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [esi + 0xf9], bl */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esp += 4; return; /* ret  */
}

void f_00781320(CPU *c) { /* FUN_10001320 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00781328u); f_00781340(c); /* call 0x781340 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00781338; /* je 0x781338 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00781335u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00781338:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00781340(CPU *c) { /* FUN_10001340 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x78f9e1u; PUSH32(c, v_); } /* push 0x1000f9e1 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 8], esi */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x790140u)); /* mov dword ptr [esi], 0x10010140 */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)((uint32_t)0x5u)); /* mov dword ptr [esp + 0x18], 5 */
    PUSH32(c, 0x00781373u); f_007814c0(c); /* call 0x7814c0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8c4u))); /* mov ecx, dword ptr [esi + 0x8c4] */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, c->ecx, c->ebx); /* cmp ecx, ebx */
    if (c->zf) goto L_00781385; /* je 0x781385 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t t_ = R32((uint32_t)(c->eax)); PUSH32(c, 0x00781385u); call_indirect(c, t_); } /* call dword ptr [eax] */
L_00781385:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x894u)); /* lea ecx, [esi + 0x894] */
    W32((uint32_t)(c->esi + 0x8c4u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x8c4], ebx */
    W8((uint32_t)(c->esp + 0x1cu), (uint8_t)((uint8_t)0x4u)); /* mov byte ptr [esp + 0x1c], 4 */
    PUSH32(c, 0x0078139cu); f_00785ec0(c); /* call 0x785ec0 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x874u)); /* lea ecx, [esi + 0x874] */
    W8((uint32_t)(c->esp + 0x1cu), (uint8_t)((uint8_t)0x3u)); /* mov byte ptr [esp + 0x1c], 3 */
    PUSH32(c, 0x007813acu); f_00785ec0(c); /* call 0x785ec0 */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x88u)); /* lea edi, [esi + 0x88] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x10], edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x5cu))); /* mov eax, dword ptr [edi + 0x5c] */
    W8((uint32_t)(c->esp + 0x1cu), (uint8_t)((uint8_t)0x9u)); /* mov byte ptr [esp + 0x1c], 9 */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_007813cb; /* je 0x7813cb */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x007813c8u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_007813cb:;
    c->ecx = (uint32_t)((uint32_t)(c->edi + 0x4cu)); /* lea ecx, [edi + 0x4c] */
    W32((uint32_t)(c->edi + 0x5cu), (uint32_t)(c->ebx)); /* mov dword ptr [edi + 0x5c], ebx */
    W8((uint32_t)(c->esp + 0x1cu), (uint8_t)((uint8_t)0x8u)); /* mov byte ptr [esp + 0x1c], 8 */
    PUSH32(c, 0x007813dbu); f_007856d0(c); /* call 0x7856d0 */
    c->ecx = (uint32_t)((uint32_t)(c->edi + 0x38u)); /* lea ecx, [edi + 0x38] */
    W32((uint32_t)(c->edi + 0x34u), (uint32_t)((uint32_t)0x790278u)); /* mov dword ptr [edi + 0x34], 0x10010278 */
    W8((uint32_t)(c->esp + 0x1cu), (uint8_t)((uint8_t)0x7u)); /* mov byte ptr [esp + 0x1c], 7 */
    W32((uint32_t)(c->ecx), (uint32_t)((uint32_t)0x790268u)); /* mov dword ptr [ecx], 0x10010268 */
    PUSH32(c, 0x007813f5u); f_00784a70(c); /* call 0x784a70 */
    W32((uint32_t)(c->edi + 0x1cu), (uint32_t)((uint32_t)0x79025cu)); /* mov dword ptr [edi + 0x1c], 0x1001025c */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x24u))); /* mov eax, dword ptr [edi + 0x24] */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    W8((uint32_t)(c->esp + 0x1cu), (uint8_t)((uint8_t)0x6u)); /* mov byte ptr [esp + 0x1c], 6 */
    W32((uint32_t)(c->edi + 0x20u), (uint32_t)((uint32_t)0x79024cu)); /* mov dword ptr [edi + 0x20], 0x1001024c */
    W32((uint32_t)(c->edi + 0x30u), (uint32_t)(c->ebx)); /* mov dword ptr [edi + 0x30], ebx */
    W32((uint32_t)(c->edi + 0x28u), (uint32_t)(c->ebx)); /* mov dword ptr [edi + 0x28], ebx */
    if (c->zf) goto L_0078141e; /* je 0x78141e */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0078141bu); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_0078141e:;
    c->ecx = (uint32_t)((uint32_t)(c->edi + 0x4u)); /* lea ecx, [edi + 4] */
    W32((uint32_t)(c->edi + 0x24u), (uint32_t)(c->ebx)); /* mov dword ptr [edi + 0x24], ebx */
    W32((uint32_t)(c->edi), (uint32_t)((uint32_t)0x790198u)); /* mov dword ptr [edi], 0x10010198 */
    W8((uint32_t)(c->esp + 0x1cu), (uint8_t)((uint8_t)0x2u)); /* mov byte ptr [esp + 0x1c], 2 */
    W32((uint32_t)(c->ecx), (uint32_t)((uint32_t)0x79023cu)); /* mov dword ptr [ecx], 0x1001023c */
    PUSH32(c, 0x0078143au); f_00785d70(c); /* call 0x785d70 */
    W32((uint32_t)(c->esi + 0x70u), (uint32_t)((uint32_t)0x7901a4u)); /* mov dword ptr [esi + 0x70], 0x100101a4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x78u))); /* mov eax, dword ptr [esi + 0x78] */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    W8((uint32_t)(c->esp + 0x1cu), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esp + 0x1c], 1 */
    W32((uint32_t)(c->esi + 0x74u), (uint32_t)((uint32_t)0x7901b0u)); /* mov dword ptr [esi + 0x74], 0x100101b0 */
    W32((uint32_t)(c->esi + 0x84u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x84], ebx */
    W32((uint32_t)(c->esi + 0x7cu), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x7c], ebx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    if (c->zf) goto L_00781467; /* je 0x781467 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00781464u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00781467:;
    W32((uint32_t)(c->esi + 0x78u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x78], ebx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x60u))); /* mov eax, dword ptr [esi + 0x60] */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    W8((uint32_t)(c->esp + 0x18u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [esp + 0x18], bl */
    if (c->zf) goto L_0078147e; /* je 0x78147e */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0078147bu); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_0078147e:;
    W32((uint32_t)(c->esi + 0x60u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x60], ebx */
    W32((uint32_t)(c->esi + 0x64u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x64], ebx */
    W32((uint32_t)(c->esi + 0x68u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x68], ebx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x14u))); /* mov eax, dword ptr [esi + 0x14] */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x790218u)); /* mov dword ptr [esi], 0x10010218 */
    c->ecx = (uint32_t)(R32((uint32_t)(0x795678u))); /* mov ecx, dword ptr [0x10015678] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [esp + 0x1c], 0xffffffff */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x007814a4u); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esp += 4; return; /* ret  */
}

void f_007814c0(CPU *c) { /* FUN_100014c0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->ecx); /* mov ebp, ecx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x7cu)), c->ebx); /* cmp dword ptr [ebp + 0x7c], ebx */
    if ((c->cf || c->zf)) goto L_00781508; /* jbe 0x781508 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x10], ebx */
L_007814d2:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x78u))); /* mov esi, dword ptr [ebp + 0x78] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(0x79567cu))); /* mov eax, dword ptr [0x1001567c] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->esi = (uint32_t)(add32(c, c->esi, c->ecx)); /* add esi, ecx */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x60u)); PUSH32(c, 0x007814f3u); call_indirect(c, t_); } /* call dword ptr [edx + 0x60] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x7cu))); /* mov eax, dword ptr [ebp + 0x7c] */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x18u)); /* add ecx, 0x18 */
    (void)sub32(c, c->ebx, c->eax); /* cmp ebx, eax */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x10], ecx */
    if (c->cf) goto L_007814d2; /* jb 0x7814d2 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
L_00781508:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x70u))); /* mov eax, dword ptr [ebp + 0x70] */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0x70u)); /* lea ecx, [ebp + 0x70] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4u)); PUSH32(c, 0x00781511u); call_indirect(c, t_); } /* call dword ptr [eax + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8b4u))); /* mov eax, dword ptr [ebp + 0x8b4] */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_00781524; /* je 0x781524 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00781521u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00781524:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8b8u))); /* mov eax, dword ptr [ebp + 0x8b8] */
    W32((uint32_t)(c->ebp + 0x8b4u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 0x8b4], ebx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_0078153d; /* je 0x78153d */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0078153au); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_0078153d:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0xf8u))); /* mov al, byte ptr [ebp + 0xf8] */
    W32((uint32_t)(c->ebp + 0x8b8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 0x8b8], ebx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00781589; /* jne 0x781589 */
    c->eax = (uint32_t)(R32((uint32_t)(0x79567cu))); /* mov eax, dword ptr [0x1001567c] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->esi = (uint32_t)((uint32_t)(c->ebp + 0x140u)); /* lea esi, [ebp + 0x140] */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x60u)); PUSH32(c, 0x0078156bu); call_indirect(c, t_); } /* call dword ptr [edx + 0x60] */
    c->eax = (uint32_t)(R32((uint32_t)(0x79567cu))); /* mov eax, dword ptr [0x1001567c] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->esi = (uint32_t)((uint32_t)(c->ebp + 0x158u)); /* lea esi, [ebp + 0x158] */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x60u)); PUSH32(c, 0x00781589u); call_indirect(c, t_); } /* call dword ptr [edx + 0x60] */
L_00781589:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00781590(CPU *c) { /* PTR_00781590 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    c->eax = (uint32_t)(R32((uint32_t)(0x79567cu))); /* mov eax, dword ptr [0x1001567c] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->esi = (uint32_t)((uint32_t)(c->ebx + 0x4u)); /* lea esi, [ebx + 4] */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t v_ = 0x79207cu; PUSH32(c, v_); } /* push 0x1001207c */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xb0u)); PUSH32(c, 0x007815bdu); call_indirect(c, t_); } /* call dword ptr [edx + 0xb0] */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    PUSH32(c, 0x007815c4u); f_00781610(c); /* call 0x781610 */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edx = (uint32_t)((uint32_t)0xc1a00000u); /* mov edx, 0xc1a00000 */
L_007815cd:;
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0xc], eax */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x10], ecx */
    FPUSH(c, (double)(int64_t)R64((uint32_t)(c->esp + 0xcu))); /* fild qword ptr [esp + 0xc] */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0x790288u))); /* fsub dword ptr [0x10010288] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x790284u))); /* fmul dword ptr [0x10010284] */
    WF32((uint32_t)(c->ebx + c->eax * 4 + 0x474u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebx + eax*4 + 0x474] */
    if (!c->zf) goto L_007815f6; /* jne 0x7815f6 */
    W32((uint32_t)(c->ebx + 0x474u), (uint32_t)(c->edx)); /* mov dword ptr [ebx + 0x474], edx */
L_007815f6:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub32(c, c->eax, (uint32_t)0x100u); /* cmp eax, 0x100 */
    if (c->cf) goto L_007815cd; /* jb 0x7815cd */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->esp += 4; return; /* ret  */
}

void f_00781610(CPU *c) { /* FUN_10001610 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(0x79567cu))); /* mov ecx, dword ptr [0x1001567c] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x7920f8u; PUSH32(c, v_); } /* push 0x100120f8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x9cu)); PUSH32(c, 0x0078162au); call_indirect(c, t_); } /* call dword ptr [eax + 0x9c] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x79567cu))); /* mov ecx, dword ptr [0x1001567c] */
    { uint32_t v_ = 0x7920f0u; PUSH32(c, v_); } /* push 0x100120f0 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x4cu)); PUSH32(c, 0x0078163au); call_indirect(c, t_); } /* call dword ptr [edx + 0x4c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esi + 0x8c0u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x8c0], eax */
    if (!c->zf) goto L_00781664; /* jne 0x781664 */
    c->eax = (uint32_t)(R32((uint32_t)(0x795678u))); /* mov eax, dword ptr [0x10015678] */
    { uint32_t v_ = 0x7920e4u; PUSH32(c, v_); } /* push 0x100120e4 */
    { uint32_t v_ = 0x44u; PUSH32(c, v_); } /* push 0x44 */
    { uint32_t v_ = 0x792048u; PUSH32(c, v_); } /* push 0x10012048 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x7920b0u; PUSH32(c, v_); } /* push 0x100120b0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00781660u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00781663u, "int3"); /* int3  */
L_00781664:;
    c->ecx = (uint32_t)(R32((uint32_t)(0x79567cu))); /* mov ecx, dword ptr [0x1001567c] */
    { uint32_t v_ = 0x7920a4u; PUSH32(c, v_); } /* push 0x100120a4 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x4cu)); PUSH32(c, 0x00781674u); call_indirect(c, t_); } /* call dword ptr [edx + 0x4c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esi + 0x8bcu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x8bc], eax */
    if (!c->zf) goto L_0078169e; /* jne 0x78169e */
    c->eax = (uint32_t)(R32((uint32_t)(0x795678u))); /* mov eax, dword ptr [0x10015678] */
    { uint32_t v_ = 0x7920a0u; PUSH32(c, v_); } /* push 0x100120a0 */
    { uint32_t v_ = 0x45u; PUSH32(c, v_); } /* push 0x45 */
    { uint32_t v_ = 0x792048u; PUSH32(c, v_); } /* push 0x10012048 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x7920b0u; PUSH32(c, v_); } /* push 0x100120b0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x0078169au); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x0078169du, "int3"); /* int3  */
L_0078169e:;
    c->ecx = (uint32_t)(R32((uint32_t)(0x79567cu))); /* mov ecx, dword ptr [0x1001567c] */
    { uint32_t v_ = 0x7920f8u; PUSH32(c, v_); } /* push 0x100120f8 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xc8u)); PUSH32(c, 0x007816b1u); call_indirect(c, t_); } /* call dword ptr [edx + 0xc8] */
    W32((uint32_t)(c->esi + 0x8c4u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x8c4], eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_007816dc; /* jne 0x7816dc */
    c->eax = (uint32_t)(R32((uint32_t)(0x795678u))); /* mov eax, dword ptr [0x10015678] */
    { uint32_t v_ = 0x79208cu; PUSH32(c, v_); } /* push 0x1001208c */
    { uint32_t v_ = 0x46u; PUSH32(c, v_); } /* push 0x46 */
    { uint32_t v_ = 0x792048u; PUSH32(c, v_); } /* push 0x10012048 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x7920b0u; PUSH32(c, v_); } /* push 0x100120b0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x007816d8u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x007816dbu, "int3"); /* int3  */
L_007816dc:;
    c->esp += 4; return; /* ret  */
}

void f_007816e0(CPU *c) { /* PTR_007816e0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x78f9f8u; PUSH32(c, v_); } /* push 0x1000f9f8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x68u)); /* sub esp, 0x68 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0xf8u))); /* mov al, byte ptr [esi + 0xf8] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00781b98; /* jne 0x781b98 */
    c->ecx = (uint32_t)(R32((uint32_t)(0x79567cu))); /* mov ecx, dword ptr [0x1001567c] */
    c->edx = (uint32_t)((uint32_t)(c->esi + 0x140u)); /* lea edx, [esi + 0x140] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x64u)); PUSH32(c, 0x0078171eu); call_indirect(c, t_); } /* call dword ptr [eax + 0x64] */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->ebp = (uint32_t)(logic32(c, 0)); /* xor ebp, ebp */
    (void)sub32(c, c->ebx, c->ebp); /* cmp ebx, ebp */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(!c->zf ? 1 : 0); /* setne al */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_0078174b; /* jne 0x78174b */
    c->eax = (uint32_t)(R32((uint32_t)(0x795678u))); /* mov eax, dword ptr [0x10015678] */
    { uint32_t v_ = 0x792178u; PUSH32(c, v_); } /* push 0x10012178 */
    { uint32_t v_ = 0x5eu; PUSH32(c, v_); } /* push 0x5e */
    { uint32_t v_ = 0x792048u; PUSH32(c, v_); } /* push 0x10012048 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x7920b0u; PUSH32(c, v_); } /* push 0x100120b0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00781747u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x0078174au, "int3"); /* int3  */
L_0078174b:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8bcu))); /* mov ecx, dword ptr [esi + 0x8bc] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea eax, [esp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x1cu; PUSH32(c, v_); } /* push 0x1c */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x130u)); PUSH32(c, 0x00781760u); call_indirect(c, t_); } /* call dword ptr [edx + 0x130] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8bcu))); /* mov ecx, dword ptr [esi + 0x8bc] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x10u)); /* lea eax, [esp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x8bu; PUSH32(c, v_); } /* push 0x8b */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x130u)); PUSH32(c, 0x00781778u); call_indirect(c, t_); } /* call dword ptr [edx + 0x130] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8bcu))); /* mov ecx, dword ptr [esi + 0x8bc] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x18u)); /* lea eax, [esp + 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x89u; PUSH32(c, v_); } /* push 0x89 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x130u)); PUSH32(c, 0x00781790u); call_indirect(c, t_); } /* call dword ptr [edx + 0x130] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8bcu))); /* mov ecx, dword ptr [esi + 0x8bc] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = 0x89u; PUSH32(c, v_); } /* push 0x89 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x12cu)); PUSH32(c, 0x007817a4u); call_indirect(c, t_); } /* call dword ptr [edx + 0x12c] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x88u))); /* mov edi, dword ptr [esp + 0x88] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0xcu)); PUSH32(c, 0x007817b3u); call_indirect(c, t_); } /* call dword ptr [eax + 0xc] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0xf9u))); /* mov al, byte ptr [esi + 0xf9] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_007817ec; /* jne 0x7817ec */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8bcu))); /* mov ecx, dword ptr [esi + 0x8bc] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = 0x1cu; PUSH32(c, v_); } /* push 0x1c */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x12cu)); PUSH32(c, 0x007817ceu); call_indirect(c, t_); } /* call dword ptr [edx + 0x12c] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x79567cu))); /* mov ecx, dword ptr [0x1001567c] */
    c->edx = (uint32_t)((uint32_t)(c->esi + 0x158u)); /* lea edx, [esi + 0x158] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x64u)); PUSH32(c, 0x007817e0u); call_indirect(c, t_); } /* call dword ptr [eax + 0x64] */
    (void)sub32(c, c->eax, c->ebp); /* cmp eax, ebp */
    if (c->zf) goto L_007817ec; /* je 0x7817ec */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x007817ecu); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
L_007817ec:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8bcu))); /* mov ecx, dword ptr [esi + 0x8bc] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = 0x89u; PUSH32(c, v_); } /* push 0x89 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x12cu)); PUSH32(c, 0x00781800u); call_indirect(c, t_); } /* call dword ptr [eax + 0x12c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8bcu))); /* mov ecx, dword ptr [esi + 0x8bc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x1cu; PUSH32(c, v_); } /* push 0x1c */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x12cu)); PUSH32(c, 0x00781815u); call_indirect(c, t_); } /* call dword ptr [edx + 0x12c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8bcu))); /* mov ecx, dword ptr [esi + 0x8bc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x8bu; PUSH32(c, v_); } /* push 0x8b */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x12cu)); PUSH32(c, 0x0078182du); call_indirect(c, t_); } /* call dword ptr [edx + 0x12c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8bcu))); /* mov ecx, dword ptr [esi + 0x8bc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x89u; PUSH32(c, v_); } /* push 0x89 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x12cu)); PUSH32(c, 0x00781845u); call_indirect(c, t_); } /* call dword ptr [edx + 0x12c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x7cu))); /* mov eax, dword ptr [esi + 0x7c] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, c->eax, c->ebp); /* cmp eax, ebp */
    if ((c->cf || c->zf)) goto L_0078192a; /* jbe 0x78192a */
    W32((uint32_t)(c->esp + 0x88u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0x88], ebp */
L_00781859:;
    c->ecx = (uint32_t)(R32((uint32_t)(0x795694u))); /* mov ecx, dword ptr [0x10015694] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x78u))); /* mov eax, dword ptr [esi + 0x78] */
    c->eax = (uint32_t)(add32(c, c->eax, c->ebp)); /* add eax, ebp */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x64u)); PUSH32(c, 0x0078186au); call_indirect(c, t_); } /* call dword ptr [edx + 0x64] */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xc8u))); /* mov eax, dword ptr [esi + 0xc8] */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    { uint32_t v_ = 0x792160u; PUSH32(c, v_); } /* push 0x10012160 */
    { uint32_t v_ = 0x94u; PUSH32(c, v_); } /* push 0x94 */
    c->edx = (uint32_t)((uint32_t)0x79212cu); /* mov edx, 0x1001212c */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(c->cf ? 1 : 0); /* setb cl */
    PUSH32(c, 0x0078188bu); f_00784910(c); /* call 0x784910 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0xc4u))); /* mov ecx, dword ptr [esi + 0xc4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x88u))); /* mov edx, dword ptr [esp + 0x88] */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->edx)); /* add ecx, edx */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x20], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov eax, dword ptr [ecx + 4] */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x24], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov ecx, dword ptr [ecx + 8] */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x28], ecx */
    if (c->zf) goto L_00781908; /* je 0x781908 */
    c->edx = (uint32_t)((uint32_t)(c->ebx + 0x20u)); /* lea edx, [ebx + 0x20] */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x1c], edx */
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
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x20u))); /* fld dword ptr [esp + 0x20] */
    WF32((uint32_t)(c->edx + 0x30u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edx + 0x30] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x28u))); /* fld dword ptr [esp + 0x28] */
    WF32((uint32_t)(c->edx + 0x38u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edx + 0x38] */
    W32((uint32_t)(c->edx + 0x34u), (uint32_t)((uint32_t)0x40a00000u)); /* mov dword ptr [edx + 0x34], 0x40a00000 */
L_00781908:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x88u))); /* mov ecx, dword ptr [esp + 0x88] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x7cu))); /* mov eax, dword ptr [esi + 0x7c] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->ebp = (uint32_t)(add32(c, c->ebp, (uint32_t)0x18u)); /* add ebp, 0x18 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x28u)); /* add ecx, 0x28 */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    W32((uint32_t)(c->esp + 0x88u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x88], ecx */
    if (c->cf) goto L_00781859; /* jb 0x781859 */
    c->ebp = (uint32_t)(logic32(c, 0)); /* xor ebp, ebp */
L_0078192a:;
    { uint32_t v_ = 0x4fu; PUSH32(c, v_); } /* push 0x4f */
    { uint32_t t_ = R32((uint32_t)(0x7900f4u)); PUSH32(c, 0x00781932u); call_indirect(c, t_); } /* call dword ptr [0x100100f4] */
    (void)logic16(c, (uint16_t)(((uint16_t)c->eax) & ((uint16_t)c->eax))); /* test ax, ax */
    if ((c->sf == c->of)) goto L_0078193e; /* jge 0x78193e */
    { uint32_t a_ = (uint32_t)(0x79569cu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) ^ (uint8_t)0x1u)))); } /* xor byte ptr [0x1001569c], 1 */
L_0078193e:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x79569cu))); /* mov al, byte ptr [0x1001569c] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00781b98; /* je 0x781b98 */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)((uint32_t)0x790298u)); /* mov dword ptr [esp + 0x24], 0x10010298 */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0x28], ebp */
    W32((uint32_t)(c->esp + 0x30u), (uint32_t)((uint32_t)0x8u)); /* mov dword ptr [esp + 0x30], 8 */
    W32((uint32_t)(c->esp + 0x34u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0x34], ebp */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0x2c], ebp */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)((uint32_t)0x79028cu)); /* mov dword ptr [esp + 0x20], 0x1001028c */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xb0u))); /* mov eax, dword ptr [esi + 0xb0] */
    W32((uint32_t)(c->esp + 0x80u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0x80], ebp */
    (void)sub32(c, c->eax, c->ebp); /* cmp eax, ebp */
    W32((uint32_t)(c->esp + 0x88u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0x88], ebp */
    if ((c->cf || c->zf)) goto L_00781ae1; /* jbe 0x781ae1 */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0x1c], ebp */
L_0078198f:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xb0u))); /* mov eax, dword ptr [esi + 0xb0] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x88u))); /* mov edx, dword ptr [esp + 0x88] */
    (void)sub32(c, c->edx, c->eax); /* cmp edx, eax */
    { uint32_t v_ = 0x792110u; PUSH32(c, v_); } /* push 0x10012110 */
    { uint32_t v_ = 0x117u; PUSH32(c, v_); } /* push 0x117 */
    c->edx = (uint32_t)((uint32_t)0x79212cu); /* mov edx, 0x1001212c */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(c->cf ? 1 : 0); /* setb cl */
    PUSH32(c, 0x007819b5u); f_00784910(c); /* call 0x784910 */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi + 0xacu))); /* mov edi, dword ptr [esi + 0xac] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov ecx, dword ptr [esp + 0x1c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov edx, dword ptr [esp + 0x2c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov eax, dword ptr [esp + 0x24] */
    c->edi = (uint32_t)(add32(c, c->edi, c->ecx)); /* add edi, ecx */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x28u)); /* lea ecx, [esp + 0x28] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0xcu)); PUSH32(c, 0x007819d2u); call_indirect(c, t_); } /* call dword ptr [eax + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov eax, dword ptr [esp + 0x2c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov ecx, dword ptr [esp + 0x28] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x2c], eax */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    c->ebx = (uint32_t)((uint32_t)(c->eax + c->ecx + 0xfffffff0u)); /* lea ebx, [eax + ecx - 0x10] */
    W32((uint32_t)(c->ebx + 0xcu), (uint32_t)((uint32_t)0xffffffu)); /* mov dword ptr [ebx + 0xc], 0xffffff */
    c->ebp = (uint32_t)(R32((uint32_t)(c->edi))); /* mov ebp, dword ptr [edi] */
    (void)sub32(c, c->ebp, R32((uint32_t)(c->esi + 0xc8u))); /* cmp ebp, dword ptr [esi + 0xc8] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(c->cf ? 1 : 0); /* setb al */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00781a1f; /* jne 0x781a1f */
    c->eax = (uint32_t)(R32((uint32_t)(0x795678u))); /* mov eax, dword ptr [0x10015678] */
    { uint32_t v_ = 0x792160u; PUSH32(c, v_); } /* push 0x10012160 */
    { uint32_t v_ = 0x94u; PUSH32(c, v_); } /* push 0x94 */
    { uint32_t v_ = 0x79212cu; PUSH32(c, v_); } /* push 0x1001212c */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0x7920b0u; PUSH32(c, v_); } /* push 0x100120b0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00781a1bu); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00781a1eu, "int3"); /* int3  */
L_00781a1f:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0xc4u))); /* mov ecx, dword ptr [esi + 0xc4] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + c->ebp * 4)); /* lea eax, [ebp + ebp*4] */
    c->edx = (uint32_t)((uint32_t)(c->ecx + c->eax * 8)); /* lea edx, [ecx + eax*8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + c->eax * 8))); /* mov eax, dword ptr [ecx + eax*8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov ecx, dword ptr [edx + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov edx, dword ptr [edx + 8] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [ebx + 4], ecx */
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [ebx + 8], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov eax, dword ptr [esp + 0x2c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov edx, dword ptr [esp + 0x24] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x24u)); /* lea ecx, [esp + 0x24] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x00781a4eu); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov eax, dword ptr [esp + 0x2c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov ecx, dword ptr [esp + 0x28] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x2c], eax */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    c->ebx = (uint32_t)((uint32_t)(c->eax + c->ecx + 0xfffffff0u)); /* lea ebx, [eax + ecx - 0x10] */
    W32((uint32_t)(c->ebx + 0xcu), (uint32_t)((uint32_t)0xffffffu)); /* mov dword ptr [ebx + 0xc], 0xffffff */
    c->edi = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov edi, dword ptr [edi + 4] */
    (void)sub32(c, c->edi, R32((uint32_t)(c->esi + 0xc8u))); /* cmp edi, dword ptr [esi + 0xc8] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(c->cf ? 1 : 0); /* setb al */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00781a9c; /* jne 0x781a9c */
    c->eax = (uint32_t)(R32((uint32_t)(0x795678u))); /* mov eax, dword ptr [0x10015678] */
    { uint32_t v_ = 0x792160u; PUSH32(c, v_); } /* push 0x10012160 */
    { uint32_t v_ = 0x94u; PUSH32(c, v_); } /* push 0x94 */
    { uint32_t v_ = 0x79212cu; PUSH32(c, v_); } /* push 0x1001212c */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0x7920b0u; PUSH32(c, v_); } /* push 0x100120b0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00781a98u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00781a9bu, "int3"); /* int3  */
L_00781a9c:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0xc4u))); /* mov ecx, dword ptr [esi + 0xc4] */
    c->eax = (uint32_t)((uint32_t)(c->edi + c->edi * 4)); /* lea eax, [edi + edi*4] */
    c->edx = (uint32_t)((uint32_t)(c->ecx + c->eax * 8)); /* lea edx, [ecx + eax*8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + c->eax * 8))); /* mov eax, dword ptr [ecx + eax*8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov ecx, dword ptr [edx + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov edx, dword ptr [edx + 8] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x88u))); /* mov eax, dword ptr [esp + 0x88] */
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [ebx + 4], ecx */
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [ebx + 8], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov edx, dword ptr [esp + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0xb0u))); /* mov ecx, dword ptr [esi + 0xb0] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0xcu)); /* add edx, 0xc */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    W32((uint32_t)(c->esp + 0x88u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x88], eax */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x1c], edx */
    if (c->cf) goto L_0078198f; /* jb 0x78198f */
L_00781ae1:;
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x38u)); /* lea eax, [esp + 0x38] */
    W32((uint32_t)(c->esp + 0x88u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x88], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x88u))); /* mov eax, dword ptr [esp + 0x88] */
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
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8bcu))); /* mov ecx, dword ptr [esi + 0x8bc] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x38u)); /* lea eax, [esp + 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x100u; PUSH32(c, v_); } /* push 0x100 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x58u)); PUSH32(c, 0x00781b3eu); call_indirect(c, t_); } /* call dword ptr [edx + 0x58] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov edx, dword ptr [esp + 0x2c] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0x8bcu))); /* mov esi, dword ptr [esi + 0x8bc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov eax, dword ptr [esp + 0x28] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edx = (uint32_t)(shr32(c, c->edx, 1)); /* shr edx, 1 */
    { uint32_t v_ = 0x792108u; PUSH32(c, v_); } /* push 0x10012108 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0xd0u)); PUSH32(c, 0x00781b61u); call_indirect(c, t_); } /* call dword ptr [ecx + 0xd0] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x3cu))); /* mov eax, dword ptr [esp + 0x3c] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    W32((uint32_t)(c->esp + 0x80u), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [esp + 0x80], 0xffffffff */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)((uint32_t)0x79028cu)); /* mov dword ptr [esp + 0x20], 0x1001028c */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)((uint32_t)0x790298u)); /* mov dword ptr [esp + 0x24], 0x10010298 */
    W32((uint32_t)(c->esp + 0x34u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x34], edi */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x2c], edi */
    if (c->zf) goto L_00781b98; /* je 0x781b98 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00781b95u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00781b98:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x78u))); /* mov ecx, dword ptr [esp + 0x78] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x74u)); /* add esp, 0x74 */
    c->esp += 8; return; /* ret 4 */
}

void f_00781bb0(CPU *c) { /* PTR_00781bb0 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    c->esp += 16; return; /* ret 0xc */
}

void f_00781bc0(CPU *c) { /* PTR_00781bc0 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x230u)); /* sub esp, 0x230 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x23cu))); /* mov ebp, dword ptr [esp + 0x23c] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov edx, dword ptr [ebp] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0xc], eax */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x14], edi */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x18], edi */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x1c], edi */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x20], edi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x00781bf4u); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    (void)sub32(c, c->eax, (uint32_t)0xc3b6u); /* cmp eax, 0xc3b6 */
    if ((!c->zf && c->sf == c->of)) goto L_00781d1c; /* jg 0x781d1c */
    if (c->zf) goto L_00781cf3; /* je 0x781cf3 */
    (void)sub32(c, c->eax, (uint32_t)0x7594u); /* cmp eax, 0x7594 */
    if (c->zf) goto L_00781c85; /* je 0x781c85 */
    (void)sub32(c, c->eax, (uint32_t)0xc3b4u); /* cmp eax, 0xc3b4 */
    if (!c->zf) goto L_00781d40; /* jne 0x781d40 */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x240u))); /* mov esi, dword ptr [esp + 0x240] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov eax, dword ptr [ebp] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    c->ebx = (uint32_t)((uint32_t)(c->esi + 0x371u)); /* lea ebx, [esi + 0x371] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0xffu; PUSH32(c, v_); } /* push 0xff */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x30u)); PUSH32(c, 0x00781c33u); call_indirect(c, t_); } /* call dword ptr [eax + 0x30] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov edx, dword ptr [ebp] */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x171u)); /* lea eax, [esi + 0x171] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0xffu; PUSH32(c, v_); } /* push 0xff */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x30u)); PUSH32(c, 0x00781c47u); call_indirect(c, t_); } /* call dword ptr [edx + 0x30] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov eax, dword ptr [ebp] */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x271u)); /* lea edi, [esi + 0x271] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0xffu; PUSH32(c, v_); } /* push 0xff */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x30u)); PUSH32(c, 0x00781c5bu); call_indirect(c, t_); } /* call dword ptr [eax + 0x30] */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x171u)); /* lea eax, [esi + 0x171] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00781c6cu); f_00783ae0(c); /* call 0x783ae0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00781c75u); f_00782610(c); /* call 0x782610 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x230u)); /* add esp, 0x230 */
    c->esp += 4; return; /* ret  */
L_00781c85:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov edx, dword ptr [ebp] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x24u)); /* lea eax, [esp + 0x24] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x24u)); PUSH32(c, 0x00781c92u); call_indirect(c, t_); } /* call dword ptr [edx + 0x24] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov edx, dword ptr [ebp] */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->edi = (uint32_t)((uint32_t)(c->esp + 0xcu)); /* lea edi, [esp + 0xc] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x13cu)); /* lea eax, [esp + 0x13c] */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0xffu; PUSH32(c, v_); } /* push 0xff */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x30u)); PUSH32(c, 0x00781cb4u); call_indirect(c, t_); } /* call dword ptr [edx + 0x30] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov edx, dword ptr [ebp] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x3cu)); /* lea eax, [esp + 0x3c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0xffu; PUSH32(c, v_); } /* push 0xff */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x30u)); PUSH32(c, 0x00781cc6u); call_indirect(c, t_); } /* call dword ptr [edx + 0x30] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x3cu)); /* lea ecx, [esp + 0x3c] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x13cu)); /* lea edx, [esp + 0x13c] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x244u))); /* mov ecx, dword ptr [esp + 0x244] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x10u)); /* lea eax, [esp + 0x10] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00781ce4u); f_00781e00(c); /* call 0x781e00 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x230u)); /* add esp, 0x230 */
    c->esp += 4; return; /* ret  */
L_00781cf3:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x240u))); /* mov ecx, dword ptr [esp + 0x240] */
    c->edx = (uint32_t)((uint32_t)(c->ecx + 0x271u)); /* lea edx, [ecx + 0x271] */
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0x171u)); /* lea eax, [ecx + 0x171] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00781d0du); f_00782610(c); /* call 0x782610 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x230u)); /* add esp, 0x230 */
    c->esp += 4; return; /* ret  */
L_00781d1c:;
    (void)sub32(c, c->eax, (uint32_t)0xc418u); /* cmp eax, 0xc418 */
    if (!c->zf) goto L_00781d40; /* jne 0x781d40 */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x240u))); /* mov esi, dword ptr [esp + 0x240] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    W8((uint32_t)(c->esi + 0xf9u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esi + 0xf9], 1 */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x00781d39u); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    W8((uint32_t)(c->esi + 0xf9u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esi + 0xf9], 0 */
L_00781d40:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x230u)); /* add esp, 0x230 */
    c->esp += 4; return; /* ret  */
}

void f_00781d50(CPU *c) { /* PTR_00781d50 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x8u))); /* fld dword ptr [esp + 8] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->ecx + 0x120u))); /* fsub dword ptr [ecx + 0x120] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    ST(0) = FPRES(c, FDIV(c, ST(0), (double)RF32((uint32_t)(c->ecx + 0x110u)))); /* fdiv dword ptr [ecx + 0x110] */
    WF32((uint32_t)(c->esp + 0xcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xc] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xcu))); /* fld dword ptr [esp + 0xc] */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)fpu_to_int32(c, ST(0))); FPOP(c); /* fistp dword ptr [esp + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->ecx + 0x128u))); /* fsub dword ptr [ecx + 0x128] */
    ST(0) = FPRES(c, FDIV(c, ST(0), (double)RF32((uint32_t)(c->ecx + 0x110u)))); /* fdiv dword ptr [ecx + 0x110] */
    WF32((uint32_t)(c->esp + 0xcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xc] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xcu))); /* fld dword ptr [esp + 0xc] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)fpu_to_int32(c, ST(0))); FPOP(c); /* fistp dword ptr [esp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x874u))); /* mov eax, dword ptr [ecx + 0x874] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov esi, dword ptr [esp + 4] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x874u)); /* add ecx, 0x874 */
    c->eax = (uint32_t)(shr32(c, c->eax, 1)); /* shr eax, 1 */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    c->eax = (uint32_t)(add32(c, c->eax, c->esi)); /* add eax, esi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    if ((c->sf != c->of)) goto L_00781de2; /* jl 0x781de2 */
    (void)sub32(c, c->eax, (uint32_t)0x400u); /* cmp eax, 0x400 */
    if ((c->sf == c->of)) goto L_00781de2; /* jge 0x781de2 */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if ((c->sf != c->of)) goto L_00781de2; /* jl 0x781de2 */
    (void)sub32(c, c->edx, (uint32_t)0x400u); /* cmp edx, 0x400 */
    if ((c->sf == c->of)) goto L_00781de2; /* jge 0x781de2 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00781dc3u); f_00786110(c); /* call 0x786110 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xffu))); /* and eax, 0xff */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x8u))); /* fild dword ptr [esp + 8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x7902acu))); /* fmul dword ptr [0x100102ac] */
    WF32((uint32_t)(c->eax), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 16; return; /* ret 0xc */
L_00781de2:;
    FPUSH(c, (double)RF32((uint32_t)(0x7902a8u))); /* fld dword ptr [0x100102a8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    WF32((uint32_t)(c->eax), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 16; return; /* ret 0xc */
}

void f_00781e00(CPU *c) { /* FUN_10001e00 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ebx, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov edi, dword ptr [esp + 0x18] */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00781e15; /* je 0x781e15 */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (!c->zf) goto L_00781e38; /* jne 0x781e38 */
L_00781e15:;
    c->eax = (uint32_t)(R32((uint32_t)(0x795678u))); /* mov eax, dword ptr [0x10015678] */
    { uint32_t v_ = 0x792180u; PUSH32(c, v_); } /* push 0x10012180 */
    { uint32_t v_ = 0xd2u; PUSH32(c, v_); } /* push 0xd2 */
    { uint32_t v_ = 0x792048u; PUSH32(c, v_); } /* push 0x10012048 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x7920b0u; PUSH32(c, v_); } /* push 0x100120b0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00781e34u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00781e37u, "int3"); /* int3  */
L_00781e38:;
    c->edx = (uint32_t)((uint32_t)(c->esi + 0x171u)); /* lea edx, [esi + 0x171] */
    W8((uint32_t)(c->esi + 0xf8u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esi + 0xf8], 1 */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edx = (uint32_t)(sub32(c, c->edx, c->edi)); /* sub edx, edi */
L_00781e49:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    W8((uint32_t)(c->edx + c->eax), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [edx + eax], cl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_00781e49; /* jne 0x781e49 */
    c->edx = (uint32_t)((uint32_t)(c->esi + 0x271u)); /* lea edx, [esi + 0x271] */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->edx = (uint32_t)(sub32(c, c->edx, c->ebx)); /* sub edx, ebx */
L_00781e5d:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    W8((uint32_t)(c->edx + c->eax), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [edx + eax], cl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_00781e5d; /* jne 0x781e5d */
    c->eax = (uint32_t)(R32((uint32_t)(0x79567cu))); /* mov eax, dword ptr [0x1001567c] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
    { uint32_t v_ = 0xau; PUSH32(c, v_); } /* push 0xa */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t v_ = 0x7920f8u; PUSH32(c, v_); } /* push 0x100120f8 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xb0u)); PUSH32(c, 0x00781e8du); call_indirect(c, t_); } /* call dword ptr [edx + 0xb0] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
}

void f_00781ea0(CPU *c) { /* PTR_00781ea0 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x20u)); /* sub esp, 0x20 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x3cu))); /* fld dword ptr [esp + 0x3c] */
    ST(0) = FTRIG(c, ST(0), cos); /* fcos  */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    WF32((uint32_t)(c->esp + 0xcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xc] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x40u))); /* fld dword ptr [esp + 0x40] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    WF32((uint32_t)(c->esp + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x3cu))); /* fld dword ptr [esp + 0x3c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x7902b4u))); /* fmul dword ptr [0x100102b4] */
    WF32((uint32_t)(c->esp + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x3cu))); /* fld dword ptr [esp + 0x3c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x7902b0u))); /* fmul dword ptr [0x100102b0] */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x4u))); /* fld dword ptr [esp + 4] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->esp + 0x10u))); FPOP(c); /* fcomp dword ptr [esp + 0x10] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00781fb1; /* jp 0x781fb1 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x34u))); /* fld dword ptr [esp + 0x34] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x7902b4u))); /* fmul dword ptr [0x100102b4] */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x34u))); /* fld dword ptr [esp + 0x34] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x7902b0u))); /* fmul dword ptr [0x100102b0] */
    WF32((uint32_t)(c->esp + 0x34u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x34] */
L_00781f05:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    W32((uint32_t)(c->esp + 0x40u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x40], eax */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x40u))); /* fld dword ptr [esp + 0x40] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->esp + 0x34u))); FPOP(c); /* fcomp dword ptr [esp + 0x34] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00781f94; /* jp 0x781f94 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x4u))); /* fld dword ptr [esp + 4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xcu))); /* fmul dword ptr [esp + 0xc] */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x4u))); /* fld dword ptr [esp + 4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x8u))); /* fmul dword ptr [esp + 8] */
    WF32((uint32_t)(c->esp + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1c] */
L_00781f34:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x40u))); /* fld dword ptr [esp + 0x40] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x8u))); /* fmul dword ptr [esp + 8] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x20u)); /* lea eax, [esp + 0x20] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(c->esp + 0x1cu)) - ST(0)); /* fsubr dword ptr [esp + 0x1c] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x3cu))); /* fadd dword ptr [esp + 0x3c] */
    WF32((uint32_t)(c->esp + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x4cu))); /* fld dword ptr [esp + 0x4c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x18u))); /* fmul dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x28u))); /* fadd dword ptr [esp + 0x28] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x34u))); /* fadd dword ptr [esp + 0x34] */
    WF32((uint32_t)(c->esp), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x48u)); PUSH32(c, 0x00781f6au); call_indirect(c, t_); } /* call dword ptr [edx + 0x48] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x20u))); /* fld dword ptr [esp + 0x20] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->esp + 0x44u))); FPOP(c); /* fcomp dword ptr [esp + 0x44] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (c->zf) goto L_00781fba; /* je 0x781fba */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x40u))); /* fld dword ptr [esp + 0x40] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0xfcu))); /* fadd dword ptr [esi + 0xfc] */
    WF32((uint32_t)(c->esp + 0x40u), (float)ST(0)); /* fst dword ptr [esp + 0x40] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->esp + 0x34u))); FPOP(c); /* fcomp dword ptr [esp + 0x34] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (!PF(c)) goto L_00781f34; /* jnp 0x781f34 */
L_00781f94:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x4u))); /* fld dword ptr [esp + 4] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x100u))); /* fadd dword ptr [esi + 0x100] */
    WF32((uint32_t)(c->esp + 0x4u), (float)ST(0)); /* fst dword ptr [esp + 4] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->esp + 0x10u))); FPOP(c); /* fcomp dword ptr [esp + 0x10] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (!PF(c)) goto L_00781f05; /* jnp 0x781f05 */
L_00781fb1:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    c->esp += 36; return; /* ret 0x20 */
L_00781fba:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    c->esp += 36; return; /* ret 0x20 */
}

void f_00781fd0(CPU *c) { /* PTR_00781fd0 */
    PREEMPT_POLL(c);
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x4u))); /* fld dword ptr [esp + 4] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x10u)); /* sub esp, 0x10 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esi + 0x120u))); /* fsub dword ptr [esi + 0x120] */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fld dword ptr [esp + 0x1c] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esi + 0x128u))); /* fsub dword ptr [esi + 0x128] */
    WF32((uint32_t)(c->esp + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    ST(0) = fabs(ST(0)); /* fabs  */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->esi + 0x12cu))); FPOP(c); /* fcomp dword ptr [esi + 0x12c] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x100u))); /* and eax, 0x100 */
    if (c->zf) goto L_007820aa; /* je 0x7820aa */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fld dword ptr [esp + 0x1c] */
    ST(0) = fabs(ST(0)); /* fabs  */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->esi + 0x134u))); FPOP(c); /* fcomp dword ptr [esi + 0x134] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x100u))); /* and eax, 0x100 */
    if (c->zf) goto L_007820aa; /* je 0x7820aa */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x138u))); /* mov eax, dword ptr [esi + 0x138] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x104u))); /* fmul dword ptr [esi + 0x104] */
    c->eax = (uint32_t)(shr32(c, c->eax, 1)); /* shr eax, 1 */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 4], eax */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 8], eax */
    ST(0) = FPRES(c, ST(0) + (double)(int32_t)R32((uint32_t)(c->esp + 0x4u))); /* fiadd dword ptr [esp + 4] */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)fpu_to_int32(c, ST(0))); FPOP(c); /* fistp dword ptr [esp + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x138u))); /* mov ecx, dword ptr [esi + 0x138] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fld dword ptr [esp + 0x1c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x108u))); /* fmul dword ptr [esi + 0x108] */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 1)); /* shr ecx, 1 */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0xc], ecx */
    ST(0) = FPRES(c, ST(0) + (double)(int32_t)R32((uint32_t)(c->esp + 0xcu))); /* fiadd dword ptr [esp + 0xc] */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)fpu_to_int32(c, ST(0))); FPOP(c); /* fistp dword ptr [esp + 0x1c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov edx, dword ptr [esp + 0x1c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x894u)); /* lea ecx, [esi + 0x894] */
    PUSH32(c, 0x0078208fu); f_00786110(c); /* call 0x786110 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov ecx, dword ptr [esp + 0x20] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xffu))); /* and eax, 0xff */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + c->eax * 4 + 0x474u))); /* fld dword ptr [esi + eax*4 + 0x474] */
    WF32((uint32_t)(c->ecx), (float)ST(0)); FPOP(c); /* fstp dword ptr [ecx] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 16; return; /* ret 0xc */
L_007820aa:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov edx, dword ptr [esp + 0x20] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->edx), (uint32_t)((uint32_t)0xc2480000u)); /* mov dword ptr [edx], 0xc2480000 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 16; return; /* ret 0xc */
}

void f_007820c0(CPU *c) { /* FUN_100020c0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(logic32(c, (uint32_t)(c->esp & (uint32_t)0xfffffff8u))); /* and esp, 0xfffffff8 */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xa4u)); /* sub esp, 0xa4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0xc], eax */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
L_007820de:;
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x10u))); /* fild dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x7902d4u))); /* fmul dword ptr [0x100102d4] */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FTRIG(c, ST(0), cos); /* fcos  */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x7902d0u))); /* fmul dword ptr [0x100102d0] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x7902d0u))); /* fmul dword ptr [0x100102d0] */
    WF32((uint32_t)(c->esp + 0x88u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x88] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->edi))); /* fadd dword ptr [edi] */
    WF32((uint32_t)(c->esp + 0x38u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x38] */
    FPUSH(c, (double)RF32((uint32_t)(c->edi + 0x4u))); /* fld dword ptr [edi + 4] */
    WF32((uint32_t)(c->esp + 0x3cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x3c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x88u))); /* fld dword ptr [esp + 0x88] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->edi + 0x8u))); /* fadd dword ptr [edi + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x3cu))); /* mov ecx, dword ptr [esp + 0x3c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x38u))); /* mov eax, dword ptr [esp + 0x38] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x18], ecx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea ecx, [esp + 0x14] */
    WF32((uint32_t)(c->esp + 0x40u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x40] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x40u))); /* mov edx, dword ptr [esp + 0x40] */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x24], edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x24u)); PUSH32(c, 0x00782143u); call_indirect(c, t_); } /* call dword ptr [eax + 0x24] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x7902a8u))); FPOP(c); /* fcomp dword ptr [0x100102a8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (c->zf) goto L_007822f8; /* je 0x7822f8 */
    c->edx = (uint32_t)(R32((uint32_t)(0x79567cu))); /* mov edx, dword ptr [0x1001567c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x8c0u))); /* mov ecx, dword ptr [ebx + 0x8c0] */
    c->esi = (uint32_t)(R32((uint32_t)(c->edx))); /* mov esi, dword ptr [edx] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x98u)); /* lea edx, [esp + 0x98] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x2cu)); PUSH32(c, 0x00782171u); call_indirect(c, t_); } /* call dword ptr [eax + 0x2c] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x79567cu))); /* mov ecx, dword ptr [0x1001567c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->esi + 0x64u)); PUSH32(c, 0x0078217bu); call_indirect(c, t_); } /* call dword ptr [esi + 0x64] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_007821a4; /* jne 0x7821a4 */
    c->eax = (uint32_t)(R32((uint32_t)(0x795678u))); /* mov eax, dword ptr [0x10015678] */
    { uint32_t v_ = 0x792190u; PUSH32(c, v_); } /* push 0x10012190 */
    { uint32_t v_ = 0x137u; PUSH32(c, v_); } /* push 0x137 */
    { uint32_t v_ = 0x792048u; PUSH32(c, v_); } /* push 0x10012048 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x7920b0u; PUSH32(c, v_); } /* push 0x100120b0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x007821a0u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x007821a3u, "int3"); /* int3  */
L_007821a4:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x50u)); /* lea eax, [esp + 0x50] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x30u)); PUSH32(c, 0x007821b0u); call_indirect(c, t_); } /* call dword ptr [edx + 0x30] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x68u))); /* fld dword ptr [esp + 0x68] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x50u))); /* fsub dword ptr [esp + 0x50] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x6cu))); /* fld dword ptr [esp + 0x6c] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x54u))); /* fsub dword ptr [esp + 0x54] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x70u))); /* fld dword ptr [esp + 0x70] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x58u))); /* fsub dword ptr [esp + 0x58] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x5cu))); /* fld dword ptr [esp + 0x5c] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x50u))); /* fsub dword ptr [esp + 0x50] */
    WF32((uint32_t)(c->esp + 0x44u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x44] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x60u))); /* fld dword ptr [esp + 0x60] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x54u))); /* fsub dword ptr [esp + 0x54] */
    WF32((uint32_t)(c->esp + 0x48u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x48] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x64u))); /* fld dword ptr [esp + 0x64] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x58u))); /* fsub dword ptr [esp + 0x58] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x48u))); /* fld dword ptr [esp + 0x48] */
    ST(0) = FPRES(c, ST(0) * ST(2)); /* fmul st(2) */
    { double v_ = ST(1); FPUSH(c, v_); } /* fld st(1) */
    ST(0) = FPRES(c, ST(0) * ST(4)); /* fmul st(4) */
    ST(1) = FPRES(c, ST(1) - ST(0)); FPOP(c); /* fsubp st(1) */
    WF32((uint32_t)(c->esp + 0x20u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x20] */
    ST(0) = FPRES(c, ST(0) * ST(3)); /* fmul st(3) */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x44u))); /* fmul dword ptr [esp + 0x44] */
    ST(1) = FPRES(c, ST(1) - ST(0)); FPOP(c); /* fsubp st(1) */
    WF32((uint32_t)(c->esp + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x24] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x44u))); /* fmul dword ptr [esp + 0x44] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x48u))); /* fld dword ptr [esp + 0x48] */
    ST(0) = FPRES(c, ST(0) * ST(2)); /* fmul st(2) */
    ST(1) = FPRES(c, ST(1) - ST(0)); FPOP(c); /* fsubp st(1) */
    ST(1) = ST(0); FPOP(c); /* fstp st(1) */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x24u))); /* fld dword ptr [esp + 0x24] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x24u))); /* fmul dword ptr [esp + 0x24] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x20u))); /* fld dword ptr [esp + 0x20] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x20u))); /* fmul dword ptr [esp + 0x20] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FCOM(c, ST(0), RF64((uint32_t)(0x7902c8u))); /* fcom qword ptr [0x100102c8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x44u)); /* test ah, 0x44 */
    if (PF(c)) goto L_00782257; /* jp 0x782257 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x2c], 0 */
    W32((uint32_t)(c->esp + 0x30u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x30], 0 */
    W32((uint32_t)(c->esp + 0x34u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x34], 0 */
    goto L_00782288; /* jmp 0x782288 */
L_00782257:;
    ST(0) = FPRES(c, sqrt(ST(0))); /* fsqrt  */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x44u)); /* lea ecx, [esp + 0x44] */
    ST(0) = FPRES(c, FDIV(c, RF64((uint32_t)(0x7902c0u)), ST(0))); /* fdivr qword ptr [0x100102c0] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF64((uint32_t)(c->esp + 0x10u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x10] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x3cu))); /* fld dword ptr [esp + 0x3c] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF64((uint32_t)(c->esp + 0x8u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x38u))); /* fld dword ptr [esp + 0x38] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    PUSH32(c, 0x00782288u); f_00783990(c); /* call 0x783990 */
L_00782288:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fld dword ptr [esp + 0x1c] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->edi + 0x8u))); /* fsub dword ptr [edi + 8] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x80u)); /* lea ecx, [esp + 0x80] */
    WF32((uint32_t)(c->esp + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x24u))); /* fld dword ptr [esp + 0x24] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->edi + 0x4u))); /* fsub dword ptr [edi + 4] */
    WF32((uint32_t)(c->esp + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x20u))); /* fld dword ptr [esp + 0x20] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->edi))); /* fsub dword ptr [edi] */
    WF32((uint32_t)(c->esp), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp] */
    PUSH32(c, 0x007822b6u); f_00783970(c); /* call 0x783970 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x74u)); /* lea edx, [esp + 0x74] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x8cu)); /* lea ecx, [esp + 0x8c] */
    PUSH32(c, 0x007822c6u); f_007839b0(c); /* call 0x7839b0 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x34u))); /* fld dword ptr [esp + 0x34] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x8u))); /* fmul dword ptr [eax + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x30u))); /* fld dword ptr [esp + 0x30] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x4u))); /* fmul dword ptr [eax + 4] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x2cu))); /* fld dword ptr [esp + 0x2c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax))); /* fmul dword ptr [eax] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x7902b8u))); FPOP(c); /* fcomp dword ptr [0x100102b8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_007822f1; /* jne 0x7822f1 */
    { uint32_t a_ = (uint32_t)(c->esp + 0xcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [esp + 0xc] */
L_007822f1:;
    (void)sub32(c, R32((uint32_t)(c->esp + 0xcu)), (uint32_t)0x1u); /* cmp dword ptr [esp + 0xc], 1 */
    if ((!c->zf && c->sf == c->of)) goto L_00782315; /* jg 0x782315 */
L_007822f8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub32(c, c->eax, (uint32_t)0x8u); /* cmp eax, 8 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    if ((c->sf != c->of)) goto L_007820de; /* jl 0x7820de */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 8; return; /* ret 4 */
L_00782315:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 8; return; /* ret 4 */
}

void f_00782320(CPU *c) { /* FUN_10002320 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x6cu)); /* sub esp, 0x6c */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->ecx); /* mov ebp, ecx */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)((uint32_t)0x4cbebc20u)); /* mov dword ptr [esp + 8], 0x4cbebc20 */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)((uint32_t)0xccbebc20u)); /* mov dword ptr [esp + 4], 0xccbebc20 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8c4u))); /* mov ecx, dword ptr [ebp + 0x8c4] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0x4cbebc20u)); /* mov dword ptr [esp + 0x10], 0x4cbebc20 */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)((uint32_t)0xccbebc20u)); /* mov dword ptr [esp + 0xc], 0xccbebc20 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4u)); PUSH32(c, 0x00782351u); call_indirect(c, t_); } /* call dword ptr [eax + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00782488; /* je 0x782488 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
L_0078235c:;
    c->ecx = (uint32_t)(R32((uint32_t)(0x79567cu))); /* mov ecx, dword ptr [0x1001567c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x64u)); PUSH32(c, 0x00782368u); call_indirect(c, t_); } /* call dword ptr [edx + 0x64] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (!c->zf) goto L_00782391; /* jne 0x782391 */
    c->eax = (uint32_t)(R32((uint32_t)(0x795678u))); /* mov eax, dword ptr [0x10015678] */
    { uint32_t v_ = 0x792198u; PUSH32(c, v_); } /* push 0x10012198 */
    { uint32_t v_ = 0x14bu; PUSH32(c, v_); } /* push 0x14b */
    { uint32_t v_ = 0x792048u; PUSH32(c, v_); } /* push 0x10012048 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x7920b0u; PUSH32(c, v_); } /* push 0x100120b0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x0078238du); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00782390u, "int3"); /* int3  */
L_00782391:;
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    goto L_00782397; /* jmp 0x782397 */
L_00782395:;
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
L_00782397:;
    c->edx = (uint32_t)(R32((uint32_t)(c->edi))); /* mov edx, dword ptr [edi] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x34u)); PUSH32(c, 0x0078239fu); call_indirect(c, t_); } /* call dword ptr [edx + 0x34] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00782472; /* je 0x782472 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x88u))); /* mov ecx, dword ptr [esi + 0x88] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x44u)); /* lea edx, [esp + 0x44] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4u)); PUSH32(c, 0x007823bau); call_indirect(c, t_); } /* call dword ptr [eax + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x60u))); /* fld dword ptr [esp + 0x60] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x68u))); /* fld dword ptr [esp + 0x68] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x74u)); /* add esi, 0x74 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x20], eax */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x20u))); /* fld dword ptr [esp + 0x20] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    ST(0) = FPRES(c, ST(0) + ST(2)); /* fadd st(2) */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov edx, dword ptr [esi + 8] */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x24], ecx */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x28], edx */
    WF32((uint32_t)(c->esp + 0x38u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x38] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x28u))); /* fld dword ptr [esp + 0x28] */
    ST(0) = FPRES(c, ST(0) + ST(1)); /* fadd st(1) */
    ST(2) = ST(0); FPOP(c); /* fstp st(2) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x6cu))); /* fld dword ptr [esp + 0x6c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x74u))); /* fld dword ptr [esp + 0x74] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(0x7902d8u))); /* fmul qword ptr [0x100102d8] */
    WF32((uint32_t)(c->esp + 0x2cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x2c] */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(0x7902d8u))); /* fmul qword ptr [0x100102d8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x38u))); /* fld dword ptr [esp + 0x38] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x2cu))); /* fsub dword ptr [esp + 0x2c] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->esp + 0x14u))); /* fcom dword ptr [esp + 0x14] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00782420; /* jp 0x782420 */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    goto L_00782422; /* jmp 0x782422 */
L_00782420:;
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
L_00782422:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x2cu))); /* fld dword ptr [esp + 0x2c] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x38u))); /* fadd dword ptr [esp + 0x38] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->esp + 0x10u))); /* fcom dword ptr [esp + 0x10] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_0078243d; /* jne 0x78243d */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
    goto L_0078243f; /* jmp 0x78243f */
L_0078243d:;
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
L_0078243f:;
    { double v_ = ST(1); FPUSH(c, v_); } /* fld st(1) */
    ST(0) = FPRES(c, ST(0) - ST(1)); /* fsub st(1) */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fcom dword ptr [esp + 0x1c] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00782454; /* jp 0x782454 */
    WF32((uint32_t)(c->esp + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1c] */
    goto L_00782456; /* jmp 0x782456 */
L_00782454:;
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
L_00782456:;
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->esp + 0x18u))); /* fcom dword ptr [esp + 0x18] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00782395; /* jne 0x782395 */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
    goto L_00782397; /* jmp 0x782397 */
L_00782472:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8c4u))); /* mov ecx, dword ptr [ebp + 0x8c4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x0078247du); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_0078235c; /* jne 0x78235c */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
L_00782488:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x4u))); /* fld dword ptr [esp + 4] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x8u))); /* fadd dword ptr [esp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x74u))); /* mov ecx, dword ptr [esp + 0x74] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x18], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x18], 0 */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x7902b0u))); /* fmul dword ptr [0x100102b0] */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x8u))); /* fld dword ptr [esp + 8] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0xcu))); /* fadd dword ptr [esp + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x7902b0u))); /* fmul dword ptr [0x100102b0] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x74u))); /* mov eax, dword ptr [esp + 0x74] */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp))); /* fld dword ptr [esp] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x4u))); /* fsub dword ptr [esp + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov edx, dword ptr [esp + 0x18] */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 8], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edx, dword ptr [esp + 0x14] */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x8u))); /* fld dword ptr [esp + 8] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0xcu))); /* fsub dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov ecx, dword ptr [esp + 0x18] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 4], edx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x6cu)); /* add esp, 0x6c */
    c->esp += 12; return; /* ret 8 */
}

void f_00782510(CPU *c) { /* FUN_10002510 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(0x795680u))); /* mov ecx, dword ptr [0x10015680] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x204u)); /* sub esp, 0x204 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x4u)); /* lea edx, [esp + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x100u; PUSH32(c, v_); } /* push 0x100 */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x2cu)); PUSH32(c, 0x0078252fu); call_indirect(c, t_); } /* call dword ptr [eax + 0x2c] */
    c->edi = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea edi, [esp + 0x14] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0xffffffffu))); /* or ecx, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    while (c->ecx) { (void)sub8(c, ((uint8_t)c->eax), R8(c->edi)); c->edi += (c->df ? -1 : 1); c->ecx--; if (c->zf) break; } /* repne scasb al, byte ptr es:[edi] */
    c->ecx = (uint32_t)((uint32_t)~c->ecx); /* not ecx */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_00782567; /* je 0x782567 */
    c->edi = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea edi, [esp + 0x14] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0xffffffffu))); /* or ecx, 0xffffffff */
    while (c->ecx) { (void)sub8(c, ((uint8_t)c->eax), R8(c->edi)); c->edi += (c->df ? -1 : 1); c->ecx--; if (c->zf) break; } /* repne scasb al, byte ptr es:[edi] */
    c->ecx = (uint32_t)((uint32_t)~c->ecx); /* not ecx */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    (void)sub8(c, R8((uint32_t)(c->esp + c->ecx + 0x13u)), (uint8_t)0x5cu); /* cmp byte ptr [esp + ecx + 0x13], 0x5c */
    if (c->zf) goto L_00782567; /* je 0x782567 */
    c->edi = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea edi, [esp + 0x14] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0xffffffffu))); /* or ecx, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    while (c->ecx) { (void)sub8(c, ((uint8_t)c->eax), R8(c->edi)); c->edi += (c->df ? -1 : 1); c->ecx--; if (c->zf) break; } /* repne scasb al, byte ptr es:[edi] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(0x79219cu))); /* mov ax, word ptr [0x1001219c] */
    W16((uint32_t)(c->edi + 0xffffffffu), (uint16_t)(((uint16_t)c->eax))); /* mov word ptr [edi - 1], ax */
L_00782567:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x218u))); /* mov ebx, dword ptr [esp + 0x218] */
    c->ebp = (uint32_t)(c->ebx); /* mov ebp, ebx */
L_00782570:;
    { uint32_t v_ = 0x5cu; PUSH32(c, v_); } /* push 0x5c */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x00782578u); f_00786a60(c); /* call 0x786a60 */
    c->ebp = (uint32_t)(c->eax); /* mov ebp, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->ebp & c->ebp)); /* test ebp, ebp */
    if (c->zf) goto L_00782600; /* je 0x782600 */
    c->esi = (uint32_t)(c->ebp); /* mov esi, ebp */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x114u)); /* lea ecx, [esp + 0x114] */
    c->esi = (uint32_t)(sub32(c, c->esi, c->ebx)); /* sub esi, ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00782594u); f_00786950(c); /* call 0x786950 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)((uint32_t)(c->esp + 0x114u)); /* lea edi, [esp + 0x114] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0xffffffffu))); /* or ecx, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ebp = (uint32_t)(inc32(c, c->ebp)); /* inc ebp */
    W8((uint32_t)(c->esp + c->esi + 0x114u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esp + esi + 0x114], 0 */
    while (c->ecx) { (void)sub8(c, ((uint8_t)c->eax), R8(c->edi)); c->edi += (c->df ? -1 : 1); c->ecx--; if (c->zf) break; } /* repne scasb al, byte ptr es:[edi] */
    c->ecx = (uint32_t)((uint32_t)~c->ecx); /* not ecx */
    c->edi = (uint32_t)(sub32(c, c->edi, c->ecx)); /* sub edi, ecx */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea edx, [esp + 0x14] */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->esi = (uint32_t)(c->edi); /* mov esi, edi */
    c->edi = (uint32_t)(c->edx); /* mov edi, edx */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0xffffffffu))); /* or ecx, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    while (c->ecx) { (void)sub8(c, ((uint8_t)c->eax), R8(c->edi)); c->edi += (c->df ? -1 : 1); c->ecx--; if (c->zf) break; } /* repne scasb al, byte ptr es:[edi] */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->ebx = (uint32_t)(c->ebp); /* mov ebx, ebp */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u))); /* and ecx, 3 */
    while (c->ecx) { W8(c->edi, R8(c->esi)); c->esi += (c->df ? -1 : 1); c->edi += (c->df ? -1 : 1); c->ecx--; } /* rep movsb byte ptr es:[edi], byte ptr [esi] */
    c->edi = (uint32_t)((uint32_t)(c->esp + 0x18u)); /* lea edi, [esp + 0x18] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0xffffffffu))); /* or ecx, 0xffffffff */
    while (c->ecx) { (void)sub8(c, ((uint8_t)c->eax), R8(c->edi)); c->edi += (c->df ? -1 : 1); c->ecx--; if (c->zf) break; } /* repne scasb al, byte ptr es:[edi] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(0x79219cu))); /* mov ax, word ptr [0x1001219c] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x795680u))); /* mov ecx, dword ptr [0x10015680] */
    W16((uint32_t)(c->edi + 0xffffffffu), (uint16_t)(((uint16_t)c->eax))); /* mov word ptr [edi - 1], ax */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x18u)); /* lea eax, [esp + 0x18] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x48u)); PUSH32(c, 0x007825fbu); call_indirect(c, t_); } /* call dword ptr [edx + 0x48] */
    goto L_00782570; /* jmp 0x782570 */
L_00782600:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x204u)); /* add esp, 0x204 */
    c->esp += 8; return; /* ret 4 */
}

void f_00782610(CPU *c) { /* FUN_10002610 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(logic32(c, (uint32_t)(c->esp & (uint32_t)0xfffffff8u))); /* and esp, 0xfffffff8 */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x78fa94u; PUSH32(c, v_); } /* push 0x1000fa94 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)((uint32_t)0x85a4u); /* mov eax, 0x85a4 */
    PUSH32(c, 0x00782636u); f_00786c00(c); /* call 0x786c00 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    W32((uint32_t)(c->esp + 0x60u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x60], esi */
    W32((uint32_t)(c->esp + 0x64u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x64], esi */
    W32((uint32_t)(c->esp + 0x68u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x68], esi */
    W32((uint32_t)(c->esp + 0x6cu), (uint32_t)((uint32_t)0x10u)); /* mov dword ptr [esp + 0x6c], 0x10 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x60u)); /* lea ecx, [esp + 0x60] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x79235cu; PUSH32(c, v_); } /* push 0x1001235c */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    W32((uint32_t)(c->esp + 0x85c8u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x85c8], esi */
    PUSH32(c, 0x0078266bu); f_00785470(c); /* call 0x785470 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x70u))); /* mov ecx, dword ptr [esp + 0x70] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x6cu))); /* mov edi, dword ptr [esp + 0x6c] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, c->ecx, c->esi); /* cmp ecx, esi */
    if ((c->cf || c->zf)) goto L_007826ad; /* jbe 0x7826ad */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)((uint8_t)0x5cu); /* mov dl, 0x5c */
L_0078267e:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + c->edi))); /* mov cl, byte ptr [eax + edi] */
    W8((uint32_t)(c->esi + c->edi), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esi + edi], cl */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x60u))); /* mov edi, dword ptr [esp + 0x60] */
    (void)sub8(c, R8((uint32_t)(c->eax + c->edi)), ((uint8_t)c->edx)); /* cmp byte ptr [eax + edi], dl */
    if (!c->zf) goto L_007826a3; /* jne 0x7826a3 */
    (void)sub8(c, R8((uint32_t)(c->eax + c->edi + 0x1u)), ((uint8_t)c->edx)); /* cmp byte ptr [eax + edi + 1], dl */
    if (!c->zf) goto L_007826a3; /* jne 0x7826a3 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x64u))); /* mov ecx, dword ptr [esp + 0x64] */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
L_00782698:;
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->cf) goto L_007826a3; /* jae 0x7826a3 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub8(c, R8((uint32_t)(c->eax + c->edi + 0x1u)), ((uint8_t)c->edx)); /* cmp byte ptr [eax + edi + 1], dl */
    if (c->zf) goto L_00782698; /* je 0x782698 */
L_007826a3:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x64u))); /* mov ecx, dword ptr [esp + 0x64] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (c->cf) goto L_0078267e; /* jb 0x78267e */
L_007826ad:;
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    W32((uint32_t)(c->esp + 0x64u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x64], esi */
    if (c->zf) goto L_007826bd; /* je 0x7826bd */
    W8((uint32_t)(c->esi + c->edi), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esi + edi], 0 */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x60u))); /* mov edi, dword ptr [esp + 0x60] */
L_007826bd:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0xb0u)); /* lea edx, [esp + 0xb0] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x7921f0u; PUSH32(c, v_); } /* push 0x100121f0 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x007826d4u); f_00786b1c(c); /* call 0x786b1c */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x70u))); /* mov eax, dword ptr [esp + 0x70] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x1c8u)); /* lea ecx, [esp + 0x1c8] */
    { uint32_t v_ = 0x792350u; PUSH32(c, v_); } /* push 0x10012350 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x007826ecu); f_00786b1c(c); /* call 0x786b1c */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x80u))); /* mov edx, dword ptr [esp + 0x80] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x007826feu); f_00782510(c); /* call 0x782510 */
    c->edi = (uint32_t)((uint32_t)(c->ebx + 0x12cu)); /* lea edi, [ebx + 0x12c] */
    c->esi = (uint32_t)((uint32_t)(c->ebx + 0x120u)); /* lea esi, [ebx + 0x120] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    PUSH32(c, 0x00782713u); f_00782320(c); /* call 0x782320 */
    FPUSH(c, (double)RF32((uint32_t)(c->edi + 0x8u))); /* fld dword ptr [edi + 8] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0x7902e0u))); /* fadd dword ptr [0x100102e0] */
    FPUSH(c, (double)RF32((uint32_t)(c->edi + 0x4u))); /* fld dword ptr [edi + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->edi))); /* fld dword ptr [edi] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0x7902e0u))); /* fadd dword ptr [0x100102e0] */
    c->edi = (uint32_t)((uint32_t)(c->ebx + 0x114u)); /* lea edi, [ebx + 0x114] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x10u)); /* sub esp, 0x10 */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    W32((uint32_t)(c->esp + 0x38u), (uint32_t)(c->esp)); /* mov dword ptr [esp + 0x38], esp */
    W32((uint32_t)(c->esp + 0x34u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x34], edi */
    WF32((uint32_t)(c->esp + 0x44u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x44] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x44u))); /* mov ecx, dword ptr [esp + 0x44] */
    WF32((uint32_t)(c->esp + 0x48u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x48] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x48u))); /* mov edx, dword ptr [esp + 0x48] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    WF32((uint32_t)(c->esp + 0x4cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x4c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4cu))); /* mov ecx, dword ptr [esp + 0x4c] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 4], edx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    c->ecx = (uint32_t)(c->esp); /* mov ecx, esp */
    FPUSH(c, (double)RF32((uint32_t)(c->edi))); /* fld dword ptr [edi] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x7902b0u))); /* fmul dword ptr [0x100102b0] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi))); /* fld dword ptr [esi] */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = 0x7921e8u; PUSH32(c, v_); } /* push 0x100121e8 */
    ST(0) = FPRES(c, ST(0) - ST(1)); /* fsub st(1) */
    WF32((uint32_t)(c->ebx + 0xe8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebx + 0xe8] */
    FPUSH(c, (double)RF32((uint32_t)(c->ebx + 0x11cu))); /* fld dword ptr [ebx + 0x11c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x7902b0u))); /* fmul dword ptr [0x100102b0] */
    FPUSH(c, (double)RF32((uint32_t)(c->ebx + 0x128u))); /* fld dword ptr [ebx + 0x128] */
    ST(0) = FPRES(c, ST(0) - ST(1)); /* fsub st(1) */
    WF32((uint32_t)(c->ebx + 0xecu), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebx + 0xec] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi))); /* fadd dword ptr [esi] */
    WF32((uint32_t)(c->ebx + 0xf0u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebx + 0xf0] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ebx + 0x128u))); /* fadd dword ptr [ebx + 0x128] */
    WF32((uint32_t)(c->ebx + 0xf4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebx + 0xf4] */
    PUSH32(c, 0x007827aau); f_007855a0(c); /* call 0x7855a0 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0xc0u)); /* lea edx, [esp + 0xc0] */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x88u)); /* lea ecx, [esp + 0x88] */
    W8((uint32_t)(c->esp + 0x85d4u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esp + 0x85d4], 1 */
    PUSH32(c, 0x007827c8u); f_007855a0(c); /* call 0x7855a0 */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x10u)); /* sub esp, 0x10 */
    W8((uint32_t)(c->esp + 0x85dcu), (uint8_t)((uint8_t)0x2u)); /* mov byte ptr [esp + 0x85dc], 2 */
    c->ecx = (uint32_t)(c->esp); /* mov ecx, esp */
    W32((uint32_t)(c->esp + 0x30u), (uint32_t)(c->esp)); /* mov dword ptr [esp + 0x30], esp */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x007827e1u); f_00785630(c); /* call 0x785630 */
    W8((uint32_t)(c->esp + 0x85dcu), (uint8_t)((uint8_t)0x3u)); /* mov byte ptr [esp + 0x85dc], 3 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x70u)); /* lea ecx, [esp + 0x70] */
    PUSH32(c, 0x007827f2u); f_007852f0(c); /* call 0x7852f0 */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x10u)); /* sub esp, 0x10 */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->ecx = (uint32_t)(c->esp); /* mov ecx, esp */
    W8((uint32_t)(c->esp + 0x85ccu), (uint8_t)((uint8_t)0x4u)); /* mov byte ptr [esp + 0x85cc], 4 */
    W32((uint32_t)(c->esp + 0x38u), (uint32_t)(c->esp)); /* mov dword ptr [esp + 0x38], esp */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 4], edx */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 8], edx */
    W32((uint32_t)(c->ecx + 0xcu), (uint32_t)((uint32_t)0x10u)); /* mov dword ptr [ecx + 0xc], 0x10 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x4u)), c->edx); /* cmp dword ptr [eax + 4], edx */
    if (c->zf) goto L_0078281f; /* je 0x78281f */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0078281fu); f_00785280(c); /* call 0x785280 */
L_0078281f:;
    c->ecx = (uint32_t)((uint32_t)(c->ebx + 0x894u)); /* lea ecx, [ebx + 0x894] */
    PUSH32(c, 0x0078282au); f_00786180(c); /* call 0x786180 */
    W8((uint32_t)(c->esp + 0xfu), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [esp + 0xf], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x50u))); /* mov eax, dword ptr [esp + 0x50] */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    W8((uint32_t)(c->esp + 0x85bcu), (uint8_t)((uint8_t)0x3u)); /* mov byte ptr [esp + 0x85bc], 3 */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->zf) goto L_00782849; /* je 0x782849 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00782846u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00782849:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x70u))); /* mov eax, dword ptr [esp + 0x70] */
    W32((uint32_t)(c->esp + 0x50u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x50], esi */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    W32((uint32_t)(c->esp + 0x54u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x54], esi */
    W32((uint32_t)(c->esp + 0x58u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x58], esi */
    W8((uint32_t)(c->esp + 0x85bcu), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esp + 0x85bc], 0 */
    if (c->zf) goto L_0078286e; /* je 0x78286e */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0078286bu); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_0078286e:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0xfu))); /* mov al, byte ptr [esp + 0xf] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00782a25; /* jne 0x782a25 */
    c->ecx = (uint32_t)(R32((uint32_t)(0x795680u))); /* mov ecx, dword ptr [0x10015680] */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0xb8u)); /* lea edx, [esp + 0xb8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = 0x80000000u; PUSH32(c, v_); } /* push 0x80000000 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4u)); PUSH32(c, 0x00782896u); call_indirect(c, t_); } /* call dword ptr [eax + 4] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (c->zf) goto L_00783242; /* je 0x783242 */
    c->ecx = (uint32_t)(R32((uint32_t)(0x795680u))); /* mov ecx, dword ptr [0x10015680] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x90u)); /* lea edx, [esp + 0x90] */
    { uint32_t v_ = 0x12u; PUSH32(c, v_); } /* push 0x12 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x18u)); PUSH32(c, 0x007828b9u); call_indirect(c, t_); } /* call dword ptr [eax + 0x18] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x98u))); /* mov eax, dword ptr [esp + 0x98] */
    { uint32_t v_ = 0x202u; PUSH32(c, v_); } /* push 0x202 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xffffu))); /* and eax, 0xffff */
    { uint32_t v_ = 0x792048u; PUSH32(c, v_); } /* push 0x10012048 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    W32((uint32_t)(c->ebx + 0x138u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 0x138], eax */
    { int64_t r_ = (int64_t)(int32_t)c->ecx * (int32_t)c->eax; c->ecx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul ecx, eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x007828e0u); f_00781070(c); /* call 0x781070 */
    W32((uint32_t)(c->esp + 0x34u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x34], eax */
    W32((uint32_t)(c->ebx + 0x8b4u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 0x8b4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x138u))); /* mov eax, dword ptr [ebx + 0x138] */
    c->edx = (uint32_t)(R32((uint32_t)(0x795680u))); /* mov edx, dword ptr [0x10015680] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { int64_t r_ = (int64_t)(int32_t)c->ecx * (int32_t)c->eax; c->ecx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul ecx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov eax, dword ptr [esp + 0x28] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edx))); /* mov edx, dword ptr [edx] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(0x795680u))); /* mov ecx, dword ptr [0x10015680] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x18u)); PUSH32(c, 0x00782912u); call_indirect(c, t_); } /* call dword ptr [edx + 0x18] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x795680u))); /* mov ecx, dword ptr [0x10015680] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x0078291eu); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x138u))); /* mov eax, dword ptr [ebx + 0x138] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x8b4u))); /* mov ecx, dword ptr [ebx + 0x8b4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->esi = (uint32_t)((uint32_t)(c->ebx + 0x894u)); /* lea esi, [ebx + 0x894] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00782939u); f_00785f10(c); /* call 0x785f10 */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x10u)); /* sub esp, 0x10 */
    c->ecx = (uint32_t)(c->esp); /* mov ecx, esp */
    W32((uint32_t)(c->esp + 0x38u), (uint32_t)(c->esp)); /* mov dword ptr [esp + 0x38], esp */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = 0x7921e8u; PUSH32(c, v_); } /* push 0x100121e8 */
    PUSH32(c, 0x0078294eu); f_007855a0(c); /* call 0x7855a0 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0xc0u)); /* lea edx, [esp + 0xc0] */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x88u)); /* lea ecx, [esp + 0x88] */
    W8((uint32_t)(c->esp + 0x85d4u), (uint8_t)((uint8_t)0x5u)); /* mov byte ptr [esp + 0x85d4], 5 */
    PUSH32(c, 0x0078296cu); f_007855a0(c); /* call 0x7855a0 */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x10u)); /* sub esp, 0x10 */
    W8((uint32_t)(c->esp + 0x85dcu), (uint8_t)((uint8_t)0x6u)); /* mov byte ptr [esp + 0x85dc], 6 */
    c->ecx = (uint32_t)(c->esp); /* mov ecx, esp */
    W32((uint32_t)(c->esp + 0x30u), (uint32_t)(c->esp)); /* mov dword ptr [esp + 0x30], esp */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00782985u); f_00785630(c); /* call 0x785630 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x70u)); /* lea ecx, [esp + 0x70] */
    W8((uint32_t)(c->esp + 0x85dcu), (uint8_t)((uint8_t)0x7u)); /* mov byte ptr [esp + 0x85dc], 7 */
    PUSH32(c, 0x00782996u); f_007852f0(c); /* call 0x7852f0 */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x10u)); /* sub esp, 0x10 */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->ecx = (uint32_t)(c->esp); /* mov ecx, esp */
    W8((uint32_t)(c->esp + 0x85ccu), (uint8_t)((uint8_t)0x8u)); /* mov byte ptr [esp + 0x85cc], 8 */
    W32((uint32_t)(c->esp + 0x38u), (uint32_t)(c->esp)); /* mov dword ptr [esp + 0x38], esp */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 4], edx */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 8], edx */
    W32((uint32_t)(c->ecx + 0xcu), (uint32_t)((uint32_t)0x10u)); /* mov dword ptr [ecx + 0xc], 0x10 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x4u)), c->edx); /* cmp dword ptr [eax + 4], edx */
    if (c->zf) goto L_007829c3; /* je 0x7829c3 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x007829c3u); f_00785280(c); /* call 0x785280 */
L_007829c3:;
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x007829cau); f_00786310(c); /* call 0x786310 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x50u))); /* mov eax, dword ptr [esp + 0x50] */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    W8((uint32_t)(c->esp + 0x85bcu), (uint8_t)((uint8_t)0x7u)); /* mov byte ptr [esp + 0x85bc], 7 */
    if (c->zf) goto L_007829e5; /* je 0x7829e5 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x007829e2u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_007829e5:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x70u))); /* mov eax, dword ptr [esp + 0x70] */
    W32((uint32_t)(c->esp + 0x50u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x50], esi */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    W32((uint32_t)(c->esp + 0x54u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x54], esi */
    W32((uint32_t)(c->esp + 0x58u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x58], esi */
    W8((uint32_t)(c->esp + 0x85bcu), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esp + 0x85bc], 0 */
    if (c->zf) goto L_00782a0a; /* je 0x782a0a */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00782a07u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00782a0a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x8b4u))); /* mov eax, dword ptr [ebx + 0x8b4] */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->zf) goto L_00782a1d; /* je 0x782a1d */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00782a1au); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00782a1d:;
    W32((uint32_t)(c->ebx + 0x8b4u), (uint32_t)(c->esi)); /* mov dword ptr [ebx + 0x8b4], esi */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_00782a25:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x894u))); /* mov edx, dword ptr [ebx + 0x894] */
    W32((uint32_t)(c->ebx + 0x13cu), (uint32_t)(c->esi)); /* mov dword ptr [ebx + 0x13c], esi */
    W32((uint32_t)(c->ebx + 0x138u), (uint32_t)(c->edx)); /* mov dword ptr [ebx + 0x138], edx */
L_00782a37:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x13cu))); /* mov ecx, dword ptr [ebx + 0x13c] */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    c->eax = (uint32_t)(shl32(c, c->eax, (c->ecx & 0xff))); /* shl eax, cl */
    (void)sub32(c, c->eax, c->edx); /* cmp eax, edx */
    if (c->zf) goto L_00782a56; /* je 0x782a56 */
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0x1u)); /* lea eax, [ecx + 1] */
    (void)sub32(c, c->eax, (uint32_t)0x1eu); /* cmp eax, 0x1e */
    W32((uint32_t)(c->ebx + 0x13cu), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 0x13c], eax */
    if (c->cf) goto L_00782a37; /* jb 0x782a37 */
L_00782a56:;
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x28], edx */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x2c], 0 */
    FPUSH(c, (double)(int64_t)R64((uint32_t)(c->esp + 0x28u))); /* fild qword ptr [esp + 0x28] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x1b0u)); /* lea eax, [esp + 0x1b0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    ST(0) = FPRES(c, FDIV(c, (double)RF32((uint32_t)(0x7902a8u)), ST(0))); /* fdivr dword ptr [0x100102a8] */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edi))); /* fmul dword ptr [edi] */
    WF32((uint32_t)(c->ebx + 0xfcu), (float)ST(0)); /* fst dword ptr [ebx + 0xfc] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ebx + 0x11cu))); /* fmul dword ptr [ebx + 0x11c] */
    WF32((uint32_t)(c->esp + 0x2cu), (float)ST(0)); /* fst dword ptr [esp + 0x2c] */
    WF32((uint32_t)(c->ebx + 0x100u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebx + 0x100] */
    FPUSH(c, (double)RF32((uint32_t)(0x7902a8u))); /* fld dword ptr [0x100102a8] */
    ST(0) = FPRES(c, FDIV(c, ST(0), ST(1))); /* fdiv st(1) */
    WF32((uint32_t)(c->ebx + 0x104u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebx + 0x104] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, (double)RF32((uint32_t)(0x7902a8u))); /* fld dword ptr [0x100102a8] */
    ST(0) = FPRES(c, FDIV(c, ST(0), (double)RF32((uint32_t)(c->esp + 0x2cu)))); /* fdiv dword ptr [esp + 0x2c] */
    WF32((uint32_t)(c->ebx + 0x108u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebx + 0x108] */
    FPUSH(c, (double)RF32((uint32_t)(c->edi))); /* fld dword ptr [edi] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x7902b0u))); /* fmul dword ptr [0x100102b0] */
    WF32((uint32_t)(c->edi), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi] */
    FPUSH(c, (double)RF32((uint32_t)(c->edi + 0x4u))); /* fld dword ptr [edi + 4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x7902b0u))); /* fmul dword ptr [0x100102b0] */
    WF32((uint32_t)(c->edi + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->edi + 0x8u))); /* fld dword ptr [edi + 8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x7902b0u))); /* fmul dword ptr [0x100102b0] */
    WF32((uint32_t)(c->edi + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->ebx + 0x12cu))); /* fld dword ptr [ebx + 0x12c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x7902b0u))); /* fmul dword ptr [0x100102b0] */
    WF32((uint32_t)(c->ebx + 0x12cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebx + 0x12c] */
    FPUSH(c, (double)RF32((uint32_t)(c->ebx + 0x130u))); /* fld dword ptr [ebx + 0x130] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x7902b0u))); /* fmul dword ptr [0x100102b0] */
    WF32((uint32_t)(c->ebx + 0x130u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebx + 0x130] */
    FPUSH(c, (double)RF32((uint32_t)(c->ebx + 0x134u))); /* fld dword ptr [ebx + 0x134] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x7902b0u))); /* fmul dword ptr [0x100102b0] */
    WF32((uint32_t)(c->ebx + 0x134u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebx + 0x134] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x795680u))); /* mov ecx, dword ptr [0x10015680] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x58u)); PUSH32(c, 0x00782b13u); call_indirect(c, t_); } /* call dword ptr [edx + 0x58] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(!c->zf ? 1 : 0); /* setne al */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x10], esi */
    W8((uint32_t)(c->esp + 0xfu), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [esp + 0xf], al */
    if (!c->zf) goto L_00782b49; /* jne 0x782b49 */
    c->eax = (uint32_t)(R32((uint32_t)(0x795678u))); /* mov eax, dword ptr [0x10015678] */
    { uint32_t v_ = 0x79234cu; PUSH32(c, v_); } /* push 0x1001234c */
    { uint32_t v_ = 0x21au; PUSH32(c, v_); } /* push 0x21a */
    { uint32_t v_ = 0x792048u; PUSH32(c, v_); } /* push 0x10012048 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x7920b0u; PUSH32(c, v_); } /* push 0x100120b0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00782b45u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00782b48u, "int3"); /* int3  */
L_00782b49:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    { uint32_t v_ = 0x792340u; PUSH32(c, v_); } /* push 0x10012340 */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x2b4u)); /* lea eax, [esp + 0x2b4] */
    { uint32_t v_ = 0xffu; PUSH32(c, v_); } /* push 0xff */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x792334u; PUSH32(c, v_); } /* push 0x10012334 */
    { uint32_t v_ = 0x79232cu; PUSH32(c, v_); } /* push 0x1001232c */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00782b6cu); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x3cu)); /* lea ecx, [esp + 0x3c] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x38u)); /* lea edx, [esp + 0x38] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x38u)); /* lea eax, [esp + 0x38] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x2bcu)); /* lea ecx, [esp + 0x2bc] */
    { uint32_t v_ = 0x792320u; PUSH32(c, v_); } /* push 0x10012320 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00782b8du); f_00786bc5(c); /* call 0x786bc5 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x2b0u)); /* lea eax, [esp + 0x2b0] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t v_ = 0x792340u; PUSH32(c, v_); } /* push 0x10012340 */
    { uint32_t v_ = 0xffu; PUSH32(c, v_); } /* push 0xff */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x792314u; PUSH32(c, v_); } /* push 0x10012314 */
    { uint32_t v_ = 0x79232cu; PUSH32(c, v_); } /* push 0x1001232c */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00782bb3u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x48u)); /* lea ecx, [esp + 0x48] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x44u)); /* lea edx, [esp + 0x44] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x44u)); /* lea eax, [esp + 0x44] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x2bcu)); /* lea ecx, [esp + 0x2bc] */
    { uint32_t v_ = 0x792320u; PUSH32(c, v_); } /* push 0x10012320 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00782bd4u); f_00786bc5(c); /* call 0x786bc5 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x50u))); /* fld dword ptr [esp + 0x50] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->ebx + 0x128u))); /* fsub dword ptr [ebx + 0x128] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x4cu))); /* fld dword ptr [esp + 0x4c] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->ebx + 0x124u))); /* fsub dword ptr [ebx + 0x124] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x48u))); /* fld dword ptr [esp + 0x48] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->ebx + 0x120u))); /* fsub dword ptr [ebx + 0x120] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    { double v_ = ST(2); FPUSH(c, v_); } /* fld st(2) */
    ST(0) = FPRES(c, ST(0) * ST(3)); /* fmul st(3) */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    { double v_ = ST(3); FPUSH(c, v_); } /* fld st(3) */
    ST(0) = FPRES(c, ST(0) * ST(4)); /* fmul st(4) */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x7902fcu))); FPOP(c); /* fcomp dword ptr [0x100102fc] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    if (!c->zf) goto L_00782ca3; /* jne 0x782ca3 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x3cu))); /* fld dword ptr [esp + 0x3c] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->ebx + 0x128u))); /* fsub dword ptr [ebx + 0x128] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x38u))); /* fld dword ptr [esp + 0x38] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->ebx + 0x124u))); /* fsub dword ptr [ebx + 0x124] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x34u))); /* fld dword ptr [esp + 0x34] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->ebx + 0x120u))); /* fsub dword ptr [ebx + 0x120] */
    c->eax = (uint32_t)(R32((uint32_t)(0x79567cu))); /* mov eax, dword ptr [0x1001567c] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x1b8u)); /* lea ecx, [esp + 0x1b8] */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    { double v_ = ST(2); FPUSH(c, v_); } /* fld st(2) */
    ST(0) = FPRES(c, ST(0) * ST(3)); /* fmul st(3) */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    { double v_ = ST(3); FPUSH(c, v_); } /* fld st(3) */
    ST(0) = FPRES(c, ST(0) * ST(4)); /* fmul st(4) */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(3) = ST(0); FPOP(c); /* fstp st(3) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    ST(0) = FPRES(c, sqrt(ST(0))); /* fsqrt  */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x7922d4u; PUSH32(c, v_); } /* push 0x100122d4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x30u)); PUSH32(c, 0x00782c72u); call_indirect(c, t_); } /* call dword ptr [edx + 0x30] */
    FPUSH(c, (double)RF32((uint32_t)(c->ebx + 0x128u))); /* fld dword ptr [ebx + 0x128] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(0x79567cu))); /* mov eax, dword ptr [0x1001567c] */
    WF64((uint32_t)(c->esp + 0x10u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x10] */
    FPUSH(c, (double)RF32((uint32_t)(c->ebx + 0x124u))); /* fld dword ptr [ebx + 0x124] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    WF64((uint32_t)(c->esp + 0x8u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->ebx + 0x120u))); /* fld dword ptr [ebx + 0x120] */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    { uint32_t v_ = 0x7922bcu; PUSH32(c, v_); } /* push 0x100122bc */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x30u)); PUSH32(c, 0x00782ca0u); call_indirect(c, t_); } /* call dword ptr [edx + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
L_00782ca3:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x48u))); /* fld dword ptr [esp + 0x48] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->edi + 0x8u))); /* fsub dword ptr [edi + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x44u))); /* fld dword ptr [esp + 0x44] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->edi + 0x4u))); /* fsub dword ptr [edi + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x40u))); /* fld dword ptr [esp + 0x40] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->edi))); /* fsub dword ptr [edi] */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    { double v_ = ST(2); FPUSH(c, v_); } /* fld st(2) */
    ST(0) = FPRES(c, ST(0) * ST(3)); /* fmul st(3) */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    { double v_ = ST(3); FPUSH(c, v_); } /* fld st(3) */
    ST(0) = FPRES(c, ST(0) * ST(4)); /* fmul st(4) */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x7902fcu))); FPOP(c); /* fcomp dword ptr [0x100102fc] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    if (!c->zf) goto L_00782d23; /* jne 0x782d23 */
    c->eax = (uint32_t)(R32((uint32_t)(0x79567cu))); /* mov eax, dword ptr [0x1001567c] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x1b0u)); /* lea edx, [esp + 0x1b0] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x792290u; PUSH32(c, v_); } /* push 0x10012290 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x00782cf4u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    FPUSH(c, (double)RF32((uint32_t)(c->ebx + 0x11cu))); /* fld dword ptr [ebx + 0x11c] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    c->eax = (uint32_t)(R32((uint32_t)(0x79567cu))); /* mov eax, dword ptr [0x1001567c] */
    WF64((uint32_t)(c->esp + 0x10u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x10] */
    FPUSH(c, (double)RF32((uint32_t)(c->ebx + 0x118u))); /* fld dword ptr [ebx + 0x118] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    WF64((uint32_t)(c->esp + 0x8u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->edi))); /* fld dword ptr [edi] */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    { uint32_t v_ = 0x79227cu; PUSH32(c, v_); } /* push 0x1001227c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x00782d20u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
L_00782d23:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0xfu))); /* mov al, byte ptr [esp + 0xf] */
    c->esi = (uint32_t)((uint32_t)(c->ebx + 0x88u)); /* lea esi, [ebx + 0x88] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00782d54; /* jne 0x782d54 */
    c->eax = (uint32_t)(R32((uint32_t)(0x795678u))); /* mov eax, dword ptr [0x10015678] */
    { uint32_t v_ = 0x792274u; PUSH32(c, v_); } /* push 0x10012274 */
    { uint32_t v_ = 0xc9u; PUSH32(c, v_); } /* push 0xc9 */
    { uint32_t v_ = 0x79212cu; PUSH32(c, v_); } /* push 0x1001212c */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0x7920b0u; PUSH32(c, v_); } /* push 0x100120b0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00782d50u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00782d53u, "int3"); /* int3  */
L_00782d54:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x1cu))); /* mov eax, dword ptr [esi + 0x1c] */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x1cu)); /* lea ecx, [esi + 0x1c] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4u)); PUSH32(c, 0x00782d5du); call_indirect(c, t_); } /* call dword ptr [eax + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x34u))); /* mov edx, dword ptr [esi + 0x34] */
    c->ebx = (uint32_t)((uint32_t)(c->esi + 0x34u)); /* lea ebx, [esi + 0x34] */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x4u)); PUSH32(c, 0x00782d68u); call_indirect(c, t_); } /* call dword ptr [edx + 4] */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x54u)); /* lea ecx, [esp + 0x54] */
    PUSH32(c, 0x00782d73u); f_007851c0(c); /* call 0x7851c0 */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x74u)); /* lea ecx, [esp + 0x74] */
    W8((uint32_t)(c->esp + 0x85c0u), (uint8_t)((uint8_t)0x9u)); /* mov byte ptr [esp + 0x85c0], 9 */
    PUSH32(c, 0x00782d86u); f_007851c0(c); /* call 0x7851c0 */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edi, dword ptr [esp + 0x10] */
    W8((uint32_t)(c->esp + 0x85bcu), (uint8_t)((uint8_t)0xau)); /* mov byte ptr [esp + 0x85bc], 0xa */
L_00782d92:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x40u))); /* mov eax, dword ptr [esi + 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x74u)); /* lea eax, [esp + 0x74] */
    { uint32_t v_ = 0x79226cu; PUSH32(c, v_); } /* push 0x1001226c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00782da5u); f_00785470(c); /* call 0x785470 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4cu))); /* mov eax, dword ptr [esi + 0x4c] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi))); /* mov edx, dword ptr [edi] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x5b0u)); /* lea ecx, [esp + 0x5b0] */
    { uint32_t v_ = 0x7956a0u; PUSH32(c, v_); } /* push 0x100156a0 */
    { uint32_t v_ = 0x8000u; PUSH32(c, v_); } /* push 0x8000 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x7cu))); /* mov ecx, dword ptr [esp + 0x7c] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    W8((uint32_t)(c->esp + 0x5c4u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esp + 0x5c4], 0 */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00782dd2u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x5b0u))); /* mov al, byte ptr [esp + 0x5b0] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00782e10; /* je 0x782e10 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    PUSH32(c, 0x00782de4u); f_00784a10(c); /* call 0x784a10 */
    c->edx = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea edx, [eax + eax*4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x3cu))); /* mov eax, dword ptr [esi + 0x3c] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->edx * 8)); /* lea eax, [eax + edx*8] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x5b0u)); /* lea edx, [esp + 0x5b0] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x8u)); /* lea ecx, [eax + 8] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [eax + 4], 0 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x792264u; PUSH32(c, v_); } /* push 0x10012264 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00782e0bu); f_00786bc5(c); /* call 0x786bc5 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    goto L_00782d92; /* jmp 0x782d92 */
L_00782e10:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x40u))); /* mov eax, dword ptr [esi + 0x40] */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x1c], 0 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->cf || c->zf)) goto L_00782fca; /* jbe 0x782fca */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x18], 0 */
L_00782e2b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov eax, dword ptr [esp + 0x1c] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x70u)); /* lea ecx, [esp + 0x70] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x79226cu; PUSH32(c, v_); } /* push 0x1001226c */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00782e3fu); f_00785470(c); /* call 0x785470 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov ecx, dword ptr [esp + 0x1c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4cu))); /* mov eax, dword ptr [esi + 0x4c] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)((uint32_t)(c->esp + 0x5b0u)); /* lea edi, [esp + 0x5b0] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    W8((uint32_t)(c->esp + 0x5b0u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esp + 0x5b0], 0 */
    { uint32_t v_ = 0x8000u; PUSH32(c, v_); } /* push 0x8000 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x78u))); /* mov edi, dword ptr [esp + 0x78] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x18u)); PUSH32(c, 0x00782e69u); call_indirect(c, t_); } /* call dword ptr [edx + 0x18] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x5b0u))); /* mov al, byte ptr [esp + 0x5b0] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00782fab; /* je 0x782fab */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x24u)); /* lea eax, [esp + 0x24] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x80u)); /* lea ecx, [esp + 0x80] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x24u)); /* lea edx, [esp + 0x24] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x5bcu)); /* lea eax, [esp + 0x5bc] */
    { uint32_t v_ = 0x792258u; PUSH32(c, v_); } /* push 0x10012258 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00782e9cu); f_00786bc5(c); /* call 0x786bc5 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x5b0u)); /* lea ecx, [esp + 0x5b0] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x54u)); /* lea ecx, [esp + 0x54] */
    PUSH32(c, 0x00782eb0u); f_007851f0(c); /* call 0x7851f0 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea edx, [esp + 0x14] */
    { uint32_t v_ = 0x792254u; PUSH32(c, v_); } /* push 0x10012254 */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x5b4u)); /* lea eax, [esp + 0x5b4] */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x5cu)); /* lea ecx, [esp + 0x5c] */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x20], ebx */
    PUSH32(c, 0x00782ed1u); f_00785530(c); /* call 0x785530 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea ecx, [esp + 0x14] */
    { uint32_t v_ = 0x792254u; PUSH32(c, v_); } /* push 0x10012254 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x5b4u)); /* lea edx, [esp + 0x5b4] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x5cu)); /* lea ecx, [esp + 0x5c] */
    PUSH32(c, 0x00782eecu); f_00785530(c); /* call 0x785530 */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea eax, [esp + 0x14] */
    { uint32_t v_ = 0x792254u; PUSH32(c, v_); } /* push 0x10012254 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x5b4u)); /* lea ecx, [esp + 0x5b4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x5cu)); /* lea ecx, [esp + 0x5c] */
    PUSH32(c, 0x00782f07u); f_00785530(c); /* call 0x785530 */
    (void)sub32(c, R32((uint32_t)(c->esp + 0x24u)), c->ebx); /* cmp dword ptr [esp + 0x24], ebx */
    if ((c->cf || c->zf)) goto L_00782fab; /* jbe 0x782fab */
L_00782f11:;
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea edx, [esp + 0x14] */
    { uint32_t v_ = 0x792254u; PUSH32(c, v_); } /* push 0x10012254 */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x5b4u)); /* lea eax, [esp + 0x5b4] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x5cu)); /* lea ecx, [esp + 0x5c] */
    PUSH32(c, 0x00782f2cu); f_00785530(c); /* call 0x785530 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x4cu)); /* lea ecx, [esp + 0x4c] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x5b0u)); /* lea edx, [esp + 0x5b0] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x792250u; PUSH32(c, v_); } /* push 0x10012250 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00782f43u); f_00786bc5(c); /* call 0x786bc5 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea eax, [esp + 0x14] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x5b0u)); /* lea ecx, [esp + 0x5b0] */
    { uint32_t v_ = 0x792254u; PUSH32(c, v_); } /* push 0x10012254 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x5cu)); /* lea ecx, [esp + 0x5c] */
    PUSH32(c, 0x00782f61u); f_00785530(c); /* call 0x785530 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x28u)); /* lea edx, [esp + 0x28] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x5b0u)); /* lea eax, [esp + 0x5b0] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x792250u; PUSH32(c, v_); } /* push 0x10012250 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00782f78u); f_00786bc5(c); /* call 0x786bc5 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov ecx, dword ptr [esp + 0x34] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x58u))); /* mov edx, dword ptr [esp + 0x58] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi + 0x3cu))); /* mov edi, dword ptr [esi + 0x3c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov eax, dword ptr [esp + 0x24] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00782f95u); f_00785910(c); /* call 0x785910 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)((uint32_t)(c->edi + 0x10u)); /* lea ecx, [edi + 0x10] */
    PUSH32(c, 0x00782f9eu); f_007846c0(c); /* call 0x7846c0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov eax, dword ptr [esp + 0x24] */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    (void)sub32(c, c->ebx, c->eax); /* cmp ebx, eax */
    if (c->cf) goto L_00782f11; /* jb 0x782f11 */
L_00782fab:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov eax, dword ptr [esp + 0x1c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov edx, dword ptr [esp + 0x18] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x40u))); /* mov ecx, dword ptr [esi + 0x40] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x28u)); /* add edx, 0x28 */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x1c], eax */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x18], edx */
    if (c->cf) goto L_00782e2b; /* jb 0x782e2b */
L_00782fca:;
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x70u)); /* lea ecx, [esp + 0x70] */
    W8((uint32_t)(c->esp + 0x85bcu), (uint8_t)((uint8_t)0x9u)); /* mov byte ptr [esp + 0x85bc], 9 */
    PUSH32(c, 0x00782fdbu); f_007856d0(c); /* call 0x7856d0 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x50u)); /* lea ecx, [esp + 0x50] */
    W8((uint32_t)(c->esp + 0x85bcu), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esp + 0x85bc], 0 */
    PUSH32(c, 0x00782fecu); f_007856d0(c); /* call 0x7856d0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x5cu))); /* mov eax, dword ptr [esi + 0x5c] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esi + 0x40u))); /* mov ebx, dword ptr [esi + 0x40] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x14], ebx */
    if (c->zf) goto L_00783003; /* je 0x783003 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00783000u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00783003:;
    c->edi = (uint32_t)(c->ebx); /* mov edi, ebx */
    W32((uint32_t)(c->esi + 0x5cu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 0x5c], 0 */
    { int64_t r_ = (int64_t)(int32_t)c->edi * (int32_t)c->ebx; c->edi = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul edi, ebx */
    c->eax = (uint32_t)((uint32_t)(c->edi * 8)); /* lea eax, [edi*8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0078301cu); f_00781030(c); /* call 0x781030 */
    W32((uint32_t)(c->esi + 0x5cu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x5c], eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if ((c->cf || c->zf)) goto L_00783044; /* jbe 0x783044 */
    c->ecx = (uint32_t)((uint32_t)0x4cbebc20u); /* mov ecx, 0x4cbebc20 */
L_0078302d:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x5cu))); /* mov edx, dword ptr [esi + 0x5c] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    W32((uint32_t)(c->edx + c->eax * 8 + 0xfffffff8u), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [edx + eax*8 - 8], 0xffffffff */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x5cu))); /* mov edx, dword ptr [esi + 0x5c] */
    W32((uint32_t)(c->edx + c->eax * 8 + 0xfffffffcu), (uint32_t)(c->ecx)); /* mov dword ptr [edx + eax*8 - 4], ecx */
    if (c->cf) goto L_0078302d; /* jb 0x78302d */
L_00783044:;
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x1c], 0 */
    if ((c->cf || c->zf)) goto L_007830e9; /* jbe 0x7830e9 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x18], eax */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x20], eax */
L_0078305e:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->esi + 0x3cu))); /* mov ebx, dword ptr [esi + 0x3c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov edx, dword ptr [esp + 0x18] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x5cu))); /* mov eax, dword ptr [esi + 0x5c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov ecx, dword ptr [esp + 0x20] */
    c->ebx = (uint32_t)(add32(c, c->ebx, c->edx)); /* add ebx, edx */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x24], eax */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x1cu))); /* mov eax, dword ptr [ebx + 0x1c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->cf || c->zf)) goto L_007830b8; /* jbe 0x7830b8 */
L_0078307d:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x18u))); /* mov ecx, dword ptr [ebx + 0x18] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov eax, dword ptr [esp + 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + c->edi * 4))); /* mov edx, dword ptr [ecx + edi*4] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00783090u); f_00785a80(c); /* call 0x785a80 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov ecx, dword ptr [esp + 0x24] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    W32((uint32_t)(c->ecx + c->eax * 8), (uint32_t)(c->eax)); /* mov dword ptr [ecx + eax*8], eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x18u))); /* mov edx, dword ptr [ebx + 0x18] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + c->edi * 4 + 0xfffffffcu))); /* mov ecx, dword ptr [edx + edi*4 - 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov edx, dword ptr [esi + 0x24] */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea ecx, [ecx + ecx*2] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + c->ecx * 4 + 0x8u))); /* mov ecx, dword ptr [edx + ecx*4 + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov edx, dword ptr [esp + 0x24] */
    W32((uint32_t)(c->edx + c->eax * 8 + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [edx + eax*8 + 4], ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x1cu))); /* mov eax, dword ptr [ebx + 0x1c] */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_0078307d; /* jb 0x78307d */
L_007830b8:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edx, dword ptr [esp + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov eax, dword ptr [esp + 0x1c] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov ebx, dword ptr [esp + 0x18] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov edi, dword ptr [esp + 0x20] */
    c->ecx = (uint32_t)((uint32_t)(c->edx * 8)); /* lea ecx, [edx*8] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x28u)); /* add ebx, 0x28 */
    c->edi = (uint32_t)(add32(c, c->edi, c->ecx)); /* add edi, ecx */
    (void)sub32(c, c->eax, c->edx); /* cmp eax, edx */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x1c], eax */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x18], ebx */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x20], edi */
    if (c->cf) goto L_0078305e; /* jb 0x78305e */
L_007830e9:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x28], 0 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->cf || c->zf)) goto L_00783233; /* jbe 0x783233 */
L_007830fd:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W8((uint32_t)(c->esp + 0xfu), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esp + 0xf], 1 */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x1c], eax */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x18], eax */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x24], eax */
L_00783110:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W32((uint32_t)(c->esp + 0x4cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x4c], eax */
L_00783116:;
    (void)sub32(c, c->eax, R32((uint32_t)(c->esp + 0x1cu))); /* cmp eax, dword ptr [esp + 0x1c] */
    if (c->zf) goto L_007831e3; /* je 0x7831e3 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esi + 0x3cu))); /* mov ebx, dword ptr [esi + 0x3c] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov edi, dword ptr [esp + 0x24] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov ecx, dword ptr [esp + 0x18] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x5cu))); /* mov edx, dword ptr [esi + 0x5c] */
    c->ebx = (uint32_t)(add32(c, c->ebx, c->edi)); /* add ebx, edi */
    W32((uint32_t)(c->esp + 0x80u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x80], 0 */
    c->edi = (uint32_t)((uint32_t)(c->eax + c->ecx)); /* lea edi, [eax + ecx] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x1cu))); /* mov ecx, dword ptr [ebx + 0x1c] */
    c->edi = (uint32_t)(shl32(c, c->edi, 3)); /* shl edi, 3 */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + c->edi + 0x4u))); /* fld dword ptr [edx + edi + 4] */
    WF32((uint32_t)(c->esp + 0x20u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x20] */
    if ((c->cf || c->zf)) goto L_007831e3; /* jbe 0x7831e3 */
L_00783154:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov eax, dword ptr [esp + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x18u))); /* mov ecx, dword ptr [ebx + 0x18] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x80u))); /* mov edx, dword ptr [esp + 0x80] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + c->edx * 4))); /* mov eax, dword ptr [ecx + edx*4] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0078316eu); f_00785a80(c); /* call 0x785a80 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x5cu))); /* mov edx, dword ptr [esi + 0x5c] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + c->eax * 8 + 0x4u))); /* fld dword ptr [edx + eax*8 + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)c->ecx; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, ecx */
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->esp + 0x4cu)))); /* add eax, dword ptr [esp + 0x4c] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->edx + c->eax * 8 + 0x4u))); /* fadd dword ptr [edx + eax*8 + 4] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->esp + 0x20u))); /* fcom dword ptr [esp + 0x20] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_007831c3; /* jp 0x7831c3 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x20u))); /* fld dword ptr [esp + 0x20] */
    ST(0) = FPRES(c, ST(1) - ST(0)); /* fsubr st(1) */
    ST(0) = fabs(ST(0)); /* fabs  */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x7902f8u))); FPOP(c); /* fcomp dword ptr [0x100102f8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_007831c3; /* jne 0x7831c3 */
    WF32((uint32_t)(c->esp + 0x20u), (float)ST(0)); /* fst dword ptr [esp + 0x20] */
    WF32((uint32_t)(c->edi + c->edx + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + edx + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x5cu))); /* mov edx, dword ptr [esi + 0x5c] */
    W8((uint32_t)(c->esp + 0xfu), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esp + 0xf], 0 */
    W32((uint32_t)(c->edi + c->edx), (uint32_t)(c->ecx)); /* mov dword ptr [edi + edx], ecx */
    goto L_007831c5; /* jmp 0x7831c5 */
L_007831c3:;
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
L_007831c5:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x80u))); /* mov eax, dword ptr [esp + 0x80] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x1cu))); /* mov ecx, dword ptr [ebx + 0x1c] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    W32((uint32_t)(c->esp + 0x80u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x80], eax */
    if (c->cf) goto L_00783154; /* jb 0x783154 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4cu))); /* mov eax, dword ptr [esp + 0x4c] */
L_007831e3:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ecx, dword ptr [esp + 0x14] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    W32((uint32_t)(c->esp + 0x4cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x4c], eax */
    if (c->cf) goto L_00783116; /* jb 0x783116 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov eax, dword ptr [esp + 0x1c] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov ebx, dword ptr [esp + 0x24] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov edi, dword ptr [esp + 0x18] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x28u)); /* add ebx, 0x28 */
    c->edi = (uint32_t)(add32(c, c->edi, c->ecx)); /* add edi, ecx */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x1c], eax */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x24], ebx */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x18], edi */
    if (c->cf) goto L_00783110; /* jb 0x783110 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0xfu))); /* mov al, byte ptr [esp + 0xf] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00783233; /* jne 0x783233 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov eax, dword ptr [esp + 0x28] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x28], eax */
    if (c->cf) goto L_007830fd; /* jb 0x7830fd */
L_00783233:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax)); PUSH32(c, 0x0078323du); call_indirect(c, t_); } /* call dword ptr [eax] */
    goto L_00783933; /* jmp 0x783933 */
L_00783242:;
    c->eax = (uint32_t)(R32((uint32_t)(0x79567cu))); /* mov eax, dword ptr [0x1001567c] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0xb0u)); /* lea edx, [esp + 0xb0] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x792230u; PUSH32(c, v_); } /* push 0x10012230 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x0078325au); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    FPUSH(c, (double)RF32((uint32_t)(c->edi))); /* fld dword ptr [edi] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x7902e8u))); /* fmul dword ptr [0x100102e8] */
    { uint32_t v_ = 0x257u; PUSH32(c, v_); } /* push 0x257 */
    { uint32_t v_ = 0x792048u; PUSH32(c, v_); } /* push 0x10012048 */
    { uint32_t v_ = 0x100000u; PUSH32(c, v_); } /* push 0x100000 */
    W32((uint32_t)(c->ebx + 0x13cu), (uint32_t)((uint32_t)0xau)); /* mov dword ptr [ebx + 0x13c], 0xa */
    W32((uint32_t)(c->ebx + 0x138u), (uint32_t)((uint32_t)0x400u)); /* mov dword ptr [ebx + 0x138], 0x400 */
    WF32((uint32_t)(c->ebx + 0xfcu), (float)ST(0)); /* fst dword ptr [ebx + 0xfc] */
    FPUSH(c, (double)RF32((uint32_t)(c->ebx + 0x11cu))); /* fld dword ptr [ebx + 0x11c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x7902e8u))); /* fmul dword ptr [0x100102e8] */
    WF32((uint32_t)(c->ebx + 0x100u), (float)ST(0)); /* fst dword ptr [ebx + 0x100] */
    FPUSH(c, (double)RF32((uint32_t)(0x7902a8u))); /* fld dword ptr [0x100102a8] */
    ST(0) = FPRES(c, FDIV(c, ST(0), ST(2))); /* fdiv st(2) */
    WF32((uint32_t)(c->ebx + 0x104u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebx + 0x104] */
    FPUSH(c, (double)RF32((uint32_t)(0x7902a8u))); /* fld dword ptr [0x100102a8] */
    ST(0) = FPRES(c, FDIV(c, ST(0), ST(1))); /* fdiv st(1) */
    WF32((uint32_t)(c->ebx + 0x108u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebx + 0x108] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    PUSH32(c, 0x007832c2u); f_00781070(c); /* call 0x781070 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebx + 0x138u))); /* mov esi, dword ptr [ebx + 0x138] */
    W32((uint32_t)(c->esp + 0x44u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x44], 0 */
    W32((uint32_t)(c->esp + 0x40u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x40], esi */
    W32((uint32_t)(c->ebx + 0x8b4u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 0x8b4], eax */
    FPUSH(c, (double)(int64_t)R64((uint32_t)(c->esp + 0x40u))); /* fild qword ptr [esp + 0x40] */
    FPUSH(c, (double)RF32((uint32_t)(0x7902b8u))); /* fld dword ptr [0x100102b8] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x1c], 0 */
    FCOM(c, ST(0), ST(1)); FPOP(c); /* fcomp st(1) */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_0078364a; /* jp 0x78364a */
L_007832fc:;
    FPUSH(c, (double)RF32((uint32_t)(0x7902b8u))); /* fld dword ptr [0x100102b8] */
    FCOM(c, ST(0), ST(1)); FPOP(c); FPOP(c); /* fcompp  */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x18], 0 */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00783608; /* jp 0x783608 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fld dword ptr [esp + 0x1c] */
    PUSH32(c, 0x00783320u); f_00786b70(c); /* call 0x786b70 */
    W32((uint32_t)(c->esp + 0x4cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x4c], eax */
L_00783324:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    { int64_t r_ = (int64_t)(int32_t)c->esi * (int32_t)R32((uint32_t)(c->esp + 0x4cu)); c->esi = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul esi, dword ptr [esp + 0x4c] */
    PUSH32(c, 0x00783332u); f_00786b70(c); /* call 0x786b70 */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x8b4u))); /* mov eax, dword ptr [ebx + 0x8b4] */
    W32((uint32_t)(c->esp + 0x84u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x84], 0 */
    W8((uint32_t)(c->esi + c->eax), (uint8_t)((uint8_t)0xffu)); /* mov byte ptr [esi + eax], 0xff */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x138u))); /* mov ecx, dword ptr [ebx + 0x138] */
    W32((uint32_t)(c->esp + 0x80u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x80], ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x124u))); /* mov edx, dword ptr [ebx + 0x124] */
    FPUSH(c, (double)(int64_t)R64((uint32_t)(c->esp + 0x80u))); /* fild qword ptr [esp + 0x80] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    W32((uint32_t)(c->esp + 0x44u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x44], edx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x34u)); /* lea ecx, [esp + 0x34] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x40u)); /* lea edx, [esp + 0x40] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x7902b0u))); /* fmul dword ptr [0x100102b0] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    ST(0) = FPRES(c, ST(0) - ST(1)); /* fsub st(1) */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ebx + 0xfcu))); /* fmul dword ptr [ebx + 0xfc] */
    WF32((uint32_t)(c->esp + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x24u))); /* fld dword ptr [esp + 0x24] */
    ST(0) = FPRES(c, ST(0) - ST(1)); /* fsub st(1) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ebx + 0x100u))); /* fmul dword ptr [ebx + 0x100] */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0x7902f4u))); /* fadd dword ptr [0x100102f4] */
    WF32((uint32_t)(c->esp + 0x30u), (float)ST(0)); /* fst dword ptr [esp + 0x30] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fld dword ptr [esp + 0x1c] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ebx + 0x120u))); /* fadd dword ptr [ebx + 0x120] */
    WF32((uint32_t)(c->esp + 0x48u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x48] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ebx + 0x128u))); /* fadd dword ptr [ebx + 0x128] */
    WF32((uint32_t)(c->esp + 0x50u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x50] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fld dword ptr [esp + 0x1c] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ebx + 0x120u))); /* fadd dword ptr [ebx + 0x120] */
    WF32((uint32_t)(c->esp + 0x3cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x3c] */
    FPUSH(c, (double)RF32((uint32_t)(c->ebx + 0x124u))); /* fld dword ptr [ebx + 0x124] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0x7902e4u))); /* fsub dword ptr [0x100102e4] */
    WF32((uint32_t)(c->esp + 0x40u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x40] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ebx + 0x128u))); /* fadd dword ptr [ebx + 0x128] */
    WF32((uint32_t)(c->esp + 0x44u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x44] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x24u)); PUSH32(c, 0x007833f2u); call_indirect(c, t_); } /* call dword ptr [eax + 0x24] */
    WF32((uint32_t)(c->esp + 0x20u), (float)ST(0)); /* fst dword ptr [esp + 0x20] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x00783401u); f_00786b97(c); /* call 0x786b97 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete al */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00783430; /* jne 0x783430 */
    c->eax = (uint32_t)(R32((uint32_t)(0x795678u))); /* mov eax, dword ptr [0x10015678] */
    { uint32_t v_ = 0x792218u; PUSH32(c, v_); } /* push 0x10012218 */
    { uint32_t v_ = 0x268u; PUSH32(c, v_); } /* push 0x268 */
    { uint32_t v_ = 0x792048u; PUSH32(c, v_); } /* push 0x10012048 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x7920b0u; PUSH32(c, v_); } /* push 0x100120b0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x0078342cu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x0078342fu, "int3"); /* int3  */
L_00783430:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x20u))); /* fld dword ptr [esp + 0x20] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x7902a8u))); FPOP(c); /* fcomp dword ptr [0x100102a8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x41u)); /* test ah, 0x41 */
    if (PF(c)) goto L_007834ee; /* jp 0x7834ee */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x3cu))); /* fld dword ptr [esp + 0x3c] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x48u))); /* fsub dword ptr [esp + 0x48] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x38u))); /* fld dword ptr [esp + 0x38] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x44u))); /* fsub dword ptr [esp + 0x44] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x34u))); /* fld dword ptr [esp + 0x34] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x40u))); /* fsub dword ptr [esp + 0x40] */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x20u))); /* fmul dword ptr [esp + 0x20] */
    WF32((uint32_t)(c->esp + 0x28u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x28] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x20u))); /* fmul dword ptr [esp + 0x20] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x20u))); /* fmul dword ptr [esp + 0x20] */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    { double v_ = ST(2); FPUSH(c, v_); } /* fld st(2) */
    ST(0) = FPRES(c, ST(0) * ST(3)); /* fmul st(3) */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x28u))); /* fld dword ptr [esp + 0x28] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x28u))); /* fmul dword ptr [esp + 0x28] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(2) = ST(0); FPOP(c); /* fstp st(2) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    ST(0) = FPRES(c, sqrt(ST(0))); /* fsqrt  */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); /* fst dword ptr [esp + 0x10] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x7902f0u))); FPOP(c); /* fcomp dword ptr [0x100102f0] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_007834ac; /* jne 0x7834ac */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0x41a00000u)); /* mov dword ptr [esp + 0x10], 0x41a00000 */
L_007834ac:;
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x40u)); /* lea edx, [esp + 0x40] */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x007834b8u); f_007820c0(c); /* call 0x7820c0 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_007834cb; /* je 0x7834cb */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x8b4u))); /* mov eax, dword ptr [ebx + 0x8b4] */
    W8((uint32_t)(c->esi + c->eax), (uint8_t)((uint8_t)0x2u)); /* mov byte ptr [esi + eax], 2 */
    goto L_007835ca; /* jmp 0x7835ca */
L_007834cb:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x7902ecu))); /* fmul dword ptr [0x100102ec] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0x790288u))); /* fadd dword ptr [0x10010288] */
    PUSH32(c, 0x007834e0u); f_00786b70(c); /* call 0x786b70 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x8b4u))); /* mov ecx, dword ptr [ebx + 0x8b4] */
    W8((uint32_t)(c->esi + c->ecx), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [esi + ecx], al */
    goto L_007835ca; /* jmp 0x7835ca */
L_007834ee:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edx, dword ptr [esp + 0x14] */
    W32((uint32_t)(c->esp + 0x74u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x74], 0 */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ebx + 0x120u))); /* fadd dword ptr [ebx + 0x120] */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    W32((uint32_t)(c->esp + 0x70u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x70], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x74u))); /* mov edx, dword ptr [esp + 0x74] */
    W32((uint32_t)(c->esp + 0x40u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x40], ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    W32((uint32_t)(c->esp + 0x44u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x44], edx */
    WF32((uint32_t)(c->esp + 0x40u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x40] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x44u))); /* fld dword ptr [esp + 0x44] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ebx + 0x124u))); /* fadd dword ptr [ebx + 0x124] */
    W32((uint32_t)(c->esp + 0x48u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x48], eax */
    W32((uint32_t)(c->esp + 0x78u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x78], eax */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    W32((uint32_t)(c->esp + 0x50u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x50], ecx */
    W32((uint32_t)(c->esp + 0x54u), (uint32_t)((uint32_t)0x44bb8000u)); /* mov dword ptr [esp + 0x54], 0x44bb8000 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x54u))); /* mov ecx, dword ptr [esp + 0x54] */
    WF32((uint32_t)(c->esp + 0x44u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x44] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x48u))); /* fld dword ptr [esp + 0x48] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ebx + 0x128u))); /* fadd dword ptr [ebx + 0x128] */
    W32((uint32_t)(c->esp + 0x34u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x34], eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov edx, dword ptr [esp + 0x28] */
    W32((uint32_t)(c->esp + 0x38u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x38], ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    W32((uint32_t)(c->esp + 0x3cu), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x3c], edx */
    W32((uint32_t)(c->esp + 0x58u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x58], edx */
    WF32((uint32_t)(c->esp + 0x48u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x48] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ebx + 0x120u))); /* fadd dword ptr [ebx + 0x120] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x34u)); /* lea ecx, [esp + 0x34] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x40u)); /* lea edx, [esp + 0x40] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    WF32((uint32_t)(c->esp + 0x3cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x3c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x40u))); /* fld dword ptr [esp + 0x40] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ebx + 0x124u))); /* fadd dword ptr [ebx + 0x124] */
    WF32((uint32_t)(c->esp + 0x40u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x40] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x44u))); /* fld dword ptr [esp + 0x44] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ebx + 0x128u))); /* fadd dword ptr [ebx + 0x128] */
    WF32((uint32_t)(c->esp + 0x44u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x44] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x24u)); PUSH32(c, 0x007835a3u); call_indirect(c, t_); } /* call dword ptr [eax + 0x24] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x7902a8u))); FPOP(c); /* fcomp dword ptr [0x100102a8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x41u)); /* test ah, 0x41 */
    if (!PF(c)) goto L_007835c0; /* jnp 0x7835c0 */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x40u)); /* lea eax, [esp + 0x40] */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x007835bcu); f_007820c0(c); /* call 0x7820c0 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_007835ca; /* je 0x7835ca */
L_007835c0:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x8b4u))); /* mov ecx, dword ptr [ebx + 0x8b4] */
    W8((uint32_t)(c->esi + c->ecx), (uint8_t)((uint8_t)0x2u)); /* mov byte ptr [esi + ecx], 2 */
L_007835ca:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0x7902a8u))); /* fadd dword ptr [0x100102a8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebx + 0x138u))); /* mov esi, dword ptr [ebx + 0x138] */
    W32((uint32_t)(c->esp + 0xacu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0xac], 0 */
    W32((uint32_t)(c->esp + 0xa8u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0xa8], esi */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
    FPUSH(c, (double)(int64_t)R64((uint32_t)(c->esp + 0xa8u))); /* fild qword ptr [esp + 0xa8] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->esp + 0x18u))); FPOP(c); /* fcomp dword ptr [esp + 0x18] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (c->zf) goto L_00783324; /* je 0x783324 */
L_00783608:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fld dword ptr [esp + 0x1c] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0x7902a8u))); /* fadd dword ptr [0x100102a8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebx + 0x138u))); /* mov esi, dword ptr [ebx + 0x138] */
    W32((uint32_t)(c->esp + 0xa4u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0xa4], 0 */
    W32((uint32_t)(c->esp + 0xa0u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0xa0], esi */
    WF32((uint32_t)(c->esp + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1c] */
    FPUSH(c, (double)(int64_t)R64((uint32_t)(c->esp + 0xa0u))); /* fild qword ptr [esp + 0xa0] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fld dword ptr [esp + 0x1c] */
    FCOM(c, ST(0), ST(1)); FPOP(c); /* fcomp st(1) */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (!PF(c)) goto L_007832fc; /* jnp 0x7832fc */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov edi, dword ptr [esp + 0x24] */
L_0078364a:;
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, (double)RF32((uint32_t)(c->edi))); /* fld dword ptr [edi] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x7902b0u))); /* fmul dword ptr [0x100102b0] */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    WF32((uint32_t)(c->edi), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi] */
    FPUSH(c, (double)RF32((uint32_t)(c->edi + 0x4u))); /* fld dword ptr [edi + 4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x7902b0u))); /* fmul dword ptr [0x100102b0] */
    WF32((uint32_t)(c->edi + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->edi + 0x8u))); /* fld dword ptr [edi + 8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x7902b0u))); /* fmul dword ptr [0x100102b0] */
    WF32((uint32_t)(c->edi + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->ebx + 0x12cu))); /* fld dword ptr [ebx + 0x12c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x7902b0u))); /* fmul dword ptr [0x100102b0] */
    WF32((uint32_t)(c->ebx + 0x12cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebx + 0x12c] */
    FPUSH(c, (double)RF32((uint32_t)(c->ebx + 0x130u))); /* fld dword ptr [ebx + 0x130] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x7902b0u))); /* fmul dword ptr [0x100102b0] */
    WF32((uint32_t)(c->ebx + 0x130u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebx + 0x130] */
    FPUSH(c, (double)RF32((uint32_t)(c->ebx + 0x134u))); /* fld dword ptr [ebx + 0x134] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x7902b0u))); /* fmul dword ptr [0x100102b0] */
    WF32((uint32_t)(c->ebx + 0x134u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebx + 0x134] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x138u))); /* mov eax, dword ptr [ebx + 0x138] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x8b4u))); /* mov edx, dword ptr [ebx + 0x8b4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0xb8u)); /* lea eax, [esp + 0xb8] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x007836c2u); f_00783a10(c); /* call 0x783a10 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x138u))); /* mov ecx, dword ptr [ebx + 0x138] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x8b4u))); /* mov edx, dword ptr [ebx + 0x8b4] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)((uint32_t)(c->ebx + 0x894u)); /* lea ecx, [ebx + 0x894] */
    PUSH32(c, 0x007836dbu); f_00785f10(c); /* call 0x785f10 */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x10u)); /* sub esp, 0x10 */
    c->ecx = (uint32_t)(c->esp); /* mov ecx, esp */
    W32((uint32_t)(c->esp + 0x38u), (uint32_t)(c->esp)); /* mov dword ptr [esp + 0x38], esp */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = 0x7921e8u; PUSH32(c, v_); } /* push 0x100121e8 */
    PUSH32(c, 0x007836f0u); f_007855a0(c); /* call 0x7855a0 */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0xc0u)); /* lea eax, [esp + 0xc0] */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x88u)); /* lea ecx, [esp + 0x88] */
    W8((uint32_t)(c->esp + 0x85d4u), (uint8_t)((uint8_t)0xbu)); /* mov byte ptr [esp + 0x85d4], 0xb */
    PUSH32(c, 0x0078370eu); f_007855a0(c); /* call 0x7855a0 */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x10u)); /* sub esp, 0x10 */
    W8((uint32_t)(c->esp + 0x85dcu), (uint8_t)((uint8_t)0xcu)); /* mov byte ptr [esp + 0x85dc], 0xc */
    c->ecx = (uint32_t)(c->esp); /* mov ecx, esp */
    W32((uint32_t)(c->esp + 0x30u), (uint32_t)(c->esp)); /* mov dword ptr [esp + 0x30], esp */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00783727u); f_00785630(c); /* call 0x785630 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x70u)); /* lea ecx, [esp + 0x70] */
    W8((uint32_t)(c->esp + 0x85dcu), (uint8_t)((uint8_t)0xdu)); /* mov byte ptr [esp + 0x85dc], 0xd */
    PUSH32(c, 0x00783738u); f_007852f0(c); /* call 0x7852f0 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x10u)); /* sub esp, 0x10 */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(c->esp); /* mov eax, esp */
    W8((uint32_t)(c->esp + 0x85ccu), (uint8_t)((uint8_t)0xeu)); /* mov byte ptr [esp + 0x85cc], 0xe */
    W32((uint32_t)(c->esp + 0x38u), (uint32_t)(c->esp)); /* mov dword ptr [esp + 0x38], esp */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x20], eax */
    W32((uint32_t)(c->eax), (uint32_t)(c->edx)); /* mov dword ptr [eax], edx */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 4], edx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 8], edx */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)((uint32_t)0x10u)); /* mov dword ptr [eax + 0xc], 0x10 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if (c->zf) goto L_007837ab; /* je 0x7837ab */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 4], ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_007837ab; /* je 0x7837ab */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov edi, dword ptr [esp + 0x20] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    PUSH32(c, 0x0078377du); f_00785180(c); /* call 0x785180 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov ecx, dword ptr [edi + 4] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi))); /* mov esi, dword ptr [esi] */
    c->edi = (uint32_t)(R32((uint32_t)(c->edi))); /* mov edi, dword ptr [edi] */
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov eax, dword ptr [esp + 0x20] */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u))); /* and ecx, 3 */
    while (c->ecx) { W8(c->edi, R8(c->esi)); c->esi += (c->df ? -1 : 1); c->edi += (c->df ? -1 : 1); c->ecx--; } /* rep movsb byte ptr es:[edi], byte ptr [esi] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov edi, dword ptr [esp + 0x34] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_007837ab; /* je 0x7837ab */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov ecx, dword ptr [esp + 0x20] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ecx, dword ptr [ecx + 4] */
    W8((uint32_t)(c->ecx + c->eax), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [ecx + eax], 0 */
L_007837ab:;
    c->ecx = (uint32_t)((uint32_t)(c->ebx + 0x894u)); /* lea ecx, [ebx + 0x894] */
    PUSH32(c, 0x007837b6u); f_00786310(c); /* call 0x786310 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x50u))); /* mov eax, dword ptr [esp + 0x50] */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    W8((uint32_t)(c->esp + 0x85bcu), (uint8_t)((uint8_t)0xdu)); /* mov byte ptr [esp + 0x85bc], 0xd */
    if (c->zf) goto L_007837d1; /* je 0x7837d1 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x007837ceu); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_007837d1:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x70u))); /* mov eax, dword ptr [esp + 0x70] */
    W32((uint32_t)(c->esp + 0x50u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x50], esi */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    W32((uint32_t)(c->esp + 0x54u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x54], esi */
    W32((uint32_t)(c->esp + 0x58u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x58], esi */
    W8((uint32_t)(c->esp + 0x85bcu), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esp + 0x85bc], 0 */
    if (c->zf) goto L_007837f6; /* je 0x7837f6 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x007837f3u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_007837f6:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x8b4u))); /* mov eax, dword ptr [ebx + 0x8b4] */
    W32((uint32_t)(c->esp + 0x70u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x70], esi */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    W32((uint32_t)(c->esp + 0x74u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x74], esi */
    W32((uint32_t)(c->esp + 0x78u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x78], esi */
    if (c->zf) goto L_00783815; /* je 0x783815 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00783812u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00783815:;
    W32((uint32_t)(c->ebx + 0x8b4u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ebx + 0x8b4], 0 */
    c->ecx = (uint32_t)(R32((uint32_t)(0x795680u))); /* mov ecx, dword ptr [0x10015680] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x1b0u)); /* lea eax, [esp + 0x1b0] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x58u)); PUSH32(c, 0x00783832u); call_indirect(c, t_); } /* call dword ptr [edx + 0x58] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_0078387a; /* jne 0x78387a */
    c->ecx = (uint32_t)(R32((uint32_t)(0x795680u))); /* mov ecx, dword ptr [0x10015680] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x1b4u)); /* lea eax, [esp + 0x1b4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x64u)); PUSH32(c, 0x0078384cu); call_indirect(c, t_); } /* call dword ptr [edx + 0x64] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(!c->zf ? 1 : 0); /* setne al */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_0078387a; /* jne 0x78387a */
    c->eax = (uint32_t)(R32((uint32_t)(0x795678u))); /* mov eax, dword ptr [0x10015678] */
    { uint32_t v_ = 0x79234cu; PUSH32(c, v_); } /* push 0x1001234c */
    { uint32_t v_ = 0x292u; PUSH32(c, v_); } /* push 0x292 */
    { uint32_t v_ = 0x792048u; PUSH32(c, v_); } /* push 0x10012048 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x7920b0u; PUSH32(c, v_); } /* push 0x100120b0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00783876u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00783879u, "int3"); /* int3  */
L_0078387a:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0xb0u)); /* lea eax, [esp + 0xb0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x79220cu; PUSH32(c, v_); } /* push 0x1001220c */
    { uint32_t v_ = 0x79232cu; PUSH32(c, v_); } /* push 0x1001232c */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x00783893u); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->ebx + 0x128u))); /* fld dword ptr [ebx + 0x128] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x3c8u)); /* lea ecx, [esp + 0x3c8] */
    WF64((uint32_t)(c->esp + 0x10u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x10] */
    FPUSH(c, (double)RF32((uint32_t)(c->ebx + 0x124u))); /* fld dword ptr [ebx + 0x124] */
    WF64((uint32_t)(c->esp + 0x8u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->ebx + 0x120u))); /* fld dword ptr [ebx + 0x120] */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    { uint32_t v_ = 0x792320u; PUSH32(c, v_); } /* push 0x10012320 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x007838c5u); f_00786b1c(c); /* call 0x786b1c */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x3b0u)); /* lea eax, [esp + 0x3b0] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x792334u; PUSH32(c, v_); } /* push 0x10012334 */
    { uint32_t v_ = 0x79232cu; PUSH32(c, v_); } /* push 0x1001232c */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x007838e1u); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->ebx + 0x11cu))); /* fld dword ptr [ebx + 0x11c] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x3c8u)); /* lea ecx, [esp + 0x3c8] */
    WF64((uint32_t)(c->esp + 0x10u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x10] */
    FPUSH(c, (double)RF32((uint32_t)(c->ebx + 0x118u))); /* fld dword ptr [ebx + 0x118] */
    WF64((uint32_t)(c->esp + 0x8u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->edi))); /* fld dword ptr [edi] */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    { uint32_t v_ = 0x792320u; PUSH32(c, v_); } /* push 0x10012320 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x0078390fu); f_00786b1c(c); /* call 0x786b1c */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x3b0u)); /* lea eax, [esp + 0x3b0] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x792314u; PUSH32(c, v_); } /* push 0x10012314 */
    { uint32_t v_ = 0x79232cu; PUSH32(c, v_); } /* push 0x1001232c */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x0078392bu); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx)); PUSH32(c, 0x00783933u); call_indirect(c, t_); } /* call dword ptr [edx] */
L_00783933:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x60u))); /* mov eax, dword ptr [esp + 0x60] */
    W32((uint32_t)(c->esp + 0x85bcu), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [esp + 0x85bc], 0xffffffff */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0078394f; /* je 0x78394f */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0078394cu); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_0078394f:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x85b4u))); /* mov ecx, dword ptr [esp + 0x85b4] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 12; return; /* ret 8 */
}

void f_00783970(CPU *c) { /* FUN_10003970 */
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

void f_00783990(CPU *c) { /* FUN_10003990 */
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

void f_007839b0(CPU *c) { /* FUN_100039b0 */
    PREEMPT_POLL(c);
    FPUSH(c, (double)RF32((uint32_t)(c->edx + 0x8u))); /* fld dword ptr [edx + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + 0x4u))); /* fld dword ptr [edx + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->edx))); /* fld dword ptr [edx] */
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
    FCOM(c, ST(0), RF64((uint32_t)(0x7902c8u))); /* fcom qword ptr [0x100102c8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x44u)); /* test ah, 0x44 */
    if (PF(c)) goto L_007839ea; /* jp 0x7839ea */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 4], eax */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 8], eax */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    c->esp += 4; return; /* ret  */
L_007839ea:;
    ST(0) = FPRES(c, sqrt(ST(0))); /* fsqrt  */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    ST(0) = FPRES(c, FDIV(c, RF64((uint32_t)(0x7902c0u)), ST(0))); /* fdivr qword ptr [0x100102c0] */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + 0x8u))); /* fld dword ptr [edx + 8] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + 0x4u))); /* fld dword ptr [edx + 4] */
    ST(0) = FPRES(c, ST(0) * ST(2)); /* fmul st(2) */
    FPUSH(c, (double)RF32((uint32_t)(c->edx))); /* fld dword ptr [edx] */
    ST(0) = FPRES(c, ST(0) * ST(3)); /* fmul st(3) */
    WF32((uint32_t)(c->ecx), (float)ST(0)); FPOP(c); /* fstp dword ptr [ecx] */
    WF32((uint32_t)(c->ecx + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ecx + 4] */
    WF32((uint32_t)(c->ecx + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ecx + 8] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    c->esp += 4; return; /* ret  */
}

void f_00783a10(CPU *c) { /* FUN_10003a10 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x14u)); /* sub esp, 0x14 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (uint32_t)(R32((uint32_t)(0x795680u))); /* mov ecx, dword ptr [0x10015680] */
    W32((uint32_t)(c->esp), (uint32_t)(c->eax)); /* mov dword ptr [esp], eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov ebx, dword ptr [esp + 0x28] */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 8], eax */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0xc], eax */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov ebp, dword ptr [esp + 0x20] */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov edi, dword ptr [esp + 0x30] */
    W16((uint32_t)(c->esp + 0x20u), (uint16_t)(((uint16_t)c->eax))); /* mov word ptr [esp + 0x20], ax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x8u); /* mov al, 8 */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    W8((uint32_t)(c->esp + 0x16u), (uint8_t)((uint8_t)0x3u)); /* mov byte ptr [esp + 0x16], 3 */
    W16((uint32_t)(c->esp + 0x20u), (uint16_t)(((uint16_t)c->edi))); /* mov word ptr [esp + 0x20], di */
    W16((uint32_t)(c->esp + 0x22u), (uint16_t)(((uint16_t)c->ebx))); /* mov word ptr [esp + 0x22], bx */
    W8((uint32_t)(c->esp + 0x24u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [esp + 0x24], al */
    W8((uint32_t)(c->esp + 0x25u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [esp + 0x25], al */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x40000000u; PUSH32(c, v_); } /* push 0x40000000 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x4u)); PUSH32(c, 0x00783a68u); call_indirect(c, t_); } /* call dword ptr [edx + 4] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (!c->zf) goto L_00783a8f; /* jne 0x783a8f */
    c->eax = (uint32_t)(R32((uint32_t)(0x79567cu))); /* mov eax, dword ptr [0x1001567c] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = 0x792374u; PUSH32(c, v_); } /* push 0x10012374 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x00783a80u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esp += 20; return; /* ret 0x10 */
L_00783a8f:;
    c->edx = (uint32_t)(R32((uint32_t)(0x79567cu))); /* mov edx, dword ptr [0x1001567c] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x12u; PUSH32(c, v_); } /* push 0x12 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov ecx, dword ptr [edx + 4] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x18u)); /* lea edx, [esp + 0x18] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x00783aa7u); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    { int64_t r_ = (int64_t)(int32_t)c->edi * (int32_t)c->ebx; c->edi = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul edi, ebx */
    c->ecx = (uint32_t)(R32((uint32_t)(0x795680u))); /* mov ecx, dword ptr [0x10015680] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov edx, dword ptr [esp + 0x2c] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x00783abeu); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x795680u))); /* mov ecx, dword ptr [0x10015680] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x00783acau); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esp += 20; return; /* ret 0x10 */
}

void f_00783ae0(CPU *c) { /* FUN_10003ae0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x78fae1u; PUSH32(c, v_); } /* push 0x1000fae1 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xb0u)); /* sub esp, 0xb0 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    W32((uint32_t)(c->esp + 0x44u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x44], eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->esp + 0x50u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x50], eax */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    c->eax = (uint32_t)((uint32_t)0x10u); /* mov eax, 0x10 */
    c->ebp = (uint32_t)(c->ecx); /* mov ebp, ecx */
    W32((uint32_t)(c->esp + 0x54u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x54], edi */
    W32((uint32_t)(c->esp + 0x58u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x58], edi */
    W32((uint32_t)(c->esp + 0x5cu), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x5c], edi */
    W32((uint32_t)(c->esp + 0x60u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x60], edi */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x14], edi */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x18], edi */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x1c], edi */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x20], eax */
    W32((uint32_t)(c->esp + 0xc8u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0xc8], edi */
    W32((uint32_t)(c->esp + 0x84u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x84], edi */
    W32((uint32_t)(c->esp + 0x88u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x88], edi */
    W32((uint32_t)(c->esp + 0x8cu), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x8c], edi */
    W32((uint32_t)(c->esp + 0x90u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x90], eax */
    W32((uint32_t)(c->esp + 0x98u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x98], edi */
    W32((uint32_t)(c->esp + 0x9cu), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x9c], edi */
    W32((uint32_t)(c->esp + 0xa0u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0xa0], edi */
    W32((uint32_t)(c->esp + 0xa4u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0xa4], eax */
    W8((uint32_t)(c->esp + 0xc8u), (uint8_t)((uint8_t)0x2u)); /* mov byte ptr [esp + 0xc8], 2 */
    PUSH32(c, 0x00783b7eu); f_007814c0(c); /* call 0x7814c0 */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0xd0u))); /* mov esi, dword ptr [esp + 0xd0] */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0x60u)); /* lea ecx, [ebp + 0x60] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00783b8eu); f_007851f0(c); /* call 0x7851f0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xd4u))); /* mov ecx, dword ptr [esp + 0xd4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x1cu)); /* lea edx, [esp + 0x1c] */
    { uint32_t v_ = 0x792410u; PUSH32(c, v_); } /* push 0x10012410 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00783ba6u); f_00785470(c); /* call 0x785470 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov ecx, dword ptr [esp + 0x28] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, c->ecx, c->edi); /* cmp ecx, edi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ecx, dword ptr [esp + 0x14] */
    if ((c->cf || c->zf)) goto L_00783bea; /* jbe 0x783bea */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)((uint8_t)0x5cu); /* mov bl, 0x5c */
L_00783bbb:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + c->ecx))); /* mov dl, byte ptr [eax + ecx] */
    W8((uint32_t)(c->esi + c->ecx), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi + ecx], dl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ecx, dword ptr [esp + 0x14] */
    (void)sub8(c, R8((uint32_t)(c->eax + c->ecx)), ((uint8_t)c->ebx)); /* cmp byte ptr [eax + ecx], bl */
    if (!c->zf) goto L_00783be0; /* jne 0x783be0 */
    (void)sub8(c, R8((uint32_t)(c->eax + c->ecx + 0x1u)), ((uint8_t)c->ebx)); /* cmp byte ptr [eax + ecx + 1], bl */
    if (!c->zf) goto L_00783be0; /* jne 0x783be0 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov edx, dword ptr [esp + 0x18] */
    c->edx = (uint32_t)(dec32(c, c->edx)); /* dec edx */
L_00783bd5:;
    (void)sub32(c, c->eax, c->edx); /* cmp eax, edx */
    if (!c->cf) goto L_00783be0; /* jae 0x783be0 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub8(c, R8((uint32_t)(c->eax + c->ecx + 0x1u)), ((uint8_t)c->ebx)); /* cmp byte ptr [eax + ecx + 1], bl */
    if (c->zf) goto L_00783bd5; /* je 0x783bd5 */
L_00783be0:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov edx, dword ptr [esp + 0x18] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub32(c, c->eax, c->edx); /* cmp eax, edx */
    if (c->cf) goto L_00783bbb; /* jb 0x783bbb */
L_00783bea:;
    (void)sub32(c, c->ecx, c->edi); /* cmp ecx, edi */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x18], esi */
    if (c->zf) goto L_00783bf6; /* je 0x783bf6 */
    W8((uint32_t)(c->esi + c->ecx), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esi + ecx], 0 */
L_00783bf6:;
    c->ecx = (uint32_t)(R32((uint32_t)(0x79567cu))); /* mov ecx, dword ptr [0x1001567c] */
    c->ebx = (uint32_t)((uint32_t)(c->ebp + 0x140u)); /* lea ebx, [ebp + 0x140] */
    { uint32_t v_ = 0x792408u; PUSH32(c, v_); } /* push 0x10012408 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x5cu)); PUSH32(c, 0x00783c0du); call_indirect(c, t_); } /* call dword ptr [eax + 0x5c] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov esi, dword ptr [ebp + 0x1c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->cf || c->zf)) goto L_00783c46; /* jbe 0x783c46 */
L_00783c17:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + c->edi * 4))); /* mov eax, dword ptr [ecx + edi*4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x00783c28u); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x7921fcu; PUSH32(c, v_); } /* push 0x100121fc */
    PUSH32(c, 0x00783c33u); f_0078f5f0(c); /* call 0x78f5f0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00783cdc; /* je 0x783cdc */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_00783c17; /* jb 0x783c17 */
L_00783c46:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
L_00783c48:;
    c->eax = (uint32_t)(R32((uint32_t)(0x79567cu))); /* mov eax, dword ptr [0x1001567c] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x5017u; PUSH32(c, v_); } /* push 0x5017 */
    { uint32_t v_ = 0x792404u; PUSH32(c, v_); } /* push 0x10012404 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->esi = (uint32_t)(c->ebx); /* mov esi, ebx */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x98u)); PUSH32(c, 0x00783c6fu); call_indirect(c, t_); } /* call dword ptr [edx + 0x98] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x3cu))); /* mov ecx, dword ptr [esp + 0x3c] */
    c->eax = (uint32_t)(R32((uint32_t)(0x79567cu))); /* mov eax, dword ptr [0x1001567c] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x28u)); /* add esp, 0x28 */
    c->esi = (uint32_t)(c->ebx); /* mov esi, ebx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x5014u; PUSH32(c, v_); } /* push 0x5014 */
    { uint32_t v_ = 0x792404u; PUSH32(c, v_); } /* push 0x10012404 */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x98u)); PUSH32(c, 0x00783c9du); call_indirect(c, t_); } /* call dword ptr [edx + 0x98] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x79567cu))); /* mov ecx, dword ptr [0x1001567c] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x28u)); /* add esp, 0x28 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x64u)); PUSH32(c, 0x00783cacu); call_indirect(c, t_); } /* call dword ptr [edx + 0x64] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0x7923fcu; PUSH32(c, v_); } /* push 0x100123fc */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x38u)); PUSH32(c, 0x00783cb8u); call_indirect(c, t_); } /* call dword ptr [edx + 0x38] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00783cea; /* je 0x783cea */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0xa8u)); /* lea ecx, [esp + 0xa8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x00783ccbu); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0x158u)); /* lea edi, [ebp + 0x158] */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    goto L_00783d05; /* jmp 0x783d05 */
L_00783cdc:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + c->edi * 4))); /* mov edx, dword ptr [ecx + edi*4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0xcu))); /* mov ecx, dword ptr [edx + 0xc] */
    goto L_00783c48; /* jmp 0x783c48 */
L_00783cea:;
    c->eax = (uint32_t)(R32((uint32_t)(0x79567cu))); /* mov eax, dword ptr [0x1001567c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xd0u))); /* mov ecx, dword ptr [esp + 0xd0] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x7923d0u; PUSH32(c, v_); } /* push 0x100123d0 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x30u)); PUSH32(c, 0x00783d02u); call_indirect(c, t_); } /* call dword ptr [edx + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_00783d05:;
    c->eax = (uint32_t)(R32((uint32_t)(0x79567cu))); /* mov eax, dword ptr [0x1001567c] */
    { uint32_t v_ = 0xau; PUSH32(c, v_); } /* push 0xa */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->esi = (uint32_t)(c->ebx); /* mov esi, ebx */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    { uint32_t v_ = 0x7920f8u; PUSH32(c, v_); } /* push 0x100120f8 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xb0u)); PUSH32(c, 0x00783d29u); call_indirect(c, t_); } /* call dword ptr [edx + 0xb0] */
    c->eax = (uint32_t)(R32((uint32_t)(0x79567cu))); /* mov eax, dword ptr [0x1001567c] */
    { uint32_t v_ = 0xau; PUSH32(c, v_); } /* push 0xa */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->esi = (uint32_t)((uint32_t)(c->ebp + 0x158u)); /* lea esi, [ebp + 0x158] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    { uint32_t v_ = 0x7920f8u; PUSH32(c, v_); } /* push 0x100120f8 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xb0u)); PUSH32(c, 0x00783d51u); call_indirect(c, t_); } /* call dword ptr [edx + 0xb0] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x79567cu))); /* mov ecx, dword ptr [0x1001567c] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x50u)); /* lea edx, [esp + 0x50] */
    { uint32_t v_ = 0x7923c8u; PUSH32(c, v_); } /* push 0x100123c8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x44u)); PUSH32(c, 0x00783d68u); call_indirect(c, t_); } /* call dword ptr [eax + 0x44] */
    c->eax = (uint32_t)(R32((uint32_t)(0x79567cu))); /* mov eax, dword ptr [0x1001567c] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->esi = (uint32_t)(c->ebx); /* mov esi, ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0xe8u))); /* mov ebx, dword ptr [esp + 0xe8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x7923bcu; PUSH32(c, v_); } /* push 0x100123bc */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    { uint32_t v_ = 0x7923b8u; PUSH32(c, v_); } /* push 0x100123b8 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->esi = (uint32_t)((uint32_t)(c->esp + 0x88u)); /* lea esi, [esp + 0x88] */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x98u)); PUSH32(c, 0x00783da9u); call_indirect(c, t_); } /* call dword ptr [edx + 0x98] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x30u)); /* add esp, 0x30 */
    c->ecx = (uint32_t)(c->esp); /* mov ecx, esp */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->esp)); /* mov dword ptr [esp + 0x20], esp */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = 0x7923b0u; PUSH32(c, v_); } /* push 0x100123b0 */
    PUSH32(c, 0x00783dbeu); f_007855a0(c); /* call 0x7855a0 */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x7cu)); /* lea ecx, [esp + 0x7c] */
    W8((uint32_t)(c->esp + 0xe0u), (uint8_t)((uint8_t)0x3u)); /* mov byte ptr [esp + 0xe0], 3 */
    PUSH32(c, 0x00783dd2u); f_007855a0(c); /* call 0x7855a0 */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x10u)); /* sub esp, 0x10 */
    W8((uint32_t)(c->esp + 0xe8u), (uint8_t)((uint8_t)0x4u)); /* mov byte ptr [esp + 0xe8], 4 */
    c->ecx = (uint32_t)(c->esp); /* mov ecx, esp */
    W32((uint32_t)(c->esp + 0xb4u), (uint32_t)(c->esp)); /* mov dword ptr [esp + 0xb4], esp */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00783deeu); f_00785630(c); /* call 0x785630 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x94u)); /* lea ecx, [esp + 0x94] */
    W8((uint32_t)(c->esp + 0xe8u), (uint8_t)((uint8_t)0x5u)); /* mov byte ptr [esp + 0xe8], 5 */
    PUSH32(c, 0x00783e02u); f_007852f0(c); /* call 0x7852f0 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->esp + 0x30u), (uint32_t)((uint32_t)0x10u)); /* mov dword ptr [esp + 0x30], 0x10 */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x24], ebx */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x28], ebx */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x2c], ebx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    (void)sub32(c, c->ecx, c->ebx); /* cmp ecx, ebx */
    W8((uint32_t)(c->esp + 0xc8u), (uint8_t)((uint8_t)0x6u)); /* mov byte ptr [esp + 0xc8], 6 */
    if (c->zf) goto L_00783e31; /* je 0x783e31 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x28u)); /* lea ecx, [esp + 0x28] */
    PUSH32(c, 0x00783e31u); f_00785280(c); /* call 0x785280 */
L_00783e31:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x74u))); /* mov eax, dword ptr [esp + 0x74] */
    W8((uint32_t)(c->esp + 0xc8u), (uint8_t)((uint8_t)0x9u)); /* mov byte ptr [esp + 0xc8], 9 */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_00783e4a; /* je 0x783e4a */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00783e47u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00783e4a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x64u))); /* mov eax, dword ptr [esp + 0x64] */
    W32((uint32_t)(c->esp + 0x74u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x74], ebx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    W32((uint32_t)(c->esp + 0x78u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x78], ebx */
    W32((uint32_t)(c->esp + 0x7cu), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x7c], ebx */
    W8((uint32_t)(c->esp + 0xc8u), (uint8_t)((uint8_t)0x8u)); /* mov byte ptr [esp + 0xc8], 8 */
    if (c->zf) goto L_00783e6f; /* je 0x783e6f */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00783e6cu); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00783e6f:;
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->esi = (uint32_t)((uint32_t)(c->ebp + 0x158u)); /* lea esi, [ebp + 0x158] */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    c->eax = (uint32_t)(R32((uint32_t)(0x79567cu))); /* mov eax, dword ptr [0x1001567c] */
    W32((uint32_t)(c->esp + 0x7cu), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x7c], ebx */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x3cu))); /* mov ecx, dword ptr [esp + 0x3c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x7923bcu; PUSH32(c, v_); } /* push 0x100123bc */
    { uint32_t v_ = 0x7923b8u; PUSH32(c, v_); } /* push 0x100123b8 */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->esi = (uint32_t)((uint32_t)(c->esp + 0x88u)); /* lea esi, [esp + 0x88] */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    W32((uint32_t)(c->esp + 0xa4u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0xa4], ebx */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(c->esp + 0xacu), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0xac], ebx */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x98u)); PUSH32(c, 0x00783ec3u); call_indirect(c, t_); } /* call dword ptr [edx + 0x98] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xc8u))); /* mov eax, dword ptr [ebp + 0xc8] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x40u)); /* add esp, 0x40 */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x10], ebx */
    if ((c->cf || c->zf)) goto L_00783fbd; /* jbe 0x783fbd */
    c->ebx = (uint32_t)((uint32_t)(c->ebp + 0x74u)); /* lea ebx, [ebp + 0x74] */
L_00783edb:;
    c->ecx = (uint32_t)(R32((uint32_t)(0x79567cu))); /* mov ecx, dword ptr [0x1001567c] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    W32((uint32_t)(c->esp + 0x34u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x34], edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W32((uint32_t)(c->esp + 0x38u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x38], edx */
    W32((uint32_t)(c->esp + 0x3cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x3c], eax */
    W32((uint32_t)(c->esp + 0x40u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x40], eax */
    W32((uint32_t)(c->esp + 0x44u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x44], eax */
    W32((uint32_t)(c->esp + 0x48u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x48], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x34u)); /* lea edx, [esp + 0x34] */
    { uint32_t v_ = 0x792408u; PUSH32(c, v_); } /* push 0x10012408 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x5cu)); PUSH32(c, 0x00783f0cu); call_indirect(c, t_); } /* call dword ptr [eax + 0x5c] */
    c->eax = (uint32_t)(R32((uint32_t)(0x79567cu))); /* mov eax, dword ptr [0x1001567c] */
    { uint32_t v_ = 0x7923a8u; PUSH32(c, v_); } /* push 0x100123a8 */
    { uint32_t v_ = 0x5014u; PUSH32(c, v_); } /* push 0x5014 */
    { uint32_t v_ = 0x792404u; PUSH32(c, v_); } /* push 0x10012404 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->esi = (uint32_t)((uint32_t)(c->esp + 0x58u)); /* lea esi, [esp + 0x58] */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x98u)); PUSH32(c, 0x00783f39u); call_indirect(c, t_); } /* call dword ptr [edx + 0x98] */
    c->eax = (uint32_t)(R32((uint32_t)(0x79567cu))); /* mov eax, dword ptr [0x1001567c] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x28u)); /* add esp, 0x28 */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->esi = (uint32_t)((uint32_t)(c->esp + 0x34u)); /* lea esi, [esp + 0x34] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0x2710u; PUSH32(c, v_); } /* push 0x2710 */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t v_ = 0x79239cu; PUSH32(c, v_); } /* push 0x1001239c */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xb0u)); PUSH32(c, 0x00783f65u); call_indirect(c, t_); } /* call dword ptr [edx + 0xb0] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x7cu))); /* mov eax, dword ptr [ebp + 0x7c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov edx, dword ptr [ebx] */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->esi = (uint32_t)((uint32_t)(c->esp + 0x34u)); /* lea esi, [esp + 0x34] */
    c->edi = (uint32_t)((uint32_t)(c->esp + 0xa8u)); /* lea edi, [esp + 0xa8] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x00783f83u); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x7cu))); /* mov eax, dword ptr [ebp + 0x7c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x78u))); /* mov ecx, dword ptr [ebp + 0x78] */
    c->esi = (uint32_t)((uint32_t)(c->esp + 0xa8u)); /* lea esi, [esp + 0xa8] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea eax, [eax + eax*2] */
    c->edi = (uint32_t)((uint32_t)(c->ecx + c->eax * 8)); /* lea edi, [ecx + eax*8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov esi, dword ptr [ebx + 8] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebx + 8], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xc8u))); /* mov ecx, dword ptr [ebp + 0xc8] */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    if (c->cf) goto L_00783edb; /* jb 0x783edb */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
L_00783fbd:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov eax, dword ptr [esp + 0x24] */
    W8((uint32_t)(c->esp + 0xc8u), (uint8_t)((uint8_t)0x2u)); /* mov byte ptr [esp + 0xc8], 2 */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_00783fd6; /* je 0x783fd6 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00783fd3u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00783fd6:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x24], ebx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x28], ebx */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x2c], ebx */
    W32((uint32_t)(c->esp + 0xc8u), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [esp + 0xc8], 0xffffffff */
    if (c->zf) goto L_00783ffe; /* je 0x783ffe */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00783ffbu); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00783ffe:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xc0u))); /* mov ecx, dword ptr [esp + 0xc0] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xbcu)); /* add esp, 0xbc */
    c->esp += 16; return; /* ret 0xc */
}

void f_00783d51(CPU *c) { /* PTR_00783d51 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(0x79567cu))); /* mov ecx, dword ptr [0x1001567c] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x50u)); /* lea edx, [esp + 0x50] */
    { uint32_t v_ = 0x7923c8u; PUSH32(c, v_); } /* push 0x100123c8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x44u)); PUSH32(c, 0x00783d68u); call_indirect(c, t_); } /* call dword ptr [eax + 0x44] */
    c->eax = (uint32_t)(R32((uint32_t)(0x79567cu))); /* mov eax, dword ptr [0x1001567c] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->esi = (uint32_t)(c->ebx); /* mov esi, ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0xe8u))); /* mov ebx, dword ptr [esp + 0xe8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x7923bcu; PUSH32(c, v_); } /* push 0x100123bc */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    { uint32_t v_ = 0x7923b8u; PUSH32(c, v_); } /* push 0x100123b8 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->esi = (uint32_t)((uint32_t)(c->esp + 0x88u)); /* lea esi, [esp + 0x88] */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x98u)); PUSH32(c, 0x00783da9u); call_indirect(c, t_); } /* call dword ptr [edx + 0x98] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x30u)); /* add esp, 0x30 */
    c->ecx = (uint32_t)(c->esp); /* mov ecx, esp */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->esp)); /* mov dword ptr [esp + 0x20], esp */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = 0x7923b0u; PUSH32(c, v_); } /* push 0x100123b0 */
    PUSH32(c, 0x00783dbeu); f_007855a0(c); /* call 0x7855a0 */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x7cu)); /* lea ecx, [esp + 0x7c] */
    W8((uint32_t)(c->esp + 0xe0u), (uint8_t)((uint8_t)0x3u)); /* mov byte ptr [esp + 0xe0], 3 */
    PUSH32(c, 0x00783dd2u); f_007855a0(c); /* call 0x7855a0 */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x10u)); /* sub esp, 0x10 */
    W8((uint32_t)(c->esp + 0xe8u), (uint8_t)((uint8_t)0x4u)); /* mov byte ptr [esp + 0xe8], 4 */
    c->ecx = (uint32_t)(c->esp); /* mov ecx, esp */
    W32((uint32_t)(c->esp + 0xb4u), (uint32_t)(c->esp)); /* mov dword ptr [esp + 0xb4], esp */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00783deeu); f_00785630(c); /* call 0x785630 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x94u)); /* lea ecx, [esp + 0x94] */
    W8((uint32_t)(c->esp + 0xe8u), (uint8_t)((uint8_t)0x5u)); /* mov byte ptr [esp + 0xe8], 5 */
    PUSH32(c, 0x00783e02u); f_007852f0(c); /* call 0x7852f0 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->esp + 0x30u), (uint32_t)((uint32_t)0x10u)); /* mov dword ptr [esp + 0x30], 0x10 */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x24], ebx */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x28], ebx */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x2c], ebx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    (void)sub32(c, c->ecx, c->ebx); /* cmp ecx, ebx */
    W8((uint32_t)(c->esp + 0xc8u), (uint8_t)((uint8_t)0x6u)); /* mov byte ptr [esp + 0xc8], 6 */
    if (c->zf) goto L_00783e31; /* je 0x783e31 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x28u)); /* lea ecx, [esp + 0x28] */
    PUSH32(c, 0x00783e31u); f_00785280(c); /* call 0x785280 */
L_00783e31:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x74u))); /* mov eax, dword ptr [esp + 0x74] */
    W8((uint32_t)(c->esp + 0xc8u), (uint8_t)((uint8_t)0x9u)); /* mov byte ptr [esp + 0xc8], 9 */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_00783e4a; /* je 0x783e4a */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00783e47u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00783e4a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x64u))); /* mov eax, dword ptr [esp + 0x64] */
    W32((uint32_t)(c->esp + 0x74u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x74], ebx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    W32((uint32_t)(c->esp + 0x78u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x78], ebx */
    W32((uint32_t)(c->esp + 0x7cu), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x7c], ebx */
    W8((uint32_t)(c->esp + 0xc8u), (uint8_t)((uint8_t)0x8u)); /* mov byte ptr [esp + 0xc8], 8 */
    if (c->zf) goto L_00783e6f; /* je 0x783e6f */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00783e6cu); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00783e6f:;
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->esi = (uint32_t)((uint32_t)(c->ebp + 0x158u)); /* lea esi, [ebp + 0x158] */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    c->eax = (uint32_t)(R32((uint32_t)(0x79567cu))); /* mov eax, dword ptr [0x1001567c] */
    W32((uint32_t)(c->esp + 0x7cu), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x7c], ebx */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x3cu))); /* mov ecx, dword ptr [esp + 0x3c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x7923bcu; PUSH32(c, v_); } /* push 0x100123bc */
    { uint32_t v_ = 0x7923b8u; PUSH32(c, v_); } /* push 0x100123b8 */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->esi = (uint32_t)((uint32_t)(c->esp + 0x88u)); /* lea esi, [esp + 0x88] */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    W32((uint32_t)(c->esp + 0xa4u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0xa4], ebx */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(c->esp + 0xacu), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0xac], ebx */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x98u)); PUSH32(c, 0x00783ec3u); call_indirect(c, t_); } /* call dword ptr [edx + 0x98] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xc8u))); /* mov eax, dword ptr [ebp + 0xc8] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x40u)); /* add esp, 0x40 */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x10], ebx */
    if ((c->cf || c->zf)) goto L_00783fbd; /* jbe 0x783fbd */
    c->ebx = (uint32_t)((uint32_t)(c->ebp + 0x74u)); /* lea ebx, [ebp + 0x74] */
L_00783edb:;
    c->ecx = (uint32_t)(R32((uint32_t)(0x79567cu))); /* mov ecx, dword ptr [0x1001567c] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    W32((uint32_t)(c->esp + 0x34u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x34], edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W32((uint32_t)(c->esp + 0x38u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x38], edx */
    W32((uint32_t)(c->esp + 0x3cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x3c], eax */
    W32((uint32_t)(c->esp + 0x40u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x40], eax */
    W32((uint32_t)(c->esp + 0x44u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x44], eax */
    W32((uint32_t)(c->esp + 0x48u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x48], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x34u)); /* lea edx, [esp + 0x34] */
    { uint32_t v_ = 0x792408u; PUSH32(c, v_); } /* push 0x10012408 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x5cu)); PUSH32(c, 0x00783f0cu); call_indirect(c, t_); } /* call dword ptr [eax + 0x5c] */
    c->eax = (uint32_t)(R32((uint32_t)(0x79567cu))); /* mov eax, dword ptr [0x1001567c] */
    { uint32_t v_ = 0x7923a8u; PUSH32(c, v_); } /* push 0x100123a8 */
    { uint32_t v_ = 0x5014u; PUSH32(c, v_); } /* push 0x5014 */
    { uint32_t v_ = 0x792404u; PUSH32(c, v_); } /* push 0x10012404 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->esi = (uint32_t)((uint32_t)(c->esp + 0x58u)); /* lea esi, [esp + 0x58] */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x98u)); PUSH32(c, 0x00783f39u); call_indirect(c, t_); } /* call dword ptr [edx + 0x98] */
    c->eax = (uint32_t)(R32((uint32_t)(0x79567cu))); /* mov eax, dword ptr [0x1001567c] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x28u)); /* add esp, 0x28 */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->esi = (uint32_t)((uint32_t)(c->esp + 0x34u)); /* lea esi, [esp + 0x34] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0x2710u; PUSH32(c, v_); } /* push 0x2710 */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t v_ = 0x79239cu; PUSH32(c, v_); } /* push 0x1001239c */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xb0u)); PUSH32(c, 0x00783f65u); call_indirect(c, t_); } /* call dword ptr [edx + 0xb0] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x7cu))); /* mov eax, dword ptr [ebp + 0x7c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov edx, dword ptr [ebx] */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->esi = (uint32_t)((uint32_t)(c->esp + 0x34u)); /* lea esi, [esp + 0x34] */
    c->edi = (uint32_t)((uint32_t)(c->esp + 0xa8u)); /* lea edi, [esp + 0xa8] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x00783f83u); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x7cu))); /* mov eax, dword ptr [ebp + 0x7c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x78u))); /* mov ecx, dword ptr [ebp + 0x78] */
    c->esi = (uint32_t)((uint32_t)(c->esp + 0xa8u)); /* lea esi, [esp + 0xa8] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea eax, [eax + eax*2] */
    c->edi = (uint32_t)((uint32_t)(c->ecx + c->eax * 8)); /* lea edi, [ecx + eax*8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov esi, dword ptr [ebx + 8] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebx + 8], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xc8u))); /* mov ecx, dword ptr [ebp + 0xc8] */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    if (c->cf) goto L_00783edb; /* jb 0x783edb */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
L_00783fbd:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov eax, dword ptr [esp + 0x24] */
    W8((uint32_t)(c->esp + 0xc8u), (uint8_t)((uint8_t)0x2u)); /* mov byte ptr [esp + 0xc8], 2 */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_00783fd6; /* je 0x783fd6 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00783fd3u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00783fd6:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x24], ebx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x28], ebx */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x2c], ebx */
    W32((uint32_t)(c->esp + 0xc8u), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [esp + 0xc8], 0xffffffff */
    if (c->zf) goto L_00783ffe; /* je 0x783ffe */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00783ffbu); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00783ffe:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xc0u))); /* mov ecx, dword ptr [esp + 0xc0] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xbcu)); /* add esp, 0xbc */
    c->esp += 16; return; /* ret 0xc */
}

void f_00784020(CPU *c) { /* PTR_00784020 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov esi, dword ptr [esp + 0x24] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov edi, dword ptr [esp + 0x2c] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x24u)); PUSH32(c, 0x00784034u); call_indirect(c, t_); } /* call dword ptr [eax + 0x24] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x7902a8u))); /* fcom dword ptr [0x100102a8] */
    WF32((uint32_t)(c->esp + 0x2cu), (float)ST(0)); /* fst dword ptr [esp + 0x2c] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x41u)); /* test ah, 0x41 */
    if (PF(c)) goto L_007840bb; /* jp 0x7840bb */
    FPUSH(c, (double)RF32((uint32_t)(c->edi))); /* fld dword ptr [edi] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esi))); /* fsub dword ptr [esi] */
    FPUSH(c, (double)RF32((uint32_t)(c->edi + 0x4u))); /* fld dword ptr [edi + 4] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esi + 0x4u))); /* fsub dword ptr [esi + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->edi + 0x8u))); /* fld dword ptr [edi + 8] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esi + 0x8u))); /* fsub dword ptr [esi + 8] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x3cu))); /* mov edx, dword ptr [esp + 0x3c] */
    c->eax = (uint32_t)(R32((uint32_t)(0x79567cu))); /* mov eax, dword ptr [0x1001567c] */
    WF32((uint32_t)(c->esp + 0x28u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x28] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * ST(2)); /* fmul st(2) */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    WF32((uint32_t)(c->esp + 0x2cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x2c] */
    ST(1) = FPRES(c, ST(1) * ST(0)); FPOP(c); /* fmulp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x28u))); /* fld dword ptr [esp + 0x28] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x44u))); /* fmul dword ptr [esp + 0x44] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x2cu))); /* fld dword ptr [esp + 0x2c] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi))); /* fadd dword ptr [esi] */
    WF32((uint32_t)(c->esp + 0x20u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x20] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x4u))); /* fadd dword ptr [esi + 4] */
    WF32((uint32_t)(c->esp + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x24] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x8u))); /* fadd dword ptr [esi + 8] */
    WF64((uint32_t)(c->esp + 0x10u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x10] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x24u))); /* fld dword ptr [esp + 0x24] */
    WF64((uint32_t)(c->esp + 0x8u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x20u))); /* fld dword ptr [esp + 0x20] */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x792428u; PUSH32(c, v_); } /* push 0x10012428 */
    { uint32_t v_ = 0x792418u; PUSH32(c, v_); } /* push 0x10012418 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0xecu)); PUSH32(c, 0x007840b4u); call_indirect(c, t_); } /* call dword ptr [ecx + 0xec] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x54u))); /* fld dword ptr [esp + 0x54] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x28u)); /* add esp, 0x28 */
L_007840bb:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    c->esp += 16; return; /* ret 0xc */
}

void f_007840d0(CPU *c) { /* FUN_100040d0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov esi, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x8c0u))); /* mov ecx, dword ptr [eax + 0x8c0] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov esi, dword ptr [esp + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8c4u))); /* mov eax, dword ptr [eax + 0x8c4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x20u)); PUSH32(c, 0x007840f3u); call_indirect(c, t_); } /* call dword ptr [edx + 0x20] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 12; return; /* ret 8 */
}

void f_00784100(CPU *c) { /* PTR_00784100 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x6cu)); /* sub esp, 0x6c */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x80u))); /* mov edi, dword ptr [esp + 0x80] */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x84u))); /* mov ecx, dword ptr [esp + 0x84] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x7cu))); /* mov ebp, dword ptr [esp + 0x7c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x2c], esi */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov edx, dword ptr [eax + 4] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 4], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 8], eax */
    c->eax = (uint32_t)((uint32_t)0x3dcccccdu); /* mov eax, 0x3dcccccd */
    W32((uint32_t)(c->edi + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + 4], eax */
    W32((uint32_t)(c->ebp + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 4], eax */
    FPUSH(c, (double)RF32((uint32_t)(c->ebp))); /* fld dword ptr [ebp] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->esi + 0xe8u))); FPOP(c); /* fcomp dword ptr [esi + 0xe8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x41u)); /* test ah, 0x41 */
    if (PF(c)) goto L_0078415a; /* jp 0x78415a */
    FPUSH(c, (double)RF32((uint32_t)(c->edi))); /* fld dword ptr [edi] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->esi + 0xe8u))); FPOP(c); /* fcomp dword ptr [esi + 0xe8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x41u)); /* test ah, 0x41 */
    if (!PF(c)) goto L_007841c1; /* jnp 0x7841c1 */
L_0078415a:;
    FPUSH(c, (double)RF32((uint32_t)(c->ebp))); /* fld dword ptr [ebp] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->esi + 0xf0u))); FPOP(c); /* fcomp dword ptr [esi + 0xf0] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x100u))); /* and eax, 0x100 */
    if (!c->zf) goto L_0078417d; /* jne 0x78417d */
    FPUSH(c, (double)RF32((uint32_t)(c->edi))); /* fld dword ptr [edi] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->esi + 0xf0u))); FPOP(c); /* fcomp dword ptr [esi + 0xf0] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x100u))); /* and eax, 0x100 */
    if (c->zf) goto L_007841c1; /* je 0x7841c1 */
L_0078417d:;
    FPUSH(c, (double)RF32((uint32_t)(c->ebp + 0x8u))); /* fld dword ptr [ebp + 8] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->esi + 0xecu))); FPOP(c); /* fcomp dword ptr [esi + 0xec] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x41u)); /* test ah, 0x41 */
    if (PF(c)) goto L_0078419d; /* jp 0x78419d */
    FPUSH(c, (double)RF32((uint32_t)(c->edi + 0x8u))); /* fld dword ptr [edi + 8] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->esi + 0xecu))); FPOP(c); /* fcomp dword ptr [esi + 0xec] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x41u)); /* test ah, 0x41 */
    if (!PF(c)) goto L_007841c1; /* jnp 0x7841c1 */
L_0078419d:;
    FPUSH(c, (double)RF32((uint32_t)(c->ebp + 0x8u))); /* fld dword ptr [ebp + 8] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->esi + 0xf4u))); FPOP(c); /* fcomp dword ptr [esi + 0xf4] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x100u))); /* and eax, 0x100 */
    if (!c->zf) goto L_007841cc; /* jne 0x7841cc */
    FPUSH(c, (double)RF32((uint32_t)(c->edi + 0x8u))); /* fld dword ptr [edi + 8] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->esi + 0xf4u))); FPOP(c); /* fcomp dword ptr [esi + 0xf4] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x100u))); /* and eax, 0x100 */
    if (!c->zf) goto L_007841cc; /* jne 0x7841cc */
L_007841c1:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x6cu)); /* add esp, 0x6c */
    c->esp += 16; return; /* ret 0xc */
L_007841cc:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x24u)); PUSH32(c, 0x007841d5u); call_indirect(c, t_); } /* call dword ptr [edx + 0x24] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x7902a8u))); FPOP(c); /* fcomp dword ptr [0x100102a8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x100u))); /* and eax, 0x100 */
    if (!c->zf) goto L_007841ef; /* jne 0x7841ef */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x6cu)); /* add esp, 0x6c */
    c->esp += 16; return; /* ret 0xc */
L_007841ef:;
    FPUSH(c, (double)RF32((uint32_t)(c->edi))); /* fld dword ptr [edi] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->ebp))); /* fsub dword ptr [ebp] */
    FPUSH(c, (double)RF32((uint32_t)(c->edi + 0x4u))); /* fld dword ptr [edi + 4] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->ebp + 0x4u))); /* fsub dword ptr [ebp + 4] */
    WF32((uint32_t)(c->esp + 0x58u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x58] */
    FPUSH(c, (double)RF32((uint32_t)(c->edi + 0x8u))); /* fld dword ptr [edi + 8] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->ebp + 0x8u))); /* fsub dword ptr [ebp + 8] */
    WF32((uint32_t)(c->esp + 0x5cu), (float)ST(0)); /* fst dword ptr [esp + 0x5c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x5cu))); /* fmul dword ptr [esp + 0x5c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x58u))); /* fld dword ptr [esp + 0x58] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x58u))); /* fmul dword ptr [esp + 0x58] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    { double v_ = ST(1); FPUSH(c, v_); } /* fld st(1) */
    ST(0) = FPRES(c, ST(0) * ST(2)); /* fmul st(2) */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FCOM(c, ST(0), RF64((uint32_t)(0x7902c8u))); /* fcom qword ptr [0x100102c8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x44u)); /* test ah, 0x44 */
    if (PF(c)) goto L_00784247; /* jp 0x784247 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    W32((uint32_t)(c->esp + 0x48u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x48], 0 */
    W32((uint32_t)(c->esp + 0x4cu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x4c], 0 */
    W32((uint32_t)(c->esp + 0x50u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x50], 0 */
    goto L_00784278; /* jmp 0x784278 */
L_00784247:;
    ST(0) = FPRES(c, sqrt(ST(0))); /* fsqrt  */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x60u)); /* lea ecx, [esp + 0x60] */
    ST(0) = FPRES(c, FDIV(c, RF64((uint32_t)(0x7902c0u)), ST(0))); /* fdivr qword ptr [0x100102c0] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x74u))); /* fld dword ptr [esp + 0x74] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF64((uint32_t)(c->esp + 0x10u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x10] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x70u))); /* fld dword ptr [esp + 0x70] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF64((uint32_t)(c->esp + 0x8u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 8] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    PUSH32(c, 0x00784278u); f_00783990(c); /* call 0x783990 */
L_00784278:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x88u)); /* add esi, 0x88 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00784287u); f_00785bb0(c); /* call 0x785bb0 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x18], ebx */
    PUSH32(c, 0x00784295u); f_00785bb0(c); /* call 0x785bb0 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xcu))); /* mov eax, dword ptr [ebx + 0xc] */
    (void)sub32(c, c->eax, (uint32_t)0x8u); /* cmp eax, 8 */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x18], ecx */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)((uint32_t)0x8u)); /* mov dword ptr [esp + 0x2c], 8 */
    if ((!c->cf && !c->zf)) goto L_007842af; /* ja 0x7842af */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x2c], eax */
L_007842af:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov eax, dword ptr [ecx + 0xc] */
    (void)sub32(c, c->eax, (uint32_t)0x8u); /* cmp eax, 8 */
    if ((c->cf || c->zf)) goto L_007842c2; /* jbe 0x7842c2 */
    c->eax = (uint32_t)((uint32_t)0x8u); /* mov eax, 8 */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x20], eax */
    goto L_007842c6; /* jmp 0x7842c6 */
L_007842c2:;
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x20], eax */
L_007842c6:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->cf || c->zf)) goto L_00784344; /* jbe 0x784344 */
    c->ebp = (uint32_t)(logic32(c, 0)); /* xor ebp, ebp */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x28], eax */
L_007842d0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    { uint32_t v_ = 0x792160u; PUSH32(c, v_); } /* push 0x10012160 */
    { uint32_t v_ = 0x94u; PUSH32(c, v_); } /* push 0x94 */
    c->edx = (uint32_t)((uint32_t)0x79212cu); /* mov edx, 0x1001212c */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ecx, dword ptr [eax + 8] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ecx + c->ebp))); /* mov ebx, dword ptr [ecx + ebp] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x40u))); /* mov ecx, dword ptr [esi + 0x40] */
    (void)sub32(c, c->ebx, c->ecx); /* cmp ebx, ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(c->cf ? 1 : 0); /* setb cl */
    PUSH32(c, 0x007842f6u); f_00784910(c); /* call 0x784910 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x3cu))); /* mov eax, dword ptr [esi + 0x3c] */
    c->edx = (uint32_t)((uint32_t)(c->ebx + c->ebx * 4)); /* lea edx, [ebx + ebx*4] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->edx * 8)); /* lea ecx, [eax + edx*8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + c->edx * 8))); /* mov edx, dword ptr [eax + edx*8] */
    W32((uint32_t)(c->esp + 0x64u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x64], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov edx, dword ptr [esp + 0x18] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov eax, dword ptr [ecx + 4] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov ebx, dword ptr [edx + 8] */
    W32((uint32_t)(c->esp + 0x68u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x68], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov ecx, dword ptr [ecx + 8] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x64u)); /* lea edx, [esp + 0x64] */
    W32((uint32_t)(c->esp + 0x6cu), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x6c], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov ecx, dword ptr [esp + 0x30] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->ebx = (uint32_t)(add32(c, c->ebx, c->ebp)); /* add ebx, ebp */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x24u)); PUSH32(c, 0x0078432cu); call_indirect(c, t_); } /* call dword ptr [eax + 0x24] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov eax, dword ptr [esp + 0x28] */
    c->ebp = (uint32_t)(add32(c, c->ebp, (uint32_t)0xcu)); /* add ebp, 0xc */
    WF32((uint32_t)(c->ebx + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebx + 8] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x28], eax */
    if (!c->zf) goto L_007842d0; /* jne 0x7842d0 */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x80u))); /* mov ebp, dword ptr [esp + 0x80] */
L_00784344:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov ecx, dword ptr [esp + 0x2c] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
    W32((uint32_t)(c->esp + 0x38u), (uint32_t)((uint32_t)0x4e6e6b28u)); /* mov dword ptr [esp + 0x38], 0x4e6e6b28 */
    W32((uint32_t)(c->esp + 0x40u), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [esp + 0x40], 0xffffffff */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x28], eax */
    if ((c->cf || c->zf)) goto L_00784693; /* jbe 0x784693 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
L_0078436a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    { uint32_t v_ = 0x792160u; PUSH32(c, v_); } /* push 0x10012160 */
    { uint32_t v_ = 0x94u; PUSH32(c, v_); } /* push 0x94 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ecx, dword ptr [eax + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x40u))); /* mov eax, dword ptr [esi + 0x40] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->edx + c->ecx))); /* mov ebx, dword ptr [edx + ecx] */
    c->edx = (uint32_t)((uint32_t)0x79212cu); /* mov edx, 0x1001212c */
    (void)sub32(c, c->ebx, c->eax); /* cmp ebx, eax */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(c->cf ? 1 : 0); /* setb cl */
    PUSH32(c, 0x00784394u); f_00784910(c); /* call 0x784910 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x3cu))); /* mov ecx, dword ptr [esi + 0x3c] */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->ebx * 4)); /* lea eax, [ebx + ebx*4] */
    c->edx = (uint32_t)((uint32_t)(c->ecx + c->eax * 8)); /* lea edx, [ecx + eax*8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + c->eax * 8))); /* mov eax, dword ptr [ecx + eax*8] */
    W32((uint32_t)(c->esp + 0x70u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x70], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov ecx, dword ptr [edx + 4] */
    W32((uint32_t)(c->esp + 0x74u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x74], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov ecx, dword ptr [esp + 0x30] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov edx, dword ptr [edx + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    W32((uint32_t)(c->esp + 0x78u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x78], edx */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x70u)); /* lea edx, [esp + 0x70] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x24u)); PUSH32(c, 0x007843c1u); call_indirect(c, t_); } /* call dword ptr [eax + 0x24] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x7902a8u))); FPOP(c); /* fcomp dword ptr [0x100102a8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (!PF(c)) goto L_00784611; /* jnp 0x784611 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    { uint32_t v_ = 0x792160u; PUSH32(c, v_); } /* push 0x10012160 */
    { uint32_t v_ = 0x94u; PUSH32(c, v_); } /* push 0x94 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ecx, dword ptr [eax + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x40u))); /* mov eax, dword ptr [esi + 0x40] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->edx + c->ecx))); /* mov ebx, dword ptr [edx + ecx] */
    c->edx = (uint32_t)((uint32_t)0x79212cu); /* mov edx, 0x1001212c */
    (void)sub32(c, c->ebx, c->eax); /* cmp ebx, eax */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(c->cf ? 1 : 0); /* setb cl */
    PUSH32(c, 0x007843fcu); f_00784910(c); /* call 0x784910 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x3cu))); /* mov ecx, dword ptr [esi + 0x3c] */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->ebx * 4)); /* lea eax, [ebx + ebx*4] */
    FPUSH(c, (double)RF32((uint32_t)(c->ebp))); /* fld dword ptr [ebp] */
    c->edx = (uint32_t)((uint32_t)(c->ecx + c->eax * 8)); /* lea edx, [ecx + eax*8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + c->eax * 8))); /* mov eax, dword ptr [ecx + eax*8] */
    W32((uint32_t)(c->esp + 0x58u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x58], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov ecx, dword ptr [edx + 4] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x58u))); /* fsub dword ptr [esp + 0x58] */
    FPUSH(c, (double)RF32((uint32_t)(c->ebp + 0x4u))); /* fld dword ptr [ebp + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov edx, dword ptr [edx + 8] */
    W32((uint32_t)(c->esp + 0x5cu), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x5c], ecx */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x5cu))); /* fsub dword ptr [esp + 0x5c] */
    FPUSH(c, (double)RF32((uint32_t)(c->ebp + 0x8u))); /* fld dword ptr [ebp + 8] */
    W32((uint32_t)(c->esp + 0x60u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x60], edx */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x60u))); /* fsub dword ptr [esp + 0x60] */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    { double v_ = ST(2); FPUSH(c, v_); } /* fld st(2) */
    ST(0) = FPRES(c, ST(0) * ST(3)); /* fmul st(3) */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    { double v_ = ST(3); FPUSH(c, v_); } /* fld st(3) */
    ST(0) = FPRES(c, ST(0) * ST(4)); /* fmul st(4) */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, sqrt(ST(0))); /* fsqrt  */
    ST(3) = ST(0); FPOP(c); /* fstp st(3) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    WF32((uint32_t)(c->esp + 0x34u), (float)ST(0)); /* fst dword ptr [esp + 0x34] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x790300u))); FPOP(c); /* fcomp dword ptr [0x10010300] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (!PF(c)) goto L_00784611; /* jnp 0x784611 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov eax, dword ptr [esp + 0x20] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->cf || c->zf)) goto L_00784611; /* jbe 0x784611 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x1c], 0 */
    W32((uint32_t)(c->esp + 0x48u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x48], ecx */
    W32((uint32_t)(c->esp + 0x3cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x3c], eax */
L_0078447c:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov edx, dword ptr [esp + 0x18] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov ecx, dword ptr [esp + 0x1c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov eax, dword ptr [edx + 8] */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x8u))); /* fld dword ptr [ecx + 8] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x7902a8u))); FPOP(c); /* fcomp dword ptr [0x100102a8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_007845f7; /* jne 0x7845f7 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov ebx, dword ptr [ecx] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x40u))); /* mov eax, dword ptr [esi + 0x40] */
    (void)sub32(c, c->ebx, c->eax); /* cmp ebx, eax */
    if (c->cf) goto L_007844cb; /* jb 0x7844cb */
    c->eax = (uint32_t)(R32((uint32_t)(0x795678u))); /* mov eax, dword ptr [0x10015678] */
    { uint32_t v_ = 0x792160u; PUSH32(c, v_); } /* push 0x10012160 */
    { uint32_t v_ = 0x94u; PUSH32(c, v_); } /* push 0x94 */
    { uint32_t v_ = 0x79212cu; PUSH32(c, v_); } /* push 0x1001212c */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0x7920b0u; PUSH32(c, v_); } /* push 0x100120b0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x007844c7u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x007844cau, "int3"); /* int3  */
L_007844cb:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x3cu))); /* mov ecx, dword ptr [esi + 0x3c] */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->ebx * 4)); /* lea eax, [ebx + ebx*4] */
    FPUSH(c, (double)RF32((uint32_t)(c->edi))); /* fld dword ptr [edi] */
    c->edx = (uint32_t)((uint32_t)(c->ecx + c->eax * 8)); /* lea edx, [ecx + eax*8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + c->eax * 8))); /* mov eax, dword ptr [ecx + eax*8] */
    W32((uint32_t)(c->esp + 0x64u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x64], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov ecx, dword ptr [edx + 4] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x64u))); /* fsub dword ptr [esp + 0x64] */
    FPUSH(c, (double)RF32((uint32_t)(c->edi + 0x4u))); /* fld dword ptr [edi + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov edx, dword ptr [edx + 8] */
    W32((uint32_t)(c->esp + 0x68u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x68], ecx */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x68u))); /* fsub dword ptr [esp + 0x68] */
    FPUSH(c, (double)RF32((uint32_t)(c->edi + 0x8u))); /* fld dword ptr [edi + 8] */
    W32((uint32_t)(c->esp + 0x6cu), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x6c], edx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ecx, dword ptr [eax + 8] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x6cu))); /* fsub dword ptr [esp + 0x6c] */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    { double v_ = ST(2); FPUSH(c, v_); } /* fld st(2) */
    ST(0) = FPRES(c, ST(0) * ST(3)); /* fmul st(3) */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov edx, dword ptr [esp + 0x1c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    { double v_ = ST(3); FPUSH(c, v_); } /* fld st(3) */
    ST(0) = FPRES(c, ST(0) * ST(4)); /* fmul st(4) */
    c->ebp = (uint32_t)(R32((uint32_t)(c->edx + c->ecx))); /* mov ebp, dword ptr [edx + ecx] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ecx, dword ptr [eax + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x40u))); /* mov eax, dword ptr [esi + 0x40] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    c->ebx = (uint32_t)(R32((uint32_t)(c->edx + c->ecx))); /* mov ebx, dword ptr [edx + ecx] */
    (void)sub32(c, c->ebx, c->eax); /* cmp ebx, eax */
    ST(0) = FPRES(c, sqrt(ST(0))); /* fsqrt  */
    ST(3) = ST(0); FPOP(c); /* fstp st(3) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    WF32((uint32_t)(c->esp + 0x48u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x48] */
    if (!c->cf) goto L_00784540; /* jae 0x784540 */
    (void)sub32(c, c->ebp, c->eax); /* cmp ebp, eax */
    if (c->cf) goto L_00784563; /* jb 0x784563 */
L_00784540:;
    c->eax = (uint32_t)(R32((uint32_t)(0x795678u))); /* mov eax, dword ptr [0x10015678] */
    { uint32_t v_ = 0x792430u; PUSH32(c, v_); } /* push 0x10012430 */
    { uint32_t v_ = 0x15du; PUSH32(c, v_); } /* push 0x15d */
    { uint32_t v_ = 0x79212cu; PUSH32(c, v_); } /* push 0x1001212c */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x7920b0u; PUSH32(c, v_); } /* push 0x100120b0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x0078455fu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00784562u, "int3"); /* int3  */
L_00784563:;
    (void)sub32(c, c->ebx, c->ebp); /* cmp ebx, ebp */
    if (!c->zf) goto L_0078456f; /* jne 0x78456f */
    FPUSH(c, (double)RF32((uint32_t)(0x7902b8u))); /* fld dword ptr [0x100102b8] */
    goto L_007845be; /* jmp 0x7845be */
L_0078456f:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x40u))); /* mov eax, dword ptr [esi + 0x40] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x5cu))); /* mov edx, dword ptr [esi + 0x5c] */
    W32((uint32_t)(c->esp + 0x44u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x44], eax */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)c->ebx; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, ebx */
    c->eax = (uint32_t)(add32(c, c->eax, c->ebp)); /* add eax, ebp */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x24], 0 */
    c->edi = (uint32_t)(R32((uint32_t)(c->edx + c->eax * 8))); /* mov edi, dword ptr [edx + eax*8] */
    (void)sub32(c, c->edi, (uint32_t)0xffffffffu); /* cmp edi, -1 */
    if (c->zf) goto L_007845b3; /* je 0x7845b3 */
L_0078458e:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00784597u); f_00785ad0(c); /* call 0x785ad0 */
    c->ebx = (uint32_t)(c->edi); /* mov ebx, edi */
    { int64_t r_ = (int64_t)(int32_t)c->edi * (int32_t)R32((uint32_t)(c->esp + 0x44u)); c->edi = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul edi, dword ptr [esp + 0x44] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x24u))); /* fadd dword ptr [esp + 0x24] */
    WF32((uint32_t)(c->esp + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x24] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x5cu))); /* mov eax, dword ptr [esi + 0x5c] */
    c->edi = (uint32_t)(add32(c, c->edi, c->ebp)); /* add edi, ebp */
    c->edi = (uint32_t)(R32((uint32_t)(c->eax + c->edi * 8))); /* mov edi, dword ptr [eax + edi*8] */
    (void)sub32(c, c->edi, (uint32_t)0xffffffffu); /* cmp edi, -1 */
    if (!c->zf) goto L_0078458e; /* jne 0x78458e */
L_007845b3:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x24u))); /* fld dword ptr [esp + 0x24] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x84u))); /* mov edi, dword ptr [esp + 0x84] */
L_007845be:;
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x48u))); /* fadd dword ptr [esp + 0x48] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x80u))); /* mov ebp, dword ptr [esp + 0x80] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x34u))); /* fadd dword ptr [esp + 0x34] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->esp + 0x38u))); /* fcom dword ptr [esp + 0x38] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_007845f5; /* jp 0x7845f5 */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x7902b8u))); /* fcom dword ptr [0x100102b8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_007845f5; /* jne 0x7845f5 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov ecx, dword ptr [esp + 0x28] */
    WF32((uint32_t)(c->esp + 0x38u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x38] */
    W32((uint32_t)(c->esp + 0x40u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x40], ecx */
    goto L_007845f7; /* jmp 0x7845f7 */
L_007845f5:;
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
L_007845f7:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov ecx, dword ptr [esp + 0x1c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x3cu))); /* mov eax, dword ptr [esp + 0x3c] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0xcu)); /* add ecx, 0xc */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x1c], ecx */
    W32((uint32_t)(c->esp + 0x3cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x3c], eax */
    if (!c->zf) goto L_0078447c; /* jne 0x78447c */
L_00784611:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov eax, dword ptr [esp + 0x28] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov ecx, dword ptr [esp + 0x2c] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0xcu)); /* add edx, 0xc */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x28], eax */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x10], edx */
    if (c->cf) goto L_0078436a; /* jb 0x78436a */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x40u))); /* mov eax, dword ptr [esp + 0x40] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (c->zf) goto L_00784693; /* je 0x784693 */
    c->edx = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea edx, [eax + eax*2] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ecx, dword ptr [eax + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x40u))); /* mov eax, dword ptr [esi + 0x40] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ecx + c->edx * 4))); /* mov edi, dword ptr [ecx + edx*4] */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_00784671; /* jb 0x784671 */
    c->eax = (uint32_t)(R32((uint32_t)(0x795678u))); /* mov eax, dword ptr [0x10015678] */
    { uint32_t v_ = 0x792160u; PUSH32(c, v_); } /* push 0x10012160 */
    { uint32_t v_ = 0x94u; PUSH32(c, v_); } /* push 0x94 */
    { uint32_t v_ = 0x79212cu; PUSH32(c, v_); } /* push 0x1001212c */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0x7920b0u; PUSH32(c, v_); } /* push 0x100120b0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x0078466du); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00784670u, "int3"); /* int3  */
L_00784671:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x3cu))); /* mov ecx, dword ptr [esi + 0x3c] */
    c->eax = (uint32_t)((uint32_t)(c->edi + c->edi * 4)); /* lea eax, [edi + edi*4] */
    c->edx = (uint32_t)((uint32_t)(c->ecx + c->eax * 8)); /* lea edx, [ecx + eax*8] */
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov edx, dword ptr [eax + 4] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov esi, dword ptr [eax + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x88u))); /* mov eax, dword ptr [esp + 0x88] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 4], edx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [eax + 8], esi */
L_00784693:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ecx, dword ptr [esp + 0x14] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx)); PUSH32(c, 0x0078469du); call_indirect(c, t_); } /* call dword ptr [edx] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov ecx, dword ptr [esp + 0x18] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax)); PUSH32(c, 0x007846a7u); call_indirect(c, t_); } /* call dword ptr [eax] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x6cu)); /* add esp, 0x6c */
    c->esp += 16; return; /* ret 0xc */
}

void f_007846c0(CPU *c) { /* FUN_100046c0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov ecx, dword ptr [esi + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x4u)); /* lea edi, [esi + 4] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0xcu)); PUSH32(c, 0x007846d4u); call_indirect(c, t_); } /* call dword ptr [eax + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov edx, dword ptr [esi + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    W32((uint32_t)(c->eax + c->edx * 4), (uint32_t)(c->ecx)); /* mov dword ptr [eax + edx*4], ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov edx, dword ptr [edi + 8] */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    W32((uint32_t)(c->edi + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [edi + 8], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00784700(CPU *c) { /* PTR_00784700 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    c->esp += 4; return; /* ret  */
}

void f_00784710(CPU *c) { /* PTR_00784710 */
    PREEMPT_POLL(c);
    c->esp += 8; return; /* ret 4 */
}

void f_00784720(CPU *c) { /* PTR_00784720 */
    PREEMPT_POLL(c);
    c->esp += 16; return; /* ret 0xc */
}

void f_00784730(CPU *c) { /* PTR_00784730 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    c->esp += 8; return; /* ret 4 */
}

void f_00784740(CPU *c) { /* PTR_00784740 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 8; return; /* ret 4 */
}

void f_00784750(CPU *c) { /* FUN_10004750 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x14u))); /* mov edx, dword ptr [esi + 0x14] */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x790218u)); /* mov dword ptr [esi], 0x10010218 */
    c->ecx = (uint32_t)(R32((uint32_t)(0x795678u))); /* mov ecx, dword ptr [0x10015678] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x00784768u); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00784778; /* je 0x784778 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00784775u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00784778:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00784780(CPU *c) { /* FUN_10004780 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x790198u)); /* mov dword ptr [esi], 0x10010198 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)((uint32_t)0x79023cu)); /* mov dword ptr [esi + 4], 0x1001023c */
    W32((uint32_t)(c->esi + 0x14u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0x14], edi */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0xc], edi */
    if (c->zf) goto L_007847a9; /* je 0x7847a9 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x007847a6u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_007847a9:;
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 8], edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_007847b0(CPU *c) { /* PTR_007847b0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov ecx, dword ptr [esi + 0xc] */
    { uint32_t d_ = c->ecx; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x007847beu, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div ecx */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    { int64_t r_ = (int64_t)(int32_t)c->edi * (int32_t)c->ecx; c->edi = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul edi, ecx */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (c->zf) goto L_0078481a; /* je 0x78481a */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x40u; PUSH32(c, v_); } /* push 0x40 */
    c->ecx = (uint32_t)((uint32_t)(c->edi * 4)); /* lea ecx, [edi*4] */
    { uint32_t v_ = 0x792460u; PUSH32(c, v_); } /* push 0x10012460 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x007847e2u); f_00781070(c); /* call 0x781070 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ecx, dword ptr [esi + 8] */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if ((c->cf || c->zf)) goto L_00784803; /* jbe 0x784803 */
L_007847f0:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov edx, dword ptr [esi + 4] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + c->eax * 4 + 0xfffffffcu))); /* mov ecx, dword ptr [edx + eax*4 - 4] */
    W32((uint32_t)(c->ebx + c->eax * 4 + 0xfffffffcu), (uint32_t)(c->ecx)); /* mov dword ptr [ebx + eax*4 - 4], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ecx, dword ptr [esi + 8] */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (c->cf) goto L_007847f0; /* jb 0x7847f0 */
L_00784803:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00784813; /* je 0x784813 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00784810u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00784813:;
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 4], ebx */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0x10], edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
L_0078481a:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00784820(CPU *c) { /* FUN_10004820 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)((uint32_t)0x79024cu)); /* mov dword ptr [eax + 4], 0x1001024c */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    W32((uint32_t)(c->eax + 0x10u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 0x10], edx */
    W32((uint32_t)(c->eax + 0x14u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x14], ecx */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0xc], ecx */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x79025cu)); /* mov dword ptr [eax], 0x1001025c */
    c->esp += 8; return; /* ret 4 */
}

void f_00784850(CPU *c) { /* FUN_10004850 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x79025cu)); /* mov dword ptr [esi], 0x1001025c */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)((uint32_t)0x79024cu)); /* mov dword ptr [esi + 4], 0x1001024c */
    W32((uint32_t)(c->esi + 0x14u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0x14], edi */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0xc], edi */
    if (c->zf) goto L_00784879; /* je 0x784879 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00784876u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00784879:;
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 8], edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00784880(CPU *c) { /* FUN_10004880 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov ecx, dword ptr [esi + 0xc] */
    { uint32_t d_ = c->ecx; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x0078488eu, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div ecx */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    { int64_t r_ = (int64_t)(int32_t)c->edi * (int32_t)c->ecx; c->edi = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul edi, ecx */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (c->zf) goto L_00784906; /* je 0x784906 */
    c->ecx = (uint32_t)((uint32_t)(c->edi + c->edi * 2)); /* lea ecx, [edi + edi*2] */
    { uint32_t v_ = 0x40u; PUSH32(c, v_); } /* push 0x40 */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 2)); /* shl ecx, 2 */
    { uint32_t v_ = 0x792460u; PUSH32(c, v_); } /* push 0x10012460 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x007848b0u); f_00781070(c); /* call 0x781070 */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x18], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->cf || c->zf)) goto L_007848ec; /* jbe 0x7848ec */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_007848c4:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov edx, dword ptr [esi + 4] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ebx, dword ptr [esp + 0x14] */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    c->ebx = (uint32_t)(add32(c, c->ebx, c->eax)); /* add ebx, eax */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xcu)); /* add eax, 0xc */
    c->ebp = (uint32_t)(R32((uint32_t)(c->edx))); /* mov ebp, dword ptr [edx] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->ebp)); /* mov dword ptr [ebx], ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov ebp, dword ptr [edx + 4] */
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->ebp)); /* mov dword ptr [ebx + 4], ebp */
    c->edx = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov edx, dword ptr [edx + 8] */
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [ebx + 8], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov edx, dword ptr [esi + 8] */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if (c->cf) goto L_007848c4; /* jb 0x7848c4 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
L_007848ec:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_007848fc; /* je 0x7848fc */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x007848f9u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_007848fc:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0x10], edi */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 4], eax */
L_00784906:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00784910(CPU *c) { /* FUN_10004910 */
    PREEMPT_POLL(c);
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_0078494f; /* jne 0x78494f */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(0x795678u))); /* mov eax, dword ptr [0x10015678] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    if (c->zf) goto L_00784939; /* je 0x784939 */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax))); /* mov esi, dword ptr [eax] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x7920b0u; PUSH32(c, v_); } /* push 0x100120b0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->esi + 0x14u)); PUSH32(c, 0x00784934u); call_indirect(c, t_); } /* call dword ptr [esi + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    goto L_0078494d; /* jmp 0x78494d */
L_00784939:;
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x7924a8u; PUSH32(c, v_); } /* push 0x100124a8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x0078494au); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_0078494d:;
    guest_trap(c, 0x0078494du, "int3"); /* int3  */
L_0078494f:;
    c->esp += 12; return; /* ret 8 */
}

void f_00784960(CPU *c) { /* FUN_10004960 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)((uint32_t)0x790268u)); /* mov dword ptr [eax + 4], 0x10010268 */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    W32((uint32_t)(c->eax + 0x10u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 0x10], edx */
    W32((uint32_t)(c->eax + 0x14u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x14], ecx */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0xc], ecx */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x790278u)); /* mov dword ptr [eax], 0x10010278 */
    c->esp += 8; return; /* ret 4 */
}

void f_00784990(CPU *c) { /* FUN_10004990 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x790278u)); /* mov dword ptr [esi], 0x10010278 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)((uint32_t)0x790268u)); /* mov dword ptr [esi + 4], 0x10010268 */
    W32((uint32_t)(c->esi + 0x14u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x14], ebx */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0xc], ebx */
    if (c->zf) goto L_007849cf; /* je 0x7849cf */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0xfffffffcu))); /* mov ecx, dword ptr [eax - 4] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)((uint32_t)(c->eax + 0xfffffffcu)); /* lea edi, [eax - 4] */
    { uint32_t v_ = 0x785890u; PUSH32(c, v_); } /* push 0x10005890 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x28u; PUSH32(c, v_); } /* push 0x28 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x007849c5u); f_00786c2f(c); /* call 0x786c2f */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x007849cbu); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_007849cf:;
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 8], ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_007849e0(CPU *c) { /* PTR_007849e0 */
    PREEMPT_POLL(c);
    { uint32_t a_ = (uint32_t)(c->ecx + 0xcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ecx + 0xc] */
    c->esp += 4; return; /* ret  */
}

void f_007849f0(CPU *c) { /* PTR_007849f0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov eax, dword ptr [ecx + 0xc] */
    c->esp += 4; return; /* ret  */
}

void f_00784a00(CPU *c) { /* PTR_00784a00 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx + 0xcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ecx + 0xc], 0 */
    c->esp += 4; return; /* ret  */
}

void f_00784a10(CPU *c) { /* FUN_10004a10 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0xcu))); /* mov ecx, dword ptr [edi + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov eax, dword ptr [edi + 4] */
    c->esi = (uint32_t)((uint32_t)(c->edi + 0x4u)); /* lea esi, [edi + 4] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0xcu)); PUSH32(c, 0x00784a24u); call_indirect(c, t_); } /* call dword ptr [eax + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov edx, dword ptr [esi + 8] */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 8], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0xcu))); /* mov eax, dword ptr [edi + 0xc] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00784a40(CPU *c) { /* PTR_00784a40 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    c->esp += 4; return; /* ret  */
}

void f_00784a50(CPU *c) { /* PTR_00784a50 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x4u))); /* mov al, byte ptr [esp + 4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x790120u)); /* mov dword ptr [esi], 0x10010120 */
    if (c->zf) goto L_00784a6a; /* je 0x784a6a */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00784a67u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00784a6a:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00784a70(CPU *c) { /* FUN_10004a70 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x10], ebx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 8], ebx */
    if (c->zf) goto L_00784aa2; /* je 0x784aa2 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0xfffffffcu))); /* mov ecx, dword ptr [eax - 4] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)((uint32_t)(c->eax + 0xfffffffcu)); /* lea edi, [eax - 4] */
    { uint32_t v_ = 0x785890u; PUSH32(c, v_); } /* push 0x10005890 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x28u; PUSH32(c, v_); } /* push 0x28 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00784a98u); f_00786c2f(c); /* call 0x786c2f */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00784a9eu); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_00784aa2:;
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 4], ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00784ab0(CPU *c) { /* FUN_10004ab0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x78fb04u; PUSH32(c, v_); } /* push 0x1000fb04 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x14u)); /* sub esp, 0x14 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov eax, dword ptr [esp + 0x24] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->ecx); /* mov ebp, ecx */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0x18], ebp */
    { uint32_t d_ = c->ecx; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x00784adau, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div ecx */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    { int64_t r_ = (int64_t)(int32_t)c->edi * (int32_t)c->ecx; c->edi = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul edi, ecx */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 8], edi */
    if (c->zf) goto L_00784c2f; /* je 0x784c2f */
    c->ecx = (uint32_t)((uint32_t)(c->edi + c->edi * 4)); /* lea ecx, [edi + edi*4] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x40u; PUSH32(c, v_); } /* push 0x40 */
    c->edx = (uint32_t)((uint32_t)(c->ecx * 8 + 0x4u)); /* lea edx, [ecx*8 + 4] */
    { uint32_t v_ = 0x792460u; PUSH32(c, v_); } /* push 0x10012460 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00784b0au); f_00781070(c); /* call 0x781070 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->esp + 0x34u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x34], eax */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x2c], ecx */
    if (c->zf) goto L_00784b3b; /* je 0x784b3b */
    { uint32_t v_ = 0x785890u; PUSH32(c, v_); } /* push 0x10005890 */
    { uint32_t v_ = 0x785700u; PUSH32(c, v_); } /* push 0x10005700 */
    c->esi = (uint32_t)((uint32_t)(c->eax + 0x4u)); /* lea esi, [eax + 4] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x28u; PUSH32(c, v_); } /* push 0x28 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W32((uint32_t)(c->eax), (uint32_t)(c->edi)); /* mov dword ptr [eax], edi */
    PUSH32(c, 0x00784b33u); f_00786d0d(c); /* call 0x786d0d */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    W32((uint32_t)(c->esp + 0x34u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x34], ebx */
    goto L_00784b41; /* jmp 0x784b41 */
L_00784b3b:;
    W32((uint32_t)(c->esp + 0x34u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x34], ecx */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
L_00784b41:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [esp + 0x2c], 0xffffffff */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x14], 0 */
    if ((c->cf || c->zf)) goto L_00784c03; /* jbe 0x784c03 */
    c->eax = (uint32_t)((uint32_t)0xffffffe4u); /* mov eax, 0xffffffe4 */
    c->esi = (uint32_t)((uint32_t)(c->ebx + 0x1cu)); /* lea esi, [ebx + 0x1c] */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ebx)); /* sub eax, ebx */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x18], eax */
    goto L_00784b70; /* jmp 0x784b70 */
L_00784b6c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
L_00784b70:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x4u))); /* mov ecx, dword ptr [ebp + 4] */
    c->eax = (uint32_t)(add32(c, c->eax, c->esi)); /* add eax, esi */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0xffffffe4u)); /* lea ecx, [esi - 0x1c] */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    c->ebx = (uint32_t)(R32((uint32_t)(c->edx))); /* mov ebx, dword ptr [edx] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->ebx)); /* mov dword ptr [ecx], ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov ebx, dword ptr [edx + 4] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [ecx + 4], ebx */
    c->ebx = (uint32_t)((uint32_t)(c->eax + 0x10u)); /* lea ebx, [eax + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov edx, dword ptr [edx + 8] */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 8], edx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0xcu))); /* mov ecx, dword ptr [eax + 0xc] */
    c->edx = (uint32_t)((uint32_t)(c->esi + 0xfffffff4u)); /* lea edx, [esi - 0xc] */
    W32((uint32_t)(c->esi + 0xfffffff0u), (uint32_t)(c->ecx)); /* mov dword ptr [esi - 0x10], ecx */
    (void)sub32(c, c->edx, c->ebx); /* cmp edx, ebx */
    if (c->zf) goto L_00784be8; /* je 0x784be8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xfffffff4u))); /* mov eax, dword ptr [esi - 0xc] */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0xfffffff4u)); /* lea ecx, [esi - 0xc] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4u)); PUSH32(c, 0x00784ba5u); call_indirect(c, t_); } /* call dword ptr [eax + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xcu))); /* mov eax, dword ptr [ebx + 0xc] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->cf || c->zf)) goto L_00784be4; /* jbe 0x784be4 */
    c->ebp = (uint32_t)((uint32_t)(c->esi + 0xfffffff8u)); /* lea ebp, [esi - 8] */
L_00784bb1:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov ecx, dword ptr [ebx + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov eax, dword ptr [ebp] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + c->edi * 4))); /* mov edx, dword ptr [ecx + edi*4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x1c], edx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0xcu)); PUSH32(c, 0x00784bc7u); call_indirect(c, t_); } /* call dword ptr [eax + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xfffffffcu))); /* mov eax, dword ptr [esi - 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov ecx, dword ptr [esp + 0x1c] */
    W32((uint32_t)(c->eax + c->edx * 4), (uint32_t)(c->ecx)); /* mov dword ptr [eax + edx*4], ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    W32((uint32_t)(c->esi), (uint32_t)(c->edx)); /* mov dword ptr [esi], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xcu))); /* mov eax, dword ptr [ebx + 0xc] */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_00784bb1; /* jb 0x784bb1 */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov ebp, dword ptr [esp + 0x20] */
L_00784be4:;
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edi, dword ptr [esp + 0x10] */
L_00784be8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x28u)); /* add esi, 0x28 */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    if (c->cf) goto L_00784b6c; /* jb 0x784b6c */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov ebx, dword ptr [esp + 0x34] */
L_00784c03:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x4u))); /* mov eax, dword ptr [ebp + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00784c27; /* je 0x784c27 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0xfffffffcu))); /* mov edx, dword ptr [eax - 4] */
    c->esi = (uint32_t)((uint32_t)(c->eax + 0xfffffffcu)); /* lea esi, [eax - 4] */
    { uint32_t v_ = 0x785890u; PUSH32(c, v_); } /* push 0x10005890 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x28u; PUSH32(c, v_); } /* push 0x28 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00784c1eu); f_00786c2f(c); /* call 0x786c2f */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00784c24u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00784c27:;
    W32((uint32_t)(c->ebp + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 4], ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 0x10], edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
L_00784c2f:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov ecx, dword ptr [esp + 0x1c] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    c->esp += 8; return; /* ret 4 */
}

void f_00784c50(CPU *c) { /* FUN_10004c50 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x7901a4u)); /* mov dword ptr [esi], 0x100101a4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)((uint32_t)0x7901b0u)); /* mov dword ptr [esi + 4], 0x100101b0 */
    W32((uint32_t)(c->esi + 0x14u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0x14], edi */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0xc], edi */
    if (c->zf) goto L_00784c79; /* je 0x784c79 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00784c76u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00784c79:;
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 8], edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00784c80(CPU *c) { /* PTR_00784c80 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov eax, dword ptr [ecx + 4] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); switch (t_) {  default: jump_indirect(c, t_, 0x00784c86u); return; } } /* jmp dword ptr [eax + 8] */
}

void f_00784c90(CPU *c) { /* PTR_00784c90 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov eax, dword ptr [ecx + 4] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4u)); switch (t_) {  default: jump_indirect(c, t_, 0x00784c96u); return; } } /* jmp dword ptr [eax + 4] */
}

void f_00784ca0(CPU *c) { /* PTR_00784ca0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0xcu))); /* mov ecx, dword ptr [ebx + 0xc] */
    { uint32_t d_ = c->ecx; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x00784caeu, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div ecx */
    c->ebp = (uint32_t)(c->eax); /* mov ebp, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x10u))); /* mov eax, dword ptr [ebx + 0x10] */
    c->ebp = (uint32_t)(inc32(c, c->ebp)); /* inc ebp */
    { int64_t r_ = (int64_t)(int32_t)c->ebp * (int32_t)c->ecx; c->ebp = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul ebp, ecx */
    (void)sub32(c, c->eax, c->ebp); /* cmp eax, ebp */
    if (c->zf) goto L_00784d54; /* je 0x784d54 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + c->ebp * 2)); /* lea ecx, [ebp + ebp*2] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x40u; PUSH32(c, v_); } /* push 0x40 */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 3)); /* shl ecx, 3 */
    { uint32_t v_ = 0x792460u; PUSH32(c, v_); } /* push 0x10012460 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00784cd7u); f_00781070(c); /* call 0x781070 */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, c->eax, c->edx); /* cmp eax, edx */
    if (c->zf) goto L_00784d0d; /* je 0x784d0d */
    c->esi = (uint32_t)((uint32_t)(c->ebp + 0xffffffffu)); /* lea esi, [ebp - 1] */
    (void)sub32(c, c->esi, c->edx); /* cmp esi, edx */
    if ((c->sf != c->of)) goto L_00784d07; /* jl 0x784d07 */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0xcu)); /* lea ecx, [eax + 0xc] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_00784ceb:;
    c->edi = (uint32_t)((uint32_t)(c->ecx + 0xfffffff4u)); /* lea edi, [ecx - 0xc] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x18u)); /* add ecx, 0x18 */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    W32((uint32_t)(c->edi + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [edi + 4], edx */
    W32((uint32_t)(c->ecx + 0xffffffe4u), (uint32_t)(c->edx)); /* mov dword ptr [ecx - 0x1c], edx */
    W32((uint32_t)(c->ecx + 0xffffffe8u), (uint32_t)(c->edx)); /* mov dword ptr [ecx - 0x18], edx */
    W32((uint32_t)(c->ecx + 0xffffffecu), (uint32_t)(c->edx)); /* mov dword ptr [ecx - 0x14], edx */
    W32((uint32_t)(c->ecx + 0xfffffff0u), (uint32_t)(c->edx)); /* mov dword ptr [ecx - 0x10], edx */
    if (!c->zf) goto L_00784ceb; /* jne 0x784ceb */
L_00784d07:;
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    goto L_00784d11; /* jmp 0x784d11 */
L_00784d0d:;
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x14], edx */
L_00784d11:;
    (void)sub32(c, R32((uint32_t)(c->ebx + 0x8u)), c->edx); /* cmp dword ptr [ebx + 8], edx */
    if ((c->cf || c->zf)) goto L_00784d38; /* jbe 0x784d38 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00784d18:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ecx, dword ptr [esp + 0x14] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov esi, dword ptr [ebx + 4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    c->edi = (uint32_t)((uint32_t)(c->eax + c->ecx)); /* lea edi, [eax + ecx] */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov ecx, dword ptr [ebx + 8] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x18u)); /* add eax, 0x18 */
    (void)sub32(c, c->edx, c->ecx); /* cmp edx, ecx */
    if (c->cf) goto L_00784d18; /* jb 0x784d18 */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
L_00784d38:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov eax, dword ptr [ebx + 4] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    (void)sub32(c, c->eax, c->edx); /* cmp eax, edx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    if (c->zf) goto L_00784d4a; /* je 0x784d4a */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00784d47u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00784d4a:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    W32((uint32_t)(c->ebx + 0x10u), (uint32_t)(c->ebp)); /* mov dword ptr [ebx + 0x10], ebp */
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [ebx + 4], edx */
L_00784d54:;
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
}

void f_00784d60(CPU *c) { /* FUN_10004d60 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x79028cu)); /* mov dword ptr [esi], 0x1001028c */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)((uint32_t)0x790298u)); /* mov dword ptr [esi + 4], 0x10010298 */
    W32((uint32_t)(c->esi + 0x14u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0x14], edi */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0xc], edi */
    if (c->zf) goto L_00784d89; /* je 0x784d89 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00784d86u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00784d89:;
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 8], edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00784d90(CPU *c) { /* FUN_10004d90 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov ecx, dword ptr [esi + 0xc] */
    { uint32_t d_ = c->ecx; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x00784d9eu, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div ecx */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    { int64_t r_ = (int64_t)(int32_t)c->edi * (int32_t)c->ecx; c->edi = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul edi, ecx */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (c->zf) goto L_00784e1b; /* je 0x784e1b */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    { uint32_t v_ = 0x40u; PUSH32(c, v_); } /* push 0x40 */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 4)); /* shl ecx, 4 */
    { uint32_t v_ = 0x792460u; PUSH32(c, v_); } /* push 0x10012460 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00784dbfu); f_00781070(c); /* call 0x781070 */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x18], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->cf || c->zf)) goto L_00784e01; /* jbe 0x784e01 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00784dd3:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov edx, dword ptr [esi + 4] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ebx, dword ptr [esp + 0x14] */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    c->ebx = (uint32_t)(add32(c, c->ebx, c->eax)); /* add ebx, eax */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x10u)); /* add eax, 0x10 */
    c->ebp = (uint32_t)(R32((uint32_t)(c->edx))); /* mov ebp, dword ptr [edx] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->ebp)); /* mov dword ptr [ebx], ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov ebp, dword ptr [edx + 4] */
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->ebp)); /* mov dword ptr [ebx + 4], ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov ebp, dword ptr [edx + 8] */
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->ebp)); /* mov dword ptr [ebx + 8], ebp */
    c->edx = (uint32_t)(R32((uint32_t)(c->edx + 0xcu))); /* mov edx, dword ptr [edx + 0xc] */
    W32((uint32_t)(c->ebx + 0xcu), (uint32_t)(c->edx)); /* mov dword ptr [ebx + 0xc], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov edx, dword ptr [esi + 8] */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if (c->cf) goto L_00784dd3; /* jb 0x784dd3 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
L_00784e01:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00784e11; /* je 0x784e11 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00784e0eu); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00784e11:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0x10], edi */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 4], eax */
L_00784e1b:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00784e20(CPU *c) { /* FUN_10004e20 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00784e28u); f_00784780(c); /* call 0x784780 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00784e38; /* je 0x784e38 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00784e35u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00784e38:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00784e40(CPU *c) { /* FUN_10004e40 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x79023cu)); /* mov dword ptr [esi], 0x1001023c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 0x10], 0 */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 8], 0 */
    if (c->zf) goto L_00784e67; /* je 0x784e67 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00784e64u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00784e67:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x8u))); /* mov al, byte ptr [esp + 8] */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 4], 0 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    if (c->zf) goto L_00784e7f; /* je 0x784e7f */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00784e7cu); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00784e7f:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00784e90(CPU *c) { /* FUN_10004e90 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00784e98u); f_00784850(c); /* call 0x784850 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00784ea8; /* je 0x784ea8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00784ea5u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00784ea8:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00784eb0(CPU *c) { /* FUN_10004eb0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x79024cu)); /* mov dword ptr [esi], 0x1001024c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 0x10], 0 */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 8], 0 */
    if (c->zf) goto L_00784ed7; /* je 0x784ed7 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00784ed4u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00784ed7:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x8u))); /* mov al, byte ptr [esp + 8] */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 4], 0 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    if (c->zf) goto L_00784eef; /* je 0x784eef */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00784eecu); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00784eef:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00784f00(CPU *c) { /* FUN_10004f00 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00784f08u); f_00784990(c); /* call 0x784990 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00784f18; /* je 0x784f18 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00784f15u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00784f18:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00784f20(CPU *c) { /* FUN_10004f20 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x790268u)); /* mov dword ptr [esi], 0x10010268 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 0x10], 0 */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 8], 0 */
    if (c->zf) goto L_00784f5d; /* je 0x784f5d */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0xfffffffcu))); /* mov ecx, dword ptr [eax - 4] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)((uint32_t)(c->eax + 0xfffffffcu)); /* lea edi, [eax - 4] */
    { uint32_t v_ = 0x785890u; PUSH32(c, v_); } /* push 0x10005890 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x28u; PUSH32(c, v_); } /* push 0x28 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00784f53u); f_00786c2f(c); /* call 0x786c2f */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00784f59u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_00784f5d:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x8u))); /* mov al, byte ptr [esp + 8] */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 4], 0 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    if (c->zf) goto L_00784f75; /* je 0x784f75 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00784f72u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00784f75:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00784f80(CPU *c) { /* FUN_10004f80 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00784f88u); f_00784c50(c); /* call 0x784c50 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00784f98; /* je 0x784f98 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00784f95u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00784f98:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00784fa0(CPU *c) { /* FUN_10004fa0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x7901b0u)); /* mov dword ptr [esi], 0x100101b0 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 0x10], 0 */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 8], 0 */
    if (c->zf) goto L_00784fc7; /* je 0x784fc7 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00784fc4u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00784fc7:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x8u))); /* mov al, byte ptr [esp + 8] */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 4], 0 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    if (c->zf) goto L_00784fdf; /* je 0x784fdf */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00784fdcu); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00784fdf:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00784ff0(CPU *c) { /* FUN_10004ff0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00784ff8u); f_00784d60(c); /* call 0x784d60 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00785008; /* je 0x785008 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00785005u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00785008:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00785010(CPU *c) { /* FUN_10005010 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x790298u)); /* mov dword ptr [esi], 0x10010298 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 0x10], 0 */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 8], 0 */
    if (c->zf) goto L_00785037; /* je 0x785037 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00785034u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00785037:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x8u))); /* mov al, byte ptr [esp + 8] */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 4], 0 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    if (c->zf) goto L_0078504f; /* je 0x78504f */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x0078504cu); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_0078504f:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00785060(CPU *c) { /* FUN_10005060 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x79023cu)); /* mov dword ptr [eax], 0x1001023c */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 4], ecx */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->edx)); /* mov dword ptr [eax + 0xc], edx */
    W32((uint32_t)(c->eax + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x10], ecx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    c->esp += 8; return; /* ret 4 */
}

void f_00785080(CPU *c) { /* FUN_10005080 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x1cu)); /* sub esp, 0x1c */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->ecx); /* mov ebp, ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0x4u)); /* lea edi, [ebp + 4] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 4], eax */
    W32((uint32_t)(c->edi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + 8], eax */
    W32((uint32_t)(c->edi + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + 0xc], eax */
    W32((uint32_t)(c->edi + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [edi + 0x10], eax */
    W32((uint32_t)(c->edi + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [edi + 0x14], eax */
    W32((uint32_t)(c->ebp), (uint32_t)((uint32_t)0x790218u)); /* mov dword ptr [ebp], 0x10010218 */
    W32((uint32_t)(c->ebp + 0x1cu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x1c], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(0x795678u))); /* mov ecx, dword ptr [0x10015678] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x007850b7u); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x795678u))); /* mov ecx, dword ptr [0x10015678] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea edx, [esp + 0x14] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x10u)); PUSH32(c, 0x007850c7u); call_indirect(c, t_); } /* call dword ptr [eax + 0x10] */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edx, dword ptr [ebp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x795678u))); /* mov ecx, dword ptr [0x10015678] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov edx, dword ptr [ebp + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4u)); PUSH32(c, 0x007850e3u); call_indirect(c, t_); } /* call dword ptr [eax + 4] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x20u)); /* lea eax, [ebp + 0x20] */
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
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    W32((uint32_t)(c->ebp), (uint32_t)((uint32_t)0x790304u)); /* mov dword ptr [ebp], 0x10010304 */
    c->eax = (uint32_t)(c->ebp); /* mov eax, ebp */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    c->esp += 4; return; /* ret  */
}

void f_00785140(CPU *c) { /* FUN_10005140 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00785148u); f_00785160(c); /* call 0x785160 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00785158; /* je 0x785158 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00785155u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00785158:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00785160(CPU *c) { /* FUN_10005160 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x790218u)); /* mov dword ptr [eax], 0x10010218 */
    c->ecx = (uint32_t)(R32((uint32_t)(0x795678u))); /* mov ecx, dword ptr [0x10015678] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x14u))); /* mov eax, dword ptr [eax + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x00785177u); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    c->esp += 4; return; /* ret  */
}

void f_00785180(CPU *c) { /* FUN_10005180 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov ecx, dword ptr [esi + 0xc] */
    { uint32_t d_ = c->ecx; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x0078518cu, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div ecx */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)c->ecx; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, ecx */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x8u)), c->eax); /* cmp dword ptr [esi + 8], eax */
    if (c->zf) goto L_007851af; /* je 0x7851af */
    { uint32_t v_ = 0x17u; PUSH32(c, v_); } /* push 0x17 */
    { uint32_t v_ = 0x7921a0u; PUSH32(c, v_); } /* push 0x100121a0 */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 8], eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x007851aau); f_00781090(c); /* call 0x781090 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
L_007851af:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_007851c0(CPU *c) { /* FUN_100051c0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    (void)sub32(c, c->eax, c->edx); /* cmp eax, edx */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 4], edx */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 8], edx */
    if (!c->zf) goto L_007851d7; /* jne 0x7851d7 */
    c->eax = (uint32_t)((uint32_t)0x10u); /* mov eax, 0x10 */
L_007851d7:;
    W32((uint32_t)(c->ecx + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 0xc], eax */
    c->esp += 8; return; /* ret 4 */
}

void f_007851e0(CPU *c) { /* FUN_100051e0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_007851ed; /* je 0x7851ed */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ecx, dword ptr [ecx + 4] */
    W8((uint32_t)(c->eax + c->ecx), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [eax + ecx], 0 */
L_007851ed:;
    c->esp += 4; return; /* ret  */
}

void f_007851f0(CPU *c) { /* FUN_100051f0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov esi, dword ptr [esp + 0xc] */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00785265; /* je 0x785265 */
    (void)sub8(c, R8((uint32_t)(c->esi)), (uint8_t)0x0u); /* cmp byte ptr [esi], 0 */
    if (c->zf) goto L_00785265; /* je 0x785265 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->esi); /* mov edi, esi */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0xffffffffu))); /* or ecx, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    while (c->ecx) { (void)sub8(c, ((uint8_t)c->eax), R8(c->edi)); c->edi += (c->df ? -1 : 1); c->ecx--; if (c->zf) break; } /* repne scasb al, byte ptr es:[edi] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0xcu))); /* mov edi, dword ptr [ebx + 0xc] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->ecx = (uint32_t)((uint32_t)~c->ecx); /* not ecx */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [ebx + 4], ecx */
    { uint32_t d_ = c->edi; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x00785218u, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div edi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov ecx, dword ptr [ebx + 8] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)c->edi; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, edi */
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
    if (c->zf) goto L_0078523d; /* je 0x78523d */
    { uint32_t v_ = 0x17u; PUSH32(c, v_); } /* push 0x17 */
    { uint32_t v_ = 0x7921a0u; PUSH32(c, v_); } /* push 0x100121a0 */
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 8], eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00785238u); f_00781090(c); /* call 0x781090 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
L_0078523d:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov ecx, dword ptr [ebx + 4] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov edi, dword ptr [ebx] */
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u))); /* and ecx, 3 */
    while (c->ecx) { W8(c->edi, R8(c->esi)); c->esi += (c->df ? -1 : 1); c->edi += (c->df ? -1 : 1); c->ecx--; } /* rep movsb byte ptr es:[edi], byte ptr [esi] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00785275; /* je 0x785275 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov ecx, dword ptr [ebx + 4] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W8((uint32_t)(c->eax + c->ecx), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [eax + ecx], 0 */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
L_00785265:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ebx + 4], 0 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00785275; /* je 0x785275 */
    W8((uint32_t)(c->eax), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [eax], 0 */
L_00785275:;
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
}

void f_00785280(CPU *c) { /* FUN_10005280 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov esi, dword ptr [esp + 0xc] */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_007852e4; /* je 0x7852e4 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0xcu))); /* mov ecx, dword ptr [ebx + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov eax, dword ptr [ebx + 4] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    { uint32_t d_ = c->ecx; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x0078529du, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div ecx */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)c->ecx; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, ecx */
    (void)sub32(c, R32((uint32_t)(c->ebx + 0x8u)), c->eax); /* cmp dword ptr [ebx + 8], eax */
    if (c->zf) goto L_007852c0; /* je 0x7852c0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov ecx, dword ptr [ebx] */
    { uint32_t v_ = 0x17u; PUSH32(c, v_); } /* push 0x17 */
    { uint32_t v_ = 0x7921a0u; PUSH32(c, v_); } /* push 0x100121a0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 8], eax */
    PUSH32(c, 0x007852bbu); f_00781090(c); /* call 0x781090 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
L_007852c0:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov ecx, dword ptr [ebx + 4] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi))); /* mov esi, dword ptr [esi] */
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov edi, dword ptr [ebx] */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u))); /* and ecx, 3 */
    while (c->ecx) { W8(c->edi, R8(c->esi)); c->esi += (c->df ? -1 : 1); c->edi += (c->df ? -1 : 1); c->ecx--; } /* rep movsb byte ptr es:[edi], byte ptr [esi] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_007852e4; /* je 0x7852e4 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov ecx, dword ptr [ebx + 4] */
    W8((uint32_t)(c->eax + c->ecx), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [eax + ecx], 0 */
L_007852e4:;
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
}

void f_007852f0(CPU *c) { /* FUN_100052f0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x78fb3fu; PUSH32(c, v_); } /* push 0x1000fb3f */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x1cu)); /* sub esp, 0x1c */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x10], esi */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x18], ebx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x40u))); /* mov eax, dword ptr [esp + 0x40] */
    c->ebp = (uint32_t)(logic32(c, 0)); /* xor ebp, ebp */
    c->ecx = (uint32_t)((uint32_t)0x10u); /* mov ecx, 0x10 */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    W32((uint32_t)(c->esp + 0x34u), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [esp + 0x34], 2 */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x1c], ebx */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0x20], ebp */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x24], ebx */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x28], ecx */
    if (c->zf) goto L_0078537c; /* je 0x78537c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x20u)); /* lea ecx, [esp + 0x20] */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x24], eax */
    PUSH32(c, 0x0078534du); f_00785180(c); /* call 0x785180 */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov ebp, dword ptr [esp + 0x20] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov ebx, dword ptr [esp + 0x1c] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x3cu))); /* mov esi, dword ptr [esp + 0x3c] */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->edi = (uint32_t)(c->ebx); /* mov edi, ebx */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u))); /* and ecx, 3 */
    while (c->ecx) { W8(c->edi, R8(c->esi)); c->esi += (c->df ? -1 : 1); c->edi += (c->df ? -1 : 1); c->ecx--; } /* rep movsb byte ptr es:[edi], byte ptr [esi] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x1cu)); /* lea ecx, [esp + 0x1c] */
    PUSH32(c, 0x00785374u); f_007851e0(c); /* call 0x7851e0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov ecx, dword ptr [esp + 0x28] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
L_0078537c:;
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x50u))); /* mov edi, dword ptr [esp + 0x50] */
    W8((uint32_t)(c->esp + 0x34u), (uint8_t)((uint8_t)0x3u)); /* mov byte ptr [esp + 0x34], 3 */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_007853e5; /* je 0x7853e5 */
    c->eax = (uint32_t)((uint32_t)(c->edi + c->ebp)); /* lea eax, [edi + ebp] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    { uint32_t d_ = c->ecx; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x00785392u, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div ecx */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)c->ecx; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, ecx */
    (void)sub32(c, R32((uint32_t)(c->esp + 0x24u)), c->eax); /* cmp dword ptr [esp + 0x24], eax */
    if (c->zf) goto L_007853b9; /* je 0x7853b9 */
    { uint32_t v_ = 0x17u; PUSH32(c, v_); } /* push 0x17 */
    { uint32_t v_ = 0x7921a0u; PUSH32(c, v_); } /* push 0x100121a0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    W32((uint32_t)(c->esp + 0x34u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x34], eax */
    PUSH32(c, 0x007853b0u); f_00781090(c); /* call 0x781090 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x1c], ebx */
L_007853b9:;
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x4cu))); /* mov esi, dword ptr [esp + 0x4c] */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    c->edi = (uint32_t)((uint32_t)(c->ebx + c->ebp)); /* lea edi, [ebx + ebp] */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ebp, dword ptr [esp + 0x14] */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u))); /* and ecx, 3 */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0x20], ebp */
    while (c->ecx) { W8(c->edi, R8(c->esi)); c->esi += (c->df ? -1 : 1); c->edi += (c->df ? -1 : 1); c->ecx--; } /* rep movsb byte ptr es:[edi], byte ptr [esi] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x1cu)); /* lea ecx, [esp + 0x1c] */
    PUSH32(c, 0x007853e1u); f_007851e0(c); /* call 0x7851e0 */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
L_007853e5:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)((uint32_t)0x10u)); /* mov dword ptr [esi + 0xc], 0x10 */
    (void)sub32(c, c->ebp, c->eax); /* cmp ebp, eax */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 4], eax */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 8], eax */
    if (c->zf) goto L_00785406; /* je 0x785406 */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x1cu)); /* lea eax, [esp + 0x1c] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00785406u); f_00785280(c); /* call 0x785280 */
L_00785406:;
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [esp + 0x18], 1 */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    W8((uint32_t)(c->esp + 0x34u), (uint8_t)((uint8_t)0x2u)); /* mov byte ptr [esp + 0x34], 2 */
    if (c->zf) goto L_00785420; /* je 0x785420 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x0078541du); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00785420:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x3cu))); /* mov eax, dword ptr [esp + 0x3c] */
    W8((uint32_t)(c->esp + 0x34u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esp + 0x34], 1 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00785436; /* je 0x785436 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00785433u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00785436:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4cu))); /* mov eax, dword ptr [esp + 0x4c] */
    W8((uint32_t)(c->esp + 0x34u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esp + 0x34], 0 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0078544c; /* je 0x78544c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00785449u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_0078544c:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov ecx, dword ptr [esp + 0x2c] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x28u)); /* add esp, 0x28 */
    c->esp += 36; return; /* ret 0x20 */
}

void f_00785470(CPU *c) { /* FUN_10005470 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x400u)); /* sub esp, 0x400 */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x40cu)); /* lea eax, [esp + 0x40c] */
    c->edx = (uint32_t)((uint32_t)(c->esp)); /* lea edx, [esp] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x0078548eu); f_00786d8f(c); /* call 0x786d8f */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x10u))); /* mov al, byte ptr [esp + 0x10] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_0078550b; /* je 0x78550b */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)((uint32_t)(c->esp + 0xcu)); /* lea edi, [esp + 0xc] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0xffffffffu))); /* or ecx, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x410u))); /* mov ebx, dword ptr [esp + 0x410] */
    while (c->ecx) { (void)sub8(c, ((uint8_t)c->eax), R8(c->edi)); c->edi += (c->df ? -1 : 1); c->ecx--; if (c->zf) break; } /* repne scasb al, byte ptr es:[edi] */
    c->ecx = (uint32_t)((uint32_t)~c->ecx); /* not ecx */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0xcu))); /* mov ecx, dword ptr [ebx + 0xc] */
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 4], eax */
    { uint32_t d_ = c->ecx; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x007854bau, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div ecx */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)c->ecx; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, ecx */
    (void)sub32(c, R32((uint32_t)(c->ebx + 0x8u)), c->eax); /* cmp dword ptr [ebx + 8], eax */
    if (c->zf) goto L_007854dd; /* je 0x7854dd */
    { uint32_t v_ = 0x17u; PUSH32(c, v_); } /* push 0x17 */
    { uint32_t v_ = 0x7921a0u; PUSH32(c, v_); } /* push 0x100121a0 */
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 8], eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x007854d8u); f_00781090(c); /* call 0x781090 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
L_007854dd:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov ecx, dword ptr [ebx + 4] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov edi, dword ptr [ebx] */
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    c->esi = (uint32_t)((uint32_t)(c->esp + 0xcu)); /* lea esi, [esp + 0xc] */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u))); /* and ecx, 3 */
    while (c->ecx) { W8(c->edi, R8(c->esi)); c->esi += (c->df ? -1 : 1); c->edi += (c->df ? -1 : 1); c->ecx--; } /* rep movsb byte ptr es:[edi], byte ptr [esi] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    if (c->zf) goto L_00785522; /* je 0x785522 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov ecx, dword ptr [ebx + 4] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    W8((uint32_t)(c->eax + c->ecx), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [eax + ecx], 0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x400u)); /* add esp, 0x400 */
    c->esp += 4; return; /* ret  */
L_0078550b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x408u))); /* mov eax, dword ptr [esp + 0x408] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [eax + 4], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00785522; /* je 0x785522 */
    W8((uint32_t)(c->eax), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [eax], 0 */
L_00785522:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x400u)); /* add esp, 0x400 */
    c->esp += 4; return; /* ret  */
}

void f_00785530(CPU *c) { /* FUN_10005530 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_00785591; /* je 0x785591 */
    c->edi = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov edi, dword ptr [ecx + 4] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ebx, dword ptr [esp + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    c->esi = (uint32_t)((uint32_t)(c->edi + 0xffffffffu)); /* lea esi, [edi - 1] */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (!c->cf) goto L_00785591; /* jae 0x785591 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->cf) goto L_00785589; /* jae 0x785589 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov dl, byte ptr [edx] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov ecx, dword ptr [ecx] */
L_00785555:;
    (void)sub8(c, R8((uint32_t)(c->ecx + c->esi)), ((uint8_t)c->edx)); /* cmp byte ptr [ecx + esi], dl */
    if (c->zf) goto L_00785567; /* je 0x785567 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (c->cf) goto L_00785555; /* jb 0x785555 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
L_00785567:;
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edi, dword ptr [esp + 0x10] */
    c->edx = (uint32_t)(c->esi); /* mov edx, esi */
    c->edx = (uint32_t)(sub32(c, c->edx, c->eax)); /* sub edx, eax */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00785579u); f_00786950(c); /* call 0x786950 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov ecx, dword ptr [ebx] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    W8((uint32_t)(c->eax + c->edi), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [eax + edi], 0 */
    W32((uint32_t)(c->ebx), (uint32_t)(c->esi)); /* mov dword ptr [ebx], esi */
L_00785589:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
L_00785591:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
}

void f_007855a0(CPU *c) { /* FUN_100055a0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov esi, dword ptr [esp + 0x14] */
    c->ebp = (uint32_t)(c->ecx); /* mov ebp, ecx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    W32((uint32_t)(c->ebp), (uint32_t)(c->eax)); /* mov dword ptr [ebp], eax */
    W32((uint32_t)(c->ebp + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 4], eax */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 8], eax */
    if (!c->zf) goto L_007855bd; /* jne 0x7855bd */
    c->esi = (uint32_t)((uint32_t)0x10u); /* mov esi, 0x10 */
L_007855bd:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ebx, dword ptr [esp + 0x10] */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
    (void)sub32(c, c->ebx, c->eax); /* cmp ebx, eax */
    if (c->zf) goto L_00785628; /* je 0x785628 */
    (void)sub8(c, R8((uint32_t)(c->ebx)), (uint8_t)0x0u); /* cmp byte ptr [ebx], 0 */
    if (c->zf) goto L_00785628; /* je 0x785628 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ebx); /* mov edi, ebx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0xffffffffu))); /* or ecx, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    while (c->ecx) { (void)sub8(c, ((uint8_t)c->eax), R8(c->edi)); c->edi += (c->df ? -1 : 1); c->ecx--; if (c->zf) break; } /* repne scasb al, byte ptr es:[edi] */
    c->ecx = (uint32_t)((uint32_t)~c->ecx); /* not ecx */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    W32((uint32_t)(c->ebp + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 4], eax */
    { uint32_t d_ = c->esi; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x007855e1u, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div esi */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)c->esi; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, esi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00785603; /* je 0x785603 */
    { uint32_t v_ = 0x17u; PUSH32(c, v_); } /* push 0x17 */
    { uint32_t v_ = 0x7921a0u; PUSH32(c, v_); } /* push 0x100121a0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 8], eax */
    PUSH32(c, 0x007855fdu); f_00781090(c); /* call 0x781090 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    W32((uint32_t)(c->ebp), (uint32_t)(c->eax)); /* mov dword ptr [ebp], eax */
L_00785603:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x4u))); /* mov ecx, dword ptr [ebp + 4] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov edi, dword ptr [ebp] */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->esi = (uint32_t)(c->ebx); /* mov esi, ebx */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u))); /* and ecx, 3 */
    while (c->ecx) { W8(c->edi, R8(c->esi)); c->esi += (c->df ? -1 : 1); c->edi += (c->df ? -1 : 1); c->ecx--; } /* rep movsb byte ptr es:[edi], byte ptr [esi] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov eax, dword ptr [ebp] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00785628; /* je 0x785628 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x4u))); /* mov ecx, dword ptr [ebp + 4] */
    W8((uint32_t)(c->eax + c->ecx), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [eax + ecx], 0 */
L_00785628:;
    c->eax = (uint32_t)(c->ebp); /* mov eax, ebp */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 12; return; /* ret 8 */
}

void f_00785630(CPU *c) { /* FUN_10005630 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->ecx); /* mov ebp, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    W32((uint32_t)(c->ebp), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ebp], 0 */
    W32((uint32_t)(c->ebp + 0x4u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ebp + 4], 0 */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ebp + 8], 0 */
    if (!c->zf) goto L_00785656; /* jne 0x785656 */
    c->ecx = (uint32_t)((uint32_t)0x10u); /* mov ecx, 0x10 */
L_00785656:;
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov esi, dword ptr [esp + 0xc] */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [ebp + 0xc], ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_007856bb; /* je 0x7856bb */
    W32((uint32_t)(c->ebp + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_007856bb; /* je 0x7856bb */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x4u))); /* mov eax, dword ptr [ebp + 4] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    { uint32_t d_ = c->ecx; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x00785673u, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div ecx */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)c->ecx; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00785695; /* je 0x785695 */
    { uint32_t v_ = 0x17u; PUSH32(c, v_); } /* push 0x17 */
    { uint32_t v_ = 0x7921a0u; PUSH32(c, v_); } /* push 0x100121a0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 8], eax */
    PUSH32(c, 0x0078568fu); f_00781090(c); /* call 0x781090 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    W32((uint32_t)(c->ebp), (uint32_t)(c->eax)); /* mov dword ptr [ebp], eax */
L_00785695:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x4u))); /* mov ecx, dword ptr [ebp + 4] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi))); /* mov esi, dword ptr [esi] */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov edi, dword ptr [ebp] */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u))); /* and ecx, 3 */
    while (c->ecx) { W8(c->edi, R8(c->esi)); c->esi += (c->df ? -1 : 1); c->edi += (c->df ? -1 : 1); c->ecx--; } /* rep movsb byte ptr es:[edi], byte ptr [esi] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov eax, dword ptr [ebp] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_007856bb; /* je 0x7856bb */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x4u))); /* mov ecx, dword ptr [ebp + 4] */
    W8((uint32_t)(c->eax + c->ecx), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [eax + ecx], 0 */
L_007856bb:;
    c->eax = (uint32_t)(c->ebp); /* mov eax, ebp */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 12; return; /* ret 8 */
}

void f_007856d0(CPU *c) { /* FUN_100056d0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_007856e2; /* je 0x7856e2 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x007856dfu); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_007856e2:;
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi], 0 */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 4], 0 */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 8], 0 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00785700(CPU *c) { /* PTR_00785700 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    W32((uint32_t)(c->eax + 0x14u), (uint32_t)((uint32_t)0x790344u)); /* mov dword ptr [eax + 0x14], 0x10010344 */
    W32((uint32_t)(c->eax + 0x18u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x18], ecx */
    W32((uint32_t)(c->eax + 0x20u), (uint32_t)((uint32_t)0x8u)); /* mov dword ptr [eax + 0x20], 8 */
    W32((uint32_t)(c->eax + 0x24u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x24], ecx */
    W32((uint32_t)(c->eax + 0x1cu), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x1c], ecx */
    W32((uint32_t)(c->eax + 0x10u), (uint32_t)((uint32_t)0x790338u)); /* mov dword ptr [eax + 0x10], 0x10010338 */
    c->esp += 4; return; /* ret  */
}

void f_00785730(CPU *c) { /* FUN_10005730 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x790344u)); /* mov dword ptr [esi], 0x10010344 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 0x10], 0 */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 8], 0 */
    if (c->zf) goto L_00785757; /* je 0x785757 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00785754u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00785757:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x8u))); /* mov al, byte ptr [esp + 8] */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 4], 0 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    if (c->zf) goto L_0078576f; /* je 0x78576f */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x0078576cu); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_0078576f:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00785780(CPU *c) { /* FUN_10005780 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x78fb79u; PUSH32(c, v_); } /* push 0x1000fb79 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 8], esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x5cu))); /* mov eax, dword ptr [esi + 0x5c] */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0x3u)); /* mov dword ptr [esp + 0x14], 3 */
    if (c->zf) goto L_007857b8; /* je 0x7857b8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x007857b5u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_007857b8:;
    W32((uint32_t)(c->esi + 0x5cu), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x5c], ebx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4cu))); /* mov eax, dword ptr [esi + 0x4c] */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    W8((uint32_t)(c->esp + 0x14u), (uint8_t)((uint8_t)0x2u)); /* mov byte ptr [esp + 0x14], 2 */
    if (c->zf) goto L_007857d0; /* je 0x7857d0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x007857cdu); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_007857d0:;
    W32((uint32_t)(c->esi + 0x4cu), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x4c], ebx */
    W32((uint32_t)(c->esi + 0x50u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x50], ebx */
    W32((uint32_t)(c->esi + 0x54u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x54], ebx */
    W32((uint32_t)(c->esi + 0x34u), (uint32_t)((uint32_t)0x790278u)); /* mov dword ptr [esi + 0x34], 0x10010278 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x3cu))); /* mov eax, dword ptr [esi + 0x3c] */
    W8((uint32_t)(c->esp + 0x14u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esp + 0x14], 1 */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    W32((uint32_t)(c->esi + 0x38u), (uint32_t)((uint32_t)0x790268u)); /* mov dword ptr [esi + 0x38], 0x10010268 */
    W32((uint32_t)(c->esi + 0x48u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x48], ebx */
    W32((uint32_t)(c->esi + 0x40u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x40], ebx */
    if (c->zf) goto L_00785818; /* je 0x785818 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0xfffffffcu))); /* mov ecx, dword ptr [eax - 4] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)((uint32_t)(c->eax + 0xfffffffcu)); /* lea edi, [eax - 4] */
    { uint32_t v_ = 0x785890u; PUSH32(c, v_); } /* push 0x10005890 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x28u; PUSH32(c, v_); } /* push 0x28 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0078580eu); f_00786c2f(c); /* call 0x786c2f */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00785814u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_00785818:;
    W32((uint32_t)(c->esi + 0x3cu), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x3c], ebx */
    W32((uint32_t)(c->esi + 0x1cu), (uint32_t)((uint32_t)0x79025cu)); /* mov dword ptr [esi + 0x1c], 0x1001025c */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov eax, dword ptr [esi + 0x24] */
    W8((uint32_t)(c->esp + 0x14u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [esp + 0x14], bl */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    W32((uint32_t)(c->esi + 0x20u), (uint32_t)((uint32_t)0x79024cu)); /* mov dword ptr [esi + 0x20], 0x1001024c */
    W32((uint32_t)(c->esi + 0x30u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x30], ebx */
    W32((uint32_t)(c->esi + 0x28u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x28], ebx */
    if (c->zf) goto L_00785843; /* je 0x785843 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00785840u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00785843:;
    W32((uint32_t)(c->esi + 0x24u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x24], ebx */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x790198u)); /* mov dword ptr [esi], 0x10010198 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [esp + 0x14], 0xffffffff */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)((uint32_t)0x79023cu)); /* mov dword ptr [esi + 4], 0x1001023c */
    W32((uint32_t)(c->esi + 0x14u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x14], ebx */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0xc], ebx */
    if (c->zf) goto L_00785871; /* je 0x785871 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0078586eu); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00785871:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 8], ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_00785890(CPU *c) { /* FUN_10005890 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)((uint32_t)0x790338u)); /* mov dword ptr [esi + 0x10], 0x10010338 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x18u))); /* mov eax, dword ptr [esi + 0x18] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    W32((uint32_t)(c->esi + 0x14u), (uint32_t)((uint32_t)0x790344u)); /* mov dword ptr [esi + 0x14], 0x10010344 */
    W32((uint32_t)(c->esi + 0x24u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0x24], edi */
    W32((uint32_t)(c->esi + 0x1cu), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0x1c], edi */
    if (c->zf) goto L_007858ba; /* je 0x7858ba */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x007858b7u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_007858ba:;
    W32((uint32_t)(c->esi + 0x18u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0x18], edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_007858c0(CPU *c) { /* FUN_100058c0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x007858c8u); f_007858e0(c); /* call 0x7858e0 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_007858d8; /* je 0x7858d8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x007858d5u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_007858d8:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_007858e0(CPU *c) { /* FUN_100058e0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x790338u)); /* mov dword ptr [esi], 0x10010338 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)((uint32_t)0x790344u)); /* mov dword ptr [esi + 4], 0x10010344 */
    W32((uint32_t)(c->esi + 0x14u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0x14], edi */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0xc], edi */
    if (c->zf) goto L_00785909; /* je 0x785909 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00785906u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00785909:;
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 8], edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00785910(CPU *c) { /* FUN_10005910 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov ebx, dword ptr [esp + 0x20] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov ebp, dword ptr [esp + 0x28] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x40u))); /* mov eax, dword ptr [esi + 0x40] */
    (void)sub32(c, c->ebx, c->eax); /* cmp ebx, eax */
    if (!c->cf) goto L_0078592c; /* jae 0x78592c */
    (void)sub32(c, c->ebp, c->eax); /* cmp ebp, eax */
    if (c->cf) goto L_0078594f; /* jb 0x78594f */
L_0078592c:;
    c->eax = (uint32_t)(R32((uint32_t)(0x795678u))); /* mov eax, dword ptr [0x10015678] */
    { uint32_t v_ = 0x7924c4u; PUSH32(c, v_); } /* push 0x100124c4 */
    { uint32_t v_ = 0xfdu; PUSH32(c, v_); } /* push 0xfd */
    { uint32_t v_ = 0x79212cu; PUSH32(c, v_); } /* push 0x1001212c */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x7920b0u; PUSH32(c, v_); } /* push 0x100120b0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x0078594bu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x0078594eu, "int3"); /* int3  */
L_0078594f:;
    (void)sub32(c, c->ebp, R32((uint32_t)(c->esi + 0x40u))); /* cmp ebp, dword ptr [esi + 0x40] */
    if (c->cf) goto L_00785977; /* jb 0x785977 */
    c->eax = (uint32_t)(R32((uint32_t)(0x795678u))); /* mov eax, dword ptr [0x10015678] */
    { uint32_t v_ = 0x792160u; PUSH32(c, v_); } /* push 0x10012160 */
    { uint32_t v_ = 0x94u; PUSH32(c, v_); } /* push 0x94 */
    { uint32_t v_ = 0x79212cu; PUSH32(c, v_); } /* push 0x1001212c */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0x7920b0u; PUSH32(c, v_); } /* push 0x100120b0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00785973u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00785976u, "int3"); /* int3  */
L_00785977:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x3cu))); /* mov ecx, dword ptr [esi + 0x3c] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + c->ebp * 4)); /* lea eax, [ebp + ebp*4] */
    c->edx = (uint32_t)((uint32_t)(c->ecx + c->eax * 8)); /* lea edx, [ecx + eax*8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + c->eax * 8))); /* mov eax, dword ptr [ecx + eax*8] */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x1c], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x40u))); /* mov eax, dword ptr [esi + 0x40] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov ecx, dword ptr [edx + 4] */
    (void)sub32(c, c->ebx, c->eax); /* cmp ebx, eax */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x20], ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov edx, dword ptr [edx + 8] */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x24], edx */
    if (c->cf) goto L_007859c0; /* jb 0x7859c0 */
    c->eax = (uint32_t)(R32((uint32_t)(0x795678u))); /* mov eax, dword ptr [0x10015678] */
    { uint32_t v_ = 0x792160u; PUSH32(c, v_); } /* push 0x10012160 */
    { uint32_t v_ = 0x94u; PUSH32(c, v_); } /* push 0x94 */
    { uint32_t v_ = 0x79212cu; PUSH32(c, v_); } /* push 0x1001212c */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x7920b0u; PUSH32(c, v_); } /* push 0x100120b0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x007859bcu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x007859bfu, "int3"); /* int3  */
L_007859c0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x3cu))); /* mov eax, dword ptr [esi + 0x3c] */
    c->edx = (uint32_t)((uint32_t)(c->ebx + c->ebx * 4)); /* lea edx, [ebx + ebx*4] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi + 0x28u))); /* mov edi, dword ptr [esi + 0x28] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->edx * 8)); /* lea ecx, [eax + edx*8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + c->edx * 8))); /* mov edx, dword ptr [eax + edx*8] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x10], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov eax, dword ptr [ecx + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fsub dword ptr [esp + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov ecx, dword ptr [ecx + 8] */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x20u))); /* fsub dword ptr [esp + 0x20] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x18], ecx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x24u))); /* fsub dword ptr [esp + 0x24] */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    { double v_ = ST(2); FPUSH(c, v_); } /* fld st(2) */
    ST(0) = FPRES(c, ST(0) * ST(3)); /* fmul st(3) */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    { double v_ = ST(3); FPUSH(c, v_); } /* fld st(3) */
    ST(0) = FPRES(c, ST(0) * ST(4)); /* fmul st(4) */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, sqrt(ST(0))); /* fsqrt  */
    ST(3) = ST(0); FPOP(c); /* fstp st(3) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    WF32((uint32_t)(c->esp + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x24] */
    if ((c->cf || c->zf)) goto L_00785a41; /* jbe 0x785a41 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov ecx, dword ptr [esi + 0x24] */
L_00785a1e:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    (void)sub32(c, c->edx, c->ebx); /* cmp edx, ebx */
    if (!c->zf) goto L_00785a29; /* jne 0x785a29 */
    (void)sub32(c, R32((uint32_t)(c->ecx + 0x4u)), c->ebp); /* cmp dword ptr [ecx + 4], ebp */
    if (c->zf) goto L_00785a3c; /* je 0x785a3c */
L_00785a29:;
    (void)sub32(c, c->edx, c->ebp); /* cmp edx, ebp */
    if (!c->zf) goto L_00785a32; /* jne 0x785a32 */
    (void)sub32(c, R32((uint32_t)(c->ecx + 0x4u)), c->ebx); /* cmp dword ptr [ecx + 4], ebx */
    if (c->zf) goto L_00785a3c; /* je 0x785a3c */
L_00785a32:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0xcu)); /* add ecx, 0xc */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (c->cf) goto L_00785a1e; /* jb 0x785a1e */
    goto L_00785a41; /* jmp 0x785a41 */
L_00785a3c:;
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (!c->zf) goto L_00785a74; /* jne 0x785a74 */
L_00785a41:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x28u))); /* mov eax, dword ptr [esi + 0x28] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov edx, dword ptr [esi + 0x20] */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x20u)); /* lea edi, [esi + 0x20] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x00785a51u); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x28u))); /* mov eax, dword ptr [esi + 0x28] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov edx, dword ptr [esi + 0x24] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea ecx, [eax + eax*2] */
    c->eax = (uint32_t)((uint32_t)(c->edx + c->ecx * 4)); /* lea eax, [edx + ecx*4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov ecx, dword ptr [esp + 0x24] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ebx)); /* mov dword ptr [eax], ebx */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ebp)); /* mov dword ptr [eax + 4], ebp */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov edx, dword ptr [edi + 8] */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    W32((uint32_t)(c->edi + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [edi + 8], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x28u))); /* mov eax, dword ptr [esi + 0x28] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
L_00785a74:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    c->esp += 12; return; /* ret 8 */
}

void f_00785a80(CPU *c) { /* FUN_10005a80 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    (void)sub32(c, c->esi, R32((uint32_t)(c->edi + 0x28u))); /* cmp esi, dword ptr [edi + 0x28] */
    if (c->cf) goto L_00785ab0; /* jb 0x785ab0 */
    c->eax = (uint32_t)(R32((uint32_t)(0x795678u))); /* mov eax, dword ptr [0x10015678] */
    { uint32_t v_ = 0x792110u; PUSH32(c, v_); } /* push 0x10012110 */
    { uint32_t v_ = 0x11du; PUSH32(c, v_); } /* push 0x11d */
    { uint32_t v_ = 0x79212cu; PUSH32(c, v_); } /* push 0x1001212c */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x7920b0u; PUSH32(c, v_); } /* push 0x100120b0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00785aacu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00785aafu, "int3"); /* int3  */
L_00785ab0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x24u))); /* mov eax, dword ptr [edi + 0x24] */
    c->edx = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea edx, [esi + esi*2] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->edx * 4)); /* lea ecx, [eax + edx*4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    (void)sub32(c, c->eax, c->edx); /* cmp eax, edx */
    if (!c->zf) goto L_00785ac8; /* jne 0x785ac8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov eax, dword ptr [ecx + 4] */
L_00785ac8:;
    c->esp += 12; return; /* ret 8 */
}

void f_00785ad0(CPU *c) { /* FUN_10005ad0 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov edi, dword ptr [esp + 0x24] */
    (void)sub32(c, c->edi, R32((uint32_t)(c->esi + 0x40u))); /* cmp edi, dword ptr [esi + 0x40] */
    if (c->cf) goto L_00785b03; /* jb 0x785b03 */
    c->eax = (uint32_t)(R32((uint32_t)(0x795678u))); /* mov eax, dword ptr [0x10015678] */
    { uint32_t v_ = 0x792160u; PUSH32(c, v_); } /* push 0x10012160 */
    { uint32_t v_ = 0x94u; PUSH32(c, v_); } /* push 0x94 */
    { uint32_t v_ = 0x79212cu; PUSH32(c, v_); } /* push 0x1001212c */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x7920b0u; PUSH32(c, v_); } /* push 0x100120b0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00785affu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00785b02u, "int3"); /* int3  */
L_00785b03:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x3cu))); /* mov eax, dword ptr [esi + 0x3c] */
    c->edx = (uint32_t)((uint32_t)(c->edi + c->edi * 4)); /* lea edx, [edi + edi*4] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov edi, dword ptr [esp + 0x28] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->edx * 8)); /* lea ecx, [eax + edx*8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + c->edx * 8))); /* mov edx, dword ptr [eax + edx*8] */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x14], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov eax, dword ptr [ecx + 4] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x18], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x40u))); /* mov eax, dword ptr [esi + 0x40] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov ecx, dword ptr [ecx + 8] */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x1c], ecx */
    if (c->cf) goto L_00785b4f; /* jb 0x785b4f */
    c->eax = (uint32_t)(R32((uint32_t)(0x795678u))); /* mov eax, dword ptr [0x10015678] */
    { uint32_t v_ = 0x792160u; PUSH32(c, v_); } /* push 0x10012160 */
    { uint32_t v_ = 0x94u; PUSH32(c, v_); } /* push 0x94 */
    { uint32_t v_ = 0x79212cu; PUSH32(c, v_); } /* push 0x1001212c */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0x7920b0u; PUSH32(c, v_); } /* push 0x100120b0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00785b4bu); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00785b4eu, "int3"); /* int3  */
L_00785b4f:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x3cu))); /* mov ecx, dword ptr [esi + 0x3c] */
    c->eax = (uint32_t)((uint32_t)(c->edi + c->edi * 4)); /* lea eax, [edi + edi*4] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->edx = (uint32_t)((uint32_t)(c->ecx + c->eax * 8)); /* lea edx, [ecx + eax*8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + c->eax * 8))); /* mov eax, dword ptr [ecx + eax*8] */
    W32((uint32_t)(c->esp), (uint32_t)(c->eax)); /* mov dword ptr [esp], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov ecx, dword ptr [edx + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp))); /* fld dword ptr [esp] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0xcu))); /* fsub dword ptr [esp + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov edx, dword ptr [edx + 8] */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 4], ecx */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x4u))); /* fld dword ptr [esp + 4] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x10u))); /* fsub dword ptr [esp + 0x10] */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 8], edx */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x8u))); /* fld dword ptr [esp + 8] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x14u))); /* fsub dword ptr [esp + 0x14] */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    { double v_ = ST(3); FPUSH(c, v_); } /* fld st(3) */
    ST(0) = FPRES(c, ST(0) * ST(4)); /* fmul st(4) */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    { double v_ = ST(2); FPUSH(c, v_); } /* fld st(2) */
    ST(0) = FPRES(c, ST(0) * ST(3)); /* fmul st(3) */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, sqrt(ST(0))); /* fsqrt  */
    ST(3) = ST(0); FPOP(c); /* fstp st(3) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    c->esp += 12; return; /* ret 8 */
}

void f_00785bb0(CPU *c) { /* FUN_10005bb0 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x10u)); /* sub esp, 0x10 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x14], edi */
    PUSH32(c, 0x00785bc4u); f_00781030(c); /* call 0x781030 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_00785bee; /* je 0x785bee */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)((uint32_t)0x790360u)); /* mov dword ptr [eax + 4], 0x10010360 */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 8], ebx */
    W32((uint32_t)(c->eax + 0x10u), (uint32_t)((uint32_t)0xc8u)); /* mov dword ptr [eax + 0x10], 0xc8 */
    W32((uint32_t)(c->eax + 0x14u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x14], ebx */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0xc], ebx */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x790354u)); /* mov dword ptr [eax], 0x10010354 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    goto L_00785bf0; /* jmp 0x785bf0 */
L_00785bee:;
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_00785bf0:;
    (void)sub32(c, R32((uint32_t)(c->edi + 0x40u)), c->ebx); /* cmp dword ptr [edi + 0x40], ebx */
    if ((c->cf || c->zf)) goto L_00785c6e; /* jbe 0x785c6e */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov ebp, dword ptr [esp + 0x24] */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x4u)); /* lea edi, [esi + 4] */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x24], ebx */
L_00785c00:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov ecx, dword ptr [esi + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0xcu)); PUSH32(c, 0x00785c0cu); call_indirect(c, t_); } /* call dword ptr [eax + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov edx, dword ptr [edi + 8] */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    W32((uint32_t)(c->edi + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [edi + 8], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    FPUSH(c, (double)RF32((uint32_t)(c->ebp))); /* fld dword ptr [ebp] */
    c->edx = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea edx, [eax + eax*2] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->edx * 4 + 0xfffffff4u)); /* lea ecx, [eax + edx*4 - 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x3cu))); /* mov eax, dword ptr [edx + 0x3c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov edx, dword ptr [esp + 0x24] */
    c->eax = (uint32_t)(add32(c, c->eax, c->edx)); /* add eax, edx */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x28u)); /* add edx, 0x28 */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x24], edx */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->eax))); /* fsub dword ptr [eax] */
    FPUSH(c, (double)RF32((uint32_t)(c->ebp + 0x4u))); /* fld dword ptr [ebp + 4] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->eax + 0x4u))); /* fsub dword ptr [eax + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->ebp + 0x8u))); /* fld dword ptr [ebp + 8] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->eax + 0x8u))); /* fsub dword ptr [eax + 8] */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    { double v_ = ST(3); FPUSH(c, v_); } /* fld st(3) */
    ST(0) = FPRES(c, ST(0) * ST(4)); /* fmul st(4) */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->ebx)); /* mov dword ptr [ecx], ebx */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    { double v_ = ST(2); FPUSH(c, v_); } /* fld st(2) */
    ST(0) = FPRES(c, ST(0) * ST(3)); /* fmul st(3) */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, sqrt(ST(0))); /* fsqrt  */
    ST(3) = ST(0); FPOP(c); /* fstp st(3) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    WF32((uint32_t)(c->ecx + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ecx + 4] */
    (void)sub32(c, c->ebx, R32((uint32_t)(c->eax + 0x40u))); /* cmp ebx, dword ptr [eax + 0x40] */
    if (c->cf) goto L_00785c00; /* jb 0x785c00 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
L_00785c6e:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov ecx, dword ptr [esi + 0xc] */
    (void)sub32(c, c->ecx, (uint32_t)0x2u); /* cmp ecx, 2 */
    if (c->cf) goto L_00785d53; /* jb 0x785d53 */
    (void)sub32(c, c->ecx, c->ebx); /* cmp ecx, ebx */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x14], ebx */
    if ((c->cf || c->zf)) goto L_00785d53; /* jbe 0x785d53 */
    c->ebp = (uint32_t)(logic32(c, 0)); /* xor ebp, ebp */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0x18], ebp */
L_00785c8c:;
    c->edx = (uint32_t)((uint32_t)(c->ebx + 0x1u)); /* lea edx, [ebx + 1] */
    (void)sub32(c, c->edx, c->ecx); /* cmp edx, ecx */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x1c], edx */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x24], edx */
    if (!c->cf) goto L_00785d3b; /* jae 0x785d3b */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0xcu)); /* lea edi, [ebp + 0xc] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x10], edi */
L_00785ca6:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->edi + c->eax + 0x4u))); /* fld dword ptr [edi + eax + 4] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->eax + c->ebp + 0x4u))); FPOP(c); /* fcomp dword ptr [eax + ebp + 4] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00785d20; /* jp 0x785d20 */
    (void)sub32(c, c->edx, c->ecx); /* cmp edx, ecx */
    if (!c->cf) goto L_00785cc0; /* jae 0x785cc0 */
    (void)sub32(c, c->ebx, c->ecx); /* cmp ebx, ecx */
    if (c->cf) goto L_00785ce0; /* jb 0x785ce0 */
L_00785cc0:;
    c->eax = (uint32_t)(R32((uint32_t)(0x795678u))); /* mov eax, dword ptr [0x10015678] */
    { uint32_t v_ = 0x792544u; PUSH32(c, v_); } /* push 0x10012544 */
    { uint32_t v_ = 0x7du; PUSH32(c, v_); } /* push 0x7d */
    { uint32_t v_ = 0x792500u; PUSH32(c, v_); } /* push 0x10012500 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x7920b0u; PUSH32(c, v_); } /* push 0x100120b0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00785cdcu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00785cdfu, "int3"); /* int3  */
L_00785ce0:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ecx, dword ptr [esi + 8] */
    c->ebp = (uint32_t)(add32(c, c->ebp, c->ecx)); /* add ebp, ecx */
    c->eax = (uint32_t)((uint32_t)(c->edi + c->ecx)); /* lea eax, [edi + ecx] */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov ecx, dword ptr [ebp] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov edx, dword ptr [ebx] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov edi, dword ptr [ebx + 4] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov ebx, dword ptr [ebx + 8] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x4u))); /* mov ecx, dword ptr [ebp + 4] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 4], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov ebp, dword ptr [esp + 0x18] */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    c->eax = (uint32_t)(add32(c, c->eax, c->ebp)); /* add eax, ebp */
    W32((uint32_t)(c->eax), (uint32_t)(c->edx)); /* mov dword ptr [eax], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov edx, dword ptr [esp + 0x24] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->edi)); /* mov dword ptr [eax + 4], edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edi, dword ptr [esp + 0x10] */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 8], ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ebx, dword ptr [esp + 0x14] */
L_00785d20:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov ecx, dword ptr [esi + 0xc] */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0xcu)); /* add edi, 0xc */
    (void)sub32(c, c->edx, c->ecx); /* cmp edx, ecx */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x24], edx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x10], edi */
    if (c->cf) goto L_00785ca6; /* jb 0x785ca6 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov edx, dword ptr [esp + 0x1c] */
L_00785d3b:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov ecx, dword ptr [esi + 0xc] */
    c->ebx = (uint32_t)(c->edx); /* mov ebx, edx */
    c->ebp = (uint32_t)(add32(c, c->ebp, (uint32_t)0xcu)); /* add ebp, 0xc */
    (void)sub32(c, c->ebx, c->ecx); /* cmp ebx, ecx */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x14], ebx */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0x18], ebp */
    if (c->cf) goto L_00785c8c; /* jb 0x785c8c */
L_00785d53:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 8; return; /* ret 4 */
}

void f_00785d60(CPU *c) { /* PTR_00785d60 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ecx + 8], 0 */
    c->esp += 4; return; /* ret  */
}

void f_00785d70(CPU *c) { /* FUN_10005d70 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0x10], edi */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 8], edi */
    if (c->zf) goto L_00785d8c; /* je 0x785d8c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00785d89u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00785d8c:;
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 4], edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00785da0(CPU *c) { /* FUN_10005da0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00785da8u); f_00785dc0(c); /* call 0x785dc0 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00785db8; /* je 0x785db8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00785db5u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00785db8:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00785dc0(CPU *c) { /* FUN_10005dc0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x790354u)); /* mov dword ptr [esi], 0x10010354 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)((uint32_t)0x790360u)); /* mov dword ptr [esi + 4], 0x10010360 */
    W32((uint32_t)(c->esi + 0x14u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0x14], edi */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0xc], edi */
    if (c->zf) goto L_00785de9; /* je 0x785de9 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00785de6u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00785de9:;
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 8], edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00785df0(CPU *c) { /* FUN_10005df0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x790360u)); /* mov dword ptr [esi], 0x10010360 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 0x10], 0 */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 8], 0 */
    if (c->zf) goto L_00785e17; /* je 0x785e17 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00785e14u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00785e17:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x8u))); /* mov al, byte ptr [esp + 8] */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 4], 0 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    if (c->zf) goto L_00785e2f; /* je 0x785e2f */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00785e2cu); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00785e2f:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00785e40(CPU *c) { /* PTR_00785e40 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    c->esp += 24; return; /* ret 0x14 */
}

void f_00785e50(CPU *c) { /* PTR_00785e50 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_00785e60(CPU *c) { /* PTR_00785e60 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    c->esp += 8; return; /* ret 4 */
}

void f_00785e70(CPU *c) { /* PTR_00785e70 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)((uint32_t)(c->ecx + 0x140u)); /* lea esi, [ecx + 0x140] */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00785e90(CPU *c) { /* PTR_00785e90 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)((uint32_t)(c->ecx + 0x158u)); /* lea esi, [ecx + 0x158] */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00785eb0(CPU *c) { /* FUN_10005eb0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    W32((uint32_t)(c->eax + 0x18u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x18], ecx */
    W32((uint32_t)(c->eax + 0x1cu), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x1c], ecx */
    c->esp += 4; return; /* ret  */
}

void f_00785ec0(CPU *c) { /* thunk_FUN_10005ed0 */
    PREEMPT_POLL(c);
    { f_00785ed0(c); return; } /* jmp 0x785ed0 */
}

void f_00785ed0(CPU *c) { /* FUN_10005ed0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x18u))); /* mov eax, dword ptr [esi + 0x18] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00785ee3; /* je 0x785ee3 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00785ee0u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00785ee3:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x1cu))); /* mov eax, dword ptr [esi + 0x1c] */
    W32((uint32_t)(c->esi + 0x18u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 0x18], 0 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00785efa; /* je 0x785efa */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00785ef7u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00785efa:;
    W32((uint32_t)(c->esi + 0x1cu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 0x1c], 0 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00785f10(CPU *c) { /* FUN_10005f10 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00785f1eu); f_00785ed0(c); /* call 0x785ed0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov eax, dword ptr [esp + 0x24] */
    c->ebp = (uint32_t)(logic32(c, 0)); /* xor ebp, ebp */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0x10], ebp */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)((uint32_t)0x8u)); /* mov dword ptr [esi + 8], 8 */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
L_00785f33:;
    c->edx = (uint32_t)((uint32_t)0x1u); /* mov edx, 1 */
    c->edx = (uint32_t)(shl32(c, c->edx, (c->ecx & 0xff))); /* shl edx, cl */
    (void)sub32(c, c->edx, (uint32_t)0x8u); /* cmp edx, 8 */
    if (c->zf) goto L_00785f47; /* je 0x785f47 */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->ecx, (uint32_t)0x1fu); /* cmp ecx, 0x1f */
    if (c->cf) goto L_00785f33; /* jb 0x785f33 */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
L_00785f47:;
    c->eax = (uint32_t)(shr32(c, c->eax, (c->ecx & 0xff))); /* shr eax, cl */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 0xc], ecx */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 4], eax */
L_00785f51:;
    c->edx = (uint32_t)((uint32_t)0x1u); /* mov edx, 1 */
    c->edx = (uint32_t)(shl32(c, c->edx, (c->ecx & 0xff))); /* shl edx, cl */
    (void)sub32(c, c->edx, c->eax); /* cmp edx, eax */
    if (c->zf) goto L_00785f64; /* je 0x785f64 */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->ecx, (uint32_t)0x1fu); /* cmp ecx, 0x1f */
    if (c->cf) goto L_00785f51; /* jb 0x785f51 */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
L_00785f64:;
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 0x10], ecx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { int64_t r_ = (int64_t)(int32_t)c->ecx * (int32_t)c->eax; c->ecx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul ecx, eax */
    { uint32_t v_ = 0x25u; PUSH32(c, v_); } /* push 0x25 */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->ecx)); /* add ecx, ecx */
    { uint32_t v_ = 0x79255cu; PUSH32(c, v_); } /* push 0x1001255c */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00785f7bu); f_00781070(c); /* call 0x781070 */
    W32((uint32_t)(c->esi + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x18], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    { uint32_t v_ = 0x26u; PUSH32(c, v_); } /* push 0x26 */
    { int64_t r_ = (int64_t)(int32_t)c->edx * (int32_t)c->eax; c->edx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul edx, eax */
    { uint32_t v_ = 0x79255cu; PUSH32(c, v_); } /* push 0x1001255c */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00785f92u); f_00781070(c); /* call 0x781070 */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov edi, dword ptr [esi + 4] */
    W32((uint32_t)(c->esi + 0x1cu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x1c], eax */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)c->edi; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, edi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x14], ebx */
    if ((c->cf || c->zf)) goto L_0078603d; /* jbe 0x78603d */
L_00785fae:;
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    { uint32_t d_ = c->edi; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x00785fb2u, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div edi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov ecx, dword ptr [esi + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ebp = (uint32_t)(c->ebx); /* mov ebp, ebx */
    { int64_t r_ = (int64_t)(int32_t)c->edi * (int32_t)c->eax; c->edi = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul edi, eax */
    c->eax = (uint32_t)(shl32(c, c->eax, (c->ecx & 0xff))); /* shl eax, cl */
    c->ebp = (uint32_t)(sub32(c, c->ebp, c->edi)); /* sub ebp, edi */
    c->ebp = (uint32_t)(shl32(c, c->ebp, (c->ecx & 0xff))); /* shl ebp, cl */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)c->edx; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, edx */
    c->ebp = (uint32_t)(add32(c, c->ebp, c->eax)); /* add ebp, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)c->eax; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, eax */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x18], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->cf || c->zf)) goto L_00786014; /* jbe 0x786014 */
L_00785fd9:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ebx, dword ptr [esi] */
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    c->eax = (uint32_t)(shr32(c, c->eax, (c->ecx & 0xff))); /* shr eax, cl */
    { int64_t r_ = (int64_t)(int32_t)c->ebx * (int32_t)c->eax; c->ebx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul ebx, eax */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov eax, dword ptr [esp + 0x20] */
    c->edi = (uint32_t)(shl32(c, c->edi, (c->ecx & 0xff))); /* shl edi, cl */
    c->ebx = (uint32_t)(sub32(c, c->ebx, c->edi)); /* sub ebx, edi */
    c->ebx = (uint32_t)(add32(c, c->ebx, c->edx)); /* add ebx, edx */
    c->ebx = (uint32_t)(add32(c, c->ebx, c->ebp)); /* add ebx, ebp */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebx + c->eax))); /* mov al, byte ptr [ebx + eax] */
    if (!c->zf) goto L_00785ffd; /* jne 0x785ffd */
    W8((uint32_t)(c->esp + 0x24u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [esp + 0x24], al */
    goto L_00786007; /* jmp 0x786007 */
L_00785ffd:;
    (void)sub8(c, R8((uint32_t)(c->esp + 0x24u)), ((uint8_t)c->eax)); /* cmp byte ptr [esp + 0x24], al */
    if (!c->zf) goto L_007860ab; /* jne 0x7860ab */
L_00786007:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    (void)sub32(c, c->edx, c->eax); /* cmp edx, eax */
    if (c->cf) goto L_00785fd9; /* jb 0x785fd9 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ebx, dword ptr [esp + 0x14] */
L_00786014:;
    c->edx = (c->edx & 0xffff0000u) | (uint16_t)((uint32_t)R8((uint32_t)(c->esp + 0x24u))); /* movzx dx, byte ptr [esp + 0x24] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x18u))); /* mov eax, dword ptr [esi + 0x18] */
    c->edx = (c->edx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->edx >> 8)) | (uint8_t)0x80u))) << 8); /* or dh, 0x80 */
    W16((uint32_t)(c->eax + c->ebx * 2), (uint16_t)(((uint16_t)c->edx))); /* mov word ptr [eax + ebx*2], dx */
L_00786024:;
    c->edi = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov edi, dword ptr [esi + 4] */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x14], ebx */
    { int64_t r_ = (int64_t)(int32_t)c->ecx * (int32_t)c->edi; c->ecx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul ecx, edi */
    (void)sub32(c, c->ebx, c->ecx); /* cmp ebx, ecx */
    if (c->cf) goto L_00785fae; /* jb 0x785fae */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ebp, dword ptr [esp + 0x10] */
L_0078603d:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    { uint32_t v_ = 0x47u; PUSH32(c, v_); } /* push 0x47 */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    { uint32_t v_ = 0x79255cu; PUSH32(c, v_); } /* push 0x1001255c */
    { int64_t r_ = (int64_t)(int32_t)c->edx * (int32_t)c->eax; c->edx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul edx, eax */
    { int64_t r_ = (int64_t)(int32_t)c->edx * (int32_t)c->ebp; c->edx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul edx, ebp */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x1cu))); /* mov eax, dword ptr [esi + 0x1c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(c->esi + 0x14u), (uint32_t)(c->ebp)); /* mov dword ptr [esi + 0x14], ebp */
    PUSH32(c, 0x0078605cu); f_00781090(c); /* call 0x781090 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov ecx, dword ptr [esp + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    W32((uint32_t)(c->esi + 0x1cu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x1c], eax */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x20], ecx */
L_0078606c:;
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
L_0078606e:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00786077u); f_00786110(c); /* call 0x786110 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov edx, dword ptr [esp + 0x20] */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->edx + c->edi))); /* cmp al, byte ptr [edx + edi] */
    if (c->zf) goto L_00786081; /* je 0x786081 */
    guest_trap(c, 0x00786080u, "int3"); /* int3  */
L_00786081:;
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->edi, (uint32_t)0x400u); /* cmp edi, 0x400 */
    if (c->cf) goto L_0078606e; /* jb 0x78606e */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov ecx, dword ptr [esp + 0x20] */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x400u)); /* add ecx, 0x400 */
    (void)sub32(c, c->ebx, (uint32_t)0x400u); /* cmp ebx, 0x400 */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x20], ecx */
    if (c->cf) goto L_0078606c; /* jb 0x78606c */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 12; return; /* ret 8 */
L_007860ab:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x18u))); /* mov ecx, dword ptr [esi + 0x18] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ebx, dword ptr [esp + 0x14] */
    c->edx = (c->edx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->esp + 0x10u))); /* mov dx, word ptr [esp + 0x10] */
    W16((uint32_t)(c->ecx + c->ebx * 2), (uint16_t)(((uint16_t)c->edx))); /* mov word ptr [ecx + ebx*2], dx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)c->eax; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, eax */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->cf || c->zf)) goto L_00786101; /* jbe 0x786101 */
L_007860c7:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov ecx, dword ptr [esi + 0xc] */
    c->edi = (uint32_t)(c->edx); /* mov edi, edx */
    c->edi = (uint32_t)(shr32(c, c->edi, (c->ecx & 0xff))); /* shr edi, cl */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)R32((uint32_t)(c->esp + 0x10u)); c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, dword ptr [esp + 0x10] */
    c->ebx = (uint32_t)(c->edi); /* mov ebx, edi */
    c->ebx = (uint32_t)(shl32(c, c->ebx, (c->ecx & 0xff))); /* shl ebx, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    { int64_t r_ = (int64_t)(int32_t)c->ecx * (int32_t)c->edi; c->ecx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul ecx, edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov edi, dword ptr [esp + 0x20] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->ebx)); /* sub ecx, ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esi + 0x1cu))); /* mov ebx, dword ptr [esi + 0x1c] */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->edx)); /* add ecx, edx */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->ebp)); /* add ecx, ebp */
    c->eax = (uint32_t)(add32(c, c->eax, c->ebx)); /* add eax, ebx */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->edi))); /* mov cl, byte ptr [ecx + edi] */
    W8((uint32_t)(c->eax + c->edx + 0xffffffffu), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax + edx - 1], cl */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)c->eax; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, eax */
    (void)sub32(c, c->edx, c->eax); /* cmp edx, eax */
    if (c->cf) goto L_007860c7; /* jb 0x7860c7 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ebx, dword ptr [esp + 0x14] */
L_00786101:;
    { uint32_t a_ = (uint32_t)(c->esp + 0x10u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [esp + 0x10] */
    goto L_00786024; /* jmp 0x786024 */
}

void f_00786110(CPU *c) { /* FUN_10006110 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->ecx); /* mov ebp, ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov eax, dword ptr [ebp + 0x18] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00786126; /* jne 0x786126 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0xffu))); /* or al, 0xff */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 12; return; /* ret 8 */
L_00786126:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov edx, dword ptr [esp + 0x18] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ebx, dword ptr [esp + 0x14] */
    c->edi = (uint32_t)(c->edx); /* mov edi, edx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->edi = (uint32_t)(shr32(c, c->edi, (c->ecx & 0xff))); /* shr edi, cl */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->eax = (uint32_t)(shl32(c, c->eax, (c->ecx & 0xff))); /* shl eax, cl */
    c->eax = (uint32_t)(add32(c, c->eax, c->ebx)); /* add eax, ebx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov eax, dword ptr [ebp + 0x18] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->eax + c->ecx * 2))); /* mov ax, word ptr [eax + ecx*2] */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->sf) goto L_00786172; /* js 0x786172 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xffffu))); /* and eax, 0xffff */
    c->edi = (uint32_t)(shl32(c, c->edi, (c->ecx & 0xff))); /* shl edi, cl */
    c->eax = (uint32_t)(shl32(c, c->eax, (c->ecx & 0xff))); /* shl eax, cl */
    c->ebx = (uint32_t)(shl32(c, c->ebx, (c->ecx & 0xff))); /* shl ebx, cl */
    c->edx = (uint32_t)(sub32(c, c->edx, c->edi)); /* sub edx, edi */
    c->edx = (uint32_t)(shl32(c, c->edx, (c->ecx & 0xff))); /* shl edx, cl */
    c->eax = (uint32_t)(shl32(c, c->eax, (c->ecx & 0xff))); /* shl eax, cl */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov eax, dword ptr [ebp + 0x1c] */
    c->edx = (uint32_t)(sub32(c, c->edx, c->ebx)); /* sub edx, ebx */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx + c->eax))); /* mov al, byte ptr [edx + eax] */
L_00786172:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 12; return; /* ret 8 */
}

void f_00786180(CPU *c) { /* FUN_10006180 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x78fb98u; PUSH32(c, v_); } /* push 0x1000fb98 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x18], 0 */
    PUSH32(c, 0x007861a8u); f_00785ed0(c); /* call 0x785ed0 */
    c->ecx = (uint32_t)(R32((uint32_t)(0x795680u))); /* mov ecx, dword ptr [0x10015680] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov ebx, dword ptr [esp + 0x20] */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = 0x80000000u; PUSH32(c, v_); } /* push 0x80000000 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4u)); PUSH32(c, 0x007861c1u); call_indirect(c, t_); } /* call dword ptr [eax + 4] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (!c->zf) goto L_007861e0; /* jne 0x7861e0 */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x18], eax */
    if (c->zf) goto L_007861d9; /* je 0x7861d9 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x007861d6u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_007861d9:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    goto L_007862f4; /* jmp 0x7862f4 */
L_007861e0:;
    c->ecx = (uint32_t)(R32((uint32_t)(0x795680u))); /* mov ecx, dword ptr [0x10015680] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x18u)); PUSH32(c, 0x007861f1u); call_indirect(c, t_); } /* call dword ptr [edx + 0x18] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x795680u))); /* mov ecx, dword ptr [0x10015680] */
    c->ebx = (uint32_t)((uint32_t)(c->edi + 0x4u)); /* lea ebx, [edi + 4] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x18u)); PUSH32(c, 0x00786205u); call_indirect(c, t_); } /* call dword ptr [eax + 0x18] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x795680u))); /* mov ecx, dword ptr [0x10015680] */
    c->ebp = (uint32_t)((uint32_t)(c->edi + 0x8u)); /* lea ebp, [edi + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x18u)); PUSH32(c, 0x00786219u); call_indirect(c, t_); } /* call dword ptr [edx + 0x18] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x795680u))); /* mov ecx, dword ptr [0x10015680] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->edx = (uint32_t)((uint32_t)(c->edi + 0xcu)); /* lea edx, [edi + 0xc] */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x18u)); PUSH32(c, 0x0078622du); call_indirect(c, t_); } /* call dword ptr [eax + 0x18] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x795680u))); /* mov ecx, dword ptr [0x10015680] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->edx = (uint32_t)((uint32_t)(c->edi + 0x10u)); /* lea edx, [edi + 0x10] */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x18u)); PUSH32(c, 0x00786241u); call_indirect(c, t_); } /* call dword ptr [eax + 0x18] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x795680u))); /* mov ecx, dword ptr [0x10015680] */
    c->eax = (uint32_t)((uint32_t)(c->edi + 0x14u)); /* lea eax, [edi + 0x14] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x18u)); PUSH32(c, 0x00786255u); call_indirect(c, t_); } /* call dword ptr [edx + 0x18] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    { uint32_t v_ = 0x6au; PUSH32(c, v_); } /* push 0x6a */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t v_ = 0x79255cu; PUSH32(c, v_); } /* push 0x1001255c */
    { int64_t r_ = (int64_t)(int32_t)c->ecx * (int32_t)c->eax; c->ecx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul ecx, eax */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->ecx)); /* add ecx, ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x0078626bu); f_00781070(c); /* call 0x781070 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov ebx, dword ptr [ebx] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    W32((uint32_t)(c->edi + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [edi + 0x18], eax */
    { int64_t r_ = (int64_t)(int32_t)c->ecx * (int32_t)c->ebx; c->ecx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul ecx, ebx */
    c->edx = (uint32_t)(R32((uint32_t)(0x795680u))); /* mov edx, dword ptr [0x10015680] */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->ecx)); /* add ecx, ecx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->edx))); /* mov edx, dword ptr [edx] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x795680u))); /* mov ecx, dword ptr [0x10015680] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x18u)); PUSH32(c, 0x00786290u); call_indirect(c, t_); } /* call dword ptr [edx + 0x18] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov eax, dword ptr [ebp] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + 0x14u))); /* mov edx, dword ptr [edi + 0x14] */
    c->ebx = (uint32_t)((uint32_t)(c->edi + 0x14u)); /* lea ebx, [edi + 0x14] */
    { int64_t r_ = (int64_t)(int32_t)c->edx * (int32_t)c->eax; c->edx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul edx, eax */
    { int64_t r_ = (int64_t)(int32_t)c->edx * (int32_t)c->eax; c->edx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul edx, eax */
    { uint32_t v_ = 0x6cu; PUSH32(c, v_); } /* push 0x6c */
    { uint32_t v_ = 0x79255cu; PUSH32(c, v_); } /* push 0x1001255c */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x007862acu); f_00781070(c); /* call 0x781070 */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov ebp, dword ptr [ebp] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->edi + 0x1cu), (uint32_t)(c->eax)); /* mov dword ptr [edi + 0x1c], eax */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov edi, dword ptr [ebx] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x795680u))); /* mov ecx, dword ptr [0x10015680] */
    { int64_t r_ = (int64_t)(int32_t)c->edi * (int32_t)c->ebp; c->edi = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul edi, ebp */
    { int64_t r_ = (int64_t)(int32_t)c->edi * (int32_t)c->ebp; c->edi = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul edi, ebp */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x18u)); PUSH32(c, 0x007862cdu); call_indirect(c, t_); } /* call dword ptr [edx + 0x18] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x795680u))); /* mov ecx, dword ptr [0x10015680] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x007862d9u); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov eax, dword ptr [esp + 0x20] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [esp + 0x18], 0xffffffff */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_007862f2; /* je 0x7862f2 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x007862efu); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_007862f2:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
L_007862f4:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 20; return; /* ret 0x10 */
}

void f_00786310(CPU *c) { /* FUN_10006310 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x78fbb8u; PUSH32(c, v_); } /* push 0x1000fbb8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(0x795680u))); /* mov ecx, dword ptr [0x10015680] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov ebx, dword ptr [esp + 0x20] */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = 0x40000000u; PUSH32(c, v_); } /* push 0x40000000 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x28], 0 */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4u)); PUSH32(c, 0x0078634cu); call_indirect(c, t_); } /* call dword ptr [eax + 4] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (!c->zf) goto L_0078636b; /* jne 0x78636b */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x18], eax */
    if (c->zf) goto L_00786364; /* je 0x786364 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00786361u); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00786364:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    goto L_00786442; /* jmp 0x786442 */
L_0078636b:;
    c->ecx = (uint32_t)(R32((uint32_t)(0x795680u))); /* mov ecx, dword ptr [0x10015680] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x0078637cu); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x795680u))); /* mov ecx, dword ptr [0x10015680] */
    c->ebx = (uint32_t)((uint32_t)(c->edi + 0x4u)); /* lea ebx, [edi + 4] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x00786390u); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x795680u))); /* mov ecx, dword ptr [0x10015680] */
    c->ebp = (uint32_t)((uint32_t)(c->edi + 0x8u)); /* lea ebp, [edi + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x007863a4u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x795680u))); /* mov ecx, dword ptr [0x10015680] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->edx = (uint32_t)((uint32_t)(c->edi + 0xcu)); /* lea edx, [edi + 0xc] */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x007863b8u); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x795680u))); /* mov ecx, dword ptr [0x10015680] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->edx = (uint32_t)((uint32_t)(c->edi + 0x10u)); /* lea edx, [edi + 0x10] */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x007863ccu); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x795680u))); /* mov ecx, dword ptr [0x10015680] */
    c->eax = (uint32_t)((uint32_t)(c->edi + 0x14u)); /* lea eax, [edi + 0x14] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x007863e0u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov ebx, dword ptr [ebx] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x795680u))); /* mov ecx, dword ptr [0x10015680] */
    c->edx = (uint32_t)(c->ebx); /* mov edx, ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { int64_t r_ = (int64_t)(int32_t)c->edx * (int32_t)c->ebx; c->edx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul edx, ebx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)(add32(c, c->edx, c->edx)); /* add edx, edx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + 0x18u))); /* mov edx, dword ptr [edi + 0x18] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x007863fcu); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov ebp, dword ptr [ebp] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + 0x14u))); /* mov edx, dword ptr [edi + 0x14] */
    { int64_t r_ = (int64_t)(int32_t)c->edx * (int32_t)c->ebp; c->edx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul edx, ebp */
    { int64_t r_ = (int64_t)(int32_t)c->edx * (int32_t)c->ebp; c->edx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul edx, ebp */
    c->ecx = (uint32_t)(R32((uint32_t)(0x795680u))); /* mov ecx, dword ptr [0x10015680] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + 0x1cu))); /* mov edx, dword ptr [edi + 0x1c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x0078641bu); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x795680u))); /* mov ecx, dword ptr [0x10015680] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x00786427u); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov eax, dword ptr [esp + 0x20] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [esp + 0x18], 0xffffffff */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00786440; /* je 0x786440 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0078643du); f_00781050(c); /* call 0x781050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00786440:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
L_00786442:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 20; return; /* ret 0x10 */
}

void f_00786460(CPU *c) { /* FUN_10006460 */
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
    { uint32_t t_ = c->eax; switch (t_) {  default: jump_indirect(c, t_, 0x0078648bu); return; } } /* jmp eax */
}

void f_0078648d(CPU *c) { /* PTR_0078648d */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 12; return; /* ret 8 */
}

void f_00786494(CPU *c) { /* FUN_10006494 */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { guest_lock(); { uint32_t t0_ = R32((uint32_t)(c->esp)), t1_ = c->eax; W32((uint32_t)(c->esp), (uint32_t)(t1_)); c->eax = (uint32_t)(t0_); } guest_unlock(); } /* xchg dword ptr [esp], eax */
    { uint32_t t_ = c->eax; switch (t_) {  default: jump_indirect(c, t_, 0x00786499u); return; } } /* jmp eax */
}

void f_0078649b(CPU *c) { /* FUN_1000649b */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { guest_lock(); { uint32_t t0_ = R32((uint32_t)(c->esp)), t1_ = c->eax; W32((uint32_t)(c->esp), (uint32_t)(t1_)); c->eax = (uint32_t)(t0_); } guest_unlock(); } /* xchg dword ptr [esp], eax */
    { uint32_t t_ = c->eax; switch (t_) {  default: jump_indirect(c, t_, 0x007864a0u); return; } } /* jmp eax */
}

void f_007864a2(CPU *c) { /* FUN_100064a2 */
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
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x7864cau)); /* mov dword ptr [ebp - 4], 0x100064ca */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x007864cau); f_0078f8d0(c); /* call 0x78f8d0 */
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

void f_007864ca(CPU *c) { /* PTR_007864ca */
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

void f_007864f1(CPU *c) { /* FUN_100064f1 */
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
    PUSH32(c, 0x00786517u); f_00786f89(c); /* call 0x786f89 */
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

void f_00786527(CPU *c) { /* FUN_10006527 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x14u)); /* sub esp, 0x14 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffecu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x14], 0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)((uint32_t)0x78657bu)); /* mov dword ptr [ebp - 0x10], 0x1000657b */
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
    PUSH32(c, 0x0078656cu); f_007877a0(c); /* call 0x7877a0 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->eax)); /* mov dword ptr fs:[0], eax */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0078657b(CPU *c) { /* FUN_1000657b */
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
    PUSH32(c, 0x0078659bu); f_00786f89(c); /* call 0x786f89 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_007865a0(CPU *c) { /* FUN_100065a0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x34u)); /* sub esp, 0x34 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffd8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x28], 0 */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)((uint32_t)0x786656u)); /* mov dword ptr [ebp - 0x24], 0x10006656 */
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
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)((uint32_t)0x786628u)); /* mov dword ptr [ebp - 0x10], 0x10006628 */
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
    PUSH32(c, 0x0078661fu); f_00787871(c); /* call 0x787871 */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x68u)); PUSH32(c, 0x00786622u); call_indirect(c, t_); } /* call dword ptr [eax + 0x68] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffccu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x34], 0 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if (c->zf) goto L_00786645; /* je 0x786645 */
    c->ebx = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov ebx, dword ptr fs:[0] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ebx, dword ptr [ebp - 0x28] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ebx)); /* mov dword ptr fs:[0], ebx */
    goto L_0078664e; /* jmp 0x78664e */
L_00786645:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->eax)); /* mov dword ptr fs:[0], eax */
L_0078664e:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffccu))); /* mov eax, dword ptr [ebp - 0x34] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00786628(CPU *c) { /* PTR_00786628 */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if (c->zf) goto L_00786645; /* je 0x786645 */
    c->ebx = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov ebx, dword ptr fs:[0] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ebx, dword ptr [ebp - 0x28] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ebx)); /* mov dword ptr fs:[0], ebx */
    goto L_0078664e; /* jmp 0x78664e */
L_00786645:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->eax)); /* mov dword ptr fs:[0], eax */
L_0078664e:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffccu))); /* mov eax, dword ptr [ebp - 0x34] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00786656(CPU *c) { /* FUN_10006656 */
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
    if (c->zf) goto L_00786679; /* je 0x786679 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->eax + 0x24u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [eax + 0x24], 1 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_007866c6; /* jmp 0x7866c6 */
L_00786679:;
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
    PUSH32(c, 0x007866a0u); f_00786f89(c); /* call 0x786f89 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x24u)), (uint32_t)0x0u); /* cmp dword ptr [eax + 0x24], 0 */
    if (!c->zf) goto L_007866b7; /* jne 0x7866b7 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x007866b7u); f_007864a2(c); /* call 0x7864a2 */
L_007866b7:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ebx, dword ptr [ebp + 0xc] */
    c->esp = (uint32_t)(R32((uint32_t)(c->ebx + 0x1cu))); /* mov esp, dword ptr [ebx + 0x1c] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ebx + 0x20u))); /* mov ebp, dword ptr [ebx + 0x20] */
    { uint32_t t_ = R32((uint32_t)(c->ebx + 0x18u)); switch (t_) {  default: jump_indirect(c, t_, 0x007866c0u); return; } } /* jmp dword ptr [ebx + 0x18] */
L_007866c6:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_007866cb(CPU *c) { /* FUN_100066cb */
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
    if ((c->sf != c->of)) goto L_00786722; /* jl 0x786722 */
L_007866e9:;
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (!c->zf) goto L_007866f3; /* jne 0x7866f3 */
    PUSH32(c, 0x007866f3u); f_007879d9(c); /* call 0x7879d9 */
L_007866f3:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi * 4)); /* lea eax, [esi + esi*4] */
    (void)sub32(c, R32((uint32_t)(c->ebx + c->eax * 4 + 0x4u)), c->ecx); /* cmp dword ptr [ebx + eax*4 + 4], ecx */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->eax * 4)); /* lea eax, [ebx + eax*4] */
    if ((c->sf == c->of)) goto L_00786708; /* jge 0x786708 */
    (void)sub32(c, c->ecx, R32((uint32_t)(c->eax + 0x8u))); /* cmp ecx, dword ptr [eax + 8] */
    if ((c->zf || c->sf != c->of)) goto L_0078670d; /* jle 0x78670d */
L_00786708:;
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (!c->zf) goto L_00786719; /* jne 0x786719 */
L_0078670d:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
L_00786719:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    if ((c->sf == c->of)) goto L_007866e9; /* jge 0x7866e9 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
L_00786722:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov ecx, dword ptr [ebp + 0x14] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    W32((uint32_t)(c->ecx), (uint32_t)(c->esi)); /* mov dword ptr [ecx], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov ecx, dword ptr [ebp + 0x18] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    (void)sub32(c, c->eax, R32((uint32_t)(c->edi + 0xcu))); /* cmp eax, dword ptr [edi + 0xc] */
    if ((!c->cf && !c->zf)) goto L_00786736; /* ja 0x786736 */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if ((c->cf || c->zf)) goto L_0078673b; /* jbe 0x78673b */
L_00786736:;
    PUSH32(c, 0x0078673bu); f_007879d9(c); /* call 0x7879d9 */
L_0078673b:;
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi * 4)); /* lea eax, [esi + esi*4] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->eax * 4)); /* lea eax, [ebx + eax*4] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00786748(CPU *c) { /* __global_unwind2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x786760u; PUSH32(c, v_); } /* push 0x10006760 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00786760u); f_0078f8d0(c); /* call 0x78f8d0 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00786760(CPU *c) { /* PTR_00786760 */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00786768(CPU *c) { /* PTR_00786768 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->ecx + 0x4u)) & (uint32_t)0x6u)); /* test dword ptr [ecx + 4], 6 */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    if (c->zf) goto L_00786789; /* je 0x786789 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    W32((uint32_t)(c->edx), (uint32_t)(c->eax)); /* mov dword ptr [edx], eax */
    c->eax = (uint32_t)((uint32_t)0x3u); /* mov eax, 3 */
L_00786789:;
    c->esp += 4; return; /* ret  */
}

void f_0078678a(CPU *c) { /* __local_unwind2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0xfffffffeu; PUSH32(c, v_); } /* push -2 */
    { uint32_t v_ = 0x786768u; PUSH32(c, v_); } /* push 0x10006768 */
    { uint32_t v_ = R32((uint32_t)(0x0u + c->fs_base)); PUSH32(c, v_); } /* push dword ptr fs:[0] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
L_007867a7:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov eax, dword ptr [esp + 0x20] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ebx, dword ptr [eax + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + 0xcu))); /* mov esi, dword ptr [eax + 0xc] */
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (c->zf) goto L_007867e4; /* je 0x7867e4 */
    (void)sub32(c, c->esi, R32((uint32_t)(c->esp + 0x24u))); /* cmp esi, dword ptr [esp + 0x24] */
    if (c->zf) goto L_007867e4; /* je 0x7867e4 */
    c->esi = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea esi, [esi + esi*2] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + c->esi * 4))); /* mov ecx, dword ptr [ebx + esi*4] */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 8], ecx */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0xc], ecx */
    (void)sub32(c, R32((uint32_t)(c->ebx + c->esi * 4 + 0x4u)), (uint32_t)0x0u); /* cmp dword ptr [ebx + esi*4 + 4], 0 */
    if (!c->zf) goto L_007867e2; /* jne 0x7867e2 */
    { uint32_t v_ = 0x101u; PUSH32(c, v_); } /* push 0x101 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + c->esi * 4 + 0x8u))); /* mov eax, dword ptr [ebx + esi*4 + 8] */
    PUSH32(c, 0x007867deu); f_0078681e(c); /* call 0x78681e */
    { uint32_t t_ = R32((uint32_t)(c->ebx + c->esi * 4 + 0x8u)); PUSH32(c, 0x007867e2u); call_indirect(c, t_); } /* call dword ptr [ebx + esi*4 + 8] */
L_007867e2:;
    goto L_007867a7; /* jmp 0x7867a7 */
L_007867e4:;
    { uint32_t v_ = R32(c->esp); c->esp += 4; W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(v_)); } /* pop dword ptr fs:[0] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_007867f2(CPU *c) { /* __abnormal_termination */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov ecx, dword ptr fs:[0] */
    (void)sub32(c, R32((uint32_t)(c->ecx + 0x4u)), (uint32_t)0x786768u); /* cmp dword ptr [ecx + 4], 0x10006768 */
    if (!c->zf) goto L_00786814; /* jne 0x786814 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov edx, dword ptr [ecx + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edx + 0xcu))); /* mov edx, dword ptr [edx + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->ecx + 0x8u)), c->edx); /* cmp dword ptr [ecx + 8], edx */
    if (!c->zf) goto L_00786814; /* jne 0x786814 */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
L_00786814:;
    c->esp += 4; return; /* ret  */
}

void f_00786815(CPU *c) { /* __NLG_Notify1 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ebx = (uint32_t)((uint32_t)0x792588u); /* mov ebx, 0x10012588 */
    { f_00786828(c); return; } /* jmp 0x786828 */
}

void f_0078681e(CPU *c) { /* FUN_1000681e */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ebx = (uint32_t)((uint32_t)0x792588u); /* mov ebx, 0x10012588 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebx + 8], ecx */
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 4], eax */
    W32((uint32_t)(c->ebx + 0xcu), (uint32_t)(c->ebp)); /* mov dword ptr [ebx + 0xc], ebp */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
}

void f_00786828(CPU *c) { /* PTR_00786828 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebx + 8], ecx */
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 4], eax */
    W32((uint32_t)(c->ebx + 0xcu), (uint32_t)(c->ebp)); /* mov dword ptr [ebx + 0xc], ebp */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
}

void f_00786836(CPU *c) { /* PTR_00786836 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x0078683cu); f_00787b21(c); /* call 0x787b21 */
    { uint32_t v_ = R32((uint32_t)(0x796db0u)); PUSH32(c, v_); } /* push dword ptr [0x10016db0] */
    PUSH32(c, 0x00786847u); f_00787e7c(c); /* call 0x787e7c */
    c->edx = (uint32_t)(R32((uint32_t)(0x796db0u))); /* mov edx, dword ptr [0x10016db0] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(0x796dacu))); /* mov ecx, dword ptr [0x10016dac] */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->esi = (uint32_t)(sub32(c, c->esi, c->edx)); /* sub esi, edx */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (!c->cf) goto L_0078689c; /* jae 0x78689c */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00786865u); f_00787e7c(c); /* call 0x787e7c */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x10u)); /* add eax, 0x10 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(0x796db0u)); PUSH32(c, v_); } /* push dword ptr [0x10016db0] */
    PUSH32(c, 0x00786874u); f_00787b4d(c); /* call 0x787b4d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_0078687f; /* jne 0x78687f */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    goto L_007868ab; /* jmp 0x7868ab */
L_0078687f:;
    c->ecx = (uint32_t)(R32((uint32_t)(0x796dacu))); /* mov ecx, dword ptr [0x10016dac] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, R32((uint32_t)(0x796db0u)))); /* sub ecx, dword ptr [0x10016db0] */
    W32((uint32_t)(0x796db0u), (uint32_t)(c->eax)); /* mov dword ptr [0x10016db0], eax */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 2)); /* sar ecx, 2 */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->ecx * 4)); /* lea ecx, [eax + ecx*4] */
    W32((uint32_t)(0x796dacu), (uint32_t)(c->ecx)); /* mov dword ptr [0x10016dac], ecx */
L_0078689c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    { uint32_t a_ = (uint32_t)(0x796dacu); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x4u))); } /* add dword ptr [0x10016dac], 4 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_007868ab:;
    PUSH32(c, 0x007868b0u); f_00787b2a(c); /* call 0x787b2a */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_007868b4(CPU *c) { /* PTR_007868b4 */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    PUSH32(c, 0x007868bdu); f_00786836(c); /* call 0x786836 */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->esp += 4; return; /* ret  */
}

void f_007868c6(CPU *c) { /* PTR_007868c6 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x80u; PUSH32(c, v_); } /* push 0x80 */
    PUSH32(c, 0x007868d0u); f_00787f6a(c); /* call 0x787f6a */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(0x796db0u), (uint32_t)(c->eax)); /* mov dword ptr [0x10016db0], eax */
    if (!c->zf) goto L_007868e7; /* jne 0x7868e7 */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    PUSH32(c, 0x007868e1u); f_00786f56(c); /* call 0x786f56 */
    c->eax = (uint32_t)(R32((uint32_t)(0x796db0u))); /* mov eax, dword ptr [0x10016db0] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_007868e7:;
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [eax], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(0x796db0u))); /* mov eax, dword ptr [0x10016db0] */
    W32((uint32_t)(0x796dacu), (uint32_t)(c->eax)); /* mov dword ptr [0x10016dac], eax */
    c->esp += 4; return; /* ret  */
}

void f_007868f5(CPU *c) { /* PTR_007868f5 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x19u; PUSH32(c, v_); } /* push 0x19 */
    PUSH32(c, 0x007868fcu); f_00786f56(c); /* call 0x786f56 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_007868fe(CPU *c) { /* FUN_100068fe */
    PREEMPT_POLL(c);
    PUSH32(c, 0x00786903u); f_00786916(c); /* call 0x786916 */
    PUSH32(c, 0x00786908u); f_007880f4(c); /* call 0x7880f4 */
    W32((uint32_t)(0x7956a8u), (uint32_t)(c->eax)); /* mov dword ptr [0x100156a8], eax */
    PUSH32(c, 0x00786912u); f_007880a4(c); /* call 0x7880a4 */
    c->fpu_sw &= 0x7f00; /* fnclex  */
    c->esp += 4; return; /* ret  */
}

void f_00786915(CPU *c) { /* PTR_00786915 */
    PREEMPT_POLL(c);
    c->esp += 4; return; /* ret  */
}

void f_00786916(CPU *c) { /* FUN_10006916 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x7884cdu); /* mov eax, 0x100084cd */
    W32((uint32_t)(0x7925dcu), (uint32_t)((uint32_t)0x788177u)); /* mov dword ptr [0x100125dc], 0x10008177 */
    W32((uint32_t)(0x7925d8u), (uint32_t)(c->eax)); /* mov dword ptr [0x100125d8], eax */
    W32((uint32_t)(0x7925e0u), (uint32_t)((uint32_t)0x7881ddu)); /* mov dword ptr [0x100125e0], 0x100081dd */
    W32((uint32_t)(0x7925e4u), (uint32_t)((uint32_t)0x78811du)); /* mov dword ptr [0x100125e4], 0x1000811d */
    W32((uint32_t)(0x7925e8u), (uint32_t)((uint32_t)0x7881c5u)); /* mov dword ptr [0x100125e8], 0x100081c5 */
    W32((uint32_t)(0x7925ecu), (uint32_t)(c->eax)); /* mov dword ptr [0x100125ec], eax */
    c->esp += 4; return; /* ret  */
}

void f_00786950(CPU *c) { /* _strncpy */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_007869d3; /* je 0x7869d3 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov esi, dword ptr [esp + 0x14] */
    (void)logic32(c, (uint32_t)(c->esi & (uint32_t)0x3u)); /* test esi, 3 */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edi, dword ptr [esp + 0x10] */
    if (!c->zf) goto L_00786974; /* jne 0x786974 */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->zf) goto L_007869e1; /* jne 0x7869e1 */
    goto L_00786995; /* jmp 0x786995 */
L_00786974:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_007869a2; /* je 0x7869a2 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_007869aa; /* je 0x7869aa */
    (void)logic32(c, (uint32_t)(c->esi & (uint32_t)0x3u)); /* test esi, 3 */
    if (!c->zf) goto L_00786974; /* jne 0x786974 */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->zf) goto L_007869e1; /* jne 0x7869e1 */
L_00786990:;
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x3u))); /* and ebx, 3 */
    if (c->zf) goto L_007869a2; /* je 0x7869a2 */
L_00786995:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_007869ce; /* je 0x7869ce */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->zf) goto L_00786995; /* jne 0x786995 */
L_007869a2:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_007869aa:;
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x3u)); /* test edi, 3 */
    if (c->zf) goto L_007869c4; /* je 0x7869c4 */
L_007869b2:;
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_00786a46; /* je 0x786a46 */
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x3u)); /* test edi, 3 */
    if (!c->zf) goto L_007869b2; /* jne 0x7869b2 */
L_007869c4:;
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->zf) goto L_00786a37; /* jne 0x786a37 */
L_007869cb:;
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
L_007869ce:;
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->zf) goto L_007869cb; /* jne 0x7869cb */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_007869d3:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_007869d9:;
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_00786990; /* je 0x786990 */
L_007869e1:;
    c->edx = (uint32_t)((uint32_t)0x7efefeffu); /* mov edx, 0x7efefeff */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ (uint32_t)0xffffffffu))); /* xor eax, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ c->edx))); /* xor eax, edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u)); /* test eax, 0x81010100 */
    if (c->zf) goto L_007869d9; /* je 0x7869d9 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00786a2b; /* je 0x786a2b */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->edx >> 8)) & ((uint8_t)(c->edx >> 8)))); /* test dh, dh */
    if (c->zf) goto L_00786a21; /* je 0x786a21 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0xff0000u)); /* test edx, 0xff0000 */
    if (c->zf) goto L_00786a17; /* je 0x786a17 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0xff000000u)); /* test edx, 0xff000000 */
    if (!c->zf) goto L_007869d9; /* jne 0x7869d9 */
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    goto L_00786a2f; /* jmp 0x786a2f */
L_00786a17:;
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0xffffu))); /* and edx, 0xffff */
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    goto L_00786a2f; /* jmp 0x786a2f */
L_00786a21:;
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0xffu))); /* and edx, 0xff */
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    goto L_00786a2f; /* jmp 0x786a2f */
L_00786a2b:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
L_00786a2f:;
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_00786a41; /* je 0x786a41 */
L_00786a37:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00786a39:;
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (!c->zf) goto L_00786a39; /* jne 0x786a39 */
L_00786a41:;
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x3u))); /* and ebx, 3 */
    if (!c->zf) goto L_007869cb; /* jne 0x7869cb */
L_00786a46:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00786a50(CPU *c) { /* PTR_00786a50 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xffffffffu)); /* lea eax, [edx - 1] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00786a60(CPU *c) { /* _strchr */
    PREEMPT_POLL(c);
    goto L_00786a60;
L_00786a50:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xffffffffu)); /* lea eax, [edx - 1] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_00786a60:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x8u))); /* mov al, byte ptr [esp + 8] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u)); /* test edx, 3 */
    if (c->zf) goto L_00786a8b; /* je 0x786a8b */
L_00786a78:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov cl, byte ptr [edx] */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    (void)sub8(c, ((uint8_t)c->ecx), ((uint8_t)c->ebx)); /* cmp cl, bl */
    if (c->zf) goto L_00786a50; /* je 0x786a50 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_00786ad4; /* je 0x786ad4 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u)); /* test edx, 3 */
    if (!c->zf) goto L_00786a78; /* jne 0x786a78 */
L_00786a8b:;
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | c->eax))); /* or ebx, eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->ebx = (uint32_t)(shl32(c, c->ebx, 16)); /* shl ebx, 0x10 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | c->eax))); /* or ebx, eax */
L_00786a96:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx))); /* mov ecx, dword ptr [edx] */
    c->edi = (uint32_t)((uint32_t)0x7efefeffu); /* mov edi, 0x7efefeff */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->esi = (uint32_t)(c->edi); /* mov esi, edi */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx ^ c->ebx))); /* xor ecx, ebx */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->ecx)); /* add edi, ecx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx ^ (uint32_t)0xffffffffu))); /* xor ecx, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ (uint32_t)0xffffffffu))); /* xor eax, 0xffffffff */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx ^ c->edi))); /* xor ecx, edi */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ c->esi))); /* xor eax, esi */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x4u)); /* add edx, 4 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x81010100u))); /* and ecx, 0x81010100 */
    if (!c->zf) goto L_00786ad8; /* jne 0x786ad8 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u))); /* and eax, 0x81010100 */
    if (c->zf) goto L_00786a96; /* je 0x786a96 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1010100u))); /* and eax, 0x1010100 */
    if (!c->zf) goto L_00786ad2; /* jne 0x786ad2 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0x80000000u))); /* and esi, 0x80000000 */
    if (!c->zf) goto L_00786a96; /* jne 0x786a96 */
L_00786ad2:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_00786ad4:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_00786ad8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0xfffffffcu))); /* mov eax, dword ptr [edx - 4] */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_00786b15; /* je 0x786b15 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00786ad2; /* je 0x786ad2 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->ebx)); /* cmp ah, bl */
    if (c->zf) goto L_00786b0e; /* je 0x786b0e */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_00786ad2; /* je 0x786ad2 */
    c->eax = (uint32_t)(shr32(c, c->eax, 16)); /* shr eax, 0x10 */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_00786b07; /* je 0x786b07 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00786ad2; /* je 0x786ad2 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->ebx)); /* cmp ah, bl */
    if (c->zf) goto L_00786b00; /* je 0x786b00 */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_00786ad2; /* je 0x786ad2 */
    goto L_00786a96; /* jmp 0x786a96 */
L_00786b00:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xffffffffu)); /* lea eax, [edx - 1] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_00786b07:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xfffffffeu)); /* lea eax, [edx - 2] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_00786b0e:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xfffffffdu)); /* lea eax, [edx - 3] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_00786b15:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xfffffffcu)); /* lea eax, [edx - 4] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00786a66(CPU *c) { /* PTR_00786a66 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u)); /* test edx, 3 */
    if (c->zf) goto L_00786a8b; /* je 0x786a8b */
L_00786a78:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov cl, byte ptr [edx] */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    (void)sub8(c, ((uint8_t)c->ecx), ((uint8_t)c->ebx)); /* cmp cl, bl */
    if (c->zf) { f_00786a50(c); return; } /* je 0x786a50 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_00786ad4; /* je 0x786ad4 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u)); /* test edx, 3 */
    if (!c->zf) goto L_00786a78; /* jne 0x786a78 */
L_00786a8b:;
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | c->eax))); /* or ebx, eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->ebx = (uint32_t)(shl32(c, c->ebx, 16)); /* shl ebx, 0x10 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | c->eax))); /* or ebx, eax */
L_00786a96:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx))); /* mov ecx, dword ptr [edx] */
    c->edi = (uint32_t)((uint32_t)0x7efefeffu); /* mov edi, 0x7efefeff */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->esi = (uint32_t)(c->edi); /* mov esi, edi */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx ^ c->ebx))); /* xor ecx, ebx */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->ecx)); /* add edi, ecx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx ^ (uint32_t)0xffffffffu))); /* xor ecx, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ (uint32_t)0xffffffffu))); /* xor eax, 0xffffffff */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx ^ c->edi))); /* xor ecx, edi */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ c->esi))); /* xor eax, esi */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x4u)); /* add edx, 4 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x81010100u))); /* and ecx, 0x81010100 */
    if (!c->zf) goto L_00786ad8; /* jne 0x786ad8 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u))); /* and eax, 0x81010100 */
    if (c->zf) goto L_00786a96; /* je 0x786a96 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1010100u))); /* and eax, 0x1010100 */
    if (!c->zf) goto L_00786ad2; /* jne 0x786ad2 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0x80000000u))); /* and esi, 0x80000000 */
    if (!c->zf) goto L_00786a96; /* jne 0x786a96 */
L_00786ad2:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_00786ad4:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_00786ad8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0xfffffffcu))); /* mov eax, dword ptr [edx - 4] */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_00786b15; /* je 0x786b15 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00786ad2; /* je 0x786ad2 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->ebx)); /* cmp ah, bl */
    if (c->zf) goto L_00786b0e; /* je 0x786b0e */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_00786ad2; /* je 0x786ad2 */
    c->eax = (uint32_t)(shr32(c, c->eax, 16)); /* shr eax, 0x10 */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_00786b07; /* je 0x786b07 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00786ad2; /* je 0x786ad2 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->ebx)); /* cmp ah, bl */
    if (c->zf) goto L_00786b00; /* je 0x786b00 */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_00786ad2; /* je 0x786ad2 */
    goto L_00786a96; /* jmp 0x786a96 */
L_00786b00:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xffffffffu)); /* lea eax, [edx - 1] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_00786b07:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xfffffffeu)); /* lea eax, [edx - 2] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_00786b0e:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xfffffffdu)); /* lea eax, [edx - 3] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_00786b15:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xfffffffcu)); /* lea eax, [edx - 4] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00786b1c(CPU *c) { /* FUN_10006b1c */
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
    PUSH32(c, 0x00786b4au); f_007888dc(c); /* call 0x7888dc */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe4u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 0x1c] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    if (c->sf) goto L_00786b5c; /* js 0x786b5c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov eax, dword ptr [ebp - 0x20] */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax], 0 */
    goto L_00786b69; /* jmp 0x786b69 */
L_00786b5c:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe0u)); /* lea eax, [ebp - 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    PUSH32(c, 0x00786b67u); f_007887c4(c); /* call 0x7887c4 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00786b69:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00786b70(CPU *c) { /* __ftol */
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

void f_00786b97(CPU *c) { /* FUN_10006b97 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xau))); /* mov eax, dword ptr [esp + 0xa] */
    c->ecx = (uint32_t)((uint32_t)0x7ff8u); /* mov ecx, 0x7ff8 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & c->ecx))); /* and eax, ecx */
    (void)sub16(c, ((uint16_t)c->eax), (uint16_t)0x7ff0u); /* cmp ax, 0x7ff0 */
    if (!c->zf) goto L_00786bb9; /* jne 0x786bb9 */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->esp + 0x8u)) & (uint32_t)0x7ffffu)); /* test dword ptr [esp + 8], 0x7ffff */
    if (!c->zf) goto L_00786bbe; /* jne 0x786bbe */
    (void)sub32(c, R32((uint32_t)(c->esp + 0x4u)), (uint32_t)0x0u); /* cmp dword ptr [esp + 4], 0 */
    if (!c->zf) goto L_00786bbe; /* jne 0x786bbe */
L_00786bb9:;
    (void)sub16(c, ((uint16_t)c->eax), ((uint16_t)c->ecx)); /* cmp ax, cx */
    if (!c->zf) goto L_00786bc2; /* jne 0x786bc2 */
L_00786bbe:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
L_00786bc2:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_00786bc5(CPU *c) { /* FUN_10006bc5 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x20u)); /* sub esp, 0x20 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x49u)); /* mov dword ptr [ebp - 0x14], 0x49 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x18], eax */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    PUSH32(c, 0x00786be1u); f_00789c00(c); /* call 0x789c00 */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe0u)); /* lea eax, [ebp - 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00786bf4u); f_0078914a(c); /* call 0x78914a */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00786c00(CPU *c) { /* FUN_10006c00 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    (void)sub32(c, c->eax, (uint32_t)0x1000u); /* cmp eax, 0x1000 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x8u)); /* lea ecx, [esp + 8] */
    if (c->cf) goto L_00786c20; /* jb 0x786c20 */
L_00786c0c:;
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x1000u)); /* sub ecx, 0x1000 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x1000u)); /* sub eax, 0x1000 */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->ecx)) & c->eax)); /* test dword ptr [ecx], eax */
    (void)sub32(c, c->eax, (uint32_t)0x1000u); /* cmp eax, 0x1000 */
    if (!c->cf) goto L_00786c0c; /* jae 0x786c0c */
L_00786c20:;
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    c->eax = (uint32_t)(c->esp); /* mov eax, esp */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->ecx)) & c->eax)); /* test dword ptr [ecx], eax */
    c->esp = (uint32_t)(c->ecx); /* mov esp, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov eax, dword ptr [eax + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->esp += 4; return; /* ret  */
}

void f_00786c2f(CPU *c) { /* FUN_10006c2f */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x7903a0u; PUSH32(c, v_); } /* push 0x100103a0 */
    { uint32_t v_ = 0x789c84u; PUSH32(c, v_); } /* push 0x10009c84 */
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
L_00786c66:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0x10u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 0x10] */
    if (c->sf) goto L_00786c76; /* js 0x786c76 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(sub32(c, R32(a_), c->esi))); } /* sub dword ptr [ebp + 8], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, 0x00786c74u); call_indirect(c, t_); } /* call dword ptr [ebp + 0x14] */
    goto L_00786c66; /* jmp 0x786c66 */
L_00786c76:;
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x1c], 1 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00786c86u); f_00786c97(c); /* call 0x786c97 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 20; return; /* ret 0x10 */
}

void f_00786c97(CPU *c) { /* FUN_10006c97 */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x1c], 0 */
    if (!c->zf) goto L_00786cae; /* jne 0x786cae */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00786caeu); f_00786caf(c); /* call 0x786caf */
L_00786cae:;
    c->esp += 4; return; /* ret  */
}

void f_00786caf(CPU *c) { /* FUN_10006caf */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x7903b0u; PUSH32(c, v_); } /* push 0x100103b0 */
    { uint32_t v_ = 0x789c84u; PUSH32(c, v_); } /* push 0x10009c84 */
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
L_00786cd8:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0x10u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 0x10] */
    if (c->sf) goto L_00786cf8; /* js 0x786cf8 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, R32((uint32_t)(c->ebp + 0xcu)))); /* sub ecx, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp + 8], ecx */
    { uint32_t t_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, 0x00786ce9u); call_indirect(c, t_); } /* call dword ptr [ebp + 0x14] */
    goto L_00786cd8; /* jmp 0x786cd8 */
L_00786cf8:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 20; return; /* ret 0x10 */
}

void f_00786ceb(CPU *c) { /* PTR_00786ceb */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffecu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x14] */
    PUSH32(c, 0x00786cf3u); f_0078737c(c); /* call 0x78737c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00786cf5(CPU *c) { /* PTR_00786cf5 */
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

void f_00786d0d(CPU *c) { /* FUN_10006d0d */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x7903c0u; PUSH32(c, v_); } /* push 0x100103c0 */
    { uint32_t v_ = 0x789c84u; PUSH32(c, v_); } /* push 0x10009c84 */
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
L_00786d3b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0x10u))); /* cmp eax, dword ptr [ebp + 0x10] */
    if ((c->sf == c->of)) goto L_00786d56; /* jge 0x786d56 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, 0x00786d4bu); call_indirect(c, t_); } /* call dword ptr [ebp + 0x14] */
    c->esi = (uint32_t)(add32(c, c->esi, R32((uint32_t)(c->ebp + 0xcu)))); /* add esi, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe4u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0x1c] */
    goto L_00786d3b; /* jmp 0x786d3b */
L_00786d56:;
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x20], 1 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00786d66u); f_00786d77(c); /* call 0x786d77 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 24; return; /* ret 0x14 */
}

void f_00786d77(CPU *c) { /* FUN_10006d77 */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x20], 0 */
    if (!c->zf) goto L_00786d8e; /* jne 0x786d8e */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00786d8eu); f_00786caf(c); /* call 0x786caf */
L_00786d8e:;
    c->esp += 4; return; /* ret  */
}

void f_00786d8f(CPU *c) { /* FUN_10006d8f */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x20u)); /* sub esp, 0x20 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x18], eax */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe0u)); /* lea eax, [ebp - 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x42u)); /* mov dword ptr [ebp - 0x14], 0x42 */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)((uint32_t)0x7fffffffu)); /* mov dword ptr [ebp - 0x1c], 0x7fffffff */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00786dbcu); f_007888dc(c); /* call 0x7888dc */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe4u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 0x1c] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    if (c->sf) goto L_00786dce; /* js 0x786dce */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov eax, dword ptr [ebp - 0x20] */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax], 0 */
    goto L_00786ddb; /* jmp 0x786ddb */
L_00786dce:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe0u)); /* lea eax, [ebp - 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    PUSH32(c, 0x00786dd9u); f_007887c4(c); /* call 0x7887c4 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00786ddb:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00786de0(CPU *c) { /* FUN_10006de0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_00786e75; /* jne 0x786e75 */
    { uint32_t t_ = R32((uint32_t)(0x790008u)); PUSH32(c, 0x00786df3u); call_indirect(c, t_); } /* call dword ptr [0x10010008] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    W32((uint32_t)(0x7956c4u), (uint32_t)(c->eax)); /* mov dword ptr [0x100156c4], eax */
    PUSH32(c, 0x00786dffu); f_0078a519(c); /* call 0x78a519 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00786e40; /* je 0x786e40 */
    c->eax = (uint32_t)(R32((uint32_t)(0x7956c4u))); /* mov eax, dword ptr [0x100156c4] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x7956c5u))); /* mov cl, byte ptr [0x100156c5] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xffu))); /* and eax, 0xff */
    { uint32_t a_ = (uint32_t)(0x7956c4u); W32(a_, (uint32_t)(shr32(c, R32(a_), 16))); } /* shr dword ptr [0x100156c4], 0x10 */
    W32((uint32_t)(0x7956ccu), (uint32_t)(c->eax)); /* mov dword ptr [0x100156cc], eax */
    W32((uint32_t)(0x7956d0u), (uint32_t)(c->ecx)); /* mov dword ptr [0x100156d0], ecx */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    W32((uint32_t)(0x7956c8u), (uint32_t)(c->eax)); /* mov dword ptr [0x100156c8], eax */
    PUSH32(c, 0x00786e37u); f_007877ec(c); /* call 0x7877ec */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00786e44; /* jne 0x786e44 */
    PUSH32(c, 0x00786e40u); f_0078a576(c); /* call 0x78a576 */
L_00786e40:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00786eb6; /* jmp 0x786eb6 */
L_00786e44:;
    { uint32_t t_ = R32((uint32_t)(0x790004u)); PUSH32(c, 0x00786e4au); call_indirect(c, t_); } /* call dword ptr [0x10010004] */
    W32((uint32_t)(0x796db4u), (uint32_t)(c->eax)); /* mov dword ptr [0x10016db4], eax */
    PUSH32(c, 0x00786e54u); f_0078a272(c); /* call 0x78a272 */
    W32((uint32_t)(0x7956b0u), (uint32_t)(c->eax)); /* mov dword ptr [0x100156b0], eax */
    PUSH32(c, 0x00786e5eu); f_00789d5c(c); /* call 0x789d5c */
    PUSH32(c, 0x00786e63u); f_0078a025(c); /* call 0x78a025 */
    PUSH32(c, 0x00786e68u); f_00789f6c(c); /* call 0x789f6c */
    PUSH32(c, 0x00786e6du); f_00787a2f(c); /* call 0x787a2f */
    { uint32_t a_ = (uint32_t)(0x7956acu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [0x100156ac] */
    goto L_00786eb3; /* jmp 0x786eb3 */
L_00786e75:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->zf) goto L_00786ea7; /* jne 0x786ea7 */
    (void)sub32(c, R32((uint32_t)(0x7956acu)), c->ecx); /* cmp dword ptr [0x100156ac], ecx */
    if ((c->zf || c->sf != c->of)) goto L_00786e40; /* jle 0x786e40 */
    { uint32_t a_ = (uint32_t)(0x7956acu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [0x100156ac] */
    (void)sub32(c, R32((uint32_t)(0x7956fcu)), c->ecx); /* cmp dword ptr [0x100156fc], ecx */
    if (!c->zf) goto L_00786e96; /* jne 0x786e96 */
    PUSH32(c, 0x00786e96u); f_00787a6d(c); /* call 0x787a6d */
L_00786e96:;
    PUSH32(c, 0x00786e9bu); f_00789f18(c); /* call 0x789f18 */
    PUSH32(c, 0x00786ea0u); f_00787840(c); /* call 0x787840 */
    PUSH32(c, 0x00786ea5u); f_0078a576(c); /* call 0x78a576 */
    goto L_00786eb3; /* jmp 0x786eb3 */
L_00786ea7:;
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_00786eb3; /* jne 0x786eb3 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00786eb2u); f_007878d8(c); /* call 0x7878d8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00786eb3:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00786eb6:;
    c->esp += 16; return; /* ret 0xc */
}

void f_00786eb9(CPU *c) { /* entry */
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
    if (!c->zf) goto L_00786ed5; /* jne 0x786ed5 */
    (void)sub32(c, R32((uint32_t)(0x7956acu)), (uint32_t)0x0u); /* cmp dword ptr [0x100156ac], 0 */
    goto L_00786efb; /* jmp 0x786efb */
L_00786ed5:;
    (void)sub32(c, c->esi, (uint32_t)0x1u); /* cmp esi, 1 */
    if (c->zf) goto L_00786edf; /* je 0x786edf */
    (void)sub32(c, c->esi, (uint32_t)0x2u); /* cmp esi, 2 */
    if (!c->zf) goto L_00786f01; /* jne 0x786f01 */
L_00786edf:;
    c->eax = (uint32_t)(R32((uint32_t)(0x796db8u))); /* mov eax, dword ptr [0x10016db8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00786ef1; /* je 0x786ef1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00786eedu); call_indirect(c, t_); } /* call eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00786efd; /* je 0x786efd */
L_00786ef1:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00786ef9u); f_00786de0(c); /* call 0x786de0 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
L_00786efb:;
    if (!c->zf) goto L_00786f01; /* jne 0x786f01 */
L_00786efd:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00786f4f; /* jmp 0x786f4f */
L_00786f01:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00786f09u); f_0078a61e(c); /* call 0x78a61e */
    (void)sub32(c, c->esi, (uint32_t)0x1u); /* cmp esi, 1 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0xc], eax */
    if (!c->zf) goto L_00786f1d; /* jne 0x786f1d */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00786f4c; /* jne 0x786f4c */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00786f1du); f_00786de0(c); /* call 0x786de0 */
L_00786f1d:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00786f26; /* je 0x786f26 */
    (void)sub32(c, c->esi, (uint32_t)0x3u); /* cmp esi, 3 */
    if (!c->zf) goto L_00786f4c; /* jne 0x786f4c */
L_00786f26:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00786f2eu); f_00786de0(c); /* call 0x786de0 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00786f35; /* jne 0x786f35 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->eax)))); } /* and dword ptr [ebp + 0xc], eax */
L_00786f35:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    if (c->zf) goto L_00786f4c; /* je 0x786f4c */
    c->eax = (uint32_t)(R32((uint32_t)(0x796db8u))); /* mov eax, dword ptr [0x10016db8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00786f4c; /* je 0x786f4c */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00786f49u); call_indirect(c, t_); } /* call eax */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0xc], eax */
L_00786f4c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
L_00786f4f:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 16; return; /* ret 0xc */
}

void f_00786f56(CPU *c) { /* __amsg_exit */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x7956b8u))); /* mov eax, dword ptr [0x100156b8] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_00786f6d; /* je 0x786f6d */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00786f72; /* jne 0x786f72 */
    (void)sub32(c, R32((uint32_t)(0x7956bcu)), (uint32_t)0x1u); /* cmp dword ptr [0x100156bc], 1 */
    if (!c->zf) goto L_00786f72; /* jne 0x786f72 */
L_00786f6d:;
    PUSH32(c, 0x00786f72u); f_0078a624(c); /* call 0x78a624 */
L_00786f72:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    PUSH32(c, 0x00786f7bu); f_0078a65d(c); /* call 0x78a65d */
    { uint32_t v_ = 0xffu; PUSH32(c, v_); } /* push 0xff */
    { uint32_t t_ = R32((uint32_t)(0x7925c0u)); PUSH32(c, 0x00786f86u); call_indirect(c, t_); } /* call dword ptr [0x100125c0] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00786f86(CPU *c) { /* PTR_00786f86 */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00786f89(CPU *c) { /* FUN_10006f89 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov esi, dword ptr [ebp + 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)((uint32_t)0x19930520u); /* mov edi, 0x19930520 */
    (void)sub32(c, R32((uint32_t)(c->esi)), c->edi); /* cmp dword ptr [esi], edi */
    if (c->zf) goto L_00786f9f; /* je 0x786f9f */
    PUSH32(c, 0x00786f9fu); f_007879d9(c); /* call 0x7879d9 */
L_00786f9f:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + 0x4u)) & (uint8_t)0x66u)); /* test byte ptr [eax + 4], 0x66 */
    if (c->zf) goto L_00786fc7; /* je 0x786fc7 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x4u)), (uint32_t)0x0u); /* cmp dword ptr [esi + 4], 0 */
    if (c->zf) goto L_0078701d; /* je 0x78701d */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x1c], 0 */
    if (!c->zf) goto L_0078701d; /* jne 0x78701d */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x00786fc2u); f_007872de(c); /* call 0x7872de */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    goto L_0078701d; /* jmp 0x78701d */
L_00786fc7:;
    (void)sub32(c, R32((uint32_t)(c->esi + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [esi + 0xc], 0 */
    if (c->zf) goto L_0078701d; /* je 0x78701d */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xe06d7363u); /* cmp dword ptr [eax], 0xe06d7363 */
    if (!c->zf) goto L_00787001; /* jne 0x787001 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x14u)), c->edi); /* cmp dword ptr [eax + 0x14], edi */
    if ((c->cf || c->zf)) goto L_00787001; /* jbe 0x787001 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x1cu))); /* mov ecx, dword ptr [eax + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov ecx, dword ptr [ecx + 8] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00787001; /* je 0x787001 */
    c->edx = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0x24u))); /* movzx edx, byte ptr [ebp + 0x24] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = c->ecx; PUSH32(c, 0x00786ffcu); call_indirect(c, t_); } /* call ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    goto L_00787020; /* jmp 0x787020 */
L_00787001:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x24u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x24] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0078701au); f_00787024(c); /* call 0x787024 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
L_0078701d:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00787020:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00787024(CPU *c) { /* FUN_10007024 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffecu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp - 0x14], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x10], eax */
    if ((c->sf != c->of)) goto L_00787044; /* jl 0x787044 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov ecx, dword ptr [ebp + 0x18] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ecx + 0x4u))); /* cmp eax, dword ptr [ecx + 4] */
    if ((c->sf != c->of)) goto L_00787049; /* jl 0x787049 */
L_00787044:;
    PUSH32(c, 0x00787049u); f_007879d9(c); /* call 0x7879d9 */
L_00787049:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    c->ebx = (uint32_t)((uint32_t)0xe06d7363u); /* mov ebx, 0xe06d7363 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)((uint32_t)0x19930520u); /* mov edi, 0x19930520 */
    (void)sub32(c, R32((uint32_t)(c->esi)), c->ebx); /* cmp dword ptr [esi], ebx */
    if (!c->zf) goto L_007871ac; /* jne 0x7871ac */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [esi + 0x10], 3 */
    if (!c->zf) goto L_007870c9; /* jne 0x7870c9 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x14u)), c->edi); /* cmp dword ptr [esi + 0x14], edi */
    if (!c->zf) goto L_007870c9; /* jne 0x7870c9 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [esi + 0x1c], 0 */
    if (!c->zf) goto L_007870c9; /* jne 0x7870c9 */
    PUSH32(c, 0x00787077u); f_00787871(c); /* call 0x787871 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x6cu)), (uint32_t)0x0u); /* cmp dword ptr [eax + 0x6c], 0 */
    if (c->zf) goto L_007871a7; /* je 0x7871a7 */
    PUSH32(c, 0x00787086u); f_00787871(c); /* call 0x787871 */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + 0x6cu))); /* mov esi, dword ptr [eax + 0x6c] */
    PUSH32(c, 0x0078708eu); f_00787871(c); /* call 0x787871 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x70u))); /* mov eax, dword ptr [eax + 0x70] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x10], eax */
    W8((uint32_t)(c->ebp + 0xffffffecu), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ebp - 0x14], 1 */
    PUSH32(c, 0x007870a0u); f_0078a7b0(c); /* call 0x78a7b0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_007870ab; /* jne 0x7870ab */
    PUSH32(c, 0x007870abu); f_007879d9(c); /* call 0x7879d9 */
L_007870ab:;
    (void)sub32(c, R32((uint32_t)(c->esi)), c->ebx); /* cmp dword ptr [esi], ebx */
    if (!c->zf) goto L_007871ac; /* jne 0x7871ac */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [esi + 0x10], 3 */
    if (!c->zf) goto L_007870c9; /* jne 0x7870c9 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x14u)), c->edi); /* cmp dword ptr [esi + 0x14], edi */
    if (!c->zf) goto L_007870c9; /* jne 0x7870c9 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [esi + 0x1c], 0 */
    if (!c->zf) goto L_007870c9; /* jne 0x7870c9 */
    PUSH32(c, 0x007870c9u); f_007879d9(c); /* call 0x7879d9 */
L_007870c9:;
    (void)sub32(c, R32((uint32_t)(c->esi)), c->ebx); /* cmp dword ptr [esi], ebx */
    if (!c->zf) goto L_007871ac; /* jne 0x7871ac */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [esi + 0x10], 3 */
    if (!c->zf) goto L_007871ac; /* jne 0x7871ac */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x14u)), c->edi); /* cmp dword ptr [esi + 0x14], edi */
    if (!c->zf) goto L_007871ac; /* jne 0x7871ac */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov edi, dword ptr [ebp - 0x10] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe8u)); /* lea eax, [ebp - 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    PUSH32(c, 0x007870fbu); f_007866cb(c); /* call 0x7866cb */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
L_00787100:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xffffffe8u))); /* cmp eax, dword ptr [ebp - 0x18] */
    if (!c->cf) goto L_00787197; /* jae 0x787197 */
    (void)sub32(c, R32((uint32_t)(c->ebx)), c->edi); /* cmp dword ptr [ebx], edi */
    if ((!c->zf && c->sf == c->of)) goto L_0078718c; /* jg 0x78718c */
    (void)sub32(c, c->edi, R32((uint32_t)(c->ebx + 0x4u))); /* cmp edi, dword ptr [ebx + 4] */
    if ((!c->zf && c->sf == c->of)) goto L_0078718c; /* jg 0x78718c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x10u))); /* mov eax, dword ptr [ebx + 0x10] */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xcu))); /* mov eax, dword ptr [ebx + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    if ((c->zf || c->sf != c->of)) goto L_00787189; /* jle 0x787189 */
L_00787125:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x1cu))); /* mov eax, dword ptr [esi + 0x1c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0xcu))); /* mov eax, dword ptr [eax + 0xc] */
    c->edi = (uint32_t)((uint32_t)(c->eax + 0x4u)); /* lea edi, [eax + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    if ((c->zf || c->sf != c->of)) goto L_00787156; /* jle 0x787156 */
L_00787137:;
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [esi + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->edi)); PUSH32(c, v_); } /* push dword ptr [edi] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00787144u); f_00787281(c); /* call 0x787281 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00787165; /* jne 0x787165 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 8] */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff8u)), c->eax); /* cmp dword ptr [ebp - 8], eax */
    if ((!c->zf && c->sf == c->of)) goto L_00787137; /* jg 0x787137 */
L_00787156:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff4u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x10u))); } /* add dword ptr [ebp + 8], 0x10 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0xc], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_00787125; /* jg 0x787125 */
    goto L_00787189; /* jmp 0x787189 */
L_00787165:;
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
    PUSH32(c, 0x00787186u); f_00787392(c); /* call 0x787392 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
L_00787189:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov edi, dword ptr [ebp - 0x10] */
L_0078718c:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x14u)); /* add ebx, 0x14 */
    goto L_00787100; /* jmp 0x787100 */
L_00787197:;
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x1cu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0x1c], 0 */
    if (c->zf) goto L_007871a7; /* je 0x7871a7 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x007871a5u); f_00787716(c); /* call 0x787716 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_007871a7:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_007871ac:;
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x1cu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0x1c], 0 */
    if (!c->zf) goto L_007871d2; /* jne 0x7871d2 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x24u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffff0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x007871cdu); f_007871d7(c); /* call 0x7871d7 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    goto L_007871a7; /* jmp 0x7871a7 */
L_007871d2:;
    { f_00787978(c); return; } /* jmp 0x787978 */
}

void f_007871d7(CPU *c) { /* FUN_100071d7 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x007871e3u); f_00787871(c); /* call 0x787871 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x68u)), (uint32_t)0x0u); /* cmp dword ptr [eax + 0x68], 0 */
    if (c->zf) goto L_0078720a; /* je 0x78720a */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x24u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00787203u); f_007865a0(c); /* call 0x7865a0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_0078727d; /* jne 0x78727d */
L_0078720a:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov edi, dword ptr [ebp + 0x1c] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    PUSH32(c, 0x00787221u); f_007866cb(c); /* call 0x7866cb */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_00787226:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xfffffff8u))); /* cmp eax, dword ptr [ebp - 8] */
    if (!c->cf) goto L_0078727d; /* jae 0x78727d */
    (void)sub32(c, c->edi, R32((uint32_t)(c->esi))); /* cmp edi, dword ptr [esi] */
    if ((c->sf != c->of)) goto L_00787275; /* jl 0x787275 */
    (void)sub32(c, c->edi, R32((uint32_t)(c->esi + 0x4u))); /* cmp edi, dword ptr [esi + 4] */
    if ((!c->zf && c->sf == c->of)) goto L_00787275; /* jg 0x787275 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0xfffffff4u))); /* mov ecx, dword ptr [eax - 0xc] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_0078724f; /* je 0x78724f */
    (void)sub8(c, R8((uint32_t)(c->ecx + 0x8u)), (uint8_t)0x0u); /* cmp byte ptr [ecx + 8], 0 */
    if (!c->zf) goto L_00787275; /* jne 0x787275 */
L_0078724f:;
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
    PUSH32(c, 0x00787272u); f_00787392(c); /* call 0x787392 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
L_00787275:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x14u)); /* add esi, 0x14 */
    goto L_00787226; /* jmp 0x787226 */
L_0078727d:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00787281(CPU *c) { /* FUN_10007281 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edi, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov eax, dword ptr [edi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_007872d8; /* je 0x7872d8 */
    (void)sub8(c, R8((uint32_t)(c->eax + 0x8u)), (uint8_t)0x0u); /* cmp byte ptr [eax + 8], 0 */
    c->edx = (uint32_t)((uint32_t)(c->eax + 0x8u)); /* lea edx, [eax + 8] */
    if (c->zf) goto L_007872d8; /* je 0x7872d8 */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (c->zf) goto L_007872b2; /* je 0x7872b2 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x8u)); /* add ecx, 8 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x007872acu); f_00788740(c); /* call 0x788740 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_007872d4; /* jne 0x7872d4 */
L_007872b2:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi)) & (uint8_t)0x2u)); /* test byte ptr [esi], 2 */
    if (c->zf) goto L_007872bc; /* je 0x7872bc */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edi)) & (uint8_t)0x8u)); /* test byte ptr [edi], 8 */
    if (c->zf) goto L_007872d4; /* je 0x7872d4 */
L_007872bc:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    if (c->zf) goto L_007872cb; /* je 0x7872cb */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edi)) & (uint8_t)0x1u)); /* test byte ptr [edi], 1 */
    if (c->zf) goto L_007872d4; /* je 0x7872d4 */
L_007872cb:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x2u)); /* test al, 2 */
    if (c->zf) goto L_007872d8; /* je 0x7872d8 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edi)) & (uint8_t)0x2u)); /* test byte ptr [edi], 2 */
    if (!c->zf) goto L_007872d8; /* jne 0x7872d8 */
L_007872d4:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_007872db; /* jmp 0x7872db */
L_007872d8:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_007872db:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_007872de(CPU *c) { /* FUN_100072de */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x7903d0u; PUSH32(c, v_); } /* push 0x100103d0 */
    { uint32_t v_ = 0x789c84u; PUSH32(c, v_); } /* push 0x10009c84 */
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
L_00787310:;
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0x14u))); /* cmp esi, dword ptr [ebp + 0x14] */
    if (c->zf) goto L_0078736a; /* je 0x78736a */
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if ((c->zf || c->sf != c->of)) goto L_0078731f; /* jle 0x78731f */
    (void)sub32(c, c->esi, R32((uint32_t)(c->edi + 0x4u))); /* cmp esi, dword ptr [edi + 4] */
    if ((c->sf != c->of)) goto L_00787324; /* jl 0x787324 */
L_0078731f:;
    PUSH32(c, 0x00787324u); f_007879d9(c); /* call 0x7879d9 */
L_00787324:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8 + 0x4u))); /* mov eax, dword ptr [eax + esi*8 + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0078733f; /* je 0x78733f */
    { uint32_t v_ = 0x103u; PUSH32(c, v_); } /* push 0x103 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0078733fu); f_007877a0(c); /* call 0x7877a0 */
L_0078733f:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    goto L_0078735f; /* jmp 0x78735f */
L_0078735f:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8))); /* mov esi, dword ptr [eax + esi*8] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x1c], esi */
    goto L_00787310; /* jmp 0x787310 */
L_0078736a:;
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebx + 8], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00787310(CPU *c) { /* PTR_00787310 */
    PREEMPT_POLL(c);
L_00787310:;
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0x14u))); /* cmp esi, dword ptr [ebp + 0x14] */
    if (c->zf) goto L_0078736a; /* je 0x78736a */
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if ((c->zf || c->sf != c->of)) goto L_0078731f; /* jle 0x78731f */
    (void)sub32(c, c->esi, R32((uint32_t)(c->edi + 0x4u))); /* cmp esi, dword ptr [edi + 4] */
    if ((c->sf != c->of)) goto L_00787324; /* jl 0x787324 */
L_0078731f:;
    PUSH32(c, 0x00787324u); f_007879d9(c); /* call 0x7879d9 */
L_00787324:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8 + 0x4u))); /* mov eax, dword ptr [eax + esi*8 + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0078733f; /* je 0x78733f */
    { uint32_t v_ = 0x103u; PUSH32(c, v_); } /* push 0x103 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0078733fu); f_007877a0(c); /* call 0x7877a0 */
L_0078733f:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    goto L_0078735f; /* jmp 0x78735f */
L_0078735f:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8))); /* mov esi, dword ptr [eax + esi*8] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x1c], esi */
    goto L_00787310; /* jmp 0x787310 */
L_0078736a:;
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebx + 8], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00787345(CPU *c) { /* PTR_00787345 */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffecu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x14] */
    PUSH32(c, 0x0078734du); f_0078737c(c); /* call 0x78737c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_0078734f(CPU *c) { /* PTR_0078734f */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edi, dword ptr [ebp + 0x10] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov esi, dword ptr [ebp - 0x1c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8))); /* mov esi, dword ptr [eax + esi*8] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x1c], esi */
    { f_00787310(c); return; } /* jmp 0x787310 */
}

void f_0078737c(CPU *c) { /* FUN_1000737c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xe06d7363u); /* cmp dword ptr [eax], 0xe06d7363 */
    if (c->zf) goto L_0078738d; /* je 0x78738d */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_0078738d:;
    { f_00787978(c); return; } /* jmp 0x787978 */
}

void f_00787392(CPU *c) { /* FUN_10007392 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x20u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x20], 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov ebx, dword ptr [ebp + 0x1c] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    if (c->zf) goto L_007873b4; /* je 0x7873b4 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x007873b1u); f_00787552(c); /* call 0x787552 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_007873b4:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x2cu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x2c], 0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    if (!c->zf) goto L_007873c0; /* jne 0x7873c0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    goto L_007873c3; /* jmp 0x7873c3 */
L_007873c0:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x2cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x2c] */
L_007873c3:;
    PUSH32(c, 0x007873c8u); f_007864a2(c); /* call 0x7864a2 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x24u))); /* mov esi, dword ptr [ebp + 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x007873d9u); f_007872de(c); /* call 0x7872de */
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
    PUSH32(c, 0x007873fau); f_0078740d(c); /* call 0x78740d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00787408; /* je 0x787408 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00787408u); f_00786460(c); /* call 0x786460 */
L_00787408:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_0078740d(CPU *c) { /* FUN_1000740d */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x7903e0u; PUSH32(c, v_); } /* push 0x100103e0 */
    { uint32_t v_ = 0x789c84u; PUSH32(c, v_); } /* push 0x10009c84 */
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
    PUSH32(c, 0x0078744bu); f_00787871(c); /* call 0x787871 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x6cu))); /* mov eax, dword ptr [eax + 0x6c] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    PUSH32(c, 0x00787456u); f_00787871(c); /* call 0x787871 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x70u))); /* mov eax, dword ptr [eax + 0x70] */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    PUSH32(c, 0x00787461u); f_00787871(c); /* call 0x787871 */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    W32((uint32_t)(c->eax + 0x6cu), (uint32_t)(c->edi)); /* mov dword ptr [eax + 0x6c], edi */
    PUSH32(c, 0x0078746cu); f_00787871(c); /* call 0x787871 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    W32((uint32_t)(c->eax + 0x70u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x70], ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x0078748du); f_00786527(c); /* call 0x786527 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x2c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x007874a0u); f_007874da(c); /* call 0x7874da */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd4u))); /* mov eax, dword ptr [ebp - 0x2c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_007874a3(CPU *c) { /* PTR_007874a3 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_007874b2(CPU *c) { /* PTR_007874b2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffecu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x14] */
    PUSH32(c, 0x007874bau); f_00787528(c); /* call 0x787528 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_007874bc(CPU *c) { /* PTR_007874bc */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffd4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x2c], 0 */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x007874ceu); f_0078678a(c); /* call 0x78678a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { f_007874a3(c); return; } /* jmp 0x7874a3 */
}

void f_007874d4(CPU *c) { /* PTR_007874d4 */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    { f_007874da(c); return; }
}

void f_007874da(CPU *c) { /* FUN_100074da */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    W32((uint32_t)(c->esi + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [esi - 4], eax */
    PUSH32(c, 0x007874e5u); f_00787871(c); /* call 0x787871 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov ecx, dword ptr [ebp - 0x1c] */
    W32((uint32_t)(c->eax + 0x6cu), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x6c], ecx */
    PUSH32(c, 0x007874f0u); f_00787871(c); /* call 0x787871 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov ecx, dword ptr [ebp - 0x20] */
    W32((uint32_t)(c->eax + 0x70u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x70], ecx */
    (void)sub32(c, R32((uint32_t)(c->edi)), (uint32_t)0xe06d7363u); /* cmp dword ptr [edi], 0xe06d7363 */
    if (!c->zf) goto L_00787527; /* jne 0x787527 */
    (void)sub32(c, R32((uint32_t)(c->edi + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [edi + 0x10], 3 */
    if (!c->zf) goto L_00787527; /* jne 0x787527 */
    (void)sub32(c, R32((uint32_t)(c->edi + 0x14u)), (uint32_t)0x19930520u); /* cmp dword ptr [edi + 0x14], 0x19930520 */
    if (!c->zf) goto L_00787527; /* jne 0x787527 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00787527; /* jne 0x787527 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x2c], 0 */
    if (c->zf) goto L_00787527; /* je 0x787527 */
    PUSH32(c, 0x0078751eu); f_007867f2(c); /* call 0x7867f2 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00787525u); f_00787716(c); /* call 0x787716 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00787527:;
    c->esp += 4; return; /* ret  */
}

void f_00787528(CPU *c) { /* FUN_10007528 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xe06d7363u); /* cmp dword ptr [eax], 0xe06d7363 */
    if (!c->zf) goto L_0078754f; /* jne 0x78754f */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [eax + 0x10], 3 */
    if (!c->zf) goto L_0078754f; /* jne 0x78754f */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x14u)), (uint32_t)0x19930520u); /* cmp dword ptr [eax + 0x14], 0x19930520 */
    if (!c->zf) goto L_0078754f; /* jne 0x78754f */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [eax + 0x1c], 0 */
    if (!c->zf) goto L_0078754f; /* jne 0x78754f */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
L_0078754f:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_00787552(CPU *c) { /* FUN_10007552 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x7903f8u; PUSH32(c, v_); } /* push 0x100103f8 */
    { uint32_t v_ = 0x789c84u; PUSH32(c, v_); } /* push 0x10009c84 */
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
    if (c->zf) goto L_007876fb; /* je 0x7876fb */
    (void)sub8(c, R8((uint32_t)(c->eax + 0x8u)), (uint8_t)0x0u); /* cmp byte ptr [eax + 8], 0 */
    if (c->zf) goto L_007876fb; /* je 0x7876fb */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov eax, dword ptr [ecx + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_007876fb; /* je 0x7876fb */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
    c->edi = (uint32_t)((uint32_t)(c->eax + c->edx + 0xcu)); /* lea edi, [eax + edx + 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ecx)) & (uint8_t)0x8u)); /* test byte ptr [ecx], 8 */
    if (c->zf) goto L_007875ef; /* je 0x7875ef */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x18] */
    PUSH32(c, 0x007875b8u); f_0078a7b0(c); /* call 0x78a7b0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_007876f2; /* je 0x7876f2 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x007875cau); f_0078a7cc(c); /* call 0x78a7cc */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_007876f2; /* je 0x7876f2 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x18u))); /* mov eax, dword ptr [esi + 0x18] */
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov ecx, dword ptr [ebp + 0x14] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x8u)); /* add ecx, 8 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
L_007875e0:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x007875e6u); f_0078777d(c); /* call 0x78777d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    goto L_007876f7; /* jmp 0x7876f7 */
L_007875ef:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov esi, dword ptr [ebp + 0x14] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi)) & (uint8_t)0x1u)); /* test byte ptr [esi], 1 */
    if (c->zf) goto L_00787649; /* je 0x787649 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    PUSH32(c, 0x00787604u); f_0078a7b0(c); /* call 0x78a7b0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_007876f2; /* je 0x7876f2 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00787616u); f_0078a7cc(c); /* call 0x78a7cc */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_007876f2; /* je 0x7876f2 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x14u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x0078762cu); f_0078a800(c); /* call 0x78a800 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x14u)), (uint32_t)0x4u); /* cmp dword ptr [esi + 0x14], 4 */
    if (!c->zf) goto L_007876f7; /* jne 0x7876f7 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_007876f7; /* je 0x7876f7 */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x8u)); /* add esi, 8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    goto L_007875e0; /* jmp 0x7875e0 */
L_00787649:;
    (void)sub32(c, R32((uint32_t)(c->esi + 0x18u)), (uint32_t)0x0u); /* cmp dword ptr [esi + 0x18], 0 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    if (!c->zf) goto L_00787691; /* jne 0x787691 */
    PUSH32(c, 0x0078765cu); f_0078a7b0(c); /* call 0x78a7b0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_007876f2; /* je 0x7876f2 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x0078766eu); f_0078a7cc(c); /* call 0x78a7cc */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_007876f2; /* je 0x7876f2 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x14u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x14] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x8u)); /* add esi, 8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    PUSH32(c, 0x00787683u); f_0078777d(c); /* call 0x78777d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x0078768cu); f_0078a800(c); /* call 0x78a800 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_007876f7; /* jmp 0x7876f7 */
L_00787691:;
    PUSH32(c, 0x00787696u); f_0078a7b0(c); /* call 0x78a7b0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_007876f2; /* je 0x7876f2 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x007876a4u); f_0078a7cc(c); /* call 0x78a7cc */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_007876f2; /* je 0x7876f2 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x18] */
    PUSH32(c, 0x007876b2u); f_0078a7e8(c); /* call 0x78a7e8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_007876f2; /* je 0x7876f2 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi)) & (uint8_t)0x4u)); /* test byte ptr [esi], 4 */
    if (c->zf) goto L_007876d8; /* je 0x7876d8 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x8u)); /* lea eax, [esi + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    PUSH32(c, 0x007876cau); f_0078777d(c); /* call 0x78777d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x007876d6u); f_0078649b(c); /* call 0x78649b */
    goto L_007876f7; /* jmp 0x7876f7 */
L_007876d8:;
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x8u)); /* lea eax, [esi + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    PUSH32(c, 0x007876e4u); f_0078777d(c); /* call 0x78777d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x007876f0u); f_00786494(c); /* call 0x786494 */
    goto L_007876f7; /* jmp 0x7876f7 */
L_007876f2:;
    PUSH32(c, 0x007876f7u); f_007879d9(c); /* call 0x7879d9 */
L_007876f7:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
L_007876fb:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0078770a(CPU *c) { /* PTR_0078770a */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_0078770e(CPU *c) { /* PTR_0078770e */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { f_00787978(c); return; } /* jmp 0x787978 */
}

void f_00787716(CPU *c) { /* FUN_10007716 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x790408u; PUSH32(c, v_); } /* push 0x10010408 */
    { uint32_t v_ = 0x789c84u; PUSH32(c, v_); } /* push 0x10009c84 */
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
    if (c->zf) goto L_0078775d; /* je 0x78775d */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x1cu))); /* mov ecx, dword ptr [eax + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ecx, dword ptr [ecx + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_0078775d; /* je 0x78775d */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = R32((uint32_t)(c->eax + 0x18u)); PUSH32(c, v_); } /* push dword ptr [eax + 0x18] */
    PUSH32(c, 0x00787759u); f_00786494(c); /* call 0x786494 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
L_0078775d:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0078776c(CPU *c) { /* PTR_0078776c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xcu)), ((uint8_t)c->eax)); /* cmp byte ptr [ebp + 0xc], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(!c->zf ? 1 : 0); /* setne al */
    c->esp += 4; return; /* ret  */
}

void f_00787775(CPU *c) { /* PTR_00787775 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { f_00787978(c); return; } /* jmp 0x787978 */
}

void f_0078777d(CPU *c) { /* FUN_1000777d */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov edx, dword ptr [ecx + 4] */
    c->eax = (uint32_t)(add32(c, c->eax, c->esi)); /* add eax, esi */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if ((c->sf != c->of)) goto L_0078779e; /* jl 0x78779e */
    c->esi = (uint32_t)(R32((uint32_t)(c->edx + c->esi))); /* mov esi, dword ptr [edx + esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov ecx, dword ptr [ecx + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + c->ecx))); /* mov ecx, dword ptr [esi + ecx] */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->edx)); /* add ecx, edx */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
L_0078779e:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_007877a0(CPU *c) { /* __CallSettingFrame@12 */
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
    PUSH32(c, 0x007877c3u); f_00786815(c); /* call 0x786815 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = c->eax; PUSH32(c, 0x007877c7u); call_indirect(c, t_); } /* call eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->ebx = (uint32_t)(c->ebp); /* mov ebx, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->ebx); /* mov ebp, ebx */
    (void)sub32(c, c->ecx, (uint32_t)0x100u); /* cmp ecx, 0x100 */
    if (!c->zf) goto L_007877df; /* jne 0x7877df */
    c->ecx = (uint32_t)((uint32_t)0x2u); /* mov ecx, 2 */
L_007877df:;
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x007877e5u); f_00786815(c); /* call 0x786815 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 16; return; /* ret 0xc */
}

void f_007877ec(CPU *c) { /* FUN_100077ec */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x007877f2u); f_00788543(c); /* call 0x788543 */
    { uint32_t t_ = R32((uint32_t)(0x790014u)); PUSH32(c, 0x007877f8u); call_indirect(c, t_); } /* call dword ptr [0x10010014] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    W32((uint32_t)(0x7925d0u), (uint32_t)(c->eax)); /* mov dword ptr [0x100125d0], eax */
    if (c->zf) goto L_0078783c; /* je 0x78783c */
    { uint32_t v_ = 0x74u; PUSH32(c, v_); } /* push 0x74 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x0078780bu); f_0078ab35(c); /* call 0x78ab35 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_0078783c; /* je 0x78783c */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(0x7925d0u)); PUSH32(c, v_); } /* push dword ptr [0x100125d0] */
    { uint32_t t_ = R32((uint32_t)(0x790010u)); PUSH32(c, 0x00787820u); call_indirect(c, t_); } /* call dword ptr [0x10010010] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0078783c; /* je 0x78783c */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x0078782au); f_0078785e(c); /* call 0x78785e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t t_ = R32((uint32_t)(0x79000cu)); PUSH32(c, 0x00787831u); call_indirect(c, t_); } /* call dword ptr [0x1001000c] */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [esi + 4], 0xffffffff */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_0078783c:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00787840(CPU *c) { /* FUN_10007840 */
    PREEMPT_POLL(c);
    PUSH32(c, 0x00787845u); f_0078856c(c); /* call 0x78856c */
    c->eax = (uint32_t)(R32((uint32_t)(0x7925d0u))); /* mov eax, dword ptr [0x100125d0] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (c->zf) goto L_0078785d; /* je 0x78785d */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x790018u)); PUSH32(c, 0x00787856u); call_indirect(c, t_); } /* call dword ptr [0x10010018] */
    { uint32_t a_ = (uint32_t)(0x7925d0u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [0x100125d0], 0xffffffff */
L_0078785d:;
    c->esp += 4; return; /* ret  */
}

void f_0078785e(CPU *c) { /* FUN_1000785e */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    W32((uint32_t)(c->eax + 0x50u), (uint32_t)((uint32_t)0x7928a0u)); /* mov dword ptr [eax + 0x50], 0x100128a0 */
    W32((uint32_t)(c->eax + 0x14u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [eax + 0x14], 1 */
    c->esp += 4; return; /* ret  */
}

void f_00787871(CPU *c) { /* FUN_10007871 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0x790024u)); PUSH32(c, 0x00787879u); call_indirect(c, t_); } /* call dword ptr [0x10010024] */
    { uint32_t v_ = R32((uint32_t)(0x7925d0u)); PUSH32(c, v_); } /* push dword ptr [0x100125d0] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    { uint32_t t_ = R32((uint32_t)(0x790020u)); PUSH32(c, 0x00787887u); call_indirect(c, t_); } /* call dword ptr [0x10010020] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_007878cc; /* jne 0x7878cc */
    { uint32_t v_ = 0x74u; PUSH32(c, v_); } /* push 0x74 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x00787896u); f_0078ab35(c); /* call 0x78ab35 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_007878c4; /* je 0x7878c4 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(0x7925d0u)); PUSH32(c, v_); } /* push dword ptr [0x100125d0] */
    { uint32_t t_ = R32((uint32_t)(0x790010u)); PUSH32(c, 0x007878abu); call_indirect(c, t_); } /* call dword ptr [0x10010010] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_007878c4; /* je 0x7878c4 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x007878b5u); f_0078785e(c); /* call 0x78785e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t t_ = R32((uint32_t)(0x79000cu)); PUSH32(c, 0x007878bcu); call_indirect(c, t_); } /* call dword ptr [0x1001000c] */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [esi + 4], 0xffffffff */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    goto L_007878cc; /* jmp 0x7878cc */
L_007878c4:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    PUSH32(c, 0x007878cbu); f_00786f56(c); /* call 0x786f56 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_007878cc:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0x79001cu)); PUSH32(c, 0x007878d3u); call_indirect(c, t_); } /* call dword ptr [0x1001001c] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_007878d8(CPU *c) { /* FUN_100078d8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x7925d0u))); /* mov eax, dword ptr [0x100125d0] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (c->zf) goto L_00787977; /* je 0x787977 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_007878fc; /* jne 0x7878fc */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x790020u)); PUSH32(c, 0x007878f6u); call_indirect(c, t_); } /* call dword ptr [0x10010020] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00787968; /* je 0x787968 */
L_007878fc:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov eax, dword ptr [esi + 0x24] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0078790a; /* je 0x78790a */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00787909u); f_0078864e(c); /* call 0x78864e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_0078790a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x28u))); /* mov eax, dword ptr [esi + 0x28] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00787918; /* je 0x787918 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00787917u); f_0078864e(c); /* call 0x78864e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00787918:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x30u))); /* mov eax, dword ptr [esi + 0x30] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00787926; /* je 0x787926 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00787925u); f_0078864e(c); /* call 0x78864e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00787926:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x38u))); /* mov eax, dword ptr [esi + 0x38] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00787934; /* je 0x787934 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00787933u); f_0078864e(c); /* call 0x78864e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00787934:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x40u))); /* mov eax, dword ptr [esi + 0x40] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00787942; /* je 0x787942 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00787941u); f_0078864e(c); /* call 0x78864e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00787942:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x44u))); /* mov eax, dword ptr [esi + 0x44] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00787950; /* je 0x787950 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0078794fu); f_0078864e(c); /* call 0x78864e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00787950:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    (void)sub32(c, c->eax, (uint32_t)0x7928a0u); /* cmp eax, 0x100128a0 */
    if (c->zf) goto L_00787961; /* je 0x787961 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00787960u); f_0078864e(c); /* call 0x78864e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00787961:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00787967u); f_0078864e(c); /* call 0x78864e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00787968:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x7925d0u)); PUSH32(c, v_); } /* push dword ptr [0x100125d0] */
    { uint32_t t_ = R32((uint32_t)(0x790010u)); PUSH32(c, 0x00787976u); call_indirect(c, t_); } /* call dword ptr [0x10010010] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00787977:;
    c->esp += 4; return; /* ret  */
}

void f_00787978(CPU *c) { /* FUN_10007978 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x790418u; PUSH32(c, v_); } /* push 0x10010418 */
    { uint32_t v_ = 0x789c84u; PUSH32(c, v_); } /* push 0x10009c84 */
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
    PUSH32(c, 0x007879a7u); f_00787871(c); /* call 0x787871 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x60u)), c->esi); /* cmp dword ptr [eax + 0x60], esi */
    if (c->zf) goto L_007879cb; /* je 0x7879cb */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    PUSH32(c, 0x007879b8u); f_00787871(c); /* call 0x787871 */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x60u)); PUSH32(c, 0x007879bbu); call_indirect(c, t_); } /* call dword ptr [eax + 0x60] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 4], esi */
    goto L_007879cb; /* jmp 0x7879cb */
L_007879cb:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x007879d4u); f_007879d4(c); /* call 0x7879d4 */
    { f_0078ac72(c); return; } /* jmp 0x78ac72 */
}

void f_007879c0(CPU *c) { /* PTR_007879c0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_007879c4(CPU *c) { /* PTR_007879c4 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x007879d4u); f_007879d4(c); /* call 0x7879d4 */
    { f_0078ac72(c); return; } /* jmp 0x78ac72 */
}

void f_007879d4(CPU *c) { /* PTR_007879d4 */
    PREEMPT_POLL(c);
    { f_0078ac72(c); return; } /* jmp 0x78ac72 */
}

void f_007879d9(CPU *c) { /* FUN_100079d9 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x790430u; PUSH32(c, v_); } /* push 0x10010430 */
    { uint32_t v_ = 0x789c84u; PUSH32(c, v_); } /* push 0x10009c84 */
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
    c->eax = (uint32_t)(R32((uint32_t)(0x7925d4u))); /* mov eax, dword ptr [0x100125d4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00787a21; /* je 0x787a21 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00787a14u); call_indirect(c, t_); } /* call eax */
    goto L_00787a1d; /* jmp 0x787a1d */
L_00787a1d:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
L_00787a21:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00787a2au); f_00787a2a(c); /* call 0x787a2a */
    { f_00787978(c); return; } /* jmp 0x787978 */
}

void f_00787a16(CPU *c) { /* PTR_00787a16 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_00787a1a(CPU *c) { /* PTR_00787a1a */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00787a2au); f_00787a2a(c); /* call 0x787a2a */
    { f_00787978(c); return; } /* jmp 0x787978 */
}

void f_00787a2a(CPU *c) { /* PTR_00787a2a */
    PREEMPT_POLL(c);
    { f_00787978(c); return; } /* jmp 0x787978 */
}

void f_00787a2f(CPU *c) { /* FUN_10007a2f */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x7925a0u))); /* mov eax, dword ptr [0x100125a0] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00787a3a; /* je 0x787a3a */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00787a3au); call_indirect(c, t_); } /* call eax */
L_00787a3a:;
    { uint32_t v_ = 0x792020u; PUSH32(c, v_); } /* push 0x10012020 */
    { uint32_t v_ = 0x79200cu; PUSH32(c, v_); } /* push 0x1001200c */
    PUSH32(c, 0x00787a49u); f_00787b33(c); /* call 0x787b33 */
    { uint32_t v_ = 0x792008u; PUSH32(c, v_); } /* push 0x10012008 */
    { uint32_t v_ = 0x792000u; PUSH32(c, v_); } /* push 0x10012000 */
    PUSH32(c, 0x00787a58u); f_00787b33(c); /* call 0x787b33 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_00787a5c(CPU *c) { /* __exit */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    PUSH32(c, 0x00787a69u); f_00787a7c(c); /* call 0x787a7c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00787a6d(CPU *c) { /* FUN_10007a6d */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    PUSH32(c, 0x00787a78u); f_00787a7c(c); /* call 0x787a7c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00787a7c(CPU *c) { /* FUN_10007a7c */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00787a82u); f_00787b21(c); /* call 0x787b21 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    (void)sub32(c, R32((uint32_t)(0x795700u)), c->edi); /* cmp dword ptr [0x10015700], edi */
    if (!c->zf) goto L_00787a9e; /* jne 0x787a9e */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    { uint32_t t_ = R32((uint32_t)(0x790030u)); PUSH32(c, 0x00787a97u); call_indirect(c, t_); } /* call dword ptr [0x10010030] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x79002cu)); PUSH32(c, 0x00787a9eu); call_indirect(c, t_); } /* call dword ptr [0x1001002c] */
L_00787a9e:;
    (void)sub32(c, R32((uint32_t)(c->esp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [esp + 0xc], 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ebx, dword ptr [esp + 0x14] */
    W32((uint32_t)(0x7956fcu), (uint32_t)(c->edi)); /* mov dword ptr [0x100156fc], edi */
    W8((uint32_t)(0x7956f8u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [0x100156f8], bl */
    if (!c->zf) goto L_00787af2; /* jne 0x787af2 */
    c->eax = (uint32_t)(R32((uint32_t)(0x796db0u))); /* mov eax, dword ptr [0x10016db0] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00787ae1; /* je 0x787ae1 */
    c->ecx = (uint32_t)(R32((uint32_t)(0x796dacu))); /* mov ecx, dword ptr [0x10016dac] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)((uint32_t)(c->ecx + 0xfffffffcu)); /* lea esi, [ecx - 4] */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if (c->cf) goto L_00787ae0; /* jb 0x787ae0 */
L_00787acd:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00787ad5; /* je 0x787ad5 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00787ad5u); call_indirect(c, t_); } /* call eax */
L_00787ad5:;
    c->esi = (uint32_t)(sub32(c, c->esi, (uint32_t)0x4u)); /* sub esi, 4 */
    (void)sub32(c, c->esi, R32((uint32_t)(0x796db0u))); /* cmp esi, dword ptr [0x10016db0] */
    if (!c->cf) goto L_00787acd; /* jae 0x787acd */
L_00787ae0:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00787ae1:;
    { uint32_t v_ = 0x79202cu; PUSH32(c, v_); } /* push 0x1001202c */
    { uint32_t v_ = 0x792024u; PUSH32(c, v_); } /* push 0x10012024 */
    PUSH32(c, 0x00787af0u); f_00787b33(c); /* call 0x787b33 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00787af2:;
    { uint32_t v_ = 0x792038u; PUSH32(c, v_); } /* push 0x10012038 */
    { uint32_t v_ = 0x792030u; PUSH32(c, v_); } /* push 0x10012030 */
    PUSH32(c, 0x00787b01u); f_00787b33(c); /* call 0x787b33 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    if (c->zf) goto L_00787b0f; /* je 0x787b0f */
    PUSH32(c, 0x00787b0du); f_00787b2a(c); /* call 0x787b2a */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_00787b0f:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    W32((uint32_t)(0x795700u), (uint32_t)(c->edi)); /* mov dword ptr [0x10015700], edi */
    { uint32_t t_ = R32((uint32_t)(0x790028u)); PUSH32(c, 0x00787b1fu); call_indirect(c, t_); } /* call dword ptr [0x10010028] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00787b1f(CPU *c) { /* PTR_00787b1f */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00787b21(CPU *c) { /* FUN_10007b21 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xdu; PUSH32(c, v_); } /* push 0xd */
    PUSH32(c, 0x00787b28u); f_007885d8(c); /* call 0x7885d8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00787b2a(CPU *c) { /* FUN_10007b2a */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xdu; PUSH32(c, v_); } /* push 0xd */
    PUSH32(c, 0x00787b31u); f_00788639(c); /* call 0x788639 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00787b33(CPU *c) { /* FUN_10007b33 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
L_00787b38:;
    (void)sub32(c, c->esi, R32((uint32_t)(c->esp + 0xcu))); /* cmp esi, dword ptr [esp + 0xc] */
    if (!c->cf) goto L_00787b4b; /* jae 0x787b4b */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00787b46; /* je 0x787b46 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00787b46u); call_indirect(c, t_); } /* call eax */
L_00787b46:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    goto L_00787b38; /* jmp 0x787b38 */
L_00787b4b:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00787b4d(CPU *c) { /* FUN_10007b4d */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x790448u; PUSH32(c, v_); } /* push 0x10010448 */
    { uint32_t v_ = 0x789c84u; PUSH32(c, v_); } /* push 0x10009c84 */
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
    if (!c->zf) goto L_00787b87; /* jne 0x787b87 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x00787b81u); f_00787f6a(c); /* call 0x787f6a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00787e6d; /* jmp 0x787e6d */
L_00787b87:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_00787b9a; /* jne 0x787b9a */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00787b94u); f_0078864e(c); /* call 0x78864e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00787e6b; /* jmp 0x787e6b */
L_00787b9a:;
    c->eax = (uint32_t)(R32((uint32_t)(0x796c84u))); /* mov eax, dword ptr [0x10016c84] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_00787ce1; /* jne 0x787ce1 */
L_00787ba8:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00787ca5; /* ja 0x787ca5 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00787bbbu); f_007885d8(c); /* call 0x7885d8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 4], edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00787bc5u); f_0078acd1(c); /* call 0x78acd1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x28], eax */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (c->zf) goto L_00787c75; /* je 0x787c75 */
    (void)sub32(c, c->esi, R32((uint32_t)(0x796c7cu))); /* cmp esi, dword ptr [0x10016c7c] */
    if ((!c->cf && !c->zf)) goto L_00787c25; /* ja 0x787c25 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00787be1u); f_0078b4da(c); /* call 0x78b4da */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00787bed; /* je 0x787bed */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x24], ebx */
    goto L_00787c25; /* jmp 0x787c25 */
L_00787bed:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00787bf3u); f_0078b025(c); /* call 0x78b025 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (c->zf) goto L_00787c25; /* je 0x787c25 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xfffffffcu))); /* mov eax, dword ptr [ebx - 4] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00787c08; /* jb 0x787c08 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00787c08:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00787c12u); f_0078bec0(c); /* call 0x78bec0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00787c18u); f_0078acd1(c); /* call 0x78acd1 */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x28], eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00787c22u); f_0078acfc(c); /* call 0x78acfc */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00787c25:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), c->edi); /* cmp dword ptr [ebp - 0x24], edi */
    if (!c->zf) goto L_00787c75; /* jne 0x787c75 */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_00787c34; /* jne 0x787c34 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_00787c34:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0x796c80u)); PUSH32(c, v_); } /* push dword ptr [0x10016c80] */
    { uint32_t t_ = R32((uint32_t)(0x790038u)); PUSH32(c, 0x00787c4bu); call_indirect(c, t_); } /* call dword ptr [0x10010038] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (c->zf) goto L_00787c75; /* je 0x787c75 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xfffffffcu))); /* mov eax, dword ptr [ebx - 4] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00787c5f; /* jb 0x787c5f */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00787c5f:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00787c69u); f_0078bec0(c); /* call 0x78bec0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x28] */
    PUSH32(c, 0x00787c72u); f_0078acfc(c); /* call 0x78acfc */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
L_00787c75:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00787c7eu); f_00787cd8(c); /* call 0x787cd8 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), c->edi); /* cmp dword ptr [ebp - 0x28], edi */
    if (!c->zf) goto L_00787ca5; /* jne 0x787ca5 */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_00787c8a; /* jne 0x787c8a */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00787c8a:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0x796c80u)); PUSH32(c, v_); } /* push dword ptr [0x10016c80] */
    { uint32_t t_ = R32((uint32_t)(0x790034u)); PUSH32(c, 0x00787ca2u); call_indirect(c, t_); } /* call dword ptr [0x10010034] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_00787ca5:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_00787e6d; /* jne 0x787e6d */
    (void)sub32(c, R32((uint32_t)(0x795880u)), c->edi); /* cmp dword ptr [0x10015880], edi */
    if (c->zf) goto L_00787e6d; /* je 0x787e6d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00787cc2u); f_0078be9d(c); /* call 0x78be9d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00787ba8; /* jne 0x787ba8 */
    goto L_00787e6b; /* jmp 0x787e6b */
L_00787ce1:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00787e31; /* jne 0x787e31 */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00787d01; /* ja 0x787d01 */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if ((c->cf || c->zf)) goto L_00787cfb; /* jbe 0x787cfb */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    goto L_00787cfe; /* jmp 0x787cfe */
L_00787cfb:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00787cfe:;
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_00787d01:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00787e00; /* ja 0x787e00 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00787d14u); f_007885d8(c); /* call 0x7885d8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00787d2au); f_0078ba2c(c); /* call 0x78ba2c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00787de4; /* je 0x787de4 */
    (void)sub32(c, c->esi, R32((uint32_t)(0x79494cu))); /* cmp esi, dword ptr [0x1001494c] */
    if (!c->cf) goto L_00787d9e; /* jae 0x787d9e */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 4)); /* shr ebx, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00787d54u); f_0078bdf4(c); /* call 0x78bdf4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00787d63; /* je 0x787d63 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_00787d9b; /* jmp 0x787d9b */
L_00787d63:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00787d69u); f_0078bac8(c); /* call 0x78bac8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00787d9b; /* je 0x787d9b */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00787d80; /* jb 0x787d80 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00787d80:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00787d8cu); f_0078bec0(c); /* call 0x78bec0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00787d98u); f_0078ba83(c); /* call 0x78ba83 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00787d9b:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00787d9e:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00787df7; /* jne 0x787df7 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x796c80u)); PUSH32(c, v_); } /* push dword ptr [0x10016c80] */
    { uint32_t t_ = R32((uint32_t)(0x790038u)); PUSH32(c, 0x00787db3u); call_indirect(c, t_); } /* call dword ptr [0x10010038] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00787df7; /* je 0x787df7 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00787dc9; /* jb 0x787dc9 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00787dc9:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00787dd3u); f_0078bec0(c); /* call 0x78bec0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00787ddfu); f_0078ba83(c); /* call 0x78ba83 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00787df7; /* jmp 0x787df7 */
L_00787de4:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x796c80u)); PUSH32(c, v_); } /* push dword ptr [0x10016c80] */
    { uint32_t t_ = R32((uint32_t)(0x790034u)); PUSH32(c, 0x00787df4u); call_indirect(c, t_); } /* call dword ptr [0x10010034] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_00787df7:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00787e00u); f_00787e26(c); /* call 0x787e26 */
L_00787e00:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_00787e6d; /* jne 0x787e6d */
    (void)sub32(c, R32((uint32_t)(0x795880u)), c->edi); /* cmp dword ptr [0x10015880], edi */
    if (c->zf) goto L_00787e6d; /* je 0x787e6d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00787e15u); f_0078be9d(c); /* call 0x78be9d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00787d01; /* jne 0x787d01 */
    goto L_00787e6b; /* jmp 0x787e6b */
L_00787e31:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00787e54; /* ja 0x787e54 */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_00787e3f; /* jne 0x787e3f */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00787e3f:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0x796c80u)); PUSH32(c, v_); } /* push dword ptr [0x10016c80] */
    { uint32_t t_ = R32((uint32_t)(0x790034u)); PUSH32(c, 0x00787e54u); call_indirect(c, t_); } /* call dword ptr [0x10010034] */
L_00787e54:;
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_00787e6d; /* jne 0x787e6d */
    (void)sub32(c, R32((uint32_t)(0x795880u)), c->edi); /* cmp dword ptr [0x10015880], edi */
    if (c->zf) goto L_00787e6d; /* je 0x787e6d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00787e66u); f_0078be9d(c); /* call 0x78be9d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00787e31; /* jne 0x787e31 */
L_00787e6b:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00787e6d:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00787cd0(CPU *c) { /* PTR_00787cd0 */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    { f_00787cd8(c); return; }
}

void f_00787cd8(CPU *c) { /* FUN_10007cd8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00787cdfu); f_00788639(c); /* call 0x788639 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00787ce1(CPU *c) { /* PTR_00787ce1 */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) { f_00787e31(c); return; } /* jne 0x787e31 */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00787d01; /* ja 0x787d01 */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if ((c->cf || c->zf)) goto L_00787cfb; /* jbe 0x787cfb */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    goto L_00787cfe; /* jmp 0x787cfe */
L_00787cfb:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00787cfe:;
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_00787d01:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00787e00; /* ja 0x787e00 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00787d14u); f_007885d8(c); /* call 0x7885d8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00787d2au); f_0078ba2c(c); /* call 0x78ba2c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00787de4; /* je 0x787de4 */
    (void)sub32(c, c->esi, R32((uint32_t)(0x79494cu))); /* cmp esi, dword ptr [0x1001494c] */
    if (!c->cf) goto L_00787d9e; /* jae 0x787d9e */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 4)); /* shr ebx, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00787d54u); f_0078bdf4(c); /* call 0x78bdf4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00787d63; /* je 0x787d63 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_00787d9b; /* jmp 0x787d9b */
L_00787d63:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00787d69u); f_0078bac8(c); /* call 0x78bac8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00787d9b; /* je 0x787d9b */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00787d80; /* jb 0x787d80 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00787d80:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00787d8cu); f_0078bec0(c); /* call 0x78bec0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00787d98u); f_0078ba83(c); /* call 0x78ba83 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00787d9b:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00787d9e:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00787df7; /* jne 0x787df7 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x796c80u)); PUSH32(c, v_); } /* push dword ptr [0x10016c80] */
    { uint32_t t_ = R32((uint32_t)(0x790038u)); PUSH32(c, 0x00787db3u); call_indirect(c, t_); } /* call dword ptr [0x10010038] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00787df7; /* je 0x787df7 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00787dc9; /* jb 0x787dc9 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00787dc9:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00787dd3u); f_0078bec0(c); /* call 0x78bec0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00787ddfu); f_0078ba83(c); /* call 0x78ba83 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00787df7; /* jmp 0x787df7 */
L_00787de4:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x796c80u)); PUSH32(c, v_); } /* push dword ptr [0x10016c80] */
    { uint32_t t_ = R32((uint32_t)(0x790034u)); PUSH32(c, 0x00787df4u); call_indirect(c, t_); } /* call dword ptr [0x10010034] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_00787df7:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00787e00u); f_00787e26(c); /* call 0x787e26 */
L_00787e00:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00787e6d(c); return; } /* jne 0x787e6d */
    (void)sub32(c, R32((uint32_t)(0x795880u)), c->edi); /* cmp dword ptr [0x10015880], edi */
    if (c->zf) { f_00787e6d(c); return; } /* je 0x787e6d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00787e15u); f_0078be9d(c); /* call 0x78be9d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00787d01; /* jne 0x787d01 */
    { f_00787e6b(c); return; } /* jmp 0x787e6b */
}

void f_00787cfb(CPU *c) { /* PTR_00787cfb */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_00787d01:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00787e00; /* ja 0x787e00 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00787d14u); f_007885d8(c); /* call 0x7885d8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00787d2au); f_0078ba2c(c); /* call 0x78ba2c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00787de4; /* je 0x787de4 */
    (void)sub32(c, c->esi, R32((uint32_t)(0x79494cu))); /* cmp esi, dword ptr [0x1001494c] */
    if (!c->cf) goto L_00787d9e; /* jae 0x787d9e */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 4)); /* shr ebx, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00787d54u); f_0078bdf4(c); /* call 0x78bdf4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00787d63; /* je 0x787d63 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_00787d9b; /* jmp 0x787d9b */
L_00787d63:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00787d69u); f_0078bac8(c); /* call 0x78bac8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00787d9b; /* je 0x787d9b */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00787d80; /* jb 0x787d80 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00787d80:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00787d8cu); f_0078bec0(c); /* call 0x78bec0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00787d98u); f_0078ba83(c); /* call 0x78ba83 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00787d9b:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00787d9e:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00787df7; /* jne 0x787df7 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x796c80u)); PUSH32(c, v_); } /* push dword ptr [0x10016c80] */
    { uint32_t t_ = R32((uint32_t)(0x790038u)); PUSH32(c, 0x00787db3u); call_indirect(c, t_); } /* call dword ptr [0x10010038] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00787df7; /* je 0x787df7 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00787dc9; /* jb 0x787dc9 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00787dc9:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00787dd3u); f_0078bec0(c); /* call 0x78bec0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00787ddfu); f_0078ba83(c); /* call 0x78ba83 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00787df7; /* jmp 0x787df7 */
L_00787de4:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x796c80u)); PUSH32(c, v_); } /* push dword ptr [0x10016c80] */
    { uint32_t t_ = R32((uint32_t)(0x790034u)); PUSH32(c, 0x00787df4u); call_indirect(c, t_); } /* call dword ptr [0x10010034] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_00787df7:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00787e00u); f_00787e26(c); /* call 0x787e26 */
L_00787e00:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00787e6d(c); return; } /* jne 0x787e6d */
    (void)sub32(c, R32((uint32_t)(0x795880u)), c->edi); /* cmp dword ptr [0x10015880], edi */
    if (c->zf) { f_00787e6d(c); return; } /* je 0x787e6d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00787e15u); f_0078be9d(c); /* call 0x78be9d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00787d01; /* jne 0x787d01 */
    { f_00787e6b(c); return; } /* jmp 0x787e6b */
}

void f_00787cfe(CPU *c) { /* PTR_00787cfe */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_00787d01:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00787e00; /* ja 0x787e00 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00787d14u); f_007885d8(c); /* call 0x7885d8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00787d2au); f_0078ba2c(c); /* call 0x78ba2c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00787de4; /* je 0x787de4 */
    (void)sub32(c, c->esi, R32((uint32_t)(0x79494cu))); /* cmp esi, dword ptr [0x1001494c] */
    if (!c->cf) goto L_00787d9e; /* jae 0x787d9e */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 4)); /* shr ebx, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00787d54u); f_0078bdf4(c); /* call 0x78bdf4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00787d63; /* je 0x787d63 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_00787d9b; /* jmp 0x787d9b */
L_00787d63:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00787d69u); f_0078bac8(c); /* call 0x78bac8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00787d9b; /* je 0x787d9b */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00787d80; /* jb 0x787d80 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00787d80:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00787d8cu); f_0078bec0(c); /* call 0x78bec0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00787d98u); f_0078ba83(c); /* call 0x78ba83 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00787d9b:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00787d9e:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00787df7; /* jne 0x787df7 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x796c80u)); PUSH32(c, v_); } /* push dword ptr [0x10016c80] */
    { uint32_t t_ = R32((uint32_t)(0x790038u)); PUSH32(c, 0x00787db3u); call_indirect(c, t_); } /* call dword ptr [0x10010038] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00787df7; /* je 0x787df7 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00787dc9; /* jb 0x787dc9 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00787dc9:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00787dd3u); f_0078bec0(c); /* call 0x78bec0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00787ddfu); f_0078ba83(c); /* call 0x78ba83 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00787df7; /* jmp 0x787df7 */
L_00787de4:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x796c80u)); PUSH32(c, v_); } /* push dword ptr [0x10016c80] */
    { uint32_t t_ = R32((uint32_t)(0x790034u)); PUSH32(c, 0x00787df4u); call_indirect(c, t_); } /* call dword ptr [0x10010034] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_00787df7:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00787e00u); f_00787e26(c); /* call 0x787e26 */
L_00787e00:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00787e6d(c); return; } /* jne 0x787e6d */
    (void)sub32(c, R32((uint32_t)(0x795880u)), c->edi); /* cmp dword ptr [0x10015880], edi */
    if (c->zf) { f_00787e6d(c); return; } /* je 0x787e6d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00787e15u); f_0078be9d(c); /* call 0x78be9d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00787d01; /* jne 0x787d01 */
    { f_00787e6b(c); return; } /* jmp 0x787e6b */
}

void f_00787d01(CPU *c) { /* PTR_00787d01 */
    PREEMPT_POLL(c);
L_00787d01:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00787e00; /* ja 0x787e00 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00787d14u); f_007885d8(c); /* call 0x7885d8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00787d2au); f_0078ba2c(c); /* call 0x78ba2c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00787de4; /* je 0x787de4 */
    (void)sub32(c, c->esi, R32((uint32_t)(0x79494cu))); /* cmp esi, dword ptr [0x1001494c] */
    if (!c->cf) goto L_00787d9e; /* jae 0x787d9e */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 4)); /* shr ebx, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00787d54u); f_0078bdf4(c); /* call 0x78bdf4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00787d63; /* je 0x787d63 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_00787d9b; /* jmp 0x787d9b */
L_00787d63:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00787d69u); f_0078bac8(c); /* call 0x78bac8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00787d9b; /* je 0x787d9b */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00787d80; /* jb 0x787d80 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00787d80:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00787d8cu); f_0078bec0(c); /* call 0x78bec0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00787d98u); f_0078ba83(c); /* call 0x78ba83 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00787d9b:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00787d9e:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00787df7; /* jne 0x787df7 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x796c80u)); PUSH32(c, v_); } /* push dword ptr [0x10016c80] */
    { uint32_t t_ = R32((uint32_t)(0x790038u)); PUSH32(c, 0x00787db3u); call_indirect(c, t_); } /* call dword ptr [0x10010038] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00787df7; /* je 0x787df7 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00787dc9; /* jb 0x787dc9 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00787dc9:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00787dd3u); f_0078bec0(c); /* call 0x78bec0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00787ddfu); f_0078ba83(c); /* call 0x78ba83 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00787df7; /* jmp 0x787df7 */
L_00787de4:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x796c80u)); PUSH32(c, v_); } /* push dword ptr [0x10016c80] */
    { uint32_t t_ = R32((uint32_t)(0x790034u)); PUSH32(c, 0x00787df4u); call_indirect(c, t_); } /* call dword ptr [0x10010034] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_00787df7:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00787e00u); f_00787e26(c); /* call 0x787e26 */
L_00787e00:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00787e6d(c); return; } /* jne 0x787e6d */
    (void)sub32(c, R32((uint32_t)(0x795880u)), c->edi); /* cmp dword ptr [0x10015880], edi */
    if (c->zf) { f_00787e6d(c); return; } /* je 0x787e6d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00787e15u); f_0078be9d(c); /* call 0x78be9d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00787d01; /* jne 0x787d01 */
    { f_00787e6b(c); return; } /* jmp 0x787e6b */
}

void f_00787d63(CPU *c) { /* PTR_00787d63 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00787d69u); f_0078bac8(c); /* call 0x78bac8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00787d9b; /* je 0x787d9b */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00787d80; /* jb 0x787d80 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00787d80:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00787d8cu); f_0078bec0(c); /* call 0x78bec0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00787d98u); f_0078ba83(c); /* call 0x78ba83 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00787d9b:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00787df7; /* jne 0x787df7 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x796c80u)); PUSH32(c, v_); } /* push dword ptr [0x10016c80] */
    { uint32_t t_ = R32((uint32_t)(0x790038u)); PUSH32(c, 0x00787db3u); call_indirect(c, t_); } /* call dword ptr [0x10010038] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00787df7; /* je 0x787df7 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00787dc9; /* jb 0x787dc9 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00787dc9:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00787dd3u); f_0078bec0(c); /* call 0x78bec0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00787ddfu); f_0078ba83(c); /* call 0x78ba83 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00787df7; /* jmp 0x787df7 */
L_00787df7:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00787e00u); f_00787e26(c); /* call 0x787e26 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00787e6d(c); return; } /* jne 0x787e6d */
    (void)sub32(c, R32((uint32_t)(0x795880u)), c->edi); /* cmp dword ptr [0x10015880], edi */
    if (c->zf) { f_00787e6d(c); return; } /* je 0x787e6d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00787e15u); f_0078be9d(c); /* call 0x78be9d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00787d01(c); return; } /* jne 0x787d01 */
    { f_00787e6b(c); return; } /* jmp 0x787e6b */
}

void f_00787d80(CPU *c) { /* PTR_00787d80 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00787d8cu); f_0078bec0(c); /* call 0x78bec0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00787d98u); f_0078ba83(c); /* call 0x78ba83 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00787df7; /* jne 0x787df7 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x796c80u)); PUSH32(c, v_); } /* push dword ptr [0x10016c80] */
    { uint32_t t_ = R32((uint32_t)(0x790038u)); PUSH32(c, 0x00787db3u); call_indirect(c, t_); } /* call dword ptr [0x10010038] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00787df7; /* je 0x787df7 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00787dc9; /* jb 0x787dc9 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00787dc9:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00787dd3u); f_0078bec0(c); /* call 0x78bec0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00787ddfu); f_0078ba83(c); /* call 0x78ba83 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00787df7; /* jmp 0x787df7 */
L_00787df7:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00787e00u); f_00787e26(c); /* call 0x787e26 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00787e6d(c); return; } /* jne 0x787e6d */
    (void)sub32(c, R32((uint32_t)(0x795880u)), c->edi); /* cmp dword ptr [0x10015880], edi */
    if (c->zf) { f_00787e6d(c); return; } /* je 0x787e6d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00787e15u); f_0078be9d(c); /* call 0x78be9d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00787d01(c); return; } /* jne 0x787d01 */
    { f_00787e6b(c); return; } /* jmp 0x787e6b */
}

void f_00787d9b(CPU *c) { /* PTR_00787d9b */
    PREEMPT_POLL(c);
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00787df7; /* jne 0x787df7 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x796c80u)); PUSH32(c, v_); } /* push dword ptr [0x10016c80] */
    { uint32_t t_ = R32((uint32_t)(0x790038u)); PUSH32(c, 0x00787db3u); call_indirect(c, t_); } /* call dword ptr [0x10010038] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00787df7; /* je 0x787df7 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00787dc9; /* jb 0x787dc9 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00787dc9:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00787dd3u); f_0078bec0(c); /* call 0x78bec0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00787ddfu); f_0078ba83(c); /* call 0x78ba83 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00787df7; /* jmp 0x787df7 */
L_00787df7:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00787e00u); f_00787e26(c); /* call 0x787e26 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00787e6d(c); return; } /* jne 0x787e6d */
    (void)sub32(c, R32((uint32_t)(0x795880u)), c->edi); /* cmp dword ptr [0x10015880], edi */
    if (c->zf) { f_00787e6d(c); return; } /* je 0x787e6d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00787e15u); f_0078be9d(c); /* call 0x78be9d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00787d01(c); return; } /* jne 0x787d01 */
    { f_00787e6b(c); return; } /* jmp 0x787e6b */
}

void f_00787d9e(CPU *c) { /* PTR_00787d9e */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00787df7; /* jne 0x787df7 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x796c80u)); PUSH32(c, v_); } /* push dword ptr [0x10016c80] */
    { uint32_t t_ = R32((uint32_t)(0x790038u)); PUSH32(c, 0x00787db3u); call_indirect(c, t_); } /* call dword ptr [0x10010038] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00787df7; /* je 0x787df7 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00787dc9; /* jb 0x787dc9 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00787dc9:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00787dd3u); f_0078bec0(c); /* call 0x78bec0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00787ddfu); f_0078ba83(c); /* call 0x78ba83 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00787df7; /* jmp 0x787df7 */
L_00787df7:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00787e00u); f_00787e26(c); /* call 0x787e26 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00787e6d(c); return; } /* jne 0x787e6d */
    (void)sub32(c, R32((uint32_t)(0x795880u)), c->edi); /* cmp dword ptr [0x10015880], edi */
    if (c->zf) { f_00787e6d(c); return; } /* je 0x787e6d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00787e15u); f_0078be9d(c); /* call 0x78be9d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00787d01(c); return; } /* jne 0x787d01 */
    { f_00787e6b(c); return; } /* jmp 0x787e6b */
}

void f_00787dc9(CPU *c) { /* PTR_00787dc9 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00787dd3u); f_0078bec0(c); /* call 0x78bec0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00787ddfu); f_0078ba83(c); /* call 0x78ba83 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00787df7; /* jmp 0x787df7 */
L_00787df7:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00787e00u); f_00787e26(c); /* call 0x787e26 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00787e6d(c); return; } /* jne 0x787e6d */
    (void)sub32(c, R32((uint32_t)(0x795880u)), c->edi); /* cmp dword ptr [0x10015880], edi */
    if (c->zf) { f_00787e6d(c); return; } /* je 0x787e6d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00787e15u); f_0078be9d(c); /* call 0x78be9d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00787d01(c); return; } /* jne 0x787d01 */
    { f_00787e6b(c); return; } /* jmp 0x787e6b */
}

void f_00787de4(CPU *c) { /* PTR_00787de4 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x796c80u)); PUSH32(c, v_); } /* push dword ptr [0x10016c80] */
    { uint32_t t_ = R32((uint32_t)(0x790034u)); PUSH32(c, 0x00787df4u); call_indirect(c, t_); } /* call dword ptr [0x10010034] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00787e00u); f_00787e26(c); /* call 0x787e26 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00787e6d(c); return; } /* jne 0x787e6d */
    (void)sub32(c, R32((uint32_t)(0x795880u)), c->edi); /* cmp dword ptr [0x10015880], edi */
    if (c->zf) { f_00787e6d(c); return; } /* je 0x787e6d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00787e15u); f_0078be9d(c); /* call 0x78be9d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00787d01(c); return; } /* jne 0x787d01 */
    { f_00787e6b(c); return; } /* jmp 0x787e6b */
}

void f_00787df7(CPU *c) { /* PTR_00787df7 */
    PREEMPT_POLL(c);
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00787e00u); f_00787e26(c); /* call 0x787e26 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00787e6d(c); return; } /* jne 0x787e6d */
    (void)sub32(c, R32((uint32_t)(0x795880u)), c->edi); /* cmp dword ptr [0x10015880], edi */
    if (c->zf) { f_00787e6d(c); return; } /* je 0x787e6d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00787e15u); f_0078be9d(c); /* call 0x78be9d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00787d01(c); return; } /* jne 0x787d01 */
    { f_00787e6b(c); return; } /* jmp 0x787e6b */
}

void f_00787e00(CPU *c) { /* PTR_00787e00 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00787e6d(c); return; } /* jne 0x787e6d */
    (void)sub32(c, R32((uint32_t)(0x795880u)), c->edi); /* cmp dword ptr [0x10015880], edi */
    if (c->zf) { f_00787e6d(c); return; } /* je 0x787e6d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00787e15u); f_0078be9d(c); /* call 0x78be9d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00787d01(c); return; } /* jne 0x787d01 */
    { f_00787e6b(c); return; } /* jmp 0x787e6b */
}

void f_00787e20(CPU *c) { /* PTR_00787e20 */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    { f_00787e26(c); return; }
}

void f_00787e26(CPU *c) { /* FUN_10007e26 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00787e2du); f_00788639(c); /* call 0x788639 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    c->esp += 4; return; /* ret  */
}

void f_00787e31(CPU *c) { /* PTR_00787e31 */
    PREEMPT_POLL(c);
L_00787e31:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00787e54; /* ja 0x787e54 */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_00787e3f; /* jne 0x787e3f */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00787e3f:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0x796c80u)); PUSH32(c, v_); } /* push dword ptr [0x10016c80] */
    { uint32_t t_ = R32((uint32_t)(0x790034u)); PUSH32(c, 0x00787e54u); call_indirect(c, t_); } /* call dword ptr [0x10010034] */
L_00787e54:;
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_00787e6d; /* jne 0x787e6d */
    (void)sub32(c, R32((uint32_t)(0x795880u)), c->edi); /* cmp dword ptr [0x10015880], edi */
    if (c->zf) goto L_00787e6d; /* je 0x787e6d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00787e66u); f_0078be9d(c); /* call 0x78be9d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00787e31; /* jne 0x787e31 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00787e6d:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00787e3f(CPU *c) { /* PTR_00787e3f */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0x796c80u)); PUSH32(c, v_); } /* push dword ptr [0x10016c80] */
    { uint32_t t_ = R32((uint32_t)(0x790034u)); PUSH32(c, 0x00787e54u); call_indirect(c, t_); } /* call dword ptr [0x10010034] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_00787e6d; /* jne 0x787e6d */
    (void)sub32(c, R32((uint32_t)(0x795880u)), c->edi); /* cmp dword ptr [0x10015880], edi */
    if (c->zf) goto L_00787e6d; /* je 0x787e6d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00787e66u); f_0078be9d(c); /* call 0x78be9d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00787e31(c); return; } /* jne 0x787e31 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00787e6d:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00787e54(CPU *c) { /* PTR_00787e54 */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_00787e6d; /* jne 0x787e6d */
    (void)sub32(c, R32((uint32_t)(0x795880u)), c->edi); /* cmp dword ptr [0x10015880], edi */
    if (c->zf) goto L_00787e6d; /* je 0x787e6d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00787e66u); f_0078be9d(c); /* call 0x78be9d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00787e31(c); return; } /* jne 0x787e31 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00787e6d:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00787e6b(CPU *c) { /* PTR_00787e6b */
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

void f_00787e6d(CPU *c) { /* PTR_00787e6d */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00787e7c(CPU *c) { /* FUN_10007e7c */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x790460u; PUSH32(c, v_); } /* push 0x10010460 */
    { uint32_t v_ = 0x789c84u; PUSH32(c, v_); } /* push 0x10009c84 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x1cu)); /* sub esp, 0x1c */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(0x796c84u))); /* mov eax, dword ptr [0x10016c84] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_00787eef; /* jne 0x787eef */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00787eb0u); f_007885d8(c); /* call 0x7885d8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00787ebeu); f_0078acd1(c); /* call 0x78acd1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00787ed1; /* je 0x787ed1 */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0xfffffffcu))); /* mov esi, dword ptr [esi - 4] */
    c->esi = (uint32_t)(sub32(c, c->esi, (uint32_t)0x9u)); /* sub esi, 9 */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x20], esi */
    goto L_00787ed4; /* jmp 0x787ed4 */
L_00787ed1:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
L_00787ed4:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00787eddu); f_00787ee6(c); /* call 0x787ee6 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x1c], 0 */
    goto L_00787f38; /* jmp 0x787f38 */
L_00787eef:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00787f3a; /* jne 0x787f3a */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00787efbu); f_007885d8(c); /* call 0x7885d8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffdcu)); /* lea eax, [ebp - 0x24] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00787f13u); f_0078ba2c(c); /* call 0x78ba2c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x28], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00787f28; /* je 0x787f28 */
    c->esi = (uint32_t)((uint32_t)R8((uint32_t)(c->eax))); /* movzx esi, byte ptr [eax] */
    c->esi = (uint32_t)(shl32(c, c->esi, 4)); /* shl esi, 4 */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x20], esi */
    goto L_00787f2b; /* jmp 0x787f2b */
L_00787f28:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
L_00787f2b:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00787f34u); f_00787f61(c); /* call 0x787f61 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x28], 0 */
L_00787f38:;
    if (!c->zf) goto L_00787f4d; /* jne 0x787f4d */
L_00787f3a:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x796c80u)); PUSH32(c, v_); } /* push dword ptr [0x10016c80] */
    { uint32_t t_ = R32((uint32_t)(0x79003cu)); PUSH32(c, 0x00787f4bu); call_indirect(c, t_); } /* call dword ptr [0x1001003c] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_00787f4d:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00787ee3(CPU *c) { /* PTR_00787ee3 */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
    { f_00787ee6(c); return; }
}

void f_00787ee6(CPU *c) { /* FUN_10007ee6 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00787eedu); f_00788639(c); /* call 0x788639 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00787eef(CPU *c) { /* PTR_00787eef */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00787f3a; /* jne 0x787f3a */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00787efbu); f_007885d8(c); /* call 0x7885d8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffdcu)); /* lea eax, [ebp - 0x24] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00787f13u); f_0078ba2c(c); /* call 0x78ba2c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x28], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00787f28; /* je 0x787f28 */
    c->esi = (uint32_t)((uint32_t)R8((uint32_t)(c->eax))); /* movzx esi, byte ptr [eax] */
    c->esi = (uint32_t)(shl32(c, c->esi, 4)); /* shl esi, 4 */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x20], esi */
    goto L_00787f2b; /* jmp 0x787f2b */
L_00787f28:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
L_00787f2b:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00787f34u); f_00787f61(c); /* call 0x787f61 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x28], 0 */
    if (!c->zf) goto L_00787f4d; /* jne 0x787f4d */
L_00787f3a:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x796c80u)); PUSH32(c, v_); } /* push dword ptr [0x10016c80] */
    { uint32_t t_ = R32((uint32_t)(0x79003cu)); PUSH32(c, 0x00787f4bu); call_indirect(c, t_); } /* call dword ptr [0x1001003c] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_00787f4d:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00787f28(CPU *c) { /* PTR_00787f28 */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00787f34u); f_00787f61(c); /* call 0x787f61 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x28], 0 */
    if (!c->zf) goto L_00787f4d; /* jne 0x787f4d */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x796c80u)); PUSH32(c, v_); } /* push dword ptr [0x10016c80] */
    { uint32_t t_ = R32((uint32_t)(0x79003cu)); PUSH32(c, 0x00787f4bu); call_indirect(c, t_); } /* call dword ptr [0x1001003c] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_00787f4d:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00787f2b(CPU *c) { /* PTR_00787f2b */
    PREEMPT_POLL(c);
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00787f34u); f_00787f61(c); /* call 0x787f61 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x28], 0 */
    if (!c->zf) goto L_00787f4d; /* jne 0x787f4d */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x796c80u)); PUSH32(c, v_); } /* push dword ptr [0x10016c80] */
    { uint32_t t_ = R32((uint32_t)(0x79003cu)); PUSH32(c, 0x00787f4bu); call_indirect(c, t_); } /* call dword ptr [0x1001003c] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_00787f4d:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00787f38(CPU *c) { /* PTR_00787f38 */
    PREEMPT_POLL(c);
    if (!c->zf) goto L_00787f4d; /* jne 0x787f4d */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x796c80u)); PUSH32(c, v_); } /* push dword ptr [0x10016c80] */
    { uint32_t t_ = R32((uint32_t)(0x79003cu)); PUSH32(c, 0x00787f4bu); call_indirect(c, t_); } /* call dword ptr [0x1001003c] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_00787f4d:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00787f3a(CPU *c) { /* PTR_00787f3a */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x796c80u)); PUSH32(c, v_); } /* push dword ptr [0x10016c80] */
    { uint32_t t_ = R32((uint32_t)(0x79003cu)); PUSH32(c, 0x00787f4bu); call_indirect(c, t_); } /* call dword ptr [0x1001003c] */
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

void f_00787f4d(CPU *c) { /* PTR_00787f4d */
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

void f_00787f5e(CPU *c) { /* PTR_00787f5e */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
    { f_00787f61(c); return; }
}

void f_00787f61(CPU *c) { /* FUN_10007f61 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00787f68u); f_00788639(c); /* call 0x788639 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00787f6a(CPU *c) { /* _malloc */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(0x795880u)); PUSH32(c, v_); } /* push dword ptr [0x10015880] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    PUSH32(c, 0x00787f79u); f_00787f7c(c); /* call 0x787f7c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00787f7c(CPU *c) { /* __nh_malloc */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->esp + 0x4u)), (uint32_t)0xffffffe0u); /* cmp dword ptr [esp + 4], -0x20 */
    if ((!c->cf && !c->zf)) goto L_00787fa5; /* ja 0x787fa5 */
L_00787f83:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    PUSH32(c, 0x00787f8cu); f_00787fa8(c); /* call 0x787fa8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00787fa7; /* jne 0x787fa7 */
    (void)sub32(c, R32((uint32_t)(c->esp + 0x8u)), c->eax); /* cmp dword ptr [esp + 8], eax */
    if (c->zf) goto L_00787fa7; /* je 0x787fa7 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    PUSH32(c, 0x00787fa0u); f_0078be9d(c); /* call 0x78be9d */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00787f83; /* jne 0x787f83 */
L_00787fa5:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00787fa7:;
    c->esp += 4; return; /* ret  */
}

void f_00787fa8(CPU *c) { /* FUN_10007fa8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x790478u; PUSH32(c, v_); } /* push 0x10010478 */
    { uint32_t v_ = 0x789c84u; PUSH32(c, v_); } /* push 0x10009c84 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(0x796c84u))); /* mov eax, dword ptr [0x10016c84] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_00788018; /* jne 0x788018 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    (void)sub32(c, c->esi, R32((uint32_t)(0x796c7cu))); /* cmp esi, dword ptr [0x10016c7c] */
    if ((!c->cf && !c->zf)) goto L_00788077; /* ja 0x788077 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00787febu); f_007885d8(c); /* call 0x7885d8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00787ff6u); f_0078b025(c); /* call 0x78b025 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00788003u); f_0078800f(c); /* call 0x78800f */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00788077; /* je 0x788077 */
    goto L_00788095; /* jmp 0x788095 */
L_00788018:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00788077; /* jne 0x788077 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0078802c; /* je 0x78802c */
    c->esi = (uint32_t)((uint32_t)(c->eax + 0xfu)); /* lea esi, [eax + 0xf] */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    goto L_0078802f; /* jmp 0x78802f */
L_0078802c:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_0078802f:;
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
    (void)sub32(c, c->esi, R32((uint32_t)(0x79494cu))); /* cmp esi, dword ptr [0x1001494c] */
    if ((!c->cf && !c->zf)) goto L_00788068; /* ja 0x788068 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00788041u); f_007885d8(c); /* call 0x7885d8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00788054u); f_0078bac8(c); /* call 0x78bac8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00788061u); f_0078806e(c); /* call 0x78806e */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00788095; /* jne 0x788095 */
L_00788068:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    goto L_00788087; /* jmp 0x788087 */
L_00788077:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00788081; /* jne 0x788081 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00788081:;
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xfu)); /* add eax, 0xf */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xf0u))); /* and al, 0xf0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
L_00788087:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x796c80u)); PUSH32(c, v_); } /* push dword ptr [0x10016c80] */
    { uint32_t t_ = R32((uint32_t)(0x790038u)); PUSH32(c, 0x00788095u); call_indirect(c, t_); } /* call dword ptr [0x10010038] */
L_00788095:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0078800f(CPU *c) { /* FUN_1000800f */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00788016u); f_00788639(c); /* call 0x788639 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00788018(CPU *c) { /* PTR_00788018 */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) { f_00788077(c); return; } /* jne 0x788077 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0078802c; /* je 0x78802c */
    c->esi = (uint32_t)((uint32_t)(c->eax + 0xfu)); /* lea esi, [eax + 0xf] */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    goto L_0078802f; /* jmp 0x78802f */
L_0078802c:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_0078802f:;
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
    (void)sub32(c, c->esi, R32((uint32_t)(0x79494cu))); /* cmp esi, dword ptr [0x1001494c] */
    if ((!c->cf && !c->zf)) goto L_00788068; /* ja 0x788068 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00788041u); f_007885d8(c); /* call 0x7885d8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00788054u); f_0078bac8(c); /* call 0x78bac8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00788061u); f_0078806e(c); /* call 0x78806e */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00788095(c); return; } /* jne 0x788095 */
L_00788068:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { f_00788087(c); return; } /* jmp 0x788087 */
}

void f_0078802c(CPU *c) { /* PTR_0078802c */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
    (void)sub32(c, c->esi, R32((uint32_t)(0x79494cu))); /* cmp esi, dword ptr [0x1001494c] */
    if ((!c->cf && !c->zf)) goto L_00788068; /* ja 0x788068 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00788041u); f_007885d8(c); /* call 0x7885d8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00788054u); f_0078bac8(c); /* call 0x78bac8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00788061u); f_0078806e(c); /* call 0x78806e */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00788095(c); return; } /* jne 0x788095 */
L_00788068:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { f_00788087(c); return; } /* jmp 0x788087 */
}

void f_0078802f(CPU *c) { /* PTR_0078802f */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
    (void)sub32(c, c->esi, R32((uint32_t)(0x79494cu))); /* cmp esi, dword ptr [0x1001494c] */
    if ((!c->cf && !c->zf)) goto L_00788068; /* ja 0x788068 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00788041u); f_007885d8(c); /* call 0x7885d8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00788054u); f_0078bac8(c); /* call 0x78bac8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00788061u); f_0078806e(c); /* call 0x78806e */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00788095(c); return; } /* jne 0x788095 */
L_00788068:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { f_00788087(c); return; } /* jmp 0x788087 */
}

void f_00788068(CPU *c) { /* PTR_00788068 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { f_00788087(c); return; } /* jmp 0x788087 */
}

void f_0078806b(CPU *c) { /* PTR_0078806b */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    { f_0078806e(c); return; }
}

void f_0078806e(CPU *c) { /* FUN_1000806e */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00788075u); f_00788639(c); /* call 0x788639 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00788077(CPU *c) { /* PTR_00788077 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00788081; /* jne 0x788081 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00788081:;
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xfu)); /* add eax, 0xf */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xf0u))); /* and al, 0xf0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x796c80u)); PUSH32(c, v_); } /* push dword ptr [0x10016c80] */
    { uint32_t t_ = R32((uint32_t)(0x790038u)); PUSH32(c, 0x00788095u); call_indirect(c, t_); } /* call dword ptr [0x10010038] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00788081(CPU *c) { /* PTR_00788081 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xfu)); /* add eax, 0xf */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xf0u))); /* and al, 0xf0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x796c80u)); PUSH32(c, v_); } /* push dword ptr [0x10016c80] */
    { uint32_t t_ = R32((uint32_t)(0x790038u)); PUSH32(c, 0x00788095u); call_indirect(c, t_); } /* call dword ptr [0x10010038] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00788087(CPU *c) { /* PTR_00788087 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x796c80u)); PUSH32(c, v_); } /* push dword ptr [0x10016c80] */
    { uint32_t t_ = R32((uint32_t)(0x790038u)); PUSH32(c, 0x00788095u); call_indirect(c, t_); } /* call dword ptr [0x10010038] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00788095(CPU *c) { /* PTR_00788095 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_007880a4(CPU *c) { /* FUN_100080a4 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x30000u; PUSH32(c, v_); } /* push 0x30000 */
    { uint32_t v_ = 0x10000u; PUSH32(c, v_); } /* push 0x10000 */
    PUSH32(c, 0x007880b3u); f_0078c22a(c); /* call 0x78c22a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_007880b6(CPU *c) { /* FUN_100080b6 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    FPUSH(c, RF64((uint32_t)(0x790498u))); /* fld qword ptr [0x10010498] */
    WF64((uint32_t)(c->ebp + 0xfffffff8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 8] */
    FPUSH(c, RF64((uint32_t)(0x790490u))); /* fld qword ptr [0x10010490] */
    WF64((uint32_t)(c->ebp + 0xfffffff0u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0x10] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff0u))); /* fld qword ptr [ebp - 0x10] */
    ST(0) = FPRES(c, FDIV(c, ST(0), RF64((uint32_t)(c->ebp + 0xfffffff8u)))); /* fdiv qword ptr [ebp - 8] */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->ebp + 0xfffffff8u))); /* fmul qword ptr [ebp - 8] */
    ST(0) = FPRES(c, RF64((uint32_t)(c->ebp + 0xfffffff0u)) - ST(0)); /* fsubr qword ptr [ebp - 0x10] */
    WF64((uint32_t)(c->ebp + 0xffffffe8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0x18] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xffffffe8u))); /* fld qword ptr [ebp - 0x18] */
    FCOM(c, ST(0), RF64((uint32_t)(0x790398u))); FPOP(c); /* fcomp qword ptr [0x10010398] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if ((c->cf || c->zf)) goto L_007880f0; /* jbe 0x7880f0 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_007880f0:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_007880f4(CPU *c) { /* FUN_100080f4 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x7904bcu; PUSH32(c, v_); } /* push 0x100104bc */
    { uint32_t t_ = R32((uint32_t)(0x790044u)); PUSH32(c, 0x007880ffu); call_indirect(c, t_); } /* call dword ptr [0x10010044] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00788118; /* je 0x788118 */
    { uint32_t v_ = 0x7904a0u; PUSH32(c, v_); } /* push 0x100104a0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x790040u)); PUSH32(c, 0x0078810fu); call_indirect(c, t_); } /* call dword ptr [0x10010040] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00788118; /* je 0x788118 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00788117u); call_indirect(c, t_); } /* call eax */
    c->esp += 4; return; /* ret  */
L_00788118:;
    { f_007880b6(c); return; } /* jmp 0x7880b6 */
}

void f_0078811d(CPU *c) { /* FUN_1000811d */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->esi))); /* movsx eax, byte ptr [esi] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0078812bu); f_0078c3d0(c); /* call 0x78c3d0 */
    (void)sub32(c, c->eax, (uint32_t)0x65u); /* cmp eax, 0x65 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_0078815d; /* je 0x78815d */
L_00788131:;
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub32(c, R32((uint32_t)(0x794950u)), (uint32_t)0x1u); /* cmp dword ptr [0x10014950], 1 */
    if ((c->zf || c->sf != c->of)) goto L_0078814a; /* jle 0x78814a */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->esi))); /* movsx eax, byte ptr [esi] */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00788146u); f_0078c35b(c); /* call 0x78c35b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00788159; /* jmp 0x788159 */
L_0078814a:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->esi))); /* movsx eax, byte ptr [esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x79495cu))); /* mov ecx, dword ptr [0x1001495c] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4u))); /* and eax, 4 */
L_00788159:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00788131; /* jne 0x788131 */
L_0078815d:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x794954u))); /* mov cl, byte ptr [0x10014954] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esi], cl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_00788168:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov cl, byte ptr [esi] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [esi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(((uint8_t)c->ecx)); /* mov al, cl */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov cl, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_00788168; /* jne 0x788168 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00788177(CPU *c) { /* PTR_00788177 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x794954u))); /* mov dl, byte ptr [0x10014954] */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_00788193; /* je 0x788193 */
L_00788187:;
    (void)sub8(c, ((uint8_t)c->ecx), ((uint8_t)c->edx)); /* cmp cl, dl */
    if (c->zf) goto L_00788193; /* je 0x788193 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1u))); /* mov cl, byte ptr [eax + 1] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_00788187; /* jne 0x788187 */
L_00788193:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_007881c4; /* je 0x7881c4 */
L_0078819a:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_007881ad; /* je 0x7881ad */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x65u); /* cmp cl, 0x65 */
    if (c->zf) goto L_007881ad; /* je 0x7881ad */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x45u); /* cmp cl, 0x45 */
    if (c->zf) goto L_007881ad; /* je 0x7881ad */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_0078819a; /* jmp 0x78819a */
L_007881ad:;
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
L_007881af:;
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x30u); /* cmp byte ptr [eax], 0x30 */
    if (c->zf) goto L_007881af; /* je 0x7881af */
    (void)sub8(c, R8((uint32_t)(c->eax)), ((uint8_t)c->edx)); /* cmp byte ptr [eax], dl */
    if (!c->zf) goto L_007881ba; /* jne 0x7881ba */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
L_007881ba:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov dl, byte ptr [ecx] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [eax], dl */
    if (!c->zf) goto L_007881ba; /* jne 0x7881ba */
L_007881c4:;
    c->esp += 4; return; /* ret  */
}

void f_007881c5(CPU *c) { /* PTR_007881c5 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    FPUSH(c, RF64((uint32_t)(c->eax))); /* fld qword ptr [eax] */
    FCOM(c, ST(0), RF64((uint32_t)(0x790390u))); FPOP(c); /* fcomp qword ptr [0x10010390] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (c->cf) goto L_007881da; /* jb 0x7881da */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
L_007881da:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_007881dd(CPU *c) { /* __fassign */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    if (c->zf) goto L_00788206; /* je 0x788206 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x007881f4u); f_0078c89c(c); /* call 0x78c89c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 4], ecx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00788206:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0078820fu); f_0078c8c9(c); /* call 0x78c8c9 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0078821b(CPU *c) { /* FUN_1000821b */
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
    PUSH32(c, 0x00788239u); f_0078c96d(c); /* call 0x78c96d */
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
    PUSH32(c, 0x00788261u); f_0078c8f6(c); /* call 0x78c8f6 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x00788273u); f_0078827c(c); /* call 0x78827c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x30u)); /* add esp, 0x30 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0078827c(CPU *c) { /* FUN_1000827c */
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
    if (c->zf) goto L_007882aa; /* je 0x7882aa */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->ebx); /* cmp dword ptr [ebp + 0xc], ebx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((!c->zf && c->sf == c->of) ? 1 : 0); /* setg al */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x2du); /* cmp dword ptr [esi], 0x2d */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete al */
    c->eax = (uint32_t)(add32(c, c->eax, c->edi)); /* add eax, edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x007882a8u); f_0078851e(c); /* call 0x78851e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_007882aa:;
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x2du); /* cmp dword ptr [esi], 0x2d */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    if (!c->zf) goto L_007882b7; /* jne 0x7882b7 */
    W8((uint32_t)(c->edi), (uint8_t)((uint8_t)0x2du)); /* mov byte ptr [edi], 0x2d */
    c->eax = (uint32_t)((uint32_t)(c->edi + 0x1u)); /* lea eax, [edi + 1] */
L_007882b7:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->ebx); /* cmp dword ptr [ebp + 0xc], ebx */
    if ((c->zf || c->sf != c->of)) goto L_007882ce; /* jle 0x7882ce */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1u))); /* mov dl, byte ptr [eax + 1] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x1u)); /* lea ecx, [eax + 1] */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [eax], dl */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x794954u))); /* mov cl, byte ptr [0x10014954] */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax], cl */
L_007882ce:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x18u)), ((uint8_t)c->ebx)); /* cmp byte ptr [ebp + 0x18], bl */
    { uint32_t v_ = 0x7904c8u; PUSH32(c, v_); } /* push 0x100104c8 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete cl */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    c->ecx = (uint32_t)(add32(c, c->ecx, R32((uint32_t)(c->ebp + 0xcu)))); /* add ecx, dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x007882e6u); f_0078ca80(c); /* call 0x78ca80 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), c->ebx); /* cmp dword ptr [ebp + 0x10], ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    if (c->zf) goto L_007882f2; /* je 0x7882f2 */
    W8((uint32_t)(c->ecx), (uint8_t)((uint8_t)0x45u)); /* mov byte ptr [ecx], 0x45 */
L_007882f2:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x30u); /* cmp byte ptr [eax], 0x30 */
    if (c->zf) goto L_00788337; /* je 0x788337 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ebx, dword ptr [esi + 4] */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->sf) goto L_00788306; /* jns 0x788306 */
    c->ebx = (uint32_t)(neg32(c, c->ebx)); /* neg ebx */
    W8((uint32_t)(c->ecx), (uint8_t)((uint8_t)0x2du)); /* mov byte ptr [ecx], 0x2d */
L_00788306:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->ebx, (uint32_t)0x64u); /* cmp ebx, 0x64 */
    if ((c->sf != c->of)) goto L_0078831d; /* jl 0x78831d */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = 0x64u; PUSH32(c, v_); } /* push 0x64 */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00788312u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [ecx], al */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00788319u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
    c->ebx = (uint32_t)(c->edx); /* mov ebx, edx */
L_0078831d:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->ebx, (uint32_t)0xau); /* cmp ebx, 0xa */
    if ((c->sf != c->of)) goto L_00788334; /* jl 0x788334 */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = 0xau; PUSH32(c, v_); } /* push 0xa */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00788329u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [ecx], al */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00788330u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
    c->ebx = (uint32_t)(c->edx); /* mov ebx, edx */
L_00788334:;
    { uint32_t a_ = (uint32_t)(c->ecx + 0x1u); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ebx)))); } /* add byte ptr [ecx + 1], bl */
L_00788337:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_0078833e(CPU *c) { /* FUN_1000833e */
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
    PUSH32(c, 0x0078835cu); f_0078c96d(c); /* call 0x78c96d */
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
    PUSH32(c, 0x0078837bu); f_0078c8f6(c); /* call 0x78c8f6 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x0078838au); f_00788393(c); /* call 0x788393 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00788393(CPU *c) { /* FUN_10008393 */
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
    if (c->zf) goto L_007883c3; /* je 0x7883c3 */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xcu))); /* cmp eax, dword ptr [ebp + 0xc] */
    if (!c->zf) goto L_007883c3; /* jne 0x7883c3 */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x2du); /* cmp dword ptr [esi], 0x2d */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete cl */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->ebx)); /* add ecx, ebx */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    W8((uint32_t)(c->eax), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [eax], 0x30 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x1u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax + 1], 0 */
L_007883c3:;
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x2du); /* cmp dword ptr [esi], 0x2d */
    c->edi = (uint32_t)(c->ebx); /* mov edi, ebx */
    if (!c->zf) goto L_007883d0; /* jne 0x7883d0 */
    W8((uint32_t)(c->ebx), (uint8_t)((uint8_t)0x2du)); /* mov byte ptr [ebx], 0x2d */
    c->edi = (uint32_t)((uint32_t)(c->ebx + 0x1u)); /* lea edi, [ebx + 1] */
L_007883d0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((!c->zf && c->sf == c->of)) goto L_007883e7; /* jg 0x7883e7 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x007883dfu); f_0078851e(c); /* call 0x78851e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W8((uint32_t)(c->edi), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [edi], 0x30 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_007883e9; /* jmp 0x7883e9 */
L_007883e7:;
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
L_007883e9:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    if ((c->zf || c->sf != c->of)) goto L_00788433; /* jle 0x788433 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x007883f7u); f_0078851e(c); /* call 0x78851e */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x794954u))); /* mov al, byte ptr [0x10014954] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov esi, dword ptr [esi + 4] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if ((c->sf == c->of)) goto L_00788433; /* jge 0x788433 */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x14u)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0x14], 0 */
    if (c->zf) goto L_00788412; /* je 0x788412 */
    c->esi = (uint32_t)(neg32(c, c->esi)); /* neg esi */
    goto L_00788419; /* jmp 0x788419 */
L_00788412:;
    c->esi = (uint32_t)(neg32(c, c->esi)); /* neg esi */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->esi); /* cmp dword ptr [ebp + 0xc], esi */
    if ((c->sf != c->of)) goto L_0078841c; /* jl 0x78841c */
L_00788419:;
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_0078841c:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00788425u); f_0078851e(c); /* call 0x78851e */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = 0x30u; PUSH32(c, v_); } /* push 0x30 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00788430u); f_0078cb70(c); /* call 0x78cb70 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
L_00788433:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_0078843a(CPU *c) { /* FUN_1000843a */
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
    PUSH32(c, 0x0078845au); f_0078c96d(c); /* call 0x78c96d */
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
    PUSH32(c, 0x0078847cu); f_0078c8f6(c); /* call 0x78c8f6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)((c->sf != c->of) ? 1 : 0); /* setl cl */
    (void)sub32(c, c->eax, (uint32_t)0xfffffffcu); /* cmp eax, -4 */
    if ((c->sf != c->of)) goto L_007884b3; /* jl 0x7884b3 */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if ((c->sf == c->of)) goto L_007884b3; /* jge 0x7884b3 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_0078849f; /* je 0x78849f */
L_00788495:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov al, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00788495; /* jne 0x788495 */
    { uint32_t a_ = (uint32_t)(c->edi + 0xfffffffeu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & ((uint8_t)c->eax))))); } /* and byte ptr [edi - 2], al */
L_0078849f:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x007884aeu); f_00788393(c); /* call 0x788393 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    goto L_007884c8; /* jmp 0x7884c8 */
L_007884b3:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x007884c5u); f_0078827c(c); /* call 0x78827c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
L_007884c8:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_007884cd(CPU *c) { /* __cfltcvt */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), (uint32_t)0x65u); /* cmp dword ptr [ebp + 0x10], 0x65 */
    if (c->zf) goto L_00788508; /* je 0x788508 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), (uint32_t)0x45u); /* cmp dword ptr [ebp + 0x10], 0x45 */
    if (c->zf) goto L_00788508; /* je 0x788508 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), (uint32_t)0x66u); /* cmp dword ptr [ebp + 0x10], 0x66 */
    if (!c->zf) goto L_007884f5; /* jne 0x7884f5 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x007884f0u); f_0078833e(c); /* call 0x78833e */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
L_007884f5:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00788506u); f_0078843a(c); /* call 0x78843a */
    goto L_00788519; /* jmp 0x788519 */
L_00788508:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00788519u); f_0078821b(c); /* call 0x78821b */
L_00788519:;
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_0078851e(CPU *c) { /* FUN_1000851e */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edi, dword ptr [esp + 0xc] */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00788541; /* je 0x788541 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov esi, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00788532u); f_00789c00(c); /* call 0x789c00 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(add32(c, c->esi, c->edi)); /* add esi, edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x0078853du); f_0078a800(c); /* call 0x78a800 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00788541:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00788543(CPU *c) { /* FUN_10008543 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(0x790048u))); /* mov esi, dword ptr [0x10010048] */
    { uint32_t v_ = R32((uint32_t)(0x792634u)); PUSH32(c, v_); } /* push dword ptr [0x10012634] */
    { uint32_t t_ = c->esi; PUSH32(c, 0x00788552u); call_indirect(c, t_); } /* call esi */
    { uint32_t v_ = R32((uint32_t)(0x792624u)); PUSH32(c, v_); } /* push dword ptr [0x10012624] */
    { uint32_t t_ = c->esi; PUSH32(c, 0x0078855au); call_indirect(c, t_); } /* call esi */
    { uint32_t v_ = R32((uint32_t)(0x792614u)); PUSH32(c, v_); } /* push dword ptr [0x10012614] */
    { uint32_t t_ = c->esi; PUSH32(c, 0x00788562u); call_indirect(c, t_); } /* call esi */
    { uint32_t v_ = R32((uint32_t)(0x7925f4u)); PUSH32(c, v_); } /* push dword ptr [0x100125f4] */
    { uint32_t t_ = c->esi; PUSH32(c, 0x0078856au); call_indirect(c, t_); } /* call esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_0078856c(CPU *c) { /* FUN_1000856c */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(0x79004cu))); /* mov edi, dword ptr [0x1001004c] */
    c->esi = (uint32_t)((uint32_t)0x7925f0u); /* mov esi, 0x100125f0 */
L_00788579:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_007885aa; /* je 0x7885aa */
    (void)sub32(c, c->esi, (uint32_t)0x792634u); /* cmp esi, 0x10012634 */
    if (c->zf) goto L_007885aa; /* je 0x7885aa */
    (void)sub32(c, c->esi, (uint32_t)0x792624u); /* cmp esi, 0x10012624 */
    if (c->zf) goto L_007885aa; /* je 0x7885aa */
    (void)sub32(c, c->esi, (uint32_t)0x792614u); /* cmp esi, 0x10012614 */
    if (c->zf) goto L_007885aa; /* je 0x7885aa */
    (void)sub32(c, c->esi, (uint32_t)0x7925f4u); /* cmp esi, 0x100125f4 */
    if (c->zf) goto L_007885aa; /* je 0x7885aa */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = c->edi; PUSH32(c, 0x007885a2u); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    PUSH32(c, 0x007885a9u); f_0078864e(c); /* call 0x78864e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_007885aa:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, c->esi, (uint32_t)0x7926b0u); /* cmp esi, 0x100126b0 */
    if ((c->sf != c->of)) goto L_00788579; /* jl 0x788579 */
    { uint32_t v_ = R32((uint32_t)(0x792614u)); PUSH32(c, v_); } /* push dword ptr [0x10012614] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x007885bdu); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = R32((uint32_t)(0x792624u)); PUSH32(c, v_); } /* push dword ptr [0x10012624] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x007885c5u); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = R32((uint32_t)(0x792634u)); PUSH32(c, v_); } /* push dword ptr [0x10012634] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x007885cdu); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = R32((uint32_t)(0x7925f4u)); PUSH32(c, v_); } /* push dword ptr [0x100125f4] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x007885d5u); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_007885d8(CPU *c) { /* FUN_100085d8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    (void)sub32(c, R32((uint32_t)(c->eax * 4 + 0x7925f0u)), (uint32_t)0x0u); /* cmp dword ptr [eax*4 + 0x100125f0], 0 */
    c->esi = (uint32_t)((uint32_t)(c->eax * 4 + 0x7925f0u)); /* lea esi, [eax*4 + 0x100125f0] */
    if (!c->zf) goto L_0078862e; /* jne 0x78862e */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    PUSH32(c, 0x007885f8u); f_00787f6a(c); /* call 0x787f6a */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (!c->zf) goto L_00788607; /* jne 0x788607 */
    { uint32_t v_ = 0x11u; PUSH32(c, v_); } /* push 0x11 */
    PUSH32(c, 0x00788606u); f_00786f56(c); /* call 0x786f56 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00788607:;
    { uint32_t v_ = 0x11u; PUSH32(c, v_); } /* push 0x11 */
    PUSH32(c, 0x0078860eu); f_007885d8(c); /* call 0x7885d8 */
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x0u); /* cmp dword ptr [esi], 0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_0078861f; /* jne 0x78861f */
    { uint32_t t_ = R32((uint32_t)(0x790048u)); PUSH32(c, 0x0078861bu); call_indirect(c, t_); } /* call dword ptr [0x10010048] */
    W32((uint32_t)(c->esi), (uint32_t)(c->edi)); /* mov dword ptr [esi], edi */
    goto L_00788625; /* jmp 0x788625 */
L_0078861f:;
    PUSH32(c, 0x00788624u); f_0078864e(c); /* call 0x78864e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00788625:;
    { uint32_t v_ = 0x11u; PUSH32(c, v_); } /* push 0x11 */
    PUSH32(c, 0x0078862cu); f_00788639(c); /* call 0x788639 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_0078862e:;
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(0x790050u)); PUSH32(c, 0x00788636u); call_indirect(c, t_); } /* call dword ptr [0x10010050] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00788639(CPU *c) { /* FUN_10008639 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->eax * 4 + 0x7925f0u)); PUSH32(c, v_); } /* push dword ptr [eax*4 + 0x100125f0] */
    { uint32_t t_ = R32((uint32_t)(0x790054u)); PUSH32(c, 0x0078864cu); call_indirect(c, t_); } /* call dword ptr [0x10010054] */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_0078864e(CPU *c) { /* FUN_1000864e */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x7904d0u; PUSH32(c, v_); } /* push 0x100104d0 */
    { uint32_t v_ = 0x789c84u; PUSH32(c, v_); } /* push 0x10009c84 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00788728; /* je 0x788728 */
    c->eax = (uint32_t)(R32((uint32_t)(0x796c84u))); /* mov eax, dword ptr [0x10016c84] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_007886c1; /* jne 0x7886c1 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x0078868du); f_007885d8(c); /* call 0x7885d8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00788698u); f_0078acd1(c); /* call 0x78acd1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_007886a9; /* je 0x7886a9 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x007886a7u); f_0078acfc(c); /* call 0x78acfc */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_007886a9:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x007886b2u); f_007886b8(c); /* call 0x7886b8 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x1c], 0 */
    goto L_00788709; /* jmp 0x788709 */
L_007886c1:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00788719; /* jne 0x788719 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x007886cdu); f_007885d8(c); /* call 0x7885d8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe0u)); /* lea eax, [ebp - 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd8u)); /* lea eax, [ebp - 0x28] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x007886e3u); f_0078ba2c(c); /* call 0x78ba2c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_007886fc; /* je 0x7886fc */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x28] */
    PUSH32(c, 0x007886f9u); f_0078ba83(c); /* call 0x78ba83 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_007886fc:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00788705u); f_00788710(c); /* call 0x788710 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
L_00788709:;
    if (!c->zf) goto L_00788728; /* jne 0x788728 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    goto L_0078871a; /* jmp 0x78871a */
L_00788719:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
L_0078871a:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x796c80u)); PUSH32(c, v_); } /* push dword ptr [0x10016c80] */
    { uint32_t t_ = R32((uint32_t)(0x790058u)); PUSH32(c, 0x00788728u); call_indirect(c, t_); } /* call dword ptr [0x10010058] */
L_00788728:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_007886b8(CPU *c) { /* FUN_100086b8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x007886bfu); f_00788639(c); /* call 0x788639 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_007886c1(CPU *c) { /* PTR_007886c1 */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) { f_00788719(c); return; } /* jne 0x788719 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x007886cdu); f_007885d8(c); /* call 0x7885d8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe0u)); /* lea eax, [ebp - 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd8u)); /* lea eax, [ebp - 0x28] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x007886e3u); f_0078ba2c(c); /* call 0x78ba2c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_007886fc; /* je 0x7886fc */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x28] */
    PUSH32(c, 0x007886f9u); f_0078ba83(c); /* call 0x78ba83 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_007886fc:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00788705u); f_00788710(c); /* call 0x788710 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) { f_00788728(c); return; } /* jne 0x788728 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { f_0078871a(c); return; } /* jmp 0x78871a */
}

void f_007886fc(CPU *c) { /* PTR_007886fc */
    PREEMPT_POLL(c);
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00788705u); f_00788710(c); /* call 0x788710 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) { f_00788728(c); return; } /* jne 0x788728 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { f_0078871a(c); return; } /* jmp 0x78871a */
}

void f_00788709(CPU *c) { /* PTR_00788709 */
    PREEMPT_POLL(c);
    if (!c->zf) { f_00788728(c); return; } /* jne 0x788728 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { f_0078871a(c); return; } /* jmp 0x78871a */
}

void f_00788710(CPU *c) { /* FUN_10008710 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00788717u); f_00788639(c); /* call 0x788639 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00788719(CPU *c) { /* PTR_00788719 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x796c80u)); PUSH32(c, v_); } /* push dword ptr [0x10016c80] */
    { uint32_t t_ = R32((uint32_t)(0x790058u)); PUSH32(c, 0x00788728u); call_indirect(c, t_); } /* call dword ptr [0x10010058] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0078871a(CPU *c) { /* PTR_0078871a */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x796c80u)); PUSH32(c, v_); } /* push dword ptr [0x10016c80] */
    { uint32_t t_ = R32((uint32_t)(0x790058u)); PUSH32(c, 0x00788728u); call_indirect(c, t_); } /* call dword ptr [0x10010058] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00788728(CPU *c) { /* PTR_00788728 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00788740(CPU *c) { /* _strcmp */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u)); /* test edx, 3 */
    if (!c->zf) goto L_0078878c; /* jne 0x78878c */
L_00788750:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edx))); /* mov eax, dword ptr [edx] */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->ecx))); /* cmp al, byte ptr [ecx] */
    if (!c->zf) goto L_00788784; /* jne 0x788784 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00788780; /* je 0x788780 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), R8((uint32_t)(c->ecx + 0x1u))); /* cmp ah, byte ptr [ecx + 1] */
    if (!c->zf) goto L_00788784; /* jne 0x788784 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | ((uint8_t)(c->eax >> 8))))) << 8); /* or ah, ah */
    if (c->zf) goto L_00788780; /* je 0x788780 */
    c->eax = (uint32_t)(shr32(c, c->eax, 16)); /* shr eax, 0x10 */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->ecx + 0x2u))); /* cmp al, byte ptr [ecx + 2] */
    if (!c->zf) goto L_00788784; /* jne 0x788784 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00788780; /* je 0x788780 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), R8((uint32_t)(c->ecx + 0x3u))); /* cmp ah, byte ptr [ecx + 3] */
    if (!c->zf) goto L_00788784; /* jne 0x788784 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x4u)); /* add edx, 4 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | ((uint8_t)(c->eax >> 8))))) << 8); /* or ah, ah */
    if (!c->zf) goto L_00788750; /* jne 0x788750 */
    c->edi = (uint32_t)(c->edi); /* mov edi, edi */
L_00788780:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_00788784:;
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(shl32(c, c->eax, 1)); /* shl eax, 1 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->esp += 4; return; /* ret  */
L_0078878c:;
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x1u)); /* test edx, 1 */
    if (c->zf) goto L_007887a8; /* je 0x7887a8 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov al, byte ptr [edx] */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->ecx))); /* cmp al, byte ptr [ecx] */
    if (!c->zf) goto L_00788784; /* jne 0x788784 */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00788780; /* je 0x788780 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x2u)); /* test edx, 2 */
    if (c->zf) goto L_00788750; /* je 0x788750 */
L_007887a8:;
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->edx))); /* mov ax, word ptr [edx] */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x2u)); /* add edx, 2 */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->ecx))); /* cmp al, byte ptr [ecx] */
    if (!c->zf) goto L_00788784; /* jne 0x788784 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00788780; /* je 0x788780 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), R8((uint32_t)(c->ecx + 0x1u))); /* cmp ah, byte ptr [ecx + 1] */
    if (!c->zf) goto L_00788784; /* jne 0x788784 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | ((uint8_t)(c->eax >> 8))))) << 8); /* or ah, ah */
    if (c->zf) goto L_00788780; /* je 0x788780 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x2u)); /* add ecx, 2 */
    goto L_00788750; /* jmp 0x788750 */
}

void f_007887c4(CPU *c) { /* FUN_100087c4 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ebx, dword ptr [esi + 0x10] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x82u)); /* test al, 0x82 */
    if (c->zf) goto L_007888d0; /* je 0x7888d0 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x40u)); /* test al, 0x40 */
    if (!c->zf) goto L_007888d0; /* jne 0x7888d0 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    if (c->zf) goto L_007887fc; /* je 0x7887fc */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi + 4], 0 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x10u)); /* test al, 0x10 */
    if (c->zf) goto L_007888d0; /* je 0x7888d0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ecx, dword ptr [esi + 8] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfeu))); /* and al, 0xfe */
    W32((uint32_t)(c->esi), (uint32_t)(c->ecx)); /* mov dword ptr [esi], ecx */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xc], eax */
L_007887fc:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi + 4], 0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp + 0xc], 0 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xefu))); /* and al, 0xef */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x2u))); /* or al, 2 */
    (void)logic16(c, (uint16_t)(((uint16_t)c->eax) & (uint16_t)0x10cu)); /* test ax, 0x10c */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xc], eax */
    if (!c->zf) goto L_00788836; /* jne 0x788836 */
    (void)sub32(c, c->esi, (uint32_t)0x794bc0u); /* cmp esi, 0x10014bc0 */
    if (c->zf) goto L_00788824; /* je 0x788824 */
    (void)sub32(c, c->esi, (uint32_t)0x794be0u); /* cmp esi, 0x10014be0 */
    if (!c->zf) goto L_0078882f; /* jne 0x78882f */
L_00788824:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x0078882au); f_0078cedd(c); /* call 0x78cedd */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00788836; /* jne 0x788836 */
L_0078882f:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00788835u); f_0078ce99(c); /* call 0x78ce99 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00788836:;
    (void)logic16(c, (uint16_t)(R16((uint32_t)(c->esi + 0xcu)) & (uint16_t)0x108u)); /* test word ptr [esi + 0xc], 0x108 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (c->zf) goto L_007888a6; /* je 0x7888a6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edi, dword ptr [esi] */
    c->edi = (uint32_t)(sub32(c, c->edi, c->eax)); /* sub edi, eax */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x1u)); /* lea ecx, [eax + 1] */
    W32((uint32_t)(c->esi), (uint32_t)(c->ecx)); /* mov dword ptr [esi], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x18u))); /* mov ecx, dword ptr [esi + 0x18] */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 4], ecx */
    if ((c->zf || c->sf != c->of)) goto L_00788866; /* jle 0x788866 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x0078885eu); f_0078cca9(c); /* call 0x78cca9 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0xc], eax */
    goto L_0078889c; /* jmp 0x78889c */
L_00788866:;
    (void)sub32(c, c->ebx, (uint32_t)0xffffffffu); /* cmp ebx, -1 */
    if (c->zf) goto L_00788884; /* je 0x788884 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 5)); /* sar ecx, 5 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1fu))); /* and eax, 0x1f */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx * 4 + 0x796ca0u))); /* mov ecx, dword ptr [ecx*4 + 0x10016ca0] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 8)); /* lea eax, [eax + eax*8] */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->eax * 4)); /* lea eax, [ecx + eax*4] */
    goto L_00788889; /* jmp 0x788889 */
L_00788884:;
    c->eax = (uint32_t)((uint32_t)0x7927e0u); /* mov eax, 0x100127e0 */
L_00788889:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + 0x4u)) & (uint8_t)0x20u)); /* test byte ptr [eax + 4], 0x20 */
    if (c->zf) goto L_0078889c; /* je 0x78889c */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00788899u); f_0078cbd1(c); /* call 0x78cbd1 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_0078889c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0x8u))); /* mov cl, byte ptr [ebp + 8] */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax], cl */
    goto L_007888ba; /* jmp 0x7888ba */
L_007888a6:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x8u)); /* lea eax, [ebp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x007888b4u); f_0078cca9(c); /* call 0x78cca9 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0xc], eax */
L_007888ba:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->edi); /* cmp dword ptr [ebp + 0xc], edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    if (c->zf) goto L_007888c6; /* je 0x7888c6 */
    { uint32_t a_ = (uint32_t)(c->esi + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x20u)))); } /* or dword ptr [esi + 0xc], 0x20 */
    goto L_007888d5; /* jmp 0x7888d5 */
L_007888c6:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xffu))); /* and eax, 0xff */
    goto L_007888d8; /* jmp 0x7888d8 */
L_007888d0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x20u))); /* or al, 0x20 */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xc], eax */
L_007888d5:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
L_007888d8:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_007888dc(CPU *c) { /* FUN_100088dc */
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
    if (c->zf) goto L_00788ff5; /* je 0x788ff5 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    goto L_00788910; /* jmp 0x788910 */
L_00788908:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd0u))); /* mov esi, dword ptr [ebp - 0x30] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
L_00788910:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffecu)), c->edx); /* cmp dword ptr [ebp - 0x14], edx */
    if ((c->sf != c->of)) goto L_00788ff5; /* jl 0x788ff5 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x20u); /* cmp bl, 0x20 */
    if ((c->sf != c->of)) goto L_00788931; /* jl 0x788931 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x78u); /* cmp bl, 0x78 */
    if ((!c->zf && c->sf == c->of)) goto L_00788931; /* jg 0x788931 */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx eax, bl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x7904c8u))); /* mov al, byte ptr [eax + 0x100104c8] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xfu))); /* and eax, 0xf */
    goto L_00788933; /* jmp 0x788933 */
L_00788931:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00788933:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->esi + c->eax * 8 + 0x7904e8u))); /* movsx eax, byte ptr [esi + eax*8 + 0x100104e8] */
    c->eax = (uint32_t)(sar32(c, c->eax, 4)); /* sar eax, 4 */
    (void)sub32(c, c->eax, (uint32_t)0x7u); /* cmp eax, 7 */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x30], eax */
    if ((!c->cf && !c->zf)) goto L_00788fe4; /* ja 0x788fe4 */
    { uint32_t t_ = R32((uint32_t)(c->eax * 4 + 0x788ffdu)); switch (t_) { case 0x00788951u: goto L_00788951; case 0x0078896cu: goto L_0078896c; case 0x007889b8u: goto L_007889b8; case 0x007889efu: goto L_007889ef; case 0x007889f7u: goto L_007889f7; case 0x00788a2cu: goto L_00788a2c; case 0x00788a7bu: goto L_00788a7b; case 0x00788abfu: goto L_00788abf; default: jump_indirect(c, t_, 0x0078894au); return; } } /* jmp dword ptr [eax*4 + 0x10008ffd] */
L_00788951:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff0u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 0x10], 0xffffffff */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x34], edx */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x28], edx */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x20], edx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x1c], edx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 4], edx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x24], edx */
    goto L_00788fe4; /* jmp 0x788fe4 */
L_0078896c:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx eax, bl */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x20u)); /* sub eax, 0x20 */
    if (c->zf) goto L_007889af; /* je 0x7889af */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3u)); /* sub eax, 3 */
    if (c->zf) goto L_007889a6; /* je 0x7889a6 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x8u)); /* sub eax, 8 */
    if (c->zf) goto L_0078899d; /* je 0x78899d */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00788994; /* je 0x788994 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3u)); /* sub eax, 3 */
    if (!c->zf) goto L_00788fe4; /* jne 0x788fe4 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x8u)))); } /* or dword ptr [ebp - 4], 8 */
    goto L_00788fe4; /* jmp 0x788fe4 */
L_00788994:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x4u)))); } /* or dword ptr [ebp - 4], 4 */
    goto L_00788fe4; /* jmp 0x788fe4 */
L_0078899d:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x1u)))); } /* or dword ptr [ebp - 4], 1 */
    goto L_00788fe4; /* jmp 0x788fe4 */
L_007889a6:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x80u)))); } /* or byte ptr [ebp - 4], 0x80 */
    goto L_00788fe4; /* jmp 0x788fe4 */
L_007889af:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x2u)))); } /* or dword ptr [ebp - 4], 2 */
    goto L_00788fe4; /* jmp 0x788fe4 */
L_007889b8:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x2au); /* cmp bl, 0x2a */
    if (!c->zf) goto L_007889e0; /* jne 0x7889e0 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x007889c6u); f_007890bb(c); /* call 0x7890bb */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    if ((c->sf == c->of)) goto L_00788fe4; /* jge 0x788fe4 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x4u)))); } /* or dword ptr [ebp - 4], 4 */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
L_007889d8:;
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    goto L_00788fe4; /* jmp 0x788fe4 */
L_007889e0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov eax, dword ptr [ebp - 0x20] */
    c->ecx = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx ecx, bl */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea eax, [eax + eax*4] */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->eax * 2 + 0xffffffd0u)); /* lea eax, [ecx + eax*2 - 0x30] */
    goto L_007889d8; /* jmp 0x7889d8 */
L_007889ef:;
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x10], edx */
    goto L_00788fe4; /* jmp 0x788fe4 */
L_007889f7:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x2au); /* cmp bl, 0x2a */
    if (!c->zf) goto L_00788a1a; /* jne 0x788a1a */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00788a05u); f_007890bb(c); /* call 0x7890bb */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x10], eax */
    if ((c->sf == c->of)) goto L_00788fe4; /* jge 0x788fe4 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff0u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 0x10], 0xffffffff */
    goto L_00788fe4; /* jmp 0x788fe4 */
L_00788a1a:;
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->ecx * 4)); /* lea eax, [ecx + ecx*4] */
    c->ecx = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx ecx, bl */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->eax * 2 + 0xffffffd0u)); /* lea eax, [ecx + eax*2 - 0x30] */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x10], eax */
    goto L_00788fe4; /* jmp 0x788fe4 */
L_00788a2c:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x49u); /* cmp bl, 0x49 */
    if (c->zf) goto L_00788a5f; /* je 0x788a5f */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x68u); /* cmp bl, 0x68 */
    if (c->zf) goto L_00788a56; /* je 0x788a56 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x6cu); /* cmp bl, 0x6c */
    if (c->zf) goto L_00788a4d; /* je 0x788a4d */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x77u); /* cmp bl, 0x77 */
    if (!c->zf) goto L_00788fe4; /* jne 0x788fe4 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffdu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x8u)))); } /* or byte ptr [ebp - 3], 8 */
    goto L_00788fe4; /* jmp 0x788fe4 */
L_00788a4d:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x10u)))); } /* or dword ptr [ebp - 4], 0x10 */
    goto L_00788fe4; /* jmp 0x788fe4 */
L_00788a56:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x20u)))); } /* or dword ptr [ebp - 4], 0x20 */
    goto L_00788fe4; /* jmp 0x788fe4 */
L_00788a5f:;
    (void)sub8(c, R8((uint32_t)(c->edi)), (uint8_t)0x36u); /* cmp byte ptr [edi], 0x36 */
    if (!c->zf) goto L_00788a78; /* jne 0x788a78 */
    (void)sub8(c, R8((uint32_t)(c->edi + 0x1u)), (uint8_t)0x34u); /* cmp byte ptr [edi + 1], 0x34 */
    if (!c->zf) goto L_00788a78; /* jne 0x788a78 */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffdu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x80u)))); } /* or byte ptr [ebp - 3], 0x80 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 0xc], edi */
    goto L_00788fe4; /* jmp 0x788fe4 */
L_00788a78:;
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x30], edx */
L_00788a7b:;
    c->ecx = (uint32_t)(R32((uint32_t)(0x79495cu))); /* mov ecx, dword ptr [0x1001495c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x24], edx */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2 + 0x1u)) & (uint8_t)0x80u)); /* test byte ptr [ecx + eax*2 + 1], 0x80 */
    if (c->zf) goto L_00788aa7; /* je 0x788aa7 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea eax, [ebp - 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx eax, bl */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00788a9eu); f_0078901d(c); /* call 0x78901d */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 0xc], edi */
L_00788aa7:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea eax, [ebp - 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx eax, bl */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00788ab7u); f_0078901d(c); /* call 0x78901d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_00788fe4; /* jmp 0x788fe4 */
L_00788abf:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx eax, bl */
    (void)sub32(c, c->eax, (uint32_t)0x67u); /* cmp eax, 0x67 */
    if ((!c->zf && c->sf == c->of)) goto L_00788ce7; /* jg 0x788ce7 */
    (void)sub32(c, c->eax, (uint32_t)0x65u); /* cmp eax, 0x65 */
    if ((c->sf == c->of)) goto L_00788b6a; /* jge 0x788b6a */
    (void)sub32(c, c->eax, (uint32_t)0x58u); /* cmp eax, 0x58 */
    if ((!c->zf && c->sf == c->of)) goto L_00788bc8; /* jg 0x788bc8 */
    if (c->zf) goto L_00788d5b; /* je 0x788d5b */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x43u)); /* sub eax, 0x43 */
    if (c->zf) goto L_00788b8b; /* je 0x788b8b */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00788b60; /* je 0x788b60 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00788b60; /* je 0x788b60 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0xcu)); /* sub eax, 0xc */
    if (!c->zf) goto L_00788ee6; /* jne 0x788ee6 */
    (void)logic16(c, (uint16_t)(R16((uint32_t)(c->ebp + 0xfffffffcu)) & (uint16_t)0x830u)); /* test word ptr [ebp - 4], 0x830 */
    if (!c->zf) goto L_00788b09; /* jne 0x788b09 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffdu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x8u)))); } /* or byte ptr [ebp - 3], 8 */
L_00788b09:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov esi, dword ptr [ebp - 0x10] */
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (!c->zf) goto L_00788b16; /* jne 0x788b16 */
    c->esi = (uint32_t)((uint32_t)0x7fffffffu); /* mov esi, 0x7fffffff */
L_00788b16:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00788b1fu); f_007890bb(c); /* call 0x7890bb */
    (void)logic16(c, (uint16_t)(R16((uint32_t)(c->ebp + 0xfffffffcu)) & (uint16_t)0x810u)); /* test word ptr [ebp - 4], 0x810 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
    if (c->zf) goto L_00788d2f; /* je 0x788d2f */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (!c->zf) goto L_00788b3e; /* jne 0x788b3e */
    c->ecx = (uint32_t)(R32((uint32_t)(0x7926b4u))); /* mov ecx, dword ptr [0x100126b4] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
L_00788b3e:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x24], 1 */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
L_00788b47:;
    c->edx = (uint32_t)(c->esi); /* mov edx, esi */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_00788d26; /* je 0x788d26 */
    (void)sub16(c, R16((uint32_t)(c->eax)), (uint16_t)0x0u); /* cmp word ptr [eax], 0 */
    if (c->zf) goto L_00788d26; /* je 0x788d26 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_00788b47; /* jmp 0x788b47 */
L_00788b60:;
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x34], 1 */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(add8(c, ((uint8_t)c->ebx), (uint8_t)0x20u)); /* add bl, 0x20 */
L_00788b6a:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x40u)))); } /* or dword ptr [ebp - 4], 0x40 */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0xfffffdb8u)); /* lea edi, [ebp - 0x248] */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 8], edi */
    if ((c->sf == c->of)) goto L_00788c4e; /* jge 0x788c4e */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)((uint32_t)0x6u)); /* mov dword ptr [ebp - 0x10], 6 */
    goto L_00788c5c; /* jmp 0x788c5c */
L_00788b8b:;
    (void)logic16(c, (uint16_t)(R16((uint32_t)(c->ebp + 0xfffffffcu)) & (uint16_t)0x830u)); /* test word ptr [ebp - 4], 0x830 */
    if (!c->zf) goto L_00788b97; /* jne 0x788b97 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffdu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x8u)))); } /* or byte ptr [ebp - 3], 8 */
L_00788b97:;
    (void)logic16(c, (uint16_t)(R16((uint32_t)(c->ebp + 0xfffffffcu)) & (uint16_t)0x810u)); /* test word ptr [ebp - 4], 0x810 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    if (c->zf) goto L_00788bde; /* je 0x788bde */
    PUSH32(c, 0x00788ba8u); f_007890d8(c); /* call 0x7890d8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffdb8u)); /* lea eax, [ebp - 0x248] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00788bb5u); f_0078d066(c); /* call 0x78d066 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf == c->of)) goto L_00788bf1; /* jge 0x788bf1 */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x28], 1 */
    goto L_00788bf1; /* jmp 0x788bf1 */
L_00788bc8:;
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x5au)); /* sub eax, 0x5a */
    if (c->zf) goto L_00788bff; /* je 0x788bff */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x9u)); /* sub eax, 9 */
    if (c->zf) goto L_00788b97; /* je 0x788b97 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00788dc1; /* je 0x788dc1 */
    goto L_00788ee6; /* jmp 0x788ee6 */
L_00788bde:;
    PUSH32(c, 0x00788be3u); f_007890bb(c); /* call 0x7890bb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W8((uint32_t)(c->ebp + 0xfffffdb8u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp - 0x248], al */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0xc], 1 */
L_00788bf1:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffdb8u)); /* lea eax, [ebp - 0x248] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    goto L_00788ee6; /* jmp 0x788ee6 */
L_00788bff:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00788c08u); f_007890bb(c); /* call 0x7890bb */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00788c40; /* je 0x788c40 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00788c40; /* je 0x788c40 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffdu)) & (uint8_t)0x8u)); /* test byte ptr [ebp - 3], 8 */
    if (c->zf) goto L_00788c31; /* je 0x788c31 */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int16_t)R16((uint32_t)(c->eax))); /* movsx eax, word ptr [eax] */
    c->eax = (uint32_t)(shr32(c, c->eax, 1)); /* shr eax, 1 */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x24], 1 */
    goto L_00788ee6; /* jmp 0x788ee6 */
L_00788c31:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffdcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x24], 0 */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int16_t)R16((uint32_t)(c->eax))); /* movsx eax, word ptr [eax] */
    goto L_00788ee3; /* jmp 0x788ee3 */
L_00788c40:;
    c->eax = (uint32_t)(R32((uint32_t)(0x7926b0u))); /* mov eax, dword ptr [0x100126b0] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    goto L_00788cdc; /* jmp 0x788cdc */
L_00788c4e:;
    if (!c->zf) goto L_00788c5c; /* jne 0x788c5c */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x67u); /* cmp bl, 0x67 */
    if (!c->zf) goto L_00788c5c; /* jne 0x788c5c */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x10], 1 */
L_00788c5c:;
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
    { uint32_t t_ = R32((uint32_t)(0x7925d8u)); PUSH32(c, 0x00788c8cu); call_indirect(c, t_); } /* call dword ptr [0x100125d8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov esi, dword ptr [ebp - 4] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0x80u))); /* and esi, 0x80 */
    if (c->zf) goto L_00788cae; /* je 0x788cae */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x10], 0 */
    if (!c->zf) goto L_00788cae; /* jne 0x788cae */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffdb8u)); /* lea eax, [ebp - 0x248] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x7925e4u)); PUSH32(c, 0x00788cadu); call_indirect(c, t_); } /* call dword ptr [0x100125e4] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00788cae:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x67u); /* cmp bl, 0x67 */
    if (!c->zf) goto L_00788cc5; /* jne 0x788cc5 */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_00788cc5; /* jne 0x788cc5 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffdb8u)); /* lea eax, [ebp - 0x248] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x7925dcu)); PUSH32(c, 0x00788cc4u); call_indirect(c, t_); } /* call dword ptr [0x100125dc] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00788cc5:;
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xfffffdb8u)), (uint8_t)0x2du); /* cmp byte ptr [ebp - 0x248], 0x2d */
    if (!c->zf) goto L_00788cdb; /* jne 0x788cdb */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffdu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x1u)))); } /* or byte ptr [ebp - 3], 1 */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0xfffffdb9u)); /* lea edi, [ebp - 0x247] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 8], edi */
L_00788cdb:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
L_00788cdc:;
    PUSH32(c, 0x00788ce1u); f_00789c00(c); /* call 0x789c00 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00788ee3; /* jmp 0x788ee3 */
L_00788ce7:;
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x69u)); /* sub eax, 0x69 */
    if (c->zf) goto L_00788dc1; /* je 0x788dc1 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x5u)); /* sub eax, 5 */
    if (c->zf) goto L_00788d97; /* je 0x788d97 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00788d84; /* je 0x788d84 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00788d54; /* je 0x788d54 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3u)); /* sub eax, 3 */
    if (c->zf) goto L_00788b09; /* je 0x788b09 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00788dc5; /* je 0x788dc5 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3u)); /* sub eax, 3 */
    if (!c->zf) goto L_00788ee6; /* jne 0x788ee6 */
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)((uint32_t)0x27u)); /* mov dword ptr [ebp - 0x2c], 0x27 */
    goto L_00788d62; /* jmp 0x788d62 */
L_00788d26:;
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->eax = (uint32_t)(sar32(c, c->eax, 1)); /* sar eax, 1 */
    goto L_00788ee3; /* jmp 0x788ee3 */
L_00788d2f:;
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (!c->zf) goto L_00788d3c; /* jne 0x788d3c */
    c->ecx = (uint32_t)(R32((uint32_t)(0x7926b0u))); /* mov ecx, dword ptr [0x100126b0] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
L_00788d3c:;
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
L_00788d3e:;
    c->edx = (uint32_t)(c->esi); /* mov edx, esi */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_00788d4d; /* je 0x788d4d */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (c->zf) goto L_00788d4d; /* je 0x788d4d */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_00788d3e; /* jmp 0x788d3e */
L_00788d4d:;
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    goto L_00788ee3; /* jmp 0x788ee3 */
L_00788d54:;
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)((uint32_t)0x8u)); /* mov dword ptr [ebp - 0x10], 8 */
L_00788d5b:;
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)((uint32_t)0x7u)); /* mov dword ptr [ebp - 0x2c], 7 */
L_00788d62:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffcu)) & (uint8_t)0x80u)); /* test byte ptr [ebp - 4], 0x80 */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)((uint32_t)0x10u)); /* mov dword ptr [ebp - 0xc], 0x10 */
    if (c->zf) goto L_00788dcc; /* je 0x788dcc */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0xffffffd4u))); /* mov al, byte ptr [ebp - 0x2c] */
    W8((uint32_t)(c->ebp + 0xffffffeau), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [ebp - 0x16], 0x30 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(add8(c, ((uint8_t)c->eax), (uint8_t)0x51u)); /* add al, 0x51 */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [ebp - 0x1c], 2 */
    W8((uint32_t)(c->ebp + 0xffffffebu), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp - 0x15], al */
    goto L_00788dcc; /* jmp 0x788dcc */
L_00788d84:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffcu)) & (uint8_t)0x80u)); /* test byte ptr [ebp - 4], 0x80 */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)((uint32_t)0x8u)); /* mov dword ptr [ebp - 0xc], 8 */
    if (c->zf) goto L_00788dcc; /* je 0x788dcc */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffdu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x2u)))); } /* or byte ptr [ebp - 3], 2 */
    goto L_00788dcc; /* jmp 0x788dcc */
L_00788d97:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00788da0u); f_007890bb(c); /* call 0x7890bb */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffcu)) & (uint8_t)0x20u)); /* test byte ptr [ebp - 4], 0x20 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00788db0; /* je 0x788db0 */
    c->ecx = (c->ecx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ebp + 0xffffffecu))); /* mov cx, word ptr [ebp - 0x14] */
    W16((uint32_t)(c->eax), (uint16_t)(((uint16_t)c->ecx))); /* mov word ptr [eax], cx */
    goto L_00788db5; /* jmp 0x788db5 */
L_00788db0:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov ecx, dword ptr [ebp - 0x14] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
L_00788db5:;
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x28], 1 */
    goto L_00788fe4; /* jmp 0x788fe4 */
L_00788dc1:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x40u)))); } /* or dword ptr [ebp - 4], 0x40 */
L_00788dc5:;
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)((uint32_t)0xau)); /* mov dword ptr [ebp - 0xc], 0xa */
L_00788dcc:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffdu)) & (uint8_t)0x80u)); /* test byte ptr [ebp - 3], 0x80 */
    if (c->zf) goto L_00788dde; /* je 0x788dde */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00788ddbu); f_007890c8(c); /* call 0x7890c8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00788e1f; /* jmp 0x788e1f */
L_00788dde:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffcu)) & (uint8_t)0x20u)); /* test byte ptr [ebp - 4], 0x20 */
    if (c->zf) goto L_00788e05; /* je 0x788e05 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffcu)) & (uint8_t)0x40u)); /* test byte ptr [ebp - 4], 0x40 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    if (c->zf) goto L_00788dfa; /* je 0x788dfa */
    PUSH32(c, 0x00788df3u); f_007890bb(c); /* call 0x7890bb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int16_t)((uint16_t)c->eax)); /* movsx eax, ax */
L_00788df7:;
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    goto L_00788e1f; /* jmp 0x788e1f */
L_00788dfa:;
    PUSH32(c, 0x00788dffu); f_007890bb(c); /* call 0x7890bb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)((uint32_t)((uint16_t)c->eax)); /* movzx eax, ax */
    goto L_00788df7; /* jmp 0x788df7 */
L_00788e05:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffcu)) & (uint8_t)0x40u)); /* test byte ptr [ebp - 4], 0x40 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    if (c->zf) goto L_00788e17; /* je 0x788e17 */
    PUSH32(c, 0x00788e14u); f_007890bb(c); /* call 0x7890bb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00788df7; /* jmp 0x788df7 */
L_00788e17:;
    PUSH32(c, 0x00788e1cu); f_007890bb(c); /* call 0x7890bb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
L_00788e1f:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffcu)) & (uint8_t)0x40u)); /* test byte ptr [ebp - 4], 0x40 */
    if (c->zf) goto L_00788e40; /* je 0x788e40 */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if ((!c->zf && c->sf == c->of)) goto L_00788e40; /* jg 0x788e40 */
    if ((c->sf != c->of)) goto L_00788e2f; /* jl 0x788e2f */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->cf) goto L_00788e40; /* jae 0x788e40 */
L_00788e2f:;
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->edx = (uint32_t)(adc32(c, c->edx, (uint32_t)0x0u)); /* adc edx, 0 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->edx = (uint32_t)(neg32(c, c->edx)); /* neg edx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffdu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x1u)))); } /* or byte ptr [ebp - 3], 1 */
    c->edi = (uint32_t)(c->edx); /* mov edi, edx */
    goto L_00788e44; /* jmp 0x788e44 */
L_00788e40:;
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->edi = (uint32_t)(c->edx); /* mov edi, edx */
L_00788e44:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffdu)) & (uint8_t)0x80u)); /* test byte ptr [ebp - 3], 0x80 */
    if (!c->zf) goto L_00788e4d; /* jne 0x788e4d */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & (uint32_t)0x0u))); /* and edi, 0 */
L_00788e4d:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x10], 0 */
    if ((c->sf == c->of)) goto L_00788e5c; /* jge 0x788e5c */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x10], 1 */
    goto L_00788e60; /* jmp 0x788e60 */
L_00788e5c:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0xfffffff7u)))); } /* and dword ptr [ebp - 4], 0xfffffff7 */
L_00788e60:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->edi))); /* or eax, edi */
    if (!c->zf) goto L_00788e6a; /* jne 0x788e6a */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x1c], 0 */
L_00788e6a:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffb7u)); /* lea eax, [ebp - 0x49] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
L_00788e70:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff0u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 0x10] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((!c->zf && c->sf == c->of)) goto L_00788e80; /* jg 0x788e80 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->edi))); /* or eax, edi */
    if (c->zf) goto L_00788ebb; /* je 0x788ebb */
L_00788e80:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W32((uint32_t)(c->ebp + 0xffffffc0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x40], eax */
    W32((uint32_t)(c->ebp + 0xffffffc4u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x3c], edx */
    PUSH32(c, 0x00788e93u); f_0078d1a0(c); /* call 0x78d1a0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x3c] */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x30u)); /* add ebx, 0x30 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x40] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00788ea5u); f_0078d130(c); /* call 0x78d130 */
    (void)sub32(c, c->ebx, (uint32_t)0x39u); /* cmp ebx, 0x39 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->edi = (uint32_t)(c->edx); /* mov edi, edx */
    if ((c->zf || c->sf != c->of)) goto L_00788eb1; /* jle 0x788eb1 */
    c->ebx = (uint32_t)(add32(c, c->ebx, R32((uint32_t)(c->ebp + 0xffffffd4u)))); /* add ebx, dword ptr [ebp - 0x2c] */
L_00788eb1:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 8] */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [eax], bl */
    goto L_00788e70; /* jmp 0x788e70 */
L_00788ebb:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffb7u)); /* lea eax, [ebp - 0x49] */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xfffffff8u)))); /* sub eax, dword ptr [ebp - 8] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffdu)) & (uint8_t)0x2u)); /* test byte ptr [ebp - 3], 2 */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    if (c->zf) goto L_00788ee6; /* je 0x788ee6 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    (void)sub8(c, R8((uint32_t)(c->ecx)), (uint8_t)0x30u); /* cmp byte ptr [ecx], 0x30 */
    if (!c->zf) goto L_00788ed9; /* jne 0x788ed9 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00788ee6; /* jne 0x788ee6 */
L_00788ed9:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 8] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    W8((uint32_t)(c->ecx), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [ecx], 0x30 */
L_00788ee3:;
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
L_00788ee6:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x28], 0 */
    if (!c->zf) goto L_00788fe4; /* jne 0x788fe4 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ebx, dword ptr [ebp - 4] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x40u)); /* test bl, 0x40 */
    if (c->zf) goto L_00788f1e; /* je 0x788f1e */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->ebx >> 8)) & (uint8_t)0x1u)); /* test bh, 1 */
    if (c->zf) goto L_00788f03; /* je 0x788f03 */
    W8((uint32_t)(c->ebp + 0xffffffeau), (uint8_t)((uint8_t)0x2du)); /* mov byte ptr [ebp - 0x16], 0x2d */
    goto L_00788f17; /* jmp 0x788f17 */
L_00788f03:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x1u)); /* test bl, 1 */
    if (c->zf) goto L_00788f0e; /* je 0x788f0e */
    W8((uint32_t)(c->ebp + 0xffffffeau), (uint8_t)((uint8_t)0x2bu)); /* mov byte ptr [ebp - 0x16], 0x2b */
    goto L_00788f17; /* jmp 0x788f17 */
L_00788f0e:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x2u)); /* test bl, 2 */
    if (c->zf) goto L_00788f1e; /* je 0x788f1e */
    W8((uint32_t)(c->ebp + 0xffffffeau), (uint8_t)((uint8_t)0x20u)); /* mov byte ptr [ebp - 0x16], 0x20 */
L_00788f17:;
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x1c], 1 */
L_00788f1e:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
    c->esi = (uint32_t)(sub32(c, c->esi, R32((uint32_t)(c->ebp + 0xffffffe4u)))); /* sub esi, dword ptr [ebp - 0x1c] */
    c->esi = (uint32_t)(sub32(c, c->esi, R32((uint32_t)(c->ebp + 0xfffffff4u)))); /* sub esi, dword ptr [ebp - 0xc] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0xcu)); /* test bl, 0xc */
    if (!c->zf) goto L_00788f3e; /* jne 0x788f3e */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea eax, [ebp - 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x20u; PUSH32(c, v_); } /* push 0x20 */
    PUSH32(c, 0x00788f3bu); f_00789052(c); /* call 0x789052 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_00788f3e:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea eax, [ebp - 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffeau)); /* lea eax, [ebp - 0x16] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00788f51u); f_00789083(c); /* call 0x789083 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x8u)); /* test bl, 8 */
    if (c->zf) goto L_00788f70; /* je 0x788f70 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x4u)); /* test bl, 4 */
    if (!c->zf) goto L_00788f70; /* jne 0x788f70 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea eax, [ebp - 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x30u; PUSH32(c, v_); } /* push 0x30 */
    PUSH32(c, 0x00788f6du); f_00789052(c); /* call 0x789052 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_00788f70:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (c->zf) goto L_00788fb7; /* je 0x788fb7 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0xc], 0 */
    if ((c->zf || c->sf != c->of)) goto L_00788fb7; /* jle 0x788fb7 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ebx, dword ptr [ebp - 8] */
    c->edi = (uint32_t)((uint32_t)(c->eax + 0xffffffffu)); /* lea edi, [eax - 1] */
L_00788f85:;
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ebx))); /* mov ax, word ptr [ebx] */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    PUSH32(c, 0x00788f94u); f_0078d066(c); /* call 0x78d066 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if ((c->zf || c->sf != c->of)) goto L_00788fcc; /* jle 0x788fcc */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea ecx, [ebp - 0x14] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00788fabu); f_00789083(c); /* call 0x789083 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00788f85; /* jne 0x788f85 */
    goto L_00788fcc; /* jmp 0x788fcc */
L_00788fb7:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea eax, [ebp - 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffff4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffff8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 8] */
    PUSH32(c, 0x00788fc9u); f_00789083(c); /* call 0x789083 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_00788fcc:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffcu)) & (uint8_t)0x4u)); /* test byte ptr [ebp - 4], 4 */
    if (c->zf) goto L_00788fe4; /* je 0x788fe4 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea eax, [ebp - 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x20u; PUSH32(c, v_); } /* push 0x20 */
    PUSH32(c, 0x00788fe1u); f_00789052(c); /* call 0x789052 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_00788fe4:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & ((uint8_t)c->ebx))); /* test bl, bl */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 0xc], edi */
    if (!c->zf) goto L_00788908; /* jne 0x788908 */
L_00788ff5:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00788951(CPU *c) { /* PTR_00788951 */
    PREEMPT_POLL(c);
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff0u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 0x10], 0xffffffff */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x34], edx */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x28], edx */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x20], edx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x1c], edx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 4], edx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x24], edx */
    goto L_00788fe4; /* jmp 0x788fe4 */
L_00788fe4:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & ((uint8_t)c->ebx))); /* test bl, bl */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 0xc], edi */
    if (!c->zf) { jump_indirect(c, 0x00788908u, 0x00788fefu); return; } /* jne 0x788908 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0078901d(CPU *c) { /* PTR_0078901d */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ecx + 4] */
    if (c->sf) goto L_00789036; /* js 0x789036 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0x8u))); /* mov al, byte ptr [ebp + 8] */
    W8((uint32_t)(c->edx), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edx], al */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->eax)); /* movzx eax, al */
    goto L_00789041; /* jmp 0x789041 */
L_00789036:;
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x0078903fu); f_007887c4(c); /* call 0x7887c4 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00789041:;
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    if (!c->zf) goto L_0078904e; /* jne 0x78904e */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [eax], 0xffffffff */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
L_0078904e:;
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [eax] */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00789052(CPU *c) { /* PTR_00789052 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edi, dword ptr [esp + 0x10] */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_00789080; /* jle 0x789080 */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov esi, dword ptr [esp + 0x18] */
L_00789063:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x14] */
    PUSH32(c, 0x00789071u); f_0078901d(c); /* call 0x78901d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0xffffffffu); /* cmp dword ptr [esi], -1 */
    if (c->zf) goto L_00789080; /* je 0x789080 */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((!c->zf && c->sf == c->of)) goto L_00789063; /* jg 0x789063 */
L_00789080:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00789083(CPU *c) { /* PTR_00789083 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ebx, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_007890b7; /* jle 0x7890b7 */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov edi, dword ptr [esp + 0x1c] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
L_00789099:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->esi))); /* movsx eax, byte ptr [esi] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [esp + 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x007890a8u); f_0078901d(c); /* call 0x78901d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, R32((uint32_t)(c->edi)), (uint32_t)0xffffffffu); /* cmp dword ptr [edi], -1 */
    if (c->zf) goto L_007890b7; /* je 0x7890b7 */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((!c->zf && c->sf == c->of)) goto L_00789099; /* jg 0x789099 */
L_007890b7:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_007890bb(CPU *c) { /* PTR_007890bb */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x4u))); } /* add dword ptr [eax], 4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0xfffffffcu))); /* mov eax, dword ptr [eax - 4] */
    c->esp += 4; return; /* ret  */
}

void f_007890c8(CPU *c) { /* PTR_007890c8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x8u))); } /* add dword ptr [eax], 8 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0xfffffff8u))); /* mov eax, dword ptr [ecx - 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0xfffffffcu))); /* mov edx, dword ptr [ecx - 4] */
    c->esp += 4; return; /* ret  */
}

void f_007890d8(CPU *c) { /* PTR_007890d8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x4u))); } /* add dword ptr [eax], 4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->eax + 0xfffffffcu))); /* mov ax, word ptr [eax - 4] */
    c->esp += 4; return; /* ret  */
}
