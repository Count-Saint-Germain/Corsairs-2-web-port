#include "recomp.h"

void f_00b27a30(CPU *c) { /* __trandisp1 */
    PREEMPT_POLL(c);
    (void)sub8(c, R8((uint32_t)(c->edx + 0xeu)), (uint8_t)0x5u); /* cmp byte ptr [edx + 0xe], 5 */
    if (!c->zf) goto L_00b27a47; /* jne 0xb27a47 */
    c->ebx = (c->ebx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ebp + 0xffffff5cu))); /* mov bx, word ptr [ebp - 0xa4] */
    c->ebx = (c->ebx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ebx >> 8)) | (uint8_t)0x2u))) << 8); /* or bh, 2 */
    c->ebx = (c->ebx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ebx >> 8)) & (uint8_t)0xfeu))) << 8); /* and bh, 0xfe */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)((uint8_t)0x3fu); /* mov bl, 0x3f */
    goto L_00b27a4b; /* jmp 0xb27a4b */
L_00b27a47:;
    c->ebx = (c->ebx & 0xffff0000u) | (uint16_t)((uint16_t)0x133fu); /* mov bx, 0x133f */
L_00b27a4b:;
    W16((uint32_t)(c->ebp + 0xffffff5eu), (uint16_t)(((uint16_t)c->ebx))); /* mov word ptr [ebp - 0xa2], bx */
    c->fpu_cw = R16((uint32_t)(c->ebp + 0xffffff5eu)); fpu_sync_rounding(c); /* fldcw word ptr [ebp - 0xa2] */
    c->ebx = (uint32_t)((uint32_t)0xb3070cu); /* mov ebx, 0x1001070c */
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
    { uint32_t t_ = R32((uint32_t)(c->ebx)); switch (t_) {  default: jump_indirect(c, t_, 0x00b27a95u); return; } } /* jmp dword ptr [ebx] */
}

void f_00b27a97(CPU *c) { /* __trandisp2 */
    PREEMPT_POLL(c);
    (void)sub8(c, R8((uint32_t)(c->edx + 0xeu)), (uint8_t)0x5u); /* cmp byte ptr [edx + 0xe], 5 */
    if (!c->zf) goto L_00b27aae; /* jne 0xb27aae */
    c->ebx = (c->ebx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ebp + 0xffffff5cu))); /* mov bx, word ptr [ebp - 0xa4] */
    c->ebx = (c->ebx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ebx >> 8)) | (uint8_t)0x2u))) << 8); /* or bh, 2 */
    c->ebx = (c->ebx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ebx >> 8)) & (uint8_t)0xfeu))) << 8); /* and bh, 0xfe */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)((uint8_t)0x3fu); /* mov bl, 0x3f */
    goto L_00b27ab2; /* jmp 0xb27ab2 */
L_00b27aae:;
    c->ebx = (c->ebx & 0xffff0000u) | (uint16_t)((uint16_t)0x133fu); /* mov bx, 0x133f */
L_00b27ab2:;
    W16((uint32_t)(c->ebp + 0xffffff5eu), (uint16_t)(((uint16_t)c->ebx))); /* mov word ptr [ebp - 0xa2], bx */
    c->fpu_cw = R16((uint32_t)(c->ebp + 0xffffff5eu)); fpu_sync_rounding(c); /* fldcw word ptr [ebp - 0xa2] */
    c->ebx = (uint32_t)((uint32_t)0xb3070cu); /* mov ebx, 0x1001070c */
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
    { uint32_t t_ = R32((uint32_t)(c->ebx)); switch (t_) {  default: jump_indirect(c, t_, 0x00b27b21u); return; } } /* jmp dword ptr [ebx] */
}

void f_00b27b23(CPU *c) { /* PTR_00b27b23 */
    PREEMPT_POLL(c);
    PUSH32(c, 0x00b27b28u); f_00b27be9(c); /* call 0xb27be9 */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    c->esp += 4; return; /* ret  */
}

void f_00b27b34(CPU *c) { /* PTR_00b27b34 */
    PREEMPT_POLL(c);
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, 0.0); /* fldz  */
    c->esp += 4; return; /* ret  */
}

void f_00b27b6d(CPU *c) { /* PTR_00b27b6d */
    PREEMPT_POLL(c);
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    WF80((uint32_t)(c->ebp + 0xffffff62u), ST(0)); FPOP(c); /* fstp xword ptr [ebp - 0x9e] */
    FPUSH(c, RF80((uint32_t)(c->ebp + 0xffffff62u))); /* fld xword ptr [ebp - 0x9e] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xffffff69u)) & (uint8_t)0x40u)); /* test byte ptr [ebp - 0x97], 0x40 */
    if (c->zf) goto L_00b27b8d; /* je 0xb27b8d */
    W8((uint32_t)(c->ebp + 0xffffff70u), (uint8_t)((uint8_t)0x7u)); /* mov byte ptr [ebp - 0x90], 7 */
    goto L_00b27b94; /* jmp 0xb27b94 */
L_00b27b8d:;
    W8((uint32_t)(c->ebp + 0xffffff70u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ebp - 0x90], 1 */
L_00b27b94:;
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    c->esp += 4; return; /* ret  */
}

void f_00b27b6f(CPU *c) { /* PTR_00b27b6f */
    PREEMPT_POLL(c);
    WF80((uint32_t)(c->ebp + 0xffffff62u), ST(0)); FPOP(c); /* fstp xword ptr [ebp - 0x9e] */
    FPUSH(c, RF80((uint32_t)(c->ebp + 0xffffff62u))); /* fld xword ptr [ebp - 0x9e] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xffffff69u)) & (uint8_t)0x40u)); /* test byte ptr [ebp - 0x97], 0x40 */
    if (c->zf) goto L_00b27b8d; /* je 0xb27b8d */
    W8((uint32_t)(c->ebp + 0xffffff70u), (uint8_t)((uint8_t)0x7u)); /* mov byte ptr [ebp - 0x90], 7 */
    goto L_00b27b94; /* jmp 0xb27b94 */
L_00b27b8d:;
    W8((uint32_t)(c->ebp + 0xffffff70u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ebp - 0x90], 1 */
L_00b27b94:;
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    c->esp += 4; return; /* ret  */
}

void f_00b27b97(CPU *c) { /* PTR_00b27b97 */
    PREEMPT_POLL(c);
    WF80((uint32_t)(c->ebp + 0xffffff62u), ST(0)); FPOP(c); /* fstp xword ptr [ebp - 0x9e] */
    FPUSH(c, RF80((uint32_t)(c->ebp + 0xffffff62u))); /* fld xword ptr [ebp - 0x9e] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xffffff69u)) & (uint8_t)0x40u)); /* test byte ptr [ebp - 0x97], 0x40 */
    if (c->zf) goto L_00b27bcc; /* je 0xb27bcc */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    WF80((uint32_t)(c->ebp + 0xffffff62u), ST(0)); FPOP(c); /* fstp xword ptr [ebp - 0x9e] */
    FPUSH(c, RF80((uint32_t)(c->ebp + 0xffffff62u))); /* fld xword ptr [ebp - 0x9e] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xffffff69u)) & (uint8_t)0x40u)); /* test byte ptr [ebp - 0x97], 0x40 */
    if (c->zf) goto L_00b27bcc; /* je 0xb27bcc */
    W8((uint32_t)(c->ebp + 0xffffff70u), (uint8_t)((uint8_t)0x7u)); /* mov byte ptr [ebp - 0x90], 7 */
    goto L_00b27bd3; /* jmp 0xb27bd3 */
L_00b27bcc:;
    W8((uint32_t)(c->ebp + 0xffffff70u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ebp - 0x90], 1 */
L_00b27bd3:;
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    c->esp += 4; return; /* ret  */
}

void f_00b27bd6(CPU *c) { /* PTR_00b27bd6 */
    PREEMPT_POLL(c);
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, RF80((uint32_t)(0xb306f0u))); /* fld xword ptr [0x100106f0] */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xffffff70u)), (uint8_t)0x0u); /* cmp byte ptr [ebp - 0x90], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_00b27bf0; /* jg 0xb27bf0 */
    W8((uint32_t)(c->ebp + 0xffffff70u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ebp - 0x90], 1 */
L_00b27bf0:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->ecx) | ((uint8_t)c->ecx)))); /* or cl, cl */
    c->esp += 4; return; /* ret  */
}

void f_00b27be9(CPU *c) { /* PTR_00b27be9 */
    PREEMPT_POLL(c);
    W8((uint32_t)(c->ebp + 0xffffff70u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ebp - 0x90], 1 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->ecx) | ((uint8_t)c->ecx)))); /* or cl, cl */
    c->esp += 4; return; /* ret  */
}

void f_00b27c00(CPU *c) { /* PTR_00b27c00 */
    PREEMPT_POLL(c);
    FPUSH(c, RF80((uint32_t)(c->esp + 0x10u))); /* fld xword ptr [esp + 0x10] */
    FPUSH(c, RF80((uint32_t)(c->esp + 0x4u))); /* fld xword ptr [esp + 4] */
L_00b27c08:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->eax = (uint32_t)(add32(c, c->eax, c->eax)); /* add eax, eax */
    if (!c->cf) goto L_00b27c9a; /* jae 0xb27c9a */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ (uint32_t)0xe000000u))); /* xor eax, 0xe000000 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0xe000000u)); /* test eax, 0xe000000 */
    if (c->zf) goto L_00b27c23; /* je 0xb27c23 */
    ST(1) = FPRES(c, FDIV(c, ST(1), ST(0))); FPOP(c); /* fdivp st(1) */
    c->esp += 4; return; /* ret  */
L_00b27c23:;
    c->eax = (uint32_t)(shr32(c, c->eax, 28)); /* shr eax, 0x1c */
    (void)sub8(c, R8((uint32_t)(c->eax + 0xb30720u)), (uint8_t)0x0u); /* cmp byte ptr [eax + 0x10010720], 0 */
    if (!c->zf) goto L_00b27c32; /* jne 0xb27c32 */
    ST(1) = FPRES(c, FDIV(c, ST(1), ST(0))); FPOP(c); /* fdivp st(1) */
    c->esp += 4; return; /* ret  */
L_00b27c32:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fffu))); /* and eax, 0x7fff */
    if (c->zf) goto L_00b27ca4; /* je 0xb27ca4 */
    (void)sub32(c, c->eax, (uint32_t)0x7fffu); /* cmp eax, 0x7fff */
    if (c->zf) goto L_00b27ca4; /* je 0xb27ca4 */
    W16((uint32_t)(c->esp + 0x1cu), c->fpu_cw); /* fnstcw word ptr [esp + 0x1c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov eax, dword ptr [esp + 0x1c] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0x33fu))); /* or eax, 0x33f */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xf3ffu))); /* and eax, 0xf3ff */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x20], eax */
    c->fpu_cw = R16((uint32_t)(c->esp + 0x20u)); fpu_sync_rounding(c); /* fldcw word ptr [esp + 0x20] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fffu))); /* and eax, 0x7fff */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_00b27c83; /* je 0xb27c83 */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb30730u))); /* fmul dword ptr [0x10010730] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb30730u))); /* fmul dword ptr [0x10010730] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    c->fpu_cw = R16((uint32_t)(c->esp + 0x1cu)); fpu_sync_rounding(c); /* fldcw word ptr [esp + 0x1c] */
    ST(1) = FPRES(c, FDIV(c, ST(1), ST(0))); FPOP(c); /* fdivp st(1) */
    c->esp += 4; return; /* ret  */
L_00b27c83:;
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb30734u))); /* fmul dword ptr [0x10010734] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb30734u))); /* fmul dword ptr [0x10010734] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    c->fpu_cw = R16((uint32_t)(c->esp + 0x1cu)); fpu_sync_rounding(c); /* fldcw word ptr [esp + 0x1c] */
    ST(1) = FPRES(c, FDIV(c, ST(1), ST(0))); FPOP(c); /* fdivp st(1) */
    c->esp += 4; return; /* ret  */
L_00b27c9a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | R32((uint32_t)(c->esp + 0x8u))))); /* or eax, dword ptr [esp + 8] */
    if (!c->zf) goto L_00b27ca7; /* jne 0xb27ca7 */
L_00b27ca4:;
    ST(1) = FPRES(c, FDIV(c, ST(1), ST(0))); FPOP(c); /* fdivp st(1) */
    c->esp += 4; return; /* ret  */
L_00b27ca7:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fffu))); /* and eax, 0x7fff */
    if (!c->zf) goto L_00b27ca4; /* jne 0xb27ca4 */
    W16((uint32_t)(c->esp + 0x1cu), c->fpu_cw); /* fnstcw word ptr [esp + 0x1c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov eax, dword ptr [esp + 0x1c] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0x33fu))); /* or eax, 0x33f */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xf3ffu))); /* and eax, 0xf3ff */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x20], eax */
    c->fpu_cw = R16((uint32_t)(c->esp + 0x20u)); fpu_sync_rounding(c); /* fldcw word ptr [esp + 0x20] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fffu))); /* and eax, 0x7fff */
    if (c->zf) goto L_00b27ce8; /* je 0xb27ce8 */
    (void)sub32(c, c->eax, (uint32_t)0x7fffu); /* cmp eax, 0x7fff */
    if (c->zf) goto L_00b27d10; /* je 0xb27d10 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->eax = (uint32_t)(add32(c, c->eax, c->eax)); /* add eax, eax */
    if (!c->cf) goto L_00b27d10; /* jae 0xb27d10 */
    goto L_00b27cf0; /* jmp 0xb27cf0 */
L_00b27ce8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->eax = (uint32_t)(add32(c, c->eax, c->eax)); /* add eax, eax */
    if (c->cf) goto L_00b27d10; /* jb 0xb27d10 */
L_00b27cf0:;
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xb30738u))); /* fmul dword ptr [0x10010738] */
    WF80((uint32_t)(c->esp + 0x4u), ST(0)); FPOP(c); /* fstp xword ptr [esp + 4] */
    FPUSH(c, RF80((uint32_t)(c->esp + 0x10u))); /* fld xword ptr [esp + 0x10] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ; /* wait  */
    c->fpu_cw = R16((uint32_t)(c->esp + 0x1cu)); fpu_sync_rounding(c); /* fldcw word ptr [esp + 0x1c] */
    goto L_00b27c08; /* jmp 0xb27c08 */
L_00b27d10:;
    c->fpu_cw = R16((uint32_t)(c->esp + 0x1cu)); fpu_sync_rounding(c); /* fldcw word ptr [esp + 0x1c] */
    ST(1) = FPRES(c, FDIV(c, ST(1), ST(0))); FPOP(c); /* fdivp st(1) */
    c->esp += 4; return; /* ret  */
}

void f_00b27fd0(CPU *c) { /* PTR_00b27fd0 */
    PREEMPT_POLL(c);
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    WF80((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp xword ptr [esp] */
    WF80((uint32_t)(c->esp + 0x20u), ST(0)); FPOP(c); /* fstp xword ptr [esp + 0x20] */
    PUSH32(c, 0x00b27fdeu); f_00b27c00(c); /* call 0xb27c00 */
    { double t_ = ST(0); ST(0) = ST(4); ST(4) = t_; } /* fxch st(4) */
    FPUSH(c, RF80((uint32_t)(c->esp + 0x20u))); /* fld xword ptr [esp + 0x20] */
    { double t_ = ST(0); ST(0) = ST(5); ST(5) = t_; } /* fxch st(5) */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
    c->esp += 4; return; /* ret  */
}

void f_00b27fe0(CPU *c) { /* PTR_00b27fe0 */
    PREEMPT_POLL(c);
    FPUSH(c, RF80((uint32_t)(c->esp + 0x20u))); /* fld xword ptr [esp + 0x20] */
    { double t_ = ST(0); ST(0) = ST(5); ST(5) = t_; } /* fxch st(5) */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
    c->esp += 4; return; /* ret  */
}

void f_00b28060(CPU *c) { /* PTR_00b28060 */
    PREEMPT_POLL(c);
    WF80((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp xword ptr [esp] */
    PUSH32(c, 0x00b28068u); f_00b27c00(c); /* call 0xb27c00 */
    { double t_ = ST(0); ST(0) = ST(4); ST(4) = t_; } /* fxch st(4) */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
    c->esp += 4; return; /* ret  */
}

void f_00b281b6(CPU *c) { /* PTR_00b281b6 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x2cu)); /* sub esp, 0x2c */
    WF80((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp xword ptr [esp] */
    WF80((uint32_t)(c->esp + 0xcu), ST(0)); FPOP(c); /* fstp xword ptr [esp + 0xc] */
    PUSH32(c, 0x00b281c5u); f_00b27c00(c); /* call 0xb27c00 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
    c->esp += 4; return; /* ret  */
}

void f_00b281c9(CPU *c) { /* PTR_00b281c9 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x2cu)); /* sub esp, 0x2c */
    WF80((uint32_t)(c->esp + 0xcu), ST(0)); FPOP(c); /* fstp xword ptr [esp + 0xc] */
    WF80((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp xword ptr [esp] */
    PUSH32(c, 0x00b281d8u); f_00b27c00(c); /* call 0xb27c00 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
    c->esp += 4; return; /* ret  */
}

void f_00b28406(CPU *c) { /* FUN_10008406 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x16u))); /* mov eax, dword ptr [esp + 0x16] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ (uint32_t)0x700u))); /* xor eax, 0x700 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x700u)); /* test eax, 0x700 */
    if (!c->zf) goto L_00b285a0; /* jne 0xb285a0 */
    c->eax = (uint32_t)(shr32(c, c->eax, 11)); /* shr eax, 0xb */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xfu))); /* and eax, 0xf */
    (void)sub8(c, R8((uint32_t)(c->eax + 0xb3073cu)), (uint8_t)0x0u); /* cmp byte ptr [eax + 0x1001073c], 0 */
    if (c->zf) goto L_00b285a0; /* je 0xb285a0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x16u))); /* mov eax, dword ptr [esp + 0x16] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fff0000u))); /* and eax, 0x7fff0000 */
    (void)sub32(c, c->eax, (uint32_t)0x7fff0000u); /* cmp eax, 0x7fff0000 */
    if (c->zf) goto L_00b285a0; /* je 0xb285a0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x2eu))); /* mov eax, dword ptr [esp + 0x2e] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fff0000u))); /* and eax, 0x7fff0000 */
    if (c->zf) goto L_00b285a0; /* je 0xb285a0 */
    (void)sub32(c, c->eax, (uint32_t)0x7fff0000u); /* cmp eax, 0x7fff0000 */
    if (c->zf) goto L_00b285a0; /* je 0xb285a0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov eax, dword ptr [esp + 0x2c] */
    c->eax = (uint32_t)(add32(c, c->eax, c->eax)); /* add eax, eax */
    if (!c->zf) goto L_00b285a0; /* jne 0xb285a0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->eax = (uint32_t)(add32(c, c->eax, c->eax)); /* add eax, eax */
    if (!c->zf) goto L_00b285a0; /* jne 0xb285a0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fffu))); /* and eax, 0x7fff */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x3fu)); /* add eax, 0x3f */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov ebx, dword ptr [esp + 0x30] */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x7fffu))); /* and ebx, 0x7fff */
    c->ebx = (uint32_t)(sub32(c, c->ebx, c->eax)); /* sub ebx, eax */
    if ((!c->cf && !c->zf)) goto L_00b284ee; /* ja 0xb284ee */
L_00b28490:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fffu))); /* and eax, 0x7fff */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xau)); /* add eax, 0xa */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov ebx, dword ptr [esp + 0x30] */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x7fffu))); /* and ebx, 0x7fff */
    c->ebx = (uint32_t)(sub32(c, c->ebx, c->eax)); /* sub ebx, eax */
    if (c->sf) goto L_00b285a0; /* js 0xb285a0 */
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
    goto L_00b28490; /* jmp 0xb28490 */
L_00b284ee:;
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x2u)); /* test edx, 2 */
    if (!c->zf) goto L_00b284fe; /* jne 0xb284fe */
    FPUSH(c, RF80((uint32_t)(c->esp + 0x10u))); /* fld xword ptr [esp + 0x10] */
    WF80((uint32_t)(c->esp + 0x1cu), ST(0)); FPOP(c); /* fstp xword ptr [esp + 0x1c] */
L_00b284fe:;
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
L_00b28558:;
    FCOM(c, ST(0), ST(1)); /* fcom st(1) */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x100u))); /* and eax, 0x100 */
    if (!c->zf) goto L_00b28565; /* jne 0xb28565 */
    ST(0) = FPRES(c, ST(0) - ST(1)); /* fsub st(1) */
L_00b28565:;
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(0xb3076cu))); /* fmul qword ptr [0x1001076c] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x1u)); /* sub ecx, 1 */
    if (!c->zf) goto L_00b28558; /* jne 0xb28558 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov ebx, dword ptr [esp + 0x30] */
    WF80((uint32_t)(c->esp + 0x28u), ST(0)); FPOP(c); /* fstp xword ptr [esp + 0x28] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, RF80((uint32_t)(c->esp + 0x1cu))); /* fld xword ptr [esp + 0x1c] */
    FPUSH(c, RF80((uint32_t)(0xb30774u))); /* fld xword ptr [0x10010774] */
    ST(0) = fmod(ST(0), ST(1)); c->fpu_sw &= ~0x0400; /* fprem  */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, RF80((uint32_t)(c->esp + 0x28u))); /* fld xword ptr [esp + 0x28] */
    c->fpu_cw = R16((uint32_t)(c->esp + 0x34u)); fpu_sync_rounding(c); /* fldcw word ptr [esp + 0x34] */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x8000u))); /* and ebx, 0x8000 */
    if (c->zf) goto L_00b285aa; /* je 0xb285aa */
    ST(0) = -ST(0); /* fchs  */
    goto L_00b285aa; /* jmp 0xb285aa */
L_00b285a0:;
    FPUSH(c, RF80((uint32_t)(c->esp + 0x10u))); /* fld xword ptr [esp + 0x10] */
    FPUSH(c, RF80((uint32_t)(c->esp + 0x28u))); /* fld xword ptr [esp + 0x28] */
    ST(0) = fmod(ST(0), ST(1)); c->fpu_sw &= ~0x0400; /* fprem  */
L_00b285aa:;
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u)); /* test edx, 3 */
    if (c->zf) goto L_00b28608; /* je 0xb28608 */
    W16((uint32_t)(c->esp + 0x3cu), FNSTSW(c)); /* fnstsw word ptr [esp + 0x3c] */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x1u)); /* test edx, 1 */
    if (c->zf) goto L_00b285dd; /* je 0xb285dd */
    W16((uint32_t)(c->esp + 0x34u), c->fpu_cw); /* fnstcw word ptr [esp + 0x34] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov eax, dword ptr [esp + 0x34] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0x300u))); /* or eax, 0x300 */
    W32((uint32_t)(c->esp + 0x38u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x38], eax */
    c->fpu_cw = R16((uint32_t)(c->esp + 0x38u)); fpu_sync_rounding(c); /* fldcw word ptr [esp + 0x38] */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(0xb3075cu))); /* fmul qword ptr [0x1001075c] */
    c->fpu_cw = R16((uint32_t)(c->esp + 0x34u)); fpu_sync_rounding(c); /* fldcw word ptr [esp + 0x34] */
L_00b285dd:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x3cu))); /* mov eax, dword ptr [esp + 0x3c] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, RF80((uint32_t)(c->esp + 0x1cu))); /* fld xword ptr [esp + 0x1c] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4300u))); /* and eax, 0x4300 */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x1cu)); /* sub esp, 0x1c */
    guest_trap(c, 0x00b285f3u, "unsupported: fnstenv [esp]"); /* fnstenv [esp] */
    { uint32_t a_ = (uint32_t)(c->esp + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0xbcffu)))); } /* and dword ptr [esp + 4], 0xbcff */
    { uint32_t a_ = (uint32_t)(c->esp + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->eax)))); } /* or dword ptr [esp + 4], eax */
    guest_trap(c, 0x00b28602u, "unsupported: fldenv [esp]"); /* fldenv [esp] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
L_00b28608:;
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_00b2860c(CPU *c) { /* FUN_1000860c */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x30u)); /* sub esp, 0x30 */
    WF80((uint32_t)(c->esp + 0x18u), ST(0)); FPOP(c); /* fstp xword ptr [esp + 0x18] */
    WF80((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp xword ptr [esp] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x6u))); /* mov eax, dword ptr [esp + 6] */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fff0000u)); /* test eax, 0x7fff0000 */
    if (c->zf) goto L_00b2862e; /* je 0xb2862e */
    PUSH32(c, 0x00b28629u); f_00b28406(c); /* call 0xb28406 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x30u)); /* add esp, 0x30 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->esp += 4; return; /* ret  */
L_00b2862e:;
    FPUSH(c, RF80((uint32_t)(c->esp))); /* fld xword ptr [esp] */
    FPUSH(c, RF80((uint32_t)(c->esp + 0x18u))); /* fld xword ptr [esp + 0x18] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp))); /* mov eax, dword ptr [esp] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | R32((uint32_t)(c->esp + 0x4u))))); /* or eax, dword ptr [esp + 4] */
    if (c->zf) goto L_00b286b7; /* je 0xb286b7 */
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
    if ((!c->cf && !c->zf)) goto L_00b28689; /* ja 0xb28689 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx | (uint32_t)0x1u))); /* or edx, 1 */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(0xb30754u))); /* fmul qword ptr [0x10010754] */
    WF80((uint32_t)(c->esp + 0x18u), ST(0)); FPOP(c); /* fstp xword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(0xb30754u))); /* fmul qword ptr [0x10010754] */
    WF80((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp xword ptr [esp] */
    goto L_00b286a9; /* jmp 0xb286a9 */
L_00b28689:;
    W16((uint32_t)(c->esp + 0x24u), c->fpu_cw); /* fnstcw word ptr [esp + 0x24] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov eax, dword ptr [esp + 0x24] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0x300u))); /* or eax, 0x300 */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x28], eax */
    c->fpu_cw = R16((uint32_t)(c->esp + 0x28u)); fpu_sync_rounding(c); /* fldcw word ptr [esp + 0x28] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(0xb30754u))); /* fmul qword ptr [0x10010754] */
    WF80((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp xword ptr [esp] */
L_00b286a9:;
    c->fpu_cw = R16((uint32_t)(c->esp + 0x24u)); fpu_sync_rounding(c); /* fldcw word ptr [esp + 0x24] */
    PUSH32(c, 0x00b286b2u); f_00b28406(c); /* call 0xb28406 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x30u)); /* add esp, 0x30 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->esp += 4; return; /* ret  */
L_00b286b7:;
    ST(0) = fmod(ST(0), ST(1)); c->fpu_sw &= ~0x0400; /* fprem  */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x30u)); /* add esp, 0x30 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->esp += 4; return; /* ret  */
}

void f_00b286be(CPU *c) { /* PTR_00b286be */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x16u))); /* mov eax, dword ptr [esp + 0x16] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ (uint32_t)0x700u))); /* xor eax, 0x700 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x700u)); /* test eax, 0x700 */
    if (!c->zf) goto L_00b28858; /* jne 0xb28858 */
    c->eax = (uint32_t)(shr32(c, c->eax, 11)); /* shr eax, 0xb */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xfu))); /* and eax, 0xf */
    (void)sub8(c, R8((uint32_t)(c->eax + 0xb3073cu)), (uint8_t)0x0u); /* cmp byte ptr [eax + 0x1001073c], 0 */
    if (c->zf) goto L_00b28858; /* je 0xb28858 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x16u))); /* mov eax, dword ptr [esp + 0x16] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fff0000u))); /* and eax, 0x7fff0000 */
    (void)sub32(c, c->eax, (uint32_t)0x7fff0000u); /* cmp eax, 0x7fff0000 */
    if (c->zf) goto L_00b28858; /* je 0xb28858 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x2eu))); /* mov eax, dword ptr [esp + 0x2e] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fff0000u))); /* and eax, 0x7fff0000 */
    if (c->zf) goto L_00b28858; /* je 0xb28858 */
    (void)sub32(c, c->eax, (uint32_t)0x7fff0000u); /* cmp eax, 0x7fff0000 */
    if (c->zf) goto L_00b28858; /* je 0xb28858 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov eax, dword ptr [esp + 0x2c] */
    c->eax = (uint32_t)(add32(c, c->eax, c->eax)); /* add eax, eax */
    if (!c->zf) goto L_00b28858; /* jne 0xb28858 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->eax = (uint32_t)(add32(c, c->eax, c->eax)); /* add eax, eax */
    if (!c->zf) goto L_00b28858; /* jne 0xb28858 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fffu))); /* and eax, 0x7fff */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x3fu)); /* add eax, 0x3f */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov ebx, dword ptr [esp + 0x30] */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x7fffu))); /* and ebx, 0x7fff */
    c->ebx = (uint32_t)(sub32(c, c->ebx, c->eax)); /* sub ebx, eax */
    if ((!c->cf && !c->zf)) goto L_00b287a6; /* ja 0xb287a6 */
L_00b28748:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fffu))); /* and eax, 0x7fff */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xau)); /* add eax, 0xa */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov ebx, dword ptr [esp + 0x30] */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x7fffu))); /* and ebx, 0x7fff */
    c->ebx = (uint32_t)(sub32(c, c->ebx, c->eax)); /* sub ebx, eax */
    if (c->sf) goto L_00b28858; /* js 0xb28858 */
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
    goto L_00b28748; /* jmp 0xb28748 */
L_00b287a6:;
    (void)logic32(c, (uint32_t)(c->ebx & (uint32_t)0x2u)); /* test ebx, 2 */
    if (!c->zf) goto L_00b287b6; /* jne 0xb287b6 */
    FPUSH(c, RF80((uint32_t)(c->esp + 0x10u))); /* fld xword ptr [esp + 0x10] */
    WF80((uint32_t)(c->esp + 0x1cu), ST(0)); FPOP(c); /* fstp xword ptr [esp + 0x1c] */
L_00b287b6:;
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
L_00b28810:;
    FCOM(c, ST(0), ST(1)); /* fcom st(1) */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x100u))); /* and eax, 0x100 */
    if (!c->zf) goto L_00b2881d; /* jne 0xb2881d */
    ST(0) = FPRES(c, ST(0) - ST(1)); /* fsub st(1) */
L_00b2881d:;
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(0xb3076cu))); /* fmul qword ptr [0x1001076c] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x1u)); /* sub ecx, 1 */
    if (!c->zf) goto L_00b28810; /* jne 0xb28810 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov ebx, dword ptr [esp + 0x30] */
    WF80((uint32_t)(c->esp + 0x28u), ST(0)); FPOP(c); /* fstp xword ptr [esp + 0x28] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, RF80((uint32_t)(c->esp + 0x1cu))); /* fld xword ptr [esp + 0x1c] */
    FPUSH(c, RF80((uint32_t)(0xb30774u))); /* fld xword ptr [0x10010774] */
    ST(0) = remainder(ST(0), ST(1)); c->fpu_sw &= ~0x0400; /* fprem1  */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, RF80((uint32_t)(c->esp + 0x28u))); /* fld xword ptr [esp + 0x28] */
    c->fpu_cw = R16((uint32_t)(c->esp + 0x34u)); fpu_sync_rounding(c); /* fldcw word ptr [esp + 0x34] */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x8000u))); /* and ebx, 0x8000 */
    if (c->zf) goto L_00b28862; /* je 0xb28862 */
    ST(0) = -ST(0); /* fchs  */
    goto L_00b28862; /* jmp 0xb28862 */
L_00b28858:;
    FPUSH(c, RF80((uint32_t)(c->esp + 0x10u))); /* fld xword ptr [esp + 0x10] */
    FPUSH(c, RF80((uint32_t)(c->esp + 0x28u))); /* fld xword ptr [esp + 0x28] */
    ST(0) = remainder(ST(0), ST(1)); c->fpu_sw &= ~0x0400; /* fprem1  */
L_00b28862:;
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u)); /* test edx, 3 */
    if (c->zf) goto L_00b288c0; /* je 0xb288c0 */
    W16((uint32_t)(c->esp + 0x3cu), FNSTSW(c)); /* fnstsw word ptr [esp + 0x3c] */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x1u)); /* test edx, 1 */
    if (c->zf) goto L_00b28895; /* je 0xb28895 */
    W16((uint32_t)(c->esp + 0x34u), c->fpu_cw); /* fnstcw word ptr [esp + 0x34] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov eax, dword ptr [esp + 0x34] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0x300u))); /* or eax, 0x300 */
    W32((uint32_t)(c->esp + 0x38u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x38], eax */
    c->fpu_cw = R16((uint32_t)(c->esp + 0x38u)); fpu_sync_rounding(c); /* fldcw word ptr [esp + 0x38] */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(0xb3075cu))); /* fmul qword ptr [0x1001075c] */
    c->fpu_cw = R16((uint32_t)(c->esp + 0x34u)); fpu_sync_rounding(c); /* fldcw word ptr [esp + 0x34] */
L_00b28895:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x3cu))); /* mov eax, dword ptr [esp + 0x3c] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, RF80((uint32_t)(c->esp + 0x1cu))); /* fld xword ptr [esp + 0x1c] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4300u))); /* and eax, 0x4300 */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x1cu)); /* sub esp, 0x1c */
    guest_trap(c, 0x00b288abu, "unsupported: fnstenv [esp]"); /* fnstenv [esp] */
    { uint32_t a_ = (uint32_t)(c->esp + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0xbcffu)))); } /* and dword ptr [esp + 4], 0xbcff */
    { uint32_t a_ = (uint32_t)(c->esp + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->eax)))); } /* or dword ptr [esp + 4], eax */
    guest_trap(c, 0x00b288bau, "unsupported: fldenv [esp]"); /* fldenv [esp] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
L_00b288c0:;
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_00b2898b(CPU *c) { /* FUN_1000898b */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x48u)); /* sub esp, 0x48 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x480u; PUSH32(c, v_); } /* push 0x480 */
    PUSH32(c, 0x00b2899eu); f_00b26c9a(c); /* call 0xb26c9a */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_00b289ad; /* jne 0xb289ad */
    { uint32_t v_ = 0x1bu; PUSH32(c, v_); } /* push 0x1b */
    PUSH32(c, 0x00b289acu); f_00b25c98(c); /* call 0xb25c98 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b289ad:;
    W32((uint32_t)(0xb33a40u), (uint32_t)(c->esi)); /* mov dword ptr [0x10013a40], esi */
    W32((uint32_t)(0xb33b40u), (uint32_t)((uint32_t)0x20u)); /* mov dword ptr [0x10013b40], 0x20 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x480u)); /* lea eax, [esi + 0x480] */
L_00b289c3:;
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if (!c->cf) goto L_00b289e5; /* jae 0xb289e5 */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [esi + 4], 0 */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [esi], 0xffffffff */
    { uint32_t a_ = (uint32_t)(c->esi + 0x8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi + 8], 0 */
    W8((uint32_t)(c->esi + 0x5u), (uint8_t)((uint8_t)0xau)); /* mov byte ptr [esi + 5], 0xa */
    c->eax = (uint32_t)(R32((uint32_t)(0xb33a40u))); /* mov eax, dword ptr [0x10013a40] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x24u)); /* add esi, 0x24 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x480u)); /* add eax, 0x480 */
    goto L_00b289c3; /* jmp 0xb289c3 */
L_00b289e5:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffb8u)); /* lea eax, [ebp - 0x48] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0xb2e070u)); PUSH32(c, 0x00b289efu); call_indirect(c, t_); } /* call dword ptr [0x1000e070] */
    (void)sub16(c, R16((uint32_t)(c->ebp + 0xffffffeau)), (uint16_t)0x0u); /* cmp word ptr [ebp - 0x16], 0 */
    if (c->zf) goto L_00b28acb; /* je 0xb28acb */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b28acb; /* je 0xb28acb */
    c->edi = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edi, dword ptr [eax] */
    c->ebx = (uint32_t)((uint32_t)(c->eax + 0x4u)); /* lea ebx, [eax + 4] */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->edi)); /* lea eax, [ebx + edi] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->eax = (uint32_t)((uint32_t)0x800u); /* mov eax, 0x800 */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if ((c->sf != c->of)) goto L_00b28a1b; /* jl 0xb28a1b */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
L_00b28a1b:;
    (void)sub32(c, R32((uint32_t)(0xb33b40u)), c->edi); /* cmp dword ptr [0x10013b40], edi */
    if ((c->sf == c->of)) goto L_00b28a79; /* jge 0xb28a79 */
    c->esi = (uint32_t)((uint32_t)0xb33a44u); /* mov esi, 0x10013a44 */
L_00b28a28:;
    { uint32_t v_ = 0x480u; PUSH32(c, v_); } /* push 0x480 */
    PUSH32(c, 0x00b28a32u); f_00b26c9a(c); /* call 0xb26c9a */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00b28a73; /* je 0xb28a73 */
    { uint32_t a_ = (uint32_t)(0xb33b40u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x20u))); } /* add dword ptr [0x10013b40], 0x20 */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x480u)); /* lea ecx, [eax + 0x480] */
L_00b28a46:;
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->cf) goto L_00b28a66; /* jae 0xb28a66 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax + 4], 0 */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [eax], 0xffffffff */
    { uint32_t a_ = (uint32_t)(c->eax + 0x8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [eax + 8], 0 */
    W8((uint32_t)(c->eax + 0x5u), (uint8_t)((uint8_t)0xau)); /* mov byte ptr [eax + 5], 0xa */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x24u)); /* add eax, 0x24 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x480u)); /* add ecx, 0x480 */
    goto L_00b28a46; /* jmp 0xb28a46 */
L_00b28a66:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, R32((uint32_t)(0xb33b40u)), c->edi); /* cmp dword ptr [0x10013b40], edi */
    if ((c->sf != c->of)) goto L_00b28a28; /* jl 0xb28a28 */
    goto L_00b28a79; /* jmp 0xb28a79 */
L_00b28a73:;
    c->edi = (uint32_t)(R32((uint32_t)(0xb33b40u))); /* mov edi, dword ptr [0x10013b40] */
L_00b28a79:;
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if ((c->zf || c->sf != c->of)) goto L_00b28acb; /* jle 0xb28acb */
L_00b28a7f:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    (void)sub32(c, c->ecx, (uint32_t)0xffffffffu); /* cmp ecx, -1 */
    if (c->zf) goto L_00b28ac1; /* je 0xb28ac1 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebx))); /* mov al, byte ptr [ebx] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    if (c->zf) goto L_00b28ac1; /* je 0xb28ac1 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x8u)); /* test al, 8 */
    if (!c->zf) goto L_00b28a9e; /* jne 0xb28a9e */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t t_ = R32((uint32_t)(0xb2e06cu)); PUSH32(c, 0x00b28a9au); call_indirect(c, t_); } /* call dword ptr [0x1000e06c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b28ac1; /* je 0xb28ac1 */
L_00b28a9e:;
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 5)); /* sar ecx, 5 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1fu))); /* and eax, 0x1f */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx * 4 + 0xb33a40u))); /* mov ecx, dword ptr [ecx*4 + 0x10013a40] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 8)); /* lea eax, [eax + eax*8] */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->eax * 4)); /* lea eax, [ecx + eax*4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov ecx, dword ptr [ecx] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebx))); /* mov cl, byte ptr [ebx] */
    W8((uint32_t)(c->eax + 0x4u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax + 4], cl */
L_00b28ac1:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x4u))); } /* add dword ptr [ebp - 4], 4 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if ((c->sf != c->of)) goto L_00b28a7f; /* jl 0xb28a7f */
L_00b28acb:;
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
L_00b28acd:;
    c->ecx = (uint32_t)(R32((uint32_t)(0xb33a40u))); /* mov ecx, dword ptr [0x10013a40] */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->ebx * 8)); /* lea eax, [ebx + ebx*8] */
    (void)sub32(c, R32((uint32_t)(c->ecx + c->eax * 4)), (uint32_t)0xffffffffu); /* cmp dword ptr [ecx + eax*4], -1 */
    c->esi = (uint32_t)((uint32_t)(c->ecx + c->eax * 4)); /* lea esi, [ecx + eax*4] */
    if (!c->zf) goto L_00b28b2c; /* jne 0xb28b2c */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    W8((uint32_t)(c->esi + 0x4u), (uint8_t)((uint8_t)0x81u)); /* mov byte ptr [esi + 4], 0x81 */
    if (!c->zf) goto L_00b28aec; /* jne 0xb28aec */
    { uint32_t v_ = 0xfffffff6u; PUSH32(c, v_); } /* push -0xa */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_00b28af6; /* jmp 0xb28af6 */
L_00b28aec:;
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xfffffff5u)); /* add eax, -0xb */
L_00b28af6:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0xb2e068u)); PUSH32(c, 0x00b28afdu); call_indirect(c, t_); } /* call dword ptr [0x1000e068] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)sub32(c, c->edi, (uint32_t)0xffffffffu); /* cmp edi, -1 */
    if (c->zf) goto L_00b28b1b; /* je 0xb28b1b */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0xb2e06cu)); PUSH32(c, 0x00b28b0bu); call_indirect(c, t_); } /* call dword ptr [0x1000e06c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b28b1b; /* je 0xb28b1b */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xffu))); /* and eax, 0xff */
    W32((uint32_t)(c->esi), (uint32_t)(c->edi)); /* mov dword ptr [esi], edi */
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00b28b21; /* jne 0xb28b21 */
L_00b28b1b:;
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x40u)))); } /* or byte ptr [esi + 4], 0x40 */
    goto L_00b28b30; /* jmp 0xb28b30 */
L_00b28b21:;
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_00b28b30; /* jne 0xb28b30 */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x8u)))); } /* or byte ptr [esi + 4], 8 */
    goto L_00b28b30; /* jmp 0xb28b30 */
L_00b28b2c:;
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x80u)))); } /* or byte ptr [esi + 4], 0x80 */
L_00b28b30:;
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    (void)sub32(c, c->ebx, (uint32_t)0x3u); /* cmp ebx, 3 */
    if ((c->sf != c->of)) goto L_00b28acd; /* jl 0xb28acd */
    { uint32_t v_ = R32((uint32_t)(0xb33b40u)); PUSH32(c, v_); } /* push dword ptr [0x10013b40] */
    { uint32_t t_ = R32((uint32_t)(0xb2e064u)); PUSH32(c, 0x00b28b42u); call_indirect(c, t_); } /* call dword ptr [0x1000e064] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b28b47(CPU *c) { /* FUN_10008b47 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)((uint32_t)0xb33a40u); /* mov esi, 0x10013a40 */
L_00b28b4f:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b28b8c; /* je 0xb28b8c */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x480u)); /* add eax, 0x480 */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (!c->cf) goto L_00b28b81; /* jae 0xb28b81 */
    c->ebx = (uint32_t)((uint32_t)(c->edi + 0xcu)); /* lea ebx, [edi + 0xc] */
L_00b28b63:;
    (void)sub32(c, R32((uint32_t)(c->ebx + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebx - 4], 0 */
    if (c->zf) goto L_00b28b70; /* je 0xb28b70 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(0xb2e050u)); PUSH32(c, 0x00b28b70u); call_indirect(c, t_); } /* call dword ptr [0x1000e050] */
L_00b28b70:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x24u)); /* add edi, 0x24 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x480u)); /* add eax, 0x480 */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x24u)); /* add ebx, 0x24 */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_00b28b63; /* jb 0xb28b63 */
L_00b28b81:;
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    PUSH32(c, 0x00b28b88u); f_00b275db(c); /* call 0xb275db */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi], 0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b28b8c:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, c->esi, (uint32_t)0xb33b40u); /* cmp esi, 0x10013b40 */
    if ((c->sf != c->of)) goto L_00b28b4f; /* jl 0xb28b4f */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00b28b9b(CPU *c) { /* FUN_10008b9b */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, R32((uint32_t)(0xb33b48u)), c->ebx); /* cmp dword ptr [0x10013b48], ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00b28bad; /* jne 0xb28bad */
    PUSH32(c, 0x00b28badu); f_00b2c259(c); /* call 0xb2c259 */
L_00b28bad:;
    c->esi = (uint32_t)(R32((uint32_t)(0xb3347cu))); /* mov esi, dword ptr [0x1001347c] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
L_00b28bb5:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_00b28bcd; /* je 0xb28bcd */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x3du); /* cmp al, 0x3d */
    if (c->zf) goto L_00b28bc0; /* je 0xb28bc0 */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
L_00b28bc0:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b28bc6u); f_00b26e60(c); /* call 0xb26e60 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esi = (uint32_t)((uint32_t)(c->esi + c->eax + 0x1u)); /* lea esi, [esi + eax + 1] */
    goto L_00b28bb5; /* jmp 0xb28bb5 */
L_00b28bcd:;
    c->eax = (uint32_t)((uint32_t)(c->edi * 4 + 0x4u)); /* lea eax, [edi*4 + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b28bdau); f_00b26c9a(c); /* call 0xb26c9a */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    W32((uint32_t)(0xb334acu), (uint32_t)(c->esi)); /* mov dword ptr [0x100134ac], esi */
    if (!c->zf) goto L_00b28bef; /* jne 0xb28bef */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b28beeu); f_00b25c98(c); /* call 0xb25c98 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b28bef:;
    c->edi = (uint32_t)(R32((uint32_t)(0xb3347cu))); /* mov edi, dword ptr [0x1001347c] */
    (void)sub8(c, R8((uint32_t)(c->edi)), ((uint8_t)c->ebx)); /* cmp byte ptr [edi], bl */
    if (c->zf) goto L_00b28c32; /* je 0xb28c32 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
L_00b28bfa:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b28c00u); f_00b26e60(c); /* call 0xb26e60 */
    c->ebp = (uint32_t)(c->eax); /* mov ebp, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ebp = (uint32_t)(inc32(c, c->ebp)); /* inc ebp */
    (void)sub8(c, R8((uint32_t)(c->edi)), (uint8_t)0x3du); /* cmp byte ptr [edi], 0x3d */
    if (c->zf) goto L_00b28c2b; /* je 0xb28c2b */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x00b28c0fu); f_00b26c9a(c); /* call 0xb26c9a */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    if (!c->zf) goto L_00b28c1e; /* jne 0xb28c1e */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b28c1du); f_00b25c98(c); /* call 0xb25c98 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b28c1e:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    PUSH32(c, 0x00b28c26u); f_00b2bc60(c); /* call 0xb2bc60 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b28c2b:;
    c->edi = (uint32_t)(add32(c, c->edi, c->ebp)); /* add edi, ebp */
    (void)sub8(c, R8((uint32_t)(c->edi)), ((uint8_t)c->ebx)); /* cmp byte ptr [edi], bl */
    if (!c->zf) goto L_00b28bfa; /* jne 0xb28bfa */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
L_00b28c32:;
    { uint32_t v_ = R32((uint32_t)(0xb3347cu)); PUSH32(c, v_); } /* push dword ptr [0x1001347c] */
    PUSH32(c, 0x00b28c3du); f_00b275db(c); /* call 0xb275db */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(0xb3347cu), (uint32_t)(c->ebx)); /* mov dword ptr [0x1001347c], ebx */
    W32((uint32_t)(c->esi), (uint32_t)(c->ebx)); /* mov dword ptr [esi], ebx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0xb33b44u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x10013b44], 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00b28c54(CPU *c) { /* FUN_10008c54 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, R32((uint32_t)(0xb33b48u)), c->ebx); /* cmp dword ptr [0x10013b48], ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00b28c6b; /* jne 0xb28c6b */
    PUSH32(c, 0x00b28c6bu); f_00b2c259(c); /* call 0xb2c259 */
L_00b28c6b:;
    c->esi = (uint32_t)((uint32_t)0xb33534u); /* mov esi, 0x10013534 */
    { uint32_t v_ = 0x104u; PUSH32(c, v_); } /* push 0x104 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(0xb2e074u)); PUSH32(c, 0x00b28c7du); call_indirect(c, t_); } /* call dword ptr [0x1000e074] */
    c->eax = (uint32_t)(R32((uint32_t)(0xb33b54u))); /* mov eax, dword ptr [0x10013b54] */
    W32((uint32_t)(0xb334bcu), (uint32_t)(c->esi)); /* mov dword ptr [0x100134bc], esi */
    c->edi = (uint32_t)(c->esi); /* mov edi, esi */
    (void)sub8(c, R8((uint32_t)(c->eax)), ((uint8_t)c->ebx)); /* cmp byte ptr [eax], bl */
    if (c->zf) goto L_00b28c90; /* je 0xb28c90 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
L_00b28c90:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b28ca0u); f_00b28ced(c); /* call 0xb28ced */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->ecx * 4)); /* lea eax, [eax + ecx*4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b28cafu); f_00b26c9a(c); /* call 0xb26c9a */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (!c->zf) goto L_00b28cc0; /* jne 0xb28cc0 */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    PUSH32(c, 0x00b28cbfu); f_00b25c98(c); /* call 0xb25c98 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b28cc0:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->eax * 4)); /* lea eax, [esi + eax*4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b28cd6u); f_00b28ced(c); /* call 0xb28ced */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    W32((uint32_t)(0xb334a4u), (uint32_t)(c->esi)); /* mov dword ptr [0x100134a4], esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0xb334a0u), (uint32_t)(c->eax)); /* mov dword ptr [0x100134a0], eax */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b28ced(CPU *c) { /* FUN_10008ced */
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
    if (c->zf) goto L_00b28d17; /* je 0xb28d17 */
    W32((uint32_t)(c->edi), (uint32_t)(c->esi)); /* mov dword ptr [edi], esi */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 0xc], edi */
L_00b28d17:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x22u); /* cmp byte ptr [eax], 0x22 */
    if (!c->zf) goto L_00b28d60; /* jne 0xb28d60 */
L_00b28d1c:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1u))); /* mov dl, byte ptr [eax + 1] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x22u); /* cmp dl, 0x22 */
    if (c->zf) goto L_00b28d4e; /* je 0xb28d4e */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00b28d4e; /* je 0xb28d4e */
    c->edx = (uint32_t)((uint32_t)((uint8_t)c->edx)); /* movzx edx, dl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edx + 0xb33901u)) & (uint8_t)0x4u)); /* test byte ptr [edx + 0x10013901], 4 */
    if (c->zf) goto L_00b28d41; /* je 0xb28d41 */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00b28d41; /* je 0xb28d41 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
L_00b28d41:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00b28d1c; /* je 0xb28d1c */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    goto L_00b28d1c; /* jmp 0xb28d1c */
L_00b28d4e:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00b28d58; /* je 0xb28d58 */
    { uint32_t a_ = (uint32_t)(c->esi); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [esi], 0 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_00b28d58:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x22u); /* cmp byte ptr [eax], 0x22 */
    if (!c->zf) goto L_00b28da3; /* jne 0xb28da3 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_00b28da3; /* jmp 0xb28da3 */
L_00b28d60:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00b28d6b; /* je 0xb28d6b */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_00b28d6b:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ebx = (uint32_t)((uint32_t)((uint8_t)c->edx)); /* movzx ebx, dl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebx + 0xb33901u)) & (uint8_t)0x4u)); /* test byte ptr [ebx + 0x10013901], 4 */
    if (c->zf) goto L_00b28d86; /* je 0xb28d86 */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00b28d85; /* je 0xb28d85 */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov bl, byte ptr [eax] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [esi], bl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_00b28d85:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
L_00b28d86:;
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x20u); /* cmp dl, 0x20 */
    if (c->zf) goto L_00b28d94; /* je 0xb28d94 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00b28d98; /* je 0xb28d98 */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x9u); /* cmp dl, 9 */
    if (!c->zf) goto L_00b28d60; /* jne 0xb28d60 */
L_00b28d94:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (!c->zf) goto L_00b28d9b; /* jne 0xb28d9b */
L_00b28d98:;
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    goto L_00b28da3; /* jmp 0xb28da3 */
L_00b28d9b:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00b28da3; /* je 0xb28da3 */
    { uint32_t a_ = (uint32_t)(c->esi + 0xffffffffu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [esi - 1], 0 */
L_00b28da3:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0x18u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp + 0x18], 0 */
L_00b28da7:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (c->zf) goto L_00b28e90; /* je 0xb28e90 */
L_00b28db0:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x20u); /* cmp dl, 0x20 */
    if (c->zf) goto L_00b28dbc; /* je 0xb28dbc */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x9u); /* cmp dl, 9 */
    if (!c->zf) goto L_00b28dbf; /* jne 0xb28dbf */
L_00b28dbc:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_00b28db0; /* jmp 0xb28db0 */
L_00b28dbf:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (c->zf) goto L_00b28e90; /* je 0xb28e90 */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00b28dd4; /* je 0xb28dd4 */
    W32((uint32_t)(c->edi), (uint32_t)(c->esi)); /* mov dword ptr [edi], esi */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 0xc], edi */
L_00b28dd4:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov edx, dword ptr [ebp + 0x14] */
    { uint32_t a_ = (uint32_t)(c->edx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [edx] */
L_00b28dd9:;
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp + 8], 1 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
L_00b28de2:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x5cu); /* cmp byte ptr [eax], 0x5c */
    if (!c->zf) goto L_00b28deb; /* jne 0xb28deb */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    goto L_00b28de2; /* jmp 0xb28de2 */
L_00b28deb:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x22u); /* cmp byte ptr [eax], 0x22 */
    if (!c->zf) goto L_00b28e1c; /* jne 0xb28e1c */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x1u)); /* test bl, 1 */
    if (!c->zf) goto L_00b28e1a; /* jne 0xb28e1a */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x18u)), c->edi); /* cmp dword ptr [ebp + 0x18], edi */
    if (c->zf) goto L_00b28e09; /* je 0xb28e09 */
    (void)sub8(c, R8((uint32_t)(c->eax + 0x1u)), (uint8_t)0x22u); /* cmp byte ptr [eax + 1], 0x22 */
    c->edx = (uint32_t)((uint32_t)(c->eax + 0x1u)); /* lea edx, [eax + 1] */
    if (!c->zf) goto L_00b28e09; /* jne 0xb28e09 */
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    goto L_00b28e0c; /* jmp 0xb28e0c */
L_00b28e09:;
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 8], edi */
L_00b28e0c:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x18u)), c->edx); /* cmp dword ptr [ebp + 0x18], edx */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete dl */
    W32((uint32_t)(c->ebp + 0x18u), (uint32_t)(c->edx)); /* mov dword ptr [ebp + 0x18], edx */
L_00b28e1a:;
    c->ebx = (uint32_t)(shr32(c, c->ebx, 1)); /* shr ebx, 1 */
L_00b28e1c:;
    c->edx = (uint32_t)(c->ebx); /* mov edx, ebx */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_00b28e31; /* je 0xb28e31 */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
L_00b28e24:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00b28e2c; /* je 0xb28e2c */
    W8((uint32_t)(c->esi), (uint8_t)((uint8_t)0x5cu)); /* mov byte ptr [esi], 0x5c */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_00b28e2c:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->zf) goto L_00b28e24; /* jne 0xb28e24 */
L_00b28e31:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00b28e81; /* je 0xb28e81 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x18u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x18], 0 */
    if (!c->zf) goto L_00b28e47; /* jne 0xb28e47 */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x20u); /* cmp dl, 0x20 */
    if (c->zf) goto L_00b28e81; /* je 0xb28e81 */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x9u); /* cmp dl, 9 */
    if (c->zf) goto L_00b28e81; /* je 0xb28e81 */
L_00b28e47:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    if (c->zf) goto L_00b28e7b; /* je 0xb28e7b */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00b28e6a; /* je 0xb28e6a */
    c->ebx = (uint32_t)((uint32_t)((uint8_t)c->edx)); /* movzx ebx, dl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebx + 0xb33901u)) & (uint8_t)0x4u)); /* test byte ptr [ebx + 0x10013901], 4 */
    if (c->zf) goto L_00b28e63; /* je 0xb28e63 */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
L_00b28e63:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    goto L_00b28e79; /* jmp 0xb28e79 */
L_00b28e6a:;
    c->edx = (uint32_t)((uint32_t)((uint8_t)c->edx)); /* movzx edx, dl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edx + 0xb33901u)) & (uint8_t)0x4u)); /* test byte ptr [edx + 0x10013901], 4 */
    if (c->zf) goto L_00b28e79; /* je 0xb28e79 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
L_00b28e79:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
L_00b28e7b:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_00b28dd9; /* jmp 0xb28dd9 */
L_00b28e81:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00b28e89; /* je 0xb28e89 */
    { uint32_t a_ = (uint32_t)(c->esi); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [esi], 0 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_00b28e89:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    goto L_00b28da7; /* jmp 0xb28da7 */
L_00b28e90:;
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00b28e97; /* je 0xb28e97 */
    { uint32_t a_ = (uint32_t)(c->edi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [edi], 0 */
L_00b28e97:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [eax] */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00b28ea1(CPU *c) { /* FUN_10008ea1 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(0xb33638u))); /* mov eax, dword ptr [0x10013638] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(0xb2e088u))); /* mov ebp, dword ptr [0x1000e088] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (!c->zf) goto L_00b28eef; /* jne 0xb28eef */
    { uint32_t t_ = c->ebp; PUSH32(c, 0x00b28ebeu); call_indirect(c, t_); } /* call ebp */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (c->zf) goto L_00b28ed0; /* je 0xb28ed0 */
    W32((uint32_t)(0xb33638u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x10013638], 1 */
    goto L_00b28ef8; /* jmp 0xb28ef8 */
L_00b28ed0:;
    { uint32_t t_ = R32((uint32_t)(0xb2e084u)); PUSH32(c, 0x00b28ed6u); call_indirect(c, t_); } /* call dword ptr [0x1000e084] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    if (c->zf) goto L_00b28fca; /* je 0xb28fca */
    W32((uint32_t)(0xb33638u), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [0x10013638], 2 */
    goto L_00b28f7e; /* jmp 0xb28f7e */
L_00b28eef:;
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_00b28f79; /* jne 0xb28f79 */
L_00b28ef8:;
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (!c->zf) goto L_00b28f08; /* jne 0xb28f08 */
    { uint32_t t_ = c->ebp; PUSH32(c, 0x00b28efeu); call_indirect(c, t_); } /* call ebp */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (c->zf) goto L_00b28fca; /* je 0xb28fca */
L_00b28f08:;
    (void)sub16(c, R16((uint32_t)(c->esi)), ((uint16_t)c->ebx)); /* cmp word ptr [esi], bx */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    if (c->zf) goto L_00b28f1d; /* je 0xb28f1d */
L_00b28f0f:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub16(c, R16((uint32_t)(c->eax)), ((uint16_t)c->ebx)); /* cmp word ptr [eax], bx */
    if (!c->zf) goto L_00b28f0f; /* jne 0xb28f0f */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub16(c, R16((uint32_t)(c->eax)), ((uint16_t)c->ebx)); /* cmp word ptr [eax], bx */
    if (!c->zf) goto L_00b28f0f; /* jne 0xb28f0f */
L_00b28f1d:;
    c->eax = (uint32_t)(sub32(c, c->eax, c->esi)); /* sub eax, esi */
    c->edi = (uint32_t)(R32((uint32_t)(0xb2e080u))); /* mov edi, dword ptr [0x1000e080] */
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
    { uint32_t t_ = c->edi; PUSH32(c, 0x00b28f36u); call_indirect(c, t_); } /* call edi */
    c->ebp = (uint32_t)(c->eax); /* mov ebp, eax */
    (void)sub32(c, c->ebp, c->ebx); /* cmp ebp, ebx */
    if (c->zf) goto L_00b28f6e; /* je 0xb28f6e */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x00b28f42u); f_00b26c9a(c); /* call 0xb26c9a */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    if (c->zf) goto L_00b28f6e; /* je 0xb28f6e */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x24u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x24] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00b28f58u); call_indirect(c, t_); } /* call edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b28f6a; /* jne 0xb28f6a */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    PUSH32(c, 0x00b28f65u); f_00b275db(c); /* call 0xb275db */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x10], ebx */
L_00b28f6a:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ebx, dword ptr [esp + 0x10] */
L_00b28f6e:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(0xb2e07cu)); PUSH32(c, 0x00b28f75u); call_indirect(c, t_); } /* call dword ptr [0x1000e07c] */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    goto L_00b28fcc; /* jmp 0xb28fcc */
L_00b28f79:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00b28fca; /* jne 0xb28fca */
L_00b28f7e:;
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    if (!c->zf) goto L_00b28f8e; /* jne 0xb28f8e */
    { uint32_t t_ = R32((uint32_t)(0xb2e084u)); PUSH32(c, 0x00b28f88u); call_indirect(c, t_); } /* call dword ptr [0x1000e084] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    if (c->zf) goto L_00b28fca; /* je 0xb28fca */
L_00b28f8e:;
    (void)sub8(c, R8((uint32_t)(c->edi)), ((uint8_t)c->ebx)); /* cmp byte ptr [edi], bl */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    if (c->zf) goto L_00b28f9e; /* je 0xb28f9e */
L_00b28f94:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), ((uint8_t)c->ebx)); /* cmp byte ptr [eax], bl */
    if (!c->zf) goto L_00b28f94; /* jne 0xb28f94 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), ((uint8_t)c->ebx)); /* cmp byte ptr [eax], bl */
    if (!c->zf) goto L_00b28f94; /* jne 0xb28f94 */
L_00b28f9e:;
    c->eax = (uint32_t)(sub32(c, c->eax, c->edi)); /* sub eax, edi */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ebp = (uint32_t)(c->eax); /* mov ebp, eax */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x00b28fa9u); f_00b26c9a(c); /* call 0xb26c9a */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (!c->zf) goto L_00b28fb4; /* jne 0xb28fb4 */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    goto L_00b28fbf; /* jmp 0xb28fbf */
L_00b28fb4:;
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b28fbcu); f_00b2aaf0(c); /* call 0xb2aaf0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_00b28fbf:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0xb2e078u)); PUSH32(c, 0x00b28fc6u); call_indirect(c, t_); } /* call dword ptr [0x1000e078] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    goto L_00b28fcc; /* jmp 0xb28fcc */
L_00b28fca:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00b28fcc:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00b28fd3(CPU *c) { /* FUN_10008fd3 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi], 0 */
    { uint32_t t_ = R32((uint32_t)(0xb2e048u)); PUSH32(c, 0x00b28fe3u); call_indirect(c, t_); } /* call dword ptr [0x1000e048] */
    (void)sub16(c, R16((uint32_t)(c->eax)), (uint16_t)0x5a4du); /* cmp word ptr [eax], 0x5a4d */
    if (!c->zf) goto L_00b28ffe; /* jne 0xb28ffe */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x3cu))); /* mov ecx, dword ptr [eax + 0x3c] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00b28ffe; /* je 0xb28ffe */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1au))); /* mov cl, byte ptr [eax + 0x1a] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esi], cl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1bu))); /* mov al, byte ptr [eax + 0x1b] */
    W8((uint32_t)(c->esi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [esi + 1], al */
L_00b28ffe:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b29000(CPU *c) { /* FUN_10009000 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->eax = (uint32_t)((uint32_t)0x122cu); /* mov eax, 0x122c */
    PUSH32(c, 0x00b2900du); f_00b2c630(c); /* call 0xb2c630 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff68u)); /* lea eax, [ebp - 0x98] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(c->ebp + 0xffffff68u), (uint32_t)((uint32_t)0x94u)); /* mov dword ptr [ebp - 0x98], 0x94 */
    { uint32_t t_ = R32((uint32_t)(0xb2e090u)); PUSH32(c, 0x00b29025u); call_indirect(c, t_); } /* call dword ptr [0x1000e090] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b29043; /* je 0xb29043 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffff78u)), (uint32_t)0x2u); /* cmp dword ptr [ebp - 0x88], 2 */
    if (!c->zf) goto L_00b29043; /* jne 0xb29043 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffff6cu)), (uint32_t)0x5u); /* cmp dword ptr [ebp - 0x94], 5 */
    if (c->cf) goto L_00b29043; /* jb 0xb29043 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_00b29145; /* jmp 0xb29145 */
L_00b29043:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffedd4u)); /* lea eax, [ebp - 0x122c] */
    { uint32_t v_ = 0x1090u; PUSH32(c, v_); } /* push 0x1090 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0xb2e418u; PUSH32(c, v_); } /* push 0x1000e418 */
    { uint32_t t_ = R32((uint32_t)(0xb2e08cu)); PUSH32(c, 0x00b2905au); call_indirect(c, t_); } /* call dword ptr [0x1000e08c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b29132; /* je 0xb29132 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffedd4u)); /* lea ecx, [ebp - 0x122c] */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xffffedd4u)), ((uint8_t)c->ebx)); /* cmp byte ptr [ebp - 0x122c], bl */
    if (c->zf) goto L_00b29085; /* je 0xb29085 */
L_00b29072:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov al, byte ptr [ecx] */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x61u); /* cmp al, 0x61 */
    if ((c->sf != c->of)) goto L_00b29080; /* jl 0xb29080 */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x7au); /* cmp al, 0x7a */
    if ((!c->zf && c->sf == c->of)) goto L_00b29080; /* jg 0xb29080 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sub8(c, ((uint8_t)c->eax), (uint8_t)0x20u)); /* sub al, 0x20 */
    W8((uint32_t)(c->ecx), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ecx], al */
L_00b29080:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub8(c, R8((uint32_t)(c->ecx)), ((uint8_t)c->ebx)); /* cmp byte ptr [ecx], bl */
    if (!c->zf) goto L_00b29072; /* jne 0xb29072 */
L_00b29085:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffedd4u)); /* lea eax, [ebp - 0x122c] */
    { uint32_t v_ = 0x16u; PUSH32(c, v_); } /* push 0x16 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0xb2e400u; PUSH32(c, v_); } /* push 0x1000e400 */
    PUSH32(c, 0x00b29098u); f_00b2c5f0(c); /* call 0xb2c5f0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b290a7; /* jne 0xb290a7 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffedd4u)); /* lea eax, [ebp - 0x122c] */
    goto L_00b290f0; /* jmp 0xb290f0 */
L_00b290a7:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe64u)); /* lea eax, [ebp - 0x19c] */
    { uint32_t v_ = 0x104u; PUSH32(c, v_); } /* push 0x104 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(0xb2e074u)); PUSH32(c, 0x00b290bau); call_indirect(c, t_); } /* call dword ptr [0x1000e074] */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xfffffe64u)), ((uint8_t)c->ebx)); /* cmp byte ptr [ebp - 0x19c], bl */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffe64u)); /* lea ecx, [ebp - 0x19c] */
    if (c->zf) goto L_00b290db; /* je 0xb290db */
L_00b290c8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov al, byte ptr [ecx] */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x61u); /* cmp al, 0x61 */
    if ((c->sf != c->of)) goto L_00b290d6; /* jl 0xb290d6 */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x7au); /* cmp al, 0x7a */
    if ((!c->zf && c->sf == c->of)) goto L_00b290d6; /* jg 0xb290d6 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sub8(c, ((uint8_t)c->eax), (uint8_t)0x20u)); /* sub al, 0x20 */
    W8((uint32_t)(c->ecx), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ecx], al */
L_00b290d6:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub8(c, R8((uint32_t)(c->ecx)), ((uint8_t)c->ebx)); /* cmp byte ptr [ecx], bl */
    if (!c->zf) goto L_00b290c8; /* jne 0xb290c8 */
L_00b290db:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe64u)); /* lea eax, [ebp - 0x19c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffedd4u)); /* lea eax, [ebp - 0x122c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b290eeu); f_00b2c570(c); /* call 0xb2c570 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b290f0:;
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_00b29132; /* je 0xb29132 */
    { uint32_t v_ = 0x2cu; PUSH32(c, v_); } /* push 0x2c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b290fcu); f_00b2c4b0(c); /* call 0xb2c4b0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00b29132; /* je 0xb29132 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), ((uint8_t)c->ebx)); /* cmp byte ptr [eax], bl */
    if (c->zf) goto L_00b29117; /* je 0xb29117 */
L_00b29109:;
    (void)sub8(c, R8((uint32_t)(c->ecx)), (uint8_t)0x3bu); /* cmp byte ptr [ecx], 0x3b */
    if (!c->zf) goto L_00b29112; /* jne 0xb29112 */
    W8((uint32_t)(c->ecx), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ecx], bl */
    goto L_00b29113; /* jmp 0xb29113 */
L_00b29112:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
L_00b29113:;
    (void)sub8(c, R8((uint32_t)(c->ecx)), ((uint8_t)c->ebx)); /* cmp byte ptr [ecx], bl */
    if (!c->zf) goto L_00b29109; /* jne 0xb29109 */
L_00b29117:;
    { uint32_t v_ = 0xau; PUSH32(c, v_); } /* push 0xa */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b29120u); f_00b2c275(c); /* call 0xb2c275 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (c->zf) goto L_00b29145; /* je 0xb29145 */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (c->zf) goto L_00b29145; /* je 0xb29145 */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_00b29145; /* je 0xb29145 */
L_00b29132:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2913bu); f_00b28fd3(c); /* call 0xb28fd3 */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xfffffffcu)), (uint8_t)0x6u); /* cmp byte ptr [ebp - 4], 6 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x3u)); /* add eax, 3 */
L_00b29145:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b29148(CPU *c) { /* FUN_10009148 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    (void)sub32(c, R32((uint32_t)(c->esp + 0x8u)), c->eax); /* cmp dword ptr [esp + 8], eax */
    { uint32_t v_ = 0x1000u; PUSH32(c, v_); } /* push 0x1000 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete al */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0xb2e098u)); PUSH32(c, 0x00b2915fu); call_indirect(c, t_); } /* call dword ptr [0x1000e098] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(0xb33a24u), (uint32_t)(c->eax)); /* mov dword ptr [0x10013a24], eax */
    if (c->zf) goto L_00b2919e; /* je 0xb2919e */
    PUSH32(c, 0x00b2916du); f_00b29000(c); /* call 0xb29000 */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    W32((uint32_t)(0xb33a28u), (uint32_t)(c->eax)); /* mov dword ptr [0x10013a28], eax */
    if (!c->zf) goto L_00b29184; /* jne 0xb29184 */
    { uint32_t v_ = 0x3f8u; PUSH32(c, v_); } /* push 0x3f8 */
    PUSH32(c, 0x00b29181u); f_00b298b9(c); /* call 0xb298b9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00b2918e; /* jmp 0xb2918e */
L_00b29184:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00b291a1; /* jne 0xb291a1 */
    PUSH32(c, 0x00b2918eu); f_00b2a400(c); /* call 0xb2a400 */
L_00b2918e:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b291a1; /* jne 0xb291a1 */
    { uint32_t v_ = R32((uint32_t)(0xb33a24u)); PUSH32(c, v_); } /* push dword ptr [0x10013a24] */
    { uint32_t t_ = R32((uint32_t)(0xb2e094u)); PUSH32(c, 0x00b2919eu); call_indirect(c, t_); } /* call dword ptr [0x1000e094] */
L_00b2919e:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_00b291a1:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_00b291a5(CPU *c) { /* FUN_100091a5 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0xb33a28u))); /* mov eax, dword ptr [0x10013a28] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00b29217; /* jne 0xb29217 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, R32((uint32_t)(0xb33a18u)), c->ebx); /* cmp dword ptr [0x10013a18], ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(0xb2e05cu))); /* mov ebp, dword ptr [0x1000e05c] */
    if ((c->zf || c->sf != c->of)) goto L_00b29203; /* jle 0xb29203 */
    c->eax = (uint32_t)(R32((uint32_t)(0xb33a1cu))); /* mov eax, dword ptr [0x10013a1c] */
    c->edi = (uint32_t)(R32((uint32_t)(0xb2e09cu))); /* mov edi, dword ptr [0x1000e09c] */
    c->esi = (uint32_t)((uint32_t)(c->eax + 0xcu)); /* lea esi, [eax + 0xc] */
L_00b291d1:;
    { uint32_t v_ = 0x4000u; PUSH32(c, v_); } /* push 0x4000 */
    { uint32_t v_ = 0x100000u; PUSH32(c, v_); } /* push 0x100000 */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00b291dfu); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = 0x8000u; PUSH32(c, v_); } /* push 0x8000 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00b291eau); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esi + 4] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb33a24u)); PUSH32(c, v_); } /* push dword ptr [0x10013a24] */
    { uint32_t t_ = c->ebp; PUSH32(c, 0x00b291f7u); call_indirect(c, t_); } /* call ebp */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x14u)); /* add esi, 0x14 */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    (void)sub32(c, c->ebx, R32((uint32_t)(0xb33a18u))); /* cmp ebx, dword ptr [0x10013a18] */
    if ((c->sf != c->of)) goto L_00b291d1; /* jl 0xb291d1 */
L_00b29203:;
    { uint32_t v_ = R32((uint32_t)(0xb33a1cu)); PUSH32(c, v_); } /* push dword ptr [0x10013a1c] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb33a24u)); PUSH32(c, v_); } /* push dword ptr [0x10013a24] */
    { uint32_t t_ = c->ebp; PUSH32(c, 0x00b29213u); call_indirect(c, t_); } /* call ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    goto L_00b2923e; /* jmp 0xb2923e */
L_00b29217:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00b2923e; /* jne 0xb2923e */
    c->edi = (uint32_t)((uint32_t)0xb309c8u); /* mov edi, 0x100109c8 */
    c->esi = (uint32_t)(c->edi); /* mov esi, edi */
L_00b29223:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b29238; /* je 0xb29238 */
    { uint32_t v_ = 0x8000u; PUSH32(c, v_); } /* push 0x8000 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0xb2e09cu)); PUSH32(c, 0x00b29238u); call_indirect(c, t_); } /* call dword ptr [0x1000e09c] */
L_00b29238:;
    c->esi = (uint32_t)(R32((uint32_t)(c->esi))); /* mov esi, dword ptr [esi] */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_00b29223; /* jne 0xb29223 */
L_00b2923e:;
    { uint32_t v_ = R32((uint32_t)(0xb33a24u)); PUSH32(c, v_); } /* push dword ptr [0x10013a24] */
    { uint32_t t_ = R32((uint32_t)(0xb2e094u)); PUSH32(c, 0x00b2924au); call_indirect(c, t_); } /* call dword ptr [0x1000e094] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b2924d(CPU *c) { /* FUN_1000924d */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 16; return; /* ret 0xc */
}

void f_00b29253(CPU *c) { /* FUN_10009253 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0xb33484u))); /* mov eax, dword ptr [0x10013484] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_00b2926a; /* je 0xb2926a */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b2928b; /* jne 0xb2928b */
    (void)sub32(c, R32((uint32_t)(0xb33488u)), (uint32_t)0x1u); /* cmp dword ptr [0x10013488], 1 */
    if (!c->zf) goto L_00b2928b; /* jne 0xb2928b */
L_00b2926a:;
    { uint32_t v_ = 0xfcu; PUSH32(c, v_); } /* push 0xfc */
    PUSH32(c, 0x00b29274u); f_00b2928c(c); /* call 0xb2928c */
    c->eax = (uint32_t)(R32((uint32_t)(0xb3363cu))); /* mov eax, dword ptr [0x1001363c] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b29280; /* je 0xb29280 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00b29280u); call_indirect(c, t_); } /* call eax */
L_00b29280:;
    { uint32_t v_ = 0xffu; PUSH32(c, v_); } /* push 0xff */
    PUSH32(c, 0x00b2928au); f_00b2928c(c); /* call 0xb2928c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b2928b:;
    c->esp += 4; return; /* ret  */
}

void f_00b2928c(CPU *c) { /* FUN_1000928c */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x1a4u)); /* sub esp, 0x1a4 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->eax = (uint32_t)((uint32_t)0xb308a8u); /* mov eax, 0x100108a8 */
L_00b2929f:;
    (void)sub32(c, c->edx, R32((uint32_t)(c->eax))); /* cmp edx, dword ptr [eax] */
    if (c->zf) goto L_00b292ae; /* je 0xb292ae */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->eax, (uint32_t)0xb30938u); /* cmp eax, 0x10010938 */
    if ((c->sf != c->of)) goto L_00b2929f; /* jl 0xb2929f */
L_00b292ae:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->esi = (uint32_t)(shl32(c, c->esi, 3)); /* shl esi, 3 */
    (void)sub32(c, c->edx, R32((uint32_t)(c->esi + 0xb308a8u))); /* cmp edx, dword ptr [esi + 0x100108a8] */
    if (!c->zf) goto L_00b293dc; /* jne 0xb293dc */
    c->eax = (uint32_t)(R32((uint32_t)(0xb33484u))); /* mov eax, dword ptr [0x10013484] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_00b293b6; /* je 0xb293b6 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b292df; /* jne 0xb292df */
    (void)sub32(c, R32((uint32_t)(0xb33488u)), (uint32_t)0x1u); /* cmp dword ptr [0x10013488], 1 */
    if (c->zf) goto L_00b293b6; /* je 0xb293b6 */
L_00b292df:;
    (void)sub32(c, c->edx, (uint32_t)0xfcu); /* cmp edx, 0xfc */
    if (c->zf) goto L_00b293dc; /* je 0xb293dc */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea eax, [ebp - 0x1a4] */
    { uint32_t v_ = 0x104u; PUSH32(c, v_); } /* push 0x104 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t t_ = R32((uint32_t)(0xb2e074u)); PUSH32(c, 0x00b292ffu); call_indirect(c, t_); } /* call dword ptr [0x1000e074] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b29316; /* jne 0xb29316 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea eax, [ebp - 0x1a4] */
    { uint32_t v_ = 0xb2e708u; PUSH32(c, v_); } /* push 0x1000e708 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b29314u); f_00b2bc60(c); /* call 0xb2bc60 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b29316:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea eax, [ebp - 0x1a4] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea edi, [ebp - 0x1a4] */
    PUSH32(c, 0x00b29329u); f_00b26e60(c); /* call 0xb26e60 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->eax, (uint32_t)0x3cu); /* cmp eax, 0x3c */
    if ((c->cf || c->zf)) goto L_00b29359; /* jbe 0xb29359 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea eax, [ebp - 0x1a4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2933cu); f_00b26e60(c); /* call 0xb26e60 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea eax, [ebp - 0x1a4] */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3bu)); /* sub eax, 0x3b */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t v_ = 0xb2e704u; PUSH32(c, v_); } /* push 0x1000e704 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b29356u); f_00b2c6f0(c); /* call 0xb2c6f0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_00b29359:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff60u)); /* lea eax, [ebp - 0xa0] */
    { uint32_t v_ = 0xb2e6e8u; PUSH32(c, v_); } /* push 0x1000e6e8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2936au); f_00b2bc60(c); /* call 0xb2bc60 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff60u)); /* lea eax, [ebp - 0xa0] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b29377u); f_00b2bc70(c); /* call 0xb2bc70 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff60u)); /* lea eax, [ebp - 0xa0] */
    { uint32_t v_ = 0xb2e6e4u; PUSH32(c, v_); } /* push 0x1000e6e4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b29388u); f_00b2bc70(c); /* call 0xb2bc70 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0xb308acu)); PUSH32(c, v_); } /* push dword ptr [esi + 0x100108ac] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff60u)); /* lea eax, [ebp - 0xa0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2939au); f_00b2bc70(c); /* call 0xb2bc70 */
    { uint32_t v_ = 0x12010u; PUSH32(c, v_); } /* push 0x12010 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff60u)); /* lea eax, [ebp - 0xa0] */
    { uint32_t v_ = 0xb2e6bcu; PUSH32(c, v_); } /* push 0x1000e6bc */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b293b0u); f_00b2c65f(c); /* call 0xb2c65f */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    goto L_00b293dc; /* jmp 0xb293dc */
L_00b293b6:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x8u)); /* lea eax, [ebp + 8] */
    c->esi = (uint32_t)((uint32_t)(c->esi + 0xb308acu)); /* lea esi, [esi + 0x100108ac] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    PUSH32(c, 0x00b293c9u); f_00b26e60(c); /* call 0xb26e60 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    { uint32_t v_ = 0xfffffff4u; PUSH32(c, v_); } /* push -0xc */
    { uint32_t t_ = R32((uint32_t)(0xb2e068u)); PUSH32(c, 0x00b293d5u); call_indirect(c, t_); } /* call dword ptr [0x1000e068] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0xb2e0a0u)); PUSH32(c, 0x00b293dcu); call_indirect(c, t_); } /* call dword ptr [0x1000e0a0] */
L_00b293dc:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b293df(CPU *c) { /* FUN_100093df */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    { uint32_t t_ = R32((uint32_t)(0xb2e0a4u)); PUSH32(c, 0x00b293f1u); call_indirect(c, t_); } /* call dword ptr [0x1000e0a4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b293f7; /* je 0xb293f7 */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_00b293f7:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b293fb(CPU *c) { /* FUN_100093fb */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    { uint32_t t_ = R32((uint32_t)(0xb2e0a8u)); PUSH32(c, 0x00b2940du); call_indirect(c, t_); } /* call dword ptr [0x1000e0a8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b29413; /* je 0xb29413 */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_00b29413:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b29417(CPU *c) { /* FUN_10009417 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    { uint32_t t_ = R32((uint32_t)(0xb2e0acu)); PUSH32(c, 0x00b29425u); call_indirect(c, t_); } /* call dword ptr [0x1000e0ac] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b2942b; /* je 0xb2942b */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_00b2942b:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b29430(CPU *c) { /* FUN_10009430 */
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
    if ((c->cf || c->zf)) goto L_00b29450; /* jbe 0xb29450 */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_00b295c8; /* jb 0xb295c8 */
L_00b29450:;
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x3u)); /* test edi, 3 */
    if (!c->zf) goto L_00b2946c; /* jne 0xb2946c */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u))); /* and edx, 3 */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) goto L_00b2948c; /* jb 0xb2948c */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb29578u)); switch (t_) { case 0x00b29588u: goto L_00b29588; case 0x00b29590u: goto L_00b29590; case 0x00b2959cu: goto L_00b2959c; case 0x00b295b0u: goto L_00b295b0; default: jump_indirect(c, t_, 0x00b29465u); return; } } /* jmp dword ptr [edx*4 + 0x10009578] */
L_00b2946c:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edx = (uint32_t)((uint32_t)0x3u); /* mov edx, 3 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x4u)); /* sub ecx, 4 */
    if (c->cf) goto L_00b29484; /* jb 0xb29484 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x3u))); /* and eax, 3 */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->eax * 4 + 0xb29490u)); switch (t_) {  default: jump_indirect(c, t_, 0x00b2947du); return; } } /* jmp dword ptr [eax*4 + 0x10009490] */
L_00b29484:;
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0xb29588u)); switch (t_) {  default: jump_indirect(c, t_, 0x00b29484u); return; } } /* jmp dword ptr [ecx*4 + 0x10009588] */
L_00b2948c:;
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0xb2950cu)); switch (t_) { case 0x00b2952cu: goto L_00b2952c; case 0x00b29534u: goto L_00b29534; case 0x00b2953cu: goto L_00b2953c; case 0x00b29544u: goto L_00b29544; case 0x00b2954cu: goto L_00b2954c; case 0x00b29554u: goto L_00b29554; case 0x00b2955cu: goto L_00b2955c; case 0x00b2956fu: goto L_00b2956f; default: jump_indirect(c, t_, 0x00b2948cu); return; } } /* jmp dword ptr [ecx*4 + 0x1000950c] */
L_00b2952c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe4u))); /* mov eax, dword ptr [esi + ecx*4 - 0x1c] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x1c], eax */
L_00b29534:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe8u))); /* mov eax, dword ptr [esi + ecx*4 - 0x18] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x18], eax */
L_00b2953c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffecu))); /* mov eax, dword ptr [esi + ecx*4 - 0x14] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffecu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x14], eax */
L_00b29544:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff0u))); /* mov eax, dword ptr [esi + ecx*4 - 0x10] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x10], eax */
L_00b2954c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff4u))); /* mov eax, dword ptr [esi + ecx*4 - 0xc] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0xc], eax */
L_00b29554:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff8u))); /* mov eax, dword ptr [esi + ecx*4 - 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 8], eax */
L_00b2955c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
L_00b2956f:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb29578u)); switch (t_) { case 0x00b29588u: goto L_00b29588; case 0x00b29590u: goto L_00b29590; case 0x00b2959cu: goto L_00b2959c; case 0x00b295b0u: goto L_00b295b0; default: jump_indirect(c, t_, 0x00b2956fu); return; } } /* jmp dword ptr [edx*4 + 0x10009578] */
L_00b29588:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b29590:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2959c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b295b0:;
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
L_00b295c8:;
    c->esi = (uint32_t)((uint32_t)(c->ecx + c->esi + 0xfffffffcu)); /* lea esi, [ecx + esi - 4] */
    c->edi = (uint32_t)((uint32_t)(c->ecx + c->edi + 0xfffffffcu)); /* lea edi, [ecx + edi - 4] */
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x3u)); /* test edi, 3 */
    if (!c->zf) goto L_00b295fc; /* jne 0xb295fc */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u))); /* and edx, 3 */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) goto L_00b295f0; /* jb 0xb295f0 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb29710u)); switch (t_) { case 0x00b29720u: goto L_00b29720; case 0x00b29728u: goto L_00b29728; case 0x00b29738u: goto L_00b29738; case 0x00b2974cu: goto L_00b2974c; default: jump_indirect(c, t_, 0x00b295e7u); return; } } /* jmp dword ptr [edx*4 + 0x10009710] */
L_00b295f0:;
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0xb296c0u)); switch (t_) { case 0x00b29707u: goto L_00b29707; default: jump_indirect(c, t_, 0x00b295f2u); return; } } /* jmp dword ptr [ecx*4 + 0x100096c0] */
L_00b295fc:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edx = (uint32_t)((uint32_t)0x3u); /* mov edx, 3 */
    (void)sub32(c, c->ecx, (uint32_t)0x4u); /* cmp ecx, 4 */
    if (c->cf) goto L_00b29614; /* jb 0xb29614 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x3u))); /* and eax, 3 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->eax * 4 + 0xb29618u)); switch (t_) {  default: jump_indirect(c, t_, 0x00b2960du); return; } } /* jmp dword ptr [eax*4 + 0x10009618] */
L_00b29614:;
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0xb29710u)); switch (t_) { case 0x00b29720u: goto L_00b29720; case 0x00b29728u: goto L_00b29728; case 0x00b29738u: goto L_00b29738; case 0x00b2974cu: goto L_00b2974c; default: jump_indirect(c, t_, 0x00b29614u); return; } } /* jmp dword ptr [ecx*4 + 0x10009710] */
L_00b29707:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb29710u)); switch (t_) { case 0x00b29720u: goto L_00b29720; case 0x00b29728u: goto L_00b29728; case 0x00b29738u: goto L_00b29738; case 0x00b2974cu: goto L_00b2974c; default: jump_indirect(c, t_, 0x00b29707u); return; } } /* jmp dword ptr [edx*4 + 0x10009710] */
L_00b29720:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b29728:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b29738:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2974c:;
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

void f_00b2948c(CPU *c) { /* PTR_00b2948c */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0xb2950cu)); switch (t_) { case 0x00b2952cu: goto L_00b2952c; case 0x00b29534u: goto L_00b29534; case 0x00b2953cu: goto L_00b2953c; case 0x00b29544u: goto L_00b29544; case 0x00b2954cu: goto L_00b2954c; case 0x00b29554u: goto L_00b29554; case 0x00b2955cu: goto L_00b2955c; case 0x00b2956fu: goto L_00b2956f; default: jump_indirect(c, t_, 0x00b2948cu); return; } } /* jmp dword ptr [ecx*4 + 0x1000950c] */
L_00b2952c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe4u))); /* mov eax, dword ptr [esi + ecx*4 - 0x1c] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x1c], eax */
L_00b29534:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe8u))); /* mov eax, dword ptr [esi + ecx*4 - 0x18] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x18], eax */
L_00b2953c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffecu))); /* mov eax, dword ptr [esi + ecx*4 - 0x14] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffecu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x14], eax */
L_00b29544:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff0u))); /* mov eax, dword ptr [esi + ecx*4 - 0x10] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x10], eax */
L_00b2954c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff4u))); /* mov eax, dword ptr [esi + ecx*4 - 0xc] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0xc], eax */
L_00b29554:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff8u))); /* mov eax, dword ptr [esi + ecx*4 - 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 8], eax */
L_00b2955c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
L_00b2956f:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb29578u)); switch (t_) { case 0x00b29588u: goto L_00b29588; case 0x00b29590u: goto L_00b29590; case 0x00b2959cu: goto L_00b2959c; case 0x00b295b0u: goto L_00b295b0; default: jump_indirect(c, t_, 0x00b2956fu); return; } } /* jmp dword ptr [edx*4 + 0x10009578] */
L_00b29588:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b29590:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2959c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b295b0:;
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

void f_00b294a0(CPU *c) { /* PTR_00b294a0 */
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
    if (c->cf) { f_00b2948c(c); return; } /* jb 0xb2948c */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb29578u)); switch (t_) { case 0x00b29588u: goto L_00b29588; case 0x00b29590u: goto L_00b29590; case 0x00b2959cu: goto L_00b2959c; case 0x00b295b0u: goto L_00b295b0; default: jump_indirect(c, t_, 0x00b294c2u); return; } } /* jmp dword ptr [edx*4 + 0x10009578] */
L_00b29588:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b29590:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2959c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b295b0:;
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

void f_00b294c0(CPU *c) { /* PTR_00b294c0 */
    PREEMPT_POLL(c);
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb29578u)); switch (t_) { case 0x00b29588u: goto L_00b29588; case 0x00b29590u: goto L_00b29590; case 0x00b2959cu: goto L_00b2959c; case 0x00b295b0u: goto L_00b295b0; default: jump_indirect(c, t_, 0x00b294c2u); return; } } /* jmp dword ptr [edx*4 + 0x10009578] */
L_00b29588:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b29590:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2959c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b295b0:;
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

void f_00b294cc(CPU *c) { /* PTR_00b294cc */
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
    if (c->cf) { f_00b2948c(c); return; } /* jb 0xb2948c */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb29578u)); switch (t_) { case 0x00b29588u: goto L_00b29588; case 0x00b29590u: goto L_00b29590; case 0x00b2959cu: goto L_00b2959c; case 0x00b295b0u: goto L_00b295b0; default: jump_indirect(c, t_, 0x00b294e8u); return; } } /* jmp dword ptr [edx*4 + 0x10009578] */
L_00b29588:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b29590:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2959c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b295b0:;
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

void f_00b294f0(CPU *c) { /* PTR_00b294f0 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & c->ecx))); /* and edx, ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) { f_00b2948c(c); return; } /* jb 0xb2948c */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb29578u)); switch (t_) { case 0x00b29588u: goto L_00b29588; case 0x00b29590u: goto L_00b29590; case 0x00b2959cu: goto L_00b2959c; case 0x00b295b0u: goto L_00b295b0; default: jump_indirect(c, t_, 0x00b29502u); return; } } /* jmp dword ptr [edx*4 + 0x10009578] */
L_00b29588:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b29590:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2959c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b295b0:;
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

void f_00b2952c(CPU *c) { /* PTR_00b2952c */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb29578u)); switch (t_) { case 0x00b29588u: goto L_00b29588; case 0x00b29590u: goto L_00b29590; case 0x00b2959cu: goto L_00b2959c; case 0x00b295b0u: goto L_00b295b0; default: jump_indirect(c, t_, 0x00b2956fu); return; } } /* jmp dword ptr [edx*4 + 0x10009578] */
L_00b29588:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b29590:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2959c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b295b0:;
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

void f_00b29534(CPU *c) { /* PTR_00b29534 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb29578u)); switch (t_) { case 0x00b29588u: goto L_00b29588; case 0x00b29590u: goto L_00b29590; case 0x00b2959cu: goto L_00b2959c; case 0x00b295b0u: goto L_00b295b0; default: jump_indirect(c, t_, 0x00b2956fu); return; } } /* jmp dword ptr [edx*4 + 0x10009578] */
L_00b29588:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b29590:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2959c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b295b0:;
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

void f_00b2953c(CPU *c) { /* PTR_00b2953c */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb29578u)); switch (t_) { case 0x00b29588u: goto L_00b29588; case 0x00b29590u: goto L_00b29590; case 0x00b2959cu: goto L_00b2959c; case 0x00b295b0u: goto L_00b295b0; default: jump_indirect(c, t_, 0x00b2956fu); return; } } /* jmp dword ptr [edx*4 + 0x10009578] */
L_00b29588:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b29590:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2959c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b295b0:;
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

void f_00b29544(CPU *c) { /* PTR_00b29544 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb29578u)); switch (t_) { case 0x00b29588u: goto L_00b29588; case 0x00b29590u: goto L_00b29590; case 0x00b2959cu: goto L_00b2959c; case 0x00b295b0u: goto L_00b295b0; default: jump_indirect(c, t_, 0x00b2956fu); return; } } /* jmp dword ptr [edx*4 + 0x10009578] */
L_00b29588:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b29590:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2959c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b295b0:;
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

void f_00b2954c(CPU *c) { /* PTR_00b2954c */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb29578u)); switch (t_) { case 0x00b29588u: goto L_00b29588; case 0x00b29590u: goto L_00b29590; case 0x00b2959cu: goto L_00b2959c; case 0x00b295b0u: goto L_00b295b0; default: jump_indirect(c, t_, 0x00b2956fu); return; } } /* jmp dword ptr [edx*4 + 0x10009578] */
L_00b29588:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b29590:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2959c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b295b0:;
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

void f_00b29554(CPU *c) { /* PTR_00b29554 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff8u))); /* mov eax, dword ptr [esi + ecx*4 - 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb29578u)); switch (t_) { case 0x00b29588u: goto L_00b29588; case 0x00b29590u: goto L_00b29590; case 0x00b2959cu: goto L_00b2959c; case 0x00b295b0u: goto L_00b295b0; default: jump_indirect(c, t_, 0x00b2956fu); return; } } /* jmp dword ptr [edx*4 + 0x10009578] */
L_00b29588:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b29590:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2959c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b295b0:;
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

void f_00b2955c(CPU *c) { /* PTR_00b2955c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb29578u)); switch (t_) { case 0x00b29588u: goto L_00b29588; case 0x00b29590u: goto L_00b29590; case 0x00b2959cu: goto L_00b2959c; case 0x00b295b0u: goto L_00b295b0; default: jump_indirect(c, t_, 0x00b2956fu); return; } } /* jmp dword ptr [edx*4 + 0x10009578] */
L_00b29588:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b29590:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2959c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b295b0:;
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

void f_00b2956f(CPU *c) { /* PTR_00b2956f */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb29578u)); switch (t_) { case 0x00b29588u: goto L_00b29588; case 0x00b29590u: goto L_00b29590; case 0x00b2959cu: goto L_00b2959c; case 0x00b295b0u: goto L_00b295b0; default: jump_indirect(c, t_, 0x00b2956fu); return; } } /* jmp dword ptr [edx*4 + 0x10009578] */
L_00b29588:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b29590:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2959c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b295b0:;
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

void f_00b29588(CPU *c) { /* PTR_00b29588 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b29590(CPU *c) { /* PTR_00b29590 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b2959c(CPU *c) { /* PTR_00b2959c */
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

void f_00b295b0(CPU *c) { /* PTR_00b295b0 */
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

void f_00b295f0(CPU *c) { /* PTR_00b295f0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0xb296c0u)); switch (t_) { case 0x00b29707u: goto L_00b29707; default: jump_indirect(c, t_, 0x00b295f2u); return; } } /* jmp dword ptr [ecx*4 + 0x100096c0] */
L_00b29707:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb29710u)); switch (t_) { case 0x00b29720u: goto L_00b29720; case 0x00b29728u: goto L_00b29728; case 0x00b29738u: goto L_00b29738; case 0x00b2974cu: goto L_00b2974c; default: jump_indirect(c, t_, 0x00b29707u); return; } } /* jmp dword ptr [edx*4 + 0x10009710] */
L_00b29720:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b29728:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b29738:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2974c:;
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

void f_00b29628(CPU *c) { /* PTR_00b29628 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & c->ecx))); /* and edx, ecx */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) { f_00b295f0(c); return; } /* jb 0xb295f0 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb29710u)); switch (t_) { case 0x00b29720u: goto L_00b29720; case 0x00b29728u: goto L_00b29728; case 0x00b29738u: goto L_00b29738; case 0x00b2974cu: goto L_00b2974c; default: jump_indirect(c, t_, 0x00b2963eu); return; } } /* jmp dword ptr [edx*4 + 0x10009710] */
L_00b29720:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b29728:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b29738:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2974c:;
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

void f_00b29648(CPU *c) { /* PTR_00b29648 */
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
    if (c->cf) { f_00b295f0(c); return; } /* jb 0xb295f0 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb29710u)); switch (t_) { case 0x00b29720u: goto L_00b29720; case 0x00b29728u: goto L_00b29728; case 0x00b29738u: goto L_00b29738; case 0x00b2974cu: goto L_00b2974c; default: jump_indirect(c, t_, 0x00b29668u); return; } } /* jmp dword ptr [edx*4 + 0x10009710] */
L_00b29720:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b29728:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b29738:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2974c:;
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

void f_00b29670(CPU *c) { /* PTR_00b29670 */
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
    if (c->cf) { f_00b295f0(c); return; } /* jb 0xb295f0 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb29710u)); switch (t_) { case 0x00b29720u: goto L_00b29720; case 0x00b29728u: goto L_00b29728; case 0x00b29738u: goto L_00b29738; case 0x00b2974cu: goto L_00b2974c; default: jump_indirect(c, t_, 0x00b2969au); return; } } /* jmp dword ptr [edx*4 + 0x10009710] */
L_00b29720:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b29728:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b29738:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2974c:;
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

void f_00b296c4(CPU *c) { /* PTR_00b296c4 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb29710u)); switch (t_) { case 0x00b29720u: goto L_00b29720; case 0x00b29728u: goto L_00b29728; case 0x00b29738u: goto L_00b29738; case 0x00b2974cu: goto L_00b2974c; default: jump_indirect(c, t_, 0x00b29707u); return; } } /* jmp dword ptr [edx*4 + 0x10009710] */
L_00b29720:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b29728:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b29738:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2974c:;
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

void f_00b296cc(CPU *c) { /* PTR_00b296cc */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb29710u)); switch (t_) { case 0x00b29720u: goto L_00b29720; case 0x00b29728u: goto L_00b29728; case 0x00b29738u: goto L_00b29738; case 0x00b2974cu: goto L_00b2974c; default: jump_indirect(c, t_, 0x00b29707u); return; } } /* jmp dword ptr [edx*4 + 0x10009710] */
L_00b29720:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b29728:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b29738:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2974c:;
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

void f_00b296d4(CPU *c) { /* PTR_00b296d4 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb29710u)); switch (t_) { case 0x00b29720u: goto L_00b29720; case 0x00b29728u: goto L_00b29728; case 0x00b29738u: goto L_00b29738; case 0x00b2974cu: goto L_00b2974c; default: jump_indirect(c, t_, 0x00b29707u); return; } } /* jmp dword ptr [edx*4 + 0x10009710] */
L_00b29720:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b29728:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b29738:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2974c:;
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

void f_00b296dc(CPU *c) { /* PTR_00b296dc */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb29710u)); switch (t_) { case 0x00b29720u: goto L_00b29720; case 0x00b29728u: goto L_00b29728; case 0x00b29738u: goto L_00b29738; case 0x00b2974cu: goto L_00b2974c; default: jump_indirect(c, t_, 0x00b29707u); return; } } /* jmp dword ptr [edx*4 + 0x10009710] */
L_00b29720:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b29728:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b29738:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2974c:;
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

void f_00b296e4(CPU *c) { /* PTR_00b296e4 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb29710u)); switch (t_) { case 0x00b29720u: goto L_00b29720; case 0x00b29728u: goto L_00b29728; case 0x00b29738u: goto L_00b29738; case 0x00b2974cu: goto L_00b2974c; default: jump_indirect(c, t_, 0x00b29707u); return; } } /* jmp dword ptr [edx*4 + 0x10009710] */
L_00b29720:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b29728:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b29738:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2974c:;
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

void f_00b296ec(CPU *c) { /* PTR_00b296ec */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x8u))); /* mov eax, dword ptr [esi + ecx*4 + 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x4u))); /* mov eax, dword ptr [esi + ecx*4 + 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb29710u)); switch (t_) { case 0x00b29720u: goto L_00b29720; case 0x00b29728u: goto L_00b29728; case 0x00b29738u: goto L_00b29738; case 0x00b2974cu: goto L_00b2974c; default: jump_indirect(c, t_, 0x00b29707u); return; } } /* jmp dword ptr [edx*4 + 0x10009710] */
L_00b29720:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b29728:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b29738:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2974c:;
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

void f_00b296f4(CPU *c) { /* PTR_00b296f4 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x4u))); /* mov eax, dword ptr [esi + ecx*4 + 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb29710u)); switch (t_) { case 0x00b29720u: goto L_00b29720; case 0x00b29728u: goto L_00b29728; case 0x00b29738u: goto L_00b29738; case 0x00b2974cu: goto L_00b2974c; default: jump_indirect(c, t_, 0x00b29707u); return; } } /* jmp dword ptr [edx*4 + 0x10009710] */
L_00b29720:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b29728:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b29738:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2974c:;
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

void f_00b29707(CPU *c) { /* PTR_00b29707 */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb29710u)); switch (t_) { case 0x00b29720u: goto L_00b29720; case 0x00b29728u: goto L_00b29728; case 0x00b29738u: goto L_00b29738; case 0x00b2974cu: goto L_00b2974c; default: jump_indirect(c, t_, 0x00b29707u); return; } } /* jmp dword ptr [edx*4 + 0x10009710] */
L_00b29720:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b29728:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b29738:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2974c:;
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

void f_00b29720(CPU *c) { /* PTR_00b29720 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b29728(CPU *c) { /* PTR_00b29728 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b29738(CPU *c) { /* PTR_00b29738 */
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

void f_00b2974c(CPU *c) { /* PTR_00b2974c */
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

void f_00b29765(CPU *c) { /* FUN_10009765 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xb2e720u; PUSH32(c, v_); } /* push 0x1000e720 */
    { uint32_t v_ = 0xb273f8u; PUSH32(c, v_); } /* push 0x100073f8 */
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
    if ((!c->cf && !c->zf)) goto L_00b297ae; /* ja 0xb297ae */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (!c->zf) goto L_00b297a3; /* jne 0xb297a3 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00b297a3:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
    goto L_00b297b0; /* jmp 0xb297b0 */
L_00b297ae:;
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
L_00b297b0:;
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x20], ebx */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00b29864; /* ja 0xb29864 */
    c->eax = (uint32_t)(R32((uint32_t)(0xb33a28u))); /* mov eax, dword ptr [0x10013a28] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_00b29807; /* jne 0xb29807 */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov edi, dword ptr [ebp - 0x1c] */
    (void)sub32(c, c->edi, R32((uint32_t)(0xb33a20u))); /* cmp edi, dword ptr [0x10013a20] */
    if ((!c->cf && !c->zf)) goto L_00b2984d; /* ja 0xb2984d */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b297d8u); f_00b27565(c); /* call 0xb27565 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 4], ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b297e2u); f_00b29c55(c); /* call 0xb29c55 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b297efu); f_00b297fe(c); /* call 0xb297fe */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (c->zf) goto L_00b29852; /* je 0xb29852 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x1c] */
    goto L_00b29841; /* jmp 0xb29841 */
L_00b29807:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00b2984d; /* jne 0xb2984d */
    (void)sub32(c, c->esi, R32((uint32_t)(0xb329ecu))); /* cmp esi, dword ptr [0x100129ec] */
    if ((!c->cf && !c->zf)) goto L_00b2984d; /* ja 0xb2984d */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b2981bu); f_00b27565(c); /* call 0xb27565 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2982eu); f_00b2a6f8(c); /* call 0xb2a6f8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b2983bu); f_00b29887(c); /* call 0xb29887 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (c->zf) goto L_00b29852; /* je 0xb29852 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
L_00b29841:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x20] */
    PUSH32(c, 0x00b2984au); f_00b2bd50(c); /* call 0xb2bd50 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_00b2984d:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (!c->zf) goto L_00b29890; /* jne 0xb29890 */
L_00b29852:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = R32((uint32_t)(0xb33a24u)); PUSH32(c, v_); } /* push dword ptr [0x10013a24] */
    { uint32_t t_ = R32((uint32_t)(0xb2e03cu)); PUSH32(c, 0x00b29861u); call_indirect(c, t_); } /* call dword ptr [0x1000e03c] */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
L_00b29864:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (!c->zf) goto L_00b29890; /* jne 0xb29890 */
    (void)sub32(c, R32((uint32_t)(0xb33648u)), c->ebx); /* cmp dword ptr [0x10013648], ebx */
    if (c->zf) goto L_00b29890; /* je 0xb29890 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b29877u); f_00b2aacd(c); /* call 0xb2aacd */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b297b0; /* jne 0xb297b0 */
    goto L_00b29893; /* jmp 0xb29893 */
L_00b29890:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov eax, dword ptr [ebp - 0x20] */
L_00b29893:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b297b0(CPU *c) { /* PTR_00b297b0 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x20], ebx */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) { f_00b29864(c); return; } /* ja 0xb29864 */
    c->eax = (uint32_t)(R32((uint32_t)(0xb33a28u))); /* mov eax, dword ptr [0x10013a28] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) { f_00b29807(c); return; } /* jne 0xb29807 */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov edi, dword ptr [ebp - 0x1c] */
    (void)sub32(c, c->edi, R32((uint32_t)(0xb33a20u))); /* cmp edi, dword ptr [0x10013a20] */
    if ((!c->cf && !c->zf)) { f_00b2984d(c); return; } /* ja 0xb2984d */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b297d8u); f_00b27565(c); /* call 0xb27565 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 4], ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b297e2u); f_00b29c55(c); /* call 0xb29c55 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b297efu); f_00b297fe(c); /* call 0xb297fe */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (c->zf) { f_00b29852(c); return; } /* je 0xb29852 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x1c] */
    { f_00b29841(c); return; } /* jmp 0xb29841 */
}

void f_00b297f9(CPU *c) { /* PTR_00b297f9 */
    PREEMPT_POLL(c);
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    { f_00b297fe(c); return; }
}

void f_00b297fe(CPU *c) { /* FUN_100097fe */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b29805u); f_00b275c6(c); /* call 0xb275c6 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00b29807(CPU *c) { /* PTR_00b29807 */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00b2984d; /* jne 0xb2984d */
    (void)sub32(c, c->esi, R32((uint32_t)(0xb329ecu))); /* cmp esi, dword ptr [0x100129ec] */
    if ((!c->cf && !c->zf)) goto L_00b2984d; /* ja 0xb2984d */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b2981bu); f_00b27565(c); /* call 0xb27565 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2982eu); f_00b2a6f8(c); /* call 0xb2a6f8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00b2983bu); f_00b29887(c); /* call 0xb29887 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (c->zf) goto L_00b29852; /* je 0xb29852 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x20] */
    PUSH32(c, 0x00b2984au); f_00b2bd50(c); /* call 0xb2bd50 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_00b2984d:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (!c->zf) { f_00b29890(c); return; } /* jne 0xb29890 */
L_00b29852:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = R32((uint32_t)(0xb33a24u)); PUSH32(c, v_); } /* push dword ptr [0x10013a24] */
    { uint32_t t_ = R32((uint32_t)(0xb2e03cu)); PUSH32(c, 0x00b29861u); call_indirect(c, t_); } /* call dword ptr [0x1000e03c] */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (!c->zf) { f_00b29890(c); return; } /* jne 0xb29890 */
    (void)sub32(c, R32((uint32_t)(0xb33648u)), c->ebx); /* cmp dword ptr [0x10013648], ebx */
    if (c->zf) { f_00b29890(c); return; } /* je 0xb29890 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b29877u); f_00b2aacd(c); /* call 0xb2aacd */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00b297b0(c); return; } /* jne 0xb297b0 */
    { f_00b29893(c); return; } /* jmp 0xb29893 */
}

void f_00b29841(CPU *c) { /* PTR_00b29841 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x20] */
    PUSH32(c, 0x00b2984au); f_00b2bd50(c); /* call 0xb2bd50 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (!c->zf) { f_00b29890(c); return; } /* jne 0xb29890 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = R32((uint32_t)(0xb33a24u)); PUSH32(c, v_); } /* push dword ptr [0x10013a24] */
    { uint32_t t_ = R32((uint32_t)(0xb2e03cu)); PUSH32(c, 0x00b29861u); call_indirect(c, t_); } /* call dword ptr [0x1000e03c] */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (!c->zf) { f_00b29890(c); return; } /* jne 0xb29890 */
    (void)sub32(c, R32((uint32_t)(0xb33648u)), c->ebx); /* cmp dword ptr [0x10013648], ebx */
    if (c->zf) { f_00b29890(c); return; } /* je 0xb29890 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b29877u); f_00b2aacd(c); /* call 0xb2aacd */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00b297b0(c); return; } /* jne 0xb297b0 */
    { f_00b29893(c); return; } /* jmp 0xb29893 */
}

void f_00b2984d(CPU *c) { /* PTR_00b2984d */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (!c->zf) { f_00b29890(c); return; } /* jne 0xb29890 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = R32((uint32_t)(0xb33a24u)); PUSH32(c, v_); } /* push dword ptr [0x10013a24] */
    { uint32_t t_ = R32((uint32_t)(0xb2e03cu)); PUSH32(c, 0x00b29861u); call_indirect(c, t_); } /* call dword ptr [0x1000e03c] */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (!c->zf) { f_00b29890(c); return; } /* jne 0xb29890 */
    (void)sub32(c, R32((uint32_t)(0xb33648u)), c->ebx); /* cmp dword ptr [0x10013648], ebx */
    if (c->zf) { f_00b29890(c); return; } /* je 0xb29890 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b29877u); f_00b2aacd(c); /* call 0xb2aacd */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00b297b0(c); return; } /* jne 0xb297b0 */
    { f_00b29893(c); return; } /* jmp 0xb29893 */
}

void f_00b29852(CPU *c) { /* PTR_00b29852 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = R32((uint32_t)(0xb33a24u)); PUSH32(c, v_); } /* push dword ptr [0x10013a24] */
    { uint32_t t_ = R32((uint32_t)(0xb2e03cu)); PUSH32(c, 0x00b29861u); call_indirect(c, t_); } /* call dword ptr [0x1000e03c] */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (!c->zf) { f_00b29890(c); return; } /* jne 0xb29890 */
    (void)sub32(c, R32((uint32_t)(0xb33648u)), c->ebx); /* cmp dword ptr [0x10013648], ebx */
    if (c->zf) { f_00b29890(c); return; } /* je 0xb29890 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b29877u); f_00b2aacd(c); /* call 0xb2aacd */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00b297b0(c); return; } /* jne 0xb297b0 */
    { f_00b29893(c); return; } /* jmp 0xb29893 */
}

void f_00b29864(CPU *c) { /* PTR_00b29864 */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (!c->zf) { f_00b29890(c); return; } /* jne 0xb29890 */
    (void)sub32(c, R32((uint32_t)(0xb33648u)), c->ebx); /* cmp dword ptr [0x10013648], ebx */
    if (c->zf) { f_00b29890(c); return; } /* je 0xb29890 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b29877u); f_00b2aacd(c); /* call 0xb2aacd */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00b297b0(c); return; } /* jne 0xb297b0 */
    { f_00b29893(c); return; } /* jmp 0xb29893 */
}

void f_00b29882(CPU *c) { /* PTR_00b29882 */
    PREEMPT_POLL(c);
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    { f_00b29887(c); return; }
}

void f_00b29887(CPU *c) { /* FUN_10009887 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00b2988eu); f_00b275c6(c); /* call 0xb275c6 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00b29890(CPU *c) { /* PTR_00b29890 */
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

void f_00b29893(CPU *c) { /* PTR_00b29893 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b298a2(CPU *c) { /* FUN_100098a2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xau; PUSH32(c, v_); } /* push 0xa */
    PUSH32(c, 0x00b298a9u); f_00b2928c(c); /* call 0xb2928c */
    { uint32_t v_ = 0x16u; PUSH32(c, v_); } /* push 0x16 */
    PUSH32(c, 0x00b298b0u); f_00b2c7ee(c); /* call 0xb2c7ee */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    PUSH32(c, 0x00b298b9u); f_00b2678c(c); /* call 0xb2678c */
    { f_00b298b9(c); return; }
}

void f_00b298b9(CPU *c) { /* FUN_100098b9 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x140u; PUSH32(c, v_); } /* push 0x140 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb33a24u)); PUSH32(c, v_); } /* push dword ptr [0x10013a24] */
    { uint32_t t_ = R32((uint32_t)(0xb2e03cu)); PUSH32(c, 0x00b298ccu); call_indirect(c, t_); } /* call dword ptr [0x1000e03c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(0xb33a1cu), (uint32_t)(c->eax)); /* mov dword ptr [0x10013a1c], eax */
    if (!c->zf) goto L_00b298d6; /* jne 0xb298d6 */
    c->esp += 4; return; /* ret  */
L_00b298d6:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    { uint32_t a_ = (uint32_t)(0xb33a14u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [0x10013a14], 0 */
    { uint32_t a_ = (uint32_t)(0xb33a18u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [0x10013a18], 0 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    W32((uint32_t)(0xb33a10u), (uint32_t)(c->eax)); /* mov dword ptr [0x10013a10], eax */
    W32((uint32_t)(0xb33a20u), (uint32_t)(c->ecx)); /* mov dword ptr [0x10013a20], ecx */
    W32((uint32_t)(0xb33a08u), (uint32_t)((uint32_t)0x10u)); /* mov dword ptr [0x10013a08], 0x10 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_00b29901(CPU *c) { /* FUN_10009901 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0xb33a18u))); /* mov eax, dword ptr [0x10013a18] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea ecx, [eax + eax*4] */
    c->eax = (uint32_t)(R32((uint32_t)(0xb33a1cu))); /* mov eax, dword ptr [0x10013a1c] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->ecx * 4)); /* lea ecx, [eax + ecx*4] */
L_00b29911:;
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->cf) goto L_00b29929; /* jae 0xb29929 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    c->edx = (uint32_t)(sub32(c, c->edx, R32((uint32_t)(c->eax + 0xcu)))); /* sub edx, dword ptr [eax + 0xc] */
    (void)sub32(c, c->edx, (uint32_t)0x100000u); /* cmp edx, 0x100000 */
    if (c->cf) goto L_00b2992b; /* jb 0xb2992b */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x14u)); /* add eax, 0x14 */
    goto L_00b29911; /* jmp 0xb29911 */
L_00b29929:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00b2992b:;
    c->esp += 4; return; /* ret  */
}

void f_00b2992c(CPU *c) { /* FUN_1000992c */
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
    if (!c->zf) goto L_00b29c50; /* jne 0xb29c50 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + c->esi))); /* mov edx, dword ptr [ecx + esi] */
    c->ebx = (uint32_t)((uint32_t)(c->ecx + c->esi)); /* lea ebx, [ecx + esi] */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0xc], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0xfffffffcu))); /* mov edx, dword ptr [esi - 4] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 8], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov edx, dword ptr [ebp - 0xc] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & (uint8_t)0x1u)); /* test dl, 1 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 0xc], ebx */
    if (!c->zf) goto L_00b29a02; /* jne 0xb29a02 */
    c->edx = (uint32_t)(sar32(c, c->edx, 4)); /* sar edx, 4 */
    c->edx = (uint32_t)(dec32(c, c->edx)); /* dec edx */
    (void)sub32(c, c->edx, (uint32_t)0x3fu); /* cmp edx, 0x3f */
    if ((c->cf || c->zf)) goto L_00b29990; /* jbe 0xb29990 */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
L_00b29990:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov ecx, dword ptr [ebx + 4] */
    (void)sub32(c, c->ecx, R32((uint32_t)(c->ebx + 0x8u))); /* cmp ecx, dword ptr [ebx + 8] */
    if (!c->zf) goto L_00b299e4; /* jne 0xb299e4 */
    (void)sub32(c, c->edx, (uint32_t)0x20u); /* cmp edx, 0x20 */
    if (!c->cf) goto L_00b299bb; /* jae 0xb299bb */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->ecx = (uint32_t)((uint32_t)(c->edx + c->eax + 0x4u)); /* lea ecx, [edx + eax + 4] */
    c->ebx = (uint32_t)((uint32_t)~c->ebx); /* not ebx */
    { uint32_t a_ = (uint32_t)(c->eax + c->edi * 4 + 0x44u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [eax + edi*4 + 0x44], ebx */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(dec8(c, R8(a_)))); } /* dec byte ptr [ecx] */
    if (!c->zf) goto L_00b299dc; /* jne 0xb299dc */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [ecx], ebx */
    goto L_00b299dc; /* jmp 0xb299dc */
L_00b299bb:;
    c->ecx = (uint32_t)((uint32_t)(c->edx + 0xffffffe0u)); /* lea ecx, [edx - 0x20] */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->ecx = (uint32_t)((uint32_t)(c->edx + c->eax + 0x4u)); /* lea ecx, [edx + eax + 4] */
    c->ebx = (uint32_t)((uint32_t)~c->ebx); /* not ebx */
    { uint32_t a_ = (uint32_t)(c->eax + c->edi * 4 + 0xc4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [eax + edi*4 + 0xc4], ebx */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(dec8(c, R8(a_)))); } /* dec byte ptr [ecx] */
    if (!c->zf) goto L_00b299dc; /* jne 0xb299dc */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [ecx + 4], ebx */
L_00b299dc:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ebx, dword ptr [ebp + 0xc] */
    goto L_00b299e7; /* jmp 0xb299e7 */
L_00b299e4:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
L_00b299e7:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov edx, dword ptr [ebx + 8] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov ebx, dword ptr [ebx + 4] */
    c->ecx = (uint32_t)(add32(c, c->ecx, R32((uint32_t)(c->ebp + 0xfffffff4u)))); /* add ecx, dword ptr [ebp - 0xc] */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [edx + 4], ebx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 4], ecx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov ebx, dword ptr [edx + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov edx, dword ptr [edx + 8] */
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [ebx + 8], edx */
L_00b29a02:;
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    c->edx = (uint32_t)(sar32(c, c->edx, 4)); /* sar edx, 4 */
    c->edx = (uint32_t)(dec32(c, c->edx)); /* dec edx */
    (void)sub32(c, c->edx, (uint32_t)0x3fu); /* cmp edx, 0x3f */
    if ((c->cf || c->zf)) goto L_00b29a10; /* jbe 0xb29a10 */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
L_00b29a10:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ebx, dword ptr [ebp - 8] */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x1u))); /* and ebx, 1 */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0xc], ebx */
    if (!c->zf) goto L_00b29ab3; /* jne 0xb29ab3 */
    c->esi = (uint32_t)(sub32(c, c->esi, R32((uint32_t)(c->ebp + 0xfffffff8u)))); /* sub esi, dword ptr [ebp - 8] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ebx, dword ptr [ebp - 8] */
    c->ebx = (uint32_t)(sar32(c, c->ebx, 4)); /* sar ebx, 4 */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    (void)sub32(c, c->ebx, c->esi); /* cmp ebx, esi */
    if ((c->cf || c->zf)) goto L_00b29a35; /* jbe 0xb29a35 */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
L_00b29a35:;
    c->ecx = (uint32_t)(add32(c, c->ecx, R32((uint32_t)(c->ebp + 0xfffffff8u)))); /* add ecx, dword ptr [ebp - 8] */
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 4], ecx */
    c->edx = (uint32_t)(sar32(c, c->edx, 4)); /* sar edx, 4 */
    c->edx = (uint32_t)(dec32(c, c->edx)); /* dec edx */
    (void)sub32(c, c->edx, c->esi); /* cmp edx, esi */
    if ((c->cf || c->zf)) goto L_00b29a47; /* jbe 0xb29a47 */
    c->edx = (uint32_t)(c->esi); /* mov edx, esi */
L_00b29a47:;
    (void)sub32(c, c->ebx, c->edx); /* cmp ebx, edx */
    if (c->zf) goto L_00b29aae; /* je 0xb29aae */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov esi, dword ptr [ecx + 4] */
    (void)sub32(c, c->esi, R32((uint32_t)(c->ecx + 0x8u))); /* cmp esi, dword ptr [ecx + 8] */
    if (!c->zf) goto L_00b29a96; /* jne 0xb29a96 */
    (void)sub32(c, c->ebx, (uint32_t)0x20u); /* cmp ebx, 0x20 */
    if (!c->cf) goto L_00b29a77; /* jae 0xb29a77 */
    c->esi = (uint32_t)((uint32_t)0x80000000u); /* mov esi, 0x80000000 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    c->esi = (uint32_t)(shr32(c, c->esi, (c->ecx & 0xff))); /* shr esi, cl */
    c->esi = (uint32_t)((uint32_t)~c->esi); /* not esi */
    { uint32_t a_ = (uint32_t)(c->eax + c->edi * 4 + 0x44u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->esi)))); } /* and dword ptr [eax + edi*4 + 0x44], esi */
    { uint32_t a_ = (uint32_t)(c->ebx + c->eax + 0x4u); W8(a_, (uint8_t)(dec8(c, R8(a_)))); } /* dec byte ptr [ebx + eax + 4] */
    if (!c->zf) goto L_00b29a96; /* jne 0xb29a96 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->esi)))); } /* and dword ptr [ecx], esi */
    goto L_00b29a96; /* jmp 0xb29a96 */
L_00b29a77:;
    c->ecx = (uint32_t)((uint32_t)(c->ebx + 0xffffffe0u)); /* lea ecx, [ebx - 0x20] */
    c->esi = (uint32_t)((uint32_t)0x80000000u); /* mov esi, 0x80000000 */
    c->esi = (uint32_t)(shr32(c, c->esi, (c->ecx & 0xff))); /* shr esi, cl */
    c->esi = (uint32_t)((uint32_t)~c->esi); /* not esi */
    { uint32_t a_ = (uint32_t)(c->eax + c->edi * 4 + 0xc4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->esi)))); } /* and dword ptr [eax + edi*4 + 0xc4], esi */
    { uint32_t a_ = (uint32_t)(c->ebx + c->eax + 0x4u); W8(a_, (uint8_t)(dec8(c, R8(a_)))); } /* dec byte ptr [ebx + eax + 4] */
    if (!c->zf) goto L_00b29a96; /* jne 0xb29a96 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->esi)))); } /* and dword ptr [ecx + 4], esi */
L_00b29a96:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov esi, dword ptr [ecx + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ecx, dword ptr [ecx + 4] */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 4], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov esi, dword ptr [ecx + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov ecx, dword ptr [ecx + 8] */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 8], ecx */
L_00b29aae:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    goto L_00b29ab6; /* jmp 0xb29ab6 */
L_00b29ab3:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00b29ab6:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0xc], 0 */
    if (!c->zf) goto L_00b29ac4; /* jne 0xb29ac4 */
    (void)sub32(c, c->ebx, c->edx); /* cmp ebx, edx */
    if (c->zf) goto L_00b29b45; /* je 0xb29b45 */
L_00b29ac4:;
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
    if (!c->zf) goto L_00b29b45; /* jne 0xb29b45 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx + c->eax + 0x4u))); /* mov cl, byte ptr [edx + eax + 4] */
    (void)sub32(c, c->edx, (uint32_t)0x20u); /* cmp edx, 0x20 */
    W8((uint32_t)(c->ebp + 0xfu), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [ebp + 0xf], cl */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(inc8(c, ((uint8_t)c->ecx))); /* inc cl */
    W8((uint32_t)(c->edx + c->eax + 0x4u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [edx + eax + 4], cl */
    if (!c->cf) goto L_00b29b1c; /* jae 0xb29b1c */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xfu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0xf], 0 */
    if (!c->zf) goto L_00b29b0b; /* jne 0xb29b0b */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->ebx)))); } /* or dword ptr [ecx], ebx */
L_00b29b0b:;
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->edi * 4 + 0x44u)); /* lea eax, [eax + edi*4 + 0x44] */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->ebx)))); } /* or dword ptr [eax], ebx */
    goto L_00b29b45; /* jmp 0xb29b45 */
L_00b29b1c:;
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xfu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0xf], 0 */
    if (!c->zf) goto L_00b29b32; /* jne 0xb29b32 */
    c->ecx = (uint32_t)((uint32_t)(c->edx + 0xffffffe0u)); /* lea ecx, [edx - 0x20] */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->ebx)))); } /* or dword ptr [ecx + 4], ebx */
L_00b29b32:;
    c->ecx = (uint32_t)((uint32_t)(c->edx + 0xffffffe0u)); /* lea ecx, [edx - 0x20] */
    c->edx = (uint32_t)((uint32_t)0x80000000u); /* mov edx, 0x80000000 */
    c->edx = (uint32_t)(shr32(c, c->edx, (c->ecx & 0xff))); /* shr edx, cl */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->edi * 4 + 0xc4u)); /* lea eax, [eax + edi*4 + 0xc4] */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edx)))); } /* or dword ptr [eax], edx */
L_00b29b45:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    W32((uint32_t)(c->eax + c->esi + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [eax + esi - 4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [eax] */
    if (!c->zf) goto L_00b29c50; /* jne 0xb29c50 */
    c->eax = (uint32_t)(R32((uint32_t)(0xb33a14u))); /* mov eax, dword ptr [0x10013a14] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b29c42; /* je 0xb29c42 */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb33a0cu))); /* mov ecx, dword ptr [0x10013a0c] */
    c->esi = (uint32_t)(R32((uint32_t)(0xb2e09cu))); /* mov esi, dword ptr [0x1000e09c] */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 15)); /* shl ecx, 0xf */
    c->ecx = (uint32_t)(add32(c, c->ecx, R32((uint32_t)(c->eax + 0xcu)))); /* add ecx, dword ptr [eax + 0xc] */
    c->ebx = (uint32_t)((uint32_t)0x8000u); /* mov ebx, 0x8000 */
    { uint32_t v_ = 0x4000u; PUSH32(c, v_); } /* push 0x4000 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t t_ = c->esi; PUSH32(c, 0x00b29b86u); call_indirect(c, t_); } /* call esi */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb33a0cu))); /* mov ecx, dword ptr [0x10013a0c] */
    c->eax = (uint32_t)(R32((uint32_t)(0xb33a14u))); /* mov eax, dword ptr [0x10013a14] */
    c->edx = (uint32_t)((uint32_t)0x80000000u); /* mov edx, 0x80000000 */
    c->edx = (uint32_t)(shr32(c, c->edx, (c->ecx & 0xff))); /* shr edx, cl */
    { uint32_t a_ = (uint32_t)(c->eax + 0x8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edx)))); } /* or dword ptr [eax + 8], edx */
    c->eax = (uint32_t)(R32((uint32_t)(0xb33a14u))); /* mov eax, dword ptr [0x10013a14] */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb33a0cu))); /* mov ecx, dword ptr [0x10013a0c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x10u))); /* mov eax, dword ptr [eax + 0x10] */
    { uint32_t a_ = (uint32_t)(c->eax + c->ecx * 4 + 0xc4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [eax + ecx*4 + 0xc4], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(0xb33a14u))); /* mov eax, dword ptr [0x10013a14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x10u))); /* mov eax, dword ptr [eax + 0x10] */
    { uint32_t a_ = (uint32_t)(c->eax + 0x43u); W8(a_, (uint8_t)(dec8(c, R8(a_)))); } /* dec byte ptr [eax + 0x43] */
    c->eax = (uint32_t)(R32((uint32_t)(0xb33a14u))); /* mov eax, dword ptr [0x10013a14] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x10u))); /* mov ecx, dword ptr [eax + 0x10] */
    (void)sub8(c, R8((uint32_t)(c->ecx + 0x43u)), (uint8_t)0x0u); /* cmp byte ptr [ecx + 0x43], 0 */
    if (!c->zf) goto L_00b29bd3; /* jne 0xb29bd3 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0xfffffffeu)))); } /* and dword ptr [eax + 4], 0xfffffffe */
    c->eax = (uint32_t)(R32((uint32_t)(0xb33a14u))); /* mov eax, dword ptr [0x10013a14] */
L_00b29bd3:;
    (void)sub32(c, R32((uint32_t)(c->eax + 0x8u)), (uint32_t)0xffffffffu); /* cmp dword ptr [eax + 8], -1 */
    if (!c->zf) goto L_00b29c42; /* jne 0xb29c42 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->eax + 0xcu)); PUSH32(c, v_); } /* push dword ptr [eax + 0xc] */
    { uint32_t t_ = c->esi; PUSH32(c, 0x00b29be1u); call_indirect(c, t_); } /* call esi */
    c->eax = (uint32_t)(R32((uint32_t)(0xb33a14u))); /* mov eax, dword ptr [0x10013a14] */
    { uint32_t v_ = R32((uint32_t)(c->eax + 0x10u)); PUSH32(c, v_); } /* push dword ptr [eax + 0x10] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb33a24u)); PUSH32(c, v_); } /* push dword ptr [0x10013a24] */
    { uint32_t t_ = R32((uint32_t)(0xb2e05cu)); PUSH32(c, 0x00b29bf7u); call_indirect(c, t_); } /* call dword ptr [0x1000e05c] */
    c->eax = (uint32_t)(R32((uint32_t)(0xb33a18u))); /* mov eax, dword ptr [0x10013a18] */
    c->edx = (uint32_t)(R32((uint32_t)(0xb33a1cu))); /* mov edx, dword ptr [0x10013a1c] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea eax, [eax + eax*4] */
    c->eax = (uint32_t)(shl32(c, c->eax, 2)); /* shl eax, 2 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(0xb33a14u))); /* mov eax, dword ptr [0x10013a14] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->edx + 0xffffffecu)); /* lea ecx, [ecx + edx - 0x14] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x14u)); /* lea ecx, [eax + 0x14] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b29c20u); f_00b29430(c); /* call 0xb29430 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t a_ = (uint32_t)(0xb33a18u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [0x10013a18] */
    (void)sub32(c, c->eax, R32((uint32_t)(0xb33a14u))); /* cmp eax, dword ptr [0x10013a14] */
    if ((c->cf || c->zf)) goto L_00b29c38; /* jbe 0xb29c38 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(sub32(c, R32(a_), (uint32_t)0x14u))); } /* sub dword ptr [ebp + 8], 0x14 */
L_00b29c38:;
    c->eax = (uint32_t)(R32((uint32_t)(0xb33a1cu))); /* mov eax, dword ptr [0x10013a1c] */
    W32((uint32_t)(0xb33a10u), (uint32_t)(c->eax)); /* mov dword ptr [0x10013a10], eax */
L_00b29c42:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(0xb33a0cu), (uint32_t)(c->edi)); /* mov dword ptr [0x10013a0c], edi */
    W32((uint32_t)(0xb33a14u), (uint32_t)(c->eax)); /* mov dword ptr [0x10013a14], eax */
L_00b29c50:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b29c55(CPU *c) { /* FUN_10009c55 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x14u)); /* sub esp, 0x14 */
    c->eax = (uint32_t)(R32((uint32_t)(0xb33a18u))); /* mov eax, dword ptr [0x10013a18] */
    c->edx = (uint32_t)(R32((uint32_t)(0xb33a1cu))); /* mov edx, dword ptr [0x10013a1c] */
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
    if ((c->sf == c->of)) goto L_00b29c95; /* jge 0xb29c95 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi | (uint32_t)0xffffffffu))); /* or esi, 0xffffffff */
    c->esi = (uint32_t)(shr32(c, c->esi, (c->ecx & 0xff))); /* shr esi, cl */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 8], 0xffffffff */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0xc], esi */
    goto L_00b29ca5; /* jmp 0xb29ca5 */
L_00b29c95:;
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0xffffffe0u)); /* add ecx, -0x20 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, (c->ecx & 0xff))); /* shr eax, cl */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0xc], esi */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
L_00b29ca5:;
    c->eax = (uint32_t)(R32((uint32_t)(0xb33a10u))); /* mov eax, dword ptr [0x10013a10] */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 8], ebx */
    if (!c->cf) goto L_00b29ccc; /* jae 0xb29ccc */
L_00b29cb3:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov ecx, dword ptr [ebx + 4] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov edi, dword ptr [ebx] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & R32((uint32_t)(c->ebp + 0xfffffff8u))))); /* and ecx, dword ptr [ebp - 8] */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & c->esi))); /* and edi, esi */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->edi))); /* or ecx, edi */
    if (!c->zf) goto L_00b29ccc; /* jne 0xb29ccc */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x14u)); /* add ebx, 0x14 */
    (void)sub32(c, c->ebx, R32((uint32_t)(c->ebp + 0xfffffffcu))); /* cmp ebx, dword ptr [ebp - 4] */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 8], ebx */
    if (c->cf) goto L_00b29cb3; /* jb 0xb29cb3 */
L_00b29ccc:;
    (void)sub32(c, c->ebx, R32((uint32_t)(c->ebp + 0xfffffffcu))); /* cmp ebx, dword ptr [ebp - 4] */
    if (!c->zf) goto L_00b29d4a; /* jne 0xb29d4a */
    c->ebx = (uint32_t)(c->edx); /* mov ebx, edx */
L_00b29cd3:;
    (void)sub32(c, c->ebx, c->eax); /* cmp ebx, eax */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 8], ebx */
    if (!c->cf) goto L_00b29cef; /* jae 0xb29cef */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov ecx, dword ptr [ebx + 4] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov edi, dword ptr [ebx] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & R32((uint32_t)(c->ebp + 0xfffffff8u))))); /* and ecx, dword ptr [ebp - 8] */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & c->esi))); /* and edi, esi */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->edi))); /* or ecx, edi */
    if (!c->zf) goto L_00b29ced; /* jne 0xb29ced */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x14u)); /* add ebx, 0x14 */
    goto L_00b29cd3; /* jmp 0xb29cd3 */
L_00b29ced:;
    (void)sub32(c, c->ebx, c->eax); /* cmp ebx, eax */
L_00b29cef:;
    if (!c->zf) goto L_00b29d4a; /* jne 0xb29d4a */
L_00b29cf1:;
    (void)sub32(c, c->ebx, R32((uint32_t)(c->ebp + 0xfffffffcu))); /* cmp ebx, dword ptr [ebp - 4] */
    if (!c->cf) goto L_00b29d07; /* jae 0xb29d07 */
    (void)sub32(c, R32((uint32_t)(c->ebx + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebx + 8], 0 */
    if (!c->zf) goto L_00b29d04; /* jne 0xb29d04 */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x14u)); /* add ebx, 0x14 */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 8], ebx */
    goto L_00b29cf1; /* jmp 0xb29cf1 */
L_00b29d04:;
    (void)sub32(c, c->ebx, R32((uint32_t)(c->ebp + 0xfffffffcu))); /* cmp ebx, dword ptr [ebp - 4] */
L_00b29d07:;
    if (!c->zf) goto L_00b29d2f; /* jne 0xb29d2f */
    c->ebx = (uint32_t)(c->edx); /* mov ebx, edx */
L_00b29d0b:;
    (void)sub32(c, c->ebx, c->eax); /* cmp ebx, eax */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 8], ebx */
    if (!c->cf) goto L_00b29d1f; /* jae 0xb29d1f */
    (void)sub32(c, R32((uint32_t)(c->ebx + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebx + 8], 0 */
    if (!c->zf) goto L_00b29d1d; /* jne 0xb29d1d */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x14u)); /* add ebx, 0x14 */
    goto L_00b29d0b; /* jmp 0xb29d0b */
L_00b29d1d:;
    (void)sub32(c, c->ebx, c->eax); /* cmp ebx, eax */
L_00b29d1f:;
    if (!c->zf) goto L_00b29d2f; /* jne 0xb29d2f */
    PUSH32(c, 0x00b29d26u); f_00b29f5e(c); /* call 0xb29f5e */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 8], ebx */
    if (c->zf) goto L_00b29d43; /* je 0xb29d43 */
L_00b29d2f:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b29d35u); f_00b2a00f(c); /* call 0xb2a00f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x10u))); /* mov ecx, dword ptr [ebx + 0x10] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x10u))); /* mov eax, dword ptr [ebx + 0x10] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xffffffffu); /* cmp dword ptr [eax], -1 */
    if (!c->zf) goto L_00b29d4a; /* jne 0xb29d4a */
L_00b29d43:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00b29f59; /* jmp 0xb29f59 */
L_00b29d4a:;
    W32((uint32_t)(0xb33a10u), (uint32_t)(c->ebx)); /* mov dword ptr [0x10013a10], ebx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x10u))); /* mov eax, dword ptr [ebx + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    (void)sub32(c, c->edx, (uint32_t)0xffffffffu); /* cmp edx, -1 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 4], edx */
    if (c->zf) goto L_00b29d71; /* je 0xb29d71 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + c->edx * 4 + 0xc4u))); /* mov ecx, dword ptr [eax + edx*4 + 0xc4] */
    c->edi = (uint32_t)(R32((uint32_t)(c->eax + c->edx * 4 + 0x44u))); /* mov edi, dword ptr [eax + edx*4 + 0x44] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & R32((uint32_t)(c->ebp + 0xfffffff8u))))); /* and ecx, dword ptr [ebp - 8] */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & c->esi))); /* and edi, esi */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->edi))); /* or ecx, edi */
    if (!c->zf) goto L_00b29da8; /* jne 0xb29da8 */
L_00b29d71:;
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0xc4u))); /* mov edx, dword ptr [eax + 0xc4] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + 0x44u))); /* mov esi, dword ptr [eax + 0x44] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & R32((uint32_t)(c->ebp + 0xfffffff8u))))); /* and edx, dword ptr [ebp - 8] */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & R32((uint32_t)(c->ebp + 0xfffffff4u))))); /* and esi, dword ptr [ebp - 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x44u)); /* lea ecx, [eax + 0x44] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx | c->esi))); /* or edx, esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov esi, dword ptr [ebp - 0xc] */
    if (!c->zf) goto L_00b29da5; /* jne 0xb29da5 */
L_00b29d8e:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x84u))); /* mov edx, dword ptr [ecx + 0x84] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & R32((uint32_t)(c->ebp + 0xfffffff8u))))); /* and edx, dword ptr [ebp - 8] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    c->edi = (uint32_t)(c->esi); /* mov edi, esi */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & R32((uint32_t)(c->ecx))))); /* and edi, dword ptr [ecx] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx | c->edi))); /* or edx, edi */
    if (c->zf) goto L_00b29d8e; /* je 0xb29d8e */
L_00b29da5:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov edx, dword ptr [ebp - 4] */
L_00b29da8:;
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    { int64_t r_ = (int64_t)(int32_t)c->ecx * (int32_t)(uint32_t)0x204u; c->ecx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul ecx, ecx, 0x204 */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->eax + 0x144u)); /* lea ecx, [ecx + eax + 0x144] */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 0xc], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + c->edx * 4 + 0x44u))); /* mov ecx, dword ptr [eax + edx*4 + 0x44] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & c->esi))); /* and ecx, esi */
    if (!c->zf) goto L_00b29dd1; /* jne 0xb29dd1 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + c->edx * 4 + 0xc4u))); /* mov ecx, dword ptr [eax + edx*4 + 0xc4] */
    { uint32_t v_ = 0x20u; PUSH32(c, v_); } /* push 0x20 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & R32((uint32_t)(c->ebp + 0xfffffff8u))))); /* and ecx, dword ptr [ebp - 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_00b29dd1:;
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if ((c->sf != c->of)) goto L_00b29dda; /* jl 0xb29dda */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 1)); /* shl ecx, 1 */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_00b29dd1; /* jmp 0xb29dd1 */
L_00b29dda:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + c->edi * 8 + 0x4u))); /* mov edx, dword ptr [ecx + edi*8 + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx))); /* mov ecx, dword ptr [edx] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, R32((uint32_t)(c->ebp + 0xfffffff0u)))); /* sub ecx, dword ptr [ebp - 0x10] */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
    c->esi = (uint32_t)(sar32(c, c->esi, 4)); /* sar esi, 4 */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    (void)sub32(c, c->esi, (uint32_t)0x3fu); /* cmp esi, 0x3f */
    if ((c->zf || c->sf != c->of)) goto L_00b29df7; /* jle 0xb29df7 */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00b29df7:;
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (c->zf) goto L_00b29f0c; /* je 0xb29f0c */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov ecx, dword ptr [edx + 4] */
    (void)sub32(c, c->ecx, R32((uint32_t)(c->edx + 0x8u))); /* cmp ecx, dword ptr [edx + 8] */
    if (!c->zf) goto L_00b29e68; /* jne 0xb29e68 */
    (void)sub32(c, c->edi, (uint32_t)0x20u); /* cmp edi, 0x20 */
    if ((c->sf == c->of)) goto L_00b29e37; /* jge 0xb29e37 */
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
    if (!c->zf) goto L_00b29e65; /* jne 0xb29e65 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov ecx, dword ptr [ebp - 0x14] */
    { uint32_t a_ = (uint32_t)(c->ebx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ecx)))); } /* and dword ptr [ebx], ecx */
    goto L_00b29e68; /* jmp 0xb29e68 */
L_00b29e37:;
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
    if (!c->zf) goto L_00b29e65; /* jne 0xb29e65 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov ecx, dword ptr [ebp - 0x14] */
    { uint32_t a_ = (uint32_t)(c->ebx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ecx)))); } /* and dword ptr [ebx + 4], ecx */
    goto L_00b29e68; /* jmp 0xb29e68 */
L_00b29e65:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00b29e68:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov ecx, dword ptr [edx + 8] */
    c->edi = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov edi, dword ptr [edx + 4] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 8], 0 */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->edi)); /* mov dword ptr [ecx + 4], edi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov ecx, dword ptr [edx + 4] */
    c->edi = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov edi, dword ptr [edx + 8] */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [ecx + 8], edi */
    if (c->zf) goto L_00b29f18; /* je 0xb29f18 */
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
    if (!c->zf) goto L_00b29f09; /* jne 0xb29f09 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + c->eax + 0x4u))); /* mov cl, byte ptr [esi + eax + 4] */
    (void)sub32(c, c->esi, (uint32_t)0x20u); /* cmp esi, 0x20 */
    W8((uint32_t)(c->ebp + 0xbu), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [ebp + 0xb], cl */
    if ((c->sf == c->of)) goto L_00b29eda; /* jge 0xb29eda */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(inc8(c, ((uint8_t)c->ecx))); /* inc cl */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xbu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0xb], 0 */
    W8((uint32_t)(c->esi + c->eax + 0x4u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esi + eax + 4], cl */
    if (!c->zf) goto L_00b29ec8; /* jne 0xb29ec8 */
    c->edi = (uint32_t)((uint32_t)0x80000000u); /* mov edi, 0x80000000 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->edi = (uint32_t)(shr32(c, c->edi, (c->ecx & 0xff))); /* shr edi, cl */
    { uint32_t a_ = (uint32_t)(c->ebx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edi)))); } /* or dword ptr [ebx], edi */
L_00b29ec8:;
    c->edi = (uint32_t)((uint32_t)0x80000000u); /* mov edi, 0x80000000 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->edi = (uint32_t)(shr32(c, c->edi, (c->ecx & 0xff))); /* shr edi, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    { uint32_t a_ = (uint32_t)(c->eax + c->ecx * 4 + 0x44u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edi)))); } /* or dword ptr [eax + ecx*4 + 0x44], edi */
    goto L_00b29f09; /* jmp 0xb29f09 */
L_00b29eda:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(inc8(c, ((uint8_t)c->ecx))); /* inc cl */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xbu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0xb], 0 */
    W8((uint32_t)(c->esi + c->eax + 0x4u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esi + eax + 4], cl */
    if (!c->zf) goto L_00b29ef3; /* jne 0xb29ef3 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0xffffffe0u)); /* lea ecx, [esi - 0x20] */
    c->edi = (uint32_t)((uint32_t)0x80000000u); /* mov edi, 0x80000000 */
    c->edi = (uint32_t)(shr32(c, c->edi, (c->ecx & 0xff))); /* shr edi, cl */
    { uint32_t a_ = (uint32_t)(c->ebx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edi)))); } /* or dword ptr [ebx + 4], edi */
L_00b29ef3:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->edi = (uint32_t)((uint32_t)(c->eax + c->ecx * 4 + 0xc4u)); /* lea edi, [eax + ecx*4 + 0xc4] */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0xffffffe0u)); /* lea ecx, [esi - 0x20] */
    c->esi = (uint32_t)((uint32_t)0x80000000u); /* mov esi, 0x80000000 */
    c->esi = (uint32_t)(shr32(c, c->esi, (c->ecx & 0xff))); /* shr esi, cl */
    { uint32_t a_ = (uint32_t)(c->edi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->esi)))); } /* or dword ptr [edi], esi */
L_00b29f09:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
L_00b29f0c:;
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00b29f1b; /* je 0xb29f1b */
    W32((uint32_t)(c->edx), (uint32_t)(c->ecx)); /* mov dword ptr [edx], ecx */
    W32((uint32_t)(c->ecx + c->edx + 0xfffffffcu), (uint32_t)(c->ecx)); /* mov dword ptr [ecx + edx - 4], ecx */
    goto L_00b29f1b; /* jmp 0xb29f1b */
L_00b29f18:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
L_00b29f1b:;
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
    if (!c->zf) goto L_00b29f51; /* jne 0xb29f51 */
    (void)sub32(c, c->ebx, R32((uint32_t)(0xb33a14u))); /* cmp ebx, dword ptr [0x10013a14] */
    if (!c->zf) goto L_00b29f51; /* jne 0xb29f51 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    (void)sub32(c, c->ecx, R32((uint32_t)(0xb33a0cu))); /* cmp ecx, dword ptr [0x10013a0c] */
    if (!c->zf) goto L_00b29f51; /* jne 0xb29f51 */
    { uint32_t a_ = (uint32_t)(0xb33a14u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [0x10013a14], 0 */
L_00b29f51:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->eax = (uint32_t)((uint32_t)(c->edx + 0x4u)); /* lea eax, [edx + 4] */
L_00b29f59:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b29f5e(CPU *c) { /* FUN_10009f5e */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0xb33a18u))); /* mov eax, dword ptr [0x10013a18] */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb33a08u))); /* mov ecx, dword ptr [0x10013a08] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->zf) goto L_00b29fa1; /* jne 0xb29fa1 */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->ecx * 4 + 0x50u)); /* lea eax, [ecx + ecx*4 + 0x50] */
    c->eax = (uint32_t)(shl32(c, c->eax, 2)); /* shl eax, 2 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(0xb33a1cu)); PUSH32(c, v_); } /* push dword ptr [0x10013a1c] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0xb33a24u)); PUSH32(c, v_); } /* push dword ptr [0x10013a24] */
    { uint32_t t_ = R32((uint32_t)(0xb2e038u)); PUSH32(c, 0x00b29f8cu); call_indirect(c, t_); } /* call dword ptr [0x1000e038] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (c->zf) goto L_00b29ff1; /* je 0xb29ff1 */
    { uint32_t a_ = (uint32_t)(0xb33a08u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x10u))); } /* add dword ptr [0x10013a08], 0x10 */
    W32((uint32_t)(0xb33a1cu), (uint32_t)(c->eax)); /* mov dword ptr [0x10013a1c], eax */
    c->eax = (uint32_t)(R32((uint32_t)(0xb33a18u))); /* mov eax, dword ptr [0x10013a18] */
L_00b29fa1:;
    c->ecx = (uint32_t)(R32((uint32_t)(0xb33a1cu))); /* mov ecx, dword ptr [0x10013a1c] */
    { uint32_t v_ = 0x41c4u; PUSH32(c, v_); } /* push 0x41c4 */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea eax, [eax + eax*4] */
    { uint32_t v_ = R32((uint32_t)(0xb33a24u)); PUSH32(c, v_); } /* push dword ptr [0x10013a24] */
    c->esi = (uint32_t)((uint32_t)(c->ecx + c->eax * 4)); /* lea esi, [ecx + eax*4] */
    { uint32_t t_ = R32((uint32_t)(0xb2e03cu)); PUSH32(c, 0x00b29fc0u); call_indirect(c, t_); } /* call dword ptr [0x1000e03c] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x10], eax */
    if (c->zf) goto L_00b29ff1; /* je 0xb29ff1 */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = 0x2000u; PUSH32(c, v_); } /* push 0x2000 */
    { uint32_t v_ = 0x100000u; PUSH32(c, v_); } /* push 0x100000 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0xb2e0b0u)); PUSH32(c, 0x00b29fdau); call_indirect(c, t_); } /* call dword ptr [0x1000e0b0] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xc], eax */
    if (!c->zf) goto L_00b29ff5; /* jne 0xb29ff5 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x10] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0xb33a24u)); PUSH32(c, v_); } /* push dword ptr [0x10013a24] */
    { uint32_t t_ = R32((uint32_t)(0xb2e05cu)); PUSH32(c, 0x00b29ff1u); call_indirect(c, t_); } /* call dword ptr [0x1000e05c] */
L_00b29ff1:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00b2a00c; /* jmp 0xb2a00c */
L_00b29ff5:;
    { uint32_t a_ = (uint32_t)(c->esi + 0x8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [esi + 8], 0xffffffff */
    W32((uint32_t)(c->esi), (uint32_t)(c->edi)); /* mov dword ptr [esi], edi */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 4], edi */
    { uint32_t a_ = (uint32_t)(0xb33a18u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [0x10013a18] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [eax], 0xffffffff */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00b2a00c:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b2a00f(CPU *c) { /* FUN_1000a00f */
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
L_00b2a021:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf != c->of)) goto L_00b2a02a; /* jl 0xb2a02a */
    c->eax = (uint32_t)(shl32(c, c->eax, 1)); /* shl eax, 1 */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    goto L_00b2a021; /* jmp 0xb2a021 */
L_00b2a02a:;
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)(uint32_t)0x204u; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, eax, 0x204 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->esi + 0x144u)); /* lea eax, [eax + esi + 0x144] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
L_00b2a03f:;
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [eax + 8], eax */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [eax + 4], eax */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
    c->edx = (uint32_t)(dec32(c, c->edx)); /* dec edx */
    if (!c->zf) goto L_00b2a03f; /* jne 0xb2a03f */
    c->edi = (uint32_t)(c->ebx); /* mov edi, ebx */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    c->edi = (uint32_t)(shl32(c, c->edi, 15)); /* shl edi, 0xf */
    c->edi = (uint32_t)(add32(c, c->edi, R32((uint32_t)(c->ecx + 0xcu)))); /* add edi, dword ptr [ecx + 0xc] */
    { uint32_t v_ = 0x1000u; PUSH32(c, v_); } /* push 0x1000 */
    { uint32_t v_ = 0x8000u; PUSH32(c, v_); } /* push 0x8000 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0xb2e0b0u)); PUSH32(c, 0x00b2a066u); call_indirect(c, t_); } /* call dword ptr [0x1000e0b0] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b2a072; /* jne 0xb2a072 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    goto L_00b2a105; /* jmp 0xb2a105 */
L_00b2a072:;
    c->edx = (uint32_t)((uint32_t)(c->edi + 0x7000u)); /* lea edx, [edi + 0x7000] */
    (void)sub32(c, c->edi, c->edx); /* cmp edi, edx */
    if ((!c->cf && !c->zf)) goto L_00b2a0b8; /* ja 0xb2a0b8 */
    c->eax = (uint32_t)((uint32_t)(c->edi + 0x10u)); /* lea eax, [edi + 0x10] */
L_00b2a07f:;
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
    if ((c->cf || c->zf)) goto L_00b2a07f; /* jbe 0xb2a07f */
L_00b2a0b8:;
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
    if (!c->zf) goto L_00b2a0f5; /* jne 0xb2a0f5 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edi)))); } /* or dword ptr [eax + 4], edi */
L_00b2a0f5:;
    c->edx = (uint32_t)((uint32_t)0x80000000u); /* mov edx, 0x80000000 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    c->edx = (uint32_t)(shr32(c, c->edx, (c->ecx & 0xff))); /* shr edx, cl */
    c->edx = (uint32_t)((uint32_t)~c->edx); /* not edx */
    { uint32_t a_ = (uint32_t)(c->eax + 0x8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->edx)))); } /* and dword ptr [eax + 8], edx */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
L_00b2a105:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b2a10a(CPU *c) { /* FUN_1000a10a */
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
    if ((c->zf || c->sf != c->of)) goto L_00b2a2b8; /* jle 0xb2a2b8 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x1u)); /* test bl, 1 */
    if (!c->zf) goto L_00b2a2b1; /* jne 0xb2a2b1 */
    c->ebx = (uint32_t)(add32(c, c->ebx, c->ecx)); /* add ebx, ecx */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if ((!c->zf && c->sf == c->of)) goto L_00b2a2b1; /* jg 0xb2a2b1 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 4)); /* sar ecx, 4 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    (void)sub32(c, c->ecx, (uint32_t)0x3fu); /* cmp ecx, 0x3f */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
    if ((c->cf || c->zf)) goto L_00b2a181; /* jbe 0xb2a181 */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
L_00b2a181:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov ebx, dword ptr [edi + 4] */
    (void)sub32(c, c->ebx, R32((uint32_t)(c->edi + 0x8u))); /* cmp ebx, dword ptr [edi + 8] */
    if (!c->zf) goto L_00b2a1d1; /* jne 0xb2a1d1 */
    (void)sub32(c, c->ecx, (uint32_t)0x20u); /* cmp ecx, 0x20 */
    if (!c->cf) goto L_00b2a1ad; /* jae 0xb2a1ad */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->eax + 0x4u)); /* lea ecx, [ecx + eax + 4] */
    c->ebx = (uint32_t)((uint32_t)~c->ebx); /* not ebx */
    { uint32_t a_ = (uint32_t)(c->eax + c->edx * 4 + 0x44u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [eax + edx*4 + 0x44], ebx */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(dec8(c, R8(a_)))); } /* dec byte ptr [ecx] */
    if (!c->zf) goto L_00b2a1d1; /* jne 0xb2a1d1 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [ecx], ebx */
    goto L_00b2a1d1; /* jmp 0xb2a1d1 */
L_00b2a1ad:;
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0xffffffe0u)); /* add ecx, -0x20 */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->eax + 0x4u)); /* lea ecx, [ecx + eax + 4] */
    c->ebx = (uint32_t)((uint32_t)~c->ebx); /* not ebx */
    { uint32_t a_ = (uint32_t)(c->eax + c->edx * 4 + 0xc4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [eax + edx*4 + 0xc4], ebx */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(dec8(c, R8(a_)))); } /* dec byte ptr [ecx] */
    if (!c->zf) goto L_00b2a1d1; /* jne 0xb2a1d1 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [ecx + 4], ebx */
L_00b2a1d1:;
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
    if ((c->zf || c->sf != c->of)) goto L_00b2a29f; /* jle 0xb2a29f */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov edi, dword ptr [ebp - 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    c->edi = (uint32_t)(sar32(c, c->edi, 4)); /* sar edi, 4 */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->esi + 0xfffffffcu)); /* lea ecx, [ecx + esi - 4] */
    (void)sub32(c, c->edi, (uint32_t)0x3fu); /* cmp edi, 0x3f */
    if ((c->cf || c->zf)) goto L_00b2a20b; /* jbe 0xb2a20b */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_00b2a20b:;
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
    if (!c->zf) goto L_00b2a28d; /* jne 0xb2a28d */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi + c->eax + 0x4u))); /* mov cl, byte ptr [edi + eax + 4] */
    (void)sub32(c, c->edi, (uint32_t)0x20u); /* cmp edi, 0x20 */
    W8((uint32_t)(c->ebp + 0x13u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [ebp + 0x13], cl */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(inc8(c, ((uint8_t)c->ecx))); /* inc cl */
    W8((uint32_t)(c->edi + c->eax + 0x4u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [edi + eax + 4], cl */
    if (!c->cf) goto L_00b2a264; /* jae 0xb2a264 */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x13u)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0x13], 0 */
    if (!c->zf) goto L_00b2a257; /* jne 0xb2a257 */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->ebx)))); } /* or dword ptr [ecx], ebx */
L_00b2a257:;
    c->eax = (uint32_t)((uint32_t)(c->eax + c->edx * 4 + 0x44u)); /* lea eax, [eax + edx*4 + 0x44] */
    c->edx = (uint32_t)((uint32_t)0x80000000u); /* mov edx, 0x80000000 */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    goto L_00b2a289; /* jmp 0xb2a289 */
L_00b2a264:;
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x13u)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0x13], 0 */
    if (!c->zf) goto L_00b2a27a; /* jne 0xb2a27a */
    c->ecx = (uint32_t)((uint32_t)(c->edi + 0xffffffe0u)); /* lea ecx, [edi - 0x20] */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->ebx)))); } /* or dword ptr [ecx + 4], ebx */
L_00b2a27a:;
    c->eax = (uint32_t)((uint32_t)(c->eax + c->edx * 4 + 0xc4u)); /* lea eax, [eax + edx*4 + 0xc4] */
    c->ecx = (uint32_t)((uint32_t)(c->edi + 0xffffffe0u)); /* lea ecx, [edi - 0x20] */
    c->edx = (uint32_t)((uint32_t)0x80000000u); /* mov edx, 0x80000000 */
L_00b2a289:;
    c->edx = (uint32_t)(shr32(c, c->edx, (c->ecx & 0xff))); /* shr edx, cl */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edx)))); } /* or dword ptr [eax], edx */
L_00b2a28d:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->eax = (uint32_t)((uint32_t)(c->edx + c->esi + 0xfffffffcu)); /* lea eax, [edx + esi - 4] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    W32((uint32_t)(c->ecx + c->eax + 0xfffffffcu), (uint32_t)(c->ecx)); /* mov dword ptr [ecx + eax - 4], ecx */
    goto L_00b2a2a2; /* jmp 0xb2a2a2 */
L_00b2a29f:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
L_00b2a2a2:;
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x1u)); /* lea eax, [esi + 1] */
    W32((uint32_t)(c->edx + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edx - 4], eax */
    W32((uint32_t)(c->edx + c->esi + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edx + esi - 8], eax */
    goto L_00b2a3f8; /* jmp 0xb2a3f8 */
L_00b2a2b1:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00b2a3fb; /* jmp 0xb2a3fb */
L_00b2a2b8:;
    if ((c->sf == c->of)) goto L_00b2a3f8; /* jge 0xb2a3f8 */
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
    if ((c->cf || c->zf)) goto L_00b2a2e3; /* jbe 0xb2a2e3 */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00b2a2e3:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffcu)) & (uint8_t)0x1u)); /* test byte ptr [ebp - 4], 1 */
    if (!c->zf) goto L_00b2a372; /* jne 0xb2a372 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov esi, dword ptr [ebp - 4] */
    c->esi = (uint32_t)(sar32(c, c->esi, 4)); /* sar esi, 4 */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    (void)sub32(c, c->esi, (uint32_t)0x3fu); /* cmp esi, 0x3f */
    if ((c->cf || c->zf)) goto L_00b2a2fc; /* jbe 0xb2a2fc */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00b2a2fc:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov ecx, dword ptr [edi + 4] */
    (void)sub32(c, c->ecx, R32((uint32_t)(c->edi + 0x8u))); /* cmp ecx, dword ptr [edi + 8] */
    if (!c->zf) goto L_00b2a34b; /* jne 0xb2a34b */
    (void)sub32(c, c->esi, (uint32_t)0x20u); /* cmp esi, 0x20 */
    if (!c->cf) goto L_00b2a327; /* jae 0xb2a327 */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->esi = (uint32_t)((uint32_t)(c->esi + c->eax + 0x4u)); /* lea esi, [esi + eax + 4] */
    c->ebx = (uint32_t)((uint32_t)~c->ebx); /* not ebx */
    { uint32_t a_ = (uint32_t)(c->eax + c->edx * 4 + 0x44u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [eax + edx*4 + 0x44], ebx */
    { uint32_t a_ = (uint32_t)(c->esi); W8(a_, (uint8_t)(dec8(c, R8(a_)))); } /* dec byte ptr [esi] */
    if (!c->zf) goto L_00b2a348; /* jne 0xb2a348 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [ecx], ebx */
    goto L_00b2a348; /* jmp 0xb2a348 */
L_00b2a327:;
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0xffffffe0u)); /* lea ecx, [esi - 0x20] */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->ecx = (uint32_t)((uint32_t)(c->esi + c->eax + 0x4u)); /* lea ecx, [esi + eax + 4] */
    c->ebx = (uint32_t)((uint32_t)~c->ebx); /* not ebx */
    { uint32_t a_ = (uint32_t)(c->eax + c->edx * 4 + 0xc4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [eax + edx*4 + 0xc4], ebx */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(dec8(c, R8(a_)))); } /* dec byte ptr [ecx] */
    if (!c->zf) goto L_00b2a348; /* jne 0xb2a348 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [ecx + 4], ebx */
L_00b2a348:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ebx, dword ptr [ebp + 0xc] */
L_00b2a34b:;
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
    if ((c->cf || c->zf)) goto L_00b2a372; /* jbe 0xb2a372 */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00b2a372:;
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
    if (!c->zf) goto L_00b2a3ef; /* jne 0xb2a3ef */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + c->eax + 0x4u))); /* mov cl, byte ptr [esi + eax + 4] */
    (void)sub32(c, c->esi, (uint32_t)0x20u); /* cmp esi, 0x20 */
    W8((uint32_t)(c->ebp + 0xfu), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [ebp + 0xf], cl */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(inc8(c, ((uint8_t)c->ecx))); /* inc cl */
    W8((uint32_t)(c->esi + c->eax + 0x4u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esi + eax + 4], cl */
    if (!c->cf) goto L_00b2a3c6; /* jae 0xb2a3c6 */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xfu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0xf], 0 */
    if (!c->zf) goto L_00b2a3b9; /* jne 0xb2a3b9 */
    c->edi = (uint32_t)((uint32_t)0x80000000u); /* mov edi, 0x80000000 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->edi = (uint32_t)(shr32(c, c->edi, (c->ecx & 0xff))); /* shr edi, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edi)))); } /* or dword ptr [ecx], edi */
L_00b2a3b9:;
    c->eax = (uint32_t)((uint32_t)(c->eax + c->edx * 4 + 0x44u)); /* lea eax, [eax + edx*4 + 0x44] */
    c->edx = (uint32_t)((uint32_t)0x80000000u); /* mov edx, 0x80000000 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    goto L_00b2a3eb; /* jmp 0xb2a3eb */
L_00b2a3c6:;
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xfu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0xf], 0 */
    if (!c->zf) goto L_00b2a3dc; /* jne 0xb2a3dc */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0xffffffe0u)); /* lea ecx, [esi - 0x20] */
    c->edi = (uint32_t)((uint32_t)0x80000000u); /* mov edi, 0x80000000 */
    c->edi = (uint32_t)(shr32(c, c->edi, (c->ecx & 0xff))); /* shr edi, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edi)))); } /* or dword ptr [ecx + 4], edi */
L_00b2a3dc:;
    c->eax = (uint32_t)((uint32_t)(c->eax + c->edx * 4 + 0xc4u)); /* lea eax, [eax + edx*4 + 0xc4] */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0xffffffe0u)); /* lea ecx, [esi - 0x20] */
    c->edx = (uint32_t)((uint32_t)0x80000000u); /* mov edx, 0x80000000 */
L_00b2a3eb:;
    c->edx = (uint32_t)(shr32(c, c->edx, (c->ecx & 0xff))); /* shr edx, cl */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edx)))); } /* or dword ptr [eax], edx */
L_00b2a3ef:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
    W32((uint32_t)(c->eax + c->ebx + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [eax + ebx - 4], eax */
L_00b2a3f8:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00b2a3fb:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b2a400(CPU *c) { /* FUN_1000a400 */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(0xb309d8u)), (uint32_t)0xffffffffu); /* cmp dword ptr [0x100109d8], -1 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00b2a414; /* jne 0xb2a414 */
    c->esi = (uint32_t)((uint32_t)0xb309c8u); /* mov esi, 0x100109c8 */
    goto L_00b2a431; /* jmp 0xb2a431 */
L_00b2a414:;
    { uint32_t v_ = 0x2020u; PUSH32(c, v_); } /* push 0x2020 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb33a24u)); PUSH32(c, v_); } /* push dword ptr [0x10013a24] */
    { uint32_t t_ = R32((uint32_t)(0xb2e03cu)); PUSH32(c, 0x00b2a427u); call_indirect(c, t_); } /* call dword ptr [0x1000e03c] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00b2a53d; /* je 0xb2a53d */
L_00b2a431:;
    c->ebp = (uint32_t)(R32((uint32_t)(0xb2e0b0u))); /* mov ebp, dword ptr [0x1000e0b0] */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = 0x2000u; PUSH32(c, v_); } /* push 0x2000 */
    { uint32_t v_ = 0x400000u; PUSH32(c, v_); } /* push 0x400000 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t t_ = c->ebp; PUSH32(c, 0x00b2a447u); call_indirect(c, t_); } /* call ebp */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00b2a526; /* je 0xb2a526 */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    c->ebx = (uint32_t)((uint32_t)0x10000u); /* mov ebx, 0x10000 */
    { uint32_t v_ = 0x1000u; PUSH32(c, v_); } /* push 0x1000 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = c->ebp; PUSH32(c, 0x00b2a461u); call_indirect(c, t_); } /* call ebp */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b2a518; /* je 0xb2a518 */
    c->eax = (uint32_t)((uint32_t)0xb309c8u); /* mov eax, 0x100109c8 */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if (!c->zf) goto L_00b2a490; /* jne 0xb2a490 */
    (void)sub32(c, R32((uint32_t)(0xb309c8u)), (uint32_t)0x0u); /* cmp dword ptr [0x100109c8], 0 */
    if (!c->zf) goto L_00b2a480; /* jne 0xb2a480 */
    W32((uint32_t)(0xb309c8u), (uint32_t)(c->eax)); /* mov dword ptr [0x100109c8], eax */
L_00b2a480:;
    (void)sub32(c, R32((uint32_t)(0xb309ccu)), (uint32_t)0x0u); /* cmp dword ptr [0x100109cc], 0 */
    if (!c->zf) goto L_00b2a4a5; /* jne 0xb2a4a5 */
    W32((uint32_t)(0xb309ccu), (uint32_t)(c->eax)); /* mov dword ptr [0x100109cc], eax */
    goto L_00b2a4a5; /* jmp 0xb2a4a5 */
L_00b2a490:;
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    c->eax = (uint32_t)(R32((uint32_t)(0xb309ccu))); /* mov eax, dword ptr [0x100109cc] */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 4], eax */
    W32((uint32_t)(0xb309ccu), (uint32_t)(c->esi)); /* mov dword ptr [0x100109cc], esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    W32((uint32_t)(c->eax), (uint32_t)(c->esi)); /* mov dword ptr [eax], esi */
L_00b2a4a5:;
    c->eax = (uint32_t)((uint32_t)(c->edi + 0x400000u)); /* lea eax, [edi + 0x400000] */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x98u)); /* lea ecx, [esi + 0x98] */
    W32((uint32_t)(c->esi + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x14], eax */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x18u)); /* lea eax, [esi + 0x18] */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 0xc], ecx */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0x10], edi */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 8], eax */
    c->ebp = (uint32_t)(logic32(c, 0)); /* xor ebp, ebp */
    c->ecx = (uint32_t)((uint32_t)0xf1u); /* mov ecx, 0xf1 */
L_00b2a4c7:;
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
    if ((c->sf != c->of)) goto L_00b2a4c7; /* jl 0xb2a4c7 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b2a4edu); f_00b2bd50(c); /* call 0xb2bd50 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_00b2a4f0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(add32(c, c->eax, c->ebx)); /* add eax, ebx */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (!c->cf) goto L_00b2a514; /* jae 0xb2a514 */
    { uint32_t a_ = (uint32_t)(c->edi + 0xf8u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0xffu)))); } /* or byte ptr [edi + 0xf8], 0xff */
    c->eax = (uint32_t)((uint32_t)(c->edi + 0x8u)); /* lea eax, [edi + 8] */
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    W32((uint32_t)(c->edi + 0x4u), (uint32_t)((uint32_t)0xf0u)); /* mov dword ptr [edi + 4], 0xf0 */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x1000u)); /* add edi, 0x1000 */
    goto L_00b2a4f0; /* jmp 0xb2a4f0 */
L_00b2a514:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    goto L_00b2a53f; /* jmp 0xb2a53f */
L_00b2a518:;
    { uint32_t v_ = 0x8000u; PUSH32(c, v_); } /* push 0x8000 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0xb2e09cu)); PUSH32(c, 0x00b2a526u); call_indirect(c, t_); } /* call dword ptr [0x1000e09c] */
L_00b2a526:;
    (void)sub32(c, c->esi, (uint32_t)0xb309c8u); /* cmp esi, 0x100109c8 */
    if (c->zf) goto L_00b2a53d; /* je 0xb2a53d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xb33a24u)); PUSH32(c, v_); } /* push dword ptr [0x10013a24] */
    { uint32_t t_ = R32((uint32_t)(0xb2e05cu)); PUSH32(c, 0x00b2a53du); call_indirect(c, t_); } /* call dword ptr [0x1000e05c] */
L_00b2a53d:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00b2a53f:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00b2a544(CPU *c) { /* FUN_1000a544 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    { uint32_t v_ = 0x8000u; PUSH32(c, v_); } /* push 0x8000 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x10] */
    { uint32_t t_ = R32((uint32_t)(0xb2e09cu)); PUSH32(c, 0x00b2a559u); call_indirect(c, t_); } /* call dword ptr [0x1000e09c] */
    (void)sub32(c, R32((uint32_t)(0xb329e8u)), c->esi); /* cmp dword ptr [0x100129e8], esi */
    if (!c->zf) goto L_00b2a569; /* jne 0xb2a569 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    W32((uint32_t)(0xb329e8u), (uint32_t)(c->eax)); /* mov dword ptr [0x100129e8], eax */
L_00b2a569:;
    (void)sub32(c, c->esi, (uint32_t)0xb309c8u); /* cmp esi, 0x100109c8 */
    if (c->zf) goto L_00b2a591; /* je 0xb2a591 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 4], ecx */
    { uint32_t v_ = R32((uint32_t)(0xb33a24u)); PUSH32(c, v_); } /* push dword ptr [0x10013a24] */
    { uint32_t t_ = R32((uint32_t)(0xb2e05cu)); PUSH32(c, 0x00b2a58fu); call_indirect(c, t_); } /* call dword ptr [0x1000e05c] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_00b2a591:;
    { uint32_t a_ = (uint32_t)(0xb309d8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [0x100109d8], 0xffffffff */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b2a59a(CPU *c) { /* FUN_1000a59a */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(0xb309ccu))); /* mov esi, dword ptr [0x100109cc] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
L_00b2a5a7:;
    (void)sub32(c, R32((uint32_t)(c->esi + 0x10u)), (uint32_t)0xffffffffu); /* cmp dword ptr [esi + 0x10], -1 */
    if (c->zf) goto L_00b2a645; /* je 0xb2a645 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x2010u)); /* lea edi, [esi + 0x2010] */
    c->ebx = (uint32_t)((uint32_t)0x3ff000u); /* mov ebx, 0x3ff000 */
L_00b2a5c0:;
    (void)sub32(c, R32((uint32_t)(c->edi)), (uint32_t)0xf0u); /* cmp dword ptr [edi], 0xf0 */
    if (!c->zf) goto L_00b2a601; /* jne 0xb2a601 */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = 0x4000u; PUSH32(c, v_); } /* push 0x4000 */
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->esi + 0x10u)))); /* add eax, dword ptr [esi + 0x10] */
    { uint32_t v_ = 0x1000u; PUSH32(c, v_); } /* push 0x1000 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0xb2e09cu)); PUSH32(c, 0x00b2a5deu); call_indirect(c, t_); } /* call dword ptr [0x1000e09c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b2a601; /* je 0xb2a601 */
    { uint32_t a_ = (uint32_t)(c->edi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [edi], 0xffffffff */
    { uint32_t a_ = (uint32_t)(0xb33640u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [0x10013640] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b2a5f6; /* je 0xb2a5f6 */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if ((c->cf || c->zf)) goto L_00b2a5f9; /* jbe 0xb2a5f9 */
L_00b2a5f6:;
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0xc], edi */
L_00b2a5f9:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 8] */
    if (c->zf) goto L_00b2a60e; /* je 0xb2a60e */
L_00b2a601:;
    c->ebx = (uint32_t)(sub32(c, c->ebx, (uint32_t)0x1000u)); /* sub ebx, 0x1000 */
    c->edi = (uint32_t)(sub32(c, c->edi, (uint32_t)0x8u)); /* sub edi, 8 */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if ((c->sf == c->of)) goto L_00b2a5c0; /* jge 0xb2a5c0 */
L_00b2a60e:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov esi, dword ptr [esi + 4] */
    if (c->zf) goto L_00b2a645; /* je 0xb2a645 */
    (void)sub32(c, R32((uint32_t)(c->ecx + 0x18u)), (uint32_t)0xffffffffu); /* cmp dword ptr [ecx + 0x18], -1 */
    if (!c->zf) goto L_00b2a645; /* jne 0xb2a645 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0x20u)); /* lea eax, [ecx + 0x20] */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
L_00b2a625:;
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xffffffffu); /* cmp dword ptr [eax], -1 */
    if (!c->zf) goto L_00b2a636; /* jne 0xb2a636 */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
    (void)sub32(c, c->edx, (uint32_t)0x400u); /* cmp edx, 0x400 */
    if ((c->sf != c->of)) goto L_00b2a625; /* jl 0xb2a625 */
L_00b2a636:;
    (void)sub32(c, c->edx, (uint32_t)0x400u); /* cmp edx, 0x400 */
    if (!c->zf) goto L_00b2a645; /* jne 0xb2a645 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00b2a644u); f_00b2a544(c); /* call 0xb2a544 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b2a645:;
    (void)sub32(c, c->esi, R32((uint32_t)(0xb309ccu))); /* cmp esi, dword ptr [0x100109cc] */
    if (c->zf) goto L_00b2a657; /* je 0xb2a657 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_00b2a5a7; /* jg 0xb2a5a7 */
L_00b2a657:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b2a65c(CPU *c) { /* FUN_1000a65c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->edx = (uint32_t)((uint32_t)0xb309c8u); /* mov edx, 0x100109c8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
L_00b2a668:;
    (void)sub32(c, c->eax, R32((uint32_t)(c->ecx + 0x10u))); /* cmp eax, dword ptr [ecx + 0x10] */
    if ((c->cf || c->zf)) goto L_00b2a672; /* jbe 0xb2a672 */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ecx + 0x14u))); /* cmp eax, dword ptr [ecx + 0x14] */
    if (c->cf) goto L_00b2a67a; /* jb 0xb2a67a */
L_00b2a672:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov ecx, dword ptr [ecx] */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if (c->zf) goto L_00b2a6af; /* je 0xb2a6af */
    goto L_00b2a668; /* jmp 0xb2a668 */
L_00b2a67a:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfu)); /* test al, 0xf */
    if (!c->zf) goto L_00b2a6af; /* jne 0xb2a6af */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->edx = (uint32_t)((uint32_t)0x100u); /* mov edx, 0x100 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffu))); /* and esi, 0xfff */
    (void)sub32(c, c->esi, c->edx); /* cmp esi, edx */
    if (c->cf) goto L_00b2a6af; /* jb 0xb2a6af */
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
L_00b2a6af:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b2a6b3(CPU *c) { /* FUN_1000a6b3 */
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
    if (!c->zf) goto L_00b2a6f7; /* jne 0xb2a6f7 */
    { uint32_t a_ = (uint32_t)(0xb33640u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [0x10013640] */
    (void)sub32(c, R32((uint32_t)(0xb33640u)), (uint32_t)0x20u); /* cmp dword ptr [0x10013640], 0x20 */
    if (!c->zf) goto L_00b2a6f7; /* jne 0xb2a6f7 */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    PUSH32(c, 0x00b2a6f6u); f_00b2a59a(c); /* call 0xb2a59a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b2a6f7:;
    c->esp += 4; return; /* ret  */
}

void f_00b2a6f8(CPU *c) { /* FUN_1000a6f8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(0xb329e8u))); /* mov esi, dword ptr [0x100129e8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
L_00b2a706:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov edx, dword ptr [esi + 0x10] */
    (void)sub32(c, c->edx, (uint32_t)0xffffffffu); /* cmp edx, -1 */
    if (c->zf) goto L_00b2a7b1; /* je 0xb2a7b1 */
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
    if (!c->cf) goto L_00b2a76b; /* jae 0xb2a76b */
L_00b2a731:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi))); /* mov ecx, dword ptr [edi] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    (void)sub32(c, c->ecx, c->ebx); /* cmp ecx, ebx */
    if ((c->sf != c->of)) goto L_00b2a754; /* jl 0xb2a754 */
    (void)sub32(c, R32((uint32_t)(c->edi + 0x4u)), c->ebx); /* cmp dword ptr [edi + 4], ebx */
    if ((c->cf || c->zf)) goto L_00b2a754; /* jbe 0xb2a754 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2a747u); f_00b2a900(c); /* call 0xb2a900 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b2a7c3; /* jne 0xb2a7c3 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    W32((uint32_t)(c->edi + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [edi + 4], ebx */
L_00b2a754:;
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x8u)); /* add edi, 8 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x2018u)); /* lea ecx, [esi + 0x2018] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x1000u)); /* add eax, 0x1000 */
    (void)sub32(c, c->edi, c->ecx); /* cmp edi, ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    if (c->cf) goto L_00b2a731; /* jb 0xb2a731 */
    goto L_00b2a76e; /* jmp 0xb2a76e */
L_00b2a76b:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00b2a76e:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x18u)); /* lea edi, [esi + 0x18] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 4], ecx */
    if (!c->cf) goto L_00b2a7b4; /* jae 0xb2a7b4 */
L_00b2a781:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if ((c->sf != c->of)) goto L_00b2a7a0; /* jl 0xb2a7a0 */
    (void)sub32(c, R32((uint32_t)(c->edi + 0x4u)), c->ebx); /* cmp dword ptr [edi + 4], ebx */
    if ((c->cf || c->zf)) goto L_00b2a7a0; /* jbe 0xb2a7a0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    PUSH32(c, 0x00b2a796u); f_00b2a900(c); /* call 0xb2a900 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b2a7c3; /* jne 0xb2a7c3 */
    W32((uint32_t)(c->edi + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [edi + 4], ebx */
L_00b2a7a0:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x1000u))); } /* add dword ptr [ebp - 4], 0x1000 */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x8u)); /* add edi, 8 */
    (void)sub32(c, c->edi, R32((uint32_t)(c->ebp + 0xfffffff8u))); /* cmp edi, dword ptr [ebp - 8] */
    if (c->cf) goto L_00b2a781; /* jb 0xb2a781 */
    goto L_00b2a7b4; /* jmp 0xb2a7b4 */
L_00b2a7b1:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00b2a7b4:;
    c->esi = (uint32_t)(R32((uint32_t)(c->esi))); /* mov esi, dword ptr [esi] */
    (void)sub32(c, c->esi, R32((uint32_t)(0xb329e8u))); /* cmp esi, dword ptr [0x100129e8] */
    if (c->zf) goto L_00b2a7d3; /* je 0xb2a7d3 */
    goto L_00b2a706; /* jmp 0xb2a706 */
L_00b2a7c3:;
    W32((uint32_t)(0xb329e8u), (uint32_t)(c->esi)); /* mov dword ptr [0x100129e8], esi */
    { uint32_t a_ = (uint32_t)(c->edi); W32(a_, (uint32_t)(sub32(c, R32(a_), c->ebx))); } /* sub dword ptr [edi], ebx */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 8], edi */
    goto L_00b2a8fb; /* jmp 0xb2a8fb */
L_00b2a7d3:;
    c->eax = (uint32_t)((uint32_t)0xb309c8u); /* mov eax, 0x100109c8 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
L_00b2a7da:;
    (void)sub32(c, R32((uint32_t)(c->edi + 0x10u)), (uint32_t)0xffffffffu); /* cmp dword ptr [edi + 0x10], -1 */
    if (c->zf) goto L_00b2a7e6; /* je 0xb2a7e6 */
    (void)sub32(c, R32((uint32_t)(c->edi + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [edi + 0xc], 0 */
    if (!c->zf) goto L_00b2a7f2; /* jne 0xb2a7f2 */
L_00b2a7e6:;
    c->edi = (uint32_t)(R32((uint32_t)(c->edi))); /* mov edi, dword ptr [edi] */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->zf) goto L_00b2a8c7; /* je 0xb2a8c7 */
    goto L_00b2a7da; /* jmp 0xb2a7da */
L_00b2a7f2:;
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
    if (!c->zf) goto L_00b2a821; /* jne 0xb2a821 */
L_00b2a810:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x10u); /* cmp dword ptr [ebp - 4], 0x10 */
    if ((c->sf == c->of)) goto L_00b2a821; /* jge 0xb2a821 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xffffffffu); /* cmp dword ptr [eax], -1 */
    if (c->zf) goto L_00b2a810; /* je 0xb2a810 */
L_00b2a821:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    c->eax = (uint32_t)(shl32(c, c->eax, 12)); /* shl eax, 0xc */
    { uint32_t v_ = 0x1000u; PUSH32(c, v_); } /* push 0x1000 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    { uint32_t t_ = R32((uint32_t)(0xb2e0b0u)); PUSH32(c, 0x00b2a839u); call_indirect(c, t_); } /* call dword ptr [0x1000e0b0] */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (!c->zf) goto L_00b2a8f9; /* jne 0xb2a8f9 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffff8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b2a84cu); f_00b2bd50(c); /* call 0xb2bd50 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov edx, dword ptr [ebp - 4] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    if ((c->zf || c->sf != c->of)) goto L_00b2a888; /* jle 0xb2a888 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x4u)); /* lea eax, [esi + 4] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 4], edx */
L_00b2a85e:;
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
    if (!c->zf) goto L_00b2a85e; /* jne 0xb2a85e */
L_00b2a888:;
    W32((uint32_t)(0xb329e8u), (uint32_t)(c->edi)); /* mov dword ptr [0x100129e8], edi */
    c->eax = (uint32_t)((uint32_t)(c->edi + 0x2018u)); /* lea eax, [edi + 0x2018] */
L_00b2a894:;
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
    if (!c->cf) goto L_00b2a8a4; /* jae 0xb2a8a4 */
    (void)sub32(c, R32((uint32_t)(c->ecx)), (uint32_t)0xffffffffu); /* cmp dword ptr [ecx], -1 */
    if (c->zf) goto L_00b2a8a2; /* je 0xb2a8a2 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x8u)); /* add ecx, 8 */
    goto L_00b2a894; /* jmp 0xb2a894 */
L_00b2a8a2:;
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
L_00b2a8a4:;
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
    goto L_00b2a8fb; /* jmp 0xb2a8fb */
L_00b2a8c7:;
    PUSH32(c, 0x00b2a8ccu); f_00b2a400(c); /* call 0xb2a400 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b2a8f9; /* je 0xb2a8f9 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x10u))); /* mov ecx, dword ptr [eax + 0x10] */
    W8((uint32_t)(c->ecx + 0x8u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ecx + 8], bl */
    c->edx = (uint32_t)((uint32_t)(c->ecx + c->ebx + 0x8u)); /* lea edx, [ecx + ebx + 8] */
    W32((uint32_t)(0xb329e8u), (uint32_t)(c->eax)); /* mov dword ptr [0x100129e8], eax */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    c->edx = (uint32_t)((uint32_t)0xf0u); /* mov edx, 0xf0 */
    c->edx = (uint32_t)(sub32(c, c->edx, c->ebx)); /* sub edx, ebx */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 4], edx */
    c->edx = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx edx, bl */
    { uint32_t a_ = (uint32_t)(c->eax + 0x18u); W32(a_, (uint32_t)(sub32(c, R32(a_), c->edx))); } /* sub dword ptr [eax + 0x18], edx */
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0x100u)); /* lea eax, [ecx + 0x100] */
    goto L_00b2a8fb; /* jmp 0xb2a8fb */
L_00b2a8f9:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00b2a8fb:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b2a900(CPU *c) { /* FUN_1000a900 */
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
    if (c->cf) goto L_00b2a945; /* jb 0xb2a945 */
    c->eax = (uint32_t)((uint32_t)(c->edi + c->edx)); /* lea eax, [edi + edx] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [edi], dl */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (!c->cf) goto L_00b2a934; /* jae 0xb2a934 */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(add32(c, R32(a_), c->edx))); } /* add dword ptr [ecx], edx */
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(sub32(c, R32(a_), c->edx))); } /* sub dword ptr [ecx + 4], edx */
    goto L_00b2a93d; /* jmp 0xb2a93d */
L_00b2a934:;
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ecx + 4], 0 */
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0x8u)); /* lea eax, [ecx + 8] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
L_00b2a93d:;
    c->eax = (uint32_t)((uint32_t)(c->edi + 0x8u)); /* lea eax, [edi + 8] */
    goto L_00b2aa13; /* jmp 0xb2aa13 */
L_00b2a945:;
    c->esi = (uint32_t)(add32(c, c->esi, c->edi)); /* add esi, edi */
    (void)sub8(c, R8((uint32_t)(c->esi)), (uint8_t)0x0u); /* cmp byte ptr [esi], 0 */
    if (c->zf) goto L_00b2a94e; /* je 0xb2a94e */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00b2a94e:;
    c->esi = (uint32_t)((uint32_t)(c->eax + c->edx)); /* lea esi, [eax + edx] */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (!c->cf) goto L_00b2a998; /* jae 0xb2a998 */
L_00b2a955:;
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov bl, byte ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & ((uint8_t)c->ebx))); /* test bl, bl */
    if (!c->zf) goto L_00b2a98b; /* jne 0xb2a98b */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ebx = (uint32_t)((uint32_t)(c->eax + 0x1u)); /* lea ebx, [eax + 1] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00b2a961:;
    (void)sub8(c, R8((uint32_t)(c->ebx)), (uint8_t)0x0u); /* cmp byte ptr [ebx], 0 */
    if (!c->zf) goto L_00b2a96a; /* jne 0xb2a96a */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    goto L_00b2a961; /* jmp 0xb2a961 */
L_00b2a96a:;
    (void)sub32(c, c->esi, c->edx); /* cmp esi, edx */
    if (!c->cf) goto L_00b2a9bc; /* jae 0xb2a9bc */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xfffffffcu))); /* cmp eax, dword ptr [ebp - 4] */
    if (!c->zf) goto L_00b2a978; /* jne 0xb2a978 */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [ecx + 4], esi */
    goto L_00b2a984; /* jmp 0xb2a984 */
L_00b2a978:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(sub32(c, R32(a_), c->esi))); } /* sub dword ptr [ebp + 0xc], esi */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->edx); /* cmp dword ptr [ebp + 0xc], edx */
    if (c->cf) goto L_00b2aa1d; /* jb 0xb2aa1d */
L_00b2a984:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov edi, dword ptr [ebp - 4] */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    goto L_00b2a990; /* jmp 0xb2a990 */
L_00b2a98b:;
    c->esi = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx esi, bl */
    c->eax = (uint32_t)(add32(c, c->eax, c->esi)); /* add eax, esi */
L_00b2a990:;
    c->esi = (uint32_t)((uint32_t)(c->eax + c->edx)); /* lea esi, [eax + edx] */
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0x8u))); /* cmp esi, dword ptr [ebp + 8] */
    if (c->cf) goto L_00b2a955; /* jb 0xb2a955 */
L_00b2a998:;
    c->esi = (uint32_t)((uint32_t)(c->ecx + 0x8u)); /* lea esi, [ecx + 8] */
L_00b2a99b:;
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->cf) goto L_00b2aa1d; /* jae 0xb2aa1d */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->edx)); /* lea eax, [esi + edx] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0x8u))); /* cmp eax, dword ptr [ebp + 8] */
    if (!c->cf) goto L_00b2aa1d; /* jae 0xb2aa1d */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00b2a9ed; /* jne 0xb2a9ed */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ebx = (uint32_t)((uint32_t)(c->esi + 0x1u)); /* lea ebx, [esi + 1] */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00b2a9b3:;
    (void)sub8(c, R8((uint32_t)(c->ebx)), (uint8_t)0x0u); /* cmp byte ptr [ebx], 0 */
    if (!c->zf) goto L_00b2a9dd; /* jne 0xb2a9dd */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_00b2a9b3; /* jmp 0xb2a9b3 */
L_00b2a9bc:;
    c->ebx = (uint32_t)((uint32_t)(c->eax + c->edx)); /* lea ebx, [eax + edx] */
    (void)sub32(c, c->ebx, R32((uint32_t)(c->ebp + 0x8u))); /* cmp ebx, dword ptr [ebp + 8] */
    if (!c->cf) goto L_00b2a9cd; /* jae 0xb2a9cd */
    c->esi = (uint32_t)(sub32(c, c->esi, c->edx)); /* sub esi, edx */
    W32((uint32_t)(c->ecx), (uint32_t)(c->ebx)); /* mov dword ptr [ecx], ebx */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [ecx + 4], esi */
    goto L_00b2a9d6; /* jmp 0xb2a9d6 */
L_00b2a9cd:;
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ecx + 4], 0 */
    c->esi = (uint32_t)((uint32_t)(c->ecx + 0x8u)); /* lea esi, [ecx + 8] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->esi)); /* mov dword ptr [ecx], esi */
L_00b2a9d6:;
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [eax], dl */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
    goto L_00b2aa13; /* jmp 0xb2aa13 */
L_00b2a9dd:;
    (void)sub32(c, c->eax, c->edx); /* cmp eax, edx */
    if (!c->cf) goto L_00b2a9f4; /* jae 0xb2a9f4 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(sub32(c, R32(a_), c->eax))); } /* sub dword ptr [ebp + 0xc], eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->edx); /* cmp dword ptr [ebp + 0xc], edx */
    if (c->cf) goto L_00b2aa1d; /* jb 0xb2aa1d */
    c->esi = (uint32_t)(c->ebx); /* mov esi, ebx */
    goto L_00b2a99b; /* jmp 0xb2a99b */
L_00b2a9ed:;
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->eax)); /* movzx eax, al */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    goto L_00b2a99b; /* jmp 0xb2a99b */
L_00b2a9f4:;
    c->ebx = (uint32_t)((uint32_t)(c->esi + c->edx)); /* lea ebx, [esi + edx] */
    (void)sub32(c, c->ebx, R32((uint32_t)(c->ebp + 0x8u))); /* cmp ebx, dword ptr [ebp + 8] */
    if (!c->cf) goto L_00b2aa05; /* jae 0xb2aa05 */
    c->eax = (uint32_t)(sub32(c, c->eax, c->edx)); /* sub eax, edx */
    W32((uint32_t)(c->ecx), (uint32_t)(c->ebx)); /* mov dword ptr [ecx], ebx */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 4], eax */
    goto L_00b2aa0e; /* jmp 0xb2aa0e */
L_00b2aa05:;
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ecx + 4], 0 */
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0x8u)); /* lea eax, [ecx + 8] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
L_00b2aa0e:;
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x8u)); /* lea eax, [esi + 8] */
L_00b2aa13:;
    { int64_t r_ = (int64_t)(int32_t)c->ecx * (int32_t)(uint32_t)0xfu; c->ecx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul ecx, ecx, 0xf */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    goto L_00b2aa1f; /* jmp 0xb2aa1f */
L_00b2aa1d:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00b2aa1f:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b2aa24(CPU *c) { /* FUN_1000aa24 */
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
    if ((c->cf || c->zf)) goto L_00b2aa5e; /* jbe 0xb2aa5e */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    W8((uint32_t)(c->edx), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edx], al */
    { uint32_t a_ = (uint32_t)(c->edi); W32(a_, (uint32_t)(add32(c, R32(a_), c->ecx))); } /* add dword ptr [edi], ecx */
    W32((uint32_t)(c->edi + 0x4u), (uint32_t)((uint32_t)0xf1u)); /* mov dword ptr [edi + 4], 0xf1 */
    goto L_00b2aabe; /* jmp 0xb2aabe */
L_00b2aa5e:;
    if (!c->cf) goto L_00b2aac5; /* jae 0xb2aac5 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    c->esi = (uint32_t)((uint32_t)(c->edx + c->eax)); /* lea esi, [edx + eax] */
    c->eax = (uint32_t)((uint32_t)(c->ebx + 0xf8u)); /* lea eax, [ebx + 0xf8] */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00b2aac5; /* jb 0xb2aac5 */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->edx)); /* lea eax, [ecx + edx] */
L_00b2aa73:;
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (!c->cf) goto L_00b2aa81; /* jae 0xb2aa81 */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (!c->zf) goto L_00b2aa7f; /* jne 0xb2aa7f */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_00b2aa73; /* jmp 0xb2aa73 */
L_00b2aa7f:;
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
L_00b2aa81:;
    if (!c->zf) goto L_00b2aac5; /* jne 0xb2aac5 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0x14u))); /* mov al, byte ptr [ebp + 0x14] */
    W8((uint32_t)(c->edx), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edx], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    (void)sub32(c, c->edx, c->eax); /* cmp edx, eax */
    if ((!c->cf && !c->zf)) goto L_00b2aab9; /* ja 0xb2aab9 */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if ((c->cf || c->zf)) goto L_00b2aab9; /* jbe 0xb2aab9 */
    c->eax = (uint32_t)((uint32_t)(c->ebx + 0xf8u)); /* lea eax, [ebx + 0xf8] */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if (!c->cf) goto L_00b2aab0; /* jae 0xb2aab0 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W32((uint32_t)(c->ebx), (uint32_t)(c->esi)); /* mov dword ptr [ebx], esi */
    (void)sub8(c, R8((uint32_t)(c->esi)), ((uint8_t)c->eax)); /* cmp byte ptr [esi], al */
    if (!c->zf) goto L_00b2aaab; /* jne 0xb2aaab */
L_00b2aaa4:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub8(c, R8((uint32_t)(c->esi + c->eax)), (uint8_t)0x0u); /* cmp byte ptr [esi + eax], 0 */
    if (c->zf) goto L_00b2aaa4; /* je 0xb2aaa4 */
L_00b2aaab:;
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 4], eax */
    goto L_00b2aab9; /* jmp 0xb2aab9 */
L_00b2aab0:;
    { uint32_t a_ = (uint32_t)(c->ebx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebx + 4], 0 */
    c->eax = (uint32_t)((uint32_t)(c->ebx + 0x8u)); /* lea eax, [ebx + 8] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
L_00b2aab9:;
    c->ecx = (uint32_t)(sub32(c, c->ecx, R32((uint32_t)(c->ebp + 0x14u)))); /* sub ecx, dword ptr [ebp + 0x14] */
    { uint32_t a_ = (uint32_t)(c->edi); W32(a_, (uint32_t)(add32(c, R32(a_), c->ecx))); } /* add dword ptr [edi], ecx */
L_00b2aabe:;
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
L_00b2aac5:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b2aacd(CPU *c) { /* FUN_1000aacd */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0xb33644u))); /* mov eax, dword ptr [0x10013644] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b2aae5; /* je 0xb2aae5 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00b2aadcu); call_indirect(c, t_); } /* call eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00b2aae5; /* je 0xb2aae5 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
L_00b2aae5:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_00b2aaf0(CPU *c) { /* FUN_1000aaf0 */
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
    if ((c->cf || c->zf)) goto L_00b2ab10; /* jbe 0xb2ab10 */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_00b2ac88; /* jb 0xb2ac88 */
L_00b2ab10:;
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x3u)); /* test edi, 3 */
    if (!c->zf) goto L_00b2ab2c; /* jne 0xb2ab2c */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u))); /* and edx, 3 */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) goto L_00b2ab4c; /* jb 0xb2ab4c */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb2ac38u)); switch (t_) { case 0x00b2ac48u: goto L_00b2ac48; case 0x00b2ac50u: goto L_00b2ac50; case 0x00b2ac5cu: goto L_00b2ac5c; case 0x00b2ac70u: goto L_00b2ac70; default: jump_indirect(c, t_, 0x00b2ab25u); return; } } /* jmp dword ptr [edx*4 + 0x1000ac38] */
L_00b2ab2c:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edx = (uint32_t)((uint32_t)0x3u); /* mov edx, 3 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x4u)); /* sub ecx, 4 */
    if (c->cf) goto L_00b2ab44; /* jb 0xb2ab44 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x3u))); /* and eax, 3 */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->eax * 4 + 0xb2ab50u)); switch (t_) {  default: jump_indirect(c, t_, 0x00b2ab3du); return; } } /* jmp dword ptr [eax*4 + 0x1000ab50] */
L_00b2ab44:;
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0xb2ac48u)); switch (t_) {  default: jump_indirect(c, t_, 0x00b2ab44u); return; } } /* jmp dword ptr [ecx*4 + 0x1000ac48] */
L_00b2ab4c:;
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0xb2abccu)); switch (t_) { case 0x00b2abecu: goto L_00b2abec; case 0x00b2abf4u: goto L_00b2abf4; case 0x00b2abfcu: goto L_00b2abfc; case 0x00b2ac04u: goto L_00b2ac04; case 0x00b2ac0cu: goto L_00b2ac0c; case 0x00b2ac14u: goto L_00b2ac14; case 0x00b2ac1cu: goto L_00b2ac1c; case 0x00b2ac2fu: goto L_00b2ac2f; default: jump_indirect(c, t_, 0x00b2ab4cu); return; } } /* jmp dword ptr [ecx*4 + 0x1000abcc] */
L_00b2abec:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe4u))); /* mov eax, dword ptr [esi + ecx*4 - 0x1c] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x1c], eax */
L_00b2abf4:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe8u))); /* mov eax, dword ptr [esi + ecx*4 - 0x18] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x18], eax */
L_00b2abfc:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffecu))); /* mov eax, dword ptr [esi + ecx*4 - 0x14] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffecu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x14], eax */
L_00b2ac04:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff0u))); /* mov eax, dword ptr [esi + ecx*4 - 0x10] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x10], eax */
L_00b2ac0c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff4u))); /* mov eax, dword ptr [esi + ecx*4 - 0xc] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0xc], eax */
L_00b2ac14:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff8u))); /* mov eax, dword ptr [esi + ecx*4 - 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 8], eax */
L_00b2ac1c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
L_00b2ac2f:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb2ac38u)); switch (t_) { case 0x00b2ac48u: goto L_00b2ac48; case 0x00b2ac50u: goto L_00b2ac50; case 0x00b2ac5cu: goto L_00b2ac5c; case 0x00b2ac70u: goto L_00b2ac70; default: jump_indirect(c, t_, 0x00b2ac2fu); return; } } /* jmp dword ptr [edx*4 + 0x1000ac38] */
L_00b2ac48:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ac50:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ac5c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ac70:;
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
L_00b2ac88:;
    c->esi = (uint32_t)((uint32_t)(c->ecx + c->esi + 0xfffffffcu)); /* lea esi, [ecx + esi - 4] */
    c->edi = (uint32_t)((uint32_t)(c->ecx + c->edi + 0xfffffffcu)); /* lea edi, [ecx + edi - 4] */
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x3u)); /* test edi, 3 */
    if (!c->zf) goto L_00b2acbc; /* jne 0xb2acbc */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u))); /* and edx, 3 */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) goto L_00b2acb0; /* jb 0xb2acb0 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb2add0u)); switch (t_) { case 0x00b2ade0u: goto L_00b2ade0; case 0x00b2ade8u: goto L_00b2ade8; case 0x00b2adf8u: goto L_00b2adf8; case 0x00b2ae0cu: goto L_00b2ae0c; default: jump_indirect(c, t_, 0x00b2aca7u); return; } } /* jmp dword ptr [edx*4 + 0x1000add0] */
L_00b2acb0:;
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0xb2ad80u)); switch (t_) { case 0x00b2adc7u: goto L_00b2adc7; default: jump_indirect(c, t_, 0x00b2acb2u); return; } } /* jmp dword ptr [ecx*4 + 0x1000ad80] */
L_00b2acbc:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edx = (uint32_t)((uint32_t)0x3u); /* mov edx, 3 */
    (void)sub32(c, c->ecx, (uint32_t)0x4u); /* cmp ecx, 4 */
    if (c->cf) goto L_00b2acd4; /* jb 0xb2acd4 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x3u))); /* and eax, 3 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->eax * 4 + 0xb2acd8u)); switch (t_) {  default: jump_indirect(c, t_, 0x00b2accdu); return; } } /* jmp dword ptr [eax*4 + 0x1000acd8] */
L_00b2acd4:;
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0xb2add0u)); switch (t_) { case 0x00b2ade0u: goto L_00b2ade0; case 0x00b2ade8u: goto L_00b2ade8; case 0x00b2adf8u: goto L_00b2adf8; case 0x00b2ae0cu: goto L_00b2ae0c; default: jump_indirect(c, t_, 0x00b2acd4u); return; } } /* jmp dword ptr [ecx*4 + 0x1000add0] */
L_00b2adc7:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb2add0u)); switch (t_) { case 0x00b2ade0u: goto L_00b2ade0; case 0x00b2ade8u: goto L_00b2ade8; case 0x00b2adf8u: goto L_00b2adf8; case 0x00b2ae0cu: goto L_00b2ae0c; default: jump_indirect(c, t_, 0x00b2adc7u); return; } } /* jmp dword ptr [edx*4 + 0x1000add0] */
L_00b2ade0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ade8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2adf8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ae0c:;
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

void f_00b2ab4c(CPU *c) { /* PTR_00b2ab4c */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0xb2abccu)); switch (t_) { case 0x00b2abecu: goto L_00b2abec; case 0x00b2abf4u: goto L_00b2abf4; case 0x00b2abfcu: goto L_00b2abfc; case 0x00b2ac04u: goto L_00b2ac04; case 0x00b2ac0cu: goto L_00b2ac0c; case 0x00b2ac14u: goto L_00b2ac14; case 0x00b2ac1cu: goto L_00b2ac1c; case 0x00b2ac2fu: goto L_00b2ac2f; default: jump_indirect(c, t_, 0x00b2ab4cu); return; } } /* jmp dword ptr [ecx*4 + 0x1000abcc] */
L_00b2abec:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe4u))); /* mov eax, dword ptr [esi + ecx*4 - 0x1c] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x1c], eax */
L_00b2abf4:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe8u))); /* mov eax, dword ptr [esi + ecx*4 - 0x18] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x18], eax */
L_00b2abfc:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffecu))); /* mov eax, dword ptr [esi + ecx*4 - 0x14] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffecu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x14], eax */
L_00b2ac04:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff0u))); /* mov eax, dword ptr [esi + ecx*4 - 0x10] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x10], eax */
L_00b2ac0c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff4u))); /* mov eax, dword ptr [esi + ecx*4 - 0xc] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0xc], eax */
L_00b2ac14:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff8u))); /* mov eax, dword ptr [esi + ecx*4 - 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 8], eax */
L_00b2ac1c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
L_00b2ac2f:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb2ac38u)); switch (t_) { case 0x00b2ac48u: goto L_00b2ac48; case 0x00b2ac50u: goto L_00b2ac50; case 0x00b2ac5cu: goto L_00b2ac5c; case 0x00b2ac70u: goto L_00b2ac70; default: jump_indirect(c, t_, 0x00b2ac2fu); return; } } /* jmp dword ptr [edx*4 + 0x1000ac38] */
L_00b2ac48:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ac50:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ac5c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ac70:;
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

void f_00b2ab50(CPU *c) { /* PTR_00b2ab50 */
    PREEMPT_POLL(c);
    W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); /* stosd dword ptr es:[edi], eax */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    ; /* nop  */
    { uint32_t s_ = c->esp; PUSH32(c, c->eax); PUSH32(c, c->ecx); PUSH32(c, c->edx); PUSH32(c, c->ebx); PUSH32(c, s_); PUSH32(c, c->ebp); PUSH32(c, c->esi); PUSH32(c, c->edi); } /* pushal  */
    W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); /* stosd dword ptr es:[edi], eax */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    guest_trap(c, 0x00b2ab58u, "unsupported: mov word ptr [ebx - 0x544ff000], gs"); /* mov word ptr [ebx - 0x544ff000], gs */
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
    if (c->cf) { f_00b2ab4c(c); return; } /* jb 0xb2ab4c */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb2ac38u)); switch (t_) { case 0x00b2ac48u: goto L_00b2ac48; case 0x00b2ac50u: goto L_00b2ac50; case 0x00b2ac5cu: goto L_00b2ac5c; case 0x00b2ac70u: goto L_00b2ac70; default: jump_indirect(c, t_, 0x00b2ab82u); return; } } /* jmp dword ptr [edx*4 + 0x1000ac38] */
L_00b2ac48:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ac50:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ac5c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ac70:;
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

void f_00b2ab60(CPU *c) { /* PTR_00b2ab60 */
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
    if (c->cf) { f_00b2ab4c(c); return; } /* jb 0xb2ab4c */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb2ac38u)); switch (t_) { case 0x00b2ac48u: goto L_00b2ac48; case 0x00b2ac50u: goto L_00b2ac50; case 0x00b2ac5cu: goto L_00b2ac5c; case 0x00b2ac70u: goto L_00b2ac70; default: jump_indirect(c, t_, 0x00b2ab82u); return; } } /* jmp dword ptr [edx*4 + 0x1000ac38] */
L_00b2ac48:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ac50:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ac5c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ac70:;
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

void f_00b2ab80(CPU *c) { /* PTR_00b2ab80 */
    PREEMPT_POLL(c);
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb2ac38u)); switch (t_) { case 0x00b2ac48u: goto L_00b2ac48; case 0x00b2ac50u: goto L_00b2ac50; case 0x00b2ac5cu: goto L_00b2ac5c; case 0x00b2ac70u: goto L_00b2ac70; default: jump_indirect(c, t_, 0x00b2ab82u); return; } } /* jmp dword ptr [edx*4 + 0x1000ac38] */
L_00b2ac48:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ac50:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ac5c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ac70:;
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

void f_00b2ab8c(CPU *c) { /* PTR_00b2ab8c */
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
    if (c->cf) { f_00b2ab4c(c); return; } /* jb 0xb2ab4c */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb2ac38u)); switch (t_) { case 0x00b2ac48u: goto L_00b2ac48; case 0x00b2ac50u: goto L_00b2ac50; case 0x00b2ac5cu: goto L_00b2ac5c; case 0x00b2ac70u: goto L_00b2ac70; default: jump_indirect(c, t_, 0x00b2aba8u); return; } } /* jmp dword ptr [edx*4 + 0x1000ac38] */
L_00b2ac48:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ac50:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ac5c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ac70:;
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

void f_00b2abb0(CPU *c) { /* PTR_00b2abb0 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & c->ecx))); /* and edx, ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) { f_00b2ab4c(c); return; } /* jb 0xb2ab4c */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb2ac38u)); switch (t_) { case 0x00b2ac48u: goto L_00b2ac48; case 0x00b2ac50u: goto L_00b2ac50; case 0x00b2ac5cu: goto L_00b2ac5c; case 0x00b2ac70u: goto L_00b2ac70; default: jump_indirect(c, t_, 0x00b2abc2u); return; } } /* jmp dword ptr [edx*4 + 0x1000ac38] */
L_00b2ac48:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ac50:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ac5c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ac70:;
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

void f_00b2abec(CPU *c) { /* PTR_00b2abec */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb2ac38u)); switch (t_) { case 0x00b2ac48u: goto L_00b2ac48; case 0x00b2ac50u: goto L_00b2ac50; case 0x00b2ac5cu: goto L_00b2ac5c; case 0x00b2ac70u: goto L_00b2ac70; default: jump_indirect(c, t_, 0x00b2ac2fu); return; } } /* jmp dword ptr [edx*4 + 0x1000ac38] */
L_00b2ac48:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ac50:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ac5c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ac70:;
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

void f_00b2abf4(CPU *c) { /* PTR_00b2abf4 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb2ac38u)); switch (t_) { case 0x00b2ac48u: goto L_00b2ac48; case 0x00b2ac50u: goto L_00b2ac50; case 0x00b2ac5cu: goto L_00b2ac5c; case 0x00b2ac70u: goto L_00b2ac70; default: jump_indirect(c, t_, 0x00b2ac2fu); return; } } /* jmp dword ptr [edx*4 + 0x1000ac38] */
L_00b2ac48:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ac50:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ac5c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ac70:;
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

void f_00b2abfc(CPU *c) { /* PTR_00b2abfc */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb2ac38u)); switch (t_) { case 0x00b2ac48u: goto L_00b2ac48; case 0x00b2ac50u: goto L_00b2ac50; case 0x00b2ac5cu: goto L_00b2ac5c; case 0x00b2ac70u: goto L_00b2ac70; default: jump_indirect(c, t_, 0x00b2ac2fu); return; } } /* jmp dword ptr [edx*4 + 0x1000ac38] */
L_00b2ac48:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ac50:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ac5c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ac70:;
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

void f_00b2ac04(CPU *c) { /* PTR_00b2ac04 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb2ac38u)); switch (t_) { case 0x00b2ac48u: goto L_00b2ac48; case 0x00b2ac50u: goto L_00b2ac50; case 0x00b2ac5cu: goto L_00b2ac5c; case 0x00b2ac70u: goto L_00b2ac70; default: jump_indirect(c, t_, 0x00b2ac2fu); return; } } /* jmp dword ptr [edx*4 + 0x1000ac38] */
L_00b2ac48:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ac50:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ac5c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ac70:;
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

void f_00b2ac0c(CPU *c) { /* PTR_00b2ac0c */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb2ac38u)); switch (t_) { case 0x00b2ac48u: goto L_00b2ac48; case 0x00b2ac50u: goto L_00b2ac50; case 0x00b2ac5cu: goto L_00b2ac5c; case 0x00b2ac70u: goto L_00b2ac70; default: jump_indirect(c, t_, 0x00b2ac2fu); return; } } /* jmp dword ptr [edx*4 + 0x1000ac38] */
L_00b2ac48:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ac50:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ac5c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ac70:;
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

void f_00b2ac14(CPU *c) { /* PTR_00b2ac14 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff8u))); /* mov eax, dword ptr [esi + ecx*4 - 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb2ac38u)); switch (t_) { case 0x00b2ac48u: goto L_00b2ac48; case 0x00b2ac50u: goto L_00b2ac50; case 0x00b2ac5cu: goto L_00b2ac5c; case 0x00b2ac70u: goto L_00b2ac70; default: jump_indirect(c, t_, 0x00b2ac2fu); return; } } /* jmp dword ptr [edx*4 + 0x1000ac38] */
L_00b2ac48:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ac50:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ac5c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ac70:;
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

void f_00b2ac1c(CPU *c) { /* PTR_00b2ac1c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb2ac38u)); switch (t_) { case 0x00b2ac48u: goto L_00b2ac48; case 0x00b2ac50u: goto L_00b2ac50; case 0x00b2ac5cu: goto L_00b2ac5c; case 0x00b2ac70u: goto L_00b2ac70; default: jump_indirect(c, t_, 0x00b2ac2fu); return; } } /* jmp dword ptr [edx*4 + 0x1000ac38] */
L_00b2ac48:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ac50:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ac5c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ac70:;
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

void f_00b2ac2f(CPU *c) { /* PTR_00b2ac2f */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb2ac38u)); switch (t_) { case 0x00b2ac48u: goto L_00b2ac48; case 0x00b2ac50u: goto L_00b2ac50; case 0x00b2ac5cu: goto L_00b2ac5c; case 0x00b2ac70u: goto L_00b2ac70; default: jump_indirect(c, t_, 0x00b2ac2fu); return; } } /* jmp dword ptr [edx*4 + 0x1000ac38] */
L_00b2ac48:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ac50:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ac5c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ac70:;
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

void f_00b2ac48(CPU *c) { /* PTR_00b2ac48 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b2ac50(CPU *c) { /* PTR_00b2ac50 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b2ac5c(CPU *c) { /* PTR_00b2ac5c */
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

void f_00b2ac70(CPU *c) { /* PTR_00b2ac70 */
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

void f_00b2acb0(CPU *c) { /* PTR_00b2acb0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0xb2ad80u)); switch (t_) { case 0x00b2adc7u: goto L_00b2adc7; default: jump_indirect(c, t_, 0x00b2acb2u); return; } } /* jmp dword ptr [ecx*4 + 0x1000ad80] */
L_00b2adc7:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb2add0u)); switch (t_) { case 0x00b2ade0u: goto L_00b2ade0; case 0x00b2ade8u: goto L_00b2ade8; case 0x00b2adf8u: goto L_00b2adf8; case 0x00b2ae0cu: goto L_00b2ae0c; default: jump_indirect(c, t_, 0x00b2adc7u); return; } } /* jmp dword ptr [edx*4 + 0x1000add0] */
L_00b2ade0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ade8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2adf8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ae0c:;
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

void f_00b2ace8(CPU *c) { /* PTR_00b2ace8 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & c->ecx))); /* and edx, ecx */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) { f_00b2acb0(c); return; } /* jb 0xb2acb0 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb2add0u)); switch (t_) { case 0x00b2ade0u: goto L_00b2ade0; case 0x00b2ade8u: goto L_00b2ade8; case 0x00b2adf8u: goto L_00b2adf8; case 0x00b2ae0cu: goto L_00b2ae0c; default: jump_indirect(c, t_, 0x00b2acfeu); return; } } /* jmp dword ptr [edx*4 + 0x1000add0] */
L_00b2ade0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ade8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2adf8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ae0c:;
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

void f_00b2ad08(CPU *c) { /* PTR_00b2ad08 */
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
    if (c->cf) { f_00b2acb0(c); return; } /* jb 0xb2acb0 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb2add0u)); switch (t_) { case 0x00b2ade0u: goto L_00b2ade0; case 0x00b2ade8u: goto L_00b2ade8; case 0x00b2adf8u: goto L_00b2adf8; case 0x00b2ae0cu: goto L_00b2ae0c; default: jump_indirect(c, t_, 0x00b2ad28u); return; } } /* jmp dword ptr [edx*4 + 0x1000add0] */
L_00b2ade0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ade8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2adf8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ae0c:;
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

void f_00b2ad30(CPU *c) { /* PTR_00b2ad30 */
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
    if (c->cf) { f_00b2acb0(c); return; } /* jb 0xb2acb0 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb2add0u)); switch (t_) { case 0x00b2ade0u: goto L_00b2ade0; case 0x00b2ade8u: goto L_00b2ade8; case 0x00b2adf8u: goto L_00b2adf8; case 0x00b2ae0cu: goto L_00b2ae0c; default: jump_indirect(c, t_, 0x00b2ad5au); return; } } /* jmp dword ptr [edx*4 + 0x1000add0] */
L_00b2ade0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ade8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2adf8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ae0c:;
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

void f_00b2ad84(CPU *c) { /* PTR_00b2ad84 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb2add0u)); switch (t_) { case 0x00b2ade0u: goto L_00b2ade0; case 0x00b2ade8u: goto L_00b2ade8; case 0x00b2adf8u: goto L_00b2adf8; case 0x00b2ae0cu: goto L_00b2ae0c; default: jump_indirect(c, t_, 0x00b2adc7u); return; } } /* jmp dword ptr [edx*4 + 0x1000add0] */
L_00b2ade0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ade8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2adf8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ae0c:;
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

void f_00b2ad8c(CPU *c) { /* PTR_00b2ad8c */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb2add0u)); switch (t_) { case 0x00b2ade0u: goto L_00b2ade0; case 0x00b2ade8u: goto L_00b2ade8; case 0x00b2adf8u: goto L_00b2adf8; case 0x00b2ae0cu: goto L_00b2ae0c; default: jump_indirect(c, t_, 0x00b2adc7u); return; } } /* jmp dword ptr [edx*4 + 0x1000add0] */
L_00b2ade0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ade8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2adf8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ae0c:;
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

void f_00b2ad94(CPU *c) { /* PTR_00b2ad94 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb2add0u)); switch (t_) { case 0x00b2ade0u: goto L_00b2ade0; case 0x00b2ade8u: goto L_00b2ade8; case 0x00b2adf8u: goto L_00b2adf8; case 0x00b2ae0cu: goto L_00b2ae0c; default: jump_indirect(c, t_, 0x00b2adc7u); return; } } /* jmp dword ptr [edx*4 + 0x1000add0] */
L_00b2ade0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ade8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2adf8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ae0c:;
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

void f_00b2ad9c(CPU *c) { /* PTR_00b2ad9c */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb2add0u)); switch (t_) { case 0x00b2ade0u: goto L_00b2ade0; case 0x00b2ade8u: goto L_00b2ade8; case 0x00b2adf8u: goto L_00b2adf8; case 0x00b2ae0cu: goto L_00b2ae0c; default: jump_indirect(c, t_, 0x00b2adc7u); return; } } /* jmp dword ptr [edx*4 + 0x1000add0] */
L_00b2ade0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ade8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2adf8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ae0c:;
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

void f_00b2ada4(CPU *c) { /* PTR_00b2ada4 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb2add0u)); switch (t_) { case 0x00b2ade0u: goto L_00b2ade0; case 0x00b2ade8u: goto L_00b2ade8; case 0x00b2adf8u: goto L_00b2adf8; case 0x00b2ae0cu: goto L_00b2ae0c; default: jump_indirect(c, t_, 0x00b2adc7u); return; } } /* jmp dword ptr [edx*4 + 0x1000add0] */
L_00b2ade0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ade8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2adf8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ae0c:;
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

void f_00b2adac(CPU *c) { /* PTR_00b2adac */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x8u))); /* mov eax, dword ptr [esi + ecx*4 + 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x4u))); /* mov eax, dword ptr [esi + ecx*4 + 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb2add0u)); switch (t_) { case 0x00b2ade0u: goto L_00b2ade0; case 0x00b2ade8u: goto L_00b2ade8; case 0x00b2adf8u: goto L_00b2adf8; case 0x00b2ae0cu: goto L_00b2ae0c; default: jump_indirect(c, t_, 0x00b2adc7u); return; } } /* jmp dword ptr [edx*4 + 0x1000add0] */
L_00b2ade0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ade8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2adf8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ae0c:;
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

void f_00b2adb4(CPU *c) { /* PTR_00b2adb4 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x4u))); /* mov eax, dword ptr [esi + ecx*4 + 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb2add0u)); switch (t_) { case 0x00b2ade0u: goto L_00b2ade0; case 0x00b2ade8u: goto L_00b2ade8; case 0x00b2adf8u: goto L_00b2adf8; case 0x00b2ae0cu: goto L_00b2ae0c; default: jump_indirect(c, t_, 0x00b2adc7u); return; } } /* jmp dword ptr [edx*4 + 0x1000add0] */
L_00b2ade0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ade8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2adf8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ae0c:;
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

void f_00b2adc7(CPU *c) { /* PTR_00b2adc7 */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xb2add0u)); switch (t_) { case 0x00b2ade0u: goto L_00b2ade0; case 0x00b2ade8u: goto L_00b2ade8; case 0x00b2adf8u: goto L_00b2adf8; case 0x00b2ae0cu: goto L_00b2ae0c; default: jump_indirect(c, t_, 0x00b2adc7u); return; } } /* jmp dword ptr [edx*4 + 0x1000add0] */
L_00b2ade0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ade8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2adf8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2ae0c:;
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

void f_00b2ade0(CPU *c) { /* PTR_00b2ade0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b2ade8(CPU *c) { /* PTR_00b2ade8 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b2adf8(CPU *c) { /* PTR_00b2adf8 */
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

void f_00b2ae0c(CPU *c) { /* PTR_00b2ae0c */
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

void f_00b2ae25(CPU *c) { /* FUN_1000ae25 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x20u; PUSH32(c, v_); } /* push 0x20 */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { int32_t d_ = (int32_t)c->ecx; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00b2ae2eu, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv ecx */
    { uint32_t v_ = 0x1fu; PUSH32(c, v_); } /* push 0x1f */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)c->ecx; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00b2ae39u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->edx)); /* sub ecx, edx */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx | (uint32_t)0xffffffffu))); /* or edx, 0xffffffff */
    c->edx = (uint32_t)(shl32(c, c->edx, (c->ecx & 0xff))); /* shl edx, cl */
    c->edx = (uint32_t)((uint32_t)~c->edx); /* not edx */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->eax + c->esi * 4)) & c->edx)); /* test dword ptr [eax + esi*4], edx */
    if (!c->zf) goto L_00b2ae6a; /* jne 0xb2ae6a */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub32(c, c->esi, (uint32_t)0x3u); /* cmp esi, 3 */
    if ((c->sf == c->of)) goto L_00b2ae65; /* jge 0xb2ae65 */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->esi * 4)); /* lea eax, [eax + esi*4] */
L_00b2ae57:;
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0x0u); /* cmp dword ptr [eax], 0 */
    if (!c->zf) goto L_00b2ae6a; /* jne 0xb2ae6a */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x4u)); /* add eax, 4 */
    (void)sub32(c, c->esi, (uint32_t)0x3u); /* cmp esi, 3 */
    if ((c->sf != c->of)) goto L_00b2ae57; /* jl 0xb2ae57 */
L_00b2ae65:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_00b2ae6a:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b2ae6e(CPU *c) { /* FUN_1000ae6e */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x20u; PUSH32(c, v_); } /* push 0x20 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ebx, dword ptr [esp + 0x14] */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { int32_t d_ = (int32_t)c->ecx; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00b2ae7du, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv ecx */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)c->ecx; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00b2ae86u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv ecx */
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
    PUSH32(c, 0x00b2ae9eu); f_00b2c9ad(c); /* call 0xb2c9ad */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    if (c->sf) goto L_00b2aec0; /* js 0xb2aec0 */
    c->edi = (uint32_t)((uint32_t)(c->ebx + c->esi * 4)); /* lea edi, [ebx + esi*4] */
L_00b2aea7:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b2aec0; /* je 0xb2aec0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->edi)); PUSH32(c, v_); } /* push dword ptr [edi] */
    PUSH32(c, 0x00b2aeb5u); f_00b2c9ad(c); /* call 0xb2c9ad */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    c->edi = (uint32_t)(sub32(c, c->edi, (uint32_t)0x4u)); /* sub edi, 4 */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if ((c->sf == c->of)) goto L_00b2aea7; /* jge 0xb2aea7 */
L_00b2aec0:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00b2aec4(CPU *c) { /* FUN_1000aec4 */
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
    { int32_t d_ = (int32_t)c->ecx; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00b2aee2u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv ecx */
    { uint32_t v_ = 0x1fu; PUSH32(c, v_); } /* push 0x1f */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00b2aeebu, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
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
    if (c->zf) goto L_00b2af28; /* je 0xb2af28 */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00b2af11u); f_00b2ae25(c); /* call 0xb2ae25 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00b2af25; /* jne 0xb2af25 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00b2af20u); f_00b2ae6e(c); /* call 0xb2ae6e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b2af25:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
L_00b2af28:;
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx | (uint32_t)0xffffffffu))); /* or edx, 0xffffffff */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->edx = (uint32_t)(shl32(c, c->edx, (c->ecx & 0xff))); /* shl edx, cl */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->edx)))); } /* and dword ptr [eax], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if ((c->sf == c->of)) goto L_00b2af48; /* jge 0xb2af48 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    c->edi = (uint32_t)((uint32_t)(c->edx + c->eax * 4)); /* lea edi, [edx + eax*4] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
L_00b2af48:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b2af50(CPU *c) { /* FUN_1000af50 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
L_00b2af5e:;
    c->esi = (uint32_t)(R32((uint32_t)(c->eax))); /* mov esi, dword ptr [eax] */
    W32((uint32_t)(c->ecx + c->eax), (uint32_t)(c->esi)); /* mov dword ptr [ecx + eax], esi */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x4u)); /* add eax, 4 */
    c->edx = (uint32_t)(dec32(c, c->edx)); /* dec edx */
    if (!c->zf) goto L_00b2af5e; /* jne 0xb2af5e */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b2af6b(CPU *c) { /* FUN_1000af6b */
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

void f_00b2af77(CPU *c) { /* FUN_1000af77 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
L_00b2af7d:;
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0x0u); /* cmp dword ptr [eax], 0 */
    if (!c->zf) goto L_00b2af8f; /* jne 0xb2af8f */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x4u)); /* add eax, 4 */
    (void)sub32(c, c->ecx, (uint32_t)0x3u); /* cmp ecx, 3 */
    if ((c->sf != c->of)) goto L_00b2af7d; /* jl 0xb2af7d */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
L_00b2af8f:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_00b2af92(CPU *c) { /* FUN_1000af92 */
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
    { int32_t d_ = (int32_t)c->ecx; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00b2afb1u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv ecx */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)c->ecx; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00b2afbau, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp + 0xc], 0 */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->esi = (uint32_t)(shl32(c, c->esi, (c->ecx & 0xff))); /* shl esi, cl */
    c->ebx = (uint32_t)(sub32(c, c->ebx, c->edx)); /* sub ebx, edx */
    c->esi = (uint32_t)((uint32_t)~c->esi); /* not esi */
L_00b2afc8:;
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
    if (!c->zf) goto L_00b2afc8; /* jne 0xb2afc8 */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov edi, dword ptr [ebp - 0xc] */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esi = (uint32_t)(c->edi); /* mov esi, edi */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esi = (uint32_t)(shl32(c, c->esi, 2)); /* shl esi, 2 */
L_00b2affa:;
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    if ((c->sf != c->of)) goto L_00b2b00d; /* jl 0xb2b00d */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->eax = (uint32_t)(sub32(c, c->eax, c->esi)); /* sub eax, esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->edx))); /* mov eax, dword ptr [eax + edx] */
    W32((uint32_t)(c->ecx + c->edx), (uint32_t)(c->eax)); /* mov dword ptr [ecx + edx], eax */
    goto L_00b2b014; /* jmp 0xb2b014 */
L_00b2b00d:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ecx + eax], 0 */
L_00b2b014:;
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x4u)); /* sub ecx, 4 */
    if (!c->sf) goto L_00b2affa; /* jns 0xb2affa */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b2b01f(CPU *c) { /* FUN_1000b01f */
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
    if (!c->zf) goto L_00b2b08c; /* jne 0xb2b08c */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2b071u); f_00b2af77(c); /* call 0xb2af77 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00b2b14b; /* jne 0xb2b14b */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2b083u); f_00b2af6b(c); /* call 0xb2af6b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b2b084:;
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
L_00b2b086:;
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_00b2b14d; /* jmp 0xb2b14d */
L_00b2b08c:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe8u)); /* lea eax, [ebp - 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2b099u); f_00b2af50(c); /* call 0xb2af50 */
    { uint32_t v_ = R32((uint32_t)(c->edi + 0x8u)); PUSH32(c, v_); } /* push dword ptr [edi + 8] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2b0a5u); f_00b2aec4(c); /* call 0xb2aec4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b2b0ad; /* je 0xb2b0ad */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
L_00b2b0ad:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov eax, dword ptr [edi + 4] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->ecx = (uint32_t)(sub32(c, c->ecx, R32((uint32_t)(c->edi + 0x8u)))); /* sub ecx, dword ptr [edi + 8] */
    (void)sub32(c, c->ebx, c->ecx); /* cmp ebx, ecx */
    if ((c->sf == c->of)) goto L_00b2b0c5; /* jge 0xb2b0c5 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2b0c2u); f_00b2af6b(c); /* call 0xb2af6b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00b2b101; /* jmp 0xb2b101 */
L_00b2b0c5:;
    (void)sub32(c, c->ebx, c->eax); /* cmp ebx, eax */
    if ((!c->zf && c->sf == c->of)) goto L_00b2b108; /* jg 0xb2b108 */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ebx)); /* sub eax, ebx */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe8u)); /* lea eax, [ebp - 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2b0dau); f_00b2af50(c); /* call 0xb2af50 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2b0e4u); f_00b2af92(c); /* call 0xb2af92 */
    { uint32_t v_ = R32((uint32_t)(c->edi + 0x8u)); PUSH32(c, v_); } /* push dword ptr [edi + 8] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2b0f0u); f_00b2aec4(c); /* call 0xb2aec4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0xcu))); /* mov eax, dword ptr [edi + 0xc] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2b0feu); f_00b2af92(c); /* call 0xb2af92 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
L_00b2b101:;
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    goto L_00b2b084; /* jmp 0xb2b084 */
L_00b2b108:;
    (void)sub32(c, c->ebx, R32((uint32_t)(c->edi))); /* cmp ebx, dword ptr [edi] */
    if ((c->sf != c->of)) goto L_00b2b134; /* jl 0xb2b134 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2b115u); f_00b2af6b(c); /* call 0xb2af6b */
    { uint32_t v_ = R32((uint32_t)(c->edi + 0xcu)); PUSH32(c, v_); } /* push dword ptr [edi + 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff7u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x80u)))); } /* or byte ptr [ebp - 9], 0x80 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2b125u); f_00b2af92(c); /* call 0xb2af92 */
    c->esi = (uint32_t)(R32((uint32_t)(c->edi + 0x14u))); /* mov esi, dword ptr [edi + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esi = (uint32_t)(add32(c, c->esi, R32((uint32_t)(c->edi)))); /* add esi, dword ptr [edi] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    goto L_00b2b086; /* jmp 0xb2b086 */
L_00b2b134:;
    { uint32_t v_ = R32((uint32_t)(c->edi + 0xcu)); PUSH32(c, v_); } /* push dword ptr [edi + 0xc] */
    c->esi = (uint32_t)(R32((uint32_t)(c->edi + 0x14u))); /* mov esi, dword ptr [edi + 0x14] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff7u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x7fu)))); } /* and byte ptr [ebp - 9], 0x7f */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->esi = (uint32_t)(add32(c, c->esi, c->ebx)); /* add esi, ebx */
    PUSH32(c, 0x00b2b149u); f_00b2af92(c); /* call 0xb2af92 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b2b14b:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00b2b14d:;
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
    if (!c->zf) goto L_00b2b17c; /* jne 0xb2b17c */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov edx, dword ptr [ebp - 8] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [ecx + 4], esi */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    goto L_00b2b186; /* jmp 0xb2b186 */
L_00b2b17c:;
    (void)sub32(c, c->edi, (uint32_t)0x20u); /* cmp edi, 0x20 */
    if (!c->zf) goto L_00b2b186; /* jne 0xb2b186 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->esi)); /* mov dword ptr [ecx], esi */
L_00b2b186:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b2b18b(CPU *c) { /* FUN_1000b18b */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xb329f0u; PUSH32(c, v_); } /* push 0x100129f0 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    PUSH32(c, 0x00b2b19du); f_00b2b01f(c); /* call 0xb2b01f */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b2b1a1(CPU *c) { /* FUN_1000b1a1 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xb32a08u; PUSH32(c, v_); } /* push 0x10012a08 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    PUSH32(c, 0x00b2b1b3u); f_00b2b01f(c); /* call 0xb2b01f */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b2b1b7(CPU *c) { /* FUN_1000b1b7 */
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
    PUSH32(c, 0x00b2b1d3u); f_00b2b211(c); /* call 0xb2b211 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2b1dfu); f_00b2b18b(c); /* call 0xb2b18b */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x24u)); /* add esp, 0x24 */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b2b1e4(CPU *c) { /* FUN_1000b1e4 */
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
    PUSH32(c, 0x00b2b200u); f_00b2b211(c); /* call 0xb2b211 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2b20cu); f_00b2b1a1(c); /* call 0xb2b1a1 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x24u)); /* add esp, 0x24 */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b2b211(CPU *c) { /* FUN_1000b211 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x5cu)); /* sub esp, 0x5c */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edi, dword ptr [ebp + 0x10] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffa4u)); /* lea eax, [ebp - 0x5c] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x28], eax */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x18], edx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x10], eax */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x2c], eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x30], eax */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x14], eax */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 0x10], edi */
L_00b2b24c:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov cl, byte ptr [edi] */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x20u); /* cmp cl, 0x20 */
    if (c->zf) goto L_00b2b262; /* je 0xb2b262 */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x9u); /* cmp cl, 9 */
    if (c->zf) goto L_00b2b262; /* je 0xb2b262 */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0xau); /* cmp cl, 0xa */
    if (c->zf) goto L_00b2b262; /* je 0xb2b262 */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0xdu); /* cmp cl, 0xd */
    if (!c->zf) goto L_00b2b265; /* jne 0xb2b265 */
L_00b2b262:;
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_00b2b24c; /* jmp 0xb2b24c */
L_00b2b265:;
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00b2b268:;
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->eax, (uint32_t)0xbu); /* cmp eax, 0xb */
    if ((!c->cf && !c->zf)) goto L_00b2b4eb; /* ja 0xb2b4eb */
    { uint32_t t_ = R32((uint32_t)(c->eax * 4 + 0xb2b6b2u)); switch (t_) { case 0x00b2b27bu: goto L_00b2b27b; case 0x00b2b2cau: goto L_00b2b2ca; case 0x00b2b321u: goto L_00b2b321; case 0x00b2b34bu: goto L_00b2b34b; case 0x00b2b3a6u: goto L_00b2b3a6; case 0x00b2b41du: goto L_00b2b41d; case 0x00b2b453u: goto L_00b2b453; case 0x00b2b47cu: goto L_00b2b47c; case 0x00b2b49du: goto L_00b2b49d; case 0x00b2b4b7u: goto L_00b2b4b7; case 0x00b2b4ebu: goto L_00b2b4eb; case 0x00b2b501u: goto L_00b2b501; default: jump_indirect(c, t_, 0x00b2b274u); return; } } /* jmp dword ptr [eax*4 + 0x1000b6b2] */
L_00b2b27b:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x31u); /* cmp bl, 0x31 */
    if ((c->sf != c->of)) goto L_00b2b28c; /* jl 0xb2b28c */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x39u); /* cmp bl, 0x39 */
    if ((!c->zf && c->sf == c->of)) goto L_00b2b28c; /* jg 0xb2b28c */
L_00b2b285:;
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    goto L_00b2b4a9; /* jmp 0xb2b4a9 */
L_00b2b28c:;
    (void)sub8(c, ((uint8_t)c->ebx), R8((uint32_t)(0xb30610u))); /* cmp bl, byte ptr [0x10010610] */
    if (!c->zf) goto L_00b2b29b; /* jne 0xb2b29b */
L_00b2b294:;
    { uint32_t v_ = 0x5u; PUSH32(c, v_); } /* push 5 */
    goto L_00b2b4e1; /* jmp 0xb2b4e1 */
L_00b2b29b:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx eax, bl */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x2bu)); /* sub eax, 0x2b */
    if (c->zf) goto L_00b2b2c1; /* je 0xb2b2c1 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00b2b2b5; /* je 0xb2b2b5 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3u)); /* sub eax, 3 */
    if (!c->zf) goto L_00b2b584; /* jne 0xb2b584 */
    goto L_00b2b344; /* jmp 0xb2b344 */
L_00b2b2b5:;
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)((uint32_t)0x8000u)); /* mov dword ptr [ebp - 0x28], 0x8000 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_00b2b268; /* jmp 0xb2b268 */
L_00b2b2c1:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffd8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x28], 0 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_00b2b268; /* jmp 0xb2b268 */
L_00b2b2ca:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x31u); /* cmp bl, 0x31 */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x10], edx */
    if ((c->sf != c->of)) goto L_00b2b2d7; /* jl 0xb2b2d7 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x39u); /* cmp bl, 0x39 */
    if ((c->zf || c->sf != c->of)) goto L_00b2b285; /* jle 0xb2b285 */
L_00b2b2d7:;
    (void)sub8(c, ((uint8_t)c->ebx), R8((uint32_t)(0xb30610u))); /* cmp bl, byte ptr [0x10010610] */
    if (c->zf) goto L_00b2b39f; /* je 0xb2b39f */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x2bu); /* cmp bl, 0x2b */
    if (c->zf) goto L_00b2b319; /* je 0xb2b319 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x2du); /* cmp bl, 0x2d */
    if (c->zf) goto L_00b2b319; /* je 0xb2b319 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x30u); /* cmp bl, 0x30 */
    if (c->zf) goto L_00b2b344; /* je 0xb2b344 */
L_00b2b2f2:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x43u); /* cmp bl, 0x43 */
    if ((c->zf || c->sf != c->of)) goto L_00b2b584; /* jle 0xb2b584 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x45u); /* cmp bl, 0x45 */
    if ((c->zf || c->sf != c->of)) goto L_00b2b312; /* jle 0xb2b312 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x63u); /* cmp bl, 0x63 */
    if ((c->zf || c->sf != c->of)) goto L_00b2b584; /* jle 0xb2b584 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x65u); /* cmp bl, 0x65 */
    if ((!c->zf && c->sf == c->of)) goto L_00b2b584; /* jg 0xb2b584 */
L_00b2b312:;
    { uint32_t v_ = 0x6u; PUSH32(c, v_); } /* push 6 */
    goto L_00b2b4e1; /* jmp 0xb2b4e1 */
L_00b2b319:;
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    { uint32_t v_ = 0xbu; PUSH32(c, v_); } /* push 0xb */
    goto L_00b2b4e1; /* jmp 0xb2b4e1 */
L_00b2b321:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x31u); /* cmp bl, 0x31 */
    if ((c->sf != c->of)) goto L_00b2b32f; /* jl 0xb2b32f */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x39u); /* cmp bl, 0x39 */
    if ((c->zf || c->sf != c->of)) goto L_00b2b285; /* jle 0xb2b285 */
L_00b2b32f:;
    (void)sub8(c, ((uint8_t)c->ebx), R8((uint32_t)(0xb30610u))); /* cmp bl, byte ptr [0x10010610] */
    if (c->zf) goto L_00b2b294; /* je 0xb2b294 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x30u); /* cmp bl, 0x30 */
    if (!c->zf) goto L_00b2b4f9; /* jne 0xb2b4f9 */
L_00b2b344:;
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    goto L_00b2b268; /* jmp 0xb2b268 */
L_00b2b34b:;
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x10], edx */
L_00b2b34e:;
    (void)sub32(c, R32((uint32_t)(0xb3060cu)), c->edx); /* cmp dword ptr [0x1001060c], edx */
    if ((c->zf || c->sf != c->of)) goto L_00b2b367; /* jle 0xb2b367 */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2b360u); f_00b26edb(c); /* call 0xb26edb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    goto L_00b2b375; /* jmp 0xb2b375 */
L_00b2b367:;
    c->ecx = (uint32_t)(R32((uint32_t)(0xb30400u))); /* mov ecx, dword ptr [0x10010400] */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & c->esi))); /* and eax, esi */
L_00b2b375:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b2b397; /* je 0xb2b397 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x19u); /* cmp dword ptr [ebp - 4], 0x19 */
    if (!c->cf) goto L_00b2b38f; /* jae 0xb2b38f */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(sub8(c, ((uint8_t)c->ebx), (uint8_t)0x30u)); /* sub bl, 0x30 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff4u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0xc] */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [eax], bl */
    goto L_00b2b392; /* jmp 0xb2b392 */
L_00b2b38f:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
L_00b2b392:;
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_00b2b34e; /* jmp 0xb2b34e */
L_00b2b397:;
    (void)sub8(c, ((uint8_t)c->ebx), R8((uint32_t)(0xb30610u))); /* cmp bl, byte ptr [0x10010610] */
    if (!c->zf) goto L_00b2b406; /* jne 0xb2b406 */
L_00b2b39f:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    goto L_00b2b268; /* jmp 0xb2b268 */
L_00b2b3a6:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x10], edx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x24], edx */
    if (!c->zf) goto L_00b2b3bf; /* jne 0xb2b3bf */
L_00b2b3b2:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x30u); /* cmp bl, 0x30 */
    if (!c->zf) goto L_00b2b3bf; /* jne 0xb2b3bf */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 8] */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_00b2b3b2; /* jmp 0xb2b3b2 */
L_00b2b3bf:;
    (void)sub32(c, R32((uint32_t)(0xb3060cu)), c->edx); /* cmp dword ptr [0x1001060c], edx */
    if ((c->zf || c->sf != c->of)) goto L_00b2b3d8; /* jle 0xb2b3d8 */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2b3d1u); f_00b26edb(c); /* call 0xb26edb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    goto L_00b2b3e6; /* jmp 0xb2b3e6 */
L_00b2b3d8:;
    c->ecx = (uint32_t)(R32((uint32_t)(0xb30400u))); /* mov ecx, dword ptr [0x10010400] */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & c->esi))); /* and eax, esi */
L_00b2b3e6:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b2b406; /* je 0xb2b406 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x19u); /* cmp dword ptr [ebp - 4], 0x19 */
    if (!c->cf) goto L_00b2b401; /* jae 0xb2b401 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(sub8(c, ((uint8_t)c->ebx), (uint8_t)0x30u)); /* sub bl, 0x30 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff4u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 8] */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [eax], bl */
L_00b2b401:;
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_00b2b3bf; /* jmp 0xb2b3bf */
L_00b2b406:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x2bu); /* cmp bl, 0x2b */
    if (c->zf) goto L_00b2b319; /* je 0xb2b319 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x2du); /* cmp bl, 0x2d */
    if (c->zf) goto L_00b2b319; /* je 0xb2b319 */
    goto L_00b2b2f2; /* jmp 0xb2b2f2 */
L_00b2b41d:;
    (void)sub32(c, R32((uint32_t)(0xb3060cu)), c->edx); /* cmp dword ptr [0x1001060c], edx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x24], edx */
    if ((c->zf || c->sf != c->of)) goto L_00b2b439; /* jle 0xb2b439 */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2b432u); f_00b26edb(c); /* call 0xb26edb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    goto L_00b2b447; /* jmp 0xb2b447 */
L_00b2b439:;
    c->ecx = (uint32_t)(R32((uint32_t)(0xb30400u))); /* mov ecx, dword ptr [0x10010400] */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & c->esi))); /* and eax, esi */
L_00b2b447:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b2b4f9; /* je 0xb2b4f9 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    goto L_00b2b4aa; /* jmp 0xb2b4aa */
L_00b2b453:;
    c->ecx = (uint32_t)((uint32_t)(c->edi + 0xfffffffeu)); /* lea ecx, [edi - 2] */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x31u); /* cmp bl, 0x31 */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp + 0x10], ecx */
    if ((c->sf != c->of)) goto L_00b2b463; /* jl 0xb2b463 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x39u); /* cmp bl, 0x39 */
    if ((c->zf || c->sf != c->of)) goto L_00b2b4a7; /* jle 0xb2b4a7 */
L_00b2b463:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx eax, bl */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x2bu)); /* sub eax, 0x2b */
    if (c->zf) goto L_00b2b4df; /* je 0xb2b4df */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00b2b4d3; /* je 0xb2b4d3 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3u)); /* sub eax, 3 */
    if (!c->zf) goto L_00b2b587; /* jne 0xb2b587 */
L_00b2b478:;
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    goto L_00b2b4e1; /* jmp 0xb2b4e1 */
L_00b2b47c:;
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x20], edx */
L_00b2b47f:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x30u); /* cmp bl, 0x30 */
    if (!c->zf) goto L_00b2b489; /* jne 0xb2b489 */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_00b2b47f; /* jmp 0xb2b47f */
L_00b2b489:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x31u); /* cmp bl, 0x31 */
    if ((c->sf != c->of)) goto L_00b2b584; /* jl 0xb2b584 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x39u); /* cmp bl, 0x39 */
    if ((!c->zf && c->sf == c->of)) goto L_00b2b584; /* jg 0xb2b584 */
    goto L_00b2b4a7; /* jmp 0xb2b4a7 */
L_00b2b49d:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x31u); /* cmp bl, 0x31 */
    if ((c->sf != c->of)) goto L_00b2b4b0; /* jl 0xb2b4b0 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x39u); /* cmp bl, 0x39 */
    if ((!c->zf && c->sf == c->of)) goto L_00b2b4b0; /* jg 0xb2b4b0 */
L_00b2b4a7:;
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
L_00b2b4a9:;
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00b2b4aa:;
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    goto L_00b2b268; /* jmp 0xb2b268 */
L_00b2b4b0:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x30u); /* cmp bl, 0x30 */
    if (!c->zf) goto L_00b2b4f9; /* jne 0xb2b4f9 */
    goto L_00b2b478; /* jmp 0xb2b478 */
L_00b2b4b7:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x20u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x20], 0 */
    if (c->zf) goto L_00b2b4e7; /* je 0xb2b4e7 */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx eax, bl */
    c->ecx = (uint32_t)((uint32_t)(c->edi + 0xffffffffu)); /* lea ecx, [edi - 1] */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x2bu)); /* sub eax, 0x2b */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp + 0x10], ecx */
    if (c->zf) goto L_00b2b4df; /* je 0xb2b4df */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (!c->zf) goto L_00b2b587; /* jne 0xb2b587 */
L_00b2b4d3:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 0x18], 0xffffffff */
    { uint32_t v_ = 0x7u; PUSH32(c, v_); } /* push 7 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_00b2b268; /* jmp 0xb2b268 */
L_00b2b4df:;
    { uint32_t v_ = 0x7u; PUSH32(c, v_); } /* push 7 */
L_00b2b4e1:;
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_00b2b268; /* jmp 0xb2b268 */
L_00b2b4e7:;
    { uint32_t v_ = 0xau; PUSH32(c, v_); } /* push 0xa */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00b2b4eb:;
    (void)sub32(c, c->eax, (uint32_t)0xau); /* cmp eax, 0xa */
    if (c->zf) goto L_00b2b589; /* je 0xb2b589 */
    goto L_00b2b268; /* jmp 0xb2b268 */
L_00b2b4f9:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edi, dword ptr [ebp + 0x10] */
    goto L_00b2b589; /* jmp 0xb2b589 */
L_00b2b501:;
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x20], 1 */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_00b2b50a:;
    (void)sub32(c, R32((uint32_t)(0xb3060cu)), (uint32_t)0x1u); /* cmp dword ptr [0x1001060c], 1 */
    if ((c->zf || c->sf != c->of)) goto L_00b2b522; /* jle 0xb2b522 */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2b51eu); f_00b26edb(c); /* call 0xb26edb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00b2b531; /* jmp 0xb2b531 */
L_00b2b522:;
    c->ecx = (uint32_t)(R32((uint32_t)(0xb30400u))); /* mov ecx, dword ptr [0x10010400] */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4u))); /* and eax, 4 */
L_00b2b531:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b2b551; /* je 0xb2b551 */
    c->ecx = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx ecx, bl */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi * 4)); /* lea eax, [esi + esi*4] */
    c->esi = (uint32_t)((uint32_t)(c->ecx + c->eax * 2 + 0xffffffd0u)); /* lea esi, [ecx + eax*2 - 0x30] */
    (void)sub32(c, c->esi, (uint32_t)0x1450u); /* cmp esi, 0x1450 */
    if ((!c->zf && c->sf == c->of)) goto L_00b2b54c; /* jg 0xb2b54c */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_00b2b50a; /* jmp 0xb2b50a */
L_00b2b54c:;
    c->esi = (uint32_t)((uint32_t)0x1451u); /* mov esi, 0x1451 */
L_00b2b551:;
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x1c], esi */
L_00b2b554:;
    (void)sub32(c, R32((uint32_t)(0xb3060cu)), (uint32_t)0x1u); /* cmp dword ptr [0x1001060c], 1 */
    if ((c->zf || c->sf != c->of)) goto L_00b2b56c; /* jle 0xb2b56c */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2b568u); f_00b26edb(c); /* call 0xb26edb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00b2b57b; /* jmp 0xb2b57b */
L_00b2b56c:;
    c->ecx = (uint32_t)(R32((uint32_t)(0xb30400u))); /* mov ecx, dword ptr [0x10010400] */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4u))); /* and eax, 4 */
L_00b2b57b:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b2b584; /* je 0xb2b584 */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_00b2b554; /* jmp 0xb2b554 */
L_00b2b584:;
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    goto L_00b2b589; /* jmp 0xb2b589 */
L_00b2b587:;
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
L_00b2b589:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x10], 0 */
    W32((uint32_t)(c->eax), (uint32_t)(c->edi)); /* mov dword ptr [eax], edi */
    if (c->zf) goto L_00b2b671; /* je 0xb2b671 */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), c->eax); /* cmp dword ptr [ebp - 4], eax */
    if ((c->cf || c->zf)) goto L_00b2b5b5; /* jbe 0xb2b5b5 */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xffffffbbu)), (uint8_t)0x5u); /* cmp byte ptr [ebp - 0x45], 5 */
    if ((c->sf != c->of)) goto L_00b2b5a9; /* jl 0xb2b5a9 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffbbu); W8(a_, (uint8_t)(inc8(c, R8(a_)))); } /* inc byte ptr [ebp - 0x45] */
L_00b2b5a9:;
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
    goto L_00b2b5b8; /* jmp 0xb2b5b8 */
L_00b2b5b5:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
L_00b2b5b8:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if ((c->cf || c->zf)) goto L_00b2b667; /* jbe 0xb2b667 */
L_00b2b5c2:;
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (!c->zf) goto L_00b2b5d0; /* jne 0xb2b5d0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 4] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
    goto L_00b2b5c2; /* jmp 0xb2b5c2 */
L_00b2b5d0:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffa4u)); /* lea eax, [ebp - 0x5c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2b5e0u); f_00b2ca87(c); /* call 0xb2ca87 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe8u)), c->ecx); /* cmp dword ptr [ebp - 0x18], ecx */
    if ((c->sf == c->of)) goto L_00b2b5ef; /* jge 0xb2b5ef */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
L_00b2b5ef:;
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->ebp + 0xfffffff8u)))); /* add eax, dword ptr [ebp - 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ecx); /* cmp dword ptr [ebp - 0x20], ecx */
    if (!c->zf) goto L_00b2b5fa; /* jne 0xb2b5fa */
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->ebp + 0x18u)))); /* add eax, dword ptr [ebp + 0x18] */
L_00b2b5fa:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), c->ecx); /* cmp dword ptr [ebp - 0x24], ecx */
    if (!c->zf) goto L_00b2b602; /* jne 0xb2b602 */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->ebp + 0x1cu)))); /* sub eax, dword ptr [ebp + 0x1c] */
L_00b2b602:;
    (void)sub32(c, c->eax, (uint32_t)0x1450u); /* cmp eax, 0x1450 */
    if ((c->zf || c->sf != c->of)) goto L_00b2b639; /* jle 0xb2b639 */
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x2c], 1 */
L_00b2b610:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ebx, dword ptr [ebp + 0x10] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov esi, dword ptr [ebp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edx, dword ptr [ebp + 0x10] */
L_00b2b61c:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x2c], 0 */
    if (c->zf) goto L_00b2b682; /* je 0xb2b682 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->eax = (uint32_t)((uint32_t)0x7fffu); /* mov eax, 0x7fff */
    c->esi = (uint32_t)((uint32_t)0x80000000u); /* mov esi, 0x80000000 */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [ebp - 0x14], 2 */
    goto L_00b2b697; /* jmp 0xb2b697 */
L_00b2b639:;
    (void)sub32(c, c->eax, (uint32_t)0xffffebb0u); /* cmp eax, 0xffffebb0 */
    if ((c->sf == c->of)) goto L_00b2b649; /* jge 0xb2b649 */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x30], 1 */
    goto L_00b2b610; /* jmp 0xb2b610 */
L_00b2b649:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2b656u); f_00b2cd6e(c); /* call 0xb2cd6e */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc0u))); /* mov edx, dword ptr [ebp - 0x40] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc2u))); /* mov ebx, dword ptr [ebp - 0x3e] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc6u))); /* mov esi, dword ptr [ebp - 0x3a] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffcau))); /* mov eax, dword ptr [ebp - 0x36] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_00b2b61c; /* jmp 0xb2b61c */
L_00b2b667:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    goto L_00b2b61c; /* jmp 0xb2b61c */
L_00b2b671:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x4u)); /* mov dword ptr [ebp - 0x14], 4 */
    goto L_00b2b697; /* jmp 0xb2b697 */
L_00b2b682:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x30], 0 */
    if (c->zf) goto L_00b2b697; /* je 0xb2b697 */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x14], 1 */
L_00b2b697:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | R32((uint32_t)(c->ebp + 0xffffffd8u))))); /* or eax, dword ptr [ebp - 0x28] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    W32((uint32_t)(c->ecx + 0x6u), (uint32_t)(c->esi)); /* mov dword ptr [ecx + 6], esi */
    W32((uint32_t)(c->ecx + 0x2u), (uint32_t)(c->ebx)); /* mov dword ptr [ecx + 2], ebx */
    W16((uint32_t)(c->ecx + 0xau), (uint16_t)(((uint16_t)c->eax))); /* mov word ptr [ecx + 0xa], ax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W16((uint32_t)(c->ecx), (uint16_t)(((uint16_t)c->edx))); /* mov word ptr [ecx], dx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b2b27b(CPU *c) { /* PTR_00b2b27b */
    PREEMPT_POLL(c);
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x31u); /* cmp bl, 0x31 */
    if ((c->sf != c->of)) goto L_00b2b28c; /* jl 0xb2b28c */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x39u); /* cmp bl, 0x39 */
    if ((!c->zf && c->sf == c->of)) goto L_00b2b28c; /* jg 0xb2b28c */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    goto L_00b2b4a9; /* jmp 0xb2b4a9 */
L_00b2b28c:;
    (void)sub8(c, ((uint8_t)c->ebx), R8((uint32_t)(0xb30610u))); /* cmp bl, byte ptr [0x10010610] */
    if (!c->zf) goto L_00b2b29b; /* jne 0xb2b29b */
    { uint32_t v_ = 0x5u; PUSH32(c, v_); } /* push 5 */
    goto L_00b2b4e1; /* jmp 0xb2b4e1 */
L_00b2b29b:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx eax, bl */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x2bu)); /* sub eax, 0x2b */
    if (c->zf) goto L_00b2b2c1; /* je 0xb2b2c1 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00b2b2b5; /* je 0xb2b2b5 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3u)); /* sub eax, 3 */
    if (!c->zf) goto L_00b2b584; /* jne 0xb2b584 */
    goto L_00b2b344; /* jmp 0xb2b344 */
L_00b2b2b5:;
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)((uint32_t)0x8000u)); /* mov dword ptr [ebp - 0x28], 0x8000 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { jump_indirect(c, 0x00b2b268u, 0x00b2b2bfu); return; } /* jmp 0xb2b268 */
L_00b2b2c1:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffd8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x28], 0 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { jump_indirect(c, 0x00b2b268u, 0x00b2b2c8u); return; } /* jmp 0xb2b268 */
L_00b2b344:;
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    { jump_indirect(c, 0x00b2b268u, 0x00b2b346u); return; } /* jmp 0xb2b268 */
L_00b2b4a9:;
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    { jump_indirect(c, 0x00b2b268u, 0x00b2b4abu); return; } /* jmp 0xb2b268 */
L_00b2b4e1:;
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { jump_indirect(c, 0x00b2b268u, 0x00b2b4e2u); return; } /* jmp 0xb2b268 */
L_00b2b584:;
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    goto L_00b2b589; /* jmp 0xb2b589 */
L_00b2b589:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x10], 0 */
    W32((uint32_t)(c->eax), (uint32_t)(c->edi)); /* mov dword ptr [eax], edi */
    if (c->zf) goto L_00b2b671; /* je 0xb2b671 */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), c->eax); /* cmp dword ptr [ebp - 4], eax */
    if ((c->cf || c->zf)) goto L_00b2b5b5; /* jbe 0xb2b5b5 */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xffffffbbu)), (uint8_t)0x5u); /* cmp byte ptr [ebp - 0x45], 5 */
    if ((c->sf != c->of)) goto L_00b2b5a9; /* jl 0xb2b5a9 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffbbu); W8(a_, (uint8_t)(inc8(c, R8(a_)))); } /* inc byte ptr [ebp - 0x45] */
L_00b2b5a9:;
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
    goto L_00b2b5b8; /* jmp 0xb2b5b8 */
L_00b2b5b5:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
L_00b2b5b8:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if ((c->cf || c->zf)) goto L_00b2b667; /* jbe 0xb2b667 */
L_00b2b5c2:;
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (!c->zf) goto L_00b2b5d0; /* jne 0xb2b5d0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 4] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
    goto L_00b2b5c2; /* jmp 0xb2b5c2 */
L_00b2b5d0:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffa4u)); /* lea eax, [ebp - 0x5c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2b5e0u); f_00b2ca87(c); /* call 0xb2ca87 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe8u)), c->ecx); /* cmp dword ptr [ebp - 0x18], ecx */
    if ((c->sf == c->of)) goto L_00b2b5ef; /* jge 0xb2b5ef */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
L_00b2b5ef:;
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->ebp + 0xfffffff8u)))); /* add eax, dword ptr [ebp - 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ecx); /* cmp dword ptr [ebp - 0x20], ecx */
    if (!c->zf) goto L_00b2b5fa; /* jne 0xb2b5fa */
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->ebp + 0x18u)))); /* add eax, dword ptr [ebp + 0x18] */
L_00b2b5fa:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), c->ecx); /* cmp dword ptr [ebp - 0x24], ecx */
    if (!c->zf) goto L_00b2b602; /* jne 0xb2b602 */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->ebp + 0x1cu)))); /* sub eax, dword ptr [ebp + 0x1c] */
L_00b2b602:;
    (void)sub32(c, c->eax, (uint32_t)0x1450u); /* cmp eax, 0x1450 */
    if ((c->zf || c->sf != c->of)) goto L_00b2b639; /* jle 0xb2b639 */
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x2c], 1 */
L_00b2b610:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ebx, dword ptr [ebp + 0x10] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov esi, dword ptr [ebp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edx, dword ptr [ebp + 0x10] */
L_00b2b61c:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x2c], 0 */
    if (c->zf) goto L_00b2b682; /* je 0xb2b682 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->eax = (uint32_t)((uint32_t)0x7fffu); /* mov eax, 0x7fff */
    c->esi = (uint32_t)((uint32_t)0x80000000u); /* mov esi, 0x80000000 */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [ebp - 0x14], 2 */
    goto L_00b2b697; /* jmp 0xb2b697 */
L_00b2b639:;
    (void)sub32(c, c->eax, (uint32_t)0xffffebb0u); /* cmp eax, 0xffffebb0 */
    if ((c->sf == c->of)) goto L_00b2b649; /* jge 0xb2b649 */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x30], 1 */
    goto L_00b2b610; /* jmp 0xb2b610 */
L_00b2b649:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2b656u); f_00b2cd6e(c); /* call 0xb2cd6e */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc0u))); /* mov edx, dword ptr [ebp - 0x40] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc2u))); /* mov ebx, dword ptr [ebp - 0x3e] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc6u))); /* mov esi, dword ptr [ebp - 0x3a] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffcau))); /* mov eax, dword ptr [ebp - 0x36] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_00b2b61c; /* jmp 0xb2b61c */
L_00b2b667:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    goto L_00b2b61c; /* jmp 0xb2b61c */
L_00b2b671:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x4u)); /* mov dword ptr [ebp - 0x14], 4 */
    goto L_00b2b697; /* jmp 0xb2b697 */
L_00b2b682:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x30], 0 */
    if (c->zf) goto L_00b2b697; /* je 0xb2b697 */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x14], 1 */
L_00b2b697:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | R32((uint32_t)(c->ebp + 0xffffffd8u))))); /* or eax, dword ptr [ebp - 0x28] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    W32((uint32_t)(c->ecx + 0x6u), (uint32_t)(c->esi)); /* mov dword ptr [ecx + 6], esi */
    W32((uint32_t)(c->ecx + 0x2u), (uint32_t)(c->ebx)); /* mov dword ptr [ecx + 2], ebx */
    W16((uint32_t)(c->ecx + 0xau), (uint16_t)(((uint16_t)c->eax))); /* mov word ptr [ecx + 0xa], ax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W16((uint32_t)(c->ecx), (uint16_t)(((uint16_t)c->edx))); /* mov word ptr [ecx], dx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b2b4f9(CPU *c) { /* PTR_00b2b4f9 */
    PREEMPT_POLL(c);
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edi, dword ptr [ebp + 0x10] */
    goto L_00b2b589; /* jmp 0xb2b589 */
L_00b2b589:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x10], 0 */
    W32((uint32_t)(c->eax), (uint32_t)(c->edi)); /* mov dword ptr [eax], edi */
    if (c->zf) goto L_00b2b671; /* je 0xb2b671 */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), c->eax); /* cmp dword ptr [ebp - 4], eax */
    if ((c->cf || c->zf)) goto L_00b2b5b5; /* jbe 0xb2b5b5 */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xffffffbbu)), (uint8_t)0x5u); /* cmp byte ptr [ebp - 0x45], 5 */
    if ((c->sf != c->of)) goto L_00b2b5a9; /* jl 0xb2b5a9 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffbbu); W8(a_, (uint8_t)(inc8(c, R8(a_)))); } /* inc byte ptr [ebp - 0x45] */
L_00b2b5a9:;
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
    goto L_00b2b5b8; /* jmp 0xb2b5b8 */
L_00b2b5b5:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
L_00b2b5b8:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if ((c->cf || c->zf)) goto L_00b2b667; /* jbe 0xb2b667 */
L_00b2b5c2:;
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (!c->zf) goto L_00b2b5d0; /* jne 0xb2b5d0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 4] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
    goto L_00b2b5c2; /* jmp 0xb2b5c2 */
L_00b2b5d0:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffa4u)); /* lea eax, [ebp - 0x5c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2b5e0u); f_00b2ca87(c); /* call 0xb2ca87 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe8u)), c->ecx); /* cmp dword ptr [ebp - 0x18], ecx */
    if ((c->sf == c->of)) goto L_00b2b5ef; /* jge 0xb2b5ef */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
L_00b2b5ef:;
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->ebp + 0xfffffff8u)))); /* add eax, dword ptr [ebp - 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ecx); /* cmp dword ptr [ebp - 0x20], ecx */
    if (!c->zf) goto L_00b2b5fa; /* jne 0xb2b5fa */
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->ebp + 0x18u)))); /* add eax, dword ptr [ebp + 0x18] */
L_00b2b5fa:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), c->ecx); /* cmp dword ptr [ebp - 0x24], ecx */
    if (!c->zf) goto L_00b2b602; /* jne 0xb2b602 */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->ebp + 0x1cu)))); /* sub eax, dword ptr [ebp + 0x1c] */
L_00b2b602:;
    (void)sub32(c, c->eax, (uint32_t)0x1450u); /* cmp eax, 0x1450 */
    if ((c->zf || c->sf != c->of)) goto L_00b2b639; /* jle 0xb2b639 */
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x2c], 1 */
L_00b2b610:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ebx, dword ptr [ebp + 0x10] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov esi, dword ptr [ebp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edx, dword ptr [ebp + 0x10] */
L_00b2b61c:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x2c], 0 */
    if (c->zf) goto L_00b2b682; /* je 0xb2b682 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->eax = (uint32_t)((uint32_t)0x7fffu); /* mov eax, 0x7fff */
    c->esi = (uint32_t)((uint32_t)0x80000000u); /* mov esi, 0x80000000 */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [ebp - 0x14], 2 */
    goto L_00b2b697; /* jmp 0xb2b697 */
L_00b2b639:;
    (void)sub32(c, c->eax, (uint32_t)0xffffebb0u); /* cmp eax, 0xffffebb0 */
    if ((c->sf == c->of)) goto L_00b2b649; /* jge 0xb2b649 */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x30], 1 */
    goto L_00b2b610; /* jmp 0xb2b610 */
L_00b2b649:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2b656u); f_00b2cd6e(c); /* call 0xb2cd6e */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc0u))); /* mov edx, dword ptr [ebp - 0x40] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc2u))); /* mov ebx, dword ptr [ebp - 0x3e] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc6u))); /* mov esi, dword ptr [ebp - 0x3a] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffcau))); /* mov eax, dword ptr [ebp - 0x36] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_00b2b61c; /* jmp 0xb2b61c */
L_00b2b667:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    goto L_00b2b61c; /* jmp 0xb2b61c */
L_00b2b671:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x4u)); /* mov dword ptr [ebp - 0x14], 4 */
    goto L_00b2b697; /* jmp 0xb2b697 */
L_00b2b682:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x30], 0 */
    if (c->zf) goto L_00b2b697; /* je 0xb2b697 */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x14], 1 */
L_00b2b697:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | R32((uint32_t)(c->ebp + 0xffffffd8u))))); /* or eax, dword ptr [ebp - 0x28] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    W32((uint32_t)(c->ecx + 0x6u), (uint32_t)(c->esi)); /* mov dword ptr [ecx + 6], esi */
    W32((uint32_t)(c->ecx + 0x2u), (uint32_t)(c->ebx)); /* mov dword ptr [ecx + 2], ebx */
    W16((uint32_t)(c->ecx + 0xau), (uint16_t)(((uint16_t)c->eax))); /* mov word ptr [ecx + 0xa], ax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W16((uint32_t)(c->ecx), (uint16_t)(((uint16_t)c->edx))); /* mov word ptr [ecx], dx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b2b6e2(CPU *c) { /* FUN_1000b6e2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xb2e740u; PUSH32(c, v_); } /* push 0x1000e740 */
    { uint32_t v_ = 0xb273f8u; PUSH32(c, v_); } /* push 0x100073f8 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    c->eax = (uint32_t)(R32((uint32_t)(0xb3364cu))); /* mov eax, dword ptr [0x1001364c] */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (!c->zf) goto L_00b2b751; /* jne 0xb2b751 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe4u)); /* lea eax, [ebp - 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0xb2e73cu; PUSH32(c, v_); } /* push 0x1000e73c */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(0xb2e0bcu)); PUSH32(c, 0x00b2b727u); call_indirect(c, t_); } /* call dword ptr [0x1000e0bc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b2b72f; /* je 0xb2b72f */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    goto L_00b2b74c; /* jmp 0xb2b74c */
L_00b2b72f:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe4u)); /* lea eax, [ebp - 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0xb2e738u; PUSH32(c, v_); } /* push 0x1000e738 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(0xb2e0b8u)); PUSH32(c, 0x00b2b741u); call_indirect(c, t_); } /* call dword ptr [0x1000e0b8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b2b817; /* je 0xb2b817 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00b2b74c:;
    W32((uint32_t)(0xb3364cu), (uint32_t)(c->eax)); /* mov dword ptr [0x1001364c], eax */
L_00b2b751:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00b2b77a; /* jne 0xb2b77a */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov eax, dword ptr [ebp + 0x1c] */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (!c->zf) goto L_00b2b762; /* jne 0xb2b762 */
    c->eax = (uint32_t)(R32((uint32_t)(0xb3367cu))); /* mov eax, dword ptr [0x1001367c] */
L_00b2b762:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0xb2e0b8u)); PUSH32(c, 0x00b2b775u); call_indirect(c, t_); } /* call dword ptr [0x1000e0b8] */
    goto L_00b2b819; /* jmp 0xb2b819 */
L_00b2b77a:;
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_00b2b817; /* jne 0xb2b817 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x18u)), c->ebx); /* cmp dword ptr [ebp + 0x18], ebx */
    if (!c->zf) goto L_00b2b790; /* jne 0xb2b790 */
    c->eax = (uint32_t)(R32((uint32_t)(0xb3368cu))); /* mov eax, dword ptr [0x1001368c] */
    W32((uint32_t)(c->ebp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x18], eax */
L_00b2b790:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x20u))); /* mov eax, dword ptr [ebp + 0x20] */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x8u))); /* and eax, 8 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t t_ = R32((uint32_t)(0xb2e0b4u)); PUSH32(c, 0x00b2b7adu); call_indirect(c, t_); } /* call dword ptr [0x1000e0b4] */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_00b2b817; /* je 0xb2b817 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 4], ebx */
    c->edi = (uint32_t)((uint32_t)(c->eax + c->eax)); /* lea edi, [eax + eax] */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x3u)); /* add eax, 3 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfcu))); /* and al, 0xfc */
    PUSH32(c, 0x00b2b7c6u); f_00b2c630(c); /* call 0xb2c630 */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    c->esi = (uint32_t)(c->esp); /* mov esi, esp */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x24], esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b2b7d6u); f_00b2bd50(c); /* call 0xb2bd50 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_00b2b7e6; /* jmp 0xb2b7e6 */
L_00b2b7e6:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (c->zf) goto L_00b2b817; /* je 0xb2b817 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x20] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t t_ = R32((uint32_t)(0xb2e0b4u)); PUSH32(c, 0x00b2b803u); call_indirect(c, t_); } /* call dword ptr [0x1000e0b4] */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_00b2b817; /* je 0xb2b817 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0xb2e0bcu)); PUSH32(c, 0x00b2b815u); call_indirect(c, t_); } /* call dword ptr [0x1000e0bc] */
    goto L_00b2b819; /* jmp 0xb2b819 */
L_00b2b817:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00b2b819:;
    c->esp = (uint32_t)((uint32_t)(c->ebp + 0xffffffccu)); /* lea esp, [ebp - 0x34] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b2b7db(CPU *c) { /* PTR_00b2b7db */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_00b2b7df(CPU *c) { /* PTR_00b2b7df */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (c->zf) goto L_00b2b817; /* je 0xb2b817 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x20] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t t_ = R32((uint32_t)(0xb2e0b4u)); PUSH32(c, 0x00b2b803u); call_indirect(c, t_); } /* call dword ptr [0x1000e0b4] */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_00b2b817; /* je 0xb2b817 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0xb2e0bcu)); PUSH32(c, 0x00b2b815u); call_indirect(c, t_); } /* call dword ptr [0x1000e0bc] */
    goto L_00b2b819; /* jmp 0xb2b819 */
L_00b2b817:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00b2b819:;
    c->esp = (uint32_t)((uint32_t)(c->ebp + 0xffffffccu)); /* lea esp, [ebp - 0x34] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b2b82b(CPU *c) { /* FUN_1000b82b */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    ; /* wait  */
    W16((uint32_t)(c->ebp + 0xfffffffcu), c->fpu_cw); /* fnstcw word ptr [ebp - 4] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    PUSH32(c, 0x00b2b83cu); f_00b2b876(c); /* call 0xb2b876 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)((uint32_t)~c->eax); /* not eax */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & c->eax))); /* and esi, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & R32((uint32_t)(c->ebp + 0xcu))))); /* and eax, dword ptr [ebp + 0xc] */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi | c->eax))); /* or esi, eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b2b853u); f_00b2b908(c); /* call 0xb2b908 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0xc], eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->fpu_cw = R16((uint32_t)(c->ebp + 0xcu)); fpu_sync_rounding(c); /* fldcw word ptr [ebp + 0xc] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b2b860(CPU *c) { /* FUN_1000b860 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xfff7ffffu))); /* and eax, 0xfff7ffff */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    PUSH32(c, 0x00b2b873u); f_00b2b82b(c); /* call 0xb2b82b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00b2b876(CPU *c) { /* FUN_1000b876 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ebx, dword ptr [esp + 8] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x1u)); /* test bl, 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (c->zf) goto L_00b2b887; /* je 0xb2b887 */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00b2b887:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x4u)); /* test bl, 4 */
    if (c->zf) goto L_00b2b88e; /* je 0xb2b88e */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x8u))); /* or al, 8 */
L_00b2b88e:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x8u)); /* test bl, 8 */
    if (c->zf) goto L_00b2b895; /* je 0xb2b895 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x4u))); /* or al, 4 */
L_00b2b895:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x10u)); /* test bl, 0x10 */
    if (c->zf) goto L_00b2b89c; /* je 0xb2b89c */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x2u))); /* or al, 2 */
L_00b2b89c:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x20u)); /* test bl, 0x20 */
    if (c->zf) goto L_00b2b8a3; /* je 0xb2b8a3 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x1u))); /* or al, 1 */
L_00b2b8a3:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x2u)); /* test bl, 2 */
    if (c->zf) goto L_00b2b8ad; /* je 0xb2b8ad */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0x80000u))); /* or eax, 0x80000 */
L_00b2b8ad:;
    c->ecx = (uint32_t)((uint32_t)((uint16_t)c->ebx)); /* movzx ecx, bx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    c->esi = (uint32_t)((uint32_t)0xc00u); /* mov esi, 0xc00 */
    c->edi = (uint32_t)((uint32_t)0x300u); /* mov edi, 0x300 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & c->esi))); /* and edx, esi */
    c->ebp = (uint32_t)((uint32_t)0x200u); /* mov ebp, 0x200 */
    if (c->zf) goto L_00b2b8e5; /* je 0xb2b8e5 */
    (void)sub32(c, c->edx, (uint32_t)0x400u); /* cmp edx, 0x400 */
    if (c->zf) goto L_00b2b8e2; /* je 0xb2b8e2 */
    (void)sub32(c, c->edx, (uint32_t)0x800u); /* cmp edx, 0x800 */
    if (c->zf) goto L_00b2b8de; /* je 0xb2b8de */
    (void)sub32(c, c->edx, c->esi); /* cmp edx, esi */
    if (!c->zf) goto L_00b2b8e5; /* jne 0xb2b8e5 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->edi))); /* or eax, edi */
    goto L_00b2b8e5; /* jmp 0xb2b8e5 */
L_00b2b8de:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->ebp))); /* or eax, ebp */
    goto L_00b2b8e5; /* jmp 0xb2b8e5 */
L_00b2b8e2:;
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | (uint8_t)0x1u))) << 8); /* or ah, 1 */
L_00b2b8e5:;
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & c->edi))); /* and ecx, edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    if (c->zf) goto L_00b2b8f5; /* je 0xb2b8f5 */
    (void)sub32(c, c->ecx, c->ebp); /* cmp ecx, ebp */
    if (!c->zf) goto L_00b2b8fa; /* jne 0xb2b8fa */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0x10000u))); /* or eax, 0x10000 */
    goto L_00b2b8fa; /* jmp 0xb2b8fa */
L_00b2b8f5:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0x20000u))); /* or eax, 0x20000 */
L_00b2b8fa:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->ebx >> 8)) & (uint8_t)0x10u)); /* test bh, 0x10 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    if (c->zf) goto L_00b2b907; /* je 0xb2b907 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0x40000u))); /* or eax, 0x40000 */
L_00b2b907:;
    c->esp += 4; return; /* ret  */
}

void f_00b2b908(CPU *c) { /* FUN_1000b908 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ebx, dword ptr [esp + 8] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x10u)); /* test bl, 0x10 */
    if (c->zf) goto L_00b2b918; /* je 0xb2b918 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00b2b918:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x8u)); /* test bl, 8 */
    if (c->zf) goto L_00b2b91f; /* je 0xb2b91f */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x4u))); /* or al, 4 */
L_00b2b91f:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x4u)); /* test bl, 4 */
    if (c->zf) goto L_00b2b926; /* je 0xb2b926 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x8u))); /* or al, 8 */
L_00b2b926:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x2u)); /* test bl, 2 */
    if (c->zf) goto L_00b2b92d; /* je 0xb2b92d */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x10u))); /* or al, 0x10 */
L_00b2b92d:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x1u)); /* test bl, 1 */
    if (c->zf) goto L_00b2b934; /* je 0xb2b934 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x20u))); /* or al, 0x20 */
L_00b2b934:;
    (void)logic32(c, (uint32_t)(c->ebx & (uint32_t)0x80000u)); /* test ebx, 0x80000 */
    if (c->zf) goto L_00b2b93e; /* je 0xb2b93e */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x2u))); /* or al, 2 */
L_00b2b93e:;
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    c->edx = (uint32_t)((uint32_t)0x300u); /* mov edx, 0x300 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & c->edx))); /* and ecx, edx */
    c->esi = (uint32_t)((uint32_t)0x200u); /* mov esi, 0x200 */
    if (c->zf) goto L_00b2b96b; /* je 0xb2b96b */
    (void)sub32(c, c->ecx, (uint32_t)0x100u); /* cmp ecx, 0x100 */
    if (c->zf) goto L_00b2b968; /* je 0xb2b968 */
    (void)sub32(c, c->ecx, c->esi); /* cmp ecx, esi */
    if (c->zf) goto L_00b2b963; /* je 0xb2b963 */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if (!c->zf) goto L_00b2b96b; /* jne 0xb2b96b */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | (uint8_t)0xcu))) << 8); /* or ah, 0xc */
    goto L_00b2b96b; /* jmp 0xb2b96b */
L_00b2b963:;
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | (uint8_t)0x8u))) << 8); /* or ah, 8 */
    goto L_00b2b96b; /* jmp 0xb2b96b */
L_00b2b968:;
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | (uint8_t)0x4u))) << 8); /* or ah, 4 */
L_00b2b96b:;
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x30000u))); /* and ecx, 0x30000 */
    if (c->zf) goto L_00b2b981; /* je 0xb2b981 */
    (void)sub32(c, c->ecx, (uint32_t)0x10000u); /* cmp ecx, 0x10000 */
    if (!c->zf) goto L_00b2b983; /* jne 0xb2b983 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->esi))); /* or eax, esi */
    goto L_00b2b983; /* jmp 0xb2b983 */
L_00b2b981:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->edx))); /* or eax, edx */
L_00b2b983:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    (void)logic32(c, (uint32_t)(c->ebx & (uint32_t)0x40000u)); /* test ebx, 0x40000 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    if (c->zf) goto L_00b2b990; /* je 0xb2b990 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | (uint8_t)0x10u))) << 8); /* or ah, 0x10 */
L_00b2b990:;
    c->esp += 4; return; /* ret  */
}

void f_00b2b991(CPU *c) { /* FUN_1000b991 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, R32((uint32_t)(0xb3367cu)), c->ebx); /* cmp dword ptr [0x1001367c], ebx */
    if (!c->zf) goto L_00b2b9af; /* jne 0xb2b9af */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    (void)sub32(c, c->eax, (uint32_t)0x41u); /* cmp eax, 0x41 */
    if ((c->sf != c->of)) goto L_00b2b9fe; /* jl 0xb2b9fe */
    (void)sub32(c, c->eax, (uint32_t)0x5au); /* cmp eax, 0x5a */
    if ((!c->zf && c->sf == c->of)) goto L_00b2b9fe; /* jg 0xb2b9fe */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x20u)); /* add eax, 0x20 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_00b2b9af:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)((uint32_t)0xb337e4u); /* mov esi, 0x100137e4 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(0xb2e0c4u)); PUSH32(c, 0x00b2b9bdu); call_indirect(c, t_); } /* call dword ptr [0x1000e0c4] */
    (void)sub32(c, R32((uint32_t)(0xb337e0u)), c->ebx); /* cmp dword ptr [0x100137e0], ebx */
    c->edi = (uint32_t)(R32((uint32_t)(0xb2e0c0u))); /* mov edi, dword ptr [0x1000e0c0] */
    if (c->zf) goto L_00b2b9d9; /* je 0xb2b9d9 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00b2b9ceu); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x00b2b9d5u); f_00b27565(c); /* call 0xb27565 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
L_00b2b9d9:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    PUSH32(c, 0x00b2b9e2u); f_00b2ba00(c); /* call 0xb2ba00 */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    if (c->zf) goto L_00b2b9f5; /* je 0xb2b9f5 */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x00b2b9f2u); f_00b275c6(c); /* call 0xb275c6 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00b2b9f8; /* jmp 0xb2b9f8 */
L_00b2b9f5:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00b2b9f8u); call_indirect(c, t_); } /* call edi */
L_00b2b9f8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00b2b9fe:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00b2ba00(CPU *c) { /* FUN_1000ba00 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    (void)sub32(c, R32((uint32_t)(0xb3367cu)), (uint32_t)0x0u); /* cmp dword ptr [0x1001367c], 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00b2ba2d; /* jne 0xb2ba2d */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)sub32(c, c->eax, (uint32_t)0x41u); /* cmp eax, 0x41 */
    if ((c->sf != c->of)) goto L_00b2bac6; /* jl 0xb2bac6 */
    (void)sub32(c, c->eax, (uint32_t)0x5au); /* cmp eax, 0x5a */
    if ((!c->zf && c->sf == c->of)) goto L_00b2bac6; /* jg 0xb2bac6 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x20u)); /* add eax, 0x20 */
    goto L_00b2bac6; /* jmp 0xb2bac6 */
L_00b2ba2d:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    c->edi = (uint32_t)((uint32_t)0x100u); /* mov edi, 0x100 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    if ((c->sf == c->of)) goto L_00b2ba61; /* jge 0xb2ba61 */
    (void)sub32(c, R32((uint32_t)(0xb3060cu)), c->esi); /* cmp dword ptr [0x1001060c], esi */
    if ((c->zf || c->sf != c->of)) goto L_00b2ba4f; /* jle 0xb2ba4f */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b2ba4bu); f_00b26edb(c); /* call 0xb26edb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00b2ba59; /* jmp 0xb2ba59 */
L_00b2ba4f:;
    c->eax = (uint32_t)(R32((uint32_t)(0xb30400u))); /* mov eax, dword ptr [0x10010400] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + c->ebx * 2))); /* mov al, byte ptr [eax + ebx*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & c->esi))); /* and eax, esi */
L_00b2ba59:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b2ba61; /* jne 0xb2ba61 */
L_00b2ba5d:;
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    goto L_00b2bac6; /* jmp 0xb2bac6 */
L_00b2ba61:;
    c->edx = (uint32_t)(R32((uint32_t)(0xb30400u))); /* mov edx, dword ptr [0x10010400] */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->eax = (uint32_t)(sar32(c, c->eax, 8)); /* sar eax, 8 */
    c->ecx = (uint32_t)((uint32_t)((uint8_t)c->eax)); /* movzx ecx, al */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edx + c->ecx * 2 + 0x1u)) & (uint8_t)0x80u)); /* test byte ptr [edx + ecx*2 + 1], 0x80 */
    if (c->zf) goto L_00b2ba85; /* je 0xb2ba85 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xau); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp + 0xa], 0 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    W8((uint32_t)(c->ebp + 0x8u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp + 8], al */
    W8((uint32_t)(c->ebp + 0x9u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ebp + 9], bl */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_00b2ba8e; /* jmp 0xb2ba8e */
L_00b2ba85:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0x9u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp + 9], 0 */
    W8((uint32_t)(c->ebp + 0x8u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ebp + 8], bl */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00b2ba8e:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea ecx, [ebp - 4] */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x8u)); /* lea eax, [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0xb3367cu)); PUSH32(c, v_); } /* push dword ptr [0x1001367c] */
    PUSH32(c, 0x00b2baa8u); f_00b2cdea(c); /* call 0xb2cdea */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b2ba5d; /* je 0xb2ba5d */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (!c->zf) goto L_00b2bab9; /* jne 0xb2bab9 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0xfffffffcu))); /* movzx eax, byte ptr [ebp - 4] */
    goto L_00b2bac6; /* jmp 0xb2bac6 */
L_00b2bab9:;
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0xfffffffdu))); /* movzx eax, byte ptr [ebp - 3] */
    c->ecx = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0xfffffffcu))); /* movzx ecx, byte ptr [ebp - 4] */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->ecx))); /* or eax, ecx */
L_00b2bac6:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b2bacb(CPU *c) { /* FUN_1000bacb */
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
    if ((c->zf || c->sf != c->of)) goto L_00b2bb08; /* jle 0xb2bb08 */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 8], ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
L_00b2baee:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov dl, byte ptr [ecx] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00b2bafa; /* je 0xb2bafa */
    c->edx = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->edx)); /* movsx edx, dl */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    goto L_00b2bafd; /* jmp 0xb2bafd */
L_00b2bafa:;
    { uint32_t v_ = 0x30u; PUSH32(c, v_); } /* push 0x30 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
L_00b2bafd:;
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [eax], dl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 8] */
    if (!c->zf) goto L_00b2baee; /* jne 0xb2baee */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edx, dword ptr [ebp + 0x10] */
L_00b2bb08:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax], 0 */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if ((c->sf != c->of)) goto L_00b2bb21; /* jl 0xb2bb21 */
    (void)sub8(c, R8((uint32_t)(c->ecx)), (uint8_t)0x35u); /* cmp byte ptr [ecx], 0x35 */
    if ((c->sf != c->of)) goto L_00b2bb21; /* jl 0xb2bb21 */
L_00b2bb14:;
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x39u); /* cmp byte ptr [eax], 0x39 */
    if (!c->zf) goto L_00b2bb1f; /* jne 0xb2bb1f */
    W8((uint32_t)(c->eax), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [eax], 0x30 */
    goto L_00b2bb14; /* jmp 0xb2bb14 */
L_00b2bb1f:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(inc8(c, R8(a_)))); } /* inc byte ptr [eax] */
L_00b2bb21:;
    (void)sub8(c, R8((uint32_t)(c->esi)), (uint8_t)0x31u); /* cmp byte ptr [esi], 0x31 */
    if (!c->zf) goto L_00b2bb2b; /* jne 0xb2bb2b */
    { uint32_t a_ = (uint32_t)(c->edx + 0x4u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [edx + 4] */
    goto L_00b2bb3d; /* jmp 0xb2bb3d */
L_00b2bb2b:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b2bb31u); f_00b26e60(c); /* call 0xb26e60 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b2bb3au); f_00b29430(c); /* call 0xb29430 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_00b2bb3d:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00b2bb42(CPU *c) { /* FUN_1000bb42 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x28u)); /* sub esp, 0x28 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x8u)); /* lea eax, [ebp + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2bb57u); f_00b2bb9e(c); /* call 0xb2bb9e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd8u)); /* lea eax, [ebp - 0x28] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esi = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea esi, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x11u; PUSH32(c, v_); } /* push 0x11 */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    W16(c->edi, R16(c->esi)); c->esi += (c->df ? -2 : 2); c->edi += (c->df ? -2 : 2); /* movsw word ptr es:[edi], word ptr [esi] */
    PUSH32(c, 0x00b2bb72u); f_00b2d039(c); /* call 0xb2d039 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov esi, dword ptr [ebp + 0x10] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov edi, dword ptr [ebp + 0x14] */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 8], eax */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->ebp + 0xffffffdau))); /* movsx eax, byte ptr [ebp - 0x26] */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int16_t)R16((uint32_t)(c->ebp + 0xffffffd8u))); /* movsx eax, word ptr [ebp - 0x28] */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffdcu)); /* lea eax, [ebp - 0x24] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00b2bb92u); f_00b2bc60(c); /* call 0xb2bc60 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0xc], edi */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b2bb9e(CPU *c) { /* FUN_1000bb9e */
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
    if (c->zf) goto L_00b2bbec; /* je 0xb2bbec */
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    if (c->zf) goto L_00b2bbe5; /* je 0xb2bbe5 */
    c->edi = (uint32_t)((uint32_t)(c->ecx + 0x3c00u)); /* lea edi, [ecx + 0x3c00] */
    goto L_00b2bc0d; /* jmp 0xb2bc0d */
L_00b2bbe5:;
    c->edi = (uint32_t)((uint32_t)0x7fffu); /* mov edi, 0x7fff */
    goto L_00b2bc0d; /* jmp 0xb2bc0d */
L_00b2bbec:;
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (!c->zf) goto L_00b2bc04; /* jne 0xb2bc04 */
    (void)sub32(c, c->edx, c->ebx); /* cmp edx, ebx */
    if (!c->zf) goto L_00b2bc04; /* jne 0xb2bc04 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 4], ebx */
    W32((uint32_t)(c->eax), (uint32_t)(c->ebx)); /* mov dword ptr [eax], ebx */
    W16((uint32_t)(c->eax + 0x8u), (uint16_t)(((uint16_t)c->ebx))); /* mov word ptr [eax + 8], bx */
    goto L_00b2bc4f; /* jmp 0xb2bc4f */
L_00b2bc04:;
    c->edi = (uint32_t)((uint32_t)(c->ecx + 0x3c01u)); /* lea edi, [ecx + 0x3c01] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 4], ebx */
L_00b2bc0d:;
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 21)); /* shr ecx, 0x15 */
    c->eax = (uint32_t)(shl32(c, c->eax, 11)); /* shl eax, 0xb */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->eax))); /* or ecx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | R32((uint32_t)(c->ebp + 0xfffffffcu))))); /* or ecx, dword ptr [ebp - 4] */
    c->edx = (uint32_t)(shl32(c, c->edx, 11)); /* shl edx, 0xb */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 4], ecx */
    W32((uint32_t)(c->eax), (uint32_t)(c->edx)); /* mov dword ptr [eax], edx */
L_00b2bc25:;
    (void)logic32(c, (uint32_t)(c->esi & c->ecx)); /* test esi, ecx */
    if (!c->zf) goto L_00b2bc46; /* jne 0xb2bc46 */
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
    goto L_00b2bc25; /* jmp 0xb2bc25 */
L_00b2bc46:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->edi))); /* or ecx, edi */
    W16((uint32_t)(c->eax + 0x8u), (uint16_t)(((uint16_t)c->ecx))); /* mov word ptr [eax + 8], cx */
L_00b2bc4f:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b2bc60(CPU *c) { /* FUN_1000bc60 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edi, dword ptr [esp + 8] */
    { f_00b2bcd1(c); return; } /* jmp 0xb2bcd1 */
}

void f_00b2bc70(CPU *c) { /* FUN_1000bc70 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u)); /* test ecx, 3 */
    if (c->zf) goto L_00b2bc8c; /* je 0xb2bc8c */
L_00b2bc7d:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov al, byte ptr [ecx] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00b2bcbf; /* je 0xb2bcbf */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u)); /* test ecx, 3 */
    if (!c->zf) goto L_00b2bc7d; /* jne 0xb2bc7d */
L_00b2bc8c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)((uint32_t)0x7efefeffu); /* mov edx, 0x7efefeff */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ (uint32_t)0xffffffffu))); /* xor eax, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ c->edx))); /* xor eax, edx */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u)); /* test eax, 0x81010100 */
    if (c->zf) goto L_00b2bc8c; /* je 0xb2bc8c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0xfffffffcu))); /* mov eax, dword ptr [ecx - 4] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00b2bcce; /* je 0xb2bcce */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_00b2bcc9; /* je 0xb2bcc9 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0xff0000u)); /* test eax, 0xff0000 */
    if (c->zf) goto L_00b2bcc4; /* je 0xb2bcc4 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0xff000000u)); /* test eax, 0xff000000 */
    if (c->zf) goto L_00b2bcbf; /* je 0xb2bcbf */
    goto L_00b2bc8c; /* jmp 0xb2bc8c */
L_00b2bcbf:;
    c->edi = (uint32_t)((uint32_t)(c->ecx + 0xffffffffu)); /* lea edi, [ecx - 1] */
    goto L_00b2bcd1; /* jmp 0xb2bcd1 */
L_00b2bcc4:;
    c->edi = (uint32_t)((uint32_t)(c->ecx + 0xfffffffeu)); /* lea edi, [ecx - 2] */
    goto L_00b2bcd1; /* jmp 0xb2bcd1 */
L_00b2bcc9:;
    c->edi = (uint32_t)((uint32_t)(c->ecx + 0xfffffffdu)); /* lea edi, [ecx - 3] */
    goto L_00b2bcd1; /* jmp 0xb2bcd1 */
L_00b2bcce:;
    c->edi = (uint32_t)((uint32_t)(c->ecx + 0xfffffffcu)); /* lea edi, [ecx - 4] */
L_00b2bcd1:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u)); /* test ecx, 3 */
    if (c->zf) goto L_00b2bcf6; /* je 0xb2bcf6 */
L_00b2bcdd:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov dl, byte ptr [ecx] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00b2bd48; /* je 0xb2bd48 */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [edi], dl */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u)); /* test ecx, 3 */
    if (!c->zf) goto L_00b2bcdd; /* jne 0xb2bcdd */
    goto L_00b2bcf6; /* jmp 0xb2bcf6 */
L_00b2bcf1:;
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
L_00b2bcf6:;
    c->edx = (uint32_t)((uint32_t)0x7efefeffu); /* mov edx, 0x7efefeff */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ (uint32_t)0xffffffffu))); /* xor eax, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ c->edx))); /* xor eax, edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u)); /* test eax, 0x81010100 */
    if (c->zf) goto L_00b2bcf1; /* je 0xb2bcf1 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00b2bd48; /* je 0xb2bd48 */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->edx >> 8)) & ((uint8_t)(c->edx >> 8)))); /* test dh, dh */
    if (c->zf) goto L_00b2bd3f; /* je 0xb2bd3f */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0xff0000u)); /* test edx, 0xff0000 */
    if (c->zf) goto L_00b2bd32; /* je 0xb2bd32 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0xff000000u)); /* test edx, 0xff000000 */
    if (c->zf) goto L_00b2bd2a; /* je 0xb2bd2a */
    goto L_00b2bcf1; /* jmp 0xb2bcf1 */
L_00b2bd2a:;
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_00b2bd32:;
    W16((uint32_t)(c->edi), (uint16_t)(((uint16_t)c->edx))); /* mov word ptr [edi], dx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [edi + 2], 0 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_00b2bd3f:;
    W16((uint32_t)(c->edi), (uint16_t)(((uint16_t)c->edx))); /* mov word ptr [edi], dx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_00b2bd48:;
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [edi], dl */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00b2bcd1(CPU *c) { /* PTR_00b2bcd1 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u)); /* test ecx, 3 */
    if (c->zf) goto L_00b2bcf6; /* je 0xb2bcf6 */
L_00b2bcdd:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov dl, byte ptr [ecx] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00b2bd48; /* je 0xb2bd48 */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [edi], dl */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u)); /* test ecx, 3 */
    if (!c->zf) goto L_00b2bcdd; /* jne 0xb2bcdd */
    goto L_00b2bcf6; /* jmp 0xb2bcf6 */
L_00b2bcf1:;
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
L_00b2bcf6:;
    c->edx = (uint32_t)((uint32_t)0x7efefeffu); /* mov edx, 0x7efefeff */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ (uint32_t)0xffffffffu))); /* xor eax, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ c->edx))); /* xor eax, edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u)); /* test eax, 0x81010100 */
    if (c->zf) goto L_00b2bcf1; /* je 0xb2bcf1 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00b2bd48; /* je 0xb2bd48 */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->edx >> 8)) & ((uint8_t)(c->edx >> 8)))); /* test dh, dh */
    if (c->zf) goto L_00b2bd3f; /* je 0xb2bd3f */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0xff0000u)); /* test edx, 0xff0000 */
    if (c->zf) goto L_00b2bd32; /* je 0xb2bd32 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0xff000000u)); /* test edx, 0xff000000 */
    if (c->zf) goto L_00b2bd2a; /* je 0xb2bd2a */
    goto L_00b2bcf1; /* jmp 0xb2bcf1 */
L_00b2bd2a:;
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_00b2bd32:;
    W16((uint32_t)(c->edi), (uint16_t)(((uint16_t)c->edx))); /* mov word ptr [edi], dx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [edi + 2], 0 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_00b2bd3f:;
    W16((uint32_t)(c->edi), (uint16_t)(((uint16_t)c->edx))); /* mov word ptr [edi], dx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_00b2bd48:;
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [edi], dl */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00b2bd50(CPU *c) { /* _memset */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_00b2bda3; /* je 0xb2bda3 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x8u))); /* mov al, byte ptr [esp + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    (void)sub32(c, c->edx, (uint32_t)0x4u); /* cmp edx, 4 */
    if (c->cf) goto L_00b2bd97; /* jb 0xb2bd97 */
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u))); /* and ecx, 3 */
    if (c->zf) goto L_00b2bd79; /* je 0xb2bd79 */
    c->edx = (uint32_t)(sub32(c, c->edx, c->ecx)); /* sub edx, ecx */
L_00b2bd73:;
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (!c->zf) goto L_00b2bd73; /* jne 0xb2bd73 */
L_00b2bd79:;
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(shl32(c, c->eax, 16)); /* shl eax, 0x10 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u))); /* and edx, 3 */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (c->zf) goto L_00b2bd97; /* je 0xb2bd97 */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_00b2bd9d; /* je 0xb2bd9d */
L_00b2bd97:;
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->edx = (uint32_t)(dec32(c, c->edx)); /* dec edx */
    if (!c->zf) goto L_00b2bd97; /* jne 0xb2bd97 */
L_00b2bd9d:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_00b2bda3:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->esp += 4; return; /* ret  */
}

void f_00b2bda8(CPU *c) { /* PTR_00b2bda8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    PUSH32(c, 0x00b2bdafu); f_00b25c98(c); /* call 0xb25c98 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00b2bdb1(CPU *c) { /* FUN_1000bdb1 */
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
    if (c->zf) goto L_00b2bdf6; /* je 0xb2bdf6 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00b2bdf2; /* je 0xb2bdf2 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00b2bdee; /* je 0xb2bdee */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00b2bdea; /* je 0xb2bdea */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00b2bdf6; /* je 0xb2bdf6 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00b2bde2; /* je 0xb2bde2 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (!c->zf) goto L_00b2be4c; /* jne 0xb2be4c */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    goto L_00b2bdf8; /* jmp 0xb2bdf8 */
L_00b2bde2:;
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [esi], 1 */
    goto L_00b2be4c; /* jmp 0xb2be4c */
L_00b2bdea:;
    { uint32_t v_ = 0x12u; PUSH32(c, v_); } /* push 0x12 */
    goto L_00b2bdf8; /* jmp 0xb2bdf8 */
L_00b2bdee:;
    { uint32_t v_ = 0x11u; PUSH32(c, v_); } /* push 0x11 */
    goto L_00b2bdf8; /* jmp 0xb2bdf8 */
L_00b2bdf2:;
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    goto L_00b2bdf8; /* jmp 0xb2bdf8 */
L_00b2bdf6:;
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
L_00b2bdf8:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x18u)); /* lea edi, [esi + 0x18] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b2be04u); f_00b2d57f(c); /* call 0xb2d57f */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b2be4c; /* jne 0xb2be4c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)sub32(c, c->eax, (uint32_t)0x10u); /* cmp eax, 0x10 */
    if (c->zf) goto L_00b2be23; /* je 0xb2be23 */
    (void)sub32(c, c->eax, (uint32_t)0x16u); /* cmp eax, 0x16 */
    if (c->zf) goto L_00b2be23; /* je 0xb2be23 */
    (void)sub32(c, c->eax, (uint32_t)0x1du); /* cmp eax, 0x1d */
    if (c->zf) goto L_00b2be23; /* je 0xb2be23 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe0u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0xfffffffeu)))); } /* and dword ptr [ebp - 0x20], 0xfffffffe */
    goto L_00b2be35; /* jmp 0xb2be35 */
L_00b2be23:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov ecx, dword ptr [ebp - 0x20] */
    FPUSH(c, RF64((uint32_t)(c->esi + 0x10u))); /* fld qword ptr [esi + 0x10] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0xffffffe3u))); /* and ecx, 0xffffffe3 */
    WF64((uint32_t)(c->ebp + 0xffffffd0u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0x30] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0x3u))); /* or ecx, 3 */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 0x20], ecx */
L_00b2be35:;
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x8u)); /* lea ecx, [esi + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffa8u)); /* lea eax, [ebp - 0x58] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2be49u); f_00b2d2cc(c); /* call 0xb2d2cc */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00b2be4c:;
    { uint32_t v_ = 0xffffu; PUSH32(c, v_); } /* push 0xffff */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    PUSH32(c, 0x00b2be59u); f_00b2d7de(c); /* call 0xb2d7de */
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x8u); /* cmp dword ptr [esi], 8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00b2be74; /* je 0xb2be74 */
    (void)sub32(c, R32((uint32_t)(0xb32d08u)), (uint32_t)0x0u); /* cmp dword ptr [0x10012d08], 0 */
    if (!c->zf) goto L_00b2be74; /* jne 0xb2be74 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b2be6fu); f_00b2d7be(c); /* call 0xb2d7be */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00b2be7c; /* jne 0xb2be7c */
L_00b2be74:;
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    PUSH32(c, 0x00b2be7bu); f_00b2d796(c); /* call 0xb2d796 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b2be7c:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b2be81(CPU *c) { /* FUN_1000be81 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x19u; PUSH32(c, v_); } /* push 0x19 */
    PUSH32(c, 0x00b2be91u); f_00b27565(c); /* call 0xb27565 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00b2be99u); f_00b2c02e(c); /* call 0xb2c02e */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->ebx, R32((uint32_t)(0xb337e8u))); /* cmp ebx, dword ptr [0x100137e8] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 8], ebx */
    if (!c->zf) goto L_00b2beaf; /* jne 0xb2beaf */
L_00b2bea8:;
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    goto L_00b2c01f; /* jmp 0xb2c01f */
L_00b2beaf:;
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (c->zf) goto L_00b2c00d; /* je 0xb2c00d */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)((uint32_t)0xb32a28u); /* mov eax, 0x10012a28 */
L_00b2bebe:;
    (void)sub32(c, R32((uint32_t)(c->eax)), c->ebx); /* cmp dword ptr [eax], ebx */
    if (c->zf) goto L_00b2bf36; /* je 0xb2bf36 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x30u)); /* add eax, 0x30 */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    (void)sub32(c, c->eax, (uint32_t)0xb32b18u); /* cmp eax, 0x10012b18 */
    if ((c->sf != c->of)) goto L_00b2bebe; /* jl 0xb2bebe */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe8u)); /* lea eax, [ebp - 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(0xb2e0c8u)); PUSH32(c, 0x00b2bed8u); call_indirect(c, t_); } /* call dword ptr [0x1000e0c8] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (!c->zf) goto L_00b2c004; /* jne 0xb2c004 */
    { uint32_t v_ = 0x40u; PUSH32(c, v_); } /* push 0x40 */
    { uint32_t a_ = (uint32_t)(0xb33a04u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [0x10013a04], 0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edi = (uint32_t)((uint32_t)0xb33900u); /* mov edi, 0x10013900 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe8u)), c->esi); /* cmp dword ptr [ebp - 0x18], esi */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
    W8(c->edi, (uint8_t)((uint8_t)c->eax)); c->edi += (c->df ? -1 : 1); /* stosb byte ptr es:[edi], al */
    W32((uint32_t)(0xb337e8u), (uint32_t)(c->ebx)); /* mov dword ptr [0x100137e8], ebx */
    if ((c->cf || c->zf)) goto L_00b2bff1; /* jbe 0xb2bff1 */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xffffffeeu)), (uint8_t)0x0u); /* cmp byte ptr [ebp - 0x12], 0 */
    if (c->zf) goto L_00b2bfcc; /* je 0xb2bfcc */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffffefu)); /* lea ecx, [ebp - 0x11] */
L_00b2bf13:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov dl, byte ptr [ecx] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00b2bfcc; /* je 0xb2bfcc */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->ecx + 0xffffffffu))); /* movzx eax, byte ptr [ecx - 1] */
    c->edx = (uint32_t)((uint32_t)((uint8_t)c->edx)); /* movzx edx, dl */
L_00b2bf24:;
    (void)sub32(c, c->eax, c->edx); /* cmp eax, edx */
    if ((!c->cf && !c->zf)) goto L_00b2bfc0; /* ja 0xb2bfc0 */
    { uint32_t a_ = (uint32_t)(c->eax + 0xb33901u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x4u)))); } /* or byte ptr [eax + 0x10013901], 4 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_00b2bf24; /* jmp 0xb2bf24 */
L_00b2bf36:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t v_ = 0x40u; PUSH32(c, v_); } /* push 0x40 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edi = (uint32_t)((uint32_t)0xb33900u); /* mov edi, 0x10013900 */
    c->esi = (uint32_t)((uint32_t)(c->edx + c->edx * 2)); /* lea esi, [edx + edx*2] */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
    c->esi = (uint32_t)(shl32(c, c->esi, 4)); /* shl esi, 4 */
    W8(c->edi, (uint8_t)((uint8_t)c->eax)); c->edi += (c->df ? -1 : 1); /* stosb byte ptr es:[edi], al */
    c->ebx = (uint32_t)((uint32_t)(c->esi + 0xb32a38u)); /* lea ebx, [esi + 0x10012a38] */
L_00b2bf53:;
    (void)sub8(c, R8((uint32_t)(c->ebx)), (uint8_t)0x0u); /* cmp byte ptr [ebx], 0 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    if (c->zf) goto L_00b2bf86; /* je 0xb2bf86 */
L_00b2bf5a:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0x1u))); /* mov dl, byte ptr [ecx + 1] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00b2bf86; /* je 0xb2bf86 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->ecx))); /* movzx eax, byte ptr [ecx] */
    c->edi = (uint32_t)((uint32_t)((uint8_t)c->edx)); /* movzx edi, dl */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if ((!c->cf && !c->zf)) goto L_00b2bf7f; /* ja 0xb2bf7f */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov edx, dword ptr [ebp - 4] */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx + 0xb32a20u))); /* mov dl, byte ptr [edx + 0x10012a20] */
L_00b2bf74:;
    { uint32_t a_ = (uint32_t)(c->eax + 0xb33901u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | ((uint8_t)c->edx))))); } /* or byte ptr [eax + 0x10013901], dl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if ((c->cf || c->zf)) goto L_00b2bf74; /* jbe 0xb2bf74 */
L_00b2bf7f:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub8(c, R8((uint32_t)(c->ecx)), (uint8_t)0x0u); /* cmp byte ptr [ecx], 0 */
    if (!c->zf) goto L_00b2bf5a; /* jne 0xb2bf5a */
L_00b2bf86:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x8u)); /* add ebx, 8 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x4u); /* cmp dword ptr [ebp - 4], 4 */
    if (c->cf) goto L_00b2bf53; /* jb 0xb2bf53 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(0xb337fcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x100137fc], 1 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0xb337e8u), (uint32_t)(c->eax)); /* mov dword ptr [0x100137e8], eax */
    PUSH32(c, 0x00b2bfaau); f_00b2c078(c); /* call 0xb2c078 */
    c->esi = (uint32_t)((uint32_t)(c->esi + 0xb32a2cu)); /* lea esi, [esi + 0x10012a2c] */
    c->edi = (uint32_t)((uint32_t)0xb337f0u); /* mov edi, 0x100137f0 */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(0xb33a04u), (uint32_t)(c->eax)); /* mov dword ptr [0x10013a04], eax */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    goto L_00b2c012; /* jmp 0xb2c012 */
L_00b2bfc0:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub8(c, R8((uint32_t)(c->ecx + 0xffffffffu)), (uint8_t)0x0u); /* cmp byte ptr [ecx - 1], 0 */
    if (!c->zf) goto L_00b2bf13; /* jne 0xb2bf13 */
L_00b2bfcc:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00b2bfce:;
    { uint32_t a_ = (uint32_t)(c->eax + 0xb33901u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x8u)))); } /* or byte ptr [eax + 0x10013901], 8 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub32(c, c->eax, (uint32_t)0xffu); /* cmp eax, 0xff */
    if (c->cf) goto L_00b2bfce; /* jb 0xb2bfce */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b2bfe3u); f_00b2c078(c); /* call 0xb2c078 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(0xb33a04u), (uint32_t)(c->eax)); /* mov dword ptr [0x10013a04], eax */
    W32((uint32_t)(0xb337fcu), (uint32_t)(c->esi)); /* mov dword ptr [0x100137fc], esi */
    goto L_00b2bff8; /* jmp 0xb2bff8 */
L_00b2bff1:;
    { uint32_t a_ = (uint32_t)(0xb337fcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [0x100137fc], 0 */
L_00b2bff8:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edi = (uint32_t)((uint32_t)0xb337f0u); /* mov edi, 0x100137f0 */
    W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); /* stosd dword ptr es:[edi], eax */
    W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); /* stosd dword ptr es:[edi], eax */
    W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); /* stosd dword ptr es:[edi], eax */
    goto L_00b2c012; /* jmp 0xb2c012 */
L_00b2c004:;
    (void)sub32(c, R32((uint32_t)(0xb33650u)), (uint32_t)0x0u); /* cmp dword ptr [0x10013650], 0 */
    if (c->zf) goto L_00b2c01c; /* je 0xb2c01c */
L_00b2c00d:;
    PUSH32(c, 0x00b2c012u); f_00b2c0ab(c); /* call 0xb2c0ab */
L_00b2c012:;
    PUSH32(c, 0x00b2c017u); f_00b2c0d4(c); /* call 0xb2c0d4 */
    goto L_00b2bea8; /* jmp 0xb2bea8 */
L_00b2c01c:;
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi | (uint32_t)0xffffffffu))); /* or esi, 0xffffffff */
L_00b2c01f:;
    { uint32_t v_ = 0x19u; PUSH32(c, v_); } /* push 0x19 */
    PUSH32(c, 0x00b2c026u); f_00b275c6(c); /* call 0xb275c6 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b2c02e(CPU *c) { /* FUN_1000c02e */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint32_t a_ = (uint32_t)(0xb33650u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [0x10013650], 0 */
    (void)sub32(c, c->eax, (uint32_t)0xfffffffeu); /* cmp eax, -2 */
    if (!c->zf) goto L_00b2c04e; /* jne 0xb2c04e */
    W32((uint32_t)(0xb33650u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x10013650], 1 */
    { uint32_t t_ = R32((uint32_t)(0xb2e0d0u)); switch (t_) {  default: jump_indirect(c, t_, 0x00b2c048u); return; } } /* jmp dword ptr [0x1000e0d0] */
L_00b2c04e:;
    (void)sub32(c, c->eax, (uint32_t)0xfffffffdu); /* cmp eax, -3 */
    if (!c->zf) goto L_00b2c063; /* jne 0xb2c063 */
    W32((uint32_t)(0xb33650u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x10013650], 1 */
    { uint32_t t_ = R32((uint32_t)(0xb2e0ccu)); switch (t_) {  default: jump_indirect(c, t_, 0x00b2c05du); return; } } /* jmp dword ptr [0x1000e0cc] */
L_00b2c063:;
    (void)sub32(c, c->eax, (uint32_t)0xfffffffcu); /* cmp eax, -4 */
    if (!c->zf) goto L_00b2c077; /* jne 0xb2c077 */
    c->eax = (uint32_t)(R32((uint32_t)(0xb3368cu))); /* mov eax, dword ptr [0x1001368c] */
    W32((uint32_t)(0xb33650u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x10013650], 1 */
L_00b2c077:;
    c->esp += 4; return; /* ret  */
}

void f_00b2c078(CPU *c) { /* FUN_1000c078 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3a4u)); /* sub eax, 0x3a4 */
    if (c->zf) goto L_00b2c0a5; /* je 0xb2c0a5 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x4u)); /* sub eax, 4 */
    if (c->zf) goto L_00b2c09f; /* je 0xb2c09f */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0xdu)); /* sub eax, 0xd */
    if (c->zf) goto L_00b2c099; /* je 0xb2c099 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00b2c093; /* je 0xb2c093 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_00b2c093:;
    c->eax = (uint32_t)((uint32_t)0x404u); /* mov eax, 0x404 */
    c->esp += 4; return; /* ret  */
L_00b2c099:;
    c->eax = (uint32_t)((uint32_t)0x412u); /* mov eax, 0x412 */
    c->esp += 4; return; /* ret  */
L_00b2c09f:;
    c->eax = (uint32_t)((uint32_t)0x804u); /* mov eax, 0x804 */
    c->esp += 4; return; /* ret  */
L_00b2c0a5:;
    c->eax = (uint32_t)((uint32_t)0x411u); /* mov eax, 0x411 */
    c->esp += 4; return; /* ret  */
}

void f_00b2c0ab(CPU *c) { /* FUN_1000c0ab */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x40u; PUSH32(c, v_); } /* push 0x40 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edi = (uint32_t)((uint32_t)0xb33900u); /* mov edi, 0x10013900 */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
    W8(c->edi, (uint8_t)((uint8_t)c->eax)); c->edi += (c->df ? -1 : 1); /* stosb byte ptr es:[edi], al */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edi = (uint32_t)((uint32_t)0xb337f0u); /* mov edi, 0x100137f0 */
    W32((uint32_t)(0xb337e8u), (uint32_t)(c->eax)); /* mov dword ptr [0x100137e8], eax */
    W32((uint32_t)(0xb337fcu), (uint32_t)(c->eax)); /* mov dword ptr [0x100137fc], eax */
    W32((uint32_t)(0xb33a04u), (uint32_t)(c->eax)); /* mov dword ptr [0x10013a04], eax */
    W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); /* stosd dword ptr es:[edi], eax */
    W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); /* stosd dword ptr es:[edi], eax */
    W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); /* stosd dword ptr es:[edi], eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00b2c0d4(CPU *c) { /* FUN_1000c0d4 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x514u)); /* sub esp, 0x514 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea eax, [ebp - 0x14] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(0xb337e8u)); PUSH32(c, v_); } /* push dword ptr [0x100137e8] */
    { uint32_t t_ = R32((uint32_t)(0xb2e0c8u)); PUSH32(c, 0x00b2c0eeu); call_indirect(c, t_); } /* call dword ptr [0x1000e0c8] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_00b2c20d; /* jne 0xb2c20d */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)((uint32_t)0x100u); /* mov esi, 0x100 */
L_00b2c0fe:;
    W8((uint32_t)(c->ebp + c->eax + 0xfffffeecu), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp + eax - 0x114], al */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00b2c0fe; /* jb 0xb2c0fe */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffff2u))); /* mov al, byte ptr [ebp - 0xe] */
    W8((uint32_t)(c->ebp + 0xfffffeecu), (uint8_t)((uint8_t)0x20u)); /* mov byte ptr [ebp - 0x114], 0x20 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00b2c14f; /* je 0xb2c14f */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edx = (uint32_t)((uint32_t)(c->ebp + 0xfffffff3u)); /* lea edx, [ebp - 0xd] */
L_00b2c11d:;
    c->ecx = (uint32_t)((uint32_t)R8((uint32_t)(c->edx))); /* movzx ecx, byte ptr [edx] */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->eax)); /* movzx eax, al */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if ((!c->cf && !c->zf)) goto L_00b2c144; /* ja 0xb2c144 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    c->edi = (uint32_t)((uint32_t)(c->ebp + c->eax + 0xfffffeecu)); /* lea edi, [ebp + eax - 0x114] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->eax = (uint32_t)((uint32_t)0x20202020u); /* mov eax, 0x20202020 */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u))); /* and ecx, 3 */
    while (c->ecx) { W8(c->edi, (uint8_t)((uint8_t)c->eax)); c->edi += (c->df ? -1 : 1); c->ecx--; } /* rep stosb byte ptr es:[edi], al */
L_00b2c144:;
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx + 0xffffffffu))); /* mov al, byte ptr [edx - 1] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00b2c11d; /* jne 0xb2c11d */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
L_00b2c14f:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffaecu)); /* lea eax, [ebp - 0x514] */
    { uint32_t v_ = R32((uint32_t)(0xb33a04u)); PUSH32(c, v_); } /* push dword ptr [0x10013a04] */
    { uint32_t v_ = R32((uint32_t)(0xb337e8u)); PUSH32(c, v_); } /* push dword ptr [0x100137e8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffeecu)); /* lea eax, [ebp - 0x114] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x00b2c173u); f_00b2b6e2(c); /* call 0xb2b6e2 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffdecu)); /* lea eax, [ebp - 0x214] */
    { uint32_t v_ = R32((uint32_t)(0xb337e8u)); PUSH32(c, v_); } /* push dword ptr [0x100137e8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffeecu)); /* lea eax, [ebp - 0x114] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(0xb33a04u)); PUSH32(c, v_); } /* push dword ptr [0x10013a04] */
    PUSH32(c, 0x00b2c197u); f_00b2cdea(c); /* call 0xb2cdea */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffcecu)); /* lea eax, [ebp - 0x314] */
    { uint32_t v_ = R32((uint32_t)(0xb337e8u)); PUSH32(c, v_); } /* push dword ptr [0x100137e8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffeecu)); /* lea eax, [ebp - 0x114] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x200u; PUSH32(c, v_); } /* push 0x200 */
    { uint32_t v_ = R32((uint32_t)(0xb33a04u)); PUSH32(c, v_); } /* push dword ptr [0x10013a04] */
    PUSH32(c, 0x00b2c1bfu); f_00b2cdea(c); /* call 0xb2cdea */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x5cu)); /* add esp, 0x5c */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffaecu)); /* lea ecx, [ebp - 0x514] */
L_00b2c1ca:;
    c->edx = (c->edx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ecx))); /* mov dx, word ptr [ecx] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & (uint8_t)0x1u)); /* test dl, 1 */
    if (c->zf) goto L_00b2c1e8; /* je 0xb2c1e8 */
    { uint32_t a_ = (uint32_t)(c->eax + 0xb33901u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x10u)))); } /* or byte ptr [eax + 0x10013901], 0x10 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + c->eax + 0xfffffdecu))); /* mov dl, byte ptr [ebp + eax - 0x214] */
L_00b2c1e0:;
    W8((uint32_t)(c->eax + 0xb33800u), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [eax + 0x10013800], dl */
    goto L_00b2c204; /* jmp 0xb2c204 */
L_00b2c1e8:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & (uint8_t)0x2u)); /* test dl, 2 */
    if (c->zf) goto L_00b2c1fd; /* je 0xb2c1fd */
    { uint32_t a_ = (uint32_t)(c->eax + 0xb33901u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x20u)))); } /* or byte ptr [eax + 0x10013901], 0x20 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + c->eax + 0xfffffcecu))); /* mov dl, byte ptr [ebp + eax - 0x314] */
    goto L_00b2c1e0; /* jmp 0xb2c1e0 */
L_00b2c1fd:;
    { uint32_t a_ = (uint32_t)(c->eax + 0xb33800u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax + 0x10013800], 0 */
L_00b2c204:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00b2c1ca; /* jb 0xb2c1ca */
    goto L_00b2c256; /* jmp 0xb2c256 */
L_00b2c20d:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)((uint32_t)0x100u); /* mov esi, 0x100 */
L_00b2c214:;
    (void)sub32(c, c->eax, (uint32_t)0x41u); /* cmp eax, 0x41 */
    if (c->cf) goto L_00b2c232; /* jb 0xb2c232 */
    (void)sub32(c, c->eax, (uint32_t)0x5au); /* cmp eax, 0x5a */
    if ((!c->cf && !c->zf)) goto L_00b2c232; /* ja 0xb2c232 */
    { uint32_t a_ = (uint32_t)(c->eax + 0xb33901u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x10u)))); } /* or byte ptr [eax + 0x10013901], 0x10 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(((uint8_t)c->eax)); /* mov cl, al */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(add8(c, ((uint8_t)c->ecx), (uint8_t)0x20u)); /* add cl, 0x20 */
L_00b2c22a:;
    W8((uint32_t)(c->eax + 0xb33800u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax + 0x10013800], cl */
    goto L_00b2c251; /* jmp 0xb2c251 */
L_00b2c232:;
    (void)sub32(c, c->eax, (uint32_t)0x61u); /* cmp eax, 0x61 */
    if (c->cf) goto L_00b2c24a; /* jb 0xb2c24a */
    (void)sub32(c, c->eax, (uint32_t)0x7au); /* cmp eax, 0x7a */
    if ((!c->cf && !c->zf)) goto L_00b2c24a; /* ja 0xb2c24a */
    { uint32_t a_ = (uint32_t)(c->eax + 0xb33901u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x20u)))); } /* or byte ptr [eax + 0x10013901], 0x20 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(((uint8_t)c->eax)); /* mov cl, al */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(sub8(c, ((uint8_t)c->ecx), (uint8_t)0x20u)); /* sub cl, 0x20 */
    goto L_00b2c22a; /* jmp 0xb2c22a */
L_00b2c24a:;
    { uint32_t a_ = (uint32_t)(c->eax + 0xb33800u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax + 0x10013800], 0 */
L_00b2c251:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00b2c214; /* jb 0xb2c214 */
L_00b2c256:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b2c259(CPU *c) { /* FUN_1000c259 */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(0xb33b48u)), (uint32_t)0x0u); /* cmp dword ptr [0x10013b48], 0 */
    if (!c->zf) goto L_00b2c274; /* jne 0xb2c274 */
    { uint32_t v_ = 0xfffffffdu; PUSH32(c, v_); } /* push -3 */
    PUSH32(c, 0x00b2c269u); f_00b2be81(c); /* call 0xb2be81 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(0xb33b48u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x10013b48], 1 */
L_00b2c274:;
    c->esp += 4; return; /* ret  */
}

void f_00b2c275(CPU *c) { /* FUN_1000c275 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    PUSH32(c, 0x00b2c288u); f_00b2c28c(c); /* call 0xb2c28c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_00b2c28c(CPU *c) { /* FUN_1000c28c */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 8], 0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->esi = (uint32_t)((uint32_t)(c->edi + 0x1u)); /* lea esi, [edi + 1] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 4], esi */
L_00b2c2a4:;
    (void)sub32(c, R32((uint32_t)(0xb3060cu)), (uint32_t)0x1u); /* cmp dword ptr [0x1001060c], 1 */
    if ((c->zf || c->sf != c->of)) goto L_00b2c2bc; /* jle 0xb2c2bc */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2c2b8u); f_00b26edb(c); /* call 0xb26edb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00b2c2cb; /* jmp 0xb2c2cb */
L_00b2c2bc:;
    c->ecx = (uint32_t)(R32((uint32_t)(0xb30400u))); /* mov ecx, dword ptr [0x10010400] */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x8u))); /* and eax, 8 */
L_00b2c2cb:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b2c2d4; /* je 0xb2c2d4 */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov bl, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    goto L_00b2c2a4; /* jmp 0xb2c2a4 */
L_00b2c2d4:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x2du); /* cmp bl, 0x2d */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 4], esi */
    if (!c->zf) goto L_00b2c2e2; /* jne 0xb2c2e2 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x14u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x2u)))); } /* or dword ptr [ebp + 0x14], 2 */
    goto L_00b2c2e7; /* jmp 0xb2c2e7 */
L_00b2c2e2:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x2bu); /* cmp bl, 0x2b */
    if (!c->zf) goto L_00b2c2ed; /* jne 0xb2c2ed */
L_00b2c2e7:;
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov bl, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 4], esi */
L_00b2c2ed:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf != c->of)) goto L_00b2c481; /* jl 0xb2c481 */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_00b2c481; /* je 0xb2c481 */
    (void)sub32(c, c->eax, (uint32_t)0x24u); /* cmp eax, 0x24 */
    if ((!c->zf && c->sf == c->of)) goto L_00b2c481; /* jg 0xb2c481 */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00b2c335; /* jne 0xb2c335 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x30u); /* cmp bl, 0x30 */
    if (c->zf) goto L_00b2c31f; /* je 0xb2c31f */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)((uint32_t)0xau)); /* mov dword ptr [ebp + 0x10], 0xa */
    goto L_00b2c351; /* jmp 0xb2c351 */
L_00b2c31f:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x78u); /* cmp al, 0x78 */
    if (c->zf) goto L_00b2c332; /* je 0xb2c332 */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x58u); /* cmp al, 0x58 */
    if (c->zf) goto L_00b2c332; /* je 0xb2c332 */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)((uint32_t)0x8u)); /* mov dword ptr [ebp + 0x10], 8 */
    goto L_00b2c351; /* jmp 0xb2c351 */
L_00b2c332:;
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp + 0x10], ecx */
L_00b2c335:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), c->ecx); /* cmp dword ptr [ebp + 0x10], ecx */
    if (!c->zf) goto L_00b2c351; /* jne 0xb2c351 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x30u); /* cmp bl, 0x30 */
    if (!c->zf) goto L_00b2c351; /* jne 0xb2c351 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x78u); /* cmp al, 0x78 */
    if (c->zf) goto L_00b2c349; /* je 0xb2c349 */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x58u); /* cmp al, 0x58 */
    if (!c->zf) goto L_00b2c351; /* jne 0xb2c351 */
L_00b2c349:;
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov bl, byte ptr [esi + 1] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 4], esi */
L_00b2c351:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    { uint32_t d_ = R32((uint32_t)(c->ebp + 0x10u)); uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x00b2c356u, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div dword ptr [ebp + 0x10] */
    c->edi = (uint32_t)((uint32_t)0x103u); /* mov edi, 0x103 */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
L_00b2c361:;
    (void)sub32(c, R32((uint32_t)(0xb3060cu)), (uint32_t)0x1u); /* cmp dword ptr [0x1001060c], 1 */
    c->esi = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx esi, bl */
    if ((c->zf || c->sf != c->of)) goto L_00b2c379; /* jle 0xb2c379 */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b2c375u); f_00b26edb(c); /* call 0xb26edb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00b2c384; /* jmp 0xb2c384 */
L_00b2c379:;
    c->eax = (uint32_t)(R32((uint32_t)(0xb30400u))); /* mov eax, dword ptr [0x10010400] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + c->esi * 2))); /* mov al, byte ptr [eax + esi*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4u))); /* and eax, 4 */
L_00b2c384:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b2c390; /* je 0xb2c390 */
    c->ecx = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx ecx, bl */
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x30u)); /* sub ecx, 0x30 */
    goto L_00b2c3c2; /* jmp 0xb2c3c2 */
L_00b2c390:;
    (void)sub32(c, R32((uint32_t)(0xb3060cu)), (uint32_t)0x1u); /* cmp dword ptr [0x1001060c], 1 */
    if ((c->zf || c->sf != c->of)) goto L_00b2c3a4; /* jle 0xb2c3a4 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00b2c3a0u); f_00b26edb(c); /* call 0xb26edb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00b2c3af; /* jmp 0xb2c3af */
L_00b2c3a4:;
    c->eax = (uint32_t)(R32((uint32_t)(0xb30400u))); /* mov eax, dword ptr [0x10010400] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->eax + c->esi * 2))); /* mov ax, word ptr [eax + esi*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & c->edi))); /* and eax, edi */
L_00b2c3af:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b2c3fd; /* je 0xb2c3fd */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx eax, bl */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2c3bcu); f_00b2d860(c); /* call 0xb2d860 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x37u)); /* sub ecx, 0x37 */
L_00b2c3c2:;
    (void)sub32(c, c->ecx, R32((uint32_t)(c->ebp + 0x10u))); /* cmp ecx, dword ptr [ebp + 0x10] */
    if (!c->cf) goto L_00b2c3fd; /* jae 0xb2c3fd */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov esi, dword ptr [ebp - 8] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x14u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x8u)))); } /* or dword ptr [ebp + 0x14], 8 */
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0xfffffff4u))); /* cmp esi, dword ptr [ebp - 0xc] */
    if (c->cf) goto L_00b2c3e7; /* jb 0xb2c3e7 */
    if (!c->zf) goto L_00b2c3e1; /* jne 0xb2c3e1 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    { uint32_t d_ = R32((uint32_t)(c->ebp + 0x10u)); uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x00b2c3dau, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div dword ptr [ebp + 0x10] */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if ((c->cf || c->zf)) goto L_00b2c3e7; /* jbe 0xb2c3e7 */
L_00b2c3e1:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0x14u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x4u)))); } /* or dword ptr [ebp + 0x14], 4 */
    goto L_00b2c3f0; /* jmp 0xb2c3f0 */
L_00b2c3e7:;
    { int64_t r_ = (int64_t)(int32_t)c->esi * (int32_t)R32((uint32_t)(c->ebp + 0x10u)); c->esi = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul esi, dword ptr [ebp + 0x10] */
    c->esi = (uint32_t)(add32(c, c->esi, c->ecx)); /* add esi, ecx */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 8], esi */
L_00b2c3f0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov bl, byte ptr [eax] */
    goto L_00b2c361; /* jmp 0xb2c361 */
L_00b2c3fd:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 4] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ebx, dword ptr [ebp + 0xc] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x8u)); /* test al, 8 */
    if (!c->zf) goto L_00b2c41a; /* jne 0xb2c41a */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (c->zf) goto L_00b2c414; /* je 0xb2c414 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
L_00b2c414:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 8], 0 */
    goto L_00b2c465; /* jmp 0xb2c465 */
L_00b2c41a:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x4u)); /* test al, 4 */
    c->esi = (uint32_t)((uint32_t)0x7fffffffu); /* mov esi, 0x7fffffff */
    if (!c->zf) goto L_00b2c43e; /* jne 0xb2c43e */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    if (!c->zf) goto L_00b2c465; /* jne 0xb2c465 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x2u))); /* and eax, 2 */
    if (c->zf) goto L_00b2c435; /* je 0xb2c435 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff8u)), (uint32_t)0x80000000u); /* cmp dword ptr [ebp - 8], 0x80000000 */
    if ((!c->cf && !c->zf)) goto L_00b2c43e; /* ja 0xb2c43e */
L_00b2c435:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b2c465; /* jne 0xb2c465 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff8u)), c->esi); /* cmp dword ptr [ebp - 8], esi */
    if ((c->cf || c->zf)) goto L_00b2c465; /* jbe 0xb2c465 */
L_00b2c43e:;
    PUSH32(c, 0x00b2c443u); f_00b2d857(c); /* call 0xb2d857 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0x14u)) & (uint8_t)0x1u)); /* test byte ptr [ebp + 0x14], 1 */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x22u)); /* mov dword ptr [eax], 0x22 */
    if (c->zf) goto L_00b2c455; /* je 0xb2c455 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 8], 0xffffffff */
    goto L_00b2c465; /* jmp 0xb2c465 */
L_00b2c455:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x2u))); /* and al, 2 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(neg8(c, ((uint8_t)c->eax))); /* neg al */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(add32(c, c->eax, c->esi)); /* add eax, esi */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
L_00b2c465:;
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (c->zf) goto L_00b2c46e; /* je 0xb2c46e */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
L_00b2c46e:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0x14u)) & (uint8_t)0x2u)); /* test byte ptr [ebp + 0x14], 2 */
    if (c->zf) goto L_00b2c47c; /* je 0xb2c47c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
L_00b2c47c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    goto L_00b2c48c; /* jmp 0xb2c48c */
L_00b2c481:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b2c48a; /* je 0xb2c48a */
    W32((uint32_t)(c->eax), (uint32_t)(c->edi)); /* mov dword ptr [eax], edi */
L_00b2c48a:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00b2c48c:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b2c4a0(CPU *c) { /* PTR_00b2c4a0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xffffffffu)); /* lea eax, [edx - 1] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00b2c4b0(CPU *c) { /* _strchr */
    PREEMPT_POLL(c);
    goto L_00b2c4b0;
L_00b2c4a0:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xffffffffu)); /* lea eax, [edx - 1] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_00b2c4b0:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x8u))); /* mov al, byte ptr [esp + 8] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u)); /* test edx, 3 */
    if (c->zf) goto L_00b2c4db; /* je 0xb2c4db */
L_00b2c4c8:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov cl, byte ptr [edx] */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    (void)sub8(c, ((uint8_t)c->ecx), ((uint8_t)c->ebx)); /* cmp cl, bl */
    if (c->zf) goto L_00b2c4a0; /* je 0xb2c4a0 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_00b2c524; /* je 0xb2c524 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u)); /* test edx, 3 */
    if (!c->zf) goto L_00b2c4c8; /* jne 0xb2c4c8 */
L_00b2c4db:;
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | c->eax))); /* or ebx, eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->ebx = (uint32_t)(shl32(c, c->ebx, 16)); /* shl ebx, 0x10 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | c->eax))); /* or ebx, eax */
L_00b2c4e6:;
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
    if (!c->zf) goto L_00b2c528; /* jne 0xb2c528 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u))); /* and eax, 0x81010100 */
    if (c->zf) goto L_00b2c4e6; /* je 0xb2c4e6 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1010100u))); /* and eax, 0x1010100 */
    if (!c->zf) goto L_00b2c522; /* jne 0xb2c522 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0x80000000u))); /* and esi, 0x80000000 */
    if (!c->zf) goto L_00b2c4e6; /* jne 0xb2c4e6 */
L_00b2c522:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_00b2c524:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_00b2c528:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0xfffffffcu))); /* mov eax, dword ptr [edx - 4] */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_00b2c565; /* je 0xb2c565 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00b2c522; /* je 0xb2c522 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->ebx)); /* cmp ah, bl */
    if (c->zf) goto L_00b2c55e; /* je 0xb2c55e */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_00b2c522; /* je 0xb2c522 */
    c->eax = (uint32_t)(shr32(c, c->eax, 16)); /* shr eax, 0x10 */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_00b2c557; /* je 0xb2c557 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00b2c522; /* je 0xb2c522 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->ebx)); /* cmp ah, bl */
    if (c->zf) goto L_00b2c550; /* je 0xb2c550 */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_00b2c522; /* je 0xb2c522 */
    goto L_00b2c4e6; /* jmp 0xb2c4e6 */
L_00b2c550:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xffffffffu)); /* lea eax, [edx - 1] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_00b2c557:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xfffffffeu)); /* lea eax, [edx - 2] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_00b2c55e:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xfffffffdu)); /* lea eax, [edx - 3] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_00b2c565:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xfffffffcu)); /* lea eax, [edx - 4] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00b2c4b6(CPU *c) { /* PTR_00b2c4b6 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u)); /* test edx, 3 */
    if (c->zf) goto L_00b2c4db; /* je 0xb2c4db */
L_00b2c4c8:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov cl, byte ptr [edx] */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    (void)sub8(c, ((uint8_t)c->ecx), ((uint8_t)c->ebx)); /* cmp cl, bl */
    if (c->zf) { f_00b2c4a0(c); return; } /* je 0xb2c4a0 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_00b2c524; /* je 0xb2c524 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u)); /* test edx, 3 */
    if (!c->zf) goto L_00b2c4c8; /* jne 0xb2c4c8 */
L_00b2c4db:;
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | c->eax))); /* or ebx, eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->ebx = (uint32_t)(shl32(c, c->ebx, 16)); /* shl ebx, 0x10 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | c->eax))); /* or ebx, eax */
L_00b2c4e6:;
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
    if (!c->zf) goto L_00b2c528; /* jne 0xb2c528 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u))); /* and eax, 0x81010100 */
    if (c->zf) goto L_00b2c4e6; /* je 0xb2c4e6 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1010100u))); /* and eax, 0x1010100 */
    if (!c->zf) goto L_00b2c522; /* jne 0xb2c522 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0x80000000u))); /* and esi, 0x80000000 */
    if (!c->zf) goto L_00b2c4e6; /* jne 0xb2c4e6 */
L_00b2c522:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_00b2c524:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_00b2c528:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0xfffffffcu))); /* mov eax, dword ptr [edx - 4] */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_00b2c565; /* je 0xb2c565 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00b2c522; /* je 0xb2c522 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->ebx)); /* cmp ah, bl */
    if (c->zf) goto L_00b2c55e; /* je 0xb2c55e */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_00b2c522; /* je 0xb2c522 */
    c->eax = (uint32_t)(shr32(c, c->eax, 16)); /* shr eax, 0x10 */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_00b2c557; /* je 0xb2c557 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00b2c522; /* je 0xb2c522 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->ebx)); /* cmp ah, bl */
    if (c->zf) goto L_00b2c550; /* je 0xb2c550 */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_00b2c522; /* je 0xb2c522 */
    goto L_00b2c4e6; /* jmp 0xb2c4e6 */
L_00b2c550:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xffffffffu)); /* lea eax, [edx - 1] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_00b2c557:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xfffffffeu)); /* lea eax, [edx - 2] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_00b2c55e:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xfffffffdu)); /* lea eax, [edx - 3] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_00b2c565:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xfffffffcu)); /* lea eax, [edx - 4] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00b2c570(CPU *c) { /* _strstr */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov dl, byte ptr [ecx] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edi, dword ptr [esp + 0x10] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00b2c5ea; /* je 0xb2c5ea */
    c->edx = (c->edx & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->ecx + 0x1u))) << 8); /* mov dh, byte ptr [ecx + 1] */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->edx >> 8)) & ((uint8_t)(c->edx >> 8)))); /* test dh, dh */
    if (c->zf) goto L_00b2c5d7; /* je 0xb2c5d7 */
L_00b2c588:;
    c->esi = (uint32_t)(c->edi); /* mov esi, edi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ecx, dword ptr [esp + 0x14] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov al, byte ptr [edi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->edx)); /* cmp al, dl */
    if (c->zf) goto L_00b2c5aa; /* je 0xb2c5aa */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00b2c5a4; /* je 0xb2c5a4 */
L_00b2c599:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_00b2c59c:;
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->edx)); /* cmp al, dl */
    if (c->zf) goto L_00b2c5aa; /* je 0xb2c5aa */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00b2c599; /* jne 0xb2c599 */
L_00b2c5a4:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_00b2c5aa:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)(c->edx >> 8))); /* cmp al, dh */
    if (!c->zf) goto L_00b2c59c; /* jne 0xb2c59c */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0xffffffffu)); /* lea edi, [esi - 1] */
L_00b2c5b4:;
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->ecx + 0x2u))) << 8); /* mov ah, byte ptr [ecx + 2] */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_00b2c5e3; /* je 0xb2c5e3 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x2u)); /* add esi, 2 */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)(c->eax >> 8))); /* cmp al, ah */
    if (!c->zf) goto L_00b2c588; /* jne 0xb2c588 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0x3u))); /* mov al, byte ptr [ecx + 3] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00b2c5e3; /* je 0xb2c5e3 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->esi + 0xffffffffu))) << 8); /* mov ah, byte ptr [esi - 1] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x2u)); /* add ecx, 2 */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)(c->eax >> 8))); /* cmp al, ah */
    if (c->zf) goto L_00b2c5b4; /* je 0xb2c5b4 */
    goto L_00b2c588; /* jmp 0xb2c588 */
L_00b2c5d7:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(((uint8_t)c->edx)); /* mov al, dl */
    { f_00b2c4b6(c); return; } /* jmp 0xb2c4b6 */
L_00b2c5e3:;
    c->eax = (uint32_t)((uint32_t)(c->edi + 0xffffffffu)); /* lea eax, [edi - 1] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_00b2c5ea:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00b2c5f0(CPU *c) { /* _strncmp */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    if (c->ecx == 0) goto L_00b2c621; /* jecxz 0xb2c621 */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    c->esi = (uint32_t)(c->edi); /* mov esi, edi */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    while (c->ecx) { (void)sub8(c, ((uint8_t)c->eax), R8(c->edi)); c->edi += (c->df ? -1 : 1); c->ecx--; if (c->zf) break; } /* repne scasb al, byte ptr es:[edi] */
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->ebx)); /* add ecx, ebx */
    c->edi = (uint32_t)(c->esi); /* mov edi, esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    while (c->ecx) { (void)sub8(c, R8(c->esi), R8(c->edi)); c->esi += (c->df ? -1 : 1); c->edi += (c->df ? -1 : 1); c->ecx--; if (!c->zf) break; } /* repe cmpsb byte ptr [esi], byte ptr es:[edi] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0xffffffffu))); /* mov al, byte ptr [esi - 1] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->edi + 0xffffffffu))); /* cmp al, byte ptr [edi - 1] */
    if ((!c->cf && !c->zf)) goto L_00b2c61f; /* ja 0xb2c61f */
    if (c->zf) goto L_00b2c621; /* je 0xb2c621 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
L_00b2c61f:;
    c->ecx = (uint32_t)((uint32_t)~c->ecx); /* not ecx */
L_00b2c621:;
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b2c630(CPU *c) { /* FUN_1000c630 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    (void)sub32(c, c->eax, (uint32_t)0x1000u); /* cmp eax, 0x1000 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x8u)); /* lea ecx, [esp + 8] */
    if (c->cf) goto L_00b2c650; /* jb 0xb2c650 */
L_00b2c63c:;
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x1000u)); /* sub ecx, 0x1000 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x1000u)); /* sub eax, 0x1000 */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->ecx)) & c->eax)); /* test dword ptr [ecx], eax */
    (void)sub32(c, c->eax, (uint32_t)0x1000u); /* cmp eax, 0x1000 */
    if (!c->cf) goto L_00b2c63c; /* jae 0xb2c63c */
L_00b2c650:;
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    c->eax = (uint32_t)(c->esp); /* mov eax, esp */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->ecx)) & c->eax)); /* test dword ptr [ecx], eax */
    c->esp = (uint32_t)(c->ecx); /* mov esp, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov eax, dword ptr [eax + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->esp += 4; return; /* ret  */
}

void f_00b2c65f(CPU *c) { /* FUN_1000c65f */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, R32((uint32_t)(0xb33654u)), c->ebx); /* cmp dword ptr [0x10013654], ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00b2c6ae; /* jne 0xb2c6ae */
    { uint32_t v_ = 0xb2e77cu; PUSH32(c, v_); } /* push 0x1000e77c */
    { uint32_t t_ = R32((uint32_t)(0xb2e0d4u)); PUSH32(c, 0x00b2c677u); call_indirect(c, t_); } /* call dword ptr [0x1000e0d4] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    if (c->zf) goto L_00b2c6e4; /* je 0xb2c6e4 */
    c->esi = (uint32_t)(R32((uint32_t)(0xb2e044u))); /* mov esi, dword ptr [0x1000e044] */
    { uint32_t v_ = 0xb2e770u; PUSH32(c, v_); } /* push 0x1000e770 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = c->esi; PUSH32(c, 0x00b2c68bu); call_indirect(c, t_); } /* call esi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(0xb33654u), (uint32_t)(c->eax)); /* mov dword ptr [0x10013654], eax */
    if (c->zf) goto L_00b2c6e4; /* je 0xb2c6e4 */
    { uint32_t v_ = 0xb2e760u; PUSH32(c, v_); } /* push 0x1000e760 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = c->esi; PUSH32(c, 0x00b2c69cu); call_indirect(c, t_); } /* call esi */
    { uint32_t v_ = 0xb2e74cu; PUSH32(c, v_); } /* push 0x1000e74c */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(0xb33658u), (uint32_t)(c->eax)); /* mov dword ptr [0x10013658], eax */
    { uint32_t t_ = c->esi; PUSH32(c, 0x00b2c6a9u); call_indirect(c, t_); } /* call esi */
    W32((uint32_t)(0xb3365cu), (uint32_t)(c->eax)); /* mov dword ptr [0x1001365c], eax */
L_00b2c6ae:;
    c->eax = (uint32_t)(R32((uint32_t)(0xb33658u))); /* mov eax, dword ptr [0x10013658] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b2c6cd; /* je 0xb2c6cd */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00b2c6b9u); call_indirect(c, t_); } /* call eax */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (c->zf) goto L_00b2c6cd; /* je 0xb2c6cd */
    c->eax = (uint32_t)(R32((uint32_t)(0xb3365cu))); /* mov eax, dword ptr [0x1001365c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b2c6cd; /* je 0xb2c6cd */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00b2c6cbu); call_indirect(c, t_); } /* call eax */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
L_00b2c6cd:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x18] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(0xb33654u)); PUSH32(c, 0x00b2c6e0u); call_indirect(c, t_); } /* call dword ptr [0x10013654] */
L_00b2c6e0:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_00b2c6e4:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00b2c6e0; /* jmp 0xb2c6e0 */
}

void f_00b2c6f0(CPU *c) { /* _strncpy */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00b2c773; /* je 0xb2c773 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov esi, dword ptr [esp + 0x14] */
    (void)logic32(c, (uint32_t)(c->esi & (uint32_t)0x3u)); /* test esi, 3 */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edi, dword ptr [esp + 0x10] */
    if (!c->zf) goto L_00b2c714; /* jne 0xb2c714 */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->zf) goto L_00b2c781; /* jne 0xb2c781 */
    goto L_00b2c735; /* jmp 0xb2c735 */
L_00b2c714:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_00b2c742; /* je 0xb2c742 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00b2c74a; /* je 0xb2c74a */
    (void)logic32(c, (uint32_t)(c->esi & (uint32_t)0x3u)); /* test esi, 3 */
    if (!c->zf) goto L_00b2c714; /* jne 0xb2c714 */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->zf) goto L_00b2c781; /* jne 0xb2c781 */
L_00b2c730:;
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x3u))); /* and ebx, 3 */
    if (c->zf) goto L_00b2c742; /* je 0xb2c742 */
L_00b2c735:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00b2c76e; /* je 0xb2c76e */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->zf) goto L_00b2c735; /* jne 0xb2c735 */
L_00b2c742:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_00b2c74a:;
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x3u)); /* test edi, 3 */
    if (c->zf) goto L_00b2c764; /* je 0xb2c764 */
L_00b2c752:;
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_00b2c7e6; /* je 0xb2c7e6 */
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x3u)); /* test edi, 3 */
    if (!c->zf) goto L_00b2c752; /* jne 0xb2c752 */
L_00b2c764:;
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->zf) goto L_00b2c7d7; /* jne 0xb2c7d7 */
L_00b2c76b:;
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
L_00b2c76e:;
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->zf) goto L_00b2c76b; /* jne 0xb2c76b */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00b2c773:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_00b2c779:;
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_00b2c730; /* je 0xb2c730 */
L_00b2c781:;
    c->edx = (uint32_t)((uint32_t)0x7efefeffu); /* mov edx, 0x7efefeff */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ (uint32_t)0xffffffffu))); /* xor eax, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ c->edx))); /* xor eax, edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u)); /* test eax, 0x81010100 */
    if (c->zf) goto L_00b2c779; /* je 0xb2c779 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00b2c7cb; /* je 0xb2c7cb */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->edx >> 8)) & ((uint8_t)(c->edx >> 8)))); /* test dh, dh */
    if (c->zf) goto L_00b2c7c1; /* je 0xb2c7c1 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0xff0000u)); /* test edx, 0xff0000 */
    if (c->zf) goto L_00b2c7b7; /* je 0xb2c7b7 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0xff000000u)); /* test edx, 0xff000000 */
    if (!c->zf) goto L_00b2c779; /* jne 0xb2c779 */
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    goto L_00b2c7cf; /* jmp 0xb2c7cf */
L_00b2c7b7:;
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0xffffu))); /* and edx, 0xffff */
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    goto L_00b2c7cf; /* jmp 0xb2c7cf */
L_00b2c7c1:;
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0xffu))); /* and edx, 0xff */
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    goto L_00b2c7cf; /* jmp 0xb2c7cf */
L_00b2c7cb:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
L_00b2c7cf:;
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_00b2c7e1; /* je 0xb2c7e1 */
L_00b2c7d7:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00b2c7d9:;
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (!c->zf) goto L_00b2c7d9; /* jne 0xb2c7d9 */
L_00b2c7e1:;
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x3u))); /* and ebx, 3 */
    if (!c->zf) goto L_00b2c76b; /* jne 0xb2c76b */
L_00b2c7e6:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00b2c730(CPU *c) { /* PTR_00b2c730 */
    PREEMPT_POLL(c);
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x3u))); /* and ebx, 3 */
    if (c->zf) goto L_00b2c742; /* je 0xb2c742 */
L_00b2c735:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00b2c76e; /* je 0xb2c76e */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->zf) goto L_00b2c735; /* jne 0xb2c735 */
L_00b2c742:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_00b2c76b:;
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
L_00b2c76e:;
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->zf) goto L_00b2c76b; /* jne 0xb2c76b */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00b2c779(CPU *c) { /* PTR_00b2c779 */
    PREEMPT_POLL(c);
L_00b2c779:;
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) { f_00b2c730(c); return; } /* je 0xb2c730 */
    c->edx = (uint32_t)((uint32_t)0x7efefeffu); /* mov edx, 0x7efefeff */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ (uint32_t)0xffffffffu))); /* xor eax, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ c->edx))); /* xor eax, edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u)); /* test eax, 0x81010100 */
    if (c->zf) goto L_00b2c779; /* je 0xb2c779 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00b2c7cb; /* je 0xb2c7cb */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->edx >> 8)) & ((uint8_t)(c->edx >> 8)))); /* test dh, dh */
    if (c->zf) goto L_00b2c7c1; /* je 0xb2c7c1 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0xff0000u)); /* test edx, 0xff0000 */
    if (c->zf) goto L_00b2c7b7; /* je 0xb2c7b7 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0xff000000u)); /* test edx, 0xff000000 */
    if (!c->zf) goto L_00b2c779; /* jne 0xb2c779 */
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    goto L_00b2c7cf; /* jmp 0xb2c7cf */
L_00b2c7b7:;
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0xffffu))); /* and edx, 0xffff */
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    goto L_00b2c7cf; /* jmp 0xb2c7cf */
L_00b2c7c1:;
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0xffu))); /* and edx, 0xff */
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    goto L_00b2c7cf; /* jmp 0xb2c7cf */
L_00b2c7cb:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
L_00b2c7cf:;
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_00b2c7e1; /* je 0xb2c7e1 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00b2c7d9:;
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (!c->zf) goto L_00b2c7d9; /* jne 0xb2c7d9 */
L_00b2c7e1:;
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x3u))); /* and ebx, 3 */
    if (!c->zf) { jump_indirect(c, 0x00b2c76bu, 0x00b2c7e4u); return; } /* jne 0xb2c76b */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00b2c781(CPU *c) { /* PTR_00b2c781 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)((uint32_t)0x7efefeffu); /* mov edx, 0x7efefeff */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ (uint32_t)0xffffffffu))); /* xor eax, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ c->edx))); /* xor eax, edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u)); /* test eax, 0x81010100 */
    if (c->zf) { f_00b2c779(c); return; } /* je 0xb2c779 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00b2c7cb; /* je 0xb2c7cb */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->edx >> 8)) & ((uint8_t)(c->edx >> 8)))); /* test dh, dh */
    if (c->zf) goto L_00b2c7c1; /* je 0xb2c7c1 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0xff0000u)); /* test edx, 0xff0000 */
    if (c->zf) goto L_00b2c7b7; /* je 0xb2c7b7 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0xff000000u)); /* test edx, 0xff000000 */
    if (!c->zf) { f_00b2c779(c); return; } /* jne 0xb2c779 */
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    goto L_00b2c7cf; /* jmp 0xb2c7cf */
L_00b2c7b7:;
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0xffffu))); /* and edx, 0xffff */
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    goto L_00b2c7cf; /* jmp 0xb2c7cf */
L_00b2c7c1:;
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0xffu))); /* and edx, 0xff */
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    goto L_00b2c7cf; /* jmp 0xb2c7cf */
L_00b2c7cb:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
L_00b2c7cf:;
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_00b2c7e1; /* je 0xb2c7e1 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00b2c7d9:;
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (!c->zf) goto L_00b2c7d9; /* jne 0xb2c7d9 */
L_00b2c7e1:;
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x3u))); /* and ebx, 3 */
    if (!c->zf) { jump_indirect(c, 0x00b2c76bu, 0x00b2c7e4u); return; } /* jne 0xb2c76b */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00b2c7ee(CPU *c) { /* FUN_1000c7ee */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (c->zf) goto L_00b2c869; /* je 0xb2c869 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00b2c84c; /* je 0xb2c84c */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x4u)); /* sub eax, 4 */
    if (c->zf) goto L_00b2c84c; /* je 0xb2c84c */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3u)); /* sub eax, 3 */
    if (c->zf) goto L_00b2c84c; /* je 0xb2c84c */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x4u)); /* sub eax, 4 */
    if (c->zf) goto L_00b2c83f; /* je 0xb2c83f */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x6u)); /* sub eax, 6 */
    if (c->zf) goto L_00b2c832; /* je 0xb2c832 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00b2c825; /* je 0xb2c825 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    goto L_00b2c96b; /* jmp 0xb2c96b */
L_00b2c825:;
    c->ebx = (uint32_t)(R32((uint32_t)(0xb33668u))); /* mov ebx, dword ptr [0x10013668] */
    c->edi = (uint32_t)((uint32_t)0xb33668u); /* mov edi, 0x10013668 */
    goto L_00b2c874; /* jmp 0xb2c874 */
L_00b2c832:;
    c->ebx = (uint32_t)(R32((uint32_t)(0xb33664u))); /* mov ebx, dword ptr [0x10013664] */
    c->edi = (uint32_t)((uint32_t)0xb33664u); /* mov edi, 0x10013664 */
    goto L_00b2c874; /* jmp 0xb2c874 */
L_00b2c83f:;
    c->ebx = (uint32_t)(R32((uint32_t)(0xb3366cu))); /* mov ebx, dword ptr [0x1001366c] */
    c->edi = (uint32_t)((uint32_t)0xb3366cu); /* mov edi, 0x1001366c */
    goto L_00b2c874; /* jmp 0xb2c874 */
L_00b2c84c:;
    PUSH32(c, 0x00b2c851u); f_00b265a1(c); /* call 0xb265a1 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x50u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x50] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00b2c85eu); f_00b2c970(c); /* call 0xb2c970 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x8u)); /* add edi, 8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->edi))); /* mov ebx, dword ptr [edi] */
    goto L_00b2c886; /* jmp 0xb2c886 */
L_00b2c869:;
    c->ebx = (uint32_t)(R32((uint32_t)(0xb33660u))); /* mov ebx, dword ptr [0x10013660] */
    c->edi = (uint32_t)((uint32_t)0xb33660u); /* mov edi, 0x10013660 */
L_00b2c874:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    PUSH32(c, 0x00b2c882u); f_00b27565(c); /* call 0xb27565 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b2c886:;
    (void)sub32(c, c->ebx, (uint32_t)0x1u); /* cmp ebx, 1 */
    if (!c->zf) goto L_00b2c8a1; /* jne 0xb2c8a1 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if (c->zf) goto L_00b2c969; /* je 0xb2c969 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b2c89bu); f_00b275c6(c); /* call 0xb275c6 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00b2c969; /* jmp 0xb2c969 */
L_00b2c8a1:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub32(c, c->ebx, c->ecx); /* cmp ebx, ecx */
    if (!c->zf) goto L_00b2c8bb; /* jne 0xb2c8bb */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), c->ecx); /* cmp dword ptr [ebp - 4], ecx */
    if (c->zf) goto L_00b2c8b4; /* je 0xb2c8b4 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x00b2c8b3u); f_00b275c6(c); /* call 0xb275c6 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b2c8b4:;
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    PUSH32(c, 0x00b2c8bbu); f_00b2678c(c); /* call 0xb2678c */
L_00b2c8bb:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)sub32(c, c->eax, (uint32_t)0x8u); /* cmp eax, 8 */
    if (c->zf) goto L_00b2c8cd; /* je 0xb2c8cd */
    (void)sub32(c, c->eax, (uint32_t)0xbu); /* cmp eax, 0xb */
    if (c->zf) goto L_00b2c8cd; /* je 0xb2c8cd */
    (void)sub32(c, c->eax, (uint32_t)0x4u); /* cmp eax, 4 */
    if (!c->zf) goto L_00b2c8e8; /* jne 0xb2c8e8 */
L_00b2c8cd:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x54u))); /* mov edx, dword ptr [esi + 0x54] */
    (void)sub32(c, c->eax, (uint32_t)0x8u); /* cmp eax, 8 */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 8], edx */
    W32((uint32_t)(c->esi + 0x54u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 0x54], ecx */
    if (!c->zf) goto L_00b2c924; /* jne 0xb2c924 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x58u))); /* mov edx, dword ptr [esi + 0x58] */
    W32((uint32_t)(c->esi + 0x58u), (uint32_t)((uint32_t)0x8cu)); /* mov dword ptr [esi + 0x58], 0x8c */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0xc], edx */
L_00b2c8e8:;
    (void)sub32(c, c->eax, (uint32_t)0x8u); /* cmp eax, 8 */
    if (!c->zf) goto L_00b2c924; /* jne 0xb2c924 */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb309b8u))); /* mov ecx, dword ptr [0x100109b8] */
    c->eax = (uint32_t)(R32((uint32_t)(0xb309bcu))); /* mov eax, dword ptr [0x100109bc] */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
    if ((c->sf == c->of)) goto L_00b2c926; /* jge 0xb2c926 */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea eax, [ecx + ecx*2] */
    c->eax = (uint32_t)(shl32(c, c->eax, 2)); /* shl eax, 2 */
L_00b2c904:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov edx, dword ptr [esi + 0x50] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xcu)); /* add eax, 0xc */
    { uint32_t a_ = (uint32_t)(c->edx + c->eax + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [edx + eax - 4], 0 */
    c->edx = (uint32_t)(R32((uint32_t)(0xb309b8u))); /* mov edx, dword ptr [0x100109b8] */
    c->edi = (uint32_t)(R32((uint32_t)(0xb309bcu))); /* mov edi, dword ptr [0x100109bc] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->edi = (uint32_t)(add32(c, c->edi, c->edx)); /* add edi, edx */
    (void)sub32(c, c->ecx, c->edi); /* cmp ecx, edi */
    if ((c->sf != c->of)) goto L_00b2c904; /* jl 0xb2c904 */
    goto L_00b2c926; /* jmp 0xb2c926 */
L_00b2c924:;
    W32((uint32_t)(c->edi), (uint32_t)(c->ecx)); /* mov dword ptr [edi], ecx */
L_00b2c926:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if (c->zf) goto L_00b2c934; /* je 0xb2c934 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x00b2c933u); f_00b275c6(c); /* call 0xb275c6 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b2c934:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x8u); /* cmp dword ptr [ebp + 8], 8 */
    if (!c->zf) goto L_00b2c945; /* jne 0xb2c945 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x58u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x58] */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t t_ = c->ebx; PUSH32(c, 0x00b2c941u); call_indirect(c, t_); } /* call ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00b2c957; /* jmp 0xb2c957 */
L_00b2c945:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = c->ebx; PUSH32(c, 0x00b2c94au); call_indirect(c, t_); } /* call ebx */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0xbu); /* cmp dword ptr [ebp + 8], 0xb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00b2c957; /* je 0xb2c957 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x4u); /* cmp dword ptr [ebp + 8], 4 */
    if (!c->zf) goto L_00b2c969; /* jne 0xb2c969 */
L_00b2c957:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x8u); /* cmp dword ptr [ebp + 8], 8 */
    W32((uint32_t)(c->esi + 0x54u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x54], eax */
    if (!c->zf) goto L_00b2c969; /* jne 0xb2c969 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    W32((uint32_t)(c->esi + 0x58u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x58], eax */
L_00b2c969:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00b2c96b:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b2c970(CPU *c) { /* FUN_1000c970 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(0xb309c4u))); /* mov ecx, dword ptr [0x100109c4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    (void)sub32(c, R32((uint32_t)(c->edx + 0x4u)), c->esi); /* cmp dword ptr [edx + 4], esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    if (c->zf) goto L_00b2c999; /* je 0xb2c999 */
    c->edi = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea edi, [ecx + ecx*2] */
    c->edi = (uint32_t)((uint32_t)(c->edx + c->edi * 4)); /* lea edi, [edx + edi*4] */
L_00b2c98d:;
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xcu)); /* add eax, 0xc */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->cf) goto L_00b2c999; /* jae 0xb2c999 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x4u)), c->esi); /* cmp dword ptr [eax + 4], esi */
    if (!c->zf) goto L_00b2c98d; /* jne 0xb2c98d */
L_00b2c999:;
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea ecx, [ecx + ecx*2] */
    c->ecx = (uint32_t)((uint32_t)(c->edx + c->ecx * 4)); /* lea ecx, [edx + ecx*4] */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->cf) goto L_00b2c9a8; /* jae 0xb2c9a8 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x4u)), c->esi); /* cmp dword ptr [eax + 4], esi */
    if (c->zf) goto L_00b2c9aa; /* je 0xb2c9aa */
L_00b2c9a8:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00b2c9aa:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b2c9ad(CPU *c) { /* FUN_1000c9ad */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov esi, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (uint32_t)((uint32_t)(c->edx + c->esi)); /* lea ecx, [edx + esi] */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if (c->cf) goto L_00b2c9c3; /* jb 0xb2c9c3 */
    (void)sub32(c, c->ecx, c->esi); /* cmp ecx, esi */
    if (!c->cf) goto L_00b2c9c6; /* jae 0xb2c9c6 */
L_00b2c9c3:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00b2c9c6:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->edx), (uint32_t)(c->ecx)); /* mov dword ptr [edx], ecx */
    c->esp += 4; return; /* ret  */
}

void f_00b2c9ce(CPU *c) { /* ___add_12 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edi, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->edi)); PUSH32(c, v_); } /* push dword ptr [edi] */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    PUSH32(c, 0x00b2c9e2u); f_00b2c9ad(c); /* call 0xb2c9ad */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b2ca00; /* je 0xb2ca00 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x4u)); /* lea eax, [esi + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->eax)); PUSH32(c, v_); } /* push dword ptr [eax] */
    PUSH32(c, 0x00b2c9f6u); f_00b2c9ad(c); /* call 0xb2c9ad */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b2ca00; /* je 0xb2ca00 */
    { uint32_t a_ = (uint32_t)(c->esi + 0x8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [esi + 8] */
L_00b2ca00:;
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x4u)); /* lea eax, [esi + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->edi + 0x4u)); PUSH32(c, v_); } /* push dword ptr [edi + 4] */
    { uint32_t v_ = R32((uint32_t)(c->eax)); PUSH32(c, v_); } /* push dword ptr [eax] */
    PUSH32(c, 0x00b2ca0eu); f_00b2c9ad(c); /* call 0xb2c9ad */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b2ca18; /* je 0xb2ca18 */
    { uint32_t a_ = (uint32_t)(c->esi + 0x8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [esi + 8] */
L_00b2ca18:;
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x8u)); /* lea eax, [esi + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->edi + 0x8u)); PUSH32(c, v_); } /* push dword ptr [edi + 8] */
    { uint32_t v_ = R32((uint32_t)(c->eax)); PUSH32(c, v_); } /* push dword ptr [eax] */
    PUSH32(c, 0x00b2ca26u); f_00b2c9ad(c); /* call 0xb2c9ad */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b2ca2c(CPU *c) { /* FUN_1000ca2c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax))); /* mov esi, dword ptr [eax] */
    c->edi = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov edi, dword ptr [eax + 4] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->esi = (uint32_t)(add32(c, c->esi, c->esi)); /* add esi, esi */
    W32((uint32_t)(c->eax), (uint32_t)(c->esi)); /* mov dword ptr [eax], esi */
    c->esi = (uint32_t)((uint32_t)(c->edi + c->edi)); /* lea esi, [edi + edi] */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 31)); /* shr ecx, 0x1f */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi | c->ecx))); /* or esi, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ecx, dword ptr [eax + 8] */
    c->edx = (uint32_t)(c->edi); /* mov edx, edi */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [eax + 4], esi */
    c->edx = (uint32_t)(shr32(c, c->edx, 31)); /* shr edx, 0x1f */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 1)); /* shl ecx, 1 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->edx))); /* or ecx, edx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b2ca5a(CPU *c) { /* FUN_1000ca5a */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov edx, dword ptr [eax + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    c->esi = (uint32_t)(c->edx); /* mov esi, edx */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    c->esi = (uint32_t)(shl32(c, c->esi, 31)); /* shl esi, 0x1f */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 1)); /* shr ecx, 1 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->esi))); /* or ecx, esi */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 4], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->edi = (uint32_t)(shl32(c, c->edi, 31)); /* shl edi, 0x1f */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 1)); /* shr ecx, 1 */
    c->edx = (uint32_t)(shr32(c, c->edx, 1)); /* shr edx, 1 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->edi))); /* or ecx, edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 8], edx */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00b2ca87(CPU *c) { /* FUN_1000ca87 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x10u)); /* sub esp, 0x10 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ebx, dword ptr [ebp + 0x10] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    (void)sub32(c, c->eax, c->edx); /* cmp eax, edx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x404eu)); /* mov dword ptr [ebp - 4], 0x404e */
    W32((uint32_t)(c->ebx), (uint32_t)(c->edx)); /* mov dword ptr [ebx], edx */
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [ebx + 4], edx */
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [ebx + 8], edx */
    if ((c->cf || c->zf)) goto L_00b2cafb; /* jbe 0xb2cafb */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x10], eax */
L_00b2caae:;
    c->esi = (uint32_t)(c->ebx); /* mov esi, ebx */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea edi, [ebp - 0x10] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    PUSH32(c, 0x00b2cabcu); f_00b2ca2c(c); /* call 0xb2ca2c */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b2cac2u); f_00b2ca2c(c); /* call 0xb2ca2c */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b2caccu); f_00b2c9ce(c); /* call 0xb2c9ce */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b2cad2u); f_00b2ca2c(c); /* call 0xb2ca2c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0xc], 0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 8], 0 */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->eax))); /* movsx eax, byte ptr [eax] */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x10], eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b2caedu); f_00b2c9ce(c); /* call 0xb2c9ce */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x10u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 0x10] */
    if (!c->zf) goto L_00b2caae; /* jne 0xb2caae */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_00b2cafb:;
    (void)sub32(c, R32((uint32_t)(c->ebx + 0x8u)), c->edx); /* cmp dword ptr [ebx + 8], edx */
    if (!c->zf) goto L_00b2cb28; /* jne 0xb2cb28 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov ecx, dword ptr [ebx + 4] */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->eax = (uint32_t)(shr32(c, c->eax, 16)); /* shr eax, 0x10 */
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->esi = (uint32_t)(shr32(c, c->esi, 16)); /* shr esi, 0x10 */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 16)); /* shl ecx, 0x10 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi | c->ecx))); /* or esi, ecx */
    c->eax = (uint32_t)(shl32(c, c->eax, 16)); /* shl eax, 0x10 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0xfff0u))); } /* add dword ptr [ebp - 4], 0xfff0 */
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [ebx + 4], esi */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
    goto L_00b2cafb; /* jmp 0xb2cafb */
L_00b2cb28:;
    c->esi = (uint32_t)((uint32_t)0x8000u); /* mov esi, 0x8000 */
L_00b2cb2d:;
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->ebx + 0x8u)) & c->esi)); /* test dword ptr [ebx + 8], esi */
    if (!c->zf) goto L_00b2cb42; /* jne 0xb2cb42 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b2cb38u); f_00b2ca2c(c); /* call 0xb2ca2c */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0xffffu))); } /* add dword ptr [ebp - 4], 0xffff */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00b2cb2d; /* jmp 0xb2cb2d */
L_00b2cb42:;
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ax, word ptr [ebp - 4] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W16((uint32_t)(c->ebx + 0xau), (uint16_t)(((uint16_t)c->eax))); /* mov word ptr [ebx + 0xa], ax */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b2cb4e(CPU *c) { /* FUN_1000cb4e */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x24u)); /* sub esp, 0x24 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ebx, dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    c->ecx = (c->ecx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ebx + 0xau))); /* mov cx, word ptr [ebx + 0xa] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x14], eax */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->esi + 0xau))); /* mov ax, word ptr [esi + 0xa] */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    c->edx = (uint32_t)((uint32_t)0x7fffu); /* mov edx, 0x7fff */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi ^ c->eax))); /* xor edi, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & c->edx))); /* and eax, edx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & c->edx))); /* and ecx, edx */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & (uint32_t)0x8000u))); /* and edi, 0x8000 */
    (void)sub16(c, ((uint16_t)c->eax), (uint16_t)0x7fffu); /* cmp ax, 0x7fff */
    c->edx = (uint32_t)((uint32_t)(c->ecx + c->eax)); /* lea edx, [ecx + eax] */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [ebp + 8], edx */
    if (!c->cf) goto L_00b2cd4e; /* jae 0xb2cd4e */
    (void)sub16(c, ((uint16_t)c->ecx), (uint16_t)0x7fffu); /* cmp cx, 0x7fff */
    if (!c->cf) goto L_00b2cd4e; /* jae 0xb2cd4e */
    (void)sub16(c, ((uint16_t)c->edx), (uint16_t)0xbffdu); /* cmp dx, 0xbffd */
    if ((!c->cf && !c->zf)) goto L_00b2cd4e; /* ja 0xb2cd4e */
    (void)sub16(c, ((uint16_t)c->edx), (uint16_t)0x3fbfu); /* cmp dx, 0x3fbf */
    if ((!c->cf && !c->zf)) goto L_00b2cbb7; /* ja 0xb2cbb7 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00b2cbf1; /* jmp 0xb2cbf1 */
L_00b2cbb7:;
    (void)logic16(c, (uint16_t)(((uint16_t)c->eax) & ((uint16_t)c->eax))); /* test ax, ax */
    c->edx = (uint32_t)((uint32_t)0x7fffffffu); /* mov edx, 0x7fffffff */
    if (!c->zf) goto L_00b2cbd9; /* jne 0xb2cbd9 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->esi + 0x8u)) & c->edx)); /* test dword ptr [esi + 8], edx */
    if (!c->zf) goto L_00b2cbd9; /* jne 0xb2cbd9 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x4u)), c->eax); /* cmp dword ptr [esi + 4], eax */
    if (!c->zf) goto L_00b2cbdb; /* jne 0xb2cbdb */
    (void)sub32(c, R32((uint32_t)(c->esi)), c->eax); /* cmp dword ptr [esi], eax */
    if (!c->zf) goto L_00b2cbdb; /* jne 0xb2cbdb */
    goto L_00b2cd48; /* jmp 0xb2cd48 */
L_00b2cbd9:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00b2cbdb:;
    (void)sub16(c, ((uint16_t)c->ecx), ((uint16_t)c->eax)); /* cmp cx, ax */
    if (!c->zf) goto L_00b2cbfe; /* jne 0xb2cbfe */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->ebx + 0x8u)) & c->edx)); /* test dword ptr [ebx + 8], edx */
    if (!c->zf) goto L_00b2cbfe; /* jne 0xb2cbfe */
    (void)sub32(c, R32((uint32_t)(c->ebx + 0x4u)), c->eax); /* cmp dword ptr [ebx + 4], eax */
    if (!c->zf) goto L_00b2cbfe; /* jne 0xb2cbfe */
    (void)sub32(c, R32((uint32_t)(c->ebx)), c->eax); /* cmp dword ptr [ebx], eax */
    if (!c->zf) goto L_00b2cbfe; /* jne 0xb2cbfe */
L_00b2cbf1:;
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 8], eax */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 4], eax */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    goto L_00b2cd69; /* jmp 0xb2cd69 */
L_00b2cbfe:;
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x10], eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe0u)); /* lea eax, [ebp - 0x20] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)((uint32_t)0x5u)); /* mov dword ptr [ebp + 0xc], 5 */
L_00b2cc0e:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    c->eax = (uint32_t)(add32(c, c->eax, c->eax)); /* add eax, eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    if ((c->zf || c->sf != c->of)) goto L_00b2cc62; /* jle 0xb2cc62 */
    c->eax = (uint32_t)(add32(c, c->eax, c->esi)); /* add eax, esi */
    c->ecx = (uint32_t)((uint32_t)(c->ebx + 0x8u)); /* lea ecx, [ebx + 8] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 0xc], ecx */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x18], eax */
L_00b2cc2a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    c->eax = (uint32_t)((uint32_t)R16((uint32_t)(c->eax))); /* movzx eax, word ptr [eax] */
    c->ecx = (uint32_t)((uint32_t)R16((uint32_t)(c->ecx))); /* movzx ecx, word ptr [ecx] */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)c->ecx; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0xfffffffcu)); /* add ecx, -4 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ecx)); PUSH32(c, v_); } /* push dword ptr [ecx] */
    PUSH32(c, 0x00b2cc48u); f_00b2c9ad(c); /* call 0xb2c9ad */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b2cc55; /* je 0xb2cc55 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    { uint32_t a_ = (uint32_t)(c->eax); W16(a_, (uint16_t)(inc16(c, R16(a_)))); } /* inc word ptr [eax] */
L_00b2cc55:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x2u))); } /* add dword ptr [ebp - 8], 2 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff4u); W32(a_, (uint32_t)(sub32(c, R32(a_), (uint32_t)0x2u))); } /* sub dword ptr [ebp - 0xc], 2 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 0x18] */
    if (!c->zf) goto L_00b2cc2a; /* jne 0xb2cc2a */
L_00b2cc62:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x2u))); } /* add dword ptr [ebp - 4], 2 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff0u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0x10] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_00b2cc0e; /* jg 0xb2cc0e */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0xc002u))); } /* add dword ptr [ebp + 8], 0xc002 */
    (void)sub16(c, R16((uint32_t)(c->ebp + 0x8u)), (uint16_t)0x0u); /* cmp word ptr [ebp + 8], 0 */
    if ((c->zf || c->sf != c->of)) goto L_00b2cca5; /* jle 0xb2cca5 */
L_00b2cc80:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xffffffe7u)) & (uint8_t)0x80u)); /* test byte ptr [ebp - 0x19], 0x80 */
    if (!c->zf) goto L_00b2cc9e; /* jne 0xb2cc9e */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffdcu)); /* lea eax, [ebp - 0x24] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2cc8fu); f_00b2ca2c(c); /* call 0xb2ca2c */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0xffffu))); } /* add dword ptr [ebp + 8], 0xffff */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub16(c, R16((uint32_t)(c->ebp + 0x8u)), (uint16_t)0x0u); /* cmp word ptr [ebp + 8], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_00b2cc80; /* jg 0xb2cc80 */
L_00b2cc9e:;
    (void)sub16(c, R16((uint32_t)(c->ebp + 0x8u)), (uint16_t)0x0u); /* cmp word ptr [ebp + 8], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_00b2ccde; /* jg 0xb2ccde */
L_00b2cca5:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0xffffu))); } /* add dword ptr [ebp + 8], 0xffff */
    (void)sub16(c, R16((uint32_t)(c->ebp + 0x8u)), (uint16_t)0x0u); /* cmp word ptr [ebp + 8], 0 */
    if ((c->sf == c->of)) goto L_00b2ccde; /* jge 0xb2ccde */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int16_t)R16((uint32_t)(c->ebp + 0x8u))); /* movsx eax, word ptr [ebp + 8] */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(add32(c, R32(a_), c->eax))); } /* add dword ptr [ebp + 8], eax */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
L_00b2ccbe:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xffffffdcu)) & (uint8_t)0x1u)); /* test byte ptr [ebp - 0x24], 1 */
    if (c->zf) goto L_00b2ccc7; /* je 0xb2ccc7 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffecu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0x14] */
L_00b2ccc7:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffdcu)); /* lea eax, [ebp - 0x24] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2ccd0u); f_00b2ca5a(c); /* call 0xb2ca5a */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00b2ccbe; /* jne 0xb2ccbe */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffecu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x14], 0 */
    if (c->zf) goto L_00b2ccde; /* je 0xb2ccde */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffdcu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x1u)))); } /* or byte ptr [ebp - 0x24], 1 */
L_00b2ccde:;
    (void)sub16(c, R16((uint32_t)(c->ebp + 0xffffffdcu)), (uint16_t)0x8000u); /* cmp word ptr [ebp - 0x24], 0x8000 */
    if ((!c->cf && !c->zf)) goto L_00b2ccf5; /* ja 0xb2ccf5 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1ffffu))); /* and eax, 0x1ffff */
    (void)sub32(c, c->eax, (uint32_t)0x18000u); /* cmp eax, 0x18000 */
    if (!c->zf) goto L_00b2cd2a; /* jne 0xb2cd2a */
L_00b2ccf5:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdeu)), (uint32_t)0xffffffffu); /* cmp dword ptr [ebp - 0x22], -1 */
    if (!c->zf) goto L_00b2cd27; /* jne 0xb2cd27 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffdeu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x22], 0 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe2u)), (uint32_t)0xffffffffu); /* cmp dword ptr [ebp - 0x1e], -1 */
    if (!c->zf) goto L_00b2cd22; /* jne 0xb2cd22 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe2u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x1e], 0 */
    (void)sub16(c, R16((uint32_t)(c->ebp + 0xffffffe6u)), (uint16_t)0xffffu); /* cmp word ptr [ebp - 0x1a], 0xffff */
    if (!c->zf) goto L_00b2cd1c; /* jne 0xb2cd1c */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp + 8] */
    W16((uint32_t)(c->ebp + 0xffffffe6u), (uint16_t)((uint16_t)0x8000u)); /* mov word ptr [ebp - 0x1a], 0x8000 */
    goto L_00b2cd2a; /* jmp 0xb2cd2a */
L_00b2cd1c:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe6u); W16(a_, (uint16_t)(inc16(c, R16(a_)))); } /* inc word ptr [ebp - 0x1a] */
    goto L_00b2cd2a; /* jmp 0xb2cd2a */
L_00b2cd22:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe2u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0x1e] */
    goto L_00b2cd2a; /* jmp 0xb2cd2a */
L_00b2cd27:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffdeu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0x22] */
L_00b2cd2a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)sub16(c, ((uint16_t)c->eax), (uint16_t)0x7fffu); /* cmp ax, 0x7fff */
    if (!c->cf) goto L_00b2cd4e; /* jae 0xb2cd4e */
    c->ecx = (c->ecx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ebp + 0xffffffdeu))); /* mov cx, word ptr [ebp - 0x22] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->edi))); /* or eax, edi */
    W16((uint32_t)(c->esi), (uint16_t)(((uint16_t)c->ecx))); /* mov word ptr [esi], cx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov ecx, dword ptr [ebp - 0x20] */
    W32((uint32_t)(c->esi + 0x2u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 2], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov ecx, dword ptr [ebp - 0x1c] */
    W32((uint32_t)(c->esi + 0x6u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 6], ecx */
L_00b2cd48:;
    W16((uint32_t)(c->esi + 0xau), (uint16_t)(((uint16_t)c->eax))); /* mov word ptr [esi + 0xa], ax */
    goto L_00b2cd69; /* jmp 0xb2cd69 */
L_00b2cd4e:;
    c->edi = (c->edi & 0xffff0000u) | (uint16_t)(neg16(c, ((uint16_t)c->edi))); /* neg di */
    c->edi = (uint32_t)(sbb32(c, c->edi, c->edi)); /* sbb edi, edi */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi + 4], 0 */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & (uint32_t)0x80000000u))); /* and edi, 0x80000000 */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x7fff8000u)); /* add edi, 0x7fff8000 */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi], 0 */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 8], edi */
L_00b2cd69:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b2cd6e(CPU *c) { /* FUN_1000cd6e */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)((uint32_t)0xb32e90u); /* mov ebx, 0x10012e90 */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->ebx = (uint32_t)(sub32(c, c->ebx, (uint32_t)0x60u)); /* sub ebx, 0x60 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->ecx); /* cmp dword ptr [ebp + 0xc], ecx */
    if (c->zf) goto L_00b2cde7; /* je 0xb2cde7 */
    if ((c->sf == c->of)) goto L_00b2cd96; /* jge 0xb2cd96 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->ebx = (uint32_t)((uint32_t)0xb32ff0u); /* mov ebx, 0x10012ff0 */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0xc], eax */
    c->ebx = (uint32_t)(sub32(c, c->ebx, (uint32_t)0x60u)); /* sub ebx, 0x60 */
L_00b2cd96:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), c->ecx); /* cmp dword ptr [ebp + 0x10], ecx */
    if (!c->zf) goto L_00b2cda1; /* jne 0xb2cda1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W16((uint32_t)(c->eax), (uint16_t)(((uint16_t)c->ecx))); /* mov word ptr [eax], cx */
L_00b2cda1:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->ecx); /* cmp dword ptr [ebp + 0xc], ecx */
    if (c->zf) goto L_00b2cde7; /* je 0xb2cde7 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
L_00b2cda8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x54u)); /* add ebx, 0x54 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(sar32(c, R32(a_), 3))); } /* sar dword ptr [ebp + 0xc], 3 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7u))); /* and eax, 7 */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (c->zf) goto L_00b2cde0; /* je 0xb2cde0 */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea eax, [eax + eax*2] */
    (void)sub16(c, R16((uint32_t)(c->ebx + c->eax * 4)), (uint16_t)0x8000u); /* cmp word ptr [ebx + eax*4], 0x8000 */
    c->esi = (uint32_t)((uint32_t)(c->ebx + c->eax * 4)); /* lea esi, [ebx + eax*4] */
    if (c->cf) goto L_00b2cdd3; /* jb 0xb2cdd3 */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea edi, [ebp - 0xc] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff6u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 0xa] */
    c->esi = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea esi, [ebp - 0xc] */
L_00b2cdd3:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00b2cddcu); f_00b2cb4e(c); /* call 0xb2cb4e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
L_00b2cde0:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->ecx); /* cmp dword ptr [ebp + 0xc], ecx */
    if (!c->zf) goto L_00b2cda8; /* jne 0xb2cda8 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00b2cde7:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b2cdea(CPU *c) { /* FUN_1000cdea */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xb2e788u; PUSH32(c, v_); } /* push 0x1000e788 */
    { uint32_t v_ = 0xb273f8u; PUSH32(c, v_); } /* push 0x100073f8 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x1cu)); /* sub esp, 0x1c */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, R32((uint32_t)(0xb336a0u)), c->edi); /* cmp dword ptr [0x100136a0], edi */
    if (!c->zf) goto L_00b2ce60; /* jne 0xb2ce60 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0xb2e73cu; PUSH32(c, v_); } /* push 0x1000e73c */
    c->esi = (uint32_t)((uint32_t)0x100u); /* mov esi, 0x100 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0xb2e0dcu)); PUSH32(c, 0x00b2ce32u); call_indirect(c, t_); } /* call dword ptr [0x1000e0dc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b2ce3e; /* je 0xb2ce3e */
    W32((uint32_t)(0xb336a0u), (uint32_t)(c->ebx)); /* mov dword ptr [0x100136a0], ebx */
    goto L_00b2ce60; /* jmp 0xb2ce60 */
L_00b2ce3e:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0xb2e738u; PUSH32(c, v_); } /* push 0x1000e738 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0xb2e0d8u)); PUSH32(c, 0x00b2ce4eu); call_indirect(c, t_); } /* call dword ptr [0x1000e0d8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b2cf78; /* je 0xb2cf78 */
    W32((uint32_t)(0xb336a0u), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [0x100136a0], 2 */
L_00b2ce60:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x14u)), c->edi); /* cmp dword ptr [ebp + 0x14], edi */
    if ((c->zf || c->sf != c->of)) goto L_00b2ce75; /* jle 0xb2ce75 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    PUSH32(c, 0x00b2ce70u); f_00b2d00e(c); /* call 0xb2d00e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x14], eax */
L_00b2ce75:;
    c->eax = (uint32_t)(R32((uint32_t)(0xb336a0u))); /* mov eax, dword ptr [0x100136a0] */
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00b2ce9c; /* jne 0xb2ce9c */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0xb2e0d8u)); PUSH32(c, 0x00b2ce97u); call_indirect(c, t_); } /* call dword ptr [0x1000e0d8] */
    goto L_00b2cf7a; /* jmp 0xb2cf7a */
L_00b2ce9c:;
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_00b2cf78; /* jne 0xb2cf78 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x20u)), c->edi); /* cmp dword ptr [ebp + 0x20], edi */
    if (!c->zf) goto L_00b2ceb2; /* jne 0xb2ceb2 */
    c->eax = (uint32_t)(R32((uint32_t)(0xb3368cu))); /* mov eax, dword ptr [0x1001368c] */
    W32((uint32_t)(c->ebp + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x20], eax */
L_00b2ceb2:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x24u))); /* mov eax, dword ptr [ebp + 0x24] */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x8u))); /* and eax, 8 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t t_ = R32((uint32_t)(0xb2e0b4u)); PUSH32(c, 0x00b2cecfu); call_indirect(c, t_); } /* call dword ptr [0x1000e0b4] */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x1c], ebx */
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    if (c->zf) goto L_00b2cf78; /* je 0xb2cf78 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 4], edi */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->ebx)); /* lea eax, [ebx + ebx] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x3u)); /* add eax, 3 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfcu))); /* and al, 0xfc */
    PUSH32(c, 0x00b2ceecu); f_00b2c630(c); /* call 0xb2c630 */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    c->eax = (uint32_t)(c->esp); /* mov eax, esp */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    goto L_00b2cf0d; /* jmp 0xb2cf0d */
L_00b2cf0d:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), c->edi); /* cmp dword ptr [ebp - 0x24], edi */
    if (c->zf) goto L_00b2cf78; /* je 0xb2cf78 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t t_ = R32((uint32_t)(0xb2e0b4u)); PUSH32(c, 0x00b2cf27u); call_indirect(c, t_); } /* call dword ptr [0x1000e0b4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b2cf78; /* je 0xb2cf78 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0xb2e0dcu)); PUSH32(c, 0x00b2cf3du); call_indirect(c, t_); } /* call dword ptr [0x1000e0dc] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x28], esi */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (c->zf) goto L_00b2cf78; /* je 0xb2cf78 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xdu)) & (uint8_t)0x4u)); /* test byte ptr [ebp + 0xd], 4 */
    if (c->zf) goto L_00b2cf8c; /* je 0xb2cf8c */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x1cu)), c->edi); /* cmp dword ptr [ebp + 0x1c], edi */
    if (c->zf) goto L_00b2d007; /* je 0xb2d007 */
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0x1cu))); /* cmp esi, dword ptr [ebp + 0x1c] */
    if ((!c->zf && c->sf == c->of)) goto L_00b2cf78; /* jg 0xb2cf78 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0xb2e0dcu)); PUSH32(c, 0x00b2cf70u); call_indirect(c, t_); } /* call dword ptr [0x1000e0dc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b2d007; /* jne 0xb2d007 */
L_00b2cf78:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00b2cf7a:;
    c->esp = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea esp, [ebp - 0x38] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2cf8c:;
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi)); /* lea eax, [esi + esi] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x3u)); /* add eax, 3 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfcu))); /* and al, 0xfc */
    PUSH32(c, 0x00b2cfa0u); f_00b2c630(c); /* call 0xb2c630 */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    c->ebx = (uint32_t)(c->esp); /* mov ebx, esp */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x20], ebx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    goto L_00b2cfc0; /* jmp 0xb2cfc0 */
L_00b2cfc0:;
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    if (c->zf) goto L_00b2cf78; /* je 0xb2cf78 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0xb2e0dcu)); PUSH32(c, 0x00b2cfd8u); call_indirect(c, t_); } /* call dword ptr [0x1000e0dc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b2cf78; /* je 0xb2cf78 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x1cu)), c->edi); /* cmp dword ptr [ebp + 0x1c], edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00b2cfe7; /* jne 0xb2cfe7 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    goto L_00b2cfed; /* jmp 0xb2cfed */
L_00b2cfe7:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
L_00b2cfed:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x220u; PUSH32(c, v_); } /* push 0x220 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t t_ = R32((uint32_t)(0xb2e080u)); PUSH32(c, 0x00b2cffdu); call_indirect(c, t_); } /* call dword ptr [0x1000e080] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (c->zf) goto L_00b2cf78; /* je 0xb2cf78 */
L_00b2d007:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    goto L_00b2cf7a; /* jmp 0xb2cf7a */
}

void f_00b2cefa(CPU *c) { /* PTR_00b2cefa */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_00b2cefe(CPU *c) { /* PTR_00b2cefe */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov ebx, dword ptr [ebp - 0x1c] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), c->edi); /* cmp dword ptr [ebp - 0x24], edi */
    if (c->zf) goto L_00b2cf78; /* je 0xb2cf78 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t t_ = R32((uint32_t)(0xb2e0b4u)); PUSH32(c, 0x00b2cf27u); call_indirect(c, t_); } /* call dword ptr [0x1000e0b4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b2cf78; /* je 0xb2cf78 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0xb2e0dcu)); PUSH32(c, 0x00b2cf3du); call_indirect(c, t_); } /* call dword ptr [0x1000e0dc] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x28], esi */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (c->zf) goto L_00b2cf78; /* je 0xb2cf78 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xdu)) & (uint8_t)0x4u)); /* test byte ptr [ebp + 0xd], 4 */
    if (c->zf) goto L_00b2cf8c; /* je 0xb2cf8c */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x1cu)), c->edi); /* cmp dword ptr [ebp + 0x1c], edi */
    if (c->zf) goto L_00b2d007; /* je 0xb2d007 */
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0x1cu))); /* cmp esi, dword ptr [ebp + 0x1c] */
    if ((!c->zf && c->sf == c->of)) goto L_00b2cf78; /* jg 0xb2cf78 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0xb2e0dcu)); PUSH32(c, 0x00b2cf70u); call_indirect(c, t_); } /* call dword ptr [0x1000e0dc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b2d007; /* jne 0xb2d007 */
L_00b2cf78:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00b2cf7a:;
    c->esp = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea esp, [ebp - 0x38] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2cf8c:;
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi)); /* lea eax, [esi + esi] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x3u)); /* add eax, 3 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfcu))); /* and al, 0xfc */
    PUSH32(c, 0x00b2cfa0u); f_00b2c630(c); /* call 0xb2c630 */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    c->ebx = (uint32_t)(c->esp); /* mov ebx, esp */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x20], ebx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    goto L_00b2cfc0; /* jmp 0xb2cfc0 */
L_00b2cfc0:;
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    if (c->zf) goto L_00b2cf78; /* je 0xb2cf78 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0xb2e0dcu)); PUSH32(c, 0x00b2cfd8u); call_indirect(c, t_); } /* call dword ptr [0x1000e0dc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b2cf78; /* je 0xb2cf78 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x1cu)), c->edi); /* cmp dword ptr [ebp + 0x1c], edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00b2cfe7; /* jne 0xb2cfe7 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    goto L_00b2cfed; /* jmp 0xb2cfed */
L_00b2cfe7:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
L_00b2cfed:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x220u; PUSH32(c, v_); } /* push 0x220 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t t_ = R32((uint32_t)(0xb2e080u)); PUSH32(c, 0x00b2cffdu); call_indirect(c, t_); } /* call dword ptr [0x1000e080] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (c->zf) goto L_00b2cf78; /* je 0xb2cf78 */
L_00b2d007:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    goto L_00b2cf7a; /* jmp 0xb2cf7a */
}

void f_00b2cf78(CPU *c) { /* PTR_00b2cf78 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea esp, [ebp - 0x38] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b2cfae(CPU *c) { /* PTR_00b2cfae */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_00b2cfb2(CPU *c) { /* PTR_00b2cfb2 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov esi, dword ptr [ebp - 0x28] */
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    if (c->zf) { f_00b2cf78(c); return; } /* je 0xb2cf78 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0xb2e0dcu)); PUSH32(c, 0x00b2cfd8u); call_indirect(c, t_); } /* call dword ptr [0x1000e0dc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) { f_00b2cf78(c); return; } /* je 0xb2cf78 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x1cu)), c->edi); /* cmp dword ptr [ebp + 0x1c], edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00b2cfe7; /* jne 0xb2cfe7 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    goto L_00b2cfed; /* jmp 0xb2cfed */
L_00b2cfe7:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
L_00b2cfed:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x220u; PUSH32(c, v_); } /* push 0x220 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t t_ = R32((uint32_t)(0xb2e080u)); PUSH32(c, 0x00b2cffdu); call_indirect(c, t_); } /* call dword ptr [0x1000e080] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (c->zf) { f_00b2cf78(c); return; } /* je 0xb2cf78 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { jump_indirect(c, 0x00b2cf7au, 0x00b2d009u); return; } /* jmp 0xb2cf7a */
}

void f_00b2d00e(CPU *c) { /* FUN_1000d00e */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ecx = (uint32_t)((uint32_t)(c->edx + 0xffffffffu)); /* lea ecx, [edx - 1] */
    if (c->zf) goto L_00b2d02b; /* je 0xb2d02b */
L_00b2d01e:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (c->zf) goto L_00b2d02b; /* je 0xb2d02b */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_00b2d01e; /* jne 0xb2d01e */
L_00b2d02b:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    if (!c->zf) goto L_00b2d036; /* jne 0xb2d036 */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->esp + 0x4u)))); /* sub eax, dword ptr [esp + 4] */
    c->esp += 4; return; /* ret  */
L_00b2d036:;
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    c->esp += 4; return; /* ret  */
}

void f_00b2d039(CPU *c) { /* FUN_1000d039 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x1cu)); /* sub esp, 0x1c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov ebx, dword ptr [ebp + 0x1c] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->esi = (uint32_t)((uint32_t)0x7fffu); /* mov esi, 0x7fff */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x8000u))); /* and ecx, 0x8000 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & c->esi))); /* and eax, esi */
    (void)logic16(c, (uint16_t)(((uint16_t)c->ecx) & ((uint16_t)c->ecx))); /* test cx, cx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W8((uint32_t)(c->ebp + 0xffffffe4u), (uint8_t)((uint8_t)0xccu)); /* mov byte ptr [ebp - 0x1c], 0xcc */
    W8((uint32_t)(c->ebp + 0xffffffe5u), (uint8_t)((uint8_t)0xccu)); /* mov byte ptr [ebp - 0x1b], 0xcc */
    W8((uint32_t)(c->ebp + 0xffffffe6u), (uint8_t)((uint8_t)0xccu)); /* mov byte ptr [ebp - 0x1a], 0xcc */
    W8((uint32_t)(c->ebp + 0xffffffe7u), (uint8_t)((uint8_t)0xccu)); /* mov byte ptr [ebp - 0x19], 0xcc */
    W8((uint32_t)(c->ebp + 0xffffffe8u), (uint8_t)((uint8_t)0xccu)); /* mov byte ptr [ebp - 0x18], 0xcc */
    W8((uint32_t)(c->ebp + 0xffffffe9u), (uint8_t)((uint8_t)0xccu)); /* mov byte ptr [ebp - 0x17], 0xcc */
    W8((uint32_t)(c->ebp + 0xffffffeau), (uint8_t)((uint8_t)0xccu)); /* mov byte ptr [ebp - 0x16], 0xcc */
    W8((uint32_t)(c->ebp + 0xffffffebu), (uint8_t)((uint8_t)0xccu)); /* mov byte ptr [ebp - 0x15], 0xcc */
    W8((uint32_t)(c->ebp + 0xffffffecu), (uint8_t)((uint8_t)0xccu)); /* mov byte ptr [ebp - 0x14], 0xcc */
    W8((uint32_t)(c->ebp + 0xffffffedu), (uint8_t)((uint8_t)0xccu)); /* mov byte ptr [ebp - 0x13], 0xcc */
    W8((uint32_t)(c->ebp + 0xffffffeeu), (uint8_t)((uint8_t)0xfbu)); /* mov byte ptr [ebp - 0x12], 0xfb */
    W8((uint32_t)(c->ebp + 0xffffffefu), (uint8_t)((uint8_t)0x3fu)); /* mov byte ptr [ebp - 0x11], 0x3f */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    if (c->zf) goto L_00b2d09b; /* je 0xb2d09b */
    W8((uint32_t)(c->ebx + 0x2u), (uint8_t)((uint8_t)0x2du)); /* mov byte ptr [ebx + 2], 0x2d */
    goto L_00b2d09f; /* jmp 0xb2d09f */
L_00b2d09b:;
    W8((uint32_t)(c->ebx + 0x2u), (uint8_t)((uint8_t)0x20u)); /* mov byte ptr [ebx + 2], 0x20 */
L_00b2d09f:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    (void)logic16(c, (uint16_t)(((uint16_t)c->edx) & ((uint16_t)c->edx))); /* test dx, dx */
    if (!c->zf) goto L_00b2d0c5; /* jne 0xb2d0c5 */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (!c->zf) goto L_00b2d0c5; /* jne 0xb2d0c5 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), c->edi); /* cmp dword ptr [ebp + 8], edi */
    if (!c->zf) goto L_00b2d0c5; /* jne 0xb2d0c5 */
L_00b2d0b0:;
    { uint32_t a_ = (uint32_t)(c->ebx); W16(a_, (uint16_t)(logic16(c, (uint16_t)(R16(a_) & (uint16_t)0x0u)))); } /* and word ptr [ebx], 0 */
    W8((uint32_t)(c->ebx + 0x2u), (uint8_t)((uint8_t)0x20u)); /* mov byte ptr [ebx + 2], 0x20 */
    W8((uint32_t)(c->ebx + 0x3u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ebx + 3], 1 */
    W8((uint32_t)(c->ebx + 0x4u), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [ebx + 4], 0x30 */
    goto L_00b2d2c3; /* jmp 0xb2d2c3 */
L_00b2d0c5:;
    (void)sub16(c, ((uint16_t)c->edx), ((uint16_t)c->esi)); /* cmp dx, si */
    if (!c->zf) goto L_00b2d144; /* jne 0xb2d144 */
    c->eax = (uint32_t)((uint32_t)0x80000000u); /* mov eax, 0x80000000 */
    W16((uint32_t)(c->ebx), (uint16_t)((uint16_t)0x1u)); /* mov word ptr [ebx], 1 */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (!c->zf) goto L_00b2d0de; /* jne 0xb2d0de */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    if (c->zf) goto L_00b2d0ed; /* je 0xb2d0ed */
L_00b2d0de:;
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x40000000u)); /* test edi, 0x40000000 */
    if (!c->zf) goto L_00b2d0ed; /* jne 0xb2d0ed */
    { uint32_t v_ = 0xb2e7b8u; PUSH32(c, v_); } /* push 0x1000e7b8 */
    goto L_00b2d133; /* jmp 0xb2d133 */
L_00b2d0ed:;
    (void)logic16(c, (uint16_t)(((uint16_t)c->ecx) & ((uint16_t)c->ecx))); /* test cx, cx */
    if (c->zf) goto L_00b2d107; /* je 0xb2d107 */
    (void)sub32(c, c->edi, (uint32_t)0xc0000000u); /* cmp edi, 0xc0000000 */
    if (!c->zf) goto L_00b2d107; /* jne 0xb2d107 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    if (!c->zf) goto L_00b2d12e; /* jne 0xb2d12e */
    { uint32_t v_ = 0xb2e7b0u; PUSH32(c, v_); } /* push 0x1000e7b0 */
    goto L_00b2d116; /* jmp 0xb2d116 */
L_00b2d107:;
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (!c->zf) goto L_00b2d12e; /* jne 0xb2d12e */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    if (!c->zf) goto L_00b2d12e; /* jne 0xb2d12e */
    { uint32_t v_ = 0xb2e7a8u; PUSH32(c, v_); } /* push 0x1000e7a8 */
L_00b2d116:;
    c->eax = (uint32_t)((uint32_t)(c->ebx + 0x4u)); /* lea eax, [ebx + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2d11fu); f_00b2bc60(c); /* call 0xb2bc60 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W8((uint32_t)(c->ebx + 0x3u), (uint8_t)((uint8_t)0x5u)); /* mov byte ptr [ebx + 3], 5 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b2d125:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    goto L_00b2d29c; /* jmp 0xb2d29c */
L_00b2d12e:;
    { uint32_t v_ = 0xb2e7a0u; PUSH32(c, v_); } /* push 0x1000e7a0 */
L_00b2d133:;
    c->eax = (uint32_t)((uint32_t)(c->ebx + 0x4u)); /* lea eax, [ebx + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2d13cu); f_00b2bc60(c); /* call 0xb2bc60 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W8((uint32_t)(c->ebx + 0x3u), (uint8_t)((uint8_t)0x6u)); /* mov byte ptr [ebx + 3], 6 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00b2d125; /* jmp 0xb2d125 */
L_00b2d144:;
    c->eax = (uint32_t)((uint32_t)((uint16_t)c->edx)); /* movzx eax, dx */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 24)); /* shr ecx, 0x18 */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)(uint32_t)0x4d10u; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, eax, 0x4d10 */
    c->esi = (uint32_t)(shr32(c, c->esi, 8)); /* shr esi, 8 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff0u); W16(a_, (uint16_t)(logic16(c, (uint16_t)(R16(a_) & (uint16_t)0x0u)))); } /* and word ptr [ebp - 0x10], 0 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + c->ecx * 2)); /* lea ecx, [esi + ecx*2] */
    W16((uint32_t)(c->ebp + 0xfffffffau), (uint16_t)(((uint16_t)c->edx))); /* mov word ptr [ebp - 6], dx */
    { int64_t r_ = (int64_t)(int32_t)c->ecx * (int32_t)(uint32_t)0x4du; c->ecx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul ecx, ecx, 0x4d */
    W32((uint32_t)(c->ebp + 0xfffffff6u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0xa], edi */
    c->esi = (uint32_t)((uint32_t)(c->ecx + c->eax + 0xecbced0cu)); /* lea esi, [ecx + eax - 0x134312f4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->esi = (uint32_t)(sar32(c, c->esi, 16)); /* sar esi, 0x10 */
    W32((uint32_t)(c->ebp + 0xfffffff2u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xe], eax */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int16_t)((uint16_t)c->esi)); /* movsx eax, si */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2d18au); f_00b2cd6e(c); /* call 0xb2cd6e */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub16(c, R16((uint32_t)(c->ebp + 0xfffffffau)), (uint16_t)0x3fffu); /* cmp word ptr [ebp - 6], 0x3fff */
    if (c->cf) goto L_00b2d1a5; /* jb 0xb2d1a5 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe4u)); /* lea eax, [ebp - 0x1c] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2d1a3u); f_00b2cb4e(c); /* call 0xb2cb4e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b2d1a5:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0x18u)) & (uint8_t)0x1u)); /* test byte ptr [ebp + 0x18], 1 */
    W16((uint32_t)(c->ebx), (uint16_t)(((uint16_t)c->esi))); /* mov word ptr [ebx], si */
    if (c->zf) goto L_00b2d1bf; /* je 0xb2d1bf */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov edi, dword ptr [ebp + 0x14] */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int16_t)((uint16_t)c->esi)); /* movsx eax, si */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if ((!c->zf && c->sf == c->of)) goto L_00b2d1c2; /* jg 0xb2d1c2 */
    goto L_00b2d0b0; /* jmp 0xb2d0b0 */
L_00b2d1bf:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov edi, dword ptr [ebp + 0x14] */
L_00b2d1c2:;
    (void)sub32(c, c->edi, (uint32_t)0x15u); /* cmp edi, 0x15 */
    if ((c->zf || c->sf != c->of)) goto L_00b2d1ca; /* jle 0xb2d1ca */
    { uint32_t v_ = 0x15u; PUSH32(c, v_); } /* push 0x15 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_00b2d1ca:;
    c->esi = (uint32_t)((uint32_t)R16((uint32_t)(c->ebp + 0xfffffffau))); /* movzx esi, word ptr [ebp - 6] */
    c->esi = (uint32_t)(sub32(c, c->esi, (uint32_t)0x3ffeu)); /* sub esi, 0x3ffe */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffau); W16(a_, (uint16_t)(logic16(c, (uint16_t)(R16(a_) & (uint16_t)0x0u)))); } /* and word ptr [ebp - 6], 0 */
    W32((uint32_t)(c->ebp + 0x1cu), (uint32_t)((uint32_t)0x8u)); /* mov dword ptr [ebp + 0x1c], 8 */
L_00b2d1e0:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2d1e9u); f_00b2ca2c(c); /* call 0xb2ca2c */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x1cu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 0x1c] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00b2d1e0; /* jne 0xb2d1e0 */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if ((c->sf == c->of)) goto L_00b2d20a; /* jge 0xb2d20a */
    c->esi = (uint32_t)(neg32(c, c->esi)); /* neg esi */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xffu))); /* and esi, 0xff */
    if ((c->zf || c->sf != c->of)) goto L_00b2d20a; /* jle 0xb2d20a */
L_00b2d1fd:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2d206u); f_00b2ca5a(c); /* call 0xb2ca5a */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00b2d1fd; /* jne 0xb2d1fd */
L_00b2d20a:;
    c->ecx = (uint32_t)((uint32_t)(c->edi + 0x1u)); /* lea ecx, [edi + 1] */
    c->eax = (uint32_t)((uint32_t)(c->ebx + 0x4u)); /* lea eax, [ebx + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    W32((uint32_t)(c->ebp + 0x1cu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x1c], eax */
    if ((c->zf || c->sf != c->of)) goto L_00b2d267; /* jle 0xb2d267 */
    W32((uint32_t)(c->ebp + 0x14u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp + 0x14], ecx */
L_00b2d21a:;
    c->esi = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea esi, [ebp - 0x10] */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0x8u)); /* lea edi, [ebp + 8] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    PUSH32(c, 0x00b2d22cu); f_00b2ca2c(c); /* call 0xb2ca2c */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2d235u); f_00b2ca2c(c); /* call 0xb2ca2c */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x8u)); /* lea eax, [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2d242u); f_00b2c9ce(c); /* call 0xb2c9ce */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2d24bu); f_00b2ca2c(c); /* call 0xb2ca2c */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffbu))); /* mov al, byte ptr [ebp - 5] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov ecx, dword ptr [ebp + 0x1c] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffbu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp - 5], 0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(add8(c, ((uint8_t)c->eax), (uint8_t)0x30u)); /* add al, 0x30 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x1cu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp + 0x1c] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x14u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 0x14] */
    W8((uint32_t)(c->ecx), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ecx], al */
    if (!c->zf) goto L_00b2d21a; /* jne 0xb2d21a */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov eax, dword ptr [ebp + 0x1c] */
L_00b2d267:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0xffffffffu))); /* mov cl, byte ptr [eax - 1] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x35u); /* cmp cl, 0x35 */
    c->ecx = (uint32_t)((uint32_t)(c->ebx + 0x4u)); /* lea ecx, [ebx + 4] */
    if ((c->sf != c->of)) goto L_00b2d2a4; /* jl 0xb2d2a4 */
L_00b2d274:;
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (c->cf) goto L_00b2d287; /* jb 0xb2d287 */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x39u); /* cmp byte ptr [eax], 0x39 */
    if (!c->zf) goto L_00b2d283; /* jne 0xb2d283 */
    W8((uint32_t)(c->eax), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [eax], 0x30 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    goto L_00b2d274; /* jmp 0xb2d274 */
L_00b2d283:;
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->cf) goto L_00b2d28b; /* jae 0xb2d28b */
L_00b2d287:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t a_ = (uint32_t)(c->ebx); W16(a_, (uint16_t)(inc16(c, R16(a_)))); } /* inc word ptr [ebx] */
L_00b2d28b:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(inc8(c, R8(a_)))); } /* inc byte ptr [eax] */
L_00b2d28d:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx))); /* sub al, bl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sub8(c, ((uint8_t)c->eax), (uint8_t)0x3u)); /* sub al, 3 */
    W8((uint32_t)(c->ebx + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebx + 3], al */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->eax)); /* movsx eax, al */
    { uint32_t a_ = (uint32_t)(c->eax + c->ebx + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax + ebx + 4], 0 */
L_00b2d29c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
L_00b2d29f:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00b2d2a4:;
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (c->cf) goto L_00b2d2b4; /* jb 0xb2d2b4 */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x30u); /* cmp byte ptr [eax], 0x30 */
    if (!c->zf) goto L_00b2d2b0; /* jne 0xb2d2b0 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    goto L_00b2d2a4; /* jmp 0xb2d2a4 */
L_00b2d2b0:;
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->cf) goto L_00b2d28d; /* jae 0xb2d28d */
L_00b2d2b4:;
    { uint32_t a_ = (uint32_t)(c->ebx); W16(a_, (uint16_t)(logic16(c, (uint16_t)(R16(a_) & (uint16_t)0x0u)))); } /* and word ptr [ebx], 0 */
    W8((uint32_t)(c->ebx + 0x2u), (uint8_t)((uint8_t)0x20u)); /* mov byte ptr [ebx + 2], 0x20 */
    W8((uint32_t)(c->ebx + 0x3u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ebx + 3], 1 */
    W8((uint32_t)(c->ecx), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [ecx], 0x30 */
L_00b2d2c3:;
    { uint32_t a_ = (uint32_t)(c->ebx + 0x5u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebx + 5], 0 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_00b2d29f; /* jmp 0xb2d29f */
}

void f_00b2d2cc(CPU *c) { /* FUN_1000d2cc */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 4], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 8], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    W32((uint32_t)(c->ecx + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 0xc], eax */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0x10u))); /* mov cl, byte ptr [ebp + 0x10] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x10u)); /* test cl, 0x10 */
    if (c->zf) goto L_00b2d2fe; /* je 0xb2d2fe */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)((uint32_t)0xc000008fu)); /* mov dword ptr [ebp + 0x10], 0xc000008f */
    { uint32_t a_ = (uint32_t)(c->eax + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->ebx)))); } /* or dword ptr [eax + 4], ebx */
L_00b2d2fe:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x2u)); /* test cl, 2 */
    if (c->zf) goto L_00b2d311; /* je 0xb2d311 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)((uint32_t)0xc0000093u)); /* mov dword ptr [ebp + 0x10], 0xc0000093 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x2u)))); } /* or dword ptr [eax + 4], 2 */
L_00b2d311:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & ((uint8_t)c->ecx))); /* test bl, cl */
    if (c->zf) goto L_00b2d323; /* je 0xb2d323 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)((uint32_t)0xc0000091u)); /* mov dword ptr [ebp + 0x10], 0xc0000091 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x4u)))); } /* or dword ptr [eax + 4], 4 */
L_00b2d323:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x4u)); /* test cl, 4 */
    if (c->zf) goto L_00b2d336; /* je 0xb2d336 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)((uint32_t)0xc000008eu)); /* mov dword ptr [ebp + 0x10], 0xc000008e */
    { uint32_t a_ = (uint32_t)(c->eax + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x8u)))); } /* or dword ptr [eax + 4], 8 */
L_00b2d336:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x8u)); /* test cl, 8 */
    if (c->zf) goto L_00b2d349; /* je 0xb2d349 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)((uint32_t)0xc0000090u)); /* mov dword ptr [ebp + 0x10], 0xc0000090 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x10u)))); } /* or dword ptr [eax + 4], 0x10 */
L_00b2d349:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov edx, dword ptr [eax + 8] */
    c->ecx = (uint32_t)((uint32_t)~c->ecx); /* not ecx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & c->ebx))); /* and ecx, ebx */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0xffffffefu))); /* and edx, 0xffffffef */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 4)); /* shl ecx, 4 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->edx))); /* or ecx, edx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)((uint32_t)~c->ecx); /* not ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov edx, dword ptr [eax + 8] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x4u))); /* and ecx, 4 */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 1)); /* shl ecx, 1 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0xfffffff7u))); /* and edx, 0xfffffff7 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->edx))); /* or ecx, edx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)((uint32_t)~c->ecx); /* not ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov edx, dword ptr [eax + 8] */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 1)); /* shr ecx, 1 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x4u))); /* and ecx, 4 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0xfffffffbu))); /* and edx, 0xfffffffb */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->edx))); /* or ecx, edx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)((uint32_t)~c->ecx); /* not ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov edx, dword ptr [eax + 8] */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 3)); /* shr ecx, 3 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & c->edi))); /* and ecx, edi */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0xfffffffdu))); /* and edx, 0xfffffffd */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->edx))); /* or ecx, edx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)((uint32_t)~c->ecx); /* not ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov edx, dword ptr [eax + 8] */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 5)); /* shr ecx, 5 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & c->ebx))); /* and ecx, ebx */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0xfffffffeu))); /* and edx, 0xfffffffe */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->edx))); /* or ecx, edx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    PUSH32(c, 0x00b2d3c7u); f_00b2d7c1(c); /* call 0xb2d7c1 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & ((uint8_t)c->eax))); /* test bl, al */
    if (c->zf) goto L_00b2d3d2; /* je 0xb2d3d2 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x10u)))); } /* or dword ptr [ecx + 0xc], 0x10 */
L_00b2d3d2:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x4u)); /* test al, 4 */
    if (c->zf) goto L_00b2d3dd; /* je 0xb2d3dd */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x8u)))); } /* or dword ptr [ecx + 0xc], 8 */
L_00b2d3dd:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x8u)); /* test al, 8 */
    if (c->zf) goto L_00b2d3e8; /* je 0xb2d3e8 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x4u)))); } /* or dword ptr [ecx + 0xc], 4 */
L_00b2d3e8:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x10u)); /* test al, 0x10 */
    if (c->zf) goto L_00b2d3f2; /* je 0xb2d3f2 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edi)))); } /* or dword ptr [ecx + 0xc], edi */
L_00b2d3f2:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x20u)); /* test al, 0x20 */
    if (c->zf) goto L_00b2d3fc; /* je 0xb2d3fc */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->eax + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->ebx)))); } /* or dword ptr [eax + 0xc], ebx */
L_00b2d3fc:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)((uint32_t)0xc00u); /* mov ecx, 0xc00 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & c->ecx))); /* and eax, ecx */
    if (c->zf) goto L_00b2d43b; /* je 0xb2d43b */
    (void)sub32(c, c->eax, (uint32_t)0x400u); /* cmp eax, 0x400 */
    if (c->zf) goto L_00b2d42d; /* je 0xb2d42d */
    (void)sub32(c, c->eax, (uint32_t)0x800u); /* cmp eax, 0x800 */
    if (c->zf) goto L_00b2d421; /* je 0xb2d421 */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->zf) goto L_00b2d441; /* jne 0xb2d441 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x3u)))); } /* or dword ptr [eax], 3 */
    goto L_00b2d441; /* jmp 0xb2d441 */
L_00b2d421:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0xfffffffeu))); /* and ecx, 0xfffffffe */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->edi))); /* or ecx, edi */
    goto L_00b2d437; /* jmp 0xb2d437 */
L_00b2d42d:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0xfffffffdu))); /* and ecx, 0xfffffffd */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->ebx))); /* or ecx, ebx */
L_00b2d437:;
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    goto L_00b2d441; /* jmp 0xb2d441 */
L_00b2d43b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0xfffffffcu)))); } /* and dword ptr [eax], 0xfffffffc */
L_00b2d441:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)((uint32_t)0x300u); /* mov ecx, 0x300 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & c->ecx))); /* and eax, ecx */
    if (c->zf) goto L_00b2d46c; /* je 0xb2d46c */
    (void)sub32(c, c->eax, (uint32_t)0x200u); /* cmp eax, 0x200 */
    if (c->zf) goto L_00b2d45f; /* je 0xb2d45f */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->zf) goto L_00b2d479; /* jne 0xb2d479 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0xffffffe3u)))); } /* and dword ptr [eax], 0xffffffe3 */
    goto L_00b2d479; /* jmp 0xb2d479 */
L_00b2d45f:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0xffffffe7u))); /* and ecx, 0xffffffe7 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0x4u))); /* or ecx, 4 */
    goto L_00b2d477; /* jmp 0xb2d477 */
L_00b2d46c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0xffffffebu))); /* and ecx, 0xffffffeb */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0x8u))); /* or ecx, 8 */
L_00b2d477:;
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
L_00b2d479:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov ecx, dword ptr [ebp + 0x14] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0xfffu))); /* and ecx, 0xfff */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 5)); /* shl ecx, 5 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0xfffe001fu))); /* and edx, 0xfffe001f */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->edx))); /* or ecx, edx */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->eax + 0x20u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->ebx)))); } /* or dword ptr [eax + 0x20], ebx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x20u))); /* mov ecx, dword ptr [eax + 0x20] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0xffffffe3u))); /* and ecx, 0xffffffe3 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->edi))); /* or ecx, edi */
    W32((uint32_t)(c->eax + 0x20u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x20], ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov eax, dword ptr [ebp + 0x18] */
    FPUSH(c, RF64((uint32_t)(c->eax))); /* fld qword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    WF64((uint32_t)(c->eax + 0x10u), ST(0)); FPOP(c); /* fstp qword ptr [eax + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->eax + 0x50u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->ebx)))); } /* or dword ptr [eax + 0x50], ebx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x50u))); /* mov ecx, dword ptr [eax + 0x50] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0xffffffe3u))); /* and ecx, 0xffffffe3 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->edi))); /* or ecx, edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov edi, dword ptr [ebp + 0x1c] */
    W32((uint32_t)(c->eax + 0x50u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x50], ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    FPUSH(c, RF64((uint32_t)(c->edi))); /* fld qword ptr [edi] */
    WF64((uint32_t)(c->eax + 0x40u), ST(0)); FPOP(c); /* fstp qword ptr [eax + 0x40] */
    PUSH32(c, 0x00b2d4d7u); f_00b2d7cf(c); /* call 0xb2d7cf */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x8u)); /* lea eax, [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t t_ = R32((uint32_t)(0xb2e004u)); PUSH32(c, 0x00b2d4e7u); call_indirect(c, t_); } /* call dword ptr [0x1000e004] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + 0x8u)) & (uint8_t)0x10u)); /* test byte ptr [eax + 8], 0x10 */
    if (c->zf) goto L_00b2d4f3; /* je 0xb2d4f3 */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0xfffffffeu)))); } /* and dword ptr [esi], 0xfffffffe */
L_00b2d4f3:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + 0x8u)) & (uint8_t)0x8u)); /* test byte ptr [eax + 8], 8 */
    if (c->zf) goto L_00b2d4fc; /* je 0xb2d4fc */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0xfffffffbu)))); } /* and dword ptr [esi], 0xfffffffb */
L_00b2d4fc:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + 0x8u)) & (uint8_t)0x4u)); /* test byte ptr [eax + 8], 4 */
    if (c->zf) goto L_00b2d505; /* je 0xb2d505 */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0xfffffff7u)))); } /* and dword ptr [esi], 0xfffffff7 */
L_00b2d505:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + 0x8u)) & (uint8_t)0x2u)); /* test byte ptr [eax + 8], 2 */
    if (c->zf) goto L_00b2d50e; /* je 0xb2d50e */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0xffffffefu)))); } /* and dword ptr [esi], 0xffffffef */
L_00b2d50e:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + 0x8u)) & ((uint8_t)c->ebx))); /* test byte ptr [eax + 8], bl */
    if (c->zf) goto L_00b2d516; /* je 0xb2d516 */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0xffffffdfu)))); } /* and dword ptr [esi], 0xffffffdf */
L_00b2d516:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->edx = (uint32_t)((uint32_t)0xfffff3ffu); /* mov edx, 0xfffff3ff */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u))); /* and ecx, 3 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x0u)); /* sub ecx, 0 */
    if (c->zf) goto L_00b2d54a; /* je 0xb2d54a */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_00b2d53e; /* je 0xb2d53e */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_00b2d534; /* je 0xb2d534 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (!c->zf) goto L_00b2d54c; /* jne 0xb2d54c */
    { uint32_t a_ = (uint32_t)(c->esi + 0x1u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0xcu)))); } /* or byte ptr [esi + 1], 0xc */
    goto L_00b2d54c; /* jmp 0xb2d54c */
L_00b2d534:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) & (uint8_t)0xfbu))) << 8); /* and ch, 0xfb */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) | (uint8_t)0x8u))) << 8); /* or ch, 8 */
    goto L_00b2d546; /* jmp 0xb2d546 */
L_00b2d53e:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) & (uint8_t)0xf7u))) << 8); /* and ch, 0xf7 */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) | (uint8_t)0x4u))) << 8); /* or ch, 4 */
L_00b2d546:;
    W32((uint32_t)(c->esi), (uint32_t)(c->ecx)); /* mov dword ptr [esi], ecx */
    goto L_00b2d54c; /* jmp 0xb2d54c */
L_00b2d54a:;
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->edx)))); } /* and dword ptr [esi], edx */
L_00b2d54c:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x7u))); /* and ecx, 7 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x0u)); /* sub ecx, 0 */
    if (c->zf) goto L_00b2d56c; /* je 0xb2d56c */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_00b2d563; /* je 0xb2d563 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (!c->zf) goto L_00b2d575; /* jne 0xb2d575 */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->edx)))); } /* and dword ptr [esi], edx */
    goto L_00b2d575; /* jmp 0xb2d575 */
L_00b2d563:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & c->edx))); /* and ecx, edx */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) | (uint8_t)0x2u))) << 8); /* or ch, 2 */
    goto L_00b2d573; /* jmp 0xb2d573 */
L_00b2d56c:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & c->edx))); /* and ecx, edx */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) | (uint8_t)0x3u))) << 8); /* or ch, 3 */
L_00b2d573:;
    W32((uint32_t)(c->esi), (uint32_t)(c->ecx)); /* mov dword ptr [esi], ecx */
L_00b2d575:;
    FPUSH(c, RF64((uint32_t)(c->eax + 0x40u))); /* fld qword ptr [eax + 0x40] */
    WF64((uint32_t)(c->edi), ST(0)); FPOP(c); /* fstp qword ptr [edi] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00b2d57f(CPU *c) { /* FUN_1000d57f */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & (uint32_t)0x1fu))); /* and edi, 0x1f */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x8u)); /* test al, 8 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    if (c->zf) goto L_00b2d5aa; /* je 0xb2d5aa */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0x10u)) & ((uint8_t)c->ebx))); /* test byte ptr [ebp + 0x10], bl */
    if (c->zf) goto L_00b2d5aa; /* je 0xb2d5aa */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b2d5a1u); f_00b2d801(c); /* call 0xb2d801 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & (uint32_t)0xfffffff7u))); /* and edi, 0xfffffff7 */
    goto L_00b2d774; /* jmp 0xb2d774 */
L_00b2d5aa:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x4u)); /* test al, 4 */
    if (c->zf) goto L_00b2d5c4; /* je 0xb2d5c4 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0x10u)) & (uint8_t)0x4u)); /* test byte ptr [ebp + 0x10], 4 */
    if (c->zf) goto L_00b2d5c4; /* je 0xb2d5c4 */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    PUSH32(c, 0x00b2d5bbu); f_00b2d801(c); /* call 0xb2d801 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & (uint32_t)0xfffffffbu))); /* and edi, 0xfffffffb */
    goto L_00b2d774; /* jmp 0xb2d774 */
L_00b2d5c4:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & ((uint8_t)c->eax))); /* test bl, al */
    if (c->zf) goto L_00b2d69e; /* je 0xb2d69e */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0x10u)) & (uint8_t)0x8u)); /* test byte ptr [ebp + 0x10], 8 */
    if (c->zf) goto L_00b2d69e; /* je 0xb2d69e */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    PUSH32(c, 0x00b2d5ddu); f_00b2d801(c); /* call 0xb2d801 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)((uint32_t)0xc00u); /* mov eax, 0xc00 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & c->eax))); /* and ecx, eax */
    if (c->zf) goto L_00b2d676; /* je 0xb2d676 */
    (void)sub32(c, c->ecx, (uint32_t)0x400u); /* cmp ecx, 0x400 */
    if (c->zf) goto L_00b2d64e; /* je 0xb2d64e */
    (void)sub32(c, c->ecx, (uint32_t)0x800u); /* cmp ecx, 0x800 */
    if (c->zf) goto L_00b2d626; /* je 0xb2d626 */
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
    if (!c->zf) goto L_00b2d696; /* jne 0xb2d696 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    FPUSH(c, RF64((uint32_t)(c->ecx))); /* fld qword ptr [ecx] */
    FCOM(c, ST(0), RF64((uint32_t)(0xb2e3a8u))); FPOP(c); /* fcomp qword ptr [0x1000e3a8] */
    FPUSH(c, RF64((uint32_t)(0xb33160u))); /* fld qword ptr [0x10013160] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if ((!c->cf && !c->zf)) goto L_00b2d61e; /* ja 0xb2d61e */
    ST(0) = -ST(0); /* fchs  */
L_00b2d61e:;
    WF64((uint32_t)(c->ebp + 0xfffffff4u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0xc] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
    goto L_00b2d694; /* jmp 0xb2d694 */
L_00b2d626:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    FPUSH(c, RF64((uint32_t)(c->ecx))); /* fld qword ptr [ecx] */
    FCOM(c, ST(0), RF64((uint32_t)(0xb2e3a8u))); FPOP(c); /* fcomp qword ptr [0x1000e3a8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if ((c->cf || c->zf)) goto L_00b2d63e; /* jbe 0xb2d63e */
    FPUSH(c, RF64((uint32_t)(0xb33150u))); /* fld qword ptr [0x10013150] */
    goto L_00b2d646; /* jmp 0xb2d646 */
L_00b2d63e:;
    FPUSH(c, RF64((uint32_t)(0xb33160u))); /* fld qword ptr [0x10013160] */
    ST(0) = -ST(0); /* fchs  */
L_00b2d646:;
    WF64((uint32_t)(c->ebp + 0xfffffff4u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0xc] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
    goto L_00b2d694; /* jmp 0xb2d694 */
L_00b2d64e:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    FPUSH(c, RF64((uint32_t)(c->ecx))); /* fld qword ptr [ecx] */
    FCOM(c, ST(0), RF64((uint32_t)(0xb2e3a8u))); FPOP(c); /* fcomp qword ptr [0x1000e3a8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if ((c->cf || c->zf)) goto L_00b2d666; /* jbe 0xb2d666 */
    FPUSH(c, RF64((uint32_t)(0xb33160u))); /* fld qword ptr [0x10013160] */
    goto L_00b2d66e; /* jmp 0xb2d66e */
L_00b2d666:;
    FPUSH(c, RF64((uint32_t)(0xb33150u))); /* fld qword ptr [0x10013150] */
    ST(0) = -ST(0); /* fchs  */
L_00b2d66e:;
    WF64((uint32_t)(c->ebp + 0xfffffff4u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0xc] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
    goto L_00b2d694; /* jmp 0xb2d694 */
L_00b2d676:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    FPUSH(c, RF64((uint32_t)(c->ecx))); /* fld qword ptr [ecx] */
    FCOM(c, ST(0), RF64((uint32_t)(0xb2e3a8u))); FPOP(c); /* fcomp qword ptr [0x1000e3a8] */
    FPUSH(c, RF64((uint32_t)(0xb33150u))); /* fld qword ptr [0x10013150] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if ((!c->cf && !c->zf)) goto L_00b2d68e; /* ja 0xb2d68e */
    ST(0) = -ST(0); /* fchs  */
L_00b2d68e:;
    WF64((uint32_t)(c->ebp + 0xfffffff4u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0xc] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
L_00b2d694:;
    WF64((uint32_t)(c->ecx), ST(0)); FPOP(c); /* fstp qword ptr [ecx] */
L_00b2d696:;
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & (uint32_t)0xfffffffeu))); /* and edi, 0xfffffffe */
    goto L_00b2d774; /* jmp 0xb2d774 */
L_00b2d69e:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x2u)); /* test al, 2 */
    if (c->zf) goto L_00b2d774; /* je 0xb2d774 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0x10u)) & (uint8_t)0x10u)); /* test byte ptr [ebp + 0x10], 0x10 */
    if (c->zf) goto L_00b2d774; /* je 0xb2d774 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x10u)); /* test al, 0x10 */
    if (c->zf) goto L_00b2d6b9; /* je 0xb2d6b9 */
    c->esi = (uint32_t)(c->ebx); /* mov esi, ebx */
L_00b2d6b9:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    FPUSH(c, RF64((uint32_t)(c->eax))); /* fld qword ptr [eax] */
    WF64((uint32_t)(c->ebp + 0xfffffff4u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0xc] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
    FCOM(c, ST(0), RF64((uint32_t)(0xb2e3a8u))); FPOP(c); /* fcomp qword ptr [0x1000e3a8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (c->zf) goto L_00b2d762; /* je 0xb2d762 */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x00b2d6e4u); f_00b2da43(c); /* call 0xb2da43 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    WF64((uint32_t)(c->ebp + 0xfffffff4u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0xc] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0xfffffa00u)); /* lea ecx, [eax - 0x600] */
    (void)sub32(c, c->ecx, (uint32_t)0xfffffbceu); /* cmp ecx, 0xfffffbce */
    if ((c->sf == c->of)) goto L_00b2d704; /* jge 0xb2d704 */
    FPUSH(c, 0.0); /* fldz  */
    c->esi = (uint32_t)(c->ebx); /* mov esi, ebx */
    WF64((uint32_t)(c->ebp + 0xfffffff4u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0xc] */
    goto L_00b2d758; /* jmp 0xb2d758 */
L_00b2d704:;
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
    FCOM(c, ST(0), RF64((uint32_t)(0xb2e3a8u))); FPOP(c); /* fcomp qword ptr [0x1000e3a8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (!c->cf) goto L_00b2d716; /* jae 0xb2d716 */
    c->edx = (uint32_t)(c->ebx); /* mov edx, ebx */
    goto L_00b2d718; /* jmp 0xb2d718 */
L_00b2d716:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
L_00b2d718:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffau))); /* mov al, byte ptr [ebp - 6] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xfu))); /* and eax, 0xf */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x10u))); /* or al, 0x10 */
    W16((uint32_t)(c->ebp + 0xfffffffau), (uint16_t)(((uint16_t)c->eax))); /* mov word ptr [ebp - 6], ax */
    c->eax = (uint32_t)((uint32_t)0xfffffc03u); /* mov eax, 0xfffffc03 */
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
    if ((c->sf == c->of)) goto L_00b2d74c; /* jge 0xb2d74c */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
L_00b2d72f:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffff4u)) & ((uint8_t)c->ebx))); /* test byte ptr [ebp - 0xc], bl */
    if (c->zf) goto L_00b2d73a; /* je 0xb2d73a */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_00b2d73a; /* jne 0xb2d73a */
    c->esi = (uint32_t)(c->ebx); /* mov esi, ebx */
L_00b2d73a:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff4u); W32(a_, (uint32_t)(shr32(c, R32(a_), 1))); } /* shr dword ptr [ebp - 0xc], 1 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffff8u)) & ((uint8_t)c->ebx))); /* test byte ptr [ebp - 8], bl */
    if (c->zf) goto L_00b2d746; /* je 0xb2d746 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff7u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x80u)))); } /* or byte ptr [ebp - 9], 0x80 */
L_00b2d746:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(shr32(c, R32(a_), 1))); } /* shr dword ptr [ebp - 8], 1 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (!c->zf) goto L_00b2d72f; /* jne 0xb2d72f */
L_00b2d74c:;
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_00b2d758; /* je 0xb2d758 */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
    ST(0) = -ST(0); /* fchs  */
    WF64((uint32_t)(c->ebp + 0xfffffff4u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0xc] */
L_00b2d758:;
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    WF64((uint32_t)(c->eax), ST(0)); FPOP(c); /* fstp qword ptr [eax] */
    goto L_00b2d764; /* jmp 0xb2d764 */
L_00b2d762:;
    c->esi = (uint32_t)(c->ebx); /* mov esi, ebx */
L_00b2d764:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    if (c->zf) goto L_00b2d771; /* je 0xb2d771 */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    PUSH32(c, 0x00b2d770u); f_00b2d801(c); /* call 0xb2d801 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00b2d771:;
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & (uint32_t)0xfffffffdu))); /* and edi, 0xfffffffd */
L_00b2d774:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0x8u)) & (uint8_t)0x10u)); /* test byte ptr [ebp + 8], 0x10 */
    if (c->zf) goto L_00b2d78b; /* je 0xb2d78b */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0x10u)) & (uint8_t)0x20u)); /* test byte ptr [ebp + 0x10], 0x20 */
    if (c->zf) goto L_00b2d78b; /* je 0xb2d78b */
    { uint32_t v_ = 0x20u; PUSH32(c, v_); } /* push 0x20 */
    PUSH32(c, 0x00b2d787u); f_00b2d801(c); /* call 0xb2d801 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & (uint32_t)0xffffffefu))); /* and edi, 0xffffffef */
L_00b2d78b:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete al */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b2d796(CPU *c) { /* FUN_1000d796 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_00b2d7b2; /* je 0xb2d7b2 */
    if ((c->zf || c->sf != c->of)) goto L_00b2d7bd; /* jle 0xb2d7bd */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if ((!c->zf && c->sf == c->of)) goto L_00b2d7bd; /* jg 0xb2d7bd */
    PUSH32(c, 0x00b2d7abu); f_00b2d857(c); /* call 0xb2d857 */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x22u)); /* mov dword ptr [eax], 0x22 */
    c->esp += 4; return; /* ret  */
L_00b2d7b2:;
    PUSH32(c, 0x00b2d7b7u); f_00b2d857(c); /* call 0xb2d857 */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x21u)); /* mov dword ptr [eax], 0x21 */
L_00b2d7bd:;
    c->esp += 4; return; /* ret  */
}

void f_00b2d7be(CPU *c) { /* FUN_1000d7be */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_00b2d7c1(CPU *c) { /* FUN_1000d7c1 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    ; /* wait  */
    W16((uint32_t)(c->ebp + 0xfffffffeu), FNSTSW(c)); /* fnstsw word ptr [ebp - 2] */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int16_t)R16((uint32_t)(c->ebp + 0xfffffffeu))); /* movsx eax, word ptr [ebp - 2] */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b2d7cf(CPU *c) { /* FUN_1000d7cf */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    W16((uint32_t)(c->ebp + 0xfffffffeu), FNSTSW(c)); /* fnstsw word ptr [ebp - 2] */
    c->fpu_sw &= 0x7f00; /* fnclex  */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int16_t)R16((uint32_t)(c->ebp + 0xfffffffeu))); /* movsx eax, word ptr [ebp - 2] */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b2d7de(CPU *c) { /* FUN_1000d7de */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    ; /* wait  */
    W16((uint32_t)(c->ebp + 0xfffffffcu), c->fpu_cw); /* fnstcw word ptr [ebp - 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & R32((uint32_t)(c->ebp + 0x8u))))); /* and eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)((uint32_t)~c->ecx); /* not ecx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & R32((uint32_t)(c->ebp + 0xfffffffcu))))); /* and ecx, dword ptr [ebp - 4] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->eax))); /* or ecx, eax */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [ebp + 0xc], ecx */
    c->fpu_cw = R16((uint32_t)(c->ebp + 0xcu)); fpu_sync_rounding(c); /* fldcw word ptr [ebp + 0xc] */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int16_t)R16((uint32_t)(c->ebp + 0xfffffffcu))); /* movsx eax, word ptr [ebp - 4] */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b2d801(CPU *c) { /* FUN_1000d801 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0x8u))); /* mov cl, byte ptr [ebp + 8] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x1u)); /* test cl, 1 */
    if (c->zf) goto L_00b2d818; /* je 0xb2d818 */
    FPUSH(c, RF80((uint32_t)(0xb32d0cu))); /* fld xword ptr [0x10012d0c] */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)fpu_to_int32(c, ST(0))); FPOP(c); /* fistp dword ptr [ebp + 8] */
    ; /* wait  */
L_00b2d818:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x8u)); /* test cl, 8 */
    if (c->zf) goto L_00b2d82d; /* je 0xb2d82d */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    FPUSH(c, RF80((uint32_t)(0xb32d0cu))); /* fld xword ptr [0x10012d0c] */
    WF64((uint32_t)(c->ebp + 0xfffffff8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 8] */
    ; /* wait  */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
L_00b2d82d:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x10u)); /* test cl, 0x10 */
    if (c->zf) goto L_00b2d83c; /* je 0xb2d83c */
    FPUSH(c, RF80((uint32_t)(0xb32d18u))); /* fld xword ptr [0x10012d18] */
    WF64((uint32_t)(c->ebp + 0xfffffff8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 8] */
    ; /* wait  */
L_00b2d83c:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x4u)); /* test cl, 4 */
    if (c->zf) goto L_00b2d84a; /* je 0xb2d84a */
    FPUSH(c, 0.0); /* fldz  */
    FPUSH(c, 1.0); /* fld1  */
    ST(1) = FPRES(c, FDIV(c, ST(0), ST(1))); FPOP(c); /* fdivrp st(1) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    ; /* wait  */
L_00b2d84a:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x20u)); /* test cl, 0x20 */
    if (c->zf) goto L_00b2d855; /* je 0xb2d855 */
    FPUSH(c, M_PI); /* fldpi  */
    WF64((uint32_t)(c->ebp + 0xfffffff8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 8] */
    ; /* wait  */
L_00b2d855:;
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b2d857(CPU *c) { /* FUN_1000d857 */
    PREEMPT_POLL(c);
    PUSH32(c, 0x00b2d85cu); f_00b265a1(c); /* call 0xb265a1 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
    c->esp += 4; return; /* ret  */
}

void f_00b2d860(CPU *c) { /* FUN_1000d860 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, R32((uint32_t)(0xb3367cu)), c->ebx); /* cmp dword ptr [0x1001367c], ebx */
    if (!c->zf) goto L_00b2d87e; /* jne 0xb2d87e */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    (void)sub32(c, c->eax, (uint32_t)0x61u); /* cmp eax, 0x61 */
    if ((c->sf != c->of)) goto L_00b2d8cd; /* jl 0xb2d8cd */
    (void)sub32(c, c->eax, (uint32_t)0x7au); /* cmp eax, 0x7a */
    if ((!c->zf && c->sf == c->of)) goto L_00b2d8cd; /* jg 0xb2d8cd */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x20u)); /* sub eax, 0x20 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_00b2d87e:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)((uint32_t)0xb337e4u); /* mov esi, 0x100137e4 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(0xb2e0c4u)); PUSH32(c, 0x00b2d88cu); call_indirect(c, t_); } /* call dword ptr [0x1000e0c4] */
    (void)sub32(c, R32((uint32_t)(0xb337e0u)), c->ebx); /* cmp dword ptr [0x100137e0], ebx */
    c->edi = (uint32_t)(R32((uint32_t)(0xb2e0c0u))); /* mov edi, dword ptr [0x1000e0c0] */
    if (c->zf) goto L_00b2d8a8; /* je 0xb2d8a8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00b2d89du); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x00b2d8a4u); f_00b27565(c); /* call 0xb27565 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
L_00b2d8a8:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    PUSH32(c, 0x00b2d8b1u); f_00b2d8cf(c); /* call 0xb2d8cf */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    if (c->zf) goto L_00b2d8c4; /* je 0xb2d8c4 */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x00b2d8c1u); f_00b275c6(c); /* call 0xb275c6 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00b2d8c7; /* jmp 0xb2d8c7 */
L_00b2d8c4:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00b2d8c7u); call_indirect(c, t_); } /* call edi */
L_00b2d8c7:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00b2d8cd:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00b2d8cf(CPU *c) { /* FUN_1000d8cf */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    (void)sub32(c, R32((uint32_t)(0xb3367cu)), (uint32_t)0x0u); /* cmp dword ptr [0x1001367c], 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    if (!c->zf) goto L_00b2d8fa; /* jne 0xb2d8fa */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)sub32(c, c->eax, (uint32_t)0x61u); /* cmp eax, 0x61 */
    if ((c->sf != c->of)) goto L_00b2d998; /* jl 0xb2d998 */
    (void)sub32(c, c->eax, (uint32_t)0x7au); /* cmp eax, 0x7a */
    if ((!c->zf && c->sf == c->of)) goto L_00b2d998; /* jg 0xb2d998 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x20u)); /* sub eax, 0x20 */
    goto L_00b2d998; /* jmp 0xb2d998 */
L_00b2d8fa:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    (void)sub32(c, c->ebx, (uint32_t)0x100u); /* cmp ebx, 0x100 */
    if ((c->sf == c->of)) goto L_00b2d92d; /* jge 0xb2d92d */
    (void)sub32(c, R32((uint32_t)(0xb3060cu)), (uint32_t)0x1u); /* cmp dword ptr [0x1001060c], 1 */
    if ((c->zf || c->sf != c->of)) goto L_00b2d91a; /* jle 0xb2d91a */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b2d916u); f_00b26edb(c); /* call 0xb26edb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00b2d925; /* jmp 0xb2d925 */
L_00b2d91a:;
    c->eax = (uint32_t)(R32((uint32_t)(0xb30400u))); /* mov eax, dword ptr [0x10010400] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + c->ebx * 2))); /* mov al, byte ptr [eax + ebx*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x2u))); /* and eax, 2 */
L_00b2d925:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00b2d92d; /* jne 0xb2d92d */
L_00b2d929:;
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    goto L_00b2d998; /* jmp 0xb2d998 */
L_00b2d92d:;
    c->edx = (uint32_t)(R32((uint32_t)(0xb30400u))); /* mov edx, dword ptr [0x10010400] */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->eax = (uint32_t)(sar32(c, c->eax, 8)); /* sar eax, 8 */
    c->ecx = (uint32_t)((uint32_t)((uint8_t)c->eax)); /* movzx ecx, al */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edx + c->ecx * 2 + 0x1u)) & (uint8_t)0x80u)); /* test byte ptr [edx + ecx*2 + 1], 0x80 */
    if (c->zf) goto L_00b2d950; /* je 0xb2d950 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xau); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp + 0xa], 0 */
    W8((uint32_t)(c->ebp + 0x8u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp + 8], al */
    W8((uint32_t)(c->ebp + 0x9u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ebp + 9], bl */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    goto L_00b2d959; /* jmp 0xb2d959 */
L_00b2d950:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0x9u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp + 9], 0 */
    W8((uint32_t)(c->ebp + 0x8u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ebp + 8], bl */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
L_00b2d959:;
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea ecx, [ebp - 4] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x8u)); /* lea eax, [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x200u; PUSH32(c, v_); } /* push 0x200 */
    { uint32_t v_ = R32((uint32_t)(0xb3367cu)); PUSH32(c, v_); } /* push dword ptr [0x1001367c] */
    PUSH32(c, 0x00b2d979u); f_00b2cdea(c); /* call 0xb2cdea */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00b2d929; /* je 0xb2d929 */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_00b2d98b; /* jne 0xb2d98b */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0xfffffffcu))); /* movzx eax, byte ptr [ebp - 4] */
    goto L_00b2d998; /* jmp 0xb2d998 */
L_00b2d98b:;
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0xfffffffdu))); /* movzx eax, byte ptr [ebp - 3] */
    c->ecx = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0xfffffffcu))); /* movzx ecx, byte ptr [ebp - 4] */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->ecx))); /* or eax, ecx */
L_00b2d998:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b2d9a0(CPU *c) { /* FUN_1000d9a0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
    c->ecx = (uint32_t)((uint32_t)(c->ecx)); /* lea ecx, [ecx] */
L_00b2d9b4:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov al, byte ptr [edx] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00b2d9c1; /* je 0xb2d9c1 */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    { int32_t b_ = (int32_t)(c->eax); uint32_t a_ = (uint32_t)(c->esp) + (uint32_t)((b_ >> 3) & ~3); unsigned k_ = b_ & 31; uint32_t v_ = R32(a_); c->cf = (v_ >> k_) & 1; W32(a_, v_ | (1u << k_)); } /* bts dword ptr [esp], eax */
    goto L_00b2d9b4; /* jmp 0xb2d9b4 */
L_00b2d9c1:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0xffffffffu))); /* or ecx, 0xffffffff */
    ; /* nop  */
L_00b2d9c8:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00b2d9d6; /* je 0xb2d9d6 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    { int32_t b_ = (int32_t)(c->eax); uint32_t a_ = (uint32_t)(c->esp) + (uint32_t)((b_ >> 3) & ~3); unsigned k_ = b_ & 31; uint32_t v_ = R32(a_); c->cf = (v_ >> k_) & 1; } /* bt dword ptr [esp], eax */
    if (!c->cf) goto L_00b2d9c8; /* jae 0xb2d9c8 */
L_00b2d9d6:;
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b2d9e0(CPU *c) { /* FUN_1000d9e0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
    c->ecx = (uint32_t)((uint32_t)(c->ecx)); /* lea ecx, [ecx] */
L_00b2d9f4:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov al, byte ptr [edx] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00b2da01; /* je 0xb2da01 */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    { int32_t b_ = (int32_t)(c->eax); uint32_t a_ = (uint32_t)(c->esp) + (uint32_t)((b_ >> 3) & ~3); unsigned k_ = b_ & 31; uint32_t v_ = R32(a_); c->cf = (v_ >> k_) & 1; W32(a_, v_ | (1u << k_)); } /* bts dword ptr [esp], eax */
    goto L_00b2d9f4; /* jmp 0xb2d9f4 */
L_00b2da01:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
L_00b2da04:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00b2da14; /* je 0xb2da14 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    { int32_t b_ = (int32_t)(c->eax); uint32_t a_ = (uint32_t)(c->esp) + (uint32_t)((b_ >> 3) & ~3); unsigned k_ = b_ & 31; uint32_t v_ = R32(a_); c->cf = (v_ >> k_) & 1; } /* bt dword ptr [esp], eax */
    if (!c->cf) goto L_00b2da04; /* jae 0xb2da04 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0xffffffffu)); /* lea eax, [esi - 1] */
L_00b2da14:;
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b2da1a(CPU *c) { /* FUN_1000da1a */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xeu))); /* mov ecx, dword ptr [ebp + 0xe] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x3feu)); /* add eax, 0x3fe */
    c->ecx = (c->ecx & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->ecx) & (uint16_t)0x800fu))); /* and cx, 0x800f */
    WF64((uint32_t)(c->ebp + 0xfffffff8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 8] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->ecx))); /* or eax, ecx */
    W16((uint32_t)(c->ebp + 0xfffffffeu), (uint16_t)(((uint16_t)c->eax))); /* mov word ptr [ebp - 2], ax */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff8u))); /* fld qword ptr [ebp - 8] */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b2da43(CPU *c) { /* FUN_1000da43 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    FCOM(c, ST(0), RF64((uint32_t)(0xb2e3a8u))); FPOP(c); /* fcomp qword ptr [0x1000e3a8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (!c->zf) goto L_00b2da63; /* jne 0xb2da63 */
    FPUSH(c, 0.0); /* fldz  */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    WF64((uint32_t)(c->ebp + 0xfffffff8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 8] */
    goto L_00b2daf9; /* jmp 0xb2daf9 */
L_00b2da63:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)logic16(c, (uint16_t)(R16((uint32_t)(c->ebp + 0xeu)) & (uint16_t)0x7ff0u)); /* test word ptr [ebp + 0xe], 0x7ff0 */
    if (!c->zf) goto L_00b2dad2; /* jne 0xb2dad2 */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->ebp + 0xcu)) & (uint32_t)0xfffffu)); /* test dword ptr [ebp + 0xc], 0xfffff */
    if (!c->zf) goto L_00b2da7b; /* jne 0xb2da7b */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), c->ecx); /* cmp dword ptr [ebp + 8], ecx */
    if (c->zf) goto L_00b2dad2; /* je 0xb2dad2 */
L_00b2da7b:;
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    FCOM(c, ST(0), RF64((uint32_t)(0xb2e3a8u))); FPOP(c); /* fcomp qword ptr [0x1000e3a8] */
    c->esi = (uint32_t)((uint32_t)0xfffffc03u); /* mov esi, 0xfffffc03 */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (!c->cf) goto L_00b2da93; /* jae 0xb2da93 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_00b2da95; /* jmp 0xb2da95 */
L_00b2da93:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00b2da95:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xeu)) & (uint8_t)0x10u)); /* test byte ptr [ebp + 0xe], 0x10 */
    if (!c->zf) goto L_00b2daae; /* jne 0xb2daae */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(shl32(c, R32(a_), 1))); } /* shl dword ptr [ebp + 0xc], 1 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xbu)) & (uint8_t)0x80u)); /* test byte ptr [ebp + 0xb], 0x80 */
    if (c->zf) goto L_00b2daa8; /* je 0xb2daa8 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x1u)))); } /* or dword ptr [ebp + 0xc], 1 */
L_00b2daa8:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(shl32(c, R32(a_), 1))); } /* shl dword ptr [ebp + 8], 1 */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    goto L_00b2da95; /* jmp 0xb2da95 */
L_00b2daae:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xeu); W16(a_, (uint16_t)(logic16(c, (uint16_t)(R16(a_) & (uint16_t)0xffefu)))); } /* and word ptr [ebp + 0xe], 0xffef */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (c->zf) goto L_00b2dabc; /* je 0xb2dabc */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x80u)))); } /* or byte ptr [ebp + 0xf], 0x80 */
L_00b2dabc:;
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x00b2dacau); f_00b2da1a(c); /* call 0xb2da1a */
    WF64((uint32_t)(c->ebp + 0xfffffff8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 8] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_00b2daf9; /* jmp 0xb2daf9 */
L_00b2dad2:;
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x00b2dae0u); f_00b2da1a(c); /* call 0xb2da1a */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xeu))); /* mov eax, dword ptr [ebp + 0xe] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    WF64((uint32_t)(c->ebp + 0xfffffff8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 8] */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->eax) & (uint16_t)0x7ffu))); /* and ax, 0x7ff */
    c->esi = (uint32_t)((uint32_t)(int32_t)(int16_t)((uint16_t)c->eax)); /* movsx esi, ax */
    c->esi = (uint32_t)(sub32(c, c->esi, (uint32_t)0x3feu)); /* sub esi, 0x3fe */
L_00b2daf9:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff8u))); /* fld qword ptr [ebp - 8] */
    W32((uint32_t)(c->eax), (uint32_t)(c->esi)); /* mov dword ptr [eax], esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b2db10(CPU *c) { /* FUN_1000db10 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    c->eax = (uint32_t)((uint32_t)(0xb33674u)); /* lea eax, [0x10013674] */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [eax + 8], 0 */
    if (!c->zf) goto L_00b2db63; /* jne 0xb2db63 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0xffu); /* mov al, 0xff */
    c->edi = (uint32_t)(c->edi); /* mov edi, edi */
L_00b2db2c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00b2db5e; /* je 0xb2db5e */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->edi))) << 8); /* mov ah, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->eax)); /* cmp ah, al */
    if (c->zf) goto L_00b2db2c; /* je 0xb2db2c */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sub8(c, ((uint8_t)c->eax), (uint8_t)0x41u)); /* sub al, 0x41 */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x1au); /* cmp al, 0x1a */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(sbb8(c, ((uint8_t)c->ecx), ((uint8_t)c->ecx))); /* sbb cl, cl */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x20u))); /* and cl, 0x20 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(add8(c, ((uint8_t)c->eax), ((uint8_t)c->ecx))); /* add al, cl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(add8(c, ((uint8_t)c->eax), (uint8_t)0x41u)); /* add al, 0x41 */
    { uint8_t t0_ = ((uint8_t)c->eax), t1_ = ((uint8_t)(c->eax >> 8)); c->eax = (c->eax & 0xffffff00u) | (uint8_t)(t1_); c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(t0_) << 8); } /* xchg al, ah */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sub8(c, ((uint8_t)c->eax), (uint8_t)0x41u)); /* sub al, 0x41 */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x1au); /* cmp al, 0x1a */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(sbb8(c, ((uint8_t)c->ecx), ((uint8_t)c->ecx))); /* sbb cl, cl */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x20u))); /* and cl, 0x20 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(add8(c, ((uint8_t)c->eax), ((uint8_t)c->ecx))); /* add al, cl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(add8(c, ((uint8_t)c->eax), (uint8_t)0x41u)); /* add al, 0x41 */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)(c->eax >> 8))); /* cmp al, ah */
    if (c->zf) goto L_00b2db2c; /* je 0xb2db2c */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sbb8(c, ((uint8_t)c->eax), ((uint8_t)c->eax))); /* sbb al, al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sbb8(c, ((uint8_t)c->eax), (uint8_t)0xffu)); /* sbb al, 0xff */
L_00b2db5e:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->eax)); /* movsx eax, al */
    goto L_00b2dbdb; /* jmp 0xb2dbdb */
L_00b2db63:;
    { guest_lock(); guest_trap(c, 0x00b2db63u, "unsupported: lock inc dword ptr [0x100137e4]"); guest_unlock(); } /* lock inc dword ptr [0x100137e4] */
    (void)sub32(c, R32((uint32_t)(0xb337e0u)), (uint32_t)0x0u); /* cmp dword ptr [0x100137e0], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_00b2db77; /* jg 0xb2db77 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    goto L_00b2db8c; /* jmp 0xb2db8c */
L_00b2db77:;
    { guest_lock(); guest_trap(c, 0x00b2db77u, "unsupported: lock dec dword ptr [0x100137e4]"); guest_unlock(); } /* lock dec dword ptr [0x100137e4] */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x00b2db85u); f_00b27565(c); /* call 0xb27565 */
    W32((uint32_t)(c->esp), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [esp], 1 */
L_00b2db8c:;
    c->eax = (uint32_t)((uint32_t)0xffu); /* mov eax, 0xff */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    ; /* nop  */
L_00b2db94:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00b2dbbf; /* je 0xb2dbbf */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_00b2db94; /* je 0xb2db94 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b2dba9u); f_00b2ba00(c); /* call 0xb2ba00 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    PUSH32(c, 0x00b2dbb3u); f_00b2ba00(c); /* call 0xb2ba00 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    (void)sub8(c, ((uint8_t)c->ebx), ((uint8_t)c->eax)); /* cmp bl, al */
    if (c->zf) goto L_00b2db94; /* je 0xb2db94 */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, (uint32_t)0xffffffffu)); /* sbb eax, -1 */
L_00b2dbbf:;
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->eax))); /* or eax, eax */
    if (!c->zf) goto L_00b2dbcf; /* jne 0xb2dbcf */
    { guest_lock(); guest_trap(c, 0x00b2dbc6u, "unsupported: lock dec dword ptr [0x100137e4]"); guest_unlock(); } /* lock dec dword ptr [0x100137e4] */
    goto L_00b2dbd9; /* jmp 0xb2dbd9 */
L_00b2dbcf:;
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x00b2dbd6u); f_00b275c6(c); /* call 0xb275c6 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00b2dbd9:;
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
L_00b2dbdb:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b2dbe0(CPU *c) { /* FUN_1000dbe0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->ecx))); /* or ecx, ecx */
    if (c->zf) goto L_00b2dcda; /* je 0xb2dcda */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)((uint32_t)(0xb33674u)); /* lea eax, [0x10013674] */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [eax + 8], 0 */
    if (!c->zf) goto L_00b2dc51; /* jne 0xb2dc51 */
    c->ebx = (c->ebx & 0xffff00ffu) | ((uint32_t)(uint8_t)((uint8_t)0x41u) << 8); /* mov bh, 0x41 */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)((uint8_t)0x5au); /* mov bl, 0x5a */
    c->edx = (c->edx & 0xffff00ffu) | ((uint32_t)(uint8_t)((uint8_t)0x20u) << 8); /* mov dh, 0x20 */
    c->ecx = (uint32_t)((uint32_t)(c->ecx)); /* lea ecx, [ecx] */
L_00b2dc0c:;
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->esi))) << 8); /* mov ah, byte ptr [esi] */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | ((uint8_t)(c->eax >> 8))))) << 8); /* or ah, ah */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov al, byte ptr [edi] */
    if (c->zf) goto L_00b2dc35; /* je 0xb2dc35 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00b2dc35; /* je 0xb2dc35 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)(c->ebx >> 8))); /* cmp ah, bh */
    if (c->cf) goto L_00b2dc24; /* jb 0xb2dc24 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->ebx)); /* cmp ah, bl */
    if ((!c->cf && !c->zf)) goto L_00b2dc24; /* ja 0xb2dc24 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(add8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)(c->edx >> 8)))) << 8); /* add ah, dh */
L_00b2dc24:;
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)(c->ebx >> 8))); /* cmp al, bh */
    if (c->cf) goto L_00b2dc2e; /* jb 0xb2dc2e */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if ((!c->cf && !c->zf)) goto L_00b2dc2e; /* ja 0xb2dc2e */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(add8(c, ((uint8_t)c->eax), ((uint8_t)(c->edx >> 8)))); /* add al, dh */
L_00b2dc2e:;
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->eax)); /* cmp ah, al */
    if (!c->zf) goto L_00b2dc3f; /* jne 0xb2dc3f */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (!c->zf) goto L_00b2dc0c; /* jne 0xb2dc0c */
L_00b2dc35:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->eax)); /* cmp ah, al */
    if (c->zf) goto L_00b2dcda; /* je 0xb2dcda */
L_00b2dc3f:;
    c->ecx = (uint32_t)((uint32_t)0xffffffffu); /* mov ecx, 0xffffffff */
    if (c->cf) goto L_00b2dcda; /* jb 0xb2dcda */
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
    goto L_00b2dcda; /* jmp 0xb2dcda */
L_00b2dc51:;
    { guest_lock(); guest_trap(c, 0x00b2dc51u, "unsupported: lock inc dword ptr [0x100137e4]"); guest_unlock(); } /* lock inc dword ptr [0x100137e4] */
    (void)sub32(c, R32((uint32_t)(0xb337e0u)), (uint32_t)0x0u); /* cmp dword ptr [0x100137e0], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_00b2dc65; /* jg 0xb2dc65 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    goto L_00b2dc7e; /* jmp 0xb2dc7e */
L_00b2dc65:;
    { guest_lock(); guest_trap(c, 0x00b2dc65u, "unsupported: lock dec dword ptr [0x100137e4]"); guest_unlock(); } /* lock dec dword ptr [0x100137e4] */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x00b2dc75u); f_00b27565(c); /* call 0xb27565 */
    W32((uint32_t)(c->esp), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [esp], 1 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
L_00b2dc7e:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->edi = (uint32_t)(c->edi); /* mov edi, edi */
L_00b2dc84:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->eax))); /* or eax, eax */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    if (c->zf) goto L_00b2dcaf; /* je 0xb2dcaf */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | c->ebx))); /* or ebx, ebx */
    if (c->zf) goto L_00b2dcaf; /* je 0xb2dcaf */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00b2dc9au); f_00b2ba00(c); /* call 0xb2ba00 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    PUSH32(c, 0x00b2dca4u); f_00b2ba00(c); /* call 0xb2ba00 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (!c->zf) goto L_00b2dcb5; /* jne 0xb2dcb5 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (!c->zf) goto L_00b2dc84; /* jne 0xb2dc84 */
L_00b2dcaf:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_00b2dcbe; /* je 0xb2dcbe */
L_00b2dcb5:;
    c->ecx = (uint32_t)((uint32_t)0xffffffffu); /* mov ecx, 0xffffffff */
    if (c->cf) goto L_00b2dcbe; /* jb 0xb2dcbe */
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
L_00b2dcbe:;
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->eax))); /* or eax, eax */
    if (!c->zf) goto L_00b2dccc; /* jne 0xb2dccc */
    { guest_lock(); guest_trap(c, 0x00b2dcc3u, "unsupported: lock dec dword ptr [0x100137e4]"); guest_unlock(); } /* lock dec dword ptr [0x100137e4] */
    goto L_00b2dcda; /* jmp 0xb2dcda */
L_00b2dccc:;
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x00b2dcd5u); f_00b275c6(c); /* call 0xb275c6 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
L_00b2dcda:;
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00b2dcf0(CPU *c) { /* PTR_00b2dcf0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->eax))); /* or eax, eax */
    if (!c->zf) goto L_00b2dd12; /* jne 0xb2dd12 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ecx, dword ptr [esp + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    { uint32_t d_ = c->ecx; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x00b2dd04u, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div ecx */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    { uint32_t d_ = c->ecx; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x00b2dd0cu, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div ecx */
    c->edx = (uint32_t)(c->ebx); /* mov edx, ebx */
    goto L_00b2dd53; /* jmp 0xb2dd53 */
L_00b2dd12:;
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ebx, dword ptr [esp + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
L_00b2dd20:;
    c->ecx = (uint32_t)(shr32(c, c->ecx, 1)); /* shr ecx, 1 */
    c->ebx = (uint32_t)(rcr32(c, c->ebx, 1)); /* rcr ebx, 1 */
    c->edx = (uint32_t)(shr32(c, c->edx, 1)); /* shr edx, 1 */
    c->eax = (uint32_t)(rcr32(c, c->eax, 1)); /* rcr eax, 1 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->ecx))); /* or ecx, ecx */
    if (!c->zf) goto L_00b2dd20; /* jne 0xb2dd20 */
    { uint32_t d_ = c->ebx; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x00b2dd2cu, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div ebx */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint64_t r_ = (uint64_t)c->eax * R32((uint32_t)(c->esp + 0x18u)); c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = c->edx != 0; } /* mul dword ptr [esp + 0x18] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    { uint64_t r_ = (uint64_t)c->eax * c->esi; c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = c->edx != 0; } /* mul esi */
    c->edx = (uint32_t)(add32(c, c->edx, c->ecx)); /* add edx, ecx */
    if (c->cf) goto L_00b2dd4e; /* jb 0xb2dd4e */
    (void)sub32(c, c->edx, R32((uint32_t)(c->esp + 0x10u))); /* cmp edx, dword ptr [esp + 0x10] */
    if ((!c->cf && !c->zf)) goto L_00b2dd4e; /* ja 0xb2dd4e */
    if (c->cf) goto L_00b2dd4f; /* jb 0xb2dd4f */
    (void)sub32(c, c->eax, R32((uint32_t)(c->esp + 0xcu))); /* cmp eax, dword ptr [esp + 0xc] */
    if ((c->cf || c->zf)) goto L_00b2dd4f; /* jbe 0xb2dd4f */
L_00b2dd4e:;
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
L_00b2dd4f:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00b2dd53:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 20; return; /* ret 0x10 */
}

void f_00b2dd60(CPU *c) { /* PTR_00b2dd60 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->eax))); /* or eax, eax */
    if (!c->zf) goto L_00b2dd81; /* jne 0xb2dd81 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    { uint32_t d_ = c->ecx; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x00b2dd73u, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t d_ = c->ecx; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x00b2dd79u, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div ecx */
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    goto L_00b2ddd1; /* jmp 0xb2ddd1 */
L_00b2dd81:;
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ebx, dword ptr [esp + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
L_00b2dd8f:;
    c->ecx = (uint32_t)(shr32(c, c->ecx, 1)); /* shr ecx, 1 */
    c->ebx = (uint32_t)(rcr32(c, c->ebx, 1)); /* rcr ebx, 1 */
    c->edx = (uint32_t)(shr32(c, c->edx, 1)); /* shr edx, 1 */
    c->eax = (uint32_t)(rcr32(c, c->eax, 1)); /* rcr eax, 1 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->ecx))); /* or ecx, ecx */
    if (!c->zf) goto L_00b2dd8f; /* jne 0xb2dd8f */
    { uint32_t d_ = c->ebx; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x00b2dd9bu, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div ebx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint64_t r_ = (uint64_t)c->eax * R32((uint32_t)(c->esp + 0x14u)); c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = c->edx != 0; } /* mul dword ptr [esp + 0x14] */
    { uint32_t t0_ = c->ecx, t1_ = c->eax; c->ecx = (uint32_t)(t1_); c->eax = (uint32_t)(t0_); } /* xchg ecx, eax */
    { uint64_t r_ = (uint64_t)c->eax * R32((uint32_t)(c->esp + 0x10u)); c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = c->edx != 0; } /* mul dword ptr [esp + 0x10] */
    c->edx = (uint32_t)(add32(c, c->edx, c->ecx)); /* add edx, ecx */
    if (c->cf) goto L_00b2ddba; /* jb 0xb2ddba */
    (void)sub32(c, c->edx, R32((uint32_t)(c->esp + 0xcu))); /* cmp edx, dword ptr [esp + 0xc] */
    if ((!c->cf && !c->zf)) goto L_00b2ddba; /* ja 0xb2ddba */
    if (c->cf) goto L_00b2ddc2; /* jb 0xb2ddc2 */
    (void)sub32(c, c->eax, R32((uint32_t)(c->esp + 0x8u))); /* cmp eax, dword ptr [esp + 8] */
    if ((c->cf || c->zf)) goto L_00b2ddc2; /* jbe 0xb2ddc2 */
L_00b2ddba:;
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->esp + 0x10u)))); /* sub eax, dword ptr [esp + 0x10] */
    c->edx = (uint32_t)(sbb32(c, c->edx, R32((uint32_t)(c->esp + 0x14u)))); /* sbb edx, dword ptr [esp + 0x14] */
L_00b2ddc2:;
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->esp + 0x8u)))); /* sub eax, dword ptr [esp + 8] */
    c->edx = (uint32_t)(sbb32(c, c->edx, R32((uint32_t)(c->esp + 0xcu)))); /* sbb edx, dword ptr [esp + 0xc] */
    c->edx = (uint32_t)(neg32(c, c->edx)); /* neg edx */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->edx = (uint32_t)(sbb32(c, c->edx, (uint32_t)0x0u)); /* sbb edx, 0 */
L_00b2ddd1:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 20; return; /* ret 0x10 */
}

void f_00b2dde0(CPU *c) { /* PTR_00b2dde0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->eax))); /* or ecx, eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    if (!c->zf) goto L_00b2ddf9; /* jne 0xb2ddf9 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint64_t r_ = (uint64_t)c->eax * c->ecx; c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = c->edx != 0; } /* mul ecx */
    c->esp += 20; return; /* ret 0x10 */
L_00b2ddf9:;
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

void f_00b2de20(CPU *c) { /* KERNEL32.DLL::RtlUnwind */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(0xb2e000u)); switch (t_) {  default: jump_indirect(c, t_, 0x00b2de20u); return; } } /* jmp dword ptr [0x1000e000] */
}

void f_00b2de30(CPU *c) { /* Unwind@1000de30 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xbu; PUSH32(c, v_); } /* push 0xb */
    { uint32_t v_ = 0xb30048u; PUSH32(c, v_); } /* push 0x10010048 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2de40u); f_00b21030(c); /* call 0xb21030 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b2de44(CPU *c) { /* PTR_00b2de44 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb2ea24u); /* mov eax, 0x1000ea24 */
    { f_00b25401(c); return; } /* jmp 0xb25401 */
}

void f_00b2de50(CPU *c) { /* Unwind@1000de50 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd4u))); /* mov ecx, dword ptr [ebp - 0x2c] */
    { f_00b21530(c); return; } /* jmp 0xb21530 */
}

void f_00b2de58(CPU *c) { /* Unwind@1000de58 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    { uint32_t v_ = 0xb30048u; PUSH32(c, v_); } /* push 0x10010048 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2de68u); f_00b21030(c); /* call 0xb21030 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b2de6c(CPU *c) { /* Unwind@1000de6c */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x15u; PUSH32(c, v_); } /* push 0x15 */
    { uint32_t v_ = 0xb30048u; PUSH32(c, v_); } /* push 0x10010048 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2de7cu); f_00b21030(c); /* call 0xb21030 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b2de80(CPU *c) { /* Unwind@1000de80 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x16u; PUSH32(c, v_); } /* push 0x16 */
    { uint32_t v_ = 0xb30048u; PUSH32(c, v_); } /* push 0x10010048 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2de90u); f_00b21030(c); /* call 0xb21030 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b2de94(CPU *c) { /* PTR_00b2de94 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb2ea60u); /* mov eax, 0x1000ea60 */
    { f_00b25401(c); return; } /* jmp 0xb25401 */
}

void f_00b2dea0(CPU *c) { /* Unwind@1000dea0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_00b21530(c); return; } /* jmp 0xb21530 */
}

void f_00b2dea8(CPU *c) { /* PTR_00b2dea8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb2ea84u); /* mov eax, 0x1000ea84 */
    { f_00b25401(c); return; } /* jmp 0xb25401 */
}

void f_00b2dec0(CPU *c) { /* Unwind@1000dec0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xb21e10u; PUSH32(c, v_); } /* push 0x10001e10 */
    { uint32_t v_ = 0xc8u; PUSH32(c, v_); } /* push 0xc8 */
    { uint32_t v_ = 0x64u; PUSH32(c, v_); } /* push 0x64 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x2cu)); /* add eax, 0x2c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2ded8u); f_00b25950(c); /* call 0xb25950 */
    c->esp += 4; return; /* ret  */
}

void f_00b2ded9(CPU *c) { /* PTR_00b2ded9 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb2eaa8u); /* mov eax, 0x1000eaa8 */
    { f_00b25401(c); return; } /* jmp 0xb25401 */
}

void f_00b2def0(CPU *c) { /* Unwind@1000def0 */
    PREEMPT_POLL(c);
    goto L_00b2def0;
L_00b21da0:;
    c->esp += 4; return; /* ret  */
L_00b2def0:;
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    goto L_00b21da0; /* jmp 0xb21da0 */
}

void f_00b2defb(CPU *c) { /* Unwind@1000defb */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00b21da0(c); return; } /* jmp 0xb21da0 */
}

void f_00b2df06(CPU *c) { /* Unwind@1000df06 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x3bu; PUSH32(c, v_); } /* push 0x3b */
    { uint32_t v_ = 0xb30180u; PUSH32(c, v_); } /* push 0x10010180 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffda0u))); /* mov eax, dword ptr [ebp - 0x260] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2df19u); f_00b21030(c); /* call 0xb21030 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b2df1d(CPU *c) { /* PTR_00b2df1d */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb2eb10u); /* mov eax, 0x1000eb10 */
    { f_00b25401(c); return; } /* jmp 0xb25401 */
}

void f_00b2df30(CPU *c) { /* Unwind@1000df30 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_00b23cf0(c); return; } /* jmp 0xb23cf0 */
}

void f_00b2df38(CPU *c) { /* PTR_00b2df38 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb2eb34u); /* mov eax, 0x1000eb34 */
    { f_00b25401(c); return; } /* jmp 0xb25401 */
}

void f_00b2df50(CPU *c) { /* Unwind@1000df50 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_00b23cf0(c); return; } /* jmp 0xb23cf0 */
}

void f_00b2df58(CPU *c) { /* Unwind@1000df58 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x7f8u)); /* add ecx, 0x7f8 */
    { f_00b23710(c); return; } /* jmp 0xb23710 */
}

void f_00b2df66(CPU *c) { /* PTR_00b2df66 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb2eb60u); /* mov eax, 0x1000eb60 */
    { f_00b25401(c); return; } /* jmp 0xb25401 */
}

void f_00b2df70(CPU *c) { /* Unwind@1000df70 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00b21da0(c); return; } /* jmp 0xb21da0 */
}

void f_00b2df7b(CPU *c) { /* Unwind@1000df7b */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x3au; PUSH32(c, v_); } /* push 0x3a */
    { uint32_t v_ = 0xb3021cu; PUSH32(c, v_); } /* push 0x1001021c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffda0u))); /* mov eax, dword ptr [ebp - 0x260] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00b2df8eu); f_00b21030(c); /* call 0xb21030 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00b2df92(CPU *c) { /* PTR_00b2df92 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb2eb8cu); /* mov eax, 0x1000eb8c */
    { f_00b25401(c); return; } /* jmp 0xb25401 */
}

void f_00b2dfa0(CPU *c) { /* Unwind@1000dfa0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_00b21da0(c); return; } /* jmp 0xb21da0 */
}

void f_00b2dfab(CPU *c) { /* PTR_00b2dfab */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xb2ebb0u); /* mov eax, 0x1000ebb0 */
    { f_00b25401(c); return; } /* jmp 0xb25401 */
}
