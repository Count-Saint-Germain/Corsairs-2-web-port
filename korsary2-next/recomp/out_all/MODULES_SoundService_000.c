#include "recomp.h"

void f_00991000(CPU *c) { /* FUN_10001000 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [eax + 8], 0 */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x9b5120u)); /* mov dword ptr [eax], 0x10025120 */
    c->esp += 4; return; /* ret  */
}

void f_00991010(CPU *c) { /* FUN_10001010 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00991018u); f_00991030(c); /* call 0x991030 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00991028; /* je 0x991028 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00991025u); f_00993c50(c); /* call 0x993c50 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00991028:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00991030(CPU *c) { /* FUN_10001030 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx), (uint32_t)((uint32_t)0x9b5120u)); /* mov dword ptr [ecx], 0x10025120 */
    c->esp += 4; return; /* ret  */
}

void f_00991040(CPU *c) { /* FUN_10001040 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00991057; /* je 0x991057 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x8u)); PUSH32(c, 0x00991050u); call_indirect(c, t_); } /* call dword ptr [ecx + 8] */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 8], 0 */
L_00991057:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00991060(CPU *c) { /* FUN_10001060 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (!c->zf) goto L_00991073; /* jne 0x991073 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 24; return; /* ret 0x14 */
L_00991073:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00991085; /* je 0x991085 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00991085u); f_00991130(c); /* call 0x991130 */
L_00991085:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x9b5128u))); FPOP(c); /* fcomp dword ptr [0x10025128] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x100u))); /* and eax, 0x100 */
    if (!c->zf) goto L_009910a6; /* jne 0x9910a6 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x10u)); /* lea ecx, [esp + 0x10] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x009910a6u); f_00991130(c); /* call 0x991130 */
L_009910a6:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x9b5128u))); FPOP(c); /* fcomp dword ptr [0x10025128] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x100u))); /* and eax, 0x100 */
    if (!c->zf) goto L_009910c7; /* jne 0x9910c7 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea edx, [esp + 0x14] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x009910c7u); f_00991130(c); /* call 0x991130 */
L_009910c7:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x9b5124u))); FPOP(c); /* fcomp dword ptr [0x10025124] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x44u)); /* test ah, 0x44 */
    if (!PF(c)) goto L_009910e7; /* jnp 0x9910e7 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x009910e7u); f_00995e60(c); /* call 0x995e60 */
L_009910e7:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x8u))); /* mov al, byte ptr [esp + 8] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_0099110a; /* je 0x99110a */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov eax, dword ptr [ecx + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x30u)); PUSH32(c, 0x00991101u); call_indirect(c, t_); } /* call dword ptr [edx + 0x30] */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->esp += 24; return; /* ret 0x14 */
L_0099110a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov eax, dword ptr [eax + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x0099111cu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->esp += 24; return; /* ret 0x14 */
}

void f_00991130(CPU *c) { /* FUN_10001130 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov eax, dword ptr [ecx + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_0099113c; /* jne 0x99113c */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    c->esp += 12; return; /* ret 8 */
L_0099113c:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_0099118a; /* je 0x99118a */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_0099116f; /* je 0x99116f */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_0099114e; /* je 0x99114e */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    c->esp += 12; return; /* ret 8 */
L_0099114e:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov esi, dword ptr [ecx + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov esi, dword ptr [ecx + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov ecx, dword ptr [ecx] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x4cu)); PUSH32(c, 0x00991166u); call_indirect(c, t_); } /* call dword ptr [edx + 0x4c] */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->esp += 12; return; /* ret 8 */
L_0099116f:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx))); /* mov ecx, dword ptr [edx] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x14], ecx */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x44u)); PUSH32(c, 0x00991182u); call_indirect(c, t_); } /* call dword ptr [edx + 0x44] */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->esp += 12; return; /* ret 8 */
L_0099118a:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx))); /* mov ecx, dword ptr [edx] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x14], ecx */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x40u)); PUSH32(c, 0x0099119du); call_indirect(c, t_); } /* call dword ptr [edx + 0x40] */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->esp += 12; return; /* ret 8 */
}

void f_009911b0(CPU *c) { /* FUN_100011b0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov eax, dword ptr [ecx + 8] */
    c->edx = (uint32_t)((uint32_t)(c->ecx + 0x8u)); /* lea edx, [ecx + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_009911cb; /* jne 0x9911cb */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov eax, dword ptr [ecx + 4] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x9b5430u; PUSH32(c, v_); } /* push 0x10025430 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov eax, dword ptr [eax + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx)); PUSH32(c, 0x009911cbu); call_indirect(c, t_); } /* call dword ptr [ecx] */
L_009911cb:;
    c->esp += 4; return; /* ret  */
}

void f_009911d0(CPU *c) { /* PTR_009911d0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x9cdfb4u))); /* mov eax, dword ptr [0x1003dfb4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x8u)); /* lea eax, [esp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)R32((uint32_t)(c->esp + 0x10u)); c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, dword ptr [esp + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov eax, dword ptr [esp + 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x18u)); PUSH32(c, 0x009911f6u); call_indirect(c, t_); } /* call dword ptr [edx + 0x18] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->esp += 4; return; /* ret  */
}

void f_00991200(CPU *c) { /* PTR_00991200 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x0u)); /* sub eax, 0 */
    if (c->zf) goto L_00991233; /* je 0x991233 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_0099122f; /* je 0x99122f */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00991213; /* je 0x991213 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    c->esp += 4; return; /* ret  */
L_00991213:;
    c->eax = (uint32_t)(R32((uint32_t)(0x9cdfb4u))); /* mov eax, dword ptr [0x1003dfb4] */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x0099122eu); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    c->esp += 4; return; /* ret  */
L_0099122f:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    goto L_00991235; /* jmp 0x991235 */
L_00991233:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
L_00991235:;
    c->ecx = (uint32_t)(R32((uint32_t)(0x9cdfb4u))); /* mov ecx, dword ptr [0x1003dfb4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ecx, dword ptr [ecx + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x0099124fu); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    c->esp += 4; return; /* ret  */
}

void f_00991250(CPU *c) { /* PTR_00991250 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x9cdfb4u))); /* mov eax, dword ptr [0x1003dfb4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x00991262u); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_00991270(CPU *c) { /* PTR_00991270 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x9cdfb4u))); /* mov eax, dword ptr [0x1003dfb4] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x00991288u); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    c->esp += 4; return; /* ret  */
}

void f_00991290(CPU *c) { /* FUN_10001290 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->edx = (uint32_t)((uint32_t)0x1u); /* mov edx, 1 */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0xc], ecx */
    W32((uint32_t)(c->eax + 0x10u), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [eax + 0x10], 0xffffffff */
    W8((uint32_t)(c->eax + 0x14u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax + 0x14], cl */
    W32((uint32_t)(c->eax + 0x18u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x18], ecx */
    W32((uint32_t)(c->eax + 0x1cu), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x1c], ecx */
    W32((uint32_t)(c->eax + 0x20u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x20], ecx */
    W32((uint32_t)(c->eax + 0x24u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x24], ecx */
    W8((uint32_t)(c->eax + 0x28u), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [eax + 0x28], dl */
    W32((uint32_t)(c->eax + 0x2cu), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x2c], ecx */
    W32((uint32_t)(c->eax + 0x30u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x30], ecx */
    W8((uint32_t)(c->eax + 0x34u), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [eax + 0x34], dl */
    W32((uint32_t)(c->eax + 0x38u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x38], ecx */
    W8((uint32_t)(c->eax + 0x3cu), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax + 0x3c], cl */
    W32((uint32_t)(c->eax + 0x40u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x40], ecx */
    W32((uint32_t)(c->eax + 0x44u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 0x44], edx */
    W32((uint32_t)(c->eax + 0x48u), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [eax + 0x48], 0xffffffff */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x9b512cu)); /* mov dword ptr [eax], 0x1002512c */
    W32((uint32_t)(c->eax + 0x320u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x320], ecx */
    c->esp += 4; return; /* ret  */
}

void f_009912e0(CPU *c) { /* FUN_100012e0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x009912e8u); f_00991300(c); /* call 0x991300 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_009912f8; /* je 0x9912f8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x009912f5u); f_00993c50(c); /* call 0x993c50 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_009912f8:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00991300(CPU *c) { /* FUN_10001300 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx), (uint32_t)((uint32_t)0x9b512cu)); /* mov dword ptr [ecx], 0x1002512c */
    { f_00991310(c); return; } /* jmp 0x991310 */
}

void f_00991310(CPU *c) { /* FUN_10001310 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub8(c, R8((uint32_t)(c->esi + 0x14u)), ((uint8_t)c->ebx)); /* cmp byte ptr [esi + 0x14], bl */
    if (c->zf) goto L_00991327; /* je 0x991327 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x50u)); /* lea eax, [esi + 0x50] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00991324u); f_009964a0(c); /* call 0x9964a0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00991327:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_00991334; /* je 0x991334 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x8u)); PUSH32(c, 0x00991334u); call_indirect(c, t_); } /* call dword ptr [ecx + 8] */
L_00991334:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x18u))); /* mov eax, dword ptr [esi + 0x18] */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0xc], ebx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_00991347; /* je 0x991347 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00991344u); f_00993c50(c); /* call 0x993c50 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00991347:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x1cu))); /* mov eax, dword ptr [esi + 0x1c] */
    W32((uint32_t)(c->esi + 0x18u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x18], ebx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_0099135a; /* je 0x99135a */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00991357u); f_00993c50(c); /* call 0x993c50 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_0099135a:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x2cu))); /* mov ecx, dword ptr [esi + 0x2c] */
    W32((uint32_t)(c->esi + 0x1cu), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x1c], ebx */
    (void)sub32(c, c->ecx, c->ebx); /* cmp ecx, ebx */
    if (c->zf) goto L_0099136a; /* je 0x99136a */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t t_ = R32((uint32_t)(c->edx)); PUSH32(c, 0x0099136au); call_indirect(c, t_); } /* call dword ptr [edx] */
L_0099136a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov eax, dword ptr [esi + 0x20] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(0x9b5010u))); /* mov edi, dword ptr [0x10025010] */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    W32((uint32_t)(c->esi + 0x2cu), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x2c], ebx */
    if (c->zf) goto L_00991381; /* je 0x991381 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = c->edi; PUSH32(c, 0x0099137eu); call_indirect(c, t_); } /* call edi */
    W32((uint32_t)(c->esi + 0x20u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x20], ebx */
L_00991381:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov eax, dword ptr [esi + 0x24] */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_0099138e; /* je 0x99138e */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = c->edi; PUSH32(c, 0x0099138bu); call_indirect(c, t_); } /* call edi */
    W32((uint32_t)(c->esi + 0x24u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x24], ebx */
L_0099138e:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (c->zf) goto L_009913bf; /* je 0x9913bf */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x9b500cu)); PUSH32(c, 0x009913a2u); call_indirect(c, t_); } /* call dword ptr [0x1002500c] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (c->zf) goto L_009913b8; /* je 0x9913b8 */
    c->eax = (uint32_t)(R32((uint32_t)(0x9cdfb4u))); /* mov eax, dword ptr [0x1003dfb4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x009913b8u); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
L_009913b8:;
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [esi + 0x10], 0xffffffff */
L_009913bf:;
    W8((uint32_t)(c->esi + 0x14u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [esi + 0x14], bl */
    W8((uint32_t)(c->esi + 0x34u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esi + 0x34], 1 */
    W32((uint32_t)(c->esi + 0x38u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x38], ebx */
    W32((uint32_t)(c->esi + 0x30u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x30], ebx */
    W8((uint32_t)(c->esi + 0x3cu), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [esi + 0x3c], bl */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_009913e0(CPU *c) { /* FUN_100013e0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x9b3cb7u; PUSH32(c, v_); } /* push 0x10023cb7 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x10], esp */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x1c], edi */
    if (c->zf) goto L_00991422; /* je 0x991422 */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00991422; /* je 0x991422 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00991422; /* je 0x991422 */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    goto L_00991424; /* jmp 0x991424 */
L_00991422:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00991424:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(!c->zf ? 1 : 0); /* setne al */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00991450; /* jne 0x991450 */
    c->eax = (uint32_t)(R32((uint32_t)(0x9cdfb0u))); /* mov eax, dword ptr [0x1003dfb0] */
    { uint32_t v_ = 0x9b7104u; PUSH32(c, v_); } /* push 0x10027104 */
    { uint32_t v_ = 0x8cu; PUSH32(c, v_); } /* push 0x8c */
    { uint32_t v_ = 0x9b70d4u; PUSH32(c, v_); } /* push 0x100270d4 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x9b70a0u; PUSH32(c, v_); } /* push 0x100270a0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x0099144cu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x0099144fu, "int3"); /* int3  */
L_00991450:;
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    PUSH32(c, 0x00991457u); f_00991310(c); /* call 0x991310 */
    c->edx = (uint32_t)(R32((uint32_t)(0x9cdfb4u))); /* mov edx, dword ptr [0x1003dfb4] */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x80000000u; PUSH32(c, v_); } /* push 0x80000000 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov ecx, dword ptr [edx + 4] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ebp - 4], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4u)); PUSH32(c, 0x00991476u); call_indirect(c, t_); } /* call dword ptr [eax + 4] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    W32((uint32_t)(c->edi + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [edi + 0x10], eax */
    if (!c->zf) goto L_009914b6; /* jne 0x9914b6 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x9b708cu; PUSH32(c, v_); } /* push 0x1002708c */
    { uint32_t v_ = 0x9bd5d0u; PUSH32(c, v_); } /* push 0x1002d5d0 */
    PUSH32(c, 0x0099148eu); f_00997f15(c); /* call 0x997f15 */
    c->eax = (uint32_t)(R32((uint32_t)(0x9cdfb0u))); /* mov eax, dword ptr [0x1003dfb0] */
    { uint32_t v_ = 0x9bd5d0u; PUSH32(c, v_); } /* push 0x1002d5d0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x0099149eu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->edx = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea edx, [ebp - 0x14] */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x9bd5d0u)); /* mov dword ptr [ebp - 0x14], 0x1002d5d0 */
    { uint32_t v_ = 0x9b6168u; PUSH32(c, v_); } /* push 0x10026168 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x009914b6u); f_00998367(c); /* call 0x998367 */
L_009914b6:;
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x10u)); /* sub esp, 0x10 */
    W8((uint32_t)(c->edi + 0x14u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [edi + 0x14], 1 */
    c->edx = (uint32_t)(R32((uint32_t)(0x9b7040u))); /* mov edx, dword ptr [0x10027040] */
    c->ecx = (uint32_t)(c->esp); /* mov ecx, esp */
    c->ebx = (uint32_t)((uint32_t)(c->edi + 0x50u)); /* lea ebx, [edi + 0x50] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    c->edx = (uint32_t)(R32((uint32_t)(0x9b7044u))); /* mov edx, dword ptr [0x10027044] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 4], edx */
    c->edx = (uint32_t)(R32((uint32_t)(0x9b7048u))); /* mov edx, dword ptr [0x10027048] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 8], edx */
    c->edx = (uint32_t)(R32((uint32_t)(0x9b704cu))); /* mov edx, dword ptr [0x1002704c] */
    W32((uint32_t)(c->ecx + 0xcu), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 0xc], edx */
    PUSH32(c, 0x009914f0u); f_009965a0(c); /* call 0x9965a0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf == c->of)) goto L_0099150c; /* jge 0x99150c */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe8u)); /* lea eax, [ebp - 0x18] */
    { uint32_t v_ = 0x9b6168u; PUSH32(c, v_); } /* push 0x10026168 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)((uint32_t)0x9b7070u)); /* mov dword ptr [ebp - 0x18], 0x10027070 */
    PUSH32(c, 0x0099150cu); f_00998367(c); /* call 0x998367 */
L_0099150c:;
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00991514u); f_00997af0(c); /* call 0x997af0 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->eax = (uint32_t)((uint32_t)(c->edi + 0x50u)); /* lea eax, [edi + 0x50] */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00991521u); f_00996e80(c); /* call 0x996e80 */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x20], edx */
    FPUSH(c, (double)(int64_t)R64((uint32_t)(c->ebp + 0xffffffdcu))); /* fild qword ptr [ebp - 0x24] */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(0x9b5130u))); /* fmul qword ptr [0x10025130] */
    PUSH32(c, 0x00991535u); f_00998340(c); /* call 0x998340 */
    c->edx = (uint32_t)(c->esi); /* mov edx, esi */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    W32((uint32_t)(c->edi + 0x44u), (uint32_t)(c->eax)); /* mov dword ptr [edi + 0x44], eax */
    { uint32_t v_ = 0xadu; PUSH32(c, v_); } /* push 0xad */
    W32((uint32_t)(c->edx), (uint32_t)(c->ecx)); /* mov dword ptr [edx], ecx */
    { uint32_t v_ = 0x9b70d4u; PUSH32(c, v_); } /* push 0x100270d4 */
    { uint32_t v_ = 0x1000u; PUSH32(c, v_); } /* push 0x1000 */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [edx + 4], ecx */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [edx + 8], ecx */
    W32((uint32_t)(c->edx + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [edx + 0xc], ecx */
    W16((uint32_t)(c->edx + 0x10u), (uint16_t)(((uint16_t)c->ecx))); /* mov word ptr [edx + 0x10], cx */
    W16((uint32_t)(c->esi), (uint16_t)((uint16_t)0x1u)); /* mov word ptr [esi], 1 */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ebx + 0x4u))); /* mov ax, word ptr [ebx + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edx, dword ptr [ebp + 0x10] */
    W16((uint32_t)(c->esi + 0x2u), (uint16_t)(((uint16_t)c->eax))); /* mov word ptr [esi + 2], ax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov ecx, dword ptr [ebx + 8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(add16(c, ((uint16_t)c->eax), ((uint16_t)c->eax))); /* add ax, ax */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 4], ecx */
    W16((uint32_t)(c->esi + 0xcu), (uint16_t)(((uint16_t)c->eax))); /* mov word ptr [esi + 0xc], ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xffffu))); /* and eax, 0xffff */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)c->ecx; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, ecx */
    W16((uint32_t)(c->esi + 0xeu), (uint16_t)((uint16_t)0x10u)); /* mov word ptr [esi + 0xe], 0x10 */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 8], eax */
    W32((uint32_t)(c->edx), (uint32_t)((uint32_t)0x3c000u)); /* mov dword ptr [edx], 0x3c000 */
    PUSH32(c, 0x00991593u); f_00993c30(c); /* call 0x993c30 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    W32((uint32_t)(c->edi + 0x1cu), (uint32_t)(c->eax)); /* mov dword ptr [edi + 0x1c], eax */
    { uint32_t v_ = 0xaeu; PUSH32(c, v_); } /* push 0xae */
    { uint32_t v_ = 0x9b70d4u; PUSH32(c, v_); } /* push 0x100270d4 */
    { uint32_t v_ = 0x1000u; PUSH32(c, v_); } /* push 0x1000 */
    PUSH32(c, 0x009915adu); f_00993c30(c); /* call 0x993c30 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->edi + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [edi + 0x18], eax */
    { uint32_t v_ = 0xafu; PUSH32(c, v_); } /* push 0xaf */
    { uint32_t v_ = 0x9b70d4u; PUSH32(c, v_); } /* push 0x100270d4 */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    PUSH32(c, 0x009915c4u); f_00993c30(c); /* call 0x993c30 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [ebp + 0xc], ecx */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    W8((uint32_t)(c->ebp + 0xfffffffcu), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ebp - 4], 1 */
    if (c->zf) goto L_009915fd; /* je 0x9915fd */
    { uint32_t v_ = 0x1e000u; PUSH32(c, v_); } /* push 0x1e000 */
    PUSH32(c, 0x009915deu); f_00995c20(c); /* call 0x995c20 */
    W32((uint32_t)(c->edi + 0x2cu), (uint32_t)(c->eax)); /* mov dword ptr [edi + 0x2c], eax */
    W32((uint32_t)(c->edi + 0x40u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [edi + 0x40], 0 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 16; return; /* ret 0xc */
L_009915fd:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W32((uint32_t)(c->edi + 0x2cu), (uint32_t)(c->eax)); /* mov dword ptr [edi + 0x2c], eax */
    W32((uint32_t)(c->edi + 0x40u), (uint32_t)(c->eax)); /* mov dword ptr [edi + 0x40], eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 16; return; /* ret 0xc */
}

void f_0099161a(CPU *c) { /* Catch@1000161a */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x9cdfb4u))); /* mov eax, dword ptr [0x1003dfb4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x00991629u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov esi, dword ptr [ebp - 0x1c] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0099164c; /* je 0x99164c */
    c->ecx = (uint32_t)(R32((uint32_t)(0x9cdfb4u))); /* mov ecx, dword ptr [0x1003dfb4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ecx, dword ptr [ecx + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x00991645u); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [esi + 0x10], 0xffffffff */
L_0099164c:;
    c->eax = (uint32_t)((uint32_t)0x991652u); /* mov eax, 0x10001652 */
    c->esp += 4; return; /* ret  */
}

void f_00991652(CPU *c) { /* PTR_00991652 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 16; return; /* ret 0xc */
}

void f_00991670(CPU *c) { /* FUN_10001670 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x10u)); /* sub esp, 0x10 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x14u))); /* mov al, byte ptr [esi + 0x14] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00991686; /* jne 0x991686 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 12; return; /* ret 8 */
L_00991686:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(0x9b5014u))); /* mov edi, dword ptr [0x10025014] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00991698u); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    W32((uint32_t)(c->esi + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x20], eax */
    { uint32_t t_ = c->edi; PUSH32(c, 0x009916a5u); call_indirect(c, t_); } /* call edi */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov ebx, dword ptr [esp + 0x20] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov ecx, dword ptr [esi + 0x20] */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0xcu)); /* lea edi, [esi + 0xc] */
    W32((uint32_t)(c->esi + 0x24u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x24], eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov edx, dword ptr [ebx] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x9b5420u; PUSH32(c, v_); } /* push 0x10025420 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x18], 0 */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x1c], ecx */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)((uint32_t)0x1e000u)); /* mov dword ptr [esp + 0x20], 0x1e000 */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x24], eax */
    { uint32_t t_ = R32((uint32_t)(c->edx)); PUSH32(c, 0x009916d5u); call_indirect(c, t_); } /* call dword ptr [edx] */
    (void)sub32(c, R32((uint32_t)(c->edi)), (uint32_t)0x0u); /* cmp dword ptr [edi], 0 */
    if (!c->zf) goto L_009916fd; /* jne 0x9916fd */
    c->eax = (uint32_t)(R32((uint32_t)(0x9cdfb0u))); /* mov eax, dword ptr [0x1003dfb0] */
    { uint32_t v_ = 0x9b7140u; PUSH32(c, v_); } /* push 0x10027140 */
    { uint32_t v_ = 0xd7u; PUSH32(c, v_); } /* push 0xd7 */
    { uint32_t v_ = 0x9b70d4u; PUSH32(c, v_); } /* push 0x100270d4 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x9b70a0u; PUSH32(c, v_); } /* push 0x100270a0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x009916f9u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x009916fcu, "int3"); /* int3  */
L_009916fd:;
    c->edi = (uint32_t)(R32((uint32_t)(c->edi))); /* mov edi, dword ptr [edi] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0xcu)); /* lea eax, [esp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi))); /* mov edx, dword ptr [edi] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x0099170cu); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00991733; /* je 0x991733 */
    c->eax = (uint32_t)(R32((uint32_t)(0x9cdfb0u))); /* mov eax, dword ptr [0x1003dfb0] */
    { uint32_t v_ = 0x9b712cu; PUSH32(c, v_); } /* push 0x1002712c */
    { uint32_t v_ = 0xdau; PUSH32(c, v_); } /* push 0xda */
    { uint32_t v_ = 0x9b70d4u; PUSH32(c, v_); } /* push 0x100270d4 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x9b70a0u; PUSH32(c, v_); } /* push 0x100270a0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x0099172fu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00991732u, "int3"); /* int3  */
L_00991733:;
    W32((uint32_t)(c->esi + 0x48u), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [esi + 0x48], 0xffffffff */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
L_0099173c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3cu))); /* mov al, byte ptr [esi + 0x3c] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00991774; /* jne 0x991774 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x0099174fu); f_00991ab0(c); /* call 0x991ab0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x2cu))); /* mov ecx, dword ptr [esi + 0x2c] */
    PUSH32(c, 0x00991757u); f_00995d90(c); /* call 0x995d90 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_0099176f; /* je 0x99176f */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov edx, dword ptr [esi + 8] */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x28u))); /* mov cl, byte ptr [esi + 0x28] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx + 0x1au))); /* mov al, byte ptr [edx + 0x1a] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x0099176eu); f_009918a0(c); /* call 0x9918a0 */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
L_0099176f:;
    (void)sub32(c, c->edi, (uint32_t)0x2u); /* cmp edi, 2 */
    if ((c->sf != c->of)) goto L_0099173c; /* jl 0x99173c */
L_00991774:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 12; return; /* ret 8 */
}

void f_00991780(CPU *c) { /* FUN_10001780 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x9b3cd0u; PUSH32(c, v_); } /* push 0x10023cd0 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov edx, dword ptr [esi + 0x10] */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x10], esp */
    (void)sub32(c, c->edx, c->ebx); /* cmp edx, ebx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(!c->zf ? 1 : 0); /* setne al */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_009917d4; /* jne 0x9917d4 */
    c->eax = (uint32_t)(R32((uint32_t)(0x9cdfb0u))); /* mov eax, dword ptr [0x1003dfb0] */
    { uint32_t v_ = 0x9b714cu; PUSH32(c, v_); } /* push 0x1002714c */
    { uint32_t v_ = 0xf7u; PUSH32(c, v_); } /* push 0xf7 */
    { uint32_t v_ = 0x9b70d4u; PUSH32(c, v_); } /* push 0x100270d4 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x9b70a0u; PUSH32(c, v_); } /* push 0x100270a0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x009917d0u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x009917d3u, "int3"); /* int3  */
L_009917d4:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x14u))); /* mov al, byte ptr [esi + 0x14] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_0099188b; /* je 0x99188b */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x2cu)), c->ebx); /* cmp dword ptr [esi + 0x2c], ebx */
    if (c->zf) goto L_0099188b; /* je 0x99188b */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 4], ebx */
L_009917eb:;
    (void)sub32(c, c->ebx, (uint32_t)0x8u); /* cmp ebx, 8 */
    if ((c->sf == c->of)) goto L_00991855; /* jge 0x991855 */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi + 0x18u))); /* mov edi, dword ptr [esi + 0x18] */
    c->edx = (uint32_t)((uint32_t)(c->esi + 0x324u)); /* lea edx, [esi + 0x324] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)((uint32_t)0x400u); /* mov ecx, 0x400 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x18u))); /* mov eax, dword ptr [esi + 0x18] */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x50u)); /* lea edi, [esi + 0x50] */
    { uint32_t v_ = 0x1000u; PUSH32(c, v_); } /* push 0x1000 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x0099181au); f_00997b30(c); /* call 0x997b30 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((!c->zf && c->sf == c->of)) goto L_0099186a; /* jg 0x99186a */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0x8u))); /* mov al, byte ptr [ebp + 8] */
    W32((uint32_t)(c->esi + 0x48u), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [esi + 0x48], 2 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00991855; /* je 0x991855 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00991839u); f_009975c0(c); /* call 0x9975c0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    PUSH32(c, 0x00991840u); f_00993be0(c); /* call 0x993be0 */
    WF32((uint32_t)(c->ebp + 0x8u), (float)ST(0)); /* fst dword ptr [ebp + 8] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    PUSH32(c, 0x0099184bu); f_00998340(c); /* call 0x998340 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ecx, dword ptr [esi + 8] */
    W32((uint32_t)(c->ecx + 0x34u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 0x34], eax */
    W8((uint32_t)(c->esi + 0x3cu), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esi + 0x3c], 0 */
L_00991855:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 8; return; /* ret 4 */
L_0099186a:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x38u))); /* mov edx, dword ptr [esi + 0x38] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x2cu))); /* mov ecx, dword ptr [esi + 0x2c] */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(c->esi + 0x38u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x38], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x18u))); /* mov edx, dword ptr [esi + 0x18] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x0099187fu); f_00995d20(c); /* call 0x995d20 */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    goto L_009917eb; /* jmp 0x9917eb */
L_0099188b:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 8; return; /* ret 4 */
}

void f_00991885(CPU *c) { /* Catch@10001885 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x99188bu); /* mov eax, 0x1000188b */
    c->esp += 4; return; /* ret  */
}

void f_0099188b(CPU *c) { /* PTR_0099188b */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 8; return; /* ret 4 */
}

void f_009918a0(CPU *c) { /* FUN_100018a0 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x14u)); /* sub esp, 0x14 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x48u))); /* mov eax, dword ptr [esi + 0x48] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (c->zf) goto L_0099199b; /* je 0x99199b */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00991997; /* jne 0x991997 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1au))); /* mov cl, byte ptr [eax + 0x1a] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_00991978; /* je 0x991978 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x50u)); /* lea eax, [esi + 0x50] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x009918d7u); f_009975c0(c); /* call 0x9975c0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ecx, dword ptr [esi + 8] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->ecx + 0x38u))); /* fild dword ptr [ecx + 0x38] */
    WF32((uint32_t)(c->esp), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp] */
    PUSH32(c, 0x009918e8u); f_00993be0(c); /* call 0x993be0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    PUSH32(c, 0x009918f0u); f_00998340(c); /* call 0x998340 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov edx, dword ptr [esi + 8] */
    W32((uint32_t)(c->edx + 0x34u), (uint32_t)(c->eax)); /* mov dword ptr [edx + 0x34], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    W8((uint32_t)(c->esi + 0x3cu), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esi + 0x3c], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov eax, dword ptr [eax + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x48u)); PUSH32(c, 0x00991906u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x48] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov edx, dword ptr [esi + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov eax, dword ptr [edx + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x34u)); PUSH32(c, 0x00991914u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x34] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov ebp, dword ptr [esp + 0x24] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea eax, [esp + 0x14] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x1cu)); /* lea ecx, [esp + 0x1c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov edx, dword ptr [ebp] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x1cu)); /* lea eax, [esp + 0x1c] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x18u)); /* lea ecx, [esp + 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x3c000u; PUSH32(c, v_); } /* push 0x3c000 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x2cu)); PUSH32(c, 0x0099193cu); call_indirect(c, t_); } /* call dword ptr [edx + 0x2c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00991985; /* jne 0x991985 */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edi, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)((uint32_t)0xf000u); /* mov ecx, 0xf000 */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov ecx, dword ptr [esp + 0x18] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov edx, dword ptr [ebp] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ecx, dword ptr [esp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x4cu)); PUSH32(c, 0x00991966u); call_indirect(c, t_); } /* call dword ptr [edx + 0x4c] */
    W32((uint32_t)(c->esi + 0x48u), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [esi + 0x48], 0xffffffff */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esp += 16; return; /* ret 0xc */
L_00991978:;
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov eax, dword ptr [eax + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x48u)); PUSH32(c, 0x00991981u); call_indirect(c, t_); } /* call dword ptr [edx + 0x48] */
    W8((uint32_t)(c->esi + 0x3cu), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esi + 0x3c], 1 */
L_00991985:;
    W32((uint32_t)(c->esi + 0x48u), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [esi + 0x48], 0xffffffff */
L_0099198c:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esp += 16; return; /* ret 0xc */
L_00991997:;
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    W32((uint32_t)(c->esi + 0x48u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x48], eax */
L_0099199b:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x2cu))); /* mov ecx, dword ptr [esi + 0x2c] */
    PUSH32(c, 0x009919a3u); f_00995d90(c); /* call 0x995d90 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_009919af; /* jne 0x9919af */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x2cu))); /* mov ecx, dword ptr [esi + 0x2c] */
    PUSH32(c, 0x009919afu); f_00995db0(c); /* call 0x995db0 */
L_009919af:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x14u))); /* mov al, byte ptr [esi + 0x14] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_0099198c; /* je 0x99198c */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x2cu))); /* mov eax, dword ptr [esi + 0x2c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0099198c; /* je 0x99198c */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x28u))); /* mov al, byte ptr [esp + 0x28] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov ebp, dword ptr [esp + 0x24] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea ecx, [esp + 0x14] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x18u)); /* lea edx, [esp + 0x18] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x18u)); /* lea ecx, [esp + 0x18] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x18u)); /* lea edx, [esp + 0x18] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    W8((uint32_t)(c->esi + 0x28u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [esi + 0x28], al */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov eax, dword ptr [ebp] */
    { uint32_t v_ = 0x1e000u; PUSH32(c, v_); } /* push 0x1e000 */
    if (c->zf) goto L_009919ee; /* je 0x9919ee */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    goto L_009919f3; /* jmp 0x9919f3 */
L_009919ee:;
    { uint32_t v_ = 0x1e000u; PUSH32(c, v_); } /* push 0x1e000 */
L_009919f3:;
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x2cu)); PUSH32(c, 0x009919f7u); call_indirect(c, t_); } /* call dword ptr [eax + 0x2c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00991a40; /* je 0x991a40 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov eax, dword ptr [ebp] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x50u)); PUSH32(c, 0x00991a02u); call_indirect(c, t_); } /* call dword ptr [eax + 0x50] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_0099198c; /* jne 0x99198c */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x28u))); /* mov al, byte ptr [esi + 0x28] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov ecx, dword ptr [ebp] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea edx, [esp + 0x14] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x1cu)); /* lea eax, [esp + 0x1c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x18u)); /* lea edx, [esp + 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x18u)); /* lea eax, [esp + 0x18] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x1e000u; PUSH32(c, v_); } /* push 0x1e000 */
    if (c->zf) goto L_00991a2f; /* je 0x991a2f */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    goto L_00991a34; /* jmp 0x991a34 */
L_00991a2f:;
    { uint32_t v_ = 0x1e000u; PUSH32(c, v_); } /* push 0x1e000 */
L_00991a34:;
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x2cu)); PUSH32(c, 0x00991a38u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x2c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_0099198c; /* jne 0x99198c */
L_00991a40:;
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edi, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)((uint32_t)0x7800u); /* mov ecx, 0x7800 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x1c], 0 */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x1cu)); /* lea ecx, [esp + 0x1c] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x2cu))); /* mov ecx, dword ptr [esi + 0x2c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00991a6cu); f_00995cb0(c); /* call 0x995cb0 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edx, dword ptr [esp + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov ecx, dword ptr [ebp] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edx, dword ptr [esp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x4cu)); PUSH32(c, 0x00991a87u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x4c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_0099198c; /* jne 0x99198c */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x28u))); /* mov al, byte ptr [esi + 0x28] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete cl */
    W8((uint32_t)(c->esi + 0x28u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esi + 0x28], cl */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esp += 16; return; /* ret 0xc */
}

void f_00991ab0(CPU *c) { /* FUN_10001ab0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x9b3ce0u; PUSH32(c, v_); } /* push 0x10023ce0 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x10], esp */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ecx, dword ptr [esi + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x34u))); /* mov eax, dword ptr [ecx + 0x34] */
    (void)sub32(c, c->eax, (uint32_t)0xffff2bcfu); /* cmp eax, 0xffff2bcf */
    if (c->zf) goto L_00991b15; /* je 0x991b15 */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->ebp + 0x10u)))); /* sub eax, dword ptr [ebp + 0x10] */
    W32((uint32_t)(c->ecx + 0x34u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 0x34], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x34u))); /* mov ecx, dword ptr [eax + 0x34] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if ((!c->zf && c->sf == c->of)) goto L_00991b15; /* jg 0x991b15 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1bu))); /* mov cl, byte ptr [eax + 0x1b] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_00991b15; /* je 0x991b15 */
    W32((uint32_t)(c->eax + 0x34u), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [eax + 0x34], 0xffffffff */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov eax, dword ptr [eax + 4] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x00991b0eu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    W32((uint32_t)(c->esi + 0x40u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 0x40], 0 */
L_00991b15:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov eax, dword ptr [esi + 0x20] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00991b91; /* je 0x991b91 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x2cu))); /* mov ecx, dword ptr [esi + 0x2c] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00991b91; /* je 0x991b91 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3cu))); /* mov al, byte ptr [esi + 0x3c] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00991b91; /* jne 0x991b91 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ebp - 4], 0 */
    PUSH32(c, 0x00991b36u); f_00995d90(c); /* call 0x995d90 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00991b5e; /* jne 0x991b5e */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x48u)), (uint32_t)0xffffffffu); /* cmp dword ptr [esi + 0x48], -1 */
    if (!c->zf) goto L_00991b5e; /* jne 0x991b5e */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00991b4bu); f_00991780(c); /* call 0x991780 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 16; return; /* ret 0xc */
L_00991b5e:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov eax, dword ptr [esi + 0x20] */
    c->ebx = (uint32_t)(R32((uint32_t)(0x9b501cu))); /* mov ebx, dword ptr [0x1002501c] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = c->ebx; PUSH32(c, 0x00991b6cu); call_indirect(c, t_); } /* call ebx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00991bc3; /* jne 0x991bc3 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x40u))); /* mov ecx, dword ptr [esi + 0x40] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x30u))); /* mov eax, dword ptr [esi + 0x30] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x1e000u)); /* add ecx, 0x1e000 */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    W32((uint32_t)(c->esi + 0x40u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 0x40], ecx */
    if ((c->sf == c->of)) goto L_00991ba4; /* jge 0x991ba4 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov ecx, dword ptr [esi + 0x20] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t t_ = R32((uint32_t)(0x9b5018u)); PUSH32(c, 0x00991b8eu); call_indirect(c, t_); } /* call dword ptr [0x10025018] */
L_00991b8e:;
    { uint32_t a_ = (uint32_t)(c->esi + 0x30u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [esi + 0x30] */
L_00991b91:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 16; return; /* ret 0xc */
L_00991ba4:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov edx, dword ptr [esi + 0x20] */
    c->edi = (uint32_t)(R32((uint32_t)(0x9b5018u))); /* mov edi, dword ptr [0x10025018] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00991bb0u); call_indirect(c, t_); } /* call edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00991bc1u); f_009918a0(c); /* call 0x9918a0 */
    goto L_00991bc9; /* jmp 0x991bc9 */
L_00991bc3:;
    c->edi = (uint32_t)(R32((uint32_t)(0x9b5018u))); /* mov edi, dword ptr [0x10025018] */
L_00991bc9:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov edx, dword ptr [esi + 0x24] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = c->ebx; PUSH32(c, 0x00991bd1u); call_indirect(c, t_); } /* call ebx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00991b91; /* jne 0x991b91 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x40u))); /* mov ecx, dword ptr [esi + 0x40] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x30u))); /* mov eax, dword ptr [esi + 0x30] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x1e000u)); /* add ecx, 0x1e000 */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    W32((uint32_t)(c->esi + 0x40u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 0x40], ecx */
    if ((c->sf == c->of)) goto L_00991bf1; /* jge 0x991bf1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov eax, dword ptr [esi + 0x24] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00991befu); call_indirect(c, t_); } /* call edi */
    goto L_00991b8e; /* jmp 0x991b8e */
L_00991bf1:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov ecx, dword ptr [esi + 0x24] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00991bf7u); call_indirect(c, t_); } /* call edi */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00991c08u); f_009918a0(c); /* call 0x9918a0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 16; return; /* ret 0xc */
}

void f_00991b91(CPU *c) { /* PTR_00991b91 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 16; return; /* ret 0xc */
}

void f_00991c1b(CPU *c) { /* Catch@10001c1b */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x991b91u); /* mov eax, 0x10001b91 */
    c->esp += 4; return; /* ret  */
}

void f_00991c30(CPU *c) { /* PTR_00991c30 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 4], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov eax, dword ptr [eax + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00991c58; /* je 0x991c58 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x8u)); /* lea edx, [esp + 8] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x8u)); /* lea edx, [esp + 8] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x10u)); PUSH32(c, 0x00991c58u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x10] */
L_00991c58:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x44u))); /* mov eax, dword ptr [esi + 0x44] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00991c87; /* je 0x991c87 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x40u))); /* mov ecx, dword ptr [esi + 0x40] */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0xc], 0 */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 8], ecx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    FPUSH(c, (double)(int64_t)R64((uint32_t)(c->esp + 0x4u))); /* fild qword ptr [esp + 4] */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 4], eax */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 8], 0 */
    ST(0) = FPRES(c, FDIV(c, ST(0), (double)(int32_t)R32((uint32_t)(c->esp + 0x4u)))); /* fidiv dword ptr [esp + 4] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
L_00991c87:;
    FPUSH(c, (double)RF32((uint32_t)(0x9b5124u))); /* fld dword ptr [0x10025124] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00991ca0(CPU *c) { /* PTR_00991ca0 */
    PREEMPT_POLL(c);
    PUSH32(c, 0x00991ca5u); f_00991cb0(c); /* call 0x991cb0 */
    goto L_00991ce0; /* jmp 0x991ce0 */
L_00991ce0:;
    { uint32_t v_ = 0x991cf0u; PUSH32(c, v_); } /* push 0x10001cf0 */
    PUSH32(c, 0x00991ceau); f_0099841f(c); /* call 0x99841f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00991cb0(CPU *c) { /* PTR_00991cb0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)0x9bddd0u); /* mov ecx, 0x1002ddd0 */
    c->eax = (uint32_t)((uint32_t)0xfa00u); /* mov eax, 0xfa00 */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
L_00991cbc:;
    W32((uint32_t)(c->eax + 0x9bddd0u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 0x1002ddd0], edx */
    W8((uint32_t)(c->ecx), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [ecx], dl */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x4u)); /* add eax, 4 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x80u)); /* add ecx, 0x80 */
    (void)sub32(c, c->eax, (uint32_t)0x101d0u); /* cmp eax, 0x101d0 */
    if ((c->sf != c->of)) goto L_00991cbc; /* jl 0x991cbc */
    c->esp += 4; return; /* ret  */
}

void f_00991cf0(CPU *c) { /* PTR_00991cf0 */
    PREEMPT_POLL(c);
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x9cdfa0u))); /* mov cl, byte ptr [0x1003dfa0] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->ecx))); /* test al, cl */
    if (!c->zf) goto L_00991d33; /* jne 0x991d33 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->ecx) | ((uint8_t)c->eax)))); /* or cl, al */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W8((uint32_t)(0x9cdfa0u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [0x1003dfa0], cl */
    c->esi = (uint32_t)((uint32_t)0xfa00u); /* mov esi, 0xfa00 */
L_00991d0a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x9bddd0u))); /* mov eax, dword ptr [esi + 0x1002ddd0] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00991d27; /* je 0x991d27 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00991d1au); f_00993c50(c); /* call 0x993c50 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    W32((uint32_t)(c->esi + 0x9bddd0u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 0x1002ddd0], 0 */
L_00991d27:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, c->esi, (uint32_t)0x101d0u); /* cmp esi, 0x101d0 */
    if ((c->sf != c->of)) goto L_00991d0a; /* jl 0x991d0a */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00991d33:;
    c->esp += 4; return; /* ret  */
}

void f_00991d40(CPU *c) { /* FUN_10001d40 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x9cdfb4u))); /* mov eax, dword ptr [0x1003dfb4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x14u; PUSH32(c, v_); } /* push 0x14 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x00991d59u); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(0x9cdfb4u))); /* mov eax, dword ptr [0x1003dfb4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x8u)); /* lea eax, [esp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = 0x12u; PUSH32(c, v_); } /* push 0x12 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x18u)); PUSH32(c, 0x00991d73u); call_indirect(c, t_); } /* call dword ptr [edx + 0x18] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x9cdfb4u))); /* mov ecx, dword ptr [0x1003dfb4] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x28u; PUSH32(c, v_); } /* push 0x28 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ecx, dword ptr [ecx + 4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x00991d88u); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(0x9cdfb4u))); /* mov eax, dword ptr [0x1003dfb4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x8u)); /* lea eax, [esp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x18u)); PUSH32(c, 0x00991da2u); call_indirect(c, t_); } /* call dword ptr [edx + 0x18] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00991db0(CPU *c) { /* FUN_10001db0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x9cdfb4u))); /* mov eax, dword ptr [0x1003dfb4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x2cu; PUSH32(c, v_); } /* push 0x2c */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x00991dcau); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(0x9cdfb4u))); /* mov eax, dword ptr [0x1003dfb4] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edi, dword ptr [esp + 0x14] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0xcu)); /* lea eax, [esp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x18u)); PUSH32(c, 0x00991de7u); call_indirect(c, t_); } /* call dword ptr [edx + 0x18] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, c->ecx, c->edi); /* cmp ecx, edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete al */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00991e00(CPU *c) { /* FUN_10001e00 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [eax + 0xc], 0xffffffff */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x9b5138u)); /* mov dword ptr [eax], 0x10025138 */
    c->esp += 4; return; /* ret  */
}

void f_00991e10(CPU *c) { /* FUN_10001e10 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00991e18u); f_00991e30(c); /* call 0x991e30 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00991e28; /* je 0x991e28 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00991e25u); f_00993c50(c); /* call 0x993c50 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00991e28:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00991e30(CPU *c) { /* FUN_10001e30 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx), (uint32_t)((uint32_t)0x9b5138u)); /* mov dword ptr [ecx], 0x10025138 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov ecx, dword ptr [ecx + 0xc] */
    (void)sub32(c, c->ecx, (uint32_t)0xffffffffu); /* cmp ecx, -1 */
    if (c->zf) goto L_00991e4c; /* je 0x991e4c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx * 4 + 0x9cd7d0u))); /* mov eax, dword ptr [ecx*4 + 0x1003d7d0] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00991e4c; /* je 0x991e4c */
    { uint32_t a_ = (uint32_t)(c->eax + 0x28u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [eax + 0x28] */
L_00991e4c:;
    c->esp += 4; return; /* ret  */
}

void f_00991e50(CPU *c) { /* FUN_10001e50 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0xcu))); /* mov eax, dword ptr [edi + 0xc] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (c->zf) goto L_00991ebb; /* je 0x991ebb */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax * 4 + 0x9cd7d0u))); /* mov esi, dword ptr [eax*4 + 0x1003d7d0] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00991ebb; /* je 0x991ebb */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov eax, dword ptr [esi + 0x20] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00991ebb; /* je 0x991ebb */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00991e74u); f_00993c50(c); /* call 0x993c50 */
    W32((uint32_t)(c->esi + 0x20u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 0x20], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(0x9cdfa4u))); /* mov edx, dword ptr [0x1003dfa4] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->edx = (uint32_t)(sub32(c, c->edx, c->eax)); /* sub edx, eax */
    W32((uint32_t)(0x9cdfa4u), (uint32_t)(c->edx)); /* mov dword ptr [0x1003dfa4], edx */
    c->esi = (uint32_t)(R32((uint32_t)(c->edi + 0xcu))); /* mov esi, dword ptr [edi + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi * 4 + 0x9cd7d0u))); /* mov eax, dword ptr [esi*4 + 0x1003d7d0] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00991ebb; /* je 0x991ebb */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00991ea3u); f_00993c50(c); /* call 0x993c50 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    W32((uint32_t)(c->esi * 4 + 0x9cd7d0u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi*4 + 0x1003d7d0], 0 */
    c->esi = (uint32_t)(shl32(c, c->esi, 7)); /* shl esi, 7 */
    W8((uint32_t)(c->esi + 0x9bddd0u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esi + 0x1002ddd0], 0 */
L_00991ebb:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00991ec0(CPU *c) { /* FUN_10001ec0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edi, dword ptr [esp + 0xc] */
    (void)sub32(c, c->edi, (uint32_t)0xffffffffu); /* cmp edi, -1 */
    if (c->zf) goto L_00991f27; /* je 0x991f27 */
    c->esi = (uint32_t)(R32((uint32_t)(c->edi * 4 + 0x9cd7d0u))); /* mov esi, dword ptr [edi*4 + 0x1003d7d0] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00991f27; /* je 0x991f27 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov eax, dword ptr [esi + 0x20] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00991f27; /* je 0x991f27 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00991ee3u); f_00993c50(c); /* call 0x993c50 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    W32((uint32_t)(c->esi + 0x20u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 0x20], 0 */
    c->edx = (uint32_t)(R32((uint32_t)(0x9cdfa4u))); /* mov edx, dword ptr [0x1003dfa4] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->edx = (uint32_t)(sub32(c, c->edx, c->eax)); /* sub edx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi * 4 + 0x9cd7d0u))); /* mov eax, dword ptr [edi*4 + 0x1003d7d0] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(0x9cdfa4u), (uint32_t)(c->edx)); /* mov dword ptr [0x1003dfa4], edx */
    if (c->zf) goto L_00991f27; /* je 0x991f27 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00991f0fu); f_00993c50(c); /* call 0x993c50 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    W32((uint32_t)(c->edi * 4 + 0x9cd7d0u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [edi*4 + 0x1003d7d0], 0 */
    c->edi = (uint32_t)(shl32(c, c->edi, 7)); /* shl edi, 7 */
    W8((uint32_t)(c->edi + 0x9bddd0u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [edi + 0x1002ddd0], 0 */
L_00991f27:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00991f30(CPU *c) { /* FUN_10001f30 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov esi, dword ptr [esp + 0x20] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->esi + 0xcu))); /* mov ax, word ptr [esi + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ecx, dword ptr [esi + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov edx, dword ptr [esi + 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov eax, dword ptr [esp + 0x1c] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00991f52u); f_00991db0(c); /* call 0x991db0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00991f61; /* jne 0x991f61 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->esp += 20; return; /* ret 0x10 */
L_00991f61:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ebx, dword ptr [esp + 0x14] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x8u)); /* lea edx, [esp + 8] */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov ecx, dword ptr [ebx] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea eax, [esp + 0x14] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x28u)); /* lea edx, [esp + 0x28] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov edx, dword ptr [esp + 0x2c] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x28u)); /* lea eax, [esp + 0x28] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x2cu)); PUSH32(c, 0x00991f88u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x2c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00991f96; /* je 0x991f96 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->esp += 20; return; /* ret 0x10 */
L_00991f96:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov ecx, dword ptr [esp + 0x20] */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (c->zf) goto L_00991fc4; /* je 0x991fc4 */
    c->eax = (uint32_t)(R32((uint32_t)(0x9cdfb0u))); /* mov eax, dword ptr [0x1003dfb0] */
    { uint32_t v_ = 0x9b7184u; PUSH32(c, v_); } /* push 0x10027184 */
    { uint32_t v_ = 0xa2u; PUSH32(c, v_); } /* push 0xa2 */
    { uint32_t v_ = 0x9b7154u; PUSH32(c, v_); } /* push 0x10027154 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x9b70a0u; PUSH32(c, v_); } /* push 0x100270a0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00991fc0u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00991fc3u, "int3"); /* int3  */
L_00991fc4:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ecx, dword ptr [esi + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov esi, dword ptr [esi + 0x20] */
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov edi, dword ptr [esp + 0x1c] */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u))); /* and ecx, 3 */
    while (c->ecx) { W8(c->edi, R8(c->esi)); c->esi += (c->df ? -1 : 1); c->edi += (c->df ? -1 : 1); c->ecx--; } /* rep movsb byte ptr es:[edi], byte ptr [esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov ecx, dword ptr [esp + 0x28] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov edx, dword ptr [esp + 0x24] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4cu)); PUSH32(c, 0x00991ff7u); call_indirect(c, t_); } /* call dword ptr [eax + 0x4c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete al */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->esp += 20; return; /* ret 0x10 */
}

void f_00992010(CPU *c) { /* FUN_10002010 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x104u)); /* sub esp, 0x104 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x120u))); /* mov eax, dword ptr [esp + 0x120] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x10cu))); /* mov ebx, dword ptr [esp + 0x10c] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x10], ecx */
    W8((uint32_t)(c->eax), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [eax], 1 */
    if (c->zf) goto L_00992205; /* je 0x992205 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x11cu))); /* mov eax, dword ptr [esp + 0x11c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00992205; /* je 0x992205 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x120u))); /* mov eax, dword ptr [esp + 0x120] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00992205; /* je 0x992205 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x124u))); /* mov eax, dword ptr [esp + 0x124] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00992205; /* je 0x992205 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x12cu))); /* mov ecx, dword ptr [esp + 0x12c] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edx = (uint32_t)(c->ebx); /* mov edx, ebx */
    W8((uint32_t)(c->ecx), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [ecx], 0 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebx))); /* mov cl, byte ptr [ebx] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_00992099; /* je 0x992099 */
L_00992078:;
    c->ecx = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->edx))); /* movsx ecx, byte ptr [edx] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0xf0000000u))); /* and ecx, 0xf0000000 */
    if (c->zf) goto L_00992094; /* je 0x992094 */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->esi = (uint32_t)(shr32(c, c->esi, 24)); /* shr esi, 0x18 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi ^ c->ecx))); /* xor esi, ecx */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ c->esi))); /* xor eax, esi */
L_00992094:;
    (void)sub8(c, R8((uint32_t)(c->edx)), (uint8_t)0x0u); /* cmp byte ptr [edx], 0 */
    if (!c->zf) goto L_00992078; /* jne 0x992078 */
L_00992099:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->ecx = (uint32_t)((uint32_t)0x1f4u); /* mov ecx, 0x1f4 */
    { uint32_t d_ = c->ecx; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x009920a0u, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div ecx */
    c->esi = (uint32_t)(c->ebx); /* mov esi, ebx */
    c->edi = (uint32_t)(c->edx); /* mov edi, edx */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->eax = (uint32_t)(shl32(c, c->eax, 7)); /* shl eax, 7 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x9bddd0u)); /* add eax, 0x1002ddd0 */
L_009920b0:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(((uint8_t)c->edx)); /* mov cl, dl */
    (void)sub8(c, ((uint8_t)c->edx), R8((uint32_t)(c->esi))); /* cmp dl, byte ptr [esi] */
    if (!c->zf) goto L_009920d4; /* jne 0x9920d4 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_009920d0; /* je 0x9920d0 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1u))); /* mov dl, byte ptr [eax + 1] */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(((uint8_t)c->edx)); /* mov cl, dl */
    (void)sub8(c, ((uint8_t)c->edx), R8((uint32_t)(c->esi + 0x1u))); /* cmp dl, byte ptr [esi + 1] */
    if (!c->zf) goto L_009920d4; /* jne 0x9920d4 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x2u)); /* add eax, 2 */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x2u)); /* add esi, 2 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_009920b0; /* jne 0x9920b0 */
L_009920d0:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_009920d9; /* jmp 0x9920d9 */
L_009920d4:;
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, (uint32_t)0xffffffffu)); /* sbb eax, -1 */
L_009920d9:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_009920e6; /* jne 0x9920e6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi * 4 + 0x9cd7d0u))); /* mov eax, dword ptr [edi*4 + 0x1003d7d0] */
    goto L_0099212f; /* jmp 0x99212f */
L_009920e6:;
    c->ebp = (uint32_t)(logic32(c, 0)); /* xor ebp, ebp */
    c->edi = (uint32_t)((uint32_t)0x9bddd0u); /* mov edi, 0x1002ddd0 */
L_009920ed:;
    c->esi = (uint32_t)(c->ebx); /* mov esi, ebx */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
L_009920f1:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(((uint8_t)c->edx)); /* mov cl, dl */
    (void)sub8(c, ((uint8_t)c->edx), R8((uint32_t)(c->esi))); /* cmp dl, byte ptr [esi] */
    if (!c->zf) goto L_00992115; /* jne 0x992115 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_00992111; /* je 0x992111 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1u))); /* mov dl, byte ptr [eax + 1] */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(((uint8_t)c->edx)); /* mov cl, dl */
    (void)sub8(c, ((uint8_t)c->edx), R8((uint32_t)(c->esi + 0x1u))); /* cmp dl, byte ptr [esi + 1] */
    if (!c->zf) goto L_00992115; /* jne 0x992115 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x2u)); /* add eax, 2 */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x2u)); /* add esi, 2 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_009920f1; /* jne 0x9920f1 */
L_00992111:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_0099211a; /* jmp 0x99211a */
L_00992115:;
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, (uint32_t)0xffffffffu)); /* sbb eax, -1 */
L_0099211a:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00992162; /* je 0x992162 */
    c->ebp = (uint32_t)(inc32(c, c->ebp)); /* inc ebp */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x80u)); /* add edi, 0x80 */
    (void)sub32(c, c->ebp, (uint32_t)0x1f4u); /* cmp ebp, 0x1f4 */
    if ((c->sf != c->of)) goto L_009920ed; /* jl 0x9920ed */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_0099212f:;
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x128u))); /* mov esi, dword ptr [esp + 0x128] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    if (c->zf) goto L_00992196; /* je 0x992196 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x20u))); /* mov ecx, dword ptr [eax + 0x20] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00992196; /* je 0x992196 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x28u)), (uint32_t)0x32u); /* cmp dword ptr [eax + 0x28], 0x32 */
    if ((c->sf != c->of)) goto L_0099216b; /* jl 0x99216b */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x130u))); /* mov eax, dword ptr [esp + 0x130] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    W8((uint32_t)(c->eax), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [eax], 0 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x104u)); /* add esp, 0x104 */
    c->esp += 32; return; /* ret 0x1c */
L_00992162:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp * 4 + 0x9cd7d0u))); /* mov eax, dword ptr [ebp*4 + 0x1003d7d0] */
    goto L_0099212f; /* jmp 0x99212f */
L_0099216b:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov edx, dword ptr [ecx + 4] */
    W8((uint32_t)(c->edx + 0x40u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [edx + 0x40], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x28u))); /* mov edx, dword ptr [eax + 0x28] */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    W32((uint32_t)(c->eax + 0x28u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 0x28], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x2cu))); /* mov edx, dword ptr [eax + 0x2c] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    W32((uint32_t)(c->ecx + 0xcu), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 0xc], edx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x104u)); /* add esp, 0x104 */
    c->esp += 32; return; /* ret 0x1c */
L_00992196:;
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea edx, [esp + 0x14] */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->edx = (uint32_t)(sub32(c, c->edx, c->ebx)); /* sub edx, ebx */
L_0099219e:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    W8((uint32_t)(c->edx + c->eax), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [edx + eax], cl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_0099219e; /* jne 0x99219e */
    c->eax = (uint32_t)(R32((uint32_t)(0x9cdfb4u))); /* mov eax, dword ptr [0x1003dfb4] */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x80000000u; PUSH32(c, v_); } /* push 0x80000000 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x20u)); /* lea eax, [esp + 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x4u)); PUSH32(c, 0x009921c3u); call_indirect(c, t_); } /* call dword ptr [edx + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x11cu))); /* mov ecx, dword ptr [esp + 0x11c] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    if (c->zf) goto L_00992205; /* je 0x992205 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x124u))); /* mov edx, dword ptr [esp + 0x124] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x120u))); /* mov edi, dword ptr [esp + 0x120] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x009921e7u); f_00991d40(c); /* call 0x991d40 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00992214; /* jne 0x992214 */
    c->eax = (uint32_t)(R32((uint32_t)(0x9cdfb4u))); /* mov eax, dword ptr [0x1003dfb4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x11cu))); /* mov eax, dword ptr [esp + 0x11c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x00992205u); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
L_00992205:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x104u)); /* add esp, 0x104 */
    c->esp += 32; return; /* ret 0x1c */
L_00992214:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)((uint32_t)0x9bddd0u); /* mov ecx, 0x1002ddd0 */
    PUSH32(c, 0x00992220u); f_009923d0(c); /* call 0x9923d0 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ebx, dword ptr [esp + 0x10] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x124u))); /* mov ebp, dword ptr [esp + 0x124] */
    { uint32_t v_ = 0xe5u; PUSH32(c, v_); } /* push 0xe5 */
    { uint32_t v_ = 0x9b7154u; PUSH32(c, v_); } /* push 0x10027154 */
    W32((uint32_t)(c->ebx + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 0xc], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov ecx, dword ptr [ebp] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00992241u); f_00993c30(c); /* call 0x993c30 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->edx + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [edx + 0x20], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov ecx, dword ptr [ebp] */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0xcu)); /* add edx, 0xc */
    W32((uint32_t)(c->edx), (uint32_t)(c->eax)); /* mov dword ptr [edx], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov ecx, dword ptr [edi + 4] */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [edx + 4], ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [edx + 8], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0xcu))); /* mov ecx, dword ptr [edi + 0xc] */
    W32((uint32_t)(c->edx + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [edx + 0xc], ecx */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->edi + 0x10u))); /* mov ax, word ptr [edi + 0x10] */
    W16((uint32_t)(c->edx + 0x10u), (uint16_t)(((uint16_t)c->eax))); /* mov word ptr [edx + 0x10], ax */
    { uint32_t t_ = R32((uint32_t)(0x9b5020u)); PUSH32(c, 0x0099227au); call_indirect(c, t_); } /* call dword ptr [0x10025020] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    W32((uint32_t)(c->edx + 0x28u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [edx + 0x28], 1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    W8((uint32_t)(c->eax + 0x4u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [eax + 4], 1 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0xcu))); /* mov edx, dword ptr [ebx + 0xc] */
    W32((uint32_t)(c->ecx + 0x2cu), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 0x2c], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov ecx, dword ptr [ebx + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x20u))); /* mov edx, dword ptr [eax + 0x20] */
    W32((uint32_t)(c->ecx + 0x44u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 0x44], edx */
    c->eax = (uint32_t)(R32((uint32_t)(0x9cdfa4u))); /* mov eax, dword ptr [0x1003dfa4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov edx, dword ptr [ebp] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x9cdfa8u))); /* mov ecx, dword ptr [0x1003dfa8] */
    c->eax = (uint32_t)(add32(c, c->eax, c->edx)); /* add eax, edx */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    W32((uint32_t)(0x9cdfa4u), (uint32_t)(c->eax)); /* mov dword ptr [0x1003dfa4], eax */
    if ((c->zf || c->sf != c->of)) goto L_009922be; /* jle 0x9922be */
    W32((uint32_t)(0x9cdfa8u), (uint32_t)(c->eax)); /* mov dword ptr [0x1003dfa8], eax */
L_009922be:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x12cu))); /* mov eax, dword ptr [esp + 0x12c] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    W8((uint32_t)(c->eax), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [eax], 1 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x104u)); /* add esp, 0x104 */
    c->esp += 32; return; /* ret 0x1c */
}

void f_009922e0(CPU *c) { /* FUN_100022e0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi | (uint32_t)0xffffffffu))); /* or esi, 0xffffffff */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi | (uint32_t)0xffffffffu))); /* or edi, 0xffffffff */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->edx = (uint32_t)((uint32_t)0x9cd7d0u); /* mov edx, 0x1003d7d0 */
    c->ebx = (uint32_t)((uint32_t)0x1f4u); /* mov ebx, 0x1f4 */
L_009922f6:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edx))); /* mov eax, dword ptr [edx] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00992313; /* je 0x992313 */
    (void)sub8(c, R8((uint32_t)(c->eax + 0x4u)), (uint8_t)0x0u); /* cmp byte ptr [eax + 4], 0 */
    if (c->zf) goto L_00992313; /* je 0x992313 */
    c->ebp = (uint32_t)(R32((uint32_t)(c->eax + 0x28u))); /* mov ebp, dword ptr [eax + 0x28] */
    (void)logic32(c, (uint32_t)(c->ebp & c->ebp)); /* test ebp, ebp */
    if ((!c->zf && c->sf == c->of)) goto L_00992313; /* jg 0x992313 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (!c->cf) goto L_00992313; /* jae 0x992313 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
L_00992313:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x4u)); /* add edx, 4 */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->zf) goto L_009922f6; /* jne 0x9922f6 */
    (void)sub32(c, c->edi, (uint32_t)0xffffffffu); /* cmp edi, -1 */
    if (c->zf) goto L_00992333; /* je 0x992333 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi * 4 + 0x9cd7d0u))); /* mov eax, dword ptr [edi*4 + 0x1003d7d0] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x9ce2e0u))); /* mov ecx, dword ptr [0x1003e2e0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00992333u); f_00995bb0(c); /* call 0x995bb0 */
L_00992333:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00992340(CPU *c) { /* FUN_10002340 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_0099234d; /* jne 0x99234d */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    c->esp += 8; return; /* ret 4 */
L_0099234d:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ecx, dword ptr [ecx + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x20u))); /* mov edx, dword ptr [eax + 0x20] */
    (void)sub32(c, c->edx, R32((uint32_t)(c->ecx + 0x44u))); /* cmp edx, dword ptr [ecx + 0x44] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete al */
    c->esp += 8; return; /* ret 4 */
}

void f_00992360(CPU *c) { /* FUN_10002360 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x9b3cf0u; PUSH32(c, v_); } /* push 0x10023cf0 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ebp - 4], 0 */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x10], esp */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_00992388:;
    (void)sub32(c, c->esi, (uint32_t)0x1f4u); /* cmp esi, 0x1f4 */
    if ((c->sf == c->of)) goto L_009923b4; /* jge 0x9923b4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi * 4 + 0x9cd7d0u))); /* mov eax, dword ptr [esi*4 + 0x1003d7d0] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009923ab; /* je 0x9923ab */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x20u))); /* mov eax, dword ptr [eax + 0x20] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009923ab; /* je 0x9923ab */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x009923a8u); f_00993c50(c); /* call 0x993c50 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_009923ab:;
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    goto L_00992388; /* jmp 0x992388 */
L_009923b4:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_009923ae(CPU *c) { /* Catch@100023ae */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x9923b4u); /* mov eax, 0x100023b4 */
    c->esp += 4; return; /* ret  */
}

void f_009923b4(CPU *c) { /* PTR_009923b4 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_009923b8(CPU *c) { /* PTR_009923b8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_009923d0(CPU *c) { /* FUN_100023d0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edi, dword ptr [esp + 0x14] */
    c->ebp = (uint32_t)(c->ecx); /* mov ebp, ecx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov cl, byte ptr [edi] */
    c->edx = (uint32_t)(c->edi); /* mov edx, edi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_00992407; /* je 0x992407 */
L_009923e6:;
    c->ecx = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->edx))); /* movsx ecx, byte ptr [edx] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0xf0000000u))); /* and ecx, 0xf0000000 */
    if (c->zf) goto L_00992402; /* je 0x992402 */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->esi = (uint32_t)(shr32(c, c->esi, 24)); /* shr esi, 0x18 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi ^ c->ecx))); /* xor esi, ecx */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ c->esi))); /* xor eax, esi */
L_00992402:;
    (void)sub8(c, R8((uint32_t)(c->edx)), (uint8_t)0x0u); /* cmp byte ptr [edx], 0 */
    if (!c->zf) goto L_009923e6; /* jne 0x9923e6 */
L_00992407:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->ecx = (uint32_t)((uint32_t)0x1f4u); /* mov ecx, 0x1f4 */
    { uint32_t d_ = c->ecx; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x0099240eu, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div ecx */
    { uint32_t v_ = 0x47u; PUSH32(c, v_); } /* push 0x47 */
    { uint32_t v_ = 0x9b71a8u; PUSH32(c, v_); } /* push 0x100271a8 */
    { uint32_t v_ = 0x30u; PUSH32(c, v_); } /* push 0x30 */
    c->esi = (uint32_t)(c->edx); /* mov esi, edx */
    PUSH32(c, 0x00992420u); f_00993c30(c); /* call 0x993c30 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_0099243c; /* je 0x99243c */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [eax], 0xffffffff */
    W8((uint32_t)(c->eax + 0x4u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [eax + 4], 1 */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 8], ebx */
    W32((uint32_t)(c->eax + 0x20u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x20], ebx */
    W32((uint32_t)(c->eax + 0x28u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x28], ebx */
    goto L_0099243e; /* jmp 0x99243e */
L_0099243c:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_0099243e:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov ebx, dword ptr [esp + 0x18] */
    c->edx = (uint32_t)(c->esi); /* mov edx, esi */
    c->edx = (uint32_t)(shl32(c, c->edx, 7)); /* shl edx, 7 */
    c->edx = (uint32_t)(add32(c, c->edx, c->ebp)); /* add edx, ebp */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
    (void)sub8(c, R8((uint32_t)(c->edx)), (uint8_t)0x0u); /* cmp byte ptr [edx], 0 */
    if (!c->zf) goto L_00992470; /* jne 0x992470 */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edx = (uint32_t)(sub32(c, c->edx, c->edi)); /* sub edx, edi */
L_00992454:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    W8((uint32_t)(c->edx + c->eax), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [edx + eax], cl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_00992454; /* jne 0x992454 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    W32((uint32_t)(c->ebp + c->esi * 4 + 0xfa00u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + esi*4 + 0xfa00], eax */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 12; return; /* ret 8 */
L_00992470:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
L_00992474:;
    (void)sub8(c, R8((uint32_t)(c->ecx)), (uint8_t)0x0u); /* cmp byte ptr [ecx], 0 */
    if (c->zf) goto L_00992491; /* je 0x992491 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x80u)); /* add ecx, 0x80 */
    (void)sub32(c, c->eax, (uint32_t)0x1f4u); /* cmp eax, 0x1f4 */
    if ((c->sf != c->of)) goto L_00992474; /* jl 0x992474 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 12; return; /* ret 8 */
L_00992491:;
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    c->edx = (uint32_t)(shl32(c, c->edx, 7)); /* shl edx, 7 */
    c->esi = (uint32_t)((uint32_t)(c->edx + c->ebp)); /* lea esi, [edx + ebp] */
    c->esi = (uint32_t)(sub32(c, c->esi, c->edi)); /* sub esi, edi */
L_0099249d:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov dl, byte ptr [ecx] */
    W8((uint32_t)(c->esi + c->ecx), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi + ecx], dl */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (!c->zf) goto L_0099249d; /* jne 0x99249d */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov ecx, dword ptr [ebx] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    W32((uint32_t)(c->ebp + c->eax * 4 + 0xfa00u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp + eax*4 + 0xfa00], ecx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 12; return; /* ret 8 */
}

void f_009924c0(CPU *c) { /* FUN_100024c0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x9b513cu)); /* mov dword ptr [eax], 0x1002513c */
    c->esp += 4; return; /* ret  */
}

void f_009924d0(CPU *c) { /* FUN_100024d0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x009924d8u); f_009924f0(c); /* call 0x9924f0 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_009924e8; /* je 0x9924e8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x009924e5u); f_00993c50(c); /* call 0x993c50 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_009924e8:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_009924f0(CPU *c) { /* FUN_100024f0 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx), (uint32_t)((uint32_t)0x9b513cu)); /* mov dword ptr [ecx], 0x1002513c */
    c->esp += 4; return; /* ret  */
}

void f_00992500(CPU *c) { /* FUN_10002500 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    c->esp += 4; return; /* ret  */
}

void f_00992510(CPU *c) { /* FUN_10002510 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov eax, dword ptr [ecx + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00992523; /* jne 0x992523 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 16; return; /* ret 0xc */
L_00992523:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xcu))); /* fld dword ptr [esp + 0xc] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x9b5124u))); FPOP(c); /* fcomp dword ptr [0x10025124] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x44u)); /* test ah, 0x44 */
    if (!PF(c)) goto L_00992540; /* jnp 0x992540 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00992540u); f_00995e60(c); /* call 0x995e60 */
L_00992540:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00992553; /* je 0x992553 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x00992553u); f_009961e0(c); /* call 0x9961e0 */
L_00992553:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x8u))); /* mov al, byte ptr [esp + 8] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00992576; /* je 0x992576 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov eax, dword ptr [ecx + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x30u)); PUSH32(c, 0x0099256du); call_indirect(c, t_); } /* call dword ptr [edx + 0x30] */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->esp += 16; return; /* ret 0xc */
L_00992576:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov eax, dword ptr [eax + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x00992588u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->esp += 16; return; /* ret 0xc */
}

void f_009925a0(CPU *c) { /* PTR_009925a0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov eax, dword ptr [ecx + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov eax, dword ptr [eax + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009925b0; /* je 0x9925b0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x48u)); PUSH32(c, 0x009925b0u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x48] */
L_009925b0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    c->esp += 4; return; /* ret  */
}

void f_009925c0(CPU *c) { /* FUN_100025c0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x9b3d3cu; PUSH32(c, v_); } /* push 0x10023d3c */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov eax, dword ptr [esp + 0x28] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x10], esi */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0xc], 0 */
    if (c->zf) goto L_00992625; /* je 0x992625 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x54u)); /* lea ecx, [esi + 0x54] */
    W32((uint32_t)(c->esi + 0x50u), (uint32_t)((uint32_t)0x9b5188u)); /* mov dword ptr [esi + 0x50], 0x10025188 */
    PUSH32(c, 0x00992600u); f_00991000(c); /* call 0x991000 */
    c->edi = (uint32_t)((uint32_t)0x1u); /* mov edi, 1 */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0xc], edi */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x60u)); /* lea ecx, [esi + 0x60] */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x1c], 0 */
    PUSH32(c, 0x00992619u); f_00991290(c); /* call 0x991290 */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)((uint32_t)0x3u)); /* mov dword ptr [esp + 0xc], 3 */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x1c], edi */
L_00992625:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov eax, dword ptr [esp + 0x30] */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x4u)); /* lea edi, [esi + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    PUSH32(c, 0x00992634u); f_00995df0(c); /* call 0x995df0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov ecx, dword ptr [esi + 0x50] */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x9b5150u)); /* mov dword ptr [esi], 0x10025150 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov ebx, dword ptr [esp + 0x24] */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [esp + 0x1c], 2 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov edx, dword ptr [ecx + 4] */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    W32((uint32_t)(c->edx + c->esi + 0x50u), (uint32_t)((uint32_t)0x9b514cu)); /* mov dword ptr [edx + esi + 0x50], 0x1002514c */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ecx, dword ptr [eax + 8] */
    W32((uint32_t)(c->ecx + c->esi + 0x50u), (uint32_t)((uint32_t)0x9b5148u)); /* mov dword ptr [ecx + esi + 0x50], 0x10025148 */
    if (!c->zf) goto L_00992686; /* jne 0x992686 */
    c->eax = (uint32_t)(R32((uint32_t)(0x9cdfb0u))); /* mov eax, dword ptr [0x1003dfb0] */
    { uint32_t v_ = 0x9b7210u; PUSH32(c, v_); } /* push 0x10027210 */
    { uint32_t v_ = 0xau; PUSH32(c, v_); } /* push 0xa */
    { uint32_t v_ = 0x9b71dcu; PUSH32(c, v_); } /* push 0x100271dc */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0x9b70a0u; PUSH32(c, v_); } /* push 0x100270a0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00992682u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00992685u, "int3"); /* int3  */
L_00992686:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ecx, dword ptr [eax + 8] */
    W32((uint32_t)(c->ecx + c->esi + 0x58u), (uint32_t)(c->edi)); /* mov dword ptr [ecx + esi + 0x58], edi */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov edx, dword ptr [esi + 0x50] */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x2cu))); /* mov cl, byte ptr [esp + 0x2c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov eax, dword ptr [edx + 4] */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x28u))); /* mov dl, byte ptr [esp + 0x28] */
    W32((uint32_t)(c->eax + c->esi + 0x54u), (uint32_t)(c->edi)); /* mov dword ptr [eax + esi + 0x54], edi */
    W8((uint32_t)(c->esi + 0x34u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esi + 0x34], cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ecx, dword ptr [esp + 0x14] */
    W32((uint32_t)(c->edi), (uint32_t)(c->ebx)); /* mov dword ptr [edi], ebx */
    W8((uint32_t)(c->esi + 0x1eu), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi + 0x1e], dl */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esp += 24; return; /* ret 0x14 */
}

void f_009926c0(CPU *c) { /* FUN_100026c0 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx), (uint32_t)((uint32_t)0x9b5194u)); /* mov dword ptr [ecx], 0x10025194 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    { f_00995e30(c); return; } /* jmp 0x995e30 */
}

void f_009926d0(CPU *c) { /* FUN_100026d0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x009926d8u); f_009926c0(c); /* call 0x9926c0 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_009926e8; /* je 0x9926e8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x009926e5u); f_00993c50(c); /* call 0x993c50 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_009926e8:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_009926f0(CPU *c) { /* FUN_100026f0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x009926f8u); f_00992720(c); /* call 0x992720 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x60u)); /* lea ecx, [esi + 0x60] */
    PUSH32(c, 0x00992700u); f_00991300(c); /* call 0x991300 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x54u)); /* lea ecx, [esi + 0x54] */
    PUSH32(c, 0x00992708u); f_00991030(c); /* call 0x991030 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00992718; /* je 0x992718 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00992715u); f_00993c50(c); /* call 0x993c50 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00992718:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00992720(CPU *c) { /* FUN_10002720 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x9b3d58u; PUSH32(c, v_); } /* push 0x10023d58 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 4], esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x9b5150u)); /* mov dword ptr [esi], 0x10025150 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    W32((uint32_t)(c->ecx + c->esi + 0x50u), (uint32_t)((uint32_t)0x9b514cu)); /* mov dword ptr [ecx + esi + 0x50], 0x1002514c */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov edx, dword ptr [esi + 0x50] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov eax, dword ptr [edx + 8] */
    W32((uint32_t)(c->eax + c->esi + 0x50u), (uint32_t)((uint32_t)0x9b5148u)); /* mov dword ptr [eax + esi + 0x50], 0x10025148 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x10], 0 */
    PUSH32(c, 0x0099276eu); f_009927a0(c); /* call 0x9927a0 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x4u)); /* lea ecx, [esi + 4] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [esp + 0x10], 0xffffffff */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x9b5194u)); /* mov dword ptr [esi], 0x10025194 */
    PUSH32(c, 0x00992784u); f_00995e30(c); /* call 0x995e30 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_009927a0(CPU *c) { /* FUN_100027a0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x50u))); /* mov eax, dword ptr [ecx + 0x50] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov edx, dword ptr [eax + 4] */
    c->ecx = (uint32_t)((uint32_t)(c->edx + c->ecx + 0x50u)); /* lea ecx, [edx + ecx + 0x50] */
    PUSH32(c, 0x009927afu); f_00991040(c); /* call 0x991040 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    c->esp += 4; return; /* ret  */
}

void f_009927c0(CPU *c) { /* PTR_009927c0 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x14u)); /* sub esp, 0x14 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x34u)); PUSH32(c, 0x009927cdu); call_indirect(c, t_); } /* call dword ptr [eax + 0x34] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov edx, dword ptr [esp + 0x24] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x10u)); /* lea ecx, [esp + 0x10] */
    c->ebx = (uint32_t)((uint32_t)(c->esi + 0xcu)); /* lea ebx, [esi + 0xc] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ecx, dword ptr [eax + 8] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->esi + 0x50u)); /* lea ecx, [ecx + esi + 0x50] */
    PUSH32(c, 0x009927eau); f_009913e0(c); /* call 0x9913e0 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_009927f7; /* jne 0x9927f7 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esp += 36; return; /* ret 0x20 */
L_009927f7:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x4u)); /* lea edi, [esi + 4] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x30190u; PUSH32(c, v_); } /* push 0x30190 */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    PUSH32(c, 0x0099280eu); f_00995f40(c); /* call 0x995f40 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_0099281b; /* jne 0x99281b */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esp += 36; return; /* ret 0x20 */
L_0099281b:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov edx, dword ptr [esi + 0x50] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ecx, dword ptr [esi + 8] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0xcu)); /* lea eax, [esp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov eax, dword ptr [edx + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->esi + 0x50u)); /* lea ecx, [eax + esi + 0x50] */
    PUSH32(c, 0x00992833u); f_00991670(c); /* call 0x991670 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00992851; /* jne 0x992851 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov ecx, dword ptr [esi + 0x50] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov edx, dword ptr [ecx + 4] */
    c->ecx = (uint32_t)((uint32_t)(c->edx + c->esi + 0x50u)); /* lea ecx, [edx + esi + 0x50] */
    PUSH32(c, 0x00992846u); f_00991040(c); /* call 0x991040 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esp += 36; return; /* ret 0x20 */
L_00992851:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->esi + 0x50u)); /* lea ecx, [ecx + esi + 0x50] */
    PUSH32(c, 0x00992860u); f_009911b0(c); /* call 0x9911b0 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x28u))); /* mov al, byte ptr [esp + 0x28] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_009928b0; /* jne 0x9928b0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov eax, dword ptr [esp + 0x2c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0099287a; /* je 0x99287a */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    PUSH32(c, 0x0099287au); f_009961e0(c); /* call 0x9961e0 */
L_0099287a:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x40u))); /* mov edx, dword ptr [esp + 0x40] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x38u))); /* mov eax, dword ptr [esp + 0x38] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov ecx, dword ptr [esp + 0x34] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov edx, dword ptr [esp + 0x34] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->esi + 0x50u)); /* lea ecx, [ecx + esi + 0x50] */
    PUSH32(c, 0x0099289fu); f_00991060(c); /* call 0x991060 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_009928ac; /* jne 0x9928ac */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esp += 36; return; /* ret 0x20 */
L_009928ac:;
    W8((uint32_t)(c->esi + 0x1fu), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esi + 0x1f], 1 */
L_009928b0:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esp += 36; return; /* ret 0x20 */
}

void f_009928c0(CPU *c) { /* PTR_009928c0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    W8((uint32_t)(c->ecx + 0x1fu), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [ecx + 0x1f], 0 */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x34u)); switch (t_) {  default: jump_indirect(c, t_, 0x009928c6u); return; } } /* jmp dword ptr [eax + 0x34] */
}

void f_009928d0(CPU *c) { /* PTR_009928d0 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    c->esp += 8; return; /* ret 4 */
}

void f_009928e0(CPU *c) { /* PTR_009928e0 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0x1fu))); /* mov al, byte ptr [ecx + 0x1f] */
    c->esp += 4; return; /* ret  */
}

void f_009928f0(CPU *c) { /* FUN_100028f0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x4u)); /* lea ecx, [esi + 4] */
    PUSH32(c, 0x009928fbu); f_00996110(c); /* call 0x996110 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1eu))); /* mov cl, byte ptr [esi + 0x1e] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov edx, dword ptr [esi + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ecx, dword ptr [eax + 8] */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->esi + 0x50u)); /* lea ecx, [ecx + esi + 0x50] */
    PUSH32(c, 0x00992917u); f_00991ab0(c); /* call 0x991ab0 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00992920(CPU *c) { /* PTR_00992920 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_00992930(CPU *c) { /* FUN_10002930 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009929ab; /* je 0x9929ab */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1fu))); /* mov cl, byte ptr [esi + 0x1f] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_00992947; /* je 0x992947 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x48u)); PUSH32(c, 0x00992947u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x48] */
L_00992947:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov edx, dword ptr [esi + 0x50] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov eax, dword ptr [edx + 8] */
    W32((uint32_t)(c->eax + c->esi + 0x90u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [eax + esi + 0x90], 0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov ecx, dword ptr [esi + 0x50] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov edx, dword ptr [ecx + 8] */
    W8((uint32_t)(c->edx + c->esi + 0x78u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [edx + esi + 0x78], 1 */
    c->eax = (uint32_t)(R32((uint32_t)(0x9ce1d4u))); /* mov eax, dword ptr [0x1003e1d4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->esi + 0x60u))); /* mov eax, dword ptr [eax + esi + 0x60] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x00992981u); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov ecx, dword ptr [esi + 0x50] */
    { uint32_t v_ = 0xbf800000u; PUSH32(c, v_); } /* push 0xbf800000 */
    { uint32_t v_ = 0xbf800000u; PUSH32(c, v_); } /* push 0xbf800000 */
    { uint32_t v_ = 0xbf800000u; PUSH32(c, v_); } /* push 0xbf800000 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov edx, dword ptr [ecx + 4] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ecx = (uint32_t)((uint32_t)(c->edx + c->esi + 0x50u)); /* lea ecx, [edx + esi + 0x50] */
    PUSH32(c, 0x009929a3u); f_00991060(c); /* call 0x991060 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_009929ab; /* je 0x9929ab */
    W8((uint32_t)(c->esi + 0x1fu), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esi + 0x1f], 1 */
L_009929ab:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_009929b0(CPU *c) { /* FUN_100029b0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1fu))); /* mov al, byte ptr [esi + 0x1f] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_009929f7; /* jne 0x9929f7 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009929cd; /* je 0x9929cd */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x4u)); /* lea ecx, [esi + 4] */
    PUSH32(c, 0x009929cdu); f_009961e0(c); /* call 0x9961e0 */
L_009929cd:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    { uint32_t v_ = 0xbf800000u; PUSH32(c, v_); } /* push 0xbf800000 */
    { uint32_t v_ = 0xbf800000u; PUSH32(c, v_); } /* push 0xbf800000 */
    { uint32_t v_ = 0xbf800000u; PUSH32(c, v_); } /* push 0xbf800000 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->esi + 0x50u)); /* lea ecx, [ecx + esi + 0x50] */
    PUSH32(c, 0x009929efu); f_00991060(c); /* call 0x991060 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_009929f7; /* je 0x9929f7 */
    W8((uint32_t)(c->esi + 0x1fu), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esi + 0x1f], 1 */
L_009929f7:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00992a00(CPU *c) { /* PTR_00992a00 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x54u)); /* sub ecx, 0x54 */
    { f_009926f0(c); return; } /* jmp 0x9926f0 */
}

void f_00992a10(CPU *c) { /* PTR_00992a10 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x60u)); /* sub ecx, 0x60 */
    { f_009926f0(c); return; } /* jmp 0x9926f0 */
}

void f_00992a20(CPU *c) { /* FUN_10002a20 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x9b3dacu; PUSH32(c, v_); } /* push 0x10023dac */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov eax, dword ptr [esp + 0x28] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x10], esi */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0xc], 0 */
    if (c->zf) goto L_00992a85; /* je 0x992a85 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x54u)); /* lea ecx, [esi + 0x54] */
    W32((uint32_t)(c->esi + 0x50u), (uint32_t)((uint32_t)0x9b5210u)); /* mov dword ptr [esi + 0x50], 0x10025210 */
    PUSH32(c, 0x00992a60u); f_009924c0(c); /* call 0x9924c0 */
    c->edi = (uint32_t)((uint32_t)0x1u); /* mov edi, 1 */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0xc], edi */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x60u)); /* lea ecx, [esi + 0x60] */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x1c], 0 */
    PUSH32(c, 0x00992a79u); f_00991290(c); /* call 0x991290 */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)((uint32_t)0x3u)); /* mov dword ptr [esp + 0xc], 3 */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x1c], edi */
L_00992a85:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov eax, dword ptr [esp + 0x30] */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x4u)); /* lea edi, [esi + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    PUSH32(c, 0x00992a94u); f_00995df0(c); /* call 0x995df0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov ecx, dword ptr [esi + 0x50] */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x9b51d8u)); /* mov dword ptr [esi], 0x100251d8 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov ebx, dword ptr [esp + 0x24] */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [esp + 0x1c], 2 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov edx, dword ptr [ecx + 4] */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    W32((uint32_t)(c->edx + c->esi + 0x50u), (uint32_t)((uint32_t)0x9b51ccu)); /* mov dword ptr [edx + esi + 0x50], 0x100251cc */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ecx, dword ptr [eax + 8] */
    W32((uint32_t)(c->ecx + c->esi + 0x50u), (uint32_t)((uint32_t)0x9b51c8u)); /* mov dword ptr [ecx + esi + 0x50], 0x100251c8 */
    if (!c->zf) goto L_00992ae6; /* jne 0x992ae6 */
    c->eax = (uint32_t)(R32((uint32_t)(0x9cdfb0u))); /* mov eax, dword ptr [0x1003dfb0] */
    { uint32_t v_ = 0x9b7210u; PUSH32(c, v_); } /* push 0x10027210 */
    { uint32_t v_ = 0xbu; PUSH32(c, v_); } /* push 0xb */
    { uint32_t v_ = 0x9b7218u; PUSH32(c, v_); } /* push 0x10027218 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0x9b70a0u; PUSH32(c, v_); } /* push 0x100270a0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00992ae2u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00992ae5u, "int3"); /* int3  */
L_00992ae6:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ecx, dword ptr [eax + 8] */
    W32((uint32_t)(c->ecx + c->esi + 0x58u), (uint32_t)(c->edi)); /* mov dword ptr [ecx + esi + 0x58], edi */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov edx, dword ptr [esi + 0x50] */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x2cu))); /* mov cl, byte ptr [esp + 0x2c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov eax, dword ptr [edx + 4] */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x28u))); /* mov dl, byte ptr [esp + 0x28] */
    W32((uint32_t)(c->eax + c->esi + 0x54u), (uint32_t)(c->edi)); /* mov dword ptr [eax + esi + 0x54], edi */
    W8((uint32_t)(c->esi + 0x34u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esi + 0x34], cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ecx, dword ptr [esp + 0x14] */
    W32((uint32_t)(c->edi), (uint32_t)(c->ebx)); /* mov dword ptr [edi], ebx */
    W8((uint32_t)(c->esi + 0x1eu), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi + 0x1e], dl */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esp += 24; return; /* ret 0x14 */
}

void f_00992b20(CPU *c) { /* FUN_10002b20 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00992b28u); f_00992b50(c); /* call 0x992b50 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x60u)); /* lea ecx, [esi + 0x60] */
    PUSH32(c, 0x00992b30u); f_00991300(c); /* call 0x991300 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x54u)); /* lea ecx, [esi + 0x54] */
    PUSH32(c, 0x00992b38u); f_009924f0(c); /* call 0x9924f0 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00992b48; /* je 0x992b48 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00992b45u); f_00993c50(c); /* call 0x993c50 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00992b48:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00992b50(CPU *c) { /* FUN_10002b50 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x9b3dc8u; PUSH32(c, v_); } /* push 0x10023dc8 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 4], esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x9b51d8u)); /* mov dword ptr [esi], 0x100251d8 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    W32((uint32_t)(c->ecx + c->esi + 0x50u), (uint32_t)((uint32_t)0x9b51ccu)); /* mov dword ptr [ecx + esi + 0x50], 0x100251cc */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov edx, dword ptr [esi + 0x50] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov eax, dword ptr [edx + 8] */
    W32((uint32_t)(c->eax + c->esi + 0x50u), (uint32_t)((uint32_t)0x9b51c8u)); /* mov dword ptr [eax + esi + 0x50], 0x100251c8 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x10], 0 */
    PUSH32(c, 0x00992b9eu); f_00992bd0(c); /* call 0x992bd0 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x4u)); /* lea ecx, [esi + 4] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [esp + 0x10], 0xffffffff */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x9b5194u)); /* mov dword ptr [esi], 0x10025194 */
    PUSH32(c, 0x00992bb4u); f_00995e30(c); /* call 0x995e30 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_00992bd0(CPU *c) { /* FUN_10002bd0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ecx, dword ptr [eax + 8] */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->esi + 0x50u)); /* lea ecx, [ecx + esi + 0x50] */
    PUSH32(c, 0x00992be2u); f_00991310(c); /* call 0x991310 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov edx, dword ptr [esi + 0x50] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov eax, dword ptr [edx + 4] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->esi + 0x50u)); /* lea ecx, [eax + esi + 0x50] */
    PUSH32(c, 0x00992bf1u); f_00992500(c); /* call 0x992500 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00992c00(CPU *c) { /* PTR_00992c00 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    rdtsc(c); /* rdtsc  */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x34u)); PUSH32(c, 0x00992c12u); call_indirect(c, t_); } /* call dword ptr [eax + 0x34] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov ecx, dword ptr [esi + 0x50] */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0xcu)); /* lea edi, [esi + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov edx, dword ptr [ecx + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x3cu))); /* mov ecx, dword ptr [esp + 0x3c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + c->esi + 0x58u))); /* mov eax, dword ptr [edx + esi + 0x58] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x10u)); /* lea edx, [esp + 0x10] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->eax + 0x38u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x38], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov ecx, dword ptr [esi + 0x50] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov eax, dword ptr [esp + 0x2c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov edx, dword ptr [ecx + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)((uint32_t)(c->edx + c->esi + 0x50u)); /* lea ecx, [edx + esi + 0x50] */
    PUSH32(c, 0x00992c40u); f_009913e0(c); /* call 0x9913e0 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00992c4c; /* jne 0x992c4c */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    c->esp += 36; return; /* ret 0x20 */
L_00992c4c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x101e8u; PUSH32(c, v_); } /* push 0x101e8 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x4u)); /* lea ecx, [esi + 4] */
    PUSH32(c, 0x00992c61u); f_00995f40(c); /* call 0x995f40 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00992c6d; /* jne 0x992c6d */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    c->esp += 36; return; /* ret 0x20 */
L_00992c6d:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov edx, dword ptr [esi + 8] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0xcu)); /* lea ecx, [esp + 0xc] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ecx, dword ptr [eax + 8] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->esi + 0x50u)); /* lea ecx, [ecx + esi + 0x50] */
    PUSH32(c, 0x00992c85u); f_00991670(c); /* call 0x991670 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00992ca2; /* jne 0x992ca2 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov edx, dword ptr [esi + 0x50] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov eax, dword ptr [edx + 4] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->esi + 0x50u)); /* lea ecx, [eax + esi + 0x50] */
    PUSH32(c, 0x00992c98u); f_00992500(c); /* call 0x992500 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    c->esp += 36; return; /* ret 0x20 */
L_00992ca2:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x28u))); /* mov al, byte ptr [esp + 0x28] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00992cd2; /* jne 0x992cd2 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov edx, dword ptr [esi + 0x50] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x40u))); /* mov ecx, dword ptr [esp + 0x40] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov eax, dword ptr [edx + 4] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->esi + 0x50u)); /* lea ecx, [eax + esi + 0x50] */
    PUSH32(c, 0x00992cc2u); f_00992510(c); /* call 0x992510 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00992cce; /* jne 0x992cce */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    c->esp += 36; return; /* ret 0x20 */
L_00992cce:;
    W8((uint32_t)(c->esi + 0x1fu), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esi + 0x1f], 1 */
L_00992cd2:;
    rdtsc(c); /* rdtsc  */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->esp + 0x8u)))); /* sub eax, dword ptr [esp + 8] */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 8], eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    c->esp += 36; return; /* ret 0x20 */
}

void f_00992cf0(CPU *c) { /* PTR_00992cf0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x50u))); /* mov eax, dword ptr [ecx + 0x50] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov edx, dword ptr [eax + 8] */
    c->ecx = (uint32_t)((uint32_t)(c->edx + c->ecx + 0x50u)); /* lea ecx, [edx + ecx + 0x50] */
    { f_00991c30(c); return; } /* jmp 0x991c30 */
}

void f_00992d00(CPU *c) { /* PTR_00992d00 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    rdtsc(c); /* rdtsc  */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 4], eax */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x4u)); /* lea ecx, [esi + 4] */
    PUSH32(c, 0x00992d12u); f_00996110(c); /* call 0x996110 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1eu))); /* mov cl, byte ptr [esi + 0x1e] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov edx, dword ptr [esi + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ecx, dword ptr [eax + 8] */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->esi + 0x50u)); /* lea ecx, [ecx + esi + 0x50] */
    PUSH32(c, 0x00992d2eu); f_00991ab0(c); /* call 0x991ab0 */
    rdtsc(c); /* rdtsc  */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->esp + 0x4u)))); /* sub eax, dword ptr [esp + 4] */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 4], eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1eu))); /* mov al, byte ptr [esi + 0x1e] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00992d4f; /* jne 0x992d4f */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00992d46u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00992d4f; /* jne 0x992d4f */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 8; return; /* ret 4 */
L_00992d4f:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 8; return; /* ret 4 */
}

void f_00992d60(CPU *c) { /* FUN_10002d60 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00992dcd; /* je 0x992dcd */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1fu))); /* mov cl, byte ptr [esi + 0x1f] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_00992d77; /* je 0x992d77 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x48u)); PUSH32(c, 0x00992d77u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x48] */
L_00992d77:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov edx, dword ptr [esi + 0x50] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov eax, dword ptr [edx + 8] */
    W32((uint32_t)(c->eax + c->esi + 0x90u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [eax + esi + 0x90], 0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov ecx, dword ptr [esi + 0x50] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov edx, dword ptr [ecx + 8] */
    W8((uint32_t)(c->edx + c->esi + 0x78u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [edx + esi + 0x78], 1 */
    c->eax = (uint32_t)(R32((uint32_t)(0x9ce1d4u))); /* mov eax, dword ptr [0x1003e1d4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->esi + 0x60u))); /* mov eax, dword ptr [eax + esi + 0x60] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x00992db1u); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov ecx, dword ptr [esi + 0x50] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0xbf800000u; PUSH32(c, v_); } /* push 0xbf800000 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov edx, dword ptr [ecx + 4] */
    c->ecx = (uint32_t)((uint32_t)(c->edx + c->esi + 0x50u)); /* lea ecx, [edx + esi + 0x50] */
    PUSH32(c, 0x00992dc9u); f_00992510(c); /* call 0x992510 */
    W8((uint32_t)(c->esi + 0x1fu), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esi + 0x1f], 1 */
L_00992dcd:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00992dd0(CPU *c) { /* PTR_00992dd0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    if (c->zf) goto L_00992de6; /* je 0x992de6 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x4u)); /* lea ecx, [esi + 4] */
    PUSH32(c, 0x00992de6u); f_009961e0(c); /* call 0x9961e0 */
L_00992de6:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1fu))); /* mov al, byte ptr [esi + 0x1f] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00992e14; /* jne 0x992e14 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x38u))); /* mov eax, dword ptr [esi + 0x38] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf == c->of)) goto L_00992e14; /* jge 0x992e14 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0xbf800000u; PUSH32(c, v_); } /* push 0xbf800000 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->esi + 0x50u)); /* lea ecx, [ecx + esi + 0x50] */
    PUSH32(c, 0x00992e0cu); f_00992510(c); /* call 0x992510 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00992e14; /* je 0x992e14 */
    W8((uint32_t)(c->esi + 0x1fu), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esi + 0x1f], 1 */
L_00992e14:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00992e20(CPU *c) { /* PTR_00992e20 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x54u)); /* sub ecx, 0x54 */
    { f_00992b20(c); return; } /* jmp 0x992b20 */
}

void f_00992e30(CPU *c) { /* PTR_00992e30 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x60u)); /* sub ecx, 0x60 */
    { f_00992b20(c); return; } /* jmp 0x992b20 */
}

void f_00992e40(CPU *c) { /* FUN_10002e40 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x9b3e1cu; PUSH32(c, v_); } /* push 0x10023e1c */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov eax, dword ptr [esp + 0x28] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x10], esi */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0xc], 0 */
    if (c->zf) goto L_00992ea5; /* je 0x992ea5 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x58u)); /* lea ecx, [esi + 0x58] */
    W32((uint32_t)(c->esi + 0x50u), (uint32_t)((uint32_t)0x9b525cu)); /* mov dword ptr [esi + 0x50], 0x1002525c */
    PUSH32(c, 0x00992e80u); f_00991000(c); /* call 0x991000 */
    c->edi = (uint32_t)((uint32_t)0x1u); /* mov edi, 1 */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0xc], edi */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x64u)); /* lea ecx, [esi + 0x64] */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x1c], 0 */
    PUSH32(c, 0x00992e99u); f_00991e00(c); /* call 0x991e00 */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)((uint32_t)0x3u)); /* mov dword ptr [esp + 0xc], 3 */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x1c], edi */
L_00992ea5:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov eax, dword ptr [esp + 0x30] */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x4u)); /* lea edi, [esi + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    PUSH32(c, 0x00992eb4u); f_00995df0(c); /* call 0x995df0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov ecx, dword ptr [esi + 0x50] */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x9b5224u)); /* mov dword ptr [esi], 0x10025224 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov ebx, dword ptr [esp + 0x24] */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [esp + 0x1c], 2 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov edx, dword ptr [ecx + 4] */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    W32((uint32_t)(c->edx + c->esi + 0x50u), (uint32_t)((uint32_t)0x9b5220u)); /* mov dword ptr [edx + esi + 0x50], 0x10025220 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ecx, dword ptr [eax + 8] */
    W32((uint32_t)(c->ecx + c->esi + 0x50u), (uint32_t)((uint32_t)0x9b521cu)); /* mov dword ptr [ecx + esi + 0x50], 0x1002521c */
    if (!c->zf) goto L_00992f06; /* jne 0x992f06 */
    c->eax = (uint32_t)(R32((uint32_t)(0x9cdfb0u))); /* mov eax, dword ptr [0x1003dfb0] */
    { uint32_t v_ = 0x9b7210u; PUSH32(c, v_); } /* push 0x10027210 */
    { uint32_t v_ = 0xfu; PUSH32(c, v_); } /* push 0xf */
    { uint32_t v_ = 0x9b7250u; PUSH32(c, v_); } /* push 0x10027250 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0x9b70a0u; PUSH32(c, v_); } /* push 0x100270a0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00992f02u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00992f05u, "int3"); /* int3  */
L_00992f06:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ecx, dword ptr [eax + 8] */
    W32((uint32_t)(c->ecx + c->esi + 0x54u), (uint32_t)(c->edi)); /* mov dword ptr [ecx + esi + 0x54], edi */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov edx, dword ptr [esi + 0x50] */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x2cu))); /* mov cl, byte ptr [esp + 0x2c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov eax, dword ptr [edx + 4] */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x28u))); /* mov dl, byte ptr [esp + 0x28] */
    W32((uint32_t)(c->eax + c->esi + 0x54u), (uint32_t)(c->edi)); /* mov dword ptr [eax + esi + 0x54], edi */
    W8((uint32_t)(c->esi + 0x34u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esi + 0x34], cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ecx, dword ptr [esp + 0x14] */
    W32((uint32_t)(c->edi), (uint32_t)(c->ebx)); /* mov dword ptr [edi], ebx */
    W8((uint32_t)(c->esi + 0x1eu), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi + 0x1e], dl */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esp += 24; return; /* ret 0x14 */
}

void f_00992f40(CPU *c) { /* FUN_10002f40 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00992f48u); f_00992f70(c); /* call 0x992f70 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x64u)); /* lea ecx, [esi + 0x64] */
    PUSH32(c, 0x00992f50u); f_00991e30(c); /* call 0x991e30 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x58u)); /* lea ecx, [esi + 0x58] */
    PUSH32(c, 0x00992f58u); f_00991030(c); /* call 0x991030 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00992f68; /* je 0x992f68 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00992f65u); f_00993c50(c); /* call 0x993c50 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00992f68:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00992f70(CPU *c) { /* FUN_10002f70 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x9b3e38u; PUSH32(c, v_); } /* push 0x10023e38 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 4], esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x9b5224u)); /* mov dword ptr [esi], 0x10025224 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    W32((uint32_t)(c->ecx + c->esi + 0x50u), (uint32_t)((uint32_t)0x9b5220u)); /* mov dword ptr [ecx + esi + 0x50], 0x10025220 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov edx, dword ptr [esi + 0x50] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov eax, dword ptr [edx + 8] */
    W32((uint32_t)(c->eax + c->esi + 0x50u), (uint32_t)((uint32_t)0x9b521cu)); /* mov dword ptr [eax + esi + 0x50], 0x1002521c */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x10], 0 */
    PUSH32(c, 0x00992fbeu); f_009927a0(c); /* call 0x9927a0 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x4u)); /* lea ecx, [esi + 4] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [esp + 0x10], 0xffffffff */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x9b5194u)); /* mov dword ptr [esi], 0x10025194 */
    PUSH32(c, 0x00992fd4u); f_00995e30(c); /* call 0x995e30 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_00992ff0(CPU *c) { /* PTR_00992ff0 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x14u)); /* sub esp, 0x14 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x34u)); PUSH32(c, 0x00992ffdu); call_indirect(c, t_); } /* call dword ptr [eax + 0x34] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0xfu)); /* lea ecx, [esp + 0xf] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x1cu)); /* lea edx, [esp + 0x1c] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov ebp, dword ptr [esp + 0x24] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea eax, [esp + 0x14] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x24u)); /* lea ecx, [esp + 0x24] */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x20], 0 */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0xcu)); /* lea edi, [esi + 0xc] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ecx, dword ptr [eax + 8] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x24u)); /* lea edx, [esp + 0x24] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->esi + 0x50u)); /* lea ecx, [ecx + esi + 0x50] */
    PUSH32(c, 0x00993036u); f_00992010(c); /* call 0x992010 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00993061; /* jne 0x993061 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0xfu))); /* mov al, byte ptr [esp + 0xf] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00993056; /* je 0x993056 */
    c->eax = (uint32_t)(R32((uint32_t)(0x9cdfb4u))); /* mov eax, dword ptr [0x1003dfb4] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = 0x9b72a8u; PUSH32(c, v_); } /* push 0x100272a8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x30u)); PUSH32(c, 0x00993053u); call_indirect(c, t_); } /* call dword ptr [edx + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_00993056:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esp += 36; return; /* ret 0x20 */
L_00993061:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov edx, dword ptr [esp + 0x18] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ecx, dword ptr [eax + 8] */
    W32((uint32_t)(c->ecx + c->esi + 0x58u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + esi + 0x58], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov eax, dword ptr [esp + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00993080u); f_009938f0(c); /* call 0x9938f0 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_009930a9; /* je 0x9930a9 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    c->ebp = (uint32_t)((uint32_t)(c->esi + 0x4u)); /* lea ebp, [esi + 4] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x30190u; PUSH32(c, v_); } /* push 0x30190 */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    PUSH32(c, 0x00993098u); f_00995f20(c); /* call 0x995f20 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_0099316a; /* jne 0x99316a */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esp += 36; return; /* ret 0x20 */
L_009930a9:;
    (void)sub16(c, R16((uint32_t)(c->esi + 0xeu)), (uint16_t)0x1u); /* cmp word ptr [esi + 0xe], 1 */
    if ((c->cf || c->zf)) goto L_009930cf; /* jbe 0x9930cf */
    c->eax = (uint32_t)(R32((uint32_t)(0x9cdfb4u))); /* mov eax, dword ptr [0x1003dfb4] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = 0x9b7284u; PUSH32(c, v_); } /* push 0x10027284 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x009930c1u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esp += 36; return; /* ret 0x20 */
L_009930cf:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ebp = (uint32_t)((uint32_t)(c->esi + 0x4u)); /* lea ebp, [esi + 4] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x30190u; PUSH32(c, v_); } /* push 0x30190 */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    PUSH32(c, 0x009930e9u); f_00995f40(c); /* call 0x995f40 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_009930f6; /* jne 0x9930f6 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esp += 36; return; /* ret 0x20 */
L_009930f6:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00993108; /* jne 0x993108 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esp += 36; return; /* ret 0x20 */
L_00993108:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov edx, dword ptr [esp + 0x18] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov ecx, dword ptr [esp + 0x18] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov edx, dword ptr [esi + 0x50] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov eax, dword ptr [edx + 8] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->esi + 0x50u)); /* lea ecx, [eax + esi + 0x50] */
    PUSH32(c, 0x00993127u); f_00991f30(c); /* call 0x991f30 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00993157; /* jne 0x993157 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov ecx, dword ptr [esi + 0x50] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov edx, dword ptr [ecx + 4] */
    c->ecx = (uint32_t)((uint32_t)(c->edx + c->esi + 0x50u)); /* lea ecx, [edx + esi + 0x50] */
    PUSH32(c, 0x0099313au); f_00991040(c); /* call 0x991040 */
    c->eax = (uint32_t)(R32((uint32_t)(0x9cdfb4u))); /* mov eax, dword ptr [0x1003dfb4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x0099314cu); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esp += 36; return; /* ret 0x20 */
L_00993157:;
    c->ecx = (uint32_t)(R32((uint32_t)(0x9cdfb4u))); /* mov ecx, dword ptr [0x1003dfb4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ecx, dword ptr [ecx + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x0099316au); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
L_0099316a:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov ecx, dword ptr [esi + 0x50] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov edx, dword ptr [ecx + 4] */
    c->ecx = (uint32_t)((uint32_t)(c->edx + c->esi + 0x50u)); /* lea ecx, [edx + esi + 0x50] */
    PUSH32(c, 0x00993179u); f_009911b0(c); /* call 0x9911b0 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x28u))); /* mov al, byte ptr [esp + 0x28] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_009931cb; /* jne 0x9931cb */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov eax, dword ptr [esp + 0x2c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00993193; /* je 0x993193 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    PUSH32(c, 0x00993193u); f_009961e0(c); /* call 0x9961e0 */
L_00993193:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x40u))); /* mov eax, dword ptr [esp + 0x40] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x38u))); /* mov ecx, dword ptr [esp + 0x38] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov edx, dword ptr [esp + 0x34] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov eax, dword ptr [esp + 0x34] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1eu))); /* mov cl, byte ptr [esi + 0x1e] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov edx, dword ptr [esi + 0x50] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov eax, dword ptr [edx + 4] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->esi + 0x50u)); /* lea ecx, [eax + esi + 0x50] */
    PUSH32(c, 0x009931bau); f_00991060(c); /* call 0x991060 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_009931c7; /* jne 0x9931c7 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esp += 36; return; /* ret 0x20 */
L_009931c7:;
    W8((uint32_t)(c->esi + 0x1fu), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esi + 0x1f], 1 */
L_009931cb:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esp += 36; return; /* ret 0x20 */
}

void f_009931e0(CPU *c) { /* PTR_009931e0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    if (c->zf) goto L_009931fa; /* je 0x9931fa */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x4u)); /* lea ecx, [esi + 4] */
    PUSH32(c, 0x009931f6u); f_009961e0(c); /* call 0x9961e0 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
L_009931fa:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00993207; /* je 0x993207 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x48u)); PUSH32(c, 0x00993207u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x48] */
L_00993207:;
    W8((uint32_t)(c->esi + 0x1fu), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esi + 0x1f], 0 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00993210(CPU *c) { /* FUN_10003210 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov ecx, dword ptr [esi + 0x50] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov edx, dword ptr [ecx + 8] */
    c->ecx = (uint32_t)((uint32_t)(c->edx + c->esi + 0x50u)); /* lea ecx, [edx + esi + 0x50] */
    PUSH32(c, 0x00993227u); f_00992340(c); /* call 0x992340 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00993243; /* je 0x993243 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ecx, dword ptr [eax + 8] */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->esi + 0x50u)); /* lea ecx, [ecx + esi + 0x50] */
    PUSH32(c, 0x0099323au); f_00991e50(c); /* call 0x991e50 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    W8((uint32_t)(c->esi + 0x45u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [esi + 0x45], al */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
L_00993243:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00993250(CPU *c) { /* PTR_00993250 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1fu))); /* mov al, byte ptr [esi + 0x1f] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00993279; /* je 0x993279 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00993279; /* je 0x993279 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x4u)); /* lea edx, [esp + 4] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x24u)); PUSH32(c, 0x0099326du); call_indirect(c, t_); } /* call dword ptr [ecx + 0x24] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x4u))); /* mov al, byte ptr [esp + 4] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u))); /* and al, 1 */
    W8((uint32_t)(c->esi + 0x1fu), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [esi + 0x1f], al */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
L_00993279:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00993280(CPU *c) { /* PTR_00993280 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0xcu)); /* lea edx, [esp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x8u)); /* lea edx, [esp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x10u)); PUSH32(c, 0x00993299u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ecx, dword ptr [eax + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + c->esi + 0x58u))); /* mov esi, dword ptr [ecx + esi + 0x58] */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0xc], esi */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    if (c->zf) goto L_009932c8; /* je 0x9932c8 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp))); /* mov edx, dword ptr [esp] */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 4], 0 */
    W32((uint32_t)(c->esp), (uint32_t)(c->edx)); /* mov dword ptr [esp], edx */
    FPUSH(c, (double)(int64_t)R64((uint32_t)(c->esp))); /* fild qword ptr [esp] */
    ST(0) = FPRES(c, FDIV(c, ST(0), (double)(int32_t)R32((uint32_t)(c->esp + 0x8u)))); /* fidiv dword ptr [esp + 8] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
L_009932c8:;
    FPUSH(c, (double)RF32((uint32_t)(0x9b5124u))); /* fld dword ptr [0x10025124] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_009932e0(CPU *c) { /* PTR_009932e0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x50u))); /* mov eax, dword ptr [ecx + 0x50] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov edx, dword ptr [eax + 4] */
    c->ecx = (uint32_t)((uint32_t)(c->edx + c->ecx + 0x50u)); /* lea ecx, [edx + ecx + 0x50] */
    { f_00991130(c); return; } /* jmp 0x991130 */
}

void f_009932f0(CPU *c) { /* FUN_100032f0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x45u))); /* mov al, byte ptr [esi + 0x45] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00993300; /* je 0x993300 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
L_00993300:;
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x4u)); /* lea ecx, [esi + 4] */
    PUSH32(c, 0x00993308u); f_00996110(c); /* call 0x996110 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x0099330fu); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(!c->zf ? 1 : 0); /* setne al */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00993320(CPU *c) { /* PTR_00993320 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    PUSH32(c, 0x0099332fu); f_00995e60(c); /* call 0x995e60 */
    c->esp += 8; return; /* ret 4 */
}

void f_00993340(CPU *c) { /* FUN_10003340 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x9b3e67u; PUSH32(c, v_); } /* push 0x10023e67 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x54u)), (uint32_t)0x32u); /* cmp dword ptr [esi + 0x54], 0x32 */
    if ((c->sf != c->of)) goto L_00993371; /* jl 0x993371 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
L_00993371:;
    { uint32_t v_ = 0xf0u; PUSH32(c, v_); } /* push 0xf0 */
    { uint32_t v_ = 0x9b7250u; PUSH32(c, v_); } /* push 0x10027250 */
    { uint32_t v_ = 0x74u; PUSH32(c, v_); } /* push 0x74 */
    PUSH32(c, 0x00993382u); f_00993c30(c); /* call 0x993c30 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 4], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x10], 0 */
    if (c->zf) goto L_009933af; /* je 0x9933af */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    PUSH32(c, 0x0099339fu); f_009933d0(c); /* call 0x9933d0 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
L_009933af:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_009933d0(CPU *c) { /* FUN_100033d0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x9b3eb4u; PUSH32(c, v_); } /* push 0x10023eb4 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov eax, dword ptr [esp + 0x1c] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x10], esi */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0xc], 0 */
    if (c->zf) goto L_00993435; /* je 0x993435 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x58u)); /* lea ecx, [esi + 0x58] */
    W32((uint32_t)(c->esi + 0x50u), (uint32_t)((uint32_t)0x9b525cu)); /* mov dword ptr [esi + 0x50], 0x1002525c */
    PUSH32(c, 0x00993410u); f_00991000(c); /* call 0x991000 */
    c->edi = (uint32_t)((uint32_t)0x1u); /* mov edi, 1 */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0xc], edi */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x64u)); /* lea ecx, [esi + 0x64] */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x1c], 0 */
    PUSH32(c, 0x00993429u); f_00991e00(c); /* call 0x991e00 */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)((uint32_t)0x3u)); /* mov dword ptr [esp + 0xc], 3 */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x1c], edi */
L_00993435:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov ebx, dword ptr [esp + 0x24] */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x4u)); /* lea edi, [esi + 4] */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x40u))); /* mov eax, dword ptr [ebx + 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00993447u); f_00995df0(c); /* call 0x995df0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov ecx, dword ptr [esi + 0x50] */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x9b5224u)); /* mov dword ptr [esi], 0x10025224 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov edx, dword ptr [ecx + 4] */
    W32((uint32_t)(c->edx + c->esi + 0x50u), (uint32_t)((uint32_t)0x9b5220u)); /* mov dword ptr [edx + esi + 0x50], 0x10025220 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ecx, dword ptr [eax + 8] */
    W32((uint32_t)(c->ecx + c->esi + 0x50u), (uint32_t)((uint32_t)0x9b521cu)); /* mov dword ptr [ecx + esi + 0x50], 0x1002521c */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x54u))); /* mov edx, dword ptr [ebx + 0x54] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    W32((uint32_t)(c->esi + 0x54u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x54], edx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ecx, dword ptr [eax + 8] */
    W32((uint32_t)(c->ecx + c->esi + 0x54u), (uint32_t)(c->edi)); /* mov dword ptr [ecx + esi + 0x54], edi */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov edx, dword ptr [esi + 0x50] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov eax, dword ptr [edx + 4] */
    W32((uint32_t)(c->eax + c->esi + 0x54u), (uint32_t)(c->edi)); /* mov dword ptr [eax + esi + 0x54], edi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x50u))); /* mov ecx, dword ptr [ebx + 0x50] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov edx, dword ptr [ecx + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ecx, dword ptr [eax + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edx + c->ebx + 0x58u))); /* mov edx, dword ptr [edx + ebx + 0x58] */
    W32((uint32_t)(c->ecx + c->esi + 0x58u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + esi + 0x58], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    W32((uint32_t)(c->ecx + c->esi + 0x58u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ecx + esi + 0x58], 0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esp += 12; return; /* ret 8 */
}

void f_009934c0(CPU *c) { /* FUN_100034c0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009934ff; /* je 0x9934ff */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1fu))); /* mov cl, byte ptr [esi + 0x1f] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_009934d7; /* je 0x9934d7 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x48u)); PUSH32(c, 0x009934d7u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x48] */
L_009934d7:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1eu))); /* mov dl, byte ptr [esi + 0x1e] */
    { uint32_t v_ = 0xbf800000u; PUSH32(c, v_); } /* push 0xbf800000 */
    { uint32_t v_ = 0xbf800000u; PUSH32(c, v_); } /* push 0xbf800000 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    { uint32_t v_ = 0xbf800000u; PUSH32(c, v_); } /* push 0xbf800000 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->esi + 0x50u)); /* lea ecx, [ecx + esi + 0x50] */
    PUSH32(c, 0x009934fbu); f_00991060(c); /* call 0x991060 */
    W8((uint32_t)(c->esi + 0x1fu), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esi + 0x1f], 1 */
L_009934ff:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00993510(CPU *c) { /* FUN_10003510 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1fu))); /* mov al, byte ptr [esi + 0x1f] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00993559; /* jne 0x993559 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0099352d; /* je 0x99352d */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x4u)); /* lea ecx, [esi + 4] */
    PUSH32(c, 0x0099352du); f_009961e0(c); /* call 0x9961e0 */
L_0099352d:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov ecx, dword ptr [esi + 0x50] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1eu))); /* mov al, byte ptr [esi + 0x1e] */
    { uint32_t v_ = 0xbf800000u; PUSH32(c, v_); } /* push 0xbf800000 */
    { uint32_t v_ = 0xbf800000u; PUSH32(c, v_); } /* push 0xbf800000 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov edx, dword ptr [ecx + 4] */
    { uint32_t v_ = 0xbf800000u; PUSH32(c, v_); } /* push 0xbf800000 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)((uint32_t)(c->edx + c->esi + 0x50u)); /* lea ecx, [edx + esi + 0x50] */
    PUSH32(c, 0x00993551u); f_00991060(c); /* call 0x991060 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00993559; /* je 0x993559 */
    W8((uint32_t)(c->esi + 0x1fu), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esi + 0x1f], 1 */
L_00993559:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00993560(CPU *c) { /* PTR_00993560 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x58u)); /* sub ecx, 0x58 */
    { f_00992f40(c); return; } /* jmp 0x992f40 */
}

void f_00993570(CPU *c) { /* PTR_00993570 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x64u)); /* sub ecx, 0x64 */
    { f_00992f40(c); return; } /* jmp 0x992f40 */
}

void f_00993580(CPU *c) { /* FUN_10003580 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x9b3efcu; PUSH32(c, v_); } /* push 0x10023efc */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov eax, dword ptr [esp + 0x28] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x10], esi */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0xc], 0 */
    if (c->zf) goto L_009935e5; /* je 0x9935e5 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x58u)); /* lea ecx, [esi + 0x58] */
    W32((uint32_t)(c->esi + 0x50u), (uint32_t)((uint32_t)0x9b52b0u)); /* mov dword ptr [esi + 0x50], 0x100252b0 */
    PUSH32(c, 0x009935c0u); f_009924c0(c); /* call 0x9924c0 */
    c->edi = (uint32_t)((uint32_t)0x1u); /* mov edi, 1 */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0xc], edi */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x60u)); /* lea ecx, [esi + 0x60] */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x1c], 0 */
    PUSH32(c, 0x009935d9u); f_00991e00(c); /* call 0x991e00 */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)((uint32_t)0x3u)); /* mov dword ptr [esp + 0xc], 3 */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x1c], edi */
L_009935e5:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov eax, dword ptr [esp + 0x30] */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x4u)); /* lea edi, [esi + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    PUSH32(c, 0x009935f4u); f_00995df0(c); /* call 0x995df0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov ecx, dword ptr [esi + 0x50] */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x9b5278u)); /* mov dword ptr [esi], 0x10025278 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov ebx, dword ptr [esp + 0x24] */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [esp + 0x1c], 2 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov edx, dword ptr [ecx + 4] */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    W32((uint32_t)(c->edx + c->esi + 0x50u), (uint32_t)((uint32_t)0x9b526cu)); /* mov dword ptr [edx + esi + 0x50], 0x1002526c */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ecx, dword ptr [eax + 8] */
    W32((uint32_t)(c->ecx + c->esi + 0x50u), (uint32_t)((uint32_t)0x9b5268u)); /* mov dword ptr [ecx + esi + 0x50], 0x10025268 */
    if (!c->zf) goto L_00993646; /* jne 0x993646 */
    c->eax = (uint32_t)(R32((uint32_t)(0x9cdfb0u))); /* mov eax, dword ptr [0x1003dfb0] */
    { uint32_t v_ = 0x9b7210u; PUSH32(c, v_); } /* push 0x10027210 */
    { uint32_t v_ = 0x17u; PUSH32(c, v_); } /* push 0x17 */
    { uint32_t v_ = 0x9b72c0u; PUSH32(c, v_); } /* push 0x100272c0 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0x9b70a0u; PUSH32(c, v_); } /* push 0x100270a0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00993642u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00993645u, "int3"); /* int3  */
L_00993646:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ecx, dword ptr [eax + 8] */
    W32((uint32_t)(c->ecx + c->esi + 0x54u), (uint32_t)(c->edi)); /* mov dword ptr [ecx + esi + 0x54], edi */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov edx, dword ptr [esi + 0x50] */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x2cu))); /* mov cl, byte ptr [esp + 0x2c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov eax, dword ptr [edx + 4] */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x28u))); /* mov dl, byte ptr [esp + 0x28] */
    W32((uint32_t)(c->eax + c->esi + 0x54u), (uint32_t)(c->edi)); /* mov dword ptr [eax + esi + 0x54], edi */
    W8((uint32_t)(c->esi + 0x34u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esi + 0x34], cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ecx, dword ptr [esp + 0x14] */
    W32((uint32_t)(c->edi), (uint32_t)(c->ebx)); /* mov dword ptr [edi], ebx */
    W8((uint32_t)(c->esi + 0x1eu), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi + 0x1e], dl */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esp += 24; return; /* ret 0x14 */
}

void f_00993680(CPU *c) { /* FUN_10003680 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00993688u); f_009936b0(c); /* call 0x9936b0 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x60u)); /* lea ecx, [esi + 0x60] */
    PUSH32(c, 0x00993690u); f_00991e30(c); /* call 0x991e30 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x58u)); /* lea ecx, [esi + 0x58] */
    PUSH32(c, 0x00993698u); f_009924f0(c); /* call 0x9924f0 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_009936a8; /* je 0x9936a8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x009936a5u); f_00993c50(c); /* call 0x993c50 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_009936a8:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_009936b0(CPU *c) { /* FUN_100036b0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x9b3f18u; PUSH32(c, v_); } /* push 0x10023f18 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 4], esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x9b5278u)); /* mov dword ptr [esi], 0x10025278 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    W32((uint32_t)(c->ecx + c->esi + 0x50u), (uint32_t)((uint32_t)0x9b526cu)); /* mov dword ptr [ecx + esi + 0x50], 0x1002526c */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov edx, dword ptr [esi + 0x50] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov eax, dword ptr [edx + 8] */
    W32((uint32_t)(c->eax + c->esi + 0x50u), (uint32_t)((uint32_t)0x9b5268u)); /* mov dword ptr [eax + esi + 0x50], 0x10025268 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x10], 0 */
    PUSH32(c, 0x009936feu); f_00993730(c); /* call 0x993730 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x4u)); /* lea ecx, [esi + 4] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [esp + 0x10], 0xffffffff */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x9b5194u)); /* mov dword ptr [esi], 0x10025194 */
    PUSH32(c, 0x00993714u); f_00995e30(c); /* call 0x995e30 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_00993730(CPU *c) { /* FUN_10003730 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x50u))); /* mov eax, dword ptr [ecx + 0x50] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov edx, dword ptr [eax + 4] */
    c->ecx = (uint32_t)((uint32_t)(c->edx + c->ecx + 0x50u)); /* lea ecx, [edx + ecx + 0x50] */
    PUSH32(c, 0x0099373fu); f_00992500(c); /* call 0x992500 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    c->esp += 4; return; /* ret  */
}

void f_00993750(CPU *c) { /* PTR_00993750 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x14u)); /* sub esp, 0x14 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x34u)); PUSH32(c, 0x0099375du); call_indirect(c, t_); } /* call dword ptr [eax + 0x34] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0xfu)); /* lea ecx, [esp + 0xf] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x1cu)); /* lea edx, [esp + 0x1c] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov ebx, dword ptr [esp + 0x24] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea eax, [esp + 0x14] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x24u)); /* lea ecx, [esp + 0x24] */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x20], 0 */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0xcu)); /* lea edi, [esi + 0xc] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ecx, dword ptr [eax + 8] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x24u)); /* lea edx, [esp + 0x24] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->esi + 0x50u)); /* lea ecx, [ecx + esi + 0x50] */
    PUSH32(c, 0x00993796u); f_00992010(c); /* call 0x992010 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_009937c1; /* jne 0x9937c1 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0xfu))); /* mov al, byte ptr [esp + 0xf] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_009937b6; /* je 0x9937b6 */
    c->eax = (uint32_t)(R32((uint32_t)(0x9cdfb4u))); /* mov eax, dword ptr [0x1003dfb4] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x9b72a8u; PUSH32(c, v_); } /* push 0x100272a8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x30u)); PUSH32(c, 0x009937b3u); call_indirect(c, t_); } /* call dword ptr [edx + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_009937b6:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esp += 36; return; /* ret 0x20 */
L_009937c1:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov edx, dword ptr [esp + 0x18] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ecx, dword ptr [eax + 8] */
    W32((uint32_t)(c->ecx + c->esi + 0x58u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + esi + 0x58], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov eax, dword ptr [esp + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x009937e0u); f_009938f0(c); /* call 0x9938f0 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    c->eax = (uint32_t)(R32((uint32_t)(0x9b72bcu))); /* mov eax, dword ptr [0x100272bc] */
    c->ebx = (uint32_t)((uint32_t)(c->esi + 0x4u)); /* lea ebx, [esi + 4] */
    if (c->zf) goto L_0099380a; /* je 0x99380a */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x009937f9u); f_00995f20(c); /* call 0x995f20 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_0099389e; /* jne 0x99389e */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esp += 36; return; /* ret 0x20 */
L_0099380a:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov edx, dword ptr [esp + 0x18] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    PUSH32(c, 0x0099381du); f_00995f40(c); /* call 0x995f40 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_0099382a; /* jne 0x99382a */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esp += 36; return; /* ret 0x20 */
L_0099382a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_0099383c; /* jne 0x99383c */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esp += 36; return; /* ret 0x20 */
L_0099383c:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov edx, dword ptr [esp + 0x18] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov ecx, dword ptr [esp + 0x18] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov edx, dword ptr [esi + 0x50] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov eax, dword ptr [edx + 8] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->esi + 0x50u)); /* lea ecx, [eax + esi + 0x50] */
    PUSH32(c, 0x0099385bu); f_00991f30(c); /* call 0x991f30 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_0099388b; /* jne 0x99388b */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov ecx, dword ptr [esi + 0x50] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov edx, dword ptr [ecx + 4] */
    c->ecx = (uint32_t)((uint32_t)(c->edx + c->esi + 0x50u)); /* lea ecx, [edx + esi + 0x50] */
    PUSH32(c, 0x0099386eu); f_00992500(c); /* call 0x992500 */
    c->eax = (uint32_t)(R32((uint32_t)(0x9cdfb4u))); /* mov eax, dword ptr [0x1003dfb4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x00993880u); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esp += 36; return; /* ret 0x20 */
L_0099388b:;
    c->ecx = (uint32_t)(R32((uint32_t)(0x9cdfb4u))); /* mov ecx, dword ptr [0x1003dfb4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ecx, dword ptr [ecx + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x0099389eu); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
L_0099389e:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x28u))); /* mov al, byte ptr [esp + 0x28] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_009938e3; /* jne 0x9938e3 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov eax, dword ptr [esp + 0x2c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009938b8; /* je 0x9938b8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    PUSH32(c, 0x009938b8u); f_009961e0(c); /* call 0x9961e0 */
L_009938b8:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x40u))); /* mov ecx, dword ptr [esp + 0x40] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1eu))); /* mov dl, byte ptr [esi + 0x1e] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->esi + 0x50u)); /* lea ecx, [ecx + esi + 0x50] */
    PUSH32(c, 0x009938d2u); f_00992510(c); /* call 0x992510 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_009938df; /* jne 0x9938df */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esp += 36; return; /* ret 0x20 */
L_009938df:;
    W8((uint32_t)(c->esi + 0x1fu), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esi + 0x1f], 1 */
L_009938e3:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esp += 36; return; /* ret 0x20 */
}

void f_009938f0(CPU *c) { /* FUN_100038f0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x20u))); /* mov ecx, dword ptr [eax + 0x20] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_0099390b; /* je 0x99390b */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x8u))); /* mov al, byte ptr [esp + 8] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_0099390b; /* jne 0x99390b */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    c->esp += 12; return; /* ret 8 */
L_0099390b:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 12; return; /* ret 8 */
}

void f_00993910(CPU *c) { /* FUN_10003910 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov ecx, dword ptr [esi + 0x50] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov edx, dword ptr [ecx + 8] */
    c->ecx = (uint32_t)((uint32_t)(c->edx + c->esi + 0x50u)); /* lea ecx, [edx + esi + 0x50] */
    PUSH32(c, 0x00993927u); f_00992340(c); /* call 0x992340 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00993947; /* je 0x993947 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ecx, dword ptr [eax + 8] */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->esi + 0x50u)); /* lea ecx, [ecx + esi + 0x50] */
    PUSH32(c, 0x0099393au); f_00991e50(c); /* call 0x991e50 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x00993941u); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
L_00993947:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00993950(CPU *c) { /* PTR_00993950 */
    PREEMPT_POLL(c);
    c->esp += 12; return; /* ret 8 */
}

void f_00993960(CPU *c) { /* FUN_10003960 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x45u))); /* mov al, byte ptr [esi + 0x45] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00993970; /* je 0x993970 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
L_00993970:;
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x4u)); /* lea ecx, [esi + 4] */
    PUSH32(c, 0x00993978u); f_00996110(c); /* call 0x996110 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1fu))); /* mov al, byte ptr [esi + 0x1f] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00993985; /* jne 0x993985 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
L_00993985:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x0099398cu); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(!c->zf ? 1 : 0); /* setne al */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_009939a0(CPU *c) { /* FUN_100039a0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x9b3f47u; PUSH32(c, v_); } /* push 0x10023f47 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x54u)), (uint32_t)0x32u); /* cmp dword ptr [esi + 0x54], 0x32 */
    if ((c->sf != c->of)) goto L_009939d1; /* jl 0x9939d1 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
L_009939d1:;
    { uint32_t v_ = 0xfau; PUSH32(c, v_); } /* push 0xfa */
    { uint32_t v_ = 0x9b72c0u; PUSH32(c, v_); } /* push 0x100272c0 */
    { uint32_t v_ = 0x70u; PUSH32(c, v_); } /* push 0x70 */
    PUSH32(c, 0x009939e2u); f_00993c30(c); /* call 0x993c30 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 4], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x10], 0 */
    if (c->zf) goto L_00993a0f; /* je 0x993a0f */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    PUSH32(c, 0x009939ffu); f_00993a30(c); /* call 0x993a30 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
L_00993a0f:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_00993a30(CPU *c) { /* FUN_10003a30 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x9b3f94u; PUSH32(c, v_); } /* push 0x10023f94 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov eax, dword ptr [esp + 0x1c] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x10], esi */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0xc], ebx */
    if (c->zf) goto L_00993a8f; /* je 0x993a8f */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x58u)); /* lea ecx, [esi + 0x58] */
    W32((uint32_t)(c->esi + 0x50u), (uint32_t)((uint32_t)0x9b52b0u)); /* mov dword ptr [esi + 0x50], 0x100252b0 */
    PUSH32(c, 0x00993a6eu); f_009924c0(c); /* call 0x9924c0 */
    c->edi = (uint32_t)((uint32_t)0x1u); /* mov edi, 1 */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0xc], edi */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x60u)); /* lea ecx, [esi + 0x60] */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x1c], ebx */
    PUSH32(c, 0x00993a83u); f_00991e00(c); /* call 0x991e00 */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)((uint32_t)0x3u)); /* mov dword ptr [esp + 0xc], 3 */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x1c], edi */
L_00993a8f:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov ebx, dword ptr [esp + 0x24] */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x4u)); /* lea edi, [esi + 4] */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x40u))); /* mov eax, dword ptr [ebx + 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00993aa1u); f_00995df0(c); /* call 0x995df0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov ecx, dword ptr [esi + 0x50] */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x9b5278u)); /* mov dword ptr [esi], 0x10025278 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov edx, dword ptr [ecx + 4] */
    W32((uint32_t)(c->edx + c->esi + 0x50u), (uint32_t)((uint32_t)0x9b526cu)); /* mov dword ptr [edx + esi + 0x50], 0x1002526c */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ecx, dword ptr [eax + 8] */
    W32((uint32_t)(c->ecx + c->esi + 0x50u), (uint32_t)((uint32_t)0x9b5268u)); /* mov dword ptr [ecx + esi + 0x50], 0x10025268 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x54u))); /* mov edx, dword ptr [ebx + 0x54] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    W32((uint32_t)(c->esi + 0x54u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x54], edx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ecx, dword ptr [eax + 8] */
    W32((uint32_t)(c->ecx + c->esi + 0x54u), (uint32_t)(c->edi)); /* mov dword ptr [ecx + esi + 0x54], edi */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov edx, dword ptr [esi + 0x50] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov eax, dword ptr [edx + 4] */
    W32((uint32_t)(c->eax + c->esi + 0x54u), (uint32_t)(c->edi)); /* mov dword ptr [eax + esi + 0x54], edi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x50u))); /* mov ecx, dword ptr [ebx + 0x50] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov edx, dword ptr [ecx + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ecx, dword ptr [eax + 8] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->edx = (uint32_t)(R32((uint32_t)(c->edx + c->ebx + 0x58u))); /* mov edx, dword ptr [edx + ebx + 0x58] */
    W32((uint32_t)(c->ecx + c->esi + 0x58u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + esi + 0x58], edx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esp += 12; return; /* ret 8 */
}

void f_00993b10(CPU *c) { /* FUN_10003b10 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00993b45; /* je 0x993b45 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1fu))); /* mov cl, byte ptr [esi + 0x1f] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_00993b27; /* je 0x993b27 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x48u)); PUSH32(c, 0x00993b27u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x48] */
L_00993b27:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1eu))); /* mov dl, byte ptr [esi + 0x1e] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0xbf800000u; PUSH32(c, v_); } /* push 0xbf800000 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->esi + 0x50u)); /* lea ecx, [ecx + esi + 0x50] */
    PUSH32(c, 0x00993b41u); f_00992510(c); /* call 0x992510 */
    W8((uint32_t)(c->esi + 0x1fu), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esi + 0x1f], 1 */
L_00993b45:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00993b50(CPU *c) { /* FUN_10003b50 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1fu))); /* mov al, byte ptr [esi + 0x1f] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00993b8f; /* jne 0x993b8f */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00993b6d; /* je 0x993b6d */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x4u)); /* lea ecx, [esi + 4] */
    PUSH32(c, 0x00993b6du); f_009961e0(c); /* call 0x9961e0 */
L_00993b6d:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov ecx, dword ptr [esi + 0x50] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1eu))); /* mov al, byte ptr [esi + 0x1e] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0xbf800000u; PUSH32(c, v_); } /* push 0xbf800000 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov edx, dword ptr [ecx + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)((uint32_t)(c->edx + c->esi + 0x50u)); /* lea ecx, [edx + esi + 0x50] */
    PUSH32(c, 0x00993b87u); f_00992510(c); /* call 0x992510 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00993b8f; /* je 0x993b8f */
    W8((uint32_t)(c->esi + 0x1fu), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esi + 0x1f], 1 */
L_00993b8f:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00993ba0(CPU *c) { /* PTR_00993ba0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x58u)); /* sub ecx, 0x58 */
    { f_00993680(c); return; } /* jmp 0x993680 */
}

void f_00993bb0(CPU *c) { /* PTR_00993bb0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x60u)); /* sub ecx, 0x60 */
    { f_00993680(c); return; } /* jmp 0x993680 */
}

void f_00993bc0(CPU *c) { /* FUN_10003bc0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00993bc6u); f_00998469(c); /* call 0x998469 */
    W32((uint32_t)(c->esp), (uint32_t)(c->eax)); /* mov dword ptr [esp], eax */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp))); /* fild dword ptr [esp] */
    ST(0) = FPRES(c, FDIV(c, ST(0), (double)RF32((uint32_t)(0x9b52bcu)))); /* fdiv dword ptr [0x100252bc] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x8u))); /* fmul dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00993be0(CPU *c) { /* FUN_10003be0 */
    PREEMPT_POLL(c);
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x4u))); /* fld dword ptr [esp + 4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x9b52c0u))); /* fmul dword ptr [0x100252c0] */
    WF32((uint32_t)(c->esp + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00993bf8u); f_00993bc0(c); /* call 0x993bc0 */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x8u))); /* fadd dword ptr [esp + 8] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->esp += 4; return; /* ret  */
}

void f_00993c00(CPU *c) { /* DMAInterface */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    W32((uint32_t)(0x9ce1d4u), (uint32_t)(c->eax)); /* mov dword ptr [0x1003e1d4], eax */
    W32((uint32_t)(0x9cdfb4u), (uint32_t)(c->eax)); /* mov dword ptr [0x1003dfb4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov eax, dword ptr [eax + 4] */
    W32((uint32_t)(0x9cdfb0u), (uint32_t)(c->ecx)); /* mov dword ptr [0x1003dfb0], ecx */
    W32((uint32_t)(0x9cdfc4u), (uint32_t)(c->eax)); /* mov dword ptr [0x1003dfc4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(0x9ce2dcu))); /* mov eax, dword ptr [0x1003e2dc] */
    c->esp += 4; return; /* ret  */
}

void f_00993c30(CPU *c) { /* FUN_10003c30 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x9ce1d4u))); /* mov ecx, dword ptr [0x1003e1d4] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4u)); PUSH32(c, 0x00993c4au); call_indirect(c, t_); } /* call dword ptr [eax + 4] */
    c->esp += 4; return; /* ret  */
}

void f_00993c50(CPU *c) { /* FUN_10003c50 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(0x9ce1d4u))); /* mov ecx, dword ptr [0x1003e1d4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x00993c60u); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
    c->esp += 4; return; /* ret  */
}

void f_00993c70(CPU *c) { /* PTR_00993c70 */
    PREEMPT_POLL(c);
    PUSH32(c, 0x00993c75u); f_00993c80(c); /* call 0x993c80 */
    { f_00993df0(c); return; } /* jmp 0x993df0 */
}

void f_00993c80(CPU *c) { /* PTR_00993c80 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9ce2dcu; PUSH32(c, v_); } /* push 0x1003e2dc */
    c->ecx = (uint32_t)((uint32_t)0x9cdfe4u); /* mov ecx, 0x1003dfe4 */
    PUSH32(c, 0x00993c8fu); f_00993c90(c); /* call 0x993c90 */
    c->esp += 4; return; /* ret  */
}

void f_00993c90(CPU *c) { /* PTR_00993c90 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->edx)); /* mov dword ptr [eax + 0xc], edx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 8], edx */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x9b52c4u)); /* mov dword ptr [eax], 0x100252c4 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov esi, dword ptr [ecx] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [eax + 4], esi */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    W32((uint32_t)(c->eax + 0x10u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 0x10], edx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00993cc0(CPU *c) { /* PTR_00993cc0 */
    PREEMPT_POLL(c);
    { uint32_t a_ = (uint32_t)(c->ecx + 0xcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ecx + 0xc] */
    c->esp += 4; return; /* ret  */
}

void f_00993cd0(CPU *c) { /* PTR_00993cd0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov eax, dword ptr [ecx + 0xc] */
    c->esp += 4; return; /* ret  */
}

void f_00993ce0(CPU *c) { /* PTR_00993ce0 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    c->esp += 4; return; /* ret  */
}

void f_00993cf0(CPU *c) { /* PTR_00993cf0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x9b72fcu); /* mov eax, 0x100272fc */
    c->esp += 4; return; /* ret  */
}

void f_00993d00(CPU *c) { /* FUN_10003d00 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x9b3fb4u; PUSH32(c, v_); } /* push 0x10023fb4 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00993d52; /* jne 0x993d52 */
    { uint32_t v_ = 0x1au; PUSH32(c, v_); } /* push 0x1a */
    { uint32_t v_ = 0x9b730cu; PUSH32(c, v_); } /* push 0x1002730c */
    { uint32_t v_ = 0x77a4u; PUSH32(c, v_); } /* push 0x77a4 */
    PUSH32(c, 0x00993d31u); f_00993c30(c); /* call 0x993c30 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 4], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x10], 0 */
    if (c->zf) goto L_00993d4d; /* je 0x993d4d */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    PUSH32(c, 0x00993d4bu); f_00993e60(c); /* call 0x993e60 */
    goto L_00993d4f; /* jmp 0x993d4f */
L_00993d4d:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00993d4f:;
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x10], eax */
L_00993d52:;
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

void f_00993d70(CPU *c) { /* FUN_10003d70 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0xc], edi */
    (void)sub32(c, c->ecx, c->edi); /* cmp ecx, edi */
    if (c->zf) goto L_00993d86; /* je 0x993d86 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t t_ = R32((uint32_t)(c->eax)); PUSH32(c, 0x00993d86u); call_indirect(c, t_); } /* call dword ptr [eax] */
L_00993d86:;
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0x10], edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00993d90(CPU *c) { /* FUN_10003d90 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00993d98u); f_00993db0(c); /* call 0x993db0 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00993da8; /* je 0x993da8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00993da5u); f_00993c50(c); /* call 0x993c50 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00993da8:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00993db0(CPU *c) { /* FUN_10003db0 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx), (uint32_t)((uint32_t)0x9b52e4u)); /* mov dword ptr [ecx], 0x100252e4 */
    c->esp += 4; return; /* ret  */
}

void f_00993dc0(CPU *c) { /* PTR_00993dc0 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx + 0xcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ecx + 0xc], 0 */
    c->esp += 4; return; /* ret  */
}

void f_00993dd0(CPU *c) { /* PTR_00993dd0 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x4u))); /* mov al, byte ptr [esp + 4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x9b52e4u)); /* mov dword ptr [esi], 0x100252e4 */
    if (c->zf) goto L_00993dea; /* je 0x993dea */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00993de7u); f_00993c50(c); /* call 0x993c50 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00993dea:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00993df0(CPU *c) { /* PTR_00993df0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x993e00u; PUSH32(c, v_); } /* push 0x10003e00 */
    PUSH32(c, 0x00993dfau); f_0099841f(c); /* call 0x99841f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00993e00(CPU *c) { /* PTR_00993e00 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)0x9cdfe4u); /* mov ecx, 0x1003dfe4 */
    { f_00993db0(c); return; } /* jmp 0x993db0 */
}

void f_00993e10(CPU *c) { /* FUN_10003e10 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov esi, dword ptr [esp + 0x14] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_00993e39; /* jne 0x993e39 */
    c->eax = (uint32_t)(R32((uint32_t)(0x9cdfb0u))); /* mov eax, dword ptr [0x1003dfb0] */
    { uint32_t v_ = 0x9b7340u; PUSH32(c, v_); } /* push 0x10027340 */
    { uint32_t v_ = 0x2au; PUSH32(c, v_); } /* push 0x2a */
    { uint32_t v_ = 0x9b730cu; PUSH32(c, v_); } /* push 0x1002730c */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x9b70a0u; PUSH32(c, v_); } /* push 0x100270a0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00993e35u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00993e38u, "int3"); /* int3  */
L_00993e39:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00993e4fu); f_009940e0(c); /* call 0x9940e0 */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 20; return; /* ret 0x10 */
}

void f_00993e60(CPU *c) { /* FUN_10003e60 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x9b3fdfu; PUSH32(c, v_); } /* push 0x10023fdf */
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
    PUSH32(c, 0x00993e87u); f_00996400(c); /* call 0x996400 */
    FPUSH(c, RF64((uint32_t)(0x9b5380u))); /* fld qword ptr [0x10025380] */
    FPUSH(c, 0.30102999566398119521); /* fldlg2  */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W8((uint32_t)(c->esi + 0x7798u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esi + 0x7798], 1 */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x20], ebx */
    W32((uint32_t)(c->esi + 0xa38u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0xa38], ebx */
    FPUSH(c, RF64((uint32_t)(0x9b5380u))); /* fld qword ptr [0x10025380] */
    W32((uint32_t)(c->esi + 0xa3cu), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0xa3c], ebx */
    W32((uint32_t)(c->esi + 0xa40u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0xa40], ebx */
    ST(1) = ST(1) * log2(ST(0)); FPOP(c); /* fyl2x  */
    W32((uint32_t)(c->esi + 0xaa8u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0xaa8], ebx */
    W8((uint32_t)(c->esi + 0xab0u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [esi + 0xab0], bl */
    W32((uint32_t)(c->esi + 0xac0u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0xac0], ebx */
    W32((uint32_t)(c->esi + 0x7794u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x7794], ebx */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x9b5318u)); /* mov dword ptr [esi], 0x10025318 */
    c->edi = (uint32_t)((uint32_t)0x9ce038u); /* mov edi, 0x1003e038 */
    ST(0) = FPRES(c, FDIV(c, RF64((uint32_t)(0x9b5310u)), ST(0))); /* fdivr qword ptr [0x10025310] */
L_00993edf:;
    { double v_ = ST(1); FPUSH(c, v_); } /* fld st(1) */
    FPUSH(c, 0.30102999566398119521); /* fldlg2  */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(1) = ST(1) * log2(ST(0)); FPOP(c); /* fyl2x  */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    PUSH32(c, 0x00993eeeu); f_00998340(c); /* call 0x998340 */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) + RF64((uint32_t)(0x9b5380u))); /* fadd qword ptr [0x10025380] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    { double v_ = ST(1); FPUSH(c, v_); } /* fld st(1) */
    FCOM(c, ST(0), RF64((uint32_t)(0x9b5308u))); FPOP(c); /* fcomp qword ptr [0x10025308] */
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x41u)); /* test ah, 0x41 */
    if (!PF(c)) goto L_00993edf; /* jnp 0x993edf */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x993e10u; PUSH32(c, v_); } /* push 0x10003e10 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    W32((uint32_t)(c->esi + 0xaacu), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [esi + 0xaac], 0x3f800000 */
    W32((uint32_t)(c->esi + 0xa44u), (uint32_t)((uint32_t)0x60u)); /* mov dword ptr [esi + 0xa44], 0x60 */
    PUSH32(c, 0x00993f2fu); f_00996490(c); /* call 0x996490 */
    { uint32_t v_ = 0xe9u; PUSH32(c, v_); } /* push 0xe9 */
    { uint32_t v_ = 0x9b730cu; PUSH32(c, v_); } /* push 0x1002730c */
    { uint32_t v_ = 0xcu; PUSH32(c, v_); } /* push 0xc */
    PUSH32(c, 0x00993f40u); f_00993c30(c); /* call 0x993c30 */
    c->ebp = (uint32_t)(c->eax); /* mov ebp, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0x14], ebp */
    (void)sub32(c, c->ebp, c->ebx); /* cmp ebp, ebx */
    W8((uint32_t)(c->esp + 0x20u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esp + 0x20], 1 */
    if (c->zf) goto L_00993f90; /* je 0x993f90 */
    { uint32_t v_ = 0x17u; PUSH32(c, v_); } /* push 0x17 */
    { uint32_t v_ = 0x9b7364u; PUSH32(c, v_); } /* push 0x10027364 */
    { uint32_t v_ = 0x258u; PUSH32(c, v_); } /* push 0x258 */
    W32((uint32_t)(c->ebp), (uint32_t)((uint32_t)0x96u)); /* mov dword ptr [ebp], 0x96 */
    W32((uint32_t)(c->ebp + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 4], ebx */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 8], ebx */
    PUSH32(c, 0x00993f70u); f_00993c30(c); /* call 0x993c30 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov ecx, dword ptr [ebp] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 2)); /* shl ecx, 2 */
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 8], edi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u))); /* and ecx, 3 */
    while (c->ecx) { W8(c->edi, (uint8_t)((uint8_t)c->eax)); c->edi += (c->df ? -1 : 1); c->ecx--; } /* rep stosb byte ptr es:[edi], al */
    goto L_00993f92; /* jmp 0x993f92 */
L_00993f90:;
    c->ebp = (uint32_t)(logic32(c, 0)); /* xor ebp, ebp */
L_00993f92:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov ecx, dword ptr [esp + 0x18] */
    W32((uint32_t)(c->esi + 0xaa4u), (uint32_t)(c->ebp)); /* mov dword ptr [esi + 0xaa4], ebp */
    W32((uint32_t)(0x9ce2e0u), (uint32_t)(c->esi)); /* mov dword ptr [0x1003e2e0], esi */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 4], ebx */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 8], ebx */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esp += 4; return; /* ret  */
}

void f_00993fc0(CPU *c) { /* PTR_00993fc0 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    c->esp += 8; return; /* ret 4 */
}

void f_00993fd0(CPU *c) { /* PTR_00993fd0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    c->esp += 4; return; /* ret  */
}

void f_00993fe0(CPU *c) { /* PTR_00993fe0 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x4u))); /* mov al, byte ptr [esp + 4] */
    W8((uint32_t)(c->ecx + 0xab0u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ecx + 0xab0], al */
    c->esp += 8; return; /* ret 4 */
}

void f_00993ff0(CPU *c) { /* FUN_10003ff0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00993ff8u); f_00994010(c); /* call 0x994010 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00994008; /* je 0x994008 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00994005u); f_00993c50(c); /* call 0x993c50 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00994008:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00994010(CPU *c) { /* FUN_10004010 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x9b3ff8u; PUSH32(c, v_); } /* push 0x10023ff8 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0xc], esi */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x9b5318u)); /* mov dword ptr [esi], 0x10025318 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x1c], ebx */
    PUSH32(c, 0x00994041u); f_009957f0(c); /* call 0x9957f0 */
    PUSH32(c, 0x00994046u); f_00992360(c); /* call 0x992360 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x0099404du); f_009942f0(c); /* call 0x9942f0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x77a0u))); /* mov eax, dword ptr [esi + 0x77a0] */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_0099405d; /* je 0x99405d */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x8u)); PUSH32(c, 0x0099405du); call_indirect(c, t_); } /* call dword ptr [ecx + 8] */
L_0099405d:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x779cu))); /* mov eax, dword ptr [esi + 0x779c] */
    W32((uint32_t)(c->esi + 0x77a0u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x77a0], ebx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_00994073; /* je 0x994073 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x00994073u); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
L_00994073:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xa40u))); /* mov eax, dword ptr [esi + 0xa40] */
    W32((uint32_t)(c->esi + 0x779cu), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x779c], ebx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_00994089; /* je 0x994089 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x8u)); PUSH32(c, 0x00994089u); call_indirect(c, t_); } /* call dword ptr [ecx + 8] */
L_00994089:;
    c->edi = (uint32_t)(R32((uint32_t)(c->esi + 0xaa4u))); /* mov edi, dword ptr [esi + 0xaa4] */
    W32((uint32_t)(c->esi + 0xa40u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0xa40], ebx */
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    if (c->zf) goto L_009940b5; /* je 0x9940b5 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_009940ac; /* je 0x9940ac */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x009940a6u); f_00993c50(c); /* call 0x993c50 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    W32((uint32_t)(c->edi + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [edi + 8], ebx */
L_009940ac:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x009940b2u); f_00993c50(c); /* call 0x993c50 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_009940b5:;
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    W32((uint32_t)(c->esi + 0xaa4u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0xaa4], ebx */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [esp + 0x18], 0xffffffff */
    PUSH32(c, 0x009940cau); f_00996430(c); /* call 0x996430 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_009940e0(CPU *c) { /* FUN_100040e0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0xa38u))); /* mov eax, dword ptr [ecx + 0xa38] */
    (void)sub32(c, c->eax, (uint32_t)0x5u); /* cmp eax, 5 */
    if ((c->sf == c->of)) goto L_0099414a; /* jge 0x99414a */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->edx = (uint32_t)(shl32(c, c->edx, 7)); /* shl edx, 7 */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    W32((uint32_t)(c->ecx + c->edx * 4 + 0x24u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + edx*4 + 0x24], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0xa38u))); /* mov eax, dword ptr [ecx + 0xa38] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->esi = (uint32_t)(shl32(c, c->esi, 7)); /* shl esi, 7 */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->esi = (uint32_t)((uint32_t)(c->ecx + c->esi * 4 + 0x28u)); /* lea esi, [ecx + esi*4 + 0x28] */
L_00994110:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov al, byte ptr [edx] */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [esi], al */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00994110; /* jne 0x994110 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0xa38u))); /* mov eax, dword ptr [ecx + 0xa38] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->esi = (uint32_t)(shl32(c, c->esi, 7)); /* shl esi, 7 */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->esi = (uint32_t)((uint32_t)(c->ecx + c->esi * 4 + 0x128u)); /* lea esi, [ecx + esi*4 + 0x128] */
L_00994132:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov al, byte ptr [edx] */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [esi], al */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00994132; /* jne 0x994132 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0xa38u))); /* mov eax, dword ptr [ecx + 0xa38] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    W32((uint32_t)(c->ecx + 0xa38u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 0xa38], eax */
L_0099414a:;
    c->esp += 16; return; /* ret 0xc */
}

void f_00994150(CPU *c) { /* FUN_10004150 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x244u)); /* sub esp, 0x244 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x124u; PUSH32(c, v_); } /* push 0x124 */
    { uint32_t v_ = 0x9b730cu; PUSH32(c, v_); } /* push 0x1002730c */
    { uint32_t v_ = 0x101d0u; PUSH32(c, v_); } /* push 0x101d0 */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    PUSH32(c, 0x00994170u); f_00993c30(c); /* call 0x993c30 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0099419b; /* je 0x99419b */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0xfa00u)); /* lea ecx, [eax + 0xfa00] */
    c->esi = (uint32_t)((uint32_t)0x1f4u); /* mov esi, 0x1f4 */
L_00994184:;
    W8((uint32_t)(c->edx), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [edx], 0 */
    W32((uint32_t)(c->ecx), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ecx], 0 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x80u)); /* add edx, 0x80 */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    if (!c->zf) goto L_00994184; /* jne 0x994184 */
    goto L_0099419d; /* jmp 0x99419d */
L_0099419b:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_0099419d:;
    W32((uint32_t)(c->ebx + 0xac0u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 0xac0], eax */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_009941a5:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x9b739cu))); /* mov cl, byte ptr [eax + 0x1002739c] */
    W8((uint32_t)(c->esp + c->eax + 0x14u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esp + eax + 0x14], cl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_009941a5; /* jne 0x9941a5 */
    c->edi = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea edi, [esp + 0x14] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0xffffffffu))); /* or ecx, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edx = (uint32_t)(R32((uint32_t)(0x9cdfb4u))); /* mov edx, dword ptr [0x1003dfb4] */
    while (c->ecx) { (void)sub8(c, ((uint8_t)c->eax), R8(c->edi)); c->edi += (c->df ? -1 : 1); c->ecx--; if (c->zf) break; } /* repne scasb al, byte ptr es:[edi] */
    c->eax = (uint32_t)(R32((uint32_t)(0x9b7394u))); /* mov eax, dword ptr [0x10027394] */
    c->ecx = (c->ecx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(0x9b7398u))); /* mov cx, word ptr [0x10027398] */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    W16((uint32_t)(c->edi + 0x4u), (uint16_t)(((uint16_t)c->ecx))); /* mov word ptr [edi + 4], cx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov ecx, dword ptr [edx + 4] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x114u)); /* lea edx, [esp + 0x114] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x18u)); /* lea edx, [esp + 0x18] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x1cu)); PUSH32(c, 0x009941edu); call_indirect(c, t_); } /* call dword ptr [eax + 0x1c] */
    c->ebp = (uint32_t)(c->eax); /* mov ebp, eax */
    (void)sub32(c, c->ebp, (uint32_t)0xffffffffu); /* cmp ebp, -1 */
    if (c->zf) goto L_009942e4; /* je 0x9942e4 */
L_009941f8:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_009941fa:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x9b739cu))); /* mov cl, byte ptr [eax + 0x1002739c] */
    W8((uint32_t)(c->esp + c->eax + 0x14u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esp + eax + 0x14], cl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_009941fa; /* jne 0x9941fa */
    c->edi = (uint32_t)((uint32_t)(c->esp + 0x140u)); /* lea edi, [esp + 0x140] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0xffffffffu))); /* or ecx, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea edx, [esp + 0x14] */
    while (c->ecx) { (void)sub8(c, ((uint8_t)c->eax), R8(c->edi)); c->edi += (c->df ? -1 : 1); c->ecx--; if (c->zf) break; } /* repne scasb al, byte ptr es:[edi] */
    c->ecx = (uint32_t)((uint32_t)~c->ecx); /* not ecx */
    c->edi = (uint32_t)(sub32(c, c->edi, c->ecx)); /* sub edi, ecx */
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
    c->eax = (uint32_t)(R32((uint32_t)(0x9cdfb4u))); /* mov eax, dword ptr [0x1003dfb4] */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u))); /* and ecx, 3 */
    while (c->ecx) { W8(c->edi, R8(c->esi)); c->esi += (c->df ? -1 : 1); c->edi += (c->df ? -1 : 1); c->ecx--; } /* rep movsb byte ptr es:[edi], byte ptr [esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea eax, [esp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x58u)); PUSH32(c, 0x0099424fu); call_indirect(c, t_); } /* call dword ptr [edx + 0x58] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_009942c5; /* je 0x9942c5 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x94u)); /* lea eax, [esp + 0x94] */
    { uint32_t v_ = 0x80u; PUSH32(c, v_); } /* push 0x80 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x58u)); PUSH32(c, 0x00994269u); call_indirect(c, t_); } /* call dword ptr [edx + 0x58] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_009942bd; /* je 0x9942bd */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x94u)); /* lea ecx, [esp + 0x94] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    PUSH32(c, 0x0099427du); f_00994370(c); /* call 0x994370 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x94u)); /* lea eax, [esp + 0x94] */
    { uint32_t v_ = 0x80u; PUSH32(c, v_); } /* push 0x80 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x5cu)); PUSH32(c, 0x00994291u); call_indirect(c, t_); } /* call dword ptr [edx + 0x5c] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_009942bd; /* je 0x9942bd */
L_00994295:;
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x94u)); /* lea ecx, [esp + 0x94] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    PUSH32(c, 0x009942a5u); f_00994370(c); /* call 0x994370 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x94u)); /* lea eax, [esp + 0x94] */
    { uint32_t v_ = 0x80u; PUSH32(c, v_); } /* push 0x80 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x5cu)); PUSH32(c, 0x009942b9u); call_indirect(c, t_); } /* call dword ptr [edx + 0x5c] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00994295; /* jne 0x994295 */
L_009942bd:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx)); PUSH32(c, 0x009942c5u); call_indirect(c, t_); } /* call dword ptr [edx] */
L_009942c5:;
    c->eax = (uint32_t)(R32((uint32_t)(0x9cdfb4u))); /* mov eax, dword ptr [0x1003dfb4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x114u)); /* lea eax, [esp + 0x114] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x20u)); PUSH32(c, 0x009942dbu); call_indirect(c, t_); } /* call dword ptr [edx + 0x20] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_009941f8; /* je 0x9941f8 */
L_009942e4:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x244u)); /* add esp, 0x244 */
    c->esp += 4; return; /* ret  */
}

void f_009942f0(CPU *c) { /* FUN_100042f0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ecx + 0xac0u))); /* mov ebp, dword ptr [ecx + 0xac0] */
    (void)logic32(c, (uint32_t)(c->ebp & c->ebp)); /* test ebp, ebp */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 4], ecx */
    if (c->zf) goto L_00994363; /* je 0x994363 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0xfa00u)); /* lea edi, [ebp + 0xfa00] */
    c->ebx = (uint32_t)((uint32_t)0x1f4u); /* mov ebx, 0x1f4 */
L_0099430e:;
    c->esi = (uint32_t)(R32((uint32_t)(c->edi))); /* mov esi, dword ptr [edi] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00994343; /* je 0x994343 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00994324; /* je 0x994324 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00994321u); f_00993c50(c); /* call 0x993c50 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00994324:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00994334; /* je 0x994334 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00994331u); f_00993c50(c); /* call 0x993c50 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00994334:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x0099433au); f_00993c50(c); /* call 0x993c50 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    W32((uint32_t)(c->edi), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [edi], 0 */
L_00994343:;
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->zf) goto L_0099430e; /* jne 0x99430e */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x0099434fu); f_00993c50(c); /* call 0x993c50 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ecx, dword ptr [esp + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    W32((uint32_t)(c->ecx + 0xac0u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ecx + 0xac0], 0 */
L_00994363:;
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00994370(CPU *c) { /* FUN_10004370 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x11cu)); /* sub esp, 0x11c */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x130u))); /* mov edi, dword ptr [esp + 0x130] */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x14], esi */
    if (c->zf) goto L_009945e2; /* je 0x9945e2 */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x134u))); /* mov ebp, dword ptr [esp + 0x134] */
    (void)logic32(c, (uint32_t)(c->ebp & c->ebp)); /* test ebp, ebp */
    if (c->zf) goto L_009945e2; /* je 0x9945e2 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x009943a4u); f_0099848b(c); /* call 0x99848b */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xac0u))); /* mov eax, dword ptr [esi + 0xac0] */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebx))); /* mov cl, byte ptr [ebx] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x1c], ebx */
    c->edx = (uint32_t)(c->ebx); /* mov edx, ebx */
    if (c->zf) goto L_009943e2; /* je 0x9943e2 */
L_009943c1:;
    c->ecx = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->edx))); /* movsx ecx, byte ptr [edx] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0xf0000000u))); /* and ecx, 0xf0000000 */
    if (c->zf) goto L_009943dd; /* je 0x9943dd */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->esi = (uint32_t)(shr32(c, c->esi, 24)); /* shr esi, 0x18 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi ^ c->ecx))); /* xor esi, ecx */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ c->esi))); /* xor eax, esi */
L_009943dd:;
    (void)sub8(c, R8((uint32_t)(c->edx)), (uint8_t)0x0u); /* cmp byte ptr [edx], 0 */
    if (!c->zf) goto L_009943c1; /* jne 0x9943c1 */
L_009943e2:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->ecx = (uint32_t)((uint32_t)0x1f4u); /* mov ecx, 0x1f4 */
    { uint32_t d_ = c->ecx; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x009943e9u, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div ecx */
    { uint32_t v_ = 0x47u; PUSH32(c, v_); } /* push 0x47 */
    { uint32_t v_ = 0x9b71a8u; PUSH32(c, v_); } /* push 0x100271a8 */
    { uint32_t v_ = 0x1cu; PUSH32(c, v_); } /* push 0x1c */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x24], edx */
    PUSH32(c, 0x009943fdu); f_00993c30(c); /* call 0x993c30 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov edx, dword ptr [esp + 0x1c] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov eax, dword ptr [esp + 0x24] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->eax = (uint32_t)(shl32(c, c->eax, 7)); /* shl eax, 7 */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->edx)); /* lea ecx, [eax + edx] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + c->edx))); /* mov al, byte ptr [eax + edx] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00994438; /* jne 0x994438 */
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->edx = (uint32_t)(sub32(c, c->edx, c->ebx)); /* sub edx, ebx */
L_0099441d:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    W8((uint32_t)(c->edx + c->eax), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [edx + eax], cl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_0099441d; /* jne 0x99441d */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov ecx, dword ptr [esp + 0x18] */
    W32((uint32_t)(c->edx + c->ecx * 4 + 0xfa00u), (uint32_t)(c->esi)); /* mov dword ptr [edx + ecx*4 + 0xfa00], esi */
    goto L_00994480; /* jmp 0x994480 */
L_00994438:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
L_0099443c:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (c->zf) goto L_0099445c; /* je 0x99445c */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x80u)); /* add eax, 0x80 */
    (void)sub32(c, c->ecx, (uint32_t)0x1f4u); /* cmp ecx, 0x1f4 */
    if ((c->sf != c->of)) goto L_0099443c; /* jl 0x99443c */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x11cu)); /* add esp, 0x11c */
    c->esp += 12; return; /* ret 8 */
L_0099445c:;
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    c->ebx = (uint32_t)(shl32(c, c->ebx, 7)); /* shl ebx, 7 */
    c->ebx = (uint32_t)(add32(c, c->ebx, c->edx)); /* add ebx, edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov edx, dword ptr [esp + 0x1c] */
    c->ebx = (uint32_t)(sub32(c, c->ebx, c->edx)); /* sub ebx, edx */
L_0099446b:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    W8((uint32_t)(c->ebx + c->eax), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [ebx + eax], dl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (!c->zf) goto L_0099446b; /* jne 0x99446b */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    W32((uint32_t)(c->eax + c->ecx * 4 + 0xfa00u), (uint32_t)(c->esi)); /* mov dword ptr [eax + ecx*4 + 0xfa00], esi */
L_00994480:;
    (void)sub32(c, c->ecx, (uint32_t)0xffffffffu); /* cmp ecx, -1 */
    if (c->zf) goto L_009945e2; /* je 0x9945e2 */
    c->eax = (uint32_t)(R32((uint32_t)(0x9ce2e4u))); /* mov eax, dword ptr [0x1003e2e4] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x24u)); /* lea ecx, [esp + 0x24] */
    { uint32_t v_ = 0x9b73dcu; PUSH32(c, v_); } /* push 0x100273dc */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    W32((uint32_t)(0x9ce2e4u), (uint32_t)(c->eax)); /* mov dword ptr [0x1003e2e4], eax */
    PUSH32(c, 0x009944a6u); f_00997f15(c); /* call 0x997f15 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->esi), (uint32_t)(c->ebx)); /* mov dword ptr [esi], ebx */
    W32((uint32_t)(c->esi + 0x14u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x14], ebx */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi))); /* mov edx, dword ptr [edi] */
    { uint32_t v_ = 0xbf800000u; PUSH32(c, v_); } /* push 0xbf800000 */
    { uint32_t v_ = 0x9b73d0u; PUSH32(c, v_); } /* push 0x100273d0 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x38u)); PUSH32(c, 0x009944c2u); call_indirect(c, t_); } /* call dword ptr [edx + 0x38] */
    WF32((uint32_t)(c->esi + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    { uint32_t v_ = 0xbf800000u; PUSH32(c, v_); } /* push 0xbf800000 */
    { uint32_t v_ = 0x9b73c4u; PUSH32(c, v_); } /* push 0x100273c4 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x38u)); PUSH32(c, 0x009944d7u); call_indirect(c, t_); } /* call dword ptr [eax + 0x38] */
    WF32((uint32_t)(c->esi + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi))); /* mov edx, dword ptr [edi] */
    { uint32_t v_ = 0xbf800000u; PUSH32(c, v_); } /* push 0xbf800000 */
    { uint32_t v_ = 0x9b73bcu; PUSH32(c, v_); } /* push 0x100273bc */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x38u)); PUSH32(c, 0x009944ecu); call_indirect(c, t_); } /* call dword ptr [edx + 0x38] */
    WF32((uint32_t)(c->esi + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x18] */
    { uint32_t v_ = 0x9ce2e8u; PUSH32(c, v_); } /* push 0x1003e2e8 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x30u)); /* lea ecx, [esp + 0x30] */
    { uint32_t v_ = 0x100u; PUSH32(c, v_); } /* push 0x100 */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0xc], ebx */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x10], ebx */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x9b73b4u; PUSH32(c, v_); } /* push 0x100273b4 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x00994511u); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00994535; /* je 0x994535 */
L_00994515:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t v_ = 0x100u; PUSH32(c, v_); } /* push 0x100 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi))); /* mov edx, dword ptr [edi] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x30u)); /* lea eax, [esp + 0x30] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x9b73b4u; PUSH32(c, v_); } /* push 0x100273b4 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x1cu)); PUSH32(c, 0x00994531u); call_indirect(c, t_); } /* call dword ptr [edx + 0x1c] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00994515; /* jne 0x994515 */
L_00994535:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    { uint32_t v_ = 0x16du; PUSH32(c, v_); } /* push 0x16d */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 8)); /* shl ecx, 8 */
    { uint32_t v_ = 0x9b730cu; PUSH32(c, v_); } /* push 0x1002730c */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x0099454au); f_00993c30(c); /* call 0x993c30 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    { uint32_t v_ = 0x16eu; PUSH32(c, v_); } /* push 0x16e */
    c->edx = (uint32_t)(shl32(c, c->edx, 2)); /* shl edx, 2 */
    { uint32_t v_ = 0x9b730cu; PUSH32(c, v_); } /* push 0x1002730c */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xc], eax */
    PUSH32(c, 0x00994562u); f_00993c30(c); /* call 0x993c30 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x2cu)); /* lea ecx, [esp + 0x2c] */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x10], eax */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    { uint32_t v_ = 0x9ce2e8u; PUSH32(c, v_); } /* push 0x1003e2e8 */
    { uint32_t v_ = 0x100u; PUSH32(c, v_); } /* push 0x100 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x9b73b4u; PUSH32(c, v_); } /* push 0x100273b4 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x0099458au); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_009945e2; /* je 0x9945e2 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ecx, dword ptr [esp + 0x14] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x2cu)); /* lea edx, [esp + 0x2c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x0099459du); f_009945f0(c); /* call 0x9945f0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x2cu)); /* lea ecx, [esp + 0x2c] */
    { uint32_t v_ = 0x100u; PUSH32(c, v_); } /* push 0x100 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x9b73b4u; PUSH32(c, v_); } /* push 0x100273b4 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x1cu)); PUSH32(c, 0x009945b4u); call_indirect(c, t_); } /* call dword ptr [eax + 0x1c] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_009945e2; /* je 0x9945e2 */
L_009945b8:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ecx, dword ptr [esp + 0x14] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x2cu)); /* lea edx, [esp + 0x2c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x009945c7u); f_009945f0(c); /* call 0x9945f0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x2cu)); /* lea ecx, [esp + 0x2c] */
    { uint32_t v_ = 0x100u; PUSH32(c, v_); } /* push 0x100 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x9b73b4u; PUSH32(c, v_); } /* push 0x100273b4 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x1cu)); PUSH32(c, 0x009945deu); call_indirect(c, t_); } /* call dword ptr [eax + 0x1c] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_009945b8; /* jne 0x9945b8 */
L_009945e2:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x11cu)); /* add esp, 0x11c */
    c->esp += 12; return; /* ret 8 */
}

void f_009945f0(CPU *c) { /* FUN_100045f0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov esi, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x32u); /* cmp dword ptr [esi], 0x32 */
    if (c->zf) goto L_0099469c; /* je 0x99469c */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ebx, dword ptr [esp + 0x14] */
    { uint32_t v_ = 0x2cu; PUSH32(c, v_); } /* push 0x2c */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x0099460cu); f_00998610(c); /* call 0x998610 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (!c->zf) goto L_0099464e; /* jne 0x99464e */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->edx = (uint32_t)(c->ebx); /* mov edx, ebx */
    W32((uint32_t)(c->ecx + c->eax * 4), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [ecx + eax*4], 0x3f800000 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x14u))); /* fld dword ptr [esi + 0x14] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0x9b5388u))); /* fadd dword ptr [0x10025388] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov edi, dword ptr [esi + 0xc] */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->eax = (uint32_t)(add32(c, c->eax, c->edi)); /* add eax, edi */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    WF32((uint32_t)(c->esi + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x14] */
    W32((uint32_t)(c->esi), (uint32_t)(c->ecx)); /* mov dword ptr [esi], ecx */
L_0099463e:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov cl, byte ptr [edx] */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax], cl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_0099463e; /* jne 0x99463e */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 12; return; /* ret 8 */
L_0099464e:;
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x10u)); /* lea edx, [esp + 0x10] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x9b73e4u; PUSH32(c, v_); } /* push 0x100273e4 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x0099465fu); f_009985bf(c); /* call 0x9985bf */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_0099467d; /* jne 0x99467d */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    WF32((uint32_t)(c->ecx + c->eax * 4), (float)ST(0)); FPOP(c); /* fstp dword ptr [ecx + eax*4] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x14u))); /* fadd dword ptr [esi + 0x14] */
    WF32((uint32_t)(c->esi + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x14] */
L_0099467d:;
    W8((uint32_t)(c->edi + 0xffffffffu), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [edi - 1], 0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov edi, dword ptr [esi + 0xc] */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->eax = (uint32_t)(add32(c, c->eax, c->edi)); /* add eax, edi */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->edx = (uint32_t)(c->ebx); /* mov edx, ebx */
    W32((uint32_t)(c->esi), (uint32_t)(c->ecx)); /* mov dword ptr [esi], ecx */
L_00994692:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov cl, byte ptr [edx] */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax], cl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_00994692; /* jne 0x994692 */
L_0099469c:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 12; return; /* ret 8 */
}

void f_009946b0(CPU *c) { /* FUN_100046b0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x14u))); /* mov eax, dword ptr [esi + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x009946beu); f_00993bc0(c); /* call 0x993bc0 */
    WF32((uint32_t)(c->esp + 0xcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xc] */
    FPUSH(c, (double)RF32((uint32_t)(0x9b5128u))); /* fld dword ptr [0x10025128] */
    FPUSH(c, (double)RF32((uint32_t)(0x9b5128u))); /* fld dword ptr [0x10025128] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->esp + 0xcu))); FPOP(c); /* fcomp dword ptr [esp + 0xc] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_009946f7; /* jp 0x9946f7 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
L_009946e0:;
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if ((c->sf == c->of)) goto L_009946f7; /* jge 0x9946f7 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->eax + c->ecx * 4 + 0xfffffffcu))); /* fadd dword ptr [eax + ecx*4 - 4] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->esp + 0x8u))); /* fcom dword ptr [esp + 8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (!PF(c)) goto L_009946e0; /* jnp 0x9946e0 */
L_009946f7:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov edx, dword ptr [esi + 0xc] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 8)); /* shl ecx, 8 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->edx + 0xffffff00u)); /* lea eax, [ecx + edx - 0x100] */
    c->esp += 8; return; /* ret 4 */
}

void f_00994710(CPU *c) { /* PTR_00994710 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx + 0x7794u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ecx + 0x7794], 0 */
    c->esp += 4; return; /* ret  */
}

void f_00994720(CPU *c) { /* FUN_10004720 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x54u)); PUSH32(c, 0x00994728u); call_indirect(c, t_); } /* call dword ptr [eax + 0x54] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x5cu)); PUSH32(c, 0x00994734u); call_indirect(c, t_); } /* call dword ptr [edx + 0x5c] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00994740(CPU *c) { /* PTR_00994740 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x9cdfb4u))); /* mov eax, dword ptr [0x1003dfb4] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    { uint32_t v_ = 0x9b73f4u; PUSH32(c, v_); } /* push 0x100273f4 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x58u)); PUSH32(c, 0x00994756u); call_indirect(c, t_); } /* call dword ptr [edx + 0x58] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_00994763; /* jne 0x994763 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
L_00994763:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edi, dword ptr [esp + 0x10] */
    { uint32_t v_ = 0x9ce2e8u; PUSH32(c, v_); } /* push 0x1003e2e8 */
    { uint32_t v_ = 0x100u; PUSH32(c, v_); } /* push 0x100 */
    { uint32_t v_ = 0x9ce1d8u; PUSH32(c, v_); } /* push 0x1003e1d8 */
    { uint32_t v_ = 0x9b73f0u; PUSH32(c, v_); } /* push 0x100273f0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x00994784u); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_009947da; /* je 0x9947da */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x9ce1d8u; PUSH32(c, v_); } /* push 0x1003e1d8 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    PUSH32(c, 0x00994796u); f_00994860(c); /* call 0x994860 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    { uint32_t v_ = 0x100u; PUSH32(c, v_); } /* push 0x100 */
    { uint32_t v_ = 0x9ce1d8u; PUSH32(c, v_); } /* push 0x1003e1d8 */
    { uint32_t v_ = 0x9b73f0u; PUSH32(c, v_); } /* push 0x100273f0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x1cu)); PUSH32(c, 0x009947adu); call_indirect(c, t_); } /* call dword ptr [edx + 0x1c] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_009947da; /* je 0x9947da */
L_009947b1:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x9ce1d8u; PUSH32(c, v_); } /* push 0x1003e1d8 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    PUSH32(c, 0x009947bfu); f_00994860(c); /* call 0x994860 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t v_ = 0x100u; PUSH32(c, v_); } /* push 0x100 */
    { uint32_t v_ = 0x9ce1d8u; PUSH32(c, v_); } /* push 0x1003e1d8 */
    { uint32_t v_ = 0x9b73f0u; PUSH32(c, v_); } /* push 0x100273f0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x1cu)); PUSH32(c, 0x009947d6u); call_indirect(c, t_); } /* call dword ptr [eax + 0x1c] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_009947b1; /* jne 0x9947b1 */
L_009947da:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    { uint32_t v_ = 0x9ce2e8u; PUSH32(c, v_); } /* push 0x1003e2e8 */
    { uint32_t v_ = 0x100u; PUSH32(c, v_); } /* push 0x100 */
    { uint32_t v_ = 0x9ce1d8u; PUSH32(c, v_); } /* push 0x1003e1d8 */
    { uint32_t v_ = 0x9b73e8u; PUSH32(c, v_); } /* push 0x100273e8 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x009947f6u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_0099484c; /* je 0x99484c */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x9ce1d8u; PUSH32(c, v_); } /* push 0x1003e1d8 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    PUSH32(c, 0x00994808u); f_00994860(c); /* call 0x994860 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t v_ = 0x100u; PUSH32(c, v_); } /* push 0x100 */
    { uint32_t v_ = 0x9ce1d8u; PUSH32(c, v_); } /* push 0x1003e1d8 */
    { uint32_t v_ = 0x9b73e8u; PUSH32(c, v_); } /* push 0x100273e8 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x1cu)); PUSH32(c, 0x0099481fu); call_indirect(c, t_); } /* call dword ptr [eax + 0x1c] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_0099484c; /* je 0x99484c */
L_00994823:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x9ce1d8u; PUSH32(c, v_); } /* push 0x1003e1d8 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    PUSH32(c, 0x00994831u); f_00994860(c); /* call 0x994860 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    { uint32_t v_ = 0x100u; PUSH32(c, v_); } /* push 0x100 */
    { uint32_t v_ = 0x9ce1d8u; PUSH32(c, v_); } /* push 0x1003e1d8 */
    { uint32_t v_ = 0x9b73e8u; PUSH32(c, v_); } /* push 0x100273e8 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x1cu)); PUSH32(c, 0x00994848u); call_indirect(c, t_); } /* call dword ptr [edx + 0x1c] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00994823; /* jne 0x994823 */
L_0099484c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax)); PUSH32(c, 0x00994854u); call_indirect(c, t_); } /* call dword ptr [eax] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
}

void f_00994860(CPU *c) { /* FUN_10004860 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov ebp, dword ptr [esp + 0x18] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x2cu; PUSH32(c, v_); } /* push 0x2c */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00994875u); f_00998610(c); /* call 0x998610 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    if (!c->zf) goto L_0099498e; /* jne 0x99498e */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x7794u))); /* mov ecx, dword ptr [esi + 0x7794] */
    c->edx = (uint32_t)(c->ebp); /* mov edx, ebp */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea eax, [ecx + ecx*2] */
    c->eax = (uint32_t)(shl32(c, c->eax, 3)); /* shl eax, 3 */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea eax, [eax + eax*2] */
    c->ecx = (uint32_t)((uint32_t)(c->esi + c->eax * 4 + 0xbd0u)); /* lea ecx, [esi + eax*4 + 0xbd0] */
L_0099489e:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov al, byte ptr [edx] */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    W8((uint32_t)(c->ecx), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ecx], al */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (!c->zf) goto L_0099489e; /* jne 0x99489e */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x7794u))); /* mov ecx, dword ptr [esi + 0x7794] */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea eax, [ecx + ecx*2] */
    c->eax = (uint32_t)(shl32(c, c->eax, 3)); /* shl eax, 3 */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea ecx, [eax + eax*2] */
    W32((uint32_t)(c->esi + c->ecx * 4 + 0xbc4u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + ecx*4 + 0xbc4], ebx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x7794u))); /* mov ecx, dword ptr [esi + 0x7794] */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea eax, [ecx + ecx*2] */
    c->eax = (uint32_t)(shl32(c, c->eax, 3)); /* shl eax, 3 */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->edx = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea edx, [eax + eax*2] */
    W32((uint32_t)(c->esi + c->edx * 4 + 0xbc8u), (uint32_t)((uint32_t)0x7fffffffu)); /* mov dword ptr [esi + edx*4 + 0xbc8], 0x7fffffff */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x7794u))); /* mov ecx, dword ptr [esi + 0x7794] */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea eax, [ecx + ecx*2] */
    c->eax = (uint32_t)(shl32(c, c->eax, 3)); /* shl eax, 3 */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea eax, [eax + eax*2] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + c->eax * 4 + 0xbc8u))); /* mov ecx, dword ptr [esi + eax*4 + 0xbc8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + c->eax * 4 + 0xbc4u))); /* mov edx, dword ptr [esi + eax*4 + 0xbc4] */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->eax * 4)); /* lea eax, [esi + eax*4] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->edx)); /* sub ecx, edx */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x14], ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x18u))); /* fild dword ptr [esp + 0x18] */
    WF32((uint32_t)(c->esp), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp] */
    PUSH32(c, 0x00994911u); f_00993bc0(c); /* call 0x993bc0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    PUSH32(c, 0x00994919u); f_00998340(c); /* call 0x998340 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x7794u))); /* mov edx, dword ptr [esi + 0x7794] */
    c->ecx = (uint32_t)((uint32_t)(c->edx + c->edx * 2)); /* lea ecx, [edx + edx*2] */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 3)); /* shl ecx, 3 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->edx)); /* sub ecx, edx */
    c->edx = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea edx, [ecx + ecx*2] */
    W32((uint32_t)(c->esi + c->edx * 4 + 0xcd0u), (uint32_t)(c->eax)); /* mov dword ptr [esi + edx*4 + 0xcd0], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x7794u))); /* mov ecx, dword ptr [esi + 0x7794] */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea eax, [ecx + ecx*2] */
    c->eax = (uint32_t)(shl32(c, c->eax, 3)); /* shl eax, 3 */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea eax, [eax + eax*2] */
    W32((uint32_t)(c->esi + c->eax * 4 + 0xbccu), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [esi + eax*4 + 0xbcc], 0x3f800000 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x7794u))); /* mov ecx, dword ptr [esi + 0x7794] */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea eax, [ecx + ecx*2] */
    c->eax = (uint32_t)(shl32(c, c->eax, 3)); /* shl eax, 3 */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea ecx, [eax + eax*2] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x24u))); /* mov al, byte ptr [esp + 0x24] */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    W8((uint32_t)(c->esi + c->ecx * 4 + 0xcd4u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [esi + ecx*4 + 0xcd4], al */
    if (c->zf) goto L_00994b65; /* je 0x994b65 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x7794u))); /* mov ecx, dword ptr [esi + 0x7794] */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea eax, [ecx + ecx*2] */
    c->eax = (uint32_t)(shl32(c, c->eax, 3)); /* shl eax, 3 */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->edx = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea edx, [eax + eax*2] */
    W32((uint32_t)(c->esi + c->edx * 4 + 0xcd0u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + edx*4 + 0xcd0], ebx */
    goto L_00994b65; /* jmp 0x994b65 */
L_0099498e:;
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x18u)); /* lea eax, [esp + 0x18] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x10u)); /* lea ecx, [esp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x24u)); /* lea edx, [esp + 0x24] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x9b7414u; PUSH32(c, v_); } /* push 0x10027414 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x009949a9u); f_009985bf(c); /* call 0x9985bf */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00994a5c; /* je 0x994a5c */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00994a2e; /* je 0x994a2e */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (!c->zf) goto L_00994ab8; /* jne 0x994ab8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov eax, dword ptr [esp + 0x20] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x7794u))); /* mov ecx, dword ptr [esi + 0x7794] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea eax, [eax + eax*4] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea eax, [eax + eax*4] */
    c->edx = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea edx, [eax + eax*4] */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea eax, [ecx + ecx*2] */
    c->eax = (uint32_t)(shl32(c, c->eax, 3)); /* shl eax, 3 */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->edx = (uint32_t)(shl32(c, c->edx, 3)); /* shl edx, 3 */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea eax, [eax + eax*2] */
    W32((uint32_t)(c->esi + c->eax * 4 + 0xbc4u), (uint32_t)(c->edx)); /* mov dword ptr [esi + eax*4 + 0xbc4], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x7794u))); /* mov ecx, dword ptr [esi + 0x7794] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea eax, [eax + eax*4] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea eax, [eax + eax*4] */
    c->edx = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea edx, [eax + eax*4] */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea eax, [ecx + ecx*2] */
    c->eax = (uint32_t)(shl32(c, c->eax, 3)); /* shl eax, 3 */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->edx = (uint32_t)(shl32(c, c->edx, 3)); /* shl edx, 3 */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea eax, [eax + eax*2] */
    W32((uint32_t)(c->esi + c->eax * 4 + 0xbc8u), (uint32_t)(c->edx)); /* mov dword ptr [esi + eax*4 + 0xbc8], edx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x7794u))); /* mov ecx, dword ptr [esi + 0x7794] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea eax, [ecx + ecx*2] */
    c->eax = (uint32_t)(shl32(c, c->eax, 3)); /* shl eax, 3 */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea ecx, [eax + eax*2] */
    WF32((uint32_t)(c->esi + c->ecx * 4 + 0xbccu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + ecx*4 + 0xbcc] */
    goto L_00994ab8; /* jmp 0x994ab8 */
L_00994a2e:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov eax, dword ptr [esp + 0x20] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x7794u))); /* mov ecx, dword ptr [esi + 0x7794] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea eax, [eax + eax*4] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea eax, [eax + eax*4] */
    c->edx = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea edx, [eax + eax*4] */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea eax, [ecx + ecx*2] */
    c->eax = (uint32_t)(shl32(c, c->eax, 3)); /* shl eax, 3 */
    c->edx = (uint32_t)(shl32(c, c->edx, 3)); /* shl edx, 3 */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea eax, [eax + eax*2] */
    W32((uint32_t)(c->esi + c->eax * 4 + 0xbc4u), (uint32_t)(c->edx)); /* mov dword ptr [esi + eax*4 + 0xbc4], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    goto L_00994a78; /* jmp 0x994a78 */
L_00994a5c:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x7794u))); /* mov ecx, dword ptr [esi + 0x7794] */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea eax, [ecx + ecx*2] */
    c->eax = (uint32_t)(shl32(c, c->eax, 3)); /* shl eax, 3 */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->edx = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea edx, [eax + eax*2] */
    W32((uint32_t)(c->esi + c->edx * 4 + 0xbc4u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + edx*4 + 0xbc4], ebx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov eax, dword ptr [esp + 0x20] */
L_00994a78:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x7794u))); /* mov ecx, dword ptr [esi + 0x7794] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea eax, [eax + eax*4] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea eax, [eax + eax*4] */
    c->edx = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea edx, [eax + eax*4] */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea eax, [ecx + ecx*2] */
    c->eax = (uint32_t)(shl32(c, c->eax, 3)); /* shl eax, 3 */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->edx = (uint32_t)(shl32(c, c->edx, 3)); /* shl edx, 3 */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea eax, [eax + eax*2] */
    W32((uint32_t)(c->esi + c->eax * 4 + 0xbc8u), (uint32_t)(c->edx)); /* mov dword ptr [esi + eax*4 + 0xbc8], edx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x7794u))); /* mov ecx, dword ptr [esi + 0x7794] */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea eax, [ecx + ecx*2] */
    c->eax = (uint32_t)(shl32(c, c->eax, 3)); /* shl eax, 3 */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea ecx, [eax + eax*2] */
    W32((uint32_t)(c->esi + c->ecx * 4 + 0xbccu), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [esi + ecx*4 + 0xbcc], 0x3f800000 */
L_00994ab8:;
    W8((uint32_t)(c->edi + 0xffffffffu), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [edi - 1], bl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x7794u))); /* mov ecx, dword ptr [esi + 0x7794] */
    c->edx = (uint32_t)(c->ebp); /* mov edx, ebp */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea eax, [ecx + ecx*2] */
    c->eax = (uint32_t)(shl32(c, c->eax, 3)); /* shl eax, 3 */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea eax, [eax + eax*2] */
    c->ecx = (uint32_t)((uint32_t)(c->esi + c->eax * 4 + 0xbd0u)); /* lea ecx, [esi + eax*4 + 0xbd0] */
L_00994ad5:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov al, byte ptr [edx] */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    W8((uint32_t)(c->ecx), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ecx], al */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (!c->zf) goto L_00994ad5; /* jne 0x994ad5 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x7794u))); /* mov ecx, dword ptr [esi + 0x7794] */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea eax, [ecx + ecx*2] */
    c->eax = (uint32_t)(shl32(c, c->eax, 3)); /* shl eax, 3 */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea ecx, [eax + eax*2] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x24u))); /* mov al, byte ptr [esp + 0x24] */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    W8((uint32_t)(c->esi + c->ecx * 4 + 0xcd4u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [esi + ecx*4 + 0xcd4], al */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x7794u))); /* mov ecx, dword ptr [esi + 0x7794] */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea eax, [ecx + ecx*2] */
    if (c->zf) goto L_00994b19; /* je 0x994b19 */
    c->eax = (uint32_t)(shl32(c, c->eax, 3)); /* shl eax, 3 */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->edx = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea edx, [eax + eax*2] */
    W32((uint32_t)(c->esi + c->edx * 4 + 0xcd0u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + edx*4 + 0xcd0], ebx */
    goto L_00994b65; /* jmp 0x994b65 */
L_00994b19:;
    c->eax = (uint32_t)(shl32(c, c->eax, 3)); /* shl eax, 3 */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea eax, [eax + eax*2] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + c->eax * 4 + 0xbc8u))); /* mov ecx, dword ptr [esi + eax*4 + 0xbc8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + c->eax * 4 + 0xbc4u))); /* mov edx, dword ptr [esi + eax*4 + 0xbc4] */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->eax * 4)); /* lea eax, [esi + eax*4] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->edx)); /* sub ecx, edx */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x24], ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x28u))); /* fild dword ptr [esp + 0x28] */
    WF32((uint32_t)(c->esp), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp] */
    PUSH32(c, 0x00994b45u); f_00993bc0(c); /* call 0x993bc0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    PUSH32(c, 0x00994b4du); f_00998340(c); /* call 0x998340 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x7794u))); /* mov edx, dword ptr [esi + 0x7794] */
    c->ecx = (uint32_t)((uint32_t)(c->edx + c->edx * 2)); /* lea ecx, [edx + edx*2] */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 3)); /* shl ecx, 3 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->edx)); /* sub ecx, edx */
    c->edx = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea edx, [ecx + ecx*2] */
    W32((uint32_t)(c->esi + c->edx * 4 + 0xcd0u), (uint32_t)(c->eax)); /* mov dword ptr [esi + edx*4 + 0xcd0], eax */
L_00994b65:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x7794u))); /* mov eax, dword ptr [esi + 0x7794] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    W32((uint32_t)(c->esi + 0x7794u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x7794], eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 12; return; /* ret 8 */
}

void f_00994b80(CPU *c) { /* PTR_00994b80 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x30u)); /* sub esp, 0x30 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xa3cu))); /* mov eax, dword ptr [esi + 0xa3c] */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0xa40u)); /* lea edi, [esi + 0xa40] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00994b9cu); f_00996496(c); /* call 0x996496 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00994ba8; /* je 0x994ba8 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x30u)); /* add esp, 0x30 */
    c->esp += 4; return; /* ret  */
L_00994ba8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    c->edx = (uint32_t)((uint32_t)(c->esi + 0xa44u)); /* lea edx, [esi + 0xa44] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x10u)); PUSH32(c, 0x00994bb7u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x10] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00994bde; /* je 0x994bde */
    c->eax = (uint32_t)(R32((uint32_t)(0x9cdfb0u))); /* mov eax, dword ptr [0x1003dfb0] */
    { uint32_t v_ = 0x9b712cu; PUSH32(c, v_); } /* push 0x1002712c */
    { uint32_t v_ = 0x215u; PUSH32(c, v_); } /* push 0x215 */
    { uint32_t v_ = 0x9b730cu; PUSH32(c, v_); } /* push 0x1002730c */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x9b70a0u; PUSH32(c, v_); } /* push 0x100270a0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00994bdau); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00994bddu, "int3"); /* int3  */
L_00994bde:;
    c->ecx = (uint32_t)(R32((uint32_t)(0x9ce1d4u))); /* mov ecx, dword ptr [0x1003e1d4] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->edi))); /* mov ebp, dword ptr [edi] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov ebx, dword ptr [ebp] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x18u)); PUSH32(c, 0x00994bf2u); call_indirect(c, t_); } /* call dword ptr [edx + 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t t_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, 0x00994bf7u); call_indirect(c, t_); } /* call dword ptr [ebx + 0x18] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00994c1e; /* je 0x994c1e */
    c->eax = (uint32_t)(R32((uint32_t)(0x9cdfb0u))); /* mov eax, dword ptr [0x1003dfb0] */
    { uint32_t v_ = 0x9b712cu; PUSH32(c, v_); } /* push 0x1002712c */
    { uint32_t v_ = 0x218u; PUSH32(c, v_); } /* push 0x218 */
    { uint32_t v_ = 0x9b730cu; PUSH32(c, v_); } /* push 0x1002730c */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x9b70a0u; PUSH32(c, v_); } /* push 0x100270a0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00994c1au); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00994c1du, "int3"); /* int3  */
L_00994c1e:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(R32((uint32_t)(0x9b5450u))); /* mov eax, dword ptr [0x10025450] */
    W32((uint32_t)(c->esp + 0x30u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x30], edx */
    c->ecx = (uint32_t)(R32((uint32_t)(0x9b5454u))); /* mov ecx, dword ptr [0x10025454] */
    c->edi = (uint32_t)(R32((uint32_t)(c->edi))); /* mov edi, dword ptr [edi] */
    W32((uint32_t)(c->esp + 0x34u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x34], edx */
    W32((uint32_t)(c->esp + 0x38u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x38], edx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->esp + 0x3cu), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x3c], edx */
    c->edx = (uint32_t)(R32((uint32_t)(0x9b5458u))); /* mov edx, dword ptr [0x10025458] */
    W32((uint32_t)(c->esp + 0x30u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x30], eax */
    c->eax = (uint32_t)(R32((uint32_t)(0x9b545cu))); /* mov eax, dword ptr [0x1002545c] */
    W32((uint32_t)(c->esp + 0x38u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x38], edx */
    c->ebp = (uint32_t)((uint32_t)(c->esi + 0x779cu)); /* lea ebp, [esi + 0x779c] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x20u)); /* lea edx, [esp + 0x20] */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)((uint32_t)0x24u)); /* mov dword ptr [esp + 0x20], 0x24 */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)((uint32_t)0xd1u)); /* mov dword ptr [esp + 0x24], 0xd1 */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x28], ebx */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x2c], ebx */
    W32((uint32_t)(c->esp + 0x30u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x30], ebx */
    W32((uint32_t)(c->esp + 0x38u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x38], ecx */
    W32((uint32_t)(c->esp + 0x40u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x40], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi))); /* mov ecx, dword ptr [edi] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0xcu)); PUSH32(c, 0x00994c89u); call_indirect(c, t_); } /* call dword ptr [ecx + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00994cb0; /* je 0x994cb0 */
    c->eax = (uint32_t)(R32((uint32_t)(0x9cdfb0u))); /* mov eax, dword ptr [0x1003dfb0] */
    { uint32_t v_ = 0x9b712cu; PUSH32(c, v_); } /* push 0x1002712c */
    { uint32_t v_ = 0x223u; PUSH32(c, v_); } /* push 0x223 */
    { uint32_t v_ = 0x9b730cu; PUSH32(c, v_); } /* push 0x1002730c */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x9b70a0u; PUSH32(c, v_); } /* push 0x100270a0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00994cacu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00994cafu, "int3"); /* int3  */
L_00994cb0:;
    c->edx = (uint32_t)(R32((uint32_t)(0x9ce1d4u))); /* mov edx, dword ptr [0x1003e1d4] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x9cdfb4u))); /* mov ecx, dword ptr [0x1003dfb4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov eax, dword ptr [edx + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    c->edi = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edi, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x110u)); PUSH32(c, 0x00994cc9u); call_indirect(c, t_); } /* call dword ptr [edx + 0x110] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(0x9ce1d4u))); /* mov eax, dword ptr [0x1003e1d4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    { uint32_t t_ = R32((uint32_t)(c->edi + 0x58u)); PUSH32(c, 0x00994cd5u); call_indirect(c, t_); } /* call dword ptr [edi + 0x58] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    if (!c->zf) goto L_00994cf4; /* jne 0x994cf4 */
    c->eax = (uint32_t)((uint32_t)0x9ce2e8u); /* mov eax, 0x1003e2e8 */
    c->edx = (uint32_t)((uint32_t)(c->esi + 0xac4u)); /* lea edx, [esi + 0xac4] */
    c->edx = (uint32_t)(sub32(c, c->edx, c->eax)); /* sub edx, eax */
L_00994ce8:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    W8((uint32_t)(c->edx + c->eax), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [edx + eax], cl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub8(c, ((uint8_t)c->ecx), ((uint8_t)c->ebx)); /* cmp cl, bl */
    if (!c->zf) goto L_00994ce8; /* jne 0x994ce8 */
    goto L_00994d1e; /* jmp 0x994d1e */
L_00994cf4:;
    c->edx = (uint32_t)(R32((uint32_t)(c->edi))); /* mov edx, dword ptr [edi] */
    { uint32_t v_ = 0x9ce2e8u; PUSH32(c, v_); } /* push 0x1003e2e8 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0xac4u)); /* lea eax, [esi + 0xac4] */
    { uint32_t v_ = 0x100u; PUSH32(c, v_); } /* push 0x100 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x9b7444u; PUSH32(c, v_); } /* push 0x10027444 */
    { uint32_t v_ = 0x9b743cu; PUSH32(c, v_); } /* push 0x1002743c */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00994d16u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi))); /* mov edx, dword ptr [edi] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    { uint32_t t_ = R32((uint32_t)(c->edx)); PUSH32(c, 0x00994d1eu); call_indirect(c, t_); } /* call dword ptr [edx] */
L_00994d1e:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov eax, dword ptr [ebp] */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x77a0u)); /* lea edi, [esi + 0x77a0] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x9b5440u; PUSH32(c, v_); } /* push 0x10025440 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx)); PUSH32(c, 0x00994d32u); call_indirect(c, t_); } /* call dword ptr [ecx] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    if (!c->zf) goto L_00994d5d; /* jne 0x994d5d */
    c->eax = (uint32_t)(R32((uint32_t)(0x9cdfb0u))); /* mov eax, dword ptr [0x1003dfb0] */
    { uint32_t v_ = 0x9b742cu; PUSH32(c, v_); } /* push 0x1002742c */
    { uint32_t v_ = 0x238u; PUSH32(c, v_); } /* push 0x238 */
    { uint32_t v_ = 0x9b730cu; PUSH32(c, v_); } /* push 0x1002730c */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0x9b70a0u; PUSH32(c, v_); } /* push 0x100270a0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00994d59u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00994d5cu, "int3"); /* int3  */
L_00994d5d:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x8u)); /* lea ecx, [esp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)((uint32_t)0x501502f9u)); /* mov dword ptr [esp + 0xc], 0x501502f9 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0x501502f9u)); /* mov dword ptr [esp + 0x10], 0x501502f9 */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0x501502f9u)); /* mov dword ptr [esp + 0x14], 0x501502f9 */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4cu)); PUSH32(c, 0x00994d81u); call_indirect(c, t_); } /* call dword ptr [eax + 0x4c] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x9ce1d4u))); /* mov ecx, dword ptr [0x1003e1d4] */
    { uint32_t v_ = 0x9b7420u; PUSH32(c, v_); } /* push 0x10027420 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x4cu)); PUSH32(c, 0x00994d91u); call_indirect(c, t_); } /* call dword ptr [edx + 0x4c] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    W32((uint32_t)(c->esi + 0xaa8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xaa8], eax */
    W8((uint32_t)(c->esi + 0xab0u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esi + 0xab0], 1 */
    PUSH32(c, 0x00994da5u); f_00994150(c); /* call 0x994150 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x30u)); /* add esp, 0x30 */
    c->esp += 4; return; /* ret  */
}

void f_00994cb0(CPU *c) { /* PTR_00994cb0 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(0x9ce1d4u))); /* mov edx, dword ptr [0x1003e1d4] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x9cdfb4u))); /* mov ecx, dword ptr [0x1003dfb4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov eax, dword ptr [edx + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    c->edi = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edi, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x110u)); PUSH32(c, 0x00994cc9u); call_indirect(c, t_); } /* call dword ptr [edx + 0x110] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(0x9ce1d4u))); /* mov eax, dword ptr [0x1003e1d4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    { uint32_t t_ = R32((uint32_t)(c->edi + 0x58u)); PUSH32(c, 0x00994cd5u); call_indirect(c, t_); } /* call dword ptr [edi + 0x58] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    if (!c->zf) goto L_00994cf4; /* jne 0x994cf4 */
    c->eax = (uint32_t)((uint32_t)0x9ce2e8u); /* mov eax, 0x1003e2e8 */
    c->edx = (uint32_t)((uint32_t)(c->esi + 0xac4u)); /* lea edx, [esi + 0xac4] */
    c->edx = (uint32_t)(sub32(c, c->edx, c->eax)); /* sub edx, eax */
L_00994ce8:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    W8((uint32_t)(c->edx + c->eax), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [edx + eax], cl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub8(c, ((uint8_t)c->ecx), ((uint8_t)c->ebx)); /* cmp cl, bl */
    if (!c->zf) goto L_00994ce8; /* jne 0x994ce8 */
    goto L_00994d1e; /* jmp 0x994d1e */
L_00994cf4:;
    c->edx = (uint32_t)(R32((uint32_t)(c->edi))); /* mov edx, dword ptr [edi] */
    { uint32_t v_ = 0x9ce2e8u; PUSH32(c, v_); } /* push 0x1003e2e8 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0xac4u)); /* lea eax, [esi + 0xac4] */
    { uint32_t v_ = 0x100u; PUSH32(c, v_); } /* push 0x100 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x9b7444u; PUSH32(c, v_); } /* push 0x10027444 */
    { uint32_t v_ = 0x9b743cu; PUSH32(c, v_); } /* push 0x1002743c */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00994d16u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi))); /* mov edx, dword ptr [edi] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    { uint32_t t_ = R32((uint32_t)(c->edx)); PUSH32(c, 0x00994d1eu); call_indirect(c, t_); } /* call dword ptr [edx] */
L_00994d1e:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov eax, dword ptr [ebp] */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x77a0u)); /* lea edi, [esi + 0x77a0] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x9b5440u; PUSH32(c, v_); } /* push 0x10025440 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx)); PUSH32(c, 0x00994d32u); call_indirect(c, t_); } /* call dword ptr [ecx] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    if (!c->zf) goto L_00994d5d; /* jne 0x994d5d */
    c->eax = (uint32_t)(R32((uint32_t)(0x9cdfb0u))); /* mov eax, dword ptr [0x1003dfb0] */
    { uint32_t v_ = 0x9b742cu; PUSH32(c, v_); } /* push 0x1002742c */
    { uint32_t v_ = 0x238u; PUSH32(c, v_); } /* push 0x238 */
    { uint32_t v_ = 0x9b730cu; PUSH32(c, v_); } /* push 0x1002730c */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0x9b70a0u; PUSH32(c, v_); } /* push 0x100270a0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00994d59u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00994d5cu, "int3"); /* int3  */
L_00994d5d:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x8u)); /* lea ecx, [esp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)((uint32_t)0x501502f9u)); /* mov dword ptr [esp + 0xc], 0x501502f9 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0x501502f9u)); /* mov dword ptr [esp + 0x10], 0x501502f9 */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0x501502f9u)); /* mov dword ptr [esp + 0x14], 0x501502f9 */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4cu)); PUSH32(c, 0x00994d81u); call_indirect(c, t_); } /* call dword ptr [eax + 0x4c] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x9ce1d4u))); /* mov ecx, dword ptr [0x1003e1d4] */
    { uint32_t v_ = 0x9b7420u; PUSH32(c, v_); } /* push 0x10027420 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x4cu)); PUSH32(c, 0x00994d91u); call_indirect(c, t_); } /* call dword ptr [edx + 0x4c] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    W32((uint32_t)(c->esi + 0xaa8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xaa8], eax */
    W8((uint32_t)(c->esi + 0xab0u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esi + 0xab0], 1 */
    PUSH32(c, 0x00994da5u); f_00994150(c); /* call 0x994150 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x30u)); /* add esp, 0x30 */
    c->esp += 4; return; /* ret  */
}

void f_00994db0(CPU *c) { /* PTR_00994db0 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->ecx); /* mov ebp, ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0xab0u))); /* mov al, byte ptr [ebp + 0xab0] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_009951b4; /* je 0x9951b4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    rdtsc(c); /* rdtsc  */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    PUSH32(c, 0x00994dd2u); f_00995c10(c); /* call 0x995c10 */
    c->ecx = (uint32_t)(R32((uint32_t)(0x9cdfb4u))); /* mov ecx, dword ptr [0x1003dfb4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0xe4u)); PUSH32(c, 0x00994de0u); call_indirect(c, t_); } /* call dword ptr [eax + 0xe4] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xaa8u))); /* mov eax, dword ptr [ebp + 0xaa8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0099502e; /* je 0x99502e */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x9cdfd4u))); /* mov cl, byte ptr [0x1003dfd4] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->ecx))); /* test al, cl */
    if (!c->zf) goto L_00994e15; /* jne 0x994e15 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(((uint8_t)c->ecx)); /* mov dl, cl */
    { uint32_t v_ = 0x995200u; PUSH32(c, v_); } /* push 0x10005200 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->edx) | ((uint8_t)c->eax)))); /* or dl, al */
    W8((uint32_t)(0x9cdfd4u), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [0x1003dfd4], dl */
    PUSH32(c, 0x00994e12u); f_0099841f(c); /* call 0x99841f */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00994e15:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x9cdfd4u))); /* mov cl, byte ptr [0x1003dfd4] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x2u); /* mov al, 2 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->ecx))); /* test al, cl */
    if (!c->zf) goto L_00994e38; /* jne 0x994e38 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(((uint8_t)c->ecx)); /* mov dl, cl */
    { uint32_t v_ = 0x9951f0u; PUSH32(c, v_); } /* push 0x100051f0 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->edx) | ((uint8_t)c->eax)))); /* or dl, al */
    W8((uint32_t)(0x9cdfd4u), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [0x1003dfd4], dl */
    PUSH32(c, 0x00994e35u); f_0099841f(c); /* call 0x99841f */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00994e38:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x9cdfd4u))); /* mov cl, byte ptr [0x1003dfd4] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x4u); /* mov al, 4 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->ecx))); /* test al, cl */
    if (!c->zf) goto L_00994e5b; /* jne 0x994e5b */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(((uint8_t)c->ecx)); /* mov dl, cl */
    { uint32_t v_ = 0x9951e0u; PUSH32(c, v_); } /* push 0x100051e0 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->edx) | ((uint8_t)c->eax)))); /* or dl, al */
    W8((uint32_t)(0x9cdfd4u), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [0x1003dfd4], dl */
    PUSH32(c, 0x00994e58u); f_0099841f(c); /* call 0x99841f */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00994e5b:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x9cdfd4u))); /* mov cl, byte ptr [0x1003dfd4] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x8u); /* mov al, 8 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->ecx))); /* test al, cl */
    if (!c->zf) goto L_00994e7e; /* jne 0x994e7e */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(((uint8_t)c->ecx)); /* mov dl, cl */
    { uint32_t v_ = 0x9951d0u; PUSH32(c, v_); } /* push 0x100051d0 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->edx) | ((uint8_t)c->eax)))); /* or dl, al */
    W8((uint32_t)(0x9cdfd4u), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [0x1003dfd4], dl */
    PUSH32(c, 0x00994e7bu); f_0099841f(c); /* call 0x99841f */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00994e7e:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x9cdfd4u))); /* mov cl, byte ptr [0x1003dfd4] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x10u); /* mov al, 0x10 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->ecx))); /* test al, cl */
    if (!c->zf) goto L_00994edc; /* jne 0x994edc */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(((uint8_t)c->ecx)); /* mov dl, cl */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->edx) | ((uint8_t)c->eax)))); /* or dl, al */
    W8((uint32_t)(0x9cdfd4u), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [0x1003dfd4], dl */
    c->eax = (uint32_t)((uint32_t)0x9cdff8u); /* mov eax, 0x1003dff8 */
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
    { uint32_t v_ = 0x9951c0u; PUSH32(c, v_); } /* push 0x100051c0 */
    PUSH32(c, 0x00994ed9u); f_0099841f(c); /* call 0x99841f */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00994edc:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xaa8u))); /* mov ecx, dword ptr [ebp + 0xaa8] */
    { uint32_t v_ = 0x9cdff8u; PUSH32(c, v_); } /* push 0x1003dff8 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x5cu)); PUSH32(c, 0x00994eeeu); call_indirect(c, t_); } /* call dword ptr [edx + 0x5c] */
    FPUSH(c, (double)RF32((uint32_t)(0x9ce00cu))); /* fld dword ptr [0x1003e00c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x9ce02cu))); /* fmul dword ptr [0x1003e02c] */
    FPUSH(c, (double)RF32((uint32_t)(0x9ce008u))); /* fld dword ptr [0x1003e008] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x9ce028u))); /* fmul dword ptr [0x1003e028] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(0x9ce010u))); /* fld dword ptr [0x1003e010] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x9ce030u))); /* fmul dword ptr [0x1003e030] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(0x9ce01cu))); /* fld dword ptr [0x1003e01c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x9ce02cu))); /* fmul dword ptr [0x1003e02c] */
    FPUSH(c, (double)RF32((uint32_t)(0x9ce020u))); /* fld dword ptr [0x1003e020] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x9ce030u))); /* fmul dword ptr [0x1003e030] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(0x9ce018u))); /* fld dword ptr [0x1003e018] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x9ce028u))); /* fmul dword ptr [0x1003e028] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(0x9ce02cu))); /* fld dword ptr [0x1003e02c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x9cdffcu))); /* fmul dword ptr [0x1003dffc] */
    FPUSH(c, (double)RF32((uint32_t)(0x9ce030u))); /* fld dword ptr [0x1003e030] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x9ce000u))); /* fmul dword ptr [0x1003e000] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(0x9ce028u))); /* fld dword ptr [0x1003e028] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x9cdff8u))); /* fmul dword ptr [0x1003dff8] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = -ST(0); /* fchs  */
    WF32((uint32_t)(0x9ce028u), (float)ST(0)); FPOP(c); /* fstp dword ptr [0x1003e028] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = -ST(0); /* fchs  */
    WF32((uint32_t)(0x9ce02cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [0x1003e02c] */
    ST(0) = -ST(0); /* fchs  */
    WF32((uint32_t)(0x9ce030u), (float)ST(0)); FPOP(c); /* fstp dword ptr [0x1003e030] */
    c->eax = (uint32_t)((uint32_t)0x9cdff8u); /* mov eax, 0x1003dff8 */
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
    c->eax = (uint32_t)(R32((uint32_t)(0x9ce018u))); /* mov eax, dword ptr [0x1003e018] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x9ce01cu))); /* mov ecx, dword ptr [0x1003e01c] */
    c->edx = (uint32_t)(R32((uint32_t)(0x9ce020u))); /* mov edx, dword ptr [0x1003e020] */
    W32((uint32_t)(0x9ce1c8u), (uint32_t)(c->eax)); /* mov dword ptr [0x1003e1c8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(0x9ce008u))); /* mov eax, dword ptr [0x1003e008] */
    W32((uint32_t)(0x9ce1ccu), (uint32_t)(c->ecx)); /* mov dword ptr [0x1003e1cc], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(0x9ce00cu))); /* mov ecx, dword ptr [0x1003e00c] */
    W32((uint32_t)(0x9ce1d0u), (uint32_t)(c->edx)); /* mov dword ptr [0x1003e1d0], edx */
    c->edx = (uint32_t)(R32((uint32_t)(0x9ce010u))); /* mov edx, dword ptr [0x1003e010] */
    W32((uint32_t)(0x9cdfd8u), (uint32_t)(c->eax)); /* mov dword ptr [0x1003dfd8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(0x9ce028u))); /* mov eax, dword ptr [0x1003e028] */
    W32((uint32_t)(0x9cdfdcu), (uint32_t)(c->ecx)); /* mov dword ptr [0x1003dfdc], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(0x9ce02cu))); /* mov ecx, dword ptr [0x1003e02c] */
    W32((uint32_t)(0x9cdfe0u), (uint32_t)(c->edx)); /* mov dword ptr [0x1003dfe0], edx */
    c->edx = (uint32_t)(R32((uint32_t)(0x9ce030u))); /* mov edx, dword ptr [0x1003e030] */
    W32((uint32_t)(0x9cdfb8u), (uint32_t)(c->eax)); /* mov dword ptr [0x1003dfb8], eax */
    W32((uint32_t)(0x9cdfbcu), (uint32_t)(c->ecx)); /* mov dword ptr [0x1003dfbc], ecx */
    W32((uint32_t)(0x9cdfc0u), (uint32_t)(c->edx)); /* mov dword ptr [0x1003dfc0], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov eax, dword ptr [ebp] */
    { uint32_t v_ = 0x9cdfb8u; PUSH32(c, v_); } /* push 0x1003dfb8 */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4cu)); PUSH32(c, 0x0099501cu); call_indirect(c, t_); } /* call dword ptr [eax + 0x4c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov edx, dword ptr [ebp] */
    { uint32_t v_ = 0x9cdfd8u; PUSH32(c, v_); } /* push 0x1003dfd8 */
    { uint32_t v_ = 0x9ce1c8u; PUSH32(c, v_); } /* push 0x1003e1c8 */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x50u)); PUSH32(c, 0x0099502eu); call_indirect(c, t_); } /* call dword ptr [edx + 0x50] */
L_0099502e:;
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
L_00995030:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xaa4u))); /* mov eax, dword ptr [ebp + 0xaa4] */
    c->esi = (uint32_t)(c->edi); /* mov esi, edi */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi | (uint32_t)0x80000000u))); /* or esi, 0x80000000 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ecx, dword ptr [eax + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + c->esi * 4))); /* mov ecx, dword ptr [ecx + esi*4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_0099505f; /* je 0x99505f */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x24u)); PUSH32(c, 0x00995052u); call_indirect(c, t_); } /* call dword ptr [edx + 0x24] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_0099505f; /* jne 0x99505f */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov edx, dword ptr [ebp] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x2cu)); PUSH32(c, 0x0099505fu); call_indirect(c, t_); } /* call dword ptr [edx + 0x2c] */
L_0099505f:;
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->edi, (uint32_t)0x96u); /* cmp edi, 0x96 */
    if ((c->sf != c->of)) goto L_00995030; /* jl 0x995030 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x77a0u))); /* mov eax, dword ptr [ebp + 0x77a0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x44u)); PUSH32(c, 0x00995074u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x44] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0x7798u))); /* mov al, byte ptr [ebp + 0x7798] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00995165; /* je 0x995165 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x7794u))); /* mov eax, dword ptr [ebp + 0x7794] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_00995165; /* jle 0x995165 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ebx, dword ptr [esp + 0x10] */
    c->esi = (uint32_t)((uint32_t)(c->ebp + 0xcd0u)); /* lea esi, [ebp + 0xcd0] */
L_0099509c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x4u))); /* mov al, byte ptr [esi + 4] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    if (c->zf) goto L_009950e5; /* je 0x9950e5 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00995150; /* jne 0x995150 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xfffffefcu))); /* mov eax, dword ptr [esi - 0x104] */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0xffffff00u)); /* lea ecx, [esi - 0x100] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0xbf800000u; PUSH32(c, v_); } /* push 0xbf800000 */
    { uint32_t v_ = 0xbf800000u; PUSH32(c, v_); } /* push 0xbf800000 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [esi], 0xffffffff */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov edx, dword ptr [ebp] */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x1cu)); PUSH32(c, 0x009950e3u); call_indirect(c, t_); } /* call dword ptr [edx + 0x1c] */
    goto L_00995150; /* jmp 0x995150 */
L_009950e5:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_009950ef; /* jle 0x9950ef */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ebx)); /* sub eax, ebx */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    goto L_00995150; /* jmp 0x995150 */
L_009950ef:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0xfffffef8u))); /* mov edx, dword ptr [esi - 0x108] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0xfffffef4u))); /* mov ecx, dword ptr [esi - 0x10c] */
    c->edx = (uint32_t)(sub32(c, c->edx, c->ecx)); /* sub edx, ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x14], edx */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x14u))); /* fild dword ptr [esp + 0x14] */
    WF32((uint32_t)(c->esp), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp] */
    PUSH32(c, 0x0099510eu); f_00993bc0(c); /* call 0x993bc0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    PUSH32(c, 0x00995116u); f_00998340(c); /* call 0x998340 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0xfffffef4u))); /* mov ecx, dword ptr [esi - 0x10c] */
    c->edx = (uint32_t)((uint32_t)(c->esi + 0xffffff00u)); /* lea edx, [esi - 0x100] */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0xfffffefcu))); /* mov ecx, dword ptr [esi - 0x104] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0xbf800000u; PUSH32(c, v_); } /* push 0xbf800000 */
    { uint32_t v_ = 0xbf800000u; PUSH32(c, v_); } /* push 0xbf800000 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov eax, dword ptr [ebp] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x1cu)); PUSH32(c, 0x00995150u); call_indirect(c, t_); } /* call dword ptr [eax + 0x1c] */
L_00995150:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x7794u))); /* mov eax, dword ptr [ebp + 0x7794] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x114u)); /* add esi, 0x114 */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if ((c->sf != c->of)) goto L_0099509c; /* jl 0x99509c */
L_00995165:;
    rdtsc(c); /* rdtsc  */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->esp + 0x14u)))); /* sub eax, dword ptr [esp + 0x14] */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xaa4u))); /* mov eax, dword ptr [ebp + 0xaa4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov eax, dword ptr [eax + 4] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    W32((uint32_t)(c->ebp + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 4], eax */
    if ((c->zf || c->sf != c->of)) goto L_00995188; /* jle 0x995188 */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 8], eax */
L_00995188:;
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea ecx, [ebp + 0x10] */
    c->edx = (uint32_t)((uint32_t)(c->ebp + 0xcu)); /* lea edx, [ebp + 0xc] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00995195u); f_00996280(c); /* call 0x996280 */
    c->eax = (uint32_t)(R32((uint32_t)(0x9cdfa4u))); /* mov eax, dword ptr [0x1003dfa4] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    W32((uint32_t)(c->ebp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x14], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(0x9cdfa8u))); /* mov ecx, dword ptr [0x1003dfa8] */
    W32((uint32_t)(c->ebp + 0x18u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp + 0x18], ecx */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    { f_00995b80(c); return; } /* jmp 0x995b80 */
L_009951b4:;
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->esp += 4; return; /* ret  */
}

void f_009951c0(CPU *c) { /* PTR_009951c0 */
    PREEMPT_POLL(c);
    c->esp += 4; return; /* ret  */
}

void f_009951d0(CPU *c) { /* PTR_009951d0 */
    PREEMPT_POLL(c);
    c->esp += 4; return; /* ret  */
}

void f_009951e0(CPU *c) { /* PTR_009951e0 */
    PREEMPT_POLL(c);
    c->esp += 4; return; /* ret  */
}

void f_009951f0(CPU *c) { /* PTR_009951f0 */
    PREEMPT_POLL(c);
    c->esp += 4; return; /* ret  */
}

void f_00995200(CPU *c) { /* PTR_00995200 */
    PREEMPT_POLL(c);
    c->esp += 4; return; /* ret  */
}

void f_00995210(CPU *c) { /* FUN_10005210 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x9b4078u; PUSH32(c, v_); } /* push 0x10024078 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x208u)); /* sub esp, 0x208 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x14u))); /* mov eax, dword ptr [ebx + 0x14] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    (void)sub32(c, c->eax, (uint32_t)0x457800u); /* cmp eax, 0x457800 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x10], ebx */
    if ((!c->zf && c->sf == c->of)) goto L_0099566f; /* jg 0x99566f */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebx + 0xab0u))); /* mov al, byte ptr [ebx + 0xab0] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_0099566f; /* je 0x99566f */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xaa4u))); /* mov eax, dword ptr [ebx + 0xaa4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if (!c->cf) goto L_0099566f; /* jae 0x99566f */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xac0u))); /* mov eax, dword ptr [ebx + 0xac0] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009953d3; /* je 0x9953d3 */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x228u))); /* mov esi, dword ptr [esp + 0x228] */
    { uint32_t v_ = 0x5cu; PUSH32(c, v_); } /* push 0x5c */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00995281u); f_00998610(c); /* call 0x998610 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_009953d3; /* jne 0x9953d3 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x18u)); /* lea edx, [esp + 0x18] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->edx = (uint32_t)(sub32(c, c->edx, c->esi)); /* sub edx, esi */
L_00995294:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    W8((uint32_t)(c->edx + c->eax), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [edx + eax], cl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_00995294; /* jne 0x995294 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x18u)); /* lea edx, [esp + 0x18] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x009952a8u); f_0099848b(c); /* call 0x99848b */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edx = (uint32_t)(c->ebx); /* mov edx, ebx */
    (void)sub8(c, R8((uint32_t)(c->ebx)), (uint8_t)0x0u); /* cmp byte ptr [ebx], 0 */
    if (c->zf) goto L_009952d7; /* je 0x9952d7 */
L_009952b6:;
    c->ecx = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->edx))); /* movsx ecx, byte ptr [edx] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0xf0000000u))); /* and ecx, 0xf0000000 */
    if (c->zf) goto L_009952d2; /* je 0x9952d2 */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->esi = (uint32_t)(shr32(c, c->esi, 24)); /* shr esi, 0x18 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi ^ c->ecx))); /* xor esi, ecx */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ c->esi))); /* xor eax, esi */
L_009952d2:;
    (void)sub8(c, R8((uint32_t)(c->edx)), (uint8_t)0x0u); /* cmp byte ptr [edx], 0 */
    if (!c->zf) goto L_009952b6; /* jne 0x9952b6 */
L_009952d7:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->ecx = (uint32_t)((uint32_t)0x1f4u); /* mov ecx, 0x1f4 */
    { uint32_t d_ = c->ecx; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x009952deu, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div ecx */
    c->esi = (uint32_t)(c->ebx); /* mov esi, ebx */
    c->ebp = (uint32_t)(c->edx); /* mov ebp, edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    c->eax = (uint32_t)(c->ebp); /* mov eax, ebp */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0xac0u))); /* mov ecx, dword ptr [edx + 0xac0] */
    c->eax = (uint32_t)(shl32(c, c->eax, 7)); /* shl eax, 7 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
L_009952f5:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(((uint8_t)c->edx)); /* mov cl, dl */
    (void)sub8(c, ((uint8_t)c->edx), R8((uint32_t)(c->esi))); /* cmp dl, byte ptr [esi] */
    if (!c->zf) goto L_00995319; /* jne 0x995319 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_00995315; /* je 0x995315 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1u))); /* mov dl, byte ptr [eax + 1] */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(((uint8_t)c->edx)); /* mov cl, dl */
    (void)sub8(c, ((uint8_t)c->edx), R8((uint32_t)(c->esi + 0x1u))); /* cmp dl, byte ptr [esi + 1] */
    if (!c->zf) goto L_00995319; /* jne 0x995319 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x2u)); /* add eax, 2 */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x2u)); /* add esi, 2 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_009952f5; /* jne 0x9952f5 */
L_00995315:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_0099531e; /* jmp 0x99531e */
L_00995319:;
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, (uint32_t)0xffffffffu)); /* sbb eax, -1 */
L_0099531e:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00995335; /* jne 0x995335 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0xac0u))); /* mov eax, dword ptr [eax + 0xac0] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->ebp * 4 + 0xfa00u))); /* mov eax, dword ptr [eax + ebp*4 + 0xfa00] */
    goto L_00995394; /* jmp 0x995394 */
L_00995335:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ecx + 0xac0u))); /* mov ebp, dword ptr [ecx + 0xac0] */
L_00995341:;
    c->esi = (uint32_t)(c->ebx); /* mov esi, ebx */
    c->eax = (uint32_t)(c->ebp); /* mov eax, ebp */
L_00995345:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(((uint8_t)c->edx)); /* mov cl, dl */
    (void)sub8(c, ((uint8_t)c->edx), R8((uint32_t)(c->esi))); /* cmp dl, byte ptr [esi] */
    if (!c->zf) goto L_00995369; /* jne 0x995369 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_00995365; /* je 0x995365 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1u))); /* mov dl, byte ptr [eax + 1] */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(((uint8_t)c->edx)); /* mov cl, dl */
    (void)sub8(c, ((uint8_t)c->edx), R8((uint32_t)(c->esi + 0x1u))); /* cmp dl, byte ptr [esi + 1] */
    if (!c->zf) goto L_00995369; /* jne 0x995369 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x2u)); /* add eax, 2 */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x2u)); /* add esi, 2 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_00995345; /* jne 0x995345 */
L_00995365:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_0099536e; /* jmp 0x99536e */
L_00995369:;
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, (uint32_t)0xffffffffu)); /* sbb eax, -1 */
L_0099536e:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00995383; /* je 0x995383 */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->ebp = (uint32_t)(add32(c, c->ebp, (uint32_t)0x80u)); /* add ebp, 0x80 */
    (void)sub32(c, c->edi, (uint32_t)0x1f4u); /* cmp edi, 0x1f4 */
    if ((c->sf != c->of)) goto L_00995341; /* jl 0x995341 */
    goto L_009953cf; /* jmp 0x9953cf */
L_00995383:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0xac0u))); /* mov eax, dword ptr [eax + 0xac0] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->edi * 4 + 0xfa00u))); /* mov eax, dword ptr [eax + edi*4 + 0xfa00] */
L_00995394:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009953cf; /* je 0x9953cf */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov edx, dword ptr [eax + 8] */
    W32((uint32_t)(c->esp + 0x248u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x248], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x18u))); /* mov ecx, dword ptr [eax + 0x18] */
    (void)sub32(c, c->ecx, (uint32_t)0xbf800000u); /* cmp ecx, 0xbf800000 */
    W32((uint32_t)(c->esp + 0x24cu), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x24c], edx */
    if (c->zf) goto L_009953be; /* je 0x9953be */
    W32((uint32_t)(c->esp + 0x254u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x254], ecx */
L_009953be:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x009953c8u); f_009946b0(c); /* call 0x9946b0 */
    W32((uint32_t)(c->esp + 0x228u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x228], eax */
L_009953cf:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ebx, dword ptr [esp + 0x10] */
L_009953d3:;
    c->eax = (uint32_t)((uint32_t)(c->ebx + 0xac4u)); /* lea eax, [ebx + 0xac4] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x18u)); /* lea edx, [esp + 0x18] */
    c->edx = (uint32_t)(sub32(c, c->edx, c->eax)); /* sub edx, eax */
L_009953df:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    W8((uint32_t)(c->edx + c->eax), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [edx + eax], cl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_009953df; /* jne 0x9953df */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x228u))); /* mov edi, dword ptr [esp + 0x228] */
    c->ebp = (uint32_t)(logic32(c, (uint32_t)(c->ebp | (uint32_t)0xffffffffu))); /* or ebp, 0xffffffff */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    while (c->ecx) { (void)sub8(c, ((uint8_t)c->eax), R8(c->edi)); c->edi += (c->df ? -1 : 1); c->ecx--; if (c->zf) break; } /* repne scasb al, byte ptr es:[edi] */
    c->ecx = (uint32_t)((uint32_t)~c->ecx); /* not ecx */
    c->edi = (uint32_t)(sub32(c, c->edi, c->ecx)); /* sub edi, ecx */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x18u)); /* lea edx, [esp + 0x18] */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->esi = (uint32_t)(c->edi); /* mov esi, edi */
    c->edi = (uint32_t)(c->edx); /* mov edi, edx */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    while (c->ecx) { (void)sub8(c, ((uint8_t)c->eax), R8(c->edi)); c->edi += (c->df ? -1 : 1); c->ecx--; if (c->zf) break; } /* repne scasb al, byte ptr es:[edi] */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u))); /* and ecx, 3 */
    while (c->ecx) { W8(c->edi, R8(c->esi)); c->esi += (c->df ? -1 : 1); c->edi += (c->df ? -1 : 1); c->ecx--; } /* rep movsb byte ptr es:[edi], byte ptr [esi] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x244u))); /* mov edi, dword ptr [esp + 0x244] */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00995481; /* je 0x995481 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x24cu))); /* fld dword ptr [esp + 0x24c] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x9b5124u))); FPOP(c); /* fcomp dword ptr [0x10025124] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x44u)); /* test ah, 0x44 */
    if (!PF(c)) goto L_00995481; /* jnp 0x995481 */
    FPUSH(c, (double)RF32((uint32_t)(c->ebx + 0xab4u))); /* fld dword ptr [ebx + 0xab4] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->edi))); /* fsub dword ptr [edi] */
    FPUSH(c, (double)RF32((uint32_t)(c->ebx + 0xab8u))); /* fld dword ptr [ebx + 0xab8] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->edi + 0x4u))); /* fsub dword ptr [edi + 4] */
    ST(0) = fabs(ST(0)); /* fabs  */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    FPUSH(c, (double)RF32((uint32_t)(c->ebx + 0xabcu))); /* fld dword ptr [ebx + 0xabc] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->edi + 0x8u))); /* fsub dword ptr [edi + 8] */
    ST(0) = fabs(ST(0)); /* fabs  */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
    ST(0) = fabs(ST(0)); /* fabs  */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x10u))); /* fadd dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x14u))); /* fadd dword ptr [esp + 0x14] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->esp + 0x24cu))); FPOP(c); /* fcomp dword ptr [esp + 0x24c] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (c->zf) goto L_0099566f; /* je 0x99566f */
L_00995481:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x22cu))); /* mov eax, dword ptr [esp + 0x22c] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if ((!c->cf && !c->zf)) goto L_0099566f; /* ja 0x99566f */
    { uint32_t t_ = R32((uint32_t)(c->eax * 4 + 0x99568cu)); switch (t_) { case 0x00995499u: goto L_00995499; case 0x009954f1u: goto L_009954f1; case 0x00995549u: goto L_00995549; case 0x00995597u: goto L_00995597; default: jump_indirect(c, t_, 0x00995492u); return; } } /* jmp dword ptr [eax*4 + 0x1000568c] */
L_00995499:;
    { uint32_t v_ = 0x320u; PUSH32(c, v_); } /* push 0x320 */
    { uint32_t v_ = 0x9b730cu; PUSH32(c, v_); } /* push 0x1002730c */
    { uint32_t v_ = 0x74u; PUSH32(c, v_); } /* push 0x74 */
    PUSH32(c, 0x009954aau); f_00993c30(c); /* call 0x993c30 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esp + 0x220u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x220], 0 */
    if (c->zf) goto L_009955e5; /* je 0x9955e5 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x230u))); /* mov ecx, dword ptr [esp + 0x230] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x23cu))); /* mov edx, dword ptr [esp + 0x23c] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x240u))); /* mov ecx, dword ptr [esp + 0x240] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0xa40u))); /* mov edx, dword ptr [ebx + 0xa40] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    PUSH32(c, 0x009954ecu); f_00992e40(c); /* call 0x992e40 */
    goto L_009955e7; /* jmp 0x9955e7 */
L_009954f1:;
    { uint32_t v_ = 0x323u; PUSH32(c, v_); } /* push 0x323 */
    { uint32_t v_ = 0x9b730cu; PUSH32(c, v_); } /* push 0x1002730c */
    { uint32_t v_ = 0x70u; PUSH32(c, v_); } /* push 0x70 */
    PUSH32(c, 0x00995502u); f_00993c30(c); /* call 0x993c30 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esp + 0x220u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [esp + 0x220], 1 */
    if (c->zf) goto L_009955e5; /* je 0x9955e5 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x230u))); /* mov ecx, dword ptr [esp + 0x230] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x23cu))); /* mov edx, dword ptr [esp + 0x23c] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x240u))); /* mov ecx, dword ptr [esp + 0x240] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0xa40u))); /* mov edx, dword ptr [ebx + 0xa40] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    PUSH32(c, 0x00995544u); f_00993580(c); /* call 0x993580 */
    goto L_009955e7; /* jmp 0x9955e7 */
L_00995549:;
    { uint32_t v_ = 0x326u; PUSH32(c, v_); } /* push 0x326 */
    { uint32_t v_ = 0x9b730cu; PUSH32(c, v_); } /* push 0x1002730c */
    { uint32_t v_ = 0x388u; PUSH32(c, v_); } /* push 0x388 */
    PUSH32(c, 0x0099555du); f_00993c30(c); /* call 0x993c30 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esp + 0x220u), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [esp + 0x220], 2 */
    if (c->zf) goto L_009955e5; /* je 0x9955e5 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x230u))); /* mov ecx, dword ptr [esp + 0x230] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x238u))); /* mov edx, dword ptr [esp + 0x238] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0xa40u))); /* mov ecx, dword ptr [ebx + 0xa40] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    PUSH32(c, 0x00995595u); f_00992a20(c); /* call 0x992a20 */
    goto L_009955e7; /* jmp 0x9955e7 */
L_00995597:;
    { uint32_t v_ = 0x329u; PUSH32(c, v_); } /* push 0x329 */
    { uint32_t v_ = 0x9b730cu; PUSH32(c, v_); } /* push 0x1002730c */
    { uint32_t v_ = 0x388u; PUSH32(c, v_); } /* push 0x388 */
    PUSH32(c, 0x009955abu); f_00993c30(c); /* call 0x993c30 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esp + 0x220u), (uint32_t)((uint32_t)0x3u)); /* mov dword ptr [esp + 0x220], 3 */
    if (c->zf) goto L_009955e5; /* je 0x9955e5 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x230u))); /* mov edx, dword ptr [esp + 0x230] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x238u))); /* mov ecx, dword ptr [esp + 0x238] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0xa40u))); /* mov edx, dword ptr [ebx + 0xa40] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    PUSH32(c, 0x009955e3u); f_009925c0(c); /* call 0x9925c0 */
    goto L_009955e7; /* jmp 0x9955e7 */
L_009955e5:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_009955e7:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x254u))); /* mov ecx, dword ptr [esp + 0x254] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x250u))); /* mov edx, dword ptr [esp + 0x250] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x250u))); /* mov ecx, dword ptr [esp + 0x250] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x250u))); /* mov edx, dword ptr [esp + 0x250] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x24cu))); /* mov ecx, dword ptr [esp + 0x24c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x244u))); /* mov edx, dword ptr [esp + 0x244] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x30u)); /* lea ecx, [esp + 0x30] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    W32((uint32_t)(c->esp + 0x240u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0x240], ebp */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4u)); PUSH32(c, 0x0099562du); call_indirect(c, t_); } /* call dword ptr [eax + 4] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00995667; /* je 0x995667 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0xaa4u))); /* mov edx, dword ptr [ebx + 0xaa4] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov eax, dword ptr [edx + 8] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0x0u); /* cmp dword ptr [eax], 0 */
    if (c->zf) goto L_00995654; /* je 0x995654 */
    c->edi = (uint32_t)(R32((uint32_t)(c->edx))); /* mov edi, dword ptr [edx] */
L_00995643:;
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    if (c->zf) goto L_0099566f; /* je 0x99566f */
    c->ebx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ebx, dword ptr [eax + 4] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x4u)); /* add eax, 4 */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (!c->zf) goto L_00995643; /* jne 0x995643 */
L_00995654:;
    W32((uint32_t)(c->eax), (uint32_t)(c->esi)); /* mov dword ptr [eax], esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov esi, dword ptr [edx + 4] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0x80000000u))); /* or ecx, 0x80000000 */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [edx + 4], esi */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    goto L_00995671; /* jmp 0x995671 */
L_00995667:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx)); PUSH32(c, 0x0099566fu); call_indirect(c, t_); } /* call dword ptr [edx] */
L_0099566f:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00995671:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x218u))); /* mov ecx, dword ptr [esp + 0x218] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x214u)); /* add esp, 0x214 */
    c->esp += 52; return; /* ret 0x30 */
}

void f_00995499(CPU *c) { /* PTR_00995499 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x320u; PUSH32(c, v_); } /* push 0x320 */
    { uint32_t v_ = 0x9b730cu; PUSH32(c, v_); } /* push 0x1002730c */
    { uint32_t v_ = 0x74u; PUSH32(c, v_); } /* push 0x74 */
    PUSH32(c, 0x009954aau); f_00993c30(c); /* call 0x993c30 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esp + 0x220u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x220], 0 */
    if (c->zf) goto L_009955e5; /* je 0x9955e5 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x230u))); /* mov ecx, dword ptr [esp + 0x230] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x23cu))); /* mov edx, dword ptr [esp + 0x23c] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x240u))); /* mov ecx, dword ptr [esp + 0x240] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0xa40u))); /* mov edx, dword ptr [ebx + 0xa40] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    PUSH32(c, 0x009954ecu); f_00992e40(c); /* call 0x992e40 */
    goto L_009955e7; /* jmp 0x9955e7 */
L_009955e5:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_009955e7:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x254u))); /* mov ecx, dword ptr [esp + 0x254] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x250u))); /* mov edx, dword ptr [esp + 0x250] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x250u))); /* mov ecx, dword ptr [esp + 0x250] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x250u))); /* mov edx, dword ptr [esp + 0x250] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x24cu))); /* mov ecx, dword ptr [esp + 0x24c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x244u))); /* mov edx, dword ptr [esp + 0x244] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x30u)); /* lea ecx, [esp + 0x30] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    W32((uint32_t)(c->esp + 0x240u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0x240], ebp */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4u)); PUSH32(c, 0x0099562du); call_indirect(c, t_); } /* call dword ptr [eax + 4] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00995667; /* je 0x995667 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0xaa4u))); /* mov edx, dword ptr [ebx + 0xaa4] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov eax, dword ptr [edx + 8] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0x0u); /* cmp dword ptr [eax], 0 */
    if (c->zf) goto L_00995654; /* je 0x995654 */
    c->edi = (uint32_t)(R32((uint32_t)(c->edx))); /* mov edi, dword ptr [edx] */
L_00995643:;
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    if (c->zf) goto L_0099566f; /* je 0x99566f */
    c->ebx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ebx, dword ptr [eax + 4] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x4u)); /* add eax, 4 */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (!c->zf) goto L_00995643; /* jne 0x995643 */
L_00995654:;
    W32((uint32_t)(c->eax), (uint32_t)(c->esi)); /* mov dword ptr [eax], esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov esi, dword ptr [edx + 4] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0x80000000u))); /* or ecx, 0x80000000 */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [edx + 4], esi */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    goto L_00995671; /* jmp 0x995671 */
L_00995667:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx)); PUSH32(c, 0x0099566fu); call_indirect(c, t_); } /* call dword ptr [edx] */
L_0099566f:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00995671:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x218u))); /* mov ecx, dword ptr [esp + 0x218] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x214u)); /* add esp, 0x214 */
    c->esp += 52; return; /* ret 0x30 */
}

void f_009954f1(CPU *c) { /* PTR_009954f1 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x323u; PUSH32(c, v_); } /* push 0x323 */
    { uint32_t v_ = 0x9b730cu; PUSH32(c, v_); } /* push 0x1002730c */
    { uint32_t v_ = 0x70u; PUSH32(c, v_); } /* push 0x70 */
    PUSH32(c, 0x00995502u); f_00993c30(c); /* call 0x993c30 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esp + 0x220u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [esp + 0x220], 1 */
    if (c->zf) goto L_009955e5; /* je 0x9955e5 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x230u))); /* mov ecx, dword ptr [esp + 0x230] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x23cu))); /* mov edx, dword ptr [esp + 0x23c] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x240u))); /* mov ecx, dword ptr [esp + 0x240] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0xa40u))); /* mov edx, dword ptr [ebx + 0xa40] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    PUSH32(c, 0x00995544u); f_00993580(c); /* call 0x993580 */
    goto L_009955e7; /* jmp 0x9955e7 */
L_009955e5:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_009955e7:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x254u))); /* mov ecx, dword ptr [esp + 0x254] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x250u))); /* mov edx, dword ptr [esp + 0x250] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x250u))); /* mov ecx, dword ptr [esp + 0x250] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x250u))); /* mov edx, dword ptr [esp + 0x250] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x24cu))); /* mov ecx, dword ptr [esp + 0x24c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x244u))); /* mov edx, dword ptr [esp + 0x244] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x30u)); /* lea ecx, [esp + 0x30] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    W32((uint32_t)(c->esp + 0x240u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0x240], ebp */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4u)); PUSH32(c, 0x0099562du); call_indirect(c, t_); } /* call dword ptr [eax + 4] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00995667; /* je 0x995667 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0xaa4u))); /* mov edx, dword ptr [ebx + 0xaa4] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov eax, dword ptr [edx + 8] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0x0u); /* cmp dword ptr [eax], 0 */
    if (c->zf) goto L_00995654; /* je 0x995654 */
    c->edi = (uint32_t)(R32((uint32_t)(c->edx))); /* mov edi, dword ptr [edx] */
L_00995643:;
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    if (c->zf) goto L_0099566f; /* je 0x99566f */
    c->ebx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ebx, dword ptr [eax + 4] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x4u)); /* add eax, 4 */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (!c->zf) goto L_00995643; /* jne 0x995643 */
L_00995654:;
    W32((uint32_t)(c->eax), (uint32_t)(c->esi)); /* mov dword ptr [eax], esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov esi, dword ptr [edx + 4] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0x80000000u))); /* or ecx, 0x80000000 */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [edx + 4], esi */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    goto L_00995671; /* jmp 0x995671 */
L_00995667:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx)); PUSH32(c, 0x0099566fu); call_indirect(c, t_); } /* call dword ptr [edx] */
L_0099566f:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00995671:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x218u))); /* mov ecx, dword ptr [esp + 0x218] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x214u)); /* add esp, 0x214 */
    c->esp += 52; return; /* ret 0x30 */
}

void f_00995549(CPU *c) { /* PTR_00995549 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x326u; PUSH32(c, v_); } /* push 0x326 */
    { uint32_t v_ = 0x9b730cu; PUSH32(c, v_); } /* push 0x1002730c */
    { uint32_t v_ = 0x388u; PUSH32(c, v_); } /* push 0x388 */
    PUSH32(c, 0x0099555du); f_00993c30(c); /* call 0x993c30 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esp + 0x220u), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [esp + 0x220], 2 */
    if (c->zf) goto L_009955e5; /* je 0x9955e5 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x230u))); /* mov ecx, dword ptr [esp + 0x230] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x238u))); /* mov edx, dword ptr [esp + 0x238] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0xa40u))); /* mov ecx, dword ptr [ebx + 0xa40] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    PUSH32(c, 0x00995595u); f_00992a20(c); /* call 0x992a20 */
    goto L_009955e7; /* jmp 0x9955e7 */
L_009955e5:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_009955e7:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x254u))); /* mov ecx, dword ptr [esp + 0x254] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x250u))); /* mov edx, dword ptr [esp + 0x250] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x250u))); /* mov ecx, dword ptr [esp + 0x250] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x250u))); /* mov edx, dword ptr [esp + 0x250] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x24cu))); /* mov ecx, dword ptr [esp + 0x24c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x244u))); /* mov edx, dword ptr [esp + 0x244] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x30u)); /* lea ecx, [esp + 0x30] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    W32((uint32_t)(c->esp + 0x240u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0x240], ebp */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4u)); PUSH32(c, 0x0099562du); call_indirect(c, t_); } /* call dword ptr [eax + 4] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00995667; /* je 0x995667 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0xaa4u))); /* mov edx, dword ptr [ebx + 0xaa4] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov eax, dword ptr [edx + 8] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0x0u); /* cmp dword ptr [eax], 0 */
    if (c->zf) goto L_00995654; /* je 0x995654 */
    c->edi = (uint32_t)(R32((uint32_t)(c->edx))); /* mov edi, dword ptr [edx] */
L_00995643:;
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    if (c->zf) goto L_0099566f; /* je 0x99566f */
    c->ebx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ebx, dword ptr [eax + 4] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x4u)); /* add eax, 4 */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (!c->zf) goto L_00995643; /* jne 0x995643 */
L_00995654:;
    W32((uint32_t)(c->eax), (uint32_t)(c->esi)); /* mov dword ptr [eax], esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov esi, dword ptr [edx + 4] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0x80000000u))); /* or ecx, 0x80000000 */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [edx + 4], esi */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    goto L_00995671; /* jmp 0x995671 */
L_00995667:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx)); PUSH32(c, 0x0099566fu); call_indirect(c, t_); } /* call dword ptr [edx] */
L_0099566f:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00995671:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x218u))); /* mov ecx, dword ptr [esp + 0x218] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x214u)); /* add esp, 0x214 */
    c->esp += 52; return; /* ret 0x30 */
}

void f_00995597(CPU *c) { /* PTR_00995597 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x329u; PUSH32(c, v_); } /* push 0x329 */
    { uint32_t v_ = 0x9b730cu; PUSH32(c, v_); } /* push 0x1002730c */
    { uint32_t v_ = 0x388u; PUSH32(c, v_); } /* push 0x388 */
    PUSH32(c, 0x009955abu); f_00993c30(c); /* call 0x993c30 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esp + 0x220u), (uint32_t)((uint32_t)0x3u)); /* mov dword ptr [esp + 0x220], 3 */
    if (c->zf) goto L_009955e5; /* je 0x9955e5 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x230u))); /* mov edx, dword ptr [esp + 0x230] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x238u))); /* mov ecx, dword ptr [esp + 0x238] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0xa40u))); /* mov edx, dword ptr [ebx + 0xa40] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    PUSH32(c, 0x009955e3u); f_009925c0(c); /* call 0x9925c0 */
    goto L_009955e7; /* jmp 0x9955e7 */
L_009955e5:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_009955e7:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x254u))); /* mov ecx, dword ptr [esp + 0x254] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x250u))); /* mov edx, dword ptr [esp + 0x250] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x250u))); /* mov ecx, dword ptr [esp + 0x250] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x250u))); /* mov edx, dword ptr [esp + 0x250] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x24cu))); /* mov ecx, dword ptr [esp + 0x24c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x244u))); /* mov edx, dword ptr [esp + 0x244] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x30u)); /* lea ecx, [esp + 0x30] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    W32((uint32_t)(c->esp + 0x240u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0x240], ebp */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4u)); PUSH32(c, 0x0099562du); call_indirect(c, t_); } /* call dword ptr [eax + 4] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00995667; /* je 0x995667 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0xaa4u))); /* mov edx, dword ptr [ebx + 0xaa4] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov eax, dword ptr [edx + 8] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0x0u); /* cmp dword ptr [eax], 0 */
    if (c->zf) goto L_00995654; /* je 0x995654 */
    c->edi = (uint32_t)(R32((uint32_t)(c->edx))); /* mov edi, dword ptr [edx] */
L_00995643:;
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    if (c->zf) goto L_0099566f; /* je 0x99566f */
    c->ebx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ebx, dword ptr [eax + 4] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x4u)); /* add eax, 4 */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (!c->zf) goto L_00995643; /* jne 0x995643 */
L_00995654:;
    W32((uint32_t)(c->eax), (uint32_t)(c->esi)); /* mov dword ptr [eax], esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov esi, dword ptr [edx + 4] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0x80000000u))); /* or ecx, 0x80000000 */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [edx + 4], esi */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    goto L_00995671; /* jmp 0x995671 */
L_00995667:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx)); PUSH32(c, 0x0099566fu); call_indirect(c, t_); } /* call dword ptr [edx] */
L_0099566f:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00995671:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x218u))); /* mov ecx, dword ptr [esp + 0x218] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x214u)); /* add esp, 0x214 */
    c->esp += 52; return; /* ret 0x30 */
}

void f_009956a0(CPU *c) { /* PTR_009956a0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi + 0xab0u))); /* mov al, byte ptr [edi + 0xab0] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00995711; /* je 0x995711 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009956df; /* je 0x9956df */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0xaa4u))); /* mov ecx, dword ptr [edi + 0xaa4] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fffffffu))); /* and eax, 0x7fffffff */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov edx, dword ptr [ecx + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + c->eax * 4))); /* mov eax, dword ptr [edx + eax*4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00995711; /* je 0x995711 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x20u)); PUSH32(c, 0x009956dbu); call_indirect(c, t_); } /* call dword ptr [edx + 0x20] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 16; return; /* ret 0xc */
L_009956df:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ebx, dword ptr [esp + 0x14] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ebp, dword ptr [esp + 0x14] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_009956ec:;
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + 0xaa4u))); /* mov edx, dword ptr [edi + 0xaa4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov eax, dword ptr [edx + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + c->eax))); /* mov ecx, dword ptr [esi + eax] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00995703; /* je 0x995703 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x20u)); PUSH32(c, 0x00995703u); call_indirect(c, t_); } /* call dword ptr [edx + 0x20] */
L_00995703:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, c->esi, (uint32_t)0x258u); /* cmp esi, 0x258 */
    if ((c->sf != c->of)) goto L_009956ec; /* jl 0x9956ec */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
L_00995711:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 16; return; /* ret 0xc */
}

void f_00995720(CPU *c) { /* PTR_00995720 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi + 0xab0u))); /* mov al, byte ptr [edi + 0xab0] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00995785; /* je 0x995785 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0099575a; /* je 0x99575a */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0xaa4u))); /* mov ecx, dword ptr [edi + 0xaa4] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fffffffu))); /* and eax, 0x7fffffff */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov edx, dword ptr [ecx + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + c->eax * 4))); /* mov eax, dword ptr [edx + eax*4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00995785; /* je 0x995785 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x00995756u); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 12; return; /* ret 8 */
L_0099575a:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ebx, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_00995762:;
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + 0xaa4u))); /* mov edx, dword ptr [edi + 0xaa4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov eax, dword ptr [edx + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + c->eax))); /* mov ecx, dword ptr [esi + eax] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00995778; /* je 0x995778 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x00995778u); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
L_00995778:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, c->esi, (uint32_t)0x258u); /* cmp esi, 0x258 */
    if ((c->sf != c->of)) goto L_00995762; /* jl 0x995762 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
L_00995785:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 12; return; /* ret 8 */
}

void f_00995790(CPU *c) { /* PTR_00995790 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi + 0xab0u))); /* mov al, byte ptr [edi + 0xab0] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_009957e9; /* je 0x9957e9 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009957c5; /* je 0x9957c5 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0xaa4u))); /* mov ecx, dword ptr [edi + 0xaa4] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fffffffu))); /* and eax, 0x7fffffff */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov edx, dword ptr [ecx + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + c->eax * 4))); /* mov eax, dword ptr [edx + eax*4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009957e9; /* je 0x9957e9 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x28u)); PUSH32(c, 0x009957c1u); call_indirect(c, t_); } /* call dword ptr [edx + 0x28] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 8; return; /* ret 4 */
L_009957c5:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_009957c8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0xaa4u))); /* mov eax, dword ptr [edi + 0xaa4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ecx, dword ptr [eax + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + c->ecx))); /* mov ecx, dword ptr [esi + ecx] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_009957dd; /* je 0x9957dd */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x28u)); PUSH32(c, 0x009957ddu); call_indirect(c, t_); } /* call dword ptr [edx + 0x28] */
L_009957dd:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, c->esi, (uint32_t)0x258u); /* cmp esi, 0x258 */
    if ((c->sf != c->of)) goto L_009957c8; /* jl 0x9957c8 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_009957e9:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 8; return; /* ret 4 */
}

void f_009957f0(CPU *c) { /* FUN_100057f0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebx + 0xab0u))); /* mov al, byte ptr [ebx + 0xab0] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_0099589a; /* je 0x99589a */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00995851; /* je 0x995851 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fffffffu))); /* and eax, 0x7fffffff */
    c->eax = (uint32_t)(shl32(c, c->eax, 2)); /* shl eax, 2 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xaa4u))); /* mov eax, dword ptr [ebx + 0xaa4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ecx, dword ptr [eax + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->edi + c->ecx))); /* mov esi, dword ptr [edi + ecx] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_0099589a; /* je 0x99589a */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x0099582cu); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax)); PUSH32(c, 0x00995834u); call_indirect(c, t_); } /* call dword ptr [eax] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebx + 0xaa4u))); /* mov ebx, dword ptr [ebx + 0xaa4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov ecx, dword ptr [ebx + 8] */
    W32((uint32_t)(c->edi + c->ecx), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [edi + ecx], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov eax, dword ptr [ebx + 4] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 4], eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
L_00995851:;
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
L_00995853:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0xaa4u))); /* mov edx, dword ptr [ebx + 0xaa4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov eax, dword ptr [edx + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + c->edi * 4))); /* mov esi, dword ptr [eax + edi*4] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00995891; /* je 0x995891 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x0099586au); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax)); PUSH32(c, 0x00995872u); call_indirect(c, t_); } /* call dword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xaa4u))); /* mov eax, dword ptr [ebx + 0xaa4] */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x7fffffffu))); /* and ecx, 0x7fffffff */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov edx, dword ptr [eax + 8] */
    W32((uint32_t)(c->edx + c->ecx * 4), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [edx + ecx*4], 0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 4], ecx */
L_00995891:;
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->edi, (uint32_t)0x96u); /* cmp edi, 0x96 */
    if ((c->sf != c->of)) goto L_00995853; /* jl 0x995853 */
L_0099589a:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
}

void f_009958a0(CPU *c) { /* PTR_009958a0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi + 0xab0u))); /* mov al, byte ptr [edi + 0xab0] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00995905; /* je 0x995905 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009958da; /* je 0x9958da */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0xaa4u))); /* mov ecx, dword ptr [edi + 0xaa4] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fffffffu))); /* and eax, 0x7fffffff */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov edx, dword ptr [ecx + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + c->eax * 4))); /* mov eax, dword ptr [edx + eax*4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00995905; /* je 0x995905 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x1cu)); PUSH32(c, 0x009958d6u); call_indirect(c, t_); } /* call dword ptr [edx + 0x1c] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 12; return; /* ret 8 */
L_009958da:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ebx, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_009958e2:;
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + 0xaa4u))); /* mov edx, dword ptr [edi + 0xaa4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov eax, dword ptr [edx + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + c->eax))); /* mov ecx, dword ptr [esi + eax] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_009958f8; /* je 0x9958f8 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x1cu)); PUSH32(c, 0x009958f8u); call_indirect(c, t_); } /* call dword ptr [edx + 0x1c] */
L_009958f8:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, c->esi, (uint32_t)0x258u); /* cmp esi, 0x258 */
    if ((c->sf != c->of)) goto L_009958e2; /* jl 0x9958e2 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
L_00995905:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 12; return; /* ret 8 */
}

void f_00995910(CPU *c) { /* PTR_00995910 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0xab0u))); /* mov al, byte ptr [ecx + 0xab0] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00995941; /* je 0x995941 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00995941; /* je 0x995941 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0xaa4u))); /* mov ecx, dword ptr [ecx + 0xaa4] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fffffffu))); /* and eax, 0x7fffffff */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov edx, dword ptr [ecx + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + c->eax * 4))); /* mov eax, dword ptr [edx + eax*4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00995941; /* je 0x995941 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x0099593eu); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->esp += 8; return; /* ret 4 */
L_00995941:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    c->esp += 8; return; /* ret 4 */
}

void f_00995950(CPU *c) { /* PTR_00995950 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi + 0xab0u))); /* mov al, byte ptr [edi + 0xab0] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_009959b5; /* je 0x9959b5 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0099598a; /* je 0x99598a */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0xaa4u))); /* mov ecx, dword ptr [edi + 0xaa4] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fffffffu))); /* and eax, 0x7fffffff */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov edx, dword ptr [ecx + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + c->eax * 4))); /* mov eax, dword ptr [edx + eax*4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009959b5; /* je 0x9959b5 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x30u)); PUSH32(c, 0x00995986u); call_indirect(c, t_); } /* call dword ptr [edx + 0x30] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 12; return; /* ret 8 */
L_0099598a:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ebx, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_00995992:;
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + 0xaa4u))); /* mov edx, dword ptr [edi + 0xaa4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov eax, dword ptr [edx + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + c->eax))); /* mov ecx, dword ptr [esi + eax] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_009959a8; /* je 0x9959a8 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x30u)); PUSH32(c, 0x009959a8u); call_indirect(c, t_); } /* call dword ptr [edx + 0x30] */
L_009959a8:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, c->esi, (uint32_t)0x258u); /* cmp esi, 0x258 */
    if ((c->sf != c->of)) goto L_00995992; /* jl 0x995992 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
L_009959b5:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 12; return; /* ret 8 */
}

void f_009959c0(CPU *c) { /* PTR_009959c0 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0xab0u))); /* mov al, byte ptr [ecx + 0xab0] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_009959f1; /* je 0x9959f1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009959f1; /* je 0x9959f1 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0xaa4u))); /* mov ecx, dword ptr [ecx + 0xaa4] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fffffffu))); /* and eax, 0x7fffffff */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov edx, dword ptr [ecx + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + c->eax * 4))); /* mov eax, dword ptr [edx + eax*4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009959f1; /* je 0x9959f1 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x18u)); PUSH32(c, 0x009959eeu); call_indirect(c, t_); } /* call dword ptr [edx + 0x18] */
    c->esp += 8; return; /* ret 4 */
L_009959f1:;
    FPUSH(c, (double)RF32((uint32_t)(0x9b5124u))); /* fld dword ptr [0x10025124] */
    c->esp += 8; return; /* ret 4 */
}

void f_00995a00(CPU *c) { /* PTR_00995a00 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0xab0u))); /* mov al, byte ptr [ecx + 0xab0] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00995a43; /* je 0x995a43 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edx = (uint32_t)((uint32_t)(c->ecx + 0xab4u)); /* lea edx, [ecx + 0xab4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x77a0u))); /* mov ecx, dword ptr [ecx + 0x77a0] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edi, dword ptr [esi] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    W32((uint32_t)(c->edx), (uint32_t)(c->edi)); /* mov dword ptr [edx], edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov edi, dword ptr [esi + 4] */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->edi)); /* mov dword ptr [edx + 4], edi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov esi, dword ptr [esi + 8] */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [edx + 8], esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov esi, dword ptr [eax + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov esi, dword ptr [eax + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x38u)); PUSH32(c, 0x00995a41u); call_indirect(c, t_); } /* call dword ptr [edx + 0x38] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00995a43:;
    c->esp += 8; return; /* ret 4 */
}

void f_00995a50(CPU *c) { /* PTR_00995a50 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0xab0u))); /* mov al, byte ptr [ecx + 0xab0] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00995a88; /* je 0x995a88 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x77a0u))); /* mov eax, dword ptr [ecx + 0x77a0] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov esi, dword ptr [ecx + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov esi, dword ptr [ecx + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov ecx, dword ptr [ecx] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov ecx, dword ptr [esp + 0x18] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov esi, dword ptr [ecx + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov esi, dword ptr [ecx + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov ecx, dword ptr [ecx] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x34u)); PUSH32(c, 0x00995a87u); call_indirect(c, t_); } /* call dword ptr [edx + 0x34] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00995a88:;
    c->esp += 12; return; /* ret 8 */
}

void f_00995a90(CPU *c) { /* PTR_00995a90 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi + 0xab0u))); /* mov al, byte ptr [edi + 0xab0] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00995adb; /* je 0x995adb */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00995ab2u); f_009962a0(c); /* call 0x9962a0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_00995ab7:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0xaa4u))); /* mov eax, dword ptr [edi + 0xaa4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ecx, dword ptr [eax + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx))); /* mov eax, dword ptr [esi + ecx] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00995acf; /* je 0x995acf */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x4u)); /* lea ecx, [eax + 4] */
    PUSH32(c, 0x00995acfu); f_00995f10(c); /* call 0x995f10 */
L_00995acf:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, c->esi, (uint32_t)0x258u); /* cmp esi, 0x258 */
    if ((c->sf != c->of)) goto L_00995ab7; /* jl 0x995ab7 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00995adb:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 16; return; /* ret 0xc */
}

void f_00995ae0(CPU *c) { /* PTR_00995ae0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00995af4u); f_009963d0(c); /* call 0x9963d0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 16; return; /* ret 0xc */
}

void f_00995b00(CPU *c) { /* FUN_10005b00 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0xab0u))); /* mov al, byte ptr [esi + 0xab0] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00995b13; /* jne 0x995b13 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
L_00995b13:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0xaa4u))); /* mov ecx, dword ptr [esi + 0xaa4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fffffffu))); /* and eax, 0x7fffffff */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov edx, dword ptr [ecx + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + c->eax * 4))); /* mov ecx, dword ptr [edx + eax*4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (!c->zf) goto L_00995b32; /* jne 0x995b32 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
L_00995b32:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x2cu)); PUSH32(c, 0x00995b39u); call_indirect(c, t_); } /* call dword ptr [eax + 0x2c] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0xaa4u))); /* mov esi, dword ptr [esi + 0xaa4] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ecx, dword ptr [esi + 8] */
    (void)sub32(c, R32((uint32_t)(c->ecx)), (uint32_t)0x0u); /* cmp dword ptr [ecx], 0 */
    if (c->zf) goto L_00995b5c; /* je 0x995b5c */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edi, dword ptr [esi] */
L_00995b4b:;
    c->ebx = (uint32_t)(c->edx); /* mov ebx, edx */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    if (c->zf) goto L_00995b73; /* je 0x995b73 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ebx, dword ptr [ecx + 4] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (!c->zf) goto L_00995b4b; /* jne 0x995b4b */
L_00995b5c:;
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx | (uint32_t)0x80000000u))); /* or edx, 0x80000000 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 4], ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
L_00995b73:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00995b80(CPU *c) { /* FUN_10005b80 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0xab0u))); /* mov al, byte ptr [ecx + 0xab0] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00995ba7; /* je 0x995ba7 */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->ecx + 0x14u))); /* fild dword ptr [ecx + 0x14] */
    FPUSH(c, (double)RF32((uint32_t)(0x9b72f8u))); /* fld dword ptr [0x100272f8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x9b538cu))); /* fmul dword ptr [0x1002538c] */
    FCOM(c, ST(0), ST(1)); FPOP(c); FPOP(c); /* fcompp  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00995ba7; /* jp 0x995ba7 */
    { f_009922e0(c); return; } /* jmp 0x9922e0 */
L_00995ba7:;
    c->esp += 4; return; /* ret  */
}

void f_00995bb0(CPU *c) { /* FUN_10005bb0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi + 0xab0u))); /* mov al, byte ptr [edi + 0xab0] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00995c09; /* je 0x995c09 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00995c09; /* je 0x995c09 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor bl, bl */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_00995bcb:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0xaa4u))); /* mov eax, dword ptr [edi + 0xaa4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ecx, dword ptr [eax + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + c->ecx))); /* mov ecx, dword ptr [esi + ecx] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00995beb; /* je 0x995beb */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x10u)); PUSH32(c, 0x00995be5u); call_indirect(c, t_); } /* call dword ptr [edx + 0x10] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00995beb; /* je 0x995beb */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov bl, 1 */
L_00995beb:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, c->esi, (uint32_t)0x258u); /* cmp esi, 0x258 */
    if ((c->sf != c->of)) goto L_00995bcb; /* jl 0x995bcb */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & ((uint8_t)c->ebx))); /* test bl, bl */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    if (!c->zf) goto L_00995c09; /* jne 0x995c09 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00995c06u); f_00991ec0(c); /* call 0x991ec0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00995c09:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 12; return; /* ret 8 */
}

void f_00995c10(CPU *c) { /* FUN_10005c10 */
    PREEMPT_POLL(c);
    c->esp += 4; return; /* ret  */
}

void f_00995c20(CPU *c) { /* FUN_10005c20 */
    PREEMPT_POLL(c);
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x4u))); /* fild dword ptr [esp + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = 0x14u; PUSH32(c, v_); } /* push 0x14 */
    ST(0) = FPRES(c, ST(0) + ST(0)); /* fadd st(0), st(0) */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 4], eax */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 8], eax */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xc], eax */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x9b5390u)); /* mov dword ptr [esi], 0x10025390 */
    { uint32_t v_ = 0x9b7450u; PUSH32(c, v_); } /* push 0x10027450 */
    PUSH32(c, 0x00995c4au); f_00998340(c); /* call 0x998340 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00995c50u); f_00993c30(c); /* call 0x993c30 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xc], eax */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00995c60(CPU *c) { /* FUN_10005c60 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00995c68u); f_00995c80(c); /* call 0x995c80 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00995c78; /* je 0x995c78 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00995c75u); f_00993c50(c); /* call 0x993c50 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00995c78:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00995c80(CPU *c) { /* FUN_10005c80 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x9b5390u)); /* mov dword ptr [esi], 0x10025390 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00995ca0; /* je 0x995ca0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00995c96u); f_00993c50(c); /* call 0x993c50 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 0xc], 0 */
L_00995ca0:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00995cb0(CPU *c) { /* FUN_10005cb0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ebp, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov ecx, dword ptr [ebx + 8] */
    (void)sub32(c, c->ecx, c->ebp); /* cmp ecx, ebp */
    if ((c->zf || c->sf != c->of)) goto L_00995cc7; /* jle 0x995cc7 */
    W32((uint32_t)(c->eax), (uint32_t)(c->ebp)); /* mov dword ptr [eax], ebp */
    goto L_00995cc9; /* jmp 0x995cc9 */
L_00995cc7:;
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
L_00995cc9:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (!c->zf) goto L_00995cd6; /* jne 0x995cd6 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
L_00995cd6:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebx + 0xcu))); /* mov esi, dword ptr [ebx + 0xc] */
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edi, dword ptr [esp + 0x14] */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u))); /* and ecx, 3 */
    while (c->ecx) { W8(c->edi, R8(c->esi)); c->esi += (c->df ? -1 : 1); c->edi += (c->df ? -1 : 1); c->ecx--; } /* rep movsb byte ptr es:[edi], byte ptr [esi] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov edx, dword ptr [ebx + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0xcu))); /* mov ecx, dword ptr [ebx + 0xc] */
    c->edx = (uint32_t)(sub32(c, c->edx, c->eax)); /* sub edx, eax */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00995d01u); f_009986d0(c); /* call 0x9986d0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov eax, dword ptr [ebx + 8] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ebp)); /* sub eax, ebp */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 8], eax */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
}

void f_00995d20(CPU *c) { /* FUN_10005d20 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ebx, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov ebp, dword ptr [edx + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov ecx, dword ptr [edx + 4] */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 8], ecx */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->ebp)); /* lea eax, [ebx + ebp] */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x14u))); /* fild dword ptr [esp + 0x14] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x8u))); /* fild dword ptr [esp + 8] */
    ST(0) = FPRES(c, ST(0) + ST(0)); /* fadd st(0), st(0) */
    FCOM(c, ST(0), ST(1)); FPOP(c); FPOP(c); /* fcompp  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x41u)); /* test ah, 0x41 */
    if (PF(c)) goto L_00995d55; /* jp 0x995d55 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 12; return; /* ret 8 */
L_00995d55:;
    (void)sub32(c, c->ebx, c->ecx); /* cmp ebx, ecx */
    if ((c->sf != c->of)) goto L_00995d61; /* jl 0x995d61 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 12; return; /* ret 8 */
L_00995d61:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov esi, dword ptr [esp + 0x14] */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->edx + 0xcu))); /* mov edi, dword ptr [edx + 0xc] */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->edi = (uint32_t)(add32(c, c->edi, c->ebp)); /* add edi, ebp */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u))); /* and ecx, 3 */
    while (c->ecx) { W8(c->edi, R8(c->esi)); c->esi += (c->df ? -1 : 1); c->edi += (c->df ? -1 : 1); c->ecx--; } /* rep movsb byte ptr es:[edi], byte ptr [esi] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov eax, dword ptr [edx + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)(add32(c, c->eax, c->ebx)); /* add eax, ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [edx + 8], eax */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 12; return; /* ret 8 */
}

void f_00995d90(CPU *c) { /* FUN_10005d90 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov eax, dword ptr [ecx + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov esi, dword ptr [ecx + 4] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)((c->sf == c->of) ? 1 : 0); /* setge dl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(((uint8_t)c->edx)); /* mov al, dl */
    c->esp += 4; return; /* ret  */
}

void f_00995db0(CPU *c) { /* FUN_10005db0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00995db8u); f_00995d90(c); /* call 0x995d90 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00995dc0; /* je 0x995dc0 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_00995dc0:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov edx, dword ptr [esi + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov edi, dword ptr [esi + 0xc] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->edx)); /* sub ecx, edx */
    c->edi = (uint32_t)(add32(c, c->edi, c->edx)); /* add edi, edx */
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u))); /* and ecx, 3 */
    while (c->ecx) { W8(c->edi, (uint8_t)((uint8_t)c->eax)); c->edi += (c->df ? -1 : 1); c->ecx--; } /* rep stosb byte ptr es:[edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 8], eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00995df0(CPU *c) { /* FUN_10005df0 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 4], ecx */
    W8((uint32_t)(c->eax + 0x1au), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax + 0x1a], cl */
    W8((uint32_t)(c->eax + 0x1bu), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax + 0x1b], cl */
    W32((uint32_t)(c->eax + 0x1cu), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [eax + 0x1c], 0x3f800000 */
    W32((uint32_t)(c->eax + 0x20u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x20], ecx */
    W32((uint32_t)(c->eax + 0x34u), (uint32_t)((uint32_t)0xffff2bcfu)); /* mov dword ptr [eax + 0x34], 0xffff2bcf */
    W32((uint32_t)(c->eax + 0x38u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x38], ecx */
    W32((uint32_t)(c->eax + 0x3cu), (uint32_t)(c->edx)); /* mov dword ptr [eax + 0x3c], edx */
    W8((uint32_t)(c->eax + 0x40u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [eax + 0x40], 1 */
    W8((uint32_t)(c->eax + 0x41u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax + 0x41], cl */
    W32((uint32_t)(c->eax + 0x48u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x48], ecx */
    c->esp += 8; return; /* ret 4 */
}

void f_00995e30(CPU *c) { /* FUN_10005e30 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00995e50; /* je 0x995e50 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x8u)); PUSH32(c, 0x00995e40u); call_indirect(c, t_); } /* call dword ptr [ecx + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x48u))); /* mov edx, dword ptr [esi + 0x48] */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 4], 0 */
    { uint32_t a_ = (uint32_t)(0x9ce2ecu); W32(a_, (uint32_t)(sub32(c, R32(a_), c->edx))); } /* sub dword ptr [0x1003e2ec], edx */
L_00995e50:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00995e60(CPU *c) { /* FUN_10005e60 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov esi, dword ptr [ecx + 4] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (c->zf) goto L_00995f08; /* je 0x995f08 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x10u))); /* mov al, byte ptr [esp + 0x10] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00995eb2; /* jne 0x995eb2 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xcu))); /* fld dword ptr [esp + 0xc] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x9b5398u))); FPOP(c); /* fcomp dword ptr [0x10025398] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00995e90; /* jp 0x995e90 */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)((uint32_t)0x3c23d70au)); /* mov dword ptr [esp + 0xc], 0x3c23d70a */
    goto L_00995eab; /* jmp 0x995eab */
L_00995e90:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xcu))); /* fld dword ptr [esp + 0xc] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x9b5388u))); FPOP(c); /* fcomp dword ptr [0x10025388] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00995eab; /* jne 0x995eab */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [esp + 0xc], 0x3f800000 */
L_00995eab:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    W32((uint32_t)(c->ecx + 0x1cu), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 0x1c], eax */
L_00995eb2:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x3cu))); /* mov ecx, dword ptr [ecx + 0x3c] */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_00995ee0; /* je 0x995ee0 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_00995ed8; /* je 0x995ed8 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_00995ed0; /* je 0x995ed0 */
    c->edx = (uint32_t)(R32((uint32_t)(0x9ce1c4u))); /* mov edx, dword ptr [0x1003e1c4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x3cu)); PUSH32(c, 0x00995ecbu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x3c] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 12; return; /* ret 8 */
L_00995ed0:;
    FPUSH(c, (double)RF32((uint32_t)(0x9b7490u))); /* fld dword ptr [0x10027490] */
    goto L_00995ee6; /* jmp 0x995ee6 */
L_00995ed8:;
    FPUSH(c, (double)RF32((uint32_t)(0x9b748cu))); /* fld dword ptr [0x1002748c] */
    goto L_00995ee6; /* jmp 0x995ee6 */
L_00995ee0:;
    FPUSH(c, (double)RF32((uint32_t)(0x9b7488u))); /* fld dword ptr [0x10027488] */
L_00995ee6:;
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xcu))); /* fmul dword ptr [esp + 0xc] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edi, dword ptr [esi] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x9b5394u))); /* fmul dword ptr [0x10025394] */
    PUSH32(c, 0x00995ef7u); f_00998340(c); /* call 0x998340 */
    c->ecx = (uint32_t)((uint32_t)0x9ce038u); /* mov ecx, 0x1003e038 */
    c->eax = (uint32_t)(shl32(c, c->eax, 2)); /* shl eax, 2 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->edi + 0x3cu)); PUSH32(c, 0x00995f08u); call_indirect(c, t_); } /* call dword ptr [edi + 0x3c] */
L_00995f08:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 12; return; /* ret 8 */
}

void f_00995f10(CPU *c) { /* FUN_10005f10 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x1cu))); /* mov eax, dword ptr [ecx + 0x1c] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00995f1bu); f_00995e60(c); /* call 0x995e60 */
    c->esp += 4; return; /* ret  */
}

void f_00995f20(CPU *c) { /* FUN_10005f20 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xcu)); /* add eax, 0xc */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00995f35u); f_00995f40(c); /* call 0x995f40 */
    c->esp += 12; return; /* ret 8 */
}

void f_00995f40(CPU *c) { /* FUN_10005f40 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x38u)); /* sub esp, 0x38 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(logic32(c, 0)); /* xor ebp, ebp */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    (void)sub32(c, c->eax, c->ebp); /* cmp eax, ebp */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00995f71; /* jne 0x995f71 */
    c->eax = (uint32_t)(R32((uint32_t)(0x9cdfb0u))); /* mov eax, dword ptr [0x1003dfb0] */
    { uint32_t v_ = 0x9b74e8u; PUSH32(c, v_); } /* push 0x100274e8 */
    { uint32_t v_ = 0x62u; PUSH32(c, v_); } /* push 0x62 */
    { uint32_t v_ = 0x9b74b4u; PUSH32(c, v_); } /* push 0x100274b4 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x9b70a0u; PUSH32(c, v_); } /* push 0x100270a0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00995f6du); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00995f70u, "int3"); /* int3  */
L_00995f71:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x54u))); /* mov edx, dword ptr [esp + 0x54] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x58u))); /* mov esi, dword ptr [esp + 0x58] */
    (void)sub32(c, c->esi, c->ebp); /* cmp esi, ebp */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx))); /* mov eax, dword ptr [edx] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov ecx, dword ptr [edx + 4] */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x14], ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov eax, dword ptr [edx + 8] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x18], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x50u))); /* mov eax, dword ptr [esp + 0x50] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0xcu))); /* mov ecx, dword ptr [edx + 0xc] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x1c], ecx */
    c->edx = (c->edx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->edx + 0x10u))); /* mov dx, word ptr [edx + 0x10] */
    W16((uint32_t)(c->esp + 0x20u), (uint16_t)(((uint16_t)c->edx))); /* mov word ptr [esp + 0x20], dx */
    if (c->zf) goto L_00995fae; /* je 0x995fae */
    (void)sub32(c, c->eax, c->ebp); /* cmp eax, ebp */
    if (!c->zf) goto L_00995fae; /* jne 0x995fae */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov edi, dword ptr [esi + 8] */
L_00995fae:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4cu))); /* mov ecx, dword ptr [esp + 0x4c] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x10u)); /* lea edx, [esp + 0x10] */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x28], ecx */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    W32((uint32_t)(c->esp + 0x38u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x38], ecx */
    W32((uint32_t)(c->esp + 0x34u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x34], edx */
    c->edx = (uint32_t)(R32((uint32_t)(0x9b5450u))); /* mov edx, dword ptr [0x10025450] */
    W32((uint32_t)(c->esp + 0x3cu), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x3c], ecx */
    W32((uint32_t)(c->esp + 0x40u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x40], ecx */
    W32((uint32_t)(c->esp + 0x38u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x38], edx */
    c->edx = (uint32_t)(R32((uint32_t)(0x9b5458u))); /* mov edx, dword ptr [0x10025458] */
    W32((uint32_t)(c->esp + 0x44u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x44], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(0x9b5454u))); /* mov ecx, dword ptr [0x10025454] */
    (void)sub32(c, c->esi, c->ebp); /* cmp esi, ebp */
    W32((uint32_t)(c->esp + 0x3cu), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x3c], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(0x9b545cu))); /* mov ecx, dword ptr [0x1002545c] */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)((uint32_t)0x24u)); /* mov dword ptr [esp + 0x24], 0x24 */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x2c], edi */
    W32((uint32_t)(c->esp + 0x30u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0x30], ebp */
    W32((uint32_t)(c->esp + 0x40u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x40], edx */
    W32((uint32_t)(c->esp + 0x44u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x44], ecx */
    if (!c->zf) goto L_00996015; /* jne 0x996015 */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x2c], eax */
    W32((uint32_t)(c->ebx + 0x44u), (uint32_t)(c->ebp)); /* mov dword ptr [ebx + 0x44], ebp */
    goto L_0099601b; /* jmp 0x99601b */
L_00996015:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov edx, dword ptr [esi + 0x20] */
    W32((uint32_t)(c->ebx + 0x44u), (uint32_t)(c->edx)); /* mov dword ptr [ebx + 0x44], edx */
L_0099601b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    c->ebp = (uint32_t)((uint32_t)(c->ebx + 0x4u)); /* lea ebp, [ebx + 4] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x28u)); /* lea edx, [esp + 0x28] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0xcu)); PUSH32(c, 0x0099602eu); call_indirect(c, t_); } /* call dword ptr [ecx + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0099603e; /* je 0x99603e */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x38u)); /* add esp, 0x38 */
    c->esp += 20; return; /* ret 0x10 */
L_0099603e:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_009960cc; /* je 0x9960cc */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x58u)); /* lea edx, [esp + 0x58] */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov eax, dword ptr [ebp] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x54u)); /* lea edx, [esp + 0x54] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x60u)); /* lea edx, [esp + 0x60] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x60u)); /* lea edx, [esp + 0x60] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x2cu)); PUSH32(c, 0x00996068u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x2c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x54u))); /* mov eax, dword ptr [esp + 0x54] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ecx, dword ptr [esi + 8] */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (c->zf) goto L_00996096; /* je 0x996096 */
    c->eax = (uint32_t)(R32((uint32_t)(0x9cdfb0u))); /* mov eax, dword ptr [0x1003dfb0] */
    { uint32_t v_ = 0x9b7494u; PUSH32(c, v_); } /* push 0x10027494 */
    { uint32_t v_ = 0x97u; PUSH32(c, v_); } /* push 0x97 */
    { uint32_t v_ = 0x9b74b4u; PUSH32(c, v_); } /* push 0x100274b4 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x9b70a0u; PUSH32(c, v_); } /* push 0x100270a0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00996092u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00996095u, "int3"); /* int3  */
L_00996096:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ecx, dword ptr [esi + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov esi, dword ptr [esi + 0x20] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x50u))); /* mov edi, dword ptr [esp + 0x50] */
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u))); /* and ecx, 3 */
    while (c->ecx) { W8(c->edi, R8(c->esi)); c->esi += (c->df ? -1 : 1); c->edi += (c->df ? -1 : 1); c->ecx--; } /* rep movsb byte ptr es:[edi], byte ptr [esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x58u))); /* mov ecx, dword ptr [esp + 0x58] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4cu))); /* mov edx, dword ptr [esp + 0x4c] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov ebp, dword ptr [ebp] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x58u))); /* mov ecx, dword ptr [esp + 0x58] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x58u))); /* mov edx, dword ptr [esp + 0x58] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov eax, dword ptr [ebp] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4cu)); PUSH32(c, 0x009960ccu); call_indirect(c, t_); } /* call dword ptr [eax + 0x4c] */
L_009960cc:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov eax, dword ptr [esp + 0x2c] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebx + 0x48u))); /* mov esi, dword ptr [ebx + 0x48] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    W32((uint32_t)(c->ebx + 0x48u), (uint32_t)(c->esi)); /* mov dword ptr [ebx + 0x48], esi */
    c->eax = (uint32_t)(R32((uint32_t)(0x9ce2ecu))); /* mov eax, dword ptr [0x1003e2ec] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x9ce2f0u))); /* mov ecx, dword ptr [0x1003e2f0] */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->eax = (uint32_t)(add32(c, c->eax, c->ebx)); /* add eax, ebx */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    W32((uint32_t)(0x9ce2ecu), (uint32_t)(c->eax)); /* mov dword ptr [0x1003e2ec], eax */
    if ((c->zf || c->sf != c->of)) goto L_009960f5; /* jle 0x9960f5 */
    W32((uint32_t)(0x9ce2f0u), (uint32_t)(c->eax)); /* mov dword ptr [0x1003e2f0], eax */
L_009960f5:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x38u)); /* add esp, 0x38 */
    c->esp += 20; return; /* ret 0x10 */
}

void f_00996110(CPU *c) { /* FUN_10006110 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov eax, dword ptr [esi + 0x20] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009961d1; /* je 0x9961d1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009961d1; /* je 0x9961d1 */
    { uint32_t t_ = R32((uint32_t)(0x9b5020u)); PUSH32(c, 0x00996133u); call_indirect(c, t_); } /* call dword ptr [0x10025020] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov edx, dword ptr [esi + 0x24] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x28u))); /* mov eax, dword ptr [esi + 0x28] */
    c->eax = (uint32_t)(add32(c, c->eax, c->edx)); /* add eax, edx */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if ((c->cf || c->zf)) goto L_00996175; /* jbe 0x996175 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov eax, dword ptr [esi + 0x20] */
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00996158; /* jne 0x996158 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x48u)); PUSH32(c, 0x00996152u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x48] */
    W8((uint32_t)(c->esi + 0x1bu), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esi + 0x1b], 0 */
    goto L_0099616a; /* jmp 0x99616a */
L_00996158:;
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_0099616a; /* jne 0x99616a */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x1cu))); /* mov edx, dword ptr [esi + 0x1c] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x0099616au); f_00995e60(c); /* call 0x995e60 */
L_0099616a:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00996175u); f_009961e0(c); /* call 0x9961e0 */
L_00996175:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov eax, dword ptr [esi + 0x20] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_009961ac; /* je 0x9961ac */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (!c->zf) goto L_009961d1; /* jne 0x9961d1 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov ecx, dword ptr [esi + 0x24] */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0xc], 0 */
    c->edi = (uint32_t)(sub32(c, c->edi, c->ecx)); /* sub edi, ecx */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0xc], edi */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    FPUSH(c, (double)(int64_t)R64((uint32_t)(c->esp + 0x10u))); /* fild qword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x2cu))); /* fmul dword ptr [esi + 0x2c] */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(c->esi + 0x1cu)) - ST(0)); /* fsubr dword ptr [esi + 0x1c] */
    WF32((uint32_t)(c->esp), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp] */
    PUSH32(c, 0x009961a6u); f_00995e60(c); /* call 0x995e60 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->esp += 4; return; /* ret  */
L_009961ac:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov ecx, dword ptr [esi + 0x24] */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0xc], 0 */
    c->edi = (uint32_t)(sub32(c, c->edi, c->ecx)); /* sub edi, ecx */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0xc], edi */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    FPUSH(c, (double)(int64_t)R64((uint32_t)(c->esp + 0x10u))); /* fild qword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x2cu))); /* fmul dword ptr [esi + 0x2c] */
    WF32((uint32_t)(c->esp), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp] */
    PUSH32(c, 0x009961d1u); f_00995e60(c); /* call 0x995e60 */
L_009961d1:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->esp += 4; return; /* ret  */
}

void f_009961e0(CPU *c) { /* FUN_100061e0 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00996276; /* je 0x996276 */
    { uint32_t t_ = R32((uint32_t)(0x9b5020u)); PUSH32(c, 0x009961f7u); call_indirect(c, t_); } /* call dword ptr [0x10025020] */
    W32((uint32_t)(c->esi + 0x24u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x24], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esi + 0x28u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x28], eax */
    if (c->zf) goto L_0099621d; /* je 0x99621d */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 4], eax */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 8], 0 */
    FPUSH(c, (double)(int64_t)R64((uint32_t)(c->esp + 0x4u))); /* fild qword ptr [esp + 4] */
    ST(0) = FPRES(c, FDIV(c, (double)RF32((uint32_t)(c->esi + 0x1cu)), ST(0))); /* fdivr dword ptr [esi + 0x1c] */
    WF32((uint32_t)(c->esi + 0x2cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x2c] */
    goto L_00996224; /* jmp 0x996224 */
L_0099621d:;
    W32((uint32_t)(c->esi + 0x2cu), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [esi + 0x2c], 0x3f800000 */
L_00996224:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00996264; /* je 0x996264 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00996249; /* je 0x996249 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x1cu))); /* mov eax, dword ptr [esi + 0x1c] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x0099623bu); f_00995e60(c); /* call 0x995e60 */
    W32((uint32_t)(c->esi + 0x20u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 0x20], 0 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->esp += 12; return; /* ret 8 */
L_00996249:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x1cu))); /* mov ecx, dword ptr [esi + 0x1c] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00996256u); f_00995e60(c); /* call 0x995e60 */
    W32((uint32_t)(c->esi + 0x20u), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [esi + 0x20], 2 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->esp += 12; return; /* ret 8 */
L_00996264:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x0099626fu); f_00995e60(c); /* call 0x995e60 */
    W32((uint32_t)(c->esi + 0x20u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [esi + 0x20], 1 */
L_00996276:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->esp += 12; return; /* ret 8 */
}

void f_00996280(CPU *c) { /* FUN_10006280 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x9ce2ecu))); /* mov ecx, dword ptr [0x1003e2ec] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->eax = (uint32_t)(R32((uint32_t)(0x9ce2f0u))); /* mov eax, dword ptr [0x1003e2f0] */
    W32((uint32_t)(c->edx), (uint32_t)(c->eax)); /* mov dword ptr [edx], eax */
    c->esp += 4; return; /* ret  */
}

void f_009962a0(CPU *c) { /* FUN_100062a0 */
    PREEMPT_POLL(c);
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x4u))); /* fld dword ptr [esp + 4] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x9b5128u))); FPOP(c); /* fcomp dword ptr [0x10025128] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_009962cb; /* jp 0x9962cb */
    c->eax = (uint32_t)(R32((uint32_t)(0x9cdfb4u))); /* mov eax, dword ptr [0x1003dfb4] */
    { uint32_t v_ = 0x9b7624u; PUSH32(c, v_); } /* push 0x10027624 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0xc], 0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x009962c9u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    goto L_009962f6; /* jmp 0x9962f6 */
L_009962cb:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x4u))); /* fld dword ptr [esp + 4] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x9b5388u))); FPOP(c); /* fcomp dword ptr [0x10025388] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_009962f9; /* jne 0x9962f9 */
    c->eax = (uint32_t)(R32((uint32_t)(0x9cdfb4u))); /* mov eax, dword ptr [0x1003dfb4] */
    { uint32_t v_ = 0x9b75e8u; PUSH32(c, v_); } /* push 0x100275e8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [esp + 0xc], 0x3f800000 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x30u)); PUSH32(c, 0x009962f6u); call_indirect(c, t_); } /* call dword ptr [edx + 0x30] */
L_009962f6:;
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
L_009962f9:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x8u))); /* fld dword ptr [esp + 8] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x9b5128u))); FPOP(c); /* fcomp dword ptr [0x10025128] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00996324; /* jp 0x996324 */
    c->eax = (uint32_t)(R32((uint32_t)(0x9cdfb4u))); /* mov eax, dword ptr [0x1003dfb4] */
    { uint32_t v_ = 0x9b75acu; PUSH32(c, v_); } /* push 0x100275ac */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x10], 0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x00996322u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    goto L_0099634f; /* jmp 0x99634f */
L_00996324:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x8u))); /* fld dword ptr [esp + 8] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x9b5388u))); FPOP(c); /* fcomp dword ptr [0x10025388] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00996352; /* jne 0x996352 */
    c->eax = (uint32_t)(R32((uint32_t)(0x9cdfb4u))); /* mov eax, dword ptr [0x1003dfb4] */
    { uint32_t v_ = 0x9b756cu; PUSH32(c, v_); } /* push 0x1002756c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [esp + 0x10], 0x3f800000 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x30u)); PUSH32(c, 0x0099634fu); call_indirect(c, t_); } /* call dword ptr [edx + 0x30] */
L_0099634f:;
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
L_00996352:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xcu))); /* fld dword ptr [esp + 0xc] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x9b5128u))); FPOP(c); /* fcomp dword ptr [0x10025128] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_0099637d; /* jp 0x99637d */
    c->eax = (uint32_t)(R32((uint32_t)(0x9cdfb4u))); /* mov eax, dword ptr [0x1003dfb4] */
    { uint32_t v_ = 0x9b752cu; PUSH32(c, v_); } /* push 0x1002752c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x14], 0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x0099637bu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    goto L_009963a8; /* jmp 0x9963a8 */
L_0099637d:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xcu))); /* fld dword ptr [esp + 0xc] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x9b5388u))); FPOP(c); /* fcomp dword ptr [0x10025388] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_009963ab; /* jne 0x9963ab */
    c->eax = (uint32_t)(R32((uint32_t)(0x9cdfb4u))); /* mov eax, dword ptr [0x1003dfb4] */
    { uint32_t v_ = 0x9b74ecu; PUSH32(c, v_); } /* push 0x100274ec */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [esp + 0x14], 0x3f800000 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x30u)); PUSH32(c, 0x009963a8u); call_indirect(c, t_); } /* call dword ptr [edx + 0x30] */
L_009963a8:;
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
L_009963ab:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    W32((uint32_t)(0x9b7488u), (uint32_t)(c->eax)); /* mov dword ptr [0x10027488], eax */
    W32((uint32_t)(0x9b748cu), (uint32_t)(c->ecx)); /* mov dword ptr [0x1002748c], ecx */
    W32((uint32_t)(0x9b7490u), (uint32_t)(c->edx)); /* mov dword ptr [0x10027490], edx */
    c->esp += 4; return; /* ret  */
}

void f_009963d0(CPU *c) { /* FUN_100063d0 */
    PREEMPT_POLL(c);
    FPUSH(c, (double)RF32((uint32_t)(0x9b7488u))); /* fld dword ptr [0x10027488] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    WF32((uint32_t)(c->eax), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax] */
    FPUSH(c, (double)RF32((uint32_t)(0x9b748cu))); /* fld dword ptr [0x1002748c] */
    WF32((uint32_t)(c->ecx), (float)ST(0)); FPOP(c); /* fstp dword ptr [ecx] */
    FPUSH(c, (double)RF32((uint32_t)(0x9b7490u))); /* fld dword ptr [0x10027490] */
    WF32((uint32_t)(c->edx), (float)ST(0)); FPOP(c); /* fstp dword ptr [edx] */
    c->esp += 4; return; /* ret  */
}

void f_00996400(CPU *c) { /* FUN_10006400 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x9b53a0u)); /* mov dword ptr [eax], 0x100253a0 */
    c->esp += 4; return; /* ret  */
}

void f_00996410(CPU *c) { /* FUN_10006410 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00996418u); f_00996430(c); /* call 0x996430 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00996428; /* je 0x996428 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00996425u); f_00993c50(c); /* call 0x993c50 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00996428:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00996430(CPU *c) { /* FUN_10006430 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx), (uint32_t)((uint32_t)0x9b5404u)); /* mov dword ptr [ecx], 0x10025404 */
    c->esp += 4; return; /* ret  */
}

void f_00996440(CPU *c) { /* PTR_00996440 */
    PREEMPT_POLL(c);
    c->esp += 4; return; /* ret  */
}

void f_00996450(CPU *c) { /* PTR_00996450 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_00996460(CPU *c) { /* PTR_00996460 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    c->esp += 4; return; /* ret  */
}

void f_00996470(CPU *c) { /* PTR_00996470 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x4u))); /* mov al, byte ptr [esp + 4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x9b5404u)); /* mov dword ptr [esi], 0x10025404 */
    if (c->zf) goto L_0099648a; /* je 0x99648a */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00996487u); f_00993c50(c); /* call 0x993c50 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_0099648a:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00996490(CPU *c) { /* DSOUND.DLL::Ordinal_2 */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(0x9b5004u)); switch (t_) {  default: jump_indirect(c, t_, 0x00996490u); return; } } /* jmp dword ptr [0x10025004] */
}

void f_00996496(CPU *c) { /* DSOUND.DLL::Ordinal_11 */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(0x9b5000u)); switch (t_) {  default: jump_indirect(c, t_, 0x00996496u); return; } } /* jmp dword ptr [0x10025000] */
}

void f_009964a0(CPU *c) { /* FUN_100064a0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edi, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00996592; /* je 0x996592 */
    c->eax = (uint32_t)((uint32_t)(c->edi + 0x250u)); /* lea eax, [edi + 0x250] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x009964b9u); f_009a31c0(c); /* call 0x9a31c0 */
    c->ecx = (uint32_t)((uint32_t)(c->edi + 0x1e0u)); /* lea ecx, [edi + 0x1e0] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x009964c5u); f_009a3550(c); /* call 0x9a3550 */
    c->edx = (uint32_t)((uint32_t)(c->edi + 0x78u)); /* lea edx, [edi + 0x78] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x009964ceu); f_009a2010(c); /* call 0x9a2010 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x48u))); /* mov eax, dword ptr [edi + 0x48] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0099652d; /* je 0x99652d */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x34u))); /* mov eax, dword ptr [edi + 0x34] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0099652d; /* je 0x99652d */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(logic32(c, 0)); /* xor ebp, ebp */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_00996517; /* jle 0x996517 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_009964ec:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x48u))); /* mov ecx, dword ptr [edi + 0x48] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x009964f9u); f_009a2980(c); /* call 0x9a2980 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x4cu))); /* mov ecx, dword ptr [edi + 0x4c] */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->ebx)); /* add ecx, ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00996504u); f_009a28c0(c); /* call 0x9a28c0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x34u))); /* mov eax, dword ptr [edi + 0x34] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->ebp = (uint32_t)(inc32(c, c->ebp)); /* inc ebp */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x20u)); /* add esi, 0x20 */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x10u)); /* add ebx, 0x10 */
    (void)sub32(c, c->ebp, c->eax); /* cmp ebp, eax */
    if ((c->sf != c->of)) goto L_009964ec; /* jl 0x9964ec */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
L_00996517:;
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + 0x48u))); /* mov edx, dword ptr [edi + 0x48] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00996520u); f_00998bae(c); /* call 0x998bae */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x4cu))); /* mov eax, dword ptr [edi + 0x4c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00996529u); f_00998bae(c); /* call 0x998bae */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
L_0099652d:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x3cu))); /* mov eax, dword ptr [edi + 0x3c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0099653d; /* je 0x99653d */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0099653au); f_00998bae(c); /* call 0x998bae */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_0099653d:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x44u))); /* mov eax, dword ptr [edi + 0x44] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0099654d; /* je 0x99654d */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0099654au); f_00998bae(c); /* call 0x998bae */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_0099654d:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x40u))); /* mov eax, dword ptr [edi + 0x40] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0099655d; /* je 0x99655d */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0099655au); f_00998bae(c); /* call 0x998bae */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_0099655d:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x38u))); /* mov eax, dword ptr [edi + 0x38] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0099656d; /* je 0x99656d */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0099656au); f_00998bae(c); /* call 0x998bae */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_0099656d:;
    c->ecx = (uint32_t)((uint32_t)(c->edi + 0x18u)); /* lea ecx, [edi + 0x18] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00996576u); f_009a21b0(c); /* call 0x9a21b0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00996589; /* je 0x996589 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edi + 0x2c8u)); PUSH32(c, 0x00996586u); call_indirect(c, t_); } /* call dword ptr [edi + 0x2c8] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00996589:;
    c->ecx = (uint32_t)((uint32_t)0xb4u); /* mov ecx, 0xb4 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
L_00996592:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_009965a0(CPU *c) { /* FUN_100065a0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ecx, dword ptr [esp + 0x14] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov edx, dword ptr [esp + 0x1c] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x10u)); /* sub esp, 0x10 */
    c->eax = (uint32_t)(c->esp); /* mov eax, esp */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov esi, dword ptr [esp + 0x1c] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov ecx, dword ptr [esp + 0x30] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 4], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov edx, dword ptr [esp + 0x34] */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov ecx, dword ptr [esp + 0x20] */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->edx)); /* mov dword ptr [eax + 0xc], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov eax, dword ptr [esp + 0x24] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov edx, dword ptr [esp + 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x009965dau); f_009965f0(c); /* call 0x9965f0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_009965ea; /* jne 0x9965ea */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x009965e7u); f_00996950(c); /* call 0x996950 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_009965ea:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_009965f0(CPU *c) { /* FUN_100065f0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ebp, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov esi, dword ptr [esp + 0x24] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    (void)logic32(c, (uint32_t)(c->ebp & c->ebp)); /* test ebp, ebp */
    if (c->zf) goto L_00996612; /* je 0x996612 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t t_ = c->esi; PUSH32(c, 0x00996609u); call_indirect(c, t_); } /* call esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    goto L_0099661a; /* jmp 0x99661a */
L_00996612:;
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [esp + 0x14], 0xffffffff */
L_0099661a:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov ebx, dword ptr [esp + 0x18] */
    c->ecx = (uint32_t)((uint32_t)0xb4u); /* mov ecx, 0xb4 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edi = (uint32_t)(c->ebx); /* mov edi, ebx */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov ecx, dword ptr [esp + 0x24] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov edx, dword ptr [esp + 0x2c] */
    c->eax = (uint32_t)((uint32_t)(c->ebx + 0x2c0u)); /* lea eax, [ebx + 0x2c0] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->ebp)); /* mov dword ptr [ebx], ebp */
    c->ebp = (uint32_t)((uint32_t)(c->ebx + 0x18u)); /* lea ebp, [ebx + 0x18] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov ecx, dword ptr [esp + 0x30] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [eax + 4], esi */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 8], edx */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0xc], ecx */
    PUSH32(c, 0x00996651u); f_009a2190(c); /* call 0x9a2190 */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov edi, dword ptr [esp + 0x20] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00996687; /* je 0x996687 */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov esi, dword ptr [esp + 0x20] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x00996667u); f_009a21e0(c); /* call 0x9a21e0 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->esi = (uint32_t)(c->edi); /* mov esi, edi */
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u))); /* and ecx, 3 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    while (c->ecx) { W8(c->edi, R8(c->esi)); c->esi += (c->df ? -1 : 1); c->edi += (c->df ? -1 : 1); c->ecx--; } /* rep movsb byte ptr es:[edi], byte ptr [esi] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x00996684u); f_009a2260(c); /* call 0x9a2260 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_00996687:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->esi = (uint32_t)((uint32_t)0x1u); /* mov esi, 1 */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (c->zf) goto L_00996698; /* je 0x996698 */
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [ebx + 4], esi */
L_00996698:;
    { uint32_t v_ = 0x20u; PUSH32(c, v_); } /* push 0x20 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W32((uint32_t)(c->ebx + 0x34u), (uint32_t)(c->esi)); /* mov dword ptr [ebx + 0x34], esi */
    PUSH32(c, 0x009966a3u); f_00998c97(c); /* call 0x998c97 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x34u))); /* mov ecx, dword ptr [ebx + 0x34] */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    W32((uint32_t)(c->ebx + 0x48u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 0x48], eax */
    PUSH32(c, 0x009966b1u); f_00998c97(c); /* call 0x998c97 */
    c->edx = (uint32_t)((uint32_t)(c->ebx + 0x5cu)); /* lea edx, [ebx + 0x5c] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    W32((uint32_t)(c->ebx + 0x4cu), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 0x4c], eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x48u))); /* mov eax, dword ptr [ebx + 0x48] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x009966c5u); f_00996700(c); /* call 0x996700 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x24u)); /* add esp, 0x24 */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if ((c->sf == c->of)) goto L_009966e4; /* jge 0x9966e4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    W32((uint32_t)(c->ebx), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ebx], 0 */
    PUSH32(c, 0x009966dau); f_009964a0(c); /* call 0x9964a0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_009966e4:;
    (void)sub32(c, R32((uint32_t)(c->ebx + 0x58u)), c->esi); /* cmp dword ptr [ebx + 0x58], esi */
    if ((c->sf == c->of)) goto L_009966ec; /* jge 0x9966ec */
    W32((uint32_t)(c->ebx + 0x58u), (uint32_t)(c->esi)); /* mov dword ptr [ebx + 0x58], esi */
L_009966ec:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00996700(CPU *c) { /* FUN_10006700 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x30u)); /* sub esp, 0x30 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x50u))); /* mov esi, dword ptr [esp + 0x50] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00996750; /* jne 0x996750 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x44u))); /* mov ebx, dword ptr [esp + 0x44] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x10u)); /* lea eax, [esp + 0x10] */
    { uint32_t v_ = 0x2134u; PUSH32(c, v_); } /* push 0x2134 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00996723u); f_00996840(c); /* call 0x996840 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, c->eax, (uint32_t)0xffffff80u); /* cmp eax, -0x80 */
    if (!c->zf) goto L_00996733; /* jne 0x996733 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x30u)); /* add esp, 0x30 */
    c->esp += 4; return; /* ret  */
L_00996733:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf == c->of)) goto L_00996744; /* jge 0x996744 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (uint32_t)((uint32_t)0xffffff7cu); /* mov eax, 0xffffff7c */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x30u)); /* add esp, 0x30 */
    c->esp += 4; return; /* ret  */
L_00996744:;
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x10u)); /* lea ecx, [esp + 0x10] */
    W32((uint32_t)(c->esp + 0x54u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x54], ecx */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    goto L_00996754; /* jmp 0x996754 */
L_00996750:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x44u))); /* mov ebx, dword ptr [esp + 0x44] */
L_00996754:;
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x50u))); /* mov edi, dword ptr [esp + 0x50] */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00996767; /* je 0x996767 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00996762u); f_009a1f40(c); /* call 0x9a1f40 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
L_00996767:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->edi = (uint32_t)((uint32_t)(c->ebx + 0x78u)); /* lea edi, [ebx + 0x78] */
    PUSH32(c, 0x00996770u); f_009a1f40(c); /* call 0x9a1f40 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00996777u); f_009a1fa0(c); /* call 0x9a1fa0 */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x54u))); /* mov ebp, dword ptr [esp + 0x54] */
    W32((uint32_t)(c->ebx + 0x58u), (uint32_t)((uint32_t)0x3u)); /* mov dword ptr [ebx + 0x58], 3 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x00996788u); f_009a2950(c); /* call 0x9a2950 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x5cu))); /* mov edx, dword ptr [esp + 0x5c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00996792u); f_009a28a0(c); /* call 0x9a28a0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
L_00996797:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x0099679eu); f_009a23d0(c); /* call 0x9a23d0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)sub32(c, c->ebx, (uint32_t)0x3u); /* cmp ebx, 3 */
    if ((c->sf == c->of)) goto L_00996835; /* jge 0x996835 */
L_009967aa:;
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x20u)); /* lea eax, [esp + 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x009967b5u); f_009a2730(c); /* call 0x9a2730 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009967e6; /* je 0x9967e6 */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (c->zf) goto L_00996802; /* je 0x996802 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4cu))); /* mov edx, dword ptr [esp + 0x4c] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x20u)); /* lea ecx, [esp + 0x20] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x009967d1u); f_009a2ae0(c); /* call 0x9a2ae0 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_00996807; /* jne 0x996807 */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    (void)sub32(c, c->ebx, (uint32_t)0x3u); /* cmp ebx, 3 */
    if ((c->sf == c->of)) goto L_00996835; /* jge 0x996835 */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x54u))); /* mov esi, dword ptr [esp + 0x54] */
    goto L_009967aa; /* jmp 0x9967aa */
L_009967e6:;
    (void)sub32(c, c->ebx, (uint32_t)0x3u); /* cmp ebx, 3 */
    if ((c->sf == c->of)) goto L_00996835; /* jge 0x996835 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x44u))); /* mov eax, dword ptr [esp + 0x44] */
    { uint32_t v_ = 0x2134u; PUSH32(c, v_); } /* push 0x2134 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x009967fbu); f_00996840(c); /* call 0x996840 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf == c->of)) goto L_00996797; /* jge 0x996797 */
L_00996802:;
    c->esi = (uint32_t)((uint32_t)0xffffff7bu); /* mov esi, 0xffffff7b */
L_00996807:;
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x0099680du); f_009a2980(c); /* call 0x9a2980 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x50u))); /* mov ecx, dword ptr [esp + 0x50] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00996817u); f_009a28c0(c); /* call 0x9a28c0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x0099681du); f_009a2010(c); /* call 0x9a2010 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x50u))); /* mov edx, dword ptr [esp + 0x50] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    W32((uint32_t)(c->edx + 0x58u), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [edx + 0x58], 2 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x30u)); /* add esp, 0x30 */
    c->esp += 4; return; /* ret  */
L_00996835:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x30u)); /* add esp, 0x30 */
    c->esp += 4; return; /* ret  */
}

void f_00996840(CPU *c) { /* FUN_10006840 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov esi, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov edi, dword ptr [esp + 0x18] */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if ((c->zf || c->sf != c->of)) goto L_00996852; /* jle 0x996852 */
    c->edi = (uint32_t)(add32(c, c->edi, R32((uint32_t)(c->esi + 0x8u)))); /* add edi, dword ptr [esi + 8] */
L_00996852:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ebx, dword ptr [esp + 0x14] */
L_00996856:;
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if ((c->zf || c->sf != c->of)) goto L_0099686d; /* jle 0x99686d */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov ecx, dword ptr [esi + 0xc] */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if ((!c->zf && c->sf == c->of)) goto L_009968a8; /* jg 0x9968a8 */
    if ((c->sf != c->of)) goto L_0099686d; /* jl 0x99686d */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov edx, dword ptr [esi + 8] */
    (void)sub32(c, c->edx, c->eax); /* cmp edx, eax */
    if (!c->cf) goto L_009968a8; /* jae 0x9968a8 */
L_0099686d:;
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x18u)); /* lea eax, [esi + 0x18] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00996877u); f_009a2280(c); /* call 0x9a2280 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf == c->of)) goto L_00996891; /* jge 0x996891 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ecx, dword ptr [esi + 8] */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 8], ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->edx)); /* sbb eax, edx */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xc], eax */
    goto L_00996856; /* jmp 0x996856 */
L_00996891:;
    if (!c->zf) goto L_009968c1; /* jne 0x9968c1 */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_009968a8; /* je 0x9968a8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x0099689du); f_009968e0(c); /* call 0x9968e0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009968af; /* je 0x9968af */
    if ((c->sf != c->of)) goto L_009968b8; /* jl 0x9968b8 */
    goto L_00996856; /* jmp 0x996856 */
L_009968a8:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_009968af:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)((uint32_t)0xfffffffeu); /* mov eax, 0xfffffffe */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_009968b8:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)((uint32_t)0xffffff80u); /* mov eax, 0xffffff80 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_009968c1:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ecx, dword ptr [esi + 8] */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 8], edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    c->eax = (uint32_t)(adc32(c, c->eax, c->edx)); /* adc eax, edx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xc], eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_009968e0(CPU *c) { /* FUN_100068e0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x009968e6u); f_00998e47(c); /* call 0x998e47 */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [eax], 0 */
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x0u); /* cmp dword ptr [esi], 0 */
    if (c->zf) goto L_00996940; /* je 0x996940 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x18u)); /* lea edi, [esi + 0x18] */
    { uint32_t v_ = 0x2134u; PUSH32(c, v_); } /* push 0x2134 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00996904u); f_009a21e0(c); /* call 0x9a21e0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x2134u; PUSH32(c, v_); } /* push 0x2134 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->esi + 0x2c0u)); PUSH32(c, 0x00996915u); call_indirect(c, t_); } /* call dword ptr [esi + 0x2c0] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if ((c->zf || c->sf != c->of)) goto L_00996928; /* jle 0x996928 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00996925u); f_009a2260(c); /* call 0x9a2260 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
L_00996928:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    if (!c->zf) goto L_0099693c; /* jne 0x99693c */
    PUSH32(c, 0x00996932u); f_00998e47(c); /* call 0x998e47 */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0x0u); /* cmp dword ptr [eax], 0 */
    if (c->zf) goto L_0099693c; /* je 0x99693c */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_0099693c:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_00996940:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00996950(CPU *c) { /* FUN_10006950 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    c->eax = (uint32_t)((uint32_t)0x2u); /* mov eax, 2 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x58u)), c->eax); /* cmp dword ptr [esi + 0x58], eax */
    if ((c->sf == c->of)) goto L_00996962; /* jge 0x996962 */
    W32((uint32_t)(c->esi + 0x58u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x58], eax */
L_00996962:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0099698d; /* je 0x99698d */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00996970u); f_009969a0(c); /* call 0x9969a0 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00996988; /* je 0x996988 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi], 0 */
    PUSH32(c, 0x00996985u); f_009964a0(c); /* call 0x9964a0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00996988:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_0099698d:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_009969a0(CPU *c) { /* FUN_100069a0 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x10u)); /* sub esp, 0x10 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov esi, dword ptr [esp + 0x20] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esi + 0x5cu))); /* mov ebx, dword ptr [esi + 0x5c] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ebp, dword ptr [esi + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->esi + 0x2c4u)); PUSH32(c, 0x009969c0u); call_indirect(c, t_); } /* call dword ptr [esi + 0x2c4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t t_ = R32((uint32_t)(c->esi + 0x2ccu)); PUSH32(c, 0x009969c9u); call_indirect(c, t_); } /* call dword ptr [esi + 0x2cc] */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x10], eax */
    W32((uint32_t)(c->esi + 0x14u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x14], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov edx, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x14u))); /* mov eax, dword ptr [esi + 0x14] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x24u)); /* lea ecx, [esp + 0x24] */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 8], edx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xc], eax */
    PUSH32(c, 0x009969e7u); f_00996a90(c); /* call 0x996a90 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if ((c->sf == c->of)) goto L_00996a03; /* jge 0x996a03 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x009969f6u); f_009964a0(c); /* call 0x9964a0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
L_00996a03:;
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x10u)); /* lea edx, [esp + 0x10] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00996a0du); f_009a1f40(c); /* call 0x9a1f40 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    if (c->zf) goto L_00996a40; /* je 0x996a40 */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00996a23u); f_00996ba0(c); /* call 0x996ba0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf == c->of)) goto L_00996a6a; /* jge 0x996a6a */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00996a30u); f_009964a0(c); /* call 0x9964a0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->eax = (uint32_t)((uint32_t)0xffffff80u); /* mov eax, 0xffffff80 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
L_00996a40:;
    c->eax = (uint32_t)((uint32_t)(c->edi + 0x1u)); /* lea eax, [edi + 1] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00996a4du); f_00996ba0(c); /* call 0x996ba0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00996a6a; /* je 0x996a6a */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00996a5au); f_009964a0(c); /* call 0x9964a0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->eax = (uint32_t)((uint32_t)0xffffff80u); /* mov eax, 0xffffff80 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
L_00996a6a:;
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00996a71u); f_00996cf0(c); /* call 0x996cf0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00996a79u); f_00996ef0(c); /* call 0x996ef0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_00996a90(CPU *c) { /* FUN_10006a90 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov ebp, dword ptr [esp + 0x18] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov esi, dword ptr [esp + 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [esp + 0x1c], 0xffffffff */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov edi, dword ptr [esi + 8] */
L_00996aaa:;
    c->edi = (uint32_t)(sub32(c, c->edi, (uint32_t)0x2134u)); /* sub edi, 0x2134 */
    if (!c->sf) goto L_00996ab4; /* jns 0x996ab4 */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
L_00996ab4:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00996abbu); f_00996b60(c); /* call 0x996b60 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov ecx, dword ptr [esi + 0xc] */
    c->eax = (uint32_t)((uint32_t)(c->edi + 0x2134u)); /* lea eax, [edi + 0x2134] */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    c->ebx = (uint32_t)(c->edx); /* mov ebx, edx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)sub32(c, c->ecx, c->ebx); /* cmp ecx, ebx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    if ((!c->zf && c->sf == c->of)) goto L_00996b13; /* jg 0x996b13 */
    if ((c->sf != c->of)) goto L_00996adb; /* jl 0x996adb */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov edx, dword ptr [esi + 8] */
    (void)sub32(c, c->edx, c->eax); /* cmp edx, eax */
    if (!c->cf) goto L_00996b13; /* jae 0x996b13 */
L_00996adb:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov edx, dword ptr [esi + 8] */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->eax = (uint32_t)(sub32(c, c->eax, c->edx)); /* sub eax, edx */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x2134u)); /* add eax, 0x2134 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00996aefu); f_00996840(c); /* call 0x996840 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, c->eax, (uint32_t)0xffffff80u); /* cmp eax, -0x80 */
    if (c->zf) goto L_00996b47; /* je 0x996b47 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf != c->of)) goto L_00996b13; /* jl 0x996b13 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov ecx, dword ptr [esi + 0xc] */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x1c], eax */
    (void)sub32(c, c->ecx, c->ebx); /* cmp ecx, ebx */
    if ((c->sf != c->of)) goto L_00996adb; /* jl 0x996adb */
    if ((!c->zf && c->sf == c->of)) goto L_00996b13; /* jg 0x996b13 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov edx, dword ptr [esi + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    (void)sub32(c, c->edx, c->eax); /* cmp edx, eax */
    if (c->cf) goto L_00996adb; /* jb 0x996adb */
L_00996b13:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov eax, dword ptr [esp + 0x1c] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (c->zf) goto L_00996aaa; /* je 0x996aaa */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00996b25u); f_00996b60(c); /* call 0x996b60 */
    { uint32_t v_ = 0x2134u; PUSH32(c, v_); } /* push 0x2134 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00996b31u); f_00996840(c); /* call 0x996840 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    c->eax = (uint32_t)((uint32_t)0xffffff7fu); /* mov eax, 0xffffff7f */
    if ((c->sf != c->of)) goto L_00996b3f; /* jl 0x996b3f */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
L_00996b3f:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->esp += 4; return; /* ret  */
L_00996b47:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (uint32_t)((uint32_t)0xffffff80u); /* mov eax, 0xffffff80 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->esp += 4; return; /* ret  */
}

void f_00996b60(CPU *c) { /* FUN_10006b60 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00996b95; /* je 0x996b95 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ebx = (uint32_t)(c->edx); /* mov ebx, edx */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t t_ = R32((uint32_t)(c->esi + 0x2c4u)); PUSH32(c, 0x00996b81u); call_indirect(c, t_); } /* call dword ptr [esi + 0x2c4] */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 8], edi */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0xc], ebx */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x18u)); /* add esi, 0x18 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00996b90u); f_009a26c0(c); /* call 0x9a26c0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
L_00996b95:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00996ba0(CPU *c) { /* FUN_10006ba0 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov ebp, dword ptr [esp + 0x24] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov esi, dword ptr [esp + 0x34] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov edi, dword ptr [esp + 0x34] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x10], esi */
    (void)sub32(c, c->edi, c->esi); /* cmp edi, esi */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x14], esi */
    if ((c->sf == c->of)) goto L_00996c3e; /* jge 0x996c3e */
    goto L_00996bc5; /* jmp 0x996bc5 */
L_00996bc1:;
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
L_00996bc5:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(sub32(c, c->eax, c->edi)); /* sub eax, edi */
    (void)sub32(c, c->eax, (uint32_t)0x2134u); /* cmp eax, 0x2134 */
    if ((c->sf == c->of)) goto L_00996bd4; /* jge 0x996bd4 */
    c->ebx = (uint32_t)(c->edi); /* mov ebx, edi */
    goto L_00996bde; /* jmp 0x996bde */
L_00996bd4:;
    c->eax = (uint32_t)((uint32_t)(c->esi + c->edi)); /* lea eax, [esi + edi] */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    c->eax = (uint32_t)(sub32(c, c->eax, c->edx)); /* sub eax, edx */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->ebx = (uint32_t)(sar32(c, c->ebx, 1)); /* sar ebx, 1 */
L_00996bde:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x00996be5u); f_00996b60(c); /* call 0x996b60 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x20u)); /* lea ecx, [esp + 0x20] */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x00996bf2u); f_00996840(c); /* call 0x996840 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    (void)sub32(c, c->esi, (uint32_t)0xffffff80u); /* cmp esi, -0x80 */
    if (c->zf) goto L_00996c9c; /* je 0x996c9c */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if ((c->sf != c->of)) goto L_00996c28; /* jl 0x996c28 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x18u)); /* lea edx, [esp + 0x18] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00996c0eu); f_009a1f40(c); /* call 0x9a1f40 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x40u))); /* mov ecx, dword ptr [esp + 0x40] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->zf) goto L_00996c28; /* jne 0x996c28 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov eax, dword ptr [esp + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov ecx, dword ptr [esp + 0x24] */
    c->edi = (uint32_t)((uint32_t)(c->ecx + c->eax)); /* lea edi, [ecx + eax] */
    c->edi = (uint32_t)(add32(c, c->edi, c->esi)); /* add edi, esi */
    goto L_00996c34; /* jmp 0x996c34 */
L_00996c28:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x10], ebx */
    if ((c->sf != c->of)) goto L_00996c34; /* jl 0x996c34 */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x14], esi */
L_00996c34:;
    (void)sub32(c, c->edi, R32((uint32_t)(c->esp + 0x10u))); /* cmp edi, dword ptr [esp + 0x10] */
    if ((c->sf != c->of)) goto L_00996bc1; /* jl 0x996bc1 */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x38u))); /* mov esi, dword ptr [esp + 0x38] */
L_00996c3e:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edx, dword ptr [esp + 0x14] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x00996c49u); f_00996b60(c); /* call 0x996b60 */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x20u)); /* lea eax, [esp + 0x20] */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x00996c56u); f_00996840(c); /* call 0x996840 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    (void)sub32(c, c->eax, (uint32_t)0xffffff80u); /* cmp eax, -0x80 */
    if (!c->zf) goto L_00996c66; /* jne 0x996c66 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    c->esp += 4; return; /* ret  */
L_00996c66:;
    (void)sub32(c, c->edi, c->esi); /* cmp edi, esi */
    if ((c->sf == c->of)) goto L_00996ca9; /* jge 0x996ca9 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf != c->of)) goto L_00996ca9; /* jl 0x996ca9 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x40u))); /* mov ebx, dword ptr [esp + 0x40] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x18u)); /* lea edx, [esp + 0x18] */
    c->ecx = (uint32_t)((uint32_t)(c->ebx + 0x1u)); /* lea ecx, [ebx + 1] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00996c80u); f_009a1f40(c); /* call 0x9a1f40 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov ecx, dword ptr [esp + 0x1c] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x00996c94u); f_00996ba0(c); /* call 0x996ba0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    (void)sub32(c, c->eax, (uint32_t)0xffffff80u); /* cmp eax, -0x80 */
    if (!c->zf) goto L_00996cd2; /* jne 0x996cd2 */
L_00996c9c:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (uint32_t)((uint32_t)0xffffff80u); /* mov eax, 0xffffff80 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    c->esp += 4; return; /* ret  */
L_00996ca9:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x40u))); /* mov ebx, dword ptr [esp + 0x40] */
    c->edx = (uint32_t)((uint32_t)(c->ebx * 8 + 0x10u)); /* lea edx, [ebx*8 + 0x10] */
    c->esi = (uint32_t)((uint32_t)(c->ebx + 0x1u)); /* lea esi, [ebx + 1] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    W32((uint32_t)(c->ebp + 0x34u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0x34], esi */
    PUSH32(c, 0x00996cc0u); f_00998e59(c); /* call 0x998e59 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    W32((uint32_t)(c->ebp + 0x38u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp + 0x38], ecx */
    W32((uint32_t)(c->ecx + c->esi * 8), (uint32_t)(c->eax)); /* mov dword ptr [ecx + esi*8], eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    W32((uint32_t)(c->ecx + c->esi * 8 + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + esi*8 + 4], edx */
L_00996cd2:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov eax, dword ptr [esp + 0x30] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x38u))); /* mov ecx, dword ptr [ebp + 0x38] */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    W32((uint32_t)(c->ecx + c->ebx * 8), (uint32_t)(c->eax)); /* mov dword ptr [ecx + ebx*8], eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    W32((uint32_t)(c->ecx + c->ebx * 8 + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + ebx*8 + 4], edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    c->esp += 4; return; /* ret  */
}

void f_00996cf0(CPU *c) { /* FUN_10006cf0 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x10u)); /* sub esp, 0x10 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov esi, dword ptr [esp + 0x1c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x34u))); /* mov eax, dword ptr [esi + 0x34] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x48u))); /* mov ecx, dword ptr [esi + 0x48] */
    c->eax = (uint32_t)(shl32(c, c->eax, 5)); /* shl eax, 5 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00996d09u); f_00998f93(c); /* call 0x998f93 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x34u))); /* mov edx, dword ptr [esi + 0x34] */
    W32((uint32_t)(c->esi + 0x48u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x48], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4cu))); /* mov eax, dword ptr [esi + 0x4c] */
    c->edx = (uint32_t)(shl32(c, c->edx, 4)); /* shl edx, 4 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00996d1cu); f_00998f93(c); /* call 0x998f93 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x34u))); /* mov ecx, dword ptr [esi + 0x34] */
    W32((uint32_t)(c->esi + 0x4cu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x4c], eax */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 3)); /* shl ecx, 3 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00996d2bu); f_00998e59(c); /* call 0x998e59 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x34u))); /* mov edx, dword ptr [esi + 0x34] */
    W32((uint32_t)(c->esi + 0x3cu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x3c], eax */
    c->edx = (uint32_t)(shl32(c, c->edx, 3)); /* shl edx, 3 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00996d3au); f_00998e59(c); /* call 0x998e59 */
    W32((uint32_t)(c->esi + 0x44u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x44], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x34u))); /* mov eax, dword ptr [esi + 0x34] */
    c->eax = (uint32_t)(shl32(c, c->eax, 2)); /* shl eax, 2 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00996d49u); f_00998e59(c); /* call 0x998e59 */
    W32((uint32_t)(c->esi + 0x40u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x40], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x34u))); /* mov eax, dword ptr [esi + 0x34] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_00996e79; /* jle 0x996e79 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
L_00996d5d:;
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (!c->zf) goto L_00996d70; /* jne 0x996d70 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov eax, dword ptr [esp + 0x24] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x3cu))); /* mov ecx, dword ptr [esi + 0x3c] */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 4], edx */
    goto L_00996ddc; /* jmp 0x996ddc */
L_00996d70:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x38u))); /* mov edx, dword ptr [esi + 0x38] */
    c->edi = (uint32_t)((uint32_t)(c->ebx * 8)); /* lea edi, [ebx*8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + c->edi))); /* mov eax, dword ptr [edx + edi] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00996d84u); f_00996b60(c); /* call 0x996b60 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4cu))); /* mov eax, dword ptr [esi + 0x4c] */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 4)); /* shl ecx, 4 */
    c->edx = (uint32_t)(c->ebx); /* mov edx, ebx */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x48u))); /* mov eax, dword ptr [esi + 0x48] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->edx = (uint32_t)(shl32(c, c->edx, 5)); /* shl edx, 5 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00996da4u); f_00996700(c); /* call 0x996700 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf == c->of)) goto L_00996dc0; /* jge 0x996dc0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x3cu))); /* mov eax, dword ptr [esi + 0x3c] */
    W32((uint32_t)(c->edi + c->eax), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [edi + eax], 0xffffffff */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    W32((uint32_t)(c->edi + 0x4u), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [edi + 4], 0xffffffff */
    goto L_00996ddc; /* jmp 0x996ddc */
L_00996dc0:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x3cu))); /* mov edx, dword ptr [esi + 0x3c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    c->edi = (uint32_t)(add32(c, c->edi, c->edx)); /* add edi, edx */
    c->edx = (uint32_t)((uint32_t)(c->esi + 0x78u)); /* lea edx, [esi + 0x78] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov ecx, dword ptr [esi + 0xc] */
    W32((uint32_t)(c->edi + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [edi + 4], ecx */
    PUSH32(c, 0x00996dd9u); f_009a2010(c); /* call 0x9a2010 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00996ddc:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x38u))); /* mov eax, dword ptr [esi + 0x38] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + c->ebx * 8 + 0x8u))); /* mov ecx, dword ptr [eax + ebx*8 + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00996deau); f_00996b60(c); /* call 0x996b60 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
L_00996ded:;
    c->edx = (uint32_t)((uint32_t)(c->esp + 0xcu)); /* lea edx, [esp + 0xc] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00996df8u); f_00996a90(c); /* call 0x996a90 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if ((c->sf != c->of)) goto L_00996e20; /* jl 0x996e20 */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0xcu)); /* lea eax, [esp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00996e0bu); f_009a1e60(c); /* call 0x9a1e60 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & c->edx))); /* and eax, edx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (!c->zf) goto L_00996e45; /* jne 0x996e45 */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 8], eax */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0xc], edx */
    goto L_00996ded; /* jmp 0x996ded */
L_00996e20:;
    c->edi = (uint32_t)(R32((uint32_t)(c->esi + 0x48u))); /* mov edi, dword ptr [esi + 0x48] */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 5)); /* shl ecx, 5 */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->edi)); /* add ecx, edi */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00996e30u); f_009a2980(c); /* call 0x9a2980 */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi + 0x4cu))); /* mov edi, dword ptr [esi + 0x4c] */
    c->edx = (uint32_t)(c->ebx); /* mov edx, ebx */
    c->edx = (uint32_t)(shl32(c, c->edx, 4)); /* shl edx, 4 */
    c->edx = (uint32_t)(add32(c, c->edx, c->edi)); /* add edx, edi */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00996e40u); f_009a28c0(c); /* call 0x9a28c0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    goto L_00996e6c; /* jmp 0x996e6c */
L_00996e45:;
    c->eax = (uint32_t)((uint32_t)(c->esp + 0xcu)); /* lea eax, [esp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00996e4fu); f_009a1f40(c); /* call 0x9a1f40 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x40u))); /* mov ecx, dword ptr [esi + 0x40] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x10u)); /* lea edx, [esp + 0x10] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    W32((uint32_t)(c->ecx + c->ebx * 4), (uint32_t)(c->eax)); /* mov dword ptr [ecx + ebx*4], eax */
    PUSH32(c, 0x00996e5fu); f_009a1e60(c); /* call 0x9a1e60 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x44u))); /* mov ecx, dword ptr [esi + 0x44] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    W32((uint32_t)(c->ecx + c->ebx * 8), (uint32_t)(c->eax)); /* mov dword ptr [ecx + ebx*8], eax */
    W32((uint32_t)(c->ecx + c->ebx * 8 + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + ebx*8 + 4], edx */
L_00996e6c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x34u))); /* mov eax, dword ptr [esi + 0x34] */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    (void)sub32(c, c->ebx, c->eax); /* cmp ebx, eax */
    if ((c->sf != c->of)) goto L_00996d5d; /* jl 0x996d5d */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_00996e79:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_00996e80(CPU *c) { /* FUN_10006e80 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edi, dword ptr [esp + 8] */
    (void)sub32(c, R32((uint32_t)(c->edi + 0x58u)), (uint32_t)0x2u); /* cmp dword ptr [edi + 0x58], 2 */
    if ((c->sf != c->of)) goto L_00996ed9; /* jl 0x996ed9 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov eax, dword ptr [edi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00996ed9; /* je 0x996ed9 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x34u))); /* mov eax, dword ptr [edi + 0x34] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
    if ((c->sf == c->of)) goto L_00996ed9; /* jge 0x996ed9 */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if ((c->sf == c->of)) goto L_00996ecd; /* jge 0x996ecd */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->ebp = (uint32_t)(logic32(c, 0)); /* xor ebp, ebp */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_00996ec4; /* jle 0x996ec4 */
L_00996eae:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00996eb5u); f_00996e80(c); /* call 0x996e80 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->ebx = (uint32_t)(add32(c, c->ebx, c->eax)); /* add ebx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x34u))); /* mov eax, dword ptr [edi + 0x34] */
    c->ebp = (uint32_t)(adc32(c, c->ebp, c->edx)); /* adc ebp, edx */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if ((c->sf != c->of)) goto L_00996eae; /* jl 0x996eae */
L_00996ec4:;
    c->edx = (uint32_t)(c->ebp); /* mov edx, ebp */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_00996ecd:;
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + 0x44u))); /* mov edx, dword ptr [edi + 0x44] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + c->ecx * 8))); /* mov eax, dword ptr [edx + ecx*8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edx + c->ecx * 8 + 0x4u))); /* mov edx, dword ptr [edx + ecx*8 + 4] */
    c->esp += 4; return; /* ret  */
L_00996ed9:;
    c->eax = (uint32_t)((uint32_t)0xffffff7du); /* mov eax, 0xffffff7d */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx | (uint32_t)0xffffffffu))); /* or edx, 0xffffffff */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00996ef0(CPU *c) { /* FUN_10006ef0 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x1a0u)); /* sub esp, 0x1a0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x1b0u))); /* mov esi, dword ptr [esp + 0x1b0] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x58u)), (uint32_t)0x2u); /* cmp dword ptr [esi + 0x58], 2 */
    if ((c->sf != c->of)) goto L_0099718b; /* jl 0x99718b */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->ebp = (uint32_t)(logic32(c, 0)); /* xor ebp, ebp */
    (void)sub32(c, c->eax, c->ebp); /* cmp eax, ebp */
    if (!c->zf) goto L_00996f24; /* jne 0x996f24 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (uint32_t)((uint32_t)0xffffff76u); /* mov eax, 0xffffff76 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1a0u)); /* add esp, 0x1a0 */
    c->esp += 4; return; /* ret  */
L_00996f24:;
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x1b8u))); /* mov edi, dword ptr [esp + 0x1b8] */
    (void)sub32(c, c->edi, c->ebp); /* cmp edi, ebp */
    if ((c->sf != c->of)) goto L_0099718b; /* jl 0x99718b */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x34u))); /* mov eax, dword ptr [esi + 0x34] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x38u))); /* mov ecx, dword ptr [esi + 0x38] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ecx + c->eax * 8 + 0x4u))); /* mov ebx, dword ptr [ecx + eax*8 + 4] */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->eax * 8)); /* lea ecx, [ecx + eax*8] */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    (void)sub32(c, c->edx, c->ebx); /* cmp edx, ebx */
    if ((!c->zf && c->sf == c->of)) goto L_0099718b; /* jg 0x99718b */
    if ((c->sf != c->of)) goto L_00996f55; /* jl 0x996f55 */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ecx))); /* cmp eax, dword ptr [ecx] */
    if ((!c->cf && !c->zf)) goto L_0099718b; /* ja 0x99718b */
L_00996f55:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W32((uint32_t)(c->esi + 0x50u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x50], eax */
    W32((uint32_t)(c->esi + 0x54u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x54], eax */
    PUSH32(c, 0x00996f64u); f_009971a0(c); /* call 0x9971a0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00996f6bu); f_00996b60(c); /* call 0x996b60 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov ebx, dword ptr [esp + 0x20] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->ecx = (uint32_t)((uint32_t)0x5au); /* mov ecx, 0x5a */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edi = (uint32_t)((uint32_t)(c->esp + 0x48u)); /* lea edi, [esp + 0x48] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0x10], ebp */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
L_00996f83:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x58u))); /* mov eax, dword ptr [esi + 0x58] */
    c->edi = (uint32_t)((uint32_t)0x3u); /* mov edi, 3 */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_00997018; /* jne 0x997018 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x28u)); /* lea edx, [esp + 0x28] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x48u)); /* lea eax, [esp + 0x48] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00996fa2u); f_009a2730(c); /* call 0x9a2730 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_00997018; /* jle 0x997018 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x60u))); /* mov ecx, dword ptr [esi + 0x60] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x48u))); /* mov edx, dword ptr [esi + 0x48] */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 5)); /* shl ecx, 5 */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->edx)); /* lea eax, [ecx + edx] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + c->edx + 0x1cu))); /* mov ecx, dword ptr [ecx + edx + 0x1c] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00996fcf; /* je 0x996fcf */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x28u)); /* lea ecx, [esp + 0x28] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00996fc8u); f_009a3d40(c); /* call 0x9a3d40 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
L_00996fcf:;
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (c->zf) goto L_00996fe3; /* je 0x996fe3 */
    c->edx = (uint32_t)((uint32_t)(c->esi + 0x78u)); /* lea edx, [esi + 0x78] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00996fdeu); f_009a2730(c); /* call 0x9a2730 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    goto L_00996ffa; /* jmp 0x996ffa */
L_00996fe3:;
    (void)logic32(c, (uint32_t)(c->ebp & c->ebp)); /* test ebp, ebp */
    if (c->zf) goto L_00996ffa; /* je 0x996ffa */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    c->eax = (uint32_t)(add32(c, c->eax, c->ebp)); /* add eax, ebp */
    c->eax = (uint32_t)(sar32(c, c->eax, 2)); /* sar eax, 2 */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x10], ecx */
L_00996ffa:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x38u))); /* mov ecx, dword ptr [esp + 0x38] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x3cu))); /* mov edi, dword ptr [esp + 0x3c] */
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & c->edi))); /* and edx, edi */
    (void)sub32(c, c->edx, (uint32_t)0xffffffffu); /* cmp edx, -1 */
    if (!c->zf) goto L_009970ff; /* jne 0x9970ff */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ebp, dword ptr [esp + 0x14] */
    goto L_00996f83; /* jmp 0x996f83 */
L_00997018:;
    (void)logic32(c, (uint32_t)(c->ebp & c->ebp)); /* test ebp, ebp */
    if (!c->zf) goto L_00997168; /* jne 0x997168 */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x18u)); /* lea eax, [esp + 0x18] */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x0099702du); f_00996840(c); /* call 0x996840 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf != c->of)) goto L_00997129; /* jl 0x997129 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x58u)), c->edi); /* cmp dword ptr [esi + 0x58], edi */
    if (!c->zf) goto L_00997067; /* jne 0x997067 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x18u)); /* lea ecx, [esp + 0x18] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00997047u); f_009a1f40(c); /* call 0x9a1f40 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x5cu))); /* mov ecx, dword ptr [esi + 0x5c] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
    if (c->zf) goto L_00997064; /* je 0x997064 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00997057u); f_009971a0(c); /* call 0x9971a0 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x4cu)); /* lea edx, [esp + 0x4c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00997061u); f_009a2010(c); /* call 0x9a2010 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
L_00997064:;
    (void)sub32(c, R32((uint32_t)(c->esi + 0x58u)), c->edi); /* cmp dword ptr [esi + 0x58], edi */
L_00997067:;
    if ((c->sf == c->of)) goto L_009970ce; /* jge 0x9970ce */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x18u)); /* lea eax, [esp + 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00997073u); f_009a1f40(c); /* call 0x9a1f40 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x34u))); /* mov edx, dword ptr [esi + 0x34] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    W32((uint32_t)(c->esi + 0x5cu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x5c], eax */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if ((c->zf || c->sf != c->of)) goto L_00997091; /* jle 0x997091 */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi + 0x40u))); /* mov edi, dword ptr [esi + 0x40] */
L_00997085:;
    (void)sub32(c, R32((uint32_t)(c->edi)), c->eax); /* cmp dword ptr [edi], eax */
    if (c->zf) goto L_00997091; /* je 0x997091 */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if ((c->sf != c->of)) goto L_00997085; /* jl 0x997085 */
L_00997091:;
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if (c->zf) goto L_0099713c; /* je 0x99713c */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x78u)); /* lea edi, [esi + 0x78] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->esi + 0x60u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 0x60], ecx */
    PUSH32(c, 0x009970a6u); f_009a1fa0(c); /* call 0x9a1fa0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x009970acu); f_009a26e0(c); /* call 0x9a26e0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x5cu))); /* mov ecx, dword ptr [esi + 0x5c] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x54u)); /* lea edx, [esp + 0x54] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x009970bau); f_009a1fa0(c); /* call 0x9a1fa0 */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x5cu)); /* lea eax, [esp + 0x5c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x009970c4u); f_009a26e0(c); /* call 0x9a26e0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    W32((uint32_t)(c->esi + 0x58u), (uint32_t)((uint32_t)0x3u)); /* mov dword ptr [esi + 0x58], 3 */
L_009970ce:;
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x18u)); /* lea ecx, [esp + 0x18] */
    c->edx = (uint32_t)((uint32_t)(c->esi + 0x78u)); /* lea edx, [esi + 0x78] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x009970dcu); f_009a23d0(c); /* call 0x9a23d0 */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x20u)); /* lea eax, [esp + 0x20] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x50u)); /* lea ecx, [esp + 0x50] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x009970ebu); f_009a23d0(c); /* call 0x9a23d0 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x28u)); /* lea edx, [esp + 0x28] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x009970f5u); f_009a1e50(c); /* call 0x9a1e50 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    goto L_00996f83; /* jmp 0x996f83 */
L_009970ff:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x60u))); /* mov edx, dword ptr [esi + 0x60] */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if ((c->zf || c->sf != c->of)) goto L_00997118; /* jle 0x997118 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x44u))); /* mov eax, dword ptr [esi + 0x44] */
L_00997109:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ebx, dword ptr [eax] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ebp, dword ptr [eax + 4] */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->ebx)); /* add ecx, ebx */
    c->edi = (uint32_t)(adc32(c, c->edi, c->ebp)); /* adc edi, ebp */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
    c->edx = (uint32_t)(dec32(c, c->edx)); /* dec edx */
    if (!c->zf) goto L_00997109; /* jne 0x997109 */
L_00997118:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    c->edi = (uint32_t)(sbb32(c, c->edi, c->edx)); /* sbb edi, edx */
    W32((uint32_t)(c->esi + 0x50u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 0x50], ecx */
    W32((uint32_t)(c->esi + 0x54u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0x54], edi */
    goto L_00997171; /* jmp 0x997171 */
L_00997129:;
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00997131u); f_00996e80(c); /* call 0x996e80 */
    W32((uint32_t)(c->esi + 0x50u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x50], eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    W32((uint32_t)(c->esi + 0x54u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x54], edx */
    goto L_00997171; /* jmp 0x997171 */
L_0099713c:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    W32((uint32_t)(c->esi + 0x50u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x50], eax */
    W32((uint32_t)(c->esi + 0x54u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x54], eax */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x48u)); /* lea eax, [esp + 0x48] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0099714fu); f_009a2010(c); /* call 0x9a2010 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00997155u); f_009971a0(c); /* call 0x9971a0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->eax = (uint32_t)((uint32_t)0xffffff77u); /* mov eax, 0xffffff77 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1a0u)); /* add esp, 0x1a0 */
    c->esp += 4; return; /* ret  */
L_00997168:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    W32((uint32_t)(c->esi + 0x50u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x50], eax */
    W32((uint32_t)(c->esi + 0x54u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x54], eax */
L_00997171:;
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x48u)); /* lea ecx, [esp + 0x48] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x0099717bu); f_009a2010(c); /* call 0x9a2010 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1a0u)); /* add esp, 0x1a0 */
    c->esp += 4; return; /* ret  */
L_0099718b:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (uint32_t)((uint32_t)0xffffff7du); /* mov eax, 0xffffff7d */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1a0u)); /* add esp, 0x1a0 */
    c->esp += 4; return; /* ret  */
}

void f_009971a0(CPU *c) { /* FUN_100071a0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x78u)); /* lea eax, [esi + 0x78] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x009971aeu); f_009a2010(c); /* call 0x9a2010 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x1e0u)); /* lea ecx, [esi + 0x1e0] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x009971bau); f_009a3550(c); /* call 0x9a3550 */
    c->edx = (uint32_t)((uint32_t)(c->esi + 0x250u)); /* lea edx, [esi + 0x250] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x009971c6u); f_009a31c0(c); /* call 0x9a31c0 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->esi + 0x68u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x68], eax */
    W32((uint32_t)(c->esi + 0x70u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x70], eax */
    W32((uint32_t)(c->esi + 0x58u), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [esi + 0x58], 2 */
    W32((uint32_t)(c->esi + 0x6cu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x6c], eax */
    W32((uint32_t)(c->esi + 0x74u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x74], eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_009971e0(CPU *c) { /* FUN_100071e0 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x68u)); /* sub esp, 0x68 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x74u))); /* mov ebp, dword ptr [esp + 0x74] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x009971f3u); f_00996e80(c); /* call 0x996e80 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x58u))); /* mov ecx, dword ptr [ebp + 0x58] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)sub32(c, c->ecx, (uint32_t)0x2u); /* cmp ecx, 2 */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x18], eax */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x1c], edx */
    if ((c->sf != c->of)) goto L_009975ab; /* jl 0x9975ab */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x4u))); /* mov ecx, dword ptr [ebp + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (!c->zf) goto L_0099721e; /* jne 0x99721e */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (uint32_t)((uint32_t)0xffffff76u); /* mov eax, 0xffffff76 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x68u)); /* add esp, 0x68 */
    c->esp += 4; return; /* ret  */
L_0099721e:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x84u))); /* mov ebx, dword ptr [esp + 0x84] */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if ((c->sf != c->of)) goto L_009975ab; /* jl 0x9975ab */
    if ((!c->zf && c->sf == c->of)) goto L_0099723e; /* jg 0x99723e */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x80u))); /* mov ecx, dword ptr [esp + 0x80] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->cf) goto L_009975ab; /* jb 0x9975ab */
L_0099723e:;
    (void)sub32(c, c->ebx, c->edx); /* cmp ebx, edx */
    if ((!c->zf && c->sf == c->of)) goto L_009975ab; /* jg 0x9975ab */
    if ((c->sf != c->of)) goto L_00997255; /* jl 0x997255 */
    (void)sub32(c, R32((uint32_t)(c->esp + 0x80u)), c->eax); /* cmp dword ptr [esp + 0x80], eax */
    if ((!c->cf && !c->zf)) goto L_009975ab; /* ja 0x9975ab */
L_00997255:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x34u))); /* mov edi, dword ptr [ebp + 0x34] */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x10], edi */
    if (c->sf) goto L_00997291; /* js 0x997291 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x44u))); /* mov ecx, dword ptr [ebp + 0x44] */
    c->esi = (uint32_t)((uint32_t)(c->ecx + c->edi * 8)); /* lea esi, [ecx + edi*8] */
L_00997265:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    c->edx = (uint32_t)(sbb32(c, c->edx, c->ecx)); /* sbb edx, ecx */
    (void)sub32(c, c->ebx, c->edx); /* cmp ebx, edx */
    if ((!c->zf && c->sf == c->of)) goto L_00997285; /* jg 0x997285 */
    if ((c->sf != c->of)) goto L_0099727d; /* jl 0x99727d */
    (void)sub32(c, R32((uint32_t)(c->esp + 0x80u)), c->eax); /* cmp dword ptr [esp + 0x80], eax */
    if (!c->cf) goto L_00997285; /* jae 0x997285 */
L_0099727d:;
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    c->esi = (uint32_t)(sub32(c, c->esi, (uint32_t)0x8u)); /* sub esi, 8 */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if ((c->sf == c->of)) goto L_00997265; /* jge 0x997265 */
L_00997285:;
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x10], edi */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x1c], edx */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x18], eax */
L_00997291:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x80u))); /* mov ecx, dword ptr [esp + 0x80] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->edx)); /* sbb eax, edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x38u))); /* mov edx, dword ptr [ebp + 0x38] */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x20], ecx */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x24], eax */
    c->esi = (uint32_t)(R32((uint32_t)(c->edx + c->edi * 8 + 0x8u))); /* mov esi, dword ptr [edx + edi*8 + 8] */
    W32((uint32_t)(c->esp + 0x7cu), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x7c], esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->edx + c->edi * 8))); /* mov esi, dword ptr [edx + edi*8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x44u))); /* mov edx, dword ptr [ebp + 0x44] */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x14], esi */
    c->ebx = (uint32_t)(R32((uint32_t)(c->edx + c->edi * 8))); /* mov ebx, dword ptr [edx + edi*8] */
    W32((uint32_t)(c->esp + 0x30u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x30], ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->edx = (uint32_t)(R32((uint32_t)(c->edx + c->edi * 8 + 0x4u))); /* mov edx, dword ptr [edx + edi*8 + 4] */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x28], ebx */
    W32((uint32_t)(c->esp + 0x34u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x34], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x7cu))); /* mov edx, dword ptr [esp + 0x7c] */
    (void)sub32(c, c->esi, c->edx); /* cmp esi, edx */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x2c], ebx */
    if ((c->sf == c->of)) goto L_00997439; /* jge 0x997439 */
    goto L_009972ee; /* jmp 0x9972ee */
L_009972e2:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov ecx, dword ptr [esp + 0x20] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov eax, dword ptr [esp + 0x24] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov ebx, dword ptr [esp + 0x28] */
L_009972ee:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x7cu))); /* mov edx, dword ptr [esp + 0x7c] */
    c->edx = (uint32_t)(sub32(c, c->edx, c->esi)); /* sub edx, esi */
    (void)sub32(c, c->edx, (uint32_t)0x2134u); /* cmp edx, 0x2134 */
    if ((c->sf == c->of)) goto L_00997300; /* jge 0x997300 */
    c->edi = (uint32_t)(c->esi); /* mov edi, esi */
    goto L_0099733d; /* jmp 0x99733d */
L_00997300:;
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov eax, dword ptr [esp + 0x2c] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->ebx)); /* sub ecx, ebx */
    c->edi = (uint32_t)(sbb32(c, c->edi, c->eax)); /* sbb edi, eax */
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00997316u); f_00999410(c); /* call 0x999410 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov ecx, dword ptr [esp + 0x30] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov edi, dword ptr [esp + 0x34] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->ebx)); /* sub ecx, ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov ebx, dword ptr [esp + 0x2c] */
    c->edi = (uint32_t)(sbb32(c, c->edi, c->ebx)); /* sbb edi, ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0099732fu); f_00999450(c); /* call 0x999450 */
    c->edi = (uint32_t)((uint32_t)(c->eax + c->esi + 0xffffdeccu)); /* lea edi, [eax + esi - 0x2134] */
    (void)sub32(c, c->edi, c->esi); /* cmp edi, esi */
    if ((!c->zf && c->sf == c->of)) goto L_0099733d; /* jg 0x99733d */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x1u)); /* lea edi, [esi + 1] */
L_0099733d:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x00997344u); f_00996b60(c); /* call 0x996b60 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
L_00997347:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x7cu))); /* mov edx, dword ptr [esp + 0x7c] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x48u)); /* lea eax, [esp + 0x48] */
    c->edx = (uint32_t)(sub32(c, c->edx, c->edi)); /* sub edx, edi */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x00997359u); f_00996840(c); /* call 0x996840 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, c->ebx, (uint32_t)0xffffff80u); /* cmp ebx, -0x80 */
    if (c->zf) goto L_0099758f; /* je 0x99758f */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if ((c->sf == c->of)) goto L_0099738c; /* jge 0x99738c */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x1u)); /* lea eax, [esi + 1] */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if ((c->zf || c->sf != c->of)) goto L_00997435; /* jle 0x997435 */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_0099758f; /* je 0x99758f */
    c->edi = (uint32_t)(sub32(c, c->edi, (uint32_t)0x2134u)); /* sub edi, 0x2134 */
    (void)sub32(c, c->edi, c->esi); /* cmp edi, esi */
    if ((!c->zf && c->sf == c->of)) goto L_00997406; /* jg 0x997406 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    goto L_00997406; /* jmp 0x997406 */
L_0099738c:;
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x48u)); /* lea ecx, [esp + 0x48] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00997396u); f_009a1e60(c); /* call 0x9a1e60 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov eax, dword ptr [esp + 0x28] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    (void)sub32(c, c->edx, c->eax); /* cmp edx, eax */
    W32((uint32_t)(c->esp + 0x3cu), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x3c], edx */
    if ((!c->zf && c->sf == c->of)) goto L_009973df; /* jg 0x9973df */
    if ((c->sf != c->of)) goto L_009973af; /* jl 0x9973af */
    (void)sub32(c, c->ecx, R32((uint32_t)(c->esp + 0x20u))); /* cmp ecx, dword ptr [esp + 0x20] */
    if (!c->cf) goto L_009973df; /* jae 0x9973df */
L_009973af:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x2c], edx */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x28], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov ecx, dword ptr [esp + 0x20] */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x14], ebx */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov eax, dword ptr [esp + 0x24] */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->edx)); /* sbb eax, edx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((!c->zf && c->sf == c->of)) goto L_0099742b; /* jg 0x99742b */
    if ((c->sf != c->of)) goto L_009973db; /* jl 0x9973db */
    (void)sub32(c, c->ecx, (uint32_t)0xac44u); /* cmp ecx, 0xac44 */
    if ((!c->cf && !c->zf)) goto L_0099742b; /* ja 0x99742b */
L_009973db:;
    c->edi = (uint32_t)(c->esi); /* mov edi, esi */
    goto L_00997410; /* jmp 0x997410 */
L_009973df:;
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x1u)); /* lea eax, [esi + 1] */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if ((c->zf || c->sf != c->of)) goto L_00997435; /* jle 0x997435 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x7cu))); /* mov eax, dword ptr [esp + 0x7c] */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0x8u))); /* cmp eax, dword ptr [ebp + 8] */
    if (!c->zf) goto L_0099741b; /* jne 0x99741b */
    (void)sub32(c, c->edx, R32((uint32_t)(c->ebp + 0xcu))); /* cmp edx, dword ptr [ebp + 0xc] */
    if (!c->zf) goto L_0099741b; /* jne 0x99741b */
    c->edi = (uint32_t)(sub32(c, c->edi, (uint32_t)0x2134u)); /* sub edi, 0x2134 */
    W32((uint32_t)(c->esp + 0x7cu), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x7c], ebx */
    (void)sub32(c, c->edi, c->esi); /* cmp edi, esi */
    if ((!c->zf && c->sf == c->of)) goto L_00997406; /* jg 0x997406 */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x1u)); /* lea edi, [esi + 1] */
L_00997406:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x0099740du); f_00996b60(c); /* call 0x996b60 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
L_00997410:;
    (void)sub32(c, c->esi, R32((uint32_t)(c->esp + 0x7cu))); /* cmp esi, dword ptr [esp + 0x7c] */
    if ((c->sf == c->of)) goto L_00997435; /* jge 0x997435 */
    goto L_00997347; /* jmp 0x997347 */
L_0099741b:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x3cu))); /* mov edx, dword ptr [esp + 0x3c] */
    W32((uint32_t)(c->esp + 0x7cu), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x7c], ebx */
    W32((uint32_t)(c->esp + 0x30u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x30], ecx */
    W32((uint32_t)(c->esp + 0x34u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x34], edx */
L_0099742b:;
    (void)sub32(c, c->esi, R32((uint32_t)(c->esp + 0x7cu))); /* cmp esi, dword ptr [esp + 0x7c] */
    if ((c->sf != c->of)) goto L_009972e2; /* jl 0x9972e2 */
L_00997435:;
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edi, dword ptr [esp + 0x10] */
L_00997439:;
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x0099743fu); f_009971a0(c); /* call 0x9971a0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x0099744au); f_00996b60(c); /* call 0x996b60 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x44u)); /* lea ecx, [esp + 0x44] */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x00997457u); f_00996840(c); /* call 0x996840 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf == c->of)) goto L_0099746b; /* jge 0x99746b */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (uint32_t)((uint32_t)0xfffffffeu); /* mov eax, 0xfffffffe */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x68u)); /* add esp, 0x68 */
    c->esp += 4; return; /* ret  */
L_0099746b:;
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x38u)); /* lea edx, [esp + 0x38] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00997475u); f_009a1f40(c); /* call 0x9a1f40 */
    c->esi = (uint32_t)((uint32_t)(c->ebp + 0x78u)); /* lea esi, [ebp + 0x78] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W32((uint32_t)(c->ebp + 0x5cu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x5c], eax */
    W32((uint32_t)(c->ebp + 0x60u), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 0x60], edi */
    PUSH32(c, 0x00997485u); f_009a1fa0(c); /* call 0x9a1fa0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x0099748bu); f_009a26e0(c); /* call 0x9a26e0 */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x48u)); /* lea eax, [esp + 0x48] */
    W32((uint32_t)(c->ebp + 0x58u), (uint32_t)((uint32_t)0x3u)); /* mov dword ptr [ebp + 0x58], 3 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x0099749du); f_009a23d0(c); /* call 0x9a23d0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_009974a0:;
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x58u)); /* lea ecx, [esp + 0x58] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x009974abu); f_009a2880(c); /* call 0x9a2880 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (c->zf) goto L_009974d8; /* je 0x9974d8 */
    if ((c->sf != c->of)) goto L_0099758f; /* jl 0x99758f */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x68u))); /* mov eax, dword ptr [esp + 0x68] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x6cu))); /* mov ecx, dword ptr [esp + 0x6c] */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & c->ecx))); /* and edx, ecx */
    (void)sub32(c, c->edx, (uint32_t)0xffffffffu); /* cmp edx, -1 */
    if (!c->zf) goto L_00997537; /* jne 0x997537 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x009974d3u); f_009a2730(c); /* call 0x9a2730 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    goto L_009974a0; /* jmp 0x9974a0 */
L_009974d8:;
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x38u)); /* lea eax, [esp + 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x009974e3u); f_00996a90(c); /* call 0x996a90 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if ((c->sf != c->of)) goto L_0099758f; /* jl 0x99758f */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x38u)); /* lea ecx, [esp + 0x38] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x009974fau); f_009a1e60(c); /* call 0x9a1e60 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    (void)sub32(c, c->edx, (uint32_t)0xffffffffu); /* cmp edx, -1 */
    if ((!c->zf && c->sf == c->of)) goto L_00997525; /* jg 0x997525 */
    if ((c->sf != c->of)) goto L_00997509; /* jl 0x997509 */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if ((!c->cf && !c->zf)) goto L_00997525; /* ja 0x997525 */
L_00997509:;
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x38u)); /* lea edx, [esp + 0x38] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00997513u); f_009a1e30(c); /* call 0x9a1e30 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00997525; /* je 0x997525 */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 8], eax */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp + 0xc], edx */
    goto L_009974d8; /* jmp 0x9974d8 */
L_00997525:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x0099752cu); f_00996ef0(c); /* call 0x996ef0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x68u)); /* add esp, 0x68 */
    c->esp += 4; return; /* ret  */
L_00997537:;
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov esi, dword ptr [esp + 0x18] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov edx, dword ptr [esp + 0x1c] */
    c->eax = (uint32_t)(add32(c, c->eax, c->esi)); /* add eax, esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x84u))); /* mov esi, dword ptr [esp + 0x84] */
    c->ecx = (uint32_t)(adc32(c, c->ecx, c->edx)); /* adc ecx, edx */
    W32((uint32_t)(c->ebp + 0x50u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x50], eax */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    W32((uint32_t)(c->ebp + 0x54u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp + 0x54], ecx */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if ((!c->zf && c->sf == c->of)) goto L_0099758a; /* jg 0x99758a */
    if ((c->sf != c->of)) goto L_00997566; /* jl 0x997566 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x50u))); /* mov ecx, dword ptr [ebp + 0x50] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x80u))); /* mov eax, dword ptr [esp + 0x80] */
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
    if ((!c->cf && !c->zf)) goto L_0099758a; /* ja 0x99758a */
L_00997566:;
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x0099756eu); f_00996e80(c); /* call 0x996e80 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)sub32(c, c->esi, c->edx); /* cmp esi, edx */
    if ((!c->zf && c->sf == c->of)) goto L_0099758a; /* jg 0x99758a */
    if ((c->sf != c->of)) goto L_00997580; /* jl 0x997580 */
    (void)sub32(c, R32((uint32_t)(c->esp + 0x80u)), c->eax); /* cmp dword ptr [esp + 0x80], eax */
    if ((!c->cf && !c->zf)) goto L_0099758a; /* ja 0x99758a */
L_00997580:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x68u)); /* add esp, 0x68 */
    c->esp += 4; return; /* ret  */
L_0099758a:;
    c->ebx = (uint32_t)((uint32_t)0xffffff7fu); /* mov ebx, 0xffffff7f */
L_0099758f:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    W32((uint32_t)(c->ebp + 0x50u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x50], eax */
    W32((uint32_t)(c->ebp + 0x54u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x54], eax */
    PUSH32(c, 0x0099759eu); f_009971a0(c); /* call 0x9971a0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x68u)); /* add esp, 0x68 */
    c->esp += 4; return; /* ret  */
L_009975ab:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (uint32_t)((uint32_t)0xffffff7du); /* mov eax, 0xffffff7d */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x68u)); /* add esp, 0x68 */
    c->esp += 4; return; /* ret  */
}

void f_009975c0(CPU *c) { /* FUN_100075c0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x30u)); /* sub esp, 0x30 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x40u))); /* mov esi, dword ptr [esp + 0x40] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    PUSH32(c, 0x009975ddu); f_009971e0(c); /* call 0x9971e0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf != c->of)) goto L_0099780e; /* jl 0x99780e */
    c->ebx = (uint32_t)((uint32_t)(c->esi + 0x78u)); /* lea ebx, [esi + 0x78] */
L_009975eb:;
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x20u)); /* lea edx, [esp + 0x20] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x009975f6u); f_009a2880(c); /* call 0x9a2880 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_009976b9; /* jle 0x9976b9 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x60u))); /* mov ecx, dword ptr [esi + 0x60] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esi + 0x48u))); /* mov ebp, dword ptr [esi + 0x48] */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 5)); /* shl ecx, 5 */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x20u)); /* lea eax, [esp + 0x20] */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->ebp)); /* add ecx, ebp */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00997617u); f_009a3d40(c); /* call 0x9a3d40 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->ebp = (uint32_t)(c->eax); /* mov ebp, eax */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00997637; /* je 0x997637 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov ecx, dword ptr [esi + 0x50] */
    c->eax = (uint32_t)((uint32_t)(c->edi + c->ebp)); /* lea eax, [edi + ebp] */
    c->eax = (uint32_t)(sar32(c, c->eax, 2)); /* sar eax, 2 */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    W32((uint32_t)(c->esi + 0x50u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 0x50], ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x54u))); /* mov eax, dword ptr [esi + 0x54] */
    c->eax = (uint32_t)(adc32(c, c->eax, c->edx)); /* adc eax, edx */
    W32((uint32_t)(c->esi + 0x54u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x54], eax */
L_00997637:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x48u))); /* mov edx, dword ptr [esi + 0x48] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00997642u); f_009a2930(c); /* call 0x9a2930 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov ecx, dword ptr [esi + 0x50] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi + 0x54u))); /* mov edi, dword ptr [esi + 0x54] */
    c->eax = (uint32_t)(add32(c, c->eax, c->ebp)); /* add eax, ebp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->eax = (uint32_t)(sar32(c, c->eax, 2)); /* sar eax, 2 */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4cu))); /* mov ecx, dword ptr [esp + 0x4c] */
    c->edx = (uint32_t)(adc32(c, c->edx, c->edi)); /* adc edx, edi */
    (void)sub32(c, c->edx, c->ecx); /* cmp edx, ecx */
    if ((!c->zf && c->sf == c->of)) goto L_00997769; /* jg 0x997769 */
    if ((c->sf != c->of)) goto L_0099766d; /* jl 0x99766d */
    (void)sub32(c, c->eax, R32((uint32_t)(c->esp + 0x48u))); /* cmp eax, dword ptr [esp + 0x48] */
    if (!c->cf) goto L_00997769; /* jae 0x997769 */
L_0099766d:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00997675u); f_009a2730(c); /* call 0x9a2730 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x3cu))); /* mov eax, dword ptr [esp + 0x3c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x38u))); /* mov ecx, dword ptr [esp + 0x38] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if ((c->sf != c->of)) goto L_009976b2; /* jl 0x9976b2 */
    if ((!c->zf && c->sf == c->of)) goto L_0099768c; /* jg 0x99768c */
    (void)sub32(c, c->ecx, (uint32_t)0xffffffffu); /* cmp ecx, -1 */
    if ((c->cf || c->zf)) goto L_009976b2; /* jbe 0x9976b2 */
L_0099768c:;
    W32((uint32_t)(c->esi + 0x50u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 0x50], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x60u))); /* mov ecx, dword ptr [esi + 0x60] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    W32((uint32_t)(c->esi + 0x54u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x54], eax */
    if ((c->zf || c->sf != c->of)) goto L_009976b2; /* jle 0x9976b2 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x44u))); /* mov eax, dword ptr [esi + 0x44] */
L_0099769c:;
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->edi = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov edi, dword ptr [eax + 4] */
    { uint32_t a_ = (uint32_t)(c->esi + 0x50u); W32(a_, (uint32_t)(add32(c, R32(a_), c->edx))); } /* add dword ptr [esi + 0x50], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x54u))); /* mov edx, dword ptr [esi + 0x54] */
    c->edx = (uint32_t)(adc32(c, c->edx, c->edi)); /* adc edx, edi */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    W32((uint32_t)(c->esi + 0x54u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x54], edx */
    if (!c->zf) goto L_0099769c; /* jne 0x99769c */
L_009976b2:;
    c->edi = (uint32_t)(c->ebp); /* mov edi, ebp */
    goto L_009975eb; /* jmp 0x9975eb */
L_009976b9:;
    if ((c->sf == c->of)) goto L_009976c4; /* jge 0x9976c4 */
    (void)sub32(c, c->eax, (uint32_t)0xfffffffdu); /* cmp eax, -3 */
    if (!c->zf) goto L_00997769; /* jne 0x997769 */
L_009976c4:;
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x10u)); /* lea eax, [esp + 0x10] */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x009976d1u); f_00996840(c); /* call 0x996840 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf != c->of)) goto L_00997769; /* jl 0x997769 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x10u)); /* lea ecx, [esp + 0x10] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x009976e6u); f_009a1f40(c); /* call 0x9a1f40 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x5cu))); /* mov ecx, dword ptr [esi + 0x5c] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
    if (c->zf) goto L_009976f9; /* je 0x9976f9 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x009976f6u); f_009971a0(c); /* call 0x9971a0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_009976f9:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x58u))); /* mov eax, dword ptr [esi + 0x58] */
    c->ebp = (uint32_t)((uint32_t)0x3u); /* mov ebp, 3 */
    (void)sub32(c, c->eax, c->ebp); /* cmp eax, ebp */
    if ((c->sf == c->of)) goto L_00997749; /* jge 0x997749 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x10u)); /* lea edx, [esp + 0x10] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x0099770fu); f_009a1f40(c); /* call 0x9a1f40 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x34u))); /* mov edx, dword ptr [esi + 0x34] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    W32((uint32_t)(c->esi + 0x5cu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x5c], eax */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if ((c->zf || c->sf != c->of)) goto L_0099772d; /* jle 0x99772d */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi + 0x40u))); /* mov edi, dword ptr [esi + 0x40] */
L_00997721:;
    (void)sub32(c, R32((uint32_t)(c->edi)), c->eax); /* cmp dword ptr [edi], eax */
    if (c->zf) goto L_0099772d; /* je 0x99772d */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if ((c->sf != c->of)) goto L_00997721; /* jl 0x997721 */
L_0099772d:;
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if (c->zf) goto L_0099775c; /* je 0x99775c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    W32((uint32_t)(c->esi + 0x60u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 0x60], ecx */
    PUSH32(c, 0x0099773bu); f_009a1fa0(c); /* call 0x9a1fa0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00997741u); f_009a26e0(c); /* call 0x9a26e0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->esi + 0x58u), (uint32_t)(c->ebp)); /* mov dword ptr [esi + 0x58], ebp */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
L_00997749:;
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x10u)); /* lea eax, [esp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00997754u); f_009a23d0(c); /* call 0x9a23d0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    goto L_009975eb; /* jmp 0x9975eb */
L_0099775c:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (uint32_t)((uint32_t)0xffffff77u); /* mov eax, 0xffffff77 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x30u)); /* add esp, 0x30 */
    c->esp += 4; return; /* ret  */
L_00997769:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x0099776fu); f_00997820(c); /* call 0x997820 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x54u))); /* mov ecx, dword ptr [esi + 0x54] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x50u))); /* mov eax, dword ptr [esp + 0x50] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
    if ((!c->zf && c->sf == c->of)) goto L_0099780c; /* jg 0x99780c */
    if ((c->sf != c->of)) goto L_0099778e; /* jl 0x99778e */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov edx, dword ptr [esi + 0x50] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x48u))); /* mov eax, dword ptr [esp + 0x48] */
    (void)sub32(c, c->edx, c->eax); /* cmp edx, eax */
    if (!c->cf) goto L_0099780c; /* jae 0x99780c */
L_0099778e:;
    c->ebp = (uint32_t)((uint32_t)(c->esi + 0x1e0u)); /* lea ebp, [esi + 0x1e0] */
L_00997794:;
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x48u))); /* mov edi, dword ptr [esp + 0x48] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    c->edi = (uint32_t)(sub32(c, c->edi, c->eax)); /* sub edi, eax */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x44u)); /* lea eax, [esp + 0x44] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x009977a8u); f_009a3b50(c); /* call 0x9a3b50 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    if ((c->zf || c->sf != c->of)) goto L_009977b3; /* jle 0x9977b3 */
    c->ebx = (uint32_t)(c->edi); /* mov ebx, edi */
L_009977b3:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x009977bau); f_009a3bb0(c); /* call 0x9a3bb0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov ecx, dword ptr [esi + 0x50] */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    W32((uint32_t)(c->esi + 0x50u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 0x50], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x54u))); /* mov ecx, dword ptr [esi + 0x54] */
    c->ecx = (uint32_t)(adc32(c, c->ecx, c->edx)); /* adc ecx, edx */
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    W32((uint32_t)(c->esi + 0x54u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 0x54], ecx */
    if ((c->sf == c->of)) goto L_009977f4; /* jge 0x9977f4 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x009977dcu); f_00997870(c); /* call 0x997870 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((!c->zf && c->sf == c->of)) goto L_009977f4; /* jg 0x9977f4 */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x009977ebu); f_00996e80(c); /* call 0x996e80 */
    W32((uint32_t)(c->esi + 0x50u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x50], eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    W32((uint32_t)(c->esi + 0x54u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x54], edx */
L_009977f4:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x54u))); /* mov ecx, dword ptr [esi + 0x54] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4cu))); /* mov eax, dword ptr [esp + 0x4c] */
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
    if ((c->sf != c->of)) goto L_00997794; /* jl 0x997794 */
    if ((!c->zf && c->sf == c->of)) goto L_0099780c; /* jg 0x99780c */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov edx, dword ptr [esi + 0x50] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x48u))); /* mov eax, dword ptr [esp + 0x48] */
    (void)sub32(c, c->edx, c->eax); /* cmp edx, eax */
    if (c->cf) goto L_00997794; /* jb 0x997794 */
L_0099780c:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_0099780e:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x30u)); /* add esp, 0x30 */
    c->esp += 4; return; /* ret  */
}

void f_00997820(CPU *c) { /* FUN_10007820 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x58u)), (uint32_t)0x3u); /* cmp dword ptr [esi + 0x58], 3 */
    if (!c->zf) goto L_0099786c; /* jne 0x99786c */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x1e0u)); /* lea edi, [esi + 0x1e0] */
    if (c->zf) goto L_00997847; /* je 0x997847 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x60u))); /* mov eax, dword ptr [esi + 0x60] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x48u))); /* mov ecx, dword ptr [esi + 0x48] */
    c->eax = (uint32_t)(shl32(c, c->eax, 5)); /* shl eax, 5 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    goto L_0099784b; /* jmp 0x99784b */
L_00997847:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x48u))); /* mov ecx, dword ptr [esi + 0x48] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
L_0099784b:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00997851u); f_009a37b0(c); /* call 0x9a37b0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->edx = (uint32_t)((uint32_t)(c->esi + 0x250u)); /* lea edx, [esi + 0x250] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00997861u); f_009a3080(c); /* call 0x9a3080 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    W32((uint32_t)(c->esi + 0x58u), (uint32_t)((uint32_t)0x4u)); /* mov dword ptr [esi + 0x58], 4 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_0099786c:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00997870(CPU *c) { /* FUN_10007870 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x30u)); /* sub esp, 0x30 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x40u))); /* mov esi, dword ptr [esp + 0x40] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
L_0099787b:;
    (void)sub32(c, R32((uint32_t)(c->esi + 0x58u)), (uint32_t)0x4u); /* cmp dword ptr [esi + 0x58], 4 */
    if (!c->zf) goto L_009978c5; /* jne 0x9978c5 */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x78u)); /* lea edi, [esi + 0x78] */
L_00997884:;
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x20u)); /* lea eax, [esp + 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x0099788fu); f_009a2730(c); /* call 0x9a2730 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (c->zf) goto L_009979f4; /* je 0x9979f4 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_009978c5; /* jle 0x9978c5 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov ebx, dword ptr [esp + 0x30] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov ebp, dword ptr [esp + 0x34] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x20u)); /* lea ecx, [esp + 0x20] */
    c->edx = (uint32_t)((uint32_t)(c->esi + 0x250u)); /* lea edx, [esi + 0x250] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x009978b8u); f_009a3be0(c); /* call 0x9a3be0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00997a01; /* je 0x997a01 */
    goto L_00997884; /* jmp 0x997884 */
L_009978c5:;
    (void)sub32(c, R32((uint32_t)(c->esi + 0x58u)), (uint32_t)0x2u); /* cmp dword ptr [esi + 0x58], 2 */
    if ((c->sf != c->of)) goto L_00997949; /* jl 0x997949 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x48u))); /* mov eax, dword ptr [esp + 0x48] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00997abe; /* je 0x997abe */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x10u)); /* lea eax, [esp + 0x10] */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x009978e4u); f_00996840(c); /* call 0x996840 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf != c->of)) goto L_00997ac8; /* jl 0x997ac8 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ecx, dword ptr [esp + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x58u))); /* mov eax, dword ptr [esi + 0x58] */
    (void)sub32(c, c->eax, (uint32_t)0x4u); /* cmp eax, 4 */
    c->edx = (uint32_t)((uint32_t)(c->ecx * 8)); /* lea edx, [ecx*8] */
    W32((uint32_t)(c->esp + 0x44u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x44], edx */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x44u))); /* fild dword ptr [esp + 0x44] */
    ST(0) = FPRES(c, ST(0) + RF64((uint32_t)(c->esi + 0x68u))); /* fadd qword ptr [esi + 0x68] */
    WF64((uint32_t)(c->esi + 0x68u), ST(0)); FPOP(c); /* fstp qword ptr [esi + 0x68] */
    if (!c->zf) goto L_00997949; /* jne 0x997949 */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x10u)); /* lea eax, [esp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0099791au); f_009a1f40(c); /* call 0x9a1f40 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x5cu))); /* mov ecx, dword ptr [esi + 0x5c] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
    if (c->zf) goto L_00997949; /* je 0x997949 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x0099792au); f_009971a0(c); /* call 0x9971a0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00997949; /* jne 0x997949 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x48u))); /* mov ecx, dword ptr [esi + 0x48] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x0099793du); f_009a2980(c); /* call 0x9a2980 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x4cu))); /* mov edx, dword ptr [esi + 0x4c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00997946u); f_009a28c0(c); /* call 0x9a28c0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
L_00997949:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x58u))); /* mov eax, dword ptr [esi + 0x58] */
    (void)sub32(c, c->eax, (uint32_t)0x4u); /* cmp eax, 4 */
    if (c->zf) goto L_009979de; /* je 0x9979de */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if ((c->sf == c->of)) goto L_009979d5; /* jge 0x9979d5 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009979b0; /* je 0x9979b0 */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x10u)); /* lea eax, [esp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0099796bu); f_009a1f40(c); /* call 0x9a1f40 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x34u))); /* mov edx, dword ptr [esi + 0x34] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    W32((uint32_t)(c->esi + 0x5cu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x5c], eax */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if ((c->zf || c->sf != c->of)) goto L_00997989; /* jle 0x997989 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esi + 0x40u))); /* mov ebx, dword ptr [esi + 0x40] */
L_0099797d:;
    (void)sub32(c, R32((uint32_t)(c->ebx)), c->eax); /* cmp dword ptr [ebx], eax */
    if (c->zf) goto L_00997989; /* je 0x997989 */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x4u)); /* add ebx, 4 */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if ((c->sf != c->of)) goto L_0099797d; /* jl 0x99797d */
L_00997989:;
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if (c->zf) goto L_00997ad5; /* je 0x997ad5 */
    c->ebx = (uint32_t)((uint32_t)(c->esi + 0x78u)); /* lea ebx, [esi + 0x78] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    W32((uint32_t)(c->esi + 0x60u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 0x60], ecx */
    PUSH32(c, 0x0099799eu); f_009a1fa0(c); /* call 0x9a1fa0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x009979a4u); f_009a26e0(c); /* call 0x9a26e0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->esi + 0x58u), (uint32_t)((uint32_t)0x3u)); /* mov dword ptr [esi + 0x58], 3 */
    goto L_009979d5; /* jmp 0x9979d5 */
L_009979b0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4cu))); /* mov eax, dword ptr [esi + 0x4c] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x10u)); /* lea ecx, [esp + 0x10] */
    c->edx = (uint32_t)((uint32_t)(c->esi + 0x5cu)); /* lea edx, [esi + 0x5c] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x48u))); /* mov ecx, dword ptr [esi + 0x48] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x009979c7u); f_00996700(c); /* call 0x996700 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00997ada; /* jne 0x997ada */
    { uint32_t a_ = (uint32_t)(c->esi + 0x60u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [esi + 0x60] */
L_009979d5:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x009979dbu); f_00997820(c); /* call 0x997820 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_009979de:;
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x10u)); /* lea edx, [esp + 0x10] */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x78u)); /* lea eax, [esi + 0x78] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x009979ecu); f_009a23d0(c); /* call 0x9a23d0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    goto L_0099787b; /* jmp 0x99787b */
L_009979f4:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (uint32_t)((uint32_t)0xfffffffdu); /* mov eax, 0xfffffffd */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x30u)); /* add esp, 0x30 */
    c->esp += 4; return; /* ret  */
L_00997a01:;
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x1e0u)); /* lea edi, [esi + 0x1e0] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00997a0fu); f_009a3b50(c); /* call 0x9a3b50 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x250u)); /* lea ecx, [esi + 0x250] */
    W32((uint32_t)(c->esp + 0x4cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x4c], eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00997a20u); f_009a37e0(c); /* call 0x9a37e0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00997a28u); f_009a3b50(c); /* call 0x9a3b50 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x5cu))); /* mov ecx, dword ptr [esp + 0x5c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x3cu))); /* mov edx, dword ptr [esp + 0x3c] */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    W32((uint32_t)(c->esp + 0x5cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x5c], eax */
    c->eax = (uint32_t)((uint32_t)(c->edx * 8)); /* lea eax, [edx*8] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x5cu))); /* fild dword ptr [esp + 0x5c] */
    W32((uint32_t)(c->esp + 0x5cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x5c], eax */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & c->ebp))); /* and ecx, ebp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    (void)sub32(c, c->ecx, (uint32_t)0xffffffffu); /* cmp ecx, -1 */
    ST(0) = FPRES(c, ST(0) + RF64((uint32_t)(c->esi + 0x70u))); /* fadd qword ptr [esi + 0x70] */
    WF64((uint32_t)(c->esi + 0x70u), ST(0)); FPOP(c); /* fstp qword ptr [esi + 0x70] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x44u))); /* fild dword ptr [esp + 0x44] */
    ST(0) = FPRES(c, ST(0) + RF64((uint32_t)(c->esi + 0x68u))); /* fadd qword ptr [esi + 0x68] */
    WF64((uint32_t)(c->esi + 0x68u), ST(0)); FPOP(c); /* fstp qword ptr [esi + 0x68] */
    if (c->zf) goto L_00997ab1; /* je 0x997ab1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov eax, dword ptr [esp + 0x2c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00997ab1; /* jne 0x997ab1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00997a79; /* je 0x997a79 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x60u))); /* mov edx, dword ptr [esi + 0x60] */
    W32((uint32_t)(c->esp + 0x44u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x44], edx */
    goto L_00997a81; /* jmp 0x997a81 */
L_00997a79:;
    W32((uint32_t)(c->esp + 0x44u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x44], 0 */
L_00997a81:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00997a89u); f_009a3b50(c); /* call 0x9a3b50 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4cu))); /* mov ecx, dword ptr [esp + 0x4c] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    c->ebx = (uint32_t)(sub32(c, c->ebx, c->eax)); /* sub ebx, eax */
    c->ebp = (uint32_t)(sbb32(c, c->ebp, c->edx)); /* sbb ebp, edx */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if ((c->zf || c->sf != c->of)) goto L_00997aab; /* jle 0x997aab */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x44u))); /* mov eax, dword ptr [esi + 0x44] */
L_00997a9c:;
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->edi = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov edi, dword ptr [eax + 4] */
    c->ebx = (uint32_t)(add32(c, c->ebx, c->edx)); /* add ebx, edx */
    c->ebp = (uint32_t)(adc32(c, c->ebp, c->edi)); /* adc ebp, edi */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (!c->zf) goto L_00997a9c; /* jne 0x997a9c */
L_00997aab:;
    W32((uint32_t)(c->esi + 0x50u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x50], ebx */
    W32((uint32_t)(c->esi + 0x54u), (uint32_t)(c->ebp)); /* mov dword ptr [esi + 0x54], ebp */
L_00997ab1:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x30u)); /* add esp, 0x30 */
    c->esp += 4; return; /* ret  */
L_00997abe:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x30u)); /* add esp, 0x30 */
    c->esp += 4; return; /* ret  */
L_00997ac8:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (uint32_t)((uint32_t)0xfffffffeu); /* mov eax, 0xfffffffe */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x30u)); /* add esp, 0x30 */
    c->esp += 4; return; /* ret  */
L_00997ad5:;
    c->eax = (uint32_t)((uint32_t)0xffffff77u); /* mov eax, 0xffffff77 */
L_00997ada:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x30u)); /* add esp, 0x30 */
    c->esp += 4; return; /* ret  */
}

void f_00997af0(CPU *c) { /* FUN_10007af0 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov eax, dword ptr [edx + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00997b26; /* je 0x997b26 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if ((c->sf == c->of)) goto L_00997b15; /* jge 0x997b15 */
    (void)sub32(c, R32((uint32_t)(c->edx + 0x58u)), (uint32_t)0x3u); /* cmp dword ptr [edx + 0x58], 3 */
    if ((c->sf != c->of)) goto L_00997b26; /* jl 0x997b26 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x60u))); /* mov eax, dword ptr [edx + 0x60] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0x48u))); /* mov ecx, dword ptr [edx + 0x48] */
    c->eax = (uint32_t)(shl32(c, c->eax, 5)); /* shl eax, 5 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    c->esp += 4; return; /* ret  */
L_00997b15:;
    (void)sub32(c, c->ecx, R32((uint32_t)(c->edx + 0x34u))); /* cmp ecx, dword ptr [edx + 0x34] */
    if ((c->sf != c->of)) goto L_00997b1d; /* jl 0x997b1d */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_00997b1d:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x48u))); /* mov eax, dword ptr [edx + 0x48] */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 5)); /* shl ecx, 5 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    c->esp += 4; return; /* ret  */
L_00997b26:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x48u))); /* mov eax, dword ptr [edx + 0x48] */
    c->esp += 4; return; /* ret  */
}

void f_00997b30(CPU *c) { /* FUN_10007b30 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00997b3eu); f_009ae820(c); /* call 0x9ae820 */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x10], eax */
    (void)sub32(c, R32((uint32_t)(c->edi + 0x58u)), (uint32_t)0x2u); /* cmp dword ptr [edi + 0x58], 2 */
    if ((c->sf == c->of)) goto L_00997b56; /* jge 0x997b56 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)((uint32_t)0xffffff7du); /* mov eax, 0xffffff7d */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
L_00997b56:;
    c->ebx = (uint32_t)((uint32_t)0x3u); /* mov ebx, 3 */
L_00997b5b:;
    (void)sub32(c, R32((uint32_t)(c->edi + 0x58u)), c->ebx); /* cmp dword ptr [edi + 0x58], ebx */
    if ((c->sf != c->of)) goto L_00997b7c; /* jl 0x997b7c */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    c->ecx = (uint32_t)((uint32_t)(c->edi + 0x1e0u)); /* lea ecx, [edi + 0x1e0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00997b70u); f_009a3b50(c); /* call 0x9a3b50 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 8], esi */
    if (!c->zf) goto L_00997b9f; /* jne 0x997b9f */
L_00997b7c:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00997b84u); f_00997870(c); /* call 0x997870 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)sub32(c, c->eax, (uint32_t)0xfffffffeu); /* cmp eax, -2 */
    if (c->zf) goto L_00997b96; /* je 0x997b96 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_00997e75; /* jle 0x997e75 */
    goto L_00997b5b; /* jmp 0x997b5b */
L_00997b96:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
L_00997b9f:;
    if ((c->zf || c->sf != c->of)) goto L_00997e73; /* jle 0x997e73 */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00997badu); f_00997af0(c); /* call 0x997af0 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ebx, dword ptr [eax + 4] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov edi, dword ptr [ebp + 0x18] */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    { int64_t r_ = (int64_t)(int32_t)c->ecx * (int32_t)c->edi; c->ecx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul ecx, edi */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)c->ecx; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00997bbcu, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0xc], ebx */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 0x18], ecx */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if ((c->zf || c->sf != c->of)) goto L_00997bd0; /* jle 0x997bd0 */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_00997bd0:;
    (void)sub32(c, c->edi, (uint32_t)0x1u); /* cmp edi, 1 */
    if (!c->zf) goto L_00997c49; /* jne 0x997c49 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov edx, dword ptr [ebp + 0x1c] */
    c->edx = (uint32_t)(neg32(c, c->edx)); /* neg edx */
    c->edx = (uint32_t)(sbb32(c, c->edx, c->edx)); /* sbb edx, edx */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0xffffff80u))); /* and edx, 0xffffff80 */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x80u)); /* add edx, 0x80 */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if ((c->zf || c->sf != c->of)) goto L_00997e34; /* jle 0x997e34 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
L_00997bf2:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if ((c->zf || c->sf != c->of)) goto L_00997c3a; /* jle 0x997c3a */
L_00997bf8:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + c->eax * 4))); /* mov ecx, dword ptr [ecx + eax*4] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + c->edi * 4))); /* fld dword ptr [ecx + edi*4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x9b5474u))); /* fmul dword ptr [0x10025474] */
    WF64((uint32_t)(c->ebp + 0xffffffecu), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0x14] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xffffffecu))); /* fld qword ptr [ebp - 0x14] */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)fpu_to_int32(c, ST(0))); FPOP(c); /* fistp dword ptr [ebp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    (void)sub32(c, c->ecx, (uint32_t)0x7fu); /* cmp ecx, 0x7f */
    if ((c->zf || c->sf != c->of)) goto L_00997c1f; /* jle 0x997c1f */
    c->ecx = (uint32_t)((uint32_t)0x7fu); /* mov ecx, 0x7f */
    goto L_00997c29; /* jmp 0x997c29 */
L_00997c1f:;
    (void)sub32(c, c->ecx, (uint32_t)0xffffff80u); /* cmp ecx, -0x80 */
    if ((c->sf == c->of)) goto L_00997c29; /* jge 0x997c29 */
    c->ecx = (uint32_t)((uint32_t)0xffffff80u); /* mov ecx, 0xffffff80 */
L_00997c29:;
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(((uint8_t)c->edx)); /* mov bl, dl */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(add8(c, ((uint8_t)c->ebx), ((uint8_t)c->ecx))); /* add bl, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [esi], bl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if ((c->sf != c->of)) goto L_00997bf8; /* jl 0x997bf8 */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
L_00997c3a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if ((c->sf != c->of)) goto L_00997bf2; /* jl 0x997bf2 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    goto L_00997e34; /* jmp 0x997e34 */
L_00997c49:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov eax, dword ptr [ebp + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov ecx, dword ptr [ebp + 0x14] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov edi, dword ptr [ebp - 0x10] */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    c->edx = (uint32_t)(neg32(c, c->edx)); /* neg edx */
    c->edx = (uint32_t)(sbb32(c, c->edx, c->edx)); /* sbb edx, edx */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0xffff8000u))); /* and edx, 0xffff8000 */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x8000u)); /* add edx, 0x8000 */
    (void)sub32(c, c->edi, c->ecx); /* cmp edi, ecx */
    W32((uint32_t)(c->ebp + 0x1cu), (uint32_t)(c->edx)); /* mov dword ptr [ebp + 0x1c], edx */
    if (!c->zf) goto L_00997d63; /* jne 0x997d63 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00997ce4; /* je 0x997ce4 */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if ((c->zf || c->sf != c->of)) goto L_00997e34; /* jle 0x997e34 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp + 0xc], edx */
L_00997c83:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + c->edi * 4))); /* mov ecx, dword ptr [eax + edi*4] */
    if ((c->zf || c->sf != c->of)) goto L_00997cd1; /* jle 0x997cd1 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov esi, dword ptr [ebp - 8] */
    c->ebx = (uint32_t)(add32(c, c->ebx, c->ebx)); /* add ebx, ebx */
L_00997c92:;
    FPUSH(c, (double)RF32((uint32_t)(c->ecx))); /* fld dword ptr [ecx] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x9b5470u))); /* fmul dword ptr [0x10025470] */
    WF64((uint32_t)(c->ebp + 0xffffffecu), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0x14] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xffffffecu))); /* fld qword ptr [ebp - 0x14] */
    W32((uint32_t)(c->ebp + 0x1cu), (uint32_t)fpu_to_int32(c, ST(0))); FPOP(c); /* fistp dword ptr [ebp + 0x1c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov eax, dword ptr [ebp + 0x1c] */
    (void)sub32(c, c->eax, (uint32_t)0x7fffu); /* cmp eax, 0x7fff */
    if ((c->zf || c->sf != c->of)) goto L_00997cb4; /* jle 0x997cb4 */
    c->eax = (uint32_t)((uint32_t)0x7fffu); /* mov eax, 0x7fff */
    goto L_00997cc0; /* jmp 0x997cc0 */
L_00997cb4:;
    (void)sub32(c, c->eax, (uint32_t)0xffff8000u); /* cmp eax, 0xffff8000 */
    if ((c->sf == c->of)) goto L_00997cc0; /* jge 0x997cc0 */
    c->eax = (uint32_t)((uint32_t)0xffff8000u); /* mov eax, 0xffff8000 */
L_00997cc0:;
    W16((uint32_t)(c->edx), (uint16_t)(((uint16_t)c->eax))); /* mov word ptr [edx], ax */
    c->edx = (uint32_t)(add32(c, c->edx, c->ebx)); /* add edx, ebx */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    if (!c->zf) goto L_00997c92; /* jne 0x997c92 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ebx, dword ptr [ebp - 0xc] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov esi, dword ptr [ebp - 8] */
L_00997cd1:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x2u)); /* add edx, 2 */
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp + 0xc], edx */
    if ((c->sf != c->of)) goto L_00997c83; /* jl 0x997c83 */
    goto L_00997e34; /* jmp 0x997e34 */
L_00997ce4:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    W32((uint32_t)(c->ebp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x18], eax */
    if ((c->zf || c->sf != c->of)) goto L_00997e34; /* jle 0x997e34 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [ebp + 0xc], ecx */
L_00997cf7:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov edx, dword ptr [ebp - 4] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    c->edx = (uint32_t)(R32((uint32_t)(c->edx + c->eax * 4))); /* mov edx, dword ptr [edx + eax*4] */
    if ((c->zf || c->sf != c->of)) goto L_00997d4d; /* jle 0x997d4d */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov esi, dword ptr [ebp - 8] */
    c->ebx = (uint32_t)(add32(c, c->ebx, c->ebx)); /* add ebx, ebx */
L_00997d06:;
    FPUSH(c, (double)RF32((uint32_t)(c->edx))); /* fld dword ptr [edx] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x9b5470u))); /* fmul dword ptr [0x10025470] */
    WF64((uint32_t)(c->ebp + 0xffffffecu), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0x14] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xffffffecu))); /* fld qword ptr [ebp - 0x14] */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)fpu_to_int32(c, ST(0))); FPOP(c); /* fistp dword ptr [ebp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    (void)sub32(c, c->eax, (uint32_t)0x7fffu); /* cmp eax, 0x7fff */
    if ((c->zf || c->sf != c->of)) goto L_00997d28; /* jle 0x997d28 */
    c->eax = (uint32_t)((uint32_t)0x7fffu); /* mov eax, 0x7fff */
    goto L_00997d34; /* jmp 0x997d34 */
L_00997d28:;
    (void)sub32(c, c->eax, (uint32_t)0xffff8000u); /* cmp eax, 0xffff8000 */
    if ((c->sf == c->of)) goto L_00997d34; /* jge 0x997d34 */
    c->eax = (uint32_t)((uint32_t)0xffff8000u); /* mov eax, 0xffff8000 */
L_00997d34:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov edi, dword ptr [ebp + 0x1c] */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x4u)); /* add edx, 4 */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    W16((uint32_t)(c->ecx), (uint16_t)(((uint16_t)c->edi))); /* mov word ptr [ecx], di */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->ebx)); /* add ecx, ebx */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    if (!c->zf) goto L_00997d06; /* jne 0x997d06 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov eax, dword ptr [ebp + 0x18] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ebx, dword ptr [ebp - 0xc] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov esi, dword ptr [ebp - 8] */
L_00997d4d:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x2u)); /* add ecx, 2 */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    W32((uint32_t)(c->ebp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x18], eax */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [ebp + 0xc], ecx */
    if ((c->sf != c->of)) goto L_00997cf7; /* jl 0x997cf7 */
    goto L_00997e34; /* jmp 0x997e34 */
L_00997d63:;
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, c->ecx, c->edi); /* cmp ecx, edi */
    if (c->zf) goto L_00997dd0; /* je 0x997dd0 */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if ((c->zf || c->sf != c->of)) goto L_00997e34; /* jle 0x997e34 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
L_00997d74:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if ((c->zf || c->sf != c->of)) goto L_00997dc4; /* jle 0x997dc4 */
L_00997d7a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->ecx * 4))); /* mov eax, dword ptr [eax + ecx*4] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + c->edi * 4))); /* fld dword ptr [eax + edi*4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x9b5470u))); /* fmul dword ptr [0x10025470] */
    WF64((uint32_t)(c->ebp + 0xffffffecu), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0x14] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xffffffecu))); /* fld qword ptr [ebp - 0x14] */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)fpu_to_int32(c, ST(0))); FPOP(c); /* fistp dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    (void)sub32(c, c->eax, (uint32_t)0x7fffu); /* cmp eax, 0x7fff */
    if ((c->zf || c->sf != c->of)) goto L_00997da3; /* jle 0x997da3 */
    c->eax = (uint32_t)((uint32_t)0x7fffu); /* mov eax, 0x7fff */
    goto L_00997daf; /* jmp 0x997daf */
L_00997da3:;
    (void)sub32(c, c->eax, (uint32_t)0xffff8000u); /* cmp eax, 0xffff8000 */
    if ((c->sf == c->of)) goto L_00997daf; /* jge 0x997daf */
    c->eax = (uint32_t)((uint32_t)0xffff8000u); /* mov eax, 0xffff8000 */
L_00997daf:;
    c->eax = (uint32_t)(add32(c, c->eax, c->edx)); /* add eax, edx */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    c->edx = (uint32_t)(sar32(c, c->edx, 8)); /* sar edx, 8 */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov edx, dword ptr [ebp + 0x1c] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [esi], al */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->ecx, c->ebx); /* cmp ecx, ebx */
    if ((c->sf != c->of)) goto L_00997d7a; /* jl 0x997d7a */
L_00997dc4:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if ((c->sf != c->of)) goto L_00997d74; /* jl 0x997d74 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    goto L_00997e34; /* jmp 0x997e34 */
L_00997dd0:;
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    W32((uint32_t)(c->ebp + 0x18u), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 0x18], edi */
    if ((c->zf || c->sf != c->of)) goto L_00997e34; /* jle 0x997e34 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
L_00997dda:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if ((c->zf || c->sf != c->of)) goto L_00997e29; /* jle 0x997e29 */
L_00997de0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov edi, dword ptr [ebp + 0x18] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->ecx * 4))); /* mov eax, dword ptr [eax + ecx*4] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + c->edi * 4))); /* fld dword ptr [eax + edi*4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x9b5470u))); /* fmul dword ptr [0x10025470] */
    WF64((uint32_t)(c->ebp + 0xffffffecu), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0x14] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xffffffecu))); /* fld qword ptr [ebp - 0x14] */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)fpu_to_int32(c, ST(0))); FPOP(c); /* fistp dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    (void)sub32(c, c->eax, (uint32_t)0x7fffu); /* cmp eax, 0x7fff */
    if ((c->zf || c->sf != c->of)) goto L_00997e0c; /* jle 0x997e0c */
    c->eax = (uint32_t)((uint32_t)0x7fffu); /* mov eax, 0x7fff */
    goto L_00997e18; /* jmp 0x997e18 */
L_00997e0c:;
    (void)sub32(c, c->eax, (uint32_t)0xffff8000u); /* cmp eax, 0xffff8000 */
    if ((c->sf == c->of)) goto L_00997e18; /* jge 0x997e18 */
    c->eax = (uint32_t)((uint32_t)0xffff8000u); /* mov eax, 0xffff8000 */
L_00997e18:;
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->ebp + 0x1cu)))); /* add eax, dword ptr [ebp + 0x1c] */
    W8((uint32_t)(c->edx), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edx], al */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    c->eax = (uint32_t)(sar32(c, c->eax, 8)); /* sar eax, 8 */
    W8((uint32_t)(c->edx), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edx], al */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->ecx, c->ebx); /* cmp ecx, ebx */
    if ((c->sf != c->of)) goto L_00997de0; /* jl 0x997de0 */
L_00997e29:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov eax, dword ptr [ebp + 0x18] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    W32((uint32_t)(c->ebp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x18], eax */
    if ((c->sf != c->of)) goto L_00997dda; /* jl 0x997dda */
L_00997e34:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ecx = (uint32_t)((uint32_t)(c->edi + 0x1e0u)); /* lea ecx, [edi + 0x1e0] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00997e44u); f_009a3bb0(c); /* call 0x9a3bb0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x50u))); /* mov ecx, dword ptr [edi + 0x50] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x20u))); /* mov eax, dword ptr [ebp + 0x20] */
    W32((uint32_t)(c->edi + 0x50u), (uint32_t)(c->ecx)); /* mov dword ptr [edi + 0x50], ecx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->edi + 0x54u))); /* mov ebx, dword ptr [edi + 0x54] */
    c->ebx = (uint32_t)(adc32(c, c->ebx, c->edx)); /* adc ebx, edx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->edi + 0x54u), (uint32_t)(c->ebx)); /* mov dword ptr [edi + 0x54], ebx */
    if (c->zf) goto L_00997e66; /* je 0x997e66 */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + 0x60u))); /* mov edx, dword ptr [edi + 0x60] */
    W32((uint32_t)(c->eax), (uint32_t)(c->edx)); /* mov dword ptr [eax], edx */
L_00997e66:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov eax, dword ptr [ebp - 0x18] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)c->esi; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
L_00997e73:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00997e75:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00997e80(CPU *c) { /* FUN_10007e80 */
    PREEMPT_POLL(c);
    PUSH32(c, 0x00997e85u); f_00997e98(c); /* call 0x997e98 */
    PUSH32(c, 0x00997e8au); f_0099954a(c); /* call 0x99954a */
    W32((uint32_t)(0x9ce2f8u), (uint32_t)(c->eax)); /* mov dword ptr [0x1003e2f8], eax */
    PUSH32(c, 0x00997e94u); f_009994fa(c); /* call 0x9994fa */
    c->fpu_sw &= 0x7f00; /* fnclex  */
    c->esp += 4; return; /* ret  */
}

void f_00997e97(CPU *c) { /* PTR_00997e97 */
    PREEMPT_POLL(c);
    c->esp += 4; return; /* ret  */
}

void f_00997e98(CPU *c) { /* FUN_10007e98 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x999923u); /* mov eax, 0x10009923 */
    W32((uint32_t)(0x9b7834u), (uint32_t)((uint32_t)0x9995cdu)); /* mov dword ptr [0x10027834], 0x100095cd */
    W32((uint32_t)(0x9b7830u), (uint32_t)(c->eax)); /* mov dword ptr [0x10027830], eax */
    W32((uint32_t)(0x9b7838u), (uint32_t)((uint32_t)0x999633u)); /* mov dword ptr [0x10027838], 0x10009633 */
    W32((uint32_t)(0x9b783cu), (uint32_t)((uint32_t)0x999573u)); /* mov dword ptr [0x1002783c], 0x10009573 */
    W32((uint32_t)(0x9b7840u), (uint32_t)((uint32_t)0x99961bu)); /* mov dword ptr [0x10027840], 0x1000961b */
    W32((uint32_t)(0x9b7844u), (uint32_t)(c->eax)); /* mov dword ptr [0x10027844], eax */
    c->esp += 4; return; /* ret  */
}

void f_00997ed0(CPU *c) { /* FUN_10007ed0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = 0x1bu; PUSH32(c, v_); } /* push 0x1b */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x9b547cu)); /* mov dword ptr [esi], 0x1002547c */
    PUSH32(c, 0x00997ee0u); f_00999a2e(c); /* call 0x999a2e */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov esi, dword ptr [esi + 4] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00997eef; /* je 0x997eef */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00997eeeu); f_00998bae(c); /* call 0x998bae */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00997eef:;
    { uint32_t v_ = 0x1bu; PUSH32(c, v_); } /* push 0x1b */
    PUSH32(c, 0x00997ef6u); f_00999a8f(c); /* call 0x999a8f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00997ef9(CPU *c) { /* type_info::vfunc_0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00997f01u); f_00997ed0(c); /* call 0x997ed0 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00997f0f; /* je 0x997f0f */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00997f0eu); f_00993c50(c); /* call 0x993c50 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00997f0f:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00997f15(CPU *c) { /* FUN_10007f15 */
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
    PUSH32(c, 0x00997f43u); f_00999c4c(c); /* call 0x999c4c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe4u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 0x1c] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    if (c->sf) goto L_00997f55; /* js 0x997f55 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov eax, dword ptr [ebp - 0x20] */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax], 0 */
    goto L_00997f62; /* jmp 0x997f62 */
L_00997f55:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe0u)); /* lea eax, [ebp - 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    PUSH32(c, 0x00997f60u); f_00999b34(c); /* call 0x999b34 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00997f62:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00997f67(CPU *c) { /* FUN_10007f67 */
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
    { uint32_t t_ = c->eax; switch (t_) {  default: jump_indirect(c, t_, 0x00997f92u); return; } } /* jmp eax */
}

void f_00997f94(CPU *c) { /* PTR_00997f94 */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 12; return; /* ret 8 */
}

void f_00997f9b(CPU *c) { /* FUN_10007f9b */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { guest_lock(); { uint32_t t0_ = R32((uint32_t)(c->esp)), t1_ = c->eax; W32((uint32_t)(c->esp), (uint32_t)(t1_)); c->eax = (uint32_t)(t0_); } guest_unlock(); } /* xchg dword ptr [esp], eax */
    { uint32_t t_ = c->eax; switch (t_) {  default: jump_indirect(c, t_, 0x00997fa0u); return; } } /* jmp eax */
}

void f_00997fa2(CPU *c) { /* FUN_10007fa2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { guest_lock(); { uint32_t t0_ = R32((uint32_t)(c->esp)), t1_ = c->eax; W32((uint32_t)(c->esp), (uint32_t)(t1_)); c->eax = (uint32_t)(t0_); } guest_unlock(); } /* xchg dword ptr [esp], eax */
    { uint32_t t_ = c->eax; switch (t_) {  default: jump_indirect(c, t_, 0x00997fa7u); return; } } /* jmp eax */
}

void f_00997fa9(CPU *c) { /* FUN_10007fa9 */
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
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x997fd1u)); /* mov dword ptr [ebp - 4], 0x10007fd1 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00997fd1u); f_009b1ab0(c); /* call 0x9b1ab0 */
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

void f_00997fd1(CPU *c) { /* PTR_00997fd1 */
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

void f_00997ff8(CPU *c) { /* FUN_10007ff8 */
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
    PUSH32(c, 0x0099801eu); f_0099a456(c); /* call 0x99a456 */
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

void f_0099802e(CPU *c) { /* FUN_1000802e */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x14u)); /* sub esp, 0x14 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffecu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x14], 0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)((uint32_t)0x998082u)); /* mov dword ptr [ebp - 0x10], 0x10008082 */
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
    PUSH32(c, 0x00998073u); f_0099ac70(c); /* call 0x99ac70 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->eax)); /* mov dword ptr fs:[0], eax */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00998082(CPU *c) { /* FUN_10008082 */
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
    PUSH32(c, 0x009980a2u); f_0099a456(c); /* call 0x99a456 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_009980a7(CPU *c) { /* FUN_100080a7 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x34u)); /* sub esp, 0x34 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffd8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x28], 0 */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)((uint32_t)0x99815du)); /* mov dword ptr [ebp - 0x24], 0x1000815d */
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
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)((uint32_t)0x99812fu)); /* mov dword ptr [ebp - 0x10], 0x1000812f */
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
    PUSH32(c, 0x00998126u); f_0099ad41(c); /* call 0x99ad41 */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x68u)); PUSH32(c, 0x00998129u); call_indirect(c, t_); } /* call dword ptr [eax + 0x68] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffccu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x34], 0 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if (c->zf) goto L_0099814c; /* je 0x99814c */
    c->ebx = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov ebx, dword ptr fs:[0] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ebx, dword ptr [ebp - 0x28] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ebx)); /* mov dword ptr fs:[0], ebx */
    goto L_00998155; /* jmp 0x998155 */
L_0099814c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->eax)); /* mov dword ptr fs:[0], eax */
L_00998155:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffccu))); /* mov eax, dword ptr [ebp - 0x34] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0099812f(CPU *c) { /* PTR_0099812f */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if (c->zf) goto L_0099814c; /* je 0x99814c */
    c->ebx = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov ebx, dword ptr fs:[0] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ebx, dword ptr [ebp - 0x28] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ebx)); /* mov dword ptr fs:[0], ebx */
    goto L_00998155; /* jmp 0x998155 */
L_0099814c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->eax)); /* mov dword ptr fs:[0], eax */
L_00998155:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffccu))); /* mov eax, dword ptr [ebp - 0x34] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0099815d(CPU *c) { /* FUN_1000815d */
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
    if (c->zf) goto L_00998180; /* je 0x998180 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->eax + 0x24u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [eax + 0x24], 1 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_009981cd; /* jmp 0x9981cd */
L_00998180:;
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
    PUSH32(c, 0x009981a7u); f_0099a456(c); /* call 0x99a456 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x24u)), (uint32_t)0x0u); /* cmp dword ptr [eax + 0x24], 0 */
    if (!c->zf) goto L_009981be; /* jne 0x9981be */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x009981beu); f_00997fa9(c); /* call 0x997fa9 */
L_009981be:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ebx, dword ptr [ebp + 0xc] */
    c->esp = (uint32_t)(R32((uint32_t)(c->ebx + 0x1cu))); /* mov esp, dword ptr [ebx + 0x1c] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ebx + 0x20u))); /* mov ebp, dword ptr [ebx + 0x20] */
    { uint32_t t_ = R32((uint32_t)(c->ebx + 0x18u)); switch (t_) {  default: jump_indirect(c, t_, 0x009981c7u); return; } } /* jmp dword ptr [ebx + 0x18] */
L_009981cd:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_009981d2(CPU *c) { /* FUN_100081d2 */
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
    if ((c->sf != c->of)) goto L_00998229; /* jl 0x998229 */
L_009981f0:;
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (!c->zf) goto L_009981fa; /* jne 0x9981fa */
    PUSH32(c, 0x009981fau); f_0099aea9(c); /* call 0x99aea9 */
L_009981fa:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi * 4)); /* lea eax, [esi + esi*4] */
    (void)sub32(c, R32((uint32_t)(c->ebx + c->eax * 4 + 0x4u)), c->ecx); /* cmp dword ptr [ebx + eax*4 + 4], ecx */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->eax * 4)); /* lea eax, [ebx + eax*4] */
    if ((c->sf == c->of)) goto L_0099820f; /* jge 0x99820f */
    (void)sub32(c, c->ecx, R32((uint32_t)(c->eax + 0x8u))); /* cmp ecx, dword ptr [eax + 8] */
    if ((c->zf || c->sf != c->of)) goto L_00998214; /* jle 0x998214 */
L_0099820f:;
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (!c->zf) goto L_00998220; /* jne 0x998220 */
L_00998214:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
L_00998220:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    if ((c->sf == c->of)) goto L_009981f0; /* jge 0x9981f0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
L_00998229:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov ecx, dword ptr [ebp + 0x14] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    W32((uint32_t)(c->ecx), (uint32_t)(c->esi)); /* mov dword ptr [ecx], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov ecx, dword ptr [ebp + 0x18] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    (void)sub32(c, c->eax, R32((uint32_t)(c->edi + 0xcu))); /* cmp eax, dword ptr [edi + 0xc] */
    if ((!c->cf && !c->zf)) goto L_0099823d; /* ja 0x99823d */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if ((c->cf || c->zf)) goto L_00998242; /* jbe 0x998242 */
L_0099823d:;
    PUSH32(c, 0x00998242u); f_0099aea9(c); /* call 0x99aea9 */
L_00998242:;
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi * 4)); /* lea eax, [esi + esi*4] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->eax * 4)); /* lea eax, [ebx + eax*4] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_009981f0(CPU *c) { /* PTR_009981f0 */
    PREEMPT_POLL(c);
L_009981f0:;
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (!c->zf) goto L_009981fa; /* jne 0x9981fa */
    PUSH32(c, 0x009981fau); f_0099aea9(c); /* call 0x99aea9 */
L_009981fa:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi * 4)); /* lea eax, [esi + esi*4] */
    (void)sub32(c, R32((uint32_t)(c->ebx + c->eax * 4 + 0x4u)), c->ecx); /* cmp dword ptr [ebx + eax*4 + 4], ecx */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->eax * 4)); /* lea eax, [ebx + eax*4] */
    if ((c->sf == c->of)) goto L_0099820f; /* jge 0x99820f */
    (void)sub32(c, c->ecx, R32((uint32_t)(c->eax + 0x8u))); /* cmp ecx, dword ptr [eax + 8] */
    if ((c->zf || c->sf != c->of)) goto L_00998214; /* jle 0x998214 */
L_0099820f:;
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (!c->zf) goto L_00998220; /* jne 0x998220 */
L_00998214:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
L_00998220:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    if ((c->sf == c->of)) goto L_009981f0; /* jge 0x9981f0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov ecx, dword ptr [ebp + 0x14] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    W32((uint32_t)(c->ecx), (uint32_t)(c->esi)); /* mov dword ptr [ecx], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov ecx, dword ptr [ebp + 0x18] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    (void)sub32(c, c->eax, R32((uint32_t)(c->edi + 0xcu))); /* cmp eax, dword ptr [edi + 0xc] */
    if ((!c->cf && !c->zf)) goto L_0099823d; /* ja 0x99823d */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if ((c->cf || c->zf)) goto L_00998242; /* jbe 0x998242 */
L_0099823d:;
    PUSH32(c, 0x00998242u); f_0099aea9(c); /* call 0x99aea9 */
L_00998242:;
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi * 4)); /* lea eax, [esi + esi*4] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->eax * 4)); /* lea eax, [ebx + eax*4] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0099820f(CPU *c) { /* PTR_0099820f */
    PREEMPT_POLL(c);
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (!c->zf) goto L_00998220; /* jne 0x998220 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
L_00998220:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    if ((c->sf == c->of)) { f_009981f0(c); return; } /* jge 0x9981f0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov ecx, dword ptr [ebp + 0x14] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    W32((uint32_t)(c->ecx), (uint32_t)(c->esi)); /* mov dword ptr [ecx], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov ecx, dword ptr [ebp + 0x18] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    (void)sub32(c, c->eax, R32((uint32_t)(c->edi + 0xcu))); /* cmp eax, dword ptr [edi + 0xc] */
    if ((!c->cf && !c->zf)) goto L_0099823d; /* ja 0x99823d */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if ((c->cf || c->zf)) goto L_00998242; /* jbe 0x998242 */
L_0099823d:;
    PUSH32(c, 0x00998242u); f_0099aea9(c); /* call 0x99aea9 */
L_00998242:;
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi * 4)); /* lea eax, [esi + esi*4] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->eax * 4)); /* lea eax, [ebx + eax*4] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00998250(CPU *c) { /* __global_unwind2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x998268u; PUSH32(c, v_); } /* push 0x10008268 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00998268u); f_009b1ab0(c); /* call 0x9b1ab0 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00998268(CPU *c) { /* PTR_00998268 */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00998270(CPU *c) { /* PTR_00998270 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->ecx + 0x4u)) & (uint32_t)0x6u)); /* test dword ptr [ecx + 4], 6 */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    if (c->zf) goto L_00998291; /* je 0x998291 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    W32((uint32_t)(c->edx), (uint32_t)(c->eax)); /* mov dword ptr [edx], eax */
    c->eax = (uint32_t)((uint32_t)0x3u); /* mov eax, 3 */
L_00998291:;
    c->esp += 4; return; /* ret  */
}

void f_00998292(CPU *c) { /* __local_unwind2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0xfffffffeu; PUSH32(c, v_); } /* push -2 */
    { uint32_t v_ = 0x998270u; PUSH32(c, v_); } /* push 0x10008270 */
    { uint32_t v_ = R32((uint32_t)(0x0u + c->fs_base)); PUSH32(c, v_); } /* push dword ptr fs:[0] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
L_009982af:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov eax, dword ptr [esp + 0x20] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ebx, dword ptr [eax + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + 0xcu))); /* mov esi, dword ptr [eax + 0xc] */
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (c->zf) goto L_009982ec; /* je 0x9982ec */
    (void)sub32(c, c->esi, R32((uint32_t)(c->esp + 0x24u))); /* cmp esi, dword ptr [esp + 0x24] */
    if (c->zf) goto L_009982ec; /* je 0x9982ec */
    c->esi = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea esi, [esi + esi*2] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + c->esi * 4))); /* mov ecx, dword ptr [ebx + esi*4] */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 8], ecx */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0xc], ecx */
    (void)sub32(c, R32((uint32_t)(c->ebx + c->esi * 4 + 0x4u)), (uint32_t)0x0u); /* cmp dword ptr [ebx + esi*4 + 4], 0 */
    if (!c->zf) goto L_009982ea; /* jne 0x9982ea */
    { uint32_t v_ = 0x101u; PUSH32(c, v_); } /* push 0x101 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + c->esi * 4 + 0x8u))); /* mov eax, dword ptr [ebx + esi*4 + 8] */
    PUSH32(c, 0x009982e6u); f_00998326(c); /* call 0x998326 */
    { uint32_t t_ = R32((uint32_t)(c->ebx + c->esi * 4 + 0x8u)); PUSH32(c, 0x009982eau); call_indirect(c, t_); } /* call dword ptr [ebx + esi*4 + 8] */
L_009982ea:;
    goto L_009982af; /* jmp 0x9982af */
L_009982ec:;
    { uint32_t v_ = R32(c->esp); c->esp += 4; W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(v_)); } /* pop dword ptr fs:[0] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_009982fa(CPU *c) { /* __abnormal_termination */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov ecx, dword ptr fs:[0] */
    (void)sub32(c, R32((uint32_t)(c->ecx + 0x4u)), (uint32_t)0x998270u); /* cmp dword ptr [ecx + 4], 0x10008270 */
    if (!c->zf) goto L_0099831c; /* jne 0x99831c */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov edx, dword ptr [ecx + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edx + 0xcu))); /* mov edx, dword ptr [edx + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->ecx + 0x8u)), c->edx); /* cmp dword ptr [ecx + 8], edx */
    if (!c->zf) goto L_0099831c; /* jne 0x99831c */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
L_0099831c:;
    c->esp += 4; return; /* ret  */
}

void f_0099831d(CPU *c) { /* __NLG_Notify1 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ebx = (uint32_t)((uint32_t)0x9b7690u); /* mov ebx, 0x10027690 */
    { f_00998330(c); return; } /* jmp 0x998330 */
}

void f_00998326(CPU *c) { /* FUN_10008326 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ebx = (uint32_t)((uint32_t)0x9b7690u); /* mov ebx, 0x10027690 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebx + 8], ecx */
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 4], eax */
    W32((uint32_t)(c->ebx + 0xcu), (uint32_t)(c->ebp)); /* mov dword ptr [ebx + 0xc], ebp */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
}

void f_00998330(CPU *c) { /* PTR_00998330 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebx + 8], ecx */
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 4], eax */
    W32((uint32_t)(c->ebx + 0xcu), (uint32_t)(c->ebp)); /* mov dword ptr [ebx + 0xc], ebp */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
}

void f_00998340(CPU *c) { /* __ftol */
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

void f_00998367(CPU *c) { /* __CxxThrowException@8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x20u)); /* sub esp, 0x20 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esi = (uint32_t)((uint32_t)0x9b5480u); /* mov esi, 0x10025480 */
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
    { uint32_t t_ = R32((uint32_t)(0x9b5028u)); PUSH32(c, 0x0099839bu); call_indirect(c, t_); } /* call dword ptr [0x10025028] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 12; return; /* ret 8 */
}

void f_009983a1(CPU *c) { /* FUN_100083a1 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x009983a7u); f_0099b055(c); /* call 0x99b055 */
    { uint32_t v_ = R32((uint32_t)(0x9cfa18u)); PUSH32(c, v_); } /* push dword ptr [0x1003fa18] */
    PUSH32(c, 0x009983b2u); f_0099b081(c); /* call 0x99b081 */
    c->edx = (uint32_t)(R32((uint32_t)(0x9cfa18u))); /* mov edx, dword ptr [0x1003fa18] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(0x9cfa14u))); /* mov ecx, dword ptr [0x1003fa14] */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->esi = (uint32_t)(sub32(c, c->esi, c->edx)); /* sub esi, edx */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (!c->cf) goto L_00998407; /* jae 0x998407 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x009983d0u); f_0099b081(c); /* call 0x99b081 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x10u)); /* add eax, 0x10 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(0x9cfa18u)); PUSH32(c, v_); } /* push dword ptr [0x1003fa18] */
    PUSH32(c, 0x009983dfu); f_00998f93(c); /* call 0x998f93 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_009983ea; /* jne 0x9983ea */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    goto L_00998416; /* jmp 0x998416 */
L_009983ea:;
    c->ecx = (uint32_t)(R32((uint32_t)(0x9cfa14u))); /* mov ecx, dword ptr [0x1003fa14] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, R32((uint32_t)(0x9cfa18u)))); /* sub ecx, dword ptr [0x1003fa18] */
    W32((uint32_t)(0x9cfa18u), (uint32_t)(c->eax)); /* mov dword ptr [0x1003fa18], eax */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 2)); /* sar ecx, 2 */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->ecx * 4)); /* lea ecx, [eax + ecx*4] */
    W32((uint32_t)(0x9cfa14u), (uint32_t)(c->ecx)); /* mov dword ptr [0x1003fa14], ecx */
L_00998407:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    { uint32_t a_ = (uint32_t)(0x9cfa14u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x4u))); } /* add dword ptr [0x1003fa14], 4 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_00998416:;
    PUSH32(c, 0x0099841bu); f_0099b05e(c); /* call 0x99b05e */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_0099841f(CPU *c) { /* FUN_1000841f */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    PUSH32(c, 0x00998428u); f_009983a1(c); /* call 0x9983a1 */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->esp += 4; return; /* ret  */
}

void f_00998431(CPU *c) { /* PTR_00998431 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x80u; PUSH32(c, v_); } /* push 0x80 */
    PUSH32(c, 0x0099843bu); f_00998e59(c); /* call 0x998e59 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(0x9cfa18u), (uint32_t)(c->eax)); /* mov dword ptr [0x1003fa18], eax */
    if (!c->zf) goto L_00998452; /* jne 0x998452 */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    PUSH32(c, 0x0099844cu); f_00998b7b(c); /* call 0x998b7b */
    c->eax = (uint32_t)(R32((uint32_t)(0x9cfa18u))); /* mov eax, dword ptr [0x1003fa18] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00998452:;
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [eax], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(0x9cfa18u))); /* mov eax, dword ptr [0x1003fa18] */
    W32((uint32_t)(0x9cfa14u), (uint32_t)(c->eax)); /* mov dword ptr [0x1003fa14], eax */
    c->esp += 4; return; /* ret  */
}

void f_00998460(CPU *c) { /* PTR_00998460 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x19u; PUSH32(c, v_); } /* push 0x19 */
    PUSH32(c, 0x00998467u); f_00998b7b(c); /* call 0x998b7b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00998469(CPU *c) { /* _rand */
    PREEMPT_POLL(c);
    PUSH32(c, 0x0099846eu); f_0099ad41(c); /* call 0x99ad41 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x14u))); /* mov ecx, dword ptr [eax + 0x14] */
    { int64_t r_ = (int64_t)(int32_t)c->ecx * (int32_t)(uint32_t)0x343fdu; c->ecx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul ecx, ecx, 0x343fd */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x269ec3u)); /* add ecx, 0x269ec3 */
    W32((uint32_t)(c->eax + 0x14u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x14], ecx */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->eax = (uint32_t)(shr32(c, c->eax, 16)); /* shr eax, 0x10 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fffu))); /* and eax, 0x7fff */
    c->esp += 4; return; /* ret  */
}

void f_0099848b(CPU *c) { /* FUN_1000848b */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    (void)sub32(c, R32((uint32_t)(0x9ce3d0u)), c->esi); /* cmp dword ptr [0x1003e3d0], esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 8], esi */
    if (!c->zf) goto L_009984c9; /* jne 0x9984c9 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (c->zf) goto L_009985bb; /* je 0x9985bb */
L_009984ad:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov cl, byte ptr [edx] */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x61u); /* cmp cl, 0x61 */
    if ((c->sf != c->of)) goto L_009984be; /* jl 0x9984be */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x7au); /* cmp cl, 0x7a */
    if ((!c->zf && c->sf == c->of)) goto L_009984be; /* jg 0x9984be */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(sub8(c, ((uint8_t)c->ecx), (uint8_t)0x20u)); /* sub cl, 0x20 */
    W8((uint32_t)(c->edx), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [edx], cl */
L_009984be:;
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    (void)sub8(c, R8((uint32_t)(c->edx)), (uint8_t)0x0u); /* cmp byte ptr [edx], 0 */
    if (!c->zf) goto L_009984ad; /* jne 0x9984ad */
    goto L_009985bb; /* jmp 0x9985bb */
L_009984c9:;
    c->edi = (uint32_t)((uint32_t)0x9cfa08u); /* mov edi, 0x1003fa08 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0x9b5030u)); PUSH32(c, 0x009984d5u); call_indirect(c, t_); } /* call dword ptr [0x10025030] */
    (void)sub32(c, R32((uint32_t)(0x9cfa04u)), c->esi); /* cmp dword ptr [0x1003fa04], esi */
    if (c->zf) goto L_009984f5; /* je 0x9984f5 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0x9b502cu)); PUSH32(c, 0x009984e4u); call_indirect(c, t_); } /* call dword ptr [0x1002502c] */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x009984ebu); f_00999a2e(c); /* call 0x999a2e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    goto L_009984f8; /* jmp 0x9984f8 */
L_009984f5:;
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 4], esi */
L_009984f8:;
    c->eax = (uint32_t)(R32((uint32_t)(0x9ce3d0u))); /* mov eax, dword ptr [0x1003e3d0] */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (!c->zf) goto L_0099853e; /* jne 0x99853e */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), c->esi); /* cmp dword ptr [ebp - 4], esi */
    if (c->zf) goto L_00998510; /* je 0x998510 */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x0099850du); f_00999a8f(c); /* call 0x999a8f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00998517; /* jmp 0x998517 */
L_00998510:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0x9b502cu)); PUSH32(c, 0x00998517u); call_indirect(c, t_); } /* call dword ptr [0x1002502c] */
L_00998517:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (c->zf) goto L_009985bb; /* je 0x9985bb */
L_00998525:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov cl, byte ptr [edx] */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x61u); /* cmp cl, 0x61 */
    if ((c->sf != c->of)) goto L_00998536; /* jl 0x998536 */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x7au); /* cmp cl, 0x7a */
    if ((!c->zf && c->sf == c->of)) goto L_00998536; /* jg 0x998536 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(sub8(c, ((uint8_t)c->ecx), (uint8_t)0x20u)); /* sub cl, 0x20 */
    W8((uint32_t)(c->edx), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [edx], cl */
L_00998536:;
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    (void)sub8(c, R8((uint32_t)(c->edx)), (uint8_t)0x0u); /* cmp byte ptr [edx], 0 */
    if (!c->zf) goto L_00998525; /* jne 0x998525 */
    goto L_009985bb; /* jmp 0x9985bb */
L_0099853e:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    c->esi = (uint32_t)((uint32_t)0x200u); /* mov esi, 0x200 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00998555u); f_0099b260(c); /* call 0x99b260 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (c->zf) goto L_00998597; /* je 0x998597 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00998564u); f_00998e59(c); /* call 0x998e59 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    if (c->zf) goto L_00998597; /* je 0x998597 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(0x9ce3d0u)); PUSH32(c, v_); } /* push dword ptr [0x1003e3d0] */
    PUSH32(c, 0x00998583u); f_0099b260(c); /* call 0x99b260 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00998597; /* je 0x998597 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffff8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00998595u); f_0099b170(c); /* call 0x99b170 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00998597:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    if (c->zf) goto L_009985a8; /* je 0x9985a8 */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x009985a5u); f_00999a8f(c); /* call 0x999a8f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_009985af; /* jmp 0x9985af */
L_009985a8:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0x9b502cu)); PUSH32(c, 0x009985afu); call_indirect(c, t_); } /* call dword ptr [0x1002502c] */
L_009985af:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffff8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 8] */
    PUSH32(c, 0x009985b7u); f_00998bae(c); /* call 0x998bae */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_009985bb:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_009985bf(CPU *c) { /* FUN_100085bf */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x20u)); /* sub esp, 0x20 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x49u)); /* mov dword ptr [ebp - 0x14], 0x49 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x18], eax */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    PUSH32(c, 0x009985dbu); f_0099bf60(c); /* call 0x99bf60 */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe0u)); /* lea eax, [ebp - 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x009985eeu); f_0099b4af(c); /* call 0x99b4af */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00998600(CPU *c) { /* PTR_00998600 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xffffffffu)); /* lea eax, [edx - 1] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00998610(CPU *c) { /* _strchr */
    PREEMPT_POLL(c);
    goto L_00998610;
L_00998600:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xffffffffu)); /* lea eax, [edx - 1] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_00998610:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x8u))); /* mov al, byte ptr [esp + 8] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u)); /* test edx, 3 */
    if (c->zf) goto L_0099863b; /* je 0x99863b */
L_00998628:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov cl, byte ptr [edx] */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    (void)sub8(c, ((uint8_t)c->ecx), ((uint8_t)c->ebx)); /* cmp cl, bl */
    if (c->zf) goto L_00998600; /* je 0x998600 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_00998684; /* je 0x998684 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u)); /* test edx, 3 */
    if (!c->zf) goto L_00998628; /* jne 0x998628 */
L_0099863b:;
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | c->eax))); /* or ebx, eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->ebx = (uint32_t)(shl32(c, c->ebx, 16)); /* shl ebx, 0x10 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | c->eax))); /* or ebx, eax */
L_00998646:;
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
    if (!c->zf) goto L_00998688; /* jne 0x998688 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u))); /* and eax, 0x81010100 */
    if (c->zf) goto L_00998646; /* je 0x998646 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1010100u))); /* and eax, 0x1010100 */
    if (!c->zf) goto L_00998682; /* jne 0x998682 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0x80000000u))); /* and esi, 0x80000000 */
    if (!c->zf) goto L_00998646; /* jne 0x998646 */
L_00998682:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_00998684:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_00998688:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0xfffffffcu))); /* mov eax, dword ptr [edx - 4] */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_009986c5; /* je 0x9986c5 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00998682; /* je 0x998682 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->ebx)); /* cmp ah, bl */
    if (c->zf) goto L_009986be; /* je 0x9986be */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_00998682; /* je 0x998682 */
    c->eax = (uint32_t)(shr32(c, c->eax, 16)); /* shr eax, 0x10 */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_009986b7; /* je 0x9986b7 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00998682; /* je 0x998682 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->ebx)); /* cmp ah, bl */
    if (c->zf) goto L_009986b0; /* je 0x9986b0 */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_00998682; /* je 0x998682 */
    goto L_00998646; /* jmp 0x998646 */
L_009986b0:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xffffffffu)); /* lea eax, [edx - 1] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_009986b7:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xfffffffeu)); /* lea eax, [edx - 2] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_009986be:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xfffffffdu)); /* lea eax, [edx - 3] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_009986c5:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xfffffffcu)); /* lea eax, [edx - 4] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00998616(CPU *c) { /* PTR_00998616 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u)); /* test edx, 3 */
    if (c->zf) goto L_0099863b; /* je 0x99863b */
L_00998628:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov cl, byte ptr [edx] */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    (void)sub8(c, ((uint8_t)c->ecx), ((uint8_t)c->ebx)); /* cmp cl, bl */
    if (c->zf) { f_00998600(c); return; } /* je 0x998600 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_00998684; /* je 0x998684 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u)); /* test edx, 3 */
    if (!c->zf) goto L_00998628; /* jne 0x998628 */
L_0099863b:;
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | c->eax))); /* or ebx, eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->ebx = (uint32_t)(shl32(c, c->ebx, 16)); /* shl ebx, 0x10 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | c->eax))); /* or ebx, eax */
L_00998646:;
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
    if (!c->zf) goto L_00998688; /* jne 0x998688 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u))); /* and eax, 0x81010100 */
    if (c->zf) goto L_00998646; /* je 0x998646 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1010100u))); /* and eax, 0x1010100 */
    if (!c->zf) goto L_00998682; /* jne 0x998682 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0x80000000u))); /* and esi, 0x80000000 */
    if (!c->zf) goto L_00998646; /* jne 0x998646 */
L_00998682:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_00998684:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_00998688:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0xfffffffcu))); /* mov eax, dword ptr [edx - 4] */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_009986c5; /* je 0x9986c5 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00998682; /* je 0x998682 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->ebx)); /* cmp ah, bl */
    if (c->zf) goto L_009986be; /* je 0x9986be */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_00998682; /* je 0x998682 */
    c->eax = (uint32_t)(shr32(c, c->eax, 16)); /* shr eax, 0x10 */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_009986b7; /* je 0x9986b7 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00998682; /* je 0x998682 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->ebx)); /* cmp ah, bl */
    if (c->zf) goto L_009986b0; /* je 0x9986b0 */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_00998682; /* je 0x998682 */
    goto L_00998646; /* jmp 0x998646 */
L_009986b0:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xffffffffu)); /* lea eax, [edx - 1] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_009986b7:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xfffffffeu)); /* lea eax, [edx - 2] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_009986be:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xfffffffdu)); /* lea eax, [edx - 3] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_009986c5:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xfffffffcu)); /* lea eax, [edx - 4] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_009986d0(CPU *c) { /* FUN_100086d0 */
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
    if ((c->cf || c->zf)) goto L_009986f0; /* jbe 0x9986f0 */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_00998868; /* jb 0x998868 */
L_009986f0:;
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x3u)); /* test edi, 3 */
    if (!c->zf) goto L_0099870c; /* jne 0x99870c */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u))); /* and edx, 3 */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) goto L_0099872c; /* jb 0x99872c */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x998818u)); switch (t_) { case 0x00998828u: goto L_00998828; case 0x00998830u: goto L_00998830; case 0x0099883cu: goto L_0099883c; case 0x00998850u: goto L_00998850; default: jump_indirect(c, t_, 0x00998705u); return; } } /* jmp dword ptr [edx*4 + 0x10008818] */
L_0099870c:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edx = (uint32_t)((uint32_t)0x3u); /* mov edx, 3 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x4u)); /* sub ecx, 4 */
    if (c->cf) goto L_00998724; /* jb 0x998724 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x3u))); /* and eax, 3 */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->eax * 4 + 0x998730u)); switch (t_) {  default: jump_indirect(c, t_, 0x0099871du); return; } } /* jmp dword ptr [eax*4 + 0x10008730] */
L_00998724:;
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0x998828u)); switch (t_) {  default: jump_indirect(c, t_, 0x00998724u); return; } } /* jmp dword ptr [ecx*4 + 0x10008828] */
L_0099872c:;
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0x9987acu)); switch (t_) { case 0x009987ccu: goto L_009987cc; case 0x009987d4u: goto L_009987d4; case 0x009987dcu: goto L_009987dc; case 0x009987e4u: goto L_009987e4; case 0x009987ecu: goto L_009987ec; case 0x009987f4u: goto L_009987f4; case 0x009987fcu: goto L_009987fc; case 0x0099880fu: goto L_0099880f; default: jump_indirect(c, t_, 0x0099872cu); return; } } /* jmp dword ptr [ecx*4 + 0x100087ac] */
L_009987cc:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe4u))); /* mov eax, dword ptr [esi + ecx*4 - 0x1c] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x1c], eax */
L_009987d4:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe8u))); /* mov eax, dword ptr [esi + ecx*4 - 0x18] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x18], eax */
L_009987dc:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffecu))); /* mov eax, dword ptr [esi + ecx*4 - 0x14] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffecu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x14], eax */
L_009987e4:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff0u))); /* mov eax, dword ptr [esi + ecx*4 - 0x10] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x10], eax */
L_009987ec:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff4u))); /* mov eax, dword ptr [esi + ecx*4 - 0xc] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0xc], eax */
L_009987f4:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff8u))); /* mov eax, dword ptr [esi + ecx*4 - 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 8], eax */
L_009987fc:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
L_0099880f:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x998818u)); switch (t_) { case 0x00998828u: goto L_00998828; case 0x00998830u: goto L_00998830; case 0x0099883cu: goto L_0099883c; case 0x00998850u: goto L_00998850; default: jump_indirect(c, t_, 0x0099880fu); return; } } /* jmp dword ptr [edx*4 + 0x10008818] */
L_00998828:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00998830:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0099883c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00998850:;
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
L_00998868:;
    c->esi = (uint32_t)((uint32_t)(c->ecx + c->esi + 0xfffffffcu)); /* lea esi, [ecx + esi - 4] */
    c->edi = (uint32_t)((uint32_t)(c->ecx + c->edi + 0xfffffffcu)); /* lea edi, [ecx + edi - 4] */
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x3u)); /* test edi, 3 */
    if (!c->zf) goto L_0099889c; /* jne 0x99889c */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u))); /* and edx, 3 */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) goto L_00998890; /* jb 0x998890 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x9989b0u)); switch (t_) { case 0x009989c0u: goto L_009989c0; case 0x009989c8u: goto L_009989c8; case 0x009989d8u: goto L_009989d8; case 0x009989ecu: goto L_009989ec; default: jump_indirect(c, t_, 0x00998887u); return; } } /* jmp dword ptr [edx*4 + 0x100089b0] */
L_00998890:;
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0x998960u)); switch (t_) { case 0x009989a7u: goto L_009989a7; default: jump_indirect(c, t_, 0x00998892u); return; } } /* jmp dword ptr [ecx*4 + 0x10008960] */
L_0099889c:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edx = (uint32_t)((uint32_t)0x3u); /* mov edx, 3 */
    (void)sub32(c, c->ecx, (uint32_t)0x4u); /* cmp ecx, 4 */
    if (c->cf) goto L_009988b4; /* jb 0x9988b4 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x3u))); /* and eax, 3 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->eax * 4 + 0x9988b8u)); switch (t_) {  default: jump_indirect(c, t_, 0x009988adu); return; } } /* jmp dword ptr [eax*4 + 0x100088b8] */
L_009988b4:;
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0x9989b0u)); switch (t_) { case 0x009989c0u: goto L_009989c0; case 0x009989c8u: goto L_009989c8; case 0x009989d8u: goto L_009989d8; case 0x009989ecu: goto L_009989ec; default: jump_indirect(c, t_, 0x009988b4u); return; } } /* jmp dword ptr [ecx*4 + 0x100089b0] */
L_009989a7:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x9989b0u)); switch (t_) { case 0x009989c0u: goto L_009989c0; case 0x009989c8u: goto L_009989c8; case 0x009989d8u: goto L_009989d8; case 0x009989ecu: goto L_009989ec; default: jump_indirect(c, t_, 0x009989a7u); return; } } /* jmp dword ptr [edx*4 + 0x100089b0] */
L_009989c0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009989c8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009989d8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009989ec:;
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

void f_0099872c(CPU *c) { /* PTR_0099872c */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0x9987acu)); switch (t_) { case 0x009987ccu: goto L_009987cc; case 0x009987d4u: goto L_009987d4; case 0x009987dcu: goto L_009987dc; case 0x009987e4u: goto L_009987e4; case 0x009987ecu: goto L_009987ec; case 0x009987f4u: goto L_009987f4; case 0x009987fcu: goto L_009987fc; case 0x0099880fu: goto L_0099880f; default: jump_indirect(c, t_, 0x0099872cu); return; } } /* jmp dword ptr [ecx*4 + 0x100087ac] */
L_009987cc:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe4u))); /* mov eax, dword ptr [esi + ecx*4 - 0x1c] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x1c], eax */
L_009987d4:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe8u))); /* mov eax, dword ptr [esi + ecx*4 - 0x18] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x18], eax */
L_009987dc:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffecu))); /* mov eax, dword ptr [esi + ecx*4 - 0x14] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffecu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x14], eax */
L_009987e4:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff0u))); /* mov eax, dword ptr [esi + ecx*4 - 0x10] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x10], eax */
L_009987ec:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff4u))); /* mov eax, dword ptr [esi + ecx*4 - 0xc] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0xc], eax */
L_009987f4:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff8u))); /* mov eax, dword ptr [esi + ecx*4 - 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 8], eax */
L_009987fc:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
L_0099880f:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x998818u)); switch (t_) { case 0x00998828u: goto L_00998828; case 0x00998830u: goto L_00998830; case 0x0099883cu: goto L_0099883c; case 0x00998850u: goto L_00998850; default: jump_indirect(c, t_, 0x0099880fu); return; } } /* jmp dword ptr [edx*4 + 0x10008818] */
L_00998828:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00998830:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0099883c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00998850:;
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

void f_00998740(CPU *c) { /* PTR_00998740 */
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
    if (c->cf) { f_0099872c(c); return; } /* jb 0x99872c */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x998818u)); switch (t_) { case 0x00998828u: goto L_00998828; case 0x00998830u: goto L_00998830; case 0x0099883cu: goto L_0099883c; case 0x00998850u: goto L_00998850; default: jump_indirect(c, t_, 0x00998762u); return; } } /* jmp dword ptr [edx*4 + 0x10008818] */
L_00998828:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00998830:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0099883c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00998850:;
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

void f_00998760(CPU *c) { /* PTR_00998760 */
    PREEMPT_POLL(c);
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x998818u)); switch (t_) { case 0x00998828u: goto L_00998828; case 0x00998830u: goto L_00998830; case 0x0099883cu: goto L_0099883c; case 0x00998850u: goto L_00998850; default: jump_indirect(c, t_, 0x00998762u); return; } } /* jmp dword ptr [edx*4 + 0x10008818] */
L_00998828:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00998830:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0099883c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00998850:;
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

void f_0099876c(CPU *c) { /* PTR_0099876c */
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
    if (c->cf) { f_0099872c(c); return; } /* jb 0x99872c */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x998818u)); switch (t_) { case 0x00998828u: goto L_00998828; case 0x00998830u: goto L_00998830; case 0x0099883cu: goto L_0099883c; case 0x00998850u: goto L_00998850; default: jump_indirect(c, t_, 0x00998788u); return; } } /* jmp dword ptr [edx*4 + 0x10008818] */
L_00998828:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00998830:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0099883c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00998850:;
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

void f_00998790(CPU *c) { /* PTR_00998790 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & c->ecx))); /* and edx, ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) { f_0099872c(c); return; } /* jb 0x99872c */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x998818u)); switch (t_) { case 0x00998828u: goto L_00998828; case 0x00998830u: goto L_00998830; case 0x0099883cu: goto L_0099883c; case 0x00998850u: goto L_00998850; default: jump_indirect(c, t_, 0x009987a2u); return; } } /* jmp dword ptr [edx*4 + 0x10008818] */
L_00998828:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00998830:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0099883c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00998850:;
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

void f_009987cc(CPU *c) { /* PTR_009987cc */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x998818u)); switch (t_) { case 0x00998828u: goto L_00998828; case 0x00998830u: goto L_00998830; case 0x0099883cu: goto L_0099883c; case 0x00998850u: goto L_00998850; default: jump_indirect(c, t_, 0x0099880fu); return; } } /* jmp dword ptr [edx*4 + 0x10008818] */
L_00998828:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00998830:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0099883c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00998850:;
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

void f_009987d4(CPU *c) { /* PTR_009987d4 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x998818u)); switch (t_) { case 0x00998828u: goto L_00998828; case 0x00998830u: goto L_00998830; case 0x0099883cu: goto L_0099883c; case 0x00998850u: goto L_00998850; default: jump_indirect(c, t_, 0x0099880fu); return; } } /* jmp dword ptr [edx*4 + 0x10008818] */
L_00998828:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00998830:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0099883c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00998850:;
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

void f_009987dc(CPU *c) { /* PTR_009987dc */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x998818u)); switch (t_) { case 0x00998828u: goto L_00998828; case 0x00998830u: goto L_00998830; case 0x0099883cu: goto L_0099883c; case 0x00998850u: goto L_00998850; default: jump_indirect(c, t_, 0x0099880fu); return; } } /* jmp dword ptr [edx*4 + 0x10008818] */
L_00998828:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00998830:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0099883c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00998850:;
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

void f_009987e4(CPU *c) { /* PTR_009987e4 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x998818u)); switch (t_) { case 0x00998828u: goto L_00998828; case 0x00998830u: goto L_00998830; case 0x0099883cu: goto L_0099883c; case 0x00998850u: goto L_00998850; default: jump_indirect(c, t_, 0x0099880fu); return; } } /* jmp dword ptr [edx*4 + 0x10008818] */
L_00998828:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00998830:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0099883c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00998850:;
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

void f_009987ec(CPU *c) { /* PTR_009987ec */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x998818u)); switch (t_) { case 0x00998828u: goto L_00998828; case 0x00998830u: goto L_00998830; case 0x0099883cu: goto L_0099883c; case 0x00998850u: goto L_00998850; default: jump_indirect(c, t_, 0x0099880fu); return; } } /* jmp dword ptr [edx*4 + 0x10008818] */
L_00998828:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00998830:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0099883c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00998850:;
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

void f_009987f4(CPU *c) { /* PTR_009987f4 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff8u))); /* mov eax, dword ptr [esi + ecx*4 - 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x998818u)); switch (t_) { case 0x00998828u: goto L_00998828; case 0x00998830u: goto L_00998830; case 0x0099883cu: goto L_0099883c; case 0x00998850u: goto L_00998850; default: jump_indirect(c, t_, 0x0099880fu); return; } } /* jmp dword ptr [edx*4 + 0x10008818] */
L_00998828:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00998830:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0099883c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00998850:;
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

void f_009987fc(CPU *c) { /* PTR_009987fc */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x998818u)); switch (t_) { case 0x00998828u: goto L_00998828; case 0x00998830u: goto L_00998830; case 0x0099883cu: goto L_0099883c; case 0x00998850u: goto L_00998850; default: jump_indirect(c, t_, 0x0099880fu); return; } } /* jmp dword ptr [edx*4 + 0x10008818] */
L_00998828:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00998830:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0099883c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00998850:;
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

void f_0099880f(CPU *c) { /* PTR_0099880f */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x998818u)); switch (t_) { case 0x00998828u: goto L_00998828; case 0x00998830u: goto L_00998830; case 0x0099883cu: goto L_0099883c; case 0x00998850u: goto L_00998850; default: jump_indirect(c, t_, 0x0099880fu); return; } } /* jmp dword ptr [edx*4 + 0x10008818] */
L_00998828:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00998830:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0099883c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00998850:;
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

void f_00998828(CPU *c) { /* PTR_00998828 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00998830(CPU *c) { /* PTR_00998830 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0099883c(CPU *c) { /* PTR_0099883c */
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

void f_00998850(CPU *c) { /* PTR_00998850 */
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

void f_00998890(CPU *c) { /* PTR_00998890 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0x998960u)); switch (t_) { case 0x009989a7u: goto L_009989a7; default: jump_indirect(c, t_, 0x00998892u); return; } } /* jmp dword ptr [ecx*4 + 0x10008960] */
L_009989a7:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x9989b0u)); switch (t_) { case 0x009989c0u: goto L_009989c0; case 0x009989c8u: goto L_009989c8; case 0x009989d8u: goto L_009989d8; case 0x009989ecu: goto L_009989ec; default: jump_indirect(c, t_, 0x009989a7u); return; } } /* jmp dword ptr [edx*4 + 0x100089b0] */
L_009989c0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009989c8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009989d8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009989ec:;
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

void f_009988c8(CPU *c) { /* PTR_009988c8 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & c->ecx))); /* and edx, ecx */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) { f_00998890(c); return; } /* jb 0x998890 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x9989b0u)); switch (t_) { case 0x009989c0u: goto L_009989c0; case 0x009989c8u: goto L_009989c8; case 0x009989d8u: goto L_009989d8; case 0x009989ecu: goto L_009989ec; default: jump_indirect(c, t_, 0x009988deu); return; } } /* jmp dword ptr [edx*4 + 0x100089b0] */
L_009989c0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009989c8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009989d8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009989ec:;
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

void f_009988e8(CPU *c) { /* PTR_009988e8 */
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
    if (c->cf) { f_00998890(c); return; } /* jb 0x998890 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x9989b0u)); switch (t_) { case 0x009989c0u: goto L_009989c0; case 0x009989c8u: goto L_009989c8; case 0x009989d8u: goto L_009989d8; case 0x009989ecu: goto L_009989ec; default: jump_indirect(c, t_, 0x00998908u); return; } } /* jmp dword ptr [edx*4 + 0x100089b0] */
L_009989c0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009989c8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009989d8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009989ec:;
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

void f_00998910(CPU *c) { /* PTR_00998910 */
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
    if (c->cf) { f_00998890(c); return; } /* jb 0x998890 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x9989b0u)); switch (t_) { case 0x009989c0u: goto L_009989c0; case 0x009989c8u: goto L_009989c8; case 0x009989d8u: goto L_009989d8; case 0x009989ecu: goto L_009989ec; default: jump_indirect(c, t_, 0x0099893au); return; } } /* jmp dword ptr [edx*4 + 0x100089b0] */
L_009989c0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009989c8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009989d8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009989ec:;
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

void f_00998964(CPU *c) { /* PTR_00998964 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x9989b0u)); switch (t_) { case 0x009989c0u: goto L_009989c0; case 0x009989c8u: goto L_009989c8; case 0x009989d8u: goto L_009989d8; case 0x009989ecu: goto L_009989ec; default: jump_indirect(c, t_, 0x009989a7u); return; } } /* jmp dword ptr [edx*4 + 0x100089b0] */
L_009989c0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009989c8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009989d8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009989ec:;
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

void f_0099896c(CPU *c) { /* PTR_0099896c */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x9989b0u)); switch (t_) { case 0x009989c0u: goto L_009989c0; case 0x009989c8u: goto L_009989c8; case 0x009989d8u: goto L_009989d8; case 0x009989ecu: goto L_009989ec; default: jump_indirect(c, t_, 0x009989a7u); return; } } /* jmp dword ptr [edx*4 + 0x100089b0] */
L_009989c0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009989c8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009989d8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009989ec:;
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

void f_00998974(CPU *c) { /* PTR_00998974 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x9989b0u)); switch (t_) { case 0x009989c0u: goto L_009989c0; case 0x009989c8u: goto L_009989c8; case 0x009989d8u: goto L_009989d8; case 0x009989ecu: goto L_009989ec; default: jump_indirect(c, t_, 0x009989a7u); return; } } /* jmp dword ptr [edx*4 + 0x100089b0] */
L_009989c0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009989c8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009989d8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009989ec:;
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

void f_0099897c(CPU *c) { /* PTR_0099897c */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x9989b0u)); switch (t_) { case 0x009989c0u: goto L_009989c0; case 0x009989c8u: goto L_009989c8; case 0x009989d8u: goto L_009989d8; case 0x009989ecu: goto L_009989ec; default: jump_indirect(c, t_, 0x009989a7u); return; } } /* jmp dword ptr [edx*4 + 0x100089b0] */
L_009989c0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009989c8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009989d8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009989ec:;
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

void f_00998984(CPU *c) { /* PTR_00998984 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x9989b0u)); switch (t_) { case 0x009989c0u: goto L_009989c0; case 0x009989c8u: goto L_009989c8; case 0x009989d8u: goto L_009989d8; case 0x009989ecu: goto L_009989ec; default: jump_indirect(c, t_, 0x009989a7u); return; } } /* jmp dword ptr [edx*4 + 0x100089b0] */
L_009989c0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009989c8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009989d8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009989ec:;
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

void f_0099898c(CPU *c) { /* PTR_0099898c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x8u))); /* mov eax, dword ptr [esi + ecx*4 + 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x4u))); /* mov eax, dword ptr [esi + ecx*4 + 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x9989b0u)); switch (t_) { case 0x009989c0u: goto L_009989c0; case 0x009989c8u: goto L_009989c8; case 0x009989d8u: goto L_009989d8; case 0x009989ecu: goto L_009989ec; default: jump_indirect(c, t_, 0x009989a7u); return; } } /* jmp dword ptr [edx*4 + 0x100089b0] */
L_009989c0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009989c8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009989d8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009989ec:;
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

void f_00998994(CPU *c) { /* PTR_00998994 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x4u))); /* mov eax, dword ptr [esi + ecx*4 + 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x9989b0u)); switch (t_) { case 0x009989c0u: goto L_009989c0; case 0x009989c8u: goto L_009989c8; case 0x009989d8u: goto L_009989d8; case 0x009989ecu: goto L_009989ec; default: jump_indirect(c, t_, 0x009989a7u); return; } } /* jmp dword ptr [edx*4 + 0x100089b0] */
L_009989c0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009989c8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009989d8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009989ec:;
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

void f_009989a7(CPU *c) { /* PTR_009989a7 */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x9989b0u)); switch (t_) { case 0x009989c0u: goto L_009989c0; case 0x009989c8u: goto L_009989c8; case 0x009989d8u: goto L_009989d8; case 0x009989ecu: goto L_009989ec; default: jump_indirect(c, t_, 0x009989a7u); return; } } /* jmp dword ptr [edx*4 + 0x100089b0] */
L_009989c0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009989c8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009989d8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009989ec:;
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

void f_009989c0(CPU *c) { /* PTR_009989c0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_009989c8(CPU *c) { /* PTR_009989c8 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_009989d8(CPU *c) { /* PTR_009989d8 */
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

void f_009989ec(CPU *c) { /* PTR_009989ec */
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
