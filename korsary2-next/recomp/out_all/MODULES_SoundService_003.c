#include "recomp.h"

void f_009b2730(CPU *c) { /* PTR_009b2730 */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    FCOM(c, ST(0), 0.0); /* ftst  */
    ; /* wait  */
    W16((uint32_t)(c->ebp + 0xffffff60u), FNSTSW(c)); /* fnstsw word ptr [ebp - 0xa0] */
    ; /* wait  */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xffffff61u)) & (uint8_t)0x1u)); /* test byte ptr [ebp - 0x9f], 1 */
    if (!c->zf) goto L_009b2753; /* jne 0x9b2753 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, RF80((uint32_t)(0x9bd320u))); /* fld xword ptr [0x1002d320] */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) | ((uint8_t)(c->ecx >> 8))))) << 8); /* or ch, ch */
    if (c->zf) goto L_009b2752; /* je 0x9b2752 */
    ST(0) = -ST(0); /* fchs  */
L_009b2752:;
    c->esp += 4; return; /* ret  */
L_009b2753:;
    W8((uint32_t)(c->ebp + 0xffffff70u), (uint8_t)((uint8_t)0x4u)); /* mov byte ptr [ebp - 0x90], 4 */
    goto L_009b2936; /* jmp 0x9b2936 */
L_009b2936:;
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, 0.0); /* fldz  */
    c->esp += 4; return; /* ret  */
}

void f_009b277e(CPU *c) { /* PTR_009b277e */
    PREEMPT_POLL(c);
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = fabs(ST(0)); /* fabs  */
    FPUSH(c, RF80((uint32_t)(0x9bd33eu))); /* fld xword ptr [0x1002d33e] */
    FCOM(c, ST(0), ST(1)); FPOP(c); FPOP(c); /* fcompp  */
    ; /* wait  */
    W16((uint32_t)(c->ebp + 0xffffff60u), FNSTSW(c)); /* fnstsw word ptr [ebp - 0xa0] */
    ; /* wait  */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xffffff61u)) & (uint8_t)0x41u)); /* test byte ptr [ebp - 0x9f], 0x41 */
    if (!c->zf) { f_009b2730(c); return; } /* jne 0x9b2730 */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = fpu_round(c, ST(0)); /* frndint  */
    FCOM(c, ST(0), 0.0); /* ftst  */
    ; /* wait  */
    W16((uint32_t)(c->ebp + 0xffffff60u), FNSTSW(c)); /* fnstsw word ptr [ebp - 0xa0] */
    ; /* wait  */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0xffffff61u))); /* mov dl, byte ptr [ebp - 0x9f] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) - ST(1)); /* fsub st(1) */
    FCOM(c, ST(0), 0.0); /* ftst  */
    ; /* wait  */
    W16((uint32_t)(c->ebp + 0xffffff60u), FNSTSW(c)); /* fnstsw word ptr [ebp - 0xa0] */
    ST(0) = fabs(ST(0)); /* fabs  */
    ST(0) = (exp2(ST(0)) - 1.0); /* f2xm1  */
    c->esp += 4; return; /* ret  */
}

void f_009b27c1(CPU *c) { /* PTR_009b27c1 */
    PREEMPT_POLL(c);
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = fpu_round(c, ST(0)); /* frndint  */
    FCOM(c, ST(0), ST(1)); FPOP(c); /* fcomp st(1) */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (!c->zf) goto L_009b27e7; /* jne 0x9b27e7 */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(0x9bd352u))); /* fmul qword ptr [0x1002d352] */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = fpu_round(c, ST(0)); /* frndint  */
    FCOM(c, ST(0), ST(1)); FPOP(c); FPOP(c); /* fcompp  */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (c->zf) goto L_009b27ee; /* je 0x9b27ee */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
L_009b27e6:;
    c->esp += 4; return; /* ret  */
L_009b27e7:;
    c->eax = (uint32_t)((uint32_t)0x0u); /* mov eax, 0 */
    goto L_009b27e6; /* jmp 0x9b27e6 */
L_009b27ee:;
    c->eax = (uint32_t)((uint32_t)0x2u); /* mov eax, 2 */
    goto L_009b27e6; /* jmp 0x9b27e6 */
}

void f_009b2830(CPU *c) { /* PTR_009b2830 */
    PREEMPT_POLL(c);
    (void)sub8(c, R8((uint32_t)(c->edx + 0xeu)), (uint8_t)0x5u); /* cmp byte ptr [edx + 0xe], 5 */
    if (!c->zf) goto L_009b2847; /* jne 0x9b2847 */
    c->ebx = (c->ebx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ebp + 0xffffff5cu))); /* mov bx, word ptr [ebp - 0xa4] */
    c->ebx = (c->ebx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ebx >> 8)) | (uint8_t)0x2u))) << 8); /* or bh, 2 */
    c->ebx = (c->ebx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ebx >> 8)) & (uint8_t)0xfeu))) << 8); /* and bh, 0xfe */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)((uint8_t)0x3fu); /* mov bl, 0x3f */
    goto L_009b284b; /* jmp 0x9b284b */
L_009b2847:;
    c->ebx = (c->ebx & 0xffff0000u) | (uint16_t)((uint16_t)0x133fu); /* mov bx, 0x133f */
L_009b284b:;
    W16((uint32_t)(c->ebp + 0xffffff5eu), (uint16_t)(((uint16_t)c->ebx))); /* mov word ptr [ebp - 0xa2], bx */
    c->fpu_cw = R16((uint32_t)(c->ebp + 0xffffff5eu)); fpu_sync_rounding(c); /* fldcw word ptr [ebp - 0xa2] */
    c->ebx = (uint32_t)((uint32_t)0x9bd39cu); /* mov ebx, 0x1002d39c */
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
    { uint32_t t_ = R32((uint32_t)(c->ebx)); switch (t_) {  default: jump_indirect(c, t_, 0x009b2895u); return; } } /* jmp dword ptr [ebx] */
}

void f_009b2a00(CPU *c) { /* FUN_10022a00 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xffffffe0u)); /* add esp, -0x20 */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov eax, dword ptr [ebp + 0x18] */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x10], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov eax, dword ptr [ebp + 0x1c] */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    { f_009b2a20(c); return; } /* jmp 0x9b2a20 */
}

void f_009b2a17(CPU *c) { /* __startOneArgErrorHandling */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xffffffe0u)); /* add esp, -0x20 */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    WF64((uint32_t)(c->ebp + 0xfffffff8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 8] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 0x1c], ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov ecx, dword ptr [ebp + 0x14] */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x18], eax */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 0x14], ecx */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x8u)); /* lea eax, [ebp + 8] */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffffe0u)); /* lea ecx, [ebp - 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x009b2a40u); f_009b3bcb(c); /* call 0x9b3bcb */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff8u))); /* fld qword ptr [ebp - 8] */
    (void)sub16(c, R16((uint32_t)(c->ebp + 0x8u)), (uint16_t)0x27fu); /* cmp word ptr [ebp + 8], 0x27f */
    if (c->zf) goto L_009b2a51; /* je 0x9b2a51 */
    c->fpu_cw = R16((uint32_t)(c->ebp + 0x8u)); fpu_sync_rounding(c); /* fldcw word ptr [ebp + 8] */
L_009b2a51:;
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_009b2a20(CPU *c) { /* PTR_009b2a20 */
    PREEMPT_POLL(c);
    WF64((uint32_t)(c->ebp + 0xfffffff8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 8] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 0x1c], ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov ecx, dword ptr [ebp + 0x14] */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x18], eax */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 0x14], ecx */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x8u)); /* lea eax, [ebp + 8] */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffffe0u)); /* lea ecx, [ebp - 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x009b2a40u); f_009b3bcb(c); /* call 0x9b3bcb */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff8u))); /* fld qword ptr [ebp - 8] */
    (void)sub16(c, R16((uint32_t)(c->ebp + 0x8u)), (uint16_t)0x27fu); /* cmp word ptr [ebp + 8], 0x27f */
    if (c->zf) goto L_009b2a51; /* je 0x9b2a51 */
    c->fpu_cw = R16((uint32_t)(c->ebp + 0x8u)); fpu_sync_rounding(c); /* fldcw word ptr [ebp + 8] */
L_009b2a51:;
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_009b2a60(CPU *c) { /* FUN_10022a60 */
    PREEMPT_POLL(c);
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = fpu_round(c, ST(0)); /* frndint  */
    ST(1) = FPRES(c, ST(0) - ST(1)); /* fsubr st(1), st(0) */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = -ST(0); /* fchs  */
    ST(0) = (exp2(ST(0)) - 1.0); /* f2xm1  */
    FPUSH(c, 1.0); /* fld1  */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = ldexp(ST(0), (int)trunc(ST(1))); /* fscale  */
    ST(1) = ST(0); FPOP(c); /* fstp st(1) */
    c->esp += 4; return; /* ret  */
}

void f_009b2a75(CPU *c) { /* FUN_10022a75 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x300u))); /* and edx, 0x300 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx | (uint32_t)0x7fu))); /* or edx, 0x7f */
    W16((uint32_t)(c->esp + 0x6u), (uint16_t)(((uint16_t)c->edx))); /* mov word ptr [esp + 6], dx */
    c->fpu_cw = R16((uint32_t)(c->esp + 0x6u)); fpu_sync_rounding(c); /* fldcw word ptr [esp + 6] */
    c->esp += 4; return; /* ret  */
}

void f_009b2a8c(CPU *c) { /* FUN_10022a8c */
    PREEMPT_POLL(c);
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x80000u)); /* test eax, 0x80000 */
    if (c->zf) goto L_009b2a99; /* je 0x9b2a99 */
    c->eax = (uint32_t)((uint32_t)0x7u); /* mov eax, 7 */
    c->esp += 4; return; /* ret  */
L_009b2a99:;
    ST(0) = FPRES(c, ST(0) + RF64((uint32_t)(0x9b5d60u))); /* fadd qword ptr [0x10025d60] */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    c->esp += 4; return; /* ret  */
}

void f_009b2aa5(CPU *c) { /* __fload_withFB */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov eax, dword ptr [edx + 4] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7ff00000u))); /* and eax, 0x7ff00000 */
    (void)sub32(c, c->eax, (uint32_t)0x7ff00000u); /* cmp eax, 0x7ff00000 */
    if (c->zf) goto L_009b2ab7; /* je 0x9b2ab7 */
    FPUSH(c, RF64((uint32_t)(c->edx))); /* fld qword ptr [edx] */
    c->esp += 4; return; /* ret  */
L_009b2ab7:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov eax, dword ptr [edx + 4] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xau)); /* sub esp, 0xa */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0x7fff0000u))); /* or eax, 0x7fff0000 */
    W32((uint32_t)(c->esp + 0x6u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 6], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov eax, dword ptr [edx + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx))); /* mov ecx, dword ptr [edx] */
    c->eax = (uint32_t)(({ unsigned n_ = 11 & 31; uint32_t r_ = n_ ? ((c->eax << n_) | (c->ecx >> (32 - n_))) : c->eax; if (n_) { c->cf = (c->eax >> (32 - n_)) & 1; c->zf = r_ == 0; c->sf = (int32_t)r_ < 0; c->pf_byte = (uint8_t)r_; } r_; })); /* shld eax, ecx, 0xb */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 11)); /* shl ecx, 0xb */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 4], eax */
    W32((uint32_t)(c->esp), (uint32_t)(c->ecx)); /* mov dword ptr [esp], ecx */
    FPUSH(c, RF80((uint32_t)(c->esp))); /* fld xword ptr [esp] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xau)); /* add esp, 0xa */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x0u)); /* test eax, 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov eax, dword ptr [edx + 4] */
    c->esp += 4; return; /* ret  */
}

void f_009b2ae8(CPU *c) { /* FUN_10022ae8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7ff00000u))); /* and eax, 0x7ff00000 */
    (void)sub32(c, c->eax, (uint32_t)0x7ff00000u); /* cmp eax, 0x7ff00000 */
    if (c->zf) goto L_009b2af9; /* je 0x9b2af9 */
    c->esp += 4; return; /* ret  */
L_009b2af9:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->esp += 4; return; /* ret  */
}

void f_009b2afe(CPU *c) { /* FUN_10022afe */
    PREEMPT_POLL(c);
    (void)sub16(c, R16((uint32_t)(c->esp)), (uint16_t)0x27fu); /* cmp word ptr [esp], 0x27f */
    if (c->zf) goto L_009b2b09; /* je 0x9b2b09 */
    c->fpu_cw = R16((uint32_t)(c->esp)); fpu_sync_rounding(c); /* fldcw word ptr [esp] */
L_009b2b09:;
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->esp += 4; return; /* ret  */
}

void f_009b2b0b(CPU *c) { /* __math_exit */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->esp))); /* mov ax, word ptr [esp] */
    (void)sub16(c, ((uint16_t)c->eax), (uint16_t)0x27fu); /* cmp ax, 0x27f */
    if (c->zf) goto L_009b2b33; /* je 0x9b2b33 */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->eax) & (uint16_t)0x20u))); /* and ax, 0x20 */
    if (c->zf) goto L_009b2b30; /* je 0x9b2b30 */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->eax) & (uint16_t)0x20u))); /* and ax, 0x20 */
    if (c->zf) goto L_009b2b30; /* je 0x9b2b30 */
    c->eax = (uint32_t)((uint32_t)0x8u); /* mov eax, 8 */
    PUSH32(c, 0x009b2b2eu); f_009b2a17(c); /* call 0x9b2a17 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->esp += 4; return; /* ret  */
L_009b2b30:;
    c->fpu_cw = R16((uint32_t)(c->esp)); fpu_sync_rounding(c); /* fldcw word ptr [esp] */
L_009b2b33:;
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->esp += 4; return; /* ret  */
}

void f_009b2b35(CPU *c) { /* PTR_009b2b35 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    WF64((uint32_t)(c->esp), ST(0)); /* fst qword ptr [esp] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7ff00000u))); /* and eax, 0x7ff00000 */
    { f_009b2b5d(c); return; } /* jmp 0x9b2b5d */
}

void f_009b2b49(CPU *c) { /* FUN_10022b49 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    WF64((uint32_t)(c->esp), ST(0)); /* fst qword ptr [esp] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7ff00000u))); /* and eax, 0x7ff00000 */
    if (c->zf) goto L_009b2b9a; /* je 0x9b2b9a */
    (void)sub32(c, c->eax, (uint32_t)0x7ff00000u); /* cmp eax, 0x7ff00000 */
    if (c->zf) goto L_009b2bc3; /* je 0x9b2bc3 */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->esp))); /* mov ax, word ptr [esp] */
    (void)sub16(c, ((uint16_t)c->eax), (uint16_t)0x27fu); /* cmp ax, 0x27f */
    if (c->zf) goto L_009b2b98; /* je 0x9b2b98 */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->eax) & (uint16_t)0x20u))); /* and ax, 0x20 */
    if (!c->zf) goto L_009b2b95; /* jne 0x9b2b95 */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->eax) & (uint16_t)0x20u))); /* and ax, 0x20 */
    if (c->zf) goto L_009b2b95; /* je 0x9b2b95 */
    c->eax = (uint32_t)((uint32_t)0x8u); /* mov eax, 8 */
L_009b2b82:;
    (void)sub32(c, c->edx, (uint32_t)0x1du); /* cmp edx, 0x1d */
    if (c->zf) goto L_009b2b8e; /* je 0x9b2b8e */
    PUSH32(c, 0x009b2b8cu); f_009b2a17(c); /* call 0x9b2a17 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->esp += 4; return; /* ret  */
L_009b2b8e:;
    PUSH32(c, 0x009b2b93u); f_009b2a00(c); /* call 0x9b2a00 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->esp += 4; return; /* ret  */
L_009b2b95:;
    c->fpu_cw = R16((uint32_t)(c->esp)); fpu_sync_rounding(c); /* fldcw word ptr [esp] */
L_009b2b98:;
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->esp += 4; return; /* ret  */
L_009b2b9a:;
    FPUSH(c, RF64((uint32_t)(0x9b5d8cu))); /* fld qword ptr [0x10025d8c] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = ldexp(ST(0), (int)trunc(ST(1))); /* fscale  */
    ST(1) = ST(0); FPOP(c); /* fstp st(1) */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = fabs(ST(0)); /* fabs  */
    FCOM(c, ST(0), RF64((uint32_t)(0x9b5d7cu))); FPOP(c); /* fcomp qword ptr [0x10025d7c] */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    c->eax = (uint32_t)((uint32_t)0x4u); /* mov eax, 4 */
    if (!c->cf) goto L_009b2b82; /* jae 0x9b2b82 */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(0x9b5d9cu))); /* fmul qword ptr [0x10025d9c] */
    goto L_009b2b82; /* jmp 0x9b2b82 */
L_009b2bc3:;
    FPUSH(c, RF64((uint32_t)(0x9b5d84u))); /* fld qword ptr [0x10025d84] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = ldexp(ST(0), (int)trunc(ST(1))); /* fscale  */
    ST(1) = ST(0); FPOP(c); /* fstp st(1) */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = fabs(ST(0)); /* fabs  */
    FCOM(c, ST(0), RF64((uint32_t)(0x9b5d74u))); FPOP(c); /* fcomp qword ptr [0x10025d74] */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    c->eax = (uint32_t)((uint32_t)0x3u); /* mov eax, 3 */
    if ((c->cf || c->zf)) goto L_009b2b82; /* jbe 0x9b2b82 */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(0x9b5d94u))); /* fmul qword ptr [0x10025d94] */
    goto L_009b2b82; /* jmp 0x9b2b82 */
}

void f_009b2b5d(CPU *c) { /* PTR_009b2b5d */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, (uint32_t)0x7ff00000u); /* cmp eax, 0x7ff00000 */
    if (c->zf) goto L_009b2bc3; /* je 0x9b2bc3 */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->esp))); /* mov ax, word ptr [esp] */
    (void)sub16(c, ((uint16_t)c->eax), (uint16_t)0x27fu); /* cmp ax, 0x27f */
    if (c->zf) goto L_009b2b98; /* je 0x9b2b98 */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->eax) & (uint16_t)0x20u))); /* and ax, 0x20 */
    if (!c->zf) goto L_009b2b95; /* jne 0x9b2b95 */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->eax) & (uint16_t)0x20u))); /* and ax, 0x20 */
    if (c->zf) goto L_009b2b95; /* je 0x9b2b95 */
    c->eax = (uint32_t)((uint32_t)0x8u); /* mov eax, 8 */
L_009b2b82:;
    (void)sub32(c, c->edx, (uint32_t)0x1du); /* cmp edx, 0x1d */
    if (c->zf) goto L_009b2b8e; /* je 0x9b2b8e */
    PUSH32(c, 0x009b2b8cu); f_009b2a17(c); /* call 0x9b2a17 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->esp += 4; return; /* ret  */
L_009b2b8e:;
    PUSH32(c, 0x009b2b93u); f_009b2a00(c); /* call 0x9b2a00 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->esp += 4; return; /* ret  */
L_009b2b95:;
    c->fpu_cw = R16((uint32_t)(c->esp)); fpu_sync_rounding(c); /* fldcw word ptr [esp] */
L_009b2b98:;
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->esp += 4; return; /* ret  */
L_009b2bc3:;
    FPUSH(c, RF64((uint32_t)(0x9b5d84u))); /* fld qword ptr [0x10025d84] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = ldexp(ST(0), (int)trunc(ST(1))); /* fscale  */
    ST(1) = ST(0); FPOP(c); /* fstp st(1) */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = fabs(ST(0)); /* fabs  */
    FCOM(c, ST(0), RF64((uint32_t)(0x9b5d74u))); FPOP(c); /* fcomp qword ptr [0x10025d74] */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    c->eax = (uint32_t)((uint32_t)0x3u); /* mov eax, 3 */
    if ((c->cf || c->zf)) goto L_009b2b82; /* jbe 0x9b2b82 */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(0x9b5d94u))); /* fmul qword ptr [0x10025d94] */
    goto L_009b2b82; /* jmp 0x9b2b82 */
}

void f_009b2bec(CPU *c) { /* FUN_10022bec */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    FCOM(c, ST(0), RF64((uint32_t)(0x9b5468u))); FPOP(c); /* fcomp qword ptr [0x10025468] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (!c->cf) goto L_009b2c09; /* jae 0x9b2c09 */
    ST(0) = -ST(0); /* fchs  */
L_009b2c09:;
    WF64((uint32_t)(c->ebp + 0xfffffff8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 8] */
    c->eax = (uint32_t)((uint32_t)0x7ff00000u); /* mov eax, 0x7ff00000 */
    c->ecx = (uint32_t)((uint32_t)0xfff00000u); /* mov ecx, 0xfff00000 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x14u)), c->eax); /* cmp dword ptr [ebp + 0x14], eax */
    if (!c->zf) goto L_009b2c4f; /* jne 0x9b2c4f */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), c->edx); /* cmp dword ptr [ebp + 0x10], edx */
    if (!c->zf) goto L_009b2c77; /* jne 0x9b2c77 */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff8u))); /* fld qword ptr [ebp - 8] */
    FCOM(c, ST(0), RF64((uint32_t)(0x9b5500u))); FPOP(c); /* fcomp qword ptr [0x10025500] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if ((!c->cf && !c->zf)) goto L_009b2c93; /* ja 0x9b2c93 */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff8u))); /* fld qword ptr [ebp - 8] */
    FCOM(c, ST(0), RF64((uint32_t)(0x9b5500u))); FPOP(c); /* fcomp qword ptr [0x10025500] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (c->cf) goto L_009b2ca9; /* jb 0x9b2ca9 */
L_009b2c3c:;
    FPUSH(c, RF64((uint32_t)(0x9b9e90u))); /* fld qword ptr [0x10029e90] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov eax, dword ptr [ebp + 0x18] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    WF64((uint32_t)(c->eax), ST(0)); FPOP(c); /* fstp qword ptr [eax] */
    goto L_009b2d17; /* jmp 0x9b2d17 */
L_009b2c4f:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x14u)), c->ecx); /* cmp dword ptr [ebp + 0x14], ecx */
    if (!c->zf) goto L_009b2c77; /* jne 0x9b2c77 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), c->edx); /* cmp dword ptr [ebp + 0x10], edx */
    if (!c->zf) goto L_009b2c77; /* jne 0x9b2c77 */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff8u))); /* fld qword ptr [ebp - 8] */
    FCOM(c, ST(0), RF64((uint32_t)(0x9b5500u))); FPOP(c); /* fcomp qword ptr [0x10025500] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if ((!c->cf && !c->zf)) goto L_009b2ca9; /* ja 0x9b2ca9 */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff8u))); /* fld qword ptr [ebp - 8] */
    FCOM(c, ST(0), RF64((uint32_t)(0x9b5500u))); FPOP(c); /* fcomp qword ptr [0x10025500] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (!c->cf) goto L_009b2c3c; /* jae 0x9b2c3c */
    goto L_009b2c93; /* jmp 0x9b2c93 */
L_009b2c77:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->eax); /* cmp dword ptr [ebp + 0xc], eax */
    if (!c->zf) goto L_009b2cad; /* jne 0x9b2cad */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), c->edx); /* cmp dword ptr [ebp + 8], edx */
    if (!c->zf) goto L_009b2d17; /* jne 0x9b2d17 */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x10u))); /* fld qword ptr [ebp + 0x10] */
    FCOM(c, ST(0), RF64((uint32_t)(0x9b5468u))); FPOP(c); /* fcomp qword ptr [0x10025468] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if ((c->cf || c->zf)) goto L_009b2c9b; /* jbe 0x9b2c9b */
L_009b2c93:;
    FPUSH(c, RF64((uint32_t)(0x9b9e88u))); /* fld qword ptr [0x10029e88] */
    goto L_009b2d12; /* jmp 0x9b2d12 */
L_009b2c9b:;
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x10u))); /* fld qword ptr [ebp + 0x10] */
    FCOM(c, ST(0), RF64((uint32_t)(0x9b5468u))); FPOP(c); /* fcomp qword ptr [0x10025468] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (!c->cf) goto L_009b2d10; /* jae 0x9b2d10 */
L_009b2ca9:;
    FPUSH(c, 0.0); /* fldz  */
    goto L_009b2d12; /* jmp 0x9b2d12 */
L_009b2cad:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->ecx); /* cmp dword ptr [ebp + 0xc], ecx */
    if (!c->zf) goto L_009b2d17; /* jne 0x9b2d17 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), c->edx); /* cmp dword ptr [ebp + 8], edx */
    if (!c->zf) goto L_009b2d17; /* jne 0x9b2d17 */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x10u))); /* fld qword ptr [ebp + 0x10] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x009b2cc4u); f_009b2d1c(c); /* call 0x9b2d1c */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x10u))); /* fld qword ptr [ebp + 0x10] */
    FCOM(c, ST(0), RF64((uint32_t)(0x9b5468u))); FPOP(c); /* fcomp qword ptr [0x10025468] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if ((c->cf || c->zf)) goto L_009b2ceb; /* jbe 0x9b2ceb */
    FPUSH(c, RF64((uint32_t)(0x9b9e88u))); /* fld qword ptr [0x10029e88] */
    (void)sub32(c, c->ecx, (uint32_t)0x1u); /* cmp ecx, 1 */
    if (!c->zf) goto L_009b2ce3; /* jne 0x9b2ce3 */
    ST(0) = -ST(0); /* fchs  */
L_009b2ce3:;
    WF64((uint32_t)(c->ebp + 0x10u), ST(0)); FPOP(c); /* fstp qword ptr [ebp + 0x10] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x10u))); /* fld qword ptr [ebp + 0x10] */
    goto L_009b2d12; /* jmp 0x9b2d12 */
L_009b2ceb:;
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x10u))); /* fld qword ptr [ebp + 0x10] */
    FCOM(c, ST(0), RF64((uint32_t)(0x9b5468u))); FPOP(c); /* fcomp qword ptr [0x10025468] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (!c->cf) goto L_009b2d10; /* jae 0x9b2d10 */
    (void)sub32(c, c->ecx, (uint32_t)0x1u); /* cmp ecx, 1 */
    if (!c->zf) goto L_009b2d06; /* jne 0x9b2d06 */
    FPUSH(c, RF64((uint32_t)(0x9b9ea8u))); /* fld qword ptr [0x10029ea8] */
    goto L_009b2d08; /* jmp 0x9b2d08 */
L_009b2d06:;
    FPUSH(c, 0.0); /* fldz  */
L_009b2d08:;
    WF64((uint32_t)(c->ebp + 0x10u), ST(0)); FPOP(c); /* fstp qword ptr [ebp + 0x10] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x10u))); /* fld qword ptr [ebp + 0x10] */
    goto L_009b2d12; /* jmp 0x9b2d12 */
L_009b2d10:;
    FPUSH(c, 1.0); /* fld1  */
L_009b2d12:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov eax, dword ptr [ebp + 0x18] */
    WF64((uint32_t)(c->eax), ST(0)); FPOP(c); /* fstp qword ptr [eax] */
L_009b2d17:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_009b2d1c(CPU *c) { /* FUN_10022d1c */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x009b2d2eu); f_009b2da2(c); /* call 0x9b2da2 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x90u)); /* test al, 0x90 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_009b2d7d; /* jne 0x9b2d7d */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x009b2d41u); f_0099f026(c); /* call 0x99f026 */
    WF64((uint32_t)(c->ebp + 0xfffffff8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 8] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff8u))); /* fld qword ptr [ebp - 8] */
    FCOM(c, ST(0), RF64((uint32_t)(c->ebp + 0x8u))); FPOP(c); /* fcomp qword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (!c->zf) goto L_009b2d7d; /* jne 0x9b2d7d */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    ST(0) = FPRES(c, FDIV(c, ST(0), RF64((uint32_t)(0x9b5c58u)))); /* fdiv qword ptr [0x10025c58] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->ebp + 0x8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp + 8] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x009b2d6au); f_0099f026(c); /* call 0x99f026 */
    FCOM(c, ST(0), RF64((uint32_t)(c->ebp + 0x8u))); FPOP(c); /* fcomp qword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (!c->zf) goto L_009b2d78; /* jne 0x9b2d78 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    goto L_009b2d7a; /* jmp 0x9b2d7a */
L_009b2d78:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
L_009b2d7a:;
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009b2d7d:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_009b2d81(CPU *c) { /* __copysign */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ R32((uint32_t)(c->ebp + 0xcu))))); /* xor eax, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fffffffu))); /* and eax, 0x7fffffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ R32((uint32_t)(c->ebp + 0x14u))))); /* xor eax, dword ptr [ebp + 0x14] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff8u))); /* fld qword ptr [ebp - 8] */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_009b2da2(CPU *c) { /* FUN_10022da2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xeu))); /* mov eax, dword ptr [ebp + 0xe] */
    c->ecx = (uint32_t)((uint32_t)0x7ff0u); /* mov ecx, 0x7ff0 */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & c->ecx))); /* and edx, ecx */
    (void)sub16(c, ((uint16_t)c->edx), ((uint16_t)c->ecx)); /* cmp dx, cx */
    if (!c->zf) goto L_009b2de2; /* jne 0x9b2de2 */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x009b2dc3u); f_0099f061(c); /* call 0x99f061 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_009b2ddb; /* je 0x9b2ddb */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_009b2dd7; /* je 0x9b2dd7 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_009b2dd3; /* je 0x9b2dd3 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
L_009b2dd0:;
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
L_009b2dd3:;
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    goto L_009b2dd0; /* jmp 0x9b2dd0 */
L_009b2dd7:;
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    goto L_009b2dd0; /* jmp 0x9b2dd0 */
L_009b2ddb:;
    c->eax = (uint32_t)((uint32_t)0x200u); /* mov eax, 0x200 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
L_009b2de2:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x8000u))); /* and eax, 0x8000 */
    (void)logic16(c, (uint16_t)(((uint16_t)c->edx) & ((uint16_t)c->edx))); /* test dx, dx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    if (!c->zf) goto L_009b2e0c; /* jne 0x9b2e0c */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->ebp + 0xcu)) & (uint32_t)0xfffffu)); /* test dword ptr [ebp + 0xc], 0xfffff */
    if (!c->zf) goto L_009b2dfd; /* jne 0x9b2dfd */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    if (c->zf) goto L_009b2e0c; /* je 0x9b2e0c */
L_009b2dfd:;
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x90u))); /* and al, 0x90 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x80u)); /* add eax, 0x80 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
L_009b2e0c:;
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    FCOM(c, ST(0), RF64((uint32_t)(0x9b5468u))); FPOP(c); /* fcomp qword ptr [0x10025468] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    if (!c->zf) goto L_009b2e27; /* jne 0x9b2e27 */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xe0u))); /* and al, 0xe0 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x40u)); /* add eax, 0x40 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
L_009b2e27:;
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x8u))); /* and al, 8 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x100u)); /* add eax, 0x100 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_009b2e40(CPU *c) { /* PTR_009b2e40 */
    PREEMPT_POLL(c);
    FPUSH(c, RF80((uint32_t)(c->esp + 0x10u))); /* fld xword ptr [esp + 0x10] */
    FPUSH(c, RF80((uint32_t)(c->esp + 0x4u))); /* fld xword ptr [esp + 4] */
L_009b2e48:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->eax = (uint32_t)(add32(c, c->eax, c->eax)); /* add eax, eax */
    if (!c->cf) goto L_009b2eda; /* jae 0x9b2eda */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ (uint32_t)0xe000000u))); /* xor eax, 0xe000000 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0xe000000u)); /* test eax, 0xe000000 */
    if (c->zf) goto L_009b2e63; /* je 0x9b2e63 */
    ST(1) = FPRES(c, FDIV(c, ST(1), ST(0))); FPOP(c); /* fdivp st(1) */
    c->esp += 4; return; /* ret  */
L_009b2e63:;
    c->eax = (uint32_t)(shr32(c, c->eax, 28)); /* shr eax, 0x1c */
    (void)sub8(c, R8((uint32_t)(c->eax + 0x9bd470u)), (uint8_t)0x0u); /* cmp byte ptr [eax + 0x1002d470], 0 */
    if (!c->zf) goto L_009b2e72; /* jne 0x9b2e72 */
    ST(1) = FPRES(c, FDIV(c, ST(1), ST(0))); FPOP(c); /* fdivp st(1) */
    c->esp += 4; return; /* ret  */
L_009b2e72:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fffu))); /* and eax, 0x7fff */
    if (c->zf) goto L_009b2ee4; /* je 0x9b2ee4 */
    (void)sub32(c, c->eax, (uint32_t)0x7fffu); /* cmp eax, 0x7fff */
    if (c->zf) goto L_009b2ee4; /* je 0x9b2ee4 */
    W16((uint32_t)(c->esp + 0x1cu), c->fpu_cw); /* fnstcw word ptr [esp + 0x1c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov eax, dword ptr [esp + 0x1c] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0x33fu))); /* or eax, 0x33f */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xf3ffu))); /* and eax, 0xf3ff */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x20], eax */
    c->fpu_cw = R16((uint32_t)(c->esp + 0x20u)); fpu_sync_rounding(c); /* fldcw word ptr [esp + 0x20] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fffu))); /* and eax, 0x7fff */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_009b2ec3; /* je 0x9b2ec3 */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x9bd480u))); /* fmul dword ptr [0x1002d480] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x9bd480u))); /* fmul dword ptr [0x1002d480] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    c->fpu_cw = R16((uint32_t)(c->esp + 0x1cu)); fpu_sync_rounding(c); /* fldcw word ptr [esp + 0x1c] */
    ST(1) = FPRES(c, FDIV(c, ST(1), ST(0))); FPOP(c); /* fdivp st(1) */
    c->esp += 4; return; /* ret  */
L_009b2ec3:;
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x9bd484u))); /* fmul dword ptr [0x1002d484] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x9bd484u))); /* fmul dword ptr [0x1002d484] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    c->fpu_cw = R16((uint32_t)(c->esp + 0x1cu)); fpu_sync_rounding(c); /* fldcw word ptr [esp + 0x1c] */
    ST(1) = FPRES(c, FDIV(c, ST(1), ST(0))); FPOP(c); /* fdivp st(1) */
    c->esp += 4; return; /* ret  */
L_009b2eda:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | R32((uint32_t)(c->esp + 0x8u))))); /* or eax, dword ptr [esp + 8] */
    if (!c->zf) goto L_009b2ee7; /* jne 0x9b2ee7 */
L_009b2ee4:;
    ST(1) = FPRES(c, FDIV(c, ST(1), ST(0))); FPOP(c); /* fdivp st(1) */
    c->esp += 4; return; /* ret  */
L_009b2ee7:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fffu))); /* and eax, 0x7fff */
    if (!c->zf) goto L_009b2ee4; /* jne 0x9b2ee4 */
    W16((uint32_t)(c->esp + 0x1cu), c->fpu_cw); /* fnstcw word ptr [esp + 0x1c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov eax, dword ptr [esp + 0x1c] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0x33fu))); /* or eax, 0x33f */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xf3ffu))); /* and eax, 0xf3ff */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x20], eax */
    c->fpu_cw = R16((uint32_t)(c->esp + 0x20u)); fpu_sync_rounding(c); /* fldcw word ptr [esp + 0x20] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fffu))); /* and eax, 0x7fff */
    if (c->zf) goto L_009b2f28; /* je 0x9b2f28 */
    (void)sub32(c, c->eax, (uint32_t)0x7fffu); /* cmp eax, 0x7fff */
    if (c->zf) goto L_009b2f50; /* je 0x9b2f50 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->eax = (uint32_t)(add32(c, c->eax, c->eax)); /* add eax, eax */
    if (!c->cf) goto L_009b2f50; /* jae 0x9b2f50 */
    goto L_009b2f30; /* jmp 0x9b2f30 */
L_009b2f28:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->eax = (uint32_t)(add32(c, c->eax, c->eax)); /* add eax, eax */
    if (c->cf) goto L_009b2f50; /* jb 0x9b2f50 */
L_009b2f30:;
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x9bd488u))); /* fmul dword ptr [0x1002d488] */
    WF80((uint32_t)(c->esp + 0x4u), ST(0)); FPOP(c); /* fstp xword ptr [esp + 4] */
    FPUSH(c, RF80((uint32_t)(c->esp + 0x10u))); /* fld xword ptr [esp + 0x10] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ; /* wait  */
    c->fpu_cw = R16((uint32_t)(c->esp + 0x1cu)); fpu_sync_rounding(c); /* fldcw word ptr [esp + 0x1c] */
    goto L_009b2e48; /* jmp 0x9b2e48 */
L_009b2f50:;
    c->fpu_cw = R16((uint32_t)(c->esp + 0x1cu)); fpu_sync_rounding(c); /* fldcw word ptr [esp + 0x1c] */
    ST(1) = FPRES(c, FDIV(c, ST(1), ST(0))); FPOP(c); /* fdivp st(1) */
    c->esp += 4; return; /* ret  */
}

void f_009b3210(CPU *c) { /* PTR_009b3210 */
    PREEMPT_POLL(c);
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    WF80((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp xword ptr [esp] */
    WF80((uint32_t)(c->esp + 0x20u), ST(0)); FPOP(c); /* fstp xword ptr [esp + 0x20] */
    PUSH32(c, 0x009b321eu); f_009b2e40(c); /* call 0x9b2e40 */
    { double t_ = ST(0); ST(0) = ST(4); ST(4) = t_; } /* fxch st(4) */
    FPUSH(c, RF80((uint32_t)(c->esp + 0x20u))); /* fld xword ptr [esp + 0x20] */
    { double t_ = ST(0); ST(0) = ST(5); ST(5) = t_; } /* fxch st(5) */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
    c->esp += 4; return; /* ret  */
}

void f_009b3220(CPU *c) { /* PTR_009b3220 */
    PREEMPT_POLL(c);
    FPUSH(c, RF80((uint32_t)(c->esp + 0x20u))); /* fld xword ptr [esp + 0x20] */
    { double t_ = ST(0); ST(0) = ST(5); ST(5) = t_; } /* fxch st(5) */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
    c->esp += 4; return; /* ret  */
}

void f_009b32a0(CPU *c) { /* PTR_009b32a0 */
    PREEMPT_POLL(c);
    WF80((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp xword ptr [esp] */
    PUSH32(c, 0x009b32a8u); f_009b2e40(c); /* call 0x9b2e40 */
    { double t_ = ST(0); ST(0) = ST(4); ST(4) = t_; } /* fxch st(4) */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
    c->esp += 4; return; /* ret  */
}

void f_009b3631(CPU *c) { /* PTR_009b3631 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x2cu)); /* sub esp, 0x2c */
    WF80((uint32_t)(c->esp + 0xcu), ST(0)); FPOP(c); /* fstp xword ptr [esp + 0xc] */
    WF80((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp xword ptr [esp] */
    PUSH32(c, 0x009b3641u); f_009b2e40(c); /* call 0x9b2e40 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_009b3bcb(CPU *c) { /* FUN_10023bcb */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x58u)); /* sub esp, 0x58 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->ecx = (uint32_t)((uint32_t)R16((uint32_t)(c->eax))); /* movzx ecx, word ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp + 0x10], ecx */
    if (c->zf) goto L_009b3c10; /* je 0x9b3c10 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_009b3c0c; /* je 0x9b3c0c */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_009b3c08; /* je 0x9b3c08 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_009b3c04; /* je 0x9b3c04 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_009b3c10; /* je 0x9b3c10 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_009b3bfc; /* je 0x9b3bfc */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (!c->zf) goto L_009b3c66; /* jne 0x9b3c66 */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    goto L_009b3c12; /* jmp 0x9b3c12 */
L_009b3bfc:;
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [esi], 1 */
    goto L_009b3c66; /* jmp 0x9b3c66 */
L_009b3c04:;
    { uint32_t v_ = 0x12u; PUSH32(c, v_); } /* push 0x12 */
    goto L_009b3c12; /* jmp 0x9b3c12 */
L_009b3c08:;
    { uint32_t v_ = 0x11u; PUSH32(c, v_); } /* push 0x11 */
    goto L_009b3c12; /* jmp 0x9b3c12 */
L_009b3c0c:;
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    goto L_009b3c12; /* jmp 0x9b3c12 */
L_009b3c10:;
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
L_009b3c12:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x18u)); /* lea edi, [esi + 0x18] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x009b3c1eu); f_0099ed0d(c); /* call 0x99ed0d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_009b3c66; /* jne 0x9b3c66 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)sub32(c, c->eax, (uint32_t)0x10u); /* cmp eax, 0x10 */
    if (c->zf) goto L_009b3c3d; /* je 0x9b3c3d */
    (void)sub32(c, c->eax, (uint32_t)0x16u); /* cmp eax, 0x16 */
    if (c->zf) goto L_009b3c3d; /* je 0x9b3c3d */
    (void)sub32(c, c->eax, (uint32_t)0x1du); /* cmp eax, 0x1d */
    if (c->zf) goto L_009b3c3d; /* je 0x9b3c3d */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe0u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0xfffffffeu)))); } /* and dword ptr [ebp - 0x20], 0xfffffffe */
    goto L_009b3c4f; /* jmp 0x9b3c4f */
L_009b3c3d:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov ecx, dword ptr [ebp - 0x20] */
    FPUSH(c, RF64((uint32_t)(c->esi + 0x10u))); /* fld qword ptr [esi + 0x10] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0xffffffe3u))); /* and ecx, 0xffffffe3 */
    WF64((uint32_t)(c->ebp + 0xffffffd0u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0x30] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0x3u))); /* or ecx, 3 */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 0x20], ecx */
L_009b3c4f:;
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x8u)); /* lea ecx, [esi + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffa8u)); /* lea eax, [ebp - 0x58] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x009b3c63u); f_0099ea5a(c); /* call 0x99ea5a */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_009b3c66:;
    { uint32_t v_ = 0xffffu; PUSH32(c, v_); } /* push 0xffff */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    PUSH32(c, 0x009b3c73u); f_0099f199(c); /* call 0x99f199 */
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x8u); /* cmp dword ptr [esi], 8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_009b3c8e; /* je 0x9b3c8e */
    (void)sub32(c, R32((uint32_t)(0x9ba2a0u)), (uint32_t)0x0u); /* cmp dword ptr [0x1002a2a0], 0 */
    if (!c->zf) goto L_009b3c8e; /* jne 0x9b3c8e */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x009b3c89u); f_009a0c5f(c); /* call 0x9a0c5f */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_009b3c96; /* jne 0x9b3c96 */
L_009b3c8e:;
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    PUSH32(c, 0x009b3c95u); f_0099efac(c); /* call 0x99efac */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_009b3c96:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_009b3ca0(CPU *c) { /* Unwind@10023ca0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xafu; PUSH32(c, v_); } /* push 0xaf */
    { uint32_t v_ = 0x9b70d4u; PUSH32(c, v_); } /* push 0x100270d4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x009b3cb3u); f_00993c50(c); /* call 0x993c50 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_009b3cb7(CPU *c) { /* PTR_009b3cb7 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x9b61b4u); /* mov eax, 0x100261b4 */
    { f_00997ff8(c); return; } /* jmp 0x997ff8 */
}

void f_009b3cd0(CPU *c) { /* PTR_009b3cd0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x9b6204u); /* mov eax, 0x10026204 */
    { f_00997ff8(c); return; } /* jmp 0x997ff8 */
}

void f_009b3ce0(CPU *c) { /* PTR_009b3ce0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x9b6254u); /* mov eax, 0x10026254 */
    { f_00997ff8(c); return; } /* jmp 0x997ff8 */
}

void f_009b3cf0(CPU *c) { /* PTR_009b3cf0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x9b62a4u); /* mov eax, 0x100262a4 */
    { f_00997ff8(c); return; } /* jmp 0x997ff8 */
}

void f_009b3d00(CPU *c) { /* Unwind@10023d00 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1u))); /* and eax, 1 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009b3d19; /* je 0x9b3d19 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x54u)); /* add ecx, 0x54 */
    { f_00991030(c); return; } /* jmp 0x991030 */
L_009b3d19:;
    c->esp += 4; return; /* ret  */
}

void f_009b3d1a(CPU *c) { /* Unwind@10023d1a */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x2u))); /* and eax, 2 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009b3d33; /* je 0x9b3d33 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x60u)); /* add ecx, 0x60 */
    { f_00991300(c); return; } /* jmp 0x991300 */
L_009b3d33:;
    c->esp += 4; return; /* ret  */
}

void f_009b3d34(CPU *c) { /* Unwind@10023d34 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_009926c0(c); return; } /* jmp 0x9926c0 */
}

void f_009b3d3c(CPU *c) { /* PTR_009b3d3c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x9b62d8u); /* mov eax, 0x100262d8 */
    { f_00997ff8(c); return; } /* jmp 0x997ff8 */
}

void f_009b3d50(CPU *c) { /* Unwind@10023d50 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_009926c0(c); return; } /* jmp 0x9926c0 */
}

void f_009b3d58(CPU *c) { /* PTR_009b3d58 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x9b62fcu); /* mov eax, 0x100262fc */
    { f_00997ff8(c); return; } /* jmp 0x997ff8 */
}

void f_009b3d70(CPU *c) { /* Unwind@10023d70 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1u))); /* and eax, 1 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009b3d89; /* je 0x9b3d89 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x54u)); /* add ecx, 0x54 */
    { f_009924f0(c); return; } /* jmp 0x9924f0 */
L_009b3d89:;
    c->esp += 4; return; /* ret  */
}

void f_009b3d8a(CPU *c) { /* Unwind@10023d8a */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x2u))); /* and eax, 2 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009b3da3; /* je 0x9b3da3 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x60u)); /* add ecx, 0x60 */
    { f_00991300(c); return; } /* jmp 0x991300 */
L_009b3da3:;
    c->esp += 4; return; /* ret  */
}

void f_009b3da4(CPU *c) { /* Unwind@10023da4 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_009926c0(c); return; } /* jmp 0x9926c0 */
}

void f_009b3dac(CPU *c) { /* PTR_009b3dac */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x9b6330u); /* mov eax, 0x10026330 */
    { f_00997ff8(c); return; } /* jmp 0x997ff8 */
}

void f_009b3dc0(CPU *c) { /* Unwind@10023dc0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_009926c0(c); return; } /* jmp 0x9926c0 */
}

void f_009b3dc8(CPU *c) { /* PTR_009b3dc8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x9b6354u); /* mov eax, 0x10026354 */
    { f_00997ff8(c); return; } /* jmp 0x997ff8 */
}

void f_009b3de0(CPU *c) { /* Unwind@10023de0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1u))); /* and eax, 1 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009b3df9; /* je 0x9b3df9 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x58u)); /* add ecx, 0x58 */
    { f_00991030(c); return; } /* jmp 0x991030 */
L_009b3df9:;
    c->esp += 4; return; /* ret  */
}

void f_009b3dfa(CPU *c) { /* Unwind@10023dfa */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x2u))); /* and eax, 2 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009b3e13; /* je 0x9b3e13 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x64u)); /* add ecx, 0x64 */
    { f_00991e30(c); return; } /* jmp 0x991e30 */
L_009b3e13:;
    c->esp += 4; return; /* ret  */
}

void f_009b3e14(CPU *c) { /* Unwind@10023e14 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_009926c0(c); return; } /* jmp 0x9926c0 */
}

void f_009b3e1c(CPU *c) { /* PTR_009b3e1c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x9b6388u); /* mov eax, 0x10026388 */
    { f_00997ff8(c); return; } /* jmp 0x997ff8 */
}

void f_009b3e30(CPU *c) { /* Unwind@10023e30 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_009926c0(c); return; } /* jmp 0x9926c0 */
}

void f_009b3e38(CPU *c) { /* PTR_009b3e38 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x9b63acu); /* mov eax, 0x100263ac */
    { f_00997ff8(c); return; } /* jmp 0x997ff8 */
}

void f_009b3e50(CPU *c) { /* Unwind@10023e50 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xf0u; PUSH32(c, v_); } /* push 0xf0 */
    { uint32_t v_ = 0x9b7250u; PUSH32(c, v_); } /* push 0x10027250 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x009b3e63u); f_00993c50(c); /* call 0x993c50 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_009b3e67(CPU *c) { /* PTR_009b3e67 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x9b63d0u); /* mov eax, 0x100263d0 */
    { f_00997ff8(c); return; } /* jmp 0x997ff8 */
}

void f_009b3e80(CPU *c) { /* Unwind@10023e80 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1u))); /* and eax, 1 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009b3e99; /* je 0x9b3e99 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x58u)); /* add ecx, 0x58 */
    { f_00991030(c); return; } /* jmp 0x991030 */
L_009b3e99:;
    c->esp += 4; return; /* ret  */
}

void f_009b3e9a(CPU *c) { /* Unwind@10023e9a */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x2u))); /* and eax, 2 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009b3eb3; /* je 0x9b3eb3 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x64u)); /* add ecx, 0x64 */
    { f_00991e30(c); return; } /* jmp 0x991e30 */
L_009b3eb3:;
    c->esp += 4; return; /* ret  */
}

void f_009b3eb4(CPU *c) { /* PTR_009b3eb4 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x9b63fcu); /* mov eax, 0x100263fc */
    { f_00997ff8(c); return; } /* jmp 0x997ff8 */
}

void f_009b3ec0(CPU *c) { /* Unwind@10023ec0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1u))); /* and eax, 1 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009b3ed9; /* je 0x9b3ed9 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x58u)); /* add ecx, 0x58 */
    { f_009924f0(c); return; } /* jmp 0x9924f0 */
L_009b3ed9:;
    c->esp += 4; return; /* ret  */
}

void f_009b3eda(CPU *c) { /* Unwind@10023eda */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x2u))); /* and eax, 2 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009b3ef3; /* je 0x9b3ef3 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x60u)); /* add ecx, 0x60 */
    { f_00991e30(c); return; } /* jmp 0x991e30 */
L_009b3ef3:;
    c->esp += 4; return; /* ret  */
}

void f_009b3ef4(CPU *c) { /* Unwind@10023ef4 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_009926c0(c); return; } /* jmp 0x9926c0 */
}

void f_009b3efc(CPU *c) { /* PTR_009b3efc */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x9b6430u); /* mov eax, 0x10026430 */
    { f_00997ff8(c); return; } /* jmp 0x997ff8 */
}

void f_009b3f10(CPU *c) { /* Unwind@10023f10 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_009926c0(c); return; } /* jmp 0x9926c0 */
}

void f_009b3f18(CPU *c) { /* PTR_009b3f18 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x9b6454u); /* mov eax, 0x10026454 */
    { f_00997ff8(c); return; } /* jmp 0x997ff8 */
}

void f_009b3f30(CPU *c) { /* Unwind@10023f30 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xfau; PUSH32(c, v_); } /* push 0xfa */
    { uint32_t v_ = 0x9b72c0u; PUSH32(c, v_); } /* push 0x100272c0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x009b3f43u); f_00993c50(c); /* call 0x993c50 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_009b3f47(CPU *c) { /* PTR_009b3f47 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x9b6478u); /* mov eax, 0x10026478 */
    { f_00997ff8(c); return; } /* jmp 0x997ff8 */
}

void f_009b3f60(CPU *c) { /* Unwind@10023f60 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1u))); /* and eax, 1 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009b3f79; /* je 0x9b3f79 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x58u)); /* add ecx, 0x58 */
    { f_009924f0(c); return; } /* jmp 0x9924f0 */
L_009b3f79:;
    c->esp += 4; return; /* ret  */
}

void f_009b3f7a(CPU *c) { /* Unwind@10023f7a */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x2u))); /* and eax, 2 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009b3f93; /* je 0x9b3f93 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x60u)); /* add ecx, 0x60 */
    { f_00991e30(c); return; } /* jmp 0x991e30 */
L_009b3f93:;
    c->esp += 4; return; /* ret  */
}

void f_009b3f94(CPU *c) { /* PTR_009b3f94 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x9b64a4u); /* mov eax, 0x100264a4 */
    { f_00997ff8(c); return; } /* jmp 0x997ff8 */
}

void f_009b3fa0(CPU *c) { /* Unwind@10023fa0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1au; PUSH32(c, v_); } /* push 0x1a */
    { uint32_t v_ = 0x9b730cu; PUSH32(c, v_); } /* push 0x1002730c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x009b3fb0u); f_00993c50(c); /* call 0x993c50 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_009b3fb4(CPU *c) { /* PTR_009b3fb4 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x9b64c8u); /* mov eax, 0x100264c8 */
    { f_00997ff8(c); return; } /* jmp 0x997ff8 */
}

void f_009b3fc0(CPU *c) { /* Unwind@10023fc0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov ecx, dword ptr [ebp - 0x14] */
    { f_00996430(c); return; } /* jmp 0x996430 */
}

void f_009b3fc8(CPU *c) { /* Unwind@10023fc8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xe9u; PUSH32(c, v_); } /* push 0xe9 */
    { uint32_t v_ = 0x9b730cu; PUSH32(c, v_); } /* push 0x1002730c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x009b3fdbu); f_00993c50(c); /* call 0x993c50 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_009b3fdf(CPU *c) { /* PTR_009b3fdf */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x9b64f4u); /* mov eax, 0x100264f4 */
    { f_00997ff8(c); return; } /* jmp 0x997ff8 */
}

void f_009b3ff0(CPU *c) { /* Unwind@10023ff0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_00996430(c); return; } /* jmp 0x996430 */
}

void f_009b3ff8(CPU *c) { /* PTR_009b3ff8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x9b6518u); /* mov eax, 0x10026518 */
    { f_00997ff8(c); return; } /* jmp 0x997ff8 */
}

void f_009b4010(CPU *c) { /* Unwind@10024010 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x320u; PUSH32(c, v_); } /* push 0x320 */
    { uint32_t v_ = 0x9b730cu; PUSH32(c, v_); } /* push 0x1002730c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffdf0u))); /* mov eax, dword ptr [ebp - 0x210] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x009b4026u); f_00993c50(c); /* call 0x993c50 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_009b402a(CPU *c) { /* Unwind@1002402a */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x323u; PUSH32(c, v_); } /* push 0x323 */
    { uint32_t v_ = 0x9b730cu; PUSH32(c, v_); } /* push 0x1002730c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffdf0u))); /* mov eax, dword ptr [ebp - 0x210] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x009b4040u); f_00993c50(c); /* call 0x993c50 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_009b4044(CPU *c) { /* Unwind@10024044 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x326u; PUSH32(c, v_); } /* push 0x326 */
    { uint32_t v_ = 0x9b730cu; PUSH32(c, v_); } /* push 0x1002730c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffdf0u))); /* mov eax, dword ptr [ebp - 0x210] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x009b405au); f_00993c50(c); /* call 0x993c50 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_009b405e(CPU *c) { /* Unwind@1002405e */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x329u; PUSH32(c, v_); } /* push 0x329 */
    { uint32_t v_ = 0x9b730cu; PUSH32(c, v_); } /* push 0x1002730c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffdf0u))); /* mov eax, dword ptr [ebp - 0x210] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x009b4074u); f_00993c50(c); /* call 0x993c50 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_009b4078(CPU *c) { /* PTR_009b4078 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x9b6554u); /* mov eax, 0x10026554 */
    { f_00997ff8(c); return; } /* jmp 0x997ff8 */
}
