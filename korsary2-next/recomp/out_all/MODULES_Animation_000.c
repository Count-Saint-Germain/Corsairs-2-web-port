#include "recomp.h"

void f_00541000(CPU *c) { /* FUN_10001000 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x55c56eu; PUSH32(c, v_); } /* push 0x1001c56e */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x10], esi */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x2bcu)); /* lea ecx, [esi + 0x2bc] */
    PUSH32(c, 0x0054102bu); f_00545f40(c); /* call 0x545f40 */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov ebp, dword ptr [esp + 0x24] */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x1c], 0 */
    (void)logic32(c, (uint32_t)(c->ebp & c->ebp)); /* test ebp, ebp */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x55d100u)); /* mov dword ptr [esi], 0x1001d100 */
    if (!c->zf) goto L_00541061; /* jne 0x541061 */
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    { uint32_t v_ = 0x55f0f0u; PUSH32(c, v_); } /* push 0x1001f0f0 */
    { uint32_t v_ = 0x14u; PUSH32(c, v_); } /* push 0x14 */
    { uint32_t v_ = 0x55f0c0u; PUSH32(c, v_); } /* push 0x1001f0c0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x0054105du); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00541060u, "int3"); /* int3  */
L_00541061:;
    (void)sub8(c, R8((uint32_t)(c->ebp)), (uint8_t)0x0u); /* cmp byte ptr [ebp], 0 */
    if (!c->zf) goto L_00541087; /* jne 0x541087 */
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    { uint32_t v_ = 0x55f07cu; PUSH32(c, v_); } /* push 0x1001f07c */
    { uint32_t v_ = 0x15u; PUSH32(c, v_); } /* push 0x15 */
    { uint32_t v_ = 0x55f0c0u; PUSH32(c, v_); } /* push 0x1001f0c0 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00541083u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00541086u, "int3"); /* int3  */
L_00541087:;
    c->edi = (uint32_t)(c->ebp); /* mov edi, ebp */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0xffffffffu))); /* or ecx, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    while (c->ecx) { (void)sub8(c, ((uint8_t)c->eax), R8(c->edi)); c->edi += (c->df ? -1 : 1); c->ecx--; if (c->zf) break; } /* repne scasb al, byte ptr es:[edi] */
    c->ecx = (uint32_t)((uint32_t)~c->ecx); /* not ecx */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    (void)sub32(c, c->ecx, (uint32_t)0x40u); /* cmp ecx, 0x40 */
    if (c->cf) goto L_005410b8; /* jb 0x5410b8 */
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    { uint32_t v_ = 0x55f068u; PUSH32(c, v_); } /* push 0x1001f068 */
    { uint32_t v_ = 0x16u; PUSH32(c, v_); } /* push 0x16 */
    { uint32_t v_ = 0x55f0c0u; PUSH32(c, v_); } /* push 0x1001f0c0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x005410b4u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x005410b7u, "int3"); /* int3  */
L_005410b8:;
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov edi, dword ptr [esp + 0x28] */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if ((c->sf == c->of)) goto L_005410e0; /* jge 0x5410e0 */
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    { uint32_t v_ = 0x55f058u; PUSH32(c, v_); } /* push 0x1001f058 */
    { uint32_t v_ = 0x17u; PUSH32(c, v_); } /* push 0x17 */
    { uint32_t v_ = 0x55f0c0u; PUSH32(c, v_); } /* push 0x1001f0c0 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x005410dcu); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x005410dfu, "int3"); /* int3  */
L_005410e0:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov ebx, dword ptr [esp + 0x2c] */
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    if ((c->zf || c->sf != c->of)) goto L_00541108; /* jle 0x541108 */
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    { uint32_t v_ = 0x55f040u; PUSH32(c, v_); } /* push 0x1001f040 */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    { uint32_t v_ = 0x55f0c0u; PUSH32(c, v_); } /* push 0x1001f0c0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00541104u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00541107u, "int3"); /* int3  */
L_00541108:;
    c->edx = (uint32_t)(c->esi); /* mov edx, esi */
    c->eax = (uint32_t)(c->ebp); /* mov eax, ebp */
    c->edx = (uint32_t)(sub32(c, c->edx, c->ebp)); /* sub edx, ebp */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x4u)); /* add edx, 4 */
L_00541111:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    W8((uint32_t)(c->edx + c->eax), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [edx + eax], cl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_00541111; /* jne 0x541111 */
    W32((uint32_t)(c->esi + 0x44u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0x44], edi */
    W32((uint32_t)(c->esi + 0x48u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x48], ebx */
    W32((uint32_t)(c->esi + 0x4cu), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [esi + 0x4c], 0x3f800000 */
    W32((uint32_t)(c->esi + 0x50u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [esi + 0x50], 1 */
    W8((uint32_t)(c->esi + 0x54u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esi + 0x54], cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ecx, dword ptr [esp + 0x14] */
    W32((uint32_t)(c->esi + 0x58u), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [esi + 0x58], 0xffffffff */
    W32((uint32_t)(c->esi + 0x2b8u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 0x2b8], 0 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 16; return; /* ret 0xc */
}

void f_00541160(CPU *c) { /* FUN_10001160 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00541168u); f_00541180(c); /* call 0x541180 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00541178; /* je 0x541178 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00541175u); f_00543960(c); /* call 0x543960 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00541178:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00541180(CPU *c) { /* FUN_10001180 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx), (uint32_t)((uint32_t)0x55d100u)); /* mov dword ptr [ecx], 0x1001d100 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x2bcu)); /* add ecx, 0x2bc */
    { f_00545f80(c); return; } /* jmp 0x545f80 */
}

void f_005411a0(CPU *c) { /* FUN_100011a0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x2b8u)), (uint32_t)0x8u); /* cmp dword ptr [esi + 0x2b8], 8 */
    if ((c->sf == c->of)) goto L_005412ba; /* jge 0x5412ba */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ebx, dword ptr [esp + 0xc] */
    (void)sub8(c, R8((uint32_t)(c->ebx)), (uint8_t)0x0u); /* cmp byte ptr [ebx], 0 */
    if (c->zf) goto L_005412ba; /* je 0x5412ba */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ebx); /* mov edi, ebx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0xffffffffu))); /* or ecx, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    while (c->ecx) { (void)sub8(c, ((uint8_t)c->eax), R8(c->edi)); c->edi += (c->df ? -1 : 1); c->ecx--; if (c->zf) break; } /* repne scasb al, byte ptr es:[edi] */
    c->ecx = (uint32_t)((uint32_t)~c->ecx); /* not ecx */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    (void)sub32(c, c->ecx, (uint32_t)0x40u); /* cmp ecx, 0x40 */
    if (c->cf) goto L_005411f1; /* jb 0x5411f1 */
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    { uint32_t v_ = 0x55f0f8u; PUSH32(c, v_); } /* push 0x1001f0f8 */
    { uint32_t v_ = 0x2cu; PUSH32(c, v_); } /* push 0x2c */
    { uint32_t v_ = 0x55f0c0u; PUSH32(c, v_); } /* push 0x1001f0c0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x005411edu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x005411f0u, "int3"); /* int3  */
L_005411f1:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x48u))); /* mov ecx, dword ptr [esi + 0x48] */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0xc], ecx */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0xcu))); /* fild dword ptr [esp + 0xc] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    FCOM(c, ST(0), ST(1)); FPOP(c); /* fcomp st(1) */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00541211; /* jne 0x541211 */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
    goto L_00541213; /* jmp 0x541213 */
L_00541211:;
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
L_00541213:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x44u))); /* mov edx, dword ptr [esi + 0x44] */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0xc], edx */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0xcu))); /* fild dword ptr [esp + 0xc] */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(c->esp + 0x10u)) - ST(0)); /* fsubr dword ptr [esp + 0x10] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x55d108u))); /* fcom dword ptr [0x1001d108] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00541239; /* jp 0x541239 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, (double)RF32((uint32_t)(0x55d108u))); /* fld dword ptr [0x1001d108] */
    goto L_00541269; /* jmp 0x541269 */
L_00541239:;
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x55d108u))); /* fcom dword ptr [0x1001d108] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00541252; /* jne 0x541252 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->edx)); /* sub ecx, edx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x10], ecx */
    ST(0) = FPRES(c, FDIV(c, ST(0), (double)(int32_t)R32((uint32_t)(c->esp + 0x10u)))); /* fidiv dword ptr [esp + 0x10] */
L_00541252:;
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x55d104u))); /* fcom dword ptr [0x1001d104] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00541269; /* jne 0x541269 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, (double)RF32((uint32_t)(0x55d104u))); /* fld dword ptr [0x1001d104] */
L_00541269:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x2b8u))); /* mov eax, dword ptr [esi + 0x2b8] */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    c->edx = (uint32_t)((uint32_t)(c->eax + c->eax * 8)); /* lea edx, [eax + eax*8] */
    c->edx = (uint32_t)((uint32_t)(c->esi + c->edx * 8 + 0x78u)); /* lea edx, [esi + edx*8 + 0x78] */
L_00541278:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov al, byte ptr [ecx] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    W8((uint32_t)(c->edx), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edx], al */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00541278; /* jne 0x541278 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x2b8u))); /* mov eax, dword ptr [esi + 0x2b8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edx, dword ptr [esp + 0x14] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 8)); /* lea eax, [eax + eax*8] */
    WF32((uint32_t)(c->esi + c->eax * 8 + 0xb8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + eax*8 + 0xb8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x2b8u))); /* mov eax, dword ptr [esi + 0x2b8] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->eax * 8)); /* lea ecx, [eax + eax*8] */
    W32((uint32_t)(c->esi + c->ecx * 8 + 0xbcu), (uint32_t)(c->edx)); /* mov dword ptr [esi + ecx*8 + 0xbc], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x2b8u))); /* mov eax, dword ptr [esi + 0x2b8] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    W32((uint32_t)(c->esi + 0x2b8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x2b8], eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
L_005412ba:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
}

void f_005412d0(CPU *c) { /* FUN_100012d0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x005412deu); f_0054dbf0(c); /* call 0x54dbf0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->esp += 8; return; /* ret 4 */
}

void f_005412f0(CPU *c) { /* PTR_005412f0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if ((c->sf != c->of)) goto L_00541304; /* jl 0x541304 */
    (void)sub32(c, c->esi, R32((uint32_t)(c->edi + 0x2b8u))); /* cmp esi, dword ptr [edi + 0x2b8] */
    if ((c->sf != c->of)) goto L_00541324; /* jl 0x541324 */
L_00541304:;
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    { uint32_t v_ = 0x55f114u; PUSH32(c, v_); } /* push 0x1001f114 */
    { uint32_t v_ = 0x47u; PUSH32(c, v_); } /* push 0x47 */
    { uint32_t v_ = 0x55f0c0u; PUSH32(c, v_); } /* push 0x1001f0c0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00541320u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00541323u, "int3"); /* int3  */
L_00541324:;
    c->edx = (uint32_t)((uint32_t)(c->esi + c->esi * 8)); /* lea edx, [esi + esi*8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + c->edx * 8 + 0xbcu))); /* mov eax, dword ptr [edi + edx*8 + 0xbc] */
    c->ecx = (uint32_t)((uint32_t)(c->edi + c->edx * 8)); /* lea ecx, [edi + edx*8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x0u)); /* sub eax, 0 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    if (c->zf) goto L_0054137d; /* je 0x54137d */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00541370; /* je 0x541370 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00541363; /* je 0x541363 */
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    { uint32_t v_ = 0x55f10cu; PUSH32(c, v_); } /* push 0x1001f10c */
    { uint32_t v_ = 0x54u; PUSH32(c, v_); } /* push 0x54 */
    { uint32_t v_ = 0x55f0c0u; PUSH32(c, v_); } /* push 0x1001f0c0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x0054135au); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x0054135du, "int3"); /* int3  */
L_00541363:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0xcu))); /* mov al, byte ptr [esp + 0xc] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_0054139d; /* je 0x54139d */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    c->esp += 16; return; /* ret 0xc */
L_00541370:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0xcu))); /* mov al, byte ptr [esp + 0xc] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00541385; /* jne 0x541385 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    c->esp += 16; return; /* ret 0xc */
L_0054137d:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0xcu))); /* mov al, byte ptr [esp + 0xc] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_0054139d; /* je 0x54139d */
L_00541385:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x8u))); /* fld dword ptr [esp + 8] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->ecx + 0xb8u))); FPOP(c); /* fcomp dword ptr [ecx + 0xb8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x100u))); /* and eax, 0x100 */
    if (c->zf) goto L_005413ae; /* je 0x5413ae */
L_00541398:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 16; return; /* ret 0xc */
L_0054139d:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x8u))); /* fld dword ptr [esp + 8] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->ecx + 0xb8u))); FPOP(c); /* fcomp dword ptr [ecx + 0xb8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x41u)); /* test ah, 0x41 */
    if (PF(c)) goto L_00541398; /* jp 0x541398 */
L_005413ae:;
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    c->esp += 16; return; /* ret 0xc */
}

void f_005413c0(CPU *c) { /* PTR_005413c0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if ((c->sf != c->of)) goto L_005413d4; /* jl 0x5413d4 */
    (void)sub32(c, c->esi, R32((uint32_t)(c->edi + 0x2b8u))); /* cmp esi, dword ptr [edi + 0x2b8] */
    if ((c->sf != c->of)) goto L_005413f4; /* jl 0x5413f4 */
L_005413d4:;
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    { uint32_t v_ = 0x55f114u; PUSH32(c, v_); } /* push 0x1001f114 */
    { uint32_t v_ = 0x5cu; PUSH32(c, v_); } /* push 0x5c */
    { uint32_t v_ = 0x55f0c0u; PUSH32(c, v_); } /* push 0x1001f0c0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x005413f0u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x005413f3u, "int3"); /* int3  */
L_005413f4:;
    c->edx = (uint32_t)((uint32_t)(c->esi + c->esi * 8)); /* lea edx, [esi + esi*8] */
    c->eax = (uint32_t)((uint32_t)(c->edi + c->edx * 8 + 0x78u)); /* lea eax, [edi + edx*8 + 0x78] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00541400(CPU *c) { /* FUN_10001400 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x55c588u; PUSH32(c, v_); } /* push 0x1001c588 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 4], esi */
    c->ecx = (uint32_t)((uint32_t)0x1u); /* mov ecx, 1 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W8((uint32_t)(c->esi + 0x1au), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esi + 0x1a], cl */
    W32((uint32_t)(c->esi + 0x14u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 0x14], ecx */
    c->ecx = (uint32_t)((uint32_t)0x3f800000u); /* mov ecx, 0x3f800000 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    W32((uint32_t)(c->esi + 0x24u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 0x24], ecx */
    W32((uint32_t)(c->esi + 0x28u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 0x28], ecx */
    W32((uint32_t)(c->esi + 0x34u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 0x34], ecx */
    W32((uint32_t)(c->esi + 0x38u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 0x38], ecx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x55d110u)); /* mov dword ptr [esi], 0x1001d110 */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 8], eax */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [esi + 0xc], 0xffffffff */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x10], eax */
    W8((uint32_t)(c->esi + 0x18u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [esi + 0x18], al */
    W8((uint32_t)(c->esi + 0x19u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [esi + 0x19], al */
    W8((uint32_t)(c->esi + 0x2cu), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [esi + 0x2c], al */
    PUSH32(c, 0x00541462u); f_00541d90(c); /* call 0x541d90 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_00541480(CPU *c) { /* FUN_10001480 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00541488u); f_005414a0(c); /* call 0x5414a0 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00541498; /* je 0x541498 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00541495u); f_00543960(c); /* call 0x543960 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00541498:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_005414a0(CPU *c) { /* FUN_100014a0 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx), (uint32_t)((uint32_t)0x55d168u)); /* mov dword ptr [ecx], 0x1001d168 */
    c->esp += 4; return; /* ret  */
}

void f_005414b0(CPU *c) { /* FUN_100014b0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_005414ec; /* je 0x5414ec */
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    { uint32_t v_ = 0x55f168u; PUSH32(c, v_); } /* push 0x1001f168 */
    { uint32_t v_ = 0x2cu; PUSH32(c, v_); } /* push 0x2c */
    { uint32_t v_ = 0x55f134u; PUSH32(c, v_); } /* push 0x1001f134 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x005414d6u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x005414d9u, "int3"); /* int3  */
L_005414ec:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 8], ecx */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0xc], edx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 12; return; /* ret 8 */
}

void f_005414da(CPU *c) { /* PTR_005414da */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 8], edx */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xc], eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 12; return; /* ret 8 */
}

void f_00541500(CPU *c) { /* FUN_10001500 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edi, dword ptr [esp + 0x10] */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    if (c->zf) goto L_0054152f; /* je 0x54152f */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_0054152f; /* je 0x54152f */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x4u)); /* add eax, 4 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00541520u); f_0054dbf0(c); /* call 0x54dbf0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_0054152f; /* jne 0x54152f */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
L_0054152f:;
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x10], ebx */
    W8((uint32_t)(c->esi + 0x19u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [esi + 0x19], bl */
    W8((uint32_t)(c->esi + 0x18u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [esi + 0x18], bl */
    W8((uint32_t)(c->esi + 0x1au), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esi + 0x1a], 1 */
    W32((uint32_t)(c->esi + 0x38u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [esi + 0x38], 0x3f800000 */
    PUSH32(c, 0x0054154au); f_005419a0(c); /* call 0x5419a0 */
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    if (c->zf) goto L_005415e6; /* je 0x5415e6 */
    (void)sub8(c, R8((uint32_t)(c->edi)), ((uint8_t)c->ebx)); /* cmp byte ptr [edi], bl */
    if (c->zf) goto L_005415e6; /* je 0x5415e6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ecx, dword ptr [eax + 8] */
    PUSH32(c, 0x00541566u); f_005438d0(c); /* call 0x5438d0 */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x10], eax */
    if (!c->zf) goto L_00541582; /* jne 0x541582 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ecx, dword ptr [esi + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x0054157au); f_005431e0(c); /* call 0x5431e0 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
L_00541582:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x44u))); /* mov ecx, dword ptr [eax + 0x44] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x48u))); /* mov edx, dword ptr [eax + 0x48] */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if (c->zf) goto L_005415b2; /* je 0x5415b2 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ecx, dword ptr [esi + 8] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov edi, dword ptr [esi + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x28u)); PUSH32(c, 0x00541597u); call_indirect(c, t_); } /* call dword ptr [edx + 0x28] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x48u))); /* mov eax, dword ptr [edi + 0x48] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x44u))); /* mov ecx, dword ptr [edi + 0x44] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x55d1b8u))); /* fmul dword ptr [0x1001d1b8] */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    ST(0) = FPRES(c, FDIV(c, ST(0), (double)(int32_t)R32((uint32_t)(c->esp + 0x10u)))); /* fidiv dword ptr [esp + 0x10] */
    WF32((uint32_t)(c->esi + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x24] */
    goto L_005415b5; /* jmp 0x5415b5 */
L_005415b2:;
    W32((uint32_t)(c->esi + 0x24u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x24], ebx */
L_005415b5:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4cu))); /* mov ecx, dword ptr [eax + 0x4c] */
    W32((uint32_t)(c->esi + 0x28u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 0x28], ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x50u))); /* mov edx, dword ptr [eax + 0x50] */
    W32((uint32_t)(c->esi + 0x14u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x14], edx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x54u))); /* mov al, byte ptr [eax + 0x54] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    W8((uint32_t)(c->esi + 0x2cu), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [esi + 0x2c], al */
    PUSH32(c, 0x005415d1u); f_005419a0(c); /* call 0x5419a0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov ecx, dword ptr [esi + 0xc] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ecx, dword ptr [esi + 8] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x005415deu); f_005431e0(c); /* call 0x5431e0 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
L_005415e6:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov edx, dword ptr [esi + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ecx, dword ptr [esi + 8] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x005415f3u); f_005431e0(c); /* call 0x5431e0 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
}

void f_00541600(CPU *c) { /* PTR_00541600 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x10u))); /* mov eax, dword ptr [ecx + 0x10] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0054160b; /* je 0x54160b */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x4u)); /* add eax, 4 */
    c->esp += 4; return; /* ret  */
L_0054160b:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_00541610(CPU *c) { /* FUN_10001610 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_0054161e; /* jne 0x54161e */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_0054161e:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x18u))); /* mov al, byte ptr [esi + 0x18] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_0054162c; /* je 0x54162c */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x19u))); /* mov al, byte ptr [esi + 0x19] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_0054166a; /* je 0x54166a */
L_0054162c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x19u))); /* mov al, byte ptr [esi + 0x19] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ecx, dword ptr [esi + 8] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    W8((uint32_t)(c->esi + 0x18u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esi + 0x18], 1 */
    if (!c->zf) goto L_0054165b; /* jne 0x54165b */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x00541645u); f_005431e0(c); /* call 0x5431e0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov ecx, dword ptr [esi + 0xc] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ecx, dword ptr [esi + 8] */
    { uint32_t v_ = 0x5u; PUSH32(c, v_); } /* push 5 */
    PUSH32(c, 0x00541653u); f_005431e0(c); /* call 0x5431e0 */
    W8((uint32_t)(c->esi + 0x19u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esi + 0x19], 0 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_0054165b:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov edx, dword ptr [esi + 0xc] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    PUSH32(c, 0x00541666u); f_005431e0(c); /* call 0x5431e0 */
    W8((uint32_t)(c->esi + 0x19u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esi + 0x19], 0 */
L_0054166a:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00541670(CPU *c) { /* PTR_00541670 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov eax, dword ptr [ecx + 0xc] */
    W8((uint32_t)(c->ecx + 0x19u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ecx + 0x19], 1 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov ecx, dword ptr [ecx + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    PUSH32(c, 0x00541682u); f_005431e0(c); /* call 0x5431e0 */
    c->esp += 4; return; /* ret  */
}

void f_00541690(CPU *c) { /* FUN_10001690 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00541698u); f_005419a0(c); /* call 0x5419a0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ecx, dword ptr [esi + 8] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    W8((uint32_t)(c->esi + 0x18u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [esi + 0x18], al */
    W8((uint32_t)(c->esi + 0x19u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [esi + 0x19], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    PUSH32(c, 0x005416aeu); f_005431e0(c); /* call 0x5431e0 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_005416b0(CPU *c) { /* FUN_100016b0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x19u))); /* mov al, byte ptr [esi + 0x19] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00541708; /* jne 0x541708 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ecx, dword ptr [esi + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    W8((uint32_t)(c->esi + 0x18u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esi + 0x18], 0 */
    W8((uint32_t)(c->esi + 0x19u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esi + 0x19], 0 */
    PUSH32(c, 0x005416d0u); f_005431e0(c); /* call 0x5431e0 */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x1cu))); /* fld dword ptr [esi + 0x1c] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x55d108u))); FPOP(c); /* fcomp dword ptr [0x1001d108] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_005416e7; /* jp 0x5416e7 */
    W32((uint32_t)(c->esi + 0x1cu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 0x1c], 0 */
L_005416e7:;
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x1cu))); /* fld dword ptr [esi + 0x1c] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x55d104u))); FPOP(c); /* fcomp dword ptr [0x1001d104] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00541700; /* jne 0x541700 */
    W32((uint32_t)(c->esi + 0x1cu), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [esi + 0x1c], 0x3f800000 */
L_00541700:;
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { f_00541d90(c); return; } /* jmp 0x541d90 */
L_00541708:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00541710(CPU *c) { /* PTR_00541710 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0x18u))); /* mov al, byte ptr [ecx + 0x18] */
    c->esp += 4; return; /* ret  */
}

void f_00541720(CPU *c) { /* PTR_00541720 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0x19u))); /* mov al, byte ptr [ecx + 0x19] */
    c->esp += 4; return; /* ret  */
}

void f_00541730(CPU *c) { /* PTR_00541730 */
    PREEMPT_POLL(c);
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x4u))); /* mov dl, byte ptr [esp + 4] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0x1au))); /* mov al, byte ptr [ecx + 0x1a] */
    W8((uint32_t)(c->ecx + 0x1au), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [ecx + 0x1a], dl */
    c->esp += 8; return; /* ret 4 */
}

void f_00541740(CPU *c) { /* PTR_00541740 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0x1au))); /* mov al, byte ptr [ecx + 0x1a] */
    c->esp += 4; return; /* ret  */
}

void f_00541750(CPU *c) { /* PTR_00541750 */
    PREEMPT_POLL(c);
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x1cu))); /* fld dword ptr [ecx + 0x1c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x4u))); /* fld dword ptr [esp + 4] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x55d108u))); /* fcom dword ptr [0x1001d108] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00541772; /* jp 0x541772 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, (double)RF32((uint32_t)(0x55d108u))); /* fld dword ptr [0x1001d108] */
    WF32((uint32_t)(c->ecx + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [ecx + 0x1c] */
    c->esp += 8; return; /* ret 4 */
L_00541772:;
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x55d104u))); /* fcom dword ptr [0x1001d104] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00541789; /* jne 0x541789 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, (double)RF32((uint32_t)(0x55d104u))); /* fld dword ptr [0x1001d104] */
L_00541789:;
    WF32((uint32_t)(c->ecx + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [ecx + 0x1c] */
    c->esp += 8; return; /* ret 4 */
}

void f_00541790(CPU *c) { /* PTR_00541790 */
    PREEMPT_POLL(c);
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x1cu))); /* fld dword ptr [ecx + 0x1c] */
    c->esp += 4; return; /* ret  */
}

void f_005417a0(CPU *c) { /* PTR_005417a0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    W32((uint32_t)(c->ecx + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 0x14], eax */
    c->esp += 8; return; /* ret 4 */
}

void f_005417b0(CPU *c) { /* PTR_005417b0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x14u))); /* mov eax, dword ptr [ecx + 0x14] */
    c->esp += 4; return; /* ret  */
}

void f_005417c0(CPU *c) { /* PTR_005417c0 */
    PREEMPT_POLL(c);
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x4u))); /* fld dword ptr [esp + 4] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x55d108u))); /* fcom dword ptr [0x1001d108] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_005417e4; /* jp 0x5417e4 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, (double)RF32((uint32_t)(0x55d108u))); /* fld dword ptr [0x1001d108] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x28u))); /* fld dword ptr [ecx + 0x28] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    WF32((uint32_t)(c->ecx + 0x28u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ecx + 0x28] */
    c->esp += 8; return; /* ret 4 */
L_005417e4:;
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x55d1bcu))); /* fcom dword ptr [0x1001d1bc] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_005417fb; /* jne 0x5417fb */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, (double)RF32((uint32_t)(0x55d1bcu))); /* fld dword ptr [0x1001d1bc] */
L_005417fb:;
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x28u))); /* fld dword ptr [ecx + 0x28] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    WF32((uint32_t)(c->ecx + 0x28u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ecx + 0x28] */
    c->esp += 8; return; /* ret 4 */
}

void f_00541810(CPU *c) { /* PTR_00541810 */
    PREEMPT_POLL(c);
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x28u))); /* fld dword ptr [ecx + 0x28] */
    c->esp += 4; return; /* ret  */
}

void f_00541820(CPU *c) { /* PTR_00541820 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x10u))); /* mov eax, dword ptr [ecx + 0x10] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0054182b; /* je 0x54182b */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x4cu))); /* fld dword ptr [eax + 0x4c] */
    c->esp += 4; return; /* ret  */
L_0054182b:;
    FPUSH(c, (double)RF32((uint32_t)(0x55d108u))); /* fld dword ptr [0x1001d108] */
    c->esp += 4; return; /* ret  */
}

void f_00541840(CPU *c) { /* PTR_00541840 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x10u))); /* mov ecx, dword ptr [ecx + 0x10] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00541850; /* je 0x541850 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x48u))); /* mov eax, dword ptr [ecx + 0x48] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x44u))); /* mov edx, dword ptr [ecx + 0x44] */
    c->eax = (uint32_t)(sub32(c, c->eax, c->edx)); /* sub eax, edx */
    c->esp += 4; return; /* ret  */
L_00541850:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_00541860(CPU *c) { /* PTR_00541860 */
    PREEMPT_POLL(c);
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x4u))); /* fld dword ptr [esp + 4] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x55d108u))); FPOP(c); /* fcomp dword ptr [0x1001d108] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_0054187b; /* jp 0x54187b */
    W32((uint32_t)(c->ecx + 0x34u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ecx + 0x34], 0 */
    c->esp += 8; return; /* ret 4 */
L_0054187b:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x4u))); /* fld dword ptr [esp + 4] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x55d104u))); FPOP(c); /* fcomp dword ptr [0x1001d104] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00541898; /* jne 0x541898 */
    W32((uint32_t)(c->ecx + 0x34u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [ecx + 0x34], 0x3f800000 */
    c->esp += 8; return; /* ret 4 */
L_00541898:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    W32((uint32_t)(c->ecx + 0x34u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 0x34], eax */
    c->esp += 8; return; /* ret 4 */
}

void f_005418b0(CPU *c) { /* PTR_005418b0 */
    PREEMPT_POLL(c);
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x34u))); /* fld dword ptr [ecx + 0x34] */
    c->esp += 4; return; /* ret  */
}

void f_005418c0(CPU *c) { /* PTR_005418c0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x10u))); /* mov eax, dword ptr [ecx + 0x10] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_005418ca; /* jne 0x5418ca */
    c->esp += 8; return; /* ret 4 */
L_005418ca:;
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x2bcu)); /* lea ecx, [eax + 0x2bc] */
    { f_00546140(c); return; } /* jmp 0x546140 */
}

void f_005418e0(CPU *c) { /* FUN_100018e0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    W32((uint32_t)(c->esi + 0x38u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [esi + 0x38], 0x3f800000 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00541964; /* je 0x541964 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x18u))); /* mov al, byte ptr [esi + 0x18] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00541964; /* je 0x541964 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x19u))); /* mov al, byte ptr [esi + 0x19] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00541964; /* jne 0x541964 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x14u))); /* mov eax, dword ptr [esi + 0x14] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00541964; /* je 0x541964 */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x28u))); /* fld dword ptr [esi + 0x28] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x24u))); /* fmul dword ptr [esi + 0x24] */
    (void)sub32(c, c->eax, (uint32_t)0x4u); /* cmp eax, 4 */
    ST(0) = FPRES(c, ST(0) * (double)(int32_t)R32((uint32_t)(c->esp + 0x8u))); /* fimul dword ptr [esp + 8] */
    WF32((uint32_t)(c->esp + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 8] */
    if ((!c->cf && !c->zf)) goto L_00541971; /* ja 0x541971 */
    { uint32_t t_ = R32((uint32_t)(c->eax * 4 + 0x541988u)); switch (t_) { case 0x00541920u: goto L_00541920; case 0x0054192eu: goto L_0054192e; case 0x0054193cu: goto L_0054193c; case 0x0054194au: goto L_0054194a; case 0x00541956u: goto L_00541956; default: jump_indirect(c, t_, 0x00541919u); return; } } /* jmp dword ptr [eax*4 + 0x10001988] */
L_00541920:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0054192cu); f_00541a70(c); /* call 0x541a70 */
    goto L_00541956; /* jmp 0x541956 */
L_0054192e:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x0054193au); f_00541ae0(c); /* call 0x541ae0 */
    goto L_00541956; /* jmp 0x541956 */
L_0054193c:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00541948u); f_00541b50(c); /* call 0x541b50 */
    goto L_00541956; /* jmp 0x541956 */
L_0054194a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00541956u); f_00541c20(c); /* call 0x541c20 */
L_00541956:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x18u))); /* mov al, byte ptr [esi + 0x18] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00541968; /* je 0x541968 */
    PUSH32(c, 0x00541964u); f_00541cf0(c); /* call 0x541cf0 */
L_00541964:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
L_00541968:;
    PUSH32(c, 0x0054196du); f_005419a0(c); /* call 0x5419a0 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
L_00541971:;
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x8u)); /* lea ecx, [esp + 8] */
    { uint32_t v_ = 0x55dd90u; PUSH32(c, v_); } /* push 0x1001dd90 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0x55f190u)); /* mov dword ptr [esp + 0x10], 0x1001f190 */
    PUSH32(c, 0x00541988u); f_00546674(c); /* call 0x546674 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(sbb32(c, R32(a_), c->eax))); } /* sbb dword ptr [eax], eax */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(adc8(c, R8(a_), ((uint8_t)(c->eax >> 8))))); } /* adc byte ptr [eax], ah */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(sbb32(c, R32(a_), c->eax))); } /* sbb dword ptr [eax], eax */
    { uint32_t a_ = (uint32_t)(c->esi); W8(a_, (uint8_t)(adc8(c, R8(a_), ((uint8_t)(c->ecx >> 8))))); } /* adc byte ptr [esi], ch */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(sbb32(c, R32(a_), c->eax))); } /* sbb dword ptr [eax], eax */
    { uint32_t a_ = (uint32_t)(c->ecx + c->ebx); W8(a_, (uint8_t)(adc8(c, R8(a_), ((uint8_t)(c->ebx >> 8))))); } /* adc byte ptr [ecx + ebx], bh */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->edx = (uint32_t)(dec32(c, c->edx)); /* dec edx */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(sbb32(c, R32(a_), c->eax))); } /* sbb dword ptr [eax], eax */
    { uint32_t a_ = (uint32_t)(c->eax + 0x8b909090u); W8(a_, (uint8_t)(adc8(c, R8(a_), ((uint8_t)c->edx)))); } /* adc byte ptr [eax - 0x746f6f70], dl */
    { jump_indirect(c, 0x005419a1u, 0x0054199bu); return; }
}

void f_00541920(CPU *c) { /* PTR_00541920 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0054192cu); f_00541a70(c); /* call 0x541a70 */
    goto L_00541956; /* jmp 0x541956 */
L_00541956:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x18u))); /* mov al, byte ptr [esi + 0x18] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00541968; /* je 0x541968 */
    PUSH32(c, 0x00541964u); f_00541cf0(c); /* call 0x541cf0 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
L_00541968:;
    PUSH32(c, 0x0054196du); f_005419a0(c); /* call 0x5419a0 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_0054192e(CPU *c) { /* PTR_0054192e */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x0054193au); f_00541ae0(c); /* call 0x541ae0 */
    goto L_00541956; /* jmp 0x541956 */
L_00541956:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x18u))); /* mov al, byte ptr [esi + 0x18] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00541968; /* je 0x541968 */
    PUSH32(c, 0x00541964u); f_00541cf0(c); /* call 0x541cf0 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
L_00541968:;
    PUSH32(c, 0x0054196du); f_005419a0(c); /* call 0x5419a0 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_0054193c(CPU *c) { /* PTR_0054193c */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00541948u); f_00541b50(c); /* call 0x541b50 */
    goto L_00541956; /* jmp 0x541956 */
L_00541956:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x18u))); /* mov al, byte ptr [esi + 0x18] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00541968; /* je 0x541968 */
    PUSH32(c, 0x00541964u); f_00541cf0(c); /* call 0x541cf0 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
L_00541968:;
    PUSH32(c, 0x0054196du); f_005419a0(c); /* call 0x5419a0 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_0054194a(CPU *c) { /* PTR_0054194a */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00541956u); f_00541c20(c); /* call 0x541c20 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x18u))); /* mov al, byte ptr [esi + 0x18] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00541968; /* je 0x541968 */
    PUSH32(c, 0x00541964u); f_00541cf0(c); /* call 0x541cf0 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
L_00541968:;
    PUSH32(c, 0x0054196du); f_005419a0(c); /* call 0x5419a0 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00541956(CPU *c) { /* PTR_00541956 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x18u))); /* mov al, byte ptr [esi + 0x18] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00541968; /* je 0x541968 */
    PUSH32(c, 0x00541964u); f_00541cf0(c); /* call 0x541cf0 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
L_00541968:;
    PUSH32(c, 0x0054196du); f_005419a0(c); /* call 0x5419a0 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00541968(CPU *c) { /* PTR_00541968 */
    PREEMPT_POLL(c);
    PUSH32(c, 0x0054196du); f_005419a0(c); /* call 0x5419a0 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00541988(CPU *c) { /* PTR_00541988 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(sbb32(c, R32(a_), c->eax))); } /* sbb dword ptr [eax], eax */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(adc8(c, R8(a_), ((uint8_t)(c->eax >> 8))))); } /* adc byte ptr [eax], ah */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(sbb32(c, R32(a_), c->eax))); } /* sbb dword ptr [eax], eax */
    { uint32_t a_ = (uint32_t)(c->esi); W8(a_, (uint8_t)(adc8(c, R8(a_), ((uint8_t)(c->ecx >> 8))))); } /* adc byte ptr [esi], ch */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(sbb32(c, R32(a_), c->eax))); } /* sbb dword ptr [eax], eax */
    { uint32_t a_ = (uint32_t)(c->ecx + c->ebx); W8(a_, (uint8_t)(adc8(c, R8(a_), ((uint8_t)(c->ebx >> 8))))); } /* adc byte ptr [ecx + ebx], bh */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->edx = (uint32_t)(dec32(c, c->edx)); /* dec edx */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(sbb32(c, R32(a_), c->eax))); } /* sbb dword ptr [eax], eax */
    { uint32_t a_ = (uint32_t)(c->eax + 0x8b909090u); W8(a_, (uint8_t)(adc8(c, R8(a_), ((uint8_t)c->edx)))); } /* adc byte ptr [eax - 0x746f6f70], dl */
    { jump_indirect(c, 0x005419a1u, 0x0054199bu); return; }
}

void f_005419a0(CPU *c) { /* FUN_100019a0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x10u))); /* mov eax, dword ptr [ecx + 0x10] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    (void)sub32(c, c->eax, c->edx); /* cmp eax, edx */
    W32((uint32_t)(c->ecx + 0x1cu), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 0x1c], edx */
    W8((uint32_t)(c->ecx + 0x20u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ecx + 0x20], 1 */
    if (c->zf) goto L_005419c7; /* je 0x5419c7 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x14u))); /* mov eax, dword ptr [ecx + 0x14] */
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (c->zf) goto L_005419bd; /* je 0x5419bd */
    (void)sub32(c, c->eax, (uint32_t)0x4u); /* cmp eax, 4 */
    if (!c->zf) goto L_005419c7; /* jne 0x5419c7 */
L_005419bd:;
    W32((uint32_t)(c->ecx + 0x1cu), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [ecx + 0x1c], 0x3f800000 */
    W8((uint32_t)(c->ecx + 0x20u), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [ecx + 0x20], dl */
L_005419c7:;
    { f_00541d90(c); return; } /* jmp 0x541d90 */
}

void f_005419d0(CPU *c) { /* FUN_100019d0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x10u))); /* mov eax, dword ptr [ecx + 0x10] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_005419e4; /* jne 0x5419e4 */
    FPUSH(c, (double)RF32((uint32_t)(0x55d108u))); /* fld dword ptr [0x1001d108] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->esp += 4; return; /* ret  */
L_005419e4:;
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x44u))); /* mov edx, dword ptr [eax + 0x44] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x48u))); /* mov eax, dword ptr [eax + 0x48] */
    c->eax = (uint32_t)(sub32(c, c->eax, c->edx)); /* sub eax, edx */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 4], edx */
    W32((uint32_t)(c->esp), (uint32_t)(c->eax)); /* mov dword ptr [esp], eax */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp))); /* fild dword ptr [esp] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ecx + 0x1cu))); /* fmul dword ptr [ecx + 0x1c] */
    ST(0) = FPRES(c, ST(0) + (double)(int32_t)R32((uint32_t)(c->esp + 0x4u))); /* fiadd dword ptr [esp + 4] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->esp += 4; return; /* ret  */
}

void f_00541a10(CPU *c) { /* FUN_10001a10 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x10u))); /* mov edx, dword ptr [eax + 0x10] */
    W32((uint32_t)(c->ecx + 0x10u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 0x10], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x14u))); /* mov edx, dword ptr [eax + 0x14] */
    W32((uint32_t)(c->ecx + 0x14u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 0x14], edx */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x18u))); /* mov dl, byte ptr [eax + 0x18] */
    W8((uint32_t)(c->ecx + 0x18u), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [ecx + 0x18], dl */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x19u))); /* mov dl, byte ptr [eax + 0x19] */
    W8((uint32_t)(c->ecx + 0x19u), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [ecx + 0x19], dl */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1au))); /* mov dl, byte ptr [eax + 0x1a] */
    W8((uint32_t)(c->ecx + 0x1au), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [ecx + 0x1a], dl */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x1cu))); /* mov edx, dword ptr [eax + 0x1c] */
    W32((uint32_t)(c->ecx + 0x1cu), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 0x1c], edx */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x20u))); /* mov dl, byte ptr [eax + 0x20] */
    W8((uint32_t)(c->ecx + 0x20u), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [ecx + 0x20], dl */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x24u))); /* mov edx, dword ptr [eax + 0x24] */
    W32((uint32_t)(c->ecx + 0x24u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 0x24], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x28u))); /* mov edx, dword ptr [eax + 0x28] */
    W32((uint32_t)(c->ecx + 0x28u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 0x28], edx */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x2cu))); /* mov dl, byte ptr [eax + 0x2c] */
    W8((uint32_t)(c->ecx + 0x2cu), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [ecx + 0x2c], dl */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x30u))); /* mov edx, dword ptr [eax + 0x30] */
    W32((uint32_t)(c->ecx + 0x30u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 0x30], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x34u))); /* mov edx, dword ptr [eax + 0x34] */
    W32((uint32_t)(c->ecx + 0x34u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 0x34], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x38u))); /* mov eax, dword ptr [eax + 0x38] */
    W32((uint32_t)(c->ecx + 0x38u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 0x38], eax */
    c->esp += 8; return; /* ret 4 */
}

void f_00541a70(CPU *c) { /* PTR_00541a70 */
    PREEMPT_POLL(c);
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x4u))); /* fld dword ptr [esp + 4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x1cu))); /* fadd dword ptr [esi + 0x1c] */
    WF32((uint32_t)(c->esi + 0x1cu), (float)ST(0)); /* fst dword ptr [esi + 0x1c] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x55d104u))); FPOP(c); /* fcomp dword ptr [0x1001d104] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x100u))); /* and eax, 0x100 */
    if (!c->zf) goto L_00541ad5; /* jne 0x541ad5 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ecx, dword ptr [esi + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x6u; PUSH32(c, v_); } /* push 6 */
    PUSH32(c, 0x00541a9au); f_005431e0(c); /* call 0x5431e0 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2cu))); /* mov al, byte ptr [esi + 0x2c] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00541ad0; /* je 0x541ad0 */
    PUSH32(c, 0x00541aa8u); f_00541d90(c); /* call 0x541d90 */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x1cu))); /* fld dword ptr [esi + 0x1c] */
    PUSH32(c, 0x00541ab0u); f_005466b0(c); /* call 0x5466b0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov ecx, dword ptr [esi + 0xc] */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 8], eax */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x8u))); /* fild dword ptr [esp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ecx, dword ptr [esi + 8] */
    { uint32_t v_ = 0x5u; PUSH32(c, v_); } /* push 5 */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(c->esi + 0x1cu)) - ST(0)); /* fsubr dword ptr [esi + 0x1c] */
    WF32((uint32_t)(c->esi + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x1c] */
    PUSH32(c, 0x00541accu); f_005431e0(c); /* call 0x5431e0 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
L_00541ad0:;
    PUSH32(c, 0x00541ad5u); f_005416b0(c); /* call 0x5416b0 */
L_00541ad5:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00541ae0(CPU *c) { /* FUN_10001ae0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x1cu))); /* fld dword ptr [esi + 0x1c] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x8u))); /* fsub dword ptr [esp + 8] */
    WF32((uint32_t)(c->esi + 0x1cu), (float)ST(0)); /* fst dword ptr [esi + 0x1c] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x55d108u))); FPOP(c); /* fcomp dword ptr [0x1001d108] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x41u)); /* test ah, 0x41 */
    if (PF(c)) goto L_00541b49; /* jp 0x541b49 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ecx, dword ptr [esi + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x6u; PUSH32(c, v_); } /* push 6 */
    PUSH32(c, 0x00541b08u); f_005431e0(c); /* call 0x5431e0 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2cu))); /* mov al, byte ptr [esi + 0x2c] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00541b44; /* je 0x541b44 */
    PUSH32(c, 0x00541b16u); f_00541d90(c); /* call 0x541d90 */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x1cu))); /* fld dword ptr [esi + 0x1c] */
    PUSH32(c, 0x00541b1eu); f_005466b0(c); /* call 0x5466b0 */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 8], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov ecx, dword ptr [esi + 0xc] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x8u))); /* fild dword ptr [esp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ecx, dword ptr [esi + 8] */
    { uint32_t v_ = 0x5u; PUSH32(c, v_); } /* push 5 */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0x55d104u))); /* fsub dword ptr [0x1001d104] */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(c->esi + 0x1cu)) - ST(0)); /* fsubr dword ptr [esi + 0x1c] */
    WF32((uint32_t)(c->esi + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x1c] */
    PUSH32(c, 0x00541b40u); f_005431e0(c); /* call 0x5431e0 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
L_00541b44:;
    PUSH32(c, 0x00541b49u); f_005416b0(c); /* call 0x5416b0 */
L_00541b49:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00541b50(CPU *c) { /* FUN_10001b50 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x20u))); /* mov al, byte ptr [esi + 0x20] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00541ba9; /* je 0x541ba9 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x8u))); /* fld dword ptr [esp + 8] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x1cu))); /* fadd dword ptr [esi + 0x1c] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x55d104u))); /* fcom dword ptr [0x1001d104] */
    WF32((uint32_t)(c->esi + 0x1cu), (float)ST(0)); /* fst dword ptr [esi + 0x1c] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x100u))); /* and eax, 0x100 */
    if (!c->zf) goto L_00541c13; /* jne 0x541c13 */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    PUSH32(c, 0x00541b7eu); f_005466b0(c); /* call 0x5466b0 */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x8u))); /* fild dword ptr [esp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ecx, dword ptr [esi + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x7u; PUSH32(c, v_); } /* push 7 */
    W8((uint32_t)(c->esi + 0x20u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esi + 0x20], 0 */
    ST(0) = FPRES(c, ST(1) - ST(0)); /* fsubr st(1) */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(0x55d104u)) - ST(0)); /* fsubr dword ptr [0x1001d104] */
    WF32((uint32_t)(c->esi + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x1c] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    PUSH32(c, 0x00541ba5u); f_005431e0(c); /* call 0x5431e0 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
L_00541ba9:;
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x1cu))); /* fld dword ptr [esi + 0x1c] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x8u))); /* fsub dword ptr [esp + 8] */
    WF32((uint32_t)(c->esi + 0x1cu), (float)ST(0)); /* fst dword ptr [esi + 0x1c] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x55d108u))); FPOP(c); /* fcomp dword ptr [0x1001d108] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00541c15; /* jp 0x541c15 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov ecx, dword ptr [esi + 0xc] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ecx, dword ptr [esi + 8] */
    { uint32_t v_ = 0x6u; PUSH32(c, v_); } /* push 6 */
    PUSH32(c, 0x00541bceu); f_005431e0(c); /* call 0x5431e0 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2cu))); /* mov al, byte ptr [esi + 0x2c] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00541c0a; /* je 0x541c0a */
    PUSH32(c, 0x00541bdcu); f_00541d90(c); /* call 0x541d90 */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x1cu))); /* fld dword ptr [esi + 0x1c] */
    PUSH32(c, 0x00541be4u); f_005466b0(c); /* call 0x5466b0 */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 8], eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov edx, dword ptr [esi + 0xc] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x8u))); /* fild dword ptr [esp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ecx, dword ptr [esi + 8] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x5u; PUSH32(c, v_); } /* push 5 */
    W8((uint32_t)(c->esi + 0x20u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esi + 0x20], 1 */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(c->esi + 0x1cu)) - ST(0)); /* fsubr dword ptr [esi + 0x1c] */
    ST(0) = -ST(0); /* fchs  */
    WF32((uint32_t)(c->esi + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x1c] */
    PUSH32(c, 0x00541c06u); f_005431e0(c); /* call 0x5431e0 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
L_00541c0a:;
    PUSH32(c, 0x00541c0fu); f_005416b0(c); /* call 0x5416b0 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
L_00541c13:;
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
L_00541c15:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00541c20(CPU *c) { /* FUN_10001c20 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x20u))); /* mov al, byte ptr [esi + 0x20] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00541c78; /* jne 0x541c78 */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x1cu))); /* fld dword ptr [esi + 0x1c] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x8u))); /* fsub dword ptr [esp + 8] */
    WF32((uint32_t)(c->esi + 0x1cu), (float)ST(0)); /* fst dword ptr [esi + 0x1c] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x55d108u))); FPOP(c); /* fcomp dword ptr [0x1001d108] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00541ce4; /* jp 0x541ce4 */
    PUSH32(c, 0x00541c4au); f_00541d90(c); /* call 0x541d90 */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x1cu))); /* fld dword ptr [esi + 0x1c] */
    PUSH32(c, 0x00541c52u); f_005466b0(c); /* call 0x5466b0 */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x8u))); /* fild dword ptr [esp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ecx, dword ptr [esi + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x7u; PUSH32(c, v_); } /* push 7 */
    W8((uint32_t)(c->esi + 0x20u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esi + 0x20], 1 */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(c->esi + 0x1cu)) - ST(0)); /* fsubr dword ptr [esi + 0x1c] */
    ST(0) = -ST(0); /* fchs  */
    WF32((uint32_t)(c->esi + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x1c] */
    PUSH32(c, 0x00541c74u); f_005431e0(c); /* call 0x5431e0 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
L_00541c78:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x8u))); /* fld dword ptr [esp + 8] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x1cu))); /* fadd dword ptr [esi + 0x1c] */
    WF32((uint32_t)(c->esi + 0x1cu), (float)ST(0)); /* fst dword ptr [esi + 0x1c] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x55d104u))); FPOP(c); /* fcomp dword ptr [0x1001d104] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x100u))); /* and eax, 0x100 */
    if (!c->zf) goto L_00541ce4; /* jne 0x541ce4 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov ecx, dword ptr [esi + 0xc] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ecx, dword ptr [esi + 8] */
    { uint32_t v_ = 0x6u; PUSH32(c, v_); } /* push 6 */
    PUSH32(c, 0x00541c9fu); f_005431e0(c); /* call 0x5431e0 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2cu))); /* mov al, byte ptr [esi + 0x2c] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00541cdf; /* je 0x541cdf */
    PUSH32(c, 0x00541cadu); f_00541d90(c); /* call 0x541d90 */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x1cu))); /* fld dword ptr [esi + 0x1c] */
    PUSH32(c, 0x00541cb5u); f_005466b0(c); /* call 0x5466b0 */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 8], eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov edx, dword ptr [esi + 0xc] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x8u))); /* fild dword ptr [esp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ecx, dword ptr [esi + 8] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x5u; PUSH32(c, v_); } /* push 5 */
    W8((uint32_t)(c->esi + 0x20u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esi + 0x20], 0 */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(c->esi + 0x1cu)) - ST(0)); /* fsubr dword ptr [esi + 0x1c] */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(0x55d104u)) - ST(0)); /* fsubr dword ptr [0x1001d104] */
    WF32((uint32_t)(c->esi + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x1c] */
    PUSH32(c, 0x00541cdbu); f_005431e0(c); /* call 0x5431e0 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
L_00541cdf:;
    PUSH32(c, 0x00541ce4u); f_005416b0(c); /* call 0x5416b0 */
L_00541ce4:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00541cf0(CPU *c) { /* PTR_00541cf0 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00541d8a; /* je 0x541d8a */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x2b8u))); /* mov eax, dword ptr [eax + 0x2b8] */
    c->ebp = (uint32_t)(logic32(c, 0)); /* xor ebp, ebp */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0xc], eax */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 8], ebp */
    if ((c->zf || c->sf != c->of)) goto L_00541d8a; /* jle 0x541d8a */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
L_00541d18:;
    c->eax = (uint32_t)(c->ebp); /* mov eax, ebp */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    c->eax = (uint32_t)(sar32(c, c->eax, 5)); /* sar eax, 5 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x1fu))); /* and ecx, 0x1f */
    c->edi = (uint32_t)((uint32_t)0x1u); /* mov edi, 1 */
    c->edi = (uint32_t)(shl32(c, c->edi, (c->ecx & 0xff))); /* shl edi, cl */
    c->ebx = (uint32_t)((uint32_t)(c->esi + c->eax * 4 + 0x30u)); /* lea ebx, [esi + eax*4 + 0x30] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->eax * 4 + 0x30u))); /* mov eax, dword ptr [esi + eax*4 + 0x30] */
    (void)logic32(c, (uint32_t)(c->edi & c->eax)); /* test edi, eax */
    if (!c->zf) goto L_00541d7b; /* jne 0x541d7b */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x20u))); /* mov cl, byte ptr [esi + 0x20] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x1cu))); /* mov edx, dword ptr [esi + 0x1c] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x00541d46u); f_005412f0(c); /* call 0x5412f0 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00541d77; /* je 0x541d77 */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov ebp, dword ptr [ebx] */
    c->ebp = (uint32_t)(logic32(c, (uint32_t)(c->ebp | c->edi))); /* or ebp, edi */
    W32((uint32_t)(c->ebx), (uint32_t)(c->ebp)); /* mov dword ptr [ebx], ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ebp, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x00541d5du); f_005413c0(c); /* call 0x5413c0 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov edx, dword ptr [esi + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0x3f4u))); /* mov ecx, dword ptr [edx + 0x3f4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00541d7b; /* je 0x541d7b */
    c->edi = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edi, dword ptr [ecx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->edi + 0x4u)); PUSH32(c, 0x00541d75u); call_indirect(c, t_); } /* call dword ptr [edi + 4] */
    goto L_00541d7b; /* jmp 0x541d7b */
L_00541d77:;
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ebp, dword ptr [esp + 0x10] */
L_00541d7b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->ebp = (uint32_t)(inc32(c, c->ebp)); /* inc ebp */
    (void)sub32(c, c->ebp, c->eax); /* cmp ebp, eax */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0x10], ebp */
    if ((c->sf != c->of)) goto L_00541d18; /* jl 0x541d18 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
L_00541d8a:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->esp += 4; return; /* ret  */
}

void f_00541d90(CPU *c) { /* FUN_10001d90 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx + 0x30u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ecx + 0x30], 0 */
    c->esp += 4; return; /* ret  */
}

void f_00541da0(CPU *c) { /* FUN_10001da0 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx), (uint32_t)((uint32_t)0x55d168u)); /* mov dword ptr [ecx], 0x1001d168 */
    c->esp += 4; return; /* ret  */
}

void f_00541db0(CPU *c) { /* FUN_10001db0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x55c5d6u; PUSH32(c, v_); } /* push 0x1001c5d6 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x10], esi */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x55d1fcu)); /* mov dword ptr [esi], 0x1001d1fc */
    { uint32_t v_ = 0x5414a0u; PUSH32(c, v_); } /* push 0x100014a0 */
    { uint32_t v_ = 0x541400u; PUSH32(c, v_); } /* push 0x10001400 */
    c->ebx = (uint32_t)((uint32_t)(c->esi + 0xcu)); /* lea ebx, [esi + 0xc] */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = 0x3cu; PUSH32(c, v_); } /* push 0x3c */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    W32((uint32_t)(c->esp + 0x30u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x30], 0 */
    PUSH32(c, 0x00541df5u); f_005467cb(c); /* call 0x5467cb */
    { uint32_t v_ = 0x545240u; PUSH32(c, v_); } /* push 0x10005240 */
    { uint32_t v_ = 0x5451f0u; PUSH32(c, v_); } /* push 0x100051f0 */
    c->ebp = (uint32_t)((uint32_t)(c->esi + 0x1ecu)); /* lea ebp, [esi + 0x1ec] */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = 0x1cu; PUSH32(c, v_); } /* push 0x1c */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    W8((uint32_t)(c->esp + 0x30u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esp + 0x30], 1 */
    PUSH32(c, 0x00541e14u); f_005467cb(c); /* call 0x5467cb */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov edi, dword ptr [esp + 0x28] */
    W8((uint32_t)(c->esp + 0x1cu), (uint8_t)((uint8_t)0x2u)); /* mov byte ptr [esp + 0x1c], 2 */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x55d1c0u)); /* mov dword ptr [esi], 0x1001d1c0 */
    if (!c->zf) goto L_00541e47; /* jne 0x541e47 */
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    { uint32_t v_ = 0x55f1f4u; PUSH32(c, v_); } /* push 0x1001f1f4 */
    { uint32_t v_ = 0x1au; PUSH32(c, v_); } /* push 0x1a */
    { uint32_t v_ = 0x55f1c4u; PUSH32(c, v_); } /* push 0x1001f1c4 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00541e43u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00541e46u, "int3"); /* int3  */
L_00541e47:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov edx, dword ptr [esp + 0x24] */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 8], edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x5cu))); /* mov eax, dword ptr [edi + 0x5c] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    W32((uint32_t)(c->edi + 0x5cu), (uint32_t)(c->eax)); /* mov dword ptr [edi + 0x5c], eax */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 4], edx */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
L_00541e5a:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    PUSH32(c, 0x00541e63u); f_005414b0(c); /* call 0x5414b0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    PUSH32(c, 0x00541e6bu); f_00545250(c); /* call 0x545250 */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x3cu)); /* add ebx, 0x3c */
    c->ebp = (uint32_t)(add32(c, c->ebp, (uint32_t)0x1cu)); /* add ebp, 0x1c */
    (void)sub32(c, c->edi, (uint32_t)0x8u); /* cmp edi, 8 */
    if ((c->sf != c->of)) goto L_00541e5a; /* jl 0x541e5a */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    { uint32_t v_ = 0x23u; PUSH32(c, v_); } /* push 0x23 */
    { uint32_t v_ = 0x55f1c4u; PUSH32(c, v_); } /* push 0x1001f1c4 */
    c->edi = (uint32_t)(R32((uint32_t)(c->eax + 0x50u))); /* mov edi, dword ptr [eax + 0x50] */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 6)); /* shl ecx, 6 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00541e8fu); f_00543940(c); /* call 0x543940 */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_00541ef0; /* je 0x541ef0 */
    c->eax = (uint32_t)((uint32_t)(c->edi + 0xffffffffu)); /* lea eax, [edi - 1] */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x28], edx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf != c->of)) goto L_00541ef2; /* jl 0x541ef2 */
    c->edi = (uint32_t)((uint32_t)(c->eax + 0x1u)); /* lea edi, [eax + 1] */
L_00541ea6:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov eax, dword ptr [esp + 0x28] */
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
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov ecx, dword ptr [esp + 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x40u)); /* add ecx, 0x40 */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x28], ecx */
    if (!c->zf) goto L_00541ea6; /* jne 0x541ea6 */
    goto L_00541ef2; /* jmp 0x541ef2 */
L_00541ef0:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
L_00541ef2:;
    c->ecx = (uint32_t)((uint32_t)0x48u); /* mov ecx, 0x48 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x2d4u)); /* lea edi, [esi + 0x2d4] */
    W32((uint32_t)(c->esi + 0x2d0u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x2d0], edx */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ecx, dword ptr [esp + 0x14] */
    W32((uint32_t)(c->esi + 0x3f4u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x3f4], eax */
    W8((uint32_t)(c->esi + 0x2ccu), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esi + 0x2cc], 1 */
    W8((uint32_t)(c->esi + 0x2cdu), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esi + 0x2cd], 1 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 12; return; /* ret 8 */
}

void f_00541f40(CPU *c) { /* FUN_10001f40 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00541f48u); f_00541f60(c); /* call 0x541f60 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00541f58; /* je 0x541f58 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00541f55u); f_00543960(c); /* call 0x543960 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00541f58:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00541f60(CPU *c) { /* FUN_10001f60 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x55c616u; PUSH32(c, v_); } /* push 0x1001c616 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 4], esi */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x55d1c0u)); /* mov dword ptr [esi], 0x1001d1c0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [esp + 0x10], 2 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x5cu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [eax + 0x5c] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(!c->sf ? 1 : 0); /* setns al */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00541fbb; /* jne 0x541fbb */
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    { uint32_t v_ = 0x55f234u; PUSH32(c, v_); } /* push 0x1001f234 */
    { uint32_t v_ = 0x80u; PUSH32(c, v_); } /* push 0x80 */
    { uint32_t v_ = 0x55f204u; PUSH32(c, v_); } /* push 0x1001f204 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00541fb7u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00541fbau, "int3"); /* int3  */
L_00541fbb:;
    c->ecx = (uint32_t)(R32((uint32_t)(0x564bc0u))); /* mov ecx, dword ptr [0x10024bc0] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00541fc7u); f_00543eb0(c); /* call 0x543eb0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x2d0u))); /* mov eax, dword ptr [esi + 0x2d0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00541fd3u); f_00543960(c); /* call 0x543960 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->edx = (uint32_t)((uint32_t)(c->esi + 0x1ecu)); /* lea edx, [esi + 0x1ec] */
    W8((uint32_t)(c->esp + 0x10u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esp + 0x10], 1 */
    { uint32_t v_ = 0x545240u; PUSH32(c, v_); } /* push 0x10005240 */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = 0x1cu; PUSH32(c, v_); } /* push 0x1c */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00541ff0u); f_005466d7(c); /* call 0x5466d7 */
    { uint32_t v_ = 0x5414a0u; PUSH32(c, v_); } /* push 0x100014a0 */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0xcu)); /* lea eax, [esi + 0xc] */
    { uint32_t v_ = 0x3cu; PUSH32(c, v_); } /* push 0x3c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W8((uint32_t)(c->esp + 0x20u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esp + 0x20], 0 */
    PUSH32(c, 0x00542007u); f_005466d7(c); /* call 0x5466d7 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x55d1fcu)); /* mov dword ptr [esi], 0x1001d1fc */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_00542020(CPU *c) { /* FUN_10002020 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if ((c->sf != c->of)) goto L_00542031; /* jl 0x542031 */
    (void)sub32(c, c->esi, (uint32_t)0x8u); /* cmp esi, 8 */
    if ((c->sf != c->of)) goto L_00542051; /* jl 0x542051 */
L_00542031:;
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    { uint32_t v_ = 0x55f244u; PUSH32(c, v_); } /* push 0x1001f244 */
    { uint32_t v_ = 0x3au; PUSH32(c, v_); } /* push 0x3a */
    { uint32_t v_ = 0x55f1c4u; PUSH32(c, v_); } /* push 0x1001f1c4 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x0054204du); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00542050u, "int3"); /* int3  */
L_00542051:;
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea eax, [esi + esi*2] */
    c->edx = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea edx, [eax + eax*4] */
    c->eax = (uint32_t)((uint32_t)(c->edi + c->edx * 4 + 0xcu)); /* lea eax, [edi + edx*4 + 0xc] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00542060(CPU *c) { /* FUN_10002060 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if ((c->sf != c->of)) goto L_00542071; /* jl 0x542071 */
    (void)sub32(c, c->esi, (uint32_t)0x8u); /* cmp esi, 8 */
    if ((c->sf != c->of)) goto L_00542091; /* jl 0x542091 */
L_00542071:;
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    { uint32_t v_ = 0x55f244u; PUSH32(c, v_); } /* push 0x1001f244 */
    { uint32_t v_ = 0x41u; PUSH32(c, v_); } /* push 0x41 */
    { uint32_t v_ = 0x55f1c4u; PUSH32(c, v_); } /* push 0x1001f1c4 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x0054208du); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00542090u, "int3"); /* int3  */
L_00542091:;
    c->edx = (uint32_t)((uint32_t)(c->esi * 8)); /* lea edx, [esi*8] */
    c->edx = (uint32_t)(sub32(c, c->edx, c->esi)); /* sub edx, esi */
    c->eax = (uint32_t)((uint32_t)(c->edi + c->edx * 4 + 0x1ecu)); /* lea eax, [edi + edx*4 + 0x1ec] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_005420b0(CPU *c) { /* FUN_100020b0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    (void)sub32(c, c->esi, (uint32_t)0x9u); /* cmp esi, 9 */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    if ((c->sf != c->of)) goto L_005420dd; /* jl 0x5420dd */
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    { uint32_t v_ = 0x55f26cu; PUSH32(c, v_); } /* push 0x1001f26c */
    { uint32_t v_ = 0x49u; PUSH32(c, v_); } /* push 0x49 */
    { uint32_t v_ = 0x55f1c4u; PUSH32(c, v_); } /* push 0x1001f1c4 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x005420d9u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x005420dcu, "int3"); /* int3  */
L_005420dd:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edx, dword ptr [esp + 0x14] */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_00542101; /* je 0x542101 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->eax = (uint32_t)(shl32(c, c->eax, 5)); /* shl eax, 5 */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->edi + 0x2d4u)); /* lea eax, [eax + edi + 0x2d4] */
L_005420f3:;
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0x0u); /* cmp dword ptr [eax], 0 */
    if (c->zf) goto L_00542109; /* je 0x542109 */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x4u)); /* add eax, 4 */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if ((c->sf != c->of)) goto L_005420f3; /* jl 0x5420f3 */
L_00542101:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    c->esp += 16; return; /* ret 0xc */
L_00542109:;
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->esi * 8)); /* lea eax, [ecx + esi*8] */
    W32((uint32_t)(c->edi + c->eax * 4 + 0x2d4u), (uint32_t)(c->edx)); /* mov dword ptr [edi + eax*4 + 0x2d4], edx */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shl32(c, c->eax, 16)); /* shl eax, 0x10 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->ecx))); /* or eax, ecx */
    c->esp += 16; return; /* ret 0xc */
}

void f_00542120(CPU *c) { /* PTR_00542120 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    if ((c->sf != c->of)) goto L_005421c4; /* jl 0x5421c4 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->esi = (uint32_t)(sar32(c, c->esi, 16)); /* sar esi, 0x10 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xffffu))); /* and eax, 0xffff */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    (void)sub32(c, c->esi, (uint32_t)0x9u); /* cmp esi, 9 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    if ((c->sf != c->of)) goto L_00542162; /* jl 0x542162 */
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    { uint32_t v_ = 0x55f26cu; PUSH32(c, v_); } /* push 0x1001f26c */
    { uint32_t v_ = 0x5au; PUSH32(c, v_); } /* push 0x5a */
    { uint32_t v_ = 0x55f1c4u; PUSH32(c, v_); } /* push 0x1001f1c4 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x0054215eu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00542161u, "int3"); /* int3  */
L_00542162:;
    (void)sub32(c, c->edi, (uint32_t)0x8u); /* cmp edi, 8 */
    if ((c->sf != c->of)) goto L_00542187; /* jl 0x542187 */
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    { uint32_t v_ = 0x55f2a0u; PUSH32(c, v_); } /* push 0x1001f2a0 */
    { uint32_t v_ = 0x5bu; PUSH32(c, v_); } /* push 0x5b */
    { uint32_t v_ = 0x55f1c4u; PUSH32(c, v_); } /* push 0x1001f1c4 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00542183u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00542186u, "int3"); /* int3  */
L_00542187:;
    c->eax = (uint32_t)((uint32_t)(c->edi + c->esi * 8)); /* lea eax, [edi + esi*8] */
    c->esi = (uint32_t)((uint32_t)(c->ebx + c->eax * 4 + 0x2d4u)); /* lea esi, [ebx + eax*4 + 0x2d4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + c->eax * 4 + 0x2d4u))); /* mov eax, dword ptr [ebx + eax*4 + 0x2d4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_005421bc; /* jne 0x5421bc */
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    { uint32_t v_ = 0x55f284u; PUSH32(c, v_); } /* push 0x1001f284 */
    { uint32_t v_ = 0x5cu; PUSH32(c, v_); } /* push 0x5c */
    { uint32_t v_ = 0x55f1c4u; PUSH32(c, v_); } /* push 0x1001f1c4 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x005421b8u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x005421bbu, "int3"); /* int3  */
L_005421bc:;
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi], 0 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_005421c4:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
}

void f_005421d0(CPU *c) { /* PTR_005421d0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    W32((uint32_t)(c->ecx + 0x3f4u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 0x3f4], eax */
    c->esp += 8; return; /* ret 4 */
}

void f_005421e0(CPU *c) { /* PTR_005421e0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov eax, dword ptr [ecx + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x50u))); /* mov eax, dword ptr [eax + 0x50] */
    c->esp += 4; return; /* ret  */
}

void f_005421f0(CPU *c) { /* PTR_005421f0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edi, dword ptr [esp + 0xc] */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if ((c->sf != c->of)) goto L_00542204; /* jl 0x542204 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    (void)sub32(c, c->edi, R32((uint32_t)(c->eax + 0x50u))); /* cmp edi, dword ptr [eax + 0x50] */
    if ((c->sf != c->of)) goto L_00542224; /* jl 0x542224 */
L_00542204:;
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    { uint32_t v_ = 0x55f2c0u; PUSH32(c, v_); } /* push 0x1001f2c0 */
    { uint32_t v_ = 0x6fu; PUSH32(c, v_); } /* push 0x6f */
    { uint32_t v_ = 0x55f1c4u; PUSH32(c, v_); } /* push 0x1001f1c4 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00542220u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00542223u, "int3"); /* int3  */
L_00542224:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x2d0u))); /* mov ecx, dword ptr [esi + 0x2d0] */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->eax = (uint32_t)(shl32(c, c->eax, 6)); /* shl eax, 6 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00542240(CPU *c) { /* PTR_00542240 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov ecx, dword ptr [ecx + 8] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x64u)); /* add ecx, 0x64 */
    { f_00546140(c); return; } /* jmp 0x546140 */
}

void f_00542250(CPU *c) { /* PTR_00542250 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edi, dword ptr [esp + 0x10] */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    if ((c->sf != c->of)) goto L_00542262; /* jl 0x542262 */
    (void)sub32(c, c->edi, (uint32_t)0x8u); /* cmp edi, 8 */
    if ((c->sf != c->of)) goto L_00542282; /* jl 0x542282 */
L_00542262:;
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    { uint32_t v_ = 0x55f318u; PUSH32(c, v_); } /* push 0x1001f318 */
    { uint32_t v_ = 0x7cu; PUSH32(c, v_); } /* push 0x7c */
    { uint32_t v_ = 0x55f1c4u; PUSH32(c, v_); } /* push 0x1001f1c4 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x0054227eu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00542281u, "int3"); /* int3  */
L_00542282:;
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ebp, dword ptr [esp + 0x14] */
    (void)logic32(c, (uint32_t)(c->ebp & c->ebp)); /* test ebp, ebp */
    if ((c->sf != c->of)) goto L_0054228f; /* jl 0x54228f */
    (void)sub32(c, c->ebp, (uint32_t)0x8u); /* cmp ebp, 8 */
    if ((c->sf != c->of)) goto L_005422af; /* jl 0x5422af */
L_0054228f:;
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    { uint32_t v_ = 0x55f2ecu; PUSH32(c, v_); } /* push 0x1001f2ec */
    { uint32_t v_ = 0x7du; PUSH32(c, v_); } /* push 0x7d */
    { uint32_t v_ = 0x55f1c4u; PUSH32(c, v_); } /* push 0x1001f1c4 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x005422abu); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x005422aeu, "int3"); /* int3  */
L_005422af:;
    (void)sub32(c, c->edi, c->ebp); /* cmp edi, ebp */
    if (c->zf) goto L_0054230d; /* je 0x54230d */
    c->eax = (uint32_t)((uint32_t)(c->edi + c->edi * 2)); /* lea eax, [edi + edi*2] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea eax, [eax + eax*4] */
    c->ecx = (uint32_t)((uint32_t)(c->esi + c->eax * 4 + 0xcu)); /* lea ecx, [esi + eax*4 + 0xc] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + c->ebp * 2)); /* lea eax, [ebp + ebp*2] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->edx = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea edx, [eax + eax*4] */
    c->ecx = (uint32_t)((uint32_t)(c->esi + c->edx * 4 + 0xcu)); /* lea ecx, [esi + edx*4 + 0xc] */
    PUSH32(c, 0x005422ceu); f_00541a10(c); /* call 0x541a10 */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x1ecu)); /* add esi, 0x1ec */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0x8u)); /* mov dword ptr [esp + 0x14], 8 */
L_005422dc:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x10u)); /* lea ecx, [esp + 0x10] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    W8((uint32_t)(c->esp + 0x18u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esp + 0x18], 0 */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x24u)); PUSH32(c, 0x005422eeu); call_indirect(c, t_); } /* call dword ptr [eax + 0x24] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_005422ff; /* je 0x5422ff */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x1cu)); PUSH32(c, 0x005422ffu); call_indirect(c, t_); } /* call dword ptr [edx + 0x1c] */
L_005422ff:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x1cu)); /* add esi, 0x1c */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    if (!c->zf) goto L_005422dc; /* jne 0x5422dc */
L_0054230d:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 16; return; /* ret 0xc */
}

void f_00542320(CPU *c) { /* PTR_00542320 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov eax, dword ptr [ecx + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x48u))); /* fld dword ptr [eax + 0x48] */
    c->esp += 4; return; /* ret  */
}

void f_00542330(CPU *c) { /* PTR_00542330 */
    PREEMPT_POLL(c);
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x4u))); /* mov dl, byte ptr [esp + 4] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0x2ccu))); /* mov al, byte ptr [ecx + 0x2cc] */
    W8((uint32_t)(c->ecx + 0x2ccu), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [ecx + 0x2cc], dl */
    c->esp += 8; return; /* ret 4 */
}

void f_00542350(CPU *c) { /* PTR_00542350 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0x2ccu))); /* mov al, byte ptr [ecx + 0x2cc] */
    c->esp += 4; return; /* ret  */
}

void f_00542360(CPU *c) { /* PTR_00542360 */
    PREEMPT_POLL(c);
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x4u))); /* mov dl, byte ptr [esp + 4] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0x2cdu))); /* mov al, byte ptr [ecx + 0x2cd] */
    W8((uint32_t)(c->ecx + 0x2cdu), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [ecx + 0x2cd], dl */
    c->esp += 8; return; /* ret 4 */
}

void f_00542380(CPU *c) { /* PTR_00542380 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0x2cdu))); /* mov al, byte ptr [ecx + 0x2cd] */
    c->esp += 4; return; /* ret  */
}

void f_00542390(CPU *c) { /* FUN_10002390 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->ecx); /* mov ebp, ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edi, dword ptr [esp + 0x14] */
    c->esi = (uint32_t)((uint32_t)(c->ebp + 0xcu)); /* lea esi, [ebp + 0xc] */
    c->ebx = (uint32_t)((uint32_t)0x8u); /* mov ebx, 8 */
L_005423a2:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x005423aau); f_005418e0(c); /* call 0x5418e0 */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x3cu)); /* add esi, 0x3c */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->zf) goto L_005423a2; /* jne 0x5423a2 */
    c->esi = (uint32_t)((uint32_t)(c->ebp + 0x1ecu)); /* lea esi, [ebp + 0x1ec] */
    c->ebx = (uint32_t)((uint32_t)0x8u); /* mov ebx, 8 */
L_005423bb:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x005423c3u); f_00545650(c); /* call 0x545650 */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x1cu)); /* add esi, 0x1c */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->zf) goto L_005423bb; /* jne 0x5423bb */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    PUSH32(c, 0x005423d0u); f_005423e0(c); /* call 0x5423e0 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
}

void f_005423e0(CPU *c) { /* FUN_100023e0 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x1c8u)); /* sub esp, 0x1c8 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->ecx); /* mov ebp, ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->esp + 0x30u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0x30], ebp */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x10], 0 */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x1c], 0 */
    c->esi = (uint32_t)((uint32_t)(c->ebp + 0xcu)); /* lea esi, [ebp + 0xc] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->eax + 0x44u))); /* mov ebx, dword ptr [eax + 0x44] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x50u))); /* mov eax, dword ptr [eax + 0x50] */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x2c], eax */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)((uint32_t)0x8u)); /* mov dword ptr [esp + 0x18], 8 */
L_00542418:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x0054241fu); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00542451; /* je 0x542451 */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x38u))); /* fld dword ptr [esi + 0x38] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    WF32((uint32_t)(c->esi + 0x4u), (float)ST(0)); /* fst dword ptr [esi + 4] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0x2cdu))); /* mov al, byte ptr [ebp + 0x2cd] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x10], ecx */
    if (c->zf) goto L_00542444; /* je 0x542444 */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x34u))); /* fmul dword ptr [esi + 0x34] */
    WF32((uint32_t)(c->esi + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 4] */
    goto L_00542446; /* jmp 0x542446 */
L_00542444:;
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
L_00542446:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fld dword ptr [esp + 0x1c] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x4u))); /* fadd dword ptr [esi + 4] */
    WF32((uint32_t)(c->esp + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1c] */
L_00542451:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x3cu)); /* add esi, 0x3c */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x18], eax */
    if (!c->zf) goto L_00542418; /* jne 0x542418 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_005431d0; /* je 0x5431d0 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fld dword ptr [esp + 0x1c] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x55d108u))); FPOP(c); /* fcomp dword ptr [0x1001d108] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x44u)); /* test ah, 0x44 */
    if (!PF(c)) goto L_0054305c; /* jnp 0x54305c */
    (void)sub32(c, c->ecx, (uint32_t)0x1u); /* cmp ecx, 1 */
    if ((c->zf || c->sf != c->of)) goto L_00542b61; /* jle 0x542b61 */
    FPUSH(c, (double)RF32((uint32_t)(0x55d104u))); /* fld dword ptr [0x1001d104] */
    ST(0) = FPRES(c, FDIV(c, ST(0), (double)RF32((uint32_t)(c->esp + 0x1cu)))); /* fdiv dword ptr [esp + 0x1c] */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xcu)); /* lea ecx, [ebp + 0xc] */
    WF32((uint32_t)(c->esp + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1c] */
    PUSH32(c, 0x0054249fu); f_005419d0(c); /* call 0x5419d0 */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    PUSH32(c, 0x005424a6u); f_005466b0(c); /* call 0x5466b0 */
    W32((uint32_t)(c->esp + 0x34u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x34], eax */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x34u))); /* fild dword ptr [esp + 0x34] */
    ST(0) = FPRES(c, ST(1) - ST(0)); /* fsubr st(1) */
    WF32((uint32_t)(c->esp + 0x38u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x38] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    if ((c->sf != c->of)) goto L_005424c9; /* jl 0x5424c9 */
    c->eax = (uint32_t)((uint32_t)(c->ebx + 0xffffffffu)); /* lea eax, [ebx - 1] */
    W32((uint32_t)(c->esp + 0x38u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x38], 0 */
    W32((uint32_t)(c->esp + 0x34u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x34], eax */
L_005424c9:;
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0x48u)); /* lea ecx, [ebp + 0x48] */
    PUSH32(c, 0x005424d1u); f_005419d0(c); /* call 0x5419d0 */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    PUSH32(c, 0x005424d8u); f_005466b0(c); /* call 0x5466b0 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x10], edi */
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x10u))); /* fild dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(1) - ST(0)); /* fsubr st(1) */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    if ((c->sf != c->of)) goto L_005424fd; /* jl 0x5424fd */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x14], 0 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x10], ebx */
    c->edi = (uint32_t)(c->ebx); /* mov edi, ebx */
L_005424fd:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fld dword ptr [esp + 0x1c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ebp + 0x10u))); /* fmul dword ptr [ebp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov eax, dword ptr [esp + 0x2c] */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(0x55d104u)) - ST(0)); /* fsubr dword ptr [0x1001d104] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x18], esi */
    WF32((uint32_t)(c->esp + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1c] */
    if ((c->zf || c->sf != c->of)) goto L_0054305c; /* jle 0x54305c */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x8cu)); /* lea ecx, [esp + 0x8c] */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x28], ecx */
    goto L_00542535; /* jmp 0x542535 */
L_0054252d:;
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov esi, dword ptr [esp + 0x18] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edi, dword ptr [esp + 0x10] */
L_00542535:;
    c->ebp = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebp, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if ((c->sf != c->of)) goto L_00542548; /* jl 0x542548 */
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0x50u))); /* cmp esi, dword ptr [ebp + 0x50] */
    if ((c->sf == c->of)) goto L_00542548; /* jge 0x542548 */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    goto L_0054254a; /* jmp 0x54254a */
L_00542548:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_0054254a:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = 0x55f380u; PUSH32(c, v_); } /* push 0x1001f380 */
    { uint32_t v_ = 0x72u; PUSH32(c, v_); } /* push 0x72 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(!c->zf ? 1 : 0); /* setne dl */
    { uint32_t v_ = 0x55f204u; PUSH32(c, v_); } /* push 0x1001f204 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00542561u); f_005434a0(c); /* call 0x5434a0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x4cu))); /* mov ecx, dword ptr [ebp + 0x4c] */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea eax, [esi + esi*2] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    c->eax = (uint32_t)(sub32(c, c->eax, c->esi)); /* sub eax, esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->ebp = (uint32_t)((uint32_t)(c->ecx + c->eax * 4)); /* lea ebp, [ecx + eax*4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov eax, dword ptr [esp + 0x28] */
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
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x38u))); /* mov eax, dword ptr [esp + 0x38] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov ebx, dword ptr [esp + 0x34] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x7cu)); /* lea edx, [esp + 0x7c] */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x005425c2u); f_00545d30(c); /* call 0x545d30 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edx, dword ptr [esp + 0x14] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x10cu)); /* lea ecx, [esp + 0x10c] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    PUSH32(c, 0x005425d7u); f_00545d30(c); /* call 0x545d30 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov eax, dword ptr [esp + 0x1c] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x10cu)); /* lea ecx, [esp + 0x10c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x80u)); /* lea edx, [esp + 0x80] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0xf8u)); /* lea eax, [esp + 0xf8] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x005425f9u); f_0054ffcb(c); /* call 0x54ffcb */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0xf0u)); /* lea ecx, [esp + 0xf0] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x8cu)); /* lea edx, [esp + 0x8c] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x0054260eu); f_0054f68a(c); /* call 0x54f68a */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x14u)); /* lea eax, [ebp + 0x14] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    W32((uint32_t)(c->esp + 0xbcu), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0xbc], ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov edx, dword ptr [eax + 4] */
    W32((uint32_t)(c->esp + 0xc0u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0xc0], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    W32((uint32_t)(c->esp + 0xc4u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0xc4], eax */
    if (!c->zf) goto L_005427a5; /* jne 0x5427a5 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    c->edx = (uint32_t)((uint32_t)(c->ebx + c->ebx * 2)); /* lea edx, [ebx + ebx*2] */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->edx * 4)); /* lea eax, [ecx + edx*4] */
    c->edx = (uint32_t)((uint32_t)(c->ebx + c->ebx * 2 + 0x3u)); /* lea edx, [ebx + ebx*2 + 3] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + c->edx * 4))); /* fld dword ptr [ecx + edx*4] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->eax))); /* fsub dword ptr [eax] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + c->edx * 4 + 0x4u))); /* fld dword ptr [ecx + edx*4 + 4] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->eax + 0x4u))); /* fsub dword ptr [eax + 4] */
    c->edx = (uint32_t)((uint32_t)(c->ecx + c->edx * 4)); /* lea edx, [ecx + edx*4] */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + 0x8u))); /* fld dword ptr [edx + 8] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->eax + 0x8u))); /* fsub dword ptr [eax + 8] */
    c->edx = (uint32_t)((uint32_t)(c->edi + c->edi * 2 + 0x3u)); /* lea edx, [edi + edi*2 + 3] */
    WF32((uint32_t)(c->esp + 0x1b0u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1b0] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x38u))); /* fmul dword ptr [esp + 0x38] */
    WF32((uint32_t)(c->esp + 0x1b4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1b4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x38u))); /* fmul dword ptr [esp + 0x38] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1b0u))); /* fld dword ptr [esp + 0x1b0] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x38u))); /* fmul dword ptr [esp + 0x38] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1b4u))); /* fld dword ptr [esp + 0x1b4] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->eax))); /* fadd dword ptr [eax] */
    WF32((uint32_t)(c->esp + 0x100u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x100] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->eax + 0x4u))); /* fadd dword ptr [eax + 4] */
    WF32((uint32_t)(c->esp + 0x104u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x104] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->eax + 0x8u))); /* fadd dword ptr [eax + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + c->edx * 4))); /* fld dword ptr [ecx + edx*4] */
    c->eax = (uint32_t)((uint32_t)(c->edi + c->edi * 2)); /* lea eax, [edi + edi*2] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->ecx + c->eax * 4))); /* fsub dword ptr [ecx + eax*4] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + c->edx * 4 + 0x4u))); /* fld dword ptr [ecx + edx*4 + 4] */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->eax * 4)); /* lea eax, [ecx + eax*4] */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->edx * 4)); /* lea ecx, [ecx + edx*4] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->eax + 0x4u))); /* fsub dword ptr [eax + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x8u))); /* fld dword ptr [ecx + 8] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->eax + 0x8u))); /* fsub dword ptr [eax + 8] */
    WF32((uint32_t)(c->esp + 0x1c8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1c8] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x14u))); /* fmul dword ptr [esp + 0x14] */
    WF32((uint32_t)(c->esp + 0x19cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x19c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x14u))); /* fmul dword ptr [esp + 0x14] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1c8u))); /* fld dword ptr [esp + 0x1c8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x14u))); /* fmul dword ptr [esp + 0x14] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x19cu))); /* fld dword ptr [esp + 0x19c] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->eax))); /* fadd dword ptr [eax] */
    WF32((uint32_t)(c->esp + 0xd8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xd8] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->eax + 0x4u))); /* fadd dword ptr [eax + 4] */
    WF32((uint32_t)(c->esp + 0xdcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xdc] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->eax + 0x8u))); /* fadd dword ptr [eax + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xd8u))); /* fld dword ptr [esp + 0xd8] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x100u))); /* fsub dword ptr [esp + 0x100] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xdcu))); /* fld dword ptr [esp + 0xdc] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x104u))); /* fsub dword ptr [esp + 0x104] */
    WF32((uint32_t)(c->esp + 0xe8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xe8] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) - ST(2)); /* fsub st(2) */
    WF32((uint32_t)(c->esp + 0xecu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xec] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fmul dword ptr [esp + 0x1c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xe8u))); /* fld dword ptr [esp + 0xe8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fmul dword ptr [esp + 0x1c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xecu))); /* fld dword ptr [esp + 0xec] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fmul dword ptr [esp + 0x1c] */
    WF32((uint32_t)(c->esp + 0x1d4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1d4] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x100u))); /* fadd dword ptr [esp + 0x100] */
    WF32((uint32_t)(c->esp + 0xccu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xcc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xccu))); /* mov eax, dword ptr [esp + 0xcc] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x104u))); /* fadd dword ptr [esp + 0x104] */
    W32((uint32_t)(c->esp + 0xbcu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0xbc], eax */
    WF32((uint32_t)(c->esp + 0xd0u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xd0] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1d4u))); /* fld dword ptr [esp + 0x1d4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xd0u))); /* mov ecx, dword ptr [esp + 0xd0] */
    ST(0) = FPRES(c, ST(0) + ST(1)); /* fadd st(1) */
    W32((uint32_t)(c->esp + 0xc0u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0xc0], ecx */
    WF32((uint32_t)(c->esp + 0xd4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xd4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xd4u))); /* mov edx, dword ptr [esp + 0xd4] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    W32((uint32_t)(c->esp + 0xc4u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0xc4], edx */
L_005427a5:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x4u))); /* mov eax, dword ptr [ebp + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00542b21; /* je 0x542b21 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x3cu)); /* add eax, 0x3c */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x24], eax */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x3cu)); /* lea eax, [esp + 0x3c] */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x20], eax */
    c->df = 0; /* cld  */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov edi, dword ptr [esp + 0x20] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov esi, dword ptr [esp + 0x24] */
    c->ecx = (uint32_t)((uint32_t)0x10u); /* mov ecx, 0x10 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x6cu))); /* fld dword ptr [esp + 0x6c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x98u))); /* fmul dword ptr [esp + 0x98] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x5cu))); /* fld dword ptr [esp + 0x5c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x94u))); /* fmul dword ptr [esp + 0x94] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x4cu))); /* fld dword ptr [esp + 0x4c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x90u))); /* fmul dword ptr [esp + 0x90] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x3cu))); /* fld dword ptr [esp + 0x3c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x8cu))); /* fmul dword ptr [esp + 0x8c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->ebp + 0x3cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp + 0x3c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x70u))); /* fld dword ptr [esp + 0x70] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x98u))); /* fmul dword ptr [esp + 0x98] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x60u))); /* fld dword ptr [esp + 0x60] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x94u))); /* fmul dword ptr [esp + 0x94] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x50u))); /* fld dword ptr [esp + 0x50] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x90u))); /* fmul dword ptr [esp + 0x90] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x40u))); /* fld dword ptr [esp + 0x40] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x8cu))); /* fmul dword ptr [esp + 0x8c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->ebp + 0x40u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp + 0x40] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x74u))); /* fld dword ptr [esp + 0x74] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x98u))); /* fmul dword ptr [esp + 0x98] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x90u))); /* fld dword ptr [esp + 0x90] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x54u))); /* fmul dword ptr [esp + 0x54] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x94u))); /* fld dword ptr [esp + 0x94] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x64u))); /* fmul dword ptr [esp + 0x64] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x44u))); /* fld dword ptr [esp + 0x44] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x8cu))); /* fmul dword ptr [esp + 0x8c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->ebp + 0x44u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp + 0x44] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x90u))); /* fld dword ptr [esp + 0x90] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x58u))); /* fmul dword ptr [esp + 0x58] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x94u))); /* fld dword ptr [esp + 0x94] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x68u))); /* fmul dword ptr [esp + 0x68] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x98u))); /* fld dword ptr [esp + 0x98] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x78u))); /* fmul dword ptr [esp + 0x78] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x8cu))); /* fld dword ptr [esp + 0x8c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x48u))); /* fmul dword ptr [esp + 0x48] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->ebp + 0x48u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp + 0x48] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x6cu))); /* fld dword ptr [esp + 0x6c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xa8u))); /* fmul dword ptr [esp + 0xa8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x5cu))); /* fld dword ptr [esp + 0x5c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xa4u))); /* fmul dword ptr [esp + 0xa4] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x4cu))); /* fld dword ptr [esp + 0x4c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xa0u))); /* fmul dword ptr [esp + 0xa0] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x3cu))); /* fld dword ptr [esp + 0x3c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x9cu))); /* fmul dword ptr [esp + 0x9c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->ebp + 0x4cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp + 0x4c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x70u))); /* fld dword ptr [esp + 0x70] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xa8u))); /* fmul dword ptr [esp + 0xa8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x60u))); /* fld dword ptr [esp + 0x60] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xa4u))); /* fmul dword ptr [esp + 0xa4] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x50u))); /* fld dword ptr [esp + 0x50] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xa0u))); /* fmul dword ptr [esp + 0xa0] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x40u))); /* fld dword ptr [esp + 0x40] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x9cu))); /* fmul dword ptr [esp + 0x9c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->ebp + 0x50u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp + 0x50] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x74u))); /* fld dword ptr [esp + 0x74] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xa8u))); /* fmul dword ptr [esp + 0xa8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x44u))); /* fld dword ptr [esp + 0x44] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x9cu))); /* fmul dword ptr [esp + 0x9c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xa0u))); /* fld dword ptr [esp + 0xa0] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x54u))); /* fmul dword ptr [esp + 0x54] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xa4u))); /* fld dword ptr [esp + 0xa4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x64u))); /* fmul dword ptr [esp + 0x64] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->ebp + 0x54u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp + 0x54] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xa0u))); /* fld dword ptr [esp + 0xa0] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x58u))); /* fmul dword ptr [esp + 0x58] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xa4u))); /* fld dword ptr [esp + 0xa4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x68u))); /* fmul dword ptr [esp + 0x68] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xa8u))); /* fld dword ptr [esp + 0xa8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x78u))); /* fmul dword ptr [esp + 0x78] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x9cu))); /* fld dword ptr [esp + 0x9c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x48u))); /* fmul dword ptr [esp + 0x48] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->ebp + 0x58u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp + 0x58] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x6cu))); /* fld dword ptr [esp + 0x6c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xb8u))); /* fmul dword ptr [esp + 0xb8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x5cu))); /* fld dword ptr [esp + 0x5c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xb4u))); /* fmul dword ptr [esp + 0xb4] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x4cu))); /* fld dword ptr [esp + 0x4c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xb0u))); /* fmul dword ptr [esp + 0xb0] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x3cu))); /* fld dword ptr [esp + 0x3c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xacu))); /* fmul dword ptr [esp + 0xac] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->ebp + 0x5cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp + 0x5c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x70u))); /* fld dword ptr [esp + 0x70] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xb8u))); /* fmul dword ptr [esp + 0xb8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x60u))); /* fld dword ptr [esp + 0x60] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xb4u))); /* fmul dword ptr [esp + 0xb4] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x50u))); /* fld dword ptr [esp + 0x50] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xb0u))); /* fmul dword ptr [esp + 0xb0] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x40u))); /* fld dword ptr [esp + 0x40] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xacu))); /* fmul dword ptr [esp + 0xac] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->ebp + 0x60u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp + 0x60] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x74u))); /* fld dword ptr [esp + 0x74] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xb8u))); /* fmul dword ptr [esp + 0xb8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x44u))); /* fld dword ptr [esp + 0x44] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xacu))); /* fmul dword ptr [esp + 0xac] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xb0u))); /* fld dword ptr [esp + 0xb0] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x54u))); /* fmul dword ptr [esp + 0x54] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xb4u))); /* fld dword ptr [esp + 0xb4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x64u))); /* fmul dword ptr [esp + 0x64] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->ebp + 0x64u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp + 0x64] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xb0u))); /* fld dword ptr [esp + 0xb0] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x58u))); /* fmul dword ptr [esp + 0x58] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xb4u))); /* fld dword ptr [esp + 0xb4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x68u))); /* fmul dword ptr [esp + 0x68] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xb8u))); /* fld dword ptr [esp + 0xb8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x78u))); /* fmul dword ptr [esp + 0x78] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xacu))); /* fld dword ptr [esp + 0xac] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x48u))); /* fmul dword ptr [esp + 0x48] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->ebp + 0x68u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp + 0x68] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x6cu))); /* fld dword ptr [esp + 0x6c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xc8u))); /* fmul dword ptr [esp + 0xc8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x5cu))); /* fld dword ptr [esp + 0x5c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xc4u))); /* fmul dword ptr [esp + 0xc4] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x4cu))); /* fld dword ptr [esp + 0x4c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xc0u))); /* fmul dword ptr [esp + 0xc0] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x3cu))); /* fld dword ptr [esp + 0x3c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xbcu))); /* fmul dword ptr [esp + 0xbc] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->ebp + 0x6cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp + 0x6c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x70u))); /* fld dword ptr [esp + 0x70] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xc8u))); /* fmul dword ptr [esp + 0xc8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x60u))); /* fld dword ptr [esp + 0x60] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xc4u))); /* fmul dword ptr [esp + 0xc4] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x50u))); /* fld dword ptr [esp + 0x50] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xc0u))); /* fmul dword ptr [esp + 0xc0] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x40u))); /* fld dword ptr [esp + 0x40] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xbcu))); /* fmul dword ptr [esp + 0xbc] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->ebp + 0x70u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp + 0x70] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x74u))); /* fld dword ptr [esp + 0x74] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xc8u))); /* fmul dword ptr [esp + 0xc8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x44u))); /* fld dword ptr [esp + 0x44] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xbcu))); /* fmul dword ptr [esp + 0xbc] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xc0u))); /* fld dword ptr [esp + 0xc0] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x54u))); /* fmul dword ptr [esp + 0x54] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xc4u))); /* fld dword ptr [esp + 0xc4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x64u))); /* fmul dword ptr [esp + 0x64] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->ebp + 0x74u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp + 0x74] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xc0u))); /* fld dword ptr [esp + 0xc0] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x58u))); /* fmul dword ptr [esp + 0x58] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xc4u))); /* fld dword ptr [esp + 0xc4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x68u))); /* fmul dword ptr [esp + 0x68] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xc8u))); /* fld dword ptr [esp + 0xc8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x78u))); /* fmul dword ptr [esp + 0x78] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xbcu))); /* fld dword ptr [esp + 0xbc] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x48u))); /* fmul dword ptr [esp + 0x48] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->ebp + 0x78u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp + 0x78] */
    goto L_00542b43; /* jmp 0x542b43 */
L_00542b21:;
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x8cu)); /* lea ecx, [esp + 0x8c] */
    c->ebp = (uint32_t)(add32(c, c->ebp, (uint32_t)0x3cu)); /* add ebp, 0x3c */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x20], ecx */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0x24], ebp */
    c->df = 0; /* cld  */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov edi, dword ptr [esp + 0x24] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov esi, dword ptr [esp + 0x20] */
    c->ecx = (uint32_t)((uint32_t)0x10u); /* mov ecx, 0x10 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
L_00542b43:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov ecx, dword ptr [esp + 0x2c] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov ebp, dword ptr [esp + 0x30] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x18], eax */
    if ((c->sf != c->of)) goto L_0054252d; /* jl 0x54252d */
    goto L_0054305c; /* jmp 0x54305c */
L_00542b61:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
    c->esi = (uint32_t)((uint32_t)(c->ebp + 0xcu)); /* lea esi, [ebp + 0xc] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00542b6cu); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00542dd6; /* je 0x542dd6 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00542b7bu); f_005419d0(c); /* call 0x5419d0 */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    PUSH32(c, 0x00542b82u); f_005466b0(c); /* call 0x5466b0 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x10], edi */
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x10u))); /* fild dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(1) - ST(0)); /* fsubr st(1) */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    if ((c->sf != c->of)) goto L_00542ba7; /* jl 0x542ba7 */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x14], 0 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x10], ebx */
    c->edi = (uint32_t)(c->ebx); /* mov edi, ebx */
L_00542ba7:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov eax, dword ptr [esp + 0x2c] */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x18], esi */
    if ((c->zf || c->sf != c->of)) goto L_0054305c; /* jle 0x54305c */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x3cu)); /* lea eax, [esp + 0x3c] */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x20], eax */
    goto L_00542bcb; /* jmp 0x542bcb */
L_00542bc3:;
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov esi, dword ptr [esp + 0x18] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edi, dword ptr [esp + 0x10] */
L_00542bcb:;
    c->ebp = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebp, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if ((c->sf != c->of)) goto L_00542bde; /* jl 0x542bde */
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0x50u))); /* cmp esi, dword ptr [ebp + 0x50] */
    if ((c->sf == c->of)) goto L_00542bde; /* jge 0x542bde */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    goto L_00542be0; /* jmp 0x542be0 */
L_00542bde:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00542be0:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = 0x55f380u; PUSH32(c, v_); } /* push 0x1001f380 */
    { uint32_t v_ = 0x72u; PUSH32(c, v_); } /* push 0x72 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(!c->zf ? 1 : 0); /* setne cl */
    { uint32_t v_ = 0x55f204u; PUSH32(c, v_); } /* push 0x1001f204 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00542bf7u); f_005434a0(c); /* call 0x5434a0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x4cu))); /* mov eax, dword ptr [ebp + 0x4c] */
    c->edx = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea edx, [esi + esi*2] */
    c->edx = (uint32_t)(shl32(c, c->edx, 4)); /* shl edx, 4 */
    c->edx = (uint32_t)(sub32(c, c->edx, c->esi)); /* sub edx, esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->ebp = (uint32_t)((uint32_t)(c->eax + c->edx * 4)); /* lea ebp, [eax + edx*4] */
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
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edx, dword ptr [esp + 0x14] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x7cu)); /* lea ecx, [esp + 0x7c] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    PUSH32(c, 0x00542c54u); f_00545d30(c); /* call 0x545d30 */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x7cu)); /* lea eax, [esp + 0x7c] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x3cu)); /* lea ecx, [esp + 0x3c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00542c63u); f_0054f68a(c); /* call 0x54f68a */
    c->edx = (uint32_t)((uint32_t)(c->ebp + 0x14u)); /* lea edx, [ebp + 0x14] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx))); /* mov eax, dword ptr [edx] */
    W32((uint32_t)(c->esp + 0x6cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x6c], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov ecx, dword ptr [edx + 4] */
    W32((uint32_t)(c->esp + 0x70u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x70], ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov edx, dword ptr [edx + 8] */
    W32((uint32_t)(c->esp + 0x74u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x74], edx */
    if (!c->zf) goto L_00542d59; /* jne 0x542d59 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->ecx = (uint32_t)((uint32_t)(c->edi + c->edi * 2 + 0x3u)); /* lea ecx, [edi + edi*2 + 3] */
    c->esi = (uint32_t)((uint32_t)(c->edi + c->edi * 2)); /* lea esi, [edi + edi*2] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + c->ecx * 4 + 0x8u))); /* fld dword ptr [eax + ecx*4 + 8] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->ecx * 4)); /* lea ecx, [eax + ecx*4] */
    c->esi = (uint32_t)(shl32(c, c->esi, 2)); /* shl esi, 2 */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->eax + c->esi + 0x8u))); /* fsub dword ptr [eax + esi + 8] */
    WF32((uint32_t)(c->esp + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x4u))); /* fld dword ptr [ecx + 4] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->eax + c->esi + 0x4u))); /* fsub dword ptr [eax + esi + 4] */
    WF32((uint32_t)(c->esp + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx))); /* fld dword ptr [ecx] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->eax + c->esi))); /* fsub dword ptr [eax + esi] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0xf0u)); /* lea ecx, [esp + 0xf0] */
    WF32((uint32_t)(c->esp), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp] */
    PUSH32(c, 0x00542cc0u); f_00543230(c); /* call 0x543230 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xecu))); /* fld dword ptr [esp + 0xec] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x14u))); /* fmul dword ptr [esp + 0x14] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0xe4u)); /* lea ecx, [esp + 0xe4] */
    WF32((uint32_t)(c->esp + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xf4u))); /* fld dword ptr [esp + 0xf4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x20u))); /* fmul dword ptr [esp + 0x20] */
    WF32((uint32_t)(c->esp + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xf0u))); /* fld dword ptr [esp + 0xf0] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x20u))); /* fmul dword ptr [esp + 0x20] */
    WF32((uint32_t)(c->esp), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp] */
    PUSH32(c, 0x00542cfbu); f_00543230(c); /* call 0x543230 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xecu))); /* fld dword ptr [esp + 0xec] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->eax + c->esi + 0x8u))); /* fadd dword ptr [eax + esi + 8] */
    c->eax = (uint32_t)(add32(c, c->eax, c->esi)); /* add eax, esi */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0xd8u)); /* lea ecx, [esp + 0xd8] */
    WF32((uint32_t)(c->esp + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xe8u))); /* fld dword ptr [esp + 0xe8] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->eax + 0x4u))); /* fadd dword ptr [eax + 4] */
    WF32((uint32_t)(c->esp + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xe4u))); /* fld dword ptr [esp + 0xe4] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->eax))); /* fadd dword ptr [eax] */
    WF32((uint32_t)(c->esp), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp] */
    PUSH32(c, 0x00542d38u); f_00543230(c); /* call 0x543230 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xccu))); /* mov edx, dword ptr [esp + 0xcc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xd0u))); /* mov eax, dword ptr [esp + 0xd0] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xd4u))); /* mov ecx, dword ptr [esp + 0xd4] */
    W32((uint32_t)(c->esp + 0x6cu), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x6c], edx */
    W32((uint32_t)(c->esp + 0x70u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x70], eax */
    W32((uint32_t)(c->esp + 0x74u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x74], ecx */
L_00542d59:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x4u))); /* mov eax, dword ptr [ebp + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00542d99; /* je 0x542d99 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x3cu)); /* add eax, 0x3c */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x11cu)); /* lea edx, [esp + 0x11c] */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x24], eax */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x28], edx */
    c->df = 0; /* cld  */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov edi, dword ptr [esp + 0x28] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov esi, dword ptr [esp + 0x24] */
    c->ecx = (uint32_t)((uint32_t)0x10u); /* mov ecx, 0x10 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x11cu)); /* lea eax, [esp + 0x11c] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x3cu)); /* lea ecx, [esp + 0x3c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0x3cu)); /* lea ecx, [ebp + 0x3c] */
    PUSH32(c, 0x00542d97u); f_00543250(c); /* call 0x543250 */
    goto L_00542db8; /* jmp 0x542db8 */
L_00542d99:;
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x3cu)); /* lea edx, [esp + 0x3c] */
    c->ebp = (uint32_t)(add32(c, c->ebp, (uint32_t)0x3cu)); /* add ebp, 0x3c */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x24], edx */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0x28], ebp */
    c->df = 0; /* cld  */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov edi, dword ptr [esp + 0x28] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov esi, dword ptr [esp + 0x24] */
    c->ecx = (uint32_t)((uint32_t)0x10u); /* mov ecx, 0x10 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
L_00542db8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov ecx, dword ptr [esp + 0x2c] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov ebp, dword ptr [esp + 0x30] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x18], eax */
    if ((c->sf != c->of)) goto L_00542bc3; /* jl 0x542bc3 */
    goto L_0054305c; /* jmp 0x54305c */
L_00542dd6:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x48u))); /* mov eax, dword ptr [ebp + 0x48] */
    c->esi = (uint32_t)((uint32_t)(c->ebp + 0x48u)); /* lea esi, [ebp + 0x48] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x00542de1u); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00543048; /* je 0x543048 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00542df0u); f_005419d0(c); /* call 0x5419d0 */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    PUSH32(c, 0x00542df7u); f_005466b0(c); /* call 0x5466b0 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x10], edi */
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x10u))); /* fild dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(1) - ST(0)); /* fsubr st(1) */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    if ((c->sf != c->of)) goto L_00542e1c; /* jl 0x542e1c */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x14], 0 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x10], ebx */
    c->edi = (uint32_t)(c->ebx); /* mov edi, ebx */
L_00542e1c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov eax, dword ptr [esp + 0x2c] */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x18], esi */
    if ((c->zf || c->sf != c->of)) goto L_0054305c; /* jle 0x54305c */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x3cu)); /* lea ecx, [esp + 0x3c] */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x20], ecx */
    goto L_00542e40; /* jmp 0x542e40 */
L_00542e38:;
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov esi, dword ptr [esp + 0x18] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edi, dword ptr [esp + 0x10] */
L_00542e40:;
    c->ebp = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebp, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if ((c->sf != c->of)) goto L_00542e53; /* jl 0x542e53 */
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0x50u))); /* cmp esi, dword ptr [ebp + 0x50] */
    if ((c->sf == c->of)) goto L_00542e53; /* jge 0x542e53 */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    goto L_00542e55; /* jmp 0x542e55 */
L_00542e53:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00542e55:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = 0x55f380u; PUSH32(c, v_); } /* push 0x1001f380 */
    { uint32_t v_ = 0x72u; PUSH32(c, v_); } /* push 0x72 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(!c->zf ? 1 : 0); /* setne dl */
    { uint32_t v_ = 0x55f204u; PUSH32(c, v_); } /* push 0x1001f204 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00542e6cu); f_005434a0(c); /* call 0x5434a0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x4cu))); /* mov ecx, dword ptr [ebp + 0x4c] */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea eax, [esi + esi*2] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    c->eax = (uint32_t)(sub32(c, c->eax, c->esi)); /* sub eax, esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->ebp = (uint32_t)((uint32_t)(c->ecx + c->eax * 4)); /* lea ebp, [ecx + eax*4] */
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
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x7cu)); /* lea edx, [esp + 0x7c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    PUSH32(c, 0x00542ec9u); f_00545d30(c); /* call 0x545d30 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x7cu)); /* lea ecx, [esp + 0x7c] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x3cu)); /* lea edx, [esp + 0x3c] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00542ed8u); f_0054f68a(c); /* call 0x54f68a */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x14u)); /* lea eax, [ebp + 0x14] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    W32((uint32_t)(c->esp + 0x6cu), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x6c], ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov edx, dword ptr [eax + 4] */
    W32((uint32_t)(c->esp + 0x70u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x70], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    W32((uint32_t)(c->esp + 0x74u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x74], eax */
    if (!c->zf) goto L_00542fce; /* jne 0x542fce */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->ecx = (uint32_t)((uint32_t)(c->edi + c->edi * 2 + 0x3u)); /* lea ecx, [edi + edi*2 + 3] */
    c->esi = (uint32_t)((uint32_t)(c->edi + c->edi * 2)); /* lea esi, [edi + edi*2] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + c->ecx * 4 + 0x8u))); /* fld dword ptr [eax + ecx*4 + 8] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->ecx * 4)); /* lea ecx, [eax + ecx*4] */
    c->esi = (uint32_t)(shl32(c, c->esi, 2)); /* shl esi, 2 */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->eax + c->esi + 0x8u))); /* fsub dword ptr [eax + esi + 8] */
    WF32((uint32_t)(c->esp + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x4u))); /* fld dword ptr [ecx + 4] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->eax + c->esi + 0x4u))); /* fsub dword ptr [eax + esi + 4] */
    WF32((uint32_t)(c->esp + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx))); /* fld dword ptr [ecx] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->eax + c->esi))); /* fsub dword ptr [eax + esi] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0xf0u)); /* lea ecx, [esp + 0xf0] */
    WF32((uint32_t)(c->esp), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp] */
    PUSH32(c, 0x00542f35u); f_00543230(c); /* call 0x543230 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xecu))); /* fld dword ptr [esp + 0xec] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x14u))); /* fmul dword ptr [esp + 0x14] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0xe4u)); /* lea ecx, [esp + 0xe4] */
    WF32((uint32_t)(c->esp + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xf4u))); /* fld dword ptr [esp + 0xf4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x20u))); /* fmul dword ptr [esp + 0x20] */
    WF32((uint32_t)(c->esp + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xf0u))); /* fld dword ptr [esp + 0xf0] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x20u))); /* fmul dword ptr [esp + 0x20] */
    WF32((uint32_t)(c->esp), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp] */
    PUSH32(c, 0x00542f70u); f_00543230(c); /* call 0x543230 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xecu))); /* fld dword ptr [esp + 0xec] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->eax + c->esi + 0x8u))); /* fadd dword ptr [eax + esi + 8] */
    c->eax = (uint32_t)(add32(c, c->eax, c->esi)); /* add eax, esi */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0xd8u)); /* lea ecx, [esp + 0xd8] */
    WF32((uint32_t)(c->esp + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xe8u))); /* fld dword ptr [esp + 0xe8] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->eax + 0x4u))); /* fadd dword ptr [eax + 4] */
    WF32((uint32_t)(c->esp + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xe4u))); /* fld dword ptr [esp + 0xe4] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->eax))); /* fadd dword ptr [eax] */
    WF32((uint32_t)(c->esp), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp] */
    PUSH32(c, 0x00542fadu); f_00543230(c); /* call 0x543230 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xccu))); /* mov edx, dword ptr [esp + 0xcc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xd0u))); /* mov eax, dword ptr [esp + 0xd0] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xd4u))); /* mov ecx, dword ptr [esp + 0xd4] */
    W32((uint32_t)(c->esp + 0x6cu), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x6c], edx */
    W32((uint32_t)(c->esp + 0x70u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x70], eax */
    W32((uint32_t)(c->esp + 0x74u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x74], ecx */
L_00542fce:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x4u))); /* mov eax, dword ptr [ebp + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0054300e; /* je 0x54300e */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x3cu)); /* add eax, 0x3c */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x11cu)); /* lea edx, [esp + 0x11c] */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x24], eax */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x28], edx */
    c->df = 0; /* cld  */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov edi, dword ptr [esp + 0x28] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov esi, dword ptr [esp + 0x24] */
    c->ecx = (uint32_t)((uint32_t)0x10u); /* mov ecx, 0x10 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x11cu)); /* lea eax, [esp + 0x11c] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x3cu)); /* lea ecx, [esp + 0x3c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0x3cu)); /* lea ecx, [ebp + 0x3c] */
    PUSH32(c, 0x0054300cu); f_00543250(c); /* call 0x543250 */
    goto L_0054302d; /* jmp 0x54302d */
L_0054300e:;
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x3cu)); /* lea edx, [esp + 0x3c] */
    c->ebp = (uint32_t)(add32(c, c->ebp, (uint32_t)0x3cu)); /* add ebp, 0x3c */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x24], edx */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0x28], ebp */
    c->df = 0; /* cld  */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov edi, dword ptr [esp + 0x28] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov esi, dword ptr [esp + 0x24] */
    c->ecx = (uint32_t)((uint32_t)0x10u); /* mov ecx, 0x10 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
L_0054302d:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov ecx, dword ptr [esp + 0x2c] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov ebp, dword ptr [esp + 0x30] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x18], eax */
    if ((c->sf != c->of)) goto L_00542e38; /* jl 0x542e38 */
    goto L_0054305c; /* jmp 0x54305c */
L_00543048:;
    c->eax = (uint32_t)(R32((uint32_t)(0x564cecu))); /* mov eax, dword ptr [0x10024cec] */
    { uint32_t v_ = 0x55f344u; PUSH32(c, v_); } /* push 0x1001f344 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x00543058u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    guest_trap(c, 0x0054305bu, "int3"); /* int3  */
L_0054305c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov eax, dword ptr [esp + 0x2c] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x18], edi */
    if ((c->zf || c->sf != c->of)) goto L_005431d0; /* jle 0x5431d0 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x8cu)); /* lea edx, [esp + 0x8c] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x15cu)); /* lea eax, [esp + 0x15c] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x11cu)); /* lea ecx, [esp + 0x11c] */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x24], edx */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x28], eax */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x14], ecx */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x11cu)); /* lea edx, [esp + 0x11c] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x3cu)); /* lea eax, [esp + 0x3c] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x3cu)); /* lea ecx, [esp + 0x3c] */
    W32((uint32_t)(c->esp + 0x38u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x38], edx */
    W32((uint32_t)(c->esp + 0x30u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x30], eax */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x1c], ecx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x10], edi */
    W32((uint32_t)(c->esp + 0x34u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x34], edi */
    goto L_005430b8; /* jmp 0x5430b8 */
L_005430b4:;
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov edi, dword ptr [esp + 0x34] */
L_005430b8:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if ((c->sf != c->of)) goto L_005430d1; /* jl 0x5430d1 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov edx, dword ptr [esp + 0x18] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    (void)sub32(c, c->edx, c->eax); /* cmp edx, eax */
    if ((c->sf == c->of)) goto L_005430d1; /* jge 0x5430d1 */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    goto L_005430d3; /* jmp 0x5430d3 */
L_005430d1:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_005430d3:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = 0x55f380u; PUSH32(c, v_); } /* push 0x1001f380 */
    { uint32_t v_ = 0x72u; PUSH32(c, v_); } /* push 0x72 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(!c->zf ? 1 : 0); /* setne al */
    { uint32_t v_ = 0x55f204u; PUSH32(c, v_); } /* push 0x1001f204 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x005430eau); f_005434a0(c); /* call 0x5434a0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4cu))); /* mov eax, dword ptr [esi + 0x4c] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->eax = (uint32_t)(add32(c, c->eax, c->edi)); /* add eax, edi */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x3cu)); /* lea ecx, [eax + 0x3c] */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x20], ecx */
    c->df = 0; /* cld  */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov edi, dword ptr [esp + 0x24] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov esi, dword ptr [esp + 0x20] */
    c->ecx = (uint32_t)((uint32_t)0x10u); /* mov ecx, 0x10 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x7cu)); /* add eax, 0x7c */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x20], eax */
    c->df = 0; /* cld  */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov edi, dword ptr [esp + 0x28] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov esi, dword ptr [esp + 0x20] */
    c->ecx = (uint32_t)((uint32_t)0x10u); /* mov ecx, 0x10 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
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
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x8cu)); /* lea edx, [esp + 0x8c] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x15cu)); /* lea eax, [esp + 0x15c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x124u)); /* lea ecx, [esp + 0x124] */
    PUSH32(c, 0x00543176u); f_00543250(c); /* call 0x543250 */
    c->df = 0; /* cld  */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov edi, dword ptr [esp + 0x30] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x38u))); /* mov esi, dword ptr [esp + 0x38] */
    c->ecx = (uint32_t)((uint32_t)0x10u); /* mov ecx, 0x10 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x2d0u))); /* mov ecx, dword ptr [ebp + 0x2d0] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->edx)); /* add ecx, edx */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x20], ecx */
    c->df = 0; /* cld  */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov edi, dword ptr [esp + 0x20] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov esi, dword ptr [esp + 0x1c] */
    c->ecx = (uint32_t)((uint32_t)0x10u); /* mov ecx, 0x10 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov edi, dword ptr [esp + 0x34] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov ecx, dword ptr [esp + 0x2c] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0xbcu)); /* add edi, 0xbc */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x40u)); /* add edx, 0x40 */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x18], eax */
    W32((uint32_t)(c->esp + 0x34u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x34], edi */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x10], edx */
    if ((c->sf != c->of)) goto L_005430b4; /* jl 0x5430b4 */
L_005431d0:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1c8u)); /* add esp, 0x1c8 */
    c->esp += 4; return; /* ret  */
}

void f_005431e0(CPU *c) { /* FUN_100031e0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edi, dword ptr [esp + 0x14] */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->ebp = (uint32_t)(c->ecx); /* mov ebp, ecx */
    c->eax = (uint32_t)(shl32(c, c->eax, 5)); /* shl eax, 5 */
    c->ebx = (uint32_t)((uint32_t)(c->eax + c->ebp + 0x2d4u)); /* lea ebx, [eax + ebp + 0x2d4] */
L_005431f8:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov ecx, dword ptr [ebx] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00543212; /* je 0x543212 */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    c->eax = (uint32_t)(shl32(c, c->eax, 16)); /* shl eax, 0x10 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->esi))); /* or eax, esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov eax, dword ptr [esp + 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x00543212u); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
L_00543212:;
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x4u)); /* add ebx, 4 */
    (void)sub32(c, c->esi, (uint32_t)0x8u); /* cmp esi, 8 */
    if ((c->sf != c->of)) goto L_005431f8; /* jl 0x5431f8 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 12; return; /* ret 8 */
}

void f_00543230(CPU *c) { /* FUN_10003230 */
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

void f_00543250(CPU *c) { /* FUN_10003250 */
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

void f_00543470(CPU *c) { /* FUN_10003470 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx), (uint32_t)((uint32_t)0x55d1fcu)); /* mov dword ptr [ecx], 0x1001d1fc */
    c->esp += 4; return; /* ret  */
}

void f_00543480(CPU *c) { /* PTR_00543480 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x4u))); /* mov al, byte ptr [esp + 4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x55d1fcu)); /* mov dword ptr [esi], 0x1001d1fc */
    if (c->zf) goto L_0054349a; /* je 0x54349a */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00543497u); f_00543960(c); /* call 0x543960 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_0054349a:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_005434a0(CPU *c) { /* FUN_100034a0 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x4u))); /* mov al, byte ptr [esp + 4] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_005434e7; /* jne 0x5434e7 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    if (c->zf) goto L_005434d0; /* je 0x5434d0 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x005434cbu); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    goto L_005434e6; /* jmp 0x5434e6 */
L_005434d0:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x55f3a0u; PUSH32(c, v_); } /* push 0x1001f3a0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x005434e3u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_005434e6:;
    guest_trap(c, 0x005434e6u, "int3"); /* int3  */
L_005434e7:;
    c->esp += 4; return; /* ret  */
}

void f_005434f0(CPU *c) { /* FUN_100034f0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x55c62bu; PUSH32(c, v_); } /* push 0x1001c62b */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x10], esi */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x64u)); /* lea ecx, [esi + 0x64] */
    PUSH32(c, 0x00543518u); f_00545f40(c); /* call 0x545f40 */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov ebp, dword ptr [esp + 0x24] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0xffffffffu))); /* or ecx, 0xffffffff */
    c->edi = (uint32_t)(c->ebp); /* mov edi, ebp */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x55d238u)); /* mov dword ptr [esi], 0x1001d238 */
    while (c->ecx) { (void)sub8(c, ((uint8_t)c->eax), R8(c->edi)); c->edi += (c->df ? -1 : 1); c->ecx--; if (c->zf) break; } /* repne scasb al, byte ptr es:[edi] */
    c->ecx = (uint32_t)((uint32_t)~c->ecx); /* not ecx */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x1c], ebx */
    (void)sub32(c, c->ecx, (uint32_t)0x40u); /* cmp ecx, 0x40 */
    if (c->cf) goto L_00543559; /* jb 0x543559 */
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    { uint32_t v_ = 0x55f3f0u; PUSH32(c, v_); } /* push 0x1001f3f0 */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    { uint32_t v_ = 0x55f3bcu; PUSH32(c, v_); } /* push 0x1001f3bc */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00543555u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00543558u, "int3"); /* int3  */
L_00543559:;
    c->edx = (uint32_t)((uint32_t)(c->esi + 0x4u)); /* lea edx, [esi + 4] */
    c->eax = (uint32_t)(c->ebp); /* mov eax, ebp */
    c->edx = (uint32_t)(sub32(c, c->edx, c->ebp)); /* sub edx, ebp */
L_00543560:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    W8((uint32_t)(c->edx + c->eax), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [edx + eax], cl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub8(c, ((uint8_t)c->ecx), ((uint8_t)c->ebx)); /* cmp cl, bl */
    if (!c->zf) goto L_00543560; /* jne 0x543560 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ecx, dword ptr [esp + 0x14] */
    W32((uint32_t)(c->esi + 0x4cu), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x4c], ebx */
    W32((uint32_t)(c->esi + 0x50u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x50], ebx */
    W32((uint32_t)(c->esi + 0x54u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x54], ebx */
    W32((uint32_t)(c->esi + 0x58u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x58], ebx */
    W32((uint32_t)(c->esi + 0x5cu), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x5c], ebx */
    W32((uint32_t)(c->esi + 0x60u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x60], ebx */
    W32((uint32_t)(c->esi + 0x48u), (uint32_t)((uint32_t)0x41700000u)); /* mov dword ptr [esi + 0x48], 0x41700000 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 8; return; /* ret 4 */
}

void f_005435a0(CPU *c) { /* FUN_100035a0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x005435a8u); f_005435c0(c); /* call 0x5435c0 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_005435b8; /* je 0x5435b8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x005435b5u); f_00543960(c); /* call 0x543960 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_005435b8:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_005435c0(CPU *c) { /* FUN_100035c0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x55c64bu; PUSH32(c, v_); } /* push 0x1001c64b */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 4], esi */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x55d238u)); /* mov dword ptr [esi], 0x1001d238 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4cu))); /* mov ecx, dword ptr [esi + 0x4c] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x10], 0 */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_005435f8; /* je 0x5435f8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    { uint32_t t_ = R32((uint32_t)(c->eax)); PUSH32(c, 0x005435f8u); call_indirect(c, t_); } /* call dword ptr [eax] */
L_005435f8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x54u))); /* mov eax, dword ptr [esi + 0x54] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0054362e; /* je 0x54362e */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x58u))); /* mov eax, dword ptr [esi + 0x58] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_00543621; /* jle 0x543621 */
L_00543609:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x54u))); /* mov ecx, dword ptr [esi + 0x54] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + c->edi * 4))); /* mov ecx, dword ptr [ecx + edi*4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00543619; /* je 0x543619 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t t_ = R32((uint32_t)(c->edx)); PUSH32(c, 0x00543619u); call_indirect(c, t_); } /* call dword ptr [edx] */
L_00543619:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x58u))); /* mov eax, dword ptr [esi + 0x58] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if ((c->sf != c->of)) goto L_00543609; /* jl 0x543609 */
L_00543621:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x54u))); /* mov eax, dword ptr [esi + 0x54] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0054362au); f_00543960(c); /* call 0x543960 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_0054362e:;
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x64u)); /* lea ecx, [esi + 0x64] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [esp + 0x10], 0xffffffff */
    PUSH32(c, 0x0054363eu); f_00545f80(c); /* call 0x545f80 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_00543650(CPU *c) { /* FUN_10003650 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x55c674u; PUSH32(c, v_); } /* push 0x1001c674 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x4cu))); /* mov eax, dword ptr [ebx + 0x4c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0054367c; /* je 0x54367c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x50u))); /* mov eax, dword ptr [ebx + 0x50] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0054367c; /* je 0x54367c */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00543681; /* jmp 0x543681 */
L_0054367c:;
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
L_00543681:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(!c->zf ? 1 : 0); /* setne al */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_005436aa; /* jne 0x5436aa */
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    { uint32_t v_ = 0x55f42cu; PUSH32(c, v_); } /* push 0x1001f42c */
    { uint32_t v_ = 0x2cu; PUSH32(c, v_); } /* push 0x2c */
    { uint32_t v_ = 0x55f3bcu; PUSH32(c, v_); } /* push 0x1001f3bc */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x005436a6u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x005436a9u, "int3"); /* int3  */
L_005436aa:;
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov esi, dword ptr [esp + 0x1c] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if ((c->zf || c->sf != c->of)) goto L_005436c1; /* jle 0x5436c1 */
    (void)sub32(c, c->esi, (uint32_t)0x100u); /* cmp esi, 0x100 */
    if ((!c->zf && c->sf == c->of)) goto L_005436c1; /* jg 0x5436c1 */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    goto L_005436c3; /* jmp 0x5436c3 */
L_005436c1:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_005436c3:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(!c->zf ? 1 : 0); /* setne al */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_005436ec; /* jne 0x5436ec */
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    { uint32_t v_ = 0x55f40cu; PUSH32(c, v_); } /* push 0x1001f40c */
    { uint32_t v_ = 0x2du; PUSH32(c, v_); } /* push 0x2d */
    { uint32_t v_ = 0x55f3bcu; PUSH32(c, v_); } /* push 0x1001f3bc */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x005436e8u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x005436ebu, "int3"); /* int3  */
L_005436ec:;
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea eax, [esi + esi*2] */
    { uint32_t v_ = 0x2fu; PUSH32(c, v_); } /* push 0x2f */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    c->eax = (uint32_t)(sub32(c, c->eax, c->esi)); /* sub eax, esi */
    { uint32_t v_ = 0x55f3bcu; PUSH32(c, v_); } /* push 0x1001f3bc */
    W32((uint32_t)(c->ebx + 0x50u), (uint32_t)(c->esi)); /* mov dword ptr [ebx + 0x50], esi */
    c->ecx = (uint32_t)((uint32_t)(c->eax * 4 + 0x4u)); /* lea ecx, [eax*4 + 4] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x0054370bu); f_00543940(c); /* call 0x543940 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x1c], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x14], 0 */
    if (c->zf) goto L_00543750; /* je 0x543750 */
    { uint32_t v_ = 0x5457c0u; PUSH32(c, v_); } /* push 0x100057c0 */
    { uint32_t v_ = 0x545720u; PUSH32(c, v_); } /* push 0x10005720 */
    c->edi = (uint32_t)((uint32_t)(c->eax + 0x4u)); /* lea edi, [eax + 4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0xbcu; PUSH32(c, v_); } /* push 0xbc */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->eax), (uint32_t)(c->esi)); /* mov dword ptr [eax], esi */
    PUSH32(c, 0x00543739u); f_005467cb(c); /* call 0x5467cb */
    W32((uint32_t)(c->ebx + 0x4cu), (uint32_t)(c->edi)); /* mov dword ptr [ebx + 0x4c], edi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 8; return; /* ret 4 */
L_00543750:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    W32((uint32_t)(c->ebx + 0x4cu), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 0x4c], eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 8; return; /* ret 4 */
}

void f_00543770(CPU *c) { /* PTR_00543770 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x8u))); /* mov bl, byte ptr [esp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x2u)); /* test bl, 2 */
    if (c->zf) goto L_005437ab; /* je 0x5437ab */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xfffffffcu))); /* mov eax, dword ptr [esi - 4] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0xfffffffcu)); /* lea edi, [esi - 4] */
    { uint32_t v_ = 0x5457c0u; PUSH32(c, v_); } /* push 0x100057c0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0xbcu; PUSH32(c, v_); } /* push 0xbc */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00543795u); f_005466d7(c); /* call 0x5466d7 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x1u)); /* test bl, 1 */
    if (c->zf) goto L_005437a3; /* je 0x5437a3 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x005437a0u); f_00543960(c); /* call 0x543960 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_005437a3:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
L_005437ab:;
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x005437b2u); f_005457c0(c); /* call 0x5457c0 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x1u)); /* test bl, 1 */
    if (c->zf) goto L_005437c0; /* je 0x5437c0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x005437bdu); f_00543960(c); /* call 0x543960 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_005437c0:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
}

void f_005437d0(CPU *c) { /* FUN_100037d0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x55c694u; PUSH32(c, v_); } /* push 0x1001c694 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ebx, dword ptr [esp + 0x14] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(!c->zf ? 1 : 0); /* setne al */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    if (!c->zf) goto L_00543817; /* jne 0x543817 */
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    { uint32_t v_ = 0x55f44cu; PUSH32(c, v_); } /* push 0x1001f44c */
    { uint32_t v_ = 0x35u; PUSH32(c, v_); } /* push 0x35 */
    { uint32_t v_ = 0x55f3bcu; PUSH32(c, v_); } /* push 0x1001f3bc */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00543813u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00543816u, "int3"); /* int3  */
L_00543817:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x58u))); /* mov eax, dword ptr [esi + 0x58] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_00543838; /* jle 0x543838 */
L_00543820:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x54u))); /* mov edx, dword ptr [esi + 0x54] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + c->edi * 4))); /* mov ecx, dword ptr [edx + edi*4] */
    PUSH32(c, 0x0054382cu); f_005412d0(c); /* call 0x5412d0 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_0054388e; /* jne 0x54388e */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x58u))); /* mov eax, dword ptr [esi + 0x58] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if ((c->sf != c->of)) goto L_00543820; /* jl 0x543820 */
L_00543838:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x58u))); /* mov eax, dword ptr [esi + 0x58] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x54u))); /* mov ecx, dword ptr [esi + 0x54] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t v_ = 0x3bu; PUSH32(c, v_); } /* push 0x3b */
    W32((uint32_t)(c->esi + 0x58u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x58], eax */
    { uint32_t v_ = 0x55f3bcu; PUSH32(c, v_); } /* push 0x1001f3bc */
    c->eax = (uint32_t)(shl32(c, c->eax, 2)); /* shl eax, 2 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00543853u); f_00543980(c); /* call 0x543980 */
    { uint32_t v_ = 0x3cu; PUSH32(c, v_); } /* push 0x3c */
    { uint32_t v_ = 0x55f3bcu; PUSH32(c, v_); } /* push 0x1001f3bc */
    { uint32_t v_ = 0x2d8u; PUSH32(c, v_); } /* push 0x2d8 */
    W32((uint32_t)(c->esi + 0x54u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x54], eax */
    PUSH32(c, 0x00543867u); f_00543940(c); /* call 0x543940 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x1c], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x14], 0 */
    if (c->zf) goto L_005438a4; /* je 0x5438a4 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov edx, dword ptr [esp + 0x24] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov ecx, dword ptr [esp + 0x20] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    PUSH32(c, 0x0054388cu); f_00541000(c); /* call 0x541000 */
    goto L_005438a6; /* jmp 0x5438a6 */
L_0054388e:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 16; return; /* ret 0xc */
L_005438a4:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_005438a6:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x58u))); /* mov edx, dword ptr [esi + 0x58] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x54u))); /* mov ecx, dword ptr [esi + 0x54] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    W32((uint32_t)(c->ecx + c->edx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ecx + edx*4 - 4], eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x58u))); /* mov edx, dword ptr [esi + 0x58] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x54u))); /* mov eax, dword ptr [esi + 0x54] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->edx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [eax + edx*4 - 4] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 16; return; /* ret 0xc */
}

void f_005438d0(CPU *c) { /* FUN_100038d0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x58u))); /* mov eax, dword ptr [edi + 0x58] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_005438fa; /* jle 0x5438fa */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ebx, dword ptr [esp + 0x10] */
L_005438e2:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x54u))); /* mov eax, dword ptr [edi + 0x54] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 4))); /* mov ecx, dword ptr [eax + esi*4] */
    PUSH32(c, 0x005438eeu); f_005412d0(c); /* call 0x5412d0 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00543902; /* jne 0x543902 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x58u))); /* mov eax, dword ptr [edi + 0x58] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if ((c->sf != c->of)) goto L_005438e2; /* jl 0x5438e2 */
L_005438fa:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
L_00543902:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x54u))); /* mov ecx, dword ptr [edi + 0x54] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + c->esi * 4))); /* mov eax, dword ptr [ecx + esi*4] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
}

void f_00543910(CPU *c) { /* DMAInterface */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    W32((uint32_t)(0x564cecu), (uint32_t)(c->eax)); /* mov dword ptr [0x10024cec], eax */
    W32((uint32_t)(0x564bccu), (uint32_t)(c->eax)); /* mov dword ptr [0x10024bcc], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov eax, dword ptr [eax + 4] */
    W32((uint32_t)(0x564bc8u), (uint32_t)(c->ecx)); /* mov dword ptr [0x10024bc8], ecx */
    W32((uint32_t)(0x564bd0u), (uint32_t)(c->eax)); /* mov dword ptr [0x10024bd0], eax */
    c->eax = (uint32_t)(R32((uint32_t)(0x5650f0u))); /* mov eax, dword ptr [0x100250f0] */
    c->esp += 4; return; /* ret  */
}

void f_00543940(CPU *c) { /* FUN_10003940 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x564cecu))); /* mov ecx, dword ptr [0x10024cec] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4u)); PUSH32(c, 0x0054395au); call_indirect(c, t_); } /* call dword ptr [eax + 4] */
    c->esp += 4; return; /* ret  */
}

void f_00543960(CPU *c) { /* FUN_10003960 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(0x564cecu))); /* mov ecx, dword ptr [0x10024cec] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x00543970u); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
    c->esp += 4; return; /* ret  */
}

void f_00543980(CPU *c) { /* FUN_10003980 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x564cecu))); /* mov ecx, dword ptr [0x10024cec] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0xcu)); PUSH32(c, 0x0054399fu); call_indirect(c, t_); } /* call dword ptr [eax + 0xc] */
    c->esp += 4; return; /* ret  */
}

void f_005439a0(CPU *c) { /* PTR_005439a0 */
    PREEMPT_POLL(c);
    PUSH32(c, 0x005439a5u); f_005439b0(c); /* call 0x5439b0 */
    { f_00543ac0(c); return; } /* jmp 0x543ac0 */
}

void f_005439b0(CPU *c) { /* PTR_005439b0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x5650f0u; PUSH32(c, v_); } /* push 0x100250f0 */
    c->ecx = (uint32_t)((uint32_t)0x564bd4u); /* mov ecx, 0x10024bd4 */
    PUSH32(c, 0x005439bfu); f_005439c0(c); /* call 0x5439c0 */
    c->esp += 4; return; /* ret  */
}

void f_005439c0(CPU *c) { /* PTR_005439c0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->edx)); /* mov dword ptr [eax + 0xc], edx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 8], edx */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x55d23cu)); /* mov dword ptr [eax], 0x1001d23c */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov esi, dword ptr [ecx] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [eax + 4], esi */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    W32((uint32_t)(c->eax + 0x10u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 0x10], edx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_005439f0(CPU *c) { /* PTR_005439f0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x55f458u); /* mov eax, 0x1001f458 */
    c->esp += 4; return; /* ret  */
}

void f_00543a00(CPU *c) { /* FUN_10003a00 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x55c6b4u; PUSH32(c, v_); } /* push 0x1001c6b4 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00543a4f; /* jne 0x543a4f */
    { uint32_t v_ = 0x36u; PUSH32(c, v_); } /* push 0x36 */
    { uint32_t v_ = 0x55f46cu; PUSH32(c, v_); } /* push 0x1001f46c */
    { uint32_t v_ = 0x14u; PUSH32(c, v_); } /* push 0x14 */
    PUSH32(c, 0x00543a2eu); f_00543940(c); /* call 0x543940 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 4], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x10], 0 */
    if (c->zf) goto L_00543a4a; /* je 0x543a4a */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    PUSH32(c, 0x00543a48u); f_00543ae0(c); /* call 0x543ae0 */
    goto L_00543a4c; /* jmp 0x543a4c */
L_00543a4a:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00543a4c:;
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x10], eax */
L_00543a4f:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xc], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_00543a70(CPU *c) { /* FUN_10003a70 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0xc], edi */
    (void)sub32(c, c->ecx, c->edi); /* cmp ecx, edi */
    if (c->zf) goto L_00543a86; /* je 0x543a86 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t t_ = R32((uint32_t)(c->eax)); PUSH32(c, 0x00543a86u); call_indirect(c, t_); } /* call dword ptr [eax] */
L_00543a86:;
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0x10], edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00543a90(CPU *c) { /* FUN_10003a90 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00543a98u); f_00543ab0(c); /* call 0x543ab0 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00543aa8; /* je 0x543aa8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00543aa5u); f_00543960(c); /* call 0x543960 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00543aa8:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00543ab0(CPU *c) { /* FUN_10003ab0 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx), (uint32_t)((uint32_t)0x55d25cu)); /* mov dword ptr [ecx], 0x1001d25c */
    c->esp += 4; return; /* ret  */
}

void f_00543ac0(CPU *c) { /* PTR_00543ac0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x543ad0u; PUSH32(c, v_); } /* push 0x10003ad0 */
    PUSH32(c, 0x00543acau); f_005468cb(c); /* call 0x5468cb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00543ad0(CPU *c) { /* PTR_00543ad0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)0x564bd4u); /* mov ecx, 0x10024bd4 */
    { f_00543ab0(c); return; } /* jmp 0x543ab0 */
}

void f_00543ae0(CPU *c) { /* FUN_10003ae0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x55c6c8u; PUSH32(c, v_); } /* push 0x1001c6c8 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 4], esi */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x55d27cu)); /* mov dword ptr [esi], 0x1001d27c */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 4], eax */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 8], eax */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xc], eax */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x10], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(0x564bc0u))); /* mov ecx, dword ptr [0x10024bc0] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
    if (c->zf) goto L_00543b42; /* je 0x543b42 */
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    { uint32_t v_ = 0x55f4d4u; PUSH32(c, v_); } /* push 0x1001f4d4 */
    { uint32_t v_ = 0x96u; PUSH32(c, v_); } /* push 0x96 */
    { uint32_t v_ = 0x55f4a4u; PUSH32(c, v_); } /* push 0x1001f4a4 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00543b3eu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00543b41u, "int3"); /* int3  */
L_00543b42:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    W32((uint32_t)(0x564bc0u), (uint32_t)(c->esi)); /* mov dword ptr [0x10024bc0], esi */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_00543b60(CPU *c) { /* FUN_10003b60 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00543b68u); f_00543b80(c); /* call 0x543b80 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00543b78; /* je 0x543b78 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00543b75u); f_00543960(c); /* call 0x543960 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00543b78:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00543b80(CPU *c) { /* FUN_10003b80 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x55c6e8u; PUSH32(c, v_); } /* push 0x1001c6e8 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 8], esi */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x55d27cu)); /* mov dword ptr [esi], 0x1001d27c */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x14], 0 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00543c08; /* je 0x543c08 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_00543bfc; /* jle 0x543bfc */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
L_00543bbd:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->edi * 4))); /* mov eax, dword ptr [eax + edi*4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00543bf3; /* je 0x543bf3 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ebx, dword ptr [eax + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x564cecu))); /* mov ecx, dword ptr [0x10024cec] */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x4u)); /* add ebx, 4 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x55f4e8u; PUSH32(c, v_); } /* push 0x1001f4e8 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x30u)); PUSH32(c, 0x00543be0u); call_indirect(c, t_); } /* call dword ptr [edx + 0x30] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + c->edi * 4))); /* mov ecx, dword ptr [eax + edi*4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00543bf3; /* je 0x543bf3 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t t_ = R32((uint32_t)(c->edx)); PUSH32(c, 0x00543bf3u); call_indirect(c, t_); } /* call dword ptr [edx] */
L_00543bf3:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if ((c->sf != c->of)) goto L_00543bbd; /* jl 0x543bbd */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
L_00543bfc:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00543c05u); f_00543960(c); /* call 0x543960 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00543c08:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00543c3c; /* je 0x543c3c */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_00543c30; /* jle 0x543c30 */
L_00543c18:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + c->edi * 4))); /* mov ecx, dword ptr [ecx + edi*4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00543c28; /* je 0x543c28 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t t_ = R32((uint32_t)(c->edx)); PUSH32(c, 0x00543c28u); call_indirect(c, t_); } /* call dword ptr [edx] */
L_00543c28:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if ((c->sf != c->of)) goto L_00543c18; /* jl 0x543c18 */
L_00543c30:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00543c39u); f_00543960(c); /* call 0x543960 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00543c3c:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x55d29cu)); /* mov dword ptr [esi], 0x1001d29c */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_00543c60(CPU *c) { /* PTR_00543c60 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x2u); /* mov eax, 2 */
    c->esp += 4; return; /* ret  */
}

void f_00543c70(CPU *c) { /* PTR_00543c70 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(0x564cecu))); /* mov ecx, dword ptr [0x10024cec] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0xe4u)); PUSH32(c, 0x00543c85u); call_indirect(c, t_); } /* call dword ptr [eax + 0xe4] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    (void)sub32(c, c->ecx, (uint32_t)0x3e8u); /* cmp ecx, 0x3e8 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x10], ecx */
    if ((c->cf || c->zf)) goto L_00543c9f; /* jbe 0x543c9f */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0x3e8u)); /* mov dword ptr [esp + 0x10], 0x3e8 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
L_00543c9f:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov eax, dword ptr [ebx + 8] */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_00543d06; /* jle 0x543d06 */
    c->edi = (uint32_t)((uint32_t)0x1u); /* mov edi, 1 */
L_00543cad:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov edx, dword ptr [ebx + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + c->esi * 4))); /* mov eax, dword ptr [edx + esi*4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00543cfe; /* je 0x543cfe */
    c->ebp = (uint32_t)(logic32(c, 0)); /* xor ebp, ebp */
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x5cu)), c->ebp); /* cmp dword ptr [eax + 0x5c], ebp */
    if (!c->zf) goto L_00543ccf; /* jne 0x543ccf */
    (void)sub32(c, c->ecx, (uint32_t)0xau); /* cmp ecx, 0xa */
    if ((!c->zf && c->sf == c->of)) goto L_00543cca; /* jg 0x543cca */
    c->edx = (uint32_t)((uint32_t)0xau); /* mov edx, 0xa */
L_00543cca:;
    { uint32_t a_ = (uint32_t)(c->eax + 0x60u); W32(a_, (uint32_t)(add32(c, R32(a_), c->edx))); } /* add dword ptr [eax + 0x60], edx */
    goto L_00543cd2; /* jmp 0x543cd2 */
L_00543ccf:;
    W32((uint32_t)(c->eax + 0x60u), (uint32_t)(c->ebp)); /* mov dword ptr [eax + 0x60], ebp */
L_00543cd2:;
    (void)sub32(c, R32((uint32_t)(c->eax + 0x60u)), c->ebp); /* cmp dword ptr [eax + 0x60], ebp */
    if ((c->sf == c->of)) goto L_00543cda; /* jge 0x543cda */
    W32((uint32_t)(c->eax + 0x60u), (uint32_t)(c->ebp)); /* mov dword ptr [eax + 0x60], ebp */
L_00543cda:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov eax, dword ptr [ebx + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 4))); /* mov eax, dword ptr [eax + esi*4] */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x60u)), c->edi); /* cmp dword ptr [eax + 0x60], edi */
    if ((c->sf != c->of)) goto L_00543cfe; /* jl 0x543cfe */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00543cf4; /* je 0x543cf4 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx)); PUSH32(c, 0x00543cf0u); call_indirect(c, t_); } /* call dword ptr [edx] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
L_00543cf4:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov eax, dword ptr [ebx + 4] */
    W32((uint32_t)(c->eax + c->esi * 4), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [eax + esi*4], 0 */
L_00543cfe:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov eax, dword ptr [ebx + 8] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if ((c->sf != c->of)) goto L_00543cad; /* jl 0x543cad */
L_00543d06:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x10u))); /* mov eax, dword ptr [ebx + 0x10] */
    c->ebp = (uint32_t)(logic32(c, 0)); /* xor ebp, ebp */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_00543d69; /* jle 0x543d69 */
L_00543d0f:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0xcu))); /* mov edx, dword ptr [ebx + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->edx + c->ebp * 4)), (uint32_t)0x0u); /* cmp dword ptr [edx + ebp*4], 0 */
    if (c->zf) goto L_00543d61; /* je 0x543d61 */
    (void)sub32(c, c->ecx, (uint32_t)0x32u); /* cmp ecx, 0x32 */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    if ((c->zf || c->sf != c->of)) goto L_00543d4d; /* jle 0x543d4d */
    c->edx = (uint32_t)((uint32_t)(c->ecx + 0xffffffcdu)); /* lea edx, [ecx - 0x33] */
    c->eax = (uint32_t)((uint32_t)0x51eb851fu); /* mov eax, 0x51eb851f */
    { uint64_t r_ = (uint64_t)c->eax * c->edx; c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = c->edx != 0; } /* mul edx */
    c->esi = (uint32_t)(c->edx); /* mov esi, edx */
    c->esi = (uint32_t)(shr32(c, c->esi, 4)); /* shr esi, 4 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi * 4)); /* lea eax, [esi + esi*4] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea eax, [eax + eax*4] */
    c->eax = (uint32_t)(add32(c, c->eax, c->eax)); /* add eax, eax */
    c->edi = (uint32_t)(sub32(c, c->edi, c->eax)); /* sub edi, eax */
L_00543d39:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0xcu))); /* mov ecx, dword ptr [ebx + 0xc] */
    { uint32_t v_ = 0x32u; PUSH32(c, v_); } /* push 0x32 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + c->ebp * 4))); /* mov ecx, dword ptr [ecx + ebp*4] */
    PUSH32(c, 0x00543d46u); f_00542390(c); /* call 0x542390 */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    if (!c->zf) goto L_00543d39; /* jne 0x543d39 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
L_00543d4d:;
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if ((c->zf || c->sf != c->of)) goto L_00543d61; /* jle 0x543d61 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0xcu))); /* mov edx, dword ptr [ebx + 0xc] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + c->ebp * 4))); /* mov ecx, dword ptr [edx + ebp*4] */
    PUSH32(c, 0x00543d5du); f_00542390(c); /* call 0x542390 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
L_00543d61:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x10u))); /* mov eax, dword ptr [ebx + 0x10] */
    c->ebp = (uint32_t)(inc32(c, c->ebp)); /* inc ebp */
    (void)sub32(c, c->ebp, c->eax); /* cmp ebp, eax */
    if ((c->sf != c->of)) goto L_00543d0f; /* jl 0x543d0f */
L_00543d69:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00543d70(CPU *c) { /* PTR_00543d70 */
    PREEMPT_POLL(c);
    c->esp += 4; return; /* ret  */
}

void f_00543d80(CPU *c) { /* PTR_00543d80 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x55c717u; PUSH32(c, v_); } /* push 0x1001c717 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ebx, dword ptr [esp + 0x14] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_00543dc3; /* jle 0x543dc3 */
L_00543da7:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + c->edi * 4))); /* mov ecx, dword ptr [eax + edi*4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00543dbb; /* je 0x543dbb */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00543db7u); f_005412d0(c); /* call 0x5412d0 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00543dc3; /* jne 0x543dc3 */
L_00543dbb:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if ((c->sf != c->of)) goto L_00543da7; /* jl 0x543da7 */
L_00543dc3:;
    (void)sub32(c, c->edi, R32((uint32_t)(c->esi + 0x8u))); /* cmp edi, dword ptr [esi + 8] */
    if (!c->zf) goto L_00543dec; /* jne 0x543dec */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00543dd0u); f_00543f60(c); /* call 0x543f60 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if ((c->sf == c->of)) goto L_00543dec; /* jge 0x543dec */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 8; return; /* ret 4 */
L_00543dec:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    c->ebx = (uint32_t)(c->edi); /* mov ebx, edi */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_00543e07; /* jle 0x543e07 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov ecx, dword ptr [esi + 0xc] */
L_00543dfa:;
    (void)sub32(c, R32((uint32_t)(c->ecx)), (uint32_t)0x0u); /* cmp dword ptr [ecx], 0 */
    if (c->zf) goto L_00543e07; /* je 0x543e07 */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if ((c->sf != c->of)) goto L_00543dfa; /* jl 0x543dfa */
L_00543e07:;
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (!c->zf) goto L_00543e4e; /* jne 0x543e4e */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov edx, dword ptr [esi + 0xc] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x40u)); /* add eax, 0x40 */
    { uint32_t v_ = 0x9fu; PUSH32(c, v_); } /* push 0x9f */
    { uint32_t v_ = 0x55f46cu; PUSH32(c, v_); } /* push 0x1001f46c */
    c->ecx = (uint32_t)((uint32_t)(c->eax * 4)); /* lea ecx, [eax*4] */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x10], eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00543e2cu); f_00543980(c); /* call 0x543980 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xc], eax */
    (void)sub32(c, c->edi, c->ecx); /* cmp edi, ecx */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    if ((c->sf == c->of)) goto L_00543e4e; /* jge 0x543e4e */
L_00543e3b:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov ecx, dword ptr [esi + 0xc] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    W32((uint32_t)(c->ecx + c->eax * 4 + 0xfffffffcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ecx + eax*4 - 4], 0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if ((c->sf != c->of)) goto L_00543e3b; /* jl 0x543e3b */
L_00543e4e:;
    { uint32_t v_ = 0xa2u; PUSH32(c, v_); } /* push 0xa2 */
    { uint32_t v_ = 0x55f46cu; PUSH32(c, v_); } /* push 0x1001f46c */
    { uint32_t v_ = 0x3f8u; PUSH32(c, v_); } /* push 0x3f8 */
    PUSH32(c, 0x00543e62u); f_00543940(c); /* call 0x543940 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x1c], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x14], 0 */
    if (c->zf) goto L_00543e86; /* je 0x543e86 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov edx, dword ptr [esi + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + c->ebx * 4))); /* mov ecx, dword ptr [edx + ebx*4] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    PUSH32(c, 0x00543e84u); f_00541db0(c); /* call 0x541db0 */
    goto L_00543e88; /* jmp 0x543e88 */
L_00543e86:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00543e88:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov edx, dword ptr [esi + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    W32((uint32_t)(c->edx + c->edi * 4), (uint32_t)(c->eax)); /* mov dword ptr [edx + edi*4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->edi * 4))); /* mov eax, dword ptr [eax + edi*4] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 8; return; /* ret 4 */
}

void f_00543eb0(CPU *c) { /* FUN_10003eb0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_00543edf; /* jne 0x543edf */
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    { uint32_t v_ = 0x55f574u; PUSH32(c, v_); } /* push 0x1001f574 */
    { uint32_t v_ = 0xa9u; PUSH32(c, v_); } /* push 0xa9 */
    { uint32_t v_ = 0x55f46cu; PUSH32(c, v_); } /* push 0x1001f46c */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00543edbu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00543edeu, "int3"); /* int3  */
L_00543edf:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf == c->of)) goto L_00543f0e; /* jge 0x543f0e */
    (void)sub32(c, c->eax, R32((uint32_t)(c->edi + 0x10u))); /* cmp eax, dword ptr [edi + 0x10] */
    if ((c->sf != c->of)) goto L_00543f0e; /* jl 0x543f0e */
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    { uint32_t v_ = 0x55f538u; PUSH32(c, v_); } /* push 0x1001f538 */
    { uint32_t v_ = 0xaau; PUSH32(c, v_); } /* push 0xaa */
    { uint32_t v_ = 0x55f46cu; PUSH32(c, v_); } /* push 0x1001f46c */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00543f0au); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00543f0du, "int3"); /* int3  */
L_00543f0e:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0xcu))); /* mov ecx, dword ptr [edi + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->ecx + c->eax * 4)), c->esi); /* cmp dword ptr [ecx + eax*4], esi */
    if (c->zf) goto L_00543f3c; /* je 0x543f3c */
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    { uint32_t v_ = 0x55f514u; PUSH32(c, v_); } /* push 0x1001f514 */
    { uint32_t v_ = 0xabu; PUSH32(c, v_); } /* push 0xab */
    { uint32_t v_ = 0x55f46cu; PUSH32(c, v_); } /* push 0x1001f46c */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00543f38u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00543f3bu, "int3"); /* int3  */
L_00543f3c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0xcu))); /* mov ecx, dword ptr [edi + 0xc] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->ecx + c->eax * 4), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ecx + eax*4], 0 */
    c->esp += 8; return; /* ret 4 */
}

void f_00543f50(CPU *c) { /* PTR_00543f50 */
    PREEMPT_POLL(c);
    c->esp += 4; return; /* ret  */
}

void f_00543f60(CPU *c) { /* FUN_10003f60 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x55c747u; PUSH32(c, v_); } /* push 0x1001c747 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x10], ecx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00543f7e:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x55fa6cu))); /* mov cl, byte ptr [eax + 0x1001fa6c] */
    W8((uint32_t)(c->eax + 0x564be8u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax + 0x10024be8], cl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_00543f7e; /* jne 0x543f7e */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov ebp, dword ptr [esp + 0x30] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ebp); /* mov edi, ebp */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0xffffffffu))); /* or ecx, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    while (c->ecx) { (void)sub8(c, ((uint8_t)c->eax), R8(c->edi)); c->edi += (c->df ? -1 : 1); c->ecx--; if (c->zf) break; } /* repne scasb al, byte ptr es:[edi] */
    c->ecx = (uint32_t)((uint32_t)~c->ecx); /* not ecx */
    c->edi = (uint32_t)(sub32(c, c->edi, c->ecx)); /* sub edi, ecx */
    { uint32_t v_ = 0x564be8u; PUSH32(c, v_); } /* push 0x10024be8 */
    c->esi = (uint32_t)(c->edi); /* mov esi, edi */
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    c->edi = (uint32_t)((uint32_t)0x564be8u); /* mov edi, 0x10024be8 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0xffffffffu))); /* or ecx, 0xffffffff */
    while (c->ecx) { (void)sub8(c, ((uint8_t)c->eax), R8(c->edi)); c->edi += (c->df ? -1 : 1); c->ecx--; if (c->zf) break; } /* repne scasb al, byte ptr es:[edi] */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->edx = (uint32_t)(R32((uint32_t)(0x564cecu))); /* mov edx, dword ptr [0x10024cec] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u))); /* and ecx, 3 */
    while (c->ecx) { W8(c->edi, R8(c->esi)); c->esi += (c->df ? -1 : 1); c->edi += (c->df ? -1 : 1); c->ecx--; } /* rep movsb byte ptr es:[edi], byte ptr [esi] */
    c->edi = (uint32_t)((uint32_t)0x564be8u); /* mov edi, 0x10024be8 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0xffffffffu))); /* or ecx, 0xffffffff */
    while (c->ecx) { (void)sub8(c, ((uint8_t)c->eax), R8(c->edi)); c->edi += (c->df ? -1 : 1); c->ecx--; if (c->zf) break; } /* repne scasb al, byte ptr es:[edi] */
    c->eax = (uint32_t)(R32((uint32_t)(0x55fa64u))); /* mov eax, dword ptr [0x1001fa64] */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x55fa68u))); /* mov cl, byte ptr [0x1001fa68] */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    W8((uint32_t)(c->edi + 0x4u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [edi + 4], cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov ecx, dword ptr [edx + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x58u)); PUSH32(c, 0x00543fefu); call_indirect(c, t_); } /* call dword ptr [eax + 0x58] */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x18], ebx */
    if (!c->zf) goto L_00544019; /* jne 0x544019 */
    c->eax = (uint32_t)(R32((uint32_t)(0x564cecu))); /* mov eax, dword ptr [0x10024cec] */
    { uint32_t v_ = 0x564be8u; PUSH32(c, v_); } /* push 0x10024be8 */
    { uint32_t v_ = 0x55fa44u; PUSH32(c, v_); } /* push 0x1001fa44 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x0054400eu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    goto L_005447b5; /* jmp 0x5447b5 */
L_00544019:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_0054401b:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x55fa6cu))); /* mov cl, byte ptr [eax + 0x1001fa6c] */
    W8((uint32_t)(c->eax + 0x564be8u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax + 0x10024be8], cl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_0054401b; /* jne 0x54401b */
    c->edi = (uint32_t)((uint32_t)0x564be8u); /* mov edi, 0x10024be8 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0xffffffffu))); /* or ecx, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov edx, dword ptr [ebx] */
    while (c->ecx) { (void)sub8(c, ((uint8_t)c->eax), R8(c->edi)); c->edi += (c->df ? -1 : 1); c->ecx--; if (c->zf) break; } /* repne scasb al, byte ptr es:[edi] */
    c->ecx = (uint32_t)((uint32_t)~c->ecx); /* not ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    c->eax = (uint32_t)((uint32_t)0x103u); /* mov eax, 0x103 */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + 0x564be8u)); /* lea ecx, [ecx + 0x10024be8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x55fa38u; PUSH32(c, v_); } /* push 0x1001fa38 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00544059u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00544086; /* jne 0x544086 */
    c->eax = (uint32_t)(R32((uint32_t)(0x564cecu))); /* mov eax, dword ptr [0x10024cec] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = 0x55fa38u; PUSH32(c, v_); } /* push 0x1001fa38 */
    { uint32_t v_ = 0x55fa0cu; PUSH32(c, v_); } /* push 0x1001fa0c */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x30u)); PUSH32(c, 0x00544073u); call_indirect(c, t_); } /* call dword ptr [edx + 0x30] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t t_ = R32((uint32_t)(c->eax)); PUSH32(c, 0x0054407eu); call_indirect(c, t_); } /* call dword ptr [eax] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    goto L_005447b5; /* jmp 0x5447b5 */
L_00544086:;
    { uint32_t v_ = 0xcfu; PUSH32(c, v_); } /* push 0xcf */
    { uint32_t v_ = 0x55f46cu; PUSH32(c, v_); } /* push 0x1001f46c */
    { uint32_t v_ = 0x80u; PUSH32(c, v_); } /* push 0x80 */
    PUSH32(c, 0x0054409au); f_00543940(c); /* call 0x543940 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->esp + 0x38u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x38], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esp + 0x30u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x30], 0 */
    if (c->zf) goto L_005440b7; /* je 0x5440b7 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    PUSH32(c, 0x005440b5u); f_005434f0(c); /* call 0x5434f0 */
    goto L_005440b9; /* jmp 0x5440b9 */
L_005440b7:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_005440b9:;
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov edi, dword ptr [esp + 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x564be8u; PUSH32(c, v_); } /* push 0x10024be8 */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x18], eax */
    W32((uint32_t)(c->esp + 0x38u), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [esp + 0x38], 0xffffffff */
    PUSH32(c, 0x005440d6u); f_00544a40(c); /* call 0x544a40 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00544110; /* jne 0x544110 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov edx, dword ptr [ebx] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    { uint32_t t_ = R32((uint32_t)(c->edx)); PUSH32(c, 0x005440e2u); call_indirect(c, t_); } /* call dword ptr [edx] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_005440f0; /* je 0x5440f0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t t_ = R32((uint32_t)(c->eax)); PUSH32(c, 0x005440f0u); call_indirect(c, t_); } /* call dword ptr [eax] */
L_005440f0:;
    c->eax = (uint32_t)(R32((uint32_t)(0x564cecu))); /* mov eax, dword ptr [0x10024cec] */
    { uint32_t v_ = 0x564be8u; PUSH32(c, v_); } /* push 0x10024be8 */
    { uint32_t v_ = 0x55f9ecu; PUSH32(c, v_); } /* push 0x1001f9ec */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x00544105u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    goto L_005447b5; /* jmp 0x5447b5 */
L_00544110:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x64u)); /* add edx, 0x64 */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00544123u); f_00544810(c); /* call 0x544810 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { uint32_t v_ = 0x564be8u; PUSH32(c, v_); } /* push 0x10024be8 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x58u)); PUSH32(c, 0x00544131u); call_indirect(c, t_); } /* call dword ptr [eax + 0x58] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00544741; /* je 0x544741 */
L_00544139:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x564be8u))); /* mov al, byte ptr [0x10024be8] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00544712; /* je 0x544712 */
    c->edi = (uint32_t)((uint32_t)0x564be8u); /* mov edi, 0x10024be8 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0xffffffffu))); /* or ecx, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    while (c->ecx) { (void)sub8(c, ((uint8_t)c->eax), R8(c->edi)); c->edi += (c->df ? -1 : 1); c->ecx--; if (c->zf) break; } /* repne scasb al, byte ptr es:[edi] */
    c->ecx = (uint32_t)((uint32_t)~c->ecx); /* not ecx */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    (void)sub32(c, c->ecx, (uint32_t)0x40u); /* cmp ecx, 0x40 */
    if (!c->cf) goto L_00544712; /* jae 0x544712 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov edx, dword ptr [ebx] */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x55f9e0u; PUSH32(c, v_); } /* push 0x1001f9e0 */
    { uint32_t v_ = 0x564be8u; PUSH32(c, v_); } /* push 0x10024be8 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x20u)); PUSH32(c, 0x00544171u); call_indirect(c, t_); } /* call dword ptr [edx + 0x20] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x1c], edi */
    if ((c->sf == c->of)) goto L_0054419e; /* jge 0x54419e */
    c->eax = (uint32_t)(R32((uint32_t)(0x564cecu))); /* mov eax, dword ptr [0x10024cec] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = 0x564be8u; PUSH32(c, v_); } /* push 0x10024be8 */
    { uint32_t v_ = 0x55f9e0u; PUSH32(c, v_); } /* push 0x1001f9e0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x55f9a8u; PUSH32(c, v_); } /* push 0x1001f9a8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x00544196u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    goto L_0054472b; /* jmp 0x54472b */
L_0054419e:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov edx, dword ptr [ebx] */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x55f99cu; PUSH32(c, v_); } /* push 0x1001f99c */
    { uint32_t v_ = 0x564be8u; PUSH32(c, v_); } /* push 0x10024be8 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x20u)); PUSH32(c, 0x005441b1u); call_indirect(c, t_); } /* call dword ptr [edx + 0x20] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x24], eax */
    if ((c->sf == c->of)) goto L_005441dc; /* jge 0x5441dc */
    c->eax = (uint32_t)(R32((uint32_t)(0x564cecu))); /* mov eax, dword ptr [0x10024cec] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = 0x564be8u; PUSH32(c, v_); } /* push 0x10024be8 */
    { uint32_t v_ = 0x55f99cu; PUSH32(c, v_); } /* push 0x1001f99c */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x55f9a8u; PUSH32(c, v_); } /* push 0x1001f9a8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x005441d4u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    goto L_0054472b; /* jmp 0x54472b */
L_005441dc:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x564be8u; PUSH32(c, v_); } /* push 0x10024be8 */
    PUSH32(c, 0x005441ecu); f_005437d0(c); /* call 0x5437d0 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x14], edi */
    if (!c->zf) goto L_00544206; /* jne 0x544206 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = 0x564be8u; PUSH32(c, v_); } /* push 0x10024be8 */
    { uint32_t v_ = 0x55f958u; PUSH32(c, v_); } /* push 0x1001f958 */
    goto L_0054471d; /* jmp 0x54471d */
L_00544206:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    { uint32_t v_ = 0x3f800000u; PUSH32(c, v_); } /* push 0x3f800000 */
    { uint32_t v_ = 0x55f950u; PUSH32(c, v_); } /* push 0x1001f950 */
    { uint32_t v_ = 0x564be8u; PUSH32(c, v_); } /* push 0x10024be8 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x38u)); PUSH32(c, 0x0054421cu); call_indirect(c, t_); } /* call dword ptr [eax + 0x38] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x55d108u))); /* fcom dword ptr [0x1001d108] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00544233; /* jp 0x544233 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, (double)RF32((uint32_t)(0x55d108u))); /* fld dword ptr [0x1001d108] */
    goto L_0054424a; /* jmp 0x54424a */
L_00544233:;
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x55d1bcu))); /* fcom dword ptr [0x1001d1bc] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_0054424a; /* jne 0x54424a */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, (double)RF32((uint32_t)(0x55d1bcu))); /* fld dword ptr [0x1001d1bc] */
L_0054424a:;
    WF32((uint32_t)(c->edi + 0x4cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + 0x4c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov edx, dword ptr [ebx] */
    { uint32_t v_ = 0x55f948u; PUSH32(c, v_); } /* push 0x1001f948 */
    { uint32_t v_ = 0x100u; PUSH32(c, v_); } /* push 0x100 */
    { uint32_t v_ = 0x564cf0u; PUSH32(c, v_); } /* push 0x10024cf0 */
    { uint32_t v_ = 0x55f940u; PUSH32(c, v_); } /* push 0x1001f940 */
    { uint32_t v_ = 0x564be8u; PUSH32(c, v_); } /* push 0x10024be8 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    c->esi = (uint32_t)((uint32_t)0x1u); /* mov esi, 1 */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00544272u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00544311; /* je 0x544311 */
    { uint32_t v_ = 0x55f948u; PUSH32(c, v_); } /* push 0x1001f948 */
    { uint32_t v_ = 0x564cf0u; PUSH32(c, v_); } /* push 0x10024cf0 */
    PUSH32(c, 0x00544289u); f_0054dbf0(c); /* call 0x54dbf0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00544292; /* jne 0x544292 */
    goto L_00544311; /* jmp 0x544311 */
L_00544292:;
    { uint32_t v_ = 0x55f938u; PUSH32(c, v_); } /* push 0x1001f938 */
    { uint32_t v_ = 0x564cf0u; PUSH32(c, v_); } /* push 0x10024cf0 */
    PUSH32(c, 0x005442a1u); f_0054dbf0(c); /* call 0x54dbf0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_005442af; /* jne 0x5442af */
    c->esi = (uint32_t)((uint32_t)0x2u); /* mov esi, 2 */
    goto L_00544311; /* jmp 0x544311 */
L_005442af:;
    { uint32_t v_ = 0x55f92cu; PUSH32(c, v_); } /* push 0x1001f92c */
    { uint32_t v_ = 0x564cf0u; PUSH32(c, v_); } /* push 0x10024cf0 */
    PUSH32(c, 0x005442beu); f_0054dbf0(c); /* call 0x54dbf0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_005442cc; /* jne 0x5442cc */
    c->esi = (uint32_t)((uint32_t)0x3u); /* mov esi, 3 */
    goto L_00544311; /* jmp 0x544311 */
L_005442cc:;
    { uint32_t v_ = 0x55f920u; PUSH32(c, v_); } /* push 0x1001f920 */
    { uint32_t v_ = 0x564cf0u; PUSH32(c, v_); } /* push 0x10024cf0 */
    PUSH32(c, 0x005442dbu); f_0054dbf0(c); /* call 0x54dbf0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_005442e9; /* jne 0x5442e9 */
    c->esi = (uint32_t)((uint32_t)0x4u); /* mov esi, 4 */
    goto L_00544311; /* jmp 0x544311 */
L_005442e9:;
    c->eax = (uint32_t)(R32((uint32_t)(0x564cecu))); /* mov eax, dword ptr [0x10024cec] */
    { uint32_t v_ = 0x55f948u; PUSH32(c, v_); } /* push 0x1001f948 */
    { uint32_t v_ = 0x564cf0u; PUSH32(c, v_); } /* push 0x10024cf0 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x564be8u; PUSH32(c, v_); } /* push 0x10024be8 */
    { uint32_t v_ = 0x55f940u; PUSH32(c, v_); } /* push 0x1001f940 */
    { uint32_t v_ = 0x55f8d0u; PUSH32(c, v_); } /* push 0x1001f8d0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x0054430eu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
L_00544311:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edx, dword ptr [esp + 0x14] */
    { uint32_t v_ = 0x55f10cu; PUSH32(c, v_); } /* push 0x1001f10c */
    { uint32_t v_ = 0x100u; PUSH32(c, v_); } /* push 0x100 */
    { uint32_t v_ = 0x564cf0u; PUSH32(c, v_); } /* push 0x10024cf0 */
    W32((uint32_t)(c->edx + 0x50u), (uint32_t)(c->esi)); /* mov dword ptr [edx + 0x50], esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov esi, dword ptr [esp + 0x24] */
    { uint32_t v_ = 0x55f8c4u; PUSH32(c, v_); } /* push 0x1001f8c4 */
    { uint32_t v_ = 0x564be8u; PUSH32(c, v_); } /* push 0x10024be8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov bl, 1 */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x0054433eu); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_0054439c; /* je 0x54439c */
    { uint32_t v_ = 0x55f8bcu; PUSH32(c, v_); } /* push 0x1001f8bc */
    { uint32_t v_ = 0x564cf0u; PUSH32(c, v_); } /* push 0x10024cf0 */
    PUSH32(c, 0x00544351u); f_0054dbf0(c); /* call 0x54dbf0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_0054435a; /* jne 0x54435a */
    goto L_0054439c; /* jmp 0x54439c */
L_0054435a:;
    { uint32_t v_ = 0x55f10cu; PUSH32(c, v_); } /* push 0x1001f10c */
    { uint32_t v_ = 0x564cf0u; PUSH32(c, v_); } /* push 0x10024cf0 */
    PUSH32(c, 0x00544369u); f_0054dbf0(c); /* call 0x54dbf0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00544374; /* jne 0x544374 */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor bl, bl */
    goto L_0054439c; /* jmp 0x54439c */
L_00544374:;
    c->eax = (uint32_t)(R32((uint32_t)(0x564cecu))); /* mov eax, dword ptr [0x10024cec] */
    { uint32_t v_ = 0x55f10cu; PUSH32(c, v_); } /* push 0x1001f10c */
    { uint32_t v_ = 0x564cf0u; PUSH32(c, v_); } /* push 0x10024cf0 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x564be8u; PUSH32(c, v_); } /* push 0x10024be8 */
    { uint32_t v_ = 0x55f8c4u; PUSH32(c, v_); } /* push 0x1001f8c4 */
    { uint32_t v_ = 0x55f858u; PUSH32(c, v_); } /* push 0x1001f858 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x00544399u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
L_0054439c:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edx, dword ptr [esp + 0x14] */
    { uint32_t v_ = 0x5650f4u; PUSH32(c, v_); } /* push 0x100250f4 */
    { uint32_t v_ = 0x100u; PUSH32(c, v_); } /* push 0x100 */
    { uint32_t v_ = 0x564cf0u; PUSH32(c, v_); } /* push 0x10024cf0 */
    W8((uint32_t)(c->edx + 0x54u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [edx + 0x54], bl */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t v_ = 0x55f84cu; PUSH32(c, v_); } /* push 0x1001f84c */
    { uint32_t v_ = 0x564be8u; PUSH32(c, v_); } /* push 0x10024be8 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x005443c3u); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_005446ee; /* je 0x5446ee */
L_005443cb:;
    c->ecx = (uint32_t)((uint32_t)0x40u); /* mov ecx, 0x40 */
    c->esi = (uint32_t)((uint32_t)0x564cf0u); /* mov esi, 0x10024cf0 */
    c->edi = (uint32_t)((uint32_t)0x564df1u); /* mov edi, 0x10024df1 */
    W8((uint32_t)(0x564df0u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [0x10024df0], 0 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    W8(c->edi, R8(c->esi)); c->esi += (c->df ? -1 : 1); c->edi += (c->df ? -1 : 1); /* movsb byte ptr es:[edi], byte ptr [esi] */
    (void)sub8(c, R8((uint32_t)(0x564cf0u)), (uint8_t)0x22u); /* cmp byte ptr [0x10024cf0], 0x22 */
    if (c->zf) goto L_00544407; /* je 0x544407 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = 0x564be8u; PUSH32(c, v_); } /* push 0x10024be8 */
    { uint32_t v_ = 0x564df1u; PUSH32(c, v_); } /* push 0x10024df1 */
    { uint32_t v_ = 0x55f84cu; PUSH32(c, v_); } /* push 0x1001f84c */
    { uint32_t v_ = 0x55f7f8u; PUSH32(c, v_); } /* push 0x1001f7f8 */
    goto L_005446bb; /* jmp 0x5446bb */
L_00544407:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x564cf1u))); /* mov al, byte ptr [0x10024cf1] */
    c->esi = (uint32_t)((uint32_t)0x1u); /* mov esi, 1 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00544424; /* je 0x544424 */
L_00544415:;
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x22u); /* cmp al, 0x22 */
    if (c->zf) goto L_00544424; /* je 0x544424 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x564cf1u))); /* mov al, byte ptr [esi + 0x10024cf1] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00544415; /* jne 0x544415 */
L_00544424:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x564cf0u))); /* mov al, byte ptr [esi + 0x10024cf0] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00544453; /* jne 0x544453 */
    c->eax = (uint32_t)(R32((uint32_t)(0x564cecu))); /* mov eax, dword ptr [0x10024cec] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = 0x564be8u; PUSH32(c, v_); } /* push 0x10024be8 */
    { uint32_t v_ = 0x564df1u; PUSH32(c, v_); } /* push 0x10024df1 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0x55f84cu; PUSH32(c, v_); } /* push 0x1001f84c */
    { uint32_t v_ = 0x55f7a0u; PUSH32(c, v_); } /* push 0x1001f7a0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x30u)); PUSH32(c, 0x0054444eu); call_indirect(c, t_); } /* call dword ptr [edx + 0x30] */
    goto L_005446c6; /* jmp 0x5446c6 */
L_00544453:;
    (void)sub32(c, c->esi, (uint32_t)0x1u); /* cmp esi, 1 */
    if (!c->zf) goto L_00544472; /* jne 0x544472 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = 0x564be8u; PUSH32(c, v_); } /* push 0x10024be8 */
    { uint32_t v_ = 0x564df1u; PUSH32(c, v_); } /* push 0x10024df1 */
    { uint32_t v_ = 0x55f84cu; PUSH32(c, v_); } /* push 0x1001f84c */
    { uint32_t v_ = 0x55f748u; PUSH32(c, v_); } /* push 0x1001f748 */
    goto L_005446bb; /* jmp 0x5446bb */
L_00544472:;
    (void)sub32(c, c->esi, (uint32_t)0x41u); /* cmp esi, 0x41 */
    if ((c->zf || c->sf != c->of)) goto L_0054449c; /* jle 0x54449c */
    c->eax = (uint32_t)(R32((uint32_t)(0x564cecu))); /* mov eax, dword ptr [0x10024cec] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = 0x564be8u; PUSH32(c, v_); } /* push 0x10024be8 */
    { uint32_t v_ = 0x564df1u; PUSH32(c, v_); } /* push 0x10024df1 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0x55f84cu; PUSH32(c, v_); } /* push 0x1001f84c */
    { uint32_t v_ = 0x55f6e8u; PUSH32(c, v_); } /* push 0x1001f6e8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x30u)); PUSH32(c, 0x00544497u); call_indirect(c, t_); } /* call dword ptr [edx + 0x30] */
    goto L_005446c6; /* jmp 0x5446c6 */
L_0054449c:;
    W8((uint32_t)(c->esi + 0x564cf0u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esi + 0x10024cf0], 0 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x564cf1u))); /* mov al, byte ptr [esi + 0x10024cf1] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_005444c1; /* je 0x5444c1 */
L_005444ae:;
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x30u); /* cmp al, 0x30 */
    if ((c->sf != c->of)) goto L_005444b6; /* jl 0x5444b6 */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x39u); /* cmp al, 0x39 */
    if ((c->zf || c->sf != c->of)) goto L_005444c1; /* jle 0x5444c1 */
L_005444b6:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x564cf1u))); /* mov al, byte ptr [esi + 0x10024cf1] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_005444ae; /* jne 0x5444ae */
L_005444c1:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x564cf0u))); /* mov cl, byte ptr [esi + 0x10024cf0] */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x564cf0u)); /* lea eax, [esi + 0x10024cf0] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_005444eb; /* jne 0x5444eb */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = 0x564be8u; PUSH32(c, v_); } /* push 0x10024be8 */
    { uint32_t v_ = 0x564df1u; PUSH32(c, v_); } /* push 0x10024df1 */
    { uint32_t v_ = 0x55f84cu; PUSH32(c, v_); } /* push 0x1001f84c */
    { uint32_t v_ = 0x55f698u; PUSH32(c, v_); } /* push 0x1001f698 */
    goto L_005446bb; /* jmp 0x5446bb */
L_005444eb:;
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov al, byte ptr [eax] */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x30u); /* cmp al, 0x30 */
    if ((c->sf != c->of)) goto L_00544502; /* jl 0x544502 */
L_005444f3:;
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x39u); /* cmp al, 0x39 */
    if ((!c->zf && c->sf == c->of)) goto L_00544502; /* jg 0x544502 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x564cf1u))); /* mov al, byte ptr [esi + 0x10024cf1] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x30u); /* cmp al, 0x30 */
    if ((c->sf == c->of)) goto L_005444f3; /* jge 0x5444f3 */
L_00544502:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x564cf0u))); /* mov al, byte ptr [esi + 0x10024cf0] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x25u); /* cmp al, 0x25 */
    W8((uint32_t)(c->esi + 0x564cf0u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esi + 0x10024cf0], 0 */
    if (c->zf) goto L_00544522; /* je 0x544522 */
    PUSH32(c, 0x00544519u); f_0054690c(c); /* call 0x54690c */
    WF32((uint32_t)(c->esp + 0x3cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x3c] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    goto L_0054457c; /* jmp 0x54457c */
L_00544522:;
    PUSH32(c, 0x00544527u); f_0054690c(c); /* call 0x54690c */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x55d108u))); /* fcom dword ptr [0x1001d108] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00544541; /* jp 0x544541 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, (double)RF32((uint32_t)(0x55d108u))); /* fld dword ptr [0x1001d108] */
    goto L_00544558; /* jmp 0x544558 */
L_00544541:;
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x55d2bcu))); /* fcom dword ptr [0x1001d2bc] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00544558; /* jne 0x544558 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, (double)RF32((uint32_t)(0x55d2bcu))); /* fld dword ptr [0x1001d2bc] */
L_00544558:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov edx, dword ptr [esp + 0x24] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov eax, dword ptr [esp + 0x1c] */
    c->edx = (uint32_t)(sub32(c, c->edx, c->eax)); /* sub edx, eax */
    W32((uint32_t)(c->esp + 0x38u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x38], edx */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x38u))); /* fild dword ptr [esp + 0x38] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x55d2b8u))); /* fmul dword ptr [0x1001d2b8] */
    ST(0) = FPRES(c, ST(0) + (double)(int32_t)R32((uint32_t)(c->esp + 0x1cu))); /* fiadd dword ptr [esp + 0x1c] */
    WF32((uint32_t)(c->esp + 0x38u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x38] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
L_0054457c:;
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x1cu))); /* fild dword ptr [esp + 0x1c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x38u))); /* fld dword ptr [esp + 0x38] */
    FCOM(c, ST(0), ST(1)); FPOP(c); /* fcomp st(1) */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00544593; /* jp 0x544593 */
    WF32((uint32_t)(c->esp + 0x38u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x38] */
    goto L_00544595; /* jmp 0x544595 */
L_00544593:;
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
L_00544595:;
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x24u))); /* fild dword ptr [esp + 0x24] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x38u))); /* fld dword ptr [esp + 0x38] */
    FCOM(c, ST(0), ST(1)); FPOP(c); /* fcomp st(1) */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_005445ae; /* jne 0x5445ae */
    WF32((uint32_t)(c->esp + 0x38u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x38] */
    goto L_005445b0; /* jmp 0x5445b0 */
L_005445ae:;
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
L_005445b0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x564cf0u))); /* mov al, byte ptr [esi + 0x10024cf0] */
    c->ebx = (uint32_t)((uint32_t)0x1u); /* mov ebx, 1 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_0054468e; /* je 0x54468e */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x564cf1u))); /* mov al, byte ptr [esi + 0x10024cf1] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_005445e9; /* je 0x5445e9 */
L_005445ce:;
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x41u); /* cmp al, 0x41 */
    if ((c->sf != c->of)) goto L_005445d6; /* jl 0x5445d6 */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x5au); /* cmp al, 0x5a */
    if ((c->zf || c->sf != c->of)) goto L_005445e9; /* jle 0x5445e9 */
L_005445d6:;
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x61u); /* cmp al, 0x61 */
    if ((c->sf != c->of)) goto L_005445de; /* jl 0x5445de */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x7au); /* cmp al, 0x7a */
    if ((c->zf || c->sf != c->of)) goto L_005445e9; /* jle 0x5445e9 */
L_005445de:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x564cf1u))); /* mov al, byte ptr [esi + 0x10024cf1] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_005445ce; /* jne 0x5445ce */
L_005445e9:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x564cf1u))); /* mov al, byte ptr [esi + 0x10024cf1] */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x564cf0u)); /* lea edi, [esi + 0x10024cf0] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00544615; /* je 0x544615 */
L_005445fa:;
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x41u); /* cmp al, 0x41 */
    if ((c->sf != c->of)) goto L_00544602; /* jl 0x544602 */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x5au); /* cmp al, 0x5a */
    if ((c->zf || c->sf != c->of)) goto L_0054460a; /* jle 0x54460a */
L_00544602:;
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x61u); /* cmp al, 0x61 */
    if ((c->sf != c->of)) goto L_00544615; /* jl 0x544615 */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x7au); /* cmp al, 0x7a */
    if ((!c->zf && c->sf == c->of)) goto L_00544615; /* jg 0x544615 */
L_0054460a:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x564cf1u))); /* mov al, byte ptr [esi + 0x10024cf1] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_005445fa; /* jne 0x5445fa */
L_00544615:;
    W8((uint32_t)(c->esi + 0x564cf0u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esi + 0x10024cf0], 0 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov al, byte ptr [edi] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_0054468e; /* je 0x54468e */
    { uint32_t v_ = 0x55f68cu; PUSH32(c, v_); } /* push 0x1001f68c */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x0054462du); f_0054dbf0(c); /* call 0x54dbf0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00544638; /* jne 0x544638 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    goto L_0054468e; /* jmp 0x54468e */
L_00544638:;
    { uint32_t v_ = 0x55f948u; PUSH32(c, v_); } /* push 0x1001f948 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00544643u); f_0054dbf0(c); /* call 0x54dbf0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00544651; /* jne 0x544651 */
    c->ebx = (uint32_t)((uint32_t)0x1u); /* mov ebx, 1 */
    goto L_0054468e; /* jmp 0x54468e */
L_00544651:;
    { uint32_t v_ = 0x55f938u; PUSH32(c, v_); } /* push 0x1001f938 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x0054465cu); f_0054dbf0(c); /* call 0x54dbf0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_0054466a; /* jne 0x54466a */
    c->ebx = (uint32_t)((uint32_t)0x2u); /* mov ebx, 2 */
    goto L_0054468e; /* jmp 0x54468e */
L_0054466a:;
    c->eax = (uint32_t)(R32((uint32_t)(0x564cecu))); /* mov eax, dword ptr [0x10024cec] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = 0x564be8u; PUSH32(c, v_); } /* push 0x10024be8 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x564df1u; PUSH32(c, v_); } /* push 0x10024df1 */
    { uint32_t v_ = 0x55f84cu; PUSH32(c, v_); } /* push 0x1001f84c */
    { uint32_t v_ = 0x55f618u; PUSH32(c, v_); } /* push 0x1001f618 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x0054468bu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
L_0054468e:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x38u))); /* mov edx, dword ptr [esp + 0x38] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ecx, dword ptr [esp + 0x14] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x564cf1u; PUSH32(c, v_); } /* push 0x10024cf1 */
    PUSH32(c, 0x005446a2u); f_005411a0(c); /* call 0x5411a0 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_005446c9; /* jne 0x5446c9 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = 0x564be8u; PUSH32(c, v_); } /* push 0x10024be8 */
    { uint32_t v_ = 0x564df1u; PUSH32(c, v_); } /* push 0x10024df1 */
    { uint32_t v_ = 0x55f84cu; PUSH32(c, v_); } /* push 0x1001f84c */
    { uint32_t v_ = 0x55f5b0u; PUSH32(c, v_); } /* push 0x1001f5b0 */
L_005446bb:;
    c->eax = (uint32_t)(R32((uint32_t)(0x564cecu))); /* mov eax, dword ptr [0x10024cec] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x005446c6u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
L_005446c6:;
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_005446c9:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov ecx, dword ptr [esp + 0x18] */
    { uint32_t v_ = 0x100u; PUSH32(c, v_); } /* push 0x100 */
    { uint32_t v_ = 0x564cf0u; PUSH32(c, v_); } /* push 0x10024cf0 */
    { uint32_t v_ = 0x55f84cu; PUSH32(c, v_); } /* push 0x1001f84c */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = 0x564be8u; PUSH32(c, v_); } /* push 0x10024be8 */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x1cu)); PUSH32(c, 0x005446e6u); call_indirect(c, t_); } /* call dword ptr [edx + 0x1c] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_005443cb; /* jne 0x5443cb */
L_005446ee:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov ecx, dword ptr [esp + 0x18] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x2bcu)); /* add eax, 0x2bc */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x564be8u; PUSH32(c, v_); } /* push 0x10024be8 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov ecx, dword ptr [esp + 0x30] */
    PUSH32(c, 0x0054470cu); f_00544810(c); /* call 0x544810 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov ebx, dword ptr [esp + 0x18] */
    goto L_0054472b; /* jmp 0x54472b */
L_00544712:;
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = 0x564be8u; PUSH32(c, v_); } /* push 0x10024be8 */
    { uint32_t v_ = 0x55f578u; PUSH32(c, v_); } /* push 0x1001f578 */
L_0054471d:;
    c->eax = (uint32_t)(R32((uint32_t)(0x564cecu))); /* mov eax, dword ptr [0x10024cec] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x30u)); PUSH32(c, 0x00544728u); call_indirect(c, t_); } /* call dword ptr [edx + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_0054472b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { uint32_t v_ = 0x564be8u; PUSH32(c, v_); } /* push 0x10024be8 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x5cu)); PUSH32(c, 0x00544739u); call_indirect(c, t_); } /* call dword ptr [eax + 0x5c] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00544139; /* jne 0x544139 */
L_00544741:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov edx, dword ptr [ebx] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    { uint32_t t_ = R32((uint32_t)(c->edx)); PUSH32(c, 0x00544749u); call_indirect(c, t_); } /* call dword ptr [edx] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov edi, dword ptr [esp + 0x20] */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_00544766; /* jle 0x544766 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov ecx, dword ptr [edi + 4] */
L_00544759:;
    (void)sub32(c, R32((uint32_t)(c->ecx)), (uint32_t)0x0u); /* cmp dword ptr [ecx], 0 */
    if (c->zf) goto L_00544766; /* je 0x544766 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if ((c->sf != c->of)) goto L_00544759; /* jl 0x544759 */
L_00544766:;
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if (!c->zf) goto L_005447a9; /* jne 0x5447a9 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov ecx, dword ptr [edi + 4] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x40u)); /* add eax, 0x40 */
    W32((uint32_t)(c->edi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + 8], eax */
    { uint32_t v_ = 0x187u; PUSH32(c, v_); } /* push 0x187 */
    c->eax = (uint32_t)(shl32(c, c->eax, 2)); /* shl eax, 2 */
    { uint32_t v_ = 0x55f46cu; PUSH32(c, v_); } /* push 0x1001f46c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00544787u); f_00543980(c); /* call 0x543980 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov ecx, dword ptr [edi + 8] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    W32((uint32_t)(c->edi + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + 4], eax */
    (void)sub32(c, c->esi, c->ecx); /* cmp esi, ecx */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    if ((c->sf == c->of)) goto L_005447a9; /* jge 0x5447a9 */
L_00544796:;
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov edx, dword ptr [edi + 4] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    W32((uint32_t)(c->edx + c->eax * 4 + 0xfffffffcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [edx + eax*4 - 4], 0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov ecx, dword ptr [edi + 8] */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if ((c->sf != c->of)) goto L_00544796; /* jl 0x544796 */
L_005447a9:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov eax, dword ptr [edi + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    W32((uint32_t)(c->eax + c->esi * 4), (uint32_t)(c->ecx)); /* mov dword ptr [eax + esi*4], ecx */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_005447b5:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov ecx, dword ptr [esp + 0x28] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x24u)); /* add esp, 0x24 */
    c->esp += 8; return; /* ret 4 */
}

void f_005447d0(CPU *c) { /* PTR_005447d0 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    c->esp += 4; return; /* ret  */
}

void f_005447e0(CPU *c) { /* PTR_005447e0 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    c->esp += 8; return; /* ret 4 */
}

void f_005447f0(CPU *c) { /* PTR_005447f0 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x4u))); /* mov al, byte ptr [esp + 4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x55d29cu)); /* mov dword ptr [esi], 0x1001d29c */
    if (c->zf) goto L_0054480a; /* je 0x54480a */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00544807u); f_00543960(c); /* call 0x543960 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_0054480a:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00544810(CPU *c) { /* FUN_10004810 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ebp, dword ptr [esp + 0xc] */
    { uint32_t v_ = 0x5650f4u; PUSH32(c, v_); } /* push 0x100250f4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = 0x3ffu; PUSH32(c, v_); } /* push 0x3ff */
    { uint32_t v_ = 0x564cf0u; PUSH32(c, v_); } /* push 0x10024cf0 */
    { uint32_t v_ = 0x55fda0u; PUSH32(c, v_); } /* push 0x1001fda0 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x00544833u); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00544a3a; /* je 0x544a3a */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov edi, dword ptr [esp + 0x20] */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
L_00544844:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x564cf0u))); /* mov al, byte ptr [0x10024cf0] */
    W8((uint32_t)(0x5650efu), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [0x100250ef], bl */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x22u); /* cmp al, 0x22 */
    if (c->zf) goto L_0054488e; /* je 0x54488e */
    c->eax = (uint32_t)(R32((uint32_t)(0x564cecu))); /* mov eax, dword ptr [0x10024cec] */
    (void)sub32(c, c->ebp, c->ebx); /* cmp ebp, ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (c->zf) goto L_00544876; /* je 0x544876 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = 0x55fda0u; PUSH32(c, v_); } /* push 0x1001fda0 */
    { uint32_t v_ = 0x55fd50u; PUSH32(c, v_); } /* push 0x1001fd50 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x0054486eu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    goto L_00544a0d; /* jmp 0x544a0d */
L_00544876:;
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0x55fda0u; PUSH32(c, v_); } /* push 0x1001fda0 */
    { uint32_t v_ = 0x55fd00u; PUSH32(c, v_); } /* push 0x1001fd00 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x30u)); PUSH32(c, 0x00544886u); call_indirect(c, t_); } /* call dword ptr [edx + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    goto L_00544a0d; /* jmp 0x544a0d */
L_0054488e:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x564cf1u))); /* mov al, byte ptr [0x10024cf1] */
    c->esi = (uint32_t)((uint32_t)0x1u); /* mov esi, 1 */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_005448ab; /* je 0x5448ab */
L_0054489c:;
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x22u); /* cmp al, 0x22 */
    if (c->zf) goto L_005448ab; /* je 0x5448ab */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x564cf1u))); /* mov al, byte ptr [esi + 0x10024cf1] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (!c->zf) goto L_0054489c; /* jne 0x54489c */
L_005448ab:;
    (void)sub8(c, R8((uint32_t)(c->esi + 0x564cf0u)), ((uint8_t)c->ebx)); /* cmp byte ptr [esi + 0x10024cf0], bl */
    if (!c->zf) goto L_005448ee; /* jne 0x5448ee */
    c->eax = (uint32_t)(R32((uint32_t)(0x564cecu))); /* mov eax, dword ptr [0x10024cec] */
    (void)sub32(c, c->ebp, c->ebx); /* cmp ebp, ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (c->zf) goto L_005448d6; /* je 0x5448d6 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = 0x55fda0u; PUSH32(c, v_); } /* push 0x1001fda0 */
    { uint32_t v_ = 0x55fca0u; PUSH32(c, v_); } /* push 0x1001fca0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x005448ceu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    goto L_00544a0d; /* jmp 0x544a0d */
L_005448d6:;
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0x55fda0u; PUSH32(c, v_); } /* push 0x1001fda0 */
    { uint32_t v_ = 0x55fc40u; PUSH32(c, v_); } /* push 0x1001fc40 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x30u)); PUSH32(c, 0x005448e6u); call_indirect(c, t_); } /* call dword ptr [edx + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    goto L_00544a0d; /* jmp 0x544a0d */
L_005448ee:;
    (void)sub32(c, c->esi, (uint32_t)0x1u); /* cmp esi, 1 */
    if (!c->zf) goto L_0054492e; /* jne 0x54492e */
    c->eax = (uint32_t)(R32((uint32_t)(0x564cecu))); /* mov eax, dword ptr [0x10024cec] */
    (void)sub32(c, c->ebp, c->ebx); /* cmp ebp, ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (c->zf) goto L_00544916; /* je 0x544916 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = 0x55fda0u; PUSH32(c, v_); } /* push 0x1001fda0 */
    { uint32_t v_ = 0x55fbf0u; PUSH32(c, v_); } /* push 0x1001fbf0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x0054490eu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    goto L_00544a0d; /* jmp 0x544a0d */
L_00544916:;
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0x55fda0u; PUSH32(c, v_); } /* push 0x1001fda0 */
    { uint32_t v_ = 0x55fba0u; PUSH32(c, v_); } /* push 0x1001fba0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x30u)); PUSH32(c, 0x00544926u); call_indirect(c, t_); } /* call dword ptr [edx + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    goto L_00544a0d; /* jmp 0x544a0d */
L_0054492e:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov ecx, dword ptr [esp + 0x1c] */
    W8((uint32_t)(c->esi + 0x564cf0u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [esi + 0x10024cf0], bl */
    { uint32_t v_ = 0x564cf1u; PUSH32(c, v_); } /* push 0x10024cf1 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    PUSH32(c, 0x00544943u); f_00546140(c); /* call 0x546140 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00544982; /* je 0x544982 */
    c->eax = (uint32_t)(R32((uint32_t)(0x564cecu))); /* mov eax, dword ptr [0x10024cec] */
    (void)sub32(c, c->ebp, c->ebx); /* cmp ebp, ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (c->zf) goto L_0054496a; /* je 0x54496a */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = 0x55fda0u; PUSH32(c, v_); } /* push 0x1001fda0 */
    { uint32_t v_ = 0x55fb58u; PUSH32(c, v_); } /* push 0x1001fb58 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x00544962u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    goto L_00544a0d; /* jmp 0x544a0d */
L_0054496a:;
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0x55fda0u; PUSH32(c, v_); } /* push 0x1001fda0 */
    { uint32_t v_ = 0x55fb10u; PUSH32(c, v_); } /* push 0x1001fb10 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x30u)); PUSH32(c, 0x0054497au); call_indirect(c, t_); } /* call dword ptr [edx + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    goto L_00544a0d; /* jmp 0x544a0d */
L_00544982:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x564cf0u))); /* mov al, byte ptr [esi + 0x10024cf0] */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_0054499b; /* je 0x54499b */
L_0054498c:;
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x22u); /* cmp al, 0x22 */
    if (c->zf) goto L_0054499b; /* je 0x54499b */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x564cf1u))); /* mov al, byte ptr [esi + 0x10024cf1] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (!c->zf) goto L_0054498c; /* jne 0x54498c */
L_0054499b:;
    (void)sub8(c, R8((uint32_t)(c->esi + 0x564cf0u)), ((uint8_t)c->ebx)); /* cmp byte ptr [esi + 0x10024cf0], bl */
    if (!c->zf) goto L_005449d8; /* jne 0x5449d8 */
    c->eax = (uint32_t)(R32((uint32_t)(0x564cecu))); /* mov eax, dword ptr [0x10024cec] */
    (void)sub32(c, c->ebp, c->ebx); /* cmp ebp, ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (c->zf) goto L_005449c3; /* je 0x5449c3 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = 0x55fda0u; PUSH32(c, v_); } /* push 0x1001fda0 */
    { uint32_t v_ = 0x55fac8u; PUSH32(c, v_); } /* push 0x1001fac8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x005449beu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    goto L_00544a0d; /* jmp 0x544a0d */
L_005449c3:;
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0x55fda0u; PUSH32(c, v_); } /* push 0x1001fda0 */
    { uint32_t v_ = 0x55fa80u; PUSH32(c, v_); } /* push 0x1001fa80 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x30u)); PUSH32(c, 0x005449d3u); call_indirect(c, t_); } /* call dword ptr [edx + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    goto L_00544a0d; /* jmp 0x544a0d */
L_005449d8:;
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x564cf0u))); /* mov al, byte ptr [esi + 0x10024cf0] */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x564cf0u)); /* lea ecx, [esi + 0x10024cf0] */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_005449f8; /* je 0x5449f8 */
L_005449e9:;
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x22u); /* cmp al, 0x22 */
    if (c->zf) goto L_005449f8; /* je 0x5449f8 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x564cf1u))); /* mov al, byte ptr [esi + 0x10024cf1] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (!c->zf) goto L_005449e9; /* jne 0x5449e9 */
L_005449f8:;
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov ecx, dword ptr [esp + 0x20] */
    { uint32_t v_ = 0x564cf1u; PUSH32(c, v_); } /* push 0x10024cf1 */
    W8((uint32_t)(c->esi + 0x564cf0u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [esi + 0x10024cf0], bl */
    PUSH32(c, 0x00544a0du); f_00545fb0(c); /* call 0x545fb0 */
L_00544a0d:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ecx, dword ptr [esp + 0x14] */
    { uint32_t v_ = 0x3ffu; PUSH32(c, v_); } /* push 0x3ff */
    { uint32_t v_ = 0x564cf0u; PUSH32(c, v_); } /* push 0x10024cf0 */
    { uint32_t v_ = 0x55fda0u; PUSH32(c, v_); } /* push 0x1001fda0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x1cu)); PUSH32(c, 0x00544a26u); call_indirect(c, t_); } /* call dword ptr [eax + 0x1c] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00544844; /* jne 0x544844 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov ecx, dword ptr [esp + 0x1c] */
    PUSH32(c, 0x00544a37u); f_005460e0(c); /* call 0x5460e0 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
L_00544a3a:;
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 20; return; /* ret 0x10 */
}

void f_00544a40(CPU *c) { /* FUN_10004a40 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x55c760u; PUSH32(c, v_); } /* push 0x1001c760 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x1cu)); /* sub esp, 0x1c */
    c->eax = (uint32_t)(R32((uint32_t)(0x564cecu))); /* mov eax, dword ptr [0x10024cec] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x10], esp */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    { uint32_t v_ = 0x80000000u; PUSH32(c, v_); } /* push 0x80000000 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [ebp - 0x14], 0xffffffff */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 4], ebx */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x4u)); PUSH32(c, 0x00544a87u); call_indirect(c, t_); } /* call dword ptr [edx + 4] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)sub32(c, c->edi, (uint32_t)0xffffffffu); /* cmp edi, -1 */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x14], edi */
    if (!c->zf) goto L_00544aaa; /* jne 0x544aaa */
    c->eax = (uint32_t)(R32((uint32_t)(0x564cecu))); /* mov eax, dword ptr [0x10024cec] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x55ff40u; PUSH32(c, v_); } /* push 0x1001ff40 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x00544aa2u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_00544d52; /* jmp 0x544d52 */
L_00544aaa:;
    c->edx = (uint32_t)(R32((uint32_t)(0x564cecu))); /* mov edx, dword ptr [0x10024cec] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0xcu; PUSH32(c, v_); } /* push 0xc */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov ecx, dword ptr [edx + 4] */
    c->edx = (uint32_t)((uint32_t)(c->ebp + 0xffffffd8u)); /* lea edx, [ebp - 0x28] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x18u)); PUSH32(c, 0x00544ac0u); call_indirect(c, t_); } /* call dword ptr [eax + 0x18] */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_0054510b; /* je 0x54510b */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    (void)sub32(c, c->ecx, c->ebx); /* cmp ecx, ebx */
    if ((c->zf || c->sf != c->of)) goto L_0054510b; /* jle 0x54510b */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov edx, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->edx, c->ebx); /* cmp edx, ebx */
    if ((c->zf || c->sf != c->of)) goto L_0054510b; /* jle 0x54510b */
    FPUSH(c, (double)RF32((uint32_t)(c->ebp + 0xffffffe0u))); /* fld dword ptr [ebp - 0x20] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x55d108u))); FPOP(c); /* fcomp dword ptr [0x1001d108] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (!PF(c)) goto L_0054510b; /* jnp 0x54510b */
    FPUSH(c, (double)RF32((uint32_t)(c->ebp + 0xffffffe0u))); /* fld dword ptr [ebp - 0x20] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x55d2c4u))); FPOP(c); /* fcomp dword ptr [0x1001d2c4] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (c->zf) goto L_0054510b; /* je 0x54510b */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x48u))); /* fld dword ptr [esi + 0x48] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x55d108u))); FPOP(c); /* fcomp dword ptr [0x1001d108] */
    W32((uint32_t)(c->esi + 0x44u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 0x44], ecx */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00544b21; /* jp 0x544b21 */
    W32((uint32_t)(c->esi + 0x48u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x48], ebx */
L_00544b21:;
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x48u))); /* fld dword ptr [esi + 0x48] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x55d2c0u))); FPOP(c); /* fcomp dword ptr [0x1001d2c0] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00544b3a; /* jne 0x544b3a */
    W32((uint32_t)(c->esi + 0x48u), (uint32_t)((uint32_t)0x49742400u)); /* mov dword ptr [esi + 0x48], 0x49742400 */
L_00544b3a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov eax, dword ptr [ebp - 0x20] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    W32((uint32_t)(c->esi + 0x48u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x48], eax */
    PUSH32(c, 0x00544b48u); f_00543650(c); /* call 0x543650 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov ecx, dword ptr [ebp - 0x24] */
    { uint32_t v_ = 0x1edu; PUSH32(c, v_); } /* push 0x1ed */
    { uint32_t v_ = 0x55f46cu; PUSH32(c, v_); } /* push 0x1001f46c */
    c->edx = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea edx, [ecx*4] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00544b62u); f_00543940(c); /* call 0x543940 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(0x564cecu))); /* mov eax, dword ptr [0x10024cec] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    c->eax = (uint32_t)(shl32(c, c->eax, 2)); /* shl eax, 2 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x18u)); PUSH32(c, 0x00544b7fu); call_indirect(c, t_); } /* call dword ptr [edx + 0x18] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00544ba0; /* jne 0x544ba0 */
    c->eax = (uint32_t)(R32((uint32_t)(0x564cecu))); /* mov eax, dword ptr [0x10024cec] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x55ff08u; PUSH32(c, v_); } /* push 0x1001ff08 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x00544b97u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    goto L_00544e4d; /* jmp 0x544e4d */
L_00544ba0:;
    c->esi = (uint32_t)((uint32_t)0x1u); /* mov esi, 1 */
L_00544ba5:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov ecx, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->esi, c->ecx); /* cmp esi, ecx */
    if ((c->sf == c->of)) goto L_00544cc2; /* jge 0x544cc2 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + c->esi * 4))); /* mov eax, dword ptr [ebx + esi*4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf == c->of)) goto L_00544bbf; /* jge 0x544bbf */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if ((c->sf != c->of)) goto L_00544bbf; /* jl 0x544bbf */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00544bc4; /* jmp 0x544bc4 */
L_00544bbf:;
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
L_00544bc4:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(!c->zf ? 1 : 0); /* setne al */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00544bf0; /* jne 0x544bf0 */
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    { uint32_t v_ = 0x55fed0u; PUSH32(c, v_); } /* push 0x1001fed0 */
    { uint32_t v_ = 0x1f7u; PUSH32(c, v_); } /* push 0x1f7 */
    { uint32_t v_ = 0x55f46cu; PUSH32(c, v_); } /* push 0x1001f46c */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00544becu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00544befu, "int3"); /* int3  */
L_00544bf0:;
    (void)sub32(c, R32((uint32_t)(c->ebx + c->esi * 4)), c->esi); /* cmp dword ptr [ebx + esi*4], esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(!c->zf ? 1 : 0); /* setne al */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00544c1d; /* jne 0x544c1d */
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    { uint32_t v_ = 0x55febcu; PUSH32(c, v_); } /* push 0x1001febc */
    { uint32_t v_ = 0x1f8u; PUSH32(c, v_); } /* push 0x1f8 */
    { uint32_t v_ = 0x55f46cu; PUSH32(c, v_); } /* push 0x1001f46c */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00544c19u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00544c1cu, "int3"); /* int3  */
L_00544c1d:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + c->esi * 4))); /* mov edi, dword ptr [ebx + esi*4] */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if ((c->sf != c->of)) goto L_00544c33; /* jl 0x544c33 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    (void)sub32(c, c->edi, R32((uint32_t)(c->eax + 0x50u))); /* cmp edi, dword ptr [eax + 0x50] */
    if ((c->sf == c->of)) goto L_00544c33; /* jge 0x544c33 */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    goto L_00544c35; /* jmp 0x544c35 */
L_00544c33:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00544c35:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(!c->zf ? 1 : 0); /* setne al */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00544c5e; /* jne 0x544c5e */
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    { uint32_t v_ = 0x55f380u; PUSH32(c, v_); } /* push 0x1001f380 */
    { uint32_t v_ = 0x72u; PUSH32(c, v_); } /* push 0x72 */
    { uint32_t v_ = 0x55f204u; PUSH32(c, v_); } /* push 0x1001f204 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00544c5au); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00544c5du, "int3"); /* int3  */
L_00544c5e:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->edx = (uint32_t)((uint32_t)(c->edi + c->edi * 2)); /* lea edx, [edi + edi*2] */
    c->edx = (uint32_t)(shl32(c, c->edx, 4)); /* shl edx, 4 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4cu))); /* mov ecx, dword ptr [eax + 0x4c] */
    c->edx = (uint32_t)(sub32(c, c->edx, c->edi)); /* sub edx, edi */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    c->edi = (uint32_t)((uint32_t)(c->ecx + c->edx * 4)); /* lea edi, [ecx + edx*4] */
    if ((c->sf != c->of)) goto L_00544c7f; /* jl 0x544c7f */
    (void)sub32(c, c->esi, R32((uint32_t)(c->eax + 0x50u))); /* cmp esi, dword ptr [eax + 0x50] */
    if ((c->sf == c->of)) goto L_00544c7f; /* jge 0x544c7f */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    goto L_00544c81; /* jmp 0x544c81 */
L_00544c7f:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00544c81:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(!c->zf ? 1 : 0); /* setne al */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00544caa; /* jne 0x544caa */
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    { uint32_t v_ = 0x55f380u; PUSH32(c, v_); } /* push 0x1001f380 */
    { uint32_t v_ = 0x72u; PUSH32(c, v_); } /* push 0x72 */
    { uint32_t v_ = 0x55f204u; PUSH32(c, v_); } /* push 0x1001f204 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00544ca6u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00544ca9u, "int3"); /* int3  */
L_00544caa:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea eax, [esi + esi*2] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4cu))); /* mov edx, dword ptr [ecx + 0x4c] */
    c->eax = (uint32_t)(sub32(c, c->eax, c->esi)); /* sub eax, esi */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    W32((uint32_t)(c->edx + c->eax * 4 + 0x4u), (uint32_t)(c->edi)); /* mov dword ptr [edx + eax*4 + 4], edi */
    goto L_00544ba5; /* jmp 0x544ba5 */
L_00544cc2:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00544cc8u); f_00543960(c); /* call 0x543960 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea eax, [eax + eax*2] */
    { uint32_t v_ = 0x1fdu; PUSH32(c, v_); } /* push 0x1fd */
    c->eax = (uint32_t)(shl32(c, c->eax, 2)); /* shl eax, 2 */
    { uint32_t v_ = 0x55f46cu; PUSH32(c, v_); } /* push 0x1001f46c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00544ce6u); f_00543940(c); /* call 0x543940 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00544cff; /* je 0x544cff */
    c->edx = (uint32_t)((uint32_t)0xcu); /* mov edx, 0xc */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
L_00544cf4:;
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    if (c->sf) goto L_00544cfb; /* js 0x544cfb */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->edx)); /* add ecx, edx */
    goto L_00544cf4; /* jmp 0x544cf4 */
L_00544cfb:;
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    goto L_00544d01; /* jmp 0x544d01 */
L_00544cff:;
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
L_00544d01:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x564cecu))); /* mov ecx, dword ptr [0x10024cec] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov esi, dword ptr [ebp - 0x14] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ecx, dword ptr [ecx + 4] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea eax, [eax + eax*2] */
    c->eax = (uint32_t)(shl32(c, c->eax, 2)); /* shl eax, 2 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x18u)); PUSH32(c, 0x00544d20u); call_indirect(c, t_); } /* call dword ptr [edx + 0x18] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00544d67; /* jne 0x544d67 */
    c->eax = (uint32_t)(R32((uint32_t)(0x564cecu))); /* mov eax, dword ptr [0x10024cec] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x55fe78u; PUSH32(c, v_); } /* push 0x1001fe78 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x00544d38u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00544d41u); f_00543960(c); /* call 0x543960 */
    c->eax = (uint32_t)(R32((uint32_t)(0x564cecu))); /* mov eax, dword ptr [0x10024cec] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
L_00544d4f:;
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x00544d52u); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
L_00544d52:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 12; return; /* ret 8 */
L_00544d67:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ebx, dword ptr [ebp + 0xc] */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_00544d6c:;
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0xffffffdcu))); /* cmp esi, dword ptr [ebp - 0x24] */
    if ((c->sf == c->of)) goto L_00544dd3; /* jge 0x544dd3 */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if ((c->sf != c->of)) goto L_00544d81; /* jl 0x544d81 */
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebx + 0x50u))); /* cmp esi, dword ptr [ebx + 0x50] */
    if ((c->sf == c->of)) goto L_00544d81; /* jge 0x544d81 */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    goto L_00544d83; /* jmp 0x544d83 */
L_00544d81:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00544d83:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(!c->zf ? 1 : 0); /* setne al */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00544dac; /* jne 0x544dac */
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    { uint32_t v_ = 0x55f380u; PUSH32(c, v_); } /* push 0x1001f380 */
    { uint32_t v_ = 0x72u; PUSH32(c, v_); } /* push 0x72 */
    { uint32_t v_ = 0x55f204u; PUSH32(c, v_); } /* push 0x1001f204 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00544da8u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00544dabu, "int3"); /* int3  */
L_00544dac:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x4cu))); /* mov eax, dword ptr [ebx + 0x4c] */
    c->edx = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea edx, [esi + esi*2] */
    c->edx = (uint32_t)(shl32(c, c->edx, 4)); /* shl edx, 4 */
    c->edx = (uint32_t)(sub32(c, c->edx, c->esi)); /* sub edx, esi */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->edx * 4)); /* lea ecx, [eax + edx*4] */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea eax, [esi + esi*2] */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete dl */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)((uint32_t)(c->edi + c->eax * 4)); /* lea edx, [edi + eax*4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00544dd0u); f_005457f0(c); /* call 0x5457f0 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    goto L_00544d6c; /* jmp 0x544d6c */
L_00544dd3:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00544dd9u); f_00543960(c); /* call 0x543960 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea ecx, [eax + eax*2] */
    { uint32_t v_ = 0x20cu; PUSH32(c, v_); } /* push 0x20c */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 2)); /* shl ecx, 2 */
    { uint32_t v_ = 0x55f46cu; PUSH32(c, v_); } /* push 0x1001f46c */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00544df7u); f_00543940(c); /* call 0x543940 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00544e10; /* je 0x544e10 */
    c->edx = (uint32_t)((uint32_t)0xcu); /* mov edx, 0xc */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
L_00544e05:;
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    if (c->sf) goto L_00544e0c; /* js 0x544e0c */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->edx)); /* add ecx, edx */
    goto L_00544e05; /* jmp 0x544e05 */
L_00544e0c:;
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    goto L_00544e12; /* jmp 0x544e12 */
L_00544e10:;
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_00544e12:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    c->edx = (uint32_t)(R32((uint32_t)(0x564cecu))); /* mov edx, dword ptr [0x10024cec] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov edi, dword ptr [ebp - 0x14] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov ecx, dword ptr [edx + 4] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea eax, [eax + eax*2] */
    c->eax = (uint32_t)(shl32(c, c->eax, 2)); /* shl eax, 2 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x18u)); PUSH32(c, 0x00544e31u); call_indirect(c, t_); } /* call dword ptr [edx + 0x18] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00544e65; /* jne 0x544e65 */
    c->eax = (uint32_t)(R32((uint32_t)(0x564cecu))); /* mov eax, dword ptr [0x10024cec] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x55fe38u; PUSH32(c, v_); } /* push 0x1001fe38 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x00544e49u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
L_00544e4d:;
    PUSH32(c, 0x00544e52u); f_00543960(c); /* call 0x543960 */
    c->eax = (uint32_t)(R32((uint32_t)(0x564cecu))); /* mov eax, dword ptr [0x10024cec] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    goto L_00544d4f; /* jmp 0x544d4f */
L_00544e65:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x50u))); /* mov edi, dword ptr [ebx + 0x50] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((!c->zf && c->sf == c->of) ? 1 : 0); /* setg al */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(!c->zf ? 1 : 0); /* setne al */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00544e98; /* jne 0x544e98 */
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    { uint32_t v_ = 0x55f380u; PUSH32(c, v_); } /* push 0x1001f380 */
    { uint32_t v_ = 0x72u; PUSH32(c, v_); } /* push 0x72 */
    { uint32_t v_ = 0x55f204u; PUSH32(c, v_); } /* push 0x1001f204 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00544e94u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00544e97u, "int3"); /* int3  */
L_00544e98:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov edx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x4cu))); /* mov ecx, dword ptr [ebx + 0x4c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00544ea5u); f_005458d0(c); /* call 0x5458d0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00544eabu); f_00543960(c); /* call 0x543960 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = 0x218u; PUSH32(c, v_); } /* push 0x218 */
    { uint32_t v_ = 0x55f46cu; PUSH32(c, v_); } /* push 0x1001f46c */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00544ec6u); f_00543940(c); /* call 0x543940 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00544edf; /* je 0x544edf */
    c->edx = (uint32_t)((uint32_t)0x10u); /* mov edx, 0x10 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
L_00544ed4:;
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    if (c->sf) goto L_00544edb; /* js 0x544edb */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->edx)); /* add ecx, edx */
    goto L_00544ed4; /* jmp 0x544ed4 */
L_00544edb:;
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    goto L_00544ee1; /* jmp 0x544ee1 */
L_00544edf:;
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
L_00544ee1:;
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_00544ee3:;
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0xffffffdcu))); /* cmp esi, dword ptr [ebp - 0x24] */
    if ((c->sf == c->of)) goto L_00544f8f; /* jge 0x544f8f */
    c->eax = (uint32_t)(R32((uint32_t)(0x564cecu))); /* mov eax, dword ptr [0x10024cec] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x18u)); PUSH32(c, 0x00544f07u); call_indirect(c, t_); } /* call dword ptr [edx + 0x18] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00544f36; /* jne 0x544f36 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(0x564cecu))); /* mov eax, dword ptr [0x10024cec] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x55fdf8u; PUSH32(c, v_); } /* push 0x1001fdf8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x00544f20u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    c->eax = (uint32_t)(R32((uint32_t)(0x564cecu))); /* mov eax, dword ptr [0x10024cec] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    goto L_00544d4f; /* jmp 0x544d4f */
L_00544f36:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if ((c->sf != c->of)) goto L_00544f46; /* jl 0x544f46 */
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebx + 0x50u))); /* cmp esi, dword ptr [ebx + 0x50] */
    if ((c->sf == c->of)) goto L_00544f46; /* jge 0x544f46 */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    goto L_00544f48; /* jmp 0x544f48 */
L_00544f46:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00544f48:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(!c->zf ? 1 : 0); /* setne al */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00544f71; /* jne 0x544f71 */
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    { uint32_t v_ = 0x55f380u; PUSH32(c, v_); } /* push 0x1001f380 */
    { uint32_t v_ = 0x72u; PUSH32(c, v_); } /* push 0x72 */
    { uint32_t v_ = 0x55f204u; PUSH32(c, v_); } /* push 0x1001f204 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00544f6du); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00544f70u, "int3"); /* int3  */
L_00544f71:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x4cu))); /* mov eax, dword ptr [ebx + 0x4c] */
    c->edx = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea edx, [esi + esi*2] */
    c->edx = (uint32_t)(shl32(c, c->edx, 4)); /* shl edx, 4 */
    c->edx = (uint32_t)(sub32(c, c->edx, c->esi)); /* sub edx, esi */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->edx * 4)); /* lea ecx, [eax + edx*4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov edx, dword ptr [ebp - 0x28] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00544f89u); f_00545970(c); /* call 0x545970 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    goto L_00544ee3; /* jmp 0x544ee3 */
L_00544f8f:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00544f95u); f_00543960(c); /* call 0x543960 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_00544f9a:;
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0xffffffdcu))); /* cmp esi, dword ptr [ebp - 0x24] */
    if ((c->sf == c->of)) goto L_00544ff0; /* jge 0x544ff0 */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if ((c->sf != c->of)) goto L_00544faf; /* jl 0x544faf */
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebx + 0x50u))); /* cmp esi, dword ptr [ebx + 0x50] */
    if ((c->sf == c->of)) goto L_00544faf; /* jge 0x544faf */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    goto L_00544fb1; /* jmp 0x544fb1 */
L_00544faf:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00544fb1:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(!c->zf ? 1 : 0); /* setne al */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00544fda; /* jne 0x544fda */
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    { uint32_t v_ = 0x55f380u; PUSH32(c, v_); } /* push 0x1001f380 */
    { uint32_t v_ = 0x72u; PUSH32(c, v_); } /* push 0x72 */
    { uint32_t v_ = 0x55f204u; PUSH32(c, v_); } /* push 0x1001f204 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00544fd6u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00544fd9u, "int3"); /* int3  */
L_00544fda:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x4cu))); /* mov eax, dword ptr [ebx + 0x4c] */
    c->edx = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea edx, [esi + esi*2] */
    c->edx = (uint32_t)(shl32(c, c->edx, 4)); /* shl edx, 4 */
    c->edx = (uint32_t)(sub32(c, c->edx, c->esi)); /* sub edx, esi */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->edx * 4)); /* lea ecx, [eax + edx*4] */
    PUSH32(c, 0x00544fedu); f_00545be0(c); /* call 0x545be0 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    goto L_00544f9a; /* jmp 0x544f9a */
L_00544ff0:;
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x18], esi */
L_00544ff5:;
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0xffffffdcu))); /* cmp esi, dword ptr [ebp - 0x24] */
    if ((c->sf == c->of)) goto L_005450e4; /* jge 0x5450e4 */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if ((c->sf != c->of)) goto L_0054500e; /* jl 0x54500e */
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebx + 0x50u))); /* cmp esi, dword ptr [ebx + 0x50] */
    if ((c->sf == c->of)) goto L_0054500e; /* jge 0x54500e */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    goto L_00545010; /* jmp 0x545010 */
L_0054500e:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00545010:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(!c->zf ? 1 : 0); /* setne al */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00545039; /* jne 0x545039 */
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    { uint32_t v_ = 0x55f380u; PUSH32(c, v_); } /* push 0x1001f380 */
    { uint32_t v_ = 0x72u; PUSH32(c, v_); } /* push 0x72 */
    { uint32_t v_ = 0x55f204u; PUSH32(c, v_); } /* push 0x1001f204 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00545035u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00545038u, "int3"); /* int3  */
L_00545039:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->edx = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea edx, [esi + esi*2] */
    c->edx = (uint32_t)(shl32(c, c->edx, 4)); /* shl edx, 4 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4cu))); /* mov ecx, dword ptr [eax + 0x4c] */
    c->edx = (uint32_t)(sub32(c, c->edx, c->esi)); /* sub edx, esi */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + c->edx * 4 + 0xb4u))); /* fld dword ptr [ecx + edx*4 + 0xb4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ecx + c->edx * 4 + 0x94u))); /* fmul dword ptr [ecx + edx*4 + 0x94] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + c->edx * 4 + 0xb0u))); /* fld dword ptr [ecx + edx*4 + 0xb0] */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->edx * 4 + 0x7cu)); /* lea eax, [ecx + edx*4 + 0x7c] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x14u))); /* fmul dword ptr [eax + 0x14] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x30u))); /* fld dword ptr [eax + 0x30] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x10u))); /* fmul dword ptr [eax + 0x10] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x38u))); /* fld dword ptr [eax + 0x38] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x28u))); /* fmul dword ptr [eax + 0x28] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x34u))); /* fld dword ptr [eax + 0x34] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x24u))); /* fmul dword ptr [eax + 0x24] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x30u))); /* fld dword ptr [eax + 0x30] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x20u))); /* fmul dword ptr [eax + 0x20] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x38u))); /* fld dword ptr [eax + 0x38] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x8u))); /* fmul dword ptr [eax + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x34u))); /* fld dword ptr [eax + 0x34] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x4u))); /* fmul dword ptr [eax + 4] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x30u))); /* fld dword ptr [eax + 0x30] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax))); /* fmul dword ptr [eax] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = -ST(0); /* fchs  */
    WF32((uint32_t)(c->eax + 0x30u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 0x30] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = -ST(0); /* fchs  */
    WF32((uint32_t)(c->eax + 0x34u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 0x34] */
    ST(0) = -ST(0); /* fchs  */
    WF32((uint32_t)(c->eax + 0x38u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 0x38] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
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
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov eax, dword ptr [ebp - 0x18] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ebx, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x18], eax */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    goto L_00544ff5; /* jmp 0x544ff5 */
L_005450e4:;
    c->edx = (uint32_t)(R32((uint32_t)(0x564cecu))); /* mov edx, dword ptr [0x10024cec] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov ecx, dword ptr [edx + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov edx, dword ptr [ebp - 0x14] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x005450f6u); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 12; return; /* ret 8 */
L_0054510b:;
    c->eax = (uint32_t)(R32((uint32_t)(0x564cecu))); /* mov eax, dword ptr [0x10024cec] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x55fdccu; PUSH32(c, v_); } /* push 0x1001fdcc */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x0054511cu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    c->edx = (uint32_t)(R32((uint32_t)(0x564cecu))); /* mov edx, dword ptr [0x10024cec] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov ecx, dword ptr [edx + 4] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x0054512eu); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
    goto L_00544d52; /* jmp 0x544d52 */
}

void f_00544d52(CPU *c) { /* PTR_00544d52 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 12; return; /* ret 8 */
}

void f_00545133(CPU *c) { /* Catch@10005133 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (c->zf) goto L_0054514a; /* je 0x54514a */
    c->ecx = (uint32_t)(R32((uint32_t)(0x564cecu))); /* mov ecx, dword ptr [0x10024cec] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ecx, dword ptr [ecx + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x0054514au); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
L_0054514a:;
    c->eax = (uint32_t)(R32((uint32_t)(0x564cecu))); /* mov eax, dword ptr [0x10024cec] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x55fda8u; PUSH32(c, v_); } /* push 0x1001fda8 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x0054515eu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->eax = (uint32_t)((uint32_t)0x544d52u); /* mov eax, 0x10004d52 */
    c->esp += 4; return; /* ret  */
}

void f_00545170(CPU *c) { /* FUN_10005170 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx), (uint32_t)((uint32_t)0x55d29cu)); /* mov dword ptr [ecx], 0x1001d29c */
    c->esp += 4; return; /* ret  */
}

void f_00545180(CPU *c) { /* PTR_00545180 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    c->esp += 4; return; /* ret  */
}

void f_00545190(CPU *c) { /* PTR_00545190 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_005451a0(CPU *c) { /* PTR_005451a0 */
    PREEMPT_POLL(c);
    { uint32_t a_ = (uint32_t)(c->ecx + 0xcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ecx + 0xc] */
    c->esp += 4; return; /* ret  */
}

void f_005451b0(CPU *c) { /* PTR_005451b0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov eax, dword ptr [ecx + 0xc] */
    c->esp += 4; return; /* ret  */
}

void f_005451c0(CPU *c) { /* PTR_005451c0 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx + 0xcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ecx + 0xc], 0 */
    c->esp += 4; return; /* ret  */
}

void f_005451d0(CPU *c) { /* PTR_005451d0 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x4u))); /* mov al, byte ptr [esp + 4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x55d25cu)); /* mov dword ptr [esi], 0x1001d25c */
    if (c->zf) goto L_005451ea; /* je 0x5451ea */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x005451e7u); f_00543960(c); /* call 0x543960 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_005451ea:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_005451f0(CPU *c) { /* PTR_005451f0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x55d2c8u)); /* mov dword ptr [eax], 0x1001d2c8 */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 4], ecx */
    W32((uint32_t)(c->eax + 0x14u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x14], ecx */
    W32((uint32_t)(c->eax + 0x18u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x18], ecx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0xc], ecx */
    W32((uint32_t)(c->eax + 0x10u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [eax + 0x10], 0x3f800000 */
    c->esp += 4; return; /* ret  */
}

void f_00545220(CPU *c) { /* FUN_10005220 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00545228u); f_00545240(c); /* call 0x545240 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00545238; /* je 0x545238 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00545235u); f_00543960(c); /* call 0x543960 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00545238:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00545240(CPU *c) { /* FUN_10005240 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx), (uint32_t)((uint32_t)0x55d2f4u)); /* mov dword ptr [ecx], 0x1001d2f4 */
    c->esp += 4; return; /* ret  */
}

void f_00545250(CPU *c) { /* FUN_10005250 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edi, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00545263; /* jne 0x545263 */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (!c->zf) goto L_00545283; /* jne 0x545283 */
L_00545263:;
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    { uint32_t v_ = 0x55ff90u; PUSH32(c, v_); } /* push 0x1001ff90 */
    { uint32_t v_ = 0x27u; PUSH32(c, v_); } /* push 0x27 */
    { uint32_t v_ = 0x55ff58u; PUSH32(c, v_); } /* push 0x1001ff58 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x0054527fu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00545282u, "int3"); /* int3  */
L_00545283:;
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 4], edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00545290(CPU *c) { /* PTR_00545290 */
    PREEMPT_POLL(c);
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x8u))); /* fld dword ptr [esp + 8] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x55d108u))); FPOP(c); /* fcomp dword ptr [0x1001d108] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_005452a9; /* jp 0x5452a9 */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 8], 0 */
L_005452a9:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x8u))); /* fld dword ptr [esp + 8] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->esp + 0x4u))); FPOP(c); /* fcomp dword ptr [esp + 4] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x100u))); /* and eax, 0x100 */
    if (c->zf) goto L_005452f0; /* je 0x5452f0 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x4u))); /* fld dword ptr [esp + 4] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x55d108u))); FPOP(c); /* fcomp dword ptr [0x1001d108] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x41u)); /* test ah, 0x41 */
    if (!PF(c)) goto L_005452f0; /* jnp 0x5452f0 */
    FPUSH(c, (double)RF32((uint32_t)(0x55d104u))); /* fld dword ptr [0x1001d104] */
    ST(0) = FPRES(c, FDIV(c, ST(0), (double)RF32((uint32_t)(c->esp + 0x4u)))); /* fdiv dword ptr [esp + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 8], eax */
    W32((uint32_t)(c->ecx + 0x10u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ecx + 0x10], 0 */
    WF32((uint32_t)(c->ecx + 0xcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [ecx + 0xc] */
    PUSH32(c, 0x005452edu); f_00545650(c); /* call 0x545650 */
    c->esp += 12; return; /* ret 8 */
L_005452f0:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x005452f5u); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    c->esp += 12; return; /* ret 8 */
}

void f_00545300(CPU *c) { /* FUN_10005300 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 8], ebx */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0xc], ebx */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [esi + 0x10], 0x3f800000 */
L_00545316:;
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x1fu))); /* and ecx, 0x1f */
    c->eax = (uint32_t)(shl32(c, c->eax, (c->ecx & 0xff))); /* shl eax, cl */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 5)); /* sar ecx, 5 */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x14u)) & c->eax)); /* test dword ptr [esi + ecx*4 + 0x14], eax */
    if (c->zf) goto L_00545371; /* je 0x545371 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x18u))); /* mov edx, dword ptr [esi + ecx*4 + 0x18] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->edx)); /* test eax, edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (c->zf) goto L_00545367; /* je 0x545367 */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4u)); PUSH32(c, 0x0054533eu); call_indirect(c, t_); } /* call dword ptr [eax + 4] */
    W32((uint32_t)(c->eax + 0x38u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x38], ebx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x4u)); PUSH32(c, 0x0054534au); call_indirect(c, t_); } /* call dword ptr [edx + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x20u)); PUSH32(c, 0x00545351u); call_indirect(c, t_); } /* call dword ptr [edx + 0x20] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00545371; /* je 0x545371 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4u)); PUSH32(c, 0x0054535eu); call_indirect(c, t_); } /* call dword ptr [eax + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x10u)); PUSH32(c, 0x00545365u); call_indirect(c, t_); } /* call dword ptr [edx + 0x10] */
    goto L_00545371; /* jmp 0x545371 */
L_00545367:;
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4u)); PUSH32(c, 0x0054536au); call_indirect(c, t_); } /* call dword ptr [eax + 4] */
    W32((uint32_t)(c->eax + 0x38u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [eax + 0x38], 0x3f800000 */
L_00545371:;
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->edi, (uint32_t)0x8u); /* cmp edi, 8 */
    if ((c->sf != c->of)) goto L_00545316; /* jl 0x545316 */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
L_00545379:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x00545382u); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->zf) goto L_0054538e; /* je 0x54538e */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->edi, (uint32_t)0x8u); /* cmp edi, 8 */
    if ((c->sf != c->of)) goto L_00545379; /* jl 0x545379 */
    goto L_00545393; /* jmp 0x545393 */
L_0054538e:;
    (void)sub32(c, c->edi, (uint32_t)0x8u); /* cmp edi, 8 */
    if ((c->sf != c->of)) goto L_005453b3; /* jl 0x5453b3 */
L_00545393:;
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    { uint32_t v_ = 0x55ffa4u; PUSH32(c, v_); } /* push 0x1001ffa4 */
    { uint32_t v_ = 0x59u; PUSH32(c, v_); } /* push 0x59 */
    { uint32_t v_ = 0x55ff58u; PUSH32(c, v_); } /* push 0x1001ff58 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x005453afu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x005453b2u, "int3"); /* int3  */
L_005453b3:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    PUSH32(c, 0x005453beu); f_005431e0(c); /* call 0x5431e0 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_005453d0(CPU *c) { /* PTR_005453d0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 8], eax */
    W32((uint32_t)(c->ecx + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 0xc], eax */
    W32((uint32_t)(c->ecx + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 0x10], eax */
    W32((uint32_t)(c->ecx + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 0x14], eax */
    W32((uint32_t)(c->ecx + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 0x18], eax */
    c->esp += 4; return; /* ret  */
}

void f_005453f0(CPU *c) { /* PTR_005453f0 */
    PREEMPT_POLL(c);
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0xcu))); /* fld dword ptr [ecx + 0xc] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x55d108u))); FPOP(c); /* fcomp dword ptr [0x1001d108] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x44u)); /* test ah, 0x44 */
    if (!PF(c)) goto L_00545406; /* jnp 0x545406 */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    c->esp += 4; return; /* ret  */
L_00545406:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_00545410(CPU *c) { /* PTR_00545410 */
    PREEMPT_POLL(c);
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x10u))); /* fld dword ptr [ecx + 0x10] */
    c->esp += 4; return; /* ret  */
}

void f_00545420(CPU *c) { /* PTR_00545420 */
    PREEMPT_POLL(c);
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0xcu))); /* fld dword ptr [ecx + 0xc] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x55d108u))); FPOP(c); /* fcomp dword ptr [0x1001d108] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_0054543c; /* jne 0x54543c */
    FPUSH(c, (double)RF32((uint32_t)(0x55d104u))); /* fld dword ptr [0x1001d104] */
    ST(0) = FPRES(c, FDIV(c, ST(0), (double)RF32((uint32_t)(c->ecx + 0xcu)))); /* fdiv dword ptr [ecx + 0xc] */
    c->esp += 4; return; /* ret  */
L_0054543c:;
    FPUSH(c, (double)RF32((uint32_t)(0x55d108u))); /* fld dword ptr [0x1001d108] */
    c->esp += 4; return; /* ret  */
}

void f_00545450(CPU *c) { /* PTR_00545450 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edi, dword ptr [esp + 0xc] */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if ((c->sf == c->of)) goto L_00545484; /* jge 0x545484 */
    (void)sub32(c, c->edi, (uint32_t)0x8u); /* cmp edi, 8 */
    if ((c->sf != c->of)) goto L_00545484; /* jl 0x545484 */
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    { uint32_t v_ = 0x55ffb8u; PUSH32(c, v_); } /* push 0x1001ffb8 */
    { uint32_t v_ = 0x81u; PUSH32(c, v_); } /* push 0x81 */
    { uint32_t v_ = 0x55ff58u; PUSH32(c, v_); } /* push 0x1001ff58 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00545480u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00545483u, "int3"); /* int3  */
L_00545484:;
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    c->edx = (uint32_t)((uint32_t)0x1u); /* mov edx, 1 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x1fu))); /* and ecx, 0x1f */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edx = (uint32_t)(shl32(c, c->edx, (c->ecx & 0xff))); /* shl edx, cl */
    c->eax = (uint32_t)(sar32(c, c->eax, 5)); /* sar eax, 5 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + c->eax * 4 + 0x14u))); /* mov ecx, dword ptr [esi + eax*4 + 0x14] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->edx))); /* or ecx, edx */
    W32((uint32_t)(c->esi + c->eax * 4 + 0x14u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + eax*4 + 0x14], ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x10u))); /* mov cl, byte ptr [esp + 0x10] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + c->eax * 4 + 0x18u))); /* mov ecx, dword ptr [esi + eax*4 + 0x18] */
    if (c->zf) goto L_005454af; /* je 0x5454af */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->edx))); /* or ecx, edx */
    goto L_005454b3; /* jmp 0x5454b3 */
L_005454af:;
    c->edx = (uint32_t)((uint32_t)~c->edx); /* not edx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & c->edx))); /* and ecx, edx */
L_005454b3:;
    W32((uint32_t)(c->esi + c->eax * 4 + 0x18u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + eax*4 + 0x18], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x4u)); PUSH32(c, 0x005454c0u); call_indirect(c, t_); } /* call dword ptr [edx + 4] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    W32((uint32_t)(c->eax + 0x38u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [eax + 0x38], 0x3f800000 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 12; return; /* ret 8 */
}

void f_005454d0(CPU *c) { /* FUN_100054d0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if ((c->sf == c->of)) goto L_00545504; /* jge 0x545504 */
    (void)sub32(c, c->esi, (uint32_t)0x8u); /* cmp esi, 8 */
    if ((c->sf != c->of)) goto L_00545504; /* jl 0x545504 */
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    { uint32_t v_ = 0x55ffb8u; PUSH32(c, v_); } /* push 0x1001ffb8 */
    { uint32_t v_ = 0x90u; PUSH32(c, v_); } /* push 0x90 */
    { uint32_t v_ = 0x55ff58u; PUSH32(c, v_); } /* push 0x1001ff58 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00545500u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00545503u, "int3"); /* int3  */
L_00545504:;
    c->edx = (uint32_t)(c->esi); /* mov edx, esi */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->edx = (uint32_t)(sar32(c, c->edx, 5)); /* sar edx, 5 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x1fu))); /* and ecx, 0x1f */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)((uint32_t)(c->edi + c->edx * 4 + 0x14u)); /* lea eax, [edi + edx*4 + 0x14] */
    c->edx = (uint32_t)((uint32_t)0x1u); /* mov edx, 1 */
    c->edx = (uint32_t)(shl32(c, c->edx, (c->ecx & 0xff))); /* shl edx, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->edx = (uint32_t)((uint32_t)~c->edx); /* not edx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & c->edx))); /* and ecx, edx */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov ecx, dword ptr [edi + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4u)); PUSH32(c, 0x0054552au); call_indirect(c, t_); } /* call dword ptr [eax + 4] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    W32((uint32_t)(c->eax + 0x38u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [eax + 0x38], 0x3f800000 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00545540(CPU *c) { /* FUN_10005540 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if ((c->sf == c->of)) goto L_00545574; /* jge 0x545574 */
    (void)sub32(c, c->esi, (uint32_t)0x8u); /* cmp esi, 8 */
    if ((c->sf != c->of)) goto L_00545574; /* jl 0x545574 */
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    { uint32_t v_ = 0x55ffb8u; PUSH32(c, v_); } /* push 0x1001ffb8 */
    { uint32_t v_ = 0x99u; PUSH32(c, v_); } /* push 0x99 */
    { uint32_t v_ = 0x55ff58u; PUSH32(c, v_); } /* push 0x1001ff58 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00545570u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00545573u, "int3"); /* int3  */
L_00545574:;
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x1fu))); /* and ecx, 0x1f */
    c->eax = (uint32_t)(shl32(c, c->eax, (c->ecx & 0xff))); /* shl eax, cl */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 5)); /* sar ecx, 5 */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->edi + c->ecx * 4 + 0x14u)) & c->eax)); /* test dword ptr [edi + ecx*4 + 0x14], eax */
    if (c->zf) goto L_005455a3; /* je 0x5455a3 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_0054559c; /* je 0x54559c */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->edi + c->ecx * 4 + 0x18u)) & c->eax)); /* test dword ptr [edi + ecx*4 + 0x18], eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(!c->zf ? 1 : 0); /* setne al */
    W8((uint32_t)(c->edx), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edx], al */
L_0054559c:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 12; return; /* ret 8 */
L_005455a3:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 12; return; /* ret 8 */
}

void f_005455b0(CPU *c) { /* PTR_005455b0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edi, dword ptr [esp + 0xc] */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if ((c->sf == c->of)) goto L_005455e4; /* jge 0x5455e4 */
    (void)sub32(c, c->edi, (uint32_t)0x8u); /* cmp edi, 8 */
    if ((c->sf != c->of)) goto L_005455e4; /* jl 0x5455e4 */
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    { uint32_t v_ = 0x55ffb8u; PUSH32(c, v_); } /* push 0x1001ffb8 */
    { uint32_t v_ = 0xa6u; PUSH32(c, v_); } /* push 0xa6 */
    { uint32_t v_ = 0x55ff58u; PUSH32(c, v_); } /* push 0x1001ff58 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x005455e0u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x005455e3u, "int3"); /* int3  */
L_005455e4:;
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x1fu))); /* and ecx, 0x1f */
    c->eax = (uint32_t)(shl32(c, c->eax, (c->ecx & 0xff))); /* shl eax, cl */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 5)); /* sar ecx, 5 */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x14u)) & c->eax)); /* test dword ptr [esi + ecx*4 + 0x14], eax */
    if (c->zf) goto L_00545642; /* je 0x545642 */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0xcu))); /* fld dword ptr [esi + 0xc] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x55d108u))); FPOP(c); /* fcomp dword ptr [0x1001d108] */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x18u)) & c->eax)); /* test dword ptr [esi + ecx*4 + 0x18], eax */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    if (c->zf) goto L_0054562a; /* je 0x54562a */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x44u)); /* test ah, 0x44 */
    if (!PF(c)) goto L_0054561f; /* jnp 0x54561f */
    FPUSH(c, (double)RF32((uint32_t)(0x55d104u))); /* fld dword ptr [0x1001d104] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esi + 0x10u))); /* fsub dword ptr [esi + 0x10] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
L_0054561f:;
    FPUSH(c, (double)RF32((uint32_t)(0x55d108u))); /* fld dword ptr [0x1001d108] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
L_0054562a:;
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x44u)); /* test ah, 0x44 */
    if (!PF(c)) goto L_00545637; /* jnp 0x545637 */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x10u))); /* fld dword ptr [esi + 0x10] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
L_00545637:;
    FPUSH(c, (double)RF32((uint32_t)(0x55d104u))); /* fld dword ptr [0x1001d104] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
L_00545642:;
    FPUSH(c, (double)RF32((uint32_t)(0x55d104u))); /* fld dword ptr [0x1001d104] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00545650(CPU *c) { /* FUN_10005650 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0xcu))); /* fld dword ptr [esi + 0xc] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x55d108u))); FPOP(c); /* fcomp dword ptr [0x1001d108] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x44u)); /* test ah, 0x44 */
    if (!PF(c)) goto L_005456f1; /* jnp 0x5456f1 */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x8u))); /* fild dword ptr [esp + 8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x55d1b8u))); /* fmul dword ptr [0x1001d1b8] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x8u))); /* fadd dword ptr [esi + 8] */
    WF32((uint32_t)(c->esi + 0x8u), (float)ST(0)); /* fst dword ptr [esi + 8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0xcu))); /* fmul dword ptr [esi + 0xc] */
    WF32((uint32_t)(c->esi + 0x10u), (float)ST(0)); /* fst dword ptr [esi + 0x10] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x55d104u))); FPOP(c); /* fcomp dword ptr [0x1001d104] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00545693; /* jne 0x545693 */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [esi + 0x10], 0x3f800000 */
L_00545693:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
L_00545696:;
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x1fu))); /* and ecx, 0x1f */
    c->eax = (uint32_t)(shl32(c, c->eax, (c->ecx & 0xff))); /* shl eax, cl */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 5)); /* sar ecx, 5 */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x14u)) & c->eax)); /* test dword ptr [esi + ecx*4 + 0x14], eax */
    if (c->zf) goto L_005456d9; /* je 0x5456d9 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x18u))); /* mov edx, dword ptr [esi + ecx*4 + 0x18] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->edx)); /* test eax, edx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (c->zf) goto L_005456c9; /* je 0x5456c9 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4u)); PUSH32(c, 0x005456beu); call_indirect(c, t_); } /* call dword ptr [eax + 4] */
    FPUSH(c, (double)RF32((uint32_t)(0x55d104u))); /* fld dword ptr [0x1001d104] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esi + 0x10u))); /* fsub dword ptr [esi + 0x10] */
    goto L_005456d1; /* jmp 0x5456d1 */
L_005456c9:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x4u)); PUSH32(c, 0x005456ceu); call_indirect(c, t_); } /* call dword ptr [edx + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x10u))); /* fld dword ptr [esi + 0x10] */
L_005456d1:;
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x38u))); /* fmul dword ptr [eax + 0x38] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x38u)); /* add eax, 0x38 */
    WF32((uint32_t)(c->eax), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax] */
L_005456d9:;
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->edi, (uint32_t)0x8u); /* cmp edi, 8 */
    if ((c->sf != c->of)) goto L_00545696; /* jl 0x545696 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    (void)sub32(c, c->eax, (uint32_t)0x3f800000u); /* cmp eax, 0x3f800000 */
    if (!c->zf) goto L_005456f1; /* jne 0x5456f1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x005456f1u); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
L_005456f1:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00545700(CPU *c) { /* PTR_00545700 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x4u))); /* mov al, byte ptr [esp + 4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x55d2f4u)); /* mov dword ptr [esi], 0x1001d2f4 */
    if (c->zf) goto L_0054571a; /* je 0x54571a */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00545717u); f_00543960(c); /* call 0x543960 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_0054571a:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00545720(CPU *c) { /* PTR_00545720 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->eax = (uint32_t)((uint32_t)(c->edx + 0x3cu)); /* lea eax, [edx + 0x3c] */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
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
    c->ecx = (uint32_t)((uint32_t)(c->edx + 0x7cu)); /* lea ecx, [edx + 0x7c] */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 4], ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
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
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W32((uint32_t)(c->edx), (uint32_t)((uint32_t)0x55d320u)); /* mov dword ptr [edx], 0x1001d320 */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [edx + 4], eax */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [edx + 8], eax */
    W32((uint32_t)(c->edx + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [edx + 0xc], eax */
    W32((uint32_t)(c->edx + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [edx + 0x10], eax */
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_005457c0(CPU *c) { /* FUN_100057c0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x55d320u)); /* mov dword ptr [esi], 0x1001d320 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_005457d9; /* je 0x5457d9 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x005457d6u); f_00543960(c); /* call 0x543960 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_005457d9:;
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov esi, dword ptr [esi + 0xc] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_005457e9; /* je 0x5457e9 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x005457e6u); f_00543960(c); /* call 0x543960 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_005457e9:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_005457f0(CPU *c) { /* FUN_100057f0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00545804; /* je 0x545804 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00545801u); f_00543960(c); /* call 0x543960 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00545804:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00545814; /* je 0x545814 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00545811u); f_00543960(c); /* call 0x543960 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00545814:;
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ebp, dword ptr [esp + 0xc] */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 8], 0 */
    (void)logic32(c, (uint32_t)(c->ebp & c->ebp)); /* test ebp, ebp */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 0xc], 0 */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->ebp)); /* mov dword ptr [esi + 0x10], ebp */
    if ((!c->zf && c->sf == c->of)) goto L_00545839; /* jg 0x545839 */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 0x10], 0 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 16; return; /* ret 0xc */
L_00545839:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x34u; PUSH32(c, v_); } /* push 0x34 */
    c->eax = (uint32_t)((uint32_t)(c->ebp * 8)); /* lea eax, [ebp*8] */
    { uint32_t v_ = 0x55ffecu; PUSH32(c, v_); } /* push 0x1001ffec */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0054584eu); f_00543940(c); /* call 0x543940 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 3)); /* shl ecx, 3 */
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 8], edi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u))); /* and ecx, 3 */
    while (c->ecx) { W8(c->edi, (uint8_t)((uint8_t)c->eax)); c->edi += (c->df ? -1 : 1); c->ecx--; } /* rep stosb byte ptr es:[edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x18u))); /* mov al, byte ptr [esp + 0x18] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_005458a9; /* je 0x5458a9 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + c->ebp * 2)); /* lea eax, [ebp + ebp*2] */
    { uint32_t v_ = 0x3eu; PUSH32(c, v_); } /* push 0x3e */
    c->eax = (uint32_t)(shl32(c, c->eax, 2)); /* shl eax, 2 */
    { uint32_t v_ = 0x55ffecu; PUSH32(c, v_); } /* push 0x1001ffec */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00545888u); f_00543940(c); /* call 0x543940 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0xc], edi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea ecx, [eax + eax*2] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 2)); /* shl ecx, 2 */
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u))); /* and ecx, 3 */
    while (c->ecx) { W8(c->edi, (uint8_t)((uint8_t)c->eax)); c->edi += (c->df ? -1 : 1); c->ecx--; } /* rep stosb byte ptr es:[edi], al */
L_005458a9:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x14u)); /* add esi, 0x14 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    W32((uint32_t)(c->esi), (uint32_t)(c->ecx)); /* mov dword ptr [esi], ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov edx, dword ptr [eax + 4] */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 4], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 8], eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 16; return; /* ret 0xc */
}

void f_005458d0(CPU *c) { /* FUN_100058d0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    (void)sub32(c, c->eax, R32((uint32_t)(c->edi + 0x10u))); /* cmp eax, dword ptr [edi + 0x10] */
    if (c->zf) goto L_005458fd; /* je 0x5458fd */
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    { uint32_t v_ = 0x560020u; PUSH32(c, v_); } /* push 0x10020020 */
    { uint32_t v_ = 0x47u; PUSH32(c, v_); } /* push 0x47 */
    { uint32_t v_ = 0x55ffecu; PUSH32(c, v_); } /* push 0x1001ffec */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x005458f9u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x005458fcu, "int3"); /* int3  */
L_005458fd:;
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov esi, dword ptr [esp + 0xc] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_00545925; /* jne 0x545925 */
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    { uint32_t v_ = 0x560018u; PUSH32(c, v_); } /* push 0x10020018 */
    { uint32_t v_ = 0x48u; PUSH32(c, v_); } /* push 0x48 */
    { uint32_t v_ = 0x55ffecu; PUSH32(c, v_); } /* push 0x1001ffec */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00545921u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00545924u, "int3"); /* int3  */
L_00545925:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0xcu))); /* mov eax, dword ptr [edi + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_0054594c; /* jne 0x54594c */
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    { uint32_t v_ = 0x560014u; PUSH32(c, v_); } /* push 0x10020014 */
    { uint32_t v_ = 0x49u; PUSH32(c, v_); } /* push 0x49 */
    { uint32_t v_ = 0x55ffecu; PUSH32(c, v_); } /* push 0x1001ffec */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00545948u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x0054594bu, "int3"); /* int3  */
L_0054594c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x10u))); /* mov eax, dword ptr [edi + 0x10] */
    c->edi = (uint32_t)(R32((uint32_t)(c->edi + 0xcu))); /* mov edi, dword ptr [edi + 0xc] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea ecx, [eax + eax*2] */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 2)); /* shl ecx, 2 */
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u))); /* and ecx, 3 */
    while (c->ecx) { W8(c->edi, R8(c->esi)); c->esi += (c->df ? -1 : 1); c->edi += (c->df ? -1 : 1); c->ecx--; } /* rep movsb byte ptr es:[edi], byte ptr [esi] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 12; return; /* ret 8 */
}

void f_00545970(CPU *c) { /* FUN_10005970 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov ebp, dword ptr [esp + 0x18] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    (void)sub32(c, c->ebp, R32((uint32_t)(c->edi + 0x10u))); /* cmp ebp, dword ptr [edi + 0x10] */
    if (c->zf) goto L_005459a2; /* je 0x5459a2 */
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    { uint32_t v_ = 0x560110u; PUSH32(c, v_); } /* push 0x10020110 */
    { uint32_t v_ = 0x58u; PUSH32(c, v_); } /* push 0x58 */
    { uint32_t v_ = 0x55ffecu; PUSH32(c, v_); } /* push 0x1001ffec */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x0054599eu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x005459a1u, "int3"); /* int3  */
L_005459a2:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov ebx, dword ptr [esp + 0x1c] */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (!c->zf) goto L_005459ca; /* jne 0x5459ca */
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    { uint32_t v_ = 0x560108u; PUSH32(c, v_); } /* push 0x10020108 */
    { uint32_t v_ = 0x59u; PUSH32(c, v_); } /* push 0x59 */
    { uint32_t v_ = 0x55ffecu; PUSH32(c, v_); } /* push 0x1001ffec */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x005459c6u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x005459c9u, "int3"); /* int3  */
L_005459ca:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_005459f1; /* jne 0x5459f1 */
    c->eax = (uint32_t)(R32((uint32_t)(0x564bc8u))); /* mov eax, dword ptr [0x10024bc8] */
    { uint32_t v_ = 0x560104u; PUSH32(c, v_); } /* push 0x10020104 */
    { uint32_t v_ = 0x5au; PUSH32(c, v_); } /* push 0x5a */
    { uint32_t v_ = 0x55ffecu; PUSH32(c, v_); } /* push 0x1001ffec */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x55f08cu; PUSH32(c, v_); } /* push 0x1001f08c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x005459edu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x005459f0u, "int3"); /* int3  */
L_005459f1:;
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    (void)logic32(c, (uint32_t)(c->ebp & c->ebp)); /* test ebp, ebp */
    if ((c->zf || c->sf != c->of)) goto L_00545bd0; /* jle 0x545bd0 */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x8u)); /* add ebx, 8 */
L_005459fe:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0xfffffff8u))); /* mov edx, dword ptr [ebx - 8] */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x20], edx */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x20u))); /* fld dword ptr [esp + 0x20] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x55d330u))); FPOP(c); /* fcomp dword ptr [0x1001d330] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00545a20; /* jp 0x545a20 */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)((uint32_t)0xbf800000u)); /* mov dword ptr [esp + 0x20], 0xbf800000 */
    goto L_00545a3b; /* jmp 0x545a3b */
L_00545a20:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x20u))); /* fld dword ptr [esp + 0x20] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x55d104u))); FPOP(c); /* fcomp dword ptr [0x1001d104] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00545a4e; /* jne 0x545a4e */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [esp + 0x20], 0x3f800000 */
L_00545a3b:;
    c->eax = (uint32_t)(R32((uint32_t)(0x564cecu))); /* mov eax, dword ptr [0x10024cec] */
    { uint32_t v_ = 0x5600d0u; PUSH32(c, v_); } /* push 0x100200d0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x00545a4bu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
L_00545a4e:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0xfffffffcu))); /* mov edx, dword ptr [ebx - 4] */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x1c], edx */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fld dword ptr [esp + 0x1c] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x55d330u))); FPOP(c); /* fcomp dword ptr [0x1001d330] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00545a70; /* jp 0x545a70 */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)((uint32_t)0xbf800000u)); /* mov dword ptr [esp + 0x1c], 0xbf800000 */
    goto L_00545a8b; /* jmp 0x545a8b */
L_00545a70:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fld dword ptr [esp + 0x1c] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x55d104u))); FPOP(c); /* fcomp dword ptr [0x1001d104] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00545a9e; /* jne 0x545a9e */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [esp + 0x1c], 0x3f800000 */
L_00545a8b:;
    c->eax = (uint32_t)(R32((uint32_t)(0x564cecu))); /* mov eax, dword ptr [0x10024cec] */
    { uint32_t v_ = 0x56009cu; PUSH32(c, v_); } /* push 0x1002009c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x00545a9bu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
L_00545a9e:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov edx, dword ptr [ebx] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x10], edx */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x55d330u))); FPOP(c); /* fcomp dword ptr [0x1001d330] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00545abf; /* jp 0x545abf */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0xbf800000u)); /* mov dword ptr [esp + 0x10], 0xbf800000 */
    goto L_00545ada; /* jmp 0x545ada */
L_00545abf:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x55d104u))); FPOP(c); /* fcomp dword ptr [0x1001d104] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00545aed; /* jne 0x545aed */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [esp + 0x10], 0x3f800000 */
L_00545ada:;
    c->eax = (uint32_t)(R32((uint32_t)(0x564cecu))); /* mov eax, dword ptr [0x10024cec] */
    { uint32_t v_ = 0x560068u; PUSH32(c, v_); } /* push 0x10020068 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x00545aeau); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
L_00545aed:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov edx, dword ptr [ebx + 4] */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x14], edx */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x55d330u))); FPOP(c); /* fcomp dword ptr [0x1001d330] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00545b0f; /* jp 0x545b0f */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0xbf800000u)); /* mov dword ptr [esp + 0x14], 0xbf800000 */
    goto L_00545b2a; /* jmp 0x545b2a */
L_00545b0f:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x55d104u))); FPOP(c); /* fcomp dword ptr [0x1001d104] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00545b3d; /* jne 0x545b3d */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [esp + 0x14], 0x3f800000 */
L_00545b2a:;
    c->eax = (uint32_t)(R32((uint32_t)(0x564cecu))); /* mov eax, dword ptr [0x10024cec] */
    { uint32_t v_ = 0x560034u; PUSH32(c, v_); } /* push 0x10020034 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x00545b3au); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
L_00545b3d:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x20u))); /* fld dword ptr [esp + 0x20] */
    PUSH32(c, 0x00545b46u); f_00546970(c); /* call 0x546970 */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(0x55d328u))); /* fmul qword ptr [0x1001d328] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x55d324u))); /* fmul dword ptr [0x1001d324] */
    PUSH32(c, 0x00545b57u); f_005466b0(c); /* call 0x5466b0 */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov edx, dword ptr [edi + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fld dword ptr [esp + 0x1c] */
    W16((uint32_t)(c->edx + c->esi * 8), (uint16_t)(((uint16_t)c->eax))); /* mov word ptr [edx + esi*8], ax */
    PUSH32(c, 0x00545b67u); f_00546970(c); /* call 0x546970 */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(0x55d328u))); /* fmul qword ptr [0x1001d328] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x55d324u))); /* fmul dword ptr [0x1001d324] */
    PUSH32(c, 0x00545b78u); f_005466b0(c); /* call 0x5466b0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov ecx, dword ptr [edi + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    W16((uint32_t)(c->ecx + c->esi * 8 + 0x2u), (uint16_t)(((uint16_t)c->eax))); /* mov word ptr [ecx + esi*8 + 2], ax */
    PUSH32(c, 0x00545b89u); f_00546970(c); /* call 0x546970 */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(0x55d328u))); /* fmul qword ptr [0x1001d328] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x55d324u))); /* fmul dword ptr [0x1001d324] */
    PUSH32(c, 0x00545b9au); f_005466b0(c); /* call 0x5466b0 */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov edx, dword ptr [edi + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    W16((uint32_t)(c->edx + c->esi * 8 + 0x4u), (uint16_t)(((uint16_t)c->eax))); /* mov word ptr [edx + esi*8 + 4], ax */
    PUSH32(c, 0x00545babu); f_00546970(c); /* call 0x546970 */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(0x55d328u))); /* fmul qword ptr [0x1001d328] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x55d324u))); /* fmul dword ptr [0x1001d324] */
    PUSH32(c, 0x00545bbcu); f_005466b0(c); /* call 0x5466b0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov ecx, dword ptr [edi + 8] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x10u)); /* add ebx, 0x10 */
    (void)sub32(c, c->esi, c->ebp); /* cmp esi, ebp */
    W16((uint32_t)(c->ecx + c->esi * 8 + 0xfffffffeu), (uint16_t)(((uint16_t)c->eax))); /* mov word ptr [ecx + esi*8 - 2], ax */
    if ((c->sf != c->of)) goto L_005459fe; /* jl 0x5459fe */
L_00545bd0:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->esp += 12; return; /* ret 8 */
}

void f_00545be0(CPU *c) { /* FUN_10005be0 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x58u)); /* sub esp, 0x58 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00545d1e; /* je 0x545d1e */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00545d1e; /* je 0x545d1e */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x1cu)); /* lea eax, [esp + 0x1c] */
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
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    c->ecx = (uint32_t)((uint32_t)(int32_t)(int16_t)R16((uint32_t)(c->eax))); /* movsx ecx, word ptr [eax] */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 8], ecx */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x8u))); /* fild dword ptr [esp + 8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x55d338u))); /* fmul dword ptr [0x1001d338] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x55d334u))); /* fmul dword ptr [0x1001d334] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
    c->edx = (uint32_t)((uint32_t)(int32_t)(int16_t)R16((uint32_t)(c->eax + 0x2u))); /* movsx edx, word ptr [eax + 2] */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 8], edx */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x8u))); /* fild dword ptr [esp + 8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x55d338u))); /* fmul dword ptr [0x1001d338] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x55d334u))); /* fmul dword ptr [0x1001d334] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    c->ecx = (uint32_t)((uint32_t)(int32_t)(int16_t)R16((uint32_t)(c->eax + 0x4u))); /* movsx ecx, word ptr [eax + 4] */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 8], ecx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x20u)); /* lea ecx, [esp + 0x20] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x8u))); /* fild dword ptr [esp + 8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x55d338u))); /* fmul dword ptr [0x1001d338] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x55d334u))); /* fmul dword ptr [0x1001d334] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
    c->edx = (uint32_t)((uint32_t)(int32_t)(int16_t)R16((uint32_t)(c->eax + 0x6u))); /* movsx edx, word ptr [eax + 6] */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 8], edx */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x10u)); /* lea eax, [esp + 0x10] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x8u))); /* fild dword ptr [esp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x55d338u))); /* fmul dword ptr [0x1001d338] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x55d334u))); /* fmul dword ptr [0x1001d334] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    WF32((uint32_t)(c->esp + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x24] */
    PUSH32(c, 0x00545cc8u); f_0054f68a(c); /* call 0x54f68a */
    c->edx = (uint32_t)((uint32_t)(c->esi + 0x14u)); /* lea edx, [esi + 0x14] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx))); /* mov eax, dword ptr [edx] */
    W32((uint32_t)(c->esp + 0x4cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x4c], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov ecx, dword ptr [edx + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov edx, dword ptr [edx + 8] */
    W32((uint32_t)(c->esp + 0x50u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x50], ecx */
    W32((uint32_t)(c->esp + 0x54u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x54], edx */
    if (c->zf) goto L_00545cfd; /* je 0x545cfd */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x7cu)); /* add eax, 0x7c */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x7cu)); /* lea ecx, [esi + 0x7c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x20u)); /* lea eax, [esp + 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00545cf8u); f_00543250(c); /* call 0x543250 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x58u)); /* add esp, 0x58 */
    c->esp += 4; return; /* ret  */
L_00545cfd:;
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x1cu)); /* lea ecx, [esp + 0x1c] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x7cu)); /* add esi, 0x7c */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 8], ecx */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0xc], esi */
    c->df = 0; /* cld  */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edi, dword ptr [esp + 0xc] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    c->ecx = (uint32_t)((uint32_t)0x10u); /* mov ecx, 0x10 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_00545d1e:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x58u)); /* add esp, 0x58 */
    c->esp += 4; return; /* ret  */
}

void f_00545d30(CPU *c) { /* FUN_10005d30 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x10u))); /* mov eax, dword ptr [ecx + 0x10] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x20u)); /* sub esp, 0x20 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    if ((c->zf || c->sf != c->of)) goto L_00545f2c; /* jle 0x545f2c */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov edx, dword ptr [esp + 0x28] */
    (void)sub32(c, c->edx, c->eax); /* cmp edx, eax */
    c->esi = (uint32_t)((uint32_t)(c->edx + 0x1u)); /* lea esi, [edx + 1] */
    if ((c->sf == c->of)) goto L_00545ea5; /* jge 0x545ea5 */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if ((c->sf == c->of)) goto L_00545ea5; /* jge 0x545ea5 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov eax, dword ptr [ecx + 8] */
    c->ecx = (uint32_t)((uint32_t)(int32_t)(int16_t)R16((uint32_t)(c->eax + c->edx * 8))); /* movsx ecx, word ptr [eax + edx*8] */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x28], ecx */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x28u))); /* fild dword ptr [esp + 0x28] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x55d338u))); /* fmul dword ptr [0x1001d338] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x55d334u))); /* fmul dword ptr [0x1001d334] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    c->ecx = (uint32_t)((uint32_t)(int32_t)(int16_t)R16((uint32_t)(c->eax + c->edx * 8 + 0x2u))); /* movsx ecx, word ptr [eax + edx*8 + 2] */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x28], ecx */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x28u))); /* fild dword ptr [esp + 0x28] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x55d338u))); /* fmul dword ptr [0x1001d338] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x55d334u))); /* fmul dword ptr [0x1001d334] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
    c->ecx = (uint32_t)((uint32_t)(int32_t)(int16_t)R16((uint32_t)(c->eax + c->edx * 8 + 0x4u))); /* movsx ecx, word ptr [eax + edx*8 + 4] */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x28], ecx */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x28u))); /* fild dword ptr [esp + 0x28] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x55d338u))); /* fmul dword ptr [0x1001d338] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x55d334u))); /* fmul dword ptr [0x1001d334] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    WF32((uint32_t)(c->esp + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1c] */
    c->edx = (uint32_t)((uint32_t)(int32_t)(int16_t)R16((uint32_t)(c->eax + c->edx * 8 + 0x6u))); /* movsx edx, word ptr [eax + edx*8 + 6] */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x28], edx */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x28u))); /* fild dword ptr [esp + 0x28] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x55d338u))); /* fmul dword ptr [0x1001d338] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x55d334u))); /* fmul dword ptr [0x1001d334] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    WF32((uint32_t)(c->esp + 0x20u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x20] */
    c->ecx = (uint32_t)((uint32_t)(int32_t)(int16_t)R16((uint32_t)(c->eax + c->esi * 8))); /* movsx ecx, word ptr [eax + esi*8] */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x28], ecx */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x28u))); /* fild dword ptr [esp + 0x28] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x55d338u))); /* fmul dword ptr [0x1001d338] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x55d334u))); /* fmul dword ptr [0x1001d334] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    WF32((uint32_t)(c->esp + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 4] */
    c->edx = (uint32_t)((uint32_t)(int32_t)(int16_t)R16((uint32_t)(c->eax + c->esi * 8 + 0x2u))); /* movsx edx, word ptr [eax + esi*8 + 2] */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x28], edx */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x28u))); /* fild dword ptr [esp + 0x28] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x55d338u))); /* fmul dword ptr [0x1001d338] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x55d334u))); /* fmul dword ptr [0x1001d334] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    WF32((uint32_t)(c->esp + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 8] */
    c->ecx = (uint32_t)((uint32_t)(int32_t)(int16_t)R16((uint32_t)(c->eax + c->esi * 8 + 0x4u))); /* movsx ecx, word ptr [eax + esi*8 + 4] */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x28], ecx */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x28u))); /* fild dword ptr [esp + 0x28] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x55d338u))); /* fmul dword ptr [0x1001d338] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x55d334u))); /* fmul dword ptr [0x1001d334] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    WF32((uint32_t)(c->esp + 0xcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xc] */
    c->edx = (uint32_t)((uint32_t)(int32_t)(int16_t)R16((uint32_t)(c->eax + c->esi * 8 + 0x6u))); /* movsx edx, word ptr [eax + esi*8 + 6] */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x28], edx */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x28u))); /* fild dword ptr [esp + 0x28] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x55d338u))); /* fmul dword ptr [0x1001d338] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x55d334u))); /* fmul dword ptr [0x1001d334] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x2cu))); /* fld dword ptr [esp + 0x2c] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x55d108u))); FPOP(c); /* fcomp dword ptr [0x1001d108] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00545e6a; /* jp 0x545e6a */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x2c], 0 */
    goto L_00545e85; /* jmp 0x545e85 */
L_00545e6a:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x2cu))); /* fld dword ptr [esp + 0x2c] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x55d104u))); FPOP(c); /* fcomp dword ptr [0x1001d104] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00545e85; /* jne 0x545e85 */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [esp + 0x2c], 0x3f800000 */
L_00545e85:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov eax, dword ptr [esp + 0x2c] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x4u)); /* lea ecx, [esp + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov eax, dword ptr [esp + 0x34] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x18u)); /* lea edx, [esp + 0x18] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00545e9eu); f_0054ffcb(c); /* call 0x54ffcb */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    c->esp += 16; return; /* ret 0xc */
L_00545ea5:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov edx, dword ptr [ecx + 8] */
    c->edx = (uint32_t)((uint32_t)(int32_t)(int16_t)R16((uint32_t)(c->edx + c->eax * 8 + 0xfffffff8u))); /* movsx edx, word ptr [edx + eax*8 - 8] */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x2c], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov edx, dword ptr [esp + 0x30] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x2cu))); /* fild dword ptr [esp + 0x2c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x55d338u))); /* fmul dword ptr [0x1001d338] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x55d334u))); /* fmul dword ptr [0x1001d334] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    WF32((uint32_t)(c->edx), (float)ST(0)); FPOP(c); /* fstp dword ptr [edx] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov esi, dword ptr [ecx + 8] */
    c->esi = (uint32_t)((uint32_t)(int32_t)(int16_t)R16((uint32_t)(c->esi + c->eax * 8 + 0xfffffffau))); /* movsx esi, word ptr [esi + eax*8 - 6] */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x2c], esi */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x2cu))); /* fild dword ptr [esp + 0x2c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x55d338u))); /* fmul dword ptr [0x1001d338] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x55d334u))); /* fmul dword ptr [0x1001d334] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    WF32((uint32_t)(c->edx + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edx + 4] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov esi, dword ptr [ecx + 8] */
    c->esi = (uint32_t)((uint32_t)(int32_t)(int16_t)R16((uint32_t)(c->esi + c->eax * 8 + 0xfffffffcu))); /* movsx esi, word ptr [esi + eax*8 - 4] */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x2c], esi */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x2cu))); /* fild dword ptr [esp + 0x2c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x55d338u))); /* fmul dword ptr [0x1001d338] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x55d334u))); /* fmul dword ptr [0x1001d334] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    WF32((uint32_t)(c->edx + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edx + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov ecx, dword ptr [ecx + 8] */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int16_t)R16((uint32_t)(c->ecx + c->eax * 8 + 0xfffffffeu))); /* movsx eax, word ptr [ecx + eax*8 - 2] */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x2c], eax */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x2cu))); /* fild dword ptr [esp + 0x2c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x55d338u))); /* fmul dword ptr [0x1001d338] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x55d334u))); /* fmul dword ptr [0x1001d334] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    WF32((uint32_t)(c->edx + 0xcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [edx + 0xc] */
L_00545f2c:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    c->esp += 16; return; /* ret 0xc */
}

void f_00545f40(CPU *c) { /* FUN_10005f40 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x55d33cu)); /* mov dword ptr [eax], 0x1001d33c */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 4], ecx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0xc], ecx */
    W32((uint32_t)(c->eax + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x10], ecx */
    W32((uint32_t)(c->eax + 0x14u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x14], ecx */
    W32((uint32_t)(c->eax + 0x18u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x18], ecx */
    c->esp += 4; return; /* ret  */
}

void f_00545f60(CPU *c) { /* FUN_10005f60 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00545f68u); f_00545f80(c); /* call 0x545f80 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00545f78; /* je 0x545f78 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00545f75u); f_00543960(c); /* call 0x543960 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00545f78:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00545f80(CPU *c) { /* FUN_10005f80 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x55d33cu)); /* mov dword ptr [esi], 0x1001d33c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00545f99; /* je 0x545f99 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00545f96u); f_00543960(c); /* call 0x543960 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00545f99:;
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov esi, dword ptr [esi + 0x10] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00545fa9; /* je 0x545fa9 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00545fa6u); f_00543960(c); /* call 0x543960 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00545fa9:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00545fb0(CPU *c) { /* FUN_10005fb0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov esi, dword ptr [esp + 0xc] */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_005460d2; /* je 0x5460d2 */
    (void)sub8(c, R8((uint32_t)(c->esi)), (uint8_t)0x0u); /* cmp byte ptr [esi], 0 */
    if (c->zf) goto L_005460d2; /* je 0x5460d2 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xcu))); /* mov eax, dword ptr [ebx + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov ecx, dword ptr [ebx + 8] */
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
    if ((c->sf != c->of)) goto L_00545ff6; /* jl 0x545ff6 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov ecx, dword ptr [ebx + 4] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x10u)); /* add eax, 0x10 */
    W32((uint32_t)(c->ebx + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 0xc], eax */
    { uint32_t v_ = 0x2du; PUSH32(c, v_); } /* push 0x2d */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea eax, [eax + eax*2] */
    { uint32_t v_ = 0x560124u; PUSH32(c, v_); } /* push 0x10020124 */
    c->eax = (uint32_t)(shl32(c, c->eax, 2)); /* shl eax, 2 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00545ff0u); f_00543980(c); /* call 0x543980 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 4], eax */
L_00545ff6:;
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->esi); /* mov edi, esi */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0xffffffffu))); /* or ecx, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    while (c->ecx) { (void)sub8(c, ((uint8_t)c->eax), R8(c->edi)); c->edi += (c->df ? -1 : 1); c->ecx--; if (c->zf) break; } /* repne scasb al, byte ptr es:[edi] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov edi, dword ptr [esp + 0x1c] */
    c->ecx = (uint32_t)((uint32_t)~c->ecx); /* not ecx */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    c->ebp = (uint32_t)(c->ecx); /* mov ebp, ecx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0xffffffffu))); /* or ecx, 0xffffffff */
    c->ebp = (uint32_t)(inc32(c, c->ebp)); /* inc ebp */
    while (c->ecx) { (void)sub8(c, ((uint8_t)c->eax), R8(c->edi)); c->edi += (c->df ? -1 : 1); c->ecx--; if (c->zf) break; } /* repne scasb al, byte ptr es:[edi] */
    c->ecx = (uint32_t)((uint32_t)~c->ecx); /* not ecx */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x18], edi */
    PUSH32(c, 0x00546020u); f_005461c0(c); /* call 0x5461c0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov ecx, dword ptr [ebx + 8] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->edx = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea edx, [ecx + ecx*2] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov ecx, dword ptr [ebx + 4] */
    W32((uint32_t)(c->ecx + c->edx * 4), (uint32_t)(c->eax)); /* mov dword ptr [ecx + edx*4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov eax, dword ptr [ebx + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x14u))); /* mov ecx, dword ptr [ebx + 0x14] */
    c->edx = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea edx, [eax + eax*2] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov eax, dword ptr [ebx + 4] */
    W32((uint32_t)(c->eax + c->edx * 4 + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + edx*4 + 4], ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov eax, dword ptr [ebx + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x14u))); /* mov edx, dword ptr [ebx + 0x14] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov ecx, dword ptr [ebx + 4] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea eax, [eax + eax*2] */
    c->edx = (uint32_t)(add32(c, c->edx, c->ebp)); /* add edx, ebp */
    W32((uint32_t)(c->ecx + c->eax * 4 + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + eax*4 + 8], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov eax, dword ptr [ebx + 8] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x18u))); /* mov ecx, dword ptr [ebx + 0x18] */
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x14u))); /* mov eax, dword ptr [ebx + 0x14] */
    c->edx = (uint32_t)((uint32_t)(c->eax + c->edi)); /* lea edx, [eax + edi] */
    c->edx = (uint32_t)(add32(c, c->edx, c->ebp)); /* add edx, ebp */
    (void)sub32(c, c->edx, c->ecx); /* cmp edx, ecx */
    if ((c->sf != c->of)) goto L_0054608c; /* jl 0x54608c */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    { uint32_t v_ = 0x3bu; PUSH32(c, v_); } /* push 0x3b */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->edi)); /* add ecx, edi */
    { uint32_t v_ = 0x560124u; PUSH32(c, v_); } /* push 0x10020124 */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->ebp + 0x400u)); /* lea eax, [ecx + ebp + 0x400] */
    W32((uint32_t)(c->ebx + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 0x18], eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x10u))); /* mov eax, dword ptr [ebx + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00546086u); f_00543980(c); /* call 0x543980 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    W32((uint32_t)(c->ebx + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 0x10], eax */
L_0054608c:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x14u))); /* mov edi, dword ptr [ebx + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x10u))); /* mov edx, dword ptr [ebx + 0x10] */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    c->edi = (uint32_t)(add32(c, c->edi, c->edx)); /* add edi, edx */
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u))); /* and ecx, 3 */
    while (c->ecx) { W8(c->edi, R8(c->esi)); c->esi += (c->df ? -1 : 1); c->edi += (c->df ? -1 : 1); c->ecx--; } /* rep movsb byte ptr es:[edi], byte ptr [esi] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x14u))); /* mov edi, dword ptr [ebx + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x10u))); /* mov edx, dword ptr [ebx + 0x10] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov esi, dword ptr [esp + 0x18] */
    c->edi = (uint32_t)(add32(c, c->edi, c->ebp)); /* add edi, ebp */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->edx)); /* add edi, edx */
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    c->eax = (uint32_t)(add32(c, c->eax, c->ebp)); /* add eax, ebp */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u))); /* and ecx, 3 */
    while (c->ecx) { W8(c->edi, R8(c->esi)); c->esi += (c->df ? -1 : 1); c->edi += (c->df ? -1 : 1); c->ecx--; } /* rep movsb byte ptr es:[edi], byte ptr [esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x14u))); /* mov ecx, dword ptr [ebx + 0x14] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    W32((uint32_t)(c->ebx + 0x14u), (uint32_t)(c->ecx)); /* mov dword ptr [ebx + 0x14], ecx */
L_005460d2:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 12; return; /* ret 8 */
}

void f_005460e0(CPU *c) { /* FUN_100060e0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov ecx, dword ptr [esi + 0xc] */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if ((c->sf == c->of)) goto L_0054610d; /* jge 0x54610d */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xc], eax */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea eax, [eax + eax*2] */
    { uint32_t v_ = 0x49u; PUSH32(c, v_); } /* push 0x49 */
    c->eax = (uint32_t)(shl32(c, c->eax, 2)); /* shl eax, 2 */
    { uint32_t v_ = 0x560124u; PUSH32(c, v_); } /* push 0x10020124 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00546107u); f_00543980(c); /* call 0x543980 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 4], eax */
L_0054610d:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x14u))); /* mov eax, dword ptr [esi + 0x14] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x18u))); /* mov ecx, dword ptr [esi + 0x18] */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if ((c->sf == c->of)) goto L_00546131; /* jge 0x546131 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov edx, dword ptr [esi + 0x10] */
    { uint32_t v_ = 0x4eu; PUSH32(c, v_); } /* push 0x4e */
    { uint32_t v_ = 0x560124u; PUSH32(c, v_); } /* push 0x10020124 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    W32((uint32_t)(c->esi + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x18], eax */
    PUSH32(c, 0x0054612bu); f_00543980(c); /* call 0x543980 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x10], eax */
L_00546131:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00546140(CPU *c) { /* FUN_10006140 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ebp, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    (void)logic32(c, (uint32_t)(c->ebp & c->ebp)); /* test ebp, ebp */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    if (c->zf) goto L_0054619a; /* je 0x54619a */
    (void)sub8(c, R8((uint32_t)(c->ebp)), (uint8_t)0x0u); /* cmp byte ptr [ebp], 0 */
    if (c->zf) goto L_0054619a; /* je 0x54619a */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x0054615au); f_005461c0(c); /* call 0x5461c0 */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x18], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_0054619a; /* jle 0x54619a */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
L_0054616c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ecx, dword ptr [esp + 0x14] */
    c->eax = (uint32_t)(add32(c, c->eax, c->ebx)); /* add eax, ebx */
    (void)sub32(c, R32((uint32_t)(c->eax)), c->ecx); /* cmp dword ptr [eax], ecx */
    if (!c->zf) goto L_0054618f; /* jne 0x54618f */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov edx, dword ptr [eax + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x00546188u); f_0054dbf0(c); /* call 0x54dbf0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_005461a3; /* je 0x5461a3 */
L_0054618f:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0xcu)); /* add ebx, 0xc */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if ((c->sf != c->of)) goto L_0054616c; /* jl 0x54616c */
L_0054619a:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
L_005461a3:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    c->eax = (uint32_t)((uint32_t)(c->edi + c->edi * 2)); /* lea eax, [edi + edi*2] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + c->eax * 4 + 0x8u))); /* mov eax, dword ptr [ecx + eax*4 + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
}

void f_005461c0(CPU *c) { /* FUN_100061c0 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov cl, byte ptr [edx] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_005461fd; /* je 0x5461fd */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
L_005461cd:;
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x41u); /* cmp cl, 0x41 */
    if ((c->sf != c->of)) goto L_005461db; /* jl 0x5461db */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x5au); /* cmp cl, 0x5a */
    if ((!c->zf && c->sf == c->of)) goto L_005461db; /* jg 0x5461db */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(add8(c, ((uint8_t)c->ecx), (uint8_t)0x20u)); /* add cl, 0x20 */
L_005461db:;
    c->ecx = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ecx)); /* movsx ecx, cl */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0xf0000000u))); /* and ecx, 0xf0000000 */
    if (c->zf) goto L_005461f6; /* je 0x5461f6 */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->esi = (uint32_t)(shr32(c, c->esi, 24)); /* shr esi, 0x18 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi ^ c->ecx))); /* xor esi, ecx */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ c->esi))); /* xor eax, esi */
L_005461f6:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov cl, byte ptr [edx] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_005461cd; /* jne 0x5461cd */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_005461fd:;
    c->esp += 4; return; /* ret  */
}

void f_00546200(CPU *c) { /* FUN_10006200 */
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
    { uint32_t t_ = c->eax; switch (t_) {  default: jump_indirect(c, t_, 0x0054622bu); return; } } /* jmp eax */
}

void f_0054622d(CPU *c) { /* PTR_0054622d */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 12; return; /* ret 8 */
}

void f_00546234(CPU *c) { /* FUN_10006234 */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { guest_lock(); { uint32_t t0_ = R32((uint32_t)(c->esp)), t1_ = c->eax; W32((uint32_t)(c->esp), (uint32_t)(t1_)); c->eax = (uint32_t)(t0_); } guest_unlock(); } /* xchg dword ptr [esp], eax */
    { uint32_t t_ = c->eax; switch (t_) {  default: jump_indirect(c, t_, 0x00546239u); return; } } /* jmp eax */
}

void f_0054623b(CPU *c) { /* FUN_1000623b */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { guest_lock(); { uint32_t t0_ = R32((uint32_t)(c->esp)), t1_ = c->eax; W32((uint32_t)(c->esp), (uint32_t)(t1_)); c->eax = (uint32_t)(t0_); } guest_unlock(); } /* xchg dword ptr [esp], eax */
    { uint32_t t_ = c->eax; switch (t_) {  default: jump_indirect(c, t_, 0x00546240u); return; } } /* jmp eax */
}

void f_00546242(CPU *c) { /* FUN_10006242 */
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
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x54626au)); /* mov dword ptr [ebp - 4], 0x1000626a */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x0054626au); f_0055c458(c); /* call 0x55c458 */
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

void f_0054626a(CPU *c) { /* PTR_0054626a */
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

void f_00546291(CPU *c) { /* FUN_10006291 */
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
    PUSH32(c, 0x005462b7u); f_00546be4(c); /* call 0x546be4 */
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

void f_005462c7(CPU *c) { /* FUN_100062c7 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x14u)); /* sub esp, 0x14 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffecu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x14], 0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)((uint32_t)0x54631bu)); /* mov dword ptr [ebp - 0x10], 0x1000631b */
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
    PUSH32(c, 0x0054630cu); f_005473f0(c); /* call 0x5473f0 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->eax)); /* mov dword ptr fs:[0], eax */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0054631b(CPU *c) { /* FUN_1000631b */
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
    PUSH32(c, 0x0054633bu); f_00546be4(c); /* call 0x546be4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00546340(CPU *c) { /* FUN_10006340 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x34u)); /* sub esp, 0x34 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffd8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x28], 0 */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)((uint32_t)0x5463f6u)); /* mov dword ptr [ebp - 0x24], 0x100063f6 */
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
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)((uint32_t)0x5463c8u)); /* mov dword ptr [ebp - 0x10], 0x100063c8 */
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
    PUSH32(c, 0x005463bfu); f_005474c1(c); /* call 0x5474c1 */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x68u)); PUSH32(c, 0x005463c2u); call_indirect(c, t_); } /* call dword ptr [eax + 0x68] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffccu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x34], 0 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if (c->zf) goto L_005463e5; /* je 0x5463e5 */
    c->ebx = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov ebx, dword ptr fs:[0] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ebx, dword ptr [ebp - 0x28] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ebx)); /* mov dword ptr fs:[0], ebx */
    goto L_005463ee; /* jmp 0x5463ee */
L_005463e5:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->eax)); /* mov dword ptr fs:[0], eax */
L_005463ee:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffccu))); /* mov eax, dword ptr [ebp - 0x34] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_005463c8(CPU *c) { /* PTR_005463c8 */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if (c->zf) goto L_005463e5; /* je 0x5463e5 */
    c->ebx = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov ebx, dword ptr fs:[0] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ebx, dword ptr [ebp - 0x28] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ebx)); /* mov dword ptr fs:[0], ebx */
    goto L_005463ee; /* jmp 0x5463ee */
L_005463e5:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->eax)); /* mov dword ptr fs:[0], eax */
L_005463ee:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffccu))); /* mov eax, dword ptr [ebp - 0x34] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_005463f6(CPU *c) { /* FUN_100063f6 */
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
    if (c->zf) goto L_00546419; /* je 0x546419 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->eax + 0x24u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [eax + 0x24], 1 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_00546466; /* jmp 0x546466 */
L_00546419:;
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
    PUSH32(c, 0x00546440u); f_00546be4(c); /* call 0x546be4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x24u)), (uint32_t)0x0u); /* cmp dword ptr [eax + 0x24], 0 */
    if (!c->zf) goto L_00546457; /* jne 0x546457 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x00546457u); f_00546242(c); /* call 0x546242 */
L_00546457:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ebx, dword ptr [ebp + 0xc] */
    c->esp = (uint32_t)(R32((uint32_t)(c->ebx + 0x1cu))); /* mov esp, dword ptr [ebx + 0x1c] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ebx + 0x20u))); /* mov ebp, dword ptr [ebx + 0x20] */
    { uint32_t t_ = R32((uint32_t)(c->ebx + 0x18u)); switch (t_) {  default: jump_indirect(c, t_, 0x00546460u); return; } } /* jmp dword ptr [ebx + 0x18] */
L_00546466:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_0054646b(CPU *c) { /* FUN_1000646b */
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
    if ((c->sf != c->of)) goto L_005464c2; /* jl 0x5464c2 */
L_00546489:;
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (!c->zf) goto L_00546493; /* jne 0x546493 */
    PUSH32(c, 0x00546493u); f_00547629(c); /* call 0x547629 */
L_00546493:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi * 4)); /* lea eax, [esi + esi*4] */
    (void)sub32(c, R32((uint32_t)(c->ebx + c->eax * 4 + 0x4u)), c->ecx); /* cmp dword ptr [ebx + eax*4 + 4], ecx */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->eax * 4)); /* lea eax, [ebx + eax*4] */
    if ((c->sf == c->of)) goto L_005464a8; /* jge 0x5464a8 */
    (void)sub32(c, c->ecx, R32((uint32_t)(c->eax + 0x8u))); /* cmp ecx, dword ptr [eax + 8] */
    if ((c->zf || c->sf != c->of)) goto L_005464ad; /* jle 0x5464ad */
L_005464a8:;
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (!c->zf) goto L_005464b9; /* jne 0x5464b9 */
L_005464ad:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
L_005464b9:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    if ((c->sf == c->of)) goto L_00546489; /* jge 0x546489 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
L_005464c2:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov ecx, dword ptr [ebp + 0x14] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    W32((uint32_t)(c->ecx), (uint32_t)(c->esi)); /* mov dword ptr [ecx], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov ecx, dword ptr [ebp + 0x18] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    (void)sub32(c, c->eax, R32((uint32_t)(c->edi + 0xcu))); /* cmp eax, dword ptr [edi + 0xc] */
    if ((!c->cf && !c->zf)) goto L_005464d6; /* ja 0x5464d6 */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if ((c->cf || c->zf)) goto L_005464db; /* jbe 0x5464db */
L_005464d6:;
    PUSH32(c, 0x005464dbu); f_00547629(c); /* call 0x547629 */
L_005464db:;
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi * 4)); /* lea eax, [esi + esi*4] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->eax * 4)); /* lea eax, [ebx + eax*4] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_005464e6(CPU *c) { /* FUN_100064e6 */
    PREEMPT_POLL(c);
    PUSH32(c, 0x005464ebu); f_005464fe(c); /* call 0x5464fe */
    PUSH32(c, 0x005464f0u); f_005476cf(c); /* call 0x5476cf */
    W32((uint32_t)(0x5650fcu), (uint32_t)(c->eax)); /* mov dword ptr [0x100250fc], eax */
    PUSH32(c, 0x005464fau); f_0054767f(c); /* call 0x54767f */
    c->fpu_sw &= 0x7f00; /* fnclex  */
    c->esp += 4; return; /* ret  */
}

void f_005464fd(CPU *c) { /* PTR_005464fd */
    PREEMPT_POLL(c);
    c->esp += 4; return; /* ret  */
}

void f_005464fe(CPU *c) { /* FUN_100064fe */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x547aa8u); /* mov eax, 0x10007aa8 */
    W32((uint32_t)(0x5601bcu), (uint32_t)((uint32_t)0x547752u)); /* mov dword ptr [0x100201bc], 0x10007752 */
    W32((uint32_t)(0x5601b8u), (uint32_t)(c->eax)); /* mov dword ptr [0x100201b8], eax */
    W32((uint32_t)(0x5601c0u), (uint32_t)((uint32_t)0x5477b8u)); /* mov dword ptr [0x100201c0], 0x100077b8 */
    W32((uint32_t)(0x5601c4u), (uint32_t)((uint32_t)0x5476f8u)); /* mov dword ptr [0x100201c4], 0x100076f8 */
    W32((uint32_t)(0x5601c8u), (uint32_t)((uint32_t)0x5477a0u)); /* mov dword ptr [0x100201c8], 0x100077a0 */
    W32((uint32_t)(0x5601ccu), (uint32_t)(c->eax)); /* mov dword ptr [0x100201cc], eax */
    c->esp += 4; return; /* ret  */
}

void f_00546538(CPU *c) { /* __global_unwind2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x546550u; PUSH32(c, v_); } /* push 0x10006550 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00546550u); f_0055c458(c); /* call 0x55c458 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00546550(CPU *c) { /* PTR_00546550 */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00546558(CPU *c) { /* PTR_00546558 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->ecx + 0x4u)) & (uint32_t)0x6u)); /* test dword ptr [ecx + 4], 6 */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    if (c->zf) goto L_00546579; /* je 0x546579 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    W32((uint32_t)(c->edx), (uint32_t)(c->eax)); /* mov dword ptr [edx], eax */
    c->eax = (uint32_t)((uint32_t)0x3u); /* mov eax, 3 */
L_00546579:;
    c->esp += 4; return; /* ret  */
}

void f_0054657a(CPU *c) { /* __local_unwind2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0xfffffffeu; PUSH32(c, v_); } /* push -2 */
    { uint32_t v_ = 0x546558u; PUSH32(c, v_); } /* push 0x10006558 */
    { uint32_t v_ = R32((uint32_t)(0x0u + c->fs_base)); PUSH32(c, v_); } /* push dword ptr fs:[0] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
L_00546597:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov eax, dword ptr [esp + 0x20] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ebx, dword ptr [eax + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + 0xcu))); /* mov esi, dword ptr [eax + 0xc] */
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (c->zf) goto L_005465d4; /* je 0x5465d4 */
    (void)sub32(c, c->esi, R32((uint32_t)(c->esp + 0x24u))); /* cmp esi, dword ptr [esp + 0x24] */
    if (c->zf) goto L_005465d4; /* je 0x5465d4 */
    c->esi = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea esi, [esi + esi*2] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + c->esi * 4))); /* mov ecx, dword ptr [ebx + esi*4] */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 8], ecx */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0xc], ecx */
    (void)sub32(c, R32((uint32_t)(c->ebx + c->esi * 4 + 0x4u)), (uint32_t)0x0u); /* cmp dword ptr [ebx + esi*4 + 4], 0 */
    if (!c->zf) goto L_005465d2; /* jne 0x5465d2 */
    { uint32_t v_ = 0x101u; PUSH32(c, v_); } /* push 0x101 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + c->esi * 4 + 0x8u))); /* mov eax, dword ptr [ebx + esi*4 + 8] */
    PUSH32(c, 0x005465ceu); f_0054660e(c); /* call 0x54660e */
    { uint32_t t_ = R32((uint32_t)(c->ebx + c->esi * 4 + 0x8u)); PUSH32(c, 0x005465d2u); call_indirect(c, t_); } /* call dword ptr [ebx + esi*4 + 8] */
L_005465d2:;
    goto L_00546597; /* jmp 0x546597 */
L_005465d4:;
    { uint32_t v_ = R32(c->esp); c->esp += 4; W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(v_)); } /* pop dword ptr fs:[0] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_005465e2(CPU *c) { /* __abnormal_termination */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov ecx, dword ptr fs:[0] */
    (void)sub32(c, R32((uint32_t)(c->ecx + 0x4u)), (uint32_t)0x546558u); /* cmp dword ptr [ecx + 4], 0x10006558 */
    if (!c->zf) goto L_00546604; /* jne 0x546604 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov edx, dword ptr [ecx + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edx + 0xcu))); /* mov edx, dword ptr [edx + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->ecx + 0x8u)), c->edx); /* cmp dword ptr [ecx + 8], edx */
    if (!c->zf) goto L_00546604; /* jne 0x546604 */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
L_00546604:;
    c->esp += 4; return; /* ret  */
}

void f_00546605(CPU *c) { /* __NLG_Notify1 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ebx = (uint32_t)((uint32_t)0x560164u); /* mov ebx, 0x10020164 */
    { f_00546618(c); return; } /* jmp 0x546618 */
}

void f_0054660e(CPU *c) { /* FUN_1000660e */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ebx = (uint32_t)((uint32_t)0x560164u); /* mov ebx, 0x10020164 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebx + 8], ecx */
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 4], eax */
    W32((uint32_t)(c->ebx + 0xcu), (uint32_t)(c->ebp)); /* mov dword ptr [ebx + 0xc], ebp */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
}

void f_00546618(CPU *c) { /* PTR_00546618 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebx + 8], ecx */
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 4], eax */
    W32((uint32_t)(c->ebx + 0xcu), (uint32_t)(c->ebp)); /* mov dword ptr [ebx + 0xc], ebp */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
}

void f_00546626(CPU *c) { /* PTR_00546626 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x19u; PUSH32(c, v_); } /* push 0x19 */
    PUSH32(c, 0x0054662du); f_00546bb1(c); /* call 0x546bb1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_0054662f(CPU *c) { /* FUN_1000662f */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = 0x1bu; PUSH32(c, v_); } /* push 0x1b */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x55d344u)); /* mov dword ptr [esi], 0x1001d344 */
    PUSH32(c, 0x0054663fu); f_00547bb3(c); /* call 0x547bb3 */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov esi, dword ptr [esi + 4] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_0054664e; /* je 0x54664e */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x0054664du); f_00547c29(c); /* call 0x547c29 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_0054664e:;
    { uint32_t v_ = 0x1bu; PUSH32(c, v_); } /* push 0x1b */
    PUSH32(c, 0x00546655u); f_00547c14(c); /* call 0x547c14 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00546658(CPU *c) { /* type_info::vfunc_0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00546660u); f_0054662f(c); /* call 0x54662f */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_0054666e; /* je 0x54666e */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x0054666du); f_00543960(c); /* call 0x543960 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_0054666e:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00546674(CPU *c) { /* __CxxThrowException@8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x20u)); /* sub esp, 0x20 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esi = (uint32_t)((uint32_t)0x55d348u); /* mov esi, 0x1001d348 */
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
    { uint32_t t_ = R32((uint32_t)(0x55d0e8u)); PUSH32(c, 0x005466a8u); call_indirect(c, t_); } /* call dword ptr [0x1001d0e8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 12; return; /* ret 8 */
}

void f_005466b0(CPU *c) { /* __ftol */
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

void f_005466d7(CPU *c) { /* FUN_100066d7 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x55d368u; PUSH32(c, v_); } /* push 0x1001d368 */
    { uint32_t v_ = 0x547e10u; PUSH32(c, v_); } /* push 0x10007e10 */
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
L_0054670e:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0x10u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 0x10] */
    if (c->sf) goto L_0054671e; /* js 0x54671e */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(sub32(c, R32(a_), c->esi))); } /* sub dword ptr [ebp + 8], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, 0x0054671cu); call_indirect(c, t_); } /* call dword ptr [ebp + 0x14] */
    goto L_0054670e; /* jmp 0x54670e */
L_0054671e:;
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x1c], 1 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x0054672eu); f_0054673f(c); /* call 0x54673f */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 20; return; /* ret 0x10 */
}

void f_0054673f(CPU *c) { /* FUN_1000673f */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x1c], 0 */
    if (!c->zf) goto L_00546756; /* jne 0x546756 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00546756u); f_00546757(c); /* call 0x546757 */
L_00546756:;
    c->esp += 4; return; /* ret  */
}

void f_00546757(CPU *c) { /* FUN_10006757 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x55d378u; PUSH32(c, v_); } /* push 0x1001d378 */
    { uint32_t v_ = 0x547e10u; PUSH32(c, v_); } /* push 0x10007e10 */
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
L_00546780:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0x10u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 0x10] */
    if (c->sf) goto L_005467a0; /* js 0x5467a0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, R32((uint32_t)(c->ebp + 0xcu)))); /* sub ecx, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp + 8], ecx */
    { uint32_t t_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, 0x00546791u); call_indirect(c, t_); } /* call dword ptr [ebp + 0x14] */
    goto L_00546780; /* jmp 0x546780 */
L_005467a0:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 20; return; /* ret 0x10 */
}

void f_00546793(CPU *c) { /* PTR_00546793 */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffecu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x14] */
    PUSH32(c, 0x0054679bu); f_005467b5(c); /* call 0x5467b5 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_0054679d(CPU *c) { /* PTR_0054679d */
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

void f_005467b5(CPU *c) { /* PTR_005467b5 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xe06d7363u); /* cmp dword ptr [eax], 0xe06d7363 */
    if (c->zf) goto L_005467c6; /* je 0x5467c6 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_005467c6:;
    { f_005475c8(c); return; } /* jmp 0x5475c8 */
}

void f_005467cb(CPU *c) { /* FUN_100067cb */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x55d388u; PUSH32(c, v_); } /* push 0x1001d388 */
    { uint32_t v_ = 0x547e10u; PUSH32(c, v_); } /* push 0x10007e10 */
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
L_005467f9:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0x10u))); /* cmp eax, dword ptr [ebp + 0x10] */
    if ((c->sf == c->of)) goto L_00546814; /* jge 0x546814 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, 0x00546809u); call_indirect(c, t_); } /* call dword ptr [ebp + 0x14] */
    c->esi = (uint32_t)(add32(c, c->esi, R32((uint32_t)(c->ebp + 0xcu)))); /* add esi, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe4u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0x1c] */
    goto L_005467f9; /* jmp 0x5467f9 */
L_00546814:;
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x20], 1 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00546824u); f_00546835(c); /* call 0x546835 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 24; return; /* ret 0x14 */
}

void f_005467f9(CPU *c) { /* PTR_005467f9 */
    PREEMPT_POLL(c);
L_005467f9:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0x10u))); /* cmp eax, dword ptr [ebp + 0x10] */
    if ((c->sf == c->of)) goto L_00546814; /* jge 0x546814 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, 0x00546809u); call_indirect(c, t_); } /* call dword ptr [ebp + 0x14] */
    c->esi = (uint32_t)(add32(c, c->esi, R32((uint32_t)(c->ebp + 0xcu)))); /* add esi, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe4u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0x1c] */
    goto L_005467f9; /* jmp 0x5467f9 */
L_00546814:;
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x20], 1 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00546824u); f_00546835(c); /* call 0x546835 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 24; return; /* ret 0x14 */
}

void f_0054680c(CPU *c) { /* PTR_0054680c */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe4u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0x1c] */
    { f_005467f9(c); return; } /* jmp 0x5467f9 */
}

void f_00546835(CPU *c) { /* FUN_10006835 */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x20], 0 */
    if (!c->zf) goto L_0054684c; /* jne 0x54684c */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x0054684cu); f_00546757(c); /* call 0x546757 */
L_0054684c:;
    c->esp += 4; return; /* ret  */
}

void f_0054684d(CPU *c) { /* PTR_0054684d */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00546853u); f_00547fda(c); /* call 0x547fda */
    { uint32_t v_ = R32((uint32_t)(0x565810u)); PUSH32(c, v_); } /* push dword ptr [0x10025810] */
    PUSH32(c, 0x0054685eu); f_00548335(c); /* call 0x548335 */
    c->edx = (uint32_t)(R32((uint32_t)(0x565810u))); /* mov edx, dword ptr [0x10025810] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(0x56580cu))); /* mov ecx, dword ptr [0x1002580c] */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->esi = (uint32_t)(sub32(c, c->esi, c->edx)); /* sub esi, edx */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (!c->cf) goto L_005468b3; /* jae 0x5468b3 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x0054687cu); f_00548335(c); /* call 0x548335 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x10u)); /* add eax, 0x10 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(0x565810u)); PUSH32(c, v_); } /* push dword ptr [0x10025810] */
    PUSH32(c, 0x0054688bu); f_00548006(c); /* call 0x548006 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00546896; /* jne 0x546896 */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    goto L_005468c2; /* jmp 0x5468c2 */
L_00546896:;
    c->ecx = (uint32_t)(R32((uint32_t)(0x56580cu))); /* mov ecx, dword ptr [0x1002580c] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, R32((uint32_t)(0x565810u)))); /* sub ecx, dword ptr [0x10025810] */
    W32((uint32_t)(0x565810u), (uint32_t)(c->eax)); /* mov dword ptr [0x10025810], eax */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 2)); /* sar ecx, 2 */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->ecx * 4)); /* lea ecx, [eax + ecx*4] */
    W32((uint32_t)(0x56580cu), (uint32_t)(c->ecx)); /* mov dword ptr [0x1002580c], ecx */
L_005468b3:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    { uint32_t a_ = (uint32_t)(0x56580cu); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x4u))); } /* add dword ptr [0x1002580c], 4 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_005468c2:;
    PUSH32(c, 0x005468c7u); f_00547fe3(c); /* call 0x547fe3 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_005468cb(CPU *c) { /* PTR_005468cb */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    PUSH32(c, 0x005468d4u); f_0054684d(c); /* call 0x54684d */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->esp += 4; return; /* ret  */
}

void f_005468dd(CPU *c) { /* PTR_005468dd */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x80u; PUSH32(c, v_); } /* push 0x80 */
    PUSH32(c, 0x005468e7u); f_00548423(c); /* call 0x548423 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(0x565810u), (uint32_t)(c->eax)); /* mov dword ptr [0x10025810], eax */
    if (!c->zf) goto L_005468fe; /* jne 0x5468fe */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    PUSH32(c, 0x005468f8u); f_00546bb1(c); /* call 0x546bb1 */
    c->eax = (uint32_t)(R32((uint32_t)(0x565810u))); /* mov eax, dword ptr [0x10025810] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_005468fe:;
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [eax], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(0x565810u))); /* mov eax, dword ptr [0x10025810] */
    W32((uint32_t)(0x56580cu), (uint32_t)(c->eax)); /* mov dword ptr [0x1002580c], eax */
    c->esp += 4; return; /* ret  */
}

void f_0054690c(CPU *c) { /* FUN_1000690c */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
L_00546916:;
    (void)sub32(c, R32((uint32_t)(0x56049cu)), (uint32_t)0x1u); /* cmp dword ptr [0x1002049c], 1 */
    if ((c->zf || c->sf != c->of)) goto L_0054692e; /* jle 0x54692e */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->esi))); /* movzx eax, byte ptr [esi] */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0054692au); f_0054865b(c); /* call 0x54865b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_0054693d; /* jmp 0x54693d */
L_0054692e:;
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->esi))); /* movzx eax, byte ptr [esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x560290u))); /* mov ecx, dword ptr [0x10020290] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x8u))); /* and eax, 8 */
L_0054693d:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00546944; /* je 0x546944 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    goto L_00546916; /* jmp 0x546916 */
L_00546944:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x0054694eu); f_005485e0(c); /* call 0x5485e0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe8u)); /* lea eax, [ebp - 0x18] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0054695au); f_0054855d(c); /* call 0x54855d */
    FPUSH(c, RF64((uint32_t)(c->eax + 0x10u))); /* fld qword ptr [eax + 0x10] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00546970(CPU *c) { /* FUN_10006970 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    WF64((uint32_t)(c->esp), ST(0)); /* fst qword ptr [esp] */
    PUSH32(c, 0x0054697bu); f_00548988(c); /* call 0x548988 */
    PUSH32(c, 0x00546980u); f_0054698d(c); /* call 0x54698d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->esp += 4; return; /* ret  */
}

void f_0054698d(CPU *c) { /* FUN_1000698d */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    ; /* wait  */
    W16((uint32_t)(c->esp), c->fpu_cw); /* fnstcw word ptr [esp] */
    if (c->zf) goto L_00546a01; /* je 0x546a01 */
    (void)sub16(c, R16((uint32_t)(c->esp)), (uint16_t)0x27fu); /* cmp word ptr [esp], 0x27f */
    if (c->zf) goto L_005469a1; /* je 0x5469a1 */
    PUSH32(c, 0x005469a1u); f_00548915(c); /* call 0x548915 */
L_005469a1:;
    (void)sub32(c, c->eax, (uint32_t)0x3ff00000u); /* cmp eax, 0x3ff00000 */
    if (!c->cf) goto L_005469d3; /* jae 0x5469d3 */
    FPUSH(c, 1.0); /* fld1  */
    ST(0) = FPRES(c, ST(0) + ST(1)); /* fadd st(1) */
    FPUSH(c, 1.0); /* fld1  */
    ST(0) = FPRES(c, ST(0) - ST(2)); /* fsub st(2) */
    ST(1) = FPRES(c, ST(1) * ST(0)); FPOP(c); /* fmulp st(1) */
    ST(0) = FPRES(c, sqrt(ST(0))); /* fsqrt  */
    ST(1) = atan2(ST(1), ST(0)); FPOP(c); /* fpatan  */
L_005469b6:;
    (void)sub32(c, R32((uint32_t)(0x5650f8u)), (uint32_t)0x0u); /* cmp dword ptr [0x100250f8], 0 */
    if (!c->zf) goto L_0054899e; /* jne 0x54899e */
    c->edx = (uint32_t)((uint32_t)0xeu); /* mov edx, 0xe */
    c->ecx = (uint32_t)((uint32_t)(0x5601a0u)); /* lea ecx, [0x100201a0] */
    { f_005489ab(c); return; } /* jmp 0x5489ab */
L_005469d3:;
    if ((!c->cf && !c->zf)) goto L_00546a0f; /* ja 0x546a0f */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xfffffu))); /* and eax, 0xfffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | R32((uint32_t)(c->esp + 0x8u))))); /* or eax, dword ptr [esp + 8] */
    if (!c->zf) goto L_00546a0f; /* jne 0x546a0f */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x80000000u))); /* and ecx, 0x80000000 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, RF80((uint32_t)(0x5604bau))); /* fld xword ptr [0x100204ba] */
    if (c->zf) goto L_005469b6; /* je 0x5469b6 */
    ST(0) = -ST(0); /* fchs  */
    goto L_005469b6; /* jmp 0x5469b6 */
L_005469fa:;
    PUSH32(c, 0x005469ffu); f_0054892c(c); /* call 0x54892c */
    goto L_00546a1c; /* jmp 0x546a1c */
L_00546a01:;
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0xfffffu)); /* test eax, 0xfffff */
    if (!c->zf) goto L_005469fa; /* jne 0x5469fa */
    (void)sub32(c, R32((uint32_t)(c->esp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [esp + 8], 0 */
    if (!c->zf) goto L_005469fa; /* jne 0x5469fa */
L_00546a0f:;
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, RF80((uint32_t)(0x5604b0u))); /* fld xword ptr [0x100204b0] */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
L_00546a1c:;
    (void)sub32(c, R32((uint32_t)(0x5650f8u)), (uint32_t)0x0u); /* cmp dword ptr [0x100250f8], 0 */
    if (!c->zf) goto L_0054899e; /* jne 0x54899e */
    c->edx = (uint32_t)((uint32_t)0xeu); /* mov edx, 0xe */
    c->ecx = (uint32_t)((uint32_t)(0x5601a0u)); /* lea ecx, [0x100201a0] */
    PUSH32(c, 0x00546a39u); f_005488b7(c); /* call 0x5488b7 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->esp += 4; return; /* ret  */
L_0054899e:;
    (void)sub16(c, R16((uint32_t)(c->esp)), (uint16_t)0x27fu); /* cmp word ptr [esp], 0x27f */
    if (c->zf) goto L_005489a9; /* je 0x5489a9 */
    c->fpu_cw = R16((uint32_t)(c->esp)); fpu_sync_rounding(c); /* fldcw word ptr [esp] */
L_005489a9:;
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->esp += 4; return; /* ret  */
}

void f_00546a3b(CPU *c) { /* FUN_10006a3b */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_00546ad0; /* jne 0x546ad0 */
    { uint32_t t_ = R32((uint32_t)(0x55d090u)); PUSH32(c, 0x00546a4eu); call_indirect(c, t_); } /* call dword ptr [0x1001d090] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    W32((uint32_t)(0x565180u), (uint32_t)(c->eax)); /* mov dword ptr [0x10025180], eax */
    PUSH32(c, 0x00546a5au); f_00549249(c); /* call 0x549249 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00546a9b; /* je 0x546a9b */
    c->eax = (uint32_t)(R32((uint32_t)(0x565180u))); /* mov eax, dword ptr [0x10025180] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x565181u))); /* mov cl, byte ptr [0x10025181] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xffu))); /* and eax, 0xff */
    { uint32_t a_ = (uint32_t)(0x565180u); W32(a_, (uint32_t)(shr32(c, R32(a_), 16))); } /* shr dword ptr [0x10025180], 0x10 */
    W32((uint32_t)(0x565188u), (uint32_t)(c->eax)); /* mov dword ptr [0x10025188], eax */
    W32((uint32_t)(0x56518cu), (uint32_t)(c->ecx)); /* mov dword ptr [0x1002518c], ecx */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    W32((uint32_t)(0x565184u), (uint32_t)(c->eax)); /* mov dword ptr [0x10025184], eax */
    PUSH32(c, 0x00546a92u); f_0054743c(c); /* call 0x54743c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00546a9f; /* jne 0x546a9f */
    PUSH32(c, 0x00546a9bu); f_005492a6(c); /* call 0x5492a6 */
L_00546a9b:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00546b11; /* jmp 0x546b11 */
L_00546a9f:;
    { uint32_t t_ = R32((uint32_t)(0x55d0e4u)); PUSH32(c, 0x00546aa5u); call_indirect(c, t_); } /* call dword ptr [0x1001d0e4] */
    W32((uint32_t)(0x565814u), (uint32_t)(c->eax)); /* mov dword ptr [0x10025814], eax */
    PUSH32(c, 0x00546aafu); f_00548fa2(c); /* call 0x548fa2 */
    W32((uint32_t)(0x565104u), (uint32_t)(c->eax)); /* mov dword ptr [0x10025104], eax */
    PUSH32(c, 0x00546ab9u); f_00548a8c(c); /* call 0x548a8c */
    PUSH32(c, 0x00546abeu); f_00548d55(c); /* call 0x548d55 */
    PUSH32(c, 0x00546ac3u); f_00548c9c(c); /* call 0x548c9c */
    PUSH32(c, 0x00546ac8u); f_00547ee8(c); /* call 0x547ee8 */
    { uint32_t a_ = (uint32_t)(0x565100u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [0x10025100] */
    goto L_00546b0e; /* jmp 0x546b0e */
L_00546ad0:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->zf) goto L_00546b02; /* jne 0x546b02 */
    (void)sub32(c, R32((uint32_t)(0x565100u)), c->ecx); /* cmp dword ptr [0x10025100], ecx */
    if ((c->zf || c->sf != c->of)) goto L_00546a9b; /* jle 0x546a9b */
    { uint32_t a_ = (uint32_t)(0x565100u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [0x10025100] */
    (void)sub32(c, R32((uint32_t)(0x5651b8u)), c->ecx); /* cmp dword ptr [0x100251b8], ecx */
    if (!c->zf) goto L_00546af1; /* jne 0x546af1 */
    PUSH32(c, 0x00546af1u); f_00547f26(c); /* call 0x547f26 */
L_00546af1:;
    PUSH32(c, 0x00546af6u); f_00548c48(c); /* call 0x548c48 */
    PUSH32(c, 0x00546afbu); f_00547490(c); /* call 0x547490 */
    PUSH32(c, 0x00546b00u); f_005492a6(c); /* call 0x5492a6 */
    goto L_00546b0e; /* jmp 0x546b0e */
L_00546b02:;
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_00546b0e; /* jne 0x546b0e */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00546b0du); f_00547528(c); /* call 0x547528 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00546b0e:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00546b11:;
    c->esp += 16; return; /* ret 0xc */
}

void f_00546b14(CPU *c) { /* entry */
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
    if (!c->zf) goto L_00546b30; /* jne 0x546b30 */
    (void)sub32(c, R32((uint32_t)(0x565100u)), (uint32_t)0x0u); /* cmp dword ptr [0x10025100], 0 */
    goto L_00546b56; /* jmp 0x546b56 */
L_00546b30:;
    (void)sub32(c, c->esi, (uint32_t)0x1u); /* cmp esi, 1 */
    if (c->zf) goto L_00546b3a; /* je 0x546b3a */
    (void)sub32(c, c->esi, (uint32_t)0x2u); /* cmp esi, 2 */
    if (!c->zf) goto L_00546b5c; /* jne 0x546b5c */
L_00546b3a:;
    c->eax = (uint32_t)(R32((uint32_t)(0x565818u))); /* mov eax, dword ptr [0x10025818] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00546b4c; /* je 0x546b4c */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00546b48u); call_indirect(c, t_); } /* call eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00546b58; /* je 0x546b58 */
L_00546b4c:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00546b54u); f_00546a3b(c); /* call 0x546a3b */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
L_00546b56:;
    if (!c->zf) goto L_00546b5c; /* jne 0x546b5c */
L_00546b58:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00546baa; /* jmp 0x546baa */
L_00546b5c:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00546b64u); f_0054934e(c); /* call 0x54934e */
    (void)sub32(c, c->esi, (uint32_t)0x1u); /* cmp esi, 1 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0xc], eax */
    if (!c->zf) goto L_00546b78; /* jne 0x546b78 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00546ba7; /* jne 0x546ba7 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00546b78u); f_00546a3b(c); /* call 0x546a3b */
L_00546b78:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00546b81; /* je 0x546b81 */
    (void)sub32(c, c->esi, (uint32_t)0x3u); /* cmp esi, 3 */
    if (!c->zf) goto L_00546ba7; /* jne 0x546ba7 */
L_00546b81:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00546b89u); f_00546a3b(c); /* call 0x546a3b */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00546b90; /* jne 0x546b90 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->eax)))); } /* and dword ptr [ebp + 0xc], eax */
L_00546b90:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    if (c->zf) goto L_00546ba7; /* je 0x546ba7 */
    c->eax = (uint32_t)(R32((uint32_t)(0x565818u))); /* mov eax, dword ptr [0x10025818] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00546ba7; /* je 0x546ba7 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00546ba4u); call_indirect(c, t_); } /* call eax */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0xc], eax */
L_00546ba7:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
L_00546baa:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 16; return; /* ret 0xc */
}

void f_00546bb1(CPU *c) { /* __amsg_exit */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x56510cu))); /* mov eax, dword ptr [0x1002510c] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_00546bc8; /* je 0x546bc8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00546bcd; /* jne 0x546bcd */
    (void)sub32(c, R32((uint32_t)(0x565110u)), (uint32_t)0x1u); /* cmp dword ptr [0x10025110], 1 */
    if (!c->zf) goto L_00546bcd; /* jne 0x546bcd */
L_00546bc8:;
    PUSH32(c, 0x00546bcdu); f_00549354(c); /* call 0x549354 */
L_00546bcd:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    PUSH32(c, 0x00546bd6u); f_0054938d(c); /* call 0x54938d */
    { uint32_t v_ = 0xffu; PUSH32(c, v_); } /* push 0xff */
    { uint32_t t_ = R32((uint32_t)(0x5601a8u)); PUSH32(c, 0x00546be1u); call_indirect(c, t_); } /* call dword ptr [0x100201a8] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00546be1(CPU *c) { /* PTR_00546be1 */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00546be4(CPU *c) { /* FUN_10006be4 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov esi, dword ptr [ebp + 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)((uint32_t)0x19930520u); /* mov edi, 0x19930520 */
    (void)sub32(c, R32((uint32_t)(c->esi)), c->edi); /* cmp dword ptr [esi], edi */
    if (c->zf) goto L_00546bfa; /* je 0x546bfa */
    PUSH32(c, 0x00546bfau); f_00547629(c); /* call 0x547629 */
L_00546bfa:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + 0x4u)) & (uint8_t)0x66u)); /* test byte ptr [eax + 4], 0x66 */
    if (c->zf) goto L_00546c22; /* je 0x546c22 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x4u)), (uint32_t)0x0u); /* cmp dword ptr [esi + 4], 0 */
    if (c->zf) goto L_00546c78; /* je 0x546c78 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x1c], 0 */
    if (!c->zf) goto L_00546c78; /* jne 0x546c78 */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x00546c1du); f_00546f39(c); /* call 0x546f39 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    goto L_00546c78; /* jmp 0x546c78 */
L_00546c22:;
    (void)sub32(c, R32((uint32_t)(c->esi + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [esi + 0xc], 0 */
    if (c->zf) goto L_00546c78; /* je 0x546c78 */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xe06d7363u); /* cmp dword ptr [eax], 0xe06d7363 */
    if (!c->zf) goto L_00546c5c; /* jne 0x546c5c */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x14u)), c->edi); /* cmp dword ptr [eax + 0x14], edi */
    if ((c->cf || c->zf)) goto L_00546c5c; /* jbe 0x546c5c */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x1cu))); /* mov ecx, dword ptr [eax + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov ecx, dword ptr [ecx + 8] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00546c5c; /* je 0x546c5c */
    c->edx = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0x24u))); /* movzx edx, byte ptr [ebp + 0x24] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = c->ecx; PUSH32(c, 0x00546c57u); call_indirect(c, t_); } /* call ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    goto L_00546c7b; /* jmp 0x546c7b */
L_00546c5c:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x24u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x24] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00546c75u); f_00546c7f(c); /* call 0x546c7f */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
L_00546c78:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00546c7b:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00546c7f(CPU *c) { /* FUN_10006c7f */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffecu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp - 0x14], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x10], eax */
    if ((c->sf != c->of)) goto L_00546c9f; /* jl 0x546c9f */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov ecx, dword ptr [ebp + 0x18] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ecx + 0x4u))); /* cmp eax, dword ptr [ecx + 4] */
    if ((c->sf != c->of)) goto L_00546ca4; /* jl 0x546ca4 */
L_00546c9f:;
    PUSH32(c, 0x00546ca4u); f_00547629(c); /* call 0x547629 */
L_00546ca4:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    c->ebx = (uint32_t)((uint32_t)0xe06d7363u); /* mov ebx, 0xe06d7363 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)((uint32_t)0x19930520u); /* mov edi, 0x19930520 */
    (void)sub32(c, R32((uint32_t)(c->esi)), c->ebx); /* cmp dword ptr [esi], ebx */
    if (!c->zf) goto L_00546e07; /* jne 0x546e07 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [esi + 0x10], 3 */
    if (!c->zf) goto L_00546d24; /* jne 0x546d24 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x14u)), c->edi); /* cmp dword ptr [esi + 0x14], edi */
    if (!c->zf) goto L_00546d24; /* jne 0x546d24 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [esi + 0x1c], 0 */
    if (!c->zf) goto L_00546d24; /* jne 0x546d24 */
    PUSH32(c, 0x00546cd2u); f_005474c1(c); /* call 0x5474c1 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x6cu)), (uint32_t)0x0u); /* cmp dword ptr [eax + 0x6c], 0 */
    if (c->zf) goto L_00546e02; /* je 0x546e02 */
    PUSH32(c, 0x00546ce1u); f_005474c1(c); /* call 0x5474c1 */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + 0x6cu))); /* mov esi, dword ptr [eax + 0x6c] */
    PUSH32(c, 0x00546ce9u); f_005474c1(c); /* call 0x5474c1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x70u))); /* mov eax, dword ptr [eax + 0x70] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x10], eax */
    W8((uint32_t)(c->ebp + 0xffffffecu), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ebp - 0x14], 1 */
    PUSH32(c, 0x00546cfbu); f_005494e0(c); /* call 0x5494e0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00546d06; /* jne 0x546d06 */
    PUSH32(c, 0x00546d06u); f_00547629(c); /* call 0x547629 */
L_00546d06:;
    (void)sub32(c, R32((uint32_t)(c->esi)), c->ebx); /* cmp dword ptr [esi], ebx */
    if (!c->zf) goto L_00546e07; /* jne 0x546e07 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [esi + 0x10], 3 */
    if (!c->zf) goto L_00546d24; /* jne 0x546d24 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x14u)), c->edi); /* cmp dword ptr [esi + 0x14], edi */
    if (!c->zf) goto L_00546d24; /* jne 0x546d24 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [esi + 0x1c], 0 */
    if (!c->zf) goto L_00546d24; /* jne 0x546d24 */
    PUSH32(c, 0x00546d24u); f_00547629(c); /* call 0x547629 */
L_00546d24:;
    (void)sub32(c, R32((uint32_t)(c->esi)), c->ebx); /* cmp dword ptr [esi], ebx */
    if (!c->zf) goto L_00546e07; /* jne 0x546e07 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [esi + 0x10], 3 */
    if (!c->zf) goto L_00546e07; /* jne 0x546e07 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x14u)), c->edi); /* cmp dword ptr [esi + 0x14], edi */
    if (!c->zf) goto L_00546e07; /* jne 0x546e07 */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov edi, dword ptr [ebp - 0x10] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe8u)); /* lea eax, [ebp - 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    PUSH32(c, 0x00546d56u); f_0054646b(c); /* call 0x54646b */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
L_00546d5b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xffffffe8u))); /* cmp eax, dword ptr [ebp - 0x18] */
    if (!c->cf) goto L_00546df2; /* jae 0x546df2 */
    (void)sub32(c, R32((uint32_t)(c->ebx)), c->edi); /* cmp dword ptr [ebx], edi */
    if ((!c->zf && c->sf == c->of)) goto L_00546de7; /* jg 0x546de7 */
    (void)sub32(c, c->edi, R32((uint32_t)(c->ebx + 0x4u))); /* cmp edi, dword ptr [ebx + 4] */
    if ((!c->zf && c->sf == c->of)) goto L_00546de7; /* jg 0x546de7 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x10u))); /* mov eax, dword ptr [ebx + 0x10] */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xcu))); /* mov eax, dword ptr [ebx + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    if ((c->zf || c->sf != c->of)) goto L_00546de4; /* jle 0x546de4 */
L_00546d80:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x1cu))); /* mov eax, dword ptr [esi + 0x1c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0xcu))); /* mov eax, dword ptr [eax + 0xc] */
    c->edi = (uint32_t)((uint32_t)(c->eax + 0x4u)); /* lea edi, [eax + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    if ((c->zf || c->sf != c->of)) goto L_00546db1; /* jle 0x546db1 */
L_00546d92:;
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [esi + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->edi)); PUSH32(c, v_); } /* push dword ptr [edi] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00546d9fu); f_00546edc(c); /* call 0x546edc */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00546dc0; /* jne 0x546dc0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 8] */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff8u)), c->eax); /* cmp dword ptr [ebp - 8], eax */
    if ((!c->zf && c->sf == c->of)) goto L_00546d92; /* jg 0x546d92 */
L_00546db1:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff4u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x10u))); } /* add dword ptr [ebp + 8], 0x10 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0xc], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_00546d80; /* jg 0x546d80 */
    goto L_00546de4; /* jmp 0x546de4 */
L_00546dc0:;
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
    PUSH32(c, 0x00546de1u); f_00546fd7(c); /* call 0x546fd7 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
L_00546de4:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov edi, dword ptr [ebp - 0x10] */
L_00546de7:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x14u)); /* add ebx, 0x14 */
    goto L_00546d5b; /* jmp 0x546d5b */
L_00546df2:;
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x1cu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0x1c], 0 */
    if (c->zf) goto L_00546e02; /* je 0x546e02 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00546e00u); f_0054735b(c); /* call 0x54735b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00546e02:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00546e07:;
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x1cu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0x1c], 0 */
    if (!c->zf) goto L_00546e2d; /* jne 0x546e2d */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x24u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffff0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00546e28u); f_00546e32(c); /* call 0x546e32 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    goto L_00546e02; /* jmp 0x546e02 */
L_00546e2d:;
    { f_005475c8(c); return; } /* jmp 0x5475c8 */
}

void f_00546e32(CPU *c) { /* FUN_10006e32 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00546e3eu); f_005474c1(c); /* call 0x5474c1 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x68u)), (uint32_t)0x0u); /* cmp dword ptr [eax + 0x68], 0 */
    if (c->zf) goto L_00546e65; /* je 0x546e65 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x24u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00546e5eu); f_00546340(c); /* call 0x546340 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00546ed8; /* jne 0x546ed8 */
L_00546e65:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov edi, dword ptr [ebp + 0x1c] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    PUSH32(c, 0x00546e7cu); f_0054646b(c); /* call 0x54646b */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_00546e81:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xfffffff8u))); /* cmp eax, dword ptr [ebp - 8] */
    if (!c->cf) goto L_00546ed8; /* jae 0x546ed8 */
    (void)sub32(c, c->edi, R32((uint32_t)(c->esi))); /* cmp edi, dword ptr [esi] */
    if ((c->sf != c->of)) goto L_00546ed0; /* jl 0x546ed0 */
    (void)sub32(c, c->edi, R32((uint32_t)(c->esi + 0x4u))); /* cmp edi, dword ptr [esi + 4] */
    if ((!c->zf && c->sf == c->of)) goto L_00546ed0; /* jg 0x546ed0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0xfffffff4u))); /* mov ecx, dword ptr [eax - 0xc] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00546eaa; /* je 0x546eaa */
    (void)sub8(c, R8((uint32_t)(c->ecx + 0x8u)), (uint8_t)0x0u); /* cmp byte ptr [ecx + 8], 0 */
    if (!c->zf) goto L_00546ed0; /* jne 0x546ed0 */
L_00546eaa:;
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
    PUSH32(c, 0x00546ecdu); f_00546fd7(c); /* call 0x546fd7 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
L_00546ed0:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x14u)); /* add esi, 0x14 */
    goto L_00546e81; /* jmp 0x546e81 */
L_00546ed8:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00546edc(CPU *c) { /* FUN_10006edc */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edi, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov eax, dword ptr [edi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00546f33; /* je 0x546f33 */
    (void)sub8(c, R8((uint32_t)(c->eax + 0x8u)), (uint8_t)0x0u); /* cmp byte ptr [eax + 8], 0 */
    c->edx = (uint32_t)((uint32_t)(c->eax + 0x8u)); /* lea edx, [eax + 8] */
    if (c->zf) goto L_00546f33; /* je 0x546f33 */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (c->zf) goto L_00546f0d; /* je 0x546f0d */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x8u)); /* add ecx, 8 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00546f07u); f_00547d20(c); /* call 0x547d20 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00546f2f; /* jne 0x546f2f */
L_00546f0d:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi)) & (uint8_t)0x2u)); /* test byte ptr [esi], 2 */
    if (c->zf) goto L_00546f17; /* je 0x546f17 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edi)) & (uint8_t)0x8u)); /* test byte ptr [edi], 8 */
    if (c->zf) goto L_00546f2f; /* je 0x546f2f */
L_00546f17:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    if (c->zf) goto L_00546f26; /* je 0x546f26 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edi)) & (uint8_t)0x1u)); /* test byte ptr [edi], 1 */
    if (c->zf) goto L_00546f2f; /* je 0x546f2f */
L_00546f26:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x2u)); /* test al, 2 */
    if (c->zf) goto L_00546f33; /* je 0x546f33 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edi)) & (uint8_t)0x2u)); /* test byte ptr [edi], 2 */
    if (!c->zf) goto L_00546f33; /* jne 0x546f33 */
L_00546f2f:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00546f36; /* jmp 0x546f36 */
L_00546f33:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00546f36:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00546f39(CPU *c) { /* FUN_10006f39 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x55d398u; PUSH32(c, v_); } /* push 0x1001d398 */
    { uint32_t v_ = 0x547e10u; PUSH32(c, v_); } /* push 0x10007e10 */
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
L_00546f6b:;
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0x14u))); /* cmp esi, dword ptr [ebp + 0x14] */
    if (c->zf) goto L_00546fc5; /* je 0x546fc5 */
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if ((c->zf || c->sf != c->of)) goto L_00546f7a; /* jle 0x546f7a */
    (void)sub32(c, c->esi, R32((uint32_t)(c->edi + 0x4u))); /* cmp esi, dword ptr [edi + 4] */
    if ((c->sf != c->of)) goto L_00546f7f; /* jl 0x546f7f */
L_00546f7a:;
    PUSH32(c, 0x00546f7fu); f_00547629(c); /* call 0x547629 */
L_00546f7f:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8 + 0x4u))); /* mov eax, dword ptr [eax + esi*8 + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00546f9a; /* je 0x546f9a */
    { uint32_t v_ = 0x103u; PUSH32(c, v_); } /* push 0x103 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00546f9au); f_005473f0(c); /* call 0x5473f0 */
L_00546f9a:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    goto L_00546fba; /* jmp 0x546fba */
L_00546fba:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8))); /* mov esi, dword ptr [eax + esi*8] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x1c], esi */
    goto L_00546f6b; /* jmp 0x546f6b */
L_00546fc5:;
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebx + 8], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00546f6b(CPU *c) { /* PTR_00546f6b */
    PREEMPT_POLL(c);
L_00546f6b:;
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0x14u))); /* cmp esi, dword ptr [ebp + 0x14] */
    if (c->zf) goto L_00546fc5; /* je 0x546fc5 */
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if ((c->zf || c->sf != c->of)) goto L_00546f7a; /* jle 0x546f7a */
    (void)sub32(c, c->esi, R32((uint32_t)(c->edi + 0x4u))); /* cmp esi, dword ptr [edi + 4] */
    if ((c->sf != c->of)) goto L_00546f7f; /* jl 0x546f7f */
L_00546f7a:;
    PUSH32(c, 0x00546f7fu); f_00547629(c); /* call 0x547629 */
L_00546f7f:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8 + 0x4u))); /* mov eax, dword ptr [eax + esi*8 + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00546f9a; /* je 0x546f9a */
    { uint32_t v_ = 0x103u; PUSH32(c, v_); } /* push 0x103 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00546f9au); f_005473f0(c); /* call 0x5473f0 */
L_00546f9a:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    goto L_00546fba; /* jmp 0x546fba */
L_00546fba:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8))); /* mov esi, dword ptr [eax + esi*8] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x1c], esi */
    goto L_00546f6b; /* jmp 0x546f6b */
L_00546fc5:;
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebx + 8], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00546fa0(CPU *c) { /* PTR_00546fa0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffecu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x14] */
    PUSH32(c, 0x00546fa8u); f_005467b5(c); /* call 0x5467b5 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00546faa(CPU *c) { /* PTR_00546faa */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edi, dword ptr [ebp + 0x10] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov esi, dword ptr [ebp - 0x1c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8))); /* mov esi, dword ptr [eax + esi*8] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x1c], esi */
    { f_00546f6b(c); return; } /* jmp 0x546f6b */
}

void f_00546fd7(CPU *c) { /* FUN_10006fd7 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x20u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x20], 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov ebx, dword ptr [ebp + 0x1c] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    if (c->zf) goto L_00546ff9; /* je 0x546ff9 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00546ff6u); f_00547197(c); /* call 0x547197 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_00546ff9:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x2cu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x2c], 0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    if (!c->zf) goto L_00547005; /* jne 0x547005 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    goto L_00547008; /* jmp 0x547008 */
L_00547005:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x2cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x2c] */
L_00547008:;
    PUSH32(c, 0x0054700du); f_00546242(c); /* call 0x546242 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x24u))); /* mov esi, dword ptr [ebp + 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x0054701eu); f_00546f39(c); /* call 0x546f39 */
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
    PUSH32(c, 0x0054703fu); f_00547052(c); /* call 0x547052 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0054704d; /* je 0x54704d */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0054704du); f_00546200(c); /* call 0x546200 */
L_0054704d:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00547052(CPU *c) { /* FUN_10007052 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x55d3a8u; PUSH32(c, v_); } /* push 0x1001d3a8 */
    { uint32_t v_ = 0x547e10u; PUSH32(c, v_); } /* push 0x10007e10 */
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
    PUSH32(c, 0x00547090u); f_005474c1(c); /* call 0x5474c1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x6cu))); /* mov eax, dword ptr [eax + 0x6c] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    PUSH32(c, 0x0054709bu); f_005474c1(c); /* call 0x5474c1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x70u))); /* mov eax, dword ptr [eax + 0x70] */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    PUSH32(c, 0x005470a6u); f_005474c1(c); /* call 0x5474c1 */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    W32((uint32_t)(c->eax + 0x6cu), (uint32_t)(c->edi)); /* mov dword ptr [eax + 0x6c], edi */
    PUSH32(c, 0x005470b1u); f_005474c1(c); /* call 0x5474c1 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    W32((uint32_t)(c->eax + 0x70u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x70], ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x005470d2u); f_005462c7(c); /* call 0x5462c7 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x2c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x005470e5u); f_0054711f(c); /* call 0x54711f */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd4u))); /* mov eax, dword ptr [ebp - 0x2c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_005470e8(CPU *c) { /* PTR_005470e8 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_005470f7(CPU *c) { /* PTR_005470f7 */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffecu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x14] */
    PUSH32(c, 0x005470ffu); f_0054716d(c); /* call 0x54716d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00547101(CPU *c) { /* PTR_00547101 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffd4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x2c], 0 */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00547113u); f_0054657a(c); /* call 0x54657a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { f_005470e8(c); return; } /* jmp 0x5470e8 */
}

void f_00547119(CPU *c) { /* PTR_00547119 */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    { f_0054711f(c); return; }
}

void f_0054711f(CPU *c) { /* FUN_1000711f */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    W32((uint32_t)(c->esi + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [esi - 4], eax */
    PUSH32(c, 0x0054712au); f_005474c1(c); /* call 0x5474c1 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov ecx, dword ptr [ebp - 0x1c] */
    W32((uint32_t)(c->eax + 0x6cu), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x6c], ecx */
    PUSH32(c, 0x00547135u); f_005474c1(c); /* call 0x5474c1 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov ecx, dword ptr [ebp - 0x20] */
    W32((uint32_t)(c->eax + 0x70u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x70], ecx */
    (void)sub32(c, R32((uint32_t)(c->edi)), (uint32_t)0xe06d7363u); /* cmp dword ptr [edi], 0xe06d7363 */
    if (!c->zf) goto L_0054716c; /* jne 0x54716c */
    (void)sub32(c, R32((uint32_t)(c->edi + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [edi + 0x10], 3 */
    if (!c->zf) goto L_0054716c; /* jne 0x54716c */
    (void)sub32(c, R32((uint32_t)(c->edi + 0x14u)), (uint32_t)0x19930520u); /* cmp dword ptr [edi + 0x14], 0x19930520 */
    if (!c->zf) goto L_0054716c; /* jne 0x54716c */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_0054716c; /* jne 0x54716c */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x2c], 0 */
    if (c->zf) goto L_0054716c; /* je 0x54716c */
    PUSH32(c, 0x00547163u); f_005465e2(c); /* call 0x5465e2 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x0054716au); f_0054735b(c); /* call 0x54735b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_0054716c:;
    c->esp += 4; return; /* ret  */
}

void f_0054716d(CPU *c) { /* PTR_0054716d */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xe06d7363u); /* cmp dword ptr [eax], 0xe06d7363 */
    if (!c->zf) goto L_00547194; /* jne 0x547194 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [eax + 0x10], 3 */
    if (!c->zf) goto L_00547194; /* jne 0x547194 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x14u)), (uint32_t)0x19930520u); /* cmp dword ptr [eax + 0x14], 0x19930520 */
    if (!c->zf) goto L_00547194; /* jne 0x547194 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [eax + 0x1c], 0 */
    if (!c->zf) goto L_00547194; /* jne 0x547194 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
L_00547194:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_00547197(CPU *c) { /* FUN_10007197 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x55d3c0u; PUSH32(c, v_); } /* push 0x1001d3c0 */
    { uint32_t v_ = 0x547e10u; PUSH32(c, v_); } /* push 0x10007e10 */
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
    if (c->zf) goto L_00547340; /* je 0x547340 */
    (void)sub8(c, R8((uint32_t)(c->eax + 0x8u)), (uint8_t)0x0u); /* cmp byte ptr [eax + 8], 0 */
    if (c->zf) goto L_00547340; /* je 0x547340 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov eax, dword ptr [ecx + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00547340; /* je 0x547340 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
    c->edi = (uint32_t)((uint32_t)(c->eax + c->edx + 0xcu)); /* lea edi, [eax + edx + 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ecx)) & (uint8_t)0x8u)); /* test byte ptr [ecx], 8 */
    if (c->zf) goto L_00547234; /* je 0x547234 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x18] */
    PUSH32(c, 0x005471fdu); f_005494e0(c); /* call 0x5494e0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00547337; /* je 0x547337 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x0054720fu); f_005494fc(c); /* call 0x5494fc */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00547337; /* je 0x547337 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x18u))); /* mov eax, dword ptr [esi + 0x18] */
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov ecx, dword ptr [ebp + 0x14] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x8u)); /* add ecx, 8 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
L_00547225:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0054722bu); f_005473c2(c); /* call 0x5473c2 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    goto L_0054733c; /* jmp 0x54733c */
L_00547234:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov esi, dword ptr [ebp + 0x14] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi)) & (uint8_t)0x1u)); /* test byte ptr [esi], 1 */
    if (c->zf) goto L_0054728e; /* je 0x54728e */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    PUSH32(c, 0x00547249u); f_005494e0(c); /* call 0x5494e0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00547337; /* je 0x547337 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x0054725bu); f_005494fc(c); /* call 0x5494fc */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00547337; /* je 0x547337 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x14u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00547271u); f_00549530(c); /* call 0x549530 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x14u)), (uint32_t)0x4u); /* cmp dword ptr [esi + 0x14], 4 */
    if (!c->zf) goto L_0054733c; /* jne 0x54733c */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0054733c; /* je 0x54733c */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x8u)); /* add esi, 8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    goto L_00547225; /* jmp 0x547225 */
L_0054728e:;
    (void)sub32(c, R32((uint32_t)(c->esi + 0x18u)), (uint32_t)0x0u); /* cmp dword ptr [esi + 0x18], 0 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    if (!c->zf) goto L_005472d6; /* jne 0x5472d6 */
    PUSH32(c, 0x005472a1u); f_005494e0(c); /* call 0x5494e0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00547337; /* je 0x547337 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x005472b3u); f_005494fc(c); /* call 0x5494fc */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00547337; /* je 0x547337 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x14u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x14] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x8u)); /* add esi, 8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    PUSH32(c, 0x005472c8u); f_005473c2(c); /* call 0x5473c2 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x005472d1u); f_00549530(c); /* call 0x549530 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_0054733c; /* jmp 0x54733c */
L_005472d6:;
    PUSH32(c, 0x005472dbu); f_005494e0(c); /* call 0x5494e0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00547337; /* je 0x547337 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x005472e9u); f_005494fc(c); /* call 0x5494fc */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00547337; /* je 0x547337 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x18] */
    PUSH32(c, 0x005472f7u); f_00549518(c); /* call 0x549518 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00547337; /* je 0x547337 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi)) & (uint8_t)0x4u)); /* test byte ptr [esi], 4 */
    if (c->zf) goto L_0054731d; /* je 0x54731d */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x8u)); /* lea eax, [esi + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    PUSH32(c, 0x0054730fu); f_005473c2(c); /* call 0x5473c2 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x0054731bu); f_0054623b(c); /* call 0x54623b */
    goto L_0054733c; /* jmp 0x54733c */
L_0054731d:;
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x8u)); /* lea eax, [esi + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    PUSH32(c, 0x00547329u); f_005473c2(c); /* call 0x5473c2 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00547335u); f_00546234(c); /* call 0x546234 */
    goto L_0054733c; /* jmp 0x54733c */
L_00547337:;
    PUSH32(c, 0x0054733cu); f_00547629(c); /* call 0x547629 */
L_0054733c:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
L_00547340:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0054734f(CPU *c) { /* PTR_0054734f */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_00547353(CPU *c) { /* PTR_00547353 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { f_005475c8(c); return; } /* jmp 0x5475c8 */
}

void f_0054735b(CPU *c) { /* FUN_1000735b */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x55d3d0u; PUSH32(c, v_); } /* push 0x1001d3d0 */
    { uint32_t v_ = 0x547e10u; PUSH32(c, v_); } /* push 0x10007e10 */
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
    if (c->zf) goto L_005473a2; /* je 0x5473a2 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x1cu))); /* mov ecx, dword ptr [eax + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ecx, dword ptr [ecx + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_005473a2; /* je 0x5473a2 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = R32((uint32_t)(c->eax + 0x18u)); PUSH32(c, v_); } /* push dword ptr [eax + 0x18] */
    PUSH32(c, 0x0054739eu); f_00546234(c); /* call 0x546234 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
L_005473a2:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_005473b1(CPU *c) { /* PTR_005473b1 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xcu)), ((uint8_t)c->eax)); /* cmp byte ptr [ebp + 0xc], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(!c->zf ? 1 : 0); /* setne al */
    c->esp += 4; return; /* ret  */
}

void f_005473ba(CPU *c) { /* PTR_005473ba */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { f_005475c8(c); return; } /* jmp 0x5475c8 */
}

void f_005473c2(CPU *c) { /* FUN_100073c2 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov edx, dword ptr [ecx + 4] */
    c->eax = (uint32_t)(add32(c, c->eax, c->esi)); /* add eax, esi */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if ((c->sf != c->of)) goto L_005473e3; /* jl 0x5473e3 */
    c->esi = (uint32_t)(R32((uint32_t)(c->edx + c->esi))); /* mov esi, dword ptr [edx + esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov ecx, dword ptr [ecx + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + c->ecx))); /* mov ecx, dword ptr [esi + ecx] */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->edx)); /* add ecx, edx */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
L_005473e3:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_005473f0(CPU *c) { /* __CallSettingFrame@12 */
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
    PUSH32(c, 0x00547413u); f_00546605(c); /* call 0x546605 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00547417u); call_indirect(c, t_); } /* call eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->ebx = (uint32_t)(c->ebp); /* mov ebx, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->ebx); /* mov ebp, ebx */
    (void)sub32(c, c->ecx, (uint32_t)0x100u); /* cmp ecx, 0x100 */
    if (!c->zf) goto L_0054742f; /* jne 0x54742f */
    c->ecx = (uint32_t)((uint32_t)0x2u); /* mov ecx, 2 */
L_0054742f:;
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00547435u); f_00546605(c); /* call 0x546605 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 16; return; /* ret 0xc */
}

void f_0054743c(CPU *c) { /* FUN_1000743c */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00547442u); f_00547b1e(c); /* call 0x547b1e */
    { uint32_t t_ = R32((uint32_t)(0x55d018u)); PUSH32(c, 0x00547448u); call_indirect(c, t_); } /* call dword ptr [0x1001d018] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    W32((uint32_t)(0x5601b0u), (uint32_t)(c->eax)); /* mov dword ptr [0x100201b0], eax */
    if (c->zf) goto L_0054748c; /* je 0x54748c */
    { uint32_t v_ = 0x74u; PUSH32(c, v_); } /* push 0x74 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x0054745bu); f_00549865(c); /* call 0x549865 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_0054748c; /* je 0x54748c */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(0x5601b0u)); PUSH32(c, v_); } /* push dword ptr [0x100201b0] */
    { uint32_t t_ = R32((uint32_t)(0x55d014u)); PUSH32(c, 0x00547470u); call_indirect(c, t_); } /* call dword ptr [0x1001d014] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0054748c; /* je 0x54748c */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x0054747au); f_005474ae(c); /* call 0x5474ae */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t t_ = R32((uint32_t)(0x55d010u)); PUSH32(c, 0x00547481u); call_indirect(c, t_); } /* call dword ptr [0x1001d010] */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [esi + 4], 0xffffffff */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_0054748c:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00547490(CPU *c) { /* FUN_10007490 */
    PREEMPT_POLL(c);
    PUSH32(c, 0x00547495u); f_00547b47(c); /* call 0x547b47 */
    c->eax = (uint32_t)(R32((uint32_t)(0x5601b0u))); /* mov eax, dword ptr [0x100201b0] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (c->zf) goto L_005474ad; /* je 0x5474ad */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x55d01cu)); PUSH32(c, 0x005474a6u); call_indirect(c, t_); } /* call dword ptr [0x1001d01c] */
    { uint32_t a_ = (uint32_t)(0x5601b0u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [0x100201b0], 0xffffffff */
L_005474ad:;
    c->esp += 4; return; /* ret  */
}

void f_005474ae(CPU *c) { /* FUN_100074ae */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    W32((uint32_t)(c->eax + 0x50u), (uint32_t)((uint32_t)0x5605a0u)); /* mov dword ptr [eax + 0x50], 0x100205a0 */
    W32((uint32_t)(c->eax + 0x14u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [eax + 0x14], 1 */
    c->esp += 4; return; /* ret  */
}

void f_005474c1(CPU *c) { /* FUN_100074c1 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0x55d028u)); PUSH32(c, 0x005474c9u); call_indirect(c, t_); } /* call dword ptr [0x1001d028] */
    { uint32_t v_ = R32((uint32_t)(0x5601b0u)); PUSH32(c, v_); } /* push dword ptr [0x100201b0] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    { uint32_t t_ = R32((uint32_t)(0x55d024u)); PUSH32(c, 0x005474d7u); call_indirect(c, t_); } /* call dword ptr [0x1001d024] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_0054751c; /* jne 0x54751c */
    { uint32_t v_ = 0x74u; PUSH32(c, v_); } /* push 0x74 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x005474e6u); f_00549865(c); /* call 0x549865 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00547514; /* je 0x547514 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(0x5601b0u)); PUSH32(c, v_); } /* push dword ptr [0x100201b0] */
    { uint32_t t_ = R32((uint32_t)(0x55d014u)); PUSH32(c, 0x005474fbu); call_indirect(c, t_); } /* call dword ptr [0x1001d014] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00547514; /* je 0x547514 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00547505u); f_005474ae(c); /* call 0x5474ae */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t t_ = R32((uint32_t)(0x55d010u)); PUSH32(c, 0x0054750cu); call_indirect(c, t_); } /* call dword ptr [0x1001d010] */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [esi + 4], 0xffffffff */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    goto L_0054751c; /* jmp 0x54751c */
L_00547514:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    PUSH32(c, 0x0054751bu); f_00546bb1(c); /* call 0x546bb1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_0054751c:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0x55d020u)); PUSH32(c, 0x00547523u); call_indirect(c, t_); } /* call dword ptr [0x1001d020] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00547528(CPU *c) { /* FUN_10007528 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x5601b0u))); /* mov eax, dword ptr [0x100201b0] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (c->zf) goto L_005475c7; /* je 0x5475c7 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_0054754c; /* jne 0x54754c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x55d024u)); PUSH32(c, 0x00547546u); call_indirect(c, t_); } /* call dword ptr [0x1001d024] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_005475b8; /* je 0x5475b8 */
L_0054754c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov eax, dword ptr [esi + 0x24] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0054755a; /* je 0x54755a */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00547559u); f_00547c29(c); /* call 0x547c29 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_0054755a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x28u))); /* mov eax, dword ptr [esi + 0x28] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00547568; /* je 0x547568 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00547567u); f_00547c29(c); /* call 0x547c29 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00547568:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x30u))); /* mov eax, dword ptr [esi + 0x30] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00547576; /* je 0x547576 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00547575u); f_00547c29(c); /* call 0x547c29 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00547576:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x38u))); /* mov eax, dword ptr [esi + 0x38] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00547584; /* je 0x547584 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00547583u); f_00547c29(c); /* call 0x547c29 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00547584:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x40u))); /* mov eax, dword ptr [esi + 0x40] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00547592; /* je 0x547592 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00547591u); f_00547c29(c); /* call 0x547c29 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00547592:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x44u))); /* mov eax, dword ptr [esi + 0x44] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_005475a0; /* je 0x5475a0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0054759fu); f_00547c29(c); /* call 0x547c29 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_005475a0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    (void)sub32(c, c->eax, (uint32_t)0x5605a0u); /* cmp eax, 0x100205a0 */
    if (c->zf) goto L_005475b1; /* je 0x5475b1 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x005475b0u); f_00547c29(c); /* call 0x547c29 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_005475b1:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x005475b7u); f_00547c29(c); /* call 0x547c29 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_005475b8:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x5601b0u)); PUSH32(c, v_); } /* push dword ptr [0x100201b0] */
    { uint32_t t_ = R32((uint32_t)(0x55d014u)); PUSH32(c, 0x005475c6u); call_indirect(c, t_); } /* call dword ptr [0x1001d014] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_005475c7:;
    c->esp += 4; return; /* ret  */
}

void f_005475c8(CPU *c) { /* FUN_100075c8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x55d3e0u; PUSH32(c, v_); } /* push 0x1001d3e0 */
    { uint32_t v_ = 0x547e10u; PUSH32(c, v_); } /* push 0x10007e10 */
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
    PUSH32(c, 0x005475f7u); f_005474c1(c); /* call 0x5474c1 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x60u)), c->esi); /* cmp dword ptr [eax + 0x60], esi */
    if (c->zf) goto L_0054761b; /* je 0x54761b */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    PUSH32(c, 0x00547608u); f_005474c1(c); /* call 0x5474c1 */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x60u)); PUSH32(c, 0x0054760bu); call_indirect(c, t_); } /* call dword ptr [eax + 0x60] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 4], esi */
    goto L_0054761b; /* jmp 0x54761b */
L_0054761b:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00547624u); f_00547624(c); /* call 0x547624 */
    { f_005499a2(c); return; } /* jmp 0x5499a2 */
}

void f_00547610(CPU *c) { /* PTR_00547610 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_00547614(CPU *c) { /* PTR_00547614 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00547624u); f_00547624(c); /* call 0x547624 */
    { f_005499a2(c); return; } /* jmp 0x5499a2 */
}

void f_00547624(CPU *c) { /* PTR_00547624 */
    PREEMPT_POLL(c);
    { f_005499a2(c); return; } /* jmp 0x5499a2 */
}

void f_00547629(CPU *c) { /* FUN_10007629 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x55d3f8u; PUSH32(c, v_); } /* push 0x1001d3f8 */
    { uint32_t v_ = 0x547e10u; PUSH32(c, v_); } /* push 0x10007e10 */
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
    c->eax = (uint32_t)(R32((uint32_t)(0x5601b4u))); /* mov eax, dword ptr [0x100201b4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00547671; /* je 0x547671 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00547664u); call_indirect(c, t_); } /* call eax */
    goto L_0054766d; /* jmp 0x54766d */
L_0054766d:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
L_00547671:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x0054767au); f_0054767a(c); /* call 0x54767a */
    { f_005475c8(c); return; } /* jmp 0x5475c8 */
}

void f_00547666(CPU *c) { /* PTR_00547666 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_0054766a(CPU *c) { /* PTR_0054766a */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x0054767au); f_0054767a(c); /* call 0x54767a */
    { f_005475c8(c); return; } /* jmp 0x5475c8 */
}

void f_0054767a(CPU *c) { /* PTR_0054767a */
    PREEMPT_POLL(c);
    { f_005475c8(c); return; } /* jmp 0x5475c8 */
}

void f_0054767f(CPU *c) { /* FUN_1000767f */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x30000u; PUSH32(c, v_); } /* push 0x30000 */
    { uint32_t v_ = 0x10000u; PUSH32(c, v_); } /* push 0x10000 */
    PUSH32(c, 0x0054768eu); f_005499ee(c); /* call 0x5499ee */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00547691(CPU *c) { /* FUN_10007691 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    FPUSH(c, RF64((uint32_t)(0x55d420u))); /* fld qword ptr [0x1001d420] */
    WF64((uint32_t)(c->ebp + 0xfffffff8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 8] */
    FPUSH(c, RF64((uint32_t)(0x55d418u))); /* fld qword ptr [0x1001d418] */
    WF64((uint32_t)(c->ebp + 0xfffffff0u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0x10] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff0u))); /* fld qword ptr [ebp - 0x10] */
    ST(0) = FPRES(c, FDIV(c, ST(0), RF64((uint32_t)(c->ebp + 0xfffffff8u)))); /* fdiv qword ptr [ebp - 8] */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->ebp + 0xfffffff8u))); /* fmul qword ptr [ebp - 8] */
    ST(0) = FPRES(c, RF64((uint32_t)(c->ebp + 0xfffffff0u)) - ST(0)); /* fsubr qword ptr [ebp - 0x10] */
    WF64((uint32_t)(c->ebp + 0xffffffe8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0x18] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xffffffe8u))); /* fld qword ptr [ebp - 0x18] */
    FCOM(c, ST(0), RF64((uint32_t)(0x55d410u))); FPOP(c); /* fcomp qword ptr [0x1001d410] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if ((c->cf || c->zf)) goto L_005476cb; /* jbe 0x5476cb */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_005476cb:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_005476cf(CPU *c) { /* FUN_100076cf */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x55d444u; PUSH32(c, v_); } /* push 0x1001d444 */
    { uint32_t t_ = R32((uint32_t)(0x55d030u)); PUSH32(c, 0x005476dau); call_indirect(c, t_); } /* call dword ptr [0x1001d030] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_005476f3; /* je 0x5476f3 */
    { uint32_t v_ = 0x55d428u; PUSH32(c, v_); } /* push 0x1001d428 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x55d02cu)); PUSH32(c, 0x005476eau); call_indirect(c, t_); } /* call dword ptr [0x1001d02c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_005476f3; /* je 0x5476f3 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x005476f2u); call_indirect(c, t_); } /* call eax */
    c->esp += 4; return; /* ret  */
L_005476f3:;
    { f_00547691(c); return; } /* jmp 0x547691 */
}

void f_005476f8(CPU *c) { /* FUN_100076f8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->esi))); /* movsx eax, byte ptr [esi] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00547706u); f_00549b1f(c); /* call 0x549b1f */
    (void)sub32(c, c->eax, (uint32_t)0x65u); /* cmp eax, 0x65 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00547738; /* je 0x547738 */
L_0054770c:;
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub32(c, R32((uint32_t)(0x56049cu)), (uint32_t)0x1u); /* cmp dword ptr [0x1002049c], 1 */
    if ((c->zf || c->sf != c->of)) goto L_00547725; /* jle 0x547725 */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->esi))); /* movsx eax, byte ptr [esi] */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00547721u); f_0054865b(c); /* call 0x54865b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00547734; /* jmp 0x547734 */
L_00547725:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->esi))); /* movsx eax, byte ptr [esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x560290u))); /* mov ecx, dword ptr [0x10020290] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4u))); /* and eax, 4 */
L_00547734:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_0054770c; /* jne 0x54770c */
L_00547738:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x5604a0u))); /* mov cl, byte ptr [0x100204a0] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esi], cl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_00547743:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov cl, byte ptr [esi] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [esi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(((uint8_t)c->ecx)); /* mov al, cl */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov cl, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_00547743; /* jne 0x547743 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00547752(CPU *c) { /* PTR_00547752 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x5604a0u))); /* mov dl, byte ptr [0x100204a0] */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_0054776e; /* je 0x54776e */
L_00547762:;
    (void)sub8(c, ((uint8_t)c->ecx), ((uint8_t)c->edx)); /* cmp cl, dl */
    if (c->zf) goto L_0054776e; /* je 0x54776e */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1u))); /* mov cl, byte ptr [eax + 1] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_00547762; /* jne 0x547762 */
L_0054776e:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_0054779f; /* je 0x54779f */
L_00547775:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_00547788; /* je 0x547788 */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x65u); /* cmp cl, 0x65 */
    if (c->zf) goto L_00547788; /* je 0x547788 */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x45u); /* cmp cl, 0x45 */
    if (c->zf) goto L_00547788; /* je 0x547788 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_00547775; /* jmp 0x547775 */
L_00547788:;
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
L_0054778a:;
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x30u); /* cmp byte ptr [eax], 0x30 */
    if (c->zf) goto L_0054778a; /* je 0x54778a */
    (void)sub8(c, R8((uint32_t)(c->eax)), ((uint8_t)c->edx)); /* cmp byte ptr [eax], dl */
    if (!c->zf) goto L_00547795; /* jne 0x547795 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
L_00547795:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov dl, byte ptr [ecx] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [eax], dl */
    if (!c->zf) goto L_00547795; /* jne 0x547795 */
L_0054779f:;
    c->esp += 4; return; /* ret  */
}

void f_005477a0(CPU *c) { /* PTR_005477a0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    FPUSH(c, RF64((uint32_t)(c->eax))); /* fld qword ptr [eax] */
    FCOM(c, ST(0), RF64((uint32_t)(0x55d450u))); FPOP(c); /* fcomp qword ptr [0x1001d450] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (c->cf) goto L_005477b5; /* jb 0x5477b5 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
L_005477b5:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_005477b8(CPU *c) { /* __fassign */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    if (c->zf) goto L_005477e1; /* je 0x5477e1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x005477cfu); f_00549feb(c); /* call 0x549feb */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 4], ecx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_005477e1:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x005477eau); f_0054a018(c); /* call 0x54a018 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_005477f6(CPU *c) { /* FUN_100077f6 */
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
    PUSH32(c, 0x00547814u); f_0054a0bc(c); /* call 0x54a0bc */
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
    PUSH32(c, 0x0054783cu); f_0054a045(c); /* call 0x54a045 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x0054784eu); f_00547857(c); /* call 0x547857 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x30u)); /* add esp, 0x30 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00547857(CPU *c) { /* FUN_10007857 */
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
    if (c->zf) goto L_00547885; /* je 0x547885 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->ebx); /* cmp dword ptr [ebp + 0xc], ebx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((!c->zf && c->sf == c->of) ? 1 : 0); /* setg al */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x2du); /* cmp dword ptr [esi], 0x2d */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete al */
    c->eax = (uint32_t)(add32(c, c->eax, c->edi)); /* add eax, edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00547883u); f_00547af9(c); /* call 0x547af9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00547885:;
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x2du); /* cmp dword ptr [esi], 0x2d */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    if (!c->zf) goto L_00547892; /* jne 0x547892 */
    W8((uint32_t)(c->edi), (uint8_t)((uint8_t)0x2du)); /* mov byte ptr [edi], 0x2d */
    c->eax = (uint32_t)((uint32_t)(c->edi + 0x1u)); /* lea eax, [edi + 1] */
L_00547892:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->ebx); /* cmp dword ptr [ebp + 0xc], ebx */
    if ((c->zf || c->sf != c->of)) goto L_005478a9; /* jle 0x5478a9 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1u))); /* mov dl, byte ptr [eax + 1] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x1u)); /* lea ecx, [eax + 1] */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [eax], dl */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x5604a0u))); /* mov cl, byte ptr [0x100204a0] */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax], cl */
L_005478a9:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x18u)), ((uint8_t)c->ebx)); /* cmp byte ptr [ebp + 0x18], bl */
    { uint32_t v_ = 0x55d458u; PUSH32(c, v_); } /* push 0x1001d458 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete cl */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    c->ecx = (uint32_t)(add32(c, c->ecx, R32((uint32_t)(c->ebp + 0xcu)))); /* add ecx, dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x005478c1u); f_0054a1d0(c); /* call 0x54a1d0 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), c->ebx); /* cmp dword ptr [ebp + 0x10], ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    if (c->zf) goto L_005478cd; /* je 0x5478cd */
    W8((uint32_t)(c->ecx), (uint8_t)((uint8_t)0x45u)); /* mov byte ptr [ecx], 0x45 */
L_005478cd:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x30u); /* cmp byte ptr [eax], 0x30 */
    if (c->zf) goto L_00547912; /* je 0x547912 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ebx, dword ptr [esi + 4] */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->sf) goto L_005478e1; /* jns 0x5478e1 */
    c->ebx = (uint32_t)(neg32(c, c->ebx)); /* neg ebx */
    W8((uint32_t)(c->ecx), (uint8_t)((uint8_t)0x2du)); /* mov byte ptr [ecx], 0x2d */
L_005478e1:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->ebx, (uint32_t)0x64u); /* cmp ebx, 0x64 */
    if ((c->sf != c->of)) goto L_005478f8; /* jl 0x5478f8 */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = 0x64u; PUSH32(c, v_); } /* push 0x64 */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x005478edu, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [ecx], al */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x005478f4u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
    c->ebx = (uint32_t)(c->edx); /* mov ebx, edx */
L_005478f8:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->ebx, (uint32_t)0xau); /* cmp ebx, 0xa */
    if ((c->sf != c->of)) goto L_0054790f; /* jl 0x54790f */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = 0xau; PUSH32(c, v_); } /* push 0xa */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00547904u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [ecx], al */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x0054790bu, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
    c->ebx = (uint32_t)(c->edx); /* mov ebx, edx */
L_0054790f:;
    { uint32_t a_ = (uint32_t)(c->ecx + 0x1u); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ebx)))); } /* add byte ptr [ecx + 1], bl */
L_00547912:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00547919(CPU *c) { /* FUN_10007919 */
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
    PUSH32(c, 0x00547937u); f_0054a0bc(c); /* call 0x54a0bc */
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
    PUSH32(c, 0x00547956u); f_0054a045(c); /* call 0x54a045 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x00547965u); f_0054796e(c); /* call 0x54796e */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0054796e(CPU *c) { /* FUN_1000796e */
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
    if (c->zf) goto L_0054799e; /* je 0x54799e */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xcu))); /* cmp eax, dword ptr [ebp + 0xc] */
    if (!c->zf) goto L_0054799e; /* jne 0x54799e */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x2du); /* cmp dword ptr [esi], 0x2d */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete cl */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->ebx)); /* add ecx, ebx */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    W8((uint32_t)(c->eax), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [eax], 0x30 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x1u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax + 1], 0 */
L_0054799e:;
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x2du); /* cmp dword ptr [esi], 0x2d */
    c->edi = (uint32_t)(c->ebx); /* mov edi, ebx */
    if (!c->zf) goto L_005479ab; /* jne 0x5479ab */
    W8((uint32_t)(c->ebx), (uint8_t)((uint8_t)0x2du)); /* mov byte ptr [ebx], 0x2d */
    c->edi = (uint32_t)((uint32_t)(c->ebx + 0x1u)); /* lea edi, [ebx + 1] */
L_005479ab:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((!c->zf && c->sf == c->of)) goto L_005479c2; /* jg 0x5479c2 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x005479bau); f_00547af9(c); /* call 0x547af9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W8((uint32_t)(c->edi), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [edi], 0x30 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_005479c4; /* jmp 0x5479c4 */
L_005479c2:;
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
L_005479c4:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    if ((c->zf || c->sf != c->of)) goto L_00547a0e; /* jle 0x547a0e */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x005479d2u); f_00547af9(c); /* call 0x547af9 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x5604a0u))); /* mov al, byte ptr [0x100204a0] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov esi, dword ptr [esi + 4] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if ((c->sf == c->of)) goto L_00547a0e; /* jge 0x547a0e */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x14u)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0x14], 0 */
    if (c->zf) goto L_005479ed; /* je 0x5479ed */
    c->esi = (uint32_t)(neg32(c, c->esi)); /* neg esi */
    goto L_005479f4; /* jmp 0x5479f4 */
L_005479ed:;
    c->esi = (uint32_t)(neg32(c, c->esi)); /* neg esi */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->esi); /* cmp dword ptr [ebp + 0xc], esi */
    if ((c->sf != c->of)) goto L_005479f7; /* jl 0x5479f7 */
L_005479f4:;
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_005479f7:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00547a00u); f_00547af9(c); /* call 0x547af9 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = 0x30u; PUSH32(c, v_); } /* push 0x30 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00547a0bu); f_0054a2c0(c); /* call 0x54a2c0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
L_00547a0e:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00547a15(CPU *c) { /* FUN_10007a15 */
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
    PUSH32(c, 0x00547a35u); f_0054a0bc(c); /* call 0x54a0bc */
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
    PUSH32(c, 0x00547a57u); f_0054a045(c); /* call 0x54a045 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)((c->sf != c->of) ? 1 : 0); /* setl cl */
    (void)sub32(c, c->eax, (uint32_t)0xfffffffcu); /* cmp eax, -4 */
    if ((c->sf != c->of)) goto L_00547a8e; /* jl 0x547a8e */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if ((c->sf == c->of)) goto L_00547a8e; /* jge 0x547a8e */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_00547a7a; /* je 0x547a7a */
L_00547a70:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov al, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00547a70; /* jne 0x547a70 */
    { uint32_t a_ = (uint32_t)(c->edi + 0xfffffffeu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & ((uint8_t)c->eax))))); } /* and byte ptr [edi - 2], al */
L_00547a7a:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x00547a89u); f_0054796e(c); /* call 0x54796e */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    goto L_00547aa3; /* jmp 0x547aa3 */
L_00547a8e:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x00547aa0u); f_00547857(c); /* call 0x547857 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
L_00547aa3:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00547aa8(CPU *c) { /* __cfltcvt */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), (uint32_t)0x65u); /* cmp dword ptr [ebp + 0x10], 0x65 */
    if (c->zf) goto L_00547ae3; /* je 0x547ae3 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), (uint32_t)0x45u); /* cmp dword ptr [ebp + 0x10], 0x45 */
    if (c->zf) goto L_00547ae3; /* je 0x547ae3 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), (uint32_t)0x66u); /* cmp dword ptr [ebp + 0x10], 0x66 */
    if (!c->zf) goto L_00547ad0; /* jne 0x547ad0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00547acbu); f_00547919(c); /* call 0x547919 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
L_00547ad0:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00547ae1u); f_00547a15(c); /* call 0x547a15 */
    goto L_00547af4; /* jmp 0x547af4 */
L_00547ae3:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00547af4u); f_005477f6(c); /* call 0x5477f6 */
L_00547af4:;
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00547af9(CPU *c) { /* FUN_10007af9 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edi, dword ptr [esp + 0xc] */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00547b1c; /* je 0x547b1c */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov esi, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00547b0du); f_005485e0(c); /* call 0x5485e0 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(add32(c, c->esi, c->edi)); /* add esi, edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00547b18u); f_00549530(c); /* call 0x549530 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00547b1c:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00547b1e(CPU *c) { /* FUN_10007b1e */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(0x55d034u))); /* mov esi, dword ptr [0x1001d034] */
    { uint32_t v_ = R32((uint32_t)(0x560214u)); PUSH32(c, v_); } /* push dword ptr [0x10020214] */
    { uint32_t t_ = c->esi; PUSH32(c, 0x00547b2du); call_indirect(c, t_); } /* call esi */
    { uint32_t v_ = R32((uint32_t)(0x560204u)); PUSH32(c, v_); } /* push dword ptr [0x10020204] */
    { uint32_t t_ = c->esi; PUSH32(c, 0x00547b35u); call_indirect(c, t_); } /* call esi */
    { uint32_t v_ = R32((uint32_t)(0x5601f4u)); PUSH32(c, v_); } /* push dword ptr [0x100201f4] */
    { uint32_t t_ = c->esi; PUSH32(c, 0x00547b3du); call_indirect(c, t_); } /* call esi */
    { uint32_t v_ = R32((uint32_t)(0x5601d4u)); PUSH32(c, v_); } /* push dword ptr [0x100201d4] */
    { uint32_t t_ = c->esi; PUSH32(c, 0x00547b45u); call_indirect(c, t_); } /* call esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00547b47(CPU *c) { /* FUN_10007b47 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(0x55d038u))); /* mov edi, dword ptr [0x1001d038] */
    c->esi = (uint32_t)((uint32_t)0x5601d0u); /* mov esi, 0x100201d0 */
L_00547b54:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00547b85; /* je 0x547b85 */
    (void)sub32(c, c->esi, (uint32_t)0x560214u); /* cmp esi, 0x10020214 */
    if (c->zf) goto L_00547b85; /* je 0x547b85 */
    (void)sub32(c, c->esi, (uint32_t)0x560204u); /* cmp esi, 0x10020204 */
    if (c->zf) goto L_00547b85; /* je 0x547b85 */
    (void)sub32(c, c->esi, (uint32_t)0x5601f4u); /* cmp esi, 0x100201f4 */
    if (c->zf) goto L_00547b85; /* je 0x547b85 */
    (void)sub32(c, c->esi, (uint32_t)0x5601d4u); /* cmp esi, 0x100201d4 */
    if (c->zf) goto L_00547b85; /* je 0x547b85 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00547b7du); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    PUSH32(c, 0x00547b84u); f_00547c29(c); /* call 0x547c29 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00547b85:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, c->esi, (uint32_t)0x560290u); /* cmp esi, 0x10020290 */
    if ((c->sf != c->of)) goto L_00547b54; /* jl 0x547b54 */
    { uint32_t v_ = R32((uint32_t)(0x5601f4u)); PUSH32(c, v_); } /* push dword ptr [0x100201f4] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00547b98u); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = R32((uint32_t)(0x560204u)); PUSH32(c, v_); } /* push dword ptr [0x10020204] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00547ba0u); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = R32((uint32_t)(0x560214u)); PUSH32(c, v_); } /* push dword ptr [0x10020214] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00547ba8u); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = R32((uint32_t)(0x5601d4u)); PUSH32(c, v_); } /* push dword ptr [0x100201d4] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00547bb0u); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00547bb3(CPU *c) { /* FUN_10007bb3 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    (void)sub32(c, R32((uint32_t)(c->eax * 4 + 0x5601d0u)), (uint32_t)0x0u); /* cmp dword ptr [eax*4 + 0x100201d0], 0 */
    c->esi = (uint32_t)((uint32_t)(c->eax * 4 + 0x5601d0u)); /* lea esi, [eax*4 + 0x100201d0] */
    if (!c->zf) goto L_00547c09; /* jne 0x547c09 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    PUSH32(c, 0x00547bd3u); f_00548423(c); /* call 0x548423 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (!c->zf) goto L_00547be2; /* jne 0x547be2 */
    { uint32_t v_ = 0x11u; PUSH32(c, v_); } /* push 0x11 */
    PUSH32(c, 0x00547be1u); f_00546bb1(c); /* call 0x546bb1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00547be2:;
    { uint32_t v_ = 0x11u; PUSH32(c, v_); } /* push 0x11 */
    PUSH32(c, 0x00547be9u); f_00547bb3(c); /* call 0x547bb3 */
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x0u); /* cmp dword ptr [esi], 0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00547bfa; /* jne 0x547bfa */
    { uint32_t t_ = R32((uint32_t)(0x55d034u)); PUSH32(c, 0x00547bf6u); call_indirect(c, t_); } /* call dword ptr [0x1001d034] */
    W32((uint32_t)(c->esi), (uint32_t)(c->edi)); /* mov dword ptr [esi], edi */
    goto L_00547c00; /* jmp 0x547c00 */
L_00547bfa:;
    PUSH32(c, 0x00547bffu); f_00547c29(c); /* call 0x547c29 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00547c00:;
    { uint32_t v_ = 0x11u; PUSH32(c, v_); } /* push 0x11 */
    PUSH32(c, 0x00547c07u); f_00547c14(c); /* call 0x547c14 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_00547c09:;
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(0x55d03cu)); PUSH32(c, 0x00547c11u); call_indirect(c, t_); } /* call dword ptr [0x1001d03c] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00547c14(CPU *c) { /* FUN_10007c14 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->eax * 4 + 0x5601d0u)); PUSH32(c, v_); } /* push dword ptr [eax*4 + 0x100201d0] */
    { uint32_t t_ = R32((uint32_t)(0x55d040u)); PUSH32(c, 0x00547c27u); call_indirect(c, t_); } /* call dword ptr [0x1001d040] */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00547c29(CPU *c) { /* FUN_10007c29 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x55d460u; PUSH32(c, v_); } /* push 0x1001d460 */
    { uint32_t v_ = 0x547e10u; PUSH32(c, v_); } /* push 0x10007e10 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00547d03; /* je 0x547d03 */
    c->eax = (uint32_t)(R32((uint32_t)(0x5656e8u))); /* mov eax, dword ptr [0x100256e8] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_00547c9c; /* jne 0x547c9c */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00547c68u); f_00547bb3(c); /* call 0x547bb3 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00547c73u); f_0054a369(c); /* call 0x54a369 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00547c84; /* je 0x547c84 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00547c82u); f_0054a394(c); /* call 0x54a394 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00547c84:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00547c8du); f_00547c93(c); /* call 0x547c93 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x1c], 0 */
    goto L_00547ce4; /* jmp 0x547ce4 */
L_00547c9c:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00547cf4; /* jne 0x547cf4 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00547ca8u); f_00547bb3(c); /* call 0x547bb3 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe0u)); /* lea eax, [ebp - 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd8u)); /* lea eax, [ebp - 0x28] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00547cbeu); f_0054b0c4(c); /* call 0x54b0c4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00547cd7; /* je 0x547cd7 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x28] */
    PUSH32(c, 0x00547cd4u); f_0054b11b(c); /* call 0x54b11b */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_00547cd7:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00547ce0u); f_00547ceb(c); /* call 0x547ceb */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
L_00547ce4:;
    if (!c->zf) goto L_00547d03; /* jne 0x547d03 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    goto L_00547cf5; /* jmp 0x547cf5 */
L_00547cf4:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
L_00547cf5:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x5656e4u)); PUSH32(c, v_); } /* push dword ptr [0x100256e4] */
    { uint32_t t_ = R32((uint32_t)(0x55d048u)); PUSH32(c, 0x00547d03u); call_indirect(c, t_); } /* call dword ptr [0x1001d048] */
L_00547d03:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00547c93(CPU *c) { /* FUN_10007c93 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00547c9au); f_00547c14(c); /* call 0x547c14 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00547c9c(CPU *c) { /* PTR_00547c9c */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) { f_00547cf4(c); return; } /* jne 0x547cf4 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00547ca8u); f_00547bb3(c); /* call 0x547bb3 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe0u)); /* lea eax, [ebp - 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd8u)); /* lea eax, [ebp - 0x28] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00547cbeu); f_0054b0c4(c); /* call 0x54b0c4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00547cd7; /* je 0x547cd7 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x28] */
    PUSH32(c, 0x00547cd4u); f_0054b11b(c); /* call 0x54b11b */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_00547cd7:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00547ce0u); f_00547ceb(c); /* call 0x547ceb */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) { f_00547d03(c); return; } /* jne 0x547d03 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { f_00547cf5(c); return; } /* jmp 0x547cf5 */
}

void f_00547cd7(CPU *c) { /* PTR_00547cd7 */
    PREEMPT_POLL(c);
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00547ce0u); f_00547ceb(c); /* call 0x547ceb */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) { f_00547d03(c); return; } /* jne 0x547d03 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { f_00547cf5(c); return; } /* jmp 0x547cf5 */
}

void f_00547ce4(CPU *c) { /* PTR_00547ce4 */
    PREEMPT_POLL(c);
    if (!c->zf) { f_00547d03(c); return; } /* jne 0x547d03 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { f_00547cf5(c); return; } /* jmp 0x547cf5 */
}

void f_00547ceb(CPU *c) { /* FUN_10007ceb */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00547cf2u); f_00547c14(c); /* call 0x547c14 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00547cf4(CPU *c) { /* PTR_00547cf4 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x5656e4u)); PUSH32(c, v_); } /* push dword ptr [0x100256e4] */
    { uint32_t t_ = R32((uint32_t)(0x55d048u)); PUSH32(c, 0x00547d03u); call_indirect(c, t_); } /* call dword ptr [0x1001d048] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00547cf5(CPU *c) { /* PTR_00547cf5 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x5656e4u)); PUSH32(c, v_); } /* push dword ptr [0x100256e4] */
    { uint32_t t_ = R32((uint32_t)(0x55d048u)); PUSH32(c, 0x00547d03u); call_indirect(c, t_); } /* call dword ptr [0x1001d048] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00547d03(CPU *c) { /* PTR_00547d03 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00547d20(CPU *c) { /* _strcmp */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u)); /* test edx, 3 */
    if (!c->zf) goto L_00547d6c; /* jne 0x547d6c */
L_00547d30:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edx))); /* mov eax, dword ptr [edx] */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->ecx))); /* cmp al, byte ptr [ecx] */
    if (!c->zf) goto L_00547d64; /* jne 0x547d64 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00547d60; /* je 0x547d60 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), R8((uint32_t)(c->ecx + 0x1u))); /* cmp ah, byte ptr [ecx + 1] */
    if (!c->zf) goto L_00547d64; /* jne 0x547d64 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | ((uint8_t)(c->eax >> 8))))) << 8); /* or ah, ah */
    if (c->zf) goto L_00547d60; /* je 0x547d60 */
    c->eax = (uint32_t)(shr32(c, c->eax, 16)); /* shr eax, 0x10 */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->ecx + 0x2u))); /* cmp al, byte ptr [ecx + 2] */
    if (!c->zf) goto L_00547d64; /* jne 0x547d64 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00547d60; /* je 0x547d60 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), R8((uint32_t)(c->ecx + 0x3u))); /* cmp ah, byte ptr [ecx + 3] */
    if (!c->zf) goto L_00547d64; /* jne 0x547d64 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x4u)); /* add edx, 4 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | ((uint8_t)(c->eax >> 8))))) << 8); /* or ah, ah */
    if (!c->zf) goto L_00547d30; /* jne 0x547d30 */
    c->edi = (uint32_t)(c->edi); /* mov edi, edi */
L_00547d60:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_00547d64:;
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(shl32(c, c->eax, 1)); /* shl eax, 1 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->esp += 4; return; /* ret  */
L_00547d6c:;
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x1u)); /* test edx, 1 */
    if (c->zf) goto L_00547d88; /* je 0x547d88 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov al, byte ptr [edx] */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->ecx))); /* cmp al, byte ptr [ecx] */
    if (!c->zf) goto L_00547d64; /* jne 0x547d64 */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00547d60; /* je 0x547d60 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x2u)); /* test edx, 2 */
    if (c->zf) goto L_00547d30; /* je 0x547d30 */
L_00547d88:;
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->edx))); /* mov ax, word ptr [edx] */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x2u)); /* add edx, 2 */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->ecx))); /* cmp al, byte ptr [ecx] */
    if (!c->zf) goto L_00547d64; /* jne 0x547d64 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00547d60; /* je 0x547d60 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), R8((uint32_t)(c->ecx + 0x1u))); /* cmp ah, byte ptr [ecx + 1] */
    if (!c->zf) goto L_00547d64; /* jne 0x547d64 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | ((uint8_t)(c->eax >> 8))))) << 8); /* or ah, ah */
    if (c->zf) goto L_00547d60; /* je 0x547d60 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x2u)); /* add ecx, 2 */
    goto L_00547d30; /* jmp 0x547d30 */
}

void f_00547da4(CPU *c) { /* FUN_10007da4 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xe06d7363u); /* cmp dword ptr [eax], 0xe06d7363 */
    if (!c->zf) goto L_00547dc7; /* jne 0x547dc7 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [eax + 0x10], 3 */
    if (!c->zf) goto L_00547dc7; /* jne 0x547dc7 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x14u)), (uint32_t)0x19930520u); /* cmp dword ptr [eax + 0x14], 0x19930520 */
    if (!c->zf) goto L_00547dc7; /* jne 0x547dc7 */
    { f_005475c8(c); return; } /* jmp 0x5475c8 */
L_00547dc7:;
    c->eax = (uint32_t)(R32((uint32_t)(0x565178u))); /* mov eax, dword ptr [0x10025178] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00547de4; /* je 0x547de4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00547dd6u); f_00549518(c); /* call 0x549518 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00547de4; /* je 0x547de4 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(0x565178u)); PUSH32(c, 0x00547de2u); call_indirect(c, t_); } /* call dword ptr [0x10025178] */
    goto L_00547de6; /* jmp 0x547de6 */
L_00547de4:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00547de6:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00547dea(CPU *c) { /* PTR_00547dea */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x547da4u; PUSH32(c, v_); } /* push 0x10007da4 */
    { uint32_t t_ = R32((uint32_t)(0x55d04cu)); PUSH32(c, 0x00547df5u); call_indirect(c, t_); } /* call dword ptr [0x1001d04c] */
    W32((uint32_t)(0x565178u), (uint32_t)(c->eax)); /* mov dword ptr [0x10025178], eax */
    c->esp += 4; return; /* ret  */
}

void f_00547dfb(CPU *c) { /* PTR_00547dfb */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(0x565178u)); PUSH32(c, v_); } /* push dword ptr [0x10025178] */
    { uint32_t t_ = R32((uint32_t)(0x55d04cu)); PUSH32(c, 0x00547e07u); call_indirect(c, t_); } /* call dword ptr [0x1001d04c] */
    c->esp += 4; return; /* ret  */
}

void f_00547ecd(CPU *c) { /* FUN_10007ecd */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov ebp, dword ptr [ecx] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x1cu))); /* mov eax, dword ptr [ecx + 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x18u))); /* mov eax, dword ptr [ecx + 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00547ee1u); f_0054657a(c); /* call 0x54657a */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 8; return; /* ret 4 */
}

void f_00547ee8(CPU *c) { /* FUN_10007ee8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x560158u))); /* mov eax, dword ptr [0x10020158] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00547ef3; /* je 0x547ef3 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00547ef3u); call_indirect(c, t_); } /* call eax */
L_00547ef3:;
    { uint32_t v_ = 0x55f01cu; PUSH32(c, v_); } /* push 0x1001f01c */
    { uint32_t v_ = 0x55f00cu; PUSH32(c, v_); } /* push 0x1001f00c */
    PUSH32(c, 0x00547f02u); f_00547fec(c); /* call 0x547fec */
    { uint32_t v_ = 0x55f008u; PUSH32(c, v_); } /* push 0x1001f008 */
    { uint32_t v_ = 0x55f000u; PUSH32(c, v_); } /* push 0x1001f000 */
    PUSH32(c, 0x00547f11u); f_00547fec(c); /* call 0x547fec */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_00547f15(CPU *c) { /* __exit */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    PUSH32(c, 0x00547f22u); f_00547f35(c); /* call 0x547f35 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00547f26(CPU *c) { /* FUN_10007f26 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    PUSH32(c, 0x00547f31u); f_00547f35(c); /* call 0x547f35 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00547f35(CPU *c) { /* FUN_10007f35 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00547f3bu); f_00547fda(c); /* call 0x547fda */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    (void)sub32(c, R32((uint32_t)(0x5651bcu)), c->edi); /* cmp dword ptr [0x100251bc], edi */
    if (!c->zf) goto L_00547f57; /* jne 0x547f57 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    { uint32_t t_ = R32((uint32_t)(0x55d054u)); PUSH32(c, 0x00547f50u); call_indirect(c, t_); } /* call dword ptr [0x1001d054] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x55d050u)); PUSH32(c, 0x00547f57u); call_indirect(c, t_); } /* call dword ptr [0x1001d050] */
L_00547f57:;
    (void)sub32(c, R32((uint32_t)(c->esp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [esp + 0xc], 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ebx, dword ptr [esp + 0x14] */
    W32((uint32_t)(0x5651b8u), (uint32_t)(c->edi)); /* mov dword ptr [0x100251b8], edi */
    W8((uint32_t)(0x5651b4u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [0x100251b4], bl */
    if (!c->zf) goto L_00547fab; /* jne 0x547fab */
    c->eax = (uint32_t)(R32((uint32_t)(0x565810u))); /* mov eax, dword ptr [0x10025810] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00547f9a; /* je 0x547f9a */
    c->ecx = (uint32_t)(R32((uint32_t)(0x56580cu))); /* mov ecx, dword ptr [0x1002580c] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)((uint32_t)(c->ecx + 0xfffffffcu)); /* lea esi, [ecx - 4] */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if (c->cf) goto L_00547f99; /* jb 0x547f99 */
L_00547f86:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00547f8e; /* je 0x547f8e */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00547f8eu); call_indirect(c, t_); } /* call eax */
L_00547f8e:;
    c->esi = (uint32_t)(sub32(c, c->esi, (uint32_t)0x4u)); /* sub esi, 4 */
    (void)sub32(c, c->esi, R32((uint32_t)(0x565810u))); /* cmp esi, dword ptr [0x10025810] */
    if (!c->cf) goto L_00547f86; /* jae 0x547f86 */
L_00547f99:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00547f9a:;
    { uint32_t v_ = 0x55f024u; PUSH32(c, v_); } /* push 0x1001f024 */
    { uint32_t v_ = 0x55f020u; PUSH32(c, v_); } /* push 0x1001f020 */
    PUSH32(c, 0x00547fa9u); f_00547fec(c); /* call 0x547fec */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00547fab:;
    { uint32_t v_ = 0x55f030u; PUSH32(c, v_); } /* push 0x1001f030 */
    { uint32_t v_ = 0x55f028u; PUSH32(c, v_); } /* push 0x1001f028 */
    PUSH32(c, 0x00547fbau); f_00547fec(c); /* call 0x547fec */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    if (c->zf) goto L_00547fc8; /* je 0x547fc8 */
    PUSH32(c, 0x00547fc6u); f_00547fe3(c); /* call 0x547fe3 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_00547fc8:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    W32((uint32_t)(0x5651bcu), (uint32_t)(c->edi)); /* mov dword ptr [0x100251bc], edi */
    { uint32_t t_ = R32((uint32_t)(0x55d044u)); PUSH32(c, 0x00547fd8u); call_indirect(c, t_); } /* call dword ptr [0x1001d044] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00547fd8(CPU *c) { /* PTR_00547fd8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00547fda(CPU *c) { /* FUN_10007fda */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xdu; PUSH32(c, v_); } /* push 0xd */
    PUSH32(c, 0x00547fe1u); f_00547bb3(c); /* call 0x547bb3 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00547fe3(CPU *c) { /* FUN_10007fe3 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xdu; PUSH32(c, v_); } /* push 0xd */
    PUSH32(c, 0x00547feau); f_00547c14(c); /* call 0x547c14 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00547fec(CPU *c) { /* FUN_10007fec */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
L_00547ff1:;
    (void)sub32(c, c->esi, R32((uint32_t)(c->esp + 0xcu))); /* cmp esi, dword ptr [esp + 0xc] */
    if (!c->cf) goto L_00548004; /* jae 0x548004 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00547fff; /* je 0x547fff */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00547fffu); call_indirect(c, t_); } /* call eax */
L_00547fff:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    goto L_00547ff1; /* jmp 0x547ff1 */
L_00548004:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00548006(CPU *c) { /* FUN_10008006 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x55d478u; PUSH32(c, v_); } /* push 0x1001d478 */
    { uint32_t v_ = 0x547e10u; PUSH32(c, v_); } /* push 0x10007e10 */
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
    if (!c->zf) goto L_00548040; /* jne 0x548040 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x0054803au); f_00548423(c); /* call 0x548423 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00548326; /* jmp 0x548326 */
L_00548040:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_00548053; /* jne 0x548053 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x0054804du); f_00547c29(c); /* call 0x547c29 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00548324; /* jmp 0x548324 */
L_00548053:;
    c->eax = (uint32_t)(R32((uint32_t)(0x5656e8u))); /* mov eax, dword ptr [0x100256e8] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_0054819a; /* jne 0x54819a */
L_00548061:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_0054815e; /* ja 0x54815e */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00548074u); f_00547bb3(c); /* call 0x547bb3 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 4], edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x0054807eu); f_0054a369(c); /* call 0x54a369 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x28], eax */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (c->zf) goto L_0054812e; /* je 0x54812e */
    (void)sub32(c, c->esi, R32((uint32_t)(0x5656e0u))); /* cmp esi, dword ptr [0x100256e0] */
    if ((!c->cf && !c->zf)) goto L_005480de; /* ja 0x5480de */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0054809au); f_0054ab72(c); /* call 0x54ab72 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_005480a6; /* je 0x5480a6 */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x24], ebx */
    goto L_005480de; /* jmp 0x5480de */
L_005480a6:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x005480acu); f_0054a6bd(c); /* call 0x54a6bd */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (c->zf) goto L_005480de; /* je 0x5480de */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xfffffffcu))); /* mov eax, dword ptr [ebx - 4] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_005480c1; /* jb 0x5480c1 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_005480c1:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x005480cbu); f_0054b550(c); /* call 0x54b550 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x005480d1u); f_0054a369(c); /* call 0x54a369 */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x28], eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x005480dbu); f_0054a394(c); /* call 0x54a394 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_005480de:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), c->edi); /* cmp dword ptr [ebp - 0x24], edi */
    if (!c->zf) goto L_0054812e; /* jne 0x54812e */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_005480ed; /* jne 0x5480ed */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_005480ed:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0x5656e4u)); PUSH32(c, v_); } /* push dword ptr [0x100256e4] */
    { uint32_t t_ = R32((uint32_t)(0x55d05cu)); PUSH32(c, 0x00548104u); call_indirect(c, t_); } /* call dword ptr [0x1001d05c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (c->zf) goto L_0054812e; /* je 0x54812e */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xfffffffcu))); /* mov eax, dword ptr [ebx - 4] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00548118; /* jb 0x548118 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00548118:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00548122u); f_0054b550(c); /* call 0x54b550 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x28] */
    PUSH32(c, 0x0054812bu); f_0054a394(c); /* call 0x54a394 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
L_0054812e:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00548137u); f_00548191(c); /* call 0x548191 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), c->edi); /* cmp dword ptr [ebp - 0x28], edi */
    if (!c->zf) goto L_0054815e; /* jne 0x54815e */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_00548143; /* jne 0x548143 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00548143:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0x5656e4u)); PUSH32(c, v_); } /* push dword ptr [0x100256e4] */
    { uint32_t t_ = R32((uint32_t)(0x55d058u)); PUSH32(c, 0x0054815bu); call_indirect(c, t_); } /* call dword ptr [0x1001d058] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_0054815e:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_00548326; /* jne 0x548326 */
    (void)sub32(c, R32((uint32_t)(0x5652d4u)), c->edi); /* cmp dword ptr [0x100252d4], edi */
    if (c->zf) goto L_00548326; /* je 0x548326 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x0054817bu); f_0054b535(c); /* call 0x54b535 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00548061; /* jne 0x548061 */
    goto L_00548324; /* jmp 0x548324 */
L_0054819a:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_005482ea; /* jne 0x5482ea */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_005481ba; /* ja 0x5481ba */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if ((c->cf || c->zf)) goto L_005481b4; /* jbe 0x5481b4 */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    goto L_005481b7; /* jmp 0x5481b7 */
L_005481b4:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_005481b7:;
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_005481ba:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_005482b9; /* ja 0x5482b9 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x005481cdu); f_00547bb3(c); /* call 0x547bb3 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x005481e3u); f_0054b0c4(c); /* call 0x54b0c4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_0054829d; /* je 0x54829d */
    (void)sub32(c, c->esi, R32((uint32_t)(0x562684u))); /* cmp esi, dword ptr [0x10022684] */
    if (!c->cf) goto L_00548257; /* jae 0x548257 */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 4)); /* shr ebx, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x0054820du); f_0054b48c(c); /* call 0x54b48c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0054821c; /* je 0x54821c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_00548254; /* jmp 0x548254 */
L_0054821c:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00548222u); f_0054b160(c); /* call 0x54b160 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00548254; /* je 0x548254 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00548239; /* jb 0x548239 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00548239:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00548245u); f_0054b550(c); /* call 0x54b550 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00548251u); f_0054b11b(c); /* call 0x54b11b */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00548254:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00548257:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_005482b0; /* jne 0x5482b0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x5656e4u)); PUSH32(c, v_); } /* push dword ptr [0x100256e4] */
    { uint32_t t_ = R32((uint32_t)(0x55d05cu)); PUSH32(c, 0x0054826cu); call_indirect(c, t_); } /* call dword ptr [0x1001d05c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_005482b0; /* je 0x5482b0 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00548282; /* jb 0x548282 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00548282:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x0054828cu); f_0054b550(c); /* call 0x54b550 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00548298u); f_0054b11b(c); /* call 0x54b11b */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_005482b0; /* jmp 0x5482b0 */
L_0054829d:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x5656e4u)); PUSH32(c, v_); } /* push dword ptr [0x100256e4] */
    { uint32_t t_ = R32((uint32_t)(0x55d058u)); PUSH32(c, 0x005482adu); call_indirect(c, t_); } /* call dword ptr [0x1001d058] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_005482b0:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x005482b9u); f_005482df(c); /* call 0x5482df */
L_005482b9:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_00548326; /* jne 0x548326 */
    (void)sub32(c, R32((uint32_t)(0x5652d4u)), c->edi); /* cmp dword ptr [0x100252d4], edi */
    if (c->zf) goto L_00548326; /* je 0x548326 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x005482ceu); f_0054b535(c); /* call 0x54b535 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_005481ba; /* jne 0x5481ba */
    goto L_00548324; /* jmp 0x548324 */
L_005482ea:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_0054830d; /* ja 0x54830d */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_005482f8; /* jne 0x5482f8 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_005482f8:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0x5656e4u)); PUSH32(c, v_); } /* push dword ptr [0x100256e4] */
    { uint32_t t_ = R32((uint32_t)(0x55d058u)); PUSH32(c, 0x0054830du); call_indirect(c, t_); } /* call dword ptr [0x1001d058] */
L_0054830d:;
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_00548326; /* jne 0x548326 */
    (void)sub32(c, R32((uint32_t)(0x5652d4u)), c->edi); /* cmp dword ptr [0x100252d4], edi */
    if (c->zf) goto L_00548326; /* je 0x548326 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x0054831fu); f_0054b535(c); /* call 0x54b535 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_005482ea; /* jne 0x5482ea */
L_00548324:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00548326:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00548189(CPU *c) { /* PTR_00548189 */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    { f_00548191(c); return; }
}

void f_00548191(CPU *c) { /* FUN_10008191 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00548198u); f_00547c14(c); /* call 0x547c14 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_0054819a(CPU *c) { /* PTR_0054819a */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) { f_005482ea(c); return; } /* jne 0x5482ea */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_005481ba; /* ja 0x5481ba */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if ((c->cf || c->zf)) goto L_005481b4; /* jbe 0x5481b4 */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    goto L_005481b7; /* jmp 0x5481b7 */
L_005481b4:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_005481b7:;
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_005481ba:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_005482b9; /* ja 0x5482b9 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x005481cdu); f_00547bb3(c); /* call 0x547bb3 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x005481e3u); f_0054b0c4(c); /* call 0x54b0c4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_0054829d; /* je 0x54829d */
    (void)sub32(c, c->esi, R32((uint32_t)(0x562684u))); /* cmp esi, dword ptr [0x10022684] */
    if (!c->cf) goto L_00548257; /* jae 0x548257 */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 4)); /* shr ebx, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x0054820du); f_0054b48c(c); /* call 0x54b48c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0054821c; /* je 0x54821c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_00548254; /* jmp 0x548254 */
L_0054821c:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00548222u); f_0054b160(c); /* call 0x54b160 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00548254; /* je 0x548254 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00548239; /* jb 0x548239 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00548239:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00548245u); f_0054b550(c); /* call 0x54b550 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00548251u); f_0054b11b(c); /* call 0x54b11b */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00548254:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00548257:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_005482b0; /* jne 0x5482b0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x5656e4u)); PUSH32(c, v_); } /* push dword ptr [0x100256e4] */
    { uint32_t t_ = R32((uint32_t)(0x55d05cu)); PUSH32(c, 0x0054826cu); call_indirect(c, t_); } /* call dword ptr [0x1001d05c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_005482b0; /* je 0x5482b0 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00548282; /* jb 0x548282 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00548282:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x0054828cu); f_0054b550(c); /* call 0x54b550 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00548298u); f_0054b11b(c); /* call 0x54b11b */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_005482b0; /* jmp 0x5482b0 */
L_0054829d:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x5656e4u)); PUSH32(c, v_); } /* push dword ptr [0x100256e4] */
    { uint32_t t_ = R32((uint32_t)(0x55d058u)); PUSH32(c, 0x005482adu); call_indirect(c, t_); } /* call dword ptr [0x1001d058] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_005482b0:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x005482b9u); f_005482df(c); /* call 0x5482df */
L_005482b9:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00548326(c); return; } /* jne 0x548326 */
    (void)sub32(c, R32((uint32_t)(0x5652d4u)), c->edi); /* cmp dword ptr [0x100252d4], edi */
    if (c->zf) { f_00548326(c); return; } /* je 0x548326 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x005482ceu); f_0054b535(c); /* call 0x54b535 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_005481ba; /* jne 0x5481ba */
    { f_00548324(c); return; } /* jmp 0x548324 */
}

void f_005481b4(CPU *c) { /* PTR_005481b4 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_005481ba:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_005482b9; /* ja 0x5482b9 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x005481cdu); f_00547bb3(c); /* call 0x547bb3 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x005481e3u); f_0054b0c4(c); /* call 0x54b0c4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_0054829d; /* je 0x54829d */
    (void)sub32(c, c->esi, R32((uint32_t)(0x562684u))); /* cmp esi, dword ptr [0x10022684] */
    if (!c->cf) goto L_00548257; /* jae 0x548257 */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 4)); /* shr ebx, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x0054820du); f_0054b48c(c); /* call 0x54b48c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0054821c; /* je 0x54821c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_00548254; /* jmp 0x548254 */
L_0054821c:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00548222u); f_0054b160(c); /* call 0x54b160 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00548254; /* je 0x548254 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00548239; /* jb 0x548239 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00548239:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00548245u); f_0054b550(c); /* call 0x54b550 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00548251u); f_0054b11b(c); /* call 0x54b11b */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00548254:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00548257:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_005482b0; /* jne 0x5482b0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x5656e4u)); PUSH32(c, v_); } /* push dword ptr [0x100256e4] */
    { uint32_t t_ = R32((uint32_t)(0x55d05cu)); PUSH32(c, 0x0054826cu); call_indirect(c, t_); } /* call dword ptr [0x1001d05c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_005482b0; /* je 0x5482b0 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00548282; /* jb 0x548282 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00548282:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x0054828cu); f_0054b550(c); /* call 0x54b550 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00548298u); f_0054b11b(c); /* call 0x54b11b */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_005482b0; /* jmp 0x5482b0 */
L_0054829d:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x5656e4u)); PUSH32(c, v_); } /* push dword ptr [0x100256e4] */
    { uint32_t t_ = R32((uint32_t)(0x55d058u)); PUSH32(c, 0x005482adu); call_indirect(c, t_); } /* call dword ptr [0x1001d058] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_005482b0:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x005482b9u); f_005482df(c); /* call 0x5482df */
L_005482b9:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00548326(c); return; } /* jne 0x548326 */
    (void)sub32(c, R32((uint32_t)(0x5652d4u)), c->edi); /* cmp dword ptr [0x100252d4], edi */
    if (c->zf) { f_00548326(c); return; } /* je 0x548326 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x005482ceu); f_0054b535(c); /* call 0x54b535 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_005481ba; /* jne 0x5481ba */
    { f_00548324(c); return; } /* jmp 0x548324 */
}

void f_005481b7(CPU *c) { /* PTR_005481b7 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_005481ba:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_005482b9; /* ja 0x5482b9 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x005481cdu); f_00547bb3(c); /* call 0x547bb3 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x005481e3u); f_0054b0c4(c); /* call 0x54b0c4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_0054829d; /* je 0x54829d */
    (void)sub32(c, c->esi, R32((uint32_t)(0x562684u))); /* cmp esi, dword ptr [0x10022684] */
    if (!c->cf) goto L_00548257; /* jae 0x548257 */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 4)); /* shr ebx, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x0054820du); f_0054b48c(c); /* call 0x54b48c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0054821c; /* je 0x54821c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_00548254; /* jmp 0x548254 */
L_0054821c:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00548222u); f_0054b160(c); /* call 0x54b160 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00548254; /* je 0x548254 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00548239; /* jb 0x548239 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00548239:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00548245u); f_0054b550(c); /* call 0x54b550 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00548251u); f_0054b11b(c); /* call 0x54b11b */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00548254:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00548257:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_005482b0; /* jne 0x5482b0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x5656e4u)); PUSH32(c, v_); } /* push dword ptr [0x100256e4] */
    { uint32_t t_ = R32((uint32_t)(0x55d05cu)); PUSH32(c, 0x0054826cu); call_indirect(c, t_); } /* call dword ptr [0x1001d05c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_005482b0; /* je 0x5482b0 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00548282; /* jb 0x548282 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00548282:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x0054828cu); f_0054b550(c); /* call 0x54b550 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00548298u); f_0054b11b(c); /* call 0x54b11b */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_005482b0; /* jmp 0x5482b0 */
L_0054829d:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x5656e4u)); PUSH32(c, v_); } /* push dword ptr [0x100256e4] */
    { uint32_t t_ = R32((uint32_t)(0x55d058u)); PUSH32(c, 0x005482adu); call_indirect(c, t_); } /* call dword ptr [0x1001d058] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_005482b0:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x005482b9u); f_005482df(c); /* call 0x5482df */
L_005482b9:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00548326(c); return; } /* jne 0x548326 */
    (void)sub32(c, R32((uint32_t)(0x5652d4u)), c->edi); /* cmp dword ptr [0x100252d4], edi */
    if (c->zf) { f_00548326(c); return; } /* je 0x548326 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x005482ceu); f_0054b535(c); /* call 0x54b535 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_005481ba; /* jne 0x5481ba */
    { f_00548324(c); return; } /* jmp 0x548324 */
}

void f_005481ba(CPU *c) { /* PTR_005481ba */
    PREEMPT_POLL(c);
L_005481ba:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_005482b9; /* ja 0x5482b9 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x005481cdu); f_00547bb3(c); /* call 0x547bb3 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x005481e3u); f_0054b0c4(c); /* call 0x54b0c4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_0054829d; /* je 0x54829d */
    (void)sub32(c, c->esi, R32((uint32_t)(0x562684u))); /* cmp esi, dword ptr [0x10022684] */
    if (!c->cf) goto L_00548257; /* jae 0x548257 */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 4)); /* shr ebx, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x0054820du); f_0054b48c(c); /* call 0x54b48c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0054821c; /* je 0x54821c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_00548254; /* jmp 0x548254 */
L_0054821c:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00548222u); f_0054b160(c); /* call 0x54b160 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00548254; /* je 0x548254 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00548239; /* jb 0x548239 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00548239:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00548245u); f_0054b550(c); /* call 0x54b550 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00548251u); f_0054b11b(c); /* call 0x54b11b */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00548254:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00548257:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_005482b0; /* jne 0x5482b0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x5656e4u)); PUSH32(c, v_); } /* push dword ptr [0x100256e4] */
    { uint32_t t_ = R32((uint32_t)(0x55d05cu)); PUSH32(c, 0x0054826cu); call_indirect(c, t_); } /* call dword ptr [0x1001d05c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_005482b0; /* je 0x5482b0 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00548282; /* jb 0x548282 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00548282:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x0054828cu); f_0054b550(c); /* call 0x54b550 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00548298u); f_0054b11b(c); /* call 0x54b11b */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_005482b0; /* jmp 0x5482b0 */
L_0054829d:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x5656e4u)); PUSH32(c, v_); } /* push dword ptr [0x100256e4] */
    { uint32_t t_ = R32((uint32_t)(0x55d058u)); PUSH32(c, 0x005482adu); call_indirect(c, t_); } /* call dword ptr [0x1001d058] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_005482b0:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x005482b9u); f_005482df(c); /* call 0x5482df */
L_005482b9:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00548326(c); return; } /* jne 0x548326 */
    (void)sub32(c, R32((uint32_t)(0x5652d4u)), c->edi); /* cmp dword ptr [0x100252d4], edi */
    if (c->zf) { f_00548326(c); return; } /* je 0x548326 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x005482ceu); f_0054b535(c); /* call 0x54b535 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_005481ba; /* jne 0x5481ba */
    { f_00548324(c); return; } /* jmp 0x548324 */
}

void f_0054821c(CPU *c) { /* PTR_0054821c */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00548222u); f_0054b160(c); /* call 0x54b160 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00548254; /* je 0x548254 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00548239; /* jb 0x548239 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00548239:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00548245u); f_0054b550(c); /* call 0x54b550 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00548251u); f_0054b11b(c); /* call 0x54b11b */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00548254:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_005482b0; /* jne 0x5482b0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x5656e4u)); PUSH32(c, v_); } /* push dword ptr [0x100256e4] */
    { uint32_t t_ = R32((uint32_t)(0x55d05cu)); PUSH32(c, 0x0054826cu); call_indirect(c, t_); } /* call dword ptr [0x1001d05c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_005482b0; /* je 0x5482b0 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00548282; /* jb 0x548282 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00548282:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x0054828cu); f_0054b550(c); /* call 0x54b550 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00548298u); f_0054b11b(c); /* call 0x54b11b */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_005482b0; /* jmp 0x5482b0 */
L_005482b0:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x005482b9u); f_005482df(c); /* call 0x5482df */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00548326(c); return; } /* jne 0x548326 */
    (void)sub32(c, R32((uint32_t)(0x5652d4u)), c->edi); /* cmp dword ptr [0x100252d4], edi */
    if (c->zf) { f_00548326(c); return; } /* je 0x548326 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x005482ceu); f_0054b535(c); /* call 0x54b535 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_005481ba(c); return; } /* jne 0x5481ba */
    { f_00548324(c); return; } /* jmp 0x548324 */
}

void f_00548239(CPU *c) { /* PTR_00548239 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00548245u); f_0054b550(c); /* call 0x54b550 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00548251u); f_0054b11b(c); /* call 0x54b11b */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_005482b0; /* jne 0x5482b0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x5656e4u)); PUSH32(c, v_); } /* push dword ptr [0x100256e4] */
    { uint32_t t_ = R32((uint32_t)(0x55d05cu)); PUSH32(c, 0x0054826cu); call_indirect(c, t_); } /* call dword ptr [0x1001d05c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_005482b0; /* je 0x5482b0 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00548282; /* jb 0x548282 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00548282:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x0054828cu); f_0054b550(c); /* call 0x54b550 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00548298u); f_0054b11b(c); /* call 0x54b11b */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_005482b0; /* jmp 0x5482b0 */
L_005482b0:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x005482b9u); f_005482df(c); /* call 0x5482df */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00548326(c); return; } /* jne 0x548326 */
    (void)sub32(c, R32((uint32_t)(0x5652d4u)), c->edi); /* cmp dword ptr [0x100252d4], edi */
    if (c->zf) { f_00548326(c); return; } /* je 0x548326 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x005482ceu); f_0054b535(c); /* call 0x54b535 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_005481ba(c); return; } /* jne 0x5481ba */
    { f_00548324(c); return; } /* jmp 0x548324 */
}

void f_00548254(CPU *c) { /* PTR_00548254 */
    PREEMPT_POLL(c);
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_005482b0; /* jne 0x5482b0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x5656e4u)); PUSH32(c, v_); } /* push dword ptr [0x100256e4] */
    { uint32_t t_ = R32((uint32_t)(0x55d05cu)); PUSH32(c, 0x0054826cu); call_indirect(c, t_); } /* call dword ptr [0x1001d05c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_005482b0; /* je 0x5482b0 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00548282; /* jb 0x548282 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00548282:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x0054828cu); f_0054b550(c); /* call 0x54b550 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00548298u); f_0054b11b(c); /* call 0x54b11b */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_005482b0; /* jmp 0x5482b0 */
L_005482b0:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x005482b9u); f_005482df(c); /* call 0x5482df */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00548326(c); return; } /* jne 0x548326 */
    (void)sub32(c, R32((uint32_t)(0x5652d4u)), c->edi); /* cmp dword ptr [0x100252d4], edi */
    if (c->zf) { f_00548326(c); return; } /* je 0x548326 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x005482ceu); f_0054b535(c); /* call 0x54b535 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_005481ba(c); return; } /* jne 0x5481ba */
    { f_00548324(c); return; } /* jmp 0x548324 */
}

void f_00548257(CPU *c) { /* PTR_00548257 */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_005482b0; /* jne 0x5482b0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x5656e4u)); PUSH32(c, v_); } /* push dword ptr [0x100256e4] */
    { uint32_t t_ = R32((uint32_t)(0x55d05cu)); PUSH32(c, 0x0054826cu); call_indirect(c, t_); } /* call dword ptr [0x1001d05c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_005482b0; /* je 0x5482b0 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00548282; /* jb 0x548282 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00548282:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x0054828cu); f_0054b550(c); /* call 0x54b550 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00548298u); f_0054b11b(c); /* call 0x54b11b */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_005482b0; /* jmp 0x5482b0 */
L_005482b0:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x005482b9u); f_005482df(c); /* call 0x5482df */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00548326(c); return; } /* jne 0x548326 */
    (void)sub32(c, R32((uint32_t)(0x5652d4u)), c->edi); /* cmp dword ptr [0x100252d4], edi */
    if (c->zf) { f_00548326(c); return; } /* je 0x548326 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x005482ceu); f_0054b535(c); /* call 0x54b535 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_005481ba(c); return; } /* jne 0x5481ba */
    { f_00548324(c); return; } /* jmp 0x548324 */
}

void f_00548282(CPU *c) { /* PTR_00548282 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x0054828cu); f_0054b550(c); /* call 0x54b550 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00548298u); f_0054b11b(c); /* call 0x54b11b */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_005482b0; /* jmp 0x5482b0 */
L_005482b0:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x005482b9u); f_005482df(c); /* call 0x5482df */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00548326(c); return; } /* jne 0x548326 */
    (void)sub32(c, R32((uint32_t)(0x5652d4u)), c->edi); /* cmp dword ptr [0x100252d4], edi */
    if (c->zf) { f_00548326(c); return; } /* je 0x548326 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x005482ceu); f_0054b535(c); /* call 0x54b535 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_005481ba(c); return; } /* jne 0x5481ba */
    { f_00548324(c); return; } /* jmp 0x548324 */
}

void f_0054829d(CPU *c) { /* PTR_0054829d */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x5656e4u)); PUSH32(c, v_); } /* push dword ptr [0x100256e4] */
    { uint32_t t_ = R32((uint32_t)(0x55d058u)); PUSH32(c, 0x005482adu); call_indirect(c, t_); } /* call dword ptr [0x1001d058] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x005482b9u); f_005482df(c); /* call 0x5482df */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00548326(c); return; } /* jne 0x548326 */
    (void)sub32(c, R32((uint32_t)(0x5652d4u)), c->edi); /* cmp dword ptr [0x100252d4], edi */
    if (c->zf) { f_00548326(c); return; } /* je 0x548326 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x005482ceu); f_0054b535(c); /* call 0x54b535 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_005481ba(c); return; } /* jne 0x5481ba */
    { f_00548324(c); return; } /* jmp 0x548324 */
}

void f_005482b0(CPU *c) { /* PTR_005482b0 */
    PREEMPT_POLL(c);
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x005482b9u); f_005482df(c); /* call 0x5482df */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00548326(c); return; } /* jne 0x548326 */
    (void)sub32(c, R32((uint32_t)(0x5652d4u)), c->edi); /* cmp dword ptr [0x100252d4], edi */
    if (c->zf) { f_00548326(c); return; } /* je 0x548326 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x005482ceu); f_0054b535(c); /* call 0x54b535 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_005481ba(c); return; } /* jne 0x5481ba */
    { f_00548324(c); return; } /* jmp 0x548324 */
}

void f_005482b9(CPU *c) { /* PTR_005482b9 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00548326(c); return; } /* jne 0x548326 */
    (void)sub32(c, R32((uint32_t)(0x5652d4u)), c->edi); /* cmp dword ptr [0x100252d4], edi */
    if (c->zf) { f_00548326(c); return; } /* je 0x548326 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x005482ceu); f_0054b535(c); /* call 0x54b535 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_005481ba(c); return; } /* jne 0x5481ba */
    { f_00548324(c); return; } /* jmp 0x548324 */
}

void f_005482d9(CPU *c) { /* PTR_005482d9 */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    { f_005482df(c); return; }
}

void f_005482df(CPU *c) { /* FUN_100082df */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x005482e6u); f_00547c14(c); /* call 0x547c14 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    c->esp += 4; return; /* ret  */
}

void f_005482ea(CPU *c) { /* PTR_005482ea */
    PREEMPT_POLL(c);
L_005482ea:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_0054830d; /* ja 0x54830d */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_005482f8; /* jne 0x5482f8 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_005482f8:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0x5656e4u)); PUSH32(c, v_); } /* push dword ptr [0x100256e4] */
    { uint32_t t_ = R32((uint32_t)(0x55d058u)); PUSH32(c, 0x0054830du); call_indirect(c, t_); } /* call dword ptr [0x1001d058] */
L_0054830d:;
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_00548326; /* jne 0x548326 */
    (void)sub32(c, R32((uint32_t)(0x5652d4u)), c->edi); /* cmp dword ptr [0x100252d4], edi */
    if (c->zf) goto L_00548326; /* je 0x548326 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x0054831fu); f_0054b535(c); /* call 0x54b535 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_005482ea; /* jne 0x5482ea */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00548326:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_005482f8(CPU *c) { /* PTR_005482f8 */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0x5656e4u)); PUSH32(c, v_); } /* push dword ptr [0x100256e4] */
    { uint32_t t_ = R32((uint32_t)(0x55d058u)); PUSH32(c, 0x0054830du); call_indirect(c, t_); } /* call dword ptr [0x1001d058] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_00548326; /* jne 0x548326 */
    (void)sub32(c, R32((uint32_t)(0x5652d4u)), c->edi); /* cmp dword ptr [0x100252d4], edi */
    if (c->zf) goto L_00548326; /* je 0x548326 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x0054831fu); f_0054b535(c); /* call 0x54b535 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_005482ea(c); return; } /* jne 0x5482ea */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00548326:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0054830d(CPU *c) { /* PTR_0054830d */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_00548326; /* jne 0x548326 */
    (void)sub32(c, R32((uint32_t)(0x5652d4u)), c->edi); /* cmp dword ptr [0x100252d4], edi */
    if (c->zf) goto L_00548326; /* je 0x548326 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x0054831fu); f_0054b535(c); /* call 0x54b535 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_005482ea(c); return; } /* jne 0x5482ea */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00548326:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00548324(CPU *c) { /* PTR_00548324 */
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

void f_00548326(CPU *c) { /* PTR_00548326 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00548335(CPU *c) { /* FUN_10008335 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x55d490u; PUSH32(c, v_); } /* push 0x1001d490 */
    { uint32_t v_ = 0x547e10u; PUSH32(c, v_); } /* push 0x10007e10 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x1cu)); /* sub esp, 0x1c */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(0x5656e8u))); /* mov eax, dword ptr [0x100256e8] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_005483a8; /* jne 0x5483a8 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00548369u); f_00547bb3(c); /* call 0x547bb3 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00548377u); f_0054a369(c); /* call 0x54a369 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0054838a; /* je 0x54838a */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0xfffffffcu))); /* mov esi, dword ptr [esi - 4] */
    c->esi = (uint32_t)(sub32(c, c->esi, (uint32_t)0x9u)); /* sub esi, 9 */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x20], esi */
    goto L_0054838d; /* jmp 0x54838d */
L_0054838a:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
L_0054838d:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00548396u); f_0054839f(c); /* call 0x54839f */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x1c], 0 */
    goto L_005483f1; /* jmp 0x5483f1 */
L_005483a8:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_005483f3; /* jne 0x5483f3 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x005483b4u); f_00547bb3(c); /* call 0x547bb3 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffdcu)); /* lea eax, [ebp - 0x24] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x005483ccu); f_0054b0c4(c); /* call 0x54b0c4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x28], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_005483e1; /* je 0x5483e1 */
    c->esi = (uint32_t)((uint32_t)R8((uint32_t)(c->eax))); /* movzx esi, byte ptr [eax] */
    c->esi = (uint32_t)(shl32(c, c->esi, 4)); /* shl esi, 4 */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x20], esi */
    goto L_005483e4; /* jmp 0x5483e4 */
L_005483e1:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
L_005483e4:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x005483edu); f_0054841a(c); /* call 0x54841a */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x28], 0 */
L_005483f1:;
    if (!c->zf) goto L_00548406; /* jne 0x548406 */
L_005483f3:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x5656e4u)); PUSH32(c, v_); } /* push dword ptr [0x100256e4] */
    { uint32_t t_ = R32((uint32_t)(0x55d060u)); PUSH32(c, 0x00548404u); call_indirect(c, t_); } /* call dword ptr [0x1001d060] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_00548406:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}
