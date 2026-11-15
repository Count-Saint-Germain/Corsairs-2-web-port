#include "recomp.h"

void f_008074d6(CPU *c) { /* FUN_100374d6 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008074e1u); f_00807504(c); /* call 0x807504 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_008074eb; /* je 0x8074eb */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_008074eb:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi + 0xdu)) & (uint8_t)0x40u)); /* test byte ptr [esi + 0xd], 0x40 */
    if (c->zf) goto L_00807500; /* je 0x807500 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x10] */
    PUSH32(c, 0x008074f9u); f_00807ae7(c); /* call 0x807ae7 */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->esp += 4; return; /* ret  */
L_00807500:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00807504(CPU *c) { /* FUN_10037504 */
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
    if (!c->zf) goto L_00807551; /* jne 0x807551 */
    (void)logic16(c, (uint16_t)(((uint16_t)c->eax) & (uint16_t)0x108u)); /* test ax, 0x108 */
    if (c->zf) goto L_00807551; /* je 0x807551 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edi, dword ptr [esi] */
    c->edi = (uint32_t)(sub32(c, c->edi, c->eax)); /* sub edi, eax */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if ((c->zf || c->sf != c->of)) goto L_00807551; /* jle 0x807551 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x10] */
    PUSH32(c, 0x00807535u); f_00805694(c); /* call 0x805694 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_0080754a; /* jne 0x80754a */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x80u)); /* test al, 0x80 */
    if (c->zf) goto L_00807551; /* je 0x807551 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfdu))); /* and al, 0xfd */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xc], eax */
    goto L_00807551; /* jmp 0x807551 */
L_0080754a:;
    { uint32_t a_ = (uint32_t)(c->esi + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x20u)))); } /* or dword ptr [esi + 0xc], 0x20 */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | (uint32_t)0xffffffffu))); /* or ebx, 0xffffffff */
L_00807551:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi + 4], 0 */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00807560(CPU *c) { /* PTR_00807560 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x00807567u); f_00807569(c); /* call 0x807569 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00807569(CPU *c) { /* FUN_10037569 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    PUSH32(c, 0x00807577u); f_00801029(c); /* call 0x801029 */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, R32((uint32_t)(0x816220u)), c->esi); /* cmp dword ptr [0x10046220], esi */
    if ((c->zf || c->sf != c->of)) goto L_008075f6; /* jle 0x8075f6 */
L_00807582:;
    c->eax = (uint32_t)(R32((uint32_t)(0x815208u))); /* mov eax, dword ptr [0x10045208] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 4))); /* mov eax, dword ptr [eax + esi*4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008075ed; /* je 0x8075ed */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + 0xcu)) & (uint8_t)0x83u)); /* test byte ptr [eax + 0xc], 0x83 */
    if (c->zf) goto L_008075ed; /* je 0x8075ed */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x0080759bu); f_008059dc(c); /* call 0x8059dc */
    c->eax = (uint32_t)(R32((uint32_t)(0x815208u))); /* mov eax, dword ptr [0x10045208] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 4))); /* mov eax, dword ptr [eax + esi*4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0xcu))); /* mov ecx, dword ptr [eax + 0xc] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x83u)); /* test cl, 0x83 */
    if (c->zf) goto L_008075dd; /* je 0x8075dd */
    (void)sub32(c, R32((uint32_t)(c->esp + 0x10u)), (uint32_t)0x1u); /* cmp dword ptr [esp + 0x10], 1 */
    if (!c->zf) goto L_008075c3; /* jne 0x8075c3 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008075bau); f_008074d6(c); /* call 0x8074d6 */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_008075dd; /* je 0x8075dd */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    goto L_008075dd; /* jmp 0x8075dd */
L_008075c3:;
    (void)sub32(c, R32((uint32_t)(c->esp + 0x10u)), (uint32_t)0x0u); /* cmp dword ptr [esp + 0x10], 0 */
    if (!c->zf) goto L_008075dd; /* jne 0x8075dd */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x2u)); /* test cl, 2 */
    if (c->zf) goto L_008075dd; /* je 0x8075dd */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008075d5u); f_008074d6(c); /* call 0x8074d6 */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_008075dd; /* jne 0x8075dd */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi | c->eax))); /* or edi, eax */
L_008075dd:;
    c->eax = (uint32_t)(R32((uint32_t)(0x815208u))); /* mov eax, dword ptr [0x10045208] */
    { uint32_t v_ = R32((uint32_t)(c->eax + c->esi * 4)); PUSH32(c, v_); } /* push dword ptr [eax + esi*4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008075ebu); f_00805a2e(c); /* call 0x805a2e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_008075ed:;
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub32(c, c->esi, R32((uint32_t)(0x816220u))); /* cmp esi, dword ptr [0x10046220] */
    if ((c->sf != c->of)) goto L_00807582; /* jl 0x807582 */
L_008075f6:;
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    PUSH32(c, 0x008075fdu); f_0080108a(c); /* call 0x80108a */
    (void)sub32(c, R32((uint32_t)(c->esp + 0x14u)), (uint32_t)0x1u); /* cmp dword ptr [esp + 0x14], 1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    if (c->zf) goto L_00807609; /* je 0x807609 */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
L_00807609:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_0080760d(CPU *c) { /* FUN_1003760d */
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
    if (!c->cf) goto L_0080780d; /* jae 0x80780d */
    (void)sub16(c, ((uint16_t)c->ecx), (uint16_t)0x7fffu); /* cmp cx, 0x7fff */
    if (!c->cf) goto L_0080780d; /* jae 0x80780d */
    (void)sub16(c, ((uint16_t)c->edx), (uint16_t)0xbffdu); /* cmp dx, 0xbffd */
    if ((!c->cf && !c->zf)) goto L_0080780d; /* ja 0x80780d */
    (void)sub16(c, ((uint16_t)c->edx), (uint16_t)0x3fbfu); /* cmp dx, 0x3fbf */
    if ((!c->cf && !c->zf)) goto L_00807676; /* ja 0x807676 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_008076b0; /* jmp 0x8076b0 */
L_00807676:;
    (void)logic16(c, (uint16_t)(((uint16_t)c->eax) & ((uint16_t)c->eax))); /* test ax, ax */
    c->edx = (uint32_t)((uint32_t)0x7fffffffu); /* mov edx, 0x7fffffff */
    if (!c->zf) goto L_00807698; /* jne 0x807698 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->esi + 0x8u)) & c->edx)); /* test dword ptr [esi + 8], edx */
    if (!c->zf) goto L_00807698; /* jne 0x807698 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x4u)), c->eax); /* cmp dword ptr [esi + 4], eax */
    if (!c->zf) goto L_0080769a; /* jne 0x80769a */
    (void)sub32(c, R32((uint32_t)(c->esi)), c->eax); /* cmp dword ptr [esi], eax */
    if (!c->zf) goto L_0080769a; /* jne 0x80769a */
    goto L_00807807; /* jmp 0x807807 */
L_00807698:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_0080769a:;
    (void)sub16(c, ((uint16_t)c->ecx), ((uint16_t)c->eax)); /* cmp cx, ax */
    if (!c->zf) goto L_008076bd; /* jne 0x8076bd */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->ebx + 0x8u)) & c->edx)); /* test dword ptr [ebx + 8], edx */
    if (!c->zf) goto L_008076bd; /* jne 0x8076bd */
    (void)sub32(c, R32((uint32_t)(c->ebx + 0x4u)), c->eax); /* cmp dword ptr [ebx + 4], eax */
    if (!c->zf) goto L_008076bd; /* jne 0x8076bd */
    (void)sub32(c, R32((uint32_t)(c->ebx)), c->eax); /* cmp dword ptr [ebx], eax */
    if (!c->zf) goto L_008076bd; /* jne 0x8076bd */
L_008076b0:;
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 8], eax */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 4], eax */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    goto L_00807828; /* jmp 0x807828 */
L_008076bd:;
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x10], eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe0u)); /* lea eax, [ebp - 0x20] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)((uint32_t)0x5u)); /* mov dword ptr [ebp + 0xc], 5 */
L_008076cd:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    c->eax = (uint32_t)(add32(c, c->eax, c->eax)); /* add eax, eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    if ((c->zf || c->sf != c->of)) goto L_00807721; /* jle 0x807721 */
    c->eax = (uint32_t)(add32(c, c->eax, c->esi)); /* add eax, esi */
    c->ecx = (uint32_t)((uint32_t)(c->ebx + 0x8u)); /* lea ecx, [ebx + 8] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 0xc], ecx */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x18], eax */
L_008076e9:;
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
    PUSH32(c, 0x00807707u); f_00806edf(c); /* call 0x806edf */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00807714; /* je 0x807714 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    { uint32_t a_ = (uint32_t)(c->eax); W16(a_, (uint16_t)(inc16(c, R16(a_)))); } /* inc word ptr [eax] */
L_00807714:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x2u))); } /* add dword ptr [ebp - 8], 2 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff4u); W32(a_, (uint32_t)(sub32(c, R32(a_), (uint32_t)0x2u))); } /* sub dword ptr [ebp - 0xc], 2 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 0x18] */
    if (!c->zf) goto L_008076e9; /* jne 0x8076e9 */
L_00807721:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x2u))); } /* add dword ptr [ebp - 4], 2 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff0u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0x10] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_008076cd; /* jg 0x8076cd */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0xc002u))); } /* add dword ptr [ebp + 8], 0xc002 */
    (void)sub16(c, R16((uint32_t)(c->ebp + 0x8u)), (uint16_t)0x0u); /* cmp word ptr [ebp + 8], 0 */
    if ((c->zf || c->sf != c->of)) goto L_00807764; /* jle 0x807764 */
L_0080773f:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xffffffe7u)) & (uint8_t)0x80u)); /* test byte ptr [ebp - 0x19], 0x80 */
    if (!c->zf) goto L_0080775d; /* jne 0x80775d */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffdcu)); /* lea eax, [ebp - 0x24] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0080774eu); f_00806f5e(c); /* call 0x806f5e */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0xffffu))); } /* add dword ptr [ebp + 8], 0xffff */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub16(c, R16((uint32_t)(c->ebp + 0x8u)), (uint16_t)0x0u); /* cmp word ptr [ebp + 8], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_0080773f; /* jg 0x80773f */
L_0080775d:;
    (void)sub16(c, R16((uint32_t)(c->ebp + 0x8u)), (uint16_t)0x0u); /* cmp word ptr [ebp + 8], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_0080779d; /* jg 0x80779d */
L_00807764:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0xffffu))); } /* add dword ptr [ebp + 8], 0xffff */
    (void)sub16(c, R16((uint32_t)(c->ebp + 0x8u)), (uint16_t)0x0u); /* cmp word ptr [ebp + 8], 0 */
    if ((c->sf == c->of)) goto L_0080779d; /* jge 0x80779d */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int16_t)R16((uint32_t)(c->ebp + 0x8u))); /* movsx eax, word ptr [ebp + 8] */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(add32(c, R32(a_), c->eax))); } /* add dword ptr [ebp + 8], eax */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
L_0080777d:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xffffffdcu)) & (uint8_t)0x1u)); /* test byte ptr [ebp - 0x24], 1 */
    if (c->zf) goto L_00807786; /* je 0x807786 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffecu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0x14] */
L_00807786:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffdcu)); /* lea eax, [ebp - 0x24] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0080778fu); f_00806f8c(c); /* call 0x806f8c */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_0080777d; /* jne 0x80777d */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffecu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x14], 0 */
    if (c->zf) goto L_0080779d; /* je 0x80779d */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffdcu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x1u)))); } /* or byte ptr [ebp - 0x24], 1 */
L_0080779d:;
    (void)sub16(c, R16((uint32_t)(c->ebp + 0xffffffdcu)), (uint16_t)0x8000u); /* cmp word ptr [ebp - 0x24], 0x8000 */
    if ((!c->cf && !c->zf)) goto L_008077b4; /* ja 0x8077b4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1ffffu))); /* and eax, 0x1ffff */
    (void)sub32(c, c->eax, (uint32_t)0x18000u); /* cmp eax, 0x18000 */
    if (!c->zf) goto L_008077e9; /* jne 0x8077e9 */
L_008077b4:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdeu)), (uint32_t)0xffffffffu); /* cmp dword ptr [ebp - 0x22], -1 */
    if (!c->zf) goto L_008077e6; /* jne 0x8077e6 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffdeu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x22], 0 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe2u)), (uint32_t)0xffffffffu); /* cmp dword ptr [ebp - 0x1e], -1 */
    if (!c->zf) goto L_008077e1; /* jne 0x8077e1 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe2u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x1e], 0 */
    (void)sub16(c, R16((uint32_t)(c->ebp + 0xffffffe6u)), (uint16_t)0xffffu); /* cmp word ptr [ebp - 0x1a], 0xffff */
    if (!c->zf) goto L_008077db; /* jne 0x8077db */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp + 8] */
    W16((uint32_t)(c->ebp + 0xffffffe6u), (uint16_t)((uint16_t)0x8000u)); /* mov word ptr [ebp - 0x1a], 0x8000 */
    goto L_008077e9; /* jmp 0x8077e9 */
L_008077db:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe6u); W16(a_, (uint16_t)(inc16(c, R16(a_)))); } /* inc word ptr [ebp - 0x1a] */
    goto L_008077e9; /* jmp 0x8077e9 */
L_008077e1:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe2u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0x1e] */
    goto L_008077e9; /* jmp 0x8077e9 */
L_008077e6:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffdeu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0x22] */
L_008077e9:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)sub16(c, ((uint16_t)c->eax), (uint16_t)0x7fffu); /* cmp ax, 0x7fff */
    if (!c->cf) goto L_0080780d; /* jae 0x80780d */
    c->ecx = (c->ecx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ebp + 0xffffffdeu))); /* mov cx, word ptr [ebp - 0x22] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->edi))); /* or eax, edi */
    W16((uint32_t)(c->esi), (uint16_t)(((uint16_t)c->ecx))); /* mov word ptr [esi], cx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov ecx, dword ptr [ebp - 0x20] */
    W32((uint32_t)(c->esi + 0x2u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 2], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov ecx, dword ptr [ebp - 0x1c] */
    W32((uint32_t)(c->esi + 0x6u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 6], ecx */
L_00807807:;
    W16((uint32_t)(c->esi + 0xau), (uint16_t)(((uint16_t)c->eax))); /* mov word ptr [esi + 0xa], ax */
    goto L_00807828; /* jmp 0x807828 */
L_0080780d:;
    c->edi = (c->edi & 0xffff0000u) | (uint16_t)(neg16(c, ((uint16_t)c->edi))); /* neg di */
    c->edi = (uint32_t)(sbb32(c, c->edi, c->edi)); /* sbb edi, edi */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi + 4], 0 */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & (uint32_t)0x80000000u))); /* and edi, 0x80000000 */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x7fff8000u)); /* add edi, 0x7fff8000 */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi], 0 */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 8], edi */
L_00807828:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0080782d(CPU *c) { /* FUN_1003782d */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)((uint32_t)0x811dc0u); /* mov ebx, 0x10041dc0 */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->ebx = (uint32_t)(sub32(c, c->ebx, (uint32_t)0x60u)); /* sub ebx, 0x60 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->ecx); /* cmp dword ptr [ebp + 0xc], ecx */
    if (c->zf) goto L_008078a6; /* je 0x8078a6 */
    if ((c->sf == c->of)) goto L_00807855; /* jge 0x807855 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->ebx = (uint32_t)((uint32_t)0x811f20u); /* mov ebx, 0x10041f20 */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0xc], eax */
    c->ebx = (uint32_t)(sub32(c, c->ebx, (uint32_t)0x60u)); /* sub ebx, 0x60 */
L_00807855:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), c->ecx); /* cmp dword ptr [ebp + 0x10], ecx */
    if (!c->zf) goto L_00807860; /* jne 0x807860 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W16((uint32_t)(c->eax), (uint16_t)(((uint16_t)c->ecx))); /* mov word ptr [eax], cx */
L_00807860:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->ecx); /* cmp dword ptr [ebp + 0xc], ecx */
    if (c->zf) goto L_008078a6; /* je 0x8078a6 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
L_00807867:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x54u)); /* add ebx, 0x54 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(sar32(c, R32(a_), 3))); } /* sar dword ptr [ebp + 0xc], 3 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7u))); /* and eax, 7 */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (c->zf) goto L_0080789f; /* je 0x80789f */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea eax, [eax + eax*2] */
    (void)sub16(c, R16((uint32_t)(c->ebx + c->eax * 4)), (uint16_t)0x8000u); /* cmp word ptr [ebx + eax*4], 0x8000 */
    c->esi = (uint32_t)((uint32_t)(c->ebx + c->eax * 4)); /* lea esi, [ebx + eax*4] */
    if (c->cf) goto L_00807892; /* jb 0x807892 */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea edi, [ebp - 0xc] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff6u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 0xa] */
    c->esi = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea esi, [ebp - 0xc] */
L_00807892:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x0080789bu); f_0080760d(c); /* call 0x80760d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
L_0080789f:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->ecx); /* cmp dword ptr [ebp + 0xc], ecx */
    if (!c->zf) goto L_00807867; /* jne 0x807867 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_008078a6:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008078a9(CPU *c) { /* FUN_100378a9 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, R32((uint32_t)(0x814e6cu)), c->ebx); /* cmp dword ptr [0x10044e6c], ebx */
    if (!c->zf) goto L_008078c7; /* jne 0x8078c7 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    (void)sub32(c, c->eax, (uint32_t)0x61u); /* cmp eax, 0x61 */
    if ((c->sf != c->of)) goto L_00807916; /* jl 0x807916 */
    (void)sub32(c, c->eax, (uint32_t)0x7au); /* cmp eax, 0x7a */
    if ((!c->zf && c->sf == c->of)) goto L_00807916; /* jg 0x807916 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x20u)); /* sub eax, 0x20 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_008078c7:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)((uint32_t)0x814fccu); /* mov esi, 0x10044fcc */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(0x8090b0u)); PUSH32(c, 0x008078d5u); call_indirect(c, t_); } /* call dword ptr [0x100390b0] */
    (void)sub32(c, R32((uint32_t)(0x814fc8u)), c->ebx); /* cmp dword ptr [0x10044fc8], ebx */
    c->edi = (uint32_t)(R32((uint32_t)(0x8090acu))); /* mov edi, dword ptr [0x100390ac] */
    if (c->zf) goto L_008078f1; /* je 0x8078f1 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = c->edi; PUSH32(c, 0x008078e6u); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x008078edu); f_00801029(c); /* call 0x801029 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
L_008078f1:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    PUSH32(c, 0x008078fau); f_00807918(c); /* call 0x807918 */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    if (c->zf) goto L_0080790d; /* je 0x80790d */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x0080790au); f_0080108a(c); /* call 0x80108a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00807910; /* jmp 0x807910 */
L_0080790d:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00807910u); call_indirect(c, t_); } /* call edi */
L_00807910:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00807916:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00807918(CPU *c) { /* FUN_10037918 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    (void)sub32(c, R32((uint32_t)(0x814e6cu)), (uint32_t)0x0u); /* cmp dword ptr [0x10044e6c], 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    if (!c->zf) goto L_00807943; /* jne 0x807943 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)sub32(c, c->eax, (uint32_t)0x61u); /* cmp eax, 0x61 */
    if ((c->sf != c->of)) goto L_008079e1; /* jl 0x8079e1 */
    (void)sub32(c, c->eax, (uint32_t)0x7au); /* cmp eax, 0x7a */
    if ((!c->zf && c->sf == c->of)) goto L_008079e1; /* jg 0x8079e1 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x20u)); /* sub eax, 0x20 */
    goto L_008079e1; /* jmp 0x8079e1 */
L_00807943:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    (void)sub32(c, c->ebx, (uint32_t)0x100u); /* cmp ebx, 0x100 */
    if ((c->sf == c->of)) goto L_00807976; /* jge 0x807976 */
    (void)sub32(c, R32((uint32_t)(0x80f2ccu)), (uint32_t)0x1u); /* cmp dword ptr [0x1003f2cc], 1 */
    if ((c->zf || c->sf != c->of)) goto L_00807963; /* jle 0x807963 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x0080795fu); f_00800eeb(c); /* call 0x800eeb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_0080796e; /* jmp 0x80796e */
L_00807963:;
    c->eax = (uint32_t)(R32((uint32_t)(0x80f0c0u))); /* mov eax, dword ptr [0x1003f0c0] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + c->ebx * 2))); /* mov al, byte ptr [eax + ebx*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x2u))); /* and eax, 2 */
L_0080796e:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00807976; /* jne 0x807976 */
L_00807972:;
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    goto L_008079e1; /* jmp 0x8079e1 */
L_00807976:;
    c->edx = (uint32_t)(R32((uint32_t)(0x80f0c0u))); /* mov edx, dword ptr [0x1003f0c0] */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->eax = (uint32_t)(sar32(c, c->eax, 8)); /* sar eax, 8 */
    c->ecx = (uint32_t)((uint32_t)((uint8_t)c->eax)); /* movzx ecx, al */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edx + c->ecx * 2 + 0x1u)) & (uint8_t)0x80u)); /* test byte ptr [edx + ecx*2 + 1], 0x80 */
    if (c->zf) goto L_00807999; /* je 0x807999 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xau); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp + 0xa], 0 */
    W8((uint32_t)(c->ebp + 0x8u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp + 8], al */
    W8((uint32_t)(c->ebp + 0x9u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ebp + 9], bl */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    goto L_008079a2; /* jmp 0x8079a2 */
L_00807999:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0x9u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp + 9], 0 */
    W8((uint32_t)(c->ebp + 0x8u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ebp + 8], bl */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
L_008079a2:;
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
    { uint32_t v_ = R32((uint32_t)(0x814e6cu)); PUSH32(c, v_); } /* push dword ptr [0x10044e6c] */
    PUSH32(c, 0x008079c2u); f_00806c90(c); /* call 0x806c90 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00807972; /* je 0x807972 */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_008079d4; /* jne 0x8079d4 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0xfffffffcu))); /* movzx eax, byte ptr [ebp - 4] */
    goto L_008079e1; /* jmp 0x8079e1 */
L_008079d4:;
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0xfffffffdu))); /* movzx eax, byte ptr [ebp - 3] */
    c->ecx = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0xfffffffcu))); /* movzx ecx, byte ptr [ebp - 4] */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->ecx))); /* or eax, ecx */
L_008079e1:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008079f0(CPU *c) { /* FUN_100379f0 */
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
L_00807a04:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov al, byte ptr [edx] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00807a11; /* je 0x807a11 */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    { int32_t b_ = (int32_t)(c->eax); uint32_t a_ = (uint32_t)(c->esp) + (uint32_t)((b_ >> 3) & ~3); unsigned k_ = b_ & 31; uint32_t v_ = R32(a_); c->cf = (v_ >> k_) & 1; W32(a_, v_ | (1u << k_)); } /* bts dword ptr [esp], eax */
    goto L_00807a04; /* jmp 0x807a04 */
L_00807a11:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0xffffffffu))); /* or ecx, 0xffffffff */
    ; /* nop  */
L_00807a18:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00807a26; /* je 0x807a26 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    { int32_t b_ = (int32_t)(c->eax); uint32_t a_ = (uint32_t)(c->esp) + (uint32_t)((b_ >> 3) & ~3); unsigned k_ = b_ & 31; uint32_t v_ = R32(a_); c->cf = (v_ >> k_) & 1; } /* bt dword ptr [esp], eax */
    if (!c->cf) goto L_00807a18; /* jae 0x807a18 */
L_00807a26:;
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00807a30(CPU *c) { /* FUN_10037a30 */
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
L_00807a44:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov al, byte ptr [edx] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00807a51; /* je 0x807a51 */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    { int32_t b_ = (int32_t)(c->eax); uint32_t a_ = (uint32_t)(c->esp) + (uint32_t)((b_ >> 3) & ~3); unsigned k_ = b_ & 31; uint32_t v_ = R32(a_); c->cf = (v_ >> k_) & 1; W32(a_, v_ | (1u << k_)); } /* bts dword ptr [esp], eax */
    goto L_00807a44; /* jmp 0x807a44 */
L_00807a51:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
L_00807a54:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00807a64; /* je 0x807a64 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    { int32_t b_ = (int32_t)(c->eax); uint32_t a_ = (uint32_t)(c->esp) + (uint32_t)((b_ >> 3) & ~3); unsigned k_ = b_ & 31; uint32_t v_ = R32(a_); c->cf = (v_ >> k_) & 1; } /* bt dword ptr [esp], eax */
    if (!c->cf) goto L_00807a54; /* jae 0x807a54 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0xffffffffu)); /* lea eax, [esi - 1] */
L_00807a64:;
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00807a6a(CPU *c) { /* FUN_10037a6a */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi | (uint32_t)0xffffffffu))); /* or edi, 0xffffffff */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi + 0xcu)) & (uint8_t)0x40u)); /* test byte ptr [esi + 0xc], 0x40 */
    if (c->zf) goto L_00807a7f; /* je 0x807a7f */
    { uint32_t a_ = (uint32_t)(c->esi + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi + 0xc], 0 */
    goto L_00807a96; /* jmp 0x807a96 */
L_00807a7f:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00807a85u); f_008059ad(c); /* call 0x8059ad */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00807a8bu); f_00807a9b(c); /* call 0x807a9b */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    PUSH32(c, 0x00807a93u); f_008059ff(c); /* call 0x8059ff */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_00807a96:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00807a9b(CPU *c) { /* FUN_10037a9b */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi | (uint32_t)0xffffffffu))); /* or edi, 0xffffffff */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi + 0xcu)) & (uint8_t)0x83u)); /* test byte ptr [esi + 0xc], 0x83 */
    if (c->zf) goto L_00807ade; /* je 0x807ade */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00807ab0u); f_00807504(c); /* call 0x807504 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    PUSH32(c, 0x00807ab8u); f_00807eb1(c); /* call 0x807eb1 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x10] */
    PUSH32(c, 0x00807ac0u); f_00807dd1(c); /* call 0x807dd1 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf == c->of)) goto L_00807acc; /* jge 0x807acc */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi | (uint32_t)0xffffffffu))); /* or edi, 0xffffffff */
    goto L_00807ade; /* jmp 0x807ade */
L_00807acc:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x1cu))); /* mov eax, dword ptr [esi + 0x1c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00807ade; /* je 0x807ade */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00807ad9u); f_0080109f(c); /* call 0x80109f */
    { uint32_t a_ = (uint32_t)(c->esi + 0x1cu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi + 0x1c], 0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00807ade:;
    { uint32_t a_ = (uint32_t)(c->esi + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi + 0xc], 0 */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00807ae7(CPU *c) { /* FUN_10037ae7 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ebx, dword ptr [esp + 8] */
    (void)sub32(c, c->ebx, R32((uint32_t)(0x816360u))); /* cmp ebx, dword ptr [0x10046360] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->cf) goto L_00807b68; /* jae 0x807b68 */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->eax = (uint32_t)(sar32(c, c->eax, 5)); /* sar eax, 5 */
    c->edi = (uint32_t)((uint32_t)(c->eax * 4 + 0x816260u)); /* lea edi, [eax*4 + 0x10046260] */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1fu))); /* and eax, 0x1f */
    c->esi = (uint32_t)((uint32_t)(c->eax + c->eax * 8)); /* lea esi, [eax + eax*8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    c->esi = (uint32_t)(shl32(c, c->esi, 2)); /* shl esi, 2 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + c->esi + 0x4u)) & (uint8_t)0x1u)); /* test byte ptr [eax + esi + 4], 1 */
    if (c->zf) goto L_00807b68; /* je 0x807b68 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00807b1cu); f_008073d4(c); /* call 0x8073d4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + c->esi + 0x4u)) & (uint8_t)0x1u)); /* test byte ptr [eax + esi + 4], 1 */
    if (c->zf) goto L_00807b4f; /* je 0x807b4f */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00807b2cu); f_00807392(c); /* call 0x807392 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x8090f0u)); PUSH32(c, 0x00807b34u); call_indirect(c, t_); } /* call dword ptr [0x100390f0] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00807b42; /* jne 0x807b42 */
    { uint32_t t_ = R32((uint32_t)(0x809030u)); PUSH32(c, 0x00807b3eu); call_indirect(c, t_); } /* call dword ptr [0x10039030] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    goto L_00807b44; /* jmp 0x807b44 */
L_00807b42:;
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_00807b44:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00807b5d; /* je 0x807b5d */
    PUSH32(c, 0x00807b4du); f_0080629b(c); /* call 0x80629b */
    W32((uint32_t)(c->eax), (uint32_t)(c->esi)); /* mov dword ptr [eax], esi */
L_00807b4f:;
    PUSH32(c, 0x00807b54u); f_00806292(c); /* call 0x806292 */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x9u)); /* mov dword ptr [eax], 9 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi | (uint32_t)0xffffffffu))); /* or esi, 0xffffffff */
L_00807b5d:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00807b63u); f_00807433(c); /* call 0x807433 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    goto L_00807b76; /* jmp 0x807b76 */
L_00807b68:;
    PUSH32(c, 0x00807b6du); f_00806292(c); /* call 0x806292 */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x9u)); /* mov dword ptr [eax], 9 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
L_00807b76:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00807b7a(CPU *c) { /* FUN_10037b7a */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x14u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x14], 0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (c->zf) goto L_00807b94; /* je 0x807b94 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    W8((uint32_t)(c->ecx), (uint8_t)((uint8_t)0x2du)); /* mov byte ptr [ecx], 0x2d */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->esi = (uint32_t)(neg32(c, c->esi)); /* neg esi */
    goto L_00807b97; /* jmp 0x807b97 */
L_00807b94:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
L_00807b97:;
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
L_00807b99:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    { uint32_t d_ = R32((uint32_t)(c->ebp + 0x10u)); uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x00807b9du, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div dword ptr [ebp + 0x10] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ebx = (uint32_t)(c->edx); /* mov ebx, edx */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    { uint32_t d_ = R32((uint32_t)(c->ebp + 0x10u)); uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x00807ba6u, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div dword ptr [ebp + 0x10] */
    (void)sub32(c, c->ebx, (uint32_t)0x9u); /* cmp ebx, 9 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    if ((c->cf || c->zf)) goto L_00807bb5; /* jbe 0x807bb5 */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(add8(c, ((uint8_t)c->ebx), (uint8_t)0x57u)); /* add bl, 0x57 */
    goto L_00807bb8; /* jmp 0x807bb8 */
L_00807bb5:;
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(add8(c, ((uint8_t)c->ebx), (uint8_t)0x30u)); /* add bl, 0x30 */
L_00807bb8:;
    W8((uint32_t)(c->ecx), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ecx], bl */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if ((!c->cf && !c->zf)) goto L_00807b99; /* ja 0x807b99 */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ecx], 0 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
L_00807bc3:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov dl, byte ptr [edi] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov al, byte ptr [ecx] */
    W8((uint32_t)(c->ecx), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [ecx], dl */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->edi, c->ecx); /* cmp edi, ecx */
    if (c->cf) goto L_00807bc3; /* jb 0x807bc3 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00807bd6(CPU *c) { /* FUN_10037bd6 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    PUSH32(c, 0x00807be9u); f_00807b7a(c); /* call 0x807b7a */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_00807c00(CPU *c) { /* FUN_10037c00 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    c->eax = (uint32_t)((uint32_t)(0x814e64u)); /* lea eax, [0x10044e64] */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [eax + 8], 0 */
    if (!c->zf) goto L_00807c53; /* jne 0x807c53 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0xffu); /* mov al, 0xff */
    c->edi = (uint32_t)(c->edi); /* mov edi, edi */
L_00807c1c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00807c4e; /* je 0x807c4e */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->edi))) << 8); /* mov ah, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->eax)); /* cmp ah, al */
    if (c->zf) goto L_00807c1c; /* je 0x807c1c */
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
    if (c->zf) goto L_00807c1c; /* je 0x807c1c */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sbb8(c, ((uint8_t)c->eax), ((uint8_t)c->eax))); /* sbb al, al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sbb8(c, ((uint8_t)c->eax), (uint8_t)0xffu)); /* sbb al, 0xff */
L_00807c4e:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->eax)); /* movsx eax, al */
    goto L_00807ccb; /* jmp 0x807ccb */
L_00807c53:;
    { guest_lock(); guest_trap(c, 0x00807c53u, "unsupported: lock inc dword ptr [0x10044fcc]"); guest_unlock(); } /* lock inc dword ptr [0x10044fcc] */
    (void)sub32(c, R32((uint32_t)(0x814fc8u)), (uint32_t)0x0u); /* cmp dword ptr [0x10044fc8], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_00807c67; /* jg 0x807c67 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    goto L_00807c7c; /* jmp 0x807c7c */
L_00807c67:;
    { guest_lock(); guest_trap(c, 0x00807c67u, "unsupported: lock dec dword ptr [0x10044fcc]"); guest_unlock(); } /* lock dec dword ptr [0x10044fcc] */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x00807c75u); f_00801029(c); /* call 0x801029 */
    W32((uint32_t)(c->esp), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [esp], 1 */
L_00807c7c:;
    c->eax = (uint32_t)((uint32_t)0xffu); /* mov eax, 0xff */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    ; /* nop  */
L_00807c84:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00807caf; /* je 0x807caf */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_00807c84; /* je 0x807c84 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00807c99u); f_008026aa(c); /* call 0x8026aa */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    PUSH32(c, 0x00807ca3u); f_008026aa(c); /* call 0x8026aa */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    (void)sub8(c, ((uint8_t)c->ebx), ((uint8_t)c->eax)); /* cmp bl, al */
    if (c->zf) goto L_00807c84; /* je 0x807c84 */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, (uint32_t)0xffffffffu)); /* sbb eax, -1 */
L_00807caf:;
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->eax))); /* or eax, eax */
    if (!c->zf) goto L_00807cbf; /* jne 0x807cbf */
    { guest_lock(); guest_trap(c, 0x00807cb6u, "unsupported: lock dec dword ptr [0x10044fcc]"); guest_unlock(); } /* lock dec dword ptr [0x10044fcc] */
    goto L_00807cc9; /* jmp 0x807cc9 */
L_00807cbf:;
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x00807cc6u); f_0080108a(c); /* call 0x80108a */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00807cc9:;
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
L_00807ccb:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00807cd0(CPU *c) { /* FUN_10037cd0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->ecx))); /* or ecx, ecx */
    if (c->zf) goto L_00807dca; /* je 0x807dca */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)((uint32_t)(0x814e64u)); /* lea eax, [0x10044e64] */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [eax + 8], 0 */
    if (!c->zf) goto L_00807d41; /* jne 0x807d41 */
    c->ebx = (c->ebx & 0xffff00ffu) | ((uint32_t)(uint8_t)((uint8_t)0x41u) << 8); /* mov bh, 0x41 */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)((uint8_t)0x5au); /* mov bl, 0x5a */
    c->edx = (c->edx & 0xffff00ffu) | ((uint32_t)(uint8_t)((uint8_t)0x20u) << 8); /* mov dh, 0x20 */
    c->ecx = (uint32_t)((uint32_t)(c->ecx)); /* lea ecx, [ecx] */
L_00807cfc:;
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->esi))) << 8); /* mov ah, byte ptr [esi] */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | ((uint8_t)(c->eax >> 8))))) << 8); /* or ah, ah */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov al, byte ptr [edi] */
    if (c->zf) goto L_00807d25; /* je 0x807d25 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00807d25; /* je 0x807d25 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)(c->ebx >> 8))); /* cmp ah, bh */
    if (c->cf) goto L_00807d14; /* jb 0x807d14 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->ebx)); /* cmp ah, bl */
    if ((!c->cf && !c->zf)) goto L_00807d14; /* ja 0x807d14 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(add8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)(c->edx >> 8)))) << 8); /* add ah, dh */
L_00807d14:;
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)(c->ebx >> 8))); /* cmp al, bh */
    if (c->cf) goto L_00807d1e; /* jb 0x807d1e */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if ((!c->cf && !c->zf)) goto L_00807d1e; /* ja 0x807d1e */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(add8(c, ((uint8_t)c->eax), ((uint8_t)(c->edx >> 8)))); /* add al, dh */
L_00807d1e:;
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->eax)); /* cmp ah, al */
    if (!c->zf) goto L_00807d2f; /* jne 0x807d2f */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (!c->zf) goto L_00807cfc; /* jne 0x807cfc */
L_00807d25:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->eax)); /* cmp ah, al */
    if (c->zf) goto L_00807dca; /* je 0x807dca */
L_00807d2f:;
    c->ecx = (uint32_t)((uint32_t)0xffffffffu); /* mov ecx, 0xffffffff */
    if (c->cf) goto L_00807dca; /* jb 0x807dca */
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
    goto L_00807dca; /* jmp 0x807dca */
L_00807d41:;
    { guest_lock(); guest_trap(c, 0x00807d41u, "unsupported: lock inc dword ptr [0x10044fcc]"); guest_unlock(); } /* lock inc dword ptr [0x10044fcc] */
    (void)sub32(c, R32((uint32_t)(0x814fc8u)), (uint32_t)0x0u); /* cmp dword ptr [0x10044fc8], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_00807d55; /* jg 0x807d55 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    goto L_00807d6e; /* jmp 0x807d6e */
L_00807d55:;
    { guest_lock(); guest_trap(c, 0x00807d55u, "unsupported: lock dec dword ptr [0x10044fcc]"); guest_unlock(); } /* lock dec dword ptr [0x10044fcc] */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x00807d65u); f_00801029(c); /* call 0x801029 */
    W32((uint32_t)(c->esp), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [esp], 1 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
L_00807d6e:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->edi = (uint32_t)(c->edi); /* mov edi, edi */
L_00807d74:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->eax))); /* or eax, eax */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    if (c->zf) goto L_00807d9f; /* je 0x807d9f */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | c->ebx))); /* or ebx, ebx */
    if (c->zf) goto L_00807d9f; /* je 0x807d9f */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00807d8au); f_008026aa(c); /* call 0x8026aa */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    PUSH32(c, 0x00807d94u); f_008026aa(c); /* call 0x8026aa */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (!c->zf) goto L_00807da5; /* jne 0x807da5 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (!c->zf) goto L_00807d74; /* jne 0x807d74 */
L_00807d9f:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_00807dae; /* je 0x807dae */
L_00807da5:;
    c->ecx = (uint32_t)((uint32_t)0xffffffffu); /* mov ecx, 0xffffffff */
    if (c->cf) goto L_00807dae; /* jb 0x807dae */
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
L_00807dae:;
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->eax))); /* or eax, eax */
    if (!c->zf) goto L_00807dbc; /* jne 0x807dbc */
    { guest_lock(); guest_trap(c, 0x00807db3u, "unsupported: lock dec dword ptr [0x10044fcc]"); guest_unlock(); } /* lock dec dword ptr [0x10044fcc] */
    goto L_00807dca; /* jmp 0x807dca */
L_00807dbc:;
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x00807dc5u); f_0080108a(c); /* call 0x80108a */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
L_00807dca:;
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00807dd1(CPU *c) { /* FUN_10037dd1 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    (void)sub32(c, c->esi, R32((uint32_t)(0x816360u))); /* cmp esi, dword ptr [0x10046360] */
    if (!c->cf) goto L_00807e16; /* jae 0x807e16 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 5)); /* sar ecx, 5 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1fu))); /* and eax, 0x1f */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx * 4 + 0x816260u))); /* mov ecx, dword ptr [ecx*4 + 0x10046260] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 8)); /* lea eax, [eax + eax*8] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 4 + 0x4u)) & (uint8_t)0x1u)); /* test byte ptr [ecx + eax*4 + 4], 1 */
    if (c->zf) goto L_00807e16; /* je 0x807e16 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00807e00u); f_008073d4(c); /* call 0x8073d4 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00807e06u); f_00807e2e(c); /* call 0x807e2e */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    PUSH32(c, 0x00807e0eu); f_00807433(c); /* call 0x807433 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_00807e16:;
    PUSH32(c, 0x00807e1bu); f_00806292(c); /* call 0x806292 */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x9u)); /* mov dword ptr [eax], 9 */
    PUSH32(c, 0x00807e26u); f_0080629b(c); /* call 0x80629b */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [eax], 0 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00807e2e(CPU *c) { /* FUN_10037e2e */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00807e3au); f_00807392(c); /* call 0x807392 */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00807e7c; /* je 0x807e7c */
    (void)sub32(c, c->esi, (uint32_t)0x1u); /* cmp esi, 1 */
    if (c->zf) goto L_00807e4a; /* je 0x807e4a */
    (void)sub32(c, c->esi, (uint32_t)0x2u); /* cmp esi, 2 */
    if (!c->zf) goto L_00807e60; /* jne 0x807e60 */
L_00807e4a:;
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    PUSH32(c, 0x00807e51u); f_00807392(c); /* call 0x807392 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    PUSH32(c, 0x00807e5au); f_00807392(c); /* call 0x807392 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00807e7c; /* je 0x807e7c */
L_00807e60:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00807e66u); f_00807392(c); /* call 0x807392 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x8090f4u)); PUSH32(c, 0x00807e6eu); call_indirect(c, t_); } /* call dword ptr [0x100390f4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00807e7c; /* jne 0x807e7c */
    { uint32_t t_ = R32((uint32_t)(0x809030u)); PUSH32(c, 0x00807e78u); call_indirect(c, t_); } /* call dword ptr [0x10039030] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    goto L_00807e7e; /* jmp 0x807e7e */
L_00807e7c:;
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
L_00807e7e:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00807e84u); f_00807313(c); /* call 0x807313 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0x1fu))); /* and esi, 0x1f */
    c->eax = (uint32_t)(sar32(c, c->eax, 5)); /* sar eax, 5 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax * 4 + 0x816260u))); /* mov eax, dword ptr [eax*4 + 0x10046260] */
    c->ecx = (uint32_t)((uint32_t)(c->esi + c->esi * 8)); /* lea ecx, [esi + esi*8] */
    { uint32_t a_ = (uint32_t)(c->eax + c->ecx * 4 + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax + ecx*4 + 4], 0 */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00807eac; /* je 0x807eac */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00807ea6u); f_0080621f(c); /* call 0x80621f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    goto L_00807eae; /* jmp 0x807eae */
L_00807eac:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00807eae:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00807eb1(CPU *c) { /* FUN_10037eb1 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x83u)); /* test al, 0x83 */
    if (c->zf) goto L_00807eda; /* je 0x807eda */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x8u)); /* test al, 8 */
    if (c->zf) goto L_00807eda; /* je 0x807eda */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esi + 8] */
    PUSH32(c, 0x00807ec9u); f_0080109f(c); /* call 0x80109f */
    { uint32_t a_ = (uint32_t)(c->esi + 0xcu); W16(a_, (uint16_t)(logic16(c, (uint16_t)(R16(a_) & (uint16_t)0xfbf7u)))); } /* and word ptr [esi + 0xc], 0xfbf7 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 8], eax */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 4], eax */
L_00807eda:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00807ee0(CPU *c) { /* KERNEL32.DLL::RtlUnwind */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(0x809008u)); switch (t_) {  default: jump_indirect(c, t_, 0x00807ee0u); return; } } /* jmp dword ptr [0x10039008] */
}

void f_00807ef0(CPU *c) { /* Unwind@10037ef0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    { f_007d7e10(c); return; } /* jmp 0x7d7e10 */
}

void f_00807ef8(CPU *c) { /* Unwind@10037ef8 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x124u)); /* add ecx, 0x124 */
    { f_007d5000(c); return; } /* jmp 0x7d5000 */
}

void f_00807f06(CPU *c) { /* Unwind@10037f06 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x134u)); /* add ecx, 0x134 */
    { f_007d5000(c); return; } /* jmp 0x7d5000 */
}

void f_00807f14(CPU *c) { /* Unwind@10037f14 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x144u)); /* add ecx, 0x144 */
    { f_007d5000(c); return; } /* jmp 0x7d5000 */
}

void f_00807f22(CPU *c) { /* Unwind@10037f22 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x154u)); /* add ecx, 0x154 */
    { f_007d5000(c); return; } /* jmp 0x7d5000 */
}

void f_00807f30(CPU *c) { /* Unwind@10037f30 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x164u)); /* add ecx, 0x164 */
    { f_007d5000(c); return; } /* jmp 0x7d5000 */
}

void f_00807f3e(CPU *c) { /* Unwind@10037f3e */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x174u)); /* add ecx, 0x174 */
    { f_007d5000(c); return; } /* jmp 0x7d5000 */
}

void f_00807f4c(CPU *c) { /* Unwind@10037f4c */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x184u)); /* add ecx, 0x184 */
    { f_007d5000(c); return; } /* jmp 0x7d5000 */
}

void f_00807f5a(CPU *c) { /* Unwind@10037f5a */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x194u)); /* add ecx, 0x194 */
    { f_007d5000(c); return; } /* jmp 0x7d5000 */
}

void f_00807f68(CPU *c) { /* Unwind@10037f68 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x1a4u)); /* add ecx, 0x1a4 */
    { f_007d5000(c); return; } /* jmp 0x7d5000 */
}

void f_00807f76(CPU *c) { /* Unwind@10037f76 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x1b4u)); /* add ecx, 0x1b4 */
    { f_007d5000(c); return; } /* jmp 0x7d5000 */
}

void f_00807f84(CPU *c) { /* Unwind@10037f84 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x1c4u)); /* add ecx, 0x1c4 */
    { f_007d5000(c); return; } /* jmp 0x7d5000 */
}

void f_00807f92(CPU *c) { /* Unwind@10037f92 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x1d4u)); /* add ecx, 0x1d4 */
    { f_007d5000(c); return; } /* jmp 0x7d5000 */
}

void f_00807fa0(CPU *c) { /* Unwind@10037fa0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x1e4u)); /* add ecx, 0x1e4 */
    { f_007d5000(c); return; } /* jmp 0x7d5000 */
}

void f_00807fae(CPU *c) { /* Unwind@10037fae */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x1f4u)); /* add ecx, 0x1f4 */
    { f_007d5000(c); return; } /* jmp 0x7d5000 */
}

void f_00807fbc(CPU *c) { /* Unwind@10037fbc */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x7d5000u; PUSH32(c, v_); } /* push 0x10005000 */
    { uint32_t v_ = 0x20u; PUSH32(c, v_); } /* push 0x20 */
    { uint32_t v_ = 0xcu; PUSH32(c, v_); } /* push 0xc */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x208u)); /* add eax, 0x208 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00807fd3u); f_007fdb7c(c); /* call 0x7fdb7c */
    c->esp += 4; return; /* ret  */
}

void f_00807fd4(CPU *c) { /* Unwind@10037fd4 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x7d5000u; PUSH32(c, v_); } /* push 0x10005000 */
    { uint32_t v_ = 0x20u; PUSH32(c, v_); } /* push 0x20 */
    { uint32_t v_ = 0xcu; PUSH32(c, v_); } /* push 0xc */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x38cu)); /* add eax, 0x38c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00807febu); f_007fdb7c(c); /* call 0x7fdb7c */
    c->esp += 4; return; /* ret  */
}

void f_00807fec(CPU *c) { /* Unwind@10037fec */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x7d5000u; PUSH32(c, v_); } /* push 0x10005000 */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x510u)); /* add eax, 0x510 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00808003u); f_007fdb7c(c); /* call 0x7fdb7c */
    c->esp += 4; return; /* ret  */
}

void f_00808004(CPU *c) { /* Unwind@10038004 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x7d5000u; PUSH32(c, v_); } /* push 0x10005000 */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x594u)); /* add eax, 0x594 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0080801bu); f_007fdb7c(c); /* call 0x7fdb7c */
    c->esp += 4; return; /* ret  */
}

void f_0080801c(CPU *c) { /* Unwind@1003801c */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x618u)); /* add ecx, 0x618 */
    { f_007d3d60(c); return; } /* jmp 0x7d3d60 */
}

void f_0080802a(CPU *c) { /* Unwind@1003802a */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x620u)); /* add ecx, 0x620 */
    { f_007d3d60(c); return; } /* jmp 0x7d3d60 */
}

void f_00808038(CPU *c) { /* Unwind@10038038 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x628u)); /* add ecx, 0x628 */
    { f_007d3d60(c); return; } /* jmp 0x7d3d60 */
}

void f_00808046(CPU *c) { /* Unwind@10038046 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x630u)); /* add ecx, 0x630 */
    { f_007d5000(c); return; } /* jmp 0x7d5000 */
}

void f_00808054(CPU *c) { /* Unwind@10038054 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x640u)); /* add ecx, 0x640 */
    { f_007d5000(c); return; } /* jmp 0x7d5000 */
}

void f_00808062(CPU *c) { /* Unwind@10038062 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x650u)); /* add ecx, 0x650 */
    { f_007d5000(c); return; } /* jmp 0x7d5000 */
}

void f_00808070(CPU *c) { /* Unwind@10038070 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x660u)); /* add ecx, 0x660 */
    { f_007d5000(c); return; } /* jmp 0x7d5000 */
}

void f_0080807e(CPU *c) { /* Unwind@1003807e */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x7d3d60u; PUSH32(c, v_); } /* push 0x10003d60 */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x670u)); /* add eax, 0x670 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00808095u); f_007fdb7c(c); /* call 0x7fdb7c */
    c->esp += 4; return; /* ret  */
}

void f_00808096(CPU *c) { /* Unwind@10038096 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x7d3d60u; PUSH32(c, v_); } /* push 0x10003d60 */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x6b4u)); /* add eax, 0x6b4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008080adu); f_007fdb7c(c); /* call 0x7fdb7c */
    c->esp += 4; return; /* ret  */
}

void f_008080ae(CPU *c) { /* Unwind@100380ae */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x7d3d60u; PUSH32(c, v_); } /* push 0x10003d60 */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x6f8u)); /* add eax, 0x6f8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008080c5u); f_007fdb7c(c); /* call 0x7fdb7c */
    c->esp += 4; return; /* ret  */
}

void f_008080c6(CPU *c) { /* Unwind@100380c6 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x73cu)); /* add ecx, 0x73c */
    { f_007d3d60(c); return; } /* jmp 0x7d3d60 */
}

void f_008080d4(CPU *c) { /* Unwind@100380d4 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x744u)); /* add ecx, 0x744 */
    { f_007d3d60(c); return; } /* jmp 0x7d3d60 */
}

void f_008080e2(CPU *c) { /* Unwind@100380e2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x7d3d60u; PUSH32(c, v_); } /* push 0x10003d60 */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x74cu)); /* add eax, 0x74c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008080f9u); f_007fdb7c(c); /* call 0x7fdb7c */
    c->esp += 4; return; /* ret  */
}

void f_008080fa(CPU *c) { /* Unwind@100380fa */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x790u)); /* add ecx, 0x790 */
    { f_007d3d60(c); return; } /* jmp 0x7d3d60 */
}

void f_00808108(CPU *c) { /* Unwind@10038108 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x798u)); /* add ecx, 0x798 */
    { f_007d3d60(c); return; } /* jmp 0x7d3d60 */
}

void f_00808116(CPU *c) { /* Unwind@10038116 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x7d8u)); /* add ecx, 0x7d8 */
    { f_007d3d60(c); return; } /* jmp 0x7d3d60 */
}

void f_00808124(CPU *c) { /* Unwind@10038124 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x98cu)); /* add ecx, 0x98c */
    { f_007f5720(c); return; } /* jmp 0x7f5720 */
}

void f_00808132(CPU *c) { /* Unwind@10038132 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x9acu)); /* add ecx, 0x9ac */
    { f_007d5010(c); return; } /* jmp 0x7d5010 */
}

void f_00808140(CPU *c) { /* PTR_00808140 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x80a41cu); /* mov eax, 0x1003a41c */
    { f_007fdd6d(c); return; } /* jmp 0x7fdd6d */
}

void f_00808150(CPU *c) { /* Unwind@10038150 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    { f_007d7e10(c); return; } /* jmp 0x7d7e10 */
}

void f_00808158(CPU *c) { /* Unwind@10038158 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x124u)); /* add ecx, 0x124 */
    { f_007d5000(c); return; } /* jmp 0x7d5000 */
}

void f_00808166(CPU *c) { /* Unwind@10038166 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x134u)); /* add ecx, 0x134 */
    { f_007d5000(c); return; } /* jmp 0x7d5000 */
}

void f_00808174(CPU *c) { /* Unwind@10038174 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x144u)); /* add ecx, 0x144 */
    { f_007d5000(c); return; } /* jmp 0x7d5000 */
}

void f_00808182(CPU *c) { /* Unwind@10038182 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x154u)); /* add ecx, 0x154 */
    { f_007d5000(c); return; } /* jmp 0x7d5000 */
}

void f_0080818b(CPU *c) { /* PTR_0080818b */
    PREEMPT_POLL(c);
    { f_007d5000(c); return; } /* jmp 0x7d5000 */
}

void f_00808190(CPU *c) { /* Unwind@10038190 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x164u)); /* add ecx, 0x164 */
    { f_007d5000(c); return; } /* jmp 0x7d5000 */
}

void f_0080819e(CPU *c) { /* Unwind@1003819e */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x174u)); /* add ecx, 0x174 */
    { f_007d5000(c); return; } /* jmp 0x7d5000 */
}

void f_008081ac(CPU *c) { /* Unwind@100381ac */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x184u)); /* add ecx, 0x184 */
    { f_007d5000(c); return; } /* jmp 0x7d5000 */
}

void f_008081ba(CPU *c) { /* Unwind@100381ba */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x194u)); /* add ecx, 0x194 */
    { f_007d5000(c); return; } /* jmp 0x7d5000 */
}

void f_008081c8(CPU *c) { /* Unwind@100381c8 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x1a4u)); /* add ecx, 0x1a4 */
    { f_007d5000(c); return; } /* jmp 0x7d5000 */
}

void f_008081d6(CPU *c) { /* Unwind@100381d6 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x1b4u)); /* add ecx, 0x1b4 */
    { f_007d5000(c); return; } /* jmp 0x7d5000 */
}

void f_008081e4(CPU *c) { /* Unwind@100381e4 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x1c4u)); /* add ecx, 0x1c4 */
    { f_007d5000(c); return; } /* jmp 0x7d5000 */
}

void f_008081f2(CPU *c) { /* Unwind@100381f2 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x1d4u)); /* add ecx, 0x1d4 */
    { f_007d5000(c); return; } /* jmp 0x7d5000 */
}

void f_00808200(CPU *c) { /* Unwind@10038200 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x1e4u)); /* add ecx, 0x1e4 */
    { f_007d5000(c); return; } /* jmp 0x7d5000 */
}

void f_0080820e(CPU *c) { /* Unwind@1003820e */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x1f4u)); /* add ecx, 0x1f4 */
    { f_007d5000(c); return; } /* jmp 0x7d5000 */
}

void f_0080821c(CPU *c) { /* Unwind@1003821c */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x7d5000u; PUSH32(c, v_); } /* push 0x10005000 */
    { uint32_t v_ = 0x20u; PUSH32(c, v_); } /* push 0x20 */
    { uint32_t v_ = 0xcu; PUSH32(c, v_); } /* push 0xc */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x208u)); /* add eax, 0x208 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00808233u); f_007fdb7c(c); /* call 0x7fdb7c */
    c->esp += 4; return; /* ret  */
}

void f_00808234(CPU *c) { /* Unwind@10038234 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x7d5000u; PUSH32(c, v_); } /* push 0x10005000 */
    { uint32_t v_ = 0x20u; PUSH32(c, v_); } /* push 0x20 */
    { uint32_t v_ = 0xcu; PUSH32(c, v_); } /* push 0xc */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x38cu)); /* add eax, 0x38c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0080824bu); f_007fdb7c(c); /* call 0x7fdb7c */
    c->esp += 4; return; /* ret  */
}

void f_0080824c(CPU *c) { /* Unwind@1003824c */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x7d5000u; PUSH32(c, v_); } /* push 0x10005000 */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x510u)); /* add eax, 0x510 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00808263u); f_007fdb7c(c); /* call 0x7fdb7c */
    c->esp += 4; return; /* ret  */
}

void f_00808264(CPU *c) { /* Unwind@10038264 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x7d5000u; PUSH32(c, v_); } /* push 0x10005000 */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x594u)); /* add eax, 0x594 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0080827bu); f_007fdb7c(c); /* call 0x7fdb7c */
    c->esp += 4; return; /* ret  */
}

void f_0080827c(CPU *c) { /* Unwind@1003827c */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x618u)); /* add ecx, 0x618 */
    { f_007d3d60(c); return; } /* jmp 0x7d3d60 */
}

void f_0080828a(CPU *c) { /* Unwind@1003828a */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x620u)); /* add ecx, 0x620 */
    { f_007d3d60(c); return; } /* jmp 0x7d3d60 */
}

void f_00808298(CPU *c) { /* Unwind@10038298 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x628u)); /* add ecx, 0x628 */
    { f_007d3d60(c); return; } /* jmp 0x7d3d60 */
}

void f_008082a6(CPU *c) { /* Unwind@100382a6 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x630u)); /* add ecx, 0x630 */
    { f_007d5000(c); return; } /* jmp 0x7d5000 */
}

void f_008082b4(CPU *c) { /* Unwind@100382b4 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x640u)); /* add ecx, 0x640 */
    { f_007d5000(c); return; } /* jmp 0x7d5000 */
}

void f_008082c2(CPU *c) { /* Unwind@100382c2 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x650u)); /* add ecx, 0x650 */
    { f_007d5000(c); return; } /* jmp 0x7d5000 */
}

void f_008082d0(CPU *c) { /* Unwind@100382d0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x660u)); /* add ecx, 0x660 */
    { f_007d5000(c); return; } /* jmp 0x7d5000 */
}

void f_008082de(CPU *c) { /* Unwind@100382de */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x7d3d60u; PUSH32(c, v_); } /* push 0x10003d60 */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x670u)); /* add eax, 0x670 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008082f5u); f_007fdb7c(c); /* call 0x7fdb7c */
    c->esp += 4; return; /* ret  */
}

void f_008082f6(CPU *c) { /* Unwind@100382f6 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x7d3d60u; PUSH32(c, v_); } /* push 0x10003d60 */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x6b4u)); /* add eax, 0x6b4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0080830du); f_007fdb7c(c); /* call 0x7fdb7c */
    c->esp += 4; return; /* ret  */
}

void f_0080830e(CPU *c) { /* Unwind@1003830e */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x7d3d60u; PUSH32(c, v_); } /* push 0x10003d60 */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x6f8u)); /* add eax, 0x6f8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00808325u); f_007fdb7c(c); /* call 0x7fdb7c */
    c->esp += 4; return; /* ret  */
}

void f_00808326(CPU *c) { /* Unwind@10038326 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x73cu)); /* add ecx, 0x73c */
    { f_007d3d60(c); return; } /* jmp 0x7d3d60 */
}

void f_00808334(CPU *c) { /* Unwind@10038334 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x744u)); /* add ecx, 0x744 */
    { f_007d3d60(c); return; } /* jmp 0x7d3d60 */
}

void f_00808342(CPU *c) { /* Unwind@10038342 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x7d3d60u; PUSH32(c, v_); } /* push 0x10003d60 */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x74cu)); /* add eax, 0x74c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00808359u); f_007fdb7c(c); /* call 0x7fdb7c */
    c->esp += 4; return; /* ret  */
}

void f_0080835a(CPU *c) { /* Unwind@1003835a */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x790u)); /* add ecx, 0x790 */
    { f_007d3d60(c); return; } /* jmp 0x7d3d60 */
}

void f_00808368(CPU *c) { /* Unwind@10038368 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x798u)); /* add ecx, 0x798 */
    { f_007d3d60(c); return; } /* jmp 0x7d3d60 */
}

void f_00808376(CPU *c) { /* Unwind@10038376 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x7d8u)); /* add ecx, 0x7d8 */
    { f_007d3d60(c); return; } /* jmp 0x7d3d60 */
}

void f_00808384(CPU *c) { /* Unwind@10038384 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x98cu)); /* add ecx, 0x98c */
    { f_007f5720(c); return; } /* jmp 0x7f5720 */
}

void f_00808392(CPU *c) { /* Unwind@10038392 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x9acu)); /* add ecx, 0x9ac */
    { f_007d5010(c); return; } /* jmp 0x7d5010 */
}

void f_008083a0(CPU *c) { /* PTR_008083a0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x80a560u); /* mov eax, 0x1003a560 */
    { f_007fdd6d(c); return; } /* jmp 0x7fdd6d */
}

void f_008083b0(CPU *c) { /* Unwind@100383b0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1d6u; PUSH32(c, v_); } /* push 0x1d6 */
    { uint32_t v_ = 0x80c6a8u; PUSH32(c, v_); } /* push 0x1003c6a8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008083c3u); f_007f14f0(c); /* call 0x7f14f0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_008083c7(CPU *c) { /* PTR_008083c7 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x80a584u); /* mov eax, 0x1003a584 */
    { f_007fdd6d(c); return; } /* jmp 0x7fdd6d */
}

void f_008083e0(CPU *c) { /* Unwind@100383e0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_007d7e10(c); return; } /* jmp 0x7d7e10 */
}

void f_008083e8(CPU *c) { /* PTR_008083e8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x80a5a8u); /* mov eax, 0x1003a5a8 */
    { f_007fdd6d(c); return; } /* jmp 0x7fdd6d */
}

void f_00808400(CPU *c) { /* Unwind@10038400 */
    PREEMPT_POLL(c);
    goto L_00808400;
L_007d28b0:;
    c->esp += 4; return; /* ret  */
L_00808400:;
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    goto L_007d28b0; /* jmp 0x7d28b0 */
}

void f_0080840b(CPU *c) { /* Unwind@1003840b */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_007d28b0(c); return; } /* jmp 0x7d28b0 */
}

void f_00808416(CPU *c) { /* PTR_00808416 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x80a608u); /* mov eax, 0x1003a608 */
    { f_007fdd6d(c); return; } /* jmp 0x7fdd6d */
}

void f_00808420(CPU *c) { /* Unwind@10038420 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_007d7e10(c); return; } /* jmp 0x7d7e10 */
}

void f_00808428(CPU *c) { /* PTR_00808428 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x80a62cu); /* mov eax, 0x1003a62c */
    { f_007fdd6d(c); return; } /* jmp 0x7fdd6d */
}

void f_00808440(CPU *c) { /* Unwind@10038440 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_007d7e10(c); return; } /* jmp 0x7d7e10 */
}

void f_00808448(CPU *c) { /* PTR_00808448 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x80a650u); /* mov eax, 0x1003a650 */
    { f_007fdd6d(c); return; } /* jmp 0x7fdd6d */
}

void f_00808460(CPU *c) { /* Unwind@10038460 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_007d28b0(c); return; } /* jmp 0x7d28b0 */
}

void f_0080846b(CPU *c) { /* PTR_0080846b */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x80a674u); /* mov eax, 0x1003a674 */
    { f_007fdd6d(c); return; } /* jmp 0x7fdd6d */
}

void f_00808480(CPU *c) { /* Unwind@10038480 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_007d7e10(c); return; } /* jmp 0x7d7e10 */
}

void f_00808488(CPU *c) { /* PTR_00808488 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x80a698u); /* mov eax, 0x1003a698 */
    { f_007fdd6d(c); return; } /* jmp 0x7fdd6d */
}

void f_008084a0(CPU *c) { /* Unwind@100384a0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_007d28b0(c); return; } /* jmp 0x7d28b0 */
}

void f_008084ab(CPU *c) { /* PTR_008084ab */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x80a6bcu); /* mov eax, 0x1003a6bc */
    { f_007fdd6d(c); return; } /* jmp 0x7fdd6d */
}

void f_008084c0(CPU *c) { /* PTR_008084c0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x80a760u); /* mov eax, 0x1003a760 */
    { f_007fdd6d(c); return; } /* jmp 0x7fdd6d */
}

void f_008084d0(CPU *c) { /* Unwind@100384d0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    { f_007d7e10(c); return; } /* jmp 0x7d7e10 */
}

void f_008084d8(CPU *c) { /* PTR_008084d8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x80a784u); /* mov eax, 0x1003a784 */
    { f_007fdd6d(c); return; } /* jmp 0x7fdd6d */
}

void f_008084f0(CPU *c) { /* Unwind@100384f0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_007d7e10(c); return; } /* jmp 0x7d7e10 */
}

void f_008084f8(CPU *c) { /* PTR_008084f8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x80a7a8u); /* mov eax, 0x1003a7a8 */
    { f_007fdd6d(c); return; } /* jmp 0x7fdd6d */
}

void f_00808510(CPU *c) { /* Unwind@10038510 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_007d28b0(c); return; } /* jmp 0x7d28b0 */
}

void f_0080851b(CPU *c) { /* PTR_0080851b */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x80a7ccu); /* mov eax, 0x1003a7cc */
    { f_007fdd6d(c); return; } /* jmp 0x7fdd6d */
}

void f_00808530(CPU *c) { /* Unwind@10038530 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    { f_007d7e10(c); return; } /* jmp 0x7d7e10 */
}

void f_00808538(CPU *c) { /* PTR_00808538 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x80a7f0u); /* mov eax, 0x1003a7f0 */
    { f_007fdd6d(c); return; } /* jmp 0x7fdd6d */
}

void f_00808550(CPU *c) { /* Unwind@10038550 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_007d7e10(c); return; } /* jmp 0x7d7e10 */
}

void f_00808558(CPU *c) { /* PTR_00808558 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x80a814u); /* mov eax, 0x1003a814 */
    { f_007fdd6d(c); return; } /* jmp 0x7fdd6d */
}

void f_00808570(CPU *c) { /* Unwind@10038570 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    { f_007d7e10(c); return; } /* jmp 0x7d7e10 */
}

void f_00808578(CPU *c) { /* Unwind@10038578 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x20u)); /* add ecx, 0x20 */
    { f_007fc120(c); return; } /* jmp 0x7fc120 */
}

void f_00808583(CPU *c) { /* Unwind@10038583 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x3140u)); /* add ecx, 0x3140 */
    { f_007f9d40(c); return; } /* jmp 0x7f9d40 */
}

void f_00808591(CPU *c) { /* Unwind@10038591 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x3374u)); /* add ecx, 0x3374 */
    { f_007f4ee0(c); return; } /* jmp 0x7f4ee0 */
}

void f_0080859f(CPU *c) { /* PTR_0080859f */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x80a850u); /* mov eax, 0x1003a850 */
    { f_007fdd6d(c); return; } /* jmp 0x7fdd6d */
}

void f_008085b0(CPU *c) { /* Unwind@100385b0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffeecu))); /* mov ecx, dword ptr [ebp - 0x114] */
    { f_007d7e10(c); return; } /* jmp 0x7d7e10 */
}

void f_008085bb(CPU *c) { /* Unwind@100385bb */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffeecu))); /* mov ecx, dword ptr [ebp - 0x114] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x20u)); /* add ecx, 0x20 */
    { f_007fc120(c); return; } /* jmp 0x7fc120 */
}

void f_008085c9(CPU *c) { /* Unwind@100385c9 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffeecu))); /* mov ecx, dword ptr [ebp - 0x114] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x3140u)); /* add ecx, 0x3140 */
    { f_007f9d40(c); return; } /* jmp 0x7f9d40 */
}

void f_008085da(CPU *c) { /* Unwind@100385da */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffeecu))); /* mov ecx, dword ptr [ebp - 0x114] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x3374u)); /* add ecx, 0x3374 */
    { f_007f4ee0(c); return; } /* jmp 0x7f4ee0 */
}

void f_008085eb(CPU *c) { /* PTR_008085eb */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x80a88cu); /* mov eax, 0x1003a88c */
    { f_007fdd6d(c); return; } /* jmp 0x7fdd6d */
}

void f_00808600(CPU *c) { /* Unwind@10038600 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_007d28b0(c); return; } /* jmp 0x7d28b0 */
}

void f_0080860b(CPU *c) { /* PTR_0080860b */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x80a8b0u); /* mov eax, 0x1003a8b0 */
    { f_007fdd6d(c); return; } /* jmp 0x7fdd6d */
}

void f_00808620(CPU *c) { /* Unwind@10038620 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1b2u; PUSH32(c, v_); } /* push 0x1b2 */
    { uint32_t v_ = 0x80de94u; PUSH32(c, v_); } /* push 0x1003de94 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffff34u))); /* mov eax, dword ptr [ebp - 0xcc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00808636u); f_007f14f0(c); /* call 0x7f14f0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_0080863a(CPU *c) { /* PTR_0080863a */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x80a8d4u); /* mov eax, 0x1003a8d4 */
    { f_007fdd6d(c); return; } /* jmp 0x7fdd6d */
}

void f_00808650(CPU *c) { /* Unwind@10038650 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    { f_007d7e10(c); return; } /* jmp 0x7d7e10 */
}

void f_00808658(CPU *c) { /* Unwind@10038658 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0xf8u)); /* add ecx, 0xf8 */
    { f_007d2980(c); return; } /* jmp 0x7d2980 */
}

void f_00808666(CPU *c) { /* PTR_00808666 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x80a900u); /* mov eax, 0x1003a900 */
    { f_007fdd6d(c); return; } /* jmp 0x7fdd6d */
}

void f_00808670(CPU *c) { /* Unwind@10038670 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_007d7e10(c); return; } /* jmp 0x7d7e10 */
}

void f_00808678(CPU *c) { /* PTR_00808678 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x80a924u); /* mov eax, 0x1003a924 */
    { f_007fdd6d(c); return; } /* jmp 0x7fdd6d */
}

void f_00808689(CPU *c) { /* PTR_00808689 */
    PREEMPT_POLL(c);
    guest_trap(c, 0x00808689u, "int3"); /* int3  */
}

void f_00808690(CPU *c) { /* Unwind@10038690 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_007d28b0(c); return; } /* jmp 0x7d28b0 */
}

void f_0080869b(CPU *c) { /* PTR_0080869b */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x80a948u); /* mov eax, 0x1003a948 */
    { f_007fdd6d(c); return; } /* jmp 0x7fdd6d */
}

void f_008086b0(CPU *c) { /* Unwind@100386b0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    { f_007d7e10(c); return; } /* jmp 0x7d7e10 */
}

void f_008086b8(CPU *c) { /* PTR_008086b8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x80a96cu); /* mov eax, 0x1003a96c */
    { f_007fdd6d(c); return; } /* jmp 0x7fdd6d */
}

void f_008086d0(CPU *c) { /* Unwind@100386d0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_007d7e10(c); return; } /* jmp 0x7d7e10 */
}

void f_008086d8(CPU *c) { /* PTR_008086d8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x80a990u); /* mov eax, 0x1003a990 */
    { f_007fdd6d(c); return; } /* jmp 0x7fdd6d */
}

void f_008086f0(CPU *c) { /* Unwind@100386f0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_007d28b0(c); return; } /* jmp 0x7d28b0 */
}

void f_008086fb(CPU *c) { /* PTR_008086fb */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x80a9b4u); /* mov eax, 0x1003a9b4 */
    { f_007fdd6d(c); return; } /* jmp 0x7fdd6d */
}

void f_00808710(CPU *c) { /* Unwind@10038710 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x20u; PUSH32(c, v_); } /* push 0x20 */
    { uint32_t v_ = 0x80e514u; PUSH32(c, v_); } /* push 0x1003e514 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00808720u); f_007f14f0(c); /* call 0x7f14f0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00808724(CPU *c) { /* PTR_00808724 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x80a9d8u); /* mov eax, 0x1003a9d8 */
    { f_007fdd6d(c); return; } /* jmp 0x7fdd6d */
}

void f_00808730(CPU *c) { /* Unwind@10038730 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x21u; PUSH32(c, v_); } /* push 0x21 */
    { uint32_t v_ = 0x80e514u; PUSH32(c, v_); } /* push 0x1003e514 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00808740u); f_007f14f0(c); /* call 0x7f14f0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00808744(CPU *c) { /* PTR_00808744 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x80a9fcu); /* mov eax, 0x1003a9fc */
    { f_007fdd6d(c); return; } /* jmp 0x7fdd6d */
}

void f_00808750(CPU *c) { /* Unwind@10038750 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x22u; PUSH32(c, v_); } /* push 0x22 */
    { uint32_t v_ = 0x80e514u; PUSH32(c, v_); } /* push 0x1003e514 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00808760u); f_007f14f0(c); /* call 0x7f14f0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00808764(CPU *c) { /* PTR_00808764 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x80aa20u); /* mov eax, 0x1003aa20 */
    { f_007fdd6d(c); return; } /* jmp 0x7fdd6d */
}

void f_00808770(CPU *c) { /* Unwind@10038770 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x23u; PUSH32(c, v_); } /* push 0x23 */
    { uint32_t v_ = 0x80e514u; PUSH32(c, v_); } /* push 0x1003e514 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00808780u); f_007f14f0(c); /* call 0x7f14f0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00808784(CPU *c) { /* PTR_00808784 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x80aa44u); /* mov eax, 0x1003aa44 */
    { f_007fdd6d(c); return; } /* jmp 0x7fdd6d */
}

void f_00808790(CPU *c) { /* Unwind@10038790 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x24u; PUSH32(c, v_); } /* push 0x24 */
    { uint32_t v_ = 0x80e514u; PUSH32(c, v_); } /* push 0x1003e514 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008087a0u); f_007f14f0(c); /* call 0x7f14f0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_008087a4(CPU *c) { /* PTR_008087a4 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x80aa68u); /* mov eax, 0x1003aa68 */
    { f_007fdd6d(c); return; } /* jmp 0x7fdd6d */
}

void f_008087b0(CPU *c) { /* Unwind@100387b0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x25u; PUSH32(c, v_); } /* push 0x25 */
    { uint32_t v_ = 0x80e514u; PUSH32(c, v_); } /* push 0x1003e514 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008087c0u); f_007f14f0(c); /* call 0x7f14f0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_008087c4(CPU *c) { /* PTR_008087c4 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x80aa8cu); /* mov eax, 0x1003aa8c */
    { f_007fdd6d(c); return; } /* jmp 0x7fdd6d */
}

void f_008087d0(CPU *c) { /* Unwind@100387d0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x26u; PUSH32(c, v_); } /* push 0x26 */
    { uint32_t v_ = 0x80e514u; PUSH32(c, v_); } /* push 0x1003e514 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008087e0u); f_007f14f0(c); /* call 0x7f14f0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_008087e4(CPU *c) { /* PTR_008087e4 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x80aab0u); /* mov eax, 0x1003aab0 */
    { f_007fdd6d(c); return; } /* jmp 0x7fdd6d */
}

void f_008087f0(CPU *c) { /* Unwind@100387f0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x27u; PUSH32(c, v_); } /* push 0x27 */
    { uint32_t v_ = 0x80e514u; PUSH32(c, v_); } /* push 0x1003e514 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00808800u); f_007f14f0(c); /* call 0x7f14f0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00808804(CPU *c) { /* PTR_00808804 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x80aad4u); /* mov eax, 0x1003aad4 */
    { f_007fdd6d(c); return; } /* jmp 0x7fdd6d */
}

void f_00808810(CPU *c) { /* Unwind@10038810 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x28u; PUSH32(c, v_); } /* push 0x28 */
    { uint32_t v_ = 0x80e514u; PUSH32(c, v_); } /* push 0x1003e514 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00808820u); f_007f14f0(c); /* call 0x7f14f0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00808824(CPU *c) { /* PTR_00808824 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x80aaf8u); /* mov eax, 0x1003aaf8 */
    { f_007fdd6d(c); return; } /* jmp 0x7fdd6d */
}

void f_00808830(CPU *c) { /* Unwind@10038830 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x29u; PUSH32(c, v_); } /* push 0x29 */
    { uint32_t v_ = 0x80e514u; PUSH32(c, v_); } /* push 0x1003e514 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00808840u); f_007f14f0(c); /* call 0x7f14f0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00808844(CPU *c) { /* PTR_00808844 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x80ab1cu); /* mov eax, 0x1003ab1c */
    { f_007fdd6d(c); return; } /* jmp 0x7fdd6d */
}

void f_00808850(CPU *c) { /* Unwind@10038850 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x2au; PUSH32(c, v_); } /* push 0x2a */
    { uint32_t v_ = 0x80e514u; PUSH32(c, v_); } /* push 0x1003e514 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00808860u); f_007f14f0(c); /* call 0x7f14f0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00808864(CPU *c) { /* PTR_00808864 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x80ab40u); /* mov eax, 0x1003ab40 */
    { f_007fdd6d(c); return; } /* jmp 0x7fdd6d */
}

void f_00808870(CPU *c) { /* Unwind@10038870 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x2bu; PUSH32(c, v_); } /* push 0x2b */
    { uint32_t v_ = 0x80e514u; PUSH32(c, v_); } /* push 0x1003e514 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00808880u); f_007f14f0(c); /* call 0x7f14f0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00808884(CPU *c) { /* PTR_00808884 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x80ab64u); /* mov eax, 0x1003ab64 */
    { f_007fdd6d(c); return; } /* jmp 0x7fdd6d */
}

void f_00808890(CPU *c) { /* Unwind@10038890 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x2cu; PUSH32(c, v_); } /* push 0x2c */
    { uint32_t v_ = 0x80e514u; PUSH32(c, v_); } /* push 0x1003e514 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008088a0u); f_007f14f0(c); /* call 0x7f14f0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_008088a4(CPU *c) { /* PTR_008088a4 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x80ab88u); /* mov eax, 0x1003ab88 */
    { f_007fdd6d(c); return; } /* jmp 0x7fdd6d */
}

void f_008088b0(CPU *c) { /* Unwind@100388b0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x2du; PUSH32(c, v_); } /* push 0x2d */
    { uint32_t v_ = 0x80e514u; PUSH32(c, v_); } /* push 0x1003e514 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008088c0u); f_007f14f0(c); /* call 0x7f14f0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_008088c4(CPU *c) { /* PTR_008088c4 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x80abacu); /* mov eax, 0x1003abac */
    { f_007fdd6d(c); return; } /* jmp 0x7fdd6d */
}

void f_008088d0(CPU *c) { /* Unwind@100388d0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_007d7e10(c); return; } /* jmp 0x7d7e10 */
}

void f_008088d8(CPU *c) { /* PTR_008088d8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x80abd0u); /* mov eax, 0x1003abd0 */
    { f_007fdd6d(c); return; } /* jmp 0x7fdd6d */
}

void f_008088f0(CPU *c) { /* Unwind@100388f0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_007d5010(c); return; } /* jmp 0x7d5010 */
}

void f_008088f8(CPU *c) { /* PTR_008088f8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x80abf4u); /* mov eax, 0x1003abf4 */
    { f_007fdd6d(c); return; } /* jmp 0x7fdd6d */
}

void f_00808910(CPU *c) { /* Unwind@10038910 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    { f_007d7e10(c); return; } /* jmp 0x7d7e10 */
}

void f_00808918(CPU *c) { /* PTR_00808918 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x80ac18u); /* mov eax, 0x1003ac18 */
    { f_007fdd6d(c); return; } /* jmp 0x7fdd6d */
}

void f_00808930(CPU *c) { /* Unwind@10038930 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_007d7e10(c); return; } /* jmp 0x7d7e10 */
}

void f_00808938(CPU *c) { /* PTR_00808938 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x80ac3cu); /* mov eax, 0x1003ac3c */
    { f_007fdd6d(c); return; } /* jmp 0x7fdd6d */
}

void f_00808950(CPU *c) { /* Unwind@10038950 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_007d10a0(c); return; } /* jmp 0x7d10a0 */
}

void f_00808958(CPU *c) { /* PTR_00808958 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x80ac60u); /* mov eax, 0x1003ac60 */
    { f_007fdd6d(c); return; } /* jmp 0x7fdd6d */
}

void f_00808970(CPU *c) { /* Unwind@10038970 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_007f6120(c); return; } /* jmp 0x7f6120 */
}

void f_00808978(CPU *c) { /* PTR_00808978 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x80ac84u); /* mov eax, 0x1003ac84 */
    { f_007fdd6d(c); return; } /* jmp 0x7fdd6d */
}

void f_00808990(CPU *c) { /* Unwind@10038990 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    { f_007f6120(c); return; } /* jmp 0x7f6120 */
}

void f_00808998(CPU *c) { /* PTR_00808998 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x80aca8u); /* mov eax, 0x1003aca8 */
    { f_007fdd6d(c); return; } /* jmp 0x7fdd6d */
}

void f_008089b0(CPU *c) { /* Unwind@100389b0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_007d28b0(c); return; } /* jmp 0x7d28b0 */
}

void f_008089bb(CPU *c) { /* PTR_008089bb */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x80acccu); /* mov eax, 0x1003accc */
    { f_007fdd6d(c); return; } /* jmp 0x7fdd6d */
}

void f_008089d0(CPU *c) { /* Unwind@100389d0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_007d28b0(c); return; } /* jmp 0x7d28b0 */
}

void f_008089db(CPU *c) { /* PTR_008089db */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x80acf0u); /* mov eax, 0x1003acf0 */
    { f_007fdd6d(c); return; } /* jmp 0x7fdd6d */
}
