#include "recomp.h"

void f_006e1000(CPU *c) { /* FUN_10001000 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(logic32(c, (uint32_t)(c->esp & (uint32_t)0xfffffff8u))); /* and esp, 0xfffffff8 */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x11cu)); /* sub esp, 0x11c */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edx + 0x2cu)) & (uint8_t)0x2u)); /* test byte ptr [edx + 0x2c], 2 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_006e1026; /* jne 0x6e1026 */
    FPUSH(c, (double)RF32((uint32_t)(0x6ed0f8u))); /* fld dword ptr [0x1000d0f8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 12; return; /* ret 8 */
L_006e1026:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax))); /* fld dword ptr [eax] */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    WF64((uint32_t)(c->esp + 0x50u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x50] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x4u))); /* fld dword ptr [eax + 4] */
    c->esi = (uint32_t)((uint32_t)(c->esp + 0x50u)); /* lea esi, [esp + 0x50] */
    WF64((uint32_t)(c->esp + 0x58u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x58] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x8u))); /* fld dword ptr [eax + 8] */
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xa0u)); /* lea eax, [edx + 0xa0] */
    WF64((uint32_t)(c->esp + 0x60u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x60] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    c->ebx = (uint32_t)((uint32_t)(c->edx + 0xb8u)); /* lea ebx, [edx + 0xb8] */
    c->esi = (uint32_t)((uint32_t)(c->esp + 0x50u)); /* lea esi, [esp + 0x50] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx))); /* fld dword ptr [ecx] */
    c->edi = (uint32_t)(c->ebx); /* mov edi, ebx */
    WF64((uint32_t)(c->esp + 0x50u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x50] */
    W32((uint32_t)(c->esp + 0x40u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x40], 0 */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x4u))); /* fld dword ptr [ecx + 4] */
    WF64((uint32_t)(c->esp + 0x58u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x58] */
    W32((uint32_t)(c->esp + 0x44u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x44], 0 */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x8u))); /* fld dword ptr [ecx + 8] */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    WF64((uint32_t)(c->esp + 0x60u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x60] */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    FPUSH(c, RF64((uint32_t)(c->ebx))); /* fld qword ptr [ebx] */
    ST(0) = FPRES(c, ST(0) - RF64((uint32_t)(c->eax))); /* fsub qword ptr [eax] */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    WF64((uint32_t)(c->esp + 0x68u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x68] */
    c->esi = (uint32_t)((uint32_t)(c->esp + 0x68u)); /* lea esi, [esp + 0x68] */
    FPUSH(c, RF64((uint32_t)(c->ebx + 0x8u))); /* fld qword ptr [ebx + 8] */
    c->edi = (uint32_t)((uint32_t)(c->esp + 0x50u)); /* lea edi, [esp + 0x50] */
    ST(0) = FPRES(c, ST(0) - RF64((uint32_t)(c->eax + 0x8u))); /* fsub qword ptr [eax + 8] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x18], 0 */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)((uint32_t)0x3ff00000u)); /* mov dword ptr [esp + 0x1c], 0x3ff00000 */
    WF64((uint32_t)(c->esp + 0x70u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x70] */
    FPUSH(c, RF64((uint32_t)(c->ebx + 0x10u))); /* fld qword ptr [ebx + 0x10] */
    ST(0) = FPRES(c, ST(0) - RF64((uint32_t)(c->eax + 0x10u))); /* fsub qword ptr [eax + 0x10] */
    WF64((uint32_t)(c->esp + 0x78u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x78] */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->esi = (uint32_t)(R32((uint32_t)(c->edx + 0xcu))); /* mov esi, dword ptr [edx + 0xc] */
    c->ecx = (uint32_t)((uint32_t)0x771dd0u); /* mov ecx, 0x10091dd0 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x18u)); /* sub ecx, 0x18 */
    W32((uint32_t)(c->esp + 0x34u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x34], ecx */
L_006e10d4:;
    FPUSH(c, (double)RF32((uint32_t)(c->esi))); /* fld dword ptr [esi] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x4u))); /* fld dword ptr [esi + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x8u))); /* fld dword ptr [esi + 8] */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->edx + 0xb0u))); /* fmul qword ptr [edx + 0xb0] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->edx + 0xa8u))); /* fmul qword ptr [edx + 0xa8] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->edx + 0xa0u))); /* fmul qword ptr [edx + 0xa0] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esi + 0xcu))); /* fsub dword ptr [esi + 0xc] */
    WF64((uint32_t)(c->esp + 0x28u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x28] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi))); /* fld dword ptr [esi] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x4u))); /* fld dword ptr [esi + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x8u))); /* fld dword ptr [esi + 8] */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->edx + 0xc8u))); /* fmul qword ptr [edx + 0xc8] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->edx + 0xc0u))); /* fmul qword ptr [edx + 0xc0] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->edx + 0xb8u))); /* fmul qword ptr [edx + 0xb8] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esi + 0xcu))); /* fsub dword ptr [esi + 0xc] */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x28u))); /* fld qword ptr [esp + 0x28] */
    ST(0) = FPRES(c, ST(0) - ST(1)); /* fsub st(1) */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x28u))); /* fld qword ptr [esp + 0x28] */
    ST(0) = FPRES(c, FDIV(c, ST(0), ST(1))); /* fdiv st(1) */
    WF64((uint32_t)(c->esp + 0x10u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x10] */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x40u))); /* fld qword ptr [esp + 0x40] */
    FCOM(c, ST(0), RF64((uint32_t)(0x6ed0f0u))); FPOP(c); /* fcomp qword ptr [0x1000d0f0] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x41u)); /* test ah, 0x41 */
    if (!c->zf) goto L_006e115c; /* jne 0x6e115c */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x40u))); /* fld qword ptr [esp + 0x40] */
    ST(0) = FPRES(c, ST(0) - RF64((uint32_t)(0x6ed0f0u))); /* fsub qword ptr [0x1000d0f0] */
    FCOM(c, ST(0), RF64((uint32_t)(c->esp + 0x10u))); FPOP(c); /* fcomp qword ptr [esp + 0x10] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x1u)); /* test ah, 1 */
    if (c->zf) goto L_006e1350; /* je 0x6e1350 */
L_006e115c:;
    FCOM(c, ST(0), RF64((uint32_t)(0x6ed0e8u))); FPOP(c); /* fcomp qword ptr [0x1000d0e8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x44u)); /* test ah, 0x44 */
    if (!PF(c)) goto L_006e1352; /* jnp 0x6e1352 */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x10u))); /* fld qword ptr [esp + 0x10] */
    FCOM(c, ST(0), RF64((uint32_t)(0x6ed0e8u))); FPOP(c); /* fcomp qword ptr [0x1000d0e8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x41u)); /* test ah, 0x41 */
    if (!PF(c)) goto L_006e1352; /* jnp 0x6e1352 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x18u))); /* fld qword ptr [esp + 0x18] */
    FCOM(c, ST(0), RF64((uint32_t)(0x6ed0e0u))); FPOP(c); /* fcomp qword ptr [0x1000d0e0] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_006e11aa; /* jp 0x6e11aa */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x18u))); /* fld qword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) + RF64((uint32_t)(0x6ed0f0u))); /* fadd qword ptr [0x1000d0f0] */
    FCOM(c, ST(0), RF64((uint32_t)(c->esp + 0x10u))); FPOP(c); /* fcomp qword ptr [esp + 0x10] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x41u)); /* test ah, 0x41 */
    if (!PF(c)) goto L_006e11bb; /* jnp 0x6e11bb */
L_006e11aa:;
    FPUSH(c, RF64((uint32_t)(c->esp + 0x10u))); /* fld qword ptr [esp + 0x10] */
    FCOM(c, ST(0), RF64((uint32_t)(0x6ed0d8u))); FPOP(c); /* fcomp qword ptr [0x1000d0d8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x1u)); /* test ah, 1 */
    if (!c->zf) goto L_006e11f7; /* jne 0x6e11f7 */
L_006e11bb:;
    FPUSH(c, RF64((uint32_t)(c->esp + 0x28u))); /* fld qword ptr [esp + 0x28] */
    FCOM(c, ST(0), RF64((uint32_t)(0x6ed0e8u))); FPOP(c); /* fcomp qword ptr [0x1000d0e8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (!PF(c)) goto L_006e135f; /* jnp 0x6e135f */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov esi, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 28)); /* shr eax, 0x1c */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x3u))); /* and eax, 3 */
    if (c->zf) goto L_006e138f; /* je 0x6e138f */
L_006e11e1:;
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0x3fffffu))); /* and esi, 0x3fffff */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea eax, [esi + esi*2] */
    c->esi = (uint32_t)(R32((uint32_t)(c->edx + 0xcu))); /* mov esi, dword ptr [edx + 0xc] */
    c->esi = (uint32_t)((uint32_t)(c->esi + c->eax * 8)); /* lea esi, [esi + eax*8] */
    goto L_006e10d4; /* jmp 0x6e10d4 */
L_006e11f7:;
    FPUSH(c, RF64((uint32_t)(c->esp + 0x28u))); /* fld qword ptr [esp + 0x28] */
    FCOM(c, ST(0), RF64((uint32_t)(0x6ed0e8u))); FPOP(c); /* fcomp qword ptr [0x1000d0e8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    if (PF(c)) goto L_006e12b1; /* jp 0x6e12b1 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x800000u)); /* test eax, 0x800000 */
    if (c->zf) goto L_006e128b; /* je 0x6e128b */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov edi, dword ptr [esp + 0x1c] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x18u)); /* add ecx, 0x18 */
    W32((uint32_t)(c->ecx + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [ecx + 0xc], edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edi, dword ptr [esp + 0x14] */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->edi)); /* mov dword ptr [ecx + 4], edi */
    W32((uint32_t)(c->ecx + 0x10u), (uint32_t)(c->esi)); /* mov dword ptr [ecx + 0x10], esi */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->edi = (uint32_t)(shr32(c, c->edi, 28)); /* shr edi, 0x1c */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & (uint32_t)0x3u))); /* and edi, 3 */
    W32((uint32_t)(c->esp + 0x34u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x34], ecx */
    if (!c->zf) goto L_006e1251; /* jne 0x6e1251 */
    W32((uint32_t)(c->ecx + 0x14u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ecx + 0x14], 0 */
    goto L_006e1264; /* jmp 0x6e1264 */
L_006e1251:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x3fffffu))); /* and eax, 0x3fffff */
    c->eax = (uint32_t)(add32(c, c->eax, c->edi)); /* add eax, edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->edx + 0xcu))); /* mov edi, dword ptr [edx + 0xc] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea eax, [eax + eax*2] */
    c->eax = (uint32_t)((uint32_t)(c->edi + c->eax * 8)); /* lea eax, [edi + eax*8] */
    W32((uint32_t)(c->ecx + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 0x14], eax */
L_006e1264:;
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov esi, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edi, dword ptr [esp + 0x14] */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0x3fffffu))); /* and esi, 0x3fffff */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x18], eax */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea eax, [esi + esi*2] */
    c->esi = (uint32_t)(R32((uint32_t)(c->edx + 0xcu))); /* mov esi, dword ptr [edx + 0xc] */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x1c], edi */
    c->esi = (uint32_t)((uint32_t)(c->esi + c->eax * 8)); /* lea esi, [esi + eax*8] */
    goto L_006e10d4; /* jmp 0x6e10d4 */
L_006e128b:;
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->edi = (uint32_t)(shr32(c, c->edi, 28)); /* shr edi, 0x1c */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & (uint32_t)0x3u))); /* and edi, 3 */
    if (!c->zf) goto L_006e129c; /* jne 0x6e129c */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    goto L_006e13c3; /* jmp 0x6e13c3 */
L_006e129c:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x3fffffu))); /* and eax, 0x3fffff */
    c->eax = (uint32_t)(add32(c, c->eax, c->edi)); /* add eax, edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->edx + 0xcu))); /* mov edi, dword ptr [edx + 0xc] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea eax, [eax + eax*2] */
    c->edi = (uint32_t)((uint32_t)(c->edi + c->eax * 8)); /* lea edi, [edi + eax*8] */
    goto L_006e13c3; /* jmp 0x6e13c3 */
L_006e12b1:;
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x30000000u)); /* test eax, 0x30000000 */
    if (c->zf) goto L_006e1332; /* je 0x6e1332 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov edi, dword ptr [esp + 0x1c] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x18u)); /* add ecx, 0x18 */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    W32((uint32_t)(c->ecx + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [ecx + 0xc], edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edi, dword ptr [esp + 0x14] */
    W32((uint32_t)(c->ecx + 0x10u), (uint32_t)(c->esi)); /* mov dword ptr [ecx + 0x10], esi */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->edi)); /* mov dword ptr [ecx + 4], edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x800000u)); /* test eax, 0x800000 */
    W32((uint32_t)(c->esp + 0x34u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x34], ecx */
    if (!c->zf) goto L_006e12f0; /* jne 0x6e12f0 */
    W32((uint32_t)(c->ecx + 0x14u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ecx + 0x14], 0 */
    goto L_006e1301; /* jmp 0x6e1301 */
L_006e12f0:;
    c->edi = (uint32_t)(R32((uint32_t)(c->edx + 0xcu))); /* mov edi, dword ptr [edx + 0xc] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x3fffffu))); /* and eax, 0x3fffff */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea eax, [eax + eax*2] */
    c->eax = (uint32_t)((uint32_t)(c->edi + c->eax * 8)); /* lea eax, [edi + eax*8] */
    W32((uint32_t)(c->ecx + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 0x14], eax */
L_006e1301:;
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov esi, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edi, dword ptr [esp + 0x14] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x18], eax */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 28)); /* shr eax, 0x1c */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0x3fffffu))); /* and esi, 0x3fffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x3u))); /* and eax, 3 */
    c->eax = (uint32_t)(add32(c, c->eax, c->esi)); /* add eax, esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->edx + 0xcu))); /* mov esi, dword ptr [edx + 0xc] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea eax, [eax + eax*2] */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x1c], edi */
    c->esi = (uint32_t)((uint32_t)(c->esi + c->eax * 8)); /* lea esi, [esi + eax*8] */
    goto L_006e10d4; /* jmp 0x6e10d4 */
L_006e1332:;
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x800000u)); /* test eax, 0x800000 */
    if (!c->zf) goto L_006e1340; /* jne 0x6e1340 */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    goto L_006e13c3; /* jmp 0x6e13c3 */
L_006e1340:;
    c->edi = (uint32_t)(R32((uint32_t)(c->edx + 0xcu))); /* mov edi, dword ptr [edx + 0xc] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x3fffffu))); /* and eax, 0x3fffff */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea eax, [eax + eax*2] */
    c->edi = (uint32_t)((uint32_t)(c->edi + c->eax * 8)); /* lea edi, [edi + eax*8] */
    goto L_006e13c3; /* jmp 0x6e13c3 */
L_006e1350:;
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
L_006e1352:;
    FCOM(c, ST(0), RF64((uint32_t)(0x6ed0e8u))); FPOP(c); /* fcomp qword ptr [0x1000d0e8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_006e137e; /* jp 0x6e137e */
L_006e135f:;
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov esi, dword ptr [esi + 0x10] */
    (void)logic32(c, (uint32_t)(c->esi & (uint32_t)0x800000u)); /* test esi, 0x800000 */
    if (c->zf) goto L_006e138f; /* je 0x6e138f */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0x3fffffu))); /* and esi, 0x3fffff */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea eax, [esi + esi*2] */
    c->esi = (uint32_t)(R32((uint32_t)(c->edx + 0xcu))); /* mov esi, dword ptr [edx + 0xc] */
    c->esi = (uint32_t)((uint32_t)(c->esi + c->eax * 8)); /* lea esi, [esi + eax*8] */
    goto L_006e10d4; /* jmp 0x6e10d4 */
L_006e137e:;
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov esi, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 28)); /* shr eax, 0x1c */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x3u))); /* and eax, 3 */
    if (!c->zf) goto L_006e11e1; /* jne 0x6e11e1 */
L_006e138f:;
    (void)sub32(c, c->ecx, (uint32_t)0x771dd0u); /* cmp ecx, 0x10091dd0 */
    if (c->cf) goto L_006e16a4; /* jb 0x6e16a4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov eax, dword ptr [ecx + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov esi, dword ptr [ecx + 0xc] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov edi, dword ptr [ecx + 4] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x18], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x1c], esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x10u))); /* mov esi, dword ptr [ecx + 0x10] */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x14], edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ecx + 0x14u))); /* mov edi, dword ptr [ecx + 0x14] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x18u)); /* sub ecx, 0x18 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    W32((uint32_t)(c->esp + 0x34u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x34], ecx */
L_006e13c3:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x13u))); /* mov al, byte ptr [esi + 0x13] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfu))); /* and al, 0xf */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x24], edi */
    if ((c->cf || c->zf)) goto L_006e1685; /* jbe 0x6e1685 */
    c->edi = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov edi, dword ptr [edx + 4] */
    W8((uint32_t)(c->esp + 0xfu), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [esp + 0xf], al */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x14u)); /* add esi, 0x14 */
    c->esp = (uint32_t)((uint32_t)(c->esp)); /* lea esp, [esp] */
L_006e13e0:;
    c->ecx = (uint32_t)((uint32_t)R8((uint32_t)(c->esi))); /* movzx ecx, byte ptr [esi] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->esi + 0x2u))) << 8); /* mov ah, byte ptr [esi + 2] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->ecx))); /* or eax, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov ecx, dword ptr [edx + 8] */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->eax * 8)); /* lea ecx, [ecx + eax*8] */
    c->ebx = (uint32_t)((uint32_t)R8((uint32_t)(c->eax + c->ecx))); /* movzx ebx, byte ptr [eax + ecx] */
    W32((uint32_t)(c->esp + 0x4cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x4c], eax */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->eax + 0x2u))) << 8); /* mov ch, byte ptr [eax + 2] */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1u))); /* mov cl, byte ptr [eax + 1] */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 8)); /* shl ecx, 8 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->ebx))); /* or ecx, ebx */
    c->ebx = (uint32_t)((uint32_t)R8((uint32_t)(c->eax + 0x3u))); /* movzx ebx, byte ptr [eax + 3] */
    W32((uint32_t)(c->esp + 0xb0u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0xb0], ecx */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->eax + 0x5u))) << 8); /* mov ch, byte ptr [eax + 5] */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x4u))); /* mov cl, byte ptr [eax + 4] */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 8)); /* shl ecx, 8 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->ebx))); /* or ecx, ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->ebx = (c->ebx & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->eax + 0x8u))) << 8); /* mov bh, byte ptr [eax + 8] */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea ecx, [ecx + ecx*2] */
    FPUSH(c, (double)RF32((uint32_t)(c->edi + c->ecx * 4))); /* fld dword ptr [edi + ecx*4] */
    c->ecx = (uint32_t)((uint32_t)(c->edi + c->ecx * 4)); /* lea ecx, [edi + ecx*4] */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x7u))); /* mov bl, byte ptr [eax + 7] */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->eax + 0x6u))); /* movzx eax, byte ptr [eax + 6] */
    c->ebx = (uint32_t)(shl32(c, c->ebx, 8)); /* shl ebx, 8 */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | c->eax))); /* or ebx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xb0u))); /* mov eax, dword ptr [esp + 0xb0] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea eax, [eax + eax*2] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->edi + c->eax * 4))); /* fsub dword ptr [edi + eax*4] */
    c->eax = (uint32_t)((uint32_t)(c->edi + c->eax * 4)); /* lea eax, [edi + eax*4] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x4u))); /* fld dword ptr [ecx + 4] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->eax + 0x4u))); /* fsub dword ptr [eax + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x8u))); /* fld dword ptr [ecx + 8] */
    c->ecx = (uint32_t)((uint32_t)(c->ebx + c->ebx * 2)); /* lea ecx, [ebx + ebx*2] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->eax + 0x8u))); /* fsub dword ptr [eax + 8] */
    c->ecx = (uint32_t)((uint32_t)(c->edi + c->ecx * 4)); /* lea ecx, [edi + ecx*4] */
    WF32((uint32_t)(c->esp + 0xacu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xac] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    WF64((uint32_t)(c->esp + 0x8cu), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x8c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xacu))); /* fld dword ptr [esp + 0xac] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx))); /* fld dword ptr [ecx] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->eax))); /* fsub dword ptr [eax] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x4u))); /* fld dword ptr [ecx + 4] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->eax + 0x4u))); /* fsub dword ptr [eax + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x8u))); /* fld dword ptr [ecx + 8] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->eax + 0x8u))); /* fsub dword ptr [eax + 8] */
    WF32((uint32_t)(c->esp + 0xc4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xc4] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    WF64((uint32_t)(c->esp + 0xc8u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0xc8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xc4u))); /* fld dword ptr [esp + 0xc4] */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x58u))); /* fld qword ptr [esp + 0x58] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x60u))); /* fld qword ptr [esp + 0x60] */
    ST(0) = FPRES(c, ST(0) * ST(3)); /* fmul st(3) */
    ST(1) = FPRES(c, ST(1) - ST(0)); FPOP(c); /* fsubp st(1) */
    WF64((uint32_t)(c->esp + 0xe0u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0xe0] */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x60u))); /* fld qword ptr [esp + 0x60] */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->esp + 0xc8u))); /* fmul qword ptr [esp + 0xc8] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->esp + 0x50u))); /* fmul qword ptr [esp + 0x50] */
    ST(1) = FPRES(c, ST(1) - ST(0)); FPOP(c); /* fsubp st(1) */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->esp + 0x50u))); /* fmul qword ptr [esp + 0x50] */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x58u))); /* fld qword ptr [esp + 0x58] */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->esp + 0xc8u))); /* fmul qword ptr [esp + 0xc8] */
    ST(1) = FPRES(c, ST(1) - ST(0)); FPOP(c); /* fsubp st(1) */
    FPUSH(c, RF64((uint32_t)(c->esp + 0xe0u))); /* fld qword ptr [esp + 0xe0] */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->esp + 0x8cu))); /* fmul qword ptr [esp + 0x8c] */
    { double v_ = ST(3); FPUSH(c, v_); } /* fld st(3) */
    ST(0) = FPRES(c, ST(0) * ST(2)); /* fmul st(2) */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    { double v_ = ST(4); FPUSH(c, v_); } /* fld st(4) */
    ST(0) = FPRES(c, ST(0) * ST(3)); /* fmul st(3) */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF64((uint32_t)(c->esp + 0x28u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x28] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax))); /* fld dword ptr [eax] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x4u))); /* fld dword ptr [eax + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x8u))); /* fld dword ptr [eax + 8] */
    WF64((uint32_t)(c->esp + 0x108u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x108] */
    FPUSH(c, RF64((uint32_t)(c->edx + 0xa0u))); /* fld qword ptr [edx + 0xa0] */
    ST(0) = FPRES(c, ST(0) - ST(2)); /* fsub st(2) */
    WF64((uint32_t)(c->esp + 0x68u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x68] */
    FPUSH(c, RF64((uint32_t)(c->edx + 0xa8u))); /* fld qword ptr [edx + 0xa8] */
    ST(0) = FPRES(c, ST(0) - ST(1)); /* fsub st(1) */
    WF64((uint32_t)(c->esp + 0x70u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x70] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, RF64((uint32_t)(c->edx + 0xb0u))); /* fld qword ptr [edx + 0xb0] */
    ST(0) = FPRES(c, ST(0) - RF64((uint32_t)(c->esp + 0x108u))); /* fsub qword ptr [esp + 0x108] */
    WF64((uint32_t)(c->esp + 0x78u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x78] */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x68u))); /* fld qword ptr [esp + 0x68] */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->esp + 0xe0u))); /* fmul qword ptr [esp + 0xe0] */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x78u))); /* fld qword ptr [esp + 0x78] */
    ST(0) = FPRES(c, ST(0) * ST(2)); /* fmul st(2) */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x70u))); /* fld qword ptr [esp + 0x70] */
    ST(0) = FPRES(c, ST(0) * ST(3)); /* fmul st(3) */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF64((uint32_t)(c->esp + 0x38u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x38] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x70u))); /* fld qword ptr [esp + 0x70] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x78u))); /* fld qword ptr [esp + 0x78] */
    ST(0) = FPRES(c, ST(0) * ST(3)); /* fmul st(3) */
    ST(1) = FPRES(c, ST(1) - ST(0)); FPOP(c); /* fsubp st(1) */
    WF64((uint32_t)(c->esp + 0x110u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x110] */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x78u))); /* fld qword ptr [esp + 0x78] */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->esp + 0x8cu))); /* fmul qword ptr [esp + 0x8c] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->esp + 0x68u))); /* fmul qword ptr [esp + 0x68] */
    ST(1) = FPRES(c, ST(1) - ST(0)); FPOP(c); /* fsubp st(1) */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->esp + 0x68u))); /* fmul qword ptr [esp + 0x68] */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x70u))); /* fld qword ptr [esp + 0x70] */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->esp + 0x8cu))); /* fmul qword ptr [esp + 0x8c] */
    ST(1) = FPRES(c, ST(1) - ST(0)); FPOP(c); /* fsubp st(1) */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x110u))); /* fld qword ptr [esp + 0x110] */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->esp + 0x50u))); /* fmul qword ptr [esp + 0x50] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->esp + 0x60u))); /* fmul qword ptr [esp + 0x60] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->esp + 0x58u))); /* fmul qword ptr [esp + 0x58] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF64((uint32_t)(c->esp + 0x80u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x80] */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x28u))); /* fld qword ptr [esp + 0x28] */
    FCOM(c, ST(0), RF64((uint32_t)(0x6ed0e8u))); FPOP(c); /* fcomp qword ptr [0x1000d0e8] */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x38u))); /* fld qword ptr [esp + 0x38] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    FCOM(c, ST(0), RF64((uint32_t)(0x6ed0e8u))); FPOP(c); /* fcomp qword ptr [0x1000d0e8] */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    if (PF(c)) goto L_006e1631; /* jp 0x6e1631 */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_006e166f; /* jp 0x6e166f */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x38u))); /* fld qword ptr [esp + 0x38] */
    FCOM(c, ST(0), RF64((uint32_t)(c->esp + 0x28u))); FPOP(c); /* fcomp qword ptr [esp + 0x28] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x41u)); /* test ah, 0x41 */
    if (!c->zf) goto L_006e166f; /* jne 0x6e166f */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x80u))); /* fld qword ptr [esp + 0x80] */
    FCOM(c, ST(0), RF64((uint32_t)(0x6ed0e8u))); FPOP(c); /* fcomp qword ptr [0x1000d0e8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_006e166f; /* jp 0x6e166f */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x80u))); /* fld qword ptr [esp + 0x80] */
    ST(0) = FPRES(c, ST(0) + RF64((uint32_t)(c->esp + 0x38u))); /* fadd qword ptr [esp + 0x38] */
    FCOM(c, ST(0), RF64((uint32_t)(c->esp + 0x28u))); FPOP(c); /* fcomp qword ptr [esp + 0x28] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x41u)); /* test ah, 0x41 */
    if (!c->zf) goto L_006e166f; /* jne 0x6e166f */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4cu))); /* mov ecx, dword ptr [esp + 0x4c] */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x10u))); /* fld qword ptr [esp + 0x10] */
    WF32((uint32_t)(c->edx + 0x20u), (float)ST(0)); /* fst dword ptr [edx + 0x20] */
    W32((uint32_t)(c->edx + 0x9cu), (uint32_t)(c->ecx)); /* mov dword ptr [edx + 0x9c], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 12; return; /* ret 8 */
L_006e1631:;
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x1u)); /* test ah, 1 */
    if (!c->zf) goto L_006e166f; /* jne 0x6e166f */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x38u))); /* fld qword ptr [esp + 0x38] */
    FCOM(c, ST(0), RF64((uint32_t)(c->esp + 0x28u))); FPOP(c); /* fcomp qword ptr [esp + 0x28] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x41u)); /* test ah, 0x41 */
    if (PF(c)) goto L_006e166f; /* jp 0x6e166f */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x80u))); /* fld qword ptr [esp + 0x80] */
    FCOM(c, ST(0), RF64((uint32_t)(0x6ed0e8u))); FPOP(c); /* fcomp qword ptr [0x1000d0e8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x1u)); /* test ah, 1 */
    if (!c->zf) goto L_006e166f; /* jne 0x6e166f */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x80u))); /* fld qword ptr [esp + 0x80] */
    ST(0) = FPRES(c, ST(0) + RF64((uint32_t)(c->esp + 0x38u))); /* fadd qword ptr [esp + 0x38] */
    FCOM(c, ST(0), RF64((uint32_t)(c->esp + 0x28u))); FPOP(c); /* fcomp qword ptr [esp + 0x28] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x41u)); /* test ah, 0x41 */
    if (!PF(c)) goto L_006e16bd; /* jnp 0x6e16bd */
L_006e166f:;
    { uint32_t a_ = (uint32_t)(c->esp + 0xfu); W8(a_, (uint8_t)(dec8(c, R8(a_)))); } /* dec byte ptr [esp + 0xf] */
    if (c->zf) goto L_006e167d; /* je 0x6e167d */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x3u)); /* add esi, 3 */
    goto L_006e13e0; /* jmp 0x6e13e0 */
L_006e167d:;
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov edi, dword ptr [esp + 0x24] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov ecx, dword ptr [esp + 0x34] */
L_006e1685:;
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_006e138f; /* je 0x6e138f */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov esi, dword ptr [esp + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    W32((uint32_t)(c->esp + 0x44u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x44], esi */
    W32((uint32_t)(c->esp + 0x40u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x40], eax */
    c->esi = (uint32_t)(c->edi); /* mov esi, edi */
    goto L_006e10d4; /* jmp 0x6e10d4 */
L_006e16a4:;
    W32((uint32_t)(c->edx + 0x9cu), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [edx + 0x9c], 0xffffffff */
    FPUSH(c, (double)RF32((uint32_t)(0x6ed0f8u))); /* fld dword ptr [0x1000d0f8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 12; return; /* ret 8 */
L_006e16bd:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4cu))); /* mov eax, dword ptr [esp + 0x4c] */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x10u))); /* fld qword ptr [esp + 0x10] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    WF32((uint32_t)(c->edx + 0x20u), (float)ST(0)); /* fst dword ptr [edx + 0x20] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->edx + 0x9cu), (uint32_t)(c->eax)); /* mov dword ptr [edx + 0x9c], eax */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 12; return; /* ret 8 */
}

void f_006e16e0(CPU *c) { /* PTR_006e16e0 */
    PREEMPT_POLL(c);
    c->esp += 4; return; /* ret  */
}

void f_006e16f0(CPU *c) { /* FUN_100016f0 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x20u)); /* sub esp, 0x20 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov edi, dword ptr [esp + 0x34] */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if ((c->zf || c->sf != c->of)) goto L_006e173b; /* jle 0x6e173b */
    c->ecx = (uint32_t)((uint32_t)0x770dd4u); /* mov ecx, 0x10090dd4 */
    c->esi = (uint32_t)(c->edi); /* mov esi, edi */
    ; /* nop  */
    c->esp = (uint32_t)((uint32_t)(c->esp)); /* lea esp, [esp] */
L_006e1710:;
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0xfffffffcu))); /* fld dword ptr [ecx - 4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edx))); /* fmul dword ptr [edx] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x4u))); /* fld dword ptr [ecx + 4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edx + 0x8u))); /* fmul dword ptr [edx + 8] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + 0x4u))); /* fld dword ptr [edx + 4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ecx))); /* fmul dword ptr [ecx] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->edx + 0xcu))); /* fsub dword ptr [edx + 0xc] */
    FCOM(c, ST(0), RF64((uint32_t)(0x6ed0e8u))); FPOP(c); /* fcomp qword ptr [0x1000d0e8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_006e1735; /* jp 0x6e1735 */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
L_006e1735:;
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0xcu)); /* add ecx, 0xc */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    if (!c->zf) goto L_006e1710; /* jne 0x6e1710 */
L_006e173b:;
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    if (c->zf) goto L_006e1a71; /* je 0x6e1a71 */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (c->zf) goto L_006e1a71; /* je 0x6e1a71 */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    W32((uint32_t)(c->esp + 0x30u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x30], esi */
    if ((c->zf || c->sf != c->of)) goto L_006e19c3; /* jle 0x6e19c3 */
    c->ebx = (uint32_t)((uint32_t)0x770dd4u); /* mov ebx, 0x10090dd4 */
    c->edi = (uint32_t)(c->edi); /* mov edi, edi */
L_006e1760:;
    FPUSH(c, (double)RF32((uint32_t)(c->ebx + 0xfffffffcu))); /* fld dword ptr [ebx - 4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edx))); /* fmul dword ptr [edx] */
    FPUSH(c, (double)RF32((uint32_t)(c->ebx + 0x4u))); /* fld dword ptr [ebx + 4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edx + 0x8u))); /* fmul dword ptr [edx + 8] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->ebx))); /* fld dword ptr [ebx] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edx + 0x4u))); /* fmul dword ptr [edx + 4] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->edx + 0xcu))); /* fsub dword ptr [edx + 0xc] */
    WF32((uint32_t)(c->esp + 0x1cu), (float)ST(0)); /* fst dword ptr [esp + 0x1c] */
    FCOM(c, ST(0), RF64((uint32_t)(0x6ed0e8u))); FPOP(c); /* fcomp qword ptr [0x1000d0e8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x41u)); /* test ah, 0x41 */
    if (!c->zf) goto L_006e17c9; /* jne 0x6e17c9 */
    (void)sub32(c, c->esi, (uint32_t)0x1u); /* cmp esi, 1 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0xffffffffu)); /* lea ecx, [esi - 1] */
    if ((c->sf == c->of)) goto L_006e1793; /* jge 0x6e1793 */
    c->ecx = (uint32_t)((uint32_t)(c->edi + 0xffffffffu)); /* lea ecx, [edi - 1] */
L_006e1793:;
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea eax, [ecx + ecx*2] */
    c->eax = (uint32_t)(shl32(c, c->eax, 2)); /* shl eax, 2 */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x770dd8u))); /* fld dword ptr [eax + 0x10090dd8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edx + 0x8u))); /* fmul dword ptr [edx + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x770dd0u))); /* fld dword ptr [eax + 0x10090dd0] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edx))); /* fmul dword ptr [edx] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x770dd4u))); /* fld dword ptr [eax + 0x10090dd4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edx + 0x4u))); /* fmul dword ptr [edx + 4] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->edx + 0xcu))); /* fsub dword ptr [edx + 0xc] */
    FCOM(c, ST(0), RF64((uint32_t)(0x6ed0e8u))); /* fcom qword ptr [0x1000d0e8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x41u)); /* test ah, 0x41 */
    if (!c->zf) goto L_006e17de; /* jne 0x6e17de */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
L_006e17c9:;
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0xcu)); /* add ebx, 0xc */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if ((c->sf != c->of)) goto L_006e1760; /* jl 0x6e1760 */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x2c], esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    c->esp += 4; return; /* ret  */
L_006e17de:;
    ST(0) = FPRES(c, (double)RF32((uint32_t)(c->esp + 0x1cu)) - ST(0)); /* fsubr dword ptr [esp + 0x1c] */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea ecx, [ecx + ecx*2] */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 2)); /* shl ecx, 2 */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea eax, [esi + esi*2] */
    c->eax = (uint32_t)(shl32(c, c->eax, 2)); /* shl eax, 2 */
    ST(0) = FPRES(c, FDIV(c, (double)RF32((uint32_t)(c->esp + 0x1cu)), ST(0))); /* fdivr dword ptr [esp + 0x1c] */
    W32((uint32_t)(c->esp + 0x30u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x30], esi */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x770dd0u))); /* fld dword ptr [ecx + 0x10090dd0] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->eax + 0x770dd0u))); /* fsub dword ptr [eax + 0x10090dd0] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->eax + 0x770dd0u))); /* fadd dword ptr [eax + 0x10090dd0] */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x770dd4u))); /* fld dword ptr [ecx + 0x10090dd4] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->eax + 0x770dd4u))); /* fsub dword ptr [eax + 0x10090dd4] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->eax + 0x770dd4u))); /* fadd dword ptr [eax + 0x10090dd4] */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x770dd8u))); /* fld dword ptr [ecx + 0x10090dd8] */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x1u)); /* lea ecx, [esi + 1] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->eax + 0x770dd8u))); /* fsub dword ptr [eax + 0x10090dd8] */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0xc], ecx */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->eax + 0x770dd8u))); /* fadd dword ptr [eax + 0x10090dd8] */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    if ((c->sf != c->of)) goto L_006e184f; /* jl 0x6e184f */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
L_006e184f:;
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->ebx * 2)); /* lea eax, [ebx + ebx*2] */
    c->eax = (uint32_t)(shl32(c, c->eax, 2)); /* shl eax, 2 */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x770dd4u))); /* fld dword ptr [eax + 0x10090dd4] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edx + 0x4u))); /* fmul dword ptr [edx + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x770dd8u))); /* fld dword ptr [eax + 0x10090dd8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edx + 0x8u))); /* fmul dword ptr [edx + 8] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x770dd0u))); /* fld dword ptr [eax + 0x10090dd0] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edx))); /* fmul dword ptr [edx] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->edx + 0xcu))); /* fsub dword ptr [edx + 0xc] */
    FCOM(c, ST(0), RF64((uint32_t)(0x6ed0e8u))); FPOP(c); /* fcomp qword ptr [0x1000d0e8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x41u)); /* test ah, 0x41 */
    if (PF(c)) goto L_006e19cc; /* jp 0x6e19cc */
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    if ((c->zf || c->sf != c->of)) goto L_006e18ca; /* jle 0x6e18ca */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    c->eax = (uint32_t)((uint32_t)(c->edi + c->edi * 2)); /* lea eax, [edi + edi*2] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->ebx)); /* sub ecx, ebx */
    c->eax = (uint32_t)((uint32_t)(c->eax * 4 + 0x770dd0u)); /* lea eax, [eax*4 + 0x10090dd0] */
    W32((uint32_t)(c->esp + 0x38u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x38], ecx */
    c->edi = (uint32_t)(c->edi); /* mov edi, edi */
L_006e18a0:;
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0xfffffff4u)); /* lea ecx, [eax - 0xc] */
    W32((uint32_t)(c->esp + 0x34u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x34], ecx */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov ebp, dword ptr [ecx] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ebp)); /* mov dword ptr [eax], ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ebp, dword ptr [ecx + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov ecx, dword ptr [ecx + 8] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ebp)); /* mov dword ptr [eax + 4], ebp */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x38u))); /* mov ecx, dword ptr [esp + 0x38] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov eax, dword ptr [esp + 0x34] */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    W32((uint32_t)(c->esp + 0x38u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x38], ecx */
    if (!c->zf) goto L_006e18a0; /* jne 0x6e18a0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
L_006e18ca:;
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if ((c->zf || c->sf != c->of)) goto L_006e18d4; /* jle 0x6e18d4 */
    W32((uint32_t)(c->esp + 0x34u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x34], ecx */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
L_006e18d4:;
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
L_006e18d5:;
    c->ecx = (uint32_t)((uint32_t)(c->ebx + 0xffffffffu)); /* lea ecx, [ebx - 1] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    if ((c->sf == c->of)) goto L_006e18e0; /* jge 0x6e18e0 */
    c->ecx = (uint32_t)((uint32_t)(c->edi + 0xffffffffu)); /* lea ecx, [edi - 1] */
L_006e18e0:;
    FPUSH(c, (double)RF32((uint32_t)(c->edx + 0x8u))); /* fld dword ptr [edx + 8] */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->ebx * 2)); /* lea eax, [ebx + ebx*2] */
    c->eax = (uint32_t)(shl32(c, c->eax, 2)); /* shl eax, 2 */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x770dd8u))); /* fmul dword ptr [eax + 0x10090dd8] */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea ecx, [ecx + ecx*2] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x770dd4u))); /* fld dword ptr [eax + 0x10090dd4] */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 2)); /* shl ecx, 2 */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edx + 0x4u))); /* fmul dword ptr [edx + 4] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x770dd0u))); /* fld dword ptr [eax + 0x10090dd0] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edx))); /* fmul dword ptr [edx] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->edx + 0xcu))); /* fsub dword ptr [edx + 0xc] */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + 0x8u))); /* fld dword ptr [edx + 8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ecx + 0x770dd8u))); /* fmul dword ptr [ecx + 0x10090dd8] */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + 0x4u))); /* fld dword ptr [edx + 4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ecx + 0x770dd4u))); /* fmul dword ptr [ecx + 0x10090dd4] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x770dd0u))); /* fld dword ptr [ecx + 0x10090dd0] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edx))); /* fmul dword ptr [edx] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->edx + 0xcu))); /* fsub dword ptr [edx + 0xc] */
    { double v_ = ST(1); FPUSH(c, v_); } /* fld st(1) */
    ST(0) = FPRES(c, ST(0) - ST(1)); /* fsub st(1) */
    ST(2) = FPRES(c, FDIV(c, ST(2), ST(0))); FPOP(c); /* fdivp st(2) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x770dd0u))); /* fld dword ptr [ecx + 0x10090dd0] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->eax + 0x770dd0u))); /* fsub dword ptr [eax + 0x10090dd0] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->eax + 0x770dd0u))); /* fadd dword ptr [eax + 0x10090dd0] */
    WF32((uint32_t)(c->esp + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1c] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x770dd4u))); /* fld dword ptr [ecx + 0x10090dd4] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->eax + 0x770dd4u))); /* fsub dword ptr [eax + 0x10090dd4] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->eax + 0x770dd4u))); /* fadd dword ptr [eax + 0x10090dd4] */
    WF32((uint32_t)(c->esp + 0x20u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x20] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x770dd8u))); /* fld dword ptr [ecx + 0x10090dd8] */
    c->ecx = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea ecx, [esi + esi*2] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->eax + 0x770dd8u))); /* fsub dword ptr [eax + 0x10090dd8] */
    c->edx = (uint32_t)((uint32_t)(c->ecx * 4 + 0x770dd0u)); /* lea edx, [ecx*4 + 0x10090dd0] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ecx, dword ptr [esp + 0x14] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->eax + 0x770dd8u))); /* fadd dword ptr [eax + 0x10090dd8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    W32((uint32_t)(c->edx), (uint32_t)(c->eax)); /* mov dword ptr [edx], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    WF32((uint32_t)(c->esp + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x24] */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [edx + 4], ecx */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [edx + 8], eax */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    if ((c->sf != c->of)) goto L_006e19a5; /* jl 0x6e19a5 */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_006e19a5:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov eax, dword ptr [esp + 0x1c] */
    c->ecx = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea ecx, [esi + esi*2] */
    c->edx = (uint32_t)((uint32_t)(c->ecx * 4 + 0x770dd0u)); /* lea edx, [ecx*4 + 0x10090dd0] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov ecx, dword ptr [esp + 0x20] */
    W32((uint32_t)(c->edx), (uint32_t)(c->eax)); /* mov dword ptr [edx], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov eax, dword ptr [esp + 0x24] */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [edx + 4], ecx */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [edx + 8], eax */
L_006e19c3:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    c->esp += 4; return; /* ret  */
L_006e19cc:;
    c->ecx = (uint32_t)((uint32_t)(c->edi + 0xffffffffu)); /* lea ecx, [edi - 1] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x10], ecx */
L_006e19d3:;
    c->ebp = (uint32_t)(c->ebx); /* mov ebp, ebx */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    if ((c->sf != c->of)) goto L_006e19dc; /* jl 0x6e19dc */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
L_006e19dc:;
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->ebx * 2)); /* lea eax, [ebx + ebx*2] */
    c->eax = (uint32_t)(shl32(c, c->eax, 2)); /* shl eax, 2 */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x770dd4u))); /* fld dword ptr [eax + 0x10090dd4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edx + 0x4u))); /* fmul dword ptr [edx + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x770dd8u))); /* fld dword ptr [eax + 0x10090dd8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edx + 0x8u))); /* fmul dword ptr [edx + 8] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x770dd0u))); /* fld dword ptr [eax + 0x10090dd0] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edx))); /* fmul dword ptr [edx] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->edx + 0xcu))); /* fsub dword ptr [edx + 0xc] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0x6ed0fcu))); FPOP(c); /* fcomp dword ptr [0x1000d0fc] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x41u)); /* test ah, 0x41 */
    if (!PF(c)) goto L_006e18d5; /* jnp 0x6e18d5 */
    (void)sub32(c, c->ebp, c->ecx); /* cmp ebp, ecx */
    if ((c->sf == c->of)) goto L_006e1a50; /* jge 0x6e1a50 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + c->ebp * 2)); /* lea eax, [ebp + ebp*2] */
    c->eax = (uint32_t)(shl32(c, c->eax, 2)); /* shl eax, 2 */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea ecx, [ecx + ecx*2] */
    c->edi = (uint32_t)((uint32_t)(c->eax + 0x770dd0u)); /* lea edi, [eax + 0x10090dd0] */
    c->esi = (uint32_t)((uint32_t)(c->eax + 0x770ddcu)); /* lea esi, [eax + 0x10090ddc] */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 2)); /* shl ecx, 2 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + c->ebp * 2)); /* lea eax, [ebp + ebp*2] */
    c->eax = (uint32_t)(shl32(c, c->eax, 2)); /* shl eax, 2 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov esi, dword ptr [esp + 0x34] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x38u))); /* mov edi, dword ptr [esp + 0x38] */
    ; /* nop  */
    c->esp = (uint32_t)((uint32_t)(c->esp)); /* lea esp, [esp] */
L_006e1a50:;
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    (void)sub32(c, c->ebp, c->esi); /* cmp ebp, esi */
    W32((uint32_t)(c->esp + 0x38u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x38], edi */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x10], ecx */
    if ((c->sf == c->of)) goto L_006e1a63; /* jge 0x6e1a63 */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    W32((uint32_t)(c->esp + 0x34u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x34], esi */
L_006e1a63:;
    (void)sub32(c, c->ebp, c->ebx); /* cmp ebp, ebx */
    if ((c->sf == c->of)) goto L_006e19d3; /* jge 0x6e19d3 */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    goto L_006e19d3; /* jmp 0x6e19d3 */
L_006e1a71:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    c->esp += 4; return; /* ret  */
}

void f_006e1a80(CPU *c) { /* PTR_006e1a80 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x24u)); /* sub esp, 0x24 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->ecx); /* mov ebp, ecx */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0x2cu)) & (uint8_t)0x2u)); /* test byte ptr [ebp + 0x2c], 2 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (c->zf) goto L_006e1cdd; /* je 0x6e1cdd */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x40u))); /* mov eax, dword ptr [esp + 0x40] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax))); /* fld dword ptr [eax] */
    WF64((uint32_t)(c->esp + 0x1cu), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x1c] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x4u))); /* fld dword ptr [eax + 4] */
    WF64((uint32_t)(c->esp + 0x24u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x24] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x8u))); /* fld dword ptr [eax + 8] */
    { uint32_t a_ = (uint32_t)(0x6ee050u); W16(a_, (uint16_t)(inc16(c, R16(a_)))); } /* inc word ptr [0x1000e050] */
    WF64((uint32_t)(c->esp + 0x2cu), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x2c] */
    if (!c->zf) goto L_006e1acb; /* jne 0x6e1acb */
    c->ecx = (uint32_t)((uint32_t)0x20000u); /* mov ecx, 0x20000 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edi = (uint32_t)((uint32_t)0x6f0dd0u); /* mov edi, 0x10010dd0 */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
    W16((uint32_t)(0x6ee050u), (uint16_t)((uint16_t)0x1u)); /* mov word ptr [0x1000e050], 1 */
L_006e1acb:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x44u))); /* fld dword ptr [esp + 0x44] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x44u))); /* fmul dword ptr [esp + 0x44] */
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    W32((uint32_t)(c->esp + 0x40u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x40], edx */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi | (uint32_t)0xffffffffu))); /* or esi, 0xffffffff */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
L_006e1ae3:;
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x10], esi */
L_006e1ae7:;
    FPUSH(c, (double)RF32((uint32_t)(c->edx))); /* fld dword ptr [edx] */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + 0x4u))); /* fld dword ptr [edx + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + 0x8u))); /* fld dword ptr [edx + 8] */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x2cu))); /* fld qword ptr [esp + 0x2c] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    { double t_ = ST(0); ST(0) = ST(3); ST(3) = t_; } /* fxch st(3) */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->esp + 0x1cu))); /* fmul qword ptr [esp + 0x1c] */
    ST(3) = FPRES(c, ST(3) + ST(0)); FPOP(c); /* faddp st(3) */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x24u))); /* fld qword ptr [esp + 0x24] */
    ST(0) = FPRES(c, ST(0) * ST(2)); /* fmul st(2) */
    ST(3) = FPRES(c, ST(3) + ST(0)); FPOP(c); /* faddp st(3) */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + 0xcu))); /* fld dword ptr [edx + 0xc] */
    ST(3) = FPRES(c, ST(3) - ST(0)); FPOP(c); /* fsubp st(3) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    FCOM(c, ST(0), ST(1)); FPOP(c); FPOP(c); /* fcompp  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x41u)); /* test ah, 0x41 */
    if (!c->zf) goto L_006e1c79; /* jne 0x6e1c79 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx + 0x13u))); /* mov cl, byte ptr [edx + 0x13] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0xfu)); /* test cl, 0xf */
    c->eax = (uint32_t)((uint32_t)(c->edx + 0x14u)); /* lea eax, [edx + 0x14] */
    W32((uint32_t)(c->esp + 0x44u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x44], eax */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x14], 0 */
    if ((c->cf || c->zf)) goto L_006e1c36; /* jbe 0x6e1c36 */
L_006e1b40:;
    c->ecx = (uint32_t)((uint32_t)R8((uint32_t)(c->eax))); /* movzx ecx, byte ptr [eax] */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->ebx = (c->ebx & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->eax + 0x2u))) << 8); /* mov bh, byte ptr [eax + 2] */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1u))); /* mov bl, byte ptr [eax + 1] */
    c->ebx = (uint32_t)(shl32(c, c->ebx, 8)); /* shl ebx, 8 */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | c->ecx))); /* or ebx, ecx */
    c->ecx = (c->ecx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(0x6ee050u))); /* mov cx, word ptr [0x1000e050] */
    (void)sub16(c, R16((uint32_t)(c->ebx * 2 + 0x6f0dd0u)), ((uint16_t)c->ecx)); /* cmp word ptr [ebx*2 + 0x10010dd0], cx */
    if (c->zf) goto L_006e1c12; /* je 0x6e1c12 */
    W16((uint32_t)(c->ebx * 2 + 0x6f0dd0u), (uint16_t)(((uint16_t)c->ecx))); /* mov word ptr [ebx*2 + 0x10010dd0], cx */
    c->ecx = (uint32_t)((uint32_t)0x770dd0u); /* mov ecx, 0x10090dd0 */
    c->esi = (uint32_t)((uint32_t)(c->ebx + c->ebx * 8)); /* lea esi, [ebx + ebx*8] */
L_006e1b75:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->edx)); /* lea eax, [esi + edx] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->edx = (c->edx & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->eax + 0x2u))) << 8); /* mov dh, byte ptr [eax + 2] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x3u)); /* add esi, 3 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1u))); /* mov dl, byte ptr [eax + 1] */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->eax))); /* movzx eax, byte ptr [eax] */
    c->edx = (uint32_t)(shl32(c, c->edx, 8)); /* shl edx, 8 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->edx))); /* or eax, edx */
    c->edx = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea edx, [eax + eax*2] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x4u))); /* mov eax, dword ptr [ebp + 4] */
    c->edx = (uint32_t)((uint32_t)(c->eax + c->edx * 4)); /* lea edx, [eax + edx*4] */
    c->edi = (uint32_t)(R32((uint32_t)(c->edx))); /* mov edi, dword ptr [edx] */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    W32((uint32_t)(c->eax), (uint32_t)(c->edi)); /* mov dword ptr [eax], edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov edi, dword ptr [edx + 4] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->edi)); /* mov dword ptr [eax + 4], edi */
    c->edx = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov edx, dword ptr [edx + 8] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0xcu)); /* add ecx, 0xc */
    (void)sub32(c, c->ecx, (uint32_t)0x770df4u); /* cmp ecx, 0x10090df4 */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 8], edx */
    if ((c->sf != c->of)) goto L_006e1b75; /* jl 0x6e1b75 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x3cu))); /* mov ecx, dword ptr [esp + 0x3c] */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    c->eax = (uint32_t)((uint32_t)0x3u); /* mov eax, 3 */
    if ((c->zf || c->sf != c->of)) goto L_006e1be5; /* jle 0x6e1be5 */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x38u))); /* mov edi, dword ptr [esp + 0x38] */
L_006e1bc7:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006e1bceu); f_006e16f0(c); /* call 0x6e16f0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e1c0a; /* je 0x6e1c0a */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x3cu))); /* mov ecx, dword ptr [esp + 0x3c] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x10u)); /* add edi, 0x10 */
    (void)sub32(c, c->esi, c->ecx); /* cmp esi, ecx */
    if ((c->sf != c->of)) goto L_006e1bc7; /* jl 0x6e1bc7 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_006e1c0a; /* jle 0x6e1c0a */
L_006e1be5:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x48u))); /* mov ecx, dword ptr [esp + 0x48] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    W32((uint32_t)(c->ebp + 0x9cu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 0x9c], ebx */
    if (c->zf) goto L_006e1cd1; /* je 0x6e1cd1 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x770dd0u; PUSH32(c, v_); } /* push 0x10090dd0 */
    { uint32_t t_ = c->ecx; PUSH32(c, 0x006e1bffu); call_indirect(c, t_); } /* call ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_006e1cd1; /* je 0x6e1cd1 */
L_006e1c0a:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x40u))); /* mov edx, dword ptr [esp + 0x40] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x44u))); /* mov eax, dword ptr [esp + 0x44] */
L_006e1c12:;
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov esi, dword ptr [esp + 0x14] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx + 0x13u))); /* mov cl, byte ptr [edx + 0x13] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x3u)); /* add eax, 3 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    W32((uint32_t)(c->esp + 0x44u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x44], eax */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x14], esi */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0xfu))); /* and ecx, 0xf */
    (void)sub32(c, c->esi, c->ecx); /* cmp esi, ecx */
    if (c->cf) goto L_006e1b40; /* jb 0x6e1b40 */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
L_006e1c36:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x10u))); /* mov eax, dword ptr [edx + 0x10] */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x800000u)); /* test eax, 0x800000 */
    if (c->zf) goto L_006e1c51; /* je 0x6e1c51 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x3fffffu))); /* and eax, 0x3fffff */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x10], esi */
    W32((uint32_t)(c->esi * 4 + 0x7719d0u), (uint32_t)(c->eax)); /* mov dword ptr [esi*4 + 0x100919d0], eax */
L_006e1c51:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x10u))); /* mov eax, dword ptr [edx + 0x10] */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    c->edx = (uint32_t)(shr32(c, c->edx, 28)); /* shr edx, 0x1c */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u))); /* and edx, 3 */
    if (c->zf) goto L_006e1cb0; /* je 0x6e1cb0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
L_006e1c61:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x3fffffu))); /* and eax, 0x3fffff */
    c->eax = (uint32_t)(add32(c, c->eax, c->edx)); /* add eax, edx */
    c->edx = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea edx, [eax + eax*2] */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->edx * 8)); /* lea eax, [ecx + edx*8] */
    W32((uint32_t)(c->esp + 0x40u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x40], eax */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    goto L_006e1ae7; /* jmp 0x6e1ae7 */
L_006e1c79:;
    FCOM(c, ST(0), RF64((uint32_t)(0x6ed0e8u))); FPOP(c); /* fcomp qword ptr [0x1000d0e8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x10u))); /* mov eax, dword ptr [edx + 0x10] */
    if (PF(c)) goto L_006e1ca6; /* jp 0x6e1ca6 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x800000u)); /* test eax, 0x800000 */
    if (c->zf) goto L_006e1cb0; /* je 0x6e1cb0 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x3fffffu))); /* and eax, 0x3fffff */
    c->edx = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea edx, [eax + eax*2] */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->edx * 8)); /* lea eax, [ecx + edx*8] */
    W32((uint32_t)(c->esp + 0x40u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x40], eax */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    goto L_006e1ae7; /* jmp 0x6e1ae7 */
L_006e1ca6:;
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    c->edx = (uint32_t)(shr32(c, c->edx, 28)); /* shr edx, 0x1c */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u))); /* and edx, 3 */
    if (!c->zf) goto L_006e1c61; /* jne 0x6e1c61 */
L_006e1cb0:;
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if ((c->zf || c->sf != c->of)) goto L_006e1cdd; /* jle 0x6e1cdd */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi * 4 + 0x7719d0u))); /* mov eax, dword ptr [esi*4 + 0x100919d0] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    c->edx = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea edx, [eax + eax*2] */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->edx * 8)); /* lea eax, [ecx + edx*8] */
    W32((uint32_t)(c->esp + 0x40u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x40], eax */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    goto L_006e1ae3; /* jmp 0x6e1ae3 */
L_006e1cd1:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x24u)); /* add esp, 0x24 */
    c->esp += 24; return; /* ret 0x14 */
L_006e1cdd:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x24u)); /* add esp, 0x24 */
    c->esp += 24; return; /* ret 0x14 */
}

void f_006e1cf0(CPU *c) { /* FUN_10001cf0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x6ec3e4u; PUSH32(c, v_); } /* push 0x1000c3e4 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x11u; PUSH32(c, v_); } /* push 0x11 */
    { uint32_t v_ = 0x6ee054u; PUSH32(c, v_); } /* push 0x1000e054 */
    { uint32_t v_ = 0xd0u; PUSH32(c, v_); } /* push 0xd0 */
    PUSH32(c, 0x006e1d17u); f_006e3440(c); /* call 0x6e3440 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->esp), (uint32_t)(c->eax)); /* mov dword ptr [esp], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0xc], 0 */
    if (c->zf) goto L_006e1d54; /* je 0x6e1d54 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov ecx, dword ptr [esp + 0x20] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov edx, dword ptr [esp + 0x1c] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov ecx, dword ptr [esp + 0x1c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov edx, dword ptr [esp + 0x1c] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    PUSH32(c, 0x006e1d45u); f_006e1d70(c); /* call 0x6e1d70 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
L_006e1d54:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_006e1d70(CPU *c) { /* FUN_10001d70 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x6ec3f8u; PUSH32(c, v_); } /* push 0x1000c3f8 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x24u)); /* sub esp, 0x24 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x24], ebx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x48u))); /* mov eax, dword ptr [esp + 0x48] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4cu))); /* mov ecx, dword ptr [esp + 0x4c] */
    c->ebp = (uint32_t)(logic32(c, 0)); /* xor ebp, ebp */
    (void)sub32(c, c->eax, c->ebp); /* cmp eax, ebp */
    W32((uint32_t)(c->esp + 0x3cu), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0x3c], ebp */
    W32((uint32_t)(c->ebx + 0x24u), (uint32_t)(c->ecx)); /* mov dword ptr [ebx + 0x24], ecx */
    W32((uint32_t)(c->ebx), (uint32_t)((uint32_t)0x6ed100u)); /* mov dword ptr [ebx], 0x1000d100 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0x10], ebp */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0x1c], ebp */
    if (c->zf) goto L_006e1df7; /* je 0x6e1df7 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x4u)); PUSH32(c, 0x006e1dbbu); call_indirect(c, t_); } /* call dword ptr [edx + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0xcu)); PUSH32(c, 0x006e1dc6u); call_indirect(c, t_); } /* call dword ptr [eax + 0xc] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)sub32(c, c->esi, c->ebp); /* cmp esi, ebp */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x1c], esi */
    if ((c->zf || c->sf != c->of)) goto L_006e1dea; /* jle 0x6e1dea */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x006e1dd9u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x1c], eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x006e1de8u); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    goto L_006e1dee; /* jmp 0x6e1dee */
L_006e1dea:;
    W32((uint32_t)(c->esp + 0x48u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0x48], ebp */
L_006e1dee:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x10u)); PUSH32(c, 0x006e1df7u); call_indirect(c, t_); } /* call dword ptr [eax + 0x10] */
L_006e1df7:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x44u))); /* mov eax, dword ptr [esp + 0x44] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x4u)); PUSH32(c, 0x006e1e04u); call_indirect(c, t_); } /* call dword ptr [edx + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = 0x48u; PUSH32(c, v_); } /* push 0x48 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->edi = (uint32_t)((uint32_t)(c->ebx + 0x28u)); /* lea edi, [ebx + 0x28] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x24], esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x006e1e19u); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    (void)sub32(c, R32((uint32_t)(c->edi)), (uint32_t)0x312e3035u); /* cmp dword ptr [edi], 0x312e3035 */
    if (c->zf) goto L_006e1e38; /* je 0x6e1e38 */
    { uint32_t v_ = 0x6ed8fcu; PUSH32(c, v_); } /* push 0x1000d8fc */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x4cu)); /* lea eax, [esp + 0x4c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(c->esp + 0x50u), (uint32_t)((uint32_t)0x6ee0a4u)); /* mov dword ptr [esp + 0x50], 0x1000e0a4 */
    PUSH32(c, 0x006e1e38u); f_006e4663(c); /* call 0x6e4663 */
L_006e1e38:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x30u))); /* mov eax, dword ptr [ebx + 0x30] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x006e1e44u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x30u))); /* mov edi, dword ptr [ebx + 0x30] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(c->ebx + 0x70u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 0x70], eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x006e1e55u); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x34u))); /* mov edx, dword ptr [ebx + 0x34] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)(shl32(c, c->edx, 2)); /* shl edx, 2 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x006e1e64u); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x34u))); /* mov edi, dword ptr [ebx + 0x34] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    c->edi = (uint32_t)(shl32(c, c->edi, 2)); /* shl edi, 2 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(c->ebx + 0x74u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 0x74], eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x006e1e78u); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x38u))); /* mov edx, dword ptr [ebx + 0x38] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)(shl32(c, c->edx, 2)); /* shl edx, 2 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x006e1e87u); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x38u))); /* mov edx, dword ptr [ebx + 0x38] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    c->edx = (uint32_t)(shl32(c, c->edx, 2)); /* shl edx, 2 */
    W32((uint32_t)(c->ebx + 0x78u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 0x78], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x006e1e99u); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x38u))); /* mov edx, dword ptr [ebx + 0x38] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    c->edx = (uint32_t)(shl32(c, c->edx, 2)); /* shl edx, 2 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x78u))); /* mov edx, dword ptr [ebx + 0x78] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    W32((uint32_t)(c->ebx + 0x7cu), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 0x7c], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x006e1eb0u); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x3cu))); /* mov edx, dword ptr [ebx + 0x3c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    { int64_t r_ = (int64_t)(int32_t)c->edx * (int32_t)(uint32_t)0x38u; c->edx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul edx, edx, 0x38 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x006e1ebfu); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x3cu))); /* mov edi, dword ptr [ebx + 0x3c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    { int64_t r_ = (int64_t)(int32_t)c->edi * (int32_t)(uint32_t)0x38u; c->edi = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul edi, edi, 0x38 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x20], eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x006e1ed4u); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x3cu))); /* mov edx, dword ptr [ebx + 0x3c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    { int64_t r_ = (int64_t)(int32_t)c->edx * (int32_t)(uint32_t)0x38u; c->edx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul edx, edx, 0x38 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x006e1ee3u); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    W32((uint32_t)(c->ebx + 0x80u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 0x80], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x40u))); /* mov eax, dword ptr [ebx + 0x40] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea eax, [eax + eax*4] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x006e1efbu); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x40u))); /* mov eax, dword ptr [ebx + 0x40] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea eax, [eax + eax*4] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x2c], edi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x006e1f15u); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x40u))); /* mov eax, dword ptr [ebx + 0x40] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)(uint32_t)0x54u; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, eax, 0x54 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x006e1f24u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    W32((uint32_t)(c->ebx + 0x84u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 0x84], eax */
    (void)sub32(c, R32((uint32_t)(c->ebx + 0x40u)), c->ebp); /* cmp dword ptr [ebx + 0x40], ebp */
    W32((uint32_t)(c->esp + 0x44u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0x44], ebp */
    if ((c->zf || c->sf != c->of)) goto L_006e20a3; /* jle 0x6e20a3 */
    c->eax = (uint32_t)((uint32_t)(c->edi + 0xcu)); /* lea eax, [edi + 0xc] */
    W32((uint32_t)(c->esp + 0x4cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x4c], eax */
    goto L_006e1f44; /* jmp 0x6e1f44 */
L_006e1f40:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4cu))); /* mov eax, dword ptr [esp + 0x4c] */
L_006e1f44:;
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0xfffffff4u))); /* mov edx, dword ptr [eax - 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x84u))); /* mov ecx, dword ptr [ebx + 0x84] */
    W32((uint32_t)(c->ecx + c->ebp), (uint32_t)(c->edx)); /* mov dword ptr [ecx + ebp], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0xfffffff8u))); /* mov edx, dword ptr [eax - 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x84u))); /* mov ecx, dword ptr [ebx + 0x84] */
    W32((uint32_t)(c->ecx + c->ebp + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + ebp + 4], edx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->ecx = (uint32_t)(add32(c, c->ecx, R32((uint32_t)(c->ebx + 0x70u)))); /* add ecx, dword ptr [ebx + 0x70] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x84u))); /* mov edx, dword ptr [ebx + 0x84] */
    W32((uint32_t)(c->edx + c->ebp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [edx + ebp + 0x10], ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov edx, dword ptr [eax + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x84u))); /* mov ecx, dword ptr [ebx + 0x84] */
    W32((uint32_t)(c->ecx + c->ebp + 0x14u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + ebp + 0x14], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov edx, dword ptr [eax + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x84u))); /* mov ecx, dword ptr [ebx + 0x84] */
    W32((uint32_t)(c->ecx + c->ebp + 0x18u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + ebp + 0x18], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0xcu))); /* mov edx, dword ptr [eax + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x84u))); /* mov ecx, dword ptr [ebx + 0x84] */
    W32((uint32_t)(c->ecx + c->ebp + 0x1cu), (uint32_t)(c->edx)); /* mov dword ptr [ecx + ebp + 0x1c], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x10u))); /* mov edx, dword ptr [eax + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x84u))); /* mov ecx, dword ptr [ebx + 0x84] */
    W32((uint32_t)(c->ecx + c->ebp + 0x20u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + ebp + 0x20], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x14u))); /* mov edx, dword ptr [eax + 0x14] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x84u))); /* mov ecx, dword ptr [ebx + 0x84] */
    W32((uint32_t)(c->ecx + c->ebp + 0x24u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + ebp + 0x24], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x18u))); /* mov edx, dword ptr [eax + 0x18] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x84u))); /* mov ecx, dword ptr [ebx + 0x84] */
    W32((uint32_t)(c->ecx + c->ebp + 0x28u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + ebp + 0x28], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x1cu))); /* mov edx, dword ptr [eax + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x84u))); /* mov ecx, dword ptr [ebx + 0x84] */
    W32((uint32_t)(c->ecx + c->ebp + 0x2cu), (uint32_t)(c->edx)); /* mov dword ptr [ecx + ebp + 0x2c], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x20u))); /* mov edx, dword ptr [eax + 0x20] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x84u))); /* mov ecx, dword ptr [ebx + 0x84] */
    W32((uint32_t)(c->ecx + c->ebp + 0x30u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + ebp + 0x30], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x24u))); /* mov edx, dword ptr [eax + 0x24] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x84u))); /* mov ecx, dword ptr [ebx + 0x84] */
    W32((uint32_t)(c->ecx + c->ebp + 0x34u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + ebp + 0x34], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x28u))); /* mov edx, dword ptr [eax + 0x28] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x84u))); /* mov ecx, dword ptr [ebx + 0x84] */
    W32((uint32_t)(c->ecx + c->ebp + 0x38u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + ebp + 0x38], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x2cu))); /* mov edx, dword ptr [eax + 0x2c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x84u))); /* mov ecx, dword ptr [ebx + 0x84] */
    W32((uint32_t)(c->ecx + c->ebp + 0x3cu), (uint32_t)(c->edx)); /* mov dword ptr [ecx + ebp + 0x3c], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x30u))); /* mov edx, dword ptr [eax + 0x30] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x84u))); /* mov ecx, dword ptr [ebx + 0x84] */
    W32((uint32_t)(c->ecx + c->ebp + 0x40u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + ebp + 0x40], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x34u))); /* mov edx, dword ptr [eax + 0x34] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x84u))); /* mov ecx, dword ptr [ebx + 0x84] */
    W32((uint32_t)(c->ecx + c->ebp + 0x44u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + ebp + 0x44], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x38u))); /* mov edx, dword ptr [eax + 0x38] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x84u))); /* mov ecx, dword ptr [ebx + 0x84] */
    W32((uint32_t)(c->ecx + c->ebp + 0x48u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + ebp + 0x48], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x3cu))); /* mov edx, dword ptr [eax + 0x3c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x84u))); /* mov ecx, dword ptr [ebx + 0x84] */
    W32((uint32_t)(c->ecx + c->ebp + 0x4cu), (uint32_t)(c->edx)); /* mov dword ptr [ecx + ebp + 0x4c], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x40u))); /* mov edx, dword ptr [eax + 0x40] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x84u))); /* mov ecx, dword ptr [ebx + 0x84] */
    W32((uint32_t)(c->ecx + c->ebp + 0x50u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + ebp + 0x50], edx */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebx + 0x84u))); /* mov esi, dword ptr [ebx + 0x84] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov eax, dword ptr [ebx + 0x24] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x54u)); /* sub esp, 0x54 */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    c->esi = (uint32_t)(add32(c, c->esi, c->ebp)); /* add esi, ebp */
    c->ecx = (uint32_t)((uint32_t)0x15u); /* mov ecx, 0x15 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x54u)); PUSH32(c, 0x006e205au); call_indirect(c, t_); } /* call dword ptr [edx + 0x54] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x84u))); /* mov ecx, dword ptr [ebx + 0x84] */
    W32((uint32_t)(c->ecx + c->ebp + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + ebp + 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x84u))); /* mov eax, dword ptr [ebx + 0x84] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->ebp + 0x8u))); /* mov eax, dword ptr [eax + ebp + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x58u)); PUSH32(c, 0x006e2077u); call_indirect(c, t_); } /* call dword ptr [edx + 0x58] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x44u))); /* mov eax, dword ptr [esp + 0x44] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x4cu))); /* mov esi, dword ptr [esp + 0x4c] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    W32((uint32_t)(c->esp + 0x44u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x44], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x40u))); /* mov ecx, dword ptr [ebx + 0x40] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x50u)); /* add esi, 0x50 */
    c->ebp = (uint32_t)(add32(c, c->ebp, (uint32_t)0x54u)); /* add ebp, 0x54 */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    W32((uint32_t)(c->esp + 0x4cu), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x4c], esi */
    if ((c->sf != c->of)) goto L_006e1f40; /* jl 0x6e1f40 */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov edi, dword ptr [esp + 0x20] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov esi, dword ptr [esp + 0x18] */
    c->ebp = (uint32_t)(logic32(c, 0)); /* xor ebp, ebp */
L_006e20a3:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x18u)); PUSH32(c, 0x006e20acu); call_indirect(c, t_); } /* call dword ptr [edx + 0x18] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x44u))); /* mov edx, dword ptr [ebx + 0x44] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    { int64_t r_ = (int64_t)(int32_t)c->edx * (int32_t)(uint32_t)0x6cu; c->edx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul edx, edx, 0x6c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x006e20bbu); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x44u))); /* mov edx, dword ptr [ebx + 0x44] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    { int64_t r_ = (int64_t)(int32_t)c->edx * (int32_t)(uint32_t)0x6cu; c->edx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul edx, edx, 0x6c */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W32((uint32_t)(c->esp + 0x58u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x58], edi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x006e20d2u); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x44u))); /* mov edx, dword ptr [ebx + 0x44] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    { int64_t r_ = (int64_t)(int32_t)c->edx * (int32_t)(uint32_t)0x6cu; c->edx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul edx, edx, 0x6c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x006e20e1u); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    W32((uint32_t)(c->ebx + 0x88u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 0x88], eax */
    (void)sub32(c, R32((uint32_t)(c->ebx + 0x44u)), c->ebp); /* cmp dword ptr [ebx + 0x44], ebp */
    if ((c->zf || c->sf != c->of)) goto L_006e2198; /* jle 0x6e2198 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edx = (uint32_t)((uint32_t)(c->edi + 0x4u)); /* lea edx, [edi + 4] */
L_006e20f5:;
    c->esi = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov esi, dword ptr [edx + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x88u))); /* mov ecx, dword ptr [ebx + 0x88] */
    W32((uint32_t)(c->eax + c->ecx), (uint32_t)(c->esi)); /* mov dword ptr [eax + ecx], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx))); /* mov ecx, dword ptr [edx] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x70u))); /* mov edi, dword ptr [ebx + 0x70] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebx + 0x88u))); /* mov esi, dword ptr [ebx + 0x88] */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->edi)); /* add ecx, edi */
    W32((uint32_t)(c->eax + c->esi + 0x48u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + esi + 0x48], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0xfffffffcu))); /* mov ecx, dword ptr [edx - 4] */
    c->ecx = (uint32_t)(add32(c, c->ecx, R32((uint32_t)(c->ebx + 0x70u)))); /* add ecx, dword ptr [ebx + 0x70] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebx + 0x88u))); /* mov esi, dword ptr [ebx + 0x88] */
    W32((uint32_t)(c->eax + c->esi + 0x44u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + esi + 0x44], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x88u))); /* mov ecx, dword ptr [ebx + 0x88] */
    c->edi = (uint32_t)((uint32_t)(c->eax + c->ecx + 0x4u)); /* lea edi, [eax + ecx + 4] */
    c->esi = (uint32_t)((uint32_t)(c->edx + 0x8u)); /* lea esi, [edx + 8] */
    c->ecx = (uint32_t)((uint32_t)0x10u); /* mov ecx, 0x10 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebx + 0x88u))); /* mov esi, dword ptr [ebx + 0x88] */
    c->esi = (uint32_t)((uint32_t)(c->eax + c->esi + 0x4cu)); /* lea esi, [eax + esi + 0x4c] */
    c->ecx = (uint32_t)((uint32_t)(c->edx + 0x48u)); /* lea ecx, [edx + 0x48] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edi, dword ptr [ecx] */
    W32((uint32_t)(c->esi), (uint32_t)(c->edi)); /* mov dword ptr [esi], edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov edi, dword ptr [ecx + 4] */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 4], edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov edi, dword ptr [ecx + 8] */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 8], edi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov ecx, dword ptr [ecx + 0xc] */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 0xc], ecx */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebx + 0x88u))); /* mov esi, dword ptr [ebx + 0x88] */
    c->ecx = (uint32_t)((uint32_t)(c->edx + 0x58u)); /* lea ecx, [edx + 0x58] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edi, dword ptr [ecx] */
    c->esi = (uint32_t)((uint32_t)(c->eax + c->esi + 0x5cu)); /* lea esi, [eax + esi + 0x5c] */
    W32((uint32_t)(c->esi), (uint32_t)(c->edi)); /* mov dword ptr [esi], edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov edi, dword ptr [ecx + 4] */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 4], edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov edi, dword ptr [ecx + 8] */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 8], edi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov ecx, dword ptr [ecx + 0xc] */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 0xc], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x44u))); /* mov ecx, dword ptr [ebx + 0x44] */
    c->ebp = (uint32_t)(inc32(c, c->ebp)); /* inc ebp */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x6cu)); /* add eax, 0x6c */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x6cu)); /* add edx, 0x6c */
    (void)sub32(c, c->ebp, c->ecx); /* cmp ebp, ecx */
    if ((c->sf != c->of)) goto L_006e20f5; /* jl 0x6e20f5 */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov esi, dword ptr [esp + 0x18] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x4cu))); /* mov edi, dword ptr [esp + 0x4c] */
    c->ebp = (uint32_t)(logic32(c, 0)); /* xor ebp, ebp */
L_006e2198:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x18u)); PUSH32(c, 0x006e21a1u); call_indirect(c, t_); } /* call dword ptr [edx + 0x18] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x48u))); /* mov edx, dword ptr [ebx + 0x48] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    { int64_t r_ = (int64_t)(int32_t)c->edx * (int32_t)(uint32_t)0x68u; c->edx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul edx, edx, 0x68 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x006e21b0u); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x48u))); /* mov edx, dword ptr [ebx + 0x48] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)(shl32(c, c->edx, 2)); /* shl edx, 2 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    W32((uint32_t)(c->esp + 0x50u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x50], edi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x006e21c5u); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x48u))); /* mov edx, dword ptr [ebx + 0x48] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    { int64_t r_ = (int64_t)(int32_t)c->edx * (int32_t)(uint32_t)0x68u; c->edx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul edx, edx, 0x68 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->ebx + 0x98u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 0x98], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x006e21dcu); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x48u))); /* mov edx, dword ptr [ebx + 0x48] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    { int64_t r_ = (int64_t)(int32_t)c->edx * (int32_t)(uint32_t)0x44u; c->edx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul edx, edx, 0x44 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x006e21ebu); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    W32((uint32_t)(c->ebx + 0x8cu), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 0x8c], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x48u))); /* mov eax, dword ptr [ebx + 0x48] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    (void)sub32(c, c->eax, c->ebp); /* cmp eax, ebp */
    if ((c->zf || c->sf != c->of)) goto L_006e22d4; /* jle 0x6e22d4 */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->eax = (uint32_t)((uint32_t)(c->edi + 0xcu)); /* lea eax, [edi + 0xc] */
L_006e2203:;
    c->ebp = (uint32_t)(R32((uint32_t)(c->eax + 0xfffffffcu))); /* mov ebp, dword ptr [eax - 4] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x8cu))); /* mov edi, dword ptr [ebx + 0x8c] */
    W32((uint32_t)(c->ecx + c->edi), (uint32_t)(c->ebp)); /* mov dword ptr [ecx + edi], ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ebp, dword ptr [eax] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x8cu))); /* mov edi, dword ptr [ebx + 0x8c] */
    W32((uint32_t)(c->ecx + c->edi + 0x4u), (uint32_t)(c->ebp)); /* mov dword ptr [ecx + edi + 4], ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ebp, dword ptr [eax + 4] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x8cu))); /* mov edi, dword ptr [ebx + 0x8c] */
    W32((uint32_t)(c->ecx + c->edi + 0x8u), (uint32_t)(c->ebp)); /* mov dword ptr [ecx + edi + 8], ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ebp, dword ptr [eax + 8] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x8cu))); /* mov edi, dword ptr [ebx + 0x8c] */
    W32((uint32_t)(c->ecx + c->edi + 0xcu), (uint32_t)(c->ebp)); /* mov dword ptr [ecx + edi + 0xc], ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->eax + 0xcu))); /* mov ebp, dword ptr [eax + 0xc] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x8cu))); /* mov edi, dword ptr [ebx + 0x8c] */
    W32((uint32_t)(c->ecx + c->edi + 0x10u), (uint32_t)(c->ebp)); /* mov dword ptr [ecx + edi + 0x10], ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->eax + 0x24u))); /* mov ebp, dword ptr [eax + 0x24] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x8cu))); /* mov edi, dword ptr [ebx + 0x8c] */
    W32((uint32_t)(c->ecx + c->edi + 0x14u), (uint32_t)(c->ebp)); /* mov dword ptr [ecx + edi + 0x14], ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->eax + 0x14u))); /* mov ebp, dword ptr [eax + 0x14] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x8cu))); /* mov edi, dword ptr [ebx + 0x8c] */
    W32((uint32_t)(c->ecx + c->edi + 0x20u), (uint32_t)(c->ebp)); /* mov dword ptr [ecx + edi + 0x20], ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->eax + 0x18u))); /* mov ebp, dword ptr [eax + 0x18] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x8cu))); /* mov edi, dword ptr [ebx + 0x8c] */
    W32((uint32_t)(c->ecx + c->edi + 0x24u), (uint32_t)(c->ebp)); /* mov dword ptr [ecx + edi + 0x24], ebp */
    c->edi = (uint32_t)(R32((uint32_t)(c->eax + 0xfffffff8u))); /* mov edi, dword ptr [eax - 8] */
    c->edi = (uint32_t)(add32(c, c->edi, R32((uint32_t)(c->ebx + 0x70u)))); /* add edi, dword ptr [ebx + 0x70] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ebx + 0x8cu))); /* mov ebp, dword ptr [ebx + 0x8c] */
    W32((uint32_t)(c->ecx + c->ebp + 0x1cu), (uint32_t)(c->edi)); /* mov dword ptr [ecx + ebp + 0x1c], edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->eax + 0xfffffff4u))); /* mov edi, dword ptr [eax - 0xc] */
    c->edi = (uint32_t)(add32(c, c->edi, R32((uint32_t)(c->ebx + 0x70u)))); /* add edi, dword ptr [ebx + 0x70] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ebx + 0x8cu))); /* mov ebp, dword ptr [ebx + 0x8c] */
    W32((uint32_t)(c->ecx + c->ebp + 0x18u), (uint32_t)(c->edi)); /* mov dword ptr [ecx + ebp + 0x18], edi */
    c->ebp = (uint32_t)(R32((uint32_t)(c->eax + 0x10u))); /* mov ebp, dword ptr [eax + 0x10] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x8cu))); /* mov edi, dword ptr [ebx + 0x8c] */
    W32((uint32_t)(c->ecx + c->edi + 0x28u), (uint32_t)(c->ebp)); /* mov dword ptr [ecx + edi + 0x28], ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->eax + 0x20u))); /* mov ebp, dword ptr [eax + 0x20] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x8cu))); /* mov edi, dword ptr [ebx + 0x8c] */
    W32((uint32_t)(c->ecx + c->edi + 0x2cu), (uint32_t)(c->ebp)); /* mov dword ptr [ecx + edi + 0x2c], ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->eax + 0x1cu))); /* mov ebp, dword ptr [eax + 0x1c] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x8cu))); /* mov edi, dword ptr [ebx + 0x8c] */
    W32((uint32_t)(c->ecx + c->edi + 0x30u), (uint32_t)(c->ebp)); /* mov dword ptr [ecx + edi + 0x30], ebp */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x98u))); /* mov edi, dword ptr [ebx + 0x98] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->eax + 0x58u))); /* mov ebp, dword ptr [eax + 0x58] */
    W32((uint32_t)(c->edi + c->edx * 4), (uint32_t)(c->ebp)); /* mov dword ptr [edi + edx*4], ebp */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x48u))); /* mov edi, dword ptr [ebx + 0x48] */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x44u)); /* add ecx, 0x44 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x68u)); /* add eax, 0x68 */
    (void)sub32(c, c->edx, c->edi); /* cmp edx, edi */
    if ((c->sf != c->of)) goto L_006e2203; /* jl 0x6e2203 */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x4cu))); /* mov edi, dword ptr [esp + 0x4c] */
    c->ebp = (uint32_t)(logic32(c, 0)); /* xor ebp, ebp */
L_006e22d4:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x18u)); PUSH32(c, 0x006e22ddu); call_indirect(c, t_); } /* call dword ptr [eax + 0x18] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x4cu))); /* mov eax, dword ptr [ebx + 0x4c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea eax, [eax + eax*2] */
    c->eax = (uint32_t)(shl32(c, c->eax, 1)); /* shl eax, 1 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x38u)); PUSH32(c, 0x006e22eeu); call_indirect(c, t_); } /* call dword ptr [edx + 0x38] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    W32((uint32_t)(c->ebx + 0x90u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 0x90], eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x3cu)); PUSH32(c, 0x006e22fdu); call_indirect(c, t_); } /* call dword ptr [edx + 0x3c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x4cu))); /* mov edx, dword ptr [ebx + 0x4c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edi, dword ptr [ecx] */
    c->edx = (uint32_t)((uint32_t)(c->edx + c->edx * 2)); /* lea edx, [edx + edx*2] */
    c->edx = (uint32_t)(shl32(c, c->edx, 1)); /* shl edx, 1 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->edi + 0x8u)); PUSH32(c, 0x006e2310u); call_indirect(c, t_); } /* call dword ptr [edi + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x90u))); /* mov edx, dword ptr [ebx + 0x90] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x40u)); PUSH32(c, 0x006e231fu); call_indirect(c, t_); } /* call dword ptr [eax + 0x40] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x50u))); /* mov edx, dword ptr [ebx + 0x50] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)(shl32(c, c->edx, 3)); /* shl edx, 3 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    W32((uint32_t)(c->esp + 0x48u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0x48], ebp */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x006e2332u); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x50u))); /* mov edx, dword ptr [ebx + 0x50] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    c->edx = (uint32_t)(shl32(c, c->edx, 3)); /* shl edx, 3 */
    c->ebp = (uint32_t)(c->eax); /* mov ebp, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x006e2345u); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x50u))); /* mov eax, dword ptr [ebx + 0x50] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea eax, [eax + eax*4] */
    c->eax = (uint32_t)(shl32(c, c->eax, 2)); /* shl eax, 2 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x006e2357u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x50u))); /* mov ecx, dword ptr [ebx + 0x50] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    W32((uint32_t)(c->ebx + 0x94u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 0x94], eax */
    if ((c->zf || c->sf != c->of)) goto L_006e23fd; /* jle 0x6e23fd */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    W32((uint32_t)(c->esp + 0x4cu), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x4c], ecx */
    goto L_006e2376; /* jmp 0x6e2376 */
L_006e2372:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4cu))); /* mov ecx, dword ptr [esp + 0x4c] */
L_006e2376:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + c->edi * 8))); /* mov edx, dword ptr [ebp + edi*8] */
    W32((uint32_t)(c->eax + c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [eax + ecx], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + c->edi * 8))); /* mov eax, dword ptr [ebp + edi*8] */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x3u))); /* and eax, 3 */
    c->edx = (uint32_t)(sar32(c, c->edx, 2)); /* sar edx, 2 */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    c->eax = (uint32_t)((uint32_t)(c->edx * 8 + 0x24u)); /* lea eax, [edx*8 + 0x24] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x94u))); /* mov edx, dword ptr [ebx + 0x94] */
    W32((uint32_t)(c->ecx + c->edx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + edx + 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x94u))); /* mov eax, dword ptr [ebx + 0x94] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + c->edi * 8 + 0x4u))); /* mov edx, dword ptr [ebp + edi*8 + 4] */
    W32((uint32_t)(c->ecx + c->eax + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + eax + 4], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x94u))); /* mov eax, dword ptr [ebx + 0x94] */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov eax, dword ptr [ecx + 4] */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)R32((uint32_t)(c->ecx + 0x8u)); int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x006e23b6u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv dword ptr [ecx + 8] */
    W32((uint32_t)(c->ecx + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 0xc], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + c->edi * 8 + 0x4u))); /* mov eax, dword ptr [ebp + edi*8 + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + c->edi * 8))); /* mov eax, dword ptr [ebp + edi*8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x28u)); PUSH32(c, 0x006e23ceu); call_indirect(c, t_); } /* call dword ptr [edx + 0x28] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4cu))); /* mov ecx, dword ptr [esp + 0x4c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x94u))); /* mov edx, dword ptr [ebx + 0x94] */
    W32((uint32_t)(c->ecx + c->edx + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + edx + 0x10], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x94u))); /* mov eax, dword ptr [ebx + 0x94] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + c->ecx + 0xcu))); /* mov edx, dword ptr [eax + ecx + 0xc] */
    { uint32_t a_ = (uint32_t)(c->esp + 0x44u); W32(a_, (uint32_t)(add32(c, R32(a_), c->edx))); } /* add dword ptr [esp + 0x44], edx */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x14u)); /* add ecx, 0x14 */
    W32((uint32_t)(c->esp + 0x4cu), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x4c], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x50u))); /* mov ecx, dword ptr [ebx + 0x50] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->edi, c->ecx); /* cmp edi, ecx */
    if ((c->sf != c->of)) goto L_006e2372; /* jl 0x6e2372 */
L_006e23fd:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x18u)); PUSH32(c, 0x006e2406u); call_indirect(c, t_); } /* call dword ptr [eax + 0x18] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x48u))); /* mov eax, dword ptr [esp + 0x48] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ebp, dword ptr [esp + 0x10] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    W32((uint32_t)(c->esp + 0x4cu), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0x4c], ebp */
    if (c->zf) goto L_006e243a; /* je 0x6e243a */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov eax, dword ptr [esp + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x44u))); /* mov ecx, dword ptr [esp + 0x44] */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u))); /* and edx, 3 */
    c->eax = (uint32_t)(add32(c, c->eax, c->edx)); /* add eax, edx */
    c->eax = (uint32_t)(sar32(c, c->eax, 2)); /* sar eax, 2 */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (c->zf) goto L_006e243a; /* je 0x6e243a */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x18u)); PUSH32(c, 0x006e2436u); call_indirect(c, t_); } /* call dword ptr [edx + 0x18] */
    W32((uint32_t)(c->esp + 0x48u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x48], edi */
L_006e243a:;
    (void)sub32(c, R32((uint32_t)(c->ebx + 0x50u)), c->edi); /* cmp dword ptr [ebx + 0x50], edi */
    W32((uint32_t)(c->esp + 0x44u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x44], edi */
    if ((c->zf || c->sf != c->of)) goto L_006e24de; /* jle 0x6e24de */
L_006e2447:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x94u))); /* mov edx, dword ptr [ebx + 0x94] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + c->edx + 0x10u))); /* mov edx, dword ptr [edi + edx + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x2cu)); PUSH32(c, 0x006e245au); call_indirect(c, t_); } /* call dword ptr [eax + 0x2c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x94u))); /* mov edx, dword ptr [ebx + 0x94] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + c->edx + 0x4u))); /* mov edx, dword ptr [edi + edx + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    c->ebp = (uint32_t)(c->eax); /* mov ebp, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x006e2471u); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x94u))); /* mov eax, dword ptr [ebx + 0x94] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + c->edi + 0xcu))); /* mov edx, dword ptr [eax + edi + 0xc] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if ((c->zf || c->sf != c->of)) goto L_006e24ae; /* jle 0x6e24ae */
L_006e2481:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x48u))); /* mov edx, dword ptr [esp + 0x48] */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_006e249f; /* je 0x6e249f */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->edi + 0x8u))); /* mov eax, dword ptr [eax + edi + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4cu))); /* mov edx, dword ptr [esp + 0x4c] */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)c->ecx; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->edx))); /* mov edx, dword ptr [edx] */
    W32((uint32_t)(c->eax + c->ebp + 0x18u), (uint32_t)(c->edx)); /* mov dword ptr [eax + ebp + 0x18], edx */
    { uint32_t a_ = (uint32_t)(c->esp + 0x4cu); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x4u))); } /* add dword ptr [esp + 0x4c], 4 */
L_006e249f:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x94u))); /* mov eax, dword ptr [ebx + 0x94] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + c->edi + 0xcu))); /* mov edx, dword ptr [eax + edi + 0xc] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if ((c->sf != c->of)) goto L_006e2481; /* jl 0x6e2481 */
L_006e24ae:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x94u))); /* mov edx, dword ptr [ebx + 0x94] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + c->edx + 0x10u))); /* mov edx, dword ptr [edi + edx + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x30u)); PUSH32(c, 0x006e24c1u); call_indirect(c, t_); } /* call dword ptr [eax + 0x30] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x44u))); /* mov eax, dword ptr [esp + 0x44] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x50u))); /* mov ecx, dword ptr [ebx + 0x50] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x14u)); /* add edi, 0x14 */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    W32((uint32_t)(c->esp + 0x44u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x44], eax */
    if ((c->sf != c->of)) goto L_006e2447; /* jl 0x6e2447 */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ebp, dword ptr [esp + 0x10] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
L_006e24de:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebx + 0x2cu)) & (uint8_t)0x2u)); /* test byte ptr [ebx + 0x2c], 2 */
    if (c->zf) goto L_006e2575; /* je 0x6e2575 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = 0xcu; PUSH32(c, v_); } /* push 0xc */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x2cu)); /* lea edx, [esp + 0x2c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x006e24f8u); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov eax, dword ptr [esp + 0x28] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea eax, [eax + eax*2] */
    c->eax = (uint32_t)(shl32(c, c->eax, 3)); /* shl eax, 3 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x006e250bu); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov edx, dword ptr [esp + 0x28] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    c->edx = (uint32_t)((uint32_t)(c->edx + c->edx * 2)); /* lea edx, [edx + edx*2] */
    c->edx = (uint32_t)(shl32(c, c->edx, 3)); /* shl edx, 3 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(c->ebx + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 0xc], eax */
    c->edi = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edi, dword ptr [ecx] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->edi + 0x8u)); PUSH32(c, 0x006e2523u); call_indirect(c, t_); } /* call dword ptr [edi + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov eax, dword ptr [esp + 0x2c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea eax, [eax + eax*2] */
    c->eax = (uint32_t)(shl32(c, c->eax, 2)); /* shl eax, 2 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x006e2536u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov edx, dword ptr [esp + 0x2c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    c->edx = (uint32_t)((uint32_t)(c->edx + c->edx * 2)); /* lea edx, [edx + edx*2] */
    c->edx = (uint32_t)(shl32(c, c->edx, 2)); /* shl edx, 2 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 4], eax */
    c->edi = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edi, dword ptr [ecx] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->edi + 0x8u)); PUSH32(c, 0x006e254eu); call_indirect(c, t_); } /* call dword ptr [edi + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov eax, dword ptr [esp + 0x30] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 8)); /* lea eax, [eax + eax*8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x006e255eu); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov edx, dword ptr [esp + 0x30] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    c->edx = (uint32_t)((uint32_t)(c->edx + c->edx * 8)); /* lea edx, [edx + edx*8] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 8], eax */
    c->edi = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edi, dword ptr [ecx] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->edi + 0x8u)); PUSH32(c, 0x006e2573u); call_indirect(c, t_); } /* call dword ptr [edi + 8] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
L_006e2575:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x10u)); PUSH32(c, 0x006e257eu); call_indirect(c, t_); } /* call dword ptr [eax + 0x10] */
    (void)sub32(c, R32((uint32_t)(c->esp + 0x48u)), c->edi); /* cmp dword ptr [esp + 0x48], edi */
    if (c->zf) goto L_006e258d; /* je 0x6e258d */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x18u)); PUSH32(c, 0x006e258du); call_indirect(c, t_); } /* call dword ptr [edx + 0x18] */
L_006e258d:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x38u))); /* mov eax, dword ptr [ebx + 0x38] */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if ((c->zf || c->sf != c->of)) goto L_006e25b8; /* jle 0x6e25b8 */
L_006e2596:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x78u))); /* mov edx, dword ptr [ebx + 0x78] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edx + c->esi * 4))); /* mov edx, dword ptr [edx + esi*4] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ebx + 0x70u))); /* mov ebp, dword ptr [ebx + 0x70] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)(add32(c, c->edx, c->ebp)); /* add edx, ebp */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x1cu)); PUSH32(c, 0x006e25aau); call_indirect(c, t_); } /* call dword ptr [eax + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x7cu))); /* mov ecx, dword ptr [ebx + 0x7c] */
    W32((uint32_t)(c->ecx + c->esi * 4), (uint32_t)(c->eax)); /* mov dword ptr [ecx + esi*4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x38u))); /* mov eax, dword ptr [ebx + 0x38] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if ((c->sf != c->of)) goto L_006e2596; /* jl 0x6e2596 */
L_006e25b8:;
    (void)sub32(c, R32((uint32_t)(c->ebx + 0x3cu)), c->edi); /* cmp dword ptr [ebx + 0x3c], edi */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x1c], edi */
    if ((c->zf || c->sf != c->of)) goto L_006e26ec; /* jle 0x6e26ec */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->ecx = (uint32_t)((uint32_t)0xfffffff8u); /* mov ecx, 0xfffffff8 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x20], ecx */
    c->ecx = (uint32_t)((uint32_t)0x8u); /* mov ecx, 8 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    W32((uint32_t)(c->esp + 0x44u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x44], ecx */
    c->edx = (uint32_t)((uint32_t)(c->eax + 0x8u)); /* lea edx, [eax + 8] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x18u)); /* add eax, 0x18 */
    W32((uint32_t)(c->esp + 0x4cu), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x4c], edi */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x18], edx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    goto L_006e25f7; /* jmp 0x6e25f7 */
L_006e25f5:;
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
L_006e25f7:;
    c->ebp = (uint32_t)(R32((uint32_t)(c->ebx + 0x70u))); /* mov ebp, dword ptr [ebx + 0x70] */
    c->esi = (uint32_t)(R32((uint32_t)(c->edx + 0xfffffff8u))); /* mov esi, dword ptr [edx - 8] */
    c->esi = (uint32_t)(add32(c, c->esi, c->ebp)); /* add esi, ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ebx + 0x80u))); /* mov ebp, dword ptr [ebx + 0x80] */
    W32((uint32_t)(c->ecx + c->ebp + 0x30u), (uint32_t)(c->esi)); /* mov dword ptr [ecx + ebp + 0x30], esi */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ebx + 0x70u))); /* mov ebp, dword ptr [ebx + 0x70] */
    c->esi = (uint32_t)(R32((uint32_t)(c->edx + 0xfffffffcu))); /* mov esi, dword ptr [edx - 4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->ebp)); /* add esi, ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ebx + 0x80u))); /* mov ebp, dword ptr [ebx + 0x80] */
    W32((uint32_t)(c->ecx + c->ebp + 0x34u), (uint32_t)(c->esi)); /* mov dword ptr [ecx + ebp + 0x34], esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebx + 0x80u))); /* mov esi, dword ptr [ebx + 0x80] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->edx))); /* mov ebp, dword ptr [edx] */
    W32((uint32_t)(c->ecx + c->esi), (uint32_t)(c->ebp)); /* mov dword ptr [ecx + esi], ebp */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebx + 0x80u))); /* mov esi, dword ptr [ebx + 0x80] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov ebp, dword ptr [edx + 4] */
    W32((uint32_t)(c->ecx + c->esi + 0x4u), (uint32_t)(c->ebp)); /* mov dword ptr [ecx + esi + 4], ebp */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebx + 0x80u))); /* mov esi, dword ptr [ebx + 0x80] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov ebp, dword ptr [edx + 8] */
    W32((uint32_t)(c->ecx + c->esi + 0x8u), (uint32_t)(c->ebp)); /* mov dword ptr [ecx + esi + 8], ebp */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebx + 0x80u))); /* mov esi, dword ptr [ebx + 0x80] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->edx + 0xcu))); /* mov ebp, dword ptr [edx + 0xc] */
    W32((uint32_t)(c->ecx + c->esi + 0xcu), (uint32_t)(c->ebp)); /* mov dword ptr [ecx + esi + 0xc], ebp */
    W32((uint32_t)(c->esp + 0x48u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x48], edi */
L_006e2651:;
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov esi, dword ptr [esp + 0x20] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x80u))); /* mov edi, dword ptr [ebx + 0x80] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ebp, dword ptr [eax] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    W32((uint32_t)(c->esi + c->edi), (uint32_t)(c->ebp)); /* mov dword ptr [esi + edi], ebp */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0x0u); /* cmp dword ptr [eax], 0 */
    if (c->zf) goto L_006e2694; /* je 0x6e2694 */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x4cu))); /* mov esi, dword ptr [esp + 0x4c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x48u))); /* mov edx, dword ptr [esp + 0x48] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x44u))); /* mov edi, dword ptr [esp + 0x44] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ebx + 0x80u))); /* mov ebp, dword ptr [ebx + 0x80] */
    c->edx = (uint32_t)(add32(c, c->edx, c->esi)); /* add edx, esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov esi, dword ptr [esp + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + c->edx * 4 + 0x28u))); /* mov edx, dword ptr [esi + edx*4 + 0x28] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebx + 0x7cu))); /* mov esi, dword ptr [ebx + 0x7c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + c->edx * 4))); /* mov edx, dword ptr [esi + edx*4] */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    W32((uint32_t)(c->edi + c->ebp), (uint32_t)(c->edx)); /* mov dword ptr [edi + ebp], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov edx, dword ptr [esp + 0x18] */
    goto L_006e26a7; /* jmp 0x6e26a7 */
L_006e2694:;
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x44u))); /* mov esi, dword ptr [esp + 0x44] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x80u))); /* mov edi, dword ptr [ebx + 0x80] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    W32((uint32_t)(c->esi + c->edi), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [esi + edi], 0xffffffff */
L_006e26a7:;
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x48u))); /* mov esi, dword ptr [esp + 0x48] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x4u)); /* add eax, 4 */
    (void)sub32(c, c->esi, (uint32_t)0x4u); /* cmp esi, 4 */
    W32((uint32_t)(c->esp + 0x48u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x48], esi */
    if ((c->sf != c->of)) goto L_006e2651; /* jl 0x6e2651 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4cu))); /* mov eax, dword ptr [esp + 0x4c] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov esi, dword ptr [esp + 0x1c] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x3cu))); /* mov edi, dword ptr [ebx + 0x3c] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xeu)); /* add eax, 0xe */
    W32((uint32_t)(c->esp + 0x4cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x4c], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x38u)); /* add edx, 0x38 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x38u)); /* add eax, 0x38 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x38u)); /* add ecx, 0x38 */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x1c], esi */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x18], edx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    if ((c->sf != c->of)) goto L_006e25f5; /* jl 0x6e25f5 */
L_006e26ec:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edx, dword ptr [esp + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x18u)); PUSH32(c, 0x006e26f9u); call_indirect(c, t_); } /* call dword ptr [eax + 0x18] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov ecx, dword ptr [esp + 0x34] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x30u)); /* add esp, 0x30 */
    c->esp += 20; return; /* ret 0x10 */
}

void f_006e2710(CPU *c) { /* FUN_10002710 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx), (uint32_t)((uint32_t)0x6ed170u)); /* mov dword ptr [ecx], 0x1000d170 */
    c->esp += 4; return; /* ret  */
}

void f_006e2720(CPU *c) { /* PTR_006e2720 */
    PREEMPT_POLL(c);
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x4u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 4], 1 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x6ed170u)); /* mov dword ptr [esi], 0x1000d170 */
    if (c->zf) goto L_006e2739; /* je 0x6e2739 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006e2736u); f_006e3420(c); /* call 0x6e3420 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_006e2739:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_006e2740(CPU *c) { /* FUN_10002740 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x006e2748u); f_006e2760(c); /* call 0x6e2760 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_006e2758; /* je 0x6e2758 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006e2755u); f_006e3420(c); /* call 0x6e3420 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_006e2758:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_006e2760(CPU *c) { /* FUN_10002760 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x6ec418u; PUSH32(c, v_); } /* push 0x1000c418 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 8], esi */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x6ed100u)); /* mov dword ptr [esi], 0x1000d100 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi + 0x2cu)) & (uint8_t)0x2u)); /* test byte ptr [esi + 0x2c], 2 */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x14], 0 */
    if (c->zf) goto L_006e27b6; /* je 0x6e27b6 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov ecx, dword ptr [esi + 0x24] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov edx, dword ptr [esi + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x18u)); PUSH32(c, 0x006e279eu); call_indirect(c, t_); } /* call dword ptr [eax + 0x18] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov ecx, dword ptr [esi + 0x24] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov edx, dword ptr [esi + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x18u)); PUSH32(c, 0x006e27aau); call_indirect(c, t_); } /* call dword ptr [eax + 0x18] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov ecx, dword ptr [esi + 0x24] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov edx, dword ptr [esi + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x18u)); PUSH32(c, 0x006e27b6u); call_indirect(c, t_); } /* call dword ptr [eax + 0x18] */
L_006e27b6:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_006e27e1; /* jle 0x6e27e1 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
L_006e27c2:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x94u))); /* mov edx, dword ptr [esi + 0x94] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov ecx, dword ptr [esi + 0x24] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + c->edx + 0x10u))); /* mov edx, dword ptr [ebx + edx + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x34u)); PUSH32(c, 0x006e27d5u); call_indirect(c, t_); } /* call dword ptr [eax + 0x34] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x14u)); /* add ebx, 0x14 */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if ((c->sf != c->of)) goto L_006e27c2; /* jl 0x6e27c2 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
L_006e27e1:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov ecx, dword ptr [esi + 0x24] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x94u))); /* mov edx, dword ptr [esi + 0x94] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x18u)); PUSH32(c, 0x006e27f0u); call_indirect(c, t_); } /* call dword ptr [eax + 0x18] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov ecx, dword ptr [esi + 0x24] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x90u))); /* mov edx, dword ptr [esi + 0x90] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x44u)); PUSH32(c, 0x006e27ffu); call_indirect(c, t_); } /* call dword ptr [eax + 0x44] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov ecx, dword ptr [esi + 0x24] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x88u))); /* mov edx, dword ptr [esi + 0x88] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x18u)); PUSH32(c, 0x006e280eu); call_indirect(c, t_); } /* call dword ptr [eax + 0x18] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov ecx, dword ptr [esi + 0x24] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x8cu))); /* mov edx, dword ptr [esi + 0x8c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x18u)); PUSH32(c, 0x006e281du); call_indirect(c, t_); } /* call dword ptr [eax + 0x18] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov ecx, dword ptr [esi + 0x24] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x98u))); /* mov edx, dword ptr [esi + 0x98] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x18u)); PUSH32(c, 0x006e282cu); call_indirect(c, t_); } /* call dword ptr [eax + 0x18] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov ecx, dword ptr [esi + 0x24] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x84u))); /* mov edx, dword ptr [esi + 0x84] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x18u)); PUSH32(c, 0x006e283bu); call_indirect(c, t_); } /* call dword ptr [eax + 0x18] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov ecx, dword ptr [esi + 0x24] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x80u))); /* mov edx, dword ptr [esi + 0x80] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x18u)); PUSH32(c, 0x006e284au); call_indirect(c, t_); } /* call dword ptr [eax + 0x18] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x38u))); /* mov eax, dword ptr [esi + 0x38] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_006e286a; /* jle 0x6e286a */
L_006e2853:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x7cu))); /* mov edx, dword ptr [esi + 0x7c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov ecx, dword ptr [esi + 0x24] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edx + c->edi * 4))); /* mov edx, dword ptr [edx + edi*4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x20u)); PUSH32(c, 0x006e2862u); call_indirect(c, t_); } /* call dword ptr [eax + 0x20] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x38u))); /* mov eax, dword ptr [esi + 0x38] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if ((c->sf != c->of)) goto L_006e2853; /* jl 0x6e2853 */
L_006e286a:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov ecx, dword ptr [esi + 0x24] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x7cu))); /* mov edx, dword ptr [esi + 0x7c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x18u)); PUSH32(c, 0x006e2876u); call_indirect(c, t_); } /* call dword ptr [eax + 0x18] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov ecx, dword ptr [esi + 0x24] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x78u))); /* mov edx, dword ptr [esi + 0x78] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x18u)); PUSH32(c, 0x006e2882u); call_indirect(c, t_); } /* call dword ptr [eax + 0x18] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov ecx, dword ptr [esi + 0x24] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x74u))); /* mov edx, dword ptr [esi + 0x74] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x18u)); PUSH32(c, 0x006e288eu); call_indirect(c, t_); } /* call dword ptr [eax + 0x18] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov ecx, dword ptr [esi + 0x24] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x70u))); /* mov edx, dword ptr [esi + 0x70] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x18u)); PUSH32(c, 0x006e289au); call_indirect(c, t_); } /* call dword ptr [eax + 0x18] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x6ed170u)); /* mov dword ptr [esi], 0x1000d170 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_006e28c0(CPU *c) { /* PTR_006e28c0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov ecx, dword ptr [esi + 0x24] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x90u))); /* mov edx, dword ptr [esi + 0x90] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x48u)); PUSH32(c, 0x006e28d4u); call_indirect(c, t_); } /* call dword ptr [eax + 0x48] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x48u))); /* mov eax, dword ptr [esi + 0x48] */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 8], ebx */
    if ((c->zf || c->sf != c->of)) goto L_006e29e9; /* jle 0x6e29e9 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov ebp, dword ptr [esp + 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    ; /* nop  */
    c->esp = (uint32_t)((uint32_t)(c->esp)); /* lea esp, [esp] */
L_006e28f0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8cu))); /* mov eax, dword ptr [esi + 0x8c] */
    c->edx = (uint32_t)((uint32_t)(c->eax + c->ebx)); /* lea edx, [eax + ebx] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edx)) & (uint8_t)0x1u)); /* test byte ptr [edx], 1 */
    if (c->zf) goto L_006e29d0; /* je 0x6e29d0 */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)logic32(c, (uint32_t)(c->ebp & c->ebp)); /* test ebp, ebp */
    if ((c->zf || c->sf != c->of)) goto L_006e2944; /* jle 0x6e2944 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov ecx, dword ptr [esp + 0x18] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    ; /* nop  */
L_006e2910:;
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x4u))); /* fld dword ptr [ecx + 4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edx + 0xcu))); /* fmul dword ptr [edx + 0xc] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0xfffffffcu))); /* fld dword ptr [ecx - 4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edx + 0x4u))); /* fmul dword ptr [edx + 4] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx))); /* fld dword ptr [ecx] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edx + 0x8u))); /* fmul dword ptr [edx + 8] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->ecx + 0x8u))); /* fsub dword ptr [ecx + 8] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->edx + 0x10u))); FPOP(c); /* fcomp dword ptr [edx + 0x10] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x41u)); /* test ah, 0x41 */
    if (c->zf) goto L_006e293c; /* je 0x6e293c */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x10u)); /* add ecx, 0x10 */
    (void)sub32(c, c->edi, c->ebp); /* cmp edi, ebp */
    if ((c->sf != c->of)) goto L_006e2910; /* jl 0x6e2910 */
    goto L_006e2944; /* jmp 0x6e2944 */
L_006e293c:;
    (void)sub32(c, c->edi, c->ebp); /* cmp edi, ebp */
    if ((c->sf != c->of)) goto L_006e29d0; /* jl 0x6e29d0 */
L_006e2944:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x28u))); /* mov eax, dword ptr [edx + 0x28] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov ecx, dword ptr [esi + 0x24] */
    c->edx = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea edx, [eax + eax*4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x94u))); /* mov eax, dword ptr [esi + 0x94] */
    c->edi = (uint32_t)((uint32_t)(c->eax + c->edx * 4)); /* lea edi, [eax + edx*4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x10u))); /* mov eax, dword ptr [edi + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x4cu)); PUSH32(c, 0x006e2963u); call_indirect(c, t_); } /* call dword ptr [edx + 0x4c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8cu))); /* mov eax, dword ptr [esi + 0x8c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->ebx + 0x14u))); /* mov eax, dword ptr [eax + ebx + 0x14] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esi + 0x80u))); /* mov ebp, dword ptr [esi + 0x80] */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)(uint32_t)0x38u; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, eax, 0x38 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov ecx, dword ptr [esi + 0x24] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    c->eax = (uint32_t)(add32(c, c->eax, c->ebp)); /* add eax, ebp */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x24u)); PUSH32(c, 0x006e2981u); call_indirect(c, t_); } /* call dword ptr [edx + 0x24] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov eax, dword ptr [esp + 0x20] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e29a4; /* je 0x6e29a4 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8cu))); /* mov ecx, dword ptr [esi + 0x8c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + c->ebx + 0x14u))); /* mov edx, dword ptr [ecx + ebx + 0x14] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esi + 0x80u))); /* mov ebp, dword ptr [esi + 0x80] */
    { int64_t r_ = (int64_t)(int32_t)c->edx * (int32_t)(uint32_t)0x38u; c->edx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul edx, edx, 0x38 */
    c->edx = (uint32_t)(add32(c, c->edx, c->ebp)); /* add edx, ebp */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = c->eax; PUSH32(c, 0x006e29a1u); call_indirect(c, t_); } /* call eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_006e29a4:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8cu))); /* mov eax, dword ptr [esi + 0x8c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + c->ebx + 0x20u))); /* mov edx, dword ptr [eax + ebx + 0x20] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov ecx, dword ptr [esi + 0x24] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov ebp, dword ptr [ecx] */
    c->eax = (uint32_t)(add32(c, c->eax, c->ebx)); /* add eax, ebx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x24u))); /* mov edx, dword ptr [eax + 0x24] */
    c->edx = (uint32_t)((uint32_t)(c->edx + c->edx * 2)); /* lea edx, [edx + edx*2] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov edx, dword ptr [edi + 8] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x30u))); /* mov edx, dword ptr [eax + 0x30] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x2cu))); /* mov eax, dword ptr [eax + 0x2c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ebp + 0x50u)); PUSH32(c, 0x006e29ccu); call_indirect(c, t_); } /* call dword ptr [ebp + 0x50] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov ebp, dword ptr [esp + 0x1c] */
L_006e29d0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x48u))); /* mov ecx, dword ptr [esi + 0x48] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x44u)); /* add ebx, 0x44 */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    if ((c->sf != c->of)) goto L_006e28f0; /* jl 0x6e28f0 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
L_006e29e9:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 16; return; /* ret 0xc */
}

void f_006e29f0(CPU *c) { /* PTR_006e29f0 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0x2cu))); /* mov al, byte ptr [ecx + 0x2c] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x78u)); /* sub esp, 0x78 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx | (uint32_t)0xffffffffu))); /* or edx, 0xffffffff */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x2u)); /* test al, 2 */
    if (c->zf) goto L_006e2d0a; /* je 0x6e2d0a */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x9cu))); /* mov eax, dword ptr [ecx + 0x9c] */
    (void)sub32(c, c->eax, c->edx); /* cmp eax, edx */
    if (c->zf) goto L_006e2d0a; /* je 0x6e2d0a */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov edx, dword ptr [ecx + 8] */
    FPUSH(c, RF64((uint32_t)(c->ecx + 0xb8u))); /* fld qword ptr [ecx + 0xb8] */
    ST(0) = FPRES(c, ST(0) - RF64((uint32_t)(c->ecx + 0xa0u))); /* fsub qword ptr [ecx + 0xa0] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 8)); /* lea eax, [eax + eax*8] */
    c->eax = (uint32_t)(add32(c, c->eax, c->edx)); /* add eax, edx */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->edx = (c->edx & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->eax + 0x2u))) << 8); /* mov dh, byte ptr [eax + 2] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)((uint32_t)R8((uint32_t)(c->eax))); /* movzx esi, byte ptr [eax] */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1u))); /* mov dl, byte ptr [eax + 1] */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->ebx = (c->ebx & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->eax + 0x8u))) << 8); /* mov bh, byte ptr [eax + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    WF64((uint32_t)(c->esp + 0x24u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x24] */
    c->edi = (uint32_t)((uint32_t)R8((uint32_t)(c->eax + 0x3u))); /* movzx edi, byte ptr [eax + 3] */
    FPUSH(c, RF64((uint32_t)(c->ecx + 0xc0u))); /* fld qword ptr [ecx + 0xc0] */
    ST(0) = FPRES(c, ST(0) - RF64((uint32_t)(c->ecx + 0xa8u))); /* fsub qword ptr [ecx + 0xa8] */
    c->edx = (uint32_t)(shl32(c, c->edx, 8)); /* shl edx, 8 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi | c->edx))); /* or esi, edx */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x7u))); /* mov bl, byte ptr [eax + 7] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->edx = (c->edx & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->eax + 0x5u))) << 8); /* mov dh, byte ptr [eax + 5] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x18], esi */
    WF64((uint32_t)(c->esp + 0x2cu), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x2c] */
    FPUSH(c, RF64((uint32_t)(c->ecx + 0xc8u))); /* fld qword ptr [ecx + 0xc8] */
    ST(0) = FPRES(c, ST(0) - RF64((uint32_t)(c->ecx + 0xb0u))); /* fsub qword ptr [ecx + 0xb0] */
    c->ebx = (uint32_t)(shl32(c, c->ebx, 8)); /* shl ebx, 8 */
    WF64((uint32_t)(c->esp + 0x34u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x34] */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x4u))); /* mov dl, byte ptr [eax + 4] */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->eax + 0x6u))); /* movzx eax, byte ptr [eax + 6] */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | c->eax))); /* or ebx, eax */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea eax, [esi + esi*2] */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x20], ebx */
    c->edx = (uint32_t)(shl32(c, c->edx, 8)); /* shl edx, 8 */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi | c->edx))); /* or edi, edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov edx, dword ptr [ecx + 4] */
    c->eax = (uint32_t)(shl32(c, c->eax, 2)); /* shl eax, 2 */
    c->esi = (uint32_t)((uint32_t)(c->edi + c->edi * 2)); /* lea esi, [edi + edi*2] */
    c->esi = (uint32_t)((uint32_t)(c->edx + c->esi * 4)); /* lea esi, [edx + esi*4] */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x1c], edi */
    FPUSH(c, (double)RF32((uint32_t)(c->esi))); /* fld dword ptr [esi] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->edx + c->eax))); /* fsub dword ptr [edx + eax] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x4u))); /* fld dword ptr [esi + 4] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->edx + c->eax + 0x4u))); /* fsub dword ptr [edx + eax + 4] */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x8u))); /* fld dword ptr [esi + 8] */
    c->esi = (uint32_t)((uint32_t)(c->ebx + c->ebx * 2)); /* lea esi, [ebx + ebx*2] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->edx + c->eax + 0x8u))); /* fsub dword ptr [edx + eax + 8] */
    c->esi = (uint32_t)((uint32_t)(c->edx + c->esi * 4)); /* lea esi, [edx + esi*4] */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi))); /* fld dword ptr [esi] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->edx + c->eax))); /* fsub dword ptr [edx + eax] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x4u))); /* fld dword ptr [esi + 4] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->edx + c->eax + 0x4u))); /* fsub dword ptr [edx + eax + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x8u))); /* fld dword ptr [esi + 8] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->edx + c->eax + 0x8u))); /* fsub dword ptr [edx + eax + 8] */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    WF64((uint32_t)(c->esp + 0x3cu), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x3c] */
    WF64((uint32_t)(c->esp + 0x44u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x44] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x2cu))); /* fld qword ptr [esp + 0x2c] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x44u))); /* fld qword ptr [esp + 0x44] */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->esp + 0x34u))); /* fmul qword ptr [esp + 0x34] */
    ST(1) = FPRES(c, ST(1) - ST(0)); FPOP(c); /* fsubp st(1) */
    WF64((uint32_t)(c->esp + 0x54u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x54] */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x34u))); /* fld qword ptr [esp + 0x34] */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->esp + 0x3cu))); /* fmul qword ptr [esp + 0x3c] */
    { double v_ = ST(1); FPUSH(c, v_); } /* fld st(1) */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->esp + 0x24u))); /* fmul qword ptr [esp + 0x24] */
    ST(1) = FPRES(c, ST(1) - ST(0)); FPOP(c); /* fsubp st(1) */
    WF64((uint32_t)(c->esp + 0x5cu), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x5c] */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x44u))); /* fld qword ptr [esp + 0x44] */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->esp + 0x24u))); /* fmul qword ptr [esp + 0x24] */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x2cu))); /* fld qword ptr [esp + 0x2c] */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->esp + 0x3cu))); /* fmul qword ptr [esp + 0x3c] */
    ST(1) = FPRES(c, ST(1) - ST(0)); FPOP(c); /* fsubp st(1) */
    WF64((uint32_t)(c->esp + 0x64u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x64] */
    { double v_ = ST(1); FPUSH(c, v_); } /* fld st(1) */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->esp + 0x64u))); /* fmul qword ptr [esp + 0x64] */
    { double v_ = ST(3); FPUSH(c, v_); } /* fld st(3) */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->esp + 0x5cu))); /* fmul qword ptr [esp + 0x5c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x54u))); /* fld qword ptr [esp + 0x54] */
    ST(0) = FPRES(c, ST(0) * ST(5)); /* fmul st(5) */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, FDIV(c, RF64((uint32_t)(0x6ed0d8u)), ST(0))); /* fdivr qword ptr [0x1000d0d8] */
    WF64((uint32_t)(c->esp + 0xcu), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0xc] */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + c->eax))); /* fld dword ptr [edx + eax] */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + c->eax + 0x4u))); /* fld dword ptr [edx + eax + 4] */
    WF64((uint32_t)(c->esp + 0x74u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x74] */
    FPUSH(c, (double)RF32((uint32_t)(c->edx + c->eax + 0x8u))); /* fld dword ptr [edx + eax + 8] */
    WF64((uint32_t)(c->esp + 0x7cu), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x7c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x88u))); /* mov edx, dword ptr [esp + 0x88] */
    ST(0) = FPRES(c, RF64((uint32_t)(c->ecx + 0xa0u)) - ST(0)); /* fsubr qword ptr [ecx + 0xa0] */
    FPUSH(c, RF64((uint32_t)(c->ecx + 0xa8u))); /* fld qword ptr [ecx + 0xa8] */
    ST(0) = FPRES(c, ST(0) - RF64((uint32_t)(c->esp + 0x74u))); /* fsub qword ptr [esp + 0x74] */
    FPUSH(c, RF64((uint32_t)(c->ecx + 0xb0u))); /* fld qword ptr [ecx + 0xb0] */
    ST(0) = FPRES(c, ST(0) - RF64((uint32_t)(c->esp + 0x7cu))); /* fsub qword ptr [esp + 0x7c] */
    WF64((uint32_t)(c->esp + 0x7cu), ST(0)); /* fst qword ptr [esp + 0x7c] */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->esp + 0x64u))); /* fmul qword ptr [esp + 0x64] */
    { double v_ = ST(1); FPUSH(c, v_); } /* fld st(1) */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->esp + 0x5cu))); /* fmul qword ptr [esp + 0x5c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    { double v_ = ST(2); FPUSH(c, v_); } /* fld st(2) */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->esp + 0x54u))); /* fmul qword ptr [esp + 0x54] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->esp + 0xcu))); /* fmul qword ptr [esp + 0xc] */
    WF32((uint32_t)(c->edx), (float)ST(0)); FPOP(c); /* fstp dword ptr [edx] */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * ST(4)); /* fmul st(4) */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x7cu))); /* fld qword ptr [esp + 0x7c] */
    ST(0) = FPRES(c, ST(0) * ST(6)); /* fmul st(6) */
    ST(1) = FPRES(c, ST(1) - ST(0)); FPOP(c); /* fsubp st(1) */
    WF64((uint32_t)(c->esp + 0x54u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x54] */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x7cu))); /* fld qword ptr [esp + 0x7c] */
    ST(0) = FPRES(c, ST(0) * ST(6)); /* fmul st(6) */
    { double v_ = ST(4); FPUSH(c, v_); } /* fld st(4) */
    ST(0) = FPRES(c, ST(0) * ST(3)); /* fmul st(3) */
    ST(1) = FPRES(c, ST(1) - ST(0)); FPOP(c); /* fsubp st(1) */
    WF64((uint32_t)(c->esp + 0x5cu), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x5c] */
    { double v_ = ST(4); FPUSH(c, v_); } /* fld st(4) */
    ST(0) = FPRES(c, ST(0) * ST(2)); /* fmul st(2) */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * ST(6)); /* fmul st(6) */
    ST(1) = FPRES(c, ST(1) - ST(0)); FPOP(c); /* fsubp st(1) */
    WF64((uint32_t)(c->esp + 0x64u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x64] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x64u))); /* fld qword ptr [esp + 0x64] */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->esp + 0x34u))); /* fmul qword ptr [esp + 0x34] */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x5cu))); /* fld qword ptr [esp + 0x5c] */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->esp + 0x2cu))); /* fmul qword ptr [esp + 0x2c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x54u))); /* fld qword ptr [esp + 0x54] */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->esp + 0x24u))); /* fmul qword ptr [esp + 0x24] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->esp + 0xcu))); /* fmul qword ptr [esp + 0xc] */
    WF32((uint32_t)(c->edx + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edx + 4] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov esi, dword ptr [ecx + 4] */
    { double v_ = ST(2); FPUSH(c, v_); } /* fld st(2) */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { double v_ = ST(2); FPUSH(c, v_); } /* fld st(2) */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->esp + 0x44u))); /* fmul qword ptr [esp + 0x44] */
    ST(1) = FPRES(c, ST(1) - ST(0)); FPOP(c); /* fsubp st(1) */
    WF64((uint32_t)(c->esp + 0x54u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x54] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->esp + 0x3cu))); /* fmul qword ptr [esp + 0x3c] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * ST(3)); /* fmul st(3) */
    ST(1) = FPRES(c, ST(1) - ST(0)); FPOP(c); /* fsubp st(1) */
    WF64((uint32_t)(c->esp + 0x5cu), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x5c] */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x44u))); /* fld qword ptr [esp + 0x44] */
    ST(2) = FPRES(c, ST(2) * ST(0)); FPOP(c); /* fmulp st(2) */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->esp + 0x3cu))); /* fmul qword ptr [esp + 0x3c] */
    ST(2) = FPRES(c, ST(2) - ST(0)); FPOP(c); /* fsubp st(2) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x5cu))); /* fld qword ptr [esp + 0x5c] */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->esp + 0x5cu))); /* fmul qword ptr [esp + 0x5c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x54u))); /* fld qword ptr [esp + 0x54] */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->esp + 0x54u))); /* fmul qword ptr [esp + 0x54] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, sqrt(ST(0))); /* fsqrt  */
    ST(0) = FPRES(c, FDIV(c, RF64((uint32_t)(0x6ed0d8u)), ST(0))); /* fdivr qword ptr [0x1000d0d8] */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x54u))); /* fld qword ptr [esp + 0x54] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF64((uint32_t)(c->esp + 0x3cu), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x3c] */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x5cu))); /* fld qword ptr [esp + 0x5c] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF64((uint32_t)(c->esp + 0x44u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 0x44] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, (double)RF32((uint32_t)(c->esi))); /* fld dword ptr [esi] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x4u))); /* fld dword ptr [esi + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x8u))); /* fld dword ptr [esi + 8] */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x3cu))); /* fld qword ptr [esp + 0x3c] */
    WF32((uint32_t)(c->edx + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edx + 0x10] */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x44u))); /* fld qword ptr [esp + 0x44] */
    WF32((uint32_t)(c->edx + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edx + 0x14] */
    { double v_ = ST(3); FPUSH(c, v_); } /* fld st(3) */
    WF32((uint32_t)(c->edx + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edx + 0x18] */
    ST(0) = FPRES(c, ST(0) * ST(3)); /* fmul st(3) */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->esp + 0x44u))); /* fmul qword ptr [esp + 0x44] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->esp + 0x3cu))); /* fmul qword ptr [esp + 0x3c] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->edx + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [edx + 0x1c] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x48u))); /* mov esi, dword ptr [ecx + 0x48] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    if ((c->zf || c->sf != c->of)) goto L_006e2ccb; /* jle 0x6e2ccb */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ecx + 0x9cu))); /* mov ebx, dword ptr [ecx + 0x9c] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ecx + 0x98u))); /* mov edi, dword ptr [ecx + 0x98] */
L_006e2ca0:;
    (void)sub32(c, R32((uint32_t)(c->edi)), c->ebx); /* cmp dword ptr [edi], ebx */
    if ((!c->zf && c->sf == c->of)) goto L_006e2cae; /* jg 0x6e2cae */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if ((c->sf != c->of)) goto L_006e2ca0; /* jl 0x6e2ca0 */
    goto L_006e2ccb; /* jmp 0x6e2ccb */
L_006e2cae:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [edx + 8], eax */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x9cu))); /* mov esi, dword ptr [ecx + 0x9c] */
    W32((uint32_t)(c->edx + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [edx + 0xc], esi */
    if ((c->zf || c->sf != c->of)) goto L_006e2ccb; /* jle 0x6e2ccb */
    c->edi = (uint32_t)(R32((uint32_t)(c->ecx + 0x98u))); /* mov edi, dword ptr [ecx + 0x98] */
    c->esi = (uint32_t)(sub32(c, c->esi, R32((uint32_t)(c->edi + c->eax * 4 + 0xfffffffcu)))); /* sub esi, dword ptr [edi + eax*4 - 4] */
    W32((uint32_t)(c->edx + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [edx + 0xc], esi */
L_006e2ccb:;
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x24u)); /* add edx, 0x24 */
L_006e2cd0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + c->esi * 4 + 0x18u))); /* mov eax, dword ptr [esp + esi*4 + 0x18] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov edi, dword ptr [ecx + 4] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea eax, [eax + eax*2] */
    c->eax = (uint32_t)(shl32(c, c->eax, 2)); /* shl eax, 2 */
    c->edi = (uint32_t)(R32((uint32_t)(c->eax + c->edi))); /* mov edi, dword ptr [eax + edi] */
    W32((uint32_t)(c->edx + 0xfffffffcu), (uint32_t)(c->edi)); /* mov dword ptr [edx - 4], edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov edi, dword ptr [ecx + 4] */
    c->edi = (uint32_t)(R32((uint32_t)(c->edi + c->eax + 0x4u))); /* mov edi, dword ptr [edi + eax + 4] */
    W32((uint32_t)(c->edx), (uint32_t)(c->edi)); /* mov dword ptr [edx], edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov edi, dword ptr [ecx + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + c->eax + 0x8u))); /* mov eax, dword ptr [edi + eax + 8] */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [edx + 4], eax */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0xcu)); /* add edx, 0xc */
    (void)sub32(c, c->esi, (uint32_t)0x3u); /* cmp esi, 3 */
    if ((c->sf != c->of)) goto L_006e2cd0; /* jl 0x6e2cd0 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x78u)); /* add esp, 0x78 */
    c->esp += 8; return; /* ret 4 */
L_006e2d0a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x7cu))); /* mov eax, dword ptr [esp + 0x7c] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)((uint32_t)0xbf800000u)); /* mov dword ptr [eax + 4], 0xbf800000 */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0xbf800000u)); /* mov dword ptr [eax], 0xbf800000 */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->edx)); /* mov dword ptr [eax + 0xc], edx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 8], edx */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x10u)); /* add eax, 0x10 */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 4], ecx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0xc], ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x78u)); /* add esp, 0x78 */
    c->esp += 8; return; /* ret 4 */
}

void f_006e2d40(CPU *c) { /* PTR_006e2d40 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)(uint32_t)0x38u; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, eax, 0x38 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x80u))); /* mov esi, dword ptr [ecx + 0x80] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edi, dword ptr [esp + 0x10] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->ecx = (uint32_t)((uint32_t)0xeu); /* mov ecx, 0xe */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 12; return; /* ret 8 */
}

void f_006e2d70(CPU *c) { /* PTR_006e2d70 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x80u))); /* mov edx, dword ptr [ecx + 0x80] */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)(uint32_t)0x38u; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, eax, 0x38 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edi, dword ptr [esi] */
    W32((uint32_t)(c->eax + c->edx), (uint32_t)(c->edi)); /* mov dword ptr [eax + edx], edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov edi, dword ptr [esi + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x80u))); /* mov edx, dword ptr [ecx + 0x80] */
    W32((uint32_t)(c->eax + c->edx + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [eax + edx + 8], edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov edi, dword ptr [esi + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x80u))); /* mov edx, dword ptr [ecx + 0x80] */
    W32((uint32_t)(c->eax + c->edx + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [eax + edx + 0xc], edi */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x80u))); /* mov edx, dword ptr [ecx + 0x80] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov edi, dword ptr [esi + 4] */
    W32((uint32_t)(c->eax + c->edx + 0x4u), (uint32_t)(c->edi)); /* mov dword ptr [eax + edx + 4], edi */
    c->edx = (uint32_t)((uint32_t)(c->eax + 0x20u)); /* lea edx, [eax + 0x20] */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x20u)); /* lea eax, [esi + 0x20] */
    c->esi = (uint32_t)((uint32_t)0x4u); /* mov esi, 4 */
    ; /* nop  */
    c->esp = (uint32_t)((uint32_t)(c->esp)); /* lea esp, [esp] */
L_006e2dc0:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->eax + 0xfffffff0u))); /* mov ebx, dword ptr [eax - 0x10] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ecx + 0x80u))); /* mov edi, dword ptr [ecx + 0x80] */
    W32((uint32_t)(c->edx + c->edi + 0xfffffff0u), (uint32_t)(c->ebx)); /* mov dword ptr [edx + edi - 0x10], ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ebx, dword ptr [eax] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ecx + 0x80u))); /* mov edi, dword ptr [ecx + 0x80] */
    W32((uint32_t)(c->edx + c->edi), (uint32_t)(c->ebx)); /* mov dword ptr [edx + edi], ebx */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x4u)); /* add eax, 4 */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x4u)); /* add edx, 4 */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    if (!c->zf) goto L_006e2dc0; /* jne 0x6e2dc0 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 12; return; /* ret 8 */
}

void f_006e2df0(CPU *c) { /* PTR_006e2df0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)(uint32_t)0x44u; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, eax, 0x44 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x8cu))); /* mov esi, dword ptr [ecx + 0x8c] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->edx))); /* mov edi, dword ptr [edx] */
    W32((uint32_t)(c->eax + c->esi), (uint32_t)(c->edi)); /* mov dword ptr [eax + esi], edi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8cu))); /* mov ecx, dword ptr [ecx + 0x8c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edx + 0x14u))); /* mov edx, dword ptr [edx + 0x14] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    W32((uint32_t)(c->eax + c->ecx + 0x14u), (uint32_t)(c->edx)); /* mov dword ptr [eax + ecx + 0x14], edx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 12; return; /* ret 8 */
}

void f_006e2e20(CPU *c) { /* PTR_006e2e20 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)(uint32_t)0x44u; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, eax, 0x44 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ebx, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    c->esi = (uint32_t)(R32((uint32_t)(c->edx + 0x8cu))); /* mov esi, dword ptr [edx + 0x8c] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(c->ebx); /* mov edi, ebx */
    c->ecx = (uint32_t)((uint32_t)0x11u); /* mov ecx, 0x11 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0x8cu))); /* mov ecx, dword ptr [edx + 0x8c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->ecx + 0x28u))); /* mov eax, dword ptr [eax + ecx + 0x28] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0x94u))); /* mov ecx, dword ptr [edx + 0x94] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea eax, [eax + eax*4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + c->eax * 4 + 0x10u))); /* mov edx, dword ptr [ecx + eax*4 + 0x10] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->ebx + 0x28u), (uint32_t)(c->edx)); /* mov dword ptr [ebx + 0x28], edx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 12; return; /* ret 8 */
}

void f_006e2e70(CPU *c) { /* PTR_006e2e70 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x38u))); /* mov edx, dword ptr [ecx + 0x38] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    W32((uint32_t)(c->eax), (uint32_t)(c->edx)); /* mov dword ptr [eax], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x3cu))); /* mov edx, dword ptr [ecx + 0x3c] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 4], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x40u))); /* mov edx, dword ptr [ecx + 0x40] */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 8], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x48u))); /* mov edx, dword ptr [ecx + 0x48] */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->edx)); /* mov dword ptr [eax + 0xc], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4cu))); /* mov edx, dword ptr [ecx + 0x4c] */
    W32((uint32_t)(c->eax + 0x10u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 0x10], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x50u))); /* mov edx, dword ptr [ecx + 0x50] */
    W32((uint32_t)(c->eax + 0x14u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 0x14], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x44u))); /* mov edx, dword ptr [ecx + 0x44] */
    W32((uint32_t)(c->eax + 0x18u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 0x18], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x60u))); /* mov edx, dword ptr [ecx + 0x60] */
    W32((uint32_t)(c->eax + 0x1cu), (uint32_t)(c->edx)); /* mov dword ptr [eax + 0x1c], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x64u))); /* mov edx, dword ptr [ecx + 0x64] */
    W32((uint32_t)(c->eax + 0x20u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 0x20], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x68u))); /* mov edx, dword ptr [ecx + 0x68] */
    W32((uint32_t)(c->eax + 0x24u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 0x24], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x54u))); /* mov edx, dword ptr [ecx + 0x54] */
    W32((uint32_t)(c->eax + 0x28u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 0x28], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x58u))); /* mov edx, dword ptr [ecx + 0x58] */
    W32((uint32_t)(c->eax + 0x2cu), (uint32_t)(c->edx)); /* mov dword ptr [eax + 0x2c], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x5cu))); /* mov edx, dword ptr [ecx + 0x5c] */
    W32((uint32_t)(c->eax + 0x30u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 0x30], edx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x6cu))); /* mov ecx, dword ptr [ecx + 0x6c] */
    W32((uint32_t)(c->eax + 0x34u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x34], ecx */
    c->esp += 8; return; /* ret 4 */
}

void f_006e2ed0(CPU *c) { /* PTR_006e2ed0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x94u))); /* mov ecx, dword ptr [ecx + 0x94] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea eax, [eax + eax*4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + c->eax * 4 + 0x10u))); /* mov eax, dword ptr [ecx + eax*4 + 0x10] */
    c->esp += 8; return; /* ret 4 */
}

void f_006e2ef0(CPU *c) { /* PTR_006e2ef0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x90u))); /* mov eax, dword ptr [ecx + 0x90] */
    c->esp += 4; return; /* ret  */
}

void f_006e2f00(CPU *c) { /* PTR_006e2f00 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x7cu))); /* mov eax, dword ptr [ecx + 0x7c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->ecx * 4))); /* mov eax, dword ptr [eax + ecx*4] */
    c->esp += 8; return; /* ret 4 */
}

void f_006e2f10(CPU *c) { /* PTR_006e2f10 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x78u))); /* mov eax, dword ptr [ecx + 0x78] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->edx * 4))); /* mov eax, dword ptr [eax + edx*4] */
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->ecx + 0x70u)))); /* add eax, dword ptr [ecx + 0x70] */
    c->esp += 8; return; /* ret 4 */
}

void f_006e2f20(CPU *c) { /* FUN_10002f20 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x34u))); /* mov eax, dword ptr [esi + 0x34] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_006e2f51; /* jle 0x6e2f51 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ebx, dword ptr [esp + 0x10] */
L_006e2f32:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x74u))); /* mov eax, dword ptr [esi + 0x74] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + c->edi * 4))); /* mov ecx, dword ptr [eax + edi*4] */
    c->ecx = (uint32_t)(add32(c, c->ecx, R32((uint32_t)(c->esi + 0x70u)))); /* add ecx, dword ptr [esi + 0x70] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x006e2f42u); f_006ec340(c); /* call 0x6ec340 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e2f5a; /* je 0x6e2f5a */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x34u))); /* mov eax, dword ptr [esi + 0x34] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if ((c->sf != c->of)) goto L_006e2f32; /* jl 0x6e2f32 */
L_006e2f51:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
L_006e2f5a:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x74u))); /* mov edx, dword ptr [esi + 0x74] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + c->edi * 4))); /* mov eax, dword ptr [edx + edi*4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x70u))); /* mov ecx, dword ptr [esi + 0x70] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
}

void f_006e2f70(CPU *c) { /* PTR_006e2f70 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x44u))); /* mov edx, dword ptr [ecx + 0x44] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    (void)sub32(c, c->eax, c->edx); /* cmp eax, edx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    if ((c->sf == c->of)) goto L_006e2f9c; /* jge 0x6e2f9c */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x88u))); /* mov ecx, dword ptr [ecx + 0x88] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { int64_t r_ = (int64_t)(int32_t)c->esi * (int32_t)(uint32_t)0x6cu; c->esi = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul esi, esi, 0x6c */
    c->ecx = (uint32_t)((uint32_t)(c->esi + c->ecx + 0x48u)); /* lea ecx, [esi + ecx + 0x48] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov esi, dword ptr [esp + 0xc] */
    ; /* nop  */
L_006e2f90:;
    (void)sub32(c, R32((uint32_t)(c->ecx)), c->esi); /* cmp dword ptr [ecx], esi */
    if (c->zf) goto L_006e2f9f; /* je 0x6e2f9f */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x6cu)); /* add ecx, 0x6c */
    (void)sub32(c, c->eax, c->edx); /* cmp eax, edx */
    if ((c->sf != c->of)) goto L_006e2f90; /* jl 0x6e2f90 */
L_006e2f9c:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
L_006e2f9f:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 12; return; /* ret 8 */
}

void f_006e2fb0(CPU *c) { /* PTR_006e2fb0 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x44u))); /* mov edx, dword ptr [ecx + 0x44] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    (void)sub32(c, c->eax, c->edx); /* cmp eax, edx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    if ((c->sf == c->of)) goto L_006e2fdc; /* jge 0x6e2fdc */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x88u))); /* mov ecx, dword ptr [ecx + 0x88] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { int64_t r_ = (int64_t)(int32_t)c->esi * (int32_t)(uint32_t)0x6cu; c->esi = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul esi, esi, 0x6c */
    c->ecx = (uint32_t)((uint32_t)(c->esi + c->ecx + 0x44u)); /* lea ecx, [esi + ecx + 0x44] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov esi, dword ptr [esp + 0xc] */
    ; /* nop  */
L_006e2fd0:;
    (void)sub32(c, R32((uint32_t)(c->ecx)), c->esi); /* cmp dword ptr [ecx], esi */
    if (c->zf) goto L_006e2fdf; /* je 0x6e2fdf */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x6cu)); /* add ecx, 0x6c */
    (void)sub32(c, c->eax, c->edx); /* cmp eax, edx */
    if ((c->sf != c->of)) goto L_006e2fd0; /* jl 0x6e2fd0 */
L_006e2fdc:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
L_006e2fdf:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 12; return; /* ret 8 */
}

void f_006e2ff0(CPU *c) { /* PTR_006e2ff0 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x88u))); /* mov edx, dword ptr [ecx + 0x88] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)(uint32_t)0x6cu; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, eax, 0x6c */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + c->edx))); /* mov esi, dword ptr [eax + edx] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    W32((uint32_t)(c->edx), (uint32_t)(c->esi)); /* mov dword ptr [edx], esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x88u))); /* mov esi, dword ptr [ecx + 0x88] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + c->eax + 0x44u))); /* mov esi, dword ptr [esi + eax + 0x44] */
    W32((uint32_t)(c->edx + 0x44u), (uint32_t)(c->esi)); /* mov dword ptr [edx + 0x44], esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x88u))); /* mov esi, dword ptr [ecx + 0x88] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + c->eax + 0x48u))); /* mov esi, dword ptr [esi + eax + 0x48] */
    W32((uint32_t)(c->edx + 0x48u), (uint32_t)(c->esi)); /* mov dword ptr [edx + 0x48], esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x88u))); /* mov esi, dword ptr [ecx + 0x88] */
    c->esi = (uint32_t)((uint32_t)(c->esi + c->eax + 0x4cu)); /* lea esi, [esi + eax + 0x4c] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ebx, dword ptr [esi] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)((uint32_t)(c->edx + 0x4cu)); /* lea edi, [edx + 0x4c] */
    W32((uint32_t)(c->edi), (uint32_t)(c->ebx)); /* mov dword ptr [edi], ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ebx, dword ptr [esi + 4] */
    W32((uint32_t)(c->edi + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [edi + 4], ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ebx, dword ptr [esi + 8] */
    W32((uint32_t)(c->edi + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [edi + 8], ebx */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov esi, dword ptr [esi + 0xc] */
    W32((uint32_t)(c->edi + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [edi + 0xc], esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x88u))); /* mov esi, dword ptr [ecx + 0x88] */
    c->esi = (uint32_t)((uint32_t)(c->esi + c->eax + 0x5cu)); /* lea esi, [esi + eax + 0x5c] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ebx, dword ptr [esi] */
    c->edi = (uint32_t)((uint32_t)(c->edx + 0x5cu)); /* lea edi, [edx + 0x5c] */
    W32((uint32_t)(c->edi), (uint32_t)(c->ebx)); /* mov dword ptr [edi], ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ebx, dword ptr [esi + 4] */
    W32((uint32_t)(c->edi + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [edi + 4], ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ebx, dword ptr [esi + 8] */
    W32((uint32_t)(c->edi + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [edi + 8], ebx */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov esi, dword ptr [esi + 0xc] */
    W32((uint32_t)(c->edi + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [edi + 0xc], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x88u))); /* mov ecx, dword ptr [ecx + 0x88] */
    c->esi = (uint32_t)((uint32_t)(c->ecx + c->eax + 0x4u)); /* lea esi, [ecx + eax + 4] */
    c->edi = (uint32_t)((uint32_t)(c->edx + 0x4u)); /* lea edi, [edx + 4] */
    c->ecx = (uint32_t)((uint32_t)0x10u); /* mov ecx, 0x10 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 12; return; /* ret 8 */
}

void f_006e3090(CPU *c) { /* PTR_006e3090 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)(uint32_t)0x6cu; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, eax, 0x6c */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x88u))); /* mov esi, dword ptr [ecx + 0x88] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->edx))); /* mov edi, dword ptr [edx] */
    W32((uint32_t)(c->eax + c->esi), (uint32_t)(c->edi)); /* mov dword ptr [eax + esi], edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ecx + 0x88u))); /* mov edi, dword ptr [ecx + 0x88] */
    c->edi = (uint32_t)((uint32_t)(c->edi + c->eax + 0x4cu)); /* lea edi, [edi + eax + 0x4c] */
    c->esi = (uint32_t)((uint32_t)(c->edx + 0x4cu)); /* lea esi, [edx + 0x4c] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ebx, dword ptr [esi] */
    W32((uint32_t)(c->edi), (uint32_t)(c->ebx)); /* mov dword ptr [edi], ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ebx, dword ptr [esi + 4] */
    W32((uint32_t)(c->edi + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [edi + 4], ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ebx, dword ptr [esi + 8] */
    W32((uint32_t)(c->edi + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [edi + 8], ebx */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov esi, dword ptr [esi + 0xc] */
    W32((uint32_t)(c->edi + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [edi + 0xc], esi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ecx + 0x88u))); /* mov edi, dword ptr [ecx + 0x88] */
    c->edi = (uint32_t)((uint32_t)(c->edi + c->eax + 0x5cu)); /* lea edi, [edi + eax + 0x5c] */
    c->esi = (uint32_t)((uint32_t)(c->edx + 0x5cu)); /* lea esi, [edx + 0x5c] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ebx, dword ptr [esi] */
    W32((uint32_t)(c->edi), (uint32_t)(c->ebx)); /* mov dword ptr [edi], ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ebx, dword ptr [esi + 4] */
    W32((uint32_t)(c->edi + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [edi + 4], ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ebx, dword ptr [esi + 8] */
    W32((uint32_t)(c->edi + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [edi + 8], ebx */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov esi, dword ptr [esi + 0xc] */
    W32((uint32_t)(c->edi + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [edi + 0xc], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x88u))); /* mov ecx, dword ptr [ecx + 0x88] */
    c->edi = (uint32_t)((uint32_t)(c->ecx + c->eax + 0x4u)); /* lea edi, [ecx + eax + 4] */
    c->esi = (uint32_t)((uint32_t)(c->edx + 0x4u)); /* lea esi, [edx + 4] */
    c->ecx = (uint32_t)((uint32_t)0x10u); /* mov ecx, 0x10 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 12; return; /* ret 8 */
}

void f_006e3110(CPU *c) { /* PTR_006e3110 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x48u))); /* mov edx, dword ptr [ecx + 0x48] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    (void)sub32(c, c->eax, c->edx); /* cmp eax, edx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    if ((c->sf == c->of)) goto L_006e313c; /* jge 0x6e313c */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8cu))); /* mov ecx, dword ptr [ecx + 0x8c] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { int64_t r_ = (int64_t)(int32_t)c->esi * (int32_t)(uint32_t)0x44u; c->esi = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul esi, esi, 0x44 */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->esi + 0x1cu)); /* lea ecx, [ecx + esi + 0x1c] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov esi, dword ptr [esp + 0xc] */
    ; /* nop  */
L_006e3130:;
    (void)sub32(c, R32((uint32_t)(c->ecx)), c->esi); /* cmp dword ptr [ecx], esi */
    if (c->zf) goto L_006e313f; /* je 0x6e313f */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x44u)); /* add ecx, 0x44 */
    (void)sub32(c, c->eax, c->edx); /* cmp eax, edx */
    if ((c->sf != c->of)) goto L_006e3130; /* jl 0x6e3130 */
L_006e313c:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
L_006e313f:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 12; return; /* ret 8 */
}

void f_006e3150(CPU *c) { /* PTR_006e3150 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x48u))); /* mov edx, dword ptr [ecx + 0x48] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    (void)sub32(c, c->eax, c->edx); /* cmp eax, edx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    if ((c->sf == c->of)) goto L_006e317c; /* jge 0x6e317c */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8cu))); /* mov ecx, dword ptr [ecx + 0x8c] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { int64_t r_ = (int64_t)(int32_t)c->esi * (int32_t)(uint32_t)0x44u; c->esi = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul esi, esi, 0x44 */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->esi + 0x18u)); /* lea ecx, [ecx + esi + 0x18] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov esi, dword ptr [esp + 0xc] */
    ; /* nop  */
L_006e3170:;
    (void)sub32(c, R32((uint32_t)(c->ecx)), c->esi); /* cmp dword ptr [ecx], esi */
    if (c->zf) goto L_006e317f; /* je 0x6e317f */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x44u)); /* add ecx, 0x44 */
    (void)sub32(c, c->eax, c->edx); /* cmp eax, edx */
    if ((c->sf != c->of)) goto L_006e3170; /* jl 0x6e3170 */
L_006e317c:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
L_006e317f:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 12; return; /* ret 8 */
}

void f_006e3190(CPU *c) { /* PTR_006e3190 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x3cu))); /* mov edx, dword ptr [ecx + 0x3c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    (void)sub32(c, c->eax, c->edx); /* cmp eax, edx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    if ((c->sf == c->of)) goto L_006e31bc; /* jge 0x6e31bc */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x80u))); /* mov ecx, dword ptr [ecx + 0x80] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { int64_t r_ = (int64_t)(int32_t)c->esi * (int32_t)(uint32_t)0x38u; c->esi = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul esi, esi, 0x38 */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->esi + 0x34u)); /* lea ecx, [ecx + esi + 0x34] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov esi, dword ptr [esp + 0xc] */
    ; /* nop  */
L_006e31b0:;
    (void)sub32(c, R32((uint32_t)(c->ecx)), c->esi); /* cmp dword ptr [ecx], esi */
    if (c->zf) goto L_006e31bf; /* je 0x6e31bf */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x38u)); /* add ecx, 0x38 */
    (void)sub32(c, c->eax, c->edx); /* cmp eax, edx */
    if ((c->sf != c->of)) goto L_006e31b0; /* jl 0x6e31b0 */
L_006e31bc:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
L_006e31bf:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 12; return; /* ret 8 */
}

void f_006e31d0(CPU *c) { /* PTR_006e31d0 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x3cu))); /* mov edx, dword ptr [ecx + 0x3c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    (void)sub32(c, c->eax, c->edx); /* cmp eax, edx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    if ((c->sf == c->of)) goto L_006e31fc; /* jge 0x6e31fc */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x80u))); /* mov ecx, dword ptr [ecx + 0x80] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { int64_t r_ = (int64_t)(int32_t)c->esi * (int32_t)(uint32_t)0x38u; c->esi = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul esi, esi, 0x38 */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->esi + 0x30u)); /* lea ecx, [ecx + esi + 0x30] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov esi, dword ptr [esp + 0xc] */
    ; /* nop  */
L_006e31f0:;
    (void)sub32(c, R32((uint32_t)(c->ecx)), c->esi); /* cmp dword ptr [ecx], esi */
    if (c->zf) goto L_006e31ff; /* je 0x6e31ff */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x38u)); /* add ecx, 0x38 */
    (void)sub32(c, c->eax, c->edx); /* cmp eax, edx */
    if ((c->sf != c->of)) goto L_006e31f0; /* jl 0x6e31f0 */
L_006e31fc:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
L_006e31ff:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 12; return; /* ret 8 */
}

void f_006e3210(CPU *c) { /* PTR_006e3210 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x40u))); /* mov edx, dword ptr [ecx + 0x40] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    (void)sub32(c, c->eax, c->edx); /* cmp eax, edx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    if ((c->sf == c->of)) goto L_006e323c; /* jge 0x6e323c */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x84u))); /* mov ecx, dword ptr [ecx + 0x84] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { int64_t r_ = (int64_t)(int32_t)c->esi * (int32_t)(uint32_t)0x54u; c->esi = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul esi, esi, 0x54 */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->esi + 0x10u)); /* lea ecx, [ecx + esi + 0x10] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov esi, dword ptr [esp + 0xc] */
    ; /* nop  */
L_006e3230:;
    (void)sub32(c, R32((uint32_t)(c->ecx)), c->esi); /* cmp dword ptr [ecx], esi */
    if (c->zf) goto L_006e323f; /* je 0x6e323f */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x54u)); /* add ecx, 0x54 */
    (void)sub32(c, c->eax, c->edx); /* cmp eax, edx */
    if ((c->sf != c->of)) goto L_006e3230; /* jl 0x6e3230 */
L_006e323c:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
L_006e323f:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 12; return; /* ret 8 */
}

void f_006e3250(CPU *c) { /* PTR_006e3250 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x40u))); /* mov edx, dword ptr [ecx + 0x40] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    (void)sub32(c, c->eax, c->edx); /* cmp eax, edx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    if ((c->sf == c->of)) goto L_006e327c; /* jge 0x6e327c */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x84u))); /* mov ecx, dword ptr [ecx + 0x84] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { int64_t r_ = (int64_t)(int32_t)c->esi * (int32_t)(uint32_t)0x54u; c->esi = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul esi, esi, 0x54 */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->esi + 0xcu)); /* lea ecx, [ecx + esi + 0xc] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov esi, dword ptr [esp + 0xc] */
    ; /* nop  */
L_006e3270:;
    (void)sub32(c, R32((uint32_t)(c->ecx)), c->esi); /* cmp dword ptr [ecx], esi */
    if (c->zf) goto L_006e327f; /* je 0x6e327f */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x54u)); /* add ecx, 0x54 */
    (void)sub32(c, c->eax, c->edx); /* cmp eax, edx */
    if ((c->sf != c->of)) goto L_006e3270; /* jl 0x6e3270 */
L_006e327c:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
L_006e327f:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 12; return; /* ret 8 */
}

void f_006e3290(CPU *c) { /* PTR_006e3290 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)(uint32_t)0x54u; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, eax, 0x54 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x84u))); /* mov esi, dword ptr [ecx + 0x84] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->edx + 0x30u))); /* mov edi, dword ptr [edx + 0x30] */
    W32((uint32_t)(c->esi + c->eax + 0x30u), (uint32_t)(c->edi)); /* mov dword ptr [esi + eax + 0x30], edi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x84u))); /* mov esi, dword ptr [ecx + 0x84] */
    c->edi = (uint32_t)(R32((uint32_t)(c->edx + 0x34u))); /* mov edi, dword ptr [edx + 0x34] */
    W32((uint32_t)(c->esi + c->eax + 0x34u), (uint32_t)(c->edi)); /* mov dword ptr [esi + eax + 0x34], edi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x84u))); /* mov esi, dword ptr [ecx + 0x84] */
    c->edi = (uint32_t)(R32((uint32_t)(c->edx + 0x38u))); /* mov edi, dword ptr [edx + 0x38] */
    W32((uint32_t)(c->esi + c->eax + 0x38u), (uint32_t)(c->edi)); /* mov dword ptr [esi + eax + 0x38], edi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x84u))); /* mov esi, dword ptr [ecx + 0x84] */
    c->edi = (uint32_t)(R32((uint32_t)(c->edx + 0x14u))); /* mov edi, dword ptr [edx + 0x14] */
    W32((uint32_t)(c->esi + c->eax + 0x14u), (uint32_t)(c->edi)); /* mov dword ptr [esi + eax + 0x14], edi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x84u))); /* mov esi, dword ptr [ecx + 0x84] */
    c->edi = (uint32_t)(R32((uint32_t)(c->edx + 0x18u))); /* mov edi, dword ptr [edx + 0x18] */
    W32((uint32_t)(c->esi + c->eax + 0x18u), (uint32_t)(c->edi)); /* mov dword ptr [esi + eax + 0x18], edi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x84u))); /* mov esi, dword ptr [ecx + 0x84] */
    c->edi = (uint32_t)(R32((uint32_t)(c->edx + 0x1cu))); /* mov edi, dword ptr [edx + 0x1c] */
    W32((uint32_t)(c->esi + c->eax + 0x1cu), (uint32_t)(c->edi)); /* mov dword ptr [esi + eax + 0x1c], edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ecx + 0x84u))); /* mov edi, dword ptr [ecx + 0x84] */
    c->edi = (uint32_t)((uint32_t)(c->edi + c->eax + 0x48u)); /* lea edi, [edi + eax + 0x48] */
    c->esi = (uint32_t)((uint32_t)(c->edx + 0x48u)); /* lea esi, [edx + 0x48] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ebx, dword ptr [esi] */
    W32((uint32_t)(c->edi), (uint32_t)(c->ebx)); /* mov dword ptr [edi], ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ebx, dword ptr [esi + 4] */
    W32((uint32_t)(c->edi + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [edi + 4], ebx */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov esi, dword ptr [esi + 8] */
    W32((uint32_t)(c->edi + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [edi + 8], esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x84u))); /* mov esi, dword ptr [ecx + 0x84] */
    c->edi = (uint32_t)(R32((uint32_t)(c->edx + 0x44u))); /* mov edi, dword ptr [edx + 0x44] */
    W32((uint32_t)(c->esi + c->eax + 0x44u), (uint32_t)(c->edi)); /* mov dword ptr [esi + eax + 0x44], edi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x84u))); /* mov esi, dword ptr [ecx + 0x84] */
    c->edi = (uint32_t)(R32((uint32_t)(c->edx))); /* mov edi, dword ptr [edx] */
    W32((uint32_t)(c->eax + c->esi), (uint32_t)(c->edi)); /* mov dword ptr [eax + esi], edi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x84u))); /* mov esi, dword ptr [ecx + 0x84] */
    c->edi = (uint32_t)(R32((uint32_t)(c->edx + 0x3cu))); /* mov edi, dword ptr [edx + 0x3c] */
    W32((uint32_t)(c->esi + c->eax + 0x3cu), (uint32_t)(c->edi)); /* mov dword ptr [esi + eax + 0x3c], edi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x84u))); /* mov esi, dword ptr [ecx + 0x84] */
    c->edi = (uint32_t)(R32((uint32_t)(c->edx + 0x40u))); /* mov edi, dword ptr [edx + 0x40] */
    W32((uint32_t)(c->esi + c->eax + 0x40u), (uint32_t)(c->edi)); /* mov dword ptr [esi + eax + 0x40], edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ecx + 0x84u))); /* mov edi, dword ptr [ecx + 0x84] */
    c->esi = (uint32_t)((uint32_t)(c->edx + 0x24u)); /* lea esi, [edx + 0x24] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ebx, dword ptr [esi] */
    c->edi = (uint32_t)((uint32_t)(c->edi + c->eax + 0x24u)); /* lea edi, [edi + eax + 0x24] */
    W32((uint32_t)(c->edi), (uint32_t)(c->ebx)); /* mov dword ptr [edi], ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ebx, dword ptr [esi + 4] */
    W32((uint32_t)(c->edi + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [edi + 4], ebx */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov esi, dword ptr [esi + 8] */
    W32((uint32_t)(c->edi + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [edi + 8], esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x84u))); /* mov esi, dword ptr [ecx + 0x84] */
    c->edi = (uint32_t)(R32((uint32_t)(c->edx + 0x20u))); /* mov edi, dword ptr [edx + 0x20] */
    W32((uint32_t)(c->esi + c->eax + 0x20u), (uint32_t)(c->edi)); /* mov dword ptr [esi + eax + 0x20], edi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x84u))); /* mov ecx, dword ptr [ecx + 0x84] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov edx, dword ptr [edx + 4] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->ecx + c->eax + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + eax + 4], edx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 12; return; /* ret 8 */
}

void f_006e3380(CPU *c) { /* PTR_006e3380 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x38u))); /* mov edx, dword ptr [ecx + 0x38] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    (void)sub32(c, c->eax, c->edx); /* cmp eax, edx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if ((c->sf == c->of)) goto L_006e33b2; /* jge 0x6e33b2 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x70u))); /* mov esi, dword ptr [ecx + 0x70] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x7cu))); /* mov ecx, dword ptr [ecx + 0x7c] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edi, dword ptr [esp + 0x14] */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->eax * 4)); /* lea ecx, [ecx + eax*4] */
    ; /* nop  */
    c->esp = (uint32_t)((uint32_t)(c->esp)); /* lea esp, [esp] */
L_006e33a0:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov ebx, dword ptr [ecx] */
    c->ebx = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->esi + c->ebx))); /* movsx ebx, byte ptr [esi + ebx] */
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    if (c->zf) goto L_006e33b5; /* je 0x6e33b5 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    (void)sub32(c, c->eax, c->edx); /* cmp eax, edx */
    if ((c->sf != c->of)) goto L_006e33a0; /* jl 0x6e33a0 */
L_006e33b2:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
L_006e33b5:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 12; return; /* ret 8 */
}

void f_006e33c0(CPU *c) { /* PTR_006e33c0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)(uint32_t)0x54u; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, eax, 0x54 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x84u))); /* mov esi, dword ptr [ecx + 0x84] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edi, dword ptr [esp + 0x10] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->ecx = (uint32_t)((uint32_t)0x15u); /* mov ecx, 0x15 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 12; return; /* ret 8 */
}

void f_006e33f0(CPU *c) { /* DMAInterface */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    W32((uint32_t)(0x7776f4u), (uint32_t)(c->eax)); /* mov dword ptr [0x100976f4], eax */
    W32((uint32_t)(0x7736d4u), (uint32_t)(c->eax)); /* mov dword ptr [0x100936d4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov eax, dword ptr [eax + 4] */
    W32((uint32_t)(0x7776d8u), (uint32_t)(c->eax)); /* mov dword ptr [0x100976d8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(0x777810u))); /* mov eax, dword ptr [0x10097810] */
    W32((uint32_t)(0x7736d0u), (uint32_t)(c->ecx)); /* mov dword ptr [0x100936d0], ecx */
    c->esp += 4; return; /* ret  */
}

void f_006e3420(CPU *c) { /* FUN_10003420 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(0x7776f4u))); /* mov ecx, dword ptr [0x100976f4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x006e3430u); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
    c->esp += 4; return; /* ret  */
}

void f_006e3440(CPU *c) { /* FUN_10003440 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x7776f4u))); /* mov ecx, dword ptr [0x100976f4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4u)); PUSH32(c, 0x006e345au); call_indirect(c, t_); } /* call dword ptr [eax + 4] */
    c->esp += 4; return; /* ret  */
}

void f_006e3460(CPU *c) { /* PTR_006e3460 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x777810u; PUSH32(c, v_); } /* push 0x10097810 */
    c->ecx = (uint32_t)((uint32_t)0x7776f8u); /* mov ecx, 0x100976f8 */
    PUSH32(c, 0x006e346fu); f_006e3480(c); /* call 0x6e3480 */
    { uint32_t v_ = 0x6e3620u; PUSH32(c, v_); } /* push 0x10003620 */
    PUSH32(c, 0x006e3479u); f_006e4713(c); /* call 0x6e4713 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_006e3480(CPU *c) { /* FUN_10003480 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->edx)); /* mov dword ptr [eax + 0xc], edx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 8], edx */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x6ed1e0u)); /* mov dword ptr [eax], 0x1000d1e0 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov esi, dword ptr [ecx] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [eax + 4], esi */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    W32((uint32_t)(c->eax + 0x10u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 0x10], edx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_006e34b0(CPU *c) { /* PTR_006e34b0 */
    PREEMPT_POLL(c);
    { uint32_t a_ = (uint32_t)(c->ecx + 0xcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ecx + 0xc] */
    c->esp += 4; return; /* ret  */
}

void f_006e34c0(CPU *c) { /* PTR_006e34c0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov eax, dword ptr [ecx + 0xc] */
    c->esp += 4; return; /* ret  */
}

void f_006e34d0(CPU *c) { /* PTR_006e34d0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x6ee0c0u); /* mov eax, 0x1000e0c0 */
    c->esp += 4; return; /* ret  */
}

void f_006e34e0(CPU *c) { /* FUN_100034e0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006e3531; /* jne 0x6e3531 */
    c->ecx = (uint32_t)(R32((uint32_t)(0x7776f4u))); /* mov ecx, dword ptr [0x100976f4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = 0x5u; PUSH32(c, v_); } /* push 5 */
    { uint32_t v_ = 0x6ee0ccu; PUSH32(c, v_); } /* push 0x1000e0cc */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4u)); PUSH32(c, 0x006e34feu); call_indirect(c, t_); } /* call dword ptr [eax + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e352c; /* je 0x6e352c */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x6ed200u)); /* mov dword ptr [eax], 0x1000d200 */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->ebx = (uint32_t)((uint32_t)(c->ebx)); /* lea ebx, [ebx] */
L_006e3510:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0x777924u))); /* mov dl, byte ptr [ecx + 0x10097924] */
    W8((uint32_t)(c->ecx + 0x777710u), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [ecx + 0x10097710], dl */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (!c->zf) goto L_006e3510; /* jne 0x6e3510 */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x10], eax */
    { uint32_t a_ = (uint32_t)(c->esi + 0xcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [esi + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_006e352c:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x10], eax */
L_006e3531:;
    { uint32_t a_ = (uint32_t)(c->esi + 0xcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [esi + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_006e3540(CPU *c) { /* PTR_006e3540 */
    PREEMPT_POLL(c);
    c->esp += 4; return; /* ret  */
}

void f_006e3550(CPU *c) { /* PTR_006e3550 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    c->esp += 8; return; /* ret 4 */
}

void f_006e3560(CPU *c) { /* FUN_10003560 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, c->ecx, c->edi); /* cmp ecx, edi */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0xc], edi */
    if (c->zf) goto L_006e3576; /* je 0x6e3576 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t t_ = R32((uint32_t)(c->eax)); PUSH32(c, 0x006e3576u); call_indirect(c, t_); } /* call dword ptr [eax] */
L_006e3576:;
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0x10], edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_006e3580(CPU *c) { /* FUN_10003580 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x006e3588u); f_006e35b0(c); /* call 0x6e35b0 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_006e359b; /* je 0x6e359b */
    c->ecx = (uint32_t)(R32((uint32_t)(0x7776f4u))); /* mov ecx, dword ptr [0x100976f4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x006e359bu); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
L_006e359b:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_006e35b0(CPU *c) { /* FUN_100035b0 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx), (uint32_t)((uint32_t)0x6ed23cu)); /* mov dword ptr [ecx], 0x1000d23c */
    c->esp += 4; return; /* ret  */
}

void f_006e35c0(CPU *c) { /* PTR_006e35c0 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    c->esp += 4; return; /* ret  */
}

void f_006e35d0(CPU *c) { /* PTR_006e35d0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_006e35e0(CPU *c) { /* PTR_006e35e0 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx + 0xcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ecx + 0xc], 0 */
    c->esp += 4; return; /* ret  */
}

void f_006e35f0(CPU *c) { /* PTR_006e35f0 */
    PREEMPT_POLL(c);
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x4u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 4], 1 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x6ed23cu)); /* mov dword ptr [esi], 0x1000d23c */
    if (c->zf) goto L_006e360c; /* je 0x6e360c */
    c->ecx = (uint32_t)(R32((uint32_t)(0x7776f4u))); /* mov ecx, dword ptr [0x100976f4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x006e360cu); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
L_006e360c:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_006e3620(CPU *c) { /* PTR_006e3620 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)0x7776f8u); /* mov ecx, 0x100976f8 */
    { f_006e35b0(c); return; } /* jmp 0x6e35b0 */
}

void f_006e3630(CPU *c) { /* PTR_006e3630 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)0x7776e0u); /* mov ecx, 0x100976e0 */
    PUSH32(c, 0x006e363au); f_006e3660(c); /* call 0x6e3660 */
    { uint32_t v_ = 0x6e3650u; PUSH32(c, v_); } /* push 0x10003650 */
    PUSH32(c, 0x006e3644u); f_006e4713(c); /* call 0x6e4713 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_006e3650(CPU *c) { /* PTR_006e3650 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)0x7776e0u); /* mov ecx, 0x100976e0 */
    { f_006e3a90(c); return; } /* jmp 0x6e3a90 */
}

void f_006e3660(CPU *c) { /* FUN_10003660 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x6ed260u)); /* mov dword ptr [eax], 0x1000d260 */
    c->esp += 4; return; /* ret  */
}

void f_006e3670(CPU *c) { /* FUN_10003670 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x006e3678u); f_006e3a90(c); /* call 0x6e3a90 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_006e368b; /* je 0x6e368b */
    c->ecx = (uint32_t)(R32((uint32_t)(0x7776f4u))); /* mov ecx, dword ptr [0x100976f4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x006e368bu); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
L_006e368b:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_006e36a0(CPU *c) { /* FUN_100036a0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x006e36a8u); f_006e36d0(c); /* call 0x6e36d0 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_006e36bb; /* je 0x6e36bb */
    c->ecx = (uint32_t)(R32((uint32_t)(0x7776f4u))); /* mov ecx, dword ptr [0x100976f4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x006e36bbu); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
L_006e36bb:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_006e36d0(CPU *c) { /* FUN_100036d0 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx), (uint32_t)((uint32_t)0x6ed2bcu)); /* mov dword ptr [ecx], 0x1000d2bc */
    c->esp += 4; return; /* ret  */
}

void f_006e36e0(CPU *c) { /* PTR_006e36e0 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    c->esp += 4; return; /* ret  */
}

void f_006e36f0(CPU *c) { /* PTR_006e36f0 */
    PREEMPT_POLL(c);
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x4u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 4], 1 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x6ed2bcu)); /* mov dword ptr [esi], 0x1000d2bc */
    if (c->zf) goto L_006e370c; /* je 0x6e370c */
    c->ecx = (uint32_t)(R32((uint32_t)(0x7776f4u))); /* mov ecx, dword ptr [0x100976f4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x006e370cu); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
L_006e370c:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_006e3720(CPU *c) { /* PTR_006e3720 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x777710u); /* mov eax, 0x10097710 */
    c->esp += 4; return; /* ret  */
}

void f_006e3730(CPU *c) { /* PTR_006e3730 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->edx = (uint32_t)((uint32_t)0x777710u); /* mov edx, 0x10097710 */
    c->edx = (uint32_t)(sub32(c, c->edx, c->eax)); /* sub edx, eax */
    ; /* nop  */
    c->esp = (uint32_t)((uint32_t)(c->esp)); /* lea esp, [esp] */
L_006e3740:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    W8((uint32_t)(c->edx + c->eax), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [edx + eax], cl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_006e3740; /* jne 0x6e3740 */
    c->esp += 8; return; /* ret 4 */
}

void f_006e3750(CPU *c) { /* PTR_006e3750 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->edx = (uint32_t)((uint32_t)0x777818u); /* mov edx, 0x10097818 */
    c->edx = (uint32_t)(sub32(c, c->edx, c->eax)); /* sub edx, eax */
    ; /* nop  */
    c->esp = (uint32_t)((uint32_t)(c->esp)); /* lea esp, [esp] */
L_006e3760:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    W8((uint32_t)(c->edx + c->eax), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [edx + eax], cl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_006e3760; /* jne 0x6e3760 */
    c->esp += 8; return; /* ret 4 */
}

void f_006e3770(CPU *c) { /* PTR_006e3770 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x46ca96e8u)); /* add eax, 0x565c96e8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov esi, dword ptr [ecx] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    W32((uint32_t)(c->edx), (uint32_t)(c->esi)); /* mov dword ptr [edx], esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov esi, dword ptr [ecx + 4] */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [edx + 4], esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov esi, dword ptr [ecx + 8] */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [edx + 8], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov ecx, dword ptr [ecx + 0xc] */
    W32((uint32_t)(c->edx + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [edx + 0xc], ecx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 12; return; /* ret 8 */
}

void f_006e37a0(CPU *c) { /* PTR_006e37a0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    W32((uint32_t)(0x777918u), (uint32_t)(c->eax)); /* mov dword ptr [0x10097918], eax */
    c->esp += 8; return; /* ret 4 */
}

void f_006e37b0(CPU *c) { /* FUN_100037b0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(0x7776f4u))); /* mov ecx, dword ptr [0x100976f4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = 0x6ee0b4u; PUSH32(c, v_); } /* push 0x1000e0b4 */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4cu)); PUSH32(c, 0x006e37c3u); call_indirect(c, t_); } /* call dword ptr [eax + 0x4c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 4], eax */
    if (!c->zf) goto L_006e37e2; /* jne 0x6e37e2 */
    c->eax = (uint32_t)(R32((uint32_t)(0x7776f4u))); /* mov eax, dword ptr [0x100976f4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x6ee0b4u; PUSH32(c, v_); } /* push 0x1000e0b4 */
    { uint32_t v_ = 0x6ee108u; PUSH32(c, v_); } /* push 0x1000e108 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x006e37dfu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_006e37e2:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov edx, dword ptr [esi + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x7736d4u))); /* mov ecx, dword ptr [0x100936d4] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    W32((uint32_t)(0x7776e4u), (uint32_t)(c->edx)); /* mov dword ptr [0x100976e4], edx */
    W32((uint32_t)(0x7776e8u), (uint32_t)(c->eax)); /* mov dword ptr [0x100976e8], eax */
    W32((uint32_t)(0x7776ecu), (uint32_t)(c->eax)); /* mov dword ptr [0x100976ec], eax */
    W32((uint32_t)(0x7776f0u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [0x100976f0], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov eax, dword ptr [ecx + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax))); /* mov esi, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x110u)); PUSH32(c, 0x006e3815u); call_indirect(c, t_); } /* call dword ptr [edx + 0x110] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(0x7736d4u))); /* mov eax, dword ptr [0x100936d4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    { uint32_t t_ = R32((uint32_t)(c->esi + 0x58u)); PUSH32(c, 0x006e3821u); call_indirect(c, t_); } /* call dword ptr [esi + 0x58] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_006e384b; /* je 0x6e384b */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x6ee0f8u; PUSH32(c, v_); } /* push 0x1000e0f8 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x20u)); PUSH32(c, 0x006e3837u); call_indirect(c, t_); } /* call dword ptr [edx + 0x20] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sbb8(c, ((uint8_t)c->eax), ((uint8_t)c->eax))); /* sbb al, al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(inc8(c, ((uint8_t)c->eax))); /* inc al */
    W8((uint32_t)(0x77791cu), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [0x1009791c], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax)); PUSH32(c, 0x006e384bu); call_indirect(c, t_); } /* call dword ptr [eax] */
L_006e384b:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_006e3850(CPU *c) { /* PTR_006e3850 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    c->esp += 8; return; /* ret 4 */
}

void f_006e3860(CPU *c) { /* FUN_10003860 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x6ec430u; PUSH32(c, v_); } /* push 0x1000c430 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x23cu)); /* sub esp, 0x23c */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x10], esp */
    if (c->zf) goto L_006e38ba; /* je 0x6e38ba */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x6ee1b4u; PUSH32(c, v_); } /* push 0x1000e1b4 */
    { uint32_t v_ = 0x7735d0u; PUSH32(c, v_); } /* push 0x100935d0 */
    PUSH32(c, 0x006e38a4u); f_006e4837(c); /* call 0x6e4837 */
    { uint32_t v_ = 0x5cu; PUSH32(c, v_); } /* push 0x5c */
    { uint32_t v_ = 0x7735d0u; PUSH32(c, v_); } /* push 0x100935d0 */
    PUSH32(c, 0x006e38b0u); f_006e4810(c); /* call 0x6e4810 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (c->zf) goto L_006e38ba; /* je 0x6e38ba */
    W8((uint32_t)(c->eax), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [eax], 0 */
L_006e38ba:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x77791cu))); /* mov al, byte ptr [0x1009791c] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_006e38ed; /* je 0x6e38ed */
    (void)sub32(c, R32((uint32_t)(0x777920u)), c->edi); /* cmp dword ptr [0x10097920], edi */
    W32((uint32_t)(0x7776dcu), (uint32_t)(c->edi)); /* mov dword ptr [0x100976dc], edi */
    if (!c->zf) goto L_006e38d8; /* jne 0x6e38d8 */
    { uint32_t v_ = 0x6ee1b0u; PUSH32(c, v_); } /* push 0x1000e1b0 */
    goto L_006e38dd; /* jmp 0x6e38dd */
L_006e38d8:;
    { uint32_t v_ = 0x6ee1acu; PUSH32(c, v_); } /* push 0x1000e1ac */
L_006e38dd:;
    { uint32_t v_ = 0x6ee1a0u; PUSH32(c, v_); } /* push 0x1000e1a0 */
    PUSH32(c, 0x006e38e7u); f_006e47fc(c); /* call 0x6e47fc */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 8], eax */
L_006e38ed:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffeb8u)); /* lea ecx, [ebp - 0x148] */
    { uint32_t v_ = 0x6ee188u; PUSH32(c, v_); } /* push 0x1000e188 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 4], edi */
    PUSH32(c, 0x006e3902u); f_006e4837(c); /* call 0x6e4837 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (c->zf) goto L_006e395b; /* je 0x6e395b */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0xffffffffu))); /* or ecx, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edi = (uint32_t)(c->esi); /* mov edi, esi */
    while (c->ecx) { (void)sub8(c, ((uint8_t)c->eax), R8(c->edi)); c->edi += (c->df ? -1 : 1); c->ecx--; if (c->zf) break; } /* repne scasb al, byte ptr es:[edi] */
    c->ecx = (uint32_t)((uint32_t)~c->ecx); /* not ecx */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_006e395b; /* je 0x6e395b */
    (void)sub8(c, R8((uint32_t)(c->esi)), (uint8_t)0x5cu); /* cmp byte ptr [esi], 0x5c */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    if (!c->zf) goto L_006e3921; /* jne 0x6e3921 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x1u)); /* lea eax, [esi + 1] */
L_006e3921:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x5cu); /* cmp byte ptr [eax], 0x5c */
    if (!c->zf) goto L_006e3927; /* jne 0x6e3927 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
L_006e3927:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->edx = (uint32_t)((uint32_t)(c->ebp + 0xfffffdb8u)); /* lea edx, [ebp - 0x248] */
    { uint32_t v_ = 0x6ee16cu; PUSH32(c, v_); } /* push 0x1000e16c */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x006e393au); f_006e4837(c); /* call 0x6e4837 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x7776e0u; PUSH32(c, v_); } /* push 0x100976e0 */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffdb8u)); /* lea ecx, [ebp - 0x248] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->edx = (uint32_t)((uint32_t)(c->ebp + 0xfffffeb8u)); /* lea edx, [ebp - 0x148] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x006e3956u); f_006e1cf0(c); /* call 0x6e1cf0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    goto L_006e3975; /* jmp 0x6e3975 */
L_006e395b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x7776e0u; PUSH32(c, v_); } /* push 0x100976e0 */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffeb8u)); /* lea ecx, [ebp - 0x148] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x006e3972u); f_006e1cf0(c); /* call 0x6e1cf0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_006e3975:;
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x77791cu))); /* mov al, byte ptr [0x1009791c] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [ebp - 4], 0xffffffff */
    if (c->zf) goto L_006e39e5; /* je 0x6e39e5 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffb8u)); /* lea eax, [ebp - 0x48] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x4u)); PUSH32(c, 0x006e3992u); call_indirect(c, t_); } /* call dword ptr [edx + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc8u))); /* mov eax, dword ptr [ebp - 0x38] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x7776dcu))); /* mov ecx, dword ptr [0x100976dc] */
    c->edi = (uint32_t)(R32((uint32_t)(0x777920u))); /* mov edi, dword ptr [0x10097920] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea eax, [eax + eax*2] */
    c->eax = (uint32_t)(shl32(c, c->eax, 1)); /* shl eax, 1 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->edx = (uint32_t)((uint32_t)(c->eax + c->ecx)); /* lea edx, [eax + ecx] */
    c->edi = (uint32_t)(add32(c, c->edi, c->edx)); /* add edi, edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc4u))); /* mov edx, dword ptr [ebp - 0x3c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffb8u))); /* mov edx, dword ptr [ebp - 0x48] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    W32((uint32_t)(0x777920u), (uint32_t)(c->edi)); /* mov dword ptr [0x10097920], edi */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(0x777920u))); /* fild dword ptr [0x10097920] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x6ed2d8u))); /* fmul dword ptr [0x1000d2d8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    { uint32_t v_ = 0x6ee134u; PUSH32(c, v_); } /* push 0x1000e134 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006e39dcu); f_006e47aa(c); /* call 0x6e47aa */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006e39e2u); f_006e4754(c); /* call 0x6e4754 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x28u)); /* add esp, 0x28 */
L_006e39e5:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 20; return; /* ret 0x10 */
}

void f_006e39fa(CPU *c) { /* Catch@100039fa */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(0x7776f4u))); /* mov eax, dword ptr [0x100976f4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)((uint32_t)(c->ebp + 0xfffffeb8u)); /* lea edx, [ebp - 0x148] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x6ee12cu; PUSH32(c, v_); } /* push 0x1000e12c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x006e3a15u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->eax = (uint32_t)((uint32_t)0x6e3a3eu); /* mov eax, 0x10003a3e */
    c->esp += 4; return; /* ret  */
}

void f_006e3a1e(CPU *c) { /* Catch@10003a1e */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x7776f4u))); /* mov eax, dword ptr [0x100976f4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->edx = (uint32_t)((uint32_t)(c->ebp + 0xfffffeb8u)); /* lea edx, [ebp - 0x148] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x6ee118u; PUSH32(c, v_); } /* push 0x1000e118 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x006e3a35u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->eax = (uint32_t)((uint32_t)0x6e3a3eu); /* mov eax, 0x10003a3e */
    c->esp += 4; return; /* ret  */
}

void f_006e3a3e(CPU *c) { /* PTR_006e3a3e */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 20; return; /* ret 0x10 */
}

void f_006e3a60(CPU *c) { /* PTR_006e3a60 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 8; return; /* ret 4 */
}

void f_006e3a70(CPU *c) { /* PTR_006e3a70 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_006e3a85; /* je 0x6e3a85 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [esp + 4], 1 */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x6cu)); switch (t_) {  default: jump_indirect(c, t_, 0x006e3a82u); return; } } /* jmp dword ptr [eax + 0x6c] */
L_006e3a85:;
    c->esp += 8; return; /* ret 4 */
}

void f_006e3a90(CPU *c) { /* FUN_10003a90 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx), (uint32_t)((uint32_t)0x6ed2e0u)); /* mov dword ptr [ecx], 0x1000d2e0 */
    c->esp += 4; return; /* ret  */
}

void f_006e3aa0(CPU *c) { /* PTR_006e3aa0 */
    PREEMPT_POLL(c);
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x4u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 4], 1 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x6ed2e0u)); /* mov dword ptr [esi], 0x1000d2e0 */
    if (c->zf) goto L_006e3abc; /* je 0x6e3abc */
    c->ecx = (uint32_t)(R32((uint32_t)(0x7776f4u))); /* mov ecx, dword ptr [0x100976f4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x006e3abcu); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
L_006e3abc:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_006e3ad0(CPU *c) { /* PTR_006e3ad0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ecx, dword ptr [ecx + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_006e3adf; /* je 0x6e3adf */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x1ecu)); PUSH32(c, 0x006e3adfu); call_indirect(c, t_); } /* call dword ptr [eax + 0x1ec] */
L_006e3adf:;
    c->ecx = (uint32_t)(R32((uint32_t)(0x7776f4u))); /* mov ecx, dword ptr [0x100976f4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ecx, dword ptr [ecx + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov esi, dword ptr [esp + 0xc] */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x80000000u; PUSH32(c, v_); } /* push 0x80000000 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x4u)); PUSH32(c, 0x006e3afdu); call_indirect(c, t_); } /* call dword ptr [edx + 4] */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    (void)sub32(c, c->ebx, (uint32_t)0xffffffffu); /* cmp ebx, -1 */
    if (!c->zf) goto L_006e3b3e; /* jne 0x6e3b3e */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->eax))); /* or ecx, eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edi = (uint32_t)(c->esi); /* mov edi, esi */
    while (c->ecx) { (void)sub8(c, ((uint8_t)c->eax), R8(c->edi)); c->edi += (c->df ? -1 : 1); c->ecx--; if (c->zf) break; } /* repne scasb al, byte ptr es:[edi] */
    c->ecx = (uint32_t)((uint32_t)~c->ecx); /* not ecx */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->esi + 0xfffffffcu)); /* lea eax, [ecx + esi - 4] */
    { uint32_t v_ = 0x6ee1d8u; PUSH32(c, v_); } /* push 0x1000e1d8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e3b1fu); f_006ec340(c); /* call 0x6ec340 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    if (c->zf) goto L_006e3b3e; /* je 0x6e3b3e */
    { uint32_t v_ = 0x6ed8fcu; PUSH32(c, v_); } /* push 0x1000d8fc */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x10u)); /* lea ecx, [esp + 0x10] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0x6ee1bcu)); /* mov dword ptr [esp + 0x14], 0x1000e1bc */
    PUSH32(c, 0x006e3b3eu); f_006e4663(c); /* call 0x6e4663 */
L_006e3b3e:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
}

void f_006e3b50(CPU *c) { /* PTR_006e3b50 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (!c->zf) goto L_006e3b5e; /* jne 0x6e3b5e */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 8; return; /* ret 4 */
L_006e3b5e:;
    c->ecx = (uint32_t)(R32((uint32_t)(0x7776f4u))); /* mov ecx, dword ptr [0x100976f4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ecx, dword ptr [ecx + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)((uint32_t)(c->esp + 0x8u)); /* lea esi, [esp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x38u)); PUSH32(c, 0x006e3b73u); call_indirect(c, t_); } /* call dword ptr [edx + 0x38] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_006e3b80(CPU *c) { /* PTR_006e3b80 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x7776f4u))); /* mov eax, dword ptr [0x100976f4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x18u)); PUSH32(c, 0x006e3b9eu); call_indirect(c, t_); } /* call dword ptr [edx + 0x18] */
    c->esp += 16; return; /* ret 0xc */
}

void f_006e3bb0(CPU *c) { /* PTR_006e3bb0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x7776f4u))); /* mov eax, dword ptr [0x100976f4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); switch (t_) {  default: jump_indirect(c, t_, 0x006e3bbau); return; } } /* jmp dword ptr [edx + 8] */
}

void f_006e3bc0(CPU *c) { /* PTR_006e3bc0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(0x7776f4u))); /* mov ecx, dword ptr [0x100976f4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = 0xcdu; PUSH32(c, v_); } /* push 0xcd */
    { uint32_t v_ = 0x6ee0ccu; PUSH32(c, v_); } /* push 0x1000e0cc */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4u)); PUSH32(c, 0x006e3bdau); call_indirect(c, t_); } /* call dword ptr [eax + 4] */
    c->esp += 8; return; /* ret 4 */
}

void f_006e3be0(CPU *c) { /* PTR_006e3be0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e3bf7; /* je 0x6e3bf7 */
    c->ecx = (uint32_t)(R32((uint32_t)(0x7776f4u))); /* mov ecx, dword ptr [0x100976f4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 4], eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); switch (t_) {  default: jump_indirect(c, t_, 0x006e3bf4u); return; } } /* jmp dword ptr [edx + 8] */
L_006e3bf7:;
    c->esp += 8; return; /* ret 4 */
}

void f_006e3c00(CPU *c) { /* PTR_006e3c00 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x100u)); /* sub esp, 0x100 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10cu))); /* mov edi, dword ptr [esp + 0x10c] */
    { uint32_t v_ = 0x6ee1f0u; PUSH32(c, v_); } /* push 0x1000e1f0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    PUSH32(c, 0x006e3c1cu); f_006ec340(c); /* call 0x6ec340 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006e3c3d; /* jne 0x6e3c3d */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x7735d0u; PUSH32(c, v_); } /* push 0x100935d0 */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x10u)); /* lea eax, [esp + 0x10] */
    { uint32_t v_ = 0x6ee1e0u; PUSH32(c, v_); } /* push 0x1000e1e0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e3c38u); f_006e4837(c); /* call 0x6e4837 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    goto L_006e3c7e; /* jmp 0x6e3c7e */
L_006e3c3d:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    ; /* nop  */
L_006e3c40:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x777710u))); /* mov cl, byte ptr [eax + 0x10097710] */
    W8((uint32_t)(c->esp + c->eax + 0x8u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esp + eax + 8], cl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_006e3c40; /* jne 0x6e3c40 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (uint32_t)((uint32_t)0xffffffffu); /* mov ecx, 0xffffffff */
    while (c->ecx) { (void)sub8(c, ((uint8_t)c->eax), R8(c->edi)); c->edi += (c->df ? -1 : 1); c->ecx--; if (c->zf) break; } /* repne scasb al, byte ptr es:[edi] */
    c->ecx = (uint32_t)((uint32_t)~c->ecx); /* not ecx */
    c->edi = (uint32_t)(sub32(c, c->edi, c->ecx)); /* sub edi, ecx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->ecx); /* mov ebp, ecx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0xffffffffu))); /* or ecx, 0xffffffff */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->edi); /* mov esi, edi */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x10u)); /* lea edx, [esp + 0x10] */
    c->edi = (uint32_t)(c->edx); /* mov edi, edx */
    while (c->ecx) { (void)sub8(c, ((uint8_t)c->eax), R8(c->edi)); c->edi += (c->df ? -1 : 1); c->ecx--; if (c->zf) break; } /* repne scasb al, byte ptr es:[edi] */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u))); /* and ecx, 3 */
    while (c->ecx) { W8(c->edi, R8(c->esi)); c->esi += (c->df ? -1 : 1); c->edi += (c->df ? -1 : 1); c->ecx--; } /* rep movsb byte ptr es:[edi], byte ptr [esi] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
L_006e3c7e:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov ecx, dword ptr [ebx + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_006e3ca5; /* je 0x6e3ca5 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x1ecu)); PUSH32(c, 0x006e3c8du); call_indirect(c, t_); } /* call dword ptr [eax + 0x1ec] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov ecx, dword ptr [ebx + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x8u)); /* lea eax, [esp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x78u)); PUSH32(c, 0x006e3c9au); call_indirect(c, t_); } /* call dword ptr [edx + 0x78] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x100u)); /* add esp, 0x100 */
    c->esp += 8; return; /* ret 4 */
L_006e3ca5:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x100u)); /* add esp, 0x100 */
    c->esp += 8; return; /* ret 4 */
}

void f_006e3cc0(CPU *c) { /* PTR_006e3cc0 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x44u)); /* sub esp, 0x44 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x50u))); /* mov edi, dword ptr [esp + 0x50] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + 0x20u))); /* mov edx, dword ptr [edi + 0x20] */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x7cu)); PUSH32(c, 0x006e3cd9u); call_indirect(c, t_); } /* call dword ptr [eax + 0x7c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x14u))); /* mov eax, dword ptr [edi + 0x14] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    if (c->zf) goto L_006e3d2f; /* je 0x6e3d2f */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x134u)); PUSH32(c, 0x006e3cf1u); call_indirect(c, t_); } /* call dword ptr [eax + 0x134] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x24u))); /* mov eax, dword ptr [edi + 0x24] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x7cu)); PUSH32(c, 0x006e3cffu); call_indirect(c, t_); } /* call dword ptr [edx + 0x7c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x134u)); PUSH32(c, 0x006e3d10u); call_indirect(c, t_); } /* call dword ptr [edx + 0x134] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x7cu)); PUSH32(c, 0x006e3d1cu); call_indirect(c, t_); } /* call dword ptr [eax + 0x7c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = 0x5u; PUSH32(c, v_); } /* push 5 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x134u)); PUSH32(c, 0x006e3d2du); call_indirect(c, t_); } /* call dword ptr [edx + 0x134] */
    goto L_006e3d5d; /* jmp 0x6e3d5d */
L_006e3d2f:;
    { uint32_t v_ = 0x5u; PUSH32(c, v_); } /* push 5 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x134u)); PUSH32(c, 0x006e3d3bu); call_indirect(c, t_); } /* call dword ptr [eax + 0x134] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x134u)); PUSH32(c, 0x006e3d4cu); call_indirect(c, t_); } /* call dword ptr [edx + 0x134] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x134u)); PUSH32(c, 0x006e3d5du); call_indirect(c, t_); } /* call dword ptr [eax + 0x134] */
L_006e3d5d:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x134u)); PUSH32(c, 0x006e3d6eu); call_indirect(c, t_); } /* call dword ptr [edx + 0x134] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x134u)); PUSH32(c, 0x006e3d7fu); call_indirect(c, t_); } /* call dword ptr [eax + 0x134] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x134u)); PUSH32(c, 0x006e3d90u); call_indirect(c, t_); } /* call dword ptr [edx + 0x134] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x134u)); PUSH32(c, 0x006e3da1u); call_indirect(c, t_); } /* call dword ptr [eax + 0x134] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x134u)); PUSH32(c, 0x006e3db2u); call_indirect(c, t_); } /* call dword ptr [edx + 0x134] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x134u)); PUSH32(c, 0x006e3dc3u); call_indirect(c, t_); } /* call dword ptr [eax + 0x134] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x1bu; PUSH32(c, v_); } /* push 0x1b */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x12cu)); PUSH32(c, 0x006e3dd2u); call_indirect(c, t_); } /* call dword ptr [edx + 0x12c] */
    FPUSH(c, (double)RF32((uint32_t)(c->edi))); /* fld dword ptr [edi] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); /* fst dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    WF32((uint32_t)(c->esp + 0xcu), (float)ST(0)); /* fst dword ptr [esp + 0xc] */
    WF32((uint32_t)(c->esp + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 8] */
    W32((uint32_t)(c->esp + 0x48u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x48], eax */
    FPUSH(c, (double)RF32((uint32_t)(c->edi + 0x4u))); /* fld dword ptr [edi + 4] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x8u)); /* lea eax, [esp + 8] */
    WF32((uint32_t)(c->esp + 0x30u), (float)ST(0)); /* fst dword ptr [esp + 0x30] */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [esp + 0x14], 0x3f800000 */
    WF32((uint32_t)(c->esp + 0x2cu), (float)ST(0)); /* fst dword ptr [esp + 0x2c] */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x24], 0 */
    WF32((uint32_t)(c->esp + 0x28u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x28] */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x20], 0 */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x1c], 0 */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x18], 0 */
    W32((uint32_t)(c->esp + 0x34u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [esp + 0x34], 0x3f800000 */
    W32((uint32_t)(c->esp + 0x44u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x44], 0 */
    W32((uint32_t)(c->esp + 0x40u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x40], 0 */
    W32((uint32_t)(c->esp + 0x3cu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x3c], 0 */
    W32((uint32_t)(c->esp + 0x38u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x38], 0 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x40u)); PUSH32(c, 0x006e3e53u); call_indirect(c, t_); } /* call dword ptr [edx + 0x40] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x44u)); /* add esp, 0x44 */
    c->esp += 8; return; /* ret 4 */
}

void f_006e3e60(CPU *c) { /* PTR_006e3e60 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ecx, dword ptr [ecx + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_006e3e6f; /* je 0x6e3e6f */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x80u)); switch (t_) {  default: jump_indirect(c, t_, 0x006e3e69u); return; } } /* jmp dword ptr [eax + 0x80] */
L_006e3e6f:;
    c->esp += 8; return; /* ret 4 */
}

void f_006e3e80(CPU *c) { /* PTR_006e3e80 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x10u)); /* sub esp, 0x10 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov ebx, dword ptr [esp + 0x1c] */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    if (!c->zf) goto L_006e3e98; /* jne 0x6e3e98 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 12; return; /* ret 8 */
L_006e3e98:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov eax, dword ptr [ecx + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006e3eaa; /* jne 0x6e3eaa */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 12; return; /* ret 8 */
L_006e3eaa:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov eax, dword ptr [esp + 0x1c] */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u))); /* and edx, 3 */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)((uint32_t)0x100u)); /* mov dword ptr [esp + 8], 0x100 */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)((uint32_t)0x200u)); /* mov dword ptr [esp + 0xc], 0x200 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0x300u)); /* mov dword ptr [esp + 0x10], 0x300 */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0x400u)); /* mov dword ptr [esp + 0x14], 0x400 */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + c->edx * 4 + 0x8u))); /* mov ebp, dword ptr [esp + edx*4 + 8] */
    c->ebp = (uint32_t)(logic32(c, (uint32_t)(c->ebp | (uint32_t)0x52u))); /* or ebp, 0x52 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x4u)); /* test al, 4 */
    if (c->zf) goto L_006e3f48; /* je 0x6e3f48 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    c->eax = (uint32_t)((uint32_t)0x7736d8u); /* mov eax, 0x100936d8 */
L_006e3ee7:;
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0x0u); /* cmp dword ptr [eax], 0 */
    if (c->zf) goto L_006e3ef7; /* je 0x6e3ef7 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x10u)); /* add eax, 0x10 */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->eax, (uint32_t)0x7776d8u); /* cmp eax, 0x100976d8 */
    if ((c->sf != c->of)) goto L_006e3ee7; /* jl 0x6e3ee7 */
L_006e3ef7:;
    c->ecx = (uint32_t)(R32((uint32_t)(0x7776f4u))); /* mov ecx, dword ptr [0x100976f4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = 0x161u; PUSH32(c, v_); } /* push 0x161 */
    { uint32_t v_ = 0x6ee0ccu; PUSH32(c, v_); } /* push 0x1000e0cc */
    c->esi = (uint32_t)(c->edi); /* mov esi, edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->esi = (uint32_t)(shl32(c, c->esi, 4)); /* shl esi, 4 */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4u)); PUSH32(c, 0x006e3f12u); call_indirect(c, t_); } /* call dword ptr [eax + 4] */
    W32((uint32_t)(c->esi + 0x7736e4u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x100936e4], eax */
    c->eax = (uint32_t)((uint32_t)0xba2e8ba3u); /* mov eax, 0xba2e8ba3 */
    { uint64_t r_ = (uint64_t)c->eax * c->ebx; c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = c->edx != 0; } /* mul ebx */
    c->edx = (uint32_t)(shr32(c, c->edx, 5)); /* shr edx, 5 */
    c->eax = (uint32_t)((uint32_t)(c->edi + 0x3b9ac9ffu)); /* lea eax, [edi + 0x3b9ac9ff] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    W32((uint32_t)(c->esi + 0x7736dcu), (uint32_t)(c->ebp)); /* mov dword ptr [esi + 0x100936dc], ebp */
    W32((uint32_t)(c->esi + 0x7736e0u), (uint32_t)((uint32_t)0x24u)); /* mov dword ptr [esi + 0x100936e0], 0x24 */
    W32((uint32_t)(c->esi + 0x7736d8u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x100936d8], edx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 12; return; /* ret 8 */
L_006e3f48:;
    c->eax = (uint32_t)(R32((uint32_t)(0x7776dcu))); /* mov eax, dword ptr [0x100976dc] */
    c->eax = (uint32_t)(add32(c, c->eax, c->ebx)); /* add eax, ebx */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    W32((uint32_t)(0x7776dcu), (uint32_t)(c->eax)); /* mov dword ptr [0x100976dc], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ecx, dword ptr [ecx + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x100u)); PUSH32(c, 0x006e3f63u); call_indirect(c, t_); } /* call dword ptr [edx + 0x100] */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 12; return; /* ret 8 */
}

void f_006e3f70(CPU *c) { /* PTR_006e3f70 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (!c->zf) goto L_006e3f7e; /* jne 0x6e3f7e */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 8; return; /* ret 4 */
L_006e3f7e:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ecx, dword ptr [ecx + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (!c->zf) goto L_006e3f8a; /* jne 0x6e3f8a */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 8; return; /* ret 4 */
L_006e3f8a:;
    (void)sub32(c, c->eax, (uint32_t)0x3b9ac9ffu); /* cmp eax, 0x3b9ac9ff */
    if (c->cf) goto L_006e3f9d; /* jb 0x6e3f9d */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x46ca96f4u))); /* mov eax, dword ptr [eax + 0x565c96f4] */
    c->esp += 8; return; /* ret 4 */
L_006e3f9d:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x110u)); PUSH32(c, 0x006e3fa8u); call_indirect(c, t_); } /* call dword ptr [edx + 0x110] */
    c->esp += 8; return; /* ret 4 */
}

void f_006e3fb0(CPU *c) { /* PTR_006e3fb0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (c->zf) goto L_006e3fd3; /* je 0x6e3fd3 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ecx, dword ptr [ecx + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_006e3fd3; /* je 0x6e3fd3 */
    (void)sub32(c, c->eax, (uint32_t)0x3b9ac9ffu); /* cmp eax, 0x3b9ac9ff */
    if (!c->cf) goto L_006e3fd3; /* jae 0x6e3fd3 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 4], eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x114u)); switch (t_) {  default: jump_indirect(c, t_, 0x006e3fcdu); return; } } /* jmp dword ptr [edx + 0x114] */
L_006e3fd3:;
    c->esp += 8; return; /* ret 4 */
}

void f_006e3fe0(CPU *c) { /* PTR_006e3fe0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (c->zf) goto L_006e401a; /* je 0x6e401a */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ecx, dword ptr [ecx + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_006e401a; /* je 0x6e401a */
    (void)sub32(c, c->eax, (uint32_t)0x3b9ac9ffu); /* cmp eax, 0x3b9ac9ff */
    if (c->cf) goto L_006e401d; /* jb 0x6e401d */
    c->ecx = (uint32_t)(R32((uint32_t)(0x7776f4u))); /* mov ecx, dword ptr [0x100976f4] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x46ca96f4u))); /* mov edx, dword ptr [esi + 0x565c96f4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x006e400fu); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
    W32((uint32_t)(c->esi + 0x46ca96e8u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 0x565c96e8], 0 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_006e401a:;
    c->esp += 8; return; /* ret 4 */
L_006e401d:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 4], eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x124u)); switch (t_) {  default: jump_indirect(c, t_, 0x006e4023u); return; } } /* jmp dword ptr [edx + 0x124] */
}

void f_006e4030(CPU *c) { /* FUN_10004030 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_006e4042; /* je 0x6e4042 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x1ecu)); PUSH32(c, 0x006e4042u); call_indirect(c, t_); } /* call dword ptr [eax + 0x1ec] */
L_006e4042:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e4060; /* je 0x6e4060 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_006e4060; /* je 0x6e4060 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x104u)); PUSH32(c, 0x006e405cu); call_indirect(c, t_); } /* call dword ptr [edx + 0x104] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
L_006e4060:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_006e4070(CPU *c) { /* PTR_006e4070 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (c->zf) goto L_006e408e; /* je 0x6e408e */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ecx, dword ptr [ecx + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_006e408e; /* je 0x6e408e */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x11cu)); PUSH32(c, 0x006e408bu); call_indirect(c, t_); } /* call dword ptr [edx + 0x11c] */
    c->esp += 8; return; /* ret 4 */
L_006e408e:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 8; return; /* ret 4 */
}

void f_006e40a0(CPU *c) { /* PTR_006e40a0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (c->zf) goto L_006e40bc; /* je 0x6e40bc */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ecx, dword ptr [ecx + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_006e40bc; /* je 0x6e40bc */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 4], eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x120u)); switch (t_) {  default: jump_indirect(c, t_, 0x006e40b6u); return; } } /* jmp dword ptr [edx + 0x120] */
L_006e40bc:;
    c->esp += 8; return; /* ret 4 */
}

void f_006e40c0(CPU *c) { /* PTR_006e40c0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (c->zf) goto L_006e40dc; /* je 0x6e40dc */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ecx, dword ptr [ecx + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_006e40dc; /* je 0x6e40dc */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 4], eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x128u)); switch (t_) {  default: jump_indirect(c, t_, 0x006e40d6u); return; } } /* jmp dword ptr [edx + 0x128] */
L_006e40dc:;
    c->esp += 8; return; /* ret 4 */
}

void f_006e40e0(CPU *c) { /* PTR_006e40e0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 8], eax */
    c->esp += 8; return; /* ret 4 */
}

void f_006e40f0(CPU *c) { /* PTR_006e40f0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    W32((uint32_t)(c->ecx + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 0xc], eax */
    W32((uint32_t)(c->ecx + 0x10u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 0x10], edx */
    c->esp += 12; return; /* ret 8 */
}

void f_006e4110(CPU *c) { /* FUN_10004110 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov ecx, dword ptr [edi + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_006e41e5; /* je 0x6e41e5 */
    c->eax = (uint32_t)(R32((uint32_t)(0x777918u))); /* mov eax, dword ptr [0x10097918] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e41ac; /* je 0x6e41ac */
    c->esi = (uint32_t)(R32((uint32_t)(c->edi + 0xcu))); /* mov esi, dword ptr [edi + 0xc] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ebx, dword ptr [esp + 0x14] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ebp, dword ptr [esp + 0x14] */
    c->esi = (uint32_t)(shl32(c, c->esi, 4)); /* shl esi, 4 */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x46ca96e8u)); /* add esi, 0x565c96e8 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov edx, dword ptr [esi + 0xc] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = c->eax; PUSH32(c, 0x006e414du); call_indirect(c, t_); } /* call eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov edx, dword ptr [esi + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov ecx, dword ptr [edi + 4] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x18], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov edx, dword ptr [esp + 0x1c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14cu)); PUSH32(c, 0x006e416au); call_indirect(c, t_); } /* call dword ptr [eax + 0x14c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov ecx, dword ptr [edi + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov edx, dword ptr [esi + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x1b8u)); PUSH32(c, 0x006e4179u); call_indirect(c, t_); } /* call dword ptr [eax + 0x1b8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov edx, dword ptr [esp + 0x24] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov eax, dword ptr [edi + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x777818u; PUSH32(c, v_); } /* push 0x10097818 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov edx, dword ptr [esp + 0x2c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov edx, dword ptr [edi + 8] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov edx, dword ptr [esi + 8] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0xd8u)); PUSH32(c, 0x006e41a2u); call_indirect(c, t_); } /* call dword ptr [ecx + 0xd8] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x28u)); /* add esp, 0x28 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 24; return; /* ret 0x14 */
L_006e41ac:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (c->zf) goto L_006e41e5; /* je 0x6e41e5 */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov esi, dword ptr [esp + 0x1c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x777818u; PUSH32(c, v_); } /* push 0x10097818 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov esi, dword ptr [esp + 0x24] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov esi, dword ptr [esp + 0x20] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov esi, dword ptr [esp + 0x20] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov eax, dword ptr [esp + 0x30] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0xcu))); /* mov eax, dword ptr [edi + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xd8u)); PUSH32(c, 0x006e41e2u); call_indirect(c, t_); } /* call dword ptr [edx + 0xd8] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x28u)); /* add esp, 0x28 */
L_006e41e5:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 24; return; /* ret 0x14 */
}

void f_006e41f0(CPU *c) { /* PTR_006e41f0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    c->esp += 88; return; /* ret 0x54 */
}

void f_006e4200(CPU *c) { /* PTR_006e4200 */
    PREEMPT_POLL(c);
    c->esp += 8; return; /* ret 4 */
}

void f_006e4210(CPU *c) { /* FUN_10004210 */
    PREEMPT_POLL(c);
    PUSH32(c, 0x006e4215u); f_006e4228(c); /* call 0x6e4228 */
    PUSH32(c, 0x006e421au); f_006e4a61(c); /* call 0x6e4a61 */
    W32((uint32_t)(0x77792cu), (uint32_t)(c->eax)); /* mov dword ptr [0x1009792c], eax */
    PUSH32(c, 0x006e4224u); f_006e4a11(c); /* call 0x6e4a11 */
    c->fpu_sw &= 0x7f00; /* fnclex  */
    c->esp += 4; return; /* ret  */
}

void f_006e4227(CPU *c) { /* PTR_006e4227 */
    PREEMPT_POLL(c);
    c->esp += 4; return; /* ret  */
}

void f_006e4228(CPU *c) { /* FUN_10004228 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x6e4e4fu); /* mov eax, 0x10004e4f */
    W32((uint32_t)(0x6ee248u), (uint32_t)((uint32_t)0x6e4ae4u)); /* mov dword ptr [0x1000e248], 0x10004ae4 */
    W32((uint32_t)(0x6ee244u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000e244], eax */
    W32((uint32_t)(0x6ee24cu), (uint32_t)((uint32_t)0x6e4b4au)); /* mov dword ptr [0x1000e24c], 0x10004b4a */
    W32((uint32_t)(0x6ee250u), (uint32_t)((uint32_t)0x6e4a8au)); /* mov dword ptr [0x1000e250], 0x10004a8a */
    W32((uint32_t)(0x6ee254u), (uint32_t)((uint32_t)0x6e4b32u)); /* mov dword ptr [0x1000e254], 0x10004b32 */
    W32((uint32_t)(0x6ee258u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000e258], eax */
    c->esp += 4; return; /* ret  */
}

void f_006e4260(CPU *c) { /* FUN_10004260 */
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
    { uint32_t t_ = c->eax; switch (t_) {  default: jump_indirect(c, t_, 0x006e428bu); return; } } /* jmp eax */
}

void f_006e428d(CPU *c) { /* PTR_006e428d */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 12; return; /* ret 8 */
}

void f_006e4294(CPU *c) { /* FUN_10004294 */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { guest_lock(); { uint32_t t0_ = R32((uint32_t)(c->esp)), t1_ = c->eax; W32((uint32_t)(c->esp), (uint32_t)(t1_)); c->eax = (uint32_t)(t0_); } guest_unlock(); } /* xchg dword ptr [esp], eax */
    { uint32_t t_ = c->eax; switch (t_) {  default: jump_indirect(c, t_, 0x006e4299u); return; } } /* jmp eax */
}

void f_006e429b(CPU *c) { /* FUN_1000429b */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { guest_lock(); { uint32_t t0_ = R32((uint32_t)(c->esp)), t1_ = c->eax; W32((uint32_t)(c->esp), (uint32_t)(t1_)); c->eax = (uint32_t)(t0_); } guest_unlock(); } /* xchg dword ptr [esp], eax */
    { uint32_t t_ = c->eax; switch (t_) {  default: jump_indirect(c, t_, 0x006e42a0u); return; } } /* jmp eax */
}

void f_006e42a2(CPU *c) { /* FUN_100042a2 */
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
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x6e42cau)); /* mov dword ptr [ebp - 4], 0x100042ca */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x006e42cau); f_006ec330(c); /* call 0x6ec330 */
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

void f_006e42ca(CPU *c) { /* PTR_006e42ca */
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

void f_006e42f1(CPU *c) { /* FUN_100042f1 */
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
    PUSH32(c, 0x006e4317u); f_006e4ec5(c); /* call 0x6e4ec5 */
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

void f_006e4327(CPU *c) { /* FUN_10004327 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x14u)); /* sub esp, 0x14 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffecu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x14], 0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)((uint32_t)0x6e437bu)); /* mov dword ptr [ebp - 0x10], 0x1000437b */
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
    PUSH32(c, 0x006e436cu); f_006e56c0(c); /* call 0x6e56c0 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->eax)); /* mov dword ptr fs:[0], eax */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006e437b(CPU *c) { /* FUN_1000437b */
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
    PUSH32(c, 0x006e439bu); f_006e4ec5(c); /* call 0x6e4ec5 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_006e43a0(CPU *c) { /* FUN_100043a0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x34u)); /* sub esp, 0x34 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffd8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x28], 0 */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)((uint32_t)0x6e4454u)); /* mov dword ptr [ebp - 0x24], 0x10004454 */
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
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)((uint32_t)0x6e4426u)); /* mov dword ptr [ebp - 0x10], 0x10004426 */
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
    { uint32_t t_ = R32((uint32_t)(0x77795cu)); PUSH32(c, 0x006e4420u); call_indirect(c, t_); } /* call dword ptr [0x1009795c] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffccu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x34], 0 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if (c->zf) goto L_006e4443; /* je 0x6e4443 */
    c->ebx = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov ebx, dword ptr fs:[0] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ebx, dword ptr [ebp - 0x28] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ebx)); /* mov dword ptr fs:[0], ebx */
    goto L_006e444c; /* jmp 0x6e444c */
L_006e4443:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->eax)); /* mov dword ptr fs:[0], eax */
L_006e444c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffccu))); /* mov eax, dword ptr [ebp - 0x34] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006e4426(CPU *c) { /* PTR_006e4426 */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if (c->zf) goto L_006e4443; /* je 0x6e4443 */
    c->ebx = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov ebx, dword ptr fs:[0] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ebx, dword ptr [ebp - 0x28] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ebx)); /* mov dword ptr fs:[0], ebx */
    goto L_006e444c; /* jmp 0x6e444c */
L_006e4443:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->eax)); /* mov dword ptr fs:[0], eax */
L_006e444c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffccu))); /* mov eax, dword ptr [ebp - 0x34] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006e4454(CPU *c) { /* FUN_10004454 */
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
    if (c->zf) goto L_006e4477; /* je 0x6e4477 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->eax + 0x24u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [eax + 0x24], 1 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_006e44c4; /* jmp 0x6e44c4 */
L_006e4477:;
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
    PUSH32(c, 0x006e449eu); f_006e4ec5(c); /* call 0x6e4ec5 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x24u)), (uint32_t)0x0u); /* cmp dword ptr [eax + 0x24], 0 */
    if (!c->zf) goto L_006e44b5; /* jne 0x6e44b5 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x006e44b5u); f_006e42a2(c); /* call 0x6e42a2 */
L_006e44b5:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ebx, dword ptr [ebp + 0xc] */
    c->esp = (uint32_t)(R32((uint32_t)(c->ebx + 0x1cu))); /* mov esp, dword ptr [ebx + 0x1c] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ebx + 0x20u))); /* mov ebp, dword ptr [ebx + 0x20] */
    { uint32_t t_ = R32((uint32_t)(c->ebx + 0x18u)); switch (t_) {  default: jump_indirect(c, t_, 0x006e44beu); return; } } /* jmp dword ptr [ebx + 0x18] */
L_006e44c4:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_006e44c9(CPU *c) { /* FUN_100044c9 */
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
    if ((c->sf != c->of)) goto L_006e4520; /* jl 0x6e4520 */
L_006e44e7:;
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (!c->zf) goto L_006e44f1; /* jne 0x6e44f1 */
    PUSH32(c, 0x006e44f1u); f_006e5762(c); /* call 0x6e5762 */
L_006e44f1:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi * 4)); /* lea eax, [esi + esi*4] */
    (void)sub32(c, R32((uint32_t)(c->ebx + c->eax * 4 + 0x4u)), c->ecx); /* cmp dword ptr [ebx + eax*4 + 4], ecx */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->eax * 4)); /* lea eax, [ebx + eax*4] */
    if ((c->sf == c->of)) goto L_006e4506; /* jge 0x6e4506 */
    (void)sub32(c, c->ecx, R32((uint32_t)(c->eax + 0x8u))); /* cmp ecx, dword ptr [eax + 8] */
    if ((c->zf || c->sf != c->of)) goto L_006e450b; /* jle 0x6e450b */
L_006e4506:;
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (!c->zf) goto L_006e4517; /* jne 0x6e4517 */
L_006e450b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
L_006e4517:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    if ((c->sf == c->of)) goto L_006e44e7; /* jge 0x6e44e7 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
L_006e4520:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov ecx, dword ptr [ebp + 0x14] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    W32((uint32_t)(c->ecx), (uint32_t)(c->esi)); /* mov dword ptr [ecx], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov ecx, dword ptr [ebp + 0x18] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    (void)sub32(c, c->eax, R32((uint32_t)(c->edi + 0xcu))); /* cmp eax, dword ptr [edi + 0xc] */
    if ((!c->cf && !c->zf)) goto L_006e4534; /* ja 0x6e4534 */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if ((c->cf || c->zf)) goto L_006e4539; /* jbe 0x6e4539 */
L_006e4534:;
    PUSH32(c, 0x006e4539u); f_006e5762(c); /* call 0x6e5762 */
L_006e4539:;
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi * 4)); /* lea eax, [esi + esi*4] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->eax * 4)); /* lea eax, [ebx + eax*4] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006e4544(CPU *c) { /* __global_unwind2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x6e455cu; PUSH32(c, v_); } /* push 0x1000455c */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x006e455cu); f_006ec330(c); /* call 0x6ec330 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_006e455c(CPU *c) { /* PTR_006e455c */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_006e4564(CPU *c) { /* PTR_006e4564 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->ecx + 0x4u)) & (uint32_t)0x6u)); /* test dword ptr [ecx + 4], 6 */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    if (c->zf) goto L_006e4585; /* je 0x6e4585 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    W32((uint32_t)(c->edx), (uint32_t)(c->eax)); /* mov dword ptr [edx], eax */
    c->eax = (uint32_t)((uint32_t)0x3u); /* mov eax, 3 */
L_006e4585:;
    c->esp += 4; return; /* ret  */
}

void f_006e4586(CPU *c) { /* __local_unwind2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0xfffffffeu; PUSH32(c, v_); } /* push -2 */
    { uint32_t v_ = 0x6e4564u; PUSH32(c, v_); } /* push 0x10004564 */
    { uint32_t v_ = R32((uint32_t)(0x0u + c->fs_base)); PUSH32(c, v_); } /* push dword ptr fs:[0] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
L_006e45a3:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov eax, dword ptr [esp + 0x20] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ebx, dword ptr [eax + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + 0xcu))); /* mov esi, dword ptr [eax + 0xc] */
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (c->zf) goto L_006e45e0; /* je 0x6e45e0 */
    (void)sub32(c, c->esi, R32((uint32_t)(c->esp + 0x24u))); /* cmp esi, dword ptr [esp + 0x24] */
    if (c->zf) goto L_006e45e0; /* je 0x6e45e0 */
    c->esi = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea esi, [esi + esi*2] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + c->esi * 4))); /* mov ecx, dword ptr [ebx + esi*4] */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 8], ecx */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0xc], ecx */
    (void)sub32(c, R32((uint32_t)(c->ebx + c->esi * 4 + 0x4u)), (uint32_t)0x0u); /* cmp dword ptr [ebx + esi*4 + 4], 0 */
    if (!c->zf) goto L_006e45de; /* jne 0x6e45de */
    { uint32_t v_ = 0x101u; PUSH32(c, v_); } /* push 0x101 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + c->esi * 4 + 0x8u))); /* mov eax, dword ptr [ebx + esi*4 + 8] */
    PUSH32(c, 0x006e45dau); f_006e461a(c); /* call 0x6e461a */
    { uint32_t t_ = R32((uint32_t)(c->ebx + c->esi * 4 + 0x8u)); PUSH32(c, 0x006e45deu); call_indirect(c, t_); } /* call dword ptr [ebx + esi*4 + 8] */
L_006e45de:;
    goto L_006e45a3; /* jmp 0x6e45a3 */
L_006e45e0:;
    { uint32_t v_ = R32(c->esp); c->esp += 4; W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(v_)); } /* pop dword ptr fs:[0] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_006e45ee(CPU *c) { /* __abnormal_termination */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov ecx, dword ptr fs:[0] */
    (void)sub32(c, R32((uint32_t)(c->ecx + 0x4u)), (uint32_t)0x6e4564u); /* cmp dword ptr [ecx + 4], 0x10004564 */
    if (!c->zf) goto L_006e4610; /* jne 0x6e4610 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov edx, dword ptr [ecx + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edx + 0xcu))); /* mov edx, dword ptr [edx + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->ecx + 0x8u)), c->edx); /* cmp dword ptr [ecx + 8], edx */
    if (!c->zf) goto L_006e4610; /* jne 0x6e4610 */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
L_006e4610:;
    c->esp += 4; return; /* ret  */
}

void f_006e4611(CPU *c) { /* __NLG_Notify1 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ebx = (uint32_t)((uint32_t)0x6ee210u); /* mov ebx, 0x1000e210 */
    { f_006e4624(c); return; } /* jmp 0x6e4624 */
}

void f_006e461a(CPU *c) { /* FUN_1000461a */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ebx = (uint32_t)((uint32_t)0x6ee210u); /* mov ebx, 0x1000e210 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebx + 8], ecx */
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 4], eax */
    W32((uint32_t)(c->ebx + 0xcu), (uint32_t)(c->ebp)); /* mov dword ptr [ebx + 0xc], ebp */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
}

void f_006e4624(CPU *c) { /* PTR_006e4624 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebx + 8], ecx */
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 4], eax */
    W32((uint32_t)(c->ebx + 0xcu), (uint32_t)(c->ebp)); /* mov dword ptr [ebx + 0xc], ebp */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
}

void f_006e4632(CPU *c) { /* FUN_10004632 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx), (uint32_t)((uint32_t)0x6ed340u)); /* mov dword ptr [ecx], 0x1000d340 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ecx, dword ptr [ecx + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_006e4646; /* je 0x6e4646 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x006e4645u); f_006e57b8(c); /* call 0x6e57b8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006e4646:;
    c->esp += 4; return; /* ret  */
}

void f_006e4647(CPU *c) { /* type_info::vfunc_0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x006e464fu); f_006e4632(c); /* call 0x6e4632 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_006e465d; /* je 0x6e465d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006e465cu); f_006e3420(c); /* call 0x6e3420 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006e465d:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_006e4663(CPU *c) { /* __CxxThrowException@8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x20u)); /* sub esp, 0x20 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esi = (uint32_t)((uint32_t)0x6ed348u); /* mov esi, 0x1000d348 */
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
    { uint32_t t_ = R32((uint32_t)(0x6ed004u)); PUSH32(c, 0x006e4697u); call_indirect(c, t_); } /* call dword ptr [0x1000d004] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 12; return; /* ret 8 */
}

void f_006e469d(CPU *c) { /* PTR_006e469d */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x19u; PUSH32(c, v_); } /* push 0x19 */
    PUSH32(c, 0x006e46a4u); f_006e49de(c); /* call 0x6e49de */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_006e46a6(CPU *c) { /* FUN_100046a6 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(0x778ed8u)); PUSH32(c, v_); } /* push dword ptr [0x10098ed8] */
    PUSH32(c, 0x006e46b2u); f_006e5cb8(c); /* call 0x6e5cb8 */
    c->edx = (uint32_t)(R32((uint32_t)(0x778ed8u))); /* mov edx, dword ptr [0x10098ed8] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(0x778ed4u))); /* mov ecx, dword ptr [0x10098ed4] */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->esi = (uint32_t)(sub32(c, c->esi, c->edx)); /* sub esi, edx */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    if (!c->cf) goto L_006e4705; /* jae 0x6e4705 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x006e46d1u); f_006e5cb8(c); /* call 0x6e5cb8 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x10u)); /* add eax, 0x10 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(0x778ed8u)); PUSH32(c, v_); } /* push dword ptr [0x10098ed8] */
    PUSH32(c, 0x006e46e0u); f_006e5918(c); /* call 0x6e5918 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006e46e8; /* jne 0x6e46e8 */
    c->esp += 4; return; /* ret  */
L_006e46e8:;
    c->ecx = (uint32_t)(R32((uint32_t)(0x778ed4u))); /* mov ecx, dword ptr [0x10098ed4] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, R32((uint32_t)(0x778ed8u)))); /* sub ecx, dword ptr [0x10098ed8] */
    W32((uint32_t)(0x778ed8u), (uint32_t)(c->eax)); /* mov dword ptr [0x10098ed8], eax */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 2)); /* sar ecx, 2 */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->ecx * 4)); /* lea ecx, [eax + ecx*4] */
    W32((uint32_t)(0x778ed4u), (uint32_t)(c->ecx)); /* mov dword ptr [0x10098ed4], ecx */
L_006e4705:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    { uint32_t a_ = (uint32_t)(0x778ed4u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x4u))); } /* add dword ptr [0x10098ed4], 4 */
    c->esp += 4; return; /* ret  */
}

void f_006e4713(CPU *c) { /* FUN_10004713 */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    PUSH32(c, 0x006e471cu); f_006e46a6(c); /* call 0x6e46a6 */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->esp += 4; return; /* ret  */
}

void f_006e4725(CPU *c) { /* PTR_006e4725 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x80u; PUSH32(c, v_); } /* push 0x80 */
    PUSH32(c, 0x006e472fu); f_006e5d19(c); /* call 0x6e5d19 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(0x778ed8u), (uint32_t)(c->eax)); /* mov dword ptr [0x10098ed8], eax */
    if (!c->zf) goto L_006e4746; /* jne 0x6e4746 */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    PUSH32(c, 0x006e4740u); f_006e49de(c); /* call 0x6e49de */
    c->eax = (uint32_t)(R32((uint32_t)(0x778ed8u))); /* mov eax, dword ptr [0x10098ed8] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006e4746:;
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [eax], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(0x778ed8u))); /* mov eax, dword ptr [0x10098ed8] */
    W32((uint32_t)(0x778ed4u), (uint32_t)(c->eax)); /* mov dword ptr [0x10098ed4], eax */
    c->esp += 4; return; /* ret  */
}

void f_006e4754(CPU *c) { /* FUN_10004754 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi | (uint32_t)0xffffffffu))); /* or edi, 0xffffffff */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x40u)); /* test al, 0x40 */
    if (c->zf) goto L_006e4769; /* je 0x6e4769 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    goto L_006e47a3; /* jmp 0x6e47a3 */
L_006e4769:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x83u)); /* test al, 0x83 */
    if (c->zf) goto L_006e47a1; /* je 0x6e47a1 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006e4773u); f_006e5ee4(c); /* call 0x6e5ee4 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    PUSH32(c, 0x006e477bu); f_006e5e7e(c); /* call 0x6e5e7e */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x10] */
    PUSH32(c, 0x006e4783u); f_006e5dcb(c); /* call 0x6e5dcb */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf == c->of)) goto L_006e478f; /* jge 0x6e478f */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi | (uint32_t)0xffffffffu))); /* or edi, 0xffffffff */
    goto L_006e47a1; /* jmp 0x6e47a1 */
L_006e478f:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x1cu))); /* mov eax, dword ptr [esi + 0x1c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e47a1; /* je 0x6e47a1 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e479cu); f_006e57b8(c); /* call 0x6e57b8 */
    { uint32_t a_ = (uint32_t)(c->esi + 0x1cu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi + 0x1c], 0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006e47a1:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
L_006e47a3:;
    { uint32_t a_ = (uint32_t)(c->esi + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi + 0xc], 0 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_006e47aa(CPU *c) { /* FUN_100047aa */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x006e47b7u); f_006e5fb6(c); /* call 0x6e5fb6 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x006e47c8u); f_006e6080(c); /* call 0x6e6080 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006e47d3u); f_006e6043(c); /* call 0x6e6043 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_006e47dc(CPU *c) { /* FUN_100047dc */
    PREEMPT_POLL(c);
    PUSH32(c, 0x006e47e1u); f_006e69fa(c); /* call 0x6e69fa */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006e47e6; /* jne 0x6e47e6 */
    c->esp += 4; return; /* ret  */
L_006e47e6:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    PUSH32(c, 0x006e47f8u); f_006e688a(c); /* call 0x6e688a */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_006e47fc(CPU *c) { /* FUN_100047fc */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x40u; PUSH32(c, v_); } /* push 0x40 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    PUSH32(c, 0x006e480bu); f_006e47dc(c); /* call 0x6e47dc */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_006e4810(CPU *c) { /* _strrchr */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0xffffffffu))); /* or ecx, 0xffffffff */
    while (c->ecx) { (void)sub8(c, ((uint8_t)c->eax), R8(c->edi)); c->edi += (c->df ? -1 : 1); c->ecx--; if (c->zf) break; } /* repne scasb al, byte ptr es:[edi] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0xcu))); /* mov al, byte ptr [ebp + 0xc] */
    c->df = 1; /* std  */
    while (c->ecx) { (void)sub8(c, ((uint8_t)c->eax), R8(c->edi)); c->edi += (c->df ? -1 : 1); c->ecx--; if (c->zf) break; } /* repne scasb al, byte ptr es:[edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub8(c, R8((uint32_t)(c->edi)), ((uint8_t)c->eax)); /* cmp byte ptr [edi], al */
    if (c->zf) goto L_006e4831; /* je 0x6e4831 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_006e4833; /* jmp 0x6e4833 */
L_006e4831:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
L_006e4833:;
    c->df = 0; /* cld  */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006e4837(CPU *c) { /* FUN_10004837 */
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
    PUSH32(c, 0x006e4865u); f_006e6080(c); /* call 0x6e6080 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe4u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 0x1c] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    if (c->sf) goto L_006e4877; /* js 0x6e4877 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov eax, dword ptr [ebp - 0x20] */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax], 0 */
    goto L_006e4884; /* jmp 0x6e4884 */
L_006e4877:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe0u)); /* lea eax, [ebp - 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    PUSH32(c, 0x006e4882u); f_006e6a72(c); /* call 0x6e6a72 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006e4884:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006e4889(CPU *c) { /* FUN_10004889 */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->esp + 0x8u)), (uint32_t)0x1u); /* cmp dword ptr [esp + 8], 1 */
    if (!c->zf) goto L_006e490e; /* jne 0x6e490e */
    { uint32_t t_ = R32((uint32_t)(0x6ed00cu)); PUSH32(c, 0x006e4896u); call_indirect(c, t_); } /* call dword ptr [0x1000d00c] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    W32((uint32_t)(0x777974u), (uint32_t)(c->eax)); /* mov dword ptr [0x10097974], eax */
    PUSH32(c, 0x006e48a2u); f_006e6cfc(c); /* call 0x6e6cfc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_006e493d; /* je 0x6e493d */
    c->eax = (uint32_t)(R32((uint32_t)(0x777974u))); /* mov eax, dword ptr [0x10097974] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x777975u))); /* mov cl, byte ptr [0x10097975] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xffu))); /* and eax, 0xff */
    { uint32_t a_ = (uint32_t)(0x777974u); W32(a_, (uint32_t)(shr32(c, R32(a_), 16))); } /* shr dword ptr [0x10097974], 0x10 */
    W32((uint32_t)(0x77797cu), (uint32_t)(c->eax)); /* mov dword ptr [0x1009797c], eax */
    W32((uint32_t)(0x777980u), (uint32_t)(c->ecx)); /* mov dword ptr [0x10097980], ecx */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    W32((uint32_t)(0x777978u), (uint32_t)(c->eax)); /* mov dword ptr [0x10097978], eax */
    { uint32_t t_ = R32((uint32_t)(0x6ed008u)); PUSH32(c, 0x006e48dfu); call_indirect(c, t_); } /* call dword ptr [0x1000d008] */
    W32((uint32_t)(0x778edcu), (uint32_t)(c->eax)); /* mov dword ptr [0x10098edc], eax */
    PUSH32(c, 0x006e48e9u); f_006e72d5(c); /* call 0x6e72d5 */
    W32((uint32_t)(0x777934u), (uint32_t)(c->eax)); /* mov dword ptr [0x10097934], eax */
    PUSH32(c, 0x006e48f3u); f_006e6e01(c); /* call 0x6e6e01 */
    PUSH32(c, 0x006e48f8u); f_006e7088(c); /* call 0x6e7088 */
    PUSH32(c, 0x006e48fdu); f_006e6fcf(c); /* call 0x6e6fcf */
    PUSH32(c, 0x006e4902u); f_006e5bb8(c); /* call 0x6e5bb8 */
    { uint32_t a_ = (uint32_t)(0x777930u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [0x10097930] */
L_006e4908:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_006e490b:;
    c->esp += 16; return; /* ret 0xc */
L_006e490e:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, R32((uint32_t)(c->esp + 0x8u)), c->eax); /* cmp dword ptr [esp + 8], eax */
    if (!c->zf) goto L_006e4908; /* jne 0x6e4908 */
    (void)sub32(c, R32((uint32_t)(0x777930u)), c->eax); /* cmp dword ptr [0x10097930], eax */
    if ((c->zf || c->sf != c->of)) goto L_006e493d; /* jle 0x6e493d */
    { uint32_t a_ = (uint32_t)(0x777930u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [0x10097930] */
    (void)sub32(c, R32((uint32_t)(0x7779acu)), c->eax); /* cmp dword ptr [0x100979ac], eax */
    if (!c->zf) goto L_006e4931; /* jne 0x6e4931 */
    PUSH32(c, 0x006e4931u); f_006e5bf6(c); /* call 0x6e5bf6 */
L_006e4931:;
    PUSH32(c, 0x006e4936u); f_006e6fac(c); /* call 0x6e6fac */
    PUSH32(c, 0x006e493bu); f_006e6d59(c); /* call 0x6e6d59 */
    goto L_006e4908; /* jmp 0x6e4908 */
L_006e493d:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_006e490b; /* jmp 0x6e490b */
}

void f_006e4941(CPU *c) { /* entry */
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
    if (!c->zf) goto L_006e495d; /* jne 0x6e495d */
    (void)sub32(c, R32((uint32_t)(0x777930u)), (uint32_t)0x0u); /* cmp dword ptr [0x10097930], 0 */
    goto L_006e4983; /* jmp 0x6e4983 */
L_006e495d:;
    (void)sub32(c, c->esi, (uint32_t)0x1u); /* cmp esi, 1 */
    if (c->zf) goto L_006e4967; /* je 0x6e4967 */
    (void)sub32(c, c->esi, (uint32_t)0x2u); /* cmp esi, 2 */
    if (!c->zf) goto L_006e4989; /* jne 0x6e4989 */
L_006e4967:;
    c->eax = (uint32_t)(R32((uint32_t)(0x778ee0u))); /* mov eax, dword ptr [0x10098ee0] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e4979; /* je 0x6e4979 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = c->eax; PUSH32(c, 0x006e4975u); call_indirect(c, t_); } /* call eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e4985; /* je 0x6e4985 */
L_006e4979:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x006e4981u); f_006e4889(c); /* call 0x6e4889 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
L_006e4983:;
    if (!c->zf) goto L_006e4989; /* jne 0x6e4989 */
L_006e4985:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_006e49d7; /* jmp 0x6e49d7 */
L_006e4989:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x006e4991u); f_006e7407(c); /* call 0x6e7407 */
    (void)sub32(c, c->esi, (uint32_t)0x1u); /* cmp esi, 1 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0xc], eax */
    if (!c->zf) goto L_006e49a5; /* jne 0x6e49a5 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006e49d4; /* jne 0x6e49d4 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x006e49a5u); f_006e4889(c); /* call 0x6e4889 */
L_006e49a5:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_006e49ae; /* je 0x6e49ae */
    (void)sub32(c, c->esi, (uint32_t)0x3u); /* cmp esi, 3 */
    if (!c->zf) goto L_006e49d4; /* jne 0x6e49d4 */
L_006e49ae:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x006e49b6u); f_006e4889(c); /* call 0x6e4889 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006e49bd; /* jne 0x6e49bd */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->eax)))); } /* and dword ptr [ebp + 0xc], eax */
L_006e49bd:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    if (c->zf) goto L_006e49d4; /* je 0x6e49d4 */
    c->eax = (uint32_t)(R32((uint32_t)(0x778ee0u))); /* mov eax, dword ptr [0x10098ee0] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e49d4; /* je 0x6e49d4 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = c->eax; PUSH32(c, 0x006e49d1u); call_indirect(c, t_); } /* call eax */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0xc], eax */
L_006e49d4:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
L_006e49d7:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 16; return; /* ret 0xc */
}

void f_006e49de(CPU *c) { /* __amsg_exit */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x77793cu))); /* mov eax, dword ptr [0x1009793c] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_006e49f5; /* je 0x6e49f5 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006e49fa; /* jne 0x6e49fa */
    (void)sub32(c, R32((uint32_t)(0x777940u)), (uint32_t)0x1u); /* cmp dword ptr [0x10097940], 1 */
    if (!c->zf) goto L_006e49fa; /* jne 0x6e49fa */
L_006e49f5:;
    PUSH32(c, 0x006e49fau); f_006e7427(c); /* call 0x6e7427 */
L_006e49fa:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    PUSH32(c, 0x006e4a03u); f_006e7460(c); /* call 0x6e7460 */
    { uint32_t v_ = 0xffu; PUSH32(c, v_); } /* push 0xff */
    { uint32_t t_ = R32((uint32_t)(0x6ee240u)); PUSH32(c, 0x006e4a0eu); call_indirect(c, t_); } /* call dword ptr [0x1000e240] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_006e4a0e(CPU *c) { /* PTR_006e4a0e */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_006e4a11(CPU *c) { /* FUN_10004a11 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x30000u; PUSH32(c, v_); } /* push 0x30000 */
    { uint32_t v_ = 0x10000u; PUSH32(c, v_); } /* push 0x10000 */
    PUSH32(c, 0x006e4a20u); f_006e75e8(c); /* call 0x6e75e8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_006e4a23(CPU *c) { /* FUN_10004a23 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    FPUSH(c, RF64((uint32_t)(0x6ed378u))); /* fld qword ptr [0x1000d378] */
    WF64((uint32_t)(c->ebp + 0xfffffff8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 8] */
    FPUSH(c, RF64((uint32_t)(0x6ed370u))); /* fld qword ptr [0x1000d370] */
    WF64((uint32_t)(c->ebp + 0xfffffff0u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0x10] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff0u))); /* fld qword ptr [ebp - 0x10] */
    ST(0) = FPRES(c, FDIV(c, ST(0), RF64((uint32_t)(c->ebp + 0xfffffff8u)))); /* fdiv qword ptr [ebp - 8] */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->ebp + 0xfffffff8u))); /* fmul qword ptr [ebp - 8] */
    ST(0) = FPRES(c, RF64((uint32_t)(c->ebp + 0xfffffff0u)) - ST(0)); /* fsubr qword ptr [ebp - 0x10] */
    WF64((uint32_t)(c->ebp + 0xffffffe8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0x18] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xffffffe8u))); /* fld qword ptr [ebp - 0x18] */
    FCOM(c, ST(0), RF64((uint32_t)(0x6ed368u))); FPOP(c); /* fcomp qword ptr [0x1000d368] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if ((c->cf || c->zf)) goto L_006e4a5d; /* jbe 0x6e4a5d */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e4a5d:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006e4a61(CPU *c) { /* FUN_10004a61 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x6ed39cu; PUSH32(c, v_); } /* push 0x1000d39c */
    { uint32_t t_ = R32((uint32_t)(0x6ed014u)); PUSH32(c, 0x006e4a6cu); call_indirect(c, t_); } /* call dword ptr [0x1000d014] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e4a85; /* je 0x6e4a85 */
    { uint32_t v_ = 0x6ed380u; PUSH32(c, v_); } /* push 0x1000d380 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x6ed010u)); PUSH32(c, 0x006e4a7cu); call_indirect(c, t_); } /* call dword ptr [0x1000d010] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e4a85; /* je 0x6e4a85 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x006e4a84u); call_indirect(c, t_); } /* call eax */
    c->esp += 4; return; /* ret  */
L_006e4a85:;
    { f_006e4a23(c); return; } /* jmp 0x6e4a23 */
}

void f_006e4a8a(CPU *c) { /* FUN_10004a8a */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->esi))); /* movsx eax, byte ptr [esi] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e4a98u); f_006e778e(c); /* call 0x6e778e */
    (void)sub32(c, c->eax, (uint32_t)0x65u); /* cmp eax, 0x65 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_006e4aca; /* je 0x6e4aca */
L_006e4a9e:;
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub32(c, R32((uint32_t)(0x6ee318u)), (uint32_t)0x1u); /* cmp dword ptr [0x1000e318], 1 */
    if ((c->zf || c->sf != c->of)) goto L_006e4ab7; /* jle 0x6e4ab7 */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->esi))); /* movsx eax, byte ptr [esi] */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e4ab3u); f_006e7719(c); /* call 0x6e7719 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_006e4ac6; /* jmp 0x6e4ac6 */
L_006e4ab7:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->esi))); /* movsx eax, byte ptr [esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x6ee324u))); /* mov ecx, dword ptr [0x1000e324] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4u))); /* and eax, 4 */
L_006e4ac6:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006e4a9e; /* jne 0x6e4a9e */
L_006e4aca:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x6ee31cu))); /* mov cl, byte ptr [0x1000e31c] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esi], cl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_006e4ad5:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov cl, byte ptr [esi] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [esi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(((uint8_t)c->ecx)); /* mov al, cl */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov cl, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_006e4ad5; /* jne 0x6e4ad5 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_006e4ae4(CPU *c) { /* PTR_006e4ae4 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x6ee31cu))); /* mov dl, byte ptr [0x1000e31c] */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_006e4b00; /* je 0x6e4b00 */
L_006e4af4:;
    (void)sub8(c, ((uint8_t)c->ecx), ((uint8_t)c->edx)); /* cmp cl, dl */
    if (c->zf) goto L_006e4b00; /* je 0x6e4b00 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1u))); /* mov cl, byte ptr [eax + 1] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_006e4af4; /* jne 0x6e4af4 */
L_006e4b00:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_006e4b31; /* je 0x6e4b31 */
L_006e4b07:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_006e4b1a; /* je 0x6e4b1a */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x65u); /* cmp cl, 0x65 */
    if (c->zf) goto L_006e4b1a; /* je 0x6e4b1a */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x45u); /* cmp cl, 0x45 */
    if (c->zf) goto L_006e4b1a; /* je 0x6e4b1a */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_006e4b07; /* jmp 0x6e4b07 */
L_006e4b1a:;
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
L_006e4b1c:;
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x30u); /* cmp byte ptr [eax], 0x30 */
    if (c->zf) goto L_006e4b1c; /* je 0x6e4b1c */
    (void)sub8(c, R8((uint32_t)(c->eax)), ((uint8_t)c->edx)); /* cmp byte ptr [eax], dl */
    if (!c->zf) goto L_006e4b27; /* jne 0x6e4b27 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
L_006e4b27:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov dl, byte ptr [ecx] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [eax], dl */
    if (!c->zf) goto L_006e4b27; /* jne 0x6e4b27 */
L_006e4b31:;
    c->esp += 4; return; /* ret  */
}

void f_006e4b32(CPU *c) { /* PTR_006e4b32 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    FPUSH(c, RF64((uint32_t)(c->eax))); /* fld qword ptr [eax] */
    FCOM(c, ST(0), RF64((uint32_t)(0x6ed3a8u))); FPOP(c); /* fcomp qword ptr [0x1000d3a8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (c->cf) goto L_006e4b47; /* jb 0x6e4b47 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
L_006e4b47:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_006e4b4a(CPU *c) { /* __fassign */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    if (c->zf) goto L_006e4b73; /* je 0x6e4b73 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e4b61u); f_006e7beb(c); /* call 0x6e7beb */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 4], ecx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e4b73:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e4b7cu); f_006e7c18(c); /* call 0x6e7c18 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006e4b88(CPU *c) { /* FUN_10004b88 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    (void)sub8(c, R8((uint32_t)(0x777948u)), (uint8_t)0x0u); /* cmp byte ptr [0x10097948], 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    if (c->zf) goto L_006e4bbd; /* je 0x6e4bbd */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ebx, dword ptr [ebp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(0x777944u))); /* mov eax, dword ptr [0x10097944] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)((!c->zf && c->sf == c->of) ? 1 : 0); /* setg cl */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0x2du); /* cmp dword ptr [eax], 0x2d */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete cl */
    c->ecx = (uint32_t)(add32(c, c->ecx, R32((uint32_t)(c->ebp + 0xcu)))); /* add ecx, dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x006e4bb9u); f_006e4ea0(c); /* call 0x6e4ea0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_006e4bf5; /* jmp 0x6e4bf5 */
L_006e4bbd:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    FPUSH(c, RF64((uint32_t)(c->eax))); /* fld qword ptr [eax] */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x006e4bccu); f_006e7db7(c); /* call 0x6e7db7 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ebx, dword ptr [ebp + 0x10] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)((uint32_t)(c->ebx + 0x1u)); /* lea eax, [ebx + 1] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x2du); /* cmp dword ptr [esi], 0x2d */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete al */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)((!c->zf && c->sf == c->of) ? 1 : 0); /* setg cl */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->edx)); /* add ecx, edx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x006e4bf2u); f_006e7d40(c); /* call 0x6e7d40 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
L_006e4bf5:;
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x2du); /* cmp dword ptr [esi], 0x2d */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    if (!c->zf) goto L_006e4c01; /* jne 0x6e4c01 */
    W8((uint32_t)(c->eax), (uint8_t)((uint8_t)0x2du)); /* mov byte ptr [eax], 0x2d */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
L_006e4c01:;
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if ((c->zf || c->sf != c->of)) goto L_006e4c19; /* jle 0x6e4c19 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1u))); /* mov cl, byte ptr [eax + 1] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)((uint32_t)(c->eax + 0x1u)); /* lea edi, [eax + 1] */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax], cl */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x6ee31cu))); /* mov cl, byte ptr [0x1000e31c] */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax], cl */
L_006e4c19:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    { uint32_t v_ = 0x6ed3b0u; PUSH32(c, v_); } /* push 0x1000d3b0 */
    (void)sub8(c, R8((uint32_t)(0x777948u)), ((uint8_t)c->ecx)); /* cmp byte ptr [0x10097948], cl */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete cl */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->ebx)); /* add ecx, ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x006e4c33u); f_006e7c50(c); /* call 0x6e7c50 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x14u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x14], 0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    if (c->zf) goto L_006e4c40; /* je 0x6e4c40 */
    W8((uint32_t)(c->ecx), (uint8_t)((uint8_t)0x45u)); /* mov byte ptr [ecx], 0x45 */
L_006e4c40:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x30u); /* cmp byte ptr [eax], 0x30 */
    if (c->zf) goto L_006e4c85; /* je 0x6e4c85 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ebx, dword ptr [esi + 4] */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->sf) goto L_006e4c54; /* jns 0x6e4c54 */
    c->ebx = (uint32_t)(neg32(c, c->ebx)); /* neg ebx */
    W8((uint32_t)(c->ecx), (uint8_t)((uint8_t)0x2du)); /* mov byte ptr [ecx], 0x2d */
L_006e4c54:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->ebx, (uint32_t)0x64u); /* cmp ebx, 0x64 */
    if ((c->sf != c->of)) goto L_006e4c6b; /* jl 0x6e4c6b */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = 0x64u; PUSH32(c, v_); } /* push 0x64 */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x006e4c60u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [ecx], al */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x006e4c67u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
    c->ebx = (uint32_t)(c->edx); /* mov ebx, edx */
L_006e4c6b:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->ebx, (uint32_t)0xau); /* cmp ebx, 0xa */
    if ((c->sf != c->of)) goto L_006e4c82; /* jl 0x6e4c82 */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = 0xau; PUSH32(c, v_); } /* push 0xa */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x006e4c77u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [ecx], al */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x006e4c7eu, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
    c->ebx = (uint32_t)(c->edx); /* mov ebx, edx */
L_006e4c82:;
    { uint32_t a_ = (uint32_t)(c->ecx + 0x1u); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ebx)))); } /* add byte ptr [ecx + 1], bl */
L_006e4c85:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_006e4c8c(CPU *c) { /* FUN_10004c8c */
    PREEMPT_POLL(c);
    (void)sub8(c, R8((uint32_t)(0x777948u)), (uint8_t)0x0u); /* cmp byte ptr [0x10097948], 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ebp, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (c->zf) goto L_006e4cc7; /* je 0x6e4cc7 */
    c->eax = (uint32_t)(R32((uint32_t)(0x77794cu))); /* mov eax, dword ptr [0x1009794c] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov ebx, dword ptr [esp + 0x1c] */
    c->esi = (uint32_t)(R32((uint32_t)(0x777944u))); /* mov esi, dword ptr [0x10097944] */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (!c->zf) goto L_006e4cf7; /* jne 0x6e4cf7 */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x2du); /* cmp dword ptr [esi], 0x2d */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete cl */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->ebp)); /* add ecx, ebp */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    W8((uint32_t)(c->eax), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [eax], 0x30 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x1u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax + 1], 0 */
    goto L_006e4cf7; /* jmp 0x6e4cf7 */
L_006e4cc7:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    FPUSH(c, RF64((uint32_t)(c->eax))); /* fld qword ptr [eax] */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x006e4cd7u); f_006e7db7(c); /* call 0x6e7db7 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov ebx, dword ptr [esp + 0x24] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->eax = (uint32_t)(add32(c, c->eax, c->ebx)); /* add eax, ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x2du); /* cmp dword ptr [esi], 0x2d */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete al */
    c->eax = (uint32_t)(add32(c, c->eax, c->ebp)); /* add eax, ebp */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e4cf4u); f_006e7d40(c); /* call 0x6e7d40 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
L_006e4cf7:;
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x2du); /* cmp dword ptr [esi], 0x2d */
    c->edi = (uint32_t)(c->ebp); /* mov edi, ebp */
    if (!c->zf) goto L_006e4d05; /* jne 0x6e4d05 */
    W8((uint32_t)(c->ebp), (uint8_t)((uint8_t)0x2du)); /* mov byte ptr [ebp], 0x2d */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0x1u)); /* lea edi, [ebp + 1] */
L_006e4d05:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((!c->zf && c->sf == c->of)) goto L_006e4d1c; /* jg 0x6e4d1c */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006e4d14u); f_006e4ea0(c); /* call 0x6e4ea0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W8((uint32_t)(c->edi), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [edi], 0x30 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_006e4d1e; /* jmp 0x6e4d1e */
L_006e4d1c:;
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
L_006e4d1e:;
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if ((c->zf || c->sf != c->of)) goto L_006e4d63; /* jle 0x6e4d63 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006e4d2au); f_006e4ea0(c); /* call 0x6e4ea0 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x6ee31cu))); /* mov al, byte ptr [0x1000e31c] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov esi, dword ptr [esi + 4] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if ((c->sf == c->of)) goto L_006e4d63; /* jge 0x6e4d63 */
    (void)sub8(c, R8((uint32_t)(0x777948u)), (uint8_t)0x0u); /* cmp byte ptr [0x10097948], 0 */
    if (c->zf) goto L_006e4d48; /* je 0x6e4d48 */
    c->esi = (uint32_t)(neg32(c, c->esi)); /* neg esi */
    goto L_006e4d4e; /* jmp 0x6e4d4e */
L_006e4d48:;
    c->esi = (uint32_t)(neg32(c, c->esi)); /* neg esi */
    (void)sub32(c, c->ebx, c->esi); /* cmp ebx, esi */
    if ((c->sf != c->of)) goto L_006e4d50; /* jl 0x6e4d50 */
L_006e4d4e:;
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
L_006e4d50:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006e4d57u); f_006e4ea0(c); /* call 0x6e4ea0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x30u; PUSH32(c, v_); } /* push 0x30 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006e4d60u); f_006e7ee0(c); /* call 0x6e7ee0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
L_006e4d63:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)(c->ebp); /* mov eax, ebp */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_006e4d6a(CPU *c) { /* FUN_10004d6a */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    FPUSH(c, RF64((uint32_t)(c->edi))); /* fld qword ptr [edi] */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x006e4d7fu); f_006e7db7(c); /* call 0x6e7db7 */
    W32((uint32_t)(0x777944u), (uint32_t)(c->eax)); /* mov dword ptr [0x10097944], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ebx, dword ptr [ebp + 0x10] */
    W32((uint32_t)(0x77794cu), (uint32_t)(c->ecx)); /* mov dword ptr [0x1009794c], ecx */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0x2du); /* cmp dword ptr [eax], 0x2d */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete cl */
    c->ecx = (uint32_t)(add32(c, c->ecx, R32((uint32_t)(c->ebp + 0xcu)))); /* add ecx, dword ptr [ebp + 0xc] */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006e4da6u); f_006e7d40(c); /* call 0x6e7d40 */
    c->eax = (uint32_t)(R32((uint32_t)(0x777944u))); /* mov eax, dword ptr [0x10097944] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    (void)sub32(c, R32((uint32_t)(0x77794cu)), c->ecx); /* cmp dword ptr [0x1009794c], ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)((c->sf != c->of) ? 1 : 0); /* setl cl */
    W8((uint32_t)(0x777950u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [0x10097950], cl */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov eax, dword ptr [eax + 4] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub32(c, c->eax, (uint32_t)0xfffffffcu); /* cmp eax, -4 */
    W32((uint32_t)(0x77794cu), (uint32_t)(c->eax)); /* mov dword ptr [0x1009794c], eax */
    if ((c->sf != c->of)) goto L_006e4df0; /* jl 0x6e4df0 */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if ((c->sf == c->of)) goto L_006e4df0; /* jge 0x6e4df0 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_006e4de1; /* je 0x6e4de1 */
L_006e4dd7:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_006e4dd7; /* jne 0x6e4dd7 */
    { uint32_t a_ = (uint32_t)(c->esi + 0xfffffffeu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & ((uint8_t)c->eax))))); } /* and byte ptr [esi - 2], al */
L_006e4de1:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006e4debu); f_006e4e2c(c); /* call 0x6e4e2c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_006e4e00; /* jmp 0x6e4e00 */
L_006e4df0:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006e4dfdu); f_006e4e05(c); /* call 0x6e4e05 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_006e4e00:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_006e4e05(CPU *c) { /* FUN_10004e05 */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    W8((uint32_t)(0x777948u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [0x10097948], 1 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    PUSH32(c, 0x006e4e21u); f_006e4b88(c); /* call 0x6e4b88 */
    { uint32_t a_ = (uint32_t)(0x777948u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [0x10097948], 0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_006e4e2c(CPU *c) { /* FUN_10004e2c */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    W8((uint32_t)(0x777948u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [0x10097948], 1 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    PUSH32(c, 0x006e4e44u); f_006e4c8c(c); /* call 0x6e4c8c */
    { uint32_t a_ = (uint32_t)(0x777948u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [0x10097948], 0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_006e4e4f(CPU *c) { /* __cfltcvt */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), (uint32_t)0x65u); /* cmp dword ptr [ebp + 0x10], 0x65 */
    if (c->zf) goto L_006e4e8a; /* je 0x6e4e8a */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), (uint32_t)0x45u); /* cmp dword ptr [ebp + 0x10], 0x45 */
    if (c->zf) goto L_006e4e8a; /* je 0x6e4e8a */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), (uint32_t)0x66u); /* cmp dword ptr [ebp + 0x10], 0x66 */
    if (!c->zf) goto L_006e4e77; /* jne 0x6e4e77 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x006e4e72u); f_006e4c8c(c); /* call 0x6e4c8c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
L_006e4e77:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x006e4e88u); f_006e4d6a(c); /* call 0x6e4d6a */
    goto L_006e4e9b; /* jmp 0x6e4e9b */
L_006e4e8a:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x006e4e9bu); f_006e4b88(c); /* call 0x6e4b88 */
L_006e4e9b:;
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_006e4ea0(CPU *c) { /* FUN_10004ea0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edi, dword ptr [esp + 0xc] */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_006e4ec3; /* je 0x6e4ec3 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov esi, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006e4eb4u); f_006e8280(c); /* call 0x6e8280 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(add32(c, c->esi, c->edi)); /* add esi, edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006e4ebfu); f_006e7f40(c); /* call 0x6e7f40 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_006e4ec3:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_006e4ec5(CPU *c) { /* FUN_10004ec5 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov esi, dword ptr [ebp + 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)((uint32_t)0x19930520u); /* mov edi, 0x19930520 */
    (void)sub32(c, R32((uint32_t)(c->esi)), c->edi); /* cmp dword ptr [esi], edi */
    if (c->zf) goto L_006e4edb; /* je 0x6e4edb */
    PUSH32(c, 0x006e4edbu); f_006e5762(c); /* call 0x6e5762 */
L_006e4edb:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + 0x4u)) & (uint8_t)0x66u)); /* test byte ptr [eax + 4], 0x66 */
    if (c->zf) goto L_006e4f03; /* je 0x6e4f03 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x4u)), (uint32_t)0x0u); /* cmp dword ptr [esi + 4], 0 */
    if (c->zf) goto L_006e4f59; /* je 0x6e4f59 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x1c], 0 */
    if (!c->zf) goto L_006e4f59; /* jne 0x6e4f59 */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x006e4efeu); f_006e520c(c); /* call 0x6e520c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    goto L_006e4f59; /* jmp 0x6e4f59 */
L_006e4f03:;
    (void)sub32(c, R32((uint32_t)(c->esi + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [esi + 0xc], 0 */
    if (c->zf) goto L_006e4f59; /* je 0x6e4f59 */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xe06d7363u); /* cmp dword ptr [eax], 0xe06d7363 */
    if (!c->zf) goto L_006e4f3d; /* jne 0x6e4f3d */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x14u)), c->edi); /* cmp dword ptr [eax + 0x14], edi */
    if ((c->cf || c->zf)) goto L_006e4f3d; /* jbe 0x6e4f3d */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x1cu))); /* mov ecx, dword ptr [eax + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov ecx, dword ptr [ecx + 8] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_006e4f3d; /* je 0x6e4f3d */
    c->edx = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0x24u))); /* movzx edx, byte ptr [ebp + 0x24] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = c->ecx; PUSH32(c, 0x006e4f38u); call_indirect(c, t_); } /* call ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    goto L_006e4f5c; /* jmp 0x6e4f5c */
L_006e4f3d:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x24u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x24] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e4f56u); f_006e4f60(c); /* call 0x6e4f60 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
L_006e4f59:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_006e4f5c:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_006e4f60(CPU *c) { /* FUN_10004f60 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffecu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp - 0x14], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x10], eax */
    if ((c->sf != c->of)) goto L_006e4f80; /* jl 0x6e4f80 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov ecx, dword ptr [ebp + 0x18] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ecx + 0x4u))); /* cmp eax, dword ptr [ecx + 4] */
    if ((c->sf != c->of)) goto L_006e4f85; /* jl 0x6e4f85 */
L_006e4f80:;
    PUSH32(c, 0x006e4f85u); f_006e5762(c); /* call 0x6e5762 */
L_006e4f85:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    c->ebx = (uint32_t)((uint32_t)0xe06d7363u); /* mov ebx, 0xe06d7363 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)((uint32_t)0x19930520u); /* mov edi, 0x19930520 */
    (void)sub32(c, R32((uint32_t)(c->esi)), c->ebx); /* cmp dword ptr [esi], ebx */
    if (!c->zf) goto L_006e50dc; /* jne 0x6e50dc */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [esi + 0x10], 3 */
    if (!c->zf) goto L_006e4ff9; /* jne 0x6e4ff9 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x14u)), c->edi); /* cmp dword ptr [esi + 0x14], edi */
    if (!c->zf) goto L_006e4ff9; /* jne 0x6e4ff9 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [esi + 0x1c], 0 */
    if (!c->zf) goto L_006e4ff9; /* jne 0x6e4ff9 */
    c->esi = (uint32_t)(R32((uint32_t)(0x777954u))); /* mov esi, dword ptr [0x10097954] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_006e50d7; /* je 0x6e50d7 */
    c->eax = (uint32_t)(R32((uint32_t)(0x777958u))); /* mov eax, dword ptr [0x10097958] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x10], eax */
    W8((uint32_t)(c->ebp + 0xffffffecu), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ebp - 0x14], 1 */
    PUSH32(c, 0x006e4fd0u); f_006e8304(c); /* call 0x6e8304 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_006e4fdb; /* jne 0x6e4fdb */
    PUSH32(c, 0x006e4fdbu); f_006e5762(c); /* call 0x6e5762 */
L_006e4fdb:;
    (void)sub32(c, R32((uint32_t)(c->esi)), c->ebx); /* cmp dword ptr [esi], ebx */
    if (!c->zf) goto L_006e50dc; /* jne 0x6e50dc */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [esi + 0x10], 3 */
    if (!c->zf) goto L_006e4ff9; /* jne 0x6e4ff9 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x14u)), c->edi); /* cmp dword ptr [esi + 0x14], edi */
    if (!c->zf) goto L_006e4ff9; /* jne 0x6e4ff9 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [esi + 0x1c], 0 */
    if (!c->zf) goto L_006e4ff9; /* jne 0x6e4ff9 */
    PUSH32(c, 0x006e4ff9u); f_006e5762(c); /* call 0x6e5762 */
L_006e4ff9:;
    (void)sub32(c, R32((uint32_t)(c->esi)), c->ebx); /* cmp dword ptr [esi], ebx */
    if (!c->zf) goto L_006e50dc; /* jne 0x6e50dc */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [esi + 0x10], 3 */
    if (!c->zf) goto L_006e50dc; /* jne 0x6e50dc */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x14u)), c->edi); /* cmp dword ptr [esi + 0x14], edi */
    if (!c->zf) goto L_006e50dc; /* jne 0x6e50dc */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov edi, dword ptr [ebp - 0x10] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe8u)); /* lea eax, [ebp - 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    PUSH32(c, 0x006e502bu); f_006e44c9(c); /* call 0x6e44c9 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
L_006e5030:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xffffffe8u))); /* cmp eax, dword ptr [ebp - 0x18] */
    if (!c->cf) goto L_006e50c7; /* jae 0x6e50c7 */
    (void)sub32(c, R32((uint32_t)(c->ebx)), c->edi); /* cmp dword ptr [ebx], edi */
    if ((!c->zf && c->sf == c->of)) goto L_006e50bc; /* jg 0x6e50bc */
    (void)sub32(c, c->edi, R32((uint32_t)(c->ebx + 0x4u))); /* cmp edi, dword ptr [ebx + 4] */
    if ((!c->zf && c->sf == c->of)) goto L_006e50bc; /* jg 0x6e50bc */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x10u))); /* mov eax, dword ptr [ebx + 0x10] */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xcu))); /* mov eax, dword ptr [ebx + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    if ((c->zf || c->sf != c->of)) goto L_006e50b9; /* jle 0x6e50b9 */
L_006e5055:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x1cu))); /* mov eax, dword ptr [esi + 0x1c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0xcu))); /* mov eax, dword ptr [eax + 0xc] */
    c->edi = (uint32_t)((uint32_t)(c->eax + 0x4u)); /* lea edi, [eax + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    if ((c->zf || c->sf != c->of)) goto L_006e5086; /* jle 0x6e5086 */
L_006e5067:;
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [esi + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->edi)); PUSH32(c, v_); } /* push dword ptr [edi] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x006e5074u); f_006e51af(c); /* call 0x6e51af */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006e5095; /* jne 0x6e5095 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 8] */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff8u)), c->eax); /* cmp dword ptr [ebp - 8], eax */
    if ((!c->zf && c->sf == c->of)) goto L_006e5067; /* jg 0x6e5067 */
L_006e5086:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff4u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x10u))); } /* add dword ptr [ebp + 8], 0x10 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0xc], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_006e5055; /* jg 0x6e5055 */
    goto L_006e50b9; /* jmp 0x6e50b9 */
L_006e5095:;
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
    PUSH32(c, 0x006e50b6u); f_006e52c0(c); /* call 0x6e52c0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
L_006e50b9:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov edi, dword ptr [ebp - 0x10] */
L_006e50bc:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x14u)); /* add ebx, 0x14 */
    goto L_006e5030; /* jmp 0x6e5030 */
L_006e50c7:;
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x1cu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0x1c], 0 */
    if (c->zf) goto L_006e50d7; /* je 0x6e50d7 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006e50d5u); f_006e5635(c); /* call 0x6e5635 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006e50d7:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e50dc:;
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x1cu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0x1c], 0 */
    if (!c->zf) goto L_006e5102; /* jne 0x6e5102 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x24u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffff0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006e50fdu); f_006e5107(c); /* call 0x6e5107 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    goto L_006e50d7; /* jmp 0x6e50d7 */
L_006e5102:;
    { f_006e570c(c); return; } /* jmp 0x6e570c */
}

void f_006e5107(CPU *c) { /* FUN_10005107 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    (void)sub32(c, R32((uint32_t)(0x77795cu)), (uint32_t)0x0u); /* cmp dword ptr [0x1009795c], 0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (c->zf) goto L_006e5138; /* je 0x6e5138 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x24u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x006e5131u); f_006e43a0(c); /* call 0x6e43a0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006e51ab; /* jne 0x6e51ab */
L_006e5138:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov edi, dword ptr [ebp + 0x1c] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    PUSH32(c, 0x006e514fu); f_006e44c9(c); /* call 0x6e44c9 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_006e5154:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xfffffff8u))); /* cmp eax, dword ptr [ebp - 8] */
    if (!c->cf) goto L_006e51ab; /* jae 0x6e51ab */
    (void)sub32(c, c->edi, R32((uint32_t)(c->esi))); /* cmp edi, dword ptr [esi] */
    if ((c->sf != c->of)) goto L_006e51a3; /* jl 0x6e51a3 */
    (void)sub32(c, c->edi, R32((uint32_t)(c->esi + 0x4u))); /* cmp edi, dword ptr [esi + 4] */
    if ((!c->zf && c->sf == c->of)) goto L_006e51a3; /* jg 0x6e51a3 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0xfffffff4u))); /* mov ecx, dword ptr [eax - 0xc] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_006e517d; /* je 0x6e517d */
    (void)sub8(c, R8((uint32_t)(c->ecx + 0x8u)), (uint8_t)0x0u); /* cmp byte ptr [ecx + 8], 0 */
    if (!c->zf) goto L_006e51a3; /* jne 0x6e51a3 */
L_006e517d:;
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
    PUSH32(c, 0x006e51a0u); f_006e52c0(c); /* call 0x6e52c0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
L_006e51a3:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x14u)); /* add esi, 0x14 */
    goto L_006e5154; /* jmp 0x6e5154 */
L_006e51ab:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006e51af(CPU *c) { /* FUN_100051af */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edi, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov eax, dword ptr [edi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e5206; /* je 0x6e5206 */
    (void)sub8(c, R8((uint32_t)(c->eax + 0x8u)), (uint8_t)0x0u); /* cmp byte ptr [eax + 8], 0 */
    c->edx = (uint32_t)((uint32_t)(c->eax + 0x8u)); /* lea edx, [eax + 8] */
    if (c->zf) goto L_006e5206; /* je 0x6e5206 */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (c->zf) goto L_006e51e0; /* je 0x6e51e0 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x8u)); /* add ecx, 8 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x006e51dau); f_006e5830(c); /* call 0x6e5830 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_006e5202; /* jne 0x6e5202 */
L_006e51e0:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi)) & (uint8_t)0x2u)); /* test byte ptr [esi], 2 */
    if (c->zf) goto L_006e51ea; /* je 0x6e51ea */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edi)) & (uint8_t)0x8u)); /* test byte ptr [edi], 8 */
    if (c->zf) goto L_006e5202; /* je 0x6e5202 */
L_006e51ea:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    if (c->zf) goto L_006e51f9; /* je 0x6e51f9 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edi)) & (uint8_t)0x1u)); /* test byte ptr [edi], 1 */
    if (c->zf) goto L_006e5202; /* je 0x6e5202 */
L_006e51f9:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x2u)); /* test al, 2 */
    if (c->zf) goto L_006e5206; /* je 0x6e5206 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edi)) & (uint8_t)0x2u)); /* test byte ptr [edi], 2 */
    if (!c->zf) goto L_006e5206; /* jne 0x6e5206 */
L_006e5202:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_006e5209; /* jmp 0x6e5209 */
L_006e5206:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_006e5209:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_006e520c(CPU *c) { /* FUN_1000520c */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x6ed3b8u; PUSH32(c, v_); } /* push 0x1000d3b8 */
    { uint32_t v_ = 0x6e835cu; PUSH32(c, v_); } /* push 0x1000835c */
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
L_006e523e:;
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0x14u))); /* cmp esi, dword ptr [ebp + 0x14] */
    if (c->zf) goto L_006e5298; /* je 0x6e5298 */
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if ((c->zf || c->sf != c->of)) goto L_006e524d; /* jle 0x6e524d */
    (void)sub32(c, c->esi, R32((uint32_t)(c->edi + 0x4u))); /* cmp esi, dword ptr [edi + 4] */
    if ((c->sf != c->of)) goto L_006e5252; /* jl 0x6e5252 */
L_006e524d:;
    PUSH32(c, 0x006e5252u); f_006e5762(c); /* call 0x6e5762 */
L_006e5252:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8 + 0x4u))); /* mov eax, dword ptr [eax + esi*8 + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e526d; /* je 0x6e526d */
    { uint32_t v_ = 0x103u; PUSH32(c, v_); } /* push 0x103 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e526du); f_006e56c0(c); /* call 0x6e56c0 */
L_006e526d:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    goto L_006e528d; /* jmp 0x6e528d */
L_006e528d:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8))); /* mov esi, dword ptr [eax + esi*8] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x1c], esi */
    goto L_006e523e; /* jmp 0x6e523e */
L_006e5298:;
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebx + 8], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006e523e(CPU *c) { /* PTR_006e523e */
    PREEMPT_POLL(c);
L_006e523e:;
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0x14u))); /* cmp esi, dword ptr [ebp + 0x14] */
    if (c->zf) goto L_006e5298; /* je 0x6e5298 */
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if ((c->zf || c->sf != c->of)) goto L_006e524d; /* jle 0x6e524d */
    (void)sub32(c, c->esi, R32((uint32_t)(c->edi + 0x4u))); /* cmp esi, dword ptr [edi + 4] */
    if ((c->sf != c->of)) goto L_006e5252; /* jl 0x6e5252 */
L_006e524d:;
    PUSH32(c, 0x006e5252u); f_006e5762(c); /* call 0x6e5762 */
L_006e5252:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8 + 0x4u))); /* mov eax, dword ptr [eax + esi*8 + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e526d; /* je 0x6e526d */
    { uint32_t v_ = 0x103u; PUSH32(c, v_); } /* push 0x103 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e526du); f_006e56c0(c); /* call 0x6e56c0 */
L_006e526d:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    goto L_006e528d; /* jmp 0x6e528d */
L_006e528d:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8))); /* mov esi, dword ptr [eax + esi*8] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x1c], esi */
    goto L_006e523e; /* jmp 0x6e523e */
L_006e5298:;
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebx + 8], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006e5273(CPU *c) { /* PTR_006e5273 */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffecu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x14] */
    PUSH32(c, 0x006e527bu); f_006e52aa(c); /* call 0x6e52aa */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_006e527d(CPU *c) { /* PTR_006e527d */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edi, dword ptr [ebp + 0x10] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov esi, dword ptr [ebp - 0x1c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8))); /* mov esi, dword ptr [eax + esi*8] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x1c], esi */
    { f_006e523e(c); return; } /* jmp 0x6e523e */
}

void f_006e52aa(CPU *c) { /* PTR_006e52aa */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xe06d7363u); /* cmp dword ptr [eax], 0xe06d7363 */
    if (c->zf) goto L_006e52bb; /* je 0x6e52bb */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_006e52bb:;
    { f_006e570c(c); return; } /* jmp 0x6e570c */
}

void f_006e52c0(CPU *c) { /* FUN_100052c0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x20u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x20], 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov ebx, dword ptr [ebp + 0x1c] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    if (c->zf) goto L_006e52e2; /* je 0x6e52e2 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x006e52dfu); f_006e5471(c); /* call 0x6e5471 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_006e52e2:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x2cu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x2c], 0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    if (!c->zf) goto L_006e52ee; /* jne 0x6e52ee */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    goto L_006e52f1; /* jmp 0x6e52f1 */
L_006e52ee:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x2cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x2c] */
L_006e52f1:;
    PUSH32(c, 0x006e52f6u); f_006e42a2(c); /* call 0x6e42a2 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x24u))); /* mov esi, dword ptr [ebp + 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006e5307u); f_006e520c(c); /* call 0x6e520c */
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
    PUSH32(c, 0x006e5328u); f_006e533b(c); /* call 0x6e533b */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e5336; /* je 0x6e5336 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e5336u); f_006e4260(c); /* call 0x6e4260 */
L_006e5336:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_006e533b(CPU *c) { /* FUN_1000533b */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x6ed3c8u; PUSH32(c, v_); } /* push 0x1000d3c8 */
    { uint32_t v_ = 0x6e835cu; PUSH32(c, v_); } /* push 0x1000835c */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x1cu)); /* sub esp, 0x1c */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov eax, dword ptr [ebp + 0x18] */
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x2c], eax */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x24], ebx */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0xfffffffcu))); /* mov ecx, dword ptr [esi - 4] */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 0x28], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(0x777954u))); /* mov ecx, dword ptr [0x10097954] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 0x1c], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(0x777958u))); /* mov ecx, dword ptr [0x10097958] */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 0x20], ecx */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    W32((uint32_t)(0x777954u), (uint32_t)(c->edi)); /* mov dword ptr [0x10097954], edi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    W32((uint32_t)(0x777958u), (uint32_t)(c->ecx)); /* mov dword ptr [0x10097958], ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 4], ebx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006e53b3u); f_006e4327(c); /* call 0x6e4327 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x2c], eax */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 4], ebx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x006e53c5u); f_006e5401(c); /* call 0x6e5401 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd4u))); /* mov eax, dword ptr [ebp - 0x2c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006e53c8(CPU *c) { /* PTR_006e53c8 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006e53d7(CPU *c) { /* PTR_006e53d7 */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffecu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x14] */
    PUSH32(c, 0x006e53dfu); f_006e5447(c); /* call 0x6e5447 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_006e53e1(CPU *c) { /* PTR_006e53e1 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffd4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x2c], 0 */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e53f3u); f_006e4586(c); /* call 0x6e4586 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { f_006e53c8(c); return; } /* jmp 0x6e53c8 */
}

void f_006e53f9(CPU *c) { /* PTR_006e53f9 */
    PREEMPT_POLL(c);
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    { f_006e5401(c); return; }
}

void f_006e5401(CPU *c) { /* FUN_10005401 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    W32((uint32_t)(c->esi + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [esi - 4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    W32((uint32_t)(0x777954u), (uint32_t)(c->eax)); /* mov dword ptr [0x10097954], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov eax, dword ptr [ebp - 0x20] */
    W32((uint32_t)(0x777958u), (uint32_t)(c->eax)); /* mov dword ptr [0x10097958], eax */
    (void)sub32(c, R32((uint32_t)(c->edi)), (uint32_t)0xe06d7363u); /* cmp dword ptr [edi], 0xe06d7363 */
    if (!c->zf) goto L_006e5446; /* jne 0x6e5446 */
    (void)sub32(c, R32((uint32_t)(c->edi + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [edi + 0x10], 3 */
    if (!c->zf) goto L_006e5446; /* jne 0x6e5446 */
    (void)sub32(c, R32((uint32_t)(c->edi + 0x14u)), (uint32_t)0x19930520u); /* cmp dword ptr [edi + 0x14], 0x19930520 */
    if (!c->zf) goto L_006e5446; /* jne 0x6e5446 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), c->ebx); /* cmp dword ptr [ebp - 0x24], ebx */
    if (!c->zf) goto L_006e5446; /* jne 0x6e5446 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd4u)), c->ebx); /* cmp dword ptr [ebp - 0x2c], ebx */
    if (c->zf) goto L_006e5446; /* je 0x6e5446 */
    PUSH32(c, 0x006e543du); f_006e45ee(c); /* call 0x6e45ee */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006e5444u); f_006e5635(c); /* call 0x6e5635 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006e5446:;
    c->esp += 4; return; /* ret  */
}

void f_006e5447(CPU *c) { /* PTR_006e5447 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xe06d7363u); /* cmp dword ptr [eax], 0xe06d7363 */
    if (!c->zf) goto L_006e546e; /* jne 0x6e546e */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [eax + 0x10], 3 */
    if (!c->zf) goto L_006e546e; /* jne 0x6e546e */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x14u)), (uint32_t)0x19930520u); /* cmp dword ptr [eax + 0x14], 0x19930520 */
    if (!c->zf) goto L_006e546e; /* jne 0x6e546e */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [eax + 0x1c], 0 */
    if (!c->zf) goto L_006e546e; /* jne 0x6e546e */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
L_006e546e:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_006e5471(CPU *c) { /* FUN_10005471 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x6ed3e0u; PUSH32(c, v_); } /* push 0x1000d3e0 */
    { uint32_t v_ = 0x6e835cu; PUSH32(c, v_); } /* push 0x1000835c */
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
    if (c->zf) goto L_006e561a; /* je 0x6e561a */
    (void)sub8(c, R8((uint32_t)(c->eax + 0x8u)), (uint8_t)0x0u); /* cmp byte ptr [eax + 8], 0 */
    if (c->zf) goto L_006e561a; /* je 0x6e561a */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov eax, dword ptr [ecx + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e561a; /* je 0x6e561a */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
    c->edi = (uint32_t)((uint32_t)(c->eax + c->edx + 0xcu)); /* lea edi, [eax + edx + 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ecx)) & (uint8_t)0x8u)); /* test byte ptr [ecx], 8 */
    if (c->zf) goto L_006e550e; /* je 0x6e550e */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x18] */
    PUSH32(c, 0x006e54d7u); f_006e8304(c); /* call 0x6e8304 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e5611; /* je 0x6e5611 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006e54e9u); f_006e8320(c); /* call 0x6e8320 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e5611; /* je 0x6e5611 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x18u))); /* mov eax, dword ptr [esi + 0x18] */
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov ecx, dword ptr [ebp + 0x14] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x8u)); /* add ecx, 8 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
L_006e54ff:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e5505u); f_006e569c(c); /* call 0x6e569c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    goto L_006e5616; /* jmp 0x6e5616 */
L_006e550e:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov esi, dword ptr [ebp + 0x14] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi)) & (uint8_t)0x1u)); /* test byte ptr [esi], 1 */
    if (c->zf) goto L_006e5568; /* je 0x6e5568 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    PUSH32(c, 0x006e5523u); f_006e8304(c); /* call 0x6e8304 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e5611; /* je 0x6e5611 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006e5535u); f_006e8320(c); /* call 0x6e8320 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e5611; /* je 0x6e5611 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x14u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006e554bu); f_006e7f40(c); /* call 0x6e7f40 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x14u)), (uint32_t)0x4u); /* cmp dword ptr [esi + 0x14], 4 */
    if (!c->zf) goto L_006e5616; /* jne 0x6e5616 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e5616; /* je 0x6e5616 */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x8u)); /* add esi, 8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    goto L_006e54ff; /* jmp 0x6e54ff */
L_006e5568:;
    (void)sub32(c, R32((uint32_t)(c->esi + 0x18u)), (uint32_t)0x0u); /* cmp dword ptr [esi + 0x18], 0 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    if (!c->zf) goto L_006e55b0; /* jne 0x6e55b0 */
    PUSH32(c, 0x006e557bu); f_006e8304(c); /* call 0x6e8304 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e5611; /* je 0x6e5611 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006e558du); f_006e8320(c); /* call 0x6e8320 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e5611; /* je 0x6e5611 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x14u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x14] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x8u)); /* add esi, 8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    PUSH32(c, 0x006e55a2u); f_006e569c(c); /* call 0x6e569c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006e55abu); f_006e7f40(c); /* call 0x6e7f40 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_006e5616; /* jmp 0x6e5616 */
L_006e55b0:;
    PUSH32(c, 0x006e55b5u); f_006e8304(c); /* call 0x6e8304 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e5611; /* je 0x6e5611 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006e55c3u); f_006e8320(c); /* call 0x6e8320 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e5611; /* je 0x6e5611 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x18] */
    PUSH32(c, 0x006e55d1u); f_006e833c(c); /* call 0x6e833c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e5611; /* je 0x6e5611 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi)) & (uint8_t)0x4u)); /* test byte ptr [esi], 4 */
    if (c->zf) goto L_006e55f7; /* je 0x6e55f7 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x8u)); /* lea eax, [esi + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    PUSH32(c, 0x006e55e9u); f_006e569c(c); /* call 0x6e569c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006e55f5u); f_006e429b(c); /* call 0x6e429b */
    goto L_006e5616; /* jmp 0x6e5616 */
L_006e55f7:;
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x8u)); /* lea eax, [esi + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    PUSH32(c, 0x006e5603u); f_006e569c(c); /* call 0x6e569c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006e560fu); f_006e4294(c); /* call 0x6e4294 */
    goto L_006e5616; /* jmp 0x6e5616 */
L_006e5611:;
    PUSH32(c, 0x006e5616u); f_006e5762(c); /* call 0x6e5762 */
L_006e5616:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
L_006e561a:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006e5629(CPU *c) { /* PTR_006e5629 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_006e562d(CPU *c) { /* PTR_006e562d */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { f_006e570c(c); return; } /* jmp 0x6e570c */
}

void f_006e5635(CPU *c) { /* FUN_10005635 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x6ed3f0u; PUSH32(c, v_); } /* push 0x1000d3f0 */
    { uint32_t v_ = 0x6e835cu; PUSH32(c, v_); } /* push 0x1000835c */
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
    if (c->zf) goto L_006e567c; /* je 0x6e567c */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x1cu))); /* mov ecx, dword ptr [eax + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ecx, dword ptr [ecx + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_006e567c; /* je 0x6e567c */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = R32((uint32_t)(c->eax + 0x18u)); PUSH32(c, v_); } /* push dword ptr [eax + 0x18] */
    PUSH32(c, 0x006e5678u); f_006e4294(c); /* call 0x6e4294 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
L_006e567c:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006e568b(CPU *c) { /* PTR_006e568b */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xcu)), ((uint8_t)c->eax)); /* cmp byte ptr [ebp + 0xc], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(!c->zf ? 1 : 0); /* setne al */
    c->esp += 4; return; /* ret  */
}

void f_006e5694(CPU *c) { /* PTR_006e5694 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { f_006e570c(c); return; } /* jmp 0x6e570c */
}

void f_006e569c(CPU *c) { /* FUN_1000569c */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov edx, dword ptr [ecx + 4] */
    c->eax = (uint32_t)(add32(c, c->eax, c->esi)); /* add eax, esi */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if ((c->sf != c->of)) goto L_006e56bd; /* jl 0x6e56bd */
    c->esi = (uint32_t)(R32((uint32_t)(c->edx + c->esi))); /* mov esi, dword ptr [edx + esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov ecx, dword ptr [ecx + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + c->ecx))); /* mov ecx, dword ptr [esi + ecx] */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->edx)); /* add ecx, edx */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
L_006e56bd:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_006e56c0(CPU *c) { /* __CallSettingFrame@12 */
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
    PUSH32(c, 0x006e56e3u); f_006e4611(c); /* call 0x6e4611 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = c->eax; PUSH32(c, 0x006e56e7u); call_indirect(c, t_); } /* call eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->ebx = (uint32_t)(c->ebp); /* mov ebx, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->ebx); /* mov ebp, ebx */
    (void)sub32(c, c->ecx, (uint32_t)0x100u); /* cmp ecx, 0x100 */
    if (!c->zf) goto L_006e56ff; /* jne 0x6e56ff */
    c->ecx = (uint32_t)((uint32_t)0x2u); /* mov ecx, 2 */
L_006e56ff:;
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x006e5705u); f_006e4611(c); /* call 0x6e4611 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 16; return; /* ret 0xc */
}

void f_006e570c(CPU *c) { /* FUN_1000570c */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x6ed400u; PUSH32(c, v_); } /* push 0x1000d400 */
    { uint32_t v_ = 0x6e835cu; PUSH32(c, v_); } /* push 0x1000835c */
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
    c->eax = (uint32_t)(R32((uint32_t)(0x777960u))); /* mov eax, dword ptr [0x10097960] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e5754; /* je 0x6e5754 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x006e5747u); call_indirect(c, t_); } /* call eax */
    goto L_006e5750; /* jmp 0x6e5750 */
L_006e5750:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
L_006e5754:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x006e575du); f_006e575d(c); /* call 0x6e575d */
    { f_006e8434(c); return; } /* jmp 0x6e8434 */
}

void f_006e5749(CPU *c) { /* PTR_006e5749 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_006e574d(CPU *c) { /* PTR_006e574d */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x006e575du); f_006e575d(c); /* call 0x6e575d */
    { f_006e8434(c); return; } /* jmp 0x6e8434 */
}

void f_006e575d(CPU *c) { /* PTR_006e575d */
    PREEMPT_POLL(c);
    { f_006e8434(c); return; } /* jmp 0x6e8434 */
}

void f_006e5762(CPU *c) { /* FUN_10005762 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x6ed418u; PUSH32(c, v_); } /* push 0x1000d418 */
    { uint32_t v_ = 0x6e835cu; PUSH32(c, v_); } /* push 0x1000835c */
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
    c->eax = (uint32_t)(R32((uint32_t)(0x6ee264u))); /* mov eax, dword ptr [0x1000e264] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e57aa; /* je 0x6e57aa */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x006e579du); call_indirect(c, t_); } /* call eax */
    goto L_006e57a6; /* jmp 0x6e57a6 */
L_006e57a6:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
L_006e57aa:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x006e57b3u); f_006e57b3(c); /* call 0x6e57b3 */
    { f_006e570c(c); return; } /* jmp 0x6e570c */
}

void f_006e579f(CPU *c) { /* PTR_006e579f */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_006e57a3(CPU *c) { /* PTR_006e57a3 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x006e57b3u); f_006e57b3(c); /* call 0x6e57b3 */
    { f_006e570c(c); return; } /* jmp 0x6e570c */
}

void f_006e57b3(CPU *c) { /* PTR_006e57b3 */
    PREEMPT_POLL(c);
    { f_006e570c(c); return; } /* jmp 0x6e570c */
}

void f_006e57b8(CPU *c) { /* FUN_100057b8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_006e581e; /* je 0x6e581e */
    c->eax = (uint32_t)(R32((uint32_t)(0x778ec8u))); /* mov eax, dword ptr [0x10098ec8] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_006e57e4; /* jne 0x6e57e4 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006e57d4u); f_006e8493(c); /* call 0x6e8493 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    if (c->zf) goto L_006e5810; /* je 0x6e5810 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e57e0u); f_006e84be(c); /* call 0x6e84be */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_006e581e; /* jmp 0x6e581e */
L_006e57e4:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_006e580f; /* jne 0x6e580f */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x8u)); /* lea eax, [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006e57f7u); f_006e91ee(c); /* call 0x6e91ee */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e580f; /* je 0x6e580f */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    PUSH32(c, 0x006e580au); f_006e9245(c); /* call 0x6e9245 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_006e581e; /* jmp 0x6e581e */
L_006e580f:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
L_006e5810:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x778ec4u)); PUSH32(c, v_); } /* push dword ptr [0x10098ec4] */
    { uint32_t t_ = R32((uint32_t)(0x6ed018u)); PUSH32(c, 0x006e581eu); call_indirect(c, t_); } /* call dword ptr [0x1000d018] */
L_006e581e:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006e5830(CPU *c) { /* _strcmp */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u)); /* test edx, 3 */
    if (!c->zf) goto L_006e587c; /* jne 0x6e587c */
L_006e5840:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edx))); /* mov eax, dword ptr [edx] */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->ecx))); /* cmp al, byte ptr [ecx] */
    if (!c->zf) goto L_006e5874; /* jne 0x6e5874 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_006e5870; /* je 0x6e5870 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), R8((uint32_t)(c->ecx + 0x1u))); /* cmp ah, byte ptr [ecx + 1] */
    if (!c->zf) goto L_006e5874; /* jne 0x6e5874 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | ((uint8_t)(c->eax >> 8))))) << 8); /* or ah, ah */
    if (c->zf) goto L_006e5870; /* je 0x6e5870 */
    c->eax = (uint32_t)(shr32(c, c->eax, 16)); /* shr eax, 0x10 */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->ecx + 0x2u))); /* cmp al, byte ptr [ecx + 2] */
    if (!c->zf) goto L_006e5874; /* jne 0x6e5874 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_006e5870; /* je 0x6e5870 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), R8((uint32_t)(c->ecx + 0x3u))); /* cmp ah, byte ptr [ecx + 3] */
    if (!c->zf) goto L_006e5874; /* jne 0x6e5874 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x4u)); /* add edx, 4 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | ((uint8_t)(c->eax >> 8))))) << 8); /* or ah, ah */
    if (!c->zf) goto L_006e5840; /* jne 0x6e5840 */
    c->edi = (uint32_t)(c->edi); /* mov edi, edi */
L_006e5870:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_006e5874:;
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(shl32(c, c->eax, 1)); /* shl eax, 1 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->esp += 4; return; /* ret  */
L_006e587c:;
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x1u)); /* test edx, 1 */
    if (c->zf) goto L_006e5898; /* je 0x6e5898 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov al, byte ptr [edx] */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->ecx))); /* cmp al, byte ptr [ecx] */
    if (!c->zf) goto L_006e5874; /* jne 0x6e5874 */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_006e5870; /* je 0x6e5870 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x2u)); /* test edx, 2 */
    if (c->zf) goto L_006e5840; /* je 0x6e5840 */
L_006e5898:;
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->edx))); /* mov ax, word ptr [edx] */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x2u)); /* add edx, 2 */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->ecx))); /* cmp al, byte ptr [ecx] */
    if (!c->zf) goto L_006e5874; /* jne 0x6e5874 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_006e5870; /* je 0x6e5870 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), R8((uint32_t)(c->ecx + 0x1u))); /* cmp ah, byte ptr [ecx + 1] */
    if (!c->zf) goto L_006e5874; /* jne 0x6e5874 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | ((uint8_t)(c->eax >> 8))))) << 8); /* or ah, ah */
    if (c->zf) goto L_006e5870; /* je 0x6e5870 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x2u)); /* add ecx, 2 */
    goto L_006e5840; /* jmp 0x6e5840 */
}

void f_006e58b4(CPU *c) { /* FUN_100058b4 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xe06d7363u); /* cmp dword ptr [eax], 0xe06d7363 */
    if (!c->zf) goto L_006e58d7; /* jne 0x6e58d7 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [eax + 0x10], 3 */
    if (!c->zf) goto L_006e58d7; /* jne 0x6e58d7 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x14u)), (uint32_t)0x19930520u); /* cmp dword ptr [eax + 0x14], 0x19930520 */
    if (!c->zf) goto L_006e58d7; /* jne 0x6e58d7 */
    { f_006e570c(c); return; } /* jmp 0x6e570c */
L_006e58d7:;
    c->eax = (uint32_t)(R32((uint32_t)(0x777964u))); /* mov eax, dword ptr [0x10097964] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e58f4; /* je 0x6e58f4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e58e6u); f_006e833c(c); /* call 0x6e833c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_006e58f4; /* je 0x6e58f4 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(0x777964u)); PUSH32(c, 0x006e58f2u); call_indirect(c, t_); } /* call dword ptr [0x10097964] */
    goto L_006e58f6; /* jmp 0x6e58f6 */
L_006e58f4:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_006e58f6:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_006e58fa(CPU *c) { /* PTR_006e58fa */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x6e58b4u; PUSH32(c, v_); } /* push 0x100058b4 */
    { uint32_t t_ = R32((uint32_t)(0x6ed01cu)); PUSH32(c, 0x006e5905u); call_indirect(c, t_); } /* call dword ptr [0x1000d01c] */
    W32((uint32_t)(0x777964u), (uint32_t)(c->eax)); /* mov dword ptr [0x10097964], eax */
    c->esp += 4; return; /* ret  */
}

void f_006e590b(CPU *c) { /* PTR_006e590b */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(0x777964u)); PUSH32(c, v_); } /* push dword ptr [0x10097964] */
    { uint32_t t_ = R32((uint32_t)(0x6ed01cu)); PUSH32(c, 0x006e5917u); call_indirect(c, t_); } /* call dword ptr [0x1000d01c] */
    c->esp += 4; return; /* ret  */
}

void f_006e5918(CPU *c) { /* FUN_10005918 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_006e5933; /* jne 0x6e5933 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x006e592du); f_006e5d19(c); /* call 0x6e5d19 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_006e5bb3; /* jmp 0x6e5bb3 */
L_006e5933:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_006e5948; /* jne 0x6e5948 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x006e5942u); f_006e57b8(c); /* call 0x6e57b8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_006e5bb1; /* jmp 0x6e5bb1 */
L_006e5948:;
    c->eax = (uint32_t)(R32((uint32_t)(0x778ec8u))); /* mov eax, dword ptr [0x10098ec8] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_006e5a58; /* jne 0x6e5a58 */
L_006e5956:;
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_006e5a34; /* ja 0x6e5a34 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x006e5969u); f_006e8493(c); /* call 0x6e8493 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (c->zf) goto L_006e5a0f; /* je 0x6e5a0f */
    (void)sub32(c, c->esi, R32((uint32_t)(0x778dbcu))); /* cmp esi, dword ptr [0x10098dbc] */
    if ((!c->cf && !c->zf)) goto L_006e59c8; /* ja 0x6e59c8 */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x006e5987u); f_006e8c9c(c); /* call 0x6e8c9c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006e59c4; /* jne 0x6e59c4 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006e5994u); f_006e87e7(c); /* call 0x6e87e7 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_006e59c8; /* je 0x6e59c8 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xfffffffcu))); /* mov eax, dword ptr [ebx - 4] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_006e59a8; /* jb 0x6e59a8 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_006e59a8:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006e59b0u); f_006e9680(c); /* call 0x6e9680 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x006e59b6u); f_006e8493(c); /* call 0x6e8493 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x006e59c1u); f_006e84be(c); /* call 0x6e84be */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_006e59c4:;
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (!c->zf) goto L_006e5a0b; /* jne 0x6e5a0b */
L_006e59c8:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_006e59cf; /* jne 0x6e59cf */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_006e59cf:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x778ec4u)); PUSH32(c, v_); } /* push dword ptr [0x10098ec4] */
    { uint32_t t_ = R32((uint32_t)(0x6ed024u)); PUSH32(c, 0x006e59e4u); call_indirect(c, t_); } /* call dword ptr [0x1000d024] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_006e5a0b; /* je 0x6e5a0b */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0xfffffffcu))); /* mov eax, dword ptr [ecx - 4] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_006e59f7; /* jb 0x6e59f7 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_006e59f7:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006e59ffu); f_006e9680(c); /* call 0x6e9680 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x006e5a08u); f_006e84be(c); /* call 0x6e84be */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
L_006e5a0b:;
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (!c->zf) goto L_006e5a30; /* jne 0x6e5a30 */
L_006e5a0f:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_006e5a16; /* jne 0x6e5a16 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_006e5a16:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x778ec4u)); PUSH32(c, v_); } /* push dword ptr [0x10098ec4] */
    { uint32_t t_ = R32((uint32_t)(0x6ed020u)); PUSH32(c, 0x006e5a2eu); call_indirect(c, t_); } /* call dword ptr [0x1000d020] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
L_006e5a30:;
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (!c->zf) goto L_006e5a51; /* jne 0x6e5a51 */
L_006e5a34:;
    (void)sub32(c, R32((uint32_t)(0x777b00u)), (uint32_t)0x0u); /* cmp dword ptr [0x10097b00], 0 */
    if (c->zf) goto L_006e5a51; /* je 0x6e5a51 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006e5a43u); f_006e965f(c); /* call 0x6e965f */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_006e5956; /* jne 0x6e5956 */
    goto L_006e5bb1; /* jmp 0x6e5bb1 */
L_006e5a51:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    goto L_006e5bb3; /* jmp 0x6e5bb3 */
L_006e5a58:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_006e5b73; /* jne 0x6e5b73 */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_006e5a75; /* ja 0x6e5a75 */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if ((c->cf || c->zf)) goto L_006e5a72; /* jbe 0x6e5a72 */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    goto L_006e5a75; /* jmp 0x6e5a75 */
L_006e5a72:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_006e5a75:;
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_006e5b55; /* ja 0x6e5b55 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xcu)); /* lea eax, [ebp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x006e5a90u); f_006e91ee(c); /* call 0x6e91ee */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (c->zf) goto L_006e5b39; /* je 0x6e5b39 */
    (void)sub32(c, c->esi, R32((uint32_t)(0x6f0584u))); /* cmp esi, dword ptr [0x10010584] */
    if (!c->cf) goto L_006e5afd; /* jae 0x6e5afd */
    c->edi = (uint32_t)(c->esi); /* mov edi, esi */
    c->edi = (uint32_t)(shr32(c, c->edi, 4)); /* shr edi, 4 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    PUSH32(c, 0x006e5ab7u); f_006e95b6(c); /* call 0x6e95b6 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e5ac3; /* je 0x6e5ac3 */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    goto L_006e5af5; /* jmp 0x6e5af5 */
L_006e5ac3:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006e5ac9u); f_006e928a(c); /* call 0x6e928a */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_006e5afd; /* je 0x6e5afd */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->ebx))); /* movzx eax, byte ptr [ebx] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_006e5adc; /* jb 0x6e5adc */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_006e5adc:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006e5ae6u); f_006e9680(c); /* call 0x6e9680 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    PUSH32(c, 0x006e5af2u); f_006e9245(c); /* call 0x6e9245 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_006e5af5:;
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (!c->zf) goto L_006e5a51; /* jne 0x6e5a51 */
L_006e5afd:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x778ec4u)); PUSH32(c, v_); } /* push dword ptr [0x10098ec4] */
    { uint32_t t_ = R32((uint32_t)(0x6ed024u)); PUSH32(c, 0x006e5b0cu); call_indirect(c, t_); } /* call dword ptr [0x1000d024] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_006e5b55; /* je 0x6e5b55 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->ebx))); /* movzx eax, byte ptr [ebx] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_006e5b1e; /* jb 0x6e5b1e */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_006e5b1e:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006e5b28u); f_006e9680(c); /* call 0x6e9680 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    PUSH32(c, 0x006e5b34u); f_006e9245(c); /* call 0x6e9245 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_006e5b4d; /* jmp 0x6e5b4d */
L_006e5b39:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x778ec4u)); PUSH32(c, v_); } /* push dword ptr [0x10098ec4] */
    { uint32_t t_ = R32((uint32_t)(0x6ed020u)); PUSH32(c, 0x006e5b4bu); call_indirect(c, t_); } /* call dword ptr [0x1000d020] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
L_006e5b4d:;
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (!c->zf) goto L_006e5a51; /* jne 0x6e5a51 */
L_006e5b55:;
    (void)sub32(c, R32((uint32_t)(0x777b00u)), (uint32_t)0x0u); /* cmp dword ptr [0x10097b00], 0 */
    if (c->zf) goto L_006e5a51; /* je 0x6e5a51 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006e5b68u); f_006e965f(c); /* call 0x6e965f */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_006e5a75; /* jne 0x6e5a75 */
    goto L_006e5bb1; /* jmp 0x6e5bb1 */
L_006e5b73:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_006e5b9d; /* ja 0x6e5b9d */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_006e5b81; /* jne 0x6e5b81 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_006e5b81:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x778ec4u)); PUSH32(c, v_); } /* push dword ptr [0x10098ec4] */
    { uint32_t t_ = R32((uint32_t)(0x6ed020u)); PUSH32(c, 0x006e5b99u); call_indirect(c, t_); } /* call dword ptr [0x1000d020] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006e5bb3; /* jne 0x6e5bb3 */
L_006e5b9d:;
    (void)sub32(c, R32((uint32_t)(0x777b00u)), (uint32_t)0x0u); /* cmp dword ptr [0x10097b00], 0 */
    if (c->zf) goto L_006e5bb3; /* je 0x6e5bb3 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006e5bacu); f_006e965f(c); /* call 0x6e965f */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_006e5b73; /* jne 0x6e5b73 */
L_006e5bb1:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_006e5bb3:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006e5bb8(CPU *c) { /* FUN_10005bb8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x6ee204u))); /* mov eax, dword ptr [0x1000e204] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e5bc3; /* je 0x6e5bc3 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x006e5bc3u); call_indirect(c, t_); } /* call eax */
L_006e5bc3:;
    { uint32_t v_ = 0x6ee028u; PUSH32(c, v_); } /* push 0x1000e028 */
    { uint32_t v_ = 0x6ee014u; PUSH32(c, v_); } /* push 0x1000e014 */
    PUSH32(c, 0x006e5bd2u); f_006e5c9e(c); /* call 0x6e5c9e */
    { uint32_t v_ = 0x6ee010u; PUSH32(c, v_); } /* push 0x1000e010 */
    { uint32_t v_ = 0x6ee000u; PUSH32(c, v_); } /* push 0x1000e000 */
    PUSH32(c, 0x006e5be1u); f_006e5c9e(c); /* call 0x6e5c9e */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_006e5be5(CPU *c) { /* __exit */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    PUSH32(c, 0x006e5bf2u); f_006e5c05(c); /* call 0x6e5c05 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_006e5bf6(CPU *c) { /* FUN_10005bf6 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    PUSH32(c, 0x006e5c01u); f_006e5c05(c); /* call 0x6e5c05 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_006e5c05(CPU *c) { /* FUN_10005c05 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    (void)sub32(c, R32((uint32_t)(0x7779b0u)), c->edi); /* cmp dword ptr [0x100979b0], edi */
    if (!c->zf) goto L_006e5c22; /* jne 0x6e5c22 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    { uint32_t t_ = R32((uint32_t)(0x6ed030u)); PUSH32(c, 0x006e5c1bu); call_indirect(c, t_); } /* call dword ptr [0x1000d030] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x6ed02cu)); PUSH32(c, 0x006e5c22u); call_indirect(c, t_); } /* call dword ptr [0x1000d02c] */
L_006e5c22:;
    (void)sub32(c, R32((uint32_t)(c->esp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [esp + 0xc], 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ebx, dword ptr [esp + 0x14] */
    W32((uint32_t)(0x7779acu), (uint32_t)(c->edi)); /* mov dword ptr [0x100979ac], edi */
    W8((uint32_t)(0x7779a8u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [0x100979a8], bl */
    if (!c->zf) goto L_006e5c76; /* jne 0x6e5c76 */
    c->eax = (uint32_t)(R32((uint32_t)(0x778ed8u))); /* mov eax, dword ptr [0x10098ed8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e5c65; /* je 0x6e5c65 */
    c->ecx = (uint32_t)(R32((uint32_t)(0x778ed4u))); /* mov ecx, dword ptr [0x10098ed4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)((uint32_t)(c->ecx + 0xfffffffcu)); /* lea esi, [ecx - 4] */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if (c->cf) goto L_006e5c64; /* jb 0x6e5c64 */
L_006e5c51:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e5c59; /* je 0x6e5c59 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x006e5c59u); call_indirect(c, t_); } /* call eax */
L_006e5c59:;
    c->esi = (uint32_t)(sub32(c, c->esi, (uint32_t)0x4u)); /* sub esi, 4 */
    (void)sub32(c, c->esi, R32((uint32_t)(0x778ed8u))); /* cmp esi, dword ptr [0x10098ed8] */
    if (!c->cf) goto L_006e5c51; /* jae 0x6e5c51 */
L_006e5c64:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_006e5c65:;
    { uint32_t v_ = 0x6ee034u; PUSH32(c, v_); } /* push 0x1000e034 */
    { uint32_t v_ = 0x6ee02cu; PUSH32(c, v_); } /* push 0x1000e02c */
    PUSH32(c, 0x006e5c74u); f_006e5c9e(c); /* call 0x6e5c9e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006e5c76:;
    { uint32_t v_ = 0x6ee040u; PUSH32(c, v_); } /* push 0x1000e040 */
    { uint32_t v_ = 0x6ee038u; PUSH32(c, v_); } /* push 0x1000e038 */
    PUSH32(c, 0x006e5c85u); f_006e5c9e(c); /* call 0x6e5c9e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    if (!c->zf) goto L_006e5c9c; /* jne 0x6e5c9c */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    W32((uint32_t)(0x7779b0u), (uint32_t)(c->edi)); /* mov dword ptr [0x100979b0], edi */
    { uint32_t t_ = R32((uint32_t)(0x6ed028u)); PUSH32(c, 0x006e5c9cu); call_indirect(c, t_); } /* call dword ptr [0x1000d028] */
L_006e5c9c:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_006e5c9e(CPU *c) { /* FUN_10005c9e */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
L_006e5ca3:;
    (void)sub32(c, c->esi, R32((uint32_t)(c->esp + 0xcu))); /* cmp esi, dword ptr [esp + 0xc] */
    if (!c->cf) goto L_006e5cb6; /* jae 0x6e5cb6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e5cb1; /* je 0x6e5cb1 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x006e5cb1u); call_indirect(c, t_); } /* call eax */
L_006e5cb1:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    goto L_006e5ca3; /* jmp 0x6e5ca3 */
L_006e5cb6:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_006e5cb8(CPU *c) { /* FUN_10005cb8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(0x778ec8u))); /* mov eax, dword ptr [0x10098ec8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_006e5ce1; /* jne 0x6e5ce1 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006e5cd1u); f_006e8493(c); /* call 0x6e8493 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_006e5cde; /* je 0x6e5cde */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xfffffffcu))); /* mov eax, dword ptr [esi - 4] */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x9u)); /* sub eax, 9 */
    goto L_006e5d16; /* jmp 0x6e5d16 */
L_006e5cde:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    goto L_006e5d08; /* jmp 0x6e5d08 */
L_006e5ce1:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_006e5d05; /* jne 0x6e5d05 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x006e5cf6u); f_006e91ee(c); /* call 0x6e91ee */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e5d05; /* je 0x6e5d05 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->eax))); /* movzx eax, byte ptr [eax] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    goto L_006e5d16; /* jmp 0x6e5d16 */
L_006e5d05:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
L_006e5d08:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x778ec4u)); PUSH32(c, v_); } /* push dword ptr [0x10098ec4] */
    { uint32_t t_ = R32((uint32_t)(0x6ed034u)); PUSH32(c, 0x006e5d16u); call_indirect(c, t_); } /* call dword ptr [0x1000d034] */
L_006e5d16:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006e5d19(CPU *c) { /* _malloc */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(0x777b00u)); PUSH32(c, v_); } /* push dword ptr [0x10097b00] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    PUSH32(c, 0x006e5d28u); f_006e5d2b(c); /* call 0x6e5d2b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_006e5d2b(CPU *c) { /* __nh_malloc */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->esp + 0x4u)), (uint32_t)0xffffffe0u); /* cmp dword ptr [esp + 4], -0x20 */
    if ((!c->cf && !c->zf)) goto L_006e5d54; /* ja 0x6e5d54 */
L_006e5d32:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    PUSH32(c, 0x006e5d3bu); f_006e5d57(c); /* call 0x6e5d57 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_006e5d56; /* jne 0x6e5d56 */
    (void)sub32(c, R32((uint32_t)(c->esp + 0x8u)), c->eax); /* cmp dword ptr [esp + 8], eax */
    if (c->zf) goto L_006e5d56; /* je 0x6e5d56 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    PUSH32(c, 0x006e5d4fu); f_006e965f(c); /* call 0x6e965f */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_006e5d32; /* jne 0x6e5d32 */
L_006e5d54:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_006e5d56:;
    c->esp += 4; return; /* ret  */
}

void f_006e5d57(CPU *c) { /* FUN_10005d57 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x778ec8u))); /* mov eax, dword ptr [0x10098ec8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_006e5d7b; /* jne 0x6e5d7b */
    (void)sub32(c, c->esi, R32((uint32_t)(0x778dbcu))); /* cmp esi, dword ptr [0x10098dbc] */
    if ((!c->cf && !c->zf)) goto L_006e5dad; /* ja 0x6e5dad */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006e5d74u); f_006e87e7(c); /* call 0x6e87e7 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_006e5dad; /* je 0x6e5dad */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_006e5d7b:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_006e5dad; /* jne 0x6e5dad */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e5d90; /* je 0x6e5d90 */
    c->esi = (uint32_t)((uint32_t)(c->eax + 0xfu)); /* lea esi, [eax + 0xf] */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    goto L_006e5d93; /* jmp 0x6e5d93 */
L_006e5d90:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_006e5d93:;
    (void)sub32(c, c->esi, R32((uint32_t)(0x6f0584u))); /* cmp esi, dword ptr [0x10010584] */
    if ((!c->cf && !c->zf)) goto L_006e5dba; /* ja 0x6e5dba */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e5da6u); f_006e928a(c); /* call 0x6e928a */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_006e5dc9; /* jne 0x6e5dc9 */
    goto L_006e5dba; /* jmp 0x6e5dba */
L_006e5dad:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_006e5db4; /* jne 0x6e5db4 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_006e5db4:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
L_006e5dba:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x778ec4u)); PUSH32(c, v_); } /* push dword ptr [0x10098ec4] */
    { uint32_t t_ = R32((uint32_t)(0x6ed024u)); PUSH32(c, 0x006e5dc9u); call_indirect(c, t_); } /* call dword ptr [0x1000d024] */
L_006e5dc9:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_006e5dcb(CPU *c) { /* FUN_10005dcb */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edi, dword ptr [esp + 0x14] */
    (void)sub32(c, c->edi, R32((uint32_t)(0x778ec0u))); /* cmp edi, dword ptr [0x10098ec0] */
    if (!c->cf) goto L_006e5e65; /* jae 0x6e5e65 */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->esi = (uint32_t)(c->edi); /* mov esi, edi */
    c->eax = (uint32_t)(sar32(c, c->eax, 5)); /* sar eax, 5 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0x1fu))); /* and esi, 0x1f */
    c->ebx = (uint32_t)((uint32_t)(c->eax * 4 + 0x778dc0u)); /* lea ebx, [eax*4 + 0x10098dc0] */
    c->esi = (uint32_t)(shl32(c, c->esi, 3)); /* shl esi, 3 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + c->esi + 0x4u)) & (uint8_t)0x1u)); /* test byte ptr [eax + esi + 4], 1 */
    if (c->zf) goto L_006e5e65; /* je 0x6e5e65 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006e5e02u); f_006e9ba2(c); /* call 0x6e9ba2 */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_006e5e44; /* je 0x6e5e44 */
    (void)sub32(c, c->edi, (uint32_t)0x1u); /* cmp edi, 1 */
    if (c->zf) goto L_006e5e12; /* je 0x6e5e12 */
    (void)sub32(c, c->edi, (uint32_t)0x2u); /* cmp edi, 2 */
    if (!c->zf) goto L_006e5e28; /* jne 0x6e5e28 */
L_006e5e12:;
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    PUSH32(c, 0x006e5e19u); f_006e9ba2(c); /* call 0x6e9ba2 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ebp = (uint32_t)(c->eax); /* mov ebp, eax */
    PUSH32(c, 0x006e5e22u); f_006e9ba2(c); /* call 0x6e9ba2 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->eax, c->ebp); /* cmp eax, ebp */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_006e5e44; /* je 0x6e5e44 */
L_006e5e28:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006e5e2eu); f_006e9ba2(c); /* call 0x6e9ba2 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x6ed03cu)); PUSH32(c, 0x006e5e36u); call_indirect(c, t_); } /* call dword ptr [0x1000d03c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006e5e44; /* jne 0x6e5e44 */
    { uint32_t t_ = R32((uint32_t)(0x6ed038u)); PUSH32(c, 0x006e5e40u); call_indirect(c, t_); } /* call dword ptr [0x1000d038] */
    c->ebp = (uint32_t)(c->eax); /* mov ebp, eax */
    goto L_006e5e46; /* jmp 0x6e5e46 */
L_006e5e44:;
    c->ebp = (uint32_t)(logic32(c, 0)); /* xor ebp, ebp */
L_006e5e46:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006e5e4cu); f_006e9b28(c); /* call 0x6e9b28 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t a_ = (uint32_t)(c->eax + c->esi + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax + esi + 4], 0 */
    (void)logic32(c, (uint32_t)(c->ebp & c->ebp)); /* test ebp, ebp */
    if (c->zf) goto L_006e5e61; /* je 0x6e5e61 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x006e5e5eu); f_006e99b5(c); /* call 0x6e99b5 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_006e5e76; /* jmp 0x6e5e76 */
L_006e5e61:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_006e5e79; /* jmp 0x6e5e79 */
L_006e5e65:;
    { uint32_t a_ = (uint32_t)(0x77796cu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [0x1009796c], 0 */
    W32((uint32_t)(0x777968u), (uint32_t)((uint32_t)0x9u)); /* mov dword ptr [0x10097968], 9 */
L_006e5e76:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
L_006e5e79:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_006e5e7e(CPU *c) { /* __freebuf */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x83u)); /* test al, 0x83 */
    if (c->zf) goto L_006e5ea7; /* je 0x6e5ea7 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x8u)); /* test al, 8 */
    if (c->zf) goto L_006e5ea7; /* je 0x6e5ea7 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esi + 8] */
    PUSH32(c, 0x006e5e96u); f_006e57b8(c); /* call 0x6e57b8 */
    { uint32_t a_ = (uint32_t)(c->esi + 0xcu); W16(a_, (uint16_t)(logic16(c, (uint16_t)(R16(a_) & (uint16_t)0xfbf7u)))); } /* and word ptr [esi + 0xc], 0xfbf7 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 8], eax */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 4], eax */
L_006e5ea7:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_006e5ea9(CPU *c) { /* FUN_10005ea9 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_006e5ebb; /* jne 0x6e5ebb */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006e5eb8u); f_006e5f49(c); /* call 0x6e5f49 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_006e5ebb:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006e5ec1u); f_006e5ee4(c); /* call 0x6e5ee4 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_006e5ecb; /* je 0x6e5ecb */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_006e5ecb:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi + 0xdu)) & (uint8_t)0x40u)); /* test byte ptr [esi + 0xd], 0x40 */
    if (c->zf) goto L_006e5ee0; /* je 0x6e5ee0 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x10] */
    PUSH32(c, 0x006e5ed9u); f_006e9bdf(c); /* call 0x6e9bdf */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->esp += 4; return; /* ret  */
L_006e5ee0:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_006e5ee4(CPU *c) { /* FUN_10005ee4 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov esi, dword ptr [esp + 0xc] */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u))); /* and ecx, 3 */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x2u); /* cmp cl, 2 */
    if (!c->zf) goto L_006e5f31; /* jne 0x6e5f31 */
    (void)logic16(c, (uint16_t)(((uint16_t)c->eax) & (uint16_t)0x108u)); /* test ax, 0x108 */
    if (c->zf) goto L_006e5f31; /* je 0x6e5f31 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edi, dword ptr [esi] */
    c->edi = (uint32_t)(sub32(c, c->edi, c->eax)); /* sub edi, eax */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if ((c->zf || c->sf != c->of)) goto L_006e5f31; /* jle 0x6e5f31 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x10] */
    PUSH32(c, 0x006e5f15u); f_006e9c36(c); /* call 0x6e9c36 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_006e5f2a; /* jne 0x6e5f2a */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x80u)); /* test al, 0x80 */
    if (c->zf) goto L_006e5f31; /* je 0x6e5f31 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfdu))); /* and al, 0xfd */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xc], eax */
    goto L_006e5f31; /* jmp 0x6e5f31 */
L_006e5f2a:;
    { uint32_t a_ = (uint32_t)(c->esi + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x20u)))); } /* or dword ptr [esi + 0xc], 0x20 */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | (uint32_t)0xffffffffu))); /* or ebx, 0xffffffff */
L_006e5f31:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi + 4], 0 */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_006e5f40(CPU *c) { /* PTR_006e5f40 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x006e5f47u); f_006e5f49(c); /* call 0x6e5f49 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_006e5f49(CPU *c) { /* flsall */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, R32((uint32_t)(0x778da0u)), c->esi); /* cmp dword ptr [0x10098da0], esi */
    if ((c->zf || c->sf != c->of)) goto L_006e5fa7; /* jle 0x6e5fa7 */
L_006e5f5a:;
    c->eax = (uint32_t)(R32((uint32_t)(0x777d88u))); /* mov eax, dword ptr [0x10097d88] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 4))); /* mov eax, dword ptr [eax + esi*4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e5f9e; /* je 0x6e5f9e */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0xcu))); /* mov ecx, dword ptr [eax + 0xc] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x83u)); /* test cl, 0x83 */
    if (c->zf) goto L_006e5f9e; /* je 0x6e5f9e */
    (void)sub32(c, R32((uint32_t)(c->esp + 0x10u)), (uint32_t)0x1u); /* cmp dword ptr [esp + 0x10], 1 */
    if (!c->zf) goto L_006e5f84; /* jne 0x6e5f84 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e5f7bu); f_006e5ea9(c); /* call 0x6e5ea9 */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_006e5f9e; /* je 0x6e5f9e */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    goto L_006e5f9e; /* jmp 0x6e5f9e */
L_006e5f84:;
    (void)sub32(c, R32((uint32_t)(c->esp + 0x10u)), (uint32_t)0x0u); /* cmp dword ptr [esp + 0x10], 0 */
    if (!c->zf) goto L_006e5f9e; /* jne 0x6e5f9e */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x2u)); /* test cl, 2 */
    if (c->zf) goto L_006e5f9e; /* je 0x6e5f9e */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e5f96u); f_006e5ea9(c); /* call 0x6e5ea9 */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_006e5f9e; /* jne 0x6e5f9e */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi | c->eax))); /* or edi, eax */
L_006e5f9e:;
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub32(c, c->esi, R32((uint32_t)(0x778da0u))); /* cmp esi, dword ptr [0x10098da0] */
    if ((c->sf != c->of)) goto L_006e5f5a; /* jl 0x6e5f5a */
L_006e5fa7:;
    (void)sub32(c, R32((uint32_t)(c->esp + 0x10u)), (uint32_t)0x1u); /* cmp dword ptr [esp + 0x10], 1 */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    if (c->zf) goto L_006e5fb2; /* je 0x6e5fb2 */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
L_006e5fb2:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_006e5fb6(CPU *c) { /* FUN_10005fb6 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x10] */
    PUSH32(c, 0x006e5fc3u); f_006e9e9c(c); /* call 0x6e9e9c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_006e603f; /* je 0x6e603f */
    (void)sub32(c, c->esi, (uint32_t)0x6f0718u); /* cmp esi, 0x10010718 */
    if (!c->zf) goto L_006e5fd4; /* jne 0x6e5fd4 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_006e5fdf; /* jmp 0x6e5fdf */
L_006e5fd4:;
    (void)sub32(c, c->esi, (uint32_t)0x6f0738u); /* cmp esi, 0x10010738 */
    if (!c->zf) goto L_006e603f; /* jne 0x6e603f */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_006e5fdf:;
    { uint32_t a_ = (uint32_t)(0x777b04u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [0x10097b04] */
    (void)logic16(c, (uint16_t)(R16((uint32_t)(c->esi + 0xcu)) & (uint16_t)0x10cu)); /* test word ptr [esi + 0xc], 0x10c */
    if (!c->zf) goto L_006e603f; /* jne 0x6e603f */
    (void)sub32(c, R32((uint32_t)(c->eax * 4 + 0x7779b4u)), (uint32_t)0x0u); /* cmp dword ptr [eax*4 + 0x100979b4], 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)((uint32_t)(c->eax * 4 + 0x7779b4u)); /* lea edi, [eax*4 + 0x100979b4] */
    c->ebx = (uint32_t)((uint32_t)0x1000u); /* mov ebx, 0x1000 */
    if (!c->zf) goto L_006e6025; /* jne 0x6e6025 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x006e600bu); f_006e5d19(c); /* call 0x6e5d19 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    if (!c->zf) goto L_006e6025; /* jne 0x6e6025 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x14u)); /* lea eax, [esi + 0x14] */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 8], eax */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    W32((uint32_t)(c->esi + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x18], eax */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 4], eax */
    goto L_006e6032; /* jmp 0x6e6032 */
L_006e6025:;
    c->edi = (uint32_t)(R32((uint32_t)(c->edi))); /* mov edi, dword ptr [edi] */
    W32((uint32_t)(c->esi + 0x18u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x18], ebx */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 8], edi */
    W32((uint32_t)(c->esi), (uint32_t)(c->edi)); /* mov dword ptr [esi], edi */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 4], ebx */
L_006e6032:;
    { uint32_t a_ = (uint32_t)(c->esi + 0xcu); W16(a_, (uint16_t)(logic16(c, (uint16_t)(R16(a_) | (uint16_t)0x1102u)))); } /* or word ptr [esi + 0xc], 0x1102 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_006e603f:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_006e6043(CPU *c) { /* FUN_10006043 */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->esp + 0x4u)), (uint32_t)0x0u); /* cmp dword ptr [esp + 4], 0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    if (c->zf) goto L_006e606d; /* je 0x6e606d */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov esi, dword ptr [esp + 0xc] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi + 0xdu)) & (uint8_t)0x10u)); /* test byte ptr [esi + 0xd], 0x10 */
    if (c->zf) goto L_006e607e; /* je 0x6e607e */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006e605bu); f_006e5ee4(c); /* call 0x6e5ee4 */
    { uint32_t a_ = (uint32_t)(c->esi + 0xdu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0xeeu)))); } /* and byte ptr [esi + 0xd], 0xee */
    { uint32_t a_ = (uint32_t)(c->esi + 0x18u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi + 0x18], 0 */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi], 0 */
    { uint32_t a_ = (uint32_t)(c->esi + 0x8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi + 8], 0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_006e606d:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + 0xdu)) & (uint8_t)0x10u)); /* test byte ptr [eax + 0xd], 0x10 */
    if (c->zf) goto L_006e607e; /* je 0x6e607e */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e607du); f_006e5ee4(c); /* call 0x6e5ee4 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006e607e:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_006e6080(CPU *c) { /* FUN_10006080 */
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
    if (c->zf) goto L_006e6799; /* je 0x6e6799 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    goto L_006e60b4; /* jmp 0x6e60b4 */
L_006e60ac:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd0u))); /* mov esi, dword ptr [ebp - 0x30] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
L_006e60b4:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffecu)), c->edx); /* cmp dword ptr [ebp - 0x14], edx */
    if ((c->sf != c->of)) goto L_006e6799; /* jl 0x6e6799 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x20u); /* cmp bl, 0x20 */
    if ((c->sf != c->of)) goto L_006e60d5; /* jl 0x6e60d5 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x78u); /* cmp bl, 0x78 */
    if ((!c->zf && c->sf == c->of)) goto L_006e60d5; /* jg 0x6e60d5 */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx eax, bl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x6ed410u))); /* mov al, byte ptr [eax + 0x1000d410] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xfu))); /* and eax, 0xf */
    goto L_006e60d7; /* jmp 0x6e60d7 */
L_006e60d5:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_006e60d7:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->esi + c->eax * 8 + 0x6ed430u))); /* movsx eax, byte ptr [esi + eax*8 + 0x1000d430] */
    c->eax = (uint32_t)(sar32(c, c->eax, 4)); /* sar eax, 4 */
    (void)sub32(c, c->eax, (uint32_t)0x7u); /* cmp eax, 7 */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x30], eax */
    if ((!c->cf && !c->zf)) goto L_006e6788; /* ja 0x6e6788 */
    { uint32_t t_ = R32((uint32_t)(c->eax * 4 + 0x6e67a1u)); switch (t_) { case 0x006e60f5u: goto L_006e60f5; case 0x006e6110u: goto L_006e6110; case 0x006e615cu: goto L_006e615c; case 0x006e6193u: goto L_006e6193; case 0x006e619bu: goto L_006e619b; case 0x006e61d0u: goto L_006e61d0; case 0x006e621fu: goto L_006e621f; case 0x006e6263u: goto L_006e6263; default: jump_indirect(c, t_, 0x006e60eeu); return; } } /* jmp dword ptr [eax*4 + 0x100067a1] */
L_006e60f5:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff0u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 0x10], 0xffffffff */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x34], edx */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x28], edx */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x20], edx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x1c], edx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 4], edx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x24], edx */
    goto L_006e6788; /* jmp 0x6e6788 */
L_006e6110:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx eax, bl */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x20u)); /* sub eax, 0x20 */
    if (c->zf) goto L_006e6153; /* je 0x6e6153 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3u)); /* sub eax, 3 */
    if (c->zf) goto L_006e614a; /* je 0x6e614a */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x8u)); /* sub eax, 8 */
    if (c->zf) goto L_006e6141; /* je 0x6e6141 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_006e6138; /* je 0x6e6138 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3u)); /* sub eax, 3 */
    if (!c->zf) goto L_006e6788; /* jne 0x6e6788 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x8u)))); } /* or dword ptr [ebp - 4], 8 */
    goto L_006e6788; /* jmp 0x6e6788 */
L_006e6138:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x4u)))); } /* or dword ptr [ebp - 4], 4 */
    goto L_006e6788; /* jmp 0x6e6788 */
L_006e6141:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x1u)))); } /* or dword ptr [ebp - 4], 1 */
    goto L_006e6788; /* jmp 0x6e6788 */
L_006e614a:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x80u)))); } /* or byte ptr [ebp - 4], 0x80 */
    goto L_006e6788; /* jmp 0x6e6788 */
L_006e6153:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x2u)))); } /* or dword ptr [ebp - 4], 2 */
    goto L_006e6788; /* jmp 0x6e6788 */
L_006e615c:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x2au); /* cmp bl, 0x2a */
    if (!c->zf) goto L_006e6184; /* jne 0x6e6184 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e616au); f_006e685f(c); /* call 0x6e685f */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    if ((c->sf == c->of)) goto L_006e6788; /* jge 0x6e6788 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x4u)))); } /* or dword ptr [ebp - 4], 4 */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
L_006e617c:;
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    goto L_006e6788; /* jmp 0x6e6788 */
L_006e6184:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov eax, dword ptr [ebp - 0x20] */
    c->ecx = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx ecx, bl */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea eax, [eax + eax*4] */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->eax * 2 + 0xffffffd0u)); /* lea eax, [ecx + eax*2 - 0x30] */
    goto L_006e617c; /* jmp 0x6e617c */
L_006e6193:;
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x10], edx */
    goto L_006e6788; /* jmp 0x6e6788 */
L_006e619b:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x2au); /* cmp bl, 0x2a */
    if (!c->zf) goto L_006e61be; /* jne 0x6e61be */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e61a9u); f_006e685f(c); /* call 0x6e685f */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x10], eax */
    if ((c->sf == c->of)) goto L_006e6788; /* jge 0x6e6788 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff0u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 0x10], 0xffffffff */
    goto L_006e6788; /* jmp 0x6e6788 */
L_006e61be:;
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->ecx * 4)); /* lea eax, [ecx + ecx*4] */
    c->ecx = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx ecx, bl */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->eax * 2 + 0xffffffd0u)); /* lea eax, [ecx + eax*2 - 0x30] */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x10], eax */
    goto L_006e6788; /* jmp 0x6e6788 */
L_006e61d0:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x49u); /* cmp bl, 0x49 */
    if (c->zf) goto L_006e6203; /* je 0x6e6203 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x68u); /* cmp bl, 0x68 */
    if (c->zf) goto L_006e61fa; /* je 0x6e61fa */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x6cu); /* cmp bl, 0x6c */
    if (c->zf) goto L_006e61f1; /* je 0x6e61f1 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x77u); /* cmp bl, 0x77 */
    if (!c->zf) goto L_006e6788; /* jne 0x6e6788 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffdu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x8u)))); } /* or byte ptr [ebp - 3], 8 */
    goto L_006e6788; /* jmp 0x6e6788 */
L_006e61f1:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x10u)))); } /* or dword ptr [ebp - 4], 0x10 */
    goto L_006e6788; /* jmp 0x6e6788 */
L_006e61fa:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x20u)))); } /* or dword ptr [ebp - 4], 0x20 */
    goto L_006e6788; /* jmp 0x6e6788 */
L_006e6203:;
    (void)sub8(c, R8((uint32_t)(c->edi)), (uint8_t)0x36u); /* cmp byte ptr [edi], 0x36 */
    if (!c->zf) goto L_006e621c; /* jne 0x6e621c */
    (void)sub8(c, R8((uint32_t)(c->edi + 0x1u)), (uint8_t)0x34u); /* cmp byte ptr [edi + 1], 0x34 */
    if (!c->zf) goto L_006e621c; /* jne 0x6e621c */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffdu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x80u)))); } /* or byte ptr [ebp - 3], 0x80 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 0xc], edi */
    goto L_006e6788; /* jmp 0x6e6788 */
L_006e621c:;
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x30], edx */
L_006e621f:;
    c->ecx = (uint32_t)(R32((uint32_t)(0x6ee324u))); /* mov ecx, dword ptr [0x1000e324] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x24], edx */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2 + 0x1u)) & (uint8_t)0x80u)); /* test byte ptr [ecx + eax*2 + 1], 0x80 */
    if (c->zf) goto L_006e624b; /* je 0x6e624b */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea eax, [ebp - 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx eax, bl */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e6242u); f_006e67c1(c); /* call 0x6e67c1 */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 0xc], edi */
L_006e624b:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea eax, [ebp - 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx eax, bl */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e625bu); f_006e67c1(c); /* call 0x6e67c1 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_006e6788; /* jmp 0x6e6788 */
L_006e6263:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx eax, bl */
    (void)sub32(c, c->eax, (uint32_t)0x67u); /* cmp eax, 0x67 */
    if ((!c->zf && c->sf == c->of)) goto L_006e648b; /* jg 0x6e648b */
    (void)sub32(c, c->eax, (uint32_t)0x65u); /* cmp eax, 0x65 */
    if ((c->sf == c->of)) goto L_006e630e; /* jge 0x6e630e */
    (void)sub32(c, c->eax, (uint32_t)0x58u); /* cmp eax, 0x58 */
    if ((!c->zf && c->sf == c->of)) goto L_006e636c; /* jg 0x6e636c */
    if (c->zf) goto L_006e64ff; /* je 0x6e64ff */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x43u)); /* sub eax, 0x43 */
    if (c->zf) goto L_006e632f; /* je 0x6e632f */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_006e6304; /* je 0x6e6304 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_006e6304; /* je 0x6e6304 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0xcu)); /* sub eax, 0xc */
    if (!c->zf) goto L_006e668a; /* jne 0x6e668a */
    (void)logic16(c, (uint16_t)(R16((uint32_t)(c->ebp + 0xfffffffcu)) & (uint16_t)0x830u)); /* test word ptr [ebp - 4], 0x830 */
    if (!c->zf) goto L_006e62ad; /* jne 0x6e62ad */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffdu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x8u)))); } /* or byte ptr [ebp - 3], 8 */
L_006e62ad:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov esi, dword ptr [ebp - 0x10] */
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (!c->zf) goto L_006e62ba; /* jne 0x6e62ba */
    c->esi = (uint32_t)((uint32_t)0x7fffffffu); /* mov esi, 0x7fffffff */
L_006e62ba:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e62c3u); f_006e685f(c); /* call 0x6e685f */
    (void)logic16(c, (uint16_t)(R16((uint32_t)(c->ebp + 0xfffffffcu)) & (uint16_t)0x810u)); /* test word ptr [ebp - 4], 0x810 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
    if (c->zf) goto L_006e64d3; /* je 0x6e64d3 */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (!c->zf) goto L_006e62e2; /* jne 0x6e62e2 */
    c->ecx = (uint32_t)(R32((uint32_t)(0x6ee274u))); /* mov ecx, dword ptr [0x1000e274] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
L_006e62e2:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x24], 1 */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
L_006e62eb:;
    c->edx = (uint32_t)(c->esi); /* mov edx, esi */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_006e64ca; /* je 0x6e64ca */
    (void)sub16(c, R16((uint32_t)(c->eax)), (uint16_t)0x0u); /* cmp word ptr [eax], 0 */
    if (c->zf) goto L_006e64ca; /* je 0x6e64ca */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_006e62eb; /* jmp 0x6e62eb */
L_006e6304:;
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x34], 1 */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(add8(c, ((uint8_t)c->ebx), (uint8_t)0x20u)); /* add bl, 0x20 */
L_006e630e:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x40u)))); } /* or dword ptr [ebp - 4], 0x40 */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0xfffffdb8u)); /* lea edi, [ebp - 0x248] */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 8], edi */
    if ((c->sf == c->of)) goto L_006e63f2; /* jge 0x6e63f2 */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)((uint32_t)0x6u)); /* mov dword ptr [ebp - 0x10], 6 */
    goto L_006e6400; /* jmp 0x6e6400 */
L_006e632f:;
    (void)logic16(c, (uint16_t)(R16((uint32_t)(c->ebp + 0xfffffffcu)) & (uint16_t)0x830u)); /* test word ptr [ebp - 4], 0x830 */
    if (!c->zf) goto L_006e633b; /* jne 0x6e633b */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffdu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x8u)))); } /* or byte ptr [ebp - 3], 8 */
L_006e633b:;
    (void)logic16(c, (uint16_t)(R16((uint32_t)(c->ebp + 0xfffffffcu)) & (uint16_t)0x810u)); /* test word ptr [ebp - 4], 0x810 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    if (c->zf) goto L_006e6382; /* je 0x6e6382 */
    PUSH32(c, 0x006e634cu); f_006e687c(c); /* call 0x6e687c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffdb8u)); /* lea eax, [ebp - 0x248] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e6359u); f_006e9ec2(c); /* call 0x6e9ec2 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf == c->of)) goto L_006e6395; /* jge 0x6e6395 */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x28], 1 */
    goto L_006e6395; /* jmp 0x6e6395 */
L_006e636c:;
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x5au)); /* sub eax, 0x5a */
    if (c->zf) goto L_006e63a3; /* je 0x6e63a3 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x9u)); /* sub eax, 9 */
    if (c->zf) goto L_006e633b; /* je 0x6e633b */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_006e6565; /* je 0x6e6565 */
    goto L_006e668a; /* jmp 0x6e668a */
L_006e6382:;
    PUSH32(c, 0x006e6387u); f_006e685f(c); /* call 0x6e685f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W8((uint32_t)(c->ebp + 0xfffffdb8u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp - 0x248], al */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0xc], 1 */
L_006e6395:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffdb8u)); /* lea eax, [ebp - 0x248] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    goto L_006e668a; /* jmp 0x6e668a */
L_006e63a3:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e63acu); f_006e685f(c); /* call 0x6e685f */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_006e63e4; /* je 0x6e63e4 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_006e63e4; /* je 0x6e63e4 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffdu)) & (uint8_t)0x8u)); /* test byte ptr [ebp - 3], 8 */
    if (c->zf) goto L_006e63d5; /* je 0x6e63d5 */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int16_t)R16((uint32_t)(c->eax))); /* movsx eax, word ptr [eax] */
    c->eax = (uint32_t)(shr32(c, c->eax, 1)); /* shr eax, 1 */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x24], 1 */
    goto L_006e668a; /* jmp 0x6e668a */
L_006e63d5:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffdcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x24], 0 */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int16_t)R16((uint32_t)(c->eax))); /* movsx eax, word ptr [eax] */
    goto L_006e6687; /* jmp 0x6e6687 */
L_006e63e4:;
    c->eax = (uint32_t)(R32((uint32_t)(0x6ee270u))); /* mov eax, dword ptr [0x1000e270] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    goto L_006e6480; /* jmp 0x6e6480 */
L_006e63f2:;
    if (!c->zf) goto L_006e6400; /* jne 0x6e6400 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x67u); /* cmp bl, 0x67 */
    if (!c->zf) goto L_006e6400; /* jne 0x6e6400 */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x10], 1 */
L_006e6400:;
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
    { uint32_t t_ = R32((uint32_t)(0x6ee244u)); PUSH32(c, 0x006e6430u); call_indirect(c, t_); } /* call dword ptr [0x1000e244] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov esi, dword ptr [ebp - 4] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0x80u))); /* and esi, 0x80 */
    if (c->zf) goto L_006e6452; /* je 0x6e6452 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x10], 0 */
    if (!c->zf) goto L_006e6452; /* jne 0x6e6452 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffdb8u)); /* lea eax, [ebp - 0x248] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x6ee250u)); PUSH32(c, 0x006e6451u); call_indirect(c, t_); } /* call dword ptr [0x1000e250] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006e6452:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x67u); /* cmp bl, 0x67 */
    if (!c->zf) goto L_006e6469; /* jne 0x6e6469 */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_006e6469; /* jne 0x6e6469 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffdb8u)); /* lea eax, [ebp - 0x248] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x6ee248u)); PUSH32(c, 0x006e6468u); call_indirect(c, t_); } /* call dword ptr [0x1000e248] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006e6469:;
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xfffffdb8u)), (uint8_t)0x2du); /* cmp byte ptr [ebp - 0x248], 0x2d */
    if (!c->zf) goto L_006e647f; /* jne 0x6e647f */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffdu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x1u)))); } /* or byte ptr [ebp - 3], 1 */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0xfffffdb9u)); /* lea edi, [ebp - 0x247] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 8], edi */
L_006e647f:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
L_006e6480:;
    PUSH32(c, 0x006e6485u); f_006e8280(c); /* call 0x6e8280 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_006e6687; /* jmp 0x6e6687 */
L_006e648b:;
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x69u)); /* sub eax, 0x69 */
    if (c->zf) goto L_006e6565; /* je 0x6e6565 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x5u)); /* sub eax, 5 */
    if (c->zf) goto L_006e653b; /* je 0x6e653b */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_006e6528; /* je 0x6e6528 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_006e64f8; /* je 0x6e64f8 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3u)); /* sub eax, 3 */
    if (c->zf) goto L_006e62ad; /* je 0x6e62ad */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_006e6569; /* je 0x6e6569 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3u)); /* sub eax, 3 */
    if (!c->zf) goto L_006e668a; /* jne 0x6e668a */
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)((uint32_t)0x27u)); /* mov dword ptr [ebp - 0x2c], 0x27 */
    goto L_006e6506; /* jmp 0x6e6506 */
L_006e64ca:;
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->eax = (uint32_t)(sar32(c, c->eax, 1)); /* sar eax, 1 */
    goto L_006e6687; /* jmp 0x6e6687 */
L_006e64d3:;
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (!c->zf) goto L_006e64e0; /* jne 0x6e64e0 */
    c->ecx = (uint32_t)(R32((uint32_t)(0x6ee270u))); /* mov ecx, dword ptr [0x1000e270] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
L_006e64e0:;
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
L_006e64e2:;
    c->edx = (uint32_t)(c->esi); /* mov edx, esi */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_006e64f1; /* je 0x6e64f1 */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (c->zf) goto L_006e64f1; /* je 0x6e64f1 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_006e64e2; /* jmp 0x6e64e2 */
L_006e64f1:;
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    goto L_006e6687; /* jmp 0x6e6687 */
L_006e64f8:;
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)((uint32_t)0x8u)); /* mov dword ptr [ebp - 0x10], 8 */
L_006e64ff:;
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)((uint32_t)0x7u)); /* mov dword ptr [ebp - 0x2c], 7 */
L_006e6506:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffcu)) & (uint8_t)0x80u)); /* test byte ptr [ebp - 4], 0x80 */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)((uint32_t)0x10u)); /* mov dword ptr [ebp - 0xc], 0x10 */
    if (c->zf) goto L_006e6570; /* je 0x6e6570 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0xffffffd4u))); /* mov al, byte ptr [ebp - 0x2c] */
    W8((uint32_t)(c->ebp + 0xffffffeau), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [ebp - 0x16], 0x30 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(add8(c, ((uint8_t)c->eax), (uint8_t)0x51u)); /* add al, 0x51 */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [ebp - 0x1c], 2 */
    W8((uint32_t)(c->ebp + 0xffffffebu), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp - 0x15], al */
    goto L_006e6570; /* jmp 0x6e6570 */
L_006e6528:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffcu)) & (uint8_t)0x80u)); /* test byte ptr [ebp - 4], 0x80 */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)((uint32_t)0x8u)); /* mov dword ptr [ebp - 0xc], 8 */
    if (c->zf) goto L_006e6570; /* je 0x6e6570 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffdu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x2u)))); } /* or byte ptr [ebp - 3], 2 */
    goto L_006e6570; /* jmp 0x6e6570 */
L_006e653b:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e6544u); f_006e685f(c); /* call 0x6e685f */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffcu)) & (uint8_t)0x20u)); /* test byte ptr [ebp - 4], 0x20 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_006e6554; /* je 0x6e6554 */
    c->ecx = (c->ecx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ebp + 0xffffffecu))); /* mov cx, word ptr [ebp - 0x14] */
    W16((uint32_t)(c->eax), (uint16_t)(((uint16_t)c->ecx))); /* mov word ptr [eax], cx */
    goto L_006e6559; /* jmp 0x6e6559 */
L_006e6554:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov ecx, dword ptr [ebp - 0x14] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
L_006e6559:;
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x28], 1 */
    goto L_006e6788; /* jmp 0x6e6788 */
L_006e6565:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x40u)))); } /* or dword ptr [ebp - 4], 0x40 */
L_006e6569:;
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)((uint32_t)0xau)); /* mov dword ptr [ebp - 0xc], 0xa */
L_006e6570:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffdu)) & (uint8_t)0x80u)); /* test byte ptr [ebp - 3], 0x80 */
    if (c->zf) goto L_006e6582; /* je 0x6e6582 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e657fu); f_006e686c(c); /* call 0x6e686c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_006e65c3; /* jmp 0x6e65c3 */
L_006e6582:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffcu)) & (uint8_t)0x20u)); /* test byte ptr [ebp - 4], 0x20 */
    if (c->zf) goto L_006e65a9; /* je 0x6e65a9 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffcu)) & (uint8_t)0x40u)); /* test byte ptr [ebp - 4], 0x40 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    if (c->zf) goto L_006e659e; /* je 0x6e659e */
    PUSH32(c, 0x006e6597u); f_006e685f(c); /* call 0x6e685f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int16_t)((uint16_t)c->eax)); /* movsx eax, ax */
L_006e659b:;
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    goto L_006e65c3; /* jmp 0x6e65c3 */
L_006e659e:;
    PUSH32(c, 0x006e65a3u); f_006e685f(c); /* call 0x6e685f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)((uint32_t)((uint16_t)c->eax)); /* movzx eax, ax */
    goto L_006e659b; /* jmp 0x6e659b */
L_006e65a9:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffcu)) & (uint8_t)0x40u)); /* test byte ptr [ebp - 4], 0x40 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    if (c->zf) goto L_006e65bb; /* je 0x6e65bb */
    PUSH32(c, 0x006e65b8u); f_006e685f(c); /* call 0x6e685f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_006e659b; /* jmp 0x6e659b */
L_006e65bb:;
    PUSH32(c, 0x006e65c0u); f_006e685f(c); /* call 0x6e685f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
L_006e65c3:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffcu)) & (uint8_t)0x40u)); /* test byte ptr [ebp - 4], 0x40 */
    if (c->zf) goto L_006e65e4; /* je 0x6e65e4 */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if ((!c->zf && c->sf == c->of)) goto L_006e65e4; /* jg 0x6e65e4 */
    if ((c->sf != c->of)) goto L_006e65d3; /* jl 0x6e65d3 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->cf) goto L_006e65e4; /* jae 0x6e65e4 */
L_006e65d3:;
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->edx = (uint32_t)(adc32(c, c->edx, (uint32_t)0x0u)); /* adc edx, 0 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->edx = (uint32_t)(neg32(c, c->edx)); /* neg edx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffdu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x1u)))); } /* or byte ptr [ebp - 3], 1 */
    c->edi = (uint32_t)(c->edx); /* mov edi, edx */
    goto L_006e65e8; /* jmp 0x6e65e8 */
L_006e65e4:;
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->edi = (uint32_t)(c->edx); /* mov edi, edx */
L_006e65e8:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffdu)) & (uint8_t)0x80u)); /* test byte ptr [ebp - 3], 0x80 */
    if (!c->zf) goto L_006e65f1; /* jne 0x6e65f1 */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & (uint32_t)0x0u))); /* and edi, 0 */
L_006e65f1:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x10], 0 */
    if ((c->sf == c->of)) goto L_006e6600; /* jge 0x6e6600 */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x10], 1 */
    goto L_006e6604; /* jmp 0x6e6604 */
L_006e6600:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0xfffffff7u)))); } /* and dword ptr [ebp - 4], 0xfffffff7 */
L_006e6604:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->edi))); /* or eax, edi */
    if (!c->zf) goto L_006e660e; /* jne 0x6e660e */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x1c], 0 */
L_006e660e:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffb7u)); /* lea eax, [ebp - 0x49] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
L_006e6614:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff0u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 0x10] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((!c->zf && c->sf == c->of)) goto L_006e6624; /* jg 0x6e6624 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->edi))); /* or eax, edi */
    if (c->zf) goto L_006e665f; /* je 0x6e665f */
L_006e6624:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W32((uint32_t)(c->ebp + 0xffffffc0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x40], eax */
    W32((uint32_t)(c->ebp + 0xffffffc4u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x3c], edx */
    PUSH32(c, 0x006e6637u); f_006e9fa0(c); /* call 0x6e9fa0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x3c] */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x30u)); /* add ebx, 0x30 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x40] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006e6649u); f_006e9f30(c); /* call 0x6e9f30 */
    (void)sub32(c, c->ebx, (uint32_t)0x39u); /* cmp ebx, 0x39 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->edi = (uint32_t)(c->edx); /* mov edi, edx */
    if ((c->zf || c->sf != c->of)) goto L_006e6655; /* jle 0x6e6655 */
    c->ebx = (uint32_t)(add32(c, c->ebx, R32((uint32_t)(c->ebp + 0xffffffd4u)))); /* add ebx, dword ptr [ebp - 0x2c] */
L_006e6655:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 8] */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [eax], bl */
    goto L_006e6614; /* jmp 0x6e6614 */
L_006e665f:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffb7u)); /* lea eax, [ebp - 0x49] */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xfffffff8u)))); /* sub eax, dword ptr [ebp - 8] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffdu)) & (uint8_t)0x2u)); /* test byte ptr [ebp - 3], 2 */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    if (c->zf) goto L_006e668a; /* je 0x6e668a */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    (void)sub8(c, R8((uint32_t)(c->ecx)), (uint8_t)0x30u); /* cmp byte ptr [ecx], 0x30 */
    if (!c->zf) goto L_006e667d; /* jne 0x6e667d */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006e668a; /* jne 0x6e668a */
L_006e667d:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 8] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    W8((uint32_t)(c->ecx), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [ecx], 0x30 */
L_006e6687:;
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
L_006e668a:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x28], 0 */
    if (!c->zf) goto L_006e6788; /* jne 0x6e6788 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ebx, dword ptr [ebp - 4] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x40u)); /* test bl, 0x40 */
    if (c->zf) goto L_006e66c2; /* je 0x6e66c2 */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->ebx >> 8)) & (uint8_t)0x1u)); /* test bh, 1 */
    if (c->zf) goto L_006e66a7; /* je 0x6e66a7 */
    W8((uint32_t)(c->ebp + 0xffffffeau), (uint8_t)((uint8_t)0x2du)); /* mov byte ptr [ebp - 0x16], 0x2d */
    goto L_006e66bb; /* jmp 0x6e66bb */
L_006e66a7:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x1u)); /* test bl, 1 */
    if (c->zf) goto L_006e66b2; /* je 0x6e66b2 */
    W8((uint32_t)(c->ebp + 0xffffffeau), (uint8_t)((uint8_t)0x2bu)); /* mov byte ptr [ebp - 0x16], 0x2b */
    goto L_006e66bb; /* jmp 0x6e66bb */
L_006e66b2:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x2u)); /* test bl, 2 */
    if (c->zf) goto L_006e66c2; /* je 0x6e66c2 */
    W8((uint32_t)(c->ebp + 0xffffffeau), (uint8_t)((uint8_t)0x20u)); /* mov byte ptr [ebp - 0x16], 0x20 */
L_006e66bb:;
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x1c], 1 */
L_006e66c2:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
    c->esi = (uint32_t)(sub32(c, c->esi, R32((uint32_t)(c->ebp + 0xffffffe4u)))); /* sub esi, dword ptr [ebp - 0x1c] */
    c->esi = (uint32_t)(sub32(c, c->esi, R32((uint32_t)(c->ebp + 0xfffffff4u)))); /* sub esi, dword ptr [ebp - 0xc] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0xcu)); /* test bl, 0xc */
    if (!c->zf) goto L_006e66e2; /* jne 0x6e66e2 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea eax, [ebp - 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x20u; PUSH32(c, v_); } /* push 0x20 */
    PUSH32(c, 0x006e66dfu); f_006e67f6(c); /* call 0x6e67f6 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_006e66e2:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea eax, [ebp - 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffeau)); /* lea eax, [ebp - 0x16] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e66f5u); f_006e6827(c); /* call 0x6e6827 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x8u)); /* test bl, 8 */
    if (c->zf) goto L_006e6714; /* je 0x6e6714 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x4u)); /* test bl, 4 */
    if (!c->zf) goto L_006e6714; /* jne 0x6e6714 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea eax, [ebp - 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x30u; PUSH32(c, v_); } /* push 0x30 */
    PUSH32(c, 0x006e6711u); f_006e67f6(c); /* call 0x6e67f6 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_006e6714:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (c->zf) goto L_006e675b; /* je 0x6e675b */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0xc], 0 */
    if ((c->zf || c->sf != c->of)) goto L_006e675b; /* jle 0x6e675b */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ebx, dword ptr [ebp - 8] */
    c->edi = (uint32_t)((uint32_t)(c->eax + 0xffffffffu)); /* lea edi, [eax - 1] */
L_006e6729:;
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ebx))); /* mov ax, word ptr [ebx] */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    PUSH32(c, 0x006e6738u); f_006e9ec2(c); /* call 0x6e9ec2 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if ((c->zf || c->sf != c->of)) goto L_006e6770; /* jle 0x6e6770 */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea ecx, [ebp - 0x14] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e674fu); f_006e6827(c); /* call 0x6e6827 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006e6729; /* jne 0x6e6729 */
    goto L_006e6770; /* jmp 0x6e6770 */
L_006e675b:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea eax, [ebp - 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffff4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffff8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 8] */
    PUSH32(c, 0x006e676du); f_006e6827(c); /* call 0x6e6827 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_006e6770:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffcu)) & (uint8_t)0x4u)); /* test byte ptr [ebp - 4], 4 */
    if (c->zf) goto L_006e6788; /* je 0x6e6788 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea eax, [ebp - 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x20u; PUSH32(c, v_); } /* push 0x20 */
    PUSH32(c, 0x006e6785u); f_006e67f6(c); /* call 0x6e67f6 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_006e6788:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & ((uint8_t)c->ebx))); /* test bl, bl */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 0xc], edi */
    if (!c->zf) goto L_006e60ac; /* jne 0x6e60ac */
L_006e6799:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006e60f5(CPU *c) { /* PTR_006e60f5 */
    PREEMPT_POLL(c);
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff0u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 0x10], 0xffffffff */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x34], edx */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x28], edx */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x20], edx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x1c], edx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 4], edx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x24], edx */
    goto L_006e6788; /* jmp 0x6e6788 */
L_006e6788:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & ((uint8_t)c->ebx))); /* test bl, bl */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 0xc], edi */
    if (!c->zf) { jump_indirect(c, 0x006e60acu, 0x006e6793u); return; } /* jne 0x6e60ac */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006e67c1(CPU *c) { /* PTR_006e67c1 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ecx + 4] */
    if (c->sf) goto L_006e67da; /* js 0x6e67da */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0x8u))); /* mov al, byte ptr [ebp + 8] */
    W8((uint32_t)(c->edx), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edx], al */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->eax)); /* movzx eax, al */
    goto L_006e67e5; /* jmp 0x6e67e5 */
L_006e67da:;
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x006e67e3u); f_006e6a72(c); /* call 0x6e6a72 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006e67e5:;
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    if (!c->zf) goto L_006e67f2; /* jne 0x6e67f2 */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [eax], 0xffffffff */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
L_006e67f2:;
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [eax] */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_006e67f6(CPU *c) { /* PTR_006e67f6 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edi, dword ptr [esp + 0x10] */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_006e6824; /* jle 0x6e6824 */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov esi, dword ptr [esp + 0x18] */
L_006e6807:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x14] */
    PUSH32(c, 0x006e6815u); f_006e67c1(c); /* call 0x6e67c1 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0xffffffffu); /* cmp dword ptr [esi], -1 */
    if (c->zf) goto L_006e6824; /* je 0x6e6824 */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((!c->zf && c->sf == c->of)) goto L_006e6807; /* jg 0x6e6807 */
L_006e6824:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_006e6827(CPU *c) { /* PTR_006e6827 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ebx, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_006e685b; /* jle 0x6e685b */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov edi, dword ptr [esp + 0x1c] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
L_006e683d:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->esi))); /* movsx eax, byte ptr [esi] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [esp + 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e684cu); f_006e67c1(c); /* call 0x6e67c1 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, R32((uint32_t)(c->edi)), (uint32_t)0xffffffffu); /* cmp dword ptr [edi], -1 */
    if (c->zf) goto L_006e685b; /* je 0x6e685b */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((!c->zf && c->sf == c->of)) goto L_006e683d; /* jg 0x6e683d */
L_006e685b:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_006e685f(CPU *c) { /* PTR_006e685f */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x4u))); } /* add dword ptr [eax], 4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0xfffffffcu))); /* mov eax, dword ptr [eax - 4] */
    c->esp += 4; return; /* ret  */
}

void f_006e686c(CPU *c) { /* PTR_006e686c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x8u))); } /* add dword ptr [eax], 8 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0xfffffff8u))); /* mov eax, dword ptr [ecx - 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0xfffffffcu))); /* mov edx, dword ptr [ecx - 4] */
    c->esp += 4; return; /* ret  */
}

void f_006e687c(CPU *c) { /* PTR_006e687c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x4u))); } /* add dword ptr [eax], 4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->eax + 0xfffffffcu))); /* mov ax, word ptr [eax - 4] */
    c->esp += 4; return; /* ret  */
}

void f_006e688a(CPU *c) { /* FUN_1000688a */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(0x777b08u))); /* mov esi, dword ptr [0x10097b08] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 8], ebx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 4], ebx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov al, byte ptr [edi] */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x61u); /* cmp al, 0x61 */
    if (c->zf) goto L_006e68c3; /* je 0x6e68c3 */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x72u); /* cmp al, 0x72 */
    if (c->zf) goto L_006e68bc; /* je 0x6e68bc */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x77u); /* cmp al, 0x77 */
    if (!c->zf) goto L_006e69d7; /* jne 0x6e69d7 */
    c->ecx = (uint32_t)((uint32_t)0x301u); /* mov ecx, 0x301 */
    goto L_006e68c8; /* jmp 0x6e68c8 */
L_006e68bc:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi | (uint32_t)0x1u))); /* or esi, 1 */
    goto L_006e68cb; /* jmp 0x6e68cb */
L_006e68c3:;
    c->ecx = (uint32_t)((uint32_t)0x109u); /* mov ecx, 0x109 */
L_006e68c8:;
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi | (uint32_t)0x2u))); /* or esi, 2 */
L_006e68cb:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
L_006e68ce:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi + 0x1u))); /* mov al, byte ptr [edi + 1] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_006e69bd; /* je 0x6e69bd */
    (void)sub32(c, c->edx, c->ebx); /* cmp edx, ebx */
    if (c->zf) goto L_006e69bd; /* je 0x6e69bd */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->eax)); /* movsx eax, al */
    (void)sub32(c, c->eax, (uint32_t)0x54u); /* cmp eax, 0x54 */
    if ((!c->zf && c->sf == c->of)) goto L_006e695c; /* jg 0x6e695c */
    if (c->zf) goto L_006e694c; /* je 0x6e694c */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x2bu)); /* sub eax, 0x2b */
    if (c->zf) goto L_006e6936; /* je 0x6e6936 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x19u)); /* sub eax, 0x19 */
    if (c->zf) goto L_006e692c; /* je 0x6e692c */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0xeu)); /* sub eax, 0xe */
    if (c->zf) goto L_006e6917; /* je 0x6e6917 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (!c->zf) goto L_006e69ae; /* jne 0x6e69ae */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), c->ebx); /* cmp dword ptr [ebp - 4], ebx */
    if (!c->zf) goto L_006e69ae; /* jne 0x6e69ae */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0x20u))); /* or ecx, 0x20 */
    goto L_006e68ce; /* jmp 0x6e68ce */
L_006e6917:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), c->ebx); /* cmp dword ptr [ebp - 4], ebx */
    if (!c->zf) goto L_006e69ae; /* jne 0x6e69ae */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0x10u))); /* or ecx, 0x10 */
    goto L_006e68ce; /* jmp 0x6e68ce */
L_006e692c:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x40u)); /* test cl, 0x40 */
    if (!c->zf) goto L_006e69ae; /* jne 0x6e69ae */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0x40u))); /* or ecx, 0x40 */
    goto L_006e68ce; /* jmp 0x6e68ce */
L_006e6936:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x2u)); /* test cl, 2 */
    if (!c->zf) goto L_006e69ae; /* jne 0x6e69ae */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0xfffffffeu))); /* and ecx, 0xfffffffe */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffffcu))); /* and esi, 0xfffffffc */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0x2u))); /* or ecx, 2 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi | (uint32_t)0x80u))); /* or esi, 0x80 */
    goto L_006e68ce; /* jmp 0x6e68ce */
L_006e694c:;
    c->eax = (uint32_t)((uint32_t)0x1000u); /* mov eax, 0x1000 */
    (void)logic32(c, (uint32_t)(c->eax & c->ecx)); /* test eax, ecx */
    if (!c->zf) goto L_006e69ae; /* jne 0x6e69ae */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->eax))); /* or ecx, eax */
    goto L_006e68ce; /* jmp 0x6e68ce */
L_006e695c:;
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x62u)); /* sub eax, 0x62 */
    if (c->zf) goto L_006e69a9; /* je 0x6e69a9 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_006e6992; /* je 0x6e6992 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0xbu)); /* sub eax, 0xb */
    if (c->zf) goto L_006e697b; /* je 0x6e697b */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x6u)); /* sub eax, 6 */
    if (!c->zf) goto L_006e69ae; /* jne 0x6e69ae */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) & (uint8_t)0xc0u)); /* test ch, 0xc0 */
    if (!c->zf) goto L_006e69ae; /* jne 0x6e69ae */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) | (uint8_t)0x40u))) << 8); /* or ch, 0x40 */
    goto L_006e68ce; /* jmp 0x6e68ce */
L_006e697b:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff8u)), c->ebx); /* cmp dword ptr [ebp - 8], ebx */
    if (!c->zf) goto L_006e69ae; /* jne 0x6e69ae */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 8], 1 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xffffbfffu))); /* and esi, 0xffffbfff */
    goto L_006e68ce; /* jmp 0x6e68ce */
L_006e6992:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff8u)), c->ebx); /* cmp dword ptr [ebp - 8], ebx */
    if (!c->zf) goto L_006e69ae; /* jne 0x6e69ae */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 8], 1 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi | (uint32_t)0x4000u))); /* or esi, 0x4000 */
    goto L_006e68ce; /* jmp 0x6e68ce */
L_006e69a9:;
    (void)logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) & (uint8_t)0xc0u)); /* test ch, 0xc0 */
    if (c->zf) goto L_006e69b5; /* je 0x6e69b5 */
L_006e69ae:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    goto L_006e68ce; /* jmp 0x6e68ce */
L_006e69b5:;
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) | (uint8_t)0x80u))) << 8); /* or ch, 0x80 */
    goto L_006e68ce; /* jmp 0x6e68ce */
L_006e69bd:;
    { uint32_t v_ = 0x1a4u; PUSH32(c, v_); } /* push 0x1a4 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x006e69ceu); f_006ea015(c); /* call 0x6ea015 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)sub32(c, c->ecx, c->ebx); /* cmp ecx, ebx */
    if ((c->sf == c->of)) goto L_006e69db; /* jge 0x6e69db */
L_006e69d7:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_006e69f5; /* jmp 0x6e69f5 */
L_006e69db:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    { uint32_t a_ = (uint32_t)(0x777b04u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [0x10097b04] */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [eax + 0xc], esi */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 4], ebx */
    W32((uint32_t)(c->eax), (uint32_t)(c->ebx)); /* mov dword ptr [eax], ebx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 8], ebx */
    W32((uint32_t)(c->eax + 0x1cu), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x1c], ebx */
    W32((uint32_t)(c->eax + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x10], ecx */
L_006e69f5:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006e69fa(CPU *c) { /* FUN_100069fa */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(0x778da0u))); /* mov edx, dword ptr [0x10098da0] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ebp = (uint32_t)(logic32(c, 0)); /* xor ebp, ebp */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, c->edx, c->ebp); /* cmp edx, ebp */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if ((c->zf || c->sf != c->of)) goto L_006e6a6b; /* jle 0x6e6a6b */
    c->ebx = (uint32_t)(R32((uint32_t)(0x777d88u))); /* mov ebx, dword ptr [0x10097d88] */
    c->edi = (uint32_t)(c->ebx); /* mov edi, ebx */
L_006e6a16:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi))); /* mov ecx, dword ptr [edi] */
    (void)sub32(c, c->ecx, c->ebp); /* cmp ecx, ebp */
    if (c->zf) goto L_006e6a31; /* je 0x6e6a31 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ecx + 0xcu)) & (uint8_t)0x83u)); /* test byte ptr [ecx + 0xc], 0x83 */
    if (c->zf) goto L_006e6a2c; /* je 0x6e6a2c */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    (void)sub32(c, c->eax, c->edx); /* cmp eax, edx */
    if ((c->sf != c->of)) goto L_006e6a16; /* jl 0x6e6a16 */
    goto L_006e6a6b; /* jmp 0x6e6a6b */
L_006e6a2c:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebx + c->eax * 4))); /* mov esi, dword ptr [ebx + eax*4] */
    goto L_006e6a55; /* jmp 0x6e6a55 */
L_006e6a31:;
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    { uint32_t v_ = 0x20u; PUSH32(c, v_); } /* push 0x20 */
    c->edi = (uint32_t)(shl32(c, c->edi, 2)); /* shl edi, 2 */
    PUSH32(c, 0x006e6a3du); f_006e5d19(c); /* call 0x6e5d19 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(0x777d88u))); /* mov ecx, dword ptr [0x10097d88] */
    W32((uint32_t)(c->edi + c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx], eax */
    c->eax = (uint32_t)(R32((uint32_t)(0x777d88u))); /* mov eax, dword ptr [0x10097d88] */
    c->edi = (uint32_t)(R32((uint32_t)(c->edi + c->eax))); /* mov edi, dword ptr [edi + eax] */
    (void)sub32(c, c->edi, c->ebp); /* cmp edi, ebp */
    if (c->zf) goto L_006e6a6b; /* je 0x6e6a6b */
    c->esi = (uint32_t)(c->edi); /* mov esi, edi */
L_006e6a55:;
    (void)sub32(c, c->esi, c->ebp); /* cmp esi, ebp */
    if (c->zf) goto L_006e6a6b; /* je 0x6e6a6b */
    { uint32_t a_ = (uint32_t)(c->esi + 0x10u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [esi + 0x10], 0xffffffff */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->ebp)); /* mov dword ptr [esi + 4], ebp */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->ebp)); /* mov dword ptr [esi + 0xc], ebp */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->ebp)); /* mov dword ptr [esi + 8], ebp */
    W32((uint32_t)(c->esi), (uint32_t)(c->ebp)); /* mov dword ptr [esi], ebp */
    W32((uint32_t)(c->esi + 0x1cu), (uint32_t)(c->ebp)); /* mov dword ptr [esi + 0x1c], ebp */
L_006e6a6b:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_006e6a72(CPU *c) { /* FUN_10006a72 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ebx, dword ptr [esi + 0x10] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x82u)); /* test al, 0x82 */
    if (c->zf) goto L_006e6b7b; /* je 0x6e6b7b */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x40u)); /* test al, 0x40 */
    if (!c->zf) goto L_006e6b7b; /* jne 0x6e6b7b */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    if (c->zf) goto L_006e6aaa; /* je 0x6e6aaa */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi + 4], 0 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x10u)); /* test al, 0x10 */
    if (c->zf) goto L_006e6b7b; /* je 0x6e6b7b */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ecx, dword ptr [esi + 8] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfeu))); /* and al, 0xfe */
    W32((uint32_t)(c->esi), (uint32_t)(c->ecx)); /* mov dword ptr [esi], ecx */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xc], eax */
L_006e6aaa:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi + 4], 0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp + 0xc], 0 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xefu))); /* and al, 0xef */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x2u))); /* or al, 2 */
    (void)logic16(c, (uint16_t)(((uint16_t)c->eax) & (uint16_t)0x10cu)); /* test ax, 0x10c */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xc], eax */
    if (!c->zf) goto L_006e6ae4; /* jne 0x6e6ae4 */
    (void)sub32(c, c->esi, (uint32_t)0x6f0718u); /* cmp esi, 0x10010718 */
    if (c->zf) goto L_006e6ad2; /* je 0x6e6ad2 */
    (void)sub32(c, c->esi, (uint32_t)0x6f0738u); /* cmp esi, 0x10010738 */
    if (!c->zf) goto L_006e6add; /* jne 0x6e6add */
L_006e6ad2:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x006e6ad8u); f_006e9e9c(c); /* call 0x6e9e9c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_006e6ae4; /* jne 0x6e6ae4 */
L_006e6add:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006e6ae3u); f_006ea368(c); /* call 0x6ea368 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006e6ae4:;
    (void)logic16(c, (uint16_t)(R16((uint32_t)(c->esi + 0xcu)) & (uint16_t)0x108u)); /* test word ptr [esi + 0xc], 0x108 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (c->zf) goto L_006e6b51; /* je 0x6e6b51 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edi, dword ptr [esi] */
    c->edi = (uint32_t)(sub32(c, c->edi, c->eax)); /* sub edi, eax */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x1u)); /* lea ecx, [eax + 1] */
    W32((uint32_t)(c->esi), (uint32_t)(c->ecx)); /* mov dword ptr [esi], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x18u))); /* mov ecx, dword ptr [esi + 0x18] */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 4], ecx */
    if ((c->zf || c->sf != c->of)) goto L_006e6b14; /* jle 0x6e6b14 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x006e6b0cu); f_006e9c36(c); /* call 0x6e9c36 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0xc], eax */
    goto L_006e6b47; /* jmp 0x6e6b47 */
L_006e6b14:;
    (void)sub32(c, c->ebx, (uint32_t)0xffffffffu); /* cmp ebx, -1 */
    if (c->zf) goto L_006e6b2f; /* je 0x6e6b2f */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    c->eax = (uint32_t)(sar32(c, c->eax, 5)); /* sar eax, 5 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x1fu))); /* and ecx, 0x1f */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax * 4 + 0x778dc0u))); /* mov eax, dword ptr [eax*4 + 0x10098dc0] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->ecx * 8)); /* lea eax, [eax + ecx*8] */
    goto L_006e6b34; /* jmp 0x6e6b34 */
L_006e6b2f:;
    c->eax = (uint32_t)((uint32_t)0x6ee280u); /* mov eax, 0x1000e280 */
L_006e6b34:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + 0x4u)) & (uint8_t)0x20u)); /* test byte ptr [eax + 4], 0x20 */
    if (c->zf) goto L_006e6b47; /* je 0x6e6b47 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x006e6b44u); f_006ea2ce(c); /* call 0x6ea2ce */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_006e6b47:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0x8u))); /* mov cl, byte ptr [ebp + 8] */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax], cl */
    goto L_006e6b65; /* jmp 0x6e6b65 */
L_006e6b51:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x8u)); /* lea eax, [ebp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x006e6b5fu); f_006e9c36(c); /* call 0x6e9c36 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0xc], eax */
L_006e6b65:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->edi); /* cmp dword ptr [ebp + 0xc], edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    if (c->zf) goto L_006e6b71; /* je 0x6e6b71 */
    { uint32_t a_ = (uint32_t)(c->esi + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x20u)))); } /* or dword ptr [esi + 0xc], 0x20 */
    goto L_006e6b80; /* jmp 0x6e6b80 */
L_006e6b71:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xffu))); /* and eax, 0xff */
    goto L_006e6b83; /* jmp 0x6e6b83 */
L_006e6b7b:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x20u))); /* or al, 0x20 */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xc], eax */
L_006e6b80:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
L_006e6b83:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_006e6b87(CPU *c) { /* FUN_10006b87 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi], 0 */
    { uint32_t t_ = R32((uint32_t)(0x6ed014u)); PUSH32(c, 0x006e6b97u); call_indirect(c, t_); } /* call dword ptr [0x1000d014] */
    (void)sub16(c, R16((uint32_t)(c->eax)), (uint16_t)0x5a4du); /* cmp word ptr [eax], 0x5a4d */
    if (!c->zf) goto L_006e6bb2; /* jne 0x6e6bb2 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x3cu))); /* mov ecx, dword ptr [eax + 0x3c] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_006e6bb2; /* je 0x6e6bb2 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1au))); /* mov cl, byte ptr [eax + 0x1a] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esi], cl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1bu))); /* mov al, byte ptr [eax + 0x1b] */
    W8((uint32_t)(c->esi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [esi + 1], al */
L_006e6bb2:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_006e6bb4(CPU *c) { /* FUN_10006bb4 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->eax = (uint32_t)((uint32_t)0x122cu); /* mov eax, 0x122c */
    PUSH32(c, 0x006e6bc1u); f_006ea760(c); /* call 0x6ea760 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff68u)); /* lea eax, [ebp - 0x98] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(c->ebp + 0xffffff68u), (uint32_t)((uint32_t)0x94u)); /* mov dword ptr [ebp - 0x98], 0x94 */
    { uint32_t t_ = R32((uint32_t)(0x6ed048u)); PUSH32(c, 0x006e6bd9u); call_indirect(c, t_); } /* call dword ptr [0x1000d048] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e6bf7; /* je 0x6e6bf7 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffff78u)), (uint32_t)0x2u); /* cmp dword ptr [ebp - 0x88], 2 */
    if (!c->zf) goto L_006e6bf7; /* jne 0x6e6bf7 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffff6cu)), (uint32_t)0x5u); /* cmp dword ptr [ebp - 0x94], 5 */
    if (c->cf) goto L_006e6bf7; /* jb 0x6e6bf7 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_006e6cf9; /* jmp 0x6e6cf9 */
L_006e6bf7:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffedd4u)); /* lea eax, [ebp - 0x122c] */
    { uint32_t v_ = 0x1090u; PUSH32(c, v_); } /* push 0x1090 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x6ed4bcu; PUSH32(c, v_); } /* push 0x1000d4bc */
    { uint32_t t_ = R32((uint32_t)(0x6ed044u)); PUSH32(c, 0x006e6c0eu); call_indirect(c, t_); } /* call dword ptr [0x1000d044] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e6ce6; /* je 0x6e6ce6 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffedd4u)); /* lea ecx, [ebp - 0x122c] */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xffffedd4u)), ((uint8_t)c->ebx)); /* cmp byte ptr [ebp - 0x122c], bl */
    if (c->zf) goto L_006e6c39; /* je 0x6e6c39 */
L_006e6c26:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov al, byte ptr [ecx] */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x61u); /* cmp al, 0x61 */
    if ((c->sf != c->of)) goto L_006e6c34; /* jl 0x6e6c34 */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x7au); /* cmp al, 0x7a */
    if ((!c->zf && c->sf == c->of)) goto L_006e6c34; /* jg 0x6e6c34 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sub8(c, ((uint8_t)c->eax), (uint8_t)0x20u)); /* sub al, 0x20 */
    W8((uint32_t)(c->ecx), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ecx], al */
L_006e6c34:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub8(c, R8((uint32_t)(c->ecx)), ((uint8_t)c->ebx)); /* cmp byte ptr [ecx], bl */
    if (!c->zf) goto L_006e6c26; /* jne 0x6e6c26 */
L_006e6c39:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffedd4u)); /* lea eax, [ebp - 0x122c] */
    { uint32_t v_ = 0x16u; PUSH32(c, v_); } /* push 0x16 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x6ed4a4u; PUSH32(c, v_); } /* push 0x1000d4a4 */
    PUSH32(c, 0x006e6c4cu); f_006ea720(c); /* call 0x6ea720 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006e6c5b; /* jne 0x6e6c5b */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffedd4u)); /* lea eax, [ebp - 0x122c] */
    goto L_006e6ca4; /* jmp 0x6e6ca4 */
L_006e6c5b:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe64u)); /* lea eax, [ebp - 0x19c] */
    { uint32_t v_ = 0x104u; PUSH32(c, v_); } /* push 0x104 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(0x6ed040u)); PUSH32(c, 0x006e6c6eu); call_indirect(c, t_); } /* call dword ptr [0x1000d040] */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xfffffe64u)), ((uint8_t)c->ebx)); /* cmp byte ptr [ebp - 0x19c], bl */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffe64u)); /* lea ecx, [ebp - 0x19c] */
    if (c->zf) goto L_006e6c8f; /* je 0x6e6c8f */
L_006e6c7c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov al, byte ptr [ecx] */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x61u); /* cmp al, 0x61 */
    if ((c->sf != c->of)) goto L_006e6c8a; /* jl 0x6e6c8a */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x7au); /* cmp al, 0x7a */
    if ((!c->zf && c->sf == c->of)) goto L_006e6c8a; /* jg 0x6e6c8a */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sub8(c, ((uint8_t)c->eax), (uint8_t)0x20u)); /* sub al, 0x20 */
    W8((uint32_t)(c->ecx), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ecx], al */
L_006e6c8a:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub8(c, R8((uint32_t)(c->ecx)), ((uint8_t)c->ebx)); /* cmp byte ptr [ecx], bl */
    if (!c->zf) goto L_006e6c7c; /* jne 0x6e6c7c */
L_006e6c8f:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe64u)); /* lea eax, [ebp - 0x19c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffedd4u)); /* lea eax, [ebp - 0x122c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e6ca2u); f_006ea6a0(c); /* call 0x6ea6a0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006e6ca4:;
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_006e6ce6; /* je 0x6e6ce6 */
    { uint32_t v_ = 0x2cu; PUSH32(c, v_); } /* push 0x2c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e6cb0u); f_006ea5e0(c); /* call 0x6ea5e0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_006e6ce6; /* je 0x6e6ce6 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), ((uint8_t)c->ebx)); /* cmp byte ptr [eax], bl */
    if (c->zf) goto L_006e6ccb; /* je 0x6e6ccb */
L_006e6cbd:;
    (void)sub8(c, R8((uint32_t)(c->ecx)), (uint8_t)0x3bu); /* cmp byte ptr [ecx], 0x3b */
    if (!c->zf) goto L_006e6cc6; /* jne 0x6e6cc6 */
    W8((uint32_t)(c->ecx), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ecx], bl */
    goto L_006e6cc7; /* jmp 0x6e6cc7 */
L_006e6cc6:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
L_006e6cc7:;
    (void)sub8(c, R8((uint32_t)(c->ecx)), ((uint8_t)c->ebx)); /* cmp byte ptr [ecx], bl */
    if (!c->zf) goto L_006e6cbd; /* jne 0x6e6cbd */
L_006e6ccb:;
    { uint32_t v_ = 0xau; PUSH32(c, v_); } /* push 0xa */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e6cd4u); f_006ea3ac(c); /* call 0x6ea3ac */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (c->zf) goto L_006e6cf9; /* je 0x6e6cf9 */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (c->zf) goto L_006e6cf9; /* je 0x6e6cf9 */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_006e6cf9; /* je 0x6e6cf9 */
L_006e6ce6:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e6cefu); f_006e6b87(c); /* call 0x6e6b87 */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xfffffffcu)), (uint8_t)0x6u); /* cmp byte ptr [ebp - 4], 6 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x3u)); /* add eax, 3 */
L_006e6cf9:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006e6cfc(CPU *c) { /* FUN_10006cfc */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    (void)sub32(c, R32((uint32_t)(c->esp + 0x8u)), c->eax); /* cmp dword ptr [esp + 8], eax */
    { uint32_t v_ = 0x1000u; PUSH32(c, v_); } /* push 0x1000 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete al */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x6ed050u)); PUSH32(c, 0x006e6d13u); call_indirect(c, t_); } /* call dword ptr [0x1000d050] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(0x778ec4u), (uint32_t)(c->eax)); /* mov dword ptr [0x10098ec4], eax */
    if (c->zf) goto L_006e6d52; /* je 0x6e6d52 */
    PUSH32(c, 0x006e6d21u); f_006e6bb4(c); /* call 0x6e6bb4 */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    W32((uint32_t)(0x778ec8u), (uint32_t)(c->eax)); /* mov dword ptr [0x10098ec8], eax */
    if (!c->zf) goto L_006e6d38; /* jne 0x6e6d38 */
    { uint32_t v_ = 0x3f8u; PUSH32(c, v_); } /* push 0x3f8 */
    PUSH32(c, 0x006e6d35u); f_006e844b(c); /* call 0x6e844b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_006e6d42; /* jmp 0x6e6d42 */
L_006e6d38:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_006e6d55; /* jne 0x6e6d55 */
    PUSH32(c, 0x006e6d42u); f_006e8f92(c); /* call 0x6e8f92 */
L_006e6d42:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006e6d55; /* jne 0x6e6d55 */
    { uint32_t v_ = R32((uint32_t)(0x778ec4u)); PUSH32(c, v_); } /* push dword ptr [0x10098ec4] */
    { uint32_t t_ = R32((uint32_t)(0x6ed04cu)); PUSH32(c, 0x006e6d52u); call_indirect(c, t_); } /* call dword ptr [0x1000d04c] */
L_006e6d52:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_006e6d55:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_006e6d59(CPU *c) { /* FUN_10006d59 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x778ec8u))); /* mov eax, dword ptr [0x10098ec8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_006e6dcb; /* jne 0x6e6dcb */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, R32((uint32_t)(0x778db4u)), c->ebx); /* cmp dword ptr [0x10098db4], ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(0x6ed018u))); /* mov ebp, dword ptr [0x1000d018] */
    if ((c->zf || c->sf != c->of)) goto L_006e6db7; /* jle 0x6e6db7 */
    c->eax = (uint32_t)(R32((uint32_t)(0x778db8u))); /* mov eax, dword ptr [0x10098db8] */
    c->edi = (uint32_t)(R32((uint32_t)(0x6ed054u))); /* mov edi, dword ptr [0x1000d054] */
    c->esi = (uint32_t)((uint32_t)(c->eax + 0xcu)); /* lea esi, [eax + 0xc] */
L_006e6d85:;
    { uint32_t v_ = 0x4000u; PUSH32(c, v_); } /* push 0x4000 */
    { uint32_t v_ = 0x100000u; PUSH32(c, v_); } /* push 0x100000 */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x006e6d93u); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = 0x8000u; PUSH32(c, v_); } /* push 0x8000 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x006e6d9eu); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esi + 4] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x778ec4u)); PUSH32(c, v_); } /* push dword ptr [0x10098ec4] */
    { uint32_t t_ = c->ebp; PUSH32(c, 0x006e6dabu); call_indirect(c, t_); } /* call ebp */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x14u)); /* add esi, 0x14 */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    (void)sub32(c, c->ebx, R32((uint32_t)(0x778db4u))); /* cmp ebx, dword ptr [0x10098db4] */
    if ((c->sf != c->of)) goto L_006e6d85; /* jl 0x6e6d85 */
L_006e6db7:;
    { uint32_t v_ = R32((uint32_t)(0x778db8u)); PUSH32(c, v_); } /* push dword ptr [0x10098db8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x778ec4u)); PUSH32(c, v_); } /* push dword ptr [0x10098ec4] */
    { uint32_t t_ = c->ebp; PUSH32(c, 0x006e6dc7u); call_indirect(c, t_); } /* call ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    goto L_006e6df2; /* jmp 0x6e6df2 */
L_006e6dcb:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_006e6df2; /* jne 0x6e6df2 */
    c->edi = (uint32_t)((uint32_t)0x6ee560u); /* mov edi, 0x1000e560 */
    c->esi = (uint32_t)(c->edi); /* mov esi, edi */
L_006e6dd7:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e6dec; /* je 0x6e6dec */
    { uint32_t v_ = 0x8000u; PUSH32(c, v_); } /* push 0x8000 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x6ed054u)); PUSH32(c, 0x006e6decu); call_indirect(c, t_); } /* call dword ptr [0x1000d054] */
L_006e6dec:;
    c->esi = (uint32_t)(R32((uint32_t)(c->esi))); /* mov esi, dword ptr [esi] */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_006e6dd7; /* jne 0x6e6dd7 */
L_006e6df2:;
    { uint32_t v_ = R32((uint32_t)(0x778ec4u)); PUSH32(c, v_); } /* push dword ptr [0x10098ec4] */
    { uint32_t t_ = R32((uint32_t)(0x6ed04cu)); PUSH32(c, 0x006e6dfeu); call_indirect(c, t_); } /* call dword ptr [0x1000d04c] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_006e6e01(CPU *c) { /* FUN_10006e01 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x44u)); /* sub esp, 0x44 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x100u; PUSH32(c, v_); } /* push 0x100 */
    PUSH32(c, 0x006e6e12u); f_006e5d19(c); /* call 0x6e5d19 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_006e6e21; /* jne 0x6e6e21 */
    { uint32_t v_ = 0x1bu; PUSH32(c, v_); } /* push 0x1b */
    PUSH32(c, 0x006e6e20u); f_006e49de(c); /* call 0x6e49de */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006e6e21:;
    W32((uint32_t)(0x778dc0u), (uint32_t)(c->esi)); /* mov dword ptr [0x10098dc0], esi */
    W32((uint32_t)(0x778ec0u), (uint32_t)((uint32_t)0x20u)); /* mov dword ptr [0x10098ec0], 0x20 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x100u)); /* lea eax, [esi + 0x100] */
L_006e6e37:;
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if (!c->cf) goto L_006e6e55; /* jae 0x6e6e55 */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [esi + 4], 0 */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [esi], 0xffffffff */
    W8((uint32_t)(c->esi + 0x5u), (uint8_t)((uint8_t)0xau)); /* mov byte ptr [esi + 5], 0xa */
    c->eax = (uint32_t)(R32((uint32_t)(0x778dc0u))); /* mov eax, dword ptr [0x10098dc0] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x8u)); /* add esi, 8 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x100u)); /* add eax, 0x100 */
    goto L_006e6e37; /* jmp 0x6e6e37 */
L_006e6e55:;
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x10u)); /* lea eax, [esp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x6ed064u)); PUSH32(c, 0x006e6e60u); call_indirect(c, t_); } /* call dword ptr [0x1000d064] */
    (void)sub16(c, R16((uint32_t)(c->esp + 0x42u)), (uint16_t)0x0u); /* cmp word ptr [esp + 0x42], 0 */
    if (c->zf) goto L_006e6f31; /* je 0x6e6f31 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x44u))); /* mov eax, dword ptr [esp + 0x44] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e6f31; /* je 0x6e6f31 */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax))); /* mov esi, dword ptr [eax] */
    c->ebp = (uint32_t)((uint32_t)(c->eax + 0x4u)); /* lea ebp, [eax + 4] */
    c->eax = (uint32_t)((uint32_t)0x800u); /* mov eax, 0x800 */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    c->ebx = (uint32_t)((uint32_t)(c->esi + c->ebp)); /* lea ebx, [esi + ebp] */
    if ((c->sf != c->of)) goto L_006e6e8b; /* jl 0x6e6e8b */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_006e6e8b:;
    (void)sub32(c, R32((uint32_t)(0x778ec0u)), c->esi); /* cmp dword ptr [0x10098ec0], esi */
    if ((c->sf == c->of)) goto L_006e6ee5; /* jge 0x6e6ee5 */
    c->edi = (uint32_t)((uint32_t)0x778dc4u); /* mov edi, 0x10098dc4 */
L_006e6e98:;
    { uint32_t v_ = 0x100u; PUSH32(c, v_); } /* push 0x100 */
    PUSH32(c, 0x006e6ea2u); f_006e5d19(c); /* call 0x6e5d19 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_006e6edf; /* je 0x6e6edf */
    { uint32_t a_ = (uint32_t)(0x778ec0u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x20u))); } /* add dword ptr [0x10098ec0], 0x20 */
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x100u)); /* lea ecx, [eax + 0x100] */
L_006e6eb6:;
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->cf) goto L_006e6ed2; /* jae 0x6e6ed2 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax + 4], 0 */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [eax], 0xffffffff */
    W8((uint32_t)(c->eax + 0x5u), (uint8_t)((uint8_t)0xau)); /* mov byte ptr [eax + 5], 0xa */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi))); /* mov ecx, dword ptr [edi] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x100u)); /* add ecx, 0x100 */
    goto L_006e6eb6; /* jmp 0x6e6eb6 */
L_006e6ed2:;
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    (void)sub32(c, R32((uint32_t)(0x778ec0u)), c->esi); /* cmp dword ptr [0x10098ec0], esi */
    if ((c->sf != c->of)) goto L_006e6e98; /* jl 0x6e6e98 */
    goto L_006e6ee5; /* jmp 0x6e6ee5 */
L_006e6edf:;
    c->esi = (uint32_t)(R32((uint32_t)(0x778ec0u))); /* mov esi, dword ptr [0x10098ec0] */
L_006e6ee5:;
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if ((c->zf || c->sf != c->of)) goto L_006e6f31; /* jle 0x6e6f31 */
L_006e6eeb:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (c->zf) goto L_006e6f28; /* je 0x6e6f28 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp))); /* mov cl, byte ptr [ebp] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x1u)); /* test cl, 1 */
    if (c->zf) goto L_006e6f28; /* je 0x6e6f28 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x8u)); /* test cl, 8 */
    if (!c->zf) goto L_006e6f0a; /* jne 0x6e6f0a */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x6ed060u)); PUSH32(c, 0x006e6f06u); call_indirect(c, t_); } /* call dword ptr [0x1000d060] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e6f28; /* je 0x6e6f28 */
L_006e6f0a:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    c->eax = (uint32_t)(sar32(c, c->eax, 5)); /* sar eax, 5 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x1fu))); /* and ecx, 0x1f */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax * 4 + 0x778dc0u))); /* mov eax, dword ptr [eax*4 + 0x10098dc0] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->ecx * 8)); /* lea eax, [eax + ecx*8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov ecx, dword ptr [ebx] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp))); /* mov cl, byte ptr [ebp] */
    W8((uint32_t)(c->eax + 0x4u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax + 4], cl */
L_006e6f28:;
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->ebp = (uint32_t)(inc32(c, c->ebp)); /* inc ebp */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x4u)); /* add ebx, 4 */
    (void)sub32(c, c->edi, c->esi); /* cmp edi, esi */
    if ((c->sf != c->of)) goto L_006e6eeb; /* jl 0x6e6eeb */
L_006e6f31:;
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
L_006e6f33:;
    c->eax = (uint32_t)(R32((uint32_t)(0x778dc0u))); /* mov eax, dword ptr [0x10098dc0] */
    (void)sub32(c, R32((uint32_t)(c->eax + c->ebx * 8)), (uint32_t)0xffffffffu); /* cmp dword ptr [eax + ebx*8], -1 */
    c->esi = (uint32_t)((uint32_t)(c->eax + c->ebx * 8)); /* lea esi, [eax + ebx*8] */
    if (!c->zf) goto L_006e6f8e; /* jne 0x6e6f8e */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    W8((uint32_t)(c->esi + 0x4u), (uint8_t)((uint8_t)0x81u)); /* mov byte ptr [esi + 4], 0x81 */
    if (!c->zf) goto L_006e6f4e; /* jne 0x6e6f4e */
    { uint32_t v_ = 0xfffffff6u; PUSH32(c, v_); } /* push -0xa */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_006e6f58; /* jmp 0x6e6f58 */
L_006e6f4e:;
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xfffffff5u)); /* add eax, -0xb */
L_006e6f58:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x6ed05cu)); PUSH32(c, 0x006e6f5fu); call_indirect(c, t_); } /* call dword ptr [0x1000d05c] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)sub32(c, c->edi, (uint32_t)0xffffffffu); /* cmp edi, -1 */
    if (c->zf) goto L_006e6f7d; /* je 0x6e6f7d */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0x6ed060u)); PUSH32(c, 0x006e6f6du); call_indirect(c, t_); } /* call dword ptr [0x1000d060] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e6f7d; /* je 0x6e6f7d */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xffu))); /* and eax, 0xff */
    W32((uint32_t)(c->esi), (uint32_t)(c->edi)); /* mov dword ptr [esi], edi */
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_006e6f83; /* jne 0x6e6f83 */
L_006e6f7d:;
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x40u)))); } /* or byte ptr [esi + 4], 0x40 */
    goto L_006e6f92; /* jmp 0x6e6f92 */
L_006e6f83:;
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_006e6f92; /* jne 0x6e6f92 */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x8u)))); } /* or byte ptr [esi + 4], 8 */
    goto L_006e6f92; /* jmp 0x6e6f92 */
L_006e6f8e:;
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x80u)))); } /* or byte ptr [esi + 4], 0x80 */
L_006e6f92:;
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    (void)sub32(c, c->ebx, (uint32_t)0x3u); /* cmp ebx, 3 */
    if ((c->sf != c->of)) goto L_006e6f33; /* jl 0x6e6f33 */
    { uint32_t v_ = R32((uint32_t)(0x778ec0u)); PUSH32(c, v_); } /* push dword ptr [0x10098ec0] */
    { uint32_t t_ = R32((uint32_t)(0x6ed058u)); PUSH32(c, 0x006e6fa4u); call_indirect(c, t_); } /* call dword ptr [0x1000d058] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x44u)); /* add esp, 0x44 */
    c->esp += 4; return; /* ret  */
}

void f_006e6fac(CPU *c) { /* FUN_10006fac */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)((uint32_t)0x778dc0u); /* mov esi, 0x10098dc0 */
L_006e6fb2:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e6fc2; /* je 0x6e6fc2 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e6fbeu); f_006e57b8(c); /* call 0x6e57b8 */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi], 0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006e6fc2:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, c->esi, (uint32_t)0x778ec0u); /* cmp esi, 0x10098ec0 */
    if ((c->sf != c->of)) goto L_006e6fb2; /* jl 0x6e6fb2 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_006e6fcf(CPU *c) { /* FUN_10006fcf */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, R32((uint32_t)(0x778ed0u)), c->ebx); /* cmp dword ptr [0x10098ed0], ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_006e6fe1; /* jne 0x6e6fe1 */
    PUSH32(c, 0x006e6fe1u); f_006eab53(c); /* call 0x6eab53 */
L_006e6fe1:;
    c->esi = (uint32_t)(R32((uint32_t)(0x777934u))); /* mov esi, dword ptr [0x10097934] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
L_006e6fe9:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_006e7001; /* je 0x6e7001 */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x3du); /* cmp al, 0x3d */
    if (c->zf) goto L_006e6ff4; /* je 0x6e6ff4 */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
L_006e6ff4:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006e6ffau); f_006e8280(c); /* call 0x6e8280 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esi = (uint32_t)((uint32_t)(c->esi + c->eax + 0x1u)); /* lea esi, [esi + eax + 1] */
    goto L_006e6fe9; /* jmp 0x6e6fe9 */
L_006e7001:;
    c->eax = (uint32_t)((uint32_t)(c->edi * 4 + 0x4u)); /* lea eax, [edi*4 + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e700eu); f_006e5d19(c); /* call 0x6e5d19 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    W32((uint32_t)(0x777990u), (uint32_t)(c->esi)); /* mov dword ptr [0x10097990], esi */
    if (!c->zf) goto L_006e7023; /* jne 0x6e7023 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x006e7022u); f_006e49de(c); /* call 0x6e49de */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006e7023:;
    c->edi = (uint32_t)(R32((uint32_t)(0x777934u))); /* mov edi, dword ptr [0x10097934] */
    (void)sub8(c, R8((uint32_t)(c->edi)), ((uint8_t)c->ebx)); /* cmp byte ptr [edi], bl */
    if (c->zf) goto L_006e7066; /* je 0x6e7066 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
L_006e702e:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006e7034u); f_006e8280(c); /* call 0x6e8280 */
    c->ebp = (uint32_t)(c->eax); /* mov ebp, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ebp = (uint32_t)(inc32(c, c->ebp)); /* inc ebp */
    (void)sub8(c, R8((uint32_t)(c->edi)), (uint8_t)0x3du); /* cmp byte ptr [edi], 0x3d */
    if (c->zf) goto L_006e705f; /* je 0x6e705f */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x006e7043u); f_006e5d19(c); /* call 0x6e5d19 */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    if (!c->zf) goto L_006e7052; /* jne 0x6e7052 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x006e7051u); f_006e49de(c); /* call 0x6e49de */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006e7052:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    PUSH32(c, 0x006e705au); f_006e7c50(c); /* call 0x6e7c50 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006e705f:;
    c->edi = (uint32_t)(add32(c, c->edi, c->ebp)); /* add edi, ebp */
    (void)sub8(c, R8((uint32_t)(c->edi)), ((uint8_t)c->ebx)); /* cmp byte ptr [edi], bl */
    if (!c->zf) goto L_006e702e; /* jne 0x6e702e */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
L_006e7066:;
    { uint32_t v_ = R32((uint32_t)(0x777934u)); PUSH32(c, v_); } /* push dword ptr [0x10097934] */
    PUSH32(c, 0x006e7071u); f_006e57b8(c); /* call 0x6e57b8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(0x777934u), (uint32_t)(c->ebx)); /* mov dword ptr [0x10097934], ebx */
    W32((uint32_t)(c->esi), (uint32_t)(c->ebx)); /* mov dword ptr [esi], ebx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0x778eccu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x10098ecc], 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_006e7088(CPU *c) { /* FUN_10007088 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, R32((uint32_t)(0x778ed0u)), c->ebx); /* cmp dword ptr [0x10098ed0], ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_006e709f; /* jne 0x6e709f */
    PUSH32(c, 0x006e709fu); f_006eab53(c); /* call 0x6eab53 */
L_006e709f:;
    c->esi = (uint32_t)((uint32_t)0x7779bcu); /* mov esi, 0x100979bc */
    { uint32_t v_ = 0x104u; PUSH32(c, v_); } /* push 0x104 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(0x6ed040u)); PUSH32(c, 0x006e70b1u); call_indirect(c, t_); } /* call dword ptr [0x1000d040] */
    c->eax = (uint32_t)(R32((uint32_t)(0x778edcu))); /* mov eax, dword ptr [0x10098edc] */
    W32((uint32_t)(0x7779a0u), (uint32_t)(c->esi)); /* mov dword ptr [0x100979a0], esi */
    c->edi = (uint32_t)(c->esi); /* mov edi, esi */
    (void)sub8(c, R8((uint32_t)(c->eax)), ((uint8_t)c->ebx)); /* cmp byte ptr [eax], bl */
    if (c->zf) goto L_006e70c4; /* je 0x6e70c4 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
L_006e70c4:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006e70d4u); f_006e7121(c); /* call 0x6e7121 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->ecx * 4)); /* lea eax, [eax + ecx*4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e70e3u); f_006e5d19(c); /* call 0x6e5d19 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (!c->zf) goto L_006e70f4; /* jne 0x6e70f4 */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    PUSH32(c, 0x006e70f3u); f_006e49de(c); /* call 0x6e49de */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006e70f4:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->eax * 4)); /* lea eax, [esi + eax*4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006e710au); f_006e7121(c); /* call 0x6e7121 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    W32((uint32_t)(0x777988u), (uint32_t)(c->esi)); /* mov dword ptr [0x10097988], esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0x777984u), (uint32_t)(c->eax)); /* mov dword ptr [0x10097984], eax */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006e7121(CPU *c) { /* FUN_10007121 */
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
    if (c->zf) goto L_006e714b; /* je 0x6e714b */
    W32((uint32_t)(c->edi), (uint32_t)(c->esi)); /* mov dword ptr [edi], esi */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 0xc], edi */
L_006e714b:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x22u); /* cmp byte ptr [eax], 0x22 */
    if (!c->zf) goto L_006e7194; /* jne 0x6e7194 */
L_006e7150:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1u))); /* mov dl, byte ptr [eax + 1] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x22u); /* cmp dl, 0x22 */
    if (c->zf) goto L_006e7182; /* je 0x6e7182 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_006e7182; /* je 0x6e7182 */
    c->edx = (uint32_t)((uint32_t)((uint8_t)c->edx)); /* movzx edx, dl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edx + 0x777c81u)) & (uint8_t)0x4u)); /* test byte ptr [edx + 0x10097c81], 4 */
    if (c->zf) goto L_006e7175; /* je 0x6e7175 */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_006e7175; /* je 0x6e7175 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
L_006e7175:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_006e7150; /* je 0x6e7150 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    goto L_006e7150; /* jmp 0x6e7150 */
L_006e7182:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_006e718c; /* je 0x6e718c */
    { uint32_t a_ = (uint32_t)(c->esi); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [esi], 0 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_006e718c:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x22u); /* cmp byte ptr [eax], 0x22 */
    if (!c->zf) goto L_006e71d7; /* jne 0x6e71d7 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_006e71d7; /* jmp 0x6e71d7 */
L_006e7194:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_006e719f; /* je 0x6e719f */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_006e719f:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ebx = (uint32_t)((uint32_t)((uint8_t)c->edx)); /* movzx ebx, dl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebx + 0x777c81u)) & (uint8_t)0x4u)); /* test byte ptr [ebx + 0x10097c81], 4 */
    if (c->zf) goto L_006e71ba; /* je 0x6e71ba */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_006e71b9; /* je 0x6e71b9 */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov bl, byte ptr [eax] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [esi], bl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_006e71b9:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
L_006e71ba:;
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x20u); /* cmp dl, 0x20 */
    if (c->zf) goto L_006e71c8; /* je 0x6e71c8 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_006e71cc; /* je 0x6e71cc */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x9u); /* cmp dl, 9 */
    if (!c->zf) goto L_006e7194; /* jne 0x6e7194 */
L_006e71c8:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (!c->zf) goto L_006e71cf; /* jne 0x6e71cf */
L_006e71cc:;
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    goto L_006e71d7; /* jmp 0x6e71d7 */
L_006e71cf:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_006e71d7; /* je 0x6e71d7 */
    { uint32_t a_ = (uint32_t)(c->esi + 0xffffffffu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [esi - 1], 0 */
L_006e71d7:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0x18u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp + 0x18], 0 */
L_006e71db:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (c->zf) goto L_006e72c4; /* je 0x6e72c4 */
L_006e71e4:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x20u); /* cmp dl, 0x20 */
    if (c->zf) goto L_006e71f0; /* je 0x6e71f0 */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x9u); /* cmp dl, 9 */
    if (!c->zf) goto L_006e71f3; /* jne 0x6e71f3 */
L_006e71f0:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_006e71e4; /* jmp 0x6e71e4 */
L_006e71f3:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (c->zf) goto L_006e72c4; /* je 0x6e72c4 */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_006e7208; /* je 0x6e7208 */
    W32((uint32_t)(c->edi), (uint32_t)(c->esi)); /* mov dword ptr [edi], esi */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 0xc], edi */
L_006e7208:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov edx, dword ptr [ebp + 0x14] */
    { uint32_t a_ = (uint32_t)(c->edx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [edx] */
L_006e720d:;
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp + 8], 1 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
L_006e7216:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x5cu); /* cmp byte ptr [eax], 0x5c */
    if (!c->zf) goto L_006e721f; /* jne 0x6e721f */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    goto L_006e7216; /* jmp 0x6e7216 */
L_006e721f:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x22u); /* cmp byte ptr [eax], 0x22 */
    if (!c->zf) goto L_006e7250; /* jne 0x6e7250 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x1u)); /* test bl, 1 */
    if (!c->zf) goto L_006e724e; /* jne 0x6e724e */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x18u)), c->edi); /* cmp dword ptr [ebp + 0x18], edi */
    if (c->zf) goto L_006e723d; /* je 0x6e723d */
    (void)sub8(c, R8((uint32_t)(c->eax + 0x1u)), (uint8_t)0x22u); /* cmp byte ptr [eax + 1], 0x22 */
    c->edx = (uint32_t)((uint32_t)(c->eax + 0x1u)); /* lea edx, [eax + 1] */
    if (!c->zf) goto L_006e723d; /* jne 0x6e723d */
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    goto L_006e7240; /* jmp 0x6e7240 */
L_006e723d:;
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 8], edi */
L_006e7240:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x18u)), c->edx); /* cmp dword ptr [ebp + 0x18], edx */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete dl */
    W32((uint32_t)(c->ebp + 0x18u), (uint32_t)(c->edx)); /* mov dword ptr [ebp + 0x18], edx */
L_006e724e:;
    c->ebx = (uint32_t)(shr32(c, c->ebx, 1)); /* shr ebx, 1 */
L_006e7250:;
    c->edx = (uint32_t)(c->ebx); /* mov edx, ebx */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_006e7265; /* je 0x6e7265 */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
L_006e7258:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_006e7260; /* je 0x6e7260 */
    W8((uint32_t)(c->esi), (uint8_t)((uint8_t)0x5cu)); /* mov byte ptr [esi], 0x5c */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_006e7260:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->zf) goto L_006e7258; /* jne 0x6e7258 */
L_006e7265:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_006e72b5; /* je 0x6e72b5 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x18u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x18], 0 */
    if (!c->zf) goto L_006e727b; /* jne 0x6e727b */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x20u); /* cmp dl, 0x20 */
    if (c->zf) goto L_006e72b5; /* je 0x6e72b5 */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x9u); /* cmp dl, 9 */
    if (c->zf) goto L_006e72b5; /* je 0x6e72b5 */
L_006e727b:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    if (c->zf) goto L_006e72af; /* je 0x6e72af */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_006e729e; /* je 0x6e729e */
    c->ebx = (uint32_t)((uint32_t)((uint8_t)c->edx)); /* movzx ebx, dl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebx + 0x777c81u)) & (uint8_t)0x4u)); /* test byte ptr [ebx + 0x10097c81], 4 */
    if (c->zf) goto L_006e7297; /* je 0x6e7297 */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
L_006e7297:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    goto L_006e72ad; /* jmp 0x6e72ad */
L_006e729e:;
    c->edx = (uint32_t)((uint32_t)((uint8_t)c->edx)); /* movzx edx, dl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edx + 0x777c81u)) & (uint8_t)0x4u)); /* test byte ptr [edx + 0x10097c81], 4 */
    if (c->zf) goto L_006e72ad; /* je 0x6e72ad */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
L_006e72ad:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
L_006e72af:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_006e720d; /* jmp 0x6e720d */
L_006e72b5:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_006e72bd; /* je 0x6e72bd */
    { uint32_t a_ = (uint32_t)(c->esi); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [esi], 0 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_006e72bd:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    goto L_006e71db; /* jmp 0x6e71db */
L_006e72c4:;
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_006e72cb; /* je 0x6e72cb */
    { uint32_t a_ = (uint32_t)(c->edi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [edi], 0 */
L_006e72cb:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [eax] */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_006e72d5(CPU *c) { /* FUN_100072d5 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(0x777ac0u))); /* mov eax, dword ptr [0x10097ac0] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(0x6ed078u))); /* mov ebp, dword ptr [0x1000d078] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (!c->zf) goto L_006e7323; /* jne 0x6e7323 */
    { uint32_t t_ = c->ebp; PUSH32(c, 0x006e72f2u); call_indirect(c, t_); } /* call ebp */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (c->zf) goto L_006e7304; /* je 0x6e7304 */
    W32((uint32_t)(0x777ac0u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x10097ac0], 1 */
    goto L_006e732c; /* jmp 0x6e732c */
L_006e7304:;
    { uint32_t t_ = R32((uint32_t)(0x6ed074u)); PUSH32(c, 0x006e730au); call_indirect(c, t_); } /* call dword ptr [0x1000d074] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    if (c->zf) goto L_006e73fe; /* je 0x6e73fe */
    W32((uint32_t)(0x777ac0u), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [0x10097ac0], 2 */
    goto L_006e73b2; /* jmp 0x6e73b2 */
L_006e7323:;
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_006e73ad; /* jne 0x6e73ad */
L_006e732c:;
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (!c->zf) goto L_006e733c; /* jne 0x6e733c */
    { uint32_t t_ = c->ebp; PUSH32(c, 0x006e7332u); call_indirect(c, t_); } /* call ebp */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (c->zf) goto L_006e73fe; /* je 0x6e73fe */
L_006e733c:;
    (void)sub16(c, R16((uint32_t)(c->esi)), ((uint16_t)c->ebx)); /* cmp word ptr [esi], bx */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    if (c->zf) goto L_006e7351; /* je 0x6e7351 */
L_006e7343:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub16(c, R16((uint32_t)(c->eax)), ((uint16_t)c->ebx)); /* cmp word ptr [eax], bx */
    if (!c->zf) goto L_006e7343; /* jne 0x6e7343 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub16(c, R16((uint32_t)(c->eax)), ((uint16_t)c->ebx)); /* cmp word ptr [eax], bx */
    if (!c->zf) goto L_006e7343; /* jne 0x6e7343 */
L_006e7351:;
    c->eax = (uint32_t)(sub32(c, c->eax, c->esi)); /* sub eax, esi */
    c->edi = (uint32_t)(R32((uint32_t)(0x6ed070u))); /* mov edi, dword ptr [0x1000d070] */
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
    { uint32_t t_ = c->edi; PUSH32(c, 0x006e736au); call_indirect(c, t_); } /* call edi */
    c->ebp = (uint32_t)(c->eax); /* mov ebp, eax */
    (void)sub32(c, c->ebp, c->ebx); /* cmp ebp, ebx */
    if (c->zf) goto L_006e73a2; /* je 0x6e73a2 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x006e7376u); f_006e5d19(c); /* call 0x6e5d19 */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    if (c->zf) goto L_006e73a2; /* je 0x6e73a2 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x24u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x24] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = c->edi; PUSH32(c, 0x006e738cu); call_indirect(c, t_); } /* call edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006e739e; /* jne 0x6e739e */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    PUSH32(c, 0x006e7399u); f_006e57b8(c); /* call 0x6e57b8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x10], ebx */
L_006e739e:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ebx, dword ptr [esp + 0x10] */
L_006e73a2:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(0x6ed06cu)); PUSH32(c, 0x006e73a9u); call_indirect(c, t_); } /* call dword ptr [0x1000d06c] */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    goto L_006e7400; /* jmp 0x6e7400 */
L_006e73ad:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_006e73fe; /* jne 0x6e73fe */
L_006e73b2:;
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    if (!c->zf) goto L_006e73c2; /* jne 0x6e73c2 */
    { uint32_t t_ = R32((uint32_t)(0x6ed074u)); PUSH32(c, 0x006e73bcu); call_indirect(c, t_); } /* call dword ptr [0x1000d074] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    if (c->zf) goto L_006e73fe; /* je 0x6e73fe */
L_006e73c2:;
    (void)sub8(c, R8((uint32_t)(c->edi)), ((uint8_t)c->ebx)); /* cmp byte ptr [edi], bl */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    if (c->zf) goto L_006e73d2; /* je 0x6e73d2 */
L_006e73c8:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), ((uint8_t)c->ebx)); /* cmp byte ptr [eax], bl */
    if (!c->zf) goto L_006e73c8; /* jne 0x6e73c8 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), ((uint8_t)c->ebx)); /* cmp byte ptr [eax], bl */
    if (!c->zf) goto L_006e73c8; /* jne 0x6e73c8 */
L_006e73d2:;
    c->eax = (uint32_t)(sub32(c, c->eax, c->edi)); /* sub eax, edi */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ebp = (uint32_t)(c->eax); /* mov ebp, eax */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x006e73ddu); f_006e5d19(c); /* call 0x6e5d19 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (!c->zf) goto L_006e73e8; /* jne 0x6e73e8 */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    goto L_006e73f3; /* jmp 0x6e73f3 */
L_006e73e8:;
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006e73f0u); f_006e9680(c); /* call 0x6e9680 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_006e73f3:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0x6ed068u)); PUSH32(c, 0x006e73fau); call_indirect(c, t_); } /* call dword ptr [0x1000d068] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    goto L_006e7400; /* jmp 0x6e7400 */
L_006e73fe:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_006e7400:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_006e7407(CPU *c) { /* FUN_10007407 */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->esp + 0x8u)), (uint32_t)0x1u); /* cmp dword ptr [esp + 8], 1 */
    if (!c->zf) goto L_006e7421; /* jne 0x6e7421 */
    (void)sub32(c, R32((uint32_t)(0x778ee0u)), (uint32_t)0x0u); /* cmp dword ptr [0x10098ee0], 0 */
    if (!c->zf) goto L_006e7421; /* jne 0x6e7421 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    { uint32_t t_ = R32((uint32_t)(0x6ed07cu)); PUSH32(c, 0x006e7421u); call_indirect(c, t_); } /* call dword ptr [0x1000d07c] */
L_006e7421:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 16; return; /* ret 0xc */
}

void f_006e7427(CPU *c) { /* FUN_10007427 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x77793cu))); /* mov eax, dword ptr [0x1009793c] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_006e743e; /* je 0x6e743e */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006e745f; /* jne 0x6e745f */
    (void)sub32(c, R32((uint32_t)(0x777940u)), (uint32_t)0x1u); /* cmp dword ptr [0x10097940], 1 */
    if (!c->zf) goto L_006e745f; /* jne 0x6e745f */
L_006e743e:;
    { uint32_t v_ = 0xfcu; PUSH32(c, v_); } /* push 0xfc */
    PUSH32(c, 0x006e7448u); f_006e7460(c); /* call 0x6e7460 */
    c->eax = (uint32_t)(R32((uint32_t)(0x777ac4u))); /* mov eax, dword ptr [0x10097ac4] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e7454; /* je 0x6e7454 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x006e7454u); call_indirect(c, t_); } /* call eax */
L_006e7454:;
    { uint32_t v_ = 0xffu; PUSH32(c, v_); } /* push 0xff */
    PUSH32(c, 0x006e745eu); f_006e7460(c); /* call 0x6e7460 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006e745f:;
    c->esp += 4; return; /* ret  */
}

void f_006e7460(CPU *c) { /* FUN_10007460 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x1a4u)); /* sub esp, 0x1a4 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->eax = (uint32_t)((uint32_t)0x6ee288u); /* mov eax, 0x1000e288 */
L_006e7473:;
    (void)sub32(c, c->edx, R32((uint32_t)(c->eax))); /* cmp edx, dword ptr [eax] */
    if (c->zf) goto L_006e7482; /* je 0x6e7482 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->eax, (uint32_t)0x6ee318u); /* cmp eax, 0x1000e318 */
    if ((c->sf != c->of)) goto L_006e7473; /* jl 0x6e7473 */
L_006e7482:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->esi = (uint32_t)(shl32(c, c->esi, 3)); /* shl esi, 3 */
    (void)sub32(c, c->edx, R32((uint32_t)(c->esi + 0x6ee288u))); /* cmp edx, dword ptr [esi + 0x1000e288] */
    if (!c->zf) goto L_006e75b0; /* jne 0x6e75b0 */
    c->eax = (uint32_t)(R32((uint32_t)(0x77793cu))); /* mov eax, dword ptr [0x1009793c] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_006e758a; /* je 0x6e758a */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006e74b3; /* jne 0x6e74b3 */
    (void)sub32(c, R32((uint32_t)(0x777940u)), (uint32_t)0x1u); /* cmp dword ptr [0x10097940], 1 */
    if (c->zf) goto L_006e758a; /* je 0x6e758a */
L_006e74b3:;
    (void)sub32(c, c->edx, (uint32_t)0xfcu); /* cmp edx, 0xfc */
    if (c->zf) goto L_006e75b0; /* je 0x6e75b0 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea eax, [ebp - 0x1a4] */
    { uint32_t v_ = 0x104u; PUSH32(c, v_); } /* push 0x104 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t t_ = R32((uint32_t)(0x6ed040u)); PUSH32(c, 0x006e74d3u); call_indirect(c, t_); } /* call dword ptr [0x1000d040] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006e74ea; /* jne 0x6e74ea */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea eax, [ebp - 0x1a4] */
    { uint32_t v_ = 0x6ed7acu; PUSH32(c, v_); } /* push 0x1000d7ac */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e74e8u); f_006e7c50(c); /* call 0x6e7c50 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006e74ea:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea eax, [ebp - 0x1a4] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea edi, [ebp - 0x1a4] */
    PUSH32(c, 0x006e74fdu); f_006e8280(c); /* call 0x6e8280 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->eax, (uint32_t)0x3cu); /* cmp eax, 0x3c */
    if ((c->cf || c->zf)) goto L_006e752d; /* jbe 0x6e752d */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea eax, [ebp - 0x1a4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e7510u); f_006e8280(c); /* call 0x6e8280 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea eax, [ebp - 0x1a4] */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3bu)); /* sub eax, 0x3b */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t v_ = 0x6ed7a8u; PUSH32(c, v_); } /* push 0x1000d7a8 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006e752au); f_006eac00(c); /* call 0x6eac00 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_006e752d:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff60u)); /* lea eax, [ebp - 0xa0] */
    { uint32_t v_ = 0x6ed78cu; PUSH32(c, v_); } /* push 0x1000d78c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e753eu); f_006e7c50(c); /* call 0x6e7c50 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff60u)); /* lea eax, [ebp - 0xa0] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e754bu); f_006e7c60(c); /* call 0x6e7c60 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff60u)); /* lea eax, [ebp - 0xa0] */
    { uint32_t v_ = 0x6ed788u; PUSH32(c, v_); } /* push 0x1000d788 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e755cu); f_006e7c60(c); /* call 0x6e7c60 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x6ee28cu)); PUSH32(c, v_); } /* push dword ptr [esi + 0x1000e28c] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff60u)); /* lea eax, [ebp - 0xa0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e756eu); f_006e7c60(c); /* call 0x6e7c60 */
    { uint32_t v_ = 0x12010u; PUSH32(c, v_); } /* push 0x12010 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff60u)); /* lea eax, [ebp - 0xa0] */
    { uint32_t v_ = 0x6ed760u; PUSH32(c, v_); } /* push 0x1000d760 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e7584u); f_006eab6f(c); /* call 0x6eab6f */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    goto L_006e75b0; /* jmp 0x6e75b0 */
L_006e758a:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x8u)); /* lea eax, [ebp + 8] */
    c->esi = (uint32_t)((uint32_t)(c->esi + 0x6ee28cu)); /* lea esi, [esi + 0x1000e28c] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    PUSH32(c, 0x006e759du); f_006e8280(c); /* call 0x6e8280 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    { uint32_t v_ = 0xfffffff4u; PUSH32(c, v_); } /* push -0xc */
    { uint32_t t_ = R32((uint32_t)(0x6ed05cu)); PUSH32(c, 0x006e75a9u); call_indirect(c, t_); } /* call dword ptr [0x1000d05c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x6ed080u)); PUSH32(c, 0x006e75b0u); call_indirect(c, t_); } /* call dword ptr [0x1000d080] */
L_006e75b0:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006e75b3(CPU *c) { /* FUN_100075b3 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    ; /* wait  */
    W16((uint32_t)(c->ebp + 0xfffffffcu), c->fpu_cw); /* fnstcw word ptr [ebp - 4] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    PUSH32(c, 0x006e75c4u); f_006e75fe(c); /* call 0x6e75fe */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)((uint32_t)~c->eax); /* not eax */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & c->eax))); /* and esi, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & R32((uint32_t)(c->ebp + 0xcu))))); /* and eax, dword ptr [ebp + 0xc] */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi | c->eax))); /* or esi, eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006e75dbu); f_006e7690(c); /* call 0x6e7690 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0xc], eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->fpu_cw = R16((uint32_t)(c->ebp + 0xcu)); fpu_sync_rounding(c); /* fldcw word ptr [ebp + 0xc] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006e75e8(CPU *c) { /* FUN_100075e8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xfff7ffffu))); /* and eax, 0xfff7ffff */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    PUSH32(c, 0x006e75fbu); f_006e75b3(c); /* call 0x6e75b3 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_006e75fe(CPU *c) { /* FUN_100075fe */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ebx, dword ptr [esp + 8] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x1u)); /* test bl, 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (c->zf) goto L_006e760f; /* je 0x6e760f */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_006e760f:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x4u)); /* test bl, 4 */
    if (c->zf) goto L_006e7616; /* je 0x6e7616 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x8u))); /* or al, 8 */
L_006e7616:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x8u)); /* test bl, 8 */
    if (c->zf) goto L_006e761d; /* je 0x6e761d */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x4u))); /* or al, 4 */
L_006e761d:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x10u)); /* test bl, 0x10 */
    if (c->zf) goto L_006e7624; /* je 0x6e7624 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x2u))); /* or al, 2 */
L_006e7624:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x20u)); /* test bl, 0x20 */
    if (c->zf) goto L_006e762b; /* je 0x6e762b */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x1u))); /* or al, 1 */
L_006e762b:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x2u)); /* test bl, 2 */
    if (c->zf) goto L_006e7635; /* je 0x6e7635 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0x80000u))); /* or eax, 0x80000 */
L_006e7635:;
    c->ecx = (uint32_t)((uint32_t)((uint16_t)c->ebx)); /* movzx ecx, bx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    c->esi = (uint32_t)((uint32_t)0xc00u); /* mov esi, 0xc00 */
    c->edi = (uint32_t)((uint32_t)0x300u); /* mov edi, 0x300 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & c->esi))); /* and edx, esi */
    c->ebp = (uint32_t)((uint32_t)0x200u); /* mov ebp, 0x200 */
    if (c->zf) goto L_006e766d; /* je 0x6e766d */
    (void)sub32(c, c->edx, (uint32_t)0x400u); /* cmp edx, 0x400 */
    if (c->zf) goto L_006e766a; /* je 0x6e766a */
    (void)sub32(c, c->edx, (uint32_t)0x800u); /* cmp edx, 0x800 */
    if (c->zf) goto L_006e7666; /* je 0x6e7666 */
    (void)sub32(c, c->edx, c->esi); /* cmp edx, esi */
    if (!c->zf) goto L_006e766d; /* jne 0x6e766d */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->edi))); /* or eax, edi */
    goto L_006e766d; /* jmp 0x6e766d */
L_006e7666:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->ebp))); /* or eax, ebp */
    goto L_006e766d; /* jmp 0x6e766d */
L_006e766a:;
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | (uint8_t)0x1u))) << 8); /* or ah, 1 */
L_006e766d:;
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & c->edi))); /* and ecx, edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    if (c->zf) goto L_006e767d; /* je 0x6e767d */
    (void)sub32(c, c->ecx, c->ebp); /* cmp ecx, ebp */
    if (!c->zf) goto L_006e7682; /* jne 0x6e7682 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0x10000u))); /* or eax, 0x10000 */
    goto L_006e7682; /* jmp 0x6e7682 */
L_006e767d:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0x20000u))); /* or eax, 0x20000 */
L_006e7682:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->ebx >> 8)) & (uint8_t)0x10u)); /* test bh, 0x10 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    if (c->zf) goto L_006e768f; /* je 0x6e768f */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0x40000u))); /* or eax, 0x40000 */
L_006e768f:;
    c->esp += 4; return; /* ret  */
}

void f_006e7690(CPU *c) { /* FUN_10007690 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ebx, dword ptr [esp + 8] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x10u)); /* test bl, 0x10 */
    if (c->zf) goto L_006e76a0; /* je 0x6e76a0 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_006e76a0:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x8u)); /* test bl, 8 */
    if (c->zf) goto L_006e76a7; /* je 0x6e76a7 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x4u))); /* or al, 4 */
L_006e76a7:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x4u)); /* test bl, 4 */
    if (c->zf) goto L_006e76ae; /* je 0x6e76ae */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x8u))); /* or al, 8 */
L_006e76ae:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x2u)); /* test bl, 2 */
    if (c->zf) goto L_006e76b5; /* je 0x6e76b5 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x10u))); /* or al, 0x10 */
L_006e76b5:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x1u)); /* test bl, 1 */
    if (c->zf) goto L_006e76bc; /* je 0x6e76bc */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x20u))); /* or al, 0x20 */
L_006e76bc:;
    (void)logic32(c, (uint32_t)(c->ebx & (uint32_t)0x80000u)); /* test ebx, 0x80000 */
    if (c->zf) goto L_006e76c6; /* je 0x6e76c6 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x2u))); /* or al, 2 */
L_006e76c6:;
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    c->edx = (uint32_t)((uint32_t)0x300u); /* mov edx, 0x300 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & c->edx))); /* and ecx, edx */
    c->esi = (uint32_t)((uint32_t)0x200u); /* mov esi, 0x200 */
    if (c->zf) goto L_006e76f3; /* je 0x6e76f3 */
    (void)sub32(c, c->ecx, (uint32_t)0x100u); /* cmp ecx, 0x100 */
    if (c->zf) goto L_006e76f0; /* je 0x6e76f0 */
    (void)sub32(c, c->ecx, c->esi); /* cmp ecx, esi */
    if (c->zf) goto L_006e76eb; /* je 0x6e76eb */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if (!c->zf) goto L_006e76f3; /* jne 0x6e76f3 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | (uint8_t)0xcu))) << 8); /* or ah, 0xc */
    goto L_006e76f3; /* jmp 0x6e76f3 */
L_006e76eb:;
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | (uint8_t)0x8u))) << 8); /* or ah, 8 */
    goto L_006e76f3; /* jmp 0x6e76f3 */
L_006e76f0:;
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | (uint8_t)0x4u))) << 8); /* or ah, 4 */
L_006e76f3:;
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x30000u))); /* and ecx, 0x30000 */
    if (c->zf) goto L_006e7709; /* je 0x6e7709 */
    (void)sub32(c, c->ecx, (uint32_t)0x10000u); /* cmp ecx, 0x10000 */
    if (!c->zf) goto L_006e770b; /* jne 0x6e770b */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->esi))); /* or eax, esi */
    goto L_006e770b; /* jmp 0x6e770b */
L_006e7709:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->edx))); /* or eax, edx */
L_006e770b:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    (void)logic32(c, (uint32_t)(c->ebx & (uint32_t)0x40000u)); /* test ebx, 0x40000 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    if (c->zf) goto L_006e7718; /* je 0x6e7718 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | (uint8_t)0x10u))) << 8); /* or ah, 0x10 */
L_006e7718:;
    c->esp += 4; return; /* ret  */
}

void f_006e7719(CPU *c) { /* FUN_10007719 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x1u)); /* lea ecx, [eax + 1] */
    (void)sub32(c, c->ecx, (uint32_t)0x100u); /* cmp ecx, 0x100 */
    if ((!c->cf && !c->zf)) goto L_006e7737; /* ja 0x6e7737 */
    c->ecx = (uint32_t)(R32((uint32_t)(0x6ee324u))); /* mov ecx, dword ptr [0x1000e324] */
    c->eax = (uint32_t)((uint32_t)R16((uint32_t)(c->ecx + c->eax * 2))); /* movzx eax, word ptr [ecx + eax*2] */
    goto L_006e7789; /* jmp 0x6e7789 */
L_006e7737:;
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(0x6ee324u))); /* mov esi, dword ptr [0x1000e324] */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 8)); /* sar ecx, 8 */
    c->edx = (uint32_t)((uint32_t)((uint8_t)c->ecx)); /* movzx edx, cl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi + c->edx * 2 + 0x1u)) & (uint8_t)0x80u)); /* test byte ptr [esi + edx*2 + 1], 0x80 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    if (c->zf) goto L_006e775c; /* je 0x6e775c */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffeu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp - 2], 0 */
    W8((uint32_t)(c->ebp + 0xfffffffcu), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [ebp - 4], cl */
    W8((uint32_t)(c->ebp + 0xfffffffdu), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp - 3], al */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    goto L_006e7765; /* jmp 0x6e7765 */
L_006e775c:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffdu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp - 3], 0 */
    W8((uint32_t)(c->ebp + 0xfffffffcu), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp - 4], al */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
L_006e7765:;
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
    PUSH32(c, 0x006e777cu); f_006eacfe(c); /* call 0x6eacfe */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006e7785; /* jne 0x6e7785 */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e7785:;
    c->eax = (uint32_t)((uint32_t)R16((uint32_t)(c->ebp + 0xau))); /* movzx eax, word ptr [ebp + 0xa] */
L_006e7789:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & R32((uint32_t)(c->ebp + 0xcu))))); /* and eax, dword ptr [ebp + 0xc] */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006e778e(CPU *c) { /* FUN_1000778e */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    (void)sub32(c, R32((uint32_t)(0x777b30u)), (uint32_t)0x0u); /* cmp dword ptr [0x10097b30], 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_006e77bb; /* jne 0x6e77bb */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)sub32(c, c->eax, (uint32_t)0x41u); /* cmp eax, 0x41 */
    if ((c->sf != c->of)) goto L_006e7854; /* jl 0x6e7854 */
    (void)sub32(c, c->eax, (uint32_t)0x5au); /* cmp eax, 0x5a */
    if ((!c->zf && c->sf == c->of)) goto L_006e7854; /* jg 0x6e7854 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x20u)); /* add eax, 0x20 */
    goto L_006e7854; /* jmp 0x6e7854 */
L_006e77bb:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    c->edi = (uint32_t)((uint32_t)0x100u); /* mov edi, 0x100 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    if ((c->sf == c->of)) goto L_006e77ef; /* jge 0x6e77ef */
    (void)sub32(c, R32((uint32_t)(0x6ee318u)), c->esi); /* cmp dword ptr [0x1000e318], esi */
    if ((c->zf || c->sf != c->of)) goto L_006e77dd; /* jle 0x6e77dd */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x006e77d9u); f_006e7719(c); /* call 0x6e7719 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_006e77e7; /* jmp 0x6e77e7 */
L_006e77dd:;
    c->eax = (uint32_t)(R32((uint32_t)(0x6ee324u))); /* mov eax, dword ptr [0x1000e324] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + c->ebx * 2))); /* mov al, byte ptr [eax + ebx*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & c->esi))); /* and eax, esi */
L_006e77e7:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006e77ef; /* jne 0x6e77ef */
L_006e77eb:;
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    goto L_006e7854; /* jmp 0x6e7854 */
L_006e77ef:;
    c->edx = (uint32_t)(R32((uint32_t)(0x6ee324u))); /* mov edx, dword ptr [0x1000e324] */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->eax = (uint32_t)(sar32(c, c->eax, 8)); /* sar eax, 8 */
    c->ecx = (uint32_t)((uint32_t)((uint8_t)c->eax)); /* movzx ecx, al */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edx + c->ecx * 2 + 0x1u)) & (uint8_t)0x80u)); /* test byte ptr [edx + ecx*2 + 1], 0x80 */
    if (c->zf) goto L_006e7813; /* je 0x6e7813 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xau); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp + 0xa], 0 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    W8((uint32_t)(c->ebp + 0x8u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp + 8], al */
    W8((uint32_t)(c->ebp + 0x9u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ebp + 9], bl */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_006e781c; /* jmp 0x6e781c */
L_006e7813:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0x9u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp + 9], 0 */
    W8((uint32_t)(c->ebp + 0x8u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ebp + 8], bl */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_006e781c:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea ecx, [ebp - 4] */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x8u)); /* lea eax, [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0x777b30u)); PUSH32(c, v_); } /* push dword ptr [0x10097b30] */
    PUSH32(c, 0x006e7836u); f_006eae47(c); /* call 0x6eae47 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e77eb; /* je 0x6e77eb */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (!c->zf) goto L_006e7847; /* jne 0x6e7847 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0xfffffffcu))); /* movzx eax, byte ptr [ebp - 4] */
    goto L_006e7854; /* jmp 0x6e7854 */
L_006e7847:;
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0xfffffffdu))); /* movzx eax, byte ptr [ebp - 3] */
    c->ecx = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0xfffffffcu))); /* movzx ecx, byte ptr [ebp - 4] */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->ecx))); /* or eax, ecx */
L_006e7854:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006e7859(CPU *c) { /* FUN_10007859 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x20u; PUSH32(c, v_); } /* push 0x20 */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { int32_t d_ = (int32_t)c->ecx; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x006e7862u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv ecx */
    { uint32_t v_ = 0x1fu; PUSH32(c, v_); } /* push 0x1f */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)c->ecx; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x006e786du, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->edx)); /* sub ecx, edx */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx | (uint32_t)0xffffffffu))); /* or edx, 0xffffffff */
    c->edx = (uint32_t)(shl32(c, c->edx, (c->ecx & 0xff))); /* shl edx, cl */
    c->edx = (uint32_t)((uint32_t)~c->edx); /* not edx */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->eax + c->esi * 4)) & c->edx)); /* test dword ptr [eax + esi*4], edx */
    if (!c->zf) goto L_006e789e; /* jne 0x6e789e */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub32(c, c->esi, (uint32_t)0x3u); /* cmp esi, 3 */
    if ((c->sf == c->of)) goto L_006e7899; /* jge 0x6e7899 */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->esi * 4)); /* lea eax, [eax + esi*4] */
L_006e788b:;
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0x0u); /* cmp dword ptr [eax], 0 */
    if (!c->zf) goto L_006e789e; /* jne 0x6e789e */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x4u)); /* add eax, 4 */
    (void)sub32(c, c->esi, (uint32_t)0x3u); /* cmp esi, 3 */
    if ((c->sf != c->of)) goto L_006e788b; /* jl 0x6e788b */
L_006e7899:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_006e789e:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_006e78a2(CPU *c) { /* FUN_100078a2 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x20u; PUSH32(c, v_); } /* push 0x20 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ebx, dword ptr [esp + 0x14] */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { int32_t d_ = (int32_t)c->ecx; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x006e78b1u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv ecx */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)c->ecx; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x006e78bau, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv ecx */
    c->edi = (uint32_t)((uint32_t)(c->ebx + c->esi * 4)); /* lea edi, [ebx + esi*4] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x1fu; PUSH32(c, v_); } /* push 0x1f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->edx)); /* sub ecx, edx */
    c->eax = (uint32_t)(shl32(c, c->eax, (c->ecx & 0xff))); /* shl eax, cl */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->edi)); PUSH32(c, v_); } /* push dword ptr [edi] */
    PUSH32(c, 0x006e78d2u); f_006eb096(c); /* call 0x6eb096 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    if (c->sf) goto L_006e78f4; /* js 0x6e78f4 */
    c->edi = (uint32_t)((uint32_t)(c->ebx + c->esi * 4)); /* lea edi, [ebx + esi*4] */
L_006e78db:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e78f4; /* je 0x6e78f4 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->edi)); PUSH32(c, v_); } /* push dword ptr [edi] */
    PUSH32(c, 0x006e78e9u); f_006eb096(c); /* call 0x6eb096 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    c->edi = (uint32_t)(sub32(c, c->edi, (uint32_t)0x4u)); /* sub edi, 4 */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if ((c->sf == c->of)) goto L_006e78db; /* jge 0x6e78db */
L_006e78f4:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_006e78f8(CPU *c) { /* FUN_100078f8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)((uint32_t)(c->eax + 0xffffffffu)); /* lea edi, [eax - 1] */
    { uint32_t v_ = 0x20u; PUSH32(c, v_); } /* push 0x20 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    c->ebx = (uint32_t)((uint32_t)(c->edi + 0x1u)); /* lea ebx, [edi + 1] */
    { uint32_t v_ = 0x20u; PUSH32(c, v_); } /* push 0x20 */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)c->ecx; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x006e7916u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv ecx */
    { uint32_t v_ = 0x1fu; PUSH32(c, v_); } /* push 0x1f */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x006e791fu, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->ecx * 4)); /* lea eax, [eax + ecx*4] */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0xc], eax */
    c->esi = (uint32_t)(sub32(c, c->esi, c->edx)); /* sub esi, edx */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->edx = (uint32_t)(shl32(c, c->edx, (c->ecx & 0xff))); /* shl edx, cl */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->eax)) & c->edx)); /* test dword ptr [eax], edx */
    if (c->zf) goto L_006e795c; /* je 0x6e795c */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x006e7945u); f_006e7859(c); /* call 0x6e7859 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_006e7959; /* jne 0x6e7959 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x006e7954u); f_006e78a2(c); /* call 0x6e78a2 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006e7959:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
L_006e795c:;
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx | (uint32_t)0xffffffffu))); /* or edx, 0xffffffff */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->edx = (uint32_t)(shl32(c, c->edx, (c->ecx & 0xff))); /* shl edx, cl */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->edx)))); } /* and dword ptr [eax], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if ((c->sf == c->of)) goto L_006e797c; /* jge 0x6e797c */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    c->edi = (uint32_t)((uint32_t)(c->edx + c->eax * 4)); /* lea edi, [edx + eax*4] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
L_006e797c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006e7984(CPU *c) { /* FUN_10007984 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
L_006e7992:;
    c->esi = (uint32_t)(R32((uint32_t)(c->eax))); /* mov esi, dword ptr [eax] */
    W32((uint32_t)(c->ecx + c->eax), (uint32_t)(c->esi)); /* mov dword ptr [ecx + eax], esi */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x4u)); /* add eax, 4 */
    c->edx = (uint32_t)(dec32(c, c->edx)); /* dec edx */
    if (!c->zf) goto L_006e7992; /* jne 0x6e7992 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_006e799f(CPU *c) { /* FUN_1000799f */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edi, dword ptr [esp + 8] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); /* stosd dword ptr es:[edi], eax */
    W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); /* stosd dword ptr es:[edi], eax */
    W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); /* stosd dword ptr es:[edi], eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_006e79ab(CPU *c) { /* FUN_100079ab */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
L_006e79b1:;
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0x0u); /* cmp dword ptr [eax], 0 */
    if (!c->zf) goto L_006e79c3; /* jne 0x6e79c3 */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x4u)); /* add eax, 4 */
    (void)sub32(c, c->ecx, (uint32_t)0x3u); /* cmp ecx, 3 */
    if ((c->sf != c->of)) goto L_006e79b1; /* jl 0x6e79b1 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
L_006e79c3:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_006e79c6(CPU *c) { /* FUN_100079c6 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x20u; PUSH32(c, v_); } /* push 0x20 */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi | (uint32_t)0xffffffffu))); /* or esi, 0xffffffff */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x3u)); /* mov dword ptr [ebp - 4], 3 */
    { int32_t d_ = (int32_t)c->ecx; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x006e79e5u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv ecx */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)c->ecx; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x006e79eeu, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp + 0xc], 0 */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->esi = (uint32_t)(shl32(c, c->esi, (c->ecx & 0xff))); /* shl esi, cl */
    c->ebx = (uint32_t)(sub32(c, c->ebx, c->edx)); /* sub ebx, edx */
    c->esi = (uint32_t)((uint32_t)~c->esi); /* not esi */
L_006e79fc:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & c->esi))); /* and ecx, esi */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->eax = (uint32_t)(shr32(c, c->eax, (c->ecx & 0xff))); /* shr eax, cl */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | R32((uint32_t)(c->ebp + 0xcu))))); /* or eax, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    c->eax = (uint32_t)(shl32(c, c->eax, (c->ecx & 0xff))); /* shl eax, cl */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 4] */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0xc], eax */
    if (!c->zf) goto L_006e79fc; /* jne 0x6e79fc */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov edi, dword ptr [ebp - 0xc] */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esi = (uint32_t)(c->edi); /* mov esi, edi */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esi = (uint32_t)(shl32(c, c->esi, 2)); /* shl esi, 2 */
L_006e7a2e:;
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    if ((c->sf != c->of)) goto L_006e7a41; /* jl 0x6e7a41 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->eax = (uint32_t)(sub32(c, c->eax, c->esi)); /* sub eax, esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->edx))); /* mov eax, dword ptr [eax + edx] */
    W32((uint32_t)(c->ecx + c->edx), (uint32_t)(c->eax)); /* mov dword ptr [ecx + edx], eax */
    goto L_006e7a48; /* jmp 0x6e7a48 */
L_006e7a41:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ecx + eax], 0 */
L_006e7a48:;
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x4u)); /* sub ecx, 4 */
    if (!c->sf) goto L_006e7a2e; /* jns 0x6e7a2e */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006e7a53(CPU *c) { /* FUN_10007a53 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)((uint32_t)R16((uint32_t)(c->eax + 0xau))); /* movzx ecx, word ptr [eax + 0xa] */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x8000u))); /* and ecx, 0x8000 */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp + 8], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x6u))); /* mov ecx, dword ptr [eax + 6] */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 0xc], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x2u))); /* mov ecx, dword ptr [eax + 2] */
    c->eax = (uint32_t)((uint32_t)R16((uint32_t)(c->eax))); /* movzx eax, word ptr [eax] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edi, dword ptr [ebp + 0x10] */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x7fffu))); /* and ebx, 0x7fff */
    c->ebx = (uint32_t)(sub32(c, c->ebx, (uint32_t)0x3fffu)); /* sub ebx, 0x3fff */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
    c->eax = (uint32_t)(shl32(c, c->eax, 16)); /* shl eax, 0x10 */
    (void)sub32(c, c->ebx, (uint32_t)0xffffc001u); /* cmp ebx, 0xffffc001 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    if (!c->zf) goto L_006e7ac0; /* jne 0x6e7ac0 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e7aa5u); f_006e79ab(c); /* call 0x6e79ab */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_006e7b7f; /* jne 0x6e7b7f */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e7ab7u); f_006e799f(c); /* call 0x6e799f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006e7ab8:;
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
L_006e7aba:;
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_006e7b81; /* jmp 0x6e7b81 */
L_006e7ac0:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe8u)); /* lea eax, [ebp - 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e7acdu); f_006e7984(c); /* call 0x6e7984 */
    { uint32_t v_ = R32((uint32_t)(c->edi + 0x8u)); PUSH32(c, v_); } /* push dword ptr [edi + 8] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e7ad9u); f_006e78f8(c); /* call 0x6e78f8 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e7ae1; /* je 0x6e7ae1 */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
L_006e7ae1:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov eax, dword ptr [edi + 4] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->ecx = (uint32_t)(sub32(c, c->ecx, R32((uint32_t)(c->edi + 0x8u)))); /* sub ecx, dword ptr [edi + 8] */
    (void)sub32(c, c->ebx, c->ecx); /* cmp ebx, ecx */
    if ((c->sf == c->of)) goto L_006e7af9; /* jge 0x6e7af9 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e7af6u); f_006e799f(c); /* call 0x6e799f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_006e7b35; /* jmp 0x6e7b35 */
L_006e7af9:;
    (void)sub32(c, c->ebx, c->eax); /* cmp ebx, eax */
    if ((!c->zf && c->sf == c->of)) goto L_006e7b3c; /* jg 0x6e7b3c */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ebx)); /* sub eax, ebx */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe8u)); /* lea eax, [ebp - 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e7b0eu); f_006e7984(c); /* call 0x6e7984 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e7b18u); f_006e79c6(c); /* call 0x6e79c6 */
    { uint32_t v_ = R32((uint32_t)(c->edi + 0x8u)); PUSH32(c, v_); } /* push dword ptr [edi + 8] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e7b24u); f_006e78f8(c); /* call 0x6e78f8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0xcu))); /* mov eax, dword ptr [edi + 0xc] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e7b32u); f_006e79c6(c); /* call 0x6e79c6 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
L_006e7b35:;
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    goto L_006e7ab8; /* jmp 0x6e7ab8 */
L_006e7b3c:;
    (void)sub32(c, c->ebx, R32((uint32_t)(c->edi))); /* cmp ebx, dword ptr [edi] */
    if ((c->sf != c->of)) goto L_006e7b68; /* jl 0x6e7b68 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e7b49u); f_006e799f(c); /* call 0x6e799f */
    { uint32_t v_ = R32((uint32_t)(c->edi + 0xcu)); PUSH32(c, v_); } /* push dword ptr [edi + 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff7u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x80u)))); } /* or byte ptr [ebp - 9], 0x80 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e7b59u); f_006e79c6(c); /* call 0x6e79c6 */
    c->esi = (uint32_t)(R32((uint32_t)(c->edi + 0x14u))); /* mov esi, dword ptr [edi + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esi = (uint32_t)(add32(c, c->esi, R32((uint32_t)(c->edi)))); /* add esi, dword ptr [edi] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    goto L_006e7aba; /* jmp 0x6e7aba */
L_006e7b68:;
    { uint32_t v_ = R32((uint32_t)(c->edi + 0xcu)); PUSH32(c, v_); } /* push dword ptr [edi + 0xc] */
    c->esi = (uint32_t)(R32((uint32_t)(c->edi + 0x14u))); /* mov esi, dword ptr [edi + 0x14] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff7u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x7fu)))); } /* and byte ptr [ebp - 9], 0x7f */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->esi = (uint32_t)(add32(c, c->esi, c->ebx)); /* add esi, ebx */
    PUSH32(c, 0x006e7b7du); f_006e79c6(c); /* call 0x6e79c6 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006e7b7f:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_006e7b81:;
    { uint32_t v_ = 0x1fu; PUSH32(c, v_); } /* push 0x1f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(sub32(c, c->ecx, R32((uint32_t)(c->edi + 0xcu)))); /* sub ecx, dword ptr [edi + 0xc] */
    c->edi = (uint32_t)(R32((uint32_t)(c->edi + 0x10u))); /* mov edi, dword ptr [edi + 0x10] */
    c->esi = (uint32_t)(shl32(c, c->esi, (c->ecx & 0xff))); /* shl esi, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
    c->ecx = (uint32_t)(sbb32(c, c->ecx, c->ecx)); /* sbb ecx, ecx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x80000000u))); /* and ecx, 0x80000000 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi | c->ecx))); /* or esi, ecx */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi | R32((uint32_t)(c->ebp + 0xfffffff4u))))); /* or esi, dword ptr [ebp - 0xc] */
    (void)sub32(c, c->edi, (uint32_t)0x40u); /* cmp edi, 0x40 */
    if (!c->zf) goto L_006e7bb0; /* jne 0x6e7bb0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov edx, dword ptr [ebp - 8] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [ecx + 4], esi */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    goto L_006e7bba; /* jmp 0x6e7bba */
L_006e7bb0:;
    (void)sub32(c, c->edi, (uint32_t)0x20u); /* cmp edi, 0x20 */
    if (!c->zf) goto L_006e7bba; /* jne 0x6e7bba */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->esi)); /* mov dword ptr [ecx], esi */
L_006e7bba:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006e7bbf(CPU *c) { /* FUN_10007bbf */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x6ee530u; PUSH32(c, v_); } /* push 0x1000e530 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    PUSH32(c, 0x006e7bd1u); f_006e7a53(c); /* call 0x6e7a53 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_006e7bd5(CPU *c) { /* FUN_10007bd5 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x6ee548u; PUSH32(c, v_); } /* push 0x1000e548 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    PUSH32(c, 0x006e7be7u); f_006e7a53(c); /* call 0x6e7a53 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_006e7beb(CPU *c) { /* FUN_10007beb */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xcu)); /* lea eax, [ebp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e7c07u); f_006eb237(c); /* call 0x6eb237 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e7c13u); f_006e7bbf(c); /* call 0x6e7bbf */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x24u)); /* add esp, 0x24 */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006e7c18(CPU *c) { /* FUN_10007c18 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xcu)); /* lea eax, [ebp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e7c34u); f_006eb237(c); /* call 0x6eb237 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e7c40u); f_006e7bd5(c); /* call 0x6e7bd5 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x24u)); /* add esp, 0x24 */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006e7c50(CPU *c) { /* FUN_10007c50 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edi, dword ptr [esp + 8] */
    { f_006e7cc1(c); return; } /* jmp 0x6e7cc1 */
}

void f_006e7c60(CPU *c) { /* FUN_10007c60 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u)); /* test ecx, 3 */
    if (c->zf) goto L_006e7c7c; /* je 0x6e7c7c */
L_006e7c6d:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov al, byte ptr [ecx] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_006e7caf; /* je 0x6e7caf */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u)); /* test ecx, 3 */
    if (!c->zf) goto L_006e7c6d; /* jne 0x6e7c6d */
L_006e7c7c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)((uint32_t)0x7efefeffu); /* mov edx, 0x7efefeff */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ (uint32_t)0xffffffffu))); /* xor eax, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ c->edx))); /* xor eax, edx */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u)); /* test eax, 0x81010100 */
    if (c->zf) goto L_006e7c7c; /* je 0x6e7c7c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0xfffffffcu))); /* mov eax, dword ptr [ecx - 4] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_006e7cbe; /* je 0x6e7cbe */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_006e7cb9; /* je 0x6e7cb9 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0xff0000u)); /* test eax, 0xff0000 */
    if (c->zf) goto L_006e7cb4; /* je 0x6e7cb4 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0xff000000u)); /* test eax, 0xff000000 */
    if (c->zf) goto L_006e7caf; /* je 0x6e7caf */
    goto L_006e7c7c; /* jmp 0x6e7c7c */
L_006e7caf:;
    c->edi = (uint32_t)((uint32_t)(c->ecx + 0xffffffffu)); /* lea edi, [ecx - 1] */
    goto L_006e7cc1; /* jmp 0x6e7cc1 */
L_006e7cb4:;
    c->edi = (uint32_t)((uint32_t)(c->ecx + 0xfffffffeu)); /* lea edi, [ecx - 2] */
    goto L_006e7cc1; /* jmp 0x6e7cc1 */
L_006e7cb9:;
    c->edi = (uint32_t)((uint32_t)(c->ecx + 0xfffffffdu)); /* lea edi, [ecx - 3] */
    goto L_006e7cc1; /* jmp 0x6e7cc1 */
L_006e7cbe:;
    c->edi = (uint32_t)((uint32_t)(c->ecx + 0xfffffffcu)); /* lea edi, [ecx - 4] */
L_006e7cc1:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u)); /* test ecx, 3 */
    if (c->zf) goto L_006e7ce6; /* je 0x6e7ce6 */
L_006e7ccd:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov dl, byte ptr [ecx] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_006e7d38; /* je 0x6e7d38 */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [edi], dl */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u)); /* test ecx, 3 */
    if (!c->zf) goto L_006e7ccd; /* jne 0x6e7ccd */
    goto L_006e7ce6; /* jmp 0x6e7ce6 */
L_006e7ce1:;
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
L_006e7ce6:;
    c->edx = (uint32_t)((uint32_t)0x7efefeffu); /* mov edx, 0x7efefeff */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ (uint32_t)0xffffffffu))); /* xor eax, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ c->edx))); /* xor eax, edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u)); /* test eax, 0x81010100 */
    if (c->zf) goto L_006e7ce1; /* je 0x6e7ce1 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_006e7d38; /* je 0x6e7d38 */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->edx >> 8)) & ((uint8_t)(c->edx >> 8)))); /* test dh, dh */
    if (c->zf) goto L_006e7d2f; /* je 0x6e7d2f */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0xff0000u)); /* test edx, 0xff0000 */
    if (c->zf) goto L_006e7d22; /* je 0x6e7d22 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0xff000000u)); /* test edx, 0xff000000 */
    if (c->zf) goto L_006e7d1a; /* je 0x6e7d1a */
    goto L_006e7ce1; /* jmp 0x6e7ce1 */
L_006e7d1a:;
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_006e7d22:;
    W16((uint32_t)(c->edi), (uint16_t)(((uint16_t)c->edx))); /* mov word ptr [edi], dx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [edi + 2], 0 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_006e7d2f:;
    W16((uint32_t)(c->edi), (uint16_t)(((uint16_t)c->edx))); /* mov word ptr [edi], dx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_006e7d38:;
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [edi], dl */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_006e7cc1(CPU *c) { /* PTR_006e7cc1 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u)); /* test ecx, 3 */
    if (c->zf) goto L_006e7ce6; /* je 0x6e7ce6 */
L_006e7ccd:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov dl, byte ptr [ecx] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_006e7d38; /* je 0x6e7d38 */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [edi], dl */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u)); /* test ecx, 3 */
    if (!c->zf) goto L_006e7ccd; /* jne 0x6e7ccd */
    goto L_006e7ce6; /* jmp 0x6e7ce6 */
L_006e7ce1:;
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
L_006e7ce6:;
    c->edx = (uint32_t)((uint32_t)0x7efefeffu); /* mov edx, 0x7efefeff */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ (uint32_t)0xffffffffu))); /* xor eax, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ c->edx))); /* xor eax, edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u)); /* test eax, 0x81010100 */
    if (c->zf) goto L_006e7ce1; /* je 0x6e7ce1 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_006e7d38; /* je 0x6e7d38 */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->edx >> 8)) & ((uint8_t)(c->edx >> 8)))); /* test dh, dh */
    if (c->zf) goto L_006e7d2f; /* je 0x6e7d2f */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0xff0000u)); /* test edx, 0xff0000 */
    if (c->zf) goto L_006e7d22; /* je 0x6e7d22 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0xff000000u)); /* test edx, 0xff000000 */
    if (c->zf) goto L_006e7d1a; /* je 0x6e7d1a */
    goto L_006e7ce1; /* jmp 0x6e7ce1 */
L_006e7d1a:;
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_006e7d22:;
    W16((uint32_t)(c->edi), (uint16_t)(((uint16_t)c->edx))); /* mov word ptr [edi], dx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [edi + 2], 0 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_006e7d2f:;
    W16((uint32_t)(c->edi), (uint16_t)(((uint16_t)c->edx))); /* mov word ptr [edi], dx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_006e7d38:;
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [edi], dl */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_006e7d40(CPU *c) { /* FUN_10007d40 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edx, dword ptr [ebp + 0x10] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ebx, dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0xcu))); /* mov ecx, dword ptr [edx + 0xc] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x1u)); /* lea edi, [esi + 1] */
    W8((uint32_t)(c->esi), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [esi], 0x30 */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    if ((c->zf || c->sf != c->of)) goto L_006e7d7d; /* jle 0x6e7d7d */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 8], ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
L_006e7d63:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov dl, byte ptr [ecx] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_006e7d6f; /* je 0x6e7d6f */
    c->edx = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->edx)); /* movsx edx, dl */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    goto L_006e7d72; /* jmp 0x6e7d72 */
L_006e7d6f:;
    { uint32_t v_ = 0x30u; PUSH32(c, v_); } /* push 0x30 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
L_006e7d72:;
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [eax], dl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 8] */
    if (!c->zf) goto L_006e7d63; /* jne 0x6e7d63 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edx, dword ptr [ebp + 0x10] */
L_006e7d7d:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax], 0 */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if ((c->sf != c->of)) goto L_006e7d96; /* jl 0x6e7d96 */
    (void)sub8(c, R8((uint32_t)(c->ecx)), (uint8_t)0x35u); /* cmp byte ptr [ecx], 0x35 */
    if ((c->sf != c->of)) goto L_006e7d96; /* jl 0x6e7d96 */
L_006e7d89:;
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x39u); /* cmp byte ptr [eax], 0x39 */
    if (!c->zf) goto L_006e7d94; /* jne 0x6e7d94 */
    W8((uint32_t)(c->eax), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [eax], 0x30 */
    goto L_006e7d89; /* jmp 0x6e7d89 */
L_006e7d94:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(inc8(c, R8(a_)))); } /* inc byte ptr [eax] */
L_006e7d96:;
    (void)sub8(c, R8((uint32_t)(c->esi)), (uint8_t)0x31u); /* cmp byte ptr [esi], 0x31 */
    if (!c->zf) goto L_006e7da0; /* jne 0x6e7da0 */
    { uint32_t a_ = (uint32_t)(c->edx + 0x4u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [edx + 4] */
    goto L_006e7db2; /* jmp 0x6e7db2 */
L_006e7da0:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006e7da6u); f_006e8280(c); /* call 0x6e8280 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006e7dafu); f_006e7f40(c); /* call 0x6e7f40 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_006e7db2:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_006e7db7(CPU *c) { /* FUN_10007db7 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x8u)); /* lea eax, [ebp + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e7dccu); f_006e7e1b(c); /* call 0x6e7e1b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esi = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea esi, [ebp - 0xc] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = 0x777ac8u; PUSH32(c, v_); } /* push 0x10097ac8 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x11u; PUSH32(c, v_); } /* push 0x11 */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    W16(c->edi, R16(c->esi)); c->esi += (c->df ? -2 : 2); c->edi += (c->df ? -2 : 2); /* movsw word ptr es:[edi], word ptr [esi] */
    PUSH32(c, 0x006e7de8u); f_006eb708(c); /* call 0x6eb708 */
    W32((uint32_t)(0x777af0u), (uint32_t)(c->eax)); /* mov dword ptr [0x10097af0], eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(0x777acau))); /* movsx eax, byte ptr [0x10097aca] */
    W32((uint32_t)(0x777ae8u), (uint32_t)(c->eax)); /* mov dword ptr [0x10097ae8], eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int16_t)R16((uint32_t)(0x777ac8u))); /* movsx eax, word ptr [0x10097ac8] */
    W32((uint32_t)(0x777aecu), (uint32_t)(c->eax)); /* mov dword ptr [0x10097aec], eax */
    W32((uint32_t)(0x777af4u), (uint32_t)((uint32_t)0x777accu)); /* mov dword ptr [0x10097af4], 0x10097acc */
    c->eax = (uint32_t)((uint32_t)0x777ae8u); /* mov eax, 0x10097ae8 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006e7e1b(CPU *c) { /* FUN_10007e1b */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->edx + 0x6u))); /* mov ax, word ptr [edx + 6] */
    c->edi = (uint32_t)((uint32_t)0x7ffu); /* mov edi, 0x7ff */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x8000u))); /* and eax, 0x8000 */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 4)); /* shr ecx, 4 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & c->edi))); /* and ecx, edi */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0xc], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov eax, dword ptr [edx + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edx))); /* mov edx, dword ptr [edx] */
    c->ebx = (uint32_t)((uint32_t)((uint16_t)c->ecx)); /* movzx ebx, cx */
    c->esi = (uint32_t)((uint32_t)0x80000000u); /* mov esi, 0x80000000 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xfffffu))); /* and eax, 0xfffff */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 4], esi */
    if (c->zf) goto L_006e7e69; /* je 0x6e7e69 */
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    if (c->zf) goto L_006e7e62; /* je 0x6e7e62 */
    c->edi = (uint32_t)((uint32_t)(c->ecx + 0x3c00u)); /* lea edi, [ecx + 0x3c00] */
    goto L_006e7e8a; /* jmp 0x6e7e8a */
L_006e7e62:;
    c->edi = (uint32_t)((uint32_t)0x7fffu); /* mov edi, 0x7fff */
    goto L_006e7e8a; /* jmp 0x6e7e8a */
L_006e7e69:;
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (!c->zf) goto L_006e7e81; /* jne 0x6e7e81 */
    (void)sub32(c, c->edx, c->ebx); /* cmp edx, ebx */
    if (!c->zf) goto L_006e7e81; /* jne 0x6e7e81 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 4], ebx */
    W32((uint32_t)(c->eax), (uint32_t)(c->ebx)); /* mov dword ptr [eax], ebx */
    W16((uint32_t)(c->eax + 0x8u), (uint16_t)(((uint16_t)c->ebx))); /* mov word ptr [eax + 8], bx */
    goto L_006e7ecc; /* jmp 0x6e7ecc */
L_006e7e81:;
    c->edi = (uint32_t)((uint32_t)(c->ecx + 0x3c01u)); /* lea edi, [ecx + 0x3c01] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 4], ebx */
L_006e7e8a:;
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 21)); /* shr ecx, 0x15 */
    c->eax = (uint32_t)(shl32(c, c->eax, 11)); /* shl eax, 0xb */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->eax))); /* or ecx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | R32((uint32_t)(c->ebp + 0xfffffffcu))))); /* or ecx, dword ptr [ebp - 4] */
    c->edx = (uint32_t)(shl32(c, c->edx, 11)); /* shl edx, 0xb */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 4], ecx */
    W32((uint32_t)(c->eax), (uint32_t)(c->edx)); /* mov dword ptr [eax], edx */
L_006e7ea2:;
    (void)logic32(c, (uint32_t)(c->esi & c->ecx)); /* test esi, ecx */
    if (!c->zf) goto L_006e7ec3; /* jne 0x6e7ec3 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->ecx)); /* add ecx, ecx */
    c->ebx = (uint32_t)(c->edx); /* mov ebx, edx */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 31)); /* shr ebx, 0x1f */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | c->ecx))); /* or ebx, ecx */
    c->ecx = (uint32_t)((uint32_t)(c->edx + c->edx)); /* lea ecx, [edx + edx] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 4], ebx */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0xffffu)); /* add edi, 0xffff */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    goto L_006e7ea2; /* jmp 0x6e7ea2 */
L_006e7ec3:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->edi))); /* or ecx, edi */
    W16((uint32_t)(c->eax + 0x8u), (uint16_t)(((uint16_t)c->ecx))); /* mov word ptr [eax + 8], cx */
L_006e7ecc:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006e7ee0(CPU *c) { /* _memset */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_006e7f33; /* je 0x6e7f33 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x8u))); /* mov al, byte ptr [esp + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    (void)sub32(c, c->edx, (uint32_t)0x4u); /* cmp edx, 4 */
    if (c->cf) goto L_006e7f27; /* jb 0x6e7f27 */
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u))); /* and ecx, 3 */
    if (c->zf) goto L_006e7f09; /* je 0x6e7f09 */
    c->edx = (uint32_t)(sub32(c, c->edx, c->ecx)); /* sub edx, ecx */
L_006e7f03:;
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (!c->zf) goto L_006e7f03; /* jne 0x6e7f03 */
L_006e7f09:;
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(shl32(c, c->eax, 16)); /* shl eax, 0x10 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u))); /* and edx, 3 */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (c->zf) goto L_006e7f27; /* je 0x6e7f27 */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_006e7f2d; /* je 0x6e7f2d */
L_006e7f27:;
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->edx = (uint32_t)(dec32(c, c->edx)); /* dec edx */
    if (!c->zf) goto L_006e7f27; /* jne 0x6e7f27 */
L_006e7f2d:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_006e7f33:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->esp += 4; return; /* ret  */
}

void f_006e7f40(CPU *c) { /* FUN_10007f40 */
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
    if ((c->cf || c->zf)) goto L_006e7f60; /* jbe 0x6e7f60 */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_006e80d8; /* jb 0x6e80d8 */
L_006e7f60:;
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x3u)); /* test edi, 3 */
    if (!c->zf) goto L_006e7f7c; /* jne 0x6e7f7c */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u))); /* and edx, 3 */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) goto L_006e7f9c; /* jb 0x6e7f9c */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x6e8088u)); switch (t_) { case 0x006e8098u: goto L_006e8098; case 0x006e80a0u: goto L_006e80a0; case 0x006e80acu: goto L_006e80ac; case 0x006e80c0u: goto L_006e80c0; default: jump_indirect(c, t_, 0x006e7f75u); return; } } /* jmp dword ptr [edx*4 + 0x10008088] */
L_006e7f7c:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edx = (uint32_t)((uint32_t)0x3u); /* mov edx, 3 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x4u)); /* sub ecx, 4 */
    if (c->cf) goto L_006e7f94; /* jb 0x6e7f94 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x3u))); /* and eax, 3 */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->eax * 4 + 0x6e7fa0u)); switch (t_) {  default: jump_indirect(c, t_, 0x006e7f8du); return; } } /* jmp dword ptr [eax*4 + 0x10007fa0] */
L_006e7f94:;
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0x6e8098u)); switch (t_) {  default: jump_indirect(c, t_, 0x006e7f94u); return; } } /* jmp dword ptr [ecx*4 + 0x10008098] */
L_006e7f9c:;
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0x6e801cu)); switch (t_) { case 0x006e803cu: goto L_006e803c; case 0x006e8044u: goto L_006e8044; case 0x006e804cu: goto L_006e804c; case 0x006e8054u: goto L_006e8054; case 0x006e805cu: goto L_006e805c; case 0x006e8064u: goto L_006e8064; case 0x006e806cu: goto L_006e806c; case 0x006e807fu: goto L_006e807f; default: jump_indirect(c, t_, 0x006e7f9cu); return; } } /* jmp dword ptr [ecx*4 + 0x1000801c] */
L_006e803c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe4u))); /* mov eax, dword ptr [esi + ecx*4 - 0x1c] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x1c], eax */
L_006e8044:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe8u))); /* mov eax, dword ptr [esi + ecx*4 - 0x18] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x18], eax */
L_006e804c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffecu))); /* mov eax, dword ptr [esi + ecx*4 - 0x14] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffecu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x14], eax */
L_006e8054:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff0u))); /* mov eax, dword ptr [esi + ecx*4 - 0x10] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x10], eax */
L_006e805c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff4u))); /* mov eax, dword ptr [esi + ecx*4 - 0xc] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0xc], eax */
L_006e8064:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff8u))); /* mov eax, dword ptr [esi + ecx*4 - 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 8], eax */
L_006e806c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
L_006e807f:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x6e8088u)); switch (t_) { case 0x006e8098u: goto L_006e8098; case 0x006e80a0u: goto L_006e80a0; case 0x006e80acu: goto L_006e80ac; case 0x006e80c0u: goto L_006e80c0; default: jump_indirect(c, t_, 0x006e807fu); return; } } /* jmp dword ptr [edx*4 + 0x10008088] */
L_006e8098:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e80a0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e80ac:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e80c0:;
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
L_006e80d8:;
    c->esi = (uint32_t)((uint32_t)(c->ecx + c->esi + 0xfffffffcu)); /* lea esi, [ecx + esi - 4] */
    c->edi = (uint32_t)((uint32_t)(c->ecx + c->edi + 0xfffffffcu)); /* lea edi, [ecx + edi - 4] */
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x3u)); /* test edi, 3 */
    if (!c->zf) goto L_006e810c; /* jne 0x6e810c */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u))); /* and edx, 3 */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) goto L_006e8100; /* jb 0x6e8100 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x6e8220u)); switch (t_) { case 0x006e8230u: goto L_006e8230; case 0x006e8238u: goto L_006e8238; case 0x006e8248u: goto L_006e8248; case 0x006e825cu: goto L_006e825c; default: jump_indirect(c, t_, 0x006e80f7u); return; } } /* jmp dword ptr [edx*4 + 0x10008220] */
L_006e8100:;
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0x6e81d0u)); switch (t_) { case 0x006e8217u: goto L_006e8217; default: jump_indirect(c, t_, 0x006e8102u); return; } } /* jmp dword ptr [ecx*4 + 0x100081d0] */
L_006e810c:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edx = (uint32_t)((uint32_t)0x3u); /* mov edx, 3 */
    (void)sub32(c, c->ecx, (uint32_t)0x4u); /* cmp ecx, 4 */
    if (c->cf) goto L_006e8124; /* jb 0x6e8124 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x3u))); /* and eax, 3 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->eax * 4 + 0x6e8128u)); switch (t_) {  default: jump_indirect(c, t_, 0x006e811du); return; } } /* jmp dword ptr [eax*4 + 0x10008128] */
L_006e8124:;
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0x6e8220u)); switch (t_) { case 0x006e8230u: goto L_006e8230; case 0x006e8238u: goto L_006e8238; case 0x006e8248u: goto L_006e8248; case 0x006e825cu: goto L_006e825c; default: jump_indirect(c, t_, 0x006e8124u); return; } } /* jmp dword ptr [ecx*4 + 0x10008220] */
L_006e8217:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x6e8220u)); switch (t_) { case 0x006e8230u: goto L_006e8230; case 0x006e8238u: goto L_006e8238; case 0x006e8248u: goto L_006e8248; case 0x006e825cu: goto L_006e825c; default: jump_indirect(c, t_, 0x006e8217u); return; } } /* jmp dword ptr [edx*4 + 0x10008220] */
L_006e8230:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e8238:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e8248:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e825c:;
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

void f_006e7f9c(CPU *c) { /* PTR_006e7f9c */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0x6e801cu)); switch (t_) { case 0x006e803cu: goto L_006e803c; case 0x006e8044u: goto L_006e8044; case 0x006e804cu: goto L_006e804c; case 0x006e8054u: goto L_006e8054; case 0x006e805cu: goto L_006e805c; case 0x006e8064u: goto L_006e8064; case 0x006e806cu: goto L_006e806c; case 0x006e807fu: goto L_006e807f; default: jump_indirect(c, t_, 0x006e7f9cu); return; } } /* jmp dword ptr [ecx*4 + 0x1000801c] */
L_006e803c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe4u))); /* mov eax, dword ptr [esi + ecx*4 - 0x1c] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x1c], eax */
L_006e8044:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe8u))); /* mov eax, dword ptr [esi + ecx*4 - 0x18] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x18], eax */
L_006e804c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffecu))); /* mov eax, dword ptr [esi + ecx*4 - 0x14] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffecu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x14], eax */
L_006e8054:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff0u))); /* mov eax, dword ptr [esi + ecx*4 - 0x10] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x10], eax */
L_006e805c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff4u))); /* mov eax, dword ptr [esi + ecx*4 - 0xc] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0xc], eax */
L_006e8064:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff8u))); /* mov eax, dword ptr [esi + ecx*4 - 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 8], eax */
L_006e806c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
L_006e807f:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x6e8088u)); switch (t_) { case 0x006e8098u: goto L_006e8098; case 0x006e80a0u: goto L_006e80a0; case 0x006e80acu: goto L_006e80ac; case 0x006e80c0u: goto L_006e80c0; default: jump_indirect(c, t_, 0x006e807fu); return; } } /* jmp dword ptr [edx*4 + 0x10008088] */
L_006e8098:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e80a0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e80ac:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e80c0:;
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

void f_006e7fb0(CPU *c) { /* PTR_006e7fb0 */
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
    if (c->cf) { f_006e7f9c(c); return; } /* jb 0x6e7f9c */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x6e8088u)); switch (t_) { case 0x006e8098u: goto L_006e8098; case 0x006e80a0u: goto L_006e80a0; case 0x006e80acu: goto L_006e80ac; case 0x006e80c0u: goto L_006e80c0; default: jump_indirect(c, t_, 0x006e7fd2u); return; } } /* jmp dword ptr [edx*4 + 0x10008088] */
L_006e8098:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e80a0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e80ac:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e80c0:;
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

void f_006e7fd0(CPU *c) { /* PTR_006e7fd0 */
    PREEMPT_POLL(c);
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x6e8088u)); switch (t_) { case 0x006e8098u: goto L_006e8098; case 0x006e80a0u: goto L_006e80a0; case 0x006e80acu: goto L_006e80ac; case 0x006e80c0u: goto L_006e80c0; default: jump_indirect(c, t_, 0x006e7fd2u); return; } } /* jmp dword ptr [edx*4 + 0x10008088] */
L_006e8098:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e80a0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e80ac:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e80c0:;
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

void f_006e7fdc(CPU *c) { /* PTR_006e7fdc */
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
    if (c->cf) { f_006e7f9c(c); return; } /* jb 0x6e7f9c */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x6e8088u)); switch (t_) { case 0x006e8098u: goto L_006e8098; case 0x006e80a0u: goto L_006e80a0; case 0x006e80acu: goto L_006e80ac; case 0x006e80c0u: goto L_006e80c0; default: jump_indirect(c, t_, 0x006e7ff8u); return; } } /* jmp dword ptr [edx*4 + 0x10008088] */
L_006e8098:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e80a0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e80ac:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e80c0:;
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

void f_006e8000(CPU *c) { /* PTR_006e8000 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & c->ecx))); /* and edx, ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) { f_006e7f9c(c); return; } /* jb 0x6e7f9c */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x6e8088u)); switch (t_) { case 0x006e8098u: goto L_006e8098; case 0x006e80a0u: goto L_006e80a0; case 0x006e80acu: goto L_006e80ac; case 0x006e80c0u: goto L_006e80c0; default: jump_indirect(c, t_, 0x006e8012u); return; } } /* jmp dword ptr [edx*4 + 0x10008088] */
L_006e8098:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e80a0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e80ac:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e80c0:;
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

void f_006e803c(CPU *c) { /* PTR_006e803c */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x6e8088u)); switch (t_) { case 0x006e8098u: goto L_006e8098; case 0x006e80a0u: goto L_006e80a0; case 0x006e80acu: goto L_006e80ac; case 0x006e80c0u: goto L_006e80c0; default: jump_indirect(c, t_, 0x006e807fu); return; } } /* jmp dword ptr [edx*4 + 0x10008088] */
L_006e8098:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e80a0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e80ac:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e80c0:;
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

void f_006e8044(CPU *c) { /* PTR_006e8044 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x6e8088u)); switch (t_) { case 0x006e8098u: goto L_006e8098; case 0x006e80a0u: goto L_006e80a0; case 0x006e80acu: goto L_006e80ac; case 0x006e80c0u: goto L_006e80c0; default: jump_indirect(c, t_, 0x006e807fu); return; } } /* jmp dword ptr [edx*4 + 0x10008088] */
L_006e8098:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e80a0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e80ac:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e80c0:;
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

void f_006e804c(CPU *c) { /* PTR_006e804c */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x6e8088u)); switch (t_) { case 0x006e8098u: goto L_006e8098; case 0x006e80a0u: goto L_006e80a0; case 0x006e80acu: goto L_006e80ac; case 0x006e80c0u: goto L_006e80c0; default: jump_indirect(c, t_, 0x006e807fu); return; } } /* jmp dword ptr [edx*4 + 0x10008088] */
L_006e8098:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e80a0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e80ac:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e80c0:;
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

void f_006e8054(CPU *c) { /* PTR_006e8054 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x6e8088u)); switch (t_) { case 0x006e8098u: goto L_006e8098; case 0x006e80a0u: goto L_006e80a0; case 0x006e80acu: goto L_006e80ac; case 0x006e80c0u: goto L_006e80c0; default: jump_indirect(c, t_, 0x006e807fu); return; } } /* jmp dword ptr [edx*4 + 0x10008088] */
L_006e8098:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e80a0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e80ac:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e80c0:;
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

void f_006e805c(CPU *c) { /* PTR_006e805c */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x6e8088u)); switch (t_) { case 0x006e8098u: goto L_006e8098; case 0x006e80a0u: goto L_006e80a0; case 0x006e80acu: goto L_006e80ac; case 0x006e80c0u: goto L_006e80c0; default: jump_indirect(c, t_, 0x006e807fu); return; } } /* jmp dword ptr [edx*4 + 0x10008088] */
L_006e8098:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e80a0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e80ac:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e80c0:;
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

void f_006e8064(CPU *c) { /* PTR_006e8064 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff8u))); /* mov eax, dword ptr [esi + ecx*4 - 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x6e8088u)); switch (t_) { case 0x006e8098u: goto L_006e8098; case 0x006e80a0u: goto L_006e80a0; case 0x006e80acu: goto L_006e80ac; case 0x006e80c0u: goto L_006e80c0; default: jump_indirect(c, t_, 0x006e807fu); return; } } /* jmp dword ptr [edx*4 + 0x10008088] */
L_006e8098:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e80a0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e80ac:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e80c0:;
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

void f_006e806c(CPU *c) { /* PTR_006e806c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x6e8088u)); switch (t_) { case 0x006e8098u: goto L_006e8098; case 0x006e80a0u: goto L_006e80a0; case 0x006e80acu: goto L_006e80ac; case 0x006e80c0u: goto L_006e80c0; default: jump_indirect(c, t_, 0x006e807fu); return; } } /* jmp dword ptr [edx*4 + 0x10008088] */
L_006e8098:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e80a0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e80ac:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e80c0:;
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

void f_006e807f(CPU *c) { /* PTR_006e807f */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x6e8088u)); switch (t_) { case 0x006e8098u: goto L_006e8098; case 0x006e80a0u: goto L_006e80a0; case 0x006e80acu: goto L_006e80ac; case 0x006e80c0u: goto L_006e80c0; default: jump_indirect(c, t_, 0x006e807fu); return; } } /* jmp dword ptr [edx*4 + 0x10008088] */
L_006e8098:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e80a0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e80ac:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e80c0:;
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

void f_006e8098(CPU *c) { /* PTR_006e8098 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006e80a0(CPU *c) { /* PTR_006e80a0 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006e80ac(CPU *c) { /* PTR_006e80ac */
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

void f_006e80c0(CPU *c) { /* PTR_006e80c0 */
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

void f_006e8100(CPU *c) { /* PTR_006e8100 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0x6e81d0u)); switch (t_) { case 0x006e8217u: goto L_006e8217; default: jump_indirect(c, t_, 0x006e8102u); return; } } /* jmp dword ptr [ecx*4 + 0x100081d0] */
L_006e8217:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x6e8220u)); switch (t_) { case 0x006e8230u: goto L_006e8230; case 0x006e8238u: goto L_006e8238; case 0x006e8248u: goto L_006e8248; case 0x006e825cu: goto L_006e825c; default: jump_indirect(c, t_, 0x006e8217u); return; } } /* jmp dword ptr [edx*4 + 0x10008220] */
L_006e8230:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e8238:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e8248:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e825c:;
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

void f_006e8138(CPU *c) { /* PTR_006e8138 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & c->ecx))); /* and edx, ecx */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) { f_006e8100(c); return; } /* jb 0x6e8100 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x6e8220u)); switch (t_) { case 0x006e8230u: goto L_006e8230; case 0x006e8238u: goto L_006e8238; case 0x006e8248u: goto L_006e8248; case 0x006e825cu: goto L_006e825c; default: jump_indirect(c, t_, 0x006e814eu); return; } } /* jmp dword ptr [edx*4 + 0x10008220] */
L_006e8230:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e8238:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e8248:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e825c:;
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

void f_006e8158(CPU *c) { /* PTR_006e8158 */
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
    if (c->cf) { f_006e8100(c); return; } /* jb 0x6e8100 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x6e8220u)); switch (t_) { case 0x006e8230u: goto L_006e8230; case 0x006e8238u: goto L_006e8238; case 0x006e8248u: goto L_006e8248; case 0x006e825cu: goto L_006e825c; default: jump_indirect(c, t_, 0x006e8178u); return; } } /* jmp dword ptr [edx*4 + 0x10008220] */
L_006e8230:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e8238:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e8248:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e825c:;
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

void f_006e8180(CPU *c) { /* PTR_006e8180 */
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
    if (c->cf) { f_006e8100(c); return; } /* jb 0x6e8100 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x6e8220u)); switch (t_) { case 0x006e8230u: goto L_006e8230; case 0x006e8238u: goto L_006e8238; case 0x006e8248u: goto L_006e8248; case 0x006e825cu: goto L_006e825c; default: jump_indirect(c, t_, 0x006e81aau); return; } } /* jmp dword ptr [edx*4 + 0x10008220] */
L_006e8230:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e8238:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e8248:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e825c:;
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

void f_006e81d4(CPU *c) { /* PTR_006e81d4 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x6e8220u)); switch (t_) { case 0x006e8230u: goto L_006e8230; case 0x006e8238u: goto L_006e8238; case 0x006e8248u: goto L_006e8248; case 0x006e825cu: goto L_006e825c; default: jump_indirect(c, t_, 0x006e8217u); return; } } /* jmp dword ptr [edx*4 + 0x10008220] */
L_006e8230:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e8238:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e8248:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e825c:;
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

void f_006e81dc(CPU *c) { /* PTR_006e81dc */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x6e8220u)); switch (t_) { case 0x006e8230u: goto L_006e8230; case 0x006e8238u: goto L_006e8238; case 0x006e8248u: goto L_006e8248; case 0x006e825cu: goto L_006e825c; default: jump_indirect(c, t_, 0x006e8217u); return; } } /* jmp dword ptr [edx*4 + 0x10008220] */
L_006e8230:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e8238:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e8248:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e825c:;
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

void f_006e81e4(CPU *c) { /* PTR_006e81e4 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x6e8220u)); switch (t_) { case 0x006e8230u: goto L_006e8230; case 0x006e8238u: goto L_006e8238; case 0x006e8248u: goto L_006e8248; case 0x006e825cu: goto L_006e825c; default: jump_indirect(c, t_, 0x006e8217u); return; } } /* jmp dword ptr [edx*4 + 0x10008220] */
L_006e8230:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e8238:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e8248:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e825c:;
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

void f_006e81ec(CPU *c) { /* PTR_006e81ec */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x6e8220u)); switch (t_) { case 0x006e8230u: goto L_006e8230; case 0x006e8238u: goto L_006e8238; case 0x006e8248u: goto L_006e8248; case 0x006e825cu: goto L_006e825c; default: jump_indirect(c, t_, 0x006e8217u); return; } } /* jmp dword ptr [edx*4 + 0x10008220] */
L_006e8230:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e8238:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e8248:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e825c:;
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

void f_006e81f4(CPU *c) { /* PTR_006e81f4 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x6e8220u)); switch (t_) { case 0x006e8230u: goto L_006e8230; case 0x006e8238u: goto L_006e8238; case 0x006e8248u: goto L_006e8248; case 0x006e825cu: goto L_006e825c; default: jump_indirect(c, t_, 0x006e8217u); return; } } /* jmp dword ptr [edx*4 + 0x10008220] */
L_006e8230:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e8238:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e8248:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e825c:;
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

void f_006e81fc(CPU *c) { /* PTR_006e81fc */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x8u))); /* mov eax, dword ptr [esi + ecx*4 + 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x4u))); /* mov eax, dword ptr [esi + ecx*4 + 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x6e8220u)); switch (t_) { case 0x006e8230u: goto L_006e8230; case 0x006e8238u: goto L_006e8238; case 0x006e8248u: goto L_006e8248; case 0x006e825cu: goto L_006e825c; default: jump_indirect(c, t_, 0x006e8217u); return; } } /* jmp dword ptr [edx*4 + 0x10008220] */
L_006e8230:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e8238:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e8248:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e825c:;
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

void f_006e8204(CPU *c) { /* PTR_006e8204 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x4u))); /* mov eax, dword ptr [esi + ecx*4 + 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x6e8220u)); switch (t_) { case 0x006e8230u: goto L_006e8230; case 0x006e8238u: goto L_006e8238; case 0x006e8248u: goto L_006e8248; case 0x006e825cu: goto L_006e825c; default: jump_indirect(c, t_, 0x006e8217u); return; } } /* jmp dword ptr [edx*4 + 0x10008220] */
L_006e8230:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e8238:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e8248:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e825c:;
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

void f_006e8217(CPU *c) { /* PTR_006e8217 */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x6e8220u)); switch (t_) { case 0x006e8230u: goto L_006e8230; case 0x006e8238u: goto L_006e8238; case 0x006e8248u: goto L_006e8248; case 0x006e825cu: goto L_006e825c; default: jump_indirect(c, t_, 0x006e8217u); return; } } /* jmp dword ptr [edx*4 + 0x10008220] */
L_006e8230:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e8238:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e8248:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006e825c:;
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

void f_006e8230(CPU *c) { /* PTR_006e8230 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006e8238(CPU *c) { /* PTR_006e8238 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006e8248(CPU *c) { /* PTR_006e8248 */
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

void f_006e825c(CPU *c) { /* PTR_006e825c */
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

void f_006e8280(CPU *c) { /* _strlen */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u)); /* test ecx, 3 */
    if (c->zf) goto L_006e82a0; /* je 0x6e82a0 */
L_006e828c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov al, byte ptr [ecx] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_006e82d3; /* je 0x6e82d3 */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u)); /* test ecx, 3 */
    if (!c->zf) goto L_006e828c; /* jne 0x6e828c */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x0u)); /* add eax, 0 */
L_006e82a0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)((uint32_t)0x7efefeffu); /* mov edx, 0x7efefeff */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ (uint32_t)0xffffffffu))); /* xor eax, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ c->edx))); /* xor eax, edx */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u)); /* test eax, 0x81010100 */
    if (c->zf) goto L_006e82a0; /* je 0x6e82a0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0xfffffffcu))); /* mov eax, dword ptr [ecx - 4] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_006e82f1; /* je 0x6e82f1 */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_006e82e7; /* je 0x6e82e7 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0xff0000u)); /* test eax, 0xff0000 */
    if (c->zf) goto L_006e82dd; /* je 0x6e82dd */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0xff000000u)); /* test eax, 0xff000000 */
    if (c->zf) goto L_006e82d3; /* je 0x6e82d3 */
    goto L_006e82a0; /* jmp 0x6e82a0 */
L_006e82d3:;
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0xffffffffu)); /* lea eax, [ecx - 1] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->esp += 4; return; /* ret  */
L_006e82dd:;
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0xfffffffeu)); /* lea eax, [ecx - 2] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->esp += 4; return; /* ret  */
L_006e82e7:;
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0xfffffffdu)); /* lea eax, [ecx - 3] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->esp += 4; return; /* ret  */
L_006e82f1:;
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0xfffffffcu)); /* lea eax, [ecx - 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->esp += 4; return; /* ret  */
}

void f_006e82fb(CPU *c) { /* PTR_006e82fb */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    PUSH32(c, 0x006e8302u); f_006e49de(c); /* call 0x6e49de */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_006e8304(CPU *c) { /* FUN_10008304 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    { uint32_t t_ = R32((uint32_t)(0x6ed084u)); PUSH32(c, 0x006e8316u); call_indirect(c, t_); } /* call dword ptr [0x1000d084] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e831c; /* je 0x6e831c */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_006e831c:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_006e8320(CPU *c) { /* FUN_10008320 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    { uint32_t t_ = R32((uint32_t)(0x6ed088u)); PUSH32(c, 0x006e8332u); call_indirect(c, t_); } /* call dword ptr [0x1000d088] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e8338; /* je 0x6e8338 */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_006e8338:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_006e833c(CPU *c) { /* FUN_1000833c */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    { uint32_t t_ = R32((uint32_t)(0x6ed08cu)); PUSH32(c, 0x006e834au); call_indirect(c, t_); } /* call dword ptr [0x1000d08c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006e8350; /* je 0x6e8350 */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_006e8350:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_006e8354(CPU *c) { /* PTR_006e8354 */
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
    if (!c->zf) goto L_006e83fc; /* jne 0x6e83fc */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    W32((uint32_t)(c->ebx + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebx - 4], eax */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebx + 0xcu))); /* mov esi, dword ptr [ebx + 0xc] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov edi, dword ptr [ebx + 8] */
L_006e838f:;
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (c->zf) goto L_006e83f5; /* je 0x6e83f5 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea ecx, [esi + esi*2] */
    (void)sub32(c, R32((uint32_t)(c->edi + c->ecx * 4 + 0x4u)), (uint32_t)0x0u); /* cmp dword ptr [edi + ecx*4 + 4], 0 */
    if (c->zf) goto L_006e83e3; /* je 0x6e83e3 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)((uint32_t)(c->ebx + 0x10u)); /* lea ebp, [ebx + 0x10] */
    { uint32_t t_ = R32((uint32_t)(c->edi + c->ecx * 4 + 0x4u)); PUSH32(c, 0x006e83a7u); call_indirect(c, t_); } /* call dword ptr [edi + ecx*4 + 4] */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ebx, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->eax))); /* or eax, eax */
    if (c->zf) goto L_006e83e3; /* je 0x6e83e3 */
    if (c->sf) goto L_006e83ee; /* js 0x6e83ee */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov edi, dword ptr [ebx + 8] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x006e83bbu); f_006e4544(c); /* call 0x6e4544 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->ebp = (uint32_t)((uint32_t)(c->ebx + 0x10u)); /* lea ebp, [ebx + 0x10] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x006e83c8u); f_006e4586(c); /* call 0x6e4586 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea ecx, [esi + esi*2] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + c->ecx * 4 + 0x8u))); /* mov eax, dword ptr [edi + ecx*4 + 8] */
    PUSH32(c, 0x006e83d9u); f_006e461a(c); /* call 0x6e461a */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + c->ecx * 4))); /* mov eax, dword ptr [edi + ecx*4] */
    W32((uint32_t)(c->ebx + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 0xc], eax */
    { uint32_t t_ = R32((uint32_t)(c->edi + c->ecx * 4 + 0x8u)); PUSH32(c, 0x006e83e3u); call_indirect(c, t_); } /* call dword ptr [edi + ecx*4 + 8] */
L_006e83e3:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov edi, dword ptr [ebx + 8] */
    c->ecx = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea ecx, [esi + esi*2] */
    c->esi = (uint32_t)(R32((uint32_t)(c->edi + c->ecx * 4))); /* mov esi, dword ptr [edi + ecx*4] */
    goto L_006e838f; /* jmp 0x6e838f */
L_006e83ee:;
    c->eax = (uint32_t)((uint32_t)0x0u); /* mov eax, 0 */
    goto L_006e8411; /* jmp 0x6e8411 */
L_006e83f5:;
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    goto L_006e8411; /* jmp 0x6e8411 */
L_006e83fc:;
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)((uint32_t)(c->ebx + 0x10u)); /* lea ebp, [ebx + 0x10] */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x006e8408u); f_006e4586(c); /* call 0x6e4586 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
L_006e8411:;
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_006e8419(CPU *c) { /* FUN_10008419 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov ebp, dword ptr [ecx] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x1cu))); /* mov eax, dword ptr [ecx + 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x18u))); /* mov eax, dword ptr [ecx + 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006e842du); f_006e4586(c); /* call 0x6e4586 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 8; return; /* ret 4 */
}
